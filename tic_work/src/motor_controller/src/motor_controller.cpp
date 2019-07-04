#include <geometry_msgs/Twist.h>
#include <nav_msgs/Odometry.h>
#include <tf/transform_datatypes.h>
#include <angles/angles.h>
#include <ros/ros.h>
#include "motor_controller/cmd.h"

#include "GetVersion.h"

#include <future>
#include <atomic>

ros::Publisher cmd_vel_pub;
std::future<void> g_control_future;
double global_x = 0,global_y = 0, global_yaw = 0;

std::atomic<bool> going_line;
std::atomic<bool> rotating;


void Pub_V(double v,double w){
    geometry_msgs::Twist msg;
    msg.linear.x = v;
    msg.angular.z = w;
    msg.linear.y = msg.linear.z = 0;
    msg.angular.x = msg.angular.y = 0;
    cmd_vel_pub.publish(msg);
}

void OdomCallback(const nav_msgs::Odometry::ConstPtr msg){
    global_x = msg->pose.pose.position.x;
    global_y = msg->pose.pose.position.y;
    global_yaw = tf::getYaw(msg->pose.pose.orientation);

}

bool StartGoLine(motor_controller::cmd::Request &req,
                motor_controller::cmd::Response &res)
{     
    auto go_line = [&](double distance, double v) {
        going_line = true;

        double current_x = global_x, current_y = global_y;
        double accu_dis = 0.0;

        ros::Rate r(10);
        while(going_line&&ros::ok()){
            accu_dis += hypot(global_x-current_x,global_y-current_y);
            current_x = global_x,current_y = global_y;
            if(accu_dis-distance > -0.05){          
                break;
            }
            Pub_V(v,0);
            r.sleep();
        }
    Pub_V(0,0);
    going_line = false;
    };
    if (rotating || going_line) return false;
    if (!g_control_future.valid()||std::future_status::ready == g_control_future.wait_for(std::chrono::duration<double>(0.0))){
        g_control_future = std::async(std::launch::async, go_line, req.distance, req.speed);       
    } else {
        return false;
    }
    return true;
}


bool StopGoLine(motor_controller::cmd::Request &req,
                motor_controller::cmd::Response &res)
{
    Pub_V(0,0);
    going_line = false;
    return true;
}

bool StartRotate(motor_controller::cmd::Request &req,
                motor_controller::cmd::Response &res)
{
    auto get_sign = [](double value){
    return value >= 0 ? 1 : -1;
    };

    auto start_rotate = [&](double angle, double speed){
    rotating = true;

    if (fabs(speed) > 0.8){
        speed = get_sign(speed) * 0.8;
    }

    double start_yaw = global_yaw;

    int times = ceil(angle / 180.0);
    if (angle < 0){
        times = abs(floor(angle / 180.0));
    }
    ros::Rate r(10);
    for (int i = 1; i <= times; ++i){
        double goal_yaw = angles::normalize_angle(start_yaw + i * M_PI);
        if (i == times){
            goal_yaw = angles::normalize_angle(start_yaw + angle / 180.0 * M_PI);
        }
        while (rotating && ros::ok()){
            if (fabs(angles::shortest_angular_distance(global_yaw, goal_yaw)) < fabs(speed) / 0.3 * 0.05)
                break;
            Pub_V(0, speed);
            r.sleep();
        }
    }
    Pub_V(0, 0);
    rotating = false;
    };
    if(rotating || going_line||fabs(req.speed) < std::numeric_limits<double>::min())
        return false;
    if (!g_control_future.valid() || std::future_status::ready == g_control_future.wait_for(std::chrono::duration<double>(0.0))) {
        g_control_future = std::async(std::launch::async, start_rotate, req.angle, req.speed);
    }else{
        return false;
    }
    return true;
}



bool StopRotate(motor_controller::cmd::Request &req,
                motor_controller::cmd::Response &res)
{
    Pub_V(0,0);
    rotating = false;
    return true;
}

int main(int argc,char** argv){
    if(('v'==getopt(argc,argv,"v"))){
        GetVersion();
        exit(0);
    }

    ros::init(argc, argv, "motor_controller");
    going_line = false;
    rotating = false;

    ros::NodeHandle nh;
    cmd_vel_pub = nh.advertise<geometry_msgs::Twist>("/cmd_vel",1);
    ros::Subscriber odom_sub = nh.subscribe<nav_msgs::Odometry>("/odom",1,OdomCallback);

    ros::ServiceServer start_go_line_srv = nh.advertiseService("/device/start_go_line",StartGoLine);
    ros::ServiceServer stop_go_line_srv = nh.advertiseService("/device/stop_go_line",StopGoLine);

    ros::ServiceServer start_rotate_srv = nh.advertiseService("/device/start_rotate",StartRotate);
    ros::ServiceServer stop_rotate_srv = nh.advertiseService("/device/stop_rotate",StopRotate);

    ros::spin();

    going_line = false;
    rotating = false;
    if (g_control_future.valid())
    g_control_future.wait();
    return 0;
}
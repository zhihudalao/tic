#include <geometry_msgs/Twist.h>
#include <nav_msgs/Odometry.h>
#include <tf/transform_datatypes.h>
#include <angles/angles.h>
#include <ros/ros.h>
#include "chassis/cmd.h"
#include <future>
#include <atomic>
#include "savelog.h"

ros::Publisher cmd_vel_pub;
std::future<void> g_control_future;
double global_x = 0,global_y = 0, global_yaw = 0;

std::atomic<bool> going_line; //直线行走任务标志
std::atomic<bool> rotating; //旋转任务标志

/****************************************
* 作者/公司  : ***
* 函数介绍   : 设置速度
* 输入参数   :
* 输出参数   :
* 返回值     :
*****************************************/
void Pub_V(double v,double w)
{
    geometry_msgs::Twist msg;
    msg.linear.x = v;
    msg.linear.y = 0;
    msg.linear.z = 0;
    msg.angular.x = 0;
    msg.angular.y = 0;
    msg.angular.z = w;

    TIC_LOG("topic cmd_val x = %f z = %f",msg.linear.x, msg.angular.z);
    cmd_vel_pub.publish(msg);
}

/****************************************
* 作者/公司  : ***
* 函数介绍   : 监听odom
* 输入参数   :
* 输出参数   :
* 返回值     :
*****************************************/
void OdomCallback(const nav_msgs::Odometry::ConstPtr msg)
{
    global_x = msg->pose.pose.position.x;
    global_y = msg->pose.pose.position.y;
    global_yaw = tf::getYaw(msg->pose.pose.orientation);
}

/****************************************
* 作者/公司  : ***
* 函数介绍   : 行走指定距离
* 输入参数   :
* 输出参数   :
* 返回值     :
*****************************************/
bool StartGoLine(chassis::cmd::Request &req, chassis::cmd::Response &res)
{     
    auto go_line = [&](double distance, double speed) 
    {
        TIC_LOG("distance = %f speed = %f", distance, speed);

        going_line = true;
        if(distance < 0) distance = -distance;

        double current_x = global_x, current_y = global_y;
        double accu_dis = 0.0;
        ros::Rate r(10);
        while(going_line && ros::ok())
        {
            accu_dis += hypot(global_x-current_x,global_y-current_y); //计算已经运行的距离
            current_x = global_x, current_y = global_y;
            if((accu_dis - distance) > DBL_EPSILON) break;
            Pub_V(speed,0);
            r.sleep();
        }

        for(int i=0;i<4;i++) Pub_V(0, 0);

        going_line = false;
    };

    if (rotating || going_line) return false;

    if (!g_control_future.valid()||std::future_status::ready == g_control_future.wait_for(std::chrono::duration<double>(0.0)))
    {
        g_control_future = std::async(std::launch::async, go_line, req.distance, req.speed);       
    }
    else 
    {
        return false;
    }

    return true;
}

/****************************************
* 作者/公司  : ***
* 函数介绍   : 停止直线行走
* 输入参数   :
* 输出参数   :
* 返回值     :
*****************************************/
bool StopGoLine(chassis::cmd::Request &req, chassis::cmd::Response &res)
{
    Pub_V(0,0);
    going_line = false;
    return true;
}

/****************************************
* 作者/公司  : ***
* 函数介绍   : 旋转指定角度
* 输入参数   :
* 输出参数   :
* 返回值     :
*****************************************/
bool StartRotate(chassis::cmd::Request &req, chassis::cmd::Response &res)
{
    auto start_rotate = [&](double angle, double speed)
    {
        TIC_LOG("angle = %f speed = %f", angle, speed);

        rotating = true;
        //double start_yaw = global_yaw; //当前角度值
        //int turns = 0; //需要旋转多少个半圈

        double run_yaw = 0; //已经运转的角度值
        if(angle < 0) angle = -angle;
        double goal_yaw = angle / 180.0 * 3.141592654;
        double old_global_yaw = global_yaw;
        ros::Rate r(10);
        while (rotating && ros::ok())
        {
            double dy = global_yaw - old_global_yaw;
            if(dy < 0) dy = -dy;
            if(dy > 3.14) dy = 6.28 - dy;
            old_global_yaw = global_yaw;
            run_yaw += dy;
            if(run_yaw >= goal_yaw) break;
            Pub_V(0, speed);
            r.sleep();
        }

/*
        //计算旋转的半圈数
        if (angle < 0) turns = abs(floor(angle / 180.0));
        else turns = ceil(angle / 180.0);
        
        ros::Rate r(10);
        for (int i = 1; i <= turns; ++i)
        {
            double goal_yaw = 0;

            if (i == turns)  goal_yaw = angles::normalize_angle(start_yaw + angle / 180.0 * M_PI); //如果是最后一圈
            else goal_yaw = angles::normalize_angle(start_yaw + (i%2) * M_PI); //360

            run_yaw = 0;
            if (!rotating) break;
            while (rotating && ros::ok())
            {                
                double yaw = fabs(angles::shortest_angular_distance(global_yaw, goal_yaw)); //180
                if(yaw < fabs(speed) / 0.3 * 0.05) break;

                Pub_V(0, speed);
                r.sleep();
            }
        }
      */  
        for(int i=0;i<4;i++) Pub_V(0, 0);
        
        rotating = false;
    };

    if(rotating || going_line||fabs(req.speed) < std::numeric_limits<double>::min()) return false;

    if (!g_control_future.valid() || std::future_status::ready == g_control_future.wait_for(std::chrono::duration<double>(0.0))) 
    {
        g_control_future = std::async(std::launch::async, start_rotate, req.angle, req.speed);
    }
    else
    {
        return false;
    }

    return true;
}

/****************************************
* 作者/公司  : ***
* 函数介绍   : 停止转圈
* 输入参数   :
* 输出参数   :
* 返回值     :
*****************************************/
bool StopRotate(chassis::cmd::Request &req, chassis::cmd::Response &res)
{
    Pub_V(0,0);
    rotating = false;
    return true;
}

/****************************************
* 作者/公司  : ***
* 函数介绍   : 主函数
* 输入参数   :
* 输出参数   :
* 返回值     :
*****************************************/
int main(int argc,char** argv){

    if('v' == getopt(argc,argv, "v")) std::cout << __DATE__ << "\r\n" << __TIME__ << "\r\n" <<"Revision:" << "V1.0" << std::endl, exit(0);

    ros::init(argc, argv, "movemotor_presisecontrol");
    going_line = false;
    rotating = false;

    ros::NodeHandle nh;

    //topic
    cmd_vel_pub = nh.advertise<geometry_msgs::Twist>("/cmd_vel",1);
    ros::Subscriber odom_sub = nh.subscribe<nav_msgs::Odometry>("/odom",1,OdomCallback);

    //server
    ros::ServiceServer start_go_line_srv = nh.advertiseService("/device/start_go_line",StartGoLine);
    ros::ServiceServer stop_go_line_srv = nh.advertiseService("/device/stop_go_line",StopGoLine);
    ros::ServiceServer start_rotate_srv = nh.advertiseService("/device/start_rotate",StartRotate);
    ros::ServiceServer stop_rotate_srv = nh.advertiseService("/device/stop_rotate",StopRotate);

    ros::spin();

    going_line = false;
    rotating = false;
    if (g_control_future.valid()) g_control_future.wait();
    
    return 0;
}
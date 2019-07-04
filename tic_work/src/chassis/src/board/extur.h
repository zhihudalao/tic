#ifndef __EXTUR_H__
#define __EXTUR_H__

#include <ros/ros.h>
#include <std_msgs/Int32.h>
#include <string.h>
#include <geometry_msgs/Twist.h>

#define DEBUG_MODE (0)
#define ULTRASOUND_NUMBER 8

#define MATH_PI (3.14159265358)

using namespace std;

struct encoder_Type
{
    int32_t info_left;
    int32_t info_right;
    int32_t info_time;
};

struct ultrasionic_Type
{
    bool debug;                 //超声虚拟数据
    float field_of_view;        //检测角度
    float min_range;            //最小检测范围
    float max_range;            //最大检测范围
    float distance[ULTRASOUND_NUMBER]; //超声数据
};

struct odomParamList_Type
{
    int32_t run_rate;
};

struct motorOther_Type
{
    int32_t rSpeed;
    int32_t dSpeed;
    int32_t controlCmd;
};


struct key_Type
{
    bool frontAntiCollision; //防碰撞前
    bool breakAntiCollision; //防碰撞后
    bool power;     //钥匙开关
    bool emergency; //急停按键
};

struct motorMove_Type
{
    float accel_limit = 0;      //启动加速度
    bool odomTfSendFlag;        //是否发送odom tf
    float centerDistance;       //轮子距离baselink坐标系中心距离
    float downGearReduction;    //速度下发时使用的减速比
    float upGearReduction;      //编码器数据长传使用的减速比
    float wheel_diameter;       //轮子直径
    int32_t encoder_resolution; //一圈多少个编码
    int32_t cmd_LeftSpeed;      //下发的左轮速度
    int32_t cmd_RightSpeed;     //下发的右轮速度
    ros::Time cmdValTimeout;
    geometry_msgs::Twist cmdVal; //收到的方向控制信息
};

struct infoMachineTime_Type
{
    int32_t run;
    int8_t s;
    int8_t m;
    int32_t h;
};

struct motor_Type
{
    struct motorMove_Type move;
    struct motorOther_Type brush;
    struct motorOther_Type brushLift;
    struct motorOther_Type wiperLift;
    struct motorOther_Type vacuum;
    struct motorOther_Type waterSpray;
};

struct battery_Type
{
    float charger_current;      //充电电流
    float discharge_current;    //放电电流
    float voltage;              //当前电压
    int8_t electricity;         //电量
    float temp;                 //温度
};

struct pcb_Type
{
    string version;//下位机版本号
    struct infoMachineTime_Type time; //下位机运行时间
};

struct nodeData_Type
{
    struct motor_Type motor;                //电机
    struct encoder_Type encoder;            //编码器
    struct battery_Type battery;            //电池
    struct ultrasionic_Type ultrasionic;    //超声
    struct key_Type key;                    //按键
    struct pcb_Type pcb;                    //控制板

    string base_frame;          //odom child_frame_id name
    float topicTimout = 0;      //cmd_val topic 超时时间
    int32_t cmd_valve;
    bool info_valve;
    int32_t info_clear_waterl;
    int32_t info_sewage_waterl;
    bool debug;
    bool motorLevelParamEnable;
    int brushLevel[3]; //刷盘电机旋转等级
    int waterSprayLevel[3]; //喷水电机等级
    float statusSendTime; //状态发送时间,单位 s
};

extern struct nodeData_Type NodeData;

#endif

#include "info.h"
#include <sensor_msgs/Range.h>
#include <tf/transform_broadcaster.h>
#include <nav_msgs/Odometry.h>
#include "motorlist.h"
#include <fstream>
#include <stdarg.h>
#include <stdio.h>

/****************************************
* 作者/公司  : chip
* 函数介绍   : 其他设备控制命令
* 输入参数   :
* 输出参数   :
* 返回值     :
*****************************************/
void InfoCmdList::boardCmdVelCallback(const diagnostic_msgs::DiagnosticStatus msg)
{
  diagnostic_msgs::KeyValue kv;

  if(msg.name == "WashManager")
  {
    for(int i=0;i<(int)msg.values.size();i++)
    if(!msg.values.empty())
    {
      kv = msg.values[i];
      stringstream sstr(kv.value);

      if(kv.key == "brushLevel")
      {
        int val = 0;
        sstr >> val;
        NodeData.motor.brush.controlCmd = val;
        TIC_LOG("topic brush = %d",NodeData.motor.brush.controlCmd);
      }

      if(kv.key == "brushLift")
      {
        int val = 0;
        sstr >> val;
        NodeData.motor.brushLift.controlCmd = val;
        TIC_LOG("topic brush lift = %d",NodeData.motor.brushLift.controlCmd);
      }

      if(kv.key == "waterSpray")
      {
        int val = 0;
        sstr >> val;
        NodeData.motor.waterSpray.controlCmd = val;
        TIC_LOG("topic water spray = %d",NodeData.motor.waterSpray.controlCmd);
      }

      if(kv.key == "wiperLift")
      {
        int val = 0;
        sstr >> val;
        NodeData.motor.wiperLift.controlCmd = val;
        TIC_LOG("topic wiper lift = %d",NodeData.motor.wiperLift.controlCmd);
      }

      if(kv.key == "vacuum")
      {
        int val = 0;
        sstr >> val;
        NodeData.motor.vacuum.controlCmd = val;
        TIC_LOG("topic vacuum = %d",NodeData.motor.vacuum.controlCmd);
      }
    }
  }
}

/****************************************
* 作者/公司  : chip
* 函数介绍   : cmd_val topic 数据解析
* 输入参数   :
* 输出参数   :
* 返回值     :
*****************************************/
void InfoCmdList::cmdVelCallback(const geometry_msgs::Twist msg)
{
  NodeData.motor.move.cmdVal = msg;
  NodeData.motor.move.cmdValTimeout = ros::Time::now(); //获取当前时间，用于超时检测

  TIC_LOG("topic cmd_val: x = %f z = %f",
  NodeData.motor.move.cmdVal.linear.x,
  NodeData.motor.move.cmdVal.angular.z);
}

/****************************************
* 作者/公司  : chip
* 函数介绍   : 发送超声数据
* 输入参数   :
* 输出参数   :
* 返回值     :
*****************************************/
void InfoCmdList::publishSonar()
{
	sensor_msgs::Range Sonar;

	Sonar.header.stamp = ros::Time::now();
	Sonar.radiation_type = sensor_msgs::Range::ULTRASOUND;
  Sonar.field_of_view = NodeData.ultrasionic.field_of_view; //检测范围
  Sonar.min_range = NodeData.ultrasionic.min_range;
  Sonar.max_range = NodeData.ultrasionic.max_range;

	//暂时只用到4路超声
  for(int i=0;i<ULTRASOUND_NUMBER;i++)
	{
    if(NodeData.ultrasionic.debug)
    {
        NodeData.ultrasionic.distance[i] = 500;
    }

    Sonar.header.frame_id = "/Ultrasound"+std::to_string(i+1);
    Sonar.range = NodeData.ultrasionic.distance[i]/1000.0;
    sonar[i].publish(Sonar);
	}
}

/****************************************
* 作者/公司  : chip
* 函数介绍   : 获取参数
* 输入参数   :
* 输出参数   :
* 返回值     :
*****************************************/
bool InfoCmdList::getParam(ros::NodeHandle *nh)
{
    bool ret = true;
    ret = true;

    if(!nh->getParam("debug",NodeData.debug))
    {
        ROS_ERROR("motorlistener node --> param error: [debug]");
        ret = false;
    }

    if(!nh->getParam("centerDistance",NodeData.motor.move.centerDistance))
    {
        ROS_ERROR("motorlistener node --> param error: [centerDistance]");
        ret = false;
    }

    if(!nh->getParam("downGearReduction",NodeData.motor.move.downGearReduction))
    {
        ROS_ERROR("motorlistener node --> param error: [downGearReduction]");
        ret = false;
    }

    if(!nh->getParam("upGearReduction",NodeData.motor.move.upGearReduction))
    {
        ROS_ERROR("motorlistener node --> param error: [upGearReduction]");
        ret = false;
    }

    if(!nh->getParam("encoder_resolution",NodeData.motor.move.encoder_resolution))
    {
        ROS_ERROR("motorlistener node --> param error: [encoder_resolution]");
        ret = false;
    }

    if(!nh->getParam("wheel_diameter",NodeData.motor.move.wheel_diameter))
    {
        ROS_ERROR("motorlistener node --> param error: [wheel_diameter]");
        ret = false;
    }

    if(!nh->getParam("odomTfSendFlag",NodeData.motor.move.odomTfSendFlag))
    {
        ROS_ERROR("motorlistener node --> param error: [odomTfSendFlag]");
        ret = false;
    }

    if(!nh->getParam("timeout",NodeData.topicTimout))
    {
        ROS_ERROR("motorlistener node --> param error: [topicTimout]");
        ret = false;
    }

    if(!nh->getParam("accel_limit",NodeData.motor.move.accel_limit))
    {
        ROS_ERROR("motorlistener node --> param error: [accel_limit]");
        ret = false;
    }

    if(!nh->getParam("base_frame",NodeData.base_frame))
    {
        ROS_ERROR("motorlistener node --> param error: [base_frame]");
        ret = false;
    }

    if(!nh->getParam("brushLevelLow",NodeData.brushLevel[0]))
    {
        ROS_ERROR("motorlistener node --> param error: [brushLevelLow]");
        ret = false;
    }
    else
    {
        if(NodeData.brushLevel[0]>100 || NodeData.brushLevel[0]<0)
        {
            ROS_ERROR("motorlistener node --> param error: [brushLevelLow]");
            ret = false;
        }
    }

    if(!nh->getParam("brushLevelMedium",NodeData.brushLevel[1]))
    {
        ROS_ERROR("motorlistener node --> param error: [brushLevelMedium]");
        ret = false;
    }
    else
    {
        if(NodeData.brushLevel[1]>100 || NodeData.brushLevel[1]<0)
        {
            ROS_ERROR("motorlistener node --> param error: [brushLevelMedium]");
            ret = false;
        }
    }

    if(!nh->getParam("brushLevelHigh",NodeData.brushLevel[2]))
    {
        ROS_ERROR("motorlistener node --> param error: [brushLevelHigh]");
        ret = false;
    }
    else
    {
        if(NodeData.brushLevel[2]>100 || NodeData.brushLevel[2]<0)
        {
            ROS_ERROR("motorlistener node --> param error: [brushLevelHigh]");
            ret = false;
        }
    }

    if(!nh->getParam("waterSprayLow",NodeData.waterSprayLevel[0]))
    {
        ROS_ERROR("motorlistener node --> param error: [waterSprayLow]");
        ret = false;
    }
    else
    {
        if(NodeData.waterSprayLevel[0]>100 || NodeData.waterSprayLevel[0]<0)
        {
            ROS_ERROR("motorlistener node --> param error: [waterSprayLow]");
            ret = false;
        }
    }

    if(!nh->getParam("waterSprayMedium",NodeData.waterSprayLevel[1]))
    {
        ROS_ERROR("motorlistener node --> param error: [waterSprayMedium]");
        ret = false;
    }
    else
    {
        if(NodeData.waterSprayLevel[1]>100 || NodeData.waterSprayLevel[1]<0)
        {
            ROS_ERROR("motorlistener node --> param error: [waterSprayMedium]");
            ret = false;
        }
    }

    if(!nh->getParam("waterSprayHigh",NodeData.waterSprayLevel[2]))
    {
        ROS_ERROR("motorlistener node --> param error: [waterSprayHigh]");
        ret = false;
    }
    else
    {
        if(NodeData.waterSprayLevel[2]>100 || NodeData.waterSprayLevel[2]<0)
        {
            ROS_ERROR("motorlistener node --> param error: [waterSprayHigh]");
            ret = false;
        }
    }

    if(!nh->getParam("motorLevelParamEnable",NodeData.motorLevelParamEnable))
    {
        ROS_ERROR("motorlistener node --> param error: [motorLevelParamEnable]");
        ret = false;
    }

    if(!nh->getParam("debugSonarTest",NodeData.ultrasionic.debug))
    {
        ROS_ERROR("motorlistener node --> param error: [debugSonarTest]");
        ret = false;
    }

    if(!nh->getParam("ultrasoundFieldView",NodeData.ultrasionic.field_of_view))
    {
        ROS_ERROR("motorlistener node --> param error: [ultrasoundFieldView]");
        ret = false;
    }

    if(!nh->getParam("ultrasoundMinRange",NodeData.ultrasionic.min_range))
    {
        ROS_ERROR("motorlistener node --> param error: [ultrasoundMinRange]");
        ret = false;
    }

    if(!nh->getParam("ultrasoundMaxRange",NodeData.ultrasionic.max_range))
    {
        ROS_ERROR("motorlistener node --> param error: [ultrasoundMaxRange]");
        ret = false;
    }

    if(!nh->getParam("statusSendTime",NodeData.statusSendTime))
    {
        ROS_ERROR("motorlistener node --> param error: [statusSendTime]");
        ret = false;
    }
    

    return ret;
}


/****************************************
* 作者/公司  : chip
* 函数介绍   : 三轮全向驱动底盘计算并发送odom
* 输入参数   : one_encoder 第一个轮子编码器数值
              tow_encoder 第二个轮子编码器数值
              three_encoder 第三个轮子编码器数值
              timer 获取编码器数值的时间 单位ms
* 输出参数   :
* 返回值     :
*****************************************/
void InfoCmdList::odomPublish(int32_t *one_encoder, int32_t *tow_encoder, int32_t *three_encoder, int32_t timer)
{

}

/****************************************
* 作者/公司  : chip
* 函数介绍   : 后轮驱动底盘计算并发送odom
* 输入参数   : left_encoder 左轮编码器数值
              right_encoder 右轮编码器数值
              timer 获取编码器数值的时间 单位ms
* 输出参数   :
* 返回值     :
*****************************************/
void InfoCmdList::odomPublish(int32_t left_encoder, int32_t right_encoder, int32_t timer)
{
  static uint32_t old_timer = 0; //上一次获取编码器的时间
  static bool first_flag = false; //第一次运行标志
  static ros::Time run_time; //第一次运行时间
  static tf::TransformBroadcaster odom_broadcaster; //odom tf
  static int32_t old_right_encoder = 0; //上一次右轮编码器的数值
  static int32_t old_left_encoder = 0; //上一次左轮编码器的数值
  double center_distance = NodeData.motor.move.centerDistance; //轮子距离odom中心的距离

  static double th = 0; //角度里程计
  static double x = 0; //x轴里程计
  static double y = 0; //y轴里程计

  double dright = 0; //右轮两次数据采集时间行走的距离
  double dleft = 0; //左轮两次数据采集时间行走的距离

  if(timer != old_timer) //计算左轮速度
  {
    if(!first_flag) //第一次运行
    {
      first_flag = true;
      run_time = ros::Time::now(); //获取当前时间
      old_right_encoder = right_encoder; //记录当前编码器的值
      old_left_encoder = left_encoder; //记录当前编码器的值
      old_timer = timer; //记录上一次获取编码器的时间
      return;
    }

    ros::Duration dt = ros::Duration((timer - old_timer)/1000.0);
    old_timer = timer;
    run_time += dt;

//    int8_t left_encoder_limit; //编码器计数到极限标志
//    int8_t rihgt_encoder_limit; 
//    double encoder_max = 2147483648; //编码器计数最大值
//    double encoder_min = -2147483648; //编码器计数最小值
//    int32_t encoder_high_wrap = (int32_t)(encoder_max - ((encoder_max - encoder_min)*0.3));
//    int32_t encoder_low_wrap = (int32_t)(encoder_min + ((encoder_max - encoder_min)*0.3));
//
//    if (left_encoder < encoder_low_wrap && old_left_encoder > encoder_high_wrap) left_encoder_limit = 1;
//    else if (left_encoder > encoder_high_wrap && old_left_encoder < encoder_low_wrap) left_encoder_limit = -1;
//    else left_encoder_limit = 0;
//
//    if (right_encoder < encoder_low_wrap && old_right_encoder > encoder_high_wrap) rihgt_encoder_limit = 1;
//    else if (right_encoder > encoder_high_wrap && old_right_encoder < encoder_low_wrap) rihgt_encoder_limit = -1;    
//    else rihgt_encoder_limit = 0

    //计算相对上次行走的距离
    //int32_t dleft_en = (left_encoder - old_left_encoder) + left_encoder_limit * (encoder_max - encoder_min);
    //int32_t dright_en = right_encoder - old_right_encoder + left_encoder_limit * (encoder_max - encoder_min);
    int32_t dleft_en = left_encoder - old_left_encoder;
    int32_t dright_en = right_encoder - old_right_encoder;
    old_left_encoder = left_encoder;
    old_right_encoder = right_encoder;
    
    //TIC_INFO("encoder_low_wrap = %d encoder_high_wrap = %d left_encoder = %d left_encoder_limit = %d dleft_en = %d",encoder_low_wrap,encoder_high_wrap,left_encoder,left_encoder_limit,dleft_en);

    //（编码器 × 减速比）/（轮轴直径×PI）
    double ticks_per_meter = NodeData.motor.move.encoder_resolution * NodeData.motor.move.upGearReduction / (NodeData.motor.move.wheel_diameter * MATH_PI);
    dleft = dleft_en / ticks_per_meter; //计算左轮距离
    dright = dright_en / ticks_per_meter; //计算右轮距离
    double dxy_ave = (dright + dleft) / 2.0; //计算两轮中心移动距离
    double dth = (dright - dleft) / center_distance; //计算两轮中心角旋转角度

    double vxy = dxy_ave / dt.toSec(); //计算两轮中心速度
    double vth = dth / dt.toSec();     //计算两轮中心角速度

    if(!(fabs(dxy_ave) < DBL_EPSILON))
    {
      double dx = cos(dth) * dxy_ave;     //x轴就是的
      double dy = -sin(dth) * dxy_ave;    //y轴加速度
      x += (cos(th) * dx - sin(th) * dy); //x轴距离原点距离
      y += (sin(th) * dx + cos(th) * dy); //y轴距离原点距离
    }

    if(!(fabs(dth) < DBL_EPSILON)) th += dth; //角度里程计

    //发送TF
    geometry_msgs::Quaternion odom_quat = tf::createQuaternionMsgFromYaw(th);
    odom_quat.x = 0.0;
    odom_quat.y = 0.0;
    odom_quat.z = sin(th / 2.0);
    odom_quat.w = cos(th / 2.0);

    geometry_msgs::TransformStamped odom_trans;
    odom_trans.header.stamp = run_time;
    odom_trans.header.frame_id = "odom";
    odom_trans.child_frame_id = NodeData.base_frame;
    odom_trans.transform.translation.x = x;
    odom_trans.transform.translation.y = y;
    odom_trans.transform.translation.z = 0.0;
    odom_trans.transform.rotation = odom_quat;

    if (NodeData.motor.move.odomTfSendFlag)
    {
      odom_broadcaster.sendTransform(odom_trans);
    }

    //发送odom
    nav_msgs::Odometry odom;
    odom.header.frame_id = "odom";
    odom.child_frame_id = NodeData.base_frame;
    odom.header.stamp = run_time;
    odom.pose.pose.position.x = x;
    odom.pose.pose.position.y = y;
    odom.pose.pose.position.z = 0;
    odom.pose.pose.orientation = odom_quat;
    odom.twist.twist.linear.x = vxy;
    odom.twist.twist.linear.y = 0;
    odom.twist.twist.angular.z = vth;

    float ODOM_POSE_COVARIANCE[36] = {
    1e-3, 0, 0, 0, 0, 0,
    0, 1e-3, 0, 0, 0, 0,
    0, 0, 1e6, 0, 0, 0,
    0, 0, 0, 1e6, 0, 0,
    0, 0, 0, 0, 1e6, 0,
    0, 0, 0, 0, 0, 1e3};

    float ODOM_TWIST_COVARIANCE[36] = {
    1e-3, 0, 0, 0, 0, 0,
    0, 1e-3, 0, 0, 0, 0,
    0, 0, 1e6, 0, 0, 0,
    0, 0, 0, 1e6, 0, 0,
    0, 0, 0, 0, 1e6, 0,
    0, 0, 0, 0, 0, 1e3};

    for(int i = 0; i < 36; i++)
    {
      odom.pose.covariance[i] = ODOM_POSE_COVARIANCE[i];
    }

    for(int i = 0; i < 36; i++)
    {
      odom.twist.covariance[i] = ODOM_TWIST_COVARIANCE[i];
    }

    odom_pub.publish(odom);
  }
}

/****************************************
* 作者/公司  : chip
* 函数介绍   : 发送下位机相关topic
* 输入参数   :
* 输出参数   :
* 返回值     :
*****************************************/
void InfoCmdList::boardPublish()
{
  //发送消息
  diagnostic_msgs::DiagnosticStatus boardStatus;
  diagnostic_msgs::KeyValue kv;

  boardStatus.name = "DevicesStatus";
  boardStatus.message = "DevicesStatus";
  boardStatus.hardware_id = "DevicesStatus";

  //电池电量
  kv.key = "batteryElectricity";
  kv.value = std::to_string(NodeData.battery.electricity);
  boardStatus.values.push_back(kv);
  //电池电压
  kv.key = "batteryVoltage";
  kv.value = std::to_string(NodeData.battery.voltage);
  boardStatus.values.push_back(kv);
  //充电电流
  kv.key = "chargerCurrent";
  kv.value = std::to_string(NodeData.battery.charger_current);
  boardStatus.values.push_back(kv);
  //放电电流
  kv.key = "dischargeCurrent";
  kv.value = std::to_string(NodeData.battery.discharge_current);
  boardStatus.values.push_back(kv);
  //下位机运行时间
  kv.key = "machineRuntime";
  kv.value = std::to_string(NodeData.pcb.time.h)+":"+std::to_string(NodeData.pcb.time.m)+":"+std::to_string(NodeData.pcb.time.s);
  boardStatus.values.push_back(kv);
  //下位机版本号
  kv.key = "machineVersion";
  kv.value = NodeData.pcb.version;
  boardStatus.values.push_back(kv);
  //急停按键
  kv.key = "emergencyKey";
  kv.value = std::to_string(NodeData.key.emergency);
  boardStatus.values.push_back(kv);
  //清水水量
  kv.key = "clearWaterl";
  kv.value = std::to_string(NodeData.info_clear_waterl);
  boardStatus.values.push_back(kv);
  //污水水量
  kv.key = "sewageWaterl";
  kv.value = std::to_string(NodeData.info_sewage_waterl);
  boardStatus.values.push_back(kv);
  //钥匙开关
  kv.key = "powerKey";
  kv.value = std::to_string(NodeData.key.power);
  boardStatus.values.push_back(kv);
  //前防碰撞
  kv.key = "frontAntiCollision";
  kv.value = std::to_string(NodeData.key.frontAntiCollision);
  boardStatus.values.push_back(kv);
  //后防碰撞
  kv.key = "breakAntiCollision";
  kv.value = std::to_string(NodeData.key.breakAntiCollision);
  boardStatus.values.push_back(kv);

  TIC_LOG("push topic /DevicesStatus");
  boardPub.publish(boardStatus); //下位机相关数据发送至topic
}

/****************************************
* 作者/公司  : chip
* 函数介绍   : 20ms执行一次，定时器终端函数
* 输入参数   :
* 输出参数   :
* 返回值     :
*****************************************/
void InfoCmdList::timer20msCallback(const ros::TimerEvent& event)
{
  boardPublish();
}

/****************************************
* 作者/公司  : chip
* 函数介绍   : 参数初始化
* 输入参数   :
* 输出参数   :
* 返回值     :
*****************************************/
void InfoCmdList::InitData()
{
  this->odomData.run_rate = 50;
}

/****************************************
* 作者/公司  : chip
* 函数介绍   : 构造函数
* 输入参数   :
* 输出参数   :
* 返回值     :
*****************************************/
InfoCmdList::InfoCmdList()
{
  ros::NodeHandle nh;
  ros::NodeHandle nh_("~");
  getParam(&nh_);
  InitData();

  odom_pub = nh.advertise<nav_msgs::Odometry>("odom", 5); //topic name
  boardPub = nh.advertise<diagnostic_msgs::DiagnosticStatus>("DevicesStatus", 5); //topic name
  for(int i=0;i<ULTRASOUND_NUMBER;i++) sonar[i] = nh.advertise<sensor_msgs::Range>("Ultrasound"+std::to_string(i+1), 5); //topic name
  cmdval = nh.subscribe("cmd_vel", 10, &InfoCmdList::cmdVelCallback, this);
  wash = nh.subscribe("WashManager", 1, &InfoCmdList::boardCmdVelCallback,this);
  time20 = nh.createTimer(ros::Duration(NodeData.statusSendTime), &InfoCmdList::timer20msCallback,this);//状态发送时间

  board.resetContBoard(); //连接下位机

}

/****************************************
* 作者/公司  : chip
* 函数介绍   : 下位机相关数据处理
* 输入参数   :
* 输出参数   :
* 返回值     :
*****************************************/
void InfoCmdList::readParser()
{
  uint16_t len = board.readBoardData(BoardDataBuf.rx_buf, len);
  if(len > 0) //读取下位机数据
  {
    board.boardDataProcess(BoardDataBuf.rx_buf, len); //处理下位机数据
    this->odomPublish(NodeData.encoder.info_left, NodeData.encoder.info_right, NodeData.encoder.info_time); 	//odom 计算解析发送
    this->publishSonar(); //发送超声数据
  }
}

/****************************************
* 作者/公司  : chip
* 函数介绍   : 下位机控制命令发送
* 输入参数   :
* 输出参数   :
* 返回值     :
*****************************************/
void InfoCmdList::sendControl()
{
  BoardDataBuf.tx_index = 0;
  board.setMotorStatus();//设置下位机运行状态

  if(!NodeData.debug)
  {
    board.sendBoardData(BoardDataBuf.tx_buf, BoardDataBuf.tx_index);//发送数据
    board.resetContBoard();//下位机断线重连
  }
}

/****************************************
* 作者/公司  : chip
* 函数介绍   : 循环执行函数
* 输入参数   :
* 输出参数   :
* 返回值     :
*****************************************/
void InfoCmdList::run()
{
  static int time2;
  ros::spinOnce();
  this->readParser();
  if(++time2 >= 2) time2 = 0,this->sendControl();
}

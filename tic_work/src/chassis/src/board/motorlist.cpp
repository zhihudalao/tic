#include "motorlist.h"
#include "extur.h"
#include "info.h"

/****************************************
* 作者/公司  : ***
* 函数介绍   : 刷盘电机控制逻辑
* 输入参数   :
* 输出参数   :
* 返回值     :
*****************************************/
void Motorlist::runContorlBush()
{
  NodeData.motor.brush.dSpeed = NodeData.motor.brush.controlCmd;
}

/****************************************
* 作者/公司  : ***
* 函数介绍   : 刷盘升降电机控制逻辑
* 输入参数   :
* 输出参数   :
* 返回值     :
*****************************************/
void Motorlist::runContorlBushLift()
{
  NodeData.motor.brushLift.dSpeed = NodeData.motor.brushLift.controlCmd;
}

/****************************************
* 作者/公司  : ***
* 函数介绍   : 喷水电机控制逻辑
* 输入参数   :
* 输出参数   :
* 返回值     :
*****************************************/
void Motorlist::runContorlWaterSpray()
{
  NodeData.motor.waterSpray.dSpeed = NodeData.motor.waterSpray.controlCmd;
  if(NodeData.motor.waterSpray.controlCmd > 0)
  {
    NodeData.cmd_valve = 1;
  }
  else
  {
    NodeData.cmd_valve = 0;
  }
}

/****************************************
* 作者/公司  : ***
* 函数介绍   : 吸水条电机控制逻辑
* 输入参数   :
* 输出参数   :
* 返回值     :
*****************************************/
void Motorlist::runContorlWaterLift()
{
  NodeData.motor.wiperLift.dSpeed = NodeData.motor.wiperLift.controlCmd;
}

/****************************************
* 作者/公司  : ***
* 函数介绍   : 吸风电机控制逻辑
* 输入参数   :
* 输出参数   :
* 返回值     :
*****************************************/
void Motorlist::runContorlVacuum()
{
  NodeData.motor.vacuum.dSpeed = NodeData.motor.vacuum.controlCmd;
}

/****************************************
* 作者/公司  : ***
* 函数介绍   : 电机加减速控制
* 输入参数   :
* 输出参数   :
* 返回值     :
*****************************************/
void Motorlist::subAcceleration(int32_t espeed,int32_t *aspeed)
{
  if(*aspeed < espeed) //加速度
  {
    *aspeed += move_motor_accel;
    if (*aspeed > espeed)
    {
      *aspeed = espeed;
    }
  }
  else //减速度
  {
    *aspeed -= move_motor_accel;
    if (*aspeed < espeed)
    {
      *aspeed = espeed;
    }
  }
}

/****************************************
* 作者/公司  : ***
* 函数介绍   : 行走电机加减速控制
* 输入参数   :
* 输出参数   :
* 返回值     :
*****************************************/
void Motorlist::accelerationMove(int32_t lespeed, int32_t respeed, int32_t *laspeed, int32_t *raspeed)
{
  subAcceleration(lespeed, laspeed);
  subAcceleration(respeed, raspeed);
}

/****************************************
* 作者/公司  : ***
* 函数介绍   : 行走电机控制逻辑
* 输入参数   :
* 输出参数   :
* 返回值     :
*****************************************/
void Motorlist::runSubContorlMove(int32_t lspeed, int32_t rspeed)
{
  static bool cmd_val_timeout = true; //cmd_val 断线检测

  //设置下位机速度
  ros::Time timenew = ros::Time::now(); //获取当前时间
  if(timenew > (NodeData.motor.move.cmdValTimeout + (ros::Duration(NodeData.topicTimout)))) //如果 cmd_val topic 超时
  {
    if(!cmd_val_timeout)
    {
      ROS_WARN("motorlistener node --> cmd_val topic timeout");
      cmd_val_timeout = true;
    }

    NodeData.motor.move.cmd_LeftSpeed = 0;
    NodeData.motor.move.cmd_RightSpeed = 0;
  }
  else if(NodeData.key.emergency)
  {
    NodeData.motor.move.cmd_LeftSpeed = 0;
    NodeData.motor.move.cmd_RightSpeed = 0;
  }
  else
  {
    cmd_val_timeout = false;
    accelerationMove(lspeed, rspeed, &NodeData.motor.move.cmd_LeftSpeed, &NodeData.motor.move.cmd_RightSpeed);
  }
}

/****************************************
* 作者/公司  : ***
* 函数介绍   : 行走电机控制
* 输入参数   :
* 输出参数   :
* 返回值     :
*****************************************/
void Motorlist::runContorlMove()
{
  int32_t left_speed = 0;
  int32_t right_speed = 0;

  int32_t v1 = 0;
  int32_t v2 = 0;
  int32_t v3 = 0;
  
  chassisFourWheelAlgorithm(NodeData.motor.move.cmdVal, &left_speed, &right_speed);
  chassisFourWheelAlgorithm(NodeData.motor.move.cmdVal, &v1, &v2, &v3);

  runSubContorlMove(left_speed,right_speed);
}

Motorlist::Motorlist()
{
  this->run_rate = 50;
  this->ticks_per_meter = NodeData.motor.move.encoder_resolution * NodeData.motor.move.downGearReduction / (NodeData.motor.move.wheel_diameter * MATH_PI);
  /*
  ROS_INFO("enco = %f %d %f %f",
  this->ticks_per_meter,
  ParamList.moveMotor.encoder_resolution,
  ParamList.moveMotor.gear_reduction,
  ParamList.moveMotor.wheel_diameter);
*/
  this->move_motor_accel = NodeData.motor.move.accel_limit * this->ticks_per_meter / run_rate; //启动时的加速度，停止时的减速带
}

void Motorlist::run()
{
  this->runContorlBush();
  this->runContorlBushLift();
  this->runContorlWaterSpray();
  this->runContorlWaterLift();
  this->runContorlVacuum();
  this->runContorlMove();
  this->runContorOther();
}

/****************************************
* 作者/公司  : chip
* 函数介绍   : 其他控制
* 输入参数   :
* 输出参数   :
* 返回值     :
*****************************************/
void Motorlist::runContorOther()
{
  if(NodeData.key.power)
  {
    TIC_LOG_ERROR("shutdown");
    //sleep(2);
    //system("shutdown -P now");//钥匙开关关机
  }

  if(NodeData.key.breakAntiCollision)
  {
    TIC_LOG_WARN("break Anti Collision");
  }

  if(NodeData.key.frontAntiCollision)
  {
    TIC_LOG_WARN("front Anti Collision");
  }
}

/****************************************
* 作者/公司  : chip
* 函数介绍   : 线速度角速度计算为轮子的真实速度,三轮全向
* 输入参数   :
* 输出参数   :
* 返回值     :
*****************************************/
void Motorlist::chassisFourWheelAlgorithm(geometry_msgs::Twist cmdval, int32_t *one, int32_t *tow, int32_t *three)
{
  #define COS60  (0.5f)
  #define SIN60  (0.8602496f)

  float center_distance = NodeData.motor.move.centerDistance; //两轮中心距
  float gear_reduction = NodeData.motor.move.downGearReduction;//减速比
  float wheel_track = NodeData.motor.move.wheel_diameter * MATH_PI;//轮子周长

  float vx = cmdval.linear.x;
  float vy = cmdval.linear.y;
  float vz = cmdval.angular.z;

  //计算每个轮子转速
  float v1 = (-COS60*vx + SIN60*vy + center_distance * vz);
  float v2 = (-COS60*vx - SIN60*vy + center_distance * vz);
  float v3 = (vx + center_distance * vz);

  //计算转速: rpm = （v * 60秒  * 减速比）/ (轮子周长)
  float v1_rpm = (v1 * 60 * gear_reduction) / wheel_track;
  float v2_rpm = (v2 * 60 * gear_reduction) / wheel_track;
  float v3_rpm = (v3 * 60 * gear_reduction) / wheel_track;
}

/****************************************
* 作者/公司  : chip
* 函数介绍   : 线速度角速度计算为轮子的真实速度，后轮驱动
* 输入参数   :
* 输出参数   :
* 返回值     :
*****************************************/
void Motorlist::chassisFourWheelAlgorithm(geometry_msgs::Twist cmdval, int32_t *left, int32_t *right)
{
  float linear_v = cmdval.linear.x; //线速度
  float angular_v = cmdval.angular.z; //角速度
  float center_distance = NodeData.motor.move.centerDistance; //两轮中心距
  float gear_reduction = NodeData.motor.move.downGearReduction; //减速比
  float wheel_track = NodeData.motor.move.wheel_diameter * MATH_PI; //轮子周长

  float left_v = 0; //左轮速度　m/s
  float right_v = 0; //右轮速度　m/s
  float left_rpm = 0; //左轮速度　rpm
  float right_rpm = 0; //右轮速度　rpm

  //限制最大角速度
  if(angular_v > 0.3) angular_v = 0.3;
  else if(angular_v < -0.3) angular_v = -0.3;

  //限制最大线速度
  if(linear_v > 0.5) linear_v = 0.5;
  else if(linear_v < -0.5) linear_v = -0.5;

  //计算左右轮速度 m/s
  if(linear_v == 0) right_v = (angular_v * center_distance / 2.0), left_v = -right_v;
  else if(angular_v == 0) left_v = right_v = linear_v;
  else left_v = linear_v - (angular_v * center_distance / 2.0), right_v = linear_v + (angular_v * center_distance / 2.0);

  //计算转速: rpm = （v * 60秒  * 减速比）/ (轮子周长)
  left_rpm = (left_v * 60 * gear_reduction ) / (wheel_track);
  right_rpm = (right_v * 60 * gear_reduction ) / (wheel_track);

  //设置速度值
  *left = left_rpm;
  *right = right_rpm;
}

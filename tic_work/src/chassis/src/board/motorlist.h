#ifndef __CONTORL_H__
#define __CONTORL_H__

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

class Motorlist
{
public:
  Motorlist();
  void run();

private:
  int32_t move_motor_accel; //移动电机加速度减速度
  float ticks_per_meter;
  float run_rate;

  //行走电机控制
  void runContorlMove();
  //行走电机控制逻辑
  void runSubContorlMove(int32_t lspeed, int32_t rspeed);
  //刷盘电机控制逻辑
  void runContorlBush();
  //刷盘升降电机控制逻辑
  void runContorlBushLift();
  //喷水电机控制逻辑
  void runContorlWaterSpray();
  //吸水条电机控制逻辑
  void runContorlWaterLift();
  //吸风电机控制逻辑
  void runContorlVacuum();
  //其他控制
  void runContorOther();
  //线速度角速度计算为轮子的真实速度，后轮驱动
  void chassisFourWheelAlgorithm(geometry_msgs::Twist cmdval, int32_t *left, int32_t *right);
  //线速度角速度计算为轮子的真实速度，三轮全向
  void chassisFourWheelAlgorithm(geometry_msgs::Twist cmdval, int32_t *one, int32_t *tow, int32_t *three);

  //行走电机加减速控制
  void accelerationMove(int32_t lespeed, int32_t respeed, int32_t *laspeed, int32_t *raspeed);
  //电机加减速控制
  void subAcceleration(int32_t espeed,int32_t *aspeed);
};

#endif

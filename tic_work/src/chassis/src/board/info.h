#ifndef __INFO_H__
#define __INFO_H__

#include "boardDown.h"
#include <geometry_msgs/Twist.h>
#include <diagnostic_msgs/DiagnosticStatus.h>
#include "extur.h"

using namespace std;

class InfoCmdList
{
public:
  InfoCmdList();
  void run();

private:
  ros::Publisher boardPub;
  ros::Publisher odom_pub;
  ros::Timer time20;
  ros::Publisher sonar[8];
  ros::Subscriber cmdval;
  ros::Subscriber wash;
  BaordDown board;
  struct odomParamList_Type odomData;

  //获取参数
  bool getParam(ros::NodeHandle *nh);
  //后轮驱动底盘计算并发送odom
  void odomPublish(int32_t leftEncoder, int32_t rightEncoder, int32_t timer);
  //三轮全向驱动底盘计算并发送odom
  void odomPublish(int32_t *one_encoder, int32_t *tow_encoder, int32_t *three_encoder, int32_t timer);
  //发送超声相关数据
  void publishSonar();
  //发送其他数据
  void boardPublish();
  //读取并处理下位机数据
  void readParser();
  //控制下位机相关状态
  void sendControl();
  void InitData();

  //Callback
  void cmdVelCallback(const geometry_msgs::Twist msg);
  void boardCmdVelCallback(const diagnostic_msgs::DiagnosticStatus msg);
  void timer20msCallback(const ros::TimerEvent& event);
};

#endif

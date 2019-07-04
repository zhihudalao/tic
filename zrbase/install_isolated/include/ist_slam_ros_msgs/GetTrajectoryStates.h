// Generated by gencpp from file ist_slam_ros_msgs/GetTrajectoryStates.msg
// DO NOT EDIT!


#ifndef IST_SLAM_ROS_MSGS_MESSAGE_GETTRAJECTORYSTATES_H
#define IST_SLAM_ROS_MSGS_MESSAGE_GETTRAJECTORYSTATES_H

#include <ros/service_traits.h>


#include <ist_slam_ros_msgs/GetTrajectoryStatesRequest.h>
#include <ist_slam_ros_msgs/GetTrajectoryStatesResponse.h>


namespace ist_slam_ros_msgs
{

struct GetTrajectoryStates
{

typedef GetTrajectoryStatesRequest Request;
typedef GetTrajectoryStatesResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct GetTrajectoryStates
} // namespace ist_slam_ros_msgs


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::ist_slam_ros_msgs::GetTrajectoryStates > {
  static const char* value()
  {
    return "b9e3b373f17df088ee6dcd817b79dff0";
  }

  static const char* value(const ::ist_slam_ros_msgs::GetTrajectoryStates&) { return value(); }
};

template<>
struct DataType< ::ist_slam_ros_msgs::GetTrajectoryStates > {
  static const char* value()
  {
    return "ist_slam_ros_msgs/GetTrajectoryStates";
  }

  static const char* value(const ::ist_slam_ros_msgs::GetTrajectoryStates&) { return value(); }
};


// service_traits::MD5Sum< ::ist_slam_ros_msgs::GetTrajectoryStatesRequest> should match 
// service_traits::MD5Sum< ::ist_slam_ros_msgs::GetTrajectoryStates > 
template<>
struct MD5Sum< ::ist_slam_ros_msgs::GetTrajectoryStatesRequest>
{
  static const char* value()
  {
    return MD5Sum< ::ist_slam_ros_msgs::GetTrajectoryStates >::value();
  }
  static const char* value(const ::ist_slam_ros_msgs::GetTrajectoryStatesRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::ist_slam_ros_msgs::GetTrajectoryStatesRequest> should match 
// service_traits::DataType< ::ist_slam_ros_msgs::GetTrajectoryStates > 
template<>
struct DataType< ::ist_slam_ros_msgs::GetTrajectoryStatesRequest>
{
  static const char* value()
  {
    return DataType< ::ist_slam_ros_msgs::GetTrajectoryStates >::value();
  }
  static const char* value(const ::ist_slam_ros_msgs::GetTrajectoryStatesRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::ist_slam_ros_msgs::GetTrajectoryStatesResponse> should match 
// service_traits::MD5Sum< ::ist_slam_ros_msgs::GetTrajectoryStates > 
template<>
struct MD5Sum< ::ist_slam_ros_msgs::GetTrajectoryStatesResponse>
{
  static const char* value()
  {
    return MD5Sum< ::ist_slam_ros_msgs::GetTrajectoryStates >::value();
  }
  static const char* value(const ::ist_slam_ros_msgs::GetTrajectoryStatesResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::ist_slam_ros_msgs::GetTrajectoryStatesResponse> should match 
// service_traits::DataType< ::ist_slam_ros_msgs::GetTrajectoryStates > 
template<>
struct DataType< ::ist_slam_ros_msgs::GetTrajectoryStatesResponse>
{
  static const char* value()
  {
    return DataType< ::ist_slam_ros_msgs::GetTrajectoryStates >::value();
  }
  static const char* value(const ::ist_slam_ros_msgs::GetTrajectoryStatesResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // IST_SLAM_ROS_MSGS_MESSAGE_GETTRAJECTORYSTATES_H
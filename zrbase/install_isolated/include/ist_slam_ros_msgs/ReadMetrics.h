// Generated by gencpp from file ist_slam_ros_msgs/ReadMetrics.msg
// DO NOT EDIT!


#ifndef IST_SLAM_ROS_MSGS_MESSAGE_READMETRICS_H
#define IST_SLAM_ROS_MSGS_MESSAGE_READMETRICS_H

#include <ros/service_traits.h>


#include <ist_slam_ros_msgs/ReadMetricsRequest.h>
#include <ist_slam_ros_msgs/ReadMetricsResponse.h>


namespace ist_slam_ros_msgs
{

struct ReadMetrics
{

typedef ReadMetricsRequest Request;
typedef ReadMetricsResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct ReadMetrics
} // namespace ist_slam_ros_msgs


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::ist_slam_ros_msgs::ReadMetrics > {
  static const char* value()
  {
    return "a1fe8d7dcf3708e96e015774b1df470e";
  }

  static const char* value(const ::ist_slam_ros_msgs::ReadMetrics&) { return value(); }
};

template<>
struct DataType< ::ist_slam_ros_msgs::ReadMetrics > {
  static const char* value()
  {
    return "ist_slam_ros_msgs/ReadMetrics";
  }

  static const char* value(const ::ist_slam_ros_msgs::ReadMetrics&) { return value(); }
};


// service_traits::MD5Sum< ::ist_slam_ros_msgs::ReadMetricsRequest> should match 
// service_traits::MD5Sum< ::ist_slam_ros_msgs::ReadMetrics > 
template<>
struct MD5Sum< ::ist_slam_ros_msgs::ReadMetricsRequest>
{
  static const char* value()
  {
    return MD5Sum< ::ist_slam_ros_msgs::ReadMetrics >::value();
  }
  static const char* value(const ::ist_slam_ros_msgs::ReadMetricsRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::ist_slam_ros_msgs::ReadMetricsRequest> should match 
// service_traits::DataType< ::ist_slam_ros_msgs::ReadMetrics > 
template<>
struct DataType< ::ist_slam_ros_msgs::ReadMetricsRequest>
{
  static const char* value()
  {
    return DataType< ::ist_slam_ros_msgs::ReadMetrics >::value();
  }
  static const char* value(const ::ist_slam_ros_msgs::ReadMetricsRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::ist_slam_ros_msgs::ReadMetricsResponse> should match 
// service_traits::MD5Sum< ::ist_slam_ros_msgs::ReadMetrics > 
template<>
struct MD5Sum< ::ist_slam_ros_msgs::ReadMetricsResponse>
{
  static const char* value()
  {
    return MD5Sum< ::ist_slam_ros_msgs::ReadMetrics >::value();
  }
  static const char* value(const ::ist_slam_ros_msgs::ReadMetricsResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::ist_slam_ros_msgs::ReadMetricsResponse> should match 
// service_traits::DataType< ::ist_slam_ros_msgs::ReadMetrics > 
template<>
struct DataType< ::ist_slam_ros_msgs::ReadMetricsResponse>
{
  static const char* value()
  {
    return DataType< ::ist_slam_ros_msgs::ReadMetrics >::value();
  }
  static const char* value(const ::ist_slam_ros_msgs::ReadMetricsResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // IST_SLAM_ROS_MSGS_MESSAGE_READMETRICS_H
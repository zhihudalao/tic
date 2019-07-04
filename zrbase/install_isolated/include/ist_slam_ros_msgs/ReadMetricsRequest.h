// Generated by gencpp from file ist_slam_ros_msgs/ReadMetricsRequest.msg
// DO NOT EDIT!


#ifndef IST_SLAM_ROS_MSGS_MESSAGE_READMETRICSREQUEST_H
#define IST_SLAM_ROS_MSGS_MESSAGE_READMETRICSREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace ist_slam_ros_msgs
{
template <class ContainerAllocator>
struct ReadMetricsRequest_
{
  typedef ReadMetricsRequest_<ContainerAllocator> Type;

  ReadMetricsRequest_()
    {
    }
  ReadMetricsRequest_(const ContainerAllocator& _alloc)
    {
  (void)_alloc;
    }







  typedef boost::shared_ptr< ::ist_slam_ros_msgs::ReadMetricsRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ist_slam_ros_msgs::ReadMetricsRequest_<ContainerAllocator> const> ConstPtr;

}; // struct ReadMetricsRequest_

typedef ::ist_slam_ros_msgs::ReadMetricsRequest_<std::allocator<void> > ReadMetricsRequest;

typedef boost::shared_ptr< ::ist_slam_ros_msgs::ReadMetricsRequest > ReadMetricsRequestPtr;
typedef boost::shared_ptr< ::ist_slam_ros_msgs::ReadMetricsRequest const> ReadMetricsRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ist_slam_ros_msgs::ReadMetricsRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ist_slam_ros_msgs::ReadMetricsRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace ist_slam_ros_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'ist_slam_ros_msgs': ['/home/ubuntu/zrbase/src/ist_slam_ros/ist_slam_ros_msgs/msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::ist_slam_ros_msgs::ReadMetricsRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ist_slam_ros_msgs::ReadMetricsRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ist_slam_ros_msgs::ReadMetricsRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ist_slam_ros_msgs::ReadMetricsRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ist_slam_ros_msgs::ReadMetricsRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ist_slam_ros_msgs::ReadMetricsRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ist_slam_ros_msgs::ReadMetricsRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d41d8cd98f00b204e9800998ecf8427e";
  }

  static const char* value(const ::ist_slam_ros_msgs::ReadMetricsRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd41d8cd98f00b204ULL;
  static const uint64_t static_value2 = 0xe9800998ecf8427eULL;
};

template<class ContainerAllocator>
struct DataType< ::ist_slam_ros_msgs::ReadMetricsRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ist_slam_ros_msgs/ReadMetricsRequest";
  }

  static const char* value(const ::ist_slam_ros_msgs::ReadMetricsRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ist_slam_ros_msgs::ReadMetricsRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n\
";
  }

  static const char* value(const ::ist_slam_ros_msgs::ReadMetricsRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ist_slam_ros_msgs::ReadMetricsRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream&, T)
    {}

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ReadMetricsRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ist_slam_ros_msgs::ReadMetricsRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream&, const std::string&, const ::ist_slam_ros_msgs::ReadMetricsRequest_<ContainerAllocator>&)
  {}
};

} // namespace message_operations
} // namespace ros

#endif // IST_SLAM_ROS_MSGS_MESSAGE_READMETRICSREQUEST_H
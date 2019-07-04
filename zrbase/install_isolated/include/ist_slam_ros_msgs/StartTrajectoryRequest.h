// Generated by gencpp from file ist_slam_ros_msgs/StartTrajectoryRequest.msg
// DO NOT EDIT!


#ifndef IST_SLAM_ROS_MSGS_MESSAGE_STARTTRAJECTORYREQUEST_H
#define IST_SLAM_ROS_MSGS_MESSAGE_STARTTRAJECTORYREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <ist_slam_ros_msgs/TrajectoryOptions.h>
#include <ist_slam_ros_msgs/SensorTopics.h>

namespace ist_slam_ros_msgs
{
template <class ContainerAllocator>
struct StartTrajectoryRequest_
{
  typedef StartTrajectoryRequest_<ContainerAllocator> Type;

  StartTrajectoryRequest_()
    : options()
    , topics()  {
    }
  StartTrajectoryRequest_(const ContainerAllocator& _alloc)
    : options(_alloc)
    , topics(_alloc)  {
  (void)_alloc;
    }



   typedef  ::ist_slam_ros_msgs::TrajectoryOptions_<ContainerAllocator>  _options_type;
  _options_type options;

   typedef  ::ist_slam_ros_msgs::SensorTopics_<ContainerAllocator>  _topics_type;
  _topics_type topics;





  typedef boost::shared_ptr< ::ist_slam_ros_msgs::StartTrajectoryRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ist_slam_ros_msgs::StartTrajectoryRequest_<ContainerAllocator> const> ConstPtr;

}; // struct StartTrajectoryRequest_

typedef ::ist_slam_ros_msgs::StartTrajectoryRequest_<std::allocator<void> > StartTrajectoryRequest;

typedef boost::shared_ptr< ::ist_slam_ros_msgs::StartTrajectoryRequest > StartTrajectoryRequestPtr;
typedef boost::shared_ptr< ::ist_slam_ros_msgs::StartTrajectoryRequest const> StartTrajectoryRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ist_slam_ros_msgs::StartTrajectoryRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ist_slam_ros_msgs::StartTrajectoryRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace ist_slam_ros_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'ist_slam_ros_msgs': ['/home/ubuntu/zrbase/src/ist_slam_ros/ist_slam_ros_msgs/msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::ist_slam_ros_msgs::StartTrajectoryRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ist_slam_ros_msgs::StartTrajectoryRequest_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ist_slam_ros_msgs::StartTrajectoryRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ist_slam_ros_msgs::StartTrajectoryRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ist_slam_ros_msgs::StartTrajectoryRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ist_slam_ros_msgs::StartTrajectoryRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ist_slam_ros_msgs::StartTrajectoryRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "0780da312468afe59b45454db35b17ed";
  }

  static const char* value(const ::ist_slam_ros_msgs::StartTrajectoryRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x0780da312468afe5ULL;
  static const uint64_t static_value2 = 0x9b45454db35b17edULL;
};

template<class ContainerAllocator>
struct DataType< ::ist_slam_ros_msgs::StartTrajectoryRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ist_slam_ros_msgs/StartTrajectoryRequest";
  }

  static const char* value(const ::ist_slam_ros_msgs::StartTrajectoryRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ist_slam_ros_msgs::StartTrajectoryRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n\
ist_slam_ros_msgs/TrajectoryOptions options\n\
ist_slam_ros_msgs/SensorTopics topics\n\
\n\
================================================================================\n\
MSG: ist_slam_ros_msgs/TrajectoryOptions\n\
\n\
string tracking_frame\n\
string published_frame\n\
string odom_frame\n\
bool provide_odom_frame\n\
bool use_odometry\n\
bool use_nav_sat\n\
bool use_landmarks\n\
bool publish_frame_projected_to_2d\n\
int32 num_laser_scans\n\
int32 num_multi_echo_laser_scans\n\
int32 num_subdivisions_per_laser_scan\n\
int32 num_point_clouds\n\
float64 rangefinder_sampling_ratio\n\
float64 odometry_sampling_ratio\n\
float64 fixed_frame_pose_sampling_ratio\n\
float64 imu_sampling_ratio\n\
float64 landmarks_sampling_ratio\n\
\n\
# This is a binary-encoded\n\
# 'ist_slam.mapping.proto.TrajectoryBuilderOptions' proto.\n\
string trajectory_builder_options_proto\n\
\n\
================================================================================\n\
MSG: ist_slam_ros_msgs/SensorTopics\n\
\n\
string laser_scan_topic\n\
string multi_echo_laser_scan_topic\n\
string point_cloud2_topic\n\
string imu_topic\n\
string odometry_topic\n\
string nav_sat_fix_topic\n\
string landmark_topic\n\
";
  }

  static const char* value(const ::ist_slam_ros_msgs::StartTrajectoryRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ist_slam_ros_msgs::StartTrajectoryRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.options);
      stream.next(m.topics);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct StartTrajectoryRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ist_slam_ros_msgs::StartTrajectoryRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ist_slam_ros_msgs::StartTrajectoryRequest_<ContainerAllocator>& v)
  {
    s << indent << "options: ";
    s << std::endl;
    Printer< ::ist_slam_ros_msgs::TrajectoryOptions_<ContainerAllocator> >::stream(s, indent + "  ", v.options);
    s << indent << "topics: ";
    s << std::endl;
    Printer< ::ist_slam_ros_msgs::SensorTopics_<ContainerAllocator> >::stream(s, indent + "  ", v.topics);
  }
};

} // namespace message_operations
} // namespace ros

#endif // IST_SLAM_ROS_MSGS_MESSAGE_STARTTRAJECTORYREQUEST_H

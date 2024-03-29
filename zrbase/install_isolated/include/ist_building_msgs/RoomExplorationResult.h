// Generated by gencpp from file ist_building_msgs/RoomExplorationResult.msg
// DO NOT EDIT!


#ifndef IST_BUILDING_MSGS_MESSAGE_ROOMEXPLORATIONRESULT_H
#define IST_BUILDING_MSGS_MESSAGE_ROOMEXPLORATIONRESULT_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <geometry_msgs/Pose2D.h>
#include <geometry_msgs/PoseStamped.h>

namespace ist_building_msgs
{
template <class ContainerAllocator>
struct RoomExplorationResult_
{
  typedef RoomExplorationResult_<ContainerAllocator> Type;

  RoomExplorationResult_()
    : coverage_path()
    , coverage_path_pose_stamped()  {
    }
  RoomExplorationResult_(const ContainerAllocator& _alloc)
    : coverage_path(_alloc)
    , coverage_path_pose_stamped(_alloc)  {
  (void)_alloc;
    }



   typedef std::vector< ::geometry_msgs::Pose2D_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::geometry_msgs::Pose2D_<ContainerAllocator> >::other >  _coverage_path_type;
  _coverage_path_type coverage_path;

   typedef std::vector< ::geometry_msgs::PoseStamped_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::geometry_msgs::PoseStamped_<ContainerAllocator> >::other >  _coverage_path_pose_stamped_type;
  _coverage_path_pose_stamped_type coverage_path_pose_stamped;





  typedef boost::shared_ptr< ::ist_building_msgs::RoomExplorationResult_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ist_building_msgs::RoomExplorationResult_<ContainerAllocator> const> ConstPtr;

}; // struct RoomExplorationResult_

typedef ::ist_building_msgs::RoomExplorationResult_<std::allocator<void> > RoomExplorationResult;

typedef boost::shared_ptr< ::ist_building_msgs::RoomExplorationResult > RoomExplorationResultPtr;
typedef boost::shared_ptr< ::ist_building_msgs::RoomExplorationResult const> RoomExplorationResultConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ist_building_msgs::RoomExplorationResult_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ist_building_msgs::RoomExplorationResult_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace ist_building_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'sensor_msgs': ['/opt/ros/kinetic/share/sensor_msgs/cmake/../msg'], 'actionlib_msgs': ['/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'ist_building_msgs': ['/home/ubuntu/zrbase/devel_isolated/ist_building_msgs/share/ist_building_msgs/msg', '/home/ubuntu/zrbase/src/caei/ist_exploration/ist_building_msgs/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::ist_building_msgs::RoomExplorationResult_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ist_building_msgs::RoomExplorationResult_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ist_building_msgs::RoomExplorationResult_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ist_building_msgs::RoomExplorationResult_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ist_building_msgs::RoomExplorationResult_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ist_building_msgs::RoomExplorationResult_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ist_building_msgs::RoomExplorationResult_<ContainerAllocator> >
{
  static const char* value()
  {
    return "12d0bcf4cde501321f572592c0c514da";
  }

  static const char* value(const ::ist_building_msgs::RoomExplorationResult_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x12d0bcf4cde50132ULL;
  static const uint64_t static_value2 = 0x1f572592c0c514daULL;
};

template<class ContainerAllocator>
struct DataType< ::ist_building_msgs::RoomExplorationResult_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ist_building_msgs/RoomExplorationResult";
  }

  static const char* value(const ::ist_building_msgs::RoomExplorationResult_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ist_building_msgs::RoomExplorationResult_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
# result definition\n\
geometry_msgs/Pose2D[] coverage_path			# when the server should return the coverage path, this is done returning the points in an array that shows the order of visiting\n\
geometry_msgs/PoseStamped[] coverage_path_pose_stamped			# (same content as coverage_path but different format) when the server should return the coverage path, this is done returning the points in an array that shows the order of visiting\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Pose2D\n\
# Deprecated\n\
# Please use the full 3D pose.\n\
\n\
# In general our recommendation is to use a full 3D representation of everything and for 2D specific applications make the appropriate projections into the plane for their calculations but optimally will preserve the 3D information during processing.\n\
\n\
# If we have parallel copies of 2D datatypes every UI and other pipeline will end up needing to have dual interfaces to plot everything. And you will end up with not being able to use 3D tools for 2D use cases even if they're completely valid, as you'd have to reimplement it with different inputs and outputs. It's not particularly hard to plot the 2D pose or compute the yaw error for the Pose message and there are already tools and libraries that can do this for you.\n\
\n\
\n\
# This expresses a position and orientation on a 2D manifold.\n\
\n\
float64 x\n\
float64 y\n\
float64 theta\n\
\n\
================================================================================\n\
MSG: geometry_msgs/PoseStamped\n\
# A Pose with reference coordinate frame and timestamp\n\
Header header\n\
Pose pose\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Pose\n\
# A representation of pose in free space, composed of position and orientation. \n\
Point position\n\
Quaternion orientation\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Point\n\
# This contains the position of a point in free space\n\
float64 x\n\
float64 y\n\
float64 z\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Quaternion\n\
# This represents an orientation in free space in quaternion form.\n\
\n\
float64 x\n\
float64 y\n\
float64 z\n\
float64 w\n\
";
  }

  static const char* value(const ::ist_building_msgs::RoomExplorationResult_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ist_building_msgs::RoomExplorationResult_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.coverage_path);
      stream.next(m.coverage_path_pose_stamped);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct RoomExplorationResult_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ist_building_msgs::RoomExplorationResult_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ist_building_msgs::RoomExplorationResult_<ContainerAllocator>& v)
  {
    s << indent << "coverage_path[]" << std::endl;
    for (size_t i = 0; i < v.coverage_path.size(); ++i)
    {
      s << indent << "  coverage_path[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::geometry_msgs::Pose2D_<ContainerAllocator> >::stream(s, indent + "    ", v.coverage_path[i]);
    }
    s << indent << "coverage_path_pose_stamped[]" << std::endl;
    for (size_t i = 0; i < v.coverage_path_pose_stamped.size(); ++i)
    {
      s << indent << "  coverage_path_pose_stamped[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::geometry_msgs::PoseStamped_<ContainerAllocator> >::stream(s, indent + "    ", v.coverage_path_pose_stamped[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // IST_BUILDING_MSGS_MESSAGE_ROOMEXPLORATIONRESULT_H

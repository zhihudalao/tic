// Generated by gencpp from file ist_slam_ros_msgs/SubmapList.msg
// DO NOT EDIT!


#ifndef IST_SLAM_ROS_MSGS_MESSAGE_SUBMAPLIST_H
#define IST_SLAM_ROS_MSGS_MESSAGE_SUBMAPLIST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>
#include <ist_slam_ros_msgs/SubmapEntry.h>

namespace ist_slam_ros_msgs
{
template <class ContainerAllocator>
struct SubmapList_
{
  typedef SubmapList_<ContainerAllocator> Type;

  SubmapList_()
    : header()
    , submap()  {
    }
  SubmapList_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , submap(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef std::vector< ::ist_slam_ros_msgs::SubmapEntry_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::ist_slam_ros_msgs::SubmapEntry_<ContainerAllocator> >::other >  _submap_type;
  _submap_type submap;





  typedef boost::shared_ptr< ::ist_slam_ros_msgs::SubmapList_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ist_slam_ros_msgs::SubmapList_<ContainerAllocator> const> ConstPtr;

}; // struct SubmapList_

typedef ::ist_slam_ros_msgs::SubmapList_<std::allocator<void> > SubmapList;

typedef boost::shared_ptr< ::ist_slam_ros_msgs::SubmapList > SubmapListPtr;
typedef boost::shared_ptr< ::ist_slam_ros_msgs::SubmapList const> SubmapListConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ist_slam_ros_msgs::SubmapList_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ist_slam_ros_msgs::SubmapList_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace ist_slam_ros_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'ist_slam_ros_msgs': ['/home/ubuntu/zrbase/src/ist_slam_ros/ist_slam_ros_msgs/msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::ist_slam_ros_msgs::SubmapList_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ist_slam_ros_msgs::SubmapList_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ist_slam_ros_msgs::SubmapList_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ist_slam_ros_msgs::SubmapList_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ist_slam_ros_msgs::SubmapList_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ist_slam_ros_msgs::SubmapList_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ist_slam_ros_msgs::SubmapList_<ContainerAllocator> >
{
  static const char* value()
  {
    return "73b1e412208f0787050395996f6143db";
  }

  static const char* value(const ::ist_slam_ros_msgs::SubmapList_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x73b1e412208f0787ULL;
  static const uint64_t static_value2 = 0x050395996f6143dbULL;
};

template<class ContainerAllocator>
struct DataType< ::ist_slam_ros_msgs::SubmapList_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ist_slam_ros_msgs/SubmapList";
  }

  static const char* value(const ::ist_slam_ros_msgs::SubmapList_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ist_slam_ros_msgs::SubmapList_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n\
std_msgs/Header header\n\
ist_slam_ros_msgs/SubmapEntry[] submap\n\
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
MSG: ist_slam_ros_msgs/SubmapEntry\n\
\n\
int32 trajectory_id\n\
int32 submap_index\n\
int32 submap_version\n\
geometry_msgs/Pose pose\n\
bool is_frozen\n\
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

  static const char* value(const ::ist_slam_ros_msgs::SubmapList_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ist_slam_ros_msgs::SubmapList_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.submap);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct SubmapList_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ist_slam_ros_msgs::SubmapList_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ist_slam_ros_msgs::SubmapList_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "submap[]" << std::endl;
    for (size_t i = 0; i < v.submap.size(); ++i)
    {
      s << indent << "  submap[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::ist_slam_ros_msgs::SubmapEntry_<ContainerAllocator> >::stream(s, indent + "    ", v.submap[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // IST_SLAM_ROS_MSGS_MESSAGE_SUBMAPLIST_H

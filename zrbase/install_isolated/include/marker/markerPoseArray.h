// Generated by gencpp from file marker/markerPoseArray.msg
// DO NOT EDIT!


#ifndef MARKER_MESSAGE_MARKERPOSEARRAY_H
#define MARKER_MESSAGE_MARKERPOSEARRAY_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <marker/markerPose.h>

namespace marker
{
template <class ContainerAllocator>
struct markerPoseArray_
{
  typedef markerPoseArray_<ContainerAllocator> Type;

  markerPoseArray_()
    : markers()  {
    }
  markerPoseArray_(const ContainerAllocator& _alloc)
    : markers(_alloc)  {
  (void)_alloc;
    }



   typedef std::vector< ::marker::markerPose_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::marker::markerPose_<ContainerAllocator> >::other >  _markers_type;
  _markers_type markers;





  typedef boost::shared_ptr< ::marker::markerPoseArray_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::marker::markerPoseArray_<ContainerAllocator> const> ConstPtr;

}; // struct markerPoseArray_

typedef ::marker::markerPoseArray_<std::allocator<void> > markerPoseArray;

typedef boost::shared_ptr< ::marker::markerPoseArray > markerPoseArrayPtr;
typedef boost::shared_ptr< ::marker::markerPoseArray const> markerPoseArrayConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::marker::markerPoseArray_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::marker::markerPoseArray_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace marker

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'marker': ['/home/ubuntu/zrbase/src/marker/msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::marker::markerPoseArray_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::marker::markerPoseArray_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::marker::markerPoseArray_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::marker::markerPoseArray_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::marker::markerPoseArray_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::marker::markerPoseArray_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::marker::markerPoseArray_<ContainerAllocator> >
{
  static const char* value()
  {
    return "c5f6d3ea5a86708d66e8b0f23988b7f6";
  }

  static const char* value(const ::marker::markerPoseArray_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xc5f6d3ea5a86708dULL;
  static const uint64_t static_value2 = 0x66e8b0f23988b7f6ULL;
};

template<class ContainerAllocator>
struct DataType< ::marker::markerPoseArray_<ContainerAllocator> >
{
  static const char* value()
  {
    return "marker/markerPoseArray";
  }

  static const char* value(const ::marker::markerPoseArray_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::marker::markerPoseArray_<ContainerAllocator> >
{
  static const char* value()
  {
    return "marker/markerPose[] markers\n\
================================================================================\n\
MSG: marker/markerPose\n\
string name\n\
geometry_msgs/Pose pose\n\
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

  static const char* value(const ::marker::markerPoseArray_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::marker::markerPoseArray_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.markers);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct markerPoseArray_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::marker::markerPoseArray_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::marker::markerPoseArray_<ContainerAllocator>& v)
  {
    s << indent << "markers[]" << std::endl;
    for (size_t i = 0; i < v.markers.size(); ++i)
    {
      s << indent << "  markers[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::marker::markerPose_<ContainerAllocator> >::stream(s, indent + "    ", v.markers[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // MARKER_MESSAGE_MARKERPOSEARRAY_H
// Generated by gencpp from file ist_building_msgs/MapSegmentationResult.msg
// DO NOT EDIT!


#ifndef IST_BUILDING_MSGS_MESSAGE_MAPSEGMENTATIONRESULT_H
#define IST_BUILDING_MSGS_MESSAGE_MAPSEGMENTATIONRESULT_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <sensor_msgs/Image.h>
#include <geometry_msgs/Pose.h>
#include <ist_building_msgs/RoomInformation.h>
#include <ist_building_msgs/RoomInformation.h>
#include <geometry_msgs/Point32.h>

namespace ist_building_msgs
{
template <class ContainerAllocator>
struct MapSegmentationResult_
{
  typedef MapSegmentationResult_<ContainerAllocator> Type;

  MapSegmentationResult_()
    : segmented_map()
    , map_resolution(0.0)
    , map_origin()
    , room_information_in_pixel()
    , room_information_in_meter()
    , doorway_points()  {
    }
  MapSegmentationResult_(const ContainerAllocator& _alloc)
    : segmented_map(_alloc)
    , map_resolution(0.0)
    , map_origin(_alloc)
    , room_information_in_pixel(_alloc)
    , room_information_in_meter(_alloc)
    , doorway_points(_alloc)  {
  (void)_alloc;
    }



   typedef  ::sensor_msgs::Image_<ContainerAllocator>  _segmented_map_type;
  _segmented_map_type segmented_map;

   typedef float _map_resolution_type;
  _map_resolution_type map_resolution;

   typedef  ::geometry_msgs::Pose_<ContainerAllocator>  _map_origin_type;
  _map_origin_type map_origin;

   typedef std::vector< ::ist_building_msgs::RoomInformation_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::ist_building_msgs::RoomInformation_<ContainerAllocator> >::other >  _room_information_in_pixel_type;
  _room_information_in_pixel_type room_information_in_pixel;

   typedef std::vector< ::ist_building_msgs::RoomInformation_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::ist_building_msgs::RoomInformation_<ContainerAllocator> >::other >  _room_information_in_meter_type;
  _room_information_in_meter_type room_information_in_meter;

   typedef std::vector< ::geometry_msgs::Point32_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::geometry_msgs::Point32_<ContainerAllocator> >::other >  _doorway_points_type;
  _doorway_points_type doorway_points;





  typedef boost::shared_ptr< ::ist_building_msgs::MapSegmentationResult_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ist_building_msgs::MapSegmentationResult_<ContainerAllocator> const> ConstPtr;

}; // struct MapSegmentationResult_

typedef ::ist_building_msgs::MapSegmentationResult_<std::allocator<void> > MapSegmentationResult;

typedef boost::shared_ptr< ::ist_building_msgs::MapSegmentationResult > MapSegmentationResultPtr;
typedef boost::shared_ptr< ::ist_building_msgs::MapSegmentationResult const> MapSegmentationResultConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ist_building_msgs::MapSegmentationResult_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ist_building_msgs::MapSegmentationResult_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::ist_building_msgs::MapSegmentationResult_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ist_building_msgs::MapSegmentationResult_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ist_building_msgs::MapSegmentationResult_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ist_building_msgs::MapSegmentationResult_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ist_building_msgs::MapSegmentationResult_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ist_building_msgs::MapSegmentationResult_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ist_building_msgs::MapSegmentationResult_<ContainerAllocator> >
{
  static const char* value()
  {
    return "eb2ec1be8ee603d0cc882bfcd358371b";
  }

  static const char* value(const ::ist_building_msgs::MapSegmentationResult_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xeb2ec1be8ee603d0ULL;
  static const uint64_t static_value2 = 0xcc882bfcd358371bULL;
};

template<class ContainerAllocator>
struct DataType< ::ist_building_msgs::MapSegmentationResult_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ist_building_msgs/MapSegmentationResult";
  }

  static const char* value(const ::ist_building_msgs::MapSegmentationResult_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ist_building_msgs::MapSegmentationResult_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
\n\
# result definition\n\
sensor_msgs/Image segmented_map			# the action server returns a map segmented into rooms which carry the segment number in every pixel cell, format 32SC1, room labels from 1 to N, room with label i -> access to room_information_in_pixel[i-1]\n\
float32 map_resolution					# the resolution of the segmented map in [meter/cell]\n\
geometry_msgs/Pose map_origin			# the origin of the segmented map in [meter]\n\
# for the following data: value in pixel can be obtained when the value of [return_format_in_pixel] from goal definition is true\n\
# the computed room centers are not the centroids of the room cells (which could be located outside of the rooms)\n\
# but accessible map pixels located within the center of the largest free space in the room\n\
ist_building_msgs/RoomInformation[] room_information_in_pixel		# room data (min/max coordinates, center coordinates) measured in pixels\n\
# for the following data: value in meter can be obtained when the value of [return_format_in_meter] from goal definition is true\n\
# the computed room centers are not the centroids of the room cells (which could be located outside of the rooms)\n\
# but accessible map pixels located within the center of the largest free space in the room\n\
ist_building_msgs/RoomInformation[] room_information_in_meter		# room data (min/max coordinates, center coordinates) measured in meters\n\
# if wanted the 5th algorithm (vrf) can return single points labeled as a doorway\n\
geometry_msgs/Point32[] doorway_points\n\
\n\
\n\
================================================================================\n\
MSG: sensor_msgs/Image\n\
# This message contains an uncompressed image\n\
# (0, 0) is at top-left corner of image\n\
#\n\
\n\
Header header        # Header timestamp should be acquisition time of image\n\
                     # Header frame_id should be optical frame of camera\n\
                     # origin of frame should be optical center of camera\n\
                     # +x should point to the right in the image\n\
                     # +y should point down in the image\n\
                     # +z should point into to plane of the image\n\
                     # If the frame_id here and the frame_id of the CameraInfo\n\
                     # message associated with the image conflict\n\
                     # the behavior is undefined\n\
\n\
uint32 height         # image height, that is, number of rows\n\
uint32 width          # image width, that is, number of columns\n\
\n\
# The legal values for encoding are in file src/image_encodings.cpp\n\
# If you want to standardize a new string format, join\n\
# ros-users@lists.sourceforge.net and send an email proposing a new encoding.\n\
\n\
string encoding       # Encoding of pixels -- channel meaning, ordering, size\n\
                      # taken from the list of strings in include/sensor_msgs/image_encodings.h\n\
\n\
uint8 is_bigendian    # is this data bigendian?\n\
uint32 step           # Full row length in bytes\n\
uint8[] data          # actual matrix data, size is (step * rows)\n\
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
\n\
================================================================================\n\
MSG: ist_building_msgs/RoomInformation\n\
geometry_msgs/Polygon room_min_max		# first point provides the minimum (x,y)-coordinate values of the rooms, second point provides the maximum (x,y)-coordinate values of the rooms\n\
geometry_msgs/Point32 room_center		# provides the (x,y)-coordinate values of the room centers\n\
================================================================================\n\
MSG: geometry_msgs/Polygon\n\
#A specification of a polygon where the first and last points are assumed to be connected\n\
Point32[] points\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Point32\n\
# This contains the position of a point in free space(with 32 bits of precision).\n\
# It is recommeded to use Point wherever possible instead of Point32.  \n\
# \n\
# This recommendation is to promote interoperability.  \n\
#\n\
# This message is designed to take up less space when sending\n\
# lots of points at once, as in the case of a PointCloud.  \n\
\n\
float32 x\n\
float32 y\n\
float32 z\n\
";
  }

  static const char* value(const ::ist_building_msgs::MapSegmentationResult_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ist_building_msgs::MapSegmentationResult_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.segmented_map);
      stream.next(m.map_resolution);
      stream.next(m.map_origin);
      stream.next(m.room_information_in_pixel);
      stream.next(m.room_information_in_meter);
      stream.next(m.doorway_points);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct MapSegmentationResult_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ist_building_msgs::MapSegmentationResult_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ist_building_msgs::MapSegmentationResult_<ContainerAllocator>& v)
  {
    s << indent << "segmented_map: ";
    s << std::endl;
    Printer< ::sensor_msgs::Image_<ContainerAllocator> >::stream(s, indent + "  ", v.segmented_map);
    s << indent << "map_resolution: ";
    Printer<float>::stream(s, indent + "  ", v.map_resolution);
    s << indent << "map_origin: ";
    s << std::endl;
    Printer< ::geometry_msgs::Pose_<ContainerAllocator> >::stream(s, indent + "  ", v.map_origin);
    s << indent << "room_information_in_pixel[]" << std::endl;
    for (size_t i = 0; i < v.room_information_in_pixel.size(); ++i)
    {
      s << indent << "  room_information_in_pixel[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::ist_building_msgs::RoomInformation_<ContainerAllocator> >::stream(s, indent + "    ", v.room_information_in_pixel[i]);
    }
    s << indent << "room_information_in_meter[]" << std::endl;
    for (size_t i = 0; i < v.room_information_in_meter.size(); ++i)
    {
      s << indent << "  room_information_in_meter[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::ist_building_msgs::RoomInformation_<ContainerAllocator> >::stream(s, indent + "    ", v.room_information_in_meter[i]);
    }
    s << indent << "doorway_points[]" << std::endl;
    for (size_t i = 0; i < v.doorway_points.size(); ++i)
    {
      s << indent << "  doorway_points[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::geometry_msgs::Point32_<ContainerAllocator> >::stream(s, indent + "    ", v.doorway_points[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // IST_BUILDING_MSGS_MESSAGE_MAPSEGMENTATIONRESULT_H
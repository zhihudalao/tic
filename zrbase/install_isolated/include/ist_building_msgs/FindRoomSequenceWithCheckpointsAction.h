// Generated by gencpp from file ist_building_msgs/FindRoomSequenceWithCheckpointsAction.msg
// DO NOT EDIT!


#ifndef IST_BUILDING_MSGS_MESSAGE_FINDROOMSEQUENCEWITHCHECKPOINTSACTION_H
#define IST_BUILDING_MSGS_MESSAGE_FINDROOMSEQUENCEWITHCHECKPOINTSACTION_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <ist_building_msgs/FindRoomSequenceWithCheckpointsActionGoal.h>
#include <ist_building_msgs/FindRoomSequenceWithCheckpointsActionResult.h>
#include <ist_building_msgs/FindRoomSequenceWithCheckpointsActionFeedback.h>

namespace ist_building_msgs
{
template <class ContainerAllocator>
struct FindRoomSequenceWithCheckpointsAction_
{
  typedef FindRoomSequenceWithCheckpointsAction_<ContainerAllocator> Type;

  FindRoomSequenceWithCheckpointsAction_()
    : action_goal()
    , action_result()
    , action_feedback()  {
    }
  FindRoomSequenceWithCheckpointsAction_(const ContainerAllocator& _alloc)
    : action_goal(_alloc)
    , action_result(_alloc)
    , action_feedback(_alloc)  {
  (void)_alloc;
    }



   typedef  ::ist_building_msgs::FindRoomSequenceWithCheckpointsActionGoal_<ContainerAllocator>  _action_goal_type;
  _action_goal_type action_goal;

   typedef  ::ist_building_msgs::FindRoomSequenceWithCheckpointsActionResult_<ContainerAllocator>  _action_result_type;
  _action_result_type action_result;

   typedef  ::ist_building_msgs::FindRoomSequenceWithCheckpointsActionFeedback_<ContainerAllocator>  _action_feedback_type;
  _action_feedback_type action_feedback;





  typedef boost::shared_ptr< ::ist_building_msgs::FindRoomSequenceWithCheckpointsAction_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ist_building_msgs::FindRoomSequenceWithCheckpointsAction_<ContainerAllocator> const> ConstPtr;

}; // struct FindRoomSequenceWithCheckpointsAction_

typedef ::ist_building_msgs::FindRoomSequenceWithCheckpointsAction_<std::allocator<void> > FindRoomSequenceWithCheckpointsAction;

typedef boost::shared_ptr< ::ist_building_msgs::FindRoomSequenceWithCheckpointsAction > FindRoomSequenceWithCheckpointsActionPtr;
typedef boost::shared_ptr< ::ist_building_msgs::FindRoomSequenceWithCheckpointsAction const> FindRoomSequenceWithCheckpointsActionConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ist_building_msgs::FindRoomSequenceWithCheckpointsAction_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ist_building_msgs::FindRoomSequenceWithCheckpointsAction_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::ist_building_msgs::FindRoomSequenceWithCheckpointsAction_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ist_building_msgs::FindRoomSequenceWithCheckpointsAction_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ist_building_msgs::FindRoomSequenceWithCheckpointsAction_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ist_building_msgs::FindRoomSequenceWithCheckpointsAction_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ist_building_msgs::FindRoomSequenceWithCheckpointsAction_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ist_building_msgs::FindRoomSequenceWithCheckpointsAction_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ist_building_msgs::FindRoomSequenceWithCheckpointsAction_<ContainerAllocator> >
{
  static const char* value()
  {
    return "4dcf6f6f1921980b3ecdc06148d06be9";
  }

  static const char* value(const ::ist_building_msgs::FindRoomSequenceWithCheckpointsAction_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x4dcf6f6f1921980bULL;
  static const uint64_t static_value2 = 0x3ecdc06148d06be9ULL;
};

template<class ContainerAllocator>
struct DataType< ::ist_building_msgs::FindRoomSequenceWithCheckpointsAction_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ist_building_msgs/FindRoomSequenceWithCheckpointsAction";
  }

  static const char* value(const ::ist_building_msgs::FindRoomSequenceWithCheckpointsAction_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ist_building_msgs::FindRoomSequenceWithCheckpointsAction_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
\n\
FindRoomSequenceWithCheckpointsActionGoal action_goal\n\
FindRoomSequenceWithCheckpointsActionResult action_result\n\
FindRoomSequenceWithCheckpointsActionFeedback action_feedback\n\
\n\
================================================================================\n\
MSG: ist_building_msgs/FindRoomSequenceWithCheckpointsActionGoal\n\
# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
\n\
Header header\n\
actionlib_msgs/GoalID goal_id\n\
FindRoomSequenceWithCheckpointsGoal goal\n\
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
MSG: actionlib_msgs/GoalID\n\
# The stamp should store the time at which this goal was requested.\n\
# It is used by an action server when it tries to preempt all\n\
# goals that were requested before a certain time\n\
time stamp\n\
\n\
# The id provides a way to associate feedback and\n\
# result message with specific goal requests. The id\n\
# specified must be unique.\n\
string id\n\
\n\
\n\
================================================================================\n\
MSG: ist_building_msgs/FindRoomSequenceWithCheckpointsGoal\n\
# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
# goal definition\n\
sensor_msgs/Image input_map 				# floor plan map [mono8 format], 0=obstacle or unknown, 255=free space \n\
float32 map_resolution						# the resolution of the map in [meter/cell]\n\
geometry_msgs/Pose map_origin				# the origin of the map in [meter]\n\
ist_building_msgs/RoomInformation[] room_information_in_pixel		# room data (min/max coordinates, center coordinates) measured in pixels\n\
float64 robot_radius						# the robot footprint radius [m], used for excluding areas from path planning that could not be visited by the robot\n\
geometry_msgs/Pose robot_start_coordinate	# current robot location (used to determine the closest checkpoint in the sequence of checkpoints) [in meter]\n\
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
================================================================================\n\
MSG: ist_building_msgs/FindRoomSequenceWithCheckpointsActionResult\n\
# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
\n\
Header header\n\
actionlib_msgs/GoalStatus status\n\
FindRoomSequenceWithCheckpointsResult result\n\
\n\
================================================================================\n\
MSG: actionlib_msgs/GoalStatus\n\
GoalID goal_id\n\
uint8 status\n\
uint8 PENDING         = 0   # The goal has yet to be processed by the action server\n\
uint8 ACTIVE          = 1   # The goal is currently being processed by the action server\n\
uint8 PREEMPTED       = 2   # The goal received a cancel request after it started executing\n\
                            #   and has since completed its execution (Terminal State)\n\
uint8 SUCCEEDED       = 3   # The goal was achieved successfully by the action server (Terminal State)\n\
uint8 ABORTED         = 4   # The goal was aborted during execution by the action server due\n\
                            #    to some failure (Terminal State)\n\
uint8 REJECTED        = 5   # The goal was rejected by the action server without being processed,\n\
                            #    because the goal was unattainable or invalid (Terminal State)\n\
uint8 PREEMPTING      = 6   # The goal received a cancel request after it started executing\n\
                            #    and has not yet completed execution\n\
uint8 RECALLING       = 7   # The goal received a cancel request before it started executing,\n\
                            #    but the action server has not yet confirmed that the goal is canceled\n\
uint8 RECALLED        = 8   # The goal received a cancel request before it started executing\n\
                            #    and was successfully cancelled (Terminal State)\n\
uint8 LOST            = 9   # An action client can determine that a goal is LOST. This should not be\n\
                            #    sent over the wire by an action server\n\
\n\
#Allow for the user to associate a string with GoalStatus for debugging\n\
string text\n\
\n\
\n\
================================================================================\n\
MSG: ist_building_msgs/FindRoomSequenceWithCheckpointsResult\n\
# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
\n\
# result definition\n\
ist_building_msgs/RoomSequence[] checkpoints			# sequence of checkpoints, should be ordered in optimized traveling salesman sequence\n\
														# (checkpoint = a clique of rooms close [in terms of robot driving distance] to each other,\n\
														#               and a central [in terms of rooms in the group] checkpoint location)\n\
sensor_msgs/Image sequence_map							# map that has the calculated sequence drawn in\n\
\n\
================================================================================\n\
MSG: ist_building_msgs/RoomSequence\n\
uint32[] room_indices		# indices of those rooms that belong to one group (connected to a checkpoint,\n\
							# i.e. the clique of rooms close [in terms of robot driving distance] to each other),\n\
							# indices should be ordered in optimized traveling salesman sequence\n\
geometry_msgs/Point32 checkpoint_position_in_pixel			# provides the (x,y)-coordinates of the checkpoint location for this group of rooms [in pixel]\n\
geometry_msgs/Point32 checkpoint_position_in_meter			# provides the (x,y)-coordinates of the checkpoint location for this group of rooms [in meter]\n\
================================================================================\n\
MSG: ist_building_msgs/FindRoomSequenceWithCheckpointsActionFeedback\n\
# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
\n\
Header header\n\
actionlib_msgs/GoalStatus status\n\
FindRoomSequenceWithCheckpointsFeedback feedback\n\
\n\
================================================================================\n\
MSG: ist_building_msgs/FindRoomSequenceWithCheckpointsFeedback\n\
# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
#feedback definition\n\
\n\
";
  }

  static const char* value(const ::ist_building_msgs::FindRoomSequenceWithCheckpointsAction_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ist_building_msgs::FindRoomSequenceWithCheckpointsAction_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.action_goal);
      stream.next(m.action_result);
      stream.next(m.action_feedback);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct FindRoomSequenceWithCheckpointsAction_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ist_building_msgs::FindRoomSequenceWithCheckpointsAction_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ist_building_msgs::FindRoomSequenceWithCheckpointsAction_<ContainerAllocator>& v)
  {
    s << indent << "action_goal: ";
    s << std::endl;
    Printer< ::ist_building_msgs::FindRoomSequenceWithCheckpointsActionGoal_<ContainerAllocator> >::stream(s, indent + "  ", v.action_goal);
    s << indent << "action_result: ";
    s << std::endl;
    Printer< ::ist_building_msgs::FindRoomSequenceWithCheckpointsActionResult_<ContainerAllocator> >::stream(s, indent + "  ", v.action_result);
    s << indent << "action_feedback: ";
    s << std::endl;
    Printer< ::ist_building_msgs::FindRoomSequenceWithCheckpointsActionFeedback_<ContainerAllocator> >::stream(s, indent + "  ", v.action_feedback);
  }
};

} // namespace message_operations
} // namespace ros

#endif // IST_BUILDING_MSGS_MESSAGE_FINDROOMSEQUENCEWITHCHECKPOINTSACTION_H
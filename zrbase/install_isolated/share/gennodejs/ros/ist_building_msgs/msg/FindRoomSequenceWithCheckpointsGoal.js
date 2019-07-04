// Auto-generated. Do not edit!

// (in-package ist_building_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let RoomInformation = require('./RoomInformation.js');
let geometry_msgs = _finder('geometry_msgs');
let sensor_msgs = _finder('sensor_msgs');

//-----------------------------------------------------------

class FindRoomSequenceWithCheckpointsGoal {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.input_map = null;
      this.map_resolution = null;
      this.map_origin = null;
      this.room_information_in_pixel = null;
      this.robot_radius = null;
      this.robot_start_coordinate = null;
    }
    else {
      if (initObj.hasOwnProperty('input_map')) {
        this.input_map = initObj.input_map
      }
      else {
        this.input_map = new sensor_msgs.msg.Image();
      }
      if (initObj.hasOwnProperty('map_resolution')) {
        this.map_resolution = initObj.map_resolution
      }
      else {
        this.map_resolution = 0.0;
      }
      if (initObj.hasOwnProperty('map_origin')) {
        this.map_origin = initObj.map_origin
      }
      else {
        this.map_origin = new geometry_msgs.msg.Pose();
      }
      if (initObj.hasOwnProperty('room_information_in_pixel')) {
        this.room_information_in_pixel = initObj.room_information_in_pixel
      }
      else {
        this.room_information_in_pixel = [];
      }
      if (initObj.hasOwnProperty('robot_radius')) {
        this.robot_radius = initObj.robot_radius
      }
      else {
        this.robot_radius = 0.0;
      }
      if (initObj.hasOwnProperty('robot_start_coordinate')) {
        this.robot_start_coordinate = initObj.robot_start_coordinate
      }
      else {
        this.robot_start_coordinate = new geometry_msgs.msg.Pose();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type FindRoomSequenceWithCheckpointsGoal
    // Serialize message field [input_map]
    bufferOffset = sensor_msgs.msg.Image.serialize(obj.input_map, buffer, bufferOffset);
    // Serialize message field [map_resolution]
    bufferOffset = _serializer.float32(obj.map_resolution, buffer, bufferOffset);
    // Serialize message field [map_origin]
    bufferOffset = geometry_msgs.msg.Pose.serialize(obj.map_origin, buffer, bufferOffset);
    // Serialize message field [room_information_in_pixel]
    // Serialize the length for message field [room_information_in_pixel]
    bufferOffset = _serializer.uint32(obj.room_information_in_pixel.length, buffer, bufferOffset);
    obj.room_information_in_pixel.forEach((val) => {
      bufferOffset = RoomInformation.serialize(val, buffer, bufferOffset);
    });
    // Serialize message field [robot_radius]
    bufferOffset = _serializer.float64(obj.robot_radius, buffer, bufferOffset);
    // Serialize message field [robot_start_coordinate]
    bufferOffset = geometry_msgs.msg.Pose.serialize(obj.robot_start_coordinate, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type FindRoomSequenceWithCheckpointsGoal
    let len;
    let data = new FindRoomSequenceWithCheckpointsGoal(null);
    // Deserialize message field [input_map]
    data.input_map = sensor_msgs.msg.Image.deserialize(buffer, bufferOffset);
    // Deserialize message field [map_resolution]
    data.map_resolution = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [map_origin]
    data.map_origin = geometry_msgs.msg.Pose.deserialize(buffer, bufferOffset);
    // Deserialize message field [room_information_in_pixel]
    // Deserialize array length for message field [room_information_in_pixel]
    len = _deserializer.uint32(buffer, bufferOffset);
    data.room_information_in_pixel = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.room_information_in_pixel[i] = RoomInformation.deserialize(buffer, bufferOffset)
    }
    // Deserialize message field [robot_radius]
    data.robot_radius = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [robot_start_coordinate]
    data.robot_start_coordinate = geometry_msgs.msg.Pose.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += sensor_msgs.msg.Image.getMessageSize(object.input_map);
    object.room_information_in_pixel.forEach((val) => {
      length += RoomInformation.getMessageSize(val);
    });
    return length + 128;
  }

  static datatype() {
    // Returns string type for a message object
    return 'ist_building_msgs/FindRoomSequenceWithCheckpointsGoal';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '285d49405549631f016ce37520e05929';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======
    # goal definition
    sensor_msgs/Image input_map 				# floor plan map [mono8 format], 0=obstacle or unknown, 255=free space 
    float32 map_resolution						# the resolution of the map in [meter/cell]
    geometry_msgs/Pose map_origin				# the origin of the map in [meter]
    ist_building_msgs/RoomInformation[] room_information_in_pixel		# room data (min/max coordinates, center coordinates) measured in pixels
    float64 robot_radius						# the robot footprint radius [m], used for excluding areas from path planning that could not be visited by the robot
    geometry_msgs/Pose robot_start_coordinate	# current robot location (used to determine the closest checkpoint in the sequence of checkpoints) [in meter]
    
    
    ================================================================================
    MSG: sensor_msgs/Image
    # This message contains an uncompressed image
    # (0, 0) is at top-left corner of image
    #
    
    Header header        # Header timestamp should be acquisition time of image
                         # Header frame_id should be optical frame of camera
                         # origin of frame should be optical center of camera
                         # +x should point to the right in the image
                         # +y should point down in the image
                         # +z should point into to plane of the image
                         # If the frame_id here and the frame_id of the CameraInfo
                         # message associated with the image conflict
                         # the behavior is undefined
    
    uint32 height         # image height, that is, number of rows
    uint32 width          # image width, that is, number of columns
    
    # The legal values for encoding are in file src/image_encodings.cpp
    # If you want to standardize a new string format, join
    # ros-users@lists.sourceforge.net and send an email proposing a new encoding.
    
    string encoding       # Encoding of pixels -- channel meaning, ordering, size
                          # taken from the list of strings in include/sensor_msgs/image_encodings.h
    
    uint8 is_bigendian    # is this data bigendian?
    uint32 step           # Full row length in bytes
    uint8[] data          # actual matrix data, size is (step * rows)
    
    ================================================================================
    MSG: std_msgs/Header
    # Standard metadata for higher-level stamped data types.
    # This is generally used to communicate timestamped data 
    # in a particular coordinate frame.
    # 
    # sequence ID: consecutively increasing ID 
    uint32 seq
    #Two-integer timestamp that is expressed as:
    # * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
    # * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
    # time-handling sugar is provided by the client library
    time stamp
    #Frame this data is associated with
    # 0: no frame
    # 1: global frame
    string frame_id
    
    ================================================================================
    MSG: geometry_msgs/Pose
    # A representation of pose in free space, composed of position and orientation. 
    Point position
    Quaternion orientation
    
    ================================================================================
    MSG: geometry_msgs/Point
    # This contains the position of a point in free space
    float64 x
    float64 y
    float64 z
    
    ================================================================================
    MSG: geometry_msgs/Quaternion
    # This represents an orientation in free space in quaternion form.
    
    float64 x
    float64 y
    float64 z
    float64 w
    
    ================================================================================
    MSG: ist_building_msgs/RoomInformation
    geometry_msgs/Polygon room_min_max		# first point provides the minimum (x,y)-coordinate values of the rooms, second point provides the maximum (x,y)-coordinate values of the rooms
    geometry_msgs/Point32 room_center		# provides the (x,y)-coordinate values of the room centers
    ================================================================================
    MSG: geometry_msgs/Polygon
    #A specification of a polygon where the first and last points are assumed to be connected
    Point32[] points
    
    ================================================================================
    MSG: geometry_msgs/Point32
    # This contains the position of a point in free space(with 32 bits of precision).
    # It is recommeded to use Point wherever possible instead of Point32.  
    # 
    # This recommendation is to promote interoperability.  
    #
    # This message is designed to take up less space when sending
    # lots of points at once, as in the case of a PointCloud.  
    
    float32 x
    float32 y
    float32 z
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new FindRoomSequenceWithCheckpointsGoal(null);
    if (msg.input_map !== undefined) {
      resolved.input_map = sensor_msgs.msg.Image.Resolve(msg.input_map)
    }
    else {
      resolved.input_map = new sensor_msgs.msg.Image()
    }

    if (msg.map_resolution !== undefined) {
      resolved.map_resolution = msg.map_resolution;
    }
    else {
      resolved.map_resolution = 0.0
    }

    if (msg.map_origin !== undefined) {
      resolved.map_origin = geometry_msgs.msg.Pose.Resolve(msg.map_origin)
    }
    else {
      resolved.map_origin = new geometry_msgs.msg.Pose()
    }

    if (msg.room_information_in_pixel !== undefined) {
      resolved.room_information_in_pixel = new Array(msg.room_information_in_pixel.length);
      for (let i = 0; i < resolved.room_information_in_pixel.length; ++i) {
        resolved.room_information_in_pixel[i] = RoomInformation.Resolve(msg.room_information_in_pixel[i]);
      }
    }
    else {
      resolved.room_information_in_pixel = []
    }

    if (msg.robot_radius !== undefined) {
      resolved.robot_radius = msg.robot_radius;
    }
    else {
      resolved.robot_radius = 0.0
    }

    if (msg.robot_start_coordinate !== undefined) {
      resolved.robot_start_coordinate = geometry_msgs.msg.Pose.Resolve(msg.robot_start_coordinate)
    }
    else {
      resolved.robot_start_coordinate = new geometry_msgs.msg.Pose()
    }

    return resolved;
    }
};

module.exports = FindRoomSequenceWithCheckpointsGoal;

// Auto-generated. Do not edit!

// (in-package ist_building_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let geometry_msgs = _finder('geometry_msgs');

//-----------------------------------------------------------

class RoomExplorationResult {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.coverage_path = null;
      this.coverage_path_pose_stamped = null;
    }
    else {
      if (initObj.hasOwnProperty('coverage_path')) {
        this.coverage_path = initObj.coverage_path
      }
      else {
        this.coverage_path = [];
      }
      if (initObj.hasOwnProperty('coverage_path_pose_stamped')) {
        this.coverage_path_pose_stamped = initObj.coverage_path_pose_stamped
      }
      else {
        this.coverage_path_pose_stamped = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type RoomExplorationResult
    // Serialize message field [coverage_path]
    // Serialize the length for message field [coverage_path]
    bufferOffset = _serializer.uint32(obj.coverage_path.length, buffer, bufferOffset);
    obj.coverage_path.forEach((val) => {
      bufferOffset = geometry_msgs.msg.Pose2D.serialize(val, buffer, bufferOffset);
    });
    // Serialize message field [coverage_path_pose_stamped]
    // Serialize the length for message field [coverage_path_pose_stamped]
    bufferOffset = _serializer.uint32(obj.coverage_path_pose_stamped.length, buffer, bufferOffset);
    obj.coverage_path_pose_stamped.forEach((val) => {
      bufferOffset = geometry_msgs.msg.PoseStamped.serialize(val, buffer, bufferOffset);
    });
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type RoomExplorationResult
    let len;
    let data = new RoomExplorationResult(null);
    // Deserialize message field [coverage_path]
    // Deserialize array length for message field [coverage_path]
    len = _deserializer.uint32(buffer, bufferOffset);
    data.coverage_path = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.coverage_path[i] = geometry_msgs.msg.Pose2D.deserialize(buffer, bufferOffset)
    }
    // Deserialize message field [coverage_path_pose_stamped]
    // Deserialize array length for message field [coverage_path_pose_stamped]
    len = _deserializer.uint32(buffer, bufferOffset);
    data.coverage_path_pose_stamped = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.coverage_path_pose_stamped[i] = geometry_msgs.msg.PoseStamped.deserialize(buffer, bufferOffset)
    }
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += 24 * object.coverage_path.length;
    object.coverage_path_pose_stamped.forEach((val) => {
      length += geometry_msgs.msg.PoseStamped.getMessageSize(val);
    });
    return length + 8;
  }

  static datatype() {
    // Returns string type for a message object
    return 'ist_building_msgs/RoomExplorationResult';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '12d0bcf4cde501321f572592c0c514da';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======
    # result definition
    geometry_msgs/Pose2D[] coverage_path			# when the server should return the coverage path, this is done returning the points in an array that shows the order of visiting
    geometry_msgs/PoseStamped[] coverage_path_pose_stamped			# (same content as coverage_path but different format) when the server should return the coverage path, this is done returning the points in an array that shows the order of visiting
    
    ================================================================================
    MSG: geometry_msgs/Pose2D
    # Deprecated
    # Please use the full 3D pose.
    
    # In general our recommendation is to use a full 3D representation of everything and for 2D specific applications make the appropriate projections into the plane for their calculations but optimally will preserve the 3D information during processing.
    
    # If we have parallel copies of 2D datatypes every UI and other pipeline will end up needing to have dual interfaces to plot everything. And you will end up with not being able to use 3D tools for 2D use cases even if they're completely valid, as you'd have to reimplement it with different inputs and outputs. It's not particularly hard to plot the 2D pose or compute the yaw error for the Pose message and there are already tools and libraries that can do this for you.
    
    
    # This expresses a position and orientation on a 2D manifold.
    
    float64 x
    float64 y
    float64 theta
    
    ================================================================================
    MSG: geometry_msgs/PoseStamped
    # A Pose with reference coordinate frame and timestamp
    Header header
    Pose pose
    
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
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new RoomExplorationResult(null);
    if (msg.coverage_path !== undefined) {
      resolved.coverage_path = new Array(msg.coverage_path.length);
      for (let i = 0; i < resolved.coverage_path.length; ++i) {
        resolved.coverage_path[i] = geometry_msgs.msg.Pose2D.Resolve(msg.coverage_path[i]);
      }
    }
    else {
      resolved.coverage_path = []
    }

    if (msg.coverage_path_pose_stamped !== undefined) {
      resolved.coverage_path_pose_stamped = new Array(msg.coverage_path_pose_stamped.length);
      for (let i = 0; i < resolved.coverage_path_pose_stamped.length; ++i) {
        resolved.coverage_path_pose_stamped[i] = geometry_msgs.msg.PoseStamped.Resolve(msg.coverage_path_pose_stamped[i]);
      }
    }
    else {
      resolved.coverage_path_pose_stamped = []
    }

    return resolved;
    }
};

module.exports = RoomExplorationResult;
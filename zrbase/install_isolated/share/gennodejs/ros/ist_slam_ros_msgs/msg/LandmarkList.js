// Auto-generated. Do not edit!

// (in-package ist_slam_ros_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let LandmarkEntry = require('./LandmarkEntry.js');
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class LandmarkList {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.landmarks = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('landmarks')) {
        this.landmarks = initObj.landmarks
      }
      else {
        this.landmarks = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type LandmarkList
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [landmarks]
    // Serialize the length for message field [landmarks]
    bufferOffset = _serializer.uint32(obj.landmarks.length, buffer, bufferOffset);
    obj.landmarks.forEach((val) => {
      bufferOffset = LandmarkEntry.serialize(val, buffer, bufferOffset);
    });
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type LandmarkList
    let len;
    let data = new LandmarkList(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [landmarks]
    // Deserialize array length for message field [landmarks]
    len = _deserializer.uint32(buffer, bufferOffset);
    data.landmarks = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.landmarks[i] = LandmarkEntry.deserialize(buffer, bufferOffset)
    }
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    object.landmarks.forEach((val) => {
      length += LandmarkEntry.getMessageSize(val);
    });
    return length + 4;
  }

  static datatype() {
    // Returns string type for a message object
    return 'ist_slam_ros_msgs/LandmarkList';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '322e3fb6b49d8fcd97544b4896b0ae66';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    
    std_msgs/Header header
    ist_slam_ros_msgs/LandmarkEntry[] landmarks
    
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
    MSG: ist_slam_ros_msgs/LandmarkEntry
    
    string id
    geometry_msgs/Pose tracking_from_landmark_transform
    float64 translation_weight
    float64 rotation_weight
    
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
    const resolved = new LandmarkList(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.landmarks !== undefined) {
      resolved.landmarks = new Array(msg.landmarks.length);
      for (let i = 0; i < resolved.landmarks.length; ++i) {
        resolved.landmarks[i] = LandmarkEntry.Resolve(msg.landmarks[i]);
      }
    }
    else {
      resolved.landmarks = []
    }

    return resolved;
    }
};

module.exports = LandmarkList;

// Auto-generated. Do not edit!

// (in-package marker.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let markerPose = require('./markerPose.js');

//-----------------------------------------------------------

class markerPoseArray {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.markers = null;
    }
    else {
      if (initObj.hasOwnProperty('markers')) {
        this.markers = initObj.markers
      }
      else {
        this.markers = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type markerPoseArray
    // Serialize message field [markers]
    // Serialize the length for message field [markers]
    bufferOffset = _serializer.uint32(obj.markers.length, buffer, bufferOffset);
    obj.markers.forEach((val) => {
      bufferOffset = markerPose.serialize(val, buffer, bufferOffset);
    });
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type markerPoseArray
    let len;
    let data = new markerPoseArray(null);
    // Deserialize message field [markers]
    // Deserialize array length for message field [markers]
    len = _deserializer.uint32(buffer, bufferOffset);
    data.markers = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.markers[i] = markerPose.deserialize(buffer, bufferOffset)
    }
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    object.markers.forEach((val) => {
      length += markerPose.getMessageSize(val);
    });
    return length + 4;
  }

  static datatype() {
    // Returns string type for a message object
    return 'marker/markerPoseArray';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'c5f6d3ea5a86708d66e8b0f23988b7f6';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    marker/markerPose[] markers
    ================================================================================
    MSG: marker/markerPose
    string name
    geometry_msgs/Pose pose
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
    const resolved = new markerPoseArray(null);
    if (msg.markers !== undefined) {
      resolved.markers = new Array(msg.markers.length);
      for (let i = 0; i < resolved.markers.length; ++i) {
        resolved.markers[i] = markerPose.Resolve(msg.markers[i]);
      }
    }
    else {
      resolved.markers = []
    }

    return resolved;
    }
};

module.exports = markerPoseArray;

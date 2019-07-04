// Auto-generated. Do not edit!

// (in-package ist_slam_ros_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class HistogramBucket {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.bucket_boundary = null;
      this.count = null;
    }
    else {
      if (initObj.hasOwnProperty('bucket_boundary')) {
        this.bucket_boundary = initObj.bucket_boundary
      }
      else {
        this.bucket_boundary = 0.0;
      }
      if (initObj.hasOwnProperty('count')) {
        this.count = initObj.count
      }
      else {
        this.count = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type HistogramBucket
    // Serialize message field [bucket_boundary]
    bufferOffset = _serializer.float64(obj.bucket_boundary, buffer, bufferOffset);
    // Serialize message field [count]
    bufferOffset = _serializer.float64(obj.count, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type HistogramBucket
    let len;
    let data = new HistogramBucket(null);
    // Deserialize message field [bucket_boundary]
    data.bucket_boundary = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [count]
    data.count = _deserializer.float64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 16;
  }

  static datatype() {
    // Returns string type for a message object
    return 'ist_slam_ros_msgs/HistogramBucket';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'b579df35b32758cf09f65ae223aea0ad';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    
    # A histogram bucket counts values x for which:
    #   previous_boundary < x <= bucket_boundary
    # holds.
    float64 bucket_boundary
    float64 count
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new HistogramBucket(null);
    if (msg.bucket_boundary !== undefined) {
      resolved.bucket_boundary = msg.bucket_boundary;
    }
    else {
      resolved.bucket_boundary = 0.0
    }

    if (msg.count !== undefined) {
      resolved.count = msg.count;
    }
    else {
      resolved.count = 0.0
    }

    return resolved;
    }
};

module.exports = HistogramBucket;

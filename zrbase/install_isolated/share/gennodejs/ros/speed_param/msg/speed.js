// Auto-generated. Do not edit!

// (in-package speed_param.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class speed {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.line = null;
      this.angular = null;
    }
    else {
      if (initObj.hasOwnProperty('line')) {
        this.line = initObj.line
      }
      else {
        this.line = 0.0;
      }
      if (initObj.hasOwnProperty('angular')) {
        this.angular = initObj.angular
      }
      else {
        this.angular = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type speed
    // Serialize message field [line]
    bufferOffset = _serializer.float32(obj.line, buffer, bufferOffset);
    // Serialize message field [angular]
    bufferOffset = _serializer.float32(obj.angular, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type speed
    let len;
    let data = new speed(null);
    // Deserialize message field [line]
    data.line = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [angular]
    data.angular = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 8;
  }

  static datatype() {
    // Returns string type for a message object
    return 'speed_param/speed';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '06684d5be7e1ff5a383443515a74e02c';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float32 line
    float32 angular
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new speed(null);
    if (msg.line !== undefined) {
      resolved.line = msg.line;
    }
    else {
      resolved.line = 0.0
    }

    if (msg.angular !== undefined) {
      resolved.angular = msg.angular;
    }
    else {
      resolved.angular = 0.0
    }

    return resolved;
    }
};

module.exports = speed;

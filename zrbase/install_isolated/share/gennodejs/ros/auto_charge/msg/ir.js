// Auto-generated. Do not edit!

// (in-package auto_charge.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class ir {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.ir_data = null;
      this.ir_charging = null;
    }
    else {
      if (initObj.hasOwnProperty('ir_data')) {
        this.ir_data = initObj.ir_data
      }
      else {
        this.ir_data = '';
      }
      if (initObj.hasOwnProperty('ir_charging')) {
        this.ir_charging = initObj.ir_charging
      }
      else {
        this.ir_charging = false;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ir
    // Serialize message field [ir_data]
    bufferOffset = _serializer.string(obj.ir_data, buffer, bufferOffset);
    // Serialize message field [ir_charging]
    bufferOffset = _serializer.bool(obj.ir_charging, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ir
    let len;
    let data = new ir(null);
    // Deserialize message field [ir_data]
    data.ir_data = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [ir_charging]
    data.ir_charging = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += object.ir_data.length;
    return length + 5;
  }

  static datatype() {
    // Returns string type for a message object
    return 'auto_charge/ir';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '9e4e7b7ff71e150dd913663f82725e90';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    string ir_data
    bool ir_charging
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ir(null);
    if (msg.ir_data !== undefined) {
      resolved.ir_data = msg.ir_data;
    }
    else {
      resolved.ir_data = ''
    }

    if (msg.ir_charging !== undefined) {
      resolved.ir_charging = msg.ir_charging;
    }
    else {
      resolved.ir_charging = false
    }

    return resolved;
    }
};

module.exports = ir;

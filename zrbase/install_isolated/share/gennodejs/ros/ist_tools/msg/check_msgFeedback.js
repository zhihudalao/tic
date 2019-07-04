// Auto-generated. Do not edit!

// (in-package ist_tools.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class check_msgFeedback {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.accomplished = null;
    }
    else {
      if (initObj.hasOwnProperty('accomplished')) {
        this.accomplished = initObj.accomplished
      }
      else {
        this.accomplished = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type check_msgFeedback
    // Serialize message field [accomplished]
    bufferOffset = _serializer.float32(obj.accomplished, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type check_msgFeedback
    let len;
    let data = new check_msgFeedback(null);
    // Deserialize message field [accomplished]
    data.accomplished = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 4;
  }

  static datatype() {
    // Returns string type for a message object
    return 'ist_tools/check_msgFeedback';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '00dcf0d5008205d95b1f8016ae205cce';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======
    #feedback
    float32 accomplished
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new check_msgFeedback(null);
    if (msg.accomplished !== undefined) {
      resolved.accomplished = msg.accomplished;
    }
    else {
      resolved.accomplished = 0.0
    }

    return resolved;
    }
};

module.exports = check_msgFeedback;

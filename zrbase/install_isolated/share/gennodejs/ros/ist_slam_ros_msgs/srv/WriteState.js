// Auto-generated. Do not edit!

// (in-package ist_slam_ros_msgs.srv)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

let StatusResponse = require('../msg/StatusResponse.js');

//-----------------------------------------------------------

class WriteStateRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.filename = null;
      this.include_unfinished_submaps = null;
    }
    else {
      if (initObj.hasOwnProperty('filename')) {
        this.filename = initObj.filename
      }
      else {
        this.filename = '';
      }
      if (initObj.hasOwnProperty('include_unfinished_submaps')) {
        this.include_unfinished_submaps = initObj.include_unfinished_submaps
      }
      else {
        this.include_unfinished_submaps = false;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type WriteStateRequest
    // Serialize message field [filename]
    bufferOffset = _serializer.string(obj.filename, buffer, bufferOffset);
    // Serialize message field [include_unfinished_submaps]
    bufferOffset = _serializer.bool(obj.include_unfinished_submaps, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type WriteStateRequest
    let len;
    let data = new WriteStateRequest(null);
    // Deserialize message field [filename]
    data.filename = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [include_unfinished_submaps]
    data.include_unfinished_submaps = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += object.filename.length;
    return length + 5;
  }

  static datatype() {
    // Returns string type for a service object
    return 'ist_slam_ros_msgs/WriteStateRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'bfd12117d83df4fe52e78631c0c6b702';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    
    string filename
    bool include_unfinished_submaps
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new WriteStateRequest(null);
    if (msg.filename !== undefined) {
      resolved.filename = msg.filename;
    }
    else {
      resolved.filename = ''
    }

    if (msg.include_unfinished_submaps !== undefined) {
      resolved.include_unfinished_submaps = msg.include_unfinished_submaps;
    }
    else {
      resolved.include_unfinished_submaps = false
    }

    return resolved;
    }
};

class WriteStateResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.status = null;
    }
    else {
      if (initObj.hasOwnProperty('status')) {
        this.status = initObj.status
      }
      else {
        this.status = new StatusResponse();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type WriteStateResponse
    // Serialize message field [status]
    bufferOffset = StatusResponse.serialize(obj.status, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type WriteStateResponse
    let len;
    let data = new WriteStateResponse(null);
    // Deserialize message field [status]
    data.status = StatusResponse.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += StatusResponse.getMessageSize(object.status);
    return length;
  }

  static datatype() {
    // Returns string type for a service object
    return 'ist_slam_ros_msgs/WriteStateResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '4e6ca4e44081fa06b258fa12804ea7cb';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    ist_slam_ros_msgs/StatusResponse status
    
    
    ================================================================================
    MSG: ist_slam_ros_msgs/StatusResponse
    
    # A common message type to indicate the outcome of a service call.
    uint8 code
    string message
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new WriteStateResponse(null);
    if (msg.status !== undefined) {
      resolved.status = StatusResponse.Resolve(msg.status)
    }
    else {
      resolved.status = new StatusResponse()
    }

    return resolved;
    }
};

module.exports = {
  Request: WriteStateRequest,
  Response: WriteStateResponse,
  md5sum() { return '96db93844e1eb87ed5b1526b3e48e3bb'; },
  datatype() { return 'ist_slam_ros_msgs/WriteState'; }
};

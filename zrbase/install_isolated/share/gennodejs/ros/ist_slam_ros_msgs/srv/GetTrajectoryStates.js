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
let TrajectoryStates = require('../msg/TrajectoryStates.js');

//-----------------------------------------------------------

class GetTrajectoryStatesRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
    }
    else {
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type GetTrajectoryStatesRequest
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type GetTrajectoryStatesRequest
    let len;
    let data = new GetTrajectoryStatesRequest(null);
    return data;
  }

  static getMessageSize(object) {
    return 0;
  }

  static datatype() {
    // Returns string type for a service object
    return 'ist_slam_ros_msgs/GetTrajectoryStatesRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'd41d8cd98f00b204e9800998ecf8427e';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new GetTrajectoryStatesRequest(null);
    return resolved;
    }
};

class GetTrajectoryStatesResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.status = null;
      this.trajectory_states = null;
    }
    else {
      if (initObj.hasOwnProperty('status')) {
        this.status = initObj.status
      }
      else {
        this.status = new StatusResponse();
      }
      if (initObj.hasOwnProperty('trajectory_states')) {
        this.trajectory_states = initObj.trajectory_states
      }
      else {
        this.trajectory_states = new TrajectoryStates();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type GetTrajectoryStatesResponse
    // Serialize message field [status]
    bufferOffset = StatusResponse.serialize(obj.status, buffer, bufferOffset);
    // Serialize message field [trajectory_states]
    bufferOffset = TrajectoryStates.serialize(obj.trajectory_states, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type GetTrajectoryStatesResponse
    let len;
    let data = new GetTrajectoryStatesResponse(null);
    // Deserialize message field [status]
    data.status = StatusResponse.deserialize(buffer, bufferOffset);
    // Deserialize message field [trajectory_states]
    data.trajectory_states = TrajectoryStates.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += StatusResponse.getMessageSize(object.status);
    length += TrajectoryStates.getMessageSize(object.trajectory_states);
    return length;
  }

  static datatype() {
    // Returns string type for a service object
    return 'ist_slam_ros_msgs/GetTrajectoryStatesResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'b9e3b373f17df088ee6dcd817b79dff0';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    ist_slam_ros_msgs/StatusResponse status
    ist_slam_ros_msgs/TrajectoryStates trajectory_states
    
    
    ================================================================================
    MSG: ist_slam_ros_msgs/StatusResponse
    
    # A common message type to indicate the outcome of a service call.
    uint8 code
    string message
    
    ================================================================================
    MSG: ist_slam_ros_msgs/TrajectoryStates
    
    uint8 ACTIVE = 0
    uint8 FINISHED = 1
    uint8 FROZEN = 2
    uint8 DELETED = 3
    
    std_msgs/Header header
    int32[] trajectory_id
    uint8[] trajectory_state
    
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
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new GetTrajectoryStatesResponse(null);
    if (msg.status !== undefined) {
      resolved.status = StatusResponse.Resolve(msg.status)
    }
    else {
      resolved.status = new StatusResponse()
    }

    if (msg.trajectory_states !== undefined) {
      resolved.trajectory_states = TrajectoryStates.Resolve(msg.trajectory_states)
    }
    else {
      resolved.trajectory_states = new TrajectoryStates()
    }

    return resolved;
    }
};

module.exports = {
  Request: GetTrajectoryStatesRequest,
  Response: GetTrajectoryStatesResponse,
  md5sum() { return 'b9e3b373f17df088ee6dcd817b79dff0'; },
  datatype() { return 'ist_slam_ros_msgs/GetTrajectoryStates'; }
};

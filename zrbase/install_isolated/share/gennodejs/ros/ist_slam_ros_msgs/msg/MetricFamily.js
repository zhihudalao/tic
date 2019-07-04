// Auto-generated. Do not edit!

// (in-package ist_slam_ros_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let Metric = require('./Metric.js');

//-----------------------------------------------------------

class MetricFamily {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.name = null;
      this.description = null;
      this.metrics = null;
    }
    else {
      if (initObj.hasOwnProperty('name')) {
        this.name = initObj.name
      }
      else {
        this.name = '';
      }
      if (initObj.hasOwnProperty('description')) {
        this.description = initObj.description
      }
      else {
        this.description = '';
      }
      if (initObj.hasOwnProperty('metrics')) {
        this.metrics = initObj.metrics
      }
      else {
        this.metrics = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type MetricFamily
    // Serialize message field [name]
    bufferOffset = _serializer.string(obj.name, buffer, bufferOffset);
    // Serialize message field [description]
    bufferOffset = _serializer.string(obj.description, buffer, bufferOffset);
    // Serialize message field [metrics]
    // Serialize the length for message field [metrics]
    bufferOffset = _serializer.uint32(obj.metrics.length, buffer, bufferOffset);
    obj.metrics.forEach((val) => {
      bufferOffset = Metric.serialize(val, buffer, bufferOffset);
    });
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type MetricFamily
    let len;
    let data = new MetricFamily(null);
    // Deserialize message field [name]
    data.name = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [description]
    data.description = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [metrics]
    // Deserialize array length for message field [metrics]
    len = _deserializer.uint32(buffer, bufferOffset);
    data.metrics = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.metrics[i] = Metric.deserialize(buffer, bufferOffset)
    }
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += object.name.length;
    length += object.description.length;
    object.metrics.forEach((val) => {
      length += Metric.getMessageSize(val);
    });
    return length + 12;
  }

  static datatype() {
    // Returns string type for a message object
    return 'ist_slam_ros_msgs/MetricFamily';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '583a11b161bb4a70f5df274715bcaf10';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    
    string name
    string description
    ist_slam_ros_msgs/Metric[] metrics
    
    ================================================================================
    MSG: ist_slam_ros_msgs/Metric
    
    uint8 TYPE_COUNTER=0
    uint8 TYPE_GAUGE=1
    uint8 TYPE_HISTOGRAM=2
    
    uint8 type
    ist_slam_ros_msgs/MetricLabel[] labels
    
    # TYPE_COUNTER or TYPE_GAUGE
    float64 value
    
    # TYPE_HISTOGRAM
    ist_slam_ros_msgs/HistogramBucket[] counts_by_bucket
    
    ================================================================================
    MSG: ist_slam_ros_msgs/MetricLabel
    
    string key
    string value
    
    ================================================================================
    MSG: ist_slam_ros_msgs/HistogramBucket
    
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
    const resolved = new MetricFamily(null);
    if (msg.name !== undefined) {
      resolved.name = msg.name;
    }
    else {
      resolved.name = ''
    }

    if (msg.description !== undefined) {
      resolved.description = msg.description;
    }
    else {
      resolved.description = ''
    }

    if (msg.metrics !== undefined) {
      resolved.metrics = new Array(msg.metrics.length);
      for (let i = 0; i < resolved.metrics.length; ++i) {
        resolved.metrics[i] = Metric.Resolve(msg.metrics[i]);
      }
    }
    else {
      resolved.metrics = []
    }

    return resolved;
    }
};

module.exports = MetricFamily;

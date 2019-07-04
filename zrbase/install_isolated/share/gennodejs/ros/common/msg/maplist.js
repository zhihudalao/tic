// Auto-generated. Do not edit!

// (in-package common.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class maplist {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.maplist = null;
    }
    else {
      if (initObj.hasOwnProperty('maplist')) {
        this.maplist = initObj.maplist
      }
      else {
        this.maplist = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type maplist
    // Serialize message field [maplist]
    bufferOffset = _arraySerializer.string(obj.maplist, buffer, bufferOffset, null);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type maplist
    let len;
    let data = new maplist(null);
    // Deserialize message field [maplist]
    data.maplist = _arrayDeserializer.string(buffer, bufferOffset, null)
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    object.maplist.forEach((val) => {
      length += 4 + val.length;
    });
    return length + 4;
  }

  static datatype() {
    // Returns string type for a message object
    return 'common/maplist';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '2f17be7ef84382701baab17066775a33';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    string[] maplist
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new maplist(null);
    if (msg.maplist !== undefined) {
      resolved.maplist = msg.maplist;
    }
    else {
      resolved.maplist = []
    }

    return resolved;
    }
};

module.exports = maplist;

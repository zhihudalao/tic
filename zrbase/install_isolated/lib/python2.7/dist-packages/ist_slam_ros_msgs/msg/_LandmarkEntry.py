# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from ist_slam_ros_msgs/LandmarkEntry.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import geometry_msgs.msg

class LandmarkEntry(genpy.Message):
  _md5sum = "133f8dd7259f83a87eb4d78b301c0b70"
  _type = "ist_slam_ros_msgs/LandmarkEntry"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """
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
"""
  __slots__ = ['id','tracking_from_landmark_transform','translation_weight','rotation_weight']
  _slot_types = ['string','geometry_msgs/Pose','float64','float64']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       id,tracking_from_landmark_transform,translation_weight,rotation_weight

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(LandmarkEntry, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.id is None:
        self.id = ''
      if self.tracking_from_landmark_transform is None:
        self.tracking_from_landmark_transform = geometry_msgs.msg.Pose()
      if self.translation_weight is None:
        self.translation_weight = 0.
      if self.rotation_weight is None:
        self.rotation_weight = 0.
    else:
      self.id = ''
      self.tracking_from_landmark_transform = geometry_msgs.msg.Pose()
      self.translation_weight = 0.
      self.rotation_weight = 0.

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self.id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_get_struct_9d().pack(_x.tracking_from_landmark_transform.position.x, _x.tracking_from_landmark_transform.position.y, _x.tracking_from_landmark_transform.position.z, _x.tracking_from_landmark_transform.orientation.x, _x.tracking_from_landmark_transform.orientation.y, _x.tracking_from_landmark_transform.orientation.z, _x.tracking_from_landmark_transform.orientation.w, _x.translation_weight, _x.rotation_weight))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      if self.tracking_from_landmark_transform is None:
        self.tracking_from_landmark_transform = geometry_msgs.msg.Pose()
      end = 0
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.id = str[start:end].decode('utf-8')
      else:
        self.id = str[start:end]
      _x = self
      start = end
      end += 72
      (_x.tracking_from_landmark_transform.position.x, _x.tracking_from_landmark_transform.position.y, _x.tracking_from_landmark_transform.position.z, _x.tracking_from_landmark_transform.orientation.x, _x.tracking_from_landmark_transform.orientation.y, _x.tracking_from_landmark_transform.orientation.z, _x.tracking_from_landmark_transform.orientation.w, _x.translation_weight, _x.rotation_weight,) = _get_struct_9d().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self.id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_get_struct_9d().pack(_x.tracking_from_landmark_transform.position.x, _x.tracking_from_landmark_transform.position.y, _x.tracking_from_landmark_transform.position.z, _x.tracking_from_landmark_transform.orientation.x, _x.tracking_from_landmark_transform.orientation.y, _x.tracking_from_landmark_transform.orientation.z, _x.tracking_from_landmark_transform.orientation.w, _x.translation_weight, _x.rotation_weight))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      if self.tracking_from_landmark_transform is None:
        self.tracking_from_landmark_transform = geometry_msgs.msg.Pose()
      end = 0
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.id = str[start:end].decode('utf-8')
      else:
        self.id = str[start:end]
      _x = self
      start = end
      end += 72
      (_x.tracking_from_landmark_transform.position.x, _x.tracking_from_landmark_transform.position.y, _x.tracking_from_landmark_transform.position.z, _x.tracking_from_landmark_transform.orientation.x, _x.tracking_from_landmark_transform.orientation.y, _x.tracking_from_landmark_transform.orientation.z, _x.tracking_from_landmark_transform.orientation.w, _x.translation_weight, _x.rotation_weight,) = _get_struct_9d().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_9d = None
def _get_struct_9d():
    global _struct_9d
    if _struct_9d is None:
        _struct_9d = struct.Struct("<9d")
    return _struct_9d

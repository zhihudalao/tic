# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from ist_slam_ros_msgs/BagfileProgress.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class BagfileProgress(genpy.Message):
  _md5sum = "2a36f93b13e2b297d45098a38cb00510"
  _type = "ist_slam_ros_msgs/BagfileProgress"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """#
# Licensed under the Apache License, Version 2.0 (the 'License');
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an 'AS IS' BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.


# Contains general information about the bagfiles processing progress

string current_bagfile_name
uint32 current_bagfile_id
uint32 total_bagfiles
uint32 total_messages
uint32 processed_messages
float32 total_seconds
float32 processed_seconds
"""
  __slots__ = ['current_bagfile_name','current_bagfile_id','total_bagfiles','total_messages','processed_messages','total_seconds','processed_seconds']
  _slot_types = ['string','uint32','uint32','uint32','uint32','float32','float32']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       current_bagfile_name,current_bagfile_id,total_bagfiles,total_messages,processed_messages,total_seconds,processed_seconds

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(BagfileProgress, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.current_bagfile_name is None:
        self.current_bagfile_name = ''
      if self.current_bagfile_id is None:
        self.current_bagfile_id = 0
      if self.total_bagfiles is None:
        self.total_bagfiles = 0
      if self.total_messages is None:
        self.total_messages = 0
      if self.processed_messages is None:
        self.processed_messages = 0
      if self.total_seconds is None:
        self.total_seconds = 0.
      if self.processed_seconds is None:
        self.processed_seconds = 0.
    else:
      self.current_bagfile_name = ''
      self.current_bagfile_id = 0
      self.total_bagfiles = 0
      self.total_messages = 0
      self.processed_messages = 0
      self.total_seconds = 0.
      self.processed_seconds = 0.

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
      _x = self.current_bagfile_name
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_get_struct_4I2f().pack(_x.current_bagfile_id, _x.total_bagfiles, _x.total_messages, _x.processed_messages, _x.total_seconds, _x.processed_seconds))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      end = 0
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.current_bagfile_name = str[start:end].decode('utf-8')
      else:
        self.current_bagfile_name = str[start:end]
      _x = self
      start = end
      end += 24
      (_x.current_bagfile_id, _x.total_bagfiles, _x.total_messages, _x.processed_messages, _x.total_seconds, _x.processed_seconds,) = _get_struct_4I2f().unpack(str[start:end])
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
      _x = self.current_bagfile_name
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_get_struct_4I2f().pack(_x.current_bagfile_id, _x.total_bagfiles, _x.total_messages, _x.processed_messages, _x.total_seconds, _x.processed_seconds))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      end = 0
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.current_bagfile_name = str[start:end].decode('utf-8')
      else:
        self.current_bagfile_name = str[start:end]
      _x = self
      start = end
      end += 24
      (_x.current_bagfile_id, _x.total_bagfiles, _x.total_messages, _x.processed_messages, _x.total_seconds, _x.processed_seconds,) = _get_struct_4I2f().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_4I2f = None
def _get_struct_4I2f():
    global _struct_4I2f
    if _struct_4I2f is None:
        _struct_4I2f = struct.Struct("<4I2f")
    return _struct_4I2f

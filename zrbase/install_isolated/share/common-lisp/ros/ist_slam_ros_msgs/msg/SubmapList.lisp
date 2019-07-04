; Auto-generated. Do not edit!


(cl:in-package ist_slam_ros_msgs-msg)


;//! \htmlinclude SubmapList.msg.html

(cl:defclass <SubmapList> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (submap
    :reader submap
    :initarg :submap
    :type (cl:vector ist_slam_ros_msgs-msg:SubmapEntry)
   :initform (cl:make-array 0 :element-type 'ist_slam_ros_msgs-msg:SubmapEntry :initial-element (cl:make-instance 'ist_slam_ros_msgs-msg:SubmapEntry))))
)

(cl:defclass SubmapList (<SubmapList>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SubmapList>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SubmapList)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name ist_slam_ros_msgs-msg:<SubmapList> is deprecated: use ist_slam_ros_msgs-msg:SubmapList instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <SubmapList>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ist_slam_ros_msgs-msg:header-val is deprecated.  Use ist_slam_ros_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'submap-val :lambda-list '(m))
(cl:defmethod submap-val ((m <SubmapList>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ist_slam_ros_msgs-msg:submap-val is deprecated.  Use ist_slam_ros_msgs-msg:submap instead.")
  (submap m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SubmapList>) ostream)
  "Serializes a message object of type '<SubmapList>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'submap))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'submap))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SubmapList>) istream)
  "Deserializes a message object of type '<SubmapList>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'submap) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'submap)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'ist_slam_ros_msgs-msg:SubmapEntry))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SubmapList>)))
  "Returns string type for a message object of type '<SubmapList>"
  "ist_slam_ros_msgs/SubmapList")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SubmapList)))
  "Returns string type for a message object of type 'SubmapList"
  "ist_slam_ros_msgs/SubmapList")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SubmapList>)))
  "Returns md5sum for a message object of type '<SubmapList>"
  "73b1e412208f0787050395996f6143db")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SubmapList)))
  "Returns md5sum for a message object of type 'SubmapList"
  "73b1e412208f0787050395996f6143db")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SubmapList>)))
  "Returns full string definition for message of type '<SubmapList>"
  (cl:format cl:nil "~%std_msgs/Header header~%ist_slam_ros_msgs/SubmapEntry[] submap~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: ist_slam_ros_msgs/SubmapEntry~%~%int32 trajectory_id~%int32 submap_index~%int32 submap_version~%geometry_msgs/Pose pose~%bool is_frozen~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SubmapList)))
  "Returns full string definition for message of type 'SubmapList"
  (cl:format cl:nil "~%std_msgs/Header header~%ist_slam_ros_msgs/SubmapEntry[] submap~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: ist_slam_ros_msgs/SubmapEntry~%~%int32 trajectory_id~%int32 submap_index~%int32 submap_version~%geometry_msgs/Pose pose~%bool is_frozen~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SubmapList>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'submap) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SubmapList>))
  "Converts a ROS message object to a list"
  (cl:list 'SubmapList
    (cl:cons ':header (header msg))
    (cl:cons ':submap (submap msg))
))

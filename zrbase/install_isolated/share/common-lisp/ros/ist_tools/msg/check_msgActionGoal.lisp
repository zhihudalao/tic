; Auto-generated. Do not edit!


(cl:in-package ist_tools-msg)


;//! \htmlinclude check_msgActionGoal.msg.html

(cl:defclass <check_msgActionGoal> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (goal_id
    :reader goal_id
    :initarg :goal_id
    :type actionlib_msgs-msg:GoalID
    :initform (cl:make-instance 'actionlib_msgs-msg:GoalID))
   (goal
    :reader goal
    :initarg :goal
    :type ist_tools-msg:check_msgGoal
    :initform (cl:make-instance 'ist_tools-msg:check_msgGoal)))
)

(cl:defclass check_msgActionGoal (<check_msgActionGoal>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <check_msgActionGoal>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'check_msgActionGoal)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name ist_tools-msg:<check_msgActionGoal> is deprecated: use ist_tools-msg:check_msgActionGoal instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <check_msgActionGoal>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ist_tools-msg:header-val is deprecated.  Use ist_tools-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'goal_id-val :lambda-list '(m))
(cl:defmethod goal_id-val ((m <check_msgActionGoal>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ist_tools-msg:goal_id-val is deprecated.  Use ist_tools-msg:goal_id instead.")
  (goal_id m))

(cl:ensure-generic-function 'goal-val :lambda-list '(m))
(cl:defmethod goal-val ((m <check_msgActionGoal>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ist_tools-msg:goal-val is deprecated.  Use ist_tools-msg:goal instead.")
  (goal m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <check_msgActionGoal>) ostream)
  "Serializes a message object of type '<check_msgActionGoal>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'goal_id) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'goal) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <check_msgActionGoal>) istream)
  "Deserializes a message object of type '<check_msgActionGoal>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'goal_id) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'goal) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<check_msgActionGoal>)))
  "Returns string type for a message object of type '<check_msgActionGoal>"
  "ist_tools/check_msgActionGoal")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'check_msgActionGoal)))
  "Returns string type for a message object of type 'check_msgActionGoal"
  "ist_tools/check_msgActionGoal")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<check_msgActionGoal>)))
  "Returns md5sum for a message object of type '<check_msgActionGoal>"
  "817480006cea562a0ac6d5ba846f7693")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'check_msgActionGoal)))
  "Returns md5sum for a message object of type 'check_msgActionGoal"
  "817480006cea562a0ac6d5ba846f7693")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<check_msgActionGoal>)))
  "Returns full string definition for message of type '<check_msgActionGoal>"
  (cl:format cl:nil "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%~%Header header~%actionlib_msgs/GoalID goal_id~%check_msgGoal goal~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: actionlib_msgs/GoalID~%# The stamp should store the time at which this goal was requested.~%# It is used by an action server when it tries to preempt all~%# goals that were requested before a certain time~%time stamp~%~%# The id provides a way to associate feedback and~%# result message with specific goal requests. The id~%# specified must be unique.~%string id~%~%~%================================================================================~%MSG: ist_tools/check_msgGoal~%# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%#goal definition~%string imu~%float32 distance~%float32 angule~%float32 vel~%float32 error~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'check_msgActionGoal)))
  "Returns full string definition for message of type 'check_msgActionGoal"
  (cl:format cl:nil "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%~%Header header~%actionlib_msgs/GoalID goal_id~%check_msgGoal goal~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: actionlib_msgs/GoalID~%# The stamp should store the time at which this goal was requested.~%# It is used by an action server when it tries to preempt all~%# goals that were requested before a certain time~%time stamp~%~%# The id provides a way to associate feedback and~%# result message with specific goal requests. The id~%# specified must be unique.~%string id~%~%~%================================================================================~%MSG: ist_tools/check_msgGoal~%# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%#goal definition~%string imu~%float32 distance~%float32 angule~%float32 vel~%float32 error~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <check_msgActionGoal>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'goal_id))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'goal))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <check_msgActionGoal>))
  "Converts a ROS message object to a list"
  (cl:list 'check_msgActionGoal
    (cl:cons ':header (header msg))
    (cl:cons ':goal_id (goal_id msg))
    (cl:cons ':goal (goal msg))
))

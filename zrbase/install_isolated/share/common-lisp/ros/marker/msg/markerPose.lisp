; Auto-generated. Do not edit!


(cl:in-package marker-msg)


;//! \htmlinclude markerPose.msg.html

(cl:defclass <markerPose> (roslisp-msg-protocol:ros-message)
  ((name
    :reader name
    :initarg :name
    :type cl:string
    :initform "")
   (pose
    :reader pose
    :initarg :pose
    :type geometry_msgs-msg:Pose
    :initform (cl:make-instance 'geometry_msgs-msg:Pose)))
)

(cl:defclass markerPose (<markerPose>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <markerPose>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'markerPose)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name marker-msg:<markerPose> is deprecated: use marker-msg:markerPose instead.")))

(cl:ensure-generic-function 'name-val :lambda-list '(m))
(cl:defmethod name-val ((m <markerPose>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader marker-msg:name-val is deprecated.  Use marker-msg:name instead.")
  (name m))

(cl:ensure-generic-function 'pose-val :lambda-list '(m))
(cl:defmethod pose-val ((m <markerPose>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader marker-msg:pose-val is deprecated.  Use marker-msg:pose instead.")
  (pose m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <markerPose>) ostream)
  "Serializes a message object of type '<markerPose>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'name))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'name))
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'pose) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <markerPose>) istream)
  "Deserializes a message object of type '<markerPose>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'name) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'name) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'pose) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<markerPose>)))
  "Returns string type for a message object of type '<markerPose>"
  "marker/markerPose")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'markerPose)))
  "Returns string type for a message object of type 'markerPose"
  "marker/markerPose")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<markerPose>)))
  "Returns md5sum for a message object of type '<markerPose>"
  "177d54286ddeee12eba514054bddffd5")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'markerPose)))
  "Returns md5sum for a message object of type 'markerPose"
  "177d54286ddeee12eba514054bddffd5")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<markerPose>)))
  "Returns full string definition for message of type '<markerPose>"
  (cl:format cl:nil "string name~%geometry_msgs/Pose pose~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'markerPose)))
  "Returns full string definition for message of type 'markerPose"
  (cl:format cl:nil "string name~%geometry_msgs/Pose pose~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <markerPose>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'name))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'pose))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <markerPose>))
  "Converts a ROS message object to a list"
  (cl:list 'markerPose
    (cl:cons ':name (name msg))
    (cl:cons ':pose (pose msg))
))

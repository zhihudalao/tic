; Auto-generated. Do not edit!


(cl:in-package marker-msg)


;//! \htmlinclude markerPoseArray.msg.html

(cl:defclass <markerPoseArray> (roslisp-msg-protocol:ros-message)
  ((markers
    :reader markers
    :initarg :markers
    :type (cl:vector marker-msg:markerPose)
   :initform (cl:make-array 0 :element-type 'marker-msg:markerPose :initial-element (cl:make-instance 'marker-msg:markerPose))))
)

(cl:defclass markerPoseArray (<markerPoseArray>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <markerPoseArray>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'markerPoseArray)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name marker-msg:<markerPoseArray> is deprecated: use marker-msg:markerPoseArray instead.")))

(cl:ensure-generic-function 'markers-val :lambda-list '(m))
(cl:defmethod markers-val ((m <markerPoseArray>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader marker-msg:markers-val is deprecated.  Use marker-msg:markers instead.")
  (markers m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <markerPoseArray>) ostream)
  "Serializes a message object of type '<markerPoseArray>"
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'markers))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'markers))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <markerPoseArray>) istream)
  "Deserializes a message object of type '<markerPoseArray>"
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'markers) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'markers)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'marker-msg:markerPose))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<markerPoseArray>)))
  "Returns string type for a message object of type '<markerPoseArray>"
  "marker/markerPoseArray")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'markerPoseArray)))
  "Returns string type for a message object of type 'markerPoseArray"
  "marker/markerPoseArray")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<markerPoseArray>)))
  "Returns md5sum for a message object of type '<markerPoseArray>"
  "c5f6d3ea5a86708d66e8b0f23988b7f6")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'markerPoseArray)))
  "Returns md5sum for a message object of type 'markerPoseArray"
  "c5f6d3ea5a86708d66e8b0f23988b7f6")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<markerPoseArray>)))
  "Returns full string definition for message of type '<markerPoseArray>"
  (cl:format cl:nil "marker/markerPose[] markers~%================================================================================~%MSG: marker/markerPose~%string name~%geometry_msgs/Pose pose~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'markerPoseArray)))
  "Returns full string definition for message of type 'markerPoseArray"
  (cl:format cl:nil "marker/markerPose[] markers~%================================================================================~%MSG: marker/markerPose~%string name~%geometry_msgs/Pose pose~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <markerPoseArray>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'markers) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <markerPoseArray>))
  "Converts a ROS message object to a list"
  (cl:list 'markerPoseArray
    (cl:cons ':markers (markers msg))
))

; Auto-generated. Do not edit!


(cl:in-package common-msg)


;//! \htmlinclude maplist.msg.html

(cl:defclass <maplist> (roslisp-msg-protocol:ros-message)
  ((maplist
    :reader maplist
    :initarg :maplist
    :type (cl:vector cl:string)
   :initform (cl:make-array 0 :element-type 'cl:string :initial-element "")))
)

(cl:defclass maplist (<maplist>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <maplist>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'maplist)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name common-msg:<maplist> is deprecated: use common-msg:maplist instead.")))

(cl:ensure-generic-function 'maplist-val :lambda-list '(m))
(cl:defmethod maplist-val ((m <maplist>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader common-msg:maplist-val is deprecated.  Use common-msg:maplist instead.")
  (maplist m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <maplist>) ostream)
  "Serializes a message object of type '<maplist>"
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'maplist))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((__ros_str_len (cl:length ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) ele))
   (cl:slot-value msg 'maplist))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <maplist>) istream)
  "Deserializes a message object of type '<maplist>"
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'maplist) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'maplist)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:aref vals i) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:aref vals i) __ros_str_idx) (cl:code-char (cl:read-byte istream))))))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<maplist>)))
  "Returns string type for a message object of type '<maplist>"
  "common/maplist")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'maplist)))
  "Returns string type for a message object of type 'maplist"
  "common/maplist")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<maplist>)))
  "Returns md5sum for a message object of type '<maplist>"
  "2f17be7ef84382701baab17066775a33")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'maplist)))
  "Returns md5sum for a message object of type 'maplist"
  "2f17be7ef84382701baab17066775a33")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<maplist>)))
  "Returns full string definition for message of type '<maplist>"
  (cl:format cl:nil "string[] maplist~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'maplist)))
  "Returns full string definition for message of type 'maplist"
  (cl:format cl:nil "string[] maplist~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <maplist>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'maplist) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4 (cl:length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <maplist>))
  "Converts a ROS message object to a list"
  (cl:list 'maplist
    (cl:cons ':maplist (maplist msg))
))

; Auto-generated. Do not edit!


(cl:in-package auto_charge-msg)


;//! \htmlinclude ir.msg.html

(cl:defclass <ir> (roslisp-msg-protocol:ros-message)
  ((ir_data
    :reader ir_data
    :initarg :ir_data
    :type cl:string
    :initform "")
   (ir_charging
    :reader ir_charging
    :initarg :ir_charging
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass ir (<ir>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ir>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ir)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name auto_charge-msg:<ir> is deprecated: use auto_charge-msg:ir instead.")))

(cl:ensure-generic-function 'ir_data-val :lambda-list '(m))
(cl:defmethod ir_data-val ((m <ir>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader auto_charge-msg:ir_data-val is deprecated.  Use auto_charge-msg:ir_data instead.")
  (ir_data m))

(cl:ensure-generic-function 'ir_charging-val :lambda-list '(m))
(cl:defmethod ir_charging-val ((m <ir>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader auto_charge-msg:ir_charging-val is deprecated.  Use auto_charge-msg:ir_charging instead.")
  (ir_charging m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ir>) ostream)
  "Serializes a message object of type '<ir>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'ir_data))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'ir_data))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'ir_charging) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ir>) istream)
  "Deserializes a message object of type '<ir>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'ir_data) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'ir_data) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:setf (cl:slot-value msg 'ir_charging) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ir>)))
  "Returns string type for a message object of type '<ir>"
  "auto_charge/ir")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ir)))
  "Returns string type for a message object of type 'ir"
  "auto_charge/ir")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ir>)))
  "Returns md5sum for a message object of type '<ir>"
  "9e4e7b7ff71e150dd913663f82725e90")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ir)))
  "Returns md5sum for a message object of type 'ir"
  "9e4e7b7ff71e150dd913663f82725e90")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ir>)))
  "Returns full string definition for message of type '<ir>"
  (cl:format cl:nil "string ir_data~%bool ir_charging~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ir)))
  "Returns full string definition for message of type 'ir"
  (cl:format cl:nil "string ir_data~%bool ir_charging~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ir>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'ir_data))
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ir>))
  "Converts a ROS message object to a list"
  (cl:list 'ir
    (cl:cons ':ir_data (ir_data msg))
    (cl:cons ':ir_charging (ir_charging msg))
))

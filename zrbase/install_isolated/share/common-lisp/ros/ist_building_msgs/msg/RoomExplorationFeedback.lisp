; Auto-generated. Do not edit!


(cl:in-package ist_building_msgs-msg)


;//! \htmlinclude RoomExplorationFeedback.msg.html

(cl:defclass <RoomExplorationFeedback> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass RoomExplorationFeedback (<RoomExplorationFeedback>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <RoomExplorationFeedback>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'RoomExplorationFeedback)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name ist_building_msgs-msg:<RoomExplorationFeedback> is deprecated: use ist_building_msgs-msg:RoomExplorationFeedback instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <RoomExplorationFeedback>) ostream)
  "Serializes a message object of type '<RoomExplorationFeedback>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <RoomExplorationFeedback>) istream)
  "Deserializes a message object of type '<RoomExplorationFeedback>"
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<RoomExplorationFeedback>)))
  "Returns string type for a message object of type '<RoomExplorationFeedback>"
  "ist_building_msgs/RoomExplorationFeedback")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'RoomExplorationFeedback)))
  "Returns string type for a message object of type 'RoomExplorationFeedback"
  "ist_building_msgs/RoomExplorationFeedback")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<RoomExplorationFeedback>)))
  "Returns md5sum for a message object of type '<RoomExplorationFeedback>"
  "d41d8cd98f00b204e9800998ecf8427e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'RoomExplorationFeedback)))
  "Returns md5sum for a message object of type 'RoomExplorationFeedback"
  "d41d8cd98f00b204e9800998ecf8427e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<RoomExplorationFeedback>)))
  "Returns full string definition for message of type '<RoomExplorationFeedback>"
  (cl:format cl:nil "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%# feedback definition~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'RoomExplorationFeedback)))
  "Returns full string definition for message of type 'RoomExplorationFeedback"
  (cl:format cl:nil "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%# feedback definition~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <RoomExplorationFeedback>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <RoomExplorationFeedback>))
  "Converts a ROS message object to a list"
  (cl:list 'RoomExplorationFeedback
))

;; Auto-generated. Do not edit!


(when (boundp 'ist_slam_ros_msgs::GetTrajectoryStates)
  (if (not (find-package "IST_SLAM_ROS_MSGS"))
    (make-package "IST_SLAM_ROS_MSGS"))
  (shadow 'GetTrajectoryStates (find-package "IST_SLAM_ROS_MSGS")))
(unless (find-package "IST_SLAM_ROS_MSGS::GETTRAJECTORYSTATES")
  (make-package "IST_SLAM_ROS_MSGS::GETTRAJECTORYSTATES"))
(unless (find-package "IST_SLAM_ROS_MSGS::GETTRAJECTORYSTATESREQUEST")
  (make-package "IST_SLAM_ROS_MSGS::GETTRAJECTORYSTATESREQUEST"))
(unless (find-package "IST_SLAM_ROS_MSGS::GETTRAJECTORYSTATESRESPONSE")
  (make-package "IST_SLAM_ROS_MSGS::GETTRAJECTORYSTATESRESPONSE"))

(in-package "ROS")





(defclass ist_slam_ros_msgs::GetTrajectoryStatesRequest
  :super ros::object
  :slots ())

(defmethod ist_slam_ros_msgs::GetTrajectoryStatesRequest
  (:init
   (&key
    )
   (send-super :init)
   self)
  (:serialization-length
   ()
   (+
    0
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;;
   self)
  )

(defclass ist_slam_ros_msgs::GetTrajectoryStatesResponse
  :super ros::object
  :slots (_status _trajectory_states ))

(defmethod ist_slam_ros_msgs::GetTrajectoryStatesResponse
  (:init
   (&key
    ((:status __status) (instance ist_slam_ros_msgs::StatusResponse :init))
    ((:trajectory_states __trajectory_states) (instance ist_slam_ros_msgs::TrajectoryStates :init))
    )
   (send-super :init)
   (setq _status __status)
   (setq _trajectory_states __trajectory_states)
   self)
  (:status
   (&rest __status)
   (if (keywordp (car __status))
       (send* _status __status)
     (progn
       (if __status (setq _status (car __status)))
       _status)))
  (:trajectory_states
   (&rest __trajectory_states)
   (if (keywordp (car __trajectory_states))
       (send* _trajectory_states __trajectory_states)
     (progn
       (if __trajectory_states (setq _trajectory_states (car __trajectory_states)))
       _trajectory_states)))
  (:serialization-length
   ()
   (+
    ;; ist_slam_ros_msgs/StatusResponse _status
    (send _status :serialization-length)
    ;; ist_slam_ros_msgs/TrajectoryStates _trajectory_states
    (send _trajectory_states :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; ist_slam_ros_msgs/StatusResponse _status
       (send _status :serialize s)
     ;; ist_slam_ros_msgs/TrajectoryStates _trajectory_states
       (send _trajectory_states :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; ist_slam_ros_msgs/StatusResponse _status
     (send _status :deserialize buf ptr-) (incf ptr- (send _status :serialization-length))
   ;; ist_slam_ros_msgs/TrajectoryStates _trajectory_states
     (send _trajectory_states :deserialize buf ptr-) (incf ptr- (send _trajectory_states :serialization-length))
   ;;
   self)
  )

(defclass ist_slam_ros_msgs::GetTrajectoryStates
  :super ros::object
  :slots ())

(setf (get ist_slam_ros_msgs::GetTrajectoryStates :md5sum-) "b9e3b373f17df088ee6dcd817b79dff0")
(setf (get ist_slam_ros_msgs::GetTrajectoryStates :datatype-) "ist_slam_ros_msgs/GetTrajectoryStates")
(setf (get ist_slam_ros_msgs::GetTrajectoryStates :request) ist_slam_ros_msgs::GetTrajectoryStatesRequest)
(setf (get ist_slam_ros_msgs::GetTrajectoryStates :response) ist_slam_ros_msgs::GetTrajectoryStatesResponse)

(defmethod ist_slam_ros_msgs::GetTrajectoryStatesRequest
  (:response () (instance ist_slam_ros_msgs::GetTrajectoryStatesResponse :init)))

(setf (get ist_slam_ros_msgs::GetTrajectoryStatesRequest :md5sum-) "b9e3b373f17df088ee6dcd817b79dff0")
(setf (get ist_slam_ros_msgs::GetTrajectoryStatesRequest :datatype-) "ist_slam_ros_msgs/GetTrajectoryStatesRequest")
(setf (get ist_slam_ros_msgs::GetTrajectoryStatesRequest :definition-)
      "

---
ist_slam_ros_msgs/StatusResponse status
ist_slam_ros_msgs/TrajectoryStates trajectory_states


================================================================================
MSG: ist_slam_ros_msgs/StatusResponse

# A common message type to indicate the outcome of a service call.
uint8 code
string message

================================================================================
MSG: ist_slam_ros_msgs/TrajectoryStates

uint8 ACTIVE = 0
uint8 FINISHED = 1
uint8 FROZEN = 2
uint8 DELETED = 3

std_msgs/Header header
int32[] trajectory_id
uint8[] trajectory_state

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
# 0: no frame
# 1: global frame
string frame_id
")

(setf (get ist_slam_ros_msgs::GetTrajectoryStatesResponse :md5sum-) "b9e3b373f17df088ee6dcd817b79dff0")
(setf (get ist_slam_ros_msgs::GetTrajectoryStatesResponse :datatype-) "ist_slam_ros_msgs/GetTrajectoryStatesResponse")
(setf (get ist_slam_ros_msgs::GetTrajectoryStatesResponse :definition-)
      "

---
ist_slam_ros_msgs/StatusResponse status
ist_slam_ros_msgs/TrajectoryStates trajectory_states


================================================================================
MSG: ist_slam_ros_msgs/StatusResponse

# A common message type to indicate the outcome of a service call.
uint8 code
string message

================================================================================
MSG: ist_slam_ros_msgs/TrajectoryStates

uint8 ACTIVE = 0
uint8 FINISHED = 1
uint8 FROZEN = 2
uint8 DELETED = 3

std_msgs/Header header
int32[] trajectory_id
uint8[] trajectory_state

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
# 0: no frame
# 1: global frame
string frame_id
")



(provide :ist_slam_ros_msgs/GetTrajectoryStates "b9e3b373f17df088ee6dcd817b79dff0")



;; Auto-generated. Do not edit!


(when (boundp 'ist_slam_ros_msgs::FinishTrajectory)
  (if (not (find-package "IST_SLAM_ROS_MSGS"))
    (make-package "IST_SLAM_ROS_MSGS"))
  (shadow 'FinishTrajectory (find-package "IST_SLAM_ROS_MSGS")))
(unless (find-package "IST_SLAM_ROS_MSGS::FINISHTRAJECTORY")
  (make-package "IST_SLAM_ROS_MSGS::FINISHTRAJECTORY"))
(unless (find-package "IST_SLAM_ROS_MSGS::FINISHTRAJECTORYREQUEST")
  (make-package "IST_SLAM_ROS_MSGS::FINISHTRAJECTORYREQUEST"))
(unless (find-package "IST_SLAM_ROS_MSGS::FINISHTRAJECTORYRESPONSE")
  (make-package "IST_SLAM_ROS_MSGS::FINISHTRAJECTORYRESPONSE"))

(in-package "ROS")





(defclass ist_slam_ros_msgs::FinishTrajectoryRequest
  :super ros::object
  :slots (_trajectory_id ))

(defmethod ist_slam_ros_msgs::FinishTrajectoryRequest
  (:init
   (&key
    ((:trajectory_id __trajectory_id) 0)
    )
   (send-super :init)
   (setq _trajectory_id (round __trajectory_id))
   self)
  (:trajectory_id
   (&optional __trajectory_id)
   (if __trajectory_id (setq _trajectory_id __trajectory_id)) _trajectory_id)
  (:serialization-length
   ()
   (+
    ;; int32 _trajectory_id
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _trajectory_id
       (write-long _trajectory_id s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _trajectory_id
     (setq _trajectory_id (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(defclass ist_slam_ros_msgs::FinishTrajectoryResponse
  :super ros::object
  :slots (_status ))

(defmethod ist_slam_ros_msgs::FinishTrajectoryResponse
  (:init
   (&key
    ((:status __status) (instance ist_slam_ros_msgs::StatusResponse :init))
    )
   (send-super :init)
   (setq _status __status)
   self)
  (:status
   (&rest __status)
   (if (keywordp (car __status))
       (send* _status __status)
     (progn
       (if __status (setq _status (car __status)))
       _status)))
  (:serialization-length
   ()
   (+
    ;; ist_slam_ros_msgs/StatusResponse _status
    (send _status :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; ist_slam_ros_msgs/StatusResponse _status
       (send _status :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; ist_slam_ros_msgs/StatusResponse _status
     (send _status :deserialize buf ptr-) (incf ptr- (send _status :serialization-length))
   ;;
   self)
  )

(defclass ist_slam_ros_msgs::FinishTrajectory
  :super ros::object
  :slots ())

(setf (get ist_slam_ros_msgs::FinishTrajectory :md5sum-) "0feba73841cb434875547ca2a563a021")
(setf (get ist_slam_ros_msgs::FinishTrajectory :datatype-) "ist_slam_ros_msgs/FinishTrajectory")
(setf (get ist_slam_ros_msgs::FinishTrajectory :request) ist_slam_ros_msgs::FinishTrajectoryRequest)
(setf (get ist_slam_ros_msgs::FinishTrajectory :response) ist_slam_ros_msgs::FinishTrajectoryResponse)

(defmethod ist_slam_ros_msgs::FinishTrajectoryRequest
  (:response () (instance ist_slam_ros_msgs::FinishTrajectoryResponse :init)))

(setf (get ist_slam_ros_msgs::FinishTrajectoryRequest :md5sum-) "0feba73841cb434875547ca2a563a021")
(setf (get ist_slam_ros_msgs::FinishTrajectoryRequest :datatype-) "ist_slam_ros_msgs/FinishTrajectoryRequest")
(setf (get ist_slam_ros_msgs::FinishTrajectoryRequest :definition-)
      "
int32 trajectory_id
---
ist_slam_ros_msgs/StatusResponse status


================================================================================
MSG: ist_slam_ros_msgs/StatusResponse

# A common message type to indicate the outcome of a service call.
uint8 code
string message
")

(setf (get ist_slam_ros_msgs::FinishTrajectoryResponse :md5sum-) "0feba73841cb434875547ca2a563a021")
(setf (get ist_slam_ros_msgs::FinishTrajectoryResponse :datatype-) "ist_slam_ros_msgs/FinishTrajectoryResponse")
(setf (get ist_slam_ros_msgs::FinishTrajectoryResponse :definition-)
      "
int32 trajectory_id
---
ist_slam_ros_msgs/StatusResponse status


================================================================================
MSG: ist_slam_ros_msgs/StatusResponse

# A common message type to indicate the outcome of a service call.
uint8 code
string message
")



(provide :ist_slam_ros_msgs/FinishTrajectory "0feba73841cb434875547ca2a563a021")



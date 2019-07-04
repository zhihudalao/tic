;; Auto-generated. Do not edit!


(when (boundp 'ist_slam_ros_msgs::StatusCode)
  (if (not (find-package "IST_SLAM_ROS_MSGS"))
    (make-package "IST_SLAM_ROS_MSGS"))
  (shadow 'StatusCode (find-package "IST_SLAM_ROS_MSGS")))
(unless (find-package "IST_SLAM_ROS_MSGS::STATUSCODE")
  (make-package "IST_SLAM_ROS_MSGS::STATUSCODE"))

(in-package "ROS")
;;//! \htmlinclude StatusCode.msg.html


(intern "*OK*" (find-package "IST_SLAM_ROS_MSGS::STATUSCODE"))
(shadow '*OK* (find-package "IST_SLAM_ROS_MSGS::STATUSCODE"))
(defconstant ist_slam_ros_msgs::StatusCode::*OK* 0)
(intern "*CANCELLED*" (find-package "IST_SLAM_ROS_MSGS::STATUSCODE"))
(shadow '*CANCELLED* (find-package "IST_SLAM_ROS_MSGS::STATUSCODE"))
(defconstant ist_slam_ros_msgs::StatusCode::*CANCELLED* 1)
(intern "*UNKNOWN*" (find-package "IST_SLAM_ROS_MSGS::STATUSCODE"))
(shadow '*UNKNOWN* (find-package "IST_SLAM_ROS_MSGS::STATUSCODE"))
(defconstant ist_slam_ros_msgs::StatusCode::*UNKNOWN* 2)
(intern "*INVALID_ARGUMENT*" (find-package "IST_SLAM_ROS_MSGS::STATUSCODE"))
(shadow '*INVALID_ARGUMENT* (find-package "IST_SLAM_ROS_MSGS::STATUSCODE"))
(defconstant ist_slam_ros_msgs::StatusCode::*INVALID_ARGUMENT* 3)
(intern "*DEADLINE_EXCEEDED*" (find-package "IST_SLAM_ROS_MSGS::STATUSCODE"))
(shadow '*DEADLINE_EXCEEDED* (find-package "IST_SLAM_ROS_MSGS::STATUSCODE"))
(defconstant ist_slam_ros_msgs::StatusCode::*DEADLINE_EXCEEDED* 4)
(intern "*NOT_FOUND*" (find-package "IST_SLAM_ROS_MSGS::STATUSCODE"))
(shadow '*NOT_FOUND* (find-package "IST_SLAM_ROS_MSGS::STATUSCODE"))
(defconstant ist_slam_ros_msgs::StatusCode::*NOT_FOUND* 5)
(intern "*ALREADY_EXISTS*" (find-package "IST_SLAM_ROS_MSGS::STATUSCODE"))
(shadow '*ALREADY_EXISTS* (find-package "IST_SLAM_ROS_MSGS::STATUSCODE"))
(defconstant ist_slam_ros_msgs::StatusCode::*ALREADY_EXISTS* 6)
(intern "*PERMISSION_DENIED*" (find-package "IST_SLAM_ROS_MSGS::STATUSCODE"))
(shadow '*PERMISSION_DENIED* (find-package "IST_SLAM_ROS_MSGS::STATUSCODE"))
(defconstant ist_slam_ros_msgs::StatusCode::*PERMISSION_DENIED* 7)
(intern "*RESOURCE_EXHAUSTED*" (find-package "IST_SLAM_ROS_MSGS::STATUSCODE"))
(shadow '*RESOURCE_EXHAUSTED* (find-package "IST_SLAM_ROS_MSGS::STATUSCODE"))
(defconstant ist_slam_ros_msgs::StatusCode::*RESOURCE_EXHAUSTED* 8)
(intern "*FAILED_PRECONDITION*" (find-package "IST_SLAM_ROS_MSGS::STATUSCODE"))
(shadow '*FAILED_PRECONDITION* (find-package "IST_SLAM_ROS_MSGS::STATUSCODE"))
(defconstant ist_slam_ros_msgs::StatusCode::*FAILED_PRECONDITION* 9)
(intern "*ABORTED*" (find-package "IST_SLAM_ROS_MSGS::STATUSCODE"))
(shadow '*ABORTED* (find-package "IST_SLAM_ROS_MSGS::STATUSCODE"))
(defconstant ist_slam_ros_msgs::StatusCode::*ABORTED* 10)
(intern "*OUT_OF_RANGE*" (find-package "IST_SLAM_ROS_MSGS::STATUSCODE"))
(shadow '*OUT_OF_RANGE* (find-package "IST_SLAM_ROS_MSGS::STATUSCODE"))
(defconstant ist_slam_ros_msgs::StatusCode::*OUT_OF_RANGE* 11)
(intern "*UNIMPLEMENTED*" (find-package "IST_SLAM_ROS_MSGS::STATUSCODE"))
(shadow '*UNIMPLEMENTED* (find-package "IST_SLAM_ROS_MSGS::STATUSCODE"))
(defconstant ist_slam_ros_msgs::StatusCode::*UNIMPLEMENTED* 12)
(intern "*INTERNAL*" (find-package "IST_SLAM_ROS_MSGS::STATUSCODE"))
(shadow '*INTERNAL* (find-package "IST_SLAM_ROS_MSGS::STATUSCODE"))
(defconstant ist_slam_ros_msgs::StatusCode::*INTERNAL* 13)
(intern "*UNAVAILABLE*" (find-package "IST_SLAM_ROS_MSGS::STATUSCODE"))
(shadow '*UNAVAILABLE* (find-package "IST_SLAM_ROS_MSGS::STATUSCODE"))
(defconstant ist_slam_ros_msgs::StatusCode::*UNAVAILABLE* 14)
(intern "*DATA_LOSS*" (find-package "IST_SLAM_ROS_MSGS::STATUSCODE"))
(shadow '*DATA_LOSS* (find-package "IST_SLAM_ROS_MSGS::STATUSCODE"))
(defconstant ist_slam_ros_msgs::StatusCode::*DATA_LOSS* 15)
(defclass ist_slam_ros_msgs::StatusCode
  :super ros::object
  :slots ())

(defmethod ist_slam_ros_msgs::StatusCode
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

(setf (get ist_slam_ros_msgs::StatusCode :md5sum-) "90c460dc6da71af1a19af6615a8dc9a4")
(setf (get ist_slam_ros_msgs::StatusCode :datatype-) "ist_slam_ros_msgs/StatusCode")
(setf (get ist_slam_ros_msgs::StatusCode :definition-)
      "
# Definition of status code constants equivalent to the gRPC API.
# https://developers.google.com/maps-booking/reference/grpc-api/status_codes
uint8 OK=0
uint8 CANCELLED=1
uint8 UNKNOWN=2
uint8 INVALID_ARGUMENT=3
uint8 DEADLINE_EXCEEDED=4
uint8 NOT_FOUND=5
uint8 ALREADY_EXISTS=6
uint8 PERMISSION_DENIED=7
uint8 RESOURCE_EXHAUSTED=8
uint8 FAILED_PRECONDITION=9
uint8 ABORTED=10
uint8 OUT_OF_RANGE=11
uint8 UNIMPLEMENTED=12
uint8 INTERNAL=13
uint8 UNAVAILABLE=14
uint8 DATA_LOSS=15

")



(provide :ist_slam_ros_msgs/StatusCode "90c460dc6da71af1a19af6615a8dc9a4")



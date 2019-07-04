;; Auto-generated. Do not edit!


(when (boundp 'ist_slam_ros_msgs::LandmarkList)
  (if (not (find-package "IST_SLAM_ROS_MSGS"))
    (make-package "IST_SLAM_ROS_MSGS"))
  (shadow 'LandmarkList (find-package "IST_SLAM_ROS_MSGS")))
(unless (find-package "IST_SLAM_ROS_MSGS::LANDMARKLIST")
  (make-package "IST_SLAM_ROS_MSGS::LANDMARKLIST"))

(in-package "ROS")
;;//! \htmlinclude LandmarkList.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass ist_slam_ros_msgs::LandmarkList
  :super ros::object
  :slots (_header _landmarks ))

(defmethod ist_slam_ros_msgs::LandmarkList
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:landmarks __landmarks) (let (r) (dotimes (i 0) (push (instance ist_slam_ros_msgs::LandmarkEntry :init) r)) r))
    )
   (send-super :init)
   (setq _header __header)
   (setq _landmarks __landmarks)
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:landmarks
   (&rest __landmarks)
   (if (keywordp (car __landmarks))
       (send* _landmarks __landmarks)
     (progn
       (if __landmarks (setq _landmarks (car __landmarks)))
       _landmarks)))
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; ist_slam_ros_msgs/LandmarkEntry[] _landmarks
    (apply #'+ (send-all _landmarks :serialization-length)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; ist_slam_ros_msgs/LandmarkEntry[] _landmarks
     (write-long (length _landmarks) s)
     (dolist (elem _landmarks)
       (send elem :serialize s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; ist_slam_ros_msgs/LandmarkEntry[] _landmarks
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _landmarks (let (r) (dotimes (i n) (push (instance ist_slam_ros_msgs::LandmarkEntry :init) r)) r))
     (dolist (elem- _landmarks)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;;
   self)
  )

(setf (get ist_slam_ros_msgs::LandmarkList :md5sum-) "322e3fb6b49d8fcd97544b4896b0ae66")
(setf (get ist_slam_ros_msgs::LandmarkList :datatype-) "ist_slam_ros_msgs/LandmarkList")
(setf (get ist_slam_ros_msgs::LandmarkList :definition-)
      "
std_msgs/Header header
ist_slam_ros_msgs/LandmarkEntry[] landmarks

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

================================================================================
MSG: ist_slam_ros_msgs/LandmarkEntry

string id
geometry_msgs/Pose tracking_from_landmark_transform
float64 translation_weight
float64 rotation_weight

================================================================================
MSG: geometry_msgs/Pose
# A representation of pose in free space, composed of position and orientation. 
Point position
Quaternion orientation

================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z

================================================================================
MSG: geometry_msgs/Quaternion
# This represents an orientation in free space in quaternion form.

float64 x
float64 y
float64 z
float64 w

")



(provide :ist_slam_ros_msgs/LandmarkList "322e3fb6b49d8fcd97544b4896b0ae66")



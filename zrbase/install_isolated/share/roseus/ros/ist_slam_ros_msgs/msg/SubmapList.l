;; Auto-generated. Do not edit!


(when (boundp 'ist_slam_ros_msgs::SubmapList)
  (if (not (find-package "IST_SLAM_ROS_MSGS"))
    (make-package "IST_SLAM_ROS_MSGS"))
  (shadow 'SubmapList (find-package "IST_SLAM_ROS_MSGS")))
(unless (find-package "IST_SLAM_ROS_MSGS::SUBMAPLIST")
  (make-package "IST_SLAM_ROS_MSGS::SUBMAPLIST"))

(in-package "ROS")
;;//! \htmlinclude SubmapList.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass ist_slam_ros_msgs::SubmapList
  :super ros::object
  :slots (_header _submap ))

(defmethod ist_slam_ros_msgs::SubmapList
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:submap __submap) (let (r) (dotimes (i 0) (push (instance ist_slam_ros_msgs::SubmapEntry :init) r)) r))
    )
   (send-super :init)
   (setq _header __header)
   (setq _submap __submap)
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:submap
   (&rest __submap)
   (if (keywordp (car __submap))
       (send* _submap __submap)
     (progn
       (if __submap (setq _submap (car __submap)))
       _submap)))
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; ist_slam_ros_msgs/SubmapEntry[] _submap
    (apply #'+ (send-all _submap :serialization-length)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; ist_slam_ros_msgs/SubmapEntry[] _submap
     (write-long (length _submap) s)
     (dolist (elem _submap)
       (send elem :serialize s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; ist_slam_ros_msgs/SubmapEntry[] _submap
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _submap (let (r) (dotimes (i n) (push (instance ist_slam_ros_msgs::SubmapEntry :init) r)) r))
     (dolist (elem- _submap)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;;
   self)
  )

(setf (get ist_slam_ros_msgs::SubmapList :md5sum-) "73b1e412208f0787050395996f6143db")
(setf (get ist_slam_ros_msgs::SubmapList :datatype-) "ist_slam_ros_msgs/SubmapList")
(setf (get ist_slam_ros_msgs::SubmapList :definition-)
      "
std_msgs/Header header
ist_slam_ros_msgs/SubmapEntry[] submap

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
MSG: ist_slam_ros_msgs/SubmapEntry

int32 trajectory_id
int32 submap_index
int32 submap_version
geometry_msgs/Pose pose
bool is_frozen

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



(provide :ist_slam_ros_msgs/SubmapList "73b1e412208f0787050395996f6143db")



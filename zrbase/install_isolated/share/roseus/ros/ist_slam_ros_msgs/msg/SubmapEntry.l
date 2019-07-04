;; Auto-generated. Do not edit!


(when (boundp 'ist_slam_ros_msgs::SubmapEntry)
  (if (not (find-package "IST_SLAM_ROS_MSGS"))
    (make-package "IST_SLAM_ROS_MSGS"))
  (shadow 'SubmapEntry (find-package "IST_SLAM_ROS_MSGS")))
(unless (find-package "IST_SLAM_ROS_MSGS::SUBMAPENTRY")
  (make-package "IST_SLAM_ROS_MSGS::SUBMAPENTRY"))

(in-package "ROS")
;;//! \htmlinclude SubmapEntry.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))


(defclass ist_slam_ros_msgs::SubmapEntry
  :super ros::object
  :slots (_trajectory_id _submap_index _submap_version _pose _is_frozen ))

(defmethod ist_slam_ros_msgs::SubmapEntry
  (:init
   (&key
    ((:trajectory_id __trajectory_id) 0)
    ((:submap_index __submap_index) 0)
    ((:submap_version __submap_version) 0)
    ((:pose __pose) (instance geometry_msgs::Pose :init))
    ((:is_frozen __is_frozen) nil)
    )
   (send-super :init)
   (setq _trajectory_id (round __trajectory_id))
   (setq _submap_index (round __submap_index))
   (setq _submap_version (round __submap_version))
   (setq _pose __pose)
   (setq _is_frozen __is_frozen)
   self)
  (:trajectory_id
   (&optional __trajectory_id)
   (if __trajectory_id (setq _trajectory_id __trajectory_id)) _trajectory_id)
  (:submap_index
   (&optional __submap_index)
   (if __submap_index (setq _submap_index __submap_index)) _submap_index)
  (:submap_version
   (&optional __submap_version)
   (if __submap_version (setq _submap_version __submap_version)) _submap_version)
  (:pose
   (&rest __pose)
   (if (keywordp (car __pose))
       (send* _pose __pose)
     (progn
       (if __pose (setq _pose (car __pose)))
       _pose)))
  (:is_frozen
   (&optional __is_frozen)
   (if __is_frozen (setq _is_frozen __is_frozen)) _is_frozen)
  (:serialization-length
   ()
   (+
    ;; int32 _trajectory_id
    4
    ;; int32 _submap_index
    4
    ;; int32 _submap_version
    4
    ;; geometry_msgs/Pose _pose
    (send _pose :serialization-length)
    ;; bool _is_frozen
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _trajectory_id
       (write-long _trajectory_id s)
     ;; int32 _submap_index
       (write-long _submap_index s)
     ;; int32 _submap_version
       (write-long _submap_version s)
     ;; geometry_msgs/Pose _pose
       (send _pose :serialize s)
     ;; bool _is_frozen
       (if _is_frozen (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _trajectory_id
     (setq _trajectory_id (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _submap_index
     (setq _submap_index (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _submap_version
     (setq _submap_version (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; geometry_msgs/Pose _pose
     (send _pose :deserialize buf ptr-) (incf ptr- (send _pose :serialization-length))
   ;; bool _is_frozen
     (setq _is_frozen (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(setf (get ist_slam_ros_msgs::SubmapEntry :md5sum-) "0b064ac06b4af2be11388441508c9572")
(setf (get ist_slam_ros_msgs::SubmapEntry :datatype-) "ist_slam_ros_msgs/SubmapEntry")
(setf (get ist_slam_ros_msgs::SubmapEntry :definition-)
      "
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



(provide :ist_slam_ros_msgs/SubmapEntry "0b064ac06b4af2be11388441508c9572")


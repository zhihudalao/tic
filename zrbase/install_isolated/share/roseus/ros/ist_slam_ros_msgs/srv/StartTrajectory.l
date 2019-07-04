;; Auto-generated. Do not edit!


(when (boundp 'ist_slam_ros_msgs::StartTrajectory)
  (if (not (find-package "IST_SLAM_ROS_MSGS"))
    (make-package "IST_SLAM_ROS_MSGS"))
  (shadow 'StartTrajectory (find-package "IST_SLAM_ROS_MSGS")))
(unless (find-package "IST_SLAM_ROS_MSGS::STARTTRAJECTORY")
  (make-package "IST_SLAM_ROS_MSGS::STARTTRAJECTORY"))
(unless (find-package "IST_SLAM_ROS_MSGS::STARTTRAJECTORYREQUEST")
  (make-package "IST_SLAM_ROS_MSGS::STARTTRAJECTORYREQUEST"))
(unless (find-package "IST_SLAM_ROS_MSGS::STARTTRAJECTORYRESPONSE")
  (make-package "IST_SLAM_ROS_MSGS::STARTTRAJECTORYRESPONSE"))

(in-package "ROS")





(defclass ist_slam_ros_msgs::StartTrajectoryRequest
  :super ros::object
  :slots (_options _topics ))

(defmethod ist_slam_ros_msgs::StartTrajectoryRequest
  (:init
   (&key
    ((:options __options) (instance ist_slam_ros_msgs::TrajectoryOptions :init))
    ((:topics __topics) (instance ist_slam_ros_msgs::SensorTopics :init))
    )
   (send-super :init)
   (setq _options __options)
   (setq _topics __topics)
   self)
  (:options
   (&rest __options)
   (if (keywordp (car __options))
       (send* _options __options)
     (progn
       (if __options (setq _options (car __options)))
       _options)))
  (:topics
   (&rest __topics)
   (if (keywordp (car __topics))
       (send* _topics __topics)
     (progn
       (if __topics (setq _topics (car __topics)))
       _topics)))
  (:serialization-length
   ()
   (+
    ;; ist_slam_ros_msgs/TrajectoryOptions _options
    (send _options :serialization-length)
    ;; ist_slam_ros_msgs/SensorTopics _topics
    (send _topics :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; ist_slam_ros_msgs/TrajectoryOptions _options
       (send _options :serialize s)
     ;; ist_slam_ros_msgs/SensorTopics _topics
       (send _topics :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; ist_slam_ros_msgs/TrajectoryOptions _options
     (send _options :deserialize buf ptr-) (incf ptr- (send _options :serialization-length))
   ;; ist_slam_ros_msgs/SensorTopics _topics
     (send _topics :deserialize buf ptr-) (incf ptr- (send _topics :serialization-length))
   ;;
   self)
  )

(defclass ist_slam_ros_msgs::StartTrajectoryResponse
  :super ros::object
  :slots (_status _trajectory_id ))

(defmethod ist_slam_ros_msgs::StartTrajectoryResponse
  (:init
   (&key
    ((:status __status) (instance ist_slam_ros_msgs::StatusResponse :init))
    ((:trajectory_id __trajectory_id) 0)
    )
   (send-super :init)
   (setq _status __status)
   (setq _trajectory_id (round __trajectory_id))
   self)
  (:status
   (&rest __status)
   (if (keywordp (car __status))
       (send* _status __status)
     (progn
       (if __status (setq _status (car __status)))
       _status)))
  (:trajectory_id
   (&optional __trajectory_id)
   (if __trajectory_id (setq _trajectory_id __trajectory_id)) _trajectory_id)
  (:serialization-length
   ()
   (+
    ;; ist_slam_ros_msgs/StatusResponse _status
    (send _status :serialization-length)
    ;; int32 _trajectory_id
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; ist_slam_ros_msgs/StatusResponse _status
       (send _status :serialize s)
     ;; int32 _trajectory_id
       (write-long _trajectory_id s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; ist_slam_ros_msgs/StatusResponse _status
     (send _status :deserialize buf ptr-) (incf ptr- (send _status :serialization-length))
   ;; int32 _trajectory_id
     (setq _trajectory_id (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(defclass ist_slam_ros_msgs::StartTrajectory
  :super ros::object
  :slots ())

(setf (get ist_slam_ros_msgs::StartTrajectory :md5sum-) "bed83613a1da70f1e83eafd765dad59d")
(setf (get ist_slam_ros_msgs::StartTrajectory :datatype-) "ist_slam_ros_msgs/StartTrajectory")
(setf (get ist_slam_ros_msgs::StartTrajectory :request) ist_slam_ros_msgs::StartTrajectoryRequest)
(setf (get ist_slam_ros_msgs::StartTrajectory :response) ist_slam_ros_msgs::StartTrajectoryResponse)

(defmethod ist_slam_ros_msgs::StartTrajectoryRequest
  (:response () (instance ist_slam_ros_msgs::StartTrajectoryResponse :init)))

(setf (get ist_slam_ros_msgs::StartTrajectoryRequest :md5sum-) "bed83613a1da70f1e83eafd765dad59d")
(setf (get ist_slam_ros_msgs::StartTrajectoryRequest :datatype-) "ist_slam_ros_msgs/StartTrajectoryRequest")
(setf (get ist_slam_ros_msgs::StartTrajectoryRequest :definition-)
      "
ist_slam_ros_msgs/TrajectoryOptions options
ist_slam_ros_msgs/SensorTopics topics

================================================================================
MSG: ist_slam_ros_msgs/TrajectoryOptions

string tracking_frame
string published_frame
string odom_frame
bool provide_odom_frame
bool use_odometry
bool use_nav_sat
bool use_landmarks
bool publish_frame_projected_to_2d
int32 num_laser_scans
int32 num_multi_echo_laser_scans
int32 num_subdivisions_per_laser_scan
int32 num_point_clouds
float64 rangefinder_sampling_ratio
float64 odometry_sampling_ratio
float64 fixed_frame_pose_sampling_ratio
float64 imu_sampling_ratio
float64 landmarks_sampling_ratio

# This is a binary-encoded
# 'ist_slam.mapping.proto.TrajectoryBuilderOptions' proto.
string trajectory_builder_options_proto

================================================================================
MSG: ist_slam_ros_msgs/SensorTopics

string laser_scan_topic
string multi_echo_laser_scan_topic
string point_cloud2_topic
string imu_topic
string odometry_topic
string nav_sat_fix_topic
string landmark_topic
---
ist_slam_ros_msgs/StatusResponse status
int32 trajectory_id


================================================================================
MSG: ist_slam_ros_msgs/StatusResponse

# A common message type to indicate the outcome of a service call.
uint8 code
string message
")

(setf (get ist_slam_ros_msgs::StartTrajectoryResponse :md5sum-) "bed83613a1da70f1e83eafd765dad59d")
(setf (get ist_slam_ros_msgs::StartTrajectoryResponse :datatype-) "ist_slam_ros_msgs/StartTrajectoryResponse")
(setf (get ist_slam_ros_msgs::StartTrajectoryResponse :definition-)
      "
ist_slam_ros_msgs/TrajectoryOptions options
ist_slam_ros_msgs/SensorTopics topics

================================================================================
MSG: ist_slam_ros_msgs/TrajectoryOptions

string tracking_frame
string published_frame
string odom_frame
bool provide_odom_frame
bool use_odometry
bool use_nav_sat
bool use_landmarks
bool publish_frame_projected_to_2d
int32 num_laser_scans
int32 num_multi_echo_laser_scans
int32 num_subdivisions_per_laser_scan
int32 num_point_clouds
float64 rangefinder_sampling_ratio
float64 odometry_sampling_ratio
float64 fixed_frame_pose_sampling_ratio
float64 imu_sampling_ratio
float64 landmarks_sampling_ratio

# This is a binary-encoded
# 'ist_slam.mapping.proto.TrajectoryBuilderOptions' proto.
string trajectory_builder_options_proto

================================================================================
MSG: ist_slam_ros_msgs/SensorTopics

string laser_scan_topic
string multi_echo_laser_scan_topic
string point_cloud2_topic
string imu_topic
string odometry_topic
string nav_sat_fix_topic
string landmark_topic
---
ist_slam_ros_msgs/StatusResponse status
int32 trajectory_id


================================================================================
MSG: ist_slam_ros_msgs/StatusResponse

# A common message type to indicate the outcome of a service call.
uint8 code
string message
")



(provide :ist_slam_ros_msgs/StartTrajectory "bed83613a1da70f1e83eafd765dad59d")



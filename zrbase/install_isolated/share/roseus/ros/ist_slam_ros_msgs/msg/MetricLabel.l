;; Auto-generated. Do not edit!


(when (boundp 'ist_slam_ros_msgs::MetricLabel)
  (if (not (find-package "IST_SLAM_ROS_MSGS"))
    (make-package "IST_SLAM_ROS_MSGS"))
  (shadow 'MetricLabel (find-package "IST_SLAM_ROS_MSGS")))
(unless (find-package "IST_SLAM_ROS_MSGS::METRICLABEL")
  (make-package "IST_SLAM_ROS_MSGS::METRICLABEL"))

(in-package "ROS")
;;//! \htmlinclude MetricLabel.msg.html


(defclass ist_slam_ros_msgs::MetricLabel
  :super ros::object
  :slots (_key _value ))

(defmethod ist_slam_ros_msgs::MetricLabel
  (:init
   (&key
    ((:key __key) "")
    ((:value __value) "")
    )
   (send-super :init)
   (setq _key (string __key))
   (setq _value (string __value))
   self)
  (:key
   (&optional __key)
   (if __key (setq _key __key)) _key)
  (:value
   (&optional __value)
   (if __value (setq _value __value)) _value)
  (:serialization-length
   ()
   (+
    ;; string _key
    4 (length _key)
    ;; string _value
    4 (length _value)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _key
       (write-long (length _key) s) (princ _key s)
     ;; string _value
       (write-long (length _value) s) (princ _value s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _key
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _key (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; string _value
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _value (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(setf (get ist_slam_ros_msgs::MetricLabel :md5sum-) "cf57fdc6617a881a88c16e768132149c")
(setf (get ist_slam_ros_msgs::MetricLabel :datatype-) "ist_slam_ros_msgs/MetricLabel")
(setf (get ist_slam_ros_msgs::MetricLabel :definition-)
      "
string key
string value

")



(provide :ist_slam_ros_msgs/MetricLabel "cf57fdc6617a881a88c16e768132149c")



;; Auto-generated. Do not edit!


(when (boundp 'ist_slam_ros_msgs::HistogramBucket)
  (if (not (find-package "IST_SLAM_ROS_MSGS"))
    (make-package "IST_SLAM_ROS_MSGS"))
  (shadow 'HistogramBucket (find-package "IST_SLAM_ROS_MSGS")))
(unless (find-package "IST_SLAM_ROS_MSGS::HISTOGRAMBUCKET")
  (make-package "IST_SLAM_ROS_MSGS::HISTOGRAMBUCKET"))

(in-package "ROS")
;;//! \htmlinclude HistogramBucket.msg.html


(defclass ist_slam_ros_msgs::HistogramBucket
  :super ros::object
  :slots (_bucket_boundary _count ))

(defmethod ist_slam_ros_msgs::HistogramBucket
  (:init
   (&key
    ((:bucket_boundary __bucket_boundary) 0.0)
    ((:count __count) 0.0)
    )
   (send-super :init)
   (setq _bucket_boundary (float __bucket_boundary))
   (setq _count (float __count))
   self)
  (:bucket_boundary
   (&optional __bucket_boundary)
   (if __bucket_boundary (setq _bucket_boundary __bucket_boundary)) _bucket_boundary)
  (:count
   (&optional __count)
   (if __count (setq _count __count)) _count)
  (:serialization-length
   ()
   (+
    ;; float64 _bucket_boundary
    8
    ;; float64 _count
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _bucket_boundary
       (sys::poke _bucket_boundary (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _count
       (sys::poke _count (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _bucket_boundary
     (setq _bucket_boundary (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _count
     (setq _count (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get ist_slam_ros_msgs::HistogramBucket :md5sum-) "b579df35b32758cf09f65ae223aea0ad")
(setf (get ist_slam_ros_msgs::HistogramBucket :datatype-) "ist_slam_ros_msgs/HistogramBucket")
(setf (get ist_slam_ros_msgs::HistogramBucket :definition-)
      "
# A histogram bucket counts values x for which:
#   previous_boundary < x <= bucket_boundary
# holds.
float64 bucket_boundary
float64 count

")



(provide :ist_slam_ros_msgs/HistogramBucket "b579df35b32758cf09f65ae223aea0ad")



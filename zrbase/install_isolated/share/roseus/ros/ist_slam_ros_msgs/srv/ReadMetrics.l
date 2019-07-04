;; Auto-generated. Do not edit!


(when (boundp 'ist_slam_ros_msgs::ReadMetrics)
  (if (not (find-package "IST_SLAM_ROS_MSGS"))
    (make-package "IST_SLAM_ROS_MSGS"))
  (shadow 'ReadMetrics (find-package "IST_SLAM_ROS_MSGS")))
(unless (find-package "IST_SLAM_ROS_MSGS::READMETRICS")
  (make-package "IST_SLAM_ROS_MSGS::READMETRICS"))
(unless (find-package "IST_SLAM_ROS_MSGS::READMETRICSREQUEST")
  (make-package "IST_SLAM_ROS_MSGS::READMETRICSREQUEST"))
(unless (find-package "IST_SLAM_ROS_MSGS::READMETRICSRESPONSE")
  (make-package "IST_SLAM_ROS_MSGS::READMETRICSRESPONSE"))

(in-package "ROS")





(defclass ist_slam_ros_msgs::ReadMetricsRequest
  :super ros::object
  :slots ())

(defmethod ist_slam_ros_msgs::ReadMetricsRequest
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

(defclass ist_slam_ros_msgs::ReadMetricsResponse
  :super ros::object
  :slots (_status _metric_families _timestamp ))

(defmethod ist_slam_ros_msgs::ReadMetricsResponse
  (:init
   (&key
    ((:status __status) (instance ist_slam_ros_msgs::StatusResponse :init))
    ((:metric_families __metric_families) (let (r) (dotimes (i 0) (push (instance ist_slam_ros_msgs::MetricFamily :init) r)) r))
    ((:timestamp __timestamp) (instance ros::time :init))
    )
   (send-super :init)
   (setq _status __status)
   (setq _metric_families __metric_families)
   (setq _timestamp __timestamp)
   self)
  (:status
   (&rest __status)
   (if (keywordp (car __status))
       (send* _status __status)
     (progn
       (if __status (setq _status (car __status)))
       _status)))
  (:metric_families
   (&rest __metric_families)
   (if (keywordp (car __metric_families))
       (send* _metric_families __metric_families)
     (progn
       (if __metric_families (setq _metric_families (car __metric_families)))
       _metric_families)))
  (:timestamp
   (&optional __timestamp)
   (if __timestamp (setq _timestamp __timestamp)) _timestamp)
  (:serialization-length
   ()
   (+
    ;; ist_slam_ros_msgs/StatusResponse _status
    (send _status :serialization-length)
    ;; ist_slam_ros_msgs/MetricFamily[] _metric_families
    (apply #'+ (send-all _metric_families :serialization-length)) 4
    ;; time _timestamp
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; ist_slam_ros_msgs/StatusResponse _status
       (send _status :serialize s)
     ;; ist_slam_ros_msgs/MetricFamily[] _metric_families
     (write-long (length _metric_families) s)
     (dolist (elem _metric_families)
       (send elem :serialize s)
       )
     ;; time _timestamp
       (write-long (send _timestamp :sec) s) (write-long (send _timestamp :nsec) s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; ist_slam_ros_msgs/StatusResponse _status
     (send _status :deserialize buf ptr-) (incf ptr- (send _status :serialization-length))
   ;; ist_slam_ros_msgs/MetricFamily[] _metric_families
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _metric_families (let (r) (dotimes (i n) (push (instance ist_slam_ros_msgs::MetricFamily :init) r)) r))
     (dolist (elem- _metric_families)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;; time _timestamp
     (send _timestamp :sec (sys::peek buf ptr- :integer)) (incf ptr- 4)  (send _timestamp :nsec (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(defclass ist_slam_ros_msgs::ReadMetrics
  :super ros::object
  :slots ())

(setf (get ist_slam_ros_msgs::ReadMetrics :md5sum-) "a1fe8d7dcf3708e96e015774b1df470e")
(setf (get ist_slam_ros_msgs::ReadMetrics :datatype-) "ist_slam_ros_msgs/ReadMetrics")
(setf (get ist_slam_ros_msgs::ReadMetrics :request) ist_slam_ros_msgs::ReadMetricsRequest)
(setf (get ist_slam_ros_msgs::ReadMetrics :response) ist_slam_ros_msgs::ReadMetricsResponse)

(defmethod ist_slam_ros_msgs::ReadMetricsRequest
  (:response () (instance ist_slam_ros_msgs::ReadMetricsResponse :init)))

(setf (get ist_slam_ros_msgs::ReadMetricsRequest :md5sum-) "a1fe8d7dcf3708e96e015774b1df470e")
(setf (get ist_slam_ros_msgs::ReadMetricsRequest :datatype-) "ist_slam_ros_msgs/ReadMetricsRequest")
(setf (get ist_slam_ros_msgs::ReadMetricsRequest :definition-)
      "
---
ist_slam_ros_msgs/StatusResponse status
ist_slam_ros_msgs/MetricFamily[] metric_families
time timestamp


================================================================================
MSG: ist_slam_ros_msgs/StatusResponse

# A common message type to indicate the outcome of a service call.
uint8 code
string message

================================================================================
MSG: ist_slam_ros_msgs/MetricFamily

string name
string description
ist_slam_ros_msgs/Metric[] metrics

================================================================================
MSG: ist_slam_ros_msgs/Metric

uint8 TYPE_COUNTER=0
uint8 TYPE_GAUGE=1
uint8 TYPE_HISTOGRAM=2

uint8 type
ist_slam_ros_msgs/MetricLabel[] labels

# TYPE_COUNTER or TYPE_GAUGE
float64 value

# TYPE_HISTOGRAM
ist_slam_ros_msgs/HistogramBucket[] counts_by_bucket

================================================================================
MSG: ist_slam_ros_msgs/MetricLabel

string key
string value

================================================================================
MSG: ist_slam_ros_msgs/HistogramBucket

# A histogram bucket counts values x for which:
#   previous_boundary < x <= bucket_boundary
# holds.
float64 bucket_boundary
float64 count
")

(setf (get ist_slam_ros_msgs::ReadMetricsResponse :md5sum-) "a1fe8d7dcf3708e96e015774b1df470e")
(setf (get ist_slam_ros_msgs::ReadMetricsResponse :datatype-) "ist_slam_ros_msgs/ReadMetricsResponse")
(setf (get ist_slam_ros_msgs::ReadMetricsResponse :definition-)
      "
---
ist_slam_ros_msgs/StatusResponse status
ist_slam_ros_msgs/MetricFamily[] metric_families
time timestamp


================================================================================
MSG: ist_slam_ros_msgs/StatusResponse

# A common message type to indicate the outcome of a service call.
uint8 code
string message

================================================================================
MSG: ist_slam_ros_msgs/MetricFamily

string name
string description
ist_slam_ros_msgs/Metric[] metrics

================================================================================
MSG: ist_slam_ros_msgs/Metric

uint8 TYPE_COUNTER=0
uint8 TYPE_GAUGE=1
uint8 TYPE_HISTOGRAM=2

uint8 type
ist_slam_ros_msgs/MetricLabel[] labels

# TYPE_COUNTER or TYPE_GAUGE
float64 value

# TYPE_HISTOGRAM
ist_slam_ros_msgs/HistogramBucket[] counts_by_bucket

================================================================================
MSG: ist_slam_ros_msgs/MetricLabel

string key
string value

================================================================================
MSG: ist_slam_ros_msgs/HistogramBucket

# A histogram bucket counts values x for which:
#   previous_boundary < x <= bucket_boundary
# holds.
float64 bucket_boundary
float64 count
")



(provide :ist_slam_ros_msgs/ReadMetrics "a1fe8d7dcf3708e96e015774b1df470e")



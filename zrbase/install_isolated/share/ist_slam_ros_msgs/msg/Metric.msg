
uint8 TYPE_COUNTER=0
uint8 TYPE_GAUGE=1
uint8 TYPE_HISTOGRAM=2

uint8 type
ist_slam_ros_msgs/MetricLabel[] labels

# TYPE_COUNTER or TYPE_GAUGE
float64 value

# TYPE_HISTOGRAM
ist_slam_ros_msgs/HistogramBucket[] counts_by_bucket

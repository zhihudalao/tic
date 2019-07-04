;; Auto-generated. Do not edit!


(when (boundp 'ist_building_msgs::ExtractAreaMapFromLabeledMap)
  (if (not (find-package "IST_BUILDING_MSGS"))
    (make-package "IST_BUILDING_MSGS"))
  (shadow 'ExtractAreaMapFromLabeledMap (find-package "IST_BUILDING_MSGS")))
(unless (find-package "IST_BUILDING_MSGS::EXTRACTAREAMAPFROMLABELEDMAP")
  (make-package "IST_BUILDING_MSGS::EXTRACTAREAMAPFROMLABELEDMAP"))
(unless (find-package "IST_BUILDING_MSGS::EXTRACTAREAMAPFROMLABELEDMAPREQUEST")
  (make-package "IST_BUILDING_MSGS::EXTRACTAREAMAPFROMLABELEDMAPREQUEST"))
(unless (find-package "IST_BUILDING_MSGS::EXTRACTAREAMAPFROMLABELEDMAPRESPONSE")
  (make-package "IST_BUILDING_MSGS::EXTRACTAREAMAPFROMLABELEDMAPRESPONSE"))

(in-package "ROS")

(if (not (find-package "SENSOR_MSGS"))
  (ros::roseus-add-msgs "sensor_msgs"))


(if (not (find-package "SENSOR_MSGS"))
  (ros::roseus-add-msgs "sensor_msgs"))


(defclass ist_building_msgs::ExtractAreaMapFromLabeledMapRequest
  :super ros::object
  :slots (_segmented_map _segment_of_interest ))

(defmethod ist_building_msgs::ExtractAreaMapFromLabeledMapRequest
  (:init
   (&key
    ((:segmented_map __segmented_map) (instance sensor_msgs::Image :init))
    ((:segment_of_interest __segment_of_interest) 0)
    )
   (send-super :init)
   (setq _segmented_map __segmented_map)
   (setq _segment_of_interest (round __segment_of_interest))
   self)
  (:segmented_map
   (&rest __segmented_map)
   (if (keywordp (car __segmented_map))
       (send* _segmented_map __segmented_map)
     (progn
       (if __segmented_map (setq _segmented_map (car __segmented_map)))
       _segmented_map)))
  (:segment_of_interest
   (&optional __segment_of_interest)
   (if __segment_of_interest (setq _segment_of_interest __segment_of_interest)) _segment_of_interest)
  (:serialization-length
   ()
   (+
    ;; sensor_msgs/Image _segmented_map
    (send _segmented_map :serialization-length)
    ;; int32 _segment_of_interest
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; sensor_msgs/Image _segmented_map
       (send _segmented_map :serialize s)
     ;; int32 _segment_of_interest
       (write-long _segment_of_interest s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; sensor_msgs/Image _segmented_map
     (send _segmented_map :deserialize buf ptr-) (incf ptr- (send _segmented_map :serialization-length))
   ;; int32 _segment_of_interest
     (setq _segment_of_interest (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(defclass ist_building_msgs::ExtractAreaMapFromLabeledMapResponse
  :super ros::object
  :slots (_segmented_area ))

(defmethod ist_building_msgs::ExtractAreaMapFromLabeledMapResponse
  (:init
   (&key
    ((:segmented_area __segmented_area) (instance sensor_msgs::Image :init))
    )
   (send-super :init)
   (setq _segmented_area __segmented_area)
   self)
  (:segmented_area
   (&rest __segmented_area)
   (if (keywordp (car __segmented_area))
       (send* _segmented_area __segmented_area)
     (progn
       (if __segmented_area (setq _segmented_area (car __segmented_area)))
       _segmented_area)))
  (:serialization-length
   ()
   (+
    ;; sensor_msgs/Image _segmented_area
    (send _segmented_area :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; sensor_msgs/Image _segmented_area
       (send _segmented_area :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; sensor_msgs/Image _segmented_area
     (send _segmented_area :deserialize buf ptr-) (incf ptr- (send _segmented_area :serialization-length))
   ;;
   self)
  )

(defclass ist_building_msgs::ExtractAreaMapFromLabeledMap
  :super ros::object
  :slots ())

(setf (get ist_building_msgs::ExtractAreaMapFromLabeledMap :md5sum-) "678bbdebce5d5e355861b28b37e6fe3c")
(setf (get ist_building_msgs::ExtractAreaMapFromLabeledMap :datatype-) "ist_building_msgs/ExtractAreaMapFromLabeledMap")
(setf (get ist_building_msgs::ExtractAreaMapFromLabeledMap :request) ist_building_msgs::ExtractAreaMapFromLabeledMapRequest)
(setf (get ist_building_msgs::ExtractAreaMapFromLabeledMap :response) ist_building_msgs::ExtractAreaMapFromLabeledMapResponse)

(defmethod ist_building_msgs::ExtractAreaMapFromLabeledMapRequest
  (:response () (instance ist_building_msgs::ExtractAreaMapFromLabeledMapResponse :init)))

(setf (get ist_building_msgs::ExtractAreaMapFromLabeledMapRequest :md5sum-) "678bbdebce5d5e355861b28b37e6fe3c")
(setf (get ist_building_msgs::ExtractAreaMapFromLabeledMapRequest :datatype-) "ist_building_msgs/ExtractAreaMapFromLabeledMapRequest")
(setf (get ist_building_msgs::ExtractAreaMapFromLabeledMapRequest :definition-)
      "




sensor_msgs/Image segmented_map

int32 segment_of_interest


================================================================================
MSG: sensor_msgs/Image
# This message contains an uncompressed image
# (0, 0) is at top-left corner of image
#

Header header        # Header timestamp should be acquisition time of image
                     # Header frame_id should be optical frame of camera
                     # origin of frame should be optical center of camera
                     # +x should point to the right in the image
                     # +y should point down in the image
                     # +z should point into to plane of the image
                     # If the frame_id here and the frame_id of the CameraInfo
                     # message associated with the image conflict
                     # the behavior is undefined

uint32 height         # image height, that is, number of rows
uint32 width          # image width, that is, number of columns

# The legal values for encoding are in file src/image_encodings.cpp
# If you want to standardize a new string format, join
# ros-users@lists.sourceforge.net and send an email proposing a new encoding.

string encoding       # Encoding of pixels -- channel meaning, ordering, size
                      # taken from the list of strings in include/sensor_msgs/image_encodings.h

uint8 is_bigendian    # is this data bigendian?
uint32 step           # Full row length in bytes
uint8[] data          # actual matrix data, size is (step * rows)

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
---

sensor_msgs/Image segmented_area



================================================================================
MSG: sensor_msgs/Image
# This message contains an uncompressed image
# (0, 0) is at top-left corner of image
#

Header header        # Header timestamp should be acquisition time of image
                     # Header frame_id should be optical frame of camera
                     # origin of frame should be optical center of camera
                     # +x should point to the right in the image
                     # +y should point down in the image
                     # +z should point into to plane of the image
                     # If the frame_id here and the frame_id of the CameraInfo
                     # message associated with the image conflict
                     # the behavior is undefined

uint32 height         # image height, that is, number of rows
uint32 width          # image width, that is, number of columns

# The legal values for encoding are in file src/image_encodings.cpp
# If you want to standardize a new string format, join
# ros-users@lists.sourceforge.net and send an email proposing a new encoding.

string encoding       # Encoding of pixels -- channel meaning, ordering, size
                      # taken from the list of strings in include/sensor_msgs/image_encodings.h

uint8 is_bigendian    # is this data bigendian?
uint32 step           # Full row length in bytes
uint8[] data          # actual matrix data, size is (step * rows)

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
")

(setf (get ist_building_msgs::ExtractAreaMapFromLabeledMapResponse :md5sum-) "678bbdebce5d5e355861b28b37e6fe3c")
(setf (get ist_building_msgs::ExtractAreaMapFromLabeledMapResponse :datatype-) "ist_building_msgs/ExtractAreaMapFromLabeledMapResponse")
(setf (get ist_building_msgs::ExtractAreaMapFromLabeledMapResponse :definition-)
      "




sensor_msgs/Image segmented_map

int32 segment_of_interest


================================================================================
MSG: sensor_msgs/Image
# This message contains an uncompressed image
# (0, 0) is at top-left corner of image
#

Header header        # Header timestamp should be acquisition time of image
                     # Header frame_id should be optical frame of camera
                     # origin of frame should be optical center of camera
                     # +x should point to the right in the image
                     # +y should point down in the image
                     # +z should point into to plane of the image
                     # If the frame_id here and the frame_id of the CameraInfo
                     # message associated with the image conflict
                     # the behavior is undefined

uint32 height         # image height, that is, number of rows
uint32 width          # image width, that is, number of columns

# The legal values for encoding are in file src/image_encodings.cpp
# If you want to standardize a new string format, join
# ros-users@lists.sourceforge.net and send an email proposing a new encoding.

string encoding       # Encoding of pixels -- channel meaning, ordering, size
                      # taken from the list of strings in include/sensor_msgs/image_encodings.h

uint8 is_bigendian    # is this data bigendian?
uint32 step           # Full row length in bytes
uint8[] data          # actual matrix data, size is (step * rows)

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
---

sensor_msgs/Image segmented_area



================================================================================
MSG: sensor_msgs/Image
# This message contains an uncompressed image
# (0, 0) is at top-left corner of image
#

Header header        # Header timestamp should be acquisition time of image
                     # Header frame_id should be optical frame of camera
                     # origin of frame should be optical center of camera
                     # +x should point to the right in the image
                     # +y should point down in the image
                     # +z should point into to plane of the image
                     # If the frame_id here and the frame_id of the CameraInfo
                     # message associated with the image conflict
                     # the behavior is undefined

uint32 height         # image height, that is, number of rows
uint32 width          # image width, that is, number of columns

# The legal values for encoding are in file src/image_encodings.cpp
# If you want to standardize a new string format, join
# ros-users@lists.sourceforge.net and send an email proposing a new encoding.

string encoding       # Encoding of pixels -- channel meaning, ordering, size
                      # taken from the list of strings in include/sensor_msgs/image_encodings.h

uint8 is_bigendian    # is this data bigendian?
uint32 step           # Full row length in bytes
uint8[] data          # actual matrix data, size is (step * rows)

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
")



(provide :ist_building_msgs/ExtractAreaMapFromLabeledMap "678bbdebce5d5e355861b28b37e6fe3c")



;; Auto-generated. Do not edit!


(when (boundp 'ist_building_msgs::FindRoomSequenceWithCheckpointsResult)
  (if (not (find-package "IST_BUILDING_MSGS"))
    (make-package "IST_BUILDING_MSGS"))
  (shadow 'FindRoomSequenceWithCheckpointsResult (find-package "IST_BUILDING_MSGS")))
(unless (find-package "IST_BUILDING_MSGS::FINDROOMSEQUENCEWITHCHECKPOINTSRESULT")
  (make-package "IST_BUILDING_MSGS::FINDROOMSEQUENCEWITHCHECKPOINTSRESULT"))

(in-package "ROS")
;;//! \htmlinclude FindRoomSequenceWithCheckpointsResult.msg.html
(if (not (find-package "SENSOR_MSGS"))
  (ros::roseus-add-msgs "sensor_msgs"))


(defclass ist_building_msgs::FindRoomSequenceWithCheckpointsResult
  :super ros::object
  :slots (_checkpoints _sequence_map ))

(defmethod ist_building_msgs::FindRoomSequenceWithCheckpointsResult
  (:init
   (&key
    ((:checkpoints __checkpoints) (let (r) (dotimes (i 0) (push (instance ist_building_msgs::RoomSequence :init) r)) r))
    ((:sequence_map __sequence_map) (instance sensor_msgs::Image :init))
    )
   (send-super :init)
   (setq _checkpoints __checkpoints)
   (setq _sequence_map __sequence_map)
   self)
  (:checkpoints
   (&rest __checkpoints)
   (if (keywordp (car __checkpoints))
       (send* _checkpoints __checkpoints)
     (progn
       (if __checkpoints (setq _checkpoints (car __checkpoints)))
       _checkpoints)))
  (:sequence_map
   (&rest __sequence_map)
   (if (keywordp (car __sequence_map))
       (send* _sequence_map __sequence_map)
     (progn
       (if __sequence_map (setq _sequence_map (car __sequence_map)))
       _sequence_map)))
  (:serialization-length
   ()
   (+
    ;; ist_building_msgs/RoomSequence[] _checkpoints
    (apply #'+ (send-all _checkpoints :serialization-length)) 4
    ;; sensor_msgs/Image _sequence_map
    (send _sequence_map :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; ist_building_msgs/RoomSequence[] _checkpoints
     (write-long (length _checkpoints) s)
     (dolist (elem _checkpoints)
       (send elem :serialize s)
       )
     ;; sensor_msgs/Image _sequence_map
       (send _sequence_map :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; ist_building_msgs/RoomSequence[] _checkpoints
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _checkpoints (let (r) (dotimes (i n) (push (instance ist_building_msgs::RoomSequence :init) r)) r))
     (dolist (elem- _checkpoints)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;; sensor_msgs/Image _sequence_map
     (send _sequence_map :deserialize buf ptr-) (incf ptr- (send _sequence_map :serialization-length))
   ;;
   self)
  )

(setf (get ist_building_msgs::FindRoomSequenceWithCheckpointsResult :md5sum-) "aed0112204502cd11e2b75f3bde2dcf7")
(setf (get ist_building_msgs::FindRoomSequenceWithCheckpointsResult :datatype-) "ist_building_msgs/FindRoomSequenceWithCheckpointsResult")
(setf (get ist_building_msgs::FindRoomSequenceWithCheckpointsResult :definition-)
      "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======

# result definition
ist_building_msgs/RoomSequence[] checkpoints			# sequence of checkpoints, should be ordered in optimized traveling salesman sequence
														# (checkpoint = a clique of rooms close [in terms of robot driving distance] to each other,
														#               and a central [in terms of rooms in the group] checkpoint location)
sensor_msgs/Image sequence_map							# map that has the calculated sequence drawn in

================================================================================
MSG: ist_building_msgs/RoomSequence
uint32[] room_indices		# indices of those rooms that belong to one group (connected to a checkpoint,
							# i.e. the clique of rooms close [in terms of robot driving distance] to each other),
							# indices should be ordered in optimized traveling salesman sequence
geometry_msgs/Point32 checkpoint_position_in_pixel			# provides the (x,y)-coordinates of the checkpoint location for this group of rooms [in pixel]
geometry_msgs/Point32 checkpoint_position_in_meter			# provides the (x,y)-coordinates of the checkpoint location for this group of rooms [in meter]
================================================================================
MSG: geometry_msgs/Point32
# This contains the position of a point in free space(with 32 bits of precision).
# It is recommeded to use Point wherever possible instead of Point32.  
# 
# This recommendation is to promote interoperability.  
#
# This message is designed to take up less space when sending
# lots of points at once, as in the case of a PointCloud.  

float32 x
float32 y
float32 z
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



(provide :ist_building_msgs/FindRoomSequenceWithCheckpointsResult "aed0112204502cd11e2b75f3bde2dcf7")



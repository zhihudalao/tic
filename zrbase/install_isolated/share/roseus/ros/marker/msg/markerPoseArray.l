;; Auto-generated. Do not edit!


(when (boundp 'marker::markerPoseArray)
  (if (not (find-package "MARKER"))
    (make-package "MARKER"))
  (shadow 'markerPoseArray (find-package "MARKER")))
(unless (find-package "MARKER::MARKERPOSEARRAY")
  (make-package "MARKER::MARKERPOSEARRAY"))

(in-package "ROS")
;;//! \htmlinclude markerPoseArray.msg.html


(defclass marker::markerPoseArray
  :super ros::object
  :slots (_markers ))

(defmethod marker::markerPoseArray
  (:init
   (&key
    ((:markers __markers) (let (r) (dotimes (i 0) (push (instance marker::markerPose :init) r)) r))
    )
   (send-super :init)
   (setq _markers __markers)
   self)
  (:markers
   (&rest __markers)
   (if (keywordp (car __markers))
       (send* _markers __markers)
     (progn
       (if __markers (setq _markers (car __markers)))
       _markers)))
  (:serialization-length
   ()
   (+
    ;; marker/markerPose[] _markers
    (apply #'+ (send-all _markers :serialization-length)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; marker/markerPose[] _markers
     (write-long (length _markers) s)
     (dolist (elem _markers)
       (send elem :serialize s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; marker/markerPose[] _markers
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _markers (let (r) (dotimes (i n) (push (instance marker::markerPose :init) r)) r))
     (dolist (elem- _markers)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;;
   self)
  )

(setf (get marker::markerPoseArray :md5sum-) "c5f6d3ea5a86708d66e8b0f23988b7f6")
(setf (get marker::markerPoseArray :datatype-) "marker/markerPoseArray")
(setf (get marker::markerPoseArray :definition-)
      "marker/markerPose[] markers
================================================================================
MSG: marker/markerPose
string name
geometry_msgs/Pose pose
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



(provide :marker/markerPoseArray "c5f6d3ea5a86708d66e8b0f23988b7f6")



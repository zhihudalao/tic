;; Auto-generated. Do not edit!


(when (boundp 'speed_param::speed)
  (if (not (find-package "SPEED_PARAM"))
    (make-package "SPEED_PARAM"))
  (shadow 'speed (find-package "SPEED_PARAM")))
(unless (find-package "SPEED_PARAM::SPEED")
  (make-package "SPEED_PARAM::SPEED"))

(in-package "ROS")
;;//! \htmlinclude speed.msg.html


(defclass speed_param::speed
  :super ros::object
  :slots (_line _angular ))

(defmethod speed_param::speed
  (:init
   (&key
    ((:line __line) 0.0)
    ((:angular __angular) 0.0)
    )
   (send-super :init)
   (setq _line (float __line))
   (setq _angular (float __angular))
   self)
  (:line
   (&optional __line)
   (if __line (setq _line __line)) _line)
  (:angular
   (&optional __angular)
   (if __angular (setq _angular __angular)) _angular)
  (:serialization-length
   ()
   (+
    ;; float32 _line
    4
    ;; float32 _angular
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _line
       (sys::poke _line (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _angular
       (sys::poke _angular (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _line
     (setq _line (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _angular
     (setq _angular (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get speed_param::speed :md5sum-) "06684d5be7e1ff5a383443515a74e02c")
(setf (get speed_param::speed :datatype-) "speed_param/speed")
(setf (get speed_param::speed :definition-)
      "float32 line
float32 angular
")



(provide :speed_param/speed "06684d5be7e1ff5a383443515a74e02c")



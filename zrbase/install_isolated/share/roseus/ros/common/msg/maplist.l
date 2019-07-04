;; Auto-generated. Do not edit!


(when (boundp 'common::maplist)
  (if (not (find-package "COMMON"))
    (make-package "COMMON"))
  (shadow 'maplist (find-package "COMMON")))
(unless (find-package "COMMON::MAPLIST")
  (make-package "COMMON::MAPLIST"))

(in-package "ROS")
;;//! \htmlinclude maplist.msg.html


(defclass common::maplist
  :super ros::object
  :slots (_maplist ))

(defmethod common::maplist
  (:init
   (&key
    ((:maplist __maplist) (let (r) (dotimes (i 0) (push "" r)) r))
    )
   (send-super :init)
   (setq _maplist __maplist)
   self)
  (:maplist
   (&optional __maplist)
   (if __maplist (setq _maplist __maplist)) _maplist)
  (:serialization-length
   ()
   (+
    ;; string[] _maplist
    (apply #'+ (mapcar #'(lambda (x) (+ 4 (length x))) _maplist)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string[] _maplist
     (write-long (length _maplist) s)
     (dolist (elem _maplist)
       (write-long (length elem) s) (princ elem s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string[] _maplist
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _maplist (make-list n))
     (dotimes (i n)
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setf (elt _maplist i) (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
     ))
   ;;
   self)
  )

(setf (get common::maplist :md5sum-) "2f17be7ef84382701baab17066775a33")
(setf (get common::maplist :datatype-) "common/maplist")
(setf (get common::maplist :definition-)
      "string[] maplist
")



(provide :common/maplist "2f17be7ef84382701baab17066775a33")



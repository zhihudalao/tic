;; Auto-generated. Do not edit!


(when (boundp 'ist_tools::check_msgResult)
  (if (not (find-package "IST_TOOLS"))
    (make-package "IST_TOOLS"))
  (shadow 'check_msgResult (find-package "IST_TOOLS")))
(unless (find-package "IST_TOOLS::CHECK_MSGRESULT")
  (make-package "IST_TOOLS::CHECK_MSGRESULT"))

(in-package "ROS")
;;//! \htmlinclude check_msgResult.msg.html


(defclass ist_tools::check_msgResult
  :super ros::object
  :slots (_issuccess ))

(defmethod ist_tools::check_msgResult
  (:init
   (&key
    ((:issuccess __issuccess) nil)
    )
   (send-super :init)
   (setq _issuccess __issuccess)
   self)
  (:issuccess
   (&optional __issuccess)
   (if __issuccess (setq _issuccess __issuccess)) _issuccess)
  (:serialization-length
   ()
   (+
    ;; bool _issuccess
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _issuccess
       (if _issuccess (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _issuccess
     (setq _issuccess (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(setf (get ist_tools::check_msgResult :md5sum-) "e40869114e279d3e4fa137fdad5acd7d")
(setf (get ist_tools::check_msgResult :datatype-) "ist_tools/check_msgResult")
(setf (get ist_tools::check_msgResult :definition-)
      "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======
#result definition
bool issuccess

")



(provide :ist_tools/check_msgResult "e40869114e279d3e4fa137fdad5acd7d")



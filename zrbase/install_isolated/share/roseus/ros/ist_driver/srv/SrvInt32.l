;; Auto-generated. Do not edit!


(when (boundp 'ist_driver::SrvInt32)
  (if (not (find-package "IST_DRIVER"))
    (make-package "IST_DRIVER"))
  (shadow 'SrvInt32 (find-package "IST_DRIVER")))
(unless (find-package "IST_DRIVER::SRVINT32")
  (make-package "IST_DRIVER::SRVINT32"))
(unless (find-package "IST_DRIVER::SRVINT32REQUEST")
  (make-package "IST_DRIVER::SRVINT32REQUEST"))
(unless (find-package "IST_DRIVER::SRVINT32RESPONSE")
  (make-package "IST_DRIVER::SRVINT32RESPONSE"))

(in-package "ROS")





(defclass ist_driver::SrvInt32Request
  :super ros::object
  :slots (_arg1 ))

(defmethod ist_driver::SrvInt32Request
  (:init
   (&key
    ((:arg1 __arg1) 0)
    )
   (send-super :init)
   (setq _arg1 (round __arg1))
   self)
  (:arg1
   (&optional __arg1)
   (if __arg1 (setq _arg1 __arg1)) _arg1)
  (:serialization-length
   ()
   (+
    ;; int32 _arg1
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _arg1
       (write-long _arg1 s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _arg1
     (setq _arg1 (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(defclass ist_driver::SrvInt32Response
  :super ros::object
  :slots (_val ))

(defmethod ist_driver::SrvInt32Response
  (:init
   (&key
    ((:val __val) 0)
    )
   (send-super :init)
   (setq _val (round __val))
   self)
  (:val
   (&optional __val)
   (if __val (setq _val __val)) _val)
  (:serialization-length
   ()
   (+
    ;; int32 _val
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _val
       (write-long _val s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _val
     (setq _val (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(defclass ist_driver::SrvInt32
  :super ros::object
  :slots ())

(setf (get ist_driver::SrvInt32 :md5sum-) "6cd15d79626e4186c53fc1d4dab3625b")
(setf (get ist_driver::SrvInt32 :datatype-) "ist_driver/SrvInt32")
(setf (get ist_driver::SrvInt32 :request) ist_driver::SrvInt32Request)
(setf (get ist_driver::SrvInt32 :response) ist_driver::SrvInt32Response)

(defmethod ist_driver::SrvInt32Request
  (:response () (instance ist_driver::SrvInt32Response :init)))

(setf (get ist_driver::SrvInt32Request :md5sum-) "6cd15d79626e4186c53fc1d4dab3625b")
(setf (get ist_driver::SrvInt32Request :datatype-) "ist_driver/SrvInt32Request")
(setf (get ist_driver::SrvInt32Request :definition-)
      "int32 arg1
---
int32 val


")

(setf (get ist_driver::SrvInt32Response :md5sum-) "6cd15d79626e4186c53fc1d4dab3625b")
(setf (get ist_driver::SrvInt32Response :datatype-) "ist_driver/SrvInt32Response")
(setf (get ist_driver::SrvInt32Response :definition-)
      "int32 arg1
---
int32 val


")



(provide :ist_driver/SrvInt32 "6cd15d79626e4186c53fc1d4dab3625b")



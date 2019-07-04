;; Auto-generated. Do not edit!


(when (boundp 'auto_charge::ir)
  (if (not (find-package "AUTO_CHARGE"))
    (make-package "AUTO_CHARGE"))
  (shadow 'ir (find-package "AUTO_CHARGE")))
(unless (find-package "AUTO_CHARGE::IR")
  (make-package "AUTO_CHARGE::IR"))

(in-package "ROS")
;;//! \htmlinclude ir.msg.html


(defclass auto_charge::ir
  :super ros::object
  :slots (_ir_data _ir_charging ))

(defmethod auto_charge::ir
  (:init
   (&key
    ((:ir_data __ir_data) "")
    ((:ir_charging __ir_charging) nil)
    )
   (send-super :init)
   (setq _ir_data (string __ir_data))
   (setq _ir_charging __ir_charging)
   self)
  (:ir_data
   (&optional __ir_data)
   (if __ir_data (setq _ir_data __ir_data)) _ir_data)
  (:ir_charging
   (&optional __ir_charging)
   (if __ir_charging (setq _ir_charging __ir_charging)) _ir_charging)
  (:serialization-length
   ()
   (+
    ;; string _ir_data
    4 (length _ir_data)
    ;; bool _ir_charging
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _ir_data
       (write-long (length _ir_data) s) (princ _ir_data s)
     ;; bool _ir_charging
       (if _ir_charging (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _ir_data
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _ir_data (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; bool _ir_charging
     (setq _ir_charging (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(setf (get auto_charge::ir :md5sum-) "9e4e7b7ff71e150dd913663f82725e90")
(setf (get auto_charge::ir :datatype-) "auto_charge/ir")
(setf (get auto_charge::ir :definition-)
      "string ir_data
bool ir_charging
")



(provide :auto_charge/ir "9e4e7b7ff71e150dd913663f82725e90")



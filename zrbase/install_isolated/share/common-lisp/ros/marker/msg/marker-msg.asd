
(cl:in-package :asdf)

(defsystem "marker-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :geometry_msgs-msg
)
  :components ((:file "_package")
    (:file "markerPose" :depends-on ("_package_markerPose"))
    (:file "_package_markerPose" :depends-on ("_package"))
    (:file "markerPoseArray" :depends-on ("_package_markerPoseArray"))
    (:file "_package_markerPoseArray" :depends-on ("_package"))
  ))
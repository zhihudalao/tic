
(cl:in-package :asdf)

(defsystem "auto_charge-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "ir" :depends-on ("_package_ir"))
    (:file "_package_ir" :depends-on ("_package"))
  ))
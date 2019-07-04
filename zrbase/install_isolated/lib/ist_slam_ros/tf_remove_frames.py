#!/usr/bin/python
# -*- coding: utf-8 -*-


import rospy
from tf.msg import tfMessage


def main():
  rospy.init_node('tf_remove_frames')
  publisher = rospy.Publisher('/tf_out', tfMessage, queue_size=1)
  remove_frames = rospy.get_param('~remove_frames', [])

  def callback(msg):
    msg.transforms = [
        t for t in msg.transforms
        if t.header.frame_id.lstrip('/') not in remove_frames and
        t.child_frame_id.lstrip('/') not in remove_frames
    ]
    publisher.publish(msg)

  rospy.Subscriber('/tf_in', tfMessage, callback)
  rospy.spin()


if __name__ == '__main__':
  main()

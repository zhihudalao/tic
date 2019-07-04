#!/usr/bin/env python

""" move_base_square.py - Version 1.1 2013-12-20

    Command a robot to move in a square using move_base actions..

    Created for the Pi Robot Project: http://www.pirobot.org
    Copyright (c) 2012 Patrick Goebel.  All rights reserved.

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.5
    
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details at:
    
    http://www.gnu.org/licenses/gpl.htmlPoint
      
"""

import rospy

import math
import tf
from geometry_msgs.msg import PoseWithCovarianceStamped,PoseStamped
from geometry_msgs.msg import Pose, Point, Quaternion, Twist

class TestRobotPose():
    def __init__(self):
        rospy.init_node('test_robotpose', anonymous=False)
        
        rospy.loginfo("start test robot pose...")

        #self.setpose_pub = rospy.Publisher("initialpose",PoseWithCovarianceStamped,tcp_nodelay=True,latch=True, queue_size=1)

        self.setpose_pub = rospy.Publisher("robot_pose", Pose,
                                           queue_size=5)

        self.set_pose = {'x':0.68,'y':-4.63,'a':1.0}
        self.test_set_pose_flag = True
        self.test_set_pose_cnt = 50
        self.set_robot_pose()

        while self.test_set_pose_flag == True:

            self.set_robot_pose()
            self.test_set_pose_cnt -= 1
            if self.test_set_pose_cnt == 0:
                self.test_set_pose_flag = False


    def set_robot_pose(self):
        # Define a set inital pose publisher.
        rospy.loginfo("start set robot pose...")
        p = Pose()
        p.position.x = self.set_pose['x']
        p.position.y = self.set_pose['y']
        p.position.z = 0.0
        (p.orientation.x,
         p.orientation.y,
         p.orientation.z,
         p.orientation.w) = tf.transformations.quaternion_from_euler(0, 0, self.set_pose['a'])
        self.setpose_pub.publish(p)
        rospy.loginfo(" stop test robot pose...")

        br = tf.TransformBroadcaster()

        br.sendTransform((p.position.x, p.position.y, p.position.z),
                         tf.transformations.quaternion_from_euler(0, 0, p.position.z),
                         rospy.Time.now(),
                         "odom",
                         "map")


if __name__ == '__main__':
    try:
        TestRobotPose()
    except rospy.ROSInterruptException:
        rospy.loginfo("robot pose test finished.")

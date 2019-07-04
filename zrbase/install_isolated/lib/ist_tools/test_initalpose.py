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
import roslib
import math
import tf
from geometry_msgs.msg import PoseWithCovarianceStamped
from geometry_msgs.msg import Pose, Point, Quaternion, Twist

class TestInitalPose():
    def __init__(self):
        rospy.init_node('test_initalpose', anonymous=False)
        
        rospy.loginfo("start test inital pose...")

        self.setpose_pub = rospy.Publisher("initialpose",PoseWithCovarianceStamped,latch=True, queue_size=1)

        #self.setpose_pub = rospy.Publisher("initialpose", PoseWithCovarianceStamped,queue_size=10)

        self.set_pose = {'x':-4.68,'y':-4.63,'a':1.0}
        self.test_set_pose_flag = True
        self.test_set_pose_cnt = 3
        #self.set_inital_pose()


        while self.test_set_pose_flag == True:

            self.set_inital_pose()
            self.test_set_pose_cnt -= 1
            if self.test_set_pose_cnt == 0:
                self.test_set_pose_flag = False
        rospy.sleep(1)

    def set_inital_pose(self):
        # Define a set inital pose publisher.
        rospy.loginfo("start set pose...")
        p = PoseWithCovarianceStamped()
        p.header.stamp = rospy.Time.now()
        p.header.frame_id = "map"
        p.pose.pose.position.x = self.set_pose['x']
        p.pose.pose.position.y = self.set_pose['y']
        p.pose.pose.position.z = self.set_pose['a']
        (p.pose.pose.orientation.x,
         p.pose.pose.orientation.y,
         p.pose.pose.orientation.z,
         p.pose.pose.orientation.w) = tf.transformations.quaternion_from_euler(0, 0, self.set_pose['a'])
        p.pose.covariance[6 * 0 + 0] = 0.5 * 0.5
        p.pose.covariance[6 * 1 + 1] = 0.5 * 0.5
        p.pose.covariance[6 * 3 + 3] = math.pi / 12.0 * math.pi / 12.0

        self.setpose_pub.publish(p)

        '''
        br = tf.TransformBroadcaster()

        br.sendTransform((p.pose.pose.position.x, p.pose.pose.position.y, p.pose.pose.position.z),
                         tf.transformations.quaternion_from_euler(0, 0, p.pose.pose.position.z),
                         rospy.Time.now(),
                         "odom",
                         "map")
        '''
        rospy.loginfo(" stop test inital pose...")



if __name__ == '__main__':
    try:
        TestInitalPose()
    except rospy.ROSInterruptException:
        rospy.loginfo("inital pose test finished.")

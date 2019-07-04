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
from tf import transformations
from geometry_msgs.msg import PoseWithCovarianceStamped
from geometry_msgs.msg import Pose, Point, Quaternion, Twist

class TestAmclPose():
    def __init__(self):
        rospy.init_node('test_amclpose', anonymous=False)
        
        rospy.loginfo("start test amcl pose...")

        #self.setpose_pub = rospy.Publisher("initialpose",PoseWithCovarianceStamped,tcp_nodelay=True,latch=True, queue_size=1)

        self.setpose_pub = rospy.Publisher("amcl_pose", PoseWithCovarianceStamped,
                                           queue_size=5)

        self.set_pose = {'x':0.68,'y':-4.63,'a':1.0}
        self.test_set_pose_flag = True
        self.test_set_pose_cnt = 50
        self.set_amcl_pose()

        while self.test_set_pose_flag == True:

            self.set_amcl_pose()
            self.test_set_pose_cnt -= 1
            if self.test_set_pose_cnt == 0:
                self.test_set_pose_flag = False


    def set_amcl_pose(self):
        # Define a set inital pose publisher.
        rospy.loginfo("start set amcl pose...")
        p = PoseWithCovarianceStamped()
        p.header.stamp = rospy.Time.now()
        p.header.frame_id = "map"
        p.pose.pose.position.x = self.set_pose['x']
        p.pose.pose.position.y = self.set_pose['y']
        (p.pose.pose.orientation.x,
         p.pose.pose.orientation.y,
         p.pose.pose.orientation.z,
         p.pose.pose.orientation.w) = transformations.quaternion_from_euler(0, 0, self.set_pose['a'])
        p.pose.covariance[6 * 0 + 0] = 0.5 * 0.5
        p.pose.covariance[6 * 1 + 1] = 0.5 * 0.5
        p.pose.covariance[6 * 3 + 3] = math.pi / 12.0 * math.pi / 12.0

        self.setpose_pub.publish(p)
        rospy.loginfo(" stop test amcl pose...")



if __name__ == '__main__':
    try:
        TestAmclPose()
    except rospy.ROSInterruptException:
        rospy.loginfo("amcl pose test finished.")

#!/usr/bin/env python

import rospy  
 
from sensor_msgs.msg import Joy  
from geometry_msgs.msg import Twist  
from std_msgs.msg import String  
 
class Teleop:  
    def __init__(self):  
        rospy.init_node('key_joy', log_level=rospy.DEBUG)  
 
        self.turn_scale = 0.2
        self.drive_scale = 0.2  
        self.deadman_button = 1
 
        self.cmd = None  
        cmd_pub = rospy.Publisher('cmd_vel', Twist) 
 
       # announce_pub = rospy.Publisher(&#39;/smartcar/announce/teleops&#39;,  
       #                            String, latch=True)  
       # announce_pub.publish(rospy.get_namespace());  
 
        rospy.Subscriber("joy", Joy, self.callback)  
        rate = rospy.Rate(20)  
 
        while not rospy.is_shutdown():  
            rate.sleep()  
            if self.cmd:  
                cmd_pub.publish(self.cmd)  
 
    def callback(self, data):  
        """ Receive joystick data, formulate Twist message. """  
        cmd = Twist()  
        cmd.linear.x = data.axes[1] * self.drive_scale  
        cmd.angular.z = data.axes[0] * self.turn_scale  
 
        if data.buttons[self.deadman_button] == 1:  
            self.cmd = cmd  
        else:  
            self.cmd = None  
 
if __name__ == "__main__": Teleop()

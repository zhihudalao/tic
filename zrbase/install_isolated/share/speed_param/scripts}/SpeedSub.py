#!/usr/bin/env python
# coding=utf-8

import rospy
# from std_srvs.srv import Empty
from speed_param.msg import speed


def callback(req):
    if req.line > 0:
        rospy.set_param('/move_base/TebLocalPlannerROS/max_vel_x', req.line)
    else:
        print 'line 参数无效或没有传'
    if req.angular > 0:
        rospy.set_param('/move_base/TebLocalPlannerROS/acc_lim_x', req.angular)
    else:
        print 'angular 参数无效或没有传'


def listener():
    rospy.init_node('speed_sub', anonymous=True)
    rospy.Subscriber('speed_sub', speed, callback)
    print("开始监听 speed_sub")
    rospy.spin()


if __name__ == '__main__':
    listener()

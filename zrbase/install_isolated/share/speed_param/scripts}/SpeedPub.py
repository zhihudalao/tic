#!/usr/bin/env python
# coding=utf-8

import rospy
from speed_param.msg import speed

def publish():
    rospy.init_node('speed_pub', anonymous=True)
    pub = rospy.Publisher('speed_pub', speed, queue_size=10)
    rate = rospy.Rate(1)  # 10hz
    while not rospy.is_shutdown():
        spd = speed()
        spd.angular = rospy.get_param('/move_base/TebLocalPlannerROS/acc_lim_x')
        spd.line = rospy.get_param('/move_base/TebLocalPlannerROS/max_vel_x')
        pub.publish(spd)
        rate.sleep()

if __name__ == '__main__':
    try:
        print("开始发布 speed_pub")
        publish()
    except rospy.ROSInterruptException:
        pass

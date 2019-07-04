#!/bin/bash

log_file=/tmp/dashgo.log
DATE=`date`

source /opt/ros/indigo/setup.bash
source /home/eaibot/dashgo_ws/devel/setup.bash

interface=eth0
echo "$DATE: dashgo-start on interface $interface" >> $log_file

export ROS_IP=`ifconfig $interface | grep -o 'inet addr:[^ ]*' | cut -d: -f2`

echo "$DATE: dashgo-start setting ROS_IP=$ROS_IP" >> $log_file

if [ "$ROS_IP" = "" ]; then
    echo "$DATE: dashgo-start can't run with empty ROS_IP." >> $log_file
    exit 1
fi

roslaunch dashgo_nav gmapping_demo_imu.launch

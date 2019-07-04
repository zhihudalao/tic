#!/bin/bash
ProgName="navigation_demo_imu.launch"
num=$(ps aux|grep ${ProgName} |grep -v grep|wc -l)

if [ $num -gt 0 ] 
then 
   echo "${ProgName} has been launched!"
else
   /home/eaibot/dashgo_ws/src/dashgo/ist_tools/startup/navigation-start-fg.sh>/dev/null 2>&1 &
   echo "${ProgName} is starting"
fi

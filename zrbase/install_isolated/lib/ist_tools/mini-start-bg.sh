#!/bin/bash
num=$(ps aux|grep minimal.launch |grep -v grep|wc -l)

if [ $num -gt 0 ] 
then 
   echo "minimal.launch  has been launched!"
else
   /home/eaibot/dashgo_ws/src/dashgo/ist_tools/startup/mini-start-fg.sh>/dev/null 2>&1 &
   echo "minimal.launch is starting"
fi

#! /bin/bash

#mapFilename = "$1" 
rosnode kill /ist_slam_node &
rosnode kill /ist_slam_occupancy_grid_node &
kill -9 `pgrep -f map_sever`&
kill -9 `pgrep -f amcl`&
sleep 0.5
roslaunch ist_nav  amcl_test.launch  &
rosrun map_server map_server /root/tic_map/$1/$1.yaml &


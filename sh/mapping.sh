#!/bin/bash

kill -9 `pgrep -f map_sever` &
sleep 1
roslaunch ist_slam_ros ist_slam_create_map.launch &


#! /bin/bash

sleep 1
roslaunch sick_tim sick_tim571_2050101.launch &
sleep 1
roslaunch ist_driver driver_imu.launch &
sleep 1
roslaunch ist_description ist_description.launch &






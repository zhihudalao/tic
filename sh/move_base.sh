#! /bin/bash

rosnode kill /rviz &
rosnode kill /cartographer_node &
rosnode kill /cartographer_occupancy_grid_node &
rosnode kill /robot_pose_publisher &
rosnode kill /teleop_twist_keyboard &
rosnode kill /ist_slam_node &
rosnode kill /ist_slam_occupancy_grid_node &
sleep 1

roslaunch ist_nav  navigation_robot_desc.launch &


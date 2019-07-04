#!/usr/bin/env python

import commands
import sys
import os
import roslaunch
from time import sleep
import signal
from functools import partial
import time
import threading
import thread
from threading import Thread
from os.path import join, getsize
import rospy
from std_msgs.msg import String

bag_dir = '/root/bag'
x_topics = '"/tf|/tf_static|/odom|/odom_filtered|/check |/check_server| /cancel|/check_server/feedback|/check_server/goal|/check_server/result|/check_server/status|/client_count|/cmd_vel \
/diagnostics \
/emergencybt_status \
/imu \
/imu_angle \
/imu_data \
/initialpose \
/is_passed \
/is_passed_2 \
/joint_states \
/nodelet_manager/bond \
/robot_cmd_vel \
/robot_pose_ekf/odom_combined \
/rosout \
/rosout_agg \
/save_map \
/scan \
/sick_tim571_2050101/parameter_descriptions \
/sick_tim571_2050101/parameter_updates \
/smoother_cmd_vel \
/velocity_smoother/parameter_descriptions \
/velocity_smoother/parameter_updates \
/wash \
/amcl/parameter_descriptions \
/amcl/parameter_updates \
/amcl_pose \
/map \
/map_metadata \
/move_base/DWAPlannerROS/cost_cloud \
/move_base/DWAPlannerROS/global_plan \
/move_base/DWAPlannerROS/local_plan \
/move_base/DWAPlannerROS/parameter_descriptions \
/move_base/DWAPlannerROS/parameter_updates \
/move_base/DWAPlannerROS/trajectory_cloud \
/move_base/GlobalPlanner/parameter_descriptions \
/move_base/GlobalPlanner/parameter_updates \
/move_base/GlobalPlanner/plan \
/move_base/GlobalPlanner/potential \
/move_base/cancel \
/move_base/current_goal \
/move_base/feedback \
/move_base/global_costmap/costmap \
/move_base/global_costmap/costmap_updates \
/move_base/global_costmap/footprint \
/move_base/global_costmap/inflation_layer/parameter_descriptions \
/move_base/global_costmap/inflation_layer/parameter_updates \
/move_base/global_costmap/obstacle_layer/parameter_descriptions \
/move_base/global_costmap/obstacle_layer/parameter_updates \
/move_base/global_costmap/parameter_descriptions \
/move_base/global_costmap/parameter_updates \
/move_base/global_costmap/static_layer/parameter_descriptions \
/move_base/global_costmap/static_layer/parameter_updates \
/move_base/goal \
/move_base/local_costmap/costmap \
/move_base/local_costmap/costmap_updates \
/move_base/local_costmap/footprint \
/move_base/local_costmap/inflation_layer/parameter_descriptions \
/move_base/local_costmap/inflation_layer/parameter_updates \
/move_base/local_costmap/obstacle_layer/clearing_endpoints \
/move_base/local_costmap/obstacle_layer/parameter_descriptions \
/move_base/local_costmap/obstacle_layer/parameter_updates \
/move_base/local_costmap/obstacle_layer/voxel_grid \
/move_base/local_costmap/parameter_descriptions \
/move_base/local_costmap/parameter_updates \
/move_base/local_costmap/static_layer/parameter_descriptions \
/move_base/local_costmap/static_layer/parameter_updates \
/move_base/parameter_descriptions \
/move_base/parameter_updates \
/move_base/result \
/move_base/status \
/move_base_simple/goal \
/mplan \
/MappingOrNavi \
/PathRecordOrPlay \
/PauseTask"'


max_sum_bag_size = 6 * 1024
max_per_bag_size = '200'

if not os.path.exists(bag_dir):
	os.makedirs(bag_dir)

def getDirSize(dir):
	size = 0.0 
	for root, dirs, files in os.walk(dir):
		for name in files: 
			name_arr = name.split('.')
			size += getsize(join(root, name))
			# if name_arr[len(name_arr) - 1] != 'active':
			# 	size += getsize(join(root, name))
	return size/1024/1024

def freeDist():
	oldest_time = time.localtime(time.time())
	oldest_file_name = ''
	for parent,dirnames,filenames in os.walk(bag_dir):
		for filename in filenames:
			temp_path = os.path.join(parent,filename)
			filename_arr = filename.split('.')
			if filename_arr[len(filename_arr) - 1] == 'bag' or filename_arr[len(filename_arr) - 1] == 'active':
				stats = os.stat(temp_path)
				lastmodDate = time.localtime(stats[8])
				if oldest_time > lastmodDate:
					oldest_time = lastmodDate
					oldest_file_name = temp_path
	if oldest_file_name != '':
		commands.getstatusoutput('rm ' + oldest_file_name)

def dfCheckThread():
	t = threading.currentThread()
	t.do_run = True
	while t.do_run:
		while 1:
			parent_dir_size = getDirSize(bag_dir)
			if parent_dir_size > max_sum_bag_size:
				freeDist()
			else:
				break
		sleep(5)

def getCurrentTime():
	timenow = time.localtime(time.time())
	timeformat = """%d-%d-%d-%d-%d-%d""" \
	%(timenow.tm_year, timenow.tm_mon, timenow.tm_mday, timenow.tm_hour, timenow.tm_min, timenow.tm_sec)
	return timeformat

global process

def startRosbagRecord():
	global process
	current_time = getCurrentTime();
	aim_path = bag_dir + "/" + current_time;
	launch = roslaunch.scriptapi.ROSLaunch()
	launch.start()
	if x_topics == '':
		node = roslaunch.core.Node('rosbag', 'record', args = '-a -j --split --size=' + max_per_bag_size +' -O ' + aim_path)
	else:
		node = roslaunch.core.Node('rosbag', 'record', args = '-a -j -x ' + x_topics + ' --split --size=' + max_per_bag_size +' -O ' + aim_path)
	process = launch.launch(node)

def handleRosbagRecordCallback(data):
	global process
	if data.data == "start":
		if not process.is_alive():
			startRosbagRecord();
	if data.data == "stop":
		if process.is_alive():
			process.stop();

def sigintHandler(df_check, signum, frame):
	global process
	if process.is_alive():
		process.stop()
	df_check.do_run = False
	df_check.join()
	exit()

if __name__ == "__main__":
	rospy.init_node('rosbag_recorder')
	df_check = Thread(target = dfCheckThread)
	df_check.start()
	startRosbagRecord();
	signal.signal(signal.SIGINT, partial(sigintHandler, df_check))
	signal.signal(signal.SIGTERM, partial(sigintHandler, df_check))
	rospy.Subscriber("handle_rosbag_record", String, handleRosbagRecordCallback)
	rospy.spin()



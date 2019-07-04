/*
 * Copyright 2016 The ist_slam Authors
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef IST_SLAM_ROS_IST_SLAM_ROS_TRAJECTORY_OPTIONS_H
#define IST_SLAM_ROS_IST_SLAM_ROS_TRAJECTORY_OPTIONS_H

#include <string>

#include "ist_slam/common/lua_parameter_dictionary.h"
#include "ist_slam/common/port.h"
#include "ist_slam/mapping/proto/trajectory_builder_options.pb.h"
#include "ist_slam_ros_msgs/TrajectoryOptions.h"

namespace ist_slam_ros {

struct TrajectoryOptions {
  ::ist_slam::mapping::proto::TrajectoryBuilderOptions
      trajectory_builder_options;
  std::string tracking_frame;
  std::string published_frame;
  std::string odom_frame;
  bool provide_odom_frame;
  bool use_odometry;
  bool use_nav_sat;
  bool use_landmarks;
  bool publish_frame_projected_to_2d;
  int num_laser_scans;
  int num_multi_echo_laser_scans;
  int num_subdivisions_per_laser_scan;
  int num_point_clouds;
  double rangefinder_sampling_ratio;
  double odometry_sampling_ratio;
  double fixed_frame_pose_sampling_ratio;
  double imu_sampling_ratio;
  double landmarks_sampling_ratio;
};

::ist_slam::mapping::proto::InitialTrajectoryPose
CreateInitialTrajectoryPose(
    ::ist_slam::common::LuaParameterDictionary* lua_parameter_dictionary);

TrajectoryOptions CreateTrajectoryOptions(
    ::ist_slam::common::LuaParameterDictionary* lua_parameter_dictionary);

TrajectoryOptions CreateTrajectoryOptions(
    ::ist_slam::common::LuaParameterDictionary* lua_parameter_dictionary,
    ::ist_slam::common::LuaParameterDictionary* initial_trajectory_pose);

// Try to convert 'msg' into 'options'. Returns false on failure.
bool FromRosMessage(const ist_slam_ros_msgs::TrajectoryOptions& msg,
                    TrajectoryOptions* options);

// Converts 'trajectory_options' into a ROS message.
ist_slam_ros_msgs::TrajectoryOptions ToRosMessage(
    const TrajectoryOptions& trajectory_options);

}  // namespace ist_slam_ros

#endif  // IST_SLAM_ROS_IST_SLAM_ROS_TRAJECTORY_OPTIONS_H

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

#ifndef IST_SLAM_ROS_IST_SLAM_ROS_NODE_OPTIONS_H
#define IST_SLAM_ROS_IST_SLAM_ROS_NODE_OPTIONS_H

#include <string>
#include <tuple>

#include "ist_slam/common/lua_parameter_dictionary.h"
#include "ist_slam/common/port.h"
#include "ist_slam/mapping/proto/map_builder_options.pb.h"
#include "ist_slam_ros/trajectory_options.h"

namespace ist_slam_ros {

// Top-level options of ist_slam's ROS integration.
struct NodeOptions {
  ::ist_slam::mapping::proto::MapBuilderOptions map_builder_options;
  std::string map_frame;
  double lookup_transform_timeout_sec;
  double submap_publish_period_sec;
  double pose_publish_period_sec;
  double trajectory_publish_period_sec;
  bool use_pose_extrapolator = true;
};

NodeOptions CreateNodeOptions(
    ::ist_slam::common::LuaParameterDictionary* lua_parameter_dictionary);

std::tuple<NodeOptions, TrajectoryOptions> LoadOptions(
    const std::string& configuration_directory,
    const std::string& configuration_basename);

}  // namespace ist_slam_ros

#endif  // IST_SLAM_ROS_IST_SLAM_ROS_NODE_OPTIONS_H

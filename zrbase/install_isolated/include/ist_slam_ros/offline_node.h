/*
 * Copyright 2018 The ist_slam Authors
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

#ifndef IST_SLAM_ROS_IST_SLAM_ROS_OFFLINE_NODE_H
#define IST_SLAM_ROS_IST_SLAM_ROS_OFFLINE_NODE_H

#include <functional>
#include <memory>
#include <string>
#include <vector>

#include "ist_slam/mapping/map_builder_interface.h"
#include "ist_slam_ros/node_options.h"

namespace ist_slam_ros {

using MapBuilderFactory =
    std::function<std::unique_ptr<::ist_slam::mapping::MapBuilderInterface>(
        const ::ist_slam::mapping::proto::MapBuilderOptions&)>;

void RunOfflineNode(const MapBuilderFactory& map_builder_factory);

}  // namespace ist_slam_ros

#endif  // IST_SLAM_ROS_IST_SLAM_ROS_OFFLINE_NODE_H

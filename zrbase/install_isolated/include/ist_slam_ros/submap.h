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

#ifndef IST_SLAM_ROS_IST_SLAM_ROS_SUBMAP_H
#define IST_SLAM_ROS_IST_SLAM_ROS_SUBMAP_H

#include <memory>
#include <string>
#include <vector>

#include "ist_slam/io/image.h"
#include "ist_slam/io/submap_painter.h"
#include "ist_slam/mapping/id.h"
#include "ist_slam/transform/rigid_transform.h"
#include "ros/ros.h"

namespace ist_slam_ros {

// Fetch 'submap_id' using the 'client' and returning the response or 'nullptr'
// on error.
std::unique_ptr<::ist_slam::io::SubmapTextures> FetchSubmapTextures(
    const ::ist_slam::mapping::SubmapId& submap_id,
    ros::ServiceClient* client);

}  // namespace ist_slam_ros

#endif  // IST_SLAM_ROS_IST_SLAM_ROS_SUBMAP_H
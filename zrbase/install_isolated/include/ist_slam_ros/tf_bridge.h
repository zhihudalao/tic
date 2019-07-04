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

#ifndef IST_SLAM_ROS_IST_SLAM_ROS_TF_BRIDGE_H
#define IST_SLAM_ROS_IST_SLAM_ROS_TF_BRIDGE_H

#include <memory>

#include "ist_slam/transform/rigid_transform.h"
#include "tf2_ros/buffer.h"

#include "ist_slam_ros/time_conversion.h"

namespace ist_slam_ros {

class TfBridge {
 public:
  TfBridge(const std::string& tracking_frame,
           double lookup_transform_timeout_sec, const tf2_ros::Buffer* buffer);
  ~TfBridge() {}

  TfBridge(const TfBridge&) = delete;
  TfBridge& operator=(const TfBridge&) = delete;

  // Returns the transform for 'frame_id' to 'tracking_frame_' if it exists at
  // 'time'.
  std::unique_ptr<::ist_slam::transform::Rigid3d> LookupToTracking(
      ::ist_slam::common::Time time, const std::string& frame_id) const;

 private:
  const std::string tracking_frame_;
  const double lookup_transform_timeout_sec_;
  const tf2_ros::Buffer* const buffer_;
};

}  // namespace ist_slam_ros

#endif  // IST_SLAM_ROS_IST_SLAM_ROS_TF_BRIDGE_H

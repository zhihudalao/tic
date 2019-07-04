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

#ifndef IST_SLAM_ROS_IST_SLAM_ROS_SENSOR_BRIDGE_H
#define IST_SLAM_ROS_IST_SLAM_ROS_SENSOR_BRIDGE_H

#include <memory>

#include "absl/types/optional.h"
#include "ist_slam/mapping/trajectory_builder_interface.h"
#include "ist_slam/sensor/imu_data.h"
#include "ist_slam/sensor/odometry_data.h"
#include "ist_slam/transform/rigid_transform.h"
#include "ist_slam/transform/transform.h"
#include "ist_slam_ros/tf_bridge.h"
#include "ist_slam_ros_msgs/LandmarkList.h"
#include "geometry_msgs/Transform.h"
#include "geometry_msgs/TransformStamped.h"
#include "nav_msgs/OccupancyGrid.h"
#include "nav_msgs/Odometry.h"
#include "sensor_msgs/Imu.h"
#include "sensor_msgs/LaserScan.h"
#include "sensor_msgs/MultiEchoLaserScan.h"
#include "sensor_msgs/NavSatFix.h"
#include "sensor_msgs/PointCloud2.h"

namespace ist_slam_ros {

// Converts ROS messages into SensorData in tracking frame for the MapBuilder.
class SensorBridge {
 public:
  explicit SensorBridge(
      int num_subdivisions_per_laser_scan, const std::string& tracking_frame,
      double lookup_transform_timeout_sec, tf2_ros::Buffer* tf_buffer,
      ::ist_slam::mapping::TrajectoryBuilderInterface* trajectory_builder);

  SensorBridge(const SensorBridge&) = delete;
  SensorBridge& operator=(const SensorBridge&) = delete;

  std::unique_ptr<::ist_slam::sensor::OdometryData> ToOdometryData(
      const nav_msgs::Odometry::ConstPtr& msg);
  void HandleOdometryMessage(const std::string& sensor_id,
                             const nav_msgs::Odometry::ConstPtr& msg);
  void HandleNavSatFixMessage(const std::string& sensor_id,
                              const sensor_msgs::NavSatFix::ConstPtr& msg);
  void HandleLandmarkMessage(
      const std::string& sensor_id,
      const ist_slam_ros_msgs::LandmarkList::ConstPtr& msg);

  std::unique_ptr<::ist_slam::sensor::ImuData> ToImuData(
      const sensor_msgs::Imu::ConstPtr& msg);
  void HandleImuMessage(const std::string& sensor_id,
                        const sensor_msgs::Imu::ConstPtr& msg);
  void HandleLaserScanMessage(const std::string& sensor_id,
                              const sensor_msgs::LaserScan::ConstPtr& msg);
  void HandleMultiEchoLaserScanMessage(
      const std::string& sensor_id,
      const sensor_msgs::MultiEchoLaserScan::ConstPtr& msg);
  void HandlePointCloud2Message(const std::string& sensor_id,
                                const sensor_msgs::PointCloud2::ConstPtr& msg);

  const TfBridge& tf_bridge() const;

 private:
  void HandleLaserScan(
      const std::string& sensor_id, ::ist_slam::common::Time start_time,
      const std::string& frame_id,
      const ::ist_slam::sensor::PointCloudWithIntensities& points);
  void HandleRangefinder(const std::string& sensor_id,
                         ::ist_slam::common::Time time,
                         const std::string& frame_id,
                         const ::ist_slam::sensor::TimedPointCloud& ranges);

  const int num_subdivisions_per_laser_scan_;
  std::map<std::string, ist_slam::common::Time>
      sensor_to_previous_subdivision_time_;
  const TfBridge tf_bridge_;
  ::ist_slam::mapping::TrajectoryBuilderInterface* const
      trajectory_builder_;

  absl::optional<::ist_slam::transform::Rigid3d> ecef_to_local_frame_;
};

}  // namespace ist_slam_ros

#endif  // IST_SLAM_ROS_IST_SLAM_ROS_SENSOR_BRIDGE_H

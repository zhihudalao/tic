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

#ifndef IST_SLAM_ROS_IST_SLAM_ROS_MSG_CONVERSION_H
#define IST_SLAM_ROS_IST_SLAM_ROS_MSG_CONVERSION_H

#include "ist_slam/common/time.h"
#include "ist_slam/io/submap_painter.h"
#include "ist_slam/sensor/landmark_data.h"
#include "ist_slam/sensor/point_cloud.h"
#include "ist_slam/transform/rigid_transform.h"
#include "ist_slam_ros_msgs/LandmarkList.h"
#include "geometry_msgs/Pose.h"
#include "geometry_msgs/Transform.h"
#include "geometry_msgs/TransformStamped.h"
#include "nav_msgs/OccupancyGrid.h"
#include "sensor_msgs/Imu.h"
#include "sensor_msgs/LaserScan.h"
#include "sensor_msgs/MultiEchoLaserScan.h"
#include "sensor_msgs/PointCloud2.h"

namespace ist_slam_ros {

sensor_msgs::PointCloud2 ToPointCloud2Message(
    int64_t timestamp, const std::string& frame_id,
    const ::ist_slam::sensor::TimedPointCloud& point_cloud);

geometry_msgs::Transform ToGeometryMsgTransform(
    const ::ist_slam::transform::Rigid3d& rigid3d);

geometry_msgs::Pose ToGeometryMsgPose(
    const ::ist_slam::transform::Rigid3d& rigid3d);

geometry_msgs::Point ToGeometryMsgPoint(const Eigen::Vector3d& vector3d);

// Converts ROS message to point cloud. Returns the time when the last point
// was acquired (different from the ROS timestamp). Timing of points is given in
// the fourth component of each point relative to `Time`.
std::tuple<::ist_slam::sensor::PointCloudWithIntensities,
           ::ist_slam::common::Time>
ToPointCloudWithIntensities(const sensor_msgs::LaserScan& msg);

std::tuple<::ist_slam::sensor::PointCloudWithIntensities,
           ::ist_slam::common::Time>
ToPointCloudWithIntensities(const sensor_msgs::MultiEchoLaserScan& msg);

std::tuple<::ist_slam::sensor::PointCloudWithIntensities,
           ::ist_slam::common::Time>
ToPointCloudWithIntensities(const sensor_msgs::PointCloud2& msg);

::ist_slam::sensor::LandmarkData ToLandmarkData(
    const ist_slam_ros_msgs::LandmarkList& landmark_list);

::ist_slam::transform::Rigid3d ToRigid3d(
    const geometry_msgs::TransformStamped& transform);

::ist_slam::transform::Rigid3d ToRigid3d(const geometry_msgs::Pose& pose);

Eigen::Vector3d ToEigen(const geometry_msgs::Vector3& vector3);

Eigen::Quaterniond ToEigen(const geometry_msgs::Quaternion& quaternion);

// Converts from WGS84 (latitude, longitude, altitude) to ECEF.
Eigen::Vector3d LatLongAltToEcef(double latitude, double longitude,
                                 double altitude);

// Returns a transform that takes ECEF coordinates from nearby points to a local
// frame that has z pointing upwards.
ist_slam::transform::Rigid3d ComputeLocalFrameFromLatLong(double latitude,
                                                              double longitude);

// Points to an occupancy grid message at a specific resolution from painted
// submap slices obtained via ::ist_slam::io::PaintSubmapSlices(...).
std::unique_ptr<nav_msgs::OccupancyGrid> CreateOccupancyGridMsg(
    const ist_slam::io::PaintSubmapSlicesResult& painted_slices,
    const double resolution, const std::string& frame_id,
    const ros::Time& time);

}  // namespace ist_slam_ros

#endif  // IST_SLAM_ROS_IST_SLAM_ROS_MSG_CONVERSION_H

/*
 * Copyright 2017 The ist_slam Authors
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

#ifndef IST_SLAM_SENSOR_IMU_DATA_H_
#define IST_SLAM_SENSOR_IMU_DATA_H_

#include "Eigen/Core"
#include "ist_slam/common/time.h"
#include "ist_slam/sensor/proto/sensor.pb.h"

namespace ist_slam {
namespace sensor {

struct ImuData {
  common::Time time;
  Eigen::Vector3d linear_acceleration;
  Eigen::Vector3d angular_velocity;
};

// Converts 'imu_data' to a proto::ImuData.
proto::ImuData ToProto(const ImuData& imu_data);

// Converts 'proto' to an ImuData.
ImuData FromProto(const proto::ImuData& proto);

}  // namespace sensor
}  // namespace ist_slam

#endif  // IST_SLAM_SENSOR_IMU_DATA_H_
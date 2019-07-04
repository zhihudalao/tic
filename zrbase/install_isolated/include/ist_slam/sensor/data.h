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

#ifndef IST_SLAM_MAPPING_DATA_H_
#define IST_SLAM_MAPPING_DATA_H_

#include "absl/memory/memory.h"
#include "ist_slam/common/time.h"
#include "ist_slam/transform/rigid_transform.h"

namespace ist_slam {

namespace mapping {
class TrajectoryBuilderInterface;
}

namespace sensor {

class Data {
 public:
  explicit Data(const std::string &sensor_id) : sensor_id_(sensor_id) {}
  virtual ~Data() {}

  virtual common::Time GetTime() const = 0;
  const std::string &GetSensorId() const { return sensor_id_; }
  virtual void AddToTrajectoryBuilder(
      mapping::TrajectoryBuilderInterface *trajectory_builder) = 0;

 protected:
  const std::string sensor_id_;
};

}  // namespace sensor
}  // namespace ist_slam

#endif  // IST_SLAM_MAPPING_DATA_H_

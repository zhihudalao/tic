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

#ifndef IST_SLAM_MAPPING_LOCAL_SLAM_RESULT_DATA_H_
#define IST_SLAM_MAPPING_LOCAL_SLAM_RESULT_DATA_H_

#include "ist_slam/mapping/pose_graph.h"
#include "ist_slam/sensor/data.h"

namespace ist_slam {
namespace mapping {

class LocalSlamResultData : public sensor::Data {
 public:
  LocalSlamResultData(const std::string& sensor_id, common::Time time)
      : Data(sensor_id), time_(time) {}

  common::Time GetTime() const override { return time_; }
  virtual void AddToPoseGraph(int trajectory_id,
                              PoseGraph* pose_graph) const = 0;

 private:
  common::Time time_;
};

}  // namespace mapping
}  // namespace ist_slam

#endif  // IST_SLAM_MAPPING_LOCAL_SLAM_RESULT_DATA_H_

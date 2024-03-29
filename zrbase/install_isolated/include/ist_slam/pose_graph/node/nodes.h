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

#ifndef IST_SLAM_POSE_GRAPH_NODE_NODES_H_
#define IST_SLAM_POSE_GRAPH_NODE_NODES_H_

#include "ist_slam/pose_graph/node/imu_calibration.h"
#include "ist_slam/pose_graph/node/pose_2d.h"
#include "ist_slam/pose_graph/node/pose_3d.h"

#include <map>

namespace ist_slam {
namespace pose_graph {

struct Nodes {
  // TODO(pifon): Migrate to Swiss Tables when they are out.
  std::map<NodeId, std::unique_ptr<Pose2D>> pose_2d_nodes;
  std::map<NodeId, std::unique_ptr<Pose3D>> pose_3d_nodes;
  std::map<NodeId, std::unique_ptr<ImuCalibration>> imu_calibration_nodes;
};

}  // namespace pose_graph
}  // namespace ist_slam

#endif  // IST_SLAM_POSE_GRAPH_NODE_NODES_H_

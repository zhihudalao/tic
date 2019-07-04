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

#ifndef IST_SLAM_POSE_GRAPH_POSE_GRAPH_DATA_H_
#define IST_SLAM_POSE_GRAPH_POSE_GRAPH_DATA_H_

#include "ist_slam/pose_graph/constraint/constraint.h"
#include "ist_slam/pose_graph/node/nodes.h"

namespace ist_slam {
namespace pose_graph {

struct PoseGraphData {
  Nodes nodes;
  std::vector<std::unique_ptr<Constraint>> constraints;
};

void AddNodeToPoseGraphData(const proto::Node& node, PoseGraphData* data);
void AddConstraintToPoseGraphData(const proto::Constraint& constraint,
                                  PoseGraphData* data);

}  // namespace pose_graph
}  // namespace ist_slam

#endif  // IST_SLAM_POSE_GRAPH_POSE_GRAPH_DATA_H_

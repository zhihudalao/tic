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

#ifndef IST_SLAM_POSE_GRAPH_SOLVER_SOLVER_H_
#define IST_SLAM_POSE_GRAPH_SOLVER_SOLVER_H_

#include "ist_slam/pose_graph/pose_graph_data.h"

namespace ist_slam {
namespace pose_graph {

class Solver {
 public:
  enum class SolverStatus {
    CONVERGENCE,
    NO_CONVERGENCE,
    FAILURE,
  };

  Solver() = default;
  virtual ~Solver() = default;

  Solver(const Solver&) = delete;
  Solver& operator=(const Solver&) = delete;

  virtual SolverStatus Solve(PoseGraphData* data) const = 0;
};

}  // namespace pose_graph
}  // namespace ist_slam

#endif  // IST_SLAM_POSE_GRAPH_SOLVER_SOLVER_H_

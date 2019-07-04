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

#ifndef IST_SLAM_POSE_GRAPH_CONSTRAINT_CONSTRAINT_H_
#define IST_SLAM_POSE_GRAPH_CONSTRAINT_CONSTRAINT_H_

#include "ist_slam/pose_graph/constraint/loss_function/loss_function.h"
#include "ist_slam/pose_graph/node/nodes.h"
#include "ist_slam/pose_graph/proto/constraint.pb.h"
#include "ceres/problem.h"

#include <string>

namespace ist_slam {
namespace pose_graph {

using ConstraintId = std::string;

class Constraint {
 public:
  Constraint(const ConstraintId& id,
             const proto::LossFunction& loss_function_proto)
      : constraint_id_(id), loss_function_(loss_function_proto) {}
  virtual ~Constraint() = default;

  Constraint(const Constraint&) = delete;
  Constraint& operator=(const Constraint&) = delete;

  proto::Constraint ToProto() const;

  const ConstraintId& constraint_id() const { return constraint_id_; }

  virtual void AddToSolver(Nodes* nodes, ceres::Problem* problem) const = 0;

 protected:
  virtual proto::CostFunction ToCostFunctionProto() const = 0;

  ceres::LossFunction* ceres_loss() const {
    return loss_function_.ceres_loss();
  }

 private:
  ConstraintId constraint_id_;
  LossFunction loss_function_;
};

}  // namespace pose_graph
}  // namespace ist_slam

#endif  // IST_SLAM_POSE_GRAPH_CONSTRAINT_CONSTRAINT_H_

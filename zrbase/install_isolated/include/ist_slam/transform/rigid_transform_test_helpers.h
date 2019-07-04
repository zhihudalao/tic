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

#ifndef IST_SLAM_TRANSFORM_RIGID_TRANSFORM_TEST_HELPERS_H_
#define IST_SLAM_TRANSFORM_RIGID_TRANSFORM_TEST_HELPERS_H_

#include <string>

#include "Eigen/Core"
#include "Eigen/Geometry"
#include "ist_slam/common/port.h"
#include "ist_slam/transform/rigid_transform.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

namespace ist_slam {
namespace transform {

template <typename T>
Eigen::Transform<T, 2, Eigen::Affine> ToEigen(const Rigid2<T>& rigid2) {
  return Eigen::Translation<T, 2>(rigid2.translation()) * rigid2.rotation();
}

template <typename T>
Eigen::Transform<T, 3, Eigen::Affine> ToEigen(const Rigid3<T>& rigid3) {
  return Eigen::Translation<T, 3>(rigid3.translation()) * rigid3.rotation();
}

MATCHER_P2(IsNearly, rigid, epsilon,
           std::string(std::string(negation ? "isn't nearly " : "is nearly ") +
                       rigid.DebugString())) {
  return ToEigen(arg).isApprox(ToEigen(rigid), epsilon);
}

}  // namespace transform
}  // namespace ist_slam

#endif  // IST_SLAM_TRANSFORM_RIGID_TRANSFORM_TEST_HELPERS_H_
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

#ifndef IST_SLAM_GROUND_TRUTH_RELATIONS_TEXT_FILE_H_
#define IST_SLAM_GROUND_TRUTH_RELATIONS_TEXT_FILE_H_

#include <string>

#include "ist_slam/common/port.h"
#include "ist_slam/ground_truth/proto/relations.pb.h"

namespace ist_slam {
namespace ground_truth {

// Reads a text file and converts it to a GroundTruth proto. Each line contains:
// time1 time2 x y z roll pitch yaw
// using Unix epoch timestamps.
//
// This is the format used in the relations files provided for:
// R. Kuemmerle, B. Steder, C. Dornhege, M. Ruhnke, G. Grisetti, C. Stachniss,
// and A. Kleiner, "On measuring the accuracy of SLAM algorithms," Autonomous
// Robots, vol. 27, no. 4, pp. 387–407, 2009.
proto::GroundTruth ReadRelationsTextFile(const std::string& relations_filename);

}  // namespace ground_truth
}  // namespace ist_slam

#endif  // IST_SLAM_GROUND_TRUTH_RELATIONS_TEXT_FILE_H_

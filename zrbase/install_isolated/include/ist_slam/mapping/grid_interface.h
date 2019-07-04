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

#ifndef IST_SLAM_MAPPING_GRID_H_
#define IST_SLAM_MAPPING_GRID_H_

#include <memory>
#include <utility>

namespace ist_slam {
namespace mapping {

class GridInterface {
  // todo(kdaun) move mutual functions of Grid2D/3D here
 public:
  virtual ~GridInterface() {}
};

}  // namespace mapping
}  // namespace ist_slam

#endif  // IST_SLAM_MAPPING_GRID_H_

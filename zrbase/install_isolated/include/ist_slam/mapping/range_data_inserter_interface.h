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

#ifndef IST_SLAM_MAPPING_RANGE_DATA_INSERTER_H_
#define IST_SLAM_MAPPING_RANGE_DATA_INSERTER_H_

#include <utility>
#include <vector>

#include "ist_slam/mapping/grid_interface.h"
#include "ist_slam/mapping/proto/2d/submaps_options_2d.pb.h"
#include "ist_slam/sensor/range_data.h"

namespace ist_slam {
namespace mapping {

proto::RangeDataInserterOptions CreateRangeDataInserterOptions(
    common::LuaParameterDictionary* const parameter_dictionary);

class RangeDataInserterInterface {
 public:
  virtual ~RangeDataInserterInterface() {}

  // Inserts 'range_data' into 'grid'.
  virtual void Insert(const sensor::RangeData& range_data,
                      GridInterface* grid) const = 0;
};

}  // namespace mapping
}  // namespace ist_slam

#endif  // IST_SLAM_MAPPING_RANGE_DATA_INSERTER_H_

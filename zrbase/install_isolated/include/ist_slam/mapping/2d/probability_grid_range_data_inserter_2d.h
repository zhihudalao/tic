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

#ifndef IST_SLAM_MAPPING_2D_RANGE_DATA_INSERTER_2D_PROBABILITY_GRID_H_
#define IST_SLAM_MAPPING_2D_RANGE_DATA_INSERTER_2D_PROBABILITY_GRID_H_

#include <utility>
#include <vector>

#include "ist_slam/common/lua_parameter_dictionary.h"
#include "ist_slam/common/port.h"
#include "ist_slam/mapping/2d/probability_grid.h"
#include "ist_slam/mapping/2d/xy_index.h"
#include "ist_slam/mapping/proto/2d/probability_grid_range_data_inserter_options_2d.pb.h"
#include "ist_slam/mapping/range_data_inserter_interface.h"
#include "ist_slam/sensor/point_cloud.h"
#include "ist_slam/sensor/range_data.h"

namespace ist_slam {
namespace mapping {

proto::ProbabilityGridRangeDataInserterOptions2D
CreateProbabilityGridRangeDataInserterOptions2D(
    common::LuaParameterDictionary* parameter_dictionary);

class ProbabilityGridRangeDataInserter2D : public RangeDataInserterInterface {
 public:
  explicit ProbabilityGridRangeDataInserter2D(
      const proto::ProbabilityGridRangeDataInserterOptions2D& options);

  ProbabilityGridRangeDataInserter2D(
      const ProbabilityGridRangeDataInserter2D&) = delete;
  ProbabilityGridRangeDataInserter2D& operator=(
      const ProbabilityGridRangeDataInserter2D&) = delete;

  // Inserts 'range_data' into 'probability_grid'.
  virtual void Insert(const sensor::RangeData& range_data,
                      GridInterface* grid) const override;

 private:
  const proto::ProbabilityGridRangeDataInserterOptions2D options_;
  const std::vector<uint16> hit_table_;
  const std::vector<uint16> miss_table_;
};

}  // namespace mapping
}  // namespace ist_slam

#endif  // IST_SLAM_MAPPING_2D_RANGE_DATA_INSERTER_2D_PROBABILITY_GRID_H_

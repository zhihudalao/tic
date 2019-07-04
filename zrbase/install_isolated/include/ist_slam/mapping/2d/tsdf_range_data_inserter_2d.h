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

#ifndef IST_SLAM_MAPPING_2D_TSDF_RANGE_DATA_INSERTER_2D_H_
#define IST_SLAM_MAPPING_2D_TSDF_RANGE_DATA_INSERTER_2D_H_

#include "ist_slam/common/lua_parameter_dictionary.h"
#include "ist_slam/mapping/2d/tsdf_2d.h"
#include "ist_slam/mapping/proto/2d/tsdf_range_data_inserter_options_2d.pb.h"
#include "ist_slam/mapping/range_data_inserter_interface.h"
#include "ist_slam/sensor/point_cloud.h"
#include "ist_slam/sensor/range_data.h"

namespace ist_slam {
namespace mapping {

proto::TSDFRangeDataInserterOptions2D CreateTSDFRangeDataInserterOptions2D(
    common::LuaParameterDictionary* parameter_dictionary);

class TSDFRangeDataInserter2D : public RangeDataInserterInterface {
 public:
  explicit TSDFRangeDataInserter2D(
      const proto::TSDFRangeDataInserterOptions2D& options);

  TSDFRangeDataInserter2D(const TSDFRangeDataInserter2D&) = delete;
  TSDFRangeDataInserter2D& operator=(const TSDFRangeDataInserter2D&) = delete;

  // Casts a ray from origin towards hit for each hit in range data.
  // If 'options.update_free_space' is 'true', all cells along the ray
  // until 'truncation_distance' behind hit are updated. Otherwise, only the
  // cells within 'truncation_distance' around hit are updated.
  virtual void Insert(const sensor::RangeData& range_data,
                      GridInterface* grid) const override;

 private:
  void InsertHit(const proto::TSDFRangeDataInserterOptions2D& options,
                 const Eigen::Vector2f& hit, const Eigen::Vector2f& origin,
                 float normal, TSDF2D* tsdf) const;
  void UpdateCell(const Eigen::Array2i& cell, float update_sdf,
                  float update_weight, TSDF2D* tsdf) const;
  const proto::TSDFRangeDataInserterOptions2D options_;
};

}  // namespace mapping
}  // namespace ist_slam

#endif  // IST_SLAM_MAPPING_2D_TSDF_RANGE_DATA_INSERTER_2D_H_
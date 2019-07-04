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

#ifndef IST_SLAM_IO_COLORING_POINTS_PROCESSOR_H_
#define IST_SLAM_IO_COLORING_POINTS_PROCESSOR_H_

#include <memory>

#include "ist_slam/common/lua_parameter_dictionary.h"
#include "ist_slam/io/points_batch.h"
#include "ist_slam/io/points_processor.h"

namespace ist_slam {
namespace io {

// Colors points with a fixed color by frame_id.
class ColoringPointsProcessor : public PointsProcessor {
 public:
  constexpr static const char* kConfigurationFileActionName = "color_points";

  ColoringPointsProcessor(const FloatColor& color, const std::string& frame_id,
                          PointsProcessor* next);

  static std::unique_ptr<ColoringPointsProcessor> FromDictionary(
      common::LuaParameterDictionary* dictionary, PointsProcessor* next);

  ~ColoringPointsProcessor() override{};

  ColoringPointsProcessor(const ColoringPointsProcessor&) = delete;
  ColoringPointsProcessor& operator=(const ColoringPointsProcessor&) = delete;

  void Process(std::unique_ptr<PointsBatch> batch) override;
  FlushResult Flush() override;

 private:
  const FloatColor color_;
  const std::string frame_id_;
  PointsProcessor* const next_;
};

}  // namespace io
}  // namespace ist_slam

#endif  // IST_SLAM_IO_COLORING_POINTS_PROCESSOR_H_
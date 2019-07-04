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

#ifndef IST_SLAM_ROS_IST_SLAM_ROS_ROS_MAP_WRITING_POINTS_PROCESSOR_H
#define IST_SLAM_ROS_IST_SLAM_ROS_ROS_MAP_WRITING_POINTS_PROCESSOR_H

#include "ist_slam/common/lua_parameter_dictionary.h"
#include "ist_slam/io/file_writer.h"
#include "ist_slam/io/points_processor.h"
#include "ist_slam/mapping/2d/probability_grid.h"
#include "ist_slam/mapping/2d/probability_grid_range_data_inserter_2d.h"
#include "ist_slam/mapping/proto/2d/probability_grid_range_data_inserter_options_2d.pb.h"
#include "ist_slam/mapping/value_conversion_tables.h"

namespace ist_slam_ros {

// Very similar to ist_slam's ProbabilityGridPointsProcessor, but writes
// out a PGM and YAML suitable for ROS map server to consume.
class RosMapWritingPointsProcessor
    : public ::ist_slam::io::PointsProcessor {
 public:
  constexpr static const char* kConfigurationFileActionName = "write_ros_map";
  RosMapWritingPointsProcessor(
      double resolution,
      const ::ist_slam::mapping::proto::
          ProbabilityGridRangeDataInserterOptions2D&
              range_data_inserter_options,
      ::ist_slam::io::FileWriterFactory file_writer_factory,
      const std::string& filestem, PointsProcessor* next);
  RosMapWritingPointsProcessor(const RosMapWritingPointsProcessor&) = delete;
  RosMapWritingPointsProcessor& operator=(const RosMapWritingPointsProcessor&) =
      delete;

  static std::unique_ptr<RosMapWritingPointsProcessor> FromDictionary(
      ::ist_slam::io::FileWriterFactory file_writer_factory,
      ::ist_slam::common::LuaParameterDictionary* dictionary,
      PointsProcessor* next);

  ~RosMapWritingPointsProcessor() override {}

  void Process(std::unique_ptr<::ist_slam::io::PointsBatch> batch) override;
  FlushResult Flush() override;

 private:
  const std::string filestem_;
  PointsProcessor* const next_;
  ::ist_slam::io::FileWriterFactory file_writer_factory_;
  ::ist_slam::mapping::ProbabilityGridRangeDataInserter2D
      range_data_inserter_;
  ::ist_slam::mapping::ValueConversionTables conversion_tables_;
  ::ist_slam::mapping::ProbabilityGrid probability_grid_;
};

}  // namespace ist_slam_ros

#endif  // IST_SLAM_ROS_IST_SLAM_ROS_ROS_MAP_WRITING_POINTS_PROCESSOR_H

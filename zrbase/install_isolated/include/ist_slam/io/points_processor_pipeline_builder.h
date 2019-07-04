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

#ifndef IST_SLAM_IO_POINTS_PROCESSOR_PIPELINE_BUILDER_H_
#define IST_SLAM_IO_POINTS_PROCESSOR_PIPELINE_BUILDER_H_

#include <string>
#include <vector>

#include "absl/container/flat_hash_map.h"
#include "ist_slam/common/lua_parameter_dictionary.h"
#include "ist_slam/io/file_writer.h"
#include "ist_slam/io/points_processor.h"
#include "ist_slam/mapping/proto/trajectory.pb.h"

namespace ist_slam {
namespace io {

// Builder to create a points processor pipeline out of a Lua configuration.
// You can register all built-in PointsProcessors using
// 'RegisterBuiltInPointsProcessors'. Non-built-in PointsProcessors must define
// a name and a factory method for building itself from a
// LuaParameterDictionary. See the various built-in PointsProcessors for
// examples.
class PointsProcessorPipelineBuilder {
 public:
  using FactoryFunction = std::function<std::unique_ptr<PointsProcessor>(
      common::LuaParameterDictionary*, PointsProcessor* next)>;

  PointsProcessorPipelineBuilder();

  PointsProcessorPipelineBuilder(const PointsProcessorPipelineBuilder&) =
      delete;
  PointsProcessorPipelineBuilder& operator=(
      const PointsProcessorPipelineBuilder&) = delete;

  // Register a new PointsProcessor type uniquly identified by 'name' which will
  // be created using 'factory'.
  void Register(const std::string& name, FactoryFunction factory);

  std::vector<std::unique_ptr<PointsProcessor>> CreatePipeline(
      common::LuaParameterDictionary* dictionary) const;

 private:
  absl::flat_hash_map<std::string, FactoryFunction> factories_;
};

// Register all 'PointsProcessor' that ship with ist_slam with this
// 'builder'.
void RegisterBuiltInPointsProcessors(
    const std::vector<mapping::proto::Trajectory>& trajectories,
    const FileWriterFactory& file_writer_factory,
    PointsProcessorPipelineBuilder* builder);

}  // namespace io
}  // namespace ist_slam

#endif  // IST_SLAM_IO_POINTS_PROCESSOR_PIPELINE_BUILDER_H_

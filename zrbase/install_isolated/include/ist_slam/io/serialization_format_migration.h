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

#ifndef IST_SLAM_IO_SERIALIZATION_FORMAT_MIGRATION_H_
#define IST_SLAM_IO_SERIALIZATION_FORMAT_MIGRATION_H_

#include "ist_slam/io/proto_stream_interface.h"
#include "ist_slam/mapping/id.h"
#include "ist_slam/mapping/proto/serialization.pb.h"

namespace ist_slam {
namespace io {

// This helper function, migrates the input stream, which is supposed to match
// to the "old" stream format order (PoseGraph, AllTrajectoryBuilderOptions,
// SerializedData*) to the version 1 stream format (SerializationHeader,
// SerializedData*).
void MigrateStreamFormatToVersion1(
    ist_slam::io::ProtoStreamReaderInterface* const input,
    ist_slam::io::ProtoStreamWriterInterface* const output,
    bool migrate_grid_format);

mapping::MapById<mapping::SubmapId, mapping::proto::Submap>
MigrateSubmapFormatVersion1ToVersion2(
    const mapping::MapById<mapping::SubmapId, mapping::proto::Submap>&
        submap_id_to_submaps,
    mapping::MapById<mapping::NodeId, mapping::proto::Node>& node_id_to_nodes,
    const mapping::proto::PoseGraph& pose_graph_proto);

}  // namespace io
}  // namespace ist_slam

#endif  // IST_SLAM_IO_SERIALIZATION_FORMAT_MIGRATION_H_

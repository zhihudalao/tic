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

#ifndef IST_SLAM_ROS_IST_SLAM_ROS_MAP_BUILDER_BRIDGE_H
#define IST_SLAM_ROS_IST_SLAM_ROS_MAP_BUILDER_BRIDGE_H

#include <memory>
#include <set>
#include <string>
#include <unordered_map>

#include "absl/synchronization/mutex.h"
#include "ist_slam/mapping/map_builder_interface.h"
#include "ist_slam/mapping/pose_graph_interface.h"
#include "ist_slam/mapping/proto/trajectory_builder_options.pb.h"
#include "ist_slam/mapping/trajectory_builder_interface.h"
#include "ist_slam_ros/node_options.h"
#include "ist_slam_ros/sensor_bridge.h"
#include "ist_slam_ros/tf_bridge.h"
#include "ist_slam_ros/trajectory_options.h"
#include "ist_slam_ros_msgs/SubmapEntry.h"
#include "ist_slam_ros_msgs/SubmapList.h"
#include "ist_slam_ros_msgs/SubmapQuery.h"
#include "nav_msgs/OccupancyGrid.h"

// Abseil unfortunately pulls in winnt.h, which #defines DELETE.
// Clean up to unbreak visualization_msgs::Marker::DELETE.
#ifdef DELETE
#undef DELETE
#endif
#include "visualization_msgs/MarkerArray.h"

namespace ist_slam_ros {

class MapBuilderBridge {
 public:
  struct LocalTrajectoryData {
    // Contains the trajectory data received from local SLAM, after
    // it had processed accumulated 'range_data_in_local' and estimated
    // current 'local_pose' at 'time'.
    struct LocalSlamData {
      ::ist_slam::common::Time time;
      ::ist_slam::transform::Rigid3d local_pose;
      ::ist_slam::sensor::RangeData range_data_in_local;
    };
    std::shared_ptr<const LocalSlamData> local_slam_data;
    ist_slam::transform::Rigid3d local_to_map;
    std::unique_ptr<ist_slam::transform::Rigid3d> published_to_tracking;
    TrajectoryOptions trajectory_options;
  };

  MapBuilderBridge(
      const NodeOptions& node_options,
      std::unique_ptr<ist_slam::mapping::MapBuilderInterface> map_builder,
      tf2_ros::Buffer* tf_buffer);

  MapBuilderBridge(const MapBuilderBridge&) = delete;
  MapBuilderBridge& operator=(const MapBuilderBridge&) = delete;

  void LoadState(const std::string& state_filename, bool load_frozen_state);
  int AddTrajectory(
      const std::set<
          ::ist_slam::mapping::TrajectoryBuilderInterface::SensorId>&
          expected_sensor_ids,
      const TrajectoryOptions& trajectory_options);
  void FinishTrajectory(int trajectory_id);
  void RunFinalOptimization();
  bool SerializeState(const std::string& filename,
                      const bool include_unfinished_submaps);

  void HandleSubmapQuery(
      ist_slam_ros_msgs::SubmapQuery::Request& request,
      ist_slam_ros_msgs::SubmapQuery::Response& response);

  std::map<int /* trajectory_id */,
           ::ist_slam::mapping::PoseGraphInterface::TrajectoryState>
  GetTrajectoryStates();
  ist_slam_ros_msgs::SubmapList GetSubmapList();
  std::unordered_map<int, LocalTrajectoryData> GetLocalTrajectoryData()
      LOCKS_EXCLUDED(mutex_);
  visualization_msgs::MarkerArray GetTrajectoryNodeList();
  visualization_msgs::MarkerArray GetLandmarkPosesList();
  visualization_msgs::MarkerArray GetConstraintList();

  SensorBridge* sensor_bridge(int trajectory_id);

 private:
  void OnLocalSlamResult(const int trajectory_id,
                         const ::ist_slam::common::Time time,
                         const ::ist_slam::transform::Rigid3d local_pose,
                         ::ist_slam::sensor::RangeData range_data_in_local)
      LOCKS_EXCLUDED(mutex_);

  absl::Mutex mutex_;
  const NodeOptions node_options_;
  std::unordered_map<int,
                     std::shared_ptr<const LocalTrajectoryData::LocalSlamData>>
      local_slam_data_ GUARDED_BY(mutex_);
  std::unique_ptr<ist_slam::mapping::MapBuilderInterface> map_builder_;
  tf2_ros::Buffer* const tf_buffer_;

  std::unordered_map<std::string /* landmark ID */, int> landmark_to_index_;

  // These are keyed with 'trajectory_id'.
  std::unordered_map<int, TrajectoryOptions> trajectory_options_;
  std::unordered_map<int, std::unique_ptr<SensorBridge>> sensor_bridges_;
  std::unordered_map<int, size_t> trajectory_to_highest_marker_id_;
};

}  // namespace ist_slam_ros

#endif  // IST_SLAM_ROS_IST_SLAM_ROS_MAP_BUILDER_BRIDGE_H

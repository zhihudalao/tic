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

#ifndef IST_SLAM_ROS_METRICS_INTERNAL_HISTOGRAM_H
#define IST_SLAM_ROS_METRICS_INTERNAL_HISTOGRAM_H

#include <map>
#include <vector>

#include "absl/synchronization/mutex.h"
#include "ist_slam/metrics/histogram.h"
#include "ist_slam_ros_msgs/Metric.h"

namespace ist_slam_ros {
namespace metrics {

constexpr double kInfiniteBoundary = std::numeric_limits<double>::infinity();

using BucketBoundaries = ::ist_slam::metrics::Histogram::BucketBoundaries;

class Histogram : public ::ist_slam::metrics::Histogram {
 public:
  explicit Histogram(const std::map<std::string, std::string>& labels,
                     const BucketBoundaries& bucket_boundaries);

  void Observe(double value) override;

  std::map<double, double> CountsByBucket();

  double Sum();

  double CumulativeCount();

  ist_slam_ros_msgs::Metric ToRosMessage();

 private:
  absl::Mutex mutex_;
  const std::map<std::string, std::string> labels_;
  const BucketBoundaries bucket_boundaries_;
  std::vector<double> bucket_counts_ GUARDED_BY(mutex_);
  double sum_ GUARDED_BY(mutex_);
};

}  // namespace metrics
}  // namespace ist_slam_ros

#endif  // IST_SLAM_ROS_METRICS_INTERNAL_HISTOGRAM_H

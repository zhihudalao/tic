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

#ifndef IST_SLAM_ROS_METRICS_FAMILY_FACTORY_H
#define IST_SLAM_ROS_METRICS_FAMILY_FACTORY_H

#include <memory>
#include <string>

#include "ist_slam/metrics/family_factory.h"
#include "ist_slam_ros/metrics/internal/counter.h"
#include "ist_slam_ros/metrics/internal/family.h"
#include "ist_slam_ros/metrics/internal/gauge.h"
#include "ist_slam_ros/metrics/internal/histogram.h"
#include "ist_slam_ros_msgs/ReadMetrics.h"

namespace ist_slam_ros {
namespace metrics {

// Realizes the factory / registry interface for the metrics in libist_slam
// and provides a wrapper to collect ROS messages from the metrics it owns.
class FamilyFactory : public ::ist_slam::metrics::FamilyFactory {
 public:
  ::ist_slam::metrics::Family<::ist_slam::metrics::Counter>*

  NewCounterFamily(const std::string& name,
                   const std::string& description) override;
  ::ist_slam::metrics::Family<::ist_slam::metrics::Gauge>*
  NewGaugeFamily(const std::string& name,
                 const std::string& description) override;
  ::ist_slam::metrics::Family<::ist_slam::metrics::Histogram>*
  NewHistogramFamily(const std::string& name, const std::string& description,
                     const ::ist_slam::metrics::Histogram::BucketBoundaries&
                         boundaries) override;

  void ReadMetrics(
      ::ist_slam_ros_msgs::ReadMetrics::Response* response) const;

 private:
  std::vector<std::unique_ptr<CounterFamily>> counter_families_;
  std::vector<std::unique_ptr<GaugeFamily>> gauge_families_;
  std::vector<std::unique_ptr<HistogramFamily>> histogram_families_;
};

}  // namespace metrics
}  // namespace ist_slam_ros

#endif  // IST_SLAM_ROS_METRICS_FAMILY_FACTORY_H

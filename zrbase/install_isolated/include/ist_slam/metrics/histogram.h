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

#ifndef IST_SLAM_METRICS_HISTOGRAM_H_
#define IST_SLAM_METRICS_HISTOGRAM_H_

#include <map>
#include <vector>

namespace ist_slam {
namespace metrics {

class Histogram {
 public:
  using BucketBoundaries = std::vector<double>;

  // Histogram instance that does nothing. Safe for use in static initializers.
  static Histogram* Null();

  static BucketBoundaries FixedWidth(double width, int num_finite_buckets);
  static BucketBoundaries ScaledPowersOf(double base, double scale_factor,
                                         double max_value);

  virtual ~Histogram() = default;
  virtual void Observe(double value) = 0;
};

}  // namespace metrics
}  // namespace ist_slam

#endif  // IST_SLAM_METRICS_HISTOGRAM_H_

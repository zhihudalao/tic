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

#ifndef IST_SLAM_METRICS_FAMILY_FACTORY_H_
#define IST_SLAM_METRICS_FAMILY_FACTORY_H_

#include <memory>
#include <string>

#include "ist_slam/metrics/counter.h"
#include "ist_slam/metrics/gauge.h"
#include "ist_slam/metrics/histogram.h"

namespace ist_slam {
namespace metrics {

template <typename MetricType>
class NullFamily;

template <typename MetricType>
class Family {
 public:  // Family instance that does nothing. Safe for use in static
          // initializers.
  static Family<MetricType>* Null() {
    static NullFamily<MetricType> null_family;
    return &null_family;
  }

  virtual ~Family() = default;

  virtual MetricType* Add(const std::map<std::string, std::string>& labels) = 0;
};

template <typename MetricType>
class NullFamily : public Family<MetricType> {
 public:
  MetricType* Add(const std::map<std::string, std::string>& labels) override {
    return MetricType::Null();
  }
};

class FamilyFactory {
 public:
  virtual ~FamilyFactory() = default;

  virtual Family<Counter>* NewCounterFamily(const std::string& name,
                                            const std::string& description) = 0;
  virtual Family<Gauge>* NewGaugeFamily(const std::string& name,
                                        const std::string& description) = 0;
  virtual Family<Histogram>* NewHistogramFamily(
      const std::string& name, const std::string& description,
      const Histogram::BucketBoundaries& boundaries) = 0;
};

}  // namespace metrics
}  // namespace ist_slam

#endif  // IST_SLAM_METRICS_FAMILY_FACTORY_H_

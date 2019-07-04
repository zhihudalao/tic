#ifndef IST_SLAM_IO_HYBRID_GRID_POINTS_PROCESSOR_H_
#define IST_SLAM_IO_HYBRID_GRID_POINTS_PROCESSOR_H_

// Library used for inserting range data points into a hybrid grid.

#include <memory>
#include <string>

#include "ist_slam/io/file_writer.h"
#include "ist_slam/io/points_batch.h"
#include "ist_slam/io/points_processor.h"
#include "ist_slam/mapping/3d/hybrid_grid.h"
#include "ist_slam/mapping/3d/range_data_inserter_3d.h"
#include "ist_slam/mapping/proto/3d/range_data_inserter_options_3d.pb.h"

namespace ist_slam {
namespace io {

// Creates a hybrid grid of the points with voxels being 'voxel_size'
// big. 'range_data_inserter' options are used to configure the range
// data ray tracing through the hybrid grid.
class HybridGridPointsProcessor : public PointsProcessor {
 public:
  constexpr static const char* kConfigurationFileActionName =
      "write_hybrid_grid";
  HybridGridPointsProcessor(double voxel_size,
                            const mapping::proto::RangeDataInserterOptions3D&
                                range_data_inserter_options,
                            std::unique_ptr<FileWriter> file_writer,
                            PointsProcessor* next);
  HybridGridPointsProcessor(const HybridGridPointsProcessor&) = delete;
  HybridGridPointsProcessor& operator=(const HybridGridPointsProcessor&) =
      delete;

  static std::unique_ptr<HybridGridPointsProcessor> FromDictionary(
      const FileWriterFactory& file_writer_factory,
      common::LuaParameterDictionary* dictionary, PointsProcessor* next);

  ~HybridGridPointsProcessor() override {}

  void Process(std::unique_ptr<PointsBatch> batch) override;
  FlushResult Flush() override;

 private:
  PointsProcessor* const next_;

  mapping::RangeDataInserter3D range_data_inserter_;
  mapping::HybridGrid hybrid_grid_;
  std::unique_ptr<FileWriter> file_writer_;
};

}  // namespace io
}  // namespace ist_slam

#endif  // IST_SLAM_IO_HYBRID_GRID_POINTS_PROCESSOR_H_

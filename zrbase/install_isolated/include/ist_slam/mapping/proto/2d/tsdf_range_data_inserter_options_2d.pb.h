// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ist_slam/mapping/proto/2d/tsdf_range_data_inserter_options_2d.proto

#ifndef PROTOBUF_ist_5fslam_2fmapping_2fproto_2f2d_2ftsdf_5frange_5fdata_5finserter_5foptions_5f2d_2eproto__INCLUDED
#define PROTOBUF_ist_5fslam_2fmapping_2fproto_2f2d_2ftsdf_5frange_5fdata_5finserter_5foptions_5f2d_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3004000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3004000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
#include "ist_slam/mapping/proto/2d/normal_estimation_options_2d.pb.h"
// @@protoc_insertion_point(includes)
namespace ist_slam {
namespace mapping {
namespace proto {
class TSDFRangeDataInserterOptions2D;
class TSDFRangeDataInserterOptions2DDefaultTypeInternal;
extern TSDFRangeDataInserterOptions2DDefaultTypeInternal _TSDFRangeDataInserterOptions2D_default_instance_;
}  // namespace proto
}  // namespace mapping
}  // namespace ist_slam

namespace ist_slam {
namespace mapping {
namespace proto {

namespace protobuf_ist_5fslam_2fmapping_2fproto_2f2d_2ftsdf_5frange_5fdata_5finserter_5foptions_5f2d_2eproto {
// Internal implementation detail -- do not call these.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[];
  static const ::google::protobuf::uint32 offsets[];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static void InitDefaultsImpl();
};
void AddDescriptors();
void InitDefaults();
}  // namespace protobuf_ist_5fslam_2fmapping_2fproto_2f2d_2ftsdf_5frange_5fdata_5finserter_5foptions_5f2d_2eproto

// ===================================================================

class TSDFRangeDataInserterOptions2D : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:ist_slam.mapping.proto.TSDFRangeDataInserterOptions2D) */ {
 public:
  TSDFRangeDataInserterOptions2D();
  virtual ~TSDFRangeDataInserterOptions2D();

  TSDFRangeDataInserterOptions2D(const TSDFRangeDataInserterOptions2D& from);

  inline TSDFRangeDataInserterOptions2D& operator=(const TSDFRangeDataInserterOptions2D& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  TSDFRangeDataInserterOptions2D(TSDFRangeDataInserterOptions2D&& from) noexcept
    : TSDFRangeDataInserterOptions2D() {
    *this = ::std::move(from);
  }

  inline TSDFRangeDataInserterOptions2D& operator=(TSDFRangeDataInserterOptions2D&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const TSDFRangeDataInserterOptions2D& default_instance();

  static inline const TSDFRangeDataInserterOptions2D* internal_default_instance() {
    return reinterpret_cast<const TSDFRangeDataInserterOptions2D*>(
               &_TSDFRangeDataInserterOptions2D_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(TSDFRangeDataInserterOptions2D* other);
  friend void swap(TSDFRangeDataInserterOptions2D& a, TSDFRangeDataInserterOptions2D& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline TSDFRangeDataInserterOptions2D* New() const PROTOBUF_FINAL { return New(NULL); }

  TSDFRangeDataInserterOptions2D* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const TSDFRangeDataInserterOptions2D& from);
  void MergeFrom(const TSDFRangeDataInserterOptions2D& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(TSDFRangeDataInserterOptions2D* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // .ist_slam.mapping.proto.NormalEstimationOptions2D normal_estimation_options = 4;
  bool has_normal_estimation_options() const;
  void clear_normal_estimation_options();
  static const int kNormalEstimationOptionsFieldNumber = 4;
  const ::ist_slam::mapping::proto::NormalEstimationOptions2D& normal_estimation_options() const;
  ::ist_slam::mapping::proto::NormalEstimationOptions2D* mutable_normal_estimation_options();
  ::ist_slam::mapping::proto::NormalEstimationOptions2D* release_normal_estimation_options();
  void set_allocated_normal_estimation_options(::ist_slam::mapping::proto::NormalEstimationOptions2D* normal_estimation_options);

  // double truncation_distance = 1;
  void clear_truncation_distance();
  static const int kTruncationDistanceFieldNumber = 1;
  double truncation_distance() const;
  void set_truncation_distance(double value);

  // double maximum_weight = 2;
  void clear_maximum_weight();
  static const int kMaximumWeightFieldNumber = 2;
  double maximum_weight() const;
  void set_maximum_weight(double value);

  // bool update_free_space = 3;
  void clear_update_free_space();
  static const int kUpdateFreeSpaceFieldNumber = 3;
  bool update_free_space() const;
  void set_update_free_space(bool value);

  // bool project_sdf_distance_to_scan_normal = 5;
  void clear_project_sdf_distance_to_scan_normal();
  static const int kProjectSdfDistanceToScanNormalFieldNumber = 5;
  bool project_sdf_distance_to_scan_normal() const;
  void set_project_sdf_distance_to_scan_normal(bool value);

  // int32 update_weight_range_exponent = 6;
  void clear_update_weight_range_exponent();
  static const int kUpdateWeightRangeExponentFieldNumber = 6;
  ::google::protobuf::int32 update_weight_range_exponent() const;
  void set_update_weight_range_exponent(::google::protobuf::int32 value);

  // double update_weight_angle_scan_normal_to_ray_kernel_bandwidth = 7;
  void clear_update_weight_angle_scan_normal_to_ray_kernel_bandwidth();
  static const int kUpdateWeightAngleScanNormalToRayKernelBandwidthFieldNumber = 7;
  double update_weight_angle_scan_normal_to_ray_kernel_bandwidth() const;
  void set_update_weight_angle_scan_normal_to_ray_kernel_bandwidth(double value);

  // double update_weight_distance_cell_to_hit_kernel_bandwidth = 8;
  void clear_update_weight_distance_cell_to_hit_kernel_bandwidth();
  static const int kUpdateWeightDistanceCellToHitKernelBandwidthFieldNumber = 8;
  double update_weight_distance_cell_to_hit_kernel_bandwidth() const;
  void set_update_weight_distance_cell_to_hit_kernel_bandwidth(double value);

  // @@protoc_insertion_point(class_scope:ist_slam.mapping.proto.TSDFRangeDataInserterOptions2D)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::ist_slam::mapping::proto::NormalEstimationOptions2D* normal_estimation_options_;
  double truncation_distance_;
  double maximum_weight_;
  bool update_free_space_;
  bool project_sdf_distance_to_scan_normal_;
  ::google::protobuf::int32 update_weight_range_exponent_;
  double update_weight_angle_scan_normal_to_ray_kernel_bandwidth_;
  double update_weight_distance_cell_to_hit_kernel_bandwidth_;
  mutable int _cached_size_;
  friend struct protobuf_ist_5fslam_2fmapping_2fproto_2f2d_2ftsdf_5frange_5fdata_5finserter_5foptions_5f2d_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// TSDFRangeDataInserterOptions2D

// double truncation_distance = 1;
inline void TSDFRangeDataInserterOptions2D::clear_truncation_distance() {
  truncation_distance_ = 0;
}
inline double TSDFRangeDataInserterOptions2D::truncation_distance() const {
  // @@protoc_insertion_point(field_get:ist_slam.mapping.proto.TSDFRangeDataInserterOptions2D.truncation_distance)
  return truncation_distance_;
}
inline void TSDFRangeDataInserterOptions2D::set_truncation_distance(double value) {
  
  truncation_distance_ = value;
  // @@protoc_insertion_point(field_set:ist_slam.mapping.proto.TSDFRangeDataInserterOptions2D.truncation_distance)
}

// double maximum_weight = 2;
inline void TSDFRangeDataInserterOptions2D::clear_maximum_weight() {
  maximum_weight_ = 0;
}
inline double TSDFRangeDataInserterOptions2D::maximum_weight() const {
  // @@protoc_insertion_point(field_get:ist_slam.mapping.proto.TSDFRangeDataInserterOptions2D.maximum_weight)
  return maximum_weight_;
}
inline void TSDFRangeDataInserterOptions2D::set_maximum_weight(double value) {
  
  maximum_weight_ = value;
  // @@protoc_insertion_point(field_set:ist_slam.mapping.proto.TSDFRangeDataInserterOptions2D.maximum_weight)
}

// bool update_free_space = 3;
inline void TSDFRangeDataInserterOptions2D::clear_update_free_space() {
  update_free_space_ = false;
}
inline bool TSDFRangeDataInserterOptions2D::update_free_space() const {
  // @@protoc_insertion_point(field_get:ist_slam.mapping.proto.TSDFRangeDataInserterOptions2D.update_free_space)
  return update_free_space_;
}
inline void TSDFRangeDataInserterOptions2D::set_update_free_space(bool value) {
  
  update_free_space_ = value;
  // @@protoc_insertion_point(field_set:ist_slam.mapping.proto.TSDFRangeDataInserterOptions2D.update_free_space)
}

// .ist_slam.mapping.proto.NormalEstimationOptions2D normal_estimation_options = 4;
inline bool TSDFRangeDataInserterOptions2D::has_normal_estimation_options() const {
  return this != internal_default_instance() && normal_estimation_options_ != NULL;
}
inline void TSDFRangeDataInserterOptions2D::clear_normal_estimation_options() {
  if (GetArenaNoVirtual() == NULL && normal_estimation_options_ != NULL) delete normal_estimation_options_;
  normal_estimation_options_ = NULL;
}
inline const ::ist_slam::mapping::proto::NormalEstimationOptions2D& TSDFRangeDataInserterOptions2D::normal_estimation_options() const {
  const ::ist_slam::mapping::proto::NormalEstimationOptions2D* p = normal_estimation_options_;
  // @@protoc_insertion_point(field_get:ist_slam.mapping.proto.TSDFRangeDataInserterOptions2D.normal_estimation_options)
  return p != NULL ? *p : *reinterpret_cast<const ::ist_slam::mapping::proto::NormalEstimationOptions2D*>(
      &::ist_slam::mapping::proto::_NormalEstimationOptions2D_default_instance_);
}
inline ::ist_slam::mapping::proto::NormalEstimationOptions2D* TSDFRangeDataInserterOptions2D::mutable_normal_estimation_options() {
  
  if (normal_estimation_options_ == NULL) {
    normal_estimation_options_ = new ::ist_slam::mapping::proto::NormalEstimationOptions2D;
  }
  // @@protoc_insertion_point(field_mutable:ist_slam.mapping.proto.TSDFRangeDataInserterOptions2D.normal_estimation_options)
  return normal_estimation_options_;
}
inline ::ist_slam::mapping::proto::NormalEstimationOptions2D* TSDFRangeDataInserterOptions2D::release_normal_estimation_options() {
  // @@protoc_insertion_point(field_release:ist_slam.mapping.proto.TSDFRangeDataInserterOptions2D.normal_estimation_options)
  
  ::ist_slam::mapping::proto::NormalEstimationOptions2D* temp = normal_estimation_options_;
  normal_estimation_options_ = NULL;
  return temp;
}
inline void TSDFRangeDataInserterOptions2D::set_allocated_normal_estimation_options(::ist_slam::mapping::proto::NormalEstimationOptions2D* normal_estimation_options) {
  delete normal_estimation_options_;
  normal_estimation_options_ = normal_estimation_options;
  if (normal_estimation_options) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:ist_slam.mapping.proto.TSDFRangeDataInserterOptions2D.normal_estimation_options)
}

// bool project_sdf_distance_to_scan_normal = 5;
inline void TSDFRangeDataInserterOptions2D::clear_project_sdf_distance_to_scan_normal() {
  project_sdf_distance_to_scan_normal_ = false;
}
inline bool TSDFRangeDataInserterOptions2D::project_sdf_distance_to_scan_normal() const {
  // @@protoc_insertion_point(field_get:ist_slam.mapping.proto.TSDFRangeDataInserterOptions2D.project_sdf_distance_to_scan_normal)
  return project_sdf_distance_to_scan_normal_;
}
inline void TSDFRangeDataInserterOptions2D::set_project_sdf_distance_to_scan_normal(bool value) {
  
  project_sdf_distance_to_scan_normal_ = value;
  // @@protoc_insertion_point(field_set:ist_slam.mapping.proto.TSDFRangeDataInserterOptions2D.project_sdf_distance_to_scan_normal)
}

// int32 update_weight_range_exponent = 6;
inline void TSDFRangeDataInserterOptions2D::clear_update_weight_range_exponent() {
  update_weight_range_exponent_ = 0;
}
inline ::google::protobuf::int32 TSDFRangeDataInserterOptions2D::update_weight_range_exponent() const {
  // @@protoc_insertion_point(field_get:ist_slam.mapping.proto.TSDFRangeDataInserterOptions2D.update_weight_range_exponent)
  return update_weight_range_exponent_;
}
inline void TSDFRangeDataInserterOptions2D::set_update_weight_range_exponent(::google::protobuf::int32 value) {
  
  update_weight_range_exponent_ = value;
  // @@protoc_insertion_point(field_set:ist_slam.mapping.proto.TSDFRangeDataInserterOptions2D.update_weight_range_exponent)
}

// double update_weight_angle_scan_normal_to_ray_kernel_bandwidth = 7;
inline void TSDFRangeDataInserterOptions2D::clear_update_weight_angle_scan_normal_to_ray_kernel_bandwidth() {
  update_weight_angle_scan_normal_to_ray_kernel_bandwidth_ = 0;
}
inline double TSDFRangeDataInserterOptions2D::update_weight_angle_scan_normal_to_ray_kernel_bandwidth() const {
  // @@protoc_insertion_point(field_get:ist_slam.mapping.proto.TSDFRangeDataInserterOptions2D.update_weight_angle_scan_normal_to_ray_kernel_bandwidth)
  return update_weight_angle_scan_normal_to_ray_kernel_bandwidth_;
}
inline void TSDFRangeDataInserterOptions2D::set_update_weight_angle_scan_normal_to_ray_kernel_bandwidth(double value) {
  
  update_weight_angle_scan_normal_to_ray_kernel_bandwidth_ = value;
  // @@protoc_insertion_point(field_set:ist_slam.mapping.proto.TSDFRangeDataInserterOptions2D.update_weight_angle_scan_normal_to_ray_kernel_bandwidth)
}

// double update_weight_distance_cell_to_hit_kernel_bandwidth = 8;
inline void TSDFRangeDataInserterOptions2D::clear_update_weight_distance_cell_to_hit_kernel_bandwidth() {
  update_weight_distance_cell_to_hit_kernel_bandwidth_ = 0;
}
inline double TSDFRangeDataInserterOptions2D::update_weight_distance_cell_to_hit_kernel_bandwidth() const {
  // @@protoc_insertion_point(field_get:ist_slam.mapping.proto.TSDFRangeDataInserterOptions2D.update_weight_distance_cell_to_hit_kernel_bandwidth)
  return update_weight_distance_cell_to_hit_kernel_bandwidth_;
}
inline void TSDFRangeDataInserterOptions2D::set_update_weight_distance_cell_to_hit_kernel_bandwidth(double value) {
  
  update_weight_distance_cell_to_hit_kernel_bandwidth_ = value;
  // @@protoc_insertion_point(field_set:ist_slam.mapping.proto.TSDFRangeDataInserterOptions2D.update_weight_distance_cell_to_hit_kernel_bandwidth)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)


}  // namespace proto
}  // namespace mapping
}  // namespace ist_slam

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_ist_5fslam_2fmapping_2fproto_2f2d_2ftsdf_5frange_5fdata_5finserter_5foptions_5f2d_2eproto__INCLUDED

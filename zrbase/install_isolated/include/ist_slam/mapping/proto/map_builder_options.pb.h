// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ist_slam/mapping/proto/map_builder_options.proto

#ifndef PROTOBUF_ist_5fslam_2fmapping_2fproto_2fmap_5fbuilder_5foptions_2eproto__INCLUDED
#define PROTOBUF_ist_5fslam_2fmapping_2fproto_2fmap_5fbuilder_5foptions_2eproto__INCLUDED

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
#include "ist_slam/mapping/proto/pose_graph_options.pb.h"
// @@protoc_insertion_point(includes)
namespace ist_slam {
namespace mapping {
namespace proto {
class MapBuilderOptions;
class MapBuilderOptionsDefaultTypeInternal;
extern MapBuilderOptionsDefaultTypeInternal _MapBuilderOptions_default_instance_;
}  // namespace proto
}  // namespace mapping
}  // namespace ist_slam

namespace ist_slam {
namespace mapping {
namespace proto {

namespace protobuf_ist_5fslam_2fmapping_2fproto_2fmap_5fbuilder_5foptions_2eproto {
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
}  // namespace protobuf_ist_5fslam_2fmapping_2fproto_2fmap_5fbuilder_5foptions_2eproto

// ===================================================================

class MapBuilderOptions : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:ist_slam.mapping.proto.MapBuilderOptions) */ {
 public:
  MapBuilderOptions();
  virtual ~MapBuilderOptions();

  MapBuilderOptions(const MapBuilderOptions& from);

  inline MapBuilderOptions& operator=(const MapBuilderOptions& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  MapBuilderOptions(MapBuilderOptions&& from) noexcept
    : MapBuilderOptions() {
    *this = ::std::move(from);
  }

  inline MapBuilderOptions& operator=(MapBuilderOptions&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const MapBuilderOptions& default_instance();

  static inline const MapBuilderOptions* internal_default_instance() {
    return reinterpret_cast<const MapBuilderOptions*>(
               &_MapBuilderOptions_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(MapBuilderOptions* other);
  friend void swap(MapBuilderOptions& a, MapBuilderOptions& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline MapBuilderOptions* New() const PROTOBUF_FINAL { return New(NULL); }

  MapBuilderOptions* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const MapBuilderOptions& from);
  void MergeFrom(const MapBuilderOptions& from);
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
  void InternalSwap(MapBuilderOptions* other);
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

  // .ist_slam.mapping.proto.PoseGraphOptions pose_graph_options = 4;
  bool has_pose_graph_options() const;
  void clear_pose_graph_options();
  static const int kPoseGraphOptionsFieldNumber = 4;
  const ::ist_slam::mapping::proto::PoseGraphOptions& pose_graph_options() const;
  ::ist_slam::mapping::proto::PoseGraphOptions* mutable_pose_graph_options();
  ::ist_slam::mapping::proto::PoseGraphOptions* release_pose_graph_options();
  void set_allocated_pose_graph_options(::ist_slam::mapping::proto::PoseGraphOptions* pose_graph_options);

  // bool use_trajectory_builder_2d = 1;
  void clear_use_trajectory_builder_2d();
  static const int kUseTrajectoryBuilder2DFieldNumber = 1;
  bool use_trajectory_builder_2d() const;
  void set_use_trajectory_builder_2d(bool value);

  // bool use_trajectory_builder_3d = 2;
  void clear_use_trajectory_builder_3d();
  static const int kUseTrajectoryBuilder3DFieldNumber = 2;
  bool use_trajectory_builder_3d() const;
  void set_use_trajectory_builder_3d(bool value);

  // bool collate_by_trajectory = 5;
  void clear_collate_by_trajectory();
  static const int kCollateByTrajectoryFieldNumber = 5;
  bool collate_by_trajectory() const;
  void set_collate_by_trajectory(bool value);

  // int32 num_background_threads = 3;
  void clear_num_background_threads();
  static const int kNumBackgroundThreadsFieldNumber = 3;
  ::google::protobuf::int32 num_background_threads() const;
  void set_num_background_threads(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:ist_slam.mapping.proto.MapBuilderOptions)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::ist_slam::mapping::proto::PoseGraphOptions* pose_graph_options_;
  bool use_trajectory_builder_2d_;
  bool use_trajectory_builder_3d_;
  bool collate_by_trajectory_;
  ::google::protobuf::int32 num_background_threads_;
  mutable int _cached_size_;
  friend struct protobuf_ist_5fslam_2fmapping_2fproto_2fmap_5fbuilder_5foptions_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// MapBuilderOptions

// bool use_trajectory_builder_2d = 1;
inline void MapBuilderOptions::clear_use_trajectory_builder_2d() {
  use_trajectory_builder_2d_ = false;
}
inline bool MapBuilderOptions::use_trajectory_builder_2d() const {
  // @@protoc_insertion_point(field_get:ist_slam.mapping.proto.MapBuilderOptions.use_trajectory_builder_2d)
  return use_trajectory_builder_2d_;
}
inline void MapBuilderOptions::set_use_trajectory_builder_2d(bool value) {
  
  use_trajectory_builder_2d_ = value;
  // @@protoc_insertion_point(field_set:ist_slam.mapping.proto.MapBuilderOptions.use_trajectory_builder_2d)
}

// bool use_trajectory_builder_3d = 2;
inline void MapBuilderOptions::clear_use_trajectory_builder_3d() {
  use_trajectory_builder_3d_ = false;
}
inline bool MapBuilderOptions::use_trajectory_builder_3d() const {
  // @@protoc_insertion_point(field_get:ist_slam.mapping.proto.MapBuilderOptions.use_trajectory_builder_3d)
  return use_trajectory_builder_3d_;
}
inline void MapBuilderOptions::set_use_trajectory_builder_3d(bool value) {
  
  use_trajectory_builder_3d_ = value;
  // @@protoc_insertion_point(field_set:ist_slam.mapping.proto.MapBuilderOptions.use_trajectory_builder_3d)
}

// int32 num_background_threads = 3;
inline void MapBuilderOptions::clear_num_background_threads() {
  num_background_threads_ = 0;
}
inline ::google::protobuf::int32 MapBuilderOptions::num_background_threads() const {
  // @@protoc_insertion_point(field_get:ist_slam.mapping.proto.MapBuilderOptions.num_background_threads)
  return num_background_threads_;
}
inline void MapBuilderOptions::set_num_background_threads(::google::protobuf::int32 value) {
  
  num_background_threads_ = value;
  // @@protoc_insertion_point(field_set:ist_slam.mapping.proto.MapBuilderOptions.num_background_threads)
}

// .ist_slam.mapping.proto.PoseGraphOptions pose_graph_options = 4;
inline bool MapBuilderOptions::has_pose_graph_options() const {
  return this != internal_default_instance() && pose_graph_options_ != NULL;
}
inline void MapBuilderOptions::clear_pose_graph_options() {
  if (GetArenaNoVirtual() == NULL && pose_graph_options_ != NULL) delete pose_graph_options_;
  pose_graph_options_ = NULL;
}
inline const ::ist_slam::mapping::proto::PoseGraphOptions& MapBuilderOptions::pose_graph_options() const {
  const ::ist_slam::mapping::proto::PoseGraphOptions* p = pose_graph_options_;
  // @@protoc_insertion_point(field_get:ist_slam.mapping.proto.MapBuilderOptions.pose_graph_options)
  return p != NULL ? *p : *reinterpret_cast<const ::ist_slam::mapping::proto::PoseGraphOptions*>(
      &::ist_slam::mapping::proto::_PoseGraphOptions_default_instance_);
}
inline ::ist_slam::mapping::proto::PoseGraphOptions* MapBuilderOptions::mutable_pose_graph_options() {
  
  if (pose_graph_options_ == NULL) {
    pose_graph_options_ = new ::ist_slam::mapping::proto::PoseGraphOptions;
  }
  // @@protoc_insertion_point(field_mutable:ist_slam.mapping.proto.MapBuilderOptions.pose_graph_options)
  return pose_graph_options_;
}
inline ::ist_slam::mapping::proto::PoseGraphOptions* MapBuilderOptions::release_pose_graph_options() {
  // @@protoc_insertion_point(field_release:ist_slam.mapping.proto.MapBuilderOptions.pose_graph_options)
  
  ::ist_slam::mapping::proto::PoseGraphOptions* temp = pose_graph_options_;
  pose_graph_options_ = NULL;
  return temp;
}
inline void MapBuilderOptions::set_allocated_pose_graph_options(::ist_slam::mapping::proto::PoseGraphOptions* pose_graph_options) {
  delete pose_graph_options_;
  pose_graph_options_ = pose_graph_options;
  if (pose_graph_options) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:ist_slam.mapping.proto.MapBuilderOptions.pose_graph_options)
}

// bool collate_by_trajectory = 5;
inline void MapBuilderOptions::clear_collate_by_trajectory() {
  collate_by_trajectory_ = false;
}
inline bool MapBuilderOptions::collate_by_trajectory() const {
  // @@protoc_insertion_point(field_get:ist_slam.mapping.proto.MapBuilderOptions.collate_by_trajectory)
  return collate_by_trajectory_;
}
inline void MapBuilderOptions::set_collate_by_trajectory(bool value) {
  
  collate_by_trajectory_ = value;
  // @@protoc_insertion_point(field_set:ist_slam.mapping.proto.MapBuilderOptions.collate_by_trajectory)
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

#endif  // PROTOBUF_ist_5fslam_2fmapping_2fproto_2fmap_5fbuilder_5foptions_2eproto__INCLUDED

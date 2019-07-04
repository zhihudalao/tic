// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ist_slam/mapping/proto/scan_matching/fast_correlative_scan_matcher_options_2d.proto

#ifndef PROTOBUF_ist_5fslam_2fmapping_2fproto_2fscan_5fmatching_2ffast_5fcorrelative_5fscan_5fmatcher_5foptions_5f2d_2eproto__INCLUDED
#define PROTOBUF_ist_5fslam_2fmapping_2fproto_2fscan_5fmatching_2ffast_5fcorrelative_5fscan_5fmatcher_5foptions_5f2d_2eproto__INCLUDED

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
// @@protoc_insertion_point(includes)
namespace ist_slam {
namespace mapping {
namespace scan_matching {
namespace proto {
class FastCorrelativeScanMatcherOptions2D;
class FastCorrelativeScanMatcherOptions2DDefaultTypeInternal;
extern FastCorrelativeScanMatcherOptions2DDefaultTypeInternal _FastCorrelativeScanMatcherOptions2D_default_instance_;
}  // namespace proto
}  // namespace scan_matching
}  // namespace mapping
}  // namespace ist_slam

namespace ist_slam {
namespace mapping {
namespace scan_matching {
namespace proto {

namespace protobuf_ist_5fslam_2fmapping_2fproto_2fscan_5fmatching_2ffast_5fcorrelative_5fscan_5fmatcher_5foptions_5f2d_2eproto {
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
}  // namespace protobuf_ist_5fslam_2fmapping_2fproto_2fscan_5fmatching_2ffast_5fcorrelative_5fscan_5fmatcher_5foptions_5f2d_2eproto

// ===================================================================

class FastCorrelativeScanMatcherOptions2D : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:ist_slam.mapping.scan_matching.proto.FastCorrelativeScanMatcherOptions2D) */ {
 public:
  FastCorrelativeScanMatcherOptions2D();
  virtual ~FastCorrelativeScanMatcherOptions2D();

  FastCorrelativeScanMatcherOptions2D(const FastCorrelativeScanMatcherOptions2D& from);

  inline FastCorrelativeScanMatcherOptions2D& operator=(const FastCorrelativeScanMatcherOptions2D& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  FastCorrelativeScanMatcherOptions2D(FastCorrelativeScanMatcherOptions2D&& from) noexcept
    : FastCorrelativeScanMatcherOptions2D() {
    *this = ::std::move(from);
  }

  inline FastCorrelativeScanMatcherOptions2D& operator=(FastCorrelativeScanMatcherOptions2D&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const FastCorrelativeScanMatcherOptions2D& default_instance();

  static inline const FastCorrelativeScanMatcherOptions2D* internal_default_instance() {
    return reinterpret_cast<const FastCorrelativeScanMatcherOptions2D*>(
               &_FastCorrelativeScanMatcherOptions2D_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(FastCorrelativeScanMatcherOptions2D* other);
  friend void swap(FastCorrelativeScanMatcherOptions2D& a, FastCorrelativeScanMatcherOptions2D& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline FastCorrelativeScanMatcherOptions2D* New() const PROTOBUF_FINAL { return New(NULL); }

  FastCorrelativeScanMatcherOptions2D* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const FastCorrelativeScanMatcherOptions2D& from);
  void MergeFrom(const FastCorrelativeScanMatcherOptions2D& from);
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
  void InternalSwap(FastCorrelativeScanMatcherOptions2D* other);
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

  // double linear_search_window = 3;
  void clear_linear_search_window();
  static const int kLinearSearchWindowFieldNumber = 3;
  double linear_search_window() const;
  void set_linear_search_window(double value);

  // double angular_search_window = 4;
  void clear_angular_search_window();
  static const int kAngularSearchWindowFieldNumber = 4;
  double angular_search_window() const;
  void set_angular_search_window(double value);

  // int32 branch_and_bound_depth = 2;
  void clear_branch_and_bound_depth();
  static const int kBranchAndBoundDepthFieldNumber = 2;
  ::google::protobuf::int32 branch_and_bound_depth() const;
  void set_branch_and_bound_depth(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:ist_slam.mapping.scan_matching.proto.FastCorrelativeScanMatcherOptions2D)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  double linear_search_window_;
  double angular_search_window_;
  ::google::protobuf::int32 branch_and_bound_depth_;
  mutable int _cached_size_;
  friend struct protobuf_ist_5fslam_2fmapping_2fproto_2fscan_5fmatching_2ffast_5fcorrelative_5fscan_5fmatcher_5foptions_5f2d_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// FastCorrelativeScanMatcherOptions2D

// double linear_search_window = 3;
inline void FastCorrelativeScanMatcherOptions2D::clear_linear_search_window() {
  linear_search_window_ = 0;
}
inline double FastCorrelativeScanMatcherOptions2D::linear_search_window() const {
  // @@protoc_insertion_point(field_get:ist_slam.mapping.scan_matching.proto.FastCorrelativeScanMatcherOptions2D.linear_search_window)
  return linear_search_window_;
}
inline void FastCorrelativeScanMatcherOptions2D::set_linear_search_window(double value) {
  
  linear_search_window_ = value;
  // @@protoc_insertion_point(field_set:ist_slam.mapping.scan_matching.proto.FastCorrelativeScanMatcherOptions2D.linear_search_window)
}

// double angular_search_window = 4;
inline void FastCorrelativeScanMatcherOptions2D::clear_angular_search_window() {
  angular_search_window_ = 0;
}
inline double FastCorrelativeScanMatcherOptions2D::angular_search_window() const {
  // @@protoc_insertion_point(field_get:ist_slam.mapping.scan_matching.proto.FastCorrelativeScanMatcherOptions2D.angular_search_window)
  return angular_search_window_;
}
inline void FastCorrelativeScanMatcherOptions2D::set_angular_search_window(double value) {
  
  angular_search_window_ = value;
  // @@protoc_insertion_point(field_set:ist_slam.mapping.scan_matching.proto.FastCorrelativeScanMatcherOptions2D.angular_search_window)
}

// int32 branch_and_bound_depth = 2;
inline void FastCorrelativeScanMatcherOptions2D::clear_branch_and_bound_depth() {
  branch_and_bound_depth_ = 0;
}
inline ::google::protobuf::int32 FastCorrelativeScanMatcherOptions2D::branch_and_bound_depth() const {
  // @@protoc_insertion_point(field_get:ist_slam.mapping.scan_matching.proto.FastCorrelativeScanMatcherOptions2D.branch_and_bound_depth)
  return branch_and_bound_depth_;
}
inline void FastCorrelativeScanMatcherOptions2D::set_branch_and_bound_depth(::google::protobuf::int32 value) {
  
  branch_and_bound_depth_ = value;
  // @@protoc_insertion_point(field_set:ist_slam.mapping.scan_matching.proto.FastCorrelativeScanMatcherOptions2D.branch_and_bound_depth)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)


}  // namespace proto
}  // namespace scan_matching
}  // namespace mapping
}  // namespace ist_slam

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_ist_5fslam_2fmapping_2fproto_2fscan_5fmatching_2ffast_5fcorrelative_5fscan_5fmatcher_5foptions_5f2d_2eproto__INCLUDED

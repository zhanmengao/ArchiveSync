// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: struct.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_struct_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_struct_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3021000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3021011 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_struct_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_struct_2eproto {
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_struct_2eproto;
namespace pb {
class Packet;
struct PacketDefaultTypeInternal;
extern PacketDefaultTypeInternal _Packet_default_instance_;
class TextItem;
struct TextItemDefaultTypeInternal;
extern TextItemDefaultTypeInternal _TextItem_default_instance_;
}  // namespace pb
PROTOBUF_NAMESPACE_OPEN
template<> ::pb::Packet* Arena::CreateMaybeMessage<::pb::Packet>(Arena*);
template<> ::pb::TextItem* Arena::CreateMaybeMessage<::pb::TextItem>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace pb {

// ===================================================================

class TextItem final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:pb.TextItem) */ {
 public:
  inline TextItem() : TextItem(nullptr) {}
  ~TextItem() override;
  explicit PROTOBUF_CONSTEXPR TextItem(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  TextItem(const TextItem& from);
  TextItem(TextItem&& from) noexcept
    : TextItem() {
    *this = ::std::move(from);
  }

  inline TextItem& operator=(const TextItem& from) {
    CopyFrom(from);
    return *this;
  }
  inline TextItem& operator=(TextItem&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const TextItem& default_instance() {
    return *internal_default_instance();
  }
  static inline const TextItem* internal_default_instance() {
    return reinterpret_cast<const TextItem*>(
               &_TextItem_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(TextItem& a, TextItem& b) {
    a.Swap(&b);
  }
  inline void Swap(TextItem* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(TextItem* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  TextItem* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<TextItem>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const TextItem& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const TextItem& from) {
    TextItem::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(TextItem* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "pb.TextItem";
  }
  protected:
  explicit TextItem(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kTextFieldNumber = 1,
    kDeviceFieldNumber = 3,
    kTimeFieldNumber = 2,
  };
  // string Text = 1 [json_name = "Text"];
  void clear_text();
  const std::string& text() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_text(ArgT0&& arg0, ArgT... args);
  std::string* mutable_text();
  PROTOBUF_NODISCARD std::string* release_text();
  void set_allocated_text(std::string* text);
  private:
  const std::string& _internal_text() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_text(const std::string& value);
  std::string* _internal_mutable_text();
  public:

  // string Device = 3 [json_name = "Device"];
  void clear_device();
  const std::string& device() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_device(ArgT0&& arg0, ArgT... args);
  std::string* mutable_device();
  PROTOBUF_NODISCARD std::string* release_device();
  void set_allocated_device(std::string* device);
  private:
  const std::string& _internal_device() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_device(const std::string& value);
  std::string* _internal_mutable_device();
  public:

  // int64 Time = 2 [json_name = "Time"];
  void clear_time();
  int64_t time() const;
  void set_time(int64_t value);
  private:
  int64_t _internal_time() const;
  void _internal_set_time(int64_t value);
  public:

  // @@protoc_insertion_point(class_scope:pb.TextItem)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr text_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr device_;
    int64_t time_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_struct_2eproto;
};
// -------------------------------------------------------------------

class Packet final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:pb.Packet) */ {
 public:
  inline Packet() : Packet(nullptr) {}
  ~Packet() override;
  explicit PROTOBUF_CONSTEXPR Packet(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Packet(const Packet& from);
  Packet(Packet&& from) noexcept
    : Packet() {
    *this = ::std::move(from);
  }

  inline Packet& operator=(const Packet& from) {
    CopyFrom(from);
    return *this;
  }
  inline Packet& operator=(Packet&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Packet& default_instance() {
    return *internal_default_instance();
  }
  static inline const Packet* internal_default_instance() {
    return reinterpret_cast<const Packet*>(
               &_Packet_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(Packet& a, Packet& b) {
    a.Swap(&b);
  }
  inline void Swap(Packet* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Packet* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Packet* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<Packet>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Packet& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const Packet& from) {
    Packet::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Packet* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "pb.Packet";
  }
  protected:
  explicit Packet(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kUIDFieldNumber = 2,
    kDeviceFieldNumber = 3,
    kBodyFieldNumber = 10,
    kCmdFieldNumber = 1,
  };
  // string UID = 2 [json_name = "UID"];
  void clear_uid();
  const std::string& uid() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_uid(ArgT0&& arg0, ArgT... args);
  std::string* mutable_uid();
  PROTOBUF_NODISCARD std::string* release_uid();
  void set_allocated_uid(std::string* uid);
  private:
  const std::string& _internal_uid() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_uid(const std::string& value);
  std::string* _internal_mutable_uid();
  public:

  // string Device = 3 [json_name = "Device"];
  void clear_device();
  const std::string& device() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_device(ArgT0&& arg0, ArgT... args);
  std::string* mutable_device();
  PROTOBUF_NODISCARD std::string* release_device();
  void set_allocated_device(std::string* device);
  private:
  const std::string& _internal_device() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_device(const std::string& value);
  std::string* _internal_mutable_device();
  public:

  // bytes Body = 10 [json_name = "Body"];
  void clear_body();
  const std::string& body() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_body(ArgT0&& arg0, ArgT... args);
  std::string* mutable_body();
  PROTOBUF_NODISCARD std::string* release_body();
  void set_allocated_body(std::string* body);
  private:
  const std::string& _internal_body() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_body(const std::string& value);
  std::string* _internal_mutable_body();
  public:

  // int32 Cmd = 1 [json_name = "Cmd"];
  void clear_cmd();
  int32_t cmd() const;
  void set_cmd(int32_t value);
  private:
  int32_t _internal_cmd() const;
  void _internal_set_cmd(int32_t value);
  public:

  // @@protoc_insertion_point(class_scope:pb.Packet)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr uid_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr device_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr body_;
    int32_t cmd_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_struct_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// TextItem

// string Text = 1 [json_name = "Text"];
inline void TextItem::clear_text() {
  _impl_.text_.ClearToEmpty();
}
inline const std::string& TextItem::text() const {
  // @@protoc_insertion_point(field_get:pb.TextItem.Text)
  return _internal_text();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void TextItem::set_text(ArgT0&& arg0, ArgT... args) {
 
 _impl_.text_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:pb.TextItem.Text)
}
inline std::string* TextItem::mutable_text() {
  std::string* _s = _internal_mutable_text();
  // @@protoc_insertion_point(field_mutable:pb.TextItem.Text)
  return _s;
}
inline const std::string& TextItem::_internal_text() const {
  return _impl_.text_.Get();
}
inline void TextItem::_internal_set_text(const std::string& value) {
  
  _impl_.text_.Set(value, GetArenaForAllocation());
}
inline std::string* TextItem::_internal_mutable_text() {
  
  return _impl_.text_.Mutable(GetArenaForAllocation());
}
inline std::string* TextItem::release_text() {
  // @@protoc_insertion_point(field_release:pb.TextItem.Text)
  return _impl_.text_.Release();
}
inline void TextItem::set_allocated_text(std::string* text) {
  if (text != nullptr) {
    
  } else {
    
  }
  _impl_.text_.SetAllocated(text, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.text_.IsDefault()) {
    _impl_.text_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:pb.TextItem.Text)
}

// int64 Time = 2 [json_name = "Time"];
inline void TextItem::clear_time() {
  _impl_.time_ = int64_t{0};
}
inline int64_t TextItem::_internal_time() const {
  return _impl_.time_;
}
inline int64_t TextItem::time() const {
  // @@protoc_insertion_point(field_get:pb.TextItem.Time)
  return _internal_time();
}
inline void TextItem::_internal_set_time(int64_t value) {
  
  _impl_.time_ = value;
}
inline void TextItem::set_time(int64_t value) {
  _internal_set_time(value);
  // @@protoc_insertion_point(field_set:pb.TextItem.Time)
}

// string Device = 3 [json_name = "Device"];
inline void TextItem::clear_device() {
  _impl_.device_.ClearToEmpty();
}
inline const std::string& TextItem::device() const {
  // @@protoc_insertion_point(field_get:pb.TextItem.Device)
  return _internal_device();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void TextItem::set_device(ArgT0&& arg0, ArgT... args) {
 
 _impl_.device_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:pb.TextItem.Device)
}
inline std::string* TextItem::mutable_device() {
  std::string* _s = _internal_mutable_device();
  // @@protoc_insertion_point(field_mutable:pb.TextItem.Device)
  return _s;
}
inline const std::string& TextItem::_internal_device() const {
  return _impl_.device_.Get();
}
inline void TextItem::_internal_set_device(const std::string& value) {
  
  _impl_.device_.Set(value, GetArenaForAllocation());
}
inline std::string* TextItem::_internal_mutable_device() {
  
  return _impl_.device_.Mutable(GetArenaForAllocation());
}
inline std::string* TextItem::release_device() {
  // @@protoc_insertion_point(field_release:pb.TextItem.Device)
  return _impl_.device_.Release();
}
inline void TextItem::set_allocated_device(std::string* device) {
  if (device != nullptr) {
    
  } else {
    
  }
  _impl_.device_.SetAllocated(device, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.device_.IsDefault()) {
    _impl_.device_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:pb.TextItem.Device)
}

// -------------------------------------------------------------------

// Packet

// int32 Cmd = 1 [json_name = "Cmd"];
inline void Packet::clear_cmd() {
  _impl_.cmd_ = 0;
}
inline int32_t Packet::_internal_cmd() const {
  return _impl_.cmd_;
}
inline int32_t Packet::cmd() const {
  // @@protoc_insertion_point(field_get:pb.Packet.Cmd)
  return _internal_cmd();
}
inline void Packet::_internal_set_cmd(int32_t value) {
  
  _impl_.cmd_ = value;
}
inline void Packet::set_cmd(int32_t value) {
  _internal_set_cmd(value);
  // @@protoc_insertion_point(field_set:pb.Packet.Cmd)
}

// string UID = 2 [json_name = "UID"];
inline void Packet::clear_uid() {
  _impl_.uid_.ClearToEmpty();
}
inline const std::string& Packet::uid() const {
  // @@protoc_insertion_point(field_get:pb.Packet.UID)
  return _internal_uid();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void Packet::set_uid(ArgT0&& arg0, ArgT... args) {
 
 _impl_.uid_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:pb.Packet.UID)
}
inline std::string* Packet::mutable_uid() {
  std::string* _s = _internal_mutable_uid();
  // @@protoc_insertion_point(field_mutable:pb.Packet.UID)
  return _s;
}
inline const std::string& Packet::_internal_uid() const {
  return _impl_.uid_.Get();
}
inline void Packet::_internal_set_uid(const std::string& value) {
  
  _impl_.uid_.Set(value, GetArenaForAllocation());
}
inline std::string* Packet::_internal_mutable_uid() {
  
  return _impl_.uid_.Mutable(GetArenaForAllocation());
}
inline std::string* Packet::release_uid() {
  // @@protoc_insertion_point(field_release:pb.Packet.UID)
  return _impl_.uid_.Release();
}
inline void Packet::set_allocated_uid(std::string* uid) {
  if (uid != nullptr) {
    
  } else {
    
  }
  _impl_.uid_.SetAllocated(uid, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.uid_.IsDefault()) {
    _impl_.uid_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:pb.Packet.UID)
}

// string Device = 3 [json_name = "Device"];
inline void Packet::clear_device() {
  _impl_.device_.ClearToEmpty();
}
inline const std::string& Packet::device() const {
  // @@protoc_insertion_point(field_get:pb.Packet.Device)
  return _internal_device();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void Packet::set_device(ArgT0&& arg0, ArgT... args) {
 
 _impl_.device_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:pb.Packet.Device)
}
inline std::string* Packet::mutable_device() {
  std::string* _s = _internal_mutable_device();
  // @@protoc_insertion_point(field_mutable:pb.Packet.Device)
  return _s;
}
inline const std::string& Packet::_internal_device() const {
  return _impl_.device_.Get();
}
inline void Packet::_internal_set_device(const std::string& value) {
  
  _impl_.device_.Set(value, GetArenaForAllocation());
}
inline std::string* Packet::_internal_mutable_device() {
  
  return _impl_.device_.Mutable(GetArenaForAllocation());
}
inline std::string* Packet::release_device() {
  // @@protoc_insertion_point(field_release:pb.Packet.Device)
  return _impl_.device_.Release();
}
inline void Packet::set_allocated_device(std::string* device) {
  if (device != nullptr) {
    
  } else {
    
  }
  _impl_.device_.SetAllocated(device, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.device_.IsDefault()) {
    _impl_.device_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:pb.Packet.Device)
}

// bytes Body = 10 [json_name = "Body"];
inline void Packet::clear_body() {
  _impl_.body_.ClearToEmpty();
}
inline const std::string& Packet::body() const {
  // @@protoc_insertion_point(field_get:pb.Packet.Body)
  return _internal_body();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void Packet::set_body(ArgT0&& arg0, ArgT... args) {
 
 _impl_.body_.SetBytes(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:pb.Packet.Body)
}
inline std::string* Packet::mutable_body() {
  std::string* _s = _internal_mutable_body();
  // @@protoc_insertion_point(field_mutable:pb.Packet.Body)
  return _s;
}
inline const std::string& Packet::_internal_body() const {
  return _impl_.body_.Get();
}
inline void Packet::_internal_set_body(const std::string& value) {
  
  _impl_.body_.Set(value, GetArenaForAllocation());
}
inline std::string* Packet::_internal_mutable_body() {
  
  return _impl_.body_.Mutable(GetArenaForAllocation());
}
inline std::string* Packet::release_body() {
  // @@protoc_insertion_point(field_release:pb.Packet.Body)
  return _impl_.body_.Release();
}
inline void Packet::set_allocated_body(std::string* body) {
  if (body != nullptr) {
    
  } else {
    
  }
  _impl_.body_.SetAllocated(body, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.body_.IsDefault()) {
    _impl_.body_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:pb.Packet.Body)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace pb

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_struct_2eproto

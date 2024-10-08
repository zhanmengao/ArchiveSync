// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: struct.proto

#include "struct.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG

namespace _pb = ::PROTOBUF_NAMESPACE_ID;
namespace _pbi = _pb::internal;

namespace pb {
PROTOBUF_CONSTEXPR TextItem::TextItem(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.text_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}
  , /*decltype(_impl_.device_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}
  , /*decltype(_impl_.time_)*/int64_t{0}
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct TextItemDefaultTypeInternal {
  PROTOBUF_CONSTEXPR TextItemDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~TextItemDefaultTypeInternal() {}
  union {
    TextItem _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 TextItemDefaultTypeInternal _TextItem_default_instance_;
PROTOBUF_CONSTEXPR Packet::Packet(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.uid_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}
  , /*decltype(_impl_.device_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}
  , /*decltype(_impl_.body_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}
  , /*decltype(_impl_.seqid_)*/int64_t{0}
  , /*decltype(_impl_.sendid_)*/int64_t{0}
  , /*decltype(_impl_.ackid_)*/int64_t{0}
  , /*decltype(_impl_.cmd_)*/0
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct PacketDefaultTypeInternal {
  PROTOBUF_CONSTEXPR PacketDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~PacketDefaultTypeInternal() {}
  union {
    Packet _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 PacketDefaultTypeInternal _Packet_default_instance_;
}  // namespace pb
static ::_pb::Metadata file_level_metadata_struct_2eproto[2];
static constexpr ::_pb::EnumDescriptor const** file_level_enum_descriptors_struct_2eproto = nullptr;
static constexpr ::_pb::ServiceDescriptor const** file_level_service_descriptors_struct_2eproto = nullptr;

const uint32_t TableStruct_struct_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::pb::TextItem, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::pb::TextItem, _impl_.text_),
  PROTOBUF_FIELD_OFFSET(::pb::TextItem, _impl_.time_),
  PROTOBUF_FIELD_OFFSET(::pb::TextItem, _impl_.device_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::pb::Packet, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::pb::Packet, _impl_.cmd_),
  PROTOBUF_FIELD_OFFSET(::pb::Packet, _impl_.uid_),
  PROTOBUF_FIELD_OFFSET(::pb::Packet, _impl_.device_),
  PROTOBUF_FIELD_OFFSET(::pb::Packet, _impl_.seqid_),
  PROTOBUF_FIELD_OFFSET(::pb::Packet, _impl_.sendid_),
  PROTOBUF_FIELD_OFFSET(::pb::Packet, _impl_.ackid_),
  PROTOBUF_FIELD_OFFSET(::pb::Packet, _impl_.body_),
};
static const ::_pbi::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::pb::TextItem)},
  { 9, -1, -1, sizeof(::pb::Packet)},
};

static const ::_pb::Message* const file_default_instances[] = {
  &::pb::_TextItem_default_instance_._instance,
  &::pb::_Packet_default_instance_._instance,
};

const char descriptor_table_protodef_struct_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\014struct.proto\022\002pb\"J\n\010TextItem\022\022\n\004Text\030\001"
  " \001(\tR\004Text\022\022\n\004Time\030\002 \001(\003R\004Time\022\026\n\006Device"
  "\030\003 \001(\tR\006Device\"\234\001\n\006Packet\022\020\n\003Cmd\030\001 \001(\005R\003"
  "Cmd\022\020\n\003UID\030\002 \001(\tR\003UID\022\026\n\006Device\030\003 \001(\tR\006D"
  "evice\022\024\n\005SeqID\030\004 \001(\003R\005SeqID\022\026\n\006SendID\030\005 "
  "\001(\003R\006SendID\022\024\n\005AckID\030\006 \001(\003R\005AckID\022\022\n\004Bod"
  "y\030\n \001(\014R\004Bodyb\006proto3"
  ;
static ::_pbi::once_flag descriptor_table_struct_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_struct_2eproto = {
    false, false, 261, descriptor_table_protodef_struct_2eproto,
    "struct.proto",
    &descriptor_table_struct_2eproto_once, nullptr, 0, 2,
    schemas, file_default_instances, TableStruct_struct_2eproto::offsets,
    file_level_metadata_struct_2eproto, file_level_enum_descriptors_struct_2eproto,
    file_level_service_descriptors_struct_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_struct_2eproto_getter() {
  return &descriptor_table_struct_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_struct_2eproto(&descriptor_table_struct_2eproto);
namespace pb {

// ===================================================================

class TextItem::_Internal {
 public:
};

TextItem::TextItem(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:pb.TextItem)
}
TextItem::TextItem(const TextItem& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  TextItem* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.text_){}
    , decltype(_impl_.device_){}
    , decltype(_impl_.time_){}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  _impl_.text_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.text_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_text().empty()) {
    _this->_impl_.text_.Set(from._internal_text(), 
      _this->GetArenaForAllocation());
  }
  _impl_.device_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.device_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_device().empty()) {
    _this->_impl_.device_.Set(from._internal_device(), 
      _this->GetArenaForAllocation());
  }
  _this->_impl_.time_ = from._impl_.time_;
  // @@protoc_insertion_point(copy_constructor:pb.TextItem)
}

inline void TextItem::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.text_){}
    , decltype(_impl_.device_){}
    , decltype(_impl_.time_){int64_t{0}}
    , /*decltype(_impl_._cached_size_)*/{}
  };
  _impl_.text_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.text_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  _impl_.device_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.device_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
}

TextItem::~TextItem() {
  // @@protoc_insertion_point(destructor:pb.TextItem)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void TextItem::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.text_.Destroy();
  _impl_.device_.Destroy();
}

void TextItem::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void TextItem::Clear() {
// @@protoc_insertion_point(message_clear_start:pb.TextItem)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.text_.ClearToEmpty();
  _impl_.device_.ClearToEmpty();
  _impl_.time_ = int64_t{0};
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* TextItem::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // string Text = 1 [json_name = "Text"];
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          auto str = _internal_mutable_text();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "pb.TextItem.Text"));
        } else
          goto handle_unusual;
        continue;
      // int64 Time = 2 [json_name = "Time"];
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 16)) {
          _impl_.time_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // string Device = 3 [json_name = "Device"];
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 26)) {
          auto str = _internal_mutable_device();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "pb.TextItem.Device"));
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* TextItem::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:pb.TextItem)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // string Text = 1 [json_name = "Text"];
  if (!this->_internal_text().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_text().data(), static_cast<int>(this->_internal_text().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "pb.TextItem.Text");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_text(), target);
  }

  // int64 Time = 2 [json_name = "Time"];
  if (this->_internal_time() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt64ToArray(2, this->_internal_time(), target);
  }

  // string Device = 3 [json_name = "Device"];
  if (!this->_internal_device().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_device().data(), static_cast<int>(this->_internal_device().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "pb.TextItem.Device");
    target = stream->WriteStringMaybeAliased(
        3, this->_internal_device(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:pb.TextItem)
  return target;
}

size_t TextItem::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:pb.TextItem)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string Text = 1 [json_name = "Text"];
  if (!this->_internal_text().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_text());
  }

  // string Device = 3 [json_name = "Device"];
  if (!this->_internal_device().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_device());
  }

  // int64 Time = 2 [json_name = "Time"];
  if (this->_internal_time() != 0) {
    total_size += ::_pbi::WireFormatLite::Int64SizePlusOne(this->_internal_time());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData TextItem::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    TextItem::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*TextItem::GetClassData() const { return &_class_data_; }


void TextItem::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<TextItem*>(&to_msg);
  auto& from = static_cast<const TextItem&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:pb.TextItem)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_text().empty()) {
    _this->_internal_set_text(from._internal_text());
  }
  if (!from._internal_device().empty()) {
    _this->_internal_set_device(from._internal_device());
  }
  if (from._internal_time() != 0) {
    _this->_internal_set_time(from._internal_time());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void TextItem::CopyFrom(const TextItem& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:pb.TextItem)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool TextItem::IsInitialized() const {
  return true;
}

void TextItem::InternalSwap(TextItem* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.text_, lhs_arena,
      &other->_impl_.text_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.device_, lhs_arena,
      &other->_impl_.device_, rhs_arena
  );
  swap(_impl_.time_, other->_impl_.time_);
}

::PROTOBUF_NAMESPACE_ID::Metadata TextItem::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_struct_2eproto_getter, &descriptor_table_struct_2eproto_once,
      file_level_metadata_struct_2eproto[0]);
}

// ===================================================================

class Packet::_Internal {
 public:
};

Packet::Packet(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:pb.Packet)
}
Packet::Packet(const Packet& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  Packet* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.uid_){}
    , decltype(_impl_.device_){}
    , decltype(_impl_.body_){}
    , decltype(_impl_.seqid_){}
    , decltype(_impl_.sendid_){}
    , decltype(_impl_.ackid_){}
    , decltype(_impl_.cmd_){}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  _impl_.uid_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.uid_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_uid().empty()) {
    _this->_impl_.uid_.Set(from._internal_uid(), 
      _this->GetArenaForAllocation());
  }
  _impl_.device_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.device_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_device().empty()) {
    _this->_impl_.device_.Set(from._internal_device(), 
      _this->GetArenaForAllocation());
  }
  _impl_.body_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.body_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_body().empty()) {
    _this->_impl_.body_.Set(from._internal_body(), 
      _this->GetArenaForAllocation());
  }
  ::memcpy(&_impl_.seqid_, &from._impl_.seqid_,
    static_cast<size_t>(reinterpret_cast<char*>(&_impl_.cmd_) -
    reinterpret_cast<char*>(&_impl_.seqid_)) + sizeof(_impl_.cmd_));
  // @@protoc_insertion_point(copy_constructor:pb.Packet)
}

inline void Packet::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.uid_){}
    , decltype(_impl_.device_){}
    , decltype(_impl_.body_){}
    , decltype(_impl_.seqid_){int64_t{0}}
    , decltype(_impl_.sendid_){int64_t{0}}
    , decltype(_impl_.ackid_){int64_t{0}}
    , decltype(_impl_.cmd_){0}
    , /*decltype(_impl_._cached_size_)*/{}
  };
  _impl_.uid_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.uid_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  _impl_.device_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.device_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  _impl_.body_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.body_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
}

Packet::~Packet() {
  // @@protoc_insertion_point(destructor:pb.Packet)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void Packet::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.uid_.Destroy();
  _impl_.device_.Destroy();
  _impl_.body_.Destroy();
}

void Packet::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void Packet::Clear() {
// @@protoc_insertion_point(message_clear_start:pb.Packet)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.uid_.ClearToEmpty();
  _impl_.device_.ClearToEmpty();
  _impl_.body_.ClearToEmpty();
  ::memset(&_impl_.seqid_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&_impl_.cmd_) -
      reinterpret_cast<char*>(&_impl_.seqid_)) + sizeof(_impl_.cmd_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Packet::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // int32 Cmd = 1 [json_name = "Cmd"];
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 8)) {
          _impl_.cmd_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // string UID = 2 [json_name = "UID"];
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 18)) {
          auto str = _internal_mutable_uid();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "pb.Packet.UID"));
        } else
          goto handle_unusual;
        continue;
      // string Device = 3 [json_name = "Device"];
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 26)) {
          auto str = _internal_mutable_device();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "pb.Packet.Device"));
        } else
          goto handle_unusual;
        continue;
      // int64 SeqID = 4 [json_name = "SeqID"];
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 32)) {
          _impl_.seqid_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // int64 SendID = 5 [json_name = "SendID"];
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 40)) {
          _impl_.sendid_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // int64 AckID = 6 [json_name = "AckID"];
      case 6:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 48)) {
          _impl_.ackid_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // bytes Body = 10 [json_name = "Body"];
      case 10:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 82)) {
          auto str = _internal_mutable_body();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* Packet::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:pb.Packet)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // int32 Cmd = 1 [json_name = "Cmd"];
  if (this->_internal_cmd() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt32ToArray(1, this->_internal_cmd(), target);
  }

  // string UID = 2 [json_name = "UID"];
  if (!this->_internal_uid().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_uid().data(), static_cast<int>(this->_internal_uid().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "pb.Packet.UID");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_uid(), target);
  }

  // string Device = 3 [json_name = "Device"];
  if (!this->_internal_device().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_device().data(), static_cast<int>(this->_internal_device().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "pb.Packet.Device");
    target = stream->WriteStringMaybeAliased(
        3, this->_internal_device(), target);
  }

  // int64 SeqID = 4 [json_name = "SeqID"];
  if (this->_internal_seqid() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt64ToArray(4, this->_internal_seqid(), target);
  }

  // int64 SendID = 5 [json_name = "SendID"];
  if (this->_internal_sendid() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt64ToArray(5, this->_internal_sendid(), target);
  }

  // int64 AckID = 6 [json_name = "AckID"];
  if (this->_internal_ackid() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt64ToArray(6, this->_internal_ackid(), target);
  }

  // bytes Body = 10 [json_name = "Body"];
  if (!this->_internal_body().empty()) {
    target = stream->WriteBytesMaybeAliased(
        10, this->_internal_body(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:pb.Packet)
  return target;
}

size_t Packet::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:pb.Packet)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string UID = 2 [json_name = "UID"];
  if (!this->_internal_uid().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_uid());
  }

  // string Device = 3 [json_name = "Device"];
  if (!this->_internal_device().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_device());
  }

  // bytes Body = 10 [json_name = "Body"];
  if (!this->_internal_body().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
        this->_internal_body());
  }

  // int64 SeqID = 4 [json_name = "SeqID"];
  if (this->_internal_seqid() != 0) {
    total_size += ::_pbi::WireFormatLite::Int64SizePlusOne(this->_internal_seqid());
  }

  // int64 SendID = 5 [json_name = "SendID"];
  if (this->_internal_sendid() != 0) {
    total_size += ::_pbi::WireFormatLite::Int64SizePlusOne(this->_internal_sendid());
  }

  // int64 AckID = 6 [json_name = "AckID"];
  if (this->_internal_ackid() != 0) {
    total_size += ::_pbi::WireFormatLite::Int64SizePlusOne(this->_internal_ackid());
  }

  // int32 Cmd = 1 [json_name = "Cmd"];
  if (this->_internal_cmd() != 0) {
    total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(this->_internal_cmd());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData Packet::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    Packet::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*Packet::GetClassData() const { return &_class_data_; }


void Packet::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<Packet*>(&to_msg);
  auto& from = static_cast<const Packet&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:pb.Packet)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_uid().empty()) {
    _this->_internal_set_uid(from._internal_uid());
  }
  if (!from._internal_device().empty()) {
    _this->_internal_set_device(from._internal_device());
  }
  if (!from._internal_body().empty()) {
    _this->_internal_set_body(from._internal_body());
  }
  if (from._internal_seqid() != 0) {
    _this->_internal_set_seqid(from._internal_seqid());
  }
  if (from._internal_sendid() != 0) {
    _this->_internal_set_sendid(from._internal_sendid());
  }
  if (from._internal_ackid() != 0) {
    _this->_internal_set_ackid(from._internal_ackid());
  }
  if (from._internal_cmd() != 0) {
    _this->_internal_set_cmd(from._internal_cmd());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void Packet::CopyFrom(const Packet& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:pb.Packet)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Packet::IsInitialized() const {
  return true;
}

void Packet::InternalSwap(Packet* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.uid_, lhs_arena,
      &other->_impl_.uid_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.device_, lhs_arena,
      &other->_impl_.device_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.body_, lhs_arena,
      &other->_impl_.body_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(Packet, _impl_.cmd_)
      + sizeof(Packet::_impl_.cmd_)
      - PROTOBUF_FIELD_OFFSET(Packet, _impl_.seqid_)>(
          reinterpret_cast<char*>(&_impl_.seqid_),
          reinterpret_cast<char*>(&other->_impl_.seqid_));
}

::PROTOBUF_NAMESPACE_ID::Metadata Packet::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_struct_2eproto_getter, &descriptor_table_struct_2eproto_once,
      file_level_metadata_struct_2eproto[1]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace pb
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::pb::TextItem*
Arena::CreateMaybeMessage< ::pb::TextItem >(Arena* arena) {
  return Arena::CreateMessageInternal< ::pb::TextItem >(arena);
}
template<> PROTOBUF_NOINLINE ::pb::Packet*
Arena::CreateMaybeMessage< ::pb::Packet >(Arena* arena) {
  return Arena::CreateMessageInternal< ::pb::Packet >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>

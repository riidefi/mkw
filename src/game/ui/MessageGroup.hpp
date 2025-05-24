#pragma once

#include <rk_types.h>

namespace UI {

class MessageGroup {
public:
  MessageGroup();

  ~MessageGroup();

  void load(const char* filename);

  void load(const void* file);

  s32 getSlot(u32 messageId) const;

  const wchar_t* getMessage(s32 slot);

  const u8* getAttributes(s32 slot);

private:
  struct Header {
    u32 signature;
    u32 dataType;
    u32 dataSize;
    u32 numBlocks;
    u8 charset;
    u8 _pad[0xf];
  };

  struct Block {
    u32 kind;
    u32 size;
    u8 data[];
  };

  enum BlockKind {
    BLOCK_KIND_INF = 0x494e4631,
    BLOCK_KIND_DAT = 0x44415431,
    BLOCK_KIND_STR = 0x53545231,
    BLOCK_KIND_MID = 0x4d494431
  };

  struct Entry {
    u32 offset;
    u8 attributes;
    u8 _pad[0x3];
  };

  struct Inf {
    u16 numEntries;
    u16 entrySize;
    u16 groupID;
    u8 defaultColor;
    u8 _pad[0x1];
    Entry entries[];
  };

  struct Mid {
    u16 numEntries;
    u8 format;
    u8 info;
    u8 _pad[0x4];
    u32 messageIds[];
  };

  const Header* mHeader;
  const Inf* mInf;
  const wchar_t* mDat;
  const void* mStr;
  const Mid* mMid;
};

} // namespace UI

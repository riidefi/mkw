// Source:
// https://github.com/doldecomp/ogws/blob/82dbeac2267170fc5cef7e67a6d8c31c5ff45d69/include/nw4r/g3d/g3d_rescommon.h
// Decompiled by kiwi515, GibHaltmannKill.

#pragma once

#include <rk_types.h>

#define NW4R_G3D_CREATE_RES_NAME_DATA(VAR, VAL)                                \
  ResNameData ResNameData_##VAR = {sizeof(VAL) - 1, VAL}

#define FIFO_ACCESS_BP 0x61
#define FIFO_ACCESS_CP 0x8
#define FIFO_ACCESS_XF 0x10

namespace nw4r {
namespace g3d {

template <typename T> class ResCommon {
  T* mPtr;

public:
  inline ResCommon(void* vptr) : mPtr(static_cast<T*>(vptr)) {}
  inline ResCommon(const void* vptr) : mPtr(static_cast<T*>(vptr)) {}

  inline T& ref() const { return *mPtr; }
  inline T* ptr() const { return mPtr; }
  inline bool IsValid() const { return mPtr; }

  template <typename TPtr> inline const TPtr* ofs_to_ptr_raw(s32 ofs) const {
    return (const TPtr*)((u8*)mPtr + ofs);
  }

  template <typename TPtr> inline TPtr* ofs_to_ptr(s32 ofs) {
    if (ofs)
      return (TPtr*)((u8*)mPtr + ofs);

    return NULL;
  }

  template <typename TPtr> inline const TPtr* ofs_to_ptr(s32 ofs) const {
    if (ofs)
      return (const TPtr*)((u8*)mPtr + ofs);

    return NULL;
  }

  template <typename TObj> inline TObj ofs_to_obj(s32 ofs) const {
    if (ofs)
      return (u8*)mPtr + ofs;

    return NULL;
  }
};

struct ResNameData {
  u32 mLength;
  char mName[0x1C];
};

struct ResName {
  ResCommon<const ResNameData> mRes;

  inline ResName(const void* vptr) : mRes(vptr) {}

  inline u32 GetLength() const { return mRes.ref().mLength; }

  inline const char* GetName() const { return mRes.ref().mName; }

  bool operator==(ResName) const;
};

struct ResBlockHeaderData
{
  char kind[4];
  u32  size;
};

namespace detail {
typedef u8 CPCmd[6];
typedef u8 BPCmd[5];

inline void ResWrite_u8(u8* res, u8 arg) { *res = arg; }

inline void ResWrite_u16(u8* res, u16 arg) {
  ResWrite_u8(res + 0, arg >> 8);
  ResWrite_u8(res + 1, arg >> 0);
}

inline void ResWrite_u32(u8* res, u32 arg) {
  ResWrite_u8(res + 0, arg >> 24);
  ResWrite_u8(res + 1, arg >> 16);
  ResWrite_u8(res + 2, arg >> 8);
  ResWrite_u8(res + 3, arg >> 0);
}

inline u8 ResRead_u8(const u8* res) { return *res; }

inline u32 ResRead_u32(const u8* res) {
  int ret = ResRead_u8(res) << 24;
  ret |= ResRead_u8(res + 1) << 16;
  ret |= ResRead_u8(res + 2) << 8;
  ret |= ResRead_u8(res + 3);
  return ret;
}

inline void ResReadBPCmd(const u8* res, u32* out) {
  *out = ResRead_u32(res + 1);
}

inline void ResReadCPCmd(const u8* res, u32* out) {
  *out = ResRead_u32(res + 2);
}

void ResWriteBPCmd(u8*, u32);
void ResWriteBPCmd(u8*, u32, u32);
void ResWriteCPCmd(u8*, u8, u32);
void ResWriteXFCmd(u8*, u16, u32);
void ResWriteSSMask(u8*, u32);

} // namespace detail
} // namespace g3d
} // namespace nw4r

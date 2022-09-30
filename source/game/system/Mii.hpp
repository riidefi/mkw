#pragma once

#include <string.h>

#include <rk_types.h>

namespace System {

class RawMii {
public:
  void reset() { memset(mBuffer, 0, sizeof(mBuffer)); }

private:
  u8 mBuffer[0x4c];
};

struct unkStruct {
  u8 x0;
  u8 x1;
  u8 x2;
  u8 x3;
};

struct MiiId {
  u8 _00[0x8 - 0x0];
};

class Mii {
public:
  Mii(s32 num) { init(num); }
  virtual ~Mii();
  void init(s32);
  s32 _4;
  u8 _8;
  s8 _9;
  s32 _C;
  RawMii mRaw;
  s32 _5C;
  unkStruct _60;
  u32 _64;
  u32 _68[15];
  u8 _A4;
  u8 _A5;
  u8 _A6;
  u32 _A8;
  u8 _AC;
  u8 _AD;
  u8 _AE;
  u32 _B0;
  u32 _B4;
};

inline Mii::~Mii() {}

} // namespace System

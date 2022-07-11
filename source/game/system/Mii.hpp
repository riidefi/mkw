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

class Mii {
public:
  Mii(s32 num) { init(num); }
  virtual ~Mii();
  void init(s32);
  s32 _4;
  u8 _8;
  s8 _9;
  s32 _C;
  unk8 _10[0x60 - 0x10];
  unkStruct _60;
  s32 _64;
  u8 _68[0xa4 - 0x68];
  u8 _A4;
  u8 _A5;
  u8 _A6;
  unk8 _[0xb8 - 0xA7];
};

} // namespace System

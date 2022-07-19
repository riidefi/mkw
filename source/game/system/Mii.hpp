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
  unk32 _5C;
  unkStruct _60; // almost certainly a color struct
  s32 _64;
  char mName[20];
  unk32 _7C;
  unk32 _80;
  unk32 _84;
  unk32 _88;
  unk32 _8C;
  unk32 _90;
  MiiId mId;
  unk32 _9C;
  unk32 _A0;
  u8 _A4;
  u8 _A5;
  u8 _A6;
  unk32 _A8;
  unk8 _AC;
  unk8 _AD;
  unk8 _AE;
  unk32 _B0;
  unk32 _B4;
};

} // namespace System

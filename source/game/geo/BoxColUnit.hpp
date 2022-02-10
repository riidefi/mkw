#pragma once

#include <egg/math/eggVector.hpp>

enum BoxColFlag {
  BOXCOL_FLAG_DRIVER = 0x1,
  BOXCOL_FLAG_ITEM = 0x2,
  BOXCOL_FLAG_4 = 0x4,
  BOXCOL_FLAG_8 = 0x8,
  BOXCOL_FLAG_OBJECT = 0xC,
  BOXCOL_FLAG_DRIVABLE = 0x10,
  BOXCOL_FLAG_100 = 0x100,
  BOXCOL_FLAG_DISABLED = 0x200,
  BOXCOL_FLAG_STATIC = 0x400,
  BOXCOL_FLAG_800 = 0x800,
};

struct BoxColUnit {
  BoxColUnit();
  ~BoxColUnit();

  void set(const EGG::Vector3f* pos, u32 flags, void* userData, float radius,
           float thickness);
  void makeDynamic();
  void resizeSphere(float radius, float thickness);

  void _80786F98();
  void _80786FA8();

  /*
  MKDS:
    s16 segmentRightEndpoint;
    s16 segmentLeftEndpoint;
    fx32 zMax;
    fx32 zMin;
    const VecFx32* position;
    fx32 boundingSphereRadius;
    u16 flags;
    void* object;
  */
  const EGG::Vector3f* position;
  f32 radius;
  f32 range;
  u32 flags; // Value of BoxColFlag
  void* userData;
  u16 rightPointID;
  u16 leftPointID;
  f32 xMax;
  f32 xMin;
};

#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x8081b500..0x8081b5a8
UNKNOWN_FUNCTION(unk_8081b500);
// PAL: 0x8081b5a8..0x8081b618
UNKNOWN_FUNCTION(unk_8081b5a8);
// PAL: 0x8081b618..0x8081b6c8
UNKNOWN_FUNCTION(unk_8081b618);
// PAL: 0x8081b6c8..0x8081b7cc
UNKNOWN_FUNCTION(ObjectKclManager_push);
// PAL: 0x8081b7cc..0x8081b870
UNKNOWN_FUNCTION(unk_8081b7cc);
// PAL: 0x8081b870..0x8081b940
UNKNOWN_FUNCTION(unk_8081b870);
// PAL: 0x8081b940..0x8081ba10
UNKNOWN_FUNCTION(unk_8081b940);
// PAL: 0x8081ba10..0x8081bb54
UNKNOWN_FUNCTION(unk_8081ba10);
// PAL: 0x8081bb54..0x8081bc98
UNKNOWN_FUNCTION(unk_8081bb54);
// PAL: 0x8081bc98..0x8081bd70
UNKNOWN_FUNCTION(unk_8081bc98);
// PAL: 0x8081bd70..0x8081be48
UNKNOWN_FUNCTION(unk_8081bd70);
// PAL: 0x8081be48..0x8081bfa0
UNKNOWN_FUNCTION(unk_8081be48);
// PAL: 0x8081bfa0..0x8081c0f8
UNKNOWN_FUNCTION(unk_8081bfa0);
// PAL: 0x8081c0f8..0x8081c1e8
UNKNOWN_FUNCTION(unk_8081c0f8);
// PAL: 0x8081c1e8..0x8081c2d8
UNKNOWN_FUNCTION(unk_8081c1e8);
// PAL: 0x8081c2d8..0x8081c43c
UNKNOWN_FUNCTION(unk_8081c2d8);
// PAL: 0x8081c43c..0x8081c5a0
UNKNOWN_FUNCTION(unk_8081c43c);
// PAL: 0x8081c5a0..0x8081c6b4
UNKNOWN_FUNCTION(unk_8081c5a0);
// PAL: 0x8081c6b4..0x8081c7c8
UNKNOWN_FUNCTION(unk_8081c6b4);
// PAL: 0x8081c7c8..0x8081c958
UNKNOWN_FUNCTION(unk_8081c7c8);
// PAL: 0x8081c958..0x8081cae8
UNKNOWN_FUNCTION(unk_8081c958);

#ifdef __cplusplus
}
#endif

#include "game/geo/ObjDrivable.hpp"

namespace GeoObj {
class ObjDrivableHolder {
public:
  static ObjDrivableHolder* spInstance;
  static ObjDrivableHolder* createInstance();
  static void destroyInstance();

  ObjDrivableHolder();
  virtual ~ObjDrivableHolder();

  void initObjs();
  /// Draws debug shapes for objects if the need to. Unused, but potentially used during development, since some objects implement such functionallity
  /// (for example ObakeBlock). It would be interesting to see what those drawings look like
  void debugDraw();
  /// Updates all objects if the need to
  void update();
  /// Adds drivable to list
  s32 push(ObjDrivable* obj);

private:
  u16 objCount;
  ObjDrivable** objs;
  u16 needUpdateCount;
  ObjDrivable** needUpdate;
  u16 drawDebugCount;
  ObjDrivable** drawDebug;
  u32 _1c;
};
}

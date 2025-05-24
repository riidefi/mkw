#pragma once

#include <rk_types.h>

#include <decomp.h>


extern "C" {
// PAL: 0x802166f4
extern UNKNOWN_FUNCTION(createStaticInstance__Q23EGG17CoreControllerMgrFv);
// PAL: 0x80216dbc
extern UNKNOWN_FUNCTION(beginFrame__Q23EGG17CoreControllerMgrFv);
// PAL: 0x80216e64
extern UNKNOWN_FUNCTION(endFrame__Q23EGG17CoreControllerMgrFv);
// PAL: 0x8021709c
extern UNKNOWN_FUNCTION(createStaticInstance__Q23EGG15GCControllerMgrFv);
// PAL: 0x802173e8
extern UNKNOWN_FUNCTION(calc__Q23EGG15GCControllerMgrFv);
// PAL: 0x80386dd0
extern UNKNOWN_DATA(spInstance__Q23EGG17CoreControllerMgr);
// PAL: 0x80386de4
extern UNKNOWN_DATA(spInstance__Q23EGG15GCControllerMgr);
}

namespace EGG {

class CoreControllerMgr {
public:
  static CoreControllerMgr* spInstance;

public:
  static void createStaticInstance();

public:
  u32 _00;
  u32 _04;
  u32 _08;
  u32 _0c;

public:
  virtual void beginFrame();                      // [vt+0x08]
  virtual void endFrame();                        // [vt+0x0c]
};

class GCControllerMgr {
public:
  static GCControllerMgr* spInstance;

public:
  static void createStaticInstance();

public:
  void calc();
};
} // namespace EGG

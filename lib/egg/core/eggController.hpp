#pragma once

#include <rk_types.h>

#include <decomp.h>

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

#pragma once

#include <rk_types.h>

#include <decomp.h>

namespace EGG {

class SimpleAudioMgr {
public:
  SimpleAudioMgr();
  ~SimpleAudioMgr();

public:
  virtual void initialize();                      // [vt+0x08]
  virtual void calc();                            // [vt+0x0c]

public:
  u8 _04[0x6b8];
};

static_assert(sizeof(SimpleAudioMgr) == 0x6bc);
} // namespace EGG

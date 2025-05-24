#pragma once

#include <rk_types.h>

#include <decomp.h>


extern "C" {
// PAL: 0x8021329c
UNKNOWN_FUNCTION(__ct__Q23EGG14SimpleAudioMgrFv);
// PAL: 0x802133d4
UNKNOWN_FUNCTION(__dt__Q23EGG14SimpleAudioMgrFv);
// PAL: 0x8021347c
UNKNOWN_FUNCTION(initialize__Q23EGG14SimpleAudioMgrFv);
// PAL: 0x802135d0
UNKNOWN_FUNCTION(calc__Q23EGG14SimpleAudioMgrFv);
}

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

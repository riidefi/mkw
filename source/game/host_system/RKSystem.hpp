/*!
 * @file RKSystem.hpp
 * @brief
 */

#pragma once

#ifndef RKSYS_IMPL

#include <rk_types.h>

#include <decomp.h>

#include <egg/core/eggAsyncDisplay.hpp>
#include <egg/core/eggSystem.hpp>
#include <game/host_system/RKSceneManager.hpp>

namespace System {

class RKSystem : EGG::BaseSystem {
public:
  static RKSystem* spInstance;
  static RKSystem sInstance;

  u8 _24[0x28];
  EGG::AsyncDisplay* mAsyncDisplay;
  u32 _50;
  RKSceneManager* mSceneMgr;
};
} // namespace System
#else

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x80008e84..0x80008e90
UNKNOWN_FUNCTION(RKSystem_getStaticInstance);
// PAL: 0x80008e90..0x80008eb0
UNKNOWN_FUNCTION(unk_80008e90);
// PAL: 0x80008eb0..0x80008ef0
UNKNOWN_FUNCTION(unk_80008eb0);
// PAL: 0x80008ef0..0x80008fac
UNKNOWN_FUNCTION(RKSystem_main);
// PAL: 0x80008fac..0x80008fb4
UNKNOWN_FUNCTION(RKSystem_getSysHeap);
// PAL: 0x80008fb4..0x80009190
UNKNOWN_FUNCTION(TSystem_initialize);
// PAL: 0x80009190..0x80009194
UNKNOWN_FUNCTION(unk_80009190);
// PAL: 0x80009194..0x8000951c
UNKNOWN_FUNCTION(RKSystem_initialize);
// PAL: 0x8000951c..0x80009818
UNKNOWN_FUNCTION(RKSystem_run);
// PAL: 0x80009818..0x80009820
UNKNOWN_FUNCTION(RKSystem_getDisplay);
// PAL: 0x80009820..0x80009824
UNKNOWN_FUNCTION(unk_80009820);
// PAL: 0x80009824..0x80009828
UNKNOWN_FUNCTION(unk_80009824);
// PAL: 0x80009828..0x80009830
UNKNOWN_FUNCTION(RKSystem_getSceneManager);
// PAL: 0x80009830..0x80009844
UNKNOWN_FUNCTION(RKSystem_getPerformanceView);
// PAL: 0x80009844..0x8000984c
UNKNOWN_FUNCTION(RkSceneManager_changeSceneWithCreator);
// PAL: 0x8000984c..0x80009984
UNKNOWN_FUNCTION(RKSceneManager_calcCurrentFader);
// PAL: 0x80009984..0x80009988
UNKNOWN_FUNCTION(RkSceneManager_calc);
// PAL: 0x80009988..0x8000998c
UNKNOWN_FUNCTION(RkSceneManager_draw);
// PAL: 0x8000998c..0x8000999c
UNKNOWN_FUNCTION(unk_8000998c);
// PAL: 0x8000999c..0x800099ac
UNKNOWN_FUNCTION(unk_8000999c);
// PAL: 0x800099ac..0x800099b4
UNKNOWN_FUNCTION(BaseSystem_getVideo);
// PAL: 0x800099b4..0x800099bc
UNKNOWN_FUNCTION(BaseSystem_getSysHeap);
// PAL: 0x800099bc..0x800099c4
UNKNOWN_FUNCTION(RKSystem_getXfbManager);
// PAL: 0x800099c4..0x800099cc
UNKNOWN_FUNCTION(RKSystem_getAudioManager);
// PAL: 0x800099cc..0x80009b40
UNKNOWN_FUNCTION(unk_800099cc);
// PAL: 0x80009b40..0x80009b80
UNKNOWN_FUNCTION(__dt__Q23EGG8Vector3fFv);
// PAL: 0x80009b80..0x80009bc0
UNKNOWN_FUNCTION(__dt__Q23EGG8Vector2fFv);

#ifdef __cplusplus
}
#endif

#endif

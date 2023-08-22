/*!
 * @file RKSystem.hpp
 * @brief
 */

#pragma once

#include <rk_types.h>

#include <decomp.h>

#include <egg/core/eggAllocator.hpp>
#include <egg/core/eggSceneManager.hpp>
#include <egg/core/eggSystem.hpp>


#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x80008e84..0x80008e90
UNKNOWN_FUNCTION(getStaticInstance__Q26System8RKSystemFv);
// PAL: 0x80008ef0..0x80008fac
UNKNOWN_FUNCTION(main__Q26System8RKSystemFiPPc);
// PAL: 0x80008fac..0x80008fb4
UNKNOWN_FUNCTION(getSysHeap__Q26System8RKSystemFv);
// PAL: 0x80008fb4..0x80009190
UNKNOWN_FUNCTION(initialize__Q23EGG10BaseSystemFv);
// PAL: 0x80009190..0x80009194
UNKNOWN_FUNCTION(initRenderMode__Q23EGG10BaseSystemFv);
// PAL: 0x80009194..0x8000951c
UNKNOWN_FUNCTION(initialize__Q26System8RKSystemFv);
// PAL: 0x8000951c..0x80009818
UNKNOWN_FUNCTION(run__Q26System8RKSystemFv);
// PAL: 0x80009818..0x80009820
UNKNOWN_FUNCTION(getDisplay__Q23EGG10BaseSystemFv);
// PAL: 0x80009820..0x80009824
UNKNOWN_FUNCTION(onBeginFrame__Q23EGG10BaseSystemFv);
// PAL: 0x80009824..0x80009828
UNKNOWN_FUNCTION(onEndFrame__Q23EGG10BaseSystemFv);
// PAL: 0x80009828..0x80009830
UNKNOWN_FUNCTION(getSceneManager__Q23EGG10BaseSystemFv);
// PAL: 0x80009830..0x80009844
UNKNOWN_FUNCTION(getPerformanceView__Q23EGG10BaseSystemFv);
// PAL: 0x800099ac..0x800099b4
UNKNOWN_FUNCTION(getVideo__Q23EGG10BaseSystemFv);
// PAL: 0x800099b4..0x800099bc
UNKNOWN_FUNCTION(getSysHeap__Q23EGG10BaseSystemFv);
// PAL: 0x800099bc..0x800099c4
UNKNOWN_FUNCTION(getXfbManager__Q23EGG10BaseSystemFv);
// PAL: 0x800099c4..0x800099cc
UNKNOWN_FUNCTION(getAudioManager__Q23EGG10BaseSystemFv);
// PAL: 0x800099cc..0x80009b40
UNKNOWN_FUNCTION(__sinit__RKSystem_cpp);
// PAL: 0x80009b40..0x80009b80
UNKNOWN_FUNCTION(__dt__Q23EGG8Vector3fFv);
// PAL: 0x80009b80..0x80009bc0
UNKNOWN_FUNCTION(__dt__Q23EGG8Vector2fFv);

#ifdef __cplusplus
}
#endif

namespace System {

// vtable @ 80270c68
class RKSceneManager : public EGG::SceneManager {
public:
  RKSceneManager(EGG::SceneCreator* creator)
    : EGG::SceneManager(creator) {}

  void calc() override;                                   // [vt+0x08]
  void draw() override;                                   // [vt+0x0c]
  void calcCurrentFader() override;                       // [vt+0x14]

  virtual void doCalcFader();                             // [vt+0x24]
  virtual void doDrawFader();                             // [vt+0x28]

  inline void changeSceneWithCreator(int sceneID);

  void changeSceneWithCreatorAfterFadeOut(int id, EGG::SceneCreator* creator);

  EGG::SceneCreator* mNextSceneCreator;                   // [this+0x2c]
};

// vtable @ 80270bf0
class RKSystem : public EGG::BaseSystem {
public:
  static RKSystem* spInstance;
  static RKSystem sInstance;

public:
  static RKSystem* getStaticInstance();

  static void main(int argc, char** argv);

public:
  inline RKSystem() : EGG::BaseSystem(), mFrameClock(true), _69(false) {}

  EGG::Heap* getSysHeap() override;                       // [vt+0x0c]

  void run() override;                                    // [vt+0x34]
  void initialize() override;                             // [vt+0x38]

  inline void beginFrame();
  inline void endFrame();

  inline void draw();
  inline void calc();

public:
  EGG::Heap* mWPADHeap;                                   // [this+0x58]
  EGG::Allocator* mWPADAllocator;                         // [this+0x5c]
  EGG::Heap* mModuleHeap;                                 // [this+0x60]
  EGG::Heap* mSysHeap2;                                   // [this+0x64]
  volatile bool mFrameClock;                              // [this+0x68]
  bool _69;
  bool _6a;
  bool _6b;
  volatile bool _6c;
  u8 _6d;
  u8 _6e;
  u8 _6f;
  void* mVFMem;                                           // [this+0x70]
};
} // namespace System

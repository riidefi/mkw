/*!
 * @file RKSystem.hpp
 * @brief
 */

#pragma once

#include <rk_types.h>

#include <decomp.h>

#include <egg/audio/eggAudioMgr.hpp>
#include <egg/core/eggAllocator.hpp>
#include <egg/core/eggAsyncDisplay.hpp>
#include <egg/core/eggController.hpp>
#include <egg/core/eggDvdFile.hpp>
#include <egg/core/eggGraphicsFifo.hpp>
#include <egg/core/eggProcessMeter.hpp>
#include <egg/core/eggSceneManager.hpp>
#include <egg/core/eggSystem.hpp>
#include <egg/core/eggXfb.hpp>
#include <egg/core/eggXfbManager.hpp>
#include <egg/core/eggVideo.hpp>

namespace System {

// vtable @ 80270c68
class RKSceneManager : public EGG::SceneManager {
public:
  RKSceneManager(EGG::SceneCreator* creator) : EGG::SceneManager(creator) {}

  void calc() override;                                   // [vt+0x08]
  void draw() override;                                   // [vt+0x0c]
  void calcCurrentFader() override;                       // [vt+0x14]

  virtual void doCalcFader();                             // [vt+0x24]
  virtual void doDrawFader();                             // [vt+0x28]

  inline void changeSceneWithCreator(int sceneID);

  void changeSceneWithCreatorAfterFadeOut(int id, EGG::SceneCreator* creator);

public:
  EGG::SceneCreator* mNextSceneCreator;                   // [this+0x2c]
};

typedef EGG::TSystem<EGG::Video, EGG::AsyncDisplay, EGG::XfbManager,
                     EGG::SimpleAudioMgr, RKSceneManager,
                     EGG::ProcessMeter> RKSystemTemplate;

// vtable @ 80270bf0
class RKSystem : public RKSystemTemplate {
public:
  static RKSystem* spInstance;
  static RKSystem sInstance;

public:
  static RKSystem* getStaticInstance();

  static void main(int argc, char** argv);

public:
  inline RKSystem() : RKSystemTemplate(), mFrameClock(true), _69(false) {}

  // Uncomment out this inline definition when enabling WIP_DECOMP
  EGG::Heap* getSysHeap() override;// { return mSysHeap2; }  // [vt+0x0c]

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

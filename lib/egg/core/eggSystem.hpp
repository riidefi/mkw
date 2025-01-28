/*!
 * @file BaseSystem.hpp
 * @brief
 */

#pragma once

#include <rk_types.h>

#include <decomp.h>

#include <rvl/dvd.h>
#include <rvl/sc.h>

struct GXRenderModeObj;

namespace EGG {

class Display;
class Heap;
class PerformanceView;
class SceneManager;
class SimpleAudioMgr;
class Thread;
class Video;
class XfbManager;

class BaseSystem {
public:
  static BaseSystem* sSystem;

public:
  inline BaseSystem()
    : mSysHeapSize(0x177000),
      mGraphicsFifoSize(0x80000),
      mRenderMode(nullptr) {}

  //! @brief [vt+0x08] Return a pointer to the video manager.
  //!
  virtual Video* getVideo() = 0;

  //! @brief [vt+0x0c] Return a pointer to the system heap.
  //!
  virtual Heap* getSysHeap() = 0;

  //! @brief [vt+0x10] Return a pointer to the display manager.
  //!
  virtual Display* getDisplay() = 0;

  //! @brief [vt+0x14] Return a pointer to the Xfb manager.
  //!
  virtual XfbManager* getXfbMgr() = 0;

  //! @brief [vt+0x18] Return a pointer to the performance view.
  //!
  virtual PerformanceView* getPerfView() = 0;

  //! @brief [vt+0x1c] Return a pointer to the scene manager.
  //!
  virtual SceneManager* getSceneMgr() = 0;

  //! @brief [vt+0x20] Return a pointer to the audio manager.
  //!
  virtual SimpleAudioMgr* getAudioMgr() = 0;

  //! @brief [vt+0x24] Called before every frame.
  //!
  virtual void onBeginFrame();

  //! @brief [vt+0x28] Called on every frame end.
  //!
  virtual void onEndFrame();

  //! @brief [vt+0x2c] Initialize the render mode.
  //!
  virtual void initRenderMode();

  //! @brief [vt+0x30] Initialize the system memory.
  //!
  virtual void initMemory();

  //! @brief [vt+0x34] Main game loop.
  //!
  virtual void run();

  //! @brief [vt+0x38] Initialize the system.
  //!
  virtual void initialize() = 0;

public:
  void* mMEM1ArenaLo;                             // [this+0x04]
  void* mMEM1ArenaHi;                             // [this+0x08]
  void* mMEM2ArenaLo;                             // [this+0x0c]
  void* mMEM2ArenaHi;                             // [this+0x10]
  u32 mMemorySize;                                // [this+0x14]
  Heap* mRootHeapMem1;                            // [this+0x18]
  Heap* mRootHeapMem2;                            // [this+0x1c]
  Heap* mRootHeapDebug;                           // [this+0x20]
  Heap* mSysHeap;                                 // [this+0x24]
  Thread* mThread;                                // [this+0x28]
  void* _2c;
  void* _30;
  u32 mSysHeapSize;                               // [this+0x34]
  u32 mGraphicsFifoSize;                          // [this+0x38]
  GXRenderModeObj* mRenderMode;                   // [this+0x3c]
};

template <class tVideo, class tDisplay, class tXfbMgr, class tAudioMgr,
          class tSceneMgr, class tPerfView>
class TSystem : public BaseSystem {
public:
  inline TSystem() : BaseSystem() {}

  Video* getVideo() override { return static_cast<Video*>(mVideo); }

  Heap* getSysHeap() override { return mSysHeap; }

  Display* getDisplay() override { return static_cast<Display*>(mDisplay); }

  XfbManager* getXfbMgr() override {
    return static_cast<XfbManager*>(mXfbMgr);
  }

  PerformanceView* getPerfView() override {
    return static_cast<PerformanceView*>(mPerfView);
  }

  SceneManager* getSceneMgr() override {
    return static_cast<SceneManager*>(mSceneMgr);
  }

  SimpleAudioMgr* getAudioMgr() override {
    return static_cast<SimpleAudioMgr*>(mAudioMgr);
  }

  void onBeginFrame() override {}
  void onEndFrame() override {}

  void initRenderMode() override {}

  void initialize() override {
    DVDInit();
    SCInit();

    initMemory();
    initRenderMode();

    GraphicsFifo::create(mGraphicsFifoSize, nullptr);

    mVideo = new tVideo(mRenderMode, nullptr);

    mXfbMgr = new tXfbMgr(nullptr);
    for (int i = 0; i < 2; ++i) {
      mXfbMgr->attach(new Xfb(mRootHeapMem2));
    }

    mDisplay = new tDisplay(1);

    Thread::initialize();
    mThread = new Thread(OSGetCurrentThread(), 4);

    mPerfView = new tPerfView(true);

    DvdFile::initialize();

    CoreControllerMgr::createStaticInstance();
    GCControllerMgr::createStaticInstance();

    Exception_create(0x40, 0x20, 4, nullptr, 1);

    mSceneMgr = new tSceneMgr(nullptr);
      
    mRootHeapMem1->becomeCurrentHeap();

    mAudioMgr = new tAudioMgr();
  }

public:
  tAudioMgr* mAudioMgr;                         // [this+0x40]
  tVideo* mVideo;                               // [this+0x44]
  tXfbMgr* mXfbMgr;                             // [this+0x48]
  tDisplay* mDisplay;                           // [this+0x4c]
  tPerfView* mPerfView;                         // [this+0x50]
  tSceneMgr* mSceneMgr;                         // [this+0x54]
};
} // namespace EGG

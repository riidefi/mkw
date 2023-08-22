/*!
 * @file BaseSystem.hpp
 * @brief
 */

#pragma once

#include <rk_types.h>

#include <decomp.h>

#include <egg/core/eggProcessMeter.hpp>


struct GXRenderModeObj;

namespace EGG {

class AudioManager; // TODO: make AudioManager header
class Display;
class Heap;
class PerformanceView;
class ProcessMeter;
class SceneManager;
class Thread;
class Video;
class XfbManager;

class BaseSystem {
public:
  static BaseSystem* sSystem;

public:
  inline BaseSystem()
    : mSysHeapSize(0x177000), mGraphicsFifoSize(0x80000),
      mRenderMode(nullptr) {}

  //! @brief [vt+0x08] Return a pointer to the video manager.
  //!
  virtual Video* getVideo();// { return mVideo; }

  //! @brief [vt+0x0c] Return a pointer to the system heap.
  //!
  virtual Heap* getSysHeap();// { return mSysHeap; }

  //! @brief [vt+0x10] Return a pointer to the display manager.
  //!
  virtual Display* getDisplay() { return mDisplay; }

  //! @brief [vt+0x14] Return a pointer to the Xfb manager.
  //!
  virtual XfbManager* getXfbManager();// { return mXfbMgr; }

  //! @brief [vt+0x18] Return a pointer to the performance view.
  //!
  virtual PerformanceView* getPerformanceView() {
    return static_cast<PerformanceView*>(mProcessMeter);
  }

  //! @brief [vt+0x1c] Return a pointer to the scene manager.
  //!
  virtual SceneManager* getSceneManager() { return mSceneMgr; }

  //! @brief [vt+0x20] Return a pointer to the audio manager.
  //!
  virtual AudioManager* getAudioManager();// { return mAudioMgr; }

  //! @brief [vt+0x24] Called by `run` at the beginning of every frame right
  //! after calling `beginFrame` on the display.
  //!
  virtual void onBeginFrame() {}

  //! @brief [vt+0x24] Called by `run` at the end of every frame right after
  //! calling `endFrame` on the display.
  //!
  virtual void onEndFrame() {}

  virtual void initRenderMode();                  // [vt+0x2c]
  virtual void initMemory();                      // [vt+0x30]

  virtual void run();                             // [vt+0x34]
  virtual void initialize();                      // [vt+0x38]

public:
  void* mMEM1ArenaLo;                             // [this+0x04]
  void* mMEM1ArenaHi;                             // [this+0x08]
  void* mMEM2ArenaLo;                             // [this+0x0c]
  void* mMEM2ArenaHi;                             // [this+0x10]
  u32 _14;
  Heap* mRootHeapMem1;                            // [this+0x18]
  Heap* mRootHeapMem2;                            // [this+0x1c]
  Heap* mRootHeapDebug;                           // [this+0x20]
  Heap* mSysHeap;                                 // [this+0x24]
  Thread* mThread;                                // [this+0x28]
  u32 _2c;
  u32 _30;
  u32 mSysHeapSize;                               // [this+0x34]
  u32 mGraphicsFifoSize;                          // [this+0x38]
  GXRenderModeObj* mRenderMode;                   // [this+0x3c]
  AudioManager* mAudioMgr;                        // [this+0x40]
  Video* mVideo;                                  // [this+0x44]
  XfbManager* mXfbMgr;                            // [this+0x48]
  Display* mDisplay;                              // [this+0x4c]
  ProcessMeter* mProcessMeter;                    // [this+0x50]
  SceneManager* mSceneMgr;                        // [this+0x54]
};
} // namespace EGG

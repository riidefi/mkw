/*!
 * @file BaseSystem.hpp
 * @brief
 */

#pragma once

#include <rk_types.h>

#include <decomp.h>


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

  //! @brief [vt+0x08] Return a pointer to the video manager.
  //!
  virtual Video* getVideo();

  //! @brief [vt+0x0c] Return a pointer to the system heap.
  //!
  virtual Heap* getSysHeap();

  //! @brief [vt+0x10] Return a pointer to the display manager.
  //!
  virtual Display* getDisplay();

  //! @brief [vt+0x14] Return a pointer to the Xfb manager.
  //!
  virtual XfbManager* getXfbManager();

  virtual PerformanceView* getPerformanceView();  // [vt+0x18]
  virtual SceneManager* getSceneManager();        // [vt+0x1c]
  virtual AudioManager* getAudioManager();        // [vt+0x20]

  virtual void onBeginFrame();                    // [vt+0x24]
  virtual void onEndFrame();                      // [vt+0x28]
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

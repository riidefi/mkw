#include "RKSystem.hpp"

#include <rvl/kpad/kpad.h>
#include <rvl/vi.h>
#include <rvl/pad/pad.h>


#include <egg/core/eggDvdFile.hpp>
#include <egg/core/eggExpHeap.hpp>

#include <host_system/eggAsyncDvdStatus.hpp>
#include <host_system/RKScene.hpp>
#include <host_system/SceneCreatorStatic.hpp>
#include <host_system/SystemManager.hpp>


// Despite having a lot of decompiled functions, this slice is not yet fully
// matching. In fact, we can get everything to match
// except __sinit, or, even more specifically, the inlined constructor of
// RKSystem. So why not include everything but __sinit, then?
//
// Basically, virtual tables are the issue here. There are 3 vtables emitted
// by this TU: RKSystem, TSystem, and RKSceneManager, in that order.
// RKSceneManager's vtable is always emitted. If we include the definition of
// main, RKSystem's vtable is emitted, but not TSystem's. Here we have a
// problem. With only RKSceneManager's vtable, we can cut the slice to not
// include the first 2, but with the one in the middle missing, we're out of
// luck. The only way to emit TSystem's vtable is to instantiate sInstance,
// but by doing so, we generate an __sinit section, and by extension the
// non-matching constructor! Here is a link to the __sinit scratch:
//
//   https://decomp.me/scratch/7uWav
//
// We also had problems trying to get the Vectors' destructors to be emitted,
// but thankfully, we figured that part out. More info at the end of this file.
//
// Before marking as `Matching`, two things need to be done. First, uncomment out
// the inline definition of getSysHeap in RKSystem.hpp. Second, clean up the file.


extern "C" {

// Extern function references.
// PAL: 0x80008c10
extern void unk_80008c10(EGG::Heap*);
// PAL: 0x8000a06c
extern void unk_8000a06c(void*, EGG::Heap*);
// PAL: 0x801a25d0
extern void OSReport(const char*, ...);
// PAL: 0x801bab2c
extern void VISetBlack(int);
// PAL: 0x801bf644
typedef void* (*WPADAllocatorF)(u32);
typedef u8 (*WPADFreeF)(void*);
extern void WPADRegisterAllocator(WPADAllocatorF, WPADFreeF);

void ModuleLinker_initStaticInstance();
// PAL: 0x801bf648
extern u32 WPADGetWorkMemorySize(void);
// PAL: 0x80207d84
extern void VFInitEx(void*, int);
// PAL: 0x802267f0
typedef void (*ExceptionUserCallback)(void);
extern void Exception_setUserCallBack(ExceptionUserCallback);

// Extern data references.
// PAL: 0x80245910
extern const GXRenderModeObj* lbl_80245910[];
// PAL: 0x80270bd8
extern void lbl_80270bd8(void);
// PAL: 0x80385fd0
extern float lbl_80385fd0;
extern float lbl_80385fd8;
// PAL: 0x80385fe0
extern float lbl_80385fe0;
// PAL: 0x80385fe8
extern int lbl_80385fe8; // argc
// PAL: 0x80385fec
extern char** lbl_80385fec; // argv
// PAL: 0x80385ff0
extern System::SceneCreatorStatic* lbl_80385ff0;
// PAL: 0x80385ff8
extern void* lbl_80385ff8;
// PAL: 0x80386f4c
extern int lbl_80386f4c;
// PAL: 0x80386f5c
extern nw4r::ut::Color lbl_80386f5c;
}

extern "C" {
#include <rvl/os/osThread.h>
}

// --- EXTERN DECLARATIONS END ---

namespace System {

RKSystem* RKSystem::spInstance;
RKSystem RKSystem::sInstance;

RKSystem* RKSystem::getStaticInstance() {
  return &sInstance;
}

void* WPADAllocator(u32 size) {
  return RKSystem::sInstance.mWPADAllocator->alloc(size);
}

u8 WPADFree(void* block) {
  RKSystem::sInstance.mWPADAllocator->free(block);
  return 1;
}

void RKSystem::main(int argc, char** argv) {
  RKSystem* sys = &sInstance;

  spInstance = sys;
  EGG::BaseSystem::sSystem = sys;

  lbl_80385fec = argv;
  lbl_80385fe8 = argc;

  // Cast needed to emit TSystem::initialize
  ((RKSystemTemplate*)sys)->initialize();

  lbl_80385ff0 = new (sys->getSysHeap(), 4) SceneCreatorStatic();
  spInstance->mSceneMgr->setCreator(lbl_80385ff0);
  spInstance->mSceneMgr->changeScene(RK_SCENE_ID_BOOTSTRAP);

  spInstance->run();
}

void RKSystem::initialize() {
  initMemory();

  mSysHeap2 = spInstance->mSysHeap;
  mSysHeap2->becomeCurrentHeap();

  mVFMem = mSysHeap2->alloc(0x10000, 0x20);
  VFInitEx(mVFMem, 0x10000);

  EGG::GraphicsFifo::create(mGraphicsFifoSize, nullptr);

  mVideo = new EGG::Video(mRenderMode, lbl_80245910);

  mXfbMgr = new EGG::XfbManager(nullptr);
  for (int i = 0; i < 2; ++i) {
    mXfbMgr->attach(new EGG::Xfb(mRootHeapMem2));
  }

  mDisplay = new EGG::AsyncDisplay(1);

  EGG::Thread::initialize();

  mPerfView = new EGG::ProcessMeter(true);
  mPerfView->setVisible(false);

  mThread = new EGG::Thread(OSGetCurrentThread(), 4);

  EGG::DvdFile::initialize();

  Exception_create(0x40, 0x20, 4, mRootHeapMem2, 2);
  Exception_setUserCallBack(lbl_80270bd8);

  mWPADHeap = EGG::ExpHeap::create(WPADGetWorkMemorySize() + 0x400, mRootHeapMem2, 0);
  mWPADAllocator = new EGG::Allocator(mWPADHeap, 8);
  WPADRegisterAllocator(WPADAllocator, WPADFree);
  KPADInit();
  VIInit();
  PADInit();
  mWPADHeap->adjust();

  mSceneMgr = new RKSceneManager(nullptr);

  SystemManager::initStaticInstance(mSysHeap2);
  SystemManager::sInstance->setupSystem(mRootHeapMem2);

  unk_80008c10(mRootHeapMem2);

  if (SystemManager::isPal50()) {
    OSReport("***********************************\n");
    OSReport("*   PAL50 mode                    *\n");
    OSReport("***********************************\n");
    ((EGG::AsyncDisplay*)mDisplay)->startSyncNTSC(2);
  }
  else {
    OSReport("***********************************\n");
    OSReport("*   NTSC/Progressive/PAL60 mode   *\n");
    OSReport("***********************************\n\0\0");
  }

  ModuleLinker_initStaticInstance();
  unk_8000a06c(lbl_80385ff8, mRootHeapDebug);

  EGG::Display* display = spInstance->mDisplay;
  nw4r::ut::Color color = 0;
  nw4r::ut::Color clearColor = 0;
  display->mClearColor = clearColor;
  lbl_80386f5c = color;

  lbl_80386f4c = 1;

  VISetBlack(0);

  mModuleHeap = EGG::ExpHeap::create(0xa00000, mRootHeapMem1, 0);
  mRootHeapMem2->becomeCurrentHeap();
}

void RKSystem::run() {
  bool flag1;
  bool flag2 = _69;

  mFrameClock = true;
  _6a = !flag2 || mFrameClock;
  _6b = false;
  _6c = false;

  bool ejectedDisc = false;

  while (true) {
    if (mFrameClock) {
      flag2 = _69;
    }

    bool isBeginFrame = mFrameClock || !flag2;
    bool isEndFrame = !mFrameClock || !flag2;

    _6a = isBeginFrame;
    flag1 = _6c;

    if (isBeginFrame) {
      beginFrame();

      draw();

      if (flag1) {
        OSSleepTicks((s64)((__OSBusClock / 4) / 125000) * 500 / 8);
      }
    }

    _6b = true; // reading DVD flag?
    if (EGG::AsyncDvdStatus::sInstance->_51) {
      if (!ejectedDisc) {
        VISetBlack(0);
        ejectedDisc = true;
      }

      EGG::AsyncDvdStatus::sInstance->halt();
      SystemManager::sInstance->handlePowerState();
    }
    else {
      ejectedDisc = false;

      calc();
    }
    _6b = false;

    if (isEndFrame) {
      endFrame();
    }

    if(flag1 && flag2 && isBeginFrame) {
      OSSleepTicks((s64)((__OSBusClock / 4) / 125000) * 500 / 8);            
    }

    mFrameClock = !mFrameClock;
  }
}

// These inline functions are needed for BaseSystem's inline virtuals to be
// emitted in the correct order.
void RKSystem::beginFrame() {
  getDisplay()->beginFrame();
  onBeginFrame();
}

void RKSystem::endFrame() {
  getDisplay()->endFrame();
  onEndFrame();
}

void RKSystem::draw() {
  getDisplay()->beginRender();

  if (EGG::AsyncDvdStatus::sInstance->_51) {
    EGG::AsyncDvdStatus::sInstance->printError();
  }
  else {
    getSceneMgr()->draw();
  }
  getPerfView()->draw();

  getDisplay()->endRender();
}

void RKSystem::calc() {
  getSceneMgr()->calc();
}


///////////////////
// RKSceneManager

void RKSceneManager::changeSceneWithCreator(int sceneID) {
  while (getCurrentScene()) {
    destroyCurrentSceneNoIncoming(true);
  }

  setCreator(mNextSceneCreator);
  mNextSceneCreator = nullptr;

  changeSiblingScene(sceneID);
}

void RKSceneManager::changeSceneWithCreatorAfterFadeOut(int id, EGG::SceneCreator* creator) {
  mNextSceneCreator = creator;
  changeSiblingSceneAfterFadeOut(id);
}

void RKSceneManager::calcCurrentFader() {
  EGG::ColorFader* currentFader = getCurrentFader();
  if (!currentFader) {
    return;
  }
  if (!currentFader->calc() != 0) {
    return;
  }

  switch (getAfterFadeType()) {
  case STATUS_CHANGE_SCENE:
    changeScene(getNextSceneID());
    break;

  case STATUS_CHANGE_SIBLING_SCENE:
    if (mNextSceneCreator) {
      changeSceneWithCreator(getNextSceneID());
    }
    else {
      changeSiblingScene();
    }
    break;

  case STATUS_OUTGOING:
    outgoingParentScene(getParentScene());
    setupNextSceneID();
    createScene(getCurrentSceneID(), getParentScene());
    break;

  case STATUS_INCOMING:
    destroyToSelectSceneID(getNextSceneID());
    break;

  case STATUS_REINITIALIZE:
    reinitCurrentScene();
    break;
  }

  setAfterFadeType(STATUS_IDLE);
}

void RKSceneManager::calc() {
  EGG::SceneManager::calc();
}

void RKSceneManager::draw() {
  EGG::SceneManager::draw();
}

void RKSceneManager::doDrawFader() {
  drawCurrentFader();
}

void RKSceneManager::doCalcFader() {
  calcCurrentFader();
}
} // namespace System


#include <egg/math/eggVector.hpp>

namespace EGG {

const EGG::Vector3f V3F_ZERO(0.f, 0.f, 0.f);
const EGG::Vector3f V3F_EX(1.f, 0.f, 0.f);
const EGG::Vector3f V3F_EY(0.f, 1.f, 0.f);
const EGG::Vector3f V3F_EZ(0.f, 0.f, 1.f);
const EGG::Vector2f V2F_ZERO(0.f, 0.f);
const EGG::Vector2f V2F_EX(1.f, 0.f);
const EGG::Vector2f V2F_EY(0.f, 1.f);

// This is how to generate a dtor after __sinit, templates! Unfortunately, this
// isn't really feasible to do with the Vector classes at the moment, since
// templated classes generate symbols that are unusable in C++ code, which
// could make matching the entire rest of the project that relies on these
// types a giant pain. This isn't really a problem for the moment, since we
// can simply not include dtors in the slice until Vectors can be templated.
//
// template <class T>
// struct example {
// public:
//   ~example() {}
// };
//
// const example<void> instance;
}

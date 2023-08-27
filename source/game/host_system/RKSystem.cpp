#include "RKSystem.hpp"

#include <egg/core/eggDvdFile.hpp>
#include <egg/core/eggExpHeap.hpp>

#include <game/host_system/eggAsyncDvdStatus.hpp>
#include <game/host_system/RKScene.hpp>
#include <game/host_system/SceneCreatorStatic.hpp>
#include <game/host_system/SystemManager.hpp>


// Despite having a lot of decompiled functions locked behind WIP_DECOMP macros,
// this slice is nearly fully matching. In fact, we can get everything to match
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
// Before enabling WIP_DECOMP, two things need to be done. First, uncomment out
// the inline definition of getSysHeap in RKSystem.hpp. Second, uncomment out
// the RKSystem block marked for WIP_DECOMP in dol_slices.yml, and of course,
// don't forget to comment out the block above!

// #define WIP_DECOMP


// --- EXTERN DECLARATIONS BEGIN ---

extern "C" {

// Extern function references.
// PAL: 0x80008c10
extern void unk_80008c10(EGG::Heap*);
// PAL: 0x80008e20
extern UNKNOWN_FUNCTION(halt__Q23EGG14AsyncDvdStatusFv);
// PAL: 0x80008e74
extern UNKNOWN_FUNCTION(printError__Q23EGG14AsyncDvdStatusFv);
// PAL: 0x80008e90..0x80008eb0
extern UNKNOWN_FUNCTION(WPADAllocator__6SystemFUl);
// PAL: 0x80008eb0..0x80008ef0
extern UNKNOWN_FUNCTION(WPADFree__6SystemFPv);
// PAL: 0x80009b40
extern UNKNOWN_FUNCTION(__dt__Q23EGG8Vector3fFv);
// PAL: 0x80009b80
extern UNKNOWN_FUNCTION(__dt__Q23EGG8Vector2fFv);
// PAL: 0x80009ff0
extern UNKNOWN_FUNCTION(ModuleLinker_initStaticInstance);
// PAL: 0x8000a06c
extern void unk_8000a06c(void*, EGG::Heap*);
// PAL: 0x8000a5d0
extern UNKNOWN_FUNCTION(initStaticInstance__Q26System13SystemManagerFPQ23EGG4Heap);
// PAL: 0x8000ac50
extern UNKNOWN_FUNCTION(setupSystem__Q26System13SystemManagerFPQ23EGG4Heap);
// PAL: 0x8000b26c
extern UNKNOWN_FUNCTION(handlePowerState__Q26System13SystemManagerFv);
// PAL: 0x8000b610
extern UNKNOWN_FUNCTION(isPal50__Q26System13SystemManagerFv);
// PAL: 0x80021338
extern UNKNOWN_FUNCTION(__register_global_object);
// PAL: 0x8015ea1c
extern UNKNOWN_FUNCTION(DVDInit);
// PAL: 0x80197aac
extern UNKNOWN_FUNCTION(KPADInit);
// PAL: 0x801a25d0
extern void OSReport(const char*, ...);
// PAL: 0x801af2f0
extern UNKNOWN_FUNCTION(PADInit);
// PAL: 0x801b0180
extern UNKNOWN_FUNCTION(SCInit);
// PAL: 0x801b94a4
extern UNKNOWN_FUNCTION(VIInit);
// PAL: 0x801bab2c
extern void VISetBlack(int);
// PAL: 0x801bf644
typedef void* (*WPADAllocatorF)(u32);
typedef u8 (*WPADFreeF)(void*);
extern void WPADRegisterAllocator(WPADAllocatorF, WPADFreeF);
// PAL: 0x801bf648
extern u32 WPADGetWorkMemorySize(void);
// PAL: 0x80207d84
extern void VFInitEx(void*, int);
// PAL: 0x8020f62c
extern UNKNOWN_FUNCTION(__ct__Q23EGG9AllocatorFPQ23EGG4Heapl);
// PAL: 0x8020fd18
extern UNKNOWN_FUNCTION(__ct__Q23EGG12AsyncDisplayFUc);
// PAL: 0x8020fd8c
extern UNKNOWN_FUNCTION(startSyncNTSC__Q23EGG12AsyncDisplayFUc);
// PAL: 0x8021329c
extern UNKNOWN_FUNCTION(__ct__Q23EGG14SimpleAudioMgrFv);
// PAL: 0x802166f4
extern UNKNOWN_FUNCTION(createStaticInstance__Q23EGG17CoreControllerMgrFv);
// PAL: 0x8021709c
extern UNKNOWN_FUNCTION(createStaticInstance__Q23EGG15GCControllerMgrFv);
// PAL: 0x8022231c
extern UNKNOWN_FUNCTION(initialize__Q23EGG7DvdFileFv);
// PAL: 0x80226734
extern void Exception_create(int, int, int, EGG::Heap*, int);
// PAL: 0x802267f0
typedef void (*ExceptionUserCallback)(void);
extern void Exception_setUserCallBack(ExceptionUserCallback);
// PAL: 0x80226ac8
extern UNKNOWN_FUNCTION(create__Q23EGG7ExpHeapFUlPQ23EGG4HeapUs);
// PAL: 0x80229540
extern UNKNOWN_FUNCTION(create__Q23EGG12GraphicsFifoFUlPQ23EGG4Heap);
// PAL: 0x80229d74
extern UNKNOWN_FUNCTION(becomeCurrentHeap__Q23EGG4HeapFv);
// PAL: 0x80229dcc
extern UNKNOWN_FUNCTION(__nw__FUl);
// PAL: 0x80229de0
extern UNKNOWN_FUNCTION(__nw__FUlPQ23EGG4Heapi);
// PAL: 0x80229e14
extern UNKNOWN_FUNCTION(__ct__Q23EGG12ProcessMeterFb);
// PAL: 0x8023addc
extern UNKNOWN_FUNCTION(__ct__Q23EGG12SceneManagerFPQ23EGG12SceneCreator);
// PAL: 0x8023ae60
extern UNKNOWN_FUNCTION(calc__Q23EGG12SceneManagerFv);
// PAL: 0x8023aeac
extern UNKNOWN_FUNCTION(draw__Q23EGG12SceneManagerFv);
// PAL: 0x8023aef8
extern UNKNOWN_FUNCTION(reinitCurrentScene__Q23EGG12SceneManagerFv);
// PAL: 0x8023af84
extern UNKNOWN_FUNCTION(changeScene__Q23EGG12SceneManagerFi);
// PAL: 0x8023afe0
extern UNKNOWN_FUNCTION(changeSiblingScene__Q23EGG12SceneManagerFi);
// PAL: 0x8023afe8
extern UNKNOWN_FUNCTION(changeSiblingSceneAfterFadeOut__Q23EGG12SceneManagerFi);
// PAL: 0x8023b064
extern UNKNOWN_FUNCTION(changeSiblingScene__Q23EGG12SceneManagerFv);
// PAL: 0x8023b0e4
extern UNKNOWN_FUNCTION(createScene__Q23EGG12SceneManagerFiPQ23EGG5Scene);
// PAL: 0x8023b2ac
extern UNKNOWN_FUNCTION(destroyCurrentSceneNoIncoming__Q23EGG12SceneManagerFb);
// PAL: 0x8023b344
extern UNKNOWN_FUNCTION(destroyToSelectSceneID__Q23EGG12SceneManagerFi);
// PAL: 0x8023b910
extern UNKNOWN_FUNCTION(setupNextSceneID__Q23EGG12SceneManagerFv);
// PAL: 0x8023b92c
extern UNKNOWN_FUNCTION(
  outgoingParentScene__Q23EGG12SceneManagerFPQ23EGG5Scene);
// PAL: 0x802433ac
extern UNKNOWN_FUNCTION(__ct__Q23EGG6ThreadFP8OSThreadi);
// PAL: 0x802435a4
extern UNKNOWN_FUNCTION(initialize__Q23EGG6ThreadFv);
// PAL: 0x80243d18
extern UNKNOWN_FUNCTION(
  initialize__Q23EGG5VideoFPC15GXRenderModeObjPCPC15GXRenderModeObj);
// PAL: 0x80244160
extern UNKNOWN_FUNCTION(__ct__Q23EGG3XfbFPQ23EGG4Heap);
// PAL: 0x80244200
extern UNKNOWN_FUNCTION(
  attach__Q23EGG10XfbManagerFPQ23EGG3Xfb);
// Extern data references.
// PAL: 0x80245910
extern const GXRenderModeObj* lbl_80245910[];
// PAL: 0x80245938
extern UNKNOWN_DATA(lbl_80245938);
// PAL: 0x80270bd8
extern void lbl_80270bd8(void);
// PAL: 0x80270bf0
extern UNKNOWN_DATA(__vt__Q26System8RKSystem);
// PAL: 0x80270c2c
extern UNKNOWN_DATA(__vt__Q23EGG10BaseSystem);
// PAL: 0x80270c68
extern UNKNOWN_DATA(__vt__Q26System14RKSceneManager);
// PAL: 0x80270cd0
extern UNKNOWN_DATA(__vt__Q26System18SceneCreatorStatic);
// PAL: 0x802a4080
extern UNKNOWN_DATA(sInstance__Q26System8RKSystem);
// PAL: 0x80385fc0
extern UNKNOWN_DATA(sInstance__Q23EGG14AsyncDvdStatus);
// PAL: 0x80385fc8
extern UNKNOWN_DATA(spInstance__Q26System8RKSystem);
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
// PAL: 0x80386000
extern UNKNOWN_DATA(sInstance__Q26System13SystemManager);
// PAL: 0x80386f4c
extern int lbl_80386f4c;
// PAL: 0x80386f5c
extern nw4r::ut::Color lbl_80386f5c;
// PAL: 0x80386f60
extern UNKNOWN_DATA(sSystem__Q23EGG10BaseSystem);
// PAL: 0x80386ff8
extern UNKNOWN_DATA(lbl_80386ff8);
// PAL: 0x80386ffc
extern UNKNOWN_DATA(lbl_80386ffc);
}

extern "C" {
#include <rvl/os/osThread.h>
}

// --- EXTERN DECLARATIONS END ---

namespace System {

RKSystem* RKSystem::spInstance;
#ifdef WIP_DECOMP
RKSystem RKSystem::sInstance;
#endif

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

#ifdef WIP_DECOMP
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
#endif
} // namespace System

#ifndef WIP_DECOMP
// Symbol: main__Q26System8RKSystemFiPPc
// PAL: 0x80008ef0..0x80008fac
MARK_BINARY_BLOB(main__Q26System8RKSystemFiPPc, 0x80008ef0, 0x80008fac);
asm UNKNOWN_FUNCTION(main__Q26System8RKSystemFiPPc){
#include "asm/80008ef0.s"
}

// Symbol: getSysHeap__Q26System8RKSystemFv
// PAL: 0x80008fac..0x80008fb4
MARK_BINARY_BLOB(getSysHeap__Q26System8RKSystemFv, 0x80008fac, 0x80008fb4);
asm UNKNOWN_FUNCTION(getSysHeap__Q26System8RKSystemFv){
#include "asm/80008fac.s"
}

// Symbol: initialize__Q23EGG10BaseSystemFv
// PAL: 0x80008fb4..0x80009190
MARK_BINARY_BLOB(initialize__Q23EGG10BaseSystemFv, 0x80008fb4, 0x80009190);
asm UNKNOWN_FUNCTION(initialize__Q23EGG10BaseSystemFv){
#include "asm/80008fb4.s"
}

// Symbol: initRenderMode__Q23EGG10BaseSystemFv
// PAL: 0x80009190..0x80009194
MARK_BINARY_BLOB(initRenderMode__Q23EGG10BaseSystemFv, 0x80009190, 0x80009194);
asm UNKNOWN_FUNCTION(initRenderMode__Q23EGG10BaseSystemFv){
#include "asm/80009190.s"
}
#endif

namespace System {

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

#ifndef WIP_DECOMP
// Symbol: getVideo__Q23EGG10BaseSystemFv
// PAL: 0x800099ac..0x800099b4
MARK_BINARY_BLOB(getVideo__Q23EGG10BaseSystemFv, 0x800099ac, 0x800099b4);
asm UNKNOWN_FUNCTION(getVideo__Q23EGG10BaseSystemFv){
#include "asm/800099ac.s"
}

// Symbol: getSysHeap__Q23EGG10BaseSystemFv
// PAL: 0x800099b4..0x800099bc
MARK_BINARY_BLOB(getSysHeap__Q23EGG10BaseSystemFv, 0x800099b4, 0x800099bc);
asm UNKNOWN_FUNCTION(getSysHeap__Q23EGG10BaseSystemFv){
#include "asm/800099b4.s"
}

// Symbol: getXfbMgr__Q23EGG10BaseSystemFv
// PAL: 0x800099bc..0x800099c4
MARK_BINARY_BLOB(getXfbMgr__Q23EGG10BaseSystemFv, 0x800099bc, 0x800099c4);
asm UNKNOWN_FUNCTION(getXfbMgr__Q23EGG10BaseSystemFv){
#include "asm/800099bc.s"
}

// Symbol: getAudioMgr__Q23EGG10BaseSystemFv
// PAL: 0x800099c4..0x800099cc
MARK_BINARY_BLOB(getAudioMgr__Q23EGG10BaseSystemFv, 0x800099c4, 0x800099cc);
asm UNKNOWN_FUNCTION(getAudioMgr__Q23EGG10BaseSystemFv) {
#include "asm/800099c4.s"
}

// Symbol: __sinit__RKSystem_cpp
// PAL: 0x800099cc..0x80009b40
MARK_BINARY_BLOB(__sinit__RKSystem_cpp, 0x800099cc, 0x80009b40);
asm UNKNOWN_FUNCTION(__sinit__RKSystem_cpp) {
#include "asm/800099cc.s"
}

// Symbol: __dt__Q23EGG8Vector3fFv
// PAL: 0x80009b40..0x80009b80
MARK_BINARY_BLOB(__dt__Q23EGG8Vector3fFv, 0x80009b40, 0x80009b80);
asm UNKNOWN_FUNCTION(__dt__Q23EGG8Vector3fFv) {
#include "asm/80009b40.s"
}

// Symbol: __dt__Q23EGG8Vector2fFv
// PAL: 0x80009b80..0x80009bc0
MARK_BINARY_BLOB(__dt__Q23EGG8Vector2fFv, 0x80009b80, 0x80009bc0);
asm UNKNOWN_FUNCTION(__dt__Q23EGG8Vector2fFv) {
#include "asm/80009b80.s"
}
#endif

#ifdef WIP_DECOMP
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
#endif

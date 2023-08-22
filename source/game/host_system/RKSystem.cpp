#include "RKSystem.hpp"

#include <egg/core/eggAsyncDisplay.hpp>
#include <egg/core/eggDvdFile.hpp>
#include <egg/core/eggExpHeap.hpp>
#include <egg/core/eggGraphicsFifo.hpp>
#include <egg/core/eggProcessMeter.hpp>
#include <egg/core/eggVideo.hpp>
#include <egg/core/eggXfb.hpp>
#include <egg/core/eggXfbManager.hpp>

#include <game/host_system/RKScene.hpp>
#include <game/host_system/SceneCreatorStatic.hpp>
#include <game/host_system/SystemManager.hpp>

// --- EXTERN DECLARATIONS BEGIN ---

extern "C" {

// Extern function references.
// PAL: 0x80008c10
extern void unk_80008c10(EGG::Heap*);
// PAL: 0x80008e20
extern UNKNOWN_FUNCTION(halt__Q23EGG14AsyncDvdStatusFv);
// PAL: 0x80008e74
extern UNKNOWN_FUNCTION(printError__Q23EGG14AsyncDvdStatusFv);
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
extern UNKNOWN_FUNCTION(SimpleAudioMgr_construct);
// PAL: 0x802166f4
extern UNKNOWN_FUNCTION(CoreControllerMgr_createInstance);
// PAL: 0x8021709c
extern UNKNOWN_FUNCTION(GCControllerMgr_createInstance);
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
extern UNKNOWN_DATA(lbl_80270bf0);
// PAL: 0x80270c2c
extern UNKNOWN_DATA(lbl_80270c2c);
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

// .rodata

// .data

// .bss

// Symbol: getStaticInstance__Q26System8RKSystemFv
// PAL: 0x80008e84..0x80008e90
MARK_BINARY_BLOB(getStaticInstance__Q26System8RKSystemFv, 0x80008e84, 0x80008e90);
asm UNKNOWN_FUNCTION(getStaticInstance__Q26System8RKSystemFv){
#include "asm/80008e84.s"
}

namespace System {

#ifdef NON_MATCHING
RKSystem* RKSystem::getStaticInstance() {
  return &sInstance;
}
#endif
} // namespace System

// Symbol: WPADAllocator
// PAL: 0x80008e90..0x80008eb0
MARK_BINARY_BLOB(WPADAllocator, 0x80008e90, 0x80008eb0);
asm void* WPADAllocator(u32) {
#include "asm/80008e90.s"
}

// Symbol: WPADFree
// PAL: 0x80008eb0..0x80008ef0
MARK_BINARY_BLOB(WPADFree, 0x80008eb0, 0x80008ef0);
asm u8 WPADFree(void*) {
#include "asm/80008eb0.s"
}

// Symbol: main__Q26System8RKSystemFiPPc
// PAL: 0x80008ef0..0x80008fac
MARK_BINARY_BLOB(main__Q26System8RKSystemFiPPc, 0x80008ef0, 0x80008fac);
asm UNKNOWN_FUNCTION(main__Q26System8RKSystemFiPPc){
#include "asm/80008ef0.s"
}

namespace System {

#ifdef NON_MATCHING
void RKSystem::main(int argc, char** argv) {
  RKSystem* sys = &sInstance;

  spInstance = sys;
  EGG::BaseSystem::sSystem = sys;

  lbl_80385fec = argv;
  lbl_80385fe8 = argc;

  sys->initialize();

  lbl_80385ff0 = new (sys->getSysHeap(), 4) SceneCreatorStatic();
  spInstance->mSceneMgr->setCreator(lbl_80385ff0);
  spInstance->mSceneMgr->changeScene(RK_SCENE_ID_BOOTSTRAP);

  spInstance->run();
}
#endif
} // namespace System

// Symbol: RKSystem_getSysHeap
// PAL: 0x80008fac..0x80008fb4
MARK_BINARY_BLOB(RKSystem_getSysHeap, 0x80008fac, 0x80008fb4);
asm UNKNOWN_FUNCTION(RKSystem_getSysHeap){
#include "asm/80008fac.s"
}

// Symbol: TSystem_initialize
// PAL: 0x80008fb4..0x80009190
MARK_BINARY_BLOB(TSystem_initialize, 0x80008fb4, 0x80009190);
asm UNKNOWN_FUNCTION(TSystem_initialize){
#include "asm/80008fb4.s"
}

// Symbol: unk_80009190
// PAL: 0x80009190..0x80009194
MARK_BINARY_BLOB(unk_80009190, 0x80009190, 0x80009194);
asm UNKNOWN_FUNCTION(unk_80009190){
#include "asm/80009190.s"
}

// Symbol: initialize__Q26System8RKSystemFv
// PAL: 0x80009194..0x8000951c
MARK_BINARY_BLOB(initialize__Q26System8RKSystemFv, 0x80009194, 0x8000951c);
asm UNKNOWN_FUNCTION(initialize__Q26System8RKSystemFv){
#include "asm/80009194.s"
}

namespace System {

#ifdef NON_MATCHING
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

  mProcessMeter = new EGG::ProcessMeter(true);
  mProcessMeter->setVisible(false);

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

  mSceneMgr = new RKSceneManager((EGG::SceneCreator*)0);

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
    OSReport("***********************************\n");
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
#endif
} // namespace System

// Symbol: RKSystem_run
// PAL: 0x8000951c..0x80009818
MARK_BINARY_BLOB(RKSystem_run, 0x8000951c, 0x80009818);
asm UNKNOWN_FUNCTION(RKSystem_run){
#include "asm/8000951c.s"
}

// Symbol: getDisplay__Q23EGG10BaseSystemFv
// PAL: 0x80009818..0x80009820
MARK_BINARY_BLOB(getDisplay__Q23EGG10BaseSystemFv, 0x80009818, 0x80009820);
asm UNKNOWN_FUNCTION(getDisplay__Q23EGG10BaseSystemFv){
#include "asm/80009818.s"
}

// Symbol: unk_80009820
// PAL: 0x80009820..0x80009824
MARK_BINARY_BLOB(unk_80009820, 0x80009820, 0x80009824);
asm UNKNOWN_FUNCTION(unk_80009820){
#include "asm/80009820.s"
}

// Symbol: unk_80009824
// PAL: 0x80009824..0x80009828
MARK_BINARY_BLOB(unk_80009824, 0x80009824, 0x80009828);
asm UNKNOWN_FUNCTION(unk_80009824){
#include "asm/80009824.s"
}

// Symbol: RKSystem_getSceneManager
// PAL: 0x80009828..0x80009830
MARK_BINARY_BLOB(RKSystem_getSceneManager, 0x80009828, 0x80009830);
asm UNKNOWN_FUNCTION(RKSystem_getSceneManager){
#include "asm/80009828.s"
}

// Symbol: RKSystem_getPerformanceView
// PAL: 0x80009830..0x80009844
MARK_BINARY_BLOB(RKSystem_getPerformanceView, 0x80009830, 0x80009844);
asm UNKNOWN_FUNCTION(RKSystem_getPerformanceView){
#include "asm/80009830.s"
}

// Symbol: RkSceneManager_changeSceneWithCreator
// PAL: 0x80009844..0x8000984c
MARK_BINARY_BLOB(RkSceneManager_changeSceneWithCreator, 0x80009844, 0x8000984c);
asm UNKNOWN_FUNCTION(RkSceneManager_changeSceneWithCreator){
#include "asm/80009844.s"
}

// Symbol: RKSceneManager_calcCurrentFader
// PAL: 0x8000984c..0x80009984
MARK_BINARY_BLOB(RKSceneManager_calcCurrentFader, 0x8000984c, 0x80009984);
asm UNKNOWN_FUNCTION(RKSceneManager_calcCurrentFader){
#include "asm/8000984c.s"
}

// Symbol: RkSceneManager_calc
// PAL: 0x80009984..0x80009988
MARK_BINARY_BLOB(RkSceneManager_calc, 0x80009984, 0x80009988);
asm UNKNOWN_FUNCTION(RkSceneManager_calc){
#include "asm/80009984.s"
}

// Symbol: RkSceneManager_draw
// PAL: 0x80009988..0x8000998c
MARK_BINARY_BLOB(RkSceneManager_draw, 0x80009988, 0x8000998c);
asm UNKNOWN_FUNCTION(RkSceneManager_draw){
#include "asm/80009988.s"
}

// Symbol: unk_8000998c
// PAL: 0x8000998c..0x8000999c
MARK_BINARY_BLOB(unk_8000998c, 0x8000998c, 0x8000999c);
asm UNKNOWN_FUNCTION(unk_8000998c){
#include "asm/8000998c.s"
}

// Symbol: unk_8000999c
// PAL: 0x8000999c..0x800099ac
MARK_BINARY_BLOB(unk_8000999c, 0x8000999c, 0x800099ac);
asm UNKNOWN_FUNCTION(unk_8000999c){
#include "asm/8000999c.s"
}

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

// Symbol: getXfbManager__Q23EGG10BaseSystemFv
// PAL: 0x800099bc..0x800099c4
MARK_BINARY_BLOB(getXfbManager__Q23EGG10BaseSystemFv, 0x800099bc, 0x800099c4);
asm UNKNOWN_FUNCTION(getXfbManager__Q23EGG10BaseSystemFv){
#include "asm/800099bc.s"
}

// Symbol: RKSystem_getAudioManager
// PAL: 0x800099c4..0x800099cc
MARK_BINARY_BLOB(RKSystem_getAudioManager, 0x800099c4, 0x800099cc);
asm UNKNOWN_FUNCTION(RKSystem_getAudioManager) {
#include "asm/800099c4.s"
}

// Symbol: unk_800099cc
// PAL: 0x800099cc..0x80009b40
MARK_BINARY_BLOB(unk_800099cc, 0x800099cc, 0x80009b40);
asm UNKNOWN_FUNCTION(unk_800099cc) {
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

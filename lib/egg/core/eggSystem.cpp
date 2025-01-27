#include "eggSystem.hpp"

#include <egg/audio/eggAudioMgr.hpp>
#include <egg/core/eggController.hpp>
#include <egg/core/eggDisplay.hpp>
#include <egg/core/eggExpHeap.hpp>
#include <egg/core/eggProcessMeter.hpp>
#include <egg/core/eggSceneManager.hpp>

#include <rvl/os/osAlloc.h>
#include <rvl/os/osArena.h>


namespace EGG {
  
BaseSystem* BaseSystem::sSystem;

void BaseSystem::initMemory() {
  void* mem1Lo = OSGetMEM1ArenaLo();
  void* mem1Hi = OSGetMEM1ArenaHi();
  void* mem2Lo = OSGetMEM2ArenaLo();
  void* mem2Hi = OSGetMEM2ArenaHi();

  void *arena1Start = OSInitAlloc(mem1Lo, mem1Hi, 2);
  void *arena2Start = OSInitAlloc(mem2Lo, mem2Hi, 2);

  mem1Lo = (void*)OSRoundUp32B(arena1Start);
  arena1Start = (void*)OSRoundDown32B(mem1Hi);
  mem2Lo = (void*)OSRoundUp32B(arena2Start);
  arena2Start = (void*)OSRoundDown32B(mem2Hi);

  _2c = (void*)0x80000000;
  _30 = mem1Lo;

  mMEM1ArenaLo = mem1Lo;
  mMEM1ArenaHi = arena1Start;
  mMEM2ArenaLo = mem2Lo;
  mMEM2ArenaHi = arena2Start;

  mMemorySize = *((u32*)0x80000028);

  OSSetMEM1ArenaLo(arena1Start);
  OSSetMEM1ArenaHi(arena1Start);
  OSSetMEM2ArenaLo(arena2Start);
  OSSetMEM2ArenaHi(arena2Start);

  Heap::initialize();

  mem1Lo = mMEM1ArenaLo;
  u32 mem1HeapSize = (u32)mMEM1ArenaHi - (u32)mem1Lo;
  mem2Lo = mMEM2ArenaLo;
  u32 mem2HeapSize = (u32)mMEM2ArenaHi - (u32)mem2Lo;

  u32 debugHeapSize;
  
  if (mem2HeapSize >= 0x4000000) {
    debugHeapSize = 0x3B50000;
    mem2HeapSize = OSRoundDown32B(mem2HeapSize - debugHeapSize);
  }
  else {
    debugHeapSize = 0;
  }
  void *debugHeapStart = (u8*)mem2Lo + mem2HeapSize;

  mRootHeapMem1 = ExpHeap::create(mem1Lo, mem1HeapSize, 0);
  mRootHeapMem1->mName = "EGGRootMEM1";

  mRootHeapMem2 = ExpHeap::create(mem2Lo, mem2HeapSize, 0);
  mRootHeapMem2->mName = "EGGRootMEM2";

  if (debugHeapSize) {
    mRootHeapDebug = ExpHeap::create(debugHeapStart, debugHeapSize, 0);
    mRootHeapDebug->mName = "EGGRootDebug";
  }
  else {
    mRootHeapDebug = nullptr;
  }

  mSysHeap = ExpHeap::create(mSysHeapSize, mRootHeapMem1, 0);
  mSysHeap->mName = "EGGSystem";
  mSysHeap->becomeCurrentHeap();
}

void BaseSystem::run() {
  CoreControllerMgr* coreConMgr = CoreControllerMgr::spInstance;
  GCControllerMgr* gcConMgr = GCControllerMgr::spInstance;
  while (true) {
    getDisplay()->beginFrame();
    onBeginFrame();
    getPerfView()->measureBeginFrame();

    coreConMgr->beginFrame();
    gcConMgr->calc();

    getDisplay()->beginRender();
    getPerfView()->measureBeginRender();

    getSceneMgr()->draw();
    getPerfView()->draw();

    getPerfView()->measureEndRender();
    getDisplay()->endRender();

    getSceneMgr()->calc();

    coreConMgr->endFrame();

    if (getAudioMgr()) {
      getAudioMgr()->calc();
    }

    getDisplay()->endFrame();
    onEndFrame();
    getPerfView()->measureEndFrame();
  }
}
} // namespace EGG

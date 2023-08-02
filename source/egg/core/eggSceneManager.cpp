#include <egg/core/eggSceneManager.hpp>
#include <egg/core/eggSystem.hpp>
#include <egg/core/eggDisplay.hpp>
#include <egg/core/eggVideo.hpp>
#include <egg/core/eggExpHeap.hpp>
#include <egg/eggInternal.hpp>
#include <rvl/gx/gxMisc.h>

extern "C" {
// PAL: 0x8023b0e4..0x8023b248
UNKNOWN_FUNCTION(createScene__Q23EGG12SceneManagerFiPQ23EGG5Scene);
// PAL: 0x8023b3f0..0x8023b568
UNKNOWN_FUNCTION(destroyScene__Q23EGG12SceneManagerFPQ23EGG5Scene);
// PAL: 0x8023b5a8..0x8023b800
UNKNOWN_FUNCTION(calcCurrentFader__Q23EGG12SceneManagerFv);
// PAL: 0x8023b8b0..0x8023b910
UNKNOWN_FUNCTION(createDefaultFader__Q23EGG12SceneManagerFv);
// PAL: 0x8023b910..0x8023b92c
UNKNOWN_FUNCTION(setupNextSceneID__Q23EGG12SceneManagerFv);
// PAL: 0x8023b92c..0x8023b940
UNKNOWN_FUNCTION(outgoingParentScene__Q23EGG12SceneManagerFPQ23EGG5Scene);
// PAL: 0x8023b940..0x8023b980
UNKNOWN_FUNCTION(findParentScene__Q23EGG12SceneManagerFi);

extern UNKNOWN_FUNCTION(__ct__Q23EGG10ColorFaderFffffQ34nw4r2ut5ColorQ33EGG5Fader7EStatus);
extern UNKNOWN_FUNCTION(__nw__FUl);
}

extern u32 unk_80389008, unk_8038900c, unk_80389010;

namespace EGG {

u16 SceneManager::sHeapOptionFlg;
Heap* SceneManager::sHeapMem1_ForCreateScene;
Heap* SceneManager::sHeapMem2_ForCreateScene;
Heap* SceneManager::sHeapDebug_ForCreateScene;

SceneManager::SceneManager(SceneCreator* creator) {
  mSceneCreator = creator;
  mCurrentScene = nullptr;
  _1C = -1;
  _18 = -1;
  mNextSceneID = -1;
  mTransitionStatus = STATUS_IDLE;
  mCurrentFader = nullptr;
  bUseMem2 = true;
  createDefaultFader();
}

bool SceneManager::fadeIn() { return mCurrentFader->fadeIn(); }

void SceneManager::calc() {
  calcCurrentScene();
  calcCurrentFader();
}

void SceneManager::draw() {
  drawCurrentScene();
  drawCurrentFader();
}

void SceneManager::reinitCurrentScene() {
  if (mCurrentScene != nullptr) {
    mCurrentScene->reinit();
  }
}

bool SceneManager::reinitCurrentSceneAfterFadeOut() {
  bool returnValue = false;

  if (mTransitionStatus == STATUS_IDLE && mCurrentFader->fadeOut()) {
    mTransitionStatus = STATUS_REINITIALIZE;
    returnValue = true;
  }

  return returnValue;
}

void SceneManager::changeUncleScene(int ID) {
  while (this->mCurrentScene) {
    // destroy current scene then go to parent
    this->destroyCurrentSceneNoIncoming(true);
  }
  this->changeSiblingScene(ID);
}

void SceneManager::changeSiblingScene(int ID) {
  this->mNextSceneID = ID;
  changeSiblingScene();
}

bool SceneManager::changeSiblingSceneAfterFadeOut(int ID) {
  bool returnValue = false;
  if (this->mTransitionStatus == -1 && this->mCurrentFader->fadeOut()) {
    this->mNextSceneID = ID;
    this->mTransitionStatus = STATUS_CHANGE_SIBLING_SCENE;
    returnValue = true;
  }
  return returnValue;
}

void SceneManager::changeSiblingScene() {
  Scene* curScene = this->mCurrentScene; // r4

  Scene* parentScene = NULL; // r31
  if (curScene) parentScene = curScene->getParentScene();

  if (curScene) {
    this->destroyScene(curScene);
    this->mCurrentScene = NULL;
  }

  s32 r30 = mNextSceneID;
  this->setupNextSceneID();
  this->createScene(r30, parentScene);
}

void SceneManager::createScene(int ID, Scene* parentScene) {
  Heap* pParentHeap_Mem1;  // r26
  Heap* pParentHeap_Mem2;  // r25
  Heap* pParentHeap_Debug; // r24

  // if the scene is not NULL (I imagine only NULL for root?), we want to
  // build off that
  if (parentScene) {
    pParentHeap_Mem1 = parentScene->getHeap_Mem1();
    pParentHeap_Mem2 = parentScene->getHeap_Mem2();
    pParentHeap_Debug = parentScene->getHeap_Debug();
  }
  // otherwise, grab the system heaps
  else {
    BaseSystem* sys = EGG::BaseSystem::sSystem;
    pParentHeap_Mem1 = sys->mRootHeapMem1;
    pParentHeap_Mem2 = sys->mRootHeapMem2;
    pParentHeap_Debug = sys->mRootHeapDebug;
  }

  Heap* pParentHeap = (!bUseMem2 ? pParentHeap_Mem1 : pParentHeap_Mem2); // r28

  int r27b = pParentHeap->lock();

  ExpHeap* pNewHeap = ExpHeap::create(-1, pParentHeap, sHeapOptionFlg); // r23

  ExpHeap* pNewHeap_Mem1;         // r25; overwrites pParentHeap_Mem2
  ExpHeap* pNewHeap_Mem2;         // r26; overwrites pParentHeap_Mem1
  ExpHeap* pNewHeap_Debug = 0; // r22

  if (pParentHeap == pParentHeap_Mem2) {
    pNewHeap_Mem1 = ExpHeap::create(-1, pParentHeap_Mem1, sHeapOptionFlg);
    pNewHeap_Mem2 = (EGG::ExpHeap*)pNewHeap;
  } else {
    pNewHeap_Mem2 = ExpHeap::create(-1, pParentHeap_Mem2, sHeapOptionFlg);
    pNewHeap_Mem1 = (EGG::ExpHeap*)pNewHeap;
  }
  // If we have a debug heap, we want to create a child debug heap
  // The system debug heap will in normal game logic be created if and only if
  // MEM2 size exceeds retail size. Since the root entry, would build off
  // this, we would not expect this code to run on a game running on a non
  // development unit
  if (pParentHeap_Debug)
    pNewHeap_Debug = ExpHeap::create(-1, pParentHeap_Debug, sHeapOptionFlg);

  // Set static heap pointers
  sHeapMem1_ForCreateScene = pNewHeap_Mem1;
  sHeapMem2_ForCreateScene = pNewHeap_Mem2;
  sHeapDebug_ForCreateScene = pNewHeap_Debug;

  // if we unset that value above, we need to restore it
  if (r27b) pParentHeap->setFlag(0);

  // Let's make the new heap the current heap
  pNewHeap->becomeCurrentHeap();

  // Create the scene through the scene creator.
  Scene* pNewScene = this->mSceneCreator->create(ID); // r3

  // Inline setters below
  if (parentScene)
    parentScene->setChildScene(pNewScene);
  this->mCurrentScene = pNewScene;
  pNewScene->setSceneID(ID);
  pNewScene->setParentScene(parentScene);
  pNewScene->setSceneMgr(this);
  pNewScene->enter();
}

void SceneManager::createChildScene(int ID, Scene* pScene) {
  outgoingParentScene(pScene);
  mNextSceneID = ID;
  setupNextSceneID();
  createScene(ID, pScene);
}

bool SceneManager::destroyCurrentSceneNoIncoming(bool destroyRootIfNoParent) {
    bool ret = 0;
    Scene * scene = mCurrentScene;
    if( scene ) {
        Scene * parent = scene->getParentScene();
        if( parent ) {
            ret = 1;
            Scene * child = parent->getChildScene();
            destroyScene( child );
            mNextSceneID = parent->getSceneID();
            setupNextSceneID();
        } else {
            if( destroyRootIfNoParent ) {
                destroyScene( scene );
                mNextSceneID = -1;
                setupNextSceneID();
            }
        }
    }
    return ret;
}

bool EGG::SceneManager::destroyToSelectSceneID(int ID) {
  bool ret = 0;
  Scene* parent = this->findParentScene(ID); // r31
  if (parent) {
    ret = 1;
    // destroyCurrentSceneNoIncoming should be inlined
    while (parent->getSceneID() != getUnk18()) {
      Scene* parent; // r30
      if (this->mCurrentScene &&
          (parent = this->mCurrentScene->getParentScene())) {
        this->destroyScene(parent->getChildScene());
        this->mNextSceneID = parent->getSceneID();
        this->setupNextSceneID();
      }
    }
    this->incomingCurrentScene();
  }
  return ret;
}

void SceneManager::destroyScene(Scene* pScene /* r30 */) {
  pScene->exit();
  GXFlush();
  GXDraw();

  // If we have a child scene, destroy that and so on
  if (pScene->getChildScene())
    this->destroyScene(pScene->getChildScene());
  GXFlush();
  GXDraw();

  Scene* parent = pScene->getParentScene(); // r31
  this->mSceneCreator->destroy(pScene->getSceneID());
  this->mCurrentScene = 0;

  // If we're not the root scene, delete ourselves from our parent
  // and make the current scene our parent
  if (parent) {
    parent->setChildScene(0);
    this->mCurrentScene = parent;
  }

  // If the scene has a debug heap, destroy it
  if (pScene->getHeap_Debug())
    pScene->getHeap_Debug()->destroy();

  Heap * sceneHeap = pScene->getHeap(); // r4
  if (pScene->getHeap_Mem1() == sceneHeap) {
    pScene->getHeap_Mem2()->destroy();
    pScene->getHeap_Mem1()->destroy();
  } else if (pScene->getHeap_Mem2() == sceneHeap) {
    pScene->getHeap_Mem1()->destroy();
    pScene->getHeap_Mem2()->destroy();
  }
    
  Heap* r31_second;
  // If we have a parent, use it's heap
  if (parent) {
    r31_second = parent->getHeap();
  }
  // If we're root, rederive it
  else {
    r31_second = !this->bUseMem2 ? BaseSystem::sSystem->mRootHeapMem1
                                 : BaseSystem::sSystem->mRootHeapMem2;
  }
  GXFlush();
  GXDraw();
  r31_second->becomeCurrentHeap();
  GXFlush();
  GXDraw();
}

void SceneManager::incomingCurrentScene() {
  if (this->mCurrentScene)
    this->mCurrentScene->incoming_childDestroy();
}

void SceneManager::calcCurrentScene() {
  if (this->mCurrentScene)
    this->mCurrentScene->calc();
}

} // namespace EGG

#if 0
namespace EGG {

void SceneManager::calcCurrentFader() {
  if (!mCurrentFader)
    return;
  if (!mCurrentFader->calc())
    return;
  switch (this->mTransitionStatus) {
  case 0: {
    int r29 = this->mNextSceneID;
    Scene* curScene;                       // r4
    while (curScene = this->mCurrentScene) // r4
    {
      if (!curScene)
        continue;
      Scene* r28 = curScene->getParentScene(); // r28
      if (r28) {
        this->destroyScene(r28->getChildScene());
        this->mNextSceneID = r28->getSceneID();
        this->setupNextSceneID();
      } else {
        this->destroyScene(curScene);
        this->mNextSceneID = -1;
        this->setupNextSceneID();
      }
    }
    this->mNextSceneID = r29;
    EGG::Scene* r30 = 0;
    if( curScene ) r30 = curScene->getParentScene();
    if( curScene ) {
      this->destroyScene(curScene);
      this->mCurrentScene = 0;
    }

    this->mNextSceneID = r29;
    this->setupNextSceneID();
    this->createScene(r29, r30);
    break;
  }
  case 1: {
    // Identical to changeSiblingScene
    Scene* r30 = 0;
    if( mCurrentScene ) r30 = mCurrentScene->getParentScene();
    if (mCurrentScene) {
      this->destroyScene(mCurrentScene);
      this->mCurrentScene = 0;
    }
    int r29 = this->mNextSceneID;
    this->setupNextSceneID();
    this->createScene(r29, r30);
    break;
  }
  case 2:
    this->outgoingParentScene(this->pParent);
    this->setupNextSceneID();
    this->createScene(this->get18(), this->pParent);
    break;
  case 4:
    // TODO
    if (Scene* s = this->findParentScene(this->mNextSceneID)) // r30
    {
      while (s->getSceneID() != this->get18()) {
        if (this->mCurrentScene == 0)
          continue;
        Scene* r28 = mCurrentScene->getParentScene();
        if (r28 == 0)
          continue;
        this->destroyScene(r28->getChildScene());
        this->mNextSceneID = r28->getSceneID();
        this->setupNextSceneID();
      }
      if (this->mCurrentScene == 0)
        break;
      this->mCurrentScene->incoming_childDestroy();
    }

    break;
  case 3:
    if (mCurrentScene)
      mCurrentScene->reinit();
    break;
  }
  this->mTransitionStatus = -1;
}

}
#else

// Symbol: calcCurrentFader__Q23EGG12SceneManagerFv
// PAL: 0x8023b5a8..0x8023b800
MARK_BINARY_BLOB(calcCurrentFader__Q23EGG12SceneManagerFv, 0x8023b5a8,
                 0x8023b800);
asm UNKNOWN_FUNCTION(calcCurrentFader__Q23EGG12SceneManagerFv) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r3;
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  stw r28, 0x10(r1);
  lwz r0, 0x24(r3);
  cmpwi r0, 0;
  beq lbl_8023b7e0;
  mr r3, r0;
  lwz r12, 0(r3);
  lwz r12, 0x18(r12);
  mtctr r12;
  bctrl;
  cmpwi r3, 0;
  beq lbl_8023b7e0;
  lwz r0, 0x20(r31);
  cmpwi r0, 0;
  beq lbl_8023b620;
  cmpwi r0, 1;
  beq lbl_8023b6c8;
  cmpwi r0, 2;
  beq lbl_8023b714;
  cmpwi r0, 4;
  beq lbl_8023b73c;
  cmpwi r0, 3;
  beq lbl_8023b7bc;
  b lbl_8023b7d8;
lbl_8023b620:
  lwz r29, 0x14(r31);
  li r30, -1;
  b lbl_8023b674;
lbl_8023b62c:
  cmpwi r4, 0;
  beq lbl_8023b674;
  lwz r28, 0x20(r4);
  cmpwi r28, 0;
  beq lbl_8023b660;
  lwz r4, 0x24(r28);
  mr r3, r31;
  bl destroyScene__Q23EGG12SceneManagerFPQ23EGG5Scene;
  lwz r0, 0x28(r28);
  mr r3, r31;
  stw r0, 0x14(r31);
  bl setupNextSceneID__Q23EGG12SceneManagerFv;
  b lbl_8023b674;
lbl_8023b660:
  mr r3, r31;
  bl destroyScene__Q23EGG12SceneManagerFPQ23EGG5Scene;
  stw r30, 0x14(r31);
  mr r3, r31;
  bl setupNextSceneID__Q23EGG12SceneManagerFv;
lbl_8023b674:
  lwz r4, 0xc(r31);
  cmpwi r4, 0;
  bne lbl_8023b62c;
  stw r29, 0x14(r31);
  li r30, 0;
  beq lbl_8023b690;
  lwz r30, 0x20(r4);
lbl_8023b690:
  cmpwi r4, 0;
  beq lbl_8023b6a8;
  mr r3, r31;
  bl destroyScene__Q23EGG12SceneManagerFPQ23EGG5Scene;
  li r0, 0;
  stw r0, 0xc(r31);
lbl_8023b6a8:
  lwz r29, 0x14(r31);
  mr r3, r31;
  bl setupNextSceneID__Q23EGG12SceneManagerFv;
  mr r3, r31;
  mr r4, r29;
  mr r5, r30;
  bl createScene__Q23EGG12SceneManagerFiPQ23EGG5Scene;
  b lbl_8023b7d8;
lbl_8023b6c8:
  lwz r4, 0xc(r31);
  li r30, 0;
  cmpwi r4, 0;
  beq lbl_8023b6dc;
  lwz r30, 0x20(r4);
lbl_8023b6dc:
  cmpwi r4, 0;
  beq lbl_8023b6f4;
  mr r3, r31;
  bl destroyScene__Q23EGG12SceneManagerFPQ23EGG5Scene;
  li r0, 0;
  stw r0, 0xc(r31);
lbl_8023b6f4:
  lwz r29, 0x14(r31);
  mr r3, r31;
  bl setupNextSceneID__Q23EGG12SceneManagerFv;
  mr r3, r31;
  mr r4, r29;
  mr r5, r30;
  bl createScene__Q23EGG12SceneManagerFiPQ23EGG5Scene;
  b lbl_8023b7d8;
lbl_8023b714:
  lwz r4, 0x10(r31);
  mr r3, r31;
  bl outgoingParentScene__Q23EGG12SceneManagerFPQ23EGG5Scene;
  mr r3, r31;
  bl setupNextSceneID__Q23EGG12SceneManagerFv;
  lwz r4, 0x18(r31);
  mr r3, r31;
  lwz r5, 0x10(r31);
  bl createScene__Q23EGG12SceneManagerFiPQ23EGG5Scene;
  b lbl_8023b7d8;
lbl_8023b73c:
  lwz r4, 0x14(r31);
  mr r3, r31;
  bl findParentScene__Q23EGG12SceneManagerFi;
  cmpwi r3, 0;
  mr r30, r3;
  beq lbl_8023b7d8;
  b lbl_8023b78c;
lbl_8023b758:
  lwz r3, 0xc(r31);
  cmpwi r3, 0;
  beq lbl_8023b78c;
  lwz r28, 0x20(r3);
  cmpwi r28, 0;
  beq lbl_8023b78c;
  lwz r4, 0x24(r28);
  mr r3, r31;
  bl destroyScene__Q23EGG12SceneManagerFPQ23EGG5Scene;
  lwz r0, 0x28(r28);
  mr r3, r31;
  stw r0, 0x14(r31);
  bl setupNextSceneID__Q23EGG12SceneManagerFv;
lbl_8023b78c:
  lwz r3, 0x28(r30);
  lwz r0, 0x18(r31);
  cmpw r3, r0;
  bne lbl_8023b758;
  lwz r3, 0xc(r31);
  cmpwi r3, 0;
  beq lbl_8023b7d8;
  lwz r12, 0(r3);
  lwz r12, 0x20(r12);
  mtctr r12;
  bctrl;
  b lbl_8023b7d8;
lbl_8023b7bc:
  lwz r3, 0xc(r31);
  cmpwi r3, 0;
  beq lbl_8023b7d8;
  lwz r12, 0(r3);
  lwz r12, 0x1c(r12);
  mtctr r12;
  bctrl;
lbl_8023b7d8:
  li r0, -1;
  stw r0, 0x20(r31);
lbl_8023b7e0:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  lwz r28, 0x10(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}
#endif

namespace EGG {

void SceneManager::drawCurrentScene() {
  if (!mCurrentScene)
    return;

  mCurrentScene->draw();

  Display* pSystemDisplay = BaseSystem::sSystem->getDisplay(); // r31
  Video * pSystemVideo = BaseSystem::sSystem->getVideo();

  // flag name likely wrong
  if ((pSystemVideo->mFlag & 1) && !pSystemDisplay->hasScreenStateFlag(0))
      pSystemDisplay->setScreenStateFlag(0);
}

void SceneManager::drawCurrentFader() {
  if (mCurrentFader)
    mCurrentFader->draw();
}

} // namespace EGG

#if 0
namespace EGG {
void SceneManager::createDefaultFader() {
  mCurrentFader = new ColorFader(0.0f, 0.0f, 640.0f, 480.0f, 0 /*color*/,
                                 Fader::ESTATUS_OPAQUE);
}
}
#else
// Symbol: createDefaultFader__Q23EGG12SceneManagerFv
// PAL: 0x8023b8b0..0x8023b910
MARK_BINARY_BLOB(createDefaultFader__Q23EGG12SceneManagerFv, 0x8023b8b0,
                 0x8023b910);
asm UNKNOWN_FUNCTION(createDefaultFader__Q23EGG12SceneManagerFv) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r3;
  li r3, 0x24;
  bl __nw__FUl;
  cmpwi r3, 0;
  beq lbl_8023b8f8;
  lfs f1, unk_80389008;
  li r0, 0;
  stw r0, 8(r1);
  addi r4, r1, 8;
  fmr f2, f1;
  lfs f3, unk_8038900c;
  lfs f4, unk_80389010;
  li r5, 0;
  bl __ct__Q23EGG10ColorFaderFffffQ34nw4r2ut5ColorQ33EGG5Fader7EStatus;
lbl_8023b8f8:
  stw r3, 0x24(r31);
  lwz r31, 0x1c(r1);
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}
#endif

namespace EGG {

void SceneManager::setupNextSceneID() {
  this->_1C = this->_18;
  this->_18 = this->mNextSceneID;
  this->mNextSceneID = -1;
}

void SceneManager::outgoingParentScene(Scene* pScene) {
  pScene->outgoing_childCreate();
}

Scene* SceneManager::findParentScene(int ID) {
  bool found = false; // r5
  Scene* scene;       // r3

  for (scene = mCurrentScene->getParentScene(); scene != NULL;
       scene = scene->getParentScene()) {
    if (scene->getSceneID() == ID) {
      found = true;
      break;
    }
  }

  return found ? scene : NULL;
}

} // namespace EGG

#include <egg/core/eggSceneManager.hpp>
#include <egg/core/eggDisplay.hpp>
#include <egg/core/eggExpHeap.hpp>
#include <egg/eggInternal.hpp>
#include <rvl/gx/gxMisc.h>

namespace EGG {

u16 SceneManager::sHeapOptionFlg;
Heap* SceneManager::sHeapMem1_ForCreateScene;
Heap* SceneManager::sHeapMem2_ForCreateScene;
Heap* SceneManager::sHeapDebug_ForCreateScene;

SceneManager::SceneManager(SceneCreator* creator) {
  setCreator(creator);
  mCurrentScene = nullptr;
  mPreviousSceneID = -1;
  mCurrentSceneID = -1;
  mNextSceneID = -1;
  mTransitionStatus = STATUS_IDLE;
  mCurrentFader = nullptr;
  bUseMem2 = true;
  createDefaultFader();
}

bool SceneManager::fadeIn() { return mCurrentFader->fadeIn(); }

// This is defined in a source file, but is always inlined in MKW
inline bool SceneManager::fadeOut() { return mCurrentFader->fadeOut(); }

void SceneManager::calc() {
  calcCurrentScene();
  calcCurrentFader();
}

void SceneManager::draw() {
  drawCurrentScene();
  drawCurrentFader();
}

void SceneManager::reinitCurrentScene() {
  if (mCurrentScene)
    mCurrentScene->reinit();
}

bool SceneManager::reinitCurrentSceneAfterFadeOut() {
  bool fadedOut = false;

  if (mTransitionStatus == STATUS_IDLE && fadeOut()) {
    setAfterFadeType(STATUS_REINITIALIZE);
    fadedOut = true;
  }

  return fadedOut;
}

void SceneManager::changeScene(int ID) {
  while (mCurrentScene) {
    // destroy current scene then go to parent
    destroyCurrentSceneNoIncoming(true);
  }
  changeSiblingScene(ID);
}

void SceneManager::changeSiblingScene(int ID) {
  setNextSceneID(ID);
  changeSiblingScene();
}

bool SceneManager::changeSiblingSceneAfterFadeOut(int ID) {
  bool fadedOut = false;
  if (mTransitionStatus == STATUS_IDLE && fadeOut()) {
    setNextSceneID(ID);
    setAfterFadeType(STATUS_CHANGE_SIBLING_SCENE);
    fadedOut = true;
  }
  return fadedOut;
}

void SceneManager::changeSiblingScene() {
  Scene* parentScene = nullptr;
  if (mCurrentScene)
    parentScene = mCurrentScene->getParentScene();

  if (mCurrentScene) {
    destroyScene(mCurrentScene);
    mCurrentScene = nullptr;
  }

  s32 nextSceneId = mNextSceneID;
  setupNextSceneID();
  createScene(nextSceneId, parentScene);
}

void SceneManager::createScene(int ID, Scene* parentScene) {
  Heap* pParentHeap_Mem1;
  Heap* pParentHeap_Mem2;
  Heap* pParentHeap_Debug;

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

  Heap* pParentHeap = (!bUseMem2 ? pParentHeap_Mem1 : pParentHeap_Mem2);

  // This should be a bool, but is typed as an int to prevent regswaps
  // Store whether or not the heap was locked to re-lock after allocations
  int locked = pParentHeap->enableAllocation();

  ExpHeap* pNewHeap = ExpHeap::create(-1, pParentHeap, sHeapOptionFlg);

  ExpHeap* pNewHeap_Mem1;
  ExpHeap* pNewHeap_Mem2;
  ExpHeap* pNewHeap_Debug = nullptr;

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

  // Disable allocation again if the heaps were locked
  if (locked)
    pParentHeap->disableAllocation();

  // Let's make the new heap the current heap
  pNewHeap->becomeCurrentHeap();

  // Create the scene through the scene creator.
  Scene* pNewScene = mSceneCreator->create(ID);

  // Inline setters below
  if (parentScene)
    parentScene->setChildScene(pNewScene);
  mCurrentScene = pNewScene;
  pNewScene->setSceneID(ID);
  pNewScene->setParentScene(parentScene);
  pNewScene->setSceneMgr(this);
  pNewScene->enter();
}

void SceneManager::createChildScene(int ID, Scene* pScene) {
  outgoingParentScene(pScene);
  setNextSceneID(ID);
  setupNextSceneID();
  createScene(ID, pScene);
}

bool SceneManager::destroyCurrentSceneNoIncoming(bool destroyRootIfNoParent) {
  bool ret = false;
  if (mCurrentScene) {
    Scene* parent = mCurrentScene->getParentScene();
    if (parent) {
      ret = true;
      destroyScene(parent->getChildScene());
      setNextSceneID(parent->getSceneID());
      setupNextSceneID();
    } else {
      if (destroyRootIfNoParent) {
        destroyScene(mCurrentScene);
        setNextSceneID(-1);
        setupNextSceneID();
      }
    }
  }
  return ret;
}

bool SceneManager::destroyToSelectSceneID(int ID) {
  bool ret = false;
  Scene* parent = findParentScene(ID);
  if (parent) {
    ret = true;
    // destroyCurrentSceneNoIncoming should be inlined
    while (parent->getSceneID() != getCurrentSceneID()) {
      destroyCurrentSceneNoIncoming(false);
    }
    incomingCurrentScene();
  }
  return ret;
}

void SceneManager::destroyScene(Scene* pScene) {
  pScene->exit();
  GXFlush();
  GXDraw();

  // If we have a child scene, destroy that and so on
  if (pScene->getChildScene())
    destroyScene(pScene->getChildScene());
  GXFlush();
  GXDraw();

  Scene* parent = pScene->getParentScene();
  mSceneCreator->destroy(pScene->getSceneID());
  mCurrentScene = nullptr;

  // If we're not the root scene, delete ourselves from our parent
  // and make the current scene our parent
  if (parent) {
    parent->setChildScene(nullptr);
    mCurrentScene = parent;
  }

  // If the scene has a debug heap, destroy it
  if (pScene->getHeap_Debug())
    pScene->getHeap_Debug()->destroy();

  Heap* sceneHeap = pScene->getHeap();
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
    r31_second = !bUseMem2 ? BaseSystem::sSystem->mRootHeapMem1
                           : BaseSystem::sSystem->mRootHeapMem2;
  }
  GXFlush();
  GXDraw();
  r31_second->becomeCurrentHeap();
  GXFlush();
  GXDraw();
}

void SceneManager::incomingCurrentScene() {
  if (mCurrentScene)
    mCurrentScene->incoming_childDestroy();
}

void SceneManager::calcCurrentScene() {
  if (mCurrentScene)
    mCurrentScene->calc();
}

void SceneManager::calcCurrentFader() {
  if (!mCurrentFader)
    return;

  if (!mCurrentFader->calc())
    return;

  switch (mTransitionStatus) {
  case STATUS_CHANGE_SCENE:
    changeScene(mNextSceneID);
    break;

  case STATUS_CHANGE_SIBLING_SCENE:
    changeSiblingScene();
    break;

  case STATUS_OUTGOING:
    outgoingParentScene(pParent);
    setupNextSceneID();
    createScene(mCurrentSceneID, pParent);
    break;

  case STATUS_INCOMING:
    destroyToSelectSceneID(mNextSceneID);
    break;

  case STATUS_REINITIALIZE:
    if (mCurrentScene)
      mCurrentScene->reinit();

    break;
  }

  resetAfterFadeType();
}

void SceneManager::drawCurrentScene() {
  if (!mCurrentScene)
    return;

  mCurrentScene->draw();

  BaseSystem::sSystem->getDisplay()->setBlack(false);
}

void SceneManager::drawCurrentFader() {
  if (mCurrentFader)
    mCurrentFader->draw();
}

void SceneManager::createDefaultFader() {
  mCurrentFader = new ColorFader(0.0f, 0.0f, 640.0f, 480.0f, 0 /*color*/,
                                 Fader::ESTATUS_OPAQUE);
}

void SceneManager::setupNextSceneID() {
  mPreviousSceneID = mCurrentSceneID;
  mCurrentSceneID = mNextSceneID;
  mNextSceneID = -1;
}

void SceneManager::outgoingParentScene(Scene* pScene) {
  pScene->outgoing_childCreate();
}

Scene* SceneManager::findParentScene(int ID) {
  bool found = false;
  Scene* scene;

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

#include <egg/core/eggSceneManager.hpp>
#include <egg/core/eggSystem.hpp>
#include <egg/core/eggDisplay.hpp>
#include <egg/core/eggVideo.hpp>
#include <egg/core/eggExpHeap.hpp>
#include <egg/eggInternal.hpp>
#include <rvl/gx/gxMisc.h>

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

static inline void createNewScene(SceneManager* manager, Scene* newScene, int _nextSceneID) {
  int nextSceneID = _nextSceneID; // manager->getNextSceneID();
  manager->setupNextSceneID();
  manager->createScene(nextSceneID, newScene);
}

static inline void setupNewScene(SceneManager* manager, Scene* currentScene) {
  Scene* newScene = nullptr;
  
  if (currentScene) 
    newScene = currentScene->getParentScene();
  
  if (currentScene) {
    manager->destroyScene(currentScene);
    manager->mCurrentScene = nullptr;
  }

  createNewScene(manager, newScene, manager->mNextSceneID);
}

void SceneManager::calcCurrentFader() {
  if (!mCurrentFader)
    return;

  if (!mCurrentFader->calc())
    return;

  switch (this->mTransitionStatus) {
    case 0: {
      int r29 = getNextSceneID();
      
      Scene* curScene = nullptr;               // r4
      while (curScene = this->mCurrentScene) { // r4
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

      setupNewScene(this, curScene);
      
      break;
    }
    case 1: {
      // Identical to changeSiblingScene
      setupNewScene(this, mCurrentScene);
      break;
    }
    case 2: {
      this->outgoingParentScene(this->pParent);
      this->setupNextSceneID();
      this->createScene(this->getUnk18(), this->pParent);
      break;
    }
    case 4: {
      // TODO
      if (Scene* s = this->findParentScene(this->mNextSceneID)) { // r30
        while (s->getSceneID() != this->getUnk18()) {
          if (this->mCurrentScene == 0)
            continue;

          Scene* r28 = mCurrentScene->getParentScene();
      
          if (r28 == nullptr)
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
    }
    case 3: {
      if (mCurrentScene)
        mCurrentScene->reinit();

      break;
    }
  }

  this->mTransitionStatus = STATUS_IDLE;
}

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

void SceneManager::createDefaultFader() {
  mCurrentFader = new ColorFader(0.0f, 0.0f, 640.0f, 480.0f, 0 /*color*/,
                                 Fader::ESTATUS_OPAQUE);
}

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

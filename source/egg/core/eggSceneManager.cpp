#include <egg/core/eggSceneManager.hpp>
#include <egg/core/eggSystem.hpp>
#include <egg/eggInternal.hpp>

namespace EGG {

u32 SceneManager::sHeapOptionFlg;
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
#if 0
bool SceneManager::fadeIn() { return mCurrentFader->fadeIn(); }

// calculate the scene and fader
void SceneManager::calc() {
  this->calcCurrentScene();
  this->calcCurrentFader();
}

// draw the scene and fader
void SceneManager::draw() {
  this->drawCurrentScene();
  this->drawCurrentFader();
}

void SceneManager::reinitCurrentScene() {
  if (mCurrentScene)
    mCurrentScene->reinit();
}

bool SceneManager::reinitCurrentSceneAfterFadeOut() {
  bool returnValue = false;

  if (this->mTransitionStatus == STATUS_IDLE &&
      this->mCurrentFader->fadeOut()) {
    this->mTransitionStatus = STATUS_REINITIALIZE;
    returnValue = true;
  }

  return returnValue;
}

// Exit current scene to parent, then manuver to sibling scene ID
// Not a real symbol
void SceneManager::ChangeUncleScene(int ID) {
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
  if (this->mTransitionStatus == -1 && !this->mCurrentFader->fadeOut()) {
    this->mNextSceneID = ID;
    this->mTransitionStatus = STATUS_CHANGE_SIBLING_SCENE;
    returnValue = true;
  }

  return returnValue;
}

void SceneManager::changeSiblingScene() {
  Scene* curScene = this->mCurrentScene; // r4

  Scene* parentScene = curScene ? curScene->getParentScene() : NULL; // r31

  if (curScene) {
    this->destroyScene(curScene);
    this->mCurrentScene = NULL;

    s32 r30 = mNextSceneID;
    this->setupNextSceneID();
    this->createScene(r30, parentScene);
  }
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
    BaseSystem* sys = EGG::ConfigurationData::sConfigData;
    pParentHeap_Mem1 = sys->mRootHeapMem1;
    pParentHeap_Mem2 = sys->mRootHeapMem2;
    pParentHeap_Debug = sys->mRootHeapDebug;
  }

  Heap* pNewHeap = bUseMem2 ? pParentHeap_Mem2 : pParentHeap_Mem1; // r28

  WiiSportsAssert(pParentHeap_Mem1 && pParentHeap_Mem2, "eggSceneManager.cpp",
                  267, "pParentHeap_Mem1 && pParentHeap_Mem2");

  // same val from "DAME DAME!"
  int r27 = pNewHeap->mFlag & 1;
  if (r27)
    pNewHeap->mFlag &= ~1;

  ExpHeap* r23 = ExpHeap::create(-1, pNewHeap, sHeapOptionFlg); // r23

  ExpHeap* pNewHeap_Debug = NULL; // r22
  ExpHeap* pNewHeap_Mem1;         // r25; overwrites pParentHeap_Mem2
  ExpHeap* pNewHeap_Mem2;         // r26; overwrites pParentHeap_Mem1

  if (pNewHeap == pParentHeap_Mem2) {
    pNewHeap_Mem1 = ExpHeap::create(-1, pParentHeap_Mem1, sHeapOptionFlg);
    pNewHeap_Mem2 = (EGG::ExpHeap*)r23;
  } else {
    pNewHeap_Mem2 = ExpHeap::create(-1, pParentHeap_Mem2, sHeapOptionFlg);
    pNewHeap_Mem1 = (EGG::ExpHeap*)r23;
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

  WiiSportsAssert(pNewHeap && pNewHeap_Mem1 && pNewHeap_Mem2,
                  "eggSceneManager.cpp", 299,
                  "pNewHeap && pNewHeap_Mem1 && pNewHeap_Mem2");

  // if we unset that value above, we need to restore it
  if (r27)
    pNewHeap->mFlag |= 1;

  // Let's make the new heap the current heap
  r23->becomeCurrentHeap();

  // Create the scene through the scene creator.
  WiiSportsAssert(this->mSceneCreator, "eggSceneManager.cpp", 311,
                  "mSceneCreator");
  Scene* pNewScene = this->mSceneCreator->create(ID); // r3
  WiiSportsAssert(pNewScene, "eggSceneManager.cpp", 313, "pNewScene");

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
  this->outgoingParentScene(pScene);
  this->mNextSceneID = ID;
  this->setupNextSceneID();
  this->createScene(ID, pScene);
}
// TODO: match to real symbol
bool SceneManager::destroyCurrentSceneNoIncoming(bool destroyRootIfNoParent) {
  bool result = false; // r30

  Scene* curScene = mCurrentScene; // r5
  if (curScene == NULL)
    return false;

  Scene* parent = curScene->getParentScene(); // r31
  if (parent) {
    this->destroyScene(parent->getChildScene());
    this->mNextSceneID = parent->getSceneID();
    this->setupNextSceneID();
    return true;
  } else if (destroyRootIfNoParent) {
    this->destroyScene(curScene);
    this->mNextSceneID = -1;
    this->setupNextSceneID();
  }
  return false;
}
bool SceneManager::destroyToSelectSceneID(int ID) {
  Scene* parent = this->findParentScene(ID); // r31

  // This ain't it, chief!
  if (parent == NULL)
    return false;
  // inline destroyCurrentSceneNoIncoming?
  while (parent->getSceneID() != this->_18) {
    Scene* parent; // r30
    if (this->mCurrentScene &&
        (parent = this->mCurrentScene->getParentScene())) {
      this->destroyScene(parent->getChildScene());
      this->mNextSceneID = parent->getSceneID();
      this->setupNextSceneID();
    }
  }
  this->incomingCurrentScene();

  return true;
}
void SceneManager::destroyScene(Scene* pScene) {
  pScene->exit();
  GXFlush();
  GXDrawDone(); // GXDraw in IDA?

  // If we have a child scene, destroy that and so on
  if (pScene->getChildScene())
    this->destroyScene(pScene->getChildScene());
  GXFlush();
  GXDrawDone();

  Scene* parent = pScene->getParentScene(); // r31
  this->mSceneCreator->destroy(pScene->getSceneID());
  this->mCurrentScene = NULL;

  // If we're not the root scene, delete ourselves from our parent
  // and make the current scene our parent
  if (parent) {
    parent->setChildScene(NULL);
    this->mCurrentScene = parent;
  }

  // If the scene has a debug heap, destroy it
  if (pScene->getHeap_Debug())
    pScene->getHeap_Debug()->destroy();

  // ???
  if (pScene->getHeap_Mem1() != pScene->getHeap()) {
    if (pScene->getHeap_Mem2() == pScene->getHeap()) {
      pScene->getHeap_Mem1()->destroy();
      pScene->getHeap_Mem2()->destroy();
    }
    // If pScene pScene->getHeap_Mem1() != pScene->getHeap() !=
    // pScene->getHeap_Mem2() we do nothing
  } else {
    pScene->getHeap_Mem2()->destroy();
    pScene->getHeap_Debug()->destroy();
  }
  Heap* r31_second;
  // If we have a parent, use it's heap
  if (parent) {
    r31_second = parent->getHeap();
  }
  // If we're root, rederive it
  else {
    r31_second = this->bUseMem2 ? BaseSystem::sConfigData->mRootHeapMem2
                                : BaseSystem::sConfigData->mRootHeapMem1;
  }
  GXFlush();
  GXDrawDone();
  r31_second->becomeCurrentHeap();
  GXFlush();
  GXDrawDone();
  r31_second->becomeCurrentHeap();
}
void SceneManager::incomingCurrentScene() {
  if (this->mCurrentScene)
    this->mCurrentScene->incoming_childDestroy();
}
void SceneManager::calcCurrentScene() {
  if (this->mCurrentScene)
    this->mCurrentScene->calc();
}

void SceneManager::calcCurrentFader() {
  if (mCurrentFader == NULL || mCurrentFader->calc() == 0)
    return;
  switch (this->mTransitionStatus) {
  case 0: {
    int r29 = this->mNextSceneID;
    Scene* curScene;                       // r4
    while (curScene = this->mCurrentScene) // r4
    {
      if (curScene == NULL)
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
    EGG::Scene* r30 = curScene ? curScene->getParentScene() : 0;
    if (curScene) {
      this->destroyScene(curScene);
      this->mCurrentScene = 0;
    }

    this->mNextSceneID = r29;
    this->setupNextSceneID();
    this->createScene(r29, r30);
    break;
  }
  case STATUS_CHANGE_SIBLING_SCENE: {
    // Identical to changeSiblingScene
    Scene* r30 = this->mCurrentScene ? mCurrentScene->getParentScene() : 0;
    if (mCurrentScene) {
      this->destroyScene(r30);
      this->mCurrentScene = NULL;
    }
    int r29 = this->mNextSceneID;
    this->setupNextSceneID();
    this->createScene(r29, r30);
    break;
  }
  case 2:
    // fields have changed a lot, cant trust this
    WiiSportsAssert(this->pParent, "eggSceneManager.cpp", 701, "pParent");
    WiiSportsAssert(this->pParent->getChildScene(), "eggSceneManager.cpp", 704,
                    "pParent->getChildScene()() == NULL");
    this->outgoingParentScene(this->pParent);
    this->setupNextSceneID();
    this->createScene(this->_18, this->pParent);
    break;
  case 4:
    // TODO
    if (Scene* s = this->findParentScene(this->mNextSceneID)) // r30
    {
      while (s->getSceneID() != this->_18) {
        if (this->mCurrentScene == 0)
          continue;
        Scene* r28 = this->mCurrentScene->getParentScene();
        if (r28 == 0)
          continue;
        this->destroyScene(r28);
        this->mNextSceneID = this->bUseMem2;
        this->setupNextSceneID();
      }
      if (this->mCurrentScene == 0)
        break;
      this->mCurrentScene->incoming_childDestroy();
    }

    break;
  case STATUS_REINITIALIZE:
    if (mCurrentScene)
      mCurrentScene->reinit();
    break;
  }
  this->mTransitionStatus = STATUS_IDLE;
}
void SceneManager::drawCurrentScene() {
  if (!mCurrentScene)
    return;

  mCurrentScene->draw();

  Display* pSystemDisplay = BaseSystem::sConfigData->getDisplay(); // r31

  // flag name likely wrong
  if (BaseSystem::sConfigData->getVideo()->mFlag &
      Video::VIDEO_FLAG_IS_NOT_BLACKED_OUT)
    if (!(pSystemDisplay->mScreenStateFlag &
          Display::SCREEN_STATE_FLAG_TOGGLE_BLACK_OUT))
      pSystemDisplay->mScreenStateFlag |=
          Display::SCREEN_STATE_FLAG_TOGGLE_BLACK_OUT;
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
#endif
} // namespace EGG

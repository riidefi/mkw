#include <egg/core/eggHeap.hpp>
#include <egg/core/eggScene.hpp>
#include <egg/core/eggSceneManager.hpp>

namespace EGG {

Scene::Scene() {
  _10 = Heap::getCurrentHeap();
  mHeapMem1 = SceneManager::getHeapForCreateScene_Mem1();
  mHeapMem2 = SceneManager::getHeapForCreateScene_Mem2();
  mHeapDebug = SceneManager::getHeapForCreateScene_Debug();
  pParentScene = 0;
  pChildScene = 0;
  mID = -1;
  pSceneMgr = 0;
}

Scene::~Scene() {}

} // namespace EGG

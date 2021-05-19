#include <EGG/core/eggHeap.hpp>
#include <EGG/core/eggScene.hpp>
#include <EGG/core/eggSceneManager.hpp>

namespace EGG {

Scene::Scene() {
  _10 = Heap::sCurrentHeap;
  mHeapMem1 = SceneManager::sHeapMem1_ForCreateScene;
  mHeapMem2 = SceneManager::sHeapMem2_ForCreateScene;
  mHeapDebug = SceneManager::sHeapDebug_ForCreateScene;
  pParentScene = 0;
  pChildScene = 0;
  mID = -1;
  pSceneMgr = 0;
}

Scene::~Scene() {}

} // namespace EGG
#include "SceneCreatorStatic.hpp"

#include <game/host_system/RKScene.hpp>

namespace System {

EGG::Scene* SceneCreatorStatic::create(int scene_id) {
  switch (scene_id) {
  case RK_SCENE_ID_BOOTSTRAP:
    return new BootStrapScene;
    break;
  default:
    OSPanic("SceneCreatorStatic.cpp", 39, "Undefined Scene");
    break;
  }

  return nullptr;
}

void SceneCreatorStatic::destroy(int scene_id) {
  switch (scene_id) {
  case RK_SCENE_ID_BOOTSTRAP:
    break;
  default:
    OSPanic("SceneCreatorStatic.cpp", 53, "Undefined Scene");
    break;
  }
}

} // namespace System

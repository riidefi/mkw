/*!
 * @file
 * @brief Static scene creator starts the boostrap scene.
 */

#pragma once

#include <egg/core/eggSceneManager.hpp>
#include <rk_types.h>

namespace System {

class BootStrapScene : public EGG::Scene {
public:
  BootStrapScene();

private:
  char _pad[3288 - 0x30];
};

//! Static scene creator starts the boostrap scene.
class SceneCreatorStatic : public EGG::SceneCreator {
public:
  //! Create the bootstrap scene.
  EGG::Scene* create(int scene_id) override;

  //! Destroy the boostratp scene.
  void destroy(int scene_id) override;
};

} // namespace System

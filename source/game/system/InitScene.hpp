#pragma once

#include <game/RKScene.hpp>

namespace System {

// Incorrect name, but is a placeholder for RaceConfigPlayer::appendParamFile
class InitScene : public RKScene {
  virtual ~InitScene();
  virtual void calc();

public:
  static InitScene* spInstance;
};

} // namespace System

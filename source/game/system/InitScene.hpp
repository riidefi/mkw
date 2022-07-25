#pragma once

#include <game/RKScene.hpp>

namespace System {

// Incorrect name, but is a placeholder for RaceConfigPlayer::appendParamFile
class InitScene : public RKScene {
public:
  static InitScene* spInstance;
};

} // namespace System

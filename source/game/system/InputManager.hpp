#pragma once

#include <rk_types.h>

namespace System {
// Placeholder class for RaceConfig
class Controller {
public:
  virtual ~Controller();
  virtual s32 getControllerId();
};

class PlayerInput {
public:
  u8 _00[0x04 - 0x00];
  Controller* controller;
  void* controller2;
  void* controller3;
  u8 _10[0xEC - 0x10];
};

class InputManager {
public:
  InputManager();
  virtual ~InputManager();
  void setGhostController(u8 playerInputIdx, void* inputs, bool driftIsAuto);

  static InputManager* spInstance;

  PlayerInput playerInputs[4];
};
} // namespace System

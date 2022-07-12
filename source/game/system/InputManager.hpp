#pragma once

#include <rk_types.h>

// Placeholder class for RaceConfig
class InputManager {
public:
  InputManager();
  virtual ~InputManager();
  void setGhostController(u8 playerInputIdx, const u8* inputs,
                          bool driftIsAuto);

  static InputManager* spInstance;
};

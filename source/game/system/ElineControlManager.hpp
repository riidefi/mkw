
#pragma once

#include "ElineController.hpp"

namespace System {
// TODO: TU 0x8052d46c-0x8052d96c
class ElineControlManager {
public:
  ElineControlManager();

  ElineController** controllers;
  u16 controllerCount;
};
}

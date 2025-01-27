
#pragma once

#include "CourseMap.hpp"

namespace System {
// TODO: TU 0x8052d270-0x8052d46c
class ElineController {
  ElineController* next;
  s16 controllerFrameCounter;
  s16 pathIdx;
  s16 controllerDurationFrames;
  bool isFinalNode;
};
}

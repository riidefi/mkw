#pragma once

#include <egg/math/eggVector.hpp>

namespace EGG {

struct BoundBox2f {
  Vector2f min;
  Vector2f max;

  BoundBox2f();
};

} // namespace EGG

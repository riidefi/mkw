#pragma once

#include <rk_types.h>

namespace System {

class Rating {
public:
  Rating() {
    mPoints = 5000;
  }
  virtual ~Rating();

  u16 mPoints;
};

} // namespace System
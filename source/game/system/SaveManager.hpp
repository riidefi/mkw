#pragma once

#include <rk_types.h>

namespace System {

class Rating {
public:
  Rating() { mPoints = 5000; }
  virtual ~Rating() {}

  s16 calcPosPoints(Rating* opponent);
  s16 calcNegPoints(Rating* opponent);

  u16 mPoints;
};

} // namespace System

#pragma once

#include <rk_types.h>

#include <decomp.h>

namespace System {

class Rating {
public:
  Rating() { mPoints = 5000; }
  virtual ~Rating() {}
  u16 getPoints() const { return mPoints; }

  static f32 calc(f32 x, s32 unused);
  static f32 calcSpline(f32 x, s32 termIdx);
  static f32 calcPoints(s16 difference, bool isPos);
  s16 calcPosPoints(const Rating& opponent) const;
  s16 calcNegPoints(const Rating& opponent) const;
  void updatePoints(s32 points);

private:
  u16 mPoints;
};

} // namespace System

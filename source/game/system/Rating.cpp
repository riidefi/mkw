
#include "Rating.hpp"

const s16 spline_terms[] = {0, 1, 8, 50, 125};

namespace System {
f32 Rating::calc(f32 x, s32 unused) {
    #pragma unused (unused)
    s32 term = -2;
    f32 ret = 0.0f;
    for (s32 i = 0; i < 9; i++) {
        u32 termIdx = term;
        if (term < 0)
            termIdx = 0;
        if (term > 4)
            termIdx = 4;

        f32 y = x - term;
        if (y < 0.0f)
            y = -y;

        f32 b = 0.0f;
        if (y >= 0.0f) {
            if (y < 1.0f) {
                b = (3.0f * y * y * y - 6.0f * y * y + 4.0f) / 6.0f;
            } else if (y <= 2.0f) {
                y = y - 2.0f;
                b = (-y * y * y) / 6.0f;
            }
        }
        term++;
        ret += b*spline_terms[termIdx];
    }
    return ret;
}

f32 Rating::calcSpline(f32 x, s32 term) {
    f32 y = x - 2.0f;
    f32 b = (-y * y * y) / 6.0f;
    return b*spline_terms[term];
}

inline s16 nothing(s32 x) { return x; }
f32 Rating::calcPoints(s16 difference, bool isPos) {
    s16 min = -9998;
    if (difference < min) {
        difference = min;
    }
    s16 max = 9998;
    if (difference > max) {
        difference = max;
    }
    if (!isPos) {
        difference = -difference;
    }

    s32 uvar2 = nothing(difference) + 9998;
    s16 ivar1 = uvar2 / 5000;

    f32 x = (1.0f/4999) * uvar2;
    f32 points = calc(x, ivar1);

    return isPos ? points : -points;
}

inline s16 sub(s32 x1, s32 x2) { return x2-x1; }
s16 Rating::calcPosPoints(const Rating& opponent) const {
    return calcPoints(sub(this->getPoints(), opponent.getPoints()), true);
}

s16 Rating::calcNegPoints(const Rating& opponent) const {
    return calcPoints(sub(this->getPoints(), opponent.getPoints()), false);
}

void Rating::updatePoints(s32 points) {
  s32 newPoints = this->mPoints + points;
  if (newPoints < 1)
    newPoints = 1;
  if (newPoints > 9999)
    newPoints = 9999;
  this->mPoints = newPoints;
}

extern const f32 sth;
const f32 sth = 1.0f/4999;
} // ns System

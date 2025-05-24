/*!
 * @file
 * @brief Provides a compile-time generic interface for performing basic math
 * operations on a certain type.
 */

#pragma once

#include <rk_types.h>
#include <math.h>

#define DEG2RAD(X) 0.017453292f * X
//#define RAD2DEG(X) 57.2957795131f * X

namespace EGG {

#if 0
template <typename T> struct Math {
  static T sqrt(T);
  static T frsqrt(T);

  static T sin(T radians);
  static T cos(T radians);
  static T tan(T radians);
  static T asin(T radians);
  static T acos(T radians);
  static T atan2(T num, T denom);
};

typedef Math<float> Mathf;
#endif

namespace Mathf {
float sqrt(float);
float frsqrt(float);

inline f32 abs(f32 t) { return t > (f32)0 ? t : -t;}

float sin(float);
float cos(float);
float tan(float);
float asin(float);
float acos(float);
float atan2(float, float);

inline bool isNonNegative(f32 x) {return x > -FLT_MIN;}
} // namespace Mathf

} // namespace EGG

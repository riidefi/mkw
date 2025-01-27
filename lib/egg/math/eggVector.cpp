/*!
 * @file
 * @brief TODO
 */

#pragma once

#include <egg/math/eggVector.hpp>
#include <float.h>

namespace EGG {

float Vector2f::normalise() {
  float out = 0.0f;
  float lenSq = x * x + y * y;

  if (lenSq > FLT_EPSILON) {
    out = Mathf::sqrt(lenSq);
    float inv = 1.0f / out;
    x *= inv;
    y *= inv;
  }

  return out;
}
void Vector2f::normalise2() {
  float lenSq = x * x + y * y;

  if (lenSq > FLT_EPSILON) {
    float inv = Mathf::frsqrt(lenSq);
    x *= inv;
    y *= inv;
  }
}

float Vector3f::normalise() {
  float out = 0.0f;
  float lenSq = x * x + y * y + z * z;

  if (lenSq > FLT_EPSILON) {
    out = Mathf::sqrt(lenSq);
    float inv = 1.0f / out;
    x *= inv;
    y *= inv;
    z *= inv;
  }

  return out;
}
void Vector3f::normalise2() {
  float lenSq = x * x + y * y + z * z;

  if (lenSq > FLT_EPSILON) {
    float inv = Mathf::frsqrt(lenSq);
    x *= inv;
    y *= inv;
    z *= inv;
  }
}

Vector2f Vector2f::zero = Vector2f(0.0f, 0.0f);
const Vector2f Vector2f::ex = Vector2f(1.0f, 0.0f);
const Vector2f Vector2f::ey = Vector2f(0.0f, 1.0f);

const Vector3f Vector3f::zero = Vector3f(0.0f, 0.0f, 0.0f);
const Vector3f Vector3f::ex = Vector3f(1.0f, 0.0f, 0.0f);
const Vector3f Vector3f::ey = Vector3f(0.0f, 1.0f, 0.0f);
const Vector3f Vector3f::ez = Vector3f(0.0f, 0.0f, 1.0f);

} // namespace EGG

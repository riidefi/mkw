/*!
 * @file
 * @brief TODO
 */

#pragma once

#include <egg/math/eggMath.hpp>

namespace EGG {

struct Vector2f {
  float x;
  float y;

  float normalise();
  // uses fsqrt directly
  void normalise2();

  static Vector2f zero;
  // Basis vectors
  static const Vector2f ex, ey;

  inline Vector2f(float _x, float _y) : x(_x), y(_y) {}
  inline Vector2f() {}

  // For now
  ~Vector2f();
};

struct Vector3f {
  float x;
  float y;
  float z;

  float dot() const {
    return x*x + y*y + z*z;
  }

  float normalise();
  // uses fsqrt directly
  void normalise2();

  static const Vector3f zero;
  // Basis vectors
  static const Vector3f ex, ey, ez;

  // Header fns

  inline Vector3f(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
  inline Vector3f() {}

  // operator Vec*() { return reinterpret_cast<Vec*>(&x); }

  Vector3f operator-() const { return Vector3f(-x, -y, -z); }
  Vector3f operator-(const Vector3f& rhs) const {
    return Vector3f(x - rhs.x, y - rhs.y, z - rhs.y);
  }
  Vector3f operator+(const Vector3f& rhs) const {
    return Vector3f(x + rhs.x, y + rhs.y, z + rhs.z);
  }
  Vector3f operator*(float scalar) const {
    return Vector3f(x * scalar, y * scalar, z * scalar);
  }
  Vector3f cross(EGG::Vector3f& rhs) const {
    return Vector3f(y * rhs.z - z * rhs.y, z * rhs.x - x * rhs.z,
                    x * rhs.y - y * rhs.x);
  }

  // for now
#ifndef REL
  ~Vector3f();
#endif
};

} // namespace EGG

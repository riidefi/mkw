/*!
 * @file
 * @brief TODO
 */

#pragma once

#include <float.h>

#include <egg/math/eggMath.hpp>
#include <nw4r/math/mathTypes.hpp>

namespace EGG {
class Quatf;

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

struct Vector3f : public nw4r::math::VEC3 {
  float dot() const { return x * x + y * y + z * z; }
  static float dot(const Vector3f& v1, const Vector3f& v2) { return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z; }

  bool isSmall() const { return dot() <= FLT_EPSILON; }

  float normalise();
  // uses fsqrt directly
  void normalise2();
  void fromRotated(const Quatf& q, const Vector3f& v);
  static void projAndRej(Vector3f& proj, Vector3f& rej, const Vector3f& v1, const Vector3f& v2);

  static const Vector3f zero;
  // Basis vectors
  static const Vector3f ex, ey, ez;

  // Header fns

  inline Vector3f(float _x, float _y, float _z) {
    x = _x;
    y = _y;
    z = _z;
  }
  inline Vector3f() {}
  inline Vector3f(const nw4r::math::VEC3& v) {
    x = v.x;
    y = v.y;
    z = v.z;
  }

  inline void setZero() {
    x = y = z = 0.0f;
  }

  inline void setOne() {
    x = y = z = 1.0f;
  }

  inline void setUp() {
    x = 0.0f;
    y = 1.0f;
    z = 0.0f;
  }

  Vector3f operator-() const { return Vector3f(-x, -y, -z); }
  Vector3f operator-(const Vector3f& rhs) const;
  Vector3f& operator+=(const Vector3f& rhs) {
    this->x += rhs.x;
    this->y += rhs.y;
    this->z += rhs.z;
    return *this;
  }
  friend Vector3f operator+(Vector3f lhs, const Vector3f& rhs) {
    lhs += rhs;
    return lhs;
  }
  Vector3f& operator*=(float rhs) {
    this->x *= rhs;
    this->y *= rhs;
    this->z *= rhs;
    return *this;
  }
  friend Vector3f operator*(Vector3f lhs, float rhs) {
    lhs *= rhs;
    return lhs;
  }
  /*Vector3f operator*(float scalar) const {
    return Vector3f(x * scalar, y * scalar, z * scalar);
  }*/
  Vector3f cross(const EGG::Vector3f& rhs) const {
    return Vector3f(y * rhs.z - z * rhs.y, z * rhs.x - x * rhs.z,
                    x * rhs.y - y * rhs.x);
  }
  static Vector3f cross(const EGG::Vector3f& lhs, const EGG::Vector3f& rhs) {
    return lhs.cross(rhs);
  }

  // for now
#ifndef REL
  // projection and rejection of v0 onto v1
  ~Vector3f();
#endif
};

inline Vector3f VEC3Sub(const Vector3f& lhs, const Vector3f& rhs) {
    Vector3f out;
    out.x = lhs.x - rhs.x;
    out.y = lhs.y - rhs.y;
    out.z = lhs.z - rhs.z;
  return out;
}
inline Vector3f Vector3f::operator-(const Vector3f& rhs) const {
    return VEC3Sub(*this, rhs);
}

} // namespace EGG

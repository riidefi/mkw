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
  float lenSq() const { return VEC3LenSq(this); }
  static float dot(const Vector3f& v1, const Vector3f& v2) { return VEC3Dot(&v1, &v2); }

  bool isSmall() const { return lenSq() <= FLT_EPSILON; }

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

  inline void setZero() {
    x = y = z = 0.0f;
  }

  inline void set(f32 val) {
    x = y = z = val;
  }

  inline void setOne() {
    x = y = z = 1.0f;
  }

  inline void setUp() {
    x = 0.0f;
    y = 1.0f;
    z = 0.0f;
  }

  Vector3f& operator+=(const Vector3f& rhs);
  Vector3f& operator*=(f32 rhs);
  Vector3f operator+(const Vector3f& rhs) const;
  Vector3f operator-(const Vector3f& rhs) const;
  Vector3f operator*(f32) const;
  Vector3f cross(const EGG::Vector3f& rhs) const {
    return Vector3f(y * rhs.z - z * rhs.y, z * rhs.x - x * rhs.z,
                    x * rhs.y - y * rhs.x);
  }
  float dot(const Vector3f& other) const { return x*other.x + y*other.y + z*other.z; }
  static Vector3f cross(const EGG::Vector3f& lhs, const EGG::Vector3f& rhs) {
    return lhs.cross(rhs);
  }

  // for now
#ifndef REL
#ifndef VEC3_DTOR_INLINE
  // projection and rejection of v0 onto v1
  ~Vector3f();
#endif
#endif
};

inline Vector3f& Vector3f::operator+=(const Vector3f& rhs) { this->x += rhs.x; this->y += rhs.y; this->z += rhs.z; return *this; }
inline Vector3f& Vector3f::operator*=(f32 rhs) { this->x *= rhs; this->y *= rhs; this->z *= rhs; return *this; }
inline Vector3f Vector3f::operator+(const Vector3f& rhs) const { return Vector3f(x + rhs.x, y + rhs.y, z + rhs.z); }
inline Vector3f Vector3f::operator-(const Vector3f& rhs) const { Vector3f tmp; (void)VEC3Sub(&tmp, this, &rhs); return tmp; }
inline Vector3f Vector3f::operator*(f32 rhs) const { return Vector3f(x * rhs, y * rhs, z * rhs); }

// likely inline, I'll just put it here for now
bool isSphereContainedInOther(const EGG::Vector3f& p1, f32 r1, const EGG::Vector3f& p2, f32 r2);

} // namespace EGG

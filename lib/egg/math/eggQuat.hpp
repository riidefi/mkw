/*!
 * @file
 * @brief TODO
 */

#pragma once

#include <rk_types.h>

#include "eggVector.hpp"

namespace EGG {

class Quatf {
public:
  void set(float w, float x, float y, float z);
  void setRPY(const Vector3f& euler);
  void setRPY(float r, float p, float y);
  void setAxisRotation(const Vector3f& axis, float angle);
  float axisSquareNorm() const { return x*x + y*y + z*z; }; // maybe Vector3f subobj
  float squareNorm();
  void normalise();
  Quatf inverse();
  void rotateVector(const Vector3f& v, Vector3f& out);
  void rotateVectorInv(const Vector3f& v, Vector3f& out);
  void slerpTo(const Quatf& r4, float, Quatf& r5) const;
  void makeVectorRotation(Vector3f& v0, Vector3f& v1);

  inline void setIdentity() {
    set(1.0f, 0.0f, 0.0f, 0.0f);
  }

  inline Quatf& operator=(const Quatf& rhs) {
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;
    w = rhs.w;
    return *this;
  }

  inline Quatf& operator*(float f) {
    x *= f;
    y *= f;
    z *= f;
    w *= f;
    return *this;
  }

  inline Quatf& operator+=(const Quatf& rhs) {
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;
    w += rhs.w;
    return *this;
  }

  inline static void quatMul(Quatf& dst, const Quatf& q1, const Quatf& q2) {
    dst.set(
      q1.w*q2.w - q1.x*q2.x - q1.y*q2.y - q1.z*q2.z,
      q1.x*q2.w + q1.w*q2.x + q1.y*q2.z - q1.z*q2.y,
      q1.y*q2.w + q1.w*q2.y + q1.z*q2.x - q1.x*q2.z,
      q1.z*q2.w + q1.w*q2.z + q1.x*q2.y - q1.y*q2.x
    );
  }
  inline static void quatMul(Quatf& dst, const Quatf& q1, const Vector3f& v) {
    float x1 = q1.x;
    float x2 = v.x;
    float y1 = q1.y;
    float y2 = v.y;
    float z1 = q1.z;
    float z2 = v.z;
    float w1 = q1.w;
    dst.set(
      -(x1*x2 + y1*y2 + z1*z2),
      y1*z2 + w1*x2 - z1*y2,
      z1*x2 + w1*y2 - x1*z2,
      w1*z2 + x1*y2 - y1*x2
    );
  }

  f32 x;
  f32 y;
  f32 z;
  f32 w;
};

} // namespace EGG

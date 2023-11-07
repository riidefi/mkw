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
    _[0] = rhs._[0];
    _[1] = rhs._[1];
    _[2] = rhs._[2];
    _[3] = rhs._[3];
    return *this;
  }

  inline Quatf& operator*(float f) {
    _[0] *= f;
    _[1] *= f;
    _[2] *= f;
    _[3] *= f;
    return *this;
  }

  inline Quatf& operator+=(const Quatf& rhs) {
    _[0] += rhs._[0];
    _[1] += rhs._[1];
    _[2] += rhs._[2];
    _[3] += rhs._[3];
    return *this;
  }

  inline static void quatMul(Quatf& dst, const Quatf& q1, const Quatf& q2) {
    dst.set(
      q1._[3]*q2._[3] - q1._[0]*q2._[0] - q1._[1]*q2._[1] - q1._[2]*q2._[2],
      q1._[0]*q2._[3] + q1._[3]*q2._[0] + q1._[1]*q2._[2] - q1._[2]*q2._[1],
      q1._[1]*q2._[3] + q1._[3]*q2._[1] + q1._[2]*q2._[0] - q1._[0]*q2._[2],
      q1._[2]*q2._[3] + q1._[3]*q2._[2] + q1._[0]*q2._[1] - q1._[1]*q2._[0]
    );
  }
  inline static void quatMul(Quatf& dst, const Quatf& q1, const Vector3f& v) {
    float x1 = q1._[0];
    float x2 = v.x;
    float y1 = q1._[1];
    float y2 = v.y;
    float z1 = q1._[2];
    float z2 = v.z;
    float w1 = q1._[3];
    dst.set(
      -(x1*x2 + y1*y2 + z1*z2),
      y1*z2 + w1*x2 - z1*y2,
      z1*x2 + w1*y2 - x1*z2,
      w1*z2 + x1*y2 - y1*x2
    );
  }

  f32 _[4];
};

} // namespace EGG

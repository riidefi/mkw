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
  void set(float a, float b, float c, float d);
  void setRPY(const Vector3f& euler);
  void setRPY(float r, float p, float y);
  void setAxisRotation(float angle, const Vector3f& axis);
  double sqNorm();
  void normalise();
  void inverse(Quatf& other);
  void rotateVector(const Vector3f& v, Vector3f& w);
  void rotateVectorInv(const Vector3f& v, Vector3f& w);
  void mul_Vec3f(const Quatf& q, const Vector3f& v, Quatf& d);
  void slerpTo(const Quatf& r4, Quatf& r5, double t);
  void makeVectorRotation(const Vector3f& v0, const Vector3f& v1);

  f32 _[4];
};

} // namespace EGG

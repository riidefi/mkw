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
  void setRPY(const Vector3f* euler);
  void setRPY(float r, float p, float y);
  void setAxisRotation(float angle, Vector3f* axis);
  double sqNorm();
  void normalise();
  void inverse(Quatf* other);
  void rotateVector(Vector3f* v, Vector3f* w);
  void rotateVectorInv(Vector3f* v, Vector3f* w);
  void mul_Vec3f(Quatf* q, Vector3f* v, Quatf* d);
  void makeVectorRotation(Vector3f* v0, Vector3f* v1);
  void slerpTo(Quatf* r4, Quatf* r5, double t);

  f32 _[4];
};

} // namespace EGG

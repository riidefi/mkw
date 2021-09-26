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
  void setAxisRotation(const Vector3f& axis, float angle);
  float squareNorm();
  void normalise();
  Quatf inverse();
  void rotateVector(const Vector3f& v);
  void rotateVectorInv(const Vector3f& v);
  void slerpTo(const Quatf& r4, float, Quatf& r5) const;
  void makeVectorRotation(Vector3f& v0, Vector3f& v1);

  f32 _[4];
};

Quatf operator*(const Quatf&, const Vector3f&);

} // namespace EGG

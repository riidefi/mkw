/*!
 * @file
 * @brief TODO
 */

#include <float.h>
#include <decomp.h>
#define VEC3_DTOR_INLINE
#include <egg/math/eggQuat.hpp>

namespace EGG {

#undef FLT_EPSILON
#define FLT_EPSILON 1.192092896e-07F

float _() {
  (void)0.5f;
  (void)2.0f;
  (void)0.0f;
  (void)FLT_EPSILON;
  (void)1.0f;
  return 2.0f;
}

// Symbol: set__Q23EGG5QuatfFffff
void Quatf::set(float a, float b, float c, float d) {
  w = a;
  x = b;
  y = c;
  z = d;
}

void Quatf::setRPY(const Vector3f& euler) {
  f32 cosZ = EGG::Mathf::cos(0.5f * euler.z);
  f32 cosY = EGG::Mathf::cos(0.5f * euler.y);
  f32 cosX = EGG::Mathf::cos(0.5f * euler.x);

  f32 sinZ = EGG::Mathf::sin(0.5f * euler.z);
  f32 sinY = EGG::Mathf::sin(0.5f * euler.y);
  f32 sinX = EGG::Mathf::sin(0.5f * euler.x);

  f32 cZcY = cosZ * cosY;
  f32 sZsY = sinZ * sinY;
  this->w = cZcY * cosX + sZsY * sinX;
  this->x = cZcY * sinX - sZsY * cosX;
  f32 cZsY = cosZ * sinY;
  f32 sZcY = sinZ * cosY;
  this->y = cZsY * cosX + sZcY * sinX;
  this->z = sZcY * cosX - cZsY * sinX;
}

void Quatf::setRPY(float x, float y, float z) {
  // doesn't match without inlining the function above
  Vector3f vec;
  vec.x = x;
  vec.y = y;
  vec.z = z;
  this->setRPY(vec);
}

void Quatf::setAxisRotation(const Vector3f &axis, f32 rot) {
  const f32 half_angle = rot * 0.5f;
  const f32 cos = Math<f32>::cos(half_angle);
  const f32 sin = Math<f32>::sin(half_angle);
  set(cos, sin * axis.x, sin * axis.y, sin * axis.z);
}


float Quatf::squareNorm() const {
  return axisSquareNorm() + w*w;
}

void Quatf::normalise() {
  f32 sqNorm = squareNorm();
  if (sqNorm > FLT_EPSILON) {
    f32 mag = Math<f32>::sqrt(sqNorm);
    if (mag > 0.0f) {
        multScalar(Math<f32>::inv(mag));
    }
  }
}

void Quatf::inverse(Quatf& out) const {
  f32 sqNorm = squareNorm();
  if (sqNorm > 0.0f) {
    f32 sqNormInv = 1.0f / sqNorm;
    out.x = sqNormInv * -x;
    out.y = sqNormInv * -y;
    out.z = sqNormInv * -z;
    out.w = sqNormInv * w;
  } else {
    out.w = w;
    out.x = -x;
    out.y = -y;
    out.z = -z;
  }
}

void Quatf::rotateVector(const Vector3f& vec, Vector3f& ret) const {
  Quatf conj = conjugate();
  Quatf res;
  vecMul(*this, vec, res);

  ret.x = (res.y * conj.z + (res.x * conj.w + res.w * conj.x)) - res.z * conj.y;
  ret.y = (res.z * conj.x + (res.y * conj.w + res.w * conj.y)) - res.x * conj.z;
  ret.z = (res.x * conj.y + (res.z * conj.w + res.w * conj.z)) - res.y * conj.x;
}

void Quatf::slerpTo(const EGG::Quatf &q1, f32 t, EGG::Quatf &dst) const {
  f32 dot = x * q1.x + y * q1.y + z * q1.z + w * q1.w;

  if (dot > 1.0f) {
    dot = 1.0f;
  } else if (dot < -1.0f) {
    dot = -1.0f;
  }

  bool bDot;
  if (dot < 0.0) {
    dot = -dot;
    bDot = true;
  } else {
    dot = dot;
    bDot = false;
  }

  f32 acos = Mathf::acos(dot);
  f32 sin = Mathf::sin(acos);

  f32 s;
  f32 recip;
  if (Mathf::abs(sin) < 0.00001f) {
    s = 1.0f - t;
  } else {
    f32 invSin = 1.0f / sin;
    f32 tmp0 = t * acos;
    s = invSin * Mathf::sin(acos - tmp0);
    recip = invSin * Mathf::sin(tmp0);
  }

  if (bDot) recip = -recip;
  dst.x = s * x + recip * q1.x;
  dst.y = s * y + recip * q1.y;
  dst.z = s * z + recip * q1.z;
  dst.w = s * w + recip * q1.w;
}

void Quatf::makeVectorRotation(const Vector3f& v0, const Vector3f& v1) {

}

} // namespace EGG

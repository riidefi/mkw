/*!
 * @file
 * @brief TODO
 */

#include <decomp.h>
#define VEC3_DTOR_INLINE
#include <egg/math/eggQuat.hpp>

extern "C" {
extern UNKNOWN_FUNCTION(Vector3f_cross);
extern UNKNOWN_FUNCTION(__ml__3EGGFRCQ23EGG5QuatfRCQ23EGG8Vector3f);
extern UNKNOWN_FUNCTION(unk_8022f8c0);
}

namespace EGG {

using EGG::Mathf::cos;
using EGG::Mathf::sin;
using EGG::Mathf::sqrt;

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

// Symbol: setAxisRotation__Q23EGG5QuatfFRCQ23EGG8Vector3ff
// PAL: 0x8023a0a0..0x8023a138
MARK_BINARY_BLOB(setAxisRotation__Q23EGG5QuatfFRCQ23EGG8Vector3ff, 0x8023a0a0,
                 0x8023a138);
asm void Quatf::setAxisRotation(const Vector3f& axis, float angle) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  stfd f31, 0x20(r1);
  psq_st f31, 40(r1), 0, 0;
  stfd f30, 0x10(r1);
  psq_st f30, 24(r1), 0, 0;
  lfs f0, 0.5f;
  stw r31, 0xc(r1);
  mr r31, r4;
  fmuls f30, f0, f1;
  stw r30, 8(r1);
  mr r30, r3;
  fmr f1, f30;
  bl cos;
  fmr f31, f1;
  fmr f1, f30;
  bl sin;
  lfs f3, 8(r31);
  lfs f2, 4(r31);
  lfs f0, 0(r31);
  fmuls f3, f1, f3;
  fmuls f2, f1, f2;
  stfs f31, 0xc(r30);
  fmuls f0, f1, f0;
  stfs f2, 4(r30);
  stfs f0, 0(r30);
  stfs f3, 8(r30);
  psq_l f31, 40(r1), 0, 0;
  lfd f31, 0x20(r1);
  psq_l f30, 24(r1), 0, 0;
  lfd f30, 0x10(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

float Quatf::squareNorm() {
  return axisSquareNorm() + w*w;
}

// Symbol: normalise__Q23EGG5QuatfFv
// PAL: 0x8023a168..0x8023a210
MARK_BINARY_BLOB(normalise__Q23EGG5QuatfFv, 0x8023a168, 0x8023a210);
asm void Quatf::normalise() {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  lfs f1, 0(r3);
  lfs f0, 4(r3);
  fmuls f3, f1, f1;
  lfs f4, 8(r3);
  fmuls f2, f0, f0;
  lfs f1, 0xc(r3);
  fmuls f4, f4, f4;
  lfs f0, FLT_EPSILON;
  fadds f2, f3, f2;
  fmuls f1, f1, f1;
  fadds f2, f4, f2;
  fadds f1, f1, f2;
  fcmpo cr0, f1, f0;
  ble lbl_8023a1fc;
  bl sqrt;
  lfs f0, 0.0f;
  fcmpo cr0, f1, f0;
  ble lbl_8023a1fc;
  lfs f0, 1.0f;
  lfs f3, 0xc(r31);
  fdivs f4, f0, f1;
  lfs f2, 0(r31);
  lfs f1, 4(r31);
  lfs f0, 8(r31);
  fmuls f3, f3, f4;
  fmuls f2, f2, f4;
  fmuls f1, f1, f4;
  stfs f3, 0xc(r31);
  fmuls f0, f0, f4;
  stfs f2, 0(r31);
  stfs f1, 4(r31);
  stfs f0, 8(r31);
lbl_8023a1fc:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: inverse__Q23EGG5QuatfFv
// PAL: 0x8023a210..0x8023a2d0
MARK_BINARY_BLOB(inverse__Q23EGG5QuatfFv, 0x8023a210, 0x8023a2d0);
asm Quatf Quatf::inverse() {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  lfs f1, 0(r3);
  lfs f0, 4(r3);
  fmuls f2, f1, f1;
  lfs f4, 0xc(r3);
  fmuls f0, f0, f0;
  lfs f3, 8(r3);
  lfs f7, 0(r3);
  fmuls f1, f4, f4;
  fadds f2, f2, f0;
  lfs f6, 4(r3);
  fmuls f3, f3, f3;
  lfs f5, 8(r3);
  fneg f7, f7;
  lfs f0, 0.0f;
  fadds f2, f3, f2;
  stfs f7, 8(r1);
  fneg f3, f5;
  fneg f6, f6;
  stfs f4, 0x14(r1);
  fadds f5, f1, f2;
  stfs f6, 0xc(r1);
  fcmpo cr0, f5, f0;
  stfs f3, 0x10(r1);
  ble lbl_8023a2ac;
  lfs f0, 1.0f;
  frsp f2, f7;
  frsp f1, f6;
  fdivs f5, f0, f5;
  frsp f0, f3;
  fmuls f3, f5, f2;
  fmuls f2, f5, f1;
  fmuls f1, f5, f0;
  stfs f3, 0(r4);
  fmuls f0, f5, f4;
  stfs f2, 4(r4);
  stfs f1, 8(r4);
  stfs f0, 0xc(r4);
  b lbl_8023a2c8;
lbl_8023a2ac:
  frsp f2, f7;
  stfs f4, 0xc(r4);
  frsp f1, f6;
  frsp f0, f3;
  stfs f2, 0(r4);
  stfs f1, 4(r4);
  stfs f0, 8(r4);
lbl_8023a2c8:
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: rotateVector__Q23EGG5QuatfFRCQ23EGG8Vector3fRQ23EGG8Vector3f
// PAL: 0x8023a2d0..0x8023a404
MARK_BINARY_BLOB(rotateVector__Q23EGG5QuatfFRCQ23EGG8Vector3fRQ23EGG8Vector3f, 0x8023a2d0,
                 0x8023a404);

asm void Quatf::rotateVector(const Vector3f& v, Vector3f& out) {
  // clang-format off
  nofralloc;
  stwu r1, -0x50(r1);
  mflr r0;
  stw r0, 0x54(r1);
  stfd f31, 0x40(r1);
  psq_st f31, 72(r1), 0, 0;
  stfd f30, 0x30(r1);
  psq_st f30, 56(r1), 0, 0;
  mr r0, r4;
  mr r4, r3;
  addi r6, r1, 8;
  stw r31, 0x2c(r1);
  mr r31, r5;
  mr r5, r0;
  lfs f2, 0(r3);
  lfs f1, 8(r3);
  fneg f3, f2;
  lfs f0, 4(r3);
  fneg f1, f1;
  fneg f2, f0;
  lfs f0, 0xc(r3);
  stfs f3, 0x18(r1);
  stfs f2, 0x1c(r1);
  stfs f1, 0x20(r1);
  stfs f0, 0x24(r1);
  bl __ml__3EGGFRCQ23EGG5QuatfRCQ23EGG8Vector3f;
  lfs f12, 0x10(r1);
  lfs f7, 0x24(r1);
  lfs f1, 0x14(r1);
  lfs f31, 0x1c(r1);
  fmuls f3, f12, f7;
  lfs f30, 8(r1);
  lfs f11, 0x20(r1);
  fmuls f5, f1, f31;
  lfs f9, 0xc(r1);
  fmuls f4, f30, f7;
  fmuls f0, f1, f11;
  lfs f8, 0x18(r1);
  fmuls f6, f9, f7;
  fmuls f13, f30, f31;
  fadds f10, f3, f0;
  fmuls f3, f1, f8;
  fmuls f1, f1, f7;
  fmuls f0, f30, f8;
  fadds f6, f6, f5;
  fadds f3, f4, f3;
  fmuls f5, f9, f11;
  fsubs f1, f1, f0;
  fmuls f0, f9, f31;
  fadds f3, f5, f3;
  fmuls f2, f12, f31;
  fsubs f1, f1, f0;
  fmuls f0, f12, f11;
  fmuls f7, f12, f8;
  fmuls f4, f9, f8;
  fsubs f8, f3, f2;
  fadds f5, f13, f10;
  fsubs f0, f1, f0;
  stfs f8, 8(r1);
  fadds f3, f7, f6;
  fmuls f2, f30, f11;
  stfs f0, 0x14(r1);
  fsubs f4, f5, f4;
  fsubs f2, f3, f2;
  stfs f4, 0x10(r1);
  stfs f2, 0xc(r1);
  stfs f8, 0(r31);
  stfs f2, 4(r31);
  stfs f4, 8(r31);
  psq_l f31, 72(r1), 0, 0;
  lfd f31, 0x40(r1);
  psq_l f30, 56(r1), 0, 0;
  lfd f30, 0x30(r1);
  lwz r31, 0x2c(r1);
  lwz r0, 0x54(r1);
  mtlr r0;
  addi r1, r1, 0x50;
  blr;
  // clang-format on
}

// Symbol: rotateVectorInv__Q23EGG5QuatfFRCQ23EGG8Vector3fRQ23EGG8Vector3f
// PAL: 0x8023a404..0x8023a540
MARK_BINARY_BLOB(rotateVectorInv__Q23EGG5QuatfFRCQ23EGG8Vector3fRQ23EGG8Vector3f, 0x8023a404,
                 0x8023a540);
asm void Quatf::rotateVectorInv(const Vector3f& v, Vector3f& out) {
  // clang-format off
  nofralloc;
  stwu r1, -0x50(r1);
  mflr r0;
  stw r0, 0x54(r1);
  stfd f31, 0x40(r1);
  psq_st f31, 72(r1), 0, 0;
  stfd f30, 0x30(r1);
  psq_st f30, 56(r1), 0, 0;
  addi r6, r1, 8;
  stw r31, 0x2c(r1);
  mr r31, r5;
  mr r5, r4;
  addi r4, r1, 0x18;
  stw r30, 0x28(r1);
  mr r30, r3;
  lfs f0, 0(r3);
  fneg f0, f0;
  stfs f0, 0x18(r1);
  lfs f0, 4(r3);
  fneg f0, f0;
  stfs f0, 0x1c(r1);
  lfs f0, 8(r3);
  fneg f0, f0;
  stfs f0, 0x20(r1);
  lfs f0, 0xc(r3);
  stfs f0, 0x24(r1);
  bl __ml__3EGGFRCQ23EGG5QuatfRCQ23EGG8Vector3f;
  lfs f12, 0x10(r1);
  lfs f7, 0xc(r30);
  lfs f1, 0x14(r1);
  lfs f31, 4(r30);
  fmuls f3, f12, f7;
  lfs f30, 8(r1);
  lfs f11, 8(r30);
  fmuls f5, f1, f31;
  lfs f9, 0xc(r1);
  fmuls f4, f30, f7;
  fmuls f0, f1, f11;
  lfs f8, 0(r30);
  fmuls f6, f9, f7;
  fmuls f13, f30, f31;
  fadds f10, f3, f0;
  fmuls f3, f1, f8;
  fmuls f1, f1, f7;
  fmuls f0, f30, f8;
  fadds f6, f6, f5;
  fadds f3, f4, f3;
  fmuls f5, f9, f11;
  fsubs f1, f1, f0;
  fmuls f0, f9, f31;
  fadds f3, f5, f3;
  fmuls f2, f12, f31;
  fsubs f1, f1, f0;
  fmuls f0, f12, f11;
  fmuls f7, f12, f8;
  fmuls f4, f9, f8;
  fsubs f8, f3, f2;
  fadds f5, f13, f10;
  fsubs f0, f1, f0;
  stfs f8, 8(r1);
  fadds f3, f7, f6;
  fmuls f2, f30, f11;
  stfs f0, 0x14(r1);
  fsubs f4, f5, f4;
  fsubs f2, f3, f2;
  stfs f4, 0x10(r1);
  stfs f2, 0xc(r1);
  stfs f8, 0(r31);
  stfs f2, 4(r31);
  stfs f4, 8(r31);
  psq_l f31, 72(r1), 0, 0;
  lfd f31, 0x40(r1);
  psq_l f30, 56(r1), 0, 0;
  lfd f30, 0x30(r1);
  lwz r31, 0x2c(r1);
  lwz r30, 0x28(r1);
  lwz r0, 0x54(r1);
  mtlr r0;
  addi r1, r1, 0x50;
  blr;
  // clang-format on
}

// Symbol: __ml__3EGGFRCQ23EGG5QuatfRCQ23EGG8Vector3f
// PAL: 0x8023a540..0x8023a5c4
MARK_BINARY_BLOB(__ml__3EGGFRCQ23EGG5QuatfRCQ23EGG8Vector3f, 0x8023a540,
                 0x8023a5c4);
asm Quatf operator*(const Quatf&, const Vector3f&) {
  // clang-format off
  nofralloc;
  lfs f7, 0(r4);
  lfs f6, 0(r5);
  lfs f5, 4(r4);
  lfs f4, 4(r5);
  fmuls f3, f7, f6;
  lfs f10, 8(r4);
  fmuls f0, f5, f6;
  fmuls f2, f5, f4;
  lfs f9, 8(r5);
  fmuls f1, f7, f4;
  fmuls f8, f10, f9;
  lfs f11, 0xc(r4);
  fadds f2, f3, f2;
  fsubs f12, f1, f0;
  fmuls f1, f7, f9;
  fadds f3, f8, f2;
  fmuls f2, f10, f6;
  fmuls f0, f11, f9;
  fneg f3, f3;
  fsubs f7, f2, f1;
  stfs f3, 0xc(r6);
  fadds f0, f12, f0;
  fmuls f1, f11, f4;
  stfs f0, 8(r6);
  fmuls f3, f5, f9;
  fmuls f2, f10, f4;
  fadds f1, f7, f1;
  fmuls f0, f11, f6;
  fsubs f2, f3, f2;
  stfs f1, 4(r6);
  fadds f0, f2, f0;
  stfs f0, 0(r6);
  blr;
  // clang-format on
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

// Symbol: makeVectorRotation__Q23EGG5QuatfFRQ23EGG8Vector3fRQ23EGG8Vector3f
// PAL: 0x8023a788..0x8023a884
MARK_BINARY_BLOB(
    makeVectorRotation__Q23EGG5QuatfFRQ23EGG8Vector3fRQ23EGG8Vector3f,
    0x8023a788, 0x8023a884);
asm void Quatf::makeVectorRotation(Vector3f& v0, Vector3f& v1) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  stw r31, 0x2c(r1);
  mr r31, r5;
  stw r30, 0x28(r1);
  mr r30, r4;
  stw r29, 0x24(r1);
  mr r29, r3;
  addi r3, r1, 8;
  bl Vector3f_cross;
  lfs f3, 0(r30);
  lfs f2, 0(r31);
  lfs f1, 4(r30);
  lfs f0, 4(r31);
  fmuls f3, f3, f2;
  lfs f4, 8(r30);
  fmuls f0, f1, f0;
  lfs f1, 8(r31);
  lfs f2, 1.0f;
  fmuls f4, f4, f1;
  lfs f1, 2.0f;
  fadds f3, f3, f0;
  lfs f0, 0.0f;
  fadds f3, f4, f3;
  fadds f2, f2, f3;
  fmuls f1, f1, f2;
  fcmpo cr0, f1, f0;
  bge lbl_8023a800;
  fmr f1, f0;
lbl_8023a800:
  bl sqrt;
  lfs f0, FLT_EPSILON;
  fcmpo cr0, f1, f0;
  cror 2, 0, 2;
  bne lbl_8023a830;
  lfs f0, 0.0f;
  lfs f1, 1.0f;
  stfs f1, 0xc(r29);
  stfs f0, 0(r29);
  stfs f0, 4(r29);
  stfs f0, 8(r29);
  b lbl_8023a868;
lbl_8023a830:
  lfs f2, 1.0f;
  lfs f0, 0.5f;
  fdivs f4, f2, f1;
  lfs f3, 0x10(r1);
  lfs f2, 0xc(r1);
  fmuls f0, f0, f1;
  fmuls f3, f3, f4;
  stfs f0, 0xc(r29);
  fmuls f1, f2, f4;
  lfs f0, 8(r1);
  fmuls f0, f0, f4;
  stfs f1, 4(r29);
  stfs f0, 0(r29);
  stfs f3, 8(r29);
lbl_8023a868:
  lwz r0, 0x34(r1);
  lwz r31, 0x2c(r1);
  lwz r30, 0x28(r1);
  lwz r29, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

} // namespace EGG

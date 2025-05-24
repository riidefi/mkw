#include "mathTypes.hpp"

#include "mathConstants.hpp"

extern "C" {
extern const f32 unk_80387ea8;
extern const f32 unk_80387eac;
extern const f32 unk_80387eb0;

/*
const f32 unk_80387ea8 = 0.0f;
const f32 unk_80387eac = 1.0f;
const f32 unk_80387eb0 = ((2 * 3.141592653589793f) / 256.f);
*/
}

namespace nw4r {
namespace math {

MTX33* MTX33Identity(register MTX33* out) {
  register f32 n00 = unk_80387ea8;
  register f32 n11 = unk_80387eac;
  register f32 n10;
  asm
  {
    ps_merge00 n10, n11, n00
    psq_st n10, 0(out), 0, 0
    psq_st n00, 8(out), 0, 0
    psq_st n10, 16(out), 0, 0
    psq_st n00, 24(out), 0, 0
    stfs n11, 32(out)
  }
  return out;
}

MTX33* MTX34ToMTX33(register MTX33* out, const register MTX34* in) {
  register f32 _fp0, _fp1, _fp2, _fp3, _fp4, _fp5;
  asm
  {
    psq_l _fp0, 0(in), 0, 0
    psq_l _fp1, 8(in), 0, 0
    psq_l _fp2, 16(in), 0, 0
    psq_l _fp3, 24(in), 0, 0
    psq_l _fp4, 32(in), 0, 0
    psq_l _fp5, 40(in), 0, 0
    psq_st _fp0, 0(out), 0, 0
    psq_st _fp1, 8(out), 1, 0
    psq_st _fp2, 12(out),0, 0
    psq_st _fp3, 20(out), 1, 0
    psq_st _fp4, 24(out), 0, 0
    psq_st _fp5, 32(out), 1, 0
  }
  return out;
}

// clang-format off
asm u32 MTX34InvTranspose(register MTX33* inv, register const MTX34* in) {
  nofralloc
  psq_l fp0, 0(in), 1, 0;
  psq_l fp1, 4(in), 0, 0;
  psq_l fp2, 16(in), 1, 0;
  ps_merge10 fp6, fp1, fp0;
  psq_l fp3, 20(in), 0, 0;
  psq_l fp4, 32(in), 1, 0;
  ps_merge10 fp7, fp3, fp2;
  psq_l fp5, 36(in), 0, 0;
  ps_mul fp11, fp3, fp6;
  ps_merge10 fp8, fp5, fp4;
  ps_mul fp13, fp5, fp7;
  ps_msub fp11, fp1, fp7, fp11;
  ps_mul fp12, fp1, fp8;
  ps_msub fp13, fp3, fp8, fp13;
  ps_msub fp12, fp5, fp6, fp12;
  ps_mul fp10, fp3, fp4;
  ps_mul fp9, fp0, fp5;
  ps_mul fp8, fp1, fp2;
  ps_msub fp10, fp2, fp5, fp10;
  ps_msub fp9, fp1, fp4, fp9;
  ps_msub fp8, fp0, fp3, fp8;
  ps_mul fp7, fp0, fp13;
  ps_sub fp1, fp1, fp1;
  ps_madd fp7, fp2, fp12, fp7;
  ps_madd fp7, fp4, fp11, fp7;
  ps_cmpo0 cr0, fp7, fp1;
  bne loc0;
  li r3, 0;
  blr;
loc0:
  fres fp0, fp7;
  ps_add fp6, fp0, fp0;
  ps_mul fp5, fp0, fp0;
  ps_nmsub fp0, fp7, fp5, fp6;
  ps_add fp6, fp0, fp0;
  ps_mul fp5, fp0, fp0;
  ps_nmsub fp0, fp7, fp5, fp6;
  ps_muls0 fp13, fp13, fp0;
  ps_muls0 fp12, fp12, fp0;
  psq_st fp13, 0x00(r3), 0, 0;
  ps_muls0 fp11, fp11, fp0;
  psq_st fp12, 0x0c(r3), 0, 0;
  ps_muls0 fp10, fp10, fp0;
  psq_st fp11, 0x18(r3), 0, 0;
  ps_muls0 fp9, fp9, fp0;
  psq_st fp10, 0x8(r3), 1, 0;
  ps_muls0 fp8, fp8, fp0;
  psq_st fp9, 0x14(r3), 1, 0;
  psq_st fp8, 0x20(r3), 1, 0;
  li r3, 1;
  blr;
}
// clang-format on

MTX34* MTX34Zero(register MTX34* out) {
  register f32 zero = unk_80387ea8;
  asm
  {
    psq_st zero, 0(out), 0, 0;
    psq_st zero, 8(out), 0, 0;
    psq_st zero, 16(out), 0, 0;
    psq_st zero, 24(out), 0, 0;
    psq_st zero, 32(out), 0, 0;
    psq_st zero, 40(out), 0, 0;
  }
  return out;
}

MTX34* MTX34Mult(register MTX34* out, const register MTX34* in,
                 register f32 f) {
  register f32 a, b;
  asm
  {
    psq_l a, 0(in), 0, 0;
    ps_muls0 b, a, f;
    psq_st b, 0(out), 0, 0;

    psq_l a, 8(in), 0, 0;
    ps_muls0 b, a, f;
    psq_st b, 8(out), 0, 0;

    psq_l a, 16(in), 0, 0;
    ps_muls0 b, a, f;
    psq_st b, 16(out), 0, 0;

    psq_l a, 24(in), 0, 0;
    ps_muls0 b, a, f;
    psq_st b, 24(out), 0, 0;

    psq_l a, 32(in), 0, 0;
    ps_muls0 b, a, f;
    psq_st b, 32(out), 0, 0;

    psq_l a, 40(in), 0, 0;
    ps_muls0 b, a, f;
    psq_st b, 40(out), 0, 0;
  }
  return out;
}

MTX34* MTX34Scale(register MTX34* out, const register MTX34* in,
                  const register VEC3* scale) {
  register f32 xy, z1;
  register f32 r0a, r0b;
  register f32 r1a, r1b;
  register f32 r2a, r2b;
  asm
  {
    psq_l xy, 0(scale), 0, 0
    psq_l z1, 8(scale), 1, 0

    psq_l r0a, 0(in), 0, 0
    psq_l r0b, 8(in), 0, 0
    psq_l r1a, 16(in), 0, 0
    psq_l r1b, 24(in), 0, 0
    psq_l r2a, 32(in), 0, 0
    psq_l r2b, 40(in), 0, 0

    ps_mul r0a, r0a, xy
    ps_mul r1a, r1a, xy
    ps_mul r2a, r2a, xy
    ps_mul r0b, r0b, z1
    ps_mul r1b, r1b, z1
    ps_mul r2b, r2b, z1

    psq_st r0a, 0(out), 0, 0
    psq_st r0b, 8(out), 0, 0
    psq_st r1a, 16(out), 0, 0
    psq_st r1b, 24(out), 0, 0
    psq_st r2a, 32(out), 0, 0
    psq_st r2b, 40(out), 0, 0
  }
  return out;
}

MTX34* MTX34Trans(register MTX34* out, const register MTX34* in,
                  const register VEC3* trans) {
  register f32 xy, z1;
  register f32 vv0, vv1, vv2, vv3, vv4, vv5;
  register f32 tmp0, tmp1, tmp2;
  asm
  {
    psq_l vv0, 0(in), 0, 0;
    psq_st vv0, 0(out), 0, 0;
    psq_l vv1, 8(in), 0, 0;
    psq_st vv1, 8(out), 0, 0;
    psq_l vv2, 16(in), 0, 0;
    psq_st vv2, 16(out), 0, 0;
    psq_l vv3, 24(in), 0, 0;
    psq_st vv3, 24(out), 0, 0;
    psq_l vv4, 32(in), 0, 0;
    psq_st vv4, 32(out), 0, 0;
    psq_l vv5, 40(in), 0, 0;
    psq_st vv5, 40(out), 0, 0;
    psq_l xy, 0(trans), 0, 0;
    psq_l z1, 8(trans), 1, 0;
    ps_mul tmp0, vv0, xy;
    ps_madd tmp1, vv1, z1, tmp0;
    ps_sum0 tmp2, tmp1, tmp2, tmp1;
    psq_st tmp2, 12(out), 1, 0;
    ps_mul tmp0, vv2, xy;
    ps_madd tmp1, vv3, z1, tmp0;
    ps_sum0 tmp2, tmp1, tmp2, tmp1;
    psq_st tmp2, 28(out), 1, 0;
    ps_mul tmp0, vv4, xy;
    ps_madd tmp1, vv5, z1, tmp0;
    ps_sum0 tmp2, tmp1, tmp2, tmp1;
    psq_st tmp2, 44(out), 1, 0;
  }
  return out;
}

MTX34* MTX34MAdd(register MTX34* out, register f32 t, const register MTX34* m1,
                 const register MTX34* m2) {
  register f32 a, b, c;
  asm
  {
    psq_l a, 0(m1), 0, 0;
    psq_l b, 0(m2), 0, 0;
    ps_muls0 a, a, t;
    ps_add c, a, b;
    psq_st c, 0(out), 0, 0;

    psq_l a, 8(m1), 0, 0;
    psq_l b, 8(m2), 0, 0;
    ps_muls0 a, a, t;
    ps_add c, a, b;
    psq_st c, 8(out), 0, 0;

    psq_l a, 16(m1), 0, 0;
    psq_l b, 16(m2), 0, 0;
    ps_muls0 a, a, t;
    ps_add c, a, b;
    psq_st c, 16(out), 0, 0;

    psq_l a, 24(m1), 0, 0;
    psq_l b, 24(m2), 0, 0;
    ps_muls0 a, a, t;
    ps_add c, a, b;
    psq_st c, 24(out), 0, 0;

    psq_l a, 32(m1), 0, 0;
    psq_l b, 32(m2), 0, 0;
    ps_muls0 a, a, t;
    ps_add c, a, b;
    psq_st c, 32(out), 0, 0;

    psq_l a, 40(m1), 0, 0;
    psq_l b, 40(m2), 0, 0;
    ps_muls0 a, a, t;
    ps_add c, a, b;
    psq_st c, 40(out), 0, 0;
  }
  return out;
}

MTX34* MTX34RotAxisFIdx(MTX34* out, const VEC3* axis, f32 amnt) {
  PSMTXRotAxisRad(*out, *axis, unk_80387eb0 * amnt);
  return out;
}

} // namespace math
} // namespace nw4r

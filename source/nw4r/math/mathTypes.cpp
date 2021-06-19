#include "mathTypes.h"

namespace nw4r {
namespace math {

MTX33* MTX33Identity(register MTX33* out) {
  register f32 n00 = 0.0f;
  register f32 n11 = 1.0f;
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

} // namespace math
} // namespace nw4r

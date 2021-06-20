#include "mtx.h"

asm void PSVECAdd(const register Vec* vv1, const register Vec* vv2,
                  register Vec* out) {
  nofralloc;
  psq_l fp2, 0(vv1), 0, 0;
  psq_l fp4, 0(vv2), 0, 0;
  ps_add fp6, fp2, fp4;
  psq_st fp6, 0(out), 0, 0;
  psq_l fp3, 8(vv1), 1, 0;
  psq_l fp5, 8(vv2), 1, 0;
  ps_add fp7, fp3, fp5;
  psq_st fp7, 8(out), 1, 0;
  blr;
}

void PSVECScale(const register Vec* in, register Vec* out, register f32 vv1) {
  register f32 vxy, vz, rxy, rz;
  asm
  {
    psq_l vxy, 0(in), 0, 0;
    psq_l vz,  8(in), 1, 0;
    ps_muls0 rxy, vxy, vv1;
    psq_st rxy, 0(out), 0, 0;
    ps_muls0 rz, vz, vv1;
    psq_st rz, 8(out), 1, 0;
  }
}

void PSVECNormalize(const register Vec* vec1, register Vec* dst) {
  register f32 vv1 = 0.5F;
  register f32 vv2 = 3.0F;
  register f32 vv3, vv4;
  register f32 vv5, vv6;
  register f32 vv7;
  register f32 vv8;
  register f32 vv9, vv10;

  asm
  {
    psq_l    vv3, 0(vec1), 0, 0;
    ps_mul   vv6, vv3, vv3;
    psq_l    vv4, 8(vec1), 1, 0;
    ps_madd  vv5, vv4, vv4, vv6;
    ps_sum0  vv7, vv5, vv4, vv6;
    frsqrte  vv8, vv7;
    fmuls    vv9, vv8, vv8;
    fmuls    vv10, vv8, vv1;
    fnmsubs  vv9, vv9, vv7, vv2;
    fmuls    vv8, vv9, vv10;
    ps_muls0 vv3, vv3, vv8;
    psq_st   vv3, 0(dst), 0, 0;
    ps_muls0 vv4, vv4, vv8;
    psq_st   vv4, 8(dst), 1, 0;
  }
}

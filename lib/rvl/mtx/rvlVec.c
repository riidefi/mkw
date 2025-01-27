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

f32 PSVECMag(const register Vec* v) {
  register f32 vv1, vv2, vv3;
  register f32 vv4, vv5, vv6;
  register f32 vv7, vv8, vv9;
  vv8 = 0.5F;
  asm {
    psq_l   vv1, 0(v), 0, 0;
    ps_mul  vv1, vv1, vv1;
    lfs     vv2, 8(v);
    fsubs   vv9, vv8, vv8;
    ps_madd vv3, vv2, vv2, vv1;
    ps_sum0 vv3, vv3, vv1, vv1;
    fcmpu   cr0, vv3, vv9;
    beq-    end;
    frsqrte vv4, vv3;
  }
  vv7 = 3.0F;
  asm {
    fmuls   vv5, vv4, vv4;
    fmuls   vv6, vv4, vv8;
    fnmsubs vv5, vv5, vv3, vv7;
    fmuls   vv4, vv5, vv6;
    fmuls   vv3, vv3, vv4;
  end:
  }
  return vv3;
}

asm f32 PSVECDotProduct(const register Vec* vec1, const register Vec* vec2) {
  nofralloc;
  psq_l fp2, 4(vec1), 0, 0;
  psq_l fp3, 4(vec2), 0, 0;
  ps_mul fp2, fp2, fp3;
  psq_l fp5, 0(vec1), 0, 0;
  psq_l fp4, 0(vec2), 0, 0;
  ps_madd fp3, fp5, fp4, fp2;
  ps_sum0 fp1, fp3, fp2, fp2;
  blr;
}

asm void PSVECCrossProduct(const register Vec* vec1, const register Vec* vec2,
                           register Vec* out) {
  nofralloc;
  psq_l fp1, 0(vec2), 0, 0;
  lfs fp2, 8(vec1);
  psq_l fp0, 0(vec1), 0, 0;
  ps_merge10 fp6, fp1, fp1;
  lfs fp3, 8(vec2);
  ps_mul fp4, fp1, fp2;
  ps_muls0 fp7, fp1, fp0;
  ps_msub fp5, fp0, fp3, fp4;
  ps_msub fp8, fp0, fp6, fp7;
  ps_merge11 fp9, fp5, fp5;
  ps_merge01 fp10, fp5, fp8;
  psq_st fp9, 0(out), 1, 0;
  ps_neg fp10, fp10;
  psq_st fp10, 4(out), 0, 0;
  blr;
}

void C_VECHalfAngle(const Vec* a, const Vec* b, Vec* half) {
  Vec vv1, vv2, vv3;

  vv1.x = -a->x;
  vv1.y = -a->y;
  vv1.z = -a->z;

  vv2.x = -b->x;
  vv2.y = -b->y;
  vv2.z = -b->z;

  PSVECNormalize(&vv1, &vv1);
  PSVECNormalize(&vv2, &vv2);

  PSVECAdd(&vv1, &vv2, &vv3);

  if (PSVECDotProduct(&vv3, &vv3) > 0.0F)
    PSVECNormalize(&vv3, half);
  else
    *half = vv3;
}

f32 PSVECSquareDistance(const register Vec* vec1, const register Vec* vec2) {
  register f32 vv1, vv2, vv3, vv4, vv5, vv6;
  register f32 out;
  asm
  {
    psq_l vv1, 4(vec1), 0, 0;
    psq_l vv2, 4(vec2), 0, 0;
    ps_sub vv5, vv1, vv2;
    psq_l vv3, 0(vec1), 0, 0;
    psq_l vv4, 0(vec2), 0, 0;
    ps_mul vv5, vv5, vv5;
    ps_sub vv6, vv3, vv4;
    ps_madd out, vv6, vv6, vv5;
    ps_sum0 out, out, vv5, vv5;
  }
  return out;
}

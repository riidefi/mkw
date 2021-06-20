#include "mtx.h"

void PSQUATMultiply(const register Quaternion* quat1,
                    const register Quaternion* quat2,
                    register Quaternion* out) {
  register f32 vv1, vv2, vv3, vv4;
  register f32 vv5, vv6, vv7, vv8;
  register f32 vv9, vvA, vvB, vvC;
  asm
  {
    psq_l vv1, 0(quat1), 0, 0;
    psq_l vv2, 8(quat1), 0, 0;
    psq_l vv3, 0(quat2), 0, 0;
    ps_neg vv7, vv1;
    psq_l vv4, 8(quat2), 0, 0;
    ps_neg vv8, vv2;
    ps_merge01 vv5, vv7, vv1;
    ps_muls0 vv9, vv2, vv3;
    ps_muls0 vvA, vv7, vv3;
    ps_merge01 vv6, vv8, vv2;
    ps_muls1 vvC, vv5, vv3;
    ps_madds0 vv9, vv5, vv4, vv9;
    ps_muls1 vvB, vv6, vv3;
    ps_madds0 vvA, vv6, vv4, vvA;
    ps_madds1 vvC, vv8, vv4, vvC;
    ps_merge10 vv9, vv9, vv9;
    ps_madds1 vvB, vv1, vv4, vvB;
    ps_merge10 vvA, vvA, vvA;
    ps_add vv9, vv9, vvB;
    psq_st vv9, 0(out), 0, 0;
    ps_sub vvA, vvA, vvC;
    psq_st vvA, 8(out), 0, 0;
  }
}

void PSQUATScale(const register Quaternion* quat1, register Quaternion* quat2,
                 register f32 ff1) {
  register f32 vv1, vv2;
  asm
  {
    psq_l    vv1, 0(quat1), 0, 0;
    psq_l    vv2, 8(quat1), 0, 0;
    ps_muls0 vv1, vv1, ff1;
    psq_st   vv1, 0(quat2), 0, 0;
    ps_muls0 vv2, vv2, ff1;
    psq_st   vv2, 8(quat2), 0, 0;
  }
}

f32 PSQUATDotProduct(const register Quaternion* quat1,
                     const register Quaternion* quat2) {
  register f32 vv1, vv2, vv3, vv4, out;
  asm
  {
    psq_l vv1, 0(quat1), 0, 0;
    psq_l vv3, 0(quat2), 0, 0;
    ps_mul out, vv1, vv3;
    psq_l vv2, 8(quat1), 0, 0;
    psq_l vv4, 8(quat2), 0, 0;
    ps_madd out, vv2, vv4, out;
    ps_sum0 out, out, out, out;
  }
  return out;
}

void PSQUATNormalize(const register Quaternion* src,
                     register Quaternion* unit) {
  // sdata2
  (void)0.00001f;
  (void)1.0f;
  (void)0.0f;
  (void)0.5f;
  (void)3.0f;

  register f32 vv1, vv2, vv3;
  register f32 vv4, vv5, vv6;
  register f32 vv7, vv8;
  register f32 vv9 = 0.00001f;
  register f32 vvA = 0.5F;
  register f32 vvB = 3.0F;
  asm
  {
    psq_l    vv1, 0(src), 0, 0;
    ps_mul   vv3, vv1, vv1;
    psq_l    vv2, 8(src), 0, 0;
    ps_sub   vv6, vv9, vv9;
    ps_madd  vv3, vv2, vv2, vv3;
    ps_sum0  vv3, vv3, vv3, vv3;
    frsqrte  vv4, vv3;
    ps_sub   vv5, vv3, vv9;
    fmul     vv7, vv4, vv4;
    fmul     vv8, vv4, vvA;
    fnmsub   vv7, vv7, vv3, vvB;
    fmul     vv4, vv7, vv8;
    ps_sel   vv4, vv5, vv4, vv6;
    ps_muls0 vv1, vv1, vv4;
    ps_muls0 vv2, vv2, vv4;
    psq_st   vv1, 0(unit), 0, 0;
    psq_st   vv2, 8(unit), 0, 0;
  }
}

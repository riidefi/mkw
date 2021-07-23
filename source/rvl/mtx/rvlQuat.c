#include "mtx.h"

#include <math.h>

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

void PSQUATInverse(const register Quaternion* src, register Quaternion* inv) {
  register f32 vv1, vv2, vv3, vv4;
  register f32 vv5, vv6, vv7, vv8, vv9, vvA, vvB;
  register f32 vvC = 1.0F;
  asm {
    psq_l       vv1, 0(src), 0, 0;
    ps_mul      vv5, vv1, vv1;
    ps_sub      vvB, vvC, vvC;
    psq_l       vv2, 8(src), 0, 0;
    ps_madd     vv5, vv2, vv2, vv5;
    ps_add      vvA, vvC, vvC;
    ps_sum0     vv5, vv5, vv5, vv5;
    fcmpu       cr0, vv5, vvB;
    beq-        loc0;
    fres        vv7, vv5;
    ps_neg      vv6, vv5;
    ps_nmsub    vv9, vv5, vv7, vvA;
    ps_mul      vv7, vv7, vv9;
    b           loc1;
loc0:
    fmr         vv7, vvC;
loc1:
    ps_neg      vv8, vv7;
    ps_muls1    vv4, vv7, vv2;
    ps_muls0    vv1, vv1, vv8;
    psq_st      vv4, 12(inv), 1, 0;
    ps_muls0    vv3, vv2, vv8;
    psq_st      vv1, 0(inv), 0, 0;
    psq_st      vv3, 8(inv), 1, 0;
  }
}

void C_QUATMtx(Quaternion* r, const Mtx m) {
  f32 vv0, vv1;
  s32 i, j, k;
  s32 idx[3] = {1, 2, 0};
  f32 vec[3];
  vv0 = m[0][0] + m[1][1] + m[2][2];
  if (vv0 > 0.0f) {
    vv1 = (f32)sqrtf(vv0 + 1.0f);
    r->w = vv1 * 0.5f;
    vv1 = 0.5f / vv1;
    r->x = (m[2][1] - m[1][2]) * vv1;
    r->y = (m[0][2] - m[2][0]) * vv1;
    r->z = (m[1][0] - m[0][1]) * vv1;
  } else {
    i = 0;
    if (m[1][1] > m[0][0])
      i = 1;
    if (m[2][2] > m[i][i])
      i = 2;
    j = idx[i];
    k = idx[j];
    vv1 = (f32)sqrtf((m[i][i] - (m[j][j] + m[k][k])) + 1.0f);
    vec[i] = vv1 * 0.5f;
    if (vv1 != 0.0f)
      vv1 = 0.5f / vv1;
    r->w = (m[k][j] - m[j][k]) * vv1;
    vec[j] = (m[i][j] + m[j][i]) * vv1;
    vec[k] = (m[i][k] + m[k][i]) * vv1;
    r->x = vec[0];
    r->y = vec[1];
    r->z = vec[2];
  }
}

void C_QUATLerp(const Quaternion* quat1, const Quaternion* quat2,
                Quaternion* out, f32 f) {
  out->x = f * (quat2->x - quat1->x) + quat1->x;
  out->y = f * (quat2->y - quat1->y) + quat1->y;
  out->z = f * (quat2->z - quat1->z) + quat1->z;
  out->w = f * (quat2->w - quat1->w) + quat1->w;
}

void C_QUATSlerp(const Quaternion* quat1, const Quaternion* quat2,
                 Quaternion* out, f32 f) {
  f32 vv1, vv2, vv3, vv4, vv5;

  vv3 = quat1->x * quat2->x + quat1->y * quat2->y + quat1->z * quat2->z +
        quat1->w * quat2->w;
  vv5 = 1.0F;

  if (vv3 < 0.0F) {
    vv3 = -vv3;
    vv5 = -vv5;
  }

  if (vv3 <= 1.0F - 0.00001f) {
    vv1 = acosf(vv3);
    vv2 = sinf(vv1);
    vv4 = sinf((1.0F - f) * vv1) / vv2;
    vv5 *= sinf(f * vv1) / vv2;
  } else {
    vv4 = 1.0F - f;
    vv5 = vv5 * f;
  }

  out->x = vv4 * quat1->x + vv5 * quat2->x;
  out->y = vv4 * quat1->y + vv5 * quat2->y;
  out->z = vv4 * quat1->z + vv5 * quat2->z;
  out->w = vv4 * quat1->w + vv5 * quat2->w;
}

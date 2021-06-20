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

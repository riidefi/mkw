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

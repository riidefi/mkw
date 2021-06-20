#include "mtx.h"

void PSMTXIdentity(register Mtx m) {
  1.0F;
  register f32 tmp0 = 0.0F;
  register f32 tmp1 = 1.0F;
  register f32 tmp2;
  register f32 tmp3;
  asm
  {
    psq_st tmp0, 8(m), 0, 0;
    ps_merge01 tmp2, tmp0, tmp1;
    psq_st tmp0, 24(m), 0, 0;
    ps_merge10 tmp3, tmp1, tmp0;
    psq_st tmp0, 32(m), 0, 0;
    psq_st tmp2, 16(m), 0, 0;
    psq_st tmp3, 0(m), 0, 0;
    psq_st tmp3, 40(m), 0, 0;
  }
}

asm void PSMTXCopy(const register Mtx in, register Mtx out) {
  nofralloc;
  psq_l fp0, 0(in), 0, 0;
  psq_st fp0, 0(out), 0, 0;
  psq_l fp1, 8(in), 0, 0;
  psq_st fp1, 8(out), 0, 0;
  psq_l fp2, 16(in), 0, 0;
  psq_st fp2, 16(out), 0, 0;
  psq_l fp3, 24(in), 0, 0;
  psq_st fp3, 24(out), 0, 0;
  psq_l fp4, 32(in), 0, 0;
  psq_st fp4, 32(out), 0, 0;
  psq_l fp5, 40(in), 0, 0;
  psq_st fp5, 40(out), 0, 0;
  blr;
}

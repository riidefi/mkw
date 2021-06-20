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

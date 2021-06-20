#include "mtx.h"

static f32 Unit01[] = { 0.0f, 1.0f };

void PSMTXIdentity(register Mtx m) {
  (void) 1.0F; // need this to force force 1 to appear first in sdata2
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

asm void PSMTXConcat(const register Mtx mA, const register Mtx mB,
                     register Mtx mAB) {
  nofralloc;
  stwu r1, -64(r1);
  psq_l fp0, 0(mA), 0, 0;
  stfd fp14, 8(r1);
  psq_l fp6, 0(mB), 0, 0;
  addis r6, 0, Unit01 @ha;
  psq_l fp7, 8(mB), 0, 0;
  stfd fp15, 16(r1);
  addi r6, r6, Unit01 @l;
  stfd fp31, 40(r1);
  psq_l fp8, 16(mB), 0, 0;
  ps_muls0 fp12, fp6, fp0;
  psq_l fp2, 16(mA), 0, 0;
  ps_muls0 fp13, fp7, fp0;
  psq_l fp31, 0(r6), 0, 0;
  ps_muls0 fp14, fp6, fp2;
  psq_l fp9, 24(mB), 0, 0;
  ps_muls0 fp15, fp7, fp2;
  psq_l fp1, 8(mA), 0, 0;
  ps_madds1 fp12, fp8, fp0, fp12;
  psq_l fp3, 24(mA), 0, 0;
  ps_madds1 fp14, fp8, fp2, fp14;
  psq_l fp10, 32(mB), 0, 0;
  ps_madds1 fp13, fp9, fp0, fp13;
  psq_l fp11, 40(mB), 0, 0;
  ps_madds1 fp15, fp9, fp2, fp15;
  psq_l fp4, 32(mA), 0, 0;
  psq_l fp5, 40(mA), 0, 0;
  ps_madds0 fp12, fp10, fp1, fp12;
  ps_madds0 fp13, fp11, fp1, fp13;
  ps_madds0 fp14, fp10, fp3, fp14;
  ps_madds0 fp15, fp11, fp3, fp15;
  psq_st fp12, 0(mAB), 0, 0;
  ps_muls0 fp2, fp6, fp4;
  ps_madds1 fp13, fp31, fp1, fp13;
  ps_muls0 fp0, fp7, fp4;
  psq_st fp14, 16(mAB), 0, 0;
  ps_madds1 fp15, fp31, fp3, fp15;
  psq_st fp13, 8(mAB), 0, 0;
  ps_madds1 fp2, fp8, fp4, fp2;
  ps_madds1 fp0, fp9, fp4, fp0;
  ps_madds0 fp2, fp10, fp5, fp2;
  lfd fp14, 8(r1);
  psq_st fp15, 24(mAB), 0, 0;
  ps_madds0 fp0, fp11, fp5, fp0;
  psq_st fp2, 32(mAB), 0, 0;
  ps_madds1 fp0, fp31, fp5, fp0;
  lfd fp15, 16(r1);
  psq_st fp0, 40(mAB), 0, 0;
  lfd fp31, 40(r1);
  addi r1, r1, 64;
  blr;
}

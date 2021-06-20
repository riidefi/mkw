#include "mtx.h"

static f32 Unit01[] = {0.0f, 1.0f};

void PSMTXIdentity(register Mtx m) {
  (void)1.0F; // need this to force force 1 to appear first in sdata2
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

void PSMTXConcatArray(const register Mtx mtx1, const register Mtx* mtx2,
                      register Mtx* mtx3, register u32 vv4) {
  register f32 va0, va1, va2, va3, va4, va5;
  register f32 vb0, vb1, vb2, vb3, vb4, vb5;
  register f32 vd0, vd1, vd2, vd3, vd4, vd5;
  register f32 u01;
  register f32* u01Ptr = Unit01;

  asm {
    psq_l va0, 0(mtx1), 0, 0;
    psq_l va1, 8(mtx1), 0, 0;
    psq_l va2, 16(mtx1), 0, 0;
    psq_l va3, 24(mtx1), 0, 0;
    subi vv4, vv4, 1;
    psq_l va4, 32(mtx1), 0, 0;
    psq_l va5, 40(mtx1), 0, 0;
    mtctr vv4;
    psq_l u01, 0(u01Ptr), 0, 0;
    psq_l vb0, 0(mtx2), 0, 0;
    psq_l vb2, 16(mtx2), 0, 0;
    ps_muls0 vd0, vb0, va0;
    ps_muls0 vd2, vb0, va2;
    ps_muls0 vd4, vb0, va4;
    psq_l vb4, 32(mtx2), 0, 0;
    ps_madds1 vd0, vb2, va0, vd0;
    ps_madds1 vd2, vb2, va2, vd2;
    ps_madds1 vd4, vb2, va4, vd4;
    psq_l vb1, 8(mtx2), 0, 0;
    ps_madds0 vd0, vb4, va1, vd0;
    ps_madds0 vd2, vb4, va3, vd2;
    ps_madds0 vd4, vb4, va5, vd4;
    psq_l vb3, 24(mtx2), 0, 0;
    psq_st vd0, 0(mtx3), 0, 0;
    ps_muls0 vd1, vb1, va0;
    ps_muls0 vd3, vb1, va2;
    ps_muls0 vd5, vb1, va4;
    psq_l vb5, 40(mtx2), 0, 0;
    psq_st vd2, 16(mtx3), 0, 0;
    ps_madds1 vd1, vb3, va0, vd1;
    ps_madds1 vd3, vb3, va2, vd3;
    ps_madds1 vd5, vb3, va4, vd5;
_loop:
    addi mtx2, mtx2, sizeof(Mtx);
    ps_madds0 vd1, vb5, va1, vd1;
    ps_madds0 vd3, vb5, va3, vd3;
    ps_madds0 vd5, vb5, va5, vd5;
    psq_l vb0, 0(mtx2), 0, 0;
    psq_st vd4, 32(mtx3), 0, 0;
    ps_madd vd1, u01, va1, vd1;
    ps_madd vd3, u01, va3, vd3;
    ps_madd vd5, u01, va5, vd5;
    psq_l vb2, 16(mtx2), 0, 0;
    psq_st vd1, 8(mtx3), 0, 0;
    ps_muls0 vd0, vb0, va0;
    ps_muls0 vd2, vb0, va2;
    ps_muls0 vd4, vb0, va4;
    psq_l vb4, 32(mtx2), 0, 0;
    psq_st vd3, 24(mtx3), 0, 0;
    ps_madds1 vd0, vb2, va0, vd0;
    ps_madds1 vd2, vb2, va2, vd2;
    ps_madds1 vd4, vb2, va4, vd4;
    psq_l vb1, 8(mtx2), 0, 0;
    psq_st vd5, 40(mtx3), 0, 0;
    addi mtx3, mtx3, sizeof(Mtx);
    ps_madds0 vd0, vb4, va1, vd0;
    ps_madds0 vd2, vb4, va3, vd2;
    ps_madds0 vd4, vb4, va5, vd4;
    psq_l vb3, 24(mtx2), 0, 0;
    psq_st vd0, 0(mtx3), 0, 0;
    ps_muls0 vd1, vb1, va0;
    ps_muls0 vd3, vb1, va2;
    ps_muls0 vd5, vb1, va4;
    psq_l vb5, 40(mtx2), 0, 0;
    psq_st vd2, 16(mtx3), 0, 0;
    ps_madds1 vd1, vb3, va0, vd1;
    ps_madds1 vd3, vb3, va2, vd3;
    ps_madds1 vd5, vb3, va4, vd5;
    bdnz _loop;
    psq_st vd4, 32(mtx3), 0, 0;
    ps_madds0 vd1, vb5, va1, vd1;
    ps_madds0 vd3, vb5, va3, vd3;
    ps_madds0 vd5, vb5, va5, vd5;
    ps_madd vd1, u01, va1, vd1;
    ps_madd vd3, u01, va3, vd3;
    ps_madd vd5, u01, va5, vd5;
    psq_st vd1, 8(mtx3), 0, 0;
    psq_st vd3, 24(mtx3), 0, 0;
    psq_st vd5, 40(mtx3), 0, 0;
  }
}

asm u32 PSMTXInverse(const register Mtx src, register Mtx inv) {
  nofralloc;
  psq_l fp0, 0(src), 1, 0;
  psq_l fp1, 4(src), 0, 0;
  psq_l fp2, 16(src), 1, 0;
  ps_merge10 fp6, fp1, fp0;
  psq_l fp3, 20(src), 0, 0;
  psq_l fp4, 32(src), 1, 0;
  ps_merge10 fp7, fp3, fp2;
  psq_l fp5, 36(src), 0, 0;
  ps_mul fp11, fp3, fp6;
  ps_mul fp13, fp5, fp7;
  ps_merge10 fp8, fp5, fp4;
  ps_msub fp11, fp1, fp7, fp11;
  ps_mul fp12, fp1, fp8;
  ps_msub fp13, fp3, fp8, fp13;
  ps_mul fp10, fp3, fp4;
  ps_msub fp12, fp5, fp6, fp12;
  ps_mul fp9, fp0, fp5;
  ps_mul fp8, fp1, fp2;
  ps_sub fp6, fp6, fp6;
  ps_msub fp10, fp2, fp5, fp10;
  ps_mul fp7, fp0, fp13;
  ps_msub fp9, fp1, fp4, fp9;
  ps_madd fp7, fp2, fp12, fp7;
  ps_msub fp8, fp0, fp3, fp8;
  ps_madd fp7, fp4, fp11, fp7;
  ps_cmpo0 cr0, fp7, fp6;
  bne loc0;
  addi r3, 0, 0;
  blr;
loc0:
  fres fp0, fp7;
  ps_add fp6, fp0, fp0;
  ps_mul fp5, fp0, fp0;
  ps_nmsub fp0, fp7, fp5, fp6;
  lfs fp1, 12(src);
  ps_muls0 fp13, fp13, fp0;
  lfs fp2, 28(src);
  ps_muls0 fp12, fp12, fp0;
  lfs fp3, 44(src);
  ps_muls0 fp11, fp11, fp0;
  ps_merge00 fp5, fp13, fp12;
  ps_muls0 fp10, fp10, fp0;
  ps_merge11 fp4, fp13, fp12;
  ps_muls0 fp9, fp9, fp0;
  psq_st fp5, 0(inv), 0, 0;
  ps_mul fp6, fp13, fp1;
  psq_st fp4, 16(inv), 0, 0;
  ps_muls0 fp8, fp8, fp0;
  ps_madd fp6, fp12, fp2, fp6;
  psq_st fp10, 32(inv), 1, 0;
  ps_nmadd fp6, fp11, fp3, fp6;
  psq_st fp9, 36(inv), 1, 0;
  ps_mul fp7, fp10, fp1;
  ps_merge00 fp5, fp11, fp6;
  psq_st fp8, 40(inv), 1, 0;
  ps_merge11 fp4, fp11, fp6;
  psq_st fp5, 8(inv), 0, 0;
  ps_madd fp7, fp9, fp2, fp7;
  psq_st fp4, 24(inv), 0, 0;
  ps_nmadd fp7, fp8, fp3, fp7;
  addi r3, 0, 1;
  psq_st fp7, 44(inv), 1, 0;
  blr;
}

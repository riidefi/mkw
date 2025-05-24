#include "mtx.h"

#include <math.h>

static f32 Unit01[] = {0.0f, 1.0f};

void PSMTXIdentity(register Mtx m) {
  // sdata2 ordering
  (void)1.0f;
  (void)0.0f;

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

asm u32 PSMTXInvXpose(const register Mtx src, register Mtx invX) {
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
  ps_merge10 fp8, fp5, fp4;
  ps_mul fp13, fp5, fp7;
  ps_msub fp11, fp1, fp7, fp11;
  ps_mul fp12, fp1, fp8;
  ps_msub fp13, fp3, fp8, fp13;
  ps_msub fp12, fp5, fp6, fp12;
  ps_mul fp10, fp3, fp4;
  ps_mul fp9, fp0, fp5;
  ps_mul fp8, fp1, fp2;
  ps_msub fp10, fp2, fp5, fp10;
  ps_msub fp9, fp1, fp4, fp9;
  ps_msub fp8, fp0, fp3, fp8;
  ps_mul fp7, fp0, fp13;
  ps_sub fp1, fp1, fp1;
  ps_madd fp7, fp2, fp12, fp7;
  ps_madd fp7, fp4, fp11, fp7;
  ps_cmpo0 cr0, fp7, fp1;
  bne _regular;
  addi r3, 0, 0;
  blr;
_regular:
  fres fp0, fp7;
  psq_st fp1, 12(invX), 1, 0;
  ps_add fp6, fp0, fp0;
  ps_mul fp5, fp0, fp0;
  psq_st fp1, 28(invX), 1, 0;
  ps_nmsub fp0, fp7, fp5, fp6;
  psq_st fp1, 44(invX), 1, 0;
  ps_muls0 fp13, fp13, fp0;
  ps_muls0 fp12, fp12, fp0;
  ps_muls0 fp11, fp11, fp0;
  psq_st fp13, 0(invX), 0, 0;
  psq_st fp12, 16(invX), 0, 0;
  ps_muls0 fp10, fp10, fp0;
  ps_muls0 fp9, fp9, fp0;
  psq_st fp11, 32(invX), 0, 0;
  psq_st fp10, 8(invX), 1, 0;
  ps_muls0 fp8, fp8, fp0;
  addi r3, 0, 1;
  psq_st fp9, 24(invX), 1, 0;
  psq_st fp8, 40(invX), 1, 0;
  blr;
}

void PSMTXRotRad(Mtx m, char axis, f32 rad) {
  f32 sinA, cosA;
  sinA = sinf(rad);
  cosA = cosf(rad);
  PSMTXRotTrig(m, axis, sinA, cosA);
}

void PSMTXRotTrig(register Mtx m, register char arg2, register f32 arg3,
                  register f32 arg4) {
  register f32 vv1, vv2, vv3;
  register f32 vv4, vv5, vv6, vv7;

  asm {
    frsp arg3, arg3;
    frsp arg4, arg4;
  }

  vv1 = 0.0F;
  vv2 = 1.0F;

  asm {
    ori arg2, arg2, 0x20;
    ps_neg vv3, arg3;
    cmplwi arg2, 'x';
    beq loc0;
    cmplwi arg2, 'y';
    beq loc1;
    cmplwi arg2, 'z';
    beq loc2;
    b loc3;
loc0:
    psq_st vv2, 0(m), 1, 0;
    psq_st vv1, 4(m), 0, 0;
    ps_merge00 vv4, arg3, arg4;
    psq_st vv1, 12(m), 0, 0;
    ps_merge00 vv5, arg4, vv3;
    psq_st vv1, 28(m), 0, 0;
    psq_st vv1, 44(m), 1, 0;
    psq_st vv4, 36(m), 0, 0;
    psq_st vv5, 20(m), 0, 0;
    b loc3;
loc1:
    ps_merge00 vv4, arg4, vv1;
    ps_merge00 vv5, vv1, vv2;
    psq_st vv1, 24(m), 0, 0;
    psq_st vv4, 0(m), 0, 0;
    ps_merge00 vv6, vv3, vv1;
    ps_merge00 vv7, arg3, vv1;
    psq_st vv4, 40(m), 0, 0;
    psq_st vv5, 16(m), 0, 0;
    psq_st vv7, 8(m), 0, 0;
    psq_st vv6, 32(m), 0, 0;
    b loc3;
loc2:
    psq_st vv1, 8(m), 0, 0;
    ps_merge00 vv4, arg3, arg4;
    ps_merge00 vv6, arg4, vv3;
    psq_st vv1, 24(m), 0, 0;
    psq_st vv1, 32(m), 0, 0;
    ps_merge00 vv5, vv2, vv1;
    psq_st vv4, 16(m), 0, 0;
    psq_st vv6, 0(m), 0, 0;
    psq_st vv5, 40(m), 0, 0;
loc3:
  }
}

void __PSMTXRotAxisRadInternal(register Mtx m, const register Vec* arg2,
                               register f32 arg3, register f32 arg4) {
  register f32 vv1, vv2;
  register f32 tmp0, tmp1, tmp2, tmp3, tmp4;
  register f32 tmp5, tmp6, tmp7, tmp8, tmp9;
  tmp9 = 0.5F;
  tmp8 = 3.0F;
  asm
  {
    frsp arg4, arg4;
    psq_l tmp0, 0(arg2), 0, 0;
    frsp arg3, arg3;
    lfs tmp1, 8(arg2);
    ps_mul tmp2, tmp0, tmp0;
    fadds tmp7, tmp9, tmp9;
    ps_madd tmp3, tmp1, tmp1, tmp2;
    fsubs vv2, tmp9, tmp9;
    ps_sum0 tmp4, tmp3, tmp1, tmp2;
    fsubs vv1, tmp7, arg4;
    frsqrte tmp5, tmp4;
    fmuls tmp2, tmp5, tmp5;
    fmuls tmp3, tmp5, tmp9;
    fnmsubs tmp2, tmp2, tmp4, tmp8;
    fmuls tmp5, tmp2, tmp3;
    ps_merge00  arg4, arg4, arg4;
    ps_muls0 tmp0, tmp0, tmp5;
    ps_muls0 tmp1, tmp1, tmp5;
    ps_muls0 tmp4, tmp0, vv1;
    ps_muls0 tmp9, tmp0, arg3;
    ps_muls0 tmp5, tmp1, vv1;
    ps_muls1 tmp3, tmp4, tmp0;
    ps_muls0 tmp2, tmp4, tmp0;
    ps_muls0 tmp4, tmp4, tmp1;
    fnmsubs tmp6, tmp1, arg3, tmp3;
    fmadds tmp7, tmp1, arg3, tmp3;
    ps_neg tmp0, tmp9;
    ps_sum0 tmp8, tmp4, vv2, tmp9;
    ps_sum0 tmp2, tmp2, tmp6, arg4;
    ps_sum1 tmp3, arg4, tmp7, tmp3;
    ps_sum0 tmp6, tmp0, vv2, tmp4;
    psq_st tmp8, 8(m), 0, 0;
    ps_sum0 tmp0, tmp4, tmp4, tmp0;
    psq_st tmp2, 0(m), 0, 0;
    ps_muls0 tmp5, tmp5, tmp1;
    psq_st tmp3, 16(m), 0, 0;
    ps_sum1 tmp4, tmp9, tmp0, tmp4;
    psq_st tmp6, 24(m), 0, 0;
    ps_sum0 tmp5, tmp5, vv2, arg4;
    psq_st tmp4, 32(m), 0, 0;
    psq_st tmp5, 40(m), 0, 0;
  }
}

void PSMTXRotAxisRad(Mtx m, const Vec* arg2, f32 arg3) {
  f32 arg2sin = sinf(arg3);
  f32 arg2cos = cosf(arg3);
  __PSMTXRotAxisRadInternal(m, arg2, arg2sin, arg2cos);
}

void PSMTXTrans(register Mtx m, register f32 _x, register f32 _y,
                register f32 _z) {
  register f32 vv0 = 0.0f;
  register f32 vv1 = 1.0f;
  asm
  {
    stfs _x, 12(m);
    stfs _y, 28(m);
    psq_st vv0, 4(m), 0, 0;
    psq_st vv0, 32(m), 0, 0;
    stfs vv0, 16(m);
    stfs vv1, 20(m);
    stfs vv0, 24(m);
    stfs vv1, 40(m);
    stfs _z, 44(m);
    stfs vv1, 0(m);
  }
}

asm void PSMTXTransApply(const register Mtx in, register Mtx out,
                         register f32 _x, register f32 _y, register f32 _z) {
  nofralloc;
  psq_l fp4, 0(in), 0, 0;
  frsp _x, _x;
  psq_l fp5, 8(in), 0, 0;
  frsp _y, _y;
  psq_l fp7, 24(in), 0, 0;
  frsp _z, _z;
  psq_l fp8, 40(in), 0, 0;
  psq_st fp4, 0(out), 0, 0;
  ps_sum1 fp5, _x, fp5, fp5;
  psq_l fp6, 16(in), 0, 0;
  psq_st fp5, 8(out), 0, 0;
  ps_sum1 fp7, _y, fp7, fp7;
  psq_l fp9, 32(in), 0, 0;
  psq_st fp6, 16(out), 0, 0;
  ps_sum1 fp8, _z, fp8, fp8;
  psq_st fp7, 24(out), 0, 0;
  psq_st fp9, 32(out), 0, 0;
  psq_st fp8, 40(out), 0, 0;
  blr;
}

void PSMTXScale(register Mtx m, register f32 _x, register f32 _y,
                register f32 _z) {
  register f32 vv0 = 0.0F;
  asm
  {
    stfs _x, 0(m);
    psq_st vv0, 4(m), 0, 0;
    psq_st vv0, 12(m), 0, 0;
    stfs _y, 20(m);
    psq_st vv0, 24(m), 0, 0;
    psq_st vv0, 32(m), 0, 0;
    stfs _z, 40(m);
    stfs vv0, 44(m);
  }
}

asm void PSMTXScaleApply(const register Mtx in, register Mtx out,
                         register f32 _x, register f32 _y, register f32 _z) {
  nofralloc;
  frsp _x, _x;
  psq_l fp4, 0(in), 0, 0;
  frsp _y, _y;
  psq_l fp5, 8(in), 0, 0;
  frsp _z, _z;
  ps_muls0 fp4, fp4, _x;
  psq_l fp6, 16(in), 0, 0;
  ps_muls0 fp5, fp5, _x;
  psq_l fp7, 24(in), 0, 0;
  ps_muls0 fp6, fp6, _y;
  psq_l fp8, 32(in), 0, 0;
  psq_st fp4, 0(out), 0, 0;
  ps_muls0 fp7, fp7, _y;
  psq_l fp2, 40(in), 0, 0;
  psq_st fp5, 8(out), 0, 0;
  ps_muls0 fp8, fp8, _z;
  psq_st fp6, 16(out), 0, 0;
  ps_muls0 fp2, fp2, _z;
  psq_st fp7, 24(out), 0, 0;
  psq_st fp8, 32(out), 0, 0;
  psq_st fp2, 40(out), 0, 0;
  blr;
}

void PSMTXQuat(register Mtx m, const register Quaternion* quat) {
  register f32 vv0, vv1, vv2, vv3;
  register f32 tmp0, tmp1, tmp2, tmp3, tmp4;
  register f32 tmp5, tmp6, tmp7, tmp8, tmp9;
  vv1 = 1.0f;
  asm
  {
    psq_l tmp0, 0(quat), 0, 0;
    psq_l tmp1, 8(quat), 0, 0;
    fsubs vv0, vv1, vv1;
    fadds vv2, vv1, vv1;
    ps_mul tmp2, tmp0, tmp0;
    ps_merge10 tmp5, tmp0, tmp0;
    ps_madd tmp4, tmp1, tmp1, tmp2;
    ps_mul tmp3, tmp1, tmp1;
    ps_sum0 vv3, tmp4, tmp4, tmp4;
    ps_muls1 tmp7, tmp5, tmp1;
    fres tmp9, vv3;
    ps_sum1 tmp4, tmp3, tmp4, tmp2;
    ps_nmsub vv3, vv3, tmp9, vv2;
    ps_muls1 tmp6, tmp1, tmp1;
    ps_mul vv3, tmp9, vv3;
    ps_sum0 tmp2, tmp2, tmp2, tmp2;
    fmuls vv3, vv3, vv2;
    ps_madd tmp8, tmp0, tmp5, tmp6;
    ps_msub tmp6, tmp0, tmp5, tmp6;
    psq_st vv0, 12(m), 1, 0;
    ps_nmsub tmp2, tmp2, vv3, vv1;
    ps_nmsub tmp4, tmp4, vv3, vv1;
    psq_st vv0, 44(m), 1, 0;
    ps_mul tmp8, tmp8, vv3;
    ps_mul tmp6, tmp6, vv3;
    psq_st tmp2, 40(m), 1, 0;
    ps_madds0 tmp5, tmp0, tmp1, tmp7;
    ps_merge00 tmp1, tmp8, tmp4;
    ps_nmsub tmp7, tmp7, vv2, tmp5;
    ps_merge10 tmp0, tmp4, tmp6;
    psq_st tmp1, 16(m), 0, 0;
    ps_mul tmp5, tmp5, vv3;
    ps_mul tmp7, tmp7, vv3;
    psq_st tmp0,  0(m), 0, 0;
    psq_st tmp5,  8(m), 1, 0;
    ps_merge10 tmp3, tmp7, vv0;
    ps_merge01 tmp9, tmp7, tmp5;
    psq_st tmp3, 24(m), 0, 0;
    psq_st tmp9, 32(m), 0, 0;
  }
}

void C_MTXLookAt(Mtx m, const Vec* _pos, const Vec* _up, const Vec* _dest) {
  Vec vv0, vv1, vv2;
  vv0.x = _pos->x - _dest->x;
  vv0.y = _pos->y - _dest->y;
  vv0.z = _pos->z - _dest->z;
  PSVECNormalize(&vv0, &vv0);
  PSVECCrossProduct(_up, &vv0, &vv1);
  PSVECNormalize(&vv1, &vv1);
  PSVECCrossProduct(&vv0, &vv1, &vv2);
  m[0][0] = vv1.x;
  m[0][1] = vv1.y;
  m[0][2] = vv1.z;
  m[0][3] = -(_pos->x * vv1.x + _pos->y * vv1.y + _pos->z * vv1.z);
  m[1][0] = vv2.x;
  m[1][1] = vv2.y;
  m[1][2] = vv2.z;
  m[1][3] = -(_pos->x * vv2.x + _pos->y * vv2.y + _pos->z * vv2.z);
  m[2][0] = vv0.x;
  m[2][1] = vv0.y;
  m[2][2] = vv0.z;
  m[2][3] = -(_pos->x * vv0.x + _pos->y * vv0.y + _pos->z * vv0.z);
}

void C_MTXLightFrustum(Mtx m, float arg1, float arg2, float arg3, float arg4,
                       float arg5, float arg6, float arg7, float arg8,
                       float arg9) {
  f32 tmp = 1.0f / (arg4 - arg3);
  m[0][0] = ((2 * arg5) * tmp) * arg6;
  m[0][1] = 0.0f;
  m[0][2] = (((arg4 + arg3) * tmp) * arg6) - arg8;
  m[0][3] = 0.0f;
  tmp = 1.0f / (arg1 - arg2);
  m[1][0] = 0.0f;
  m[1][1] = ((2 * arg5) * tmp) * arg7;
  m[1][2] = (((arg1 + arg2) * tmp) * arg7) - arg9;
  m[1][3] = 0.0f;
  m[2][0] = 0.0f;
  m[2][1] = 0.0f;
  m[2][2] = -1.0f;
  m[2][3] = 0.0f;
}

void C_MTXLightPerspective(Mtx m, f32 arg1, f32 arg2, float arg3, float arg4,
                           float arg5, float arg6) {
  f32 angle = arg1 * 0.5f * 0.01745329252f;
  f32 cot = 1.0f / tanf(angle);
  m[0][0] = (cot / arg2) * arg3;
  m[0][1] = 0.0f;
  m[0][2] = -arg5;
  m[0][3] = 0.0f;
  m[1][0] = 0.0f;
  m[1][1] = cot * arg4;
  m[1][2] = -arg6;
  m[1][3] = 0.0f;
  m[2][0] = 0.0f;
  m[2][1] = 0.0f;
  m[2][2] = -1.0f;
  m[2][3] = 0.0f;
}

void C_MTXLightOrtho(Mtx m, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6,
                     f32 arg7, f32 arg8, f32 arg9) {
  f32 tmp;
  tmp = 1.0f / (arg5 - arg4);
  m[0][0] = (2.0f * tmp * arg6);
  m[0][1] = 0.0f;
  m[0][2] = 0.0f;
  m[0][3] = ((-(arg5 + arg4) * tmp) * arg6) + arg8;
  tmp = 1.0f / (arg2 - arg3);
  m[1][0] = 0.0f;
  m[1][1] = (2.0f * tmp) * arg7;
  m[1][2] = 0.0f;
  m[1][3] = ((-(arg2 + arg3) * tmp) * arg7) + arg9;
  m[2][0] = 0.0f;
  m[2][1] = 0.0f;
  m[2][2] = 0.0f;
  m[2][3] = 1.0f;
}

asm void PSMTXMultVec(const register Mtx m, const register Vec* in,
                      register Vec* out) {
  nofralloc;
  psq_l fp0, 0(in), 0, 0;
  psq_l fp2, 0(m), 0, 0;
  psq_l fp1, 8(in), 1, 0;
  ps_mul fp4, fp2, fp0;
  psq_l fp3, 8(m), 0, 0;
  ps_madd fp5, fp3, fp1, fp4;
  psq_l fp8, 16(m), 0, 0;
  ps_sum0 fp6, fp5, fp6, fp5;
  psq_l fp9, 24(m), 0, 0;
  ps_mul fp10, fp8, fp0;
  psq_st fp6, 0(out), 1, 0;
  ps_madd fp11, fp9, fp1, fp10;
  psq_l fp2, 32(m), 0, 0;
  ps_sum0 fp12, fp11, fp12, fp11;
  psq_l fp3, 40(m), 0, 0;
  ps_mul fp4, fp2, fp0;
  psq_st fp12, 4(out), 1, 0;
  ps_madd fp5, fp3, fp1, fp4;
  ps_sum0 fp6, fp5, fp6, fp5;
  psq_st fp6, 8(out), 1, 0;
  blr;
}

asm void PSMTXMultVecSR(const register Mtx m, const register Vec* in,
                        register Vec* out) {
  nofralloc;
  psq_l fp0, 0(m), 0, 0;
  psq_l fp6, 0(in), 0, 0;
  psq_l fp2, 16(m), 0, 0;
  ps_mul fp8, fp0, fp6;
  psq_l fp4, 32(m), 0, 0;
  ps_mul fp10, fp2, fp6;
  psq_l fp7, 8(in), 1, 0;
  ps_mul fp12, fp4, fp6;
  psq_l fp3, 24(m), 0, 0;
  ps_sum0 fp8, fp8, fp8, fp8;
  psq_l fp5, 40(m), 0, 0;
  ps_sum0 fp10, fp10, fp10, fp10;
  psq_l fp1, 8(m), 0, 0;
  ps_sum0 fp12, fp12, fp12, fp12;
  ps_madd fp9, fp1, fp7, fp8;
  psq_st fp9, 0(out), 1, 0;
  ps_madd fp11, fp3, fp7, fp10;
  psq_st fp11, 4(out), 1, 0;
  ps_madd fp13, fp5, fp7, fp12;
  psq_st fp13, 8(out), 1, 0;
  blr;
}

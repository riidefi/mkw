#include "eggDecomp.hpp"

#include <decomp.h>

#define getSZSExpandSize(src)                                                  \
  ((src[4] << 24) | (src[5] << 16) | (src[6] << 8) | src[7])

#define getASExpandSize(src) ((src[5] << 16) | (src[6] << 8) | src[7])

namespace EGG {
namespace Decomp {

long long unk_80386de8 = 0;
int unk_80386df0 = 0;
int unk_80386df4 = 0;
int unk_80386df8 = 0;
int unk_80386dfc = 0;
int unk_80386e00 = 0;
int unk_80386e04 = 0;
int unk_80386e08 = 0;

s32 decode(const u8* src, u8* dst) {
  switch (checkCompressed(src)) {
  case TYPE_SZS:
    return decodeSZS(src, dst);
  case TYPE_ASH:
    return decodeASH(src, dst);
  case TYPE_ASR:
    return decodeASR(src, dst);
  default:
    return -1;
  }
}

s32 decodeSZS(const u8* src, u8* dst) {

  long expandSize = getSZSExpandSize(src);
  long srcIdx = 0x10;
  u8 code = 0;

  u8 byte;

  for (long destIdx = 0; destIdx < expandSize; code >>= 1) {
    if (!code) {
      code = 0x80;
      byte = src[srcIdx++];
    }

    // Direct copy (code bit = 1)
    if (byte & code) {
      dst[destIdx++] = src[srcIdx++];
    }
    // RLE compressed data (code bit = 0)
    else {
      // Lower nibble of byte1 + byte2
      long distToDest = (src[srcIdx] << 8) | src[srcIdx + 1];
      srcIdx += sizeof(u8) * 2;
      long runSrcIdx = destIdx - (distToDest & 0xfff);

      // Upper nibble of byte 1
      long runLen = ((distToDest >> 12) == 0) ? src[srcIdx++] + 0x12
                                              : (distToDest >> 12) + 2;

      for (; runLen > 0; runLen--, destIdx++, runSrcIdx++) {
        dst[destIdx] = dst[runSrcIdx - 1];
      }
    }

    // Prepare next code bit
  }

  return expandSize;
}

// Symbol: decodeASH__Q23EGG6DecompFPUcPUc
// PAL: 0x80218dc0..0x80218ff0
MARK_BINARY_BLOB(decodeASH__Q23EGG6DecompFPUcPUc, 0x80218dc0, 0x80218ff0);
asm s32 decodeASH(const u8*, u8*) {
  // clang-format off
  nofralloc;
  stwu r1, -0x40(r1);
  mflr r0;
  lbz r10, 0xa(r3);
  addi r8, r13, -24080;
  stw r0, 0x44(r1);
  li r5, 0xc;
  lbz r0, 9(r3);
  li r9, 0;
  stmw r20, 0x10(r1);
  mr r22, r4;
  lbz r6, 0xb(r3);
  li r7, 0x200;
  lbz r4, 8(r3);
  slwi r0, r0, 0x10;
  lbz r11, 6(r3);
  rlwimi r6, r10, 8, 0x10, 0x17;
  rlwimi r0, r4, 0x18, 0, 7;
  lbz r12, 5(r3);
  slwi r10, r11, 8;
  lbz r11, 7(r3);
  rlwimi r10, r12, 0x10, 8, 0xf;
  or r12, r6, r0;
  addi r4, r13, -24064;
  addi r6, r13, -24072;
  li r0, 0x800;
  mr r21, r3;
  or r23, r11, r10;
  lwz r27, unk_80386de8;
  stw r5, unk_80386e00;
  li r5, 0;
  addi r26, r27, 0xffc;
  addi r25, r26, 0xffc;
  stw r12, 4(r4);
  addi r24, r25, 0x3ffc;
  li r4, 0x20;
  stw r9, 4(r8);
  addi r20, r24, 0x3ffc;
  stw r9, unk_80386df0;
  stw r7, unk_80386df8;
  stw r0, 4(r6);
  bl getBitsCode;
  mr r3, r21;
  li r4, 0x20;
  li r5, 1;
  bl getBitsCode;
  mr r3, r21;
  mr r4, r27;
  mr r5, r26;
  mr r6, r20;
  bl readTree9;
  mr r29, r3;
  mr r3, r21;
  mr r4, r25;
  mr r5, r24;
  mr r6, r20;
  bl readTree12;
  mr r28, r3;
  li r30, 0;
  b lbl_80218fd0;
lbl_80218eac:
  mr r31, r29;
  b lbl_80218edc;
lbl_80218eb4:
  mr r3, r21;
  li r4, 0;
  bl getBit1c;
  cmpwi r3, 0;
  beq lbl_80218ed4;
  slwi r0, r31, 1;
  lhzx r31, r26, r0;
  b lbl_80218edc;
lbl_80218ed4:
  slwi r0, r31, 1;
  lhzx r31, r27, r0;
lbl_80218edc:
  cmpwi r31, 0x200;
  bge lbl_80218eb4;
  cmpwi r31, 0x100;
  bge lbl_80218ef8;
  stbx r31, r22, r30;
  addi r30, r30, 1;
  b lbl_80218fd0;
lbl_80218ef8:
  mr r20, r28;
  b lbl_80218f28;
lbl_80218f00:
  mr r3, r21;
  li r4, 1;
  bl getBit1c;
  cmpwi r3, 0;
  beq lbl_80218f20;
  slwi r0, r20, 1;
  lhzx r20, r24, r0;
  b lbl_80218f28;
lbl_80218f20:
  slwi r0, r20, 1;
  lhzx r20, r25, r0;
lbl_80218f28:
  cmpwi r20, 0x800;
  bge lbl_80218f00;
  subf r4, r20, r30;
  addic. r31, r31, -253;
  addi r5, r4, -1;
  add r3, r22, r30;
  add r4, r22, r5;
  ble lbl_80218fd0;
  rlwinm. r0, r31, 0x1d, 3, 0x1f;
  mtctr r0;
  beq lbl_80218fb0;
lbl_80218f54:
  lbz r0, 0(r4);
  addi r30, r30, 8;
  stb r0, 0(r3);
  addi r5, r5, 8;
  lbz r0, 1(r4);
  stb r0, 1(r3);
  lbz r0, 2(r4);
  stb r0, 2(r3);
  lbz r0, 3(r4);
  stb r0, 3(r3);
  lbz r0, 4(r4);
  stb r0, 4(r3);
  lbz r0, 5(r4);
  stb r0, 5(r3);
  lbz r0, 6(r4);
  stb r0, 6(r3);
  lbz r0, 7(r4);
  addi r4, r4, 8;
  stb r0, 7(r3);
  addi r3, r3, 8;
  bdnz lbl_80218f54;
  andi. r31, r31, 7;
  beq lbl_80218fd0;
lbl_80218fb0:
  mtctr r31;
lbl_80218fb4:
  lbz r0, 0(r4);
  addi r5, r5, 1;
  stb r0, 0(r3);
  addi r3, r3, 1;
  addi r4, r4, 1;
  addi r30, r30, 1;
  bdnz lbl_80218fb4;
lbl_80218fd0:
  cmplw r30, r23;
  blt lbl_80218eac;
  mr r3, r30;
  lmw r20, 0x10(r1);
  lwz r0, 0x44(r1);
  mtlr r0;
  addi r1, r1, 0x40;
  blr;
  // clang-format on
}

// Symbol: decodeASR__Q23EGG6DecompFPUcPUc
// PAL: 0x80218ff0..0x802198f8
MARK_BINARY_BLOB(decodeASR__Q23EGG6DecompFPUcPUc, 0x80218ff0, 0x802198f8);
asm s32 decodeASR(const u8*, u8*) {
  // clang-format off
  nofralloc;
  stwu r1, -0x50(r1);
  li r11, 0x200;
  lbz r5, 6(r3);
  stmw r14, 8(r1);
  lbz r0, 4(r3);
  slwi r7, r5, 8;
  lbz r8, 5(r3);
  rlwinm. r0, r0, 0, 0x18, 0x18;
  lbz r0, 9(r3);
  rlwimi r7, r8, 0x10, 8, 0xf;
  lbz r8, 7(r3);
  lbz r5, 0xa(r3);
  lbz r6, 0xb(r3);
  slwi r0, r0, 0x10;
  rlwimi r6, r5, 8, 0x10, 0x17;
  lbz r5, 8(r3);
  or r24, r8, r7;
  rlwimi r0, r5, 0x18, 0, 7;
  or r23, r6, r0;
  beq lbl_80219044;
  li r11, 0x1000;
lbl_80219044:
  lwz r21, unk_80386de8;
  li r16, 0;
  li r8, 0x20;
  li r7, -1;
  addi r20, r21, 0x800;
  stw r16, 0x5004(r21);
  addi r19, r20, 0x804;
  mr r5, r21;
  addi r18, r19, 0x4000;
  mr r6, r20;
  li r17, -1;
  li r15, 0;
  stw r16, 0x800(r21);
  li r0, 1;
  mtctr r8;
lbl_80219080:
  stw r0, 0(r5);
  lwz r8, 0(r6);
  addi r8, r8, 1;
  stw r8, 4(r6);
  stw r0, 4(r5);
  lwz r8, 4(r6);
  addi r8, r8, 1;
  stw r8, 8(r6);
  stw r0, 8(r5);
  lwz r8, 8(r6);
  addi r8, r8, 1;
  stw r8, 0xc(r6);
  stw r0, 0xc(r5);
  lwz r8, 0xc(r6);
  addi r8, r8, 1;
  stw r8, 0x10(r6);
  stw r0, 0x10(r5);
  lwz r8, 0x10(r6);
  addi r8, r8, 1;
  stw r8, 0x14(r6);
  stw r0, 0x14(r5);
  lwz r8, 0x14(r6);
  addi r8, r8, 1;
  stw r8, 0x18(r6);
  stw r0, 0x18(r5);
  lwz r8, 0x18(r6);
  addi r8, r8, 1;
  stw r8, 0x1c(r6);
  stw r0, 0x1c(r5);
  lwz r8, 0x1c(r6);
  addi r8, r8, 1;
  stw r8, 0x20(r6);
  stw r0, 0x20(r5);
  lwz r8, 0x20(r6);
  addi r8, r8, 1;
  stw r8, 0x24(r6);
  stw r0, 0x24(r5);
  lwz r8, 0x24(r6);
  addi r8, r8, 1;
  stw r8, 0x28(r6);
  stw r0, 0x28(r5);
  lwz r8, 0x28(r6);
  addi r8, r8, 1;
  stw r8, 0x2c(r6);
  stw r0, 0x2c(r5);
  lwz r8, 0x2c(r6);
  addi r8, r8, 1;
  stw r8, 0x30(r6);
  stw r0, 0x30(r5);
  lwz r8, 0x30(r6);
  addi r8, r8, 1;
  stw r8, 0x34(r6);
  stw r0, 0x34(r5);
  lwz r8, 0x34(r6);
  addi r8, r8, 1;
  stw r8, 0x38(r6);
  stw r0, 0x38(r5);
  lwz r8, 0x38(r6);
  addi r8, r8, 1;
  stw r8, 0x3c(r6);
  stw r0, 0x3c(r5);
  addi r5, r5, 0x40;
  lwz r8, 0x3c(r6);
  addi r8, r8, 1;
  stwu r8, 0x40(r6);
  bdnz lbl_80219080;
  cmpwi cr1, r11, 0;
  li r8, 0;
  ble cr1, lbl_802192a8;
  cmpwi r11, 8;
  addi r10, r11, -8;
  ble lbl_80219270;
  li r6, 0;
  blt cr1, lbl_802191bc;
  lis r5, 0x8000;
  addi r0, r5, -2;
  cmpw r11, r0;
  bgt lbl_802191bc;
  li r6, 1;
lbl_802191bc:
  cmpwi r6, 0;
  beq lbl_80219270;
  addi r9, r10, 7;
  mr r5, r19;
  srwi r9, r9, 3;
  mr r6, r18;
  li r0, 1;
  mtctr r9;
  cmpwi r10, 0;
  ble lbl_80219270;
lbl_802191e4:
  stw r0, 0(r5);
  addi r8, r8, 8;
  lwz r9, 0(r6);
  addi r9, r9, 1;
  stw r9, 4(r6);
  stw r0, 4(r5);
  lwz r9, 4(r6);
  addi r9, r9, 1;
  stw r9, 8(r6);
  stw r0, 8(r5);
  lwz r9, 8(r6);
  addi r9, r9, 1;
  stw r9, 0xc(r6);
  stw r0, 0xc(r5);
  lwz r9, 0xc(r6);
  addi r9, r9, 1;
  stw r9, 0x10(r6);
  stw r0, 0x10(r5);
  lwz r9, 0x10(r6);
  addi r9, r9, 1;
  stw r9, 0x14(r6);
  stw r0, 0x14(r5);
  lwz r9, 0x14(r6);
  addi r9, r9, 1;
  stw r9, 0x18(r6);
  stw r0, 0x18(r5);
  lwz r9, 0x18(r6);
  addi r9, r9, 1;
  stw r9, 0x1c(r6);
  stw r0, 0x1c(r5);
  addi r5, r5, 0x20;
  lwz r9, 0x1c(r6);
  addi r9, r9, 1;
  stwu r9, 0x20(r6);
  bdnz lbl_802191e4;
lbl_80219270:
  slwi r5, r8, 2;
  subf r0, r8, r11;
  add r9, r19, r5;
  li r6, 1;
  add r10, r18, r5;
  mtctr r0;
  cmpw r8, r11;
  bge lbl_802192a8;
lbl_80219290:
  stw r6, 0(r9);
  addi r9, r9, 4;
  lwz r5, 0(r10);
  addi r0, r5, 1;
  stwu r0, 4(r10);
  bdnz lbl_80219290;
lbl_802192a8:
  lbz r8, 0xd(r3);
  add r6, r23, r3;
  lbzx r5, r3, r23;
  slwi r10, r11, 2;
  slwi r9, r8, 0x10;
  lbz r8, 0xc(r3);
  lbz r0, 1(r6);
  li r28, 0;
  rlwimi r9, r8, 0x18, 0, 7;
  lbz r8, 2(r6);
  lbz r6, 3(r6);
  slwi r0, r0, 0x10;
  rlwimi r0, r5, 0x18, 0, 7;
  rlwimi r6, r8, 8, 0x10, 0x17;
  or r26, r6, r0;
  lbz r14, 0xe(r3);
  lbz r12, 0xf(r3);
  li r22, 0x10;
  rlwimi r12, r14, 8, 0x10, 0x17;
  lis r5, 1;
  or r27, r12, r9;
  li r6, 0;
  lis r14, 0x8000;
  li r0, 0x40;
  addi r23, r23, 4;
  b lbl_802198e0;
lbl_80219310:
  lwz r25, 0x800(r20);
  subf r12, r16, r27;
  li r8, 0;
  li r9, 0x200;
  divwu r25, r7, r25;
  divwu r12, r12, r25;
  b lbl_8021935c;
lbl_8021932c:
  add r29, r8, r9;
  rlwinm r7, r29, 1, 0, 0x1d;
  lwzx r7, r20, r7;
  srawi r30, r29, 1;
  cmplw r12, r7;
  bge lbl_80219348;
  mr r9, r30;
lbl_80219348:
  slwi r7, r30, 2;
  lwzx r7, r20, r7;
  cmplw r12, r7;
  blt lbl_8021935c;
  addi r8, r30, 1;
lbl_8021935c:
  cmpw r8, r9;
  blt lbl_8021932c;
  slwi r7, r30, 2;
  addi r8, r30, 1;
  add r7, r20, r7;
  mtctr r8;
  cmpwi r30, 0;
  blt lbl_802193a0;
lbl_8021937c:
  lwz r8, 0(r7);
  cmplw r8, r12;
  bgt lbl_80219394;
  lwz r8, 4(r7);
  cmplw r12, r8;
  blt lbl_802193a0;
lbl_80219394:
  addi r7, r7, -4;
  addi r30, r30, -1;
  bdnz lbl_8021937c;
lbl_802193a0:
  slwi r31, r30, 2;
  mr r29, r30;
  lwzx r7, r20, r31;
  add r12, r20, r31;
  lwzx r8, r21, r31;
  mullw r9, r25, r7;
  addi r7, r8, 1;
  stwx r7, r21, r31;
  mullw r7, r25, r8;
  add r16, r16, r9;
  b lbl_802193d8;
lbl_802193cc:
  lwz r8, 0(r12);
  addi r8, r8, 1;
  stw r8, 0(r12);
lbl_802193d8:
  addi r30, r30, 1;
  addi r12, r12, 4;
  cmpwi r30, 0x200;
  ble lbl_802193cc;
  lwz r8, 0x800(r20);
  cmplw r8, r5;
  blt lbl_802194ec;
  mr r8, r21;
  mr r9, r20;
  stw r6, 0(r20);
  mtctr r0;
lbl_80219404:
  lwz r12, 0(r8);
  srwi r12, r12, 1;
  ori r25, r12, 1;
  stw r25, 0(r8);
  lwz r12, 0(r9);
  add r12, r12, r25;
  stw r12, 4(r9);
  lwz r12, 4(r8);
  srwi r12, r12, 1;
  ori r25, r12, 1;
  stw r25, 4(r8);
  lwz r12, 4(r9);
  add r12, r12, r25;
  stw r12, 8(r9);
  lwz r12, 8(r8);
  srwi r12, r12, 1;
  ori r25, r12, 1;
  stw r25, 8(r8);
  lwz r12, 8(r9);
  add r12, r12, r25;
  stw r12, 0xc(r9);
  lwz r12, 0xc(r8);
  srwi r12, r12, 1;
  ori r25, r12, 1;
  stw r25, 0xc(r8);
  lwz r12, 0xc(r9);
  add r12, r12, r25;
  stw r12, 0x10(r9);
  lwz r12, 0x10(r8);
  srwi r12, r12, 1;
  ori r25, r12, 1;
  stw r25, 0x10(r8);
  lwz r12, 0x10(r9);
  add r12, r12, r25;
  stw r12, 0x14(r9);
  lwz r12, 0x14(r8);
  srwi r12, r12, 1;
  ori r25, r12, 1;
  stw r25, 0x14(r8);
  lwz r12, 0x14(r9);
  add r12, r12, r25;
  stw r12, 0x18(r9);
  lwz r12, 0x18(r8);
  srwi r12, r12, 1;
  ori r25, r12, 1;
  stw r25, 0x18(r8);
  lwz r12, 0x18(r9);
  add r12, r12, r25;
  stw r12, 0x1c(r9);
  lwz r12, 0x1c(r8);
  srwi r12, r12, 1;
  ori r25, r12, 1;
  stw r25, 0x1c(r8);
  addi r8, r8, 0x20;
  lwz r12, 0x1c(r9);
  add r12, r12, r25;
  stwu r12, 0x20(r9);
  bdnz lbl_80219404;
lbl_802194ec:
  add r8, r3, r22;
  b lbl_80219510;
lbl_802194f4:
  lbz r9, 0(r8);
  slwi r12, r27, 8;
  slwi r16, r16, 8;
  slwi r7, r7, 8;
  add r27, r12, r9;
  addi r22, r22, 1;
  addi r8, r8, 1;
lbl_80219510:
  add r9, r16, r7;
  rlwinm r12, r16, 0, 0, 7;
  rlwinm r9, r9, 0, 0, 7;
  cmplw r12, r9;
  beq lbl_802194f4;
  add r8, r3, r22;
  b lbl_80219550;
lbl_8021952c:
  clrlwi r7, r16, 0x10;
  lbz r9, 0(r8);
  subf r7, r7, r5;
  slwi r12, r27, 8;
  slwi r7, r7, 8;
  slwi r16, r16, 8;
  add r27, r12, r9;
  addi r22, r22, 1;
  addi r8, r8, 1;
lbl_80219550:
  cmplw r7, r5;
  blt lbl_8021952c;
  cmpwi r29, 0x100;
  bge lbl_8021956c;
  stbx r29, r4, r28;
  addi r28, r28, 1;
  b lbl_802198e0;
lbl_8021956c:
  lwzx r8, r18, r10;
  subf r9, r15, r26;
  mr r25, r11;
  li r12, 0;
  divwu r8, r17, r8;
  divwu r9, r9, r8;
  b lbl_802195b8;
lbl_80219588:
  add r30, r12, r25;
  rlwinm r17, r30, 1, 0, 0x1d;
  lwzx r17, r18, r17;
  srawi r30, r30, 1;
  cmplw r9, r17;
  bge lbl_802195a4;
  mr r25, r30;
lbl_802195a4:
  slwi r17, r30, 2;
  lwzx r17, r18, r17;
  cmplw r9, r17;
  blt lbl_802195b8;
  addi r12, r30, 1;
lbl_802195b8:
  cmpw r12, r25;
  blt lbl_80219588;
  slwi r12, r30, 2;
  addi r17, r30, 1;
  add r12, r18, r12;
  mtctr r17;
  cmpwi r30, 0;
  blt lbl_802195fc;
lbl_802195d8:
  lwz r17, 0(r12);
  cmplw r17, r9;
  bgt lbl_802195f0;
  lwz r17, 4(r12);
  cmplw r9, r17;
  blt lbl_802195fc;
lbl_802195f0:
  addi r12, r12, -4;
  addi r30, r30, -1;
  bdnz lbl_802195d8;
lbl_802195fc:
  subf r12, r30, r28;
  addic. r29, r29, -253;
  addi r17, r12, -1;
  add r9, r4, r28;
  add r12, r4, r17;
  ble lbl_8021969c;
  rlwinm. r25, r29, 0x1d, 3, 0x1f;
  mtctr r25;
  beq lbl_8021967c;
lbl_80219620:
  lbz r25, 0(r12);
  addi r28, r28, 8;
  stb r25, 0(r9);
  addi r17, r17, 8;
  lbz r25, 1(r12);
  stb r25, 1(r9);
  lbz r25, 2(r12);
  stb r25, 2(r9);
  lbz r25, 3(r12);
  stb r25, 3(r9);
  lbz r25, 4(r12);
  stb r25, 4(r9);
  lbz r25, 5(r12);
  stb r25, 5(r9);
  lbz r25, 6(r12);
  stb r25, 6(r9);
  lbz r25, 7(r12);
  addi r12, r12, 8;
  stb r25, 7(r9);
  addi r9, r9, 8;
  bdnz lbl_80219620;
  andi. r29, r29, 7;
  beq lbl_8021969c;
lbl_8021967c:
  mtctr r29;
lbl_80219680:
  lbz r25, 0(r12);
  addi r17, r17, 1;
  stb r25, 0(r9);
  addi r9, r9, 1;
  addi r12, r12, 1;
  addi r28, r28, 1;
  bdnz lbl_80219680;
lbl_8021969c:
  slwi r17, r30, 2;
  lwzx r12, r18, r17;
  add r25, r18, r17;
  lwzx r9, r19, r17;
  mullw r12, r8, r12;
  addi r29, r9, 1;
  stwx r29, r19, r17;
  mullw r17, r8, r9;
  add r15, r15, r12;
  b lbl_802196d0;
lbl_802196c4:
  lwz r8, 0(r25);
  addi r8, r8, 1;
  stw r8, 0(r25);
lbl_802196d0:
  addi r30, r30, 1;
  addi r25, r25, 4;
  cmpw r30, r11;
  ble lbl_802196c4;
  lwzx r8, r18, r10;
  cmplw r8, r5;
  blt lbl_80219874;
  cmpwi cr1, r11, 0;
  stw r6, 0(r18);
  li r8, 0;
  ble cr1, lbl_80219874;
  cmpwi r11, 8;
  addi r9, r11, -8;
  ble lbl_80219830;
  li r25, 0;
  blt cr1, lbl_80219720;
  addi r12, r14, -2;
  cmpw r11, r12;
  bgt lbl_80219720;
  li r25, 1;
lbl_80219720:
  cmpwi r25, 0;
  beq lbl_80219830;
  addi r29, r9, 7;
  mr r12, r19;
  srwi r29, r29, 3;
  mr r25, r18;
  mtctr r29;
  cmpwi r9, 0;
  ble lbl_80219830;
lbl_80219744:
  lwz r9, 0(r12);
  addi r8, r8, 8;
  srwi r9, r9, 1;
  ori r29, r9, 1;
  stw r29, 0(r12);
  lwz r9, 0(r25);
  add r9, r9, r29;
  stw r9, 4(r25);
  lwz r9, 4(r12);
  srwi r9, r9, 1;
  ori r29, r9, 1;
  stw r29, 4(r12);
  lwz r9, 4(r25);
  add r9, r9, r29;
  stw r9, 8(r25);
  lwz r9, 8(r12);
  srwi r9, r9, 1;
  ori r29, r9, 1;
  stw r29, 8(r12);
  lwz r9, 8(r25);
  add r9, r9, r29;
  stw r9, 0xc(r25);
  lwz r9, 0xc(r12);
  srwi r9, r9, 1;
  ori r29, r9, 1;
  stw r29, 0xc(r12);
  lwz r9, 0xc(r25);
  add r9, r9, r29;
  stw r9, 0x10(r25);
  lwz r9, 0x10(r12);
  srwi r9, r9, 1;
  ori r29, r9, 1;
  stw r29, 0x10(r12);
  lwz r9, 0x10(r25);
  add r9, r9, r29;
  stw r9, 0x14(r25);
  lwz r9, 0x14(r12);
  srwi r9, r9, 1;
  ori r29, r9, 1;
  stw r29, 0x14(r12);
  lwz r9, 0x14(r25);
  add r9, r9, r29;
  stw r9, 0x18(r25);
  lwz r9, 0x18(r12);
  srwi r9, r9, 1;
  ori r29, r9, 1;
  stw r29, 0x18(r12);
  lwz r9, 0x18(r25);
  add r9, r9, r29;
  stw r9, 0x1c(r25);
  lwz r9, 0x1c(r12);
  srwi r9, r9, 1;
  ori r29, r9, 1;
  stw r29, 0x1c(r12);
  addi r12, r12, 0x20;
  lwz r9, 0x1c(r25);
  add r9, r9, r29;
  stwu r9, 0x20(r25);
  bdnz lbl_80219744;
lbl_80219830:
  slwi r12, r8, 2;
  subf r25, r8, r11;
  add r9, r19, r12;
  add r12, r18, r12;
  mtctr r25;
  cmpw r8, r11;
  bge lbl_80219874;
lbl_8021984c:
  lwz r25, 0(r9);
  addi r8, r8, 1;
  srwi r25, r25, 1;
  ori r29, r25, 1;
  stw r29, 0(r9);
  addi r9, r9, 4;
  lwz r25, 0(r12);
  add r25, r25, r29;
  stwu r25, 4(r12);
  bdnz lbl_8021984c;
lbl_80219874:
  add r8, r3, r23;
  b lbl_80219898;
lbl_8021987c:
  lbz r9, 0(r8);
  slwi r12, r26, 8;
  slwi r15, r15, 8;
  slwi r17, r17, 8;
  add r26, r12, r9;
  addi r23, r23, 1;
  addi r8, r8, 1;
lbl_80219898:
  add r9, r15, r17;
  rlwinm r12, r15, 0, 0, 7;
  rlwinm r9, r9, 0, 0, 7;
  cmplw r12, r9;
  beq lbl_8021987c;
  add r8, r3, r23;
  b lbl_802198d8;
lbl_802198b4:
  clrlwi r12, r15, 0x10;
  lbz r9, 0(r8);
  subf r17, r12, r5;
  slwi r15, r15, 8;
  slwi r12, r26, 8;
  addi r23, r23, 1;
  slwi r17, r17, 8;
  addi r8, r8, 1;
  add r26, r12, r9;
lbl_802198d8:
  cmplw r17, r5;
  blt lbl_802198b4;
lbl_802198e0:
  cmpw r28, r24;
  blt lbl_80219310;
  mr r3, r28;
  lmw r14, 8(r1);
  addi r1, r1, 0x50;
  blr;
  // clang-format on
}

CompressionType checkCompressed(const u8* src) {
  if ((src[0] == 'Y') && (src[1] == 'a') && (src[2] == 'z'))
    return TYPE_SZS;
  if ((src[0] == 'A') && (src[1] == 'S') && (src[2] == 'H'))
    return TYPE_ASH;
  if ((src[0] == 'A') && (src[1] == 'S') && (src[2] == 'R'))
    return TYPE_ASR;

  return TYPE_UNKNOWN;
}

s32 getExpandSize(const u8* src) {
  switch (checkCompressed(src)) {
  case TYPE_SZS:
    return getSZSExpandSize(src);
  case TYPE_ASH:
    return getASExpandSize(src);
  case TYPE_ASR:
    return getASExpandSize(src);
  default:
    return -1;
  }
}

// Symbol: getBitsCode__Q23EGG6DecompFPUcii
// PAL: 0x80219a7c..0x80219b84
MARK_BINARY_BLOB(getBitsCode__Q23EGG6DecompFPUcii, 0x80219a7c, 0x80219b84);
asm int getBitsCode(const u8*, int, int) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  slwi r0, r5, 2;
  addi r6, r13, -24080;
  addi r7, r13, -24064;
  stw r31, 0x1c(r1);
  addi r5, r13, -24056;
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  stw r28, 0x10(r1);
  lwzx r28, r6, r0;
  lwzx r29, r7, r0;
  add r31, r28, r4;
  lwzx r8, r5, r0;
  cmpwi r31, 0x20;
  ble lbl_80219b10;
  add r11, r29, r3;
  subfic r9, r4, 0x20;
  lbz r10, 1(r11);
  subfic r4, r4, 0x40;
  lbz r30, 2(r11);
  subf r4, r28, r4;
  lbz r12, 3(r11);
  slwi r10, r10, 0x10;
  lbzx r11, r3, r29;
  addi r28, r31, -32;
  addi r3, r29, 4;
  stwx r28, r6, r0;
  rlwimi r12, r30, 8, 0x10, 0x17;
  rlwimi r10, r11, 0x18, 0, 7;
  or r10, r12, r10;
  stwx r3, r7, r0;
  slw r3, r10, r28;
  srw r6, r8, r9;
  srw r4, r10, r4;
  stwx r3, r5, r0;
  or r3, r6, r4;
  b lbl_80219b6c;
lbl_80219b10:
  bne lbl_80219b58;
  add r11, r29, r3;
  subfic r30, r4, 0x20;
  lbz r10, 1(r11);
  addi r9, r29, 4;
  lbz r31, 2(r11);
  li r4, 0;
  lbz r12, 3(r11);
  slwi r10, r10, 0x10;
  lbzx r11, r3, r29;
  rlwimi r12, r31, 8, 0x10, 0x17;
  stwx r9, r7, r0;
  srw r3, r8, r30;
  rlwimi r10, r11, 0x18, 0, 7;
  or r7, r12, r10;
  stwx r7, r5, r0;
  stwx r4, r6, r0;
  b lbl_80219b6c;
lbl_80219b58:
  slw r3, r8, r4;
  subfic r7, r4, 0x20;
  stwx r3, r5, r0;
  srw r3, r8, r7;
  stwx r31, r6, r0;
lbl_80219b6c:
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  lwz r28, 0x10(r1);
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: getBit1c__Q23EGG6DecompFPUci
// PAL: 0x80219b84..0x80219c10
MARK_BINARY_BLOB(getBit1c__Q23EGG6DecompFPUci, 0x80219b84, 0x80219c10);
asm int getBit1c(const u8*, int) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  slwi r11, r4, 2;
  addi r9, r13, -24080;
  addi r8, r13, -24056;
  stw r31, 0xc(r1);
  addi r10, r13, -24064;
  lwzx r4, r9, r11;
  lwzx r0, r8, r11;
  cmpwi r4, 0x1f;
  lwzx r12, r10, r11;
  srwi r31, r0, 0x1f;
  bne lbl_80219bf0;
  add r6, r12, r3;
  addi r4, r12, 4;
  lbz r5, 1(r6);
  li r0, 0;
  lbz r7, 2(r6);
  lbz r6, 3(r6);
  slwi r5, r5, 0x10;
  lbzx r3, r3, r12;
  rlwimi r6, r7, 8, 0x10, 0x17;
  stwx r4, r10, r11;
  rlwimi r5, r3, 0x18, 0, 7;
  or r3, r6, r5;
  stwx r3, r8, r11;
  stwx r0, r9, r11;
  b lbl_80219c00;
lbl_80219bf0:
  slwi r3, r0, 1;
  addi r0, r4, 1;
  stwx r3, r8, r11;
  stwx r0, r9, r11;
lbl_80219c00:
  mr r3, r31;
  lwz r31, 0xc(r1);
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: readTree9__Q23EGG6DecompFPUcPUsPUsPUs
// PAL: 0x80219c10..0x80219d34
MARK_BINARY_BLOB(readTree9__Q23EGG6DecompFPUcPUsPUsPUs, 0x80219c10, 0x80219d34);
asm void readTree9(const u8*, unsigned short*, unsigned short*,
                   unsigned short*) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  stmw r25, 0x14(r1);
  mr r26, r3;
  mr r27, r4;
  mr r28, r5;
  mr r29, r6;
  li r30, 0;
  li r25, 0;
  lwz r31, unk_80386df8;
  mr r4, r31;
lbl_80219c40:
  lwz r5, unk_80386df0;
  lwz r0, unk_80386e08;
  cmpwi r5, 0x1f;
  lwz r3, unk_80386e00;
  srwi r8, r0, 0x1f;
  bne lbl_80219c90;
  add r5, r26, r3;
  addi r0, r3, 4;
  lbz r3, 1(r5);
  lbz r7, 2(r5);
  lbz r6, 3(r5);
  slwi r3, r3, 0x10;
  lbz r5, 0(r5);
  rlwimi r6, r7, 8, 0x10, 0x17;
  stw r0, unk_80386e00;
  rlwimi r3, r5, 0x18, 0, 7;
  or r0, r6, r3;
  stw r0, unk_80386e08;
  stw r25, unk_80386df0;
  b lbl_80219ca0;
lbl_80219c90:
  slwi r3, r0, 1;
  addi r0, r5, 1;
  stw r3, unk_80386e08;
  stw r0, unk_80386df0;
lbl_80219ca0:
  cmpwi r8, 0;
  beq lbl_80219cd0;
  slwi r0, r30, 1;
  ori r3, r4, 0x8000;
  add r5, r29, r0;
  addi r31, r31, 1;
  sth r3, 0(r5);
  ori r0, r4, 0x4000;
  addi r4, r4, 1;
  addi r30, r30, 2;
  sth r0, 2(r5);
  b lbl_80219c40;
lbl_80219cd0:
  mr r3, r26;
  li r4, 9;
  li r5, 0;
  bl getBitsCode;
  slwi r4, r30, 1;
lbl_80219ce4:
  addi r4, r4, -2;
  addi r30, r30, -1;
  lhzx r5, r29, r4;
  rlwinm. r0, r5, 0, 0x10, 0x10;
  beq lbl_80219d10;
  rlwinm r0, r5, 1, 0x11, 0x1e;
  cmpwi r30, 0;
  sthx r3, r28, r0;
  clrlwi r3, r5, 0x12;
  bne lbl_80219ce4;
  b lbl_80219d20;
lbl_80219d10:
  rlwinm r0, r5, 1, 0x11, 0x1e;
  mr r4, r31;
  sthx r3, r27, r0;
  b lbl_80219c40;
lbl_80219d20:
  lmw r25, 0x14(r1);
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: readTree12__Q23EGG6DecompFPUcPUsPUsPUs
// PAL: 0x80219d34..0x80219e68
MARK_BINARY_BLOB(readTree12__Q23EGG6DecompFPUcPUsPUsPUs, 0x80219d34,
                 0x80219e68);
asm void readTree12(const u8*, unsigned short*, unsigned short*,
                    unsigned short*) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  addi r7, r13, -24072;
  stw r0, 0x34(r1);
  stmw r22, 8(r1);
  mr r22, r3;
  mr r23, r4;
  mr r24, r5;
  mr r25, r6;
  li r26, 0;
  addi r30, r13, -24056;
  addi r31, r13, -24080;
  addi r28, r13, -24064;
  li r29, 0;
  lwz r27, 4(r7);
  mr r4, r27;
lbl_80219d74:
  lwz r5, 4(r31);
  lwz r0, 4(r30);
  cmpwi r5, 0x1f;
  lwz r3, 4(r28);
  srwi r8, r0, 0x1f;
  bne lbl_80219dc4;
  add r5, r22, r3;
  addi r0, r3, 4;
  lbz r3, 1(r5);
  lbz r7, 2(r5);
  lbz r6, 3(r5);
  slwi r3, r3, 0x10;
  lbz r5, 0(r5);
  rlwimi r6, r7, 8, 0x10, 0x17;
  stw r0, 4(r28);
  rlwimi r3, r5, 0x18, 0, 7;
  or r0, r6, r3;
  stw r0, 4(r30);
  stw r29, 4(r31);
  b lbl_80219dd4;
lbl_80219dc4:
  slwi r3, r0, 1;
  addi r0, r5, 1;
  stw r3, 4(r30);
  stw r0, 4(r31);
lbl_80219dd4:
  cmpwi r8, 0;
  beq lbl_80219e04;
  slwi r0, r26, 1;
  ori r3, r4, 0x8000;
  add r5, r25, r0;
  addi r27, r27, 1;
  sth r3, 0(r5);
  ori r0, r4, 0x4000;
  addi r4, r4, 1;
  addi r26, r26, 2;
  sth r0, 2(r5);
  b lbl_80219d74;
lbl_80219e04:
  mr r3, r22;
  li r4, 0xb;
  li r5, 1;
  bl getBitsCode;
  slwi r4, r26, 1;
lbl_80219e18:
  addi r4, r4, -2;
  addi r26, r26, -1;
  lhzx r5, r25, r4;
  rlwinm. r0, r5, 0, 0x10, 0x10;
  beq lbl_80219e44;
  rlwinm r0, r5, 1, 0x11, 0x1e;
  cmpwi r26, 0;
  sthx r3, r24, r0;
  clrlwi r3, r5, 0x12;
  bne lbl_80219e18;
  b lbl_80219e54;
lbl_80219e44:
  rlwinm r0, r5, 1, 0x11, 0x1e;
  mr r4, r27;
  sthx r3, r23, r0;
  b lbl_80219d74;
lbl_80219e54:
  lmw r22, 8(r1);
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

} // namespace Decomp
} // namespace EGG

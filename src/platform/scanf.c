#include <stdio.h>
#include <stdlib.h>

#include "va_arg.h"

// Extern function references.
// PAL: 0x8000eff8
extern UNKNOWN_FUNCTION(mbtowc);
// PAL: 0x8001365c
extern UNKNOWN_FUNCTION(__strtold);
// PAL: 0x80014e00
extern UNKNOWN_FUNCTION(__strtoull);

// Local functions.
// PAL: 0x80011c98..0x80012320
UNKNOWN_FUNCTION(parse_format);
// PAL: 0x80012320..0x80012fb8
UNKNOWN_FUNCTION(__sformatter);
// PAL: 0x80012fb8..0x80013040
UNKNOWN_FUNCTION(__StringRead);

// Symbol: parse_format
// PAL: 0x80011c98..0x80012320
MARK_BINARY_BLOB(parse_format, 0x80011c98, 0x80012320);
asm UNKNOWN_FUNCTION(parse_format) {
  // clang-format off
  nofralloc;
  stwu r1, -0x40(r1);
  lis r6, 0x8024;
  lbzu r5, 1(r3);
  stw r31, 0x3c(r1);
  extsb r5, r5;
  stw r30, 0x38(r1);
  cmpwi r5, 0x25;
  lwzu r0, 0x6650(r6);
  stw r0, 8(r1);
  lwz r30, 4(r6);
  lwz r31, 8(r6);
  lwz r12, 0xc(r6);
  lwz r11, 0x10(r6);
  lwz r10, 0x14(r6);
  lwz r9, 0x18(r6);
  lwz r8, 0x1c(r6);
  lwz r7, 0x20(r6);
  lwz r6, 0x24(r6);
  stw r30, 0xc(r1);
  stw r31, 0x10(r1);
  stw r12, 0x14(r1);
  stw r11, 0x18(r1);
  stw r10, 0x1c(r1);
  stw r9, 0x20(r1);
  stw r8, 0x24(r1);
  stw r7, 0x28(r1);
  stw r6, 0x2c(r1);
  bne lbl_80011d40;
  stb r5, 0xb(r1);
  addi r3, r3, 1;
  lwz r0, 8(r1);
  stw r0, 0(r4);
  stw r30, 4(r4);
  stw r31, 8(r4);
  stw r12, 0xc(r4);
  stw r11, 0x10(r4);
  stw r10, 0x14(r4);
  stw r9, 0x18(r4);
  stw r8, 0x1c(r4);
  stw r7, 0x20(r4);
  stw r6, 0x24(r4);
  b lbl_80012310;
lbl_80011d40:
  cmpwi r5, 0x2a;
  bne lbl_80011d58;
  lbzu r5, 1(r3);
  li r0, 1;
  stb r0, 8(r1);
  extsb r5, r5;
lbl_80011d58:
  cmplwi r5, 0xff;
  li r0, 1;
  bgt lbl_80011d68;
  li r0, 0;
lbl_80011d68:
  cmpwi r0, 0;
  beq lbl_80011d78;
  li r0, 0;
  b lbl_80011d94;
lbl_80011d78:
  lis r6, 0x8027;
  slwi r0, r5, 1;
  addi r6, r6, 0x1148;
  lwz r6, 0x38(r6);
  lwz r6, 8(r6);
  lhzx r0, r6, r0;
  rlwinm r0, r0, 0, 0x1c, 0x1c;
lbl_80011d94:
  cmpwi r0, 0;
  beq lbl_80011e74;
  lis r6, 0x8027;
  li r0, 0;
  addi r6, r6, 0x1148;
  stw r0, 0xc(r1);
  lwz r7, 0x38(r6);
lbl_80011db0:
  lwz r0, 0xc(r1);
  li r8, 1;
  mulli r0, r0, 0xa;
  add r6, r5, r0;
  lbzu r5, 1(r3);
  addi r0, r6, -48;
  stw r0, 0xc(r1);
  extsb r5, r5;
  cmplwi r5, 0xff;
  bgt lbl_80011ddc;
  li r8, 0;
lbl_80011ddc:
  cmpwi r8, 0;
  beq lbl_80011dec;
  li r0, 0;
  b lbl_80011dfc;
lbl_80011dec:
  lwz r6, 8(r7);
  slwi r0, r5, 1;
  lhzx r0, r6, r0;
  rlwinm r0, r0, 0, 0x1c, 0x1c;
lbl_80011dfc:
  cmpwi r0, 0;
  bne lbl_80011db0;
  lwz r6, 0xc(r1);
  cmpwi r6, 0;
  bne lbl_80011e6c;
  li r0, 0xff;
  stb r0, 0xb(r1);
  addi r3, r3, 1;
  lwz r0, 8(r1);
  stw r0, 0(r4);
  stw r6, 4(r4);
  lwz r5, 0x10(r1);
  lwz r0, 0x14(r1);
  stw r0, 0xc(r4);
  stw r5, 8(r4);
  lwz r5, 0x18(r1);
  lwz r0, 0x1c(r1);
  stw r0, 0x14(r4);
  stw r5, 0x10(r4);
  lwz r5, 0x20(r1);
  lwz r0, 0x24(r1);
  stw r0, 0x1c(r4);
  stw r5, 0x18(r4);
  lwz r5, 0x28(r1);
  lwz r0, 0x2c(r1);
  stw r0, 0x24(r4);
  stw r5, 0x20(r4);
  b lbl_80012310;
lbl_80011e6c:
  li r0, 1;
  stb r0, 9(r1);
lbl_80011e74:
  cmpwi r5, 0x68;
  li r7, 1;
  beq lbl_80011eac;
  cmpwi r5, 0x6c;
  beq lbl_80011ed8;
  cmpwi r5, 0x4c;
  beq lbl_80011f04;
  cmpwi r5, 0x6a;
  beq lbl_80011f10;
  cmpwi r5, 0x7a;
  beq lbl_80011f1c;
  cmpwi r5, 0x74;
  beq lbl_80011f28;
  b lbl_80011f34;
lbl_80011eac:
  lbz r0, 1(r3);
  li r6, 2;
  stb r6, 0xa(r1);
  extsb r6, r0;
  cmpwi r6, 0x68;
  bne lbl_80011f38;
  li r0, 1;
  stb r0, 0xa(r1);
  mr r5, r6;
  addi r3, r3, 1;
  b lbl_80011f38;
lbl_80011ed8:
  lbz r0, 1(r3);
  li r6, 3;
  stb r6, 0xa(r1);
  extsb r6, r0;
  cmpwi r6, 0x6c;
  bne lbl_80011f38;
  li r0, 7;
  stb r0, 0xa(r1);
  mr r5, r6;
  addi r3, r3, 1;
  b lbl_80011f38;
lbl_80011f04:
  li r0, 9;
  stb r0, 0xa(r1);
  b lbl_80011f38;
lbl_80011f10:
  li r0, 4;
  stb r0, 0xa(r1);
  b lbl_80011f38;
lbl_80011f1c:
  li r0, 5;
  stb r0, 0xa(r1);
  b lbl_80011f38;
lbl_80011f28:
  li r0, 6;
  stb r0, 0xa(r1);
  b lbl_80011f38;
lbl_80011f34:
  li r7, 0;
lbl_80011f38:
  cmpwi r7, 0;
  beq lbl_80011f48;
  lbzu r5, 1(r3);
  extsb r5, r5;
lbl_80011f48:
  addi r0, r5, -65;
  stb r5, 0xb(r1);
  cmplwi r0, 0x37;
  bgt lbl_800122b4;
  lis r5, 0x8027;
  slwi r0, r0, 2;
  addi r5, r5, 0x13c0;
  lwzx r5, r5, r0;
  mtctr r5;
  bctr;
  lbz r0, 0xa(r1);
  cmplwi r0, 9;
  bne lbl_800122bc;
  li r0, 0xff;
  stb r0, 0xb(r1);
  b lbl_800122bc;
  lbz r5, 0xa(r1);
  addi r0, r5, 0xfc;
  clrlwi r0, r0, 0x18;
  cmplwi r0, 3;
  ble lbl_80011fb8;
  addi r0, r5, 0xff;
  clrlwi r0, r0, 0x18;
  cmplwi r0, 1;
  ble lbl_80011fb8;
  cmplwi r5, 3;
  beq lbl_80011fc4;
  b lbl_800122bc;
lbl_80011fb8:
  li r0, 0xff;
  stb r0, 0xb(r1);
  b lbl_800122bc;
lbl_80011fc4:
  li r0, 8;
  stb r0, 0xa(r1);
  b lbl_800122bc;
  li r5, 3;
  li r0, 0x78;
  stb r5, 0xa(r1);
  stb r0, 0xb(r1);
  b lbl_800122bc;
  lbz r0, 0xa(r1);
  cmplwi r0, 3;
  bne lbl_80011ffc;
  li r0, 0xa;
  stb r0, 0xa(r1);
  b lbl_800122bc;
lbl_80011ffc:
  cmpwi r0, 0;
  beq lbl_800122bc;
  li r0, 0xff;
  stb r0, 0xb(r1);
  b lbl_800122bc;
  lbz r0, 0xa(r1);
  cmplwi r0, 3;
  bne lbl_80012028;
  li r0, 0xa;
  stb r0, 0xa(r1);
  b lbl_80012038;
lbl_80012028:
  cmpwi r0, 0;
  beq lbl_80012038;
  li r0, 0xff;
  stb r0, 0xb(r1);
lbl_80012038:
  li r6, 0xff;
  li r5, 0xc1;
  li r0, 0xfe;
  stb r6, 0x10(r1);
  stb r6, 0x12(r1);
  stb r6, 0x13(r1);
  stb r6, 0x15(r1);
  stb r6, 0x16(r1);
  stb r6, 0x17(r1);
  stb r6, 0x18(r1);
  stb r6, 0x19(r1);
  stb r6, 0x1a(r1);
  stb r6, 0x1b(r1);
  stb r6, 0x1c(r1);
  stb r6, 0x1d(r1);
  stb r6, 0x1e(r1);
  stb r6, 0x1f(r1);
  stb r6, 0x20(r1);
  stb r6, 0x21(r1);
  stb r6, 0x22(r1);
  stb r6, 0x23(r1);
  stb r6, 0x24(r1);
  stb r6, 0x25(r1);
  stb r6, 0x26(r1);
  stb r6, 0x27(r1);
  stb r6, 0x28(r1);
  stb r6, 0x29(r1);
  stb r6, 0x2a(r1);
  stb r6, 0x2b(r1);
  stb r6, 0x2c(r1);
  stb r6, 0x2d(r1);
  stb r6, 0x2e(r1);
  stb r6, 0x2f(r1);
  stb r5, 0x11(r1);
  stb r0, 0x14(r1);
  b lbl_800122bc;
  lbz r0, 0xa(r1);
  cmplwi r0, 3;
  bne lbl_800120e0;
  li r0, 0xa;
  stb r0, 0xa(r1);
  b lbl_800120f0;
lbl_800120e0:
  cmpwi r0, 0;
  beq lbl_800120f0;
  li r0, 0xff;
  stb r0, 0xb(r1);
lbl_800120f0:
  lbzu r10, 1(r3);
  li r11, 0;
  extsb r10, r10;
  cmpwi r10, 0x5e;
  bne lbl_80012110;
  lbzu r10, 1(r3);
  li r11, 1;
  extsb r10, r10;
lbl_80012110:
  cmpwi r10, 0x5d;
  bne lbl_8001212c;
  lbz r0, 0x1b(r1);
  lbzu r10, 1(r3);
  ori r0, r0, 0x20;
  stb r0, 0x1b(r1);
  extsb r10, r10;
lbl_8001212c:
  addi r8, r1, 8;
  li r5, 1;
  b lbl_800121b4;
lbl_80012138:
  rlwinm r6, r10, 0x1d, 0x1b, 0x1f;
  lbz r0, 1(r3);
  add r9, r8, r6;
  clrlwi r6, r10, 0x1d;
  lbz r7, 8(r9);
  slw r6, r5, r6;
  cmpwi r0, 0x2d;
  or r6, r7, r6;
  stb r6, 8(r9);
  bne lbl_800121ac;
  lbz r9, 2(r3);
  extsb. r9, r9;
  beq lbl_800121ac;
  cmpwi r9, 0x5d;
  beq lbl_800121ac;
  b lbl_80012194;
lbl_80012178:
  rlwinm r6, r10, 0x1d, 0x1b, 0x1f;
  clrlwi r0, r10, 0x1d;
  add r7, r8, r6;
  lbz r6, 8(r7);
  slw r0, r5, r0;
  or r0, r6, r0;
  stb r0, 8(r7);
lbl_80012194:
  addi r10, r10, 1;
  cmpw r10, r9;
  ble lbl_80012178;
  lbzu r10, 3(r3);
  extsb r10, r10;
  b lbl_800121b4;
lbl_800121ac:
  lbzu r10, 1(r3);
  extsb r10, r10;
lbl_800121b4:
  cmpwi r10, 0;
  beq lbl_800121c8;
  cmpwi r10, 0x5d;
  beq lbl_800121d4;
  b lbl_80012138;
lbl_800121c8:
  li r0, 0xff;
  stb r0, 0xb(r1);
  b lbl_800122bc;
lbl_800121d4:
  cmpwi r11, 0;
  beq lbl_800122bc;
  li r0, 2;
  addi r5, r1, 0x10;
  mtctr r0;
lbl_800121e8:
  lbz r0, 0(r5);
  nor r0, r0, r0;
  stb r0, 0(r5);
  lbz r0, 1(r5);
  nor r0, r0, r0;
  stb r0, 1(r5);
  lbz r0, 2(r5);
  nor r0, r0, r0;
  stb r0, 2(r5);
  lbz r0, 3(r5);
  nor r0, r0, r0;
  stb r0, 3(r5);
  lbz r0, 4(r5);
  nor r0, r0, r0;
  stb r0, 4(r5);
  lbz r0, 5(r5);
  nor r0, r0, r0;
  stb r0, 5(r5);
  lbz r0, 6(r5);
  nor r0, r0, r0;
  stb r0, 6(r5);
  lbz r0, 7(r5);
  nor r0, r0, r0;
  stb r0, 7(r5);
  lbz r0, 8(r5);
  nor r0, r0, r0;
  stb r0, 8(r5);
  lbz r0, 9(r5);
  nor r0, r0, r0;
  stb r0, 9(r5);
  lbz r0, 0xa(r5);
  nor r0, r0, r0;
  stb r0, 0xa(r5);
  lbz r0, 0xb(r5);
  nor r0, r0, r0;
  stb r0, 0xb(r5);
  lbz r0, 0xc(r5);
  nor r0, r0, r0;
  stb r0, 0xc(r5);
  lbz r0, 0xd(r5);
  nor r0, r0, r0;
  stb r0, 0xd(r5);
  lbz r0, 0xe(r5);
  nor r0, r0, r0;
  stb r0, 0xe(r5);
  lbz r0, 0xf(r5);
  nor r0, r0, r0;
  stb r0, 0xf(r5);
  addi r5, r5, 0x10;
  bdnz lbl_800121e8;
  b lbl_800122bc;
lbl_800122b4:
  li r0, 0xff;
  stb r0, 0xb(r1);
lbl_800122bc:
  lwz r5, 8(r1);
  addi r3, r3, 1;
  lwz r0, 0xc(r1);
  stw r0, 4(r4);
  stw r5, 0(r4);
  lwz r5, 0x10(r1);
  lwz r0, 0x14(r1);
  stw r0, 0xc(r4);
  stw r5, 8(r4);
  lwz r5, 0x18(r1);
  lwz r0, 0x1c(r1);
  stw r0, 0x14(r4);
  stw r5, 0x10(r4);
  lwz r5, 0x20(r1);
  lwz r0, 0x24(r1);
  stw r0, 0x1c(r4);
  stw r5, 0x18(r4);
  lwz r5, 0x28(r1);
  lwz r0, 0x2c(r1);
  stw r0, 0x24(r4);
  stw r5, 0x20(r4);
lbl_80012310:
  lwz r31, 0x3c(r1);
  lwz r30, 0x38(r1);
  addi r1, r1, 0x40;
  blr;
  // clang-format on
}

// Symbol: __sformatter
// PAL: 0x80012320..0x80012fb8
MARK_BINARY_BLOB(__sformatter, 0x80012320, 0x80012fb8);
asm UNKNOWN_FUNCTION(__sformatter) {
  // clang-format off
  nofralloc;
  stwu r1, -0xb0(r1);
  mflr r0;
  stw r0, 0xb4(r1);
  addi r11, r1, 0xb0;
  bl _savegpr_15;
  lis r8, 0x8027;
  li r0, 0;
  stw r0, 0x5c(r1);
  li r0, 0;
  mr r26, r3;
  mr r27, r4;
  stw r6, 8(r1);
  mr r17, r5;
  mr r28, r7;
  addi r25, r1, 0x20;
  stw r0, 0x58(r1);
  addi r23, r8, 0x1148;
  li r29, 0;
  li r21, 0;
  li r20, 0;
  li r19, 0;
  li r24, 1;
  b lbl_80012f60;
lbl_8001237c:
  cmplwi r22, 0xff;
  li r0, 1;
  bgt lbl_8001238c;
  li r0, 0;
lbl_8001238c:
  cmpwi r0, 0;
  beq lbl_8001239c;
  li r0, 0;
  b lbl_800123b0;
lbl_8001239c:
  lwz r3, 0x38(r23);
  slwi r0, r22, 1;
  lwz r3, 8(r3);
  lhzx r0, r3, r0;
  rlwinm r0, r0, 0, 0x17, 0x17;
lbl_800123b0:
  cmpwi r0, 0;
  beq lbl_80012488;
  lwz r4, 0x38(r23);
lbl_800123bc:
  lbzu r0, 1(r17);
  li r3, 1;
  extsb r0, r0;
  cmplwi r0, 0xff;
  bgt lbl_800123d4;
  li r3, 0;
lbl_800123d4:
  cmpwi r3, 0;
  beq lbl_800123e4;
  li r0, 0;
  b lbl_800123f4;
lbl_800123e4:
  lwz r3, 8(r4);
  slwi r0, r0, 1;
  lhzx r0, r3, r0;
  rlwinm r0, r0, 0, 0x17, 0x17;
lbl_800123f4:
  cmpwi r0, 0;
  bne lbl_800123bc;
  cmpwi r29, 0;
  bne lbl_80012f60;
  b lbl_8001240c;
lbl_80012408:
  addi r21, r21, 1;
lbl_8001240c:
  mr r12, r26;
  mr r3, r27;
  li r4, 0;
  li r5, 0;
  mtctr r12;
  bctrl;
  extsb r0, r3;
  stb r3, 0xc(r1);
  cmplwi r0, 0xff;
  li r4, 1;
  bgt lbl_8001243c;
  li r4, 0;
lbl_8001243c:
  cmpwi r4, 0;
  beq lbl_8001244c;
  li r0, 0;
  b lbl_80012460;
lbl_8001244c:
  lwz r4, 0x38(r23);
  slwi r0, r0, 1;
  lwz r4, 8(r4);
  lhzx r0, r4, r0;
  rlwinm r0, r0, 0, 0x17, 0x17;
lbl_80012460:
  cmpwi r0, 0;
  bne lbl_80012408;
  clrlwi r4, r3, 0x18;
  mr r12, r26;
  mr r3, r27;
  li r5, 1;
  extsb r4, r4;
  mtctr r12;
  bctrl;
  b lbl_80012f60;
lbl_80012488:
  cmpwi r22, 0x25;
  beq lbl_80012500;
  cmpwi r29, 0;
  bne lbl_80012500;
  mr r12, r26;
  mr r3, r27;
  li r4, 0;
  li r5, 0;
  mtctr r12;
  bctrl;
  extsb r4, r3;
  clrlwi r0, r22, 0x18;
  cmpw r0, r4;
  stb r3, 0xc(r1);
  beq lbl_800124f4;
  clrlwi r4, r3, 0x18;
  mr r12, r26;
  mr r3, r27;
  li r5, 1;
  extsb r4, r4;
  mtctr r12;
  bctrl;
  cmpwi r28, 0;
  beq lbl_80012f6c;
  li r29, 1;
  addi r17, r17, 1;
  b lbl_80012f60;
lbl_800124f4:
  addi r21, r21, 1;
  addi r17, r17, 1;
  b lbl_80012f60;
lbl_80012500:
  mr r3, r17;
  addi r4, r1, 0x20;
  bl parse_format;
  lbz r0, 0x20(r1);
  mr r17, r3;
  cmpwi r0, 0;
  bne lbl_8001253c;
  lbz r0, 0x23(r1);
  cmplwi r0, 0x25;
  beq lbl_8001253c;
  lwz r3, 8(r1);
  li r4, 1;
  bl __va_arg;
  lwz r22, 0(r3);
  b lbl_80012540;
lbl_8001253c:
  li r22, 0;
lbl_80012540:
  lbz r0, 0x23(r1);
  cmplwi r0, 0x6e;
  beq lbl_80012580;
  cmpwi r29, 0;
  bne lbl_80012580;
  mr r12, r26;
  mr r3, r27;
  li r4, 0;
  li r5, 2;
  mtctr r12;
  bctrl;
  cmpwi r3, 0;
  beq lbl_80012580;
  cmpwi r28, 0;
  beq lbl_80012f6c;
  li r29, 1;
lbl_80012580:
  lbz r3, 0x23(r1);
  addi r0, r3, -37;
  cmplwi r0, 0x53;
  bgt lbl_80012f6c;
  lis r3, 0x8027;
  slwi r0, r0, 2;
  addi r3, r3, 0x14e0;
  lwzx r3, r3, r0;
  mtctr r3;
  bctr;
  li r3, 0xa;
  b lbl_800125b4;
  li r3, 0;
lbl_800125b4:
  cmpwi r29, 0;
  beq lbl_800125d4;
  li r0, 0;
  stw r0, 0x5c(r1);
  li r0, 0;
  li r16, 0;
  stw r0, 0x58(r1);
  b lbl_800126c8;
lbl_800125d4:
  lbz r0, 0x22(r1);
  cmplwi r0, 7;
  beq lbl_800125e8;
  cmplwi r0, 4;
  bne lbl_80012610;
lbl_800125e8:
  lwz r4, 0x24(r1);
  mr r5, r26;
  mr r6, r27;
  addi r7, r1, 0x18;
  addi r8, r1, 0x14;
  addi r9, r1, 0x10;
  bl __strtoull;
  stw r4, 0x54(r1);
  stw r3, 0x50(r1);
  b lbl_80012630;
lbl_80012610:
  lwz r4, 0x24(r1);
  mr r5, r26;
  mr r6, r27;
  addi r7, r1, 0x18;
  addi r8, r1, 0x14;
  addi r9, r1, 0x10;
  bl __strtoul;
  mr r15, r3;
lbl_80012630:
  lwz r3, 0x18(r1);
  cmpwi r3, 0;
  bne lbl_80012660;
  cmpwi r28, 0;
  beq lbl_80012f6c;
  li r0, 0;
  stw r0, 0x5c(r1);
  li r0, 0;
  li r29, 1;
  stw r0, 0x58(r1);
  li r16, 0;
  b lbl_800126c8;
lbl_80012660:
  lbz r0, 0x22(r1);
  add r21, r21, r3;
  cmplwi r0, 7;
  beq lbl_80012678;
  cmplwi r0, 4;
  bne lbl_800126b4;
lbl_80012678:
  lwz r0, 0x14(r1);
  cmpwi r0, 0;
  beq lbl_800126a0;
  lwz r0, 0x54(r1);
  subfic r0, r0, 0;
  stw r0, 0x5c(r1);
  lwz r0, 0x50(r1);
  subfze r0, r0;
  stw r0, 0x58(r1);
  b lbl_800126c8;
lbl_800126a0:
  lwz r0, 0x54(r1);
  stw r0, 0x5c(r1);
  lwz r0, 0x50(r1);
  stw r0, 0x58(r1);
  b lbl_800126c8;
lbl_800126b4:
  lwz r0, 0x14(r1);
  mr r16, r15;
  cmpwi r0, 0;
  beq lbl_800126c8;
  neg r16, r15;
lbl_800126c8:
  cmpwi r22, 0;
  beq lbl_80012754;
  lbz r0, 0x22(r1);
  cmplwi r0, 7;
  bgt lbl_80012748;
  lis r3, 0x8027;
  slwi r0, r0, 2;
  addi r3, r3, 0x14c0;
  lwzx r3, r3, r0;
  mtctr r3;
  bctr;
  stw r16, 0(r22);
  b lbl_80012748;
  stb r16, 0(r22);
  b lbl_80012748;
  sth r16, 0(r22);
  b lbl_80012748;
  stw r16, 0(r22);
  b lbl_80012748;
  lwz r0, 0x5c(r1);
  stw r0, 4(r22);
  lwz r0, 0x58(r1);
  stw r0, 0(r22);
  b lbl_80012748;
  stw r16, 0(r22);
  b lbl_80012748;
  stw r16, 0(r22);
  b lbl_80012748;
  lwz r0, 0x5c(r1);
  stw r0, 4(r22);
  lwz r0, 0x58(r1);
  stw r0, 0(r22);
lbl_80012748:
  cmpwi r29, 0;
  bne lbl_80012754;
  addi r20, r20, 1;
lbl_80012754:
  addi r19, r19, 1;
  b lbl_80012f60;
  li r3, 8;
  b lbl_80012770;
  li r3, 0xa;
  b lbl_80012770;
  li r3, 0x10;
lbl_80012770:
  cmpwi r29, 0;
  beq lbl_80012790;
  li r0, 0;
  stw r0, 0x54(r1);
  li r0, 0;
  li r15, 0;
  stw r0, 0x50(r1);
  b lbl_80012860;
lbl_80012790:
  lbz r0, 0x22(r1);
  cmplwi r0, 7;
  beq lbl_800127a4;
  cmplwi r0, 4;
  bne lbl_800127cc;
lbl_800127a4:
  lwz r4, 0x24(r1);
  mr r5, r26;
  mr r6, r27;
  addi r7, r1, 0x18;
  addi r8, r1, 0x14;
  addi r9, r1, 0x10;
  bl __strtoull;
  stw r4, 0x54(r1);
  stw r3, 0x50(r1);
  b lbl_800127ec;
lbl_800127cc:
  lwz r4, 0x24(r1);
  mr r5, r26;
  mr r6, r27;
  addi r7, r1, 0x18;
  addi r8, r1, 0x14;
  addi r9, r1, 0x10;
  bl __strtoul;
  mr r15, r3;
lbl_800127ec:
  lwz r3, 0x18(r1);
  cmpwi r3, 0;
  bne lbl_8001281c;
  cmpwi r28, 0;
  beq lbl_80012f6c;
  li r0, 0;
  stw r0, 0x54(r1);
  li r0, 0;
  li r29, 1;
  stw r0, 0x50(r1);
  li r15, 0;
  b lbl_80012860;
lbl_8001281c:
  lwz r0, 0x14(r1);
  add r21, r21, r3;
  cmpwi r0, 0;
  beq lbl_80012860;
  lbz r0, 0x22(r1);
  cmplwi r0, 7;
  bne lbl_80012850;
  lwz r0, 0x54(r1);
  subfic r0, r0, 0;
  stw r0, 0x54(r1);
  lwz r0, 0x50(r1);
  subfze r0, r0;
  stw r0, 0x50(r1);
lbl_80012850:
  lbz r0, 0x22(r1);
  cmplwi r0, 7;
  beq lbl_80012860;
  neg r15, r15;
lbl_80012860:
  cmpwi r22, 0;
  beq lbl_800128ec;
  lbz r0, 0x22(r1);
  cmplwi r0, 7;
  bgt lbl_800128e0;
  lis r3, 0x8027;
  slwi r0, r0, 2;
  addi r3, r3, 0x14a0;
  lwzx r3, r3, r0;
  mtctr r3;
  bctr;
  stw r15, 0(r22);
  b lbl_800128e0;
  stb r15, 0(r22);
  b lbl_800128e0;
  sth r15, 0(r22);
  b lbl_800128e0;
  stw r15, 0(r22);
  b lbl_800128e0;
  lwz r0, 0x54(r1);
  stw r0, 4(r22);
  lwz r0, 0x50(r1);
  stw r0, 0(r22);
  b lbl_800128e0;
  stw r15, 0(r22);
  b lbl_800128e0;
  stw r15, 0(r22);
  b lbl_800128e0;
  lwz r0, 0x54(r1);
  stw r0, 4(r22);
  lwz r0, 0x50(r1);
  stw r0, 0(r22);
lbl_800128e0:
  cmpwi r29, 0;
  bne lbl_800128ec;
  addi r20, r20, 1;
lbl_800128ec:
  addi r19, r19, 1;
  b lbl_80012f60;
  cmpwi r29, 0;
  beq lbl_80012908;
  lis r3, 0x8038;
  lfs f1, 0x4c20(r3);
  b lbl_80012948;
lbl_80012908:
  lwz r3, 0x24(r1);
  mr r4, r26;
  mr r5, r27;
  addi r6, r1, 0x18;
  addi r7, r1, 0x10;
  bl __strtold;
  lwz r0, 0x18(r1);
  cmpwi r0, 0;
  bne lbl_80012944;
  cmpwi r28, 0;
  beq lbl_80012f6c;
  lis r3, 0x8038;
  li r29, 1;
  lfs f1, 0x4c20(r3);
  b lbl_80012948;
lbl_80012944:
  add r21, r21, r0;
lbl_80012948:
  cmpwi r22, 0;
  beq lbl_80012994;
  lbz r0, 0x22(r1);
  cmpwi r0, 0;
  beq lbl_80012970;
  cmpwi r0, 8;
  beq lbl_8001297c;
  cmpwi r0, 9;
  beq lbl_80012984;
  b lbl_80012988;
lbl_80012970:
  frsp f0, f1;
  stfs f0, 0(r22);
  b lbl_80012988;
lbl_8001297c:
  stfd f1, 0(r22);
  b lbl_80012988;
lbl_80012984:
  stfd f1, 0(r22);
lbl_80012988:
  cmpwi r29, 0;
  bne lbl_80012994;
  addi r20, r20, 1;
lbl_80012994:
  addi r19, r19, 1;
  b lbl_80012f60;
  lbz r0, 0x21(r1);
  cmpwi r0, 0;
  bne lbl_800129ac;
  stw r24, 0x24(r1);
lbl_800129ac:
  cmpwi r22, 0;
  beq lbl_80012adc;
  cmpwi r28, 0;
  beq lbl_800129d0;
  lwz r3, 8(r1);
  li r31, 1;
  li r4, 1;
  bl __va_arg;
  lwz r30, 0(r3);
lbl_800129d0:
  cmpwi r29, 0;
  li r0, 0;
  stw r0, 0x18(r1);
  beq lbl_800129f4;
  cmpwi r30, 0;
  beq lbl_80012f60;
  li r0, 0;
  stb r0, 0(r22);
  b lbl_80012f60;
lbl_800129f4:
  stw r22, 0x4c(r1);
  b lbl_80012a38;
lbl_800129fc:
  lbz r0, 0x22(r1);
  stb r3, 0xc(r1);
  cmplwi r0, 0xa;
  bne lbl_80012a24;
  mr r3, r22;
  addi r4, r1, 0xc;
  li r5, 1;
  bl mbtowc;
  addi r22, r22, 2;
  b lbl_80012a2c;
lbl_80012a24:
  stb r3, 0(r22);
  addi r22, r22, 1;
lbl_80012a2c:
  lwz r3, 0x18(r1);
  addi r0, r3, 1;
  stw r0, 0x18(r1);
lbl_80012a38:
  lwz r3, 0x24(r1);
  cmpwi r3, 0;
  addi r3, r3, -1;
  stw r3, 0x24(r1);
  beq lbl_80012a8c;
  cmpwi r28, 0;
  beq lbl_80012a68;
  xor r0, r30, r0;
  cntlzw r0, r0;
  slw r0, r30, r0;
  rlwinm. r31, r0, 1, 0x1f, 0x1f;
  beq lbl_80012a8c;
lbl_80012a68:
  mr r12, r26;
  mr r3, r27;
  li r4, 0;
  li r5, 0;
  mtctr r12;
  bctrl;
  cmpwi r3, -1;
  mr r18, r3;
  bne lbl_800129fc;
lbl_80012a8c:
  lwz r0, 0x18(r1);
  stb r18, 0xc(r1);
  cmpwi r0, 0;
  beq lbl_80012aac;
  cmpwi r28, 0;
  beq lbl_80012ad0;
  cmpwi r31, 0;
  bne lbl_80012ad0;
lbl_80012aac:
  cmpwi r28, 0;
  beq lbl_80012f6c;
  cmpwi r30, 0;
  li r29, 1;
  beq lbl_80012f60;
  lwz r3, 0x4c(r1);
  li r0, 0;
  stb r0, 0(r3);
  b lbl_80012f60;
lbl_80012ad0:
  add r21, r21, r0;
  addi r20, r20, 1;
  b lbl_80012b40;
lbl_80012adc:
  li r0, 0;
  stw r0, 0x18(r1);
  b lbl_80012af8;
lbl_80012ae8:
  lwz r4, 0x18(r1);
  stb r3, 0xc(r1);
  addi r0, r4, 1;
  stw r0, 0x18(r1);
lbl_80012af8:
  lwz r3, 0x24(r1);
  cmpwi r3, 0;
  addi r0, r3, -1;
  stw r0, 0x24(r1);
  beq lbl_80012b30;
  mr r12, r26;
  mr r3, r27;
  li r4, 0;
  li r5, 0;
  mtctr r12;
  bctrl;
  cmpwi r3, -1;
  mr r18, r3;
  bne lbl_80012ae8;
lbl_80012b30:
  lwz r0, 0x18(r1);
  stb r18, 0xc(r1);
  cmpwi r0, 0;
  beq lbl_80012f6c;
lbl_80012b40:
  addi r19, r19, 1;
  b lbl_80012f60;
  cmpwi r29, 0;
  bne lbl_80012f60;
  b lbl_80012b58;
lbl_80012b54:
  addi r21, r21, 1;
lbl_80012b58:
  mr r12, r26;
  mr r3, r27;
  li r4, 0;
  li r5, 0;
  mtctr r12;
  bctrl;
  extsb r0, r3;
  stb r3, 0xc(r1);
  cmplwi r0, 0xff;
  li r4, 1;
  bgt lbl_80012b88;
  li r4, 0;
lbl_80012b88:
  cmpwi r4, 0;
  beq lbl_80012b98;
  li r0, 0;
  b lbl_80012bac;
lbl_80012b98:
  lwz r4, 0x38(r23);
  slwi r0, r0, 1;
  lwz r4, 8(r4);
  lhzx r0, r4, r0;
  rlwinm r0, r0, 0, 0x17, 0x17;
lbl_80012bac:
  cmpwi r0, 0;
  bne lbl_80012b54;
  clrlwi r0, r3, 0x18;
  extsb r4, r0;
  cmpwi r4, 0x25;
  beq lbl_80012be8;
  mr r12, r26;
  mr r3, r27;
  li r5, 1;
  mtctr r12;
  bctrl;
  cmpwi r28, 0;
  beq lbl_80012f6c;
  li r29, 1;
  b lbl_80012f60;
lbl_80012be8:
  addi r21, r21, 1;
  b lbl_80012f60;
  cmpwi r29, 0;
  bne lbl_80012c94;
  mr r12, r26;
  mr r3, r27;
  li r4, 0;
  li r5, 0;
  mtctr r12;
  bctrl;
  stb r3, 0xc(r1);
  b lbl_80012c38;
lbl_80012c18:
  mr r12, r26;
  mr r3, r27;
  li r4, 0;
  li r5, 0;
  mtctr r12;
  addi r21, r21, 1;
  bctrl;
  stb r3, 0xc(r1);
lbl_80012c38:
  clrlwi r4, r3, 0x18;
  li r3, 1;
  extsb r0, r4;
  cmplwi r0, 0xff;
  bgt lbl_80012c50;
  li r3, 0;
lbl_80012c50:
  cmpwi r3, 0;
  beq lbl_80012c60;
  li r0, 0;
  b lbl_80012c74;
lbl_80012c60:
  lwz r3, 0x38(r23);
  slwi r0, r0, 1;
  lwz r3, 8(r3);
  lhzx r0, r3, r0;
  rlwinm r0, r0, 0, 0x17, 0x17;
lbl_80012c74:
  cmpwi r0, 0;
  bne lbl_80012c18;
  mr r12, r26;
  mr r3, r27;
  extsb r4, r4;
  li r5, 1;
  mtctr r12;
  bctrl;
lbl_80012c94:
  cmpwi r22, 0;
  beq lbl_80012e28;
  cmpwi r28, 0;
  beq lbl_80012cbc;
  lwz r3, 8(r1);
  li r31, 1;
  li r4, 1;
  bl __va_arg;
  lwz r3, 0(r3);
  addi r30, r3, -1;
lbl_80012cbc:
  cmpwi r29, 0;
  li r0, 0;
  stw r0, 0x18(r1);
  beq lbl_80012ce0;
  cmpwi r30, 0;
  beq lbl_80012f60;
  li r0, 0;
  stb r0, 0(r22);
  b lbl_80012f60;
lbl_80012ce0:
  stw r22, 0x48(r1);
  b lbl_80012d44;
lbl_80012ce8:
  rlwinm r0, r3, 0x1d, 0x1b, 0x1f;
  clrlwi r5, r3, 0x1d;
  add r4, r25, r0;
  stb r3, 0xc(r1);
  lbz r0, 8(r4);
  slw r4, r24, r5;
  clrlwi r3, r3, 0x18;
  and. r0, r4, r0;
  beq lbl_80012d9c;
  lbz r0, 0x22(r1);
  cmplwi r0, 0xa;
  bne lbl_80012d30;
  mr r3, r22;
  addi r4, r1, 0xc;
  li r5, 1;
  bl mbtowc;
  addi r22, r22, 2;
  b lbl_80012d38;
lbl_80012d30:
  stb r3, 0(r22);
  addi r22, r22, 1;
lbl_80012d38:
  lwz r3, 0x18(r1);
  addi r0, r3, 1;
  stw r0, 0x18(r1);
lbl_80012d44:
  lwz r3, 0x24(r1);
  cmpwi r3, 0;
  addi r3, r3, -1;
  stw r3, 0x24(r1);
  beq lbl_80012d9c;
  cmpwi r28, 0;
  beq lbl_80012d78;
  subf r4, r0, r30;
  orc r3, r30, r0;
  srwi r0, r4, 1;
  subf r0, r0, r3;
  rlwinm. r31, r0, 1, 0x1f, 0x1f;
  beq lbl_80012d9c;
lbl_80012d78:
  mr r12, r26;
  mr r3, r27;
  li r4, 0;
  li r5, 0;
  mtctr r12;
  bctrl;
  cmpwi r3, -1;
  mr r18, r3;
  bne lbl_80012ce8;
lbl_80012d9c:
  lwz r3, 0x18(r1);
  stb r18, 0xc(r1);
  cmpwi r3, 0;
  beq lbl_80012dbc;
  cmpwi r28, 0;
  beq lbl_80012dfc;
  cmpwi r31, 0;
  bne lbl_80012dfc;
lbl_80012dbc:
  clrlwi r4, r18, 0x18;
  mr r12, r26;
  mr r3, r27;
  li r5, 1;
  extsb r4, r4;
  mtctr r12;
  bctrl;
  cmpwi r28, 0;
  beq lbl_80012f6c;
  cmpwi r30, 0;
  li r29, 1;
  beq lbl_80012f60;
  lwz r3, 0x48(r1);
  li r0, 0;
  stb r0, 0(r3);
  b lbl_80012f60;
lbl_80012dfc:
  lbz r0, 0x22(r1);
  add r21, r21, r3;
  cmplwi r0, 0xa;
  bne lbl_80012e18;
  li r0, 0;
  sth r0, 0(r22);
  b lbl_80012e20;
lbl_80012e18:
  li r0, 0;
  stb r0, 0(r22);
lbl_80012e20:
  addi r20, r20, 1;
  b lbl_80012ecc;
lbl_80012e28:
  li r0, 0;
  stw r0, 0x18(r1);
  b lbl_80012e60;
lbl_80012e34:
  rlwinm r0, r3, 0x1d, 0x1b, 0x1f;
  clrlwi r5, r3, 0x1d;
  add r4, r25, r0;
  stb r3, 0xc(r1);
  lbz r0, 8(r4);
  slw r3, r24, r5;
  and. r0, r3, r0;
  beq lbl_80012e98;
  lwz r3, 0x18(r1);
  addi r0, r3, 1;
  stw r0, 0x18(r1);
lbl_80012e60:
  lwz r3, 0x24(r1);
  cmpwi r3, 0;
  addi r0, r3, -1;
  stw r0, 0x24(r1);
  beq lbl_80012e98;
  mr r12, r26;
  mr r3, r27;
  li r4, 0;
  li r5, 0;
  mtctr r12;
  bctrl;
  cmpwi r3, -1;
  mr r18, r3;
  bne lbl_80012e34;
lbl_80012e98:
  lwz r0, 0x18(r1);
  stb r18, 0xc(r1);
  cmpwi r0, 0;
  bne lbl_80012ec8;
  clrlwi r4, r18, 0x18;
  mr r12, r26;
  mr r3, r27;
  li r5, 1;
  extsb r4, r4;
  mtctr r12;
  bctrl;
  b lbl_80012f60;
lbl_80012ec8:
  add r21, r21, r0;
lbl_80012ecc:
  lwz r0, 0x24(r1);
  cmpwi r0, 0;
  blt lbl_80012ef4;
  lbz r4, 0xc(r1);
  mr r12, r26;
  mr r3, r27;
  li r5, 1;
  extsb r4, r4;
  mtctr r12;
  bctrl;
lbl_80012ef4:
  addi r19, r19, 1;
  b lbl_80012f60;
  cmpwi r22, 0;
  beq lbl_80012f60;
  lbz r0, 0x22(r1);
  cmpwi r0, 0;
  beq lbl_80012f34;
  cmpwi r0, 2;
  beq lbl_80012f3c;
  cmpwi r0, 3;
  beq lbl_80012f44;
  cmpwi r0, 1;
  beq lbl_80012f4c;
  cmpwi r0, 7;
  beq lbl_80012f54;
  b lbl_80012f60;
lbl_80012f34:
  stw r21, 0(r22);
  b lbl_80012f60;
lbl_80012f3c:
  sth r21, 0(r22);
  b lbl_80012f60;
lbl_80012f44:
  stw r21, 0(r22);
  b lbl_80012f60;
lbl_80012f4c:
  stb r21, 0(r22);
  b lbl_80012f60;
lbl_80012f54:
  stw r21, 4(r22);
  srawi r0, r21, 0x1f;
  stw r0, 0(r22);
lbl_80012f60:
  lbz r0, 0(r17);
  extsb. r22, r0;
  bne lbl_8001237c;
lbl_80012f6c:
  mr r12, r26;
  mr r3, r27;
  li r4, 0;
  li r5, 2;
  mtctr r12;
  bctrl;
  cmpwi r3, 0;
  beq lbl_80012f9c;
  cmpwi r19, 0;
  bne lbl_80012f9c;
  li r3, -1;
  b lbl_80012fa0;
lbl_80012f9c:
  mr r3, r20;
lbl_80012fa0:
  addi r11, r1, 0xb0;
  bl _restgpr_15;
  lwz r0, 0xb4(r1);
  mtlr r0;
  addi r1, r1, 0xb0;
  blr;
  // clang-format on
}

// Symbol: __StringRead
// PAL: 0x80012fb8..0x80013040
MARK_BINARY_BLOB(__StringRead, 0x80012fb8, 0x80013040);
asm UNKNOWN_FUNCTION(__StringRead) {
  // clang-format off
  nofralloc;
  cmpwi r5, 0;
  beq lbl_80012fd4;
  cmpwi r5, 1;
  beq lbl_80013004;
  cmpwi r5, 2;
  beq lbl_80013030;
  b lbl_80013038;
lbl_80012fd4:
  lwz r4, 0(r3);
  lbz r5, 0(r4);
  extsb. r0, r5;
  bne lbl_80012ff4;
  li r0, 1;
  stw r0, 4(r3);
  li r3, -1;
  blr;
lbl_80012ff4:
  addi r0, r4, 1;
  stw r0, 0(r3);
  mr r3, r5;
  blr;
lbl_80013004:
  lwz r0, 4(r3);
  cmpwi r0, 0;
  bne lbl_80013020;
  lwz r5, 0(r3);
  addi r0, r5, -1;
  stw r0, 0(r3);
  b lbl_80013028;
lbl_80013020:
  li r0, 0;
  stw r0, 4(r3);
lbl_80013028:
  mr r3, r4;
  blr;
lbl_80013030:
  lwz r3, 4(r3);
  blr;
lbl_80013038:
  li r3, 0;
  blr;
  // clang-format on
}

// Symbol: sscanf
// PAL: 0x80013040..0x80013108
MARK_BINARY_BLOB(sscanf, 0x80013040, 0x80013108);
asm int sscanf(const char* str, const char* format, ...) {
  // clang-format off
  nofralloc;
  stwu r1, -0x90(r1);
  mflr r0;
  stw r0, 0x94(r1);
  stw r31, 0x8c(r1);
  bne cr1, lbl_80013074;
  stfd f1, 0x28(r1);
  stfd f2, 0x30(r1);
  stfd f3, 0x38(r1);
  stfd f4, 0x40(r1);
  stfd f5, 0x48(r1);
  stfd f6, 0x50(r1);
  stfd f7, 0x58(r1);
  stfd f8, 0x60(r1);
lbl_80013074:
  cmpwi r3, 0;
  addi r11, r1, 0x98;
  addi r0, r1, 8;
  lis r12, 0x200;
  stw r3, 8(r1);
  addi r31, r1, 0x70;
  stw r4, 0xc(r1);
  stw r5, 0x10(r1);
  stw r6, 0x14(r1);
  stw r7, 0x18(r1);
  stw r8, 0x1c(r1);
  stw r9, 0x20(r1);
  stw r10, 0x24(r1);
  stw r12, 0x70(r1);
  stw r11, 0x74(r1);
  stw r0, 0x78(r1);
  stw r3, 0x68(r1);
  beq lbl_800130c8;
  lbz r0, 0(r3);
  extsb. r0, r0;
  bne lbl_800130d0;
lbl_800130c8:
  li r3, -1;
  b lbl_800130f4;
lbl_800130d0:
  li r0, 0;
  lis r3, 0x8001;
  mr r5, r4;
  stw r0, 0x6c(r1);
  mr r6, r31;
  addi r3, r3, 0x2fb8;
  addi r4, r1, 0x68;
  li r7, 0;
  bl __sformatter;
lbl_800130f4:
  lwz r0, 0x94(r1);
  lwz r31, 0x8c(r1);
  mtlr r0;
  addi r1, r1, 0x90;
  blr;
  // clang-format on
}

#include "printf.h"

#include <string.h>

#include "ansi_fp.h"
#include "va_arg.h"

// Extern function references.
// PAL: 0x8000e954
extern UNKNOWN_FUNCTION(__fwrite);
// PAL: 0x8000f138
extern UNKNOWN_FUNCTION(wcstombs);
// PAL: 0x8000f640
extern UNKNOWN_FUNCTION(parse_format2);
// PAL: 0x8000fbfc
extern UNKNOWN_FUNCTION(long2str);
// PAL: 0x8000fe34
extern UNKNOWN_FUNCTION(longlong2str);
// PAL: 0x80013108
extern UNKNOWN_FUNCTION(raise);
// PAL: 0x800155d8
extern UNKNOWN_FUNCTION(fwide);

// Symbol: double2hex
// PAL: 0x800100e4..0x800104b4
MARK_BINARY_BLOB(double2hex, 0x800100e4, 0x800104b4);
asm UNKNOWN_FUNCTION(double2hex) {
  // clang-format off
  nofralloc;
  stwu r1, -0x90(r1);
  mflr r0;
  stw r0, 0x94(r1);
  stfd f31, 0x80(r1);
  psq_st f31, 136(r1), 0, 0;
  lis r5, 0x8027;
  lwz r0, 0xc(r4);
  fmr f31, f1;
  stw r31, 0x7c(r1);
  cmpwi r0, 0x1fd;
  stw r30, 0x78(r1);
  mr r30, r4;
  stw r29, 0x74(r1);
  mr r29, r3;
  stw r28, 0x70(r1);
  lwz r5, 0xf98(r5);
  stfd f1, 8(r1);
  lbz r31, 0(r5);
  ble lbl_80010138;
  li r3, 0;
  b lbl_8001048c;
lbl_80010138:
  li r28, 0;
  li r0, 0x20;
  stb r28, 0x10(r1);
  addi r3, r1, 0x10;
  addi r4, r1, 0x38;
  sth r0, 0x12(r1);
  bl __num2dec;
  lbz r0, 0x3d(r1);
  cmpwi r0, 0x30;
  beq lbl_80010174;
  cmpwi r0, 0x49;
  beq lbl_8001017c;
  cmpwi r0, 0x4e;
  beq lbl_80010208;
  b lbl_80010298;
lbl_80010174:
  sth r28, 0x3a(r1);
  b lbl_80010298;
lbl_8001017c:
  lbz r0, 0x38(r1);
  extsb. r0, r0;
  beq lbl_800101c4;
  lbz r0, 5(r30);
  addi r28, r29, -5;
  cmplwi r0, 0x41;
  bne lbl_800101ac;
  lis r4, 0x8024;
  mr r3, r28;
  addi r4, r4, 0x6628;
  bl strcpy;
  b lbl_80010200;
lbl_800101ac:
  lis r4, 0x8024;
  mr r3, r28;
  addi r4, r4, 0x6628;
  addi r4, r4, 5;
  bl strcpy;
  b lbl_80010200;
lbl_800101c4:
  lbz r0, 5(r30);
  addi r28, r29, -4;
  cmplwi r0, 0x41;
  bne lbl_800101ec;
  lis r4, 0x8024;
  mr r3, r28;
  addi r4, r4, 0x6628;
  addi r4, r4, 0xa;
  bl strcpy;
  b lbl_80010200;
lbl_800101ec:
  lis r4, 0x8024;
  mr r3, r28;
  addi r4, r4, 0x6628;
  addi r4, r4, 0xe;
  bl strcpy;
lbl_80010200:
  mr r3, r28;
  b lbl_8001048c;
lbl_80010208:
  lbz r0, 0x38(r1);
  extsb. r0, r0;
  beq lbl_80010254;
  lbz r0, 5(r30);
  addi r28, r29, -5;
  cmplwi r0, 0x41;
  bne lbl_8001023c;
  lis r4, 0x8024;
  mr r3, r28;
  addi r4, r4, 0x6628;
  addi r4, r4, 0x12;
  bl strcpy;
  b lbl_80010290;
lbl_8001023c:
  lis r4, 0x8024;
  mr r3, r28;
  addi r4, r4, 0x6628;
  addi r4, r4, 0x17;
  bl strcpy;
  b lbl_80010290;
lbl_80010254:
  lbz r0, 5(r30);
  addi r28, r29, -4;
  cmplwi r0, 0x41;
  bne lbl_8001027c;
  lis r4, 0x8024;
  mr r3, r28;
  addi r4, r4, 0x6628;
  addi r4, r4, 0x1c;
  bl strcpy;
  b lbl_80010290;
lbl_8001027c:
  lis r4, 0x8024;
  mr r3, r28;
  addi r4, r4, 0x6628;
  addi r4, r4, 0x20;
  bl strcpy;
lbl_80010290:
  mr r3, r28;
  b lbl_8001048c;
lbl_80010298:
  lbz r0, 9(r1);
  li r8, 0;
  lbz r3, 8(r1);
  li r9, 1;
  slwi r0, r0, 0x11;
  li r7, 0x64;
  rlwimi r0, r3, 0x19, 0, 6;
  stb r9, 0x28(r1);
  srwi r5, r0, 0x15;
  mr r4, r29;
  neg r0, r5;
  stb r9, 0x29(r1);
  or r3, r0, r5;
  addi r0, r5, -1023;
  stb r8, 0x2a(r1);
  srawi r3, r3, 0x1f;
  addi r5, r1, 0x18;
  stb r8, 0x2b(r1);
  and r3, r0, r3;
  lwz r6, 0x28(r1);
  stb r8, 0x2c(r1);
  stb r7, 0x2d(r1);
  lwz r0, 0x2c(r1);
  stw r8, 0x30(r1);
  stw r9, 0x34(r1);
  stw r6, 0x18(r1);
  stw r0, 0x1c(r1);
  stw r8, 0x20(r1);
  stw r9, 0x24(r1);
  bl long2str;
  lbz r0, 5(r30);
  cmplwi r0, 0x61;
  bne lbl_80010328;
  li r0, 0x70;
  stbu r0, -1(r3);
  b lbl_80010330;
lbl_80010328:
  li r0, 0x50;
  stbu r0, -1(r3);
lbl_80010330:
  lwz r0, 0xc(r30);
  addi r8, r1, 8;
  slwi r4, r0, 2;
  addi r9, r4, 0xb;
  mtctr r0;
  cmpwi r0, 1;
  blt lbl_800103e4;
lbl_8001034c:
  cmpwi r9, 0x40;
  bge lbl_800103d4;
  srawi r4, r9, 3;
  addi r0, r9, -4;
  add r7, r8, r4;
  clrlwi r6, r9, 0x1d;
  rlwinm r4, r9, 0, 0, 0x1c;
  rlwinm r0, r0, 0, 0, 0x1c;
  lbz r5, 0(r7);
  subfic r6, r6, 7;
  cmpw r4, r0;
  sraw r0, r5, r6;
  clrlwi r4, r0, 0x18;
  beq lbl_80010398;
  lbz r0, -1(r7);
  slwi r0, r0, 8;
  sraw r0, r0, r6;
  or r0, r4, r0;
  clrlwi r4, r0, 0x18;
lbl_80010398:
  clrlwi r4, r4, 0x1c;
  cmplwi r4, 0xa;
  bge lbl_800103b0;
  addi r0, r4, 0x30;
  clrlwi r4, r0, 0x18;
  b lbl_800103d8;
lbl_800103b0:
  lbz r0, 5(r30);
  cmplwi r0, 0x61;
  bne lbl_800103c8;
  addi r0, r4, 0x57;
  clrlwi r4, r0, 0x18;
  b lbl_800103d8;
lbl_800103c8:
  addi r0, r4, 0x37;
  clrlwi r4, r0, 0x18;
  b lbl_800103d8;
lbl_800103d4:
  li r4, 0x30;
lbl_800103d8:
  stbu r4, -1(r3);
  addi r9, r9, -4;
  bdnz lbl_8001034c;
lbl_800103e4:
  lwz r0, 0xc(r30);
  cmpwi r0, 0;
  bne lbl_800103fc;
  lbz r0, 3(r30);
  cmpwi r0, 0;
  beq lbl_80010400;
lbl_800103fc:
  stbu r31, -1(r3);
lbl_80010400:
  fabs f1, f31;
  lfd f0, -0x7f20(r2);
  fcmpu cr0, f0, f1;
  beq lbl_8001041c;
  li r0, 0x31;
  stbu r0, -1(r3);
  b lbl_80010424;
lbl_8001041c:
  li r0, 0x30;
  stbu r0, -1(r3);
lbl_80010424:
  lbz r0, 5(r30);
  cmplwi r0, 0x61;
  bne lbl_8001043c;
  li r0, 0x78;
  stbu r0, -1(r3);
  b lbl_80010444;
lbl_8001043c:
  li r0, 0x58;
  stbu r0, -1(r3);
lbl_80010444:
  li r0, 0x30;
  stbu r0, -1(r3);
  lbz r0, 0x38(r1);
  extsb. r0, r0;
  beq lbl_80010464;
  li r0, 0x2d;
  stbu r0, -1(r3);
  b lbl_8001048c;
lbl_80010464:
  lbz r0, 1(r30);
  cmplwi r0, 1;
  bne lbl_8001047c;
  li r0, 0x2b;
  stbu r0, -1(r3);
  b lbl_8001048c;
lbl_8001047c:
  cmplwi r0, 2;
  bne lbl_8001048c;
  li r0, 0x20;
  stbu r0, -1(r3);
lbl_8001048c:
  psq_l f31, 136(r1), 0, 0;
  lwz r0, 0x94(r1);
  lfd f31, 0x80(r1);
  lwz r31, 0x7c(r1);
  lwz r30, 0x78(r1);
  lwz r29, 0x74(r1);
  lwz r28, 0x70(r1);
  mtlr r0;
  addi r1, r1, 0x90;
  blr;
  // clang-format on
}

// Symbol: round_decimal
// PAL: 0x800104b4..0x800105dc
MARK_BINARY_BLOB(round_decimal, 0x800104b4, 0x800105dc);
asm UNKNOWN_FUNCTION(round_decimal) {
  // clang-format off
  nofralloc;
  cmpwi r4, 0;
  bge lbl_800104d8;
lbl_800104bc:
  li r5, 0;
  li r4, 1;
  li r0, 0x30;
  sth r5, 2(r3);
  stb r4, 4(r3);
  stb r0, 5(r3);
  blr;
lbl_800104d8:
  lbz r7, 4(r3);
  cmpw r4, r7;
  bgelr;
  add r6, r3, r4;
  lbz r5, 5(r6);
  addi r8, r6, 5;
  addi r0, r5, -48;
  extsb r6, r0;
  cmpwi r6, 5;
  bne lbl_8001053c;
  add r5, r3, r7;
  addi r5, r5, 5;
lbl_80010508:
  addi r5, r5, -1;
  cmplw r5, r8;
  ble lbl_80010520;
  lbz r0, 0(r5);
  cmpwi r0, 0x30;
  beq lbl_80010508;
lbl_80010520:
  cmplw r5, r8;
  bne lbl_80010534;
  lbz r0, -1(r8);
  clrlwi r5, r0, 0x1f;
  b lbl_80010550;
lbl_80010534:
  li r5, 1;
  b lbl_80010550;
lbl_8001053c:
  xori r0, r6, 5;
  srawi r5, r0, 1;
  and r0, r0, r6;
  subf r0, r0, r5;
  srwi r5, r0, 0x1f;
lbl_80010550:
  mtctr r4;
  cmpwi r4, 0;
  beq lbl_800105a4;
lbl_8001055c:
  lbzu r0, -1(r8);
  add r5, r0, r5;
  addi r0, r5, -48;
  extsb r6, r0;
  xori r0, r6, 9;
  srawi r5, r0, 1;
  and r0, r0, r6;
  subf r0, r0, r5;
  rlwinm. r5, r0, 1, 0x1f, 0x1f;
  bne lbl_8001058c;
  cmpwi r6, 0;
  bne lbl_80010594;
lbl_8001058c:
  addi r4, r4, -1;
  b lbl_800105a0;
lbl_80010594:
  addi r0, r6, 0x30;
  stb r0, 0(r8);
  b lbl_800105a4;
lbl_800105a0:
  bdnz lbl_8001055c;
lbl_800105a4:
  cmpwi r5, 0;
  beq lbl_800105cc;
  lha r5, 2(r3);
  li r4, 1;
  li r0, 0x31;
  stb r4, 4(r3);
  addi r4, r5, 1;
  sth r4, 2(r3);
  stb r0, 5(r3);
  blr;
lbl_800105cc:
  cmpwi r4, 0;
  beq lbl_800104bc;
  stb r4, 4(r3);
  blr;
  // clang-format on
}

// Symbol: float2str
// PAL: 0x800105dc..0x80010d74
MARK_BINARY_BLOB(float2str, 0x800105dc, 0x80010d74);
asm UNKNOWN_FUNCTION(float2str) {
  // clang-format off
  nofralloc;
  stwu r1, -0x50(r1);
  mflr r0;
  lis r5, 0x8027;
  stw r0, 0x54(r1);
  lwz r0, 0xc(r4);
  stfd f31, 0x48(r1);
  fmr f31, f1;
  cmpwi r0, 0x1fd;
  stw r31, 0x44(r1);
  stw r30, 0x40(r1);
  stw r29, 0x3c(r1);
  mr r29, r4;
  stw r28, 0x38(r1);
  mr r28, r3;
  lwz r5, 0xf98(r5);
  lbz r30, 0(r5);
  ble lbl_80010628;
  li r3, 0;
  b lbl_80010d50;
lbl_80010628:
  li r3, 0;
  li r0, 0x20;
  stb r3, 8(r1);
  addi r3, r1, 8;
  addi r4, r1, 0xc;
  sth r0, 0xa(r1);
  bl __num2dec;
  lbz r0, 0x10(r1);
  addi r5, r1, 0x11;
  add r5, r5, r0;
  b lbl_8001066c;
lbl_80010654:
  lbz r4, 0x10(r1);
  lha r3, 0xe(r1);
  addi r0, r4, -1;
  stb r0, 0x10(r1);
  addi r0, r3, 1;
  sth r0, 0xe(r1);
lbl_8001066c:
  lbz r0, 0x10(r1);
  cmplwi r0, 1;
  ble lbl_80010684;
  lbzu r0, -1(r5);
  cmpwi r0, 0x30;
  beq lbl_80010654;
lbl_80010684:
  lbz r0, 0x11(r1);
  cmpwi r0, 0x30;
  beq lbl_800106a4;
  cmpwi r0, 0x49;
  beq lbl_800106b0;
  cmpwi r0, 0x4e;
  beq lbl_800107b4;
  b lbl_800108bc;
lbl_800106a4:
  li r0, 0;
  sth r0, 0xe(r1);
  b lbl_800108bc;
lbl_800106b0:
  lfd f0, -0x7f20(r2);
  fcmpo cr0, f31, f0;
  bge lbl_80010734;
  lbz r0, 5(r29);
  addi r31, r28, -5;
  li r3, 1;
  cmplwi r0, 0xff;
  bgt lbl_800106d4;
  li r3, 0;
lbl_800106d4:
  cmpwi r3, 0;
  beq lbl_800106e4;
  li r0, 0;
  b lbl_80010700;
lbl_800106e4:
  lis r3, 0x8027;
  slwi r0, r0, 1;
  addi r3, r3, 0x1148;
  lwz r3, 0x38(r3);
  lwz r3, 8(r3);
  lhzx r0, r3, r0;
  rlwinm r0, r0, 0, 0x16, 0x16;
lbl_80010700:
  cmpwi r0, 0;
  beq lbl_8001071c;
  lis r4, 0x8024;
  mr r3, r31;
  addi r4, r4, 0x6628;
  bl strcpy;
  b lbl_800107ac;
lbl_8001071c:
  lis r4, 0x8024;
  mr r3, r31;
  addi r4, r4, 0x6628;
  addi r4, r4, 5;
  bl strcpy;
  b lbl_800107ac;
lbl_80010734:
  lbz r0, 5(r29);
  addi r31, r28, -4;
  li r3, 1;
  cmplwi r0, 0xff;
  bgt lbl_8001074c;
  li r3, 0;
lbl_8001074c:
  cmpwi r3, 0;
  beq lbl_8001075c;
  li r0, 0;
  b lbl_80010778;
lbl_8001075c:
  lis r3, 0x8027;
  slwi r0, r0, 1;
  addi r3, r3, 0x1148;
  lwz r3, 0x38(r3);
  lwz r3, 8(r3);
  lhzx r0, r3, r0;
  rlwinm r0, r0, 0, 0x16, 0x16;
lbl_80010778:
  cmpwi r0, 0;
  beq lbl_80010798;
  lis r4, 0x8024;
  mr r3, r31;
  addi r4, r4, 0x6628;
  addi r4, r4, 0xa;
  bl strcpy;
  b lbl_800107ac;
lbl_80010798:
  lis r4, 0x8024;
  mr r3, r31;
  addi r4, r4, 0x6628;
  addi r4, r4, 0xe;
  bl strcpy;
lbl_800107ac:
  mr r3, r31;
  b lbl_80010d50;
lbl_800107b4:
  lbz r0, 0xc(r1);
  extsb. r0, r0;
  beq lbl_8001083c;
  lbz r0, 5(r29);
  addi r31, r28, -5;
  li r3, 1;
  cmplwi r0, 0xff;
  bgt lbl_800107d8;
  li r3, 0;
lbl_800107d8:
  cmpwi r3, 0;
  beq lbl_800107e8;
  li r0, 0;
  b lbl_80010804;
lbl_800107e8:
  lis r3, 0x8027;
  slwi r0, r0, 1;
  addi r3, r3, 0x1148;
  lwz r3, 0x38(r3);
  lwz r3, 8(r3);
  lhzx r0, r3, r0;
  rlwinm r0, r0, 0, 0x16, 0x16;
lbl_80010804:
  cmpwi r0, 0;
  beq lbl_80010824;
  lis r4, 0x8024;
  mr r3, r31;
  addi r4, r4, 0x6628;
  addi r4, r4, 0x12;
  bl strcpy;
  b lbl_800108b4;
lbl_80010824:
  lis r4, 0x8024;
  mr r3, r31;
  addi r4, r4, 0x6628;
  addi r4, r4, 0x17;
  bl strcpy;
  b lbl_800108b4;
lbl_8001083c:
  lbz r0, 5(r29);
  addi r31, r28, -4;
  li r3, 1;
  cmplwi r0, 0xff;
  bgt lbl_80010854;
  li r3, 0;
lbl_80010854:
  cmpwi r3, 0;
  beq lbl_80010864;
  li r0, 0;
  b lbl_80010880;
lbl_80010864:
  lis r3, 0x8027;
  slwi r0, r0, 1;
  addi r3, r3, 0x1148;
  lwz r3, 0x38(r3);
  lwz r3, 8(r3);
  lhzx r0, r3, r0;
  rlwinm r0, r0, 0, 0x16, 0x16;
lbl_80010880:
  cmpwi r0, 0;
  beq lbl_800108a0;
  lis r4, 0x8024;
  mr r3, r31;
  addi r4, r4, 0x6628;
  addi r4, r4, 0x1c;
  bl strcpy;
  b lbl_800108b4;
lbl_800108a0:
  lis r4, 0x8024;
  mr r3, r31;
  addi r4, r4, 0x6628;
  addi r4, r4, 0x20;
  bl strcpy;
lbl_800108b4:
  mr r3, r31;
  b lbl_80010d50;
lbl_800108bc:
  lha r4, 0xe(r1);
  li r0, 0;
  lbz r3, 0x10(r1);
  addi r31, r28, -1;
  lbz r5, 5(r29);
  add r3, r3, r4;
  addi r3, r3, -1;
  sth r3, 0xe(r1);
  cmpwi r5, 0x67;
  stb r0, -1(r28);
  beq lbl_80010914;
  cmpwi r5, 0x47;
  beq lbl_80010914;
  cmpwi r5, 0x65;
  beq lbl_800109cc;
  cmpwi r5, 0x45;
  beq lbl_800109cc;
  cmpwi r5, 0x66;
  beq lbl_80010b30;
  cmpwi r5, 0x46;
  beq lbl_80010b30;
  b lbl_80010d4c;
lbl_80010914:
  lwz r4, 0xc(r29);
  lbz r0, 0x10(r1);
  cmpw r0, r4;
  ble lbl_8001092c;
  addi r3, r1, 0xc;
  bl round_decimal;
lbl_8001092c:
  lha r4, 0xe(r1);
  cmpwi r4, -4;
  blt lbl_80010944;
  lwz r3, 0xc(r29);
  cmpw r4, r3;
  blt lbl_80010990;
lbl_80010944:
  lbz r0, 3(r29);
  cmpwi r0, 0;
  beq lbl_80010960;
  lwz r3, 0xc(r29);
  addi r0, r3, -1;
  stw r0, 0xc(r29);
  b lbl_8001096c;
lbl_80010960:
  lbz r3, 0x10(r1);
  addi r0, r3, -1;
  stw r0, 0xc(r29);
lbl_8001096c:
  lbz r0, 5(r29);
  cmplwi r0, 0x67;
  bne lbl_80010984;
  li r0, 0x65;
  stb r0, 5(r29);
  b lbl_800109cc;
lbl_80010984:
  li r0, 0x45;
  stb r0, 5(r29);
  b lbl_800109cc;
lbl_80010990:
  lbz r0, 3(r29);
  cmpwi r0, 0;
  beq lbl_800109ac;
  addi r0, r4, 1;
  subf r0, r0, r3;
  stw r0, 0xc(r29);
  b lbl_80010b30;
lbl_800109ac:
  lbz r0, 0x10(r1);
  addi r3, r4, 1;
  subf. r0, r3, r0;
  stw r0, 0xc(r29);
  bge lbl_80010b30;
  li r0, 0;
  stw r0, 0xc(r29);
  b lbl_80010b30;
lbl_800109cc:
  lwz r3, 0xc(r29);
  lbz r0, 0x10(r1);
  addi r4, r3, 1;
  cmpw r0, r4;
  ble lbl_800109e8;
  addi r3, r1, 0xc;
  bl round_decimal;
lbl_800109e8:
  lha r6, 0xe(r1);
  li r8, 0x2b;
  cmpwi r6, 0;
  bge lbl_80010a00;
  neg r6, r6;
  li r8, 0x2d;
lbl_80010a00:
  lis r3, 0x6666;
  li r7, 0;
  addi r5, r3, 0x6667;
  b lbl_80010a44;
lbl_80010a10:
  mulhw r0, r5, r6;
  addi r7, r7, 1;
  srawi r3, r0, 2;
  srwi r4, r3, 0x1f;
  srawi r0, r0, 2;
  add r3, r3, r4;
  mulli r4, r3, 0xa;
  srwi r3, r0, 0x1f;
  subf r4, r4, r6;
  add r6, r0, r3;
  addi r0, r4, 0x30;
  stb r0, -1(r31);
  addi r31, r31, -1;
lbl_80010a44:
  cmpwi r6, 0;
  bne lbl_80010a10;
  cmpwi r7, 2;
  blt lbl_80010a10;
  stb r8, -1(r31);
  lbz r0, 5(r29);
  stbu r0, -2(r31);
  lwz r3, 0xc(r29);
  subf r0, r31, r28;
  add r0, r3, r0;
  cmpwi r0, 0x1fd;
  ble lbl_80010a7c;
  li r3, 0;
  b lbl_80010d50;
lbl_80010a7c:
  lbz r4, 0x10(r1);
  addi r0, r3, 1;
  cmpw r4, r0;
  bge lbl_80010aa8;
  addi r3, r3, 2;
  li r0, 0x30;
  subf r3, r4, r3;
  b lbl_80010aa0;
lbl_80010a9c:
  stbu r0, -1(r31);
lbl_80010aa0:
  addic. r3, r3, -1;
  bne lbl_80010a9c;
lbl_80010aa8:
  lbz r3, 0x10(r1);
  addi r4, r1, 0x11;
  add r4, r4, r3;
  b lbl_80010ac0;
lbl_80010ab8:
  lbzu r0, -1(r4);
  stbu r0, -1(r31);
lbl_80010ac0:
  addic. r3, r3, -1;
  bne lbl_80010ab8;
  lwz r0, 0xc(r29);
  cmpwi r0, 0;
  bne lbl_80010ae0;
  lbz r0, 3(r29);
  cmpwi r0, 0;
  beq lbl_80010ae4;
lbl_80010ae0:
  stbu r30, -1(r31);
lbl_80010ae4:
  lbz r0, 0x11(r1);
  stbu r0, -1(r31);
  lbz r0, 0xc(r1);
  extsb. r0, r0;
  beq lbl_80010b04;
  li r0, 0x2d;
  stbu r0, -1(r31);
  b lbl_80010d4c;
lbl_80010b04:
  lbz r0, 1(r29);
  cmplwi r0, 1;
  bne lbl_80010b1c;
  li r0, 0x2b;
  stbu r0, -1(r31);
  b lbl_80010d4c;
lbl_80010b1c:
  cmplwi r0, 2;
  bne lbl_80010d4c;
  li r0, 0x20;
  stbu r0, -1(r31);
  b lbl_80010d4c;
lbl_80010b30:
  lbz r4, 0x10(r1);
  lha r5, 0xe(r1);
  subf r3, r5, r4;
  addic. r8, r3, -1;
  bge lbl_80010b48;
  li r8, 0;
lbl_80010b48:
  lwz r0, 0xc(r29);
  cmpw r8, r0;
  ble lbl_80010b7c;
  subf r0, r0, r8;
  addi r3, r1, 0xc;
  subf r4, r0, r4;
  bl round_decimal;
  lbz r4, 0x10(r1);
  lha r5, 0xe(r1);
  subf r3, r5, r4;
  addic. r8, r3, -1;
  bge lbl_80010b7c;
  li r8, 0;
lbl_80010b7c:
  addic. r7, r5, 1;
  bge lbl_80010b88;
  li r7, 0;
lbl_80010b88:
  add r0, r7, r8;
  cmpwi r0, 0x1fd;
  ble lbl_80010b9c;
  li r3, 0;
  b lbl_80010d50;
lbl_80010b9c:
  addi r6, r1, 0x11;
  li r5, 0;
  add r6, r6, r4;
  li r3, 0x30;
  b lbl_80010bb8;
lbl_80010bb0:
  stbu r3, -1(r31);
  addi r5, r5, 1;
lbl_80010bb8:
  lwz r0, 0xc(r29);
  subf r0, r8, r0;
  cmpw r5, r0;
  blt lbl_80010bb0;
  li r3, 0;
  b lbl_80010bdc;
lbl_80010bd0:
  lbzu r0, -1(r6);
  addi r3, r3, 1;
  stbu r0, -1(r31);
lbl_80010bdc:
  cmpw r3, r8;
  bge lbl_80010bf0;
  lbz r0, 0x10(r1);
  cmpw r3, r0;
  blt lbl_80010bd0;
lbl_80010bf0:
  cmpw r3, r8;
  subf r3, r3, r8;
  li r4, 0x30;
  bge lbl_80010c44;
  rlwinm. r0, r3, 0x1d, 3, 0x1f;
  mtctr r0;
  beq lbl_80010c38;
lbl_80010c0c:
  stb r4, -1(r31);
  stb r4, -2(r31);
  stb r4, -3(r31);
  stb r4, -4(r31);
  stb r4, -5(r31);
  stb r4, -6(r31);
  stb r4, -7(r31);
  stbu r4, -8(r31);
  bdnz lbl_80010c0c;
  andi. r3, r3, 7;
  beq lbl_80010c44;
lbl_80010c38:
  mtctr r3;
lbl_80010c3c:
  stbu r4, -1(r31);
  bdnz lbl_80010c3c;
lbl_80010c44:
  lwz r0, 0xc(r29);
  cmpwi r0, 0;
  bne lbl_80010c5c;
  lbz r0, 3(r29);
  cmpwi r0, 0;
  beq lbl_80010c60;
lbl_80010c5c:
  stbu r30, -1(r31);
lbl_80010c60:
  cmpwi r7, 0;
  beq lbl_80010d04;
  li r4, 0;
  li r3, 0x30;
  b lbl_80010c7c;
lbl_80010c74:
  stbu r3, -1(r31);
  addi r4, r4, 1;
lbl_80010c7c:
  lbz r0, 0x10(r1);
  subf r0, r0, r7;
  cmpw r4, r0;
  blt lbl_80010c74;
  cmpw r4, r7;
  subf r3, r4, r7;
  bge lbl_80010d0c;
  rlwinm. r0, r3, 0x1d, 3, 0x1f;
  mtctr r0;
  beq lbl_80010cf0;
lbl_80010ca4:
  lbz r0, -1(r6);
  stb r0, -1(r31);
  lbz r0, -2(r6);
  stb r0, -2(r31);
  lbz r0, -3(r6);
  stb r0, -3(r31);
  lbz r0, -4(r6);
  stb r0, -4(r31);
  lbz r0, -5(r6);
  stb r0, -5(r31);
  lbz r0, -6(r6);
  stb r0, -6(r31);
  lbz r0, -7(r6);
  stb r0, -7(r31);
  lbzu r0, -8(r6);
  stbu r0, -8(r31);
  bdnz lbl_80010ca4;
  andi. r3, r3, 7;
  beq lbl_80010d0c;
lbl_80010cf0:
  mtctr r3;
lbl_80010cf4:
  lbzu r0, -1(r6);
  stbu r0, -1(r31);
  bdnz lbl_80010cf4;
  b lbl_80010d0c;
lbl_80010d04:
  li r0, 0x30;
  stbu r0, -1(r31);
lbl_80010d0c:
  lbz r0, 0xc(r1);
  extsb. r0, r0;
  beq lbl_80010d24;
  li r0, 0x2d;
  stbu r0, -1(r31);
  b lbl_80010d4c;
lbl_80010d24:
  lbz r0, 1(r29);
  cmplwi r0, 1;
  bne lbl_80010d3c;
  li r0, 0x2b;
  stbu r0, -1(r31);
  b lbl_80010d4c;
lbl_80010d3c:
  cmplwi r0, 2;
  bne lbl_80010d4c;
  li r0, 0x20;
  stbu r0, -1(r31);
lbl_80010d4c:
  mr r3, r31;
lbl_80010d50:
  lwz r0, 0x54(r1);
  lfd f31, 0x48(r1);
  lwz r31, 0x44(r1);
  lwz r30, 0x40(r1);
  lwz r29, 0x3c(r1);
  lwz r28, 0x38(r1);
  mtlr r0;
  addi r1, r1, 0x50;
  blr;
  // clang-format on
}

// Symbol: __pformatter
// PAL: 0x80010d74..0x80011620
MARK_BINARY_BLOB(__pformatter, 0x80010d74, 0x80011620);
asm UNKNOWN_FUNCTION(__pformatter) {
  // clang-format off
  nofralloc;
  stwu r1, -0x2d0(r1);
  mflr r0;
  stw r0, 0x2d4(r1);
  stmw r15, 0x28c(r1);
  li r24, 0x20;
  lis r22, 0x8024;
  mr r25, r3;
  mr r26, r4;
  mr r15, r5;
  mr r27, r6;
  mr r28, r7;
  addi r22, r22, 0x6628;
  addi r21, r1, 0x27f;
  li r17, 0;
  lis r20, 0x8027;
  li r23, 0x25;
  stb r24, 9(r1);
  b lbl_800115fc;
lbl_80010dbc:
  mr r3, r15;
  li r4, 0x25;
  bl strchr;
  cmpwi r3, 0;
  mr r16, r3;
  bne lbl_80010e10;
  mr r3, r15;
  bl strlen;
  cmpwi r3, 0;
  mr r5, r3;
  add r17, r17, r3;
  beq lbl_80011608;
  mr r12, r25;
  mr r3, r26;
  mr r4, r15;
  mtctr r12;
  bctrl;
  cmpwi r3, 0;
  bne lbl_80011608;
  li r3, -1;
  b lbl_8001160c;
lbl_80010e10:
  subf. r5, r15, r3;
  add r17, r17, r5;
  beq lbl_80010e40;
  mr r12, r25;
  mr r3, r26;
  mr r4, r15;
  mtctr r12;
  bctrl;
  cmpwi r3, 0;
  bne lbl_80010e40;
  li r3, -1;
  b lbl_8001160c;
lbl_80010e40:
  mr r3, r16;
  mr r4, r27;
  addi r5, r1, 0x70;
  bl parse_format2;
  lbz r4, 0x75(r1);
  mr r15, r3;
  addi r0, r4, -37;
  cmplwi r0, 0x53;
  bgt lbl_8001141c;
  addi r3, r20, 0x1270;
  slwi r0, r0, 2;
  lwzx r3, r3, r0;
  mtctr r3;
  bctr;
  lbz r0, 0x74(r1);
  cmplwi r0, 3;
  bne lbl_80010e98;
  mr r3, r27;
  li r4, 1;
  bl __va_arg;
  lwz r31, 0(r3);
  b lbl_80010f20;
lbl_80010e98:
  cmplwi r0, 4;
  bne lbl_80010eb8;
  mr r3, r27;
  li r4, 2;
  bl __va_arg;
  lwz r30, 0(r3);
  lwz r29, 4(r3);
  b lbl_80010f20;
lbl_80010eb8:
  cmplwi r0, 6;
  bne lbl_80010ed8;
  mr r3, r27;
  li r4, 2;
  bl __va_arg;
  lwz r30, 0(r3);
  lwz r29, 4(r3);
  b lbl_80010f20;
lbl_80010ed8:
  cmplwi r0, 7;
  bne lbl_80010ef4;
  mr r3, r27;
  li r4, 1;
  bl __va_arg;
  lwz r31, 0(r3);
  b lbl_80010f20;
lbl_80010ef4:
  cmplwi r0, 8;
  bne lbl_80010f10;
  mr r3, r27;
  li r4, 1;
  bl __va_arg;
  lwz r31, 0(r3);
  b lbl_80010f20;
lbl_80010f10:
  mr r3, r27;
  li r4, 1;
  bl __va_arg;
  lwz r31, 0(r3);
lbl_80010f20:
  lbz r0, 0x74(r1);
  cmplwi r0, 2;
  bne lbl_80010f30;
  extsh r31, r31;
lbl_80010f30:
  cmplwi r0, 1;
  bne lbl_80010f3c;
  extsb r31, r31;
lbl_80010f3c:
  cmplwi r0, 4;
  beq lbl_80010f4c;
  cmplwi r0, 6;
  bne lbl_80010f90;
lbl_80010f4c:
  lwz r9, 0x70(r1);
  mr r4, r29;
  lwz r8, 0x74(r1);
  mr r3, r30;
  lwz r7, 0x78(r1);
  addi r5, r1, 0x280;
  lwz r0, 0x7c(r1);
  addi r6, r1, 0x60;
  stw r9, 0x60(r1);
  stw r8, 0x64(r1);
  stw r7, 0x68(r1);
  stw r0, 0x6c(r1);
  bl longlong2str;
  cmpwi r3, 0;
  mr r18, r3;
  beq lbl_8001141c;
  b lbl_80010fcc;
lbl_80010f90:
  lwz r8, 0x70(r1);
  mr r3, r31;
  lwz r7, 0x74(r1);
  addi r4, r1, 0x280;
  lwz r6, 0x78(r1);
  addi r5, r1, 0x50;
  lwz r0, 0x7c(r1);
  stw r8, 0x50(r1);
  stw r7, 0x54(r1);
  stw r6, 0x58(r1);
  stw r0, 0x5c(r1);
  bl long2str;
  cmpwi r3, 0;
  mr r18, r3;
  beq lbl_8001141c;
lbl_80010fcc:
  subf r19, r18, r21;
  b lbl_80011460;
  lbz r0, 0x74(r1);
  cmplwi r0, 3;
  bne lbl_80010ff4;
  mr r3, r27;
  li r4, 1;
  bl __va_arg;
  lwz r31, 0(r3);
  b lbl_8001107c;
lbl_80010ff4:
  cmplwi r0, 4;
  bne lbl_80011014;
  mr r3, r27;
  li r4, 2;
  bl __va_arg;
  lwz r30, 0(r3);
  lwz r29, 4(r3);
  b lbl_8001107c;
lbl_80011014:
  cmplwi r0, 6;
  bne lbl_80011034;
  mr r3, r27;
  li r4, 2;
  bl __va_arg;
  lwz r30, 0(r3);
  lwz r29, 4(r3);
  b lbl_8001107c;
lbl_80011034:
  cmplwi r0, 7;
  bne lbl_80011050;
  mr r3, r27;
  li r4, 1;
  bl __va_arg;
  lwz r31, 0(r3);
  b lbl_8001107c;
lbl_80011050:
  cmplwi r0, 8;
  bne lbl_8001106c;
  mr r3, r27;
  li r4, 1;
  bl __va_arg;
  lwz r31, 0(r3);
  b lbl_8001107c;
lbl_8001106c:
  mr r3, r27;
  li r4, 1;
  bl __va_arg;
  lwz r31, 0(r3);
lbl_8001107c:
  lbz r0, 0x74(r1);
  cmplwi r0, 2;
  bne lbl_8001108c;
  clrlwi r31, r31, 0x10;
lbl_8001108c:
  cmplwi r0, 1;
  bne lbl_80011098;
  clrlwi r31, r31, 0x18;
lbl_80011098:
  cmplwi r0, 4;
  beq lbl_800110a8;
  cmplwi r0, 6;
  bne lbl_800110ec;
lbl_800110a8:
  lwz r9, 0x70(r1);
  mr r4, r29;
  lwz r8, 0x74(r1);
  mr r3, r30;
  lwz r7, 0x78(r1);
  addi r5, r1, 0x280;
  lwz r0, 0x7c(r1);
  addi r6, r1, 0x40;
  stw r9, 0x40(r1);
  stw r8, 0x44(r1);
  stw r7, 0x48(r1);
  stw r0, 0x4c(r1);
  bl longlong2str;
  cmpwi r3, 0;
  mr r18, r3;
  beq lbl_8001141c;
  b lbl_80011128;
lbl_800110ec:
  lwz r8, 0x70(r1);
  mr r3, r31;
  lwz r7, 0x74(r1);
  addi r4, r1, 0x280;
  lwz r6, 0x78(r1);
  addi r5, r1, 0x30;
  lwz r0, 0x7c(r1);
  stw r8, 0x30(r1);
  stw r7, 0x34(r1);
  stw r6, 0x38(r1);
  stw r0, 0x3c(r1);
  bl long2str;
  cmpwi r3, 0;
  mr r18, r3;
  beq lbl_8001141c;
lbl_80011128:
  subf r19, r18, r21;
  b lbl_80011460;
  lbz r0, 0x74(r1);
  cmplwi r0, 9;
  bne lbl_80011150;
  mr r3, r27;
  li r4, 3;
  bl __va_arg;
  lfd f1, 0(r3);
  b lbl_80011160;
lbl_80011150:
  mr r3, r27;
  li r4, 3;
  bl __va_arg;
  lfd f1, 0(r3);
lbl_80011160:
  lwz r7, 0x70(r1);
  addi r3, r1, 0x280;
  lwz r6, 0x74(r1);
  addi r4, r1, 0x20;
  lwz r5, 0x78(r1);
  lwz r0, 0x7c(r1);
  stw r7, 0x20(r1);
  stw r6, 0x24(r1);
  stw r5, 0x28(r1);
  stw r0, 0x2c(r1);
  bl float2str;
  cmpwi r3, 0;
  mr r18, r3;
  beq lbl_8001141c;
  subf r19, r3, r21;
  b lbl_80011460;
  lbz r0, 0x74(r1);
  cmplwi r0, 9;
  bne lbl_800111c0;
  mr r3, r27;
  li r4, 3;
  bl __va_arg;
  lfd f1, 0(r3);
  b lbl_800111d0;
lbl_800111c0:
  mr r3, r27;
  li r4, 3;
  bl __va_arg;
  lfd f1, 0(r3);
lbl_800111d0:
  lwz r7, 0x70(r1);
  addi r3, r1, 0x280;
  lwz r6, 0x74(r1);
  addi r4, r1, 0x10;
  lwz r5, 0x78(r1);
  lwz r0, 0x7c(r1);
  stw r7, 0x10(r1);
  stw r6, 0x14(r1);
  stw r5, 0x18(r1);
  stw r0, 0x1c(r1);
  bl double2hex;
  cmpwi r3, 0;
  mr r18, r3;
  beq lbl_8001141c;
  subf r19, r3, r21;
  b lbl_80011460;
  lbz r0, 0x74(r1);
  cmplwi r0, 5;
  bne lbl_8001127c;
  mr r3, r27;
  li r4, 1;
  bl __va_arg;
  cmpwi r28, 0;
  lwz r4, 0(r3);
  beq lbl_80011254;
  cmpwi r4, 0;
  bne lbl_80011254;
  li r3, 0;
  li r4, 0;
  li r5, -1;
  bl raise;
  li r3, -1;
  b lbl_8001160c;
lbl_80011254:
  cmpwi r4, 0;
  bne lbl_80011260;
  addi r4, r13, -32720;
lbl_80011260:
  addi r3, r1, 0x80;
  li r5, 0x200;
  bl wcstombs;
  cmpwi r3, 0;
  blt lbl_8001141c;
  addi r18, r1, 0x80;
  b lbl_8001128c;
lbl_8001127c:
  mr r3, r27;
  li r4, 1;
  bl __va_arg;
  lwz r18, 0(r3);
lbl_8001128c:
  cmpwi r28, 0;
  beq lbl_800112b4;
  cmpwi r18, 0;
  bne lbl_800112b4;
  li r3, 0;
  li r4, 0;
  li r5, -1;
  bl raise;
  li r3, -1;
  b lbl_8001160c;
lbl_800112b4:
  cmpwi r18, 0;
  bne lbl_800112c0;
  addi r18, r22, 0x24;
lbl_800112c0:
  lbz r0, 0x73(r1);
  cmpwi r0, 0;
  beq lbl_800112f4;
  lbz r0, 0x72(r1);
  lbz r19, 0(r18);
  addi r18, r18, 1;
  cmpwi r0, 0;
  beq lbl_80011460;
  lwz r0, 0x7c(r1);
  cmpw r19, r0;
  ble lbl_80011460;
  mr r19, r0;
  b lbl_80011460;
lbl_800112f4:
  lbz r0, 0x72(r1);
  cmpwi r0, 0;
  beq lbl_80011324;
  lwz r19, 0x7c(r1);
  mr r3, r18;
  li r4, 0;
  mr r5, r19;
  bl memchr;
  cmpwi r3, 0;
  beq lbl_80011460;
  subf r19, r18, r3;
  b lbl_80011460;
lbl_80011324:
  mr r3, r18;
  bl strlen;
  mr r19, r3;
  b lbl_80011460;
  cmpwi r28, 0;
  beq lbl_80011354;
  li r3, 0;
  li r4, 0;
  li r5, -1;
  bl raise;
  li r3, -1;
  b lbl_8001160c;
lbl_80011354:
  mr r3, r27;
  li r4, 1;
  bl __va_arg;
  lbz r0, 0x74(r1);
  lwz r3, 0(r3);
  cmpwi r0, 0;
  beq lbl_800113a4;
  cmpwi r0, 2;
  beq lbl_800113ac;
  cmpwi r0, 3;
  beq lbl_800113b4;
  cmpwi r0, 6;
  beq lbl_800113bc;
  cmpwi r0, 7;
  beq lbl_800113cc;
  cmpwi r0, 8;
  beq lbl_800113d4;
  cmpwi r0, 4;
  beq lbl_800113dc;
  b lbl_800115fc;
lbl_800113a4:
  stw r17, 0(r3);
  b lbl_800115fc;
lbl_800113ac:
  sth r17, 0(r3);
  b lbl_800115fc;
lbl_800113b4:
  stw r17, 0(r3);
  b lbl_800115fc;
lbl_800113bc:
  stw r17, 4(r3);
  srawi r0, r17, 0x1f;
  stw r0, 0(r3);
  b lbl_800115fc;
lbl_800113cc:
  stw r17, 0(r3);
  b lbl_800115fc;
lbl_800113d4:
  stw r17, 0(r3);
  b lbl_800115fc;
lbl_800113dc:
  stw r17, 4(r3);
  srawi r0, r17, 0x1f;
  stw r0, 0(r3);
  b lbl_800115fc;
  mr r3, r27;
  addi r18, r1, 0x80;
  li r4, 1;
  bl __va_arg;
  lwz r0, 0(r3);
  li r19, 1;
  stb r0, 0x80(r1);
  b lbl_80011460;
  stb r23, 0x80(r1);
  addi r18, r1, 0x80;
  li r19, 1;
  b lbl_80011460;
lbl_8001141c:
  mr r3, r16;
  bl strlen;
  cmpwi r3, 0;
  mr r5, r3;
  add r17, r17, r3;
  beq lbl_80011458;
  mr r12, r25;
  mr r3, r26;
  mr r4, r16;
  mtctr r12;
  bctrl;
  cmpwi r3, 0;
  bne lbl_80011458;
  li r3, -1;
  b lbl_8001160c;
lbl_80011458:
  mr r3, r17;
  b lbl_8001160c;
lbl_80011460:
  lbz r0, 0x70(r1);
  mr r16, r19;
  cmpwi r0, 0;
  beq lbl_8001157c;
  cmplwi r0, 2;
  li r3, 0x20;
  bne lbl_80011480;
  li r3, 0x30;
lbl_80011480:
  stb r3, 9(r1);
  lbz r0, 0(r18);
  extsb r0, r0;
  cmpwi r0, 0x2b;
  beq lbl_800114a4;
  cmpwi r0, 0x2d;
  beq lbl_800114a4;
  cmpwi r0, 0x20;
  bne lbl_800114e0;
lbl_800114a4:
  extsb r0, r3;
  cmpwi r0, 0x30;
  bne lbl_800114e0;
  mr r12, r25;
  mr r3, r26;
  mr r4, r18;
  li r5, 1;
  mtctr r12;
  bctrl;
  cmpwi r3, 0;
  bne lbl_800114d8;
  li r3, -1;
  b lbl_8001160c;
lbl_800114d8:
  addi r18, r18, 1;
  addi r19, r19, -1;
lbl_800114e0:
  lbz r0, 0x70(r1);
  cmplwi r0, 2;
  bne lbl_80011570;
  lbz r0, 0x75(r1);
  cmplwi r0, 0x61;
  beq lbl_80011500;
  cmplwi r0, 0x41;
  bne lbl_80011570;
lbl_80011500:
  cmpwi r19, 2;
  bge lbl_80011510;
  li r3, -1;
  b lbl_8001160c;
lbl_80011510:
  mr r12, r25;
  mr r3, r26;
  mr r4, r18;
  li r5, 2;
  mtctr r12;
  bctrl;
  cmpwi r3, 0;
  bne lbl_80011538;
  li r3, -1;
  b lbl_8001160c;
lbl_80011538:
  addi r19, r19, -2;
  addi r18, r18, 2;
  b lbl_80011570;
lbl_80011544:
  mr r12, r25;
  mr r3, r26;
  addi r4, r1, 9;
  li r5, 1;
  mtctr r12;
  bctrl;
  cmpwi r3, 0;
  bne lbl_8001156c;
  li r3, -1;
  b lbl_8001160c;
lbl_8001156c:
  addi r16, r16, 1;
lbl_80011570:
  lwz r0, 0x78(r1);
  cmpw r16, r0;
  blt lbl_80011544;
lbl_8001157c:
  cmpwi r19, 0;
  beq lbl_800115ac;
  mr r12, r25;
  mr r3, r26;
  mr r4, r18;
  mr r5, r19;
  mtctr r12;
  bctrl;
  cmpwi r3, 0;
  bne lbl_800115ac;
  li r3, -1;
  b lbl_8001160c;
lbl_800115ac:
  lbz r0, 0x70(r1);
  cmpwi r0, 0;
  bne lbl_800115f8;
  b lbl_800115ec;
lbl_800115bc:
  mr r12, r25;
  mr r3, r26;
  stb r24, 8(r1);
  addi r4, r1, 8;
  li r5, 1;
  mtctr r12;
  bctrl;
  cmpwi r3, 0;
  bne lbl_800115e8;
  li r3, -1;
  b lbl_8001160c;
lbl_800115e8:
  addi r16, r16, 1;
lbl_800115ec:
  lwz r0, 0x78(r1);
  cmpw r16, r0;
  blt lbl_800115bc;
lbl_800115f8:
  add r17, r17, r16;
lbl_800115fc:
  lbz r0, 0(r15);
  extsb. r0, r0;
  bne lbl_80010dbc;
lbl_80011608:
  mr r3, r17;
lbl_8001160c:
  lmw r15, 0x28c(r1);
  lwz r0, 0x2d4(r1);
  mtlr r0;
  addi r1, r1, 0x2d0;
  blr;
  // clang-format on
}

// Symbol: __FileWrite
// PAL: 0x80011620..0x80011678
MARK_BINARY_BLOB(__FileWrite, 0x80011620, 0x80011678);
asm UNKNOWN_FUNCTION(__FileWrite) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r5;
  stw r30, 8(r1);
  mr r30, r3;
  mr r3, r4;
  li r4, 1;
  mr r6, r30;
  bl __fwrite;
  cmplw r31, r3;
  bne lbl_80011658;
  b lbl_8001165c;
lbl_80011658:
  li r30, 0;
lbl_8001165c:
  mr r3, r30;
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: __StringWrite
// PAL: 0x80011678..0x800116e4
MARK_BINARY_BLOB(__StringWrite, 0x80011678, 0x800116e4);
asm UNKNOWN_FUNCTION(__StringWrite) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  stw r30, 8(r1);
  mr r30, r3;
  lwz r6, 8(r3);
  lwz r7, 4(r3);
  add r0, r6, r5;
  cmplw r0, r7;
  subf r31, r6, r7;
  bgt lbl_800116ac;
  mr r31, r5;
lbl_800116ac:
  lwz r0, 0(r3);
  mr r5, r31;
  add r3, r0, r6;
  bl memcpy;
  lwz r0, 8(r30);
  li r3, 1;
  add r0, r0, r31;
  stw r0, 8(r30);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: printf
// PAL: 0x800116e4..0x800117b0
MARK_BINARY_BLOB(printf, 0x800116e4, 0x800117b0);
asm UNKNOWN_FUNCTION(printf) {
  // clang-format off
  nofralloc;
  stwu r1, -0x80(r1);
  mflr r0;
  stw r0, 0x84(r1);
  stw r31, 0x7c(r1);
  stw r30, 0x78(r1);
  mr r30, r3;
  bne cr1, lbl_80011720;
  stfd f1, 0x28(r1);
  stfd f2, 0x30(r1);
  stfd f3, 0x38(r1);
  stfd f4, 0x40(r1);
  stfd f5, 0x48(r1);
  stfd f6, 0x50(r1);
  stfd f7, 0x58(r1);
  stfd f8, 0x60(r1);
lbl_80011720:
  lis r31, 0x8027;
  stw r4, 0xc(r1);
  addi r31, r31, 0xcf0;
  li r4, -1;
  stw r3, 8(r1);
  addi r3, r31, 0x50;
  stw r5, 0x10(r1);
  stw r6, 0x14(r1);
  stw r7, 0x18(r1);
  stw r8, 0x1c(r1);
  stw r9, 0x20(r1);
  stw r10, 0x24(r1);
  bl fwide;
  cmpwi r3, 0;
  blt lbl_80011764;
  li r3, -1;
  b lbl_80011798;
lbl_80011764:
  addi r4, r1, 0x88;
  addi r0, r1, 8;
  lis r5, 0x100;
  lis r3, 0x8001;
  stw r5, 0x68(r1);
  addi r6, r1, 0x68;
  mr r5, r30;
  addi r3, r3, 0x1620;
  stw r4, 0x6c(r1);
  addi r4, r31, 0x50;
  li r7, 0;
  stw r0, 0x70(r1);
  bl __pformatter;
lbl_80011798:
  lwz r0, 0x84(r1);
  lwz r31, 0x7c(r1);
  lwz r30, 0x78(r1);
  mtlr r0;
  addi r1, r1, 0x80;
  blr;
  // clang-format on
}

// Symbol: vprintf
// PAL: 0x800117b0..0x8001182c
MARK_BINARY_BLOB(vprintf, 0x800117b0, 0x8001182c);
asm int vprintf(const char* format, va_list arg) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  lis r31, 0x8027;
  addi r31, r31, 0xcf0;
  stw r30, 0x18(r1);
  mr r30, r4;
  li r4, -1;
  stw r29, 0x14(r1);
  mr r29, r3;
  addi r3, r31, 0x50;
  bl fwide;
  cmpwi r3, 0;
  blt lbl_800117f4;
  li r3, -1;
  b lbl_80011810;
lbl_800117f4:
  lis r3, 0x8001;
  mr r5, r29;
  mr r6, r30;
  addi r4, r31, 0x50;
  addi r3, r3, 0x1620;
  li r7, 0;
  bl __pformatter;
lbl_80011810:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: vsnprintf
// PAL: 0x8001182c..0x800118b4
MARK_BINARY_BLOB(vsnprintf, 0x8001182c, 0x800118b4);
asm int vsnprintf(char* s, size_t n, const char* format, va_list arg) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  lis r7, 0x8001;
  stw r0, 0x34(r1);
  stw r31, 0x2c(r1);
  li r31, 0;
  stw r30, 0x28(r1);
  mr r30, r4;
  stw r29, 0x24(r1);
  mr r29, r3;
  stw r3, 8(r1);
  addi r3, r7, 0x1678;
  li r7, 0;
  stw r4, 0xc(r1);
  addi r4, r1, 8;
  stw r31, 0x10(r1);
  bl __pformatter;
  cmpwi r29, 0;
  beq lbl_80011898;
  cmplw r3, r30;
  bge lbl_80011888;
  stbx r31, r29, r3;
  b lbl_80011898;
lbl_80011888:
  cmpwi r30, 0;
  beq lbl_80011898;
  add r4, r29, r30;
  stb r31, -1(r4);
lbl_80011898:
  lwz r0, 0x34(r1);
  lwz r31, 0x2c(r1);
  lwz r30, 0x28(r1);
  lwz r29, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: vsprintf
// PAL: 0x800118b4..0x80011938
MARK_BINARY_BLOB(vsprintf, 0x800118b4, 0x80011938);
asm int vsprintf(char* s, const char* format, va_list arg) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  mr r6, r5;
  mr r5, r4;
  stw r0, 0x34(r1);
  lis r7, 0x8001;
  addi r4, r1, 8;
  stw r31, 0x2c(r1);
  li r31, 0;
  stw r30, 0x28(r1);
  li r30, -1;
  stw r29, 0x24(r1);
  mr r29, r3;
  stw r3, 8(r1);
  addi r3, r7, 0x1678;
  li r7, 0;
  stw r30, 0xc(r1);
  stw r31, 0x10(r1);
  bl __pformatter;
  cmpwi r29, 0;
  beq lbl_8001191c;
  cmplw r3, r30;
  bge lbl_80011918;
  stbx r31, r29, r3;
  b lbl_8001191c;
lbl_80011918:
  stb r31, -2(r29);
lbl_8001191c:
  lwz r0, 0x34(r1);
  lwz r31, 0x2c(r1);
  lwz r30, 0x28(r1);
  lwz r29, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: snprintf
// PAL: 0x80011938..0x80011a2c
MARK_BINARY_BLOB(snprintf, 0x80011938, 0x80011a2c);
asm int snprintf(char* s, size_t n, const char* format, ...) {
  // clang-format off
  nofralloc;
  stwu r1, -0x90(r1);
  mflr r0;
  stw r0, 0x94(r1);
  stw r31, 0x8c(r1);
  stw r30, 0x88(r1);
  stw r29, 0x84(r1);
  mr r29, r4;
  stw r28, 0x80(r1);
  mr r28, r3;
  bne cr1, lbl_80011980;
  stfd f1, 0x28(r1);
  stfd f2, 0x30(r1);
  stfd f3, 0x38(r1);
  stfd f4, 0x40(r1);
  stfd f5, 0x48(r1);
  stfd f6, 0x50(r1);
  stfd f7, 0x58(r1);
  stfd f8, 0x60(r1);
lbl_80011980:
  addi r12, r1, 0x98;
  addi r0, r1, 8;
  lis r30, 0x300;
  stw r7, 0x18(r1);
  li r31, 0;
  addi r7, r1, 0x74;
  stw r6, 0x14(r1);
  mr r6, r7;
  lis r11, 0x8001;
  li r7, 0;
  stw r5, 0x10(r1);
  stw r3, 8(r1);
  stw r3, 0x68(r1);
  addi r3, r11, 0x1678;
  stw r4, 0xc(r1);
  stw r4, 0x6c(r1);
  addi r4, r1, 0x68;
  stw r8, 0x1c(r1);
  stw r9, 0x20(r1);
  stw r10, 0x24(r1);
  stw r30, 0x74(r1);
  stw r12, 0x78(r1);
  stw r0, 0x7c(r1);
  stw r31, 0x70(r1);
  bl __pformatter;
  cmpwi r28, 0;
  beq lbl_80011a0c;
  cmplw r3, r29;
  bge lbl_800119fc;
  stbx r31, r28, r3;
  b lbl_80011a0c;
lbl_800119fc:
  cmpwi r29, 0;
  beq lbl_80011a0c;
  add r4, r28, r29;
  stb r31, -1(r4);
lbl_80011a0c:
  lwz r0, 0x94(r1);
  lwz r31, 0x8c(r1);
  lwz r30, 0x88(r1);
  lwz r29, 0x84(r1);
  lwz r28, 0x80(r1);
  mtlr r0;
  addi r1, r1, 0x90;
  blr;
  // clang-format on
}

// Symbol: sprintf
// PAL: 0x80011a2c..0x80011b00
MARK_BINARY_BLOB(sprintf, 0x80011a2c, 0x80011b00);
asm int sprintf(char* str, const char* format, ...) {
  // clang-format off
  nofralloc;
  stwu r1, -0xa0(r1);
  mflr r0;
  stw r0, 0xa4(r1);
  stmw r27, 0x8c(r1);
  mr r27, r3;
  bne cr1, lbl_80011a64;
  stfd f1, 0x28(r1);
  stfd f2, 0x30(r1);
  stfd f3, 0x38(r1);
  stfd f4, 0x40(r1);
  stfd f5, 0x48(r1);
  stfd f6, 0x50(r1);
  stfd f7, 0x58(r1);
  stfd f8, 0x60(r1);
lbl_80011a64:
  addi r12, r1, 0xa8;
  addi r0, r1, 8;
  lis r29, 0x200;
  stw r5, 0x10(r1);
  li r30, -1;
  li r31, 0;
  stw r7, 0x18(r1);
  addi r28, r1, 0x74;
  lis r11, 0x8001;
  mr r5, r4;
  stw r4, 0xc(r1);
  addi r4, r1, 0x68;
  li r7, 0;
  stw r6, 0x14(r1);
  mr r6, r28;
  stw r3, 8(r1);
  stw r3, 0x68(r1);
  addi r3, r11, 0x1678;
  stw r8, 0x1c(r1);
  stw r9, 0x20(r1);
  stw r10, 0x24(r1);
  stw r29, 0x74(r1);
  stw r12, 0x78(r1);
  stw r0, 0x7c(r1);
  stw r30, 0x6c(r1);
  stw r31, 0x70(r1);
  bl __pformatter;
  cmpwi r27, 0;
  beq lbl_80011aec;
  cmplw r3, r30;
  bge lbl_80011ae8;
  stbx r31, r27, r3;
  b lbl_80011aec;
lbl_80011ae8:
  stb r31, -2(r27);
lbl_80011aec:
  lmw r27, 0x8c(r1);
  lwz r0, 0xa4(r1);
  mtlr r0;
  addi r1, r1, 0xa0;
  blr;
  // clang-format on
}

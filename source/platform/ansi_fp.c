#include "ansi_fp.h"

#include <math.h>

// Symbol: __ull2dec
// PAL: 0x8000cadc..0x8000cbb8
MARK_BINARY_BLOB(__ull2dec, 0x8000cadc, 0x8000cbb8);
asm UNKNOWN_FUNCTION(__ull2dec) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  li r0, 0;
  stw r31, 0x1c(r1);
  mr r31, r5;
  stw r30, 0x18(r1);
  mr r30, r6;
  stw r29, 0x14(r1);
  mr r29, r3;
  stb r0, 0(r3);
  stb r0, 4(r3);
  b lbl_8000cb54;
lbl_8000cb10:
  mr r3, r31;
  mr r4, r30;
  li r6, 0xa;
  li r5, 0;
  bl __mod2u;
  lbz r8, 4(r29);
  mr r3, r31;
  li r6, 0xa;
  li r5, 0;
  add r7, r29, r8;
  addi r0, r8, 1;
  stb r4, 5(r7);
  mr r4, r30;
  stb r0, 4(r29);
  bl __div2u;
  mr r30, r4;
  mr r31, r3;
lbl_8000cb54:
  or. r0, r30, r31;
  bne lbl_8000cb10;
  lbz r0, 4(r29);
  addi r4, r29, 5;
  add r3, r29, r0;
  addi r3, r3, 5;
  b lbl_8000cb84;
lbl_8000cb70:
  lbz r5, 0(r4);
  lbz r0, 0(r3);
  stb r0, 0(r4);
  addi r4, r4, 1;
  stb r5, 0(r3);
lbl_8000cb84:
  addi r3, r3, -1;
  cmplw r4, r3;
  blt lbl_8000cb70;
  lbz r3, 4(r29);
  addi r0, r3, -1;
  sth r0, 2(r29);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: __timesdec
// PAL: 0x8000cbb8..0x8000ce40
MARK_BINARY_BLOB(__timesdec, 0x8000cbb8, 0x8000ce40);
asm UNKNOWN_FUNCTION(__timesdec) {
  // clang-format off
  nofralloc;
  stwu r1, -0x60(r1);
  lis r6, 0xcccd;
  lbz r8, 4(r4);
  addi r9, r6, -13107;
  stw r31, 0x5c(r1);
  addi r0, r1, 8;
  lbz r7, 4(r5);
  li r11, 0;
  stw r30, 0x58(r1);
  add r12, r8, r7;
  stw r29, 0x54(r1);
  addi r12, r12, -1;
  add r6, r0, r12;
  addi r6, r6, 1;
  stb r11, 0(r3);
  mr r0, r6;
  b lbl_8000cd28;
lbl_8000cbfc:
  lbz r7, 4(r5);
  addi r31, r7, -1;
  subf r7, r31, r12;
  addic. r30, r7, -1;
  bge lbl_8000cc18;
  li r30, 0;
  addi r31, r12, -1;
lbl_8000cc18:
  lbz r7, 4(r4);
  add r8, r5, r31;
  addi r31, r31, 1;
  add r10, r4, r30;
  subf r7, r30, r7;
  addi r29, r8, 5;
  cmpw r31, r7;
  addi r30, r10, 5;
  ble lbl_8000cc40;
  mr r31, r7;
lbl_8000cc40:
  cmpwi r31, 0;
  ble lbl_8000cd08;
  rlwinm. r7, r31, 0x1d, 3, 0x1f;
  mtctr r7;
  beq lbl_8000cce8;
lbl_8000cc54:
  lbz r10, 0(r30);
  lbz r8, 0(r29);
  mullw r7, r10, r8;
  lbz r10, 1(r30);
  lbz r8, -1(r29);
  add r11, r11, r7;
  mullw r7, r10, r8;
  lbz r10, 2(r30);
  lbz r8, -2(r29);
  add r11, r11, r7;
  mullw r7, r10, r8;
  lbz r10, 3(r30);
  lbz r8, -3(r29);
  add r11, r11, r7;
  mullw r7, r10, r8;
  lbz r10, 4(r30);
  lbz r8, -4(r29);
  add r11, r11, r7;
  mullw r7, r10, r8;
  lbz r10, 5(r30);
  lbz r8, -5(r29);
  add r11, r11, r7;
  mullw r7, r10, r8;
  lbz r10, 6(r30);
  lbz r8, -6(r29);
  add r11, r11, r7;
  mullw r7, r10, r8;
  lbz r10, 7(r30);
  lbz r8, -7(r29);
  addi r30, r30, 8;
  addi r29, r29, -8;
  add r11, r11, r7;
  mullw r7, r10, r8;
  add r11, r11, r7;
  bdnz lbl_8000cc54;
  andi. r31, r31, 7;
  beq lbl_8000cd08;
lbl_8000cce8:
  mtctr r31;
lbl_8000ccec:
  lbz r10, 0(r30);
  addi r30, r30, 1;
  lbz r8, 0(r29);
  addi r29, r29, -1;
  mullw r7, r10, r8;
  add r11, r11, r7;
  bdnz lbl_8000ccec;
lbl_8000cd08:
  mulhwu r8, r9, r11;
  addi r12, r12, -1;
  mr r7, r8;
  srwi r8, r8, 3;
  mulli r8, r8, 0xa;
  subf r8, r8, r11;
  stbu r8, -1(r6);
  srwi r11, r7, 3;
lbl_8000cd28:
  cmpwi r12, 0;
  bgt lbl_8000cbfc;
  lha r7, 2(r4);
  cmpwi r11, 0;
  lha r4, 2(r5);
  add r4, r7, r4;
  sth r4, 2(r3);
  beq lbl_8000cd58;
  stbu r11, -1(r6);
  extsh r4, r4;
  addi r4, r4, 1;
  sth r4, 2(r3);
lbl_8000cd58:
  li r7, 0;
  b lbl_8000cd74;
lbl_8000cd60:
  add r4, r3, r7;
  lbz r5, 0(r6);
  stb r5, 5(r4);
  addi r7, r7, 1;
  addi r6, r6, 1;
lbl_8000cd74:
  cmpwi r7, 0x24;
  bge lbl_8000cd84;
  cmplw r6, r0;
  blt lbl_8000cd60;
lbl_8000cd84:
  cmplw r6, r0;
  stb r7, 4(r3);
  bge lbl_8000ce2c;
  lbz r4, 0(r6);
  cmplwi r4, 5;
  blt lbl_8000ce2c;
  bne lbl_8000cdd4;
  addi r5, r6, 1;
  subf r4, r5, r0;
  mtctr r4;
  cmplw r5, r0;
  bge lbl_8000cdc8;
lbl_8000cdb4:
  lbz r0, 0(r5);
  cmpwi r0, 0;
  bne lbl_8000cdd4;
  addi r5, r5, 1;
  bdnz lbl_8000cdb4;
lbl_8000cdc8:
  lbz r0, -1(r6);
  clrlwi. r0, r0, 0x1f;
  beq lbl_8000ce2c;
lbl_8000cdd4:
  lbz r4, 4(r3);
  addi r6, r3, 5;
  li r0, 0;
  add r5, r6, r4;
  addi r5, r5, -1;
lbl_8000cde8:
  lbz r4, 0(r5);
  cmplwi r4, 9;
  bge lbl_8000ce00;
  addi r0, r4, 1;
  stb r0, 0(r5);
  b lbl_8000ce2c;
lbl_8000ce00:
  cmplw r5, r6;
  bne lbl_8000ce20;
  li r0, 1;
  stb r0, 0(r5);
  lha r4, 2(r3);
  addi r0, r4, 1;
  sth r0, 2(r3);
  b lbl_8000ce2c;
lbl_8000ce20:
  stb r0, 0(r5);
  addi r5, r5, -1;
  b lbl_8000cde8;
lbl_8000ce2c:
  lwz r31, 0x5c(r1);
  lwz r30, 0x58(r1);
  lwz r29, 0x54(r1);
  addi r1, r1, 0x60;
  blr;
  // clang-format on
}

// Symbol: __str2dec
// PAL: 0x8000ce40..0x8000cf2c
MARK_BINARY_BLOB(__str2dec, 0x8000ce40, 0x8000cf2c);
asm UNKNOWN_FUNCTION(__str2dec) {
  // clang-format off
  nofralloc;
  li r0, 0;
  sth r5, 2(r3);
  li r7, 0;
  stb r0, 0(r3);
  b lbl_8000ce6c;
lbl_8000ce54:
  lbz r6, 0(r4);
  add r5, r3, r7;
  addi r4, r4, 1;
  addi r7, r7, 1;
  addi r0, r6, -48;
  stb r0, 5(r5);
lbl_8000ce6c:
  cmpwi r7, 0x24;
  bge lbl_8000ce80;
  lbz r0, 0(r4);
  extsb. r0, r0;
  bne lbl_8000ce54;
lbl_8000ce80:
  lbz r0, 0(r4);
  stb r7, 4(r3);
  extsb. r0, r0;
  beqlr;
  cmpwi r0, 5;
  bltlr;
  bgt lbl_8000ced0;
  addi r5, r4, 1;
  b lbl_8000ceb4;
lbl_8000cea4:
  extsb r0, r4;
  cmpwi r0, 0x30;
  bne lbl_8000ced0;
  addi r5, r5, 1;
lbl_8000ceb4:
  lbz r4, 0(r5);
  extsb. r0, r4;
  bne lbl_8000cea4;
  add r4, r7, r3;
  lbz r0, 4(r4);
  clrlwi. r0, r0, 0x1f;
  beqlr;
lbl_8000ced0:
  lbz r4, 4(r3);
  addi r6, r3, 5;
  li r0, 0;
  add r5, r6, r4;
  addi r5, r5, -1;
lbl_8000cee4:
  lbz r4, 0(r5);
  cmplwi r4, 9;
  bge lbl_8000cefc;
  addi r0, r4, 1;
  stb r0, 0(r5);
  blr;
lbl_8000cefc:
  cmplw r5, r6;
  bne lbl_8000cf1c;
  li r0, 1;
  stb r0, 0(r5);
  lha r4, 2(r3);
  addi r0, r4, 1;
  sth r0, 2(r3);
  blr;
lbl_8000cf1c:
  stb r0, 0(r5);
  addi r5, r5, -1;
  b lbl_8000cee4;
  blr;
  // clang-format on
}

// Symbol: __two_exp
// PAL: 0x8000cf2c..0x8000d298
MARK_BINARY_BLOB(__two_exp, 0x8000cf2c, 0x8000d298);
asm UNKNOWN_FUNCTION(__two_exp) {
  // clang-format off
  nofralloc;
lbl_8000cf2c:
  stwu r1, -0x70(r1);
  mflr r0;
  stw r0, 0x74(r1);
  addi r0, r4, 0x40;
  cmplwi r0, 0x48;
  stw r31, 0x6c(r1);
  mr r31, r3;
  stw r30, 0x68(r1);
  mr r30, r4;
  bgt lbl_8000d160;
  lis r5, 0x8027;
  slwi r0, r0, 2;
  addi r5, r5, 0xe30;
  lwzx r5, r5, r0;
  mtctr r5;
  bctr;
  lis r4, 0x8024;
  li r5, -20;
  addi r4, r4, 0x6040;
  bl __str2dec;
  b lbl_8000d280;
  lis r4, 0x8024;
  li r5, -16;
  addi r4, r4, 0x6040;
  addi r4, r4, 0x2e;
  bl __str2dec;
  b lbl_8000d280;
  lis r4, 0x8024;
  li r5, -10;
  addi r4, r4, 0x6040;
  addi r4, r4, 0x55;
  bl __str2dec;
  b lbl_8000d280;
  lis r4, 0x8024;
  li r5, -5;
  addi r4, r4, 0x6040;
  addi r4, r4, 0x6d;
  bl __str2dec;
  b lbl_8000d280;
  lis r4, 0x8024;
  li r5, -3;
  addi r4, r4, 0x6040;
  addi r4, r4, 0x7a;
  bl __str2dec;
  b lbl_8000d280;
  lis r4, 0x8024;
  li r5, -3;
  addi r4, r4, 0x6040;
  addi r4, r4, 0x81;
  bl __str2dec;
  b lbl_8000d280;
  lis r4, 0x8024;
  li r5, -2;
  addi r4, r4, 0x6040;
  addi r4, r4, 0x87;
  bl __str2dec;
  b lbl_8000d280;
  lis r4, 0x8024;
  li r5, -2;
  addi r4, r4, 0x6040;
  addi r4, r4, 0x8d;
  bl __str2dec;
  b lbl_8000d280;
  lis r4, 0x8024;
  li r5, -2;
  addi r4, r4, 0x6040;
  addi r4, r4, 0x92;
  bl __str2dec;
  b lbl_8000d280;
  lis r4, 0x8024;
  li r5, -1;
  addi r4, r4, 0x6040;
  addi r4, r4, 0x96;
  bl __str2dec;
  b lbl_8000d280;
  lis r4, 0x8024;
  li r5, -1;
  addi r4, r4, 0x6040;
  addi r4, r4, 0x9a;
  bl __str2dec;
  b lbl_8000d280;
  lis r4, 0x8024;
  li r5, -1;
  addi r4, r4, 0x6040;
  addi r4, r4, 0x9d;
  bl __str2dec;
  b lbl_8000d280;
  lis r4, 0x8024;
  li r5, 0;
  addi r4, r4, 0x6040;
  addi r4, r4, 0x9f;
  bl __str2dec;
  b lbl_8000d280;
  lis r4, 0x8024;
  li r5, 0;
  addi r4, r4, 0x6040;
  addi r4, r4, 0xa1;
  bl __str2dec;
  b lbl_8000d280;
  lis r4, 0x8024;
  li r5, 0;
  addi r4, r4, 0x6040;
  addi r4, r4, 0xa3;
  bl __str2dec;
  b lbl_8000d280;
  lis r4, 0x8024;
  li r5, 0;
  addi r4, r4, 0x6040;
  addi r4, r4, 0xa5;
  bl __str2dec;
  b lbl_8000d280;
  lis r4, 0x8024;
  li r5, 1;
  addi r4, r4, 0x6040;
  addi r4, r4, 0xa7;
  bl __str2dec;
  b lbl_8000d280;
  lis r4, 0x8024;
  li r5, 1;
  addi r4, r4, 0x6040;
  addi r4, r4, 0xaa;
  bl __str2dec;
  b lbl_8000d280;
  lis r4, 0x8024;
  li r5, 1;
  addi r4, r4, 0x6040;
  addi r4, r4, 0xad;
  bl __str2dec;
  b lbl_8000d280;
  lis r4, 0x8024;
  li r5, 2;
  addi r4, r4, 0x6040;
  addi r4, r4, 0xb0;
  bl __str2dec;
  b lbl_8000d280;
  lis r4, 0x8024;
  li r5, 2;
  addi r4, r4, 0x6040;
  addi r4, r4, 0xb4;
  bl __str2dec;
  b lbl_8000d280;
lbl_8000d160:
  srwi r0, r4, 0x1f;
  addi r3, r1, 0x34;
  add r0, r0, r4;
  srawi r4, r0, 1;
  bl lbl_8000cf2c;
  addi r4, r1, 0x34;
  mr r3, r31;
  mr r5, r4;
  bl __timesdec;
  clrlwi. r0, r30, 0x1f;
  beq lbl_8000d280;
  lhz r3, 0(r31);
  cmpwi r30, 0;
  lhz r0, 2(r31);
  sth r0, 0xa(r1);
  sth r3, 8(r1);
  lhz r3, 4(r31);
  lhz r0, 6(r31);
  sth r0, 0xe(r1);
  sth r3, 0xc(r1);
  lhz r3, 8(r31);
  lhz r0, 0xa(r31);
  sth r0, 0x12(r1);
  sth r3, 0x10(r1);
  lhz r3, 0xc(r31);
  lhz r0, 0xe(r31);
  sth r0, 0x16(r1);
  sth r3, 0x14(r1);
  lhz r3, 0x10(r31);
  lhz r0, 0x12(r31);
  sth r0, 0x1a(r1);
  sth r3, 0x18(r1);
  lhz r3, 0x14(r31);
  lhz r0, 0x16(r31);
  sth r0, 0x1e(r1);
  sth r3, 0x1c(r1);
  lhz r3, 0x18(r31);
  lhz r0, 0x1a(r31);
  sth r0, 0x22(r1);
  sth r3, 0x20(r1);
  lhz r3, 0x1c(r31);
  lhz r0, 0x1e(r31);
  sth r0, 0x26(r1);
  sth r3, 0x24(r1);
  lhz r3, 0x20(r31);
  lhz r0, 0x22(r31);
  sth r0, 0x2a(r1);
  sth r3, 0x28(r1);
  lhz r3, 0x24(r31);
  lhz r0, 0x26(r31);
  sth r0, 0x2e(r1);
  sth r3, 0x2c(r1);
  lhz r0, 0x28(r31);
  sth r0, 0x30(r1);
  ble lbl_8000d258;
  lis r4, 0x8024;
  addi r3, r1, 0x34;
  addi r4, r4, 0x6040;
  li r5, 0;
  addi r4, r4, 0xa1;
  bl __str2dec;
  b lbl_8000d270;
lbl_8000d258:
  lis r4, 0x8024;
  addi r3, r1, 0x34;
  addi r4, r4, 0x6040;
  li r5, -1;
  addi r4, r4, 0x9d;
  bl __str2dec;
lbl_8000d270:
  mr r3, r31;
  addi r4, r1, 8;
  addi r5, r1, 0x34;
  bl __timesdec;
lbl_8000d280:
  lwz r0, 0x74(r1);
  lwz r31, 0x6c(r1);
  lwz r30, 0x68(r1);
  mtlr r0;
  addi r1, r1, 0x70;
  blr;
  // clang-format on
}

// Symbol: __equals_dec
// PAL: 0x8000d298..0x8000d37c
MARK_BINARY_BLOB(__equals_dec, 0x8000d298, 0x8000d37c);
asm UNKNOWN_FUNCTION(__equals_dec) {
  // clang-format off
  nofralloc;
  lbz r5, 5(r3);
  cmpwi r5, 0;
  bne lbl_8000d2b4;
  lbz r0, 5(r4);
  cntlzw r0, r0;
  srwi r3, r0, 5;
  blr;
lbl_8000d2b4:
  lbz r0, 5(r4);
  cmpwi r0, 0;
  bne lbl_8000d2cc;
  cntlzw r0, r5;
  srwi r3, r0, 5;
  blr;
lbl_8000d2cc:
  lha r5, 2(r3);
  lha r0, 2(r4);
  cmpw r5, r0;
  bne lbl_8000d374;
  lbz r7, 4(r3);
  lbz r0, 4(r4);
  mr r9, r7;
  cmpw r7, r0;
  ble lbl_8000d2f4;
  mr r9, r0;
lbl_8000d2f4:
  li r8, 0;
  mtctr r9;
  cmpwi r9, 0;
  ble lbl_8000d32c;
lbl_8000d304:
  add r6, r3, r8;
  add r5, r4, r8;
  lbz r6, 5(r6);
  lbz r0, 5(r5);
  cmplw r6, r0;
  beq lbl_8000d324;
  li r3, 0;
  blr;
lbl_8000d324:
  addi r8, r8, 1;
  bdnz lbl_8000d304;
lbl_8000d32c:
  cmpw r9, r7;
  bne lbl_8000d338;
  mr r3, r4;
lbl_8000d338:
  lbz r4, 4(r3);
  subf r0, r8, r4;
  mtctr r0;
  cmpw r8, r4;
  bge lbl_8000d36c;
lbl_8000d34c:
  add r4, r3, r8;
  lbz r0, 5(r4);
  cmpwi r0, 0;
  beq lbl_8000d364;
  li r3, 0;
  blr;
lbl_8000d364:
  addi r8, r8, 1;
  bdnz lbl_8000d34c;
lbl_8000d36c:
  li r3, 1;
  blr;
lbl_8000d374:
  li r3, 0;
  blr;
  // clang-format on
}

// Symbol: __less_dec
// PAL: 0x8000d37c..0x8000d47c
MARK_BINARY_BLOB(__less_dec, 0x8000d37c, 0x8000d47c);
asm UNKNOWN_FUNCTION(__less_dec) {
  // clang-format off
  nofralloc;
  lbz r0, 5(r3);
  cmpwi r0, 0;
  bne lbl_8000d39c;
  lbz r3, 5(r4);
  neg r0, r3;
  or r0, r0, r3;
  srwi r3, r0, 0x1f;
  blr;
lbl_8000d39c:
  lbz r0, 5(r4);
  cmpwi r0, 0;
  bne lbl_8000d3b0;
  li r3, 0;
  blr;
lbl_8000d3b0:
  lha r5, 2(r4);
  lha r0, 2(r3);
  cmpw r0, r5;
  bne lbl_8000d464;
  lbz r7, 4(r3);
  lbz r0, 4(r4);
  mr r9, r7;
  cmpw r7, r0;
  ble lbl_8000d3d8;
  mr r9, r0;
lbl_8000d3d8:
  li r8, 0;
  mtctr r9;
  cmpwi r9, 0;
  ble lbl_8000d420;
lbl_8000d3e8:
  add r6, r4, r8;
  add r5, r3, r8;
  lbz r6, 5(r6);
  lbz r0, 5(r5);
  cmplw r0, r6;
  bge lbl_8000d408;
  li r3, 1;
  blr;
lbl_8000d408:
  cmplw r6, r0;
  bge lbl_8000d418;
  li r3, 0;
  blr;
lbl_8000d418:
  addi r8, r8, 1;
  bdnz lbl_8000d3e8;
lbl_8000d420:
  cmpw r9, r7;
  bne lbl_8000d45c;
  lbz r3, 4(r4);
  subf r0, r8, r3;
  mtctr r0;
  cmpw r8, r3;
  bge lbl_8000d45c;
lbl_8000d43c:
  add r3, r4, r8;
  lbz r0, 5(r3);
  cmpwi r0, 0;
  beq lbl_8000d454;
  li r3, 1;
  blr;
lbl_8000d454:
  addi r8, r8, 1;
  bdnz lbl_8000d43c;
lbl_8000d45c:
  li r3, 0;
  blr;
lbl_8000d464:
  xor r0, r5, r0;
  srawi r3, r0, 1;
  and r0, r0, r5;
  subf r0, r0, r3;
  srwi r3, r0, 0x1f;
  blr;
  // clang-format on
}

// Symbol: __minus_dec
// PAL: 0x8000d47c..0x8000d998
MARK_BINARY_BLOB(__minus_dec, 0x8000d47c, 0x8000d998);
asm UNKNOWN_FUNCTION(__minus_dec) {
  // clang-format off
  nofralloc;
  stwu r1, -0x40(r1);
  lhz r12, 0x1a(r4);
  stmw r19, 0xc(r1);
  lhz r19, 0(r4);
  lhz r20, 2(r4);
  lhz r21, 4(r4);
  lhz r22, 6(r4);
  lhz r23, 8(r4);
  lhz r24, 0xa(r4);
  lhz r25, 0xc(r4);
  lhz r26, 0xe(r4);
  lhz r27, 0x10(r4);
  lhz r28, 0x12(r4);
  lhz r29, 0x14(r4);
  lhz r30, 0x16(r4);
  lhz r31, 0x18(r4);
  lhz r11, 0x1c(r4);
  lhz r10, 0x1e(r4);
  lhz r9, 0x20(r4);
  lhz r8, 0x22(r4);
  lhz r7, 0x24(r4);
  lhz r6, 0x26(r4);
  lhz r0, 0x28(r4);
  sth r19, 0(r3);
  sth r20, 2(r3);
  sth r21, 4(r3);
  sth r22, 6(r3);
  sth r23, 8(r3);
  sth r24, 0xa(r3);
  sth r25, 0xc(r3);
  sth r26, 0xe(r3);
  sth r27, 0x10(r3);
  sth r28, 0x12(r3);
  sth r29, 0x14(r3);
  sth r30, 0x16(r3);
  sth r31, 0x18(r3);
  sth r12, 0x1a(r3);
  sth r11, 0x1c(r3);
  sth r10, 0x1e(r3);
  sth r9, 0x20(r3);
  sth r8, 0x22(r3);
  sth r7, 0x24(r3);
  sth r6, 0x26(r3);
  sth r0, 0x28(r3);
  lbz r0, 5(r5);
  cmpwi r0, 0;
  beq lbl_8000d98c;
  lbz r8, 4(r3);
  lbz r0, 4(r5);
  cmpw r8, r0;
  bge lbl_8000d54c;
  mr r8, r0;
lbl_8000d54c:
  lha r4, 2(r5);
  lha r0, 2(r3);
  subf r0, r4, r0;
  add r8, r8, r0;
  cmpwi r8, 0x24;
  ble lbl_8000d568;
  li r8, 0x24;
lbl_8000d568:
  li r7, 0;
  b lbl_8000d584;
lbl_8000d570:
  lbz r6, 4(r3);
  add r4, r3, r6;
  addi r6, r6, 1;
  stb r7, 5(r4);
  stb r6, 4(r3);
lbl_8000d584:
  lbz r4, 4(r3);
  cmpw r4, r8;
  blt lbl_8000d570;
  lbz r7, 4(r5);
  addi r4, r3, 5;
  add r6, r4, r8;
  add r7, r7, r0;
  cmpw r7, r8;
  bge lbl_8000d5ac;
  add r6, r4, r7;
lbl_8000d5ac:
  subf r7, r4, r6;
  addi r9, r5, 5;
  subf r7, r0, r7;
  add r10, r9, r7;
  mr r11, r10;
  b lbl_8000d6e4;
lbl_8000d5c4:
  lbzu r8, -1(r6);
  lbzu r7, -1(r10);
  cmplw r8, r7;
  bge lbl_8000d6d4;
  addi r12, r6, -1;
  b lbl_8000d5e0;
lbl_8000d5dc:
  addi r12, r12, -1;
lbl_8000d5e0:
  lbz r7, 0(r12);
  cmpwi r7, 0;
  beq lbl_8000d5dc;
  cmplw r12, r6;
  subf r8, r12, r6;
  beq lbl_8000d6d4;
  rlwinm. r7, r8, 0x1d, 3, 0x1f;
  mtctr r7;
  beq lbl_8000d6b4;
lbl_8000d604:
  lbz r7, 0(r12);
  addi r7, r7, -1;
  stb r7, 0(r12);
  lbz r7, 1(r12);
  addi r7, r7, 0xa;
  clrlwi r7, r7, 0x18;
  addi r7, r7, -1;
  stb r7, 1(r12);
  lbz r7, 2(r12);
  addi r7, r7, 0xa;
  clrlwi r7, r7, 0x18;
  addi r7, r7, -1;
  stb r7, 2(r12);
  lbz r7, 3(r12);
  addi r7, r7, 0xa;
  clrlwi r7, r7, 0x18;
  addi r7, r7, -1;
  stb r7, 3(r12);
  lbz r7, 4(r12);
  addi r7, r7, 0xa;
  clrlwi r7, r7, 0x18;
  addi r7, r7, -1;
  stb r7, 4(r12);
  lbz r7, 5(r12);
  addi r7, r7, 0xa;
  clrlwi r7, r7, 0x18;
  addi r7, r7, -1;
  stb r7, 5(r12);
  lbz r7, 6(r12);
  addi r7, r7, 0xa;
  clrlwi r7, r7, 0x18;
  addi r7, r7, -1;
  stb r7, 6(r12);
  lbz r7, 7(r12);
  addi r7, r7, 0xa;
  clrlwi r7, r7, 0x18;
  addi r7, r7, -1;
  stb r7, 7(r12);
  lbz r7, 8(r12);
  addi r7, r7, 0xa;
  stbu r7, 8(r12);
  bdnz lbl_8000d604;
  andi. r8, r8, 7;
  beq lbl_8000d6d4;
lbl_8000d6b4:
  mtctr r8;
lbl_8000d6b8:
  lbz r7, 0(r12);
  addi r7, r7, -1;
  stb r7, 0(r12);
  lbz r7, 1(r12);
  addi r7, r7, 0xa;
  stbu r7, 1(r12);
  bdnz lbl_8000d6b8;
lbl_8000d6d4:
  lbz r8, 0(r10);
  lbz r7, 0(r6);
  subf r7, r8, r7;
  stb r7, 0(r6);
lbl_8000d6e4:
  cmplw r6, r4;
  ble lbl_8000d6f4;
  cmplw r10, r9;
  bgt lbl_8000d5c4;
lbl_8000d6f4:
  lbz r8, 4(r5);
  subf r9, r9, r11;
  cmpw r9, r8;
  bge lbl_8000d888;
  lbz r7, 0(r11);
  li r10, 0;
  cmplwi r7, 5;
  bge lbl_8000d71c;
  li r10, 1;
  b lbl_8000d768;
lbl_8000d71c:
  bne lbl_8000d768;
  add r5, r5, r8;
  addi r6, r11, 1;
  addi r7, r5, 5;
  subf r5, r6, r7;
  mtctr r5;
  cmplw r6, r7;
  bge lbl_8000d750;
lbl_8000d73c:
  lbz r5, 0(r6);
  cmpwi r5, 0;
  bne lbl_8000d888;
  addi r6, r6, 1;
  bdnz lbl_8000d73c;
lbl_8000d750:
  add r5, r4, r9;
  add r6, r0, r5;
  lbzu r0, -1(r6);
  clrlwi. r0, r0, 0x1f;
  beq lbl_8000d768;
  li r10, 1;
lbl_8000d768:
  cmpwi r10, 0;
  beq lbl_8000d888;
  lbz r0, 0(r6);
  cmplwi r0, 1;
  bge lbl_8000d87c;
  addi r8, r6, -1;
  b lbl_8000d788;
lbl_8000d784:
  addi r8, r8, -1;
lbl_8000d788:
  lbz r0, 0(r8);
  cmpwi r0, 0;
  beq lbl_8000d784;
  cmplw r8, r6;
  subf r5, r8, r6;
  beq lbl_8000d87c;
  rlwinm. r0, r5, 0x1d, 3, 0x1f;
  mtctr r0;
  beq lbl_8000d85c;
lbl_8000d7ac:
  lbz r7, 0(r8);
  addi r0, r7, -1;
  stb r0, 0(r8);
  lbz r7, 1(r8);
  addi r0, r7, 0xa;
  clrlwi r7, r0, 0x18;
  addi r0, r7, -1;
  stb r0, 1(r8);
  lbz r7, 2(r8);
  addi r0, r7, 0xa;
  clrlwi r7, r0, 0x18;
  addi r0, r7, -1;
  stb r0, 2(r8);
  lbz r7, 3(r8);
  addi r0, r7, 0xa;
  clrlwi r7, r0, 0x18;
  addi r0, r7, -1;
  stb r0, 3(r8);
  lbz r7, 4(r8);
  addi r0, r7, 0xa;
  clrlwi r7, r0, 0x18;
  addi r0, r7, -1;
  stb r0, 4(r8);
  lbz r7, 5(r8);
  addi r0, r7, 0xa;
  clrlwi r7, r0, 0x18;
  addi r0, r7, -1;
  stb r0, 5(r8);
  lbz r7, 6(r8);
  addi r0, r7, 0xa;
  clrlwi r7, r0, 0x18;
  addi r0, r7, -1;
  stb r0, 6(r8);
  lbz r7, 7(r8);
  addi r0, r7, 0xa;
  clrlwi r7, r0, 0x18;
  addi r0, r7, -1;
  stb r0, 7(r8);
  lbz r7, 8(r8);
  addi r0, r7, 0xa;
  stbu r0, 8(r8);
  bdnz lbl_8000d7ac;
  andi. r5, r5, 7;
  beq lbl_8000d87c;
lbl_8000d85c:
  mtctr r5;
lbl_8000d860:
  lbz r7, 0(r8);
  addi r0, r7, -1;
  stb r0, 0(r8);
  lbz r7, 1(r8);
  addi r0, r7, 0xa;
  stbu r0, 1(r8);
  bdnz lbl_8000d860;
lbl_8000d87c:
  lbz r5, 0(r6);
  addi r0, r5, -1;
  stb r0, 0(r6);
lbl_8000d888:
  mr r7, r4;
  b lbl_8000d894;
lbl_8000d890:
  addi r7, r7, 1;
lbl_8000d894:
  lbz r0, 0(r7);
  cmpwi r0, 0;
  beq lbl_8000d890;
  cmplw r7, r4;
  ble lbl_8000d954;
  lbz r0, 4(r3);
  subf r6, r4, r7;
  clrlwi r8, r6, 0x18;
  lha r5, 2(r3);
  add r6, r4, r0;
  cmplw r7, r6;
  subf r0, r8, r5;
  sth r0, 2(r3);
  subf r5, r7, r6;
  bge lbl_8000d948;
  rlwinm. r0, r5, 0x1d, 3, 0x1f;
  mtctr r0;
  beq lbl_8000d930;
lbl_8000d8dc:
  lbz r0, 0(r7);
  stb r0, 0(r4);
  lbz r0, 1(r7);
  stb r0, 1(r4);
  lbz r0, 2(r7);
  stb r0, 2(r4);
  lbz r0, 3(r7);
  stb r0, 3(r4);
  lbz r0, 4(r7);
  stb r0, 4(r4);
  lbz r0, 5(r7);
  stb r0, 5(r4);
  lbz r0, 6(r7);
  stb r0, 6(r4);
  lbz r0, 7(r7);
  addi r7, r7, 8;
  stb r0, 7(r4);
  addi r4, r4, 8;
  bdnz lbl_8000d8dc;
  andi. r5, r5, 7;
  beq lbl_8000d948;
lbl_8000d930:
  mtctr r5;
lbl_8000d934:
  lbz r0, 0(r7);
  addi r7, r7, 1;
  stb r0, 0(r4);
  addi r4, r4, 1;
  bdnz lbl_8000d934;
lbl_8000d948:
  lbz r0, 4(r3);
  subf r0, r8, r0;
  stb r0, 4(r3);
lbl_8000d954:
  lbz r0, 4(r3);
  addi r4, r3, 5;
  add r5, r4, r0;
  subf r0, r4, r5;
  mtctr r0;
  cmplw r5, r4;
  ble lbl_8000d980;
lbl_8000d970:
  lbzu r0, -1(r5);
  cmpwi r0, 0;
  bne lbl_8000d980;
  bdnz lbl_8000d970;
lbl_8000d980:
  subf r4, r4, r5;
  addi r0, r4, 1;
  stb r0, 4(r3);
lbl_8000d98c:
  lmw r19, 0xc(r1);
  addi r1, r1, 0x40;
  blr;
  // clang-format on
}

// Symbol: __num2dec_internal
// PAL: 0x8000d998..0x8000dafc
MARK_BINARY_BLOB(__num2dec_internal, 0x8000d998, 0x8000dafc);
asm UNKNOWN_FUNCTION(__num2dec_internal) {
  // clang-format off
  nofralloc;
  stwu r1, -0x90(r1);
  mflr r0;
  stw r0, 0x94(r1);
  stfd f31, 0x88(r1);
  fmr f31, f1;
  stw r31, 0x84(r1);
  stw r30, 0x80(r1);
  mr r30, r3;
  stw r29, 0x7c(r1);
  bl __signbitd;
  lfd f0, 0.0;
  neg r0, r3;
  or r0, r0, r3;
  fcmpu cr0, f0, f31;
  srwi r0, r0, 0x1f;
  extsb r31, r0;
  bne lbl_8000d9f8;
  li r3, 0;
  li r0, 1;
  stb r31, 0(r30);
  sth r3, 2(r30);
  stb r0, 4(r30);
  stb r3, 5(r30);
  b lbl_8000dadc;
lbl_8000d9f8:
  fmr f1, f31;
  bl __fpclassifyd;
  cmpwi r3, 2;
  bgt lbl_8000da3c;
  fmr f1, f31;
  li r3, 0;
  li r0, 1;
  stb r31, 0(r30);
  sth r3, 2(r30);
  stb r0, 4(r30);
  bl __fpclassifyd;
  cmpwi r3, 1;
  li r0, 0x49;
  bne lbl_8000da34;
  li r0, 0x4e;
lbl_8000da34:
  stb r0, 5(r30);
  b lbl_8000dadc;
lbl_8000da3c:
  cmpwi r31, 0;
  beq lbl_8000da48;
  fneg f31, f31;
lbl_8000da48:
  fmr f1, f31;
  addi r3, r1, 8;
  bl frexp;
  stfd f1, 0x10(r1);
  fmr f31, f1;
  lwz r4, 0x14(r1);
  lwz r3, 0x10(r1);
  addi r0, r4, -1;
  cmpwi r4, 0;
  andc r0, r0, r4;
  oris r3, r3, 0x10;
  cntlzw r0, r0;
  subfic r4, r0, 0x20;
  bne lbl_8000da94;
  addi r0, r3, -1;
  andc r0, r0, r3;
  cntlzw r0, r0;
  subfic r3, r0, 0x20;
  addi r4, r3, 0x20;
lbl_8000da94:
  lwz r0, 8(r1);
  subfic r29, r4, 0x35;
  addi r3, r1, 0x18;
  subf r4, r29, r0;
  bl __two_exp;
  fmr f1, f31;
  mr r3, r29;
  bl ldexp;
  bl __cvt_dbl_ull;
  mr r5, r3;
  mr r6, r4;
  addi r3, r1, 0x44;
  bl __ull2dec;
  mr r3, r30;
  addi r4, r1, 0x44;
  addi r5, r1, 0x18;
  bl __timesdec;
  stb r31, 0(r30);
lbl_8000dadc:
  lwz r0, 0x94(r1);
  lfd f31, 0x88(r1);
  lwz r31, 0x84(r1);
  lwz r30, 0x80(r1);
  lwz r29, 0x7c(r1);
  mtlr r0;
  addi r1, r1, 0x90;
  blr;
  // clang-format on
}

// Symbol: __num2dec
// PAL: 0x8000dafc..0x8000dc9c
MARK_BINARY_BLOB(__num2dec, 0x8000dafc, 0x8000dc9c);
asm UNKNOWN_FUNCTION(__num2dec) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  lha r31, 2(r3);
  stw r30, 8(r1);
  mr r30, r4;
  mr r3, r30;
  bl __num2dec_internal;
  lbz r0, 5(r30);
  cmplwi r0, 9;
  bgt lbl_8000dc84;
  cmpwi r31, 0x24;
  ble lbl_8000db38;
  li r31, 0x24;
lbl_8000db38:
  cmpwi r31, 0;
  ble lbl_8000dc24;
  lbz r0, 4(r30);
  cmpw r31, r0;
  bge lbl_8000dc24;
  addi r4, r30, 5;
  lbzx r0, r4, r31;
  add r3, r4, r31;
  cmplwi r0, 5;
  ble lbl_8000db68;
  li r4, 1;
  b lbl_8000dbc4;
lbl_8000db68:
  bge lbl_8000db74;
  li r4, -1;
  b lbl_8000dbc4;
lbl_8000db74:
  lbz r0, 4(r30);
  addi r3, r3, 1;
  add r4, r4, r0;
  subf r0, r3, r4;
  mtctr r0;
  cmplw r3, r4;
  bge lbl_8000dbac;
lbl_8000db90:
  lbz r0, 0(r3);
  cmpwi r0, 0;
  beq lbl_8000dba4;
  li r4, 1;
  b lbl_8000dbc4;
lbl_8000dba4:
  addi r3, r3, 1;
  bdnz lbl_8000db90;
lbl_8000dbac:
  add r3, r31, r30;
  li r4, -1;
  lbz r0, 4(r3);
  clrlwi. r0, r0, 0x1f;
  beq lbl_8000dbc4;
  li r4, 1;
lbl_8000dbc4:
  cmpwi r4, 0;
  stb r31, 4(r30);
  blt lbl_8000dc24;
  addi r4, r30, 5;
  li r0, 0;
  add r5, r4, r31;
  addi r5, r5, -1;
lbl_8000dbe0:
  lbz r3, 0(r5);
  cmplwi r3, 9;
  bge lbl_8000dbf8;
  addi r0, r3, 1;
  stb r0, 0(r5);
  b lbl_8000dc24;
lbl_8000dbf8:
  cmplw r5, r4;
  bne lbl_8000dc18;
  li r0, 1;
  stb r0, 0(r5);
  lha r3, 2(r30);
  addi r0, r3, 1;
  sth r0, 2(r30);
  b lbl_8000dc24;
lbl_8000dc18:
  stb r0, 0(r5);
  addi r5, r5, -1;
  b lbl_8000dbe0;
lbl_8000dc24:
  li r5, 0;
  b lbl_8000dc40;
lbl_8000dc2c:
  lbz r4, 4(r30);
  add r3, r30, r4;
  addi r0, r4, 1;
  stb r5, 5(r3);
  stb r0, 4(r30);
lbl_8000dc40:
  lbz r3, 4(r30);
  cmpw r3, r31;
  blt lbl_8000dc2c;
  lha r0, 2(r30);
  addi r3, r3, -1;
  li r5, 0;
  subf r0, r3, r0;
  sth r0, 2(r30);
  b lbl_8000dc78;
lbl_8000dc64:
  add r4, r30, r5;
  addi r5, r5, 1;
  lbz r3, 5(r4);
  addi r0, r3, 0x30;
  stb r0, 5(r4);
lbl_8000dc78:
  lbz r0, 4(r30);
  cmpw r5, r0;
  blt lbl_8000dc64;
lbl_8000dc84:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: __dec2num
// PAL: 0x8000dc9c..0x8000e418
MARK_BINARY_BLOB(__dec2num, 0x8000dc9c, 0x8000e418);
asm UNKNOWN_FUNCTION(__dec2num) {
  // clang-format off
  nofralloc;
  stwu r1, -0x180(r1);
  mflr r0;
  stw r0, 0x184(r1);
  stfd f31, 0x170(r1);
  psq_st f31, 376(r1), 0, 0;
  addi r11, r1, 0x170;
  bl _savegpr_19;
  lbz r0, 4(r3);
  lis r4, 0x4330;
  stw r4, 0x128(r1);
  mr r27, r3;
  cmpwi r0, 0;
  stw r4, 0x130(r1);
  bne lbl_8000dcf8;
  lbz r0, 0(r3);
  extsb. r0, r0;
  bne lbl_8000dce8;
  lfd f2, 1.0;
  b lbl_8000dcec;
lbl_8000dce8:
  lfd f2, -1.0;
lbl_8000dcec:
  lfd f1, 0.0;
  bl copysign;
  b lbl_8000e414;
lbl_8000dcf8:
  lbz r0, 5(r3);
  cmpwi r0, 0x30;
  beq lbl_8000dd18;
  cmpwi r0, 0x49;
  beq lbl_8000dd3c;
  cmpwi r0, 0x4e;
  beq lbl_8000dd64;
  b lbl_8000dda4;
lbl_8000dd18:
  lbz r0, 0(r3);
  extsb. r0, r0;
  bne lbl_8000dd2c;
  lfd f2, 1.0;
  b lbl_8000dd30;
lbl_8000dd2c:
  lfd f2, -1.0;
lbl_8000dd30:
  lfd f1, 0.0;
  bl copysign;
  b lbl_8000e414;
lbl_8000dd3c:
  lbz r0, 0(r3);
  extsb. r0, r0;
  bne lbl_8000dd50;
  lfd f2, 1.0;
  b lbl_8000dd54;
lbl_8000dd50:
  lfd f2, -1.0;
lbl_8000dd54:
  lis r3, 0x8038;
  lfs f1, 0x4c24(r3);
  bl copysign;
  b lbl_8000e414;
lbl_8000dd64:
  lbz r0, 0(r3);
  li r4, 0;
  lis r3, 0x7ff0;
  stw r4, 0x1c(r1);
  extsb. r0, r0;
  stw r3, 0x18(r1);
  beq lbl_8000dd90;
  lis r0, 0x8000;
  stw r4, 0x1c(r1);
  oris r0, r0, 0x7ff0;
  stw r0, 0x18(r1);
lbl_8000dd90:
  lwz r0, 0x18(r1);
  oris r0, r0, 8;
  stw r0, 0x18(r1);
  lfd f1, 0x18(r1);
  b lbl_8000e414;
lbl_8000dda4:
  lhz r0, 4(r3);
  addi r4, r1, 0x101;
  sth r0, 0x100(r1);
  lhz r19, 0(r3);
  lbz r0, 0x100(r1);
  lhz r20, 2(r3);
  add r28, r4, r0;
  lhz r31, 6(r3);
  lhz r30, 8(r3);
  cmplw cr1, r4, r28;
  lhz r29, 0xa(r3);
  lhz r26, 0xc(r3);
  lhz r25, 0xe(r3);
  lhz r24, 0x10(r3);
  lhz r23, 0x12(r3);
  lhz r22, 0x14(r3);
  lhz r21, 0x16(r3);
  lhz r12, 0x18(r3);
  lhz r11, 0x1a(r3);
  lhz r10, 0x1c(r3);
  lhz r9, 0x1e(r3);
  lhz r8, 0x20(r3);
  lhz r7, 0x22(r3);
  lhz r6, 0x24(r3);
  lhz r5, 0x26(r3);
  lhz r0, 0x28(r3);
  sth r19, 0xfc(r1);
  sth r20, 0xfe(r1);
  sth r31, 0x102(r1);
  sth r30, 0x104(r1);
  sth r29, 0x106(r1);
  sth r26, 0x108(r1);
  sth r25, 0x10a(r1);
  sth r24, 0x10c(r1);
  sth r23, 0x10e(r1);
  sth r22, 0x110(r1);
  sth r21, 0x112(r1);
  sth r12, 0x114(r1);
  sth r11, 0x116(r1);
  sth r10, 0x118(r1);
  sth r9, 0x11a(r1);
  sth r8, 0x11c(r1);
  sth r7, 0x11e(r1);
  sth r6, 0x120(r1);
  sth r5, 0x122(r1);
  sth r0, 0x124(r1);
  bge cr1, lbl_8000df18;
  subf r0, r4, r28;
  addi r3, r28, -8;
  cmpwi r0, 8;
  ble lbl_8000def4;
  bgt cr1, lbl_8000def4;
  addi r0, r3, 7;
  subf r0, r4, r0;
  srwi r0, r0, 3;
  mtctr r0;
  cmplw r4, r3;
  bge lbl_8000def4;
lbl_8000de8c:
  lbz r3, 0(r4);
  addi r0, r3, -48;
  stb r0, 0(r4);
  lbz r3, 1(r4);
  addi r0, r3, -48;
  stb r0, 1(r4);
  lbz r3, 2(r4);
  addi r0, r3, -48;
  stb r0, 2(r4);
  lbz r3, 3(r4);
  addi r0, r3, -48;
  stb r0, 3(r4);
  lbz r3, 4(r4);
  addi r0, r3, -48;
  stb r0, 4(r4);
  lbz r3, 5(r4);
  addi r0, r3, -48;
  stb r0, 5(r4);
  lbz r3, 6(r4);
  addi r0, r3, -48;
  stb r0, 6(r4);
  lbz r3, 7(r4);
  addi r0, r3, -48;
  stb r0, 7(r4);
  addi r4, r4, 8;
  bdnz lbl_8000de8c;
lbl_8000def4:
  subf r0, r4, r28;
  mtctr r0;
  cmplw r4, r28;
  bge lbl_8000df18;
lbl_8000df04:
  lbz r3, 0(r4);
  addi r0, r3, -48;
  stb r0, 0(r4);
  addi r4, r4, 1;
  bdnz lbl_8000df04;
lbl_8000df18:
  lha r6, 0xfe(r1);
  lis r4, 0x8024;
  lbz r0, 0x100(r1);
  addi r4, r4, 0x6040;
  addi r3, r1, 0xd0;
  li r5, 0x134;
  add r6, r0, r6;
  addi r4, r4, 0xb8;
  addi r0, r6, -1;
  sth r0, 0xfe(r1);
  extsh r29, r0;
  bl __str2dec;
  addi r3, r1, 0xd0;
  addi r4, r1, 0xfc;
  bl __less_dec;
  cmpwi r3, 0;
  beq lbl_8000df84;
  lbz r0, 0(r27);
  extsb. r0, r0;
  bne lbl_8000df70;
  lfd f2, 1.0;
  b lbl_8000df74;
lbl_8000df70:
  lfd f2, -1.0;
lbl_8000df74:
  lis r3, 0x8038;
  lfs f1, 0x4c24(r3);
  bl copysign;
  b lbl_8000e414;
lbl_8000df84:
  lbz r0, 0x101(r1);
  lis r7, 0x8027;
  stw r0, 0x12c(r1);
  addi r4, r1, 0x102;
  lfd f2, -0x7f48(r2);
  addi r7, r7, 0xf58;
  lfd f0, 0x128(r1);
  lis r3, 0x8000;
  fsub f31, f0, f2;
  b lbl_8000e0e8;
lbl_8000dfac:
  subf r5, r4, r28;
  li r10, 0;
  slwi r0, r5, 0x1d;
  srwi r5, r5, 0x1f;
  subf r0, r5, r0;
  rotlwi r0, r0, 3;
  add. r6, r0, r5;
  bne lbl_8000dfd0;
  li r6, 8;
lbl_8000dfd0:
  cmpwi cr1, r6, 0;
  li r5, 0;
  ble cr1, lbl_8000e0b0;
  cmpwi r6, 8;
  addi r8, r6, -8;
  ble lbl_8000e088;
  li r9, 0;
  blt cr1, lbl_8000e000;
  addi r0, r3, -2;
  cmpw r6, r0;
  bgt lbl_8000e000;
  li r9, 1;
lbl_8000e000:
  cmpwi r9, 0;
  beq lbl_8000e088;
  addi r0, r8, 7;
  srwi r0, r0, 3;
  mtctr r0;
  cmpwi r8, 0;
  ble lbl_8000e088;
lbl_8000e01c:
  mulli r0, r10, 0xa;
  lbz r9, 0(r4);
  lbz r8, 1(r4);
  addi r5, r5, 8;
  lbz r21, 2(r4);
  add r0, r9, r0;
  mulli r0, r0, 0xa;
  lbz r12, 3(r4);
  lbz r11, 4(r4);
  lbz r10, 5(r4);
  add r0, r8, r0;
  lbz r9, 6(r4);
  mulli r0, r0, 0xa;
  lbz r8, 7(r4);
  addi r4, r4, 8;
  add r0, r21, r0;
  mulli r0, r0, 0xa;
  add r0, r12, r0;
  mulli r0, r0, 0xa;
  add r0, r11, r0;
  mulli r0, r0, 0xa;
  add r0, r10, r0;
  mulli r0, r0, 0xa;
  add r0, r9, r0;
  mulli r0, r0, 0xa;
  add r10, r8, r0;
  bdnz lbl_8000e01c;
lbl_8000e088:
  subf r0, r5, r6;
  mtctr r0;
  cmpw r5, r6;
  bge lbl_8000e0b0;
lbl_8000e098:
  mulli r0, r10, 0xa;
  lbz r8, 0(r4);
  addi r5, r5, 1;
  addi r4, r4, 1;
  add r10, r8, r0;
  bdnz lbl_8000e098;
lbl_8000e0b0:
  slwi r0, r6, 3;
  stw r10, 0x134(r1);
  add r5, r7, r0;
  cmpwi r10, 0;
  lfd f1, -8(r5);
  lfd f0, 0x130(r1);
  fmul f1, f31, f1;
  fsub f0, f0, f2;
  fadd f0, f1, f0;
  beq lbl_8000e0e0;
  fcmpu cr0, f1, f0;
  beq lbl_8000e0f0;
lbl_8000e0e0:
  fmr f31, f0;
  subf r29, r6, r29;
lbl_8000e0e8:
  cmplw r4, r28;
  blt lbl_8000dfac;
lbl_8000e0f0:
  cmpwi r29, 0;
  bge lbl_8000e120;
  neg r0, r29;
  lfd f2, -0x7f40(r2);
  xoris r0, r0, 0x8000;
  stw r0, 0x12c(r1);
  lfd f1, 5.0;
  lfd f0, 0x128(r1);
  fsub f2, f0, f2;
  bl pow;
  fdiv f31, f31, f1;
  b lbl_8000e140;
lbl_8000e120:
  xoris r0, r29, 0x8000;
  stw r0, 0x134(r1);
  lfd f2, -0x7f40(r2);
  lfd f0, 0x130(r1);
  lfd f1, 5.0;
  fsub f2, f0, f2;
  bl pow;
  fmul f31, f31, f1;
lbl_8000e140:
  fmr f1, f31;
  mr r3, r29;
  bl ldexp;
  fmr f31, f1;
  stfd f1, 0x10(r1);
  bl __fpclassifyd;
  cmpwi r3, 2;
  bne lbl_8000e168;
  lfd f31, -0x7f50(r2);
  stfd f31, 0x10(r1);
lbl_8000e168:
  fmr f1, f31;
  addi r3, r1, 0xa4;
  li r27, 0;
  bl __num2dec_internal;
  addi r3, r1, 0xa4;
  addi r4, r1, 0xfc;
  bl __equals_dec;
  cmpwi r3, 0;
  bne lbl_8000e400;
  addi r3, r1, 0xa4;
  addi r4, r1, 0xfc;
  bl __less_dec;
  cmpwi r3, 0;
  beq lbl_8000e1a4;
  li r27, 1;
lbl_8000e1a4:
  cntlzw r0, r27;
  stfd f31, 8(r1);
  srwi r28, r0, 5;
  li r29, 1;
  li r30, 0;
  li r31, -1;
lbl_8000e1bc:
  cmpwi r28, 0;
  bne lbl_8000e1f0;
  lwz r0, 0xc(r1);
  lwz r3, 8(r1);
  addc r0, r0, r29;
  stw r0, 0xc(r1);
  adde r0, r3, r30;
  stw r0, 8(r1);
  lfd f1, 8(r1);
  bl __fpclassifyd;
  cmpwi r3, 2;
  beq lbl_8000e400;
  b lbl_8000e208;
lbl_8000e1f0:
  lwz r0, 0xc(r1);
  lwz r3, 8(r1);
  addc r0, r0, r31;
  stw r0, 0xc(r1);
  adde r0, r3, r31;
  stw r0, 8(r1);
lbl_8000e208:
  lfd f1, 8(r1);
  addi r3, r1, 0x78;
  bl __num2dec_internal;
  cmpwi r27, 0;
  beq lbl_8000e230;
  addi r3, r1, 0x78;
  addi r4, r1, 0xfc;
  bl __less_dec;
  cmpwi r3, 0;
  beq lbl_8000e3a0;
lbl_8000e230:
  cmpwi r27, 0;
  bne lbl_8000e33c;
  addi r3, r1, 0xfc;
  addi r4, r1, 0x78;
  bl __less_dec;
  cmpwi r3, 0;
  bne lbl_8000e33c;
  fmr f0, f31;
  lfd f31, 8(r1);
  lwz r21, 0xa4(r1);
  lwz r12, 0x78(r1);
  lwz r22, 0xa8(r1);
  lwz r11, 0x7c(r1);
  lwz r23, 0xac(r1);
  lwz r10, 0x80(r1);
  lwz r24, 0xb0(r1);
  lwz r9, 0x84(r1);
  lwz r25, 0xb4(r1);
  lwz r8, 0x88(r1);
  lwz r26, 0xb8(r1);
  lwz r7, 0x8c(r1);
  lwz r31, 0xbc(r1);
  lwz r6, 0x90(r1);
  lwz r30, 0xc0(r1);
  lwz r5, 0x94(r1);
  lwz r29, 0xc4(r1);
  lwz r4, 0x98(r1);
  lwz r28, 0xc8(r1);
  lwz r3, 0x9c(r1);
  lhz r27, 0xcc(r1);
  lhz r0, 0xa0(r1);
  stw r21, 0x4c(r1);
  stw r22, 0x50(r1);
  stw r23, 0x54(r1);
  stw r24, 0x58(r1);
  stw r25, 0x5c(r1);
  stw r26, 0x60(r1);
  stw r31, 0x64(r1);
  stw r30, 0x68(r1);
  stw r29, 0x6c(r1);
  stw r28, 0x70(r1);
  sth r27, 0x74(r1);
  stw r12, 0xa4(r1);
  stw r11, 0xa8(r1);
  stw r10, 0xac(r1);
  stw r9, 0xb0(r1);
  stw r8, 0xb4(r1);
  stw r7, 0xb8(r1);
  stw r6, 0xbc(r1);
  stw r5, 0xc0(r1);
  stw r4, 0xc4(r1);
  stw r3, 0xc8(r1);
  sth r0, 0xcc(r1);
  stw r21, 0x78(r1);
  stw r22, 0x7c(r1);
  stw r23, 0x80(r1);
  stw r24, 0x84(r1);
  stw r25, 0x88(r1);
  stw r26, 0x8c(r1);
  stw r31, 0x90(r1);
  stw r30, 0x94(r1);
  stw r29, 0x98(r1);
  stw r28, 0x9c(r1);
  sth r27, 0xa0(r1);
  stfd f31, 0x10(r1);
  stfd f0, 8(r1);
  b lbl_8000e3a0;
lbl_8000e33c:
  lwz r12, 0x78(r1);
  lwz r11, 0x7c(r1);
  lwz r10, 0x80(r1);
  lwz r9, 0x84(r1);
  lwz r8, 0x88(r1);
  lwz r7, 0x8c(r1);
  lwz r6, 0x90(r1);
  lwz r5, 0x94(r1);
  lwz r4, 0x98(r1);
  lwz r3, 0x9c(r1);
  lhz r0, 0xa0(r1);
  lfd f31, 8(r1);
  stw r12, 0xa4(r1);
  stw r11, 0xa8(r1);
  stw r10, 0xac(r1);
  stw r9, 0xb0(r1);
  stw r8, 0xb4(r1);
  stw r7, 0xb8(r1);
  stw r6, 0xbc(r1);
  stw r5, 0xc0(r1);
  stw r4, 0xc4(r1);
  stw r3, 0xc8(r1);
  sth r0, 0xcc(r1);
  stfd f31, 0x10(r1);
  b lbl_8000e1bc;
lbl_8000e3a0:
  addi r3, r1, 0x4c;
  addi r4, r1, 0xfc;
  addi r5, r1, 0xa4;
  bl __minus_dec;
  addi r3, r1, 0x20;
  addi r4, r1, 0x78;
  addi r5, r1, 0xfc;
  bl __minus_dec;
  addi r3, r1, 0x4c;
  addi r4, r1, 0x20;
  bl __equals_dec;
  cmpwi r3, 0;
  beq lbl_8000e3e8;
  lwz r0, 0x14(r1);
  clrlwi. r0, r0, 0x1f;
  beq lbl_8000e400;
  lfd f31, 8(r1);
  b lbl_8000e400;
lbl_8000e3e8:
  addi r3, r1, 0x4c;
  addi r4, r1, 0x20;
  bl __less_dec;
  cmpwi r3, 0;
  bne lbl_8000e400;
  lfd f31, 8(r1);
lbl_8000e400:
  lbz r0, 0xfc(r1);
  extsb. r0, r0;
  beq lbl_8000e410;
  fneg f31, f31;
lbl_8000e410:
  fmr f1, f31;
lbl_8000e414:
  psq_l f31, 376(r1), 0, 0;
  // clang-format on
}

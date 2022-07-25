#include "gxAttr.h"

#include "gx.h"

// Symbol: GXSetVtxDesc
// PAL: 0x8016d3a4..0x8016d608
MARK_BINARY_BLOB(GXSetVtxDesc, 0x8016d3a4, 0x8016d608);
asm void GXSetVtxDesc(GXAttr, int) {
  // clang-format off
  nofralloc;
  cmplwi r3, 0x19;
  bgt lbl_8016d5b8;
  lis r5, 0x8029;
  slwi r0, r3, 2;
  addi r5, r5, -24624;
  lwzx r5, r5, r0;
  mtctr r5;
  bctr;
  lwz r3, gx;
  lwz r0, 0x14(r3);
  rlwimi r0, r4, 0, 0x1f, 0x1f;
  stw r0, 0x14(r3);
  b lbl_8016d5b8;
  lwz r3, gx;
  lwz r0, 0x14(r3);
  rlwimi r0, r4, 1, 0x1e, 0x1e;
  stw r0, 0x14(r3);
  b lbl_8016d5b8;
  lwz r3, gx;
  lwz r0, 0x14(r3);
  rlwimi r0, r4, 2, 0x1d, 0x1d;
  stw r0, 0x14(r3);
  b lbl_8016d5b8;
  lwz r3, gx;
  lwz r0, 0x14(r3);
  rlwimi r0, r4, 3, 0x1c, 0x1c;
  stw r0, 0x14(r3);
  b lbl_8016d5b8;
  lwz r3, gx;
  lwz r0, 0x14(r3);
  rlwimi r0, r4, 4, 0x1b, 0x1b;
  stw r0, 0x14(r3);
  b lbl_8016d5b8;
  lwz r3, gx;
  lwz r0, 0x14(r3);
  rlwimi r0, r4, 5, 0x1a, 0x1a;
  stw r0, 0x14(r3);
  b lbl_8016d5b8;
  lwz r3, gx;
  lwz r0, 0x14(r3);
  rlwimi r0, r4, 6, 0x19, 0x19;
  stw r0, 0x14(r3);
  b lbl_8016d5b8;
  lwz r3, gx;
  lwz r0, 0x14(r3);
  rlwimi r0, r4, 7, 0x18, 0x18;
  stw r0, 0x14(r3);
  b lbl_8016d5b8;
  lwz r3, gx;
  lwz r0, 0x14(r3);
  rlwimi r0, r4, 8, 0x17, 0x17;
  stw r0, 0x14(r3);
  b lbl_8016d5b8;
  lwz r3, gx;
  lwz r0, 0x14(r3);
  rlwimi r0, r4, 9, 0x15, 0x16;
  stw r0, 0x14(r3);
  b lbl_8016d5b8;
  cmpwi r4, 0;
  beq lbl_8016d4b0;
  lwz r5, gx;
  li r3, 1;
  li r0, 0;
  stb r3, 0x524(r5);
  stb r0, 0x525(r5);
  stw r4, 0x520(r5);
  b lbl_8016d5b8;
lbl_8016d4b0:
  lwz r3, gx;
  li r0, 0;
  stb r0, 0x524(r3);
  b lbl_8016d5b8;
  cmpwi r4, 0;
  beq lbl_8016d4e4;
  lwz r5, gx;
  li r3, 1;
  li r0, 0;
  stb r3, 0x525(r5);
  stb r0, 0x524(r5);
  stw r4, 0x520(r5);
  b lbl_8016d5b8;
lbl_8016d4e4:
  lwz r3, gx;
  li r0, 0;
  stb r0, 0x525(r3);
  b lbl_8016d5b8;
  lwz r3, gx;
  lwz r0, 0x14(r3);
  rlwimi r0, r4, 0xd, 0x11, 0x12;
  stw r0, 0x14(r3);
  b lbl_8016d5b8;
  lwz r3, gx;
  lwz r0, 0x14(r3);
  rlwimi r0, r4, 0xf, 0xf, 0x10;
  stw r0, 0x14(r3);
  b lbl_8016d5b8;
  lwz r3, gx;
  lwz r0, 0x18(r3);
  rlwimi r0, r4, 0, 0x1e, 0x1f;
  stw r0, 0x18(r3);
  b lbl_8016d5b8;
  lwz r3, gx;
  lwz r0, 0x18(r3);
  rlwimi r0, r4, 2, 0x1c, 0x1d;
  stw r0, 0x18(r3);
  b lbl_8016d5b8;
  lwz r3, gx;
  lwz r0, 0x18(r3);
  rlwimi r0, r4, 4, 0x1a, 0x1b;
  stw r0, 0x18(r3);
  b lbl_8016d5b8;
  lwz r3, gx;
  lwz r0, 0x18(r3);
  rlwimi r0, r4, 6, 0x18, 0x19;
  stw r0, 0x18(r3);
  b lbl_8016d5b8;
  lwz r3, gx;
  lwz r0, 0x18(r3);
  rlwimi r0, r4, 8, 0x16, 0x17;
  stw r0, 0x18(r3);
  b lbl_8016d5b8;
  lwz r3, gx;
  lwz r0, 0x18(r3);
  rlwimi r0, r4, 0xa, 0x14, 0x15;
  stw r0, 0x18(r3);
  b lbl_8016d5b8;
  lwz r3, gx;
  lwz r0, 0x18(r3);
  rlwimi r0, r4, 0xc, 0x12, 0x13;
  stw r0, 0x18(r3);
  b lbl_8016d5b8;
  lwz r3, gx;
  lwz r0, 0x18(r3);
  rlwimi r0, r4, 0xe, 0x10, 0x11;
  stw r0, 0x18(r3);
lbl_8016d5b8:
  lwz r4, gx;
  lbz r0, 0x524(r4);
  cmpwi r0, 0;
  bne lbl_8016d5d4;
  lbz r0, 0x525(r4);
  cmpwi r0, 0;
  beq lbl_8016d5ec;
lbl_8016d5d4:
  lwz r5, gx;
  lwz r0, 0x520(r5);
  lwz r3, 0x14(r5);
  rlwimi r3, r0, 0xb, 0x13, 0x14;
  stw r3, 0x14(r5);
  b lbl_8016d5f8;
lbl_8016d5ec:
  lwz r0, 0x14(r4);
  rlwinm r0, r0, 0, 0x15, 0x12;
  stw r0, 0x14(r4);
lbl_8016d5f8:
  lwz r0, 0x5fc(r4);
  ori r0, r0, 8;
  stw r0, 0x5fc(r4);
  blr;
  // clang-format on
}

// Symbol: GXSetVtxDescv
// PAL: 0x8016d608..0x8016d814
MARK_BINARY_BLOB(GXSetVtxDescv, 0x8016d608, 0x8016d814);
asm UNKNOWN_FUNCTION(GXSetVtxDescv) {
  // clang-format off
  nofralloc;
  lwz r5, gx;
  li r7, 0;
  li r8, 1;
  lis r4, 0x8029;
  b lbl_8016d7c0;
lbl_8016d61c:
  lwz r6, 0(r3);
  lwz r0, 4(r3);
  cmplwi r6, 0x19;
  bgt lbl_8016d7bc;
  addi r9, r4, -24520;
  slwi r6, r6, 2;
  lwzx r9, r9, r6;
  mtctr r9;
  bctr;
  lwz r6, 0x14(r5);
  rlwimi r6, r0, 0, 0x1f, 0x1f;
  stw r6, 0x14(r5);
  b lbl_8016d7bc;
  lwz r6, 0x14(r5);
  rlwimi r6, r0, 1, 0x1e, 0x1e;
  stw r6, 0x14(r5);
  b lbl_8016d7bc;
  lwz r6, 0x14(r5);
  rlwimi r6, r0, 2, 0x1d, 0x1d;
  stw r6, 0x14(r5);
  b lbl_8016d7bc;
  lwz r6, 0x14(r5);
  rlwimi r6, r0, 3, 0x1c, 0x1c;
  stw r6, 0x14(r5);
  b lbl_8016d7bc;
  lwz r6, 0x14(r5);
  rlwimi r6, r0, 4, 0x1b, 0x1b;
  stw r6, 0x14(r5);
  b lbl_8016d7bc;
  lwz r6, 0x14(r5);
  rlwimi r6, r0, 5, 0x1a, 0x1a;
  stw r6, 0x14(r5);
  b lbl_8016d7bc;
  lwz r6, 0x14(r5);
  rlwimi r6, r0, 6, 0x19, 0x19;
  stw r6, 0x14(r5);
  b lbl_8016d7bc;
  lwz r6, 0x14(r5);
  rlwimi r6, r0, 7, 0x18, 0x18;
  stw r6, 0x14(r5);
  b lbl_8016d7bc;
  lwz r6, 0x14(r5);
  rlwimi r6, r0, 8, 0x17, 0x17;
  stw r6, 0x14(r5);
  b lbl_8016d7bc;
  lwz r6, 0x14(r5);
  rlwimi r6, r0, 9, 0x15, 0x16;
  stw r6, 0x14(r5);
  b lbl_8016d7bc;
  cmpwi r0, 0;
  beq lbl_8016d6f8;
  stb r8, 0x524(r5);
  stb r7, 0x525(r5);
  stw r0, 0x520(r5);
  b lbl_8016d7bc;
lbl_8016d6f8:
  stb r7, 0x524(r5);
  b lbl_8016d7bc;
  cmpwi r0, 0;
  beq lbl_8016d718;
  stb r8, 0x525(r5);
  stb r7, 0x524(r5);
  stw r0, 0x520(r5);
  b lbl_8016d7bc;
lbl_8016d718:
  stb r7, 0x525(r5);
  b lbl_8016d7bc;
  lwz r6, 0x14(r5);
  rlwimi r6, r0, 0xd, 0x11, 0x12;
  stw r6, 0x14(r5);
  b lbl_8016d7bc;
  lwz r6, 0x14(r5);
  rlwimi r6, r0, 0xf, 0xf, 0x10;
  stw r6, 0x14(r5);
  b lbl_8016d7bc;
  lwz r6, 0x18(r5);
  rlwimi r6, r0, 0, 0x1e, 0x1f;
  stw r6, 0x18(r5);
  b lbl_8016d7bc;
  lwz r6, 0x18(r5);
  rlwimi r6, r0, 2, 0x1c, 0x1d;
  stw r6, 0x18(r5);
  b lbl_8016d7bc;
  lwz r6, 0x18(r5);
  rlwimi r6, r0, 4, 0x1a, 0x1b;
  stw r6, 0x18(r5);
  b lbl_8016d7bc;
  lwz r6, 0x18(r5);
  rlwimi r6, r0, 6, 0x18, 0x19;
  stw r6, 0x18(r5);
  b lbl_8016d7bc;
  lwz r6, 0x18(r5);
  rlwimi r6, r0, 8, 0x16, 0x17;
  stw r6, 0x18(r5);
  b lbl_8016d7bc;
  lwz r6, 0x18(r5);
  rlwimi r6, r0, 0xa, 0x14, 0x15;
  stw r6, 0x18(r5);
  b lbl_8016d7bc;
  lwz r6, 0x18(r5);
  rlwimi r6, r0, 0xc, 0x12, 0x13;
  stw r6, 0x18(r5);
  b lbl_8016d7bc;
  lwz r6, 0x18(r5);
  rlwimi r6, r0, 0xe, 0x10, 0x11;
  stw r6, 0x18(r5);
lbl_8016d7bc:
  addi r3, r3, 8;
lbl_8016d7c0:
  lwz r0, 0(r3);
  cmpwi r0, 0xff;
  bne lbl_8016d61c;
  lbz r0, 0x524(r5);
  cmpwi r0, 0;
  bne lbl_8016d7e4;
  lbz r0, 0x525(r5);
  cmpwi r0, 0;
  beq lbl_8016d7f8;
lbl_8016d7e4:
  lwz r0, 0x520(r5);
  lwz r3, 0x14(r5);
  rlwimi r3, r0, 0xb, 0x13, 0x14;
  stw r3, 0x14(r5);
  b lbl_8016d804;
lbl_8016d7f8:
  lwz r0, 0x14(r5);
  rlwinm r0, r0, 0, 0x15, 0x12;
  stw r0, 0x14(r5);
lbl_8016d804:
  lwz r0, 0x5fc(r5);
  ori r0, r0, 8;
  stw r0, 0x5fc(r5);
  blr;
  // clang-format on
}

// Symbol: __GXSetVCD
// PAL: 0x8016d814..0x8016d8c4
MARK_BINARY_BLOB(__GXSetVCD, 0x8016d814, 0x8016d8c4);
asm UNKNOWN_FUNCTION(__GXSetVCD) {
  // clang-format off
  nofralloc;
  lis r5, 0xcc01;
  li r6, 8;
  stb r6, -0x8000(r5);
  li r4, 0x50;
  lwz r3, gx;
  li r0, 0x60;
  stb r4, -0x8000(r5);
  lwz r4, 0x14(r3);
  stw r4, -0x8000(r5);
  stb r6, -0x8000(r5);
  stb r0, -0x8000(r5);
  lwz r0, 0x18(r3);
  stw r0, -0x8000(r5);
  lbz r0, 0x525(r3);
  cmpwi r0, 0;
  beq lbl_8016d85c;
  li r8, 2;
  b lbl_8016d86c;
lbl_8016d85c:
  lbz r4, 0x524(r3);
  neg r0, r4;
  or r0, r0, r4;
  srwi r8, r0, 0x1f;
lbl_8016d86c:
  lwz r5, 0x14(r3);
  lis r6, 0xcc01;
  lwz r4, 0x18(r3);
  li r0, 0x10;
  rlwinm r7, r5, 0x13, 0x1c, 0x1f;
  li r5, 0x1008;
  cntlzw r7, r7;
  clrlwi r4, r4, 0x10;
  stb r0, -0x8000(r6);
  subfic r7, r7, 0x21;
  cntlzw r0, r4;
  slwi r4, r8, 2;
  subfic r0, r0, 0x21;
  srwi r7, r7, 1;
  rlwinm r0, r0, 3, 0, 0x1b;
  stw r5, -0x8000(r6);
  or r5, r0, r7;
  or r4, r5, r4;
  li r0, 1;
  stw r4, -0x8000(r6);
  sth r0, 2(r3);
  blr;
  // clang-format on
}

// Symbol: __GXCalculateVLim
// PAL: 0x8016d8c4..0x8016d9f0
MARK_BINARY_BLOB(__GXCalculateVLim, 0x8016d8c4, 0x8016d9f0);
asm UNKNOWN_FUNCTION(__GXCalculateVLim) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  lwz r3, gx;
  stw r31, 0xc(r1);
  lhz r0, 4(r3);
  cmpwi r0, 0;
  beq lbl_8016d9e4;
  lwz r9, 0x14(r3);
  addi r7, r13, -29376;
  lwz r5, 0x1c(r3);
  clrlwi r0, r9, 0x1f;
  rlwinm r4, r9, 0x1f, 0x1f, 0x1f;
  add r0, r0, r4;
  rlwinm r8, r5, 0x17, 0x1f, 0x1f;
  rlwinm r4, r9, 0x1e, 0x1f, 0x1f;
  rlwinm r5, r9, 0x15, 0x1e, 0x1f;
  add r0, r0, r4;
  cmpwi r8, 1;
  rlwinm r4, r9, 0x1d, 0x1f, 0x1f;
  rlwinm r6, r9, 0x1a, 0x1f, 0x1f;
  add r0, r0, r4;
  rlwinm r8, r9, 0x18, 0x1f, 0x1f;
  rlwinm r4, r9, 0x1c, 0x1f, 0x1f;
  lwz r31, 0x18(r3);
  add r0, r0, r4;
  lbzx r5, r7, r5;
  rlwinm r4, r9, 0x1b, 0x1f, 0x1f;
  add r0, r0, r4;
  add r0, r0, r6;
  rlwinm r6, r9, 0x19, 0x1f, 0x1f;
  add r0, r0, r6;
  rlwinm r4, r9, 0x17, 0x1e, 0x1f;
  lbzx r6, r7, r4;
  add r0, r0, r8;
  li r4, 1;
  add r0, r0, r6;
  bne lbl_8016d958;
  li r4, 3;
lbl_8016d958:
  mullw r8, r5, r4;
  addi r7, r13, -29384;
  rlwinm r4, r9, 0x13, 0x1e, 0x1f;
  rlwinm r5, r9, 0x11, 0x1e, 0x1f;
  lbzx r6, r7, r4;
  lbzx r5, r7, r5;
  add r0, r0, r8;
  addi r12, r13, -29380;
  add r0, r0, r6;
  clrlwi r4, r31, 0x1e;
  rlwinm r10, r31, 0x1e, 0x1e, 0x1f;
  lbzx r11, r12, r4;
  add r0, r0, r5;
  rlwinm r9, r31, 0x1c, 0x1e, 0x1f;
  rlwinm r8, r31, 0x1a, 0x1e, 0x1f;
  rlwinm r7, r31, 0x18, 0x1e, 0x1f;
  rlwinm r6, r31, 0x16, 0x1e, 0x1f;
  rlwinm r5, r31, 0x14, 0x1e, 0x1f;
  rlwinm r4, r31, 0x12, 0x1e, 0x1f;
  lbzx r10, r12, r10;
  add r0, r0, r11;
  lbzx r9, r12, r9;
  add r0, r0, r10;
  lbzx r8, r12, r8;
  add r0, r0, r9;
  lbzx r7, r12, r7;
  add r0, r0, r8;
  lbzx r6, r12, r6;
  add r0, r0, r7;
  lbzx r5, r12, r5;
  add r0, r0, r6;
  lbzx r4, r12, r4;
  add r0, r0, r5;
  add r0, r0, r4;
  sth r0, 6(r3);
lbl_8016d9e4:
  lwz r31, 0xc(r1);
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: GXGetVtxDesc
// PAL: 0x8016d9f0..0x8016dba4
MARK_BINARY_BLOB(GXGetVtxDesc, 0x8016d9f0, 0x8016dba4);
asm UNKNOWN_FUNCTION(GXGetVtxDesc) {
  // clang-format off
  nofralloc;
  cmplwi r3, 0x19;
  bgt lbl_8016db98;
  lis r5, 0x8029;
  slwi r0, r3, 2;
  addi r5, r5, -24416;
  lwzx r5, r5, r0;
  mtctr r5;
  bctr;
  lwz r3, gx;
  lwz r0, 0x14(r3);
  clrlwi r0, r0, 0x1f;
  b lbl_8016db9c;
  lwz r3, gx;
  lwz r0, 0x14(r3);
  rlwinm r0, r0, 0x1f, 0x1f, 0x1f;
  b lbl_8016db9c;
  lwz r3, gx;
  lwz r0, 0x14(r3);
  rlwinm r0, r0, 0x1e, 0x1f, 0x1f;
  b lbl_8016db9c;
  lwz r3, gx;
  lwz r0, 0x14(r3);
  rlwinm r0, r0, 0x1d, 0x1f, 0x1f;
  b lbl_8016db9c;
  lwz r3, gx;
  lwz r0, 0x14(r3);
  rlwinm r0, r0, 0x1c, 0x1f, 0x1f;
  b lbl_8016db9c;
  lwz r3, gx;
  lwz r0, 0x14(r3);
  rlwinm r0, r0, 0x1b, 0x1f, 0x1f;
  b lbl_8016db9c;
  lwz r3, gx;
  lwz r0, 0x14(r3);
  rlwinm r0, r0, 0x1a, 0x1f, 0x1f;
  b lbl_8016db9c;
  lwz r3, gx;
  lwz r0, 0x14(r3);
  rlwinm r0, r0, 0x19, 0x1f, 0x1f;
  b lbl_8016db9c;
  lwz r3, gx;
  lwz r0, 0x14(r3);
  rlwinm r0, r0, 0x18, 0x1f, 0x1f;
  b lbl_8016db9c;
  lwz r3, gx;
  lwz r0, 0x14(r3);
  rlwinm r0, r0, 0x17, 0x1e, 0x1f;
  b lbl_8016db9c;
  lwz r3, gx;
  lbz r0, 0x524(r3);
  cmpwi r0, 0;
  beq lbl_8016dacc;
  lwz r0, 0x14(r3);
  rlwinm r0, r0, 0x15, 0x1e, 0x1f;
  b lbl_8016db9c;
lbl_8016dacc:
  li r0, 0;
  b lbl_8016db9c;
  lwz r3, gx;
  lbz r0, 0x525(r3);
  cmpwi r0, 0;
  beq lbl_8016daf0;
  lwz r0, 0x14(r3);
  rlwinm r0, r0, 0x15, 0x1e, 0x1f;
  b lbl_8016db9c;
lbl_8016daf0:
  li r0, 0;
  b lbl_8016db9c;
  lwz r3, gx;
  lwz r0, 0x14(r3);
  rlwinm r0, r0, 0x13, 0x1e, 0x1f;
  b lbl_8016db9c;
  lwz r3, gx;
  lwz r0, 0x14(r3);
  rlwinm r0, r0, 0x11, 0x1e, 0x1f;
  b lbl_8016db9c;
  lwz r3, gx;
  lwz r0, 0x18(r3);
  clrlwi r0, r0, 0x1e;
  b lbl_8016db9c;
  lwz r3, gx;
  lwz r0, 0x18(r3);
  rlwinm r0, r0, 0x1e, 0x1e, 0x1f;
  b lbl_8016db9c;
  lwz r3, gx;
  lwz r0, 0x18(r3);
  rlwinm r0, r0, 0x1c, 0x1e, 0x1f;
  b lbl_8016db9c;
  lwz r3, gx;
  lwz r0, 0x18(r3);
  rlwinm r0, r0, 0x1a, 0x1e, 0x1f;
  b lbl_8016db9c;
  lwz r3, gx;
  lwz r0, 0x18(r3);
  rlwinm r0, r0, 0x18, 0x1e, 0x1f;
  b lbl_8016db9c;
  lwz r3, gx;
  lwz r0, 0x18(r3);
  rlwinm r0, r0, 0x16, 0x1e, 0x1f;
  b lbl_8016db9c;
  lwz r3, gx;
  lwz r0, 0x18(r3);
  rlwinm r0, r0, 0x14, 0x1e, 0x1f;
  b lbl_8016db9c;
  lwz r3, gx;
  lwz r0, 0x18(r3);
  rlwinm r0, r0, 0x12, 0x1e, 0x1f;
  b lbl_8016db9c;
lbl_8016db98:
  li r0, 0;
lbl_8016db9c:
  stw r0, 0(r4);
  blr;
  // clang-format on
}

// Symbol: GXGetVtxDescv
// PAL: 0x8016dba4..0x8016dc34
MARK_BINARY_BLOB(GXGetVtxDescv, 0x8016dba4, 0x8016dc34);
asm UNKNOWN_FUNCTION(GXGetVtxDescv) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  li r31, 0;
  stw r30, 0x18(r1);
  li r30, 0;
  stw r29, 0x14(r1);
  mr r29, r3;
lbl_8016dbc8:
  add r4, r29, r31;
  stwx r30, r29, r31;
  mr r3, r30;
  addi r4, r4, 4;
  bl GXGetVtxDesc;
  addi r30, r30, 1;
  addi r31, r31, 8;
  cmpwi r30, 0x14;
  ble lbl_8016dbc8;
  slwi r3, r30, 3;
  li r0, 0x19;
  add r4, r29, r3;
  stw r0, 0(r4);
  li r3, 0x19;
  addi r4, r4, 4;
  bl GXGetVtxDesc;
  addi r30, r30, 1;
  li r3, 0xff;
  slwi r0, r30, 3;
  stwx r3, r29, r0;
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: GXClearVtxDesc
// PAL: 0x8016dc34..0x8016dc68
MARK_BINARY_BLOB(GXClearVtxDesc, 0x8016dc34, 0x8016dc68);
asm void GXClearVtxDesc(void) {
  // clang-format off
  nofralloc;
  lwz r5, gx;
  li r0, 1;
  li r3, 0;
  li r4, 0;
  rlwimi r3, r0, 9, 0x15, 0x16;
  stw r3, 0x14(r5);
  stw r4, 0x18(r5);
  stb r4, 0x524(r5);
  stb r4, 0x525(r5);
  lwz r0, 0x5fc(r5);
  ori r0, r0, 8;
  stw r0, 0x5fc(r5);
  blr;
  // clang-format on
}

// Symbol: GXSetVtxAttrFmt
// PAL: 0x8016dc68..0x8016de08
MARK_BINARY_BLOB(GXSetVtxAttrFmt, 0x8016dc68, 0x8016de08);
asm void GXSetVtxAttrFmt(int, GXAttr, int, int, int) {
  // clang-format off
  nofralloc;
  addi r0, r4, -9;
  lwz r8, gx;
  cmplwi r0, 0x10;
  slwi r4, r3, 2;
  add r8, r8, r4;
  bgt lbl_8016ddd8;
  lis r4, 0x8029;
  slwi r0, r0, 2;
  addi r4, r4, -24312;
  lwzx r4, r4, r0;
  mtctr r4;
  bctr;
  lwz r0, 0x1c(r8);
  rlwimi r0, r5, 0, 0x1f, 0x1f;
  rlwimi r0, r6, 1, 0x1c, 0x1e;
  rlwimi r0, r7, 4, 0x17, 0x1b;
  stw r0, 0x1c(r8);
  b lbl_8016ddd8;
  lwz r0, 0x1c(r8);
  rlwimi r0, r6, 0xa, 0x13, 0x15;
  cmpwi r5, 2;
  stw r0, 0x1c(r8);
  bne lbl_8016dcd8;
  lwz r0, 0x1c(r8);
  ori r0, r0, 0x200;
  oris r0, r0, 0x8000;
  stw r0, 0x1c(r8);
  b lbl_8016ddd8;
lbl_8016dcd8:
  lwz r0, 0x1c(r8);
  rlwimi r0, r5, 9, 0x16, 0x16;
  clrlwi r0, r0, 1;
  stw r0, 0x1c(r8);
  b lbl_8016ddd8;
  lwz r0, 0x1c(r8);
  rlwimi r0, r5, 0xd, 0x12, 0x12;
  rlwimi r0, r6, 0xe, 0xf, 0x11;
  stw r0, 0x1c(r8);
  b lbl_8016ddd8;
  lwz r0, 0x1c(r8);
  rlwimi r0, r5, 0x11, 0xe, 0xe;
  rlwimi r0, r6, 0x12, 0xb, 0xd;
  stw r0, 0x1c(r8);
  b lbl_8016ddd8;
  lwz r0, 0x1c(r8);
  rlwimi r0, r5, 0x15, 0xa, 0xa;
  rlwimi r0, r6, 0x16, 7, 9;
  rlwimi r0, r7, 0x19, 2, 6;
  stw r0, 0x1c(r8);
  b lbl_8016ddd8;
  lwz r0, 0x3c(r8);
  rlwimi r0, r5, 0, 0x1f, 0x1f;
  rlwimi r0, r6, 1, 0x1c, 0x1e;
  rlwimi r0, r7, 4, 0x17, 0x1b;
  stw r0, 0x3c(r8);
  b lbl_8016ddd8;
  lwz r0, 0x3c(r8);
  rlwimi r0, r5, 9, 0x16, 0x16;
  rlwimi r0, r6, 0xa, 0x13, 0x15;
  rlwimi r0, r7, 0xd, 0xe, 0x12;
  stw r0, 0x3c(r8);
  b lbl_8016ddd8;
  lwz r0, 0x3c(r8);
  rlwimi r0, r5, 0x12, 0xd, 0xd;
  rlwimi r0, r6, 0x13, 0xa, 0xc;
  rlwimi r0, r7, 0x16, 5, 9;
  stw r0, 0x3c(r8);
  b lbl_8016ddd8;
  lwz r0, 0x3c(r8);
  rlwimi r0, r5, 0x1b, 4, 4;
  rlwimi r0, r6, 0x1c, 1, 3;
  stw r0, 0x3c(r8);
  lwz r0, 0x5c(r8);
  rlwimi r0, r7, 0, 0x1b, 0x1f;
  stw r0, 0x5c(r8);
  b lbl_8016ddd8;
  lwz r0, 0x5c(r8);
  rlwimi r0, r5, 5, 0x1a, 0x1a;
  rlwimi r0, r6, 6, 0x17, 0x19;
  rlwimi r0, r7, 9, 0x12, 0x16;
  stw r0, 0x5c(r8);
  b lbl_8016ddd8;
  lwz r0, 0x5c(r8);
  rlwimi r0, r5, 0xe, 0x11, 0x11;
  rlwimi r0, r6, 0xf, 0xe, 0x10;
  rlwimi r0, r7, 0x12, 9, 0xd;
  stw r0, 0x5c(r8);
  b lbl_8016ddd8;
  lwz r0, 0x5c(r8);
  rlwimi r0, r5, 0x17, 8, 8;
  rlwimi r0, r6, 0x18, 5, 7;
  rlwimi r0, r7, 0x1b, 0, 4;
  stw r0, 0x5c(r8);
lbl_8016ddd8:
  lwz r5, gx;
  clrlwi r0, r3, 0x18;
  li r3, 1;
  lwz r4, 0x5fc(r5);
  slw r0, r3, r0;
  clrlwi r0, r0, 0x18;
  ori r3, r4, 0x10;
  stw r3, 0x5fc(r5);
  lbz r3, 0x5fb(r5);
  or r0, r3, r0;
  stb r0, 0x5fb(r5);
  blr;
  // clang-format on
}

// Symbol: GXSetVtxAttrFmtv
// PAL: 0x8016de08..0x8016dfcc
MARK_BINARY_BLOB(GXSetVtxAttrFmtv, 0x8016de08, 0x8016dfcc);
asm UNKNOWN_FUNCTION(GXSetVtxAttrFmtv) {
  // clang-format off
  nofralloc;
  lwz r6, gx;
  slwi r0, r3, 2;
  lis r5, 0x8029;
  add r8, r6, r0;
  b lbl_8016df90;
lbl_8016de1c:
  lwz r6, 0(r4);
  lbz r7, 0xc(r4);
  addi r0, r6, -9;
  lwz r10, 8(r4);
  cmplwi r0, 0x10;
  lwz r9, 4(r4);
  bgt lbl_8016df8c;
  addi r6, r5, -24244;
  slwi r0, r0, 2;
  lwzx r6, r6, r0;
  mtctr r6;
  bctr;
  lwz r0, 0x1c(r8);
  rlwimi r0, r9, 0, 0x1f, 0x1f;
  rlwimi r0, r10, 1, 0x1c, 0x1e;
  rlwimi r0, r7, 4, 0x17, 0x1b;
  stw r0, 0x1c(r8);
  b lbl_8016df8c;
  lwz r0, 0x1c(r8);
  rlwimi r0, r10, 0xa, 0x13, 0x15;
  cmpwi r9, 2;
  stw r0, 0x1c(r8);
  bne lbl_8016de8c;
  lwz r0, 0x1c(r8);
  ori r0, r0, 0x200;
  oris r0, r0, 0x8000;
  stw r0, 0x1c(r8);
  b lbl_8016df8c;
lbl_8016de8c:
  lwz r0, 0x1c(r8);
  rlwimi r0, r9, 9, 0x16, 0x16;
  clrlwi r0, r0, 1;
  stw r0, 0x1c(r8);
  b lbl_8016df8c;
  lwz r0, 0x1c(r8);
  rlwimi r0, r9, 0xd, 0x12, 0x12;
  rlwimi r0, r10, 0xe, 0xf, 0x11;
  stw r0, 0x1c(r8);
  b lbl_8016df8c;
  lwz r0, 0x1c(r8);
  rlwimi r0, r9, 0x11, 0xe, 0xe;
  rlwimi r0, r10, 0x12, 0xb, 0xd;
  stw r0, 0x1c(r8);
  b lbl_8016df8c;
  lwz r0, 0x1c(r8);
  rlwimi r0, r9, 0x15, 0xa, 0xa;
  rlwimi r0, r10, 0x16, 7, 9;
  rlwimi r0, r7, 0x19, 2, 6;
  stw r0, 0x1c(r8);
  b lbl_8016df8c;
  lwz r0, 0x3c(r8);
  rlwimi r0, r9, 0, 0x1f, 0x1f;
  rlwimi r0, r10, 1, 0x1c, 0x1e;
  rlwimi r0, r7, 4, 0x17, 0x1b;
  stw r0, 0x3c(r8);
  b lbl_8016df8c;
  lwz r0, 0x3c(r8);
  rlwimi r0, r9, 9, 0x16, 0x16;
  rlwimi r0, r10, 0xa, 0x13, 0x15;
  rlwimi r0, r7, 0xd, 0xe, 0x12;
  stw r0, 0x3c(r8);
  b lbl_8016df8c;
  lwz r0, 0x3c(r8);
  rlwimi r0, r9, 0x12, 0xd, 0xd;
  rlwimi r0, r10, 0x13, 0xa, 0xc;
  rlwimi r0, r7, 0x16, 5, 9;
  stw r0, 0x3c(r8);
  b lbl_8016df8c;
  lwz r0, 0x3c(r8);
  rlwimi r0, r9, 0x1b, 4, 4;
  rlwimi r0, r10, 0x1c, 1, 3;
  stw r0, 0x3c(r8);
  lwz r0, 0x5c(r8);
  rlwimi r0, r7, 0, 0x1b, 0x1f;
  stw r0, 0x5c(r8);
  b lbl_8016df8c;
  lwz r0, 0x5c(r8);
  rlwimi r0, r9, 5, 0x1a, 0x1a;
  rlwimi r0, r10, 6, 0x17, 0x19;
  rlwimi r0, r7, 9, 0x12, 0x16;
  stw r0, 0x5c(r8);
  b lbl_8016df8c;
  lwz r0, 0x5c(r8);
  rlwimi r0, r9, 0xe, 0x11, 0x11;
  rlwimi r0, r10, 0xf, 0xe, 0x10;
  rlwimi r0, r7, 0x12, 9, 0xd;
  stw r0, 0x5c(r8);
  b lbl_8016df8c;
  lwz r0, 0x5c(r8);
  rlwimi r0, r9, 0x17, 8, 8;
  rlwimi r0, r10, 0x18, 5, 7;
  rlwimi r0, r7, 0x1b, 0, 4;
  stw r0, 0x5c(r8);
lbl_8016df8c:
  addi r4, r4, 0x10;
lbl_8016df90:
  lwz r0, 0(r4);
  cmpwi r0, 0xff;
  bne lbl_8016de1c;
  lwz r5, gx;
  clrlwi r0, r3, 0x18;
  li r3, 1;
  lwz r4, 0x5fc(r5);
  slw r0, r3, r0;
  clrlwi r0, r0, 0x18;
  ori r3, r4, 0x10;
  stw r3, 0x5fc(r5);
  lbz r3, 0x5fb(r5);
  or r0, r3, r0;
  stb r0, 0x5fb(r5);
  blr;
  // clang-format on
}

// Symbol: __GXSetVAT
// PAL: 0x8016dfcc..0x8016e04c
MARK_BINARY_BLOB(__GXSetVAT, 0x8016dfcc, 0x8016e04c);
asm UNKNOWN_FUNCTION(__GXSetVAT) {
  // clang-format off
  nofralloc;
  lwz r8, gx;
  li r9, 0;
  li r6, 8;
  lis r5, 0xcc01;
  lbz r10, 0x5fb(r8);
  mr r7, r8;
lbl_8016dfe4:
  clrlwi. r0, r10, 0x1f;
  beq lbl_8016e028;
  stb r6, -0x8000(r5);
  ori r4, r9, 0x70;
  ori r3, r9, 0x80;
  ori r0, r9, 0x90;
  stb r4, -0x8000(r5);
  lwz r4, 0x1c(r7);
  stw r4, -0x8000(r5);
  stb r6, -0x8000(r5);
  stb r3, -0x8000(r5);
  lwz r3, 0x3c(r7);
  stw r3, -0x8000(r5);
  stb r6, -0x8000(r5);
  stb r0, -0x8000(r5);
  lwz r0, 0x5c(r7);
  stw r0, -0x8000(r5);
lbl_8016e028:
  rlwinm. r10, r10, 0x1f, 1, 0x1f;
  addi r9, r9, 1;
  addi r7, r7, 4;
  bne lbl_8016dfe4;
  li r0, 0;
  lis r3, 0xcc01;
  stb r0, -0x8000(r3);
  stb r0, 0x5fb(r8);
  blr;
  // clang-format on
}

// Symbol: GXGetVtxAttrFmt
// PAL: 0x8016e04c..0x8016e2b8
MARK_BINARY_BLOB(GXGetVtxAttrFmt, 0x8016e04c, 0x8016e2b8);
asm UNKNOWN_FUNCTION(GXGetVtxAttrFmt) {
  // clang-format off
  nofralloc;
  addi r0, r4, -9;
  lwz r4, gx;
  cmplwi r0, 0x10;
  slwi r3, r3, 2;
  add r3, r4, r3;
  bgt lbl_8016e2a0;
  lis r4, 0x8029;
  slwi r0, r0, 2;
  addi r4, r4, -24176;
  lwzx r4, r4, r0;
  mtctr r4;
  bctr;
  lwz r0, 0x1c(r3);
  clrlwi r0, r0, 0x1f;
  stw r0, 0(r5);
  lwz r0, 0x1c(r3);
  rlwinm r0, r0, 0x1f, 0x1d, 0x1f;
  stw r0, 0(r6);
  lwz r0, 0x1c(r3);
  rlwinm r0, r0, 0x1c, 0x1b, 0x1f;
  stb r0, 0(r7);
  blr;
  lwz r0, 0x1c(r3);
  rlwinm r0, r0, 0x17, 0x1f, 0x1f;
  cmpwi r0, 1;
  stw r0, 0(r5);
  bne lbl_8016e0cc;
  lwz r0, 0x1c(r3);
  rlwinm. r0, r0, 1, 0x1f, 0x1f;
  beq lbl_8016e0cc;
  li r0, 2;
  stw r0, 0(r5);
lbl_8016e0cc:
  lwz r0, 0x1c(r3);
  rlwinm r0, r0, 0x16, 0x1d, 0x1f;
  cmpwi r0, 2;
  stw r0, 0(r6);
  beq lbl_8016e10c;
  bge lbl_8016e0f0;
  cmpwi r0, 1;
  bge lbl_8016e0fc;
  b lbl_8016e10c;
lbl_8016e0f0:
  cmpwi r0, 4;
  bge lbl_8016e10c;
  b lbl_8016e104;
lbl_8016e0fc:
  li r0, 6;
  b lbl_8016e110;
lbl_8016e104:
  li r0, 0xe;
  b lbl_8016e110;
lbl_8016e10c:
  li r0, 0;
lbl_8016e110:
  stb r0, 0(r7);
  blr;
  lwz r4, 0x1c(r3);
  li r0, 0;
  rlwinm r4, r4, 0x13, 0x1f, 0x1f;
  stw r4, 0(r5);
  lwz r3, 0x1c(r3);
  rlwinm r3, r3, 0x12, 0x1d, 0x1f;
  stw r3, 0(r6);
  stb r0, 0(r7);
  blr;
  lwz r4, 0x1c(r3);
  li r0, 0;
  rlwinm r4, r4, 0xf, 0x1f, 0x1f;
  stw r4, 0(r5);
  lwz r3, 0x1c(r3);
  rlwinm r3, r3, 0xe, 0x1d, 0x1f;
  stw r3, 0(r6);
  stb r0, 0(r7);
  blr;
  lwz r0, 0x1c(r3);
  rlwinm r0, r0, 0xb, 0x1f, 0x1f;
  stw r0, 0(r5);
  lwz r0, 0x1c(r3);
  rlwinm r0, r0, 0xa, 0x1d, 0x1f;
  stw r0, 0(r6);
  lwz r0, 0x1c(r3);
  rlwinm r0, r0, 7, 0x1b, 0x1f;
  stb r0, 0(r7);
  blr;
  lwz r0, 0x3c(r3);
  clrlwi r0, r0, 0x1f;
  stw r0, 0(r5);
  lwz r0, 0x3c(r3);
  rlwinm r0, r0, 0x1f, 0x1d, 0x1f;
  stw r0, 0(r6);
  lwz r0, 0x3c(r3);
  rlwinm r0, r0, 0x1c, 0x1b, 0x1f;
  stb r0, 0(r7);
  blr;
  lwz r0, 0x3c(r3);
  rlwinm r0, r0, 0x17, 0x1f, 0x1f;
  stw r0, 0(r5);
  lwz r0, 0x3c(r3);
  rlwinm r0, r0, 0x16, 0x1d, 0x1f;
  stw r0, 0(r6);
  lwz r0, 0x3c(r3);
  rlwinm r0, r0, 0x13, 0x1b, 0x1f;
  stb r0, 0(r7);
  blr;
  lwz r0, 0x3c(r3);
  rlwinm r0, r0, 0xe, 0x1f, 0x1f;
  stw r0, 0(r5);
  lwz r0, 0x3c(r3);
  rlwinm r0, r0, 0xd, 0x1d, 0x1f;
  stw r0, 0(r6);
  lwz r0, 0x3c(r3);
  rlwinm r0, r0, 0xa, 0x1b, 0x1f;
  stb r0, 0(r7);
  blr;
  lwz r0, 0x3c(r3);
  rlwinm r0, r0, 5, 0x1f, 0x1f;
  stw r0, 0(r5);
  lwz r0, 0x3c(r3);
  rlwinm r0, r0, 4, 0x1d, 0x1f;
  stw r0, 0(r6);
  lwz r0, 0x5c(r3);
  clrlwi r0, r0, 0x1b;
  stb r0, 0(r7);
  blr;
  lwz r0, 0x5c(r3);
  rlwinm r0, r0, 0x1b, 0x1f, 0x1f;
  stw r0, 0(r5);
  lwz r0, 0x5c(r3);
  rlwinm r0, r0, 0x1a, 0x1d, 0x1f;
  stw r0, 0(r6);
  lwz r0, 0x5c(r3);
  rlwinm r0, r0, 0x17, 0x1b, 0x1f;
  stb r0, 0(r7);
  blr;
  lwz r0, 0x5c(r3);
  rlwinm r0, r0, 0x12, 0x1f, 0x1f;
  stw r0, 0(r5);
  lwz r0, 0x5c(r3);
  rlwinm r0, r0, 0x11, 0x1d, 0x1f;
  stw r0, 0(r6);
  lwz r0, 0x5c(r3);
  rlwinm r0, r0, 0xe, 0x1b, 0x1f;
  stb r0, 0(r7);
  blr;
  lwz r0, 0x5c(r3);
  rlwinm r0, r0, 9, 0x1f, 0x1f;
  stw r0, 0(r5);
  lwz r0, 0x5c(r3);
  rlwinm r0, r0, 8, 0x1d, 0x1f;
  stw r0, 0(r6);
  lwz r0, 0x5c(r3);
  srwi r0, r0, 0x1b;
  stb r0, 0(r7);
  blr;
lbl_8016e2a0:
  li r3, 1;
  li r0, 0;
  stw r3, 0(r5);
  stw r0, 0(r6);
  stb r0, 0(r7);
  blr;
  // clang-format on
}

// Symbol: GXGetVtxAttrFmtv
// PAL: 0x8016e2b8..0x8016e32c
MARK_BINARY_BLOB(GXGetVtxAttrFmtv, 0x8016e2b8, 0x8016e32c);
asm UNKNOWN_FUNCTION(GXGetVtxAttrFmtv) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  li r31, 9;
  stw r30, 0x18(r1);
  mr r30, r4;
  stw r29, 0x14(r1);
  mr r29, r3;
lbl_8016e2dc:
  stw r31, 0(r30);
  mr r3, r29;
  mr r4, r31;
  addi r5, r30, 4;
  addi r6, r30, 8;
  addi r7, r30, 0xc;
  bl GXGetVtxAttrFmt;
  addi r31, r31, 1;
  addi r30, r30, 0x10;
  cmpwi r31, 0x14;
  ble lbl_8016e2dc;
  li r0, 0xff;
  stw r0, 0(r30);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: GXSetArray
// PAL: 0x8016e32c..0x8016e36c
MARK_BINARY_BLOB(GXSetArray, 0x8016e32c, 0x8016e36c);
asm void GXSetArray(GXAttr, const void*, u8) {
  // clang-format off
  nofralloc;
  cmpwi r3, 0x19;
  bne lbl_8016e338;
  li r3, 0xa;
lbl_8016e338:
  lis r6, 0xcc01;
  li r7, 8;
  addi r8, r3, -9;
  stb r7, -0x8000(r6);
  ori r0, r8, 0xa0;
  clrlwi r3, r4, 2;
  stb r0, -0x8000(r6);
  ori r0, r8, 0xb0;
  stw r3, -0x8000(r6);
  stb r7, -0x8000(r6);
  stb r0, -0x8000(r6);
  stw r5, -0x8000(r6);
  blr;
  // clang-format on
}

// Symbol: GXInvalidateVtxCache
// PAL: 0x8016e36c..0x8016e37c
MARK_BINARY_BLOB(GXInvalidateVtxCache, 0x8016e36c, 0x8016e37c);
asm void GXInvalidateVtxCache(void) {
  // clang-format off
  nofralloc;
  li r0, 0x48;
  lis r3, 0xcc01;
  stb r0, -0x8000(r3);
  blr;
  // clang-format on
}

// Symbol: GXSetTexCoordGen2
// PAL: 0x8016e37c..0x8016e5a4
MARK_BINARY_BLOB(GXSetTexCoordGen2, 0x8016e37c, 0x8016e5a4);
asm void GXSetTexCoordGen2(int, int function, int, int, int, int) {
  // clang-format off
  nofralloc;
  cmplwi r5, 0x14;
  li r11, 0;
  li r12, 0;
  li r10, 5;
  bgt lbl_8016e424;
  lis r9, 0x8029;
  slwi r0, r5, 2;
  addi r9, r9, -24080;
  lwzx r9, r9, r0;
  mtctr r9;
  bctr;
  li r10, 0;
  li r12, 1;
  b lbl_8016e424;
  li r10, 1;
  li r12, 1;
  b lbl_8016e424;
  li r10, 3;
  li r12, 1;
  b lbl_8016e424;
  li r10, 4;
  li r12, 1;
  b lbl_8016e424;
  li r10, 2;
  b lbl_8016e424;
  li r10, 2;
  b lbl_8016e424;
  li r10, 5;
  b lbl_8016e424;
  li r10, 6;
  b lbl_8016e424;
  li r10, 7;
  b lbl_8016e424;
  li r10, 8;
  b lbl_8016e424;
  li r10, 9;
  b lbl_8016e424;
  li r10, 0xa;
  b lbl_8016e424;
  li r10, 0xb;
  b lbl_8016e424;
  li r10, 0xc;
lbl_8016e424:
  cmpwi r4, 1;
  beq lbl_8016e44c;
  bge lbl_8016e43c;
  cmpwi r4, 0;
  bge lbl_8016e45c;
  b lbl_8016e4c4;
lbl_8016e43c:
  cmpwi r4, 0xa;
  beq lbl_8016e498;
  bge lbl_8016e4c4;
  b lbl_8016e470;
lbl_8016e44c:
  li r11, 0;
  rlwimi r11, r12, 2, 0x1d, 0x1d;
  rlwimi r11, r10, 7, 0x14, 0x18;
  b lbl_8016e4c4;
lbl_8016e45c:
  li r0, 0;
  ori r11, r0, 2;
  rlwimi r11, r12, 2, 0x1d, 0x1d;
  rlwimi r11, r10, 7, 0x14, 0x18;
  b lbl_8016e4c4;
lbl_8016e470:
  li r9, 1;
  addi r5, r5, -12;
  li r11, 0;
  addi r0, r4, -2;
  rlwimi r11, r12, 2, 0x1d, 0x1d;
  rlwimi r11, r9, 4, 0x19, 0x1b;
  rlwimi r11, r10, 7, 0x14, 0x18;
  rlwimi r11, r5, 0xc, 0x11, 0x13;
  rlwimi r11, r0, 0xf, 0xe, 0x10;
  b lbl_8016e4c4;
lbl_8016e498:
  cmpwi r5, 0x13;
  li r11, 0;
  rlwimi r11, r12, 2, 0x1d, 0x1d;
  bne lbl_8016e4b4;
  li r0, 2;
  rlwimi r11, r0, 4, 0x19, 0x1b;
  b lbl_8016e4bc;
lbl_8016e4b4:
  li r0, 3;
  rlwimi r11, r0, 4, 0x19, 0x1b;
lbl_8016e4bc:
  li r0, 2;
  rlwimi r11, r0, 7, 0x14, 0x18;
lbl_8016e4c4:
  lwz r10, gx;
  slwi r9, r3, 2;
  addi r0, r8, -64;
  li r4, 0;
  add r8, r10, r9;
  lis r5, 1;
  stw r11, 0xc8(r8);
  rlwimi r4, r0, 0, 0x1a, 0x1f;
  slw r0, r5, r3;
  cmplwi r3, 6;
  lwz r5, 0x5fc(r10);
  rlwimi r4, r7, 8, 0x17, 0x17;
  or r0, r5, r0;
  stw r0, 0x5fc(r10);
  stw r4, 0xe8(r8);
  bgt lbl_8016e588;
  lis r3, 0x8029;
  addi r3, r3, -24108;
  lwzx r3, r3, r9;
  mtctr r3;
  bctr;
  lwz r0, 0x80(r10);
  rlwimi r0, r6, 6, 0x14, 0x19;
  stw r0, 0x80(r10);
  b lbl_8016e594;
  lwz r0, 0x80(r10);
  rlwimi r0, r6, 0xc, 0xe, 0x13;
  stw r0, 0x80(r10);
  b lbl_8016e594;
  lwz r0, 0x80(r10);
  rlwimi r0, r6, 0x12, 8, 0xd;
  stw r0, 0x80(r10);
  b lbl_8016e594;
  lwz r0, 0x80(r10);
  rlwimi r0, r6, 0x18, 2, 7;
  stw r0, 0x80(r10);
  b lbl_8016e594;
  lwz r0, 0x84(r10);
  rlwimi r0, r6, 0, 0x1a, 0x1f;
  stw r0, 0x84(r10);
  b lbl_8016e594;
  lwz r0, 0x84(r10);
  rlwimi r0, r6, 6, 0x14, 0x19;
  stw r0, 0x84(r10);
  b lbl_8016e594;
  lwz r0, 0x84(r10);
  rlwimi r0, r6, 0xc, 0xe, 0x13;
  stw r0, 0x84(r10);
  b lbl_8016e594;
lbl_8016e588:
  lwz r0, 0x84(r10);
  rlwimi r0, r6, 0x12, 8, 0xd;
  stw r0, 0x84(r10);
lbl_8016e594:
  lwz r0, 0x5fc(r10);
  oris r0, r0, 0x400;
  stw r0, 0x5fc(r10);
  blr;
  // clang-format on
}

// Symbol: GXSetNumTexGens
// PAL: 0x8016e5a4..0x8016e5c8
MARK_BINARY_BLOB(GXSetNumTexGens, 0x8016e5a4, 0x8016e5c8);
asm void GXSetNumTexGens(int) {
  // clang-format off
  nofralloc;
  lwz r4, gx;
  lwz r0, 0x254(r4);
  rlwimi r0, r3, 0, 0x1c, 0x1f;
  stw r0, 0x254(r4);
  lwz r0, 0x5fc(r4);
  oris r0, r0, 0x200;
  ori r0, r0, 4;
  stw r0, 0x5fc(r4);
  blr;
  // clang-format on
}

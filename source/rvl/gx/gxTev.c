#include "gxTev.h"

// Symbol: GXSetTevOp
// PAL: 0x80171c4c..0x80171ce0
MARK_BINARY_BLOB(GXSetTevOp, 0x80171c4c, 0x80171ce0);
asm void GXSetTevOp(GXTevStageID, int tevMode) {
  // clang-format off
  nofralloc;
  cmpwi r3, 0;
  lis r5, 0x8029;
  addi r5, r5, -23104;
  bne lbl_80171c74;
  slwi r6, r4, 2;
  addi r4, r5, 0;
  addi r0, r5, 0x28;
  add r8, r4, r6;
  add r9, r0, r6;
  b lbl_80171c88;
lbl_80171c74:
  slwi r6, r4, 2;
  addi r4, r5, 0x14;
  addi r0, r5, 0x3c;
  add r8, r4, r6;
  add r9, r0, r6;
lbl_80171c88:
  lwz r7, gx;
  slwi r0, r3, 2;
  lwz r3, 0(r8);
  lis r4, 0xcc01;
  add r6, r7, r0;
  li r5, 0x61;
  lwz r8, 0x180(r6);
  li r0, 0;
  stb r5, -0x8000(r4);
  rlwinm r8, r8, 0, 0, 7;
  rlwimi r8, r3, 0, 8, 0x1f;
  stw r8, -0x8000(r4);
  stw r8, 0x180(r6);
  lwz r8, 0x1c0(r6);
  lwz r3, 0(r9);
  rlwinm r8, r8, 0, 0x1c, 7;
  stb r5, -0x8000(r4);
  rlwimi r8, r3, 0, 8, 0x1b;
  stw r8, -0x8000(r4);
  stw r8, 0x1c0(r6);
  sth r0, 2(r7);
  blr;
  // clang-format on
}

// Symbol: GXSetTevColorIn
// PAL: 0x80171ce0..0x80171d20
MARK_BINARY_BLOB(GXSetTevColorIn, 0x80171ce0, 0x80171d20);
asm void GXSetTevColorIn(GXTevStageID, int a, int b, int c, int d) {
  // clang-format off
  nofralloc;
  lwz r11, gx;
  slwi r0, r3, 2;
  lis r3, 0xcc01;
  li r8, 0x61;
  add r10, r11, r0;
  li r0, 0;
  lwz r9, 0x180(r10);
  rlwimi r9, r4, 0xc, 0x10, 0x13;
  rlwimi r9, r5, 8, 0x14, 0x17;
  stb r8, -0x8000(r3);
  rlwimi r9, r6, 4, 0x18, 0x1b;
  rlwimi r9, r7, 0, 0x1c, 0x1f;
  stw r9, -0x8000(r3);
  stw r9, 0x180(r10);
  sth r0, 2(r11);
  blr;
  // clang-format on
}

// Symbol: GXSetTevAlphaIn
// PAL: 0x80171d20..0x80171d60
MARK_BINARY_BLOB(GXSetTevAlphaIn, 0x80171d20, 0x80171d60);
asm void GXSetTevAlphaIn(GXTevStageID, int a, int b, int c, int d) {
  // clang-format off
  nofralloc;
  lwz r11, gx;
  slwi r0, r3, 2;
  lis r3, 0xcc01;
  li r8, 0x61;
  add r10, r11, r0;
  li r0, 0;
  lwz r9, 0x1c0(r10);
  rlwimi r9, r4, 0xd, 0x10, 0x12;
  rlwimi r9, r5, 0xa, 0x13, 0x15;
  stb r8, -0x8000(r3);
  rlwimi r9, r6, 7, 0x16, 0x18;
  rlwimi r9, r7, 4, 0x19, 0x1b;
  stw r9, -0x8000(r3);
  stw r9, 0x1c0(r10);
  sth r0, 2(r11);
  blr;
  // clang-format on
}

// Symbol: GXSetTevColorOp
// PAL: 0x80171d60..0x80171db8
MARK_BINARY_BLOB(GXSetTevColorOp, 0x80171d60, 0x80171db8);
asm void GXSetTevColorOp(GXTevStageID, int, int, int, int, int) {
  // clang-format off
  nofralloc;
  lwz r10, gx;
  slwi r0, r3, 2;
  cmpwi r4, 1;
  add r9, r10, r0;
  lwz r11, 0x180(r9);
  rlwimi r11, r4, 0x12, 0xd, 0xd;
  bgt lbl_80171d88;
  rlwimi r11, r6, 0x14, 0xa, 0xb;
  rlwimi r11, r5, 0x10, 0xe, 0xf;
  b lbl_80171d90;
lbl_80171d88:
  rlwimi r11, r4, 0x13, 0xa, 0xb;
  oris r11, r11, 3;
lbl_80171d90:
  lis r3, 0xcc01;
  li r0, 0x61;
  stb r0, -0x8000(r3);
  rlwimi r11, r7, 0x13, 0xc, 0xc;
  rlwimi r11, r8, 0x16, 8, 9;
  li r0, 0;
  stw r11, -0x8000(r3);
  stw r11, 0x180(r9);
  sth r0, 2(r10);
  blr;
  // clang-format on
}

// Symbol: GXSetTevAlphaOp
// PAL: 0x80171db8..0x80171e10
MARK_BINARY_BLOB(GXSetTevAlphaOp, 0x80171db8, 0x80171e10);
asm void GXSetTevAlphaOp(GXTevStageID, int, int, int, int, int) {
  // clang-format off
  nofralloc;
  lwz r10, gx;
  slwi r0, r3, 2;
  cmpwi r4, 1;
  add r9, r10, r0;
  lwz r11, 0x1c0(r9);
  rlwimi r11, r4, 0x12, 0xd, 0xd;
  bgt lbl_80171de0;
  rlwimi r11, r6, 0x14, 0xa, 0xb;
  rlwimi r11, r5, 0x10, 0xe, 0xf;
  b lbl_80171de8;
lbl_80171de0:
  rlwimi r11, r4, 0x13, 0xa, 0xb;
  oris r11, r11, 3;
lbl_80171de8:
  lis r3, 0xcc01;
  li r0, 0x61;
  stb r0, -0x8000(r3);
  rlwimi r11, r7, 0x13, 0xc, 0xc;
  rlwimi r11, r8, 0x16, 8, 9;
  li r0, 0;
  stw r11, -0x8000(r3);
  stw r11, 0x1c0(r9);
  sth r0, 2(r10);
  blr;
  // clang-format on
}

// Symbol: GXSetTevColor
// PAL: 0x80171e10..0x80171e70
MARK_BINARY_BLOB(GXSetTevColor, 0x80171e10, 0x80171e70);
asm void GXSetTevColor(GXTevRegID, GXColor) {
  // clang-format off
  nofralloc;
  slwi r3, r3, 1;
  lwz r8, 0(r4);
  addi r0, r3, 0xe0;
  lis r4, 0xcc01;
  slwi r7, r0, 0x18;
  li r5, 0x61;
  rlwimi r7, r8, 8, 0x18, 0x1f;
  stb r5, -0x8000(r4);
  rlwimi r7, r8, 0xc, 0xc, 0x13;
  addi r0, r3, 0xe1;
  stw r7, -0x8000(r4);
  slwi r6, r0, 0x18;
  rlwimi r6, r8, 0x18, 0x18, 0x1f;
  lwz r3, gx;
  stb r5, -0x8000(r4);
  rlwimi r6, r8, 0x1c, 0xc, 0x13;
  li r0, 0;
  stw r6, -0x8000(r4);
  stb r5, -0x8000(r4);
  stw r6, -0x8000(r4);
  stb r5, -0x8000(r4);
  stw r6, -0x8000(r4);
  sth r0, 2(r3);
  blr;
  // clang-format on
}

// Symbol: GXSetTevColorS10
// PAL: 0x80171e70..0x80171ed4
MARK_BINARY_BLOB(GXSetTevColorS10, 0x80171e70, 0x80171ed4);
asm UNKNOWN_FUNCTION(GXSetTevColorS10) {
  // clang-format off
  nofralloc;
  slwi r3, r3, 1;
  lwz r8, 0(r4);
  addi r0, r3, 0xe0;
  lis r5, 0xcc01;
  slwi r7, r0, 0x18;
  li r6, 0x61;
  lwz r9, 4(r4);
  rlwimi r7, r8, 0x10, 0x15, 0x1f;
  stb r6, -0x8000(r5);
  addi r0, r3, 0xe1;
  rlwimi r7, r9, 0xc, 9, 0x13;
  lwz r3, gx;
  slwi r4, r0, 0x18;
  stw r7, -0x8000(r5);
  rlwimi r4, r9, 0x10, 0x15, 0x1f;
  li r0, 0;
  stb r6, -0x8000(r5);
  rlwimi r4, r8, 0xc, 9, 0x13;
  stw r4, -0x8000(r5);
  stb r6, -0x8000(r5);
  stw r4, -0x8000(r5);
  stb r6, -0x8000(r5);
  stw r4, -0x8000(r5);
  sth r0, 2(r3);
  blr;
  // clang-format on
}

// Symbol: GXSetTevKColor
// PAL: 0x80171ed4..0x80171f30
MARK_BINARY_BLOB(GXSetTevKColor, 0x80171ed4, 0x80171f30);
asm void GXSetTevKColor(GXTevRegID, GXColor) {
  // clang-format off
  nofralloc;
  slwi r6, r3, 1;
  lwz r9, 0(r4);
  addi r3, r6, 0xe0;
  lis r4, 0xcc01;
  slwi r8, r3, 0x18;
  li r5, 0x61;
  rlwimi r8, r9, 8, 0x18, 0x1f;
  stb r5, -0x8000(r4);
  li r7, 8;
  addi r0, r6, 0xe1;
  rlwimi r8, r9, 0xc, 0xc, 0x13;
  lwz r3, gx;
  slwi r6, r0, 0x18;
  li r0, 0;
  rlwimi r8, r7, 0x14, 8, 0xb;
  stw r8, -0x8000(r4);
  rlwimi r6, r9, 0x18, 0x18, 0x1f;
  rlwimi r6, r9, 0x1c, 0xc, 0x13;
  stb r5, -0x8000(r4);
  rlwimi r6, r7, 0x14, 8, 0xb;
  stw r6, -0x8000(r4);
  sth r0, 2(r3);
  blr;
  // clang-format on
}

// Symbol: GXSetTevKColorSel
// PAL: 0x80171f30..0x80171f80
MARK_BINARY_BLOB(GXSetTevKColorSel, 0x80171f30, 0x80171f80);
asm void GXSetTevKColorSel(GXTevStageID, int) {
  // clang-format off
  nofralloc;
  clrlwi. r0, r3, 0x1f;
  lwz r5, gx;
  rlwinm r0, r3, 1, 0, 0x1d;
  add r3, r5, r0;
  beq lbl_80171f54;
  lwz r0, 0x200(r3);
  rlwimi r0, r4, 0xe, 0xd, 0x11;
  stw r0, 0x200(r3);
  b lbl_80171f60;
lbl_80171f54:
  lwz r0, 0x200(r3);
  rlwimi r0, r4, 4, 0x17, 0x1b;
  stw r0, 0x200(r3);
lbl_80171f60:
  lis r4, 0xcc01;
  li r0, 0x61;
  stb r0, -0x8000(r4);
  li r0, 0;
  lwz r3, 0x200(r3);
  stw r3, -0x8000(r4);
  sth r0, 2(r5);
  blr;
  // clang-format on
}

// Symbol: GXSetTevKAlphaSel
// PAL: 0x80171f80..0x80171fd0
MARK_BINARY_BLOB(GXSetTevKAlphaSel, 0x80171f80, 0x80171fd0);
asm void GXSetTevKAlphaSel(GXTevStageID, int) {
  // clang-format off
  nofralloc;
  clrlwi. r0, r3, 0x1f;
  lwz r5, gx;
  rlwinm r0, r3, 1, 0, 0x1d;
  add r3, r5, r0;
  beq lbl_80171fa4;
  lwz r0, 0x200(r3);
  rlwimi r0, r4, 0x13, 8, 0xc;
  stw r0, 0x200(r3);
  b lbl_80171fb0;
lbl_80171fa4:
  lwz r0, 0x200(r3);
  rlwimi r0, r4, 9, 0x12, 0x16;
  stw r0, 0x200(r3);
lbl_80171fb0:
  lis r4, 0xcc01;
  li r0, 0x61;
  stb r0, -0x8000(r4);
  li r0, 0;
  lwz r3, 0x200(r3);
  stw r3, -0x8000(r4);
  sth r0, 2(r5);
  blr;
  // clang-format on
}

// Symbol: GXSetTevSwapMode
// PAL: 0x80171fd0..0x8017200c
MARK_BINARY_BLOB(GXSetTevSwapMode, 0x80171fd0, 0x8017200c);
asm void GXSetTevSwapMode(int, int, int) {
  // clang-format off
  nofralloc;
  lwz r9, gx;
  slwi r0, r3, 2;
  lis r6, 0xcc01;
  li r3, 0x61;
  add r8, r9, r0;
  li r0, 0;
  lwz r7, 0x1c0(r8);
  rlwimi r7, r4, 0, 0x1e, 0x1f;
  rlwimi r7, r5, 2, 0x1c, 0x1d;
  stw r7, 0x1c0(r8);
  stb r3, -0x8000(r6);
  lwz r3, 0x1c0(r8);
  stw r3, -0x8000(r6);
  sth r0, 2(r9);
  blr;
  // clang-format on
}

// Symbol: GXSetTevSwapModeTable
// PAL: 0x8017200c..0x80172088
MARK_BINARY_BLOB(GXSetTevSwapModeTable, 0x8017200c, 0x80172088);
asm void GXSetTevSwapModeTable(GXTevSwapSel, int, int, int, int) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  slwi r11, r3, 3;
  slwi r12, r3, 1;
  lis r8, 0xcc01;
  stw r31, 0xc(r1);
  li r9, 0x61;
  addi r3, r12, 1;
  li r0, 0;
  stw r30, 8(r1);
  lwz r30, gx;
  addi r31, r30, 0x200;
  lwzx r10, r31, r11;
  rlwimi r10, r4, 0, 0x1e, 0x1f;
  rlwimi r10, r5, 2, 0x1c, 0x1d;
  slwi r4, r3, 2;
  stwx r10, r31, r11;
  stb r9, -0x8000(r8);
  lwzx r3, r31, r11;
  stw r3, -0x8000(r8);
  lwzx r3, r31, r4;
  rlwimi r3, r6, 0, 0x1e, 0x1f;
  rlwimi r3, r7, 2, 0x1c, 0x1d;
  stwx r3, r31, r4;
  stb r9, -0x8000(r8);
  lwzx r3, r31, r4;
  stw r3, -0x8000(r8);
  sth r0, 2(r30);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: GXSetAlphaCompare
// PAL: 0x80172088..0x801720c0
MARK_BINARY_BLOB(GXSetAlphaCompare, 0x80172088, 0x801720c0);
asm void GXSetAlphaCompare(int, int, int, int, int) {
  // clang-format off
  nofralloc;
  lis r8, 0xcc01;
  li r0, 0x61;
  stb r0, -0x8000(r8);
  lis r9, 0xf300;
  rlwimi r9, r4, 0, 0x18, 0x1f;
  lwz r4, gx;
  rlwimi r9, r7, 8, 0x10, 0x17;
  li r0, 0;
  rlwimi r9, r3, 0x10, 0xd, 0xf;
  rlwimi r9, r6, 0x13, 0xa, 0xc;
  rlwimi r9, r5, 0x16, 8, 9;
  stw r9, -0x8000(r8);
  sth r0, 2(r4);
  blr;
  // clang-format on
}

// Symbol: GXSetZTexture
// PAL: 0x801720c0..0x8017214c
MARK_BINARY_BLOB(GXSetZTexture, 0x801720c0, 0x8017214c);
asm void GXSetZTexture(int, int zTexFormat, int) {
  // clang-format off
  nofralloc;
  cmpwi r4, 0x13;
  li r7, 0;
  li r0, 0xf4;
  rlwimi r7, r5, 0, 8, 0x1f;
  rlwimi r7, r0, 0x18, 0, 7;
  beq lbl_801720fc;
  bge lbl_801720e8;
  cmpwi r4, 0x11;
  beq lbl_801720f4;
  b lbl_8017210c;
lbl_801720e8:
  cmpwi r4, 0x16;
  beq lbl_80172104;
  b lbl_8017210c;
lbl_801720f4:
  li r5, 0;
  b lbl_80172110;
lbl_801720fc:
  li r5, 1;
  b lbl_80172110;
lbl_80172104:
  li r5, 2;
  b lbl_80172110;
lbl_8017210c:
  li r5, 2;
lbl_80172110:
  lis r4, 0xcc01;
  li r0, 0x61;
  stb r0, -0x8000(r4);
  li r6, 0;
  rlwimi r6, r5, 0, 0x1e, 0x1f;
  li r5, 0xf5;
  stw r7, -0x8000(r4);
  rlwimi r6, r3, 2, 0x1c, 0x1d;
  rlwimi r6, r5, 0x18, 0, 7;
  lwz r3, gx;
  stb r0, -0x8000(r4);
  li r0, 0;
  stw r6, -0x8000(r4);
  sth r0, 2(r3);
  blr;
  // clang-format on
}

// Symbol: GXSetTevOrder
// PAL: 0x8017214c..0x801722a8
MARK_BINARY_BLOB(GXSetTevOrder, 0x8017214c, 0x801722a8);
asm void GXSetTevOrder(int, int, int, int colorChanID) {
  // clang-format off
  nofralloc;
  rlwinm r11, r5, 0, 0x18, 0x16;
  li r7, 8;
  srwi r9, r3, 0x1f;
  lwz r10, gx;
  subfc r0, r7, r11;
  slwi r8, r3, 2;
  addze r0, r7;
  add r9, r9, r3;
  add r7, r10, r8;
  cmpwi r4, 8;
  rlwinm r8, r9, 1, 0, 0x1d;
  subfic r0, r0, 8;
  stw r5, 0x5a4(r7);
  add r7, r10, r8;
  andc r9, r11, r0;
  blt lbl_801721a8;
  li r0, 1;
  lwz r8, 0x5e8(r10);
  slw r0, r0, r3;
  li r4, 0;
  andc r0, r8, r0;
  stw r0, 0x5e8(r10);
  b lbl_801721bc;
lbl_801721a8:
  li r0, 1;
  lwz r8, 0x5e8(r10);
  slw r0, r0, r3;
  or r0, r8, r0;
  stw r0, 0x5e8(r10);
lbl_801721bc:
  clrlwi. r0, r3, 0x1f;
  beq lbl_80172220;
  lwz r8, 0x150(r7);
  rlwimi r8, r9, 0xc, 0x11, 0x13;
  rlwimi r8, r4, 0xf, 0xe, 0x10;
  cmpwi r6, 0xff;
  stw r8, 0x150(r7);
  bne lbl_801721e4;
  li r0, 7;
  b lbl_801721f4;
lbl_801721e4:
  lis r3, 0x8029;
  slwi r0, r6, 2;
  addi r3, r3, -23024;
  lwzx r0, r3, r0;
lbl_801721f4:
  rlwimi r8, r0, 0x13, 0xa, 0xc;
  cmpwi r5, 0xff;
  stw r8, 0x150(r7);
  li r3, 0;
  beq lbl_80172214;
  rlwinm. r0, r5, 0, 0x17, 0x17;
  bne lbl_80172214;
  li r3, 1;
lbl_80172214:
  rlwimi r8, r3, 0x12, 0xd, 0xd;
  stw r8, 0x150(r7);
  b lbl_80172278;
lbl_80172220:
  lwz r8, 0x150(r7);
  rlwimi r8, r9, 0, 0x1d, 0x1f;
  rlwimi r8, r4, 3, 0x1a, 0x1c;
  cmpwi r6, 0xff;
  stw r8, 0x150(r7);
  bne lbl_80172240;
  li r0, 7;
  b lbl_80172250;
lbl_80172240:
  lis r3, 0x8029;
  slwi r0, r6, 2;
  addi r3, r3, -23024;
  lwzx r0, r3, r0;
lbl_80172250:
  rlwimi r8, r0, 7, 0x16, 0x18;
  cmpwi r5, 0xff;
  stw r8, 0x150(r7);
  li r3, 0;
  beq lbl_80172270;
  rlwinm. r0, r5, 0, 0x17, 0x17;
  bne lbl_80172270;
  li r3, 1;
lbl_80172270:
  rlwimi r8, r3, 6, 0x19, 0x19;
  stw r8, 0x150(r7);
lbl_80172278:
  lis r4, 0xcc01;
  li r0, 0x61;
  stb r0, -0x8000(r4);
  li r0, 0;
  lwz r5, gx;
  lwz r3, 0x150(r7);
  stw r3, -0x8000(r4);
  sth r0, 2(r5);
  lwz r0, 0x5fc(r5);
  ori r0, r0, 1;
  stw r0, 0x5fc(r5);
  blr;
  // clang-format on
}

// Symbol: GXSetNumTevStages
// PAL: 0x801722a8..0x801722cc
MARK_BINARY_BLOB(GXSetNumTevStages, 0x801722a8, 0x801722cc);
asm void GXSetNumTevStages(int) {
  // clang-format off
  nofralloc;
  lwz r4, gx;
  addi r0, r3, -1;
  lwz r3, 0x254(r4);
  rlwimi r3, r0, 0xa, 0x12, 0x15;
  stw r3, 0x254(r4);
  lwz r0, 0x5fc(r4);
  ori r0, r0, 4;
  stw r0, 0x5fc(r4);
  blr;
  // clang-format on
}

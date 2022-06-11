#include "eggFog.hpp"

extern "C" UNKNOWN_FUNCTION(GXSetFog);
extern "C" UNKNOWN_FUNCTION(GXSetFogRangeAdj);

extern float unk_80388d00;
extern float unk_80388d04;
extern u8 unk_80388b44;
extern u8 unk_80388b45;
extern u8 unk_80388b46;
extern u8 unk_80388b47;

// Symbol: unk_80226f04
// PAL: 0x80226f04..0x80226f60
MARK_BINARY_BLOB(unk_80226f04, 0x80226f04, 0x80226f60);
asm UNKNOWN_FUNCTION(unk_80226f04) {
  // clang-format off
  nofralloc;
  lis r4, 0x802a;
  addi r4, r4, 0x3028;
  stw r4, 0(r3);
  blr;
  addi r4, r2, -25692;
  lfs f0, unk_80388d00;
  lbz r7, unk_80388b44;
  li r8, 0;
  lbz r6, 1(r4);
  li r0, 2;
  lbz r5, 2(r4);
  lbz r4, 3(r4);
  stb r8, 0x1c(r3);
  stb r7, 4(r3);
  stb r6, 5(r3);
  stb r5, 6(r3);
  stb r4, 7(r3);
  stfs f0, 0x14(r3);
  stfs f0, 0x10(r3);
  stfs f0, 0xc(r3);
  stfs f0, 8(r3);
  stw r0, 0x18(r3);
  blr;
  // clang-format on
}

// Symbol: unk_80226f60
// PAL: 0x80226f60..0x80227018
MARK_BINARY_BLOB(unk_80226f60, 0x80226f60, 0x80227018);
asm UNKNOWN_FUNCTION(unk_80226f60) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  mr r8, r3;
  stw r0, 0x14(r1);
  lbz r0, 0x1c(r3);
  clrlwi. r0, r0, 0x1f;
  beq lbl_80226fbc;
  lbz r7, 4(r3);
  addi r4, r1, 0xc;
  lbz r6, 5(r3);
  lbz r5, 6(r3);
  lbz r0, 7(r3);
  stb r7, 0xc(r1);
  lwz r3, 0x18(r3);
  stb r6, 0xd(r1);
  lfs f1, 8(r8);
  stb r5, 0xe(r1);
  lfs f2, 0xc(r8);
  stb r0, 0xf(r1);
  lfs f3, 0x10(r8);
  lfs f4, 0x14(r8);
  bl GXSetFog;
  b lbl_80226ff8;
lbl_80226fbc:
  lfs f1, unk_80388d00;
  addi r4, r1, 8;
  lfs f2, unk_80388d04;
  li r3, 0;
  lbz r7, unk_80388b44;
  fmr f3, f1;
  lbz r6, unk_80388b45;
  fmr f4, f2;
  lbz r5, unk_80388b46;
  lbz r0, unk_80388b47;
  stb r7, 8(r1);
  stb r6, 9(r1);
  stb r5, 0xa(r1);
  stb r0, 0xb(r1);
  bl GXSetFog;
lbl_80226ff8:
  li r3, 0;
  li r4, 0;
  li r5, 0;
  bl GXSetFogRangeAdj;
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: unk_80227018
// PAL: 0x80227018..0x80227174
MARK_BINARY_BLOB(unk_80227018, 0x80227018, 0x80227174);
asm UNKNOWN_FUNCTION(unk_80227018) {
  // clang-format off
  nofralloc;
  lbz r0, 0x1c(r3);
  stwu r1, -0x10(r1);
  clrlwi. r0, r0, 0x1f;
  beq lbl_80227030;
  lwz r0, 0x18(r3);
  b lbl_80227034;
lbl_80227030:
  li r0, 0;
lbl_80227034:
  lwz r5, 0(r4);
  cmpwi r5, 0;
  beq lbl_80227044;
  stw r0, 0(r5);
lbl_80227044:
  lwz r5, 0(r4);
  lfs f1, 0xc(r3);
  cmpwi r5, 0;
  lfs f0, 8(r3);
  beq lbl_80227060;
  stfs f0, 4(r5);
  stfs f1, 8(r5);
lbl_80227060:
  lwz r7, 0(r4);
  lbz r6, 4(r3);
  lbz r5, 5(r3);
  cmpwi r7, 0;
  lbz r4, 6(r3);
  lbz r0, 7(r3);
  stb r6, 8(r1);
  stb r5, 9(r1);
  stb r4, 0xa(r1);
  stb r0, 0xb(r1);
  beq lbl_8022709c;
  stb r6, 0x14(r7);
  stb r5, 0x15(r7);
  stb r4, 0x16(r7);
  stb r0, 0x17(r7);
lbl_8022709c:
  addi r1, r1, 0x10;
  blr;
  lis r3, 0x8025;
  addi r3, r3, 0x7720;
  addi r3, r3, 6;
  blr;
  lbz r0, 8(r4);
  cmpwi r0, 0;
  bnelr;
  lfs f0, 0x10(r4);
  lfs f1, 0x14(r4);
  lfs f2, 0x18(r4);
  lfs f3, 0x1c(r4);
  lbz r9, 0x20(r4);
  lbz r8, 0x21(r4);
  lbz r7, 0x22(r4);
  lbz r6, 0x23(r4);
  lbz r5, 0x24(r4);
  lbz r0, 0x25(r4);
  stfs f0, 8(r3);
  stfs f1, 0xc(r3);
  stfs f2, 0x10(r3);
  stfs f3, 0x14(r3);
  stb r9, 4(r3);
  stb r8, 5(r3);
  stb r7, 6(r3);
  stb r6, 7(r3);
  stw r5, 0x18(r3);
  stb r0, 0x1c(r3);
  blr;
  lfs f0, 8(r3);
  lfs f1, 0xc(r3);
  lfs f2, 0x10(r3);
  lfs f3, 0x14(r3);
  lbz r9, 4(r3);
  lbz r8, 5(r3);
  lbz r7, 6(r3);
  lbz r6, 7(r3);
  lwz r5, 0x18(r3);
  lbz r0, 0x1c(r3);
  stfs f0, 0x10(r4);
  stfs f1, 0x14(r4);
  stfs f2, 0x18(r4);
  stfs f3, 0x1c(r4);
  stb r9, 0x20(r4);
  stb r8, 0x21(r4);
  stb r7, 0x22(r4);
  stb r6, 0x23(r4);
  stb r5, 0x24(r4);
  stb r0, 0x25(r4);
  blr;
  blr;
  li r3, 0x30;
  blr;
  // clang-format on
}

// Symbol: unk_80227174
// PAL: 0x80227174..0x802271bc
MARK_BINARY_BLOB(unk_80227174, 0x80227174, 0x802271bc);
asm UNKNOWN_FUNCTION(unk_80227174) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmpwi r3, 0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  beq lbl_8022719c;
  cmpwi r4, 0;
  ble lbl_8022719c;
  bl __dl__FPv;
lbl_8022719c:
  mr r3, r31;
  lwz r31, 0xc(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  li r3, 0;
  blr;
  // clang-format on
}

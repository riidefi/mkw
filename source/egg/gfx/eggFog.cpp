#include "eggFog.hpp"

// Source:
// https://github.com/doldecomp/ogws/blob/master/include/egg/gfx/eggFog.h

extern "C" UNKNOWN_FUNCTION(GXSetFog);
extern "C" UNKNOWN_FUNCTION(GXSetFogRangeAdj);

extern const GXColor unk_80388b44;
extern const u8 unk_80388b45;
extern const u8 unk_80388b46;
extern const u8 unk_80388b47;

namespace EGG {

Fog::Fog() {}

void Fog::Reset() {
  mFlags = 0;

  mColor = unk_80388b44;

  mFarZ = 0.0f;
  mNearZ = 0.0f;
  mEndZ = 0.0f;
  mStartZ = 0.0f;

  mFogType = GX_FOG_PERSP_LIN;
}

// void Fog::SetGX() const {
//   if (mFlags & BOUND) {
//     again, need to copy color byte-wise, not word wise
//     GXSetFog((int)mFogType, mStartZ, mEndZ, mNearZ, mFarZ, mColor);
//   } else {
//     GXSetFog(GX_FOG_NONE, 0.0f, 1.0f, 0.0f, 1.0f, unk_80388b44);
//   }
//   GXSetFogRangeAdj(0, 0, NULL);
// }

} // namespace EGG

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
  lfs f1, 0.0f;
  addi r4, r1, 8;
  lfs f2, 1.0f;
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
  // bruh
  lis r3, 0x8025;
  addi r3, r3, 0x7720;
  addi r3, r3, 6;
  blr;
  // bruh
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
  // bruh
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
  // bruh
  blr;
  // bruh
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

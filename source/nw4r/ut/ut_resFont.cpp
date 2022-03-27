#include "ut_resFont.hpp"

extern "C" {

// PAL: 0x80274ed0
extern void* __vt__Q34nw4r2ut7ResFont;

// Extern function references.
// PAL: 0x800af3a0
extern UNKNOWN_FUNCTION(
    IsValidBinaryFile__Q24nw4r2utFPCQ34nw4r2ut16BinaryFileHeaderUlUsUs);
// PAL: 0x800b1970
extern UNKNOWN_FUNCTION(
    InitReaderFunc__Q34nw4r2ut4FontFQ34nw4r2ut12FontEncoding);
// PAL: 0x800b1f90
extern UNKNOWN_FUNCTION(__ct__Q44nw4r2ut6detail11ResFontBaseFv);
// PAL: 0x800b1ff0
extern UNKNOWN_FUNCTION(__dt__Q44nw4r2ut6detail11ResFontBaseFv);
// PAL: 0x800b2030
extern UNKNOWN_FUNCTION(
    SetResourceBuffer__Q44nw4r2ut6detail11ResFontBaseFPvPQ34nw4r2ut15FontInformation);
}

namespace nw4r {
namespace ut {

// Symbol: __ct__Q34nw4r2ut7ResFontFv
// PAL: 0x800b2830..0x800b2870
MARK_BINARY_BLOB(__ct__Q34nw4r2ut7ResFontFv, 0x800b2830, 0x800b2870);
asm ResFont::ResFont() {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  bl __ct__Q44nw4r2ut6detail11ResFontBaseFv;
  lis r4, __vt__Q34nw4r2ut7ResFont@ha;
  mr r3, r31;
  addi r4, r4, __vt__Q34nw4r2ut7ResFont@l;
  stw r4, 0(r31);
  lwz r31, 0xc(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: __dt__Q34nw4r2ut7ResFontFv
// PAL: 0x800b2870..0x800b28d0
MARK_BINARY_BLOB(__dt__Q34nw4r2ut7ResFontFv, 0x800b2870, 0x800b28d0);
asm ResFont::~ResFont() {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmpwi r3, 0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  beq lbl_800b28ac;
  li r4, 0;
  bl __dt__Q44nw4r2ut6detail11ResFontBaseFv;
  cmpwi r31, 0;
  ble lbl_800b28ac;
  mr r3, r30;
  bl __dl__FPv;
lbl_800b28ac:
  mr r3, r30;
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: SetResource__Q34nw4r2ut7ResFontFPv
// PAL: 0x800b28d0..0x800b2a20
MARK_BINARY_BLOB(SetResource__Q34nw4r2ut7ResFontFPv, 0x800b28d0, 0x800b2a20);
asm bool ResFont::SetResource(void*) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  li r5, 0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  lwz r0, 0x10(r3);
  cmpwi r0, 0;
  beq lbl_800b2904;
  li r3, 0;
  b lbl_800b2a00;
lbl_800b2904:
  lwz r3, 0(r4);
  addis r0, r3, 0xadba;
  cmplwi r0, 0x4e55;
  bne lbl_800b2958;
  lhz r0, 0xc(r4);
  lhz r3, 0xe(r4);
  add r4, r4, r0;
  mtctr r3;
  cmpwi r3, 0;
  ble lbl_800b29c0;
  nop;
lbl_800b2930:
  lwz r3, 0(r4);
  addis r0, r3, 0xb9b7;
  cmplwi r0, 0x4e46;
  bne lbl_800b2948;
  addi r5, r4, 8;
  b lbl_800b29c0;
lbl_800b2948:
  lwz r0, 4(r4);
  add r4, r4, r0;
  bdnz lbl_800b2930;
  b lbl_800b29c0;
lbl_800b2958:
  lhz r0, 6(r4);
  cmplwi r0, 0x104;
  bne lbl_800b298c;
  lis r4, 0x5246;
  mr r3, r31;
  addi r4, r4, 0x4e54;
  li r5, 0x104;
  li r6, 2;
  bl IsValidBinaryFile__Q24nw4r2utFPCQ34nw4r2ut16BinaryFileHeaderUlUsUs;
  cmpwi r3, 0;
  bne lbl_800b29b4;
  li r3, 0;
  b lbl_800b2a00;
lbl_800b298c:
  lis r4, 0x5246;
  mr r3, r31;
  addi r4, r4, 0x4e54;
  li r5, 0x102;
  li r6, 2;
  bl IsValidBinaryFile__Q24nw4r2utFPCQ34nw4r2ut16BinaryFileHeaderUlUsUs;
  cmpwi r3, 0;
  bne lbl_800b29b4;
  li r3, 0;
  b lbl_800b2a00;
lbl_800b29b4:
  mr r3, r31;
  bl Rebuild;
  mr r5, r3;
lbl_800b29c0:
  cmpwi r5, 0;
  bne lbl_800b29d0;
  li r3, 0;
  b lbl_800b2a00;
lbl_800b29d0:
  mr r3, r30;
  mr r4, r31;
  bl SetResourceBuffer__Q44nw4r2ut6detail11ResFontBaseFPvPQ34nw4r2ut15FontInformation;
  lwz r12, 0(r30);
  mr r3, r30;
  lwz r12, 0x58(r12);
  mtctr r12;
  bctrl;
  mr r4, r3;
  mr r3, r30;
  bl InitReaderFunc__Q34nw4r2ut4FontFQ34nw4r2ut12FontEncoding;
  li r3, 1;
lbl_800b2a00:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: Rebuild__Q34nw4r2ut7ResFontFPQ34nw4r2ut16BinaryFileHeader
// PAL: 0x800b2a20..0x800b2b2c
MARK_BINARY_BLOB(Rebuild__Q34nw4r2ut7ResFontFPQ34nw4r2ut16BinaryFileHeader,
                 0x800b2a20, 0x800b2b2c);
asm FontInformation* ResFont::Rebuild(BinaryFileHeader*) {
  // clang-format off
  nofralloc;
  lhz r0, 0xc(r3);
  li r6, 0;
  li r7, 0;
  add r5, r3, r0;
  b lbl_800b2b0c;
  nop;
lbl_800b2a38:
  lwz r4, 0(r5);
  addis r0, r4, 0xb9b7;
  cmplwi r0, 0x4e46;
  beq lbl_800b2a7c;
  addis r0, r4, 0xabb9;
  cmplwi r0, 0x4c50;
  beq lbl_800b2ab8;
  addis r0, r4, 0xbca9;
  cmplwi r0, 0x4448;
  beq lbl_800b2ac8;
  addis r0, r4, 0xbcb3;
  cmplwi r0, 0x4150;
  beq lbl_800b2ae0;
  addis r0, r4, 0xb8b4;
  cmplwi r0, 0x4752;
  beq lbl_800b2b00;
  b lbl_800b2af8;
lbl_800b2a7c:
  lwz r0, 0x10(r5);
  addi r6, r5, 8;
  add r0, r3, r0;
  stw r0, 0x10(r5);
  lwz r0, 0x14(r5);
  cmpwi r0, 0;
  beq lbl_800b2aa0;
  add r0, r3, r0;
  stw r0, 0xc(r6);
lbl_800b2aa0:
  lwz r0, 0x10(r6);
  cmpwi r0, 0;
  beq lbl_800b2b00;
  add r0, r3, r0;
  stw r0, 0x10(r6);
  b lbl_800b2b00;
lbl_800b2ab8:
  lwz r0, 0x1c(r5);
  add r0, r3, r0;
  stw r0, 0x1c(r5);
  b lbl_800b2b00;
lbl_800b2ac8:
  lwz r0, 0xc(r5);
  cmpwi r0, 0;
  beq lbl_800b2b00;
  add r0, r3, r0;
  stw r0, 0xc(r5);
  b lbl_800b2b00;
lbl_800b2ae0:
  lwz r0, 0x10(r5);
  cmpwi r0, 0;
  beq lbl_800b2b00;
  add r0, r3, r0;
  stw r0, 0x10(r5);
  b lbl_800b2b00;
lbl_800b2af8:
  li r3, 0;
  blr;
lbl_800b2b00:
  lwz r0, 4(r5);
  addi r7, r7, 1;
  add r5, r5, r0;
lbl_800b2b0c:
  lhz r0, 0xe(r3);
  cmpw r7, r0;
  blt lbl_800b2a38;
  lis r4, 0x5246;
  addi r0, r4, 0x4e55;
  stw r0, 0(r3);
  mr r3, r6;
  blr;
  // clang-format on
}

} // namespace ut
} // namespace nw4r

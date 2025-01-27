#include "ut_binaryFileFormat.hpp"

// Symbol: IsValidBinaryFile__Q24nw4r2utFPCQ34nw4r2ut16BinaryFileHeaderUlUsUs
// PAL: 0x800af3a0..0x800af420
MARK_BINARY_BLOB(
    IsValidBinaryFile__Q24nw4r2utFPCQ34nw4r2ut16BinaryFileHeaderUlUsUs,
    0x800af3a0, 0x800af420);
asm UNKNOWN_FUNCTION(
    IsValidBinaryFile__Q24nw4r2utFPCQ34nw4r2ut16BinaryFileHeaderUlUsUs) {
  // clang-format off
  nofralloc;
  lwz r0, 0(r3);
  cmplw r0, r4;
  beq lbl_800af3b4;
  li r3, 0;
  blr;
lbl_800af3b4:
  lhz r0, 4(r3);
  cmplwi r0, 0xfeff;
  beq lbl_800af3c8;
  li r3, 0;
  blr;
lbl_800af3c8:
  lhz r0, 6(r3);
  cmplw r0, r5;
  beq lbl_800af3dc;
  li r3, 0;
  blr;
lbl_800af3dc:
  rlwinm r4, r6, 3, 0xd, 0x1c;
  lwz r5, 8(r3);
  addi r0, r4, 0x10;
  cmplw r5, r0;
  bge lbl_800af3f8;
  li r3, 0;
  blr;
lbl_800af3f8:
  lhz r3, 0xe(r3);
  subf r0, r6, r3;
  orc r3, r3, r6;
  srwi r0, r0, 1;
  subf r0, r0, r3;
  srwi r3, r0, 0x1f;
  blr;
  // clang-format on
}

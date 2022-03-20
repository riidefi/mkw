#include "ut_fileStream.hpp"

// Symbol: nw4r_ut_FilePosition_Cancel
// Function signature is unknown.
// PAL: 0x800afef0..0x800aff00
MARK_BINARY_BLOB(nw4r_ut_FilePosition_Cancel, 0x800afef0, 0x800aff00);
asm UNKNOWN_FUNCTION(nw4r_ut_FilePosition_Cancel) {
  // clang-format off
  nofralloc;
  blr;
  // clang-format on
}

// Symbol: nw4r_ut_FileStream_CancelAsync
// Function signature is unknown.
// PAL: 0x800aff00..0x800aff10
MARK_BINARY_BLOB(nw4r_ut_FileStream_CancelAsync, 0x800aff00, 0x800aff10);
asm UNKNOWN_FUNCTION(nw4r_ut_FileStream_CancelAsync) {
  // clang-format off
  nofralloc;
  li r3, 1;
  blr;
  // clang-format on
}

// Symbol: nw4r_ut_FilePosition_Skip
// Function signature is unknown.
// PAL: 0x800aff10..0x800aff80
MARK_BINARY_BLOB(nw4r_ut_FilePosition_Skip, 0x800aff10, 0x800aff80);
asm UNKNOWN_FUNCTION(nw4r_ut_FilePosition_Skip) {
  // clang-format off
  nofralloc;
  cmpwi r4, 0;
  beq lbl_800aff6c;
  lwz r0, 4(r3);
  li r5, 0;
  lwz r6, 0(r3);
  xoris r5, r5, 0x8000;
  add r7, r0, r4;
  subfc r0, r7, r6;
  subfe r0, r5, r5;
  subfe r0, r5, r5;
  neg. r0, r0;
  beq lbl_800aff44;
  b lbl_800aff68;
lbl_800aff44:
  li r6, 0;
  xoris r4, r6, 0x8000;
  subfc r0, r6, r7;
  subfe r4, r4, r5;
  subfe r4, r5, r5;
  neg. r4, r4;
  beq lbl_800aff64;
  b lbl_800aff68;
lbl_800aff64:
  mr r6, r7;
lbl_800aff68:
  stw r6, 4(r3);
lbl_800aff6c:
  lwz r3, 4(r3);
  blr;
  // clang-format on
}

// Symbol: nw4r_ut_FilePosition_Append
// Function signature is unknown.
// PAL: 0x800aff80..0x800affd0
MARK_BINARY_BLOB(nw4r_ut_FilePosition_Append, 0x800aff80, 0x800affd0);
asm UNKNOWN_FUNCTION(nw4r_ut_FilePosition_Append) {
  // clang-format off
  nofralloc;
  lwz r5, 4(r3);
  li r6, 0;
  xoris r0, r6, 0x8000;
  add r5, r5, r4;
  subfc r4, r6, r5;
  subfe r4, r0, r0;
  subfe r4, r0, r0;
  neg. r4, r4;
  beq lbl_800affb0;
  li r0, 0;
  stw r0, 4(r3);
  b lbl_800affc8;
lbl_800affb0:
  lwz r0, 0(r3);
  stw r5, 4(r3);
  cmplw r5, r0;
  bge lbl_800affc4;
  mr r5, r0;
lbl_800affc4:
  stw r5, 0(r3);
lbl_800affc8:
  lwz r3, 4(r3);
  blr;
  // clang-format on
}

// Symbol: nw4r_ut_FilePosition_Seek
// Function signature is unknown.
// PAL: 0x800affd0..0x800b0058
MARK_BINARY_BLOB(nw4r_ut_FilePosition_Seek, 0x800affd0, 0x800b0058);
asm UNKNOWN_FUNCTION(nw4r_ut_FilePosition_Seek) {
  // clang-format off
  nofralloc;
  cmpwi r5, 0;
  beq lbl_800affe4;
  cmplwi r5, 2;
  beq lbl_800afff0;
  b lbl_800afff8;
lbl_800affe4:
  li r0, 0;
  stw r0, 4(r3);
  b lbl_800afff8;
lbl_800afff0:
  lwz r0, 0(r3);
  stw r0, 4(r3);
lbl_800afff8:
  cmpwi r4, 0;
  beqlr;
  lwz r0, 4(r3);
  li r5, 0;
  lwz r6, 0(r3);
  xoris r5, r5, 0x8000;
  add r7, r0, r4;
  subfc r0, r7, r6;
  subfe r0, r5, r5;
  subfe r0, r5, r5;
  neg. r0, r0;
  beq lbl_800b002c;
  b lbl_800b0050;
lbl_800b002c:
  li r6, 0;
  xoris r4, r6, 0x8000;
  subfc r0, r6, r7;
  subfe r4, r4, r5;
  subfe r4, r5, r5;
  neg. r4, r4;
  beq lbl_800b004c;
  b lbl_800b0050;
lbl_800b004c:
  mr r6, r7;
lbl_800b0050:
  stw r6, 4(r3);
  blr;
  // clang-format on
}

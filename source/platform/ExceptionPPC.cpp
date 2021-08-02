#include "ExceptionPPC.h"

// Symbol: __register_fragment
// Function signature is unknown.
// PAL: 0x80020dd8..0x80020e0c
MARK_BINARY_BLOB(__register_fragment, 0x80020dd8, 0x80020e0c);
asm UNKNOWN_FUNCTION(__register_fragment) {
  // clang-format off
  nofralloc;
  lis r5, 0x802a;
  addi r5, r5, 0x6968;
  lwz r0, 8(r5);
  cmpwi r0, 0;
  bne lbl_80020e04;
  stw r3, 0(r5);
  li r0, 1;
  li r3, 0;
  stw r4, 4(r5);
  stw r0, 8(r5);
  blr;
lbl_80020e04:
  li r3, -1;
  blr;
  // clang-format on
}

// Symbol: __unregister_fragment
// Function signature is unknown.
// PAL: 0x80020e0c..0x80020e34
MARK_BINARY_BLOB(__unregister_fragment, 0x80020e0c, 0x80020e34);
asm UNKNOWN_FUNCTION(__unregister_fragment) {
  // clang-format off
  nofralloc;
  cmpwi r3, 0;
  bnelr;
  mulli r4, r3, 0xc;
  lis r3, 0x802a;
  li r0, 0;
  addi r3, r3, 0x6968;
  stwux r0, r3, r4;
  stw r0, 4(r3);
  stw r0, 8(r3);
  blr;
  // clang-format on
}

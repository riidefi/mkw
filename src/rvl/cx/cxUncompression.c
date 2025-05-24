#include "cxUncompression.h"

// Symbol: CXGetUncompressedSize
// PAL: 0x8015c2e0..0x8015c320
MARK_BINARY_BLOB(CXGetUncompressedSize, 0x8015c2e0, 0x8015c320);
asm UNKNOWN_FUNCTION(CXGetUncompressedSize) {
  // clang-format off
  nofralloc;
  lwz r5, 0(r3);
  rlwinm r4, r5, 8, 8, 0xf;
  rlwinm r0, r5, 0x18, 0x10, 0x17;
  rlwimi r4, r5, 0x18, 0, 7;
  rlwimi r0, r5, 8, 0x18, 0x1f;
  or r0, r4, r0;
  rlwinm. r0, r0, 0x18, 8, 0x1f;
  bne lbl_8015c318;
  lwz r4, 4(r3);
  rlwinm r3, r4, 8, 8, 0xf;
  rlwinm r0, r4, 0x18, 0x10, 0x17;
  rlwimi r3, r4, 0x18, 0, 7;
  rlwimi r0, r4, 8, 0x18, 0x1f;
  or r0, r3, r0;
lbl_8015c318:
  mr r3, r0;
  blr;
  // clang-format on
}

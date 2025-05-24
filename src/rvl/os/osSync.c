#include "osSync.h"

#include <string.h>

#include "osCache.h"

// Symbol: SystemCallVector
// PAL: 0x801a9528..0x801a9548
MARK_BINARY_BLOB(SystemCallVector, 0x801a9528, 0x801a9548);
asm UNKNOWN_FUNCTION(SystemCallVector) {
  // clang-format off
  nofralloc;
  mfspr r9, 0x3f0;
  ori r10, r9, 8;
  mtspr 0x3f0, r10;
  isync;
  sync;
  mtspr 0x3f0, r9;
  rfi;
  nop;
  // clang-format on
}

// Symbol: __OSInitSystemCall
// PAL: 0x801a9548..0x801a95a8
MARK_BINARY_BLOB(__OSInitSystemCall, 0x801a9548, 0x801a95a8);
asm UNKNOWN_FUNCTION(__OSInitSystemCall) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r4, 0x801b;
  lis r5, 0x801b;
  stw r0, 0x14(r1);
  addi r4, r4, -27352;
  addi r5, r5, -27324;
  stw r31, 0xc(r1);
  lis r31, 0x8000;
  addi r3, r31, 0xc00;
  subf r5, r4, r5;
  bl memcpy;
  addi r3, r31, 0xc00;
  li r4, 0x100;
  bl DCFlushRangeNoSync;
  sync;
  addi r3, r31, 0xc00;
  li r4, 0x100;
  bl ICInvalidateRange;
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

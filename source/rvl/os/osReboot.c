#include "osReboot.h"

#include "osArena.h"
#include "osInterrupt.h"

// Extern function references.
// PAL: 0x801a4648
extern UNKNOWN_FUNCTION(__OSBootDol);

u32 _unk_80386904;
u32 _unk_80386900;

// Symbol: __OSReboot
// PAL: 0x801a81b8..0x801a8224
MARK_BINARY_BLOB(__OSReboot, 0x801a81b8, 0x801a8224);
asm UNKNOWN_FUNCTION(__OSReboot) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r4;
  stw r30, 0x18(r1);
  mr r30, r3;
  bl OSDisableInterrupts;
  lis r3, 0x8128;
  bl OSSetArenaLo;
  lis r3, 0x812f;
  bl OSSetArenaHi;
  li r0, 0;
  lis r6, 0x8000;
  stw r0, 8(r1);
  mr r3, r31;
  oris r4, r30, 0x8000;
  addi r5, r1, 8;
  lwz r0, 0x3194(r6);
  stw r0, -0x6340(r13);
  bl __OSBootDol;
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: OSGetSaveRegion
// PAL: 0x801a8224..0x801a8238
MARK_BINARY_BLOB(OSGetSaveRegion, 0x801a8224, 0x801a8238);
asm UNKNOWN_FUNCTION(OSGetSaveRegion) {
  // clang-format off
  nofralloc;
  lwz r0, _unk_80386900;
  stw r0, 0(r3);
  lwz r0, _unk_80386904;
  stw r0, 0(r4);
  blr;
  // clang-format on
}

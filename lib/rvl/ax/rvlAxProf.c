#include "prof.h"

u32 __AXProfileInitialized = 0;
u32 __AXCurrentProfile = 0;
u32 __AXMaxProfiles = 0;
u32 __AXProfile = 0;

// Symbol: __AXGetCurrentProfile
// PAL: 0x80127fec..0x8012802c
MARK_BINARY_BLOB(__AXGetCurrentProfile, 0x80127fec, 0x8012802c);
asm UNKNOWN_FUNCTION(__AXGetCurrentProfile) {
  // clang-format off
  nofralloc;
  lwz r0, __AXProfileInitialized;
  cmpwi r0, 0;
  beq lbl_80128024;
  lwz r5, __AXCurrentProfile;
  lwz r3, __AXMaxProfiles;
  addi r4, r5, 1;
  lwz r6, __AXProfile;
  divwu r0, r4, r3;
  mullw r0, r0, r3;
  mulli r3, r5, 0x38;
  subf r0, r0, r4;
  stw r0, __AXCurrentProfile;
  add r3, r6, r3;
  blr;
lbl_80128024:
  li r3, 0;
  blr;
  // clang-format on
}

#include "bte_init.h"

// Extern function references.
// PAL: 0x80143460
extern UNKNOWN_FUNCTION(GAP_Init);
// PAL: 0x80146d34
extern UNKNOWN_FUNCTION(HID_DevInit);
// PAL: 0x801477b8
extern UNKNOWN_FUNCTION(HID_HostInit);
// PAL: 0x80150188
extern UNKNOWN_FUNCTION(RFCOMM_Init);

// Symbol: BTE_InitStack
// PAL: 0x80131658..0x80131684
MARK_BINARY_BLOB(BTE_InitStack, 0x80131658, 0x80131684);
asm UNKNOWN_FUNCTION(BTE_InitStack) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  bl RFCOMM_Init;
  bl GAP_Init;
  bl HID_DevInit;
  bl HID_HostInit;
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

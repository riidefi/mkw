#include "btu_init.h"

#include <string.h>

#include "btm_discovery.h"
#include "btm_main.h"
#include "l2c_main.h"
#include "sdp_main.h"

// Symbol: btu_init_core
// PAL: 0x80143308..0x80143334
MARK_BINARY_BLOB(btu_init_core, 0x80143308, 0x80143334);
asm UNKNOWN_FUNCTION(btu_init_core) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  bl btm_init;
  bl l2c_init;
  bl sdp_init;
  bl btm_discovery_db_init;
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: BTE_Init
// PAL: 0x80143334..0x80143380
MARK_BINARY_BLOB(BTE_Init, 0x80143334, 0x80143380);
asm UNKNOWN_FUNCTION(BTE_Init) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  li r4, 0;
  li r5, 0x84;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  lis r31, 0x8033;
  addi r3, r31, 0x5d50;
  bl memset;
  addi r3, r31, 0x5d50;
  li r4, 0x2a4;
  li r0, 1;
  sth r4, 0x7e(r3);
  sth r0, 0x80(r3);
  lwz r31, 0xc(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

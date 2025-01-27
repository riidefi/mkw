#include "btm_discovery.h"

#include <string.h>

#include "bte_task1.h"
#include "sdp_api.h"

// Symbol: btm_discovery_db_init
// PAL: 0x8013b9f4..0x8013ba6c
MARK_BINARY_BLOB(btm_discovery_db_init, 0x8013b9f4, 0x8013ba6c);
asm UNKNOWN_FUNCTION(btm_discovery_db_init) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  li r4, 0;
  li r5, 0x1020;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  lis r31, 0x8033;
  addi r31, r31, 0x6278;
  addi r0, r31, 0x6d4;
  stw r0, 0x1678(r31);
  addi r3, r31, 0x658;
  bl memset;
  li r3, 1;
  li r4, 2;
  li r0, 0x1002;
  sth r3, 0x670(r31);
  lwz r3, 0x1678(r31);
  addi r6, r31, 0x674;
  sth r4, 0x674(r31);
  li r4, 0xfa0;
  li r5, 1;
  li r7, 0;
  sth r0, 0x678(r31);
  li r8, 0;
  bl SDP_InitDiscoveryDb;
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: btm_discovery_db_reset
// PAL: 0x8013ba6c..0x8013bb24
MARK_BINARY_BLOB(btm_discovery_db_reset, 0x8013ba6c, 0x8013bb24);
asm UNKNOWN_FUNCTION(btm_discovery_db_reset) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  lis r31, 0x8033;
  addi r31, r31, 0x6278;
  addi r3, r31, 0x658;
  bl btu_stop_timer;
  lbz r0, 0x1674(r31);
  cmpwi r0, 0;
  beq lbl_8013babc;
  lwz r12, 0x6d0(r31);
  li r0, 0;
  stb r0, 0x1674(r31);
  cmpwi r12, 0;
  stw r0, 0x6d0(r31);
  beq lbl_8013babc;
  li r3, 0;
  mtctr r12;
  bctrl;
lbl_8013babc:
  lis r31, 0x8033;
  li r4, 0;
  addi r31, r31, 0x6278;
  li r5, 0x1020;
  addi r0, r31, 0x6d4;
  stw r0, 0x1678(r31);
  addi r3, r31, 0x658;
  bl memset;
  li r3, 1;
  li r4, 2;
  li r0, 0x1002;
  sth r3, 0x670(r31);
  lwz r3, 0x1678(r31);
  addi r6, r31, 0x674;
  sth r4, 0x674(r31);
  li r4, 0xfa0;
  li r5, 1;
  li r7, 0;
  sth r0, 0x678(r31);
  li r8, 0;
  bl SDP_InitDiscoveryDb;
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: btm_discovery_timeout
// PAL: 0x8013bb24..0x8013bb28
MARK_BINARY_BLOB(btm_discovery_timeout, 0x8013bb24, 0x8013bb28);
asm UNKNOWN_FUNCTION(btm_discovery_timeout) {
  // clang-format off
  nofralloc;
  blr;
  // clang-format on
}

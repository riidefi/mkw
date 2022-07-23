#include "bta_dm_main.h"

// Symbol: bta_dm_sm_execute
// PAL: 0x80134cc8..0x80134d60
MARK_BINARY_BLOB(bta_dm_sm_execute, 0x80134cc8, 0x80134d60);
asm UNKNOWN_FUNCTION(bta_dm_sm_execute) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  lis r31, 0x8025;
  addi r31, r31, -14272;
  stw r30, 0x18(r1);
  lis r30, 0x8025;
  addi r30, r30, -14220;
  stw r29, 0x14(r1);
  li r29, 0;
  stw r28, 0x10(r1);
  mr r28, r3;
lbl_80134cfc:
  lhz r3, 0(r28);
  add r0, r29, r30;
  clrlwi r4, r3, 0x18;
  rlwinm r3, r3, 2, 0x16, 0x1d;
  subf r3, r4, r3;
  lbzx r0, r3, r0;
  cmplwi r0, 0xd;
  beq lbl_80134d3c;
  rlwinm r0, r0, 2, 0x16, 0x1d;
  mr r3, r28;
  lwzx r12, r31, r0;
  mtctr r12;
  bctrl;
  addi r29, r29, 1;
  cmpwi r29, 2;
  blt lbl_80134cfc;
lbl_80134d3c:
  lwz r31, 0x1c(r1);
  li r3, 1;
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  lwz r28, 0x10(r1);
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: bta_dm_search_sm_execute
// PAL: 0x80134d60..0x80134e28
MARK_BINARY_BLOB(bta_dm_search_sm_execute, 0x80134d60, 0x80134e28);
asm UNKNOWN_FUNCTION(bta_dm_search_sm_execute) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  lis r7, 0x8033;
  lis r5, 0x8025;
  stw r0, 0x24(r1);
  addi r7, r7, 0x5e98;
  addi r5, r5, -13992;
  stw r31, 0x1c(r1);
  lis r31, 0x8025;
  addi r31, r31, -14176;
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  li r29, 0;
  stw r28, 0x10(r1);
  mr r28, r3;
  lhz r6, 0x18(r7);
  lhz r0, 0(r3);
  slwi r6, r6, 2;
  clrlwi r4, r0, 0x18;
  rlwinm r0, r0, 2, 0x16, 0x1d;
  lwzx r30, r5, r6;
  subf r0, r4, r0;
  add r3, r30, r0;
  lbz r0, 2(r3);
  sth r0, 0x18(r7);
lbl_80134dc4:
  lhz r3, 0(r28);
  add r0, r29, r30;
  clrlwi r4, r3, 0x18;
  rlwinm r3, r3, 2, 0x16, 0x1d;
  subf r3, r4, r3;
  lbzx r0, r3, r0;
  cmplwi r0, 0x12;
  beq lbl_80134e04;
  rlwinm r0, r0, 2, 0x16, 0x1d;
  mr r3, r28;
  lwzx r12, r31, r0;
  mtctr r12;
  bctrl;
  addi r29, r29, 1;
  cmpwi r29, 2;
  blt lbl_80134dc4;
lbl_80134e04:
  lwz r31, 0x1c(r1);
  li r3, 1;
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  lwz r28, 0x10(r1);
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

#include "btm_pm.h"

#include <string.h>

#include "gki_buffer.h"
#include "bte_logmsg.h"
#include "btm_acl.h"
#include "btm_dev.h"
#include "btm_devctl.h"
#include "btm_sco.h"
#include "hcicmds.h"

// Symbol: BTM_PmRegister
// PAL: 0x8013d61c..0x8013d6d8
MARK_BINARY_BLOB(BTM_PmRegister, 0x8013d61c, 0x8013d6d8);
asm UNKNOWN_FUNCTION(BTM_PmRegister) {
  // clang-format off
  nofralloc;
  rlwinm. r0, r3, 0, 0x1d, 0x1d;
  beq lbl_8013d658;
  lbz r0, 0(r4);
  cmplwi r0, 2;
  blt lbl_8013d638;
  li r3, 5;
  blr;
lbl_8013d638:
  lis r3, 0x8033;
  rlwinm r0, r0, 3, 0x15, 0x1c;
  addi r3, r3, 0x6278;
  li r5, 0;
  add r4, r3, r0;
  stb r5, 0x558(r4);
  li r3, 0;
  blr;
lbl_8013d658:
  lis r6, 0x8033;
  li r0, 2;
  addi r6, r6, 0x6278;
  li r7, 0;
  mtctr r0;
lbl_8013d66c:
  lbz r0, 0x558(r6);
  cmpwi r0, 0;
  bne lbl_8013d6c4;
  rlwinm. r0, r3, 0, 0x1e, 0x1e;
  beq lbl_8013d6a4;
  cmpwi r5, 0;
  bne lbl_8013d690;
  li r3, 5;
  blr;
lbl_8013d690:
  lis r6, 0x8033;
  slwi r0, r7, 3;
  addi r6, r6, 0x6278;
  add r6, r6, r0;
  stw r5, 0x554(r6);
lbl_8013d6a4:
  lis r5, 0x8033;
  slwi r0, r7, 3;
  addi r5, r5, 0x6278;
  add r5, r5, r0;
  stb r3, 0x558(r5);
  li r3, 0;
  stb r7, 0(r4);
  blr;
lbl_8013d6c4:
  addi r6, r6, 8;
  addi r7, r7, 1;
  bdnz lbl_8013d66c;
  li r3, 3;
  blr;
  // clang-format on
}

// Symbol: BTM_SetPowerMode
// PAL: 0x8013d6d8..0x8013d8a8
MARK_BINARY_BLOB(BTM_SetPowerMode, 0x8013d6d8, 0x8013d8a8);
asm UNKNOWN_FUNCTION(BTM_SetPowerMode) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_26;
  cmplwi r3, 2;
  mr r27, r3;
  mr r26, r4;
  mr r28, r5;
  blt lbl_8013d704;
  li r27, 0x80;
lbl_8013d704:
  cmpwi r5, 0;
  bne lbl_8013d714;
  li r3, 5;
  b lbl_8013d890;
lbl_8013d714:
  lbz r0, 8(r5);
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  li r29, 0;
  rlwinm r31, r0, 0, 0x1c, 0x1a;
  addi r30, r3, 0x34;
lbl_8013d72c:
  lbz r0, 0x119(r30);
  cmpwi r0, 0;
  beq lbl_8013d750;
  mr r4, r26;
  addi r3, r30, 8;
  li r5, 6;
  bl memcmp;
  cmpwi r3, 0;
  beq lbl_8013d760;
lbl_8013d750:
  addi r29, r29, 1;
  addi r30, r30, 0x11c;
  cmplwi r29, 4;
  blt lbl_8013d72c;
lbl_8013d760:
  clrlwi r30, r29, 0x18;
  cmpwi r30, 4;
  bne lbl_8013d774;
  li r3, 7;
  b lbl_8013d890;
lbl_8013d774:
  mulli r0, r30, 0x22;
  lis r4, 0x8033;
  clrlwi. r3, r31, 0x18;
  addi r4, r4, 0x6278;
  add r4, r4, r0;
  addi r29, r4, 0x4cc;
  beq lbl_8013d7bc;
  addi r26, r3, -1;
  bl BTM_ReadLocalFeatures;
  addi r4, r2, -26880;
  addi r5, r2, -26876;
  lbzx r0, r4, r26;
  lbzx r4, r5, r26;
  lbzx r0, r3, r0;
  and. r0, r4, r0;
  bne lbl_8013d7bc;
  li r3, 4;
  b lbl_8013d890;
lbl_8013d7bc:
  lbz r0, 0x20(r29);
  clrlwi r3, r31, 0x18;
  cmplw r3, r0;
  bne lbl_8013d7f8;
  cmpwi r3, 0;
  beq lbl_8013d7f0;
  lhz r3, 0x1e(r29);
  lhz r0, 0(r28);
  cmplw r0, r3;
  blt lbl_8013d7f8;
  lhz r0, 2(r28);
  cmplw r0, r3;
  bgt lbl_8013d7f8;
lbl_8013d7f0:
  li r3, 0;
  b lbl_8013d890;
lbl_8013d7f8:
  cmplwi r27, 0x80;
  beq lbl_8013d850;
  lis r3, 0x8033;
  rlwinm r0, r27, 3, 0x15, 0x1c;
  addi r3, r3, 0x6278;
  add r3, r3, r0;
  lbz r0, 0x558(r3);
  clrlwi. r0, r0, 0x1f;
  beq lbl_8013d850;
  lhz r4, 0(r28);
  mulli r5, r27, 0xa;
  lhz r3, 2(r28);
  li r0, 1;
  sthux r4, r5, r29;
  sth r3, 2(r5);
  lhz r4, 4(r28);
  lhz r3, 6(r28);
  sth r4, 4(r5);
  sth r3, 6(r5);
  lhz r3, 8(r28);
  sth r3, 8(r5);
  stb r0, 0x21(r29);
lbl_8013d850:
  lbz r0, 0x20(r29);
  cmplwi r0, 1;
  beq lbl_8013d878;
  cmplwi r0, 4;
  beq lbl_8013d878;
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lbz r0, 0x564(r3);
  cmplwi r0, 4;
  beq lbl_8013d880;
lbl_8013d878:
  li r3, 0xd;
  b lbl_8013d890;
lbl_8013d880:
  mr r3, r27;
  mr r4, r30;
  mr r5, r28;
  bl btm_pm_snd_md_req;
lbl_8013d890:
  addi r11, r1, 0x20;
  bl _restgpr_26;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: BTM_ReadPowerMode
// PAL: 0x8013d8a8..0x8013d960
MARK_BINARY_BLOB(BTM_ReadPowerMode, 0x8013d8a8, 0x8013d960);
asm UNKNOWN_FUNCTION(BTM_ReadPowerMode) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  lis r5, 0x8033;
  stw r0, 0x24(r1);
  addi r5, r5, 0x6278;
  stw r31, 0x1c(r1);
  li r31, 0;
  stw r30, 0x18(r1);
  addi r30, r5, 0x34;
  stw r29, 0x14(r1);
  mr r29, r4;
  stw r28, 0x10(r1);
  mr r28, r3;
lbl_8013d8dc:
  lbz r0, 0x119(r30);
  cmpwi r0, 0;
  beq lbl_8013d900;
  mr r4, r28;
  addi r3, r30, 8;
  li r5, 6;
  bl memcmp;
  cmpwi r3, 0;
  beq lbl_8013d910;
lbl_8013d900:
  addi r31, r31, 1;
  addi r30, r30, 0x11c;
  cmplwi r31, 4;
  blt lbl_8013d8dc;
lbl_8013d910:
  clrlwi r0, r31, 0x18;
  cmpwi r0, 4;
  bne lbl_8013d924;
  li r3, 7;
  b lbl_8013d940;
lbl_8013d924:
  mulli r0, r0, 0x22;
  lis r4, 0x8033;
  li r3, 0;
  addi r4, r4, 0x6278;
  add r4, r4, r0;
  lbz r0, 0x4ec(r4);
  stb r0, 0(r29);
lbl_8013d940:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  lwz r28, 0x10(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: btm_pm_reset
// PAL: 0x8013d960..0x8013d9d8
MARK_BINARY_BLOB(btm_pm_reset, 0x8013d960, 0x8013d9d8);
asm UNKNOWN_FUNCTION(btm_pm_reset) {
  // clang-format off
  nofralloc;
  lis r3, 0x8033;
  li r12, 0;
  addi r3, r3, 0x6278;
  lbz r0, 0x565(r3);
  cmplwi r0, 0x80;
  beq lbl_8013d990;
  rlwinm r0, r0, 3, 0x15, 0x1c;
  add r3, r3, r0;
  lbz r0, 0x558(r3);
  rlwinm. r0, r0, 0, 0x1e, 0x1e;
  beq lbl_8013d990;
  lwz r12, 0x554(r3);
lbl_8013d990:
  lis r3, 0x8033;
  cmpwi r12, 0;
  addi r3, r3, 0x6278;
  li r0, 0;
  li r4, 4;
  stb r0, 0x558(r3);
  stb r4, 0x564(r3);
  stb r0, 0x560(r3);
  beqlr;
  mulli r0, r4, 0x11c;
  li r4, 5;
  li r5, 0xc;
  li r6, 0;
  add r3, r3, r0;
  addi r3, r3, 0x3c;
  mtctr r12;
  bctr;
  blr;
  // clang-format on
}

// Symbol: btm_pm_sm_alloc
// PAL: 0x8013d9d8..0x8013da28
MARK_BINARY_BLOB(btm_pm_sm_alloc, 0x8013d9d8, 0x8013da28);
asm UNKNOWN_FUNCTION(btm_pm_sm_alloc) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  li r4, 0;
  li r5, 0x22;
  stw r0, 0x14(r1);
  mulli r0, r3, 0x22;
  lis r3, 0x8033;
  stw r31, 0xc(r1);
  addi r3, r3, 0x6278;
  add r3, r3, r0;
  addi r31, r3, 0x4cc;
  mr r3, r31;
  bl memset;
  li r0, 0;
  stb r0, 0x20(r31);
  lwz r31, 0xc(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: btm_pm_compare_modes
// PAL: 0x8013da28..0x8013dc44
MARK_BINARY_BLOB(btm_pm_compare_modes, 0x8013da28, 0x8013dc44);
asm UNKNOWN_FUNCTION(btm_pm_compare_modes) {
  // clang-format off
  nofralloc;
  cmpwi r3, 0;
  bne lbl_8013da60;
  lhz r6, 0(r4);
  mr r3, r4;
  lhz r0, 2(r4);
  sth r6, 0(r5);
  sth r0, 2(r5);
  lhz r6, 4(r4);
  lhz r0, 6(r4);
  sth r6, 4(r5);
  sth r0, 6(r5);
  lhz r0, 8(r4);
  sth r0, 8(r5);
  blr;
lbl_8013da60:
  lbz r9, 8(r4);
  cmpwi r9, 0;
  beq lbl_8013da78;
  lbz r8, 8(r3);
  cmpwi r8, 0;
  bne lbl_8013da80;
lbl_8013da78:
  li r3, 0;
  blr;
lbl_8013da80:
  rlwinm. r0, r8, 0, 0x1b, 0x1b;
  beq lbl_8013dac4;
  lhz r4, 0(r3);
  lhz r0, 2(r3);
  sth r4, 0(r5);
  sth r0, 2(r5);
  lhz r4, 4(r3);
  lhz r0, 6(r3);
  sth r4, 4(r5);
  sth r0, 6(r5);
  lhz r0, 8(r3);
  mr r3, r5;
  sth r0, 8(r5);
  lbz r0, 8(r5);
  rlwinm r0, r0, 0, 0x1c, 0x1a;
  stb r0, 8(r5);
  blr;
lbl_8013dac4:
  rlwinm. r0, r9, 0, 0x1b, 0x1b;
  beq lbl_8013db08;
  lhz r6, 0(r4);
  mr r3, r5;
  lhz r0, 2(r4);
  sth r6, 0(r5);
  sth r0, 2(r5);
  lhz r6, 4(r4);
  lhz r0, 6(r4);
  sth r6, 4(r5);
  sth r0, 6(r5);
  lhz r0, 8(r4);
  sth r0, 8(r5);
  lbz r0, 8(r5);
  rlwinm r0, r0, 0, 0x1c, 0x1a;
  stb r0, 8(r5);
  blr;
lbl_8013db08:
  addi r7, r8, -1;
  lis r6, 0x8025;
  slwi r0, r7, 2;
  subf r0, r7, r0;
  addi r6, r6, -13840;
  add r7, r9, r0;
  addi r0, r7, -1;
  clrlwi r0, r0, 0x18;
  lbzx r0, r6, r0;
  cmpwi r0, 2;
  beq lbl_8013db7c;
  bge lbl_8013db44;
  cmpwi r0, 1;
  bge lbl_8013db50;
  b lbl_8013dc3c;
lbl_8013db44:
  cmpwi r0, 4;
  bge lbl_8013dc3c;
  b lbl_8013dbac;
lbl_8013db50:
  lhz r4, 0(r3);
  lhz r0, 2(r3);
  sth r4, 0(r5);
  sth r0, 2(r5);
  lhz r4, 4(r3);
  lhz r0, 6(r3);
  sth r4, 4(r5);
  sth r0, 6(r5);
  lhz r0, 8(r3);
  sth r0, 8(r5);
  blr;
lbl_8013db7c:
  lhz r6, 0(r4);
  mr r3, r4;
  lhz r0, 2(r4);
  sth r6, 0(r5);
  sth r0, 2(r5);
  lhz r6, 4(r4);
  lhz r0, 6(r4);
  sth r6, 4(r5);
  sth r0, 6(r5);
  lhz r0, 8(r4);
  sth r0, 8(r5);
  blr;
lbl_8013dbac:
  stb r8, 8(r5);
  lhz r6, 0(r4);
  lhz r0, 0(r3);
  cmplw r0, r6;
  bge lbl_8013dbc4;
  mr r6, r0;
lbl_8013dbc4:
  sth r6, 0(r5);
  lhz r7, 2(r4);
  lhz r0, 2(r3);
  cmplw r0, r7;
  ble lbl_8013dbdc;
  mr r7, r0;
lbl_8013dbdc:
  lhz r6, 0(r5);
  clrlwi r0, r7, 0x10;
  sth r7, 2(r5);
  cmplw r6, r0;
  bge lbl_8013dbf8;
  li r3, 0;
  blr;
lbl_8013dbf8:
  lbz r0, 8(r5);
  cmplwi r0, 2;
  bne lbl_8013dc34;
  lhz r6, 4(r4);
  lhz r0, 4(r3);
  cmplw r0, r6;
  ble lbl_8013dc18;
  mr r6, r0;
lbl_8013dc18:
  sth r6, 4(r5);
  lhz r4, 6(r4);
  lhz r0, 6(r3);
  cmplw r0, r4;
  ble lbl_8013dc30;
  mr r4, r0;
lbl_8013dc30:
  sth r4, 6(r5);
lbl_8013dc34:
  mr r3, r5;
  blr;
lbl_8013dc3c:
  li r3, 0;
  blr;
  // clang-format on
}

// Symbol: btm_pm_get_set_mode
// PAL: 0x8013dc44..0x8013dda4
MARK_BINARY_BLOB(btm_pm_get_set_mode, 0x8013dc44, 0x8013dda4);
asm UNKNOWN_FUNCTION(btm_pm_get_set_mode) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_26;
  cmpwi r5, 0;
  mr r26, r3;
  mr r27, r5;
  mr r28, r6;
  li r7, 0;
  beq lbl_8013dcb4;
  lbz r0, 8(r5);
  rlwinm. r0, r0, 0, 0x1b, 0x1b;
  beq lbl_8013dcb4;
  lhz r3, 0(r5);
  lhz r0, 2(r5);
  sth r3, 0(r6);
  sth r0, 2(r6);
  lhz r3, 4(r5);
  lhz r0, 6(r5);
  sth r3, 4(r6);
  sth r0, 6(r6);
  lhz r0, 8(r5);
  sth r0, 8(r6);
  lbz r0, 8(r6);
  rlwinm r3, r0, 0, 0x1c, 0x1a;
  stb r3, 8(r6);
  b lbl_8013dd8c;
lbl_8013dcb4:
  lis r31, 0x8033;
  mr r30, r4;
  addi r31, r31, 0x6278;
  li r29, 0;
lbl_8013dcc4:
  lbz r0, 0x558(r31);
  clrlwi. r0, r0, 0x1f;
  beq lbl_8013dd08;
  lbz r0, 8(r30);
  cmpwi r0, 0;
  bne lbl_8013dce4;
  li r3, 0;
  b lbl_8013dd8c;
lbl_8013dce4:
  mr r3, r7;
  mr r4, r30;
  mr r5, r28;
  bl btm_pm_compare_modes;
  cmpwi r3, 0;
  bne lbl_8013dd04;
  li r3, 0;
  b lbl_8013dd8c;
lbl_8013dd04:
  mr r7, r28;
lbl_8013dd08:
  addi r29, r29, 1;
  addi r30, r30, 0xa;
  cmpwi r29, 2;
  addi r31, r31, 8;
  blt lbl_8013dcc4;
  cmpwi r7, 0;
  bne lbl_8013dd60;
  cmpwi r27, 0;
  beq lbl_8013dd58;
  lhz r3, 0(r27);
  lhz r0, 2(r27);
  sth r3, 0(r28);
  sth r0, 2(r28);
  lhz r3, 4(r27);
  lhz r0, 6(r27);
  sth r3, 4(r28);
  sth r0, 6(r28);
  lhz r0, 8(r27);
  sth r0, 8(r28);
  b lbl_8013dd88;
lbl_8013dd58:
  li r3, 0;
  b lbl_8013dd8c;
lbl_8013dd60:
  cmplwi r26, 0x80;
  bne lbl_8013dd88;
  mr r3, r27;
  mr r4, r7;
  mr r5, r28;
  bl btm_pm_compare_modes;
  cmpwi r3, 0;
  bne lbl_8013dd88;
  li r3, 0;
  b lbl_8013dd8c;
lbl_8013dd88:
  lbz r3, 8(r28);
lbl_8013dd8c:
  addi r11, r1, 0x20;
  bl _restgpr_26;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: btm_pm_snd_md_req
// PAL: 0x8013dda4..0x8013dfd8
MARK_BINARY_BLOB(btm_pm_snd_md_req, 0x8013dda4, 0x8013dfd8);
asm UNKNOWN_FUNCTION(btm_pm_snd_md_req) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  lis r6, 0x8033;
  stw r0, 0x34(r1);
  mulli r0, r4, 0x22;
  addi r6, r6, 0x6278;
  stw r31, 0x2c(r1);
  li r31, 0;
  stw r30, 0x28(r1);
  mr r30, r4;
  stw r29, 0x24(r1);
  mr r29, r3;
  add r3, r6, r0;
  addi r6, r1, 8;
  stw r28, 0x20(r1);
  addi r28, r3, 0x4cc;
  mr r3, r29;
  mr r4, r28;
  bl btm_pm_get_set_mode;
  lbz r4, 0x20(r28);
  clrlwi r0, r3, 0x18;
  stb r3, 0x10(r1);
  cmplw r4, r0;
  bne lbl_8013de34;
  cmpwi r0, 0;
  beq lbl_8013de28;
  lhz r4, 0x1e(r28);
  lhz r0, 8(r1);
  cmplw r0, r4;
  blt lbl_8013de30;
  lhz r0, 0xa(r1);
  cmplw r0, r4;
  bgt lbl_8013de30;
lbl_8013de28:
  li r3, 0xd;
  b lbl_8013dfb8;
lbl_8013de30:
  li r31, 1;
lbl_8013de34:
  clrlwi. r0, r3, 0x18;
  stb r31, 0x21(r28);
  beq lbl_8013de54;
  lbz r0, 0x20(r28);
  cmpwi r0, 0;
  beq lbl_8013de54;
  li r0, 1;
  stb r0, 0x21(r28);
lbl_8013de54:
  li r3, 2;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  mr r31, r3;
  bne lbl_8013de70;
  li r3, 3;
  b lbl_8013dfb8;
lbl_8013de70:
  lbz r0, 0x21(r28);
  cmplwi r0, 1;
  bne lbl_8013de84;
  li r0, 0;
  stb r0, 0x10(r1);
lbl_8013de84:
  lbz r0, 0x10(r1);
  lis r4, 0x8033;
  addi r4, r4, 0x6278;
  cmpwi r0, 2;
  stb r30, 0x564(r4);
  stb r29, 0x565(r4);
  beq lbl_8013df40;
  bge lbl_8013deb4;
  cmpwi r0, 0;
  beq lbl_8013dec0;
  bge lbl_8013df20;
  b lbl_8013df88;
lbl_8013deb4:
  cmpwi r0, 4;
  bge lbl_8013df88;
  b lbl_8013df68;
lbl_8013dec0:
  lbz r0, 0x20(r28);
  cmpwi r0, 3;
  beq lbl_8013def4;
  bge lbl_8013df0c;
  cmpwi r0, 2;
  bge lbl_8013dedc;
  b lbl_8013df0c;
lbl_8013dedc:
  mulli r0, r30, 0x11c;
  mr r3, r31;
  add r4, r4, r0;
  lhz r4, 0x34(r4);
  bl btsnd_hcic_exit_sniff_mode;
  b lbl_8013df98;
lbl_8013def4:
  mulli r0, r30, 0x11c;
  mr r3, r31;
  add r4, r4, r0;
  lhz r4, 0x34(r4);
  bl btsnd_hcic_exit_park_mode;
  b lbl_8013df98;
lbl_8013df0c:
  lis r3, 0x8033;
  li r0, 4;
  addi r3, r3, 0x6278;
  stb r0, 0x564(r3);
  b lbl_8013df98;
lbl_8013df20:
  mulli r0, r30, 0x11c;
  lhz r5, 8(r1);
  lhz r6, 0xa(r1);
  mr r3, r31;
  add r4, r4, r0;
  lhz r4, 0x34(r4);
  bl btsnd_hcic_hold_mode;
  b lbl_8013df98;
lbl_8013df40:
  mulli r0, r30, 0x11c;
  lhz r5, 8(r1);
  lhz r6, 0xa(r1);
  mr r3, r31;
  lhz r7, 0xc(r1);
  add r4, r4, r0;
  lhz r4, 0x34(r4);
  lhz r8, 0xe(r1);
  bl btsnd_hcic_sniff_mode;
  b lbl_8013df98;
lbl_8013df68:
  mulli r0, r30, 0x11c;
  lhz r5, 8(r1);
  lhz r6, 0xa(r1);
  mr r3, r31;
  add r4, r4, r0;
  lhz r4, 0x34(r4);
  bl btsnd_hcic_park_mode;
  b lbl_8013df98;
lbl_8013df88:
  lis r3, 0x8033;
  li r0, 4;
  addi r3, r3, 0x6278;
  stb r0, 0x564(r3);
lbl_8013df98:
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lbz r0, 0x564(r3);
  cmplwi r0, 4;
  bne lbl_8013dfb4;
  mr r3, r31;
  bl GKI_freebuf;
lbl_8013dfb4:
  li r3, 1;
lbl_8013dfb8:
  lwz r0, 0x34(r1);
  lwz r31, 0x2c(r1);
  lwz r30, 0x28(r1);
  lwz r29, 0x24(r1);
  lwz r28, 0x20(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: btm_pm_proc_cmd_status
// PAL: 0x8013dfd8..0x8013e088
MARK_BINARY_BLOB(btm_pm_proc_cmd_status, 0x8013dfd8, 0x8013e088);
asm UNKNOWN_FUNCTION(btm_pm_proc_cmd_status) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r4, 0x8033;
  stw r0, 0x14(r1);
  addi r4, r4, 0x6278;
  lbz r0, 0x564(r4);
  cmplwi r0, 4;
  bge lbl_8013e078;
  mulli r0, r0, 0x22;
  cmpwi r3, 0;
  add r5, r4, r0;
  bne lbl_8013e018;
  li r0, 4;
  li r4, 4;
  stb r0, 0x4ec(r5);
  b lbl_8013e01c;
lbl_8013e018:
  li r4, 5;
lbl_8013e01c:
  lis r7, 0x8033;
  addi r7, r7, 0x6278;
  lbz r0, 0x565(r7);
  cmplwi r0, 0x80;
  beq lbl_8013e068;
  rlwinm r0, r0, 3, 0x15, 0x1c;
  add r5, r7, r0;
  lbz r0, 0x558(r5);
  rlwinm. r0, r0, 0, 0x1e, 0x1e;
  beq lbl_8013e068;
  lbz r0, 0x564(r7);
  mr r6, r3;
  lwz r12, 0x554(r5);
  li r5, 0;
  mulli r0, r0, 0x11c;
  add r3, r7, r0;
  addi r3, r3, 0x3c;
  mtctr r12;
  bctrl;
lbl_8013e068:
  lis r3, 0x8033;
  li r0, 4;
  addi r3, r3, 0x6278;
  stb r0, 0x564(r3);
lbl_8013e078:
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: btm_pm_proc_mode_change
// PAL: 0x8013e088..0x8013e2b0
MARK_BINARY_BLOB(btm_pm_proc_mode_change, 0x8013e088, 0x8013e2b0);
asm UNKNOWN_FUNCTION(btm_pm_proc_mode_change) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_24;
  mr r26, r4;
  mr r25, r3;
  mr r27, r5;
  mr r28, r6;
  mr r3, r26;
  bl btm_handle_to_acl_index;
  clrlwi r29, r3, 0x18;
  cmpwi r29, 4;
  bge lbl_8013e298;
  mulli r30, r29, 0x11c;
  lis r24, 0x8033;
  cmpwi r27, 0;
  addi r24, r24, 0x6278;
  add r31, r24, r30;
  bne lbl_8013e12c;
  lhz r0, 0x38(r31);
  cmpwi r0, 0;
  beq lbl_8013e12c;
  bl btm_num_sco_links_active;
  clrlwi. r0, r3, 0x18;
  bne lbl_8013e12c;
  li r0, 0;
  sth r0, 0x38(r31);
  lbz r0, 0x27c0(r24);
  cmplwi r0, 5;
  blt lbl_8013e120;
  lis r3, 0xd;
  lis r4, 0x8028;
  lhz r6, 0x36(r31);
  mr r5, r26;
  addi r3, r3, 4;
  addi r4, r4, 0x3db0;
  bl LogMsg_2;
lbl_8013e120:
  lhz r3, 0x34(r31);
  lhz r4, 0x36(r31);
  bl btsnd_hcic_change_conn_type;
lbl_8013e12c:
  mulli r0, r29, 0x22;
  lis r3, 0x8033;
  cmpwi r27, 0;
  addi r3, r3, 0x6278;
  add r4, r3, r0;
  stb r27, 0x4ec(r4);
  li r0, 0;
  sth r28, 0x4ea(r4);
  bne lbl_8013e160;
  lbz r3, 0x4d4(r4);
  cmplwi r3, 1;
  bne lbl_8013e160;
  stb r0, 0x4d4(r4);
lbl_8013e160:
  cmpwi r27, 0;
  addi r5, r4, 0x4d6;
  bne lbl_8013e17c;
  lbz r3, 8(r5);
  cmplwi r3, 1;
  bne lbl_8013e17c;
  stb r0, 8(r5);
lbl_8013e17c:
  lbz r0, 0x4ed(r4);
  cmplwi r0, 1;
  bne lbl_8013e198;
  mr r4, r29;
  li r3, 0x80;
  li r5, 0;
  bl btm_pm_snd_md_req;
lbl_8013e198:
  lis r24, 0x8033;
  li r29, 0;
  addi r24, r24, 0x6278;
lbl_8013e1a4:
  lbz r0, 0x558(r24);
  rlwinm. r0, r0, 0, 0x1e, 0x1e;
  beq lbl_8013e1cc;
  lwz r12, 0x554(r24);
  mr r4, r27;
  mr r5, r28;
  mr r6, r25;
  addi r3, r31, 0x3c;
  mtctr r12;
  bctrl;
lbl_8013e1cc:
  addi r29, r29, 1;
  addi r24, r24, 8;
  cmpwi r29, 2;
  blt lbl_8013e1a4;
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  add r28, r3, r30;
  lbz r0, 0x14f(r28);
  cmplwi r0, 1;
  bne lbl_8013e298;
  addi r24, r28, 0x3c;
  mr r3, r24;
  bl btm_find_dev;
  cmpwi r3, 0;
  beq lbl_8013e234;
  lbz r0, 0x76(r3);
  rlwinm. r0, r0, 0, 0x1d, 0x1d;
  beq lbl_8013e234;
  mr r3, r26;
  li r4, 0;
  bl btsnd_hcic_set_conn_encrypt;
  clrlwi. r0, r3, 0x18;
  beq lbl_8013e268;
  li r0, 2;
  stb r0, 0x14f(r28);
  b lbl_8013e298;
lbl_8013e234:
  lis r4, 0x8033;
  mr r3, r24;
  addi r4, r4, 0x6278;
  add r4, r4, r30;
  lbz r0, 0x14e(r4);
  cntlzw r0, r0;
  rlwinm r4, r0, 0x1b, 0x18, 0x1f;
  bl btsnd_hcic_switch_role;
  clrlwi. r0, r3, 0x18;
  beq lbl_8013e268;
  li r0, 0;
  stb r0, 0x14f(r28);
  b lbl_8013e298;
lbl_8013e268:
  li r27, 0;
  lis r26, 0x8033;
  stb r27, 0x14f(r28);
  addi r26, r26, 0x6278;
  lwz r12, 0x62c(r26);
  cmpwi r12, 0;
  beq lbl_8013e298;
  stb r25, 0x624(r26);
  addi r3, r26, 0x624;
  mtctr r12;
  bctrl;
  stw r27, 0x62c(r26);
lbl_8013e298:
  addi r11, r1, 0x30;
  bl _restgpr_24;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

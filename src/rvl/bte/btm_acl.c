#include "btm_acl.h"

#include <string.h>

#include "bte_logmsg.h"
#include "bte_task1.h"
#include "btm_dev.h"
#include "btm_devctl.h"
#include "btm_pm.h"
#include "btm_sco.h"
#include "hcicmds.h"
#include "l2c_link.h"

// Symbol: btm_acl_init
// PAL: 0x80137c5c..0x80137c78
MARK_BINARY_BLOB(btm_acl_init, 0x80137c5c, 0x80137c78);
asm UNKNOWN_FUNCTION(btm_acl_init) {
  // clang-format off
  nofralloc;
  lis r3, 0x8033;
  li r4, 0x7d00;
  addi r3, r3, 0x6278;
  li r0, 0xff;
  sth r4, 0x4c6(r3);
  stb r0, 0x27bf(r3);
  blr;
  // clang-format on
}

// Symbol: btm_handle_to_acl_index
// PAL: 0x80137c78..0x80137cfc
MARK_BINARY_BLOB(btm_handle_to_acl_index, 0x80137c78, 0x80137cfc);
asm UNKNOWN_FUNCTION(btm_handle_to_acl_index) {
  // clang-format off
  nofralloc;
  lis r4, 0x8033;
  li r5, 0;
  addi r4, r4, 0x6278;
  lbz r0, 0x14d(r4);
  cmpwi r0, 0;
  beq lbl_80137c9c;
  lhz r0, 0x34(r4);
  cmplw r0, r3;
  beq lbl_80137cf4;
lbl_80137c9c:
  lbz r0, 0x269(r4);
  li r5, 1;
  cmpwi r0, 0;
  beq lbl_80137cb8;
  lhz r0, 0x150(r4);
  cmplw r0, r3;
  beq lbl_80137cf4;
lbl_80137cb8:
  lbz r0, 0x385(r4);
  li r5, 2;
  cmpwi r0, 0;
  beq lbl_80137cd4;
  lhz r0, 0x26c(r4);
  cmplw r0, r3;
  beq lbl_80137cf4;
lbl_80137cd4:
  lbz r0, 0x4a1(r4);
  li r5, 3;
  cmpwi r0, 0;
  beq lbl_80137cf0;
  lhz r0, 0x388(r4);
  cmplw r0, r3;
  beq lbl_80137cf4;
lbl_80137cf0:
  li r5, 4;
lbl_80137cf4:
  mr r3, r5;
  blr;
  // clang-format on
}

// Symbol: btm_acl_created
// PAL: 0x80137cfc..0x80138010
MARK_BINARY_BLOB(btm_acl_created, 0x80137cfc, 0x80138010);
asm UNKNOWN_FUNCTION(btm_acl_created) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_25;
  lis r8, 0x8033;
  mr r30, r3;
  addi r8, r8, 0x6278;
  mr r25, r4;
  mr r26, r5;
  mr r27, r6;
  mr r28, r7;
  addi r29, r8, 0x34;
  li r31, 0;
lbl_80137d34:
  lbz r0, 0x119(r29);
  cmpwi r0, 0;
  beq lbl_80137d5c;
  mr r4, r30;
  addi r3, r29, 8;
  li r5, 6;
  bl memcmp;
  cmpwi r3, 0;
  bne lbl_80137d5c;
  b lbl_80137d70;
lbl_80137d5c:
  addi r31, r31, 1;
  addi r29, r29, 0x11c;
  cmplwi r31, 4;
  blt lbl_80137d34;
  li r29, 0;
lbl_80137d70:
  cmpwi r29, 0;
  beq lbl_80137dc4;
  sth r27, 0(r29);
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  stb r28, 0x11a(r29);
  lbz r0, 0x27c0(r3);
  cmplwi r0, 4;
  blt lbl_80137ff8;
  lis r3, 0xd;
  lis r4, 0x8028;
  lbz r5, 0(r30);
  addi r3, r3, 3;
  lbz r6, 1(r30);
  addi r4, r4, 0x3520;
  lbz r7, 2(r30);
  lbz r8, 3(r30);
  lbz r9, 4(r30);
  lbz r10, 5(r30);
  bl LogMsg_6;
  b lbl_80137ff8;
lbl_80137dc4:
  lis r3, 0x8033;
  li r0, 4;
  addi r3, r3, 0x6278;
  li r4, 0;
  addi r31, r3, 0x34;
  mtctr r0;
lbl_80137ddc:
  lbz r0, 0x119(r31);
  cmpwi r0, 0;
  bne lbl_80137fec;
  li r3, 1;
  li r0, 0;
  stb r3, 0x119(r31);
  clrlwi r3, r4, 0x18;
  sth r27, 0(r31);
  stb r28, 0x11a(r31);
  sth r0, 4(r31);
  bl btm_pm_sm_alloc;
  mr r4, r30;
  addi r3, r31, 8;
  li r5, 6;
  bl memcpy;
  cmpwi r25, 0;
  beq lbl_80137e30;
  mr r4, r25;
  addi r3, r31, 0xe;
  li r5, 3;
  bl memcpy;
lbl_80137e30:
  cmpwi r26, 0;
  beq lbl_80137e48;
  mr r4, r26;
  addi r3, r31, 0x11;
  li r5, 0xf8;
  bl memcpy;
lbl_80137e48:
  lhz r3, 0(r31);
  bl btsnd_hcic_read_rmt_clk_offset;
  lhz r3, 0(r31);
  bl btsnd_hcic_rmt_ver_req;
  mr r3, r27;
  bl btm_find_dev_by_handle;
  cmpwi r3, 0;
  mr r5, r3;
  beq lbl_80137fe0;
  li r0, 8;
  li r6, 0;
  mtctr r0;
lbl_80137e78:
  clrlwi r0, r6, 0x18;
  add r4, r3, r0;
  lbz r0, 0x77(r4);
  cmpwi r0, 0;
  beq lbl_80137fd8;
  addi r4, r5, 0x77;
  addi r3, r31, 0x110;
  li r5, 8;
  bl memcpy;
  lis r3, 0x8033;
  li r0, -13063;
  addi r3, r3, 0x6278;
  lhz r5, 0x654(r3);
  lbz r3, 0x636(r3);
  andi. r4, r5, 0xcc18;
  cmplwi r3, 3;
  and r30, r4, r0;
  blt lbl_80137ecc;
  andi. r0, r5, 0x3306;
  or r0, r4, r0;
  clrlwi r30, r0, 0x10;
lbl_80137ecc:
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lbz r0, 0x27c0(r3);
  cmplwi r0, 4;
  blt lbl_80137ef8;
  lis r3, 0xd;
  lis r4, 0x8028;
  addi r3, r3, 3;
  clrlwi r5, r30, 0x10;
  addi r4, r4, 0x3560;
  bl LogMsg_1;
lbl_80137ef8:
  lhz r3, 0(r31);
  clrlwi r4, r30, 0x10;
  bl btsnd_hcic_change_conn_type;
  clrlwi. r0, r3, 0x18;
  beq lbl_80137f10;
  sth r30, 2(r31);
lbl_80137f10:
  lis r4, 0x8033;
  addi r4, r4, 0x6278;
  lhz r0, 0x4c4(r4);
  cmpwi r0, 0;
  beq lbl_80137f30;
  addi r3, r31, 8;
  addi r4, r4, 0x4c4;
  bl BTM_SetLinkPolicy;
lbl_80137f30:
  lis r3, 0x8033;
  li r29, 0;
  addi r3, r3, 0x6278;
  lhz r28, 0x4c6(r3);
  addi r30, r3, 0x34;
lbl_80137f44:
  lbz r0, 0x119(r30);
  cmpwi r0, 0;
  beq lbl_80137f6c;
  addi r3, r30, 8;
  addi r4, r31, 8;
  li r5, 6;
  bl memcmp;
  cmpwi r3, 0;
  bne lbl_80137f6c;
  b lbl_80137f80;
lbl_80137f6c:
  addi r29, r29, 1;
  addi r30, r30, 0x11c;
  cmplwi r29, 4;
  blt lbl_80137f44;
  li r30, 0;
lbl_80137f80:
  cmpwi r30, 0;
  beq lbl_80137fa4;
  sth r28, 0x10e(r30);
  lbz r0, 0x11a(r30);
  cmpwi r0, 0;
  bne lbl_80137fa4;
  lhz r3, 0(r30);
  mr r4, r28;
  bl btsnd_hcic_write_link_super_tout;
lbl_80137fa4:
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lwz r12, 0x4c8(r3);
  cmpwi r12, 0;
  beq lbl_80137ff8;
  addi r3, r31, 8;
  addi r4, r31, 0xe;
  addi r5, r31, 0x11;
  addi r6, r31, 0x110;
  li r7, 1;
  mtctr r12;
  bctrl;
  b lbl_80137ff8;
lbl_80137fd8:
  addi r6, r6, 1;
  bdnz lbl_80137e78;
lbl_80137fe0:
  lhz r3, 0(r31);
  bl btsnd_hcic_rmt_features_req;
  b lbl_80137ff8;
lbl_80137fec:
  addi r4, r4, 1;
  addi r31, r31, 0x11c;
  bdnz lbl_80137ddc;
lbl_80137ff8:
  addi r11, r1, 0x30;
  bl _restgpr_25;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: btm_acl_removed
// PAL: 0x80138010..0x801380d4
MARK_BINARY_BLOB(btm_acl_removed, 0x80138010, 0x801380d4);
asm UNKNOWN_FUNCTION(btm_acl_removed) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  lis r4, 0x8033;
  stw r0, 0x24(r1);
  addi r4, r4, 0x6278;
  stw r31, 0x1c(r1);
  li r31, 0;
  stw r30, 0x18(r1);
  addi r30, r4, 0x34;
  stw r29, 0x14(r1);
  mr r29, r3;
lbl_8013803c:
  lbz r0, 0x119(r30);
  cmpwi r0, 0;
  beq lbl_80138064;
  mr r4, r29;
  addi r3, r30, 8;
  li r5, 6;
  bl memcmp;
  cmpwi r3, 0;
  bne lbl_80138064;
  b lbl_80138078;
lbl_80138064:
  addi r31, r31, 1;
  addi r30, r30, 0x11c;
  cmplwi r31, 4;
  blt lbl_8013803c;
  li r30, 0;
lbl_80138078:
  cmpwi r30, 0;
  beq lbl_801380b8;
  li r0, 0;
  lis r3, 0x8033;
  stb r0, 0x119(r30);
  addi r3, r3, 0x6278;
  lwz r12, 0x4c8(r3);
  cmpwi r12, 0;
  beq lbl_801380b8;
  mr r3, r29;
  li r4, 0;
  li r5, 0;
  li r6, 0;
  li r7, 0;
  mtctr r12;
  bctrl;
lbl_801380b8:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: btm_acl_device_down
// PAL: 0x801380d4..0x80138138
MARK_BINARY_BLOB(btm_acl_device_down, 0x801380d4, 0x80138138);
asm UNKNOWN_FUNCTION(btm_acl_device_down) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r3, 0x8033;
  stw r0, 0x14(r1);
  addi r3, r3, 0x6278;
  stw r31, 0xc(r1);
  addi r31, r3, 0x34;
  stw r30, 8(r1);
  li r30, 0;
lbl_801380f8:
  lbz r0, 0x119(r31);
  cmpwi r0, 0;
  beq lbl_80138110;
  lhz r3, 0(r31);
  li r4, 3;
  bl l2c_link_hci_disc_comp;
lbl_80138110:
  addi r30, r30, 1;
  addi r31, r31, 0x11c;
  cmplwi r30, 4;
  blt lbl_801380f8;
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: BTM_SwitchRole
// PAL: 0x80138138..0x80138354
MARK_BINARY_BLOB(BTM_SwitchRole, 0x80138138, 0x80138354);
asm UNKNOWN_FUNCTION(BTM_SwitchRole) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_27;
  lis r6, 0x8033;
  mr r28, r3;
  addi r6, r6, 0x6278;
  mr r29, r4;
  lbz r0, 0x640(r6);
  mr r30, r5;
  rlwinm. r0, r0, 0, 0x1a, 0x1a;
  bne lbl_80138174;
  li r3, 4;
  b lbl_8013833c;
lbl_80138174:
  addi r31, r6, 0x34;
  li r27, 0;
lbl_8013817c:
  lbz r0, 0x119(r31);
  cmpwi r0, 0;
  beq lbl_801381a4;
  mr r4, r28;
  addi r3, r31, 8;
  li r5, 6;
  bl memcmp;
  cmpwi r3, 0;
  bne lbl_801381a4;
  b lbl_801381b8;
lbl_801381a4:
  addi r27, r27, 1;
  addi r31, r31, 0x11c;
  cmplwi r27, 4;
  blt lbl_8013817c;
  li r31, 0;
lbl_801381b8:
  cmpwi r31, 0;
  bne lbl_801381c8;
  li r3, 7;
  b lbl_8013833c;
lbl_801381c8:
  lbz r0, 0x11a(r31);
  cmplw r0, r29;
  bne lbl_801381dc;
  li r3, 0;
  b lbl_8013833c;
lbl_801381dc:
  mr r3, r28;
  bl btm_is_sco_active_by_bdaddr;
  clrlwi r0, r3, 0x18;
  cmplwi r0, 1;
  bne lbl_801381f8;
  li r3, 3;
  b lbl_8013833c;
lbl_801381f8:
  lbz r0, 0x11b(r31);
  cmpwi r0, 0;
  beq lbl_80138234;
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lbz r0, 0x27c0(r3);
  cmplwi r0, 5;
  blt lbl_8013822c;
  lis r3, 0xd;
  lis r4, 0x8028;
  addi r3, r3, 4;
  addi r4, r4, 0x3580;
  bl LogMsg_0;
lbl_8013822c:
  li r3, 2;
  b lbl_8013833c;
lbl_80138234:
  lis r3, 0x8033;
  li r4, 0;
  addi r3, r3, 0x6278;
  li r5, 8;
  addi r3, r3, 0x624;
  bl memset;
  addi r3, r31, 8;
  addi r4, r1, 8;
  bl BTM_ReadPowerMode;
  clrlwi. r0, r3, 0x18;
  beq lbl_80138264;
  b lbl_8013833c;
lbl_80138264:
  lbz r3, 8(r1);
  addi r0, r3, 0xfe;
  clrlwi r0, r0, 0x18;
  cmplwi r0, 1;
  bgt lbl_801382b0;
  li r0, 0;
  addi r4, r31, 8;
  stb r0, 0x14(r1);
  addi r5, r1, 0xc;
  li r3, 0x80;
  bl BTM_SetPowerMode;
  clrlwi r0, r3, 0x18;
  cmplwi r0, 1;
  beq lbl_801382a4;
  li r3, 6;
  b lbl_8013833c;
lbl_801382a4:
  li r0, 1;
  stb r0, 0x11b(r31);
  b lbl_80138318;
lbl_801382b0:
  mr r3, r28;
  bl btm_find_dev;
  cmpwi r3, 0;
  beq lbl_801382f4;
  lbz r0, 0x76(r3);
  rlwinm. r0, r0, 0, 0x1d, 0x1d;
  beq lbl_801382f4;
  lhz r3, 0(r31);
  li r4, 0;
  bl btsnd_hcic_set_conn_encrypt;
  clrlwi. r0, r3, 0x18;
  bne lbl_801382e8;
  li r3, 3;
  b lbl_8013833c;
lbl_801382e8:
  li r0, 2;
  stb r0, 0x11b(r31);
  b lbl_80138318;
lbl_801382f4:
  mr r3, r28;
  mr r4, r29;
  bl btsnd_hcic_switch_role;
  clrlwi. r0, r3, 0x18;
  bne lbl_80138310;
  li r3, 3;
  b lbl_8013833c;
lbl_80138310:
  li r0, 5;
  stb r0, 0x11b(r31);
lbl_80138318:
  lis r31, 0x8033;
  mr r4, r28;
  addi r31, r31, 0x6278;
  li r5, 6;
  addi r3, r31, 0x626;
  bl memcpy;
  stb r29, 0x625(r31);
  li r3, 1;
  stw r30, 0x62c(r31);
lbl_8013833c:
  addi r11, r1, 0x30;
  bl _restgpr_27;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: btm_acl_encrypt_change
// PAL: 0x80138354..0x801384c4
MARK_BINARY_BLOB(btm_acl_encrypt_change, 0x80138354, 0x801384c4);
asm UNKNOWN_FUNCTION(btm_acl_encrypt_change) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  lis r4, 0x8033;
  li r6, 0;
  stw r0, 0x24(r1);
  addi r4, r4, 0x6278;
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  lbz r0, 0x14d(r4);
  cmpwi r0, 0;
  beq lbl_80138390;
  lhz r0, 0x34(r4);
  cmplw r0, r3;
  beq lbl_801383e8;
lbl_80138390:
  lbz r0, 0x269(r4);
  li r6, 1;
  cmpwi r0, 0;
  beq lbl_801383ac;
  lhz r0, 0x150(r4);
  cmplw r0, r3;
  beq lbl_801383e8;
lbl_801383ac:
  lbz r0, 0x385(r4);
  li r6, 2;
  cmpwi r0, 0;
  beq lbl_801383c8;
  lhz r0, 0x26c(r4);
  cmplw r0, r3;
  beq lbl_801383e8;
lbl_801383c8:
  lbz r0, 0x4a1(r4);
  li r6, 3;
  cmpwi r0, 0;
  beq lbl_801383e4;
  lhz r0, 0x388(r4);
  cmplw r0, r3;
  beq lbl_801383e8;
lbl_801383e4:
  li r6, 4;
lbl_801383e8:
  cmplwi r6, 4;
  bge lbl_801384a8;
  mulli r0, r6, 0x11c;
  lis r30, 0x8033;
  addi r30, r30, 0x6278;
  add r29, r30, r0;
  b lbl_80138408;
  b lbl_801384a8;
lbl_80138408:
  lbz r0, 0x14f(r29);
  cmplwi r0, 2;
  bne lbl_8013847c;
  cmpwi r5, 0;
  beq lbl_80138428;
  li r0, 0;
  stb r0, 0x14f(r29);
  b lbl_80138430;
lbl_80138428:
  li r0, 3;
  stb r0, 0x14f(r29);
lbl_80138430:
  lbz r0, 0x14e(r29);
  addi r3, r29, 0x3c;
  cntlzw r0, r0;
  rlwinm r4, r0, 0x1b, 0x18, 0x1f;
  bl btsnd_hcic_switch_role;
  clrlwi. r0, r3, 0x18;
  bne lbl_801384a8;
  li r30, 0;
  lis r31, 0x8033;
  stb r30, 0x14f(r29);
  addi r31, r31, 0x6278;
  lwz r12, 0x62c(r31);
  cmpwi r12, 0;
  beq lbl_801384a8;
  addi r3, r31, 0x624;
  mtctr r12;
  bctrl;
  stw r30, 0x62c(r31);
  b lbl_801384a8;
lbl_8013847c:
  cmplwi r0, 4;
  bne lbl_801384a8;
  li r31, 0;
  stb r31, 0x14f(r29);
  lwz r12, 0x62c(r30);
  cmpwi r12, 0;
  beq lbl_801384a8;
  addi r3, r30, 0x624;
  mtctr r12;
  bctrl;
  stw r31, 0x62c(r30);
lbl_801384a8:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: BTM_SetLinkPolicy
// PAL: 0x801384c4..0x801386b4
MARK_BINARY_BLOB(BTM_SetLinkPolicy, 0x801384c4, 0x801386b4);
asm UNKNOWN_FUNCTION(BTM_SetLinkPolicy) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  lis r30, 0x8028;
  addi r30, r30, 0x3520;
  stw r29, 0x14(r1);
  mr r29, r4;
  stw r28, 0x10(r1);
  mr r28, r3;
  bl BTM_ReadLocalFeatures;
  lhz r4, 0(r29);
  mr r31, r3;
  cmpwi r4, 0;
  beq lbl_8013861c;
  clrlwi. r0, r4, 0x1f;
  beq lbl_80138544;
  lbz r0, 0(r3);
  rlwinm. r0, r0, 0, 0x1a, 0x1a;
  bne lbl_80138544;
  rlwinm r5, r4, 0, 0x10, 0x1e;
  lis r3, 0x8033;
  sth r5, 0(r29);
  addi r3, r3, 0x6278;
  lbz r0, 0x27c0(r3);
  cmplwi r0, 3;
  blt lbl_80138544;
  lis r3, 0xd;
  addi r4, r30, 0xbc;
  addi r3, r3, 2;
  bl LogMsg_1;
lbl_80138544:
  lhz r3, 0(r29);
  rlwinm. r0, r3, 0, 0x1e, 0x1e;
  beq lbl_8013858c;
  lbz r0, 0(r31);
  rlwinm. r0, r0, 0, 0x19, 0x19;
  bne lbl_8013858c;
  rlwinm r5, r3, 0, 0x1f, 0x1d;
  lis r3, 0x8033;
  sth r5, 0(r29);
  addi r3, r3, 0x6278;
  lbz r0, 0x27c0(r3);
  cmplwi r0, 3;
  blt lbl_8013858c;
  lis r3, 0xd;
  addi r4, r30, 0xf8;
  addi r3, r3, 2;
  clrlwi r5, r5, 0x10;
  bl LogMsg_1;
lbl_8013858c:
  lhz r3, 0(r29);
  rlwinm. r0, r3, 0, 0x1d, 0x1d;
  beq lbl_801385d4;
  lbz r0, 0(r31);
  rlwinm. r0, r0, 0, 0x18, 0x18;
  bne lbl_801385d4;
  rlwinm r5, r3, 0, 0x1e, 0x1c;
  lis r3, 0x8033;
  sth r5, 0(r29);
  addi r3, r3, 0x6278;
  lbz r0, 0x27c0(r3);
  cmplwi r0, 3;
  blt lbl_801385d4;
  lis r3, 0xd;
  addi r4, r30, 0x130;
  addi r3, r3, 2;
  clrlwi r5, r5, 0x10;
  bl LogMsg_1;
lbl_801385d4:
  lhz r3, 0(r29);
  rlwinm. r0, r3, 0, 0x1c, 0x1c;
  beq lbl_8013861c;
  lbz r0, 1(r31);
  clrlwi. r0, r0, 0x1f;
  bne lbl_8013861c;
  rlwinm r5, r3, 0, 0x1d, 0x1b;
  lis r3, 0x8033;
  sth r5, 0(r29);
  addi r3, r3, 0x6278;
  lbz r0, 0x27c0(r3);
  cmplwi r0, 3;
  blt lbl_8013861c;
  lis r3, 0xd;
  addi r4, r30, 0x170;
  addi r3, r3, 2;
  clrlwi r5, r5, 0x10;
  bl LogMsg_1;
lbl_8013861c:
  lis r3, 0x8033;
  li r30, 0;
  addi r3, r3, 0x6278;
  addi r31, r3, 0x34;
lbl_8013862c:
  lbz r0, 0x119(r31);
  cmpwi r0, 0;
  beq lbl_80138654;
  mr r4, r28;
  addi r3, r31, 8;
  li r5, 6;
  bl memcmp;
  cmpwi r3, 0;
  bne lbl_80138654;
  b lbl_80138668;
lbl_80138654:
  addi r30, r30, 1;
  addi r31, r31, 0x11c;
  cmplwi r30, 4;
  blt lbl_8013862c;
  li r31, 0;
lbl_80138668:
  cmpwi r31, 0;
  beq lbl_80138690;
  lhz r3, 0(r31);
  lhz r4, 0(r29);
  bl btsnd_hcic_write_policy_set;
  clrlwi. r0, r3, 0x18;
  li r3, 3;
  beq lbl_80138694;
  li r3, 1;
  b lbl_80138694;
lbl_80138690:
  li r3, 7;
lbl_80138694:
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

// Symbol: BTM_SetDefaultLinkPolicy
// PAL: 0x801386b4..0x801386c4
MARK_BINARY_BLOB(BTM_SetDefaultLinkPolicy, 0x801386b4, 0x801386c4);
asm UNKNOWN_FUNCTION(BTM_SetDefaultLinkPolicy) {
  // clang-format off
  nofralloc;
  lis r4, 0x8033;
  addi r4, r4, 0x6278;
  sth r3, 0x4c4(r4);
  blr;
  // clang-format on
}

// Symbol: btm_read_link_policy_complete
// PAL: 0x801386c4..0x801387c8
MARK_BINARY_BLOB(btm_read_link_policy_complete, 0x801386c4, 0x801387c8);
asm UNKNOWN_FUNCTION(btm_read_link_policy_complete) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  stw r31, 0x2c(r1);
  lis r31, 0x8033;
  addi r31, r31, 0x6278;
  stw r30, 0x28(r1);
  stw r29, 0x24(r1);
  addi r29, r31, 0x34;
  stw r28, 0x20(r1);
  mr r28, r3;
  addi r3, r31, 0x5ac;
  lwz r30, 0x5c4(r31);
  bl btu_stop_timer;
  li r3, 0;
  cmpwi r30, 0;
  stw r3, 0x5c4(r31);
  beq lbl_801387a8;
  lbz r0, 0(r28);
  cmpwi r0, 0;
  stb r0, 9(r1);
  bne lbl_80138790;
  stb r3, 8(r1);
  li r0, 4;
  li r7, 0;
  lbz r4, 2(r28);
  lbz r3, 4(r28);
  slwi r5, r4, 8;
  lbz r6, 1(r28);
  lbz r4, 3(r28);
  slwi r3, r3, 8;
  add r5, r6, r5;
  add r3, r4, r3;
  sth r3, 0x10(r1);
  clrlwi r3, r5, 0x10;
  mtctr r0;
lbl_80138754:
  lbz r0, 0x119(r29);
  cmpwi r0, 0;
  beq lbl_80138780;
  lhz r0, 0(r29);
  cmplw r3, r0;
  bne lbl_80138780;
  addi r3, r1, 0xa;
  addi r4, r29, 8;
  li r5, 6;
  bl memcpy;
  b lbl_80138798;
lbl_80138780:
  addi r7, r7, 1;
  addi r29, r29, 0x11c;
  bdnz lbl_80138754;
  b lbl_80138798;
lbl_80138790:
  li r0, 0xa;
  stb r0, 8(r1);
lbl_80138798:
  mr r12, r30;
  addi r3, r1, 8;
  mtctr r12;
  bctrl;
lbl_801387a8:
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

// Symbol: btm_read_remote_version_complete
// PAL: 0x801387c8..0x80138854
MARK_BINARY_BLOB(btm_read_remote_version_complete, 0x801387c8, 0x80138854);
asm UNKNOWN_FUNCTION(btm_read_remote_version_complete) {
  // clang-format off
  nofralloc;
  lbz r0, 0(r3);
  lis r4, 0x8033;
  addi r4, r4, 0x6278;
  cmpwi r0, 0;
  addi r6, r4, 0x34;
  bnelr;
  lbz r4, 2(r3);
  li r0, 4;
  lbz r5, 1(r3);
  slwi r4, r4, 8;
  add r4, r5, r4;
  clrlwi r4, r4, 0x10;
  mtctr r0;
lbl_801387fc:
  lbz r0, 0x119(r6);
  cmpwi r0, 0;
  beq lbl_80138848;
  lhz r0, 0(r6);
  cmplw r0, r4;
  bne lbl_80138848;
  lbz r0, 3(r3);
  stb r0, 0x118(r6);
  lbz r0, 5(r3);
  lbz r4, 4(r3);
  slwi r0, r0, 8;
  add r0, r4, r0;
  sth r0, 0x10a(r6);
  lbz r0, 7(r3);
  lbz r3, 6(r3);
  slwi r0, r0, 8;
  add r0, r3, r0;
  sth r0, 0x10c(r6);
  blr;
lbl_80138848:
  addi r6, r6, 0x11c;
  bdnz lbl_801387fc;
  blr;
  // clang-format on
}

// Symbol: btm_read_remote_features_complete
// PAL: 0x80138854..0x80138a80
MARK_BINARY_BLOB(btm_read_remote_features_complete, 0x80138854, 0x80138a80);
asm UNKNOWN_FUNCTION(btm_read_remote_features_complete) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  lis r4, 0x8033;
  stw r0, 0x24(r1);
  addi r4, r4, 0x6278;
  stw r31, 0x1c(r1);
  addi r31, r4, 0x34;
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  stw r28, 0x10(r1);
  lbz r0, 0(r3);
  cmpwi r0, 0;
  bne lbl_80138a60;
  lbz r4, 2(r3);
  li r0, 4;
  lbz r5, 1(r3);
  slwi r4, r4, 8;
  add r4, r5, r4;
  clrlwi r4, r4, 0x10;
  mtctr r0;
lbl_801388a4:
  lbz r0, 0x119(r31);
  cmpwi r0, 0;
  beq lbl_80138a58;
  lhz r0, 0(r31);
  cmplw r0, r4;
  bne lbl_80138a58;
  lbz r0, 3(r3);
  stb r0, 0x110(r31);
  lbz r0, 4(r3);
  stb r0, 0x111(r31);
  lbz r0, 5(r3);
  stb r0, 0x112(r31);
  lbz r0, 6(r3);
  stb r0, 0x113(r31);
  lbz r0, 7(r3);
  stb r0, 0x114(r31);
  lbz r0, 8(r3);
  stb r0, 0x115(r31);
  lbz r0, 9(r3);
  stb r0, 0x116(r31);
  lbz r0, 0xa(r3);
  mr r3, r4;
  stb r0, 0x117(r31);
  bl btm_find_dev_by_handle;
  cmpwi r3, 0;
  beq lbl_8013891c;
  addi r4, r31, 0x110;
  li r5, 8;
  addi r3, r3, 0x77;
  bl memcpy;
lbl_8013891c:
  lis r3, 0x8033;
  li r0, -13063;
  addi r3, r3, 0x6278;
  lhz r5, 0x654(r3);
  lbz r3, 0x636(r3);
  andi. r4, r5, 0xcc18;
  cmplwi r3, 3;
  and r30, r4, r0;
  blt lbl_8013894c;
  andi. r0, r5, 0x3306;
  or r0, r4, r0;
  clrlwi r30, r0, 0x10;
lbl_8013894c:
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lbz r0, 0x27c0(r3);
  cmplwi r0, 4;
  blt lbl_80138978;
  lis r3, 0xd;
  lis r4, 0x8028;
  addi r3, r3, 3;
  clrlwi r5, r30, 0x10;
  addi r4, r4, 0x3560;
  bl LogMsg_1;
lbl_80138978:
  lhz r3, 0(r31);
  clrlwi r4, r30, 0x10;
  bl btsnd_hcic_change_conn_type;
  clrlwi. r0, r3, 0x18;
  beq lbl_80138990;
  sth r30, 2(r31);
lbl_80138990:
  lis r4, 0x8033;
  addi r4, r4, 0x6278;
  lhz r0, 0x4c4(r4);
  cmpwi r0, 0;
  beq lbl_801389b0;
  addi r3, r31, 8;
  addi r4, r4, 0x4c4;
  bl BTM_SetLinkPolicy;
lbl_801389b0:
  lis r3, 0x8033;
  li r30, 0;
  addi r3, r3, 0x6278;
  lhz r28, 0x4c6(r3);
  addi r29, r3, 0x34;
lbl_801389c4:
  lbz r0, 0x119(r29);
  cmpwi r0, 0;
  beq lbl_801389ec;
  addi r3, r29, 8;
  addi r4, r31, 8;
  li r5, 6;
  bl memcmp;
  cmpwi r3, 0;
  bne lbl_801389ec;
  b lbl_80138a00;
lbl_801389ec:
  addi r30, r30, 1;
  addi r29, r29, 0x11c;
  cmplwi r30, 4;
  blt lbl_801389c4;
  li r29, 0;
lbl_80138a00:
  cmpwi r29, 0;
  beq lbl_80138a24;
  sth r28, 0x10e(r29);
  lbz r0, 0x11a(r29);
  cmpwi r0, 0;
  bne lbl_80138a24;
  lhz r3, 0(r29);
  mr r4, r28;
  bl btsnd_hcic_write_link_super_tout;
lbl_80138a24:
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lwz r12, 0x4c8(r3);
  cmpwi r12, 0;
  beq lbl_80138a60;
  addi r3, r31, 8;
  addi r4, r31, 0xe;
  addi r5, r31, 0x11;
  addi r6, r31, 0x110;
  li r7, 1;
  mtctr r12;
  bctrl;
  b lbl_80138a60;
lbl_80138a58:
  addi r31, r31, 0x11c;
  bdnz lbl_801388a4;
lbl_80138a60:
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

// Symbol: BTM_SetDefaultLinkSuperTout
// PAL: 0x80138a80..0x80138a90
MARK_BINARY_BLOB(BTM_SetDefaultLinkSuperTout, 0x80138a80, 0x80138a90);
asm UNKNOWN_FUNCTION(BTM_SetDefaultLinkSuperTout) {
  // clang-format off
  nofralloc;
  lis r4, 0x8033;
  addi r4, r4, 0x6278;
  sth r3, 0x4c6(r4);
  blr;
  // clang-format on
}

// Symbol: BTM_IsAclConnectionUp
// PAL: 0x80138a90..0x80138b68
MARK_BINARY_BLOB(BTM_IsAclConnectionUp, 0x80138a90, 0x80138b68);
asm UNKNOWN_FUNCTION(BTM_IsAclConnectionUp) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  lis r4, 0x8033;
  stw r0, 0x24(r1);
  addi r4, r4, 0x6278;
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  mr r29, r3;
  lbz r0, 0x27c0(r4);
  cmplwi r0, 3;
  blt lbl_80138aec;
  lis r3, 0xd;
  lis r4, 0x8028;
  lbz r5, 0(r29);
  addi r3, r3, 2;
  lbz r6, 1(r29);
  addi r4, r4, 0x3700;
  lbz r7, 2(r29);
  lbz r8, 3(r29);
  lbz r9, 4(r29);
  lbz r10, 5(r29);
  bl LogMsg_6;
lbl_80138aec:
  lis r3, 0x8033;
  li r31, 0;
  addi r3, r3, 0x6278;
  addi r30, r3, 0x34;
lbl_80138afc:
  lbz r0, 0x119(r30);
  cmpwi r0, 0;
  beq lbl_80138b24;
  mr r4, r29;
  addi r3, r30, 8;
  li r5, 6;
  bl memcmp;
  cmpwi r3, 0;
  bne lbl_80138b24;
  b lbl_80138b38;
lbl_80138b24:
  addi r31, r31, 1;
  addi r30, r30, 0x11c;
  cmplwi r31, 4;
  blt lbl_80138afc;
  li r30, 0;
lbl_80138b38:
  cmpwi r30, 0;
  beq lbl_80138b48;
  li r3, 1;
  b lbl_80138b4c;
lbl_80138b48:
  li r3, 0;
lbl_80138b4c:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: BTM_GetNumAclLinks
// PAL: 0x80138b68..0x80138bc4
MARK_BINARY_BLOB(BTM_GetNumAclLinks, 0x80138b68, 0x80138bc4);
asm UNKNOWN_FUNCTION(BTM_GetNumAclLinks) {
  // clang-format off
  nofralloc;
  lis r4, 0x8033;
  li r3, 0;
  addi r4, r4, 0x6278;
  lbz r0, 0x14d(r4);
  cmpwi r0, 0;
  beq lbl_80138b84;
  li r3, 1;
lbl_80138b84:
  lbz r0, 0x269(r4);
  cmpwi r0, 0;
  beq lbl_80138b98;
  addi r0, r3, 1;
  clrlwi r3, r0, 0x10;
lbl_80138b98:
  lbz r0, 0x385(r4);
  cmpwi r0, 0;
  beq lbl_80138bac;
  addi r0, r3, 1;
  clrlwi r3, r0, 0x10;
lbl_80138bac:
  lbz r0, 0x4a1(r4);
  cmpwi r0, 0;
  beqlr;
  addi r0, r3, 1;
  clrlwi r3, r0, 0x10;
  blr;
  // clang-format on
}

// Symbol: btm_get_acl_disc_reason_code
// PAL: 0x80138bc4..0x80138bd4
MARK_BINARY_BLOB(btm_get_acl_disc_reason_code, 0x80138bc4, 0x80138bd4);
asm UNKNOWN_FUNCTION(btm_get_acl_disc_reason_code) {
  // clang-format off
  nofralloc;
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lbz r3, 0x27bf(r3);
  blr;
  // clang-format on
}

// Symbol: BTM_GetHCIConnHandle
// PAL: 0x80138bd4..0x80138c70
MARK_BINARY_BLOB(BTM_GetHCIConnHandle, 0x80138bd4, 0x80138c70);
asm UNKNOWN_FUNCTION(BTM_GetHCIConnHandle) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  lis r4, 0x8033;
  stw r0, 0x24(r1);
  addi r4, r4, 0x6278;
  stw r31, 0x1c(r1);
  li r31, 0;
  stw r30, 0x18(r1);
  addi r30, r4, 0x34;
  stw r29, 0x14(r1);
  mr r29, r3;
lbl_80138c00:
  lbz r0, 0x119(r30);
  cmpwi r0, 0;
  beq lbl_80138c28;
  mr r4, r29;
  addi r3, r30, 8;
  li r5, 6;
  bl memcmp;
  cmpwi r3, 0;
  bne lbl_80138c28;
  b lbl_80138c3c;
lbl_80138c28:
  addi r31, r31, 1;
  addi r30, r30, 0x11c;
  cmplwi r31, 4;
  blt lbl_80138c00;
  li r30, 0;
lbl_80138c3c:
  cmpwi r30, 0;
  beq lbl_80138c4c;
  lhz r3, 0(r30);
  b lbl_80138c54;
lbl_80138c4c:
  lis r3, 1;
  addi r3, r3, -1;
lbl_80138c54:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: btm_process_clk_off_comp_evt
// PAL: 0x80138c70..0x80138d0c
MARK_BINARY_BLOB(btm_process_clk_off_comp_evt, 0x80138c70, 0x80138d0c);
asm UNKNOWN_FUNCTION(btm_process_clk_off_comp_evt) {
  // clang-format off
  nofralloc;
  lis r5, 0x8033;
  li r6, 0;
  addi r5, r5, 0x6278;
  lbz r0, 0x14d(r5);
  cmpwi r0, 0;
  beq lbl_80138c94;
  lhz r0, 0x34(r5);
  cmplw r0, r3;
  beq lbl_80138cec;
lbl_80138c94:
  lbz r0, 0x269(r5);
  li r6, 1;
  cmpwi r0, 0;
  beq lbl_80138cb0;
  lhz r0, 0x150(r5);
  cmplw r0, r3;
  beq lbl_80138cec;
lbl_80138cb0:
  lbz r0, 0x385(r5);
  li r6, 2;
  cmpwi r0, 0;
  beq lbl_80138ccc;
  lhz r0, 0x26c(r5);
  cmplw r0, r3;
  beq lbl_80138cec;
lbl_80138ccc:
  lbz r0, 0x4a1(r5);
  li r6, 3;
  cmpwi r0, 0;
  beq lbl_80138ce8;
  lhz r0, 0x388(r5);
  cmplw r0, r3;
  beq lbl_80138cec;
lbl_80138ce8:
  li r6, 4;
lbl_80138cec:
  cmplwi r6, 4;
  bgelr;
  mulli r0, r6, 0x11c;
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  add r3, r3, r0;
  sth r4, 0x3a(r3);
  blr;
  // clang-format on
}

// Symbol: btm_acl_role_changed
// PAL: 0x80138d0c..0x80138f00
MARK_BINARY_BLOB(btm_acl_role_changed, 0x80138d0c, 0x80138f00);
asm UNKNOWN_FUNCTION(btm_acl_role_changed) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_25;
  cmpwi r4, 0;
  mr r25, r3;
  mr r26, r4;
  mr r28, r5;
  beq lbl_80138d3c;
  mr r27, r26;
  b lbl_80138d48;
lbl_80138d3c:
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  addi r27, r3, 0x27b4;
lbl_80138d48:
  lis r3, 0x8033;
  li r30, 0;
  addi r3, r3, 0x6278;
  addi r29, r3, 0x34;
lbl_80138d58:
  lbz r0, 0x119(r29);
  cmpwi r0, 0;
  beq lbl_80138d80;
  mr r4, r27;
  addi r3, r29, 8;
  li r5, 6;
  bl memcmp;
  cmpwi r3, 0;
  bne lbl_80138d80;
  b lbl_80138d94;
lbl_80138d80:
  addi r30, r30, 1;
  addi r29, r29, 0x11c;
  cmplwi r30, 4;
  blt lbl_80138d58;
  li r29, 0;
lbl_80138d94:
  lis r3, 0x8033;
  cmpwi r29, 0;
  addi r3, r3, 0x6278;
  addi r31, r3, 0x624;
  beq lbl_80138ee8;
  cmpwi r25, 0;
  stb r25, 0(r31);
  bne lbl_80138dcc;
  stb r28, 1(r31);
  mr r4, r27;
  addi r3, r31, 2;
  li r5, 6;
  bl memcpy;
  stb r28, 0x11a(r29);
lbl_80138dcc:
  cmpwi r26, 0;
  beq lbl_80138e48;
  lis r3, 0x8033;
  lhz r30, 0x10e(r29);
  addi r3, r3, 0x6278;
  li r28, 0;
  addi r27, r3, 0x34;
lbl_80138de8:
  lbz r0, 0x119(r27);
  cmpwi r0, 0;
  beq lbl_80138e10;
  addi r3, r27, 8;
  addi r4, r29, 8;
  li r5, 6;
  bl memcmp;
  cmpwi r3, 0;
  bne lbl_80138e10;
  b lbl_80138e24;
lbl_80138e10:
  addi r28, r28, 1;
  addi r27, r27, 0x11c;
  cmplwi r28, 4;
  blt lbl_80138de8;
  li r27, 0;
lbl_80138e24:
  cmpwi r27, 0;
  beq lbl_80138e48;
  sth r30, 0x10e(r27);
  lbz r0, 0x11a(r27);
  cmpwi r0, 0;
  bne lbl_80138e48;
  lhz r3, 0(r27);
  mr r4, r30;
  bl btsnd_hcic_write_link_super_tout;
lbl_80138e48:
  lbz r0, 0x11b(r29);
  cmplwi r0, 3;
  bne lbl_80138e74;
  lhz r3, 0(r29);
  li r4, 1;
  bl btsnd_hcic_set_conn_encrypt;
  clrlwi. r0, r3, 0x18;
  beq lbl_80138e74;
  li r0, 4;
  stb r0, 0x11b(r29);
  b lbl_80138ee8;
lbl_80138e74:
  cmpwi r29, 0;
  beq lbl_80138e90;
  lbz r0, 0x11b(r29);
  cmplwi r0, 5;
  bne lbl_80138e90;
  li r0, 0;
  stb r0, 0x11b(r29);
lbl_80138e90:
  lis r30, 0x8033;
  addi r30, r30, 0x6278;
  lwz r12, 0x62c(r30);
  cmpwi r12, 0;
  beq lbl_80138eb8;
  mr r3, r31;
  mtctr r12;
  bctrl;
  li r0, 0;
  stw r0, 0x62c(r30);
lbl_80138eb8:
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lbz r0, 0x27c0(r3);
  cmplwi r0, 4;
  blt lbl_80138ee8;
  lis r3, 0xd;
  lis r4, 0x8028;
  lbz r5, 1(r31);
  addi r3, r3, 3;
  lbz r6, 0(r31);
  addi r4, r4, 0x373c;
  bl LogMsg_2;
lbl_80138ee8:
  addi r11, r1, 0x30;
  bl _restgpr_25;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: btm_acl_timeout
// PAL: 0x80138f00..0x80138f5c
MARK_BINARY_BLOB(btm_acl_timeout, 0x80138f00, 0x80138f5c);
asm UNKNOWN_FUNCTION(btm_acl_timeout) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  lwz r0, 0x10(r3);
  cmplwi r0, 4;
  bne lbl_80138f4c;
  lis r4, 0x8033;
  li r3, 0xa;
  addi r4, r4, 0x6278;
  li r0, 0;
  lwz r12, 0x5c4(r4);
  stb r3, 8(r1);
  cmpwi r12, 0;
  sth r0, 0x10(r1);
  stw r0, 0x5c4(r4);
  beq lbl_80138f4c;
  addi r3, r1, 8;
  mtctr r12;
  bctrl;
lbl_80138f4c:
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: btm_get_max_packet_size
// PAL: 0x80138f5c..0x801390fc
MARK_BINARY_BLOB(btm_get_max_packet_size, 0x80138f5c, 0x801390fc);
asm UNKNOWN_FUNCTION(btm_get_max_packet_size) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_27;
  lis r4, 0x8033;
  mr r27, r3;
  addi r4, r4, 0x6278;
  li r30, 0;
  addi r29, r4, 0x34;
lbl_80138f84:
  lbz r0, 0x119(r29);
  cmpwi r0, 0;
  beq lbl_80138fac;
  mr r4, r27;
  addi r3, r29, 8;
  li r5, 6;
  bl memcmp;
  cmpwi r3, 0;
  bne lbl_80138fac;
  b lbl_80138fc0;
lbl_80138fac:
  addi r30, r30, 1;
  addi r29, r29, 0x11c;
  cmplwi r30, 4;
  blt lbl_80138f84;
  li r29, 0;
lbl_80138fc0:
  cmpwi r29, 0;
  li r28, 0;
  li r31, 0;
  beq lbl_80138fd8;
  lhz r28, 2(r29);
  b lbl_80138ffc;
lbl_80138fd8:
  lis r30, 0x8033;
  mr r4, r27;
  addi r30, r30, 0x6278;
  li r5, 6;
  addi r3, r30, 0x630;
  bl memcmp;
  cmpwi r3, 0;
  bne lbl_80138ffc;
  lhz r28, 0x654(r30);
lbl_80138ffc:
  cmpwi r28, 0;
  beq lbl_801390c0;
  rlwinm. r0, r28, 0, 0x12, 0x12;
  bne lbl_80139014;
  li r31, 0x3fd;
  b lbl_801390c0;
lbl_80139014:
  rlwinm. r0, r28, 0, 0x13, 0x13;
  bne lbl_80139024;
  li r31, 0x2a7;
  b lbl_801390c0;
lbl_80139024:
  rlwinm. r0, r28, 0, 0x16, 0x16;
  bne lbl_80139034;
  li r31, 0x228;
  b lbl_801390c0;
lbl_80139034:
  rlwinm. r0, r28, 0, 0x10, 0x10;
  beq lbl_80139044;
  li r31, 0x153;
  b lbl_801390c0;
lbl_80139044:
  rlwinm. r0, r28, 0, 0x17, 0x17;
  bne lbl_80139054;
  li r31, 0x16f;
  b lbl_801390c0;
lbl_80139054:
  rlwinm. r0, r28, 0, 0x11, 0x11;
  beq lbl_80139064;
  li r31, 0xe0;
  b lbl_801390c0;
lbl_80139064:
  rlwinm. r0, r28, 0, 0x14, 0x14;
  beq lbl_80139074;
  li r31, 0xb7;
  b lbl_801390c0;
lbl_80139074:
  rlwinm. r0, r28, 0, 0x15, 0x15;
  beq lbl_80139084;
  li r31, 0x79;
  b lbl_801390c0;
lbl_80139084:
  rlwinm. r0, r28, 0, 0x1d, 0x1d;
  bne lbl_80139094;
  li r31, 0x53;
  b lbl_801390c0;
lbl_80139094:
  rlwinm. r0, r28, 0, 0x1e, 0x1e;
  bne lbl_801390a4;
  li r31, 0x36;
  b lbl_801390c0;
lbl_801390a4:
  rlwinm. r0, r28, 0, 0x1b, 0x1b;
  beq lbl_801390b4;
  li r31, 0x1b;
  b lbl_801390c0;
lbl_801390b4:
  rlwinm. r0, r28, 0, 0x1c, 0x1c;
  beq lbl_801390c0;
  li r31, 0x11;
lbl_801390c0:
  cmplwi r31, 0x3fd;
  bne lbl_801390e0;
  lis r3, 0x8033;
  addi r3, r3, 0x5d50;
  lhz r0, 0x7c(r3);
  cmplwi r0, 0x3f9;
  bne lbl_801390e0;
  li r31, 0x3f9;
lbl_801390e0:
  addi r11, r1, 0x20;
  mr r3, r31;
  bl _restgpr_27;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: BTM_AclRegisterForChanges
// PAL: 0x801390fc..0x80139140
MARK_BINARY_BLOB(BTM_AclRegisterForChanges, 0x801390fc, 0x80139140);
asm UNKNOWN_FUNCTION(BTM_AclRegisterForChanges) {
  // clang-format off
  nofralloc;
  cmpwi r3, 0;
  bne lbl_80139118;
  lis r3, 0x8033;
  li r0, 0;
  addi r3, r3, 0x6278;
  stw r0, 0x4c8(r3);
  b lbl_80139138;
lbl_80139118:
  lis r4, 0x8033;
  addi r4, r4, 0x6278;
  lwz r0, 0x4c8(r4);
  cmpwi r0, 0;
  beq lbl_80139134;
  li r3, 2;
  blr;
lbl_80139134:
  stw r3, 0x4c8(r4);
lbl_80139138:
  li r3, 0;
  blr;
  // clang-format on
}

// Symbol: btm_qos_setup_complete
// PAL: 0x80139140..0x80139218
MARK_BINARY_BLOB(btm_qos_setup_complete, 0x80139140, 0x80139218);
asm UNKNOWN_FUNCTION(btm_qos_setup_complete) {
  // clang-format off
  nofralloc;
  stwu r1, -0x40(r1);
  mflr r0;
  stw r0, 0x44(r1);
  addi r11, r1, 0x40;
  bl _savegpr_27;
  lis r31, 0x8033;
  mr r27, r3;
  addi r31, r31, 0x6278;
  mr r28, r4;
  lwz r30, 0x618(r31);
  mr r29, r5;
  addi r3, r31, 0x600;
  bl btu_stop_timer;
  li r0, 0;
  cmpwi r30, 0;
  stw r0, 0x618(r31);
  beq lbl_80139200;
  cmpwi r29, 0;
  stb r27, 0x22(r1);
  sth r28, 0x20(r1);
  beq lbl_801391c4;
  lbz r0, 0(r29);
  stb r0, 8(r1);
  lbz r0, 1(r29);
  stb r0, 9(r1);
  lwz r0, 4(r29);
  stw r0, 0xc(r1);
  lwz r0, 0xc(r29);
  stw r0, 0x14(r1);
  lwz r0, 0x10(r29);
  stw r0, 0x18(r1);
  lwz r0, 0x14(r29);
  stw r0, 0x1c(r1);
lbl_801391c4:
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lbz r0, 0x27c0(r3);
  cmplwi r0, 5;
  blt lbl_801391f0;
  lis r3, 0xd;
  lis r4, 0x8028;
  lwz r5, 0x14(r29);
  addi r3, r3, 4;
  addi r4, r4, 0x37a4;
  bl LogMsg_1;
lbl_801391f0:
  mr r12, r30;
  addi r3, r1, 8;
  mtctr r12;
  bctrl;
lbl_80139200:
  addi r11, r1, 0x40;
  bl _restgpr_27;
  lwz r0, 0x44(r1);
  mtlr r0;
  addi r1, r1, 0x40;
  blr;
  // clang-format on
}

// Symbol: BTM_ReadRSSI
// PAL: 0x80139218..0x80139354
MARK_BINARY_BLOB(BTM_ReadRSSI, 0x80139218, 0x80139354);
asm UNKNOWN_FUNCTION(BTM_ReadRSSI) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  lis r5, 0x8033;
  stw r0, 0x24(r1);
  addi r5, r5, 0x6278;
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  mr r29, r4;
  stw r28, 0x10(r1);
  mr r28, r3;
  lbz r0, 0x27c0(r5);
  cmplwi r0, 3;
  blt lbl_8013927c;
  lis r3, 0xd;
  lis r4, 0x8028;
  lbz r5, 0(r28);
  addi r3, r3, 2;
  lbz r6, 1(r28);
  addi r4, r4, 0x37cc;
  lbz r7, 2(r28);
  lbz r8, 3(r28);
  lbz r9, 4(r28);
  lbz r10, 5(r28);
  bl LogMsg_6;
lbl_8013927c:
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lwz r0, 0x5e0(r3);
  cmpwi r0, 0;
  beq lbl_80139298;
  li r3, 2;
  b lbl_80139334;
lbl_80139298:
  addi r30, r3, 0x34;
  li r31, 0;
lbl_801392a0:
  lbz r0, 0x119(r30);
  cmpwi r0, 0;
  beq lbl_801392c8;
  mr r4, r28;
  addi r3, r30, 8;
  li r5, 6;
  bl memcmp;
  cmpwi r3, 0;
  bne lbl_801392c8;
  b lbl_801392dc;
lbl_801392c8:
  addi r31, r31, 1;
  addi r30, r30, 0x11c;
  cmplwi r31, 4;
  blt lbl_801392a0;
  li r30, 0;
lbl_801392dc:
  cmpwi r30, 0;
  beq lbl_80139330;
  lis r31, 0x8033;
  li r4, 9;
  addi r31, r31, 0x6278;
  li r5, 3;
  addi r3, r31, 0x5c8;
  bl btu_start_timer;
  stw r29, 0x5e0(r31);
  lhz r3, 0(r30);
  bl btsnd_hcic_read_rssi;
  clrlwi. r0, r3, 0x18;
  bne lbl_80139328;
  li r0, 0;
  addi r3, r31, 0x5c8;
  stw r0, 0x5e0(r31);
  bl btu_stop_timer;
  li r3, 3;
  b lbl_80139334;
lbl_80139328:
  li r3, 1;
  b lbl_80139334;
lbl_80139330:
  li r3, 7;
lbl_80139334:
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

// Symbol: BTM_ReadLinkQuality
// PAL: 0x80139354..0x80139490
MARK_BINARY_BLOB(BTM_ReadLinkQuality, 0x80139354, 0x80139490);
asm UNKNOWN_FUNCTION(BTM_ReadLinkQuality) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  lis r5, 0x8033;
  stw r0, 0x24(r1);
  addi r5, r5, 0x6278;
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  mr r29, r4;
  stw r28, 0x10(r1);
  mr r28, r3;
  lbz r0, 0x27c0(r5);
  cmplwi r0, 3;
  blt lbl_801393b8;
  lis r3, 0xd;
  lis r4, 0x8028;
  lbz r5, 0(r28);
  addi r3, r3, 2;
  lbz r6, 1(r28);
  addi r4, r4, 0x3800;
  lbz r7, 2(r28);
  lbz r8, 3(r28);
  lbz r9, 4(r28);
  lbz r10, 5(r28);
  bl LogMsg_6;
lbl_801393b8:
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lwz r0, 0x5fc(r3);
  cmpwi r0, 0;
  beq lbl_801393d4;
  li r3, 2;
  b lbl_80139470;
lbl_801393d4:
  addi r30, r3, 0x34;
  li r31, 0;
lbl_801393dc:
  lbz r0, 0x119(r30);
  cmpwi r0, 0;
  beq lbl_80139404;
  mr r4, r28;
  addi r3, r30, 8;
  li r5, 6;
  bl memcmp;
  cmpwi r3, 0;
  bne lbl_80139404;
  b lbl_80139418;
lbl_80139404:
  addi r31, r31, 1;
  addi r30, r30, 0x11c;
  cmplwi r31, 4;
  blt lbl_801393dc;
  li r30, 0;
lbl_80139418:
  cmpwi r30, 0;
  beq lbl_8013946c;
  lis r31, 0x8033;
  li r4, 9;
  addi r31, r31, 0x6278;
  li r5, 3;
  addi r3, r31, 0x5e4;
  bl btu_start_timer;
  stw r29, 0x5fc(r31);
  lhz r3, 0(r30);
  bl btsnd_hcic_get_link_quality;
  clrlwi. r0, r3, 0x18;
  bne lbl_80139464;
  addi r3, r31, 0x5e4;
  bl btu_stop_timer;
  li r0, 0;
  li r3, 3;
  stw r0, 0x5fc(r31);
  b lbl_80139470;
lbl_80139464:
  li r3, 1;
  b lbl_80139470;
lbl_8013946c:
  li r3, 7;
lbl_80139470:
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

// Symbol: btm_read_rssi_complete
// PAL: 0x80139490..0x801395ac
MARK_BINARY_BLOB(btm_read_rssi_complete, 0x80139490, 0x801395ac);
asm UNKNOWN_FUNCTION(btm_read_rssi_complete) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  stw r31, 0x2c(r1);
  lis r31, 0x8033;
  addi r31, r31, 0x6278;
  stw r30, 0x28(r1);
  stw r29, 0x24(r1);
  addi r29, r31, 0x34;
  stw r28, 0x20(r1);
  mr r28, r3;
  addi r3, r31, 0x5c8;
  lwz r30, 0x5e0(r31);
  bl btu_stop_timer;
  li r0, 0;
  cmpwi r30, 0;
  stw r0, 0x5e0(r31);
  beq lbl_8013958c;
  lbz r6, 0(r28);
  cmpwi r6, 0;
  stb r6, 9(r1);
  bne lbl_80139574;
  stb r0, 8(r1);
  lbz r0, 0x27c0(r31);
  lbz r3, 2(r28);
  lbz r4, 1(r28);
  cmplwi r0, 4;
  lbz r5, 3(r28);
  slwi r0, r3, 8;
  add r0, r4, r0;
  stb r5, 0xa(r1);
  clrlwi r31, r0, 0x10;
  blt lbl_8013952c;
  lis r3, 0xd;
  lis r4, 0x8028;
  addi r3, r3, 3;
  extsb r5, r5;
  addi r4, r4, 0x383c;
  bl LogMsg_2;
lbl_8013952c:
  li r0, 4;
  li r3, 0;
  mtctr r0;
lbl_80139538:
  lbz r0, 0x119(r29);
  cmpwi r0, 0;
  beq lbl_80139564;
  lhz r0, 0(r29);
  cmplw r31, r0;
  bne lbl_80139564;
  addi r3, r1, 0xb;
  addi r4, r29, 8;
  li r5, 6;
  bl memcpy;
  b lbl_8013957c;
lbl_80139564:
  addi r3, r3, 1;
  addi r29, r29, 0x11c;
  bdnz lbl_80139538;
  b lbl_8013957c;
lbl_80139574:
  li r0, 0xa;
  stb r0, 8(r1);
lbl_8013957c:
  mr r12, r30;
  addi r3, r1, 8;
  mtctr r12;
  bctrl;
lbl_8013958c:
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

// Symbol: btm_read_link_quality_complete
// PAL: 0x801395ac..0x801396c4
MARK_BINARY_BLOB(btm_read_link_quality_complete, 0x801395ac, 0x801396c4);
asm UNKNOWN_FUNCTION(btm_read_link_quality_complete) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  stw r31, 0x2c(r1);
  lis r31, 0x8033;
  addi r31, r31, 0x6278;
  stw r30, 0x28(r1);
  stw r29, 0x24(r1);
  addi r29, r31, 0x34;
  stw r28, 0x20(r1);
  mr r28, r3;
  addi r3, r31, 0x5c8;
  lwz r30, 0x5fc(r31);
  bl btu_stop_timer;
  li r0, 0;
  cmpwi r30, 0;
  stw r0, 0x5fc(r31);
  beq lbl_801396a4;
  lbz r6, 0(r28);
  cmpwi r6, 0;
  stb r6, 9(r1);
  bne lbl_8013968c;
  stb r0, 8(r1);
  lbz r0, 0x27c0(r31);
  lbz r3, 2(r28);
  lbz r4, 1(r28);
  cmplwi r0, 4;
  lbz r5, 3(r28);
  slwi r0, r3, 8;
  add r0, r4, r0;
  stb r5, 0xa(r1);
  clrlwi r31, r0, 0x10;
  blt lbl_80139644;
  lis r3, 0xd;
  lis r4, 0x8028;
  addi r3, r3, 3;
  addi r4, r4, 0x386c;
  bl LogMsg_2;
lbl_80139644:
  li r0, 4;
  li r3, 0;
  mtctr r0;
lbl_80139650:
  lbz r0, 0x119(r29);
  cmpwi r0, 0;
  beq lbl_8013967c;
  lhz r0, 0(r29);
  cmplw r31, r0;
  bne lbl_8013967c;
  addi r3, r1, 0xb;
  addi r4, r29, 8;
  li r5, 6;
  bl memcpy;
  b lbl_80139694;
lbl_8013967c:
  addi r3, r3, 1;
  addi r29, r29, 0x11c;
  bdnz lbl_80139650;
  b lbl_80139694;
lbl_8013968c:
  li r0, 0xa;
  stb r0, 8(r1);
lbl_80139694:
  mr r12, r30;
  addi r3, r1, 8;
  mtctr r12;
  bctrl;
lbl_801396a4:
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

// Symbol: btm_remove_acl
// PAL: 0x801396c4..0x80139780
MARK_BINARY_BLOB(btm_remove_acl, 0x801396c4, 0x80139780);
asm UNKNOWN_FUNCTION(btm_remove_acl) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  lis r4, 0x8033;
  stw r0, 0x24(r1);
  addi r4, r4, 0x6278;
  stw r31, 0x1c(r1);
  li r31, 0;
  stw r30, 0x18(r1);
  addi r30, r4, 0x34;
  stw r29, 0x14(r1);
  mr r29, r3;
lbl_801396f0:
  lbz r0, 0x119(r30);
  cmpwi r0, 0;
  beq lbl_80139718;
  mr r4, r29;
  addi r3, r30, 8;
  li r5, 6;
  bl memcmp;
  cmpwi r3, 0;
  bne lbl_80139718;
  b lbl_8013972c;
lbl_80139718:
  addi r31, r31, 1;
  addi r30, r30, 0x11c;
  cmplwi r31, 4;
  blt lbl_801396f0;
  li r30, 0;
lbl_8013972c:
  cmpwi r30, 0;
  beq lbl_8013973c;
  lhz r3, 0(r30);
  b lbl_80139744;
lbl_8013973c:
  lis r3, 1;
  addi r3, r3, -1;
lbl_80139744:
  clrlwi r3, r3, 0x10;
  li r4, 0x13;
  bl btsnd_hcic_disconnect;
  clrlwi. r0, r3, 0x18;
  bne lbl_80139760;
  li r3, 3;
  b lbl_80139764;
lbl_80139760:
  li r3, 0;
lbl_80139764:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: btm_chg_all_acl_pkt_types
// PAL: 0x80139780..0x801399a0
MARK_BINARY_BLOB(btm_chg_all_acl_pkt_types, 0x80139780, 0x801399a0);
asm UNKNOWN_FUNCTION(btm_chg_all_acl_pkt_types) {
  // clang-format off
  nofralloc;
  stwu r1, -0x40(r1);
  mflr r0;
  stw r0, 0x44(r1);
  addi r11, r1, 0x40;
  bl _savegpr_24;
  lis r4, 0x8033;
  cmpwi r3, 0;
  addi r31, r4, 0x6278;
  lis r30, 0x8028;
  addi r30, r30, 0x3520;
  addi r28, r31, 0x34;
  beq lbl_80139874;
  li r29, 0;
  lis r26, 0xd;
  li r24, -13063;
lbl_801397bc:
  lbz r0, 0x119(r28);
  cmpwi r0, 0;
  beq lbl_80139860;
  lbz r0, 0x27c0(r31);
  cmplwi r0, 5;
  blt lbl_801397e4;
  lhz r5, 0(r28);
  addi r3, r26, 4;
  addi r4, r30, 0x38c;
  bl LogMsg_1;
lbl_801397e4:
  lhz r0, 2(r28);
  li r5, 0x18;
  sth r0, 4(r28);
  lbz r3, 0x636(r31);
  cmplwi r3, 3;
  blt lbl_80139804;
  ori r0, r5, 0x3300;
  clrlwi r5, r0, 0x10;
lbl_80139804:
  lhz r4, 0x654(r31);
  cmplwi cr1, r3, 3;
  and r0, r5, r4;
  andi. r3, r0, 0xcc18;
  and r25, r3, r24;
  blt cr1, lbl_8013982c;
  or r0, r5, r4;
  andi. r0, r0, 0x3306;
  or r0, r3, r0;
  clrlwi r25, r0, 0x10;
lbl_8013982c:
  lbz r0, 0x27c0(r31);
  cmplwi r0, 4;
  blt lbl_80139848;
  addi r3, r26, 3;
  addi r4, r30, 0x40;
  clrlwi r5, r25, 0x10;
  bl LogMsg_1;
lbl_80139848:
  lhz r3, 0(r28);
  clrlwi r4, r25, 0x10;
  bl btsnd_hcic_change_conn_type;
  clrlwi. r0, r3, 0x18;
  beq lbl_80139860;
  sth r25, 2(r28);
lbl_80139860:
  addi r29, r29, 1;
  addi r28, r28, 0x11c;
  cmplwi r29, 4;
  blt lbl_801397bc;
  b lbl_80139988;
lbl_80139874:
  li r29, 0;
  lis r24, 0xd;
  li r25, 0;
  li r27, -13063;
lbl_80139884:
  lbz r0, 0x119(r28);
  cmpwi r0, 0;
  beq lbl_80139978;
  lhz r0, 4(r28);
  cmpwi r0, 0;
  beq lbl_80139978;
  addi r3, r28, 8;
  addi r4, r1, 8;
  bl BTM_ReadPowerMode;
  clrlwi. r0, r3, 0x18;
  bne lbl_80139978;
  lbz r0, 8(r1);
  cmplwi r0, 2;
  bne lbl_801398f0;
  lbz r0, 0x27c0(r31);
  cmplwi r0, 5;
  blt lbl_801398d8;
  lhz r5, 0(r28);
  addi r3, r24, 4;
  addi r4, r30, 0x3bc;
  bl LogMsg_1;
lbl_801398d8:
  stb r25, 0x14(r1);
  addi r4, r28, 8;
  addi r5, r1, 0xc;
  li r3, 0x80;
  bl BTM_SetPowerMode;
  b lbl_80139978;
lbl_801398f0:
  lbz r0, 0x27c0(r31);
  cmplwi r0, 5;
  blt lbl_80139910;
  lhz r5, 0(r28);
  addi r3, r24, 4;
  lhz r6, 2(r28);
  addi r4, r30, 0x3ec;
  bl LogMsg_2;
lbl_80139910:
  lhz r4, 4(r28);
  lhz r5, 0x654(r31);
  lbz r0, 0x636(r31);
  and r3, r4, r5;
  andi. r3, r3, 0xcc18;
  cmplwi r0, 3;
  and r26, r3, r27;
  blt lbl_80139940;
  or r0, r4, r5;
  andi. r0, r0, 0x3306;
  or r0, r3, r0;
  clrlwi r26, r0, 0x10;
lbl_80139940:
  lbz r0, 0x27c0(r31);
  cmplwi r0, 4;
  blt lbl_8013995c;
  addi r3, r24, 3;
  addi r4, r30, 0x40;
  clrlwi r5, r26, 0x10;
  bl LogMsg_1;
lbl_8013995c:
  lhz r3, 0(r28);
  clrlwi r4, r26, 0x10;
  bl btsnd_hcic_change_conn_type;
  clrlwi. r0, r3, 0x18;
  beq lbl_80139974;
  sth r26, 2(r28);
lbl_80139974:
  sth r25, 4(r28);
lbl_80139978:
  addi r29, r29, 1;
  addi r28, r28, 0x11c;
  cmplwi r29, 4;
  blt lbl_80139884;
lbl_80139988:
  addi r11, r1, 0x40;
  bl _restgpr_24;
  lwz r0, 0x44(r1);
  mtlr r0;
  addi r1, r1, 0x40;
  blr;
  // clang-format on
}

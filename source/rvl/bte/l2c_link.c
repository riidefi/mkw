#include "l2c_link.h"

#include <string.h>

#include "gki_buffer.h"
#include "bte_logmsg.h"
#include "bte_hcisu.h"
#include "bte_task1.h"
#include "btm_acl.h"
#include "btm_dev.h"
#include "btm_pm.h"
#include "btm_sco.h"
#include "btm_sec.h"
#include "hcicmds.h"
#include "l2c_csm.h"
#include "l2c_main.h"
#include "l2c_utils.h"

// Symbol: l2c_link_hci_conn_req
// PAL: 0x8014c108..0x8014c25c
MARK_BINARY_BLOB(l2c_link_hci_conn_req, 0x8014c108, 0x8014c25c);
asm UNKNOWN_FUNCTION(l2c_link_hci_conn_req) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  mr r29, r3;
  li r3, 2;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  mr r30, r3;
  beq lbl_8014c240;
  mr r3, r29;
  bl l2cu_find_lcb_by_bd_addr;
  cmpwi r3, 0;
  mr r31, r3;
  bne lbl_8014c1cc;
  mr r3, r29;
  bl l2cu_allocate_lcb;
  cmpwi r3, 0;
  mr r31, r3;
  bne lbl_8014c194;
  mr r3, r30;
  mr r4, r29;
  li r5, 0x14;
  bl btsnd_hcic_reject_conn;
  lis r3, 0x8034;
  lbz r0, -0x6cc0(r3);
  cmplwi r0, 1;
  blt lbl_8014c240;
  lis r4, 0x8028;
  lis r3, 8;
  addi r4, r4, 0x6468;
  bl LogMsg_0;
  b lbl_8014c240;
lbl_8014c194:
  bl l2cu_get_conn_role;
  mr r0, r3;
  stb r3, 0x30(r31);
  mr r3, r30;
  mr r4, r29;
  clrlwi r5, r0, 0x18;
  bl btsnd_hcic_accept_conn;
  li r0, 3;
  addi r3, r31, 0x10;
  stw r0, 4(r31);
  li r4, 2;
  li r5, 0x3c;
  bl btu_start_timer;
  b lbl_8014c240;
lbl_8014c1cc:
  lwz r0, 4(r3);
  cmpwi r0, 3;
  beq lbl_8014c1e0;
  cmpwi r0, 1;
  bne lbl_8014c1fc;
lbl_8014c1e0:
  lbz r5, 0x30(r31);
  mr r3, r30;
  mr r4, r29;
  bl btsnd_hcic_accept_conn;
  li r0, 3;
  stw r0, 4(r31);
  b lbl_8014c240;
lbl_8014c1fc:
  cmpwi r0, 5;
  bne lbl_8014c218;
  mr r3, r30;
  mr r4, r29;
  li r5, 0x15;
  bl btsnd_hcic_reject_conn;
  b lbl_8014c240;
lbl_8014c218:
  lis r3, 0x8034;
  lbz r0, -0x6cc0(r3);
  cmplwi r0, 1;
  blt lbl_8014c238;
  lis r4, 0x8028;
  lis r3, 8;
  addi r4, r4, 0x6488;
  bl LogMsg_0;
lbl_8014c238:
  mr r3, r30;
  bl GKI_freebuf;
lbl_8014c240:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: l2c_link_hci_conn_comp
// PAL: 0x8014c25c..0x8014c494
MARK_BINARY_BLOB(l2c_link_hci_conn_comp, 0x8014c25c, 0x8014c494);
asm UNKNOWN_FUNCTION(l2c_link_hci_conn_comp) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  stw r31, 0x2c(r1);
  stw r30, 0x28(r1);
  mr r30, r5;
  li r5, 6;
  stw r29, 0x24(r1);
  mr r29, r4;
  mr r4, r30;
  stw r28, 0x20(r1);
  mr r28, r3;
  stb r3, 0xe(r1);
  addi r3, r1, 8;
  bl memcpy;
  addi r3, r1, 8;
  bl l2cu_find_lcb_by_bd_addr;
  cmpwi r3, 0;
  mr r31, r3;
  bne lbl_8014c2e8;
  mr r3, r29;
  bl btm_sec_is_bonding;
  clrlwi. r0, r3, 0x18;
  bne lbl_8014c2e0;
  lis r3, 0x8034;
  lbz r0, -0x6cc0(r3);
  cmplwi r0, 2;
  blt lbl_8014c2e0;
  lis r3, 8;
  lis r4, 0x8028;
  addi r3, r3, 1;
  addi r4, r4, 0x64b0;
  bl LogMsg_0;
lbl_8014c2e0:
  li r3, 0;
  b lbl_8014c474;
lbl_8014c2e8:
  lwz r5, 4(r3);
  cmpwi r5, 3;
  beq lbl_8014c334;
  lis r3, 0x8034;
  lbz r0, -0x6cc0(r3);
  cmplwi r0, 1;
  blt lbl_8014c318;
  lis r4, 0x8028;
  mr r6, r28;
  lis r3, 8;
  addi r4, r4, 0x64d8;
  bl LogMsg_2;
lbl_8014c318:
  cmpwi r28, 0;
  beq lbl_8014c32c;
  lhz r3, 0x28(r31);
  mr r4, r28;
  bl l2c_link_hci_disc_comp;
lbl_8014c32c:
  li r3, 0;
  b lbl_8014c474;
lbl_8014c334:
  sth r29, 0x28(r3);
  lbz r0, 0xe(r1);
  cmpwi r0, 0;
  bne lbl_8014c418;
  li r0, 4;
  stw r0, 4(r3);
  mr r3, r30;
  bl btm_find_dev;
  cmpwi r3, 0;
  mr r5, r3;
  beq lbl_8014c37c;
  lbz r7, 0x30(r31);
  addi r4, r5, 0x22;
  mr r6, r29;
  addi r3, r1, 8;
  addi r5, r5, 0x35;
  bl btm_acl_created;
  b lbl_8014c394;
lbl_8014c37c:
  lbz r7, 0x30(r31);
  mr r6, r29;
  addi r3, r1, 8;
  li r4, 0;
  li r5, 0;
  bl btm_acl_created;
lbl_8014c394:
  li r3, 0;
  bl l2c_process_held_packets;
  addi r3, r31, 0x10;
  bl btu_stop_timer;
  lwz r30, 8(r31);
  b lbl_8014c3c0;
lbl_8014c3ac:
  mr r3, r30;
  addi r5, r1, 8;
  li r4, 0;
  bl l2c_csm_execute;
  lwz r30, 8(r30);
lbl_8014c3c0:
  cmpwi r30, 0;
  bne lbl_8014c3ac;
  lwz r0, 0x54(r31);
  cmpwi r0, 0;
  beq lbl_8014c3f8;
  mr r3, r31;
  li r4, 0;
  li r5, 0;
  bl l2cu_send_peer_echo_req;
  addi r3, r31, 0x10;
  li r4, 2;
  li r5, 0x1e;
  bl btu_start_timer;
  b lbl_8014c470;
lbl_8014c3f8:
  lwz r0, 8(r31);
  cmpwi r0, 0;
  bne lbl_8014c470;
  addi r3, r31, 0x10;
  li r4, 2;
  li r5, 0x3c;
  bl btu_start_timer;
  b lbl_8014c470;
lbl_8014c418:
  cmplwi r0, 9;
  bne lbl_8014c444;
  bl l2cu_lcb_disconnecting;
  clrlwi. r0, r3, 0x18;
  beq lbl_8014c444;
  li r0, 1;
  lis r3, 1;
  stw r0, 4(r31);
  addi r0, r3, -1;
  sth r0, 0x28(r31);
  b lbl_8014c470;
lbl_8014c444:
  lwz r3, 8(r31);
  b lbl_8014c460;
lbl_8014c44c:
  lwz r30, 8(r3);
  addi r5, r1, 8;
  li r4, 1;
  bl l2c_csm_execute;
  mr r3, r30;
lbl_8014c460:
  cmpwi r3, 0;
  bne lbl_8014c44c;
  mr r3, r31;
  bl l2cu_release_lcb;
lbl_8014c470:
  li r3, 1;
lbl_8014c474:
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

// Symbol: l2c_link_sec_comp
// PAL: 0x8014c494..0x8014c548
MARK_BINARY_BLOB(l2c_link_sec_comp, 0x8014c494, 0x8014c548);
asm UNKNOWN_FUNCTION(l2c_link_sec_comp) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r3;
  addi r3, r1, 8;
  stw r30, 0x18(r1);
  mr r30, r5;
  mr r4, r31;
  stb r5, 0xe(r1);
  li r5, 6;
  bl memcpy;
  mr r3, r31;
  bl l2cu_find_lcb_by_bd_addr;
  cmpwi r3, 0;
  bne lbl_8014c4fc;
  lis r3, 0x8034;
  lbz r0, -0x6cc0(r3);
  cmplwi r0, 2;
  blt lbl_8014c530;
  lis r3, 8;
  lis r4, 0x8028;
  addi r3, r3, 1;
  addi r4, r4, 0x650c;
  bl LogMsg_0;
  b lbl_8014c530;
lbl_8014c4fc:
  cntlzw r0, r30;
  lwz r3, 8(r3);
  rlwinm r0, r0, 0x1b, 0x1f, 0x1f;
  neg r31, r0;
  b lbl_8014c528;
lbl_8014c510:
  addi r0, r31, 8;
  lwz r30, 8(r3);
  clrlwi r4, r0, 0x18;
  addi r5, r1, 8;
  bl l2c_csm_execute;
  mr r3, r30;
lbl_8014c528:
  cmpwi r3, 0;
  bne lbl_8014c510;
lbl_8014c530:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: l2c_link_hci_disc_comp
// PAL: 0x8014c548..0x8014c604
MARK_BINARY_BLOB(l2c_link_hci_disc_comp, 0x8014c548, 0x8014c604);
asm UNKNOWN_FUNCTION(l2c_link_hci_disc_comp) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  li r30, 1;
  stw r29, 0x14(r1);
  stb r4, 8(r1);
  bl l2cu_find_lcb_by_handle;
  cmpwi r3, 0;
  mr r31, r3;
  bne lbl_8014c580;
  li r30, 0;
  b lbl_8014c5d0;
lbl_8014c580:
  lis r4, 0x8033;
  addi r4, r4, 0x6278;
  lbz r0, 0x27bf(r4);
  cmplwi r0, 0xe;
  beq lbl_8014c59c;
  lbz r0, 8(r1);
  stb r0, 0x27bf(r4);
lbl_8014c59c:
  lwz r3, 8(r3);
  b lbl_8014c5b8;
lbl_8014c5a4:
  lwz r29, 8(r3);
  addi r5, r1, 8;
  li r4, 3;
  bl l2c_csm_execute;
  mr r3, r29;
lbl_8014c5b8:
  cmpwi r3, 0;
  bne lbl_8014c5a4;
  addi r3, r31, 0x2a;
  bl btm_sco_acl_removed;
  mr r3, r31;
  bl l2cu_release_lcb;
lbl_8014c5d0:
  li r3, 1;
  bl l2cu_find_lcb_by_state;
  cmpwi r3, 0;
  beq lbl_8014c5e4;
  bl l2cu_create_conn;
lbl_8014c5e4:
  mr r3, r30;
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: l2c_link_hci_qos_violation
// PAL: 0x8014c604..0x8014c674
MARK_BINARY_BLOB(l2c_link_hci_qos_violation, 0x8014c604, 0x8014c674);
asm UNKNOWN_FUNCTION(l2c_link_hci_qos_violation) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  bl l2cu_find_lcb_by_handle;
  cmpwi r3, 0;
  bne lbl_8014c628;
  li r3, 0;
  b lbl_8014c660;
lbl_8014c628:
  lwz r31, 8(r3);
  b lbl_8014c654;
lbl_8014c630:
  lwz r3, 0x30(r31);
  lwz r0, 0x20(r3);
  cmpwi r0, 0;
  beq lbl_8014c650;
  mr r3, r31;
  li r4, 6;
  li r5, 0;
  bl l2c_csm_execute;
lbl_8014c650:
  lwz r31, 8(r31);
lbl_8014c654:
  cmpwi r31, 0;
  bne lbl_8014c630;
  li r3, 1;
lbl_8014c660:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: l2c_link_timeout
// PAL: 0x8014c674..0x8014c7e8
MARK_BINARY_BLOB(l2c_link_timeout, 0x8014c674, 0x8014c7e8);
asm UNKNOWN_FUNCTION(l2c_link_timeout) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  stw r30, 8(r1);
  mr r30, r3;
  lwz r0, 4(r3);
  cmpwi r0, 2;
  beq lbl_8014c6b0;
  cmpwi r0, 3;
  beq lbl_8014c6b0;
  cmpwi r0, 1;
  beq lbl_8014c6b0;
  cmpwi r0, 5;
  bne lbl_8014c6dc;
lbl_8014c6b0:
  lwz r3, 8(r3);
  b lbl_8014c6cc;
lbl_8014c6b8:
  lwz r31, 8(r3);
  li r4, 3;
  li r5, 0;
  bl l2c_csm_execute;
  mr r3, r31;
lbl_8014c6cc:
  cmpwi r3, 0;
  bne lbl_8014c6b8;
  mr r3, r30;
  bl l2cu_release_lcb;
lbl_8014c6dc:
  lwz r0, 4(r30);
  cmpwi r0, 4;
  bne lbl_8014c7d0;
  lwz r12, 0x54(r30);
  cmpwi r12, 0;
  beq lbl_8014c750;
  li r0, 0;
  li r3, 2;
  stw r0, 0x54(r30);
  mtctr r12;
  bctrl;
  lis r3, 0x8034;
  lbz r0, -0x6cc0(r3);
  cmplwi r0, 2;
  blt lbl_8014c72c;
  lis r3, 8;
  lis r4, 0x8028;
  addi r3, r3, 1;
  addi r4, r4, 0x6534;
  bl LogMsg_0;
lbl_8014c72c:
  lwz r3, 8(r30);
  b lbl_8014c748;
lbl_8014c734:
  lwz r31, 8(r3);
  li r4, 3;
  li r5, 0;
  bl l2c_csm_execute;
  mr r3, r31;
lbl_8014c748:
  cmpwi r3, 0;
  bne lbl_8014c734;
lbl_8014c750:
  lwz r0, 8(r30);
  cmpwi r0, 0;
  bne lbl_8014c7c0;
  lhz r3, 0x28(r30);
  li r4, 0x13;
  bl btm_sec_disconnect;
  clrlwi r0, r3, 0x18;
  cmplwi r0, 1;
  bne lbl_8014c784;
  li r0, 5;
  li r3, 0x1e;
  stw r0, 4(r30);
  b lbl_8014c7a4;
lbl_8014c784:
  cmpwi r0, 0;
  bne lbl_8014c7a0;
  li r0, 5;
  lis r3, 1;
  stw r0, 4(r30);
  addi r3, r3, -1;
  b lbl_8014c7a4;
lbl_8014c7a0:
  li r3, 1;
lbl_8014c7a4:
  clrlwi r5, r3, 0x10;
  cmplwi r5, 0xffff;
  beq lbl_8014c7d0;
  addi r3, r30, 0x10;
  li r4, 2;
  bl btu_start_timer;
  b lbl_8014c7d0;
lbl_8014c7c0:
  mr r3, r30;
  li r4, 0;
  li r5, 0;
  bl l2c_link_check_send_pkts;
lbl_8014c7d0:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: l2c_link_send_to_lower
// PAL: 0x8014c7e8..0x8014c8f0
MARK_BINARY_BLOB(l2c_link_send_to_lower, 0x8014c7e8, 0x8014c8f0);
asm UNKNOWN_FUNCTION(l2c_link_send_to_lower) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r6, 0x8033;
  stw r0, 0x14(r1);
  addi r6, r6, 0x5d50;
  mr r0, r4;
  lhz r7, 2(r4);
  lhz r5, 0x7e(r6);
  cmplw r7, r5;
  bgt lbl_8014c84c;
  lhz r4, 0x36(r3);
  lis r6, 0x8034;
  lhz r5, 0x38(r3);
  addi r6, r6, -27840;
  addi r7, r4, -1;
  li r4, 0x2100;
  addi r5, r5, 1;
  sth r7, 0x36(r3);
  sth r5, 0x38(r3);
  mr r3, r0;
  lhz r5, 4(r6);
  addi r0, r5, -1;
  sth r0, 4(r6);
  bl bte_hcisu_send;
  b lbl_8014c8dc;
lbl_8014c84c:
  lhz r8, 0x7c(r6);
  lis r5, 0x8034;
  addi r5, r5, -27840;
  add r6, r7, r8;
  lhz r7, 4(r5);
  addi r5, r6, -5;
  divw r5, r5, r8;
  clrlwi r8, r5, 0x10;
  cmplw r8, r7;
  ble lbl_8014c884;
  sth r7, 6(r4);
  li r5, 1;
  mr r8, r7;
  stb r5, 0x40(r3);
lbl_8014c884:
  lhz r6, 0x36(r3);
  clrlwi r5, r8, 0x10;
  cmplw r5, r6;
  ble lbl_8014c8a4;
  sth r6, 6(r4);
  li r4, 1;
  mr r8, r6;
  stb r4, 0x40(r3);
lbl_8014c8a4:
  lis r6, 0x8034;
  li r4, 0x2100;
  addi r6, r6, -27840;
  lhz r5, 4(r6);
  subf r5, r8, r5;
  sth r5, 4(r6);
  lhz r6, 0x36(r3);
  lhz r5, 0x38(r3);
  subf r6, r8, r6;
  add r5, r5, r8;
  sth r6, 0x36(r3);
  sth r5, 0x38(r3);
  mr r3, r0;
  bl bte_hcisu_send;
lbl_8014c8dc:
  lwz r0, 0x14(r1);
  li r3, 1;
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: l2c_link_check_send_pkts
// PAL: 0x8014c8f0..0x8014cbbc
MARK_BINARY_BLOB(l2c_link_check_send_pkts, 0x8014c8f0, 0x8014cbbc);
asm UNKNOWN_FUNCTION(l2c_link_check_send_pkts) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_26;
  cmpwi r5, 0;
  lis r31, 0x8028;
  mr r29, r3;
  mr r30, r5;
  addi r31, r31, 0x6468;
  beq lbl_8014ca0c;
  lhz r4, 0x4c(r3);
  lhz r0, 0x3a(r3);
  cmplw r4, r0;
  blt lbl_8014c9bc;
  lbz r0, 0x41(r3);
  cmpwi r0, 0;
  bne lbl_8014c9bc;
  lwz r26, 8(r3);
  lis r28, 8;
  lis r27, 0x8034;
  b lbl_8014c9ac;
lbl_8014c948:
  lbz r0, -0x6cc0(r27);
  cmplwi r0, 2;
  blt lbl_8014c964;
  lhz r5, 0x14(r26);
  addi r3, r28, 1;
  addi r4, r31, 0xe4;
  bl LogMsg_1;
lbl_8014c964:
  lwz r3, 0x30(r26);
  lwz r0, 0x28(r3);
  cmpwi r0, 0;
  beq lbl_8014c9a8;
  lbz r0, -0x6cc0(r27);
  cmplwi r0, 3;
  blt lbl_8014c990;
  lhz r5, 0x14(r26);
  addi r3, r28, 2;
  addi r4, r31, 0x110;
  bl LogMsg_1;
lbl_8014c990:
  lwz r5, 0x30(r26);
  li r4, 1;
  lhz r3, 0x14(r26);
  lwz r12, 0x28(r5);
  mtctr r12;
  bctrl;
lbl_8014c9a8:
  lwz r26, 8(r26);
lbl_8014c9ac:
  cmpwi r26, 0;
  bne lbl_8014c948;
  li r0, 1;
  stb r0, 0x41(r29);
lbl_8014c9bc:
  lhz r3, 0x4c(r29);
  lhz r0, 0x3e(r29);
  cmplw r3, r0;
  bgt lbl_8014c9e4;
  li r0, 0;
  mr r4, r30;
  sth r0, 6(r30);
  addi r3, r29, 0x44;
  bl GKI_enqueue;
  b lbl_8014ca0c;
lbl_8014c9e4:
  mr r3, r30;
  bl GKI_freebuf;
  lis r3, 0x8034;
  lbz r0, -0x6cc0(r3);
  cmplwi r0, 2;
  blt lbl_8014ca0c;
  lis r3, 8;
  addi r4, r31, 0x150;
  addi r3, r3, 1;
  bl LogMsg_0;
lbl_8014ca0c:
  lbz r0, 0x40(r29);
  cmpwi r0, 0;
  bne lbl_8014cba4;
  addi r3, r29, 0x2a;
  addi r4, r1, 8;
  bl BTM_ReadPowerMode;
  clrlwi. r0, r3, 0x18;
  bne lbl_8014ca70;
  lbz r0, 8(r1);
  cmplwi r0, 3;
  bne lbl_8014ca70;
  lhz r0, 0x4c(r29);
  cmpwi r0, 0;
  beq lbl_8014ca70;
  li r0, 0;
  addi r4, r29, 0x2a;
  stb r0, 0x14(r1);
  addi r5, r1, 0xc;
  li r3, 0x80;
  bl BTM_SetPowerMode;
  addi r3, r29, 0x10;
  li r4, 2;
  li r5, 1;
  bl btu_start_timer;
  b lbl_8014cba4;
lbl_8014ca70:
  lis r28, 0x8034;
  addi r28, r28, -27840;
  b lbl_8014cac8;
lbl_8014ca7c:
  lwz r3, 0x44(r29);
  cmpwi r3, 0;
  beq lbl_8014cae0;
  lhz r0, 6(r3);
  cmpwi r0, 0;
  bne lbl_8014cae0;
  lbz r0, 0x40(r29);
  cmpwi r0, 0;
  bne lbl_8014cba4;
  addi r3, r29, 0x44;
  bl GKI_dequeue;
  cmpwi r3, 0;
  mr r30, r3;
  beq lbl_8014cae0;
  mr r3, r29;
  mr r4, r30;
  bl l2c_link_send_to_lower;
  clrlwi. r0, r3, 0x18;
  beq lbl_8014cae0;
lbl_8014cac8:
  lhz r0, 4(r28);
  cmpwi r0, 0;
  beq lbl_8014cae0;
  lhz r0, 0x36(r29);
  cmpwi r0, 0;
  bne lbl_8014ca7c;
lbl_8014cae0:
  lbz r0, 0x40(r29);
  cmpwi r0, 0;
  bne lbl_8014cba4;
  lhz r0, 0x4c(r29);
  cmpwi r0, 0;
  beq lbl_8014cb14;
  lhz r0, 0x36(r29);
  cmpwi r0, 0;
  beq lbl_8014cb14;
  addi r3, r29, 0x10;
  li r4, 2;
  li r5, 2;
  bl btu_start_timer;
lbl_8014cb14:
  lbz r0, 0x41(r29);
  cmpwi r0, 0;
  beq lbl_8014cba4;
  lhz r3, 0x4c(r29);
  lhz r0, 0x3c(r29);
  cmplw r3, r0;
  bgt lbl_8014cba4;
  li r0, 0;
  lwz r27, 8(r29);
  stb r0, 0x41(r29);
  lis r30, 8;
  lis r28, 0x8034;
  b lbl_8014cb9c;
lbl_8014cb48:
  lwz r3, 0x30(r27);
  lwz r0, 0x28(r3);
  cmpwi r0, 0;
  beq lbl_8014cb98;
  lbz r0, -0x6cc0(r28);
  cmplwi r0, 3;
  blt lbl_8014cb74;
  lhz r5, 0x14(r27);
  addi r3, r30, 2;
  addi r4, r31, 0x170;
  bl LogMsg_1;
lbl_8014cb74:
  lwz r5, 0x30(r27);
  li r4, 0;
  lhz r3, 0x14(r27);
  lwz r12, 0x28(r5);
  mtctr r12;
  bctrl;
  lbz r0, 0x41(r29);
  cmpwi r0, 0;
  bne lbl_8014cba4;
lbl_8014cb98:
  lwz r27, 8(r27);
lbl_8014cb9c:
  cmpwi r27, 0;
  bne lbl_8014cb48;
lbl_8014cba4:
  addi r11, r1, 0x30;
  bl _restgpr_26;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: l2c_link_adjust_allocation
// PAL: 0x8014cbbc..0x8014cd54
MARK_BINARY_BLOB(l2c_link_adjust_allocation, 0x8014cbbc, 0x8014cd54);
asm UNKNOWN_FUNCTION(l2c_link_adjust_allocation) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_23;
  lis r3, 0x8034;
  li r26, 0;
  addi r3, r3, -27840;
  lhz r4, 0x7b8(r3);
  cmpwi r4, 0;
  beq lbl_8014cd3c;
  lbz r0, 8(r3);
  cmpwi r0, 0;
  beq lbl_8014cc04;
  lbz r0, 0x62(r3);
  cmplwi r0, 1;
  bne lbl_8014cc04;
  li r26, 1;
lbl_8014cc04:
  lbz r0, 0x64(r3);
  cmpwi r0, 0;
  beq lbl_8014cc20;
  lbz r0, 0xbe(r3);
  cmplwi r0, 1;
  bne lbl_8014cc20;
  addi r26, r26, 1;
lbl_8014cc20:
  lbz r0, 0xc0(r3);
  cmpwi r0, 0;
  beq lbl_8014cc3c;
  lbz r0, 0x11a(r3);
  cmplwi r0, 1;
  bne lbl_8014cc3c;
  addi r26, r26, 1;
lbl_8014cc3c:
  lbz r0, 0x11c(r3);
  cmpwi r0, 0;
  beq lbl_8014cc58;
  lbz r0, 0x176(r3);
  cmplwi r0, 1;
  bne lbl_8014cc58;
  addi r26, r26, 1;
lbl_8014cc58:
  lis r30, 0x8034;
  li r29, 0;
  addi r3, r30, -27840;
  li r31, 3;
  lhz r0, 2(r3);
  addi r28, r3, 8;
  lis r24, 8;
  lis r25, 0x8028;
  divw r3, r0, r4;
  lis r23, 0x51ec;
  addi r0, r3, 1;
  clrlwi r27, r0, 0x10;
lbl_8014cc88:
  lbz r0, 0(r28);
  cmpwi r0, 0;
  beq lbl_8014cd2c;
  cmpwi r26, 0;
  beq lbl_8014cca8;
  lbz r0, 0x5a(r28);
  cmplwi r0, 1;
  bne lbl_8014ccb4;
lbl_8014cca8:
  sth r27, 0x34(r28);
  sth r27, 0x36(r28);
  b lbl_8014ccbc;
lbl_8014ccb4:
  sth r31, 0x34(r28);
  sth r31, 0x36(r28);
lbl_8014ccbc:
  lhz r0, 0x34(r28);
  addi r3, r23, -31457;
  mulli r0, r0, 0x78;
  mulhw r0, r3, r0;
  srawi r0, r0, 5;
  srwi r3, r0, 0x1f;
  add r0, r0, r3;
  clrlwi r4, r0, 0x10;
  sth r0, 0x3a(r28);
  subfc r0, r4, r31;
  subfe r3, r0, r0;
  addi r0, r4, -3;
  and r3, r0, r3;
  sth r3, 0x3c(r28);
  addi r0, r4, 2;
  sth r0, 0x3e(r28);
  lbz r0, -0x6cc0(r30);
  cmplwi r0, 5;
  blt lbl_8014cd2c;
  lbz r6, 0x5a(r28);
  addi r3, r24, 4;
  lhz r7, 0x36(r28);
  addi r4, r25, 0x6618;
  lhz r8, 0x3a(r28);
  clrlwi r5, r29, 0x10;
  lhz r9, 0x3c(r28);
  lhz r10, 0x3e(r28);
  bl LogMsg_6;
lbl_8014cd2c:
  addi r29, r29, 1;
  addi r28, r28, 0x5c;
  cmplwi r29, 4;
  blt lbl_8014cc88;
lbl_8014cd3c:
  addi r11, r1, 0x30;
  bl _restgpr_23;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: l2c_link_process_num_completed_pkts
// PAL: 0x8014cd54..0x8014ce38
MARK_BINARY_BLOB(l2c_link_process_num_completed_pkts, 0x8014cd54, 0x8014ce38);
asm UNKNOWN_FUNCTION(l2c_link_process_num_completed_pkts) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_26;
  lis r28, 0x8034;
  lbz r31, 0(r3);
  addi r29, r3, 1;
  li r30, 0;
  addi r28, r28, -27840;
  li r27, 0;
  b lbl_8014ce14;
lbl_8014cd84:
  lbz r3, 1(r29);
  lbz r0, 3(r29);
  slwi r4, r3, 8;
  lbz r5, 0(r29);
  lbz r3, 2(r29);
  slwi r0, r0, 8;
  add r4, r5, r4;
  addi r29, r29, 4;
  add r0, r3, r0;
  clrlwi r3, r4, 0x10;
  clrlwi r26, r0, 0x10;
  bl l2cu_find_lcb_by_handle;
  cmpwi r3, 0;
  beq lbl_8014ce10;
  lhz r0, 0x36(r3);
  add r0, r0, r26;
  sth r0, 0x36(r3);
  clrlwi r0, r0, 0x10;
  lhz r4, 0x34(r3);
  cmplw r0, r4;
  ble lbl_8014cddc;
  sth r4, 0x36(r3);
lbl_8014cddc:
  lhz r0, 0x38(r3);
  cmplw r0, r26;
  ble lbl_8014cdf4;
  subf r0, r26, r0;
  sth r0, 0x38(r3);
  b lbl_8014cdf8;
lbl_8014cdf4:
  sth r27, 0x38(r3);
lbl_8014cdf8:
  lhz r0, 4(r28);
  li r4, 0;
  li r5, 0;
  add r0, r0, r26;
  sth r0, 4(r28);
  bl l2c_link_check_send_pkts;
lbl_8014ce10:
  addi r30, r30, 1;
lbl_8014ce14:
  clrlwi r0, r30, 0x18;
  cmplw r0, r31;
  blt lbl_8014cd84;
  addi r11, r1, 0x20;
  bl _restgpr_26;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: l2c_link_processs_num_bufs
// PAL: 0x8014ce38..0x8014ce4c
MARK_BINARY_BLOB(l2c_link_processs_num_bufs, 0x8014ce38, 0x8014ce4c);
asm UNKNOWN_FUNCTION(l2c_link_processs_num_bufs) {
  // clang-format off
  nofralloc;
  lis r4, 0x8034;
  addi r4, r4, -27840;
  sth r3, 2(r4);
  sth r3, 4(r4);
  blr;
  // clang-format on
}

// Symbol: l2cap_link_chk_pkt_start
// PAL: 0x8014ce4c..0x8014d01c
MARK_BINARY_BLOB(l2cap_link_chk_pkt_start, 0x8014ce4c, 0x8014d01c);
asm UNKNOWN_FUNCTION(l2cap_link_chk_pkt_start) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_24;
  lhz r0, 4(r3);
  li r6, 0;
  sth r6, 6(r3);
  lis r24, 0x8034;
  add r7, r3, r0;
  mr r28, r3;
  lbz r3, 9(r7);
  addi r25, r24, -27840;
  lbz r0, 0xb(r7);
  slwi r4, r3, 8;
  lbz r5, 8(r7);
  lbz r3, 0xa(r7);
  slwi r0, r0, 8;
  add r4, r5, r4;
  add r0, r3, r0;
  stw r6, 0x7bc(r25);
  clrlwi r31, r0, 0x10;
  rlwinm r27, r4, 0x14, 0x1e, 0x1f;
  clrlwi r3, r4, 0x14;
  bl l2cu_find_lcb_by_handle;
  cmpwi r3, 0;
  mr r26, r3;
  bne lbl_8014cec4;
  mr r3, r28;
  b lbl_8014d004;
lbl_8014cec4:
  cmplwi r27, 2;
  bne lbl_8014cf18;
  lwz r0, 0x50(r3);
  cmpwi r0, 0;
  beq lbl_8014cf00;
  lbz r0, -0x6cc0(r24);
  cmplwi r0, 2;
  blt lbl_8014cef8;
  lis r3, 8;
  lis r4, 0x8028;
  addi r3, r3, 1;
  addi r4, r4, 0x6660;
  bl LogMsg_0;
lbl_8014cef8:
  lwz r3, 0x50(r26);
  bl GKI_freebuf;
lbl_8014cf00:
  lis r3, 0x8034;
  stw r28, 0x50(r26);
  addi r3, r3, -27840;
  mr r30, r28;
  stw r26, 0x7bc(r3);
  b lbl_8014cff0;
lbl_8014cf18:
  lwz r30, 0x50(r3);
  cmpwi r30, 0;
  beq lbl_8014cfec;
  lhz r0, 4(r30);
  add r27, r30, r0;
  lbz r0, 0xb(r27);
  lbz r4, 0xa(r27);
  slwi r0, r0, 8;
  add r0, r4, r0;
  clrlwi r29, r0, 0x10;
  add r0, r29, r31;
  cmpwi r0, 0x69f;
  bgt lbl_8014cfb4;
  stw r3, 0x7bc(r25);
  lhz r3, 2(r28);
  cmplwi r3, 4;
  ble lbl_8014cf98;
  lhz r4, 4(r30);
  addi r5, r3, -4;
  lhz r0, 4(r28);
  add r6, r30, r4;
  lhz r3, 2(r30);
  add r4, r28, r0;
  add r3, r6, r3;
  addi r3, r3, 8;
  addi r4, r4, 0xc;
  bl memcpy;
  lhz r3, 2(r30);
  lhz r0, 2(r28);
  add r3, r0, r3;
  addi r0, r3, -4;
  sth r0, 2(r30);
lbl_8014cf98:
  mr r3, r28;
  bl GKI_freebuf;
  add r29, r29, r31;
  stb r29, 0xa(r27);
  rlwinm r0, r29, 0x18, 0x18, 0x1f;
  stb r0, 0xb(r27);
  b lbl_8014cff0;
lbl_8014cfb4:
  lbz r0, -0x6cc0(r24);
  cmplwi r0, 2;
  blt lbl_8014cfd4;
  lis r3, 8;
  lis r4, 0x8028;
  addi r3, r3, 1;
  addi r4, r4, 0x6680;
  bl LogMsg_0;
lbl_8014cfd4:
  lwz r3, 0x50(r26);
  bl GKI_freebuf;
  li r0, 0;
  li r30, 0;
  stw r0, 0x50(r26);
  b lbl_8014cff0;
lbl_8014cfec:
  li r30, 0;
lbl_8014cff0:
  cmpwi r30, 0;
  bne lbl_8014d000;
  mr r3, r28;
  bl GKI_freebuf;
lbl_8014d000:
  mr r3, r30;
lbl_8014d004:
  addi r11, r1, 0x30;
  bl _restgpr_24;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: l2cap_link_chk_pkt_end
// PAL: 0x8014d01c..0x8014d088
MARK_BINARY_BLOB(l2cap_link_chk_pkt_end, 0x8014d01c, 0x8014d088);
asm UNKNOWN_FUNCTION(l2cap_link_chk_pkt_end) {
  // clang-format off
  nofralloc;
  lis r3, 0x8034;
  addi r3, r3, -27840;
  lwz r6, 0x7bc(r3);
  cmpwi r6, 0;
  beq lbl_8014d03c;
  lwz r4, 0x50(r6);
  cmpwi r4, 0;
  bne lbl_8014d044;
lbl_8014d03c:
  li r3, 1;
  blr;
lbl_8014d044:
  lhz r0, 4(r4);
  lhz r3, 2(r4);
  add r5, r4, r0;
  lbz r4, 0xd(r5);
  addi r0, r3, -8;
  lbz r5, 0xc(r5);
  slwi r3, r4, 8;
  add r3, r5, r3;
  clrlwi r3, r3, 0x10;
  cmpw r3, r0;
  ble lbl_8014d078;
  li r3, 0;
  blr;
lbl_8014d078:
  li r0, 0;
  li r3, 1;
  stw r0, 0x50(r6);
  blr;
  // clang-format on
}

// Symbol: l2c_link_role_changed
// PAL: 0x8014d088..0x8014d108
MARK_BINARY_BLOB(l2c_link_role_changed, 0x8014d088, 0x8014d108);
asm UNKNOWN_FUNCTION(l2c_link_role_changed) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  stw r30, 8(r1);
  mr r30, r4;
  bl l2cu_find_lcb_by_bd_addr;
  cmpwi r3, 0;
  beq lbl_8014d0b0;
  stb r30, 0x30(r3);
lbl_8014d0b0:
  lis r3, 0x8034;
  li r30, 0;
  addi r3, r3, -27840;
  addi r31, r3, 8;
lbl_8014d0c0:
  lbz r0, 0(r31);
  cmpwi r0, 0;
  beq lbl_8014d0e0;
  lwz r0, 4(r31);
  cmpwi r0, 2;
  bne lbl_8014d0e0;
  mr r3, r31;
  bl l2cu_create_conn_after_switch;
lbl_8014d0e0:
  addi r30, r30, 1;
  addi r31, r31, 0x5c;
  cmpwi r30, 4;
  blt lbl_8014d0c0;
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: l2c_link_role_change_failed
// PAL: 0x8014d108..0x8014d174
MARK_BINARY_BLOB(l2c_link_role_change_failed, 0x8014d108, 0x8014d174);
asm UNKNOWN_FUNCTION(l2c_link_role_change_failed) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r3, 0x8034;
  stw r0, 0x14(r1);
  addi r3, r3, -27840;
  stw r31, 0xc(r1);
  addi r31, r3, 8;
  stw r30, 8(r1);
  li r30, 0;
lbl_8014d12c:
  lbz r0, 0(r31);
  cmpwi r0, 0;
  beq lbl_8014d14c;
  lwz r0, 4(r31);
  cmpwi r0, 2;
  bne lbl_8014d14c;
  mr r3, r31;
  bl l2cu_create_conn_after_switch;
lbl_8014d14c:
  addi r30, r30, 1;
  addi r31, r31, 0x5c;
  cmpwi r30, 4;
  blt lbl_8014d12c;
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: l2c_link_segments_xmitted
// PAL: 0x8014d174..0x8014d250
MARK_BINARY_BLOB(l2c_link_segments_xmitted, 0x8014d174, 0x8014d250);
asm UNKNOWN_FUNCTION(l2c_link_segments_xmitted) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  mr r29, r3;
  lhz r0, 4(r3);
  add r3, r3, r0;
  lbz r0, 9(r3);
  lbz r3, 8(r3);
  slwi r0, r0, 8;
  add r0, r3, r0;
  clrlwi r31, r0, 0x14;
  mr r3, r31;
  bl l2cu_find_lcb_by_handle;
  cmpwi r3, 0;
  mr r30, r3;
  bne lbl_8014d1f4;
  lis r3, 0x8034;
  lbz r0, -0x6cc0(r3);
  cmplwi r0, 2;
  blt lbl_8014d1e8;
  lis r3, 8;
  lis r4, 0x8028;
  mr r5, r31;
  addi r3, r3, 1;
  addi r4, r4, 0x66a0;
  bl LogMsg_1;
lbl_8014d1e8:
  mr r3, r29;
  bl GKI_freebuf;
  b lbl_8014d234;
lbl_8014d1f4:
  lwz r0, 4(r3);
  cmpwi r0, 4;
  bne lbl_8014d22c;
  li r31, 0;
  mr r4, r29;
  sth r31, 6(r29);
  addi r3, r3, 0x44;
  bl GKI_enqueue_head;
  stb r31, 0x40(r30);
  mr r3, r30;
  li r4, 0;
  li r5, 0;
  bl l2c_link_check_send_pkts;
  b lbl_8014d234;
lbl_8014d22c:
  mr r3, r29;
  bl GKI_freebuf;
lbl_8014d234:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: l2c_pin_code_request
// PAL: 0x8014d250..0x8014d294
MARK_BINARY_BLOB(l2c_pin_code_request, 0x8014d250, 0x8014d294);
asm UNKNOWN_FUNCTION(l2c_pin_code_request) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  bl l2cu_find_lcb_by_bd_addr;
  cmpwi r3, 0;
  beq lbl_8014d284;
  lwz r0, 8(r3);
  cmpwi r0, 0;
  bne lbl_8014d284;
  li r4, 2;
  li r5, 0x78;
  addi r3, r3, 0x10;
  bl btu_start_timer;
lbl_8014d284:
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

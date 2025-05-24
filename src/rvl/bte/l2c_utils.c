#include "l2c_utils.h"

#include <string.h>

#include "gki_buffer.h"
#include "bte_logmsg.h"
#include "bte_task1.h"
#include "btm_acl.h"
#include "btm_devctl.h"
#include "btm_inq.h"
#include "btm_sec.h"
#include "btm_sco.h"
#include "hcicmds.h"
#include "l2c_link.h"

// Symbol: l2cu_allocate_lcb
// PAL: 0x8014e2c4..0x8014e398
MARK_BINARY_BLOB(l2cu_allocate_lcb, 0x8014e2c4, 0x8014e398);
asm UNKNOWN_FUNCTION(l2cu_allocate_lcb) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r4, 0x8034;
  stw r0, 0x14(r1);
  li r0, 4;
  addi r4, r4, -27840;
  stw r31, 0xc(r1);
  addi r31, r4, 8;
  stw r30, 8(r1);
  mr r30, r3;
  mtctr r0;
lbl_8014e2f0:
  lbz r0, 0(r31);
  cmpwi r0, 0;
  bne lbl_8014e374;
  mr r3, r31;
  li r4, 0;
  li r5, 0x5c;
  bl memset;
  li r0, 1;
  mr r4, r30;
  stb r0, 0(r31);
  addi r3, r31, 0x2a;
  li r5, 6;
  bl memcpy;
  li r5, 0;
  lis r3, 1;
  stw r5, 4(r31);
  addi r0, r3, -1;
  lis r4, 0x8034;
  sth r0, 0x28(r31);
  addi r4, r4, -27840;
  stw r5, 0x50(r31);
  sth r0, 0x32(r31);
  stw r31, 0x20(r31);
  sth r5, 0x38(r31);
  lhz r0, 0x7ba(r4);
  sth r0, 0x58(r31);
  stb r5, 0x31(r31);
  lhz r3, 0x7b8(r4);
  addi r0, r3, 1;
  sth r0, 0x7b8(r4);
  bl l2c_link_adjust_allocation;
  mr r3, r31;
  b lbl_8014e380;
lbl_8014e374:
  addi r31, r31, 0x5c;
  bdnz lbl_8014e2f0;
  li r3, 0;
lbl_8014e380:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: l2cu_release_lcb
// PAL: 0x8014e398..0x8014e498
MARK_BINARY_BLOB(l2cu_release_lcb, 0x8014e398, 0x8014e498);
asm UNKNOWN_FUNCTION(l2cu_release_lcb) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  li r31, 0;
  stw r30, 8(r1);
  mr r30, r3;
  stb r31, 0(r3);
  addi r3, r3, 0x10;
  bl btu_stop_timer;
  lwz r3, 0x50(r30);
  cmpwi r3, 0;
  beq lbl_8014e3d4;
  bl GKI_freebuf;
  stw r31, 0x50(r30);
lbl_8014e3d4:
  addi r3, r30, 0x2a;
  bl btm_remove_sco_links;
  lwz r3, 8(r30);
  b lbl_8014e3ec;
lbl_8014e3e4:
  bl l2cu_release_ccb;
  lwz r3, 8(r30);
lbl_8014e3ec:
  cmpwi r3, 0;
  bne lbl_8014e3e4;
  lwz r3, 4(r30);
  addi r0, r3, -4;
  cmplwi r0, 1;
  bgt lbl_8014e41c;
  addi r3, r30, 0x2a;
  bl btm_acl_removed;
  b lbl_8014e41c;
lbl_8014e410:
  addi r3, r30, 0x44;
  bl GKI_dequeue;
  bl GKI_freebuf;
lbl_8014e41c:
  lwz r0, 0x44(r30);
  cmpwi r0, 0;
  bne lbl_8014e410;
  lis r4, 0x8034;
  addi r4, r4, -27840;
  lhz r3, 0x7b8(r4);
  cmplwi r3, 1;
  blt lbl_8014e444;
  addi r0, r3, -1;
  sth r0, 0x7b8(r4);
lbl_8014e444:
  lis r4, 0x8034;
  lhz r0, 0x38(r30);
  addi r4, r4, -27840;
  lhz r3, 4(r4);
  add r0, r3, r0;
  sth r0, 4(r4);
  bl l2c_link_adjust_allocation;
  lwz r12, 0x54(r30);
  cmpwi r12, 0;
  beq lbl_8014e480;
  li r0, 0;
  li r3, 1;
  stw r0, 0x54(r30);
  mtctr r12;
  bctrl;
lbl_8014e480:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: l2cu_find_lcb_by_bd_addr
// PAL: 0x8014e498..0x8014e520
MARK_BINARY_BLOB(l2cu_find_lcb_by_bd_addr, 0x8014e498, 0x8014e520);
asm UNKNOWN_FUNCTION(l2cu_find_lcb_by_bd_addr) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  lis r4, 0x8034;
  stw r0, 0x24(r1);
  addi r4, r4, -27840;
  stw r31, 0x1c(r1);
  li r31, 0;
  stw r30, 0x18(r1);
  addi r30, r4, 8;
  stw r29, 0x14(r1);
  mr r29, r3;
lbl_8014e4c4:
  lbz r0, 0(r30);
  cmpwi r0, 0;
  beq lbl_8014e4f0;
  mr r4, r29;
  addi r3, r30, 0x2a;
  li r5, 6;
  bl memcmp;
  cmpwi r3, 0;
  bne lbl_8014e4f0;
  mr r3, r30;
  b lbl_8014e504;
lbl_8014e4f0:
  addi r31, r31, 1;
  addi r30, r30, 0x5c;
  cmpwi r31, 4;
  blt lbl_8014e4c4;
  li r3, 0;
lbl_8014e504:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: l2cu_find_lcb_by_handle
// PAL: 0x8014e520..0x8014e5b0
MARK_BINARY_BLOB(l2cu_find_lcb_by_handle, 0x8014e520, 0x8014e5b0);
asm UNKNOWN_FUNCTION(l2cu_find_lcb_by_handle) {
  // clang-format off
  nofralloc;
  lis r4, 0x8034;
  addi r4, r4, -27840;
  lbzu r0, 8(r4);
  cmpwi r0, 0;
  beq lbl_8014e548;
  lhz r0, 0x28(r4);
  cmplw r0, r3;
  bne lbl_8014e548;
  mr r3, r4;
  blr;
lbl_8014e548:
  lbzu r0, 0x5c(r4);
  cmpwi r0, 0;
  beq lbl_8014e568;
  lhz r0, 0x28(r4);
  cmplw r0, r3;
  bne lbl_8014e568;
  mr r3, r4;
  blr;
lbl_8014e568:
  lbzu r0, 0x5c(r4);
  cmpwi r0, 0;
  beq lbl_8014e588;
  lhz r0, 0x28(r4);
  cmplw r0, r3;
  bne lbl_8014e588;
  mr r3, r4;
  blr;
lbl_8014e588:
  lbzu r0, 0x5c(r4);
  cmpwi r0, 0;
  beq lbl_8014e5a8;
  lhz r0, 0x28(r4);
  cmplw r0, r3;
  bne lbl_8014e5a8;
  mr r3, r4;
  blr;
lbl_8014e5a8:
  li r3, 0;
  blr;
  // clang-format on
}

// Symbol: l2cu_get_conn_role
// PAL: 0x8014e5b0..0x8014e5c0
MARK_BINARY_BLOB(l2cu_get_conn_role, 0x8014e5b0, 0x8014e5c0);
asm UNKNOWN_FUNCTION(l2cu_get_conn_role) {
  // clang-format off
  nofralloc;
  lis r3, 0x8034;
  addi r3, r3, -27840;
  lbz r3, 1(r3);
  blr;
  // clang-format on
}

// Symbol: l2cu_build_header
// PAL: 0x8014e5c0..0x8014e684
MARK_BINARY_BLOB(l2cu_build_header, 0x8014e5c0, 0x8014e684);
asm UNKNOWN_FUNCTION(l2cu_build_header) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r6;
  stw r30, 0x18(r1);
  mr r30, r5;
  stw r29, 0x14(r1);
  mr r29, r4;
  stw r28, 0x10(r1);
  mr r28, r3;
  li r3, 2;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  bne lbl_8014e604;
  li r3, 0;
  b lbl_8014e664;
lbl_8014e604:
  li r8, 0;
  ori r5, r28, 0x2000;
  sth r8, 4(r3);
  addi r0, r29, 0xc;
  srawi r7, r5, 8;
  addi r9, r29, 8;
  sth r0, 2(r3);
  srawi r6, r9, 8;
  addi r10, r29, 4;
  li r4, 1;
  stb r5, 8(r3);
  srawi r5, r10, 8;
  rlwinm r0, r29, 0x18, 0x18, 0x1f;
  stb r7, 9(r3);
  stb r9, 0xa(r3);
  stb r6, 0xb(r3);
  stb r10, 0xc(r3);
  stb r5, 0xd(r3);
  stb r4, 0xe(r3);
  stb r8, 0xf(r3);
  stb r30, 0x10(r3);
  stb r31, 0x11(r3);
  stb r29, 0x12(r3);
  stb r0, 0x13(r3);
lbl_8014e664:
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

// Symbol: l2cu_send_peer_cmd_reject
// PAL: 0x8014e684..0x8014e780
MARK_BINARY_BLOB(l2cu_send_peer_cmd_reject, 0x8014e684, 0x8014e780);
asm UNKNOWN_FUNCTION(l2cu_send_peer_cmd_reject) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_27;
  cmplwi r4, 1;
  mr r27, r3;
  mr r28, r4;
  mr r29, r6;
  mr r30, r7;
  bne lbl_8014e6b8;
  li r31, 2;
  b lbl_8014e6cc;
lbl_8014e6b8:
  addi r6, r4, -2;
  subfic r0, r4, 2;
  nor r0, r6, r0;
  srawi r0, r0, 0x1f;
  rlwinm r31, r0, 0, 0x1d, 0x1d;
lbl_8014e6cc:
  addi r0, r31, 2;
  lhz r3, 0x28(r3);
  mr r6, r5;
  li r5, 1;
  clrlwi r4, r0, 0x10;
  bl l2cu_build_header;
  cmpwi r3, 0;
  mr r5, r3;
  bne lbl_8014e718;
  lis r3, 0x8034;
  lbz r0, -0x6cc0(r3);
  cmplwi r0, 2;
  blt lbl_8014e768;
  lis r3, 8;
  lis r4, 0x8028;
  addi r3, r3, 1;
  addi r4, r4, 0x69d8;
  bl LogMsg_0;
  b lbl_8014e768;
lbl_8014e718:
  clrlwi r0, r31, 0x10;
  stb r28, 0x14(r3);
  rlwinm r4, r28, 0x18, 0x18, 0x1f;
  addi r6, r3, 0x16;
  cmplwi r0, 2;
  stb r4, 0x15(r3);
  blt lbl_8014e744;
  stb r29, 0(r6);
  rlwinm r0, r29, 0x18, 0x18, 0x1f;
  stb r0, 1(r6);
  addi r6, r6, 2;
lbl_8014e744:
  clrlwi r0, r31, 0x10;
  cmplwi r0, 4;
  blt lbl_8014e75c;
  stb r30, 0(r6);
  rlwinm r0, r30, 0x18, 0x18, 0x1f;
  stb r0, 1(r6);
lbl_8014e75c:
  mr r3, r27;
  li r4, 0;
  bl l2c_link_check_send_pkts;
lbl_8014e768:
  addi r11, r1, 0x20;
  bl _restgpr_27;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: l2cu_send_peer_connect_req
// PAL: 0x8014e780..0x8014e844
MARK_BINARY_BLOB(l2cu_send_peer_connect_req, 0x8014e780, 0x8014e844);
asm UNKNOWN_FUNCTION(l2cu_send_peer_connect_req) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  li r4, 4;
  li r5, 2;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  lwz r7, 0x10(r3);
  lbz r6, 0x31(r7);
  addi r0, r6, 1;
  stb r0, 0x31(r7);
  clrlwi r6, r0, 0x18;
  stb r0, 0x35(r3);
  lwz r3, 0x10(r3);
  lhz r3, 0x28(r3);
  bl l2cu_build_header;
  cmpwi r3, 0;
  bne lbl_8014e7f0;
  lis r3, 0x8034;
  lbz r0, -0x6cc0(r3);
  cmplwi r0, 2;
  blt lbl_8014e830;
  lis r3, 8;
  lis r4, 0x8028;
  addi r3, r3, 1;
  addi r4, r4, 0x69f4;
  bl LogMsg_0;
  b lbl_8014e830;
lbl_8014e7f0:
  lwz r6, 0x30(r31);
  mr r5, r3;
  li r4, 0;
  lhz r0, 2(r6);
  stb r0, 0x14(r3);
  lwz r6, 0x30(r31);
  lhz r0, 2(r6);
  srawi r0, r0, 8;
  stb r0, 0x15(r3);
  lhz r0, 0x14(r31);
  stb r0, 0x16(r3);
  lhz r0, 0x14(r31);
  srawi r0, r0, 8;
  stb r0, 0x17(r3);
  lwz r3, 0x10(r31);
  bl l2c_link_check_send_pkts;
lbl_8014e830:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: l2cu_send_peer_connect_rsp
// PAL: 0x8014e844..0x8014e91c
MARK_BINARY_BLOB(l2cu_send_peer_connect_rsp, 0x8014e844, 0x8014e91c);
asm UNKNOWN_FUNCTION(l2cu_send_peer_connect_rsp) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r5;
  li r5, 3;
  stw r30, 0x18(r1);
  mr r30, r4;
  li r4, 8;
  stw r29, 0x14(r1);
  mr r29, r3;
  lwz r6, 0x10(r3);
  lhz r3, 0x28(r6);
  lbz r6, 0x36(r29);
  bl l2cu_build_header;
  cmpwi r3, 0;
  bne lbl_8014e8b0;
  lis r3, 0x8034;
  lbz r0, -0x6cc0(r3);
  cmplwi r0, 2;
  blt lbl_8014e900;
  lis r3, 8;
  lis r4, 0x8028;
  addi r3, r3, 1;
  addi r4, r4, 0x69f4;
  bl LogMsg_0;
  b lbl_8014e900;
lbl_8014e8b0:
  lhz r6, 0x14(r29);
  rlwinm r0, r31, 0x18, 0x18, 0x1f;
  mr r5, r3;
  li r4, 0;
  stb r6, 0x14(r3);
  lhz r6, 0x14(r29);
  srawi r6, r6, 8;
  stb r6, 0x15(r3);
  lhz r6, 0x16(r29);
  stb r6, 0x16(r3);
  lhz r6, 0x16(r29);
  srawi r6, r6, 8;
  stb r6, 0x17(r3);
  srawi r6, r30, 8;
  stb r30, 0x18(r3);
  stb r6, 0x19(r3);
  stb r31, 0x1a(r3);
  stb r0, 0x1b(r3);
  lwz r3, 0x10(r29);
  bl l2c_link_check_send_pkts;
lbl_8014e900:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: l2cu_reject_connection
// PAL: 0x8014e91c..0x8014e9dc
MARK_BINARY_BLOB(l2cu_reject_connection, 0x8014e91c, 0x8014e9dc);
asm UNKNOWN_FUNCTION(l2cu_reject_connection) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r6;
  mr r6, r5;
  li r5, 3;
  stw r30, 0x18(r1);
  mr r30, r4;
  li r4, 8;
  stw r29, 0x14(r1);
  mr r29, r3;
  lhz r3, 0x28(r3);
  bl l2cu_build_header;
  cmpwi r3, 0;
  bne lbl_8014e984;
  lis r3, 0x8034;
  lbz r0, -0x6cc0(r3);
  cmplwi r0, 2;
  blt lbl_8014e9c0;
  lis r3, 8;
  lis r4, 0x8028;
  addi r3, r3, 1;
  addi r4, r4, 0x69f4;
  bl LogMsg_0;
  b lbl_8014e9c0;
lbl_8014e984:
  li r7, 0;
  srawi r6, r30, 8;
  stb r7, 0x14(r3);
  rlwinm r0, r31, 0x18, 0x18, 0x1f;
  mr r5, r3;
  li r4, 0;
  stb r7, 0x15(r3);
  stb r30, 0x16(r3);
  stb r6, 0x17(r3);
  stb r31, 0x18(r3);
  stb r0, 0x19(r3);
  stb r7, 0x1a(r3);
  stb r7, 0x1b(r3);
  mr r3, r29;
  bl l2c_link_check_send_pkts;
lbl_8014e9c0:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: l2cu_send_peer_config_req
// PAL: 0x8014e9dc..0x8014ecd4
MARK_BINARY_BLOB(l2cu_send_peer_config_req, 0x8014e9dc, 0x8014ecd4);
asm UNKNOWN_FUNCTION(l2cu_send_peer_config_req) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  li r7, 0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  lwz r6, 0x10(r3);
  lbz r5, 0x31(r6);
  addi r0, r5, 1;
  stb r0, 0x31(r6);
  stb r0, 0x35(r3);
  lbz r0, 2(r4);
  cmpwi r0, 0;
  beq lbl_8014ea20;
  li r7, 4;
lbl_8014ea20:
  lbz r0, 0x20(r4);
  cmpwi r0, 0;
  beq lbl_8014ea34;
  addi r0, r7, 4;
  clrlwi r7, r0, 0x10;
lbl_8014ea34:
  lbz r0, 6(r4);
  cmpwi r0, 0;
  beq lbl_8014ea48;
  addi r0, r7, 0x18;
  clrlwi r7, r0, 0x10;
lbl_8014ea48:
  lbz r0, 0x24(r4);
  cmpwi r0, 0;
  beq lbl_8014ea5c;
  addi r0, r7, 0xb;
  clrlwi r7, r0, 0x10;
lbl_8014ea5c:
  lwz r3, 0x10(r3);
  addi r0, r7, 4;
  lbz r6, 0x35(r30);
  clrlwi r4, r0, 0x10;
  lhz r3, 0x28(r3);
  li r5, 4;
  bl l2cu_build_header;
  cmpwi r3, 0;
  mr r5, r3;
  bne lbl_8014eaac;
  lis r3, 0x8034;
  lbz r0, -0x6cc0(r3);
  cmplwi r0, 2;
  blt lbl_8014ecbc;
  lis r3, 8;
  lis r4, 0x8028;
  addi r3, r3, 1;
  addi r4, r4, 0x69f4;
  bl LogMsg_0;
  b lbl_8014ecbc;
lbl_8014eaac:
  lhz r6, 0x16(r30);
  li r0, 0;
  addi r4, r3, 0x18;
  stb r6, 0x14(r3);
  lhz r6, 0x16(r30);
  srawi r6, r6, 8;
  stb r6, 0x15(r3);
  stb r0, 0x16(r3);
  stb r0, 0x17(r3);
  lbz r0, 2(r31);
  cmpwi r0, 0;
  beq lbl_8014eb04;
  li r3, 1;
  li r0, 2;
  stb r3, 0(r4);
  stb r0, 1(r4);
  lhz r0, 4(r31);
  stb r0, 2(r4);
  lhz r0, 4(r31);
  srawi r0, r0, 8;
  stb r0, 3(r4);
  addi r4, r4, 4;
lbl_8014eb04:
  lbz r0, 0x20(r31);
  cmpwi r0, 0;
  beq lbl_8014eb34;
  li r0, 2;
  stb r0, 0(r4);
  stb r0, 1(r4);
  lhz r0, 0x22(r31);
  stb r0, 2(r4);
  lhz r0, 0x22(r31);
  srawi r0, r0, 8;
  stb r0, 3(r4);
  addi r4, r4, 4;
lbl_8014eb34:
  lbz r0, 6(r31);
  cmpwi r0, 0;
  beq lbl_8014ec40;
  li r3, 3;
  li r0, 0x16;
  stb r3, 0(r4);
  stb r0, 1(r4);
  lbz r0, 8(r31);
  stb r0, 2(r4);
  lbz r0, 9(r31);
  stb r0, 3(r4);
  lwz r0, 0xc(r31);
  stb r0, 4(r4);
  lwz r0, 0xc(r31);
  rlwinm r0, r0, 0x18, 0x18, 0x1f;
  stb r0, 5(r4);
  lwz r0, 0xc(r31);
  rlwinm r0, r0, 0x10, 0x18, 0x1f;
  stb r0, 6(r4);
  lwz r0, 0xc(r31);
  srwi r0, r0, 0x18;
  stb r0, 7(r4);
  lwz r0, 0x10(r31);
  stb r0, 8(r4);
  lwz r0, 0x10(r31);
  rlwinm r0, r0, 0x18, 0x18, 0x1f;
  stb r0, 9(r4);
  lwz r0, 0x10(r31);
  rlwinm r0, r0, 0x10, 0x18, 0x1f;
  stb r0, 0xa(r4);
  lwz r0, 0x10(r31);
  srwi r0, r0, 0x18;
  stb r0, 0xb(r4);
  lwz r0, 0x14(r31);
  stb r0, 0xc(r4);
  lwz r0, 0x14(r31);
  rlwinm r0, r0, 0x18, 0x18, 0x1f;
  stb r0, 0xd(r4);
  lwz r0, 0x14(r31);
  rlwinm r0, r0, 0x10, 0x18, 0x1f;
  stb r0, 0xe(r4);
  lwz r0, 0x14(r31);
  srwi r0, r0, 0x18;
  stb r0, 0xf(r4);
  lwz r0, 0x18(r31);
  stb r0, 0x10(r4);
  lwz r0, 0x18(r31);
  rlwinm r0, r0, 0x18, 0x18, 0x1f;
  stb r0, 0x11(r4);
  lwz r0, 0x18(r31);
  rlwinm r0, r0, 0x10, 0x18, 0x1f;
  stb r0, 0x12(r4);
  lwz r0, 0x18(r31);
  srwi r0, r0, 0x18;
  stb r0, 0x13(r4);
  lwz r0, 0x1c(r31);
  stb r0, 0x14(r4);
  lwz r0, 0x1c(r31);
  rlwinm r0, r0, 0x18, 0x18, 0x1f;
  stb r0, 0x15(r4);
  lwz r0, 0x1c(r31);
  rlwinm r0, r0, 0x10, 0x18, 0x1f;
  stb r0, 0x16(r4);
  lwz r0, 0x1c(r31);
  srwi r0, r0, 0x18;
  stb r0, 0x17(r4);
  addi r4, r4, 0x18;
lbl_8014ec40:
  lbz r0, 0x24(r31);
  cmpwi r0, 0;
  beq lbl_8014ecb0;
  li r3, 4;
  li r0, 9;
  stb r3, 0(r4);
  stb r0, 1(r4);
  lbz r0, 0x26(r31);
  stb r0, 2(r4);
  lbz r0, 0x27(r31);
  stb r0, 3(r4);
  lbz r0, 0x28(r31);
  stb r0, 4(r4);
  lhz r0, 0x2a(r31);
  stb r0, 5(r4);
  lhz r0, 0x2a(r31);
  srawi r0, r0, 8;
  stb r0, 6(r4);
  lhz r0, 0x2c(r31);
  stb r0, 7(r4);
  lhz r0, 0x2c(r31);
  srawi r0, r0, 8;
  stb r0, 8(r4);
  lhz r0, 0x2e(r31);
  stb r0, 9(r4);
  lhz r0, 0x2e(r31);
  srawi r0, r0, 8;
  stb r0, 0xa(r4);
lbl_8014ecb0:
  lwz r3, 0x10(r30);
  li r4, 0;
  bl l2c_link_check_send_pkts;
lbl_8014ecbc:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: l2cu_send_peer_config_rsp
// PAL: 0x8014ecd4..0x8014efcc
MARK_BINARY_BLOB(l2cu_send_peer_config_rsp, 0x8014ecd4, 0x8014efcc);
asm UNKNOWN_FUNCTION(l2cu_send_peer_config_rsp) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  li r5, 0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  lbz r0, 2(r4);
  cmpwi r0, 0;
  beq lbl_8014ed04;
  li r5, 4;
lbl_8014ed04:
  lbz r0, 0x20(r4);
  cmpwi r0, 0;
  beq lbl_8014ed18;
  addi r0, r5, 4;
  clrlwi r5, r0, 0x10;
lbl_8014ed18:
  lbz r0, 6(r4);
  cmpwi r0, 0;
  beq lbl_8014ed2c;
  addi r0, r5, 0x18;
  clrlwi r5, r0, 0x10;
lbl_8014ed2c:
  lbz r0, 0x24(r4);
  cmpwi r0, 0;
  beq lbl_8014ed40;
  addi r0, r5, 0xb;
  clrlwi r5, r0, 0x10;
lbl_8014ed40:
  lwz r3, 0x10(r3);
  addi r0, r5, 6;
  lbz r6, 0x36(r30);
  clrlwi r4, r0, 0x10;
  lhz r3, 0x28(r3);
  li r5, 5;
  bl l2cu_build_header;
  cmpwi r3, 0;
  mr r5, r3;
  bne lbl_8014ed90;
  lis r3, 0x8034;
  lbz r0, -0x6cc0(r3);
  cmplwi r0, 2;
  blt lbl_8014efb4;
  lis r3, 8;
  lis r4, 0x8028;
  addi r3, r3, 1;
  addi r4, r4, 0x69f4;
  bl LogMsg_0;
  b lbl_8014efb4;
lbl_8014ed90:
  lhz r6, 0x16(r30);
  li r0, 0;
  addi r4, r3, 0x1a;
  stb r6, 0x14(r3);
  lhz r6, 0x16(r30);
  srawi r6, r6, 8;
  stb r6, 0x15(r3);
  stb r0, 0x16(r3);
  stb r0, 0x17(r3);
  lhz r0, 0(r31);
  stb r0, 0x18(r3);
  lhz r0, 0(r31);
  srawi r0, r0, 8;
  stb r0, 0x19(r3);
  lbz r0, 2(r31);
  cmpwi r0, 0;
  beq lbl_8014edfc;
  li r3, 1;
  li r0, 2;
  stb r3, 0(r4);
  stb r0, 1(r4);
  lhz r0, 4(r31);
  stb r0, 2(r4);
  lhz r0, 4(r31);
  srawi r0, r0, 8;
  stb r0, 3(r4);
  addi r4, r4, 4;
lbl_8014edfc:
  lbz r0, 0x20(r31);
  cmpwi r0, 0;
  beq lbl_8014ee2c;
  li r0, 2;
  stb r0, 0(r4);
  stb r0, 1(r4);
  lhz r0, 0x22(r31);
  stb r0, 2(r4);
  lhz r0, 0x22(r31);
  srawi r0, r0, 8;
  stb r0, 3(r4);
  addi r4, r4, 4;
lbl_8014ee2c:
  lbz r0, 6(r31);
  cmpwi r0, 0;
  beq lbl_8014ef38;
  li r3, 3;
  li r0, 0x16;
  stb r3, 0(r4);
  stb r0, 1(r4);
  lbz r0, 8(r31);
  stb r0, 2(r4);
  lbz r0, 9(r31);
  stb r0, 3(r4);
  lwz r0, 0xc(r31);
  stb r0, 4(r4);
  lwz r0, 0xc(r31);
  rlwinm r0, r0, 0x18, 0x18, 0x1f;
  stb r0, 5(r4);
  lwz r0, 0xc(r31);
  rlwinm r0, r0, 0x10, 0x18, 0x1f;
  stb r0, 6(r4);
  lwz r0, 0xc(r31);
  srwi r0, r0, 0x18;
  stb r0, 7(r4);
  lwz r0, 0x10(r31);
  stb r0, 8(r4);
  lwz r0, 0x10(r31);
  rlwinm r0, r0, 0x18, 0x18, 0x1f;
  stb r0, 9(r4);
  lwz r0, 0x10(r31);
  rlwinm r0, r0, 0x10, 0x18, 0x1f;
  stb r0, 0xa(r4);
  lwz r0, 0x10(r31);
  srwi r0, r0, 0x18;
  stb r0, 0xb(r4);
  lwz r0, 0x14(r31);
  stb r0, 0xc(r4);
  lwz r0, 0x14(r31);
  rlwinm r0, r0, 0x18, 0x18, 0x1f;
  stb r0, 0xd(r4);
  lwz r0, 0x14(r31);
  rlwinm r0, r0, 0x10, 0x18, 0x1f;
  stb r0, 0xe(r4);
  lwz r0, 0x14(r31);
  srwi r0, r0, 0x18;
  stb r0, 0xf(r4);
  lwz r0, 0x18(r31);
  stb r0, 0x10(r4);
  lwz r0, 0x18(r31);
  rlwinm r0, r0, 0x18, 0x18, 0x1f;
  stb r0, 0x11(r4);
  lwz r0, 0x18(r31);
  rlwinm r0, r0, 0x10, 0x18, 0x1f;
  stb r0, 0x12(r4);
  lwz r0, 0x18(r31);
  srwi r0, r0, 0x18;
  stb r0, 0x13(r4);
  lwz r0, 0x1c(r31);
  stb r0, 0x14(r4);
  lwz r0, 0x1c(r31);
  rlwinm r0, r0, 0x18, 0x18, 0x1f;
  stb r0, 0x15(r4);
  lwz r0, 0x1c(r31);
  rlwinm r0, r0, 0x10, 0x18, 0x1f;
  stb r0, 0x16(r4);
  lwz r0, 0x1c(r31);
  srwi r0, r0, 0x18;
  stb r0, 0x17(r4);
  addi r4, r4, 0x18;
lbl_8014ef38:
  lbz r0, 0x24(r31);
  cmpwi r0, 0;
  beq lbl_8014efa8;
  li r3, 4;
  li r0, 9;
  stb r3, 0(r4);
  stb r0, 1(r4);
  lbz r0, 0x26(r31);
  stb r0, 2(r4);
  lbz r0, 0x27(r31);
  stb r0, 3(r4);
  lbz r0, 0x28(r31);
  stb r0, 4(r4);
  lhz r0, 0x2a(r31);
  stb r0, 5(r4);
  lhz r0, 0x2a(r31);
  srawi r0, r0, 8;
  stb r0, 6(r4);
  lhz r0, 0x2c(r31);
  stb r0, 7(r4);
  lhz r0, 0x2c(r31);
  srawi r0, r0, 8;
  stb r0, 8(r4);
  lhz r0, 0x2e(r31);
  stb r0, 9(r4);
  lhz r0, 0x2e(r31);
  srawi r0, r0, 8;
  stb r0, 0xa(r4);
lbl_8014efa8:
  lwz r3, 0x10(r30);
  li r4, 0;
  bl l2c_link_check_send_pkts;
lbl_8014efb4:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: l2cu_send_peer_config_rej
// PAL: 0x8014efcc..0x8014f180
MARK_BINARY_BLOB(l2cu_send_peer_config_rej, 0x8014efcc, 0x8014f180);
asm UNKNOWN_FUNCTION(l2cu_send_peer_config_rej) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_24;
  mr r25, r3;
  mr r26, r4;
  mr r27, r5;
  mr r24, r6;
  li r3, 2;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  mr r31, r3;
  bne lbl_8014f02c;
  lis r3, 0x8034;
  lbz r0, -0x6cc0(r3);
  cmplwi r0, 2;
  blt lbl_8014f168;
  lis r3, 8;
  lis r4, 0x8028;
  addi r3, r3, 1;
  addi r4, r4, 0x6a14;
  bl LogMsg_0;
  b lbl_8014f168;
lbl_8014f02c:
  li r7, 0;
  addi r30, r3, 0xa;
  sth r7, 4(r3);
  addi r8, r24, 0xa;
  li r5, 1;
  li r4, 5;
  lwz r6, 0x10(r25);
  addi r9, r24, 6;
  li r0, 3;
  mr r29, r30;
  lhz r6, 0x28(r6);
  add r28, r26, r27;
  ori r6, r6, 0x2000;
  stb r6, 8(r3);
  lwz r6, 0x10(r25);
  lhz r6, 0x28(r6);
  ori r6, r6, 0x2000;
  srawi r6, r6, 8;
  stb r6, 9(r3);
  srawi r6, r8, 8;
  srawi r3, r9, 8;
  stb r8, 2(r30);
  stb r6, 3(r30);
  stb r5, 4(r30);
  stb r7, 5(r30);
  stb r4, 6(r30);
  lbz r4, 0x36(r25);
  stb r4, 7(r30);
  stb r9, 8(r30);
  stb r3, 9(r30);
  lhz r3, 0x16(r25);
  stb r3, 0xa(r30);
  lhz r3, 0x16(r25);
  srawi r3, r3, 8;
  stb r3, 0xb(r30);
  stb r7, 0xc(r30);
  stb r7, 0xd(r30);
  stb r0, 0xe(r30);
  stb r7, 0xf(r30);
  addi r30, r30, 0x10;
  b lbl_8014f130;
lbl_8014f0d0:
  lbz r4, 0(r26);
  lbz r3, 1(r26);
  clrlwi r0, r4, 0x19;
  cmpwi r0, 4;
  bge lbl_8014f0fc;
  cmpwi r0, 1;
  bge lbl_8014f0f0;
  b lbl_8014f0fc;
lbl_8014f0f0:
  add r3, r3, r26;
  addi r26, r3, 2;
  b lbl_8014f130;
lbl_8014f0fc:
  addi r24, r3, 2;
  cmpw r24, r27;
  bgt lbl_8014f12c;
  rlwinm. r0, r4, 0, 0x18, 0x18;
  bne lbl_8014f124;
  mr r3, r30;
  mr r4, r26;
  mr r5, r24;
  bl memcpy;
  add r30, r30, r24;
lbl_8014f124:
  add r26, r26, r24;
  b lbl_8014f130;
lbl_8014f12c:
  mr r26, r28;
lbl_8014f130:
  cmplw r26, r28;
  blt lbl_8014f0d0;
  subf r3, r29, r30;
  mr r4, r25;
  addi r3, r3, -2;
  mr r5, r31;
  stb r3, 0(r29);
  rlwinm r0, r3, 0x18, 0x18, 0x1f;
  clrlwi r3, r3, 0x10;
  stb r0, 1(r29);
  addi r0, r3, 4;
  sth r0, 2(r31);
  lwz r3, 0x10(r25);
  bl l2c_link_check_send_pkts;
lbl_8014f168:
  addi r11, r1, 0x30;
  bl _restgpr_24;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: l2cu_send_peer_disc_req
// PAL: 0x8014f180..0x8014f254
MARK_BINARY_BLOB(l2cu_send_peer_disc_req, 0x8014f180, 0x8014f254);
asm UNKNOWN_FUNCTION(l2cu_send_peer_disc_req) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  li r4, 4;
  li r5, 6;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  lwz r7, 0x10(r3);
  lbz r6, 0x31(r7);
  addi r0, r6, 1;
  stb r0, 0x31(r7);
  clrlwi r6, r0, 0x18;
  stb r0, 0x35(r3);
  lwz r3, 0x10(r3);
  lhz r3, 0x28(r3);
  bl l2cu_build_header;
  cmpwi r3, 0;
  bne lbl_8014f1f0;
  lis r3, 0x8034;
  lbz r0, -0x6cc0(r3);
  cmplwi r0, 2;
  blt lbl_8014f240;
  lis r3, 8;
  lis r4, 0x8028;
  addi r3, r3, 1;
  addi r4, r4, 0x69f4;
  bl LogMsg_0;
  b lbl_8014f240;
lbl_8014f1f0:
  lhz r5, 0x16(r31);
  li r0, 0;
  mr r4, r3;
  stb r5, 0x14(r3);
  lhz r5, 0x16(r31);
  srawi r5, r5, 8;
  stb r5, 0x15(r3);
  lhz r5, 0x14(r31);
  stb r5, 0x16(r3);
  lhz r5, 0x14(r31);
  srawi r5, r5, 8;
  stb r5, 0x17(r3);
  sth r0, 6(r3);
  lwz r3, 0x10(r31);
  addi r3, r3, 0x44;
  bl GKI_enqueue;
  lwz r3, 0x10(r31);
  li r4, 0;
  li r5, 0;
  bl l2c_link_check_send_pkts;
lbl_8014f240:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: l2cu_send_peer_disc_rsp
// PAL: 0x8014f254..0x8014f314
MARK_BINARY_BLOB(l2cu_send_peer_disc_rsp, 0x8014f254, 0x8014f314);
asm UNKNOWN_FUNCTION(l2cu_send_peer_disc_rsp) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r6;
  mr r6, r4;
  li r4, 4;
  stw r30, 0x18(r1);
  mr r30, r5;
  li r5, 7;
  stw r29, 0x14(r1);
  mr r29, r3;
  lhz r3, 0x28(r3);
  bl l2cu_build_header;
  cmpwi r3, 0;
  bne lbl_8014f2bc;
  lis r3, 0x8034;
  lbz r0, -0x6cc0(r3);
  cmplwi r0, 2;
  blt lbl_8014f2f8;
  lis r3, 8;
  lis r4, 0x8028;
  addi r3, r3, 1;
  addi r4, r4, 0x69f4;
  bl LogMsg_0;
  b lbl_8014f2f8;
lbl_8014f2bc:
  stb r30, 0x14(r3);
  srawi r4, r30, 8;
  rlwinm r5, r31, 0x18, 0x18, 0x1f;
  li r0, 0;
  stb r4, 0x15(r3);
  mr r4, r3;
  stb r31, 0x16(r3);
  stb r5, 0x17(r3);
  sth r0, 6(r3);
  addi r3, r29, 0x44;
  bl GKI_enqueue;
  mr r3, r29;
  li r4, 0;
  li r5, 0;
  bl l2c_link_check_send_pkts;
lbl_8014f2f8:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: l2cu_send_peer_echo_req
// PAL: 0x8014f314..0x8014f484
MARK_BINARY_BLOB(l2cu_send_peer_echo_req, 0x8014f314, 0x8014f484);
asm UNKNOWN_FUNCTION(l2cu_send_peer_echo_req) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r5;
  stw r30, 0x18(r1);
  mr r30, r4;
  mr r4, r31;
  stw r29, 0x14(r1);
  mr r29, r3;
  lbz r5, 0x31(r3);
  lhz r3, 0x28(r3);
  addi r0, r5, 1;
  li r5, 8;
  stb r0, 0x31(r29);
  clrlwi r6, r0, 0x18;
  bl l2cu_build_header;
  cmpwi r3, 0;
  mr r5, r3;
  bne lbl_8014f38c;
  lis r3, 0x8034;
  lbz r0, -0x6cc0(r3);
  cmplwi r0, 2;
  blt lbl_8014f468;
  lis r3, 8;
  lis r4, 0x8028;
  addi r3, r3, 1;
  addi r4, r4, 0x6a34;
  bl LogMsg_0;
  b lbl_8014f468;
lbl_8014f38c:
  cmpwi cr1, r31, 0;
  addi r7, r3, 0x14;
  beq cr1, lbl_8014f45c;
  li r8, 0;
  ble cr1, lbl_8014f45c;
  cmpwi r31, 8;
  addi r4, r31, -8;
  ble lbl_8014f434;
  li r6, 0;
  blt cr1, lbl_8014f3c8;
  lis r3, 0x8000;
  addi r0, r3, -2;
  cmpw r31, r0;
  bgt lbl_8014f3c8;
  li r6, 1;
lbl_8014f3c8:
  cmpwi r6, 0;
  beq lbl_8014f434;
  addi r0, r4, 7;
  srwi r0, r0, 3;
  mtctr r0;
  cmpwi r4, 0;
  ble lbl_8014f434;
lbl_8014f3e4:
  lbzx r0, r30, r8;
  add r3, r30, r8;
  addi r8, r8, 8;
  stb r0, 0(r7);
  lbz r0, 1(r3);
  stb r0, 1(r7);
  lbz r0, 2(r3);
  stb r0, 2(r7);
  lbz r0, 3(r3);
  stb r0, 3(r7);
  lbz r0, 4(r3);
  stb r0, 4(r7);
  lbz r0, 5(r3);
  stb r0, 5(r7);
  lbz r0, 6(r3);
  stb r0, 6(r7);
  lbz r0, 7(r3);
  stb r0, 7(r7);
  addi r7, r7, 8;
  bdnz lbl_8014f3e4;
lbl_8014f434:
  subf r0, r8, r31;
  add r3, r30, r8;
  mtctr r0;
  cmpw r8, r31;
  bge lbl_8014f45c;
lbl_8014f448:
  lbz r0, 0(r3);
  addi r3, r3, 1;
  stb r0, 0(r7);
  addi r7, r7, 1;
  bdnz lbl_8014f448;
lbl_8014f45c:
  mr r3, r29;
  li r4, 0;
  bl l2c_link_check_send_pkts;
lbl_8014f468:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: l2cu_send_peer_echo_rsp
// PAL: 0x8014f484..0x8014f620
MARK_BINARY_BLOB(l2cu_send_peer_echo_rsp, 0x8014f484, 0x8014f620);
asm UNKNOWN_FUNCTION(l2cu_send_peer_echo_rsp) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  lis r7, 0x8033;
  mr r8, r4;
  stw r0, 0x24(r1);
  addi r7, r7, 0x5d50;
  stw r31, 0x1c(r1);
  mr r31, r6;
  stw r30, 0x18(r1);
  mr r30, r5;
  stw r29, 0x14(r1);
  mr r29, r3;
  lhz r0, 0x7e(r7);
  cmplwi r0, 0x294;
  bge lbl_8014f4c8;
  lhz r4, 0x7c(r7);
  b lbl_8014f4cc;
lbl_8014f4c8:
  li r4, 0x294;
lbl_8014f4cc:
  addi r0, r4, -12;
  clrlwi r0, r0, 0x10;
  cmplw r6, r0;
  ble lbl_8014f4e0;
  li r31, 0;
lbl_8014f4e0:
  lhz r3, 0x28(r3);
  mr r4, r31;
  mr r6, r8;
  li r5, 9;
  bl l2cu_build_header;
  cmpwi r3, 0;
  mr r5, r3;
  bne lbl_8014f528;
  lis r3, 0x8034;
  lbz r0, -0x6cc0(r3);
  cmplwi r0, 2;
  blt lbl_8014f604;
  lis r3, 8;
  lis r4, 0x8028;
  addi r3, r3, 1;
  addi r4, r4, 0x69f4;
  bl LogMsg_0;
  b lbl_8014f604;
lbl_8014f528:
  cmpwi cr1, r31, 0;
  addi r7, r3, 0x14;
  beq cr1, lbl_8014f5f8;
  li r8, 0;
  ble cr1, lbl_8014f5f8;
  cmpwi r31, 8;
  addi r4, r31, -8;
  ble lbl_8014f5d0;
  li r6, 0;
  blt cr1, lbl_8014f564;
  lis r3, 0x8000;
  addi r0, r3, -2;
  cmpw r31, r0;
  bgt lbl_8014f564;
  li r6, 1;
lbl_8014f564:
  cmpwi r6, 0;
  beq lbl_8014f5d0;
  addi r0, r4, 7;
  srwi r0, r0, 3;
  mtctr r0;
  cmpwi r4, 0;
  ble lbl_8014f5d0;
lbl_8014f580:
  lbzx r0, r30, r8;
  add r3, r30, r8;
  addi r8, r8, 8;
  stb r0, 0(r7);
  lbz r0, 1(r3);
  stb r0, 1(r7);
  lbz r0, 2(r3);
  stb r0, 2(r7);
  lbz r0, 3(r3);
  stb r0, 3(r7);
  lbz r0, 4(r3);
  stb r0, 4(r7);
  lbz r0, 5(r3);
  stb r0, 5(r7);
  lbz r0, 6(r3);
  stb r0, 6(r7);
  lbz r0, 7(r3);
  stb r0, 7(r7);
  addi r7, r7, 8;
  bdnz lbl_8014f580;
lbl_8014f5d0:
  subf r0, r8, r31;
  add r3, r30, r8;
  mtctr r0;
  cmpw r8, r31;
  bge lbl_8014f5f8;
lbl_8014f5e4:
  lbz r0, 0(r3);
  addi r3, r3, 1;
  stb r0, 0(r7);
  addi r7, r7, 1;
  bdnz lbl_8014f5e4;
lbl_8014f5f8:
  mr r3, r29;
  li r4, 0;
  bl l2c_link_check_send_pkts;
lbl_8014f604:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: l2cu_send_peer_info_rsp
// PAL: 0x8014f620..0x8014f6c4
MARK_BINARY_BLOB(l2cu_send_peer_info_rsp, 0x8014f620, 0x8014f6c4);
asm UNKNOWN_FUNCTION(l2cu_send_peer_info_rsp) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  mr r6, r4;
  li r4, 4;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r5;
  li r5, 0xb;
  stw r30, 8(r1);
  mr r30, r3;
  lhz r3, 0x28(r3);
  bl l2cu_build_header;
  cmpwi r3, 0;
  bne lbl_8014f680;
  lis r3, 0x8034;
  lbz r0, -0x6cc0(r3);
  cmplwi r0, 2;
  blt lbl_8014f6ac;
  lis r3, 8;
  lis r4, 0x8028;
  addi r3, r3, 1;
  addi r4, r4, 0x69f4;
  bl LogMsg_0;
  b lbl_8014f6ac;
lbl_8014f680:
  stb r31, 0x14(r3);
  rlwinm r4, r31, 0x18, 0x18, 0x1f;
  li r6, 1;
  li r0, 0;
  stb r4, 0x15(r3);
  mr r5, r3;
  li r4, 0;
  stb r6, 0x16(r3);
  stb r0, 0x17(r3);
  mr r3, r30;
  bl l2c_link_check_send_pkts;
lbl_8014f6ac:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: l2cu_allocate_ccb
// PAL: 0x8014f6c4..0x8014f7d0
MARK_BINARY_BLOB(l2cu_allocate_ccb, 0x8014f6c4, 0x8014f7d0);
asm UNKNOWN_FUNCTION(l2cu_allocate_ccb) {
  // clang-format off
  nofralloc;
  lis r7, 0x8034;
  addi r7, r7, -27840;
  lwz r8, 0x7b0(r7);
  cmpwi r8, 0;
  bne lbl_8014f6e0;
  li r3, 0;
  blr;
lbl_8014f6e0:
  addi r0, r7, 0x178;
  lis r4, 0x8421;
  subf r0, r0, r8;
  lwz r6, 8(r8);
  addi r4, r4, 0x843;
  li r5, 1;
  mulhw r4, r4, r0;
  stw r6, 0x7b0(r7);
  stb r5, 0(r8);
  add r0, r4, r0;
  srawi r0, r0, 6;
  srwi r4, r0, 0x1f;
  add r0, r0, r4;
  clrlwi r4, r0, 0x10;
  addi r0, r4, 0x40;
  sth r0, 0x14(r8);
  stw r3, 0x10(r8);
  lwz r0, 8(r3);
  cmpwi r0, 0;
  bne lbl_8014f748;
  stw r8, 0xc(r3);
  li r0, 0;
  stw r8, 8(r3);
  stw r0, 8(r8);
  stw r0, 0xc(r8);
  b lbl_8014f764;
lbl_8014f748:
  li r0, 0;
  stw r0, 8(r8);
  lwz r0, 0xc(r3);
  stw r0, 0xc(r8);
  lwz r4, 0xc(r3);
  stw r8, 8(r4);
  stw r8, 0xc(r3);
lbl_8014f764:
  lis r3, 1;
  li r6, 0x2a0;
  addi r0, r3, -1;
  li r5, 1;
  sth r0, 0x3c(r8);
  li r4, 0;
  li r0, -1;
  mr r3, r8;
  sth r6, 0x3a(r8);
  sth r6, 0x38(r8);
  stb r5, 0x59(r8);
  stb r5, 0x41(r8);
  stw r4, 0x5c(r8);
  stw r4, 0x44(r8);
  stw r4, 0x60(r8);
  stw r4, 0x48(r8);
  stw r4, 0x64(r8);
  stw r4, 0x4c(r8);
  stw r0, 0x68(r8);
  stw r0, 0x50(r8);
  stw r0, 0x6c(r8);
  stw r0, 0x54(r8);
  stb r4, 0x34(r8);
  stw r4, 4(r8);
  stb r5, 0x37(r8);
  stw r8, 0x28(r8);
  blr;
  // clang-format on
}

// Symbol: l2cu_release_ccb
// PAL: 0x8014f7d0..0x8014f974
MARK_BINARY_BLOB(l2cu_release_ccb, 0x8014f7d0, 0x8014f974);
asm UNKNOWN_FUNCTION(l2cu_release_ccb) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  stw r30, 8(r1);
  mr r30, r3;
  lbz r0, 0(r3);
  lwz r31, 0x10(r3);
  cmpwi r0, 0;
  beq lbl_8014f95c;
  li r0, 0;
  stb r0, 0(r3);
  addi r3, r3, 0x18;
  bl btu_stop_timer;
  b lbl_8014f818;
lbl_8014f80c:
  addi r3, r30, 0x70;
  bl GKI_dequeue;
  bl GKI_freebuf;
lbl_8014f818:
  lwz r0, 0x70(r30);
  cmpwi r0, 0;
  bne lbl_8014f80c;
  li r4, 0;
  stw r4, 0x10(r30);
  lwz r0, 8(r31);
  cmplw r0, r30;
  bne lbl_8014f850;
  lwz r3, 8(r30);
  cmpwi r3, 0;
  stw r3, 8(r31);
  beq lbl_8014f884;
  stw r4, 0xc(r3);
  b lbl_8014f884;
lbl_8014f850:
  lwz r0, 0xc(r31);
  cmplw r0, r30;
  bne lbl_8014f86c;
  lwz r3, 0xc(r30);
  stw r3, 0xc(r31);
  stw r4, 8(r3);
  b lbl_8014f884;
lbl_8014f86c:
  lwz r0, 8(r30);
  lwz r3, 0xc(r30);
  stw r0, 8(r3);
  lwz r0, 0xc(r30);
  lwz r3, 8(r30);
  stw r0, 0xc(r3);
lbl_8014f884:
  lis r4, 0x8034;
  addi r4, r4, -27840;
  lwz r0, 0x7b0(r4);
  cmpwi r0, 0;
  bne lbl_8014f8b0;
  stw r30, 0x7b0(r4);
  li r0, 0;
  stw r30, 0x7b4(r4);
  stw r0, 8(r30);
  stw r0, 0xc(r30);
  b lbl_8014f8cc;
lbl_8014f8b0:
  li r0, 0;
  stw r0, 8(r30);
  lwz r0, 0x7b4(r4);
  stw r0, 0xc(r30);
  lwz r3, 0x7b4(r4);
  stw r30, 8(r3);
  stw r30, 0x7b4(r4);
lbl_8014f8cc:
  lbz r0, 0(r31);
  cmpwi r0, 0;
  beq lbl_8014f95c;
  lwz r0, 4(r31);
  cmpwi r0, 4;
  bne lbl_8014f95c;
  lwz r0, 8(r31);
  cmpwi r0, 0;
  bne lbl_8014f95c;
  lhz r3, 0x58(r31);
  cmpwi r3, 0;
  bne lbl_8014f944;
  lhz r3, 0x28(r31);
  li r4, 0x13;
  bl btm_sec_disconnect;
  clrlwi r0, r3, 0x18;
  cmplwi r0, 1;
  bne lbl_8014f924;
  li r0, 5;
  li r3, 0x1e;
  stw r0, 4(r31);
  b lbl_8014f944;
lbl_8014f924:
  cmpwi r0, 0;
  bne lbl_8014f940;
  li r0, 5;
  lis r3, 1;
  stw r0, 4(r31);
  addi r3, r3, -1;
  b lbl_8014f944;
lbl_8014f940:
  li r3, 1;
lbl_8014f944:
  clrlwi r5, r3, 0x10;
  cmplwi r5, 0xffff;
  beq lbl_8014f95c;
  addi r3, r31, 0x10;
  li r4, 2;
  bl btu_start_timer;
lbl_8014f95c:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: l2cu_find_ccb_by_cid
// PAL: 0x8014f974..0x8014f9d0
MARK_BINARY_BLOB(l2cu_find_ccb_by_cid, 0x8014f974, 0x8014f9d0);
asm UNKNOWN_FUNCTION(l2cu_find_ccb_by_cid) {
  // clang-format off
  nofralloc;
  cmplwi r4, 0x40;
  li r5, 0;
  blt lbl_8014f9c8;
  addi r0, r4, -64;
  lis r4, 0x8034;
  clrlwi r0, r0, 0x10;
  mulli r0, r0, 0x7c;
  addi r4, r4, -27840;
  add r4, r4, r0;
  lbz r0, 0x178(r4);
  addi r5, r4, 0x178;
  cmpwi r0, 0;
  bne lbl_8014f9b0;
  li r5, 0;
  b lbl_8014f9c8;
lbl_8014f9b0:
  cmpwi r3, 0;
  beq lbl_8014f9c8;
  lwz r0, 0x10(r5);
  cmplw r3, r0;
  beq lbl_8014f9c8;
  li r5, 0;
lbl_8014f9c8:
  mr r3, r5;
  blr;
  // clang-format on
}

// Symbol: l2cu_allocate_rcb
// PAL: 0x8014f9d0..0x8014fa1c
MARK_BINARY_BLOB(l2cu_allocate_rcb, 0x8014f9d0, 0x8014fa1c);
asm UNKNOWN_FUNCTION(l2cu_allocate_rcb) {
  // clang-format off
  nofralloc;
  lis r4, 0x8034;
  li r0, 8;
  addi r4, r4, -27840;
  li r5, 0;
  addi r4, r4, 0x650;
  mtctr r0;
lbl_8014f9e8:
  lbz r0, 0(r4);
  cmpwi r0, 0;
  bne lbl_8014fa08;
  li r0, 1;
  stb r0, 0(r4);
  sth r3, 2(r4);
  mr r3, r4;
  blr;
lbl_8014fa08:
  addi r5, r5, 1;
  addi r4, r4, 0x2c;
  bdnz lbl_8014f9e8;
  li r3, 0;
  blr;
  // clang-format on
}

// Symbol: l2cu_release_rcb
// PAL: 0x8014fa1c..0x8014fa2c
MARK_BINARY_BLOB(l2cu_release_rcb, 0x8014fa1c, 0x8014fa2c);
asm UNKNOWN_FUNCTION(l2cu_release_rcb) {
  // clang-format off
  nofralloc;
  li r0, 0;
  stb r0, 0(r3);
  sth r0, 2(r3);
  blr;
  // clang-format on
}

// Symbol: l2cu_find_rcb_by_psm
// PAL: 0x8014fa2c..0x8014fae4
MARK_BINARY_BLOB(l2cu_find_rcb_by_psm, 0x8014fa2c, 0x8014fae4);
asm UNKNOWN_FUNCTION(l2cu_find_rcb_by_psm) {
  // clang-format off
  nofralloc;
  lis r4, 0x8034;
  li r0, 2;
  addi r4, r4, -27840;
  li r5, 0;
  addi r4, r4, 0x650;
  mtctr r0;
lbl_8014fa44:
  lbz r0, 0(r4);
  cmpwi r0, 0;
  beq lbl_8014fa64;
  lhz r0, 2(r4);
  cmplw r0, r3;
  bne lbl_8014fa64;
  mr r3, r4;
  blr;
lbl_8014fa64:
  lbzu r0, 0x2c(r4);
  addi r5, r5, 1;
  cmpwi r0, 0;
  beq lbl_8014fa88;
  lhz r0, 2(r4);
  cmplw r0, r3;
  bne lbl_8014fa88;
  mr r3, r4;
  blr;
lbl_8014fa88:
  lbzu r0, 0x2c(r4);
  addi r5, r5, 1;
  cmpwi r0, 0;
  beq lbl_8014faac;
  lhz r0, 2(r4);
  cmplw r0, r3;
  bne lbl_8014faac;
  mr r3, r4;
  blr;
lbl_8014faac:
  lbzu r0, 0x2c(r4);
  addi r5, r5, 1;
  cmpwi r0, 0;
  beq lbl_8014fad0;
  lhz r0, 2(r4);
  cmplw r0, r3;
  bne lbl_8014fad0;
  mr r3, r4;
  blr;
lbl_8014fad0:
  addi r5, r5, 1;
  addi r4, r4, 0x2c;
  bdnz lbl_8014fa44;
  li r3, 0;
  blr;
  // clang-format on
}

// Symbol: l2cu_process_peer_cfg_req
// PAL: 0x8014fae4..0x8014fc2c
MARK_BINARY_BLOB(l2cu_process_peer_cfg_req, 0x8014fae4, 0x8014fc2c);
asm UNKNOWN_FUNCTION(l2cu_process_peer_cfg_req) {
  // clang-format off
  nofralloc;
  lbz r0, 2(r4);
  li r6, 1;
  li r7, 1;
  li r8, 1;
  cmpwi r0, 0;
  beq lbl_8014fb30;
  lhz r0, 4(r4);
  cmplwi r0, 0x30;
  blt lbl_8014fb24;
  cmplwi r0, 0x69b;
  sth r0, 0x3a(r3);
  ble lbl_8014fb30;
  li r0, 0x69b;
  sth r0, 4(r4);
  sth r0, 0x3a(r3);
  b lbl_8014fb30;
lbl_8014fb24:
  li r0, 0x30;
  li r6, 0;
  sth r0, 4(r4);
lbl_8014fb30:
  lbz r0, 0x20(r4);
  cmpwi r0, 0;
  beq lbl_8014fb58;
  lhz r0, 0x22(r4);
  cmpwi r0, 0;
  bne lbl_8014fb58;
  lis r5, 1;
  li r8, 0;
  addi r0, r5, -1;
  sth r0, 0x22(r4);
lbl_8014fb58:
  lbz r0, 6(r4);
  cmpwi r0, 0;
  beq lbl_8014fbb0;
  lbz r0, 9(r4);
  cmplwi r0, 2;
  bgt lbl_8014fba4;
  lwz r5, 8(r4);
  lwz r0, 0xc(r4);
  stw r5, 0x40(r3);
  stw r0, 0x44(r3);
  lwz r5, 0x10(r4);
  lwz r0, 0x14(r4);
  stw r5, 0x48(r3);
  stw r0, 0x4c(r3);
  lwz r5, 0x18(r4);
  lwz r0, 0x1c(r4);
  stw r5, 0x50(r3);
  stw r0, 0x54(r3);
  b lbl_8014fbb0;
lbl_8014fba4:
  li r0, 1;
  li r7, 0;
  stb r0, 9(r4);
lbl_8014fbb0:
  cmpwi r6, 0;
  li r3, 0;
  li r0, 0;
  beq lbl_8014fbd4;
  cmpwi r8, 0;
  beq lbl_8014fbd4;
  cmpwi r7, 0;
  beq lbl_8014fbd4;
  li r0, 1;
lbl_8014fbd4:
  cmpwi r0, 0;
  beq lbl_8014fbe0;
  li r3, 1;
lbl_8014fbe0:
  cmpwi r3, 0;
  bnelr;
  li r0, 1;
  cmpwi r6, 0;
  sth r0, 0(r4);
  beq lbl_8014fc00;
  li r0, 0;
  stb r0, 2(r4);
lbl_8014fc00:
  cmpwi r8, 0;
  beq lbl_8014fc10;
  li r0, 0;
  stb r0, 0x20(r4);
lbl_8014fc10:
  cmpwi r7, 0;
  beq lbl_8014fc20;
  li r0, 0;
  stb r0, 6(r4);
lbl_8014fc20:
  li r0, 0;
  stb r0, 0x24(r4);
  blr;
  // clang-format on
}

// Symbol: l2cu_process_peer_cfg_rsp
// PAL: 0x8014fc2c..0x8014fc6c
MARK_BINARY_BLOB(l2cu_process_peer_cfg_rsp, 0x8014fc2c, 0x8014fc6c);
asm UNKNOWN_FUNCTION(l2cu_process_peer_cfg_rsp) {
  // clang-format off
  nofralloc;
  lbz r0, 6(r4);
  cmpwi r0, 0;
  beqlr;
  lwz r5, 8(r4);
  lwz r0, 0xc(r4);
  stw r5, 0x58(r3);
  stw r0, 0x5c(r3);
  lwz r5, 0x10(r4);
  lwz r0, 0x14(r4);
  stw r5, 0x60(r3);
  stw r0, 0x64(r3);
  lwz r5, 0x18(r4);
  lwz r0, 0x1c(r4);
  stw r5, 0x68(r3);
  stw r0, 0x6c(r3);
  blr;
  // clang-format on
}

// Symbol: l2cu_process_our_cfg_req
// PAL: 0x8014fc6c..0x8014fd7c
MARK_BINARY_BLOB(l2cu_process_our_cfg_req, 0x8014fc6c, 0x8014fd7c);
asm UNKNOWN_FUNCTION(l2cu_process_our_cfg_req) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  stw r30, 8(r1);
  lbz r0, 2(r4);
  cmpwi r0, 0;
  beq lbl_8014fca8;
  lhz r0, 4(r4);
  cmplwi r0, 0x69b;
  sth r0, 0x38(r3);
  ble lbl_8014fca8;
  li r0, 0x69b;
  sth r0, 4(r4);
  sth r0, 0x38(r3);
lbl_8014fca8:
  lbz r0, 6(r4);
  cmpwi r0, 0;
  beq lbl_8014fce4;
  lwz r5, 8(r4);
  lwz r0, 0xc(r4);
  stw r5, 0x58(r3);
  stw r0, 0x5c(r3);
  lwz r5, 0x10(r4);
  lwz r0, 0x14(r4);
  stw r5, 0x60(r3);
  stw r0, 0x64(r3);
  lwz r5, 0x18(r4);
  lwz r0, 0x1c(r4);
  stw r5, 0x68(r3);
  stw r0, 0x6c(r3);
lbl_8014fce4:
  lbz r0, 0x20(r4);
  cmpwi r0, 0;
  beq lbl_8014fd64;
  lhz r0, 0x22(r4);
  cmpwi r0, 0;
  beq lbl_8014fd64;
  sth r0, 0x3c(r3);
  lwz r31, 0x10(r3);
  lhz r3, 0x22(r4);
  lhz r0, 0x32(r31);
  cmplw r3, r0;
  bge lbl_8014fd64;
  sth r3, 0x32(r31);
  lhz r0, 0x22(r4);
  cmplwi r0, 0x4ff;
  bgt lbl_8014fd64;
  rlwinm r3, r0, 3, 0xd, 0x1c;
  lis r4, 0x6666;
  addi r0, r3, 3;
  addi r4, r4, 0x6667;
  li r3, 2;
  mulhw r0, r4, r0;
  srawi r0, r0, 1;
  srwi r4, r0, 0x1f;
  add r0, r0, r4;
  clrlwi r30, r0, 0x10;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  beq lbl_8014fd64;
  lhz r4, 0x28(r31);
  mr r5, r30;
  bl btsnd_hcic_write_auto_flush_tout;
lbl_8014fd64:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: l2cu_process_our_cfg_rsp
// PAL: 0x8014fd7c..0x8014fdbc
MARK_BINARY_BLOB(l2cu_process_our_cfg_rsp, 0x8014fd7c, 0x8014fdbc);
asm UNKNOWN_FUNCTION(l2cu_process_our_cfg_rsp) {
  // clang-format off
  nofralloc;
  lbz r0, 6(r4);
  cmpwi r0, 0;
  beqlr;
  lwz r5, 8(r4);
  lwz r0, 0xc(r4);
  stw r5, 0x40(r3);
  stw r0, 0x44(r3);
  lwz r5, 0x10(r4);
  lwz r0, 0x14(r4);
  stw r5, 0x48(r3);
  stw r0, 0x4c(r3);
  lwz r5, 0x18(r4);
  lwz r0, 0x1c(r4);
  stw r5, 0x50(r3);
  stw r0, 0x54(r3);
  blr;
  // clang-format on
}

// Symbol: l2cu_device_reset
// PAL: 0x8014fdbc..0x8014fe28
MARK_BINARY_BLOB(l2cu_device_reset, 0x8014fdbc, 0x8014fe28);
asm UNKNOWN_FUNCTION(l2cu_device_reset) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r3, 0x8034;
  stw r0, 0x14(r1);
  addi r3, r3, -27840;
  stw r31, 0xc(r1);
  li r31, 0;
  stw r30, 8(r1);
  addi r30, r3, 8;
lbl_8014fde0:
  lbz r0, 0(r30);
  cmpwi r0, 0;
  beq lbl_8014fe00;
  lhz r3, 0x28(r30);
  cmplwi r3, 0xffff;
  beq lbl_8014fe00;
  li r4, 0xff;
  bl l2c_link_hci_disc_comp;
lbl_8014fe00:
  addi r31, r31, 1;
  addi r30, r30, 0x5c;
  cmpwi r31, 4;
  blt lbl_8014fde0;
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: l2cu_create_conn
// PAL: 0x8014fe28..0x8014ff40
MARK_BINARY_BLOB(l2cu_create_conn, 0x8014fe28, 0x8014ff40);
asm UNKNOWN_FUNCTION(l2cu_create_conn) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_24;
  li r0, 3;
  lis r26, 0x8034;
  addi r4, r26, -27840;
  lis r30, 0x8033;
  stw r0, 4(r3);
  mr r31, r3;
  addi r24, r4, 8;
  addi r30, r30, 0x6278;
  li r25, 0;
  lis r28, 8;
  lis r29, 0x8028;
lbl_8014fe68:
  cmplw r24, r31;
  beq lbl_8014ff10;
  lbz r0, 0(r24);
  cmpwi r0, 0;
  beq lbl_8014ff10;
  lbz r0, 0x30(r24);
  cmplwi r0, 1;
  bne lbl_8014ff10;
  addi r3, r24, 0x2a;
  bl btm_is_sco_active_by_bdaddr;
  lbz r0, -0x6cc0(r26);
  mr r27, r3;
  cmplwi r0, 3;
  blt lbl_8014fec0;
  clrlwi r0, r27, 0x18;
  addi r3, r28, 2;
  cmplwi r0, 1;
  addi r4, r29, 0x6a54;
  addi r5, r13, -29544;
  bne lbl_8014febc;
  addi r5, r13, -29552;
lbl_8014febc:
  bl LogMsg_1;
lbl_8014fec0:
  clrlwi r0, r27, 0x18;
  cmplwi r0, 1;
  beq lbl_8014ff10;
  lbz r0, 0x640(r30);
  rlwinm. r0, r0, 0, 0x1a, 0x1a;
  beq lbl_8014ff10;
  li r3, 2;
  li r0, 0;
  stw r3, 4(r31);
  addi r3, r24, 0x2a;
  li r4, 0;
  li r5, 0;
  stb r0, 0x30(r31);
  bl BTM_SwitchRole;
  addi r3, r31, 0x10;
  li r4, 2;
  li r5, 0xa;
  bl btu_start_timer;
  li r3, 1;
  b lbl_8014ff28;
lbl_8014ff10:
  addi r25, r25, 1;
  addi r24, r24, 0x5c;
  cmpwi r25, 4;
  blt lbl_8014fe68;
  mr r3, r31;
  bl l2cu_create_conn_after_switch;
lbl_8014ff28:
  addi r11, r1, 0x30;
  bl _restgpr_24;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: l2cu_create_conn_after_switch
// PAL: 0x8014ff40..0x80150010
MARK_BINARY_BLOB(l2cu_create_conn_after_switch, 0x8014ff40, 0x80150010);
asm UNKNOWN_FUNCTION(l2cu_create_conn_after_switch) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  stw r30, 8(r1);
  mr r30, r3;
  bl BTM_ReadLocalFeatures;
  lbz r4, 0(r3);
  li r0, 3;
  addi r3, r30, 0x2a;
  stw r0, 4(r30);
  rlwinm r31, r4, 0x1b, 0x1f, 0x1f;
  bl BTM_InqDbRead;
  cmpwi r3, 0;
  beq lbl_8014ff90;
  lhz r0, 0(r3);
  lbz r5, 0xb(r3);
  lbz r6, 0xd(r3);
  ori r7, r0, 0x8000;
  b lbl_8014ff9c;
lbl_8014ff90:
  li r5, 1;
  li r6, 0;
  li r7, 0;
lbl_8014ff9c:
  mr r8, r31;
  addi r3, r30, 0x2a;
  li r4, 0x18;
  bl btsnd_hcic_create_conn;
  clrlwi. r0, r3, 0x18;
  bne lbl_8014ffe4;
  lis r3, 0x8034;
  lbz r0, -0x6cc0(r3);
  cmplwi r0, 1;
  blt lbl_8014ffd4;
  lis r4, 0x8028;
  lis r3, 8;
  addi r4, r4, 0x6a98;
  bl LogMsg_0;
lbl_8014ffd4:
  mr r3, r30;
  bl l2cu_release_lcb;
  li r3, 0;
  b lbl_8014fff8;
lbl_8014ffe4:
  addi r3, r30, 0x10;
  li r4, 2;
  li r5, 0x3c;
  bl btu_start_timer;
  li r3, 1;
lbl_8014fff8:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: l2cu_find_lcb_by_state
// PAL: 0x80150010..0x801500a0
MARK_BINARY_BLOB(l2cu_find_lcb_by_state, 0x80150010, 0x801500a0);
asm UNKNOWN_FUNCTION(l2cu_find_lcb_by_state) {
  // clang-format off
  nofralloc;
  lis r4, 0x8034;
  addi r4, r4, -27840;
  lbzu r0, 8(r4);
  cmpwi r0, 0;
  beq lbl_80150038;
  lwz r0, 4(r4);
  cmpw r0, r3;
  bne lbl_80150038;
  mr r3, r4;
  blr;
lbl_80150038:
  lbzu r0, 0x5c(r4);
  cmpwi r0, 0;
  beq lbl_80150058;
  lwz r0, 4(r4);
  cmpw r0, r3;
  bne lbl_80150058;
  mr r3, r4;
  blr;
lbl_80150058:
  lbzu r0, 0x5c(r4);
  cmpwi r0, 0;
  beq lbl_80150078;
  lwz r0, 4(r4);
  cmpw r0, r3;
  bne lbl_80150078;
  mr r3, r4;
  blr;
lbl_80150078:
  lbzu r0, 0x5c(r4);
  cmpwi r0, 0;
  beq lbl_80150098;
  lwz r0, 4(r4);
  cmpw r0, r3;
  bne lbl_80150098;
  mr r3, r4;
  blr;
lbl_80150098:
  li r3, 0;
  blr;
  // clang-format on
}

// Symbol: l2cu_lcb_disconnecting
// PAL: 0x801500a0..0x80150188
MARK_BINARY_BLOB(l2cu_lcb_disconnecting, 0x801500a0, 0x80150188);
asm UNKNOWN_FUNCTION(l2cu_lcb_disconnecting) {
  // clang-format off
  nofralloc;
  lis r4, 0x8034;
  li r0, 2;
  addi r4, r4, -27840;
  li r3, 0;
  addi r5, r4, 8;
  li r6, 0;
  mtctr r0;
lbl_801500bc:
  lbz r0, 0(r5);
  cmpwi r0, 0;
  beq lbl_80150118;
  lwz r4, 8(r5);
  cmpwi r4, 0;
  beq lbl_801500e0;
  lwz r0, 4(r5);
  cmpwi r0, 5;
  bne lbl_801500e8;
lbl_801500e0:
  li r3, 1;
  blr;
lbl_801500e8:
  lwz r0, 0xc(r5);
  cmplw r4, r0;
  bne lbl_80150118;
  lbz r0, 0(r4);
  cmpwi r0, 0;
  beq lbl_80150118;
  lwz r4, 4(r4);
  addi r0, r4, -7;
  cmplwi r0, 1;
  bgt lbl_80150118;
  li r3, 1;
  blr;
lbl_80150118:
  lbz r0, 0x5c(r5);
  addi r6, r6, 1;
  cmpwi r0, 0;
  beq lbl_80150178;
  lwz r4, 0x64(r5);
  cmpwi r4, 0;
  beq lbl_80150140;
  lwz r0, 0x60(r5);
  cmpwi r0, 5;
  bne lbl_80150148;
lbl_80150140:
  li r3, 1;
  blr;
lbl_80150148:
  lwz r0, 0x68(r5);
  cmplw r4, r0;
  bne lbl_80150178;
  lbz r0, 0(r4);
  cmpwi r0, 0;
  beq lbl_80150178;
  lwz r4, 4(r4);
  addi r0, r4, -7;
  cmplwi r0, 1;
  bgt lbl_80150178;
  li r3, 1;
  blr;
lbl_80150178:
  addi r6, r6, 1;
  addi r5, r5, 0xb8;
  bdnz lbl_801500bc;
  blr;
  // clang-format on
}

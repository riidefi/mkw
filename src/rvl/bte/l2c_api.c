#include "l2c_api.h"

#include <string.h>

#include "gki_buffer.h"
#include "bte_logmsg.h"
#include "btm_devctl.h"
#include "l2c_csm.h"
#include "l2c_utils.h"

// Symbol: L2CA_Register
// PAL: 0x8014a060..0x8014a1fc
MARK_BINARY_BLOB(L2CA_Register, 0x8014a060, 0x8014a1fc);
asm UNKNOWN_FUNCTION(L2CA_Register) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  lis r5, 0x8034;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  lis r31, 0x8028;
  addi r31, r31, 0x54a0;
  stw r30, 0x18(r1);
  mr r30, r4;
  stw r29, 0x14(r1);
  mr r29, r3;
  lbz r0, -0x6cc0(r5);
  cmplwi r0, 3;
  blt lbl_8014a0ac;
  lis r3, 8;
  mr r5, r29;
  addi r3, r3, 2;
  addi r4, r31, 0;
  bl LogMsg_1;
lbl_8014a0ac:
  lwz r0, 0x10(r30);
  cmpwi r0, 0;
  beq lbl_8014a0dc;
  lwz r0, 0xc(r30);
  cmpwi r0, 0;
  beq lbl_8014a0dc;
  lwz r0, 0x20(r30);
  cmpwi r0, 0;
  beq lbl_8014a0dc;
  lwz r0, 0x14(r30);
  cmpwi r0, 0;
  bne lbl_8014a104;
lbl_8014a0dc:
  lis r3, 0x8034;
  lbz r0, -0x6cc0(r3);
  cmplwi r0, 1;
  blt lbl_8014a0fc;
  mr r5, r29;
  addi r4, r31, 0x30;
  lis r3, 8;
  bl LogMsg_1;
lbl_8014a0fc:
  li r3, 0;
  b lbl_8014a1e0;
lbl_8014a104:
  andi. r0, r29, 0x101;
  cmpwi r0, 1;
  beq lbl_8014a138;
  lis r3, 0x8034;
  lbz r0, -0x6cc0(r3);
  cmplwi r0, 1;
  blt lbl_8014a130;
  mr r5, r29;
  addi r4, r31, 0x58;
  lis r3, 8;
  bl LogMsg_1;
lbl_8014a130:
  li r3, 0;
  b lbl_8014a1e0;
lbl_8014a138:
  mr r3, r29;
  bl l2cu_find_rcb_by_psm;
  cmpwi r3, 0;
  mr r5, r3;
  bne lbl_8014a18c;
  mr r3, r29;
  bl l2cu_allocate_rcb;
  cmpwi r3, 0;
  mr r5, r3;
  bne lbl_8014a18c;
  lis r3, 0x8034;
  lbz r0, -0x6cc0(r3);
  cmplwi r0, 2;
  blt lbl_8014a184;
  lis r3, 8;
  mr r5, r29;
  addi r3, r3, 1;
  addi r4, r31, 0x80;
  bl LogMsg_1;
lbl_8014a184:
  li r3, 0;
  b lbl_8014a1e0;
lbl_8014a18c:
  lwz r4, 0(r30);
  li r3, 1;
  lwz r0, 4(r30);
  stw r4, 4(r5);
  stw r0, 8(r5);
  lwz r4, 8(r30);
  lwz r0, 0xc(r30);
  stw r4, 0xc(r5);
  stw r0, 0x10(r5);
  lwz r4, 0x10(r30);
  lwz r0, 0x14(r30);
  stw r4, 0x14(r5);
  stw r0, 0x18(r5);
  lwz r4, 0x18(r30);
  lwz r0, 0x1c(r30);
  stw r4, 0x1c(r5);
  stw r0, 0x20(r5);
  lwz r4, 0x20(r30);
  lwz r0, 0x24(r30);
  stw r4, 0x24(r5);
  stw r0, 0x28(r5);
lbl_8014a1e0:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: L2CA_Deregister
// PAL: 0x8014a1fc..0x8014a28c
MARK_BINARY_BLOB(L2CA_Deregister, 0x8014a1fc, 0x8014a28c);
asm UNKNOWN_FUNCTION(L2CA_Deregister) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r4, 0x8034;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  lbz r0, -0x6cc0(r4);
  cmplwi r0, 3;
  blt lbl_8014a238;
  lis r3, 8;
  lis r4, 0x8028;
  mr r5, r31;
  addi r3, r3, 2;
  addi r4, r4, 0x5548;
  bl LogMsg_1;
lbl_8014a238:
  mr r3, r31;
  bl l2cu_find_rcb_by_psm;
  cmpwi r3, 0;
  beq lbl_8014a250;
  bl l2cu_release_rcb;
  b lbl_8014a278;
lbl_8014a250:
  lis r3, 0x8034;
  lbz r0, -0x6cc0(r3);
  cmplwi r0, 2;
  blt lbl_8014a278;
  lis r3, 8;
  lis r4, 0x8028;
  mr r5, r31;
  addi r3, r3, 1;
  addi r4, r4, 0x557c;
  bl LogMsg_1;
lbl_8014a278:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: L2CA_ConnectReq
// PAL: 0x8014a28c..0x8014a4c0
MARK_BINARY_BLOB(L2CA_ConnectReq, 0x8014a28c, 0x8014a4c0);
asm UNKNOWN_FUNCTION(L2CA_ConnectReq) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  lis r5, 0x8034;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  lis r31, 0x8028;
  addi r31, r31, 0x54a0;
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  mr r29, r3;
  stw r28, 0x10(r1);
  mr r28, r4;
  lbz r0, -0x6cc0(r5);
  cmplwi r0, 3;
  blt lbl_8014a2dc;
  lis r3, 8;
  mr r5, r29;
  addi r3, r3, 2;
  addi r4, r31, 0x110;
  bl LogMsg_1;
lbl_8014a2dc:
  lis r3, 0x8034;
  lbz r0, -0x6cc0(r3);
  cmplwi r0, 3;
  blt lbl_8014a314;
  lis r3, 8;
  lbz r5, 0(r28);
  lbz r6, 1(r28);
  addi r3, r3, 2;
  lbz r7, 2(r28);
  addi r4, r31, 0x130;
  lbz r8, 3(r28);
  lbz r9, 4(r28);
  lbz r10, 5(r28);
  bl LogMsg_6;
lbl_8014a314:
  bl BTM_IsDeviceUp;
  clrlwi. r0, r3, 0x18;
  bne lbl_8014a348;
  lis r3, 0x8034;
  lbz r0, -0x6cc0(r3);
  cmplwi r0, 2;
  blt lbl_8014a340;
  lis r3, 8;
  addi r4, r31, 0x168;
  addi r3, r3, 1;
  bl LogMsg_0;
lbl_8014a340:
  li r3, 0;
  b lbl_8014a4a0;
lbl_8014a348:
  mr r3, r29;
  bl l2cu_find_rcb_by_psm;
  cmpwi r3, 0;
  mr r30, r3;
  bne lbl_8014a388;
  lis r3, 0x8034;
  lbz r0, -0x6cc0(r3);
  cmplwi r0, 2;
  blt lbl_8014a380;
  lis r3, 8;
  mr r5, r29;
  addi r3, r3, 1;
  addi r4, r31, 0x18c;
  bl LogMsg_1;
lbl_8014a380:
  li r3, 0;
  b lbl_8014a4a0;
lbl_8014a388:
  mr r3, r28;
  bl l2cu_find_lcb_by_bd_addr;
  cmpwi r3, 0;
  mr r29, r3;
  bne lbl_8014a3ec;
  mr r3, r28;
  bl l2cu_allocate_lcb;
  cmpwi r3, 0;
  mr r29, r3;
  bne lbl_8014a3d8;
  lis r3, 0x8034;
  lbz r0, -0x6cc0(r3);
  cmplwi r0, 2;
  blt lbl_8014a3d0;
  lis r3, 8;
  addi r4, r31, 0x1bc;
  addi r3, r3, 1;
  bl LogMsg_0;
lbl_8014a3d0:
  li r3, 0;
  b lbl_8014a4a0;
lbl_8014a3d8:
  bl l2cu_create_conn;
  clrlwi. r0, r3, 0x18;
  bne lbl_8014a3ec;
  li r3, 0;
  b lbl_8014a4a0;
lbl_8014a3ec:
  lwz r0, 4(r29);
  cmpwi r0, 5;
  bne lbl_8014a420;
  lis r3, 0x8034;
  lbz r0, -0x6cc0(r3);
  cmplwi r0, 3;
  blt lbl_8014a418;
  lis r3, 8;
  addi r4, r31, 0x1e0;
  addi r3, r3, 2;
  bl LogMsg_0;
lbl_8014a418:
  li r3, 0;
  b lbl_8014a4a0;
lbl_8014a420:
  mr r3, r29;
  bl l2cu_allocate_ccb;
  cmpwi r3, 0;
  mr r28, r3;
  bne lbl_8014a45c;
  lis r3, 0x8034;
  lbz r0, -0x6cc0(r3);
  cmplwi r0, 2;
  blt lbl_8014a454;
  lis r3, 8;
  addi r4, r31, 0x218;
  addi r3, r3, 1;
  bl LogMsg_0;
lbl_8014a454:
  li r3, 0;
  b lbl_8014a4a0;
lbl_8014a45c:
  stw r30, 0x30(r3);
  lwz r0, 4(r29);
  cmpwi r0, 4;
  bne lbl_8014a478;
  li r4, 0x14;
  li r5, 0;
  bl l2c_csm_execute;
lbl_8014a478:
  lis r3, 0x8034;
  lbz r0, -0x6cc0(r3);
  cmplwi r0, 3;
  blt lbl_8014a49c;
  lis r3, 8;
  lhz r5, 0x14(r28);
  addi r3, r3, 2;
  addi r4, r31, 0x23c;
  bl LogMsg_1;
lbl_8014a49c:
  lhz r3, 0x14(r28);
lbl_8014a4a0:
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

// Symbol: L2CA_ConnectRsp
// PAL: 0x8014a4c0..0x8014a650
MARK_BINARY_BLOB(L2CA_ConnectRsp, 0x8014a4c0, 0x8014a650);
asm UNKNOWN_FUNCTION(L2CA_ConnectRsp) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_26;
  lis r8, 0x8034;
  lis r31, 0x8028;
  lbz r0, -0x6cc0(r8);
  mr r26, r3;
  mr r27, r4;
  mr r28, r5;
  cmplwi r0, 3;
  mr r29, r6;
  mr r30, r7;
  addi r31, r31, 0x54a0;
  blt lbl_8014a510;
  lis r3, 8;
  addi r4, r31, 0x26c;
  addi r3, r3, 2;
  bl LogMsg_3;
lbl_8014a510:
  lis r3, 0x8034;
  lbz r0, -0x6cc0(r3);
  cmplwi r0, 3;
  blt lbl_8014a548;
  lis r3, 8;
  lbz r5, 0(r26);
  lbz r6, 1(r26);
  addi r3, r3, 2;
  lbz r7, 2(r26);
  addi r4, r31, 0x2a4;
  lbz r8, 3(r26);
  lbz r9, 4(r26);
  lbz r10, 5(r26);
  bl LogMsg_6;
lbl_8014a548:
  mr r3, r26;
  bl l2cu_find_lcb_by_bd_addr;
  cmpwi r3, 0;
  bne lbl_8014a580;
  lis r3, 0x8034;
  lbz r0, -0x6cc0(r3);
  cmplwi r0, 2;
  blt lbl_8014a578;
  lis r3, 8;
  addi r4, r31, 0x2dc;
  addi r3, r3, 1;
  bl LogMsg_0;
lbl_8014a578:
  li r3, 0;
  b lbl_8014a638;
lbl_8014a580:
  mr r4, r28;
  bl l2cu_find_ccb_by_cid;
  cmpwi r3, 0;
  bne lbl_8014a5b8;
  lis r3, 0x8034;
  lbz r0, -0x6cc0(r3);
  cmplwi r0, 2;
  blt lbl_8014a5b0;
  lis r3, 8;
  addi r4, r31, 0x300;
  addi r3, r3, 1;
  bl LogMsg_0;
lbl_8014a5b0:
  li r3, 0;
  b lbl_8014a638;
lbl_8014a5b8:
  lbz r5, 0x36(r3);
  cmplw r5, r27;
  beq lbl_8014a5f0;
  lis r3, 0x8034;
  lbz r0, -0x6cc0(r3);
  cmplwi r0, 2;
  blt lbl_8014a5e8;
  lis r3, 8;
  mr r6, r27;
  addi r4, r31, 0x324;
  addi r3, r3, 1;
  bl LogMsg_2;
lbl_8014a5e8:
  li r3, 0;
  b lbl_8014a638;
lbl_8014a5f0:
  cmpwi r29, 0;
  bne lbl_8014a608;
  li r4, 0x15;
  li r5, 0;
  bl l2c_csm_execute;
  b lbl_8014a634;
lbl_8014a608:
  cmplwi r29, 1;
  sth r29, 0x12(r1);
  sth r30, 0x14(r1);
  bne lbl_8014a628;
  addi r5, r1, 8;
  li r4, 0x15;
  bl l2c_csm_execute;
  b lbl_8014a634;
lbl_8014a628:
  addi r5, r1, 8;
  li r4, 0x16;
  bl l2c_csm_execute;
lbl_8014a634:
  li r3, 1;
lbl_8014a638:
  addi r11, r1, 0x30;
  bl _restgpr_26;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: L2CA_ConfigReq
// PAL: 0x8014a650..0x8014a708
MARK_BINARY_BLOB(L2CA_ConfigReq, 0x8014a650, 0x8014a708);
asm UNKNOWN_FUNCTION(L2CA_ConfigReq) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r5, 0x8034;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  lbz r0, -0x6cc0(r5);
  cmplwi r0, 3;
  blt lbl_8014a694;
  lis r3, 8;
  lis r4, 0x8028;
  mr r5, r30;
  addi r3, r3, 2;
  addi r4, r4, 0x57f8;
  bl LogMsg_1;
lbl_8014a694:
  mr r4, r30;
  li r3, 0;
  bl l2cu_find_ccb_by_cid;
  cmpwi r3, 0;
  bne lbl_8014a6d8;
  lis r3, 0x8034;
  lbz r0, -0x6cc0(r3);
  cmplwi r0, 2;
  blt lbl_8014a6d0;
  lis r3, 8;
  lis r4, 0x8028;
  mr r5, r30;
  addi r3, r3, 1;
  addi r4, r4, 0x5818;
  bl LogMsg_1;
lbl_8014a6d0:
  li r3, 0;
  b lbl_8014a6f0;
lbl_8014a6d8:
  li r0, 0;
  mr r5, r31;
  stb r0, 0x24(r31);
  li r4, 0x17;
  bl l2c_csm_execute;
  li r3, 1;
lbl_8014a6f0:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: L2CA_ConfigRsp
// PAL: 0x8014a708..0x8014a7d8
MARK_BINARY_BLOB(L2CA_ConfigRsp, 0x8014a708, 0x8014a7d8);
asm UNKNOWN_FUNCTION(L2CA_ConfigRsp) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r5, 0x8034;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  lbz r0, -0x6cc0(r5);
  cmplwi r0, 3;
  blt lbl_8014a750;
  lis r3, 8;
  lis r4, 0x8028;
  lhz r6, 0(r31);
  mr r5, r30;
  addi r3, r3, 2;
  addi r4, r4, 0x5844;
  bl LogMsg_2;
lbl_8014a750:
  mr r4, r30;
  li r3, 0;
  bl l2cu_find_ccb_by_cid;
  cmpwi r3, 0;
  bne lbl_8014a794;
  lis r3, 0x8034;
  lbz r0, -0x6cc0(r3);
  cmplwi r0, 2;
  blt lbl_8014a78c;
  lis r3, 8;
  lis r4, 0x8028;
  mr r5, r30;
  addi r3, r3, 1;
  addi r4, r4, 0x5870;
  bl LogMsg_1;
lbl_8014a78c:
  li r3, 0;
  b lbl_8014a7c0;
lbl_8014a794:
  lhz r0, 0(r31);
  cmpwi r0, 0;
  bne lbl_8014a7b0;
  mr r5, r31;
  li r4, 0x18;
  bl l2c_csm_execute;
  b lbl_8014a7bc;
lbl_8014a7b0:
  mr r5, r31;
  li r4, 0x19;
  bl l2c_csm_execute;
lbl_8014a7bc:
  li r3, 1;
lbl_8014a7c0:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: L2CA_DisconnectReq
// PAL: 0x8014a7d8..0x8014a87c
MARK_BINARY_BLOB(L2CA_DisconnectReq, 0x8014a7d8, 0x8014a87c);
asm UNKNOWN_FUNCTION(L2CA_DisconnectReq) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r4, 0x8034;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  lbz r0, -0x6cc0(r4);
  cmplwi r0, 3;
  blt lbl_8014a814;
  lis r3, 8;
  lis r4, 0x8028;
  mr r5, r31;
  addi r3, r3, 2;
  addi r4, r4, 0x589c;
  bl LogMsg_1;
lbl_8014a814:
  mr r4, r31;
  li r3, 0;
  bl l2cu_find_ccb_by_cid;
  cmpwi r3, 0;
  bne lbl_8014a858;
  lis r3, 0x8034;
  lbz r0, -0x6cc0(r3);
  cmplwi r0, 2;
  blt lbl_8014a850;
  lis r3, 8;
  lis r4, 0x8028;
  mr r5, r31;
  addi r3, r3, 1;
  addi r4, r4, 0x58c0;
  bl LogMsg_1;
lbl_8014a850:
  li r3, 0;
  b lbl_8014a868;
lbl_8014a858:
  li r4, 0x1a;
  li r5, 0;
  bl l2c_csm_execute;
  li r3, 1;
lbl_8014a868:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: L2CA_DisconnectRsp
// PAL: 0x8014a87c..0x8014a920
MARK_BINARY_BLOB(L2CA_DisconnectRsp, 0x8014a87c, 0x8014a920);
asm UNKNOWN_FUNCTION(L2CA_DisconnectRsp) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r4, 0x8034;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  lbz r0, -0x6cc0(r4);
  cmplwi r0, 3;
  blt lbl_8014a8b8;
  lis r3, 8;
  lis r4, 0x8028;
  mr r5, r31;
  addi r3, r3, 2;
  addi r4, r4, 0x58ec;
  bl LogMsg_1;
lbl_8014a8b8:
  mr r4, r31;
  li r3, 0;
  bl l2cu_find_ccb_by_cid;
  cmpwi r3, 0;
  bne lbl_8014a8fc;
  lis r3, 0x8034;
  lbz r0, -0x6cc0(r3);
  cmplwi r0, 2;
  blt lbl_8014a8f4;
  lis r3, 8;
  lis r4, 0x8028;
  mr r5, r31;
  addi r3, r3, 1;
  addi r4, r4, 0x5910;
  bl LogMsg_1;
lbl_8014a8f4:
  li r3, 0;
  b lbl_8014a90c;
lbl_8014a8fc:
  li r4, 0x1b;
  li r5, 0;
  bl l2c_csm_execute;
  li r3, 1;
lbl_8014a90c:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: L2CA_DataWrite
// PAL: 0x8014a920..0x8014aa44
MARK_BINARY_BLOB(L2CA_DataWrite, 0x8014a920, 0x8014aa44);
asm UNKNOWN_FUNCTION(L2CA_DataWrite) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  lis r5, 0x8034;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  lis r31, 0x8028;
  addi r31, r31, 0x54a0;
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  mr r29, r4;
  stw r28, 0x10(r1);
  mr r28, r3;
  lbz r0, -0x6cc0(r5);
  cmplwi r0, 3;
  blt lbl_8014a974;
  lis r3, 8;
  lhz r6, 2(r29);
  mr r5, r28;
  addi r4, r31, 0x49c;
  addi r3, r3, 2;
  bl LogMsg_2;
lbl_8014a974:
  mr r4, r28;
  li r3, 0;
  bl l2cu_find_ccb_by_cid;
  cmpwi r3, 0;
  mr r30, r3;
  bne lbl_8014a9c0;
  lis r3, 0x8034;
  lbz r0, -0x6cc0(r3);
  cmplwi r0, 2;
  blt lbl_8014a9b0;
  lis r3, 8;
  mr r5, r28;
  addi r3, r3, 1;
  addi r4, r31, 0x4c4;
  bl LogMsg_1;
lbl_8014a9b0:
  mr r3, r29;
  bl GKI_freebuf;
  li r3, 0;
  b lbl_8014aa24;
lbl_8014a9c0:
  lhz r4, 2(r29);
  lhz r0, 0x3a(r3);
  cmplw r4, r0;
  bgt lbl_8014a9f8;
  mr r5, r29;
  li r4, 0x1d;
  bl l2c_csm_execute;
  lwz r3, 0x10(r30);
  lbz r3, 0x41(r3);
  neg r0, r3;
  or r0, r0, r3;
  srwi r3, r0, 0x1f;
  addi r3, r3, 1;
  b lbl_8014aa24;
lbl_8014a9f8:
  lis r3, 0x8034;
  lbz r0, -0x6cc0(r3);
  cmplwi r0, 2;
  blt lbl_8014aa18;
  lis r3, 8;
  addi r4, r31, 0x4f0;
  addi r3, r3, 1;
  bl LogMsg_0;
lbl_8014aa18:
  mr r3, r29;
  bl GKI_freebuf;
  li r3, 0;
lbl_8014aa24:
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

// Symbol: L2CA_SetIdleTimeout
// PAL: 0x8014aa44..0x8014ab0c
MARK_BINARY_BLOB(L2CA_SetIdleTimeout, 0x8014aa44, 0x8014ab0c);
asm UNKNOWN_FUNCTION(L2CA_SetIdleTimeout) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmpwi r5, 0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  beq lbl_8014aa78;
  lis r3, 0x8034;
  addi r3, r3, -27840;
  sth r4, 0x7ba(r3);
  b lbl_8014aaf0;
lbl_8014aa78:
  mr r4, r30;
  li r3, 0;
  bl l2cu_find_ccb_by_cid;
  cmpwi r3, 0;
  bne lbl_8014aabc;
  lis r3, 0x8034;
  lbz r0, -0x6cc0(r3);
  cmplwi r0, 2;
  blt lbl_8014aab4;
  lis r3, 8;
  lis r4, 0x8028;
  mr r5, r30;
  addi r3, r3, 1;
  addi r4, r4, 0x5a70;
  bl LogMsg_1;
lbl_8014aab4:
  li r3, 0;
  b lbl_8014aaf4;
lbl_8014aabc:
  lwz r3, 0x10(r3);
  cmpwi r3, 0;
  beq lbl_8014aae8;
  lbz r0, 0(r3);
  cmpwi r0, 0;
  beq lbl_8014aae8;
  lwz r0, 4(r3);
  cmpwi r0, 4;
  bne lbl_8014aae8;
  sth r31, 0x58(r3);
  b lbl_8014aaf0;
lbl_8014aae8:
  li r3, 0;
  b lbl_8014aaf4;
lbl_8014aaf0:
  li r3, 1;
lbl_8014aaf4:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: L2CA_SetIdleTimeoutByBdAddr
// PAL: 0x8014ab0c..0x8014ac0c
MARK_BINARY_BLOB(L2CA_SetIdleTimeoutByBdAddr, 0x8014ab0c, 0x8014ac0c);
asm UNKNOWN_FUNCTION(L2CA_SetIdleTimeoutByBdAddr) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  li r5, 6;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  mr r4, r30;
  addi r3, r2, -26864;
  bl memcmp;
  cmpwi r3, 0;
  beq lbl_8014ab78;
  mr r3, r30;
  bl l2cu_find_lcb_by_bd_addr;
  cmpwi r3, 0;
  beq lbl_8014ab70;
  lbz r0, 0(r3);
  cmpwi r0, 0;
  beq lbl_8014ab70;
  lwz r0, 4(r3);
  cmpwi r0, 4;
  bne lbl_8014ab70;
  sth r31, 0x58(r3);
  b lbl_8014abf0;
lbl_8014ab70:
  li r3, 0;
  b lbl_8014abf4;
lbl_8014ab78:
  lis r3, 0x8034;
  addi r3, r3, -27840;
  lbz r0, 8(r3);
  cmpwi r0, 0;
  beq lbl_8014ab9c;
  lwz r0, 0xc(r3);
  cmpwi r0, 4;
  bne lbl_8014ab9c;
  sth r31, 0x60(r3);
lbl_8014ab9c:
  lbzu r0, 0x64(r3);
  cmpwi r0, 0;
  beq lbl_8014abb8;
  lwz r0, 4(r3);
  cmpwi r0, 4;
  bne lbl_8014abb8;
  sth r31, 0x58(r3);
lbl_8014abb8:
  lbz r0, 0x5c(r3);
  cmpwi r0, 0;
  beq lbl_8014abd4;
  lwz r0, 0x60(r3);
  cmpwi r0, 4;
  bne lbl_8014abd4;
  sth r31, 0xb4(r3);
lbl_8014abd4:
  lbz r0, 0xb8(r3);
  cmpwi r0, 0;
  beq lbl_8014abf0;
  lwz r0, 0xbc(r3);
  cmpwi r0, 4;
  bne lbl_8014abf0;
  sth r31, 0x110(r3);
lbl_8014abf0:
  li r3, 1;
lbl_8014abf4:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: L2CA_SetTraceLevel
// PAL: 0x8014ac0c..0x8014ac28
MARK_BINARY_BLOB(L2CA_SetTraceLevel, 0x8014ac0c, 0x8014ac28);
asm UNKNOWN_FUNCTION(L2CA_SetTraceLevel) {
  // clang-format off
  nofralloc;
  cmplwi r3, 0xff;
  beq lbl_8014ac1c;
  lis r4, 0x8034;
  stb r3, -0x6cc0(r4);
lbl_8014ac1c:
  lis r3, 0x8034;
  lbz r3, -0x6cc0(r3);
  blr;
  // clang-format on
}

// Symbol: L2CA_RegisterCompression
// PAL: 0x8014ac28..0x8014ac2c
MARK_BINARY_BLOB(L2CA_RegisterCompression, 0x8014ac28, 0x8014ac2c);
asm UNKNOWN_FUNCTION(L2CA_RegisterCompression) {
  // clang-format off
  nofralloc;
  blr;
  // clang-format on
}

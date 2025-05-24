#include "gap_conn.h"

#include <string.h>

#include "gki_buffer.h"
#include "bte_logmsg.h"
#include "l2c_api.h"

// Symbol: gap_conn_init
// PAL: 0x801434c0..0x80143530
MARK_BINARY_BLOB(gap_conn_init, 0x801434c0, 0x80143530);
asm UNKNOWN_FUNCTION(gap_conn_init) {
  // clang-format off
  nofralloc;
  lis r10, 0x8014;
  lis r9, 0x8034;
  lis r8, 0x8014;
  lis r7, 0x8014;
  lis r6, 0x8014;
  lis r5, 0x8014;
  lis r4, 0x8014;
  lis r3, 0x8014;
  addi r10, r10, 0x3530;
  addi r9, r9, -30144;
  li r0, 0;
  addi r8, r8, 0x36bc;
  addi r7, r7, 0x3898;
  addi r6, r6, 0x39d4;
  addi r5, r5, 0x3bc0;
  addi r4, r4, 0x3db8;
  addi r3, r3, 0x3ec8;
  stw r10, 0x84(r9);
  stw r8, 0x88(r9);
  stw r0, 0x8c(r9);
  stw r7, 0x90(r9);
  stw r6, 0x94(r9);
  stw r5, 0x98(r9);
  stw r0, 0x9c(r9);
  stw r0, 0xa0(r9);
  stw r4, 0xa4(r9);
  stw r3, 0xa8(r9);
  blr;
  // clang-format on
}

// Symbol: gap_connect_ind
// PAL: 0x80143530..0x801436bc
MARK_BINARY_BLOB(gap_connect_ind, 0x80143530, 0x801436bc);
asm UNKNOWN_FUNCTION(gap_connect_ind) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_26;
  lis r7, 0x8034;
  mr r26, r3;
  addi r7, r7, -30144;
  mr r31, r4;
  mr r27, r5;
  mr r28, r6;
  addi r29, r7, 0xac;
  li r30, 0;
lbl_80143564:
  lbz r0, 0(r29);
  cmplwi r0, 1;
  bne lbl_801435a0;
  lhz r0, 0x10(r29);
  cmplw r0, r27;
  bne lbl_801435a0;
  lbz r0, 8(r29);
  cmpwi r0, 0;
  beq lbl_801435b0;
  mr r3, r26;
  addi r4, r29, 9;
  li r5, 6;
  bl memcmp;
  cmpwi r3, 0;
  beq lbl_801435b0;
lbl_801435a0:
  addi r30, r30, 1;
  addi r29, r29, 0x60;
  cmplwi r30, 8;
  blt lbl_80143564;
lbl_801435b0:
  clrlwi r0, r30, 0x10;
  cmplwi r0, 8;
  bne lbl_80143638;
  lis r3, 0x8034;
  addi r3, r3, -30144;
  lbz r0, 0x28(r3);
  cmplwi r0, 2;
  blt lbl_801435e0;
  lis r3, 0xe;
  addi r4, r13, -29560;
  addi r3, r3, 1;
  bl LogMsg_0;
lbl_801435e0:
  lis r3, 0x8034;
  addi r3, r3, -30144;
  lbz r0, 0x28(r3);
  cmplwi r0, 2;
  blt lbl_80143608;
  lis r3, 0xe;
  lis r4, 0x8028;
  addi r3, r3, 1;
  addi r4, r4, 0x4b90;
  bl LogMsg_0;
lbl_80143608:
  lis r3, 0x8034;
  addi r3, r3, -30144;
  lbz r0, 0x28(r3);
  cmplwi r0, 2;
  blt lbl_8014362c;
  lis r3, 0xe;
  addi r4, r13, -29560;
  addi r3, r3, 1;
  bl LogMsg_0;
lbl_8014362c:
  mr r3, r31;
  bl L2CA_DisconnectReq;
  b lbl_801436a4;
lbl_80143638:
  li r0, 3;
  mr r4, r26;
  stb r0, 0(r29);
  addi r3, r29, 9;
  li r5, 6;
  bl memcpy;
  sth r31, 6(r29);
  mr r3, r26;
  mr r4, r28;
  mr r5, r31;
  li r6, 0;
  li r7, 0;
  bl L2CA_ConnectRsp;
  lis r3, 0x8034;
  addi r3, r3, -30144;
  lbz r0, 0x28(r3);
  cmplwi r0, 4;
  blt lbl_80143698;
  lis r3, 0xe;
  lis r4, 0x8028;
  lhz r5, 6(r29);
  addi r3, r3, 3;
  addi r4, r4, 0x4bd4;
  bl LogMsg_1;
lbl_80143698:
  mr r3, r31;
  addi r4, r29, 0x24;
  bl L2CA_ConfigReq;
lbl_801436a4:
  addi r11, r1, 0x20;
  bl _restgpr_26;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: gap_connect_cfm
// PAL: 0x801436bc..0x80143898
MARK_BINARY_BLOB(gap_connect_cfm, 0x801436bc, 0x80143898);
asm UNKNOWN_FUNCTION(gap_connect_cfm) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r5, 0x8034;
  stw r0, 0x14(r1);
  li r0, 2;
  addi r5, r5, -30144;
  stw r31, 0xc(r1);
  addi r31, r5, 0xac;
  li r5, 0;
  stw r30, 8(r1);
  mtctr r0;
lbl_801436e8:
  lbz r0, 0(r31);
  cmpwi r0, 0;
  beq lbl_80143704;
  lhz r0, 6(r31);
  cmplw r0, r3;
  bne lbl_80143704;
  b lbl_80143774;
lbl_80143704:
  lbzu r0, 0x60(r31);
  addi r5, r5, 1;
  cmpwi r0, 0;
  beq lbl_80143724;
  lhz r0, 6(r31);
  cmplw r0, r3;
  bne lbl_80143724;
  b lbl_80143774;
lbl_80143724:
  lbzu r0, 0x60(r31);
  addi r5, r5, 1;
  cmpwi r0, 0;
  beq lbl_80143744;
  lhz r0, 6(r31);
  cmplw r0, r3;
  bne lbl_80143744;
  b lbl_80143774;
lbl_80143744:
  lbzu r0, 0x60(r31);
  addi r5, r5, 1;
  cmpwi r0, 0;
  beq lbl_80143764;
  lhz r0, 6(r31);
  cmplw r0, r3;
  bne lbl_80143764;
  b lbl_80143774;
lbl_80143764:
  addi r5, r5, 1;
  addi r31, r31, 0x60;
  bdnz lbl_801436e8;
  li r31, 0;
lbl_80143774:
  cmpwi r31, 0;
  beq lbl_80143880;
  cmpwi r4, 0;
  bne lbl_801437a4;
  lbz r0, 0(r31);
  cmplwi r0, 2;
  bne lbl_801437a4;
  li r0, 3;
  addi r4, r31, 0x24;
  stb r0, 0(r31);
  bl L2CA_ConfigReq;
  b lbl_80143880;
lbl_801437a4:
  lwz r12, 0x20(r31);
  cmpwi r12, 0;
  beq lbl_801437c0;
  lhz r3, 4(r31);
  li r4, 0x101;
  mtctr r12;
  bctrl;
lbl_801437c0:
  lhz r30, 0x10(r31);
  b lbl_801437d4;
lbl_801437c8:
  addi r3, r31, 0x14;
  bl GKI_dequeue;
  bl GKI_freebuf;
lbl_801437d4:
  lwz r0, 0x14(r31);
  cmpwi r0, 0;
  bne lbl_801437c8;
  lis r3, 0x8034;
  li r4, 0;
  addi r3, r3, -30144;
  li r0, 2;
  stb r4, 0(r31);
  addi r4, r3, 0xac;
  li r3, 0;
  mtctr r0;
lbl_80143800:
  lbz r0, 0(r4);
  cmpwi r0, 0;
  beq lbl_80143818;
  lhz r0, 0x10(r4);
  cmplw r0, r30;
  beq lbl_80143880;
lbl_80143818:
  lbz r0, 0x60(r4);
  addi r3, r3, 1;
  cmpwi r0, 0;
  beq lbl_80143834;
  lhz r0, 0x70(r4);
  cmplw r0, r30;
  beq lbl_80143880;
lbl_80143834:
  lbz r0, 0xc0(r4);
  addi r3, r3, 1;
  cmpwi r0, 0;
  beq lbl_80143850;
  lhz r0, 0xd0(r4);
  cmplw r0, r30;
  beq lbl_80143880;
lbl_80143850:
  lbz r0, 0x120(r4);
  addi r3, r3, 1;
  cmpwi r0, 0;
  beq lbl_8014386c;
  lhz r0, 0x130(r4);
  cmplw r0, r30;
  beq lbl_80143880;
lbl_8014386c:
  addi r3, r3, 1;
  addi r4, r4, 0x180;
  bdnz lbl_80143800;
  mr r3, r30;
  bl L2CA_Deregister;
lbl_80143880:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: gap_config_ind
// PAL: 0x80143898..0x801439d4
MARK_BINARY_BLOB(gap_config_ind, 0x80143898, 0x801439d4);
asm UNKNOWN_FUNCTION(gap_config_ind) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r5, 0x8034;
  li r6, 0;
  stw r0, 0x14(r1);
  li r0, 2;
  addi r5, r5, -30144;
  stw r31, 0xc(r1);
  addi r31, r5, 0xac;
  mtctr r0;
lbl_801438c0:
  lbz r0, 0(r31);
  cmpwi r0, 0;
  beq lbl_801438dc;
  lhz r0, 6(r31);
  cmplw r0, r3;
  bne lbl_801438dc;
  b lbl_8014394c;
lbl_801438dc:
  lbzu r0, 0x60(r31);
  addi r6, r6, 1;
  cmpwi r0, 0;
  beq lbl_801438fc;
  lhz r0, 6(r31);
  cmplw r0, r3;
  bne lbl_801438fc;
  b lbl_8014394c;
lbl_801438fc:
  lbzu r0, 0x60(r31);
  addi r6, r6, 1;
  cmpwi r0, 0;
  beq lbl_8014391c;
  lhz r0, 6(r31);
  cmplw r0, r3;
  bne lbl_8014391c;
  b lbl_8014394c;
lbl_8014391c:
  lbzu r0, 0x60(r31);
  addi r6, r6, 1;
  cmpwi r0, 0;
  beq lbl_8014393c;
  lhz r0, 6(r31);
  cmplw r0, r3;
  bne lbl_8014393c;
  b lbl_8014394c;
lbl_8014393c:
  addi r6, r6, 1;
  addi r31, r31, 0x60;
  bdnz lbl_801438c0;
  li r31, 0;
lbl_8014394c:
  cmpwi r31, 0;
  beq lbl_801439c0;
  lbz r0, 2(r4);
  cmpwi r0, 0;
  beq lbl_8014396c;
  lhz r0, 4(r4);
  cmplwi r0, 0x69b;
  ble lbl_80143978;
lbl_8014396c:
  li r0, 0x69b;
  sth r0, 0x12(r31);
  b lbl_8014397c;
lbl_80143978:
  sth r0, 0x12(r31);
lbl_8014397c:
  li r0, 0;
  stb r0, 0x20(r4);
  stb r0, 2(r4);
  sth r0, 0(r4);
  bl L2CA_ConfigRsp;
  lbz r0, 1(r31);
  ori r3, r0, 2;
  rlwinm. r0, r3, 0, 0x1d, 0x1d;
  stb r3, 1(r31);
  beq lbl_801439c0;
  li r0, 4;
  li r4, 0x100;
  stb r0, 0(r31);
  lwz r12, 0x20(r31);
  lhz r3, 4(r31);
  mtctr r12;
  bctrl;
lbl_801439c0:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: gap_config_cfm
// PAL: 0x801439d4..0x80143bc0
MARK_BINARY_BLOB(gap_config_cfm, 0x801439d4, 0x80143bc0);
asm UNKNOWN_FUNCTION(gap_config_cfm) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r5, 0x8034;
  li r6, 0;
  stw r0, 0x14(r1);
  li r0, 2;
  addi r5, r5, -30144;
  stw r31, 0xc(r1);
  addi r31, r5, 0xac;
  stw r30, 8(r1);
  mtctr r0;
lbl_80143a00:
  lbz r0, 0(r31);
  cmpwi r0, 0;
  beq lbl_80143a1c;
  lhz r0, 6(r31);
  cmplw r0, r3;
  bne lbl_80143a1c;
  b lbl_80143a8c;
lbl_80143a1c:
  lbzu r0, 0x60(r31);
  addi r6, r6, 1;
  cmpwi r0, 0;
  beq lbl_80143a3c;
  lhz r0, 6(r31);
  cmplw r0, r3;
  bne lbl_80143a3c;
  b lbl_80143a8c;
lbl_80143a3c:
  lbzu r0, 0x60(r31);
  addi r6, r6, 1;
  cmpwi r0, 0;
  beq lbl_80143a5c;
  lhz r0, 6(r31);
  cmplw r0, r3;
  bne lbl_80143a5c;
  b lbl_80143a8c;
lbl_80143a5c:
  lbzu r0, 0x60(r31);
  addi r6, r6, 1;
  cmpwi r0, 0;
  beq lbl_80143a7c;
  lhz r0, 6(r31);
  cmplw r0, r3;
  bne lbl_80143a7c;
  b lbl_80143a8c;
lbl_80143a7c:
  addi r6, r6, 1;
  addi r31, r31, 0x60;
  bdnz lbl_80143a00;
  li r31, 0;
lbl_80143a8c:
  cmpwi r31, 0;
  beq lbl_80143ba8;
  lhz r0, 0(r4);
  cmpwi r0, 0;
  bne lbl_80143ad4;
  lbz r0, 1(r31);
  ori r3, r0, 4;
  rlwinm. r0, r3, 0, 0x1e, 0x1e;
  stb r3, 1(r31);
  beq lbl_80143ba8;
  li r0, 4;
  li r4, 0x100;
  stb r0, 0(r31);
  lwz r12, 0x20(r31);
  lhz r3, 4(r31);
  mtctr r12;
  bctrl;
  b lbl_80143ba8;
lbl_80143ad4:
  lwz r12, 0x20(r31);
  li r4, 0x101;
  lhz r3, 4(r31);
  mtctr r12;
  bctrl;
  lhz r30, 0x10(r31);
  b lbl_80143afc;
lbl_80143af0:
  addi r3, r31, 0x14;
  bl GKI_dequeue;
  bl GKI_freebuf;
lbl_80143afc:
  lwz r0, 0x14(r31);
  cmpwi r0, 0;
  bne lbl_80143af0;
  lis r3, 0x8034;
  li r4, 0;
  addi r3, r3, -30144;
  li r0, 2;
  stb r4, 0(r31);
  addi r4, r3, 0xac;
  li r3, 0;
  mtctr r0;
lbl_80143b28:
  lbz r0, 0(r4);
  cmpwi r0, 0;
  beq lbl_80143b40;
  lhz r0, 0x10(r4);
  cmplw r0, r30;
  beq lbl_80143ba8;
lbl_80143b40:
  lbz r0, 0x60(r4);
  addi r3, r3, 1;
  cmpwi r0, 0;
  beq lbl_80143b5c;
  lhz r0, 0x70(r4);
  cmplw r0, r30;
  beq lbl_80143ba8;
lbl_80143b5c:
  lbz r0, 0xc0(r4);
  addi r3, r3, 1;
  cmpwi r0, 0;
  beq lbl_80143b78;
  lhz r0, 0xd0(r4);
  cmplw r0, r30;
  beq lbl_80143ba8;
lbl_80143b78:
  lbz r0, 0x120(r4);
  addi r3, r3, 1;
  cmpwi r0, 0;
  beq lbl_80143b94;
  lhz r0, 0x130(r4);
  cmplw r0, r30;
  beq lbl_80143ba8;
lbl_80143b94:
  addi r3, r3, 1;
  addi r4, r4, 0x180;
  bdnz lbl_80143b28;
  mr r3, r30;
  bl L2CA_Deregister;
lbl_80143ba8:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: gap_disconnect_ind
// PAL: 0x80143bc0..0x80143db8
MARK_BINARY_BLOB(gap_disconnect_ind, 0x80143bc0, 0x80143db8);
asm UNKNOWN_FUNCTION(gap_disconnect_ind) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  lis r5, 0x8034;
  stw r0, 0x24(r1);
  addi r5, r5, -30144;
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  mr r30, r4;
  stw r29, 0x14(r1);
  mr r29, r3;
  lbz r0, 0x28(r5);
  cmplwi r0, 4;
  blt lbl_80143c0c;
  lis r3, 0xe;
  lis r4, 0x8028;
  mr r5, r29;
  addi r3, r3, 3;
  addi r4, r4, 0x4c00;
  bl LogMsg_1;
lbl_80143c0c:
  lis r3, 0x8034;
  li r0, 2;
  addi r3, r3, -30144;
  li r4, 0;
  addi r31, r3, 0xac;
  mtctr r0;
lbl_80143c24:
  lbz r0, 0(r31);
  cmpwi r0, 0;
  beq lbl_80143c40;
  lhz r0, 6(r31);
  cmplw r0, r29;
  bne lbl_80143c40;
  b lbl_80143cb0;
lbl_80143c40:
  lbzu r0, 0x60(r31);
  addi r4, r4, 1;
  cmpwi r0, 0;
  beq lbl_80143c60;
  lhz r0, 6(r31);
  cmplw r0, r29;
  bne lbl_80143c60;
  b lbl_80143cb0;
lbl_80143c60:
  lbzu r0, 0x60(r31);
  addi r4, r4, 1;
  cmpwi r0, 0;
  beq lbl_80143c80;
  lhz r0, 6(r31);
  cmplw r0, r29;
  bne lbl_80143c80;
  b lbl_80143cb0;
lbl_80143c80:
  lbzu r0, 0x60(r31);
  addi r4, r4, 1;
  cmpwi r0, 0;
  beq lbl_80143ca0;
  lhz r0, 6(r31);
  cmplw r0, r29;
  bne lbl_80143ca0;
  b lbl_80143cb0;
lbl_80143ca0:
  addi r4, r4, 1;
  addi r31, r31, 0x60;
  bdnz lbl_80143c24;
  li r31, 0;
lbl_80143cb0:
  cmpwi r31, 0;
  beq lbl_80143d9c;
  cmpwi r30, 0;
  beq lbl_80143cc8;
  mr r3, r29;
  bl L2CA_DisconnectRsp;
lbl_80143cc8:
  lwz r12, 0x20(r31);
  li r4, 0x101;
  lhz r3, 4(r31);
  mtctr r12;
  bctrl;
  lhz r30, 0x10(r31);
  b lbl_80143cf0;
lbl_80143ce4:
  addi r3, r31, 0x14;
  bl GKI_dequeue;
  bl GKI_freebuf;
lbl_80143cf0:
  lwz r0, 0x14(r31);
  cmpwi r0, 0;
  bne lbl_80143ce4;
  lis r3, 0x8034;
  li r4, 0;
  addi r3, r3, -30144;
  li r0, 2;
  stb r4, 0(r31);
  addi r4, r3, 0xac;
  li r3, 0;
  mtctr r0;
lbl_80143d1c:
  lbz r0, 0(r4);
  cmpwi r0, 0;
  beq lbl_80143d34;
  lhz r0, 0x10(r4);
  cmplw r0, r30;
  beq lbl_80143d9c;
lbl_80143d34:
  lbz r0, 0x60(r4);
  addi r3, r3, 1;
  cmpwi r0, 0;
  beq lbl_80143d50;
  lhz r0, 0x70(r4);
  cmplw r0, r30;
  beq lbl_80143d9c;
lbl_80143d50:
  lbz r0, 0xc0(r4);
  addi r3, r3, 1;
  cmpwi r0, 0;
  beq lbl_80143d6c;
  lhz r0, 0xd0(r4);
  cmplw r0, r30;
  beq lbl_80143d9c;
lbl_80143d6c:
  lbz r0, 0x120(r4);
  addi r3, r3, 1;
  cmpwi r0, 0;
  beq lbl_80143d88;
  lhz r0, 0x130(r4);
  cmplw r0, r30;
  beq lbl_80143d9c;
lbl_80143d88:
  addi r3, r3, 1;
  addi r4, r4, 0x180;
  bdnz lbl_80143d1c;
  mr r3, r30;
  bl L2CA_Deregister;
lbl_80143d9c:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: gap_data_ind
// PAL: 0x80143db8..0x80143ec8
MARK_BINARY_BLOB(gap_data_ind, 0x80143db8, 0x80143ec8);
asm UNKNOWN_FUNCTION(gap_data_ind) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r5, 0x8034;
  stw r0, 0x14(r1);
  li r0, 2;
  addi r5, r5, -30144;
  stw r31, 0xc(r1);
  addi r31, r5, 0xac;
  li r5, 0;
  mtctr r0;
lbl_80143de0:
  lbz r0, 0(r31);
  cmpwi r0, 0;
  beq lbl_80143dfc;
  lhz r0, 6(r31);
  cmplw r0, r3;
  bne lbl_80143dfc;
  b lbl_80143e6c;
lbl_80143dfc:
  lbzu r0, 0x60(r31);
  addi r5, r5, 1;
  cmpwi r0, 0;
  beq lbl_80143e1c;
  lhz r0, 6(r31);
  cmplw r0, r3;
  bne lbl_80143e1c;
  b lbl_80143e6c;
lbl_80143e1c:
  lbzu r0, 0x60(r31);
  addi r5, r5, 1;
  cmpwi r0, 0;
  beq lbl_80143e3c;
  lhz r0, 6(r31);
  cmplw r0, r3;
  bne lbl_80143e3c;
  b lbl_80143e6c;
lbl_80143e3c:
  lbzu r0, 0x60(r31);
  addi r5, r5, 1;
  cmpwi r0, 0;
  beq lbl_80143e5c;
  lhz r0, 6(r31);
  cmplw r0, r3;
  bne lbl_80143e5c;
  b lbl_80143e6c;
lbl_80143e5c:
  addi r5, r5, 1;
  addi r31, r31, 0x60;
  bdnz lbl_80143de0;
  li r31, 0;
lbl_80143e6c:
  cmpwi r31, 0;
  bne lbl_80143e80;
  mr r3, r4;
  bl GKI_freebuf;
  b lbl_80143eb4;
lbl_80143e80:
  lbz r0, 0(r31);
  cmplwi r0, 4;
  bne lbl_80143eac;
  addi r3, r31, 0x14;
  bl GKI_enqueue;
  lwz r12, 0x20(r31);
  li r4, 0x102;
  lhz r3, 4(r31);
  mtctr r12;
  bctrl;
  b lbl_80143eb4;
lbl_80143eac:
  mr r3, r4;
  bl GKI_freebuf;
lbl_80143eb4:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: gap_congestion_ind
// PAL: 0x80143ec8..0x80143ffc
MARK_BINARY_BLOB(gap_congestion_ind, 0x80143ec8, 0x80143ffc);
asm UNKNOWN_FUNCTION(gap_congestion_ind) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r5, 0x8034;
  stw r0, 0x14(r1);
  addi r5, r5, -30144;
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  lbz r0, 0x28(r5);
  cmplwi r0, 4;
  blt lbl_80143f14;
  lis r3, 0xe;
  lis r4, 0x8028;
  mr r5, r31;
  mr r6, r30;
  addi r3, r3, 3;
  addi r4, r4, 0x4c28;
  bl LogMsg_2;
lbl_80143f14:
  lis r3, 0x8034;
  li r0, 2;
  addi r3, r3, -30144;
  li r4, 0;
  addi r3, r3, 0xac;
  mtctr r0;
lbl_80143f2c:
  lbz r0, 0(r3);
  cmpwi r0, 0;
  beq lbl_80143f48;
  lhz r0, 6(r3);
  cmplw r0, r30;
  bne lbl_80143f48;
  b lbl_80143fb8;
lbl_80143f48:
  lbzu r0, 0x60(r3);
  addi r4, r4, 1;
  cmpwi r0, 0;
  beq lbl_80143f68;
  lhz r0, 6(r3);
  cmplw r0, r30;
  bne lbl_80143f68;
  b lbl_80143fb8;
lbl_80143f68:
  lbzu r0, 0x60(r3);
  addi r4, r4, 1;
  cmpwi r0, 0;
  beq lbl_80143f88;
  lhz r0, 6(r3);
  cmplw r0, r30;
  bne lbl_80143f88;
  b lbl_80143fb8;
lbl_80143f88:
  lbzu r0, 0x60(r3);
  addi r4, r4, 1;
  cmpwi r0, 0;
  beq lbl_80143fa8;
  lhz r0, 6(r3);
  cmplw r0, r30;
  bne lbl_80143fa8;
  b lbl_80143fb8;
lbl_80143fa8:
  addi r4, r4, 1;
  addi r3, r3, 0x60;
  bdnz lbl_80143f2c;
  li r3, 0;
lbl_80143fb8:
  cmpwi r3, 0;
  beq lbl_80143fe4;
  neg r0, r31;
  lwz r12, 0x20(r3);
  or r0, r0, r31;
  lhz r3, 4(r3);
  srawi r4, r0, 0x1f;
  addi r0, r4, 0x104;
  clrlwi r4, r0, 0x10;
  mtctr r12;
  bctrl;
lbl_80143fe4:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

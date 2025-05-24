#include "rfc_mx_fsm.h"

#include <string.h>

#include "gki_buffer.h"
#include "bte_logmsg.h"
#include "l2c_api.h"
#include "port_rfc.h"
#include "rfc_l2cap_if.h"
#include "rfc_ts_frames.h"
#include "rfc_utils.h"

// Symbol: rfc_mx_sm_execute
// PAL: 0x801524e0..0x80152524
MARK_BINARY_BLOB(rfc_mx_sm_execute, 0x801524e0, 0x80152524);
asm UNKNOWN_FUNCTION(rfc_mx_sm_execute) {
  // clang-format off
  nofralloc;
  lbz r0, 0x6c(r3);
  cmplwi r0, 6;
  bgtlr;
  lis r6, 0x8028;
  slwi r0, r0, 2;
  addi r6, r6, 0x7078;
  lwzx r6, r6, r0;
  mtctr r6;
  bctr;
  b rfc_mx_sm_state_idle;
  b rfc_mx_sm_state_wait_conn_cnf;
  b rfc_mx_sm_state_configure;
  b rfc_mx_sm_sabme_wait_ua;
  b rfc_mx_sm_state_wait_sabme;
  b rfc_mx_sm_state_connected;
  b rfc_mx_sm_state_disc_wait_ua;
  blr;
  // clang-format on
}

// Symbol: rfc_mx_sm_state_idle
// PAL: 0x80152524..0x80152738
MARK_BINARY_BLOB(rfc_mx_sm_state_idle, 0x80152524, 0x80152738);
asm UNKNOWN_FUNCTION(rfc_mx_sm_state_idle) {
  // clang-format off
  nofralloc;
  stwu r1, -0x60(r1);
  mflr r0;
  lis r6, 0x8034;
  stw r0, 0x64(r1);
  addi r6, r6, -25816;
  stw r31, 0x5c(r1);
  mr r31, r3;
  stw r30, 0x58(r1);
  lis r30, 0x8028;
  addi r30, r30, 0x7078;
  stw r29, 0x54(r1);
  mr r29, r5;
  stw r28, 0x50(r1);
  mr r28, r4;
  lbz r0, 0x414(r6);
  cmplwi r0, 4;
  blt lbl_8015257c;
  lis r3, 9;
  mr r5, r28;
  addi r3, r3, 3;
  addi r4, r30, 0x1c;
  bl LogMsg_1;
lbl_8015257c:
  cmplwi r28, 0xc;
  bgt lbl_801526ec;
  lis r3, 0x8028;
  slwi r0, r28, 2;
  addi r3, r3, 0x7110;
  lwzx r3, r3, r0;
  mtctr r3;
  bctr;
  li r0, 0x29a;
  addi r4, r31, 0x62;
  sth r0, 0x6a(r31);
  li r3, 3;
  bl L2CA_ConnectReq;
  clrlwi. r4, r3, 0x10;
  sth r3, 0x68(r31);
  bne lbl_801525cc;
  mr r3, r31;
  li r4, 1;
  bl PORT_StartCnf;
  b lbl_80152718;
lbl_801525cc:
  mr r3, r31;
  bl rfc_save_lcid_mcb;
  li r0, 1;
  stb r0, 0x6c(r31);
  b lbl_80152718;
  lis r3, 0x8034;
  addi r3, r3, -25816;
  lbz r0, 0x414(r3);
  cmplwi r0, 1;
  blt lbl_80152718;
  lbz r5, 0x6c(r31);
  mr r6, r28;
  addi r4, r30, 0x3c;
  lis r3, 9;
  bl LogMsg_2;
  b lbl_80152718;
  lbz r0, 0x6d(r31);
  cmpwi r0, 0;
  beq lbl_80152634;
  lbz r4, 0(r29);
  addi r3, r31, 0x62;
  lhz r5, 0x68(r31);
  li r6, 1;
  li r7, 0;
  bl L2CA_ConnectRsp;
  b lbl_80152718;
lbl_80152634:
  mr r3, r31;
  li r4, 0x78;
  bl rfc_timer_start;
  lbz r4, 0(r29);
  addi r3, r31, 0x62;
  lhz r5, 0x68(r31);
  li r6, 0;
  li r7, 0;
  bl L2CA_ConnectRsp;
  lis r3, 0x8034;
  addi r3, r3, -25816;
  lbz r0, 0x414(r3);
  cmplwi r0, 4;
  blt lbl_8015267c;
  lis r3, 9;
  addi r4, r30, 0x58;
  addi r3, r3, 3;
  bl LogMsg_0;
lbl_8015267c:
  addi r3, r1, 8;
  li r4, 0;
  li r5, 0x3c;
  bl memset;
  li r0, 0;
  li r4, 1;
  li r3, 0x69b;
  stb r4, 0xa(r1);
  addi r4, r1, 8;
  sth r3, 0xc(r1);
  stb r0, 0x28(r1);
  stb r0, 0xe(r1);
  lhz r3, 0x68(r31);
  bl L2CA_ConfigReq;
  li r0, 2;
  stb r0, 0x6c(r31);
  b lbl_80152718;
  b lbl_80152718;
  mr r3, r31;
  li r4, 0;
  li r5, 1;
  bl rfc_send_dm;
  b lbl_80152718;
  mr r3, r31;
  li r4, 0;
  li r5, 0;
  bl rfc_send_dm;
  b lbl_80152718;
lbl_801526ec:
  lis r3, 0x8034;
  addi r3, r3, -25816;
  lbz r0, 0x414(r3);
  cmplwi r0, 4;
  blt lbl_80152718;
  lis r3, 9;
  lbz r6, 0x6c(r31);
  mr r5, r28;
  addi r4, r30, 0x70;
  addi r3, r3, 3;
  bl LogMsg_2;
lbl_80152718:
  lwz r0, 0x64(r1);
  lwz r31, 0x5c(r1);
  lwz r30, 0x58(r1);
  lwz r29, 0x54(r1);
  lwz r28, 0x50(r1);
  mtlr r0;
  addi r1, r1, 0x60;
  blr;
  // clang-format on
}

// Symbol: rfc_mx_sm_state_wait_conn_cnf
// PAL: 0x80152738..0x801528f4
MARK_BINARY_BLOB(rfc_mx_sm_state_wait_conn_cnf, 0x80152738, 0x801528f4);
asm UNKNOWN_FUNCTION(rfc_mx_sm_state_wait_conn_cnf) {
  // clang-format off
  nofralloc;
  stwu r1, -0x60(r1);
  mflr r0;
  lis r6, 0x8034;
  stw r0, 0x64(r1);
  addi r6, r6, -25816;
  stw r31, 0x5c(r1);
  mr r31, r3;
  stw r30, 0x58(r1);
  lis r30, 0x8028;
  addi r30, r30, 0x7078;
  stw r29, 0x54(r1);
  mr r29, r5;
  stw r28, 0x50(r1);
  mr r28, r4;
  lbz r0, 0x414(r6);
  cmplwi r0, 4;
  blt lbl_80152790;
  lis r3, 9;
  mr r5, r28;
  addi r3, r3, 3;
  addi r4, r30, 0xcc;
  bl LogMsg_1;
lbl_80152790:
  cmpwi r28, 9;
  beq lbl_801527ec;
  bge lbl_801527b4;
  cmpwi r28, 6;
  beq lbl_801527c0;
  bge lbl_801528a8;
  cmpwi r28, 5;
  bge lbl_8015288c;
  b lbl_801528a8;
lbl_801527b4:
  cmpwi r28, 0xe;
  beq lbl_80152878;
  b lbl_801528a8;
lbl_801527c0:
  lis r3, 0x8034;
  addi r3, r3, -25816;
  lbz r0, 0x414(r3);
  cmplwi r0, 1;
  blt lbl_801528d4;
  lbz r5, 0x6c(r31);
  mr r6, r28;
  addi r4, r30, 0x3c;
  lis r3, 9;
  bl LogMsg_2;
  b lbl_801528d4;
lbl_801527ec:
  lhz r0, 0(r29);
  cmpwi r0, 0;
  beq lbl_80152810;
  li r0, 0;
  mr r3, r31;
  stb r0, 0x6c(r31);
  lhz r4, 0(r29);
  bl PORT_StartCnf;
  b lbl_801528d4;
lbl_80152810:
  li r0, 2;
  lis r3, 0x8034;
  stb r0, 0x6c(r31);
  addi r3, r3, -25816;
  lbz r0, 0x414(r3);
  cmplwi r0, 4;
  blt lbl_8015283c;
  lis r3, 9;
  addi r4, r30, 0x58;
  addi r3, r3, 3;
  bl LogMsg_0;
lbl_8015283c:
  addi r3, r1, 8;
  li r4, 0;
  li r5, 0x3c;
  bl memset;
  li r0, 0;
  li r4, 1;
  li r3, 0x69b;
  stb r4, 0xa(r1);
  addi r4, r1, 8;
  sth r3, 0xc(r1);
  stb r0, 0x28(r1);
  stb r0, 0xe(r1);
  lhz r3, 0x68(r31);
  bl L2CA_ConfigReq;
  b lbl_801528d4;
lbl_80152878:
  li r0, 0;
  mr r3, r31;
  stb r0, 0x6c(r31);
  bl PORT_CloseInd;
  b lbl_801528d4;
lbl_8015288c:
  li r0, 0;
  lhz r3, 0x68(r31);
  stb r0, 0x6c(r31);
  bl L2CA_DisconnectReq;
  mr r3, r31;
  bl PORT_CloseInd;
  b lbl_801528d4;
lbl_801528a8:
  lis r3, 0x8034;
  addi r3, r3, -25816;
  lbz r0, 0x414(r3);
  cmplwi r0, 4;
  blt lbl_801528d4;
  lis r3, 9;
  lbz r6, 0x6c(r31);
  mr r5, r28;
  addi r4, r30, 0x70;
  addi r3, r3, 3;
  bl LogMsg_2;
lbl_801528d4:
  lwz r0, 0x64(r1);
  lwz r31, 0x5c(r1);
  lwz r30, 0x58(r1);
  lwz r29, 0x54(r1);
  lwz r28, 0x50(r1);
  mtlr r0;
  addi r1, r1, 0x60;
  blr;
  // clang-format on
}

// Symbol: rfc_mx_sm_state_configure
// PAL: 0x801528f4..0x80152a1c
MARK_BINARY_BLOB(rfc_mx_sm_state_configure, 0x801528f4, 0x80152a1c);
asm UNKNOWN_FUNCTION(rfc_mx_sm_state_configure) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  lis r6, 0x8034;
  stw r0, 0x24(r1);
  addi r6, r6, -25816;
  stw r31, 0x1c(r1);
  lis r31, 0x8028;
  addi r31, r31, 0x7078;
  stw r30, 0x18(r1);
  mr r30, r5;
  stw r29, 0x14(r1);
  mr r29, r4;
  stw r28, 0x10(r1);
  mr r28, r3;
  lbz r0, 0x414(r6);
  cmplwi r0, 4;
  blt lbl_8015294c;
  lis r3, 9;
  mr r5, r29;
  addi r3, r3, 3;
  addi r4, r31, 0xf4;
  bl LogMsg_1;
lbl_8015294c:
  addi r0, r29, -6;
  cmplwi r0, 8;
  bgt lbl_801529d0;
  lis r3, 0x8028;
  slwi r0, r0, 2;
  addi r3, r3, 0x7190;
  lwzx r3, r3, r0;
  mtctr r3;
  bctr;
  lis r3, 0x8034;
  addi r3, r3, -25816;
  lbz r0, 0x414(r3);
  cmplwi r0, 1;
  blt lbl_801529fc;
  lbz r5, 0x6c(r28);
  mr r6, r29;
  addi r4, r31, 0x3c;
  lis r3, 9;
  bl LogMsg_2;
  b lbl_801529fc;
  mr r3, r28;
  mr r4, r30;
  bl rfc_mx_conf_ind;
  b lbl_801529fc;
  mr r3, r28;
  mr r4, r30;
  bl rfc_mx_conf_cnf;
  b lbl_801529fc;
  li r0, 0;
  mr r3, r28;
  stb r0, 0x6c(r28);
  bl PORT_CloseInd;
  b lbl_801529fc;
lbl_801529d0:
  lis r3, 0x8034;
  addi r3, r3, -25816;
  lbz r0, 0x414(r3);
  cmplwi r0, 4;
  blt lbl_801529fc;
  lis r3, 9;
  lbz r6, 0x6c(r28);
  mr r5, r29;
  addi r4, r31, 0x70;
  addi r3, r3, 3;
  bl LogMsg_2;
lbl_801529fc:
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

// Symbol: rfc_mx_sm_sabme_wait_ua
// PAL: 0x80152a1c..0x80152b90
MARK_BINARY_BLOB(rfc_mx_sm_sabme_wait_ua, 0x80152a1c, 0x80152b90);
asm UNKNOWN_FUNCTION(rfc_mx_sm_sabme_wait_ua) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  lis r6, 0x8034;
  stw r0, 0x24(r1);
  addi r6, r6, -25816;
  stw r31, 0x1c(r1);
  mr r31, r3;
  stw r30, 0x18(r1);
  lis r30, 0x8028;
  addi r30, r30, 0x7078;
  stw r29, 0x14(r1);
  mr r29, r5;
  stw r28, 0x10(r1);
  mr r28, r4;
  lbz r0, 0x414(r6);
  cmplwi r0, 4;
  blt lbl_80152a74;
  lis r3, 9;
  mr r5, r28;
  addi r3, r3, 3;
  addi r4, r30, 0x13c;
  bl LogMsg_1;
lbl_80152a74:
  cmplwi r28, 0xe;
  bgt lbl_80152b44;
  lis r3, 0x8028;
  slwi r0, r28, 2;
  addi r3, r3, 0x71d8;
  lwzx r3, r3, r0;
  mtctr r3;
  bctr;
  lis r3, 0x8034;
  addi r3, r3, -25816;
  lbz r0, 0x414(r3);
  cmplwi r0, 1;
  blt lbl_80152b70;
  lbz r5, 0x6c(r31);
  mr r6, r28;
  addi r4, r30, 0x3c;
  lis r3, 9;
  bl LogMsg_2;
  b lbl_80152b70;
  mr r3, r31;
  mr r4, r29;
  bl rfc_mx_conf_ind;
  b lbl_80152b70;
  mr r3, r31;
  mr r4, r29;
  bl rfc_mx_conf_cnf;
  b lbl_80152b70;
  li r0, 0;
  mr r3, r31;
  stb r0, 0x6c(r31);
  bl PORT_CloseInd;
  b lbl_80152b70;
  mr r3, r31;
  bl rfc_timer_stop;
  li r3, 5;
  li r0, 1;
  stb r3, 0x6c(r31);
  mr r3, r31;
  li r4, 0;
  stb r0, 0x71(r31);
  bl PORT_StartCnf;
  b lbl_80152b70;
  mr r3, r31;
  bl rfc_timer_stop;
  li r0, 0;
  lhz r3, 0x68(r31);
  stb r0, 0x6c(r31);
  bl L2CA_DisconnectReq;
  mr r3, r31;
  li r4, 1;
  bl PORT_StartCnf;
  b lbl_80152b70;
lbl_80152b44:
  lis r3, 0x8034;
  addi r3, r3, -25816;
  lbz r0, 0x414(r3);
  cmplwi r0, 4;
  blt lbl_80152b70;
  lis r3, 9;
  lbz r6, 0x6c(r31);
  mr r5, r28;
  addi r4, r30, 0x70;
  addi r3, r3, 3;
  bl LogMsg_2;
lbl_80152b70:
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

// Symbol: rfc_mx_sm_state_wait_sabme
// PAL: 0x80152b90..0x80152cb0
MARK_BINARY_BLOB(rfc_mx_sm_state_wait_sabme, 0x80152b90, 0x80152cb0);
asm UNKNOWN_FUNCTION(rfc_mx_sm_state_wait_sabme) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  lis r6, 0x8034;
  stw r0, 0x24(r1);
  addi r6, r6, -25816;
  stw r31, 0x1c(r1);
  mr r31, r5;
  stw r30, 0x18(r1);
  mr r30, r4;
  stw r29, 0x14(r1);
  mr r29, r3;
  lbz r0, 0x414(r6);
  cmplwi r0, 4;
  blt lbl_80152be0;
  lis r3, 9;
  lis r4, 0x8028;
  mr r5, r30;
  addi r3, r3, 3;
  addi r4, r4, 0x7214;
  bl LogMsg_1;
lbl_80152be0:
  cmpwi r30, 7;
  beq lbl_80152c24;
  bge lbl_80152bf8;
  cmpwi r30, 0;
  beq lbl_80152c18;
  b lbl_80152c64;
lbl_80152bf8:
  cmpwi r30, 0xe;
  beq lbl_80152c04;
  b lbl_80152c64;
lbl_80152c04:
  li r0, 0;
  mr r3, r29;
  stb r0, 0x6c(r29);
  bl PORT_CloseInd;
  b lbl_80152c94;
lbl_80152c18:
  mr r3, r29;
  bl PORT_StartInd;
  b lbl_80152c94;
lbl_80152c24:
  lhz r0, 0(r31);
  cmpwi r0, 0;
  beq lbl_80152c44;
  mr r3, r29;
  li r4, 0;
  li r5, 1;
  bl rfc_send_dm;
  b lbl_80152c94;
lbl_80152c44:
  mr r3, r29;
  li r4, 0;
  bl rfc_send_ua;
  li r3, 5;
  li r0, 1;
  stb r3, 0x6c(r29);
  stb r0, 0x71(r29);
  b lbl_80152c94;
lbl_80152c64:
  lis r3, 0x8034;
  addi r3, r3, -25816;
  lbz r0, 0x414(r3);
  cmplwi r0, 4;
  blt lbl_80152c94;
  lis r3, 9;
  lis r4, 0x8028;
  lbz r6, 0x6c(r29);
  mr r5, r30;
  addi r3, r3, 3;
  addi r4, r4, 0x70e8;
  bl LogMsg_2;
lbl_80152c94:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: rfc_mx_sm_state_connected
// PAL: 0x80152cb0..0x80152dc8
MARK_BINARY_BLOB(rfc_mx_sm_state_connected, 0x80152cb0, 0x80152dc8);
asm UNKNOWN_FUNCTION(rfc_mx_sm_state_connected) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r5, 0x8034;
  stw r0, 0x14(r1);
  addi r5, r5, -25816;
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  lbz r0, 0x414(r5);
  cmplwi r0, 4;
  blt lbl_80152cf8;
  lis r3, 9;
  lis r4, 0x8028;
  mr r5, r31;
  addi r3, r3, 3;
  addi r4, r4, 0x7238;
  bl LogMsg_1;
lbl_80152cf8:
  addi r0, r31, -3;
  cmplwi r0, 0xb;
  bgt lbl_80152d80;
  lis r3, 0x8028;
  slwi r0, r0, 2;
  addi r3, r3, 0x725c;
  lwzx r3, r3, r0;
  mtctr r3;
  bctr;
  mr r3, r30;
  li r4, 3;
  bl rfc_timer_start;
  li r0, 6;
  mr r3, r30;
  stb r0, 0x6c(r30);
  li r4, 0;
  bl rfc_send_disc;
  b lbl_80152db0;
  li r0, 0;
  mr r3, r30;
  stb r0, 0x6c(r30);
  bl PORT_CloseInd;
  b lbl_80152db0;
  mr r3, r30;
  li r4, 0;
  bl rfc_send_ua;
  lbz r0, 0x6d(r30);
  cmpwi r0, 0;
  beq lbl_80152d74;
  lhz r3, 0x68(r30);
  bl L2CA_DisconnectReq;
lbl_80152d74:
  mr r3, r30;
  bl PORT_CloseInd;
  b lbl_80152db0;
lbl_80152d80:
  lis r3, 0x8034;
  addi r3, r3, -25816;
  lbz r0, 0x414(r3);
  cmplwi r0, 4;
  blt lbl_80152db0;
  lis r3, 9;
  lis r4, 0x8028;
  lbz r6, 0x6c(r30);
  mr r5, r31;
  addi r3, r3, 3;
  addi r4, r4, 0x70e8;
  bl LogMsg_2;
lbl_80152db0:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: rfc_mx_sm_state_disc_wait_ua
// PAL: 0x80152dc8..0x80152f40
MARK_BINARY_BLOB(rfc_mx_sm_state_disc_wait_ua, 0x80152dc8, 0x80152f40);
asm UNKNOWN_FUNCTION(rfc_mx_sm_state_disc_wait_ua) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  lis r6, 0x8034;
  stw r0, 0x24(r1);
  addi r6, r6, -25816;
  stw r31, 0x1c(r1);
  mr r31, r5;
  stw r30, 0x18(r1);
  mr r30, r4;
  stw r29, 0x14(r1);
  mr r29, r3;
  lbz r0, 0x414(r6);
  cmplwi r0, 4;
  blt lbl_80152e18;
  lis r3, 9;
  lis r4, 0x8028;
  mr r5, r30;
  addi r3, r3, 3;
  addi r4, r4, 0x728c;
  bl LogMsg_1;
lbl_80152e18:
  cmplwi r30, 0xe;
  bgt lbl_80152ef4;
  lis r3, 0x8028;
  slwi r0, r30, 2;
  addi r3, r3, 0x72b4;
  lwzx r3, r3, r0;
  mtctr r3;
  bctr;
  lhz r3, 0x68(r29);
  bl L2CA_DisconnectReq;
  lbz r0, 0x70(r29);
  cmpwi r0, 0;
  beq lbl_80152e98;
  addi r4, r29, 0x62;
  li r3, 3;
  bl L2CA_ConnectReq;
  clrlwi. r4, r3, 0x10;
  sth r3, 0x68(r29);
  bne lbl_80152e74;
  mr r3, r29;
  li r4, 1;
  bl PORT_StartCnf;
  b lbl_80152f24;
lbl_80152e74:
  mr r3, r29;
  bl rfc_save_lcid_mcb;
  li r3, 0;
  li r0, 1;
  stb r3, 0x70(r29);
  stb r3, 0x6e(r29);
  stb r3, 0x6f(r29);
  stb r0, 0x6c(r29);
  b lbl_80152f24;
lbl_80152e98:
  mr r3, r29;
  bl rfc_release_multiplexer_channel;
  b lbl_80152f24;
  mr r3, r29;
  li r4, 0;
  bl rfc_send_ua;
  b lbl_80152f24;
  mr r3, r31;
  bl GKI_freebuf;
  mr r3, r29;
  li r4, 0;
  li r5, 0;
  bl rfc_send_dm;
  b lbl_80152f24;
  li r0, 1;
  stb r0, 0x70(r29);
  b lbl_80152f24;
  li r0, 0;
  mr r3, r29;
  stb r0, 0x6c(r29);
  bl PORT_CloseInd;
  b lbl_80152f24;
  b lbl_80152f24;
lbl_80152ef4:
  lis r3, 0x8034;
  addi r3, r3, -25816;
  lbz r0, 0x414(r3);
  cmplwi r0, 4;
  blt lbl_80152f24;
  lis r3, 9;
  lis r4, 0x8028;
  lbz r6, 0x6c(r29);
  mr r5, r30;
  addi r3, r3, 3;
  addi r4, r4, 0x70e8;
  bl LogMsg_2;
lbl_80152f24:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: rfc_mx_conf_cnf
// PAL: 0x80152f40..0x80153034
MARK_BINARY_BLOB(rfc_mx_conf_cnf, 0x80152f40, 0x80153034);
asm UNKNOWN_FUNCTION(rfc_mx_conf_cnf) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r5, 0x8034;
  stw r0, 0x14(r1);
  addi r5, r5, -25816;
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  lbz r0, 0x414(r5);
  cmplwi r0, 4;
  blt lbl_80152f9c;
  cmpwi r31, 0;
  lis r3, 9;
  lis r4, 0x8028;
  mr r5, r31;
  addi r3, r3, 3;
  addi r4, r4, 0x72f0;
  beq lbl_80152f94;
  lhz r6, 0(r31);
  b lbl_80152f98;
lbl_80152f94:
  li r6, 0;
lbl_80152f98:
  bl LogMsg_2;
lbl_80152f9c:
  lhz r4, 0(r31);
  cmpwi r4, 0;
  beq lbl_80152fd0;
  lbz r0, 0x6d(r30);
  cmpwi r0, 0;
  beq lbl_80152fc4;
  mr r3, r30;
  bl PORT_StartCnf;
  lhz r3, 0x68(r30);
  bl L2CA_DisconnectReq;
lbl_80152fc4:
  mr r3, r30;
  bl rfc_release_multiplexer_channel;
  b lbl_8015301c;
lbl_80152fd0:
  lbz r0, 0x6c(r30);
  li r3, 1;
  stb r3, 0x6e(r30);
  cmplwi r0, 2;
  bne lbl_8015301c;
  lbz r0, 0x6f(r30);
  cmpwi r0, 0;
  beq lbl_8015301c;
  lbz r0, 0x6d(r30);
  cmpwi r0, 0;
  beq lbl_80153014;
  li r0, 3;
  mr r3, r30;
  stb r0, 0x6c(r30);
  li r4, 0;
  bl rfc_send_sabme;
  b lbl_8015301c;
lbl_80153014:
  li r0, 4;
  stb r0, 0x6c(r30);
lbl_8015301c:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: rfc_mx_conf_ind
// PAL: 0x80153034..0x80153124
MARK_BINARY_BLOB(rfc_mx_conf_ind, 0x80153034, 0x80153124);
asm UNKNOWN_FUNCTION(rfc_mx_conf_ind) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r5, 0x8034;
  stw r0, 0x14(r1);
  addi r5, r5, -25816;
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  lbz r0, 0x414(r5);
  cmplwi r0, 4;
  blt lbl_8015307c;
  lis r3, 9;
  lis r4, 0x8028;
  mr r5, r31;
  addi r3, r3, 3;
  addi r4, r4, 0x7314;
  bl LogMsg_1;
lbl_8015307c:
  lbz r0, 2(r31);
  cmpwi r0, 0;
  beq lbl_80153098;
  lhz r3, 4(r31);
  addi r0, r3, -6;
  sth r0, 0x6a(r30);
  b lbl_801530a0;
lbl_80153098:
  li r0, 0x29a;
  sth r0, 0x6a(r30);
lbl_801530a0:
  li r0, 0;
  mr r4, r31;
  stb r0, 2(r31);
  stb r0, 0x20(r31);
  stb r0, 6(r31);
  sth r0, 0(r31);
  lhz r3, 0x68(r30);
  bl L2CA_ConfigRsp;
  lbz r0, 0x6c(r30);
  li r3, 1;
  stb r3, 0x6f(r30);
  cmplwi r0, 2;
  bne lbl_8015310c;
  lbz r0, 0x6e(r30);
  cmpwi r0, 0;
  beq lbl_8015310c;
  lbz r0, 0x6d(r30);
  cmpwi r0, 0;
  beq lbl_80153104;
  li r0, 3;
  mr r3, r30;
  stb r0, 0x6c(r30);
  li r4, 0;
  bl rfc_send_sabme;
  b lbl_8015310c;
lbl_80153104:
  li r0, 4;
  stb r0, 0x6c(r30);
lbl_8015310c:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

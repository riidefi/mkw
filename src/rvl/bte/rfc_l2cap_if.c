#include "rfc_l2cap_if.h"

#include "gki_buffer.h"
#include "bte_logmsg.h"
#include "l2c_api.h"
#include "port_utils.h"

#include "rfc_mx_fsm.h"
#include "rfc_port_fsm.h"
#include "rfc_ts_frames.h"
#include "rfc_utils.h"

// Symbol: rfcomm_l2cap_if_init
// PAL: 0x80151bac..0x80151c28
MARK_BINARY_BLOB(rfcomm_l2cap_if_init, 0x80151bac, 0x80151c28);
asm UNKNOWN_FUNCTION(rfcomm_l2cap_if_init) {
  // clang-format off
  nofralloc;
  lis r3, 0x8015;
  lis r4, 0x8034;
  addi r3, r3, 0x1c28;
  lis r11, 0x8015;
  addi r4, r4, -25816;
  lis r10, 0x8015;
  lis r9, 0x8015;
  lis r8, 0x8015;
  lis r7, 0x8015;
  lis r6, 0x8015;
  lis r5, 0x8015;
  stwu r3, 0x14(r4);
  li r0, 0;
  addi r11, r11, 0x1cb4;
  addi r10, r10, 0x1db8;
  addi r9, r9, 0x1ec0;
  addi r8, r8, 0x1fcc;
  addi r7, r7, 0x1fc8;
  addi r6, r6, 0x20f0;
  addi r5, r5, 0x2390;
  stw r11, 4(r4);
  li r3, 3;
  stw r0, 8(r4);
  stw r10, 0xc(r4);
  stw r9, 0x10(r4);
  stw r8, 0x14(r4);
  stw r0, 0x18(r4);
  stw r7, 0x1c(r4);
  stw r6, 0x20(r4);
  stw r5, 0x24(r4);
  b L2CA_Register;
  // clang-format on
}

// Symbol: RFCOMM_ConnectInd
// PAL: 0x80151c28..0x80151cb4
MARK_BINARY_BLOB(RFCOMM_ConnectInd, 0x80151c28, 0x80151cb4);
asm UNKNOWN_FUNCTION(RFCOMM_ConnectInd) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r4;
  li r4, 0;
  stw r30, 0x18(r1);
  mr r30, r3;
  stb r6, 8(r1);
  bl rfc_alloc_multiplexer_channel;
  addi r0, r31, -64;
  lis r4, 0x8034;
  addi r4, r4, -25816;
  cmpwi r3, 0;
  slwi r0, r0, 2;
  add r4, r4, r0;
  stw r3, 0x3c(r4);
  bne lbl_80151c8c;
  lbz r4, 8(r1);
  mr r3, r30;
  mr r5, r31;
  li r6, 4;
  li r7, 0;
  bl L2CA_ConnectRsp;
  b lbl_80151c9c;
lbl_80151c8c:
  sth r31, 0x68(r3);
  addi r5, r1, 8;
  li r4, 0xa;
  bl rfc_mx_sm_execute;
lbl_80151c9c:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: RFCOMM_ConnectCnf
// PAL: 0x80151cb4..0x80151db8
MARK_BINARY_BLOB(RFCOMM_ConnectCnf, 0x80151cb4, 0x80151db8);
asm UNKNOWN_FUNCTION(RFCOMM_ConnectCnf) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r0, r3, -64;
  cmpwi r0, 0xa;
  stw r31, 0x1c(r1);
  lis r31, 0x8028;
  addi r31, r31, 0x6f38;
  stw r30, 0x18(r1);
  mr r30, r3;
  sth r4, 8(r1);
  blt lbl_80151d10;
  lis r3, 0x8034;
  addi r3, r3, -25816;
  lbz r0, 0x414(r3);
  cmplwi r0, 1;
  blt lbl_80151d08;
  mr r5, r30;
  addi r4, r31, 0;
  lis r3, 9;
  bl LogMsg_1;
lbl_80151d08:
  li r4, 0;
  b lbl_80151d5c;
lbl_80151d10:
  lis r5, 0x8034;
  slwi r0, r0, 2;
  addi r5, r5, -25816;
  add r4, r5, r0;
  lwz r4, 0x3c(r4);
  cmpwi r4, 0;
  beq lbl_80151d5c;
  lhz r6, 0x68(r4);
  cmplw r6, r3;
  beq lbl_80151d5c;
  lbz r0, 0x414(r5);
  cmplwi r0, 2;
  blt lbl_80151d58;
  lis r3, 9;
  mr r5, r30;
  addi r4, r31, 0x1c;
  addi r3, r3, 1;
  bl LogMsg_2;
lbl_80151d58:
  li r4, 0;
lbl_80151d5c:
  cmpwi r4, 0;
  bne lbl_80151d8c;
  lis r3, 0x8034;
  addi r3, r3, -25816;
  lbz r0, 0x414(r3);
  cmplwi r0, 1;
  blt lbl_80151da0;
  mr r5, r30;
  addi r4, r31, 0x54;
  lis r3, 9;
  bl LogMsg_1;
  b lbl_80151da0;
lbl_80151d8c:
  sth r30, 0x68(r4);
  mr r3, r4;
  addi r5, r1, 8;
  li r4, 9;
  bl rfc_mx_sm_execute;
lbl_80151da0:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: RFCOMM_ConfigInd
// PAL: 0x80151db8..0x80151ec0
MARK_BINARY_BLOB(RFCOMM_ConfigInd, 0x80151db8, 0x80151ec0);
asm UNKNOWN_FUNCTION(RFCOMM_ConfigInd) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r0, r3, -64;
  cmpwi r0, 0xa;
  stw r31, 0x1c(r1);
  lis r31, 0x8028;
  addi r31, r31, 0x6f38;
  stw r30, 0x18(r1);
  mr r30, r4;
  stw r29, 0x14(r1);
  mr r29, r3;
  blt lbl_80151e18;
  lis r3, 0x8034;
  addi r3, r3, -25816;
  lbz r0, 0x414(r3);
  cmplwi r0, 1;
  blt lbl_80151e10;
  mr r5, r29;
  addi r4, r31, 0;
  lis r3, 9;
  bl LogMsg_1;
lbl_80151e10:
  li r4, 0;
  b lbl_80151e64;
lbl_80151e18:
  lis r5, 0x8034;
  slwi r0, r0, 2;
  addi r5, r5, -25816;
  add r4, r5, r0;
  lwz r4, 0x3c(r4);
  cmpwi r4, 0;
  beq lbl_80151e64;
  lhz r6, 0x68(r4);
  cmplw r6, r3;
  beq lbl_80151e64;
  lbz r0, 0x414(r5);
  cmplwi r0, 2;
  blt lbl_80151e60;
  lis r3, 9;
  mr r5, r29;
  addi r4, r31, 0x1c;
  addi r3, r3, 1;
  bl LogMsg_2;
lbl_80151e60:
  li r4, 0;
lbl_80151e64:
  cmpwi r4, 0;
  bne lbl_80151e94;
  lis r3, 0x8034;
  addi r3, r3, -25816;
  lbz r0, 0x414(r3);
  cmplwi r0, 1;
  blt lbl_80151ea4;
  mr r5, r29;
  addi r4, r31, 0x70;
  lis r3, 9;
  bl LogMsg_1;
  b lbl_80151ea4;
lbl_80151e94:
  mr r3, r4;
  mr r5, r30;
  li r4, 0xc;
  bl rfc_mx_sm_execute;
lbl_80151ea4:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: RFCOMM_ConfigCnf
// PAL: 0x80151ec0..0x80151fc8
MARK_BINARY_BLOB(RFCOMM_ConfigCnf, 0x80151ec0, 0x80151fc8);
asm UNKNOWN_FUNCTION(RFCOMM_ConfigCnf) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r0, r3, -64;
  cmpwi r0, 0xa;
  stw r31, 0x1c(r1);
  lis r31, 0x8028;
  addi r31, r31, 0x6f38;
  stw r30, 0x18(r1);
  mr r30, r4;
  stw r29, 0x14(r1);
  mr r29, r3;
  blt lbl_80151f20;
  lis r3, 0x8034;
  addi r3, r3, -25816;
  lbz r0, 0x414(r3);
  cmplwi r0, 1;
  blt lbl_80151f18;
  mr r5, r29;
  addi r4, r31, 0;
  lis r3, 9;
  bl LogMsg_1;
lbl_80151f18:
  li r4, 0;
  b lbl_80151f6c;
lbl_80151f20:
  lis r5, 0x8034;
  slwi r0, r0, 2;
  addi r5, r5, -25816;
  add r4, r5, r0;
  lwz r4, 0x3c(r4);
  cmpwi r4, 0;
  beq lbl_80151f6c;
  lhz r6, 0x68(r4);
  cmplw r6, r3;
  beq lbl_80151f6c;
  lbz r0, 0x414(r5);
  cmplwi r0, 2;
  blt lbl_80151f68;
  lis r3, 9;
  mr r5, r29;
  addi r4, r31, 0x1c;
  addi r3, r3, 1;
  bl LogMsg_2;
lbl_80151f68:
  li r4, 0;
lbl_80151f6c:
  cmpwi r4, 0;
  bne lbl_80151f9c;
  lis r3, 0x8034;
  addi r3, r3, -25816;
  lbz r0, 0x414(r3);
  cmplwi r0, 1;
  blt lbl_80151fac;
  mr r5, r29;
  addi r4, r31, 0x8c;
  lis r3, 9;
  bl LogMsg_1;
  b lbl_80151fac;
lbl_80151f9c:
  mr r3, r4;
  mr r5, r30;
  li r4, 0xb;
  bl rfc_mx_sm_execute;
lbl_80151fac:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: RFCOMM_QoSViolationInd
// PAL: 0x80151fc8..0x80151fcc
MARK_BINARY_BLOB(RFCOMM_QoSViolationInd, 0x80151fc8, 0x80151fcc);
asm UNKNOWN_FUNCTION(RFCOMM_QoSViolationInd) {
  // clang-format off
  nofralloc;
  blr;
  // clang-format on
}

// Symbol: RFCOMM_DisconnectInd
// PAL: 0x80151fcc..0x801520f0
MARK_BINARY_BLOB(RFCOMM_DisconnectInd, 0x80151fcc, 0x801520f0);
asm UNKNOWN_FUNCTION(RFCOMM_DisconnectInd) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r0, r3, -64;
  cmpwi r0, 0xa;
  stw r31, 0x1c(r1);
  lis r31, 0x8028;
  addi r31, r31, 0x6f38;
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  mr r29, r4;
  stw r28, 0x10(r1);
  mr r28, r3;
  blt lbl_80152030;
  lis r3, 0x8034;
  addi r3, r3, -25816;
  lbz r0, 0x414(r3);
  cmplwi r0, 1;
  blt lbl_80152028;
  mr r5, r28;
  addi r4, r31, 0;
  lis r3, 9;
  bl LogMsg_1;
lbl_80152028:
  li r30, 0;
  b lbl_8015207c;
lbl_80152030:
  lis r5, 0x8034;
  slwi r0, r0, 2;
  addi r5, r5, -25816;
  add r4, r5, r0;
  lwz r30, 0x3c(r4);
  cmpwi r30, 0;
  beq lbl_8015207c;
  lhz r6, 0x68(r30);
  cmplw r6, r3;
  beq lbl_8015207c;
  lbz r0, 0x414(r5);
  cmplwi r0, 2;
  blt lbl_80152078;
  lis r3, 9;
  mr r5, r28;
  addi r4, r31, 0x1c;
  addi r3, r3, 1;
  bl LogMsg_2;
lbl_80152078:
  li r30, 0;
lbl_8015207c:
  cmpwi r29, 0;
  beq lbl_8015208c;
  mr r3, r28;
  bl L2CA_DisconnectRsp;
lbl_8015208c:
  cmpwi r30, 0;
  bne lbl_801520c0;
  lis r3, 0x8034;
  addi r3, r3, -25816;
  lbz r0, 0x414(r3);
  cmplwi r0, 2;
  blt lbl_801520d0;
  lis r3, 9;
  mr r5, r28;
  addi r3, r3, 1;
  addi r4, r31, 0xa8;
  bl LogMsg_1;
  b lbl_801520d0;
lbl_801520c0:
  mr r3, r30;
  li r4, 0xe;
  li r5, 0;
  bl rfc_mx_sm_execute;
lbl_801520d0:
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

// Symbol: RFCOMM_BufDataInd
// PAL: 0x801520f0..0x80152390
MARK_BINARY_BLOB(RFCOMM_BufDataInd, 0x801520f0, 0x80152390);
asm UNKNOWN_FUNCTION(RFCOMM_BufDataInd) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_27;
  addi r0, r3, -64;
  lis r29, 0x8028;
  cmpwi r0, 0xa;
  mr r27, r3;
  mr r31, r4;
  addi r29, r29, 0x6f38;
  blt lbl_8015214c;
  lis r3, 0x8034;
  addi r3, r3, -25816;
  lbz r0, 0x414(r3);
  cmplwi r0, 1;
  blt lbl_80152144;
  mr r5, r27;
  addi r4, r29, 0;
  lis r3, 9;
  bl LogMsg_1;
lbl_80152144:
  li r28, 0;
  b lbl_80152198;
lbl_8015214c:
  lis r5, 0x8034;
  slwi r0, r0, 2;
  addi r5, r5, -25816;
  add r4, r5, r0;
  lwz r28, 0x3c(r4);
  cmpwi r28, 0;
  beq lbl_80152198;
  lhz r6, 0x68(r28);
  cmplw r6, r3;
  beq lbl_80152198;
  lbz r0, 0x414(r5);
  cmplwi r0, 2;
  blt lbl_80152194;
  lis r3, 9;
  mr r5, r27;
  addi r4, r29, 0x1c;
  addi r3, r3, 1;
  bl LogMsg_2;
lbl_80152194:
  li r28, 0;
lbl_80152198:
  cmpwi r28, 0;
  bne lbl_801521d4;
  lis r3, 0x8034;
  addi r3, r3, -25816;
  lbz r0, 0x414(r3);
  cmplwi r0, 2;
  blt lbl_801521c8;
  lis r3, 9;
  mr r5, r27;
  addi r3, r3, 1;
  addi r4, r29, 0xc8;
  bl LogMsg_1;
lbl_801521c8:
  mr r3, r31;
  bl GKI_freebuf;
  b lbl_80152378;
lbl_801521d4:
  lis r30, 0x8034;
  mr r3, r28;
  mr r5, r31;
  addi r4, r30, -25816;
  bl rfc_parse_data;
  clrlwi r4, r3, 0x18;
  mr r29, r3;
  cmplwi r4, 0x32;
  bne lbl_80152204;
  mr r3, r31;
  bl GKI_freebuf;
  b lbl_80152378;
lbl_80152204:
  lbz r0, -0x64d8(r30);
  cmpwi r0, 0;
  bne lbl_80152240;
  cmplwi r4, 4;
  bne lbl_80152228;
  mr r3, r28;
  mr r4, r31;
  bl rfc_process_mx_message;
  b lbl_80152378;
lbl_80152228:
  mr r3, r28;
  li r5, 0;
  bl rfc_mx_sm_execute;
  mr r3, r31;
  bl GKI_freebuf;
  b lbl_80152378;
lbl_80152240:
  mr r3, r28;
  mr r4, r0;
  bl port_find_mcb_dlci_port;
  cmpwi r3, 0;
  mr r27, r3;
  beq lbl_80152264;
  lwz r0, 0x6c(r3);
  cmpwi r0, 0;
  bne lbl_80152314;
lbl_80152264:
  clrlwi. r0, r29, 0x18;
  beq lbl_801522cc;
  lbz r4, 0x6d(r28);
  cmpwi r4, 0;
  beq lbl_8015228c;
  lis r3, 0x8034;
  addi r3, r3, -25816;
  lbz r0, 2(r3);
  cmpwi r0, 0;
  beq lbl_801522a8;
lbl_8015228c:
  cmpwi r4, 0;
  bne lbl_801522c0;
  lis r3, 0x8034;
  addi r3, r3, -25816;
  lbz r0, 2(r3);
  cmpwi r0, 0;
  beq lbl_801522c0;
lbl_801522a8:
  lis r4, 0x8034;
  mr r3, r28;
  addi r5, r4, -25816;
  lbz r4, -0x64d8(r4);
  lbz r5, 4(r5);
  bl rfc_send_dm;
lbl_801522c0:
  mr r3, r31;
  bl GKI_freebuf;
  b lbl_80152378;
lbl_801522cc:
  lis r30, 0x8034;
  lbz r3, -0x64d8(r30);
  bl port_find_dlci_port;
  cmpwi r3, 0;
  mr r27, r3;
  bne lbl_80152300;
  lbz r4, -0x64d8(r30);
  mr r3, r28;
  li r5, 1;
  bl rfc_send_dm;
  mr r3, r31;
  bl GKI_freebuf;
  b lbl_80152378;
lbl_80152300:
  lbz r0, -0x64d8(r30);
  lbz r5, 0(r3);
  add r4, r28, r0;
  stb r5, 0x24(r4);
  stw r28, 0x6c(r3);
lbl_80152314:
  clrlwi r4, r29, 0x18;
  cmplwi r4, 4;
  bne lbl_80152364;
  lhz r0, 2(r31);
  cmpwi r0, 0;
  beq lbl_8015233c;
  mr r3, r27;
  mr r5, r31;
  bl rfc_port_sm_execute;
  b lbl_80152344;
lbl_8015233c:
  mr r3, r31;
  bl GKI_freebuf;
lbl_80152344:
  lis r3, 0x8034;
  addi r3, r3, -25816;
  lbz r4, 5(r3);
  cmpwi r4, 0;
  beq lbl_80152378;
  mr r3, r27;
  bl rfc_inc_credit;
  b lbl_80152378;
lbl_80152364:
  mr r3, r27;
  li r5, 0;
  bl rfc_port_sm_execute;
  mr r3, r31;
  bl GKI_freebuf;
lbl_80152378:
  addi r11, r1, 0x20;
  bl _restgpr_27;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: RFCOMM_CongestionStatusInd
// PAL: 0x80152390..0x801524c4
MARK_BINARY_BLOB(RFCOMM_CongestionStatusInd, 0x80152390, 0x801524c4);
asm UNKNOWN_FUNCTION(RFCOMM_CongestionStatusInd) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r0, r3, -64;
  cmpwi r0, 0xa;
  stw r31, 0x1c(r1);
  lis r31, 0x8028;
  addi r31, r31, 0x6f38;
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  mr r29, r4;
  stw r28, 0x10(r1);
  mr r28, r3;
  blt lbl_801523f4;
  lis r3, 0x8034;
  addi r3, r3, -25816;
  lbz r0, 0x414(r3);
  cmplwi r0, 1;
  blt lbl_801523ec;
  mr r5, r28;
  addi r4, r31, 0;
  lis r3, 9;
  bl LogMsg_1;
lbl_801523ec:
  li r30, 0;
  b lbl_80152440;
lbl_801523f4:
  lis r5, 0x8034;
  slwi r0, r0, 2;
  addi r5, r5, -25816;
  add r4, r5, r0;
  lwz r30, 0x3c(r4);
  cmpwi r30, 0;
  beq lbl_80152440;
  lhz r6, 0x68(r30);
  cmplw r6, r3;
  beq lbl_80152440;
  lbz r0, 0x414(r5);
  cmplwi r0, 2;
  blt lbl_8015243c;
  lis r3, 9;
  mr r5, r28;
  addi r4, r31, 0x1c;
  addi r3, r3, 1;
  bl LogMsg_2;
lbl_8015243c:
  li r30, 0;
lbl_80152440:
  cmpwi r30, 0;
  bne lbl_80152470;
  lis r3, 0x8034;
  addi r3, r3, -25816;
  lbz r0, 0x414(r3);
  cmplwi r0, 1;
  blt lbl_801524a4;
  mr r5, r28;
  addi r4, r31, 0xe4;
  lis r3, 9;
  bl LogMsg_1;
  b lbl_801524a4;
lbl_80152470:
  lis r3, 0x8034;
  addi r3, r3, -25816;
  lbz r0, 0x414(r3);
  cmplwi r0, 4;
  blt lbl_80152498;
  lis r3, 9;
  mr r5, r28;
  addi r3, r3, 3;
  addi r4, r31, 0x114;
  bl LogMsg_1;
lbl_80152498:
  mr r3, r30;
  mr r4, r29;
  bl rfc_process_l2cap_congestion;
lbl_801524a4:
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

// Symbol: rfc_save_lcid_mcb
// PAL: 0x801524c4..0x801524e0
MARK_BINARY_BLOB(rfc_save_lcid_mcb, 0x801524c4, 0x801524e0);
asm UNKNOWN_FUNCTION(rfc_save_lcid_mcb) {
  // clang-format off
  nofralloc;
  addi r0, r4, -64;
  lis r4, 0x8034;
  addi r4, r4, -25816;
  slwi r0, r0, 2;
  add r4, r4, r0;
  stw r3, 0x3c(r4);
  blr;
  // clang-format on
}

#include "rfc_port_if.h"

#include "port_rfc.h"
#include "port_utils.h"
#include "rfc_mx_fsm.h"
#include "rfc_port_fsm.h"
#include "rfc_ts_frames.h"
#include "rfc_utils.h"

// Symbol: RFCOMM_StartRsp
// PAL: 0x801542c4..0x801542f0
MARK_BINARY_BLOB(RFCOMM_StartRsp, 0x801542c4, 0x801542f0);
asm UNKNOWN_FUNCTION(RFCOMM_StartRsp) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  addi r5, r1, 8;
  sth r4, 8(r1);
  li r4, 7;
  bl rfc_mx_sm_execute;
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: RFCOMM_DlcEstablishReq
// PAL: 0x801542f0..0x80154358
MARK_BINARY_BLOB(RFCOMM_DlcEstablishReq, 0x801542f0, 0x80154358);
asm UNKNOWN_FUNCTION(RFCOMM_DlcEstablishReq) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  bl port_find_mcb_dlci_port;
  lbz r0, 0x6c(r30);
  cmplwi r0, 5;
  beq lbl_80154334;
  mr r3, r30;
  mr r4, r31;
  li r5, 0;
  li r6, 1;
  bl PORT_DlcEstablishCnf;
  b lbl_80154340;
lbl_80154334:
  li r4, 9;
  li r5, 0;
  bl rfc_port_sm_execute;
lbl_80154340:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: RFCOMM_DlcEstablishRsp
// PAL: 0x80154358..0x801543c8
MARK_BINARY_BLOB(RFCOMM_DlcEstablishRsp, 0x80154358, 0x801543c8);
asm UNKNOWN_FUNCTION(RFCOMM_DlcEstablishRsp) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r4;
  stw r30, 0x18(r1);
  mr r30, r3;
  sth r6, 8(r1);
  bl port_find_mcb_dlci_port;
  lbz r0, 0x6c(r30);
  cmplwi r0, 5;
  beq lbl_801543a4;
  lhz r0, 8(r1);
  cmpwi r0, 0;
  bne lbl_801543a4;
  mr r3, r30;
  mr r4, r31;
  bl PORT_DlcReleaseInd;
  b lbl_801543b0;
lbl_801543a4:
  addi r5, r1, 8;
  li r4, 0xb;
  bl rfc_port_sm_execute;
lbl_801543b0:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: RFCOMM_ParNegReq
// PAL: 0x801543c8..0x801544a8
MARK_BINARY_BLOB(RFCOMM_ParNegReq, 0x801543c8, 0x801544a8);
asm UNKNOWN_FUNCTION(RFCOMM_ParNegReq) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  mr r30, r5;
  stw r29, 0x14(r1);
  mr r29, r4;
  stw r28, 0x10(r1);
  mr r28, r3;
  bl port_find_mcb_dlci_port;
  lbz r0, 0x6c(r28);
  mr r31, r3;
  cmplwi r0, 5;
  beq lbl_80154410;
  li r0, 0xd;
  stb r0, 0xe(r3);
  b lbl_80154488;
lbl_80154410:
  lbz r4, 0x72(r28);
  li r0, 2;
  cmpwi r4, 0;
  beq lbl_80154424;
  mr r0, r4;
lbl_80154424:
  clrlwi r0, r0, 0x18;
  cmplwi r0, 2;
  bne lbl_80154454;
  lhz r4, 0x9c(r3);
  li r7, 0xf0;
  li r0, 7;
  cmplwi r4, 7;
  bge lbl_80154448;
  mr r0, r4;
lbl_80154448:
  clrlwi r8, r0, 0x18;
  sth r8, 0x9a(r3);
  b lbl_8015445c;
lbl_80154454:
  li r7, 0;
  li r8, 0;
lbl_8015445c:
  lbz r0, 0x69(r3);
  mr r4, r29;
  mr r6, r30;
  li r5, 1;
  ori r0, r0, 1;
  stb r0, 0x69(r3);
  mr r3, r28;
  bl rfc_send_pn;
  mr r3, r31;
  li r4, 0x3c;
  bl rfc_port_timer_start;
lbl_80154488:
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

// Symbol: RFCOMM_ParNegRsp
// PAL: 0x801544a8..0x801544d0
MARK_BINARY_BLOB(RFCOMM_ParNegRsp, 0x801544a8, 0x801544d0);
asm UNKNOWN_FUNCTION(RFCOMM_ParNegRsp) {
  // clang-format off
  nofralloc;
  lbz r0, 0x6c(r3);
  mr r9, r6;
  mr r8, r7;
  cmplwi r0, 5;
  bnelr;
  mr r6, r5;
  mr r7, r9;
  li r5, 0;
  b rfc_send_pn;
  blr;
  // clang-format on
}

// Symbol: RFCOMM_PortNegReq
// PAL: 0x801544d0..0x8015458c
MARK_BINARY_BLOB(RFCOMM_PortNegReq, 0x801544d0, 0x8015458c);
asm UNKNOWN_FUNCTION(RFCOMM_PortNegReq) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  mr r30, r5;
  stw r29, 0x14(r1);
  mr r29, r4;
  stw r28, 0x10(r1);
  mr r28, r3;
  bl port_find_mcb_dlci_port;
  lbz r0, 0x6c(r28);
  mr r31, r3;
  cmplwi r0, 5;
  beq lbl_80154524;
  mr r3, r28;
  mr r4, r29;
  li r5, 0;
  li r6, 1;
  bl PORT_PortNegCnf;
  b lbl_8015456c;
lbl_80154524:
  cmpwi r30, 0;
  bne lbl_8015453c;
  lbz r0, 0x69(r3);
  ori r0, r0, 2;
  stb r0, 0x69(r3);
  b lbl_80154548;
lbl_8015453c:
  lbz r0, 0x69(r3);
  ori r0, r0, 4;
  stb r0, 0x69(r3);
lbl_80154548:
  mr r3, r28;
  mr r4, r29;
  mr r6, r30;
  li r5, 1;
  li r7, 0x3f7f;
  bl rfc_send_rpn;
  mr r3, r31;
  li r4, 0x3c;
  bl rfc_port_timer_start;
lbl_8015456c:
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

// Symbol: RFCOMM_PortNegRsp
// PAL: 0x8015458c..0x801545ac
MARK_BINARY_BLOB(RFCOMM_PortNegRsp, 0x8015458c, 0x801545ac);
asm UNKNOWN_FUNCTION(RFCOMM_PortNegRsp) {
  // clang-format off
  nofralloc;
  lbz r0, 0x6c(r3);
  mr r7, r6;
  cmplwi r0, 5;
  bnelr;
  mr r6, r5;
  li r5, 0;
  b rfc_send_rpn;
  blr;
  // clang-format on
}

// Symbol: RFCOMM_ControlReq
// PAL: 0x801545ac..0x80154650
MARK_BINARY_BLOB(RFCOMM_ControlReq, 0x801545ac, 0x80154650);
asm UNKNOWN_FUNCTION(RFCOMM_ControlReq) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  mr r30, r5;
  stw r29, 0x14(r1);
  mr r29, r4;
  stw r28, 0x10(r1);
  mr r28, r3;
  bl port_find_mcb_dlci_port;
  lbz r0, 2(r3);
  mr r31, r3;
  cmplwi r0, 2;
  bne lbl_80154630;
  lbz r0, 0x68(r3);
  cmplwi r0, 4;
  beq lbl_801545f8;
  b lbl_80154630;
lbl_801545f8:
  lbz r0, 0x64(r3);
  mr r4, r29;
  mr r6, r30;
  li r5, 1;
  ori r0, r0, 1;
  stb r0, 0x64(r3);
  lbz r0, 0x69(r3);
  ori r0, r0, 8;
  stb r0, 0x69(r3);
  mr r3, r28;
  bl rfc_send_msc;
  mr r3, r31;
  li r4, 0x3c;
  bl rfc_port_timer_start;
lbl_80154630:
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

// Symbol: RFCOMM_FlowReq
// PAL: 0x80154650..0x801546f4
MARK_BINARY_BLOB(RFCOMM_FlowReq, 0x80154650, 0x801546f4);
asm UNKNOWN_FUNCTION(RFCOMM_FlowReq) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  mr r30, r5;
  stw r29, 0x14(r1);
  mr r29, r4;
  stw r28, 0x10(r1);
  mr r28, r3;
  bl port_find_mcb_dlci_port;
  lbz r0, 2(r3);
  mr r31, r3;
  cmplwi r0, 2;
  bne lbl_801546d4;
  lbz r0, 0x68(r3);
  cmplwi r0, 4;
  beq lbl_8015469c;
  b lbl_801546d4;
lbl_8015469c:
  cntlzw r0, r30;
  mr r4, r29;
  rlwinm r0, r0, 0x1b, 0x18, 0x1f;
  addi r6, r31, 0x5a;
  stb r0, 0x5e(r3);
  li r5, 1;
  lbz r0, 0x69(r3);
  ori r0, r0, 8;
  stb r0, 0x69(r3);
  mr r3, r28;
  bl rfc_send_msc;
  mr r3, r31;
  li r4, 0x3c;
  bl rfc_port_timer_start;
lbl_801546d4:
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

// Symbol: RFCOMM_LineStatusReq
// PAL: 0x801546f4..0x8015478c
MARK_BINARY_BLOB(RFCOMM_LineStatusReq, 0x801546f4, 0x8015478c);
asm UNKNOWN_FUNCTION(RFCOMM_LineStatusReq) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  mr r30, r5;
  stw r29, 0x14(r1);
  mr r29, r4;
  stw r28, 0x10(r1);
  mr r28, r3;
  bl port_find_mcb_dlci_port;
  lbz r0, 2(r3);
  mr r31, r3;
  cmplwi r0, 2;
  bne lbl_8015476c;
  lbz r0, 0x68(r3);
  cmplwi r0, 4;
  beq lbl_80154740;
  b lbl_8015476c;
lbl_80154740:
  lbz r0, 0x69(r3);
  mr r4, r29;
  mr r6, r30;
  li r5, 1;
  ori r0, r0, 0x10;
  stb r0, 0x69(r3);
  mr r3, r28;
  bl rfc_send_rls;
  mr r3, r31;
  li r4, 0x3c;
  bl rfc_port_timer_start;
lbl_8015476c:
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

// Symbol: RFCOMM_DlcReleaseReq
// PAL: 0x8015478c..0x801547b8
MARK_BINARY_BLOB(RFCOMM_DlcReleaseReq, 0x8015478c, 0x801547b8);
asm UNKNOWN_FUNCTION(RFCOMM_DlcReleaseReq) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  bl port_find_mcb_dlci_port;
  li r4, 0xc;
  li r5, 0;
  bl rfc_port_sm_execute;
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: RFCOMM_DataReq
// PAL: 0x801547b8..0x801547f0
MARK_BINARY_BLOB(RFCOMM_DataReq, 0x801547b8, 0x801547f0);
asm UNKNOWN_FUNCTION(RFCOMM_DataReq) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r5;
  bl port_find_mcb_dlci_port;
  mr r5, r31;
  li r4, 0xe;
  bl rfc_port_sm_execute;
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

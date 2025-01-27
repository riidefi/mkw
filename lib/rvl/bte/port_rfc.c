#include "port_rfc.h"

#include <string.h>

#include "gki_buffer.h"
#include "bte_logmsg.h"
#include "port_utils.h"
#include "rfc_port_if.h"
#include "rfc_ts_frames.h"
#include "rfc_utils.h"

// Symbol: PORT_StartCnf
// PAL: 0x801501d8..0x80150338
MARK_BINARY_BLOB(PORT_StartCnf, 0x801501d8, 0x80150338);
asm UNKNOWN_FUNCTION(PORT_StartCnf) {
  // clang-format off
  nofralloc;
  stwu r1, -0x40(r1);
  mflr r0;
  stw r0, 0x44(r1);
  addi r11, r1, 0x40;
  bl _savegpr_20;
  lis r5, 0x8034;
  mr r29, r3;
  addi r5, r5, -25816;
  mr r30, r4;
  lbz r0, 0x414(r5);
  li r31, 1;
  cmplwi r0, 4;
  blt lbl_80150224;
  lis r3, 9;
  lis r4, 0x8028;
  mr r5, r30;
  addi r3, r3, 3;
  addi r4, r4, 0x6af8;
  bl LogMsg_1;
lbl_80150224:
  lis r22, 0x8034;
  li r20, 0;
  addi r22, r22, -25816;
  lis r23, 9;
  lis r24, 0x8028;
  li r26, 0xc;
  addi r21, r22, 0x68;
  li r25, 0x18;
  lis r28, 1;
  li r27, 0;
lbl_8015024c:
  lwz r0, 0x6c(r21);
  cmplw r0, r29;
  bne lbl_80150300;
  cmpwi r30, 0;
  li r31, 0;
  bne lbl_80150278;
  lbz r4, 0xd(r21);
  mr r3, r29;
  lhz r5, 0x12(r21);
  bl RFCOMM_ParNegReq;
  b lbl_80150300;
lbl_80150278:
  lbz r0, 0x414(r22);
  cmplwi r0, 2;
  blt lbl_80150294;
  mr r5, r30;
  addi r3, r23, 1;
  addi r4, r24, 0x6b10;
  bl LogMsg_1;
lbl_80150294:
  cmplwi r30, 4;
  bne lbl_801502a4;
  stb r25, 0xe(r21);
  b lbl_801502a8;
lbl_801502a4:
  stb r26, 0xe(r21);
lbl_801502a8:
  mr r3, r29;
  bl rfc_release_multiplexer_channel;
  stw r27, 0x6c(r21);
  lwz r12, 0x8c(r21);
  cmpwi r12, 0;
  beq lbl_801502dc;
  lwz r0, 0x88(r21);
  rlwinm. r0, r0, 0, 0x10, 0x10;
  beq lbl_801502dc;
  addi r3, r28, -32768;
  lbz r4, 0(r21);
  mtctr r12;
  bctrl;
lbl_801502dc:
  lwz r12, 0x90(r21);
  cmpwi r12, 0;
  beq lbl_801502f8;
  lbz r4, 0(r21);
  li r3, 0xc;
  mtctr r12;
  bctrl;
lbl_801502f8:
  mr r3, r21;
  bl port_release_port;
lbl_80150300:
  addi r20, r20, 1;
  addi r21, r21, 0xa4;
  cmpwi r20, 5;
  blt lbl_8015024c;
  cmpwi r31, 0;
  beq lbl_80150320;
  mr r3, r29;
  bl rfc_check_mcb_active;
lbl_80150320:
  addi r11, r1, 0x40;
  bl _restgpr_20;
  lwz r0, 0x44(r1);
  mtlr r0;
  addi r1, r1, 0x40;
  blr;
  // clang-format on
}

// Symbol: PORT_StartInd
// PAL: 0x80150338..0x801503d4
MARK_BINARY_BLOB(PORT_StartInd, 0x80150338, 0x801503d4);
asm UNKNOWN_FUNCTION(PORT_StartInd) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r4, 0x8034;
  stw r0, 0x14(r1);
  addi r4, r4, -25816;
  stw r31, 0xc(r1);
  mr r31, r3;
  lbz r0, 0x414(r4);
  cmplwi r0, 4;
  blt lbl_80150374;
  lis r3, 9;
  lis r4, 0x8028;
  addi r3, r3, 3;
  addi r4, r4, 0x6b30;
  bl LogMsg_0;
lbl_80150374:
  lis r3, 0x8034;
  li r0, 5;
  addi r3, r3, -25816;
  addi r3, r3, 0x68;
  mtctr r0;
lbl_80150388:
  lwz r0, 0x6c(r3);
  cmpwi r0, 0;
  beq lbl_8015039c;
  cmplw r0, r31;
  bne lbl_801503ac;
lbl_8015039c:
  mr r3, r31;
  li r4, 0;
  bl RFCOMM_StartRsp;
  b lbl_801503c0;
lbl_801503ac:
  addi r3, r3, 0xa4;
  bdnz lbl_80150388;
  mr r3, r31;
  li r4, 1;
  bl RFCOMM_StartRsp;
lbl_801503c0:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: PORT_ParNegInd
// PAL: 0x801503d4..0x80150584
MARK_BINARY_BLOB(PORT_ParNegInd, 0x801503d4, 0x80150584);
asm UNKNOWN_FUNCTION(PORT_ParNegInd) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_26;
  mr r31, r4;
  mr r30, r3;
  mr r26, r5;
  mr r27, r6;
  mr r28, r7;
  bl port_find_mcb_dlci_port;
  lis r4, 0x8034;
  mr r29, r3;
  addi r4, r4, -25816;
  lbz r0, 0x414(r4);
  cmplwi r0, 4;
  blt lbl_80150434;
  lis r3, 9;
  lis r4, 0x8028;
  mr r5, r31;
  mr r6, r26;
  addi r3, r3, 3;
  addi r4, r4, 0x6b40;
  bl LogMsg_2;
lbl_80150434:
  cmpwi r29, 0;
  bne lbl_801504a0;
  mr r3, r31;
  bl port_find_dlci_port;
  cmpwi r3, 0;
  mr r29, r3;
  bne lbl_80150494;
  mr r3, r30;
  mr r4, r31;
  li r5, 0;
  bl rfc_send_dm;
  mr r3, r30;
  bl rfc_check_mcb_active;
  lis r3, 0x8034;
  addi r3, r3, -25816;
  lbz r0, 0x414(r3);
  cmplwi r0, 4;
  blt lbl_8015056c;
  lis r3, 9;
  lis r4, 0x8028;
  addi r3, r3, 3;
  addi r4, r4, 0x6b60;
  bl LogMsg_0;
  b lbl_8015056c;
lbl_80150494:
  lbz r0, 0(r3);
  add r3, r30, r31;
  stb r0, 0x24(r3);
lbl_801504a0:
  addi r3, r29, 6;
  addi r4, r30, 0x62;
  li r5, 6;
  bl memcpy;
  mr r3, r29;
  bl port_select_mtu;
  stw r30, 0x6c(r29);
  lhz r0, 0x12(r29);
  cmplw r0, r26;
  bge lbl_801504cc;
  mr r26, r0;
lbl_801504cc:
  sth r26, 0x12(r29);
  sth r26, 0x14(r29);
  lbz r0, 0x72(r30);
  cmpwi r0, 0;
  bne lbl_801504fc;
  cmpwi r27, 0;
  bne lbl_801504f4;
  li r0, 1;
  stb r0, 0x72(r30);
  b lbl_801504fc;
lbl_801504f4:
  li r0, 2;
  stb r0, 0x72(r30);
lbl_801504fc:
  cmpwi r27, 0;
  bne lbl_80150510;
  li r6, 0;
  li r7, 0;
  b lbl_8015055c;
lbl_80150510:
  lbz r0, 0x72(r30);
  cmplwi r0, 2;
  bne lbl_80150554;
  cmpwi r28, 0;
  sth r28, 0x98(r29);
  bne lbl_80150530;
  li r0, 1;
  stb r0, 0x24(r29);
lbl_80150530:
  lhz r3, 0x9c(r29);
  li r6, 0xe0;
  li r0, 7;
  cmplwi r3, 7;
  bge lbl_80150548;
  mr r0, r3;
lbl_80150548:
  clrlwi r7, r0, 0x18;
  sth r7, 0x9a(r29);
  b lbl_8015055c;
lbl_80150554:
  li r6, 0;
  li r7, 0;
lbl_8015055c:
  lhz r5, 0x12(r29);
  mr r3, r30;
  mr r4, r31;
  bl RFCOMM_ParNegRsp;
lbl_8015056c:
  addi r11, r1, 0x20;
  bl _restgpr_26;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: PORT_ParNegCnf
// PAL: 0x80150584..0x80150688
MARK_BINARY_BLOB(PORT_ParNegCnf, 0x80150584, 0x80150688);
asm UNKNOWN_FUNCTION(PORT_ParNegCnf) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_26;
  mr r27, r4;
  mr r26, r3;
  mr r28, r5;
  mr r29, r6;
  mr r30, r7;
  bl port_find_mcb_dlci_port;
  lis r4, 0x8034;
  mr r31, r3;
  addi r4, r4, -25816;
  lbz r0, 0x414(r4);
  cmplwi r0, 4;
  blt lbl_801505ec;
  lis r3, 9;
  lis r4, 0x8028;
  mr r5, r27;
  mr r6, r28;
  mr r7, r29;
  mr r8, r30;
  addi r3, r3, 3;
  addi r4, r4, 0x6b80;
  bl LogMsg_4;
lbl_801505ec:
  cmpwi r31, 0;
  beq lbl_80150670;
  lbz r0, 0x72(r26);
  cmpwi r0, 0;
  bne lbl_8015061c;
  cmplwi r29, 0xe0;
  bne lbl_80150614;
  li r0, 2;
  stb r0, 0x72(r26);
  b lbl_8015061c;
lbl_80150614:
  li r0, 1;
  stb r0, 0x72(r26);
lbl_8015061c:
  lhz r0, 0x12(r31);
  cmplw r0, r28;
  bge lbl_8015062c;
  mr r28, r0;
lbl_8015062c:
  sth r28, 0x12(r31);
  sth r28, 0x14(r31);
  lbz r0, 0x72(r26);
  cmplwi r0, 2;
  bne lbl_80150654;
  cmpwi r30, 0;
  sth r30, 0x98(r31);
  bne lbl_80150654;
  li r0, 1;
  stb r0, 0x24(r31);
lbl_80150654:
  lbz r0, 2(r31);
  cmplwi r0, 1;
  bne lbl_80150670;
  lbz r4, 0xd(r31);
  mr r3, r26;
  lhz r5, 0x12(r31);
  bl RFCOMM_DlcEstablishReq;
lbl_80150670:
  addi r11, r1, 0x20;
  bl _restgpr_26;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: PORT_DlcEstablishInd
// PAL: 0x80150688..0x801507c8
MARK_BINARY_BLOB(PORT_DlcEstablishInd, 0x80150688, 0x801507c8);
asm UNKNOWN_FUNCTION(PORT_DlcEstablishInd) {
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
  lis r4, 0x8034;
  mr r31, r3;
  addi r4, r4, -25816;
  lbz r0, 0x414(r4);
  cmplwi r0, 4;
  blt lbl_801506e8;
  lis r3, 9;
  lis r4, 0x8028;
  mr r5, r29;
  mr r6, r30;
  addi r3, r3, 3;
  addi r4, r4, 0x6bac;
  bl LogMsg_2;
lbl_801506e8:
  cmpwi r31, 0;
  bne lbl_80150728;
  mr r3, r29;
  bl port_find_dlci_port;
  cmpwi r3, 0;
  mr r31, r3;
  bne lbl_8015071c;
  mr r3, r28;
  mr r4, r29;
  li r5, 0;
  li r6, 1;
  bl RFCOMM_DlcEstablishRsp;
  b lbl_801507a8;
lbl_8015071c:
  lbz r0, 0(r3);
  add r3, r28, r29;
  stb r0, 0x24(r3);
lbl_80150728:
  cmpwi r30, 0;
  beq lbl_80150740;
  lhz r0, 0x14(r31);
  cmplw r30, r0;
  bge lbl_80150740;
  sth r30, 0x14(r31);
lbl_80150740:
  mr r3, r28;
  bl rfc_timer_stop;
  lhz r5, 0x12(r31);
  mr r3, r28;
  mr r4, r29;
  li r6, 0;
  bl RFCOMM_DlcEstablishRsp;
  lwz r12, 0x8c(r31);
  cmpwi r12, 0;
  beq lbl_80150784;
  lwz r0, 0x88(r31);
  rlwinm. r0, r0, 0, 0x16, 0x16;
  beq lbl_80150784;
  lbz r4, 0(r31);
  li r3, 0x200;
  mtctr r12;
  bctrl;
lbl_80150784:
  lwz r12, 0x90(r31);
  cmpwi r12, 0;
  beq lbl_801507a0;
  lbz r4, 0(r31);
  li r3, 0;
  mtctr r12;
  bctrl;
lbl_801507a0:
  li r0, 2;
  stb r0, 2(r31);
lbl_801507a8:
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

// Symbol: PORT_DlcEstablishCnf
// PAL: 0x801507c8..0x8015090c
MARK_BINARY_BLOB(PORT_DlcEstablishCnf, 0x801507c8, 0x8015090c);
asm UNKNOWN_FUNCTION(PORT_DlcEstablishCnf) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_27;
  mr r28, r4;
  mr r27, r3;
  mr r29, r5;
  mr r30, r6;
  bl port_find_mcb_dlci_port;
  lis r4, 0x8034;
  mr r31, r3;
  addi r4, r4, -25816;
  lbz r0, 0x414(r4);
  cmplwi r0, 4;
  blt lbl_80150828;
  lis r3, 9;
  lis r4, 0x8028;
  mr r5, r28;
  mr r6, r29;
  mr r7, r30;
  addi r3, r3, 3;
  addi r4, r4, 0x6bd0;
  bl LogMsg_3;
lbl_80150828:
  cmpwi r31, 0;
  beq lbl_801508f4;
  cmpwi r30, 0;
  beq lbl_80150850;
  li r0, 0xc;
  mr r3, r31;
  stb r0, 0xe(r31);
  li r4, 0xc;
  bl port_rfc_closed;
  b lbl_801508f4;
lbl_80150850:
  cmpwi r29, 0;
  beq lbl_80150868;
  lhz r0, 0x14(r31);
  cmplw r29, r0;
  bge lbl_80150868;
  sth r29, 0x14(r31);
lbl_80150868:
  mr r3, r27;
  bl rfc_timer_stop;
  lwz r12, 0x8c(r31);
  cmpwi r12, 0;
  beq lbl_80150898;
  lwz r0, 0x88(r31);
  rlwinm. r0, r0, 0, 0x16, 0x16;
  beq lbl_80150898;
  lbz r4, 0(r31);
  li r3, 0x200;
  mtctr r12;
  bctrl;
lbl_80150898:
  lwz r12, 0x90(r31);
  cmpwi r12, 0;
  beq lbl_801508b4;
  lbz r4, 0(r31);
  li r3, 0;
  mtctr r12;
  bctrl;
lbl_801508b4:
  li r0, 2;
  stb r0, 2(r31);
  lhz r0, 4(r31);
  cmplwi r0, 0x1103;
  beq lbl_801508d0;
  cmplwi r0, 0x1111;
  bne lbl_801508e4;
lbl_801508d0:
  lwz r3, 0x6c(r31);
  li r5, 0;
  lbz r4, 0xd(r31);
  bl RFCOMM_PortNegReq;
  b lbl_801508f4;
lbl_801508e4:
  lwz r3, 0x6c(r31);
  addi r5, r31, 0x5a;
  lbz r4, 0xd(r31);
  bl RFCOMM_ControlReq;
lbl_801508f4:
  addi r11, r1, 0x20;
  bl _restgpr_27;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: PORT_PortNegInd
// PAL: 0x8015090c..0x80150a5c
MARK_BINARY_BLOB(PORT_PortNegInd, 0x8015090c, 0x80150a5c);
asm UNKNOWN_FUNCTION(PORT_PortNegInd) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_27;
  mr r27, r4;
  mr r30, r3;
  mr r31, r5;
  mr r28, r6;
  bl port_find_mcb_dlci_port;
  lis r4, 0x8034;
  mr r29, r3;
  addi r4, r4, -25816;
  lbz r0, 0x414(r4);
  cmplwi r0, 4;
  blt lbl_80150960;
  lis r3, 9;
  lis r4, 0x8028;
  addi r3, r3, 3;
  addi r4, r4, 0x6c00;
  bl LogMsg_0;
lbl_80150960:
  cmpwi r29, 0;
  bne lbl_801509e8;
  mr r3, r27;
  bl port_find_dlci_port;
  cmpwi r3, 0;
  mr r29, r3;
  bne lbl_801509dc;
  lbz r7, 0(r31);
  mr r4, r27;
  lbz r0, 1(r31);
  mr r5, r31;
  li r6, 0;
  stb r7, 0x51(r3);
  stb r0, 0x52(r3);
  lbz r7, 2(r31);
  lbz r0, 3(r31);
  stb r7, 0x53(r3);
  stb r0, 0x54(r3);
  lbz r7, 4(r31);
  lbz r0, 5(r31);
  stb r7, 0x55(r3);
  stb r0, 0x56(r3);
  lbz r7, 6(r31);
  lbz r0, 7(r31);
  stb r7, 0x57(r3);
  stb r0, 0x58(r3);
  lbz r0, 8(r31);
  stb r0, 0x59(r3);
  mr r3, r30;
  bl RFCOMM_PortNegRsp;
  b lbl_80150a44;
lbl_801509dc:
  lbz r0, 0(r3);
  add r3, r30, r27;
  stb r0, 0x24(r3);
lbl_801509e8:
  lbz r7, 0(r31);
  mr r3, r30;
  lbz r0, 1(r31);
  mr r4, r27;
  mr r5, r31;
  mr r6, r28;
  stb r7, 0x51(r29);
  stb r0, 0x52(r29);
  lbz r7, 2(r31);
  lbz r0, 3(r31);
  stb r7, 0x53(r29);
  stb r0, 0x54(r29);
  lbz r7, 4(r31);
  lbz r0, 5(r31);
  stb r7, 0x55(r29);
  stb r0, 0x56(r29);
  lbz r7, 6(r31);
  lbz r0, 7(r31);
  stb r7, 0x57(r29);
  stb r0, 0x58(r29);
  lbz r0, 8(r31);
  stb r0, 0x59(r29);
  bl RFCOMM_PortNegRsp;
lbl_80150a44:
  addi r11, r1, 0x20;
  bl _restgpr_27;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: PORT_PortNegCnf
// PAL: 0x80150a5c..0x80150b74
MARK_BINARY_BLOB(PORT_PortNegCnf, 0x80150a5c, 0x80150b74);
asm UNKNOWN_FUNCTION(PORT_PortNegCnf) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  lis r31, 0x8028;
  addi r31, r31, 0x6ac0;
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  mr r29, r6;
  stw r28, 0x10(r1);
  mr r28, r3;
  bl port_find_mcb_dlci_port;
  lis r4, 0x8034;
  mr r30, r3;
  addi r4, r4, -25816;
  lbz r0, 0x414(r4);
  cmplwi r0, 4;
  blt lbl_80150ab4;
  lis r3, 9;
  addi r4, r31, 0x150;
  addi r3, r3, 3;
  bl LogMsg_0;
lbl_80150ab4:
  cmpwi r30, 0;
  bne lbl_80150ae4;
  lis r3, 0x8034;
  addi r3, r3, -25816;
  lbz r0, 0x414(r3);
  cmplwi r0, 2;
  blt lbl_80150b54;
  lis r3, 9;
  addi r4, r31, 0x160;
  addi r3, r3, 1;
  bl LogMsg_0;
  b lbl_80150b54;
lbl_80150ae4:
  cmpwi r29, 0;
  beq lbl_80150b10;
  li r0, 0xe;
  mr r3, r28;
  stb r0, 0xe(r30);
  lbz r4, 0xd(r30);
  bl RFCOMM_DlcReleaseReq;
  mr r3, r30;
  li r4, 0xe;
  bl port_rfc_closed;
  b lbl_80150b54;
lbl_80150b10:
  lbz r0, 0x64(r30);
  clrlwi. r0, r0, 0x1f;
  bne lbl_80150b30;
  lwz r3, 0x6c(r30);
  addi r5, r30, 0x5a;
  lbz r4, 0xd(r30);
  bl RFCOMM_ControlReq;
  b lbl_80150b54;
lbl_80150b30:
  lis r3, 0x8034;
  addi r3, r3, -25816;
  lbz r0, 0x414(r3);
  cmplwi r0, 2;
  blt lbl_80150b54;
  lis r3, 9;
  addi r4, r31, 0x178;
  addi r3, r3, 1;
  bl LogMsg_0;
lbl_80150b54:
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

// Symbol: PORT_ControlInd
// PAL: 0x80150b74..0x80150cec
MARK_BINARY_BLOB(PORT_ControlInd, 0x80150b74, 0x80150cec);
asm UNKNOWN_FUNCTION(PORT_ControlInd) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  mr r30, r5;
  stw r29, 0x14(r1);
  bl port_find_mcb_dlci_port;
  lis r4, 0x8034;
  mr r31, r3;
  addi r4, r4, -25816;
  lbz r0, 0x414(r4);
  cmplwi r0, 4;
  blt lbl_80150bc0;
  lis r3, 9;
  lis r4, 0x8028;
  addi r3, r3, 3;
  addi r4, r4, 0x6c60;
  bl LogMsg_0;
lbl_80150bc0:
  cmpwi r31, 0;
  beq lbl_80150cd0;
  lbz r4, 0x5f(r31);
  mr r3, r31;
  lbz r5, 0(r30);
  bl port_get_signal_changes;
  lbz r0, 0(r30);
  mr r29, r3;
  stb r0, 0x5f(r31);
  lbz r0, 1(r30);
  stb r0, 0x60(r31);
  lbz r0, 2(r30);
  stb r0, 0x61(r31);
  lbz r0, 3(r30);
  stb r0, 0x62(r31);
  lbz r0, 4(r30);
  stb r0, 0x63(r31);
  lbz r4, 0x64(r31);
  clrlwi. r0, r4, 0x1f;
  bne lbl_80150c24;
  lwz r3, 0x6c(r31);
  addi r5, r31, 0x5a;
  lbz r4, 0xd(r31);
  bl RFCOMM_ControlReq;
  b lbl_80150c4c;
lbl_80150c24:
  rlwinm. r0, r4, 0, 0x1d, 0x1d;
  bne lbl_80150c38;
  lwz r0, 0x88(r31);
  rlwinm r0, r0, 0, 0x16, 0x16;
  or r29, r3, r0;
lbl_80150c38:
  rlwinm. r0, r4, 0, 0x1e, 0x1e;
  beq lbl_80150c4c;
  mr r3, r31;
  bl port_rfc_send_tx_data;
  or r29, r29, r3;
lbl_80150c4c:
  lbz r0, 0x64(r31);
  ori r0, r0, 0xc;
  stb r0, 0x64(r31);
  lbz r0, 1(r30);
  cmpwi r0, 0;
  beq lbl_80150c70;
  lwz r0, 0x88(r31);
  rlwinm r0, r0, 0, 0x19, 0x19;
  or r29, r29, r0;
lbl_80150c70:
  cmpwi r29, 0;
  beq lbl_80150c94;
  lwz r12, 0x8c(r31);
  cmpwi r12, 0;
  beq lbl_80150c94;
  mr r3, r29;
  lbz r4, 0(r31);
  mtctr r12;
  bctrl;
lbl_80150c94:
  lis r3, 0x8034;
  addi r3, r3, -25816;
  lbz r0, 0x414(r3);
  cmplwi r0, 4;
  blt lbl_80150cd0;
  lbz r0, 0x5f(r31);
  lis r3, 9;
  lis r4, 0x8028;
  rlwinm r8, r0, 0x1d, 0x1f, 0x1f;
  rlwinm r7, r0, 0x1e, 0x1f, 0x1f;
  rlwinm r6, r0, 0x1f, 0x1f, 0x1f;
  addi r3, r3, 3;
  addi r4, r4, 0x6c70;
  clrlwi r5, r0, 0x1f;
  bl LogMsg_4;
lbl_80150cd0:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: PORT_ControlCnf
// PAL: 0x80150cec..0x80150db0
MARK_BINARY_BLOB(PORT_ControlCnf, 0x80150cec, 0x80150db0);
asm UNKNOWN_FUNCTION(PORT_ControlCnf) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  stw r30, 8(r1);
  bl port_find_mcb_dlci_port;
  lis r4, 0x8034;
  mr r31, r3;
  addi r4, r4, -25816;
  li r30, 0;
  lbz r0, 0x414(r4);
  cmplwi r0, 4;
  blt lbl_80150d34;
  lis r3, 9;
  lis r4, 0x8028;
  addi r3, r3, 3;
  addi r4, r4, 0x6cb0;
  bl LogMsg_0;
lbl_80150d34:
  cmpwi r31, 0;
  beq lbl_80150d98;
  lbz r3, 0x64(r31);
  rlwinm. r0, r3, 0, 0x1e, 0x1e;
  bne lbl_80150d60;
  ori r3, r3, 2;
  rlwinm. r0, r3, 0, 0x1d, 0x1d;
  stb r3, 0x64(r31);
  beq lbl_80150d60;
  lwz r0, 0x88(r31);
  rlwinm r30, r0, 0, 0x16, 0x16;
lbl_80150d60:
  rlwinm. r0, r3, 0, 0x1d, 0x1d;
  beq lbl_80150d74;
  mr r3, r31;
  bl port_rfc_send_tx_data;
  or r30, r30, r3;
lbl_80150d74:
  cmpwi r30, 0;
  beq lbl_80150d98;
  lwz r12, 0x8c(r31);
  cmpwi r12, 0;
  beq lbl_80150d98;
  mr r3, r30;
  lbz r4, 0(r31);
  mtctr r12;
  bctrl;
lbl_80150d98:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: PORT_LineStatusInd
// PAL: 0x80150db0..0x80150e78
MARK_BINARY_BLOB(PORT_LineStatusInd, 0x80150db0, 0x80150e78);
asm UNKNOWN_FUNCTION(PORT_LineStatusInd) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  mr r29, r5;
  bl port_find_mcb_dlci_port;
  lis r4, 0x8034;
  mr r31, r3;
  addi r4, r4, -25816;
  li r30, 0;
  lbz r0, 0x414(r4);
  cmplwi r0, 4;
  blt lbl_80150e00;
  lis r3, 9;
  lis r4, 0x8028;
  addi r3, r3, 3;
  addi r4, r4, 0x6cc0;
  bl LogMsg_0;
lbl_80150e00:
  cmpwi r31, 0;
  beq lbl_80150e5c;
  lbz r3, 0xf(r31);
  rlwinm. r0, r29, 0, 0x1e, 0x1e;
  or r0, r3, r29;
  stb r0, 0xf(r31);
  beq lbl_80150e20;
  ori r30, r30, 0x2000;
lbl_80150e20:
  clrlwi. r0, r29, 0x1f;
  beq lbl_80150e2c;
  ori r30, r30, 0x40;
lbl_80150e2c:
  rlwinm. r0, r29, 0, 0x18, 0x1d;
  beq lbl_80150e38;
  ori r30, r30, 0x80;
lbl_80150e38:
  lwz r12, 0x8c(r31);
  cmpwi r12, 0;
  beq lbl_80150e5c;
  lwz r0, 0x88(r31);
  and. r3, r0, r30;
  beq lbl_80150e5c;
  lbz r4, 0(r31);
  mtctr r12;
  bctrl;
lbl_80150e5c:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: PORT_DlcReleaseInd
// PAL: 0x80150e78..0x80150ee0
MARK_BINARY_BLOB(PORT_DlcReleaseInd, 0x80150e78, 0x80150ee0);
asm UNKNOWN_FUNCTION(PORT_DlcReleaseInd) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  bl port_find_mcb_dlci_port;
  lis r4, 0x8034;
  mr r31, r3;
  addi r4, r4, -25816;
  lbz r0, 0x414(r4);
  cmplwi r0, 4;
  blt lbl_80150eb8;
  lis r3, 9;
  lis r4, 0x8028;
  addi r3, r3, 3;
  addi r4, r4, 0x6cd4;
  bl LogMsg_0;
lbl_80150eb8:
  cmpwi r31, 0;
  beq lbl_80150ecc;
  mr r3, r31;
  li r4, 0x13;
  bl port_rfc_closed;
lbl_80150ecc:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: PORT_CloseInd
// PAL: 0x80150ee0..0x80150f80
MARK_BINARY_BLOB(PORT_CloseInd, 0x80150ee0, 0x80150f80);
asm UNKNOWN_FUNCTION(PORT_CloseInd) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  lis r4, 0x8034;
  stw r0, 0x24(r1);
  addi r4, r4, -25816;
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  mr r29, r3;
  lbz r0, 0x414(r4);
  cmplwi r0, 4;
  blt lbl_80150f24;
  lis r3, 9;
  lis r4, 0x8028;
  addi r3, r3, 3;
  addi r4, r4, 0x6ce8;
  bl LogMsg_0;
lbl_80150f24:
  lis r3, 0x8034;
  li r30, 0;
  addi r3, r3, -25816;
  addi r31, r3, 0x68;
lbl_80150f34:
  lwz r0, 0x6c(r31);
  cmplw r0, r29;
  bne lbl_80150f4c;
  mr r3, r31;
  li r4, 0x10;
  bl port_rfc_closed;
lbl_80150f4c:
  addi r30, r30, 1;
  addi r31, r31, 0xa4;
  cmpwi r30, 5;
  blt lbl_80150f34;
  mr r3, r29;
  bl rfc_release_multiplexer_channel;
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: Port_TimeOutCloseMux
// PAL: 0x80150f80..0x80151018
MARK_BINARY_BLOB(Port_TimeOutCloseMux, 0x80150f80, 0x80151018);
asm UNKNOWN_FUNCTION(Port_TimeOutCloseMux) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  lis r4, 0x8034;
  stw r0, 0x24(r1);
  addi r4, r4, -25816;
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  mr r29, r3;
  lbz r0, 0x414(r4);
  cmplwi r0, 4;
  blt lbl_80150fc4;
  lis r3, 9;
  lis r4, 0x8028;
  addi r3, r3, 3;
  addi r4, r4, 0x6cf8;
  bl LogMsg_0;
lbl_80150fc4:
  lis r3, 0x8034;
  li r30, 0;
  addi r3, r3, -25816;
  addi r31, r3, 0x68;
lbl_80150fd4:
  lwz r0, 0x6c(r31);
  cmplw r0, r29;
  bne lbl_80150fec;
  mr r3, r31;
  li r4, 0x12;
  bl port_rfc_closed;
lbl_80150fec:
  addi r30, r30, 1;
  addi r31, r31, 0xa4;
  cmpwi r30, 5;
  blt lbl_80150fd4;
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: PORT_DataInd
// PAL: 0x80151018..0x80151218
MARK_BINARY_BLOB(PORT_DataInd, 0x80151018, 0x80151218);
asm UNKNOWN_FUNCTION(PORT_DataInd) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_27;
  mr r28, r4;
  mr r27, r3;
  mr r29, r5;
  bl port_find_mcb_dlci_port;
  lis r4, 0x8034;
  mr r31, r3;
  addi r4, r4, -25816;
  li r30, 0;
  lbz r0, 0x414(r4);
  cmplwi r0, 4;
  blt lbl_80151070;
  lis r3, 9;
  lis r4, 0x8028;
  lhz r5, 2(r29);
  addi r3, r3, 3;
  addi r4, r4, 0x6d10;
  bl LogMsg_1;
lbl_80151070:
  cmpwi r31, 0;
  bne lbl_80151084;
  mr r3, r29;
  bl GKI_freebuf;
  b lbl_80151200;
lbl_80151084:
  lwz r0, 0x94(r31);
  cmpwi r0, 0;
  beq lbl_801510cc;
  mr r3, r31;
  li r4, 1;
  li r5, 1;
  bl port_flow_control_peer;
  lhz r0, 4(r29);
  lwz r12, 0x94(r31);
  add r4, r29, r0;
  lbz r3, 0(r31);
  addi r4, r4, 8;
  lhz r5, 2(r29);
  mtctr r12;
  bctrl;
  mr r3, r29;
  bl GKI_freebuf;
  b lbl_80151200;
lbl_801510cc:
  lhz r4, 2(r29);
  lwz r0, 0x40(r31);
  add r0, r0, r4;
  cmplwi r0, 0x2ee0;
  bgt lbl_801510f4;
  lhz r3, 0x38(r31);
  lhz r0, 0xa0(r31);
  addi r3, r3, 1;
  cmpw r3, r0;
  ble lbl_80151138;
lbl_801510f4:
  lis r3, 0x8034;
  addi r3, r3, -25816;
  lbz r0, 0x414(r3);
  cmplwi r0, 4;
  blt lbl_8015111c;
  lis r3, 9;
  lis r4, 0x8028;
  addi r3, r3, 3;
  addi r4, r4, 0x6d34;
  bl LogMsg_0;
lbl_8015111c:
  mr r3, r29;
  bl GKI_freebuf;
  mr r3, r27;
  mr r4, r28;
  li r5, 2;
  bl RFCOMM_LineStatusReq;
  b lbl_80151200;
lbl_80151138:
  lbz r5, 0x4e(r31);
  cmpwi r5, 0;
  beq lbl_80151184;
  lwz r0, 0x88(r31);
  rlwinm. r0, r0, 0, 0x1e, 0x1e;
  beq lbl_80151184;
  lhz r0, 4(r29);
  add r3, r29, r0;
  addi r3, r3, 8;
  mtctr r4;
  cmpwi r4, 0;
  ble lbl_80151184;
lbl_80151168:
  lbz r0, 0(r3);
  addi r3, r3, 1;
  cmplw r0, r5;
  bne lbl_80151180;
  ori r30, r30, 2;
  b lbl_80151184;
lbl_80151180:
  bdnz lbl_80151168;
lbl_80151184:
  mr r4, r29;
  addi r3, r31, 0x30;
  bl GKI_enqueue;
  lwz r6, 0x40(r31);
  mr r3, r31;
  lhz r0, 2(r29);
  li r4, 0;
  li r5, 0;
  add r0, r6, r0;
  stw r0, 0x40(r31);
  bl port_flow_control_peer;
  lbz r0, 0x3d(r31);
  cmpwi r0, 0;
  beq lbl_801511d0;
  rlwinm. r0, r30, 0, 0x1e, 0x1e;
  beq lbl_80151200;
  li r0, 1;
  stb r0, 0x65(r31);
  b lbl_80151200;
lbl_801511d0:
  lwz r12, 0x8c(r31);
  ori r30, r30, 1;
  lwz r0, 0x88(r31);
  cmpwi r12, 0;
  and r30, r30, r0;
  beq lbl_80151200;
  cmpwi r30, 0;
  beq lbl_80151200;
  mr r3, r30;
  lbz r4, 0(r31);
  mtctr r12;
  bctrl;
lbl_80151200:
  addi r11, r1, 0x20;
  bl _restgpr_27;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: PORT_FlowInd
// PAL: 0x80151218..0x80151348
MARK_BINARY_BLOB(PORT_FlowInd, 0x80151218, 0x80151348);
asm UNKNOWN_FUNCTION(PORT_FlowInd) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_26;
  lis r6, 0x8034;
  mr r26, r3;
  addi r6, r6, -25816;
  mr r27, r4;
  lbz r0, 0x414(r6);
  mr r28, r5;
  li r29, 0;
  cmplwi r0, 4;
  blt lbl_80151264;
  lis r3, 9;
  lis r4, 0x8028;
  addi r3, r3, 3;
  addi r4, r4, 0x6d68;
  bl LogMsg_1;
lbl_80151264:
  cmpwi r27, 0;
  bne lbl_80151274;
  stb r28, 0x71(r26);
  b lbl_80151298;
lbl_80151274:
  mr r3, r26;
  mr r4, r27;
  bl port_find_mcb_dlci_port;
  cmpwi r3, 0;
  mr r29, r3;
  beq lbl_80151330;
  cntlzw r0, r28;
  rlwinm r0, r0, 0x1b, 0x18, 0x1f;
  stb r0, 0x24(r3);
lbl_80151298:
  lis r3, 0x8034;
  li r28, 0;
  addi r3, r3, -25816;
  addi r30, r3, 0x68;
lbl_801512a8:
  cmpwi r27, 0;
  bne lbl_801512d8;
  lbz r0, 1(r30);
  mr r29, r30;
  cmpwi r0, 0;
  beq lbl_80151320;
  lwz r0, 0x6c(r30);
  cmplw r0, r26;
  bne lbl_80151320;
  lbz r0, 0x68(r30);
  cmplwi r0, 4;
  bne lbl_80151320;
lbl_801512d8:
  mr r3, r29;
  bl port_flow_control_user;
  mr r31, r3;
  mr r3, r29;
  bl port_rfc_send_tx_data;
  lwz r12, 0x8c(r29);
  or r3, r31, r3;
  lwz r0, 0x88(r29);
  cmpwi r12, 0;
  and r3, r3, r0;
  beq lbl_80151318;
  cmpwi r3, 0;
  beq lbl_80151318;
  lbz r4, 0(r29);
  mtctr r12;
  bctrl;
lbl_80151318:
  cmpwi r27, 0;
  bne lbl_80151330;
lbl_80151320:
  addi r28, r28, 1;
  addi r30, r30, 0xa4;
  cmpwi r28, 5;
  blt lbl_801512a8;
lbl_80151330:
  addi r11, r1, 0x20;
  bl _restgpr_26;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: port_rfc_send_tx_data
// PAL: 0x80151348..0x80151440
MARK_BINARY_BLOB(port_rfc_send_tx_data, 0x80151348, 0x80151440);
asm UNKNOWN_FUNCTION(port_rfc_send_tx_data) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_26;
  lwz r0, 0x28(r3);
  mr r26, r3;
  li r28, 0;
  cmpwi r0, 0;
  beq lbl_80151420;
  lis r29, 0x8034;
  lis r30, 9;
  addi r29, r29, -25816;
  lis r31, 0x8028;
  b lbl_801513f0;
lbl_80151384:
  addi r3, r26, 0x18;
  bl GKI_dequeue;
  cmpwi r3, 0;
  mr r27, r3;
  beq lbl_801513e8;
  lbz r0, 0x414(r29);
  cmplwi r0, 4;
  blt lbl_801513b0;
  addi r3, r30, 3;
  addi r4, r31, 0x6d7c;
  bl LogMsg_0;
lbl_801513b0:
  lhz r4, 2(r27);
  mr r5, r27;
  lwz r0, 0x28(r26);
  lwz r3, 0x6c(r26);
  subf r0, r4, r0;
  lbz r4, 0xd(r26);
  stw r0, 0x28(r26);
  bl RFCOMM_DataReq;
  lwz r0, 0x28(r26);
  ori r28, r28, 0x4000;
  cmpwi r0, 0;
  bne lbl_801513f0;
  ori r28, r28, 4;
  b lbl_80151414;
lbl_801513e8:
  ori r28, r28, 4;
  b lbl_80151414;
lbl_801513f0:
  lbz r0, 0x24(r26);
  cmpwi r0, 0;
  bne lbl_80151414;
  lwz r3, 0x6c(r26);
  cmpwi r3, 0;
  beq lbl_80151414;
  lbz r0, 0x71(r3);
  cmpwi r0, 0;
  bne lbl_80151384;
lbl_80151414:
  mr r3, r26;
  bl port_flow_control_user;
  or r28, r28, r3;
lbl_80151420:
  lwz r0, 0x88(r26);
  addi r11, r1, 0x20;
  and r3, r28, r0;
  bl _restgpr_26;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: port_rfc_closed
// PAL: 0x80151440..0x801515d4
MARK_BINARY_BLOB(port_rfc_closed, 0x80151440, 0x801515d4);
asm UNKNOWN_FUNCTION(port_rfc_closed) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r3;
  stw r30, 0x18(r1);
  li r30, 0;
  stw r29, 0x14(r1);
  stw r28, 0x10(r1);
  mr r28, r4;
  lbz r5, 2(r3);
  lwz r29, 0x6c(r3);
  cmplwi r5, 1;
  bne lbl_801514ec;
  lbz r0, 0xc(r3);
  cmpwi r0, 0;
  beq lbl_801514ec;
  lis r3, 0x8034;
  addi r3, r3, -25816;
  lbz r0, 0x414(r3);
  cmplwi r0, 4;
  blt lbl_801514ac;
  lis r3, 9;
  lis r4, 0x8028;
  addi r3, r3, 3;
  addi r4, r4, 0x6d94;
  bl LogMsg_0;
lbl_801514ac:
  mr r3, r31;
  bl rfc_port_timer_stop;
  li r30, 0;
  cmpwi r29, 0;
  stb r30, 0x68(r31);
  beq lbl_801514dc;
  lbz r0, 0xd(r31);
  mr r3, r29;
  add r4, r29, r0;
  stb r30, 0x24(r4);
  bl rfc_check_mcb_active;
  stw r30, 0x6c(r31);
lbl_801514dc:
  lbz r0, 0xd(r31);
  rlwinm r0, r0, 0, 0x18, 0x1e;
  stb r0, 0xd(r31);
  b lbl_801515b4;
lbl_801514ec:
  cmplwi r5, 3;
  beq lbl_80151534;
  cmpwi r5, 0;
  beq lbl_80151534;
  lbz r5, 0xf(r3);
  li r0, -12;
  lbz r4, 0x5f(r3);
  ori r6, r5, 0x10;
  and r5, r4, r0;
  stb r6, 0xf(r3);
  stb r5, 0x5f(r3);
  mr r3, r31;
  bl port_get_signal_changes;
  lwz r0, 0x88(r31);
  mr r30, r3;
  rlwinm. r0, r0, 0, 0x10, 0x10;
  beq lbl_80151534;
  ori r30, r3, 0x8000;
lbl_80151534:
  lis r3, 0x8034;
  addi r3, r3, -25816;
  lbz r0, 0x414(r3);
  cmplwi r0, 4;
  blt lbl_80151564;
  lis r3, 9;
  lis r4, 0x8028;
  lbz r5, 2(r31);
  mr r6, r30;
  addi r3, r3, 3;
  addi r4, r4, 0x6dc0;
  bl LogMsg_2;
lbl_80151564:
  lwz r12, 0x8c(r31);
  cmpwi r12, 0;
  beq lbl_80151588;
  cmpwi r30, 0;
  beq lbl_80151588;
  mr r3, r30;
  lbz r4, 0(r31);
  mtctr r12;
  bctrl;
lbl_80151588:
  lwz r12, 0x90(r31);
  cmpwi r12, 0;
  beq lbl_801515a4;
  mr r3, r28;
  lbz r4, 0(r31);
  mtctr r12;
  bctrl;
lbl_801515a4:
  li r0, 0;
  mr r3, r31;
  stb r0, 0x68(r31);
  bl port_release_port;
lbl_801515b4:
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

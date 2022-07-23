#include "port_utils.h"

#include <string.h>

#include "gki_buffer.h"
#include "bte_logmsg.h"
#include "btm_acl.h"
#include "rfc_port_if.h"
#include "rfc_ts_frames.h"
#include "rfc_utils.h"

// Symbol: port_select_mtu
// PAL: 0x801515d4..0x80151750
MARK_BINARY_BLOB(port_select_mtu, 0x801515d4, 0x80151750);
asm UNKNOWN_FUNCTION(port_select_mtu) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  lis r31, 0x8028;
  addi r31, r31, 0x6df0;
  stw r30, 8(r1);
  mr r30, r3;
  lhz r5, 0x12(r3);
  cmpwi r5, 0;
  bne lbl_801516bc;
  addi r3, r3, 6;
  bl btm_get_max_packet_size;
  clrlwi. r5, r3, 0x10;
  bne lbl_80151640;
  lis r3, 0x8034;
  addi r3, r3, -25816;
  lbz r0, 0x414(r3);
  cmplwi r0, 2;
  blt lbl_80151634;
  lis r3, 9;
  addi r4, r31, 0;
  addi r3, r3, 1;
  bl LogMsg_0;
lbl_80151634:
  li r0, 0x7f;
  sth r0, 0x12(r30);
  b lbl_801516e0;
lbl_80151640:
  cmplwi r5, 0x69f;
  bgt lbl_80151688;
  li r0, 0x69f;
  lis r4, 0x8034;
  divw r0, r0, r5;
  addi r4, r4, -25816;
  mullw r3, r0, r3;
  addi r5, r3, -10;
  sth r5, 0x12(r30);
  lbz r0, 0x414(r4);
  cmplwi r0, 5;
  blt lbl_801516e0;
  lis r3, 9;
  addi r4, r31, 0x20;
  addi r3, r3, 4;
  clrlwi r5, r5, 0x10;
  bl LogMsg_1;
  b lbl_801516e0;
lbl_80151688:
  li r0, 0x695;
  lis r3, 0x8034;
  sth r0, 0x12(r30);
  addi r3, r3, -25816;
  lbz r0, 0x414(r3);
  cmplwi r0, 5;
  blt lbl_801516e0;
  lis r3, 9;
  addi r4, r31, 0x58;
  addi r3, r3, 4;
  li r5, 0x695;
  bl LogMsg_1;
  b lbl_801516e0;
lbl_801516bc:
  lis r3, 0x8034;
  addi r3, r3, -25816;
  lbz r0, 0x414(r3);
  cmplwi r0, 5;
  blt lbl_801516e0;
  lis r3, 9;
  addi r4, r31, 0x90;
  addi r3, r3, 4;
  bl LogMsg_1;
lbl_801516e0:
  lhz r7, 0x12(r30);
  li r3, 0x1f40;
  li r4, 0x1388;
  li r0, 0x2ee0;
  divw r5, r3, r7;
  lis r3, 0x8034;
  addi r3, r3, -25816;
  divw r6, r4, r7;
  sth r5, 0x9c(r30);
  divw r7, r0, r7;
  sth r6, 0x9e(r30);
  sth r7, 0xa0(r30);
  lbz r0, 0x414(r3);
  cmplwi r0, 5;
  blt lbl_80151738;
  lis r3, 9;
  addi r4, r31, 0xb8;
  addi r3, r3, 4;
  clrlwi r5, r5, 0x10;
  clrlwi r6, r6, 0x10;
  clrlwi r7, r7, 0x10;
  bl LogMsg_3;
lbl_80151738:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: port_release_port
// PAL: 0x80151750..0x8015182c
MARK_BINARY_BLOB(port_release_port, 0x80151750, 0x8015182c);
asm UNKNOWN_FUNCTION(port_release_port) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  b lbl_8015176c;
lbl_80151768:
  bl GKI_freebuf;
lbl_8015176c:
  addi r3, r31, 0x30;
  bl GKI_dequeue;
  cmpwi r3, 0;
  bne lbl_80151768;
  li r0, 0;
  stw r0, 0x40(r31);
  b lbl_8015178c;
lbl_80151788:
  bl GKI_freebuf;
lbl_8015178c:
  addi r3, r31, 0x18;
  bl GKI_dequeue;
  cmpwi r3, 0;
  bne lbl_80151788;
  lbz r0, 0x68(r31);
  li r3, 0;
  stw r3, 0x28(r31);
  cmpwi r0, 0;
  stb r3, 2(r31);
  bne lbl_80151818;
  lis r3, 0x8034;
  addi r3, r3, -25816;
  lbz r0, 0x414(r3);
  cmplwi r0, 5;
  blt lbl_801517dc;
  lis r3, 9;
  lis r4, 0x8028;
  addi r3, r3, 4;
  addi r4, r4, 0x6ef0;
  bl LogMsg_0;
lbl_801517dc:
  lwz r3, 0x6c(r31);
  cmpwi r3, 0;
  beq lbl_80151800;
  lbz r0, 0xd(r31);
  li r4, 0;
  add r3, r3, r0;
  stb r4, 0x24(r3);
  lwz r3, 0x6c(r31);
  bl rfc_check_mcb_active;
lbl_80151800:
  mr r3, r31;
  bl rfc_port_timer_stop;
  mr r3, r31;
  li r4, 0;
  li r5, 0xa4;
  bl memset;
lbl_80151818:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: port_find_mcb_dlci_port
// PAL: 0x8015182c..0x80151880
MARK_BINARY_BLOB(port_find_mcb_dlci_port, 0x8015182c, 0x80151880);
asm UNKNOWN_FUNCTION(port_find_mcb_dlci_port) {
  // clang-format off
  nofralloc;
  cmpwi r3, 0;
  bne lbl_8015183c;
  li r3, 0;
  blr;
lbl_8015183c:
  cmplwi r4, 0x3d;
  ble lbl_8015184c;
  li r3, 0;
  blr;
lbl_8015184c:
  add r3, r3, r4;
  lbz r3, 0x24(r3);
  cmpwi r3, 0;
  bne lbl_80151864;
  li r3, 0;
  blr;
lbl_80151864:
  addi r0, r3, -1;
  lis r3, 0x8034;
  mulli r0, r0, 0xa4;
  addi r3, r3, -25816;
  add r3, r3, r0;
  addi r3, r3, 0x68;
  blr;
  // clang-format on
}

// Symbol: port_find_dlci_port
// PAL: 0x80151880..0x80151908
MARK_BINARY_BLOB(port_find_dlci_port, 0x80151880, 0x80151908);
asm UNKNOWN_FUNCTION(port_find_dlci_port) {
  // clang-format off
  nofralloc;
  lis r5, 0x8034;
  li r0, 5;
  clrlwi r6, r3, 0x1f;
  addi r7, r3, -1;
  addi r5, r5, -25816;
  li r8, 0;
  mtctr r0;
lbl_8015189c:
  clrlwi r0, r8, 0x10;
  mulli r0, r0, 0xa4;
  add r4, r5, r0;
  lbz r0, 0x69(r4);
  addi r9, r4, 0x68;
  cmpwi r0, 0;
  beq lbl_801518f8;
  lwz r0, 0x6c(r9);
  cmpwi r0, 0;
  bne lbl_801518f8;
  lbz r4, 0xd(r9);
  cmplw r4, r3;
  bne lbl_801518d8;
  mr r3, r9;
  blr;
lbl_801518d8:
  cmpwi r6, 0;
  beq lbl_801518f8;
  cmpw r4, r7;
  bne lbl_801518f8;
  addi r0, r4, 1;
  mr r3, r9;
  stb r0, 0xd(r9);
  blr;
lbl_801518f8:
  addi r8, r8, 1;
  bdnz lbl_8015189c;
  li r3, 0;
  blr;
  // clang-format on
}

// Symbol: port_flow_control_user
// PAL: 0x80151908..0x80151978
MARK_BINARY_BLOB(port_flow_control_user, 0x80151908, 0x80151978);
asm UNKNOWN_FUNCTION(port_flow_control_user) {
  // clang-format off
  nofralloc;
  lbz r0, 0x24(r3);
  li r5, 0;
  cmpwi r0, 0;
  bne lbl_80151948;
  lwz r4, 0x6c(r3);
  cmpwi r4, 0;
  beq lbl_80151948;
  lbz r0, 0x71(r4);
  cmpwi r0, 0;
  beq lbl_80151948;
  lwz r0, 0x28(r3);
  cmplwi r0, 0x1f40;
  bgt lbl_80151948;
  lhz r0, 0x20(r3);
  cmplwi r0, 0x10;
  ble lbl_8015194c;
lbl_80151948:
  li r5, 1;
lbl_8015194c:
  lbz r0, 0x25(r3);
  cmplw r0, r5;
  bne lbl_80151960;
  li r3, 0;
  blr;
lbl_80151960:
  cmpwi r5, 0;
  stb r5, 0x25(r3);
  lis r3, 3;
  beqlr;
  lis r3, 1;
  blr;
  // clang-format on
}

// Symbol: port_get_signal_changes
// PAL: 0x80151978..0x801519e0
MARK_BINARY_BLOB(port_get_signal_changes, 0x80151978, 0x801519e0);
asm UNKNOWN_FUNCTION(port_get_signal_changes) {
  // clang-format off
  nofralloc;
  xor r4, r5, r4;
  li r6, 0;
  clrlwi. r0, r4, 0x1f;
  beq lbl_80151998;
  clrlwi. r0, r5, 0x1f;
  ori r6, r6, 0x10;
  beq lbl_80151998;
  ori r6, r6, 0x800;
lbl_80151998:
  rlwinm. r0, r4, 0, 0x1e, 0x1e;
  beq lbl_801519b0;
  rlwinm. r0, r5, 0, 0x1e, 0x1e;
  ori r6, r6, 8;
  beq lbl_801519b0;
  ori r6, r6, 0x400;
lbl_801519b0:
  rlwinm. r0, r4, 0, 0x1d, 0x1d;
  beq lbl_801519bc;
  ori r6, r6, 0x100;
lbl_801519bc:
  rlwinm. r0, r4, 0, 0x1c, 0x1c;
  beq lbl_801519d4;
  rlwinm. r0, r5, 0, 0x1c, 0x1c;
  ori r6, r6, 0x20;
  beq lbl_801519d4;
  ori r6, r6, 0x1000;
lbl_801519d4:
  lwz r0, 0x88(r3);
  and r3, r0, r6;
  blr;
  // clang-format on
}

// Symbol: port_flow_control_peer
// PAL: 0x801519e0..0x80151bac
MARK_BINARY_BLOB(port_flow_control_peer, 0x801519e0, 0x80151bac);
asm UNKNOWN_FUNCTION(port_flow_control_peer) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  lwz r6, 0x6c(r3);
  cmpwi r6, 0;
  beq lbl_80151b98;
  lbz r0, 0x72(r6);
  cmplwi r0, 2;
  bne lbl_80151ab8;
  cmpwi r4, 0;
  beq lbl_80151a84;
  lhz r0, 0x9a(r3);
  cmplw r5, r0;
  ble lbl_80151a2c;
  li r0, 0;
  sth r0, 0x9a(r3);
  b lbl_80151a34;
lbl_80151a2c:
  subf r0, r5, r0;
  sth r0, 0x9a(r3);
lbl_80151a34:
  lhz r4, 0x9a(r3);
  lhz r0, 0x9e(r3);
  cmplw r4, r0;
  bgt lbl_80151b98;
  lbz r0, 0x3d(r3);
  cmpwi r0, 0;
  bne lbl_80151b98;
  lhz r0, 0x9c(r3);
  cmplw r0, r4;
  ble lbl_80151b98;
  subf r0, r4, r0;
  lwz r3, 0x6c(r3);
  lbz r4, 0xd(r31);
  clrlwi r5, r0, 0x18;
  bl rfc_send_credit;
  lhz r3, 0x9c(r31);
  li r0, 0;
  stb r0, 0x3c(r31);
  sth r3, 0x9a(r31);
  b lbl_80151b98;
lbl_80151a84:
  lwz r0, 0x94(r3);
  cmpwi r0, 0;
  beq lbl_80151a9c;
  li r0, 1;
  stb r0, 0x3c(r3);
  b lbl_80151b98;
lbl_80151a9c:
  lhz r4, 0x38(r3);
  lhz r0, 0x9c(r3);
  cmplw r4, r0;
  blt lbl_80151b98;
  li r0, 1;
  stb r0, 0x3c(r3);
  b lbl_80151b98;
lbl_80151ab8:
  cmpwi r4, 0;
  beq lbl_80151b0c;
  lbz r0, 0x3c(r3);
  cmpwi r0, 0;
  beq lbl_80151b98;
  lwz r0, 0x40(r3);
  cmplwi r0, 0x1388;
  bge lbl_80151b98;
  lhz r0, 0x38(r3);
  cmplwi r0, 8;
  bge lbl_80151b98;
  lbz r0, 0x3d(r3);
  li r4, 0;
  stb r4, 0x3c(r3);
  cmpwi r0, 0;
  bne lbl_80151b98;
  lbz r4, 0xd(r31);
  mr r3, r6;
  li r5, 1;
  bl RFCOMM_FlowReq;
  b lbl_80151b98;
lbl_80151b0c:
  lwz r0, 0x94(r3);
  cmpwi r0, 0;
  beq lbl_80151b34;
  li r0, 1;
  lbz r4, 0xd(r31);
  stb r0, 0x3c(r3);
  mr r3, r6;
  li r5, 0;
  bl RFCOMM_FlowReq;
  b lbl_80151b98;
lbl_80151b34:
  lwz r0, 0x40(r3);
  cmplwi r0, 0x1f40;
  bgt lbl_80151b4c;
  lhz r0, 0x38(r3);
  cmplwi r0, 0x10;
  ble lbl_80151b98;
lbl_80151b4c:
  lbz r0, 0x3c(r3);
  cmpwi r0, 0;
  bne lbl_80151b98;
  lis r3, 0x8034;
  addi r3, r3, -25816;
  lbz r0, 0x414(r3);
  cmplwi r0, 4;
  blt lbl_80151b80;
  lis r3, 9;
  lis r4, 0x8028;
  addi r3, r3, 3;
  addi r4, r4, 0x6f08;
  bl LogMsg_0;
lbl_80151b80:
  li r0, 1;
  lwz r3, 0x6c(r31);
  stb r0, 0x3c(r31);
  li r5, 0;
  lbz r4, 0xd(r31);
  bl RFCOMM_FlowReq;
lbl_80151b98:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

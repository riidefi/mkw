#include "hcicmds.h"

#include <string.h>

#include "gki_buffer.h"
#include "btu_hcif.h"

// Symbol: btsnd_hcic_inquiry
// PAL: 0x80144618..0x801446c0
MARK_BINARY_BLOB(btsnd_hcic_inquiry, 0x80144618, 0x801446c0);
asm UNKNOWN_FUNCTION(btsnd_hcic_inquiry) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r5;
  stw r30, 0x18(r1);
  mr r30, r4;
  stw r29, 0x14(r1);
  mr r29, r3;
  li r3, 2;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  bne lbl_80144654;
  li r3, 0;
  b lbl_801446a4;
lbl_80144654:
  li r0, 8;
  li r5, 0;
  sth r0, 2(r3);
  li r4, 1;
  li r0, 4;
  li r6, 5;
  sth r5, 4(r3);
  lbz r5, 2(r29);
  stb r4, 8(r3);
  lbz r4, 1(r29);
  stb r0, 9(r3);
  lbz r0, 0(r29);
  stb r6, 0xa(r3);
  stb r5, 0xb(r3);
  stb r4, 0xc(r3);
  stb r0, 0xd(r3);
  stb r30, 0xe(r3);
  stb r31, 0xf(r3);
  bl btu_hcif_send_cmd;
  li r3, 1;
lbl_801446a4:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: btsnd_hcic_inq_cancel
// PAL: 0x801446c0..0x80144720
MARK_BINARY_BLOB(btsnd_hcic_inq_cancel, 0x801446c0, 0x80144720);
asm UNKNOWN_FUNCTION(btsnd_hcic_inq_cancel) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  li r3, 2;
  stw r0, 0x14(r1);
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  bne lbl_801446e4;
  li r3, 0;
  b lbl_80144710;
lbl_801446e4:
  li r0, 3;
  li r5, 0;
  sth r0, 2(r3);
  li r4, 2;
  li r0, 4;
  sth r5, 4(r3);
  stb r4, 8(r3);
  stb r0, 9(r3);
  stb r5, 0xa(r3);
  bl btu_hcif_send_cmd;
  li r3, 1;
lbl_80144710:
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: btsnd_hcic_per_inq_mode
// PAL: 0x80144720..0x801447e0
MARK_BINARY_BLOB(btsnd_hcic_per_inq_mode, 0x80144720, 0x801447e0);
asm UNKNOWN_FUNCTION(btsnd_hcic_per_inq_mode) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_27;
  mr r27, r3;
  mr r28, r4;
  mr r29, r5;
  mr r30, r6;
  mr r31, r7;
  li r3, 2;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  bne lbl_80144760;
  li r3, 0;
  b lbl_801447c8;
lbl_80144760:
  li r0, 0xc;
  li r5, 0;
  sth r0, 2(r3);
  li r4, 3;
  li r0, 4;
  li r8, 9;
  sth r5, 4(r3);
  srawi r7, r27, 8;
  rlwinm r6, r28, 0x18, 0x18, 0x1f;
  lbz r5, 2(r29);
  stb r4, 8(r3);
  lbz r4, 1(r29);
  stb r0, 9(r3);
  lbz r0, 0(r29);
  stb r8, 0xa(r3);
  stb r27, 0xb(r3);
  stb r7, 0xc(r3);
  stb r28, 0xd(r3);
  stb r6, 0xe(r3);
  stb r5, 0xf(r3);
  stb r4, 0x10(r3);
  stb r0, 0x11(r3);
  stb r30, 0x12(r3);
  stb r31, 0x13(r3);
  bl btu_hcif_send_cmd;
  li r3, 1;
lbl_801447c8:
  addi r11, r1, 0x20;
  bl _restgpr_27;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: btsnd_hcic_create_conn
// PAL: 0x801447e0..0x801448c0
MARK_BINARY_BLOB(btsnd_hcic_create_conn, 0x801447e0, 0x801448c0);
asm UNKNOWN_FUNCTION(btsnd_hcic_create_conn) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_26;
  mr r26, r3;
  mr r27, r4;
  mr r28, r5;
  mr r29, r6;
  mr r30, r7;
  mr r31, r8;
  li r3, 2;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  bne lbl_80144824;
  li r3, 0;
  b lbl_801448a8;
lbl_80144824:
  li r4, 0x10;
  li r0, 0;
  sth r4, 2(r3);
  li r7, 5;
  li r6, 4;
  li r5, 0xd;
  sth r0, 4(r3);
  srawi r4, r27, 8;
  rlwinm r0, r30, 0x18, 0x18, 0x1f;
  stb r7, 8(r3);
  stb r6, 9(r3);
  stb r5, 0xa(r3);
  lbz r5, 5(r26);
  stb r5, 0xb(r3);
  lbz r5, 4(r26);
  stb r5, 0xc(r3);
  lbz r5, 3(r26);
  stb r5, 0xd(r3);
  lbz r5, 2(r26);
  stb r5, 0xe(r3);
  lbz r5, 1(r26);
  stb r5, 0xf(r3);
  lbz r5, 0(r26);
  stb r5, 0x10(r3);
  stb r27, 0x11(r3);
  stb r4, 0x12(r3);
  stb r28, 0x13(r3);
  stb r29, 0x14(r3);
  stb r30, 0x15(r3);
  stb r0, 0x16(r3);
  stb r31, 0x17(r3);
  bl btu_hcif_send_cmd;
  li r3, 1;
lbl_801448a8:
  addi r11, r1, 0x20;
  bl _restgpr_26;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: btsnd_hcic_disconnect
// PAL: 0x801448c0..0x80144948
MARK_BINARY_BLOB(btsnd_hcic_disconnect, 0x801448c0, 0x80144948);
asm UNKNOWN_FUNCTION(btsnd_hcic_disconnect) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  li r3, 2;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  bne lbl_801448f4;
  li r3, 0;
  b lbl_80144930;
lbl_801448f4:
  li r7, 6;
  li r6, 0;
  sth r7, 2(r3);
  li r5, 4;
  li r4, 3;
  rlwinm r0, r30, 0x18, 0x18, 0x1f;
  sth r6, 4(r3);
  stb r7, 8(r3);
  stb r5, 9(r3);
  stb r4, 0xa(r3);
  stb r30, 0xb(r3);
  stb r0, 0xc(r3);
  stb r31, 0xd(r3);
  bl btu_hcif_send_cmd;
  li r3, 1;
lbl_80144930:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: btsnd_hcic_add_SCO_conn
// PAL: 0x80144948..0x801449d4
MARK_BINARY_BLOB(btsnd_hcic_add_SCO_conn, 0x80144948, 0x801449d4);
asm UNKNOWN_FUNCTION(btsnd_hcic_add_SCO_conn) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  li r3, 2;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  bne lbl_8014497c;
  li r3, 0;
  b lbl_801449bc;
lbl_8014497c:
  li r7, 7;
  li r6, 0;
  sth r7, 2(r3);
  li r5, 4;
  srawi r4, r30, 8;
  rlwinm r0, r31, 0x18, 0x18, 0x1f;
  sth r6, 4(r3);
  stb r7, 8(r3);
  stb r5, 9(r3);
  stb r5, 0xa(r3);
  stb r30, 0xb(r3);
  stb r4, 0xc(r3);
  stb r31, 0xd(r3);
  stb r0, 0xe(r3);
  bl btu_hcif_send_cmd;
  li r3, 1;
lbl_801449bc:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: btsnd_hcic_accept_conn
// PAL: 0x801449d4..0x80144a34
MARK_BINARY_BLOB(btsnd_hcic_accept_conn, 0x801449d4, 0x80144a34);
asm UNKNOWN_FUNCTION(btsnd_hcic_accept_conn) {
  // clang-format off
  nofralloc;
  li r9, 0xa;
  li r8, 0;
  li r7, 9;
  li r6, 4;
  li r0, 7;
  sth r9, 2(r3);
  sth r8, 4(r3);
  stb r7, 8(r3);
  stb r6, 9(r3);
  stb r0, 0xa(r3);
  lbz r0, 5(r4);
  stb r0, 0xb(r3);
  lbz r0, 4(r4);
  stb r0, 0xc(r3);
  lbz r0, 3(r4);
  stb r0, 0xd(r3);
  lbz r0, 2(r4);
  stb r0, 0xe(r3);
  lbz r0, 1(r4);
  stb r0, 0xf(r3);
  lbz r0, 0(r4);
  stb r0, 0x10(r3);
  stb r5, 0x11(r3);
  b btu_hcif_send_cmd;
  // clang-format on
}

// Symbol: btsnd_hcic_reject_conn
// PAL: 0x80144a34..0x80144a90
MARK_BINARY_BLOB(btsnd_hcic_reject_conn, 0x80144a34, 0x80144a90);
asm UNKNOWN_FUNCTION(btsnd_hcic_reject_conn) {
  // clang-format off
  nofralloc;
  li r8, 0xa;
  li r7, 0;
  li r6, 4;
  li r0, 7;
  sth r8, 2(r3);
  sth r7, 4(r3);
  stb r8, 8(r3);
  stb r6, 9(r3);
  stb r0, 0xa(r3);
  lbz r0, 5(r4);
  stb r0, 0xb(r3);
  lbz r0, 4(r4);
  stb r0, 0xc(r3);
  lbz r0, 3(r4);
  stb r0, 0xd(r3);
  lbz r0, 2(r4);
  stb r0, 0xe(r3);
  lbz r0, 1(r4);
  stb r0, 0xf(r3);
  lbz r0, 0(r4);
  stb r0, 0x10(r3);
  stb r5, 0x11(r3);
  b btu_hcif_send_cmd;
  // clang-format on
}

// Symbol: btsnd_hcic_link_key_req_reply
// PAL: 0x80144a90..0x80144c30
MARK_BINARY_BLOB(btsnd_hcic_link_key_req_reply, 0x80144a90, 0x80144c30);
asm UNKNOWN_FUNCTION(btsnd_hcic_link_key_req_reply) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_23;
  mr r30, r3;
  mr r31, r4;
  li r3, 2;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  bne lbl_80144ac4;
  li r3, 0;
  b lbl_80144c18;
lbl_80144ac4:
  li r0, 0x19;
  li r4, 0;
  sth r0, 2(r3);
  li r0, 0xb;
  li r6, 4;
  li r5, 0x16;
  sth r4, 4(r3);
  subfic r24, r4, 0xf;
  li r25, 1;
  li r27, 2;
  stb r0, 8(r3);
  subfic r26, r25, 0xf;
  subfic r28, r27, 0xf;
  li r4, 3;
  stb r6, 9(r3);
  subfic r29, r4, 0xf;
  li r9, 5;
  subfic r10, r6, 0xf;
  stb r5, 0xa(r3);
  subfic r8, r9, 0xf;
  li r7, 6;
  li r5, 7;
  lbz r4, 5(r30);
  subfic r6, r7, 0xf;
  li r23, 8;
  li r25, 9;
  stb r4, 0xb(r3);
  subfic r4, r5, 0xf;
  li r27, 0xa;
  li r11, 0xc;
  lbz r5, 4(r30);
  li r9, 0xd;
  li r7, 0xe;
  stb r5, 0xc(r3);
  li r5, 0xf;
  lbz r12, 3(r30);
  stb r12, 0xd(r3);
  lbz r12, 2(r30);
  stb r12, 0xe(r3);
  lbz r12, 1(r30);
  stb r12, 0xf(r3);
  lbz r12, 0(r30);
  stb r12, 0x10(r3);
  lbzx r12, r31, r24;
  subfic r24, r23, 0xf;
  stb r12, 0x11(r3);
  lbzx r12, r31, r26;
  subfic r26, r25, 0xf;
  stb r12, 0x12(r3);
  lbzx r12, r31, r28;
  subfic r28, r27, 0xf;
  stb r12, 0x13(r3);
  lbzx r12, r31, r29;
  subfic r29, r0, 0xf;
  stb r12, 0x14(r3);
  lbzx r0, r31, r10;
  subfic r10, r11, 0xf;
  stb r0, 0x15(r3);
  lbzx r0, r31, r8;
  subfic r8, r9, 0xf;
  stb r0, 0x16(r3);
  lbzx r0, r31, r6;
  subfic r6, r7, 0xf;
  stb r0, 0x17(r3);
  lbzx r0, r31, r4;
  subfic r4, r5, 0xf;
  stb r0, 0x18(r3);
  lbzx r12, r31, r24;
  stb r12, 0x19(r3);
  lbzx r12, r31, r26;
  stb r12, 0x1a(r3);
  lbzx r12, r31, r28;
  stb r12, 0x1b(r3);
  lbzx r12, r31, r29;
  stb r12, 0x1c(r3);
  lbzx r0, r31, r10;
  stb r0, 0x1d(r3);
  lbzx r0, r31, r8;
  stb r0, 0x1e(r3);
  lbzx r0, r31, r6;
  stb r0, 0x1f(r3);
  lbzx r0, r31, r4;
  stb r0, 0x20(r3);
  bl btu_hcif_send_cmd;
  li r3, 1;
lbl_80144c18:
  addi r11, r1, 0x30;
  bl _restgpr_23;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: btsnd_hcic_link_key_neg_reply
// PAL: 0x80144c30..0x80144cd0
MARK_BINARY_BLOB(btsnd_hcic_link_key_neg_reply, 0x80144c30, 0x80144cd0);
asm UNKNOWN_FUNCTION(btsnd_hcic_link_key_neg_reply) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  li r3, 2;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  bne lbl_80144c5c;
  li r3, 0;
  b lbl_80144cbc;
lbl_80144c5c:
  li r0, 9;
  li r6, 0;
  sth r0, 2(r3);
  li r5, 0xc;
  li r4, 4;
  li r0, 6;
  sth r6, 4(r3);
  stb r5, 8(r3);
  stb r4, 9(r3);
  stb r0, 0xa(r3);
  lbz r0, 5(r31);
  stb r0, 0xb(r3);
  lbz r0, 4(r31);
  stb r0, 0xc(r3);
  lbz r0, 3(r31);
  stb r0, 0xd(r3);
  lbz r0, 2(r31);
  stb r0, 0xe(r3);
  lbz r0, 1(r31);
  stb r0, 0xf(r3);
  lbz r0, 0(r31);
  stb r0, 0x10(r3);
  bl btu_hcif_send_cmd;
  li r3, 1;
lbl_80144cbc:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: btsnd_hcic_pin_code_req_reply
// PAL: 0x80144cd0..0x80144eb4
MARK_BINARY_BLOB(btsnd_hcic_pin_code_req_reply, 0x80144cd0, 0x80144eb4);
asm UNKNOWN_FUNCTION(btsnd_hcic_pin_code_req_reply) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r5;
  stw r30, 0x18(r1);
  mr r30, r4;
  stw r29, 0x14(r1);
  mr r29, r3;
  li r3, 2;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  bne lbl_80144d0c;
  li r3, 0;
  b lbl_80144e98;
lbl_80144d0c:
  li r0, 0x1a;
  li r4, 0;
  sth r0, 2(r3);
  li r7, 0xd;
  li r6, 4;
  li r0, 0x17;
  sth r4, 4(r3);
  cmpwi cr1, r30, 0;
  addi r4, r3, 0x12;
  li r5, 0;
  stb r7, 8(r3);
  stb r6, 9(r3);
  stb r0, 0xa(r3);
  lbz r0, 5(r29);
  stb r0, 0xb(r3);
  lbz r0, 4(r29);
  stb r0, 0xc(r3);
  lbz r0, 3(r29);
  stb r0, 0xd(r3);
  lbz r0, 2(r29);
  stb r0, 0xe(r3);
  lbz r0, 1(r29);
  stb r0, 0xf(r3);
  lbz r0, 0(r29);
  stb r0, 0x10(r3);
  stb r30, 0x11(r3);
  ble cr1, lbl_80144e34;
  cmpwi r30, 8;
  addi r7, r30, -8;
  ble lbl_80144e0c;
  li r8, 0;
  blt cr1, lbl_80144da0;
  lis r6, 0x8000;
  addi r0, r6, -2;
  cmpw r30, r0;
  bgt lbl_80144da0;
  li r8, 1;
lbl_80144da0:
  cmpwi r8, 0;
  beq lbl_80144e0c;
  addi r0, r7, 7;
  srwi r0, r0, 3;
  mtctr r0;
  cmpwi r7, 0;
  ble lbl_80144e0c;
lbl_80144dbc:
  lbz r0, 0(r31);
  addi r5, r5, 8;
  stb r0, 0(r4);
  lbz r0, 1(r31);
  stb r0, 1(r4);
  lbz r0, 2(r31);
  stb r0, 2(r4);
  lbz r0, 3(r31);
  stb r0, 3(r4);
  lbz r0, 4(r31);
  stb r0, 4(r4);
  lbz r0, 5(r31);
  stb r0, 5(r4);
  lbz r0, 6(r31);
  stb r0, 6(r4);
  lbz r0, 7(r31);
  addi r31, r31, 8;
  stb r0, 7(r4);
  addi r4, r4, 8;
  bdnz lbl_80144dbc;
lbl_80144e0c:
  subf r0, r5, r30;
  mtctr r0;
  cmpw r5, r30;
  bge lbl_80144e34;
lbl_80144e1c:
  lbz r0, 0(r31);
  addi r5, r5, 1;
  addi r31, r31, 1;
  stb r0, 0(r4);
  addi r4, r4, 1;
  bdnz lbl_80144e1c;
lbl_80144e34:
  cmpwi r5, 0x10;
  subfic r5, r5, 0x10;
  li r6, 0;
  bge lbl_80144e90;
  rlwinm. r0, r5, 0x1d, 3, 0x1f;
  mtctr r0;
  beq lbl_80144e80;
lbl_80144e50:
  stb r6, 0(r4);
  stb r6, 1(r4);
  stb r6, 2(r4);
  stb r6, 3(r4);
  stb r6, 4(r4);
  stb r6, 5(r4);
  stb r6, 6(r4);
  stb r6, 7(r4);
  addi r4, r4, 8;
  bdnz lbl_80144e50;
  andi. r5, r5, 7;
  beq lbl_80144e90;
lbl_80144e80:
  mtctr r5;
lbl_80144e84:
  stb r6, 0(r4);
  addi r4, r4, 1;
  bdnz lbl_80144e84;
lbl_80144e90:
  bl btu_hcif_send_cmd;
  li r3, 1;
lbl_80144e98:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: btsnd_hcic_pin_code_neg_reply
// PAL: 0x80144eb4..0x80144f54
MARK_BINARY_BLOB(btsnd_hcic_pin_code_neg_reply, 0x80144eb4, 0x80144f54);
asm UNKNOWN_FUNCTION(btsnd_hcic_pin_code_neg_reply) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  li r3, 2;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  bne lbl_80144ee0;
  li r3, 0;
  b lbl_80144f40;
lbl_80144ee0:
  li r0, 9;
  li r6, 0;
  sth r0, 2(r3);
  li r5, 0xe;
  li r4, 4;
  li r0, 6;
  sth r6, 4(r3);
  stb r5, 8(r3);
  stb r4, 9(r3);
  stb r0, 0xa(r3);
  lbz r0, 5(r31);
  stb r0, 0xb(r3);
  lbz r0, 4(r31);
  stb r0, 0xc(r3);
  lbz r0, 3(r31);
  stb r0, 0xd(r3);
  lbz r0, 2(r31);
  stb r0, 0xe(r3);
  lbz r0, 1(r31);
  stb r0, 0xf(r3);
  lbz r0, 0(r31);
  stb r0, 0x10(r3);
  bl btu_hcif_send_cmd;
  li r3, 1;
lbl_80144f40:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: btsnd_hcic_change_conn_type
// PAL: 0x80144f54..0x80144fe4
MARK_BINARY_BLOB(btsnd_hcic_change_conn_type, 0x80144f54, 0x80144fe4);
asm UNKNOWN_FUNCTION(btsnd_hcic_change_conn_type) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  li r3, 2;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  bne lbl_80144f88;
  li r3, 0;
  b lbl_80144fcc;
lbl_80144f88:
  li r4, 7;
  li r0, 0;
  sth r4, 2(r3);
  li r6, 0xf;
  li r5, 4;
  srawi r4, r30, 8;
  sth r0, 4(r3);
  rlwinm r0, r31, 0x18, 0x18, 0x1f;
  stb r6, 8(r3);
  stb r5, 9(r3);
  stb r5, 0xa(r3);
  stb r30, 0xb(r3);
  stb r4, 0xc(r3);
  stb r31, 0xd(r3);
  stb r0, 0xe(r3);
  bl btu_hcif_send_cmd;
  li r3, 1;
lbl_80144fcc:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: btsnd_hcic_auth_request
// PAL: 0x80144fe4..0x80145060
MARK_BINARY_BLOB(btsnd_hcic_auth_request, 0x80144fe4, 0x80145060);
asm UNKNOWN_FUNCTION(btsnd_hcic_auth_request) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  li r3, 2;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  bne lbl_80145010;
  li r3, 0;
  b lbl_8014504c;
lbl_80145010:
  li r4, 5;
  li r0, 0;
  sth r4, 2(r3);
  li r6, 0x11;
  li r5, 4;
  li r4, 2;
  sth r0, 4(r3);
  rlwinm r0, r31, 0x18, 0x18, 0x1f;
  stb r6, 8(r3);
  stb r5, 9(r3);
  stb r4, 0xa(r3);
  stb r31, 0xb(r3);
  stb r0, 0xc(r3);
  bl btu_hcif_send_cmd;
  li r3, 1;
lbl_8014504c:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: btsnd_hcic_set_conn_encrypt
// PAL: 0x80145060..0x801450ec
MARK_BINARY_BLOB(btsnd_hcic_set_conn_encrypt, 0x80145060, 0x801450ec);
asm UNKNOWN_FUNCTION(btsnd_hcic_set_conn_encrypt) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  li r3, 2;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  bne lbl_80145094;
  li r3, 0;
  b lbl_801450d4;
lbl_80145094:
  li r4, 6;
  li r0, 0;
  sth r4, 2(r3);
  li r6, 0x13;
  li r5, 4;
  li r4, 3;
  sth r0, 4(r3);
  rlwinm r0, r30, 0x18, 0x18, 0x1f;
  stb r6, 8(r3);
  stb r5, 9(r3);
  stb r4, 0xa(r3);
  stb r30, 0xb(r3);
  stb r0, 0xc(r3);
  stb r31, 0xd(r3);
  bl btu_hcif_send_cmd;
  li r3, 1;
lbl_801450d4:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: btsnd_hcic_rmt_name_req
// PAL: 0x801450ec..0x801451c4
MARK_BINARY_BLOB(btsnd_hcic_rmt_name_req, 0x801450ec, 0x801451c4);
asm UNKNOWN_FUNCTION(btsnd_hcic_rmt_name_req) {
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
  bne lbl_80145130;
  li r3, 0;
  b lbl_801451a4;
lbl_80145130:
  li r4, 0xd;
  li r0, 0;
  sth r4, 2(r3);
  li r6, 0x19;
  li r5, 4;
  li r4, 0xa;
  sth r0, 4(r3);
  rlwinm r0, r31, 0x18, 0x18, 0x1f;
  stb r6, 8(r3);
  stb r5, 9(r3);
  stb r4, 0xa(r3);
  lbz r4, 5(r28);
  stb r4, 0xb(r3);
  lbz r4, 4(r28);
  stb r4, 0xc(r3);
  lbz r4, 3(r28);
  stb r4, 0xd(r3);
  lbz r4, 2(r28);
  stb r4, 0xe(r3);
  lbz r4, 1(r28);
  stb r4, 0xf(r3);
  lbz r4, 0(r28);
  stb r4, 0x10(r3);
  stb r29, 0x11(r3);
  stb r30, 0x12(r3);
  stb r31, 0x13(r3);
  stb r0, 0x14(r3);
  bl btu_hcif_send_cmd;
  li r3, 1;
lbl_801451a4:
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

// Symbol: btsnd_hcic_rmt_name_req_cancel
// PAL: 0x801451c4..0x80145264
MARK_BINARY_BLOB(btsnd_hcic_rmt_name_req_cancel, 0x801451c4, 0x80145264);
asm UNKNOWN_FUNCTION(btsnd_hcic_rmt_name_req_cancel) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  li r3, 2;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  bne lbl_801451f0;
  li r3, 0;
  b lbl_80145250;
lbl_801451f0:
  li r0, 9;
  li r6, 0;
  sth r0, 2(r3);
  li r5, 0x1a;
  li r4, 4;
  li r0, 6;
  sth r6, 4(r3);
  stb r5, 8(r3);
  stb r4, 9(r3);
  stb r0, 0xa(r3);
  lbz r0, 5(r31);
  stb r0, 0xb(r3);
  lbz r0, 4(r31);
  stb r0, 0xc(r3);
  lbz r0, 3(r31);
  stb r0, 0xd(r3);
  lbz r0, 2(r31);
  stb r0, 0xe(r3);
  lbz r0, 1(r31);
  stb r0, 0xf(r3);
  lbz r0, 0(r31);
  stb r0, 0x10(r3);
  bl btu_hcif_send_cmd;
  li r3, 1;
lbl_80145250:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: btsnd_hcic_rmt_features_req
// PAL: 0x80145264..0x801452e0
MARK_BINARY_BLOB(btsnd_hcic_rmt_features_req, 0x80145264, 0x801452e0);
asm UNKNOWN_FUNCTION(btsnd_hcic_rmt_features_req) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  li r3, 2;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  bne lbl_80145290;
  li r3, 0;
  b lbl_801452cc;
lbl_80145290:
  li r4, 5;
  li r0, 0;
  sth r4, 2(r3);
  li r6, 0x1b;
  li r5, 4;
  li r4, 2;
  sth r0, 4(r3);
  rlwinm r0, r31, 0x18, 0x18, 0x1f;
  stb r6, 8(r3);
  stb r5, 9(r3);
  stb r4, 0xa(r3);
  stb r31, 0xb(r3);
  stb r0, 0xc(r3);
  bl btu_hcif_send_cmd;
  li r3, 1;
lbl_801452cc:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: btsnd_hcic_rmt_ver_req
// PAL: 0x801452e0..0x8014535c
MARK_BINARY_BLOB(btsnd_hcic_rmt_ver_req, 0x801452e0, 0x8014535c);
asm UNKNOWN_FUNCTION(btsnd_hcic_rmt_ver_req) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  li r3, 2;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  bne lbl_8014530c;
  li r3, 0;
  b lbl_80145348;
lbl_8014530c:
  li r4, 5;
  li r0, 0;
  sth r4, 2(r3);
  li r6, 0x1d;
  li r5, 4;
  li r4, 2;
  sth r0, 4(r3);
  rlwinm r0, r31, 0x18, 0x18, 0x1f;
  stb r6, 8(r3);
  stb r5, 9(r3);
  stb r4, 0xa(r3);
  stb r31, 0xb(r3);
  stb r0, 0xc(r3);
  bl btu_hcif_send_cmd;
  li r3, 1;
lbl_80145348:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: btsnd_hcic_read_rmt_clk_offset
// PAL: 0x8014535c..0x801453d8
MARK_BINARY_BLOB(btsnd_hcic_read_rmt_clk_offset, 0x8014535c, 0x801453d8);
asm UNKNOWN_FUNCTION(btsnd_hcic_read_rmt_clk_offset) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  li r3, 2;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  bne lbl_80145388;
  li r3, 0;
  b lbl_801453c4;
lbl_80145388:
  li r4, 5;
  li r0, 0;
  sth r4, 2(r3);
  li r6, 0x1f;
  li r5, 4;
  li r4, 2;
  sth r0, 4(r3);
  rlwinm r0, r31, 0x18, 0x18, 0x1f;
  stb r6, 8(r3);
  stb r5, 9(r3);
  stb r4, 0xa(r3);
  stb r31, 0xb(r3);
  stb r0, 0xc(r3);
  bl btu_hcif_send_cmd;
  li r3, 1;
lbl_801453c4:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: btsnd_hcic_setup_esco_conn
// PAL: 0x801453d8..0x801454d4
MARK_BINARY_BLOB(btsnd_hcic_setup_esco_conn, 0x801453d8, 0x801454d4);
asm UNKNOWN_FUNCTION(btsnd_hcic_setup_esco_conn) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_25;
  mr r25, r3;
  mr r26, r4;
  mr r27, r5;
  mr r28, r6;
  mr r29, r7;
  mr r30, r8;
  mr r31, r9;
  li r3, 2;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  bne lbl_80145420;
  li r3, 0;
  b lbl_801454bc;
lbl_80145420:
  li r0, 0x14;
  srawi r12, r25, 8;
  sth r0, 2(r3);
  li r0, 0;
  li r6, 0x28;
  li r4, 4;
  sth r0, 4(r3);
  li r0, 0x11;
  rlwinm r11, r26, 0x18, 0x18, 0x1f;
  rlwinm r10, r26, 0x10, 0x18, 0x1f;
  stb r6, 8(r3);
  srwi r9, r26, 0x18;
  rlwinm r8, r27, 0x18, 0x18, 0x1f;
  rlwinm r7, r27, 0x10, 0x18, 0x1f;
  stb r4, 9(r3);
  srawi r5, r28, 8;
  srwi r6, r27, 0x18;
  srawi r4, r29, 8;
  stb r0, 0xa(r3);
  rlwinm r0, r31, 0x18, 0x18, 0x1f;
  stb r25, 0xb(r3);
  stb r12, 0xc(r3);
  stb r26, 0xd(r3);
  stb r11, 0xe(r3);
  stb r10, 0xf(r3);
  stb r9, 0x10(r3);
  stb r27, 0x11(r3);
  stb r8, 0x12(r3);
  stb r7, 0x13(r3);
  stb r6, 0x14(r3);
  stb r28, 0x15(r3);
  stb r5, 0x16(r3);
  stb r29, 0x17(r3);
  stb r4, 0x18(r3);
  stb r30, 0x19(r3);
  stb r31, 0x1a(r3);
  stb r0, 0x1b(r3);
  bl btu_hcif_send_cmd;
  li r3, 1;
lbl_801454bc:
  addi r11, r1, 0x30;
  bl _restgpr_25;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: btsnd_hcic_accept_esco_conn
// PAL: 0x801454d4..0x801455bc
MARK_BINARY_BLOB(btsnd_hcic_accept_esco_conn, 0x801454d4, 0x801455bc);
asm UNKNOWN_FUNCTION(btsnd_hcic_accept_esco_conn) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_25;
  li r26, 0x18;
  li r12, 0;
  li r11, 0x29;
  li r0, 4;
  li r25, 0x15;
  sth r26, 2(r3);
  rlwinm r26, r5, 0x18, 0x18, 0x1f;
  rlwinm r27, r5, 0x10, 0x18, 0x1f;
  sth r12, 4(r3);
  srwi r28, r5, 0x18;
  rlwinm r29, r6, 0x18, 0x18, 0x1f;
  rlwinm r30, r6, 0x10, 0x18, 0x1f;
  stb r11, 8(r3);
  srwi r31, r6, 0x18;
  srawi r12, r7, 8;
  rlwinm r11, r8, 0x18, 0x18, 0x1f;
  stb r0, 9(r3);
  rlwinm r0, r10, 0x18, 0x18, 0x1f;
  stb r25, 0xa(r3);
  lbz r25, 5(r4);
  stb r25, 0xb(r3);
  lbz r25, 4(r4);
  stb r25, 0xc(r3);
  lbz r25, 3(r4);
  stb r25, 0xd(r3);
  lbz r25, 2(r4);
  stb r25, 0xe(r3);
  lbz r25, 1(r4);
  stb r25, 0xf(r3);
  lbz r4, 0(r4);
  stb r4, 0x10(r3);
  stb r5, 0x11(r3);
  stb r26, 0x12(r3);
  stb r27, 0x13(r3);
  stb r28, 0x14(r3);
  stb r6, 0x15(r3);
  stb r29, 0x16(r3);
  stb r30, 0x17(r3);
  stb r31, 0x18(r3);
  stb r7, 0x19(r3);
  stb r12, 0x1a(r3);
  stb r8, 0x1b(r3);
  stb r11, 0x1c(r3);
  stb r9, 0x1d(r3);
  stb r10, 0x1e(r3);
  stb r0, 0x1f(r3);
  bl btu_hcif_send_cmd;
  addi r11, r1, 0x30;
  bl _restgpr_25;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: btsnd_hcic_reject_esco_conn
// PAL: 0x801455bc..0x8014561c
MARK_BINARY_BLOB(btsnd_hcic_reject_esco_conn, 0x801455bc, 0x8014561c);
asm UNKNOWN_FUNCTION(btsnd_hcic_reject_esco_conn) {
  // clang-format off
  nofralloc;
  li r9, 0xa;
  li r8, 0;
  li r7, 0x2a;
  li r6, 4;
  li r0, 7;
  sth r9, 2(r3);
  sth r8, 4(r3);
  stb r7, 8(r3);
  stb r6, 9(r3);
  stb r0, 0xa(r3);
  lbz r0, 5(r4);
  stb r0, 0xb(r3);
  lbz r0, 4(r4);
  stb r0, 0xc(r3);
  lbz r0, 3(r4);
  stb r0, 0xd(r3);
  lbz r0, 2(r4);
  stb r0, 0xe(r3);
  lbz r0, 1(r4);
  stb r0, 0xf(r3);
  lbz r0, 0(r4);
  stb r0, 0x10(r3);
  stb r5, 0x11(r3);
  b btu_hcif_send_cmd;
  // clang-format on
}

// Symbol: btsnd_hcic_hold_mode
// PAL: 0x8014561c..0x801456d0
MARK_BINARY_BLOB(btsnd_hcic_hold_mode, 0x8014561c, 0x801456d0);
asm UNKNOWN_FUNCTION(btsnd_hcic_hold_mode) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  cmpwi r3, 0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r6;
  stw r30, 0x18(r1);
  mr r30, r5;
  stw r29, 0x14(r1);
  mr r29, r4;
  bne lbl_80145660;
  li r3, 2;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  bne lbl_80145660;
  li r3, 0;
  b lbl_801456b4;
lbl_80145660:
  li r0, 9;
  srawi r5, r29, 8;
  sth r0, 2(r3);
  li r0, 0;
  li r8, 1;
  li r7, 8;
  sth r0, 4(r3);
  li r6, 6;
  srawi r4, r30, 8;
  rlwinm r0, r31, 0x18, 0x18, 0x1f;
  stb r8, 8(r3);
  stb r7, 9(r3);
  stb r6, 0xa(r3);
  stb r29, 0xb(r3);
  stb r5, 0xc(r3);
  stb r30, 0xd(r3);
  stb r4, 0xe(r3);
  stb r31, 0xf(r3);
  stb r0, 0x10(r3);
  bl btu_hcif_send_cmd;
  li r3, 1;
lbl_801456b4:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: btsnd_hcic_sniff_mode
// PAL: 0x801456d0..0x8014579c
MARK_BINARY_BLOB(btsnd_hcic_sniff_mode, 0x801456d0, 0x8014579c);
asm UNKNOWN_FUNCTION(btsnd_hcic_sniff_mode) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_27;
  cmpwi r3, 0;
  mr r27, r4;
  mr r28, r5;
  mr r29, r6;
  mr r30, r7;
  mr r31, r8;
  bne lbl_80145718;
  li r3, 2;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  bne lbl_80145718;
  li r3, 0;
  b lbl_80145784;
lbl_80145718:
  li r0, 0xd;
  srawi r7, r27, 8;
  sth r0, 2(r3);
  li r4, 0;
  srawi r6, r28, 8;
  li r0, 3;
  sth r4, 4(r3);
  srawi r5, r29, 8;
  li r9, 8;
  li r8, 0xa;
  stb r0, 8(r3);
  srawi r4, r30, 8;
  rlwinm r0, r31, 0x18, 0x18, 0x1f;
  stb r9, 9(r3);
  stb r8, 0xa(r3);
  stb r27, 0xb(r3);
  stb r7, 0xc(r3);
  stb r28, 0xd(r3);
  stb r6, 0xe(r3);
  stb r29, 0xf(r3);
  stb r5, 0x10(r3);
  stb r30, 0x11(r3);
  stb r4, 0x12(r3);
  stb r31, 0x13(r3);
  stb r0, 0x14(r3);
  bl btu_hcif_send_cmd;
  li r3, 1;
lbl_80145784:
  addi r11, r1, 0x20;
  bl _restgpr_27;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: btsnd_hcic_exit_sniff_mode
// PAL: 0x8014579c..0x80145820
MARK_BINARY_BLOB(btsnd_hcic_exit_sniff_mode, 0x8014579c, 0x80145820);
asm UNKNOWN_FUNCTION(btsnd_hcic_exit_sniff_mode) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmpwi r3, 0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  bne lbl_801457d0;
  li r3, 2;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  bne lbl_801457d0;
  li r3, 0;
  b lbl_8014580c;
lbl_801457d0:
  li r4, 5;
  li r0, 0;
  sth r4, 2(r3);
  li r6, 4;
  li r5, 8;
  li r4, 2;
  sth r0, 4(r3);
  rlwinm r0, r31, 0x18, 0x18, 0x1f;
  stb r6, 8(r3);
  stb r5, 9(r3);
  stb r4, 0xa(r3);
  stb r31, 0xb(r3);
  stb r0, 0xc(r3);
  bl btu_hcif_send_cmd;
  li r3, 1;
lbl_8014580c:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: btsnd_hcic_park_mode
// PAL: 0x80145820..0x801458d4
MARK_BINARY_BLOB(btsnd_hcic_park_mode, 0x80145820, 0x801458d4);
asm UNKNOWN_FUNCTION(btsnd_hcic_park_mode) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  cmpwi r3, 0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r6;
  stw r30, 0x18(r1);
  mr r30, r5;
  stw r29, 0x14(r1);
  mr r29, r4;
  bne lbl_80145864;
  li r3, 2;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  bne lbl_80145864;
  li r3, 0;
  b lbl_801458b8;
lbl_80145864:
  li r0, 9;
  srawi r5, r29, 8;
  sth r0, 2(r3);
  li r0, 0;
  li r8, 5;
  li r7, 8;
  sth r0, 4(r3);
  li r6, 6;
  srawi r4, r30, 8;
  rlwinm r0, r31, 0x18, 0x18, 0x1f;
  stb r8, 8(r3);
  stb r7, 9(r3);
  stb r6, 0xa(r3);
  stb r29, 0xb(r3);
  stb r5, 0xc(r3);
  stb r30, 0xd(r3);
  stb r4, 0xe(r3);
  stb r31, 0xf(r3);
  stb r0, 0x10(r3);
  bl btu_hcif_send_cmd;
  li r3, 1;
lbl_801458b8:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: btsnd_hcic_exit_park_mode
// PAL: 0x801458d4..0x80145958
MARK_BINARY_BLOB(btsnd_hcic_exit_park_mode, 0x801458d4, 0x80145958);
asm UNKNOWN_FUNCTION(btsnd_hcic_exit_park_mode) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmpwi r3, 0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  bne lbl_80145908;
  li r3, 2;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  bne lbl_80145908;
  li r3, 0;
  b lbl_80145944;
lbl_80145908:
  li r4, 5;
  li r0, 0;
  sth r4, 2(r3);
  li r6, 6;
  li r5, 8;
  li r4, 2;
  sth r0, 4(r3);
  rlwinm r0, r31, 0x18, 0x18, 0x1f;
  stb r6, 8(r3);
  stb r5, 9(r3);
  stb r4, 0xa(r3);
  stb r31, 0xb(r3);
  stb r0, 0xc(r3);
  bl btu_hcif_send_cmd;
  li r3, 1;
lbl_80145944:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: btsnd_hcic_switch_role
// PAL: 0x80145958..0x80145a08
MARK_BINARY_BLOB(btsnd_hcic_switch_role, 0x80145958, 0x80145a08);
asm UNKNOWN_FUNCTION(btsnd_hcic_switch_role) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  li r3, 2;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  bne lbl_8014598c;
  li r3, 0;
  b lbl_801459f0;
lbl_8014598c:
  li r0, 0xa;
  li r6, 0;
  sth r0, 2(r3);
  li r5, 0xb;
  li r4, 8;
  li r0, 7;
  sth r6, 4(r3);
  stb r5, 8(r3);
  stb r4, 9(r3);
  stb r0, 0xa(r3);
  lbz r0, 5(r30);
  stb r0, 0xb(r3);
  lbz r0, 4(r30);
  stb r0, 0xc(r3);
  lbz r0, 3(r30);
  stb r0, 0xd(r3);
  lbz r0, 2(r30);
  stb r0, 0xe(r3);
  lbz r0, 1(r30);
  stb r0, 0xf(r3);
  lbz r0, 0(r30);
  stb r0, 0x10(r3);
  stb r31, 0x11(r3);
  bl btu_hcif_send_cmd;
  li r3, 1;
lbl_801459f0:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: btsnd_hcic_write_policy_set
// PAL: 0x80145a08..0x80145a9c
MARK_BINARY_BLOB(btsnd_hcic_write_policy_set, 0x80145a08, 0x80145a9c);
asm UNKNOWN_FUNCTION(btsnd_hcic_write_policy_set) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  li r3, 2;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  bne lbl_80145a3c;
  li r3, 0;
  b lbl_80145a84;
lbl_80145a3c:
  li r4, 7;
  li r0, 0;
  sth r4, 2(r3);
  li r7, 0xd;
  li r6, 8;
  li r5, 4;
  sth r0, 4(r3);
  srawi r4, r30, 8;
  rlwinm r0, r31, 0x18, 0x18, 0x1f;
  stb r7, 8(r3);
  stb r6, 9(r3);
  stb r5, 0xa(r3);
  stb r30, 0xb(r3);
  stb r4, 0xc(r3);
  stb r31, 0xd(r3);
  stb r0, 0xe(r3);
  bl btu_hcif_send_cmd;
  li r3, 1;
lbl_80145a84:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: btsnd_hcic_reset
// PAL: 0x80145a9c..0x80145af8
MARK_BINARY_BLOB(btsnd_hcic_reset, 0x80145a9c, 0x80145af8);
asm UNKNOWN_FUNCTION(btsnd_hcic_reset) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  li r3, 2;
  stw r0, 0x14(r1);
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  bne lbl_80145ac0;
  li r3, 0;
  b lbl_80145ae8;
lbl_80145ac0:
  li r5, 3;
  li r4, 0;
  sth r5, 2(r3);
  li r0, 0xc;
  sth r4, 4(r3);
  stb r5, 8(r3);
  stb r0, 9(r3);
  stb r4, 0xa(r3);
  bl btu_hcif_send_cmd;
  li r3, 1;
lbl_80145ae8:
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: btsnd_hcic_set_event_filter
// PAL: 0x80145af8..0x80145cb4
MARK_BINARY_BLOB(btsnd_hcic_set_event_filter, 0x80145af8, 0x80145cb4);
asm UNKNOWN_FUNCTION(btsnd_hcic_set_event_filter) {
  // clang-format off
  nofralloc;
  li r0, 0;
  li r9, 5;
  li r8, 0xc;
  sth r0, 4(r3);
  cmpwi r4, 0;
  mr r0, r6;
  stb r9, 8(r3);
  stb r8, 9(r3);
  beq lbl_80145c9c;
  addi r8, r7, 5;
  addi r9, r7, 2;
  sth r8, 2(r3);
  cmplwi r5, 1;
  addi r8, r3, 0xd;
  stb r9, 0xa(r3);
  stb r4, 0xb(r3);
  stb r5, 0xc(r3);
  bne lbl_80145b84;
  lbz r4, 2(r6);
  addi r0, r7, -6;
  clrlwi r7, r0, 0x18;
  stb r4, 0(r8);
  addi r0, r6, 6;
  lbz r4, 1(r6);
  stb r4, 1(r8);
  lbz r4, 0(r6);
  stb r4, 2(r8);
  lbz r4, 5(r6);
  stb r4, 3(r8);
  lbz r4, 4(r6);
  stb r4, 4(r8);
  lbz r4, 3(r6);
  stb r4, 5(r8);
  addi r8, r8, 6;
  b lbl_80145bcc;
lbl_80145b84:
  cmplwi r5, 2;
  bne lbl_80145bcc;
  lbz r4, 5(r6);
  addi r0, r7, -6;
  clrlwi r7, r0, 0x18;
  stb r4, 0(r8);
  addi r0, r6, 6;
  lbz r4, 4(r6);
  stb r4, 1(r8);
  lbz r4, 3(r6);
  stb r4, 2(r8);
  lbz r4, 2(r6);
  stb r4, 3(r8);
  lbz r4, 1(r6);
  stb r4, 4(r8);
  lbz r4, 0(r6);
  stb r4, 5(r8);
  addi r8, r8, 6;
lbl_80145bcc:
  cmpwi cr1, r7, 0;
  beq cr1, lbl_80145cb0;
  li r9, 0;
  ble cr1, lbl_80145cb0;
  cmpwi r7, 8;
  addi r5, r7, -8;
  ble lbl_80145c70;
  li r6, 0;
  blt cr1, lbl_80145c04;
  lis r4, 0x8000;
  addi r4, r4, -2;
  cmpw r7, r4;
  bgt lbl_80145c04;
  li r6, 1;
lbl_80145c04:
  cmpwi r6, 0;
  beq lbl_80145c70;
  addi r4, r5, 7;
  srwi r4, r4, 3;
  mtctr r4;
  cmpwi r5, 0;
  ble lbl_80145c70;
lbl_80145c20:
  lbzx r4, r9, r0;
  add r5, r0, r9;
  addi r9, r9, 8;
  stb r4, 0(r8);
  lbz r4, 1(r5);
  stb r4, 1(r8);
  lbz r4, 2(r5);
  stb r4, 2(r8);
  lbz r4, 3(r5);
  stb r4, 3(r8);
  lbz r4, 4(r5);
  stb r4, 4(r8);
  lbz r4, 5(r5);
  stb r4, 5(r8);
  lbz r4, 6(r5);
  stb r4, 6(r8);
  lbz r4, 7(r5);
  stb r4, 7(r8);
  addi r8, r8, 8;
  bdnz lbl_80145c20;
lbl_80145c70:
  subf r4, r9, r7;
  add r5, r0, r9;
  mtctr r4;
  cmpw r9, r7;
  bge lbl_80145cb0;
lbl_80145c84:
  lbz r0, 0(r5);
  addi r5, r5, 1;
  stb r0, 0(r8);
  addi r8, r8, 1;
  bdnz lbl_80145c84;
  b lbl_80145cb0;
lbl_80145c9c:
  li r5, 4;
  li r0, 1;
  sth r5, 2(r3);
  stb r0, 0xa(r3);
  stb r4, 0xb(r3);
lbl_80145cb0:
  b btu_hcif_send_cmd;
  // clang-format on
}

// Symbol: btsnd_hcic_write_pin_type
// PAL: 0x80145cb4..0x80145d28
MARK_BINARY_BLOB(btsnd_hcic_write_pin_type, 0x80145cb4, 0x80145d28);
asm UNKNOWN_FUNCTION(btsnd_hcic_write_pin_type) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  li r3, 2;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  bne lbl_80145ce0;
  li r3, 0;
  b lbl_80145d14;
lbl_80145ce0:
  li r0, 4;
  li r6, 0;
  sth r0, 2(r3);
  li r5, 0xa;
  li r4, 0xc;
  li r0, 1;
  sth r6, 4(r3);
  stb r5, 8(r3);
  stb r4, 9(r3);
  stb r0, 0xa(r3);
  stb r31, 0xb(r3);
  bl btu_hcif_send_cmd;
  li r3, 1;
lbl_80145d14:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: btsnd_hcic_read_stored_key
// PAL: 0x80145d28..0x80145d88
MARK_BINARY_BLOB(btsnd_hcic_read_stored_key, 0x80145d28, 0x80145d88);
asm UNKNOWN_FUNCTION(btsnd_hcic_read_stored_key) {
  // clang-format off
  nofralloc;
  li r9, 0xa;
  li r8, 0;
  li r7, 0xd;
  li r6, 0xc;
  li r0, 7;
  sth r9, 2(r3);
  sth r8, 4(r3);
  stb r7, 8(r3);
  stb r6, 9(r3);
  stb r0, 0xa(r3);
  lbz r0, 5(r4);
  stb r0, 0xb(r3);
  lbz r0, 4(r4);
  stb r0, 0xc(r3);
  lbz r0, 3(r4);
  stb r0, 0xd(r3);
  lbz r0, 2(r4);
  stb r0, 0xe(r3);
  lbz r0, 1(r4);
  stb r0, 0xf(r3);
  lbz r0, 0(r4);
  stb r0, 0x10(r3);
  stb r5, 0x11(r3);
  b btu_hcif_send_cmd;
  // clang-format on
}

// Symbol: btsnd_hcic_write_stored_key
// PAL: 0x80145d88..0x80145f48
MARK_BINARY_BLOB(btsnd_hcic_write_stored_key, 0x80145d88, 0x80145f48);
asm UNKNOWN_FUNCTION(btsnd_hcic_write_stored_key) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_22;
  mulli r7, r4, 0x16;
  li r0, 0;
  li r9, 0x11;
  sth r0, 4(r3);
  li r8, 0xc;
  addi r10, r7, 4;
  clrlwi r7, r10, 0x10;
  cmplwi r4, 0xb;
  addi r0, r7, -3;
  sth r10, 2(r3);
  stb r9, 8(r3);
  stb r8, 9(r3);
  stb r0, 0xa(r3);
  ble lbl_80145dd8;
  li r4, 0xb;
lbl_80145dd8:
  stb r4, 0xb(r3);
  addi r7, r3, 0xc;
  mtctr r4;
  cmpwi r4, 0;
  ble lbl_80145f2c;
lbl_80145dec:
  lbz r0, 5(r5);
  li r22, 0;
  subfic r23, r22, 0xf;
  li r24, 1;
  stb r0, 0(r7);
  subfic r25, r24, 0xf;
  li r26, 2;
  li r28, 3;
  lbz r0, 4(r5);
  subfic r27, r26, 0xf;
  subfic r29, r28, 0xf;
  li r30, 4;
  stb r0, 1(r7);
  subfic r31, r30, 0xf;
  li r12, 5;
  li r10, 6;
  lbz r0, 3(r5);
  subfic r11, r12, 0xf;
  subfic r9, r10, 0xf;
  li r8, 7;
  stb r0, 2(r7);
  subfic r4, r8, 0xf;
  li r22, 8;
  li r24, 9;
  lbz r0, 2(r5);
  li r26, 0xa;
  li r28, 0xb;
  li r30, 0xc;
  stb r0, 3(r7);
  li r12, 0xd;
  li r10, 0xe;
  li r8, 0xf;
  lbz r0, 1(r5);
  stb r0, 4(r7);
  lbz r0, 0(r5);
  addi r5, r5, 6;
  stb r0, 5(r7);
  lbzx r0, r6, r23;
  subfic r23, r22, 0xf;
  stb r0, 6(r7);
  lbzx r0, r6, r25;
  subfic r25, r24, 0xf;
  stb r0, 7(r7);
  lbzx r0, r6, r27;
  subfic r27, r26, 0xf;
  stb r0, 8(r7);
  lbzx r0, r6, r29;
  subfic r29, r28, 0xf;
  stb r0, 9(r7);
  lbzx r0, r6, r31;
  subfic r31, r30, 0xf;
  stb r0, 0xa(r7);
  lbzx r0, r6, r11;
  subfic r11, r12, 0xf;
  stb r0, 0xb(r7);
  lbzx r0, r6, r9;
  subfic r9, r10, 0xf;
  stb r0, 0xc(r7);
  lbzx r0, r6, r4;
  subfic r4, r8, 0xf;
  stb r0, 0xd(r7);
  lbzx r0, r6, r23;
  stb r0, 0xe(r7);
  lbzx r0, r6, r25;
  stb r0, 0xf(r7);
  lbzx r0, r6, r27;
  stb r0, 0x10(r7);
  lbzx r0, r6, r29;
  stb r0, 0x11(r7);
  lbzx r0, r6, r31;
  stb r0, 0x12(r7);
  lbzx r0, r6, r11;
  stb r0, 0x13(r7);
  lbzx r0, r6, r9;
  stb r0, 0x14(r7);
  lbzx r0, r6, r4;
  addi r6, r6, 0x10;
  stb r0, 0x15(r7);
  addi r7, r7, 0x16;
  bdnz lbl_80145dec;
lbl_80145f2c:
  bl btu_hcif_send_cmd;
  addi r11, r1, 0x30;
  bl _restgpr_22;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: btsnd_hcic_delete_stored_key
// PAL: 0x80145f48..0x80145ff8
MARK_BINARY_BLOB(btsnd_hcic_delete_stored_key, 0x80145f48, 0x80145ff8);
asm UNKNOWN_FUNCTION(btsnd_hcic_delete_stored_key) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  li r3, 2;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  bne lbl_80145f7c;
  li r3, 0;
  b lbl_80145fe0;
lbl_80145f7c:
  li r0, 0xa;
  li r6, 0;
  sth r0, 2(r3);
  li r5, 0x12;
  li r4, 0xc;
  li r0, 7;
  sth r6, 4(r3);
  stb r5, 8(r3);
  stb r4, 9(r3);
  stb r0, 0xa(r3);
  lbz r0, 5(r30);
  stb r0, 0xb(r3);
  lbz r0, 4(r30);
  stb r0, 0xc(r3);
  lbz r0, 3(r30);
  stb r0, 0xd(r3);
  lbz r0, 2(r30);
  stb r0, 0xe(r3);
  lbz r0, 1(r30);
  stb r0, 0xf(r3);
  lbz r0, 0(r30);
  stb r0, 0x10(r3);
  stb r31, 0x11(r3);
  bl btu_hcif_send_cmd;
  li r3, 1;
lbl_80145fe0:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: btsnd_hcic_change_name
// PAL: 0x80145ff8..0x80146138
MARK_BINARY_BLOB(btsnd_hcic_change_name, 0x80145ff8, 0x80146138);
asm UNKNOWN_FUNCTION(btsnd_hcic_change_name) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  stw r30, 8(r1);
  mr r30, r4;
  mr r3, r30;
  bl strlen;
  addi r0, r3, 1;
  li r6, 0xfb;
  clrlwi r7, r0, 0x10;
  li r5, 0;
  li r4, 0x13;
  li r3, 0xc;
  li r0, 0xf8;
  sth r6, 2(r31);
  cmpwi cr1, r7, 0;
  addi r6, r31, 0xb;
  sth r5, 4(r31);
  li r8, 0;
  stb r4, 8(r31);
  stb r3, 9(r31);
  stb r0, 0xa(r31);
  ble cr1, lbl_80146118;
  cmpwi r7, 8;
  addi r4, r7, -8;
  ble lbl_801460f0;
  li r5, 0;
  blt cr1, lbl_80146084;
  lis r3, 0x8000;
  addi r0, r3, -2;
  cmpw r7, r0;
  bgt lbl_80146084;
  li r5, 1;
lbl_80146084:
  cmpwi r5, 0;
  beq lbl_801460f0;
  addi r0, r4, 7;
  srwi r0, r0, 3;
  mtctr r0;
  cmpwi r4, 0;
  ble lbl_801460f0;
lbl_801460a0:
  lbzx r0, r30, r8;
  add r3, r30, r8;
  addi r8, r8, 8;
  stb r0, 0(r6);
  lbz r0, 1(r3);
  stb r0, 1(r6);
  lbz r0, 2(r3);
  stb r0, 2(r6);
  lbz r0, 3(r3);
  stb r0, 3(r6);
  lbz r0, 4(r3);
  stb r0, 4(r6);
  lbz r0, 5(r3);
  stb r0, 5(r6);
  lbz r0, 6(r3);
  stb r0, 6(r6);
  lbz r0, 7(r3);
  stb r0, 7(r6);
  addi r6, r6, 8;
  bdnz lbl_801460a0;
lbl_801460f0:
  subf r0, r8, r7;
  add r3, r30, r8;
  mtctr r0;
  cmpw r8, r7;
  bge lbl_80146118;
lbl_80146104:
  lbz r0, 0(r3);
  addi r3, r3, 1;
  stb r0, 0(r6);
  addi r6, r6, 1;
  bdnz lbl_80146104;
lbl_80146118:
  mr r3, r31;
  bl btu_hcif_send_cmd;
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: btsnd_hcic_write_page_tout
// PAL: 0x80146138..0x80146170
MARK_BINARY_BLOB(btsnd_hcic_write_page_tout, 0x80146138, 0x80146170);
asm UNKNOWN_FUNCTION(btsnd_hcic_write_page_tout) {
  // clang-format off
  nofralloc;
  rlwinm r0, r4, 0x18, 0x18, 0x1f;
  li r9, 5;
  li r8, 0;
  li r7, 0x18;
  li r6, 0xc;
  li r5, 2;
  sth r9, 2(r3);
  sth r8, 4(r3);
  stb r7, 8(r3);
  stb r6, 9(r3);
  stb r5, 0xa(r3);
  stb r4, 0xb(r3);
  stb r0, 0xc(r3);
  b btu_hcif_send_cmd;
  // clang-format on
}

// Symbol: btsnd_hcic_write_scan_enable
// PAL: 0x80146170..0x801461a0
MARK_BINARY_BLOB(btsnd_hcic_write_scan_enable, 0x80146170, 0x801461a0);
asm UNKNOWN_FUNCTION(btsnd_hcic_write_scan_enable) {
  // clang-format off
  nofralloc;
  li r8, 4;
  li r7, 0;
  li r6, 0x1a;
  li r5, 0xc;
  li r0, 1;
  sth r8, 2(r3);
  sth r7, 4(r3);
  stb r6, 8(r3);
  stb r5, 9(r3);
  stb r0, 0xa(r3);
  stb r4, 0xb(r3);
  b btu_hcif_send_cmd;
  // clang-format on
}

// Symbol: btsnd_hcic_write_pagescan_cfg
// PAL: 0x801461a0..0x801461e4
MARK_BINARY_BLOB(btsnd_hcic_write_pagescan_cfg, 0x801461a0, 0x801461e4);
asm UNKNOWN_FUNCTION(btsnd_hcic_write_pagescan_cfg) {
  // clang-format off
  nofralloc;
  rlwinm r6, r4, 0x18, 0x18, 0x1f;
  rlwinm r0, r5, 0x18, 0x18, 0x1f;
  li r11, 7;
  li r10, 0;
  li r9, 0x1c;
  li r8, 0xc;
  li r7, 4;
  sth r11, 2(r3);
  sth r10, 4(r3);
  stb r9, 8(r3);
  stb r8, 9(r3);
  stb r7, 0xa(r3);
  stb r4, 0xb(r3);
  stb r6, 0xc(r3);
  stb r5, 0xd(r3);
  stb r0, 0xe(r3);
  b btu_hcif_send_cmd;
  // clang-format on
}

// Symbol: btsnd_hcic_write_inqscan_cfg
// PAL: 0x801461e4..0x80146228
MARK_BINARY_BLOB(btsnd_hcic_write_inqscan_cfg, 0x801461e4, 0x80146228);
asm UNKNOWN_FUNCTION(btsnd_hcic_write_inqscan_cfg) {
  // clang-format off
  nofralloc;
  rlwinm r6, r4, 0x18, 0x18, 0x1f;
  rlwinm r0, r5, 0x18, 0x18, 0x1f;
  li r11, 7;
  li r10, 0;
  li r9, 0x1e;
  li r8, 0xc;
  li r7, 4;
  sth r11, 2(r3);
  sth r10, 4(r3);
  stb r9, 8(r3);
  stb r8, 9(r3);
  stb r7, 0xa(r3);
  stb r4, 0xb(r3);
  stb r6, 0xc(r3);
  stb r5, 0xd(r3);
  stb r0, 0xe(r3);
  b btu_hcif_send_cmd;
  // clang-format on
}

// Symbol: btsnd_hcic_write_auth_enable
// PAL: 0x80146228..0x8014629c
MARK_BINARY_BLOB(btsnd_hcic_write_auth_enable, 0x80146228, 0x8014629c);
asm UNKNOWN_FUNCTION(btsnd_hcic_write_auth_enable) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  li r3, 2;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  bne lbl_80146254;
  li r3, 0;
  b lbl_80146288;
lbl_80146254:
  li r0, 4;
  li r6, 0;
  sth r0, 2(r3);
  li r5, 0x20;
  li r4, 0xc;
  li r0, 1;
  sth r6, 4(r3);
  stb r5, 8(r3);
  stb r4, 9(r3);
  stb r0, 0xa(r3);
  stb r31, 0xb(r3);
  bl btu_hcif_send_cmd;
  li r3, 1;
lbl_80146288:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: btsnd_hcic_write_encr_mode
// PAL: 0x8014629c..0x80146310
MARK_BINARY_BLOB(btsnd_hcic_write_encr_mode, 0x8014629c, 0x80146310);
asm UNKNOWN_FUNCTION(btsnd_hcic_write_encr_mode) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  li r3, 2;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  bne lbl_801462c8;
  li r3, 0;
  b lbl_801462fc;
lbl_801462c8:
  li r0, 4;
  li r6, 0;
  sth r0, 2(r3);
  li r5, 0x22;
  li r4, 0xc;
  li r0, 1;
  sth r6, 4(r3);
  stb r5, 8(r3);
  stb r4, 9(r3);
  stb r0, 0xa(r3);
  stb r31, 0xb(r3);
  bl btu_hcif_send_cmd;
  li r3, 1;
lbl_801462fc:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: btsnd_hcic_write_dev_class
// PAL: 0x80146310..0x80146354
MARK_BINARY_BLOB(btsnd_hcic_write_dev_class, 0x80146310, 0x80146354);
asm UNKNOWN_FUNCTION(btsnd_hcic_write_dev_class) {
  // clang-format off
  nofralloc;
  li r8, 6;
  li r7, 0;
  li r6, 0x24;
  li r5, 0xc;
  li r0, 3;
  sth r8, 2(r3);
  sth r7, 4(r3);
  stb r6, 8(r3);
  stb r5, 9(r3);
  stb r0, 0xa(r3);
  lbz r0, 2(r4);
  stb r0, 0xb(r3);
  lbz r0, 1(r4);
  stb r0, 0xc(r3);
  lbz r0, 0(r4);
  stb r0, 0xd(r3);
  b btu_hcif_send_cmd;
  // clang-format on
}

// Symbol: btsnd_hcic_write_auto_flush_tout
// PAL: 0x80146354..0x80146398
MARK_BINARY_BLOB(btsnd_hcic_write_auto_flush_tout, 0x80146354, 0x80146398);
asm UNKNOWN_FUNCTION(btsnd_hcic_write_auto_flush_tout) {
  // clang-format off
  nofralloc;
  rlwinm r6, r4, 0x18, 0x18, 0x1f;
  rlwinm r0, r5, 0x18, 0x18, 0x1f;
  li r11, 7;
  li r10, 0;
  li r9, 0x28;
  li r8, 0xc;
  li r7, 4;
  sth r11, 2(r3);
  sth r10, 4(r3);
  stb r9, 8(r3);
  stb r8, 9(r3);
  stb r7, 0xa(r3);
  stb r4, 0xb(r3);
  stb r6, 0xc(r3);
  stb r5, 0xd(r3);
  stb r0, 0xe(r3);
  b btu_hcif_send_cmd;
  // clang-format on
}

// Symbol: btsnd_hcic_set_host_buf_size
// PAL: 0x80146398..0x80146454
MARK_BINARY_BLOB(btsnd_hcic_set_host_buf_size, 0x80146398, 0x80146454);
asm UNKNOWN_FUNCTION(btsnd_hcic_set_host_buf_size) {
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
  bne lbl_801463dc;
  li r3, 0;
  b lbl_80146434;
lbl_801463dc:
  li r0, 0xa;
  srawi r5, r28, 8;
  sth r0, 2(r3);
  li r0, 0;
  li r8, 0x33;
  li r7, 0xc;
  sth r0, 4(r3);
  li r6, 7;
  srawi r4, r30, 8;
  rlwinm r0, r31, 0x18, 0x18, 0x1f;
  stb r8, 8(r3);
  stb r7, 9(r3);
  stb r6, 0xa(r3);
  stb r28, 0xb(r3);
  stb r5, 0xc(r3);
  stb r29, 0xd(r3);
  stb r30, 0xe(r3);
  stb r4, 0xf(r3);
  stb r31, 0x10(r3);
  stb r0, 0x11(r3);
  bl btu_hcif_send_cmd;
  li r3, 1;
lbl_80146434:
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

// Symbol: btsnd_hcic_write_link_super_tout
// PAL: 0x80146454..0x801464e8
MARK_BINARY_BLOB(btsnd_hcic_write_link_super_tout, 0x80146454, 0x801464e8);
asm UNKNOWN_FUNCTION(btsnd_hcic_write_link_super_tout) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  li r3, 2;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  bne lbl_80146488;
  li r3, 0;
  b lbl_801464d0;
lbl_80146488:
  li r4, 7;
  li r0, 0;
  sth r4, 2(r3);
  li r7, 0x37;
  li r6, 0xc;
  li r5, 4;
  sth r0, 4(r3);
  srawi r4, r30, 8;
  rlwinm r0, r31, 0x18, 0x18, 0x1f;
  stb r7, 8(r3);
  stb r6, 9(r3);
  stb r5, 0xa(r3);
  stb r30, 0xb(r3);
  stb r4, 0xc(r3);
  stb r31, 0xd(r3);
  stb r0, 0xe(r3);
  bl btu_hcif_send_cmd;
  li r3, 1;
lbl_801464d0:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: btsnd_hcic_write_cur_iac_lap
// PAL: 0x801464e8..0x80146558
MARK_BINARY_BLOB(btsnd_hcic_write_cur_iac_lap, 0x801464e8, 0x80146558);
asm UNKNOWN_FUNCTION(btsnd_hcic_write_cur_iac_lap) {
  // clang-format off
  nofralloc;
  rlwinm r0, r4, 2, 0x16, 0x1d;
  li r9, 0;
  subf r6, r4, r0;
  li r8, 0x3a;
  addi r10, r6, 4;
  li r7, 0xc;
  clrlwi r6, r10, 0x10;
  sth r10, 2(r3);
  addi r0, r6, -3;
  addi r6, r3, 0xc;
  sth r9, 4(r3);
  stb r8, 8(r3);
  stb r7, 9(r3);
  stb r0, 0xa(r3);
  stb r4, 0xb(r3);
  mtctr r4;
  cmpwi r4, 0;
  ble lbl_80146554;
lbl_80146530:
  lbz r0, 2(r5);
  stb r0, 0(r6);
  lbz r0, 1(r5);
  stb r0, 1(r6);
  lbz r0, 0(r5);
  addi r5, r5, 3;
  stb r0, 2(r6);
  addi r6, r6, 3;
  bdnz lbl_80146530;
lbl_80146554:
  b btu_hcif_send_cmd;
  // clang-format on
}

// Symbol: btsnd_hcic_read_local_ver
// PAL: 0x80146558..0x801465b8
MARK_BINARY_BLOB(btsnd_hcic_read_local_ver, 0x80146558, 0x801465b8);
asm UNKNOWN_FUNCTION(btsnd_hcic_read_local_ver) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  li r3, 2;
  stw r0, 0x14(r1);
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  bne lbl_8014657c;
  li r3, 0;
  b lbl_801465a8;
lbl_8014657c:
  li r0, 3;
  li r5, 0;
  sth r0, 2(r3);
  li r4, 1;
  li r0, 0x10;
  sth r5, 4(r3);
  stb r4, 8(r3);
  stb r0, 9(r3);
  stb r5, 0xa(r3);
  bl btu_hcif_send_cmd;
  li r3, 1;
lbl_801465a8:
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: btsnd_hcic_read_local_features
// PAL: 0x801465b8..0x80146614
MARK_BINARY_BLOB(btsnd_hcic_read_local_features, 0x801465b8, 0x80146614);
asm UNKNOWN_FUNCTION(btsnd_hcic_read_local_features) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  li r3, 2;
  stw r0, 0x14(r1);
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  bne lbl_801465dc;
  li r3, 0;
  b lbl_80146604;
lbl_801465dc:
  li r5, 3;
  li r4, 0;
  sth r5, 2(r3);
  li r0, 0x10;
  sth r4, 4(r3);
  stb r5, 8(r3);
  stb r0, 9(r3);
  stb r4, 0xa(r3);
  bl btu_hcif_send_cmd;
  li r3, 1;
lbl_80146604:
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: btsnd_hcic_read_buffer_size
// PAL: 0x80146614..0x8014663c
MARK_BINARY_BLOB(btsnd_hcic_read_buffer_size, 0x80146614, 0x8014663c);
asm UNKNOWN_FUNCTION(btsnd_hcic_read_buffer_size) {
  // clang-format off
  nofralloc;
  li r5, 0;
  li r6, 3;
  li r4, 5;
  li r0, 0x10;
  sth r6, 2(r3);
  sth r5, 4(r3);
  stb r4, 8(r3);
  stb r0, 9(r3);
  stb r5, 0xa(r3);
  b btu_hcif_send_cmd;
  // clang-format on
}

// Symbol: btsnd_hcic_read_bd_addr
// PAL: 0x8014663c..0x8014669c
MARK_BINARY_BLOB(btsnd_hcic_read_bd_addr, 0x8014663c, 0x8014669c);
asm UNKNOWN_FUNCTION(btsnd_hcic_read_bd_addr) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  li r3, 2;
  stw r0, 0x14(r1);
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  bne lbl_80146660;
  li r3, 0;
  b lbl_8014668c;
lbl_80146660:
  li r0, 3;
  li r5, 0;
  sth r0, 2(r3);
  li r4, 9;
  li r0, 0x10;
  sth r5, 4(r3);
  stb r4, 8(r3);
  stb r0, 9(r3);
  stb r5, 0xa(r3);
  bl btu_hcif_send_cmd;
  li r3, 1;
lbl_8014668c:
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: btsnd_hcic_get_link_quality
// PAL: 0x8014669c..0x80146718
MARK_BINARY_BLOB(btsnd_hcic_get_link_quality, 0x8014669c, 0x80146718);
asm UNKNOWN_FUNCTION(btsnd_hcic_get_link_quality) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  li r3, 2;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  bne lbl_801466c8;
  li r3, 0;
  b lbl_80146704;
lbl_801466c8:
  li r4, 5;
  li r0, 0;
  sth r4, 2(r3);
  li r6, 3;
  li r5, 0x14;
  li r4, 2;
  sth r0, 4(r3);
  rlwinm r0, r31, 0x18, 0x18, 0x1f;
  stb r6, 8(r3);
  stb r5, 9(r3);
  stb r4, 0xa(r3);
  stb r31, 0xb(r3);
  stb r0, 0xc(r3);
  bl btu_hcif_send_cmd;
  li r3, 1;
lbl_80146704:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: btsnd_hcic_read_rssi
// PAL: 0x80146718..0x80146790
MARK_BINARY_BLOB(btsnd_hcic_read_rssi, 0x80146718, 0x80146790);
asm UNKNOWN_FUNCTION(btsnd_hcic_read_rssi) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  li r3, 2;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  bne lbl_80146744;
  li r3, 0;
  b lbl_8014677c;
lbl_80146744:
  li r7, 5;
  li r6, 0;
  sth r7, 2(r3);
  li r5, 0x14;
  li r4, 2;
  rlwinm r0, r31, 0x18, 0x18, 0x1f;
  sth r6, 4(r3);
  stb r7, 8(r3);
  stb r5, 9(r3);
  stb r4, 0xa(r3);
  stb r31, 0xb(r3);
  stb r0, 0xc(r3);
  bl btu_hcif_send_cmd;
  li r3, 1;
lbl_8014677c:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: btsnd_hcic_set_afh_channels
// PAL: 0x80146790..0x80146bb0
MARK_BINARY_BLOB(btsnd_hcic_set_afh_channels, 0x80146790, 0x80146bb0);
asm UNKNOWN_FUNCTION(btsnd_hcic_set_afh_channels) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  stw r31, 0x2c(r1);
  mr r31, r4;
  stw r30, 0x28(r1);
  mr r30, r3;
  li r3, 2;
  stw r29, 0x24(r1);
  lis r29, 0x8025;
  lbzu r12, -0x35f0(r29);
  lbz r11, 1(r29);
  lbz r10, 2(r29);
  lbz r9, 3(r29);
  lbz r8, 4(r29);
  lbz r7, 5(r29);
  lbz r6, 6(r29);
  lbz r5, 7(r29);
  lbz r4, 8(r29);
  lbz r0, 9(r29);
  stb r12, 8(r1);
  stb r11, 9(r1);
  stb r10, 0xa(r1);
  stb r9, 0xb(r1);
  stb r8, 0xc(r1);
  stb r7, 0xd(r1);
  stb r6, 0xe(r1);
  stb r5, 0xf(r1);
  stb r4, 0x10(r1);
  stb r0, 0x11(r1);
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  bne lbl_8014681c;
  li r3, 0;
  b lbl_80146b94;
lbl_8014681c:
  li r4, 0xd;
  li r0, 0;
  sth r4, 2(r3);
  li r5, 0x3f;
  li r4, 0xc;
  cmplw r30, r31;
  sth r0, 4(r3);
  li r0, 0xa;
  stb r5, 8(r3);
  stb r4, 9(r3);
  stb r0, 0xa(r3);
  bgt lbl_80146b3c;
  cmplwi r31, 0x4e;
  bgt lbl_80146b3c;
  cmpw cr1, r30, r31;
  bgt cr1, lbl_80146b3c;
  subf r11, r30, r31;
  addi r7, r31, -8;
  addi r12, r11, 1;
  cmpwi r12, 8;
  ble lbl_80146aec;
  li r5, 0;
  li r6, 0;
  li r8, 0;
  li r9, 0;
  li r10, 0;
  bgt cr1, lbl_8014689c;
  lis r4, 0x8000;
  addi r0, r4, -2;
  cmpw r31, r0;
  bgt lbl_8014689c;
  li r10, 1;
lbl_8014689c:
  cmpwi r10, 0;
  beq lbl_801468b8;
  lis r4, 0x8000;
  addi r0, r4, -2;
  cmpw r30, r0;
  bgt lbl_801468b8;
  li r9, 1;
lbl_801468b8:
  cmpwi r9, 0;
  beq lbl_801468d0;
  addis r0, r30, 0x8000;
  cmplwi r0, 0;
  beq lbl_801468d0;
  li r8, 1;
lbl_801468d0:
  cmpwi r8, 0;
  beq lbl_8014690c;
  neg r0, r30;
  rlwinm r8, r31, 0, 0, 0;
  rlwinm r0, r0, 0, 0, 0;
  li r4, 1;
  cmpw r8, r0;
  bne lbl_80146900;
  rlwinm r0, r11, 0, 0, 0;
  cmpw r8, r0;
  beq lbl_80146900;
  li r4, 0;
lbl_80146900:
  cmpwi r4, 0;
  beq lbl_8014690c;
  li r6, 1;
lbl_8014690c:
  cmpwi r6, 0;
  beq lbl_80146938;
  rlwinm. r0, r11, 0, 0, 0;
  li r4, 1;
  bne lbl_8014692c;
  rlwinm. r0, r12, 0, 0, 0;
  beq lbl_8014692c;
  li r4, 0;
lbl_8014692c:
  cmpwi r4, 0;
  beq lbl_80146938;
  li r5, 1;
lbl_80146938:
  cmpwi r5, 0;
  beq lbl_80146aec;
  addi r5, r7, 8;
  srawi r0, r30, 3;
  subf r5, r30, r5;
  addi r4, r1, 8;
  addze r6, r0;
  li r0, 1;
  srwi r5, r5, 3;
  add r6, r4, r6;
  mtctr r5;
  cmpw r30, r7;
  bgt lbl_80146aec;
lbl_8014696c:
  slwi r5, r30, 0x1d;
  srwi r8, r30, 0x1f;
  subf r5, r8, r5;
  lbz r10, 0(r6);
  rotlwi r5, r5, 3;
  addi r7, r30, 1;
  add r5, r5, r8;
  addi r9, r30, 2;
  slw r5, r0, r5;
  addi r8, r30, 3;
  andc r11, r10, r5;
  srwi r10, r7, 0x1f;
  stb r11, 0(r6);
  slwi r5, r7, 0x1d;
  srawi r11, r7, 3;
  addi r7, r30, 4;
  subf r5, r10, r5;
  addi r6, r6, 1;
  addze r29, r11;
  rotlwi r5, r5, 3;
  lbzx r12, r4, r29;
  add r10, r5, r10;
  slw r11, r0, r10;
  slwi r5, r9, 0x1d;
  srwi r10, r9, 0x1f;
  srawi r9, r9, 3;
  andc r11, r12, r11;
  subf r5, r10, r5;
  stbx r11, r4, r29;
  addze r29, r9;
  addi r9, r30, 5;
  rotlwi r5, r5, 3;
  lbzx r12, r4, r29;
  add r5, r5, r10;
  srawi r10, r8, 3;
  slw r11, r0, r5;
  andc r12, r12, r11;
  slwi r5, r8, 0x1d;
  srwi r8, r8, 0x1f;
  stbx r12, r4, r29;
  subf r5, r8, r5;
  addze r11, r10;
  rotlwi r5, r5, 3;
  lbzx r10, r4, r11;
  add r8, r5, r8;
  srawi r5, r7, 3;
  slw r8, r0, r8;
  andc r10, r10, r8;
  addze r29, r5;
  stbx r10, r4, r11;
  slwi r5, r7, 0x1d;
  srwi r8, r7, 0x1f;
  srawi r7, r9, 3;
  subf r5, r8, r5;
  lbzx r11, r4, r29;
  rotlwi r5, r5, 3;
  addze r12, r7;
  add r5, r5, r8;
  addi r8, r30, 6;
  slw r10, r0, r5;
  slwi r5, r9, 0x1d;
  srwi r9, r9, 0x1f;
  andc r10, r11, r10;
  stbx r10, r4, r29;
  subf r5, r9, r5;
  rotlwi r7, r5, 3;
  add r9, r7, r9;
  srawi r5, r8, 3;
  addze r11, r5;
  addi r7, r30, 7;
  lbzx r10, r4, r12;
  slw r9, r0, r9;
  slwi r5, r8, 0x1d;
  addi r30, r30, 8;
  andc r10, r10, r9;
  srwi r9, r8, 0x1f;
  stbx r10, r4, r12;
  subf r5, r9, r5;
  rotlwi r5, r5, 3;
  srawi r8, r7, 3;
  add r5, r5, r9;
  lbzx r10, r4, r11;
  slw r9, r0, r5;
  slwi r5, r7, 0x1d;
  srwi r7, r7, 0x1f;
  andc r9, r10, r9;
  subf r5, r7, r5;
  stbx r9, r4, r11;
  addze r9, r8;
  rotlwi r5, r5, 3;
  lbzx r8, r4, r9;
  add r5, r5, r7;
  slw r5, r0, r5;
  andc r5, r8, r5;
  stbx r5, r4, r9;
  bdnz lbl_8014696c;
lbl_80146aec:
  addi r0, r31, 1;
  addi r7, r1, 8;
  subf r0, r30, r0;
  li r5, 1;
  mtctr r0;
  cmpw r30, r31;
  bgt lbl_80146b3c;
lbl_80146b08:
  slwi r0, r30, 0x1d;
  srwi r4, r30, 0x1f;
  srawi r6, r30, 3;
  addi r30, r30, 1;
  subf r0, r4, r0;
  addze r8, r6;
  rotlwi r0, r0, 3;
  lbzx r6, r7, r8;
  add r0, r0, r4;
  slw r0, r5, r0;
  andc r0, r6, r0;
  stbx r0, r7, r8;
  bdnz lbl_80146b08;
lbl_80146b3c:
  lbz r0, 8(r1);
  stb r0, 0xb(r3);
  lbz r0, 9(r1);
  stb r0, 0xc(r3);
  lbz r0, 0xa(r1);
  stb r0, 0xd(r3);
  lbz r0, 0xb(r1);
  stb r0, 0xe(r3);
  lbz r0, 0xc(r1);
  stb r0, 0xf(r3);
  lbz r0, 0xd(r1);
  stb r0, 0x10(r3);
  lbz r0, 0xe(r1);
  stb r0, 0x11(r3);
  lbz r0, 0xf(r1);
  stb r0, 0x12(r3);
  lbz r0, 0x10(r1);
  stb r0, 0x13(r3);
  lbz r0, 0x11(r1);
  stb r0, 0x14(r3);
  bl btu_hcif_send_cmd;
  li r3, 1;
lbl_80146b94:
  lwz r0, 0x34(r1);
  lwz r31, 0x2c(r1);
  lwz r30, 0x28(r1);
  lwz r29, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: btsnd_hcic_write_inqscan_type
// PAL: 0x80146bb0..0x80146be0
MARK_BINARY_BLOB(btsnd_hcic_write_inqscan_type, 0x80146bb0, 0x80146be0);
asm UNKNOWN_FUNCTION(btsnd_hcic_write_inqscan_type) {
  // clang-format off
  nofralloc;
  li r8, 4;
  li r7, 0;
  li r6, 0x43;
  li r5, 0xc;
  li r0, 1;
  sth r8, 2(r3);
  sth r7, 4(r3);
  stb r6, 8(r3);
  stb r5, 9(r3);
  stb r0, 0xa(r3);
  stb r4, 0xb(r3);
  b btu_hcif_send_cmd;
  // clang-format on
}

// Symbol: btsnd_hcic_write_inquiry_mode
// PAL: 0x80146be0..0x80146c10
MARK_BINARY_BLOB(btsnd_hcic_write_inquiry_mode, 0x80146be0, 0x80146c10);
asm UNKNOWN_FUNCTION(btsnd_hcic_write_inquiry_mode) {
  // clang-format off
  nofralloc;
  li r8, 4;
  li r7, 0;
  li r6, 0x45;
  li r5, 0xc;
  li r0, 1;
  sth r8, 2(r3);
  sth r7, 4(r3);
  stb r6, 8(r3);
  stb r5, 9(r3);
  stb r0, 0xa(r3);
  stb r4, 0xb(r3);
  b btu_hcif_send_cmd;
  // clang-format on
}

// Symbol: btsnd_hcic_write_pagescan_type
// PAL: 0x80146c10..0x80146c40
MARK_BINARY_BLOB(btsnd_hcic_write_pagescan_type, 0x80146c10, 0x80146c40);
asm UNKNOWN_FUNCTION(btsnd_hcic_write_pagescan_type) {
  // clang-format off
  nofralloc;
  li r8, 4;
  li r7, 0;
  li r6, 0x47;
  li r5, 0xc;
  li r0, 1;
  sth r8, 2(r3);
  sth r7, 4(r3);
  stb r6, 8(r3);
  stb r5, 9(r3);
  stb r0, 0xa(r3);
  stb r4, 0xb(r3);
  b btu_hcif_send_cmd;
  // clang-format on
}

// Symbol: btsnd_hcic_vendor_spec_cmd
// PAL: 0x80146c40..0x80146d34
MARK_BINARY_BLOB(btsnd_hcic_vendor_spec_cmd, 0x80146c40, 0x80146d34);
asm UNKNOWN_FUNCTION(btsnd_hcic_vendor_spec_cmd) {
  // clang-format off
  nofralloc;
  ori r8, r4, 0xfc00;
  addi r7, r5, 3;
  srawi r0, r8, 8;
  li r4, 0;
  cmpwi cr1, r5, 0;
  sth r7, 2(r3);
  addi r9, r3, 0xb;
  li r10, 0;
  sth r4, 4(r3);
  stb r8, 8(r3);
  stb r0, 9(r3);
  stb r5, 0xa(r3);
  ble cr1, lbl_80146d30;
  cmpwi r5, 8;
  addi r7, r5, -8;
  ble lbl_80146d08;
  li r8, 0;
  blt cr1, lbl_80146c9c;
  lis r4, 0x8000;
  addi r0, r4, -2;
  cmpw r5, r0;
  bgt lbl_80146c9c;
  li r8, 1;
lbl_80146c9c:
  cmpwi r8, 0;
  beq lbl_80146d08;
  addi r0, r7, 7;
  srwi r0, r0, 3;
  mtctr r0;
  cmpwi r7, 0;
  ble lbl_80146d08;
lbl_80146cb8:
  lbzx r0, r6, r10;
  add r4, r6, r10;
  addi r10, r10, 8;
  stb r0, 0(r9);
  lbz r0, 1(r4);
  stb r0, 1(r9);
  lbz r0, 2(r4);
  stb r0, 2(r9);
  lbz r0, 3(r4);
  stb r0, 3(r9);
  lbz r0, 4(r4);
  stb r0, 4(r9);
  lbz r0, 5(r4);
  stb r0, 5(r9);
  lbz r0, 6(r4);
  stb r0, 6(r9);
  lbz r0, 7(r4);
  stb r0, 7(r9);
  addi r9, r9, 8;
  bdnz lbl_80146cb8;
lbl_80146d08:
  subf r0, r10, r5;
  add r4, r6, r10;
  mtctr r0;
  cmpw r10, r5;
  bge lbl_80146d30;
lbl_80146d1c:
  lbz r0, 0(r4);
  addi r4, r4, 1;
  stb r0, 0(r9);
  addi r9, r9, 1;
  bdnz lbl_80146d1c;
lbl_80146d30:
  b btu_hcif_send_cmd;
  // clang-format on
}

#include "rfc_ts_frames.h"

#include "gki_buffer.h"
#include "bte_logmsg.h"
#include "l2c_api.h"
#include "rfc_port_fsm.h"
#include "rfc_utils.h"

// Symbol: rfc_send_sabme
// PAL: 0x801547f0..0x801548a0
MARK_BINARY_BLOB(rfc_send_sabme, 0x801547f0, 0x801548a0);
asm UNKNOWN_FUNCTION(rfc_send_sabme) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_27;
  lbz r0, 0x6d(r3);
  mr r27, r3;
  mr r28, r4;
  li r3, 1;
  cmpwi r0, 0;
  bne lbl_80154820;
  li r3, 0;
lbl_80154820:
  rlwinm r29, r3, 1, 0x18, 0x1e;
  li r3, 2;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  mr r30, r3;
  beq lbl_80154888;
  li r0, 9;
  addi r31, r3, 0x11;
  sth r0, 4(r3);
  ori r3, r29, 1;
  rlwinm r0, r28, 2, 0x16, 0x1d;
  li r5, 0x3f;
  or r3, r3, r0;
  mr r4, r31;
  stb r3, 0(r31);
  li r0, 1;
  li r3, 3;
  stb r5, 1(r31);
  stb r0, 2(r31);
  bl rfc_calc_fcs;
  stb r3, 3(r31);
  li r0, 4;
  mr r3, r27;
  mr r4, r30;
  sth r0, 2(r30);
  bl rfc_check_send_cmd;
lbl_80154888:
  addi r11, r1, 0x20;
  bl _restgpr_27;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: rfc_send_ua
// PAL: 0x801548a0..0x80154950
MARK_BINARY_BLOB(rfc_send_ua, 0x801548a0, 0x80154950);
asm UNKNOWN_FUNCTION(rfc_send_ua) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_27;
  lbz r0, 0x6d(r3);
  mr r27, r3;
  mr r28, r4;
  li r3, 1;
  cmpwi r0, 0;
  beq lbl_801548d0;
  li r3, 0;
lbl_801548d0:
  rlwinm r29, r3, 1, 0x18, 0x1e;
  li r3, 2;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  mr r30, r3;
  beq lbl_80154938;
  li r0, 9;
  addi r31, r3, 0x11;
  sth r0, 4(r3);
  ori r3, r29, 1;
  rlwinm r0, r28, 2, 0x16, 0x1d;
  li r5, 0x73;
  or r3, r3, r0;
  mr r4, r31;
  stb r3, 0(r31);
  li r0, 1;
  li r3, 3;
  stb r5, 1(r31);
  stb r0, 2(r31);
  bl rfc_calc_fcs;
  stb r3, 3(r31);
  li r0, 4;
  mr r3, r27;
  mr r4, r30;
  sth r0, 2(r30);
  bl rfc_check_send_cmd;
lbl_80154938:
  addi r11, r1, 0x20;
  bl _restgpr_27;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: rfc_send_dm
// PAL: 0x80154950..0x80154a14
MARK_BINARY_BLOB(rfc_send_dm, 0x80154950, 0x80154a14);
asm UNKNOWN_FUNCTION(rfc_send_dm) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_27;
  lbz r0, 0x6d(r3);
  mr r31, r3;
  mr r27, r4;
  mr r30, r5;
  cmpwi r0, 0;
  li r0, 1;
  beq lbl_80154984;
  li r0, 0;
lbl_80154984:
  rlwinm r28, r0, 1, 0x18, 0x1e;
  li r3, 2;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  mr r29, r3;
  beq lbl_801549fc;
  neg r0, r30;
  li r4, 9;
  or r0, r0, r30;
  sth r4, 4(r3);
  addi r30, r3, 0x11;
  ori r5, r28, 1;
  srawi r3, r0, 0x1f;
  rlwinm r4, r27, 2, 0x16, 0x1d;
  or r4, r5, r4;
  li r0, 1;
  rlwinm r3, r3, 0, 0x1b, 0x1b;
  stb r4, 0(r30);
  ori r3, r3, 0xf;
  mr r4, r30;
  stb r3, 1(r30);
  li r3, 3;
  stb r0, 2(r30);
  bl rfc_calc_fcs;
  stb r3, 3(r30);
  li r0, 4;
  mr r3, r31;
  mr r4, r29;
  sth r0, 2(r29);
  bl rfc_check_send_cmd;
lbl_801549fc:
  addi r11, r1, 0x20;
  bl _restgpr_27;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: rfc_send_disc
// PAL: 0x80154a14..0x80154ac4
MARK_BINARY_BLOB(rfc_send_disc, 0x80154a14, 0x80154ac4);
asm UNKNOWN_FUNCTION(rfc_send_disc) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_27;
  lbz r0, 0x6d(r3);
  mr r27, r3;
  mr r28, r4;
  li r3, 1;
  cmpwi r0, 0;
  bne lbl_80154a44;
  li r3, 0;
lbl_80154a44:
  rlwinm r29, r3, 1, 0x18, 0x1e;
  li r3, 2;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  mr r30, r3;
  beq lbl_80154aac;
  li r0, 9;
  addi r31, r3, 0x11;
  sth r0, 4(r3);
  ori r3, r29, 1;
  rlwinm r0, r28, 2, 0x16, 0x1d;
  li r5, 0x53;
  or r3, r3, r0;
  mr r4, r31;
  stb r3, 0(r31);
  li r0, 1;
  li r3, 3;
  stb r5, 1(r31);
  stb r0, 2(r31);
  bl rfc_calc_fcs;
  stb r3, 3(r31);
  li r0, 4;
  mr r3, r27;
  mr r4, r30;
  sth r0, 2(r30);
  bl rfc_check_send_cmd;
lbl_80154aac:
  addi r11, r1, 0x20;
  bl _restgpr_27;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: rfc_send_buf_uih
// PAL: 0x80154ac4..0x80154c5c
MARK_BINARY_BLOB(rfc_send_buf_uih, 0x80154ac4, 0x80154c5c);
asm UNKNOWN_FUNCTION(rfc_send_buf_uih) {
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
  stw r28, 0x10(r1);
  lbz r0, 0x6d(r3);
  cmpwi r0, 0;
  li r0, 1;
  bne lbl_80154b00;
  li r0, 0;
lbl_80154b00:
  lhz r3, 4(r5);
  rlwinm r6, r0, 1, 0x18, 0x1e;
  lhz r0, 2(r5);
  addi r3, r3, -3;
  cmplwi r0, 0x7f;
  sth r3, 4(r5);
  ble lbl_80154b28;
  clrlwi r3, r3, 0x10;
  addi r0, r3, -1;
  sth r0, 4(r5);
lbl_80154b28:
  cmpwi r4, 0;
  beq lbl_80154b3c;
  lhz r0, 6(r5);
  clrlwi r0, r0, 0x18;
  b lbl_80154b40;
lbl_80154b3c:
  li r0, 0;
lbl_80154b40:
  cmpwi r0, 0;
  beq lbl_80154b54;
  lhz r3, 4(r5);
  addi r3, r3, -1;
  sth r3, 4(r5);
lbl_80154b54:
  neg r3, r0;
  lhz r7, 4(r5);
  or r3, r3, r0;
  ori r6, r6, 1;
  rlwinm r4, r4, 2, 0x16, 0x1d;
  add r7, r5, r7;
  or r4, r6, r4;
  srawi r3, r3, 0x1f;
  rlwinm r3, r3, 0, 0x1b, 0x1b;
  stb r4, 8(r7);
  ori r3, r3, 0xef;
  addi r4, r7, 0xa;
  stb r3, 9(r7);
  lhz r3, 2(r5);
  cmplwi r3, 0x7f;
  bgt lbl_80154bb4;
  rlwinm r3, r3, 1, 0xf, 0x1e;
  ori r3, r3, 1;
  stb r3, 0(r4);
  addi r4, r4, 1;
  lhz r3, 2(r5);
  addi r3, r3, 3;
  sth r3, 2(r5);
  b lbl_80154bd8;
lbl_80154bb4:
  rlwinm r3, r3, 1, 0x18, 0x1e;
  stb r3, 0(r4);
  lhz r3, 2(r5);
  srawi r3, r3, 7;
  stb r3, 1(r4);
  addi r4, r4, 2;
  lhz r3, 2(r5);
  addi r3, r3, 4;
  sth r3, 2(r5);
lbl_80154bd8:
  cmpwi r0, 0;
  beq lbl_80154bf0;
  stb r0, 0(r4);
  lhz r3, 2(r5);
  addi r0, r3, 1;
  sth r0, 2(r5);
lbl_80154bf0:
  lhz r4, 2(r5);
  li r3, 2;
  lhz r6, 4(r5);
  addi r0, r4, 1;
  add r6, r5, r6;
  sth r0, 2(r5);
  add r28, r6, r4;
  addi r4, r6, 8;
  bl rfc_calc_fcs;
  cmpwi r30, 0;
  stb r3, 8(r28);
  bne lbl_80154c30;
  mr r3, r29;
  mr r4, r31;
  bl rfc_check_send_cmd;
  b lbl_80154c3c;
lbl_80154c30:
  lhz r3, 0x68(r29);
  mr r4, r31;
  bl L2CA_DataWrite;
lbl_80154c3c:
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

// Symbol: rfc_send_pn
// PAL: 0x80154c5c..0x80154d44
MARK_BINARY_BLOB(rfc_send_pn, 0x80154c5c, 0x80154d44);
asm UNKNOWN_FUNCTION(rfc_send_pn) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_26;
  mr r30, r3;
  mr r26, r4;
  mr r27, r5;
  mr r31, r6;
  mr r28, r7;
  mr r29, r8;
  li r3, 2;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  beq lbl_80154d2c;
  neg r0, r27;
  li r4, 0xc;
  or r0, r0, r27;
  sth r4, 4(r3);
  srawi r4, r0, 0x1f;
  cmpwi r27, 0;
  rlwinm r4, r4, 0, 0x1e, 0x1e;
  li r0, 0x11;
  ori r4, r4, 0x81;
  addi r8, r3, 0x18;
  stb r4, 0x14(r3);
  stb r0, 0x15(r3);
  stb r26, 0x16(r3);
  stb r28, 0x17(r3);
  beq lbl_80154ce4;
  li r0, 0;
  stb r0, 0(r8);
  addi r8, r8, 1;
  b lbl_80154cf8;
lbl_80154ce4:
  lis r4, 0x8034;
  addi r4, r4, -25816;
  lbz r0, 0xb(r4);
  stb r0, 0(r8);
  addi r8, r8, 1;
lbl_80154cf8:
  li r7, 0;
  rlwinm r6, r31, 0x18, 0x18, 0x1f;
  stb r7, 0(r8);
  li r0, 0xa;
  mr r5, r3;
  li r4, 0;
  stb r31, 1(r8);
  stb r6, 2(r8);
  stb r7, 3(r8);
  stb r29, 4(r8);
  sth r0, 2(r3);
  mr r3, r30;
  bl rfc_send_buf_uih;
lbl_80154d2c:
  addi r11, r1, 0x20;
  bl _restgpr_26;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: rfc_send_fcon
// PAL: 0x80154d44..0x80154dc8
MARK_BINARY_BLOB(rfc_send_fcon, 0x80154d44, 0x80154dc8);
asm UNKNOWN_FUNCTION(rfc_send_fcon) {
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
  beq lbl_80154db0;
  neg r0, r31;
  li r4, 0xc;
  or r0, r0, r31;
  sth r4, 4(r3);
  srawi r4, r0, 0x1f;
  li r6, 2;
  rlwinm r4, r4, 0, 0x1e, 0x1e;
  li r0, 1;
  ori r4, r4, 0xa1;
  mr r5, r3;
  stb r4, 0x14(r3);
  li r4, 0;
  stb r0, 0x15(r3);
  sth r6, 2(r3);
  mr r3, r30;
  bl rfc_send_buf_uih;
lbl_80154db0:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: rfc_send_fcoff
// PAL: 0x80154dc8..0x80154e4c
MARK_BINARY_BLOB(rfc_send_fcoff, 0x80154dc8, 0x80154e4c);
asm UNKNOWN_FUNCTION(rfc_send_fcoff) {
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
  beq lbl_80154e34;
  neg r0, r31;
  li r4, 0xc;
  or r0, r0, r31;
  sth r4, 4(r3);
  srawi r4, r0, 0x1f;
  li r6, 2;
  rlwinm r4, r4, 0, 0x1e, 0x1e;
  li r0, 1;
  ori r4, r4, 0x61;
  mr r5, r3;
  stb r4, 0x14(r3);
  li r4, 0;
  stb r0, 0x15(r3);
  sth r6, 2(r3);
  mr r3, r30;
  bl rfc_send_buf_uih;
lbl_80154e34:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: rfc_send_msc
// PAL: 0x80154e4c..0x80154f6c
MARK_BINARY_BLOB(rfc_send_msc, 0x80154e4c, 0x80154f6c);
asm UNKNOWN_FUNCTION(rfc_send_msc) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_26;
  lbz r31, 0(r6);
  mr r28, r3;
  lbz r30, 1(r6);
  mr r26, r4;
  mr r27, r5;
  mr r29, r6;
  li r3, 2;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  beq lbl_80154f54;
  neg r0, r27;
  neg r4, r30;
  or r0, r0, r27;
  li r6, 0xc;
  or r5, r4, r30;
  sth r6, 4(r3);
  srawi r0, r0, 0x1f;
  rlwinm r4, r26, 2, 0x16, 0x1d;
  rlwinm r0, r0, 0, 0x1e, 0x1e;
  srwi r5, r5, 0x1f;
  ori r0, r0, 0xe1;
  cmpwi r30, 0;
  addi r9, r5, 2;
  stb r0, 0x14(r3);
  rlwinm r5, r9, 1, 0x17, 0x1e;
  clrlwi r0, r31, 0x1f;
  ori r6, r5, 1;
  ori r5, r4, 3;
  stb r6, 0x15(r3);
  rlwinm r4, r31, 0x1f, 0x1f, 0x1f;
  neg r8, r0;
  stb r5, 0x16(r3);
  neg r4, r4;
  rlwinm r0, r31, 0x1e, 0x1f, 0x1f;
  lbz r7, 4(r29);
  rlwinm r10, r4, 0, 0x1c, 0x1c;
  neg r6, r0;
  rlwinm r0, r31, 0x1d, 0x1f, 0x1f;
  neg r4, r7;
  or r4, r4, r7;
  neg r5, r0;
  srawi r4, r4, 0x1f;
  ori r0, r10, 1;
  rlwinm r4, r4, 0, 0x1e, 0x1e;
  addi r7, r3, 0x18;
  rlwimi r4, r8, 0, 0x1d, 0x1d;
  rlwimi r4, r6, 0, 0x19, 0x19;
  rlwimi r4, r5, 0, 0x18, 0x18;
  or r0, r4, r0;
  stb r0, 0x17(r3);
  beq lbl_80154f38;
  rlwinm r0, r30, 4, 0x14, 0x1b;
  ori r0, r0, 3;
  stb r0, 0(r7);
lbl_80154f38:
  clrlwi r4, r9, 0x18;
  mr r5, r3;
  addi r0, r4, 2;
  sth r0, 2(r3);
  li r4, 0;
  mr r3, r28;
  bl rfc_send_buf_uih;
lbl_80154f54:
  addi r11, r1, 0x20;
  bl _restgpr_26;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: rfc_send_rls
// PAL: 0x80154f6c..0x8015501c
MARK_BINARY_BLOB(rfc_send_rls, 0x80154f6c, 0x8015501c);
asm UNKNOWN_FUNCTION(rfc_send_rls) {
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
  beq lbl_80154ffc;
  neg r0, r30;
  li r5, 0xc;
  or r4, r0, r30;
  sth r5, 4(r3);
  srawi r4, r4, 0x1f;
  rlwinm r0, r29, 2, 0x16, 0x1d;
  rlwinm r5, r4, 0, 0x1e, 0x1e;
  ori r6, r31, 1;
  ori r5, r5, 0x51;
  ori r7, r0, 3;
  stb r5, 0x14(r3);
  li r4, 5;
  li r0, 4;
  mr r5, r3;
  stb r4, 0x15(r3);
  li r4, 0;
  stb r7, 0x16(r3);
  stb r6, 0x17(r3);
  sth r0, 2(r3);
  mr r3, r28;
  bl rfc_send_buf_uih;
lbl_80154ffc:
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

// Symbol: rfc_send_rpn
// PAL: 0x8015501c..0x80155138
MARK_BINARY_BLOB(rfc_send_rpn, 0x8015501c, 0x80155138);
asm UNKNOWN_FUNCTION(rfc_send_rpn) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_27;
  mr r29, r3;
  mr r27, r4;
  mr r28, r5;
  mr r30, r6;
  mr r31, r7;
  li r3, 2;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  mr r5, r3;
  beq lbl_80155120;
  neg r0, r28;
  li r4, 0xc;
  or r0, r0, r28;
  sth r4, 4(r3);
  srawi r0, r0, 0x1f;
  cmpwi r30, 0;
  rlwinm r0, r0, 0, 0x1e, 0x1e;
  addi r4, r3, 0x15;
  ori r0, r0, 0x91;
  stb r0, 0x14(r3);
  bne lbl_801550a0;
  li r6, 3;
  rlwinm r0, r27, 2, 0x16, 0x1d;
  stb r6, 0(r4);
  ori r0, r0, 3;
  stb r0, 1(r4);
  sth r6, 2(r3);
  b lbl_80155114;
lbl_801550a0:
  li r6, 0x11;
  rlwinm r0, r27, 2, 0x16, 0x1d;
  stb r6, 0(r4);
  ori r7, r0, 3;
  rlwinm r6, r31, 0x18, 0x18, 0x1f;
  li r0, 0xa;
  stb r7, 1(r4);
  lbz r7, 0(r30);
  stb r7, 2(r4);
  lbz r7, 2(r30);
  lbz r9, 3(r30);
  lbz r10, 4(r30);
  slwi r7, r7, 2;
  lbz r8, 1(r30);
  slwi r9, r9, 3;
  slwi r10, r10, 4;
  or r7, r8, r7;
  or r7, r9, r7;
  or r7, r10, r7;
  stb r7, 3(r4);
  lbz r7, 5(r30);
  stb r7, 4(r4);
  lbz r7, 7(r30);
  stb r7, 5(r4);
  lbz r7, 8(r30);
  stb r7, 6(r4);
  stb r31, 7(r4);
  stb r6, 8(r4);
  sth r0, 2(r3);
lbl_80155114:
  mr r3, r29;
  li r4, 0;
  bl rfc_send_buf_uih;
lbl_80155120:
  addi r11, r1, 0x20;
  bl _restgpr_27;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: rfc_send_test
// PAL: 0x80155138..0x801551e0
MARK_BINARY_BLOB(rfc_send_test, 0x80155138, 0x801551e0);
asm UNKNOWN_FUNCTION(rfc_send_test) {
  // clang-format off
  nofralloc;
  lhz r0, 4(r5);
  cmplwi r0, 0x10;
  bge lbl_80155190;
  lhz r6, 2(r5);
  add r0, r5, r0;
  li r8, 0;
  add r7, r0, r6;
  add r6, r5, r6;
  addi r7, r7, 7;
  addi r9, r6, 0x17;
  b lbl_80155178;
lbl_80155164:
  lbz r0, 0(r7);
  addi r8, r8, 1;
  addi r7, r7, -1;
  stb r0, 0(r9);
  addi r9, r9, -1;
lbl_80155178:
  lhz r0, 2(r5);
  clrlwi r6, r8, 0x10;
  cmplw r6, r0;
  blt lbl_80155164;
  li r0, 0x10;
  sth r0, 4(r5);
lbl_80155190:
  neg r0, r4;
  lhz r6, 4(r5);
  or r0, r0, r4;
  addi r4, r6, -2;
  srawi r0, r0, 0x1f;
  sth r4, 4(r5);
  clrlwi r6, r4, 0x10;
  li r4, 0;
  rlwinm r0, r0, 0, 0x1e, 0x1e;
  add r6, r5, r6;
  ori r0, r0, 0x21;
  stb r0, 8(r6);
  lhz r0, 2(r5);
  slwi r0, r0, 1;
  ori r0, r0, 1;
  stb r0, 9(r6);
  lhz r6, 2(r5);
  addi r0, r6, 2;
  sth r0, 2(r5);
  b rfc_send_buf_uih;
  // clang-format on
}

// Symbol: rfc_send_credit
// PAL: 0x801551e0..0x801552a0
MARK_BINARY_BLOB(rfc_send_credit, 0x801551e0, 0x801552a0);
asm UNKNOWN_FUNCTION(rfc_send_credit) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_27;
  lbz r0, 0x6d(r3);
  mr r27, r3;
  mr r28, r4;
  mr r29, r5;
  cmpwi r0, 0;
  li r0, 1;
  bne lbl_80155214;
  li r0, 0;
lbl_80155214:
  rlwinm r30, r0, 1, 0x18, 0x1e;
  li r3, 2;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  mr r31, r3;
  beq lbl_80155288;
  li r5, 9;
  ori r4, r30, 1;
  rlwinm r0, r28, 2, 0x16, 0x1d;
  sth r5, 4(r3);
  or r0, r4, r0;
  li r4, 0xff;
  stb r0, 0x11(r3);
  li r0, 1;
  addi r30, r31, 0x15;
  stb r4, 0x12(r3);
  stb r0, 0x13(r3);
  stb r29, 0x14(r3);
  li r3, 2;
  lhz r0, 4(r31);
  add r4, r31, r0;
  addi r4, r4, 8;
  bl rfc_calc_fcs;
  stb r3, 0(r30);
  li r0, 5;
  mr r3, r27;
  mr r4, r31;
  sth r0, 2(r31);
  bl rfc_check_send_cmd;
lbl_80155288:
  addi r11, r1, 0x20;
  bl _restgpr_27;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: rfc_parse_data
// PAL: 0x801552a0..0x80155814
MARK_BINARY_BLOB(rfc_parse_data, 0x801552a0, 0x80155814);
asm UNKNOWN_FUNCTION(rfc_parse_data) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  lis r31, 0x8028;
  addi r31, r31, 0x7658;
  stw r30, 0x18(r1);
  mr r30, r4;
  stw r29, 0x14(r1);
  mr r29, r3;
  lhz r0, 4(r5);
  lhz r8, 2(r5);
  add r6, r5, r0;
  addi r7, r6, 8;
  cmplwi r8, 3;
  mr r0, r7;
  bge lbl_80155310;
  lis r3, 0x8034;
  addi r3, r3, -25816;
  lbz r0, 0x414(r3);
  cmplwi r0, 1;
  blt lbl_80155308;
  mr r5, r8;
  addi r4, r31, 0;
  lis r3, 9;
  bl LogMsg_1;
lbl_80155308:
  li r3, 0x32;
  b lbl_801557f8;
lbl_80155310:
  lbz r8, 0(r7);
  rlwinm r6, r8, 0, 0x1e, 0x1e;
  clrlwi. r9, r8, 0x1f;
  srawi r6, r6, 1;
  stb r6, 2(r4);
  lbz r6, 0(r7);
  addi r7, r7, 1;
  srawi r8, r6, 2;
  stb r8, 0(r4);
  bne lbl_80155350;
  lbz r6, 0(r7);
  clrlwi r8, r8, 0x18;
  addi r7, r7, 1;
  slwi r6, r6, 6;
  add r6, r8, r6;
  stb r6, 0(r4);
lbl_80155350:
  lbz r6, 0(r7);
  rlwinm r6, r6, 0, 0x1c, 0x1a;
  stb r6, 1(r4);
  lbz r6, 0(r7);
  rlwinm r6, r6, 0, 0x1b, 0x1b;
  srawi r6, r6, 4;
  stb r6, 4(r4);
  lbz r6, 1(r7);
  addi r7, r7, 2;
  clrlwi. r10, r6, 0x1f;
  srawi r8, r6, 1;
  bne lbl_80155394;
  lbz r6, 0(r7);
  addi r7, r7, 1;
  slwi r6, r6, 7;
  add r6, r8, r6;
  clrlwi r8, r6, 0x10;
lbl_80155394:
  cntlzw r6, r10;
  cntlzw r9, r9;
  srwi r11, r6, 5;
  lhz r6, 4(r5);
  srwi r10, r9, 5;
  lhz r9, 2(r5);
  add r11, r10, r11;
  addi r10, r11, 4;
  add r6, r11, r6;
  subf r9, r10, r9;
  addi r6, r6, 3;
  sth r9, 2(r5);
  sth r6, 4(r5);
  lbz r6, 0x72(r3);
  cmplwi r6, 2;
  bne lbl_80155420;
  lbz r6, 1(r4);
  cmplwi r6, 0xef;
  bne lbl_80155420;
  lbz r6, 0(r4);
  cmpwi r6, 0;
  beq lbl_80155420;
  lbz r6, 4(r4);
  cmplwi r6, 1;
  bne lbl_80155420;
  lbz r6, 0(r7);
  addi r7, r7, 1;
  stb r6, 5(r4);
  lhz r9, 2(r5);
  lhz r6, 4(r5);
  addi r9, r9, -1;
  addi r6, r6, 1;
  sth r9, 2(r5);
  sth r6, 4(r5);
  b lbl_80155428;
lbl_80155420:
  li r6, 0;
  stb r6, 5(r4);
lbl_80155428:
  lhz r5, 2(r5);
  clrlwi r6, r8, 0x10;
  cmplw r5, r6;
  beq lbl_80155460;
  lis r3, 0x8034;
  addi r3, r3, -25816;
  lbz r0, 0x414(r3);
  cmplwi r0, 1;
  blt lbl_80155458;
  addi r4, r31, 0x10;
  lis r3, 9;
  bl LogMsg_2;
lbl_80155458:
  li r3, 0x32;
  b lbl_801557f8;
lbl_80155460:
  lbz r9, 1(r4);
  lbzx r5, r7, r6;
  cmpwi r9, 0x43;
  beq lbl_80155678;
  bge lbl_8015548c;
  cmpwi r9, 0x2f;
  beq lbl_801554a4;
  bge lbl_801557f4;
  cmpwi r9, 0xf;
  beq lbl_801555e4;
  b lbl_801557f4;
lbl_8015548c:
  cmpwi r9, 0xef;
  beq lbl_80155718;
  bge lbl_801557f4;
  cmpwi r9, 0x63;
  beq lbl_80155544;
  b lbl_801557f4;
lbl_801554a4:
  lbz r6, 0x6d(r3);
  cmpwi r6, 0;
  beq lbl_801554bc;
  lbz r3, 2(r4);
  cmpwi r3, 0;
  bne lbl_80155514;
lbl_801554bc:
  cmpwi r6, 0;
  bne lbl_801554d0;
  lbz r3, 2(r4);
  cmpwi r3, 0;
  beq lbl_80155514;
lbl_801554d0:
  lbz r3, 4(r4);
  cmpwi r3, 0;
  beq lbl_80155514;
  clrlwi. r3, r8, 0x10;
  bne lbl_80155514;
  lbz r3, 0(r4);
  cmpwi r3, 0;
  beq lbl_80155500;
  cmplwi r3, 2;
  blt lbl_80155514;
  cmplwi r3, 0x3d;
  bgt lbl_80155514;
lbl_80155500:
  mr r4, r0;
  li r3, 3;
  bl rfc_check_fcs;
  clrlwi. r0, r3, 0x18;
  bne lbl_8015553c;
lbl_80155514:
  lis r3, 0x8034;
  addi r3, r3, -25816;
  lbz r0, 0x414(r3);
  cmplwi r0, 1;
  blt lbl_80155534;
  addi r4, r31, 0x24;
  lis r3, 9;
  bl LogMsg_0;
lbl_80155534:
  li r3, 0x32;
  b lbl_801557f8;
lbl_8015553c:
  li r3, 0;
  b lbl_801557f8;
lbl_80155544:
  lbz r6, 0x6d(r3);
  cmpwi r6, 0;
  beq lbl_8015555c;
  lbz r3, 2(r4);
  cmpwi r3, 0;
  beq lbl_801555b4;
lbl_8015555c:
  cmpwi r6, 0;
  bne lbl_80155570;
  lbz r3, 2(r4);
  cmpwi r3, 0;
  bne lbl_801555b4;
lbl_80155570:
  lbz r3, 4(r4);
  cmpwi r3, 0;
  beq lbl_801555b4;
  clrlwi. r3, r8, 0x10;
  bne lbl_801555b4;
  lbz r3, 0(r4);
  cmpwi r3, 0;
  beq lbl_801555a0;
  cmplwi r3, 2;
  blt lbl_801555b4;
  cmplwi r3, 0x3d;
  bgt lbl_801555b4;
lbl_801555a0:
  mr r4, r0;
  li r3, 3;
  bl rfc_check_fcs;
  clrlwi. r0, r3, 0x18;
  bne lbl_801555dc;
lbl_801555b4:
  lis r3, 0x8034;
  addi r3, r3, -25816;
  lbz r0, 0x414(r3);
  cmplwi r0, 1;
  blt lbl_801555d4;
  lis r3, 9;
  addi r4, r13, -29536;
  bl LogMsg_0;
lbl_801555d4:
  li r3, 0x32;
  b lbl_801557f8;
lbl_801555dc:
  li r3, 1;
  b lbl_801557f8;
lbl_801555e4:
  lbz r6, 0x6d(r3);
  cmpwi r6, 0;
  beq lbl_801555fc;
  lbz r3, 2(r4);
  cmpwi r3, 0;
  beq lbl_80155648;
lbl_801555fc:
  cmpwi r6, 0;
  bne lbl_80155610;
  lbz r3, 2(r4);
  cmpwi r3, 0;
  bne lbl_80155648;
lbl_80155610:
  clrlwi. r3, r8, 0x10;
  bne lbl_80155648;
  lbz r3, 0(r4);
  cmpwi r3, 0;
  beq lbl_80155634;
  cmplwi r3, 2;
  blt lbl_80155648;
  cmplwi r3, 0x3d;
  bgt lbl_80155648;
lbl_80155634:
  mr r4, r0;
  li r3, 3;
  bl rfc_check_fcs;
  clrlwi. r0, r3, 0x18;
  bne lbl_80155670;
lbl_80155648:
  lis r3, 0x8034;
  addi r3, r3, -25816;
  lbz r0, 0x414(r3);
  cmplwi r0, 1;
  blt lbl_80155668;
  lis r3, 9;
  addi r4, r13, -29528;
  bl LogMsg_0;
lbl_80155668:
  li r3, 0x32;
  b lbl_801557f8;
lbl_80155670:
  li r3, 2;
  b lbl_801557f8;
lbl_80155678:
  lbz r6, 0x6d(r3);
  cmpwi r6, 0;
  beq lbl_80155690;
  lbz r3, 2(r4);
  cmpwi r3, 0;
  bne lbl_801556e8;
lbl_80155690:
  cmpwi r6, 0;
  bne lbl_801556a4;
  lbz r3, 2(r4);
  cmpwi r3, 0;
  beq lbl_801556e8;
lbl_801556a4:
  lbz r3, 4(r4);
  cmpwi r3, 0;
  beq lbl_801556e8;
  clrlwi. r3, r8, 0x10;
  bne lbl_801556e8;
  lbz r3, 0(r4);
  cmpwi r3, 0;
  beq lbl_801556d4;
  cmplwi r3, 2;
  blt lbl_801556e8;
  cmplwi r3, 0x3d;
  bgt lbl_801556e8;
lbl_801556d4:
  mr r4, r0;
  li r3, 3;
  bl rfc_check_fcs;
  clrlwi. r0, r3, 0x18;
  bne lbl_80155710;
lbl_801556e8:
  lis r3, 0x8034;
  addi r3, r3, -25816;
  lbz r0, 0x414(r3);
  cmplwi r0, 1;
  blt lbl_80155708;
  addi r4, r31, 0x30;
  lis r3, 9;
  bl LogMsg_0;
lbl_80155708:
  li r3, 0x32;
  b lbl_801557f8;
lbl_80155710:
  li r3, 3;
  b lbl_801557f8;
lbl_80155718:
  lbz r3, 0(r4);
  cmpwi r3, 0;
  beq lbl_8015575c;
  cmplwi r3, 2;
  blt lbl_80155734;
  cmplwi r3, 0x3d;
  ble lbl_8015575c;
lbl_80155734:
  lis r3, 0x8034;
  addi r3, r3, -25816;
  lbz r0, 0x414(r3);
  cmplwi r0, 1;
  blt lbl_80155754;
  addi r4, r31, 0x3c;
  lis r3, 9;
  bl LogMsg_0;
lbl_80155754:
  li r3, 0x32;
  b lbl_801557f8;
lbl_8015575c:
  mr r4, r0;
  li r3, 2;
  bl rfc_check_fcs;
  clrlwi. r0, r3, 0x18;
  bne lbl_80155798;
  lis r3, 0x8034;
  addi r3, r3, -25816;
  lbz r0, 0x414(r3);
  cmplwi r0, 1;
  blt lbl_80155790;
  addi r4, r31, 0x54;
  lis r3, 9;
  bl LogMsg_0;
lbl_80155790:
  li r3, 0x32;
  b lbl_801557f8;
lbl_80155798:
  lbz r3, 0x6d(r29);
  cmpwi r3, 0;
  beq lbl_801557b0;
  lbz r0, 2(r30);
  cmpwi r0, 0;
  bne lbl_801557c4;
lbl_801557b0:
  cmpwi r3, 0;
  bne lbl_801557ec;
  lbz r0, 2(r30);
  cmpwi r0, 0;
  bne lbl_801557ec;
lbl_801557c4:
  lis r3, 0x8034;
  addi r3, r3, -25816;
  lbz r0, 0x414(r3);
  cmplwi r0, 1;
  blt lbl_801557e4;
  addi r4, r31, 0x64;
  lis r3, 9;
  bl LogMsg_0;
lbl_801557e4:
  li r3, 4;
  b lbl_801557f8;
lbl_801557ec:
  li r3, 4;
  b lbl_801557f8;
lbl_801557f4:
  li r3, 0x32;
lbl_801557f8:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: rfc_process_mx_message
// PAL: 0x80155814..0x80155e38
MARK_BINARY_BLOB(rfc_process_mx_message, 0x80155814, 0x80155e38);
asm UNKNOWN_FUNCTION(rfc_process_mx_message) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  lis r7, 0x8028;
  stw r0, 0x24(r1);
  addi r7, r7, 0x7658;
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  lis r30, 0x8034;
  addi r30, r30, -25816;
  stw r29, 0x14(r1);
  mr r29, r4;
  stw r28, 0x10(r1);
  mr r28, r3;
  lhz r0, 4(r4);
  lhz r6, 2(r4);
  add r5, r4, r0;
  lbz r0, 8(r5);
  clrlwi. r0, r0, 0x1f;
  stb r0, 3(r30);
  lbz r0, 8(r5);
  rlwinm r31, r0, 0x1f, 0x1f, 0x1f;
  stb r31, 2(r30);
  lbz r0, 8(r5);
  rlwinm r0, r0, 0, 0x18, 0x1d;
  stb r0, 1(r30);
  beq lbl_80155884;
  cmpwi r6, 0;
  bne lbl_801558b4;
lbl_80155884:
  lis r3, 0x8034;
  addi r3, r3, -25816;
  lbz r0, 0x414(r3);
  cmplwi r0, 1;
  blt lbl_801558a8;
  lbz r5, 3(r30);
  addi r4, r7, 0x78;
  lis r3, 9;
  bl LogMsg_2;
lbl_801558a8:
  mr r3, r29;
  bl GKI_freebuf;
  b lbl_80155e18;
lbl_801558b4:
  lbz r3, 9(r5);
  addis r6, r6, 1;
  addi r5, r5, 0xa;
  clrlwi. r0, r3, 0x1f;
  srawi r8, r3, 1;
  addi r6, r6, -2;
  bne lbl_801558e8;
  lbz r0, 0(r5);
  addi r6, r6, -1;
  addi r5, r5, 1;
  slwi r0, r0, 7;
  add r0, r8, r0;
  clrlwi r8, r0, 0x18;
lbl_801558e8:
  clrlwi r0, r8, 0x18;
  clrlwi r3, r6, 0x10;
  cmpw r0, r3;
  beq lbl_80155924;
  lis r3, 0x8034;
  addi r3, r3, -25816;
  lbz r0, 0x414(r3);
  cmplwi r0, 1;
  blt lbl_80155918;
  addi r4, r7, 0x98;
  lis r3, 9;
  bl LogMsg_0;
lbl_80155918:
  mr r3, r29;
  bl GKI_freebuf;
  b lbl_80155e18;
lbl_80155924:
  lbz r0, 1(r30);
  cmpwi r0, 0x80;
  beq lbl_80155988;
  bge lbl_80155964;
  cmpwi r0, 0x50;
  beq lbl_80155d14;
  bge lbl_80155958;
  cmpwi r0, 0x20;
  beq lbl_80155a5c;
  bge lbl_80155da8;
  cmpwi r0, 0x10;
  beq lbl_80155bac;
  b lbl_80155da8;
lbl_80155958:
  cmpwi r0, 0x60;
  beq lbl_80155ad0;
  b lbl_80155da8;
lbl_80155964:
  cmpwi r0, 0xa0;
  beq lbl_80155ab0;
  bge lbl_8015597c;
  cmpwi r0, 0x90;
  beq lbl_80155bfc;
  b lbl_80155da8;
lbl_8015597c:
  cmpwi r0, 0xe0;
  beq lbl_80155af0;
  b lbl_80155da8;
lbl_80155988:
  cmplwi r3, 8;
  bne lbl_80155da8;
  lbz r0, 0(r5);
  clrlwi. r4, r0, 0x1a;
  stb r4, 0(r30);
  lbz r0, 1(r5);
  clrlwi r0, r0, 0x1c;
  stb r0, 9(r30);
  lbz r0, 1(r5);
  rlwinm r0, r0, 0, 0x18, 0x1b;
  stb r0, 0xa(r30);
  lbz r0, 2(r5);
  clrlwi r0, r0, 0x1a;
  stb r0, 0xb(r30);
  lbz r0, 3(r5);
  stb r0, 0xc(r30);
  lbz r0, 5(r5);
  lbz r3, 4(r5);
  slwi r0, r0, 8;
  add r0, r3, r0;
  sth r0, 0xe(r30);
  lbz r0, 6(r5);
  stb r0, 0x10(r30);
  lbz r0, 7(r5);
  clrlwi r0, r0, 0x1d;
  stb r0, 0x11(r30);
  beq lbl_80155a1c;
  beq lbl_80155a08;
  cmplwi r4, 2;
  blt lbl_80155a1c;
  cmplwi r4, 0x3d;
  bgt lbl_80155a1c;
lbl_80155a08:
  lhz r0, 0xe(r30);
  cmplwi r0, 0x17;
  blt lbl_80155a1c;
  cmplwi r0, 0x7fff;
  ble lbl_80155a40;
lbl_80155a1c:
  lis r3, 0x8034;
  addi r3, r3, -25816;
  lbz r0, 0x414(r3);
  cmplwi r0, 1;
  blt lbl_80155da8;
  addi r4, r7, 0xa8;
  lis r3, 9;
  bl LogMsg_0;
  b lbl_80155da8;
lbl_80155a40:
  mr r3, r29;
  bl GKI_freebuf;
  mr r3, r28;
  mr r4, r31;
  mr r5, r30;
  bl rfc_process_pn;
  b lbl_80155e18;
lbl_80155a5c:
  cmpwi r3, 0;
  beq lbl_80155da8;
  stw r5, 8(r30);
  cmpwi r31, 0;
  sth r6, 0xc(r30);
  lhz r5, 4(r4);
  lhz r3, 2(r4);
  addi r5, r5, 2;
  addi r0, r3, -2;
  sth r5, 4(r4);
  sth r0, 2(r4);
  beq lbl_80155aa0;
  mr r3, r28;
  mr r5, r29;
  li r4, 0;
  bl rfc_send_test;
  b lbl_80155e18;
lbl_80155aa0:
  mr r3, r28;
  mr r4, r29;
  bl rfc_process_test_rsp;
  b lbl_80155e18;
lbl_80155ab0:
  cmpwi r3, 0;
  bne lbl_80155da8;
  mr r3, r29;
  bl GKI_freebuf;
  mr r3, r28;
  mr r4, r31;
  bl rfc_process_fcon;
  b lbl_80155e18;
lbl_80155ad0:
  cmpwi r3, 0;
  bne lbl_80155da8;
  mr r3, r29;
  bl GKI_freebuf;
  mr r3, r28;
  mr r4, r31;
  bl rfc_process_fcoff;
  b lbl_80155e18;
lbl_80155af0:
  lbz r4, 0(r5);
  rlwinm r3, r4, 0, 0x1e, 0x1e;
  clrlwi. r0, r4, 0x1f;
  srawi r0, r3, 1;
  srawi r3, r4, 2;
  stb r3, 0(r30);
  beq lbl_80155b30;
  clrlwi. r0, r0, 0x18;
  beq lbl_80155b30;
  clrlwi. r0, r3, 0x18;
  beq lbl_80155b30;
  beq lbl_80155b54;
  cmplwi r0, 2;
  blt lbl_80155b30;
  cmplwi r0, 0x3d;
  ble lbl_80155b54;
lbl_80155b30:
  lis r3, 0x8034;
  addi r3, r3, -25816;
  lbz r0, 0x414(r3);
  cmplwi r0, 1;
  blt lbl_80155da8;
  addi r4, r7, 0xb8;
  lis r3, 9;
  bl LogMsg_0;
  b lbl_80155da8;
lbl_80155b54:
  clrlwi r0, r8, 0x18;
  lbz r3, 1(r5);
  cmplwi r0, 3;
  stb r3, 9(r30);
  bne lbl_80155b84;
  lbz r0, 2(r5);
  rlwinm r0, r0, 0, 0x1e, 0x1e;
  stb r0, 0xa(r30);
  lbz r0, 2(r5);
  rlwinm r0, r0, 0x1c, 0x1c, 0x1f;
  stb r0, 0xb(r30);
  b lbl_80155b90;
lbl_80155b84:
  li r0, 0;
  stb r0, 0xa(r30);
  stb r0, 0xb(r30);
lbl_80155b90:
  mr r3, r29;
  bl GKI_freebuf;
  mr r3, r28;
  mr r4, r31;
  mr r5, r30;
  bl rfc_process_msc;
  b lbl_80155e18;
lbl_80155bac:
  cmplwi r3, 1;
  bne lbl_80155da8;
  cmpwi r31, 0;
  beq lbl_80155da8;
  lbz r0, 0(r5);
  mr r3, r29;
  clrlwi r0, r0, 0x1f;
  stb r0, 8(r30);
  lbz r0, 0(r5);
  rlwinm r0, r0, 0, 0x1e, 0x1e;
  srawi r0, r0, 1;
  stb r0, 9(r30);
  lbz r0, 0(r5);
  srawi r0, r0, 2;
  stb r0, 0xa(r30);
  bl GKI_freebuf;
  mr r3, r28;
  mr r4, r30;
  bl rfc_process_nsc;
  b lbl_80155e18;
lbl_80155bfc:
  cmplwi r3, 1;
  beq lbl_80155c0c;
  cmplwi r3, 8;
  bne lbl_80155da8;
lbl_80155c0c:
  lbz r4, 0(r5);
  rlwinm r3, r4, 0, 0x1e, 0x1e;
  clrlwi. r0, r4, 0x1f;
  srawi r0, r3, 1;
  srawi r3, r4, 2;
  stb r3, 0(r30);
  beq lbl_80155c4c;
  clrlwi. r0, r0, 0x18;
  beq lbl_80155c4c;
  clrlwi. r0, r3, 0x18;
  beq lbl_80155c4c;
  beq lbl_80155c70;
  cmplwi r0, 2;
  blt lbl_80155c4c;
  cmplwi r0, 0x3d;
  ble lbl_80155c70;
lbl_80155c4c:
  lis r3, 0x8034;
  addi r3, r3, -25816;
  lbz r0, 0x414(r3);
  cmplwi r0, 1;
  blt lbl_80155da8;
  addi r4, r7, 0xc8;
  lis r3, 9;
  bl LogMsg_0;
  b lbl_80155da8;
lbl_80155c70:
  clrlwi r3, r6, 0x10;
  addi r0, r3, -1;
  cntlzw r0, r0;
  rlwinm. r0, r0, 0x1b, 0x18, 0x1f;
  stb r0, 9(r30);
  bne lbl_80155cf4;
  lbz r0, 1(r5);
  stb r0, 0xa(r30);
  lbz r0, 2(r5);
  clrlwi r0, r0, 0x1e;
  stb r0, 0xb(r30);
  lbz r0, 2(r5);
  rlwinm r0, r0, 0x1e, 0x1f, 0x1f;
  stb r0, 0xc(r30);
  lbz r0, 2(r5);
  rlwinm r0, r0, 0x1d, 0x1f, 0x1f;
  stb r0, 0xd(r30);
  lbz r0, 2(r5);
  rlwinm r0, r0, 0x1c, 0x1e, 0x1f;
  stb r0, 0xe(r30);
  lbz r0, 3(r5);
  clrlwi r0, r0, 0x1a;
  stb r0, 0xf(r30);
  lbz r0, 4(r5);
  stb r0, 0x10(r30);
  lbz r0, 5(r5);
  stb r0, 0x11(r30);
  lbz r0, 7(r5);
  lbz r3, 6(r5);
  slwi r0, r0, 8;
  add r0, r3, r0;
  andi. r0, r0, 0x3f7f;
  sth r0, 0x12(r30);
lbl_80155cf4:
  mr r3, r29;
  bl GKI_freebuf;
  lbz r5, 9(r30);
  mr r3, r28;
  mr r4, r31;
  mr r6, r30;
  bl rfc_process_rpn;
  b lbl_80155e18;
lbl_80155d14:
  cmplwi r3, 2;
  bne lbl_80155da8;
  lbz r6, 0(r5);
  rlwinm r3, r6, 0, 0x1e, 0x1e;
  clrlwi. r0, r6, 0x1f;
  srawi r4, r3, 1;
  srawi r3, r6, 2;
  stb r3, 0(r30);
  lbz r0, 1(r5);
  rlwinm r0, r0, 0, 0x18, 0x1e;
  stb r0, 9(r30);
  beq lbl_80155d68;
  clrlwi. r0, r4, 0x18;
  beq lbl_80155d68;
  clrlwi. r0, r3, 0x18;
  beq lbl_80155d68;
  beq lbl_80155d8c;
  cmplwi r0, 2;
  blt lbl_80155d68;
  cmplwi r0, 0x3d;
  ble lbl_80155d8c;
lbl_80155d68:
  lis r3, 0x8034;
  addi r3, r3, -25816;
  lbz r0, 0x414(r3);
  cmplwi r0, 1;
  blt lbl_80155da8;
  addi r4, r7, 0xc8;
  lis r3, 9;
  bl LogMsg_0;
  b lbl_80155da8;
lbl_80155d8c:
  mr r3, r29;
  bl GKI_freebuf;
  mr r3, r28;
  mr r4, r31;
  mr r5, r30;
  bl rfc_process_rls;
  b lbl_80155e18;
lbl_80155da8:
  mr r3, r29;
  bl GKI_freebuf;
  cmpwi r31, 0;
  beq lbl_80155e18;
  li r3, 2;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  beq lbl_80155e18;
  li r0, 0xc;
  lis r7, 0x8034;
  sth r0, 4(r3);
  li r0, 0x11;
  li r8, 3;
  addi r7, r7, -25816;
  stb r0, 0x14(r3);
  mr r5, r3;
  li r4, 0;
  stb r8, 0x15(r3);
  lbz r0, 2(r7);
  lbz r6, 3(r7);
  slwi r0, r0, 1;
  lbz r7, 1(r7);
  or r0, r6, r0;
  or r0, r7, r0;
  stb r0, 0x16(r3);
  sth r8, 2(r3);
  mr r3, r28;
  bl rfc_send_buf_uih;
lbl_80155e18:
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

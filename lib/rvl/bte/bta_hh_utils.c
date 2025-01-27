#include "bta_hh_utils.h"

#include <string.h>

#include "gki_buffer.h"
#include "bte_logmsg.h"
#include "bd.h"
#include "utl.h"

// Symbol: bta_hh_find_cb
// PAL: 0x801378b0..0x801379ec
MARK_BINARY_BLOB(bta_hh_find_cb, 0x801378b0, 0x801379ec);
asm UNKNOWN_FUNCTION(bta_hh_find_cb) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_27;
  lis r31, 0x8033;
  lis r30, 0x8028;
  mr r27, r3;
  li r28, 0;
  addi r30, r30, 0x3260;
  addi r31, r31, 0x6048;
lbl_801378dc:
  rlwinm r29, r28, 5, 0x13, 0x1a;
  mr r3, r27;
  add r4, r31, r29;
  addi r4, r4, 0x18;
  bl bdcmp;
  cmpwi r3, 0;
  bne lbl_80137938;
  mr r3, r27;
  addi r4, r2, -24136;
  bl bdcmp;
  cmpwi r3, 0;
  beq lbl_80137938;
  lbz r0, -0x6610(r13);
  cmplwi r0, 5;
  blt lbl_80137930;
  add r3, r31, r29;
  addi r4, r30, 0;
  lbz r6, 0x26(r3);
  clrlwi r5, r28, 0x18;
  li r3, 0x504;
  bl LogMsg_2;
lbl_80137930:
  mr r3, r28;
  b lbl_801379d4;
lbl_80137938:
  lbz r0, -0x6610(r13);
  cmplwi r0, 5;
  blt lbl_80137964;
  add r8, r31, r29;
  addi r4, r30, 0x24;
  lbz r5, 0x28(r8);
  clrlwi r6, r28, 0x18;
  lbz r7, 0x26(r8);
  li r3, 0x504;
  lbz r8, 0x2c(r8);
  bl LogMsg_4;
lbl_80137964:
  addi r28, r28, 1;
  cmplwi r28, 0x10;
  blt lbl_801378dc;
  lis r4, 0x8033;
  li r0, 0x10;
  addi r4, r4, 0x6048;
  li r29, 0;
  mtctr r0;
lbl_80137984:
  rlwinm r0, r29, 5, 0x13, 0x1a;
  add r3, r4, r0;
  lbz r0, 0x28(r3);
  cmpwi r0, 0;
  bne lbl_801379a8;
  mr r4, r27;
  addi r3, r3, 0x18;
  bl bdcpy;
  b lbl_801379b0;
lbl_801379a8:
  addi r29, r29, 1;
  bdnz lbl_80137984;
lbl_801379b0:
  lbz r0, -0x6610(r13);
  cmplwi r0, 5;
  blt lbl_801379d0;
  addi r4, r30, 0x58;
  clrlwi r5, r29, 0x18;
  li r3, 0x504;
  li r6, 0x10;
  bl LogMsg_2;
lbl_801379d0:
  mr r3, r29;
lbl_801379d4:
  addi r11, r1, 0x20;
  bl _restgpr_27;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: bta_hh_clean_up_kdev
// PAL: 0x801379ec..0x80137a6c
MARK_BINARY_BLOB(bta_hh_clean_up_kdev, 0x801379ec, 0x80137a6c);
asm UNKNOWN_FUNCTION(bta_hh_clean_up_kdev) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  stw r30, 8(r1);
  mr r30, r3;
  lbz r5, 0x16(r3);
  cmplwi r5, 0xff;
  beq lbl_80137a24;
  lis r4, 0x8033;
  li r0, 0x10;
  addi r4, r4, 0x6048;
  add r4, r4, r5;
  stb r0, 0x214(r4);
lbl_80137a24:
  lbz r31, 0x12(r3);
  addi r3, r3, 4;
  bl utl_freebuf;
  mr r3, r30;
  li r4, 0;
  li r5, 0x20;
  bl memset;
  li r3, 1;
  li r0, 0xff;
  stb r31, 0x12(r30);
  stb r3, 0x1c(r30);
  stb r0, 0x16(r30);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: bta_hh_add_device_to_list
// PAL: 0x80137a6c..0x80137b28
MARK_BINARY_BLOB(bta_hh_add_device_to_list, 0x80137a6c, 0x80137b28);
asm UNKNOWN_FUNCTION(bta_hh_add_device_to_list) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_26;
  lbz r0, -0x6610(r13);
  mr r26, r3;
  mr r27, r4;
  mr r28, r5;
  cmplwi r0, 5;
  mr r29, r6;
  mr r30, r7;
  mr r31, r8;
  blt lbl_80137ab8;
  lis r4, 0x8028;
  mr r5, r30;
  addi r4, r4, 0x32e4;
  li r3, 0x504;
  bl LogMsg_1;
lbl_80137ab8:
  li r0, 1;
  cmpwi r29, 0;
  stb r27, 0x16(r26);
  stb r0, 0x18(r26);
  sth r28, 0xe(r26);
  stb r30, 0x13(r26);
  stb r31, 0x15(r26);
  beq lbl_80137b10;
  addi r3, r26, 4;
  bl utl_freebuf;
  lhz r3, 0(r29);
  cmpwi r3, 0;
  beq lbl_80137b10;
  bl GKI_getbuf;
  cmpwi r3, 0;
  stw r3, 4(r26);
  beq lbl_80137b10;
  lhz r0, 0(r29);
  sth r0, 0(r26);
  lwz r4, 4(r29);
  lhz r5, 0(r29);
  bl memcpy;
lbl_80137b10:
  addi r11, r1, 0x20;
  bl _restgpr_26;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: bta_hh_tod_spt
// PAL: 0x80137b28..0x80137b7c
MARK_BINARY_BLOB(bta_hh_tod_spt, 0x80137b28, 0x80137b7c);
asm UNKNOWN_FUNCTION(bta_hh_tod_spt) {
  // clang-format off
  nofralloc;
  lwz r7, -0x73c0(r13);
  rlwinm r9, r4, 0x1e, 0x1a, 0x1f;
  li r8, 0;
  lbz r5, 0(r7);
  b lbl_80137b68;
lbl_80137b3c:
  lwz r4, 4(r7);
  rlwinm r6, r8, 1, 0x17, 0x1e;
  lbzx r0, r4, r6;
  cmplw r9, r0;
  bne lbl_80137b64;
  add r4, r4, r6;
  lbz r0, 1(r4);
  stb r0, 0x15(r3);
  li r3, 1;
  blr;
lbl_80137b64:
  addi r8, r8, 1;
lbl_80137b68:
  clrlwi r0, r8, 0x18;
  cmplw r0, r5;
  blt lbl_80137b3c;
  li r3, 0;
  blr;
  // clang-format on
}

// Symbol: bta_hh_trace_dev_db
// PAL: 0x80137b7c..0x80137c5c
MARK_BINARY_BLOB(bta_hh_trace_dev_db, 0x80137b7c, 0x80137c5c);
asm UNKNOWN_FUNCTION(bta_hh_trace_dev_db) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  lis r30, 0x8028;
  addi r30, r30, 0x3260;
  stw r29, 0x14(r1);
  lbz r0, -0x6610(r13);
  cmplwi r0, 5;
  blt lbl_80137bb4;
  addi r4, r30, 0x1e4;
  li r3, 0x504;
  bl LogMsg_0;
lbl_80137bb4:
  lis r3, 0x8033;
  li r29, 0;
  addi r31, r3, 0x6048;
lbl_80137bc0:
  lbz r0, -0x6610(r13);
  cmplwi r0, 5;
  blt lbl_80137bec;
  rlwinm r0, r29, 5, 0x13, 0x1a;
  addi r4, r30, 0x220;
  add r7, r31, r0;
  clrlwi r5, r29, 0x18;
  lbz r6, 0x28(r7);
  li r3, 0x504;
  lbz r7, 0x26(r7);
  bl LogMsg_3;
lbl_80137bec:
  lbz r0, -0x6610(r13);
  cmplwi r0, 5;
  blt lbl_80137c1c;
  rlwinm r0, r29, 5, 0x13, 0x1a;
  addi r4, r30, 0x244;
  add r8, r31, r0;
  li r3, 0x504;
  lhz r5, 0x1e(r8);
  lbz r6, 0x2c(r8);
  lbz r7, 0x23(r8);
  lbz r8, 0x22(r8);
  bl LogMsg_4;
lbl_80137c1c:
  addi r29, r29, 1;
  cmplwi r29, 0x10;
  blt lbl_80137bc0;
  lbz r0, -0x6610(r13);
  cmplwi r0, 5;
  blt lbl_80137c40;
  addi r4, r30, 0x280;
  li r3, 0x504;
  bl LogMsg_0;
lbl_80137c40:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

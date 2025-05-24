#include "sdp_utils.h"

#include <string.h>

#include "gki_buffer.h"
#include "bte_logmsg.h"
#include "bte_task1.h"
#include "l2c_api.h"

// Symbol: sdpu_find_ccb_by_cid
// PAL: 0x8015ac40..0x8015acd0
MARK_BINARY_BLOB(sdpu_find_ccb_by_cid, 0x8015ac40, 0x8015acd0);
asm UNKNOWN_FUNCTION(sdpu_find_ccb_by_cid) {
  // clang-format off
  nofralloc;
  lis r4, 0x8034;
  addi r4, r4, -24768;
  lbzu r0, 0x3c(r4);
  cmpwi r0, 0;
  beq lbl_8015ac68;
  lhz r0, 0x22(r4);
  cmplw r0, r3;
  bne lbl_8015ac68;
  mr r3, r4;
  blr;
lbl_8015ac68:
  lbzu r0, 0x478(r4);
  cmpwi r0, 0;
  beq lbl_8015ac88;
  lhz r0, 0x22(r4);
  cmplw r0, r3;
  bne lbl_8015ac88;
  mr r3, r4;
  blr;
lbl_8015ac88:
  lbzu r0, 0x478(r4);
  cmpwi r0, 0;
  beq lbl_8015aca8;
  lhz r0, 0x22(r4);
  cmplw r0, r3;
  bne lbl_8015aca8;
  mr r3, r4;
  blr;
lbl_8015aca8:
  lbzu r0, 0x478(r4);
  cmpwi r0, 0;
  beq lbl_8015acc8;
  lhz r0, 0x22(r4);
  cmplw r0, r3;
  bne lbl_8015acc8;
  mr r3, r4;
  blr;
lbl_8015acc8:
  li r3, 0;
  blr;
  // clang-format on
}

// Symbol: sdpu_allocate_ccb
// PAL: 0x8015acd0..0x8015ad44
MARK_BINARY_BLOB(sdpu_allocate_ccb, 0x8015acd0, 0x8015ad44);
asm UNKNOWN_FUNCTION(sdpu_allocate_ccb) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r3, 0x8034;
  li r4, 0;
  stw r0, 0x14(r1);
  li r0, 4;
  addi r3, r3, -24768;
  stw r31, 0xc(r1);
  addi r31, r3, 0x3c;
  mtctr r0;
lbl_8015acf8:
  lbz r0, 0(r31);
  cmpwi r0, 0;
  bne lbl_8015ad20;
  mr r3, r31;
  li r4, 0;
  li r5, 0x478;
  bl memset;
  stw r31, 0x18(r31);
  mr r3, r31;
  b lbl_8015ad30;
lbl_8015ad20:
  addi r4, r4, 1;
  addi r31, r31, 0x478;
  bdnz lbl_8015acf8;
  li r3, 0;
lbl_8015ad30:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: sdpu_release_ccb
// PAL: 0x8015ad44..0x8015ad7c
MARK_BINARY_BLOB(sdpu_release_ccb, 0x8015ad44, 0x8015ad7c);
asm UNKNOWN_FUNCTION(sdpu_release_ccb) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  addi r3, r3, 8;
  bl btu_stop_timer;
  li r0, 0;
  stb r0, 0(r31);
  lwz r31, 0xc(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: sdpu_build_attrib_seq
// PAL: 0x8015ad7c..0x8015af4c
MARK_BINARY_BLOB(sdpu_build_attrib_seq, 0x8015ad7c, 0x8015af4c);
asm UNKNOWN_FUNCTION(sdpu_build_attrib_seq) {
  // clang-format off
  nofralloc;
  cmpwi r4, 0;
  beq lbl_8015ad94;
  slwi r0, r5, 2;
  subf r0, r5, r0;
  clrlwi r7, r0, 0x10;
  b lbl_8015ad98;
lbl_8015ad94:
  li r7, 5;
lbl_8015ad98:
  cmplwi r7, 0xff;
  ble lbl_8015adbc;
  rlwinm r0, r7, 0x18, 0x18, 0x1f;
  li r6, 0x36;
  stb r6, 0(r3);
  addi r6, r3, 3;
  stb r0, 1(r3);
  stb r7, 2(r3);
  b lbl_8015adcc;
lbl_8015adbc:
  li r0, 0x35;
  stb r7, 1(r3);
  addi r6, r3, 2;
  stb r0, 0(r3);
lbl_8015adcc:
  cmpwi r4, 0;
  bne lbl_8015adfc;
  li r0, 0xa;
  li r3, 0;
  stb r0, 0(r6);
  li r0, 0xff;
  stb r3, 1(r6);
  stb r3, 2(r6);
  stb r0, 3(r6);
  stb r0, 4(r6);
  addi r6, r6, 5;
  b lbl_8015af44;
lbl_8015adfc:
  cmpwi r5, 0;
  li r3, 0;
  beq lbl_8015af44;
  cmplwi r5, 8;
  addis r7, r5, 1;
  addi r7, r7, -8;
  ble lbl_8015af04;
  clrlwi r8, r7, 0x10;
  li r0, 9;
  addi r7, r8, 7;
  srwi r7, r7, 3;
  mtctr r7;
  cmplwi r8, 0;
  ble lbl_8015af04;
lbl_8015ae34:
  stb r0, 0(r6);
  addi r3, r3, 8;
  lhz r7, 0(r4);
  srawi r7, r7, 8;
  stb r7, 1(r6);
  lhz r7, 0(r4);
  stb r7, 2(r6);
  stb r0, 3(r6);
  lhz r7, 2(r4);
  srawi r7, r7, 8;
  stb r7, 4(r6);
  lhz r7, 2(r4);
  stb r7, 5(r6);
  stb r0, 6(r6);
  lhz r7, 4(r4);
  srawi r7, r7, 8;
  stb r7, 7(r6);
  lhz r7, 4(r4);
  stb r7, 8(r6);
  stb r0, 9(r6);
  lhz r7, 6(r4);
  srawi r7, r7, 8;
  stb r7, 0xa(r6);
  lhz r7, 6(r4);
  stb r7, 0xb(r6);
  stb r0, 0xc(r6);
  lhz r7, 8(r4);
  srawi r7, r7, 8;
  stb r7, 0xd(r6);
  lhz r7, 8(r4);
  stb r7, 0xe(r6);
  stb r0, 0xf(r6);
  lhz r7, 0xa(r4);
  srawi r7, r7, 8;
  stb r7, 0x10(r6);
  lhz r7, 0xa(r4);
  stb r7, 0x11(r6);
  stb r0, 0x12(r6);
  lhz r7, 0xc(r4);
  srawi r7, r7, 8;
  stb r7, 0x13(r6);
  lhz r7, 0xc(r4);
  stb r7, 0x14(r6);
  stb r0, 0x15(r6);
  lhz r7, 0xe(r4);
  srawi r7, r7, 8;
  stb r7, 0x16(r6);
  lhz r7, 0xe(r4);
  addi r4, r4, 0x10;
  stb r7, 0x17(r6);
  addi r6, r6, 0x18;
  bdnz lbl_8015ae34;
lbl_8015af04:
  clrlwi r7, r3, 0x10;
  li r8, 9;
  subf r0, r7, r5;
  mtctr r0;
  cmplw r7, r5;
  bge lbl_8015af44;
lbl_8015af1c:
  stb r8, 0(r6);
  addi r3, r3, 1;
  lhz r0, 0(r4);
  srawi r0, r0, 8;
  stb r0, 1(r6);
  lhz r0, 0(r4);
  addi r4, r4, 2;
  stb r0, 2(r6);
  addi r6, r6, 3;
  bdnz lbl_8015af1c;
lbl_8015af44:
  mr r3, r6;
  blr;
  // clang-format on
}

// Symbol: sdpu_build_attrib_entry
// PAL: 0x8015af4c..0x8015b0a0
MARK_BINARY_BLOB(sdpu_build_attrib_entry, 0x8015af4c, 0x8015b0a0);
asm UNKNOWN_FUNCTION(sdpu_build_attrib_entry) {
  // clang-format off
  nofralloc;
  li r0, 9;
  stb r0, 0(r3);
  lhz r0, 8(r4);
  srawi r0, r0, 8;
  stb r0, 1(r3);
  lhz r0, 8(r4);
  stb r0, 2(r3);
  lbz r6, 0xa(r4);
  cmpwi r6, 5;
  beq lbl_8015afd4;
  bge lbl_8015af84;
  cmpwi r6, 4;
  bge lbl_8015af8c;
  b lbl_8015afd4;
lbl_8015af84:
  cmpwi r6, 9;
  bge lbl_8015afd4;
lbl_8015af8c:
  rlwinm r0, r6, 3, 0x15, 0x1c;
  addi r6, r3, 5;
  ori r0, r0, 5;
  li r5, 0;
  stb r0, 3(r3);
  lwz r0, 0(r4);
  stb r0, 4(r3);
  b lbl_8015afc0;
lbl_8015afac:
  lwz r3, 4(r4);
  lbzx r0, r3, r5;
  addi r5, r5, 1;
  stb r0, 0(r6);
  addi r6, r6, 1;
lbl_8015afc0:
  lwz r0, 0(r4);
  cmpw r5, r0;
  blt lbl_8015afac;
  mr r3, r6;
  blr;
lbl_8015afd4:
  lwz r0, 0(r4);
  cmplwi r0, 0x10;
  bgt lbl_8015b058;
  lis r5, 0x8028;
  slwi r0, r0, 2;
  addi r5, r5, 0x7da8;
  lwzx r5, r5, r0;
  mtctr r5;
  bctr;
  rlwinm r0, r6, 3, 0x18, 0x1c;
  addi r6, r3, 4;
  stb r0, 3(r3);
  b lbl_8015b070;
  rlwinm r0, r6, 3, 0x15, 0x1c;
  addi r6, r3, 4;
  ori r0, r0, 1;
  stb r0, 3(r3);
  b lbl_8015b070;
  rlwinm r0, r6, 3, 0x15, 0x1c;
  addi r6, r3, 4;
  ori r0, r0, 2;
  stb r0, 3(r3);
  b lbl_8015b070;
  rlwinm r0, r6, 3, 0x15, 0x1c;
  addi r6, r3, 4;
  ori r0, r0, 3;
  stb r0, 3(r3);
  b lbl_8015b070;
  rlwinm r0, r6, 3, 0x15, 0x1c;
  addi r6, r3, 4;
  ori r0, r0, 4;
  stb r0, 3(r3);
  b lbl_8015b070;
lbl_8015b058:
  rlwinm r0, r6, 3, 0x15, 0x1c;
  addi r6, r3, 5;
  ori r0, r0, 5;
  stb r0, 3(r3);
  lwz r0, 0(r4);
  stb r0, 4(r3);
lbl_8015b070:
  li r5, 0;
  b lbl_8015b08c;
lbl_8015b078:
  lwz r3, 4(r4);
  lbzx r0, r3, r5;
  addi r5, r5, 1;
  stb r0, 0(r6);
  addi r6, r6, 1;
lbl_8015b08c:
  lwz r0, 0(r4);
  cmpw r5, r0;
  blt lbl_8015b078;
  mr r3, r6;
  blr;
  // clang-format on
}

// Symbol: sdpu_build_n_send_error
// PAL: 0x8015b0a0..0x8015b1dc
MARK_BINARY_BLOB(sdpu_build_n_send_error, 0x8015b0a0, 0x8015b1dc);
asm UNKNOWN_FUNCTION(sdpu_build_n_send_error) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_24;
  lis r7, 0x8034;
  mr r31, r3;
  addi r7, r7, -24768;
  mr r30, r4;
  lbz r0, 0x4630(r7);
  mr r25, r5;
  mr r24, r6;
  cmplwi r0, 2;
  blt lbl_8015b0f0;
  lis r3, 0xa;
  lis r4, 0x8028;
  lhz r6, 0x22(r31);
  addi r3, r3, 1;
  addi r4, r4, 0x7dec;
  bl LogMsg_2;
lbl_8015b0f0:
  li r3, 2;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  mr r26, r3;
  bne lbl_8015b12c;
  lis r3, 0x8034;
  addi r3, r3, -24768;
  lbz r0, 0x4630(r3);
  cmplwi r0, 1;
  blt lbl_8015b1c4;
  lis r4, 0x8028;
  lis r3, 0xa;
  addi r4, r4, 0x7e24;
  bl LogMsg_0;
  b lbl_8015b1c4;
lbl_8015b12c:
  li r0, 9;
  addi r28, r3, 0x11;
  sth r0, 4(r3);
  li r0, 1;
  addi r29, r28, 3;
  srawi r3, r30, 8;
  stb r0, 0(r28);
  mr r27, r29;
  rlwinm r0, r25, 0x18, 0x18, 0x1f;
  cmpwi r24, 0;
  stb r3, 1(r28);
  addi r29, r29, 4;
  stb r30, 2(r28);
  stb r0, 5(r28);
  stb r25, 6(r28);
  beq lbl_8015b19c;
  mr r30, r24;
  li r25, 0;
  b lbl_8015b18c;
lbl_8015b178:
  lbz r0, 0(r30);
  addi r25, r25, 1;
  addi r30, r30, 1;
  stb r0, 0(r29);
  addi r29, r29, 1;
lbl_8015b18c:
  mr r3, r24;
  bl strlen;
  cmpw r25, r3;
  blt lbl_8015b178;
lbl_8015b19c:
  subf r3, r27, r29;
  subf r0, r28, r29;
  addi r5, r3, -2;
  mr r4, r26;
  rlwinm r3, r5, 0x18, 0x18, 0x1f;
  stb r3, 0(r27);
  stb r5, 1(r27);
  sth r0, 2(r26);
  lhz r3, 0x22(r31);
  bl L2CA_DataWrite;
lbl_8015b1c4:
  addi r11, r1, 0x30;
  bl _restgpr_24;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: sdpu_extract_uid_seq
// PAL: 0x8015b1dc..0x8015b52c
MARK_BINARY_BLOB(sdpu_extract_uid_seq, 0x8015b1dc, 0x8015b52c);
asm UNKNOWN_FUNCTION(sdpu_extract_uid_seq) {
  // clang-format off
  nofralloc;
  li r0, 0;
  addi r8, r3, 1;
  sth r0, 0(r5);
  lbz r3, 0(r3);
  srawi r0, r3, 3;
  clrlwi r6, r3, 0x1d;
  cmplwi r0, 6;
  beq lbl_8015b204;
  li r3, 0;
  blr;
lbl_8015b204:
  cmplwi r6, 7;
  bgt lbl_8015b294;
  lis r3, 0x8028;
  slwi r0, r6, 2;
  addi r3, r3, 0x7e60;
  lwzx r3, r3, r0;
  mtctr r3;
  bctr;
  li r0, 2;
  b lbl_8015b29c;
  li r0, 4;
  b lbl_8015b29c;
  li r0, 0x10;
  b lbl_8015b29c;
  lbz r0, 0(r8);
  addi r8, r8, 1;
  b lbl_8015b29c;
  lbz r3, 0(r8);
  lbz r0, 1(r8);
  addi r8, r8, 2;
  slwi r3, r3, 8;
  add r0, r3, r0;
  clrlwi r0, r0, 0x10;
  b lbl_8015b29c;
  lbz r6, 0(r8);
  lbz r3, 1(r8);
  lbz r0, 2(r8);
  slwi r7, r6, 0x18;
  lbz r6, 3(r8);
  slwi r3, r3, 0x10;
  slwi r0, r0, 8;
  addi r8, r8, 4;
  add r3, r7, r3;
  add r0, r6, r0;
  add r0, r3, r0;
  b lbl_8015b29c;
lbl_8015b294:
  li r3, 0;
  blr;
lbl_8015b29c:
  cmplw r0, r4;
  blt lbl_8015b2ac;
  li r3, 0;
  blr;
lbl_8015b2ac:
  add r0, r8, r0;
  lis r4, 0x8028;
  lis r3, 0x8000;
  b lbl_8015b510;
lbl_8015b2bc:
  lbz r7, 0(r8);
  addi r8, r8, 1;
  srawi r6, r7, 3;
  clrlwi r9, r7, 0x1d;
  cmplwi r6, 3;
  beq lbl_8015b2dc;
  li r3, 0;
  blr;
lbl_8015b2dc:
  cmplwi r9, 7;
  bgt lbl_8015b368;
  addi r7, r4, 0x7e40;
  slwi r6, r9, 2;
  lwzx r7, r7, r6;
  mtctr r7;
  bctr;
  li r6, 2;
  b lbl_8015b370;
  li r6, 4;
  b lbl_8015b370;
  li r6, 0x10;
  b lbl_8015b370;
  lbz r6, 0(r8);
  addi r8, r8, 1;
  b lbl_8015b370;
  lbz r7, 0(r8);
  lbz r6, 1(r8);
  addi r8, r8, 2;
  slwi r7, r7, 8;
  add r6, r7, r6;
  clrlwi r6, r6, 0x10;
  b lbl_8015b370;
  lbz r9, 0(r8);
  lbz r7, 1(r8);
  lbz r6, 2(r8);
  slwi r10, r9, 0x18;
  lbz r9, 3(r8);
  slwi r7, r7, 0x10;
  slwi r6, r6, 8;
  addi r8, r8, 4;
  add r7, r10, r7;
  add r6, r9, r6;
  add r6, r7, r6;
  b lbl_8015b370;
lbl_8015b368:
  li r3, 0;
  blr;
lbl_8015b370:
  cmplwi r6, 2;
  beq lbl_8015b388;
  cmplwi r6, 4;
  beq lbl_8015b388;
  cmplwi r6, 0x10;
  bne lbl_8015b4f4;
lbl_8015b388:
  lhz r9, 0(r5);
  cmpwi cr1, r6, 0;
  li r7, 0;
  mulli r9, r9, 0x12;
  add r9, r5, r9;
  sth r6, 2(r9);
  ble cr1, lbl_8015b4e4;
  cmpwi r6, 8;
  addi r10, r6, -8;
  ble lbl_8015b4b0;
  li r11, 0;
  blt cr1, lbl_8015b3c8;
  addi r9, r3, -2;
  cmpw r6, r9;
  bgt lbl_8015b3c8;
  li r11, 1;
lbl_8015b3c8:
  cmpwi r11, 0;
  beq lbl_8015b4b0;
  addi r9, r10, 7;
  srwi r9, r9, 3;
  mtctr r9;
  cmpwi r10, 0;
  ble lbl_8015b4b0;
lbl_8015b3e4:
  lhz r9, 0(r5);
  lbz r10, 0(r8);
  mulli r9, r9, 0x12;
  add r9, r5, r9;
  add r9, r9, r7;
  stb r10, 4(r9);
  lhz r9, 0(r5);
  lbz r10, 1(r8);
  mulli r9, r9, 0x12;
  add r9, r5, r9;
  add r9, r9, r7;
  stb r10, 5(r9);
  lhz r9, 0(r5);
  lbz r10, 2(r8);
  mulli r9, r9, 0x12;
  add r9, r5, r9;
  add r9, r9, r7;
  stb r10, 6(r9);
  lhz r9, 0(r5);
  lbz r10, 3(r8);
  mulli r9, r9, 0x12;
  add r9, r5, r9;
  add r9, r9, r7;
  stb r10, 7(r9);
  lhz r9, 0(r5);
  lbz r10, 4(r8);
  mulli r9, r9, 0x12;
  add r9, r5, r9;
  add r9, r9, r7;
  stb r10, 8(r9);
  lhz r9, 0(r5);
  lbz r10, 5(r8);
  mulli r9, r9, 0x12;
  add r9, r5, r9;
  add r9, r9, r7;
  stb r10, 9(r9);
  lhz r9, 0(r5);
  lbz r10, 6(r8);
  mulli r9, r9, 0x12;
  add r9, r5, r9;
  add r9, r9, r7;
  stb r10, 0xa(r9);
  lhz r9, 0(r5);
  lbz r10, 7(r8);
  addi r8, r8, 8;
  mulli r9, r9, 0x12;
  add r9, r5, r9;
  add r9, r9, r7;
  addi r7, r7, 8;
  stb r10, 0xb(r9);
  bdnz lbl_8015b3e4;
lbl_8015b4b0:
  subf r9, r7, r6;
  mtctr r9;
  cmpw r7, r6;
  bge lbl_8015b4e4;
lbl_8015b4c0:
  lhz r6, 0(r5);
  lbz r9, 0(r8);
  addi r8, r8, 1;
  mulli r6, r6, 0x12;
  add r6, r5, r6;
  add r6, r6, r7;
  addi r7, r7, 1;
  stb r9, 4(r6);
  bdnz lbl_8015b4c0;
lbl_8015b4e4:
  lhz r6, 0(r5);
  addi r6, r6, 1;
  sth r6, 0(r5);
  b lbl_8015b4fc;
lbl_8015b4f4:
  li r3, 0;
  blr;
lbl_8015b4fc:
  clrlwi r6, r6, 0x10;
  cmplwi r6, 0x10;
  blt lbl_8015b510;
  li r3, 0;
  blr;
lbl_8015b510:
  cmplw r8, r0;
  blt lbl_8015b2bc;
  beq lbl_8015b524;
  li r3, 0;
  blr;
lbl_8015b524:
  mr r3, r8;
  blr;
  // clang-format on
}

// Symbol: sdpu_extract_attr_seq
// PAL: 0x8015b52c..0x8015b77c
MARK_BINARY_BLOB(sdpu_extract_attr_seq, 0x8015b52c, 0x8015b77c);
asm UNKNOWN_FUNCTION(sdpu_extract_attr_seq) {
  // clang-format off
  nofralloc;
  li r0, 0;
  sth r0, 0(r5);
  lbz r6, 0(r3);
  srawi r0, r6, 3;
  clrlwi r6, r6, 0x1d;
  cmplwi r0, 6;
  beq lbl_8015b550;
  addi r3, r3, 1;
  blr;
lbl_8015b550:
  cmpwi r6, 6;
  beq lbl_8015b580;
  bge lbl_8015b568;
  cmpwi r6, 5;
  bge lbl_8015b574;
  b lbl_8015b5cc;
lbl_8015b568:
  cmpwi r6, 8;
  bge lbl_8015b5cc;
  b lbl_8015b59c;
lbl_8015b574:
  lbz r0, 1(r3);
  addi r6, r3, 2;
  b lbl_8015b5d4;
lbl_8015b580:
  lbz r7, 1(r3);
  addi r6, r3, 3;
  lbz r0, 2(r3);
  slwi r3, r7, 8;
  add r0, r3, r0;
  clrlwi r0, r0, 0x10;
  b lbl_8015b5d4;
lbl_8015b59c:
  lbz r8, 1(r3);
  addi r6, r3, 5;
  lbz r7, 2(r3);
  lbz r0, 3(r3);
  slwi r8, r8, 0x18;
  lbz r3, 4(r3);
  slwi r7, r7, 0x10;
  slwi r0, r0, 8;
  add r3, r7, r3;
  add r0, r8, r0;
  add r0, r3, r0;
  b lbl_8015b5d4;
lbl_8015b5cc:
  addi r3, r3, 1;
  blr;
lbl_8015b5d4:
  cmplw r0, r4;
  ble lbl_8015b5e4;
  mr r3, r6;
  blr;
lbl_8015b5e4:
  add r0, r6, r0;
  b lbl_8015b76c;
lbl_8015b5ec:
  lbz r4, 0(r6);
  addi r6, r6, 1;
  srawi r3, r4, 3;
  clrlwi r4, r4, 0x1d;
  cmplwi r3, 1;
  beq lbl_8015b60c;
  mr r3, r6;
  blr;
lbl_8015b60c:
  cmpwi r4, 5;
  beq lbl_8015b650;
  bge lbl_8015b630;
  cmpwi r4, 2;
  beq lbl_8015b648;
  bge lbl_8015b6a8;
  cmpwi r4, 1;
  bge lbl_8015b640;
  b lbl_8015b6a8;
lbl_8015b630:
  cmpwi r4, 7;
  beq lbl_8015b678;
  bge lbl_8015b6a8;
  b lbl_8015b65c;
lbl_8015b640:
  li r3, 2;
  b lbl_8015b6b0;
lbl_8015b648:
  li r3, 4;
  b lbl_8015b6b0;
lbl_8015b650:
  lbz r3, 0(r6);
  addi r6, r6, 1;
  b lbl_8015b6b0;
lbl_8015b65c:
  lbz r4, 0(r6);
  lbz r3, 1(r6);
  addi r6, r6, 2;
  slwi r4, r4, 8;
  add r3, r4, r3;
  clrlwi r3, r3, 0x10;
  b lbl_8015b6b0;
lbl_8015b678:
  lbz r7, 0(r6);
  lbz r4, 1(r6);
  lbz r3, 2(r6);
  slwi r8, r7, 0x18;
  lbz r7, 3(r6);
  slwi r4, r4, 0x10;
  slwi r3, r3, 8;
  addi r6, r6, 4;
  add r4, r8, r4;
  add r3, r7, r3;
  add r3, r4, r3;
  b lbl_8015b6b0;
lbl_8015b6a8:
  li r3, 0;
  blr;
lbl_8015b6b0:
  cmplwi r3, 2;
  bne lbl_8015b6f4;
  lbz r7, 0(r6);
  lhz r3, 0(r5);
  lbz r4, 1(r6);
  slwi r7, r7, 8;
  slwi r3, r3, 2;
  addi r6, r6, 2;
  add r4, r7, r4;
  add r3, r5, r3;
  sth r4, 2(r3);
  lhz r3, 0(r5);
  slwi r3, r3, 2;
  add r4, r5, r3;
  lhz r3, 2(r4);
  sth r3, 4(r4);
  b lbl_8015b74c;
lbl_8015b6f4:
  cmplwi r3, 4;
  bne lbl_8015b744;
  lbz r7, 0(r6);
  lhz r3, 0(r5);
  lbz r4, 1(r6);
  slwi r7, r7, 8;
  slwi r3, r3, 2;
  add r4, r7, r4;
  add r3, r5, r3;
  sth r4, 2(r3);
  lbz r7, 2(r6);
  lhz r3, 0(r5);
  lbz r4, 3(r6);
  slwi r7, r7, 8;
  slwi r3, r3, 2;
  addi r6, r6, 4;
  add r4, r7, r4;
  add r3, r5, r3;
  sth r4, 4(r3);
  b lbl_8015b74c;
lbl_8015b744:
  li r3, 0;
  blr;
lbl_8015b74c:
  lhz r3, 0(r5);
  addi r4, r3, 1;
  clrlwi r3, r4, 0x10;
  sth r4, 0(r5);
  cmplwi r3, 0x10;
  blt lbl_8015b76c;
  li r3, 0;
  blr;
lbl_8015b76c:
  cmplw r6, r0;
  blt lbl_8015b5ec;
  mr r3, r6;
  blr;
  // clang-format on
}

// Symbol: sdpu_get_len_from_type
// PAL: 0x8015b77c..0x8015b84c
MARK_BINARY_BLOB(sdpu_get_len_from_type, 0x8015b77c, 0x8015b84c);
asm UNKNOWN_FUNCTION(sdpu_get_len_from_type) {
  // clang-format off
  nofralloc;
  clrlwi r0, r4, 0x1d;
  mr r8, r3;
  cmplwi r0, 7;
  bgt lbl_8015b844;
  lis r4, 0x8028;
  slwi r0, r0, 2;
  addi r4, r4, 0x7e80;
  lwzx r4, r4, r0;
  mtctr r4;
  bctr;
  li r0, 1;
  stw r0, 0(r5);
  b lbl_8015b844;
  li r0, 2;
  stw r0, 0(r5);
  b lbl_8015b844;
  li r0, 4;
  stw r0, 0(r5);
  b lbl_8015b844;
  li r0, 8;
  stw r0, 0(r5);
  b lbl_8015b844;
  li r0, 0x10;
  stw r0, 0(r5);
  b lbl_8015b844;
  lbz r0, 0(r3);
  addi r8, r3, 1;
  stw r0, 0(r5);
  b lbl_8015b844;
  lbz r4, 0(r3);
  addi r8, r3, 2;
  lbz r0, 1(r3);
  slwi r3, r4, 8;
  add r0, r3, r0;
  clrlwi r0, r0, 0x10;
  stw r0, 0(r5);
  b lbl_8015b844;
  lbz r6, 0(r3);
  addi r8, r3, 4;
  lbz r0, 2(r3);
  lbz r4, 1(r3);
  slwi r7, r6, 0x18;
  slwi r0, r0, 8;
  slwi r6, r4, 0x10;
  lbz r4, 3(r3);
  add r3, r7, r6;
  add r0, r4, r0;
  add r0, r3, r0;
  clrlwi r0, r0, 0x10;
  stw r0, 0(r5);
lbl_8015b844:
  mr r3, r8;
  blr;
  // clang-format on
}

// Symbol: sdpu_is_base_uuid
// PAL: 0x8015b84c..0x8015b92c
MARK_BINARY_BLOB(sdpu_is_base_uuid, 0x8015b84c, 0x8015b92c);
asm UNKNOWN_FUNCTION(sdpu_is_base_uuid) {
  // clang-format off
  nofralloc;
  lis r5, 0x8025;
  li r0, 2;
  addi r5, r5, -13496;
  li r6, 4;
  mtctr r0;
lbl_8015b860:
  clrlwi r0, r6, 0x10;
  lbzx r4, r5, r0;
  lbzx r0, r3, r0;
  cmplw r4, r0;
  beq lbl_8015b87c;
  li r3, 0;
  blr;
lbl_8015b87c:
  addi r6, r6, 1;
  clrlwi r0, r6, 0x10;
  lbzx r4, r5, r0;
  lbzx r0, r3, r0;
  cmplw r4, r0;
  beq lbl_8015b89c;
  li r3, 0;
  blr;
lbl_8015b89c:
  addi r6, r6, 1;
  clrlwi r0, r6, 0x10;
  lbzx r4, r5, r0;
  lbzx r0, r3, r0;
  cmplw r4, r0;
  beq lbl_8015b8bc;
  li r3, 0;
  blr;
lbl_8015b8bc:
  addi r6, r6, 1;
  clrlwi r0, r6, 0x10;
  lbzx r4, r5, r0;
  lbzx r0, r3, r0;
  cmplw r4, r0;
  beq lbl_8015b8dc;
  li r3, 0;
  blr;
lbl_8015b8dc:
  addi r6, r6, 1;
  clrlwi r0, r6, 0x10;
  lbzx r4, r5, r0;
  lbzx r0, r3, r0;
  cmplw r4, r0;
  beq lbl_8015b8fc;
  li r3, 0;
  blr;
lbl_8015b8fc:
  addi r6, r6, 1;
  clrlwi r0, r6, 0x10;
  lbzx r4, r5, r0;
  lbzx r0, r3, r0;
  cmplw r4, r0;
  beq lbl_8015b91c;
  li r3, 0;
  blr;
lbl_8015b91c:
  addi r6, r6, 1;
  bdnz lbl_8015b860;
  li r3, 1;
  blr;
  // clang-format on
}

// Symbol: sdpu_compare_uuid_arrays
// PAL: 0x8015b92c..0x8015bba0
MARK_BINARY_BLOB(sdpu_compare_uuid_arrays, 0x8015b92c, 0x8015bba0);
asm UNKNOWN_FUNCTION(sdpu_compare_uuid_arrays) {
  // clang-format off
  nofralloc;
  stwu r1, -0x40(r1);
  mflr r0;
  cmplw r4, r6;
  stw r0, 0x44(r1);
  stw r31, 0x3c(r1);
  mr r31, r6;
  stw r30, 0x38(r1);
  mr r30, r5;
  stw r29, 0x34(r1);
  mr r29, r4;
  stw r28, 0x30(r1);
  mr r28, r3;
  bne lbl_8015ba08;
  cmplwi r4, 2;
  bne lbl_8015b998;
  lbz r4, 0(r3);
  li r6, 0;
  lbz r0, 0(r5);
  cmplw r4, r0;
  bne lbl_8015b990;
  lbz r3, 1(r3);
  lbz r0, 1(r5);
  cmplw r3, r0;
  bne lbl_8015b990;
  li r6, 1;
lbl_8015b990:
  mr r3, r6;
  b lbl_8015bb80;
lbl_8015b998:
  cmplwi r4, 4;
  bne lbl_8015b9ec;
  lbz r4, 0(r3);
  li r6, 0;
  lbz r0, 0(r5);
  cmplw r4, r0;
  bne lbl_8015ba00;
  lbz r4, 1(r3);
  lbz r0, 1(r5);
  cmplw r4, r0;
  bne lbl_8015ba00;
  lbz r4, 2(r3);
  lbz r0, 2(r5);
  cmplw r4, r0;
  bne lbl_8015ba00;
  lbz r3, 3(r3);
  lbz r0, 3(r5);
  cmplw r3, r0;
  bne lbl_8015ba00;
  li r6, 1;
  b lbl_8015ba00;
lbl_8015b9ec:
  mr r4, r30;
  mr r5, r29;
  bl memcmp;
  cntlzw r0, r3;
  rlwinm r6, r0, 0x1b, 0x18, 0x1f;
lbl_8015ba00:
  mr r3, r6;
  b lbl_8015bb80;
lbl_8015ba08:
  ble lbl_8015bac8;
  cmplwi r4, 4;
  bne lbl_8015ba5c;
  lbz r0, 0(r3);
  li r6, 0;
  cmpwi r0, 0;
  bne lbl_8015ba54;
  lbz r0, 1(r3);
  cmpwi r0, 0;
  bne lbl_8015ba54;
  lbz r4, 2(r3);
  lbz r0, 0(r5);
  cmplw r4, r0;
  bne lbl_8015ba54;
  lbz r3, 3(r3);
  lbz r0, 1(r5);
  cmplw r3, r0;
  bne lbl_8015ba54;
  li r6, 1;
lbl_8015ba54:
  mr r3, r6;
  b lbl_8015bb80;
lbl_8015ba5c:
  mr r4, r28;
  addi r3, r1, 0x18;
  li r5, 0x10;
  bl memcpy;
  lis r4, 0x8025;
  addi r3, r1, 8;
  addi r4, r4, -13496;
  li r5, 0x10;
  bl memcpy;
  cmplwi r31, 4;
  bne lbl_8015ba9c;
  mr r4, r30;
  mr r5, r31;
  addi r3, r1, 8;
  bl memcpy;
  b lbl_8015baac;
lbl_8015ba9c:
  mr r4, r30;
  mr r5, r31;
  addi r3, r1, 0xa;
  bl memcpy;
lbl_8015baac:
  addi r3, r1, 0x18;
  addi r4, r1, 8;
  li r5, 0x10;
  bl memcmp;
  cntlzw r0, r3;
  rlwinm r3, r0, 0x1b, 0x18, 0x1f;
  b lbl_8015bb80;
lbl_8015bac8:
  cmplwi r6, 4;
  bne lbl_8015bb18;
  lbz r0, 0(r5);
  li r6, 0;
  cmpwi r0, 0;
  bne lbl_8015bb10;
  lbz r0, 1(r5);
  cmpwi r0, 0;
  bne lbl_8015bb10;
  lbz r4, 2(r5);
  lbz r0, 0(r3);
  cmplw r4, r0;
  bne lbl_8015bb10;
  lbz r4, 3(r5);
  lbz r0, 1(r3);
  cmplw r4, r0;
  bne lbl_8015bb10;
  li r6, 1;
lbl_8015bb10:
  mr r3, r6;
  b lbl_8015bb80;
lbl_8015bb18:
  mr r4, r30;
  addi r3, r1, 8;
  li r5, 0x10;
  bl memcpy;
  lis r4, 0x8025;
  addi r3, r1, 0x18;
  addi r4, r4, -13496;
  li r5, 0x10;
  bl memcpy;
  cmplwi r29, 4;
  bne lbl_8015bb58;
  mr r4, r28;
  mr r5, r29;
  addi r3, r1, 0x18;
  bl memcpy;
  b lbl_8015bb68;
lbl_8015bb58:
  mr r4, r28;
  mr r5, r29;
  addi r3, r1, 0x1a;
  bl memcpy;
lbl_8015bb68:
  addi r3, r1, 0x18;
  addi r4, r1, 8;
  li r5, 0x10;
  bl memcmp;
  cntlzw r0, r3;
  rlwinm r3, r0, 0x1b, 0x18, 0x1f;
lbl_8015bb80:
  lwz r0, 0x44(r1);
  lwz r31, 0x3c(r1);
  lwz r30, 0x38(r1);
  lwz r29, 0x34(r1);
  lwz r28, 0x30(r1);
  mtlr r0;
  addi r1, r1, 0x40;
  blr;
  // clang-format on
}

// Symbol: sdpu_compare_uuid_with_attr
// PAL: 0x8015bba0..0x8015bc30
MARK_BINARY_BLOB(sdpu_compare_uuid_with_attr, 0x8015bba0, 0x8015bc30);
asm UNKNOWN_FUNCTION(sdpu_compare_uuid_with_attr) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  lhz r0, 6(r4);
  lhz r5, 0(r3);
  clrlwi r0, r0, 0x14;
  cmplw r5, r0;
  beq lbl_8015bbc8;
  li r3, 0;
  b lbl_8015bc20;
lbl_8015bbc8:
  cmplwi r5, 2;
  bne lbl_8015bbe8;
  lhz r3, 4(r3);
  lhz r0, 8(r4);
  subf r0, r3, r0;
  cntlzw r0, r0;
  rlwinm r3, r0, 0x1b, 0x18, 0x1f;
  b lbl_8015bc20;
lbl_8015bbe8:
  cmplwi r5, 4;
  bne lbl_8015bc08;
  lwz r3, 4(r3);
  lwz r0, 8(r4);
  subf r0, r3, r0;
  cntlzw r0, r0;
  rlwinm r3, r0, 0x1b, 0x18, 0x1f;
  b lbl_8015bc20;
lbl_8015bc08:
  li r5, 0x10;
  addi r3, r3, 4;
  addi r4, r4, 8;
  bl memcmp;
  cntlzw r0, r3;
  rlwinm r3, r0, 0x1b, 0x18, 0x1f;
lbl_8015bc20:
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: sdpu_sort_attr_list
// PAL: 0x8015bc30..0x8015bc80
MARK_BINARY_BLOB(sdpu_sort_attr_list, 0x8015bc30, 0x8015bc80);
asm UNKNOWN_FUNCTION(sdpu_sort_attr_list) {
  // clang-format off
  nofralloc;
  cmplwi r3, 1;
  blelr;
  addi r5, r3, -1;
  li r8, 0;
  lis r3, 1;
  b lbl_8015bc70;
lbl_8015bc48:
  rlwinm r0, r8, 1, 0xf, 0x1e;
  add r7, r4, r0;
  lhz r6, 0x50(r7);
  lhz r0, 0x4e(r7);
  cmplw r0, r6;
  ble lbl_8015bc6c;
  sth r6, 0x4e(r7);
  addi r8, r3, -1;
  sth r0, 0x50(r7);
lbl_8015bc6c:
  addi r8, r8, 1;
lbl_8015bc70:
  clrlwi r0, r8, 0x10;
  cmpw r0, r5;
  blt lbl_8015bc48;
  blr;
  // clang-format on
}

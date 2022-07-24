#include "sdp_server.h"

#include <string.h>

#include "gki_buffer.h"
#include "bte_logmsg.h"
#include "sdp_db.h"
#include "sdp_utils.h"

// Extern function references.
// PAL: 0x80131d0c
extern UNKNOWN_FUNCTION(btu_start_timer);
// PAL: 0x8014a920
extern UNKNOWN_FUNCTION(L2CA_DataWrite);

// Symbol: sdp_server_handle_client_req
// PAL: 0x80159f30..0x8015a084
MARK_BINARY_BLOB(sdp_server_handle_client_req, 0x80159f30, 0x8015a084);
asm UNKNOWN_FUNCTION(sdp_server_handle_client_req) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  stw r28, 0x10(r1);
  mr r28, r3;
  addi r3, r3, 8;
  lhz r5, 4(r4);
  lhz r0, 2(r4);
  add r5, r4, r5;
  li r4, 5;
  addi r31, r5, 8;
  li r5, 0x1e;
  add r30, r31, r0;
  bl btu_start_timer;
  lbz r3, 3(r31);
  lbz r0, 4(r31);
  slwi r3, r3, 8;
  lbz r6, 1(r31);
  add r0, r3, r0;
  lbz r29, 0(r31);
  lbz r4, 2(r31);
  clrlwi r5, r0, 0x10;
  addi r31, r31, 1;
  slwi r6, r6, 8;
  add r3, r31, r5;
  addi r0, r3, 4;
  add r3, r6, r4;
  cmplw r0, r30;
  clrlwi r4, r3, 0x10;
  ble lbl_80159fc8;
  mr r3, r28;
  li r5, 4;
  li r6, 0;
  bl sdpu_build_n_send_error;
  b lbl_8015a064;
lbl_80159fc8:
  cmpwi r29, 4;
  beq lbl_8015a000;
  bge lbl_80159fe0;
  cmpwi r29, 2;
  beq lbl_80159fec;
  b lbl_8015a028;
lbl_80159fe0:
  cmpwi r29, 6;
  beq lbl_8015a014;
  b lbl_8015a028;
lbl_80159fec:
  mr r3, r28;
  mr r7, r30;
  addi r6, r31, 4;
  bl process_service_search;
  b lbl_8015a064;
lbl_8015a000:
  mr r3, r28;
  mr r7, r30;
  addi r6, r31, 4;
  bl process_service_attr_req;
  b lbl_8015a064;
lbl_8015a014:
  mr r3, r28;
  mr r7, r30;
  addi r6, r31, 4;
  bl process_service_search_attr_req;
  b lbl_8015a064;
lbl_8015a028:
  mr r3, r28;
  li r5, 3;
  li r6, 0;
  bl sdpu_build_n_send_error;
  lis r3, 0x8034;
  addi r3, r3, -24768;
  lbz r0, 0x4630(r3);
  cmplwi r0, 2;
  blt lbl_8015a064;
  lis r3, 0xa;
  lis r4, 0x8028;
  mr r5, r29;
  addi r3, r3, 1;
  addi r4, r4, 0x7d68;
  bl LogMsg_1;
lbl_8015a064:
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

// Symbol: process_service_search
// PAL: 0x8015a084..0x8015a494
MARK_BINARY_BLOB(process_service_search, 0x8015a084, 0x8015a494);
asm UNKNOWN_FUNCTION(process_service_search) {
  // clang-format off
  nofralloc;
  stwu r1, -0x1d0(r1);
  mflr r0;
  stw r0, 0x1d4(r1);
  addi r11, r1, 0x1d0;
  bl _savegpr_14;
  li r0, 0;
  mr r30, r3;
  stb r0, 0x17c(r1);
  mr r17, r4;
  mr r4, r5;
  mr r3, r6;
  addi r5, r1, 0x58;
  li r19, 0;
  bl sdpu_extract_uid_seq;
  cmpwi r3, 0;
  mr r15, r3;
  beq lbl_8015a0d4;
  lhz r0, 0x58(r1);
  cmpwi r0, 0;
  bne lbl_8015a0ec;
lbl_8015a0d4:
  mr r3, r30;
  mr r4, r17;
  li r5, 3;
  li r6, 0;
  bl sdpu_build_n_send_error;
  b lbl_8015a47c;
lbl_8015a0ec:
  lbz r4, 0(r3);
  lbz r0, 1(r3);
  slwi r3, r4, 8;
  add r0, r3, r0;
  clrlwi r18, r0, 0x10;
  cmplwi r18, 0x14;
  ble lbl_8015a10c;
  li r18, 0x14;
lbl_8015a10c:
  addi r14, r1, 8;
  li r16, 0;
  b lbl_8015a140;
lbl_8015a118:
  mr r3, r19;
  addi r4, r1, 0x58;
  bl sdp_db_service_search;
  cmpwi r3, 0;
  mr r19, r3;
  beq lbl_8015a14c;
  lwz r3, 0(r3);
  rlwinm r0, r16, 2, 0xe, 0x1d;
  addi r16, r16, 1;
  stwx r3, r14, r0;
lbl_8015a140:
  clrlwi r0, r16, 0x10;
  cmplw r0, r18;
  blt lbl_8015a118;
lbl_8015a14c:
  lbz r0, 2(r15);
  cmpwi r0, 0;
  beq lbl_8015a1c0;
  cmplwi r0, 2;
  addi r3, r15, 3;
  beq lbl_8015a17c;
  mr r3, r30;
  mr r4, r17;
  li r5, 5;
  li r6, 0;
  bl sdpu_build_n_send_error;
  b lbl_8015a47c;
lbl_8015a17c:
  lbz r0, 0(r3);
  lbz r3, 1(r3);
  slwi r4, r0, 8;
  lhz r0, 0x476(r30);
  add r3, r4, r3;
  clrlwi r31, r3, 0x10;
  cmplw r31, r0;
  beq lbl_8015a1b4;
  mr r3, r30;
  mr r4, r17;
  li r5, 5;
  li r6, 0;
  bl sdpu_build_n_send_error;
  b lbl_8015a47c;
lbl_8015a1b4:
  subf r0, r31, r16;
  clrlwi r4, r0, 0x10;
  b lbl_8015a1c8;
lbl_8015a1c0:
  mr r4, r16;
  li r31, 0;
lbl_8015a1c8:
  lhz r3, 0x20(r30);
  clrlwi r0, r4, 0x10;
  addi r3, r3, -12;
  srawi r3, r3, 2;
  addze r3, r3;
  clrlwi r15, r3, 0x10;
  cmplw r0, r15;
  bgt lbl_8015a1f0;
  mr r15, r4;
  b lbl_8015a204;
lbl_8015a1f0:
  lhz r3, 0x476(r30);
  li r0, 1;
  stb r0, 0x17c(r1);
  add r0, r3, r15;
  sth r0, 0x476(r30);
lbl_8015a204:
  li r3, 2;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  bne lbl_8015a23c;
  lis r3, 0x8034;
  addi r3, r3, -24768;
  lbz r0, 0x4630(r3);
  cmplwi r0, 1;
  blt lbl_8015a47c;
  lis r4, 0x8028;
  lis r3, 0xa;
  addi r4, r4, 0x7d8c;
  bl LogMsg_0;
  b lbl_8015a47c;
lbl_8015a23c:
  li r0, 9;
  addi r14, r3, 0x11;
  sth r0, 4(r3);
  li r4, 3;
  clrlwi r0, r15, 0x10;
  addi r11, r14, 3;
  stb r4, 0x11(r3);
  add r10, r31, r0;
  srawi r5, r17, 8;
  rlwinm r4, r16, 0x18, 0x18, 0x1f;
  stb r5, 0x12(r3);
  rlwinm r0, r15, 0x18, 0x18, 0x1f;
  cmpw r31, r10;
  stb r17, 0x13(r3);
  stb r4, 0x16(r3);
  stb r16, 0x17(r3);
  stb r0, 0x18(r3);
  stw r11, 0x180(r1);
  addi r11, r11, 6;
  stb r15, 0x19(r3);
  bge lbl_8015a410;
  clrlwi r5, r10, 0x10;
  addi r0, r10, -8;
  subf r4, r31, r5;
  clrlwi r4, r4, 0x10;
  cmplwi r4, 8;
  ble lbl_8015a3d0;
  cmplw r31, r5;
  bgt lbl_8015a3d0;
  b lbl_8015a3c4;
lbl_8015a2b4:
  rlwinm r4, r31, 2, 0xe, 0x1d;
  addi r17, r1, 8;
  lwzux r8, r17, r4;
  addi r31, r31, 8;
  srwi r5, r8, 0x18;
  lwz r24, 4(r17);
  stb r5, 0(r11);
  rlwinm r6, r8, 0x10, 0x18, 0x1f;
  lwz r4, 8(r17);
  rlwinm r7, r8, 0x18, 0x18, 0x1f;
  stb r6, 1(r11);
  srwi r9, r24, 0x18;
  lwz r6, 0x10(r17);
  rlwinm r18, r24, 0x10, 0x18, 0x1f;
  stb r7, 2(r11);
  rlwinm r21, r24, 0x18, 0x18, 0x1f;
  lwz r7, 0x14(r17);
  srwi r27, r4, 0x18;
  stb r8, 3(r11);
  rlwinm r12, r4, 0x10, 0x18, 0x1f;
  lwz r8, 0x18(r17);
  rlwinm r15, r4, 0x18, 0x18, 0x1f;
  stb r9, 4(r11);
  srwi r19, r6, 0x18;
  lwz r9, 0x1c(r17);
  rlwinm r20, r6, 0x10, 0x18, 0x1f;
  stb r18, 5(r11);
  srwi r22, r7, 0x18;
  lwz r5, 0xc(r17);
  rlwinm r23, r7, 0x10, 0x18, 0x1f;
  stb r21, 6(r11);
  rlwinm r21, r6, 0x18, 0x18, 0x1f;
  srwi r16, r5, 0x18;
  rlwinm r17, r5, 0x10, 0x18, 0x1f;
  stb r24, 7(r11);
  rlwinm r18, r5, 0x18, 0x18, 0x1f;
  rlwinm r24, r7, 0x18, 0x18, 0x1f;
  srwi r25, r8, 0x18;
  stb r27, 8(r11);
  rlwinm r26, r8, 0x10, 0x18, 0x1f;
  rlwinm r27, r8, 0x18, 0x18, 0x1f;
  srwi r28, r9, 0x18;
  stb r12, 9(r11);
  rlwinm r29, r9, 0x10, 0x18, 0x1f;
  rlwinm r12, r9, 0x18, 0x18, 0x1f;
  stb r15, 0xa(r11);
  stb r4, 0xb(r11);
  stb r16, 0xc(r11);
  stb r17, 0xd(r11);
  stb r18, 0xe(r11);
  stb r5, 0xf(r11);
  stb r19, 0x10(r11);
  stb r20, 0x11(r11);
  stb r21, 0x12(r11);
  stb r6, 0x13(r11);
  stb r22, 0x14(r11);
  stb r23, 0x15(r11);
  stb r24, 0x16(r11);
  stb r7, 0x17(r11);
  stb r25, 0x18(r11);
  stb r26, 0x19(r11);
  stb r27, 0x1a(r11);
  stb r8, 0x1b(r11);
  stb r28, 0x1c(r11);
  stb r29, 0x1d(r11);
  stb r12, 0x1e(r11);
  stb r9, 0x1f(r11);
  addi r11, r11, 0x20;
lbl_8015a3c4:
  clrlwi r4, r31, 0x10;
  cmpw r4, r0;
  blt lbl_8015a2b4;
lbl_8015a3d0:
  addi r5, r1, 8;
  b lbl_8015a404;
lbl_8015a3d8:
  rlwinm r0, r31, 2, 0xe, 0x1d;
  addi r31, r31, 1;
  lwzx r6, r5, r0;
  srwi r0, r6, 0x18;
  rlwinm r4, r6, 0x10, 0x18, 0x1f;
  stb r0, 0(r11);
  rlwinm r0, r6, 0x18, 0x18, 0x1f;
  stb r4, 1(r11);
  stb r0, 2(r11);
  stb r6, 3(r11);
  addi r11, r11, 4;
lbl_8015a404:
  clrlwi r0, r31, 0x10;
  cmpw r0, r10;
  blt lbl_8015a3d8;
lbl_8015a410:
  lbz r0, 0x17c(r1);
  cmpwi r0, 0;
  beq lbl_8015a440;
  li r0, 2;
  stb r0, 0(r11);
  lhz r0, 0x476(r30);
  srawi r0, r0, 8;
  stb r0, 1(r11);
  lhz r0, 0x476(r30);
  stb r0, 2(r11);
  addi r11, r11, 3;
  b lbl_8015a44c;
lbl_8015a440:
  li r0, 0;
  stb r0, 0(r11);
  addi r11, r11, 1;
lbl_8015a44c:
  lwz r0, 0x180(r1);
  lwz r5, 0x180(r1);
  subf r4, r0, r11;
  subf r0, r14, r11;
  addi r7, r4, -2;
  rlwinm r6, r7, 0x18, 0x18, 0x1f;
  mr r4, r3;
  stb r6, 0(r5);
  stb r7, 1(r5);
  sth r0, 2(r3);
  lhz r3, 0x22(r30);
  bl L2CA_DataWrite;
lbl_8015a47c:
  addi r11, r1, 0x1d0;
  bl _restgpr_14;
  lwz r0, 0x1d4(r1);
  mtlr r0;
  addi r1, r1, 0x1d0;
  blr;
  // clang-format on
}

// Symbol: process_service_attr_req
// PAL: 0x8015a494..0x8015a824
MARK_BINARY_BLOB(process_service_attr_req, 0x8015a494, 0x8015a824);
asm UNKNOWN_FUNCTION(process_service_attr_req) {
  // clang-format off
  nofralloc;
  stwu r1, -0x70(r1);
  mflr r0;
  stw r0, 0x74(r1);
  addi r11, r1, 0x70;
  bl _savegpr_24;
  lbz r9, 0(r6);
  addi r0, r6, 4;
  lbz r8, 1(r6);
  cmplw r0, r7;
  lbz r0, 2(r6);
  slwi r10, r9, 0x18;
  slwi r8, r8, 0x10;
  lbz r9, 3(r6);
  slwi r0, r0, 8;
  mr r25, r3;
  add r8, r10, r8;
  mr r26, r4;
  add r0, r9, r0;
  mr r24, r7;
  add r27, r8, r0;
  ble lbl_8015a4f8;
  li r5, 2;
  li r6, 0;
  bl sdpu_build_n_send_error;
  b lbl_8015a80c;
lbl_8015a4f8:
  lbz r4, 4(r6);
  lbz r0, 5(r6);
  slwi r4, r4, 8;
  lhz r3, 0x20(r3);
  add r0, r4, r0;
  clrlwi r30, r0, 0x10;
  addi r0, r3, -10;
  cmpw r30, r0;
  ble lbl_8015a520;
  clrlwi r30, r0, 0x10;
lbl_8015a520:
  mr r4, r5;
  addi r3, r6, 6;
  addi r5, r1, 8;
  bl sdpu_extract_attr_seq;
  cmpwi r3, 0;
  mr r28, r3;
  beq lbl_8015a550;
  lhz r0, 8(r1);
  cmpwi r0, 0;
  beq lbl_8015a550;
  cmplw r3, r24;
  ble lbl_8015a568;
lbl_8015a550:
  mr r3, r25;
  mr r4, r26;
  li r5, 3;
  li r6, 0;
  bl sdpu_build_n_send_error;
  b lbl_8015a80c;
lbl_8015a568:
  mr r3, r27;
  bl sdp_db_find_record;
  cmpwi r3, 0;
  mr r27, r3;
  bne lbl_8015a594;
  mr r3, r25;
  mr r4, r26;
  li r5, 2;
  li r6, 0;
  bl sdpu_build_n_send_error;
  b lbl_8015a80c;
lbl_8015a594:
  lbz r0, 0(r28);
  cmpwi r0, 0;
  beq lbl_8015a5f8;
  cmplwi r0, 2;
  beq lbl_8015a5c0;
  mr r3, r25;
  mr r4, r26;
  li r5, 5;
  li r6, 0;
  bl sdpu_build_n_send_error;
  b lbl_8015a80c;
lbl_8015a5c0:
  lbz r0, 1(r28);
  lbz r3, 2(r28);
  slwi r4, r0, 8;
  lhz r0, 0x476(r25);
  add r3, r4, r3;
  clrlwi r3, r3, 0x10;
  cmplw r3, r0;
  beq lbl_8015a6f0;
  mr r3, r25;
  mr r4, r26;
  li r5, 5;
  li r6, 0;
  bl sdpu_build_n_send_error;
  b lbl_8015a80c;
lbl_8015a5f8:
  li r0, 0;
  addi r29, r25, 0x29;
  sth r0, 0x476(r25);
  li r28, 0;
  b lbl_8015a68c;
lbl_8015a60c:
  rlwinm r0, r28, 2, 0xe, 0x1d;
  addi r31, r1, 8;
  add r31, r31, r0;
  mr r3, r27;
  lhz r4, 2(r31);
  lhz r5, 4(r31);
  bl sdp_db_find_attr_in_rec;
  cmpwi r3, 0;
  mr r24, r3;
  beq lbl_8015a688;
  addi r0, r25, 0x26;
  lwz r4, 0(r3);
  subf r0, r0, r29;
  clrlwi r0, r0, 0x10;
  subfic r0, r0, 0x3e8;
  clrlwi r3, r0, 0x10;
  addi r0, r3, -6;
  cmplw r4, r0;
  bgt lbl_8015a69c;
  mr r3, r29;
  mr r4, r24;
  bl sdpu_build_attrib_entry;
  lhz r4, 2(r31);
  mr r29, r3;
  lhz r0, 4(r31);
  cmplw r4, r0;
  beq lbl_8015a688;
  lhz r3, 8(r24);
  addi r28, r28, -1;
  addi r0, r3, 1;
  sth r0, 2(r31);
lbl_8015a688:
  addi r28, r28, 1;
lbl_8015a68c:
  lhz r0, 8(r1);
  clrlwi r3, r28, 0x10;
  cmplw r3, r0;
  blt lbl_8015a60c;
lbl_8015a69c:
  addi r0, r25, 0x26;
  subf r0, r0, r29;
  clrlwi r4, r0, 0x10;
  sth r0, 0x24(r25);
  cmplwi r4, 0xff;
  ble lbl_8015a6d0;
  addi r3, r4, -3;
  li r4, 0x36;
  srawi r0, r3, 8;
  stb r4, 0x26(r25);
  stb r0, 0x27(r25);
  stb r3, 0x28(r25);
  b lbl_8015a6f0;
lbl_8015a6d0:
  addi r3, r4, -3;
  addi r0, r4, -1;
  li r5, 1;
  li r4, 0x35;
  sth r5, 0x476(r25);
  stb r4, 0x27(r25);
  stb r3, 0x28(r25);
  sth r0, 0x24(r25);
lbl_8015a6f0:
  li r3, 2;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  mr r27, r3;
  bne lbl_8015a72c;
  lis r3, 0x8034;
  addi r3, r3, -24768;
  lbz r0, 0x4630(r3);
  cmplwi r0, 1;
  blt lbl_8015a80c;
  lis r4, 0x8028;
  lis r3, 0xa;
  addi r4, r4, 0x7d8c;
  bl LogMsg_0;
  b lbl_8015a80c;
lbl_8015a72c:
  li r0, 9;
  addi r29, r3, 0x11;
  sth r0, 4(r3);
  li r3, 5;
  addi r31, r29, 3;
  rlwinm r0, r26, 0x18, 0x18, 0x1f;
  stb r3, 0(r29);
  mr r28, r31;
  stb r0, 1(r29);
  stb r26, 2(r29);
  lhz r0, 0x24(r25);
  cmplw r0, r30;
  bgt lbl_8015a764;
  mr r30, r0;
lbl_8015a764:
  rlwinm r0, r30, 0x18, 0x18, 0x1f;
  clrlwi r5, r30, 0x10;
  stb r0, 2(r31);
  stb r30, 3(r31);
  addi r31, r31, 4;
  mr r3, r31;
  lhz r0, 0x476(r25);
  add r4, r25, r0;
  addi r4, r4, 0x26;
  bl memcpy;
  lhz r0, 0x24(r25);
  clrlwi r3, r30, 0x10;
  add r31, r31, r3;
  lhz r4, 0x476(r25);
  subf r3, r30, r0;
  clrlwi. r0, r3, 0x10;
  sth r3, 0x24(r25);
  add r0, r4, r30;
  sth r0, 0x476(r25);
  beq lbl_8015a7d8;
  li r0, 2;
  stb r0, 0(r31);
  lhz r0, 0x476(r25);
  srawi r0, r0, 8;
  stb r0, 1(r31);
  lhz r0, 0x476(r25);
  stb r0, 2(r31);
  addi r31, r31, 3;
  b lbl_8015a7e4;
lbl_8015a7d8:
  li r0, 0;
  stb r0, 0(r31);
  addi r31, r31, 1;
lbl_8015a7e4:
  subf r3, r28, r31;
  subf r0, r29, r31;
  addi r5, r3, -2;
  mr r4, r27;
  rlwinm r3, r5, 0x18, 0x18, 0x1f;
  stb r3, 0(r28);
  stb r5, 1(r28);
  sth r0, 2(r27);
  lhz r3, 0x22(r25);
  bl L2CA_DataWrite;
lbl_8015a80c:
  addi r11, r1, 0x70;
  bl _restgpr_24;
  lwz r0, 0x74(r1);
  mtlr r0;
  addi r1, r1, 0x70;
  blr;
  // clang-format on
}

// Symbol: process_service_search_attr_req
// PAL: 0x8015a824..0x8015ac40
MARK_BINARY_BLOB(process_service_search_attr_req, 0x8015a824, 0x8015ac40);
asm UNKNOWN_FUNCTION(process_service_search_attr_req) {
  // clang-format off
  nofralloc;
  stwu r1, -0x1f0(r1);
  mflr r0;
  stw r0, 0x1f4(r1);
  addi r11, r1, 0x1f0;
  bl _savegpr_20;
  mr r20, r5;
  mr r21, r3;
  mr r22, r4;
  mr r3, r6;
  mr r4, r20;
  addi r5, r1, 0x90;
  li r24, 0;
  bl sdpu_extract_uid_seq;
  cmpwi r3, 0;
  beq lbl_8015a86c;
  lhz r0, 0x90(r1);
  cmpwi r0, 0;
  bne lbl_8015a884;
lbl_8015a86c:
  mr r3, r21;
  mr r4, r22;
  li r5, 3;
  li r6, 0;
  bl sdpu_build_n_send_error;
  b lbl_8015ac28;
lbl_8015a884:
  lbz r4, 0(r3);
  lbz r0, 1(r3);
  slwi r5, r4, 8;
  lhz r4, 0x20(r21);
  add r0, r5, r0;
  clrlwi r29, r0, 0x10;
  addi r0, r4, -10;
  cmpw r29, r0;
  ble lbl_8015a8ac;
  clrlwi r29, r0, 0x10;
lbl_8015a8ac:
  mr r4, r20;
  addi r5, r1, 0x4c;
  addi r3, r3, 2;
  bl sdpu_extract_attr_seq;
  cmpwi r3, 0;
  beq lbl_8015a8d0;
  lhz r0, 0x4c(r1);
  cmpwi r0, 0;
  bne lbl_8015a8e8;
lbl_8015a8d0:
  mr r3, r21;
  mr r4, r22;
  li r5, 3;
  li r6, 0;
  bl sdpu_build_n_send_error;
  b lbl_8015ac28;
lbl_8015a8e8:
  li r0, 8;
  addi r6, r1, 4;
  addi r5, r1, 0x48;
  mtctr r0;
lbl_8015a8f8:
  lwz r4, 4(r5);
  lwzu r0, 8(r5);
  stw r4, 4(r6);
  stwu r0, 8(r6);
  bdnz lbl_8015a8f8;
  lhz r0, 4(r5);
  sth r0, 4(r6);
  lbz r0, 0(r3);
  cmpwi r0, 0;
  beq lbl_8015a978;
  cmplwi r0, 2;
  beq lbl_8015a940;
  mr r3, r21;
  mr r4, r22;
  li r5, 5;
  li r6, 0;
  bl sdpu_build_n_send_error;
  b lbl_8015ac28;
lbl_8015a940:
  lbz r0, 1(r3);
  lbz r3, 2(r3);
  slwi r4, r0, 8;
  lhz r0, 0x476(r21);
  add r3, r4, r3;
  clrlwi r3, r3, 0x10;
  cmplw r3, r0;
  beq lbl_8015ab0c;
  mr r3, r21;
  mr r4, r22;
  li r5, 5;
  li r6, 0;
  bl sdpu_build_n_send_error;
  b lbl_8015ac28;
lbl_8015a978:
  li r0, 0;
  addi r28, r21, 0x29;
  sth r0, 0x476(r21);
  addi r4, r1, 0x90;
  li r3, 0;
  bl sdp_db_service_search;
  mr r26, r3;
  li r31, 8;
  li r20, 0x36;
  b lbl_8015aab0;
lbl_8015a9a0:
  addi r5, r1, 0x48;
  addi r4, r1, 4;
  mtctr r31;
lbl_8015a9ac:
  lwz r3, 4(r4);
  lwzu r0, 8(r4);
  stw r3, 4(r5);
  stwu r0, 8(r5);
  bdnz lbl_8015a9ac;
  lhz r0, 4(r4);
  mr r23, r28;
  li r27, 0;
  addi r28, r28, 3;
  sth r0, 4(r5);
  b lbl_8015aa60;
lbl_8015a9d8:
  rlwinm r0, r27, 2, 0xe, 0x1d;
  addi r30, r1, 0x4c;
  add r30, r30, r0;
  mr r3, r26;
  lhz r4, 2(r30);
  lhz r5, 4(r30);
  bl sdp_db_find_attr_in_rec;
  cmpwi r3, 0;
  mr r25, r3;
  beq lbl_8015aa5c;
  addi r0, r21, 0x26;
  lwz r4, 0(r3);
  subf r0, r0, r28;
  clrlwi r0, r0, 0x10;
  subfic r0, r0, 0x3e8;
  clrlwi r3, r0, 0x10;
  addi r0, r3, -6;
  cmplw r4, r0;
  ble lbl_8015aa2c;
  li r24, 1;
  b lbl_8015aa70;
lbl_8015aa2c:
  mr r3, r28;
  mr r4, r25;
  bl sdpu_build_attrib_entry;
  lhz r4, 2(r30);
  mr r28, r3;
  lhz r0, 4(r30);
  cmplw r4, r0;
  beq lbl_8015aa5c;
  lhz r3, 8(r25);
  addi r27, r27, -1;
  addi r0, r3, 1;
  sth r0, 2(r30);
lbl_8015aa5c:
  addi r27, r27, 1;
lbl_8015aa60:
  lhz r0, 0x4c(r1);
  clrlwi r3, r27, 0x10;
  cmplw r3, r0;
  blt lbl_8015a9d8;
lbl_8015aa70:
  cmpwi r24, 0;
  bne lbl_8015aab8;
  subf r3, r23, r28;
  addi r0, r3, -3;
  clrlwi. r3, r0, 0x10;
  beq lbl_8015aa9c;
  stb r20, 0(r23);
  rlwinm r0, r3, 0x18, 0x18, 0x1f;
  stb r0, 1(r23);
  stb r3, 2(r23);
  b lbl_8015aaa0;
lbl_8015aa9c:
  mr r28, r23;
lbl_8015aaa0:
  mr r3, r26;
  addi r4, r1, 0x90;
  bl sdp_db_service_search;
  mr r26, r3;
lbl_8015aab0:
  cmpwi r26, 0;
  bne lbl_8015a9a0;
lbl_8015aab8:
  addi r0, r21, 0x26;
  subf r0, r0, r28;
  clrlwi r4, r0, 0x10;
  sth r0, 0x24(r21);
  cmplwi r4, 0xff;
  ble lbl_8015aaec;
  addi r3, r4, -3;
  li r4, 0x36;
  srawi r0, r3, 8;
  stb r4, 0x26(r21);
  stb r0, 0x27(r21);
  stb r3, 0x28(r21);
  b lbl_8015ab0c;
lbl_8015aaec:
  addi r3, r4, -3;
  addi r0, r4, -1;
  li r5, 1;
  li r4, 0x35;
  sth r5, 0x476(r21);
  stb r4, 0x27(r21);
  stb r3, 0x28(r21);
  sth r0, 0x24(r21);
lbl_8015ab0c:
  li r3, 2;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  mr r25, r3;
  bne lbl_8015ab48;
  lis r3, 0x8034;
  addi r3, r3, -24768;
  lbz r0, 0x4630(r3);
  cmplwi r0, 1;
  blt lbl_8015ac28;
  lis r4, 0x8028;
  lis r3, 0xa;
  addi r4, r4, 0x7d8c;
  bl LogMsg_0;
  b lbl_8015ac28;
lbl_8015ab48:
  li r0, 9;
  addi r28, r3, 0x11;
  sth r0, 4(r3);
  li r3, 7;
  addi r30, r28, 3;
  rlwinm r0, r22, 0x18, 0x18, 0x1f;
  stb r3, 0(r28);
  mr r31, r30;
  stb r0, 1(r28);
  stb r22, 2(r28);
  lhz r0, 0x24(r21);
  cmplw r0, r29;
  bgt lbl_8015ab80;
  mr r29, r0;
lbl_8015ab80:
  rlwinm r0, r29, 0x18, 0x18, 0x1f;
  clrlwi r5, r29, 0x10;
  stb r0, 2(r30);
  stb r29, 3(r30);
  addi r30, r30, 4;
  mr r3, r30;
  lhz r0, 0x476(r21);
  add r4, r21, r0;
  addi r4, r4, 0x26;
  bl memcpy;
  lhz r0, 0x24(r21);
  clrlwi r3, r29, 0x10;
  add r30, r30, r3;
  lhz r4, 0x476(r21);
  subf r3, r29, r0;
  clrlwi. r0, r3, 0x10;
  sth r3, 0x24(r21);
  add r0, r4, r29;
  sth r0, 0x476(r21);
  beq lbl_8015abf4;
  li r0, 2;
  stb r0, 0(r30);
  lhz r0, 0x476(r21);
  srawi r0, r0, 8;
  stb r0, 1(r30);
  lhz r0, 0x476(r21);
  stb r0, 2(r30);
  addi r30, r30, 3;
  b lbl_8015ac00;
lbl_8015abf4:
  li r0, 0;
  stb r0, 0(r30);
  addi r30, r30, 1;
lbl_8015ac00:
  subf r3, r31, r30;
  subf r0, r28, r30;
  addi r5, r3, -2;
  mr r4, r25;
  rlwinm r3, r5, 0x18, 0x18, 0x1f;
  stb r3, 0(r31);
  stb r5, 1(r31);
  sth r0, 2(r25);
  lhz r3, 0x22(r21);
  bl L2CA_DataWrite;
lbl_8015ac28:
  addi r11, r1, 0x1f0;
  bl _restgpr_20;
  lwz r0, 0x1f4(r1);
  mtlr r0;
  addi r1, r1, 0x1f0;
  blr;
  // clang-format on
}

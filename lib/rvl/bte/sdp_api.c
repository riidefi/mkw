#include "sdp_api.h"

#include <string.h>

#include "gki_buffer.h"
#include "bte_logmsg.h"
#include "sdp_db.h"
#include "sdp_main.h"
#include "sdp_utils.h"

// Symbol: SDP_InitDiscoveryDb
// PAL: 0x80156618..0x80156990
MARK_BINARY_BLOB(SDP_InitDiscoveryDb, 0x80156618, 0x80156990);
asm UNKNOWN_FUNCTION(SDP_InitDiscoveryDb) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_26;
  cmpwi r3, 0;
  mr r27, r3;
  mr r26, r4;
  mr r28, r5;
  mr r29, r6;
  mr r30, r7;
  mr r31, r8;
  beq lbl_80156664;
  cmplwi r4, 0x6c;
  blt lbl_80156664;
  cmplwi r7, 0xc;
  bgt lbl_80156664;
  cmplwi r5, 3;
  ble lbl_801566a0;
lbl_80156664:
  lis r3, 0x8034;
  addi r3, r3, -24768;
  lbz r0, 0x4630(r3);
  cmplwi r0, 1;
  blt lbl_80156698;
  lis r4, 0x8028;
  mr r5, r27;
  mr r6, r26;
  mr r7, r28;
  mr r8, r30;
  addi r4, r4, 0x77c0;
  lis r3, 0xa;
  bl LogMsg_4;
lbl_80156698:
  li r3, 0;
  b lbl_80156978;
lbl_801566a0:
  mr r5, r26;
  li r4, 0;
  bl memset;
  addi r5, r26, -108;
  addi r0, r27, 0x6c;
  li r3, 0;
  cmpwi r28, 0;
  stw r5, 0(r27);
  li r4, 0;
  stw r5, 4(r27);
  stw r3, 8(r27);
  stw r0, 0x68(r27);
  beq lbl_801568a8;
  cmplwi r28, 8;
  addis r3, r28, 1;
  addi r3, r3, -8;
  ble lbl_80156854;
  clrlwi r3, r3, 0x10;
  addi r0, r3, 7;
  srwi r0, r0, 3;
  mtctr r0;
  cmplwi r3, 0;
  ble lbl_80156854;
lbl_801566fc:
  clrlwi r0, r4, 0x10;
  lwz r5, 0(r29);
  mulli r3, r0, 0x14;
  lwz r0, 4(r29);
  addi r4, r4, 8;
  add r3, r27, r3;
  stw r5, 0x10(r3);
  stw r0, 0x14(r3);
  lwz r5, 8(r29);
  lwz r0, 0xc(r29);
  stw r5, 0x18(r3);
  stw r0, 0x1c(r3);
  lwz r0, 0x10(r29);
  stw r0, 0x20(r3);
  lwz r5, 0x14(r29);
  lwz r0, 0x18(r29);
  stw r5, 0x24(r3);
  stw r0, 0x28(r3);
  lwz r5, 0x1c(r29);
  lwz r0, 0x20(r29);
  stw r5, 0x2c(r3);
  stw r0, 0x30(r3);
  lwz r0, 0x24(r29);
  stw r0, 0x34(r3);
  lwz r5, 0x28(r29);
  lwz r0, 0x2c(r29);
  stw r5, 0x38(r3);
  stw r0, 0x3c(r3);
  lwz r5, 0x30(r29);
  lwz r0, 0x34(r29);
  stw r5, 0x40(r3);
  stw r0, 0x44(r3);
  lwz r0, 0x38(r29);
  stw r0, 0x48(r3);
  lwz r5, 0x3c(r29);
  lwz r0, 0x40(r29);
  stw r5, 0x4c(r3);
  stw r0, 0x50(r3);
  lwz r5, 0x44(r29);
  lwz r0, 0x48(r29);
  stw r5, 0x54(r3);
  stw r0, 0x58(r3);
  lwz r0, 0x4c(r29);
  stw r0, 0x5c(r3);
  lwz r5, 0x50(r29);
  lwz r0, 0x54(r29);
  stw r5, 0x60(r3);
  stw r0, 0x64(r3);
  lwz r5, 0x58(r29);
  lwz r0, 0x5c(r29);
  stw r5, 0x68(r3);
  stw r0, 0x6c(r3);
  lwz r0, 0x60(r29);
  stw r0, 0x70(r3);
  lwz r5, 0x64(r29);
  lwz r0, 0x68(r29);
  stw r5, 0x74(r3);
  stw r0, 0x78(r3);
  lwz r5, 0x6c(r29);
  lwz r0, 0x70(r29);
  stw r5, 0x7c(r3);
  stw r0, 0x80(r3);
  lwz r0, 0x74(r29);
  stw r0, 0x84(r3);
  lwz r5, 0x78(r29);
  lwz r0, 0x7c(r29);
  stw r5, 0x88(r3);
  stw r0, 0x8c(r3);
  lwz r5, 0x80(r29);
  lwz r0, 0x84(r29);
  stw r5, 0x90(r3);
  stw r0, 0x94(r3);
  lwz r0, 0x88(r29);
  stw r0, 0x98(r3);
  lwz r5, 0x8c(r29);
  lwz r0, 0x90(r29);
  stw r5, 0x9c(r3);
  stw r0, 0xa0(r3);
  lwz r5, 0x94(r29);
  lwz r0, 0x98(r29);
  stw r5, 0xa4(r3);
  stw r0, 0xa8(r3);
  lwz r0, 0x9c(r29);
  addi r29, r29, 0xa0;
  stw r0, 0xac(r3);
  bdnz lbl_801566fc;
lbl_80156854:
  clrlwi r3, r4, 0x10;
  subf r0, r3, r28;
  mtctr r0;
  cmplw r3, r28;
  bge lbl_801568a8;
lbl_80156868:
  clrlwi r0, r4, 0x10;
  lwz r3, 0(r29);
  mulli r5, r0, 0x14;
  lwz r0, 4(r29);
  addi r4, r4, 1;
  add r5, r27, r5;
  stw r3, 0x10(r5);
  stw r0, 0x14(r5);
  lwz r3, 8(r29);
  lwz r0, 0xc(r29);
  stw r3, 0x18(r5);
  stw r0, 0x1c(r5);
  lwz r0, 0x10(r29);
  addi r29, r29, 0x14;
  stw r0, 0x20(r5);
  bdnz lbl_80156868;
lbl_801568a8:
  cmpwi r30, 0;
  sth r28, 0xc(r27);
  li r5, 0;
  beq lbl_80156964;
  cmplwi r30, 8;
  addis r3, r30, 1;
  addi r3, r3, -8;
  ble lbl_80156934;
  clrlwi r3, r3, 0x10;
  addi r0, r3, 7;
  srwi r0, r0, 3;
  mtctr r0;
  cmplwi r3, 0;
  ble lbl_80156934;
lbl_801568e0:
  rlwinm r3, r5, 1, 0xf, 0x1e;
  lhz r0, 0(r31);
  add r3, r27, r3;
  addi r5, r5, 8;
  sth r0, 0x4e(r3);
  lhz r0, 2(r31);
  sth r0, 0x50(r3);
  lhz r0, 4(r31);
  sth r0, 0x52(r3);
  lhz r0, 6(r31);
  sth r0, 0x54(r3);
  lhz r0, 8(r31);
  sth r0, 0x56(r3);
  lhz r0, 0xa(r31);
  sth r0, 0x58(r3);
  lhz r0, 0xc(r31);
  sth r0, 0x5a(r3);
  lhz r0, 0xe(r31);
  addi r31, r31, 0x10;
  sth r0, 0x5c(r3);
  bdnz lbl_801568e0;
lbl_80156934:
  clrlwi r3, r5, 0x10;
  subf r0, r3, r30;
  mtctr r0;
  cmplw r3, r30;
  bge lbl_80156964;
lbl_80156948:
  rlwinm r0, r5, 1, 0xf, 0x1e;
  lhz r4, 0(r31);
  add r3, r27, r0;
  addi r5, r5, 1;
  sth r4, 0x4e(r3);
  addi r31, r31, 2;
  bdnz lbl_80156948;
lbl_80156964:
  mr r3, r30;
  mr r4, r27;
  bl sdpu_sort_attr_list;
  sth r30, 0x4c(r27);
  li r3, 1;
lbl_80156978:
  addi r11, r1, 0x20;
  bl _restgpr_26;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: SDP_ServiceSearchRequest
// PAL: 0x80156990..0x801569ec
MARK_BINARY_BLOB(SDP_ServiceSearchRequest, 0x80156990, 0x801569ec);
asm UNKNOWN_FUNCTION(SDP_ServiceSearchRequest) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r5;
  stw r30, 8(r1);
  mr r30, r4;
  bl sdp_conn_originate;
  cmpwi r3, 0;
  bne lbl_801569c0;
  li r3, 0;
  b lbl_801569d4;
lbl_801569c0:
  li r0, 0;
  stb r0, 0x474(r3);
  stw r30, 0x410(r3);
  stw r31, 0x414(r3);
  li r3, 1;
lbl_801569d4:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: SDP_ServiceSearchAttributeRequest
// PAL: 0x801569ec..0x80156a50
MARK_BINARY_BLOB(SDP_ServiceSearchAttributeRequest, 0x801569ec, 0x80156a50);
asm UNKNOWN_FUNCTION(SDP_ServiceSearchAttributeRequest) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r5;
  stw r30, 8(r1);
  mr r30, r4;
  bl sdp_conn_originate;
  cmpwi r3, 0;
  bne lbl_80156a1c;
  li r3, 0;
  b lbl_80156a38;
lbl_80156a1c:
  li r4, 0;
  li r0, 1;
  stb r4, 0x474(r3);
  stw r30, 0x410(r3);
  stw r31, 0x414(r3);
  stb r0, 0x475(r3);
  li r3, 1;
lbl_80156a38:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: SDP_FindAttributeInRec
// PAL: 0x80156a50..0x80156a78
MARK_BINARY_BLOB(SDP_FindAttributeInRec, 0x80156a50, 0x80156a78);
asm UNKNOWN_FUNCTION(SDP_FindAttributeInRec) {
  // clang-format off
  nofralloc;
  lwz r3, 0(r3);
  b lbl_80156a68;
lbl_80156a58:
  lhz r0, 4(r3);
  cmplw r0, r4;
  beqlr;
  lwz r3, 0(r3);
lbl_80156a68:
  cmpwi r3, 0;
  bne lbl_80156a58;
  li r3, 0;
  blr;
  // clang-format on
}

// Symbol: SDP_FindServiceInDb
// PAL: 0x80156a78..0x80156b44
MARK_BINARY_BLOB(SDP_FindServiceInDb, 0x80156a78, 0x80156b44);
asm UNKNOWN_FUNCTION(SDP_FindServiceInDb) {
  // clang-format off
  nofralloc;
  cmpwi r5, 0;
  bne lbl_80156a88;
  lwz r3, 8(r3);
  b lbl_80156b34;
lbl_80156a88:
  lwz r3, 4(r5);
  b lbl_80156b34;
lbl_80156a90:
  lwz r6, 0(r3);
  b lbl_80156b28;
lbl_80156a98:
  lhz r5, 4(r6);
  cmplwi r5, 1;
  bne lbl_80156af4;
  lhz r0, 6(r6);
  srawi r0, r0, 0xc;
  cmpwi r0, 6;
  bne lbl_80156af4;
  lwz r6, 8(r6);
  b lbl_80156ae8;
lbl_80156abc:
  lhz r5, 6(r6);
  srawi r0, r5, 0xc;
  cmpwi r0, 3;
  bne lbl_80156ae4;
  clrlwi r0, r5, 0x14;
  cmpwi r0, 2;
  bne lbl_80156ae4;
  lhz r0, 8(r6);
  cmplw r0, r4;
  beqlr;
lbl_80156ae4:
  lwz r6, 0(r6);
lbl_80156ae8:
  cmpwi r6, 0;
  bne lbl_80156abc;
  b lbl_80156b30;
lbl_80156af4:
  cmplwi r5, 3;
  bne lbl_80156b24;
  lhz r5, 6(r6);
  srawi r0, r5, 0xc;
  cmpwi r0, 3;
  bne lbl_80156b24;
  clrlwi r0, r5, 0x14;
  cmpwi r0, 2;
  bne lbl_80156b24;
  lhz r0, 8(r6);
  cmplw r0, r4;
  beqlr;
lbl_80156b24:
  lwz r6, 0(r6);
lbl_80156b28:
  cmpwi r6, 0;
  bne lbl_80156a98;
lbl_80156b30:
  lwz r3, 4(r3);
lbl_80156b34:
  cmpwi r3, 0;
  bne lbl_80156a90;
  li r3, 0;
  blr;
  // clang-format on
}

// Symbol: SDP_FindServiceUUIDInDb
// PAL: 0x80156b44..0x80156c4c
MARK_BINARY_BLOB(SDP_FindServiceUUIDInDb, 0x80156b44, 0x80156c4c);
asm UNKNOWN_FUNCTION(SDP_FindServiceUUIDInDb) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  cmpwi r5, 0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  mr r29, r4;
  bne lbl_80156b70;
  lwz r31, 8(r3);
  b lbl_80156c24;
lbl_80156b70:
  lwz r31, 4(r5);
  b lbl_80156c24;
lbl_80156b78:
  lwz r30, 0(r31);
  b lbl_80156c18;
lbl_80156b80:
  lhz r3, 4(r30);
  cmplwi r3, 1;
  bne lbl_80156be0;
  lhz r0, 6(r30);
  srawi r0, r0, 0xc;
  cmpwi r0, 6;
  bne lbl_80156be0;
  lwz r30, 8(r30);
  b lbl_80156bd4;
lbl_80156ba4:
  lhz r0, 6(r30);
  srawi r0, r0, 0xc;
  cmpwi r0, 3;
  bne lbl_80156bd0;
  mr r3, r29;
  mr r4, r30;
  bl sdpu_compare_uuid_with_attr;
  clrlwi. r0, r3, 0x18;
  beq lbl_80156bd0;
  mr r3, r31;
  b lbl_80156c30;
lbl_80156bd0:
  lwz r30, 0(r30);
lbl_80156bd4:
  cmpwi r30, 0;
  bne lbl_80156ba4;
  b lbl_80156c20;
lbl_80156be0:
  cmplwi r3, 3;
  bne lbl_80156c14;
  lhz r0, 6(r30);
  srawi r0, r0, 0xc;
  cmpwi r0, 3;
  bne lbl_80156c14;
  mr r3, r29;
  mr r4, r30;
  bl sdpu_compare_uuid_with_attr;
  clrlwi. r0, r3, 0x18;
  beq lbl_80156c14;
  mr r3, r31;
  b lbl_80156c30;
lbl_80156c14:
  lwz r30, 0(r30);
lbl_80156c18:
  cmpwi r30, 0;
  bne lbl_80156b80;
lbl_80156c20:
  lwz r31, 4(r31);
lbl_80156c24:
  cmpwi r31, 0;
  bne lbl_80156b78;
  li r3, 0;
lbl_80156c30:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: SDP_SetLocalDiRecord
// PAL: 0x80156c4c..0x80156fac
MARK_BINARY_BLOB(SDP_SetLocalDiRecord, 0x80156c4c, 0x80156fac);
asm UNKNOWN_FUNCTION(SDP_SetLocalDiRecord) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  cmpwi r3, 0;
  stw r0, 0x24(r1);
  li r0, 0x1200;
  stw r31, 0x1c(r1);
  li r31, 0;
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  mr r29, r3;
  stw r28, 0x10(r1);
  mr r28, r4;
  sth r0, 0xc(r1);
  stw r31, 0(r4);
  bne lbl_80156c90;
  li r3, 0xb;
  b lbl_80156f8c;
lbl_80156c90:
  lbz r0, 8(r3);
  cmplwi r0, 1;
  bne lbl_80156cb4;
  lis r3, 0x8034;
  addi r3, r3, -24768;
  lwz r30, 0x121c(r3);
  cmpwi r30, 0;
  beq lbl_80156cb4;
  b lbl_80156ccc;
lbl_80156cb4:
  bl SDP_CreateRecord;
  cmpwi r3, 0;
  mr r30, r3;
  bne lbl_80156ccc;
  li r3, 6;
  b lbl_80156f8c;
lbl_80156ccc:
  stw r30, 0(r28);
  mr r3, r30;
  addi r5, r1, 0xc;
  li r4, 1;
  bl SDP_AddServiceClassIdList;
  clrlwi. r0, r3, 0x18;
  bne lbl_80156cec;
  li r31, 7;
lbl_80156cec:
  cmpwi r31, 0;
  bne lbl_80156d28;
  li r3, 0;
  li r0, 9;
  stb r3, 8(r1);
  addi r7, r1, 8;
  mr r3, r30;
  li r4, 0x200;
  stb r0, 9(r1);
  li r5, 1;
  li r6, 2;
  bl SDP_AddAttribute;
  clrlwi. r0, r3, 0x18;
  bne lbl_80156d28;
  li r31, 7;
lbl_80156d28:
  cmpwi r31, 0;
  bne lbl_80156d80;
  lbz r0, 9(r29);
  extsb. r0, r0;
  beq lbl_80156d80;
  addi r3, r29, 9;
  bl strlen;
  addi r0, r3, 1;
  cmplwi r0, 0x50;
  bgt lbl_80156d7c;
  addi r3, r29, 9;
  bl strlen;
  mr r4, r3;
  mr r3, r30;
  addi r6, r4, 1;
  addi r7, r29, 9;
  li r4, 0xb;
  li r5, 8;
  bl SDP_AddAttribute;
  clrlwi. r0, r3, 0x18;
  bne lbl_80156d80;
lbl_80156d7c:
  li r31, 7;
lbl_80156d80:
  cmpwi r31, 0;
  bne lbl_80156dd8;
  lbz r0, 0x59(r29);
  extsb. r0, r0;
  beq lbl_80156dd8;
  addi r3, r29, 0x59;
  bl strlen;
  addi r0, r3, 1;
  cmplwi r0, 0x50;
  bgt lbl_80156dd4;
  addi r3, r29, 0x59;
  bl strlen;
  mr r4, r3;
  mr r3, r30;
  addi r6, r4, 1;
  addi r7, r29, 0x59;
  li r4, 0x101;
  li r5, 4;
  bl SDP_AddAttribute;
  clrlwi. r0, r3, 0x18;
  bne lbl_80156dd8;
lbl_80156dd4:
  li r31, 7;
lbl_80156dd8:
  cmpwi r31, 0;
  bne lbl_80156e30;
  lbz r0, 0xa9(r29);
  extsb. r0, r0;
  beq lbl_80156e30;
  addi r3, r29, 0xa9;
  bl strlen;
  addi r0, r3, 1;
  cmplwi r0, 0x50;
  bgt lbl_80156e2c;
  addi r3, r29, 0xa9;
  bl strlen;
  mr r4, r3;
  mr r3, r30;
  addi r6, r4, 1;
  addi r7, r29, 0xa9;
  li r4, 0xa;
  li r5, 8;
  bl SDP_AddAttribute;
  clrlwi. r0, r3, 0x18;
  bne lbl_80156e30;
lbl_80156e2c:
  li r31, 7;
lbl_80156e30:
  cmpwi r31, 0;
  bne lbl_80156e70;
  lhz r0, 0(r29);
  addi r7, r1, 8;
  mr r3, r30;
  li r4, 0x201;
  srawi r0, r0, 8;
  li r5, 1;
  stb r0, 8(r1);
  li r6, 2;
  lhz r0, 0(r29);
  stb r0, 9(r1);
  bl SDP_AddAttribute;
  clrlwi. r0, r3, 0x18;
  bne lbl_80156e70;
  li r31, 7;
lbl_80156e70:
  cmpwi r31, 0;
  bne lbl_80156eb0;
  lhz r0, 4(r29);
  addi r7, r1, 8;
  mr r3, r30;
  li r4, 0x202;
  srawi r0, r0, 8;
  li r5, 1;
  stb r0, 8(r1);
  li r6, 2;
  lhz r0, 4(r29);
  stb r0, 9(r1);
  bl SDP_AddAttribute;
  clrlwi. r0, r3, 0x18;
  bne lbl_80156eb0;
  li r31, 7;
lbl_80156eb0:
  cmpwi r31, 0;
  bne lbl_80156ef0;
  lhz r0, 6(r29);
  addi r7, r1, 8;
  mr r3, r30;
  li r4, 0x203;
  srawi r0, r0, 8;
  li r5, 1;
  stb r0, 8(r1);
  li r6, 2;
  lhz r0, 6(r29);
  stb r0, 9(r1);
  bl SDP_AddAttribute;
  clrlwi. r0, r3, 0x18;
  bne lbl_80156ef0;
  li r31, 7;
lbl_80156ef0:
  cmpwi r31, 0;
  bne lbl_80156f1c;
  mr r3, r30;
  addi r7, r29, 8;
  li r4, 0x204;
  li r5, 5;
  li r6, 1;
  bl SDP_AddAttribute;
  clrlwi. r0, r3, 0x18;
  bne lbl_80156f1c;
  li r31, 7;
lbl_80156f1c:
  cmpwi r31, 0;
  bne lbl_80156f5c;
  lhz r0, 2(r29);
  addi r7, r1, 8;
  mr r3, r30;
  li r4, 0x205;
  srawi r0, r0, 8;
  li r5, 1;
  stb r0, 8(r1);
  li r6, 2;
  lhz r0, 2(r29);
  stb r0, 9(r1);
  bl SDP_AddAttribute;
  clrlwi. r0, r3, 0x18;
  bne lbl_80156f5c;
  li r31, 7;
lbl_80156f5c:
  cmpwi r31, 0;
  beq lbl_80156f70;
  mr r3, r30;
  bl SDP_DeleteRecord;
  b lbl_80156f88;
lbl_80156f70:
  lbz r0, 8(r29);
  cmplwi r0, 1;
  bne lbl_80156f88;
  lis r3, 0x8034;
  addi r3, r3, -24768;
  stw r30, 0x121c(r3);
lbl_80156f88:
  mr r3, r31;
lbl_80156f8c:
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

// Symbol: SDP_GetLocalDiRecord
// PAL: 0x80156fac..0x8015745c
MARK_BINARY_BLOB(SDP_GetLocalDiRecord, 0x80156fac, 0x8015745c);
asm UNKNOWN_FUNCTION(SDP_GetLocalDiRecord) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  li r31, 9;
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  mr r29, r3;
  stw r28, 0x10(r1);
  mr r28, r4;
  lwz r0, 0(r4);
  cmpwi r0, 0;
  bne lbl_80156ff0;
  lis r3, 0x8034;
  addi r3, r3, -24768;
  lwz r0, 0x121c(r3);
  stw r0, 0(r4);
lbl_80156ff0:
  lwz r3, 0(r4);
  bl sdp_db_find_record;
  cmpwi r3, 0;
  mr r30, r3;
  beq lbl_80157430;
  mr r3, r29;
  li r4, 0;
  li r5, 0xfa;
  bl memset;
  mr r3, r30;
  li r31, 0;
  li r4, 0x200;
  li r5, 0x200;
  bl sdp_db_find_attr_in_rec;
  cmpwi r3, 0;
  beq lbl_80157048;
  lwz r4, 4(r3);
  lbz r3, 0(r4);
  lbz r0, 1(r4);
  slwi r3, r3, 8;
  add r0, r3, r0;
  sth r0, 0(r29);
lbl_80157048:
  mr r3, r30;
  li r4, 0x201;
  li r5, 0x201;
  bl sdp_db_find_attr_in_rec;
  cmpwi r3, 0;
  beq lbl_80157078;
  lwz r4, 4(r3);
  lbz r3, 0(r4);
  lbz r0, 1(r4);
  slwi r3, r3, 8;
  add r0, r3, r0;
  sth r0, 2(r29);
lbl_80157078:
  mr r3, r30;
  li r4, 0x202;
  li r5, 0x202;
  bl sdp_db_find_attr_in_rec;
  cmpwi r3, 0;
  beq lbl_801570a8;
  lwz r4, 4(r3);
  lbz r3, 0(r4);
  lbz r0, 1(r4);
  slwi r3, r3, 8;
  add r0, r3, r0;
  sth r0, 6(r29);
lbl_801570a8:
  mr r3, r30;
  li r4, 0x203;
  li r5, 0x203;
  bl sdp_db_find_attr_in_rec;
  cmpwi r3, 0;
  beq lbl_801570d8;
  lwz r4, 4(r3);
  lbz r3, 0(r4);
  lbz r0, 1(r4);
  slwi r3, r3, 8;
  add r0, r3, r0;
  sth r0, 8(r29);
lbl_801570d8:
  mr r3, r30;
  li r4, 0x205;
  li r5, 0x205;
  bl sdp_db_find_attr_in_rec;
  cmpwi r3, 0;
  beq lbl_80157108;
  lwz r4, 4(r3);
  lbz r3, 0(r4);
  lbz r0, 1(r4);
  slwi r3, r3, 8;
  add r0, r3, r0;
  sth r0, 4(r29);
lbl_80157108:
  mr r3, r30;
  li r4, 0x204;
  li r5, 0x204;
  bl sdp_db_find_attr_in_rec;
  cmpwi r3, 0;
  beq lbl_8015712c;
  lwz r3, 4(r3);
  lbz r0, 0(r3);
  stb r0, 0xa(r29);
lbl_8015712c:
  mr r3, r30;
  li r4, 0xb;
  li r5, 0xb;
  bl sdp_db_find_attr_in_rec;
  cmpwi r3, 0;
  beq lbl_8015722c;
  lwz r0, 0(r3);
  li r4, 0x50;
  cmplwi r0, 0x50;
  bge lbl_80157158;
  mr r4, r0;
lbl_80157158:
  cmpwi cr1, r4, 0;
  lwz r7, 4(r3);
  li r8, 0;
  ble cr1, lbl_8015722c;
  cmpwi r4, 8;
  addi r5, r4, -8;
  ble lbl_80157200;
  li r6, 0;
  blt cr1, lbl_80157190;
  lis r3, 0x8000;
  addi r0, r3, -2;
  cmpw r4, r0;
  bgt lbl_80157190;
  li r6, 1;
lbl_80157190:
  cmpwi r6, 0;
  beq lbl_80157200;
  addi r0, r5, 7;
  addi r3, r29, 0xb;
  srwi r0, r0, 3;
  mtctr r0;
  cmpwi r5, 0;
  ble lbl_80157200;
lbl_801571b0:
  lbz r0, 0(r7);
  addi r8, r8, 8;
  stb r0, 0(r3);
  lbz r0, 1(r7);
  stb r0, 1(r3);
  lbz r0, 2(r7);
  stb r0, 2(r3);
  lbz r0, 3(r7);
  stb r0, 3(r3);
  lbz r0, 4(r7);
  stb r0, 4(r3);
  lbz r0, 5(r7);
  stb r0, 5(r3);
  lbz r0, 6(r7);
  stb r0, 6(r3);
  lbz r0, 7(r7);
  addi r7, r7, 8;
  stb r0, 7(r3);
  addi r3, r3, 8;
  bdnz lbl_801571b0;
lbl_80157200:
  add r3, r29, r8;
  subf r0, r8, r4;
  addi r3, r3, 0xb;
  mtctr r0;
  cmpw r8, r4;
  bge lbl_8015722c;
lbl_80157218:
  lbz r0, 0(r7);
  addi r7, r7, 1;
  stb r0, 0(r3);
  addi r3, r3, 1;
  bdnz lbl_80157218;
lbl_8015722c:
  mr r3, r30;
  li r4, 0x101;
  li r5, 0x101;
  bl sdp_db_find_attr_in_rec;
  cmpwi r3, 0;
  beq lbl_8015732c;
  lwz r0, 0(r3);
  li r4, 0x50;
  cmplwi r0, 0x50;
  bge lbl_80157258;
  mr r4, r0;
lbl_80157258:
  cmpwi cr1, r4, 0;
  lwz r7, 4(r3);
  li r8, 0;
  ble cr1, lbl_8015732c;
  cmpwi r4, 8;
  addi r5, r4, -8;
  ble lbl_80157300;
  li r6, 0;
  blt cr1, lbl_80157290;
  lis r3, 0x8000;
  addi r0, r3, -2;
  cmpw r4, r0;
  bgt lbl_80157290;
  li r6, 1;
lbl_80157290:
  cmpwi r6, 0;
  beq lbl_80157300;
  addi r0, r5, 7;
  addi r3, r29, 0x5b;
  srwi r0, r0, 3;
  mtctr r0;
  cmpwi r5, 0;
  ble lbl_80157300;
lbl_801572b0:
  lbz r0, 0(r7);
  addi r8, r8, 8;
  stb r0, 0(r3);
  lbz r0, 1(r7);
  stb r0, 1(r3);
  lbz r0, 2(r7);
  stb r0, 2(r3);
  lbz r0, 3(r7);
  stb r0, 3(r3);
  lbz r0, 4(r7);
  stb r0, 4(r3);
  lbz r0, 5(r7);
  stb r0, 5(r3);
  lbz r0, 6(r7);
  stb r0, 6(r3);
  lbz r0, 7(r7);
  addi r7, r7, 8;
  stb r0, 7(r3);
  addi r3, r3, 8;
  bdnz lbl_801572b0;
lbl_80157300:
  add r3, r29, r8;
  subf r0, r8, r4;
  addi r3, r3, 0x5b;
  mtctr r0;
  cmpw r8, r4;
  bge lbl_8015732c;
lbl_80157318:
  lbz r0, 0(r7);
  addi r7, r7, 1;
  stb r0, 0(r3);
  addi r3, r3, 1;
  bdnz lbl_80157318;
lbl_8015732c:
  mr r3, r30;
  li r4, 0xa;
  li r5, 0xa;
  bl sdp_db_find_attr_in_rec;
  cmpwi r3, 0;
  beq lbl_80157438;
  lwz r0, 0(r3);
  li r4, 0x50;
  cmplwi r0, 0x50;
  bge lbl_80157358;
  mr r4, r0;
lbl_80157358:
  cmpwi cr1, r4, 0;
  lwz r7, 4(r3);
  li r8, 0;
  ble cr1, lbl_80157438;
  cmpwi r4, 8;
  addi r5, r4, -8;
  ble lbl_80157400;
  li r6, 0;
  blt cr1, lbl_80157390;
  lis r3, 0x8000;
  addi r0, r3, -2;
  cmpw r4, r0;
  bgt lbl_80157390;
  li r6, 1;
lbl_80157390:
  cmpwi r6, 0;
  beq lbl_80157400;
  addi r0, r5, 7;
  addi r3, r29, 0xab;
  srwi r0, r0, 3;
  mtctr r0;
  cmpwi r5, 0;
  ble lbl_80157400;
lbl_801573b0:
  lbz r0, 0(r7);
  addi r8, r8, 8;
  stb r0, 0(r3);
  lbz r0, 1(r7);
  stb r0, 1(r3);
  lbz r0, 2(r7);
  stb r0, 2(r3);
  lbz r0, 3(r7);
  stb r0, 3(r3);
  lbz r0, 4(r7);
  stb r0, 4(r3);
  lbz r0, 5(r7);
  stb r0, 5(r3);
  lbz r0, 6(r7);
  stb r0, 6(r3);
  lbz r0, 7(r7);
  addi r7, r7, 8;
  stb r0, 7(r3);
  addi r3, r3, 8;
  bdnz lbl_801573b0;
lbl_80157400:
  add r3, r29, r8;
  subf r0, r8, r4;
  addi r3, r3, 0xab;
  mtctr r0;
  cmpw r8, r4;
  bge lbl_80157438;
lbl_80157418:
  lbz r0, 0(r7);
  addi r7, r7, 1;
  stb r0, 0(r3);
  addi r3, r3, 1;
  bdnz lbl_80157418;
  b lbl_80157438;
lbl_80157430:
  li r0, 0;
  stw r0, 0(r28);
lbl_80157438:
  mr r3, r31;
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  lwz r28, 0x10(r1);
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: SDP_SetTraceLevel
// PAL: 0x8015745c..0x80157480
MARK_BINARY_BLOB(SDP_SetTraceLevel, 0x8015745c, 0x80157480);
asm UNKNOWN_FUNCTION(SDP_SetTraceLevel) {
  // clang-format off
  nofralloc;
  cmplwi r3, 0xff;
  beq lbl_80157470;
  lis r4, 0x8034;
  addi r4, r4, -24768;
  stb r3, 0x4630(r4);
lbl_80157470:
  lis r3, 0x8034;
  addi r3, r3, -24768;
  lbz r3, 0x4630(r3);
  blr;
  // clang-format on
}

#include "sdp_db.h"

#include <string.h>

#include "bte_logmsg.h"
#include "sdp_utils.h"

// Symbol: sdp_db_service_search
// PAL: 0x80157480..0x801575bc
MARK_BINARY_BLOB(sdp_db_service_search, 0x80157480, 0x801575bc);
asm UNKNOWN_FUNCTION(sdp_db_service_search) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_24;
  lis r5, 0x8034;
  cmpwi r3, 0;
  addi r5, r5, -24768;
  mr r29, r4;
  lhz r0, 0x1222(r5);
  mulli r0, r0, 0x298;
  add r4, r5, r0;
  addi r30, r4, 0x1224;
  bne lbl_801574c0;
  addi r28, r5, 0x1224;
  b lbl_80157598;
lbl_801574c0:
  addi r28, r3, 0x298;
  b lbl_80157598;
lbl_801574c8:
  li r31, 0;
  b lbl_8015756c;
lbl_801574d0:
  clrlwi r0, r31, 0x10;
  addi r24, r28, 0xc;
  mulli r0, r0, 0x12;
  li r25, 0;
  add r27, r29, r0;
  addi r26, r27, 4;
  b lbl_80157548;
lbl_801574ec:
  lbz r0, 0xa(r24);
  cmplwi r0, 3;
  bne lbl_80157518;
  lwz r3, 4(r24);
  mr r5, r26;
  lwz r4, 0(r24);
  lhz r6, 2(r27);
  bl sdpu_compare_uuid_arrays;
  clrlwi. r0, r3, 0x18;
  bne lbl_80157558;
  b lbl_80157540;
lbl_80157518:
  cmplwi r0, 6;
  bne lbl_80157540;
  lwz r3, 4(r24);
  mr r5, r26;
  lwz r4, 0(r24);
  li r7, 0;
  lhz r6, 2(r27);
  bl find_uuid_in_seq;
  clrlwi. r0, r3, 0x18;
  bne lbl_80157558;
lbl_80157540:
  addi r25, r25, 1;
  addi r24, r24, 0xc;
lbl_80157548:
  lhz r0, 8(r28);
  clrlwi r3, r25, 0x10;
  cmplw r3, r0;
  blt lbl_801574ec;
lbl_80157558:
  lhz r0, 8(r28);
  clrlwi r3, r25, 0x10;
  cmplw r3, r0;
  beq lbl_8015757c;
  addi r31, r31, 1;
lbl_8015756c:
  lhz r0, 0(r29);
  clrlwi r3, r31, 0x10;
  cmplw r3, r0;
  blt lbl_801574d0;
lbl_8015757c:
  lhz r0, 0(r29);
  clrlwi r3, r31, 0x10;
  cmplw r3, r0;
  bne lbl_80157594;
  mr r3, r28;
  b lbl_801575a4;
lbl_80157594:
  addi r28, r28, 0x298;
lbl_80157598:
  cmplw r28, r30;
  blt lbl_801574c8;
  li r3, 0;
lbl_801575a4:
  addi r11, r1, 0x30;
  bl _restgpr_24;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: find_uuid_in_seq
// PAL: 0x801575bc..0x80157694
MARK_BINARY_BLOB(find_uuid_in_seq, 0x801575bc, 0x80157694);
asm UNKNOWN_FUNCTION(find_uuid_in_seq) {
  // clang-format off
  nofralloc;
lbl_801575bc:
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_26;
  cmpwi r7, 3;
  mr r26, r3;
  mr r27, r5;
  mr r28, r6;
  mr r29, r7;
  add r31, r3, r4;
  ble lbl_80157670;
  li r3, 0;
  b lbl_8015767c;
  b lbl_80157670;
lbl_801575f8:
  lbz r30, 0(r26);
  addi r3, r26, 1;
  addi r5, r1, 8;
  mr r4, r30;
  bl sdpu_get_len_from_type;
  rlwinm r0, r30, 0x1d, 0x1b, 0x1f;
  mr r26, r3;
  cmplwi r0, 3;
  bne lbl_8015763c;
  lwz r4, 8(r1);
  mr r5, r27;
  mr r6, r28;
  bl sdpu_compare_uuid_arrays;
  clrlwi. r0, r3, 0x18;
  beq lbl_80157668;
  li r3, 1;
  b lbl_8015767c;
lbl_8015763c:
  cmplwi r0, 6;
  bne lbl_80157668;
  lwz r4, 8(r1);
  mr r5, r27;
  mr r6, r28;
  addi r7, r29, 1;
  bl lbl_801575bc;
  clrlwi. r0, r3, 0x18;
  beq lbl_80157668;
  li r3, 1;
  b lbl_8015767c;
lbl_80157668:
  lwz r0, 8(r1);
  add r26, r26, r0;
lbl_80157670:
  cmplw r26, r31;
  blt lbl_801575f8;
  li r3, 0;
lbl_8015767c:
  addi r11, r1, 0x30;
  bl _restgpr_26;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: sdp_db_find_record
// PAL: 0x80157694..0x801576f0
MARK_BINARY_BLOB(sdp_db_find_record, 0x80157694, 0x801576f0);
asm UNKNOWN_FUNCTION(sdp_db_find_record) {
  // clang-format off
  nofralloc;
  lis r5, 0x8034;
  li r0, 0x298;
  addi r5, r5, -24768;
  lhz r4, 0x1222(r5);
  addi r6, r5, 0x1224;
  mulli r4, r4, 0x298;
  add r4, r5, r4;
  addi r5, r4, 0x1224;
  addi r4, r5, 0x297;
  subf r4, r6, r4;
  divwu r4, r4, r0;
  mtctr r4;
  cmplw r6, r5;
  bge lbl_801576e8;
lbl_801576cc:
  lwz r0, 0(r6);
  cmplw r0, r3;
  bne lbl_801576e0;
  mr r3, r6;
  blr;
lbl_801576e0:
  addi r6, r6, 0x298;
  bdnz lbl_801576cc;
lbl_801576e8:
  li r3, 0;
  blr;
  // clang-format on
}

// Symbol: sdp_db_find_attr_in_rec
// PAL: 0x801576f0..0x80157730
MARK_BINARY_BLOB(sdp_db_find_attr_in_rec, 0x801576f0, 0x80157730);
asm UNKNOWN_FUNCTION(sdp_db_find_attr_in_rec) {
  // clang-format off
  nofralloc;
  lhz r6, 8(r3);
  addi r3, r3, 0xc;
  li r7, 0;
  b lbl_8015771c;
lbl_80157700:
  lhz r0, 8(r3);
  cmplw r0, r4;
  blt lbl_80157714;
  cmplw r0, r5;
  blelr;
lbl_80157714:
  addi r7, r7, 1;
  addi r3, r3, 0xc;
lbl_8015771c:
  clrlwi r0, r7, 0x10;
  cmplw r0, r6;
  blt lbl_80157700;
  li r3, 0;
  blr;
  // clang-format on
}

// Symbol: SDP_CreateRecord
// PAL: 0x80157730..0x80157810
MARK_BINARY_BLOB(SDP_CreateRecord, 0x80157730, 0x80157810);
asm UNKNOWN_FUNCTION(SDP_CreateRecord) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  lis r3, 0x8034;
  stw r0, 0x24(r1);
  addi r3, r3, -24768;
  stw r31, 0x1c(r1);
  addi r31, r3, 0x121c;
  lhz r0, 0x1222(r3);
  cmplwi r0, 0x14;
  bge lbl_801577f8;
  mulli r0, r0, 0x298;
  li r4, 0;
  li r5, 0x298;
  add r3, r31, r0;
  addi r3, r3, 8;
  bl memset;
  lhz r4, 6(r31);
  cmpwi r4, 0;
  beq lbl_80157794;
  addi r0, r4, -1;
  mulli r0, r0, 0x298;
  add r3, r31, r0;
  lwz r3, 8(r3);
  addi r3, r3, 1;
  b lbl_80157798;
lbl_80157794:
  lis r3, 1;
lbl_80157798:
  mulli r4, r4, 0x298;
  srwi r0, r3, 0x18;
  rlwinm r6, r3, 0x10, 0x18, 0x1f;
  stb r0, 8(r1);
  rlwinm r0, r3, 0x18, 0x18, 0x1f;
  add r4, r31, r4;
  stw r3, 8(r4);
  addi r7, r1, 8;
  li r4, 0;
  li r5, 1;
  lhz r8, 6(r31);
  stb r6, 9(r1);
  li r6, 4;
  addi r8, r8, 1;
  sth r8, 6(r31);
  stb r0, 0xa(r1);
  stb r3, 0xb(r1);
  bl SDP_AddAttribute;
  lhz r3, 6(r31);
  addi r0, r3, -1;
  mulli r0, r0, 0x298;
  add r3, r31, r0;
  lwz r3, 8(r3);
  b lbl_801577fc;
lbl_801577f8:
  li r3, 0;
lbl_801577fc:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: SDP_DeleteRecord
// PAL: 0x80157810..0x80157924
MARK_BINARY_BLOB(SDP_DeleteRecord, 0x80157810, 0x80157924);
asm UNKNOWN_FUNCTION(SDP_DeleteRecord) {
  // clang-format off
  nofralloc;
  lis r4, 0x8034;
  cmpwi r3, 0;
  addi r4, r4, -24768;
  addi r10, r4, 0x1224;
  beq lbl_80157830;
  lhz r4, 0x1222(r4);
  cmpwi r4, 0;
  bne lbl_80157850;
lbl_80157830:
  lis r4, 0x8034;
  li r0, 0;
  addi r4, r4, -24768;
  li r3, 1;
  sth r0, 0x1222(r4);
  stw r0, 0x121c(r4);
  stb r0, 0x1220(r4);
  blr;
lbl_80157850:
  li r9, 0;
  b lbl_80157910;
lbl_80157858:
  lwz r0, 0(r10);
  cmplw r0, r3;
  bne lbl_80157908;
  lis r5, 0x8034;
  li r7, 0x53;
  addi r5, r5, -24768;
  b lbl_801578d0;
lbl_80157874:
  addi r8, r10, -4;
  addi r6, r10, 0x294;
  mtctr r7;
lbl_80157880:
  lwz r4, 4(r6);
  lwzu r0, 8(r6);
  stw r4, 4(r8);
  stwu r0, 8(r8);
  bdnz lbl_80157880;
  li r8, 0;
  b lbl_801578b8;
lbl_8015789c:
  clrlwi r0, r8, 0x10;
  addi r8, r8, 1;
  mulli r0, r0, 0xc;
  add r6, r10, r0;
  lwz r4, 0x10(r6);
  addi r0, r4, -664;
  stw r0, 0x10(r6);
lbl_801578b8:
  lhz r0, 8(r10);
  clrlwi r4, r8, 0x10;
  cmplw r4, r0;
  blt lbl_8015789c;
  addi r9, r9, 1;
  addi r10, r10, 0x298;
lbl_801578d0:
  lhz r4, 0x1222(r5);
  clrlwi r0, r9, 0x10;
  cmplw r0, r4;
  blt lbl_80157874;
  lwz r0, 0x121c(r5);
  addi r4, r4, -1;
  sth r4, 0x1222(r5);
  cmplw r0, r3;
  bne lbl_80157900;
  li r0, 0;
  stw r0, 0x121c(r5);
  stb r0, 0x1220(r5);
lbl_80157900:
  li r3, 1;
  blr;
lbl_80157908:
  addi r9, r9, 1;
  addi r10, r10, 0x298;
lbl_80157910:
  clrlwi r0, r9, 0x10;
  cmplw r0, r4;
  blt lbl_80157858;
  li r3, 0;
  blr;
  // clang-format on
}

// Symbol: SDP_AddAttribute
// PAL: 0x80157924..0x80157cbc
MARK_BINARY_BLOB(SDP_AddAttribute, 0x80157924, 0x80157cbc);
asm UNKNOWN_FUNCTION(SDP_AddAttribute) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_23;
  lis r8, 0x8034;
  mr r26, r5;
  addi r8, r8, -24768;
  mr r24, r3;
  lhz r9, 0x1222(r8);
  mr r25, r4;
  mr r27, r6;
  mr r28, r7;
  addi r30, r8, 0x1224;
  li r5, 0;
  b lbl_80157c94;
lbl_80157964:
  lwz r0, 0(r30);
  cmplw r0, r3;
  bne lbl_80157c8c;
  lhz r3, 8(r30);
  addi r29, r30, 0xc;
  li r31, 0;
  b lbl_801579a8;
lbl_80157980:
  lhz r0, 8(r29);
  cmplw r0, r4;
  bne lbl_8015799c;
  mr r3, r24;
  mr r4, r25;
  bl SDP_DeleteAttribute;
  b lbl_801579b4;
lbl_8015799c:
  bgt lbl_801579b4;
  addi r31, r31, 1;
  addi r29, r29, 0xc;
lbl_801579a8:
  clrlwi r0, r31, 0x10;
  cmplw r0, r3;
  blt lbl_80157980;
lbl_801579b4:
  lhz r5, 8(r30);
  cmplwi r5, 0x19;
  bne lbl_801579c8;
  li r3, 0;
  b lbl_80157ca4;
lbl_801579c8:
  clrlwi r0, r31, 0x10;
  cmplw r0, r5;
  bne lbl_801579e4;
  mulli r0, r5, 0xc;
  add r3, r30, r0;
  addi r29, r3, 0xc;
  b lbl_80157ba8;
lbl_801579e4:
  cmplw cr1, r5, r0;
  ble cr1, lbl_80157ba8;
  subf r0, r31, r5;
  addi r3, r31, 8;
  clrlwi r0, r0, 0x10;
  cmplwi r0, 8;
  ble lbl_80157b64;
  blt cr1, lbl_80157b64;
  clrlwi r3, r3, 0x10;
  addi r0, r5, 7;
  subf r0, r3, r0;
  srwi r0, r0, 3;
  mtctr r0;
  cmplw r5, r3;
  ble lbl_80157b64;
lbl_80157a20:
  clrlwi r0, r5, 0x10;
  addis r3, r5, 1;
  mulli r4, r0, 0xc;
  lwzux r9, r4, r30;
  addi r6, r3, -1;
  addi r0, r3, -2;
  lwz r7, 4(r4);
  clrlwi r6, r6, 0x10;
  mulli r8, r6, 0xc;
  addi r5, r5, -8;
  stw r9, 0xc(r4);
  clrlwi r6, r0, 0x10;
  addi r0, r3, -3;
  stw r7, 0x10(r4);
  clrlwi r0, r0, 0x10;
  add r23, r30, r8;
  lwz r11, 8(r4);
  mulli r10, r6, 0xc;
  addi r6, r3, -4;
  stw r11, 0x14(r4);
  mulli r9, r0, 0xc;
  addi r0, r3, -5;
  lwzx r12, r30, r8;
  clrlwi r6, r6, 0x10;
  lwz r11, 4(r23);
  clrlwi r7, r0, 0x10;
  stw r12, 0(r4);
  add r12, r30, r10;
  addi r0, r3, -6;
  add r10, r30, r9;
  mulli r8, r6, 0xc;
  stw r11, 4(r4);
  clrlwi r6, r0, 0x10;
  addi r0, r3, -7;
  mulli r3, r6, 0xc;
  lwz r6, 8(r23);
  clrlwi r0, r0, 0x10;
  stw r6, 8(r4);
  add r9, r30, r8;
  mulli r7, r7, 0xc;
  lwz r11, 0(r12);
  add r8, r30, r7;
  add r7, r30, r3;
  lwz r3, 4(r12);
  mulli r0, r0, 0xc;
  stw r11, -0xc(r4);
  stw r3, -8(r4);
  add r6, r30, r0;
  lwz r0, 8(r12);
  stw r0, -4(r4);
  lwz r3, 0(r10);
  lwz r0, 4(r10);
  stw r3, -0x18(r4);
  stw r0, -0x14(r4);
  lwz r0, 8(r10);
  stw r0, -0x10(r4);
  lwz r3, 0(r9);
  lwz r0, 4(r9);
  stw r3, -0x24(r4);
  stw r0, -0x20(r4);
  lwz r0, 8(r9);
  stw r0, -0x1c(r4);
  lwz r3, 0(r8);
  lwz r0, 4(r8);
  stw r3, -0x30(r4);
  stw r0, -0x2c(r4);
  lwz r0, 8(r8);
  stw r0, -0x28(r4);
  lwz r3, 0(r7);
  lwz r0, 4(r7);
  stw r3, -0x3c(r4);
  stw r0, -0x38(r4);
  lwz r0, 8(r7);
  stw r0, -0x34(r4);
  lwz r3, 0(r6);
  lwz r0, 4(r6);
  stw r3, -0x48(r4);
  stw r0, -0x44(r4);
  lwz r0, 8(r6);
  stw r0, -0x40(r4);
  bdnz lbl_80157a20;
lbl_80157b64:
  clrlwi r3, r31, 0x10;
  clrlwi r4, r5, 0x10;
  subf r0, r3, r4;
  mtctr r0;
  cmplw r4, r3;
  ble lbl_80157ba8;
lbl_80157b7c:
  clrlwi r0, r5, 0x10;
  addi r5, r5, -1;
  mulli r0, r0, 0xc;
  add r4, r30, r0;
  lwzx r3, r30, r0;
  lwz r0, 4(r4);
  stw r3, 0xc(r4);
  stw r0, 0x10(r4);
  lwz r0, 8(r4);
  stw r0, 0x14(r4);
  bdnz lbl_80157b7c;
lbl_80157ba8:
  lhz r3, 8(r30);
  addi r0, r3, 1;
  sth r0, 8(r30);
  sth r25, 8(r29);
  stw r27, 0(r29);
  stb r26, 0xa(r29);
  lwz r6, 4(r30);
  add r0, r6, r27;
  cmplwi r0, 0x15e;
  blt lbl_80157c1c;
  lis r3, 0x8034;
  addi r3, r3, -24768;
  lbz r0, 0x4630(r3);
  cmplwi r0, 2;
  blt lbl_80157c00;
  lis r3, 0xa;
  lis r4, 0x8028;
  mr r5, r27;
  subfic r6, r6, 0x15e;
  addi r3, r3, 1;
  addi r4, r4, 0x7810;
  bl LogMsg_2;
lbl_80157c00:
  lwz r0, 4(r30);
  li r3, 0;
  subfic r27, r0, 0x15e;
  stbx r3, r28, r27;
  lwz r0, 4(r30);
  subfic r0, r0, 0x15f;
  stbx r3, r28, r0;
lbl_80157c1c:
  cmpwi r27, 0;
  beq lbl_80157c60;
  cmpwi r28, 0;
  beq lbl_80157c60;
  lwz r0, 4(r30);
  mr r4, r28;
  mr r5, r27;
  add r3, r30, r0;
  addi r3, r3, 0x138;
  bl memcpy;
  lwz r0, 4(r30);
  add r3, r30, r0;
  addi r0, r3, 0x138;
  stw r0, 4(r29);
  lwz r0, 4(r30);
  add r0, r0, r27;
  stw r0, 4(r30);
lbl_80157c60:
  lis r3, 0x8034;
  addi r3, r3, -24768;
  lwz r0, 0x121c(r3);
  cmplw r24, r0;
  bne lbl_80157c84;
  cmplwi r25, 0x8001;
  bne lbl_80157c84;
  li r0, 1;
  stb r0, 0x1220(r3);
lbl_80157c84:
  li r3, 1;
  b lbl_80157ca4;
lbl_80157c8c:
  addi r5, r5, 1;
  addi r30, r30, 0x298;
lbl_80157c94:
  clrlwi r0, r5, 0x10;
  cmplw r0, r9;
  blt lbl_80157964;
  li r3, 0;
lbl_80157ca4:
  addi r11, r1, 0x30;
  bl _restgpr_23;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: SDP_AddUuidSequence
// PAL: 0x80157cbc..0x80157d94
MARK_BINARY_BLOB(SDP_AddUuidSequence, 0x80157cbc, 0x80157d94);
asm UNKNOWN_FUNCTION(SDP_AddUuidSequence) {
  // clang-format off
  nofralloc;
  stwu r1, -0xc0(r1);
  mflr r0;
  li r7, 0;
  stw r0, 0xc4(r1);
  stw r31, 0xbc(r1);
  addi r31, r1, 8;
  stw r30, 0xb8(r1);
  mr r30, r4;
  li r4, 0x19;
  stw r29, 0xb4(r1);
  mr r29, r3;
  mr r3, r31;
  mtctr r5;
  cmplwi r5, 0;
  ble lbl_80157d60;
lbl_80157cf8:
  stb r4, 0(r31);
  lhz r0, 0(r6);
  srawi r0, r0, 8;
  stb r0, 1(r31);
  lhz r0, 0(r6);
  stb r0, 2(r31);
  addi r31, r31, 3;
  subf r0, r3, r31;
  cmpwi r0, 0x4d;
  ble lbl_80157d54;
  lis r3, 0x8034;
  addi r3, r3, -24768;
  lbz r0, 0x4630(r3);
  cmplwi r0, 2;
  blt lbl_80157d60;
  lis r3, 0xa;
  lis r4, 0x8028;
  mr r6, r5;
  clrlwi r5, r7, 0x10;
  addi r3, r3, 1;
  addi r4, r4, 0x784c;
  bl LogMsg_2;
  b lbl_80157d60;
lbl_80157d54:
  addi r7, r7, 1;
  addi r6, r6, 2;
  bdnz lbl_80157cf8;
lbl_80157d60:
  addi r7, r1, 8;
  mr r3, r29;
  mr r4, r30;
  li r5, 6;
  subf r6, r7, r31;
  bl SDP_AddAttribute;
  lwz r0, 0xc4(r1);
  lwz r31, 0xbc(r1);
  lwz r30, 0xb8(r1);
  lwz r29, 0xb4(r1);
  mtlr r0;
  addi r1, r1, 0xc0;
  blr;
  // clang-format on
}

// Symbol: SDP_AddServiceClassIdList
// PAL: 0x80157d94..0x80157f10
MARK_BINARY_BLOB(SDP_AddServiceClassIdList, 0x80157d94, 0x80157f10);
asm UNKNOWN_FUNCTION(SDP_AddServiceClassIdList) {
  // clang-format off
  nofralloc;
  stwu r1, -0xb0(r1);
  mflr r0;
  cmpwi r4, 0;
  li r6, 0;
  stw r0, 0xb4(r1);
  addi r8, r1, 8;
  beq lbl_80157eec;
  cmplwi r4, 8;
  addis r7, r4, 1;
  addi r7, r7, -8;
  ble lbl_80157eac;
  clrlwi r9, r7, 0x10;
  li r0, 0x19;
  addi r7, r9, 7;
  srwi r7, r7, 3;
  mtctr r7;
  cmplwi r9, 0;
  ble lbl_80157eac;
lbl_80157ddc:
  stb r0, 0(r8);
  addi r6, r6, 8;
  lhz r7, 0(r5);
  srawi r7, r7, 8;
  stb r7, 1(r8);
  lhz r7, 0(r5);
  stb r7, 2(r8);
  stb r0, 3(r8);
  lhz r7, 2(r5);
  srawi r7, r7, 8;
  stb r7, 4(r8);
  lhz r7, 2(r5);
  stb r7, 5(r8);
  stb r0, 6(r8);
  lhz r7, 4(r5);
  srawi r7, r7, 8;
  stb r7, 7(r8);
  lhz r7, 4(r5);
  stb r7, 8(r8);
  stb r0, 9(r8);
  lhz r7, 6(r5);
  srawi r7, r7, 8;
  stb r7, 0xa(r8);
  lhz r7, 6(r5);
  stb r7, 0xb(r8);
  stb r0, 0xc(r8);
  lhz r7, 8(r5);
  srawi r7, r7, 8;
  stb r7, 0xd(r8);
  lhz r7, 8(r5);
  stb r7, 0xe(r8);
  stb r0, 0xf(r8);
  lhz r7, 0xa(r5);
  srawi r7, r7, 8;
  stb r7, 0x10(r8);
  lhz r7, 0xa(r5);
  stb r7, 0x11(r8);
  stb r0, 0x12(r8);
  lhz r7, 0xc(r5);
  srawi r7, r7, 8;
  stb r7, 0x13(r8);
  lhz r7, 0xc(r5);
  stb r7, 0x14(r8);
  stb r0, 0x15(r8);
  lhz r7, 0xe(r5);
  srawi r7, r7, 8;
  stb r7, 0x16(r8);
  lhz r7, 0xe(r5);
  addi r5, r5, 0x10;
  stb r7, 0x17(r8);
  addi r8, r8, 0x18;
  bdnz lbl_80157ddc;
lbl_80157eac:
  clrlwi r7, r6, 0x10;
  li r9, 0x19;
  subf r0, r7, r4;
  mtctr r0;
  cmplw r7, r4;
  bge lbl_80157eec;
lbl_80157ec4:
  stb r9, 0(r8);
  addi r6, r6, 1;
  lhz r0, 0(r5);
  srawi r0, r0, 8;
  stb r0, 1(r8);
  lhz r0, 0(r5);
  addi r5, r5, 2;
  stb r0, 2(r8);
  addi r8, r8, 3;
  bdnz lbl_80157ec4;
lbl_80157eec:
  addi r7, r1, 8;
  li r4, 1;
  subf r6, r7, r8;
  li r5, 6;
  bl SDP_AddAttribute;
  lwz r0, 0xb4(r1);
  mtlr r0;
  addi r1, r1, 0xb0;
  blr;
  // clang-format on
}

// Symbol: SDP_DeleteAttribute
// PAL: 0x80157f10..0x8015814c
MARK_BINARY_BLOB(SDP_DeleteAttribute, 0x80157f10, 0x8015814c);
asm UNKNOWN_FUNCTION(SDP_DeleteAttribute) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_25;
  lis r27, 0x8034;
  mr r25, r3;
  addi r27, r27, -24768;
  mr r26, r4;
  addi r31, r27, 0x1224;
  li r3, 0;
  lis r28, 0xa;
  lis r29, 0x8028;
  b lbl_80158120;
lbl_80157f48:
  lwz r0, 0(r31);
  cmplw r0, r25;
  bne lbl_80158118;
  lbz r0, 0x4630(r27);
  addi r30, r31, 0xc;
  cmplwi r0, 3;
  blt lbl_80157f78;
  mr r5, r26;
  mr r6, r25;
  addi r3, r28, 2;
  addi r4, r29, 0x7880;
  bl LogMsg_2;
lbl_80157f78:
  lhz r4, 8(r31);
  li r3, 0;
  b lbl_8015810c;
lbl_80157f84:
  lhz r0, 8(r30);
  cmplw r0, r26;
  bne lbl_80158104;
  lwz r0, 0(r30);
  lwz r4, 4(r30);
  cmpwi r0, 0;
  beq lbl_80157fdc;
  li r7, 0;
  b lbl_80157fcc;
lbl_80157fa8:
  clrlwi r5, r7, 0x10;
  mulli r5, r5, 0xc;
  add r6, r31, r5;
  lwz r5, 0x10(r6);
  cmplw r5, r4;
  ble lbl_80157fc8;
  subf r5, r0, r5;
  stw r5, 0x10(r6);
lbl_80157fc8:
  addi r7, r7, 1;
lbl_80157fcc:
  lhz r5, 8(r31);
  clrlwi r6, r7, 0x10;
  cmplw r6, r5;
  blt lbl_80157fa8;
lbl_80157fdc:
  lhz r5, 8(r31);
  addi r5, r5, -1;
  sth r5, 8(r31);
  b lbl_8015800c;
lbl_80157fec:
  lwz r6, 0xc(r30);
  addi r3, r3, 1;
  lwz r5, 0x10(r30);
  stw r6, 0(r30);
  stw r5, 4(r30);
  lwz r5, 0x14(r30);
  stw r5, 8(r30);
  addi r30, r30, 0xc;
lbl_8015800c:
  lhz r5, 8(r31);
  clrlwi r6, r3, 0x10;
  cmplw r6, r5;
  blt lbl_80157fec;
  cmpwi r0, 0;
  beq lbl_801580fc;
  addi r5, r31, 0x138;
  add r6, r4, r0;
  lwz r3, 4(r31);
  subf r5, r5, r6;
  li r7, 0;
  subf r3, r5, r3;
  clrlwi. r8, r3, 0x10;
  beq lbl_801580f0;
  cmplwi r8, 8;
  addis r3, r8, 1;
  addi r3, r3, -8;
  ble lbl_801580c0;
  clrlwi r5, r3, 0x10;
  addi r3, r5, 7;
  srwi r3, r3, 3;
  mtctr r3;
  cmplwi r5, 0;
  ble lbl_801580c0;
lbl_8015806c:
  lbz r3, 0(r6);
  add r5, r4, r0;
  addi r7, r7, 8;
  addi r6, r6, 8;
  stb r3, 0(r4);
  lbz r3, 1(r5);
  stb r3, 1(r4);
  lbz r3, 2(r5);
  stb r3, 2(r4);
  lbz r3, 3(r5);
  stb r3, 3(r4);
  lbz r3, 4(r5);
  stb r3, 4(r4);
  lbz r3, 5(r5);
  stb r3, 5(r4);
  lbz r3, 6(r5);
  stb r3, 6(r4);
  lbz r3, 7(r5);
  stb r3, 7(r4);
  addi r4, r4, 8;
  bdnz lbl_8015806c;
lbl_801580c0:
  clrlwi r6, r7, 0x10;
  add r5, r0, r4;
  subf r3, r6, r8;
  mtctr r3;
  cmplw r6, r8;
  bge lbl_801580f0;
lbl_801580d8:
  lbz r3, 0(r5);
  addi r7, r7, 1;
  addi r5, r5, 1;
  stb r3, 0(r4);
  addi r4, r4, 1;
  bdnz lbl_801580d8;
lbl_801580f0:
  lwz r3, 4(r31);
  subf r0, r0, r3;
  stw r0, 4(r31);
lbl_801580fc:
  li r3, 1;
  b lbl_80158134;
lbl_80158104:
  addi r3, r3, 1;
  addi r30, r30, 0xc;
lbl_8015810c:
  clrlwi r0, r3, 0x10;
  cmplw r0, r4;
  blt lbl_80157f84;
lbl_80158118:
  addi r3, r3, 1;
  addi r31, r31, 0x298;
lbl_80158120:
  lhz r0, 0x1222(r27);
  clrlwi r4, r3, 0x10;
  cmplw r4, r0;
  blt lbl_80157f48;
  li r3, 0;
lbl_80158134:
  addi r11, r1, 0x30;
  bl _restgpr_25;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

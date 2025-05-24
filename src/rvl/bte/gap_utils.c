#include "gap_utils.h"

#include <string.h>

#include "bte_logmsg.h"
#include "btm_inq.h"

// Symbol: btm_cback
// PAL: 0x80143ffc..0x801441d4
MARK_BINARY_BLOB(btm_cback, 0x80143ffc, 0x801441d4);
asm UNKNOWN_FUNCTION(btm_cback) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  lis r7, 0x8028;
  cmplwi r3, 2;
  stw r0, 0x24(r1);
  addi r7, r7, 0x4c60;
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  mr r30, r4;
  bge lbl_801441bc;
  lis r8, 0x8034;
  rlwinm r0, r3, 4, 0xc, 0x1b;
  addi r8, r8, -30144;
  add r31, r8, r0;
  lbz r0, 0xf(r31);
  cmpwi r0, 0;
  beq lbl_801441bc;
  lhz r0, 0xc(r31);
  cmpwi r0, 3;
  beq lbl_801440b4;
  bge lbl_8014405c;
  cmpwi r0, 2;
  bge lbl_80144068;
  b lbl_8014418c;
lbl_8014405c:
  cmpwi r0, 5;
  bge lbl_8014418c;
  b lbl_80144100;
lbl_80144068:
  lbz r6, 1(r4);
  li r3, 0x114;
  lbz r0, 0x28(r8);
  addi r30, r1, 8;
  stb r6, 0xa(r1);
  cmplwi r0, 4;
  lbz r0, 0(r4);
  cntlzw r0, r0;
  rlwinm r0, r0, 0x1b, 0x1f, 0x1f;
  neg r0, r0;
  andc r0, r3, r0;
  sth r0, 8(r1);
  blt lbl_8014418c;
  lis r3, 0xe;
  addi r4, r7, 0;
  addi r3, r3, 3;
  clrlwi r5, r0, 0x10;
  bl LogMsg_2;
  b lbl_8014418c;
lbl_801440b4:
  lhz r5, 0(r4);
  cmpwi r5, 0;
  beq lbl_801440e0;
  lbz r0, 0x28(r8);
  cmplwi r0, 4;
  blt lbl_8014418c;
  lis r3, 0xe;
  addi r4, r7, 0x3c;
  addi r3, r3, 3;
  bl LogMsg_1;
  b lbl_8014418c;
lbl_801440e0:
  lbz r0, 0x28(r8);
  cmplwi r0, 4;
  blt lbl_8014418c;
  lis r3, 0xe;
  addi r4, r7, 0x70;
  addi r3, r3, 3;
  bl LogMsg_0;
  b lbl_8014418c;
lbl_80144100:
  lhz r0, 0(r4);
  clrlwi r0, r0, 0x18;
  cmplwi r0, 8;
  bgt lbl_80144160;
  lis r3, 0x8028;
  slwi r0, r0, 2;
  addi r3, r3, 0x4d2c;
  lwzx r3, r3, r0;
  mtctr r3;
  bctr;
  li r5, 0;
  b lbl_80144164;
  li r5, 0x10b;
  b lbl_80144164;
  li r5, 0x103;
  b lbl_80144164;
  li r5, 0x109;
  b lbl_80144164;
  li r5, 0x10c;
  b lbl_80144164;
  li r5, 0x10d;
  b lbl_80144164;
  li r5, 0x115;
  b lbl_80144164;
lbl_80144160:
  li r5, 0x114;
lbl_80144164:
  lis r3, 0x8034;
  sth r5, 0(r4);
  addi r3, r3, -30144;
  lbz r0, 0x28(r3);
  cmplwi r0, 4;
  blt lbl_8014418c;
  lis r3, 0xe;
  addi r4, r7, 0x98;
  addi r3, r3, 3;
  bl LogMsg_1;
lbl_8014418c:
  lwz r12, 4(r31);
  cmpwi r12, 0;
  beq lbl_801441a8;
  mr r4, r30;
  lhz r3, 0xc(r31);
  mtctr r12;
  bctrl;
lbl_801441a8:
  cmpwi r31, 0;
  beq lbl_801441bc;
  li r0, 0;
  stw r0, 4(r31);
  stb r0, 0xf(r31);
lbl_801441bc:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: gap_btm_cback0
// PAL: 0x801441d4..0x801441e0
MARK_BINARY_BLOB(gap_btm_cback0, 0x801441d4, 0x801441e0);
asm UNKNOWN_FUNCTION(gap_btm_cback0) {
  // clang-format off
  nofralloc;
  mr r4, r3;
  li r3, 0;
  b btm_cback;
  // clang-format on
}

// Symbol: gap_btm_cback1
// PAL: 0x801441e0..0x801441ec
MARK_BINARY_BLOB(gap_btm_cback1, 0x801441e0, 0x801441ec);
asm UNKNOWN_FUNCTION(gap_btm_cback1) {
  // clang-format off
  nofralloc;
  mr r4, r3;
  li r3, 1;
  b btm_cback;
  // clang-format on
}

// Symbol: gap_find_addr_name_cb
// PAL: 0x801441ec..0x80144404
MARK_BINARY_BLOB(gap_find_addr_name_cb, 0x801441ec, 0x80144404);
asm UNKNOWN_FUNCTION(gap_find_addr_name_cb) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  lis r31, 0x8034;
  addi r31, r31, -30144;
  stw r30, 0x18(r1);
  addi r30, r31, 0x34;
  stw r29, 0x14(r1);
  mr r29, r3;
  lbz r0, 0x7e(r31);
  cmpwi r0, 0;
  beq lbl_801443e8;
  lhz r5, 0(r3);
  cmpwi r5, 0;
  bne lbl_80144338;
  lbz r0, 0x28(r31);
  cmplwi r0, 4;
  blt lbl_80144250;
  lis r3, 0xe;
  lis r4, 0x8028;
  addi r6, r29, 4;
  addi r3, r3, 3;
  addi r4, r4, 0x4dd8;
  bl LogMsg_2;
lbl_80144250:
  addi r3, r30, 8;
  bl strlen;
  mr r5, r3;
  addi r3, r30, 8;
  addi r4, r29, 4;
  bl strncmp;
  cmpwi r3, 0;
  bne lbl_80144290;
  lwz r4, 0x30(r31);
  addi r3, r30, 2;
  li r5, 6;
  addi r4, r4, 2;
  bl memcpy;
  li r0, 0;
  sth r0, 0(r30);
  b lbl_801443c0;
lbl_80144290:
  lwz r3, 0x30(r31);
  bl BTM_InqDbNext;
  cmpwi r3, 0;
  stw r3, 0x30(r31);
  beq lbl_8014432c;
  lis r4, 0x8014;
  addi r3, r3, 2;
  addi r4, r4, 0x41ec;
  bl BTM_ReadRemoteDeviceName;
  clrlwi r0, r3, 0x18;
  cmplwi r0, 1;
  beq lbl_801443e8;
  lhz r0, 0(r29);
  clrlwi r0, r0, 0x18;
  cmplwi r0, 8;
  bgt lbl_80144320;
  lis r3, 0x8028;
  slwi r0, r0, 2;
  addi r3, r3, 0x4e7c;
  lwzx r3, r3, r0;
  mtctr r3;
  bctr;
  li r0, 0;
  b lbl_80144324;
  li r0, 0x10b;
  b lbl_80144324;
  li r0, 0x103;
  b lbl_80144324;
  li r0, 0x109;
  b lbl_80144324;
  li r0, 0x10c;
  b lbl_80144324;
  li r0, 0x10d;
  b lbl_80144324;
  li r0, 0x115;
  b lbl_80144324;
lbl_80144320:
  li r0, 0x114;
lbl_80144324:
  sth r0, 0(r30);
  b lbl_801443c0;
lbl_8014432c:
  li r0, 0x102;
  sth r0, 0(r30);
  b lbl_801443c0;
lbl_80144338:
  lbz r0, 0x28(r31);
  cmplwi r0, 4;
  blt lbl_80144358;
  lis r3, 0xe;
  lis r4, 0x8028;
  addi r3, r3, 3;
  addi r4, r4, 0x4e1c;
  bl LogMsg_1;
lbl_80144358:
  lhz r0, 0(r29);
  clrlwi r0, r0, 0x18;
  cmplwi r0, 8;
  bgt lbl_801443b8;
  lis r3, 0x8028;
  slwi r0, r0, 2;
  addi r3, r3, 0x4e58;
  lwzx r3, r3, r0;
  mtctr r3;
  bctr;
  li r0, 0;
  b lbl_801443bc;
  li r0, 0x10b;
  b lbl_801443bc;
  li r0, 0x103;
  b lbl_801443bc;
  li r0, 0x109;
  b lbl_801443bc;
  li r0, 0x10c;
  b lbl_801443bc;
  li r0, 0x10d;
  b lbl_801443bc;
  li r0, 0x115;
  b lbl_801443bc;
lbl_801443b8:
  li r0, 0x114;
lbl_801443bc:
  sth r0, 0(r30);
lbl_801443c0:
  lwz r12, 0x2c(r31);
  cmpwi r12, 0;
  beq lbl_801443dc;
  mr r4, r30;
  li r3, 5;
  mtctr r12;
  bctrl;
lbl_801443dc:
  li r0, 0;
  stb r0, 0x7e(r31);
  stw r0, 0x2c(r31);
lbl_801443e8:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: gap_find_addr_inq_cb
// PAL: 0x80144404..0x801445b8
MARK_BINARY_BLOB(gap_find_addr_inq_cb, 0x80144404, 0x801445b8);
asm UNKNOWN_FUNCTION(gap_find_addr_inq_cb) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  lis r31, 0x8034;
  addi r31, r31, -30144;
  stw r30, 0x18(r1);
  addi r30, r31, 0x34;
  stw r29, 0x14(r1);
  mr r29, r3;
  lbz r0, 0x7e(r31);
  cmpwi r0, 0;
  beq lbl_8014459c;
  lbz r0, 0x28(r31);
  cmplwi r0, 4;
  blt lbl_80144460;
  lis r3, 0xe;
  lis r4, 0x8028;
  lbz r5, 0(r29);
  addi r3, r3, 3;
  lbz r6, 1(r29);
  addi r4, r4, 0x4ea0;
  bl LogMsg_2;
lbl_80144460:
  lbz r0, 0(r29);
  cmpwi r0, 0;
  bne lbl_80144514;
  li r0, 0x111;
  sth r0, 0(r30);
  bl BTM_InqDbFirst;
  cmpwi r3, 0;
  stw r3, 0x30(r31);
  beq lbl_80144508;
  lis r4, 0x8014;
  addi r3, r3, 2;
  addi r4, r4, 0x41ec;
  bl BTM_ReadRemoteDeviceName;
  clrlwi r0, r3, 0x18;
  cmplwi r0, 1;
  beq lbl_8014459c;
  lbz r0, 0(r29);
  cmplwi r0, 8;
  bgt lbl_801444fc;
  lis r3, 0x8028;
  slwi r0, r0, 2;
  addi r3, r3, 0x4f08;
  lwzx r3, r3, r0;
  mtctr r3;
  bctr;
  li r0, 0;
  b lbl_80144500;
  li r0, 0x10b;
  b lbl_80144500;
  li r0, 0x103;
  b lbl_80144500;
  li r0, 0x109;
  b lbl_80144500;
  li r0, 0x10c;
  b lbl_80144500;
  li r0, 0x10d;
  b lbl_80144500;
  li r0, 0x115;
  b lbl_80144500;
lbl_801444fc:
  li r0, 0x114;
lbl_80144500:
  sth r0, 0(r30);
  b lbl_80144574;
lbl_80144508:
  li r0, 0x102;
  sth r0, 0(r30);
  b lbl_80144574;
lbl_80144514:
  cmplwi r0, 8;
  bgt lbl_8014456c;
  lis r3, 0x8028;
  slwi r0, r0, 2;
  addi r3, r3, 0x4ee4;
  lwzx r3, r3, r0;
  mtctr r3;
  bctr;
  li r0, 0;
  b lbl_80144570;
  li r0, 0x10b;
  b lbl_80144570;
  li r0, 0x103;
  b lbl_80144570;
  li r0, 0x109;
  b lbl_80144570;
  li r0, 0x10c;
  b lbl_80144570;
  li r0, 0x10d;
  b lbl_80144570;
  li r0, 0x115;
  b lbl_80144570;
lbl_8014456c:
  li r0, 0x114;
lbl_80144570:
  sth r0, 0(r30);
lbl_80144574:
  lwz r12, 0x2c(r31);
  cmpwi r12, 0;
  beq lbl_80144590;
  mr r4, r30;
  li r3, 5;
  mtctr r12;
  bctrl;
lbl_80144590:
  li r0, 0;
  stb r0, 0x7e(r31);
  stw r0, 0x2c(r31);
lbl_8014459c:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: gap_convert_btm_status
// PAL: 0x801445b8..0x80144618
MARK_BINARY_BLOB(gap_convert_btm_status, 0x801445b8, 0x80144618);
asm UNKNOWN_FUNCTION(gap_convert_btm_status) {
  // clang-format off
  nofralloc;
  cmplwi r3, 8;
  bgt lbl_80144610;
  lis r4, 0x8028;
  slwi r0, r3, 2;
  addi r4, r4, 0x4f2c;
  lwzx r4, r4, r0;
  mtctr r4;
  bctr;
  li r3, 0;
  blr;
  li r3, 0x10b;
  blr;
  li r3, 0x103;
  blr;
  li r3, 0x109;
  blr;
  li r3, 0x10c;
  blr;
  li r3, 0x10d;
  blr;
  li r3, 0x115;
  blr;
lbl_80144610:
  li r3, 0x114;
  blr;
  // clang-format on
}

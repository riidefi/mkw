#include "bta_hh_main.h"

#include <string.h>

#include "bte_logmsg.h"
#include "bd.h"
#include "bta_hh_api.h"
#include "bta_hh_act.h"
#include "bta_hh_utils.h"

// Symbol: bta_hh_sm_execute
// PAL: 0x8013735c..0x801376b0
MARK_BINARY_BLOB(bta_hh_sm_execute, 0x8013735c, 0x801376b0);
asm UNKNOWN_FUNCTION(bta_hh_sm_execute) {
  // clang-format off
  nofralloc;
  stwu r1, -0x40(r1);
  mflr r0;
  stw r0, 0x44(r1);
  addi r11, r1, 0x40;
  bl _savegpr_26;
  lis r31, 0x8028;
  mr r27, r3;
  mr r28, r4;
  mr r29, r5;
  addi r31, r31, 0x2f80;
  addi r3, r1, 8;
  li r30, 0;
  li r4, 0;
  li r5, 0x20;
  bl memset;
  cmpwi r27, 0;
  bne lbl_801374f4;
  lis r3, 0x8033;
  addi r3, r3, 0x6048;
  lwz r0, 0x224(r3);
  cmpwi r0, 0;
  beq lbl_80137698;
  cmpwi r28, 0x1708;
  beq lbl_80137448;
  bge lbl_801373d8;
  cmpwi r28, 0x1701;
  beq lbl_8013749c;
  bge lbl_801374b4;
  cmpwi r28, 0x1700;
  bge lbl_801373e4;
  b lbl_801374b4;
lbl_801373d8:
  cmpwi r28, 0x170a;
  beq lbl_80137408;
  b lbl_801374b4;
lbl_801373e4:
  addi r3, r1, 8;
  addi r4, r29, 8;
  li r30, 2;
  bl bdcpy;
  li r3, 9;
  li r0, 0xff;
  stb r3, 0xe(r1);
  stb r0, 0xf(r1);
  b lbl_801374d0;
lbl_80137408:
  lhz r30, 0x10(r29);
  cmplwi r30, 0xb;
  bne lbl_80137434;
  addi r3, r1, 8;
  addi r4, r29, 8;
  bl bdcpy;
  li r3, 9;
  li r0, 0xff;
  stb r3, 0xe(r1);
  stb r0, 0xf(r1);
  b lbl_801374d0;
lbl_80137434:
  li r0, 0xd;
  stb r0, 0xe(r1);
  lhz r0, 6(r29);
  stb r0, 0xf(r1);
  b lbl_801374d0;
lbl_80137448:
  lbz r30, 8(r29);
  cmplwi r30, 7;
  beq lbl_80137464;
  cmplwi r30, 5;
  beq lbl_80137464;
  cmplwi r30, 9;
  bne lbl_80137478;
lbl_80137464:
  li r0, 0xd;
  stb r0, 8(r1);
  lhz r0, 6(r29);
  stb r0, 9(r1);
  b lbl_801374d0;
lbl_80137478:
  cmplwi r30, 0xa;
  beq lbl_801374d0;
  cmplwi r30, 1;
  beq lbl_801374d0;
  lhz r3, 6(r29);
  li r0, 0xd;
  stb r3, 9(r1);
  stb r0, 8(r1);
  b lbl_801374d0;
lbl_8013749c:
  li r0, 0xd;
  li r30, 3;
  stb r0, 8(r1);
  lhz r0, 6(r29);
  stb r0, 9(r1);
  b lbl_801374d0;
lbl_801374b4:
  lbz r0, -0x6610(r13);
  cmplwi r0, 1;
  blt lbl_801374d0;
  lhz r5, 6(r29);
  addi r4, r31, 0;
  li r3, 0x500;
  bl LogMsg_1;
lbl_801374d0:
  clrlwi. r3, r30, 0x10;
  beq lbl_80137698;
  lis r5, 0x8033;
  addi r4, r1, 8;
  addi r5, r5, 0x6048;
  lwz r12, 0x224(r5);
  mtctr r12;
  bctrl;
  b lbl_80137698;
lbl_801374f4:
  lbz r0, -0x6610(r13);
  lbz r30, 0x1c(r27);
  cmplwi r0, 4;
  blt lbl_80137570;
  cmpwi r30, 2;
  beq lbl_8013753c;
  bge lbl_80137520;
  cmpwi r30, 0;
  beq lbl_8013752c;
  bge lbl_80137534;
  b lbl_8013754c;
lbl_80137520:
  cmpwi r30, 4;
  bge lbl_8013754c;
  b lbl_80137544;
lbl_8013752c:
  addi r26, r31, 0x1c;
  b lbl_80137550;
lbl_80137534:
  addi r26, r31, 0x2c;
  b lbl_80137550;
lbl_8013753c:
  addi r26, r31, 0x3c;
  b lbl_80137550;
lbl_80137544:
  addi r26, r31, 0x50;
  b lbl_80137550;
lbl_8013754c:
  addi r26, r31, 0x60;
lbl_80137550:
  mr r3, r28;
  bl bta_hh_evt_code;
  mr r7, r3;
  mr r5, r30;
  mr r6, r26;
  addi r4, r31, 0x78;
  li r3, 0x503;
  bl LogMsg_3;
lbl_80137570:
  lbz r4, 0x1c(r27);
  lis r3, 0x8025;
  addi r3, r3, -13856;
  clrlwi r28, r28, 0x18;
  addi r0, r4, -1;
  slwi r0, r0, 2;
  slwi r4, r28, 1;
  lwzx r5, r3, r0;
  add r3, r5, r4;
  lbz r0, 1(r3);
  stb r0, 0x1c(r27);
  lbzx r0, r5, r4;
  cmplwi r0, 0xc;
  beq lbl_801375c8;
  lis r4, 0x8025;
  rlwinm r0, r0, 2, 0x16, 0x1d;
  addi r4, r4, -13976;
  mr r3, r27;
  lwzx r12, r4, r0;
  mr r4, r29;
  mtctr r12;
  bctrl;
lbl_801375c8:
  lbz r3, 0x1c(r27);
  cmplw r30, r3;
  beq lbl_80137698;
  lbz r0, -0x6610(r13);
  cmplwi r0, 5;
  blt lbl_80137698;
  cmpwi r30, 2;
  beq lbl_80137618;
  bge lbl_801375fc;
  cmpwi r30, 0;
  beq lbl_80137608;
  bge lbl_80137610;
  b lbl_80137628;
lbl_801375fc:
  cmpwi r30, 4;
  bge lbl_80137628;
  b lbl_80137620;
lbl_80137608:
  addi r26, r31, 0x1c;
  b lbl_8013762c;
lbl_80137610:
  addi r26, r31, 0x2c;
  b lbl_8013762c;
lbl_80137618:
  addi r26, r31, 0x3c;
  b lbl_8013762c;
lbl_80137620:
  addi r26, r31, 0x50;
  b lbl_8013762c;
lbl_80137628:
  addi r26, r31, 0x60;
lbl_8013762c:
  cmpwi r3, 2;
  beq lbl_80137664;
  bge lbl_80137648;
  cmpwi r3, 0;
  beq lbl_80137654;
  bge lbl_8013765c;
  b lbl_80137674;
lbl_80137648:
  cmpwi r3, 4;
  bge lbl_80137674;
  b lbl_8013766c;
lbl_80137654:
  addi r27, r31, 0x1c;
  b lbl_80137678;
lbl_8013765c:
  addi r27, r31, 0x2c;
  b lbl_80137678;
lbl_80137664:
  addi r27, r31, 0x3c;
  b lbl_80137678;
lbl_8013766c:
  addi r27, r31, 0x50;
  b lbl_80137678;
lbl_80137674:
  addi r27, r31, 0x60;
lbl_80137678:
  mr r3, r28;
  bl bta_hh_evt_code;
  mr r7, r3;
  mr r5, r26;
  mr r6, r27;
  addi r4, r31, 0xac;
  li r3, 0x504;
  bl LogMsg_3;
lbl_80137698:
  addi r11, r1, 0x40;
  bl _restgpr_26;
  lwz r0, 0x44(r1);
  mtlr r0;
  addi r1, r1, 0x40;
  blr;
  // clang-format on
}

// Symbol: bta_hh_hdl_event
// PAL: 0x801376b0..0x801377fc
MARK_BINARY_BLOB(bta_hh_hdl_event, 0x801376b0, 0x801377fc);
asm UNKNOWN_FUNCTION(bta_hh_hdl_event) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  li r6, 0x10;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  li r31, 0;
  stw r30, 8(r1);
  mr r30, r3;
  lhz r0, 0(r3);
  cmpwi r0, 0x170e;
  beq lbl_80137714;
  bge lbl_801376f0;
  cmpwi r0, 0x170c;
  beq lbl_801376fc;
  bge lbl_80137704;
  b lbl_8013771c;
lbl_801376f0:
  cmpwi r0, 0x1710;
  bge lbl_8013771c;
  b lbl_8013770c;
lbl_801376fc:
  bl bta_hh_api_enable;
  b lbl_801377e0;
lbl_80137704:
  bl bta_hh_api_disable;
  b lbl_801377e0;
lbl_8013770c:
  bl bta_hh_disc_cmpl;
  b lbl_801377e0;
lbl_80137714:
  bl bta_hh_get_acl_q_info;
  b lbl_801377e0;
lbl_8013771c:
  cmplwi r0, 0x1700;
  bne lbl_80137734;
  addi r3, r3, 8;
  bl bta_hh_find_cb;
  mr r6, r3;
  b lbl_8013778c;
lbl_80137734:
  cmplwi r0, 0x170a;
  bne lbl_80137770;
  lhz r0, 0x10(r3);
  cmplwi r0, 0xb;
  bne lbl_80137758;
  addi r3, r3, 8;
  bl bta_hh_find_cb;
  mr r6, r3;
  b lbl_8013778c;
lbl_80137758:
  lis r4, 0x8033;
  lhz r0, 6(r3);
  addi r4, r4, 0x6048;
  add r3, r4, r0;
  lbz r6, 0x214(r3);
  b lbl_8013778c;
lbl_80137770:
  lhz r0, 6(r3);
  cmplwi r0, 0x10;
  bge lbl_8013778c;
  lis r3, 0x8033;
  addi r3, r3, 0x6048;
  add r3, r3, r0;
  lbz r6, 0x214(r3);
lbl_8013778c:
  clrlwi r0, r6, 0x18;
  cmplwi r0, 0x10;
  beq lbl_801377ac;
  lis r3, 0x8033;
  rlwinm r0, r6, 5, 0x13, 0x1a;
  addi r3, r3, 0x6048;
  add r3, r3, r0;
  addi r31, r3, 0x10;
lbl_801377ac:
  lbz r0, -0x6610(r13);
  cmplwi r0, 5;
  blt lbl_801377d0;
  lis r4, 0x8028;
  lhz r5, 6(r30);
  addi r4, r4, 0x305c;
  clrlwi r6, r6, 0x18;
  li r3, 0x504;
  bl LogMsg_2;
lbl_801377d0:
  lhz r4, 0(r30);
  mr r3, r31;
  mr r5, r30;
  bl bta_hh_sm_execute;
lbl_801377e0:
  lwz r31, 0xc(r1);
  li r3, 1;
  lwz r30, 8(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: bta_hh_evt_code
// PAL: 0x801377fc..0x801378b0
MARK_BINARY_BLOB(bta_hh_evt_code, 0x801377fc, 0x801378b0);
asm UNKNOWN_FUNCTION(bta_hh_evt_code) {
  // clang-format off
  nofralloc;
  addi r0, r3, -5888;
  lis r4, 0x8028;
  cmplwi r0, 0xf;
  addi r4, r4, 0x2f80;
  bgt lbl_801378a8;
  lis r3, 0x8028;
  slwi r0, r0, 2;
  addi r3, r3, 0x3220;
  lwzx r3, r3, r0;
  mtctr r3;
  bctr;
  addi r3, r4, 0x108;
  blr;
  addi r3, r4, 0x120;
  blr;
  addi r3, r4, 0x138;
  blr;
  addi r3, r4, 0x14c;
  blr;
  addi r3, r4, 0x164;
  blr;
  addi r3, r4, 0x178;
  blr;
  addi r3, r4, 0x190;
  blr;
  addi r3, r4, 0x1a8;
  blr;
  addi r3, r4, 0x1bc;
  blr;
  addi r3, r4, 0x1d4;
  blr;
  addi r3, r4, 0x1f0;
  blr;
  addi r3, r4, 0x204;
  blr;
  addi r3, r4, 0x21c;
  blr;
  addi r3, r4, 0x238;
  blr;
  addi r3, r4, 0x250;
  blr;
  addi r3, r4, 0x268;
  blr;
lbl_801378a8:
  addi r3, r4, 0x284;
  blr;
  // clang-format on
}

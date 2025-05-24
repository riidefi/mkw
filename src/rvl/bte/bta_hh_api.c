#include "bta_hh_api.h"

#include <string.h>

#include "gki_buffer.h"
#include "gki_ppc.h"
#include "bte_logmsg.h"
#include "bd.h"
#include "bta_sys.h"

// Symbol: BTA_HhEnable
// PAL: 0x80136f8c..0x80137014
MARK_BINARY_BLOB(BTA_HhEnable, 0x80136f8c, 0x80137014);
asm UNKNOWN_FUNCTION(BTA_HhEnable) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  mr r30, r4;
  stw r29, 0x14(r1);
  mr r29, r3;
  bl GKI_sched_lock;
  li r3, 0x17;
  addi r4, r2, -26896;
  bl bta_sys_register;
  bl GKI_sched_unlock;
  li r3, 0x34;
  bl GKI_getbuf;
  cmpwi r3, 0;
  mr r31, r3;
  beq lbl_80136ff8;
  li r4, 0;
  li r5, 0x34;
  bl memset;
  li r0, 0x170c;
  mr r3, r31;
  sth r0, 0(r31);
  stw r30, 0x30(r31);
  stb r29, 8(r31);
  bl bta_sys_sendmsg;
lbl_80136ff8:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: BTA_HhDisable
// PAL: 0x80137014..0x8013704c
MARK_BINARY_BLOB(BTA_HhDisable, 0x80137014, 0x8013704c);
asm UNKNOWN_FUNCTION(BTA_HhDisable) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  li r3, 8;
  stw r0, 0x14(r1);
  bl GKI_getbuf;
  cmpwi r3, 0;
  beq lbl_8013703c;
  li r0, 0x170d;
  sth r0, 0(r3);
  bl bta_sys_sendmsg;
lbl_8013703c:
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: BTA_HhClose
// PAL: 0x8013704c..0x801370b0
MARK_BINARY_BLOB(BTA_HhClose, 0x8013704c, 0x801370b0);
asm UNKNOWN_FUNCTION(BTA_HhClose) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  stw r30, 8(r1);
  mr r30, r3;
  li r3, 8;
  bl GKI_getbuf;
  cmpwi r3, 0;
  mr r31, r3;
  beq lbl_80137098;
  li r4, 0;
  li r5, 8;
  bl memset;
  li r0, 0x1701;
  mr r3, r31;
  sth r0, 0(r31);
  sth r30, 6(r31);
  bl bta_sys_sendmsg;
lbl_80137098:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: BTA_HhOpen
// PAL: 0x801370b0..0x80137164
MARK_BINARY_BLOB(BTA_HhOpen, 0x801370b0, 0x80137164);
asm UNKNOWN_FUNCTION(BTA_HhOpen) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  mr r30, r5;
  stw r29, 0x14(r1);
  mr r29, r4;
  stw r28, 0x10(r1);
  mr r28, r3;
  li r3, 0x10;
  bl GKI_getbuf;
  cmpwi r3, 0;
  mr r31, r3;
  beq lbl_80137128;
  li r4, 0;
  li r5, 0x10;
  bl memset;
  li r3, 0x1700;
  li r0, 0xff;
  sth r3, 0(r31);
  mr r4, r28;
  addi r3, r31, 8;
  sth r0, 6(r31);
  stb r30, 0xe(r31);
  stb r29, 0xf(r31);
  bl bdcpy;
  mr r3, r31;
  bl bta_sys_sendmsg;
  b lbl_80137144;
lbl_80137128:
  lbz r0, -0x6610(r13);
  cmplwi r0, 1;
  blt lbl_80137144;
  lis r4, 0x8028;
  li r3, 0x500;
  addi r4, r4, 0x2f50;
  bl LogMsg_0;
lbl_80137144:
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

// Symbol: BTA_HhSendData
// PAL: 0x80137164..0x801371f4
MARK_BINARY_BLOB(BTA_HhSendData, 0x80137164, 0x801371f4);
asm UNKNOWN_FUNCTION(BTA_HhSendData) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  mr r30, r4;
  stw r29, 0x14(r1);
  mr r29, r3;
  li r3, 0x14;
  bl GKI_getbuf;
  cmpwi r3, 0;
  mr r31, r3;
  beq lbl_801371d8;
  li r4, 0;
  li r5, 0x14;
  bl memset;
  li r0, 0x1708;
  li r5, 0xa;
  sth r0, 0(r31);
  li r4, 0;
  li r0, 2;
  mr r3, r31;
  sth r29, 6(r31);
  stb r5, 8(r31);
  sth r4, 0xc(r31);
  stb r0, 9(r31);
  stw r30, 0x10(r31);
  stb r4, 0xa(r31);
  bl bta_sys_sendmsg;
lbl_801371d8:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: BTA_HhAddDev
// PAL: 0x801371f4..0x8013729c
MARK_BINARY_BLOB(BTA_HhAddDev, 0x801371f4, 0x8013729c);
asm UNKNOWN_FUNCTION(BTA_HhAddDev) {
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
  li r3, 0x1c;
  bl GKI_getbuf;
  cmpwi r3, 0;
  mr r31, r3;
  beq lbl_80137284;
  li r4, 0;
  li r5, 0x1c;
  bl memset;
  li r0, 0x170a;
  li r5, 0xb;
  sth r0, 0(r31);
  li r0, 0xff;
  mr r4, r30;
  addi r3, r31, 0x14;
  sth r5, 0x10(r31);
  li r5, 8;
  sth r0, 6(r31);
  sth r27, 0xe(r31);
  stb r28, 0x12(r31);
  stb r29, 0x13(r31);
  bl memcpy;
  mr r4, r26;
  addi r3, r31, 8;
  bl bdcpy;
  mr r3, r31;
  bl bta_sys_sendmsg;
lbl_80137284:
  addi r11, r1, 0x20;
  bl _restgpr_26;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: BTA_HhRemoveDev
// PAL: 0x8013729c..0x80137308
MARK_BINARY_BLOB(BTA_HhRemoveDev, 0x8013729c, 0x80137308);
asm UNKNOWN_FUNCTION(BTA_HhRemoveDev) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  stw r30, 8(r1);
  mr r30, r3;
  li r3, 0x1c;
  bl GKI_getbuf;
  cmpwi r3, 0;
  mr r31, r3;
  beq lbl_801372f0;
  li r4, 0;
  li r5, 0x1c;
  bl memset;
  li r3, 0x170a;
  li r0, 0xc;
  sth r3, 0(r31);
  mr r3, r31;
  sth r0, 0x10(r31);
  sth r30, 6(r31);
  bl bta_sys_sendmsg;
lbl_801372f0:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: BTA_HhGetAclQueueInfo
// PAL: 0x80137308..0x8013735c
MARK_BINARY_BLOB(BTA_HhGetAclQueueInfo, 0x80137308, 0x8013735c);
asm UNKNOWN_FUNCTION(BTA_HhGetAclQueueInfo) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  li r3, 8;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  bl GKI_getbuf;
  cmpwi r3, 0;
  mr r31, r3;
  beq lbl_80137348;
  li r4, 0;
  li r5, 8;
  bl memset;
  li r0, 0x170e;
  mr r3, r31;
  sth r0, 0(r31);
  bl bta_sys_sendmsg;
lbl_80137348:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

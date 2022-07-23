#include "bta_api.h"

#include <string.h>

#include "gki_buffer.h"
#include "gki_ppc.h"
#include "bd.h"
#include "bta_sys.h"

// Extern function references.
// PAL: 0x801399a0
extern UNKNOWN_FUNCTION(BTM_SecAddDevice);
// PAL: 0x80139b28
extern UNKNOWN_FUNCTION(BTM_SecDeleteDevice);
// PAL: 0x8013a300
extern UNKNOWN_FUNCTION(BTM_IsDeviceUp);

// Symbol: BTA_EnableBluetooth
// PAL: 0x8013485c..0x801348e4
MARK_BINARY_BLOB(BTA_EnableBluetooth, 0x8013485c, 0x801348e4);
asm UNKNOWN_FUNCTION(BTA_EnableBluetooth) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r4, 0x8033;
  li r5, 0x104;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  addi r3, r4, 0x5f14;
  li r4, 0;
  bl memset;
  bl GKI_sched_lock;
  li r3, 1;
  addi r4, r2, -26912;
  bl bta_sys_register;
  li r3, 2;
  addi r4, r2, -26904;
  bl bta_sys_register;
  bl GKI_sched_unlock;
  li r3, 0xc;
  bl GKI_getbuf;
  cmpwi r3, 0;
  beq lbl_801348cc;
  li r0, 0x100;
  sth r0, 0(r3);
  stw r31, 8(r3);
  bl bta_sys_sendmsg;
  li r3, 0;
  b lbl_801348d0;
lbl_801348cc:
  li r3, 1;
lbl_801348d0:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: BTA_DisableBluetooth
// PAL: 0x801348e4..0x8013491c
MARK_BINARY_BLOB(BTA_DisableBluetooth, 0x801348e4, 0x8013491c);
asm UNKNOWN_FUNCTION(BTA_DisableBluetooth) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  li r3, 8;
  stw r0, 0x14(r1);
  bl GKI_getbuf;
  cmpwi r3, 0;
  beq lbl_8013490c;
  li r0, 0x101;
  sth r0, 0(r3);
  bl bta_sys_sendmsg;
lbl_8013490c:
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: BTA_DmIsDeviceUp
// PAL: 0x8013491c..0x80134954
MARK_BINARY_BLOB(BTA_DmIsDeviceUp, 0x8013491c, 0x80134954);
asm UNKNOWN_FUNCTION(BTA_DmIsDeviceUp) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  bl GKI_sched_lock;
  bl BTM_IsDeviceUp;
  mr r31, r3;
  bl GKI_sched_unlock;
  mr r3, r31;
  lwz r31, 0xc(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: BTA_DmSetDeviceName
// PAL: 0x80134954..0x801349b8
MARK_BINARY_BLOB(BTA_DmSetDeviceName, 0x80134954, 0x801349b8);
asm UNKNOWN_FUNCTION(BTA_DmSetDeviceName) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  stw r30, 8(r1);
  mr r30, r3;
  li r3, 0x28;
  bl GKI_getbuf;
  cmpwi r3, 0;
  mr r31, r3;
  beq lbl_801349a0;
  li r0, 0x102;
  mr r4, r30;
  sth r0, 0(r3);
  li r5, 0x20;
  addi r3, r3, 8;
  bl strncpy;
  mr r3, r31;
  bl bta_sys_sendmsg;
lbl_801349a0:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: BTA_DmSetVisibility
// PAL: 0x801349b8..0x80134a10
MARK_BINARY_BLOB(BTA_DmSetVisibility, 0x801349b8, 0x80134a10);
asm UNKNOWN_FUNCTION(BTA_DmSetVisibility) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  li r3, 0x110;
  bl GKI_getbuf;
  cmpwi r3, 0;
  beq lbl_801349f8;
  li r0, 0x103;
  sth r0, 0(r3);
  stb r30, 8(r3);
  stb r31, 9(r3);
  bl bta_sys_sendmsg;
lbl_801349f8:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: BTA_DmSearch
// PAL: 0x80134a10..0x80134a94
MARK_BINARY_BLOB(BTA_DmSearch, 0x80134a10, 0x80134a94);
asm UNKNOWN_FUNCTION(BTA_DmSearch) {
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
  li r3, 0x1c;
  bl GKI_getbuf;
  cmpwi r3, 0;
  mr r31, r3;
  beq lbl_80134a74;
  li r0, 0x200;
  mr r4, r28;
  sth r0, 0(r3);
  li r5, 0xa;
  addi r3, r3, 8;
  bl memcpy;
  stw r29, 0x14(r31);
  mr r3, r31;
  stw r30, 0x18(r31);
  bl bta_sys_sendmsg;
lbl_80134a74:
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

// Symbol: BTA_DmSearchCancel
// PAL: 0x80134a94..0x80134acc
MARK_BINARY_BLOB(BTA_DmSearchCancel, 0x80134a94, 0x80134acc);
asm UNKNOWN_FUNCTION(BTA_DmSearchCancel) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  li r3, 8;
  stw r0, 0x14(r1);
  bl GKI_getbuf;
  cmpwi r3, 0;
  beq lbl_80134abc;
  li r0, 0x201;
  sth r0, 0(r3);
  bl bta_sys_sendmsg;
lbl_80134abc:
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: BTA_DmPinReply
// PAL: 0x80134acc..0x80134b58
MARK_BINARY_BLOB(BTA_DmPinReply, 0x80134acc, 0x80134b58);
asm UNKNOWN_FUNCTION(BTA_DmPinReply) {
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
  li r3, 0x20;
  bl GKI_getbuf;
  cmpwi r3, 0;
  mr r31, r3;
  beq lbl_80134b40;
  li r0, 0x107;
  mr r4, r27;
  sth r0, 0(r3);
  addi r3, r3, 8;
  bl bdcpy;
  cmpwi r28, 0;
  stb r28, 0xe(r31);
  beq lbl_80134b38;
  stb r29, 0xf(r31);
  mr r4, r30;
  mr r5, r29;
  addi r3, r31, 0x10;
  bl memcpy;
lbl_80134b38:
  mr r3, r31;
  bl bta_sys_sendmsg;
lbl_80134b40:
  addi r11, r1, 0x20;
  bl _restgpr_27;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: BTA_DmAddDevice
// PAL: 0x80134b58..0x80134c48
MARK_BINARY_BLOB(BTA_DmAddDevice, 0x80134b58, 0x80134c48);
asm UNKNOWN_FUNCTION(BTA_DmAddDevice) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_27;
  mr r28, r3;
  mr r29, r4;
  mr r30, r5;
  mr r27, r6;
  addi r3, r1, 8;
  li r31, 0;
  li r4, 0;
  li r5, 8;
  bl memset;
  cmpwi r27, 0;
  beq lbl_80134bfc;
  lis r7, 0x8025;
  addi r5, r1, 8;
  addi r7, r7, -14392;
  li r3, 1;
  b lbl_80134be8;
lbl_80134bac:
  clrlwi r0, r31, 0x18;
  slw r4, r3, r0;
  and. r0, r30, r4;
  beq lbl_80134be4;
  rlwinm r0, r31, 2, 0x16, 0x1d;
  andc r30, r30, r4;
  lwzx r4, r7, r0;
  rlwinm r0, r4, 0, 0x13, 0x1a;
  rlwinm r6, r4, 0x1d, 0x16, 0x1d;
  subf r0, r0, r4;
  lwzx r4, r5, r6;
  slw r0, r3, r0;
  or r0, r4, r0;
  stwx r0, r5, r6;
lbl_80134be4:
  addi r31, r31, 1;
lbl_80134be8:
  cmpwi r30, 0;
  beq lbl_80134bfc;
  clrlwi r0, r31, 0x18;
  cmplwi r0, 0x17;
  blt lbl_80134bac;
lbl_80134bfc:
  bl GKI_sched_lock;
  mr r3, r28;
  mr r8, r29;
  addi r7, r1, 8;
  li r4, 0;
  li r5, 0;
  li r6, 0;
  bl BTM_SecAddDevice;
  mr r28, r3;
  bl GKI_sched_unlock;
  clrlwi r0, r28, 0x18;
  addi r11, r1, 0x30;
  cntlzw r0, r0;
  rlwinm r3, r0, 0x1b, 0x18, 0x1f;
  bl _restgpr_27;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: BTA_DmRemoveDevice
// PAL: 0x80134c48..0x80134c90
MARK_BINARY_BLOB(BTA_DmRemoveDevice, 0x80134c48, 0x80134c90);
asm UNKNOWN_FUNCTION(BTA_DmRemoveDevice) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  bl GKI_sched_lock;
  mr r3, r31;
  bl BTM_SecDeleteDevice;
  mr r31, r3;
  bl GKI_sched_unlock;
  clrlwi r0, r31, 0x18;
  lwz r31, 0xc(r1);
  cntlzw r0, r0;
  rlwinm r3, r0, 0x1b, 0x18, 0x1f;
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: BTA_DmSendHciReset
// PAL: 0x80134c90..0x80134cc8
MARK_BINARY_BLOB(BTA_DmSendHciReset, 0x80134c90, 0x80134cc8);
asm UNKNOWN_FUNCTION(BTA_DmSendHciReset) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  li r3, 8;
  stw r0, 0x14(r1);
  bl GKI_getbuf;
  cmpwi r3, 0;
  beq lbl_80134cb8;
  li r0, 0x10c;
  sth r0, 0(r3);
  bl bta_sys_sendmsg;
lbl_80134cb8:
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

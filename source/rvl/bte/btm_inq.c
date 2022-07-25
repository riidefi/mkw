#include "btm_inq.h"

#include <string.h>

#include "gki_buffer.h"
#include "gki_time.h"
#include "bte_task1.h"
#include "bte_logmsg.h"
#include "btm_devctl.h"
#include "btm_sec.h"
#include "hcicmds.h"

// Symbol: BTM_SetDiscoverability
// PAL: 0x8013bb28..0x8013bdac
MARK_BINARY_BLOB(BTM_SetDiscoverability, 0x8013bb28, 0x8013bdac);
asm UNKNOWN_FUNCTION(BTM_SetDiscoverability) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_27;
  cmpwi r3, 0;
  mr r31, r3;
  mr r27, r4;
  mr r28, r5;
  li r30, 0;
  beq lbl_8013bb6c;
  cmplwi r3, 1;
  beq lbl_8013bb6c;
  cmplwi r3, 2;
  beq lbl_8013bb6c;
  li r3, 5;
  b lbl_8013bd94;
lbl_8013bb6c:
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lbz r0, 0x64e(r3);
  cmplwi r0, 3;
  bge lbl_8013bb88;
  li r3, 0xc;
  b lbl_8013bd94;
lbl_8013bb88:
  cmpwi r4, 0;
  bne lbl_8013bb94;
  li r27, 0x12;
lbl_8013bb94:
  cmpwi r5, 0;
  bne lbl_8013bba0;
  li r28, 0x800;
lbl_8013bba0:
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lbz r0, 0x27c0(r3);
  cmplwi r0, 3;
  blt lbl_8013bbd4;
  lis r3, 0xd;
  lis r4, 0x8028;
  mr r5, r31;
  mr r6, r27;
  mr r7, r28;
  addi r3, r3, 2;
  addi r4, r4, 0x3ba0;
  bl LogMsg_3;
lbl_8013bbd4:
  cmpwi r31, 0;
  beq lbl_8013bc0c;
  cmplwi r27, 0x12;
  blt lbl_8013bc04;
  cmplwi r27, 0x1000;
  bgt lbl_8013bc04;
  cmplwi r28, 0x12;
  blt lbl_8013bc04;
  cmplwi r28, 0x1000;
  bgt lbl_8013bc04;
  cmplw r27, r28;
  ble lbl_8013bc0c;
lbl_8013bc04:
  li r3, 5;
  b lbl_8013bd94;
lbl_8013bc0c:
  cmpwi r31, 0;
  beq lbl_8013bc80;
  li r3, 2;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  mr r29, r3;
  beq lbl_8013bc78;
  clrlwi. r0, r31, 0x1f;
  beq lbl_8013bc64;
  addi r3, r1, 0xc;
  addi r4, r2, -26884;
  li r5, 3;
  bl memcpy;
  addi r3, r1, 0xf;
  addi r4, r2, -26888;
  li r5, 3;
  bl memcpy;
  mr r3, r29;
  addi r5, r1, 0xc;
  li r4, 2;
  bl btsnd_hcic_write_cur_iac_lap;
  b lbl_8013bc70;
lbl_8013bc64:
  li r4, 1;
  addi r5, r2, -26888;
  bl btsnd_hcic_write_cur_iac_lap;
lbl_8013bc70:
  ori r30, r30, 1;
  b lbl_8013bc80;
lbl_8013bc78:
  li r3, 3;
  b lbl_8013bd94;
lbl_8013bc80:
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lhz r0, 0x16a0(r3);
  cmplw r27, r0;
  bne lbl_8013bca0;
  lhz r0, 0x16a2(r3);
  cmplw r28, r0;
  beq lbl_8013bcd8;
lbl_8013bca0:
  li r3, 2;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  beq lbl_8013bcd0;
  lis r6, 0x8033;
  mr r4, r28;
  addi r6, r6, 0x6278;
  mr r5, r27;
  sth r27, 0x16a0(r6);
  sth r28, 0x16a2(r6);
  bl btsnd_hcic_write_inqscan_cfg;
  b lbl_8013bcd8;
lbl_8013bcd0:
  li r3, 3;
  b lbl_8013bd94;
lbl_8013bcd8:
  li r3, 2;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  beq lbl_8013bd1c;
  lis r4, 0x8033;
  addi r4, r4, 0x6278;
  lhz r0, 0x169a(r4);
  cmpwi r0, 0;
  beq lbl_8013bd04;
  ori r0, r30, 2;
  clrlwi r30, r0, 0x18;
lbl_8013bd04:
  lis r5, 0x8033;
  clrlwi r4, r30, 0x18;
  addi r5, r5, 0x6278;
  sth r31, 0x1698(r5);
  bl btsnd_hcic_write_scan_enable;
  b lbl_8013bd24;
lbl_8013bd1c:
  li r3, 3;
  b lbl_8013bd94;
lbl_8013bd24:
  bl BTM_ReadDeviceClass;
  lbz r4, 0(r3);
  clrlwi r6, r31, 0x1f;
  lbz r5, 1(r3);
  rlwinm r4, r4, 8, 0x10, 0x17;
  rlwinm r0, r5, 0, 0x18, 0x1a;
  add r4, r4, r0;
  rlwinm r0, r4, 0x1b, 0x1f, 0x1f;
  xor. r0, r6, r0;
  clrlwi r4, r4, 0x10;
  beq lbl_8013bd90;
  lbz r3, 2(r3);
  cmpwi r6, 0;
  rlwinm r0, r4, 0, 0x1b, 0x19;
  clrlwi r5, r5, 0x1b;
  rlwinm r6, r3, 0, 0x18, 0x1d;
  clrlwi r0, r0, 0x10;
  beq lbl_8013bd70;
  ori r0, r4, 0x20;
lbl_8013bd70:
  rlwinm r3, r0, 0, 0x18, 0x1a;
  rlwinm r0, r0, 0x18, 0x18, 0x1f;
  add r4, r5, r3;
  stb r6, 0xa(r1);
  addi r3, r1, 8;
  stb r4, 9(r1);
  stb r0, 8(r1);
  bl BTM_SetDeviceClass;
lbl_8013bd90:
  li r3, 0;
lbl_8013bd94:
  addi r11, r1, 0x30;
  bl _restgpr_27;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: BTM_SetInquiryScanType
// PAL: 0x8013bdac..0x8013be5c
MARK_BINARY_BLOB(BTM_SetInquiryScanType, 0x8013bdac, 0x8013be5c);
asm UNKNOWN_FUNCTION(BTM_SetInquiryScanType) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmpwi r3, 0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  stw r30, 8(r1);
  mr r30, r3;
  beq lbl_8013bddc;
  cmplwi r3, 1;
  beq lbl_8013bddc;
  li r3, 5;
  b lbl_8013be44;
lbl_8013bddc:
  lis r31, 0x8033;
  addi r31, r31, 0x6278;
  lbz r0, 0x643(r31);
  rlwinm. r0, r0, 0, 0x1b, 0x1b;
  bne lbl_8013bdf8;
  li r3, 4;
  b lbl_8013be44;
lbl_8013bdf8:
  lhz r0, 0x16a4(r31);
  cmplw r3, r0;
  beq lbl_8013be40;
  bl BTM_IsDeviceUp;
  clrlwi. r0, r3, 0x18;
  beq lbl_8013be38;
  li r3, 2;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  beq lbl_8013be30;
  clrlwi r4, r30, 0x18;
  bl btsnd_hcic_write_inqscan_type;
  sth r30, 0x16a4(r31);
  b lbl_8013be40;
lbl_8013be30:
  li r3, 3;
  b lbl_8013be44;
lbl_8013be38:
  li r3, 6;
  b lbl_8013be44;
lbl_8013be40:
  li r3, 0;
lbl_8013be44:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: BTM_SetPageScanType
// PAL: 0x8013be5c..0x8013bf0c
MARK_BINARY_BLOB(BTM_SetPageScanType, 0x8013be5c, 0x8013bf0c);
asm UNKNOWN_FUNCTION(BTM_SetPageScanType) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmpwi r3, 0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  stw r30, 8(r1);
  mr r30, r3;
  beq lbl_8013be8c;
  cmplwi r3, 1;
  beq lbl_8013be8c;
  li r3, 5;
  b lbl_8013bef4;
lbl_8013be8c:
  lis r31, 0x8033;
  addi r31, r31, 0x6278;
  lbz r0, 0x643(r31);
  rlwinm. r0, r0, 0, 0x1a, 0x1a;
  bne lbl_8013bea8;
  li r3, 4;
  b lbl_8013bef4;
lbl_8013bea8:
  lhz r0, 0x16a6(r31);
  cmplw r3, r0;
  beq lbl_8013bef0;
  bl BTM_IsDeviceUp;
  clrlwi. r0, r3, 0x18;
  beq lbl_8013bee8;
  li r3, 2;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  beq lbl_8013bee0;
  clrlwi r4, r30, 0x18;
  bl btsnd_hcic_write_pagescan_type;
  sth r30, 0x16a6(r31);
  b lbl_8013bef0;
lbl_8013bee0:
  li r3, 3;
  b lbl_8013bef4;
lbl_8013bee8:
  li r3, 6;
  b lbl_8013bef4;
lbl_8013bef0:
  li r3, 0;
lbl_8013bef4:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: BTM_SetInquiryMode
// PAL: 0x8013bf0c..0x8013bfa4
MARK_BINARY_BLOB(BTM_SetInquiryMode, 0x8013bf0c, 0x8013bfa4);
asm UNKNOWN_FUNCTION(BTM_SetInquiryMode) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmpwi r3, 0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  beq lbl_8013bf38;
  cmplwi r3, 1;
  beq lbl_8013bf38;
  li r3, 5;
  b lbl_8013bf90;
lbl_8013bf38:
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lbz r0, 0x643(r3);
  rlwinm. r0, r0, 0, 0x19, 0x19;
  bne lbl_8013bf54;
  li r3, 4;
  b lbl_8013bf90;
lbl_8013bf54:
  bl BTM_IsDeviceUp;
  clrlwi. r0, r3, 0x18;
  bne lbl_8013bf68;
  li r3, 6;
  b lbl_8013bf90;
lbl_8013bf68:
  li r3, 2;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  beq lbl_8013bf84;
  mr r4, r31;
  bl btsnd_hcic_write_inquiry_mode;
  b lbl_8013bf8c;
lbl_8013bf84:
  li r3, 3;
  b lbl_8013bf90;
lbl_8013bf8c:
  li r3, 0;
lbl_8013bf90:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: BTM_SetConnectability
// PAL: 0x8013bfa4..0x8013c12c
MARK_BINARY_BLOB(BTM_SetConnectability, 0x8013bfa4, 0x8013c12c);
asm UNKNOWN_FUNCTION(BTM_SetConnectability) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_27;
  cmpwi r3, 0;
  lis r31, 0x8033;
  mr r27, r3;
  mr r28, r4;
  mr r29, r5;
  addi r31, r31, 0x6278;
  li r30, 0;
  beq lbl_8013bfe8;
  cmplwi r3, 1;
  beq lbl_8013bfe8;
  li r3, 5;
  b lbl_8013c114;
lbl_8013bfe8:
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lbz r0, 0x64e(r3);
  cmplwi r0, 3;
  bge lbl_8013c004;
  li r3, 0xc;
  b lbl_8013c114;
lbl_8013c004:
  cmpwi r4, 0;
  bne lbl_8013c010;
  li r28, 0x12;
lbl_8013c010:
  cmpwi r5, 0;
  bne lbl_8013c01c;
  li r29, 0x800;
lbl_8013c01c:
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lbz r0, 0x27c0(r3);
  cmplwi r0, 3;
  blt lbl_8013c050;
  lis r3, 0xd;
  lis r4, 0x8028;
  mr r5, r27;
  mr r6, r28;
  mr r7, r29;
  addi r3, r3, 2;
  addi r4, r4, 0x3bfc;
  bl LogMsg_3;
lbl_8013c050:
  cmplwi r27, 1;
  bne lbl_8013c08c;
  cmplwi r28, 0x12;
  blt lbl_8013c080;
  cmplwi r28, 0x1000;
  bgt lbl_8013c080;
  cmplwi r29, 0x12;
  blt lbl_8013c080;
  cmplwi r29, 0x1000;
  bgt lbl_8013c080;
  cmplw r28, r29;
  ble lbl_8013c088;
lbl_8013c080:
  li r3, 5;
  b lbl_8013c114;
lbl_8013c088:
  ori r30, r30, 2;
lbl_8013c08c:
  lhz r0, 0x169c(r31);
  cmplw r28, r0;
  bne lbl_8013c0a4;
  lhz r0, 0x169e(r31);
  cmplw r29, r0;
  beq lbl_8013c0d4;
lbl_8013c0a4:
  li r3, 2;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  beq lbl_8013c0cc;
  sth r28, 0x169c(r31);
  mr r4, r29;
  mr r5, r28;
  sth r29, 0x169e(r31);
  bl btsnd_hcic_write_pagescan_cfg;
  b lbl_8013c0d4;
lbl_8013c0cc:
  li r3, 3;
  b lbl_8013c114;
lbl_8013c0d4:
  li r3, 2;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  beq lbl_8013c108;
  lhz r0, 0x1698(r31);
  cmpwi r0, 0;
  beq lbl_8013c0f8;
  ori r0, r30, 1;
  clrlwi r30, r0, 0x18;
lbl_8013c0f8:
  sth r27, 0x169a(r31);
  clrlwi r4, r30, 0x18;
  bl btsnd_hcic_write_scan_enable;
  b lbl_8013c110;
lbl_8013c108:
  li r3, 3;
  b lbl_8013c114;
lbl_8013c110:
  li r3, 0;
lbl_8013c114:
  addi r11, r1, 0x20;
  bl _restgpr_27;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: BTM_IsInquiryActive
// PAL: 0x8013c12c..0x8013c13c
MARK_BINARY_BLOB(BTM_IsInquiryActive, 0x8013c12c, 0x8013c13c);
asm UNKNOWN_FUNCTION(BTM_IsInquiryActive) {
  // clang-format off
  nofralloc;
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lbz r3, 0x1848(r3);
  blr;
  // clang-format on
}

// Symbol: BTM_CancelInquiry
// PAL: 0x8013c13c..0x8013c244
MARK_BINARY_BLOB(BTM_CancelInquiry, 0x8013c13c, 0x8013c244);
asm UNKNOWN_FUNCTION(BTM_CancelInquiry) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  lis r30, 0x8033;
  addi r30, r30, 0x6278;
  stw r29, 0x14(r1);
  li r29, 0;
  lbz r0, 0x27c0(r30);
  cmplwi r0, 3;
  blt lbl_8013c180;
  lis r3, 0xd;
  lis r4, 0x8028;
  addi r3, r3, 2;
  addi r4, r4, 0x3c50;
  bl LogMsg_0;
lbl_8013c180:
  bl BTM_IsDeviceUp;
  clrlwi. r0, r3, 0x18;
  bne lbl_8013c194;
  li r3, 6;
  b lbl_8013c228;
lbl_8013c194:
  lbz r0, 0x1848(r30);
  cmpwi r0, 0;
  beq lbl_8013c224;
  rlwinm. r0, r0, 0, 0x1d, 0x1d;
  bne lbl_8013c224;
  lbz r0, 0x1844(r30);
  li r4, 0;
  stb r4, 0x1848(r30);
  cmpwi r0, 0;
  stb r4, 0x1847(r30);
  stw r4, 0x16b4(r30);
  stw r4, 0x16b0(r30);
  beq lbl_8013c1dc;
  lbz r3, 0x1845(r30);
  stb r4, 0x1844(r30);
  addi r0, r3, 1;
  stb r0, 0x1845(r30);
  b lbl_8013c1ec;
lbl_8013c1dc:
  bl btsnd_hcic_inq_cancel;
  clrlwi. r0, r3, 0x18;
  bne lbl_8013c1ec;
  li r29, 3;
lbl_8013c1ec:
  lis r31, 0x8033;
  lwz r4, 0x16c0(r30);
  addi r31, r31, 0x6278;
  lwz r3, 0x16dc(r31);
  addi r0, r4, 1;
  stw r0, 0x16c0(r30);
  cmpwi r3, 0;
  beq lbl_8013c218;
  bl GKI_freebuf;
  li r0, 0;
  stw r0, 0x16dc(r31);
lbl_8013c218:
  li r0, 0;
  sth r0, 0x16e0(r31);
  sth r0, 0x16e2(r31);
lbl_8013c224:
  mr r3, r29;
lbl_8013c228:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: BTM_StartInquiry
// PAL: 0x8013c244..0x8013c3f8
MARK_BINARY_BLOB(BTM_StartInquiry, 0x8013c244, 0x8013c3f8);
asm UNKNOWN_FUNCTION(BTM_StartInquiry) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  lis r31, 0x8033;
  addi r31, r31, 0x6278;
  stw r30, 0x18(r1);
  mr r30, r5;
  stw r29, 0x14(r1);
  mr r29, r4;
  stw r28, 0x10(r1);
  mr r28, r3;
  lbz r0, 0x27c0(r31);
  cmplwi r0, 3;
  blt lbl_8013c2a4;
  lis r3, 0xd;
  lis r4, 0x8028;
  lbz r5, 0(r28);
  addi r3, r3, 2;
  lbz r6, 1(r28);
  addi r4, r4, 0x3c6c;
  lbz r7, 2(r28);
  lbz r8, 3(r28);
  bl LogMsg_4;
lbl_8013c2a4:
  lbz r0, 0x1848(r31);
  cmpwi r0, 0;
  bne lbl_8013c2bc;
  lbz r0, 0x1844(r31);
  cmpwi r0, 0;
  beq lbl_8013c2c4;
lbl_8013c2bc:
  li r3, 2;
  b lbl_8013c3d8;
lbl_8013c2c4:
  lbz r0, 0(r28);
  cmpwi r0, 0;
  beq lbl_8013c2e0;
  cmplwi r0, 1;
  beq lbl_8013c2e0;
  li r3, 5;
  b lbl_8013c3d8;
lbl_8013c2e0:
  bl BTM_IsDeviceUp;
  clrlwi. r0, r3, 0x18;
  bne lbl_8013c2f4;
  li r3, 6;
  b lbl_8013c3d8;
lbl_8013c2f4:
  lbz r5, 0(r28);
  li r0, 3;
  lbz r3, 1(r28);
  li r6, 0;
  li r4, 1;
  stb r5, 0x1834(r31);
  stb r3, 0x1835(r31);
  lbz r5, 2(r28);
  lbz r3, 3(r28);
  stb r5, 0x1836(r31);
  stb r3, 0x1837(r31);
  lbz r5, 4(r28);
  lbz r3, 5(r28);
  stb r5, 0x1838(r31);
  stb r3, 0x1839(r31);
  lbz r5, 6(r28);
  lbz r3, 7(r28);
  stb r5, 0x183a(r31);
  stb r3, 0x183b(r31);
  lbz r3, 8(r28);
  stb r3, 0x183c(r31);
  lbz r3, 9(r28);
  stb r3, 0x183d(r31);
  stb r0, 0x1847(r31);
  stw r30, 0x16b0(r31);
  stw r29, 0x16b4(r31);
  stb r6, 0x183f(r31);
  lbz r5, 0(r28);
  addi r3, r5, -1;
  subfic r0, r5, 1;
  nor r0, r3, r0;
  srawi r3, r0, 0x1f;
  addi r0, r3, 2;
  stb r0, 0x1848(r31);
  lbz r0, 3(r28);
  cmpwi r0, 0;
  beq lbl_8013c398;
  blt lbl_8013c3b0;
  cmpwi r0, 3;
  bge lbl_8013c3b0;
  b lbl_8013c3a4;
lbl_8013c398:
  li r0, 2;
  stb r0, 0x1847(r31);
  b lbl_8013c3b8;
lbl_8013c3a4:
  stb r4, 0x1847(r31);
  stb r6, 3(r28);
  b lbl_8013c3b8;
lbl_8013c3b0:
  li r3, 5;
  b lbl_8013c3d8;
lbl_8013c3b8:
  lbz r3, 3(r28);
  addi r4, r28, 4;
  bl btm_set_inq_event_filter;
  clrlwi r0, r3, 0x18;
  cmplwi r0, 1;
  beq lbl_8013c3d8;
  li r0, 0;
  stb r0, 0x1847(r31);
lbl_8013c3d8:
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

// Symbol: BTM_ReadRemoteDeviceName
// PAL: 0x8013c3f8..0x8013c4e0
MARK_BINARY_BLOB(BTM_ReadRemoteDeviceName, 0x8013c3f8, 0x8013c4e0);
asm UNKNOWN_FUNCTION(BTM_ReadRemoteDeviceName) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_27;
  lis r5, 0x8033;
  mr r27, r3;
  addi r5, r5, 0x6278;
  mr r28, r4;
  lbz r0, 0x27c0(r5);
  li r29, 0;
  cmplwi r0, 3;
  blt lbl_8013c458;
  lis r3, 0xd;
  lis r4, 0x8028;
  lbz r5, 0(r27);
  addi r3, r3, 2;
  lbz r6, 1(r27);
  addi r4, r4, 0x3ca4;
  lbz r7, 2(r27);
  lbz r8, 3(r27);
  lbz r9, 4(r27);
  lbz r10, 5(r27);
  bl LogMsg_6;
lbl_8013c458:
  lis r3, 0x8033;
  li r30, 0;
  addi r3, r3, 0x6278;
  addi r31, r3, 0x16e4;
lbl_8013c468:
  lbz r0, 0x1a(r31);
  cmpwi r0, 0;
  beq lbl_8013c490;
  mr r4, r27;
  addi r3, r31, 0xa;
  li r5, 6;
  bl memcmp;
  cmpwi r3, 0;
  bne lbl_8013c490;
  b lbl_8013c4a4;
lbl_8013c490:
  addi r30, r30, 1;
  addi r31, r31, 0x1c;
  cmplwi r30, 0xc;
  blt lbl_8013c468;
  li r31, 0;
lbl_8013c4a4:
  cmpwi r31, 0;
  beq lbl_8013c4b0;
  addi r29, r31, 8;
lbl_8013c4b0:
  mr r3, r27;
  mr r4, r29;
  mr r7, r28;
  li r5, 1;
  li r6, 0x28;
  bl btm_initiate_rem_name;
  addi r11, r1, 0x20;
  bl _restgpr_27;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: BTM_CancelRemoteDeviceName
// PAL: 0x8013c4e0..0x8013c558
MARK_BINARY_BLOB(BTM_CancelRemoteDeviceName, 0x8013c4e0, 0x8013c558);
asm UNKNOWN_FUNCTION(BTM_CancelRemoteDeviceName) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  lis r31, 0x8033;
  addi r31, r31, 0x6278;
  lbz r0, 0x27c0(r31);
  cmplwi r0, 3;
  blt lbl_8013c518;
  lis r3, 0xd;
  lis r4, 0x8028;
  addi r3, r3, 2;
  addi r4, r4, 0x3ce4;
  bl LogMsg_0;
lbl_8013c518:
  lbz r0, 0x16ae(r31);
  clrlwi. r0, r0, 0x1f;
  beq lbl_8013c540;
  addi r3, r31, 0x16a8;
  bl btsnd_hcic_rmt_name_req_cancel;
  clrlwi. r0, r3, 0x18;
  li r3, 3;
  beq lbl_8013c544;
  li r3, 1;
  b lbl_8013c544;
lbl_8013c540:
  li r3, 6;
lbl_8013c544:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: BTM_InqDbRead
// PAL: 0x8013c558..0x8013c618
MARK_BINARY_BLOB(BTM_InqDbRead, 0x8013c558, 0x8013c618);
asm UNKNOWN_FUNCTION(BTM_InqDbRead) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  lis r4, 0x8033;
  stw r0, 0x24(r1);
  addi r4, r4, 0x6278;
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  addi r30, r4, 0x16e4;
  stw r29, 0x14(r1);
  mr r29, r3;
  lbz r0, 0x27c0(r4);
  cmplwi r0, 3;
  blt lbl_8013c5b8;
  lis r3, 0xd;
  lis r4, 0x8028;
  lbz r5, 0(r29);
  addi r3, r3, 2;
  lbz r6, 1(r29);
  addi r4, r4, 0x3d04;
  lbz r7, 2(r29);
  lbz r8, 3(r29);
  lbz r9, 4(r29);
  lbz r10, 5(r29);
  bl LogMsg_6;
lbl_8013c5b8:
  li r31, 0;
lbl_8013c5bc:
  lbz r0, 0x1a(r30);
  cmpwi r0, 0;
  beq lbl_8013c5e8;
  mr r4, r29;
  addi r3, r30, 0xa;
  li r5, 6;
  bl memcmp;
  cmpwi r3, 0;
  bne lbl_8013c5e8;
  addi r3, r30, 8;
  b lbl_8013c5fc;
lbl_8013c5e8:
  addi r31, r31, 1;
  addi r30, r30, 0x1c;
  cmplwi r31, 0xc;
  blt lbl_8013c5bc;
  li r3, 0;
lbl_8013c5fc:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: BTM_InqDbFirst
// PAL: 0x8013c618..0x8013c6d0
MARK_BINARY_BLOB(BTM_InqDbFirst, 0x8013c618, 0x8013c6d0);
asm UNKNOWN_FUNCTION(BTM_InqDbFirst) {
  // clang-format off
  nofralloc;
  lis r3, 0x8033;
  li r0, 2;
  addi r3, r3, 0x6278;
  li r4, 0;
  addi r3, r3, 0x16e4;
  mtctr r0;
lbl_8013c630:
  lbz r0, 0x1a(r3);
  cmpwi r0, 0;
  beq lbl_8013c644;
  addi r3, r3, 8;
  blr;
lbl_8013c644:
  lbz r0, 0x36(r3);
  addi r4, r4, 1;
  cmpwi r0, 0;
  beq lbl_8013c65c;
  addi r3, r3, 0x24;
  blr;
lbl_8013c65c:
  lbz r0, 0x52(r3);
  addi r4, r4, 1;
  cmpwi r0, 0;
  beq lbl_8013c674;
  addi r3, r3, 0x40;
  blr;
lbl_8013c674:
  lbz r0, 0x6e(r3);
  addi r4, r4, 1;
  cmpwi r0, 0;
  beq lbl_8013c68c;
  addi r3, r3, 0x5c;
  blr;
lbl_8013c68c:
  lbz r0, 0x8a(r3);
  addi r4, r4, 1;
  cmpwi r0, 0;
  beq lbl_8013c6a4;
  addi r3, r3, 0x78;
  blr;
lbl_8013c6a4:
  lbz r0, 0xa6(r3);
  addi r4, r4, 1;
  cmpwi r0, 0;
  beq lbl_8013c6bc;
  addi r3, r3, 0x94;
  blr;
lbl_8013c6bc:
  addi r4, r4, 1;
  addi r3, r3, 0xa8;
  bdnz lbl_8013c630;
  li r3, 0;
  blr;
  // clang-format on
}

// Symbol: BTM_InqDbNext
// PAL: 0x8013c6d0..0x8013c80c
MARK_BINARY_BLOB(BTM_InqDbNext, 0x8013c6d0, 0x8013c80c);
asm UNKNOWN_FUNCTION(BTM_InqDbNext) {
  // clang-format off
  nofralloc;
  cmpwi r3, 0;
  beq lbl_8013c754;
  lis r5, 0x8033;
  lis r4, 0x9249;
  addi r5, r5, 0x6278;
  addi r0, r3, -8;
  addi r3, r5, 0x16e4;
  addi r4, r4, 0x2493;
  subf r0, r3, r0;
  mulhw r3, r4, r0;
  add r0, r3, r0;
  srawi r0, r0, 4;
  srwi r3, r0, 0x1f;
  add r3, r0, r3;
  addi r0, r3, 1;
  clrlwi r4, r0, 0x10;
  mulli r3, r4, 0x1c;
  subfic r0, r4, 0xc;
  add r3, r5, r3;
  addi r3, r3, 0x16e4;
  mtctr r0;
  cmplwi r4, 0xc;
  bge lbl_8013c74c;
lbl_8013c72c:
  lbz r0, 0x1a(r3);
  cmpwi r0, 0;
  beq lbl_8013c740;
  addi r3, r3, 8;
  blr;
lbl_8013c740:
  addi r4, r4, 1;
  addi r3, r3, 0x1c;
  bdnz lbl_8013c72c;
lbl_8013c74c:
  li r3, 0;
  blr;
lbl_8013c754:
  lis r3, 0x8033;
  li r0, 2;
  addi r3, r3, 0x6278;
  li r4, 0;
  addi r3, r3, 0x16e4;
  mtctr r0;
lbl_8013c76c:
  lbz r0, 0x1a(r3);
  cmpwi r0, 0;
  beq lbl_8013c780;
  addi r3, r3, 8;
  blr;
lbl_8013c780:
  lbz r0, 0x36(r3);
  addi r4, r4, 1;
  cmpwi r0, 0;
  beq lbl_8013c798;
  addi r3, r3, 0x24;
  blr;
lbl_8013c798:
  lbz r0, 0x52(r3);
  addi r4, r4, 1;
  cmpwi r0, 0;
  beq lbl_8013c7b0;
  addi r3, r3, 0x40;
  blr;
lbl_8013c7b0:
  lbz r0, 0x6e(r3);
  addi r4, r4, 1;
  cmpwi r0, 0;
  beq lbl_8013c7c8;
  addi r3, r3, 0x5c;
  blr;
lbl_8013c7c8:
  lbz r0, 0x8a(r3);
  addi r4, r4, 1;
  cmpwi r0, 0;
  beq lbl_8013c7e0;
  addi r3, r3, 0x78;
  blr;
lbl_8013c7e0:
  lbz r0, 0xa6(r3);
  addi r4, r4, 1;
  cmpwi r0, 0;
  beq lbl_8013c7f8;
  addi r3, r3, 0x94;
  blr;
lbl_8013c7f8:
  addi r4, r4, 1;
  addi r3, r3, 0xa8;
  bdnz lbl_8013c76c;
  li r3, 0;
  blr;
  // clang-format on
}

// Symbol: BTM_ClearInqDb
// PAL: 0x8013c80c..0x8013c8dc
MARK_BINARY_BLOB(BTM_ClearInqDb, 0x8013c80c, 0x8013c8dc);
asm UNKNOWN_FUNCTION(BTM_ClearInqDb) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_27;
  lis r4, 0x8033;
  mr r27, r3;
  addi r30, r4, 0x6278;
  lbz r0, 0x1848(r30);
  cmpwi r0, 0;
  bne lbl_8013c850;
  lbz r0, 0x16ae(r30);
  cmpwi r0, 0;
  bne lbl_8013c850;
  lbz r0, 0x1844(r30);
  cmpwi r0, 0;
  beq lbl_8013c858;
lbl_8013c850:
  li r3, 2;
  b lbl_8013c8c4;
lbl_8013c858:
  addi r28, r30, 0x16e4;
  li r29, 0;
  li r31, 0;
lbl_8013c864:
  lbz r0, 0x1a(r28);
  cmpwi r0, 0;
  beq lbl_8013c8b0;
  cmpwi r27, 0;
  beq lbl_8013c890;
  mr r4, r27;
  addi r3, r28, 0xa;
  li r5, 6;
  bl memcmp;
  cmpwi r3, 0;
  bne lbl_8013c8b0;
lbl_8013c890:
  stb r31, 0x1a(r28);
  lwz r12, 0x16bc(r30);
  cmpwi r12, 0;
  beq lbl_8013c8b0;
  addi r3, r28, 8;
  li r4, 0;
  mtctr r12;
  bctrl;
lbl_8013c8b0:
  addi r29, r29, 1;
  addi r28, r28, 0x1c;
  cmplwi r29, 0xc;
  blt lbl_8013c864;
  li r3, 0;
lbl_8013c8c4:
  addi r11, r1, 0x20;
  bl _restgpr_27;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: btm_inq_db_reset
// PAL: 0x8013c8dc..0x8013ca74
MARK_BINARY_BLOB(btm_inq_db_reset, 0x8013c8dc, 0x8013ca74);
asm UNKNOWN_FUNCTION(btm_inq_db_reset) {
  // clang-format off
  nofralloc;
  stwu r1, -0x120(r1);
  mflr r0;
  stw r0, 0x124(r1);
  addi r11, r1, 0x120;
  bl _savegpr_27;
  lis r29, 0x8033;
  addi r29, r29, 0x6278;
  addi r3, r29, 0x16c4;
  bl btu_stop_timer;
  lbz r3, 0x1848(r29);
  cmpwi r3, 0;
  beq lbl_8013c940;
  addi r0, r3, 0xff;
  li r3, 0;
  clrlwi r0, r0, 0x18;
  stb r3, 0x1848(r29);
  cmplwi r0, 1;
  bgt lbl_8013c940;
  lwz r12, 0x16b0(r29);
  cmpwi r12, 0;
  beq lbl_8013c940;
  stb r3, 9(r1);
  addi r3, r1, 9;
  mtctr r12;
  bctrl;
lbl_8013c940:
  lbz r0, 0x16ae(r29);
  clrlwi. r0, r0, 0x1f;
  beq lbl_8013c990;
  addi r3, r29, 0x1680;
  bl btu_stop_timer;
  li r30, 0;
  addi r3, r29, 0x16a8;
  stb r30, 0x16ae(r29);
  li r4, 0;
  li r5, 6;
  bl memset;
  lwz r12, 0x167c(r29);
  cmpwi r12, 0;
  beq lbl_8013c990;
  li r0, 0xc;
  addi r3, r1, 0xc;
  sth r0, 0xc(r1);
  mtctr r12;
  bctrl;
  stw r30, 0x167c(r29);
lbl_8013c990:
  lbz r0, 0x1844(r29);
  cmpwi r0, 0;
  beq lbl_8013c9c4;
  lwz r12, 0x16b8(r29);
  li r0, 0;
  stb r0, 0x1844(r29);
  cmpwi r12, 0;
  beq lbl_8013c9c4;
  li r0, 0xc;
  addi r3, r1, 8;
  stb r0, 8(r1);
  mtctr r12;
  bctrl;
lbl_8013c9c4:
  li r30, 0;
  lis r31, 0x8033;
  addi r31, r31, 0x6278;
  stb r30, 0x1847(r29);
  li r28, 0;
  stb r30, 0x1845(r29);
  addi r27, r31, 0x16e4;
  stw r30, 0x16b4(r29);
lbl_8013c9e4:
  lbz r0, 0x1a(r27);
  cmpwi r0, 0;
  beq lbl_8013ca10;
  stb r30, 0x1a(r27);
  lwz r12, 0x16bc(r31);
  cmpwi r12, 0;
  beq lbl_8013ca10;
  addi r3, r27, 8;
  li r4, 0;
  mtctr r12;
  bctrl;
lbl_8013ca10:
  addi r28, r28, 1;
  addi r27, r27, 0x1c;
  cmplwi r28, 0xc;
  blt lbl_8013c9e4;
  lis r31, 0x8033;
  addi r31, r31, 0x6278;
  lwz r3, 0x16dc(r31);
  cmpwi r3, 0;
  beq lbl_8013ca40;
  bl GKI_freebuf;
  li r0, 0;
  stw r0, 0x16dc(r31);
lbl_8013ca40:
  li r0, 0;
  addi r11, r1, 0x120;
  sth r0, 0x16e0(r31);
  sth r0, 0x16e2(r31);
  sth r0, 0x1698(r29);
  sth r0, 0x169a(r29);
  sth r0, 0x16a6(r29);
  sth r0, 0x16a4(r29);
  bl _restgpr_27;
  lwz r0, 0x124(r1);
  mtlr r0;
  addi r1, r1, 0x120;
  blr;
  // clang-format on
}

// Symbol: btm_inq_db_init
// PAL: 0x8013ca74..0x8013ca78
MARK_BINARY_BLOB(btm_inq_db_init, 0x8013ca74, 0x8013ca78);
asm UNKNOWN_FUNCTION(btm_inq_db_init) {
  // clang-format off
  nofralloc;
  blr;
  // clang-format on
}

// Symbol: btm_inq_find_bdaddr
// PAL: 0x8013ca78..0x8013cb54
MARK_BINARY_BLOB(btm_inq_find_bdaddr, 0x8013ca78, 0x8013cb54);
asm UNKNOWN_FUNCTION(btm_inq_find_bdaddr) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_27;
  lis r31, 0x8033;
  mr r27, r3;
  addi r31, r31, 0x6278;
  lbz r0, 0x1848(r31);
  lwz r29, 0x16dc(r31);
  rlwinm. r0, r0, 0, 0x1d, 0x1d;
  bne lbl_8013cab0;
  cmpwi r29, 0;
  bne lbl_8013cab8;
lbl_8013cab0:
  li r3, 0;
  b lbl_8013cb3c;
lbl_8013cab8:
  lhz r30, 0x16e0(r31);
  li r28, 0;
  b lbl_8013cafc;
lbl_8013cac4:
  mr r4, r27;
  addi r3, r29, 4;
  li r5, 6;
  bl memcmp;
  cmpwi r3, 0;
  bne lbl_8013caf4;
  lwz r3, 0(r29);
  lwz r0, 0x16c0(r31);
  cmplw r3, r0;
  bne lbl_8013caf4;
  li r3, 1;
  b lbl_8013cb3c;
lbl_8013caf4:
  addi r28, r28, 1;
  addi r29, r29, 0xc;
lbl_8013cafc:
  clrlwi r3, r28, 0x10;
  cmplw r3, r30;
  blt lbl_8013cac4;
  lhz r0, 0x16e2(r31);
  cmplw r3, r0;
  bge lbl_8013cb38;
  lwz r0, 0x16c0(r31);
  mr r4, r27;
  addi r3, r29, 4;
  li r5, 6;
  stw r0, 0(r29);
  bl memcpy;
  lhz r3, 0x16e0(r31);
  addi r0, r3, 1;
  sth r0, 0x16e0(r31);
lbl_8013cb38:
  li r3, 0;
lbl_8013cb3c:
  addi r11, r1, 0x20;
  bl _restgpr_27;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: btm_inq_db_new
// PAL: 0x8013cb54..0x8013cc58
MARK_BINARY_BLOB(btm_inq_db_new, 0x8013cb54, 0x8013cc58);
asm UNKNOWN_FUNCTION(btm_inq_db_new) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  lis r4, 0x8033;
  stw r0, 0x24(r1);
  addi r4, r4, 0x6278;
  li r0, 0xc;
  stw r31, 0x1c(r1);
  addi r31, r4, 0x16e4;
  li r4, -1;
  stw r30, 0x18(r1);
  mr r30, r31;
  stw r29, 0x14(r1);
  mr r29, r3;
  li r3, 0;
  mtctr r0;
lbl_8013cb90:
  lbz r0, 0x1a(r31);
  cmpwi r0, 0;
  bne lbl_8013cbcc;
  mr r3, r31;
  li r4, 0;
  li r5, 0x1c;
  bl memset;
  mr r4, r29;
  addi r3, r31, 0xa;
  li r5, 6;
  bl memcpy;
  li r0, 1;
  mr r3, r31;
  stb r0, 0x1a(r31);
  b lbl_8013cc3c;
lbl_8013cbcc:
  lwz r0, 0(r31);
  cmplw r0, r4;
  bge lbl_8013cbe0;
  mr r30, r31;
  mr r4, r0;
lbl_8013cbe0:
  addi r3, r3, 1;
  addi r31, r31, 0x1c;
  bdnz lbl_8013cb90;
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lwz r12, 0x16bc(r3);
  cmpwi r12, 0;
  beq lbl_8013cc10;
  addi r3, r30, 8;
  li r4, 0;
  mtctr r12;
  bctrl;
lbl_8013cc10:
  mr r3, r30;
  li r4, 0;
  li r5, 0x1c;
  bl memset;
  mr r4, r29;
  addi r3, r30, 0xa;
  li r5, 6;
  bl memcpy;
  li r0, 1;
  mr r3, r30;
  stb r0, 0x1a(r30);
lbl_8013cc3c:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: btm_set_inq_event_filter
// PAL: 0x8013cc58..0x8013cd3c
MARK_BINARY_BLOB(btm_set_inq_event_filter, 0x8013cc58, 0x8013cd3c);
asm UNKNOWN_FUNCTION(btm_set_inq_event_filter) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_27;
  mr r27, r3;
  mr r28, r4;
  addi r29, r1, 8;
  li r30, 6;
  li r3, 2;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  mr r31, r3;
  beq lbl_8013cd20;
  cmpwi r27, 1;
  beq lbl_8013ccb4;
  bge lbl_8013cca8;
  cmpwi r27, 0;
  bge lbl_8013cce0;
  b lbl_8013cce8;
lbl_8013cca8:
  cmpwi r27, 3;
  bge lbl_8013cce8;
  b lbl_8013ccd8;
lbl_8013ccb4:
  mr r3, r29;
  mr r4, r28;
  li r5, 3;
  bl memcpy;
  addi r3, r1, 0xb;
  addi r4, r28, 3;
  li r5, 3;
  bl memcpy;
  b lbl_8013ccf0;
lbl_8013ccd8:
  mr r29, r28;
  b lbl_8013ccf0;
lbl_8013cce0:
  li r30, 0;
  b lbl_8013ccf0;
lbl_8013cce8:
  li r3, 5;
  b lbl_8013cd24;
lbl_8013ccf0:
  lis r4, 0x8033;
  li r0, 1;
  addi r4, r4, 0x6278;
  mr r3, r31;
  stb r0, 0x1844(r4);
  mr r5, r27;
  mr r6, r29;
  mr r7, r30;
  li r4, 1;
  bl btsnd_hcic_set_event_filter;
  li r3, 1;
  b lbl_8013cd24;
lbl_8013cd20:
  li r3, 3;
lbl_8013cd24:
  addi r11, r1, 0x30;
  bl _restgpr_27;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: btm_event_filter_complete
// PAL: 0x8013cd3c..0x8013cf5c
MARK_BINARY_BLOB(btm_event_filter_complete, 0x8013cd3c, 0x8013cf5c);
asm UNKNOWN_FUNCTION(btm_event_filter_complete) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  lis r31, 0x8033;
  addi r31, r31, 0x6278;
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  lbz r4, 0x1845(r31);
  lwz r29, 0x16b8(r31);
  cmpwi r4, 0;
  beq lbl_8013cd78;
  addi r0, r4, -1;
  stb r0, 0x1845(r31);
  b lbl_8013cf40;
lbl_8013cd78:
  lbz r0, 0x1844(r31);
  cmplwi r0, 1;
  bne lbl_8013cf40;
  lbz r5, 0(r3);
  cmpwi r5, 0;
  beq lbl_8013cdbc;
  lbz r0, 0x27c0(r31);
  cmplwi r0, 2;
  blt lbl_8013cdb0;
  lis r3, 0xd;
  lis r4, 0x8028;
  addi r3, r3, 1;
  addi r4, r4, 0x3d38;
  bl LogMsg_1;
lbl_8013cdb0:
  li r0, 0xa;
  stb r0, 8(r1);
  b lbl_8013cdc4;
lbl_8013cdbc:
  li r0, 0;
  stb r0, 8(r1);
lbl_8013cdc4:
  lbz r3, 0x1847(r31);
  cmpwi r3, 0;
  bne lbl_8013cdf4;
  li r0, 0;
  cmpwi r29, 0;
  stb r0, 0x1844(r31);
  beq lbl_8013cf40;
  mr r12, r29;
  addi r3, r1, 8;
  mtctr r12;
  bctrl;
  b lbl_8013cf40;
lbl_8013cdf4:
  cmpwi r0, 0;
  beq lbl_8013ce18;
  li r3, 0xa;
  bl btm_process_inq_complete;
  li r0, 0;
  stb r0, 0x1844(r31);
  stb r0, 0x1848(r31);
  stb r0, 0x1847(r31);
  b lbl_8013cf40;
lbl_8013ce18:
  cmplwi r3, 1;
  bne lbl_8013ce5c;
  lbz r3, 0x1837(r31);
  addi r4, r31, 0x1838;
  bl btm_set_inq_event_filter;
  clrlwi r0, r3, 0x18;
  stb r3, 8(r1);
  cmplwi r0, 1;
  bne lbl_8013ce48;
  li r0, 2;
  stb r0, 0x1847(r31);
  b lbl_8013cf40;
lbl_8013ce48:
  li r0, 0;
  li r3, 0xa;
  stb r0, 0x1844(r31);
  bl btm_process_inq_complete;
  b lbl_8013cf40;
lbl_8013ce5c:
  lbz r4, 0x1836(r31);
  li r0, 3;
  li r3, 0;
  stb r0, 0x1847(r31);
  cmplwi r4, 0xc;
  li r0, 0xc;
  stb r3, 0x1844(r31);
  bgt lbl_8013ce80;
  mr r0, r4;
lbl_8013ce80:
  lbz r3, 0x1848(r31);
  addi r29, r2, -26888;
  stb r0, 0x1836(r31);
  clrlwi. r0, r3, 0x1f;
  beq lbl_8013ce98;
  addi r29, r2, -26884;
lbl_8013ce98:
  rlwinm. r0, r3, 0, 0x1d, 0x1d;
  beq lbl_8013cecc;
  lhz r3, 0x1842(r31);
  mr r5, r29;
  lhz r4, 0x1840(r31);
  lbz r6, 0x1835(r31);
  lbz r7, 0x1836(r31);
  bl btsnd_hcic_per_inq_mode;
  clrlwi. r0, r3, 0x18;
  bne lbl_8013cf40;
  li r3, 3;
  bl btm_process_inq_complete;
  b lbl_8013cf40;
lbl_8013cecc:
  lis r30, 0x8033;
  addi r30, r30, 0x6278;
  lwz r3, 0x16dc(r30);
  cmpwi r3, 0;
  beq lbl_8013ceec;
  bl GKI_freebuf;
  li r0, 0;
  stw r0, 0x16dc(r30);
lbl_8013ceec:
  li r0, 0;
  li r3, 0x708;
  sth r0, 0x16e0(r30);
  sth r0, 0x16e2(r30);
  bl GKI_getbuf;
  cmpwi r3, 0;
  stw r3, 0x16dc(r31);
  beq lbl_8013cf20;
  li r0, 0x96;
  li r4, 0;
  sth r0, 0x16e2(r31);
  li r5, 0x708;
  bl memset;
lbl_8013cf20:
  lbz r4, 0x1835(r31);
  mr r3, r29;
  li r5, 0;
  bl btsnd_hcic_inquiry;
  clrlwi. r0, r3, 0x18;
  bne lbl_8013cf40;
  li r3, 3;
  bl btm_process_inq_complete;
lbl_8013cf40:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: btm_process_inq_results
// PAL: 0x8013cf5c..0x8013d1d4
MARK_BINARY_BLOB(btm_process_inq_results, 0x8013cf5c, 0x8013d1d4);
asm UNKNOWN_FUNCTION(btm_process_inq_results) {
  // clang-format off
  nofralloc;
  stwu r1, -0x60(r1);
  mflr r0;
  stw r0, 0x64(r1);
  addi r11, r1, 0x60;
  bl _savegpr_16;
  lis r5, 0x8033;
  mr r18, r4;
  addi r27, r5, 0x6278;
  li r23, 1;
  lbz r0, 0x1848(r27);
  li r21, 0;
  lwz r22, 0x16b4(r27);
  li r20, 0;
  cmpwi r0, 0;
  beq lbl_8013d1bc;
  lbz r28, 0(r3);
  addi r17, r3, 1;
  li r26, 0;
  li r31, 0x7f;
  li r16, 0;
  b lbl_8013d1b0;
lbl_8013cfb0:
  lbz r0, 0(r17);
  cmpwi r18, 0;
  stb r0, 0x11(r1);
  lbz r0, 1(r17);
  stb r0, 0x10(r1);
  lbz r0, 2(r17);
  stb r0, 0xf(r1);
  lbz r0, 3(r17);
  stb r0, 0xe(r1);
  lbz r0, 4(r17);
  stb r0, 0xd(r1);
  lbz r0, 5(r17);
  stb r0, 0xc(r1);
  lbz r29, 6(r17);
  lbz r30, 7(r17);
  addi r17, r17, 8;
  bne lbl_8013cffc;
  lbz r21, 0(r17);
  addi r17, r17, 1;
lbl_8013cffc:
  lbz r0, 0(r17);
  cmpwi r18, 0;
  stb r0, 0xa(r1);
  lbz r0, 1(r17);
  stb r0, 9(r1);
  lbz r0, 2(r17);
  stb r0, 8(r1);
  lbz r0, 4(r17);
  lbz r3, 3(r17);
  addi r17, r17, 5;
  slwi r0, r0, 8;
  add r0, r3, r0;
  clrlwi r19, r0, 0x10;
  beq lbl_8013d03c;
  lbz r20, 0(r17);
  addi r17, r17, 1;
lbl_8013d03c:
  addi r3, r1, 0xc;
  bl btm_inq_find_bdaddr;
  clrlwi. r0, r3, 0x18;
  bne lbl_8013d1ac;
  lwz r12, 0x184c(r27);
  cmpwi r12, 0;
  beq lbl_8013d070;
  addi r3, r1, 0xc;
  addi r4, r1, 8;
  mtctr r12;
  bctrl;
  clrlwi. r0, r3, 0x18;
  beq lbl_8013d1ac;
lbl_8013d070:
  addi r25, r27, 0x16e4;
  li r24, 0;
lbl_8013d078:
  lbz r0, 0x1a(r25);
  cmpwi r0, 0;
  beq lbl_8013d0a0;
  addi r3, r25, 0xa;
  addi r4, r1, 0xc;
  li r5, 6;
  bl memcmp;
  cmpwi r3, 0;
  bne lbl_8013d0a0;
  b lbl_8013d0b4;
lbl_8013d0a0:
  addi r24, r24, 1;
  addi r25, r25, 0x1c;
  cmplwi r24, 0xc;
  blt lbl_8013d078;
  li r25, 0;
lbl_8013d0b4:
  cmpwi r25, 0;
  bne lbl_8013d0d0;
  addi r3, r1, 0xc;
  bl btm_inq_db_new;
  mr r25, r3;
  li r23, 1;
  b lbl_8013d0e4;
lbl_8013d0d0:
  lwz r3, 4(r25);
  lwz r0, 0x16c0(r27);
  cmplw r3, r0;
  bne lbl_8013d0e4;
  li r23, 0;
lbl_8013d0e4:
  cmplwi r23, 1;
  bne lbl_8013d1ac;
  stb r29, 0x13(r25);
  cmpwi r18, 0;
  lbz r5, 8(r1);
  ori r0, r19, 0x8000;
  stb r30, 0x14(r25);
  addi r24, r25, 8;
  lbz r4, 9(r1);
  stb r21, 0x15(r25);
  lbz r3, 0xa(r1);
  stb r5, 0x10(r25);
  stb r4, 0x11(r25);
  stb r3, 0x12(r25);
  sth r0, 8(r25);
  beq lbl_8013d12c;
  stb r20, 0xe(r24);
  b lbl_8013d130;
lbl_8013d12c:
  stb r31, 0xe(r24);
lbl_8013d130:
  bl GKI_get_tick_count;
  stw r3, 0(r25);
  lwz r0, 0x16c0(r27);
  stw r0, 4(r25);
  lbz r0, 0x1848(r27);
  lbz r3, 0x183f(r27);
  rlwinm. r0, r0, 0, 0x1d, 0x1d;
  addi r0, r3, 1;
  stb r0, 0x183f(r27);
  bne lbl_8013d174;
  lbz r3, 0x1836(r27);
  cmpwi r3, 0;
  beq lbl_8013d174;
  clrlwi r0, r0, 0x18;
  cmplw r0, r3;
  bne lbl_8013d174;
  bl btsnd_hcic_inq_cancel;
lbl_8013d174:
  cmpwi r22, 0;
  stb r16, 0x18(r25);
  beq lbl_8013d190;
  mr r12, r22;
  mr r3, r24;
  mtctr r12;
  bctrl;
lbl_8013d190:
  lwz r12, 0x16bc(r27);
  cmpwi r12, 0;
  beq lbl_8013d1ac;
  addi r3, r25, 8;
  li r4, 1;
  mtctr r12;
  bctrl;
lbl_8013d1ac:
  addi r26, r26, 1;
lbl_8013d1b0:
  clrlwi r0, r26, 0x18;
  cmplw r0, r28;
  blt lbl_8013cfb0;
lbl_8013d1bc:
  addi r11, r1, 0x60;
  bl _restgpr_16;
  lwz r0, 0x64(r1);
  mtlr r0;
  addi r1, r1, 0x60;
  blr;
  // clang-format on
}

// Symbol: btm_process_inq_complete
// PAL: 0x8013d1d4..0x8013d2d8
MARK_BINARY_BLOB(btm_process_inq_complete, 0x8013d1d4, 0x8013d2d8);
asm UNKNOWN_FUNCTION(btm_process_inq_complete) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  lis r29, 0x8033;
  addi r29, r29, 0x6278;
  stw r28, 0x10(r1);
  lbz r0, 0x1848(r29);
  lwz r28, 0x16b0(r29);
  cmpwi r0, 0;
  beq lbl_8013d2b8;
  lwz r4, 0x16c0(r29);
  cmpwi r3, 0;
  li r3, 0xa;
  addi r0, r4, 1;
  stw r0, 0x16c0(r29);
  bne lbl_8013d224;
  li r3, 0;
lbl_8013d224:
  lbz r0, 0x1848(r29);
  stb r3, 0x183e(r29);
  rlwinm. r0, r0, 0, 0x1d, 0x1d;
  bne lbl_8013d2b8;
  lis r31, 0x8033;
  li r30, 0;
  addi r31, r31, 0x6278;
  stw r30, 0x16b4(r29);
  lwz r3, 0x16dc(r31);
  stb r30, 0x1848(r29);
  cmpwi r3, 0;
  stb r30, 0x1847(r29);
  stw r30, 0x16b0(r29);
  beq lbl_8013d264;
  bl GKI_freebuf;
  stw r30, 0x16dc(r31);
lbl_8013d264:
  lis r3, 0x8033;
  li r4, 0;
  addi r3, r3, 0x6278;
  sth r4, 0x16e0(r31);
  lbz r0, 0x27c0(r3);
  sth r4, 0x16e2(r31);
  cmplwi r0, 5;
  blt lbl_8013d2a0;
  lis r3, 0xd;
  lis r4, 0x8028;
  lbz r5, 0x183e(r29);
  addi r3, r3, 4;
  lbz r6, 0x183f(r29);
  addi r4, r4, 0x3d74;
  bl LogMsg_2;
lbl_8013d2a0:
  cmpwi r28, 0;
  beq lbl_8013d2b8;
  mr r12, r28;
  addi r3, r29, 0x183e;
  mtctr r12;
  bctrl;
lbl_8013d2b8:
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

// Symbol: btm_initiate_rem_name
// PAL: 0x8013d2d8..0x8013d428
MARK_BINARY_BLOB(btm_initiate_rem_name, 0x8013d2d8, 0x8013d428);
asm UNKNOWN_FUNCTION(btm_initiate_rem_name) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_23;
  lis r31, 0x8033;
  mr r23, r3;
  mr r24, r4;
  mr r25, r5;
  mr r26, r6;
  mr r27, r7;
  addi r31, r31, 0x6278;
  li r30, 1;
  li r29, 1;
  li r28, 1;
  bl BTM_IsDeviceUp;
  clrlwi. r0, r3, 0x18;
  bne lbl_8013d328;
  li r3, 6;
  b lbl_8013d410;
lbl_8013d328:
  lbz r3, 0x16ae(r31);
  and. r0, r3, r25;
  bne lbl_8013d408;
  cmplwi r25, 1;
  bne lbl_8013d374;
  cmpwi r3, 0;
  beq lbl_8013d36c;
  mr r3, r23;
  addi r4, r31, 0x16a8;
  li r5, 6;
  bl memcmp;
  cmpwi r3, 0;
  bne lbl_8013d364;
  li r30, 0;
  b lbl_8013d36c;
lbl_8013d364:
  li r3, 2;
  b lbl_8013d410;
lbl_8013d36c:
  stw r27, 0x167c(r31);
  b lbl_8013d384;
lbl_8013d374:
  cmpwi r3, 0;
  beq lbl_8013d384;
  li r3, 2;
  b lbl_8013d410;
lbl_8013d384:
  cmpwi r30, 0;
  beq lbl_8013d3e8;
  mr r4, r23;
  addi r3, r31, 0x16a8;
  li r5, 6;
  bl memcpy;
  mr r5, r26;
  addi r3, r31, 0x1680;
  li r4, 0xa;
  bl btu_start_timer;
  cmpwi r24, 0;
  beq lbl_8013d3d0;
  lhz r0, 0(r24);
  mr r3, r23;
  lbz r4, 0xb(r24);
  lbz r5, 0xd(r24);
  ori r6, r0, 0x8000;
  bl btsnd_hcic_rmt_name_req;
  b lbl_8013d3e4;
lbl_8013d3d0:
  mr r3, r23;
  li r4, 1;
  li r5, 0;
  li r6, 0;
  bl btsnd_hcic_rmt_name_req;
lbl_8013d3e4:
  mr r29, r3;
lbl_8013d3e8:
  clrlwi. r0, r29, 0x18;
  beq lbl_8013d400;
  lbz r0, 0x16ae(r31);
  or r0, r0, r25;
  stb r0, 0x16ae(r31);
  b lbl_8013d40c;
lbl_8013d400:
  li r28, 3;
  b lbl_8013d40c;
lbl_8013d408:
  li r28, 2;
lbl_8013d40c:
  mr r3, r28;
lbl_8013d410:
  addi r11, r1, 0x30;
  bl _restgpr_23;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: btm_process_remote_name
// PAL: 0x8013d428..0x8013d580
MARK_BINARY_BLOB(btm_process_remote_name, 0x8013d428, 0x8013d580);
asm UNKNOWN_FUNCTION(btm_process_remote_name) {
  // clang-format off
  nofralloc;
  stwu r1, -0x120(r1);
  mflr r0;
  stw r0, 0x124(r1);
  addi r11, r1, 0x120;
  bl _savegpr_26;
  lis r31, 0x8033;
  mr r26, r4;
  addi r31, r31, 0x6278;
  mr r27, r5;
  lwz r30, 0x167c(r31);
  mr r28, r6;
  lbz r29, 0x16ae(r31);
  addi r3, r31, 0x1680;
  bl btu_stop_timer;
  li r3, 0;
  cmpwi r28, 0;
  stb r3, 0x16ae(r31);
  bne lbl_8013d520;
  cmplwi r27, 0xf8;
  addi r4, r1, 0xc;
  li r3, 0xf8;
  bge lbl_8013d484;
  mr r3, r27;
lbl_8013d484:
  clrlwi. r5, r3, 0x10;
  li r0, 0;
  sth r3, 0xa(r1);
  sth r0, 8(r1);
  mr r3, r5;
  beq lbl_8013d530;
  rlwinm. r0, r5, 0x1d, 3, 0x1f;
  mtctr r0;
  beq lbl_8013d500;
lbl_8013d4a8:
  lbz r0, 0(r26);
  addi r5, r5, -8;
  stb r0, 0(r4);
  lbz r0, 1(r26);
  stb r0, 1(r4);
  lbz r0, 2(r26);
  stb r0, 2(r4);
  lbz r0, 3(r26);
  stb r0, 3(r4);
  lbz r0, 4(r26);
  stb r0, 4(r4);
  lbz r0, 5(r26);
  stb r0, 5(r4);
  lbz r0, 6(r26);
  stb r0, 6(r4);
  lbz r0, 7(r26);
  addi r26, r26, 8;
  stb r0, 7(r4);
  addi r4, r4, 8;
  bdnz lbl_8013d4a8;
  andi. r3, r3, 7;
  beq lbl_8013d530;
lbl_8013d500:
  mtctr r3;
lbl_8013d504:
  lbz r0, 0(r26);
  addi r5, r5, -1;
  addi r26, r26, 1;
  stb r0, 0(r4);
  addi r4, r4, 1;
  bdnz lbl_8013d504;
  b lbl_8013d530;
lbl_8013d520:
  li r0, 9;
  sth r3, 0xa(r1);
  sth r0, 8(r1);
  stb r3, 0xc(r1);
lbl_8013d530:
  addi r3, r31, 0x16a8;
  li r4, 0;
  li r5, 6;
  bl memset;
  clrlwi. r0, r29, 0x1f;
  beq lbl_8013d568;
  li r0, 0;
  cmpwi r30, 0;
  stw r0, 0x167c(r31);
  beq lbl_8013d568;
  mr r12, r30;
  addi r3, r1, 8;
  mtctr r12;
  bctrl;
lbl_8013d568:
  addi r11, r1, 0x120;
  bl _restgpr_26;
  lwz r0, 0x124(r1);
  mtlr r0;
  addi r1, r1, 0x120;
  blr;
  // clang-format on
}

// Symbol: btm_inq_rmt_name_failed
// PAL: 0x8013d580..0x8013d5c0
MARK_BINARY_BLOB(btm_inq_rmt_name_failed, 0x8013d580, 0x8013d5c0);
asm UNKNOWN_FUNCTION(btm_inq_rmt_name_failed) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  li r3, 0;
  li r4, 0;
  stw r0, 0x14(r1);
  li r5, 0;
  li r6, 0x1f;
  bl btm_process_remote_name;
  li r3, 0;
  li r4, 0;
  li r5, 0x1f;
  bl btm_sec_rmt_name_request_complete;
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

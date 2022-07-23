#include "btm_devctl.h"

#include <string.h>

#include "gki_buffer.h"
#include "bte_task1.h"
#include "bte_logmsg.h"
#include "btm_acl.h"
#include "btm_discovery.h"
#include "btm_inq.h"
#include "btm_pm.h"
#include "btm_sec.h"
#include "hcicmds.h"
#include "l2c_link.h"
#include "l2c_utils.h"

// Symbol: btm_dev_init
// PAL: 0x8013a06c..0x8013a10c
MARK_BINARY_BLOB(btm_dev_init, 0x8013a06c, 0x8013a10c);
asm UNKNOWN_FUNCTION(btm_dev_init) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  addi r4, r13, -29584;
  li r5, 3;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  lis r31, 0x8033;
  addi r31, r31, 0x6278;
  addi r3, r31, 0x648;
  bl memcpy;
  lis r3, 1;
  li r7, 0xff;
  addi r9, r3, -13288;
  li r12, 1;
  li r3, 0x1400;
  li r11, 2;
  li r10, 4;
  li r8, 0x3f;
  li r6, 0;
  li r0, 5;
  sth r3, 0x64c(r31);
  addi r3, r31, 0x574;
  li r4, 1;
  li r5, 4;
  stw r12, 0x584(r31);
  stw r11, 0x5a0(r31);
  stw r10, 0x5bc(r31);
  sth r9, 0x654(r31);
  sth r8, 0x656(r31);
  stb r7, 0x27bd(r31);
  stb r7, 0x27be(r31);
  stb r6, 0x64e(r31);
  stb r0, 0x64f(r31);
  bl btu_start_timer;
  bl btsnd_hcic_reset;
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: btm_db_reset
// PAL: 0x8013a10c..0x8013a1bc
MARK_BINARY_BLOB(btm_db_reset, 0x8013a10c, 0x8013a1bc);
asm UNKNOWN_FUNCTION(btm_db_reset) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  li r0, 0xc;
  stb r0, 8(r1);
  bl btm_inq_db_reset;
  bl btm_discovery_db_reset;
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lwz r12, 0x5a8(r3);
  cmpwi r12, 0;
  beq lbl_8013a154;
  li r0, 0;
  stw r0, 0x5a8(r3);
  beq lbl_8013a154;
  li r3, 0;
  mtctr r12;
  bctrl;
lbl_8013a154:
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lwz r12, 0x5c4(r3);
  cmpwi r12, 0;
  beq lbl_8013a180;
  li r0, 0;
  stw r0, 0x5c4(r3);
  beq lbl_8013a180;
  addi r3, r1, 8;
  mtctr r12;
  bctrl;
lbl_8013a180:
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lwz r12, 0x5e0(r3);
  cmpwi r12, 0;
  beq lbl_8013a1ac;
  li r0, 0;
  stw r0, 0x5e0(r3);
  beq lbl_8013a1ac;
  addi r3, r1, 8;
  mtctr r12;
  bctrl;
lbl_8013a1ac:
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: BTM_DeviceReset
// PAL: 0x8013a1bc..0x8013a258
MARK_BINARY_BLOB(BTM_DeviceReset, 0x8013a1bc, 0x8013a258);
asm UNKNOWN_FUNCTION(BTM_DeviceReset) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r4, 0x8033;
  stw r0, 0x14(r1);
  addi r4, r4, 0x6278;
  stw r31, 0xc(r1);
  stw r30, 8(r1);
  mr r30, r3;
  lwz r0, 0x58c(r4);
  cmpwi r0, 0;
  beq lbl_8013a1f0;
  cmplw r0, r3;
  bne lbl_8013a240;
lbl_8013a1f0:
  bl btm_acl_device_down;
  bl btm_db_reset;
  lis r31, 0x8033;
  li r6, 0;
  addi r31, r31, 0x6278;
  li r0, 5;
  stw r30, 0x58c(r31);
  addi r3, r31, 0x574;
  li r4, 1;
  li r5, 4;
  stb r6, 0x64e(r31);
  stb r0, 0x64f(r31);
  bl btu_start_timer;
  bl btsnd_hcic_reset;
  lwz r12, 0x568(r31);
  cmpwi r12, 0;
  beq lbl_8013a240;
  li r3, 1;
  mtctr r12;
  bctrl;
lbl_8013a240:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: BTM_SendHciReset
// PAL: 0x8013a258..0x8013a300
MARK_BINARY_BLOB(BTM_SendHciReset, 0x8013a258, 0x8013a300);
asm UNKNOWN_FUNCTION(BTM_SendHciReset) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r4, 0x8033;
  stw r0, 0x14(r1);
  addi r4, r4, 0x6278;
  stw r31, 0xc(r1);
  stw r30, 8(r1);
  mr r30, r3;
  lwz r0, 0x58c(r4);
  cmpwi r0, 0;
  beq lbl_8013a298;
  cmplw r0, r3;
  beq lbl_8013a298;
  lwz r0, 0x620(r4);
  cmplw r0, r3;
  bne lbl_8013a2e8;
lbl_8013a298:
  bl btm_acl_device_down;
  bl btm_db_reset;
  lis r31, 0x8033;
  li r6, 0;
  addi r31, r31, 0x6278;
  li r0, 5;
  stw r30, 0x620(r31);
  addi r3, r31, 0x574;
  li r4, 1;
  li r5, 4;
  stb r6, 0x64e(r31);
  stb r0, 0x64f(r31);
  bl btu_start_timer;
  bl btsnd_hcic_reset;
  lwz r12, 0x568(r31);
  cmpwi r12, 0;
  beq lbl_8013a2e8;
  li r3, 1;
  mtctr r12;
  bctrl;
lbl_8013a2e8:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: BTM_IsDeviceUp
// PAL: 0x8013a300..0x8013a31c
MARK_BINARY_BLOB(BTM_IsDeviceUp, 0x8013a300, 0x8013a31c);
asm UNKNOWN_FUNCTION(BTM_IsDeviceUp) {
  // clang-format off
  nofralloc;
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lbz r3, 0x64e(r3);
  addi r0, r3, -5;
  cntlzw r0, r0;
  rlwinm r3, r0, 0x1b, 0x18, 0x1f;
  blr;
  // clang-format on
}

// Symbol: BTM_SetAfhChannels
// PAL: 0x8013a31c..0x8013a40c
MARK_BINARY_BLOB(BTM_SetAfhChannels, 0x8013a31c, 0x8013a40c);
asm UNKNOWN_FUNCTION(BTM_SetAfhChannels) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r7, 0x8033;
  stw r0, 0x14(r1);
  addi r7, r7, 0x6278;
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  lbz r0, 0x27c0(r7);
  cmplwi r0, 3;
  blt lbl_8013a370;
  lis r3, 0xd;
  lis r4, 0x8028;
  lbz r6, 0x27bd(r7);
  mr r5, r30;
  lbz r8, 0x27be(r7);
  mr r7, r31;
  addi r3, r3, 2;
  addi r4, r4, 0x3940;
  bl LogMsg_4;
lbl_8013a370:
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lbz r4, 0x645(r3);
  rlwinm. r0, r4, 0, 0x1c, 0x1c;
  bne lbl_8013a3a0;
  lbz r0, 0x644(r3);
  rlwinm. r0, r0, 0, 0x1b, 0x1b;
  bne lbl_8013a3a0;
  rlwinm. r0, r4, 0, 0x1b, 0x1b;
  bne lbl_8013a3a0;
  li r3, 4;
  b lbl_8013a3f4;
lbl_8013a3a0:
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lbz r0, 0x27bd(r3);
  cmplw r0, r30;
  bne lbl_8013a3c0;
  lbz r0, 0x27be(r3);
  cmplw r0, r31;
  beq lbl_8013a3f0;
lbl_8013a3c0:
  mr r3, r30;
  mr r4, r31;
  bl btsnd_hcic_set_afh_channels;
  clrlwi. r0, r3, 0x18;
  beq lbl_8013a3e8;
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  stb r30, 0x27bd(r3);
  stb r31, 0x27be(r3);
  b lbl_8013a3f0;
lbl_8013a3e8:
  li r3, 3;
  b lbl_8013a3f4;
lbl_8013a3f0:
  li r3, 0;
lbl_8013a3f4:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: btm_dev_timeout
// PAL: 0x8013a40c..0x8013a6a4
MARK_BINARY_BLOB(btm_dev_timeout, 0x8013a40c, 0x8013a6a4);
asm UNKNOWN_FUNCTION(btm_dev_timeout) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  stw r30, 8(r1);
  lwz r0, 0x10(r3);
  cmplwi r0, 1;
  bne lbl_8013a65c;
  lis r6, 0x8033;
  addi r6, r6, 0x6278;
  lbz r0, 0x64e(r6);
  cmpwi r0, 2;
  beq lbl_8013a59c;
  bge lbl_8013a454;
  cmpwi r0, 0;
  beq lbl_8013a460;
  bge lbl_8013a488;
  b lbl_8013a68c;
lbl_8013a454:
  cmpwi r0, 4;
  bge lbl_8013a68c;
  b lbl_8013a600;
lbl_8013a460:
  li r3, 0;
  li r0, 5;
  stb r3, 0x64e(r6);
  addi r3, r6, 0x574;
  li r4, 1;
  li r5, 4;
  stb r0, 0x64f(r6);
  bl btu_start_timer;
  bl btsnd_hcic_reset;
  b lbl_8013a68c;
lbl_8013a488:
  li r0, 4;
  li r3, 2;
  stb r3, 0x64e(r6);
  stb r0, 0x64f(r6);
  b lbl_8013a4b0;
  stb r0, 0x64f(r6);
  stb r0, 0x64e(r6);
  bl btu_start_timer;
  bl btsnd_hcic_reset;
  b lbl_8013a4d4;
lbl_8013a4b0:
  addi r3, r6, 0x574;
  li r4, 1;
  li r5, 1;
  bl btu_start_timer;
  li r3, 2;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  beq lbl_8013a4d4;
  bl btsnd_hcic_read_buffer_size;
lbl_8013a4d4:
  lis r31, 0x8033;
  li r5, 3;
  addi r31, r31, 0x6278;
  addi r3, r31, 0x648;
  mr r4, r3;
  bl memcpy;
  lbz r0, 0x64e(r31);
  cmpwi r0, 0;
  beq lbl_8013a518;
  cmplwi r0, 1;
  beq lbl_8013a518;
  li r3, 2;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  beq lbl_8013a518;
  addi r4, r31, 0x648;
  bl btsnd_hcic_write_dev_class;
lbl_8013a518:
  lis r0, 0x8033;
  addic. r31, r0, 0x6278;
  beq lbl_8013a580;
  lbz r0, 0x64e(r31);
  cmpwi r0, 0;
  beq lbl_8013a580;
  cmplwi r0, 1;
  beq lbl_8013a580;
  li r3, 2;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  mr r30, r3;
  beq lbl_8013a580;
  cmplw r31, r31;
  beq lbl_8013a574;
  mr r3, r31;
  li r4, 0;
  li r5, 0x20;
  bl memset;
  mr r3, r31;
  mr r4, r31;
  li r5, 0x1f;
  bl strncpy;
lbl_8013a574:
  mr r3, r30;
  mr r4, r31;
  bl btsnd_hcic_change_name;
lbl_8013a580:
  lis r5, 0x8033;
  addi r5, r5, 0x6278;
  lbz r3, 0x20(r5);
  addi r4, r5, 0x22;
  lbz r5, 0x21(r5);
  bl BTM_SetPinType;
  b lbl_8013a68c;
lbl_8013a59c:
  lbz r3, 0x64f(r6);
  addi r3, r3, -1;
  clrlwi. r0, r3, 0x18;
  stb r3, 0x64f(r6);
  bne lbl_8013a5d8;
  li r3, 0;
  li r0, 5;
  stb r3, 0x64e(r6);
  addi r3, r6, 0x574;
  li r4, 1;
  li r5, 4;
  stb r0, 0x64f(r6);
  bl btu_start_timer;
  bl btsnd_hcic_reset;
  b lbl_8013a68c;
lbl_8013a5d8:
  addi r3, r6, 0x574;
  li r4, 1;
  li r5, 1;
  bl btu_start_timer;
  li r3, 2;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  beq lbl_8013a68c;
  bl btsnd_hcic_read_buffer_size;
  b lbl_8013a68c;
lbl_8013a600:
  lbz r3, 0x64f(r6);
  addi r3, r3, -1;
  clrlwi. r0, r3, 0x18;
  stb r3, 0x64f(r6);
  bne lbl_8013a63c;
  li r3, 0;
  li r0, 5;
  stb r3, 0x64e(r6);
  addi r3, r6, 0x574;
  li r4, 1;
  li r5, 4;
  stb r0, 0x64f(r6);
  bl btu_start_timer;
  bl btsnd_hcic_reset;
  b lbl_8013a68c;
lbl_8013a63c:
  addi r3, r6, 0x574;
  li r4, 1;
  li r5, 1;
  bl btu_start_timer;
  bl btsnd_hcic_read_local_ver;
  bl btsnd_hcic_read_bd_addr;
  bl btm_pm_reset;
  b lbl_8013a68c;
lbl_8013a65c:
  cmplwi r0, 2;
  bne lbl_8013a68c;
  lis r3, 0x8033;
  li r0, 0;
  addi r3, r3, 0x6278;
  lwz r12, 0x5a8(r3);
  cmpwi r12, 0;
  stw r0, 0x5a8(r3);
  beq lbl_8013a68c;
  li r3, 0;
  mtctr r12;
  bctrl;
lbl_8013a68c:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: btm_reset_complete
// PAL: 0x8013a6a4..0x8013a868
MARK_BINARY_BLOB(btm_reset_complete, 0x8013a6a4, 0x8013a868);
asm UNKNOWN_FUNCTION(btm_reset_complete) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r3, 0x8033;
  stw r0, 0x14(r1);
  addi r3, r3, 0x6278;
  stw r31, 0xc(r1);
  stw r30, 8(r1);
  lbz r0, 0x27c0(r3);
  cmplwi r0, 4;
  blt lbl_8013a6e0;
  lis r3, 0xd;
  lis r4, 0x8028;
  addi r3, r3, 3;
  addi r4, r4, 0x3970;
  bl LogMsg_0;
lbl_8013a6e0:
  lis r31, 0x8033;
  addi r31, r31, 0x6278;
  lwz r12, 0x620(r31);
  cmpwi r12, 0;
  beq lbl_8013a70c;
  li r0, 0;
  li r3, 0;
  stw r0, 0x620(r31);
  mtctr r12;
  bctrl;
  b lbl_8013a850;
lbl_8013a70c:
  lbz r0, 0x64e(r31);
  cmpwi r0, 0;
  bne lbl_8013a850;
  bl l2cu_device_reset;
  li r6, 0x12;
  li r5, 0x800;
  li r4, 0;
  li r0, 4;
  li r3, 2;
  sth r6, 0x16a0(r31);
  sth r5, 0x16a2(r31);
  sth r4, 0x16a4(r31);
  sth r6, 0x169c(r31);
  sth r5, 0x169e(r31);
  sth r4, 0x16a6(r31);
  stb r3, 0x64e(r31);
  stb r0, 0x64f(r31);
  b lbl_8013a768;
  stb r4, 0x64e(r31);
  stb r0, 0x64f(r31);
  bl btu_start_timer;
  bl btsnd_hcic_reset;
  b lbl_8013a78c;
lbl_8013a768:
  addi r3, r31, 0x574;
  li r4, 1;
  li r5, 1;
  bl btu_start_timer;
  li r3, 2;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  beq lbl_8013a78c;
  bl btsnd_hcic_read_buffer_size;
lbl_8013a78c:
  lis r31, 0x8033;
  li r5, 3;
  addi r31, r31, 0x6278;
  addi r3, r31, 0x648;
  mr r4, r3;
  bl memcpy;
  lbz r0, 0x64e(r31);
  cmpwi r0, 0;
  beq lbl_8013a7d0;
  cmplwi r0, 1;
  beq lbl_8013a7d0;
  li r3, 2;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  beq lbl_8013a7d0;
  addi r4, r31, 0x648;
  bl btsnd_hcic_write_dev_class;
lbl_8013a7d0:
  lis r0, 0x8033;
  addic. r31, r0, 0x6278;
  beq lbl_8013a838;
  lbz r0, 0x64e(r31);
  cmpwi r0, 0;
  beq lbl_8013a838;
  cmplwi r0, 1;
  beq lbl_8013a838;
  li r3, 2;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  mr r30, r3;
  beq lbl_8013a838;
  cmplw r31, r31;
  beq lbl_8013a82c;
  mr r3, r31;
  li r4, 0;
  li r5, 0x20;
  bl memset;
  mr r3, r31;
  mr r4, r31;
  li r5, 0x1f;
  bl strncpy;
lbl_8013a82c:
  mr r3, r30;
  mr r4, r31;
  bl btsnd_hcic_change_name;
lbl_8013a838:
  lis r5, 0x8033;
  addi r5, r5, 0x6278;
  lbz r3, 0x20(r5);
  addi r4, r5, 0x22;
  lbz r5, 0x21(r5);
  bl BTM_SetPinType;
lbl_8013a850:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: btm_read_hci_buf_size_complete
// PAL: 0x8013a868..0x8013a930
MARK_BINARY_BLOB(btm_read_hci_buf_size_complete, 0x8013a868, 0x8013a930);
asm UNKNOWN_FUNCTION(btm_read_hci_buf_size_complete) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  lbz r0, 0(r3);
  cmpwi r0, 0;
  bne lbl_8013a8d4;
  lbz r0, 2(r3);
  lis r6, 0x8033;
  lbz r4, 1(r3);
  addi r6, r6, 0x5d50;
  slwi r0, r0, 8;
  add r0, r4, r0;
  sth r0, 0x7c(r6);
  clrlwi r4, r0, 0x10;
  addi r0, r4, 4;
  lbz r4, 5(r3);
  lbz r5, 4(r3);
  slwi r3, r4, 8;
  add r3, r5, r3;
  sth r0, 0x7e(r6);
  clrlwi r3, r3, 0x10;
  bl l2c_link_processs_num_bufs;
  li r3, 0x69b;
  li r4, 0x1e;
  li r5, 0x14;
  li r6, 0xa;
  bl btsnd_hcic_set_host_buf_size;
lbl_8013a8d4:
  lis r3, 0x8033;
  li r0, 4;
  addi r3, r3, 0x6278;
  li r4, 3;
  stb r4, 0x64e(r3);
  stb r0, 0x64f(r3);
  b lbl_8013a904;
  stb r0, 0x64f(r3);
  stb r0, 0x64e(r3);
  bl btu_start_timer;
  bl btsnd_hcic_reset;
  b lbl_8013a920;
lbl_8013a904:
  addi r3, r3, 0x574;
  li r4, 1;
  li r5, 1;
  bl btu_start_timer;
  bl btsnd_hcic_read_local_ver;
  bl btsnd_hcic_read_bd_addr;
  bl btm_pm_reset;
lbl_8013a920:
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: btm_read_local_version_complete
// PAL: 0x8013a930..0x8013a9ec
MARK_BINARY_BLOB(btm_read_local_version_complete, 0x8013a930, 0x8013a9ec);
asm UNKNOWN_FUNCTION(btm_read_local_version_complete) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r5, 0x8033;
  stw r0, 0x14(r1);
  addi r5, r5, 0x6278;
  lbz r0, 0(r3);
  cmpwi r0, 0;
  bne lbl_8013a99c;
  lbz r0, 1(r3);
  stb r0, 0x636(r5);
  lbz r0, 3(r3);
  lbz r4, 2(r3);
  slwi r0, r0, 8;
  add r0, r4, r0;
  sth r0, 0x638(r5);
  lbz r0, 4(r3);
  stb r0, 0x63a(r5);
  lbz r0, 6(r3);
  lbz r4, 5(r3);
  slwi r0, r0, 8;
  add r0, r4, r0;
  sth r0, 0x63c(r5);
  lbz r0, 8(r3);
  lbz r3, 7(r3);
  slwi r0, r0, 8;
  add r0, r3, r0;
  sth r0, 0x63e(r5);
lbl_8013a99c:
  lis r3, 0x8033;
  li r0, 4;
  addi r3, r3, 0x6278;
  stb r0, 0x64e(r3);
  stb r0, 0x64f(r3);
  b lbl_8013a9c8;
  stb r0, 0x64f(r3);
  stb r0, 0x64e(r3);
  bl btu_start_timer;
  bl btsnd_hcic_reset;
  b lbl_8013a9dc;
lbl_8013a9c8:
  addi r3, r3, 0x574;
  li r4, 1;
  li r5, 1;
  bl btu_start_timer;
  bl btsnd_hcic_read_local_features;
lbl_8013a9dc:
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: btm_read_local_features_complete
// PAL: 0x8013a9ec..0x8013aee8
MARK_BINARY_BLOB(btm_read_local_features_complete, 0x8013a9ec, 0x8013aee8);
asm UNKNOWN_FUNCTION(btm_read_local_features_complete) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_27;
  lis r31, 0x8033;
  lis r30, 0x8028;
  addi r31, r31, 0x6278;
  li r0, 0;
  lwz r28, 0x58c(r31);
  addi r30, r30, 0x3940;
  stw r0, 0x58c(r31);
  lbz r0, 0(r3);
  cmpwi r0, 0;
  bne lbl_8013aed0;
  li r0, 5;
  li r4, 0x18;
  stb r0, 0x64e(r31);
  lbz r0, 1(r3);
  stb r0, 0x640(r31);
  clrlwi. r0, r0, 0x1f;
  lbz r0, 2(r3);
  stb r0, 0x641(r31);
  lbz r0, 3(r3);
  stb r0, 0x642(r31);
  lbz r0, 4(r3);
  stb r0, 0x643(r31);
  lbz r0, 5(r3);
  stb r0, 0x644(r31);
  lbz r0, 6(r3);
  stb r0, 0x645(r31);
  lbz r0, 7(r3);
  stb r0, 0x646(r31);
  lbz r0, 8(r3);
  stb r0, 0x647(r31);
  sth r4, 0x654(r31);
  beq lbl_8013aa88;
  ori r0, r4, 0xc00;
  sth r0, 0x654(r31);
lbl_8013aa88:
  lbz r0, 0x640(r31);
  rlwinm. r0, r0, 0, 0x1e, 0x1e;
  beq lbl_8013aaa8;
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lhz r0, 0x654(r3);
  ori r0, r0, 0xc000;
  sth r0, 0x654(r3);
lbl_8013aaa8:
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lbz r0, 0x636(r3);
  cmplwi r0, 3;
  blt lbl_8013ab48;
  lbz r0, 0x643(r31);
  rlwinm. r0, r0, 0, 0x1e, 0x1e;
  bne lbl_8013aad4;
  lhz r0, 0x654(r3);
  ori r0, r0, 0x1102;
  sth r0, 0x654(r3);
lbl_8013aad4:
  lbz r0, 0x643(r31);
  rlwinm. r0, r0, 0, 0x1d, 0x1d;
  bne lbl_8013aaf4;
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lhz r0, 0x654(r3);
  ori r0, r0, 0x2204;
  sth r0, 0x654(r3);
lbl_8013aaf4:
  lbz r3, 0x643(r31);
  rlwinm. r0, r3, 0, 0x1e, 0x1e;
  bne lbl_8013ab08;
  rlwinm. r0, r3, 0, 0x1d, 0x1d;
  beq lbl_8013ab48;
lbl_8013ab08:
  lbz r0, 0x644(r31);
  rlwinm. r0, r0, 0, 0x18, 0x18;
  bne lbl_8013ab28;
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lhz r0, 0x654(r3);
  ori r0, r0, 0x300;
  sth r0, 0x654(r3);
lbl_8013ab28:
  lbz r0, 0x645(r31);
  clrlwi. r0, r0, 0x1f;
  bne lbl_8013ab48;
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lhz r0, 0x654(r3);
  ori r0, r0, 0x3000;
  sth r0, 0x654(r3);
lbl_8013ab48:
  lis r4, 0x8033;
  addi r4, r4, 0x6278;
  lbz r0, 0x27c0(r4);
  cmplwi r0, 5;
  blt lbl_8013ab70;
  lis r3, 0xd;
  lhz r5, 0x654(r4);
  addi r3, r3, 4;
  addi r4, r30, 0x44;
  bl LogMsg_1;
lbl_8013ab70:
  lbz r3, 0x641(r31);
  lis r4, 0x8033;
  addi r4, r4, 0x6278;
  li r5, 0;
  rlwinm. r0, r3, 0, 0x1c, 0x1c;
  sth r5, 0x656(r4);
  stb r5, 0x1908(r4);
  beq lbl_8013abc8;
  rlwinm. r0, r3, 0, 0x1b, 0x1b;
  li r0, 1;
  sth r0, 0x656(r4);
  beq lbl_8013aba8;
  ori r0, r0, 2;
  sth r0, 0x656(r4);
lbl_8013aba8:
  lbz r0, 0x641(r31);
  rlwinm. r0, r0, 0, 0x1a, 0x1a;
  beq lbl_8013abc8;
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lhz r0, 0x656(r3);
  ori r0, r0, 4;
  sth r0, 0x656(r3);
lbl_8013abc8:
  lbz r0, 0x643(r31);
  rlwinm. r0, r0, 0, 0x18, 0x18;
  beq lbl_8013abe8;
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lhz r0, 0x656(r3);
  ori r0, r0, 8;
  sth r0, 0x656(r3);
lbl_8013abe8:
  lbz r0, 0x644(r31);
  clrlwi. r0, r0, 0x1f;
  beq lbl_8013ac08;
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lhz r0, 0x656(r3);
  ori r0, r0, 0x10;
  sth r0, 0x656(r3);
lbl_8013ac08:
  lbz r0, 0x644(r31);
  rlwinm. r0, r0, 0, 0x1e, 0x1e;
  beq lbl_8013ac28;
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lhz r0, 0x656(r3);
  ori r0, r0, 0x20;
  sth r0, 0x656(r3);
lbl_8013ac28:
  lis r4, 0x8033;
  addi r4, r4, 0x6278;
  lhz r3, 0x656(r4);
  rlwinm. r0, r3, 0, 0x1a, 0x1c;
  beq lbl_8013acac;
  lbz r5, 0x645(r31);
  li r0, 1;
  stb r0, 0x1908(r4);
  rlwinm. r0, r5, 0, 0x1a, 0x1a;
  beq lbl_8013ac64;
  rlwinm. r0, r5, 0, 0x18, 0x18;
  bne lbl_8013ac6c;
  ori r0, r3, 0x100;
  sth r0, 0x656(r4);
  b lbl_8013ac6c;
lbl_8013ac64:
  ori r0, r3, 0x140;
  sth r0, 0x656(r4);
lbl_8013ac6c:
  lbz r3, 0x645(r31);
  rlwinm. r0, r3, 0, 0x19, 0x19;
  beq lbl_8013ac98;
  rlwinm. r0, r3, 0, 0x18, 0x18;
  bne lbl_8013acac;
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lhz r0, 0x656(r3);
  ori r0, r0, 0x200;
  sth r0, 0x656(r3);
  b lbl_8013acac;
lbl_8013ac98:
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lhz r0, 0x656(r3);
  ori r0, r0, 0x280;
  sth r0, 0x656(r3);
lbl_8013acac:
  lis r4, 0x8033;
  addi r4, r4, 0x6278;
  lbz r0, 0x27c0(r4);
  cmplwi r0, 5;
  blt lbl_8013acd4;
  lis r3, 0xd;
  lhz r5, 0x656(r4);
  addi r3, r3, 4;
  addi r4, r30, 0x70;
  bl LogMsg_1;
lbl_8013acd4:
  lbz r0, 0x640(r31);
  rlwinm. r0, r0, 0, 0x1a, 0x1a;
  beq lbl_8013acf8;
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lhz r0, 0x4c4(r3);
  ori r0, r0, 1;
  sth r0, 0x4c4(r3);
  b lbl_8013ad0c;
lbl_8013acf8:
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lhz r0, 0x4c4(r3);
  rlwinm r0, r0, 0, 0x10, 0x1e;
  sth r0, 0x4c4(r3);
lbl_8013ad0c:
  lbz r0, 0x640(r31);
  rlwinm. r0, r0, 0, 0x19, 0x19;
  beq lbl_8013ad30;
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lhz r0, 0x4c4(r3);
  ori r0, r0, 2;
  sth r0, 0x4c4(r3);
  b lbl_8013ad44;
lbl_8013ad30:
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lhz r0, 0x4c4(r3);
  rlwinm r0, r0, 0, 0x1f, 0x1d;
  sth r0, 0x4c4(r3);
lbl_8013ad44:
  lbz r0, 0x640(r31);
  rlwinm. r0, r0, 0, 0x18, 0x18;
  beq lbl_8013ad68;
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lhz r0, 0x4c4(r3);
  ori r0, r0, 4;
  sth r0, 0x4c4(r3);
  b lbl_8013ad7c;
lbl_8013ad68:
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lhz r0, 0x4c4(r3);
  rlwinm r0, r0, 0, 0x1e, 0x1c;
  sth r0, 0x4c4(r3);
lbl_8013ad7c:
  lbz r0, 0x641(r31);
  clrlwi. r0, r0, 0x1f;
  beq lbl_8013ada0;
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lhz r0, 0x4c4(r3);
  ori r0, r0, 8;
  sth r0, 0x4c4(r3);
  b lbl_8013adb4;
lbl_8013ada0:
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lhz r0, 0x4c4(r3);
  rlwinm r0, r0, 0, 0x1d, 0x1b;
  sth r0, 0x4c4(r3);
lbl_8013adb4:
  bl btm_sec_dev_reset;
  lis r4, 0x8033;
  addi r4, r4, 0x6278;
  lbz r29, 0x27be(r4);
  cmplwi r29, 0xff;
  beq lbl_8013ae74;
  lbz r0, 0x27c0(r4);
  li r3, 0xff;
  lbz r27, 0x27bd(r4);
  cmplwi r0, 3;
  stb r3, 0x27be(r4);
  stb r3, 0x27bd(r4);
  blt lbl_8013ae08;
  lis r3, 0xd;
  mr r5, r27;
  mr r7, r29;
  addi r4, r30, 0;
  addi r3, r3, 2;
  li r6, 0xff;
  li r8, 0xff;
  bl LogMsg_4;
lbl_8013ae08:
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lbz r4, 0x645(r3);
  rlwinm. r0, r4, 0, 0x1c, 0x1c;
  bne lbl_8013ae30;
  lbz r0, 0x644(r3);
  rlwinm. r0, r0, 0, 0x1b, 0x1b;
  bne lbl_8013ae30;
  rlwinm. r0, r4, 0, 0x1b, 0x1b;
  beq lbl_8013ae74;
lbl_8013ae30:
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lbz r0, 0x27bd(r3);
  cmplw r0, r27;
  bne lbl_8013ae50;
  lbz r0, 0x27be(r3);
  cmplw r0, r29;
  beq lbl_8013ae74;
lbl_8013ae50:
  mr r3, r27;
  mr r4, r29;
  bl btsnd_hcic_set_afh_channels;
  clrlwi. r0, r3, 0x18;
  beq lbl_8013ae74;
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  stb r27, 0x27bd(r3);
  stb r29, 0x27be(r3);
lbl_8013ae74:
  lbz r0, 0x643(r31);
  rlwinm. r0, r0, 0, 0x19, 0x19;
  beq lbl_8013ae88;
  li r3, 1;
  bl BTM_SetInquiryMode;
lbl_8013ae88:
  li r3, 1;
  bl BTM_SetPageScanType;
  li r3, 1;
  bl BTM_SetInquiryScanType;
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lwz r12, 0x568(r3);
  cmpwi r12, 0;
  beq lbl_8013aeb8;
  li r3, 0;
  mtctr r12;
  bctrl;
lbl_8013aeb8:
  cmpwi r28, 0;
  beq lbl_8013aed0;
  mr r12, r28;
  li r3, 0;
  mtctr r12;
  bctrl;
lbl_8013aed0:
  addi r11, r1, 0x20;
  bl _restgpr_27;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: BTM_SetLocalDeviceName
// PAL: 0x8013aee8..0x8013afa0
MARK_BINARY_BLOB(BTM_SetLocalDeviceName, 0x8013aee8, 0x8013afa0);
asm UNKNOWN_FUNCTION(BTM_SetLocalDeviceName) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  cmpwi r3, 0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  mr r29, r3;
  bne lbl_8013af14;
  li r3, 5;
  b lbl_8013af84;
lbl_8013af14:
  lis r30, 0x8033;
  addi r30, r30, 0x6278;
  lbz r0, 0x64e(r30);
  cmplwi r0, 1;
  bgt lbl_8013af30;
  li r3, 0xc;
  b lbl_8013af84;
lbl_8013af30:
  li r3, 2;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  mr r31, r3;
  beq lbl_8013af80;
  cmplw r30, r29;
  beq lbl_8013af6c;
  mr r3, r30;
  li r4, 0;
  li r5, 0x20;
  bl memset;
  mr r3, r30;
  mr r4, r29;
  li r5, 0x1f;
  bl strncpy;
lbl_8013af6c:
  mr r3, r31;
  mr r4, r30;
  bl btsnd_hcic_change_name;
  li r3, 1;
  b lbl_8013af84;
lbl_8013af80:
  li r3, 3;
lbl_8013af84:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: btm_read_local_name_complete
// PAL: 0x8013afa0..0x8013b02c
MARK_BINARY_BLOB(btm_read_local_name_complete, 0x8013afa0, 0x8013b02c);
asm UNKNOWN_FUNCTION(btm_read_local_name_complete) {
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
  mr r29, r3;
  addi r3, r31, 0x590;
  lwz r30, 0x5a8(r31);
  bl btu_stop_timer;
  li r0, 0;
  cmpwi r30, 0;
  stw r0, 0x5a8(r31);
  beq lbl_8013b010;
  lbz r0, 0(r29);
  cmpwi r0, 0;
  bne lbl_8013b000;
  mr r12, r30;
  addi r3, r29, 1;
  mtctr r12;
  bctrl;
  b lbl_8013b010;
lbl_8013b000:
  mr r12, r30;
  li r3, 0;
  mtctr r12;
  bctrl;
lbl_8013b010:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: BTM_ReadLocalDeviceAddr
// PAL: 0x8013b02c..0x8013b06c
MARK_BINARY_BLOB(BTM_ReadLocalDeviceAddr, 0x8013b02c, 0x8013b06c);
asm UNKNOWN_FUNCTION(BTM_ReadLocalDeviceAddr) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmpwi r3, 0;
  stw r0, 0x14(r1);
  beq lbl_8013b058;
  lis r4, 0x8033;
  mr r12, r3;
  addi r4, r4, 0x6278;
  addi r3, r4, 0x630;
  mtctr r12;
  bctrl;
lbl_8013b058:
  lwz r0, 0x14(r1);
  li r3, 0;
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: btm_read_local_addr_complete
// PAL: 0x8013b06c..0x8013b0b4
MARK_BINARY_BLOB(btm_read_local_addr_complete, 0x8013b06c, 0x8013b0b4);
asm UNKNOWN_FUNCTION(btm_read_local_addr_complete) {
  // clang-format off
  nofralloc;
  lbz r0, 0(r3);
  cmpwi r0, 0;
  bnelr;
  lis r4, 0x8033;
  lbz r0, 1(r3);
  addi r4, r4, 0x6278;
  stb r0, 0x635(r4);
  lbz r0, 2(r3);
  stb r0, 0x634(r4);
  lbz r0, 3(r3);
  stb r0, 0x633(r4);
  lbz r0, 4(r3);
  stb r0, 0x632(r4);
  lbz r0, 5(r3);
  stb r0, 0x631(r4);
  lbz r0, 6(r3);
  stb r0, 0x630(r4);
  blr;
  // clang-format on
}

// Symbol: BTM_ReadLocalVersion
// PAL: 0x8013b0b4..0x8013b100
MARK_BINARY_BLOB(BTM_ReadLocalVersion, 0x8013b0b4, 0x8013b100);
asm UNKNOWN_FUNCTION(BTM_ReadLocalVersion) {
  // clang-format off
  nofralloc;
  lis r5, 0x8033;
  addi r5, r5, 0x6278;
  lbz r0, 0x64e(r5);
  cmplwi r0, 4;
  bge lbl_8013b0d0;
  li r3, 0xc;
  blr;
lbl_8013b0d0:
  lhz r4, 0x636(r5);
  lhz r0, 0x638(r5);
  sth r4, 0(r3);
  sth r0, 2(r3);
  lhz r4, 0x63a(r5);
  lhz r0, 0x63c(r5);
  sth r4, 4(r3);
  sth r0, 6(r3);
  lhz r0, 0x63e(r5);
  sth r0, 8(r3);
  li r3, 0;
  blr;
  // clang-format on
}

// Symbol: BTM_SetDeviceClass
// PAL: 0x8013b100..0x8013b180
MARK_BINARY_BLOB(BTM_SetDeviceClass, 0x8013b100, 0x8013b180);
asm UNKNOWN_FUNCTION(BTM_SetDeviceClass) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  li r5, 3;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  lis r31, 0x8033;
  addi r31, r31, 0x6278;
  stw r30, 8(r1);
  mr r30, r3;
  mr r4, r30;
  addi r3, r31, 0x648;
  bl memcpy;
  lbz r0, 0x64e(r31);
  cmplwi r0, 1;
  bgt lbl_8013b144;
  li r3, 0xc;
  b lbl_8013b168;
lbl_8013b144:
  li r3, 2;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  beq lbl_8013b164;
  mr r4, r30;
  bl btsnd_hcic_write_dev_class;
  li r3, 0;
  b lbl_8013b168;
lbl_8013b164:
  li r3, 3;
lbl_8013b168:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: BTM_ReadDeviceClass
// PAL: 0x8013b180..0x8013b190
MARK_BINARY_BLOB(BTM_ReadDeviceClass, 0x8013b180, 0x8013b190);
asm UNKNOWN_FUNCTION(BTM_ReadDeviceClass) {
  // clang-format off
  nofralloc;
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  addi r3, r3, 0x648;
  blr;
  // clang-format on
}

// Symbol: BTM_ReadLocalFeatures
// PAL: 0x8013b190..0x8013b1a0
MARK_BINARY_BLOB(BTM_ReadLocalFeatures, 0x8013b190, 0x8013b1a0);
asm UNKNOWN_FUNCTION(BTM_ReadLocalFeatures) {
  // clang-format off
  nofralloc;
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  addi r3, r3, 0x640;
  blr;
  // clang-format on
}

// Symbol: BTM_RegisterForDeviceStatusNotif
// PAL: 0x8013b1a0..0x8013b1b8
MARK_BINARY_BLOB(BTM_RegisterForDeviceStatusNotif, 0x8013b1a0, 0x8013b1b8);
asm UNKNOWN_FUNCTION(BTM_RegisterForDeviceStatusNotif) {
  // clang-format off
  nofralloc;
  lis r4, 0x8033;
  mr r0, r3;
  addi r4, r4, 0x6278;
  lwz r3, 0x568(r4);
  stw r0, 0x568(r4);
  blr;
  // clang-format on
}

// Symbol: BTM_VendorSpecificCommand
// PAL: 0x8013b1b8..0x8013b2b4
MARK_BINARY_BLOB(BTM_VendorSpecificCommand, 0x8013b1b8, 0x8013b2b4);
asm UNKNOWN_FUNCTION(BTM_VendorSpecificCommand) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_27;
  lis r7, 0x8033;
  mr r27, r3;
  addi r7, r7, 0x6278;
  mr r28, r4;
  lbz r0, 0x27c0(r7);
  mr r29, r5;
  mr r30, r6;
  cmplwi r0, 4;
  blt lbl_8013b20c;
  lis r3, 0xd;
  lis r4, 0x8028;
  mr r5, r27;
  mr r6, r28;
  addi r3, r3, 3;
  addi r4, r4, 0x39dc;
  bl LogMsg_2;
lbl_8013b20c:
  lis r31, 0x8033;
  addi r31, r31, 0x6278;
  lbz r0, 0x650(r31);
  cmpwi r0, 0;
  beq lbl_8013b248;
  lbz r0, 0x27c0(r31);
  cmplwi r0, 4;
  blt lbl_8013b240;
  lis r3, 0xd;
  lis r4, 0x8028;
  addi r3, r3, 3;
  addi r4, r4, 0x3a1c;
  bl LogMsg_0;
lbl_8013b240:
  li r3, 2;
  b lbl_8013b29c;
lbl_8013b248:
  addi r0, r28, 0xb;
  clrlwi r3, r0, 0x10;
  bl GKI_getbuf;
  cmpwi r3, 0;
  beq lbl_8013b298;
  cmpwi r30, 0;
  stw r30, 0x61c(r31);
  beq lbl_8013b270;
  li r0, 1;
  stb r0, 0x650(r31);
lbl_8013b270:
  mr r4, r27;
  mr r5, r28;
  mr r6, r29;
  bl btsnd_hcic_vendor_spec_cmd;
  cmpwi r30, 0;
  beq lbl_8013b290;
  li r3, 1;
  b lbl_8013b29c;
lbl_8013b290:
  li r3, 0;
  b lbl_8013b29c;
lbl_8013b298:
  li r3, 3;
lbl_8013b29c:
  addi r11, r1, 0x20;
  bl _restgpr_27;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: btm_vsc_complete
// PAL: 0x8013b2b4..0x8013b320
MARK_BINARY_BLOB(btm_vsc_complete, 0x8013b2b4, 0x8013b320);
asm UNKNOWN_FUNCTION(btm_vsc_complete) {
  // clang-format off
  nofralloc;
  stwu r1, -0x120(r1);
  mflr r0;
  lis r6, 0x8033;
  mr r7, r3;
  stw r0, 0x124(r1);
  addi r6, r6, 0x6278;
  li r0, 0;
  addi r3, r1, 0xc;
  stw r31, 0x11c(r1);
  lwz r31, 0x61c(r6);
  stb r0, 0x650(r6);
  cmpwi r31, 0;
  stw r0, 0x61c(r6);
  beq lbl_8013b30c;
  sth r4, 8(r1);
  mr r4, r7;
  sth r5, 0xa(r1);
  bl memcpy;
  mr r12, r31;
  addi r3, r1, 8;
  mtctr r12;
  bctrl;
lbl_8013b30c:
  lwz r0, 0x124(r1);
  lwz r31, 0x11c(r1);
  mtlr r0;
  addi r1, r1, 0x120;
  blr;
  // clang-format on
}

// Symbol: BTM_RegisterForVSEvents
// PAL: 0x8013b320..0x8013b358
MARK_BINARY_BLOB(BTM_RegisterForVSEvents, 0x8013b320, 0x8013b358);
asm UNKNOWN_FUNCTION(BTM_RegisterForVSEvents) {
  // clang-format off
  nofralloc;
  lis r4, 0x8033;
  addi r4, r4, 0x6278;
  lwz r0, 0x56c(r4);
  cmpwi r0, 0;
  beq lbl_8013b344;
  cmpwi r3, 0;
  beq lbl_8013b344;
  li r3, 2;
  blr;
lbl_8013b344:
  lis r4, 0x8033;
  addi r4, r4, 0x6278;
  stw r3, 0x56c(r4);
  li r3, 0;
  blr;
  // clang-format on
}

// Symbol: btm_vendor_specific_evt
// PAL: 0x8013b358..0x8013b3f0
MARK_BINARY_BLOB(btm_vendor_specific_evt, 0x8013b358, 0x8013b3f0);
asm UNKNOWN_FUNCTION(btm_vendor_specific_evt) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  lis r31, 0x8033;
  addi r31, r31, 0x6278;
  stw r30, 0x18(r1);
  mr r30, r4;
  stw r29, 0x14(r1);
  mr r29, r3;
  lhz r0, 0x63c(r31);
  cmplwi r0, 0x12;
  beq lbl_8013b3ac;
  lbz r0, 0x27c0(r31);
  cmplwi r0, 4;
  blt lbl_8013b3ac;
  lis r3, 0xd;
  lis r4, 0x8028;
  addi r3, r3, 3;
  addi r4, r4, 0x3a60;
  bl LogMsg_0;
lbl_8013b3ac:
  lwz r12, 0x56c(r31);
  li r0, 0;
  stw r0, 0x61c(r31);
  cmpwi r12, 0;
  stb r0, 0x650(r31);
  beq lbl_8013b3d4;
  mr r3, r30;
  mr r4, r29;
  mtctr r12;
  bctrl;
lbl_8013b3d4:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: BTM_WritePageTimeout
// PAL: 0x8013b3f0..0x8013b490
MARK_BINARY_BLOB(BTM_WritePageTimeout, 0x8013b3f0, 0x8013b490);
asm UNKNOWN_FUNCTION(BTM_WritePageTimeout) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r4, 0x8033;
  stw r0, 0x14(r1);
  addi r4, r4, 0x6278;
  stw r31, 0xc(r1);
  mr r31, r3;
  lbz r0, 0x27c0(r4);
  cmplwi r0, 4;
  blt lbl_8013b430;
  lis r3, 0xd;
  lis r4, 0x8028;
  mr r5, r31;
  addi r3, r3, 3;
  addi r4, r4, 0x3aa0;
  bl LogMsg_1;
lbl_8013b430:
  mulli r0, r31, 0x271;
  lis r3, 0x1062;
  lis r4, 0x8033;
  addi r3, r3, 0x4dd3;
  mulhw r0, r3, r0;
  addi r4, r4, 0x6278;
  li r3, 2;
  srawi r0, r0, 6;
  srwi r5, r0, 0x1f;
  add r0, r0, r5;
  sth r0, 0x64c(r4);
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  beq lbl_8013b478;
  mr r4, r31;
  bl btsnd_hcic_write_page_tout;
  li r3, 0;
  b lbl_8013b47c;
lbl_8013b478:
  li r3, 3;
lbl_8013b47c:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: BTM_ReadStoredLinkKey
// PAL: 0x8013b490..0x8013b568
MARK_BINARY_BLOB(BTM_ReadStoredLinkKey, 0x8013b490, 0x8013b568);
asm UNKNOWN_FUNCTION(BTM_ReadStoredLinkKey) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  lis r5, 0x8033;
  stw r0, 0x24(r1);
  addi r5, r5, 0x6278;
  stw r31, 0x1c(r1);
  li r31, 0;
  stw r30, 0x18(r1);
  mr r30, r4;
  stw r29, 0x14(r1);
  mr r29, r3;
  lwz r0, 0x570(r5);
  cmpwi r0, 0;
  beq lbl_8013b4d0;
  li r3, 2;
  b lbl_8013b54c;
lbl_8013b4d0:
  cmpwi r3, 0;
  bne lbl_8013b4e0;
  li r31, 1;
  addi r29, r1, 8;
lbl_8013b4e0:
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lbz r0, 0x27c0(r3);
  cmplwi r0, 4;
  blt lbl_8013b518;
  cmpwi r31, 0;
  lis r3, 0xd;
  lis r4, 0x8028;
  addi r5, r13, -29572;
  addi r3, r3, 3;
  addi r4, r4, 0x3b10;
  beq lbl_8013b514;
  addi r5, r13, -29580;
lbl_8013b514:
  bl LogMsg_1;
lbl_8013b518:
  li r3, 2;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  beq lbl_8013b548;
  lis r6, 0x8033;
  mr r4, r29;
  addi r6, r6, 0x6278;
  mr r5, r31;
  stw r30, 0x570(r6);
  bl btsnd_hcic_read_stored_key;
  li r3, 0;
  b lbl_8013b54c;
lbl_8013b548:
  li r3, 3;
lbl_8013b54c:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: BTM_WriteStoredLinkKey
// PAL: 0x8013b568..0x8013b638
MARK_BINARY_BLOB(BTM_WriteStoredLinkKey, 0x8013b568, 0x8013b638);
asm UNKNOWN_FUNCTION(BTM_WriteStoredLinkKey) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  lis r7, 0x8033;
  stw r0, 0x24(r1);
  addi r7, r7, 0x6278;
  stw r31, 0x1c(r1);
  mr r31, r6;
  stw r30, 0x18(r1);
  mr r30, r5;
  stw r29, 0x14(r1);
  mr r29, r4;
  stw r28, 0x10(r1);
  mr r28, r3;
  lwz r0, 0x570(r7);
  cmpwi r0, 0;
  beq lbl_8013b5b0;
  li r3, 2;
  b lbl_8013b618;
lbl_8013b5b0:
  lbz r0, 0x27c0(r7);
  cmplwi r0, 4;
  blt lbl_8013b5d4;
  lis r3, 0xd;
  lis r4, 0x8028;
  mr r5, r28;
  addi r3, r3, 3;
  addi r4, r4, 0x3b3c;
  bl LogMsg_1;
lbl_8013b5d4:
  cmplwi r28, 0xb;
  ble lbl_8013b5e0;
  li r28, 0xb;
lbl_8013b5e0:
  li r3, 2;
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  beq lbl_8013b614;
  lis r6, 0x8033;
  mr r4, r28;
  addi r6, r6, 0x6278;
  mr r5, r29;
  stw r31, 0x570(r6);
  mr r6, r30;
  bl btsnd_hcic_write_stored_key;
  li r3, 0;
  b lbl_8013b618;
lbl_8013b614:
  li r3, 3;
lbl_8013b618:
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

// Symbol: BTM_DeleteStoredLinkKey
// PAL: 0x8013b638..0x8013b708
MARK_BINARY_BLOB(BTM_DeleteStoredLinkKey, 0x8013b638, 0x8013b708);
asm UNKNOWN_FUNCTION(BTM_DeleteStoredLinkKey) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  lis r5, 0x8033;
  stw r0, 0x24(r1);
  addi r5, r5, 0x6278;
  stw r31, 0x1c(r1);
  li r31, 0;
  stw r30, 0x18(r1);
  mr r30, r4;
  stw r29, 0x14(r1);
  mr r29, r3;
  lwz r0, 0x570(r5);
  cmpwi r0, 0;
  beq lbl_8013b678;
  li r3, 2;
  b lbl_8013b6ec;
lbl_8013b678:
  cmpwi r3, 0;
  bne lbl_8013b688;
  li r31, 1;
  addi r29, r1, 8;
lbl_8013b688:
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lbz r0, 0x27c0(r3);
  cmplwi r0, 4;
  blt lbl_8013b6c0;
  cmpwi r31, 0;
  lis r3, 0xd;
  lis r4, 0x8028;
  addi r5, r13, -29572;
  addi r3, r3, 3;
  addi r4, r4, 0x3b68;
  beq lbl_8013b6bc;
  addi r5, r13, -29580;
lbl_8013b6bc:
  bl LogMsg_1;
lbl_8013b6c0:
  lis r5, 0x8033;
  mr r3, r29;
  addi r5, r5, 0x6278;
  mr r4, r31;
  stw r30, 0x570(r5);
  bl btsnd_hcic_delete_stored_key;
  clrlwi. r0, r3, 0x18;
  bne lbl_8013b6e8;
  li r3, 3;
  b lbl_8013b6ec;
lbl_8013b6e8:
  li r3, 0;
lbl_8013b6ec:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: btm_read_stored_link_key_complete
// PAL: 0x8013b708..0x8013b784
MARK_BINARY_BLOB(btm_read_stored_link_key_complete, 0x8013b708, 0x8013b784);
asm UNKNOWN_FUNCTION(btm_read_stored_link_key_complete) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r4, 0x8033;
  stw r0, 0x14(r1);
  addi r4, r4, 0x6278;
  li r0, 0;
  lwz r12, 0x570(r4);
  cmpwi r12, 0;
  stw r0, 0x570(r4);
  beq lbl_8013b774;
  li r0, 2;
  stb r0, 8(r1);
  lbz r0, 0(r3);
  stb r0, 9(r1);
  lbz r0, 2(r3);
  lbz r4, 1(r3);
  slwi r0, r0, 8;
  add r0, r4, r0;
  sth r0, 0xa(r1);
  lbz r0, 4(r3);
  lbz r4, 3(r3);
  addi r3, r1, 8;
  slwi r0, r0, 8;
  add r0, r4, r0;
  sth r0, 0xc(r1);
  mtctr r12;
  bctrl;
lbl_8013b774:
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: btm_write_stored_link_key_complete
// PAL: 0x8013b784..0x8013b7e0
MARK_BINARY_BLOB(btm_write_stored_link_key_complete, 0x8013b784, 0x8013b7e0);
asm UNKNOWN_FUNCTION(btm_write_stored_link_key_complete) {
  // clang-format off
  stwu r1, -0x10(r1);
  mflr r0;
  lis r4, 0x8033;
  stw r0, 0x14(r1);
  addi r4, r4, 0x6278;
  li r0, 0;
  lwz r12, 0x570(r4);
  cmpwi r12, 0;
  stw r0, 0x570(r4);
  beq lbl_8013b7d0;
  li r0, 3;
  stb r0, 8(r1);
  lbz r0, 0(r3);
  stb r0, 9(r1);
  lbz r0, 1(r3);
  addi r3, r1, 8;
  stb r0, 0xa(r1);
  mtctr r12;
  bctrl;
lbl_8013b7d0:
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: btm_delete_stored_link_key_complete
// PAL: 0x8013b7e0..0x8013b848
MARK_BINARY_BLOB(btm_delete_stored_link_key_complete, 0x8013b7e0, 0x8013b848);
asm UNKNOWN_FUNCTION(btm_delete_stored_link_key_complete) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r4, 0x8033;
  stw r0, 0x14(r1);
  addi r4, r4, 0x6278;
  li r0, 0;
  lwz r12, 0x570(r4);
  cmpwi r12, 0;
  stw r0, 0x570(r4);
  beq lbl_8013b838;
  li r0, 4;
  stb r0, 8(r1);
  lbz r0, 0(r3);
  stb r0, 9(r1);
  lbz r0, 2(r3);
  lbz r4, 1(r3);
  addi r3, r1, 8;
  slwi r0, r0, 8;
  add r0, r4, r0;
  sth r0, 0xa(r1);
  mtctr r12;
  bctrl;
lbl_8013b838:
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: btm_return_link_keys_evt
// PAL: 0x8013b848..0x8013b9d4
MARK_BINARY_BLOB(btm_return_link_keys_evt, 0x8013b848, 0x8013b9d4);
asm UNKNOWN_FUNCTION(btm_return_link_keys_evt) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  lis r4, 0x8033;
  stw r0, 0x24(r1);
  addi r4, r4, 0x6278;
  lwz r12, 0x570(r4);
  cmpwi r12, 0;
  beq lbl_8013b9c4;
  addi r5, r3, 2;
  li r4, 0;
  b lbl_8013b9ac;
lbl_8013b874:
  lbz r11, 0(r5);
  addi r4, r4, 1;
  lbz r10, 1(r5);
  lbz r9, 2(r5);
  lbz r8, 3(r5);
  lbz r7, 4(r5);
  lbz r6, 5(r5);
  lbz r0, 6(r5);
  stb r0, 0x17(r1);
  lbz r0, 7(r5);
  stb r0, 0x16(r1);
  lbz r0, 8(r5);
  stb r0, 0x15(r1);
  lbz r0, 9(r5);
  stb r0, 0x14(r1);
  lbz r0, 0xa(r5);
  stb r0, 0x13(r1);
  lbz r0, 0xb(r5);
  stb r0, 0x12(r1);
  lbz r0, 0xc(r5);
  stb r0, 0x11(r1);
  lbz r0, 0xd(r5);
  stb r0, 0x10(r1);
  lbz r0, 0xe(r5);
  stb r0, 0xf(r1);
  lbz r0, 0xf(r5);
  stb r0, 0xe(r1);
  lbz r0, 0x10(r5);
  stb r0, 0xd(r1);
  lbz r0, 0x11(r5);
  stb r0, 0xc(r1);
  lbz r0, 0x12(r5);
  stb r0, 0xb(r1);
  lbz r0, 0x13(r5);
  stb r0, 0xa(r1);
  lbz r0, 0x14(r5);
  stb r0, 9(r1);
  lbz r0, 0x15(r5);
  stb r0, 8(r1);
  stb r6, 0(r5);
  stb r7, 1(r5);
  stb r8, 2(r5);
  stb r9, 3(r5);
  stb r10, 4(r5);
  stb r11, 5(r5);
  lbz r0, 8(r1);
  stb r0, 6(r5);
  lbz r0, 9(r1);
  stb r0, 7(r5);
  lbz r0, 0xa(r1);
  stb r0, 8(r5);
  lbz r0, 0xb(r1);
  stb r0, 9(r5);
  lbz r0, 0xc(r1);
  stb r0, 0xa(r5);
  lbz r0, 0xd(r1);
  stb r0, 0xb(r5);
  lbz r0, 0xe(r1);
  stb r0, 0xc(r5);
  lbz r0, 0xf(r1);
  stb r0, 0xd(r5);
  lbz r0, 0x10(r1);
  stb r0, 0xe(r5);
  lbz r0, 0x11(r1);
  stb r0, 0xf(r5);
  lbz r0, 0x12(r1);
  stb r0, 0x10(r5);
  lbz r0, 0x13(r1);
  stb r0, 0x11(r5);
  lbz r0, 0x14(r1);
  stb r0, 0x12(r5);
  lbz r0, 0x15(r1);
  stb r0, 0x13(r5);
  lbz r0, 0x16(r1);
  stb r0, 0x14(r5);
  lbz r0, 0x17(r1);
  stb r0, 0x15(r5);
  addi r5, r5, 0x16;
lbl_8013b9ac:
  lbz r0, 1(r3);
  clrlwi r6, r4, 0x18;
  cmplw r6, r0;
  blt lbl_8013b874;
  mtctr r12;
  bctrl;
lbl_8013b9c4:
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: btm_report_device_status
// PAL: 0x8013b9d4..0x8013b9f4
MARK_BINARY_BLOB(btm_report_device_status, 0x8013b9d4, 0x8013b9f4);
asm UNKNOWN_FUNCTION(btm_report_device_status) {
  // clang-format off
  nofralloc;
  lis r4, 0x8033;
  addi r4, r4, 0x6278;
  lwz r12, 0x568(r4);
  cmpwi r12, 0;
  beqlr;
  mtctr r12;
  bctr;
  blr;
  // clang-format on
}

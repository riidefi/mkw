#include "bta_dm_int.h"

#include <string.h>

#include "gki_buffer.h"
#include "bte_logmsg.h"
#include "bd.h"
#include "bta_sys.h"
#include "bta_dm_pm.h"
#include "btm_acl.h"
#include "btm_dev.h"
#include "btm_devctl.h"
#include "btm_discovery.h"
#include "btm_inq.h"
#include "btm_sec.h"
#include "wbt_ext.h"

// Extern function references.
// PAL: 0x80146170
extern UNKNOWN_FUNCTION(btsnd_hcic_write_scan_enable);
// PAL: 0x8014aa44
extern UNKNOWN_FUNCTION(L2CA_SetIdleTimeout);
// PAL: 0x8014ab0c
extern UNKNOWN_FUNCTION(L2CA_SetIdleTimeoutByBdAddr);
// PAL: 0x8014ac28
extern UNKNOWN_FUNCTION(L2CA_RegisterCompression);
// PAL: 0x80156618
extern UNKNOWN_FUNCTION(SDP_InitDiscoveryDb);
// PAL: 0x801569ec
extern UNKNOWN_FUNCTION(SDP_ServiceSearchAttributeRequest);
// PAL: 0x80156a50
extern UNKNOWN_FUNCTION(SDP_FindAttributeInRec);
// PAL: 0x80156a78
extern UNKNOWN_FUNCTION(SDP_FindServiceInDb);
// PAL: 0x801d09c4
extern UNKNOWN_FUNCTION(bta_dm_co_get_compress_memory);

const u16 unk_80388678 = 0x0001;
const u16 unk_8038867a = 0x8001;

// Symbol: bta_dm_enable
// PAL: 0x80132520..0x80132630
MARK_BINARY_BLOB(bta_dm_enable, 0x80132520, 0x80132630);
asm UNKNOWN_FUNCTION(bta_dm_enable) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  lis r4, 0x8033;
  li r5, 0x7c;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  mr r30, r3;
  addi r3, r4, 0x5e98;
  li r4, 0;
  bl memset;
  lis r3, 0x8033;
  li r4, 0;
  addi r3, r3, 0x6018;
  li r5, 0x2e;
  bl memset;
  lis r31, 0x8025;
  addi r3, r1, 8;
  addi r4, r31, -14600;
  li r5, 3;
  bl memcpy;
  addi r3, r1, 8;
  bl BTM_SetDeviceClass;
  lis r4, 0x8033;
  lwz r0, 8(r30);
  addi r4, r4, 0x5f14;
  lis r3, 0x8025;
  stw r0, 0x50(r4);
  addi r3, r3, -14296;
  bl BTM_SecRegister;
  addi r31, r31, -14600;
  lhz r3, 8(r31);
  bl BTM_SetDefaultLinkSuperTout;
  lhz r3, 6(r31);
  bl BTM_WritePageTimeout;
  lhz r3, 4(r31);
  bl BTM_SetDefaultLinkPolicy;
  lis r3, 0x8013;
  addi r3, r3, 0x3f60;
  bl BTM_AclRegisterForChanges;
  lis r3, 0x8013;
  addi r3, r3, 0x3e08;
  bl BTM_ReadLocalDeviceAddr;
  lis r3, 0x8013;
  addi r3, r3, 0x4660;
  bl bta_sys_rm_register;
  lis r31, 0x8013;
  addi r3, r31, 0x4428;
  bl bta_sys_compress_register;
  bl bta_dm_init_pm;
  lis r3, 0x8033;
  li r4, 0;
  addi r3, r3, 0x5e68;
  li r5, 0x2d;
  bl memset;
  addi r3, r31, 0x4428;
  bl bta_sys_compress_register;
  lis r3, 0x8013;
  li r4, 0;
  addi r3, r3, 0x4344;
  bl L2CA_RegisterCompression;
  bl WBT_ExtCreateRecord;
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: bta_dm_disable
// PAL: 0x80132630..0x801326e0
MARK_BINARY_BLOB(bta_dm_disable, 0x80132630, 0x801326e0);
asm UNKNOWN_FUNCTION(bta_dm_disable) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  addi r3, r2, -26864;
  li r4, 0;
  stw r0, 0x14(r1);
  bl L2CA_SetIdleTimeoutByBdAddr;
  bl bta_sys_disable;
  li r3, 0;
  li r4, 0;
  li r5, 0;
  bl BTM_SetDiscoverability;
  li r3, 0;
  li r4, 0;
  li r5, 0;
  bl BTM_SetConnectability;
  bl bta_dm_disable_pm;
  bl BTM_GetNumAclLinks;
  clrlwi. r0, r3, 0x10;
  bne lbl_801326a4;
  lis r6, 0x8013;
  lis r3, 0x8033;
  addi r3, r3, 0x5f14;
  li r4, 0;
  addi r6, r6, 0x4250;
  li r5, 0x3e8;
  stw r6, 0x7c(r3);
  addi r3, r3, 0x74;
  bl bta_sys_start_timer;
  b lbl_801326d0;
lbl_801326a4:
  lis r6, 0x8033;
  lis r5, 0x8013;
  addi r6, r6, 0x5f14;
  li r0, 1;
  addi r5, r5, 0x26e0;
  stb r0, 0x72(r6);
  addi r3, r6, 0x74;
  li r4, 0;
  stw r5, 0x7c(r6);
  li r5, 0x1388;
  bl bta_sys_start_timer;
lbl_801326d0:
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: bta_dm_disable_timer_cback
// PAL: 0x801326e0..0x8013279c
MARK_BINARY_BLOB(bta_dm_disable_timer_cback, 0x801326e0, 0x8013279c);
asm UNKNOWN_FUNCTION(bta_dm_disable_timer_cback) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  stw r30, 8(r1);
  lbz r0, -0x6610(r13);
  cmplwi r0, 4;
  blt lbl_80132710;
  lis r4, 0x8028;
  li r3, 0x503;
  addi r4, r4, 0x28c8;
  bl LogMsg_0;
lbl_80132710:
  bl BTM_GetNumAclLinks;
  clrlwi. r0, r3, 0x10;
  beq lbl_80132760;
  lis r3, 0x8033;
  addi r31, r3, 0x5f14;
  lbz r0, 0x101(r31);
  cmpwi r0, 0;
  bne lbl_80132760;
  li r30, 0;
  b lbl_8013274c;
lbl_80132738:
  clrlwi r0, r30, 0x18;
  mulli r0, r0, 0xb;
  add r3, r31, r0;
  bl btm_remove_acl;
  addi r30, r30, 1;
lbl_8013274c:
  lbz r0, 0x4d(r31);
  clrlwi r3, r30, 0x18;
  cmplw r3, r0;
  blt lbl_80132738;
  b lbl_80132784;
lbl_80132760:
  lis r5, 0x8033;
  li r0, 0;
  addi r5, r5, 0x5f14;
  li r3, 1;
  lwz r12, 0x50(r5);
  li r4, 0;
  stb r0, 0x72(r5);
  mtctr r12;
  bctrl;
lbl_80132784:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: bta_dm_set_dev_name
// PAL: 0x8013279c..0x801327a4
MARK_BINARY_BLOB(bta_dm_set_dev_name, 0x8013279c, 0x801327a4);
asm UNKNOWN_FUNCTION(bta_dm_set_dev_name) {
  // clang-format off
  nofralloc;
  addi r3, r3, 8;
  b BTM_SetLocalDeviceName;
  // clang-format on
}

// Symbol: bta_dm_set_visibility
// PAL: 0x801327a4..0x801327ec
MARK_BINARY_BLOB(bta_dm_set_visibility, 0x801327a4, 0x801327ec);
asm UNKNOWN_FUNCTION(bta_dm_set_visibility) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  li r4, 0;
  li r5, 0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  lbz r3, 8(r3);
  bl BTM_SetDiscoverability;
  lbz r3, 9(r31);
  li r4, 0;
  li r5, 0;
  bl BTM_SetConnectability;
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: bta_dm_bond
// PAL: 0x801327ec..0x8013285c
MARK_BINARY_BLOB(bta_dm_bond, 0x801327ec, 0x8013285c);
asm UNKNOWN_FUNCTION(bta_dm_bond) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r3;
  addi r3, r3, 8;
  bl btm_read_trusted_mask;
  cmpwi r3, 0;
  beq lbl_80132824;
  mr r4, r3;
  addi r3, r1, 8;
  li r5, 8;
  bl memcpy;
  b lbl_80132834;
lbl_80132824:
  addi r3, r1, 8;
  li r4, 0;
  li r5, 8;
  bl memset;
lbl_80132834:
  lbz r4, 0xe(r31);
  addi r3, r31, 8;
  addi r5, r31, 0xf;
  addi r6, r1, 8;
  bl BTM_SecBond;
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: bta_dm_pin_reply
// PAL: 0x8013285c..0x801328f8
MARK_BINARY_BLOB(bta_dm_pin_reply, 0x8013285c, 0x801328f8);
asm UNKNOWN_FUNCTION(bta_dm_pin_reply) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r3;
  addi r3, r3, 8;
  bl btm_read_trusted_mask;
  cmpwi r3, 0;
  beq lbl_80132894;
  mr r4, r3;
  addi r3, r1, 8;
  li r5, 8;
  bl memcpy;
  b lbl_801328a4;
lbl_80132894:
  addi r3, r1, 8;
  li r4, 0;
  li r5, 8;
  bl memset;
lbl_801328a4:
  lbz r0, 0xe(r31);
  cmpwi r0, 0;
  beq lbl_801328cc;
  lbz r5, 0xf(r31);
  addi r3, r31, 8;
  addi r6, r31, 0x10;
  addi r7, r1, 8;
  li r4, 0;
  bl BTM_PINCodeReply;
  b lbl_801328e4;
lbl_801328cc:
  addi r3, r31, 8;
  addi r7, r1, 8;
  li r4, 0xb;
  li r5, 0;
  li r6, 0;
  bl BTM_PINCodeReply;
lbl_801328e4:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: bta_dm_auth_reply
// PAL: 0x801328f8..0x801329cc
MARK_BINARY_BLOB(bta_dm_auth_reply, 0x801328f8, 0x801329cc);
asm UNKNOWN_FUNCTION(bta_dm_auth_reply) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r3;
  addi r3, r3, 8;
  bl btm_read_trusted_mask;
  cmpwi r3, 0;
  beq lbl_80132930;
  mr r4, r3;
  addi r3, r1, 8;
  li r5, 8;
  bl memcpy;
  b lbl_80132940;
lbl_80132930:
  addi r3, r1, 8;
  li r4, 0;
  li r5, 8;
  bl memset;
lbl_80132940:
  lbz r0, 0xf(r31);
  cmplwi r0, 2;
  beq lbl_801329a8;
  cmpwi r0, 0;
  bne lbl_80132994;
  lbz r0, 0xe(r31);
  cmplwi r0, 0x17;
  bgt lbl_80132994;
  lis r3, 0x8025;
  rlwinm r0, r0, 2, 0x16, 0x1d;
  addi r3, r3, -14392;
  addi r5, r1, 8;
  lwzx r4, r3, r0;
  li r3, 1;
  rlwinm r0, r4, 0, 0x13, 0x1a;
  rlwinm r6, r4, 0x1d, 0x16, 0x1d;
  subf r0, r0, r4;
  lwzx r4, r5, r6;
  slw r0, r3, r0;
  or r0, r4, r0;
  stwx r0, r5, r6;
lbl_80132994:
  addi r3, r31, 8;
  addi r5, r1, 8;
  li r4, 0;
  bl BTM_DeviceAuthorized;
  b lbl_801329b8;
lbl_801329a8:
  addi r3, r31, 8;
  addi r5, r1, 8;
  li r4, 0xb;
  bl BTM_DeviceAuthorized;
lbl_801329b8:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: bta_dm_search_start
// PAL: 0x801329cc..0x80132a2c
MARK_BINARY_BLOB(bta_dm_search_start, 0x801329cc, 0x80132a2c);
asm UNKNOWN_FUNCTION(bta_dm_search_start) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  li r3, 0;
  bl BTM_ClearInqDb;
  lwz r0, 0x18(r31);
  lis r3, 0x8033;
  lis r4, 0x8013;
  lis r5, 0x8013;
  stw r0, 0x5e98(r3);
  addi r6, r3, 0x5e98;
  addi r3, r31, 8;
  addi r4, r4, 0x37f4;
  lwz r0, 0x14(r31);
  addi r5, r5, 0x3884;
  stw r0, 8(r6);
  bl BTM_StartInquiry;
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: bta_dm_search_cancel
// PAL: 0x80132a2c..0x80132ab0
MARK_BINARY_BLOB(bta_dm_search_cancel, 0x80132a2c, 0x80132ab0);
asm UNKNOWN_FUNCTION(bta_dm_search_cancel) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  li r3, 0;
  stw r0, 0x14(r1);
  bl BTM_ClearInqDb;
  bl BTM_IsInquiryActive;
  clrlwi. r0, r3, 0x10;
  beq lbl_80132a88;
  bl BTM_CancelInquiry;
  lis r4, 0x8033;
  li r3, 4;
  lwz r12, 0x5e98(r4);
  li r4, 0;
  mtctr r12;
  bctrl;
  li r3, 0x110;
  bl GKI_getbuf;
  cmpwi r3, 0;
  beq lbl_80132aa0;
  li r0, 0x207;
  sth r0, 0(r3);
  bl bta_sys_sendmsg;
  b lbl_80132aa0;
lbl_80132a88:
  lis r3, 0x8033;
  addi r3, r3, 0x5e98;
  lwz r0, 8(r3);
  cmpwi r0, 0;
  bne lbl_80132aa0;
  bl BTM_CancelRemoteDeviceName;
lbl_80132aa0:
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: bta_dm_discover
// PAL: 0x80132ab0..0x80132bc4
MARK_BINARY_BLOB(bta_dm_discover, 0x80132ab0, 0x80132bc4);
asm UNKNOWN_FUNCTION(bta_dm_discover) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r4, 0x8033;
  stw r0, 0x14(r1);
  li r0, 0;
  stw r31, 0xc(r1);
  addi r31, r4, 0x5e98;
  stw r30, 8(r1);
  mr r30, r3;
  lwz r5, 0x14(r3);
  stw r5, 0x5e98(r4);
  lis r4, 0x8013;
  lwz r5, 0x10(r3);
  addi r3, r4, 0x38d0;
  stw r5, 8(r31);
  stw r5, 0xc(r31);
  stb r0, 0x70(r31);
  stw r0, 0x10(r31);
  stb r0, 0x20(r31);
  bl BTM_SecAddRmtNameNotifyCallback;
  addi r3, r31, 0x1a;
  addi r4, r30, 8;
  bl bdcpy;
  lwz r0, 8(r31);
  cmpwi r0, 0;
  beq lbl_80132b24;
  addi r3, r31, 0x1a;
  bl bta_dm_find_services;
  b lbl_80132bac;
lbl_80132b24:
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lhz r4, 0x64c(r3);
  cmplwi r4, 0x7530;
  bge lbl_80132b48;
  addi r5, r4, 0x64;
  addi r3, r31, 0x58;
  li r4, 0x205;
  bl bta_sys_start_timer;
lbl_80132b48:
  lis r31, 0x8033;
  lis r4, 0x8013;
  addi r31, r31, 0x5e98;
  addi r3, r31, 0x1a;
  addi r4, r4, 0x399c;
  bl BTM_ReadRemoteDeviceName;
  clrlwi r0, r3, 0x18;
  cmplwi r0, 1;
  beq lbl_80132bac;
  addi r3, r31, 0x58;
  bl bta_sys_stop_timer;
  li r3, 0x110;
  bl GKI_getbuf;
  cmpwi r3, 0;
  mr r30, r3;
  beq lbl_80132bac;
  addi r3, r3, 8;
  addi r4, r31, 0x1a;
  bl bdcpy;
  li r3, 0;
  li r0, 0x204;
  stb r3, 0xe(r30);
  mr r3, r30;
  sth r0, 0(r30);
  bl bta_sys_sendmsg;
lbl_80132bac:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: bta_dm_inq_cmpl
// PAL: 0x80132bc4..0x80132de8
MARK_BINARY_BLOB(bta_dm_inq_cmpl, 0x80132bc4, 0x80132de8);
asm UNKNOWN_FUNCTION(bta_dm_inq_cmpl) {
  // clang-format off
  nofralloc;
  stwu r1, -0x230(r1);
  mflr r0;
  stw r0, 0x234(r1);
  addi r11, r1, 0x230;
  bl _savegpr_27;
  mr r31, r3;
  li r27, 1;
  bl BTM_InqDbFirst;
  lis r28, 0x8033;
  cmpwi r3, 0;
  addi r29, r28, 0x5e98;
  stw r3, 4(r29);
  beq lbl_80132d7c;
  lwz r0, 8(r29);
  li r27, 0;
  cmpwi r0, 0;
  beq lbl_80132c7c;
  addi r3, r3, 2;
  bl BTM_IsAclConnectionUp;
  clrlwi. r0, r3, 0x18;
  beq lbl_80132c24;
  li r0, 0;
  stb r0, 0x78(r29);
  b lbl_80132c2c;
lbl_80132c24:
  li r0, 1;
  stb r0, 0x78(r29);
lbl_80132c2c:
  lis r30, 0x8033;
  lis r3, 0x8013;
  addi r30, r30, 0x5e98;
  li r29, 0;
  stb r29, 0x79(r30);
  addi r3, r3, 0x38d0;
  bl BTM_SecAddRmtNameNotifyCallback;
  lwz r0, 8(r30);
  addi r3, r30, 0x1a;
  lwz r4, 4(r30);
  stb r29, 0x70(r30);
  addi r4, r4, 2;
  stw r29, 0x10(r30);
  stw r0, 0xc(r30);
  stb r29, 0x20(r30);
  bl bdcpy;
  lwz r3, 4(r30);
  addi r3, r3, 2;
  bl bta_dm_find_services;
  b lbl_80132d7c;
lbl_80132c7c:
  li r27, 1;
  li r30, 0;
  b lbl_80132d70;
lbl_80132c88:
  lbz r0, 0x10(r4);
  cmpwi r0, 0;
  beq lbl_80132cc0;
  addi r3, r1, 8;
  addi r4, r4, 2;
  bl bdcpy;
  lwz r12, 0x5e98(r28);
  addi r4, r1, 8;
  stb r30, 0xe(r1);
  li r3, 2;
  stw r30, 0x108(r1);
  mtctr r12;
  bctrl;
  b lbl_80132d64;
lbl_80132cc0:
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lhz r4, 0x64c(r3);
  cmplwi r4, 0x7530;
  bge lbl_80132cec;
  lis r3, 0x8033;
  addi r5, r4, 0x64;
  addi r3, r3, 0x5e98;
  li r4, 0x205;
  addi r3, r3, 0x58;
  bl bta_sys_start_timer;
lbl_80132cec:
  lis r30, 0x8033;
  lis r4, 0x8013;
  addi r30, r30, 0x5e98;
  lwz r3, 4(r30);
  addi r4, r4, 0x3910;
  addi r3, r3, 2;
  bl BTM_ReadRemoteDeviceName;
  clrlwi r0, r3, 0x18;
  cmplwi r0, 1;
  beq lbl_80132d5c;
  addi r3, r30, 0x58;
  bl bta_sys_stop_timer;
  lwz r4, 4(r30);
  li r3, 0x110;
  addi r28, r4, 2;
  bl GKI_getbuf;
  cmpwi r3, 0;
  mr r29, r3;
  beq lbl_80132d5c;
  mr r4, r28;
  addi r3, r3, 8;
  bl bdcpy;
  li r3, 0;
  li r0, 0x204;
  stb r3, 0xe(r29);
  mr r3, r29;
  sth r0, 0(r29);
  bl bta_sys_sendmsg;
lbl_80132d5c:
  li r27, 0;
  b lbl_80132d7c;
lbl_80132d64:
  lwz r3, 4(r29);
  bl BTM_InqDbNext;
  stw r3, 4(r29);
lbl_80132d70:
  lwz r4, 4(r29);
  cmpwi r4, 0;
  bne lbl_80132c88;
lbl_80132d7c:
  cmpwi r27, 0;
  beq lbl_80132db0;
  lis r4, 0x8033;
  li r0, 0;
  addi r4, r4, 0x5e98;
  li r3, 0x110;
  stw r0, 8(r4);
  bl GKI_getbuf;
  cmpwi r3, 0;
  beq lbl_80132db0;
  li r0, 0x207;
  sth r0, 0(r3);
  bl bta_sys_sendmsg;
lbl_80132db0:
  lis r3, 0x8033;
  lbz r0, 8(r31);
  lwz r12, 0x5e98(r3);
  addi r4, r1, 0x110;
  stb r0, 0x110(r1);
  li r3, 1;
  mtctr r12;
  bctrl;
  addi r11, r1, 0x230;
  bl _restgpr_27;
  lwz r0, 0x234(r1);
  mtlr r0;
  addi r1, r1, 0x230;
  blr;
  // clang-format on
}

// Symbol: bta_dm_rmt_name
// PAL: 0x80132de8..0x80132f54
MARK_BINARY_BLOB(bta_dm_rmt_name, 0x80132de8, 0x80132f54);
asm UNKNOWN_FUNCTION(bta_dm_rmt_name) {
  // clang-format off
  nofralloc;
  stwu r1, -0x130(r1);
  mflr r0;
  stw r0, 0x134(r1);
  addi r11, r1, 0x130;
  bl _savegpr_27;
  lis r28, 0x8033;
  mr r31, r3;
  li r27, 1;
  li r30, 0;
  addi r29, r28, 0x5e98;
  b lbl_80132eec;
lbl_80132e14:
  lwz r4, 4(r29);
  lbz r0, 0x10(r4);
  cmpwi r0, 0;
  beq lbl_80132e50;
  addi r3, r1, 8;
  addi r4, r4, 2;
  bl bdcpy;
  lwz r12, 0x5e98(r28);
  addi r4, r1, 8;
  stb r30, 0xe(r1);
  li r3, 2;
  stw r30, 0x108(r1);
  mtctr r12;
  bctrl;
  b lbl_80132eec;
lbl_80132e50:
  lis r3, 0x8033;
  addi r3, r3, 0x6278;
  lhz r4, 0x64c(r3);
  cmplwi r4, 0x7530;
  bge lbl_80132e74;
  addi r5, r4, 0x64;
  addi r3, r29, 0x58;
  li r4, 0x205;
  bl bta_sys_start_timer;
lbl_80132e74:
  lis r30, 0x8033;
  lis r4, 0x8013;
  addi r30, r30, 0x5e98;
  lwz r3, 4(r30);
  addi r4, r4, 0x3910;
  addi r3, r3, 2;
  bl BTM_ReadRemoteDeviceName;
  clrlwi r0, r3, 0x18;
  cmplwi r0, 1;
  beq lbl_80132ee4;
  addi r3, r30, 0x58;
  bl bta_sys_stop_timer;
  lwz r4, 4(r30);
  li r3, 0x110;
  addi r28, r4, 2;
  bl GKI_getbuf;
  cmpwi r3, 0;
  mr r29, r3;
  beq lbl_80132ee4;
  mr r4, r28;
  addi r3, r3, 8;
  bl bdcpy;
  li r3, 0;
  li r0, 0x204;
  stb r3, 0xe(r29);
  mr r3, r29;
  sth r0, 0(r29);
  bl bta_sys_sendmsg;
lbl_80132ee4:
  li r27, 0;
  b lbl_80132f00;
lbl_80132eec:
  lwz r3, 4(r29);
  bl BTM_InqDbNext;
  cmpwi r3, 0;
  stw r3, 4(r29);
  bne lbl_80132e14;
lbl_80132f00:
  cmpwi r27, 0;
  beq lbl_80132f24;
  li r3, 0x110;
  bl GKI_getbuf;
  cmpwi r3, 0;
  beq lbl_80132f24;
  li r0, 0x207;
  sth r0, 0(r3);
  bl bta_sys_sendmsg;
lbl_80132f24:
  lis r3, 0x8033;
  addi r4, r31, 8;
  lwz r12, 0x5e98(r3);
  li r3, 2;
  mtctr r12;
  bctrl;
  addi r11, r1, 0x130;
  bl _restgpr_27;
  lwz r0, 0x134(r1);
  mtlr r0;
  addi r1, r1, 0x130;
  blr;
  // clang-format on
}

// Symbol: bta_dm_disc_rmt_name
// PAL: 0x80132f54..0x80132fb8
MARK_BINARY_BLOB(bta_dm_disc_rmt_name, 0x80132f54, 0x80132fb8);
asm UNKNOWN_FUNCTION(bta_dm_disc_rmt_name) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  li r3, 0x110;
  bl GKI_getbuf;
  cmpwi r3, 0;
  beq lbl_80132f84;
  li r0, 0x207;
  sth r0, 0(r3);
  bl bta_sys_sendmsg;
lbl_80132f84:
  li r0, 0;
  lis r5, 0x8033;
  stw r0, 0x108(r31);
  addi r4, r31, 8;
  li r3, 2;
  lwz r12, 0x5e98(r5);
  mtctr r12;
  bctrl;
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: bta_dm_sdp_result
// PAL: 0x80132fb8..0x80133220
MARK_BINARY_BLOB(bta_dm_sdp_result, 0x80132fb8, 0x80133220);
asm UNKNOWN_FUNCTION(bta_dm_sdp_result) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  li r29, 0;
  lhz r5, 8(r3);
  li r3, 0;
  cmpwi r5, 0;
  beq lbl_80132ff4;
  cmplwi r5, 0xfff0;
  beq lbl_80132ff4;
  cmplwi r5, 0xfff4;
  bne lbl_80133144;
lbl_80132ff4:
  lis r6, 0x8033;
  lis r4, 0x8025;
  addi r6, r6, 0x5e98;
  cmplwi r5, 0xfff4;
  lbz r5, 0x70(r6);
  addi r4, r4, -14440;
  addi r0, r5, -1;
  slwi r0, r0, 1;
  lhzx r30, r4, r0;
  beq lbl_80133034;
  lwz r3, 0x14(r6);
  mr r4, r30;
  li r5, 0;
  bl SDP_FindServiceInDb;
  cmpwi r3, 0;
  beq lbl_80133094;
lbl_80133034:
  cmplwi r30, 0x1200;
  bne lbl_80133064;
  cmpwi r3, 0;
  beq lbl_80133068;
  lis r4, 1;
  addi r0, r4, -32767;
  clrlwi r4, r0, 0x10;
  bl SDP_FindAttributeInRec;
  cmpwi r3, 0;
  beq lbl_80133068;
  li r29, 1;
  b lbl_80133068;
lbl_80133064:
  li r29, 1;
lbl_80133068:
  cmpwi r29, 0;
  beq lbl_80133094;
  lis r6, 0x8033;
  li r4, 1;
  addi r6, r6, 0x5e98;
  lbz r3, 0x70(r6);
  lwz r5, 0x10(r6);
  addi r0, r3, -1;
  slw r0, r4, r0;
  or r0, r5, r0;
  stw r0, 0x10(r6);
lbl_80133094:
  lis r30, 0x8033;
  addi r30, r30, 0x5e98;
  lwz r3, 0x14(r30);
  bl GKI_freebuf;
  lwz r0, 0xc(r30);
  li r31, 0;
  stw r31, 0x14(r30);
  cmpwi r0, 0;
  beq lbl_801330c4;
  addi r3, r30, 0x1a;
  bl bta_dm_find_services;
  b lbl_80133204;
lbl_801330c4:
  lis r3, 0x8013;
  addi r3, r3, 0x38d0;
  bl BTM_SecDeleteRmtNameNotifyCallback;
  li r3, 0x110;
  bl GKI_getbuf;
  cmpwi r3, 0;
  mr r29, r3;
  beq lbl_80133204;
  li r0, 0x208;
  addi r4, r30, 0x1a;
  sth r0, 0(r3);
  stb r31, 0x10c(r3);
  lwz r0, 0x10(r30);
  stw r0, 0x108(r3);
  addi r3, r3, 8;
  bl bdcpy;
  lbz r0, 0x20(r30);
  addi r31, r30, 0x20;
  extsb. r0, r0;
  bne lbl_80133128;
  addi r3, r30, 0x1a;
  bl BTM_SecReadDevName;
  cmpwi r3, 0;
  beq lbl_80133128;
  mr r31, r3;
lbl_80133128:
  mr r4, r31;
  addi r3, r29, 0xe;
  li r5, 0x20;
  bl strncpy;
  mr r3, r29;
  bl bta_sys_sendmsg;
  b lbl_80133204;
lbl_80133144:
  cmplwi r5, 0xfff1;
  beq lbl_8013315c;
  addi r0, r5, 0xa;
  clrlwi r0, r0, 0x10;
  cmplwi r0, 1;
  bgt lbl_8013316c;
lbl_8013315c:
  lis r3, 0x8033;
  li r0, 0;
  addi r3, r3, 0x5e98;
  stb r0, 0x78(r3);
lbl_8013316c:
  lis r31, 0x8033;
  addi r31, r31, 0x5e98;
  lwz r3, 0x14(r31);
  bl GKI_freebuf;
  li r0, 0;
  lis r3, 0x8013;
  stw r0, 0x14(r31);
  addi r3, r3, 0x38d0;
  bl BTM_SecDeleteRmtNameNotifyCallback;
  li r3, 0x110;
  bl GKI_getbuf;
  cmpwi r3, 0;
  mr r29, r3;
  beq lbl_80133204;
  li r4, 0x208;
  li r0, 1;
  sth r4, 0(r3);
  addi r4, r31, 0x1a;
  stb r0, 0x10c(r3);
  lwz r0, 0x10(r31);
  stw r0, 0x108(r3);
  addi r3, r3, 8;
  bl bdcpy;
  lbz r0, 0x20(r31);
  addi r30, r31, 0x20;
  extsb. r0, r0;
  bne lbl_801331ec;
  addi r3, r31, 0x1a;
  bl BTM_SecReadDevName;
  cmpwi r3, 0;
  beq lbl_801331ec;
  mr r30, r3;
lbl_801331ec:
  mr r4, r30;
  addi r3, r29, 0xe;
  li r5, 0x20;
  bl strncpy;
  mr r3, r29;
  bl bta_sys_sendmsg;
lbl_80133204:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: bta_dm_search_cmpl
// PAL: 0x80133220..0x80133238
MARK_BINARY_BLOB(bta_dm_search_cmpl, 0x80133220, 0x80133238);
asm UNKNOWN_FUNCTION(bta_dm_search_cmpl) {
  // clang-format off
  nofralloc;
  lis r4, 0x8033;
  li r3, 3;
  lwz r12, 0x5e98(r4);
  li r4, 0;
  mtctr r12;
  bctr;
  // clang-format on
}

// Symbol: bta_dm_disc_result
// PAL: 0x80133238..0x80133288
MARK_BINARY_BLOB(bta_dm_disc_result, 0x80133238, 0x80133288);
asm UNKNOWN_FUNCTION(bta_dm_disc_result) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r4, 0x8033;
  stw r0, 0x14(r1);
  lwz r12, 0x5e98(r4);
  addi r4, r3, 8;
  li r3, 2;
  mtctr r12;
  bctrl;
  li r3, 0x110;
  bl GKI_getbuf;
  cmpwi r3, 0;
  beq lbl_80133278;
  li r0, 0x207;
  sth r0, 0(r3);
  bl bta_sys_sendmsg;
lbl_80133278:
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: bta_dm_search_result
// PAL: 0x80133288..0x80133310
MARK_BINARY_BLOB(bta_dm_search_result, 0x80133288, 0x80133310);
asm UNKNOWN_FUNCTION(bta_dm_search_result) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  lwz r0, 0x108(r3);
  cmpwi r0, 0;
  beq lbl_801332b8;
  lis r5, 0x8033;
  addi r4, r3, 8;
  lwz r12, 0x5e98(r5);
  li r3, 2;
  mtctr r12;
  bctrl;
lbl_801332b8:
  lis r6, 0x8033;
  addi r6, r6, 0x5e98;
  lbz r0, 0x78(r6);
  cmpwi r0, 0;
  bne lbl_801332dc;
  li r0, 0;
  stb r0, 0x78(r6);
  bl bta_dm_discover_next_device;
  b lbl_80133300;
lbl_801332dc:
  lis r5, 0x8013;
  li r0, 1;
  addi r5, r5, 0x3310;
  stb r0, 0x79(r6);
  addi r3, r6, 0x40;
  li r4, 0;
  stw r5, 0x48(r6);
  li r5, 0xbb8;
  bl bta_sys_start_timer;
lbl_80133300:
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: bta_dm_search_timer_cback
// PAL: 0x80133310..0x8013335c
MARK_BINARY_BLOB(bta_dm_search_timer_cback, 0x80133310, 0x8013335c);
asm UNKNOWN_FUNCTION(bta_dm_search_timer_cback) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  lbz r0, -0x6610(r13);
  cmplwi r0, 4;
  blt lbl_80133338;
  lis r4, 0x8028;
  li r3, 0x503;
  addi r4, r4, 0x28e8;
  bl LogMsg_0;
lbl_80133338:
  lis r3, 0x8033;
  li r0, 0;
  addi r3, r3, 0x5e98;
  stb r0, 0x78(r3);
  bl bta_dm_discover_next_device;
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: bta_dm_free_sdp_db
// PAL: 0x8013335c..0x801333a0
MARK_BINARY_BLOB(bta_dm_free_sdp_db, 0x8013335c, 0x801333a0);
asm UNKNOWN_FUNCTION(bta_dm_free_sdp_db) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  lis r31, 0x8033;
  addi r31, r31, 0x5e98;
  lwz r3, 0x14(r31);
  cmpwi r3, 0;
  beq lbl_8013338c;
  bl GKI_freebuf;
  li r0, 0;
  stw r0, 0x14(r31);
lbl_8013338c:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: bta_dm_queue_search
// PAL: 0x801333a0..0x801333e8
MARK_BINARY_BLOB(bta_dm_queue_search, 0x801333a0, 0x801333e8);
asm UNKNOWN_FUNCTION(bta_dm_queue_search) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  li r3, 0x1c;
  bl GKI_getbuf;
  lis r6, 0x8033;
  mr r4, r31;
  addi r6, r6, 0x5e98;
  li r5, 0x1c;
  stw r3, 0x74(r6);
  bl memcpy;
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: bta_dm_queue_disc
// PAL: 0x801333e8..0x80133430
MARK_BINARY_BLOB(bta_dm_queue_disc, 0x801333e8, 0x80133430);
asm UNKNOWN_FUNCTION(bta_dm_queue_disc) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  li r3, 0x18;
  bl GKI_getbuf;
  lis r6, 0x8033;
  mr r4, r31;
  addi r6, r6, 0x5e98;
  li r5, 0x18;
  stw r3, 0x74(r6);
  bl memcpy;
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: bta_dm_search_clear_queue
// PAL: 0x80133430..0x80133474
MARK_BINARY_BLOB(bta_dm_search_clear_queue, 0x80133430, 0x80133474);
asm UNKNOWN_FUNCTION(bta_dm_search_clear_queue) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  lis r31, 0x8033;
  addi r31, r31, 0x5e98;
  lwz r3, 0x74(r31);
  cmpwi r3, 0;
  beq lbl_80133460;
  bl GKI_freebuf;
  li r0, 0;
  stw r0, 0x74(r31);
lbl_80133460:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: bta_dm_search_cancel_cmpl
// PAL: 0x80133474..0x801334b8
MARK_BINARY_BLOB(bta_dm_search_cancel_cmpl, 0x80133474, 0x801334b8);
asm UNKNOWN_FUNCTION(bta_dm_search_cancel_cmpl) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  lis r31, 0x8033;
  addi r31, r31, 0x5e98;
  lwz r3, 0x74(r31);
  cmpwi r3, 0;
  beq lbl_801334a4;
  bl bta_sys_sendmsg;
  li r0, 0;
  stw r0, 0x74(r31);
lbl_801334a4:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: bta_dm_search_cancel_transac_cmpl
// PAL: 0x801334b8..0x80133514
MARK_BINARY_BLOB(bta_dm_search_cancel_transac_cmpl, 0x801334b8, 0x80133514);
asm UNKNOWN_FUNCTION(bta_dm_search_cancel_transac_cmpl) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  lis r31, 0x8033;
  addi r31, r31, 0x5e98;
  lwz r3, 0x14(r31);
  cmpwi r3, 0;
  beq lbl_801334e8;
  bl GKI_freebuf;
  li r0, 0;
  stw r0, 0x14(r31);
lbl_801334e8:
  lis r4, 0x8033;
  li r3, 4;
  lwz r12, 0x5e98(r4);
  li r4, 0;
  mtctr r12;
  bctrl;
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: bta_dm_search_cancel_notify
// PAL: 0x80133514..0x8013352c
MARK_BINARY_BLOB(bta_dm_search_cancel_notify, 0x80133514, 0x8013352c);
asm UNKNOWN_FUNCTION(bta_dm_search_cancel_notify) {
  // clang-format off
  nofralloc;
  lis r4, 0x8033;
  li r3, 4;
  lwz r12, 0x5e98(r4);
  li r4, 0;
  mtctr r12;
  bctr;
  // clang-format on
}

// Symbol: bta_dm_find_services
// PAL: 0x8013352c..0x801336cc
MARK_BINARY_BLOB(bta_dm_find_services, 0x8013352c, 0x801336cc);
asm UNKNOWN_FUNCTION(bta_dm_find_services) {
  // clang-format off
  nofralloc;
  stwu r1, -0x50(r1);
  mflr r0;
  stw r0, 0x54(r1);
  addi r11, r1, 0x50;
  bl _savegpr_23;
  lhz r4, unk_80388678;
  lis r26, 0x8033;
  lhz r0, unk_8038867a;
  lis r25, 0x8025;
  sth r4, 8(r1);
  mr r30, r3;
  addi r25, r25, -14440;
  addi r26, r26, 0x5e98;
  sth r0, 0xa(r1);
  li r31, 1;
  li r23, 1;
  li r24, 2;
  lis r27, 0x8013;
  li r28, 0;
  li r29, 0x17;
  b lbl_80133638;
lbl_80133580:
  lwz r3, 0xc(r26);
  slw r0, r23, r0;
  and. r0, r3, r0;
  beq lbl_8013362c;
  li r3, 0xfa;
  bl GKI_getbuf;
  cmpwi r3, 0;
  stw r3, 0x14(r26);
  beq lbl_8013362c;
  lbz r3, 0x70(r26);
  lwz r4, 0xc(r26);
  slwi r0, r3, 1;
  slw r3, r23, r3;
  lhzx r0, r25, r0;
  andc r3, r4, r3;
  stw r3, 0xc(r26);
  cmplwi r0, 0x1200;
  sth r24, 0xc(r1);
  sth r0, 0x10(r1);
  bne lbl_801335d4;
  li r31, 2;
lbl_801335d4:
  lwz r3, 0x14(r26);
  mr r7, r31;
  addi r6, r1, 0xc;
  addi r8, r1, 8;
  li r4, 0xfa;
  li r5, 1;
  bl SDP_InitDiscoveryDb;
  lwz r4, 0x14(r26);
  mr r3, r30;
  addi r5, r27, 0x37ac;
  bl SDP_ServiceSearchAttributeRequest;
  clrlwi. r0, r3, 0x18;
  bne lbl_8013361c;
  lwz r3, 0x14(r26);
  bl GKI_freebuf;
  stw r28, 0x14(r26);
  stb r29, 0x70(r26);
  b lbl_8013362c;
lbl_8013361c:
  lbz r3, 0x70(r26);
  addi r0, r3, 1;
  stb r0, 0x70(r26);
  b lbl_801336b4;
lbl_8013362c:
  lbz r3, 0x70(r26);
  addi r0, r3, 1;
  stb r0, 0x70(r26);
lbl_80133638:
  lbz r0, 0x70(r26);
  cmplwi r0, 0x17;
  blt lbl_80133580;
  blt lbl_801336b4;
  li r3, 0x110;
  bl GKI_getbuf;
  cmpwi r3, 0;
  mr r24, r3;
  beq lbl_801336b4;
  li r0, 0x208;
  addi r4, r26, 0x1a;
  sth r0, 0(r3);
  lwz r0, 0x10(r26);
  stw r0, 0x108(r3);
  addi r3, r3, 8;
  bl bdcpy;
  lbz r0, 0x20(r26);
  addi r23, r26, 0x20;
  extsb. r0, r0;
  bne lbl_8013369c;
  addi r3, r26, 0x1a;
  bl BTM_SecReadDevName;
  cmpwi r3, 0;
  beq lbl_8013369c;
  mr r23, r3;
lbl_8013369c:
  mr r4, r23;
  addi r3, r24, 0xe;
  li r5, 0x20;
  bl strncpy;
  mr r3, r24;
  bl bta_sys_sendmsg;
lbl_801336b4:
  addi r11, r1, 0x50;
  bl _restgpr_23;
  lwz r0, 0x54(r1);
  mtlr r0;
  addi r1, r1, 0x50;
  blr;
  // clang-format on
}

// Symbol: bta_dm_discover_next_device
// PAL: 0x801336cc..0x801337ac
MARK_BINARY_BLOB(bta_dm_discover_next_device, 0x801336cc, 0x801337ac);
asm UNKNOWN_FUNCTION(bta_dm_discover_next_device) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  stw r30, 8(r1);
  lis r30, 0x8033;
  addi r30, r30, 0x5e98;
  lwz r3, 4(r30);
  bl BTM_InqDbNext;
  cmpwi r3, 0;
  stw r3, 4(r30);
  beq lbl_80133770;
  addi r3, r3, 2;
  bl BTM_IsAclConnectionUp;
  clrlwi. r0, r3, 0x18;
  beq lbl_80133718;
  li r0, 0;
  stb r0, 0x78(r30);
  b lbl_80133720;
lbl_80133718:
  li r0, 1;
  stb r0, 0x78(r30);
lbl_80133720:
  lis r31, 0x8033;
  lis r3, 0x8013;
  addi r31, r31, 0x5e98;
  li r30, 0;
  stb r30, 0x79(r31);
  addi r3, r3, 0x38d0;
  bl BTM_SecAddRmtNameNotifyCallback;
  lwz r0, 8(r31);
  addi r3, r31, 0x1a;
  lwz r4, 4(r31);
  stb r30, 0x70(r31);
  addi r4, r4, 2;
  stw r30, 0x10(r31);
  stb r30, 0x20(r31);
  stw r0, 0xc(r31);
  bl bdcpy;
  lwz r3, 4(r31);
  addi r3, r3, 2;
  bl bta_dm_find_services;
  b lbl_80133794;
lbl_80133770:
  li r0, 0;
  li r3, 0x110;
  stw r0, 8(r30);
  bl GKI_getbuf;
  cmpwi r3, 0;
  beq lbl_80133794;
  li r0, 0x207;
  sth r0, 0(r3);
  bl bta_sys_sendmsg;
lbl_80133794:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: bta_dm_sdp_callback
// PAL: 0x801337ac..0x801337f4
MARK_BINARY_BLOB(bta_dm_sdp_callback, 0x801337ac, 0x801337f4);
asm UNKNOWN_FUNCTION(bta_dm_sdp_callback) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  li r3, 0xa;
  bl GKI_getbuf;
  cmpwi r3, 0;
  beq lbl_801337e0;
  li r0, 0x206;
  sth r0, 0(r3);
  sth r31, 8(r3);
  bl bta_sys_sendmsg;
lbl_801337e0:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: bta_dm_inq_results_cb
// PAL: 0x801337f4..0x80133884
MARK_BINARY_BLOB(bta_dm_inq_results_cb, 0x801337f4, 0x80133884);
asm UNKNOWN_FUNCTION(bta_dm_inq_results_cb) {
  // clang-format off
  nofralloc;
  stwu r1, -0x120(r1);
  mflr r0;
  stw r0, 0x124(r1);
  stw r31, 0x11c(r1);
  mr r31, r3;
  addi r3, r1, 8;
  addi r4, r31, 2;
  bl bdcpy;
  addi r3, r1, 0xe;
  addi r4, r31, 8;
  li r5, 3;
  bl memcpy;
  lbz r0, 0xe(r31);
  addi r3, r31, 2;
  stb r0, 0x11(r1);
  bl BTM_InqDbRead;
  cmpwi r3, 0;
  mr r31, r3;
  beq lbl_80133848;
  li r0, 0;
  stb r0, 0x12(r1);
lbl_80133848:
  lis r3, 0x8033;
  addi r4, r1, 8;
  lwz r12, 0x5e98(r3);
  li r3, 0;
  mtctr r12;
  bctrl;
  cmpwi r31, 0;
  beq lbl_80133870;
  lbz r0, 0x12(r1);
  stb r0, 0x10(r31);
lbl_80133870:
  lwz r0, 0x124(r1);
  lwz r31, 0x11c(r1);
  mtlr r0;
  addi r1, r1, 0x120;
  blr;
  // clang-format on
}

// Symbol: bta_dm_inq_cmpl_cb
// PAL: 0x80133884..0x801338d0
MARK_BINARY_BLOB(bta_dm_inq_cmpl_cb, 0x80133884, 0x801338d0);
asm UNKNOWN_FUNCTION(bta_dm_inq_cmpl_cb) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  li r3, 0x110;
  bl GKI_getbuf;
  cmpwi r3, 0;
  beq lbl_801338bc;
  li r0, 0x203;
  sth r0, 0(r3);
  lbz r0, 1(r31);
  stb r0, 8(r3);
  bl bta_sys_sendmsg;
lbl_801338bc:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: bta_dm_service_search_remname_cback
// PAL: 0x801338d0..0x80133910
MARK_BINARY_BLOB(bta_dm_service_search_remname_cback, 0x801338d0, 0x80133910);
asm UNKNOWN_FUNCTION(bta_dm_service_search_remname_cback) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r3, 0x8033;
  mr r4, r5;
  addi r3, r3, 0x5e98;
  stw r0, 0x14(r1);
  li r5, 0x1f;
  addi r3, r3, 0x20;
  bl strncpy;
  lis r3, 0x8013;
  addi r3, r3, 0x38d0;
  bl BTM_SecDeleteRmtNameNotifyCallback;
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: bta_dm_remname_cback
// PAL: 0x80133910..0x8013399c
MARK_BINARY_BLOB(bta_dm_remname_cback, 0x80133910, 0x8013399c);
asm UNKNOWN_FUNCTION(bta_dm_remname_cback) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  lis r31, 0x8033;
  addi r31, r31, 0x5e98;
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  mr r29, r3;
  addi r3, r31, 0x58;
  bl bta_sys_stop_timer;
  li r3, 0x110;
  bl GKI_getbuf;
  cmpwi r3, 0;
  mr r30, r3;
  beq lbl_80133980;
  lwz r4, 4(r31);
  addi r3, r3, 8;
  addi r4, r4, 2;
  bl bdcpy;
  addi r3, r30, 0xe;
  addi r4, r29, 4;
  li r5, 0x20;
  bl strncpy;
  li r0, 0x204;
  mr r3, r30;
  sth r0, 0(r30);
  bl bta_sys_sendmsg;
lbl_80133980:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: bta_dm_disc_remname_cback
// PAL: 0x8013399c..0x80133a24
MARK_BINARY_BLOB(bta_dm_disc_remname_cback, 0x8013399c, 0x80133a24);
asm UNKNOWN_FUNCTION(bta_dm_disc_remname_cback) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  lis r31, 0x8033;
  addi r31, r31, 0x5e98;
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  mr r29, r3;
  addi r3, r31, 0x58;
  bl bta_sys_stop_timer;
  li r3, 0x110;
  bl GKI_getbuf;
  cmpwi r3, 0;
  mr r30, r3;
  beq lbl_80133a08;
  addi r3, r3, 8;
  addi r4, r31, 0x1a;
  bl bdcpy;
  addi r3, r30, 0xe;
  addi r4, r29, 4;
  li r5, 0x20;
  bl strncpy;
  li r0, 0x204;
  mr r3, r30;
  sth r0, 0(r30);
  bl bta_sys_sendmsg;
lbl_80133a08:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: bta_dm_cancel_rmt_name
// PAL: 0x80133a24..0x80133a28
MARK_BINARY_BLOB(bta_dm_cancel_rmt_name, 0x80133a24, 0x80133a28);
asm UNKNOWN_FUNCTION(bta_dm_cancel_rmt_name) {
  // clang-format off
  nofralloc;
  b BTM_CancelRemoteDeviceName;
  // clang-format on
}

// Symbol: bta_dm_authorize_cback
// PAL: 0x80133a28..0x80133af0
MARK_BINARY_BLOB(bta_dm_authorize_cback, 0x80133a28, 0x80133af0);
asm UNKNOWN_FUNCTION(bta_dm_authorize_cback) {
  // clang-format off
  nofralloc;
  stwu r1, -0x130(r1);
  mflr r0;
  mr r4, r3;
  stw r0, 0x134(r1);
  addi r3, r1, 8;
  stw r31, 0x12c(r1);
  li r31, 1;
  stw r30, 0x128(r1);
  mr r30, r7;
  stw r29, 0x124(r1);
  mr r29, r5;
  bl bdcpy;
  mr r4, r29;
  addi r3, r1, 0xe;
  li r5, 0x20;
  bl strncpy;
  lis r3, 0x8025;
  li r0, 0x17;
  addi r3, r3, -14392;
  mtctr r0;
lbl_80133a78:
  rlwinm r0, r31, 2, 0x16, 0x1d;
  lwzx r0, r3, r0;
  cmplw r30, r0;
  bne lbl_80133a90;
  stb r31, 0x106(r1);
  b lbl_80133a98;
lbl_80133a90:
  addi r31, r31, 1;
  bdnz lbl_80133a78;
lbl_80133a98:
  lis r3, 0x8033;
  addi r3, r3, 0x5f14;
  lwz r12, 0x50(r3);
  cmpwi r12, 0;
  beq lbl_80133ad0;
  clrlwi r0, r31, 0x18;
  cmplwi r0, 0x17;
  bgt lbl_80133ad0;
  addi r4, r1, 8;
  li r3, 4;
  mtctr r12;
  bctrl;
  li r3, 1;
  b lbl_80133ad4;
lbl_80133ad0:
  li r3, 0xb;
lbl_80133ad4:
  lwz r0, 0x134(r1);
  lwz r31, 0x12c(r1);
  lwz r30, 0x128(r1);
  lwz r29, 0x124(r1);
  mtlr r0;
  addi r1, r1, 0x130;
  blr;
  // clang-format on
}

// Symbol: bta_dm_pinname_cback
// PAL: 0x80133af0..0x80133bb0
MARK_BINARY_BLOB(bta_dm_pinname_cback, 0x80133af0, 0x80133bb0);
asm UNKNOWN_FUNCTION(bta_dm_pinname_cback) {
  // clang-format off
  nofralloc;
  stwu r1, -0x120(r1);
  mflr r0;
  stw r0, 0x124(r1);
  stw r31, 0x11c(r1);
  lis r31, 0x8033;
  addi r31, r31, 0x5f14;
  stw r30, 0x118(r1);
  mr r30, r3;
  addi r3, r1, 8;
  addi r4, r31, 0xf8;
  bl bdcpy;
  lbz r4, 0xfe(r31);
  cmpwi r30, 0;
  lbz r3, 0xff(r31);
  lbz r0, 0x100(r31);
  stb r4, 0x106(r1);
  stb r3, 0x107(r1);
  stb r0, 0x108(r1);
  beq lbl_80133b74;
  lhz r0, 0(r30);
  cmpwi r0, 0;
  bne lbl_80133b74;
  lhz r0, 2(r30);
  addi r3, r1, 0xe;
  addi r4, r30, 4;
  li r5, 0x20;
  cmplwi r0, 0x20;
  bge lbl_80133b64;
  mr r5, r0;
lbl_80133b64:
  bl memcpy;
  li r0, 0;
  stb r0, 0x2e(r1);
  b lbl_80133b7c;
lbl_80133b74:
  li r0, 0;
  stb r0, 0xe(r1);
lbl_80133b7c:
  lis r5, 0x8033;
  addi r4, r1, 8;
  addi r5, r5, 0x5f14;
  li r3, 2;
  lwz r12, 0x50(r5);
  mtctr r12;
  bctrl;
  lwz r0, 0x124(r1);
  lwz r31, 0x11c(r1);
  lwz r30, 0x118(r1);
  mtlr r0;
  addi r1, r1, 0x120;
  blr;
  // clang-format on
}

// Symbol: bta_dm_pin_cback
// PAL: 0x80133bb0..0x80133ce0
MARK_BINARY_BLOB(bta_dm_pin_cback, 0x80133bb0, 0x80133ce0);
asm UNKNOWN_FUNCTION(bta_dm_pin_cback) {
  // clang-format off
  nofralloc;
  stwu r1, -0x130(r1);
  mflr r0;
  stw r0, 0x134(r1);
  stw r31, 0x12c(r1);
  lis r31, 0x8033;
  addi r31, r31, 0x5f14;
  stw r30, 0x128(r1);
  mr r30, r5;
  stw r29, 0x124(r1);
  mr r29, r4;
  stw r28, 0x120(r1);
  mr r28, r3;
  lwz r0, 0x50(r31);
  cmpwi r0, 0;
  bne lbl_80133bf4;
  li r3, 0xb;
  b lbl_80133cc0;
lbl_80133bf4:
  lbz r0, 0(r5);
  cmpwi r0, 0;
  bne lbl_80133c64;
  mr r4, r28;
  addi r3, r31, 0xf8;
  bl bdcpy;
  lbz r0, 0(r29);
  lis r4, 0x8013;
  mr r3, r28;
  stb r0, 0xfe(r31);
  addi r4, r4, 0x3af0;
  lbz r0, 1(r29);
  stb r0, 0xff(r31);
  lbz r0, 2(r29);
  stb r0, 0x100(r31);
  bl BTM_ReadRemoteDeviceName;
  clrlwi r0, r3, 0x18;
  cmplwi r0, 1;
  bne lbl_80133c48;
  li r3, 1;
  b lbl_80133cc0;
lbl_80133c48:
  lbz r0, -0x6610(r13);
  cmplwi r0, 2;
  blt lbl_80133c64;
  lis r4, 0x8028;
  li r3, 0x501;
  addi r4, r4, 0x2908;
  bl LogMsg_0;
lbl_80133c64:
  mr r4, r28;
  addi r3, r1, 8;
  bl bdcpy;
  lbz r0, 0(r29);
  mr r4, r30;
  addi r3, r1, 0xe;
  li r5, 0x20;
  stb r0, 0x106(r1);
  lbz r0, 1(r29);
  stb r0, 0x107(r1);
  lbz r0, 2(r29);
  stb r0, 0x108(r1);
  bl strncpy;
  lis r3, 0x8033;
  li r0, 0;
  addi r3, r3, 0x5f14;
  stb r0, 0x2e(r1);
  lwz r12, 0x50(r3);
  addi r4, r1, 8;
  li r3, 2;
  mtctr r12;
  bctrl;
  li r3, 1;
lbl_80133cc0:
  lwz r0, 0x134(r1);
  lwz r31, 0x12c(r1);
  lwz r30, 0x128(r1);
  lwz r29, 0x124(r1);
  lwz r28, 0x120(r1);
  mtlr r0;
  addi r1, r1, 0x130;
  blr;
  // clang-format on
}

// Symbol: bta_dm_link_key_request_cback
// PAL: 0x80133ce0..0x80133ce8
MARK_BINARY_BLOB(bta_dm_link_key_request_cback, 0x80133ce0, 0x80133ce8);
asm UNKNOWN_FUNCTION(bta_dm_link_key_request_cback) {
  // clang-format off
  nofralloc;
  li r3, 0xb;
  blr;
  // clang-format on
}

// Symbol: bta_dm_new_link_key_cback
// PAL: 0x80133ce8..0x80133d84
MARK_BINARY_BLOB(bta_dm_new_link_key_cback, 0x80133ce8, 0x80133d84);
asm UNKNOWN_FUNCTION(bta_dm_new_link_key_cback) {
  // clang-format off
  nofralloc;
  stwu r1, -0x120(r1);
  mflr r0;
  mr r4, r3;
  stw r0, 0x124(r1);
  addi r3, r1, 8;
  stw r31, 0x11c(r1);
  mr r31, r6;
  stw r30, 0x118(r1);
  mr r30, r5;
  bl bdcpy;
  mr r4, r30;
  addi r3, r1, 0xe;
  li r5, 0x1f;
  bl memcpy;
  li r0, 0;
  mr r4, r31;
  stb r0, 0x2d(r1);
  addi r3, r1, 0x107;
  li r5, 0x10;
  bl memcpy;
  lis r3, 0x8033;
  li r0, 1;
  addi r3, r3, 0x5f14;
  stb r0, 0x106(r1);
  lwz r12, 0x50(r3);
  stb r0, 0x117(r1);
  cmpwi r12, 0;
  beq lbl_80133d68;
  addi r4, r1, 8;
  li r3, 3;
  mtctr r12;
  bctrl;
lbl_80133d68:
  lwz r31, 0x11c(r1);
  li r3, 1;
  lwz r30, 0x118(r1);
  lwz r0, 0x124(r1);
  mtlr r0;
  addi r1, r1, 0x120;
  blr;
  // clang-format on
}

// Symbol: bta_dm_authentication_complete_cback
// PAL: 0x80133d84..0x80133e08
MARK_BINARY_BLOB(bta_dm_authentication_complete_cback, 0x80133d84, 0x80133e08);
asm UNKNOWN_FUNCTION(bta_dm_authentication_complete_cback) {
  // clang-format off
  nofralloc;
  stwu r1, -0x120(r1);
  mflr r0;
  cmpwi r6, 0;
  stw r0, 0x124(r1);
  stw r31, 0x11c(r1);
  mr r31, r5;
  beq lbl_80133df0;
  mr r4, r3;
  addi r3, r1, 8;
  bl bdcpy;
  mr r4, r31;
  addi r3, r1, 0xe;
  li r5, 0x1f;
  bl memcpy;
  lis r3, 0x8033;
  li r0, 0;
  addi r3, r3, 0x5f14;
  stb r0, 0x2d(r1);
  lwz r12, 0x50(r3);
  stb r0, 0x117(r1);
  cmpwi r12, 0;
  stb r0, 0x106(r1);
  beq lbl_80133df0;
  addi r4, r1, 8;
  li r3, 3;
  mtctr r12;
  bctrl;
lbl_80133df0:
  lwz r31, 0x11c(r1);
  li r3, 0;
  lwz r0, 0x124(r1);
  mtlr r0;
  addi r1, r1, 0x120;
  blr;
  // clang-format on
}

// Symbol: bta_dm_local_addr_cback
// PAL: 0x80133e08..0x80133e30
MARK_BINARY_BLOB(bta_dm_local_addr_cback, 0x80133e08, 0x80133e30);
asm UNKNOWN_FUNCTION(bta_dm_local_addr_cback) {
  // clang-format off
  nofralloc;
  lis r4, 0x8033;
  addi r4, r4, 0x5f14;
  lwz r12, 0x50(r4);
  cmpwi r12, 0;
  beqlr;
  mr r4, r3;
  li r3, 0;
  mtctr r12;
  bctr;
  blr;
  // clang-format on
}

// Symbol: bta_dm_signal_strength
// PAL: 0x80133e30..0x80133e6c
MARK_BINARY_BLOB(bta_dm_signal_strength, 0x80133e30, 0x80133e6c);
asm UNKNOWN_FUNCTION(bta_dm_signal_strength) {
  // clang-format off
  nofralloc;
  lbz r0, 0xc(r3);
  cmpwi r0, 0;
  beq lbl_80133e5c;
  lis r4, 0x8033;
  lbz r0, 8(r3);
  addi r4, r4, 0x5f14;
  stb r0, 0x6c(r4);
  lhz r0, 0xa(r3);
  li r3, 0;
  sth r0, 0x70(r4);
  b bta_dm_signal_strength_timer_cback;
lbl_80133e5c:
  lis r3, 0x8033;
  addi r3, r3, 0x5f14;
  addi r3, r3, 0x54;
  b bta_sys_stop_timer;
  // clang-format on
}

// Symbol: bta_dm_signal_strength_timer_cback
// PAL: 0x80133e6c..0x80133f60
MARK_BINARY_BLOB(bta_dm_signal_strength_timer_cback, 0x80133e6c, 0x80133f60);
asm UNKNOWN_FUNCTION(bta_dm_signal_strength_timer_cback) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  lis r3, 0x8033;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  addi r31, r3, 0x5f14;
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  lbz r0, 0x6c(r31);
  clrlwi. r0, r0, 0x1f;
  beq lbl_80133ecc;
  li r29, 0;
  lis r30, 0x8013;
  b lbl_80133ebc;
lbl_80133ea4:
  clrlwi r0, r29, 0x18;
  addi r4, r30, 0x426c;
  mulli r0, r0, 0xb;
  add r3, r31, r0;
  bl BTM_ReadRSSI;
  addi r29, r29, 1;
lbl_80133ebc:
  lbz r0, 0x4d(r31);
  clrlwi r3, r29, 0x18;
  cmplw r3, r0;
  blt lbl_80133ea4;
lbl_80133ecc:
  lis r3, 0x8033;
  addi r30, r3, 0x5f14;
  lbz r0, 0x6c(r30);
  rlwinm. r0, r0, 0, 0x1e, 0x1e;
  beq lbl_80133f14;
  li r29, 0;
  lis r31, 0x8013;
  b lbl_80133f04;
lbl_80133eec:
  clrlwi r0, r29, 0x18;
  addi r4, r31, 0x42d8;
  mulli r0, r0, 0xb;
  add r3, r30, r0;
  bl BTM_ReadLinkQuality;
  addi r29, r29, 1;
lbl_80133f04:
  lbz r0, 0x4d(r30);
  clrlwi r3, r29, 0x18;
  cmplw r3, r0;
  blt lbl_80133eec;
lbl_80133f14:
  lis r7, 0x8033;
  addi r7, r7, 0x5f14;
  lhz r0, 0x70(r7);
  cmpwi r0, 0;
  beq lbl_80133f44;
  lis r6, 0x8013;
  addi r3, r7, 0x54;
  addi r6, r6, 0x3e6c;
  li r4, 0;
  mulli r5, r0, 0x3e8;
  stw r6, 0x5c(r7);
  bl bta_sys_start_timer;
lbl_80133f44:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: bta_dm_acl_change_cback
// PAL: 0x80133f60..0x80133fd0
MARK_BINARY_BLOB(bta_dm_acl_change_cback, 0x80133f60, 0x80133fd0);
asm UNKNOWN_FUNCTION(bta_dm_acl_change_cback) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  mr r30, r7;
  stw r29, 0x14(r1);
  mr r29, r3;
  li r3, 0x12;
  bl GKI_getbuf;
  cmpwi r3, 0;
  mr r31, r3;
  beq lbl_80133fb4;
  mr r4, r29;
  addi r3, r3, 0xb;
  bl bdcpy;
  stb r30, 0xa(r31);
  li r0, 0x105;
  mr r3, r31;
  sth r0, 0(r31);
  bl bta_sys_sendmsg;
lbl_80133fb4:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: bta_dm_acl_change
// PAL: 0x80133fd0..0x80134250
MARK_BINARY_BLOB(bta_dm_acl_change, 0x80133fd0, 0x80134250);
asm UNKNOWN_FUNCTION(bta_dm_acl_change) {
  // clang-format off
  nofralloc;
  stwu r1, -0x130(r1);
  mflr r0;
  stw r0, 0x134(r1);
  stw r31, 0x12c(r1);
  addi r31, r3, 0xb;
  stw r30, 0x128(r1);
  stw r29, 0x124(r1);
  lbz r0, 0xa(r3);
  cmpwi r0, 0;
  beq lbl_801340b4;
  lis r3, 0x8033;
  li r29, 0;
  addi r30, r3, 0x5f14;
  b lbl_80134028;
lbl_80134008:
  clrlwi r0, r29, 0x18;
  mr r4, r31;
  mulli r0, r0, 0xb;
  add r3, r30, r0;
  bl bdcmp;
  cmpwi r3, 0;
  beq lbl_80134038;
  addi r29, r29, 1;
lbl_80134028:
  lbz r0, 0x4d(r30);
  clrlwi r3, r29, 0x18;
  cmplw r3, r0;
  blt lbl_80134008;
lbl_80134038:
  lis r30, 0x8033;
  clrlwi r0, r29, 0x18;
  addi r30, r30, 0x5f14;
  lbz r3, 0x4d(r30);
  cmplw r0, r3;
  bne lbl_8013406c;
  mulli r0, r3, 0xb;
  mr r4, r31;
  add r3, r30, r0;
  bl bdcpy;
  lbz r3, 0x4d(r30);
  addi r0, r3, 1;
  stb r0, 0x4d(r30);
lbl_8013406c:
  clrlwi r0, r29, 0x18;
  lis r30, 0x8033;
  mulli r4, r0, 0xb;
  li r3, 1;
  addi r30, r30, 0x5f14;
  li r0, 0;
  add r5, r30, r4;
  stb r3, 6(r5);
  mr r4, r31;
  addi r3, r1, 8;
  stb r0, 7(r5);
  bl bdcpy;
  lwz r12, 0x50(r30);
  addi r4, r1, 8;
  li r3, 5;
  mtctr r12;
  bctrl;
  b lbl_80134234;
lbl_801340b4:
  lis r3, 0x8033;
  li r29, 0;
  addi r30, r3, 0x5f14;
  b lbl_80134128;
lbl_801340c4:
  clrlwi r0, r29, 0x18;
  mr r4, r31;
  mulli r0, r0, 0xb;
  add r3, r30, r0;
  bl bdcmp;
  cmpwi r3, 0;
  bne lbl_80134124;
  lis r3, 0x8033;
  addi r30, r3, 0x5f14;
  b lbl_80134110;
lbl_801340ec:
  clrlwi r3, r29, 0x18;
  li r5, 0xb;
  addi r0, r3, 1;
  mulli r3, r3, 0xb;
  mulli r0, r0, 0xb;
  add r3, r30, r3;
  add r4, r30, r0;
  bl memcpy;
  addi r29, r29, 1;
lbl_80134110:
  lbz r0, 0x4d(r30);
  clrlwi r3, r29, 0x18;
  cmplw r3, r0;
  blt lbl_801340ec;
  b lbl_80134138;
lbl_80134124:
  addi r29, r29, 1;
lbl_80134128:
  lbz r0, 0x4d(r30);
  clrlwi r3, r29, 0x18;
  cmplw r3, r0;
  blt lbl_801340c4;
lbl_80134138:
  lis r4, 0x8033;
  lis r30, 0x8033;
  addi r4, r4, 0x5f14;
  addi r30, r30, 0x5e98;
  lbz r3, 0x4d(r4);
  lbz r0, 0x78(r30);
  addi r3, r3, -1;
  cmpwi r0, 0;
  stb r3, 0x4d(r4);
  beq lbl_801341b8;
  mr r4, r31;
  addi r3, r30, 0x1a;
  bl bdcmp;
  cmpwi r3, 0;
  bne lbl_801341b8;
  lbz r0, 0x79(r30);
  li r3, 0;
  stb r3, 0x78(r30);
  cmpwi r0, 0;
  beq lbl_801341b8;
  lbz r0, -0x6610(r13);
  cmplwi r0, 4;
  blt lbl_801341a4;
  lis r4, 0x8028;
  li r3, 0x503;
  addi r4, r4, 0x2948;
  bl LogMsg_0;
lbl_801341a4:
  lis r3, 0x8033;
  addi r3, r3, 0x5e98;
  addi r3, r3, 0x40;
  bl bta_sys_stop_timer;
  bl bta_dm_discover_next_device;
lbl_801341b8:
  lis r30, 0x8033;
  addi r30, r30, 0x5f14;
  lbz r0, 0x72(r30);
  cmpwi r0, 0;
  beq lbl_80134204;
  bl BTM_GetNumAclLinks;
  clrlwi. r0, r3, 0x10;
  bne lbl_80134204;
  li r0, 0;
  addi r3, r30, 0x74;
  stb r0, 0x72(r30);
  bl bta_sys_stop_timer;
  lis r5, 0x8013;
  addi r3, r30, 0x74;
  addi r5, r5, 0x4250;
  li r4, 0;
  stw r5, 0x7c(r30);
  li r5, 0x3e8;
  bl bta_sys_start_timer;
lbl_80134204:
  mr r4, r31;
  addi r3, r1, 8;
  bl bdcpy;
  bl btm_get_acl_disc_reason_code;
  lis r5, 0x8033;
  stb r3, 0xe(r1);
  addi r5, r5, 0x5f14;
  addi r4, r1, 8;
  lwz r12, 0x50(r5);
  li r3, 6;
  mtctr r12;
  bctrl;
lbl_80134234:
  lwz r0, 0x134(r1);
  lwz r31, 0x12c(r1);
  lwz r30, 0x128(r1);
  lwz r29, 0x124(r1);
  mtlr r0;
  addi r1, r1, 0x130;
  blr;
  // clang-format on
}

// Symbol: bta_dm_disable_conn_down_timer_cback
// PAL: 0x80134250..0x8013426c
MARK_BINARY_BLOB(bta_dm_disable_conn_down_timer_cback, 0x80134250, 0x8013426c);
asm UNKNOWN_FUNCTION(bta_dm_disable_conn_down_timer_cback) {
  // clang-format off
  nofralloc;
  lis r5, 0x8033;
  li r3, 1;
  addi r5, r5, 0x5f14;
  li r4, 0;
  lwz r12, 0x50(r5);
  mtctr r12;
  bctr;
  // clang-format on
}

// Symbol: bta_dm_rssi_cback
// PAL: 0x8013426c..0x801342d8
MARK_BINARY_BLOB(bta_dm_rssi_cback, 0x8013426c, 0x801342d8);
asm UNKNOWN_FUNCTION(bta_dm_rssi_cback) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r3;
  lbz r0, 0(r3);
  cmpwi r0, 0;
  bne lbl_801342c4;
  addi r3, r1, 8;
  addi r4, r31, 3;
  bl bdcpy;
  li r0, 1;
  lis r3, 0x8033;
  stb r0, 0xe(r1);
  addi r3, r3, 0x5f14;
  lwz r12, 0x50(r3);
  addi r4, r1, 8;
  lbz r0, 2(r31);
  li r3, 7;
  stb r0, 0xf(r1);
  mtctr r12;
  bctrl;
lbl_801342c4:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: bta_dm_link_quality_cback
// PAL: 0x801342d8..0x80134344
MARK_BINARY_BLOB(bta_dm_link_quality_cback, 0x801342d8, 0x80134344);
asm UNKNOWN_FUNCTION(bta_dm_link_quality_cback) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r3;
  lbz r0, 0(r3);
  cmpwi r0, 0;
  bne lbl_80134330;
  addi r3, r1, 8;
  addi r4, r31, 3;
  bl bdcpy;
  li r0, 2;
  lis r3, 0x8033;
  stb r0, 0xe(r1);
  addi r3, r3, 0x5f14;
  lwz r12, 0x50(r3);
  addi r4, r1, 8;
  lbz r0, 2(r31);
  li r3, 7;
  stb r0, 0x10(r1);
  mtctr r12;
  bctrl;
lbl_80134330:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: bta_dm_l2cap_server_compress_cback
// PAL: 0x80134344..0x80134428
MARK_BINARY_BLOB(bta_dm_l2cap_server_compress_cback, 0x80134344, 0x80134428);
asm UNKNOWN_FUNCTION(bta_dm_l2cap_server_compress_cback) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_25;
  lis r31, 0x8033;
  lwz r27, 0x38(r1);
  addi r31, r31, 0x5e68;
  mr r25, r3;
  mr r26, r10;
  li r29, 0;
  mr r30, r31;
  li r28, 0;
lbl_80134378:
  lbz r0, 8(r31);
  cmplwi r0, 1;
  bne lbl_801343f8;
  mr r3, r30;
  mr r4, r25;
  bl bdcmp;
  cmpwi r3, 0;
  bne lbl_801343f8;
  lbz r0, -0x6610(r13);
  cmplwi r0, 4;
  blt lbl_801343cc;
  slwi r0, r28, 3;
  lis r5, 0x8033;
  addi r5, r5, 0x5e68;
  lis r4, 0x8028;
  add r0, r0, r28;
  li r3, 0x503;
  add r5, r5, r0;
  addi r4, r4, 0x295c;
  lbz r5, 6(r5);
  bl LogMsg_1;
lbl_801343cc:
  slwi r0, r28, 3;
  lis r3, 0x8033;
  addi r3, r3, 0x5e68;
  mr r4, r26;
  add r0, r0, r28;
  mr r5, r27;
  add r3, r3, r0;
  lbz r3, 6(r3);
  bl bta_dm_co_get_compress_memory;
  mr r29, r3;
  b lbl_8013440c;
lbl_801343f8:
  addi r28, r28, 1;
  addi r30, r30, 9;
  cmpwi r28, 5;
  addi r31, r31, 9;
  blt lbl_80134378;
lbl_8013440c:
  addi r11, r1, 0x30;
  mr r3, r29;
  bl _restgpr_25;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: bta_dm_compress_cback
// PAL: 0x80134428..0x80134660
MARK_BINARY_BLOB(bta_dm_compress_cback, 0x80134428, 0x80134660);
asm UNKNOWN_FUNCTION(bta_dm_compress_cback) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  cmpwi r3, 0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  bne lbl_8013459c;
  lwz r3, -0x73dc(r13);
  li r7, 1;
  lbz r9, 1(r3);
  b lbl_8013458c;
lbl_80134458:
  clrlwi r8, r7, 0x18;
  rlwinm r0, r7, 2, 0x16, 0x1d;
  subf r0, r8, r0;
  add r8, r3, r0;
  lbz r0, 1(r8);
  cmplw r5, r0;
  beq lbl_8013447c;
  cmplwi r0, 0xff;
  bne lbl_80134588;
lbl_8013447c:
  lbz r0, 0(r8);
  cmplw r4, r0;
  bne lbl_80134588;
  lbz r0, 2(r8);
  cmplwi r0, 1;
  bne lbl_80134588;
  lis r8, 0x8033;
  lbz r11, 1(r3);
  lbz r10, 0x6018(r8);
  addi r9, r8, 0x6018;
  li r31, 0;
  li r29, 1;
  b lbl_8013450c;
lbl_801344b0:
  clrlwi r8, r29, 0x18;
  rlwinm r0, r29, 2, 0x16, 0x1d;
  subf r0, r8, r0;
  add r12, r3, r0;
  lbz r0, 2(r12);
  cmplwi r0, 2;
  bne lbl_80134508;
  li r30, 0;
  b lbl_801344fc;
lbl_801344d4:
  clrlwi r8, r30, 0x18;
  rlwinm r0, r30, 3, 0x15, 0x1c;
  add r8, r0, r8;
  lbz r0, 0(r12);
  add r8, r9, r8;
  lbz r8, 7(r8);
  cmplw r8, r0;
  bne lbl_801344f8;
  li r31, 1;
lbl_801344f8:
  addi r30, r30, 1;
lbl_801344fc:
  clrlwi r0, r30, 0x18;
  cmplw r0, r10;
  blt lbl_801344d4;
lbl_80134508:
  addi r29, r29, 1;
lbl_8013450c:
  clrlwi r0, r29, 0x18;
  cmplw r0, r11;
  ble lbl_801344b0;
  cmpwi r31, 0;
  bne lbl_80134644;
  clrlwi r3, r7, 0x18;
  lis r30, 0x8033;
  addi r3, r3, -1;
  slwi r0, r3, 3;
  addi r30, r30, 0x5e68;
  add r29, r0, r3;
  add r31, r30, r29;
  stb r5, 7(r31);
  mr r3, r31;
  stb r4, 6(r31);
  mr r4, r6;
  bl bdcpy;
  lbz r0, -0x6610(r13);
  li r3, 1;
  stb r3, 8(r31);
  mr r7, r31;
  cmplwi r0, 4;
  blt lbl_80134644;
  lis r4, 0x8028;
  lbz r5, 7(r31);
  lbz r6, 6(r31);
  addi r4, r4, 0x298c;
  lbz r7, 8(r7);
  li r3, 0x503;
  bl LogMsg_3;
  b lbl_80134644;
lbl_80134588:
  addi r7, r7, 1;
lbl_8013458c:
  clrlwi r0, r7, 0x18;
  cmplw r0, r9;
  ble lbl_80134458;
  b lbl_80134644;
lbl_8013459c:
  cmplwi r3, 1;
  bne lbl_80134644;
  lwz r7, -0x73dc(r13);
  li r8, 1;
  lbz r6, 1(r7);
  b lbl_80134638;
lbl_801345b4:
  clrlwi r3, r8, 0x18;
  rlwinm r0, r8, 2, 0x16, 0x1d;
  subf r0, r3, r0;
  add r3, r7, r0;
  lbz r0, 1(r3);
  cmplw r5, r0;
  beq lbl_801345d8;
  cmplwi r0, 0xff;
  bne lbl_80134634;
lbl_801345d8:
  lbz r0, 0(r3);
  cmplw r4, r0;
  bne lbl_80134634;
  clrlwi r3, r8, 0x18;
  lbz r0, -0x6610(r13);
  addi r5, r3, -1;
  lis r3, 0x8033;
  cmplwi r0, 4;
  slwi r4, r5, 3;
  add r0, r4, r5;
  addi r3, r3, 0x5e68;
  add r3, r3, r0;
  li r0, 0;
  stb r0, 8(r3);
  blt lbl_80134644;
  lis r4, 0x8028;
  lbz r5, 7(r3);
  lbz r6, 6(r3);
  addi r4, r4, 0x29c8;
  lbz r7, 8(r3);
  li r3, 0x503;
  bl LogMsg_3;
  b lbl_80134644;
lbl_80134634:
  addi r8, r8, 1;
lbl_80134638:
  clrlwi r0, r8, 0x18;
  cmplw r0, r6;
  ble lbl_801345b4;
lbl_80134644:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: bta_dm_rm_cback
// PAL: 0x80134660..0x80134768
MARK_BINARY_BLOB(bta_dm_rm_cback, 0x80134660, 0x80134768);
asm UNKNOWN_FUNCTION(bta_dm_rm_cback) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_26;
  cmpwi r3, 0;
  mr r30, r4;
  mr r31, r5;
  mr r26, r6;
  bne lbl_80134750;
  lis r3, 0x8033;
  li r27, 0;
  addi r29, r3, 0x5f14;
  b lbl_80134740;
lbl_80134698:
  clrlwi r0, r27, 0x18;
  mr r4, r26;
  mulli r28, r0, 0xb;
  add r3, r29, r28;
  bl bdcmp;
  cmpwi r3, 0;
  bne lbl_8013473c;
  add r3, r29, r28;
  li r0, 1;
  stb r0, 6(r3);
  li r7, 1;
  lwz r6, -0x73e0(r13);
  lbz r4, 1(r6);
  b lbl_8013472c;
lbl_801346d0:
  clrlwi r3, r7, 0x18;
  rlwinm r0, r7, 2, 0x16, 0x1d;
  subf r5, r3, r0;
  add r3, r6, r5;
  lbz r0, 1(r3);
  cmplw r31, r0;
  beq lbl_801346f4;
  cmplwi r0, 0xff;
  bne lbl_80134728;
lbl_801346f4:
  lbz r0, 0(r3);
  cmplw r30, r0;
  bne lbl_80134728;
  lis r3, 0x8033;
  add r4, r6, r5;
  addi r3, r3, 0x5f14;
  lbz r4, 2(r4);
  add r3, r3, r28;
  lbz r0, 7(r3);
  cmplw r4, r0;
  ble lbl_80134750;
  stb r4, 7(r3);
  b lbl_80134750;
lbl_80134728:
  addi r7, r7, 1;
lbl_8013472c:
  clrlwi r0, r7, 0x18;
  cmplw r0, r4;
  ble lbl_801346d0;
  b lbl_80134750;
lbl_8013473c:
  addi r27, r27, 1;
lbl_80134740:
  lbz r0, 0x4d(r29);
  clrlwi r3, r27, 0x18;
  cmplw r3, r0;
  blt lbl_80134698;
lbl_80134750:
  addi r11, r1, 0x20;
  bl _restgpr_26;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: bta_dm_keep_acl
// PAL: 0x80134768..0x801347ec
MARK_BINARY_BLOB(bta_dm_keep_acl, 0x80134768, 0x801347ec);
asm UNKNOWN_FUNCTION(bta_dm_keep_acl) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  lhz r4, 6(r3);
  lis r3, 0x8033;
  addi r3, r3, 0x5f14;
  clrlwi. r0, r4, 0x18;
  stb r4, 0x101(r3);
  beq lbl_801347bc;
  lis r31, 1;
  addi r3, r2, -26864;
  addi r0, r31, -1;
  clrlwi r4, r0, 0x10;
  bl L2CA_SetIdleTimeoutByBdAddr;
  addi r0, r31, -1;
  li r3, 0;
  clrlwi r4, r0, 0x10;
  li r5, 1;
  bl L2CA_SetIdleTimeout;
  b lbl_801347d8;
lbl_801347bc:
  addi r3, r2, -26864;
  li r4, 2;
  bl L2CA_SetIdleTimeoutByBdAddr;
  li r3, 0;
  li r4, 2;
  li r5, 1;
  bl L2CA_SetIdleTimeout;
lbl_801347d8:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: bta_dm_immediate_disable
// PAL: 0x801347ec..0x80134808
MARK_BINARY_BLOB(bta_dm_immediate_disable, 0x801347ec, 0x80134808);
asm UNKNOWN_FUNCTION(bta_dm_immediate_disable) {
  // clang-format off
  nofralloc;
  lis r5, 0x8033;
  li r3, 1;
  addi r5, r5, 0x5f14;
  li r4, 0;
  lwz r12, 0x50(r5);
  mtctr r12;
  bctr;
  // clang-format on
}

// Symbol: bta_dm_reset_complete
// PAL: 0x80134808..0x8013480c
MARK_BINARY_BLOB(bta_dm_reset_complete, 0x80134808, 0x8013480c);
asm UNKNOWN_FUNCTION(bta_dm_reset_complete) {
  // clang-format off
  nofralloc;
  blr;
  // clang-format on
}

// Symbol: bta_dm_send_hci_reset
// PAL: 0x8013480c..0x8013485c
MARK_BINARY_BLOB(bta_dm_send_hci_reset, 0x8013480c, 0x8013485c);
asm UNKNOWN_FUNCTION(bta_dm_send_hci_reset) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r4, 0x8033;
  li r3, 2;
  stw r0, 0x14(r1);
  li r0, 1;
  addi r4, r4, 0x5dd8;
  stb r0, 0x7e(r4);
  bl GKI_getpoolbuf;
  cmpwi r3, 0;
  beq lbl_80134840;
  li r4, 0;
  bl btsnd_hcic_write_scan_enable;
lbl_80134840:
  lis r3, 0x8013;
  addi r3, r3, 0x4808;
  bl BTM_SendHciReset;
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

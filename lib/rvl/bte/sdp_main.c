#include "sdp_main.h"

#include <string.h>

#include "gki_buffer.h"
#include "bte_logmsg.h"
#include "l2c_api.h"
#include "sdp_discovery.h"
#include "sdp_utils.h"

// Extern function references.
// PAL: 0x80131d0c
extern UNKNOWN_FUNCTION(btu_start_timer);
// PAL: 0x8013f2b4
extern UNKNOWN_FUNCTION(BTM_SetSecurityLevel);
// PAL: 0x80159f30
extern UNKNOWN_FUNCTION(sdp_server_handle_client_req);

// Symbol: sdp_init
// PAL: 0x801593c4..0x80159564
MARK_BINARY_BLOB(sdp_init, 0x801593c4, 0x80159564);
asm UNKNOWN_FUNCTION(sdp_init) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  li r4, 0;
  li r5, 0x4634;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  lis r30, 0x8028;
  addi r30, r30, 0x7a08;
  stw r29, 0x14(r1);
  lis r29, 0x8034;
  addi r3, r29, -24768;
  bl memset;
  lis r3, 1;
  addi r31, r29, -24768;
  li r7, 1;
  li r5, 0x100;
  addi r11, r3, -1;
  li r10, 0xf0;
  li r0, 0x15;
  sth r5, 4(r31);
  addi r4, r30, 0;
  li r29, 0;
  stb r7, 2(r31);
  li r3, 0;
  li r5, 0;
  li r6, 0;
  stb r7, 0x20(r31);
  li r7, 1;
  li r8, 0;
  li r9, 0;
  sth r11, 0x22(r31);
  sth r10, 0x462c(r31);
  sth r0, 0x462e(r31);
  bl BTM_SetSecurityLevel;
  clrlwi. r0, r3, 0x18;
  bne lbl_80159474;
  lbz r0, 0x4630(r31);
  cmplwi r0, 1;
  blt lbl_80159548;
  addi r4, r30, 0x14;
  lis r3, 0xa;
  bl LogMsg_0;
  b lbl_80159548;
lbl_80159474:
  addi r4, r30, 0;
  li r3, 1;
  li r5, 0;
  li r6, 0;
  li r7, 1;
  li r8, 0;
  li r9, 0;
  bl BTM_SetSecurityLevel;
  clrlwi. r0, r3, 0x18;
  bne lbl_801594b8;
  lbz r0, 0x4630(r31);
  cmplwi r0, 1;
  blt lbl_80159548;
  addi r4, r30, 0x38;
  lis r3, 0xa;
  bl LogMsg_0;
  b lbl_80159548;
lbl_801594b8:
  lis r11, 0x8016;
  lis r10, 0x8016;
  lis r9, 0x8016;
  lis r8, 0x8016;
  lis r7, 0x8016;
  lis r6, 0x8016;
  lis r5, 0x8016;
  addi r11, r11, -27292;
  addi r10, r10, -27096;
  addi r9, r9, -26696;
  addi r8, r8, -26380;
  addi r7, r7, -26000;
  addi r6, r6, -25108;
  addi r5, r5, -25752;
  stb r29, 0x4630(r31);
  addi r4, r31, 0x4604;
  li r3, 1;
  stw r11, 0x4604(r31);
  stw r10, 0x4608(r31);
  stw r29, 0x460c(r31);
  stw r9, 0x4610(r31);
  stw r8, 0x4614(r31);
  stw r7, 0x4618(r31);
  stw r6, 0x461c(r31);
  stw r29, 0x4620(r31);
  stw r5, 0x4624(r31);
  stw r29, 0x4628(r31);
  bl L2CA_Register;
  clrlwi. r0, r3, 0x18;
  bne lbl_80159548;
  lbz r0, 0x4630(r31);
  cmplwi r0, 1;
  blt lbl_80159548;
  addi r4, r30, 0x60;
  lis r3, 0xa;
  bl LogMsg_0;
lbl_80159548:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: sdp_connect_ind
// PAL: 0x80159564..0x80159628
MARK_BINARY_BLOB(sdp_connect_ind, 0x80159564, 0x80159628);
asm UNKNOWN_FUNCTION(sdp_connect_ind) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r6;
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  mr r29, r4;
  stw r28, 0x10(r1);
  mr r28, r3;
  bl sdpu_allocate_ccb;
  cmpwi r3, 0;
  mr r30, r3;
  beq lbl_80159608;
  li r0, 2;
  mr r4, r28;
  stb r0, 0(r3);
  li r5, 6;
  addi r3, r3, 2;
  bl memcpy;
  sth r29, 0x22(r30);
  mr r3, r28;
  mr r4, r31;
  mr r5, r29;
  li r6, 0;
  li r7, 0;
  bl L2CA_ConnectRsp;
  lis r31, 0x8034;
  mr r3, r29;
  addi r4, r31, -24768;
  bl L2CA_ConfigReq;
  addi r3, r31, -24768;
  lbz r0, 0x4630(r3);
  cmplwi r0, 4;
  blt lbl_80159608;
  lis r3, 0xa;
  lis r4, 0x8028;
  lhz r5, 0x22(r30);
  addi r3, r3, 3;
  addi r4, r4, 0x7a80;
  bl LogMsg_1;
lbl_80159608:
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

// Symbol: sdp_connect_cfm
// PAL: 0x80159628..0x801597b8
MARK_BINARY_BLOB(sdp_connect_cfm, 0x80159628, 0x801597b8);
asm UNKNOWN_FUNCTION(sdp_connect_cfm) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r4;
  stw r30, 0x18(r1);
  lis r30, 0x8028;
  addi r30, r30, 0x7a08;
  stw r29, 0x14(r1);
  stw r28, 0x10(r1);
  mr r28, r3;
  bl sdpu_find_ccb_by_cid;
  cmpwi r3, 0;
  mr r29, r3;
  bne lbl_80159690;
  lis r3, 0x8034;
  addi r3, r3, -24768;
  lbz r0, 0x4630(r3);
  cmplwi r0, 2;
  blt lbl_80159798;
  lis r3, 0xa;
  mr r5, r28;
  addi r3, r3, 1;
  addi r4, r30, 0xb0;
  bl LogMsg_1;
  b lbl_80159798;
lbl_80159690:
  cmpwi r31, 0;
  bne lbl_801596e4;
  lbz r0, 0(r3);
  cmplwi r0, 1;
  bne lbl_801596e4;
  li r0, 2;
  lis r31, 0x8034;
  stb r0, 0(r3);
  mr r3, r28;
  addi r4, r31, -24768;
  bl L2CA_ConfigReq;
  addi r3, r31, -24768;
  lbz r0, 0x4630(r3);
  cmplwi r0, 4;
  blt lbl_80159798;
  lis r3, 0xa;
  lhz r5, 0x22(r29);
  addi r3, r3, 3;
  addi r4, r30, 0xdc;
  bl LogMsg_1;
  b lbl_80159798;
lbl_801596e4:
  lis r3, 0x8034;
  addi r3, r3, -24768;
  lbz r0, 0x4630(r3);
  cmplwi r0, 2;
  blt lbl_80159710;
  lis r3, 0xa;
  lhz r6, 0x22(r29);
  mr r5, r31;
  addi r4, r30, 0x108;
  addi r3, r3, 1;
  bl LogMsg_2;
lbl_80159710:
  lwz r12, 0x414(r29);
  cmpwi r12, 0;
  beq lbl_80159790;
  cmplwi r31, 0xe;
  beq lbl_80159744;
  cmplwi r31, 5;
  beq lbl_80159744;
  cmplwi r31, 0x18;
  beq lbl_80159744;
  cmplwi r31, 0x29;
  beq lbl_80159744;
  cmplwi r31, 6;
  bne lbl_8015975c;
lbl_80159744:
  lis r3, 1;
  addi r0, r3, -10;
  clrlwi r3, r0, 0x10;
  mtctr r12;
  bctrl;
  b lbl_80159790;
lbl_8015975c:
  cmplwi r31, 0xf;
  bne lbl_8015977c;
  lis r3, 1;
  addi r0, r3, -9;
  clrlwi r3, r0, 0x10;
  mtctr r12;
  bctrl;
  b lbl_80159790;
lbl_8015977c:
  lis r3, 1;
  addi r0, r3, -15;
  clrlwi r3, r0, 0x10;
  mtctr r12;
  bctrl;
lbl_80159790:
  mr r3, r29;
  bl sdpu_release_ccb;
lbl_80159798:
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

// Symbol: sdp_config_ind
// PAL: 0x801597b8..0x801598f4
MARK_BINARY_BLOB(sdp_config_ind, 0x801597b8, 0x801598f4);
asm UNKNOWN_FUNCTION(sdp_config_ind) {
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
  bl sdpu_find_ccb_by_cid;
  cmpwi r3, 0;
  mr r31, r3;
  bne lbl_80159818;
  lis r3, 0x8034;
  addi r3, r3, -24768;
  lbz r0, 0x4630(r3);
  cmplwi r0, 2;
  blt lbl_801598d8;
  lis r3, 0xa;
  lis r4, 0x8028;
  mr r5, r29;
  addi r3, r3, 1;
  addi r4, r4, 0x7b40;
  bl LogMsg_1;
  b lbl_801598d8;
lbl_80159818:
  lbz r0, 2(r30);
  cmpwi r0, 0;
  bne lbl_80159830;
  li r0, 0x100;
  sth r0, 0x20(r3);
  b lbl_8015984c;
lbl_80159830:
  lhz r0, 4(r30);
  cmplwi r0, 0x100;
  ble lbl_80159848;
  li r0, 0x100;
  sth r0, 0x20(r3);
  b lbl_8015984c;
lbl_80159848:
  sth r0, 0x20(r3);
lbl_8015984c:
  li r0, 0;
  mr r3, r29;
  stb r0, 0x20(r30);
  mr r4, r30;
  stb r0, 2(r30);
  sth r0, 0(r30);
  bl L2CA_ConfigRsp;
  lis r3, 0x8034;
  addi r3, r3, -24768;
  lbz r0, 0x4630(r3);
  cmplwi r0, 4;
  blt lbl_80159894;
  lis r3, 0xa;
  lis r4, 0x8028;
  mr r5, r29;
  addi r3, r3, 3;
  addi r4, r4, 0x7b6c;
  bl LogMsg_1;
lbl_80159894:
  lbz r0, 1(r31);
  ori r3, r0, 2;
  rlwinm. r0, r3, 0, 0x1d, 0x1d;
  stb r3, 1(r31);
  beq lbl_801598d8;
  li r0, 3;
  stb r0, 0(r31);
  lbz r0, 1(r31);
  clrlwi. r0, r0, 0x1f;
  beq lbl_801598c8;
  mr r3, r31;
  bl sdp_disc_connected;
  b lbl_801598d8;
lbl_801598c8:
  addi r3, r31, 8;
  li r4, 5;
  li r5, 0x1e;
  bl btu_start_timer;
lbl_801598d8:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: sdp_config_cfm
// PAL: 0x801598f4..0x80159a70
MARK_BINARY_BLOB(sdp_config_cfm, 0x801598f4, 0x80159a70);
asm UNKNOWN_FUNCTION(sdp_config_cfm) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  lis r5, 0x8034;
  stw r0, 0x24(r1);
  addi r5, r5, -24768;
  stw r31, 0x1c(r1);
  lis r31, 0x8028;
  addi r31, r31, 0x7a08;
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  mr r29, r4;
  stw r28, 0x10(r1);
  mr r28, r3;
  lbz r0, 0x4630(r5);
  cmplwi r0, 4;
  blt lbl_8015994c;
  lis r3, 0xa;
  lhz r6, 0(r29);
  mr r5, r28;
  addi r4, r31, 0x190;
  addi r3, r3, 3;
  bl LogMsg_2;
lbl_8015994c:
  mr r3, r28;
  bl sdpu_find_ccb_by_cid;
  cmpwi r3, 0;
  mr r30, r3;
  bne lbl_8015998c;
  lis r3, 0x8034;
  addi r3, r3, -24768;
  lbz r0, 0x4630(r3);
  cmplwi r0, 2;
  blt lbl_80159a50;
  lis r3, 0xa;
  mr r5, r28;
  addi r3, r3, 1;
  addi r4, r31, 0x138;
  bl LogMsg_1;
  b lbl_80159a50;
lbl_8015998c:
  lhz r0, 0(r29);
  cmpwi r0, 0;
  bne lbl_801599dc;
  lbz r0, 1(r3);
  ori r4, r0, 4;
  rlwinm. r0, r4, 0, 0x1e, 0x1e;
  stb r4, 1(r3);
  beq lbl_80159a50;
  li r0, 3;
  stb r0, 0(r3);
  lbz r0, 1(r3);
  clrlwi. r0, r0, 0x1f;
  beq lbl_801599c8;
  bl sdp_disc_connected;
  b lbl_80159a50;
lbl_801599c8:
  li r4, 5;
  li r5, 0x1e;
  addi r3, r3, 8;
  bl btu_start_timer;
  b lbl_80159a50;
lbl_801599dc:
  lis r3, 0x8034;
  addi r3, r3, -24768;
  lbz r0, 0x4630(r3);
  cmplwi r0, 4;
  blt lbl_80159a04;
  lis r3, 0xa;
  lhz r5, 0x22(r30);
  addi r3, r3, 3;
  addi r4, r31, 0x1bc;
  bl LogMsg_1;
lbl_80159a04:
  lbz r0, 0(r30);
  cmplwi r0, 1;
  beq lbl_80159a28;
  lhz r3, 0x22(r30);
  bl L2CA_DisconnectReq;
  lis r3, 1;
  addi r0, r3, -14;
  sth r0, 0x472(r30);
  b lbl_80159a50;
lbl_80159a28:
  lwz r12, 0x414(r30);
  cmpwi r12, 0;
  beq lbl_80159a48;
  lis r3, 1;
  addi r0, r3, -14;
  clrlwi r3, r0, 0x10;
  mtctr r12;
  bctrl;
lbl_80159a48:
  mr r3, r30;
  bl sdpu_release_ccb;
lbl_80159a50:
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

// Symbol: sdp_disconnect_ind
// PAL: 0x80159a70..0x80159b68
MARK_BINARY_BLOB(sdp_disconnect_ind, 0x80159a70, 0x80159b68);
asm UNKNOWN_FUNCTION(sdp_disconnect_ind) {
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
  bl sdpu_find_ccb_by_cid;
  cmpwi r3, 0;
  mr r31, r3;
  bne lbl_80159ad0;
  lis r3, 0x8034;
  addi r3, r3, -24768;
  lbz r0, 0x4630(r3);
  cmplwi r0, 2;
  blt lbl_80159b4c;
  lis r3, 0xa;
  lis r4, 0x8028;
  mr r5, r29;
  addi r3, r3, 1;
  addi r4, r4, 0x7be0;
  bl LogMsg_1;
  b lbl_80159b4c;
lbl_80159ad0:
  cmpwi r30, 0;
  beq lbl_80159ae0;
  mr r3, r29;
  bl L2CA_DisconnectRsp;
lbl_80159ae0:
  lis r3, 0x8034;
  addi r3, r3, -24768;
  lbz r0, 0x4630(r3);
  cmplwi r0, 4;
  blt lbl_80159b0c;
  lis r3, 0xa;
  lis r4, 0x8028;
  mr r5, r29;
  addi r3, r3, 3;
  addi r4, r4, 0x7c0c;
  bl LogMsg_1;
lbl_80159b0c:
  lwz r12, 0x414(r31);
  cmpwi r12, 0;
  beq lbl_80159b44;
  lbz r5, 0(r31);
  lis r3, 1;
  addi r0, r3, -15;
  addi r4, r5, -3;
  subfic r3, r5, 3;
  nor r3, r4, r3;
  srawi r3, r3, 0x1f;
  andc r0, r0, r3;
  clrlwi r3, r0, 0x10;
  mtctr r12;
  bctrl;
lbl_80159b44:
  mr r3, r31;
  bl sdpu_release_ccb;
lbl_80159b4c:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: sdp_data_ind
// PAL: 0x80159b68..0x80159c3c
MARK_BINARY_BLOB(sdp_data_ind, 0x80159b68, 0x80159c3c);
asm UNKNOWN_FUNCTION(sdp_data_ind) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  bl sdpu_find_ccb_by_cid;
  cmpwi r3, 0;
  beq lbl_80159bf0;
  lbz r5, 0(r3);
  cmplwi r5, 3;
  bne lbl_80159bc0;
  lbz r0, 1(r3);
  clrlwi. r0, r0, 0x1f;
  beq lbl_80159bb4;
  mr r4, r31;
  bl sdp_disc_server_rsp;
  b lbl_80159c1c;
lbl_80159bb4:
  mr r4, r31;
  bl sdp_server_handle_client_req;
  b lbl_80159c1c;
lbl_80159bc0:
  lis r3, 0x8034;
  addi r3, r3, -24768;
  lbz r0, 0x4630(r3);
  cmplwi r0, 2;
  blt lbl_80159c1c;
  lis r3, 0xa;
  lis r4, 0x8028;
  mr r6, r30;
  addi r3, r3, 1;
  addi r4, r4, 0x7c30;
  bl LogMsg_2;
  b lbl_80159c1c;
lbl_80159bf0:
  lis r3, 0x8034;
  addi r3, r3, -24768;
  lbz r0, 0x4630(r3);
  cmplwi r0, 2;
  blt lbl_80159c1c;
  lis r3, 0xa;
  lis r4, 0x8028;
  mr r5, r30;
  addi r3, r3, 1;
  addi r4, r4, 0x7c68;
  bl LogMsg_1;
lbl_80159c1c:
  mr r3, r31;
  bl GKI_freebuf;
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: sdp_conn_originate
// PAL: 0x80159c3c..0x80159d50
MARK_BINARY_BLOB(sdp_conn_originate, 0x80159c3c, 0x80159d50);
asm UNKNOWN_FUNCTION(sdp_conn_originate) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  lis r31, 0x8028;
  addi r31, r31, 0x7a08;
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  mr r29, r3;
  bl sdpu_allocate_ccb;
  cmpwi r3, 0;
  mr r30, r3;
  bne lbl_80159c9c;
  lis r3, 0x8034;
  addi r3, r3, -24768;
  lbz r0, 0x4630(r3);
  cmplwi r0, 2;
  blt lbl_80159c94;
  lis r3, 0xa;
  addi r4, r31, 0x28c;
  addi r3, r3, 1;
  bl LogMsg_0;
lbl_80159c94:
  li r3, 0;
  b lbl_80159d34;
lbl_80159c9c:
  lis r3, 0x8034;
  addi r3, r3, -24768;
  lbz r0, 0x4630(r3);
  cmplwi r0, 4;
  blt lbl_80159cc0;
  lis r3, 0xa;
  addi r4, r31, 0x2a8;
  addi r3, r3, 3;
  bl LogMsg_0;
lbl_80159cc0:
  lbz r0, 1(r30);
  mr r4, r29;
  addi r3, r30, 2;
  li r5, 6;
  ori r0, r0, 1;
  stb r0, 1(r30);
  bl memcpy;
  li r0, 1;
  mr r4, r29;
  stb r0, 0(r30);
  li r3, 1;
  bl L2CA_ConnectReq;
  clrlwi. r0, r3, 0x10;
  beq lbl_80159d04;
  sth r3, 0x22(r30);
  mr r3, r30;
  b lbl_80159d34;
lbl_80159d04:
  lis r3, 0x8034;
  addi r3, r3, -24768;
  lbz r0, 0x4630(r3);
  cmplwi r0, 2;
  blt lbl_80159d28;
  lis r3, 0xa;
  addi r4, r31, 0x2c0;
  addi r3, r3, 1;
  bl LogMsg_0;
lbl_80159d28:
  mr r3, r30;
  bl sdpu_release_ccb;
  li r3, 0;
lbl_80159d34:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: sdp_disconnect
// PAL: 0x80159d50..0x80159dec
MARK_BINARY_BLOB(sdp_disconnect, 0x80159d50, 0x80159dec);
asm UNKNOWN_FUNCTION(sdp_disconnect) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r5, 0x8034;
  stw r0, 0x14(r1);
  addi r5, r5, -24768;
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  lbz r0, 0x4630(r5);
  cmplwi r0, 4;
  blt lbl_80159d98;
  lis r3, 0xa;
  lis r4, 0x8028;
  lhz r5, 0x22(r30);
  addi r3, r3, 3;
  addi r4, r4, 0x7bc4;
  bl LogMsg_1;
lbl_80159d98:
  lbz r0, 0(r30);
  cmplwi r0, 1;
  beq lbl_80159db4;
  lhz r3, 0x22(r30);
  bl L2CA_DisconnectReq;
  sth r31, 0x472(r30);
  b lbl_80159dd4;
lbl_80159db4:
  lwz r12, 0x414(r30);
  cmpwi r12, 0;
  beq lbl_80159dcc;
  mr r3, r31;
  mtctr r12;
  bctrl;
lbl_80159dcc:
  mr r3, r30;
  bl sdpu_release_ccb;
lbl_80159dd4:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: sdp_disconnect_cfm
// PAL: 0x80159dec..0x80159ea8
MARK_BINARY_BLOB(sdp_disconnect_cfm, 0x80159dec, 0x80159ea8);
asm UNKNOWN_FUNCTION(sdp_disconnect_cfm) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  stw r30, 8(r1);
  mr r30, r3;
  bl sdpu_find_ccb_by_cid;
  cmpwi r3, 0;
  mr r31, r3;
  bne lbl_80159e44;
  lis r3, 0x8034;
  addi r3, r3, -24768;
  lbz r0, 0x4630(r3);
  cmplwi r0, 2;
  blt lbl_80159e90;
  lis r3, 0xa;
  lis r4, 0x8028;
  mr r5, r30;
  addi r3, r3, 1;
  addi r4, r4, 0x7ce0;
  bl LogMsg_1;
  b lbl_80159e90;
lbl_80159e44:
  lis r3, 0x8034;
  addi r3, r3, -24768;
  lbz r0, 0x4630(r3);
  cmplwi r0, 4;
  blt lbl_80159e70;
  lis r3, 0xa;
  lis r4, 0x8028;
  mr r5, r30;
  addi r3, r3, 3;
  addi r4, r4, 0x7d10;
  bl LogMsg_1;
lbl_80159e70:
  lwz r12, 0x414(r31);
  cmpwi r12, 0;
  beq lbl_80159e88;
  lhz r3, 0x472(r31);
  mtctr r12;
  bctrl;
lbl_80159e88:
  mr r3, r31;
  bl sdpu_release_ccb;
lbl_80159e90:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: sdp_conn_timeout
// PAL: 0x80159ea8..0x80159f30
MARK_BINARY_BLOB(sdp_conn_timeout, 0x80159ea8, 0x80159f30);
asm UNKNOWN_FUNCTION(sdp_conn_timeout) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r4, 0x8034;
  stw r0, 0x14(r1);
  addi r4, r4, -24768;
  stw r31, 0xc(r1);
  mr r31, r3;
  lbz r0, 0x4630(r4);
  cmplwi r0, 4;
  blt lbl_80159eec;
  lis r3, 0xa;
  lis r4, 0x8028;
  lbz r5, 0(r31);
  addi r3, r3, 3;
  lhz r6, 0x22(r31);
  addi r4, r4, 0x7d38;
  bl LogMsg_2;
lbl_80159eec:
  lhz r3, 0x22(r31);
  bl L2CA_DisconnectReq;
  lwz r12, 0x414(r31);
  cmpwi r12, 0;
  beq lbl_80159f14;
  lis r3, 1;
  addi r0, r3, -15;
  clrlwi r3, r0, 0x10;
  mtctr r12;
  bctrl;
lbl_80159f14:
  mr r3, r31;
  bl sdpu_release_ccb;
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

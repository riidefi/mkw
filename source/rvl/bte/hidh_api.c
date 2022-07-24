#include "hidh_api.h"

#include <string.h>

#include "gki_buffer.h"
#include "bte_logmsg.h"
#include "bte_task1.h"
#include "btm_sec.h"
#include "hidh_conn.h"
#include "sdp_api.h"

// Symbol: HID_HostGetSDPRecord
// PAL: 0x801472a0..0x80147368
MARK_BINARY_BLOB(HID_HostGetSDPRecord, 0x801472a0, 0x80147368);
asm UNKNOWN_FUNCTION(HID_HostGetSDPRecord) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  stw r31, 0x2c(r1);
  lis r31, 0x8034;
  addi r31, r31, -28872;
  stw r30, 0x28(r1);
  mr r30, r6;
  stw r29, 0x24(r1);
  mr r29, r4;
  stw r28, 0x20(r1);
  mr r28, r3;
  lbz r0, 0x380(r31);
  cmpwi r0, 0;
  beq lbl_801472e4;
  li r3, 0x10;
  b lbl_80147348;
lbl_801472e4:
  li r7, 2;
  li r0, 0x1124;
  stw r4, 0x388(r31);
  mr r4, r5;
  mr r3, r29;
  addi r6, r1, 8;
  sth r7, 8(r1);
  li r5, 1;
  li r7, 0;
  li r8, 0;
  sth r0, 0xc(r1);
  bl SDP_InitDiscoveryDb;
  lis r5, 0x8014;
  mr r3, r28;
  mr r4, r29;
  addi r5, r5, 0x7368;
  bl SDP_ServiceSearchRequest;
  clrlwi. r0, r3, 0x18;
  beq lbl_80147344;
  li r0, 1;
  stw r30, 0x384(r31);
  li r3, 0;
  stb r0, 0x380(r31);
  b lbl_80147348;
lbl_80147344:
  li r3, 3;
lbl_80147348:
  lwz r0, 0x34(r1);
  lwz r31, 0x2c(r1);
  lwz r30, 0x28(r1);
  lwz r29, 0x24(r1);
  lwz r28, 0x20(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: hidh_search_callback
// PAL: 0x80147368..0x801477b8
MARK_BINARY_BLOB(hidh_search_callback, 0x80147368, 0x801477b8);
asm UNKNOWN_FUNCTION(hidh_search_callback) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  li r4, 2;
  cmpwi r3, 0;
  stw r0, 0x34(r1);
  li r0, 0x1124;
  stw r31, 0x2c(r1);
  stw r30, 0x28(r1);
  stw r29, 0x24(r1);
  li r29, 0;
  stw r28, 0x20(r1);
  lis r28, 0x8034;
  addi r28, r28, -28872;
  sth r4, 8(r1);
  addi r30, r28, 0x38c;
  lwz r4, 0x388(r28);
  sth r0, 0xc(r1);
  stb r29, 0x380(r28);
  beq lbl_801473cc;
  lwz r12, 0x384(r28);
  li r4, 0;
  li r5, 0;
  mtctr r12;
  bctrl;
  b lbl_80147798;
lbl_801473cc:
  mr r3, r4;
  addi r4, r1, 8;
  li r5, 0;
  bl SDP_FindServiceUUIDInDb;
  cmpwi r3, 0;
  mr r31, r3;
  bne lbl_80147404;
  lwz r12, 0x384(r28);
  li r3, 0xc;
  li r4, 0;
  li r5, 0;
  mtctr r12;
  bctrl;
  b lbl_80147798;
lbl_80147404:
  mr r3, r30;
  li r4, 0;
  li r5, 0x74;
  bl memset;
  mr r3, r31;
  li r4, 0x206;
  bl SDP_FindAttributeInRec;
  cmpwi r3, 0;
  beq lbl_8014747c;
  lhz r0, 6(r3);
  srawi r0, r0, 0xc;
  cmpwi r0, 6;
  bne lbl_8014747c;
  lwz r3, 8(r3);
  cmpwi r3, 0;
  beq lbl_8014747c;
  lhz r0, 6(r3);
  srawi r0, r0, 0xc;
  cmpwi r0, 6;
  bne lbl_8014747c;
  lwz r3, 8(r3);
  cmpwi r3, 0;
  beq lbl_8014747c;
  lwz r4, 0(r3);
  cmpwi r4, 0;
  beq lbl_8014747c;
  lhz r3, 6(r4);
  srawi r0, r3, 0xc;
  cmpwi r0, 4;
  beq lbl_801474a0;
lbl_8014747c:
  lis r5, 0x8034;
  li r3, 0xd;
  addi r5, r5, -28872;
  li r4, 0;
  lwz r12, 0x384(r5);
  li r5, 0;
  mtctr r12;
  bctrl;
  b lbl_80147798;
lbl_801474a0:
  clrlwi. r0, r3, 0x14;
  sth r0, 0x68(r30);
  beq lbl_801474b4;
  addi r0, r4, 8;
  stw r0, 0x6c(r30);
lbl_801474b4:
  mr r3, r31;
  li r4, 0x204;
  bl SDP_FindAttributeInRec;
  cmpwi r3, 0;
  beq lbl_801474d8;
  lbz r0, 8(r3);
  cmpwi r0, 0;
  beq lbl_801474d8;
  ori r29, r29, 1;
lbl_801474d8:
  mr r3, r31;
  li r4, 0x205;
  bl SDP_FindAttributeInRec;
  cmpwi r3, 0;
  beq lbl_80147500;
  lbz r0, 8(r3);
  cmpwi r0, 0;
  beq lbl_80147500;
  ori r0, r29, 4;
  clrlwi r29, r0, 0x10;
lbl_80147500:
  mr r3, r31;
  li r4, 0x20d;
  bl SDP_FindAttributeInRec;
  cmpwi r3, 0;
  beq lbl_80147528;
  lbz r0, 8(r3);
  cmpwi r0, 0;
  beq lbl_80147528;
  ori r0, r29, 2;
  clrlwi r29, r0, 0x10;
lbl_80147528:
  mr r3, r31;
  li r4, 0x208;
  bl SDP_FindAttributeInRec;
  cmpwi r3, 0;
  beq lbl_80147550;
  lbz r0, 8(r3);
  cmpwi r0, 0;
  beq lbl_80147550;
  ori r0, r29, 8;
  clrlwi r29, r0, 0x10;
lbl_80147550:
  mr r3, r31;
  li r4, 0x209;
  bl SDP_FindAttributeInRec;
  cmpwi r3, 0;
  beq lbl_80147578;
  lbz r0, 8(r3);
  cmpwi r0, 0;
  beq lbl_80147578;
  ori r0, r29, 0x10;
  clrlwi r29, r0, 0x10;
lbl_80147578:
  mr r3, r31;
  li r4, 0x20a;
  bl SDP_FindAttributeInRec;
  cmpwi r3, 0;
  beq lbl_801475a0;
  lbz r0, 8(r3);
  cmpwi r0, 0;
  beq lbl_801475a0;
  ori r0, r29, 0x20;
  clrlwi r29, r0, 0x10;
lbl_801475a0:
  mr r3, r31;
  li r4, 0x100;
  bl SDP_FindAttributeInRec;
  cmpwi r3, 0;
  mr r4, r3;
  beq lbl_80147600;
  lhz r0, 6(r3);
  clrlwi r28, r0, 0x14;
  cmplwi r28, 0x20;
  bge lbl_801475e4;
  mr r3, r30;
  mr r5, r28;
  addi r4, r4, 8;
  bl memcpy;
  li r0, 0;
  stbx r0, r30, r28;
  b lbl_80147608;
lbl_801475e4:
  mr r3, r30;
  addi r4, r4, 8;
  li r5, 0x1f;
  bl memcpy;
  li r0, 0;
  stb r0, 0x20(r30);
  b lbl_80147608;
lbl_80147600:
  li r0, 0;
  stb r0, 0(r30);
lbl_80147608:
  mr r3, r31;
  li r4, 0x101;
  bl SDP_FindAttributeInRec;
  cmpwi r3, 0;
  mr r4, r3;
  beq lbl_8014766c;
  lhz r0, 6(r3);
  clrlwi r28, r0, 0x14;
  cmplwi r28, 0x20;
  bge lbl_80147650;
  mr r5, r28;
  addi r3, r30, 0x20;
  addi r4, r4, 8;
  bl memcpy;
  add r3, r30, r28;
  li r0, 0;
  stb r0, 0x20(r3);
  b lbl_80147674;
lbl_80147650:
  addi r3, r30, 0x20;
  addi r4, r4, 8;
  li r5, 0x1f;
  bl memcpy;
  li r0, 0;
  stb r0, 0x40(r30);
  b lbl_80147674;
lbl_8014766c:
  li r0, 0;
  stb r0, 0x20(r30);
lbl_80147674:
  mr r3, r31;
  li r4, 0x102;
  bl SDP_FindAttributeInRec;
  cmpwi r3, 0;
  mr r4, r3;
  beq lbl_801476d8;
  lhz r0, 6(r3);
  clrlwi r28, r0, 0x14;
  cmplwi r28, 0x20;
  bge lbl_801476bc;
  mr r5, r28;
  addi r3, r30, 0x40;
  addi r4, r4, 8;
  bl memcpy;
  add r3, r30, r28;
  li r0, 0;
  stb r0, 0x40(r3);
  b lbl_801476e0;
lbl_801476bc:
  addi r3, r30, 0x40;
  addi r4, r4, 8;
  li r5, 0x1f;
  bl memcpy;
  li r0, 0;
  stb r0, 0x60(r30);
  b lbl_801476e0;
lbl_801476d8:
  li r0, 0;
  stb r0, 0x40(r30);
lbl_801476e0:
  mr r3, r31;
  li r4, 0x200;
  bl SDP_FindAttributeInRec;
  cmpwi r3, 0;
  beq lbl_801476fc;
  lhz r0, 8(r3);
  sth r0, 0x60(r30);
lbl_801476fc:
  mr r3, r31;
  li r4, 0x203;
  bl SDP_FindAttributeInRec;
  cmpwi r3, 0;
  beq lbl_80147718;
  lbz r0, 8(r3);
  stb r0, 0x65(r30);
lbl_80147718:
  mr r3, r31;
  li r4, 0x202;
  bl SDP_FindAttributeInRec;
  cmpwi r3, 0;
  beq lbl_80147734;
  lbz r0, 8(r3);
  stb r0, 0x64(r30);
lbl_80147734:
  mr r3, r31;
  li r4, 0x201;
  bl SDP_FindAttributeInRec;
  cmpwi r3, 0;
  beq lbl_80147750;
  lhz r0, 8(r3);
  sth r0, 0x62(r30);
lbl_80147750:
  mr r3, r31;
  li r4, 0x20c;
  bl SDP_FindAttributeInRec;
  cmpwi r3, 0;
  beq lbl_80147774;
  lhz r0, 8(r3);
  ori r3, r29, 0x40;
  clrlwi r29, r3, 0x10;
  sth r0, 0x66(r30);
lbl_80147774:
  lis r6, 0x8034;
  clrlwi r4, r29, 0x10;
  addi r6, r6, -28872;
  li r3, 0;
  lwz r12, 0x384(r6);
  addi r5, r6, 0x38c;
  stw r31, 0x3fc(r6);
  mtctr r12;
  bctrl;
lbl_80147798:
  lwz r0, 0x34(r1);
  lwz r31, 0x2c(r1);
  lwz r30, 0x28(r1);
  lwz r29, 0x24(r1);
  lwz r28, 0x20(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: HID_HostInit
// PAL: 0x801477b8..0x801477fc
MARK_BINARY_BLOB(HID_HostInit, 0x801477b8, 0x801477fc);
asm UNKNOWN_FUNCTION(HID_HostInit) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  li r4, 0;
  li r5, 0x404;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  lis r31, 0x8034;
  addi r3, r31, -28872;
  bl memset;
  addi r3, r31, -28872;
  li r0, 0;
  stb r0, 0x401(r3);
  lwz r31, 0xc(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: HID_HostRegister
// PAL: 0x801477fc..0x80147878
MARK_BINARY_BLOB(HID_HostRegister, 0x801477fc, 0x80147878);
asm UNKNOWN_FUNCTION(HID_HostRegister) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  lis r31, 0x8034;
  addi r31, r31, -28872;
  stw r30, 8(r1);
  mr r30, r3;
  lbz r0, 0x400(r31);
  cmpwi r0, 0;
  beq lbl_80147830;
  li r3, 2;
  b lbl_80147860;
lbl_80147830:
  cmpwi r3, 0;
  bne lbl_80147840;
  li r3, 5;
  b lbl_80147860;
lbl_80147840:
  bl hidh_conn_reg;
  clrlwi. r0, r3, 0x18;
  beq lbl_80147850;
  b lbl_80147860;
lbl_80147850:
  li r0, 1;
  stw r30, 0x340(r31);
  li r3, 0;
  stb r0, 0x400(r31);
lbl_80147860:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: HID_HostDeregister
// PAL: 0x80147878..0x8014795c
MARK_BINARY_BLOB(HID_HostDeregister, 0x80147878, 0x8014795c);
asm UNKNOWN_FUNCTION(HID_HostDeregister) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_27;
  lis r3, 0x8034;
  addi r29, r3, -28872;
  lbz r0, 0x400(r29);
  cmpwi r0, 0;
  bne lbl_801478a8;
  li r3, 1;
  b lbl_80147944;
lbl_801478a8:
  li r27, 0;
  li r30, 1;
  li r31, 0;
lbl_801478b4:
  lbz r0, 0x400(r29);
  cmpwi cr6, r0, 0;
  beq cr6, lbl_80147920;
  clrlwi r0, r27, 0x18;
  cmplwi cr1, r0, 0x10;
  bgt cr1, lbl_80147920;
  mulli r0, r0, 0x34;
  add r28, r29, r0;
  lbzx r0, r29, r0;
  cmpwi r0, 0;
  beq lbl_80147920;
  beq cr6, lbl_80147910;
  bgt cr1, lbl_80147910;
  beq lbl_80147910;
  stb r30, 0xc(r28);
  addi r3, r28, 0x1c;
  bl btu_stop_timer;
  lbz r0, 0xa(r28);
  cmplwi r0, 1;
  bne lbl_80147910;
  stb r30, 0xc(r28);
  clrlwi r3, r27, 0x18;
  bl hidh_conn_disconnect;
lbl_80147910:
  stb r31, 0(r28);
  stb r31, 0x10(r28);
  sth r31, 0x16(r28);
  sth r31, 0x14(r28);
lbl_80147920:
  addi r27, r27, 1;
  cmplwi r27, 0x10;
  blt lbl_801478b4;
  bl hidh_conn_dereg;
  lis r4, 0x8034;
  li r0, 0;
  addi r4, r4, -28872;
  li r3, 0;
  stb r0, 0x400(r4);
lbl_80147944:
  addi r11, r1, 0x20;
  bl _restgpr_27;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: HID_HostAddDev
// PAL: 0x8014795c..0x80147aec
MARK_BINARY_BLOB(HID_HostAddDev, 0x8014795c, 0x80147aec);
asm UNKNOWN_FUNCTION(HID_HostAddDev) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_26;
  lis r31, 0x8034;
  mr r26, r3;
  addi r31, r31, -28872;
  mr r27, r4;
  lbz r0, 0x400(r31);
  mr r28, r5;
  cmpwi r0, 0;
  bne lbl_80147998;
  li r3, 1;
  b lbl_80147ad4;
lbl_80147998:
  li r29, 0;
lbl_8014799c:
  mr r3, r26;
  addi r4, r31, 1;
  li r5, 6;
  bl memcmp;
  cmpwi r3, 0;
  beq lbl_801479c4;
  addi r29, r29, 1;
  addi r31, r31, 0x34;
  cmpwi r29, 0x10;
  blt lbl_8014799c;
lbl_801479c4:
  cmpwi r29, 0x10;
  bne lbl_80147a68;
  lis r3, 0x8034;
  li r0, 2;
  addi r3, r3, -28872;
  li r29, 0;
  mtctr r0;
lbl_801479e0:
  lbz r0, 0(r3);
  cmpwi r0, 0;
  beq lbl_80147a68;
  lbz r0, 0x34(r3);
  addi r29, r29, 1;
  cmpwi r0, 0;
  beq lbl_80147a68;
  lbz r0, 0x68(r3);
  addi r29, r29, 1;
  cmpwi r0, 0;
  beq lbl_80147a68;
  lbz r0, 0x9c(r3);
  addi r29, r29, 1;
  cmpwi r0, 0;
  beq lbl_80147a68;
  lbz r0, 0xd0(r3);
  addi r29, r29, 1;
  cmpwi r0, 0;
  beq lbl_80147a68;
  lbz r0, 0x104(r3);
  addi r29, r29, 1;
  cmpwi r0, 0;
  beq lbl_80147a68;
  lbz r0, 0x138(r3);
  addi r29, r29, 1;
  cmpwi r0, 0;
  beq lbl_80147a68;
  lbz r0, 0x16c(r3);
  addi r29, r29, 1;
  cmpwi r0, 0;
  beq lbl_80147a68;
  addi r3, r3, 0x1a0;
  addi r29, r29, 1;
  bdnz lbl_801479e0;
lbl_80147a68:
  cmpwi r29, 0x10;
  bne lbl_80147a78;
  li r3, 3;
  b lbl_80147ad4;
lbl_80147a78:
  mulli r30, r29, 0x34;
  lis r31, 0x8034;
  addi r31, r31, -28872;
  lbzx r0, r31, r30;
  cmpwi r0, 0;
  bne lbl_80147abc;
  li r0, 1;
  add r3, r31, r30;
  stbx r0, r31, r30;
  mr r4, r26;
  addi r3, r3, 1;
  li r5, 6;
  bl memcpy;
  add r3, r31, r30;
  li r0, 0;
  stb r0, 0xa(r3);
  stb r0, 0xc(r3);
lbl_80147abc:
  lis r4, 0x8034;
  li r3, 0;
  addi r4, r4, -28872;
  add r4, r4, r30;
  sth r27, 8(r4);
  stb r29, 0(r28);
lbl_80147ad4:
  addi r11, r1, 0x20;
  bl _restgpr_26;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: HID_HostRemoveDev
// PAL: 0x80147aec..0x80147bb4
MARK_BINARY_BLOB(HID_HostRemoveDev, 0x80147aec, 0x80147bb4);
asm UNKNOWN_FUNCTION(HID_HostRemoveDev) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_27;
  lis r30, 0x8034;
  mr r27, r3;
  addi r30, r30, -28872;
  lbz r0, 0x400(r30);
  cmpwi cr6, r0, 0;
  bne cr6, lbl_80147b20;
  li r3, 1;
  b lbl_80147b9c;
lbl_80147b20:
  cmplwi cr1, r3, 0x10;
  bgt cr1, lbl_80147b3c;
  mulli r28, r3, 0x34;
  lbzx r0, r30, r28;
  add r29, r30, r28;
  cmpwi r0, 0;
  bne lbl_80147b44;
lbl_80147b3c:
  li r3, 5;
  b lbl_80147b9c;
lbl_80147b44:
  beq cr6, lbl_80147b78;
  bgt cr1, lbl_80147b78;
  beq lbl_80147b78;
  li r31, 1;
  addi r3, r29, 0x1c;
  stb r31, 0xc(r29);
  bl btu_stop_timer;
  lbz r0, 0xa(r29);
  cmplwi r0, 1;
  bne lbl_80147b78;
  stb r31, 0xc(r29);
  mr r3, r27;
  bl hidh_conn_disconnect;
lbl_80147b78:
  li r0, 0;
  lis r3, 0x8034;
  addi r3, r3, -28872;
  stb r0, 0(r29);
  add r4, r3, r28;
  stb r0, 0x10(r4);
  li r3, 0;
  sth r0, 0x16(r4);
  sth r0, 0x14(r4);
lbl_80147b9c:
  addi r11, r1, 0x20;
  bl _restgpr_27;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: HID_HostOpenDev
// PAL: 0x80147bb4..0x80147c18
MARK_BINARY_BLOB(HID_HostOpenDev, 0x80147bb4, 0x80147c18);
asm UNKNOWN_FUNCTION(HID_HostOpenDev) {
  // clang-format off
  nofralloc;
  lis r4, 0x8034;
  addi r4, r4, -28872;
  lbz r0, 0x400(r4);
  cmpwi r0, 0;
  bne lbl_80147bd0;
  li r3, 1;
  blr;
lbl_80147bd0:
  cmplwi r3, 0x10;
  bgt lbl_80147be8;
  mulli r5, r3, 0x34;
  lbzx r0, r4, r5;
  cmpwi r0, 0;
  bne lbl_80147bf0;
lbl_80147be8:
  li r3, 5;
  blr;
lbl_80147bf0:
  add r4, r4, r5;
  lbz r0, 0xa(r4);
  cmpwi r0, 0;
  beq lbl_80147c08;
  li r3, 0xa;
  blr;
lbl_80147c08:
  li r0, 1;
  stb r0, 0xc(r4);
  b hidh_conn_initiate;
  blr;
  // clang-format on
}

// Symbol: HID_HostWriteDev
// PAL: 0x80147c18..0x80147d58
MARK_BINARY_BLOB(HID_HostWriteDev, 0x80147c18, 0x80147d58);
asm UNKNOWN_FUNCTION(HID_HostWriteDev) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_24;
  lis r9, 0x8034;
  lis r31, 0x8028;
  addi r9, r9, -28872;
  mr r25, r3;
  lbz r0, 0x400(r9);
  mr r26, r4;
  mr r27, r5;
  mr r28, r6;
  cmpwi r0, 0;
  mr r29, r7;
  mr r30, r8;
  addi r31, r31, 0x4fa0;
  li r24, 0;
  bne lbl_80147c80;
  lbz r0, 0x401(r9);
  cmplwi r0, 1;
  blt lbl_80147c7c;
  addi r4, r31, 0;
  lis r3, 0x1e;
  bl LogMsg_0;
lbl_80147c7c:
  li r24, 1;
lbl_80147c80:
  cmplwi r25, 0x10;
  bgt lbl_80147ca0;
  mulli r0, r25, 0x34;
  lis r3, 0x8034;
  addi r3, r3, -28872;
  lbzx r0, r3, r0;
  cmpwi r0, 0;
  bne lbl_80147cc4;
lbl_80147ca0:
  lis r3, 0x8034;
  addi r3, r3, -28872;
  lbz r0, 0x401(r3);
  cmplwi r0, 1;
  blt lbl_80147cc0;
  addi r4, r31, 0x18;
  lis r3, 0x1e;
  bl LogMsg_0;
lbl_80147cc0:
  li r24, 5;
lbl_80147cc4:
  mulli r0, r25, 0x34;
  lis r4, 0x8034;
  addi r4, r4, -28872;
  add r3, r4, r0;
  lbz r0, 0xa(r3);
  cmplwi r0, 1;
  beq lbl_80147d00;
  lbz r0, 0x401(r4);
  cmplwi r0, 1;
  blt lbl_80147cfc;
  mr r5, r25;
  addi r4, r31, 0x30;
  lis r3, 0x1e;
  bl LogMsg_1;
lbl_80147cfc:
  li r24, 4;
lbl_80147d00:
  cmpwi r24, 0;
  beq lbl_80147d1c;
  cmpwi r30, 0;
  beq lbl_80147d3c;
  mr r3, r30;
  bl GKI_freebuf;
  b lbl_80147d3c;
lbl_80147d1c:
  mr r3, r25;
  mr r4, r26;
  mr r5, r27;
  mr r6, r28;
  mr r7, r29;
  mr r8, r30;
  bl hidh_conn_snd_data;
  mr r24, r3;
lbl_80147d3c:
  addi r11, r1, 0x30;
  mr r3, r24;
  bl _restgpr_24;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: HID_HostCloseDev
// PAL: 0x80147d58..0x80147df8
MARK_BINARY_BLOB(HID_HostCloseDev, 0x80147d58, 0x80147df8);
asm UNKNOWN_FUNCTION(HID_HostCloseDev) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_27;
  lis r30, 0x8034;
  mr r27, r3;
  addi r30, r30, -28872;
  lbz r0, 0x400(r30);
  cmpwi r0, 0;
  bne lbl_80147d8c;
  li r3, 1;
  b lbl_80147de0;
lbl_80147d8c:
  cmplwi r3, 0x10;
  bgt lbl_80147da8;
  mulli r28, r3, 0x34;
  lbzx r0, r30, r28;
  add r29, r30, r28;
  cmpwi r0, 0;
  bne lbl_80147db0;
lbl_80147da8:
  li r3, 5;
  b lbl_80147de0;
lbl_80147db0:
  li r31, 1;
  addi r3, r29, 0x1c;
  stb r31, 0xc(r29);
  bl btu_stop_timer;
  lbz r0, 0xa(r29);
  cmplwi r0, 1;
  beq lbl_80147dd4;
  li r3, 4;
  b lbl_80147de0;
lbl_80147dd4:
  stb r31, 0xc(r29);
  mr r3, r27;
  bl hidh_conn_disconnect;
lbl_80147de0:
  addi r11, r1, 0x20;
  bl _restgpr_27;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: HID_HostSetSecurityLevel
// PAL: 0x80147df8..0x80148020
MARK_BINARY_BLOB(HID_HostSetSecurityLevel, 0x80147df8, 0x80148020);
asm UNKNOWN_FUNCTION(HID_HostSetSecurityLevel) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  li r5, 0x20;
  li r7, 0x11;
  stw r0, 0x24(r1);
  li r8, 6;
  li r9, 1;
  stw r31, 0x1c(r1);
  lis r31, 0x8028;
  addi r31, r31, 0x4fa0;
  stw r30, 0x18(r1);
  mr r30, r4;
  mr r6, r30;
  stw r29, 0x14(r1);
  mr r29, r3;
  li r3, 0;
  mr r4, r29;
  bl BTM_SetSecurityLevel;
  clrlwi. r0, r3, 0x18;
  bne lbl_80147e70;
  lis r3, 0x8034;
  addi r3, r3, -28872;
  lbz r0, 0x401(r3);
  cmplwi r0, 1;
  blt lbl_80147e68;
  addi r4, r31, 0x54;
  lis r3, 0x1e;
  bl LogMsg_0;
lbl_80147e68:
  li r3, 3;
  b lbl_80148004;
lbl_80147e70:
  mr r4, r29;
  mr r6, r30;
  li r3, 1;
  li r5, 0x20;
  li r7, 0x11;
  li r8, 6;
  li r9, 1;
  bl BTM_SetSecurityLevel;
  clrlwi. r0, r3, 0x18;
  bne lbl_80147ec0;
  lis r3, 0x8034;
  addi r3, r3, -28872;
  lbz r0, 0x401(r3);
  cmplwi r0, 1;
  blt lbl_80147eb8;
  addi r4, r31, 0x74;
  lis r3, 0x1e;
  bl LogMsg_0;
lbl_80147eb8:
  li r3, 3;
  b lbl_80148004;
lbl_80147ec0:
  mr r4, r29;
  li r3, 0;
  li r5, 0x21;
  li r6, 0;
  li r7, 0x11;
  li r8, 6;
  li r9, 2;
  bl BTM_SetSecurityLevel;
  clrlwi. r0, r3, 0x18;
  bne lbl_80147f10;
  lis r3, 0x8034;
  addi r3, r3, -28872;
  lbz r0, 0x401(r3);
  cmplwi r0, 1;
  blt lbl_80147f08;
  addi r4, r31, 0x94;
  lis r3, 0x1e;
  bl LogMsg_0;
lbl_80147f08:
  li r3, 3;
  b lbl_80148004;
lbl_80147f10:
  mr r4, r29;
  li r3, 1;
  li r5, 0x21;
  li r6, 0;
  li r7, 0x11;
  li r8, 6;
  li r9, 2;
  bl BTM_SetSecurityLevel;
  clrlwi. r0, r3, 0x18;
  bne lbl_80147f60;
  lis r3, 0x8034;
  addi r3, r3, -28872;
  lbz r0, 0x401(r3);
  cmplwi r0, 1;
  blt lbl_80147f58;
  addi r4, r31, 0xb4;
  lis r3, 0x1e;
  bl LogMsg_0;
lbl_80147f58:
  li r3, 3;
  b lbl_80148004;
lbl_80147f60:
  mr r4, r29;
  li r3, 1;
  li r5, 0x22;
  li r6, 0;
  li r7, 0x13;
  li r8, 6;
  li r9, 0;
  bl BTM_SetSecurityLevel;
  clrlwi. r0, r3, 0x18;
  bne lbl_80147fb0;
  lis r3, 0x8034;
  addi r3, r3, -28872;
  lbz r0, 0x401(r3);
  cmplwi r0, 1;
  blt lbl_80147fa8;
  addi r4, r31, 0xd4;
  lis r3, 0x1e;
  bl LogMsg_0;
lbl_80147fa8:
  li r3, 3;
  b lbl_80148004;
lbl_80147fb0:
  mr r4, r29;
  li r3, 0;
  li r5, 0x22;
  li r6, 0;
  li r7, 0x13;
  li r8, 6;
  li r9, 0;
  bl BTM_SetSecurityLevel;
  clrlwi. r0, r3, 0x18;
  bne lbl_80148000;
  lis r3, 0x8034;
  addi r3, r3, -28872;
  lbz r0, 0x401(r3);
  cmplwi r0, 1;
  blt lbl_80147ff8;
  addi r4, r31, 0xf4;
  lis r3, 0x1e;
  bl LogMsg_0;
lbl_80147ff8:
  li r3, 3;
  b lbl_80148004;
lbl_80148000:
  li r3, 0;
lbl_80148004:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

#include "spb.h"

#include <rvl/os/osCache.h>

u32 __AXSpbAux3;
u32 __AXSpbAux2;
u32 __AXSpbAux1;
u32 __AXSpbAux0;
u32 __AXSpbMain3;
u32 __AXSpbMain2;
u32 __AXSpbMain1;
u32 __AXSpbMain0;
u32 __AXSpbACS;
u32 __AXSpbACR;
u32 __AXSpbACL;
u32 __AXSpbABS;
u32 __AXSpbABR;
u32 __AXSpbABL;
u32 __AXSpbAAS;
u32 __AXSpbAAR;
u32 __AXSpbAAL;
u32 __AXSpbAS;
u32 __AXSpbAR;
u32 __AXSpbAL;

AXSPB __AXStudio;

// Symbol: __AXGetStudio
// PAL: 0x80126e30..0x80126e3c
AXSPB* __AXGetStudio() { return &__AXStudio; }

// Symbol: __AXDepopFadeMain
// PAL: 0x80126e3c..0x80126ea8
MARK_BINARY_BLOB(__AXDepopFadeMain, 0x80126e3c, 0x80126ea8);
asm UNKNOWN_FUNCTION(__AXDepopFadeMain) {
  // clang-format off
  nofralloc;
  lis r6, 0x2aab;
  lwz r7, 0(r3);
  addi r0, r6, -21845;
  mulhw r0, r0, r7;
  srawi r0, r0, 4;
  srwi r6, r0, 0x1f;
  add. r0, r0, r6;
  beq lbl_80126e94;
  cmpwi r0, 0x14;
  ble lbl_80126e68;
  li r0, 0x14;
lbl_80126e68:
  cmpwi r0, -20;
  bge lbl_80126e74;
  li r0, -20;
lbl_80126e74:
  stw r7, 0(r4);
  mulli r6, r0, 0x60;
  neg r0, r0;
  lwz r4, 0(r3);
  subf r4, r6, r4;
  stw r4, 0(r3);
  sth r0, 0(r5);
  blr;
lbl_80126e94:
  li r0, 0;
  stw r0, 0(r3);
  stw r0, 0(r4);
  sth r0, 0(r5);
  blr;
  // clang-format on
}

// Symbol: __AXDepopFadeRmt
// PAL: 0x80126ea8..0x80126f14
MARK_BINARY_BLOB(__AXDepopFadeRmt, 0x80126ea8, 0x80126f14);
asm UNKNOWN_FUNCTION(__AXDepopFadeRmt) {
  // clang-format off
  nofralloc;
  lis r6, 0x38e4;
  lwz r7, 0(r3);
  addi r0, r6, -29127;
  mulhw r0, r0, r7;
  srawi r0, r0, 2;
  srwi r6, r0, 0x1f;
  add. r0, r0, r6;
  beq lbl_80126f00;
  cmpwi r0, 0x14;
  ble lbl_80126ed4;
  li r0, 0x14;
lbl_80126ed4:
  cmpwi r0, -20;
  bge lbl_80126ee0;
  li r0, -20;
lbl_80126ee0:
  stw r7, 0(r4);
  mulli r6, r0, 0x12;
  neg r0, r0;
  lwz r4, 0(r3);
  subf r4, r6, r4;
  stw r4, 0(r3);
  sth r0, 0(r5);
  blr;
lbl_80126f00:
  li r0, 0;
  stw r0, 0(r3);
  stw r0, 0(r4);
  sth r0, 0(r5);
  blr;
  // clang-format on
}

// Symbol: __AXPrintStudio
// PAL: 0x80126f14..0x8012708c
MARK_BINARY_BLOB(__AXPrintStudio, 0x80126f14, 0x8012708c);
asm UNKNOWN_FUNCTION(__AXPrintStudio) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  la r3, __AXSpbAux3;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  lis r31, 0x8030;
  addi r4, r31, -32192;
  addi r5, r4, 4;
  bl __AXDepopFadeMain;
  addi r31, r31, -32192;
  la r3, __AXSpbAux2;
  addi r4, r31, 6;
  addi r5, r31, 0xa;
  bl __AXDepopFadeMain;
  addi r4, r31, 0xc;
  addi r5, r31, 0x10;
  la r3, __AXSpbAux1;
  bl __AXDepopFadeMain;
  addi r4, r31, 0x12;
  addi r5, r31, 0x16;
  la r3, __AXSpbAux0;
  bl __AXDepopFadeMain;
  addi r4, r31, 0x18;
  addi r5, r31, 0x1c;
  la r3, __AXSpbMain3;
  bl __AXDepopFadeMain;
  addi r4, r31, 0x1e;
  addi r5, r31, 0x22;
  la r3, __AXSpbMain2;
  bl __AXDepopFadeMain;
  addi r4, r31, 0x24;
  addi r5, r31, 0x28;
  la r3, __AXSpbMain1;
  bl __AXDepopFadeMain;
  addi r4, r31, 0x2a;
  addi r5, r31, 0x2e;
  la r3, __AXSpbMain0;
  bl __AXDepopFadeMain;
  addi r4, r31, 0x30;
  addi r5, r31, 0x34;
  la r3, __AXSpbACS;
  bl __AXDepopFadeMain;
  addi r4, r31, 0x36;
  addi r5, r31, 0x3a;
  la r3, __AXSpbACR;
  bl __AXDepopFadeMain;
  addi r4, r31, 0x3c;
  addi r5, r31, 0x40;
  la r3, __AXSpbACL;
  bl __AXDepopFadeMain;
  addi r4, r31, 0x42;
  addi r5, r31, 0x46;
  la r3, __AXSpbABS;
  bl __AXDepopFadeMain;
  addi r4, r31, 0x48;
  addi r5, r31, 0x4c;
  la r3, __AXSpbABR;
  bl __AXDepopFadeRmt;
  addi r4, r31, 0x54;
  addi r5, r31, 0x58;
  la r3, __AXSpbABL;
  bl __AXDepopFadeRmt;
  addi r4, r31, 0x60;
  addi r5, r31, 0x64;
  la r3, __AXSpbAAS;
  bl __AXDepopFadeRmt;
  addi r4, r31, 0x6c;
  addi r5, r31, 0x70;
  la r3, __AXSpbAAR;
  bl __AXDepopFadeRmt;
  addi r4, r31, 0x4e;
  addi r5, r31, 0x52;
  la r3, __AXSpbAAL;
  bl __AXDepopFadeRmt;
  addi r4, r31, 0x5a;
  addi r5, r31, 0x5e;
  la r3, __AXSpbAS;
  bl __AXDepopFadeRmt;
  addi r4, r31, 0x66;
  addi r5, r31, 0x6a;
  la r3, __AXSpbAR;
  bl __AXDepopFadeRmt;
  addi r4, r31, 0x72;
  addi r5, r31, 0x76;
  la r3, __AXSpbAL;
  bl __AXDepopFadeRmt;
  mr r3, r31;
  li r4, 0x78;
  bl DCFlushRange;
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: __AXSPBInit
// PAL: 0x8012708c..0x801270e4
void __AXSPBInit() {
  __AXSpbAL = 0;
  __AXSpbAR = 0;
  __AXSpbAS = 0;
  __AXSpbAAL = 0;
  __AXSpbAAR = 0;
  __AXSpbAAS = 0;
  __AXSpbABL = 0;
  __AXSpbABR = 0;
  __AXSpbABS = 0;
  __AXSpbACL = 0;
  __AXSpbACR = 0;
  __AXSpbACS = 0;
  __AXSpbMain0 = 0;
  __AXSpbMain1 = 0;
  __AXSpbMain2 = 0;
  __AXSpbMain3 = 0;
  __AXSpbAux0 = 0;
  __AXSpbAux1 = 0;
  __AXSpbAux2 = 0;
  __AXSpbAux3 = 0;
}

// Symbol: __AXDepopVoice
// PAL: 0x801270e4..0x80127250
MARK_BINARY_BLOB(__AXDepopVoice, 0x801270e4, 0x80127250);
asm UNKNOWN_FUNCTION(__AXDepopVoice) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_27;
  lwz r5, __AXSpbAux3;
  lha r0, 0x52(r3);
  lwz r4, __AXSpbAux0;
  add r0, r5, r0;
  lwz r7, __AXSpbMain1;
  stw r0, __AXSpbAux3;
  lwz r6, __AXSpbACR;
  lha r0, 0x54(r3);
  lwz r5, __AXSpbAux2;
  add r0, r4, r0;
  lwz r4, __AXSpbMain3;
  stw r0, __AXSpbAux0;
  lwz r27, __AXSpbMain0;
  lha r0, 0x56(r3);
  lwz r28, __AXSpbACL;
  add r0, r7, r0;
  lwz r29, __AXSpbAux1;
  stw r0, __AXSpbMain1;
  lwz r30,__AXSpbMain2;
  lha r0, 0x58(r3);
  lwz r31, __AXSpbACS;
  add r0, r6, r0;
  lwz r12, __AXSpbABS;
  stw r0, __AXSpbACR;
  lwz r11, __AXSpbABR;
  lha r0, 0x5a(r3);
  lwz r10, __AXSpbABL;
  add r0, r5, r0;
  lwz r9, __AXSpbAAS;
  stw r0, __AXSpbAux2;
  lwz r8, __AXSpbAAR;
  lha r0, 0x5c(r3);
  lwz r7, __AXSpbAAL;
  add r0, r4, r0;
  lwz r6, __AXSpbAS;
  stw r0, __AXSpbMain3;
  lwz r5, __AXSpbAR;
  lha r0, 0x5e(r3);
  lwz r4, __AXSpbAL;
  add r0, r27, r0;
  stw r0, __AXSpbMain0;
  lha r0, 0x60(r3);
  add r0, r28, r0;
  stw r0, __AXSpbACL;
  lha r0, 0x62(r3);
  add r0, r29, r0;
  stw r0, __AXSpbAux1;
  lha r0, 0x64(r3);
  add r0, r30, r0;
  stw r0,__AXSpbMain2;
  lha r0, 0x66(r3);
  add r0, r31, r0;
  stw r0, __AXSpbACS;
  lha r0, 0x68(r3);
  add r0, r12, r0;
  stw r0, __AXSpbABS;
  lha r0, 0xfa(r3);
  add r0, r11, r0;
  addi r11, r1, 0x20;
  stw r0, __AXSpbABR;
  lha r0, 0xfc(r3);
  add r0, r10, r0;
  stw r0, __AXSpbABL;
  lha r0, 0xfe(r3);
  add r0, r9, r0;
  stw r0, __AXSpbAAS;
  lha r0, 0x100(r3);
  add r0, r8, r0;
  stw r0, __AXSpbAAR;
  lha r0, 0x102(r3);
  add r0, r7, r0;
  stw r0, __AXSpbAAL;
  lha r0, 0x104(r3);
  add r0, r6, r0;
  stw r0, __AXSpbAS;
  lha r0, 0x106(r3);
  add r0, r5, r0;
  stw r0, __AXSpbAR;
  lha r0, 0x108(r3);
  add r0, r4, r0;
  stw r0, __AXSpbAL;
  bl _restgpr_27;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

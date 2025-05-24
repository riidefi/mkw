#include "gxDisplayList.h"

#include <string.h>

#include <rvl/os/osInterrupt.h>

#include "gx.h"
#include "gxBump.h"
#include "gxFifo.h"
#include "gxGeometry.h"
#include "gxMisc.h"

// Symbol: GXBeginDisplayList
// PAL: 0x80172e00..0x80172eb4
MARK_BINARY_BLOB(GXBeginDisplayList, 0x80172e00, 0x80172eb4);
asm UNKNOWN_FUNCTION(GXBeginDisplayList) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_27;
  lwz r30, gx;
  lis r31, 0x8034;
  addi r31, r31, 0x4090;
  mr r27, r3;
  lwz r0, 0x5fc(r30);
  mr r28, r4;
  addi r29, r31, 0;
  cmpwi r0, 0;
  beq lbl_80172e3c;
  bl __GXSetDirtyState;
lbl_80172e3c:
  lbz r0, 0x5f9(r30);
  cmpwi r0, 0;
  beq lbl_80172e58;
  mr r4, r30;
  addi r3, r31, 0x80;
  li r5, 0x600;
  bl memcpy;
lbl_80172e58:
  add r4, r27, r28;
  li r3, 0;
  addi r4, r4, -4;
  stw r27, 0(r29);
  li r0, 1;
  stw r4, 4(r29);
  stw r28, 8(r29);
  stw r3, 0x1c(r29);
  stw r27, 0x14(r29);
  stw r27, 0x18(r29);
  stb r0, 0x5f8(r30);
  bl GXFlush;
  addi r3, r31, 0x680;
  bl GXGetCPUFifo;
  addi r3, r31, 0;
  bl GXSetCPUFifo;
  bl GXResetWriteGatherPipe;
  addi r11, r1, 0x20;
  bl _restgpr_27;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: GXEndDisplayList
// PAL: 0x80172eb4..0x80172f64
MARK_BINARY_BLOB(GXEndDisplayList, 0x80172eb4, 0x80172f64);
asm UNKNOWN_FUNCTION(GXEndDisplayList) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_26;
  lis r30, 0x8034;
  addi r30, r30, 0x4090;
  bl GXFlush;
  addi r3, r30, 0;
  bl GXGetCPUFifo;
  addi r3, r30, 0;
  bl GXGetFifoWrap;
  mr r31, r3;
  addi r3, r30, 0x680;
  bl GXSetCPUFifo;
  lwz r29, gx;
  lbz r0, 0x5f9(r29);
  cmpwi r0, 0;
  beq lbl_80172f2c;
  bl OSDisableInterrupts;
  lwz r28, gx;
  mr r27, r3;
  addi r4, r30, 0x80;
  li r5, 0x600;
  lwz r26, 8(r28);
  mr r3, r28;
  bl memcpy;
  stw r26, 8(r28);
  mr r3, r27;
  bl OSRestoreInterrupts;
lbl_80172f2c:
  clrlwi. r0, r31, 0x18;
  li r0, 0;
  stb r0, 0x5f8(r29);
  bne lbl_80172f48;
  addi r3, r30, 0;
  bl GXGetFifoCount;
  b lbl_80172f4c;
lbl_80172f48:
  li r3, 0;
lbl_80172f4c:
  addi r11, r1, 0x20;
  bl _restgpr_26;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: GXCallDisplayList
// PAL: 0x80172f64..0x80172fd8
MARK_BINARY_BLOB(GXCallDisplayList, 0x80172f64, 0x80172fd8);
asm UNKNOWN_FUNCTION(GXCallDisplayList) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  lwz r31, gx;
  stw r30, 0x18(r1);
  mr r30, r4;
  stw r29, 0x14(r1);
  mr r29, r3;
  lwz r0, 0x5fc(r31);
  cmpwi r0, 0;
  beq lbl_80172f98;
  bl __GXSetDirtyState;
lbl_80172f98:
  lwz r0, 0(r31);
  cmpwi r0, 0;
  bne lbl_80172fa8;
  bl __GXSendFlushPrim;
lbl_80172fa8:
  lis r3, 0xcc01;
  li r0, 0x40;
  stb r0, -0x8000(r3);
  stw r29, -0x8000(r3);
  stw r30, -0x8000(r3);
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

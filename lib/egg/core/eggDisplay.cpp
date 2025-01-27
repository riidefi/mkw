#include "eggDisplay.hpp"

#include <rvl/os/os.h>
#include <rvl/gx.h>
#include <rvl/gx/gxDraw.h>
#include <rvl/gx/gxFrameBuf.h>
#include <rvl/gx/gxMisc.h>
#include <egg/core/eggVideo.hpp>
#include <egg/core/eggSystem.hpp>
#include <egg/core/eggXfbManager.hpp>

extern "C" {

// Extern function references.
// PAL: 0x801b99ec
extern UNKNOWN_FUNCTION(VIWaitForRetrace);
// PAL: 0x801bab2c
extern UNKNOWN_FUNCTION(VISetBlack);
// PAL: 0x801baba4
extern UNKNOWN_FUNCTION(VIGetRetraceCount);
// PAL: 0x80243ed0
extern UNKNOWN_FUNCTION(getTickPerVRetrace__Q23EGG5VideoFv);
// PAL: 0x80244268
extern UNKNOWN_FUNCTION(copyEFB__Q23EGG10XfbManagerFb);
// PAL: 0x802442e8
extern UNKNOWN_FUNCTION(setNextFrameBuffer__Q23EGG10XfbManagerFv);

extern UNKNOWN_FUNCTION(calcFrequency__Q23EGG7DisplayFv);
extern UNKNOWN_FUNCTION(endRender__Q23EGG7DisplayFv);
extern UNKNOWN_FUNCTION(copyEFBtoXFB__Q23EGG7DisplayFv);

// Symbol: __ct__Q23EGG7DisplayFUc
// PAL: 0x80219e68..0x80219eb0
MARK_BINARY_BLOB(__ct__Q23EGG7DisplayFUc, 0x80219e68, 0x80219eb0);
asm void __ct__Q23EGG7DisplayFUc() {
  // clang-format off
  nofralloc;
  li r7, 0;
  lis r8, 0x802a;
  lis r6, 0x8081;
  lis r5, 0x100;
  addi r8, r8, 0x2b28;
  ori r0, r7, 1;
  addi r6, r6, -32513;
  addi r5, r5, -1;
  stw r8, 4(r3);
  stb r4, 8(r3);
  stb r7, 9(r3);
  stw r7, 0xc(r3);
  stw r7, 0x10(r3);
  stw r6, 0x14(r3);
  stw r5, 0x18(r3);
  stw r7, 0x1c(r3);
  stb r0, 0(r3);
  blr;
  // clang-format on
}
}

namespace EGG {

// Display::Display(u8 wait) :
//     mScreenStateFlag(0),
//     mMaxRetraces(wait),
//     mRetraceCount(0),
//     mFrameCount(0),
//     mClearColor(0x808080ff),
//     mClearZ(0x00ffffff),
//     mBeginTick(0)
// {
//     setFlag(0);
// }

// Symbol: getTickPerFrame__Q23EGG7DisplayFv
// PAL: 0x80219eb0..0x80219eb4
MARK_BINARY_BLOB(getTickPerFrame__Q23EGG7DisplayFv, 0x80219eb0, 0x80219eb4);
asm u32 Display::getTickPerFrame(void) {
  // clang-format off
  nofralloc;
  b getTickPerVRetrace__Q23EGG5VideoFv;
  // clang-format on
}

// Symbol: beginFrame__Q23EGG7DisplayFv
// PAL: 0x80219eb4..0x80219fa8
MARK_BINARY_BLOB(beginFrame__Q23EGG7DisplayFv, 0x80219eb4, 0x80219fac);
asm void Display::beginFrame(void) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stmw r27, 0xc(r1);
  mr r28, r3;
  lbz r31, 8(r3);
  bl VIGetRetraceCount;
  lwz r0, 0xc(r28);
  addi r29, r31, -1;
  subf r30, r0, r3;
lbl_80219edc:
  cmplw r30, r29;
  blt lbl_80219f68;
  lbz r0, 9(r28);
  clrlwi. r0, r0, 0x1f;
  beq lbl_80219f50;
  lwz r3, -0x5ca0(r13);
  lwz r12, 0(r3);
  lwz r12, 8(r12);
  mtctr r12;
  bctrl;
  lbz r0, 4(r3);
  mr r27, r3;
  clrlwi r0, r0, 0x1f;
  cntlzw r0, r0;
  srwi r3, r0, 5;
  bl VISetBlack;
  lbz r0, 4(r27);
  clrlwi. r0, r0, 0x1f;
  bne lbl_80219f38;
  lbz r0, 4(r27);
  ori r0, r0, 1;
  stb r0, 4(r27);
  b lbl_80219f44;
lbl_80219f38:
  lbz r0, 4(r27);
  rlwinm r0, r0, 0, 0x18, 0x1e;
  stb r0, 4(r27);
lbl_80219f44:
  lbz r0, 9(r28);
  rlwinm r0, r0, 0, 0x18, 0x1e;
  stb r0, 9(r28);
lbl_80219f50:
  lwz r3, -0x5ca0(r13);
  lwz r12, 0(r3);
  lwz r12, 0x14(r12);
  mtctr r12;
  bctrl;
  bl setNextFrameBuffer__Q23EGG10XfbManagerFv;
lbl_80219f68:
  bl VIWaitForRetrace;
  addi r30, r30, 1;
  cmplw r30, r31;
  blt lbl_80219edc;
  mr r3, r28;
  bl calcFrequency__Q23EGG7DisplayFv;
  bl VIGetRetraceCount;
  lwz r4, 0x10(r28);
  stw r3, 0xc(r28);
  addi r0, r4, 1;
  stw r0, 0x10(r28);
  lmw r27, 0xc(r1);
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

void Display::beginRender() {}

void Display::endRender() { copyEFBtoXFB__Q23EGG7DisplayFv(); }

void Display::endFrame() { GXDraw(); }

// void Display::copyEFBtoXFB() {
//   if (hasFlag(0)) {
//     // need bytewise copy
//     nw4r::ut::Color c(mClearColor);
//     GXSetCopyClear(c, mClearZ);
//   }
//   GXRenderModeObj const* pObj = BaseSystem::sSystem->getVideo()->pRenderMode;
//   bool b = (pObj->aa == 0);
//   GXSetCopyFilter(pObj->aa, pObj->sample, b, pObj->vert_filter);
//   bool efbFlag = hasFlag(0);
//   BaseSystem::sSystem->getXfbMgr()->copyEFB(efbFlag);
// }

// Symbol: copyEFBtoXFB__Q23EGG7DisplayFv
// PAL: 0x80219fb4..0x8021a06c
MARK_BINARY_BLOB(copyEFBtoXFB__Q23EGG7DisplayFv, 0x80219fb4, 0x8021a06c);
asm void Display::copyEFBtoXFB(void) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r3;
  lbz r0, 0(r3);
  clrlwi. r0, r0, 0x1f;
  beq lbl_8021a004;
  lbz r0, 0x14(r3);
  addi r4, r1, 8;
  stb r0, 8(r1);
  lbz r0, 0x15(r3);
  stb r0, 9(r1);
  lbz r0, 0x16(r3);
  stb r0, 0xa(r1);
  lbz r0, 0x17(r3);
  mr r3, r4;
  stb r0, 0xb(r1);
  lwz r4, 0x18(r31);
  bl GXSetCopyClear;
lbl_8021a004:
  lwz r3, -0x5ca0(r13);
  lwz r12, 0(r3);
  lwz r12, 8(r12);
  mtctr r12;
  bctrl;
  lwz r5, 0(r3);
  lbz r3, 0x19(r5);
  addi r4, r5, 0x1a;
  addi r6, r5, 0x32;
  cntlzw r0, r3;
  rlwinm r5, r0, 0x1b, 0x18, 0x1f;
  bl GXSetCopyFilter;
  lwz r3, -0x5ca0(r13);
  lbz r0, 0(r31);
  lwz r12, 0(r3);
  clrlwi r31, r0, 0x1f;
  lwz r12, 0x14(r12);
  mtctr r12;
  bctrl;
  mr r4, r31;
  bl copyEFB__Q23EGG10XfbManagerFb;
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

u32 __OSConsoleBusSpeed : 0x800000f8;

void Display::calcFrequency() {
  const s32 endTick = OSGetTick();
  mDeltaTick = endTick - mBeginTick;
  mFrequency =
      1000000.0f / ((mDeltaTick * 8) / ((__OSConsoleBusSpeed >> 2) / 125000));
  mBeginTick = endTick;
}

} // namespace EGG

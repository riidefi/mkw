#include "ppcArch.h"

#include <rvl/os/osError.h>

// Symbol: PPCMfmsr
// PAL: 0x8012e564..0x8012e56c
asm u32 PPCMfmsr() {
  nofralloc;
  mfmsr r3;
  blr;
}

// Symbol: PPCMtmsr
// PAL: 0x8012e56c..0x8012e574
asm void PPCMtmsr(u32) {
  nofralloc;
  mtmsr r3;
  blr;
}

// Symbol: PPCMfhid0
// PAL: 0x8012e574..0x8012e57c
asm u32 PPCMfhid0() {
  nofralloc;
  mfspr r3, 0x3f0;
  blr;
}

// Symbol: PPCMthid0
// PAL: 0x8012e57c..0x8012e584
asm void PPCMthid0(u32) {
  nofralloc;
  mtspr 0x3f0, r3;
  blr;
}

// Symbol: PPCMfl2cr
// PAL: 0x8012e584..0x8012e58c
asm u32 PPCMfl2cr() {
  nofralloc;
  mfspr r3, 0x3f9;
  blr;
}

// Symbol: PPCMtl2cr
// PAL: 0x8012e58c..0x8012e594
asm void PPCMtl2cr(u32) {
  nofralloc;
  mtspr 0x3f9, r3;
  blr;
}

// Symbol: PPCMtdec
// PAL: 0x8012e594..0x8012e59c
asm void PPCMtdec(u32) {
  nofralloc;
  mtspr 0x16, r3;
  blr;
}

// Symbol: PPCSync
// PAL: 0x8012e59c..0x8012e5a4
asm void PPCSync() {
  nofralloc;
  sc;
  blr;
}

// Symbol: PPCHalt
// PAL: 0x8012e5a4..0x8012e5b8
MARK_BINARY_BLOB(PPCHalt, 0x8012e5a4, 0x8012e5b8);
asm void PPCHalt() {
  // clang-format off
  nofralloc;
  sync;
lbl_8012e5a8:
  nop;
  li r3, 0;
  nop;
  b lbl_8012e5a8;
  // clang-format on
}

// Symbol: PPCMtmmcr0
// PAL: 0x8012e5b8..0x8012e5c0
asm void PPCMtmmcr0(u32) {
  nofralloc;
  mtspr 0x3b8, r3;
  blr;
}

// Symbol: PPCMtmmcr1
// PAL: 0x8012e5c0..0x8012e5c8
asm void PPCMtmmcr1(u32) {
  nofralloc;
  mtspr 0x3bc, r3;
  blr;
}

// Symbol: PPCMtpmc1
// PAL: 0x8012e5c8..0x8012e5d0
asm void PPCMtpmc1(u32) {
  nofralloc;
  mtspr 0x3b9, r3;
  blr;
}

// Symbol: PPCMtpmc2
// PAL: 0x8012e5d0..0x8012e5d8
asm void PPCMtpmc2(u32) {
  nofralloc;
  mtspr 0x3ba, r3;
  blr;
}

// Symbol: PPCMtpmc3
// PAL: 0x8012e5d8..0x8012e5e0
asm void PPCMtpmc3(u32) {
  nofralloc;
  mtspr 0x3bd, r3;
  blr;
}

// Symbol: PPCMtpmc4
// PAL: 0x8012e5e0..0x8012e5e8
asm void PPCMtpmc4(u32) {
  nofralloc;
  mtspr 0x3be, r3;
  blr;
}

// Symbol: PPCMffpscr
// PAL: 0x8012e5e8..0x8012e608
MARK_BINARY_BLOB(PPCMffpscr, 0x8012e5e8, 0x8012e608);
asm u32 PPCMffpscr() {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  stfd f31, 0x18(r1);
  mffs f31;
  stfd f31, 8(r1);
  lfd f31, 0x18(r1);
  lwz r3, 0xc(r1);
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: PPCMtfpscr
// PAL: 0x8012e608..0x8012e630
MARK_BINARY_BLOB(PPCMtfpscr, 0x8012e608, 0x8012e630);
asm void PPCMtfpscr(u32) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  stfd f31, 0x18(r1);
  li r4, 0;
  stw r3, 0xc(r1);
  stw r4, 8(r1);
  lfd f31, 8(r1);
  mtfsf 0xff, f31;
  lfd f31, 0x18(r1);
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: PPCMfhid2
// PAL: 0x8012e630..0x8012e638
asm u32 PPCMfhid2() {
  nofralloc;
  mfspr r3, 0x398;
  blr;
}

// Symbol: PPCMthid2
// PAL: 0x8012e638..0x8012e640
asm void PPCMthid2(register u32 x) {
  nofralloc;
  mtspr 0x398, x;
  blr;
}

// Symbol: PPCMfwpar
// PAL: 0x8012e640..0x8012e64c
asm u32 PPCMfwpar() {
  nofralloc;
  sync;
  mfspr r3, 0x399;
  blr;
}

// Symbol: PPCMtwpar
// PAL: 0x8012e64c..0x8012e654
asm void PPCMtwpar(register u32 x) {
  nofralloc;
  mtspr 0x399, x;
  blr;
}

// Symbol: PPCDisableSpeculation
// PAL: 0x8012e654..0x8012e67c
void PPCDisableSpeculation() { PPCMthid0(PPCMfhid0() | 0x00000200); }

// Symbol: PPCSetFpNonIEEEMode
// PAL: 0x8012e67c..0x8012e684
asm void PPCSetFpNonIEEEMode() {
  nofralloc;
  mtfsb1 0x1d;
  blr;
}

// Symbol: PPCMthid4
// PAL: 0x8012e684..0x8012e6d4
void PPCMthid4(register u32 x) {
  if (x & 0x80000000) {
    asm { mtspr 0x3f3, x; }
  } else {
    OSReport("H4A should not be cleared because of Broadway errata.\n");
    x |= 0x80000000;
    asm { mtspr 0x3f3, x; }
  }
}

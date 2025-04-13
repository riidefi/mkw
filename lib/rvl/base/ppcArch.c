#include "ppcArch.h"

#include <rvl/os/osError.h>

#ifdef __CWCC__

asm u32 PPCMfmsr() {
  nofralloc;
  mfmsr r3;
  blr;
}

asm void PPCMtmsr(u32) {
  nofralloc;
  mtmsr r3;
  blr;
}

asm u32 PPCMfhid0() {
  nofralloc;
  mfspr r3, 0x3f0;
  blr;
}

asm void PPCMthid0(u32) {
  nofralloc;
  mtspr 0x3f0, r3;
  blr;
}

asm u32 PPCMfl2cr() {
  nofralloc;
  mfspr r3, 0x3f9;
  blr;
}

asm void PPCMtl2cr(u32) {
  nofralloc;
  mtspr 0x3f9, r3;
  blr;
}

asm void PPCMtdec(u32) {
  nofralloc;
  mtspr 0x16, r3;
  blr;
}

asm void PPCSync() {
  nofralloc;
  sc;
  blr;
}

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

asm void PPCMtmmcr0(u32) {
  nofralloc;
  mtspr 0x3b8, r3;
  blr;
}

asm void PPCMtmmcr1(u32) {
  nofralloc;
  mtspr 0x3bc, r3;
  blr;
}

asm void PPCMtpmc1(u32) {
  nofralloc;
  mtspr 0x3b9, r3;
  blr;
}

asm void PPCMtpmc2(u32) {
  nofralloc;
  mtspr 0x3ba, r3;
  blr;
}

asm void PPCMtpmc3(u32) {
  nofralloc;
  mtspr 0x3bd, r3;
  blr;
}

asm void PPCMtpmc4(u32) {
  nofralloc;
  mtspr 0x3be, r3;
  blr;
}

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

asm u32 PPCMfhid2() {
  nofralloc;
  mfspr r3, 0x398;
  blr;
}

asm void PPCMthid2(register u32 x) {
  nofralloc;
  mtspr 0x398, x;
  blr;
}

asm u32 PPCMfwpar() {
  nofralloc;
  sync;
  mfspr r3, 0x399;
  blr;
}

asm void PPCMtwpar(register u32 x) {
  nofralloc;
  mtspr 0x399, x;
  blr;
}

void PPCDisableSpeculation() { PPCMthid0(PPCMfhid0() | 0x00000200); }

asm void PPCSetFpNonIEEEMode() {
  nofralloc;
  mtfsb1 0x1d;
  blr;
}

void PPCMthid4(register u32 x) {
  if (x & 0x80000000) {
    asm { mtspr 0x3f3, x; }
  } else {
    OSReport("H4A should not be cleared because of Broadway errata.\n");
    x |= 0x80000000;
    asm { mtspr 0x3f3, x; }
  }
}

#endif

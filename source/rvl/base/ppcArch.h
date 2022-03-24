#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x8012e564..0x8012e56c
u32 PPCMfmsr();
// PAL: 0x8012e56c..0x8012e574
void PPCMtmsr(u32);
// PAL: 0x8012e574..0x8012e57c
u32 PPCMfhid0();
// PAL: 0x8012e57c..0x8012e584
void PPCMthid0(u32);
// PAL: 0x8012e584..0x8012e58c
u32 PPCMfl2cr();
// PAL: 0x8012e58c..0x8012e594
void PPCMtl2cr(u32);
// PAL: 0x8012e594..0x8012e59c
void PPCMtdec(u32);
// PAL: 0x8012e59c..0x8012e5a4
void PPCSync();
// PAL: 0x8012e5a4..0x8012e5b8
void PPCHalt();
// PAL: 0x8012e5b8..0x8012e5c0
void PPCMtmmcr0(u32);
// PAL: 0x8012e5c0..0x8012e5c8
void PPCMtmmcr1(u32);
// PAL: 0x8012e5c8..0x8012e5d0
void PPCMtpmc1(u32);
// PAL: 0x8012e5d0..0x8012e5d8
void PPCMtpmc2(u32);
// PAL: 0x8012e5d8..0x8012e5e0
void PPCMtpmc3(u32);
// PAL: 0x8012e5e0..0x8012e5e8
void PPCMtpmc4(u32);
// PAL: 0x8012e5e8..0x8012e608
u32 PPCMffpscr();
// PAL: 0x8012e608..0x8012e630
void PPCMtfpscr(u32);
// PAL: 0x8012e630..0x8012e638
u32 PPCMfhid2();
// PAL: 0x8012e638..0x8012e640
void PPCMthid2(u32);
// PAL: 0x8012e640..0x8012e64c
u32 PPCMfwpar();
// PAL: 0x8012e64c..0x8012e654
void PPCMtwpar(u32);
// PAL: 0x8012e654..0x8012e67c
void PPCDisableSpeculation();
// PAL: 0x8012e67c..0x8012e684
void PPCSetFpNonIEEEMode();
// PAL: 0x8012e684..0x8012e6d4
void PPCMthid4(u32);

#ifdef __cplusplus
}
#endif

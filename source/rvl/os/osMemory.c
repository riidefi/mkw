#include "osMemory.h"

// Extern function references.
// PAL: 0x8002159c
extern UNKNOWN_FUNCTION(_savegpr_26);
// PAL: 0x800215e8
extern UNKNOWN_FUNCTION(_restgpr_26);
// PAL: 0x801a1600
extern UNKNOWN_FUNCTION(DCInvalidateRange);
// PAL: 0x801a162c
extern UNKNOWN_FUNCTION(DCFlushRange);
// PAL: 0x801a2a14
extern UNKNOWN_FUNCTION(__OSUnhandledException);
// PAL: 0x801a65ac
extern UNKNOWN_FUNCTION(OSDisableInterrupts);
// PAL: 0x801a65d4
extern UNKNOWN_FUNCTION(OSRestoreInterrupts);
// PAL: 0x801a65f8
extern UNKNOWN_FUNCTION(__OSSetInterruptHandler);
// PAL: 0x801a693c
extern UNKNOWN_FUNCTION(__OSMaskInterrupts);
// PAL: 0x801a69bc
extern UNKNOWN_FUNCTION(__OSUnmaskInterrupts);
// PAL: 0x801a8238
extern UNKNOWN_FUNCTION(OSRegisterShutdownFunction);

// Symbol: OSGetPhysicalMem1Size
// PAL: 0x801a75d0..0x801a75dc
MARK_BINARY_BLOB(OSGetPhysicalMem1Size, 0x801a75d0, 0x801a75dc);
asm UNKNOWN_FUNCTION(OSGetPhysicalMem1Size) {
  // clang-format off
  nofralloc;
  lis r3, 0x8000;
  lwz r3, 0x3100(r3);
  blr;
  // clang-format on
}

// Symbol: OSGetPhysicalMem2Size
// PAL: 0x801a75dc..0x801a75e8
MARK_BINARY_BLOB(OSGetPhysicalMem2Size, 0x801a75dc, 0x801a75e8);
asm UNKNOWN_FUNCTION(OSGetPhysicalMem2Size) {
  // clang-format off
  nofralloc;
  lis r3, 0x8000;
  lwz r3, 0x3118(r3);
  blr;
  // clang-format on
}

// Symbol: OSGetConsoleSimulatedMem1Size
// PAL: 0x801a75e8..0x801a75f4
MARK_BINARY_BLOB(OSGetConsoleSimulatedMem1Size, 0x801a75e8, 0x801a75f4);
asm UNKNOWN_FUNCTION(OSGetConsoleSimulatedMem1Size) {
  // clang-format off
  nofralloc;
  lis r3, 0x8000;
  lwz r3, 0x3104(r3);
  blr;
  // clang-format on
}

// Symbol: OSGetConsoleSimulatedMem2Size
// PAL: 0x801a75f4..0x801a7600
MARK_BINARY_BLOB(OSGetConsoleSimulatedMem2Size, 0x801a75f4, 0x801a7600);
asm UNKNOWN_FUNCTION(OSGetConsoleSimulatedMem2Size) {
  // clang-format off
  nofralloc;
  lis r3, 0x8000;
  lwz r3, 0x311c(r3);
  blr;
  // clang-format on
}

// Symbol: OnShutdown
// PAL: 0x801a7600..0x801a763c
MARK_BINARY_BLOB(OnShutdown, 0x801a7600, 0x801a763c);
asm UNKNOWN_FUNCTION(OnShutdown) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmpwi r3, 0;
  stw r0, 0x14(r1);
  beq lbl_801a7628;
  li r0, 0xff;
  lis r3, 0xcc00;
  sth r0, 0x4010(r3);
  lis r3, 0xf000;
  bl __OSMaskInterrupts;
lbl_801a7628:
  lwz r0, 0x14(r1);
  li r3, 1;
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: MEMIntrruptHandler
// PAL: 0x801a763c..0x801a7684
MARK_BINARY_BLOB(MEMIntrruptHandler, 0x801a763c, 0x801a7684);
asm UNKNOWN_FUNCTION(MEMIntrruptHandler) {
  // clang-format off
  nofralloc;
  lis r8, 0xcc00;
  lis r3, 0x8034;
  lhz r5, 0x401e(r8);
  li r0, 0;
  lhz r7, 0x4024(r8);
  addi r3, r3, 0x70f0;
  lhz r6, 0x4022(r8);
  rlwimi r6, r7, 0x10, 6, 0xf;
  sth r0, 0x4020(r8);
  lwz r12, 0x3c(r3);
  cmpwi r12, 0;
  beq lbl_801a767c;
  li r3, 0xf;
  crclr 6;
  mtctr r12;
  bctr;
lbl_801a767c:
  li r3, 0xf;
  b __OSUnhandledException;
  // clang-format on
}

// Symbol: OSProtectRange
// PAL: 0x801a7684..0x801a774c
MARK_BINARY_BLOB(OSProtectRange, 0x801a7684, 0x801a774c);
asm UNKNOWN_FUNCTION(OSProtectRange) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  addi r11, r1, 0x20;
  bl _savegpr_26;
  cmplwi r3, 4;
  mr r26, r3;
  bge lbl_801a7734;
  add r3, r4, r5;
  rlwinm r28, r4, 0, 0, 0x15;
  addi r0, r3, 0x3ff;
  clrlwi r27, r6, 0x1e;
  rlwinm r30, r0, 0, 0, 0x15;
  mr r3, r28;
  subf r4, r28, r30;
  bl DCFlushRange;
  bl OSDisableInterrupts;
  lis r0, 0x8000;
  mr r29, r3;
  srw r31, r0, r26;
  mr r3, r31;
  bl __OSMaskInterrupts;
  lis r5, 0xcc00;
  slwi r0, r26, 2;
  add r4, r5, r0;
  rlwinm r3, r30, 0x16, 0x10, 0x1f;
  rlwinm r0, r28, 0x16, 0x10, 0x1f;
  slwi r6, r26, 1;
  sth r0, 0x4000(r4);
  li r0, 3;
  cmplwi r27, 3;
  sth r3, 0x4002(r4);
  slw r3, r0, r6;
  slw r0, r27, r6;
  lhz r4, 0x4010(r5);
  andc r3, r4, r3;
  clrlwi r3, r3, 0x10;
  or r0, r3, r0;
  sth r0, 0x4010(r5);
  beq lbl_801a772c;
  mr r3, r31;
  bl __OSUnmaskInterrupts;
lbl_801a772c:
  mr r3, r29;
  bl OSRestoreInterrupts;
lbl_801a7734:
  addi r11, r1, 0x20;
  bl _restgpr_26;
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: ConfigMEM1_24MB
// PAL: 0x801a774c..0x801a77cc
MARK_BINARY_BLOB(ConfigMEM1_24MB, 0x801a774c, 0x801a77cc);
asm UNKNOWN_FUNCTION(ConfigMEM1_24MB) {
  // clang-format off
  nofralloc;
  li r7, 0;
  lis r4, 0;
  addi r4, r4, 2;
  lis r3, 0x8000;
  addi r3, r3, 0x1ff;
  lis r6, 0x100;
  addi r6, r6, 2;
  lis r5, 0x8100;
  addi r5, r5, 0xff;
  isync;
  mtdbatu 0, r7;
  mtdbatl 0, r4;
  mtdbatu 0, r3;
  isync;
  mtibatu 0, r7;
  mtibatl 0, r4;
  mtibatu 0, r3;
  isync;
  mtdbatu 2, r7;
  mtdbatl 2, r6;
  mtdbatu 2, r5;
  isync;
  mtibatu 2, r7;
  mtibatl 2, r6;
  mtibatu 2, r5;
  isync;
  mfmsr r3;
  ori r3, r3, 0x30;
  mtspr 0x1b, r3;
  mflr r3;
  mtspr 0x1a, r3;
  rfi;
  // clang-format on
}

// Symbol: ConfigMEM1_48MB
// PAL: 0x801a77cc..0x801a784c
MARK_BINARY_BLOB(ConfigMEM1_48MB, 0x801a77cc, 0x801a784c);
asm UNKNOWN_FUNCTION(ConfigMEM1_48MB) {
  // clang-format off
  nofralloc;
  li r7, 0;
  lis r4, 0;
  addi r4, r4, 2;
  lis r3, 0x8000;
  addi r3, r3, 0x3ff;
  lis r6, 0x200;
  addi r6, r6, 2;
  lis r5, 0x8200;
  addi r5, r5, 0x1ff;
  isync;
  mtdbatu 0, r7;
  mtdbatl 0, r4;
  mtdbatu 0, r3;
  isync;
  mtibatu 0, r7;
  mtibatl 0, r4;
  mtibatu 0, r3;
  isync;
  mtdbatu 2, r7;
  mtdbatl 2, r6;
  mtdbatu 2, r5;
  isync;
  mtibatu 2, r7;
  mtibatl 2, r6;
  mtibatu 2, r5;
  isync;
  mfmsr r3;
  ori r3, r3, 0x30;
  mtspr 0x1b, r3;
  mflr r3;
  mtspr 0x1a, r3;
  rfi;
  // clang-format on
}

// Symbol: ConfigMEM2_52MB
// PAL: 0x801a784c..0x801a792c
MARK_BINARY_BLOB(ConfigMEM2_52MB, 0x801a784c, 0x801a792c);
asm UNKNOWN_FUNCTION(ConfigMEM2_52MB) {
  // clang-format off
  nofralloc;
  li r7, 0;
  lis r4, 0x1000;
  addi r4, r4, 2;
  lis r3, 0x9000;
  addi r3, r3, 0x3ff;
  lis r6, 0x1000;
  addi r6, r6, 0x2a;
  lis r5, 0xd000;
  addi r5, r5, 0x7ff;
  isync;
  mtspr 0x238, r7;
  mtspr 0x239, r4;
  mtspr 0x238, r3;
  isync;
  mtspr 0x230, r7;
  mtspr 0x231, r4;
  mtspr 0x230, r3;
  isync;
  mtspr 0x23a, r7;
  mtspr 0x23b, r6;
  mtspr 0x23a, r5;
  isync;
  mtspr 0x232, r7;
  mtspr 0x233, r7;
  isync;
  lis r4, 0x1200;
  addi r4, r4, 2;
  lis r3, 0x9200;
  addi r3, r3, 0x1ff;
  lis r6, 0x1300;
  addi r6, r6, 2;
  lis r5, 0x9300;
  addi r5, r5, 0x7f;
  isync;
  mtspr 0x23c, r7;
  mtspr 0x23d, r4;
  mtspr 0x23c, r3;
  isync;
  mtspr 0x234, r7;
  mtspr 0x235, r4;
  mtspr 0x234, r3;
  isync;
  mtspr 0x23e, r7;
  mtspr 0x23f, r6;
  mtspr 0x23e, r5;
  isync;
  mtspr 0x236, r7;
  mtspr 0x237, r6;
  mtspr 0x236, r5;
  isync;
  mfmsr r3;
  ori r3, r3, 0x30;
  mtspr 0x1b, r3;
  mflr r3;
  mtspr 0x1a, r3;
  rfi;
  // clang-format on
}

// Symbol: ConfigMEM2_56MB
// PAL: 0x801a792c..0x801a7a0c
MARK_BINARY_BLOB(ConfigMEM2_56MB, 0x801a792c, 0x801a7a0c);
asm UNKNOWN_FUNCTION(ConfigMEM2_56MB) {
  // clang-format off
  nofralloc;
  li r7, 0;
  lis r4, 0x1000;
  addi r4, r4, 2;
  lis r3, 0x9000;
  addi r3, r3, 0x3ff;
  lis r6, 0x1000;
  addi r6, r6, 0x2a;
  lis r5, 0xd000;
  addi r5, r5, 0x7ff;
  isync;
  mtspr 0x238, r7;
  mtspr 0x239, r4;
  mtspr 0x238, r3;
  isync;
  mtspr 0x230, r7;
  mtspr 0x231, r4;
  mtspr 0x230, r3;
  isync;
  mtspr 0x23a, r7;
  mtspr 0x23b, r6;
  mtspr 0x23a, r5;
  isync;
  mtspr 0x232, r7;
  mtspr 0x233, r7;
  isync;
  lis r4, 0x1200;
  addi r4, r4, 2;
  lis r3, 0x9200;
  addi r3, r3, 0x1ff;
  lis r6, 0x1300;
  addi r6, r6, 2;
  lis r5, 0x9300;
  addi r5, r5, 0xff;
  isync;
  mtspr 0x23c, r7;
  mtspr 0x23d, r4;
  mtspr 0x23c, r3;
  isync;
  mtspr 0x234, r7;
  mtspr 0x235, r4;
  mtspr 0x234, r3;
  isync;
  mtspr 0x23e, r7;
  mtspr 0x23f, r6;
  mtspr 0x23e, r5;
  isync;
  mtspr 0x236, r7;
  mtspr 0x237, r6;
  mtspr 0x236, r5;
  isync;
  mfmsr r3;
  ori r3, r3, 0x30;
  mtspr 0x1b, r3;
  mflr r3;
  mtspr 0x1a, r3;
  rfi;
  // clang-format on
}

// Symbol: ConfigMEM2_64MB
// PAL: 0x801a7a0c..0x801a7ab8
MARK_BINARY_BLOB(ConfigMEM2_64MB, 0x801a7a0c, 0x801a7ab8);
asm UNKNOWN_FUNCTION(ConfigMEM2_64MB) {
  // clang-format off
  nofralloc;
  li r7, 0;
  lis r4, 0x1000;
  addi r4, r4, 2;
  lis r3, 0x9000;
  addi r3, r3, 0x7ff;
  lis r6, 0x1000;
  addi r6, r6, 0x2a;
  lis r5, 0xd000;
  addi r5, r5, 0x7ff;
  isync;
  mtspr 0x238, r7;
  mtspr 0x239, r4;
  mtspr 0x238, r3;
  isync;
  mtspr 0x230, r7;
  mtspr 0x231, r4;
  mtspr 0x230, r3;
  isync;
  mtspr 0x23a, r7;
  mtspr 0x23b, r6;
  mtspr 0x23a, r5;
  isync;
  mtspr 0x232, r7;
  mtspr 0x233, r7;
  isync;
  mtspr 0x234, r7;
  mtspr 0x235, r7;
  isync;
  mtspr 0x236, r7;
  mtspr 0x237, r7;
  isync;
  mtspr 0x23c, r7;
  mtspr 0x23d, r7;
  isync;
  mtspr 0x23e, r7;
  mtspr 0x23f, r7;
  isync;
  mfmsr r3;
  ori r3, r3, 0x30;
  mtspr 0x1b, r3;
  mflr r3;
  mtspr 0x1a, r3;
  rfi;
  // clang-format on
}

// Symbol: ConfigMEM2_112MB
// PAL: 0x801a7ab8..0x801a7b98
MARK_BINARY_BLOB(ConfigMEM2_112MB, 0x801a7ab8, 0x801a7b98);
asm UNKNOWN_FUNCTION(ConfigMEM2_112MB) {
  // clang-format off
  nofralloc;
  li r7, 0;
  lis r4, 0x1000;
  addi r4, r4, 2;
  lis r3, 0x9000;
  addi r3, r3, 0x7ff;
  lis r6, 0x1000;
  addi r6, r6, 0x2a;
  lis r5, 0xd000;
  addi r5, r5, 0xfff;
  isync;
  mtspr 0x238, r7;
  mtspr 0x239, r4;
  mtspr 0x238, r3;
  isync;
  mtspr 0x230, r7;
  mtspr 0x231, r4;
  mtspr 0x230, r3;
  isync;
  mtspr 0x23a, r7;
  mtspr 0x23b, r6;
  mtspr 0x23a, r5;
  isync;
  mtspr 0x232, r7;
  mtspr 0x233, r7;
  isync;
  lis r4, 0x1400;
  addi r4, r4, 2;
  lis r3, 0x9400;
  addi r3, r3, 0x3ff;
  lis r6, 0x1600;
  addi r6, r6, 2;
  lis r5, 0x9600;
  addi r5, r5, 0x1ff;
  isync;
  mtspr 0x23c, r7;
  mtspr 0x23d, r4;
  mtspr 0x23c, r3;
  isync;
  mtspr 0x234, r7;
  mtspr 0x235, r4;
  mtspr 0x234, r3;
  isync;
  mtspr 0x23e, r7;
  mtspr 0x23f, r6;
  mtspr 0x23e, r5;
  isync;
  mtspr 0x236, r7;
  mtspr 0x237, r6;
  mtspr 0x236, r5;
  isync;
  mfmsr r3;
  ori r3, r3, 0x30;
  mtspr 0x1b, r3;
  mflr r3;
  mtspr 0x1a, r3;
  rfi;
  // clang-format on
}

// Symbol: ConfigMEM2_128MB
// PAL: 0x801a7b98..0x801a7c44
MARK_BINARY_BLOB(ConfigMEM2_128MB, 0x801a7b98, 0x801a7c44);
asm UNKNOWN_FUNCTION(ConfigMEM2_128MB) {
  // clang-format off
  nofralloc;
  li r7, 0;
  lis r4, 0x1000;
  addi r4, r4, 2;
  lis r3, 0x9000;
  addi r3, r3, 0xfff;
  lis r6, 0x1000;
  addi r6, r6, 0x2a;
  lis r5, 0xd000;
  addi r5, r5, 0xfff;
  isync;
  mtspr 0x238, r7;
  mtspr 0x239, r4;
  mtspr 0x238, r3;
  isync;
  mtspr 0x230, r7;
  mtspr 0x231, r4;
  mtspr 0x230, r3;
  isync;
  mtspr 0x23a, r7;
  mtspr 0x23b, r6;
  mtspr 0x23a, r5;
  isync;
  mtspr 0x232, r7;
  mtspr 0x233, r7;
  isync;
  mtspr 0x234, r7;
  mtspr 0x235, r7;
  isync;
  mtspr 0x236, r7;
  mtspr 0x237, r7;
  isync;
  mtspr 0x23c, r7;
  mtspr 0x23d, r7;
  isync;
  mtspr 0x23e, r7;
  mtspr 0x23f, r7;
  isync;
  mfmsr r3;
  ori r3, r3, 0x30;
  mtspr 0x1b, r3;
  mflr r3;
  mtspr 0x1a, r3;
  rfi;
  // clang-format on
}

// Symbol: ConfigMEM_ES1_0
// PAL: 0x801a7c44..0x801a7c94
MARK_BINARY_BLOB(ConfigMEM_ES1_0, 0x801a7c44, 0x801a7c94);
asm UNKNOWN_FUNCTION(ConfigMEM_ES1_0) {
  // clang-format off
  nofralloc;
  li r7, 0;
  lis r4, 0;
  addi r4, r4, 2;
  lis r3, 0x8000;
  addi r3, r3, 0xfff;
  isync;
  mtdbatu 0, r7;
  mtdbatl 0, r4;
  mtdbatu 0, r3;
  isync;
  mtibatu 0, r7;
  mtibatl 0, r4;
  mtibatu 0, r3;
  isync;
  mfmsr r3;
  ori r3, r3, 0x30;
  mtspr 0x1b, r3;
  mflr r3;
  mtspr 0x1a, r3;
  rfi;
  // clang-format on
}

// Symbol: RealMode
// PAL: 0x801a7c94..0x801a7cac
MARK_BINARY_BLOB(RealMode, 0x801a7c94, 0x801a7cac);
asm UNKNOWN_FUNCTION(RealMode) {
  // clang-format off
  nofralloc;
  clrlwi r3, r3, 2;
  mtspr 0x1a, r3;
  mfmsr r3;
  rlwinm r3, r3, 0, 0x1c, 0x19;
  mtspr 0x1b, r3;
  rfi;
  // clang-format on
}

// Symbol: BATConfig
// PAL: 0x801a7cac..0x801a7dfc
MARK_BINARY_BLOB(BATConfig, 0x801a7cac, 0x801a7dfc);
asm UNKNOWN_FUNCTION(BATConfig) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r3, 0x8000;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  lwz r0, 0x3138(r3);
  cmpwi r0, 0;
  bne lbl_801a7ce8;
  lis r0, 0x801a;
  addic. r0, r0, 0x75d0;
  bne lbl_801a7ce8;
  lis r3, 0x801a;
  addi r3, r3, 0x7c44;
  bl RealMode;
  b lbl_801a7de8;
lbl_801a7ce8:
  lis r3, 0x8000;
  lwz r31, 0x3104(r3);
  lwz r0, 0x3100(r3);
  cmplw r31, r0;
  bge lbl_801a7d20;
  addis r0, r31, 0xfe80;
  cmplwi r0, 0;
  bne lbl_801a7d20;
  lis r3, 0x8180;
  lis r4, 0x180;
  bl DCInvalidateRange;
  li r0, 2;
  lis r3, 0xcc00;
  sth r0, 0x4028(r3);
lbl_801a7d20:
  lis r0, 0x180;
  cmplw r31, r0;
  bgt lbl_801a7d3c;
  lis r3, 0x801a;
  addi r3, r3, 0x774c;
  bl RealMode;
  b lbl_801a7d54;
lbl_801a7d3c:
  lis r0, 0x300;
  cmplw r31, r0;
  bgt lbl_801a7d54;
  lis r3, 0x801a;
  addi r3, r3, 0x77cc;
  bl RealMode;
lbl_801a7d54:
  lis r3, 0x8000;
  lis r0, 0x400;
  lwz r4, 0x311c(r3);
  lwz r3, 0x3120(r3);
  cmplw r4, r0;
  bgt lbl_801a7db4;
  lis r0, 0x9340;
  cmplw r3, r0;
  bgt lbl_801a7d88;
  lis r3, 0x801a;
  addi r3, r3, 0x784c;
  bl RealMode;
  b lbl_801a7de8;
lbl_801a7d88:
  lis r0, 0x9380;
  cmplw r3, r0;
  bgt lbl_801a7da4;
  lis r3, 0x801a;
  addi r3, r3, 0x792c;
  bl RealMode;
  b lbl_801a7de8;
lbl_801a7da4:
  lis r3, 0x801a;
  addi r3, r3, 0x7a0c;
  bl RealMode;
  b lbl_801a7de8;
lbl_801a7db4:
  lis r0, 0x800;
  cmplw r4, r0;
  bgt lbl_801a7de8;
  lis r0, 0x9700;
  cmplw r3, r0;
  bgt lbl_801a7ddc;
  lis r3, 0x801a;
  addi r3, r3, 0x7ab8;
  bl RealMode;
  b lbl_801a7de8;
lbl_801a7ddc:
  lis r3, 0x801a;
  addi r3, r3, 0x7b98;
  bl RealMode;
lbl_801a7de8:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: __OSInitMemoryProtection
// PAL: 0x801a7dfc..0x801a7eac
MARK_BINARY_BLOB(__OSInitMemoryProtection, 0x801a7dfc, 0x801a7eac);
asm UNKNOWN_FUNCTION(__OSInitMemoryProtection) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  stw r30, 8(r1);
  bl OSDisableInterrupts;
  lis r4, 0xcc00;
  li r0, 0;
  sth r0, 0x4020(r4);
  li r0, 0xff;
  mr r30, r3;
  lis r3, 0xf000;
  sth r0, 0x4010(r4);
  bl __OSMaskInterrupts;
  lis r31, 0x801a;
  li r3, 0;
  addi r4, r31, 0x763c;
  bl __OSSetInterruptHandler;
  addi r4, r31, 0x763c;
  li r3, 1;
  bl __OSSetInterruptHandler;
  addi r4, r31, 0x763c;
  li r3, 2;
  bl __OSSetInterruptHandler;
  addi r4, r31, 0x763c;
  li r3, 3;
  bl __OSSetInterruptHandler;
  addi r4, r31, 0x763c;
  li r3, 4;
  bl __OSSetInterruptHandler;
  lis r3, 0x8029;
  addi r3, r3, 0x658;
  bl OSRegisterShutdownFunction;
  bl BATConfig;
  lis r3, 0x800;
  bl __OSUnmaskInterrupts;
  mr r3, r30;
  bl OSRestoreInterrupts;
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

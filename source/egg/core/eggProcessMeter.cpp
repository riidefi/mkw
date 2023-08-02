#include "eggProcessMeter.hpp"

// Extern function references.
// PAL: 0x800aef60
extern "C" void List_Init__Q24nw4r2utFPQ34nw4r2ut4ListUs();
// PAL: 0x800aef80
extern "C" void List_Append__Q24nw4r2utFPQ34nw4r2ut4ListPv();
// PAL: 0x800af180
extern "C" void List_GetNext__Q24nw4r2utFPCQ34nw4r2ut4ListPCv();
// PAL: 0x8016cfa0
extern "C" void GXGetGPFifo();
// PAL: 0x8016d030
extern "C" void GXGetFifoPtrs();
// PAL: 0x8016d098
extern "C" void GXEnableBreakPt();
// PAL: 0x8016d138
extern "C" void GXDisableBreakPt();
// PAL: 0x8016d39c
extern "C" void GXGetCurrentGXThread();
// PAL: 0x8016dc34
extern "C" void GXClearVtxDesc();
// PAL: 0x8016dc68
extern "C" void GXSetVtxAttrFmt();
// PAL: 0x8016e5a4
extern "C" void GXSetNumTexGens();
// PAL: 0x8016e9fc
extern "C" void GXSetDrawSync();
// PAL: 0x8016ec88
extern "C" void GXSetDrawSyncCallback();
// PAL: 0x8016f0f0
extern "C" void GXBegin();
// PAL: 0x8016f314
extern "C" void GXSetLineWidth();
// PAL: 0x8016f3b8
extern "C" void GXSetCullMode();
// PAL: 0x80170474
extern "C" void GXSetChanMatColor();
// PAL: 0x8017054c
extern "C" void GXSetNumChans();
// PAL: 0x80170570
extern "C" void GXSetChanCtrl();
// PAL: 0x80171b38
extern "C" void GXSetNumIndStages();
// PAL: 0x80171c4c
extern "C" void GXSetTevOp();
// PAL: 0x8017214c
extern "C" void GXSetTevOrder();
// PAL: 0x801722a8
extern "C" void GXSetNumTevStages();
// PAL: 0x8017277c
extern "C" void GXSetBlendMode();
// PAL: 0x801727cc
extern "C" void GXSetColorUpdate();
// PAL: 0x80172824
extern "C" void GXSetZMode();
// PAL: 0x8017301c
extern "C" void GXSetProjection();
// PAL: 0x8017310c
extern "C" void GXLoadPosMtxImm();
// PAL: 0x80173214
extern "C" void GXSetCurrentMtx();
// PAL: 0x801733b4
extern "C" void GXSetViewport();
// PAL: 0x80173430
extern "C" void GXSetScissor();
// PAL: 0x80199d64
extern "C" void PSMTXConcat();
// PAL: 0x8019a3e0
extern "C" void PSMTXTrans();
// PAL: 0x8019a460
extern "C" void PSMTXScale();
// PAL: 0x8019ab4c
extern "C" void C_MTXOrtho();
// PAL: 0x801a65ac
extern "C" void OSDisableInterrupts();
// PAL: 0x801a65d4
extern "C" void OSRestoreInterrupts();
// PAL: 0x801a735c
extern "C" void OSSendMessage();
// PAL: 0x801a7424
extern "C" void OSReceiveMessage();
// PAL: 0x801aa58c
extern "C" void OSResumeThread();
// PAL: 0x801aab98
extern "C" void OSSetThreadPriority();
// PAL: 0x801aad74
extern "C" void OSGetTick();
// PAL: 0x80238f54
extern "C" void ProcessMeter_append2();
// PAL: 0x80239338
extern "C" void ProcessMeter_draw2();
// PAL: 0x802432e0
extern "C" void __ct__Q23EGG6ThreadFUliiPQ23EGG4Heap();
// PAL: 0x8024341c
extern "C" void __dt__Q23EGG6ThreadFv();

// Symbol: CpuMonitor_measureBegin
// PAL: 0x802386dc..0x80238714
MARK_BINARY_BLOB(CpuMonitor_measureBegin, 0x802386dc, 0x80238714);
asm UNKNOWN_FUNCTION(CpuMonitor_measureBegin) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  bl OSGetTick;
  li r0, 0;
  stw r3, 0xc(r31);
  stw r0, 0x10(r31);
  lwz r31, 0xc(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: CpuMonitor_measureEnd
// PAL: 0x80238714..0x80238750
MARK_BINARY_BLOB(CpuMonitor_measureEnd, 0x80238714, 0x80238750);
asm UNKNOWN_FUNCTION(CpuMonitor_measureEnd) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  lwz r0, 0xc(r3);
  cmpwi r0, 0;
  beq lbl_8023873c;
  bl OSGetTick;
  stw r3, 0x10(r31);
lbl_8023873c:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: CpuMonitor_show
// PAL: 0x80238750..0x80238760
MARK_BINARY_BLOB(CpuMonitor_show, 0x80238750, 0x80238760);
asm UNKNOWN_FUNCTION(CpuMonitor_show) {
  // clang-format off
  nofralloc;
  lbz r0, 0x20(r3);
  rlwinm r0, r0, 0, 0x18, 0x1e;
  stb r0, 0x20(r3);
  blr;
  // clang-format on
}

// Symbol: CpuMonitor_hide
// PAL: 0x80238760..0x80238770
MARK_BINARY_BLOB(CpuMonitor_hide, 0x80238760, 0x80238770);
asm UNKNOWN_FUNCTION(CpuMonitor_hide) {
  // clang-format off
  nofralloc;
  lbz r0, 0x20(r3);
  ori r0, r0, 1;
  stb r0, 0x20(r3);
  blr;
  // clang-format on
}

// Symbol: CpuGpMonitor_measureBegin
// PAL: 0x80238770..0x802387bc
MARK_BINARY_BLOB(CpuGpMonitor_measureBegin, 0x80238770, 0x802387bc);
asm UNKNOWN_FUNCTION(CpuGpMonitor_measureBegin) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  bl OSGetTick;
  stw r3, 0xc(r31);
  li r4, 0;
  li r0, 1;
  lwz r3, 0x58(r31);
  stw r4, 0x10(r31);
  addi r4, r31, 0x5c;
  sth r0, 0x54(r31);
  bl ProcessMeter_setDrawSync;
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: CpuGpMonitor_measureEnd
// PAL: 0x802387bc..0x80238804
MARK_BINARY_BLOB(CpuGpMonitor_measureEnd, 0x802387bc, 0x80238804);
asm UNKNOWN_FUNCTION(CpuGpMonitor_measureEnd) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  lwz r0, 0xc(r3);
  cmpwi r0, 0;
  beq lbl_802387e4;
  bl OSGetTick;
  stw r3, 0x10(r31);
lbl_802387e4:
  lwz r3, 0x58(r31);
  addi r4, r31, 0x6c;
  bl ProcessMeter_setDrawSync;
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: CpuGpMonitor_show
// PAL: 0x80238804..0x80238820
MARK_BINARY_BLOB(CpuGpMonitor_show, 0x80238804, 0x80238820);
asm UNKNOWN_FUNCTION(CpuGpMonitor_show) {
  // clang-format off
  nofralloc;
  lbz r4, 0x20(r3);
  lbz r0, 0x48(r3);
  rlwinm r4, r4, 0, 0x18, 0x1e;
  stb r4, 0x20(r3);
  rlwinm r0, r0, 0, 0x18, 0x1e;
  stb r0, 0x48(r3);
  blr;
  // clang-format on
}

// Symbol: CpuGpMonitor_hide
// PAL: 0x80238820..0x8023883c
MARK_BINARY_BLOB(CpuGpMonitor_hide, 0x80238820, 0x8023883c);
asm UNKNOWN_FUNCTION(CpuGpMonitor_hide) {
  // clang-format off
  nofralloc;
  lbz r4, 0x20(r3);
  lbz r0, 0x48(r3);
  ori r4, r4, 1;
  stb r4, 0x20(r3);
  ori r0, r0, 1;
  stb r0, 0x48(r3);
  blr;
  // clang-format on
}

// Symbol: ProcessMeter_construct
// PAL: 0x8023883c..0x80238a94
MARK_BINARY_BLOB(ProcessMeter_construct, 0x8023883c, 0x80238a94);
asm UNKNOWN_FUNCTION(ProcessMeter_construct) {
  // clang-format off
  nofralloc;
  stwu r1, -0x50(r1);
  mflr r0;
  stw r0, 0x54(r1);
  addi r11, r1, 0x50;
  bl _savegpr_18;
  mr r31, r4;
  mr r30, r3;
  li r4, 0x1000;
  li r5, 4;
  li r6, 0;
  li r7, 0;
  bl __ct__Q23EGG6ThreadFUliiPQ23EGG4Heap;
  lis r5, 0x802a;
  lfs f2, -0x5ffc(r2);
  addi r5, r5, 0x3ce0;
  lfs f1, -0x5ff8(r2);
  lfs f0, -0x6000(r2);
  lis r3, 0xcccd;
  addi r0, r3, -13057;
  addi r4, r5, 0x18;
  stw r4, 0x48(r30);
  addi r3, r30, 0x60;
  li r4, 0x20;
  stw r5, 0(r30);
  stw r0, 0x4c(r30);
  stfs f2, 0x50(r30);
  stfs f2, 0x54(r30);
  stfs f1, 0x58(r30);
  stfs f0, 0x5c(r30);
  bl List_Init__Q24nw4r2utFPQ34nw4r2ut4ListUs;
  lis r4, 0xff50;
  lis r6, 0x50ff;
  addi r0, r4, 0x50ff;
  stw r0, 0x10(r1);
  lis r3, 0x5051;
  addi r6, r6, 0x50ff;
  lfs f2, -0x6018(r2);
  addi r3, r3, -1;
  li r0, 0;
  stw r6, 8(r1);
  lfs f1, -0x6000(r2);
  addi r5, r30, 0xc8;
  stw r3, 0xc(r1);
  li r6, 0x32c8;
  lis r22, 0x802a;
  lbz r23, 0x10(r1);
  stw r6, 0x14(r1);
  addi r22, r22, 0x3d60;
  lis r11, 0x802a;
  lbz r24, 0x11(r1);
  lbz r18, 0x14(r1);
  li r6, 0x14;
  lbz r19, 0x15(r1);
  addi r11, r11, 0x3d48;
  stw r22, 0xc8(r30);
  addi r4, r30, 0x9c;
  lbz r20, 0x16(r1);
  mr r3, r30;
  lbz r21, 0x17(r1);
  lbz r25, 0x12(r1);
  lbz r26, 0x13(r1);
  lbz r27, 8(r1);
  lbz r28, 9(r1);
  lbz r29, 0xa(r1);
  lbz r12, 0xb(r1);
  lbz r10, 0xc(r1);
  lbz r9, 0xd(r1);
  lbz r8, 0xe(r1);
  lbz r7, 0xf(r1);
  lfs f0, -0x5ff4(r2);
  stfs f2, 0x74(r30);
  stfs f2, 0x78(r30);
  stw r0, 0x7c(r30);
  stw r0, 0x80(r30);
  stb r18, 0x84(r30);
  stb r19, 0x85(r30);
  stb r20, 0x86(r30);
  stb r21, 0x87(r30);
  stfs f2, 0x88(r30);
  stfs f1, 0x8c(r30);
  stb r0, 0x90(r30);
  stw r22, 0x9c(r30);
  stfs f2, 0xa0(r30);
  stfs f2, 0xa4(r30);
  stw r0, 0xa8(r30);
  stw r0, 0xac(r30);
  stb r23, 0xb0(r30);
  stb r24, 0xb1(r30);
  stb r25, 0xb2(r30);
  stb r26, 0xb3(r30);
  stfs f2, 0xb4(r30);
  stfs f1, 0xb8(r30);
  stb r0, 0xbc(r30);
  stfs f2, 0xcc(r30);
  stfs f2, 0xd0(r30);
  stw r0, 0xd4(r30);
  stw r0, 0xd8(r30);
  stb r27, 0xdc(r30);
  stb r28, 0xdd(r30);
  stb r29, 0xde(r30);
  stb r12, 0xdf(r30);
  stfs f1, 0xe0(r30);
  stfs f1, 0xe4(r30);
  stb r0, 0xe8(r30);
  stw r11, 0xc8(r30);
  stfs f2, 0xf4(r30);
  stfs f2, 0xf8(r30);
  stw r0, 0xfc(r30);
  stw r0, 0x100(r30);
  stb r10, 0x104(r30);
  stb r9, 0x105(r30);
  stb r8, 0x106(r30);
  stb r7, 0x107(r30);
  stfs f0, 0x108(r30);
  stfs f1, 0x10c(r30);
  stb r0, 0x110(r30);
  sth r0, 0x11c(r30);
  stw r5, 0x130(r30);
  stw r5, 0x140(r30);
  stw r6, 0x144(r30);
  stb r0, 0x152(r30);
  stw r0, 0x6c(r30);
  stw r0, 0x70(r30);
  bl ProcessMeter_append;
  mr r3, r30;
  addi r4, r30, 0xc8;
  bl ProcessMeter_append2;
  lbz r0, 0x152(r30);
  cmpwi r31, 0;
  ori r0, r0, 1;
  stb r0, 0x152(r30);
  beq lbl_80238a58;
  lis r3, 0x8023;
  addi r3, r3, 0x4a04;
  bl GXSetDrawSyncCallback;
lbl_80238a58:
  bl GXGetCurrentGXThread;
  mr r4, r3;
  lwz r3, 8(r30);
  lwz r4, 0x2d0(r4);
  addi r4, r4, -1;
  bl OSSetThreadPriority;
  lwz r3, 8(r30);
  bl OSResumeThread;
  addi r11, r1, 0x50;
  mr r3, r30;
  bl _restgpr_18;
  lwz r0, 0x54(r1);
  mtlr r0;
  addi r1, r1, 0x50;
  blr;
  // clang-format on
}

// Symbol: ProcessMeter_measureBeginFrame
// PAL: 0x80238a94..0x80238d10
MARK_BINARY_BLOB(ProcessMeter_measureBeginFrame, 0x80238a94, 0x80238d10);
asm UNKNOWN_FUNCTION(ProcessMeter_measureBeginFrame) {
  // clang-format off
  nofralloc;
  stwu r1, -0x80(r1);
  mflr r0;
  stw r0, 0x84(r1);
  stfd f31, 0x70(r1);
  psq_st f31, 120(r1), 0, 0;
  stfd f30, 0x60(r1);
  psq_st f30, 104(r1), 0, 0;
  stfd f29, 0x50(r1);
  psq_st f29, 88(r1), 0, 0;
  stfd f28, 0x40(r1);
  psq_st f28, 72(r1), 0, 0;
  stfd f27, 0x30(r1);
  psq_st f27, 56(r1), 0, 0;
  lis r4, 0x4330;
  stw r31, 0x2c(r1);
  stw r30, 0x28(r1);
  mr r30, r3;
  stw r29, 0x24(r1);
  stw r28, 0x20(r1);
  lwz r0, 0x7c(r3);
  stw r4, 8(r1);
  cmpwi r0, 0;
  stw r4, 0x10(r1);
  beq lbl_80238afc;
  bl OSGetTick;
  stw r3, 0x80(r30);
lbl_80238afc:
  lfs f0, -0x6018(r2);
  stfs f0, 0x74(r30);
  fcmpo cr0, f0, f0;
  lwz r31, 0x7c(r30);
  bge lbl_80238b14;
  stfs f0, 0x74(r30);
lbl_80238b14:
  lwz r0, 0x7c(r30);
  cmpwi r0, 0;
  beq lbl_80238b34;
  lwz r3, 0x80(r30);
  cmpwi r3, 0;
  beq lbl_80238b34;
  subf r5, r0, r3;
  b lbl_80238b38;
lbl_80238b34:
  li r5, 0;
lbl_80238b38:
  lis r4, 0x8000;
  lis r3, 0x1062;
  lwz r0, 0xf8(r4);
  addi r3, r3, 0x4dd3;
  stw r5, 0xc(r1);
  srwi r0, r0, 2;
  lfd f3, -0x6008(r2);
  mulhwu r0, r3, r0;
  lfd f1, 8(r1);
  lfs f0, -0x6018(r2);
  fsubs f2, f1, f3;
  srwi r0, r0, 6;
  stw r0, 0x14(r1);
  lfd f1, 0x10(r1);
  fsubs f1, f1, f3;
  fdivs f1, f2, f1;
  stfs f1, 0x78(r30);
  fcmpo cr0, f1, f0;
  mfcr r0;
  rlwinm. r0, r0, 2, 0x1f, 0x1f;
  cmpwi r0, 0;
  lfs f31, -0x6018(r2);
  lis r3, 0x1062;
  lfd f27, -0x6010(r2);
  addi r28, r3, 0x4dd3;
  fmr f29, f31;
  lfd f28, -0x6008(r2);
  fmr f30, f31;
  li r4, 0;
  lis r29, 0x8000;
  b lbl_80238c84;
lbl_80238bb4:
  lwz r0, 0xf8(r29);
  lwz r5, 8(r3);
  srwi r0, r0, 2;
  mulhwu r0, r28, r0;
  subf r5, r31, r5;
  xoris r5, r5, 0x8000;
  stw r5, 0xc(r1);
  lfd f0, 8(r1);
  srwi r0, r0, 6;
  stw r0, 0x14(r1);
  fsubs f1, f0, f27;
  lfd f0, 0x10(r1);
  fsubs f0, f0, f28;
  fdivs f0, f1, f0;
  stfs f0, 0(r3);
  fcmpo cr0, f0, f29;
  bge lbl_80238bfc;
  stfs f29, 0(r3);
lbl_80238bfc:
  lwz r0, 8(r3);
  cmpwi r0, 0;
  beq lbl_80238c1c;
  lwz r5, 0xc(r3);
  cmpwi r5, 0;
  beq lbl_80238c1c;
  subf r5, r0, r5;
  b lbl_80238c20;
lbl_80238c1c:
  li r5, 0;
lbl_80238c20:
  lwz r0, 0xf8(r29);
  stw r5, 0xc(r1);
  srwi r0, r0, 2;
  mulhwu r0, r28, r0;
  lfd f0, 8(r1);
  fsubs f1, f0, f28;
  srwi r0, r0, 6;
  stw r0, 0x14(r1);
  lfd f0, 0x10(r1);
  fsubs f0, f0, f28;
  fdivs f0, f1, f0;
  stfs f0, 4(r3);
  fcmpo cr0, f0, f30;
  ble lbl_80238c68;
  lfs f1, 0x14(r3);
  lfs f0, 0x18(r3);
  fadds f0, f1, f0;
  b lbl_80238c6c;
lbl_80238c68:
  fmr f0, f30;
lbl_80238c6c:
  lbz r0, 0x1c(r3);
  clrlwi. r0, r0, 0x1f;
  bne lbl_80238c84;
  fcmpo cr0, f0, f31;
  ble lbl_80238c84;
  fmr f31, f0;
lbl_80238c84:
  addi r3, r30, 0x60;
  bl List_GetNext__Q24nw4r2utFPCQ34nw4r2ut4ListPCv;
  cmpwi r3, 0;
  mr r4, r3;
  bne lbl_80238bb4;
  lfs f0, -0x6000(r2);
  fadds f0, f0, f31;
  stfs f0, 0x148(r30);
  bl OSGetTick;
  stw r3, 0x7c(r30);
  li r0, 0;
  addi r3, r30, 0x9c;
  stw r0, 0x80(r30);
  lwz r12, 0x9c(r30);
  lwz r12, 0x10(r12);
  mtctr r12;
  bctrl;
  psq_l f31, 120(r1), 0, 0;
  lfd f31, 0x70(r1);
  psq_l f30, 104(r1), 0, 0;
  lfd f30, 0x60(r1);
  psq_l f29, 88(r1), 0, 0;
  lfd f29, 0x50(r1);
  psq_l f28, 72(r1), 0, 0;
  lfd f28, 0x40(r1);
  psq_l f27, 56(r1), 0, 0;
  lfd f27, 0x30(r1);
  lwz r31, 0x2c(r1);
  lwz r30, 0x28(r1);
  lwz r29, 0x24(r1);
  lwz r0, 0x84(r1);
  lwz r28, 0x20(r1);
  mtlr r0;
  addi r1, r1, 0x80;
  blr;
  // clang-format on
}

// Symbol: ProcessMeter_measureEndFrame
// PAL: 0x80238d10..0x80238d20
MARK_BINARY_BLOB(ProcessMeter_measureEndFrame, 0x80238d10, 0x80238d20);
asm UNKNOWN_FUNCTION(ProcessMeter_measureEndFrame) {
  // clang-format off
  nofralloc;
  lwzu r12, 0x9c(r3);
  lwz r12, 0x14(r12);
  mtctr r12;
  bctr;
  // clang-format on
}

// Symbol: ProcessMeter_measureBeginRender
// PAL: 0x80238d20..0x80238d30
MARK_BINARY_BLOB(ProcessMeter_measureBeginRender, 0x80238d20, 0x80238d30);
asm UNKNOWN_FUNCTION(ProcessMeter_measureBeginRender) {
  // clang-format off
  nofralloc;
  lwzu r12, 0xc8(r3);
  lwz r12, 0x10(r12);
  mtctr r12;
  bctr;
  // clang-format on
}

// Symbol: ProcessMeter_measureEndRender
// PAL: 0x80238d30..0x80238d40
MARK_BINARY_BLOB(ProcessMeter_measureEndRender, 0x80238d30, 0x80238d40);
asm UNKNOWN_FUNCTION(ProcessMeter_measureEndRender) {
  // clang-format off
  nofralloc;
  lwzu r12, 0xc8(r3);
  lwz r12, 0x14(r12);
  mtctr r12;
  bctr;
  // clang-format on
}

// Symbol: ProcessMeter_callbackDrawSync
// PAL: 0x80238d40..0x80238d8c
MARK_BINARY_BLOB(ProcessMeter_callbackDrawSync, 0x80238d40, 0x80238d8c);
asm UNKNOWN_FUNCTION(ProcessMeter_callbackDrawSync) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  lwz r5, 0x6c(r3);
  lhz r0, 4(r5);
  cmplw r0, r4;
  bne lbl_80238d78;
  bl OSGetTick;
  mr r4, r3;
  addi r3, r31, 0xc;
  li r5, 0;
  bl OSSendMessage;
lbl_80238d78:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: ProcessMeter_run
// PAL: 0x80238d8c..0x80238e38
MARK_BINARY_BLOB(ProcessMeter_run, 0x80238d8c, 0x80238e38);
asm UNKNOWN_FUNCTION(ProcessMeter_run) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  stmw r27, 0x1c(r1);
  mr r27, r3;
  li r30, 2;
  li r31, 0;
lbl_80238da8:
  addi r3, r27, 0xc;
  addi r4, r1, 8;
  li r5, 1;
  bl OSReceiveMessage;
  lwz r29, 8(r1);
  bl OSDisableInterrupts;
  lwz r4, 0x6c(r27);
  mr r28, r3;
  lwz r3, 8(r4);
  cmpwi r3, 0;
  beq lbl_80238df0;
  lwz r3, 8(r3);
  cmpwi r3, 0;
  beq lbl_80238dec;
  lwz r3, 0(r3);
  bl GXEnableBreakPt;
  b lbl_80238df0;
lbl_80238dec:
  bl GXDisableBreakPt;
lbl_80238df0:
  lwz r4, 0x6c(r27);
  mr r3, r28;
  lwz r28, 0xc(r4);
  lwz r0, 8(r4);
  stw r0, 0x6c(r27);
  bl OSRestoreInterrupts;
  lhz r0, 0x54(r28);
  cmpwi r0, 1;
  beq lbl_80238e20;
  cmpwi r0, 2;
  beq lbl_80238e2c;
  b lbl_80238da8;
lbl_80238e20:
  stw r29, 0x34(r28);
  sth r30, 0x54(r28);
  b lbl_80238da8;
lbl_80238e2c:
  stw r29, 0x38(r28);
  sth r31, 0x54(r28);
  b lbl_80238da8;
  // clang-format on
}

// Symbol: ProcessMeter_setDrawSync
// PAL: 0x80238e38..0x80238f14
MARK_BINARY_BLOB(ProcessMeter_setDrawSync, 0x80238e38, 0x80238f14);
asm UNKNOWN_FUNCTION(ProcessMeter_setDrawSync) {
  // clang-format off
  nofralloc;
  stwu r1, -0xa0(r1);
  mflr r0;
  stw r0, 0xa4(r1);
  stw r31, 0x9c(r1);
  stw r30, 0x98(r1);
  mr r30, r4;
  stw r29, 0x94(r1);
  mr r29, r3;
  bl OSDisableInterrupts;
  lhz r4, 0x150(r29);
  mr r31, r3;
  addi r0, r4, 1;
  sth r0, 0x150(r29);
  clrlwi r0, r0, 0x10;
  cmplwi r0, 0xdfff;
  ble lbl_80238e84;
  lis r3, 1;
  addi r0, r3, -12288;
  sth r0, 0x150(r29);
lbl_80238e84:
  lhz r3, 0x150(r29);
  li r0, 0;
  sth r3, 4(r30);
  stw r0, 8(r30);
  lwz r0, 0x6c(r29);
  cmpwi r0, 0;
  beq lbl_80238ee0;
  addi r3, r1, 0x10;
  bl GXGetGPFifo;
  mr r5, r30;
  addi r3, r1, 0x10;
  addi r4, r1, 8;
  bl GXGetFifoPtrs;
  lwz r3, 0x6c(r29);
  lwz r0, 8(r3);
  cmpwi r0, 0;
  bne lbl_80238ed0;
  lwz r3, 0(r30);
  bl GXEnableBreakPt;
lbl_80238ed0:
  lwz r3, 0x70(r29);
  stw r30, 8(r3);
  stw r30, 0x70(r29);
  b lbl_80238ee8;
lbl_80238ee0:
  stw r30, 0x6c(r29);
  stw r30, 0x70(r29);
lbl_80238ee8:
  lhz r3, 0x150(r29);
  bl GXSetDrawSync;
  mr r3, r31;
  bl OSRestoreInterrupts;
  lwz r0, 0xa4(r1);
  lwz r31, 0x9c(r1);
  lwz r30, 0x98(r1);
  lwz r29, 0x94(r1);
  mtlr r0;
  addi r1, r1, 0xa0;
  blr;
  // clang-format on
}

// Symbol: ProcessMeter_setVisible
// PAL: 0x80238f14..0x80238f3c
MARK_BINARY_BLOB(ProcessMeter_setVisible, 0x80238f14, 0x80238f3c);
asm UNKNOWN_FUNCTION(ProcessMeter_setVisible) {
  // clang-format off
  nofralloc;
  cmpwi r4, 0;
  beq lbl_80238f2c;
  lbz r0, 0x152(r3);
  ori r0, r0, 1;
  stb r0, 0x152(r3);
  blr;
lbl_80238f2c:
  lbz r0, 0x152(r3);
  rlwinm r0, r0, 0, 0x18, 0x1e;
  stb r0, 0x152(r3);
  blr;
  // clang-format on
}

// Symbol: ProcessMeter_isVisible
// PAL: 0x80238f3c..0x80238f48
MARK_BINARY_BLOB(ProcessMeter_isVisible, 0x80238f3c, 0x80238f48);
asm UNKNOWN_FUNCTION(ProcessMeter_isVisible) {
  // clang-format off
  nofralloc;
  lbz r0, 0x152(r3);
  clrlwi r3, r0, 0x1f;
  blr;
  // clang-format on
}

// Symbol: ProcessMeter_append
MARK_BINARY_BLOB(ProcessMeter_append, 0x80238f48, 0x80238f54);
asm UNKNOWN_FUNCTION(ProcessMeter_append) {
  // clang-format off
  nofralloc;
  addi r3, r3, 0x60;
  addi r4, r4, 4;
  b List_Append__Q24nw4r2utFPQ34nw4r2ut4ListPv;
  // clang-format on
}


MARK_BINARY_BLOB(ProcessMeter_append2, 0x80238f54, 0x80238fa4);
asm UNKNOWN_FUNCTION(ProcessMeter_append2) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  addi r4, r4, 4;
  stw r30, 8(r1);
  mr r30, r3;
  addi r3, r3, 0x60;
  bl List_Append__Q24nw4r2utFPQ34nw4r2ut4ListPv;
  addi r3, r30, 0x60;
  addi r4, r31, 0x2c;
  bl List_Append__Q24nw4r2utFPQ34nw4r2ut4ListPv;
  stw r30, 0x58(r31);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: ProcessMeter_draw
MARK_BINARY_BLOB(ProcessMeter_draw, 0x80238fa4, 0x80239338);
asm UNKNOWN_FUNCTION(ProcessMeter_draw) {
  // clang-format off
  nofralloc;
  stwu r1, -0xa0(r1);
  mflr r0;
  stw r0, 0xa4(r1);
  stfd f31, 0x90(r1);
  psq_st f31, 152(r1), 0, 0;
  stfd f30, 0x80(r1);
  psq_st f30, 136(r1), 0, 0;
  stfd f29, 0x70(r1);
  psq_st f29, 120(r1), 0, 0;
  stfd f28, 0x60(r1);
  psq_st f28, 104(r1), 0, 0;
  stfd f27, 0x50(r1);
  psq_st f27, 88(r1), 0, 0;
  addi r11, r1, 0x50;
  bl _savegpr_27;
  lbz r0, 0x152(r3);
  mr r28, r3;
  clrlwi. r0, r0, 0x1f;
  beq lbl_802392f8;
  lis r6, 0x8000;
  lis r5, 0x4330;
  lwz r7, 0xf8(r6);
  lis r6, 0x431c;
  addi r8, r6, -8573;
  lbz r0, 0x153(r3);
  srwi r6, r7, 2;
  slwi r7, r4, 3;
  mulhwu r4, r8, r6;
  stw r0, 0x34(r1);
  lfd f5, -0x6008(r2);
  stw r5, 0x30(r1);
  lfs f3, -0x5ff0(r2);
  lfd f0, 0x30(r1);
  srwi r0, r4, 0xf;
  stw r5, 0x28(r1);
  divwu r0, r7, r0;
  fsubs f0, f0, f5;
  stw r0, 0x2c(r1);
  lfd f4, 0x28(r1);
  fsubs f4, f4, f5;
  fdivs f27, f4, f3;
  fmuls f3, f27, f0;
  bl ProcessMeter_drawSetting;
  lbz r7, 0x84(r28);
  addi r4, r1, 0x10;
  lbz r6, 0x85(r28);
  li r3, 4;
  lbz r5, 0x86(r28);
  lbz r0, 0x87(r28);
  lfs f31, 0x148(r28);
  stb r7, 0x1c(r1);
  stb r6, 0x1d(r1);
  stb r5, 0x1e(r1);
  stb r0, 0x1f(r1);
  stb r7, 0x10(r1);
  stb r6, 0x11(r1);
  stb r5, 0x12(r1);
  stb r0, 0x13(r1);
  bl GXSetChanMatColor;
  lfs f29, 0x78(r28);
  lfs f0, -0x6018(r2);
  lfs f30, 0x74(r28);
  fcmpo cr0, f29, f0;
  ble lbl_802390f4;
  fcmpo cr0, f31, f0;
  ble lbl_802390f4;
  li r3, 0x80;
  li r4, 0;
  li r5, 4;
  bl GXBegin;
  lis r3, 0xcc01;
  lfs f0, -0x5fec(r2);
  stfs f30, -0x8000(r3);
  fadds f2, f30, f29;
  lfs f1, -0x5fec(r2);
  fadds f0, f0, f31;
  stfs f1, -0x8000(r3);
  stfs f2, -0x8000(r3);
  lfs f1, -0x5fec(r2);
  stfs f1, -0x8000(r3);
  stfs f2, -0x8000(r3);
  stfs f0, -0x8000(r3);
  stfs f30, -0x8000(r3);
  stfs f0, -0x8000(r3);
lbl_802390f4:
  lfs f28, -0x6018(r2);
  addi r31, r1, 0x18;
  lfs f29, 0x78(r28);
  addi r30, r1, 0x14;
  li r29, 0;
  lis r27, 0xcc01;
  b lbl_802391f8;
lbl_80239110:
  li r3, 0x14;
  li r4, 0;
  bl GXSetLineWidth;
  lbz r7, 0x84(r28);
  mr r4, r31;
  lbz r6, 0x85(r28);
  li r3, 4;
  lbz r5, 0x86(r28);
  lbz r0, 0x87(r28);
  stb r7, 0x24(r1);
  stb r6, 0x25(r1);
  stb r5, 0x26(r1);
  stb r0, 0x27(r1);
  stb r7, 0x18(r1);
  stb r6, 0x19(r1);
  stb r5, 0x1a(r1);
  stb r0, 0x1b(r1);
  bl GXSetChanMatColor;
  lfs f31, 0x148(r28);
  li r3, 0xa8;
  li r4, 0;
  li r5, 2;
  bl GXBegin;
  stfs f28, -0x8000(r27);
  li r3, 0xc;
  lfs f0, -0x5fec(r2);
  li r4, 0;
  stfs f0, -0x8000(r27);
  stfs f28, -0x8000(r27);
  stfs f31, -0x8000(r27);
  bl GXSetLineWidth;
  lbz r7, 0x4c(r28);
  mr r4, r30;
  lbz r6, 0x4d(r28);
  li r3, 4;
  lbz r5, 0x4e(r28);
  lbz r0, 0x4f(r28);
  stb r7, 0x20(r1);
  stb r6, 0x21(r1);
  stb r5, 0x22(r1);
  stb r0, 0x23(r1);
  stb r7, 0x14(r1);
  stb r6, 0x15(r1);
  stb r5, 0x16(r1);
  stb r0, 0x17(r1);
  bl GXSetChanMatColor;
  lfs f31, 0x148(r28);
  li r3, 0xa8;
  li r4, 0;
  li r5, 2;
  bl GXBegin;
  stfs f28, -0x8000(r27);
  addi r29, r29, 1;
  lfs f0, -0x5fec(r2);
  stfs f0, -0x8000(r27);
  stfs f28, -0x8000(r27);
  fadds f28, f28, f27;
  stfs f31, -0x8000(r27);
lbl_802391f8:
  fcmpo cr0, f28, f29;
  mfcr r0;
  rlwinm. r0, r0, 1, 0x1f, 0x1f;
  beq lbl_80239214;
  lwz r0, 0x144(r28);
  cmplw r29, r0;
  blt lbl_80239110;
lbl_80239214:
  lbz r0, 0x152(r28);
  rlwinm. r0, r0, 0, 0x1e, 0x1e;
  beq lbl_8023922c;
  lbz r0, 0x153(r28);
  cmpw r29, r0;
  ble lbl_80239110;
lbl_8023922c:
  lfs f31, -0x6018(r2);
  addi r27, r1, 8;
  li r30, 0;
  lis r29, 0xcc01;
  b lbl_802392e0;
lbl_80239240:
  lbz r0, 0x1c(r3);
  clrlwi. r0, r0, 0x1f;
  bne lbl_802392e0;
  lbz r7, 0x10(r3);
  mr r4, r27;
  lbz r6, 0x11(r3);
  lbz r5, 0x12(r3);
  lbz r0, 0x13(r3);
  lfs f30, 0x18(r3);
  lfs f29, 0x14(r3);
  li r3, 4;
  stb r7, 0xc(r1);
  stb r6, 0xd(r1);
  stb r5, 0xe(r1);
  stb r0, 0xf(r1);
  stb r7, 8(r1);
  stb r6, 9(r1);
  stb r5, 0xa(r1);
  stb r0, 0xb(r1);
  bl GXSetChanMatColor;
  lfs f27, 4(r30);
  lfs f28, 0(r30);
  fcmpo cr0, f27, f31;
  ble lbl_802392e0;
  fcmpo cr0, f30, f31;
  ble lbl_802392e0;
  li r3, 0x80;
  li r4, 0;
  li r5, 4;
  bl GXBegin;
  stfs f28, -0x8000(r29);
  fadds f1, f28, f27;
  fadds f0, f29, f30;
  stfs f29, -0x8000(r29);
  stfs f1, -0x8000(r29);
  stfs f29, -0x8000(r29);
  stfs f1, -0x8000(r29);
  stfs f0, -0x8000(r29);
  stfs f28, -0x8000(r29);
  stfs f0, -0x8000(r29);
lbl_802392e0:
  mr r4, r30;
  addi r3, r28, 0x60;
  bl List_GetNext__Q24nw4r2utFPCQ34nw4r2ut4ListPCv;
  cmpwi r3, 0;
  mr r30, r3;
  bne lbl_80239240;
lbl_802392f8:
  psq_l f31, 152(r1), 0, 0;
  lfd f31, 0x90(r1);
  psq_l f30, 136(r1), 0, 0;
  lfd f30, 0x80(r1);
  psq_l f29, 120(r1), 0, 0;
  lfd f29, 0x70(r1);
  psq_l f28, 104(r1), 0, 0;
  lfd f28, 0x60(r1);
  psq_l f27, 88(r1), 0, 0;
  addi r11, r1, 0x50;
  lfd f27, 0x50(r1);
  bl _restgpr_27;
  lwz r0, 0xa4(r1);
  mtlr r0;
  addi r1, r1, 0xa0;
  blr;
  // clang-format on
}

// Symbol: ProcessMeter_draw2
MARK_BINARY_BLOB(ProcessMeter_draw2, 0x80239338, 0x802393e0);
asm UNKNOWN_FUNCTION(ProcessMeter_draw2) {
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  stw r30, 0x18(r1);
  mr r30, r3;
  lwz r3, -0x5ca0(r13);
  lwz r12, 0(r3);
  lwz r12, 8(r12);
  mtctr r12;
  bctrl;
  lwz r31, 0(r3);
  lwz r3, -0x5ca0(r13);
  lwz r12, 0(r3);
  lwz r12, 0x10(r12);
  mtctr r12;
  bctrl;
  lwz r12, 4(r3);
  lwz r12, 0x18(r12);
  mtctr r12;
  bctrl;
  lhz r6, 4(r31);
  lis r5, 0x4330;
  stw r6, 0xc(r1);
  mr r4, r3;
  lhz r0, 6(r31);
  mr r3, r30;
  stw r5, 8(r1);
  lfd f2, -0x6008(r2);
  lfd f0, 8(r1);
  stw r0, 0x14(r1);
  fsubs f1, f0, f2;
  stw r5, 0x10(r1);
  lfd f0, 0x10(r1);
  fsubs f2, f0, f2;
  bl ProcessMeter_draw;
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: ProcessMeter_drawSetting
// PAL: 0x802393e0..0x80239628
MARK_BINARY_BLOB(ProcessMeter_drawSetting, 0x802393e0, 0x80239628);
asm UNKNOWN_FUNCTION(ProcessMeter_drawSetting) {
  // clang-format off
  nofralloc;
  stwu r1, -0x110(r1);
  mflr r0;
  stw r0, 0x114(r1);
  stfd f31, 0x100(r1);
  psq_st f31, 264(r1), 0, 0;
  stfd f30, 0xf0(r1);
  psq_st f30, 248(r1), 0, 0;
  stfd f29, 0xe0(r1);
  psq_st f29, 232(r1), 0, 0;
  fmr f29, f1;
  fmr f30, f2;
  lfs f1, -0x6018(r2);
  stw r31, 0xdc(r1);
  fmr f31, f3;
  fmr f2, f1;
  stw r30, 0xd8(r1);
  fmr f3, f29;
  lfs f6, -0x6000(r2);
  fmr f4, f30;
  mr r30, r3;
  fmr f5, f1;
  bl GXSetViewport;
  fmr f1, f30;
  bl __cvt_fp2unsigned;
  fmr f1, f29;
  mr r31, r3;
  bl __cvt_fp2unsigned;
  mr r5, r3;
  mr r6, r31;
  li r3, 0;
  li r4, 0;
  bl GXSetScissor;
  lfs f1, -0x6000(r2);
  addi r3, r1, 0x98;
  lfs f2, -0x6018(r2);
  fmr f4, f1;
  fmr f3, f2;
  fmr f5, f2;
  fmr f6, f1;
  bl C_MTXOrtho;
  addi r3, r1, 0x98;
  li r4, 1;
  bl GXSetProjection;
  lfs f1, 0x50(r30);
  addi r3, r1, 8;
  lfs f2, -0x5fe8(r2);
  lfs f0, 0x54(r30);
  fdivs f1, f1, f2;
  lfs f3, -0x6018(r2);
  fdivs f2, f0, f2;
  bl PSMTXTrans;
  lfs f1, 0x58(r30);
  addi r3, r1, 0x38;
  lfs f2, -0x5fe8(r2);
  lfs f0, 0x5c(r30);
  fdivs f1, f1, f2;
  lfs f3, -0x6018(r2);
  fdivs f2, f0, f2;
  bl PSMTXScale;
  addi r3, r1, 8;
  addi r4, r1, 0x38;
  addi r5, r1, 0x68;
  bl PSMTXConcat;
  lbz r0, 0x152(r30);
  rlwinm. r0, r0, 0, 0x1e, 0x1e;
  beq lbl_8023950c;
  lfs f0, 0x78(r30);
  fcmpo cr0, f0, f31;
  bge lbl_8023950c;
  lfs f2, -0x6000(r2);
  addi r3, r1, 0x38;
  fdivs f1, f2, f31;
  fmr f3, f2;
  bl PSMTXScale;
  b lbl_80239524;
lbl_8023950c:
  lfs f2, -0x6000(r2);
  addi r3, r1, 0x38;
  lfs f0, 0x78(r30);
  fmr f3, f2;
  fdivs f1, f2, f0;
  bl PSMTXScale;
lbl_80239524:
  addi r3, r1, 0x68;
  addi r4, r1, 0x38;
  mr r5, r3;
  bl PSMTXConcat;
  addi r3, r1, 0x68;
  li r4, 0;
  bl GXLoadPosMtxImm;
  li r3, 0;
  bl GXSetCurrentMtx;
  li r3, 4;
  li r4, 0;
  li r5, 0;
  li r6, 0;
  li r7, 0;
  li r8, 0;
  li r9, 2;
  bl GXSetChanCtrl;
  li r3, 1;
  bl GXSetNumChans;
  li r3, 0;
  bl GXSetNumIndStages;
  li r3, 0;
  bl GXSetNumTexGens;
  li r3, 0;
  li r4, 0xff;
  li r5, 0xff;
  li r6, 4;
  bl GXSetTevOrder;
  li r3, 0;
  li r4, 4;
  bl GXSetTevOp;
  li r3, 1;
  bl GXSetNumTevStages;
  li r3, 0;
  bl GXSetCullMode;
  li r3, 2;
  li r4, 1;
  li r5, 0;
  li r6, 3;
  bl GXSetBlendMode;
  li r3, 1;
  bl GXSetColorUpdate;
  bl GXClearVtxDesc;
  li r3, 0;
  li r4, 9;
  li r5, 0;
  li r6, 4;
  li r7, 0;
  bl GXSetVtxAttrFmt;
  li r3, 0;
  li r4, 7;
  li r5, 0;
  bl GXSetZMode;
  psq_l f31, 264(r1), 0, 0;
  lfd f31, 0x100(r1);
  psq_l f30, 248(r1), 0, 0;
  lfd f30, 0xf0(r1);
  psq_l f29, 232(r1), 0, 0;
  lfd f29, 0xe0(r1);
  lwz r31, 0xdc(r1);
  lwz r0, 0x114(r1);
  lwz r30, 0xd8(r1);
  mtlr r0;
  addi r1, r1, 0x110;
  blr;
  // clang-format on
}

// Symbol: ProcessMeter_destroy
// PAL: 0x80239628..0x80239680
MARK_BINARY_BLOB(ProcessMeter_destroy, 0x80239628, 0x80239680);
asm UNKNOWN_FUNCTION(ProcessMeter_destroy) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmpwi r3, 0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  beq lbl_80239664;
  li r4, 0;
  bl __dt__Q23EGG6ThreadFv;
  cmpwi r31, 0;
  ble lbl_80239664;
  mr r3, r30;
  bl __dl__FPv;
lbl_80239664:
  mr r3, r30;
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: ProcessMeter_isVisible_
// PAL: 0x80239680..0x80239688
MARK_BINARY_BLOB(ProcessMeter_isVisible_, 0x80239680, 0x80239688);
asm UNKNOWN_FUNCTION(ProcessMeter_isVisible_) {
  // clang-format off
  nofralloc;
  addi r3, r3, -72;
  b ProcessMeter_isVisible;
  // clang-format on
}

// Symbol: ProcessMeter_setVisible_
// PAL: 0x80239688..0x80239690
MARK_BINARY_BLOB(ProcessMeter_setVisible_, 0x80239688, 0x80239690);
asm UNKNOWN_FUNCTION(ProcessMeter_setVisible_) {
  // clang-format off
  nofralloc;
  addi r3, r3, -72;
  b ProcessMeter_setVisible;
  // clang-format on
}

// Symbol: ProcessMeter_draw_
// PAL: 0x80239690..0x80239698
MARK_BINARY_BLOB(ProcessMeter_draw_, 0x80239690, 0x80239698);
asm UNKNOWN_FUNCTION(ProcessMeter_draw_) {
  // clang-format off
  nofralloc;
  addi r3, r3, -72;
  b ProcessMeter_draw2;
  // clang-format on
}

// Symbol: ProcessMeter_callbackDrawSync_
// PAL: 0x80239698..0x802396a0
MARK_BINARY_BLOB(ProcessMeter_callbackDrawSync_, 0x80239698, 0x802396a0);
asm UNKNOWN_FUNCTION(ProcessMeter_callbackDrawSync_) {
  // clang-format off
  nofralloc;
  addi r3, r3, -72;
  b ProcessMeter_callbackDrawSync;
  // clang-format on
}

// Symbol: ProcessMeter_measureEndRender_
// PAL: 0x802396a0..0x802396a8
MARK_BINARY_BLOB(ProcessMeter_measureEndRender_, 0x802396a0, 0x802396a8);
asm UNKNOWN_FUNCTION(ProcessMeter_measureEndRender_) {
  // clang-format off
  nofralloc;
  addi r3, r3, -72;
  b ProcessMeter_measureEndRender;
  // clang-format on
}

// Symbol: ProcessMeter_measureBeginRender_
// PAL: 0x802396a8..0x802396b0
MARK_BINARY_BLOB(ProcessMeter_measureBeginRender_, 0x802396a8, 0x802396b0);
asm UNKNOWN_FUNCTION(ProcessMeter_measureBeginRender_) {
  // clang-format off
  nofralloc;
  addi r3, r3, -72;
  b ProcessMeter_measureBeginRender;
  // clang-format on
}

// Symbol: ProcessMeter_measureEndFrame_
// PAL: 0x802396b0..0x802396b8
MARK_BINARY_BLOB(ProcessMeter_measureEndFrame_, 0x802396b0, 0x802396b8);
asm UNKNOWN_FUNCTION(ProcessMeter_measureEndFrame_) {
  // clang-format off
  nofralloc;
  addi r3, r3, -72;
  b ProcessMeter_measureEndFrame;
  // clang-format on
}

// Symbol: ProcessMeter_measureBeginFrame_
// PAL: 0x802396b8..0x802396c0
MARK_BINARY_BLOB(ProcessMeter_measureBeginFrame_, 0x802396b8, 0x802396c0);
asm UNKNOWN_FUNCTION(ProcessMeter_measureBeginFrame_) {
  // clang-format off
  nofralloc;
  addi r3, r3, -72;
  b ProcessMeter_measureBeginFrame;
  // clang-format on
}


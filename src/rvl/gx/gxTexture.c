#include "gxTexture.h"

#include <string.h>

// Extern function references.
// PAL: 0x80171c28
extern UNKNOWN_FUNCTION(__GXFlushTextureState);

extern const f32 unk_80388738;
extern const f64 unk_80388740;
extern const f32 unk_80388748;
extern const f32 unk_8038874c;
extern const f32 unk_80388750;
extern const f32 unk_80388754;
extern const f32 unk_80388758;
extern const f32 unk_8038875c;
extern const f32 unk_80388760;
extern const f32 unk_80388764;
extern const f32 unk_80388768;

// Symbol: GXGetTexBufferSize
// PAL: 0x80170614..0x80170738
MARK_BINARY_BLOB(GXGetTexBufferSize, 0x80170614, 0x80170738);
asm UNKNOWN_FUNCTION(GXGetTexBufferSize) {
  // clang-format off
  nofralloc;
  cmplwi r5, 0x3c;
  bgt lbl_80170658;
  lis r8, 0x8029;
  slwi r0, r5, 2;
  addi r8, r8, -23656;
  lwzx r8, r8, r0;
  mtctr r8;
  bctr;
  li r10, 3;
  li r0, 3;
  b lbl_80170660;
  li r10, 3;
  li r0, 2;
  b lbl_80170660;
  li r10, 2;
  li r0, 2;
  b lbl_80170660;
lbl_80170658:
  li r0, 0;
  li r10, 0;
lbl_80170660:
  cmplwi r5, 6;
  beq lbl_80170670;
  cmplwi r5, 0x16;
  bne lbl_80170678;
lbl_80170670:
  li r11, 0x40;
  b lbl_8017067c;
lbl_80170678:
  li r11, 0x20;
lbl_8017067c:
  cmplwi r6, 1;
  bne lbl_80170704;
  li r5, 1;
  li r12, 0;
  slw r8, r5, r10;
  slw r9, r5, r0;
  mtctr r7;
  cmplwi r7, 0;
  ble lbl_80170730;
lbl_801706a0:
  add r6, r3, r8;
  add r5, r4, r9;
  addi r6, r6, -1;
  cmplwi r3, 1;
  sraw r6, r6, r10;
  addi r5, r5, -1;
  mullw r6, r11, r6;
  sraw r5, r5, r0;
  mullw r5, r6, r5;
  add r12, r12, r5;
  bne lbl_801706d4;
  cmplwi r4, 1;
  beq lbl_80170730;
lbl_801706d4:
  cmplwi r3, 1;
  li r5, 1;
  ble lbl_801706e4;
  rlwinm r5, r3, 0x1f, 0x11, 0x1f;
lbl_801706e4:
  cmplwi r4, 1;
  clrlwi r3, r5, 0x10;
  li r5, 1;
  ble lbl_801706f8;
  rlwinm r5, r4, 0x1f, 0x11, 0x1f;
lbl_801706f8:
  clrlwi r4, r5, 0x10;
  bdnz lbl_801706a0;
  b lbl_80170730;
lbl_80170704:
  li r6, 1;
  slw r5, r6, r10;
  add r5, r3, r5;
  slw r3, r6, r0;
  addi r5, r5, -1;
  sraw r5, r5, r10;
  add r3, r4, r3;
  mullw r4, r11, r5;
  addi r3, r3, -1;
  sraw r0, r3, r0;
  mullw r12, r4, r0;
lbl_80170730:
  mr r3, r12;
  blr;
  // clang-format on
}

// Symbol: __GetImageTileCount
// PAL: 0x80170738..0x801707f8
MARK_BINARY_BLOB(__GetImageTileCount, 0x80170738, 0x801707f8);
asm UNKNOWN_FUNCTION(__GetImageTileCount) {
  // clang-format off
  nofralloc;
  cmplwi r3, 0x3c;
  bgt lbl_8017077c;
  lis r9, 0x8029;
  slwi r0, r3, 2;
  addi r9, r9, -23412;
  lwzx r9, r9, r0;
  mtctr r9;
  bctr;
  li r11, 3;
  li r12, 3;
  b lbl_80170784;
  li r11, 3;
  li r12, 2;
  b lbl_80170784;
  li r11, 2;
  li r12, 2;
  b lbl_80170784;
lbl_8017077c:
  li r12, 0;
  li r11, 0;
lbl_80170784:
  cmpwi r4, 0;
  bne lbl_80170790;
  li r4, 1;
lbl_80170790:
  cmpwi r5, 0;
  bne lbl_8017079c;
  li r5, 1;
lbl_8017079c:
  li r10, 1;
  cmpwi r3, 6;
  slw r0, r10, r11;
  li r9, 0;
  add r4, r4, r0;
  slw r0, r10, r12;
  addi r4, r4, -1;
  sraw r10, r4, r11;
  add r4, r5, r0;
  stw r10, 0(r6);
  addi r0, r4, -1;
  sraw r0, r0, r12;
  stw r0, 0(r7);
  beq lbl_801707dc;
  cmpwi r3, 0x16;
  bne lbl_801707e0;
lbl_801707dc:
  li r9, 1;
lbl_801707e0:
  neg r0, r9;
  or r0, r0, r9;
  srwi r3, r0, 0x1f;
  addi r0, r3, 1;
  stw r0, 0(r8);
  blr;
  // clang-format on
}

// Symbol: GXInitTexObj
// PAL: 0x801707f8..0x80170a04
MARK_BINARY_BLOB(GXInitTexObj, 0x801707f8, 0x80170a04);
asm void GXInitTexObj(GXTexObj* obj, void* image_ptr, u16 width, u16 height,
                      int format, int wrap_s, int wrap_t, int mipmap) {
  // clang-format off
  nofralloc;
  stwu r1, -0x40(r1);
  mflr r0;
  stw r0, 0x44(r1);
  addi r11, r1, 0x40;
  bl _savegpr_24;
  mr r27, r4;
  mr r28, r5;
  mr r31, r3;
  mr r29, r6;
  mr r30, r7;
  mr r24, r8;
  mr r25, r9;
  mr r26, r10;
  li r4, 0;
  li r5, 0x20;
  bl memset;
  lwz r0, 0(r31);
  rlwimi r0, r24, 0, 0x1e, 0x1f;
  rlwimi r0, r25, 2, 0x1c, 0x1d;
  cmpwi r26, 0;
  ori r4, r0, 0x10;
  stw r4, 0(r31);
  beq lbl_801708e0;
  lbz r3, 0x1f(r31);
  addi r0, r30, -8;
  cmplwi r0, 2;
  ori r0, r3, 1;
  stb r0, 0x1f(r31);
  bgt lbl_8017087c;
  li r0, 5;
  rlwimi r4, r0, 5, 0x18, 0x1a;
  stw r4, 0(r31);
  b lbl_80170888;
lbl_8017087c:
  li r0, 6;
  rlwimi r4, r0, 5, 0x18, 0x1a;
  stw r4, 0(r31);
lbl_80170888:
  cmplw r28, r29;
  ble lbl_8017089c;
  cntlzw r0, r28;
  subfic r3, r0, 0x1f;
  b lbl_801708a4;
lbl_8017089c:
  cntlzw r0, r29;
  subfic r3, r0, 0x1f;
lbl_801708a4:
  lis r0, 0x4330;
  stw r3, 0xc(r1);
  lfd f2, unk_80388740;
  stw r0, 8(r1);
  lfs f0, unk_80388738;
  lfd f1, 8(r1);
  lwz r0, 4(r31);
  fsubs f1, f1, f2;
  fmuls f0, f0, f1;
  fctiwz f0, f0;
  stfd f0, 0x10(r1);
  lwz r3, 0x14(r1);
  rlwimi r0, r3, 8, 0x10, 0x17;
  stw r0, 4(r31);
  b lbl_801708ec;
lbl_801708e0:
  li r0, 4;
  rlwimi r4, r0, 5, 0x18, 0x1a;
  stw r4, 0(r31);
lbl_801708ec:
  addi r0, r28, -1;
  lwz r3, 8(r31);
  rlwimi r3, r0, 0, 0x16, 0x1f;
  clrlwi r4, r30, 0x1c;
  addi r0, r29, -1;
  stw r30, 0x14(r31);
  rlwimi r3, r0, 0xa, 0xc, 0x15;
  lwz r0, 0xc(r31);
  rlwimi r0, r27, 0x1b, 8, 0x1f;
  cmplwi r4, 0xe;
  rlwimi r3, r30, 0x14, 8, 0xb;
  stw r0, 0xc(r31);
  stw r3, 8(r31);
  bgt lbl_801709a0;
  lis r3, 0x8029;
  slwi r0, r4, 2;
  addi r3, r3, -23168;
  lwzx r3, r3, r0;
  mtctr r3;
  bctr;
  li r0, 1;
  li r6, 3;
  stb r0, 0x1e(r31);
  li r7, 3;
  b lbl_801709b0;
  li r0, 2;
  li r6, 3;
  stb r0, 0x1e(r31);
  li r7, 2;
  b lbl_801709b0;
  li r0, 2;
  li r6, 2;
  stb r0, 0x1e(r31);
  li r7, 2;
  b lbl_801709b0;
  li r0, 3;
  li r6, 2;
  stb r0, 0x1e(r31);
  li r7, 2;
  b lbl_801709b0;
  li r0, 0;
  li r6, 3;
  stb r0, 0x1e(r31);
  li r7, 3;
  b lbl_801709b0;
lbl_801709a0:
  li r0, 2;
  li r6, 2;
  stb r0, 0x1e(r31);
  li r7, 2;
lbl_801709b0:
  li r5, 1;
  lbz r0, 0x1f(r31);
  slw r3, r5, r6;
  addi r11, r1, 0x40;
  add r4, r28, r3;
  ori r0, r0, 2;
  slw r3, r5, r7;
  stb r0, 0x1f(r31);
  addi r4, r4, -1;
  add r3, r29, r3;
  sraw r4, r4, r6;
  addi r0, r3, -1;
  sraw r0, r0, r7;
  mullw r0, r4, r0;
  clrlwi r0, r0, 0x11;
  sth r0, 0x1c(r31);
  bl _restgpr_24;
  lwz r0, 0x44(r1);
  mtlr r0;
  addi r1, r1, 0x40;
  blr;
  // clang-format on
}

// Symbol: GXInitTexObjCI
// PAL: 0x80170a04..0x80170a4c
MARK_BINARY_BLOB(GXInitTexObjCI, 0x80170a04, 0x80170a4c);
asm UNKNOWN_FUNCTION(GXInitTexObjCI) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  lwz r31, 0x18(r1);
  stw r30, 8(r1);
  mr r30, r3;
  bl GXInitTexObj;
  lbz r0, 0x1f(r30);
  stw r31, 0x18(r30);
  rlwinm r0, r0, 0, 0x1f, 0x1d;
  stb r0, 0x1f(r30);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: GXInitTexObjLOD
// PAL: 0x80170a4c..0x80170b50
MARK_BINARY_BLOB(GXInitTexObjLOD, 0x80170a4c, 0x80170b50);
asm void GXInitTexObjLOD(GXTexObj* obj, int min_filt, int mag_filt, f32 min_lod,
                         f32 max_lod, f32 lod_bias, int bias_clamp,
                         int do_edge_lod, int max_aniso) {
  // clang-format off
  nofralloc;
  lfs f0, unk_80388748;
  stwu r1, -0x10(r1);
  fcmpo cr0, f3, f0;
  bge lbl_80170a64;
  fmr f3, f0;
  b lbl_80170a78;
lbl_80170a64:
  lfs f0, unk_80388750;
  fcmpo cr0, f3, f0;
  cror 2, 1, 2;
  bne lbl_80170a78;
  lfs f3, unk_8038874c;
lbl_80170a78:
  lfs f4, unk_80388754;
  addi r0, r5, -1;
  cntlzw r9, r0;
  lfs f0, unk_80388758;
  fmuls f3, f4, f3;
  cntlzw r0, r7;
  lwz r10, 0(r3);
  addi r5, r13, -29312;
  fcmpo cr0, f1, f0;
  fctiwz f3, f3;
  stfd f3, 8(r1);
  lwz r7, 0xc(r1);
  rlwimi r10, r7, 9, 0xf, 0x16;
  rlwimi r10, r9, 0x1f, 0x1b, 0x1b;
  stw r10, 0(r3);
  lbzx r4, r5, r4;
  rlwimi r10, r4, 5, 0x18, 0x1a;
  rlwimi r10, r0, 3, 0x17, 0x17;
  rlwinm r0, r10, 0, 0xf, 0xc;
  rlwimi r0, r8, 0x13, 0xb, 0xc;
  rlwimi r0, r6, 0x15, 0xa, 0xa;
  stw r0, 0(r3);
  bge lbl_80170adc;
  fmr f1, f0;
  b lbl_80170aec;
lbl_80170adc:
  lfs f0, unk_8038875c;
  fcmpo cr0, f1, f0;
  ble lbl_80170aec;
  fmr f1, f0;
lbl_80170aec:
  lfs f3, unk_80388738;
  lfs f0, unk_80388758;
  fmuls f1, f3, f1;
  fcmpo cr0, f2, f0;
  fctiwz f1, f1;
  stfd f1, 8(r1);
  lwz r4, 0xc(r1);
  bge lbl_80170b14;
  fmr f2, f0;
  b lbl_80170b24;
lbl_80170b14:
  lfs f0, unk_8038875c;
  fcmpo cr0, f2, f0;
  ble lbl_80170b24;
  fmr f2, f0;
lbl_80170b24:
  lfs f0, unk_80388738;
  lwz r0, 4(r3);
  rlwimi r0, r4, 0, 0x18, 0x1f;
  fmuls f0, f0, f2;
  fctiwz f0, f0;
  stfd f0, 8(r1);
  lwz r4, 0xc(r1);
  rlwimi r0, r4, 8, 0x10, 0x17;
  stw r0, 4(r3);
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: GXInitTexObjWrapMode
// PAL: 0x80170b50..0x80170b64
MARK_BINARY_BLOB(GXInitTexObjWrapMode, 0x80170b50, 0x80170b64);
asm UNKNOWN_FUNCTION(GXInitTexObjWrapMode) {
  // clang-format off
  nofralloc;
  lwz r0, 0(r3);
  rlwimi r0, r4, 0, 0x1e, 0x1f;
  rlwimi r0, r5, 2, 0x1c, 0x1d;
  stw r0, 0(r3);
  blr;
  // clang-format on
}

// Symbol: GXInitTexObjTlut
// PAL: 0x80170b64..0x80170b6c
MARK_BINARY_BLOB(GXInitTexObjTlut, 0x80170b64, 0x80170b6c);
asm UNKNOWN_FUNCTION(GXInitTexObjTlut) {
  // clang-format off
  nofralloc;
  stw r4, 0x18(r3);
  blr;
  // clang-format on
}

// Symbol: GXInitTexObjFilter
// PAL: 0x80170b6c..0x80170b94
MARK_BINARY_BLOB(GXInitTexObjFilter, 0x80170b6c, 0x80170b94);
asm UNKNOWN_FUNCTION(GXInitTexObjFilter) {
  // clang-format off
  nofralloc;
  addi r0, r5, -1;
  lwz r6, 0(r3);
  cntlzw r0, r0;
  addi r5, r13, -29312;
  rlwimi r6, r0, 0x1f, 0x1b, 0x1b;
  stw r6, 0(r3);
  lbzx r0, r5, r4;
  rlwimi r6, r0, 5, 0x18, 0x1a;
  stw r6, 0(r3);
  blr;
  // clang-format on
}

// Symbol: GXInitTexObjLODBias
// PAL: 0x80170b94..0x80170be8
MARK_BINARY_BLOB(GXInitTexObjLODBias, 0x80170b94, 0x80170be8);
asm UNKNOWN_FUNCTION(GXInitTexObjLODBias) {
  // clang-format off
  nofralloc;
  lfs f0, unk_80388748;
  stwu r1, -0x10(r1);
  fcmpo cr0, f1, f0;
  bge lbl_80170bac;
  fmr f1, f0;
  b lbl_80170bc0;
lbl_80170bac:
  lfs f0, unk_80388750;
  fcmpo cr0, f1, f0;
  cror 2, 1, 2;
  bne lbl_80170bc0;
  lfs f1, unk_8038874c;
lbl_80170bc0:
  lfs f0, unk_80388754;
  lwz r0, 0(r3);
  fmuls f0, f0, f1;
  fctiwz f0, f0;
  stfd f0, 8(r1);
  lwz r4, 0xc(r1);
  rlwimi r0, r4, 9, 0xf, 0x16;
  stw r0, 0(r3);
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: GXInitTexObjUserData
// PAL: 0x80170be8..0x80170bf0
MARK_BINARY_BLOB(GXInitTexObjUserData, 0x80170be8, 0x80170bf0);
asm UNKNOWN_FUNCTION(GXInitTexObjUserData) {
  // clang-format off
  nofralloc;
  stw r4, 0x10(r3);
  blr;
  // clang-format on
}

// Symbol: GXGetTexObjUserData
// PAL: 0x80170bf0..0x80170bf8
MARK_BINARY_BLOB(GXGetTexObjUserData, 0x80170bf0, 0x80170bf8);
asm UNKNOWN_FUNCTION(GXGetTexObjUserData) {
  // clang-format off
  nofralloc;
  lwz r3, 0x10(r3);
  blr;
  // clang-format on
}

// Symbol: GXGetTexObjAll
// PAL: 0x80170bf8..0x80170c5c
MARK_BINARY_BLOB(GXGetTexObjAll, 0x80170bf8, 0x80170c5c);
asm UNKNOWN_FUNCTION(GXGetTexObjAll) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  lwz r0, 0xc(r3);
  stw r31, 0xc(r1);
  lwz r31, 8(r3);
  rlwinm r0, r0, 5, 3, 0x1a;
  stw r0, 0(r4);
  clrlwi r12, r31, 0x16;
  rlwinm r4, r31, 0x16, 0x16, 0x1f;
  addi r0, r12, 1;
  lwz r11, 0(r3);
  sth r0, 0(r5);
  addi r4, r4, 1;
  lbz r0, 0x1f(r3);
  clrlwi r5, r11, 0x1e;
  sth r4, 0(r6);
  rlwinm r4, r11, 0x1e, 0x1e, 0x1f;
  lwz r3, 0x14(r3);
  clrlwi r0, r0, 0x1f;
  stw r3, 0(r7);
  stw r5, 0(r8);
  stw r4, 0(r9);
  stb r0, 0(r10);
  lwz r31, 0xc(r1);
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: GXGetTexObjData
// PAL: 0x80170c5c..0x80170c68
MARK_BINARY_BLOB(GXGetTexObjData, 0x80170c5c, 0x80170c68);
asm UNKNOWN_FUNCTION(GXGetTexObjData) {
  // clang-format off
  nofralloc;
  lwz r0, 0xc(r3);
  rlwinm r3, r0, 5, 3, 0x1a;
  blr;
  // clang-format on
}

// Symbol: GXGetTexObjWidth
// PAL: 0x80170c68..0x80170c7c
MARK_BINARY_BLOB(GXGetTexObjWidth, 0x80170c68, 0x80170c7c);
asm UNKNOWN_FUNCTION(GXGetTexObjWidth) {
  // clang-format off
  nofralloc;
  lwz r0, 8(r3);
  clrlwi r3, r0, 0x16;
  addi r0, r3, 1;
  clrlwi r3, r0, 0x10;
  blr;
  // clang-format on
}

// Symbol: GXGetTexObjHeight
// PAL: 0x80170c7c..0x80170c90
MARK_BINARY_BLOB(GXGetTexObjHeight, 0x80170c7c, 0x80170c90);
asm UNKNOWN_FUNCTION(GXGetTexObjHeight) {
  // clang-format off
  nofralloc;
  lwz r0, 8(r3);
  rlwinm r3, r0, 0x16, 0x16, 0x1f;
  addi r0, r3, 1;
  clrlwi r3, r0, 0x10;
  blr;
  // clang-format on
}

// Symbol: GXGetTexObjFmt
// PAL: 0x80170c90..0x80170c98
MARK_BINARY_BLOB(GXGetTexObjFmt, 0x80170c90, 0x80170c98);
asm UNKNOWN_FUNCTION(GXGetTexObjFmt) {
  // clang-format off
  nofralloc;
  lwz r3, 0x14(r3);
  blr;
  // clang-format on
}

// Symbol: GXGetTexObjWrapS
// PAL: 0x80170c98..0x80170ca4
MARK_BINARY_BLOB(GXGetTexObjWrapS, 0x80170c98, 0x80170ca4);
asm UNKNOWN_FUNCTION(GXGetTexObjWrapS) {
  // clang-format off
  nofralloc;
  lwz r0, 0(r3);
  clrlwi r3, r0, 0x1e;
  blr;
  // clang-format on
}

// Symbol: GXGetTexObjWrapT
// PAL: 0x80170ca4..0x80170cb0
MARK_BINARY_BLOB(GXGetTexObjWrapT, 0x80170ca4, 0x80170cb0);
asm UNKNOWN_FUNCTION(GXGetTexObjWrapT) {
  // clang-format off
  nofralloc;
  lwz r0, 0(r3);
  rlwinm r3, r0, 0x1e, 0x1e, 0x1f;
  blr;
  // clang-format on
}

// Symbol: GXGetTexObjMipMap
// PAL: 0x80170cb0..0x80170cbc
MARK_BINARY_BLOB(GXGetTexObjMipMap, 0x80170cb0, 0x80170cbc);
asm UNKNOWN_FUNCTION(GXGetTexObjMipMap) {
  // clang-format off
  nofralloc;
  lbz r0, 0x1f(r3);
  clrlwi r3, r0, 0x1f;
  blr;
  // clang-format on
}

// Symbol: GXGetTexObjLODAll
// PAL: 0x80170cbc..0x80170da0
MARK_BINARY_BLOB(GXGetTexObjLODAll, 0x80170cbc, 0x80170da0);
asm UNKNOWN_FUNCTION(GXGetTexObjLODAll) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  lwz r0, 4(r3);
  stw r31, 0x2c(r1);
  lis r31, 0x4330;
  clrlwi r11, r0, 0x18;
  lfd f5, unk_80388740;
  stw r30, 0x28(r1);
  lfs f3, unk_80388760;
  stw r29, 0x24(r1);
  addi r29, r13, -29304;
  lfd f2, unk_80388768;
  stw r28, 0x20(r1);
  lwz r28, 0(r3);
  rlwinm r3, r0, 0x18, 0x18, 0x1f;
  stw r11, 0xc(r1);
  rlwinm r0, r28, 0x17, 0x18, 0x1f;
  rlwinm r11, r28, 0x1b, 0x1d, 0x1f;
  stw r31, 8(r1);
  extsh r0, r0;
  extsb r0, r0;
  lbzx r29, r29, r11;
  xoris r12, r0, 0x8000;
  lfd f0, 8(r1);
  stw r3, 0x14(r1);
  rlwinm r0, r28, 0x18, 0x1f, 0x1f;
  fsubs f1, f0, f5;
  cntlzw r0, r0;
  stw r31, 0x10(r1);
  rlwinm r30, r28, 0x1c, 0x1f, 0x1f;
  rlwinm r3, r0, 0x1b, 0x18, 0x1f;
  rlwinm r11, r28, 0xb, 0x1f, 0x1f;
  stw r29, 0(r4);
  fmuls f4, f1, f3;
  lfd f0, 0x10(r1);
  rlwinm r0, r28, 0xd, 0x1e, 0x1f;
  stw r30, 0(r5);
  fsubs f1, f0, f5;
  lfs f0, unk_80388764;
  stw r12, 0x1c(r1);
  lwz r4, 0x38(r1);
  stw r31, 0x18(r1);
  fmuls f3, f1, f3;
  lfd f1, 0x18(r1);
  stfs f4, 0(r6);
  fsubs f1, f1, f2;
  stfs f3, 0(r7);
  fmuls f0, f1, f0;
  stfs f0, 0(r8);
  stb r11, 0(r9);
  stb r3, 0(r10);
  stw r0, 0(r4);
  lwz r31, 0x2c(r1);
  lwz r30, 0x28(r1);
  lwz r29, 0x24(r1);
  lwz r28, 0x20(r1);
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: GXGetTexObjMinFilt
// PAL: 0x80170da0..0x80170db4
MARK_BINARY_BLOB(GXGetTexObjMinFilt, 0x80170da0, 0x80170db4);
asm UNKNOWN_FUNCTION(GXGetTexObjMinFilt) {
  // clang-format off
  nofralloc;
  lwz r0, 0(r3);
  addi r3, r13, -29304;
  rlwinm r0, r0, 0x1b, 0x1d, 0x1f;
  lbzx r3, r3, r0;
  blr;
  // clang-format on
}

// Symbol: GXGetTexObjMagFilt
// PAL: 0x80170db4..0x80170dc0
MARK_BINARY_BLOB(GXGetTexObjMagFilt, 0x80170db4, 0x80170dc0);
asm UNKNOWN_FUNCTION(GXGetTexObjMagFilt) {
  // clang-format off
  nofralloc;
  lwz r0, 0(r3);
  rlwinm r3, r0, 0x1c, 0x1f, 0x1f;
  blr;
  // clang-format on
}

// Symbol: GXGetTexObjTlut
// PAL: 0x80170dc0..0x80170dc8
MARK_BINARY_BLOB(GXGetTexObjTlut, 0x80170dc0, 0x80170dc8);
asm UNKNOWN_FUNCTION(GXGetTexObjTlut) {
  // clang-format off
  nofralloc;
  lwz r3, 0x18(r3);
  blr;
  // clang-format on
}

// Symbol: GXLoadTexObjPreLoaded
// PAL: 0x80170dc8..0x80170f2c
MARK_BINARY_BLOB(GXLoadTexObjPreLoaded, 0x80170dc8, 0x80170f2c);
asm UNKNOWN_FUNCTION(GXLoadTexObjPreLoaded) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  addi r11, r13, -29368;
  addi r10, r13, -29360;
  stw r0, 0x24(r1);
  addi r9, r13, -29352;
  lwz r12, 0(r3);
  addi r8, r13, -29344;
  stw r31, 0x1c(r1);
  addi r7, r13, -29336;
  addi r6, r13, -29328;
  mr r31, r5;
  stw r30, 0x18(r1);
  mr r30, r3;
  stw r29, 0x14(r1);
  lis r29, 0xcc01;
  stw r28, 0x10(r1);
  li r28, 0x61;
  lbzx r0, r11, r5;
  lwz r11, 4(r3);
  rlwimi r12, r0, 0x18, 0, 7;
  lbzx r0, r10, r5;
  lbzx r10, r9, r5;
  rlwimi r11, r0, 0x18, 0, 7;
  lbzx r0, r7, r5;
  lbzx r8, r8, r5;
  lbzx r5, r6, r5;
  lwz r9, 8(r3);
  rlwimi r9, r10, 0x18, 0, 7;
  stb r28, -0x8000(r29);
  lwz r7, 0(r4);
  rlwimi r7, r8, 0x18, 0, 7;
  stw r12, -0x8000(r29);
  lwz r6, 4(r4);
  rlwimi r6, r0, 0x18, 0, 7;
  stb r28, -0x8000(r29);
  lbz r0, 0x1f(r3);
  stw r11, -0x8000(r29);
  rlwinm. r0, r0, 0, 0x1e, 0x1e;
  lwz r0, 0xc(r3);
  stb r28, -0x8000(r29);
  rlwimi r0, r5, 0x18, 0, 7;
  stw r9, -0x8000(r29);
  stb r28, -0x8000(r29);
  stw r7, -0x8000(r29);
  stb r28, -0x8000(r29);
  stw r6, -0x8000(r29);
  stb r28, -0x8000(r29);
  stw r12, 0(r3);
  stw r11, 4(r3);
  stw r9, 8(r3);
  stw r7, 0(r4);
  stw r6, 4(r4);
  stw r0, 0xc(r3);
  stw r0, -0x8000(r29);
  bne lbl_80170edc;
  lwz r4, gx;
  lwz r3, 0x18(r3);
  lwz r12, 0x51c(r4);
  mtctr r12;
  bctrl;
  addi r4, r13, -29320;
  lwz r0, 4(r3);
  lbzx r4, r4, r31;
  rlwimi r0, r4, 0x18, 0, 7;
  stw r0, 4(r3);
  stb r28, -0x8000(r29);
  lwz r0, 4(r3);
  stw r0, -0x8000(r29);
lbl_80170edc:
  lwz r6, gx;
  slwi r3, r31, 2;
  lwz r5, 8(r30);
  li r0, 0;
  add r4, r6, r3;
  lwz r3, 0(r30);
  stw r5, 0x564(r4);
  stw r3, 0x584(r4);
  lwz r3, 0x5fc(r6);
  ori r3, r3, 1;
  stw r3, 0x5fc(r6);
  sth r0, 2(r6);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  lwz r28, 0x10(r1);
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: GXLoadTexObj
// PAL: 0x80170f2c..0x80170f80
MARK_BINARY_BLOB(GXLoadTexObj, 0x80170f2c, 0x80170f80);
asm void GXLoadTexObj(GXTexObj*, int texMapID) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lwz r5, gx;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r4;
  stw r30, 8(r1);
  mr r30, r3;
  lwz r12, 0x518(r5);
  mtctr r12;
  bctrl;
  mr r4, r3;
  mr r3, r30;
  mr r5, r31;
  bl GXLoadTexObjPreLoaded;
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: GXInitTlutObj
// PAL: 0x80170f80..0x80170fa8
MARK_BINARY_BLOB(GXInitTlutObj, 0x80170f80, 0x80170fa8);
asm UNKNOWN_FUNCTION(GXInitTlutObj) {
  // clang-format off
  nofralloc;
  lwz r7, 4(r3);
  li r0, 0x64;
  rlwimi r7, r4, 0x1b, 8, 0x1f;
  li r4, 0;
  rlwimi r4, r5, 0xa, 0x14, 0x15;
  sth r6, 8(r3);
  rlwimi r7, r0, 0x18, 0, 7;
  stw r4, 0(r3);
  stw r7, 4(r3);
  blr;
  // clang-format on
}

// Symbol: GXLoadTlut
// PAL: 0x80170fa8..0x8017103c
MARK_BINARY_BLOB(GXLoadTlut, 0x80170fa8, 0x8017103c);
asm UNKNOWN_FUNCTION(GXLoadTlut) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lwz r5, gx;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  stw r30, 8(r1);
  mr r30, r3;
  mr r3, r4;
  lwz r12, 0x51c(r5);
  mtctr r12;
  bctrl;
  mr r31, r3;
  bl __GXFlushTextureState;
  lis r3, 0xcc01;
  li r4, 0x61;
  stb r4, -0x8000(r3);
  lwz r0, 4(r30);
  stw r0, -0x8000(r3);
  stb r4, -0x8000(r3);
  lwz r0, 0(r31);
  stw r0, -0x8000(r3);
  bl __GXFlushTextureState;
  lwz r0, 0(r31);
  lwz r4, 0(r30);
  rlwimi r4, r0, 0, 0x16, 0x1f;
  lwz r3, 4(r30);
  stw r4, 4(r31);
  lwz r0, 8(r30);
  stw r3, 8(r31);
  stw r0, 0xc(r31);
  stw r4, 0(r30);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: GXInitTexCacheRegion
// PAL: 0x8017103c..0x801710f0
MARK_BINARY_BLOB(GXInitTexCacheRegion, 0x8017103c, 0x801710f0);
asm UNKNOWN_FUNCTION(GXInitTexCacheRegion) {
  // clang-format off
  nofralloc;
  cmpwi r6, 1;
  beq lbl_80171068;
  bge lbl_80171054;
  cmpwi r6, 0;
  bge lbl_80171060;
  b lbl_80171074;
lbl_80171054:
  cmpwi r6, 3;
  bge lbl_80171074;
  b lbl_80171070;
lbl_80171060:
  li r6, 3;
  b lbl_80171074;
lbl_80171068:
  li r6, 4;
  b lbl_80171074;
lbl_80171070:
  li r6, 5;
lbl_80171074:
  li r0, 0;
  cmpwi r8, 2;
  rlwimi r0, r5, 0x1b, 0x11, 0x1f;
  rlwimi r0, r6, 0xf, 0xe, 0x10;
  rlwimi r0, r6, 0x12, 0xb, 0xd;
  stw r0, 0(r3);
  beq lbl_801710c0;
  bge lbl_801710a4;
  cmpwi r8, 0;
  beq lbl_801710b0;
  bge lbl_801710b8;
  b lbl_801710cc;
lbl_801710a4:
  cmpwi r8, 4;
  bge lbl_801710cc;
  b lbl_801710c8;
lbl_801710b0:
  li r6, 3;
  b lbl_801710cc;
lbl_801710b8:
  li r6, 4;
  b lbl_801710cc;
lbl_801710c0:
  li r6, 5;
  b lbl_801710cc;
lbl_801710c8:
  li r6, 0;
lbl_801710cc:
  li r5, 0;
  li r0, 1;
  rlwimi r5, r7, 0x1b, 0x11, 0x1f;
  stb r4, 0xc(r3);
  rlwimi r5, r6, 0xf, 0xe, 0x10;
  rlwimi r5, r6, 0x12, 0xb, 0xd;
  stb r0, 0xd(r3);
  stw r5, 4(r3);
  blr;
  // clang-format on
}

// Symbol: GXInitTlutRegion
// PAL: 0x801710f0..0x80171110
MARK_BINARY_BLOB(GXInitTlutRegion, 0x801710f0, 0x80171110);
asm UNKNOWN_FUNCTION(GXInitTlutRegion) {
  // clang-format off
  nofralloc;
  addis r0, r4, 0xfff8;
  li r4, 0;
  rlwimi r4, r0, 0x17, 0x16, 0x1f;
  li r0, 0x65;
  rlwimi r4, r5, 0xa, 0xb, 0x15;
  rlwimi r4, r0, 0x18, 0, 7;
  stw r4, 0(r3);
  blr;
  // clang-format on
}

// Symbol: GXInvalidateTexAll
// PAL: 0x80171110..0x80171158
MARK_BINARY_BLOB(GXInvalidateTexAll, 0x80171110, 0x80171158);
asm UNKNOWN_FUNCTION(GXInvalidateTexAll) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  bl __GXFlushTextureState;
  lis r4, 0xcc01;
  li r5, 0x61;
  lis r3, 0x6600;
  stb r5, -0x8000(r4);
  addi r0, r3, 0x1000;
  stw r0, -0x8000(r4);
  addi r0, r3, 0x1100;
  stb r5, -0x8000(r4);
  stw r0, -0x8000(r4);
  bl __GXFlushTextureState;
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: GXSetTexRegionCallback
// PAL: 0x80171158..0x8017116c
MARK_BINARY_BLOB(GXSetTexRegionCallback, 0x80171158, 0x8017116c);
asm UNKNOWN_FUNCTION(GXSetTexRegionCallback) {
  // clang-format off
  nofralloc;
  lwz r4, gx;
  mr r0, r3;
  lwz r3, 0x518(r4);
  stw r0, 0x518(r4);
  blr;
  // clang-format on
}

// Symbol: GXSetTlutRegionCallback
// PAL: 0x8017116c..0x80171180
MARK_BINARY_BLOB(GXSetTlutRegionCallback, 0x8017116c, 0x80171180);
asm UNKNOWN_FUNCTION(GXSetTlutRegionCallback) {
  // clang-format off
  nofralloc;
  lwz r4, gx;
  mr r0, r3;
  lwz r3, 0x51c(r4);
  stw r0, 0x51c(r4);
  blr;
  // clang-format on
}

// Symbol: GXSetTexCoordScaleManually
// PAL: 0x80171180..0x801711fc
MARK_BINARY_BLOB(GXSetTexCoordScaleManually, 0x80171180, 0x801711fc);
asm UNKNOWN_FUNCTION(GXSetTexCoordScaleManually) {
  // clang-format off
  nofralloc;
  lwz r9, gx;
  li r0, 1;
  slw r7, r0, r3;
  cmpwi r4, 0;
  lwz r8, 0x5e4(r9);
  slw r0, r4, r3;
  andc r4, r8, r7;
  or r0, r4, r0;
  stw r0, 0x5e4(r9);
  beqlr;
  slwi r0, r3, 2;
  addi r3, r5, -1;
  add r8, r9, r0;
  addi r5, r6, -1;
  lwz r0, 0x108(r8);
  rlwimi r0, r3, 0, 0x10, 0x1f;
  lis r4, 0xcc01;
  li r7, 0x61;
  stw r0, 0x108(r8);
  li r0, 0;
  lwz r3, 0x128(r8);
  rlwimi r3, r5, 0, 0x10, 0x1f;
  stw r3, 0x128(r8);
  stb r7, -0x8000(r4);
  lwz r3, 0x108(r8);
  stw r3, -0x8000(r4);
  stb r7, -0x8000(r4);
  lwz r3, 0x128(r8);
  stw r3, -0x8000(r4);
  sth r0, 2(r9);
  blr;
  // clang-format on
}

// Symbol: GXSetTexCoordBias
// PAL: 0x801711fc..0x80171260
MARK_BINARY_BLOB(GXSetTexCoordBias, 0x801711fc, 0x80171260);
asm UNKNOWN_FUNCTION(GXSetTexCoordBias) {
  // clang-format off
  nofralloc;
  lwz r8, gx;
  slwi r6, r3, 2;
  li r0, 1;
  add r7, r8, r6;
  lwz r6, 0x108(r7);
  rlwimi r6, r4, 0x10, 0xf, 0xf;
  slw r0, r0, r3;
  stw r6, 0x108(r7);
  lwz r3, 0x128(r7);
  rlwimi r3, r5, 0x10, 0xf, 0xf;
  stw r3, 0x128(r7);
  lwz r3, 0x5e4(r8);
  and. r0, r3, r0;
  beqlr;
  lis r4, 0xcc01;
  li r5, 0x61;
  stb r5, -0x8000(r4);
  li r0, 0;
  lwz r3, 0x108(r7);
  stw r3, -0x8000(r4);
  stb r5, -0x8000(r4);
  lwz r3, 0x128(r7);
  stw r3, -0x8000(r4);
  sth r0, 2(r8);
  blr;
  // clang-format on
}

// Symbol: __SetSURegs
// PAL: 0x80171260..0x801712f0
MARK_BINARY_BLOB(__SetSURegs, 0x80171260, 0x801712f0);
asm UNKNOWN_FUNCTION(__SetSURegs) {
  // clang-format off
  nofralloc;
  lwz r11, gx;
  slwi r6, r4, 2;
  slwi r0, r3, 2;
  lis r5, 0xcc01;
  add r10, r11, r0;
  add r9, r11, r6;
  lwz r3, 0x564(r10);
  li r4, 0x61;
  lwz r8, 0x108(r9);
  li r0, 0;
  clrlwi r6, r3, 0x16;
  rlwinm r3, r3, 0x16, 0x16, 0x1f;
  rlwimi r8, r6, 0, 0x10, 0x1f;
  stw r8, 0x108(r9);
  lwz r7, 0x128(r9);
  rlwimi r7, r3, 0, 0x10, 0x1f;
  stw r7, 0x128(r9);
  lwz r3, 0x584(r10);
  clrlwi r6, r3, 0x1e;
  rlwinm r3, r3, 0x1e, 0x1e, 0x1f;
  addi r6, r6, -1;
  cntlzw r6, r6;
  addi r3, r3, -1;
  rlwimi r8, r6, 0xb, 0xf, 0xf;
  cntlzw r3, r3;
  stw r8, 0x108(r9);
  rlwimi r7, r3, 0xb, 0xf, 0xf;
  stw r7, 0x128(r9);
  stb r4, -0x8000(r5);
  lwz r3, 0x108(r9);
  stw r3, -0x8000(r5);
  stb r4, -0x8000(r5);
  lwz r3, 0x128(r9);
  stw r3, -0x8000(r5);
  sth r0, 2(r11);
  blr;
  // clang-format on
}

// Symbol: __GXSetSUTexRegs
// PAL: 0x801712f0..0x80171458
MARK_BINARY_BLOB(__GXSetSUTexRegs, 0x801712f0, 0x80171458);
asm UNKNOWN_FUNCTION(__GXSetSUTexRegs) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  addi r11, r1, 0x30;
  bl _savegpr_23;
  lwz r29, gx;
  lwz r0, 0x5e4(r29);
  cmplwi r0, 0xff;
  beq lbl_80171440;
  lwz r0, 0x254(r29);
  li r28, 0;
  li r23, 1;
  rlwinm r3, r0, 0x16, 0x1c, 0x1f;
  rlwinm r27, r0, 0x10, 0x1d, 0x1f;
  addi r26, r3, 1;
  b lbl_801713b4;
lbl_80171330:
  cmpwi r28, 2;
  beq lbl_80171378;
  bge lbl_8017134c;
  cmpwi r28, 0;
  beq lbl_80171358;
  bge lbl_80171368;
  b lbl_80171394;
lbl_8017134c:
  cmpwi r28, 4;
  bge lbl_80171394;
  b lbl_80171388;
lbl_80171358:
  lwz r0, 0x170(r29);
  clrlwi r25, r0, 0x1d;
  rlwinm r24, r0, 0x1d, 0x1d, 0x1f;
  b lbl_80171394;
lbl_80171368:
  lwz r0, 0x170(r29);
  rlwinm r25, r0, 0x1a, 0x1d, 0x1f;
  rlwinm r24, r0, 0x17, 0x1d, 0x1f;
  b lbl_80171394;
lbl_80171378:
  lwz r0, 0x170(r29);
  rlwinm r25, r0, 0x14, 0x1d, 0x1f;
  rlwinm r24, r0, 0x11, 0x1d, 0x1f;
  b lbl_80171394;
lbl_80171388:
  lwz r0, 0x170(r29);
  rlwinm r25, r0, 0xe, 0x1d, 0x1f;
  rlwinm r24, r0, 0xb, 0x1d, 0x1f;
lbl_80171394:
  lwz r3, 0x5e4(r29);
  slw r0, r23, r24;
  and. r0, r3, r0;
  bne lbl_801713b0;
  mr r3, r25;
  mr r4, r24;
  bl __SetSURegs;
lbl_801713b0:
  addi r28, r28, 1;
lbl_801713b4:
  cmplw r28, r27;
  blt lbl_80171330;
  lwz r28, gx;
  li r27, 0;
  li r23, 1;
  mr r31, r28;
  addi r30, r28, 0x150;
  b lbl_80171438;
lbl_801713d4:
  clrlwi. r0, r27, 0x1f;
  lwz r0, 0x5a4(r31);
  rlwinm r3, r27, 1, 0, 0x1d;
  rlwinm r25, r0, 0, 0x18, 0x16;
  beq lbl_801713f4;
  lwzx r0, r30, r3;
  rlwinm r24, r0, 0x11, 0x1d, 0x1f;
  b lbl_801713fc;
lbl_801713f4:
  lwzx r0, r30, r3;
  rlwinm r24, r0, 0x1d, 0x1d, 0x1f;
lbl_801713fc:
  cmplwi r25, 0xff;
  beq lbl_80171430;
  lwz r3, 0x5e4(r29);
  slw r0, r23, r24;
  and. r0, r3, r0;
  bne lbl_80171430;
  lwz r3, 0x5e8(r28);
  slw r0, r23, r27;
  and. r0, r3, r0;
  beq lbl_80171430;
  mr r3, r25;
  mr r4, r24;
  bl __SetSURegs;
lbl_80171430:
  addi r31, r31, 4;
  addi r27, r27, 1;
lbl_80171438:
  cmplw r27, r26;
  blt lbl_801713d4;
lbl_80171440:
  addi r11, r1, 0x30;
  bl _restgpr_23;
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: __GXSetTmemConfig
// PAL: 0x80171458..0x801717ac
MARK_BINARY_BLOB(__GXSetTmemConfig, 0x80171458, 0x801717ac);
asm UNKNOWN_FUNCTION(__GXSetTmemConfig) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  cmpwi r3, 1;
  stw r31, 0xc(r1);
  stw r30, 8(r1);
  beq lbl_80171588;
  bge lbl_80171474;
  b lbl_80171694;
lbl_80171474:
  cmpwi r3, 3;
  bge lbl_80171694;
  lis r3, 0xcc01;
  li r0, 0x61;
  lis r4, 0x8c0e;
  stb r0, -0x8000(r3);
  addi r4, r4, -32768;
  lis r5, 0x900e;
  stw r4, -0x8000(r3);
  lis r4, 0x8d0e;
  lis r31, 0x910e;
  lis r30, 0x8e0e;
  stb r0, -0x8000(r3);
  addi r5, r5, -16384;
  lis r12, 0x920e;
  lis r11, 0x8f0e;
  stw r5, -0x8000(r3);
  lis r10, 0x930e;
  lis r9, 0xac0e;
  lis r8, 0xb00e;
  stb r0, -0x8000(r3);
  addi r4, r4, -30720;
  lis r7, 0xad0e;
  lis r6, 0xb10e;
  stw r4, -0x8000(r3);
  lis r5, 0xae0e;
  lis r4, 0xb20e;
  addi r31, r31, -14336;
  stb r0, -0x8000(r3);
  addi r30, r30, -28672;
  addi r12, r12, -12288;
  addi r11, r11, -26624;
  stw r31, -0x8000(r3);
  addi r10, r10, -10240;
  addi r9, r9, -24576;
  addi r8, r8, -15360;
  stb r0, -0x8000(r3);
  addi r7, r7, -22528;
  addi r6, r6, -13312;
  addi r5, r5, -20480;
  stw r30, -0x8000(r3);
  addi r4, r4, -11264;
  stb r0, -0x8000(r3);
  stw r12, -0x8000(r3);
  stb r0, -0x8000(r3);
  stw r11, -0x8000(r3);
  stb r0, -0x8000(r3);
  stw r10, -0x8000(r3);
  stb r0, -0x8000(r3);
  stw r9, -0x8000(r3);
  stb r0, -0x8000(r3);
  stw r8, -0x8000(r3);
  stb r0, -0x8000(r3);
  stw r7, -0x8000(r3);
  stb r0, -0x8000(r3);
  stw r6, -0x8000(r3);
  stb r0, -0x8000(r3);
  stw r5, -0x8000(r3);
  stb r0, -0x8000(r3);
  stw r4, -0x8000(r3);
  stb r0, -0x8000(r3);
  lis r5, 0xaf0e;
  lis r4, 0xb30e;
  addi r5, r5, -18432;
  stw r5, -0x8000(r3);
  addi r4, r4, -9216;
  stb r0, -0x8000(r3);
  stw r4, -0x8000(r3);
  b lbl_8017179c;
lbl_80171588:
  lis r3, 0xcc01;
  li r0, 0x61;
  lis r4, 0x8c0e;
  stb r0, -0x8000(r3);
  addi r4, r4, -32768;
  lis r5, 0x900e;
  stw r4, -0x8000(r3);
  lis r4, 0x8d0e;
  lis r31, 0x910e;
  lis r30, 0x8e0e;
  stb r0, -0x8000(r3);
  addi r5, r5, -16384;
  lis r12, 0x920e;
  lis r11, 0x8f0e;
  stw r5, -0x8000(r3);
  lis r10, 0x930e;
  lis r9, 0xac0e;
  lis r8, 0xb00e;
  stb r0, -0x8000(r3);
  addi r4, r4, -30720;
  lis r7, 0xad0e;
  lis r6, 0xb10e;
  stw r4, -0x8000(r3);
  lis r5, 0xae0e;
  lis r4, 0xb20e;
  addi r31, r31, -14336;
  stb r0, -0x8000(r3);
  addi r30, r30, -28672;
  addi r12, r12, -12288;
  addi r11, r11, -26624;
  stw r31, -0x8000(r3);
  addi r10, r10, -10240;
  addi r9, r9, -24576;
  addi r8, r8, -8192;
  stb r0, -0x8000(r3);
  addi r7, r7, -22528;
  addi r6, r6, -6144;
  addi r5, r5, -20480;
  stw r30, -0x8000(r3);
  addi r4, r4, -4096;
  stb r0, -0x8000(r3);
  stw r12, -0x8000(r3);
  stb r0, -0x8000(r3);
  stw r11, -0x8000(r3);
  stb r0, -0x8000(r3);
  stw r10, -0x8000(r3);
  stb r0, -0x8000(r3);
  stw r9, -0x8000(r3);
  stb r0, -0x8000(r3);
  stw r8, -0x8000(r3);
  stb r0, -0x8000(r3);
  stw r7, -0x8000(r3);
  stb r0, -0x8000(r3);
  stw r6, -0x8000(r3);
  stb r0, -0x8000(r3);
  stw r5, -0x8000(r3);
  stb r0, -0x8000(r3);
  stw r4, -0x8000(r3);
  stb r0, -0x8000(r3);
  lis r5, 0xaf0e;
  lis r4, 0xb30e;
  addi r5, r5, -18432;
  stw r5, -0x8000(r3);
  addi r4, r4, -2048;
  stb r0, -0x8000(r3);
  stw r4, -0x8000(r3);
  b lbl_8017179c;
lbl_80171694:
  lis r3, 0xcc01;
  li r0, 0x61;
  lis r4, 0x8c0e;
  stb r0, -0x8000(r3);
  addi r4, r4, -32768;
  lis r5, 0x900e;
  stw r4, -0x8000(r3);
  lis r4, 0x8d0e;
  lis r30, 0x910e;
  lis r31, 0x8e0e;
  stb r0, -0x8000(r3);
  addi r5, r5, -16384;
  lis r12, 0x920e;
  lis r11, 0x8f0e;
  stw r5, -0x8000(r3);
  lis r10, 0x930e;
  lis r9, 0xac0e;
  lis r8, 0xb00e;
  stb r0, -0x8000(r3);
  addi r4, r4, -31744;
  lis r7, 0xad0e;
  lis r6, 0xb10e;
  stw r4, -0x8000(r3);
  lis r5, 0xae0e;
  lis r4, 0xb20e;
  addi r30, r30, -15360;
  stb r0, -0x8000(r3);
  addi r31, r31, -30720;
  addi r12, r12, -14336;
  addi r11, r11, -29696;
  stw r30, -0x8000(r3);
  addi r10, r10, -13312;
  addi r9, r9, -28672;
  addi r8, r8, -12288;
  stb r0, -0x8000(r3);
  addi r7, r7, -27648;
  addi r6, r6, -11264;
  addi r5, r5, -26624;
  stw r31, -0x8000(r3);
  addi r4, r4, -10240;
  stb r0, -0x8000(r3);
  stw r12, -0x8000(r3);
  stb r0, -0x8000(r3);
  stw r11, -0x8000(r3);
  stb r0, -0x8000(r3);
  stw r10, -0x8000(r3);
  stb r0, -0x8000(r3);
  stw r9, -0x8000(r3);
  stb r0, -0x8000(r3);
  stw r8, -0x8000(r3);
  stb r0, -0x8000(r3);
  stw r7, -0x8000(r3);
  stb r0, -0x8000(r3);
  stw r6, -0x8000(r3);
  stb r0, -0x8000(r3);
  stw r5, -0x8000(r3);
  stb r0, -0x8000(r3);
  stw r4, -0x8000(r3);
  stb r0, -0x8000(r3);
  lis r5, 0xaf0e;
  lis r4, 0xb30e;
  addi r5, r5, -25600;
  stw r5, -0x8000(r3);
  addi r4, r4, -9216;
  stb r0, -0x8000(r3);
  stw r4, -0x8000(r3);
lbl_8017179c:
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

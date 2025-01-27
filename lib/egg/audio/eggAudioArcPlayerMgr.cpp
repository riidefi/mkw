#include "eggAudioArcPlayerMgr.hpp"

#include <rvl/os/osCache.h>

namespace EGG {

extern "C" {
// Extern function references.
// PAL: 0x80090fc0
extern UNKNOWN_FUNCTION(__ct__Q34nw4r3snd15DvdSoundArchiveFv);
// PAL: 0x80091010
extern UNKNOWN_FUNCTION(__dt__Q34nw4r3snd15DvdSoundArchiveFv);
// PAL: 0x80091090
extern UNKNOWN_FUNCTION(Open__Q34nw4r3snd15DvdSoundArchiveFPCc);
// PAL: 0x800911d0
extern UNKNOWN_FUNCTION(Close__Q34nw4r3snd15DvdSoundArchiveFv);
// PAL: 0x80091390
extern UNKNOWN_FUNCTION(LoadHeader__Q34nw4r3snd15DvdSoundArchiveFPvUl);
// PAL: 0x80091420
extern UNKNOWN_FUNCTION(unk_80091420);
// PAL: 0x80095d80
extern UNKNOWN_FUNCTION(unk_80095d80);
// PAL: 0x80095dd0
extern UNKNOWN_FUNCTION(unk_80095dd0);
// PAL: 0x80095e30
extern UNKNOWN_FUNCTION(unk_80095e30);
// PAL: 0x80095eb0
extern UNKNOWN_FUNCTION(unk_80095eb0);
// PAL: 0x80097570
extern UNKNOWN_FUNCTION(NandSoundArchive_ct);
// PAL: 0x800975c0
extern UNKNOWN_FUNCTION(unk_800975c0);
// PAL: 0x80097650
extern UNKNOWN_FUNCTION(unk_80097650);
// PAL: 0x80097790
extern UNKNOWN_FUNCTION(unk_80097790);
// PAL: 0x80097ab0
extern UNKNOWN_FUNCTION(unk_80097ab0);
// PAL: 0x80097b60
extern UNKNOWN_FUNCTION(unk_80097b60);
// PAL: 0x800a08f0
extern UNKNOWN_FUNCTION(unk_800a08f0);
// PAL: 0x800a0910
extern UNKNOWN_FUNCTION(unk_800a0910);
// PAL: 0x800a0a20
extern UNKNOWN_FUNCTION(unk_800a0a20);
// PAL: 0x800a0b50
extern UNKNOWN_FUNCTION(unk_800a0b50);
// PAL: 0x800a0c90
extern UNKNOWN_FUNCTION(unk_800a0c90);
// PAL: 0x800a1180
extern UNKNOWN_FUNCTION(unk_800a1180);
// PAL: 0x800a1550
extern UNKNOWN_FUNCTION(SoundArchivePlayer_GetSoundPlayer);
// PAL: 0x800a28b0
extern UNKNOWN_FUNCTION(unk_800a28b0);
// PAL: 0x800a2a20
extern UNKNOWN_FUNCTION(unk_800a2a20);
// PAL: 0x800a3020
extern UNKNOWN_FUNCTION(unk_800a3020);
// PAL: 0x800a34d0
extern UNKNOWN_FUNCTION(unk_800a34d0);
// PAL: 0x8015bcf0
extern UNKNOWN_FUNCTION(CNTGetLength);
// PAL: 0x80214e68
extern UNKNOWN_FUNCTION(__ct__Q23EGG7CntFileFv);
// PAL: 0x80214eac
extern UNKNOWN_FUNCTION(__dt__Q23EGG7CntFileFv);
// PAL: 0x80214f14
extern UNKNOWN_FUNCTION(initThreading__Q23EGG7CntFileFv);
// PAL: 0x80214f88
extern UNKNOWN_FUNCTION(spawnFileHandle__Q23EGG7CntFileFPCcPv);
// PAL: 0x80215030
extern UNKNOWN_FUNCTION(close__Q23EGG7CntFileFv);
// PAL: 0x802150a0
extern UNKNOWN_FUNCTION(readData__Q23EGG7CntFileFPvll);
}

// Symbol: __ct__Q23EGG9ArcPlayerFPQ34nw4r3snd9SoundHeap
// PAL: 0x80210590..0x80210624
MARK_BINARY_BLOB(__ct__Q23EGG9ArcPlayerFPQ34nw4r3snd9SoundHeap, 0x80210590,
                 0x80210624);
asm void ArcPlayer::ct(nw4r::snd::SoundHeap* heap) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  lis r6, 0x802a;
  stw r0, 0x24(r1);
  addi r6, r6, 0x2730;
  stw r31, 0x1c(r1);
  li r31, 0;
  stw r30, 0x18(r1);
  mr r30, r5;
  stw r29, 0x14(r1);
  mr r29, r4;
  stw r28, 0x10(r1);
  mr r28, r3;
  stw r6, 0(r3);
  stb r31, 4(r3);
  stb r31, 5(r3);
  stw r31, 8(r3);
  addi r3, r3, 0xc;
  bl __ct__Q34nw4r3snd15DvdSoundArchiveFv;
  addi r3, r28, 0x198;
  bl NandSoundArchive_ct;
  addi r3, r28, 0x374;
  bl unk_80095d80;
  li r0, 1;
  stw r29, 0x4c4(r28);
  mr r3, r28;
  stw r30, 0x4c8(r28);
  stw r31, 0x4cc(r28);
  stw r0, 0x4d0(r28);
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

// Symbol: __dt__Q23EGG9ArcPlayerFv
// PAL: 0x80210624..0x80210698
MARK_BINARY_BLOB(__dt__Q23EGG9ArcPlayerFv, 0x80210624, 0x80210698);
asm ArcPlayer::~ArcPlayer() {
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
  beq lbl_8021067c;
  li r4, -1;
  addi r3, r3, 0x374;
  bl unk_80095dd0;
  addi r3, r30, 0x198;
  li r4, -1;
  bl unk_800975c0;
  addi r3, r30, 0xc;
  li r4, -1;
  bl __dt__Q34nw4r3snd15DvdSoundArchiveFv;
  cmpwi r31, 0;
  ble lbl_8021067c;
  mr r3, r30;
  bl __dl__FPv;
lbl_8021067c:
  mr r3, r30;
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: setSteamBlocks__Q23EGG9ArcPlayerFUl
// PAL: 0x80210698..0x802106b8
MARK_BINARY_BLOB(setSteamBlocks__Q23EGG9ArcPlayerFUl, 0x80210698, 0x802106b8);
asm void ArcPlayer::setSteamBlocks(u32 blocks) {
  // clang-format off
  nofralloc;
  lwz r0, 8(r3);
  cmpwi r0, 0;
  bne lbl_802106b0;
  stw r4, 0x4d0(r3);
  li r3, 1;
  blr;
lbl_802106b0:
  li r3, 0;
  blr;
  // clang-format on
}

extern "C" {

// PAL: 0x802106b8..0x80210748
MARK_BINARY_BLOB(unk_802106b8, 0x802106b8, 0x80210748);
asm UNKNOWN_FUNCTION(unk_802106b8) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmpwi r6, 1;
  mr r8, r5;
  stw r0, 0x14(r1);
  li r0, 0;
  beq lbl_802106e8;
  cmpwi r6, 2;
  beq lbl_80210700;
  cmpwi r6, 3;
  beq lbl_80210718;
  b lbl_80210734;
lbl_802106e8:
  lwz r12, 0(r3);
  lwz r12, 0x10(r12);
  mtctr r12;
  bctrl;
  mr r0, r3;
  b lbl_80210734;
lbl_80210700:
  lwz r12, 0(r3);
  lwz r12, 0x14(r12);
  mtctr r12;
  bctrl;
  mr r0, r3;
  b lbl_80210734;
lbl_80210718:
  lwz r12, 0(r3);
  mr r5, r7;
  mr r6, r8;
  lwz r12, 0x18(r12);
  mtctr r12;
  bctrl;
  mr r0, r3;
lbl_80210734:
  mr r3, r0;
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// PAL: 0x80210748..0x802108bc
MARK_BINARY_BLOB(unk_80210748, 0x80210748, 0x802108bc);
asm UNKNOWN_FUNCTION(unk_80210748) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  cmpwi r5, 0;
  stw r0, 0x24(r1);
  stmw r26, 8(r1);
  mr r26, r3;
  mr r27, r5;
  bne lbl_8021076c;
  lwz r27, 0x4c8(r3);
lbl_8021076c:
  lwz r0, 8(r3);
  cmpwi r0, 0;
  beq lbl_80210780;
  lwz r3, 0x4c4(r3);
  b lbl_802108a8;
lbl_80210780:
  addi r0, r3, 0xc;
  stw r0, 8(r3);
  mr r3, r0;
  bl Open__Q34nw4r3snd15DvdSoundArchiveFPCc;
  cmpwi r3, 0;
  beq lbl_802108a4;
  lwz r30, 0x130(r26);
  li r31, 1;
  stb r31, 4(r26);
  mr r3, r27;
  mr r4, r30;
  li r5, 0;
  li r6, 0;
  bl unk_800a3020;
  stw r3, 0x4d4(r26);
  mr r4, r3;
  mr r5, r30;
  addi r3, r26, 0xc;
  bl LoadHeader__Q34nw4r3snd15DvdSoundArchiveFPvUl;
  cmpwi r3, 0;
  bne lbl_802107e4;
  li r0, 0;
  stb r0, 4(r26);
  li r3, 0;
  b lbl_802108a8;
lbl_802107e4:
  lwz r3, 0x4c4(r26);
  lwz r4, 8(r26);
  bl unk_800a0b50;
  mr r30, r3;
  mr r3, r27;
  mr r4, r30;
  li r5, 0;
  li r6, 0;
  bl unk_800a3020;
  mr r29, r3;
  lwz r3, 0x4c4(r26);
  lwz r4, 8(r26);
  bl unk_800a0c90;
  lwz r0, 0x4d0(r26);
  li r5, 0;
  li r6, 0;
  mullw r28, r0, r3;
  mr r3, r27;
  mr r4, r28;
  bl unk_800a3020;
  mr r7, r3;
  lwz r3, 0x4c4(r26);
  lwz r4, 8(r26);
  mr r5, r29;
  mr r6, r30;
  mr r8, r28;
  bl unk_800a0910;
  cmpwi r3, 0;
  bne lbl_80210868;
  li r0, 0;
  stb r0, 4(r26);
  li r3, 0;
  b lbl_802108a8;
lbl_80210868:
  lwz r30, 0x128(r26);
  mr r3, r27;
  li r5, 0;
  li r6, 0;
  mr r4, r30;
  bl unk_800a3020;
  mr r4, r3;
  mr r5, r30;
  addi r3, r26, 0xc;
  bl unk_80091420;
  li r0, 0;
  stw r31, 0x4cc(r26);
  lwz r3, 0x4c4(r26);
  stb r0, 4(r26);
  b lbl_802108a8;
lbl_802108a4:
  li r3, 0;
lbl_802108a8:
  lmw r26, 8(r1);
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// PAL: 0x802108bc..0x80210a30
MARK_BINARY_BLOB(unk_802108bc, 0x802108bc, 0x80210a30);
asm UNKNOWN_FUNCTION(unk_802108bc) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  cmpwi r5, 0;
  stw r0, 0x24(r1);
  stmw r27, 0xc(r1);
  mr r27, r3;
  mr r28, r5;
  bne lbl_802108e0;
  lwz r28, 0x4c8(r3);
lbl_802108e0:
  lwz r0, 8(r3);
  cmpwi r0, 0;
  beq lbl_802108f4;
  lwz r3, 0x4c4(r3);
  b lbl_80210a1c;
lbl_802108f4:
  addi r0, r3, 0x198;
  stw r0, 8(r3);
  mr r3, r0;
  bl unk_80097650;
  cmpwi r3, 0;
  beq lbl_80210a18;
  lwz r31, 0x2bc(r27);
  li r0, 1;
  stb r0, 4(r27);
  mr r3, r28;
  mr r4, r31;
  li r5, 0;
  li r6, 0;
  bl unk_800a3020;
  mr r4, r3;
  mr r5, r31;
  addi r3, r27, 0x198;
  bl unk_80097ab0;
  cmpwi r3, 0;
  bne lbl_80210954;
  li r0, 0;
  stb r0, 4(r27);
  li r3, 0;
  b lbl_80210a1c;
lbl_80210954:
  lwz r3, 0x4c4(r27);
  addi r4, r27, 0x198;
  bl unk_800a0b50;
  mr r31, r3;
  mr r3, r28;
  mr r4, r31;
  li r5, 0;
  li r6, 0;
  bl unk_800a3020;
  mr r30, r3;
  lwz r3, 0x4c4(r27);
  addi r4, r27, 0x198;
  bl unk_800a0c90;
  lwz r0, 0x4d0(r27);
  li r5, 0;
  li r6, 0;
  mullw r29, r0, r3;
  mr r3, r28;
  mr r4, r29;
  bl unk_800a3020;
  mr r7, r3;
  lwz r3, 0x4c4(r27);
  mr r5, r30;
  mr r6, r31;
  mr r8, r29;
  addi r4, r27, 0x198;
  bl unk_800a0910;
  cmpwi r3, 0;
  bne lbl_802109d8;
  li r0, 0;
  stb r0, 4(r27);
  li r3, 0;
  b lbl_80210a1c;
lbl_802109d8:
  lwz r31, 0x2b4(r27);
  mr r3, r28;
  li r5, 0;
  li r6, 0;
  mr r4, r31;
  bl unk_800a3020;
  mr r4, r3;
  mr r5, r31;
  addi r3, r27, 0x198;
  bl unk_80097b60;
  li r3, 2;
  li r0, 0;
  stw r3, 0x4cc(r27);
  lwz r3, 0x4c4(r27);
  stb r0, 4(r27);
  b lbl_80210a1c;
lbl_80210a18:
  li r3, 0;
lbl_80210a1c:
  lmw r27, 0xc(r1);
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// PAL: 0x80210a30..0x80210bd8
MARK_BINARY_BLOB(unk_80210a30, 0x80210a30, 0x80210bd8);
asm UNKNOWN_FUNCTION(unk_80210a30) {
  // clang-format off
  nofralloc;
  stwu r1, -0xd0(r1);
  mflr r0;
  cmpwi r6, 0;
  stw r0, 0xd4(r1);
  stmw r27, 0xbc(r1);
  mr r27, r3;
  mr r30, r4;
  mr r29, r5;
  mr r28, r6;
  bne lbl_80210a5c;
  lwz r28, 0x4c8(r3);
lbl_80210a5c:
  lwz r0, 8(r3);
  cmpwi r0, 0;
  beq lbl_80210a70;
  lwz r3, 0x4c4(r3);
  b lbl_80210bc4;
lbl_80210a70:
  addi r3, r1, 8;
  bl __ct__Q23EGG7CntFileFv;
  addi r3, r1, 8;
  bl initThreading__Q23EGG7CntFileFv;
  mr r4, r30;
  mr r5, r29;
  addi r3, r1, 8;
  bl spawnFileHandle__Q23EGG7CntFileFPCcPv;
  addi r3, r1, 0x44;
  bl CNTGetLength;
  mr r31, r3;
  mr r3, r28;
  mr r4, r31;
  li r5, 0;
  li r6, 0;
  bl unk_800a3020;
  mr r30, r3;
  mr r5, r31;
  mr r4, r30;
  addi r3, r1, 8;
  li r6, 0;
  bl readData__Q23EGG7CntFileFPvll;
  mr r3, r30;
  mr r4, r31;
  bl DCFlushRange;
  addi r3, r1, 8;
  bl close__Q23EGG7CntFileFv;
  addi r3, r27, 0x374;
  stw r3, 8(r27);
  mr r4, r30;
  bl unk_80095e30;
  cmpwi r3, 0;
  beq lbl_80210bb4;
  li r0, 1;
  stb r0, 4(r27);
  lwz r3, 0x4c4(r27);
  addi r4, r27, 0x374;
  bl unk_800a0b50;
  mr r30, r3;
  mr r3, r28;
  mr r4, r30;
  li r5, 0;
  li r6, 0;
  bl unk_800a3020;
  mr r31, r3;
  lwz r3, 0x4c4(r27);
  addi r4, r27, 0x374;
  bl unk_800a0c90;
  lwz r0, 0x4d0(r27);
  li r5, 0;
  li r6, 0;
  mullw r29, r0, r3;
  mr r3, r28;
  mr r4, r29;
  bl unk_800a3020;
  mr r7, r3;
  lwz r3, 0x4c4(r27);
  mr r5, r31;
  mr r6, r30;
  mr r8, r29;
  addi r4, r27, 0x374;
  bl unk_800a0910;
  cmpwi r3, 0;
  bne lbl_80210b8c;
  li r0, 0;
  stb r0, 4(r27);
  addi r3, r1, 8;
  li r4, -1;
  bl __dt__Q23EGG7CntFileFv;
  li r3, 0;
  b lbl_80210bc4;
lbl_80210b8c:
  li r3, 3;
  li r0, 0;
  stw r3, 0x4cc(r27);
  addi r3, r1, 8;
  lwz r31, 0x4c4(r27);
  li r4, -1;
  stb r0, 4(r27);
  bl __dt__Q23EGG7CntFileFv;
  mr r3, r31;
  b lbl_80210bc4;
lbl_80210bb4:
  addi r3, r1, 8;
  li r4, -1;
  bl __dt__Q23EGG7CntFileFv;
  li r3, 0;
lbl_80210bc4:
  lmw r27, 0xbc(r1);
  lwz r0, 0xd4(r1);
  mtlr r0;
  addi r1, r1, 0xd0;
  blr;
  // clang-format on
}

// PAL: 0x80210bd8..0x80210ce4
MARK_BINARY_BLOB(unk_80210bd8, 0x80210bd8, 0x80210ce4);
asm UNKNOWN_FUNCTION(unk_80210bd8) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  cmpwi r5, 0;
  stw r0, 0x24(r1);
  stmw r27, 0xc(r1);
  mr r27, r3;
  mr r28, r5;
  bne lbl_80210bfc;
  lwz r28, 0x4c8(r3);
lbl_80210bfc:
  lwz r0, 8(r3);
  cmpwi r0, 0;
  beq lbl_80210c10;
  lwz r3, 0x4c4(r3);
  b lbl_80210cd0;
lbl_80210c10:
  addi r0, r3, 0x374;
  stw r0, 8(r3);
  mr r3, r0;
  bl unk_80095e30;
  cmpwi r3, 0;
  beq lbl_80210ccc;
  li r0, 1;
  stb r0, 4(r27);
  lwz r3, 0x4c4(r27);
  addi r4, r27, 0x374;
  bl unk_800a0b50;
  mr r31, r3;
  mr r3, r28;
  mr r4, r31;
  li r5, 0;
  li r6, 0;
  bl unk_800a3020;
  mr r30, r3;
  lwz r3, 0x4c4(r27);
  addi r4, r27, 0x374;
  bl unk_800a0c90;
  lwz r0, 0x4d0(r27);
  li r5, 0;
  li r6, 0;
  mullw r29, r0, r3;
  mr r3, r28;
  mr r4, r29;
  bl unk_800a3020;
  mr r7, r3;
  lwz r3, 0x4c4(r27);
  mr r5, r30;
  mr r6, r31;
  mr r8, r29;
  addi r4, r27, 0x374;
  bl unk_800a0910;
  cmpwi r3, 0;
  bne lbl_80210cb4;
  li r0, 0;
  stb r0, 4(r27);
  li r3, 0;
  b lbl_80210cd0;
lbl_80210cb4:
  li r3, 4;
  li r0, 0;
  stw r3, 0x4cc(r27);
  lwz r3, 0x4c4(r27);
  stb r0, 4(r27);
  b lbl_80210cd0;
lbl_80210ccc:
  li r3, 0;
lbl_80210cd0:
  lmw r27, 0xc(r1);
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// PAL: 0x80210ce4..0x80210a30
MARK_BINARY_BLOB(unk_80210ce4, 0x80210ce4, 0x80210d70);
asm UNKNOWN_FUNCTION(unk_80210ce4) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  lwz r0, 8(r3);
  cmpwi r0, 0;
  beq lbl_80210d5c;
  lwz r4, 0x4cc(r3);
  addi r0, r4, -3;
  cmplwi r0, 1;
  ble lbl_80210d40;
  cmpwi r4, 1;
  beq lbl_80210d28;
  cmpwi r4, 2;
  beq lbl_80210d34;
  b lbl_80210d48;
lbl_80210d28:
  addi r3, r3, 0xc;
  bl Close__Q34nw4r3snd15DvdSoundArchiveFv;
  b lbl_80210d48;
lbl_80210d34:
  addi r3, r3, 0x198;
  bl unk_80097790;
  b lbl_80210d48;
lbl_80210d40:
  addi r3, r3, 0x374;
  bl unk_80095eb0;
lbl_80210d48:
  lwz r3, 0x4c4(r31);
  bl unk_800a0a20;
  li r0, 0;
  stw r0, 0x4cc(r31);
  stw r0, 8(r31);
lbl_80210d5c:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// PAL: 0x80210d70..0x80210e3c
MARK_BINARY_BLOB(unk_80210d70, 0x80210d70, 0x80210e3c);
asm UNKNOWN_FUNCTION(unk_80210d70) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r6;
  stw r30, 0x18(r1);
  mr r30, r5;
  stw r29, 0x14(r1);
  mr r29, r4;
  stw r28, 0x10(r1);
  mr r28, r3;
  lwz r7, 0x4cc(r3);
  addi r0, r7, -2;
  cmplwi r0, 1;
  bgt lbl_80210db4;
  li r3, 1;
  b lbl_80210e1c;
lbl_80210db4:
  cmpwi r5, 0;
  bne lbl_80210dc0;
  lwz r30, 0x4c8(r3);
lbl_80210dc0:
  lbz r0, 4(r3);
  cmpwi r0, 0;
  beq lbl_80210dd4;
  li r3, 0;
  b lbl_80210e1c;
lbl_80210dd4:
  lwz r3, 0x4c4(r3);
  bl unk_800a08f0;
  cmpwi r3, 0;
  bne lbl_80210dec;
  li r3, 0;
  b lbl_80210e1c;
lbl_80210dec:
  li r0, 1;
  stb r0, 5(r28);
  lwz r3, 0x4c4(r28);
  mr r4, r29;
  mr r5, r30;
  mr r6, r31;
  bl unk_800a28b0;
  neg r0, r3;
  li r4, 0;
  or r0, r0, r3;
  stb r4, 5(r28);
  srwi r3, r0, 0x1f;
lbl_80210e1c:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  lwz r28, 0x10(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// PAL: 0x80210e3c..0x80210f08
MARK_BINARY_BLOB(unk_80210e3c, 0x80210e3c, 0x80210f08);
asm UNKNOWN_FUNCTION(unk_80210e3c) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r6;
  stw r30, 0x18(r1);
  mr r30, r5;
  stw r29, 0x14(r1);
  mr r29, r4;
  stw r28, 0x10(r1);
  mr r28, r3;
  lwz r7, 0x4cc(r3);
  addi r0, r7, -2;
  cmplwi r0, 1;
  bgt lbl_80210e80;
  li r3, 1;
  b lbl_80210ee8;
lbl_80210e80:
  cmpwi r5, 0;
  bne lbl_80210e8c;
  lwz r30, 0x4c8(r3);
lbl_80210e8c:
  lbz r0, 4(r3);
  cmpwi r0, 0;
  beq lbl_80210ea0;
  li r3, 0;
  b lbl_80210ee8;
lbl_80210ea0:
  lwz r3, 0x4c4(r3);
  bl unk_800a08f0;
  cmpwi r3, 0;
  bne lbl_80210eb8;
  li r3, 0;
  b lbl_80210ee8;
lbl_80210eb8:
  li r0, 1;
  stb r0, 5(r28);
  lwz r3, 0x4c4(r28);
  mr r4, r29;
  mr r5, r30;
  mr r6, r31;
  bl unk_800a28b0;
  neg r0, r3;
  li r4, 0;
  or r0, r0, r3;
  stb r4, 5(r28);
  srwi r3, r0, 0x1f;
lbl_80210ee8:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  lwz r28, 0x10(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// PAL: 0x80210f08..0x80210fd4
MARK_BINARY_BLOB(unk_80210f08, 0x80210f08, 0x80210fd4);
asm UNKNOWN_FUNCTION(unk_80210f08) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r6;
  stw r30, 0x18(r1);
  mr r30, r5;
  stw r29, 0x14(r1);
  mr r29, r4;
  stw r28, 0x10(r1);
  mr r28, r3;
  lwz r7, 0x4cc(r3);
  addi r0, r7, -2;
  cmplwi r0, 1;
  bgt lbl_80210f4c;
  li r3, 1;
  b lbl_80210fb4;
lbl_80210f4c:
  cmpwi r5, 0;
  bne lbl_80210f58;
  lwz r30, 0x4c8(r3);
lbl_80210f58:
  lbz r0, 4(r3);
  cmpwi r0, 0;
  beq lbl_80210f6c;
  li r3, 0;
  b lbl_80210fb4;
lbl_80210f6c:
  lwz r3, 0x4c4(r3);
  bl unk_800a08f0;
  cmpwi r3, 0;
  bne lbl_80210f84;
  li r3, 0;
  b lbl_80210fb4;
lbl_80210f84:
  li r0, 1;
  stb r0, 5(r28);
  lwz r3, 0x4c4(r28);
  mr r4, r29;
  mr r5, r30;
  mr r6, r31;
  bl unk_800a2a20;
  neg r4, r3;
  li r0, 0;
  or r3, r4, r3;
  stb r0, 5(r28);
  srwi r3, r3, 0x1f;
lbl_80210fb4:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  lwz r28, 0x10(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}
}

// Symbol: calc__Q23EGG9ArcPlayerFv
// PAL: 0x80210fd4..0x80210fec
MARK_BINARY_BLOB(calc__Q23EGG9ArcPlayerFv, 0x80210fd4, 0x80210fec);
asm void ArcPlayer::calc() {
  // clang-format off
  nofralloc;
  lbz r0, 4(r3);
  cmpwi r0, 0;
  bnelr;
  lwz r3, 0x4c4(r3);
  b unk_800a1180;
  blr;
  // clang-format on
}

// Symbol: stopAllSound__Q23EGG9ArcPlayerFv
// PAL: 0x80210fec..0x80211048
MARK_BINARY_BLOB(stopAllSound__Q23EGG9ArcPlayerFv, 0x80210fec, 0x80211048);
asm void ArcPlayer::stopAllSound() {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  li r31, 0;
  stw r30, 8(r1);
  mr r30, r3;
  b lbl_80211020;
lbl_8021100c:
  mr r4, r31;
  bl SoundArchivePlayer_GetSoundPlayer;
  li r4, 0;
  bl unk_800a34d0;
  addi r31, r31, 1;
lbl_80211020:
  lwz r3, 0x4c4(r30);
  lwz r0, 0x30(r3);
  cmplw r31, r0;
  blt lbl_8021100c;
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

extern "C" {

// PAL: 0x80211048..0x80211058
MARK_BINARY_BLOB(unk_80211048, 0x80211048, 0x80211058);
asm UNKNOWN_FUNCTION(unk_80211048) {
  // clang-format off
  nofralloc;
  lwz r12, 0(r3);
  lwz r12, 0x1c(r12);
  mtctr r12;
  bctr;
  // clang-format on
}
}

} // namespace EGG

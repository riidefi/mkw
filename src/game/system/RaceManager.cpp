#include "RaceManager.hpp"

// --- EXTERN DECLARATIONS BEGIN ---

extern "C" {

// Extern function references.
// PAL: 0x80020e34
extern UNKNOWN_FUNCTION(__construct_new_array);
// PAL: 0x80020ff4
extern UNKNOWN_FUNCTION(__construct_array);
// PAL: 0x80021478
// extern UNKNOWN_FUNCTION(__cvt_fp2unsigned);
// PAL: 0x80021580
extern UNKNOWN_FUNCTION(_savegpr_19);
// PAL: 0x80021588
extern UNKNOWN_FUNCTION(_savegpr_21);
// PAL: 0x8002158c
extern UNKNOWN_FUNCTION(_savegpr_22);
// PAL: 0x80021594
extern UNKNOWN_FUNCTION(_savegpr_24);
// PAL: 0x80021598
extern UNKNOWN_FUNCTION(_savegpr_25);
// PAL: 0x800215a0
extern UNKNOWN_FUNCTION(_savegpr_27);
// PAL: 0x800215cc
extern UNKNOWN_FUNCTION(_restgpr_19);
// PAL: 0x800215d4
extern UNKNOWN_FUNCTION(_restgpr_21);
// PAL: 0x800215d8
extern UNKNOWN_FUNCTION(_restgpr_22);
// PAL: 0x800215e0
extern UNKNOWN_FUNCTION(_restgpr_24);
// PAL: 0x800215e4
extern UNKNOWN_FUNCTION(_restgpr_25);
// PAL: 0x800215ec
extern UNKNOWN_FUNCTION(_restgpr_27);
// PAL: 0x80021828
extern UNKNOWN_FUNCTION(__mod2u);
// PAL: 0x80021a60
extern UNKNOWN_FUNCTION(__cvt_ull_flt);
// PAL: 0x80021b00
extern UNKNOWN_FUNCTION(__cvt_dbl_ull);
// PAL: 0x800850b0
extern UNKNOWN_FUNCTION(unk_800850b0);
// PAL: 0x80229dcc
extern UNKNOWN_FUNCTION(__nw__FUl);
// PAL: 0x80229df0
extern UNKNOWN_FUNCTION(__nwa__FUl);
// PAL: 0x80229ee0
extern UNKNOWN_FUNCTION(__dla__FPv);
// PAL: 0x8022f80c
extern UNKNOWN_FUNCTION(sqrt__Q23EGG5MathfFf);
// PAL: 0x80243a00
extern UNKNOWN_FUNCTION(normalise__Q23EGG8Vector2fFv);
// PAL: 0x80243b6c
extern UNKNOWN_FUNCTION(normalise2__Q23EGG8Vector3fFv);
// PAL: 0x80511500
extern UNKNOWN_FUNCTION(KmpHolder_findNextCheckpoint);
// PAL: 0x80511e7c
extern UNKNOWN_FUNCTION(computeExactFinishingTime);
// PAL: 0x805147d4
extern UNKNOWN_FUNCTION(VEC3_fromNeg);
// PAL: 0x80514810
extern UNKNOWN_FUNCTION(Vec3_scale);
// PAL: 0x80514838
extern UNKNOWN_FUNCTION(Vec3_add);
// PAL: 0x8051486c
extern UNKNOWN_FUNCTION(VEC3_sub);
// PAL: 0x80514b24
extern UNKNOWN_FUNCTION(unk_80514b24);
// PAL: 0x80514b30
extern UNKNOWN_FUNCTION(getStartPoint__Q26System9CourseMapCFUs);
// PAL: 0x80514bc8
extern UNKNOWN_FUNCTION(getEnemyPath__Q26System9CourseMapCFUs);
// PAL: 0x80515014
extern UNKNOWN_FUNCTION(CheckpathHolder_findCheckpathForCheckpoint);
// PAL: 0x80515c24
extern UNKNOWN_FUNCTION(getCheckPoint__Q26System9CourseMapCFUs);
// PAL: 0x80518920
extern UNKNOWN_FUNCTION(getJugemPoint__Q26System9CourseMapCFUs);
// PAL: 0x80518b78
extern UNKNOWN_FUNCTION(getStage__Q26System9CourseMapCFv);
// PAL: 0x8051c334
extern UNKNOWN_FUNCTION(__dt__Q26System4TimeFv);
// PAL: 0x8051c374
extern UNKNOWN_FUNCTION(__ct__Q26System4TimeFv);
// PAL: 0x805235ac
extern UNKNOWN_FUNCTION(resetPlayersActivityStatus__Q26System12KPadDirectorFv);
// PAL: 0x80524568
extern UNKNOWN_FUNCTION(lockGhostProxies__Q26System12KPadDirectorFv);
// PAL: 0x80524580
extern UNKNOWN_FUNCTION(startGhostProxies__Q26System12KPadDirectorFv);
// PAL: 0x805245cc
extern UNKNOWN_FUNCTION(endGhostProxy__Q26System12KPadDirectorFUc);
// PAL: 0x805275ec
extern UNKNOWN_FUNCTION(isMii);
// PAL: 0x8052cb6c
extern UNKNOWN_FUNCTION(unk_8052cb6c);
// PAL: 0x8052cca4
extern UNKNOWN_FUNCTION(unk_8052cca4);
// PAL: 0x8052d46c
extern UNKNOWN_FUNCTION(unk_8052d46c);
// PAL: 0x8052d888
extern UNKNOWN_FUNCTION(unk_8052d888);
// PAL: 0x80531f70
extern UNKNOWN_FUNCTION(getHudPlayerId__Q26System10RaceConfigFUc);
// PAL: 0x80531f80
extern UNKNOWN_FUNCTION(loadNextCourse__Q26System10RaceConfigFv);
// PAL: 0x80532188
extern UNKNOWN_FUNCTION(Raceinfo_initGamemode);
// PAL: 0x805321cc
extern UNKNOWN_FUNCTION(jump_805321cc);
// PAL: 0x80532220
extern UNKNOWN_FUNCTION(jump_80532220);
// PAL: 0x80532248
extern UNKNOWN_FUNCTION(jump_80532248);
// PAL: 0x80532254
extern UNKNOWN_FUNCTION(jump_80532254);
// PAL: 0x805322c8
extern UNKNOWN_FUNCTION(jump_805322c8);
// PAL: 0x805323e0
extern UNKNOWN_FUNCTION(jump_805323e0);
// PAL: 0x80532444
extern UNKNOWN_FUNCTION(jump_80532444);
// PAL: 0x80532488
extern UNKNOWN_FUNCTION(unk_80532488);
// PAL: 0x805324ac
extern UNKNOWN_FUNCTION(unk_805324ac);
// PAL: 0x805324ec
extern UNKNOWN_FUNCTION(unk_805324ec);
// PAL: 0x8053252c
extern UNKNOWN_FUNCTION(unk_8053252c);
// PAL: 0x8053256c
extern UNKNOWN_FUNCTION(unk_8053256c);
// PAL: 0x805325ac
extern UNKNOWN_FUNCTION(unk_805325ac);
// PAL: 0x805325ec
extern UNKNOWN_FUNCTION(unk_805325ec);
// PAL: 0x8053262c
extern UNKNOWN_FUNCTION(unk_8053262c);
// PAL: 0x8053266c
extern UNKNOWN_FUNCTION(unk_8053266c);
// PAL: 0x805326ac
extern UNKNOWN_FUNCTION(unk_805326ac);
// PAL: 0x805327a0
extern UNKNOWN_FUNCTION(Raceinfo_construct);
// PAL: 0x80532d44
extern UNKNOWN_FUNCTION(unk_80532d44);
// PAL: 0x80532de0
extern UNKNOWN_FUNCTION(unk_80532de0);
// PAL: 0x80532e3c
extern UNKNOWN_FUNCTION(unk_80532e3c);
// PAL: 0x80532f48
extern UNKNOWN_FUNCTION(RaceinfoPlayer_destroy);
// PAL: 0x8053308c
extern UNKNOWN_FUNCTION(unk_8053308c);
// PAL: 0x805336a0
extern UNKNOWN_FUNCTION(unk_805336a0);
// PAL: 0x805336d8
extern UNKNOWN_FUNCTION(unk_805336d8);
// PAL: 0x80533be8
extern UNKNOWN_FUNCTION(unk_80533be8);
// PAL: 0x80533c34
extern UNKNOWN_FUNCTION(unk_80533c34);
// PAL: 0x80533c6c
extern UNKNOWN_FUNCTION(unk_80533c6c);
// PAL: 0x80533ed8
extern UNKNOWN_FUNCTION(RaceinfoPlayer_construct);
// PAL: 0x80534194
extern UNKNOWN_FUNCTION(RaceinfoPlayer_init);
// PAL: 0x805342e8
extern UNKNOWN_FUNCTION(unk_805342e8);
// PAL: 0x80534684
extern UNKNOWN_FUNCTION(unk_80534684);
// PAL: 0x805347f4
extern UNKNOWN_FUNCTION(RaceinfoPlayer_endRace);
// PAL: 0x805349b8
extern UNKNOWN_FUNCTION(RaceinfoPlayer_endLap);
// PAL: 0x80534df8
extern UNKNOWN_FUNCTION(RaceinfoPlayer_updateCheckpoint);
// PAL: 0x80535304
extern UNKNOWN_FUNCTION(RaceinfoPlayer_update);
// PAL: 0x80535864
extern UNKNOWN_FUNCTION(unk_80535864);
// PAL: 0x80535904
extern UNKNOWN_FUNCTION(unk_80535904);
// PAL: 0x80535d14
extern UNKNOWN_FUNCTION(TimeAttackGamemode_canEndRace);
// PAL: 0x80535de8
extern UNKNOWN_FUNCTION(unk_80535de8);
// PAL: 0x80535e84
extern UNKNOWN_FUNCTION(unk_80535e84);
// PAL: 0x80535ef4
extern UNKNOWN_FUNCTION(unk_80535ef4);
// PAL: 0x80535f28
extern UNKNOWN_FUNCTION(unk_80535f28);
// PAL: 0x80535fe4
extern UNKNOWN_FUNCTION(unk_80535fe4);
// PAL: 0x80536054
extern UNKNOWN_FUNCTION(unk_80536054);
// PAL: 0x80536328
extern UNKNOWN_FUNCTION(jump_80536328);
// PAL: 0x80536450
extern UNKNOWN_FUNCTION(jump_80536450);
// PAL: 0x80536484
extern UNKNOWN_FUNCTION(jump_80536484);
// PAL: 0x80536494
extern UNKNOWN_FUNCTION(jump_80536494);
// PAL: 0x805364a4
extern UNKNOWN_FUNCTION(jump_805364a4);
// PAL: 0x80536540
extern UNKNOWN_FUNCTION(jump_80536540);
// PAL: 0x805365c8
extern UNKNOWN_FUNCTION(unk_805365c8);
// PAL: 0x80536618
extern UNKNOWN_FUNCTION(jump_80536618);
// PAL: 0x80536738
extern UNKNOWN_FUNCTION(jump_80536738);
// PAL: 0x805367b8
extern UNKNOWN_FUNCTION(jump_805367b8);
// PAL: 0x805367e4
extern UNKNOWN_FUNCTION(jump_805367e4);
// PAL: 0x805367ec
extern UNKNOWN_FUNCTION(jump_805367ec);
// PAL: 0x805367f4
extern UNKNOWN_FUNCTION(jump_805367f4);
// PAL: 0x805371a4
extern UNKNOWN_FUNCTION(unk_805371a4);
// PAL: 0x805371a8
extern UNKNOWN_FUNCTION(unk_805371a8);
// PAL: 0x805371e8
extern UNKNOWN_FUNCTION(unk_805371e8);
// PAL: 0x8053724c
extern UNKNOWN_FUNCTION(unk_8053724c);
// PAL: 0x805372b4
extern UNKNOWN_FUNCTION(unk_805372b4);
// PAL: 0x805372bc
extern UNKNOWN_FUNCTION(unk_805372bc);
// PAL: 0x80537320
extern UNKNOWN_FUNCTION(unk_80537320);
// PAL: 0x80537388
extern UNKNOWN_FUNCTION(unk_80537388);
// PAL: 0x80537390
extern UNKNOWN_FUNCTION(unk_80537390);
// PAL: 0x805373f4
extern UNKNOWN_FUNCTION(unk_805373f4);
// PAL: 0x8053745c
extern UNKNOWN_FUNCTION(unk_8053745c);
// PAL: 0x80537464
extern UNKNOWN_FUNCTION(unk_80537464);
// PAL: 0x805374c8
extern UNKNOWN_FUNCTION(unk_805374c8);
// PAL: 0x80537530
extern UNKNOWN_FUNCTION(unk_80537530);
// PAL: 0x80537538
extern UNKNOWN_FUNCTION(unk_80537538);
// PAL: 0x8053759c
extern UNKNOWN_FUNCTION(unk_8053759c);
// PAL: 0x80537604
extern UNKNOWN_FUNCTION(unk_80537604);
// PAL: 0x8053760c
extern UNKNOWN_FUNCTION(unk_8053760c);
// PAL: 0x80537670
extern UNKNOWN_FUNCTION(unk_80537670);
// PAL: 0x805376d8
extern UNKNOWN_FUNCTION(unk_805376d8);
// PAL: 0x805376e0
extern UNKNOWN_FUNCTION(unk_805376e0);
// PAL: 0x80537830
extern UNKNOWN_FUNCTION(VEC3_fromCross);
// PAL: 0x80537b80
extern UNKNOWN_FUNCTION(unk_80537b80);
// PAL: 0x80537cd4
extern UNKNOWN_FUNCTION(unk_80537cd4);
// PAL: 0x8053831c
extern UNKNOWN_FUNCTION(unk_8053831c);
// PAL: 0x80538344
extern UNKNOWN_FUNCTION(unk_80538344);
// PAL: 0x80539f88
extern UNKNOWN_FUNCTION(unk_80539f88);
// PAL: 0x8053d97c
extern UNKNOWN_FUNCTION(unk_8053d97c);
// PAL: 0x805411fc
extern UNKNOWN_FUNCTION(getFile__Q26System15ResourceManagerFlPCcPUl);
// PAL: 0x805506ec
extern UNKNOWN_FUNCTION(unk_805506ec);
// PAL: 0x8055070c
extern UNKNOWN_FUNCTION(unk_8055070c);
// PAL: 0x80555464
extern UNKNOWN_FUNCTION(__ct__Q24Util6RandomFv);
// PAL: 0x80555514
extern UNKNOWN_FUNCTION(__ct__Q24Util6RandomFUl);
// PAL: 0x80555538
extern UNKNOWN_FUNCTION(__dt__Q24Util6RandomFv);
// PAL: 0x805555cc
extern UNKNOWN_FUNCTION(nextU32__Q24Util6RandomFUl);
// PAL: 0x805813a4
extern UNKNOWN_FUNCTION(unk_805813a4);
// PAL: 0x80590100
extern UNKNOWN_FUNCTION(PlayerHolder_getPlayer);
// PAL: 0x80590110
extern UNKNOWN_FUNCTION(unk_80590110);
// PAL: 0x8059020c
extern UNKNOWN_FUNCTION(getPos__Q24Kart15KartObjectProxyCFv);
// PAL: 0x80590224
extern UNKNOWN_FUNCTION(PlayerPointers_getPlayerPhysicsHolderPosition);
// PAL: 0x8059077c
extern UNKNOWN_FUNCTION(kartMove__Q24Kart15KartObjectProxyFv);
// PAL: 0x80590c94
extern UNKNOWN_FUNCTION(PlayerPointers_getBodyFront);
// PAL: 0x805a8fbc
extern UNKNOWN_FUNCTION(unk_805a8fbc);
// PAL: 0x80635a3c
extern UNKNOWN_FUNCTION(SectionManager_setNextSection);
// PAL: 0x80635b2c
extern UNKNOWN_FUNCTION(SectionManager_startReinit);
// PAL: 0x806545dc
extern UNKNOWN_FUNCTION(unk_806545dc);
// PAL: 0x8078f140
extern UNKNOWN_FUNCTION(checkSpherePartial__Q25Field11CourseModelFRCQ23EGG8Vector3fRCQ23EGG8Vector3fUlPQ25Field14ColInfoPartialPUlfUl);
// PAL: 0x8082b3d4
extern UNKNOWN_FUNCTION(unk_8082b3d4);
// PAL: 0x8082b420
extern UNKNOWN_FUNCTION(unk_8082b420);
// PAL: 0x80860124
extern UNKNOWN_FUNCTION(unk_80860124); // Extern data references.
// PAL: 0x80385fc8
extern UNKNOWN_DATA(spInstance__Q26System8RKSystem);
// PAL: 0x80386000
extern UNKNOWN_DATA(sInstance__Q26System13SystemManager);
// PAL: 0x80890218
extern UNKNOWN_DATA(lbl_80890218);
// PAL: 0x8089021c
extern UNKNOWN_DATA(lbl_8089021c);
// PAL: 0x80890220
extern UNKNOWN_DATA(lbl_80890220);
// PAL: 0x80890238
extern UNKNOWN_DATA(lbl_80890238);
// PAL: 0x808b2d44
extern UNKNOWN_DATA(__vt__Q26System4Time);
// PAL: 0x808b3524
extern UNKNOWN_DATA(lbl_808b3524);
// PAL: 0x808b3698
extern UNKNOWN_DATA(lbl_808b3698);
// PAL: 0x808b36e4
extern UNKNOWN_DATA(lbl_808b36e4);
// PAL: 0x808b3928
extern UNKNOWN_DATA(lbl_808b3928);
// PAL: 0x809bd6e8
extern UNKNOWN_DATA(spInstance__Q26System9CourseMap);
// PAL: 0x809bd70c
extern UNKNOWN_DATA(spInstance__Q26System12KPadDirector);
// PAL: 0x809bd728
extern UNKNOWN_DATA(spInstance__Q26System10RaceConfig);
// PAL: 0x809bd738
extern UNKNOWN_DATA(spInstance__Q26System15ResourceManager);
// PAL: 0x809c18f8
extern UNKNOWN_DATA(lbl_809c18f8);
// PAL: 0x809c19b8
extern UNKNOWN_DATA(lbl_809c19b8);
// PAL: 0x809c1e38
extern UNKNOWN_DATA(lbl_809c1e38);
// PAL: 0x809c1f50
extern UNKNOWN_DATA(lbl_809c1f50);
// PAL: 0x809c2f44
extern UNKNOWN_DATA(spInstance__Q25Field11CourseModel);
// PAL: 0x809c3c04
extern UNKNOWN_DATA(VEC_INFINITY);
// PAL: 0x809c4330
extern UNKNOWN_DATA(lbl_809c4330);
}

// --- EXTERN DECLARATIONS END ---

// .rodata
extern const f32 unused_80890148;
const f32 unused_80890148 = 5 / 3.0 * 1e-5;
extern const f32 unused_8089014c;
const f32 unused_8089014c = 0.001f;
const u32 lbl_80890150[] = {0x00000000};
const u32 lbl_80890154[] = {0xbf800000};
const u32 lbl_80890158[] = {0x3f8ccccd, 0x00000000};
const u32 lbl_80890160[] = {0x3f847ae1, 0x40000000};
const u32 lbl_80890168[] = {0x4156e378, 0xc0000000};
const u32 lbl_80890170[] = {0x43300000, 0x00000000};
const u32 lbl_80890178[] = {0x3f7fffef};
const u32 lbl_8089017c[] = {0x3f800000};
const u32 lbl_80890180[] = {0x42c80000};
const u32 lbl_80890184[] = {0x41880000};
const u32 lbl_80890188[] = {0x378bcf65};
const u32 lbl_8089018c[] = {0x3a83126f};
const u32 lbl_80890190[] = {0xbf19999a};
const u32 lbl_80890194[] = {0x3f19999a};
const u32 lbl_80890198[] = {0x3f733333};
const u32 lbl_8089019c[] = {0xbf733333};
const u32 lbl_808901a0[] = {0x43300000, 0x80000000};
const u32 lbl_808901a8[] = {0x3f7fff58};
const u32 lbl_808901ac[] = {0xbf000000};
const u32 lbl_808901b0[] = {0x3089705f};
const u32 lbl_808901b4[] = {0x476a6000};
const u32 lbl_808901b8[] = {0x447a0000};
const u32 lbl_808901bc[] = {0x3f000000};
const u32 lbl_808901c0[] = {0x3727c5ac};
const u32 lbl_808901c4[] = {0x4e6e6b28, 0x3727c5ac, 0x00060000,
                            0x3f7fff58, 0x00000000, 0x40590000,
                            0x00000000, 0x3f847ae1, 0x40000000};
const u32 lbl_808901e8[] = {0x2f72616e, 0x6b74696d, 0x6547502e, 0x6b727400,
                            0x2f72616e, 0x6b74696d, 0x6547502e, 0x6b727400,
                            0x2f6d696e, 0x6967616d, 0x652e6b6d, 0x67000000};

// .data
#pragma explicit_zero_data on
u32 lbl_808b32b0[] = {0x00000000, 0x00000000, 0x00000000};
void (*jtbl_808b32bc[])() = {
    jump_805321cc, jump_80532220, jump_80532444, jump_80532254,
    jump_80532248, jump_80532444, jump_80532444, jump_805322c8,
    jump_805322c8, jump_805323e0, jump_805323e0,
};

void (*jtbl_808b32e8[])() = {
    jump_80536540, jump_80536540, jump_80536494, jump_80536328, jump_805364a4,
    jump_80536494, jump_80536540, jump_80536540, jump_80536540, jump_80536328,
    jump_80536328, jump_80536450, jump_80536484,
};

void (*jtbl_808b331c[])() = {
    jump_805367f4, jump_805367f4, jump_805367ec, jump_80536618, jump_80536738,
    jump_805367ec, jump_805367f4, jump_805367f4, jump_805367f4, jump_80536618,
    jump_80536618, jump_805367b8, jump_805367e4,
};

u32 lbl_808b3350[] = {0x00000000, 0x00000000, (u32)&unk_80532e3c, 0x00000000};
u32 lbl_808b3360[] = {0x00000000,         0x00000000,
                      (u32)&unk_8053266c, (u32)&unk_805371e8,
                      (u32)&unk_8053724c, (u32)&unk_805372b4};
u32 lbl_808b3378[] = {0x00000000,         0x00000000,
                      (u32)&unk_8053262c, (u32)&unk_805372bc,
                      (u32)&unk_80537320, (u32)&unk_80537388};
u32 lbl_808b3390[] = {0x00000000,         0x00000000,
                      (u32)&unk_805325ac, (u32)&unk_80537390,
                      (u32)&unk_805373f4, (u32)&unk_8053745c};
u32 lbl_808b33a8[] = {0x00000000,         0x00000000,
                      (u32)&unk_8053256c, (u32)&unk_80537464,
                      (u32)&unk_805374c8, (u32)&unk_80537530};
u32 lbl_808b33c0[] = {0x00000000,         0x00000000,
                      (u32)&unk_8053252c, (u32)&unk_80537538,
                      (u32)&unk_8053759c, (u32)&unk_80537604};
u32 lbl_808b33d8[] = {0x00000000, 0x00000000, (u32)&unk_805325ec,
                      0x00000000, 0x00000000, 0x00000000};
u32 lbl_808b33f0[] = {0x00000000,         0x00000000,
                      (u32)&unk_805326ac, (u32)&unk_8053760c,
                      (u32)&unk_80537670, (u32)&unk_805376d8};
u32 lbl_808b3408[] = {0x00000000, 0x00000000, (u32)&unk_805324ec,
                      0x00000000, 0x00000000, 0x00000000};
u32 lbl_808b3420[] = {
    0x00000000,         0x00000000,         (u32)&unk_80536054,
    (u32)&unk_80535de8, (u32)&unk_80535e84, (u32)&unk_805336d8,
    (u32)&unk_80535ef4, (u32)&unk_8053308c, (u32)&unk_80533be8,
    (u32)&unk_80533c34, (u32)&unk_805371a4};
u32 lbl_808b344c[] = {
    0x00000000,         0x00000000,         (u32)&unk_80535f28,
    (u32)&unk_80535de8, (u32)&unk_80535fe4, (u32)&unk_805336d8,
    (u32)&unk_80535ef4, (u32)&unk_8053308c, (u32)&unk_80533be8,
    (u32)&unk_80533c34, (u32)&unk_805371a4};
u32 lbl_808b3478[] = {
    0x00000000,         0x00000000,         (u32)&TimeAttackGamemode_canEndRace,
    (u32)&unk_80535de8, (u32)&unk_80535e84, (u32)&unk_805336d8,
    (u32)&unk_80535ef4, (u32)&unk_8053308c, (u32)&unk_80533be8,
    (u32)&unk_80533c34, (u32)&unk_805371a4};
u32 lbl_808b34a4[] = {0x00000000, 0x00000000, (u32)&RaceinfoPlayer_destroy};
u32 lbl_808b34b0[] = {0x00000000, 0x00000000, (u32)&unk_805376e0,
                      (u32)&unk_80535864, (u32)&unk_80535904};
u32 lbl_808b34c4[] = {0x00000000, 0x00000000, (u32)&unk_80532de0,
                      (u32)&unk_80532d44, (u32)&unk_805336a0};
u32 lbl_808b34d8[] = {0x00000000, 0x00000000, (u32)&unk_805371a8,
                      0x00000000, 0x00000000, 0x00000000};
#pragma explicit_zero_data off

// .bss
u8 spInstance__Q26System11RaceManager[8];

// Symbol: Raceinfo_initStaticInstance
// PAL: 0x80532084..0x805320d4
MARK_BINARY_BLOB(Raceinfo_initStaticInstance, 0x80532084, 0x805320d4);
asm UNKNOWN_FUNCTION(Raceinfo_initStaticInstance) {
  // clang-format off
  nofralloc
  /* 80532084 9421FFF0 */ stwu        r1, -0x10(r1)
  /* 80532088 7C0802A6 */ mflr        r0
  /* 8053208C 3C60809C */ lis         r3, spInstance__Q26System11RaceManager@ha
  /* 80532090 90010014 */ stw         r0, 0x14(r1)
  /* 80532094 8003D730 */ lwz         r0, spInstance__Q26System11RaceManager@l(r3)
  /* 80532098 2C000000 */ cmpwi       r0, 0x0
  /* 8053209C 40820020 */ bne-        lbl_805320bc
  /* 805320A0 3860004C */ li          r3, 0x4c
  /* 805320A4 4BCF7D29 */ bl          __nw__FUl
  /* 805320A8 2C030000 */ cmpwi       r3, 0x0
  /* 805320AC 41820008 */ beq-        lbl_805320b4
  /* 805320B0 480006F1 */ bl          Raceinfo_construct
  lbl_805320b4:
  /* 805320B4 3C80809C */ lis         r4, spInstance__Q26System11RaceManager@ha
  /* 805320B8 9064D730 */ stw         r3, spInstance__Q26System11RaceManager@l(r4)
  lbl_805320bc:
  /* 805320BC 80010014 */ lwz         r0, 0x14(r1)
  /* 805320C0 3C60809C */ lis         r3, spInstance__Q26System11RaceManager@ha
  /* 805320C4 8063D730 */ lwz         r3, spInstance__Q26System11RaceManager@l(r3)
  /* 805320C8 7C0803A6 */ mtlr        r0
  /* 805320CC 38210010 */ addi        r1, r1, 0x10
  /* 805320D0 4E800020 */ blr // clang-format on
}

// Symbol: Raceinfo_destroyStaticInstance
// PAL: 0x805320d4..0x80532124
MARK_BINARY_BLOB(Raceinfo_destroyStaticInstance, 0x805320d4, 0x80532124);
asm UNKNOWN_FUNCTION(Raceinfo_destroyStaticInstance) {
  // clang-format off
  nofralloc
  /* 805320D4 9421FFF0 */ stwu        r1, -0x10(r1)
  /* 805320D8 7C0802A6 */ mflr        r0
  /* 805320DC 3C60809C */ lis         r3, spInstance__Q26System11RaceManager@ha
  /* 805320E0 90010014 */ stw         r0, 0x14(r1)
  /* 805320E4 8063D730 */ lwz         r3, spInstance__Q26System11RaceManager@l(r3)
  /* 805320E8 2C030000 */ cmpwi       r3, 0x0
  /* 805320EC 4182001C */ beq-        lbl_80532108
  /* 805320F0 41820018 */ beq-        lbl_80532108
  /* 805320F4 81830000 */ lwz         r12, 0(r3)
  /* 805320F8 38800001 */ li          r4, 0x1
  /* 805320FC 818C0008 */ lwz         r12, 8(r12)
  /* 80532100 7D8903A6 */ mtctr       r12
  /* 80532104 4E800421 */ bctrl
  lbl_80532108:
  /* 80532108 3C60809C */ lis         r3, spInstance__Q26System11RaceManager@ha
  /* 8053210C 38000000 */ li          r0, 0x0
  /* 80532110 9003D730 */ stw         r0, spInstance__Q26System11RaceManager@l(r3)
  /* 80532114 80010014 */ lwz         r0, 0x14(r1)
  /* 80532118 7C0803A6 */ mtlr        r0
  /* 8053211C 38210010 */ addi        r1, r1, 0x10
  /* 80532120 4E800020 */ blr // clang-format on
}

// Symbol: unk_80532124
// PAL: 0x80532124..0x80532188
MARK_BINARY_BLOB(unk_80532124, 0x80532124, 0x80532188);
asm UNKNOWN_FUNCTION(unk_80532124) {
  // clang-format off
  nofralloc
  /* 80532124 9421FFF0 */ stwu        r1, -0x10(r1)
  /* 80532128 7C0802A6 */ mflr        r0
  /* 8053212C 3CA0808B */ lis         r5, lbl_808b344c@ha
  /* 80532130 3CE0809C */ lis         r7, spInstance__Q26System15ResourceManager@ha
  /* 80532134 90010014 */ stw         r0, 0x14(r1)
  /* 80532138 38A5344C */ addi        r5, r5, lbl_808b344c@l
  /* 8053213C 38000000 */ li          r0, 0x0
  /* 80532140 38C00000 */ li          r6, 0x0
  /* 80532144 93E1000C */ stw         r31, 0xc(r1)
  /* 80532148 7C7F1B78 */ mr          r31, r3
  /* 8053214C 90830004 */ stw         r4, 4(r3)
  /* 80532150 38800000 */ li          r4, 0x0
  /* 80532154 90A30000 */ stw         r5, 0(r3)
  /* 80532158 3CA08089 */ lis         r5, lbl_808901e8@ha
  /* 8053215C 38A501E8 */ addi        r5, r5, lbl_808901e8@l
  /* 80532160 90030008 */ stw         r0, 8(r3)
  /* 80532164 8067D738 */ lwz         r3, spInstance__Q26System15ResourceManager@l(r7)
  /* 80532168 4800F095 */ bl          getFile__Q26System15ResourceManagerFlPCcPUl
  /* 8053216C 907F0008 */ stw         r3, 8(r31)
  /* 80532170 7FE3FB78 */ mr          r3, r31
  /* 80532174 83E1000C */ lwz         r31, 0xc(r1)
  /* 80532178 80010014 */ lwz         r0, 0x14(r1)
  /* 8053217C 7C0803A6 */ mtlr        r0
  /* 80532180 38210010 */ addi        r1, r1, 0x10
  /* 80532184 4E800020 */ blr // clang-format on
}

// Symbol: Raceinfo_initGamemode
// PAL: 0x80532188..0x80532488
MARK_BINARY_BLOB(Raceinfo_initGamemode, 0x80532188, 0x80532488);
asm UNKNOWN_FUNCTION(Raceinfo_initGamemode) {
  // clang-format off
  nofralloc
  /* 80532188 9421FFE0 */ stwu        r1, -0x20(r1)
  /* 8053218C 7C0802A6 */ mflr        r0
  /* 80532190 2804000A */ cmplwi      r4, 0xa
  /* 80532194 90010024 */ stw         r0, 0x24(r1)
  /* 80532198 93E1001C */ stw         r31, 0x1c(r1)
  /* 8053219C 3FE0808B */ lis         r31, lbl_808b32b0@ha
  /* 805321A0 3BFF32B0 */ addi        r31, r31, lbl_808b32b0@l
  /* 805321A4 93C10018 */ stw         r30, 0x18(r1)
  /* 805321A8 93A10014 */ stw         r29, 0x14(r1)
  /* 805321AC 7C7D1B78 */ mr          r29, r3
  /* 805321B0 41810294 */ bgt-        lbl_80532444
  /* 805321B4 3CA0808B */ lis         r5, jtbl_808b32bc@ha
  /* 805321B8 5480103A */ slwi        r0, r4, 2
  /* 805321BC 38A532BC */ addi        r5, r5, jtbl_808b32bc@l
  /* 805321C0 7CA5002E */ lwzx        r5, r5, r0
  /* 805321C4 7CA903A6 */ mtctr       r5
  /* 805321C8 4E800420 */ bctr
  lbl_805321cc:
  entry jump_805321cc
  /* 805321CC 3860000C */ li          r3, 0xc
  /* 805321D0 4BCF7BFD */ bl          __nw__FUl
  /* 805321D4 2C030000 */ cmpwi       r3, 0x0
  /* 805321D8 7C7E1B78 */ mr          r30, r3
  /* 805321DC 4182028C */ beq-        lbl_80532468
  /* 805321E0 93A30004 */ stw         r29, 4(r3)
  /* 805321E4 3CA0808B */ lis         r5, lbl_808b344c@ha
  /* 805321E8 38A5344C */ addi        r5, r5, lbl_808b344c@l
  /* 805321EC 3C808089 */ lis         r4, lbl_808901e8@ha
  /* 805321F0 90A30000 */ stw         r5, 0(r3)
  /* 805321F4 38000000 */ li          r0, 0x0
  /* 805321F8 388401E8 */ addi        r4, r4, lbl_808901e8@l
  /* 805321FC 3CE0809C */ lis         r7, spInstance__Q26System15ResourceManager@ha
  /* 80532200 90030008 */ stw         r0, 8(r3)
  /* 80532204 38A40010 */ addi        r5, r4, 0x10
  /* 80532208 38800000 */ li          r4, 0x0
  /* 8053220C 38C00000 */ li          r6, 0x0
  /* 80532210 8067D738 */ lwz         r3, spInstance__Q26System15ResourceManager@l(r7)
  /* 80532214 4800EFE9 */ bl          getFile__Q26System15ResourceManagerFlPCcPUl
  /* 80532218 907E0008 */ stw         r3, 8(r30)
  /* 8053221C 4800024C */ b           lbl_80532468
  lbl_80532220:
  entry jump_80532220
  /* 80532220 38600008 */ li          r3, 0x8
  /* 80532224 4BCF7BA9 */ bl          __nw__FUl
  /* 80532228 2C030000 */ cmpwi       r3, 0x0
  /* 8053222C 41820014 */ beq-        lbl_80532240
  /* 80532230 93A30004 */ stw         r29, 4(r3)
  /* 80532234 3C80808B */ lis         r4, lbl_808b3420@ha
  /* 80532238 38843420 */ addi        r4, r4, lbl_808b3420@l
  /* 8053223C 90830000 */ stw         r4, 0(r3)
  lbl_80532240:
  /* 80532240 7C7E1B78 */ mr          r30, r3
  /* 80532244 48000224 */ b           lbl_80532468
  lbl_80532248:
  entry jump_80532248
  /* 80532248 4800B735 */ bl          unk_8053d97c
  /* 8053224C 7C7E1B78 */ mr          r30, r3
  /* 80532250 48000218 */ b           lbl_80532468
  lbl_80532254:
  entry jump_80532254
  /* 80532254 3C60809C */ lis         r3, spInstance__Q26System10RaceConfig@ha
  /* 80532258 8063D728 */ lwz         r3, spInstance__Q26System10RaceConfig@l(r3)
  /* 8053225C 80030B78 */ lwz         r0, 0xb78(r3)
  /* 80532260 2C000000 */ cmpwi       r0, 0x0
  /* 80532264 40820034 */ bne-        lbl_80532298
  /* 80532268 38600038 */ li          r3, 0x38
  /* 8053226C 4BCF7B61 */ bl          __nw__FUl
  /* 80532270 2C030000 */ cmpwi       r3, 0x0
  /* 80532274 4182001C */ beq-        lbl_80532290
  /* 80532278 93A30004 */ stw         r29, 4(r3)
  /* 8053227C 38000000 */ li          r0, 0x0
  /* 80532280 3C80808B */ lis         r4, lbl_808b36e4@ha
  /* 80532284 90030008 */ stw         r0, 8(r3)
  /* 80532288 388436E4 */ addi        r4, r4, lbl_808b36e4@l
  /* 8053228C 90830000 */ stw         r4, 0(r3)
  lbl_80532290:
  /* 80532290 7C7E1B78 */ mr          r30, r3
  /* 80532294 480001D4 */ b           lbl_80532468
  lbl_80532298:
  /* 80532298 38600038 */ li          r3, 0x38
  /* 8053229C 4BCF7B31 */ bl          __nw__FUl
  /* 805322A0 2C030000 */ cmpwi       r3, 0x0
  /* 805322A4 4182001C */ beq-        lbl_805322c0
  /* 805322A8 93A30004 */ stw         r29, 4(r3)
  /* 805322AC 38000000 */ li          r0, 0x0
  /* 805322B0 3C80808B */ lis         r4, lbl_808b3698@ha
  /* 805322B4 90030008 */ stw         r0, 8(r3)
  /* 805322B8 38843698 */ addi        r4, r4, lbl_808b3698@l
  /* 805322BC 90830000 */ stw         r4, 0(r3)
  lbl_805322c0:
  /* 805322C0 7C7E1B78 */ mr          r30, r3
  /* 805322C4 480001A4 */ b           lbl_80532468
  lbl_805322c8:
  entry jump_805322c8
  /* 805322C8 38600174 */ li          r3, 0x174
  /* 805322CC 4BCF7B01 */ bl          __nw__FUl
  /* 805322D0 2C030000 */ cmpwi       r3, 0x0
  /* 805322D4 7C7E1B78 */ mr          r30, r3
  /* 805322D8 41820190 */ beq-        lbl_80532468
  /* 805322DC 93A30004 */ stw         r29, 4(r3)
  /* 805322E0 3CA0808B */ lis         r5, lbl_808b3928@ha
  /* 805322E4 38A53928 */ addi        r5, r5, lbl_808b3928@l
  /* 805322E8 3C808053 */ lis         r4, unk_80532488@ha
  /* 805322EC 90A30000 */ stw         r5, 0(r3)
  /* 805322F0 3CA08053 */ lis         r5, unk_805324ac@ha
  /* 805322F4 38842488 */ addi        r4, r4, unk_80532488@l
  /* 805322F8 38C00014 */ li          r6, 0x14
  /* 805322FC 38A524AC */ addi        r5, r5, unk_805324ac@l
  /* 80532300 38E0000C */ li          r7, 0xc
  /* 80532304 38630008 */ addi        r3, r3, 0x8
  /* 80532308 4BAEECED */ bl          __construct_array
  /* 8053230C 3D20808B */ lis         r9, lbl_808b3408@ha
  /* 80532310 3C60808B */ lis         r3, lbl_808b33c0@ha
  /* 80532314 39293408 */ addi        r9, r9, lbl_808b3408@l
  /* 80532318 913E012C */ stw         r9, 0x12c(r30)
  /* 8053231C 3D00808B */ lis         r8, lbl_808b33a8@ha
  /* 80532320 3CE0808B */ lis         r7, lbl_808b3390@ha
  /* 80532324 881F0000 */ lbz         r0, 0(r31)
  /* 80532328 3CC0808B */ lis         r6, lbl_808b33d8@ha
  /* 8053232C 981E0130 */ stb         r0, 0x130(r30)
  /* 80532330 386333C0 */ addi        r3, r3, lbl_808b33c0@l
  /* 80532334 3CA0808B */ lis         r5, lbl_808b3378@ha
  /* 80532338 3C80808B */ lis         r4, lbl_808b3360@ha
  /* 8053233C 907E012C */ stw         r3, 0x12c(r30)
  /* 80532340 3C60808B */ lis         r3, lbl_808b33f0@ha
  /* 80532344 390833A8 */ addi        r8, r8, lbl_808b33a8@l
  /* 80532348 38E73390 */ addi        r7, r7, lbl_808b3390@l
  /* 8053234C 913E0134 */ stw         r9, 0x134(r30)
  /* 80532350 38C633D8 */ addi        r6, r6, lbl_808b33d8@l
  /* 80532354 38A53378 */ addi        r5, r5, lbl_808b3378@l
  /* 80532358 38843360 */ addi        r4, r4, lbl_808b3360@l
  /* 8053235C 881F0001 */ lbz         r0, 1(r31)
  /* 80532360 386333F0 */ addi        r3, r3, lbl_808b33f0@l
  /* 80532364 981E0138 */ stb         r0, 0x138(r30)
  /* 80532368 911E0134 */ stw         r8, 0x134(r30)
  /* 8053236C 913E013C */ stw         r9, 0x13c(r30)
  /* 80532370 881F0002 */ lbz         r0, 2(r31)
  /* 80532374 981E0140 */ stb         r0, 0x140(r30)
  /* 80532378 90FE013C */ stw         r7, 0x13c(r30)
  /* 8053237C 90DE0144 */ stw         r6, 0x144(r30)
  /* 80532380 A01F0004 */ lhz         r0, 4(r31)
  /* 80532384 B01E0148 */ sth         r0, 0x148(r30)
  /* 80532388 90BE0144 */ stw         r5, 0x144(r30)
  /* 8053238C 90DE014C */ stw         r6, 0x14c(r30)
  /* 80532390 A01F0006 */ lhz         r0, 6(r31)
  /* 80532394 B01E0150 */ sth         r0, 0x150(r30)
  /* 80532398 909E014C */ stw         r4, 0x14c(r30)
  /* 8053239C 90DE0154 */ stw         r6, 0x154(r30)
  /* 805323A0 A01F0006 */ lhz         r0, 6(r31)
  /* 805323A4 B01E0158 */ sth         r0, 0x158(r30)
  /* 805323A8 909E0154 */ stw         r4, 0x154(r30)
  /* 805323AC 90DE015C */ stw         r6, 0x15c(r30)
  /* 805323B0 A01F0006 */ lhz         r0, 6(r31)
  /* 805323B4 B01E0160 */ sth         r0, 0x160(r30)
  /* 805323B8 909E015C */ stw         r4, 0x15c(r30)
  /* 805323BC 913E0164 */ stw         r9, 0x164(r30)
  /* 805323C0 881F0008 */ lbz         r0, 8(r31)
  /* 805323C4 981E0168 */ stb         r0, 0x168(r30)
  /* 805323C8 907E0164 */ stw         r3, 0x164(r30)
  /* 805323CC 90DE016C */ stw         r6, 0x16c(r30)
  /* 805323D0 A01F0006 */ lhz         r0, 6(r31)
  /* 805323D4 B01E0170 */ sth         r0, 0x170(r30)
  /* 805323D8 909E016C */ stw         r4, 0x16c(r30)
  /* 805323DC 4800008C */ b           lbl_80532468
  lbl_805323e0:
  entry jump_805323e0
  /* 805323E0 3C60809C */ lis         r3, spInstance__Q26System10RaceConfig@ha
  /* 805323E4 8063D728 */ lwz         r3, spInstance__Q26System10RaceConfig@l(r3)
  /* 805323E8 80030B78 */ lwz         r0, 0xb78(r3)
  /* 805323EC 2C000000 */ cmpwi       r0, 0x0
  /* 805323F0 40820024 */ bne-        lbl_80532414
  /* 805323F4 38600170 */ li          r3, 0x170
  /* 805323F8 4BCF79D5 */ bl          __nw__FUl
  /* 805323FC 2C030000 */ cmpwi       r3, 0x0
  /* 80532400 4182000C */ beq-        lbl_8053240c
  /* 80532404 7FA4EB78 */ mr          r4, r29
  /* 80532408 48007B81 */ bl          unk_80539f88
  lbl_8053240c:
  /* 8053240C 7C7E1B78 */ mr          r30, r3
  /* 80532410 48000058 */ b           lbl_80532468
  lbl_80532414:
  /* 80532414 38600038 */ li          r3, 0x38
  /* 80532418 4BCF79B5 */ bl          __nw__FUl
  /* 8053241C 2C030000 */ cmpwi       r3, 0x0
  /* 80532420 4182001C */ beq-        lbl_8053243c
  /* 80532424 93A30004 */ stw         r29, 4(r3)
  /* 80532428 38000000 */ li          r0, 0x0
  /* 8053242C 3C80808B */ lis         r4, lbl_808b3524@ha
  /* 80532430 90030008 */ stw         r0, 8(r3)
  /* 80532434 38843524 */ addi        r4, r4, lbl_808b3524@l
  /* 80532438 90830000 */ stw         r4, 0(r3)
  lbl_8053243c:
  /* 8053243C 7C7E1B78 */ mr          r30, r3
  /* 80532440 48000028 */ b           lbl_80532468
  lbl_80532444:
  entry jump_80532444
  /* 80532444 38600008 */ li          r3, 0x8
  /* 80532448 4BCF7985 */ bl          __nw__FUl
  /* 8053244C 2C030000 */ cmpwi       r3, 0x0
  /* 80532450 41820014 */ beq-        lbl_80532464
  /* 80532454 3C80808B */ lis         r4, lbl_808b3478@ha
  /* 80532458 38843478 */ addi        r4, r4, lbl_808b3478@l
  /* 8053245C 90830000 */ stw         r4, 0(r3)
  /* 80532460 93A30004 */ stw         r29, 4(r3)
  lbl_80532464:
  /* 80532464 7C7E1B78 */ mr          r30, r3
  lbl_80532468:
  /* 80532468 7FC3F378 */ mr          r3, r30
  /* 8053246C 83E1001C */ lwz         r31, 0x1c(r1)
  /* 80532470 83C10018 */ lwz         r30, 0x18(r1)
  /* 80532474 83A10014 */ lwz         r29, 0x14(r1)
  /* 80532478 80010024 */ lwz         r0, 0x24(r1)
  /* 8053247C 7C0803A6 */ mtlr        r0
  /* 80532480 38210020 */ addi        r1, r1, 0x20
  /* 80532484 4E800020 */ blr // clang-format on
}

// Symbol: unk_80532488
// PAL: 0x80532488..0x805324ac
MARK_BINARY_BLOB(unk_80532488, 0x80532488, 0x805324ac);
asm UNKNOWN_FUNCTION(unk_80532488) {
  // clang-format off
  nofralloc
  /* 80532488 3C80808B */ lis         r4, __vt__Q26System4Time@ha
  /* 8053248C 38000000 */ li          r0, 0x0
  /* 80532490 38842D44 */ addi        r4, r4, __vt__Q26System4Time@l
  /* 80532494 90830000 */ stw         r4, 0(r3)
  /* 80532498 9803000A */ stb         r0, 0xa(r3)
  /* 8053249C B0030004 */ sth         r0, 4(r3)
  /* 805324A0 98030006 */ stb         r0, 6(r3)
  /* 805324A4 B0030008 */ sth         r0, 8(r3)
  /* 805324A8 4E800020 */ blr // clang-format on
}

// Symbol: unk_805324ac
// PAL: 0x805324ac..0x805324ec
MARK_BINARY_BLOB(unk_805324ac, 0x805324ac, 0x805324ec);
asm UNKNOWN_FUNCTION(unk_805324ac){
  // clang-format off
  nofralloc
  /* 805324AC 9421FFF0 */ stwu        r1, -0x10(r1)
  /* 805324B0 7C0802A6 */ mflr        r0
  /* 805324B4 2C030000 */ cmpwi       r3, 0x0
  /* 805324B8 90010014 */ stw         r0, 0x14(r1)
  /* 805324BC 93E1000C */ stw         r31, 0xc(r1)
  /* 805324C0 7C7F1B78 */ mr          r31, r3
  /* 805324C4 41820010 */ beq-        lbl_805324d4
  /* 805324C8 2C040000 */ cmpwi       r4, 0x0
  /* 805324CC 40810008 */ ble-        lbl_805324d4
  /* 805324D0 4BCF7945 */ bl          __dl__FPv
  lbl_805324d4:
  /* 805324D4 7FE3FB78 */ mr          r3, r31
  /* 805324D8 83E1000C */ lwz         r31, 0xc(r1)
  /* 805324DC 80010014 */ lwz         r0, 0x14(r1)
  /* 805324E0 7C0803A6 */ mtlr        r0
  /* 805324E4 38210010 */ addi        r1, r1, 0x10
  /* 805324E8 4E800020 */ blr // clang-format on
}

// Symbol: unk_805324ec
// PAL: 0x805324ec..0x8053252c
MARK_BINARY_BLOB(unk_805324ec, 0x805324ec, 0x8053252c);
asm UNKNOWN_FUNCTION(unk_805324ec){
  // clang-format off
  nofralloc
  /* 805324EC 9421FFF0 */ stwu        r1, -0x10(r1)
  /* 805324F0 7C0802A6 */ mflr        r0
  /* 805324F4 2C030000 */ cmpwi       r3, 0x0
  /* 805324F8 90010014 */ stw         r0, 0x14(r1)
  /* 805324FC 93E1000C */ stw         r31, 0xc(r1)
  /* 80532500 7C7F1B78 */ mr          r31, r3
  /* 80532504 41820010 */ beq-        lbl_80532514
  /* 80532508 2C040000 */ cmpwi       r4, 0x0
  /* 8053250C 40810008 */ ble-        lbl_80532514
  /* 80532510 4BCF7905 */ bl          __dl__FPv
  lbl_80532514:
  /* 80532514 7FE3FB78 */ mr          r3, r31
  /* 80532518 83E1000C */ lwz         r31, 0xc(r1)
  /* 8053251C 80010014 */ lwz         r0, 0x14(r1)
  /* 80532520 7C0803A6 */ mtlr        r0
  /* 80532524 38210010 */ addi        r1, r1, 0x10
  /* 80532528 4E800020 */ blr // clang-format on
}

// Symbol: unk_8053252c
// PAL: 0x8053252c..0x8053256c
MARK_BINARY_BLOB(unk_8053252c, 0x8053252c, 0x8053256c);
asm UNKNOWN_FUNCTION(unk_8053252c){
  // clang-format off
  nofralloc
  /* 8053252C 9421FFF0 */ stwu        r1, -0x10(r1)
  /* 80532530 7C0802A6 */ mflr        r0
  /* 80532534 2C030000 */ cmpwi       r3, 0x0
  /* 80532538 90010014 */ stw         r0, 0x14(r1)
  /* 8053253C 93E1000C */ stw         r31, 0xc(r1)
  /* 80532540 7C7F1B78 */ mr          r31, r3
  /* 80532544 41820010 */ beq-        lbl_80532554
  /* 80532548 2C040000 */ cmpwi       r4, 0x0
  /* 8053254C 40810008 */ ble-        lbl_80532554
  /* 80532550 4BCF78C5 */ bl          __dl__FPv
  lbl_80532554:
  /* 80532554 7FE3FB78 */ mr          r3, r31
  /* 80532558 83E1000C */ lwz         r31, 0xc(r1)
  /* 8053255C 80010014 */ lwz         r0, 0x14(r1)
  /* 80532560 7C0803A6 */ mtlr        r0
  /* 80532564 38210010 */ addi        r1, r1, 0x10
  /* 80532568 4E800020 */ blr // clang-format on
}

// Symbol: unk_8053256c
// PAL: 0x8053256c..0x805325ac
MARK_BINARY_BLOB(unk_8053256c, 0x8053256c, 0x805325ac);
asm UNKNOWN_FUNCTION(unk_8053256c){
  // clang-format off
  nofralloc
  /* 8053256C 9421FFF0 */ stwu        r1, -0x10(r1)
  /* 80532570 7C0802A6 */ mflr        r0
  /* 80532574 2C030000 */ cmpwi       r3, 0x0
  /* 80532578 90010014 */ stw         r0, 0x14(r1)
  /* 8053257C 93E1000C */ stw         r31, 0xc(r1)
  /* 80532580 7C7F1B78 */ mr          r31, r3
  /* 80532584 41820010 */ beq-        lbl_80532594
  /* 80532588 2C040000 */ cmpwi       r4, 0x0
  /* 8053258C 40810008 */ ble-        lbl_80532594
  /* 80532590 4BCF7885 */ bl          __dl__FPv
  lbl_80532594:
  /* 80532594 7FE3FB78 */ mr          r3, r31
  /* 80532598 83E1000C */ lwz         r31, 0xc(r1)
  /* 8053259C 80010014 */ lwz         r0, 0x14(r1)
  /* 805325A0 7C0803A6 */ mtlr        r0
  /* 805325A4 38210010 */ addi        r1, r1, 0x10
  /* 805325A8 4E800020 */ blr // clang-format on
}

// Symbol: unk_805325ac
// PAL: 0x805325ac..0x805325ec
MARK_BINARY_BLOB(unk_805325ac, 0x805325ac, 0x805325ec);
asm UNKNOWN_FUNCTION(unk_805325ac){
  // clang-format off
  nofralloc
  /* 805325AC 9421FFF0 */ stwu        r1, -0x10(r1)
  /* 805325B0 7C0802A6 */ mflr        r0
  /* 805325B4 2C030000 */ cmpwi       r3, 0x0
  /* 805325B8 90010014 */ stw         r0, 0x14(r1)
  /* 805325BC 93E1000C */ stw         r31, 0xc(r1)
  /* 805325C0 7C7F1B78 */ mr          r31, r3
  /* 805325C4 41820010 */ beq-        lbl_805325d4
  /* 805325C8 2C040000 */ cmpwi       r4, 0x0
  /* 805325CC 40810008 */ ble-        lbl_805325d4
  /* 805325D0 4BCF7845 */ bl          __dl__FPv
  lbl_805325d4:
  /* 805325D4 7FE3FB78 */ mr          r3, r31
  /* 805325D8 83E1000C */ lwz         r31, 0xc(r1)
  /* 805325DC 80010014 */ lwz         r0, 0x14(r1)
  /* 805325E0 7C0803A6 */ mtlr        r0
  /* 805325E4 38210010 */ addi        r1, r1, 0x10
  /* 805325E8 4E800020 */ blr // clang-format on
}

// Symbol: unk_805325ec
// PAL: 0x805325ec..0x8053262c
MARK_BINARY_BLOB(unk_805325ec, 0x805325ec, 0x8053262c);
asm UNKNOWN_FUNCTION(unk_805325ec){
  // clang-format off
  nofralloc
  /* 805325EC 9421FFF0 */ stwu        r1, -0x10(r1)
  /* 805325F0 7C0802A6 */ mflr        r0
  /* 805325F4 2C030000 */ cmpwi       r3, 0x0
  /* 805325F8 90010014 */ stw         r0, 0x14(r1)
  /* 805325FC 93E1000C */ stw         r31, 0xc(r1)
  /* 80532600 7C7F1B78 */ mr          r31, r3
  /* 80532604 41820010 */ beq-        lbl_80532614
  /* 80532608 2C040000 */ cmpwi       r4, 0x0
  /* 8053260C 40810008 */ ble-        lbl_80532614
  /* 80532610 4BCF7805 */ bl          __dl__FPv
  lbl_80532614:
  /* 80532614 7FE3FB78 */ mr          r3, r31
  /* 80532618 83E1000C */ lwz         r31, 0xc(r1)
  /* 8053261C 80010014 */ lwz         r0, 0x14(r1)
  /* 80532620 7C0803A6 */ mtlr        r0
  /* 80532624 38210010 */ addi        r1, r1, 0x10
  /* 80532628 4E800020 */ blr // clang-format on
}

// Symbol: unk_8053262c
// PAL: 0x8053262c..0x8053266c
MARK_BINARY_BLOB(unk_8053262c, 0x8053262c, 0x8053266c);
asm UNKNOWN_FUNCTION(unk_8053262c){
  // clang-format off
  nofralloc
  /* 8053262C 9421FFF0 */ stwu        r1, -0x10(r1)
  /* 80532630 7C0802A6 */ mflr        r0
  /* 80532634 2C030000 */ cmpwi       r3, 0x0
  /* 80532638 90010014 */ stw         r0, 0x14(r1)
  /* 8053263C 93E1000C */ stw         r31, 0xc(r1)
  /* 80532640 7C7F1B78 */ mr          r31, r3
  /* 80532644 41820010 */ beq-        lbl_80532654
  /* 80532648 2C040000 */ cmpwi       r4, 0x0
  /* 8053264C 40810008 */ ble-        lbl_80532654
  /* 80532650 4BCF77C5 */ bl          __dl__FPv
  lbl_80532654:
  /* 80532654 7FE3FB78 */ mr          r3, r31
  /* 80532658 83E1000C */ lwz         r31, 0xc(r1)
  /* 8053265C 80010014 */ lwz         r0, 0x14(r1)
  /* 80532660 7C0803A6 */ mtlr        r0
  /* 80532664 38210010 */ addi        r1, r1, 0x10
  /* 80532668 4E800020 */ blr // clang-format on
}

// Symbol: unk_8053266c
// PAL: 0x8053266c..0x805326ac
MARK_BINARY_BLOB(unk_8053266c, 0x8053266c, 0x805326ac);
asm UNKNOWN_FUNCTION(unk_8053266c){
  // clang-format off
  nofralloc
  /* 8053266C 9421FFF0 */ stwu        r1, -0x10(r1)
  /* 80532670 7C0802A6 */ mflr        r0
  /* 80532674 2C030000 */ cmpwi       r3, 0x0
  /* 80532678 90010014 */ stw         r0, 0x14(r1)
  /* 8053267C 93E1000C */ stw         r31, 0xc(r1)
  /* 80532680 7C7F1B78 */ mr          r31, r3
  /* 80532684 41820010 */ beq-        lbl_80532694
  /* 80532688 2C040000 */ cmpwi       r4, 0x0
  /* 8053268C 40810008 */ ble-        lbl_80532694
  /* 80532690 4BCF7785 */ bl          __dl__FPv
  lbl_80532694:
  /* 80532694 7FE3FB78 */ mr          r3, r31
  /* 80532698 83E1000C */ lwz         r31, 0xc(r1)
  /* 8053269C 80010014 */ lwz         r0, 0x14(r1)
  /* 805326A0 7C0803A6 */ mtlr        r0
  /* 805326A4 38210010 */ addi        r1, r1, 0x10
  /* 805326A8 4E800020 */ blr // clang-format on
}

// Symbol: unk_805326ac
// PAL: 0x805326ac..0x805326ec
MARK_BINARY_BLOB(unk_805326ac, 0x805326ac, 0x805326ec);
asm UNKNOWN_FUNCTION(unk_805326ac){
  // clang-format off
  nofralloc
  /* 805326AC 9421FFF0 */ stwu        r1, -0x10(r1)
  /* 805326B0 7C0802A6 */ mflr        r0
  /* 805326B4 2C030000 */ cmpwi       r3, 0x0
  /* 805326B8 90010014 */ stw         r0, 0x14(r1)
  /* 805326BC 93E1000C */ stw         r31, 0xc(r1)
  /* 805326C0 7C7F1B78 */ mr          r31, r3
  /* 805326C4 41820010 */ beq-        lbl_805326d4
  /* 805326C8 2C040000 */ cmpwi       r4, 0x0
  /* 805326CC 40810008 */ ble-        lbl_805326d4
  /* 805326D0 4BCF7745 */ bl          __dl__FPv
  lbl_805326d4:
  /* 805326D4 7FE3FB78 */ mr          r3, r31
  /* 805326D8 83E1000C */ lwz         r31, 0xc(r1)
  /* 805326DC 80010014 */ lwz         r0, 0x14(r1)
  /* 805326E0 7C0803A6 */ mtlr        r0
  /* 805326E4 38210010 */ addi        r1, r1, 0x10
  /* 805326E8 4E800020 */ blr // clang-format on
}

// Symbol: unk_805326ec
// PAL: 0x805326ec..0x805327a0
MARK_BINARY_BLOB(unk_805326ec, 0x805326ec, 0x805327a0);
asm UNKNOWN_FUNCTION(unk_805326ec) {
  // clang-format off
  nofralloc
  /* 805326EC 9421FFF0 */ stwu        r1, -0x10(r1)
  /* 805326F0 7C0802A6 */ mflr        r0
  /* 805326F4 3C80809C */ lis         r4, spInstance__Q26System10RaceConfig@ha
  /* 805326F8 90010014 */ stw         r0, 0x14(r1)
  /* 805326FC 93E1000C */ stw         r31, 0xc(r1)
  /* 80532700 93C10008 */ stw         r30, 8(r1)
  /* 80532704 8084D728 */ lwz         r4, spInstance__Q26System10RaceConfig@l(r4)
  /* 80532708 80040B78 */ lwz         r0, 0xb78(r4)
  /* 8053270C 2C000000 */ cmpwi       r0, 0x0
  /* 80532710 40820040 */ bne-        lbl_80532750
  /* 80532714 83C3003C */ lwz         r30, 0x3c(r3)
  /* 80532718 8BE40024 */ lbz         r31, 0x24(r4)
  /* 8053271C 80840B68 */ lwz         r4, 0xb68(r4)
  /* 80532720 7FC3F378 */ mr          r3, r30
  /* 80532724 48005C21 */ bl          unk_80538344
  /* 80532728 7C630734 */ extsh       r3, r3
  /* 8053272C 381FFFFE */ addi        r0, r31, -0x2
  /* 80532730 1C630016 */ mulli       r3, r3, 0x16
  /* 80532734 809E0004 */ lwz         r4, 4(r30)
  /* 80532738 5400083C */ slwi        r0, r0, 1
  /* 8053273C 7C641A14 */ add         r3, r4, r3
  /* 80532740 7C630214 */ add         r3, r3, r0
  /* 80532744 A8030010 */ lha         r0, 0x10(r3)
  /* 80532748 5403043E */ clrlwi      r3, r0, 0x10
  /* 8053274C 4800003C */ b           lbl_80532788
  lbl_80532750:
  /* 80532750 83C3003C */ lwz         r30, 0x3c(r3)
  /* 80532754 8BE40024 */ lbz         r31, 0x24(r4)
  /* 80532758 80840B68 */ lwz         r4, 0xb68(r4)
  /* 8053275C 7FC3F378 */ mr          r3, r30
  /* 80532760 48005BE5 */ bl          unk_80538344
  /* 80532764 7C630734 */ extsh       r3, r3
  /* 80532768 381FFFFE */ addi        r0, r31, -0x2
  /* 8053276C 1C630016 */ mulli       r3, r3, 0x16
  /* 80532770 809E0004 */ lwz         r4, 4(r30)
  /* 80532774 5400083C */ slwi        r0, r0, 1
  /* 80532778 7C641A14 */ add         r3, r4, r3
  /* 8053277C 7C630214 */ add         r3, r3, r0
  /* 80532780 A80301DC */ lha         r0, 0x1dc(r3)
  /* 80532784 5403043E */ clrlwi      r3, r0, 0x10
  lbl_80532788:
  /* 80532788 80010014 */ lwz         r0, 0x14(r1)
  /* 8053278C 83E1000C */ lwz         r31, 0xc(r1)
  /* 80532790 83C10008 */ lwz         r30, 8(r1)
  /* 80532794 7C0803A6 */ mtlr        r0
  /* 80532798 38210010 */ addi        r1, r1, 0x10
  /* 8053279C 4E800020 */ blr // clang-format on
}

// Symbol: Raceinfo_construct
// PAL: 0x805327a0..0x80532d44
MARK_BINARY_BLOB(Raceinfo_construct, 0x805327a0, 0x80532d44);
asm UNKNOWN_FUNCTION(Raceinfo_construct) {
  // clang-format off
  nofralloc
  /* 805327A0 9421FF70 */ stwu        r1, -0x90(r1)
  /* 805327A4 7C0802A6 */ mflr        r0
  /* 805327A8 3C80808B */ lis         r4, lbl_808b3350@ha
  /* 805327AC 90010094 */ stw         r0, 0x94(r1)
  /* 805327B0 38843350 */ addi        r4, r4, lbl_808b3350@l
  /* 805327B4 93E1008C */ stw         r31, 0x8c(r1)
  /* 805327B8 93C10088 */ stw         r30, 0x88(r1)
  /* 805327BC 93A10084 */ stw         r29, 0x84(r1)
  /* 805327C0 93810080 */ stw         r28, 0x80(r1)
  /* 805327C4 7C7C1B78 */ mr          r28, r3
  /* 805327C8 90830000 */ stw         r4, 0(r3)
  /* 805327CC 3880000C */ li          r4, 0xc
  /* 805327D0 38630034 */ addi        r3, r3, 0x34
  /* 805327D4 4801DF19 */ bl          unk_805506ec
  /* 805327D8 38600018 */ li          r3, 0x18
  /* 805327DC 4BCF75F1 */ bl          __nw__FUl
  /* 805327E0 2C030000 */ cmpwi       r3, 0x0
  /* 805327E4 41820014 */ beq-        lbl_805327f8
  /* 805327E8 3C80809C */ lis         r4, spInstance__Q26System10RaceConfig@ha
  /* 805327EC 8084D728 */ lwz         r4, spInstance__Q26System10RaceConfig@l(r4)
  /* 805327F0 80840B94 */ lwz         r4, 0xb94(r4)
  /* 805327F4 48022D21 */ bl          __ct__Q24Util6RandomFUl
  lbl_805327f8:
  /* 805327F8 907C0004 */ stw         r3, 4(r28)
  /* 805327FC 38600018 */ li          r3, 0x18
  /* 80532800 4BCF75CD */ bl          __nw__FUl
  /* 80532804 2C030000 */ cmpwi       r3, 0x0
  /* 80532808 41820014 */ beq-        lbl_8053281c
  /* 8053280C 3C80809C */ lis         r4, spInstance__Q26System10RaceConfig@ha
  /* 80532810 8084D728 */ lwz         r4, spInstance__Q26System10RaceConfig@l(r4)
  /* 80532814 80840B98 */ lwz         r4, 0xb98(r4)
  /* 80532818 48022CFD */ bl          __ct__Q24Util6RandomFUl
  lbl_8053281c:
  /* 8053281C 907C0008 */ stw         r3, 8(r28)
  /* 80532820 3FC0809C */ lis         r30, spInstance__Q26System10RaceConfig@ha
  /* 80532824 807ED728 */ lwz         r3, spInstance__Q26System10RaceConfig@l(r30)
  /* 80532828 88030024 */ lbz         r0, 0x24(r3)
  /* 8053282C 5403103A */ slwi        r3, r0, 2
  /* 80532830 4BCF75C1 */ bl          __nwa__FUl
  /* 80532834 907C000C */ stw         r3, 0xc(r28)
  /* 80532838 807ED728 */ lwz         r3, spInstance__Q26System10RaceConfig@l(r30)
  /* 8053283C 88630024 */ lbz         r3, 0x24(r3)
  /* 80532840 4BCF75B1 */ bl          __nwa__FUl
  /* 80532844 907C0018 */ stw         r3, 0x18(r28)
  /* 80532848 7F83E378 */ mr          r3, r28
  /* 8053284C 809ED728 */ lwz         r4, spInstance__Q26System10RaceConfig@l(r30)
  /* 80532850 80840B70 */ lwz         r4, 0xb70(r4)
  /* 80532854 4BFFF935 */ bl          Raceinfo_initGamemode
  /* 80532858 3C808089 */ lis         r4, lbl_80890154@ha
  /* 8053285C 38000000 */ li          r0, 0x0
  /* 80532860 C0040154 */ lfs         f0, lbl_80890154@l(r4)
  /* 80532864 3BE00001 */ li          r31, 0x1
  /* 80532868 907C0010 */ stw         r3, 0x10(r28)
  /* 8053286C 3BA00000 */ li          r29, 0x0
  /* 80532870 B01C001E */ sth         r0, 0x1e(r28)
  /* 80532874 901C0028 */ stw         r0, 0x28(r28)
  /* 80532878 D01C0044 */ stfs        f0, 0x44(r28)
  /* 8053287C 9BFC0048 */ stb         r31, 0x48(r28)
  /* 80532880 981C002C */ stb         r0, 0x2c(r28)
  /* 80532884 981C002E */ stb         r0, 0x2e(r28)
  /* 80532888 981C002F */ stb         r0, 0x2f(r28)
  /* 8053288C 480000C0 */ b           lbl_8053294c
  lbl_80532890:
  /* 80532890 38600054 */ li          r3, 0x54
  /* 80532894 4BCF7539 */ bl          __nw__FUl
  /* 80532898 2C030000 */ cmpwi       r3, 0x0
  /* 8053289C 4182003C */ beq-        lbl_805328d8
  /* 805328A0 809ED728 */ lwz         r4, spInstance__Q26System10RaceConfig@l(r30)
  /* 805328A4 38A00003 */ li          r5, 0x3
  /* 805328A8 80040B90 */ lwz         r0, 0xb90(r4)
  /* 805328AC 5400077B */ rlwinm.     r0, r0, 0, 0x1d, 0x1d
  /* 805328B0 4182001C */ beq-        lbl_805328cc
  /* 805328B4 88A40B8D */ lbz         r5, 0xb8d(r4)
  /* 805328B8 380500FF */ addi        r0, r5, 0xff
  /* 805328BC 5400063E */ clrlwi      r0, r0, 0x18
  /* 805328C0 28000008 */ cmplwi      r0, 8
  /* 805328C4 40810008 */ ble-        lbl_805328cc
  /* 805328C8 38A00003 */ li          r5, 0x3
  lbl_805328cc:
  /* 805328CC 57A4063E */ clrlwi      r4, r29, 0x18
  /* 805328D0 54A5063E */ clrlwi      r5, r5, 0x18
  /* 805328D4 48001605 */ bl          RaceinfoPlayer_construct
  lbl_805328d8:
  /* 805328D8 809C000C */ lwz         r4, 0xc(r28)
  /* 805328DC 57A615BA */ rlwinm      r6, r29, 2, 0x16, 0x1d
  /* 805328E0 38A00000 */ li          r5, 0x0
  /* 805328E4 7C64312E */ stwx        r3, r4, r6
  /* 805328E8 809ED728 */ lwz         r4, spInstance__Q26System10RaceConfig@l(r30)
  /* 805328EC 80640B70 */ lwz         r3, 0xb70(r4)
  /* 805328F0 3803FFFD */ addi        r0, r3, -0x3
  /* 805328F4 28000007 */ cmplwi      r0, 7
  /* 805328F8 41810014 */ bgt-        lbl_8053290c
  /* 805328FC 7FE00030 */ slw         r0, r31, r0
  /* 80532900 700000C1 */ andi.       r0, r0, 0xc1
  /* 80532904 41820008 */ beq-        lbl_8053290c
  /* 80532908 38A00001 */ li          r5, 0x1
  lbl_8053290c:
  /* 8053290C 2C050000 */ cmpwi       r5, 0x0
  /* 80532910 41820010 */ beq-        lbl_80532920
  /* 80532914 381D0001 */ addi        r0, r29, 0x1
  /* 80532918 5404063E */ clrlwi      r4, r0, 0x18
  /* 8053291C 48000014 */ b           lbl_80532930
  lbl_80532920:
  /* 80532920 57A0063E */ clrlwi      r0, r29, 0x18
  /* 80532924 1C0000F0 */ mulli       r0, r0, 0xf0
  /* 80532928 7C640214 */ add         r3, r4, r0
  /* 8053292C 88830109 */ lbz         r4, 0x109(r3)
  lbl_80532930:
  /* 80532930 807C000C */ lwz         r3, 0xc(r28)
  /* 80532934 7C63302E */ lwzx        r3, r3, r6
  /* 80532938 98830020 */ stb         r4, 0x20(r3)
  /* 8053293C 801C0018 */ lwz         r0, 0x18(r28)
  /* 80532940 7C602214 */ add         r3, r0, r4
  /* 80532944 9BA3FFFF */ stb         r29, -1(r3)
  /* 80532948 3BBD0001 */ addi        r29, r29, 0x1
  lbl_8053294c:
  /* 8053294C 807ED728 */ lwz         r3, spInstance__Q26System10RaceConfig@l(r30)
  /* 80532950 57A4063E */ clrlwi      r4, r29, 0x18
  /* 80532954 88030024 */ lbz         r0, 0x24(r3)
  /* 80532958 7C040040 */ cmplw       r4, r0
  /* 8053295C 4180FF34 */ blt+        lbl_80532890
  /* 80532960 38600050 */ li          r3, 0x50
  /* 80532964 4BCF7469 */ bl          __nw__FUl
  /* 80532968 2C030000 */ cmpwi       r3, 0x0
  /* 8053296C 7C7D1B78 */ mr          r29, r3
  /* 80532970 41820080 */ beq-        lbl_805329f0
  /* 80532974 3CA0808B */ lis         r5, lbl_808b34c4@ha
  /* 80532978 3C80808B */ lis         r4, __vt__Q26System4Time@ha
  /* 8053297C 38A534C4 */ addi        r5, r5, lbl_808b34c4@l
  /* 80532980 90A30000 */ stw         r5, 0(r3)
  /* 80532984 38842D44 */ addi        r4, r4, __vt__Q26System4Time@l
  /* 80532988 38000000 */ li          r0, 0x0
  /* 8053298C 90830004 */ stw         r4, 4(r3)
  /* 80532990 9803000E */ stb         r0, 0xe(r3)
  /* 80532994 B0030008 */ sth         r0, 8(r3)
  /* 80532998 9803000A */ stb         r0, 0xa(r3)
  /* 8053299C B003000C */ sth         r0, 0xc(r3)
  /* 805329A0 90830010 */ stw         r4, 0x10(r3)
  /* 805329A4 9803001A */ stb         r0, 0x1a(r3)
  /* 805329A8 B0030014 */ sth         r0, 0x14(r3)
  /* 805329AC 98030016 */ stb         r0, 0x16(r3)
  /* 805329B0 B0030018 */ sth         r0, 0x18(r3)
  /* 805329B4 9083001C */ stw         r4, 0x1c(r3)
  /* 805329B8 98030026 */ stb         r0, 0x26(r3)
  /* 805329BC B0030020 */ sth         r0, 0x20(r3)
  /* 805329C0 98030022 */ stb         r0, 0x22(r3)
  /* 805329C4 B0030024 */ sth         r0, 0x24(r3)
  /* 805329C8 38630028 */ addi        r3, r3, 0x28
  /* 805329CC 48022A99 */ bl          __ct__Q24Util6RandomFv
  /* 805329D0 819D0000 */ lwz         r12, 0(r29)
  /* 805329D4 7FA3EB78 */ mr          r3, r29
  /* 805329D8 818C000C */ lwz         r12, 0xc(r12)
  /* 805329DC 7D8903A6 */ mtctr       r12
  /* 805329E0 4E800421 */ bctrl
  /* 805329E4 3C60808B */ lis         r3, lbl_808b34b0@ha
  /* 805329E8 386334B0 */ addi        r3, r3, lbl_808b34b0@l
  /* 805329EC 907D0000 */ stw         r3, 0(r29)
  lbl_805329f0:
  /* 805329F0 93BC0014 */ stw         r29, 0x14(r28)
  /* 805329F4 7FA3EB78 */ mr          r3, r29
  /* 805329F8 819D0000 */ lwz         r12, 0(r29)
  /* 805329FC 818C000C */ lwz         r12, 0xc(r12)
  /* 80532A00 7D8903A6 */ mtctr       r12
  /* 80532A04 4E800421 */ bctrl
  /* 80532A08 3C60809C */ lis         r3, spInstance__Q26System10RaceConfig@ha
  /* 80532A0C 8063D728 */ lwz         r3, spInstance__Q26System10RaceConfig@l(r3)
  /* 80532A10 80030B90 */ lwz         r0, 0xb90(r3)
  /* 80532A14 5400077B */ rlwinm.     r0, r0, 0, 0x1d, 0x1d
  /* 80532A18 408200B0 */ bne-        lbl_80532ac8
  /* 80532A1C 80030B70 */ lwz         r0, 0xb70(r3)
  /* 80532A20 2C000004 */ cmpwi       r0, 0x4
  /* 80532A24 408200A4 */ bne-        lbl_80532ac8
  /* 80532A28 3800000E */ li          r0, 0xe
  /* 80532A2C 38A10004 */ addi        r5, r1, 0x4
  /* 80532A30 38830B98 */ addi        r4, r3, 0xb98
  /* 80532A34 7C0903A6 */ mtctr       r0
  lbl_80532a38:
  /* 80532A38 80640004 */ lwz         r3, 4(r4)
  /* 80532A3C 84040008 */ lwzu        r0, 8(r4)
  /* 80532A40 90650004 */ stw         r3, 4(r5)
  /* 80532A44 94050008 */ stwu        r0, 8(r5)
  /* 80532A48 4200FFF0 */ bdnz        lbl_80532a38
  /* 80532A4C 3C608889 */ lis         r3, 0x8889
  /* 80532A50 A1210034 */ lhz         r9, 0x34(r1)
  /* 80532A54 38038889 */ addi        r0, r3, -0x7777
  /* 80532A58 811C0014 */ lwz         r8, 0x14(r28)
  /* 80532A5C 7C004896 */ mulhw       r0, r0, r9
  /* 80532A60 38800000 */ li          r4, 0x0
  /* 80532A64 38600001 */ li          r3, 0x1
  /* 80532A68 7C004A14 */ add         r0, r0, r9
  /* 80532A6C 7C062E70 */ srawi       r6, r0, 5
  /* 80532A70 7C002E70 */ srawi       r0, r0, 5
  /* 80532A74 54050FFE */ srwi        r5, r0, 0x1f
  /* 80532A78 54C70FFE */ srwi        r7, r6, 0x1f
  /* 80532A7C 7C002A14 */ add         r0, r0, r5
  /* 80532A80 7CA63A14 */ add         r5, r6, r7
  /* 80532A84 54A6063E */ clrlwi      r6, r5, 0x18
  /* 80532A88 B0C80020 */ sth         r6, 0x20(r8)
  /* 80532A8C 1C00003C */ mulli       r0, r0, 0x3c
  /* 80532A90 7CA04850 */ subf        r5, r0, r9
  /* 80532A94 98A80022 */ stb         r5, 0x22(r8)
  /* 80532A98 1C06003C */ mulli       r0, r6, 0x3c
  /* 80532A9C B0880024 */ sth         r4, 0x24(r8)
  /* 80532AA0 54A7063E */ clrlwi      r7, r5, 0x18
  /* 80532AA4 98680026 */ stb         r3, 0x26(r8)
  /* 80532AA8 7C070214 */ add         r0, r7, r0
  /* 80532AAC 1C0003E8 */ mulli       r0, r0, 0x3e8
  /* 80532AB0 98680042 */ stb         r3, 0x42(r8)
  /* 80532AB4 B0C80014 */ sth         r6, 0x14(r8)
  /* 80532AB8 98A80016 */ stb         r5, 0x16(r8)
  /* 80532ABC B0880018 */ sth         r4, 0x18(r8)
  /* 80532AC0 9868001A */ stb         r3, 0x1a(r8)
  /* 80532AC4 90080044 */ stw         r0, 0x44(r8)
  lbl_80532ac8:
  /* 80532AC8 3C60809C */ lis         r3, spInstance__Q26System10RaceConfig@ha
  /* 80532ACC 38800000 */ li          r4, 0x0
  /* 80532AD0 8063D728 */ lwz         r3, spInstance__Q26System10RaceConfig@l(r3)
  /* 80532AD4 80630B70 */ lwz         r3, 0xb70(r3)
  /* 80532AD8 3803FFFD */ addi        r0, r3, -0x3
  /* 80532ADC 28000007 */ cmplwi      r0, 7
  /* 80532AE0 41810018 */ bgt-        lbl_80532af8
  /* 80532AE4 38600001 */ li          r3, 0x1
  /* 80532AE8 7C600030 */ slw         r0, r3, r0
  /* 80532AEC 700000C1 */ andi.       r0, r0, 0xc1
  /* 80532AF0 41820008 */ beq-        lbl_80532af8
  /* 80532AF4 7C641B78 */ mr          r4, r3
  lbl_80532af8:
  /* 80532AF8 2C040000 */ cmpwi       r4, 0x0
  /* 80532AFC 4182017C */ beq-        lbl_80532c78
  /* 80532B00 807C0004 */ lwz         r3, 4(r28)
  /* 80532B04 38800006 */ li          r4, 0x6
  /* 80532B08 48022AC5 */ bl          nextU32__Q24Util6RandomFUl
  /* 80532B0C 987C0024 */ stb         r3, 0x24(r28)
  /* 80532B10 3C80809C */ lis         r4, spInstance__Q26System9CourseMap@ha
  /* 80532B14 807C0004 */ lwz         r3, 4(r28)
  /* 80532B18 8084D6E8 */ lwz         r4, spInstance__Q26System9CourseMap@l(r4)
  /* 80532B1C 80840008 */ lwz         r4, 8(r4)
  /* 80532B20 2C040000 */ cmpwi       r4, 0x0
  /* 80532B24 4182000C */ beq-        lbl_80532b30
  /* 80532B28 A0840004 */ lhz         r4, 4(r4)
  /* 80532B2C 48000008 */ b           lbl_80532b34
  lbl_80532b30:
  /* 80532B30 38800000 */ li          r4, 0x0
  lbl_80532b34:
  /* 80532B34 48022A99 */ bl          nextU32__Q24Util6RandomFUl
  /* 80532B38 987C0025 */ stb         r3, 0x25(r28)
  /* 80532B3C 3CA08089 */ lis         r5, lbl_808901e8@ha
  /* 80532B40 3C60809C */ lis         r3, spInstance__Q26System15ResourceManager@ha
  /* 80532B44 38800000 */ li          r4, 0x0
  /* 80532B48 38A501E8 */ addi        r5, r5, lbl_808901e8@l
  /* 80532B4C 8063D738 */ lwz         r3, spInstance__Q26System15ResourceManager@l(r3)
  /* 80532B50 38A50020 */ addi        r5, r5, 0x20
  /* 80532B54 38C00000 */ li          r6, 0x0
  /* 80532B58 4800E6A5 */ bl          getFile__Q26System15ResourceManagerFlPCcPUl
  /* 80532B5C 7C7D1B78 */ mr          r29, r3
  /* 80532B60 38600008 */ li          r3, 0x8
  /* 80532B64 4BCF7269 */ bl          __nw__FUl
  /* 80532B68 2C030000 */ cmpwi       r3, 0x0
  /* 80532B6C 7C7E1B78 */ mr          r30, r3
  /* 80532B70 41820018 */ beq-        lbl_80532b88
  /* 80532B74 3CA0808B */ lis         r5, lbl_808b34d8@ha
  /* 80532B78 7FA4EB78 */ mr          r4, r29
  /* 80532B7C 38A534D8 */ addi        r5, r5, lbl_808b34d8@l
  /* 80532B80 90A30000 */ stw         r5, 0(r3)
  /* 80532B84 48005799 */ bl          unk_8053831c
  lbl_80532b88:
  /* 80532B88 93DC003C */ stw         r30, 0x3c(r28)
  /* 80532B8C 3C60809C */ lis         r3, spInstance__Q26System10RaceConfig@ha
  /* 80532B90 8083D728 */ lwz         r4, spInstance__Q26System10RaceConfig@l(r3)
  /* 80532B94 80040B78 */ lwz         r0, 0xb78(r4)
  /* 80532B98 2C000000 */ cmpwi       r0, 0x0
  /* 80532B9C 4082003C */ bne-        lbl_80532bd8
  /* 80532BA0 8BA40024 */ lbz         r29, 0x24(r4)
  /* 80532BA4 7FC3F378 */ mr          r3, r30
  /* 80532BA8 80840B68 */ lwz         r4, 0xb68(r4)
  /* 80532BAC 48005799 */ bl          unk_80538344
  /* 80532BB0 7C630734 */ extsh       r3, r3
  /* 80532BB4 381DFFFE */ addi        r0, r29, -0x2
  /* 80532BB8 1C630016 */ mulli       r3, r3, 0x16
  /* 80532BBC 809E0004 */ lwz         r4, 4(r30)
  /* 80532BC0 5400083C */ slwi        r0, r0, 1
  /* 80532BC4 7C641A14 */ add         r3, r4, r3
  /* 80532BC8 7C630214 */ add         r3, r3, r0
  /* 80532BCC A8030010 */ lha         r0, 0x10(r3)
  /* 80532BD0 5407043E */ clrlwi      r7, r0, 0x10
  /* 80532BD4 48000038 */ b           lbl_80532c0c
  lbl_80532bd8:
  /* 80532BD8 8BA40024 */ lbz         r29, 0x24(r4)
  /* 80532BDC 7FC3F378 */ mr          r3, r30
  /* 80532BE0 80840B68 */ lwz         r4, 0xb68(r4)
  /* 80532BE4 48005761 */ bl          unk_80538344
  /* 80532BE8 7C630734 */ extsh       r3, r3
  /* 80532BEC 381DFFFE */ addi        r0, r29, -0x2
  /* 80532BF0 1C630016 */ mulli       r3, r3, 0x16
  /* 80532BF4 809E0004 */ lwz         r4, 4(r30)
  /* 80532BF8 5400083C */ slwi        r0, r0, 1
  /* 80532BFC 7C641A14 */ add         r3, r4, r3
  /* 80532C00 7C630214 */ add         r3, r3, r0
  /* 80532C04 A80301DC */ lha         r0, 0x1dc(r3)
  /* 80532C08 5407043E */ clrlwi      r7, r0, 0x10
  lbl_80532c0c:
  /* 80532C0C 3C608889 */ lis         r3, 0x8889
  /* 80532C10 811C0014 */ lwz         r8, 0x14(r28)
  /* 80532C14 38038889 */ addi        r0, r3, -0x7777
  /* 80532C18 38800000 */ li          r4, 0x0
  /* 80532C1C 7C003896 */ mulhw       r0, r0, r7
  /* 80532C20 38600001 */ li          r3, 0x1
  /* 80532C24 7C003A14 */ add         r0, r0, r7
  /* 80532C28 7C002E70 */ srawi       r0, r0, 5
  /* 80532C2C 54050FFE */ srwi        r5, r0, 0x1f
  /* 80532C30 7CC02A14 */ add         r6, r0, r5
  /* 80532C34 B0C80020 */ sth         r6, 0x20(r8)
  /* 80532C38 54C0043E */ clrlwi      r0, r6, 0x10
  /* 80532C3C 1C00003C */ mulli       r0, r0, 0x3c
  /* 80532C40 7CA03850 */ subf        r5, r0, r7
  /* 80532C44 98A80022 */ stb         r5, 0x22(r8)
  /* 80532C48 54A7063E */ clrlwi      r7, r5, 0x18
  /* 80532C4C B0880024 */ sth         r4, 0x24(r8)
  /* 80532C50 7C070214 */ add         r0, r7, r0
  /* 80532C54 1C0003E8 */ mulli       r0, r0, 0x3e8
  /* 80532C58 98680026 */ stb         r3, 0x26(r8)
  /* 80532C5C 98680042 */ stb         r3, 0x42(r8)
  /* 80532C60 B0C80014 */ sth         r6, 0x14(r8)
  /* 80532C64 98A80016 */ stb         r5, 0x16(r8)
  /* 80532C68 B0880018 */ sth         r4, 0x18(r8)
  /* 80532C6C 9868001A */ stb         r3, 0x1a(r8)
  /* 80532C70 90080044 */ stw         r0, 0x44(r8)
  /* 80532C74 48000014 */ b           lbl_80532c88
  lbl_80532c78:
  /* 80532C78 38000000 */ li          r0, 0x0
  /* 80532C7C 981C0024 */ stb         r0, 0x24(r28)
  /* 80532C80 981C0025 */ stb         r0, 0x25(r28)
  /* 80532C84 901C003C */ stw         r0, 0x3c(r28)
  lbl_80532c88:
  /* 80532C88 3C80809C */ lis         r4, spInstance__Q26System10RaceConfig@ha
  /* 80532C8C 38600000 */ li          r3, 0x0
  /* 80532C90 8084D728 */ lwz         r4, spInstance__Q26System10RaceConfig@l(r4)
  /* 80532C94 80040B70 */ lwz         r0, 0xb70(r4)
  /* 80532C98 2C000007 */ cmpwi       r0, 0x7
  /* 80532C9C 41800010 */ blt-        lbl_80532cac
  /* 80532CA0 2C00000A */ cmpwi       r0, 0xa
  /* 80532CA4 41810008 */ bgt-        lbl_80532cac
  /* 80532CA8 38600001 */ li          r3, 0x1
  lbl_80532cac:
  /* 80532CAC 2C030000 */ cmpwi       r3, 0x0
  /* 80532CB0 4082000C */ bne-        lbl_80532cbc
  /* 80532CB4 38000001 */ li          r0, 0x1
  /* 80532CB8 981C002E */ stb         r0, 0x2e(r28)
  lbl_80532cbc:
  /* 80532CBC 3C60809C */ lis         r3, spInstance__Q26System10RaceConfig@ha
  /* 80532CC0 8063D728 */ lwz         r3, spInstance__Q26System10RaceConfig@l(r3)
  /* 80532CC4 80030B70 */ lwz         r0, 0xb70(r3)
  /* 80532CC8 2C00000B */ cmpwi       r0, 0xb
  /* 80532CCC 41800014 */ blt-        lbl_80532ce0
  /* 80532CD0 2C00000C */ cmpwi       r0, 0xc
  /* 80532CD4 4181000C */ bgt-        lbl_80532ce0
  /* 80532CD8 38000001 */ li          r0, 0x1
  /* 80532CDC 981C002F */ stb         r0, 0x2f(r28)
  lbl_80532ce0:
  /* 80532CE0 3C60809C */ lis         r3, spInstance__Q26System10RaceConfig@ha
  /* 80532CE4 8063D728 */ lwz         r3, spInstance__Q26System10RaceConfig@l(r3)
  /* 80532CE8 80030B74 */ lwz         r0, 0xb74(r3)
  /* 80532CEC 2C000006 */ cmpwi       r0, 0x6
  /* 80532CF0 40820010 */ bne-        lbl_80532d00
  /* 80532CF4 38000001 */ li          r0, 0x1
  /* 80532CF8 981C002D */ stb         r0, 0x2d(r28)
  /* 80532CFC 4800000C */ b           lbl_80532d08
  lbl_80532d00:
  /* 80532D00 38000000 */ li          r0, 0x0
  /* 80532D04 981C002D */ stb         r0, 0x2d(r28)
  lbl_80532d08:
  /* 80532D08 38600008 */ li          r3, 0x8
  /* 80532D0C 4BCF70C1 */ bl          __nw__FUl
  /* 80532D10 2C030000 */ cmpwi       r3, 0x0
  /* 80532D14 41820008 */ beq-        lbl_80532d1c
  /* 80532D18 4BFFA755 */ bl          unk_8052d46c
  lbl_80532d1c:
  /* 80532D1C 907C0040 */ stw         r3, 0x40(r28)
  /* 80532D20 7F83E378 */ mr          r3, r28
  /* 80532D24 83E1008C */ lwz         r31, 0x8c(r1)
  /* 80532D28 83C10088 */ lwz         r30, 0x88(r1)
  /* 80532D2C 83A10084 */ lwz         r29, 0x84(r1)
  /* 80532D30 83810080 */ lwz         r28, 0x80(r1)
  /* 80532D34 80010094 */ lwz         r0, 0x94(r1)
  /* 80532D38 7C0803A6 */ mtlr        r0
  /* 80532D3C 38210090 */ addi        r1, r1, 0x90
  /* 80532D40 4E800020 */ blr // clang-format on
}

// Symbol: unk_80532d44
// PAL: 0x80532d44..0x80532de0
MARK_BINARY_BLOB(unk_80532d44, 0x80532d44, 0x80532de0);
asm UNKNOWN_FUNCTION(unk_80532d44){
    // clang-format off
  nofralloc
  /* 80532D44 9421FFE0 */ stwu        r1, -0x20(r1)
  /* 80532D48 7C0802A6 */ mflr        r0
  /* 80532D4C 90010024 */ stw         r0, 0x24(r1)
  /* 80532D50 93E1001C */ stw         r31, 0x1c(r1)
  /* 80532D54 3BE00000 */ li          r31, 0x0
  /* 80532D58 93C10018 */ stw         r30, 0x18(r1)
  /* 80532D5C 3BC00001 */ li          r30, 0x1
  /* 80532D60 93A10014 */ stw         r29, 0x14(r1)
  /* 80532D64 7C7D1B78 */ mr          r29, r3
  /* 80532D68 9BC3001A */ stb         r30, 0x1a(r3)
  /* 80532D6C B3E30014 */ sth         r31, 0x14(r3)
  /* 80532D70 9BE30016 */ stb         r31, 0x16(r3)
  /* 80532D74 B3E30018 */ sth         r31, 0x18(r3)
  /* 80532D78 9BC3000E */ stb         r30, 0xe(r3)
  /* 80532D7C B3E30008 */ sth         r31, 8(r3)
  /* 80532D80 9BE3000A */ stb         r31, 0xa(r3)
  /* 80532D84 B3E3000C */ sth         r31, 0xc(r3)
  /* 80532D88 9BE30041 */ stb         r31, 0x41(r3)
  /* 80532D8C 9BE30040 */ stb         r31, 0x40(r3)
  /* 80532D90 4BC77FE5 */ bl          OSGetTick
  /* 80532D94 3C8001CA */ lis         r4, 0x1ca
  /* 80532D98 907D0034 */ stw         r3, 0x34(r29)
  /* 80532D9C 3804C37B */ addi        r0, r4, -0x3c85
  /* 80532DA0 93FD0030 */ stw         r31, 0x30(r29)
  /* 80532DA4 907D003C */ stw         r3, 0x3c(r29)
  /* 80532DA8 93FD0038 */ stw         r31, 0x38(r29)
  /* 80532DAC 9BDD0026 */ stb         r30, 0x26(r29)
  /* 80532DB0 B3FD0020 */ sth         r31, 0x20(r29)
  /* 80532DB4 9BFD0022 */ stb         r31, 0x22(r29)
  /* 80532DB8 B3FD0024 */ sth         r31, 0x24(r29)
  /* 80532DBC 9BFD0042 */ stb         r31, 0x42(r29)
  /* 80532DC0 901D0044 */ stw         r0, 0x44(r29)
  /* 80532DC4 83E1001C */ lwz         r31, 0x1c(r1)
  /* 80532DC8 83C10018 */ lwz         r30, 0x18(r1)
  /* 80532DCC 83A10014 */ lwz         r29, 0x14(r1)
  /* 80532DD0 80010024 */ lwz         r0, 0x24(r1)
  /* 80532DD4 7C0803A6 */ mtlr        r0
  /* 80532DD8 38210020 */ addi        r1, r1, 0x20
  /* 80532DDC 4E800020 */ blr // clang-format on
}

// Symbol: unk_80532de0
// PAL: 0x80532de0..0x80532e3c
MARK_BINARY_BLOB(unk_80532de0, 0x80532de0, 0x80532e3c);
asm UNKNOWN_FUNCTION(unk_80532de0){
  // clang-format off
  nofralloc
  /* 80532DE0 9421FFF0 */ stwu        r1, -0x10(r1)
  /* 80532DE4 7C0802A6 */ mflr        r0
  /* 80532DE8 2C030000 */ cmpwi       r3, 0x0
  /* 80532DEC 90010014 */ stw         r0, 0x14(r1)
  /* 80532DF0 93E1000C */ stw         r31, 0xc(r1)
  /* 80532DF4 7C9F2378 */ mr          r31, r4
  /* 80532DF8 93C10008 */ stw         r30, 8(r1)
  /* 80532DFC 7C7E1B78 */ mr          r30, r3
  /* 80532E00 41820020 */ beq-        lbl_80532e20
  /* 80532E04 3880FFFF */ li          r4, -0x1
  /* 80532E08 38630028 */ addi        r3, r3, 0x28
  /* 80532E0C 4802272D */ bl          __dt__Q24Util6RandomFv
  /* 80532E10 2C1F0000 */ cmpwi       r31, 0x0
  /* 80532E14 4081000C */ ble-        lbl_80532e20
  /* 80532E18 7FC3F378 */ mr          r3, r30
  /* 80532E1C 4BCF6FF9 */ bl          __dl__FPv
  lbl_80532e20:
  /* 80532E20 7FC3F378 */ mr          r3, r30
  /* 80532E24 83E1000C */ lwz         r31, 0xc(r1)
  /* 80532E28 83C10008 */ lwz         r30, 8(r1)
  /* 80532E2C 80010014 */ lwz         r0, 0x14(r1)
  /* 80532E30 7C0803A6 */ mtlr        r0
  /* 80532E34 38210010 */ addi        r1, r1, 0x10
  /* 80532E38 4E800020 */ blr // clang-format on
}

// Symbol: unk_80532e3c
// PAL: 0x80532e3c..0x80532f48
MARK_BINARY_BLOB(unk_80532e3c, 0x80532e3c, 0x80532f48);
asm UNKNOWN_FUNCTION(unk_80532e3c) {
  // clang-format off
  nofralloc
  /* 80532E3C 9421FFE0 */ stwu        r1, -0x20(r1)
  /* 80532E40 7C0802A6 */ mflr        r0
  /* 80532E44 2C030000 */ cmpwi       r3, 0x0
  /* 80532E48 90010024 */ stw         r0, 0x24(r1)
  /* 80532E4C 93E1001C */ stw         r31, 0x1c(r1)
  /* 80532E50 93C10018 */ stw         r30, 0x18(r1)
  /* 80532E54 93A10014 */ stw         r29, 0x14(r1)
  /* 80532E58 7C9D2378 */ mr          r29, r4
  /* 80532E5C 93810010 */ stw         r28, 0x10(r1)
  /* 80532E60 7C7C1B78 */ mr          r28, r3
  /* 80532E64 418200C0 */ beq-        lbl_80532f24
  /* 80532E68 80030004 */ lwz         r0, 4(r3)
  /* 80532E6C 3C80808B */ lis         r4, lbl_808b3350@ha
  /* 80532E70 38843350 */ addi        r4, r4, lbl_808b3350@l
  /* 80532E74 90830000 */ stw         r4, 0(r3)
  /* 80532E78 2C000000 */ cmpwi       r0, 0x0
  /* 80532E7C 4182001C */ beq-        lbl_80532e98
  /* 80532E80 7C030378 */ mr          r3, r0
  /* 80532E84 38800001 */ li          r4, 0x1
  /* 80532E88 81830000 */ lwz         r12, 0(r3)
  /* 80532E8C 818C0008 */ lwz         r12, 8(r12)
  /* 80532E90 7D8903A6 */ mtctr       r12
  /* 80532E94 4E800421 */ bctrl
  lbl_80532e98:
  /* 80532E98 807C0008 */ lwz         r3, 8(r28)
  /* 80532E9C 2C030000 */ cmpwi       r3, 0x0
  /* 80532EA0 41820018 */ beq-        lbl_80532eb8
  /* 80532EA4 81830000 */ lwz         r12, 0(r3)
  /* 80532EA8 38800001 */ li          r4, 0x1
  /* 80532EAC 818C0008 */ lwz         r12, 8(r12)
  /* 80532EB0 7D8903A6 */ mtctr       r12
  /* 80532EB4 4E800421 */ bctrl
  lbl_80532eb8:
  /* 80532EB8 3BC00000 */ li          r30, 0x0
  /* 80532EBC 3FE0809C */ lis         r31, spInstance__Q26System10RaceConfig@ha
  /* 80532EC0 48000030 */ b           lbl_80532ef0
  lbl_80532ec4:
  /* 80532EC4 807C000C */ lwz         r3, 0xc(r28)
  /* 80532EC8 57C015BA */ rlwinm      r0, r30, 2, 0x16, 0x1d
  /* 80532ECC 7C63002E */ lwzx        r3, r3, r0
  /* 80532ED0 2C030000 */ cmpwi       r3, 0x0
  /* 80532ED4 41820018 */ beq-        lbl_80532eec
  /* 80532ED8 81830000 */ lwz         r12, 0(r3)
  /* 80532EDC 38800001 */ li          r4, 0x1
  /* 80532EE0 818C0008 */ lwz         r12, 8(r12)
  /* 80532EE4 7D8903A6 */ mtctr       r12
  /* 80532EE8 4E800421 */ bctrl
  lbl_80532eec:
  /* 80532EEC 3BDE0001 */ addi        r30, r30, 0x1
  lbl_80532ef0:
  /* 80532EF0 807FD728 */ lwz         r3, spInstance__Q26System10RaceConfig@l(r31)
  /* 80532EF4 57C4063E */ clrlwi      r4, r30, 0x18
  /* 80532EF8 88030024 */ lbz         r0, 0x24(r3)
  /* 80532EFC 7C040040 */ cmplw       r4, r0
  /* 80532F00 4180FFC4 */ blt+        lbl_80532ec4
  /* 80532F04 807C000C */ lwz         r3, 0xc(r28)
  /* 80532F08 4BCF6FD9 */ bl          __dla__FPv
  /* 80532F0C 807C0018 */ lwz         r3, 0x18(r28)
  /* 80532F10 4BCF6FD1 */ bl          __dla__FPv
  /* 80532F14 2C1D0000 */ cmpwi       r29, 0x0
  /* 80532F18 4081000C */ ble-        lbl_80532f24
  /* 80532F1C 7F83E378 */ mr          r3, r28
  /* 80532F20 4BCF6EF5 */ bl          __dl__FPv
  lbl_80532f24:
  /* 80532F24 83E1001C */ lwz         r31, 0x1c(r1)
  /* 80532F28 7F83E378 */ mr          r3, r28
  /* 80532F2C 83C10018 */ lwz         r30, 0x18(r1)
  /* 80532F30 83A10014 */ lwz         r29, 0x14(r1)
  /* 80532F34 83810010 */ lwz         r28, 0x10(r1)
  /* 80532F38 80010024 */ lwz         r0, 0x24(r1)
  /* 80532F3C 7C0803A6 */ mtlr        r0
  /* 80532F40 38210020 */ addi        r1, r1, 0x20
  /* 80532F44 4E800020 */ blr // clang-format on
}

// Symbol: RaceinfoPlayer_destroy
// PAL: 0x80532f48..0x80532f88
MARK_BINARY_BLOB(RaceinfoPlayer_destroy, 0x80532f48, 0x80532f88);
asm UNKNOWN_FUNCTION(RaceinfoPlayer_destroy){
  // clang-format off
  nofralloc
  /* 80532F48 9421FFF0 */ stwu        r1, -0x10(r1)
  /* 80532F4C 7C0802A6 */ mflr        r0
  /* 80532F50 2C030000 */ cmpwi       r3, 0x0
  /* 80532F54 90010014 */ stw         r0, 0x14(r1)
  /* 80532F58 93E1000C */ stw         r31, 0xc(r1)
  /* 80532F5C 7C7F1B78 */ mr          r31, r3
  /* 80532F60 41820010 */ beq-        lbl_80532f70
  /* 80532F64 2C040000 */ cmpwi       r4, 0x0
  /* 80532F68 40810008 */ ble-        lbl_80532f70
  /* 80532F6C 4BCF6EA9 */ bl          __dl__FPv
  lbl_80532f70:
  /* 80532F70 7FE3FB78 */ mr          r3, r31
  /* 80532F74 83E1000C */ lwz         r31, 0xc(r1)
  /* 80532F78 80010014 */ lwz         r0, 0x14(r1)
  /* 80532F7C 7C0803A6 */ mtlr        r0
  /* 80532F80 38210010 */ addi        r1, r1, 0x10
  /* 80532F84 4E800020 */ blr // clang-format on
}

// Symbol: Raceinfo_init
// PAL: 0x80532f88..0x8053308c
MARK_BINARY_BLOB(Raceinfo_init, 0x80532f88, 0x8053308c);
asm UNKNOWN_FUNCTION(Raceinfo_init) {
  // clang-format off
  nofralloc
  /* 80532F88 9421FFE0 */ stwu        r1, -0x20(r1)
  /* 80532F8C 7C0802A6 */ mflr        r0
  /* 80532F90 38A00000 */ li          r5, 0x0
  /* 80532F94 3C80809C */ lis         r4, spInstance__Q26System10RaceConfig@ha
  /* 80532F98 90010024 */ stw         r0, 0x24(r1)
  /* 80532F9C 38000001 */ li          r0, 0x1
  /* 80532FA0 93E1001C */ stw         r31, 0x1c(r1)
  /* 80532FA4 7C7F1B78 */ mr          r31, r3
  /* 80532FA8 93C10018 */ stw         r30, 0x18(r1)
  /* 80532FAC 93A10014 */ stw         r29, 0x14(r1)
  /* 80532FB0 98A3001C */ stb         r5, 0x1c(r3)
  /* 80532FB4 98A3001D */ stb         r5, 0x1d(r3)
  /* 80532FB8 90A30020 */ stw         r5, 0x20(r3)
  /* 80532FBC 98030030 */ stb         r0, 0x30(r3)
  /* 80532FC0 8064D728 */ lwz         r3, spInstance__Q26System10RaceConfig@l(r4)
  /* 80532FC4 80030B70 */ lwz         r0, 0xb70(r3)
  /* 80532FC8 2C000004 */ cmpwi       r0, 0x4
  /* 80532FCC 40820020 */ bne-        lbl_80532fec
  /* 80532FD0 3C60809C */ lis         r3, spInstance__Q26System9CourseMap@ha
  /* 80532FD4 8063D6E8 */ lwz         r3, spInstance__Q26System9CourseMap@l(r3)
  /* 80532FD8 4BFE5BA1 */ bl          getStage__Q26System9CourseMapCFv
  /* 80532FDC 80630000 */ lwz         r3, 0(r3)
  /* 80532FE0 88030000 */ lbz         r0, 0(r3)
  /* 80532FE4 2C000000 */ cmpwi       r0, 0x0
  /* 80532FE8 41820024 */ beq-        lbl_8053300c
  lbl_80532fec:
  /* 80532FEC 3C60809C */ lis         r3, spInstance__Q26System10RaceConfig@ha
  /* 80532FF0 8063D728 */ lwz         r3, spInstance__Q26System10RaceConfig@l(r3)
  /* 80532FF4 80030B90 */ lwz         r0, 0xb90(r3)
  /* 80532FF8 5400077B */ rlwinm.     r0, r0, 0, 0x1d, 0x1d
  /* 80532FFC 41820018 */ beq-        lbl_80533014
  /* 80533000 88030B8D */ lbz         r0, 0xb8d(r3)
  /* 80533004 2C000000 */ cmpwi       r0, 0x0
  /* 80533008 4082000C */ bne-        lbl_80533014
  lbl_8053300c:
  /* 8053300C 38000000 */ li          r0, 0x0
  /* 80533010 981F0030 */ stb         r0, 0x30(r31)
  lbl_80533014:
  /* 80533014 3C008000 */ lis         r0, 0x8000
  /* 80533018 901F0038 */ stw         r0, 0x38(r31)
  /* 8053301C 3C60809C */ lis         r3, spInstance__Q26System12KPadDirector@ha
  /* 80533020 8063D70C */ lwz         r3, spInstance__Q26System12KPadDirector@l(r3)
  /* 80533024 4BFF1545 */ bl          lockGhostProxies__Q26System12KPadDirectorFv
  /* 80533028 3BA00000 */ li          r29, 0x0
  /* 8053302C 3FC0809C */ lis         r30, spInstance__Q26System10RaceConfig@ha
  /* 80533030 48000018 */ b           lbl_80533048
  lbl_80533034:
  /* 80533034 807F000C */ lwz         r3, 0xc(r31)
  /* 80533038 57A015BA */ rlwinm      r0, r29, 2, 0x16, 0x1d
  /* 8053303C 7C63002E */ lwzx        r3, r3, r0
  /* 80533040 48001155 */ bl          RaceinfoPlayer_init
  /* 80533044 3BBD0001 */ addi        r29, r29, 0x1
  lbl_80533048:
  /* 80533048 807ED728 */ lwz         r3, spInstance__Q26System10RaceConfig@l(r30)
  /* 8053304C 57A4063E */ clrlwi      r4, r29, 0x18
  /* 80533050 88030024 */ lbz         r0, 0x24(r3)
  /* 80533054 7C040040 */ cmplw       r4, r0
  /* 80533058 4180FFDC */ blt+        lbl_80533034
  /* 8053305C 807F0010 */ lwz         r3, 0x10(r31)
  /* 80533060 81830000 */ lwz         r12, 0(r3)
  /* 80533064 818C001C */ lwz         r12, 0x1c(r12)
  /* 80533068 7D8903A6 */ mtctr       r12
  /* 8053306C 4E800421 */ bctrl
  /* 80533070 80010024 */ lwz         r0, 0x24(r1)
  /* 80533074 83E1001C */ lwz         r31, 0x1c(r1)
  /* 80533078 83C10018 */ lwz         r30, 0x18(r1)
  /* 8053307C 83A10014 */ lwz         r29, 0x14(r1)
  /* 80533080 7C0803A6 */ mtlr        r0
  /* 80533084 38210020 */ addi        r1, r1, 0x20
  /* 80533088 4E800020 */ blr // clang-format on
}

// Symbol: unk_8053308c
// PAL: 0x8053308c..0x80533090
MARK_BINARY_BLOB(unk_8053308c, 0x8053308c, 0x80533090);
asm UNKNOWN_FUNCTION(unk_8053308c){
    // clang-format off
  nofralloc
  /* 8053308C 4E800020 */ blr // clang-format on
}

// Symbol: RaceInfo_getCountdown
// PAL: 0x80533090..0x805330c0
MARK_BINARY_BLOB(RaceInfo_getCountdown, 0x80533090, 0x805330c0);
asm UNKNOWN_FUNCTION(RaceInfo_getCountdown) {
  // clang-format off
  nofralloc
  /* 80533090 3C80809C */ lis         r4, spInstance__Q26System10RaceConfig@ha
  /* 80533094 8084D728 */ lwz         r4, spInstance__Q26System10RaceConfig@l(r4)
  /* 80533098 80040B70 */ lwz         r0, 0xb70(r4)
  /* 8053309C 2C00000B */ cmpwi       r0, 0xb
  /* 805330A0 41800014 */ blt-        lbl_805330b4
  /* 805330A4 2C00000C */ cmpwi       r0, 0xc
  /* 805330A8 4181000C */ bgt-        lbl_805330b4
  /* 805330AC 38600000 */ li          r3, 0x0
  /* 805330B0 4E800020 */ blr
  lbl_805330b4:
  /* 805330B4 80030020 */ lwz         r0, 0x20(r3)
  /* 805330B8 206000F0 */ subfic      r3, r0, 0xf0
  /* 805330BC 4E800020 */ blr // clang-format on
}

// Symbol: unk_805330c0
// PAL: 0x805330c0..0x805331b4
MARK_BINARY_BLOB(unk_805330c0, 0x805330c0, 0x805331b4);
asm UNKNOWN_FUNCTION(unk_805330c0) {
  // clang-format off
  nofralloc
  /* 805330C0 9421FFD0 */ stwu        r1, -0x30(r1)
  /* 805330C4 7C0802A6 */ mflr        r0
  /* 805330C8 90010034 */ stw         r0, 0x34(r1)
  /* 805330CC DBE10020 */ stfd        f31, 0x20(r1)
  /* 805330D0 F3E10028 */ opword      0xf3e10028
  /* 805330D4 DBC10010 */ stfd        f30, 0x10(r1)
  /* 805330D8 F3C10018 */ opword      0xf3c10018
  /* 805330DC 3C80809C */ lis         r4, lbl_809c4330@ha
  /* 805330E0 93E1000C */ stw         r31, 0xc(r1)
  /* 805330E4 93C10008 */ stw         r30, 8(r1)
  /* 805330E8 7C7E1B78 */ mr          r30, r3
  /* 805330EC 80644330 */ lwz         r3, lbl_809c4330@l(r4)
  /* 805330F0 80030050 */ lwz         r0, 0x50(r3)
  /* 805330F4 2C000000 */ cmpwi       r0, 0x0
  /* 805330F8 41820094 */ beq-        lbl_8053318c
  /* 805330FC 3C60809C */ lis         r3, spInstance__Q26System10RaceConfig@ha
  /* 80533100 8063D728 */ lwz         r3, spInstance__Q26System10RaceConfig@l(r3)
  /* 80533104 80030B68 */ lwz         r0, 0xb68(r3)
  /* 80533108 2C000020 */ cmpwi       r0, 0x20
  /* 8053310C 40820080 */ bne-        lbl_8053318c
  /* 80533110 3C608089 */ lis         r3, lbl_80890150@ha
  /* 80533114 C0230150 */ lfs         f1, lbl_80890150@l(r3)
  /* 80533118 482F82BD */ bl          unk_8082b3d4
  /* 8053311C 801E0020 */ lwz         r0, 0x20(r30)
  /* 80533120 FFE00850 */ fneg        f31, f1
  /* 80533124 C01E0044 */ lfs         f0, 0x44(r30)
  /* 80533128 5400073E */ clrlwi      r0, r0, 0x1c
  /* 8053312C 2800000F */ cmplwi      r0, 0xf
  /* 80533130 EFC0F828 */ fsubs       f30, f0, f31
  /* 80533134 40820058 */ bne-        lbl_8053318c
  /* 80533138 482F82E9 */ bl          unk_8082b420
  /* 8053313C 3FE08089 */ lis         r31, lbl_80890158@ha
  /* 80533140 FC200850 */ fneg        f1, f1
  /* 80533144 C01F0158 */ lfs         f0, lbl_80890158@l(r31)
  /* 80533148 EC000072 */ fmuls       f0, f0, f1
  /* 8053314C FC1E0040 */ opword      0xfc1e0040
  /* 80533150 41800018 */ blt-        lbl_80533168
  /* 80533154 482F82CD */ bl          unk_8082b420
  /* 80533158 C01F0158 */ lfs         f0, lbl_80890158@l(r31)
  /* 8053315C EC000072 */ fmuls       f0, f0, f1
  /* 80533160 FC1E0040 */ opword      0xfc1e0040
  /* 80533164 40810028 */ ble-        lbl_8053318c
  lbl_80533168:
  /* 80533168 C01E0044 */ lfs         f0, 0x44(r30)
  /* 8053316C FC00F840 */ opword      0xfc00f840
  /* 80533170 40800010 */ bge-        lbl_80533180
  /* 80533174 38000001 */ li          r0, 0x1
  /* 80533178 981E0048 */ stb         r0, 0x48(r30)
  /* 8053317C 4800000C */ b           lbl_80533188
  lbl_80533180:
  /* 80533180 38000000 */ li          r0, 0x0
  /* 80533184 981E0048 */ stb         r0, 0x48(r30)
  lbl_80533188:
  /* 80533188 D3FE0044 */ stfs        f31, 0x44(r30)
  lbl_8053318c:
  /* 8053318C E3E10028 */ opword      0xe3e10028
  /* 80533190 CBE10020 */ lfd         f31, 0x20(r1)
  /* 80533194 E3C10018 */ opword      0xe3c10018
  /* 80533198 CBC10010 */ lfd         f30, 0x10(r1)
  /* 8053319C 83E1000C */ lwz         r31, 0xc(r1)
  /* 805331A0 80010034 */ lwz         r0, 0x34(r1)
  /* 805331A4 83C10008 */ lwz         r30, 8(r1)
  /* 805331A8 7C0803A6 */ mtlr        r0
  /* 805331AC 38210030 */ addi        r1, r1, 0x30
  /* 805331B0 4E800020 */ blr // clang-format on
}

// Symbol: RaceInfo_update
// PAL: 0x805331b4..0x805336a0
MARK_BINARY_BLOB(RaceInfo_update, 0x805331b4, 0x805336a0);
asm UNKNOWN_FUNCTION(RaceInfo_update) {
  // clang-format off
  nofralloc
  /* 805331B4 9421FFC0 */ stwu        r1, -0x40(r1)
  /* 805331B8 7C0802A6 */ mflr        r0
  /* 805331BC 90010044 */ stw         r0, 0x44(r1)
  /* 805331C0 DBE10030 */ stfd        f31, 0x30(r1)
  /* 805331C4 F3E10038 */ opword      0xf3e10038
  /* 805331C8 DBC10020 */ stfd        f30, 0x20(r1)
  /* 805331CC F3C10028 */ opword      0xf3c10028
  /* 805331D0 93E1001C */ stw         r31, 0x1c(r1)
  /* 805331D4 7C7F1B78 */ mr          r31, r3
  /* 805331D8 93C10018 */ stw         r30, 0x18(r1)
  /* 805331DC 93A10014 */ stw         r29, 0x14(r1)
  /* 805331E0 80630014 */ lwz         r3, 0x14(r3)
  /* 805331E4 81830000 */ lwz         r12, 0(r3)
  /* 805331E8 818C0010 */ lwz         r12, 0x10(r12)
  /* 805331EC 7D8903A6 */ mtctr       r12
  /* 805331F0 4E800421 */ bctrl
  /* 805331F4 3BA00000 */ li          r29, 0x0
  /* 805331F8 3FC0809C */ lis         r30, spInstance__Q26System10RaceConfig@ha
  /* 805331FC 48000018 */ b           lbl_80533214
  lbl_80533200:
  /* 80533200 807F000C */ lwz         r3, 0xc(r31)
  /* 80533204 57A015BA */ rlwinm      r0, r29, 2, 0x16, 0x1d
  /* 80533208 7C63002E */ lwzx        r3, r3, r0
  /* 8053320C 480020F9 */ bl          RaceinfoPlayer_update
  /* 80533210 3BBD0001 */ addi        r29, r29, 0x1
  lbl_80533214:
  /* 80533214 807ED728 */ lwz         r3, spInstance__Q26System10RaceConfig@l(r30)
  /* 80533218 57A4063E */ clrlwi      r4, r29, 0x18
  /* 8053321C 88030024 */ lbz         r0, 0x24(r3)
  /* 80533220 7C040040 */ cmplw       r4, r0
  /* 80533224 4180FFDC */ blt+        lbl_80533200
  /* 80533228 807F0010 */ lwz         r3, 0x10(r31)
  /* 8053322C 81830000 */ lwz         r12, 0(r3)
  /* 80533230 818C0010 */ lwz         r12, 0x10(r12)
  /* 80533234 7D8903A6 */ mtctr       r12
  /* 80533238 4E800421 */ bctrl
  /* 8053323C 807F0040 */ lwz         r3, 0x40(r31)
  /* 80533240 4BFFA649 */ bl          unk_8052d888
  /* 80533244 3C60809C */ lis         r3, lbl_809c4330@ha
  /* 80533248 80634330 */ lwz         r3, lbl_809c4330@l(r3)
  /* 8053324C 80030050 */ lwz         r0, 0x50(r3)
  /* 80533250 2C000000 */ cmpwi       r0, 0x0
  /* 80533254 41820090 */ beq-        lbl_805332e4
  /* 80533258 807ED728 */ lwz         r3, spInstance__Q26System10RaceConfig@l(r30)
  /* 8053325C 80030B68 */ lwz         r0, 0xb68(r3)
  /* 80533260 2C000020 */ cmpwi       r0, 0x20
  /* 80533264 40820080 */ bne-        lbl_805332e4
  /* 80533268 3C608089 */ lis         r3, lbl_80890150@ha
  /* 8053326C C0230150 */ lfs         f1, lbl_80890150@l(r3)
  /* 80533270 482F8165 */ bl          unk_8082b3d4
  /* 80533274 801F0020 */ lwz         r0, 0x20(r31)
  /* 80533278 FFC00850 */ fneg        f30, f1
  /* 8053327C C01F0044 */ lfs         f0, 0x44(r31)
  /* 80533280 5400073E */ clrlwi      r0, r0, 0x1c
  /* 80533284 2800000F */ cmplwi      r0, 0xf
  /* 80533288 EFE0F028 */ fsubs       f31, f0, f30
  /* 8053328C 40820058 */ bne-        lbl_805332e4
  /* 80533290 482F8191 */ bl          unk_8082b420
  /* 80533294 3FC08089 */ lis         r30, lbl_80890158@ha
  /* 80533298 FC200850 */ fneg        f1, f1
  /* 8053329C C01E0158 */ lfs         f0, lbl_80890158@l(r30)
  /* 805332A0 EC000072 */ fmuls       f0, f0, f1
  /* 805332A4 FC1F0040 */ opword      0xfc1f0040
  /* 805332A8 41800018 */ blt-        lbl_805332c0
  /* 805332AC 482F8175 */ bl          unk_8082b420
  /* 805332B0 C01E0158 */ lfs         f0, lbl_80890158@l(r30)
  /* 805332B4 EC000072 */ fmuls       f0, f0, f1
  /* 805332B8 FC1F0040 */ opword      0xfc1f0040
  /* 805332BC 40810028 */ ble-        lbl_805332e4
  lbl_805332c0:
  /* 805332C0 C01F0044 */ lfs         f0, 0x44(r31)
  /* 805332C4 FC00F040 */ opword      0xfc00f040
  /* 805332C8 40800010 */ bge-        lbl_805332d8
  /* 805332CC 38000001 */ li          r0, 0x1
  /* 805332D0 981F0048 */ stb         r0, 0x48(r31)
  /* 805332D4 4800000C */ b           lbl_805332e0
  lbl_805332d8:
  /* 805332D8 38000000 */ li          r0, 0x0
  /* 805332DC 981F0048 */ stb         r0, 0x48(r31)
  lbl_805332e0:
  /* 805332E0 D3DF0044 */ stfs        f30, 0x44(r31)
  lbl_805332e4:
  /* 805332E4 801F0028 */ lwz         r0, 0x28(r31)
  /* 805332E8 2C000001 */ cmpwi       r0, 0x1
  /* 805332EC 4080020C */ bge-        lbl_805334f8
  /* 805332F0 A07F001E */ lhz         r3, 0x1e(r31)
  /* 805332F4 3FC0809C */ lis         r30, spInstance__Q26System10RaceConfig@ha
  /* 805332F8 38030001 */ addi        r0, r3, 0x1
  /* 805332FC B01F001E */ sth         r0, 0x1e(r31)
  /* 80533300 807ED728 */ lwz         r3, spInstance__Q26System10RaceConfig@l(r30)
  /* 80533304 80030B74 */ lwz         r0, 0xb74(r3)
  /* 80533308 2C000005 */ cmpwi       r0, 0x5
  /* 8053330C 40820100 */ bne-        lbl_8053340c
  /* 80533310 3C608038 */ lis         r3, spInstance__Q26System8RKSystem@ha
  /* 80533314 80635FC8 */ lwz         r3, spInstance__Q26System8RKSystem@l(r3)
  /* 80533318 80630054 */ lwz         r3, 0x54(r3)
  /* 8053331C 80630024 */ lwz         r3, 0x24(r3)
  /* 80533320 81830000 */ lwz         r12, 0(r3)
  /* 80533324 818C000C */ lwz         r12, 0xc(r12)
  /* 80533328 7D8903A6 */ mtctr       r12
  /* 8053332C 4E800421 */ bctrl
  /* 80533330 20830001 */ subfic      r4, r3, 0x1
  /* 80533334 3803FFFF */ addi        r0, r3, -0x1
  /* 80533338 7C800378 */ or          r0, r4, r0
  /* 8053333C 54000FFF */ rlwinm.     r0, r0, 1, 0x1f, 0x1f
  /* 80533340 4082022C */ bne-        lbl_8053356c
  /* 80533344 3C60809C */ lis         r3, lbl_809c19b8@ha
  /* 80533348 806319B8 */ lwz         r3, lbl_809c19b8@l(r3)
  /* 8053334C 88030024 */ lbz         r0, 0x24(r3)
  /* 80533350 2C000000 */ cmpwi       r0, 0x0
  /* 80533354 40820010 */ bne-        lbl_80533364
  /* 80533358 881F002C */ lbz         r0, 0x2c(r31)
  /* 8053335C 2C000000 */ cmpwi       r0, 0x0
  /* 80533360 41820044 */ beq-        lbl_805333a4
  lbl_80533364:
  /* 80533364 3C60809C */ lis         r3, spInstance__Q26System10RaceConfig@ha
  /* 80533368 38000000 */ li          r0, 0x0
  /* 8053336C 8063D728 */ lwz         r3, spInstance__Q26System10RaceConfig@l(r3)
  /* 80533370 3FC0809C */ lis         r30, lbl_809c1e38@ha
  /* 80533374 90031764 */ stw         r0, 0x1764(r3)
  /* 80533378 83BE1E38 */ lwz         r29, lbl_809c1e38@l(r30)
  /* 8053337C 4832CDA9 */ bl          unk_80860124
  /* 80533380 7C641B78 */ mr          r4, r3
  /* 80533384 7FA3EB78 */ mr          r3, r29
  /* 80533388 38A00000 */ li          r5, 0x0
  /* 8053338C 481026B1 */ bl          SectionManager_setNextSection
  /* 80533390 807E1E38 */ lwz         r3, lbl_809c1e38@l(r30)
  /* 80533394 38800000 */ li          r4, 0x0
  /* 80533398 38A000FF */ li          r5, 0xff
  /* 8053339C 48102791 */ bl          SectionManager_startReinit
  /* 805333A0 480001CC */ b           lbl_8053356c
  lbl_805333a4:
  /* 805333A4 A01F001E */ lhz         r0, 0x1e(r31)
  /* 805333A8 2800003C */ cmplwi      r0, 0x3c
  /* 805333AC 408101C0 */ ble-        lbl_8053356c
  /* 805333B0 807ED728 */ lwz         r3, spInstance__Q26System10RaceConfig@l(r30)
  /* 805333B4 38C00000 */ li          r6, 0x0
  /* 805333B8 88830024 */ lbz         r4, 0x24(r3)
  /* 805333BC 48000040 */ b           lbl_805333fc
  lbl_805333c0:
  /* 805333C0 807F000C */ lwz         r3, 0xc(r31)
  /* 805333C4 54C015BA */ rlwinm      r0, r6, 2, 0x16, 0x1d
  /* 805333C8 7C63002E */ lwzx        r3, r3, r0
  /* 805333CC 80A30048 */ lwz         r5, 0x48(r3)
  /* 805333D0 2C050000 */ cmpwi       r5, 0x0
  /* 805333D4 41820024 */ beq-        lbl_805333f8
  /* 805333D8 A065005C */ lhz         r3, 0x5c(r5)
  /* 805333DC A0050090 */ lhz         r0, 0x90(r5)
  /* 805333E0 546307FE */ clrlwi      r3, r3, 0x1f
  /* 805333E4 7C600079 */ andc.       r0, r3, r0
  /* 805333E8 41820010 */ beq-        lbl_805333f8
  /* 805333EC 38000001 */ li          r0, 0x1
  /* 805333F0 981F002C */ stb         r0, 0x2c(r31)
  /* 805333F4 48000178 */ b           lbl_8053356c
  lbl_805333f8:
  /* 805333F8 38C60001 */ addi        r6, r6, 0x1
  lbl_805333fc:
  /* 805333FC 54C0063E */ clrlwi      r0, r6, 0x18
  /* 80533400 7C002040 */ cmplw       r0, r4
  /* 80533404 4180FFBC */ blt+        lbl_805333c0
  /* 80533408 48000164 */ b           lbl_8053356c
  lbl_8053340c:
  /* 8053340C 881F002E */ lbz         r0, 0x2e(r31)
  /* 80533410 2C000000 */ cmpwi       r0, 0x0
  /* 80533414 41820158 */ beq-        lbl_8053356c
  /* 80533418 881F002F */ lbz         r0, 0x2f(r31)
  /* 8053341C 2C000000 */ cmpwi       r0, 0x0
  /* 80533420 40820018 */ bne-        lbl_80533438
  /* 80533424 3C60809C */ lis         r3, lbl_809c19b8@ha
  /* 80533428 806319B8 */ lwz         r3, lbl_809c19b8@l(r3)
  /* 8053342C 48075B91 */ bl          unk_805a8fbc
  /* 80533430 2C030000 */ cmpwi       r3, 0x0
  /* 80533434 41820138 */ beq-        lbl_8053356c
  lbl_80533438:
  /* 80533438 807F0010 */ lwz         r3, 0x10(r31)
  /* 8053343C 81830000 */ lwz         r12, 0(r3)
  /* 80533440 818C0020 */ lwz         r12, 0x20(r12)
  /* 80533444 7D8903A6 */ mtctr       r12
  /* 80533448 4E800421 */ bctrl
  /* 8053344C 3C60809C */ lis         r3, spInstance__Q26System12KPadDirector@ha
  /* 80533450 8063D70C */ lwz         r3, spInstance__Q26System12KPadDirector@l(r3)
  /* 80533454 4BFF112D */ bl          startGhostProxies__Q26System12KPadDirectorFv
  /* 80533458 3C80809C */ lis         r4, spInstance__Q26System10RaceConfig@ha
  /* 8053345C 38600000 */ li          r3, 0x0
  /* 80533460 8084D728 */ lwz         r4, spInstance__Q26System10RaceConfig@l(r4)
  /* 80533464 80040B70 */ lwz         r0, 0xb70(r4)
  /* 80533468 2C000007 */ cmpwi       r0, 0x7
  /* 8053346C 41800010 */ blt-        lbl_8053347c
  /* 80533470 2C00000A */ cmpwi       r0, 0xa
  /* 80533474 41810008 */ bgt-        lbl_8053347c
  /* 80533478 38600001 */ li          r3, 0x1
  lbl_8053347c:
  /* 8053347C 2C030000 */ cmpwi       r3, 0x0
  /* 80533480 41820020 */ beq-        lbl_805334a0
  /* 80533484 3FC0809C */ lis         r30, spInstance__Q26System12KPadDirector@ha
  /* 80533488 807ED70C */ lwz         r3, spInstance__Q26System12KPadDirector@l(r30)
  /* 8053348C 4BFF0121 */ bl          resetPlayersActivityStatus__Q26System12KPadDirectorFv
  /* 80533490 807ED70C */ lwz         r3, spInstance__Q26System12KPadDirector@l(r30)
  /* 80533494 38000001 */ li          r0, 0x1
  /* 80533498 98034156 */ stb         r0, 0x4156(r3)
  /* 8053349C 48000014 */ b           lbl_805334b0
  lbl_805334a0:
  /* 805334A0 3C60809C */ lis         r3, spInstance__Q26System12KPadDirector@ha
  /* 805334A4 38000000 */ li          r0, 0x0
  /* 805334A8 8063D70C */ lwz         r3, spInstance__Q26System12KPadDirector@l(r3)
  /* 805334AC 98034156 */ stb         r0, 0x4156(r3)
  lbl_805334b0:
  /* 805334B0 38000001 */ li          r0, 0x1
  /* 805334B4 901F0028 */ stw         r0, 0x28(r31)
  /* 805334B8 3C80809C */ lis         r4, spInstance__Q26System10RaceConfig@ha
  /* 805334BC 8064D728 */ lwz         r3, spInstance__Q26System10RaceConfig@l(r4)
  /* 805334C0 80630B74 */ lwz         r3, 0xb74(r3)
  /* 805334C4 2C030002 */ cmpwi       r3, 0x2
  /* 805334C8 41800024 */ blt-        lbl_805334ec
  /* 805334CC 2C030004 */ cmpwi       r3, 0x4
  /* 805334D0 4181001C */ bgt-        lbl_805334ec
  /* 805334D4 807F0014 */ lwz         r3, 0x14(r31)
  /* 805334D8 98030041 */ stb         r0, 0x41(r3)
  /* 805334DC 8064D728 */ lwz         r3, spInstance__Q26System10RaceConfig@l(r4)
  /* 805334E0 4BFFEAA1 */ bl          loadNextCourse__Q26System10RaceConfigFv
  /* 805334E4 38000002 */ li          r0, 0x2
  /* 805334E8 901F0028 */ stw         r0, 0x28(r31)
  lbl_805334ec:
  /* 805334EC 38000000 */ li          r0, 0x0
  /* 805334F0 901F0020 */ stw         r0, 0x20(r31)
  /* 805334F4 48000078 */ b           lbl_8053356c
  lbl_805334f8:
  /* 805334F8 809F0020 */ lwz         r4, 0x20(r31)
  /* 805334FC 387F0034 */ addi        r3, r31, 0x34
  /* 80533500 38040001 */ addi        r0, r4, 0x1
  /* 80533504 901F0020 */ stw         r0, 0x20(r31)
  /* 80533508 4801D205 */ bl          unk_8055070c
  /* 8053350C 801F0028 */ lwz         r0, 0x28(r31)
  /* 80533510 2C000002 */ cmpwi       r0, 0x2
  /* 80533514 40800058 */ bge-        lbl_8053356c
  /* 80533518 3C60809C */ lis         r3, spInstance__Q26System10RaceConfig@ha
  /* 8053351C 8063D728 */ lwz         r3, spInstance__Q26System10RaceConfig@l(r3)
  /* 80533520 80030B70 */ lwz         r0, 0xb70(r3)
  /* 80533524 2C00000B */ cmpwi       r0, 0xb
  /* 80533528 41800014 */ blt-        lbl_8053353c
  /* 8053352C 2C00000C */ cmpwi       r0, 0xc
  /* 80533530 4181000C */ bgt-        lbl_8053353c
  /* 80533534 38000000 */ li          r0, 0x0
  /* 80533538 4800000C */ b           lbl_80533544
  lbl_8053353c:
  /* 8053353C 801F0020 */ lwz         r0, 0x20(r31)
  /* 80533540 200000F0 */ subfic      r0, r0, 0xf0
  lbl_80533544:
  /* 80533544 2C000000 */ cmpwi       r0, 0x0
  /* 80533548 41810024 */ bgt-        lbl_8053356c
  /* 8053354C 809F0014 */ lwz         r4, 0x14(r31)
  /* 80533550 38000001 */ li          r0, 0x1
  /* 80533554 3C60809C */ lis         r3, spInstance__Q26System10RaceConfig@ha
  /* 80533558 98040041 */ stb         r0, 0x41(r4)
  /* 8053355C 8063D728 */ lwz         r3, spInstance__Q26System10RaceConfig@l(r3)
  /* 80533560 4BFFEA21 */ bl          loadNextCourse__Q26System10RaceConfigFv
  /* 80533564 38000002 */ li          r0, 0x2
  /* 80533568 901F0028 */ stw         r0, 0x28(r31)
  lbl_8053356c:
  /* 8053356C 881F002D */ lbz         r0, 0x2d(r31)
  /* 80533570 2C000000 */ cmpwi       r0, 0x0
  /* 80533574 418200EC */ beq-        lbl_80533660
  /* 80533578 801F0028 */ lwz         r0, 0x28(r31)
  /* 8053357C 2C000001 */ cmpwi       r0, 0x1
  /* 80533580 408000C0 */ bge-        lbl_80533640
  /* 80533584 807F0010 */ lwz         r3, 0x10(r31)
  /* 80533588 81830000 */ lwz         r12, 0(r3)
  /* 8053358C 818C0020 */ lwz         r12, 0x20(r12)
  /* 80533590 7D8903A6 */ mtctr       r12
  /* 80533594 4E800421 */ bctrl
  /* 80533598 3C60809C */ lis         r3, spInstance__Q26System12KPadDirector@ha
  /* 8053359C 8063D70C */ lwz         r3, spInstance__Q26System12KPadDirector@l(r3)
  /* 805335A0 4BFF0FE1 */ bl          startGhostProxies__Q26System12KPadDirectorFv
  /* 805335A4 3C80809C */ lis         r4, spInstance__Q26System10RaceConfig@ha
  /* 805335A8 38600000 */ li          r3, 0x0
  /* 805335AC 8084D728 */ lwz         r4, spInstance__Q26System10RaceConfig@l(r4)
  /* 805335B0 80040B70 */ lwz         r0, 0xb70(r4)
  /* 805335B4 2C000007 */ cmpwi       r0, 0x7
  /* 805335B8 41800010 */ blt-        lbl_805335c8
  /* 805335BC 2C00000A */ cmpwi       r0, 0xa
  /* 805335C0 41810008 */ bgt-        lbl_805335c8
  /* 805335C4 38600001 */ li          r3, 0x1
  lbl_805335c8:
  /* 805335C8 2C030000 */ cmpwi       r3, 0x0
  /* 805335CC 41820020 */ beq-        lbl_805335ec
  /* 805335D0 3FC0809C */ lis         r30, spInstance__Q26System12KPadDirector@ha
  /* 805335D4 807ED70C */ lwz         r3, spInstance__Q26System12KPadDirector@l(r30)
  /* 805335D8 4BFEFFD5 */ bl          resetPlayersActivityStatus__Q26System12KPadDirectorFv
  /* 805335DC 807ED70C */ lwz         r3, spInstance__Q26System12KPadDirector@l(r30)
  /* 805335E0 38000001 */ li          r0, 0x1
  /* 805335E4 98034156 */ stb         r0, 0x4156(r3)
  /* 805335E8 48000014 */ b           lbl_805335fc
  lbl_805335ec:
  /* 805335EC 3C60809C */ lis         r3, spInstance__Q26System12KPadDirector@ha
  /* 805335F0 38000000 */ li          r0, 0x0
  /* 805335F4 8063D70C */ lwz         r3, spInstance__Q26System12KPadDirector@l(r3)
  /* 805335F8 98034156 */ stb         r0, 0x4156(r3)
  lbl_805335fc:
  /* 805335FC 38000001 */ li          r0, 0x1
  /* 80533600 901F0028 */ stw         r0, 0x28(r31)
  /* 80533604 3C80809C */ lis         r4, spInstance__Q26System10RaceConfig@ha
  /* 80533608 8064D728 */ lwz         r3, spInstance__Q26System10RaceConfig@l(r4)
  /* 8053360C 80630B74 */ lwz         r3, 0xb74(r3)
  /* 80533610 2C030002 */ cmpwi       r3, 0x2
  /* 80533614 41800024 */ blt-        lbl_80533638
  /* 80533618 2C030004 */ cmpwi       r3, 0x4
  /* 8053361C 4181001C */ bgt-        lbl_80533638
  /* 80533620 807F0014 */ lwz         r3, 0x14(r31)
  /* 80533624 98030041 */ stb         r0, 0x41(r3)
  /* 80533628 8064D728 */ lwz         r3, spInstance__Q26System10RaceConfig@l(r4)
  /* 8053362C 4BFFE955 */ bl          loadNextCourse__Q26System10RaceConfigFv
  /* 80533630 38000002 */ li          r0, 0x2
  /* 80533634 901F0028 */ stw         r0, 0x28(r31)
  lbl_80533638:
  /* 80533638 38000000 */ li          r0, 0x0
  /* 8053363C 901F0020 */ stw         r0, 0x20(r31)
  lbl_80533640:
  /* 80533640 3C60809C */ lis         r3, lbl_809c1f50@ha
  /* 80533644 80631F50 */ lwz         r3, lbl_809c1f50@l(r3)
  /* 80533648 48120F95 */ bl          unk_806545dc
  /* 8053364C 801F0020 */ lwz         r0, 0x20(r31)
  /* 80533650 7C001840 */ cmplw       r0, r3
  /* 80533654 4081000C */ ble-        lbl_80533660
  /* 80533658 38000000 */ li          r0, 0x0
  /* 8053365C 981F002D */ stb         r0, 0x2d(r31)
  lbl_80533660:
  /* 80533660 801F0028 */ lwz         r0, 0x28(r31)
  /* 80533664 2C000003 */ cmpwi       r0, 0x3
  /* 80533668 4180000C */ blt-        lbl_80533674
  /* 8053366C 38000004 */ li          r0, 0x4
  /* 80533670 901F0028 */ stw         r0, 0x28(r31)
  lbl_80533674:
  /* 80533674 E3E10038 */ opword      0xe3e10038
  /* 80533678 CBE10030 */ lfd         f31, 0x30(r1)
  /* 8053367C E3C10028 */ opword      0xe3c10028
  /* 80533680 CBC10020 */ lfd         f30, 0x20(r1)
  /* 80533684 83E1001C */ lwz         r31, 0x1c(r1)
  /* 80533688 83C10018 */ lwz         r30, 0x18(r1)
  /* 8053368C 80010044 */ lwz         r0, 0x44(r1)
  /* 80533690 83A10014 */ lwz         r29, 0x14(r1)
  /* 80533694 7C0803A6 */ mtlr        r0
  /* 80533698 38210040 */ addi        r1, r1, 0x40
  /* 8053369C 4E800020 */ blr // clang-format on
}

// Symbol: unk_805336a0
// PAL: 0x805336a0..0x805336a4
MARK_BINARY_BLOB(unk_805336a0, 0x805336a0, 0x805336a4);
asm UNKNOWN_FUNCTION(unk_805336a0){
    // clang-format off
  nofralloc
  /* 805336A0 4E800020 */ blr // clang-format on
}

// Symbol: getLapCount
// PAL: 0x805336a4..0x805336d8
MARK_BINARY_BLOB(getLapCount, 0x805336a4, 0x805336d8);
asm UNKNOWN_FUNCTION(getLapCount) {
  // clang-format off
  nofralloc
  /* 805336A4 3C80809C */ lis         r4, spInstance__Q26System10RaceConfig@ha
  /* 805336A8 38600003 */ li          r3, 0x3
  /* 805336AC 8084D728 */ lwz         r4, spInstance__Q26System10RaceConfig@l(r4)
  /* 805336B0 80040B90 */ lwz         r0, 0xb90(r4)
  /* 805336B4 5400077B */ rlwinm.     r0, r0, 0, 0x1d, 0x1d
  /* 805336B8 4D820020 */ beqlr-
  /* 805336BC 88640B8D */ lbz         r3, 0xb8d(r4)
  /* 805336C0 380300FF */ addi        r0, r3, 0xff
  /* 805336C4 5400063E */ clrlwi      r0, r0, 0x18
  /* 805336C8 28000008 */ cmplwi      r0, 8
  /* 805336CC 4C810020 */ blelr-
  /* 805336D0 38600003 */ li          r3, 0x3
  /* 805336D4 4E800020 */ blr // clang-format on
}

// Symbol: unk_805336d8
// PAL: 0x805336d8..0x80533afc
MARK_BINARY_BLOB(unk_805336d8, 0x805336d8, 0x80533afc);
asm UNKNOWN_FUNCTION(unk_805336d8) {
  // clang-format off
  nofralloc
  /* 805336D8 9421FF40 */ stwu        r1, -0xc0(r1)
  /* 805336DC 7C0802A6 */ mflr        r0
  /* 805336E0 900100C4 */ stw         r0, 0xc4(r1)
  /* 805336E4 396100C0 */ addi        r11, r1, 0xc0
  /* 805336E8 4BAEDE99 */ bl          _savegpr_19
  /* 805336EC 3C80809C */ lis         r4, spInstance__Q26System10RaceConfig@ha
  /* 805336F0 3CC08089 */ lis         r6, lbl_80890170@ha
  /* 805336F4 80E4D728 */ lwz         r7, spInstance__Q26System10RaceConfig@l(r4)
  /* 805336F8 3C80809C */ lis         r4, spInstance__Q26System11RaceManager@ha
  /* 805336FC 3CA08089 */ lis         r5, lbl_80890160@ha
  /* 80533700 3D008089 */ lis         r8, lbl_80890168@ha
  /* 80533704 8BE70024 */ lbz         r31, 0x24(r7)
  /* 80533708 38E10018 */ addi        r7, r1, 0x18
  /* 8053370C C8860170 */ lfd         f4, lbl_80890170@l(r6)
  /* 80533710 38C10008 */ addi        r6, r1, 0x8
  /* 80533714 C8650160 */ lfd         f3, lbl_80890160@l(r5)
  /* 80533718 38A00000 */ li          r5, 0x0
  /* 8053371C 8084D730 */ lwz         r4, spInstance__Q26System11RaceManager@l(r4)
  /* 80533720 3D404330 */ lis         r10, 0x4330
  /* 80533724 C8280168 */ lfd         f1, lbl_80890168@l(r8)
  /* 80533728 480000E0 */ b           lbl_80533808
  lbl_8053372c:
  /* 8053372C 81230004 */ lwz         r9, 4(r3)
  /* 80533730 54A015BA */ rlwinm      r0, r5, 2, 0x16, 0x1d
  /* 80533734 8104000C */ lwz         r8, 0xc(r4)
  /* 80533738 8129000C */ lwz         r9, 0xc(r9)
  /* 8053373C 7D68002E */ lwzx        r11, r8, r0
  /* 80533740 7D29002E */ lwzx        r9, r9, r0
  /* 80533744 800B0038 */ lwz         r0, 0x38(r11)
  /* 80533748 89090020 */ lbz         r8, 0x20(r9)
  /* 8053374C 540007BD */ rlwinm.     r0, r0, 0, 0x1e, 0x1e
  /* 80533750 7D080774 */ extsb       r8, r8
  /* 80533754 3A88FFFF */ addi        r20, r8, -0x1
  /* 80533758 4182009C */ beq-        lbl_805337f4
  /* 8053375C 810B0040 */ lwz         r8, 0x40(r11)
  /* 80533760 38000063 */ li          r0, 0x63
  /* 80533764 A1680004 */ lhz         r11, 4(r8)
  /* 80533768 89880006 */ lbz         r12, 6(r8)
  /* 8053376C 280B0063 */ cmplwi      r11, 0x63
  /* 80533770 A2680008 */ lhz         r19, 8(r8)
  /* 80533774 41810008 */ bgt-        lbl_8053377c
  /* 80533778 7D605B78 */ mr          r0, r11
  lbl_8053377c:
  /* 8053377C 280B0063 */ cmplwi      r11, 0x63
  /* 80533780 5409063E */ clrlwi      r9, r0, 0x18
  /* 80533784 3900003B */ li          r8, 0x3b
  /* 80533788 41810008 */ bgt-        lbl_80533790
  /* 8053378C 7D886378 */ mr          r8, r12
  lbl_80533790:
  /* 80533790 54A0063E */ clrlwi      r0, r5, 0x18
  /* 80533794 9001007C */ stw         r0, 0x7c(r1)
  /* 80533798 280B0063 */ cmplwi      r11, 0x63
  /* 8053379C 550B063E */ clrlwi      r11, r8, 0x18
  /* 805337A0 91410078 */ stw         r10, 0x78(r1)
  /* 805337A4 380003E7 */ li          r0, 0x3e7
  /* 805337A8 C8010078 */ lfd         f0, 0x78(r1)
  /* 805337AC FC002028 */ fsub        f0, f0, f4
  /* 805337B0 FC430032 */ fmul        f2, f3, f0
  /* 805337B4 41810008 */ bgt-        lbl_805337bc
  /* 805337B8 7E609B78 */ mr          r0, r19
  lbl_805337bc:
  /* 805337BC 1D09003C */ mulli       r8, r9, 0x3c
  /* 805337C0 5409043E */ clrlwi      r9, r0, 0x10
  /* 805337C4 91410080 */ stw         r10, 0x80(r1)
  /* 805337C8 56801838 */ slwi        r0, r20, 3
  /* 805337CC 7D0B4214 */ add         r8, r11, r8
  /* 805337D0 1D0803E8 */ mulli       r8, r8, 0x3e8
  /* 805337D4 7D094214 */ add         r8, r9, r8
  /* 805337D8 91010084 */ stw         r8, 0x84(r1)
  /* 805337DC C8010080 */ lfd         f0, 0x80(r1)
  /* 805337E0 FC002028 */ fsub        f0, f0, f4
  /* 805337E4 FC010028 */ fsub        f0, f1, f0
  /* 805337E8 FC02002A */ fadd        f0, f2, f0
  /* 805337EC 7C0705AE */ stfdx       f0, r7, r0
  /* 805337F0 48000010 */ b           lbl_80533800
  lbl_805337f4:
  /* 805337F4 56801838 */ slwi        r0, r20, 3
  /* 805337F8 C009000C */ lfs         f0, 0xc(r9)
  /* 805337FC 7C0705AE */ stfdx       f0, r7, r0
  lbl_80533800:
  /* 80533800 7CA6A1AE */ stbx        r5, r6, r20
  /* 80533804 38A50001 */ addi        r5, r5, 0x1
  lbl_80533808:
  /* 80533808 54A0063E */ clrlwi      r0, r5, 0x18
  /* 8053380C 7C00F800 */ cmpw        r0, r31
  /* 80533810 4180FF1C */ blt+        lbl_8053372c
  /* 80533814 381FFFFF */ addi        r0, r31, -0x1
  /* 80533818 38E10020 */ addi        r7, r1, 0x20
  /* 8053381C 39010009 */ addi        r8, r1, 0x9
  /* 80533820 38C10018 */ addi        r6, r1, 0x18
  /* 80533824 38A10008 */ addi        r5, r1, 0x8
  /* 80533828 39600001 */ li          r11, 0x1
  /* 8053382C 38800008 */ li          r4, 0x8
  /* 80533830 7C0903A6 */ mtctr       r0
  /* 80533834 2C1F0001 */ cmpwi       r31, 0x1
  /* 80533838 40810074 */ ble-        lbl_805338ac
  lbl_8053383c:
  /* 8053383C 39210018 */ addi        r9, r1, 0x18
  /* 80533840 39410008 */ addi        r10, r1, 0x8
  /* 80533844 C8270000 */ lfd         f1, 0(r7)
  /* 80533848 7D6C5B78 */ mr          r12, r11
  /* 8053384C 8A680000 */ lbz         r19, 0(r8)
  /* 80533850 7D292214 */ add         r9, r9, r4
  /* 80533854 7D4A5A14 */ add         r10, r10, r11
  /* 80533858 48000020 */ b           lbl_80533878
  lbl_8053385c:
  /* 8053385C C809FFF8 */ lfd         f0, -8(r9)
  /* 80533860 398CFFFF */ addi        r12, r12, -0x1
  /* 80533864 880AFFFF */ lbz         r0, -1(r10)
  /* 80533868 D8090000 */ stfd        f0, 0(r9)
  /* 8053386C 3929FFF8 */ addi        r9, r9, -0x8
  /* 80533870 980A0000 */ stb         r0, 0(r10)
  /* 80533874 394AFFFF */ addi        r10, r10, -0x1
  lbl_80533878:
  /* 80533878 2C0C0000 */ cmpwi       r12, 0x0
  /* 8053387C 40810010 */ ble-        lbl_8053388c
  /* 80533880 C809FFF8 */ lfd         f0, -8(r9)
  /* 80533884 FC000840 */ opword      0xfc000840
  /* 80533888 4180FFD4 */ blt+        lbl_8053385c
  lbl_8053388c:
  /* 8053388C 55801838 */ slwi        r0, r12, 3
  /* 80533890 7E6561AE */ stbx        r19, r5, r12
  /* 80533894 396B0001 */ addi        r11, r11, 0x1
  /* 80533898 38840008 */ addi        r4, r4, 0x8
  /* 8053389C 7C2605AE */ stfdx       f1, r6, r0
  /* 805338A0 38E70008 */ addi        r7, r7, 0x8
  /* 805338A4 39080001 */ addi        r8, r8, 0x1
  /* 805338A8 4200FF94 */ bdnz        lbl_8053383c
  lbl_805338ac:
  /* 805338AC 2C1F0000 */ cmpwi       r31, 0x0
  /* 805338B0 3BC00000 */ li          r30, 0x0
  /* 805338B4 40810230 */ ble-        lbl_80533ae4
  /* 805338B8 281F0008 */ cmplwi      r31, 8
  /* 805338BC 38DFFFF8 */ addi        r6, r31, -0x8
  /* 805338C0 408101D8 */ ble-        lbl_80533a98
  /* 805338C4 480001C8 */ b           lbl_80533a8c
  lbl_805338c8:
  /* 805338C8 57C5063E */ clrlwi      r5, r30, 0x18
  /* 805338CC 80830004 */ lwz         r4, 4(r3)
  /* 805338D0 38E10008 */ addi        r7, r1, 0x8
  /* 805338D4 7E8728EE */ lbzux       r20, r7, r5
  /* 805338D8 8104000C */ lwz         r8, 0xc(r4)
  /* 805338DC 3A650001 */ addi        r19, r5, 0x1
  /* 805338E0 5684103A */ slwi        r4, r20, 2
  /* 805338E4 395E0003 */ addi        r10, r30, 0x3
  /* 805338E8 7D28202E */ lwzx        r9, r8, r4
  /* 805338EC 381E0001 */ addi        r0, r30, 0x1
  /* 805338F0 5404063E */ clrlwi      r4, r0, 0x18
  /* 805338F4 554A063E */ clrlwi      r10, r10, 0x18
  /* 805338F8 9A690020 */ stb         r19, 0x20(r9)
  /* 805338FC 39040001 */ addi        r8, r4, 0x1
  /* 80533900 88870002 */ lbz         r4, 2(r7)
  /* 80533904 381E0002 */ addi        r0, r30, 0x2
  /* 80533908 81630004 */ lwz         r11, 4(r3)
  /* 8053390C 5409063E */ clrlwi      r9, r0, 0x18
  /* 80533910 88070003 */ lbz         r0, 3(r7)
  /* 80533914 394A0001 */ addi        r10, r10, 0x1
  /* 80533918 818B0018 */ lwz         r12, 0x18(r11)
  /* 8053391C 5673063E */ clrlwi      r19, r19, 0x18
  /* 80533920 8B270004 */ lbz         r25, 4(r7)
  /* 80533924 397E0004 */ addi        r11, r30, 0x4
  /* 80533928 7D8C9A14 */ add         r12, r12, r19
  /* 8053392C 88A70001 */ lbz         r5, 1(r7)
  /* 80533930 9A8CFFFF */ stb         r20, -1(r12)
  /* 80533934 556B063E */ clrlwi      r11, r11, 0x18
  /* 80533938 396B0001 */ addi        r11, r11, 0x1
  /* 8053393C 399E0005 */ addi        r12, r30, 0x5
  /* 80533940 82630004 */ lwz         r19, 4(r3)
  /* 80533944 558C063E */ clrlwi      r12, r12, 0x18
  /* 80533948 398C0001 */ addi        r12, r12, 0x1
  /* 8053394C 54B4103A */ slwi        r20, r5, 2
  /* 80533950 82D3000C */ lwz         r22, 0xc(r19)
  /* 80533954 5513063E */ clrlwi      r19, r8, 0x18
  /* 80533958 5495103A */ slwi        r21, r4, 2
  /* 8053395C 39290001 */ addi        r9, r9, 0x1
  /* 80533960 7E96A02E */ lwzx        r20, r22, r20
  /* 80533964 5536063E */ clrlwi      r22, r9, 0x18
  /* 80533968 5417103A */ slwi        r23, r0, 2
  /* 8053396C 5558063E */ clrlwi      r24, r10, 0x18
  /* 80533970 99140020 */ stb         r8, 0x20(r20)
  /* 80533974 573A103A */ slwi        r26, r25, 2
  /* 80533978 8B870005 */ lbz         r28, 5(r7)
  /* 8053397C 557B063E */ clrlwi      r27, r11, 0x18
  /* 80533980 82830004 */ lwz         r20, 4(r3)
  /* 80533984 559D063E */ clrlwi      r29, r12, 0x18
  /* 80533988 5788103A */ slwi        r8, r28, 2
  /* 8053398C 82940018 */ lwz         r20, 0x18(r20)
  /* 80533990 7E949A14 */ add         r20, r20, r19
  /* 80533994 98B4FFFF */ stb         r5, -1(r20)
  /* 80533998 80A30004 */ lwz         r5, 4(r3)
  /* 8053399C 80A5000C */ lwz         r5, 0xc(r5)
  /* 805339A0 7CA5A82E */ lwzx        r5, r5, r21
  /* 805339A4 99250020 */ stb         r9, 0x20(r5)
  /* 805339A8 80A30004 */ lwz         r5, 4(r3)
  /* 805339AC 80A50018 */ lwz         r5, 0x18(r5)
  /* 805339B0 7CA5B214 */ add         r5, r5, r22
  /* 805339B4 9885FFFF */ stb         r4, -1(r5)
  /* 805339B8 80830004 */ lwz         r4, 4(r3)
  /* 805339BC 8084000C */ lwz         r4, 0xc(r4)
  /* 805339C0 7C84B82E */ lwzx        r4, r4, r23
  /* 805339C4 99440020 */ stb         r10, 0x20(r4)
  /* 805339C8 80830004 */ lwz         r4, 4(r3)
  /* 805339CC 80840018 */ lwz         r4, 0x18(r4)
  /* 805339D0 7C84C214 */ add         r4, r4, r24
  /* 805339D4 9804FFFF */ stb         r0, -1(r4)
  /* 805339D8 80830004 */ lwz         r4, 4(r3)
  /* 805339DC 8084000C */ lwz         r4, 0xc(r4)
  /* 805339E0 7C84D02E */ lwzx        r4, r4, r26
  /* 805339E4 99640020 */ stb         r11, 0x20(r4)
  /* 805339E8 80830004 */ lwz         r4, 4(r3)
  /* 805339EC 80040018 */ lwz         r0, 0x18(r4)
  /* 805339F0 7C80DA14 */ add         r4, r0, r27
  /* 805339F4 9B24FFFF */ stb         r25, -1(r4)
  /* 805339F8 80830004 */ lwz         r4, 4(r3)
  /* 805339FC 8084000C */ lwz         r4, 0xc(r4)
  /* 80533A00 7C84402E */ lwzx        r4, r4, r8
  /* 80533A04 99840020 */ stb         r12, 0x20(r4)
  /* 80533A08 80A30004 */ lwz         r5, 4(r3)
  /* 80533A0C 389E0006 */ addi        r4, r30, 0x6
  /* 80533A10 381E0007 */ addi        r0, r30, 0x7
  /* 80533A14 89270006 */ lbz         r9, 6(r7)
  /* 80533A18 81050018 */ lwz         r8, 0x18(r5)
  /* 80533A1C 5484063E */ clrlwi      r4, r4, 0x18
  /* 80533A20 88A70007 */ lbz         r5, 7(r7)
  /* 80533A24 39640001 */ addi        r11, r4, 0x1
  /* 80533A28 7CE8EA14 */ add         r7, r8, r29
  /* 80533A2C 5404063E */ clrlwi      r4, r0, 0x18
  /* 80533A30 9B87FFFF */ stb         r28, -1(r7)
  /* 80533A34 39840001 */ addi        r12, r4, 0x1
  /* 80533A38 5524103A */ slwi        r4, r9, 2
  /* 80533A3C 5568063E */ clrlwi      r8, r11, 0x18
  /* 80533A40 81430004 */ lwz         r10, 4(r3)
  /* 80533A44 54A0103A */ slwi        r0, r5, 2
  /* 80533A48 5587063E */ clrlwi      r7, r12, 0x18
  /* 80533A4C 3BDE0008 */ addi        r30, r30, 0x8
  /* 80533A50 814A000C */ lwz         r10, 0xc(r10)
  /* 80533A54 7C8A202E */ lwzx        r4, r10, r4
  /* 80533A58 99640020 */ stb         r11, 0x20(r4)
  /* 80533A5C 80830004 */ lwz         r4, 4(r3)
  /* 80533A60 80840018 */ lwz         r4, 0x18(r4)
  /* 80533A64 7C844214 */ add         r4, r4, r8
  /* 80533A68 9924FFFF */ stb         r9, -1(r4)
  /* 80533A6C 80830004 */ lwz         r4, 4(r3)
  /* 80533A70 8084000C */ lwz         r4, 0xc(r4)
  /* 80533A74 7C84002E */ lwzx        r4, r4, r0
  /* 80533A78 99840020 */ stb         r12, 0x20(r4)
  /* 80533A7C 80830004 */ lwz         r4, 4(r3)
  /* 80533A80 80040018 */ lwz         r0, 0x18(r4)
  /* 80533A84 7C803A14 */ add         r4, r0, r7
  /* 80533A88 98A4FFFF */ stb         r5, -1(r4)
  lbl_80533a8c:
  /* 80533A8C 57C0063E */ clrlwi      r0, r30, 0x18
  /* 80533A90 7C003000 */ cmpw        r0, r6
  /* 80533A94 4180FE34 */ blt+        lbl_805338c8
  lbl_80533a98:
  /* 80533A98 38E10008 */ addi        r7, r1, 0x8
  /* 80533A9C 4800003C */ b           lbl_80533ad8
  lbl_80533aa0:
  /* 80533AA0 57C6063E */ clrlwi      r6, r30, 0x18
  /* 80533AA4 80830004 */ lwz         r4, 4(r3)
  /* 80533AA8 7CA730AE */ lbzx        r5, r7, r6
  /* 80533AAC 39060001 */ addi        r8, r6, 0x1
  /* 80533AB0 8084000C */ lwz         r4, 0xc(r4)
  /* 80533AB4 5506063E */ clrlwi      r6, r8, 0x18
  /* 80533AB8 54A0103A */ slwi        r0, r5, 2
  /* 80533ABC 3BDE0001 */ addi        r30, r30, 0x1
  /* 80533AC0 7C84002E */ lwzx        r4, r4, r0
  /* 80533AC4 99040020 */ stb         r8, 0x20(r4)
  /* 80533AC8 80830004 */ lwz         r4, 4(r3)
  /* 80533ACC 80040018 */ lwz         r0, 0x18(r4)
  /* 80533AD0 7C803214 */ add         r4, r0, r6
  /* 80533AD4 98A4FFFF */ stb         r5, -1(r4)
  lbl_80533ad8:
  /* 80533AD8 57C0063E */ clrlwi      r0, r30, 0x18
  /* 80533ADC 7C00F800 */ cmpw        r0, r31
  /* 80533AE0 4180FFC0 */ blt+        lbl_80533aa0
  lbl_80533ae4:
  /* 80533AE4 396100C0 */ addi        r11, r1, 0xc0
  /* 80533AE8 4BAEDAE5 */ bl          _restgpr_19
  /* 80533AEC 800100C4 */ lwz         r0, 0xc4(r1)
  /* 80533AF0 7C0803A6 */ mtlr        r0
  /* 80533AF4 382100C0 */ addi        r1, r1, 0xc0
  /* 80533AF8 4E800020 */ blr // clang-format on
}

// Symbol: unk_80533afc
// PAL: 0x80533afc..0x80533be8
MARK_BINARY_BLOB(unk_80533afc, 0x80533afc, 0x80533be8);
asm UNKNOWN_FUNCTION(unk_80533afc) {
  // clang-format off
  nofralloc
  /* 80533AFC 9421FFF0 */ stwu        r1, -0x10(r1)
  /* 80533B00 7C0802A6 */ mflr        r0
  /* 80533B04 90010014 */ stw         r0, 0x14(r1)
  /* 80533B08 93E1000C */ stw         r31, 0xc(r1)
  /* 80533B0C 7C7F1B78 */ mr          r31, r3
  /* 80533B10 93C10008 */ stw         r30, 8(r1)
  /* 80533B14 80630010 */ lwz         r3, 0x10(r3)
  /* 80533B18 81830000 */ lwz         r12, 0(r3)
  /* 80533B1C 818C0020 */ lwz         r12, 0x20(r12)
  /* 80533B20 7D8903A6 */ mtctr       r12
  /* 80533B24 4E800421 */ bctrl
  /* 80533B28 3C60809C */ lis         r3, spInstance__Q26System12KPadDirector@ha
  /* 80533B2C 8063D70C */ lwz         r3, spInstance__Q26System12KPadDirector@l(r3)
  /* 80533B30 4BFF0A51 */ bl          startGhostProxies__Q26System12KPadDirectorFv
  /* 80533B34 3C80809C */ lis         r4, spInstance__Q26System10RaceConfig@ha
  /* 80533B38 38600000 */ li          r3, 0x0
  /* 80533B3C 8084D728 */ lwz         r4, spInstance__Q26System10RaceConfig@l(r4)
  /* 80533B40 80040B70 */ lwz         r0, 0xb70(r4)
  /* 80533B44 2C000007 */ cmpwi       r0, 0x7
  /* 80533B48 41800010 */ blt-        lbl_80533b58
  /* 80533B4C 2C00000A */ cmpwi       r0, 0xa
  /* 80533B50 41810008 */ bgt-        lbl_80533b58
  /* 80533B54 38600001 */ li          r3, 0x1
  lbl_80533b58:
  /* 80533B58 2C030000 */ cmpwi       r3, 0x0
  /* 80533B5C 41820020 */ beq-        lbl_80533b7c
  /* 80533B60 3FC0809C */ lis         r30, spInstance__Q26System12KPadDirector@ha
  /* 80533B64 807ED70C */ lwz         r3, spInstance__Q26System12KPadDirector@l(r30)
  /* 80533B68 4BFEFA45 */ bl          resetPlayersActivityStatus__Q26System12KPadDirectorFv
  /* 80533B6C 807ED70C */ lwz         r3, spInstance__Q26System12KPadDirector@l(r30)
  /* 80533B70 38000001 */ li          r0, 0x1
  /* 80533B74 98034156 */ stb         r0, 0x4156(r3)
  /* 80533B78 48000014 */ b           lbl_80533b8c
  lbl_80533b7c:
  /* 80533B7C 3C60809C */ lis         r3, spInstance__Q26System12KPadDirector@ha
  /* 80533B80 38000000 */ li          r0, 0x0
  /* 80533B84 8063D70C */ lwz         r3, spInstance__Q26System12KPadDirector@l(r3)
  /* 80533B88 98034156 */ stb         r0, 0x4156(r3)
  lbl_80533b8c:
  /* 80533B8C 38000001 */ li          r0, 0x1
  /* 80533B90 901F0028 */ stw         r0, 0x28(r31)
  /* 80533B94 3C80809C */ lis         r4, spInstance__Q26System10RaceConfig@ha
  /* 80533B98 8064D728 */ lwz         r3, spInstance__Q26System10RaceConfig@l(r4)
  /* 80533B9C 80630B74 */ lwz         r3, 0xb74(r3)
  /* 80533BA0 2C030002 */ cmpwi       r3, 0x2
  /* 80533BA4 41800024 */ blt-        lbl_80533bc8
  /* 80533BA8 2C030004 */ cmpwi       r3, 0x4
  /* 80533BAC 4181001C */ bgt-        lbl_80533bc8
  /* 80533BB0 807F0014 */ lwz         r3, 0x14(r31)
  /* 80533BB4 98030041 */ stb         r0, 0x41(r3)
  /* 80533BB8 8064D728 */ lwz         r3, spInstance__Q26System10RaceConfig@l(r4)
  /* 80533BBC 4BFFE3C5 */ bl          loadNextCourse__Q26System10RaceConfigFv
  /* 80533BC0 38000002 */ li          r0, 0x2
  /* 80533BC4 901F0028 */ stw         r0, 0x28(r31)
  lbl_80533bc8:
  /* 80533BC8 38000000 */ li          r0, 0x0
  /* 80533BCC 901F0020 */ stw         r0, 0x20(r31)
  /* 80533BD0 83E1000C */ lwz         r31, 0xc(r1)
  /* 80533BD4 83C10008 */ lwz         r30, 8(r1)
  /* 80533BD8 80010014 */ lwz         r0, 0x14(r1)
  /* 80533BDC 7C0803A6 */ mtlr        r0
  /* 80533BE0 38210010 */ addi        r1, r1, 0x10
  /* 80533BE4 4E800020 */ blr // clang-format on
}

// Symbol: unk_80533be8
// PAL: 0x80533be8..0x80533bec
MARK_BINARY_BLOB(unk_80533be8, 0x80533be8, 0x80533bec);
asm UNKNOWN_FUNCTION(unk_80533be8){
    // clang-format off
  nofralloc
  /* 80533BE8 4E800020 */ blr // clang-format on
}

// Symbol: unk_80533bec
// PAL: 0x80533bec..0x80533c34
MARK_BINARY_BLOB(unk_80533bec, 0x80533bec, 0x80533c34);
asm UNKNOWN_FUNCTION(unk_80533bec) {
  // clang-format off
  nofralloc
  /* 80533BEC 9421FFF0 */ stwu        r1, -0x10(r1)
  /* 80533BF0 7C0802A6 */ mflr        r0
  /* 80533BF4 3C80809C */ lis         r4, spInstance__Q26System10RaceConfig@ha
  /* 80533BF8 90010014 */ stw         r0, 0x14(r1)
  /* 80533BFC 38000001 */ li          r0, 0x1
  /* 80533C00 93E1000C */ stw         r31, 0xc(r1)
  /* 80533C04 7C7F1B78 */ mr          r31, r3
  /* 80533C08 80A30014 */ lwz         r5, 0x14(r3)
  /* 80533C0C 98050041 */ stb         r0, 0x41(r5)
  /* 80533C10 8064D728 */ lwz         r3, spInstance__Q26System10RaceConfig@l(r4)
  /* 80533C14 4BFFE36D */ bl          loadNextCourse__Q26System10RaceConfigFv
  /* 80533C18 38000002 */ li          r0, 0x2
  /* 80533C1C 901F0028 */ stw         r0, 0x28(r31)
  /* 80533C20 83E1000C */ lwz         r31, 0xc(r1)
  /* 80533C24 80010014 */ lwz         r0, 0x14(r1)
  /* 80533C28 7C0803A6 */ mtlr        r0
  /* 80533C2C 38210010 */ addi        r1, r1, 0x10
  /* 80533C30 4E800020 */ blr // clang-format on
}

// Symbol: unk_80533c34
// PAL: 0x80533c34..0x80533c6c
MARK_BINARY_BLOB(unk_80533c34, 0x80533c34, 0x80533c6c);
asm UNKNOWN_FUNCTION(unk_80533c34){
  // clang-format off
  nofralloc
  /* 80533C34 9421FFF0 */ stwu        r1, -0x10(r1)
  /* 80533C38 7C0802A6 */ mflr        r0
  /* 80533C3C 7C042840 */ cmplw       r4, r5
  /* 80533C40 90010014 */ stw         r0, 0x14(r1)
  /* 80533C44 40800014 */ bge-        lbl_80533c58
  /* 80533C48 81830000 */ lwz         r12, 0(r3)
  /* 80533C4C 818C000C */ lwz         r12, 0xc(r12)
  /* 80533C50 7D8903A6 */ mtctr       r12
  /* 80533C54 4E800421 */ bctrl
  lbl_80533c58:
  /* 80533C58 80010014 */ lwz         r0, 0x14(r1)
  /* 80533C5C 38600001 */ li          r3, 0x1
  /* 80533C60 7C0803A6 */ mtlr        r0
  /* 80533C64 38210010 */ addi        r1, r1, 0x10
  /* 80533C68 4E800020 */ blr // clang-format on
}

// Symbol: unk_80533c6c
// PAL: 0x80533c6c..0x80533d84
MARK_BINARY_BLOB(unk_80533c6c, 0x80533c6c, 0x80533d84);
asm UNKNOWN_FUNCTION(unk_80533c6c) {
  // clang-format off
  nofralloc
  /* 80533C6C 9421FFF0 */ stwu        r1, -0x10(r1)
  /* 80533C70 7C0802A6 */ mflr        r0
  /* 80533C74 90010014 */ stw         r0, 0x14(r1)
  /* 80533C78 1C0400F0 */ mulli       r0, r4, 0xf0
  /* 80533C7C 3C80809C */ lis         r4, spInstance__Q26System10RaceConfig@ha
  /* 80533C80 93E1000C */ stw         r31, 0xc(r1)
  /* 80533C84 7C7F1B78 */ mr          r31, r3
  /* 80533C88 93C10008 */ stw         r30, 8(r1)
  /* 80533C8C 88A3001C */ lbz         r5, 0x1c(r3)
  /* 80533C90 38A50001 */ addi        r5, r5, 0x1
  /* 80533C94 98A3001C */ stb         r5, 0x1c(r3)
  /* 80533C98 8064D728 */ lwz         r3, spInstance__Q26System10RaceConfig@l(r4)
  /* 80533C9C 7C630214 */ add         r3, r3, r0
  /* 80533CA0 8803002E */ lbz         r0, 0x2e(r3)
  /* 80533CA4 7C000775 */ extsb.      r0, r0
  /* 80533CA8 41800014 */ blt-        lbl_80533cbc
  /* 80533CAC 3C60809C */ lis         r3, spInstance__Q26System12KPadDirector@ha
  /* 80533CB0 5404063E */ clrlwi      r4, r0, 0x18
  /* 80533CB4 8063D70C */ lwz         r3, spInstance__Q26System12KPadDirector@l(r3)
  /* 80533CB8 4BFF0915 */ bl          endGhostProxy__Q26System12KPadDirectorFUc
  lbl_80533cbc:
  /* 80533CBC 3C80809C */ lis         r4, spInstance__Q26System10RaceConfig@ha
  /* 80533CC0 3C60809C */ lis         r3, spInstance__Q26System11RaceManager@ha
  /* 80533CC4 80A4D728 */ lwz         r5, spInstance__Q26System10RaceConfig@l(r4)
  /* 80533CC8 3BC00000 */ li          r30, 0x0
  /* 80533CCC 8083D730 */ lwz         r4, spInstance__Q26System11RaceManager@l(r3)
  /* 80533CD0 38C00000 */ li          r6, 0x0
  /* 80533CD4 88A50024 */ lbz         r5, 0x24(r5)
  /* 80533CD8 4800002C */ b           lbl_80533d04
  lbl_80533cdc:
  /* 80533CDC 8064000C */ lwz         r3, 0xc(r4)
  /* 80533CE0 54C015BA */ rlwinm      r0, r6, 2, 0x16, 0x1d
  /* 80533CE4 7C63002E */ lwzx        r3, r3, r0
  /* 80533CE8 80630038 */ lwz         r3, 0x38(r3)
  /* 80533CEC 546007BD */ rlwinm.     r0, r3, 0, 0x1e, 0x1e
  /* 80533CF0 4082000C */ bne-        lbl_80533cfc
  /* 80533CF4 546006F7 */ rlwinm.     r0, r3, 0, 0x1b, 0x1b
  /* 80533CF8 41820008 */ beq-        lbl_80533d00
  lbl_80533cfc:
  /* 80533CFC 3BDE0001 */ addi        r30, r30, 0x1
  lbl_80533d00:
  /* 80533D00 38C60001 */ addi        r6, r6, 0x1
  lbl_80533d04:
  /* 80533D04 54C0063E */ clrlwi      r0, r6, 0x18
  /* 80533D08 7C002840 */ cmplw       r0, r5
  /* 80533D0C 4180FFD0 */ blt+        lbl_80533cdc
  /* 80533D10 801F0028 */ lwz         r0, 0x28(r31)
  /* 80533D14 2C000004 */ cmpwi       r0, 0x4
  /* 80533D18 40800054 */ bge-        lbl_80533d6c
  /* 80533D1C 807F0010 */ lwz         r3, 0x10(r31)
  /* 80533D20 81830000 */ lwz         r12, 0(r3)
  /* 80533D24 818C0008 */ lwz         r12, 8(r12)
  /* 80533D28 7D8903A6 */ mtctr       r12
  /* 80533D2C 4E800421 */ bctrl
  /* 80533D30 2C030000 */ cmpwi       r3, 0x0
  /* 80533D34 41820038 */ beq-        lbl_80533d6c
  /* 80533D38 807F0010 */ lwz         r3, 0x10(r31)
  /* 80533D3C 3C80809C */ lis         r4, spInstance__Q26System10RaceConfig@ha
  /* 80533D40 80A4D728 */ lwz         r5, spInstance__Q26System10RaceConfig@l(r4)
  /* 80533D44 57C4063E */ clrlwi      r4, r30, 0x18
  /* 80533D48 81830000 */ lwz         r12, 0(r3)
  /* 80533D4C 88A50024 */ lbz         r5, 0x24(r5)
  /* 80533D50 818C0024 */ lwz         r12, 0x24(r12)
  /* 80533D54 7D8903A6 */ mtctr       r12
  /* 80533D58 4E800421 */ bctrl
  /* 80533D5C 2C030000 */ cmpwi       r3, 0x0
  /* 80533D60 4182000C */ beq-        lbl_80533d6c
  /* 80533D64 38000003 */ li          r0, 0x3
  /* 80533D68 901F0028 */ stw         r0, 0x28(r31)
  lbl_80533d6c:
  /* 80533D6C 80010014 */ lwz         r0, 0x14(r1)
  /* 80533D70 83E1000C */ lwz         r31, 0xc(r1)
  /* 80533D74 83C10008 */ lwz         r30, 8(r1)
  /* 80533D78 7C0803A6 */ mtlr        r0
  /* 80533D7C 38210010 */ addi        r1, r1, 0x10
  /* 80533D80 4E800020 */ blr // clang-format on
}

// Symbol: unk_80533d84
// PAL: 0x80533d84..0x80533dd4
MARK_BINARY_BLOB(unk_80533d84, 0x80533d84, 0x80533dd4);
asm UNKNOWN_FUNCTION(unk_80533d84) {
  // clang-format off
  nofralloc
  /* 80533D84 9421FFF0 */ stwu        r1, -0x10(r1)
  /* 80533D88 7C0802A6 */ mflr        r0
  /* 80533D8C 90010014 */ stw         r0, 0x14(r1)
  /* 80533D90 548015BA */ rlwinm      r0, r4, 2, 0x16, 0x1d
  /* 80533D94 80A3000C */ lwz         r5, 0xc(r3)
  /* 80533D98 3C60809C */ lis         r3, lbl_809c18f8@ha
  /* 80533D9C 7C85002E */ lwzx        r4, r5, r0
  /* 80533DA0 80040038 */ lwz         r0, 0x38(r4)
  /* 80533DA4 60000020 */ ori         r0, r0, 0x20
  /* 80533DA8 90040038 */ stw         r0, 0x38(r4)
  /* 80533DAC 806318F8 */ lwz         r3, lbl_809c18f8@l(r3)
  /* 80533DB0 88840008 */ lbz         r4, 8(r4)
  /* 80533DB4 4805C34D */ bl          PlayerHolder_getPlayer
  /* 80533DB8 4805C9C5 */ bl          kartMove__Q24Kart15KartObjectProxyFv
  /* 80533DBC 38800001 */ li          r4, 0x1
  /* 80533DC0 4804D5E5 */ bl          unk_805813a4
  /* 80533DC4 80010014 */ lwz         r0, 0x14(r1)
  /* 80533DC8 7C0803A6 */ mtlr        r0
  /* 80533DCC 38210010 */ addi        r1, r1, 0x10
  /* 80533DD0 4E800020 */ blr // clang-format on
}

// Symbol: unk_80533dd4
// PAL: 0x80533dd4..0x80533ed8
MARK_BINARY_BLOB(unk_80533dd4, 0x80533dd4, 0x80533ed8);
asm UNKNOWN_FUNCTION(unk_80533dd4) {
  // clang-format off
  nofralloc
  /* 80533DD4 9421FFF0 */ stwu        r1, -0x10(r1)
  /* 80533DD8 7C0802A6 */ mflr        r0
  /* 80533DDC 3CA0809C */ lis         r5, spInstance__Q26System10RaceConfig@ha
  /* 80533DE0 90010014 */ stw         r0, 0x14(r1)
  /* 80533DE4 548015BA */ rlwinm      r0, r4, 2, 0x16, 0x1d
  /* 80533DE8 93E1000C */ stw         r31, 0xc(r1)
  /* 80533DEC 3BE00000 */ li          r31, 0x0
  /* 80533DF0 93C10008 */ stw         r30, 8(r1)
  /* 80533DF4 7C7E1B78 */ mr          r30, r3
  /* 80533DF8 88E3001D */ lbz         r7, 0x1d(r3)
  /* 80533DFC 80C3000C */ lwz         r6, 0xc(r3)
  /* 80533E00 38870001 */ addi        r4, r7, 0x1
  /* 80533E04 9883001D */ stb         r4, 0x1d(r3)
  /* 80533E08 3C80809C */ lis         r4, spInstance__Q26System11RaceManager@ha
  /* 80533E0C 38E00000 */ li          r7, 0x0
  /* 80533E10 7CC6002E */ lwzx        r6, r6, r0
  /* 80533E14 80060038 */ lwz         r0, 0x38(r6)
  /* 80533E18 60000010 */ ori         r0, r0, 0x10
  /* 80533E1C 90060038 */ stw         r0, 0x38(r6)
  /* 80533E20 80C5D728 */ lwz         r6, spInstance__Q26System10RaceConfig@l(r5)
  /* 80533E24 80A4D730 */ lwz         r5, spInstance__Q26System11RaceManager@l(r4)
  /* 80533E28 88C60024 */ lbz         r6, 0x24(r6)
  /* 80533E2C 4800002C */ b           lbl_80533e58
  lbl_80533e30:
  /* 80533E30 8085000C */ lwz         r4, 0xc(r5)
  /* 80533E34 54E015BA */ rlwinm      r0, r7, 2, 0x16, 0x1d
  /* 80533E38 7C84002E */ lwzx        r4, r4, r0
  /* 80533E3C 80840038 */ lwz         r4, 0x38(r4)
  /* 80533E40 548007BD */ rlwinm.     r0, r4, 0, 0x1e, 0x1e
  /* 80533E44 4082000C */ bne-        lbl_80533e50
  /* 80533E48 548006F7 */ rlwinm.     r0, r4, 0, 0x1b, 0x1b
  /* 80533E4C 41820008 */ beq-        lbl_80533e54
  lbl_80533e50:
  /* 80533E50 3BFF0001 */ addi        r31, r31, 0x1
  lbl_80533e54:
  /* 80533E54 38E70001 */ addi        r7, r7, 0x1
  lbl_80533e58:
  /* 80533E58 54E0063E */ clrlwi      r0, r7, 0x18
  /* 80533E5C 7C003040 */ cmplw       r0, r6
  /* 80533E60 4180FFD0 */ blt+        lbl_80533e30
  /* 80533E64 80030028 */ lwz         r0, 0x28(r3)
  /* 80533E68 2C000004 */ cmpwi       r0, 0x4
  /* 80533E6C 40800054 */ bge-        lbl_80533ec0
  /* 80533E70 80630010 */ lwz         r3, 0x10(r3)
  /* 80533E74 81830000 */ lwz         r12, 0(r3)
  /* 80533E78 818C0008 */ lwz         r12, 8(r12)
  /* 80533E7C 7D8903A6 */ mtctr       r12
  /* 80533E80 4E800421 */ bctrl
  /* 80533E84 2C030000 */ cmpwi       r3, 0x0
  /* 80533E88 41820038 */ beq-        lbl_80533ec0
  /* 80533E8C 807E0010 */ lwz         r3, 0x10(r30)
  /* 80533E90 3C80809C */ lis         r4, spInstance__Q26System10RaceConfig@ha
  /* 80533E94 80A4D728 */ lwz         r5, spInstance__Q26System10RaceConfig@l(r4)
  /* 80533E98 57E4063E */ clrlwi      r4, r31, 0x18
  /* 80533E9C 81830000 */ lwz         r12, 0(r3)
  /* 80533EA0 88A50024 */ lbz         r5, 0x24(r5)
  /* 80533EA4 818C0024 */ lwz         r12, 0x24(r12)
  /* 80533EA8 7D8903A6 */ mtctr       r12
  /* 80533EAC 4E800421 */ bctrl
  /* 80533EB0 2C030000 */ cmpwi       r3, 0x0
  /* 80533EB4 4182000C */ beq-        lbl_80533ec0
  /* 80533EB8 38000003 */ li          r0, 0x3
  /* 80533EBC 901E0028 */ stw         r0, 0x28(r30)
  lbl_80533ec0:
  /* 80533EC0 80010014 */ lwz         r0, 0x14(r1)
  /* 80533EC4 83E1000C */ lwz         r31, 0xc(r1)
  /* 80533EC8 83C10008 */ lwz         r30, 8(r1)
  /* 80533ECC 7C0803A6 */ mtlr        r0
  /* 80533ED0 38210010 */ addi        r1, r1, 0x10
  /* 80533ED4 4E800020 */ blr // clang-format on
}

// Symbol: RaceinfoPlayer_construct
// PAL: 0x80533ed8..0x80534194
MARK_BINARY_BLOB(RaceinfoPlayer_construct, 0x80533ed8, 0x80534194);
asm UNKNOWN_FUNCTION(RaceinfoPlayer_construct) {
  // clang-format off
  nofralloc
  /* 80533ED8 9421FFE0 */ stwu        r1, -0x20(r1)
  /* 80533EDC 7C0802A6 */ mflr        r0
  /* 80533EE0 3CC08089 */ lis         r6, lbl_80890150@ha
  /* 80533EE4 3CE08089 */ lis         r7, lbl_80890154@ha
  /* 80533EE8 90010024 */ stw         r0, 0x24(r1)
  /* 80533EEC 3D00808B */ lis         r8, lbl_808b34a4@ha
  /* 80533EF0 C0460150 */ lfs         f2, lbl_80890150@l(r6)
  /* 80533EF4 3CC08089 */ lis         r6, lbl_80890178@ha
  /* 80533EF8 93E1001C */ stw         r31, 0x1c(r1)
  /* 80533EFC 390834A4 */ addi        r8, r8, lbl_808b34a4@l
  /* 80533F00 C0270154 */ lfs         f1, lbl_80890154@l(r7)
  /* 80533F04 38040001 */ addi        r0, r4, 0x1
  /* 80533F08 93C10018 */ stw         r30, 0x18(r1)
  /* 80533F0C 38E00000 */ li          r7, 0x0
  /* 80533F10 C0060178 */ lfs         f0, lbl_80890178@l(r6)
  /* 80533F14 3CC0809C */ lis         r6, spInstance__Q26System9CourseMap@ha
  /* 80533F18 93A10014 */ stw         r29, 0x14(r1)
  /* 80533F1C 7C7E1B78 */ mr          r30, r3
  /* 80533F20 7CBF2B78 */ mr          r31, r5
  /* 80533F24 93810010 */ stw         r28, 0x10(r1)
  /* 80533F28 91030000 */ stw         r8, 0(r3)
  /* 80533F2C 98830008 */ stb         r4, 8(r3)
  /* 80533F30 B0E3000A */ sth         r7, 0xa(r3)
  /* 80533F34 D043000C */ stfs        f2, 0xc(r3)
  /* 80533F38 D0230014 */ stfs        f1, 0x14(r3)
  /* 80533F3C D0430018 */ stfs        f2, 0x18(r3)
  /* 80533F40 D003001C */ stfs        f0, 0x1c(r3)
  /* 80533F44 98030020 */ stb         r0, 0x20(r3)
  /* 80533F48 8106D6E8 */ lwz         r8, spInstance__Q26System9CourseMap@l(r6)
  /* 80533F4C 80C80020 */ lwz         r6, 0x20(r8)
  /* 80533F50 2C060000 */ cmpwi       r6, 0x0
  /* 80533F54 41820008 */ beq-        lbl_80533f5c
  /* 80533F58 A0E60004 */ lhz         r7, 4(r6)
  lbl_80533f5c:
  /* 80533F5C 7C0700D0 */ neg         r0, r7
  /* 80533F60 7C003B78 */ or          r0, r0, r7
  /* 80533F64 54000FFF */ rlwinm.     r0, r0, 1, 0x1f, 0x1f
  /* 80533F68 41820028 */ beq-        lbl_80533f90
  /* 80533F6C 8088001C */ lwz         r4, 0x1c(r8)
  /* 80533F70 2C040000 */ cmpwi       r4, 0x0
  /* 80533F74 4182000C */ beq-        lbl_80533f80
  /* 80533F78 A0840004 */ lhz         r4, 4(r4)
  /* 80533F7C 48000008 */ b           lbl_80533f84
  lbl_80533f80:
  /* 80533F80 38800000 */ li          r4, 0x0
  lbl_80533f84:
  /* 80533F84 7C0400D0 */ neg         r0, r4
  /* 80533F88 7C002378 */ or          r0, r0, r4
  /* 80533F8C 54000FFE */ srwi        r0, r0, 0x1f
  lbl_80533f90:
  /* 80533F90 2C000000 */ cmpwi       r0, 0x0
  /* 80533F94 41820010 */ beq-        lbl_80533fa4
  /* 80533F98 80880020 */ lwz         r4, 0x20(r8)
  /* 80533F9C 8804000C */ lbz         r0, 0xc(r4)
  /* 80533FA0 48000008 */ b           lbl_80533fa8
  lbl_80533fa4:
  /* 80533FA4 3800FFFF */ li          r0, -0x1
  lbl_80533fa8:
  /* 80533FA8 7C000774 */ extsb       r0, r0
  /* 80533FAC 2C00FFFF */ cmpwi       r0, -0x1
  /* 80533FB0 418200E0 */ beq-        lbl_80534090
  /* 80533FB4 2C060000 */ cmpwi       r6, 0x0
  /* 80533FB8 41820010 */ beq-        lbl_80533fc8
  /* 80533FBC 80880020 */ lwz         r4, 0x20(r8)
  /* 80533FC0 A0840004 */ lhz         r4, 4(r4)
  /* 80533FC4 48000008 */ b           lbl_80533fcc
  lbl_80533fc8:
  /* 80533FC8 38800000 */ li          r4, 0x0
  lbl_80533fcc:
  /* 80533FCC 7C0400D0 */ neg         r0, r4
  /* 80533FD0 7C002378 */ or          r0, r0, r4
  /* 80533FD4 54000FFF */ rlwinm.     r0, r0, 1, 0x1f, 0x1f
  /* 80533FD8 41820028 */ beq-        lbl_80534000
  /* 80533FDC 8088001C */ lwz         r4, 0x1c(r8)
  /* 80533FE0 2C040000 */ cmpwi       r4, 0x0
  /* 80533FE4 4182000C */ beq-        lbl_80533ff0
  /* 80533FE8 A0840004 */ lhz         r4, 4(r4)
  /* 80533FEC 48000008 */ b           lbl_80533ff4
  lbl_80533ff0:
  /* 80533FF0 38800000 */ li          r4, 0x0
  lbl_80533ff4:
  /* 80533FF4 7C0400D0 */ neg         r0, r4
  /* 80533FF8 7C002378 */ or          r0, r0, r4
  /* 80533FFC 54000FFE */ srwi        r0, r0, 0x1f
  lbl_80534000:
  /* 80534000 2C000000 */ cmpwi       r0, 0x0
  /* 80534004 41820010 */ beq-        lbl_80534014
  /* 80534008 80880020 */ lwz         r4, 0x20(r8)
  /* 8053400C 8804000C */ lbz         r0, 0xc(r4)
  /* 80534010 48000008 */ b           lbl_80534018
  lbl_80534014:
  /* 80534014 3800FFFF */ li          r0, -0x1
  lbl_80534018:
  /* 80534018 98030027 */ stb         r0, 0x27(r3)
  /* 8053401C 3C80809C */ lis         r4, spInstance__Q26System9CourseMap@ha
  /* 80534020 80C4D6E8 */ lwz         r6, spInstance__Q26System9CourseMap@l(r4)
  /* 80534024 80860020 */ lwz         r4, 0x20(r6)
  /* 80534028 2C040000 */ cmpwi       r4, 0x0
  /* 8053402C 4182000C */ beq-        lbl_80534038
  /* 80534030 A0840004 */ lhz         r4, 4(r4)
  /* 80534034 48000008 */ b           lbl_8053403c
  lbl_80534038:
  /* 80534038 38800000 */ li          r4, 0x0
  lbl_8053403c:
  /* 8053403C 7C0400D0 */ neg         r0, r4
  /* 80534040 7C002378 */ or          r0, r0, r4
  /* 80534044 54000FFF */ rlwinm.     r0, r0, 1, 0x1f, 0x1f
  /* 80534048 41820028 */ beq-        lbl_80534070
  /* 8053404C 8086001C */ lwz         r4, 0x1c(r6)
  /* 80534050 2C040000 */ cmpwi       r4, 0x0
  /* 80534054 4182000C */ beq-        lbl_80534060
  /* 80534058 A0840004 */ lhz         r4, 4(r4)
  /* 8053405C 48000008 */ b           lbl_80534064
  lbl_80534060:
  /* 80534060 38800000 */ li          r4, 0x0
  lbl_80534064:
  /* 80534064 7C0400D0 */ neg         r0, r4
  /* 80534068 7C002378 */ or          r0, r0, r4
  /* 8053406C 54000FFE */ srwi        r0, r0, 0x1f
  lbl_80534070:
  /* 80534070 2C000000 */ cmpwi       r0, 0x0
  /* 80534074 41820010 */ beq-        lbl_80534084
  /* 80534078 80860020 */ lwz         r4, 0x20(r6)
  /* 8053407C 8804000C */ lbz         r0, 0xc(r4)
  /* 80534080 48000008 */ b           lbl_80534088
  lbl_80534084:
  /* 80534084 3800FFFF */ li          r0, -0x1
  lbl_80534088:
  /* 80534088 98030028 */ stb         r0, 0x28(r3)
  /* 8053408C 48000010 */ b           lbl_8053409c
  lbl_80534090:
  /* 80534090 3800FFFF */ li          r0, -0x1
  /* 80534094 98030027 */ stb         r0, 0x27(r3)
  /* 80534098 98030028 */ stb         r0, 0x28(r3)
  lbl_8053409c:
  /* 8053409C 1C85000C */ mulli       r4, r5, 0xc
  /* 805340A0 3B800000 */ li          r28, 0x0
  /* 805340A4 3BA00001 */ li          r29, 0x1
  /* 805340A8 B3830024 */ sth         r28, 0x24(r3)
  /* 805340AC 9BA30026 */ stb         r29, 0x26(r3)
  /* 805340B0 93830038 */ stw         r28, 0x38(r3)
  /* 805340B4 38640010 */ addi        r3, r4, 0x10
  /* 805340B8 4BCF5D39 */ bl          __nwa__FUl
  /* 805340BC 3C808052 */ lis         r4, __ct__Q26System4TimeFv@ha
  /* 805340C0 3CA08052 */ lis         r5, __dt__Q26System4TimeFv@ha
  /* 805340C4 7FE7FB78 */ mr          r7, r31
  /* 805340C8 38C0000C */ li          r6, 0xc
  /* 805340CC 3884C374 */ addi        r4, r4, __ct__Q26System4TimeFv@l
  /* 805340D0 38A5C334 */ addi        r5, r5, __dt__Q26System4TimeFv@l
  /* 805340D4 4BAECD61 */ bl          __construct_new_array
  /* 805340D8 907E003C */ stw         r3, 0x3c(r30)
  /* 805340DC 3860000C */ li          r3, 0xc
  /* 805340E0 4BCF5CED */ bl          __nw__FUl
  /* 805340E4 2C030000 */ cmpwi       r3, 0x0
  /* 805340E8 41820020 */ beq-        lbl_80534108
  /* 805340EC 3C80808B */ lis         r4, __vt__Q26System4Time@ha
  /* 805340F0 38842D44 */ addi        r4, r4, __vt__Q26System4Time@l
  /* 805340F4 90830000 */ stw         r4, 0(r3)
  /* 805340F8 9BA3000A */ stb         r29, 0xa(r3)
  /* 805340FC B3830004 */ sth         r28, 4(r3)
  /* 80534100 9B830006 */ stb         r28, 6(r3)
  /* 80534104 B3830008 */ sth         r28, 8(r3)
  lbl_80534108:
  /* 80534108 88BE0008 */ lbz         r5, 8(r30)
  /* 8053410C 38800000 */ li          r4, 0x0
  /* 80534110 907E0040 */ stw         r3, 0x40(r30)
  /* 80534114 3C60809C */ lis         r3, spInstance__Q26System10RaceConfig@ha
  /* 80534118 1C0500F0 */ mulli       r0, r5, 0xf0
  /* 8053411C 909E0044 */ stw         r4, 0x44(r30)
  /* 80534120 8063D728 */ lwz         r3, spInstance__Q26System10RaceConfig@l(r3)
  /* 80534124 7C630214 */ add         r3, r3, r0
  /* 80534128 8803002E */ lbz         r0, 0x2e(r3)
  /* 8053412C 7C000774 */ extsb       r0, r0
  /* 80534130 2C00FFFF */ cmpwi       r0, -0x1
  /* 80534134 41820024 */ beq-        lbl_80534158
  /* 80534138 5400063E */ clrlwi      r0, r0, 0x18
  /* 8053413C 3C60809C */ lis         r3, spInstance__Q26System12KPadDirector@ha
  /* 80534140 1C0000EC */ mulli       r0, r0, 0xec
  /* 80534144 8063D70C */ lwz         r3, spInstance__Q26System12KPadDirector@l(r3)
  /* 80534148 7C630214 */ add         r3, r3, r0
  /* 8053414C 38030004 */ addi        r0, r3, 0x4
  /* 80534150 901E0048 */ stw         r0, 0x48(r30)
  /* 80534154 4800001C */ b           lbl_80534170
  lbl_80534158:
  /* 80534158 3C60809C */ lis         r3, spInstance__Q26System12KPadDirector@ha
  /* 8053415C 1C050180 */ mulli       r0, r5, 0x180
  /* 80534160 8063D70C */ lwz         r3, spInstance__Q26System12KPadDirector@l(r3)
  /* 80534164 7C630214 */ add         r3, r3, r0
  /* 80534168 380303B4 */ addi        r0, r3, 0x3b4
  /* 8053416C 901E0048 */ stw         r0, 0x48(r30)
  lbl_80534170:
  /* 80534170 7FC3F378 */ mr          r3, r30
  /* 80534174 83E1001C */ lwz         r31, 0x1c(r1)
  /* 80534178 83C10018 */ lwz         r30, 0x18(r1)
  /* 8053417C 83A10014 */ lwz         r29, 0x14(r1)
  /* 80534180 83810010 */ lwz         r28, 0x10(r1)
  /* 80534184 80010024 */ lwz         r0, 0x24(r1)
  /* 80534188 7C0803A6 */ mtlr        r0
  /* 8053418C 38210020 */ addi        r1, r1, 0x20
  /* 80534190 4E800020 */ blr // clang-format on
}

// Symbol: RaceinfoPlayer_init
// PAL: 0x80534194..0x805342e8
MARK_BINARY_BLOB(RaceinfoPlayer_init, 0x80534194, 0x805342e8);
asm UNKNOWN_FUNCTION(RaceinfoPlayer_init) {
  // clang-format off
  nofralloc
  /* 80534194 9421FFE0 */ stwu        r1, -0x20(r1)
  /* 80534198 7C0802A6 */ mflr        r0
  /* 8053419C 3C80809C */ lis         r4, spInstance__Q26System11RaceManager@ha
  /* 805341A0 90010024 */ stw         r0, 0x24(r1)
  /* 805341A4 93E1001C */ stw         r31, 0x1c(r1)
  /* 805341A8 7C7F1B78 */ mr          r31, r3
  /* 805341AC 93C10018 */ stw         r30, 0x18(r1)
  /* 805341B0 3BC00000 */ li          r30, 0x0
  /* 805341B4 B3C30022 */ sth         r30, 0x22(r3)
  /* 805341B8 8064D730 */ lwz         r3, spInstance__Q26System11RaceManager@l(r4)
  /* 805341BC 3880000A */ li          r4, 0xa
  /* 805341C0 80630008 */ lwz         r3, 8(r3)
  /* 805341C4 48021409 */ bl          nextU32__Q24Util6RandomFUl
  /* 805341C8 38630001 */ addi        r3, r3, 0x1
  /* 805341CC 38000001 */ li          r0, 0x1
  /* 805341D0 7C001830 */ slw         r0, r0, r3
  /* 805341D4 901F004C */ stw         r0, 0x4c(r31)
  /* 805341D8 3C60809C */ lis         r3, spInstance__Q26System9CourseMap@ha
  /* 805341DC 901F0004 */ stw         r0, 4(r31)
  /* 805341E0 8083D6E8 */ lwz         r4, spInstance__Q26System9CourseMap@l(r3)
  /* 805341E4 80640020 */ lwz         r3, 0x20(r4)
  /* 805341E8 2C030000 */ cmpwi       r3, 0x0
  /* 805341EC 41820008 */ beq-        lbl_805341f4
  /* 805341F0 A3C30004 */ lhz         r30, 4(r3)
  lbl_805341f4:
  /* 805341F4 7C1E00D0 */ neg         r0, r30
  /* 805341F8 7C00F378 */ or          r0, r0, r30
  /* 805341FC 54000FFF */ rlwinm.     r0, r0, 1, 0x1f, 0x1f
  /* 80534200 41820028 */ beq-        lbl_80534228
  /* 80534204 8064001C */ lwz         r3, 0x1c(r4)
  /* 80534208 2C030000 */ cmpwi       r3, 0x0
  /* 8053420C 4182000C */ beq-        lbl_80534218
  /* 80534210 A0630004 */ lhz         r3, 4(r3)
  /* 80534214 48000008 */ b           lbl_8053421c
  lbl_80534218:
  /* 80534218 38600000 */ li          r3, 0x0
  lbl_8053421c:
  /* 8053421C 7C0300D0 */ neg         r0, r3
  /* 80534220 7C001B78 */ or          r0, r0, r3
  /* 80534224 54000FFE */ srwi        r0, r0, 0x1f
  lbl_80534228:
  /* 80534228 2C000000 */ cmpwi       r0, 0x0
  /* 8053422C 41820070 */ beq-        lbl_8053429c
  /* 80534230 3C60809C */ lis         r3, lbl_809c18f8@ha
  /* 80534234 889F0008 */ lbz         r4, 8(r31)
  /* 80534238 806318F8 */ lwz         r3, lbl_809c18f8@l(r3)
  /* 8053423C 4805BEC5 */ bl          PlayerHolder_getPlayer
  /* 80534240 4805BFCD */ bl          getPos__Q24Kart15KartObjectProxyCFv
  /* 80534244 3C80809C */ lis         r4, spInstance__Q26System9CourseMap@ha
  /* 80534248 7C651B78 */ mr          r5, r3
  /* 8053424C 8064D6E8 */ lwz         r3, spInstance__Q26System9CourseMap@l(r4)
  /* 80534250 38E10008 */ addi        r7, r1, 0x8
  /* 80534254 889F0008 */ lbz         r4, 8(r31)
  /* 80534258 38C00000 */ li          r6, 0x0
  /* 8053425C 39000001 */ li          r8, 0x1
  /* 80534260 4BFDD2A1 */ bl          KmpHolder_findNextCheckpoint
  /* 80534264 7C600735 */ extsh.      r0, r3
  /* 80534268 4180000C */ blt-        lbl_80534274
  /* 8053426C B07F000A */ sth         r3, 0xa(r31)
  /* 80534270 4800000C */ b           lbl_8053427c
  lbl_80534274:
  /* 80534274 38000000 */ li          r0, 0x0
  /* 80534278 B01F000A */ sth         r0, 0xa(r31)
  lbl_8053427c:
  /* 8053427C 3C60809C */ lis         r3, spInstance__Q26System9CourseMap@ha
  /* 80534280 A09F000A */ lhz         r4, 0xa(r31)
  /* 80534284 8063D6E8 */ lwz         r3, spInstance__Q26System9CourseMap@l(r3)
  /* 80534288 4BFE199D */ bl          getCheckPoint__Q26System9CourseMapCFUs
  /* 8053428C 80630000 */ lwz         r3, 0(r3)
  /* 80534290 88030010 */ lbz         r0, 0x10(r3)
  /* 80534294 981F0021 */ stb         r0, 0x21(r31)
  /* 80534298 4800000C */ b           lbl_805342a4
  lbl_8053429c:
  /* 8053429C 38000000 */ li          r0, 0x0
  /* 805342A0 981F0021 */ stb         r0, 0x21(r31)
  lbl_805342a4:
  /* 805342A4 801F0038 */ lwz         r0, 0x38(r31)
  /* 805342A8 38A00000 */ li          r5, 0x0
  /* 805342AC 3880000D */ li          r4, 0xd
  /* 805342B0 38600007 */ li          r3, 0x7
  /* 805342B4 60000001 */ ori         r0, r0, 1
  /* 805342B8 90BF002C */ stw         r5, 0x2c(r31)
  /* 805342BC 90BF0030 */ stw         r5, 0x30(r31)
  /* 805342C0 B0BF0050 */ sth         r5, 0x50(r31)
  /* 805342C4 989F0052 */ stb         r4, 0x52(r31)
  /* 805342C8 907F0034 */ stw         r3, 0x34(r31)
  /* 805342CC 901F0038 */ stw         r0, 0x38(r31)
  /* 805342D0 83E1001C */ lwz         r31, 0x1c(r1)
  /* 805342D4 83C10018 */ lwz         r30, 0x18(r1)
  /* 805342D8 80010024 */ lwz         r0, 0x24(r1)
  /* 805342DC 7C0803A6 */ mtlr        r0
  /* 805342E0 38210020 */ addi        r1, r1, 0x20
  /* 805342E4 4E800020 */ blr // clang-format on
}

// Symbol: unk_805342e8
// PAL: 0x805342e8..0x80534684
MARK_BINARY_BLOB(unk_805342e8, 0x805342e8, 0x80534684);
asm UNKNOWN_FUNCTION(unk_805342e8) {
  // clang-format off
  nofralloc
  /* 805342E8 9421FFA0 */ stwu        r1, -0x60(r1)
  /* 805342EC 7C0802A6 */ mflr        r0
  /* 805342F0 3CC0808B */ lis         r6, __vt__Q26System4Time@ha
  /* 805342F4 2C050000 */ cmpwi       r5, 0x0
  /* 805342F8 90010064 */ stw         r0, 0x64(r1)
  /* 805342FC 3CA04330 */ lis         r5, 0x4330
  /* 80534300 38000000 */ li          r0, 0x0
  /* 80534304 38C62D44 */ addi        r6, r6, __vt__Q26System4Time@l
  /* 80534308 93E1005C */ stw         r31, 0x5c(r1)
  /* 8053430C 7C9F2378 */ mr          r31, r4
  /* 80534310 93C10058 */ stw         r30, 0x58(r1)
  /* 80534314 7C7E1B78 */ mr          r30, r3
  /* 80534318 93A10054 */ stw         r29, 0x54(r1)
  /* 8053431C 90A10038 */ stw         r5, 0x38(r1)
  /* 80534320 90A10040 */ stw         r5, 0x40(r1)
  /* 80534324 90C1002C */ stw         r6, 0x2c(r1)
  /* 80534328 98010036 */ stb         r0, 0x36(r1)
  /* 8053432C B0010030 */ sth         r0, 0x30(r1)
  /* 80534330 98010032 */ stb         r0, 0x32(r1)
  /* 80534334 B0010034 */ sth         r0, 0x34(r1)
  /* 80534338 41820240 */ beq-        lbl_80534578
  /* 8053433C 3C80809C */ lis         r4, spInstance__Q26System10RaceConfig@ha
  /* 80534340 38A00003 */ li          r5, 0x3
  /* 80534344 80C4D728 */ lwz         r6, spInstance__Q26System10RaceConfig@l(r4)
  /* 80534348 80060B90 */ lwz         r0, 0xb90(r6)
  /* 8053434C 5400077B */ rlwinm.     r0, r0, 0, 0x1d, 0x1d
  /* 80534350 4182001C */ beq-        lbl_8053436c
  /* 80534354 88A60B8D */ lbz         r5, 0xb8d(r6)
  /* 80534358 380500FF */ addi        r0, r5, 0xff
  /* 8053435C 5400063E */ clrlwi      r0, r0, 0x18
  /* 80534360 28000008 */ cmplwi      r0, 8
  /* 80534364 40810008 */ ble-        lbl_8053436c
  /* 80534368 38A00003 */ li          r5, 0x3
  lbl_8053436c:
  /* 8053436C 54A0063E */ clrlwi      r0, r5, 0x18
  /* 80534370 9001003C */ stw         r0, 0x3c(r1)
  /* 80534374 3CA08089 */ lis         r5, lbl_80890170@ha
  /* 80534378 3C808089 */ lis         r4, lbl_8089017c@ha
  /* 8053437C C8450170 */ lfd         f2, lbl_80890170@l(r5)
  /* 80534380 C8010038 */ lfd         f0, 0x38(r1)
  /* 80534384 C024017C */ lfs         f1, lbl_8089017c@l(r4)
  /* 80534388 EC401028 */ fsubs       f2, f0, f2
  /* 8053438C C003000C */ lfs         f0, 0xc(r3)
  /* 80534390 FC000840 */ opword      0xfc000840
  /* 80534394 EC21102A */ fadds       f1, f1, f2
  /* 80534398 40810044 */ ble-        lbl_805343dc
  /* 8053439C EC210024 */ fdivs       f1, f1, f0
  /* 805343A0 3C60809C */ lis         r3, spInstance__Q26System11RaceManager@ha
  /* 805343A4 8083D730 */ lwz         r4, spInstance__Q26System11RaceManager@l(r3)
  /* 805343A8 38610014 */ addi        r3, r1, 0x14
  /* 805343AC 80840014 */ lwz         r4, 0x14(r4)
  /* 805343B0 38840004 */ addi        r4, r4, 0x4
  /* 805343B4 480002D1 */ bl          unk_80534684
  /* 805343B8 A0A10018 */ lhz         r5, 0x18(r1)
  /* 805343BC 8881001A */ lbz         r4, 0x1a(r1)
  /* 805343C0 A061001C */ lhz         r3, 0x1c(r1)
  /* 805343C4 8801001E */ lbz         r0, 0x1e(r1)
  /* 805343C8 B0A10030 */ sth         r5, 0x30(r1)
  /* 805343CC 98810032 */ stb         r4, 0x32(r1)
  /* 805343D0 B0610034 */ sth         r3, 0x34(r1)
  /* 805343D4 98010036 */ stb         r0, 0x36(r1)
  /* 805343D8 480000E0 */ b           lbl_805344b8
  lbl_805343dc:
  /* 805343DC 3CA0808B */ lis         r5, __vt__Q26System4Time@ha
  /* 805343E0 38800000 */ li          r4, 0x0
  /* 805343E4 38A52D44 */ addi        r5, r5, __vt__Q26System4Time@l
  /* 805343E8 90A10020 */ stw         r5, 0x20(r1)
  /* 805343EC 9881002A */ stb         r4, 0x2a(r1)
  /* 805343F0 B0810024 */ sth         r4, 0x24(r1)
  /* 805343F4 98810026 */ stb         r4, 0x26(r1)
  /* 805343F8 B0810028 */ sth         r4, 0x28(r1)
  /* 805343FC 80060B70 */ lwz         r0, 0xb70(r6)
  /* 80534400 2C000007 */ cmpwi       r0, 0x7
  /* 80534404 41800010 */ blt-        lbl_80534414
  /* 80534408 2C00000A */ cmpwi       r0, 0xa
  /* 8053440C 41810008 */ bgt-        lbl_80534414
  /* 80534410 38800001 */ li          r4, 0x1
  lbl_80534414:
  /* 80534414 2C040000 */ cmpwi       r4, 0x0
  /* 80534418 41820024 */ beq-        lbl_8053443c
  /* 8053441C 38000000 */ li          r0, 0x0
  /* 80534420 38A00001 */ li          r5, 0x1
  /* 80534424 38800005 */ li          r4, 0x5
  /* 80534428 98A1002A */ stb         r5, 0x2a(r1)
  /* 8053442C B0810024 */ sth         r4, 0x24(r1)
  /* 80534430 98010026 */ stb         r0, 0x26(r1)
  /* 80534434 B0010028 */ sth         r0, 0x28(r1)
  /* 80534438 48000020 */ b           lbl_80534458
  lbl_8053443c:
  /* 8053443C 38000000 */ li          r0, 0x0
  /* 80534440 38A00001 */ li          r5, 0x1
  /* 80534444 38800064 */ li          r4, 0x64
  /* 80534448 98A1002A */ stb         r5, 0x2a(r1)
  /* 8053444C B0810024 */ sth         r4, 0x24(r1)
  /* 80534450 98010026 */ stb         r0, 0x26(r1)
  /* 80534454 B0010028 */ sth         r0, 0x28(r1)
  lbl_80534458:
  /* 80534458 3C808089 */ lis         r4, lbl_8089017c@ha
  /* 8053445C C003000C */ lfs         f0, 0xc(r3)
  /* 80534460 C044017C */ lfs         f2, lbl_8089017c@l(r4)
  /* 80534464 EC22082A */ fadds       f1, f2, f1
  /* 80534468 EC210028 */ fsubs       f1, f1, f0
  /* 8053446C FC011040 */ opword      0xfc011040
  /* 80534470 40800008 */ bge-        lbl_80534478
  /* 80534474 FC201090 */ fmr         f1, f2
  lbl_80534478:
  /* 80534478 3C608089 */ lis         r3, lbl_80890180@ha
  /* 8053447C C0030180 */ lfs         f0, lbl_80890180@l(r3)
  /* 80534480 FC010040 */ opword      0xfc010040
  /* 80534484 40810008 */ ble-        lbl_8053448c
  /* 80534488 FC200090 */ fmr         f1, f0
  lbl_8053448c:
  /* 8053448C 38610008 */ addi        r3, r1, 0x8
  /* 80534490 38810020 */ addi        r4, r1, 0x20
  /* 80534494 480001F1 */ bl          unk_80534684
  /* 80534498 A0A1000C */ lhz         r5, 0xc(r1)
  /* 8053449C 8881000E */ lbz         r4, 0xe(r1)
  /* 805344A0 A0610010 */ lhz         r3, 0x10(r1)
  /* 805344A4 88010012 */ lbz         r0, 0x12(r1)
  /* 805344A8 B0A10030 */ sth         r5, 0x30(r1)
  /* 805344AC 98810032 */ stb         r4, 0x32(r1)
  /* 805344B0 B0610034 */ sth         r3, 0x34(r1)
  /* 805344B4 98010036 */ stb         r0, 0x36(r1)
  lbl_805344b8:
  /* 805344B8 A0010034 */ lhz         r0, 0x34(r1)
  /* 805344BC 3C808089 */ lis         r4, lbl_80890170@ha
  /* 805344C0 90010044 */ stw         r0, 0x44(r1)
  /* 805344C4 3C608089 */ lis         r3, lbl_80890184@ha
  /* 805344C8 C8440170 */ lfd         f2, lbl_80890170@l(r4)
  /* 805344CC 38800000 */ li          r4, 0x0
  /* 805344D0 C8210040 */ lfd         f1, 0x40(r1)
  /* 805344D4 C0030184 */ lfs         f0, lbl_80890184@l(r3)
  /* 805344D8 EC211028 */ fsubs       f1, f1, f2
  /* 805344DC EC00082A */ fadds       f0, f0, f1
  /* 805344E0 FC00001E */ fctiwz      f0, f0
  /* 805344E4 D8010048 */ stfd        f0, 0x48(r1)
  /* 805344E8 80A1004C */ lwz         r5, 0x4c(r1)
  /* 805344EC 54A0043E */ clrlwi      r0, r5, 0x10
  /* 805344F0 280003E7 */ cmplwi      r0, 0x3e7
  /* 805344F4 40810064 */ ble-        lbl_80534558
  /* 805344F8 88610032 */ lbz         r3, 0x32(r1)
  /* 805344FC 3805FC18 */ addi        r0, r5, -0x3e8
  /* 80534500 5405043E */ clrlwi      r5, r0, 0x10
  /* 80534504 38630001 */ addi        r3, r3, 0x1
  /* 80534508 5460063E */ clrlwi      r0, r3, 0x18
  /* 8053450C 2800003B */ cmplwi      r0, 0x3b
  /* 80534510 40810010 */ ble-        lbl_80534520
  /* 80534514 3803FFC4 */ addi        r0, r3, -0x3c
  /* 80534518 38800001 */ li          r4, 0x1
  /* 8053451C 5403063E */ clrlwi      r3, r0, 0x18
  lbl_80534520:
  /* 80534520 A0010030 */ lhz         r0, 0x30(r1)
  /* 80534524 7C840214 */ add         r4, r4, r0
  /* 80534528 5480043E */ clrlwi      r0, r4, 0x10
  /* 8053452C 280003E7 */ cmplwi      r0, 0x3e7
  /* 80534530 40810010 */ ble-        lbl_80534540
  /* 80534534 388003E7 */ li          r4, 0x3e7
  /* 80534538 3860003B */ li          r3, 0x3b
  /* 8053453C 38A003E7 */ li          r5, 0x3e7
  lbl_80534540:
  /* 80534540 38000001 */ li          r0, 0x1
  /* 80534544 98010036 */ stb         r0, 0x36(r1)
  /* 80534548 B0810030 */ sth         r4, 0x30(r1)
  /* 8053454C 98610032 */ stb         r3, 0x32(r1)
  /* 80534550 B0A10034 */ sth         r5, 0x34(r1)
  /* 80534554 48000100 */ b           lbl_80534654
  lbl_80534558:
  /* 80534558 88810032 */ lbz         r4, 0x32(r1)
  /* 8053455C 38000001 */ li          r0, 0x1
  /* 80534560 A0610030 */ lhz         r3, 0x30(r1)
  /* 80534564 98010036 */ stb         r0, 0x36(r1)
  /* 80534568 B0610030 */ sth         r3, 0x30(r1)
  /* 8053456C 98810032 */ stb         r4, 0x32(r1)
  /* 80534570 B0A10034 */ sth         r5, 0x34(r1)
  /* 80534574 480000E0 */ b           lbl_80534654
  lbl_80534578:
  /* 80534578 3FA0809C */ lis         r29, spInstance__Q26System11RaceManager@ha
  /* 8053457C 38800010 */ li          r4, 0x10
  /* 80534580 807DD730 */ lwz         r3, spInstance__Q26System11RaceManager@l(r29)
  /* 80534584 80630008 */ lwz         r3, 8(r3)
  /* 80534588 48021045 */ bl          nextU32__Q24Util6RandomFUl
  /* 8053458C 80BDD730 */ lwz         r5, spInstance__Q26System11RaceManager@l(r29)
  /* 80534590 3C808089 */ lis         r4, lbl_80890170@ha
  /* 80534594 9061003C */ stw         r3, 0x3c(r1)
  /* 80534598 38E00000 */ li          r7, 0x0
  /* 8053459C 80A50014 */ lwz         r5, 0x14(r5)
  /* 805345A0 C8440170 */ lfd         f2, lbl_80890170@l(r4)
  /* 805345A4 A005000C */ lhz         r0, 0xc(r5)
  /* 805345A8 90010044 */ stw         r0, 0x44(r1)
  /* 805345AC C8210038 */ lfd         f1, 0x38(r1)
  /* 805345B0 C8010040 */ lfd         f0, 0x40(r1)
  /* 805345B4 EC211028 */ fsubs       f1, f1, f2
  /* 805345B8 EC001028 */ fsubs       f0, f0, f2
  /* 805345BC EC01002A */ fadds       f0, f1, f0
  /* 805345C0 FC00001E */ fctiwz      f0, f0
  /* 805345C4 D8010048 */ stfd        f0, 0x48(r1)
  /* 805345C8 80C1004C */ lwz         r6, 0x4c(r1)
  /* 805345CC 54C0043E */ clrlwi      r0, r6, 0x10
  /* 805345D0 280003E7 */ cmplwi      r0, 0x3e7
  /* 805345D4 40810064 */ ble-        lbl_80534638
  /* 805345D8 8865000A */ lbz         r3, 0xa(r5)
  /* 805345DC 3806FC18 */ addi        r0, r6, -0x3e8
  /* 805345E0 5406043E */ clrlwi      r6, r0, 0x10
  /* 805345E4 38630001 */ addi        r3, r3, 0x1
  /* 805345E8 5460063E */ clrlwi      r0, r3, 0x18
  /* 805345EC 2800003B */ cmplwi      r0, 0x3b
  /* 805345F0 40810010 */ ble-        lbl_80534600
  /* 805345F4 3803FFC4 */ addi        r0, r3, -0x3c
  /* 805345F8 38E00001 */ li          r7, 0x1
  /* 805345FC 5403063E */ clrlwi      r3, r0, 0x18
  lbl_80534600:
  /* 80534600 A0050008 */ lhz         r0, 8(r5)
  /* 80534604 7CE70214 */ add         r7, r7, r0
  /* 80534608 54E0043E */ clrlwi      r0, r7, 0x10
  /* 8053460C 280003E7 */ cmplwi      r0, 0x3e7
  /* 80534610 40810010 */ ble-        lbl_80534620
  /* 80534614 38E003E7 */ li          r7, 0x3e7
  /* 80534618 3860003B */ li          r3, 0x3b
  /* 8053461C 38C003E7 */ li          r6, 0x3e7
  lbl_80534620:
  /* 80534620 38000001 */ li          r0, 0x1
  /* 80534624 98010036 */ stb         r0, 0x36(r1)
  /* 80534628 B0E10030 */ sth         r7, 0x30(r1)
  /* 8053462C 98610032 */ stb         r3, 0x32(r1)
  /* 80534630 B0C10034 */ sth         r6, 0x34(r1)
  /* 80534634 48000020 */ b           lbl_80534654
  lbl_80534638:
  /* 80534638 8885000A */ lbz         r4, 0xa(r5)
  /* 8053463C 38000001 */ li          r0, 0x1
  /* 80534640 A0650008 */ lhz         r3, 8(r5)
  /* 80534644 B0610030 */ sth         r3, 0x30(r1)
  /* 80534648 98010036 */ stb         r0, 0x36(r1)
  /* 8053464C 98810032 */ stb         r4, 0x32(r1)
  /* 80534650 B0C10034 */ sth         r6, 0x34(r1)
  lbl_80534654:
  /* 80534654 7FC3F378 */ mr          r3, r30
  /* 80534658 7FE6FB78 */ mr          r6, r31
  /* 8053465C 3881002C */ addi        r4, r1, 0x2c
  /* 80534660 38A00001 */ li          r5, 0x1
  /* 80534664 48000191 */ bl          RaceinfoPlayer_endRace
  /* 80534668 80010064 */ lwz         r0, 0x64(r1)
  /* 8053466C 83E1005C */ lwz         r31, 0x5c(r1)
  /* 80534670 83C10058 */ lwz         r30, 0x58(r1)
  /* 80534674 83A10054 */ lwz         r29, 0x54(r1)
  /* 80534678 7C0803A6 */ mtlr        r0
  /* 8053467C 38210060 */ addi        r1, r1, 0x60
  /* 80534680 4E800020 */ blr // clang-format on
}

// Symbol: unk_80534684
// PAL: 0x80534684..0x805347f4
MARK_BINARY_BLOB(unk_80534684, 0x80534684, 0x805347f4);
asm UNKNOWN_FUNCTION(unk_80534684) {
  // clang-format off
  nofralloc
  /* 80534684 9421FFC0 */ stwu        r1, -0x40(r1)
  /* 80534688 7C0802A6 */ mflr        r0
  /* 8053468C 90010044 */ stw         r0, 0x44(r1)
  /* 80534690 DBE10030 */ stfd        f31, 0x30(r1)
  /* 80534694 F3E10038 */ opword      0xf3e10038
  /* 80534698 FFE00890 */ fmr         f31, f1
  /* 8053469C A0040004 */ lhz         r0, 4(r4)
  /* 805346A0 93E1002C */ stw         r31, 0x2c(r1)
  /* 805346A4 1C00003C */ mulli       r0, r0, 0x3c
  /* 805346A8 88A40006 */ lbz         r5, 6(r4)
  /* 805346AC 93C10028 */ stw         r30, 0x28(r1)
  /* 805346B0 7C7E1B78 */ mr          r30, r3
  /* 805346B4 A0640008 */ lhz         r3, 8(r4)
  /* 805346B8 7C050214 */ add         r0, r5, r0
  /* 805346BC 1C0003E8 */ mulli       r0, r0, 0x3e8
  /* 805346C0 93A10024 */ stw         r29, 0x24(r1)
  /* 805346C4 93810020 */ stw         r28, 0x20(r1)
  /* 805346C8 7C830214 */ add         r4, r3, r0
  /* 805346CC 7C83FE70 */ srawi       r3, r4, 0x1f
  /* 805346D0 4BAED391 */ bl          __cvt_ull_flt
  /* 805346D4 EC3F0072 */ fmuls       f1, f31, f1
  /* 805346D8 4BAED429 */ bl          __cvt_dbl_ull
  /* 805346DC 3CA00393 */ lis         r5, 0x393
  /* 805346E0 38C00000 */ li          r6, 0x0
  /* 805346E4 38059CA0 */ addi        r0, r5, -0x6360
  /* 805346E8 7C9F2378 */ mr          r31, r4
  /* 805346EC 7C002010 */ subfc       r0, r0, r4
  /* 805346F0 7C7D1B78 */ mr          r29, r3
  /* 805346F4 7C061910 */ subfe       r0, r6, r3
  /* 805346F8 7C042110 */ subfe       r0, r4, r4
  /* 805346FC 7C0000D1 */ neg.        r0, r0
  /* 80534700 40820030 */ bne-        lbl_80534730
  /* 80534704 3CA0808B */ lis         r5, __vt__Q26System4Time@ha
  /* 80534708 3C600001 */ lis         r3, 1
  /* 8053470C 38A52D44 */ addi        r5, r5, __vt__Q26System4Time@l
  /* 80534710 38800001 */ li          r4, 0x1
  /* 80534714 3803FFFF */ addi        r0, r3, -0x1
  /* 80534718 90BE0000 */ stw         r5, 0(r30)
  /* 8053471C 989E000A */ stb         r4, 0xa(r30)
  /* 80534720 B01E0004 */ sth         r0, 4(r30)
  /* 80534724 98DE0006 */ stb         r6, 6(r30)
  /* 80534728 B0DE0008 */ sth         r6, 8(r30)
  /* 8053472C 480000A0 */ b           lbl_805347cc
  lbl_80534730:
  /* 80534730 4BAED331 */ bl          __cvt_ull_flt
  /* 80534734 3C808089 */ lis         r4, lbl_80890188@ha
  /* 80534738 3C600001 */ lis         r3, 1
  /* 8053473C C0040188 */ lfs         f0, lbl_80890188@l(r4)
  /* 80534740 3803EA60 */ addi        r0, r3, -0x15a0
  /* 80534744 EC000072 */ fmuls       f0, f0, f1
  /* 80534748 FC00001E */ fctiwz      f0, f0
  /* 8053474C D8010008 */ stfd        f0, 8(r1)
  /* 80534750 8381000C */ lwz         r28, 0xc(r1)
  /* 80534754 5783043E */ clrlwi      r3, r28, 0x10
  /* 80534758 7C6301D6 */ mullw       r3, r3, r0
  /* 8053475C 7C60FE70 */ srawi       r0, r3, 0x1f
  /* 80534760 7FE3F810 */ subfc       r31, r3, r31
  /* 80534764 7FA0E910 */ subfe       r29, r0, r29
  /* 80534768 7FA3EB78 */ mr          r3, r29
  /* 8053476C 7FE4FB78 */ mr          r4, r31
  /* 80534770 4BAED2F1 */ bl          __cvt_ull_flt
  /* 80534774 3C808089 */ lis         r4, lbl_8089018c@ha
  /* 80534778 38000001 */ li          r0, 0x1
  /* 8053477C C004018C */ lfs         f0, lbl_8089018c@l(r4)
  /* 80534780 3C60808B */ lis         r3, __vt__Q26System4Time@ha
  /* 80534784 38632D44 */ addi        r3, r3, __vt__Q26System4Time@l
  /* 80534788 981E000A */ stb         r0, 0xa(r30)
  /* 8053478C EC000072 */ fmuls       f0, f0, f1
  /* 80534790 38C003E8 */ li          r6, 0x3e8
  /* 80534794 907E0000 */ stw         r3, 0(r30)
  /* 80534798 38A00000 */ li          r5, 0x0
  /* 8053479C FC00001E */ fctiwz      f0, f0
  /* 805347A0 B39E0004 */ sth         r28, 4(r30)
  /* 805347A4 D8010010 */ stfd        f0, 0x10(r1)
  /* 805347A8 80010014 */ lwz         r0, 0x14(r1)
  /* 805347AC 981E0006 */ stb         r0, 6(r30)
  /* 805347B0 5400063E */ clrlwi      r0, r0, 0x18
  /* 805347B4 1C6003E8 */ mulli       r3, r0, 0x3e8
  /* 805347B8 7C60FE70 */ srawi       r0, r3, 0x1f
  /* 805347BC 7C83F810 */ subfc       r4, r3, r31
  /* 805347C0 7C60E910 */ subfe       r3, r0, r29
  /* 805347C4 4BAED065 */ bl          __mod2u
  /* 805347C8 B09E0008 */ sth         r4, 8(r30)
  lbl_805347cc:
  /* 805347CC E3E10038 */ opword      0xe3e10038
  /* 805347D0 80010044 */ lwz         r0, 0x44(r1)
  /* 805347D4 CBE10030 */ lfd         f31, 0x30(r1)
  /* 805347D8 83E1002C */ lwz         r31, 0x2c(r1)
  /* 805347DC 83C10028 */ lwz         r30, 0x28(r1)
  /* 805347E0 83A10024 */ lwz         r29, 0x24(r1)
  /* 805347E4 83810020 */ lwz         r28, 0x20(r1)
  /* 805347E8 7C0803A6 */ mtlr        r0
  /* 805347EC 38210040 */ addi        r1, r1, 0x40
  /* 805347F0 4E800020 */ blr // clang-format on
}

// Symbol: RaceinfoPlayer_endRace
// PAL: 0x805347f4..0x80534934
MARK_BINARY_BLOB(RaceinfoPlayer_endRace, 0x805347f4, 0x80534934);
asm UNKNOWN_FUNCTION(RaceinfoPlayer_endRace) {
  // clang-format off
  nofralloc
  /* 805347F4 9421FFF0 */ stwu        r1, -0x10(r1)
  /* 805347F8 7C0802A6 */ mflr        r0
  /* 805347FC 39800000 */ li          r12, 0x0
  /* 80534800 3D60809C */ lis         r11, spInstance__Q26System11RaceManager@ha
  /* 80534804 90010014 */ stw         r0, 0x14(r1)
  /* 80534808 38000000 */ li          r0, 0x0
  /* 8053480C 39400001 */ li          r10, 0x1
  /* 80534810 3D00809C */ lis         r8, spInstance__Q26System10RaceConfig@ha
  /* 80534814 93E1000C */ stw         r31, 0xc(r1)
  /* 80534818 7C7F1B78 */ mr          r31, r3
  /* 8053481C B0030050 */ sth         r0, 0x50(r3)
  /* 80534820 48000040 */ b           lbl_80534860
  lbl_80534824:
  /* 80534824 80EBD730 */ lwz         r7, spInstance__Q26System11RaceManager@l(r11)
  /* 80534828 558015BA */ rlwinm      r0, r12, 2, 0x16, 0x1d
  /* 8053482C 80E7000C */ lwz         r7, 0xc(r7)
  /* 80534830 7CE7002E */ lwzx        r7, r7, r0
  /* 80534834 80E70038 */ lwz         r7, 0x38(r7)
  /* 80534838 54E007BD */ rlwinm.     r0, r7, 0, 0x1e, 0x1e
  /* 8053483C 4082000C */ bne-        lbl_80534848
  /* 80534840 54E00739 */ rlwinm.     r0, r7, 0, 0x1c, 0x1c
  /* 80534844 41820018 */ beq-        lbl_8053485c
  lbl_80534848:
  /* 80534848 5580063E */ clrlwi      r0, r12, 0x18
  /* 8053484C A0E30050 */ lhz         r7, 0x50(r3)
  /* 80534850 7D400030 */ slw         r0, r10, r0
  /* 80534854 7CE00378 */ or          r0, r7, r0
  /* 80534858 B0030050 */ sth         r0, 0x50(r3)
  lbl_8053485c:
  /* 8053485C 398C0001 */ addi        r12, r12, 0x1
  lbl_80534860:
  /* 80534860 80E8D728 */ lwz         r7, spInstance__Q26System10RaceConfig@l(r8)
  /* 80534864 5589063E */ clrlwi      r9, r12, 0x18
  /* 80534868 88070024 */ lbz         r0, 0x24(r7)
  /* 8053486C 7C090040 */ cmplw       r9, r0
  /* 80534870 4180FFB4 */ blt+        lbl_80534824
  /* 80534874 3CE0809C */ lis         r7, spInstance__Q26System11RaceManager@ha
  /* 80534878 80030038 */ lwz         r0, 0x38(r3)
  /* 8053487C 80E7D730 */ lwz         r7, spInstance__Q26System11RaceManager@l(r7)
  /* 80534880 2C050000 */ cmpwi       r5, 0x0
  /* 80534884 60000002 */ ori         r0, r0, 2
  /* 80534888 81030040 */ lwz         r8, 0x40(r3)
  /* 8053488C 88A7001C */ lbz         r5, 0x1c(r7)
  /* 80534890 98A30052 */ stb         r5, 0x52(r3)
  /* 80534894 A0A40004 */ lhz         r5, 4(r4)
  /* 80534898 90030038 */ stw         r0, 0x38(r3)
  /* 8053489C 88040006 */ lbz         r0, 6(r4)
  /* 805348A0 B0A80004 */ sth         r5, 4(r8)
  /* 805348A4 A0A40008 */ lhz         r5, 8(r4)
  /* 805348A8 98080006 */ stb         r0, 6(r8)
  /* 805348AC 8804000A */ lbz         r0, 0xa(r4)
  /* 805348B0 B0A80008 */ sth         r5, 8(r8)
  /* 805348B4 9808000A */ stb         r0, 0xa(r8)
  /* 805348B8 90C30044 */ stw         r6, 0x44(r3)
  /* 805348BC 41820010 */ beq-        lbl_805348cc
  /* 805348C0 80030038 */ lwz         r0, 0x38(r3)
  /* 805348C4 60000040 */ ori         r0, r0, 0x40
  /* 805348C8 90030038 */ stw         r0, 0x38(r3)
  lbl_805348cc:
  /* 805348CC 88A30008 */ lbz         r5, 8(r3)
  /* 805348D0 3C80809C */ lis         r4, spInstance__Q26System10RaceConfig@ha
  /* 805348D4 8084D728 */ lwz         r4, spInstance__Q26System10RaceConfig@l(r4)
  /* 805348D8 1C0500F0 */ mulli       r0, r5, 0xf0
  /* 805348DC 7C840214 */ add         r4, r4, r0
  /* 805348E0 8804002E */ lbz         r0, 0x2e(r4)
  /* 805348E4 7C000774 */ extsb       r0, r0
  /* 805348E8 2C00FFFF */ cmpwi       r0, -0x1
  /* 805348EC 4182001C */ beq-        lbl_80534908
  /* 805348F0 3C80809C */ lis         r4, spInstance__Q26System12KPadDirector@ha
  /* 805348F4 1C050180 */ mulli       r0, r5, 0x180
  /* 805348F8 8084D70C */ lwz         r4, spInstance__Q26System12KPadDirector@l(r4)
  /* 805348FC 7C840214 */ add         r4, r4, r0
  /* 80534900 380403B4 */ addi        r0, r4, 0x3b4
  /* 80534904 90030048 */ stw         r0, 0x48(r3)
  lbl_80534908:
  /* 80534908 88630008 */ lbz         r3, 8(r3)
  /* 8053490C 4805B805 */ bl          unk_80590110
  /* 80534910 3C60809C */ lis         r3, spInstance__Q26System11RaceManager@ha
  /* 80534914 889F0008 */ lbz         r4, 8(r31)
  /* 80534918 8063D730 */ lwz         r3, spInstance__Q26System11RaceManager@l(r3)
  /* 8053491C 4BFFF351 */ bl          unk_80533c6c
  /* 80534920 80010014 */ lwz         r0, 0x14(r1)
  /* 80534924 83E1000C */ lwz         r31, 0xc(r1)
  /* 80534928 7C0803A6 */ mtlr        r0
  /* 8053492C 38210010 */ addi        r1, r1, 0x10
  /* 80534930 4E800020 */ blr // clang-format on
}

// Symbol: unk_80534934
// PAL: 0x80534934..0x805349b8
MARK_BINARY_BLOB(unk_80534934, 0x80534934, 0x805349b8);
asm UNKNOWN_FUNCTION(unk_80534934){
  // clang-format off
  nofralloc
  /* 80534934 9421FFF0 */ stwu        r1, -0x10(r1)
  /* 80534938 7C0802A6 */ mflr        r0
  /* 8053493C 90010014 */ stw         r0, 0x14(r1)
  /* 80534940 93E1000C */ stw         r31, 0xc(r1)
  /* 80534944 7C7F1B78 */ mr          r31, r3
  /* 80534948 8063004C */ lwz         r3, 0x4c(r3)
  /* 8053494C 4BB50765 */ bl          unk_800850b0
  /* 80534950 2C030000 */ cmpwi       r3, 0x0
  /* 80534954 38600000 */ li          r3, 0x0
  /* 80534958 4182004C */ beq-        lbl_805349a4
  /* 8053495C 809F004C */ lwz         r4, 0x4c(r31)
  /* 80534960 3804FFFF */ addi        r0, r4, -0x1
  /* 80534964 7C830034 */ cntlzw      r3, r4
  /* 80534968 7C002078 */ andc        r0, r0, r4
  /* 8053496C 7C000034 */ cntlzw      r0, r0
  /* 80534970 20000020 */ subfic      r0, r0, 0x20
  /* 80534974 2C000000 */ cmpwi       r0, 0x0
  /* 80534978 4182000C */ beq-        lbl_80534984
  /* 8053497C 2C030000 */ cmpwi       r3, 0x0
  /* 80534980 4082000C */ bne-        lbl_8053498c
  lbl_80534984:
  /* 80534984 38600000 */ li          r3, 0x0
  /* 80534988 4800001C */ b           lbl_805349a4
  lbl_8053498c:
  /* 8053498C 7C030214 */ add         r0, r3, r0
  /* 80534990 2000001F */ subfic      r0, r0, 0x1f
  /* 80534994 7C030734 */ extsh       r3, r0
  /* 80534998 2C030009 */ cmpwi       r3, 0x9
  /* 8053499C 40810008 */ ble-        lbl_805349a4
  /* 805349A0 38600000 */ li          r3, 0x0
  lbl_805349a4:
  /* 805349A4 80010014 */ lwz         r0, 0x14(r1)
  /* 805349A8 83E1000C */ lwz         r31, 0xc(r1)
  /* 805349AC 7C0803A6 */ mtlr        r0
  /* 805349B0 38210010 */ addi        r1, r1, 0x10
  /* 805349B4 4E800020 */ blr // clang-format on
}

// Symbol: RaceinfoPlayer_endLap
// PAL: 0x805349b8..0x80534c78
MARK_BINARY_BLOB(RaceinfoPlayer_endLap, 0x805349b8, 0x80534c78);
asm UNKNOWN_FUNCTION(RaceinfoPlayer_endLap) {
  // clang-format off
  nofralloc
  /* 805349B8 9421FFB0 */ stwu        r1, -0x50(r1)
  /* 805349BC 7C0802A6 */ mflr        r0
  /* 805349C0 90010054 */ stw         r0, 0x54(r1)
  /* 805349C4 39610050 */ addi        r11, r1, 0x50
  /* 805349C8 4BAECBD9 */ bl          _savegpr_27
  /* 805349CC 3BE00000 */ li          r31, 0x0
  /* 805349D0 9BE30028 */ stb         r31, 0x28(r3)
  /* 805349D4 80A30038 */ lwz         r5, 0x38(r3)
  /* 805349D8 3CC0809C */ lis         r6, spInstance__Q26System11RaceManager@ha
  /* 805349DC 8086D730 */ lwz         r4, spInstance__Q26System11RaceManager@l(r6)
  /* 805349E0 7C7D1B78 */ mr          r29, r3
  /* 805349E4 54A007BD */ rlwinm.     r0, r5, 0, 0x1e, 0x1e
  /* 805349E8 83C40014 */ lwz         r30, 0x14(r4)
  /* 805349EC 40820274 */ bne-        lbl_80534c60
  /* 805349F0 54A00739 */ rlwinm.     r0, r5, 0, 0x1c, 0x1c
  /* 805349F4 4082026C */ bne-        lbl_80534c60
  /* 805349F8 A8830024 */ lha         r4, 0x24(r3)
  /* 805349FC 38A40001 */ addi        r5, r4, 0x1
  /* 80534A00 B0A30024 */ sth         r5, 0x24(r3)
  /* 80534A04 8086D730 */ lwz         r4, spInstance__Q26System11RaceManager@l(r6)
  /* 80534A08 88040030 */ lbz         r0, 0x30(r4)
  /* 80534A0C 2C000000 */ cmpwi       r0, 0x0
  /* 80534A10 41820250 */ beq-        lbl_80534c60
  /* 80534A14 88030026 */ lbz         r0, 0x26(r3)
  /* 80534A18 7CA30734 */ extsh       r3, r5
  /* 80534A1C 7C030000 */ cmpw        r3, r0
  /* 80534A20 40810240 */ ble-        lbl_80534c60
  /* 80534A24 3F80809C */ lis         r28, lbl_809c18f8@ha
  /* 80534A28 889D0008 */ lbz         r4, 8(r29)
  /* 80534A2C 807C18F8 */ lwz         r3, lbl_809c18f8@l(r28)
  /* 80534A30 4805B6D1 */ bl          PlayerHolder_getPlayer
  /* 80534A34 4805B7F1 */ bl          PlayerPointers_getPlayerPhysicsHolderPosition
  /* 80534A38 7C7B1B78 */ mr          r27, r3
  /* 80534A3C 807C18F8 */ lwz         r3, lbl_809c18f8@l(r28)
  /* 80534A40 889D0008 */ lbz         r4, 8(r29)
  /* 80534A44 4805B6BD */ bl          PlayerHolder_getPlayer
  /* 80534A48 4805B7C5 */ bl          getPos__Q24Kart15KartObjectProxyCFv
  /* 80534A4C 3C80809C */ lis         r4, spInstance__Q26System9CourseMap@ha
  /* 80534A50 7C651B78 */ mr          r5, r3
  /* 80534A54 8064D6E8 */ lwz         r3, spInstance__Q26System9CourseMap@l(r4)
  /* 80534A58 7F66DB78 */ mr          r6, r27
  /* 80534A5C A09D000A */ lhz         r4, 0xa(r29)
  /* 80534A60 4BFDD41D */ bl          computeExactFinishingTime
  /* 80534A64 3CA0808B */ lis         r5, __vt__Q26System4Time@ha
  /* 80534A68 3C804330 */ lis         r4, 0x4330
  /* 80534A6C 38A52D44 */ addi        r5, r5, __vt__Q26System4Time@l
  /* 80534A70 90A10008 */ stw         r5, 8(r1)
  /* 80534A74 5465043E */ clrlwi      r5, r3, 0x10
  /* 80534A78 3C608089 */ lis         r3, lbl_80890170@ha
  /* 80534A7C 9BE10012 */ stb         r31, 0x12(r1)
  /* 80534A80 38C00000 */ li          r6, 0x0
  /* 80534A84 C8430170 */ lfd         f2, lbl_80890170@l(r3)
  /* 80534A88 B3E1000C */ sth         r31, 0xc(r1)
  /* 80534A8C 9BE1000E */ stb         r31, 0xe(r1)
  /* 80534A90 B3E10010 */ sth         r31, 0x10(r1)
  /* 80534A94 A01E000C */ lhz         r0, 0xc(r30)
  /* 80534A98 90A1001C */ stw         r5, 0x1c(r1)
  /* 80534A9C 90810018 */ stw         r4, 0x18(r1)
  /* 80534AA0 C8010018 */ lfd         f0, 0x18(r1)
  /* 80534AA4 90010024 */ stw         r0, 0x24(r1)
  /* 80534AA8 EC201028 */ fsubs       f1, f0, f2
  /* 80534AAC 90810020 */ stw         r4, 0x20(r1)
  /* 80534AB0 C8010020 */ lfd         f0, 0x20(r1)
  /* 80534AB4 EC001028 */ fsubs       f0, f0, f2
  /* 80534AB8 EC01002A */ fadds       f0, f1, f0
  /* 80534ABC FC00001E */ fctiwz      f0, f0
  /* 80534AC0 D8010028 */ stfd        f0, 0x28(r1)
  /* 80534AC4 80A1002C */ lwz         r5, 0x2c(r1)
  /* 80534AC8 54A0043E */ clrlwi      r0, r5, 0x10
  /* 80534ACC 280003E7 */ cmplwi      r0, 0x3e7
  /* 80534AD0 40810064 */ ble-        lbl_80534b34
  /* 80534AD4 887E000A */ lbz         r3, 0xa(r30)
  /* 80534AD8 3805FC18 */ addi        r0, r5, -0x3e8
  /* 80534ADC 5405043E */ clrlwi      r5, r0, 0x10
  /* 80534AE0 38630001 */ addi        r3, r3, 0x1
  /* 80534AE4 5460063E */ clrlwi      r0, r3, 0x18
  /* 80534AE8 2800003B */ cmplwi      r0, 0x3b
  /* 80534AEC 40810010 */ ble-        lbl_80534afc
  /* 80534AF0 3803FFC4 */ addi        r0, r3, -0x3c
  /* 80534AF4 38C00001 */ li          r6, 0x1
  /* 80534AF8 5403063E */ clrlwi      r3, r0, 0x18
  lbl_80534afc:
  /* 80534AFC A01E0008 */ lhz         r0, 8(r30)
  /* 80534B00 7CC60214 */ add         r6, r6, r0
  /* 80534B04 54C0043E */ clrlwi      r0, r6, 0x10
  /* 80534B08 280003E7 */ cmplwi      r0, 0x3e7
  /* 80534B0C 40810010 */ ble-        lbl_80534b1c
  /* 80534B10 38C003E7 */ li          r6, 0x3e7
  /* 80534B14 3860003B */ li          r3, 0x3b
  /* 80534B18 38A003E7 */ li          r5, 0x3e7
  lbl_80534b1c:
  /* 80534B1C 38000001 */ li          r0, 0x1
  /* 80534B20 98010012 */ stb         r0, 0x12(r1)
  /* 80534B24 B0C1000C */ sth         r6, 0xc(r1)
  /* 80534B28 9861000E */ stb         r3, 0xe(r1)
  /* 80534B2C B0A10010 */ sth         r5, 0x10(r1)
  /* 80534B30 48000020 */ b           lbl_80534b50
  lbl_80534b34:
  /* 80534B34 889E000A */ lbz         r4, 0xa(r30)
  /* 80534B38 38000001 */ li          r0, 0x1
  /* 80534B3C A07E0008 */ lhz         r3, 8(r30)
  /* 80534B40 B061000C */ sth         r3, 0xc(r1)
  /* 80534B44 98010012 */ stb         r0, 0x12(r1)
  /* 80534B48 9881000E */ stb         r4, 0xe(r1)
  /* 80534B4C B0A10010 */ sth         r5, 0x10(r1)
  lbl_80534b50:
  /* 80534B50 887D0026 */ lbz         r3, 0x26(r29)
  /* 80534B54 809D003C */ lwz         r4, 0x3c(r29)
  /* 80534B58 3863FFFF */ addi        r3, r3, -0x1
  /* 80534B5C A001000C */ lhz         r0, 0xc(r1)
  /* 80534B60 1C63000C */ mulli       r3, r3, 0xc
  /* 80534B64 7C841A14 */ add         r4, r4, r3
  /* 80534B68 B0040004 */ sth         r0, 4(r4)
  /* 80534B6C 8801000E */ lbz         r0, 0xe(r1)
  /* 80534B70 98040006 */ stb         r0, 6(r4)
  /* 80534B74 A0010010 */ lhz         r0, 0x10(r1)
  /* 80534B78 B0040008 */ sth         r0, 8(r4)
  /* 80534B7C 88010012 */ lbz         r0, 0x12(r1)
  /* 80534B80 9804000A */ stb         r0, 0xa(r4)
  /* 80534B84 881E0040 */ lbz         r0, 0x40(r30)
  /* 80534B88 2C000000 */ cmpwi       r0, 0x0
  /* 80534B8C 4182001C */ beq-        lbl_80534ba8
  /* 80534B90 3C600001 */ lis         r3, 1
  /* 80534B94 38000000 */ li          r0, 0x0
  /* 80534B98 3863FFFF */ addi        r3, r3, -0x1
  /* 80534B9C B0640004 */ sth         r3, 4(r4)
  /* 80534BA0 98040006 */ stb         r0, 6(r4)
  /* 80534BA4 B0040008 */ sth         r0, 8(r4)
  lbl_80534ba8:
  /* 80534BA8 3C60809C */ lis         r3, spInstance__Q26System10RaceConfig@ha
  /* 80534BAC 38800003 */ li          r4, 0x3
  /* 80534BB0 80A3D728 */ lwz         r5, spInstance__Q26System10RaceConfig@l(r3)
  /* 80534BB4 80050B90 */ lwz         r0, 0xb90(r5)
  /* 80534BB8 5400077B */ rlwinm.     r0, r0, 0, 0x1d, 0x1d
  /* 80534BBC 4182001C */ beq-        lbl_80534bd8
  /* 80534BC0 88850B8D */ lbz         r4, 0xb8d(r5)
  /* 80534BC4 380400FF */ addi        r0, r4, 0xff
  /* 80534BC8 5400063E */ clrlwi      r0, r0, 0x18
  /* 80534BCC 28000008 */ cmplwi      r0, 8
  /* 80534BD0 40810008 */ ble-        lbl_80534bd8
  /* 80534BD4 38800003 */ li          r4, 0x3
  lbl_80534bd8:
  /* 80534BD8 887D0026 */ lbz         r3, 0x26(r29)
  /* 80534BDC 5480063E */ clrlwi      r0, r4, 0x18
  /* 80534BE0 7C030040 */ cmplw       r3, r0
  /* 80534BE4 41800074 */ blt-        lbl_80534c58
  /* 80534BE8 881D0008 */ lbz         r0, 8(r29)
  /* 80534BEC 1C0000F0 */ mulli       r0, r0, 0xf0
  /* 80534BF0 7C650214 */ add         r3, r5, r0
  /* 80534BF4 80030038 */ lwz         r0, 0x38(r3)
  /* 80534BF8 2C000004 */ cmpwi       r0, 0x4
  /* 80534BFC 40820014 */ bne-        lbl_80534c10
  /* 80534C00 801D0038 */ lwz         r0, 0x38(r29)
  /* 80534C04 60000008 */ ori         r0, r0, 8
  /* 80534C08 901D0038 */ stw         r0, 0x38(r29)
  /* 80534C0C 48000054 */ b           lbl_80534c60
  lbl_80534c10:
  /* 80534C10 7FA3EB78 */ mr          r3, r29
  /* 80534C14 38810008 */ addi        r4, r1, 0x8
  /* 80534C18 38A00000 */ li          r5, 0x0
  /* 80534C1C 38C00001 */ li          r6, 0x1
  /* 80534C20 4BFFFBD5 */ bl          RaceinfoPlayer_endRace
  /* 80534C24 881E0040 */ lbz         r0, 0x40(r30)
  /* 80534C28 2C000000 */ cmpwi       r0, 0x0
  /* 80534C2C 41820034 */ beq-        lbl_80534c60
  /* 80534C30 80BD0040 */ lwz         r5, 0x40(r29)
  /* 80534C34 38000001 */ li          r0, 0x1
  /* 80534C38 38800063 */ li          r4, 0x63
  /* 80534C3C 3860003B */ li          r3, 0x3b
  /* 80534C40 9805000A */ stb         r0, 0xa(r5)
  /* 80534C44 380003E7 */ li          r0, 0x3e7
  /* 80534C48 B0850004 */ sth         r4, 4(r5)
  /* 80534C4C 98650006 */ stb         r3, 6(r5)
  /* 80534C50 B0050008 */ sth         r0, 8(r5)
  /* 80534C54 4800000C */ b           lbl_80534c60
  lbl_80534c58:
  /* 80534C58 A81D0024 */ lha         r0, 0x24(r29)
  /* 80534C5C 981D0026 */ stb         r0, 0x26(r29)
  lbl_80534c60:
  /* 80534C60 39610050 */ addi        r11, r1, 0x50
  /* 80534C64 4BAEC989 */ bl          _restgpr_27
  /* 80534C68 80010054 */ lwz         r0, 0x54(r1)
  /* 80534C6C 7C0803A6 */ mtlr        r0
  /* 80534C70 38210050 */ addi        r1, r1, 0x50
  /* 80534C74 4E800020 */ blr // clang-format on
}

// Symbol: unk_80534c78
// PAL: 0x80534c78..0x80534cbc
MARK_BINARY_BLOB(unk_80534c78, 0x80534c78, 0x80534cbc);
asm UNKNOWN_FUNCTION(unk_80534c78) {
  // clang-format off
  nofralloc
  /* 80534C78 9421FFF0 */ stwu        r1, -0x10(r1)
  /* 80534C7C 7C0802A6 */ mflr        r0
  /* 80534C80 3CA0809C */ lis         r5, lbl_809c18f8@ha
  /* 80534C84 90010014 */ stw         r0, 0x14(r1)
  /* 80534C88 80030038 */ lwz         r0, 0x38(r3)
  /* 80534C8C 88830008 */ lbz         r4, 8(r3)
  /* 80534C90 60000020 */ ori         r0, r0, 0x20
  /* 80534C94 90030038 */ stw         r0, 0x38(r3)
  /* 80534C98 806518F8 */ lwz         r3, lbl_809c18f8@l(r5)
  /* 80534C9C 4805B465 */ bl          PlayerHolder_getPlayer
  /* 80534CA0 4805BADD */ bl          kartMove__Q24Kart15KartObjectProxyFv
  /* 80534CA4 38800001 */ li          r4, 0x1
  /* 80534CA8 4804C6FD */ bl          unk_805813a4
  /* 80534CAC 80010014 */ lwz         r0, 0x14(r1)
  /* 80534CB0 7C0803A6 */ mtlr        r0
  /* 80534CB4 38210010 */ addi        r1, r1, 0x10
  /* 80534CB8 4E800020 */ blr // clang-format on
}

// Symbol: unk_80534cbc
// PAL: 0x80534cbc..0x80534ccc
MARK_BINARY_BLOB(unk_80534cbc, 0x80534cbc, 0x80534ccc);
asm UNKNOWN_FUNCTION(unk_80534cbc){
    // clang-format off
  nofralloc
  /* 80534CBC 80030038 */ lwz         r0, 0x38(r3)
  /* 80534CC0 60000010 */ ori         r0, r0, 0x10
  /* 80534CC4 90030038 */ stw         r0, 0x38(r3)
  /* 80534CC8 4E800020 */ blr // clang-format on
}

// Symbol: unk_80534ccc
// PAL: 0x80534ccc..0x80534d6c
MARK_BINARY_BLOB(unk_80534ccc, 0x80534ccc, 0x80534d6c);
asm UNKNOWN_FUNCTION(unk_80534ccc) {
  // clang-format off
  nofralloc
  /* 80534CCC 9421FFF0 */ stwu        r1, -0x10(r1)
  /* 80534CD0 7C0802A6 */ mflr        r0
  /* 80534CD4 3CA0809C */ lis         r5, spInstance__Q26System10RaceConfig@ha
  /* 80534CD8 38C00003 */ li          r6, 0x3
  /* 80534CDC 90010014 */ stw         r0, 0x14(r1)
  /* 80534CE0 93E1000C */ stw         r31, 0xc(r1)
  /* 80534CE4 7C7F1B78 */ mr          r31, r3
  /* 80534CE8 80A5D728 */ lwz         r5, spInstance__Q26System10RaceConfig@l(r5)
  /* 80534CEC 80050B90 */ lwz         r0, 0xb90(r5)
  /* 80534CF0 5400077B */ rlwinm.     r0, r0, 0, 0x1d, 0x1d
  /* 80534CF4 4182001C */ beq-        lbl_80534d10
  /* 80534CF8 88C50B8D */ lbz         r6, 0xb8d(r5)
  /* 80534CFC 380600FF */ addi        r0, r6, 0xff
  /* 80534D00 5400063E */ clrlwi      r0, r0, 0x18
  /* 80534D04 28000008 */ cmplwi      r0, 8
  /* 80534D08 40810008 */ ble-        lbl_80534d10
  /* 80534D0C 38C00003 */ li          r6, 0x3
  lbl_80534d10:
  /* 80534D10 80030038 */ lwz         r0, 0x38(r3)
  /* 80534D14 54C5063E */ clrlwi      r5, r6, 0x18
  /* 80534D18 B0A30024 */ sth         r5, 0x24(r3)
  /* 80534D1C 54000739 */ rlwinm.     r0, r0, 0, 0x1c, 0x1c
  /* 80534D20 98C30026 */ stb         r6, 0x26(r3)
  /* 80534D24 41820018 */ beq-        lbl_80534d3c
  /* 80534D28 7FE3FB78 */ mr          r3, r31
  /* 80534D2C 38A00000 */ li          r5, 0x0
  /* 80534D30 38C00005 */ li          r6, 0x5
  /* 80534D34 4BFFFAC1 */ bl          RaceinfoPlayer_endRace
  /* 80534D38 48000020 */ b           lbl_80534d58
  lbl_80534d3c:
  /* 80534D3C 7FE3FB78 */ mr          r3, r31
  /* 80534D40 38A00001 */ li          r5, 0x1
  /* 80534D44 38C00005 */ li          r6, 0x5
  /* 80534D48 4BFFFAAD */ bl          RaceinfoPlayer_endRace
  /* 80534D4C 801F0038 */ lwz         r0, 0x38(r31)
  /* 80534D50 60000008 */ ori         r0, r0, 8
  /* 80534D54 901F0038 */ stw         r0, 0x38(r31)
  lbl_80534d58:
  /* 80534D58 80010014 */ lwz         r0, 0x14(r1)
  /* 80534D5C 83E1000C */ lwz         r31, 0xc(r1)
  /* 80534D60 7C0803A6 */ mtlr        r0
  /* 80534D64 38210010 */ addi        r1, r1, 0x10
  /* 80534D68 4E800020 */ blr // clang-format on
}

// Symbol: unk_80534d6c
// PAL: 0x80534d6c..0x80534df8
MARK_BINARY_BLOB(unk_80534d6c, 0x80534d6c, 0x80534df8);
asm UNKNOWN_FUNCTION(unk_80534d6c) {
  // clang-format off
  nofralloc
  /* 80534D6C 80030038 */ lwz         r0, 0x38(r3)
  /* 80534D70 540007BD */ rlwinm.     r0, r0, 0, 0x1e, 0x1e
  /* 80534D74 4C820020 */ bnelr-
  /* 80534D78 3C80809C */ lis         r4, spInstance__Q26System9CourseMap@ha
  /* 80534D7C 80A4D6E8 */ lwz         r5, spInstance__Q26System9CourseMap@l(r4)
  /* 80534D80 80850020 */ lwz         r4, 0x20(r5)
  /* 80534D84 2C040000 */ cmpwi       r4, 0x0
  /* 80534D88 4182000C */ beq-        lbl_80534d94
  /* 80534D8C A0840004 */ lhz         r4, 4(r4)
  /* 80534D90 48000008 */ b           lbl_80534d98
  lbl_80534d94:
  /* 80534D94 38800000 */ li          r4, 0x0
  lbl_80534d98:
  /* 80534D98 7C0400D0 */ neg         r0, r4
  /* 80534D9C 7C002378 */ or          r0, r0, r4
  /* 80534DA0 54000FFF */ rlwinm.     r0, r0, 1, 0x1f, 0x1f
  /* 80534DA4 41820028 */ beq-        lbl_80534dcc
  /* 80534DA8 8085001C */ lwz         r4, 0x1c(r5)
  /* 80534DAC 2C040000 */ cmpwi       r4, 0x0
  /* 80534DB0 4182000C */ beq-        lbl_80534dbc
  /* 80534DB4 A0840004 */ lhz         r4, 4(r4)
  /* 80534DB8 48000008 */ b           lbl_80534dc0
  lbl_80534dbc:
  /* 80534DBC 38800000 */ li          r4, 0x0
  lbl_80534dc0:
  /* 80534DC0 7C0400D0 */ neg         r0, r4
  /* 80534DC4 7C002378 */ or          r0, r0, r4
  /* 80534DC8 54000FFE */ srwi        r0, r0, 0x1f
  lbl_80534dcc:
  /* 80534DCC 2C000000 */ cmpwi       r0, 0x0
  /* 80534DD0 41820010 */ beq-        lbl_80534de0
  /* 80534DD4 80850020 */ lwz         r4, 0x20(r5)
  /* 80534DD8 8804000C */ lbz         r0, 0xc(r4)
  /* 80534DDC 48000008 */ b           lbl_80534de4
  lbl_80534de0:
  /* 80534DE0 3800FFFF */ li          r0, -0x1
  lbl_80534de4:
  /* 80534DE4 A8830024 */ lha         r4, 0x24(r3)
  /* 80534DE8 98030028 */ stb         r0, 0x28(r3)
  /* 80534DEC 3804FFFF */ addi        r0, r4, -0x1
  /* 80534DF0 B0030024 */ sth         r0, 0x24(r3)
  /* 80534DF4 4E800020 */ blr // clang-format on
}

// Symbol: RaceinfoPlayer_updateCheckpoint
// PAL: 0x80534df8..0x8053520c
MARK_BINARY_BLOB(RaceinfoPlayer_updateCheckpoint, 0x80534df8, 0x8053520c);
asm UNKNOWN_FUNCTION(RaceinfoPlayer_updateCheckpoint) {
  // clang-format off
  nofralloc
  /* 80534DF8 9421FFA0 */ stwu        r1, -0x60(r1)
  /* 80534DFC 7C0802A6 */ mflr        r0
  /* 80534E00 90010064 */ stw         r0, 0x64(r1)
  /* 80534E04 DBE10050 */ stfd        f31, 0x50(r1)
  /* 80534E08 F3E10058 */ opword      0xf3e10058
  /* 80534E0C DBC10040 */ stfd        f30, 0x40(r1)
  /* 80534E10 F3C10048 */ opword      0xf3c10048
  /* 80534E14 39610040 */ addi        r11, r1, 0x40
  /* 80534E18 4BAEC781 */ bl          _savegpr_25
  /* 80534E1C A3C3000A */ lhz         r30, 0xa(r3)
  /* 80534E20 3F20809C */ lis         r25, spInstance__Q26System9CourseMap@ha
  /* 80534E24 7C7A1B78 */ mr          r26, r3
  /* 80534E28 FFC00890 */ fmr         f30, f1
  /* 80534E2C B083000A */ sth         r4, 0xa(r3)
  /* 80534E30 549D043E */ clrlwi      r29, r4, 0x10
  /* 80534E34 7C9B2378 */ mr          r27, r4
  /* 80534E38 7CBC2B78 */ mr          r28, r5
  /* 80534E3C 8079D6E8 */ lwz         r3, spInstance__Q26System9CourseMap@l(r25)
  /* 80534E40 7FA4EB78 */ mr          r4, r29
  /* 80534E44 8063001C */ lwz         r3, 0x1c(r3)
  /* 80534E48 C3E3000C */ lfs         f31, 0xc(r3)
  /* 80534E4C 4BFE01C9 */ bl          CheckpathHolder_findCheckpathForCheckpoint
  /* 80534E50 C0030008 */ lfs         f0, 8(r3)
  /* 80534E54 3C004330 */ lis         r0, 0x4330
  /* 80534E58 3C808089 */ lis         r4, lbl_808901a0@ha
  /* 80534E5C 90010008 */ stw         r0, 8(r1)
  /* 80534E60 ECA007F2 */ fmuls       f5, f0, f31
  /* 80534E64 C88401A0 */ lfd         f4, lbl_808901a0@l(r4)
  /* 80534E68 90010010 */ stw         r0, 0x10(r1)
  /* 80534E6C C01A001C */ lfs         f0, 0x1c(r26)
  /* 80534E70 D0BA0014 */ stfs        f5, 0x14(r26)
  /* 80534E74 EC3E0172 */ fmuls       f1, f30, f5
  /* 80534E78 A09A000A */ lhz         r4, 0xa(r26)
  /* 80534E7C 80A30000 */ lwz         r5, 0(r3)
  /* 80534E80 88630004 */ lbz         r3, 4(r3)
  /* 80534E84 88050000 */ lbz         r0, 0(r5)
  /* 80534E88 7C630774 */ extsb       r3, r3
  /* 80534E8C 7C00E850 */ subf        r0, r0, r29
  /* 80534E90 6C638000 */ xoris       r3, r3, 0x8000
  /* 80534E94 9061000C */ stw         r3, 0xc(r1)
  /* 80534E98 6C008000 */ xoris       r0, r0, 0x8000
  /* 80534E9C 90010014 */ stw         r0, 0x14(r1)
  /* 80534EA0 C8610008 */ lfd         f3, 8(r1)
  /* 80534EA4 C8410010 */ lfd         f2, 0x10(r1)
  /* 80534EA8 EC632028 */ fsubs       f3, f3, f4
  /* 80534EAC EC422028 */ fsubs       f2, f2, f4
  /* 80534EB0 EC6307F2 */ fmuls       f3, f3, f31
  /* 80534EB4 EC4500B2 */ fmuls       f2, f5, f2
  /* 80534EB8 EC43102A */ fadds       f2, f3, f2
  /* 80534EBC D05A0018 */ stfs        f2, 0x18(r26)
  /* 80534EC0 EFE2082A */ fadds       f31, f2, f1
  /* 80534EC4 8079D6E8 */ lwz         r3, spInstance__Q26System9CourseMap@l(r25)
  /* 80534EC8 EFC0F828 */ fsubs       f30, f0, f31
  /* 80534ECC 4BFE0D59 */ bl          getCheckPoint__Q26System9CourseMapCFUs
  /* 80534ED0 80830000 */ lwz         r4, 0(r3)
  /* 80534ED4 7C7D1B78 */ mr          r29, r3
  /* 80534ED8 88840010 */ lbz         r4, 0x10(r4)
  /* 80534EDC 7C800775 */ extsb.      r0, r4
  /* 80534EE0 41800008 */ blt-        lbl_80534ee8
  /* 80534EE4 989A0021 */ stb         r4, 0x21(r26)
  lbl_80534ee8:
  /* 80534EE8 80A30000 */ lwz         r5, 0(r3)
  /* 80534EEC 3F20809C */ lis         r25, spInstance__Q26System9CourseMap@ha
  /* 80534EF0 8079D6E8 */ lwz         r3, spInstance__Q26System9CourseMap@l(r25)
  /* 80534EF4 7FC4F378 */ mr          r4, r30
  /* 80534EF8 88050011 */ lbz         r0, 0x11(r5)
  /* 80534EFC 7C1F0774 */ extsb       r31, r0
  /* 80534F00 4BFE0D25 */ bl          getCheckPoint__Q26System9CourseMapCFUs
  /* 80534F04 2C1C0000 */ cmpwi       r28, 0x0
  /* 80534F08 7C7C1B78 */ mr          r28, r3
  /* 80534F0C 418200B8 */ beq-        lbl_80534fc4
  /* 80534F10 3C608089 */ lis         r3, lbl_80890190@ha
  /* 80534F14 C0030190 */ lfs         f0, lbl_80890190@l(r3)
  /* 80534F18 FC1E0040 */ opword      0xfc1e0040
  /* 80534F1C 4080008C */ bge-        lbl_80534fa8
  /* 80534F20 801A0038 */ lwz         r0, 0x38(r26)
  /* 80534F24 540007BD */ rlwinm.     r0, r0, 0, 0x1e, 0x1e
  /* 80534F28 408202B4 */ bne-        lbl_805351dc
  /* 80534F2C 8099D6E8 */ lwz         r4, spInstance__Q26System9CourseMap@l(r25)
  /* 80534F30 80640020 */ lwz         r3, 0x20(r4)
  /* 80534F34 2C030000 */ cmpwi       r3, 0x0
  /* 80534F38 4182000C */ beq-        lbl_80534f44
  /* 80534F3C A0630004 */ lhz         r3, 4(r3)
  /* 80534F40 48000008 */ b           lbl_80534f48
  lbl_80534f44:
  /* 80534F44 38600000 */ li          r3, 0x0
  lbl_80534f48:
  /* 80534F48 7C0300D0 */ neg         r0, r3
  /* 80534F4C 7C001B78 */ or          r0, r0, r3
  /* 80534F50 54000FFF */ rlwinm.     r0, r0, 1, 0x1f, 0x1f
  /* 80534F54 41820028 */ beq-        lbl_80534f7c
  /* 80534F58 8064001C */ lwz         r3, 0x1c(r4)
  /* 80534F5C 2C030000 */ cmpwi       r3, 0x0
  /* 80534F60 4182000C */ beq-        lbl_80534f6c
  /* 80534F64 A0630004 */ lhz         r3, 4(r3)
  /* 80534F68 48000008 */ b           lbl_80534f70
  lbl_80534f6c:
  /* 80534F6C 38600000 */ li          r3, 0x0
  lbl_80534f70:
  /* 80534F70 7C0300D0 */ neg         r0, r3
  /* 80534F74 7C001B78 */ or          r0, r0, r3
  /* 80534F78 54000FFE */ srwi        r0, r0, 0x1f
  lbl_80534f7c:
  /* 80534F7C 2C000000 */ cmpwi       r0, 0x0
  /* 80534F80 41820010 */ beq-        lbl_80534f90
  /* 80534F84 80640020 */ lwz         r3, 0x20(r4)
  /* 80534F88 8803000C */ lbz         r0, 0xc(r3)
  /* 80534F8C 48000008 */ b           lbl_80534f94
  lbl_80534f90:
  /* 80534F90 3800FFFF */ li          r0, -0x1
  lbl_80534f94:
  /* 80534F94 A87A0024 */ lha         r3, 0x24(r26)
  /* 80534F98 981A0028 */ stb         r0, 0x28(r26)
  /* 80534F9C 3803FFFF */ addi        r0, r3, -0x1
  /* 80534FA0 B01A0024 */ sth         r0, 0x24(r26)
  /* 80534FA4 48000238 */ b           lbl_805351dc
  lbl_80534fa8:
  /* 80534FA8 3C608089 */ lis         r3, lbl_80890194@ha
  /* 80534FAC C0030194 */ lfs         f0, lbl_80890194@l(r3)
  /* 80534FB0 FC1E0040 */ opword      0xfc1e0040
  /* 80534FB4 40810228 */ ble-        lbl_805351dc
  /* 80534FB8 7F43D378 */ mr          r3, r26
  /* 80534FBC 4BFFF9FD */ bl          RaceinfoPlayer_endLap
  /* 80534FC0 4800021C */ b           lbl_805351dc
  lbl_80534fc4:
  /* 80534FC4 2C1FFFFF */ cmpwi       r31, -0x1
  /* 80534FC8 41820114 */ beq-        lbl_805350dc
  /* 80534FCC 88BA0028 */ lbz         r5, 0x28(r26)
  /* 80534FD0 7CA00774 */ extsb       r0, r5
  /* 80534FD4 7C1F0000 */ cmpw        r31, r0
  /* 80534FD8 4081000C */ ble-        lbl_80534fe4
  /* 80534FDC 9BFA0028 */ stb         r31, 0x28(r26)
  /* 80534FE0 480000F8 */ b           lbl_805350d8
  lbl_80534fe4:
  /* 80534FE4 80D9D6E8 */ lwz         r6, spInstance__Q26System9CourseMap@l(r25)
  /* 80534FE8 80860020 */ lwz         r4, 0x20(r6)
  /* 80534FEC 2C040000 */ cmpwi       r4, 0x0
  /* 80534FF0 4182000C */ beq-        lbl_80534ffc
  /* 80534FF4 A0840004 */ lhz         r4, 4(r4)
  /* 80534FF8 48000008 */ b           lbl_80535000
  lbl_80534ffc:
  /* 80534FFC 38800000 */ li          r4, 0x0
  lbl_80535000:
  /* 80535000 7C0400D0 */ neg         r0, r4
  /* 80535004 7C002378 */ or          r0, r0, r4
  /* 80535008 54000FFF */ rlwinm.     r0, r0, 1, 0x1f, 0x1f
  /* 8053500C 41820028 */ beq-        lbl_80535034
  /* 80535010 8086001C */ lwz         r4, 0x1c(r6)
  /* 80535014 2C040000 */ cmpwi       r4, 0x0
  /* 80535018 4182000C */ beq-        lbl_80535024
  /* 8053501C A0840004 */ lhz         r4, 4(r4)
  /* 80535020 48000008 */ b           lbl_80535028
  lbl_80535024:
  /* 80535024 38800000 */ li          r4, 0x0
  lbl_80535028:
  /* 80535028 7C0400D0 */ neg         r0, r4
  /* 8053502C 7C002378 */ or          r0, r0, r4
  /* 80535030 54000FFE */ srwi        r0, r0, 0x1f
  lbl_80535034:
  /* 80535034 2C000000 */ cmpwi       r0, 0x0
  /* 80535038 7CA50774 */ extsb       r5, r5
  /* 8053503C 41820010 */ beq-        lbl_8053504c
  /* 80535040 80860020 */ lwz         r4, 0x20(r6)
  /* 80535044 8804000C */ lbz         r0, 0xc(r4)
  /* 80535048 48000008 */ b           lbl_80535050
  lbl_8053504c:
  /* 8053504C 3800FFFF */ li          r0, -0x1
  lbl_80535050:
  /* 80535050 7C000774 */ extsb       r0, r0
  /* 80535054 7C050000 */ cmpw        r5, r0
  /* 80535058 40820080 */ bne-        lbl_805350d8
  /* 8053505C 2C1F0000 */ cmpwi       r31, 0x0
  /* 80535060 40820060 */ bne-        lbl_805350c0
  /* 80535064 A0E30004 */ lhz         r7, 4(r3)
  /* 80535068 7F86E378 */ mr          r6, r28
  /* 8053506C 5764043E */ clrlwi      r4, r27, 0x10
  /* 80535070 38A00000 */ li          r5, 0x0
  /* 80535074 7CE903A6 */ mtctr       r7
  /* 80535078 2C070000 */ cmpwi       r7, 0x0
  /* 8053507C 40810038 */ ble-        lbl_805350b4
  lbl_80535080:
  /* 80535080 7C053800 */ cmpw        r5, r7
  /* 80535084 4080000C */ bge-        lbl_80535090
  /* 80535088 80660038 */ lwz         r3, 0x38(r6)
  /* 8053508C 48000008 */ b           lbl_80535094
  lbl_80535090:
  /* 80535090 38600000 */ li          r3, 0x0
  lbl_80535094:
  /* 80535094 A003001A */ lhz         r0, 0x1a(r3)
  /* 80535098 7C040040 */ cmplw       r4, r0
  /* 8053509C 4082000C */ bne-        lbl_805350a8
  /* 805350A0 38000001 */ li          r0, 0x1
  /* 805350A4 48000014 */ b           lbl_805350b8
  lbl_805350a8:
  /* 805350A8 38C60018 */ addi        r6, r6, 0x18
  /* 805350AC 38A50001 */ addi        r5, r5, 0x1
  /* 805350B0 4200FFD0 */ bdnz        lbl_80535080
  lbl_805350b4:
  /* 805350B4 38000000 */ li          r0, 0x0
  lbl_805350b8:
  /* 805350B8 2C000000 */ cmpwi       r0, 0x0
  /* 805350BC 40820014 */ bne-        lbl_805350d0
  lbl_805350c0:
  /* 805350C0 3C608089 */ lis         r3, lbl_80890198@ha
  /* 805350C4 C0030198 */ lfs         f0, lbl_80890198@l(r3)
  /* 805350C8 FC1E0040 */ opword      0xfc1e0040
  /* 805350CC 4081000C */ ble-        lbl_805350d8
  lbl_805350d0:
  /* 805350D0 7F43D378 */ mr          r3, r26
  /* 805350D4 4BFFF8E5 */ bl          RaceinfoPlayer_endLap
  lbl_805350d8:
  /* 805350D8 9BFA0027 */ stb         r31, 0x27(r26)
  lbl_805350dc:
  /* 805350DC 807C0000 */ lwz         r3, 0(r28)
  /* 805350E0 88030011 */ lbz         r0, 0x11(r3)
  /* 805350E4 7C000775 */ extsb.      r0, r0
  /* 805350E8 4082005C */ bne-        lbl_80535144
  /* 805350EC A0DD0004 */ lhz         r6, 4(r29)
  /* 805350F0 7FA5EB78 */ mr          r5, r29
  /* 805350F4 38800000 */ li          r4, 0x0
  /* 805350F8 7CC903A6 */ mtctr       r6
  /* 805350FC 2C060000 */ cmpwi       r6, 0x0
  /* 80535100 40810038 */ ble-        lbl_80535138
  lbl_80535104:
  /* 80535104 7C043000 */ cmpw        r4, r6
  /* 80535108 4080000C */ bge-        lbl_80535114
  /* 8053510C 80650038 */ lwz         r3, 0x38(r5)
  /* 80535110 48000008 */ b           lbl_80535118
  lbl_80535114:
  /* 80535114 38600000 */ li          r3, 0x0
  lbl_80535118:
  /* 80535118 A003001A */ lhz         r0, 0x1a(r3)
  /* 8053511C 7C1E0040 */ cmplw       r30, r0
  /* 80535120 4082000C */ bne-        lbl_8053512c
  /* 80535124 38000001 */ li          r0, 0x1
  /* 80535128 48000014 */ b           lbl_8053513c
  lbl_8053512c:
  /* 8053512C 38A50018 */ addi        r5, r5, 0x18
  /* 80535130 38840001 */ addi        r4, r4, 0x1
  /* 80535134 4200FFD0 */ bdnz        lbl_80535104
  lbl_80535138:
  /* 80535138 38000000 */ li          r0, 0x0
  lbl_8053513c:
  /* 8053513C 2C000000 */ cmpwi       r0, 0x0
  /* 80535140 40820014 */ bne-        lbl_80535154
  lbl_80535144:
  /* 80535144 3C608089 */ lis         r3, lbl_8089019c@ha
  /* 80535148 C003019C */ lfs         f0, lbl_8089019c@l(r3)
  /* 8053514C FC1E0040 */ opword      0xfc1e0040
  /* 80535150 4080008C */ bge-        lbl_805351dc
  lbl_80535154:
  /* 80535154 801A0038 */ lwz         r0, 0x38(r26)
  /* 80535158 540007BD */ rlwinm.     r0, r0, 0, 0x1e, 0x1e
  /* 8053515C 40820080 */ bne-        lbl_805351dc
  /* 80535160 3C60809C */ lis         r3, spInstance__Q26System9CourseMap@ha
  /* 80535164 8083D6E8 */ lwz         r4, spInstance__Q26System9CourseMap@l(r3)
  /* 80535168 80640020 */ lwz         r3, 0x20(r4)
  /* 8053516C 2C030000 */ cmpwi       r3, 0x0
  /* 80535170 4182000C */ beq-        lbl_8053517c
  /* 80535174 A0630004 */ lhz         r3, 4(r3)
  /* 80535178 48000008 */ b           lbl_80535180
  lbl_8053517c:
  /* 8053517C 38600000 */ li          r3, 0x0
  lbl_80535180:
  /* 80535180 7C0300D0 */ neg         r0, r3
  /* 80535184 7C001B78 */ or          r0, r0, r3
  /* 80535188 54000FFF */ rlwinm.     r0, r0, 1, 0x1f, 0x1f
  /* 8053518C 41820028 */ beq-        lbl_805351b4
  /* 80535190 8064001C */ lwz         r3, 0x1c(r4)
  /* 80535194 2C030000 */ cmpwi       r3, 0x0
  /* 80535198 4182000C */ beq-        lbl_805351a4
  /* 8053519C A0630004 */ lhz         r3, 4(r3)
  /* 805351A0 48000008 */ b           lbl_805351a8
  lbl_805351a4:
  /* 805351A4 38600000 */ li          r3, 0x0
  lbl_805351a8:
  /* 805351A8 7C0300D0 */ neg         r0, r3
  /* 805351AC 7C001B78 */ or          r0, r0, r3
  /* 805351B0 54000FFE */ srwi        r0, r0, 0x1f
  lbl_805351b4:
  /* 805351B4 2C000000 */ cmpwi       r0, 0x0
  /* 805351B8 41820010 */ beq-        lbl_805351c8
  /* 805351BC 80640020 */ lwz         r3, 0x20(r4)
  /* 805351C0 8803000C */ lbz         r0, 0xc(r3)
  /* 805351C4 48000008 */ b           lbl_805351cc
  lbl_805351c8:
  /* 805351C8 3800FFFF */ li          r0, -0x1
  lbl_805351cc:
  /* 805351CC A87A0024 */ lha         r3, 0x24(r26)
  /* 805351D0 981A0028 */ stb         r0, 0x28(r26)
  /* 805351D4 3803FFFF */ addi        r0, r3, -0x1
  /* 805351D8 B01A0024 */ sth         r0, 0x24(r26)
  lbl_805351dc:
  /* 805351DC D3FA001C */ stfs        f31, 0x1c(r26)
  /* 805351E0 7FA3EB78 */ mr          r3, r29
  /* 805351E4 E3E10058 */ opword      0xe3e10058
  /* 805351E8 CBE10050 */ lfd         f31, 0x50(r1)
  /* 805351EC E3C10048 */ opword      0xe3c10048
  /* 805351F0 CBC10040 */ lfd         f30, 0x40(r1)
  /* 805351F4 39610040 */ addi        r11, r1, 0x40
  /* 805351F8 4BAEC3ED */ bl          _restgpr_25
  /* 805351FC 80010064 */ lwz         r0, 0x64(r1)
  /* 80535200 7C0803A6 */ mtlr        r0
  /* 80535204 38210060 */ addi        r1, r1, 0x60
  /* 80535208 4E800020 */ blr // clang-format on
}

// Symbol: unk_8053520c
// PAL: 0x8053520c..0x80535304
MARK_BINARY_BLOB(unk_8053520c, 0x8053520c, 0x80535304);
asm UNKNOWN_FUNCTION(unk_8053520c) {
  // clang-format off
  nofralloc
  /* 8053520C 3C60809C */ lis         r3, spInstance__Q26System9CourseMap@ha
  /* 80535210 80C3D6E8 */ lwz         r6, spInstance__Q26System9CourseMap@l(r3)
  /* 80535214 80660020 */ lwz         r3, 0x20(r6)
  /* 80535218 2C030000 */ cmpwi       r3, 0x0
  /* 8053521C 4182000C */ beq-        lbl_80535228
  /* 80535220 A0630004 */ lhz         r3, 4(r3)
  /* 80535224 48000008 */ b           lbl_8053522c
  lbl_80535228:
  /* 80535228 38600000 */ li          r3, 0x0
  lbl_8053522c:
  /* 8053522C 7C0300D0 */ neg         r0, r3
  /* 80535230 7C001B78 */ or          r0, r0, r3
  /* 80535234 54000FFF */ rlwinm.     r0, r0, 1, 0x1f, 0x1f
  /* 80535238 41820028 */ beq-        lbl_80535260
  /* 8053523C 8066001C */ lwz         r3, 0x1c(r6)
  /* 80535240 2C030000 */ cmpwi       r3, 0x0
  /* 80535244 4182000C */ beq-        lbl_80535250
  /* 80535248 A0630004 */ lhz         r3, 4(r3)
  /* 8053524C 48000008 */ b           lbl_80535254
  lbl_80535250:
  /* 80535250 38600000 */ li          r3, 0x0
  lbl_80535254:
  /* 80535254 7C0300D0 */ neg         r0, r3
  /* 80535258 7C001B78 */ or          r0, r0, r3
  /* 8053525C 54000FFE */ srwi        r0, r0, 0x1f
  lbl_80535260:
  /* 80535260 2C000000 */ cmpwi       r0, 0x0
  /* 80535264 41820010 */ beq-        lbl_80535274
  /* 80535268 80660020 */ lwz         r3, 0x20(r6)
  /* 8053526C 8803000C */ lbz         r0, 0xc(r3)
  /* 80535270 48000008 */ b           lbl_80535278
  lbl_80535274:
  /* 80535274 3800FFFF */ li          r0, -0x1
  lbl_80535278:
  /* 80535278 80650000 */ lwz         r3, 0(r5)
  /* 8053527C 5407063E */ clrlwi      r7, r0, 0x18
  /* 80535280 80C40000 */ lwz         r6, 0(r4)
  /* 80535284 88030011 */ lbz         r0, 0x11(r3)
  /* 80535288 8864001C */ lbz         r3, 0x1c(r4)
  /* 8053528C 88A5001C */ lbz         r5, 0x1c(r5)
  /* 80535290 88C60011 */ lbz         r6, 0x11(r6)
  /* 80535294 7C051840 */ cmplw       r5, r3
  /* 80535298 7CC40774 */ extsb       r4, r6
  /* 8053529C 7C060774 */ extsb       r6, r0
  /* 805352A0 4082000C */ bne-        lbl_805352ac
  /* 805352A4 38600001 */ li          r3, 0x1
  /* 805352A8 4E800020 */ blr
  lbl_805352ac:
  /* 805352AC 2C04FFFF */ cmpwi       r4, -0x1
  /* 805352B0 41820018 */ beq-        lbl_805352c8
  /* 805352B4 3804FFFF */ addi        r0, r4, -0x1
  /* 805352B8 7C050000 */ cmpw        r5, r0
  /* 805352BC 4082000C */ bne-        lbl_805352c8
  /* 805352C0 38600001 */ li          r3, 0x1
  /* 805352C4 4E800020 */ blr
  lbl_805352c8:
  /* 805352C8 2C06FFFF */ cmpwi       r6, -0x1
  /* 805352CC 41820030 */ beq-        lbl_805352fc
  /* 805352D0 38030001 */ addi        r0, r3, 0x1
  /* 805352D4 7C060000 */ cmpw        r6, r0
  /* 805352D8 4082000C */ bne-        lbl_805352e4
  /* 805352DC 38600001 */ li          r3, 0x1
  /* 805352E0 4E800020 */ blr
  lbl_805352e4:
  /* 805352E4 2C060000 */ cmpwi       r6, 0x0
  /* 805352E8 40820014 */ bne-        lbl_805352fc
  /* 805352EC 7C033840 */ cmplw       r3, r7
  /* 805352F0 4082000C */ bne-        lbl_805352fc
  /* 805352F4 38600001 */ li          r3, 0x1
  /* 805352F8 4E800020 */ blr
  lbl_805352fc:
  /* 805352FC 38600000 */ li          r3, 0x0
  /* 80535300 4E800020 */ blr // clang-format on
}

// Symbol: RaceinfoPlayer_update
// PAL: 0x80535304..0x80535698
MARK_BINARY_BLOB(RaceinfoPlayer_update, 0x80535304, 0x80535698);
asm UNKNOWN_FUNCTION(RaceinfoPlayer_update) {
  // clang-format off
  nofralloc
  /* 80535304 9421FFB0 */ stwu        r1, -0x50(r1)
  /* 80535308 7C0802A6 */ mflr        r0
  /* 8053530C 3CA0809C */ lis         r5, spInstance__Q26System10RaceConfig@ha
  /* 80535310 90010054 */ stw         r0, 0x54(r1)
  /* 80535314 93E1004C */ stw         r31, 0x4c(r1)
  /* 80535318 93C10048 */ stw         r30, 0x48(r1)
  /* 8053531C 7C7E1B78 */ mr          r30, r3
  /* 80535320 93A10044 */ stw         r29, 0x44(r1)
  /* 80535324 88830008 */ lbz         r4, 8(r3)
  /* 80535328 80030038 */ lwz         r0, 0x38(r3)
  /* 8053532C 1C8400F0 */ mulli       r4, r4, 0xf0
  /* 80535330 80A5D728 */ lwz         r5, spInstance__Q26System10RaceConfig@l(r5)
  /* 80535334 540007BD */ rlwinm.     r0, r0, 0, 0x1e, 0x1e
  /* 80535338 7C852214 */ add         r4, r5, r4
  /* 8053533C 80840038 */ lwz         r4, 0x38(r4)
  /* 80535340 3804FFFC */ addi        r0, r4, -0x4
  /* 80535344 7C000034 */ cntlzw      r0, r0
  /* 80535348 541FD97E */ srwi        r31, r0, 5
  /* 8053534C 40820028 */ bne-        lbl_80535374
  /* 80535350 88030020 */ lbz         r0, 0x20(r3)
  /* 80535354 2C000001 */ cmpwi       r0, 0x1
  /* 80535358 40820010 */ bne-        lbl_80535368
  /* 8053535C 80830030 */ lwz         r4, 0x30(r3)
  /* 80535360 38040001 */ addi        r0, r4, 0x1
  /* 80535364 90030030 */ stw         r0, 0x30(r3)
  lbl_80535368:
  /* 80535368 8083002C */ lwz         r4, 0x2c(r3)
  /* 8053536C 38040001 */ addi        r0, r4, 0x1
  /* 80535370 9003002C */ stw         r0, 0x2c(r3)
  lbl_80535374:
  /* 80535374 3C80809C */ lis         r4, spInstance__Q26System9CourseMap@ha
  /* 80535378 80A4D6E8 */ lwz         r5, spInstance__Q26System9CourseMap@l(r4)
  /* 8053537C 80850020 */ lwz         r4, 0x20(r5)
  /* 80535380 2C040000 */ cmpwi       r4, 0x0
  /* 80535384 4182000C */ beq-        lbl_80535390
  /* 80535388 A0840004 */ lhz         r4, 4(r4)
  /* 8053538C 48000008 */ b           lbl_80535394
  lbl_80535390:
  /* 80535390 38800000 */ li          r4, 0x0
  lbl_80535394:
  /* 80535394 7C0400D0 */ neg         r0, r4
  /* 80535398 7C002378 */ or          r0, r0, r4
  /* 8053539C 54000FFF */ rlwinm.     r0, r0, 1, 0x1f, 0x1f
  /* 805353A0 41820028 */ beq-        lbl_805353c8
  /* 805353A4 8085001C */ lwz         r4, 0x1c(r5)
  /* 805353A8 2C040000 */ cmpwi       r4, 0x0
  /* 805353AC 4182000C */ beq-        lbl_805353b8
  /* 805353B0 A0840004 */ lhz         r4, 4(r4)
  /* 805353B4 48000008 */ b           lbl_805353bc
  lbl_805353b8:
  /* 805353B8 38800000 */ li          r4, 0x0
  lbl_805353bc:
  /* 805353BC 7C0400D0 */ neg         r0, r4
  /* 805353C0 7C002378 */ or          r0, r0, r4
  /* 805353C4 54000FFE */ srwi        r0, r0, 0x1f
  lbl_805353c8:
  /* 805353C8 2C000000 */ cmpwi       r0, 0x0
  /* 805353CC 418202B0 */ beq-        lbl_8053567c
  /* 805353D0 80030038 */ lwz         r0, 0x38(r3)
  /* 805353D4 540007FF */ clrlwi.     r0, r0, 0x1f
  /* 805353D8 418202A4 */ beq-        lbl_8053567c
  /* 805353DC 3C60809C */ lis         r3, lbl_809c18f8@ha
  /* 805353E0 889E0008 */ lbz         r4, 8(r30)
  /* 805353E4 806318F8 */ lwz         r3, lbl_809c18f8@l(r3)
  /* 805353E8 4805AD19 */ bl          PlayerHolder_getPlayer
  /* 805353EC 80630000 */ lwz         r3, 0(r3)
  /* 805353F0 80630004 */ lwz         r3, 4(r3)
  /* 805353F4 80030004 */ lwz         r0, 4(r3)
  /* 805353F8 540006F7 */ rlwinm.     r0, r0, 0, 0x1b, 0x1b
  /* 805353FC 40820280 */ bne-        lbl_8053567c
  /* 80535400 3C60809C */ lis         r3, spInstance__Q26System10RaceConfig@ha
  /* 80535404 3BA00000 */ li          r29, 0x0
  /* 80535408 8083D728 */ lwz         r4, spInstance__Q26System10RaceConfig@l(r3)
  /* 8053540C 38600000 */ li          r3, 0x0
  /* 80535410 80040B70 */ lwz         r0, 0xb70(r4)
  /* 80535414 2C000007 */ cmpwi       r0, 0x7
  /* 80535418 41800010 */ blt-        lbl_80535428
  /* 8053541C 2C00000A */ cmpwi       r0, 0xa
  /* 80535420 41810008 */ bgt-        lbl_80535428
  /* 80535424 38600001 */ li          r3, 0x1
  lbl_80535428:
  /* 80535428 2C030000 */ cmpwi       r3, 0x0
  /* 8053542C 41820020 */ beq-        lbl_8053544c
  /* 80535430 881E0008 */ lbz         r0, 8(r30)
  /* 80535434 1C0000F0 */ mulli       r0, r0, 0xf0
  /* 80535438 7C640214 */ add         r3, r4, r0
  /* 8053543C 80030038 */ lwz         r0, 0x38(r3)
  /* 80535440 2C000004 */ cmpwi       r0, 0x4
  /* 80535444 40820008 */ bne-        lbl_8053544c
  /* 80535448 3BA00001 */ li          r29, 0x1
  lbl_8053544c:
  /* 8053544C 3C60809C */ lis         r3, lbl_809c18f8@ha
  /* 80535450 889E0008 */ lbz         r4, 8(r30)
  /* 80535454 806318F8 */ lwz         r3, lbl_809c18f8@l(r3)
  /* 80535458 4805ACA9 */ bl          PlayerHolder_getPlayer
  /* 8053545C 4805ADB1 */ bl          getPos__Q24Kart15KartObjectProxyCFv
  /* 80535460 3C80809C */ lis         r4, spInstance__Q26System9CourseMap@ha
  /* 80535464 7C651B78 */ mr          r5, r3
  /* 80535468 8064D6E8 */ lwz         r3, spInstance__Q26System9CourseMap@l(r4)
  /* 8053546C 7FA8EB78 */ mr          r8, r29
  /* 80535470 889E0008 */ lbz         r4, 8(r30)
  /* 80535474 38E10008 */ addi        r7, r1, 0x8
  /* 80535478 A0DE000A */ lhz         r6, 0xa(r30)
  /* 8053547C 4BFDC085 */ bl          KmpHolder_findNextCheckpoint
  /* 80535480 7C640734 */ extsh       r4, r3
  /* 80535484 7C661B78 */ mr          r6, r3
  /* 80535488 2C04FFFF */ cmpwi       r4, -0x1
  /* 8053548C 418201F0 */ beq-        lbl_8053567c
  /* 80535490 3C608089 */ lis         r3, lbl_80890150@ha
  /* 80535494 C03E0014 */ lfs         f1, 0x14(r30)
  /* 80535498 C0030150 */ lfs         f0, lbl_80890150@l(r3)
  /* 8053549C 38600000 */ li          r3, 0x0
  /* 805354A0 FC010040 */ opword      0xfc010040
  /* 805354A4 4080000C */ bge-        lbl_805354b0
  /* 805354A8 38600001 */ li          r3, 0x1
  /* 805354AC 48000014 */ b           lbl_805354c0
  lbl_805354b0:
  /* 805354B0 A01E000A */ lhz         r0, 0xa(r30)
  /* 805354B4 7C002000 */ cmpw        r0, r4
  /* 805354B8 41820008 */ beq-        lbl_805354c0
  /* 805354BC 38600001 */ li          r3, 0x1
  lbl_805354c0:
  /* 805354C0 2C030000 */ cmpwi       r3, 0x0
  /* 805354C4 41820020 */ beq-        lbl_805354e4
  /* 805354C8 C0210008 */ lfs         f1, 8(r1)
  /* 805354CC 7FC3F378 */ mr          r3, r30
  /* 805354D0 7FE5FB78 */ mr          r5, r31
  /* 805354D4 7CC40734 */ extsh       r4, r6
  /* 805354D8 4BFFF921 */ bl          RaceinfoPlayer_updateCheckpoint
  /* 805354DC 7C7F1B78 */ mr          r31, r3
  /* 805354E0 48000018 */ b           lbl_805354f8
  lbl_805354e4:
  /* 805354E4 3C60809C */ lis         r3, spInstance__Q26System9CourseMap@ha
  /* 805354E8 A09E000A */ lhz         r4, 0xa(r30)
  /* 805354EC 8063D6E8 */ lwz         r3, spInstance__Q26System9CourseMap@l(r3)
  /* 805354F0 4BFE0735 */ bl          getCheckPoint__Q26System9CourseMapCFUs
  /* 805354F4 7C7F1B78 */ mr          r31, r3
  lbl_805354f8:
  /* 805354F8 C03E0014 */ lfs         f1, 0x14(r30)
  /* 805354FC 3C004330 */ lis         r0, 0x4330
  /* 80535500 C0010008 */ lfs         f0, 8(r1)
  /* 80535504 3CA08089 */ lis         r5, lbl_808901a0@ha
  /* 80535508 A87E0024 */ lha         r3, 0x24(r30)
  /* 8053550C EC210032 */ fmuls       f1, f1, f0
  /* 80535510 C01E0018 */ lfs         f0, 0x18(r30)
  /* 80535514 6C648000 */ xoris       r4, r3, 0x8000
  /* 80535518 9081002C */ stw         r4, 0x2c(r1)
  /* 8053551C C88501A0 */ lfd         f4, lbl_808901a0@l(r5)
  /* 80535520 3C608089 */ lis         r3, lbl_808901a8@ha
  /* 80535524 90010028 */ stw         r0, 0x28(r1)
  /* 80535528 EC40082A */ fadds       f2, f0, f1
  /* 8053552C C02301A8 */ lfs         f1, lbl_808901a8@l(r3)
  /* 80535530 C8610028 */ lfd         f3, 0x28(r1)
  /* 80535534 90810034 */ stw         r4, 0x34(r1)
  /* 80535538 EC632028 */ fsubs       f3, f3, f4
  /* 8053553C 90010030 */ stw         r0, 0x30(r1)
  /* 80535540 C8010030 */ lfd         f0, 0x30(r1)
  /* 80535544 EC43102A */ fadds       f2, f3, f2
  /* 80535548 EC002028 */ fsubs       f0, f0, f4
  /* 8053554C D05E000C */ stfs        f2, 0xc(r30)
  /* 80535550 EC01002A */ fadds       f0, f1, f0
  /* 80535554 FC020040 */ opword      0xfc020040
  /* 80535558 4081001C */ ble-        lbl_80535574
  /* 8053555C 90810034 */ stw         r4, 0x34(r1)
  /* 80535560 90010030 */ stw         r0, 0x30(r1)
  /* 80535564 C8010030 */ lfd         f0, 0x30(r1)
  /* 80535568 EC002028 */ fsubs       f0, f0, f4
  /* 8053556C EC01002A */ fadds       f0, f1, f0
  /* 80535570 D01E000C */ stfs        f0, 0xc(r30)
  lbl_80535574:
  /* 80535574 C03E000C */ lfs         f1, 0xc(r30)
  /* 80535578 C01E0010 */ lfs         f0, 0x10(r30)
  /* 8053557C FC010040 */ opword      0xfc010040
  /* 80535580 40810008 */ ble-        lbl_80535588
  /* 80535584 D03E0010 */ stfs        f1, 0x10(r30)
  lbl_80535588:
  /* 80535588 3C60809C */ lis         r3, spInstance__Q26System10RaceConfig@ha
  /* 8053558C 38800000 */ li          r4, 0x0
  /* 80535590 8063D728 */ lwz         r3, spInstance__Q26System10RaceConfig@l(r3)
  /* 80535594 80630B70 */ lwz         r3, 0xb70(r3)
  /* 80535598 3803FFFD */ addi        r0, r3, -0x3
  /* 8053559C 28000007 */ cmplwi      r0, 7
  /* 805355A0 41810018 */ bgt-        lbl_805355b8
  /* 805355A4 38600001 */ li          r3, 0x1
  /* 805355A8 7C600030 */ slw         r0, r3, r0
  /* 805355AC 700000C1 */ andi.       r0, r0, 0xc1
  /* 805355B0 41820008 */ beq-        lbl_805355b8
  /* 805355B4 7C641B78 */ mr          r4, r3
  lbl_805355b8:
  /* 805355B8 2C040000 */ cmpwi       r4, 0x0
  /* 805355BC 408200C0 */ bne-        lbl_8053567c
  /* 805355C0 3C60809C */ lis         r3, lbl_809c18f8@ha
  /* 805355C4 889E0008 */ lbz         r4, 8(r30)
  /* 805355C8 806318F8 */ lwz         r3, lbl_809c18f8@l(r3)
  /* 805355CC 4805AB35 */ bl          PlayerHolder_getPlayer
  /* 805355D0 38810018 */ addi        r4, r1, 0x18
  /* 805355D4 4805B6C1 */ bl          PlayerPointers_getBodyFront
  /* 805355D8 3C608089 */ lis         r3, lbl_80890150@ha
  /* 805355DC C0010018 */ lfs         f0, 0x18(r1)
  /* 805355E0 C0230150 */ lfs         f1, lbl_80890150@l(r3)
  /* 805355E4 FC010000 */ opword      0xfc010000
  /* 805355E8 40820010 */ bne-        lbl_805355f8
  /* 805355EC C0010020 */ lfs         f0, 0x20(r1)
  /* 805355F0 FC010000 */ opword      0xfc010000
  /* 805355F4 41820088 */ beq-        lbl_8053567c
  lbl_805355f8:
  /* 805355F8 C0210020 */ lfs         f1, 0x20(r1)
  /* 805355FC 38610010 */ addi        r3, r1, 0x10
  /* 80535600 C0010018 */ lfs         f0, 0x18(r1)
  /* 80535604 D0010010 */ stfs        f0, 0x10(r1)
  /* 80535608 D0210014 */ stfs        f1, 0x14(r1)
  /* 8053560C 4BD0E3F5 */ bl          normalise__Q23EGG8Vector2fFv
  /* 80535610 3C60809C */ lis         r3, spInstance__Q26System9CourseMap@ha
  /* 80535614 8063D6E8 */ lwz         r3, spInstance__Q26System9CourseMap@l(r3)
  /* 80535618 4BFE3561 */ bl          getStage__Q26System9CourseMapCFv
  /* 8053561C 80630000 */ lwz         r3, 0(r3)
  /* 80535620 88030000 */ lbz         r0, 0(r3)
  /* 80535624 2C000000 */ cmpwi       r0, 0x0
  /* 80535628 41820054 */ beq-        lbl_8053567c
  /* 8053562C C0210014 */ lfs         f1, 0x14(r1)
  /* 80535630 3C608089 */ lis         r3, lbl_808901ac@ha
  /* 80535634 C01F0014 */ lfs         f0, 0x14(r31)
  /* 80535638 C0610010 */ lfs         f3, 0x10(r1)
  /* 8053563C C05F0010 */ lfs         f2, 0x10(r31)
  /* 80535640 EC200072 */ fmuls       f1, f0, f1
  /* 80535644 C00301AC */ lfs         f0, lbl_808901ac@l(r3)
  /* 80535648 EC4200F2 */ fmuls       f2, f2, f3
  /* 8053564C EC22082A */ fadds       f1, f2, f1
  /* 80535650 FC010040 */ opword      0xfc010040
  /* 80535654 7C000026 */ mfcr        r0
  /* 80535658 540017FF */ rlwinm.     r0, r0, 2, 0x1f, 0x1f
  /* 8053565C 41820014 */ beq-        lbl_80535670
  /* 80535660 801E0038 */ lwz         r0, 0x38(r30)
  /* 80535664 540007B8 */ rlwinm      r0, r0, 0, 0x1e, 0x1c
  /* 80535668 901E0038 */ stw         r0, 0x38(r30)
  /* 8053566C 48000010 */ b           lbl_8053567c
  lbl_80535670:
  /* 80535670 801E0038 */ lwz         r0, 0x38(r30)
  /* 80535674 60000004 */ ori         r0, r0, 4
  /* 80535678 901E0038 */ stw         r0, 0x38(r30)
  lbl_8053567c:
  /* 8053567C 80010054 */ lwz         r0, 0x54(r1)
  /* 80535680 83E1004C */ lwz         r31, 0x4c(r1)
  /* 80535684 83C10048 */ lwz         r30, 0x48(r1)
  /* 80535688 83A10044 */ lwz         r29, 0x44(r1)
  /* 8053568C 7C0803A6 */ mtlr        r0
  /* 80535690 38210050 */ addi        r1, r1, 0x50
  /* 80535694 4E800020 */ blr // clang-format on
}

// Symbol: unk_80535698
// PAL: 0x80535698..0x8053569c
MARK_BINARY_BLOB(unk_80535698, 0x80535698, 0x8053569c);
asm UNKNOWN_FUNCTION(unk_80535698){
    // clang-format off
  nofralloc
  /* 80535698 4E800020 */ blr // clang-format on
}

// Symbol: unk_8053569c
// PAL: 0x8053569c..0x80535718
MARK_BINARY_BLOB(unk_8053569c, 0x8053569c, 0x80535718);
asm UNKNOWN_FUNCTION(unk_8053569c) {
  // clang-format off
  nofralloc
  /* 8053569C 3C80809C */ lis         r4, spInstance__Q26System9CourseMap@ha
  /* 805356A0 80A4D6E8 */ lwz         r5, spInstance__Q26System9CourseMap@l(r4)
  /* 805356A4 80850020 */ lwz         r4, 0x20(r5)
  /* 805356A8 2C040000 */ cmpwi       r4, 0x0
  /* 805356AC 4182000C */ beq-        lbl_805356b8
  /* 805356B0 A0840004 */ lhz         r4, 4(r4)
  /* 805356B4 48000008 */ b           lbl_805356bc
  lbl_805356b8:
  /* 805356B8 38800000 */ li          r4, 0x0
  lbl_805356bc:
  /* 805356BC 7C0400D0 */ neg         r0, r4
  /* 805356C0 7C002378 */ or          r0, r0, r4
  /* 805356C4 54000FFF */ rlwinm.     r0, r0, 1, 0x1f, 0x1f
  /* 805356C8 41820028 */ beq-        lbl_805356f0
  /* 805356CC 8085001C */ lwz         r4, 0x1c(r5)
  /* 805356D0 2C040000 */ cmpwi       r4, 0x0
  /* 805356D4 4182000C */ beq-        lbl_805356e0
  /* 805356D8 A0840004 */ lhz         r4, 4(r4)
  /* 805356DC 48000008 */ b           lbl_805356e4
  lbl_805356e0:
  /* 805356E0 38800000 */ li          r4, 0x0
  lbl_805356e4:
  /* 805356E4 7C0400D0 */ neg         r0, r4
  /* 805356E8 7C002378 */ or          r0, r0, r4
  /* 805356EC 54000FFE */ srwi        r0, r0, 0x1f
  lbl_805356f0:
  /* 805356F0 2C000000 */ cmpwi       r0, 0x0
  /* 805356F4 4D820020 */ beqlr-
  /* 805356F8 80030038 */ lwz         r0, 0x38(r3)
  /* 805356FC 540007FF */ clrlwi.     r0, r0, 0x1f
  /* 80535700 4D820020 */ beqlr-
  /* 80535704 3CA0809C */ lis         r5, lbl_809c18f8@ha
  /* 80535708 88830008 */ lbz         r4, 8(r3)
  /* 8053570C 806518F8 */ lwz         r3, lbl_809c18f8@l(r5)
  /* 80535710 4805A9F0 */ b           PlayerHolder_getPlayer
  /* 80535714 4E800020 */ blr // clang-format on
}

// Symbol: unk_80535718
// PAL: 0x80535718..0x8053572c
MARK_BINARY_BLOB(unk_80535718, 0x80535718, 0x8053572c);
asm UNKNOWN_FUNCTION(unk_80535718){
    // clang-format off
  nofralloc
  /* 80535718 80630048 */ lwz         r3, 0x48(r3)
  /* 8053571C 81830000 */ lwz         r12, 0(r3)
  /* 80535720 818C0014 */ lwz         r12, 0x14(r12)
  /* 80535724 7D8903A6 */ mtctr       r12
  /* 80535728 4E800420 */ bctr // clang-format on
}

// Symbol: RaceinfoPlayer_getLapSplit
// PAL: 0x8053572c..0x80535864
MARK_BINARY_BLOB(RaceinfoPlayer_getLapSplit, 0x8053572c, 0x80535864);
asm UNKNOWN_FUNCTION(RaceinfoPlayer_getLapSplit) {
  // clang-format off
  nofralloc
  /* 8053572C 28040002 */ cmplwi      r4, 2
  /* 80535730 4080002C */ bge-        lbl_8053575c
  /* 80535734 8063003C */ lwz         r3, 0x3c(r3)
  /* 80535738 A0030004 */ lhz         r0, 4(r3)
  /* 8053573C B0050004 */ sth         r0, 4(r5)
  /* 80535740 88030006 */ lbz         r0, 6(r3)
  /* 80535744 98050006 */ stb         r0, 6(r5)
  /* 80535748 A0030008 */ lhz         r0, 8(r3)
  /* 8053574C B0050008 */ sth         r0, 8(r5)
  /* 80535750 8803000A */ lbz         r0, 0xa(r3)
  /* 80535754 9805000A */ stb         r0, 0xa(r5)
  /* 80535758 4E800020 */ blr
  lbl_8053575c:
  /* 8053575C 3CC0809C */ lis         r6, spInstance__Q26System11RaceManager@ha
  /* 80535760 80C6D730 */ lwz         r6, spInstance__Q26System11RaceManager@l(r6)
  /* 80535764 80C60014 */ lwz         r6, 0x14(r6)
  /* 80535768 88060040 */ lbz         r0, 0x40(r6)
  /* 8053576C 2C000000 */ cmpwi       r0, 0x0
  /* 80535770 41820028 */ beq-        lbl_80535798
  /* 80535774 38C00001 */ li          r6, 0x1
  /* 80535778 38800063 */ li          r4, 0x63
  /* 8053577C 3860003B */ li          r3, 0x3b
  /* 80535780 380003E7 */ li          r0, 0x3e7
  /* 80535784 98C5000A */ stb         r6, 0xa(r5)
  /* 80535788 B0850004 */ sth         r4, 4(r5)
  /* 8053578C 98650006 */ stb         r3, 6(r5)
  /* 80535790 B0050008 */ sth         r0, 8(r5)
  /* 80535794 4E800020 */ blr
  lbl_80535798:
  /* 80535798 38C4FFFE */ addi        r6, r4, -0x2
  /* 8053579C 3804FFFF */ addi        r0, r4, -0x1
  /* 805357A0 1D86000C */ mulli       r12, r6, 0xc
  /* 805357A4 80C3003C */ lwz         r6, 0x3c(r3)
  /* 805357A8 39400000 */ li          r10, 0x0
  /* 805357AC 39200000 */ li          r9, 0x0
  /* 805357B0 7CE66214 */ add         r7, r6, r12
  /* 805357B4 1D60000C */ mulli       r11, r0, 0xc
  /* 805357B8 A0870008 */ lhz         r4, 8(r7)
  /* 805357BC 7CC65A14 */ add         r6, r6, r11
  /* 805357C0 A0060008 */ lhz         r0, 8(r6)
  /* 805357C4 7D040051 */ subf.       r8, r4, r0
  /* 805357C8 4080000C */ bge-        lbl_805357d4
  /* 805357CC 3920FFFF */ li          r9, -0x1
  /* 805357D0 390803E8 */ addi        r8, r8, 0x3e8
  lbl_805357d4:
  /* 805357D4 88870006 */ lbz         r4, 6(r7)
  /* 805357D8 88060006 */ lbz         r0, 6(r6)
  /* 805357DC 7C040050 */ subf        r0, r4, r0
  /* 805357E0 7D290215 */ add.        r9, r9, r0
  /* 805357E4 4080000C */ bge-        lbl_805357f0
  /* 805357E8 3940FFFF */ li          r10, -0x1
  /* 805357EC 3929003C */ addi        r9, r9, 0x3c
  lbl_805357f0:
  /* 805357F0 A0870004 */ lhz         r4, 4(r7)
  /* 805357F4 A0060004 */ lhz         r0, 4(r6)
  /* 805357F8 7C040050 */ subf        r0, r4, r0
  /* 805357FC 7D4A0215 */ add.        r10, r10, r0
  /* 80535800 40800010 */ bge-        lbl_80535810
  /* 80535804 39400000 */ li          r10, 0x0
  /* 80535808 39200000 */ li          r9, 0x0
  /* 8053580C 39000000 */ li          r8, 0x0
  lbl_80535810:
  /* 80535810 38000001 */ li          r0, 0x1
  /* 80535814 9805000A */ stb         r0, 0xa(r5)
  /* 80535818 B1450004 */ sth         r10, 4(r5)
  /* 8053581C 99250006 */ stb         r9, 6(r5)
  /* 80535820 B1050008 */ sth         r8, 8(r5)
  /* 80535824 8083003C */ lwz         r4, 0x3c(r3)
  /* 80535828 7C645A14 */ add         r3, r4, r11
  /* 8053582C 8803000A */ lbz         r0, 0xa(r3)
  /* 80535830 2C000000 */ cmpwi       r0, 0x0
  /* 80535834 41820014 */ beq-        lbl_80535848
  /* 80535838 7C646214 */ add         r3, r4, r12
  /* 8053583C 8803000A */ lbz         r0, 0xa(r3)
  /* 80535840 2C000000 */ cmpwi       r0, 0x0
  /* 80535844 4C820020 */ bnelr-
  lbl_80535848:
  /* 80535848 3C600001 */ lis         r3, 1
  /* 8053584C 38000000 */ li          r0, 0x0
  /* 80535850 3863FFFF */ addi        r3, r3, -0x1
  /* 80535854 B0650004 */ sth         r3, 4(r5)
  /* 80535858 98050006 */ stb         r0, 6(r5)
  /* 8053585C B0050008 */ sth         r0, 8(r5)
  /* 80535860 4E800020 */ blr // clang-format on
}

// Symbol: unk_80535864
// PAL: 0x80535864..0x80535904
MARK_BINARY_BLOB(unk_80535864, 0x80535864, 0x80535904);
asm UNKNOWN_FUNCTION(unk_80535864){
    // clang-format off
  nofralloc
  /* 80535864 9421FFE0 */ stwu        r1, -0x20(r1)
  /* 80535868 7C0802A6 */ mflr        r0
  /* 8053586C 90010024 */ stw         r0, 0x24(r1)
  /* 80535870 93E1001C */ stw         r31, 0x1c(r1)
  /* 80535874 3BE00000 */ li          r31, 0x0
  /* 80535878 93C10018 */ stw         r30, 0x18(r1)
  /* 8053587C 3BC00001 */ li          r30, 0x1
  /* 80535880 93A10014 */ stw         r29, 0x14(r1)
  /* 80535884 7C7D1B78 */ mr          r29, r3
  /* 80535888 9BC3001A */ stb         r30, 0x1a(r3)
  /* 8053588C B3E30014 */ sth         r31, 0x14(r3)
  /* 80535890 9BE30016 */ stb         r31, 0x16(r3)
  /* 80535894 B3E30018 */ sth         r31, 0x18(r3)
  /* 80535898 9BC3000E */ stb         r30, 0xe(r3)
  /* 8053589C B3E30008 */ sth         r31, 8(r3)
  /* 805358A0 9BE3000A */ stb         r31, 0xa(r3)
  /* 805358A4 B3E3000C */ sth         r31, 0xc(r3)
  /* 805358A8 9BE30041 */ stb         r31, 0x41(r3)
  /* 805358AC 9BE30040 */ stb         r31, 0x40(r3)
  /* 805358B0 4BC754C5 */ bl          OSGetTick
  /* 805358B4 3C8001CA */ lis         r4, 0x1ca
  /* 805358B8 907D0034 */ stw         r3, 0x34(r29)
  /* 805358BC 3804C37B */ addi        r0, r4, -0x3c85
  /* 805358C0 93FD0030 */ stw         r31, 0x30(r29)
  /* 805358C4 907D003C */ stw         r3, 0x3c(r29)
  /* 805358C8 93FD0038 */ stw         r31, 0x38(r29)
  /* 805358CC 9BDD0026 */ stb         r30, 0x26(r29)
  /* 805358D0 B3FD0020 */ sth         r31, 0x20(r29)
  /* 805358D4 9BFD0022 */ stb         r31, 0x22(r29)
  /* 805358D8 B3FD0024 */ sth         r31, 0x24(r29)
  /* 805358DC 9BFD0042 */ stb         r31, 0x42(r29)
  /* 805358E0 901D0044 */ stw         r0, 0x44(r29)
  /* 805358E4 93FD0048 */ stw         r31, 0x48(r29)
  /* 805358E8 83E1001C */ lwz         r31, 0x1c(r1)
  /* 805358EC 83C10018 */ lwz         r30, 0x18(r1)
  /* 805358F0 83A10014 */ lwz         r29, 0x14(r1)
  /* 805358F4 80010024 */ lwz         r0, 0x24(r1)
  /* 805358F8 7C0803A6 */ mtlr        r0
  /* 805358FC 38210020 */ addi        r1, r1, 0x20
  /* 80535900 4E800020 */ blr // clang-format on
}

// Symbol: unk_80535904
// PAL: 0x80535904..0x80535ca0
MARK_BINARY_BLOB(unk_80535904, 0x80535904, 0x80535ca0);
asm UNKNOWN_FUNCTION(unk_80535904) {
  // clang-format off
  nofralloc
  /* 80535904 9421FFC0 */ stwu        r1, -0x40(r1)
  /* 80535908 7C0802A6 */ mflr        r0
  /* 8053590C 3C804330 */ lis         r4, 0x4330
  /* 80535910 90010044 */ stw         r0, 0x44(r1)
  /* 80535914 93E1003C */ stw         r31, 0x3c(r1)
  /* 80535918 93C10038 */ stw         r30, 0x38(r1)
  /* 8053591C 93A10034 */ stw         r29, 0x34(r1)
  /* 80535920 7C7D1B78 */ mr          r29, r3
  /* 80535924 93810030 */ stw         r28, 0x30(r1)
  /* 80535928 88030041 */ lbz         r0, 0x41(r3)
  /* 8053592C 90810008 */ stw         r4, 8(r1)
  /* 80535930 2C000000 */ cmpwi       r0, 0x0
  /* 80535934 90810010 */ stw         r4, 0x10(r1)
  /* 80535938 41820348 */ beq-        lbl_80535c80
  /* 8053593C 88030040 */ lbz         r0, 0x40(r3)
  /* 80535940 2C000000 */ cmpwi       r0, 0x0
  /* 80535944 4182000C */ beq-        lbl_80535950
  /* 80535948 3BC00000 */ li          r30, 0x0
  /* 8053594C 48000030 */ b           lbl_8053597c
  lbl_80535950:
  /* 80535950 3C808038 */ lis         r4, sInstance__Q26System13SystemManager@ha
  /* 80535954 3C608089 */ lis         r3, lbl_808901b0@ha
  /* 80535958 80846000 */ lwz         r4, sInstance__Q26System13SystemManager@l(r4)
  /* 8053595C C00301B0 */ lfs         f0, lbl_808901b0@l(r3)
  /* 80535960 C024007C */ lfs         f1, 0x7c(r4)
  /* 80535964 EC210028 */ fsubs       f1, f1, f0
  /* 80535968 4BAEBB11 */ bl          __cvt_fp2unsigned
  /* 8053596C 7C641B78 */ mr          r4, r3
  /* 80535970 387D0028 */ addi        r3, r29, 0x28
  /* 80535974 4801FC59 */ bl          nextU32__Q24Util6RandomFUl
  /* 80535978 7C7E1B78 */ mr          r30, r3
  lbl_8053597c:
  /* 8053597C 801D0048 */ lwz         r0, 0x48(r29)
  /* 80535980 3C608089 */ lis         r3, lbl_80890170@ha
  /* 80535984 9001000C */ stw         r0, 0xc(r1)
  /* 80535988 3C808038 */ lis         r4, sInstance__Q26System13SystemManager@ha
  /* 8053598C 80846000 */ lwz         r4, sInstance__Q26System13SystemManager@l(r4)
  /* 80535990 C8230170 */ lfd         f1, lbl_80890170@l(r3)
  /* 80535994 C8010008 */ lfd         f0, 8(r1)
  /* 80535998 C044007C */ lfs         f2, 0x7c(r4)
  /* 8053599C EC000828 */ fsubs       f0, f0, f1
  /* 805359A0 EC2000B2 */ fmuls       f1, f0, f2
  /* 805359A4 4BAEBAD5 */ bl          __cvt_fp2unsigned
  /* 805359A8 801D0044 */ lwz         r0, 0x44(r29)
  /* 805359AC 7C030040 */ cmplw       r3, r0
  /* 805359B0 4081000C */ ble-        lbl_805359bc
  /* 805359B4 38000001 */ li          r0, 0x1
  /* 805359B8 981D0040 */ stb         r0, 0x40(r29)
  lbl_805359bc:
  /* 805359BC 881D0040 */ lbz         r0, 0x40(r29)
  /* 805359C0 2C000000 */ cmpwi       r0, 0x0
  /* 805359C4 41820014 */ beq-        lbl_805359d8
  /* 805359C8 3BE00063 */ li          r31, 0x63
  /* 805359CC 3B80003B */ li          r28, 0x3b
  /* 805359D0 38A003E7 */ li          r5, 0x3e7
  /* 805359D4 480000BC */ b           lbl_80535a90
  lbl_805359d8:
  /* 805359D8 90610014 */ stw         r3, 0x14(r1)
  /* 805359DC 3F808089 */ lis         r28, lbl_80890170@ha
  /* 805359E0 3CA08089 */ lis         r5, lbl_80890188@ha
  /* 805359E4 C89C0170 */ lfd         f4, lbl_80890170@l(r28)
  /* 805359E8 C8010010 */ lfd         f0, 0x10(r1)
  /* 805359EC 3C808089 */ lis         r4, lbl_808901b4@ha
  /* 805359F0 9061000C */ stw         r3, 0xc(r1)
  /* 805359F4 EC602028 */ fsubs       f3, f0, f4
  /* 805359F8 C0450188 */ lfs         f2, lbl_80890188@l(r5)
  /* 805359FC C8210008 */ lfd         f1, 8(r1)
  /* 80535A00 C00401B4 */ lfs         f0, lbl_808901b4@l(r4)
  /* 80535A04 EC6200F2 */ fmuls       f3, f2, f3
  /* 80535A08 EC412028 */ fsubs       f2, f1, f4
  /* 80535A0C FC20181E */ fctiwz      f1, f3
  /* 80535A10 D8210018 */ stfd        f1, 0x18(r1)
  /* 80535A14 83E1001C */ lwz         r31, 0x1c(r1)
  /* 80535A18 57E0043E */ clrlwi      r0, r31, 0x10
  /* 80535A1C 90010014 */ stw         r0, 0x14(r1)
  /* 80535A20 C8210010 */ lfd         f1, 0x10(r1)
  /* 80535A24 EC212028 */ fsubs       f1, f1, f4
  /* 80535A28 EC000072 */ fmuls       f0, f0, f1
  /* 80535A2C EC220028 */ fsubs       f1, f2, f0
  /* 80535A30 4BAEBA49 */ bl          __cvt_fp2unsigned
  /* 80535A34 9061000C */ stw         r3, 0xc(r1)
  /* 80535A38 3CA08089 */ lis         r5, lbl_8089018c@ha
  /* 80535A3C C89C0170 */ lfd         f4, lbl_80890170@l(r28)
  /* 80535A40 3C808089 */ lis         r4, lbl_808901b8@ha
  /* 80535A44 C8010008 */ lfd         f0, 8(r1)
  /* 80535A48 90610014 */ stw         r3, 0x14(r1)
  /* 80535A4C EC602028 */ fsubs       f3, f0, f4
  /* 80535A50 C045018C */ lfs         f2, lbl_8089018c@l(r5)
  /* 80535A54 C8210010 */ lfd         f1, 0x10(r1)
  /* 80535A58 C00401B8 */ lfs         f0, lbl_808901b8@l(r4)
  /* 80535A5C EC6200F2 */ fmuls       f3, f2, f3
  /* 80535A60 EC412028 */ fsubs       f2, f1, f4
  /* 80535A64 FC20181E */ fctiwz      f1, f3
  /* 80535A68 D8210020 */ stfd        f1, 0x20(r1)
  /* 80535A6C 83810024 */ lwz         r28, 0x24(r1)
  /* 80535A70 5780063E */ clrlwi      r0, r28, 0x18
  /* 80535A74 9001000C */ stw         r0, 0xc(r1)
  /* 80535A78 C8210008 */ lfd         f1, 8(r1)
  /* 80535A7C EC212028 */ fsubs       f1, f1, f4
  /* 80535A80 EC000072 */ fmuls       f0, f0, f1
  /* 80535A84 EC220028 */ fsubs       f1, f2, f0
  /* 80535A88 4BAEB9F1 */ bl          __cvt_fp2unsigned
  /* 80535A8C 5465043E */ clrlwi      r5, r3, 0x10
  lbl_80535a90:
  /* 80535A90 881D0042 */ lbz         r0, 0x42(r29)
  /* 80535A94 38800001 */ li          r4, 0x1
  /* 80535A98 989D000E */ stb         r4, 0xe(r29)
  /* 80535A9C 2C000000 */ cmpwi       r0, 0x0
  /* 80535AA0 B3FD0008 */ sth         r31, 8(r29)
  /* 80535AA4 9B9D000A */ stb         r28, 0xa(r29)
  /* 80535AA8 B0BD000C */ sth         r5, 0xc(r29)
  /* 80535AAC 4182010C */ beq-        lbl_80535bb8
  /* 80535AB0 93C10014 */ stw         r30, 0x14(r1)
  /* 80535AB4 3C608089 */ lis         r3, lbl_80890170@ha
  /* 80535AB8 C8430170 */ lfd         f2, lbl_80890170@l(r3)
  /* 80535ABC 38E00000 */ li          r7, 0x0
  /* 80535AC0 90A1000C */ stw         r5, 0xc(r1)
  /* 80535AC4 C8210010 */ lfd         f1, 0x10(r1)
  /* 80535AC8 C8010008 */ lfd         f0, 8(r1)
  /* 80535ACC EC211028 */ fsubs       f1, f1, f2
  /* 80535AD0 EC001028 */ fsubs       f0, f0, f2
  /* 80535AD4 EC01002A */ fadds       f0, f1, f0
  /* 80535AD8 FC00001E */ fctiwz      f0, f0
  /* 80535ADC D8010020 */ stfd        f0, 0x20(r1)
  /* 80535AE0 80810024 */ lwz         r4, 0x24(r1)
  /* 80535AE4 5480043E */ clrlwi      r0, r4, 0x10
  /* 80535AE8 280003E7 */ cmplwi      r0, 0x3e7
  /* 80535AEC 40810050 */ ble-        lbl_80535b3c
  /* 80535AF0 5783063E */ clrlwi      r3, r28, 0x18
  /* 80535AF4 3884FC18 */ addi        r4, r4, -0x3e8
  /* 80535AF8 39030001 */ addi        r8, r3, 0x1
  /* 80535AFC 5500063E */ clrlwi      r0, r8, 0x18
  /* 80535B00 5484043E */ clrlwi      r4, r4, 0x10
  /* 80535B04 2800003B */ cmplwi      r0, 0x3b
  /* 80535B08 40810010 */ ble-        lbl_80535b18
  /* 80535B0C 3808FFC4 */ addi        r0, r8, -0x3c
  /* 80535B10 38E00001 */ li          r7, 0x1
  /* 80535B14 5408063E */ clrlwi      r8, r0, 0x18
  lbl_80535b18:
  /* 80535B18 A01D0008 */ lhz         r0, 8(r29)
  /* 80535B1C 7CE70214 */ add         r7, r7, r0
  /* 80535B20 54E0043E */ clrlwi      r0, r7, 0x10
  /* 80535B24 280003E7 */ cmplwi      r0, 0x3e7
  /* 80535B28 4081001C */ ble-        lbl_80535b44
  /* 80535B2C 38E003E7 */ li          r7, 0x3e7
  /* 80535B30 3900003B */ li          r8, 0x3b
  /* 80535B34 388003E7 */ li          r4, 0x3e7
  /* 80535B38 4800000C */ b           lbl_80535b44
  lbl_80535b3c:
  /* 80535B3C 57E7043E */ clrlwi      r7, r31, 0x10
  /* 80535B40 5788063E */ clrlwi      r8, r28, 0x18
  lbl_80535b44:
  /* 80535B44 A01D0024 */ lhz         r0, 0x24(r29)
  /* 80535B48 5483043E */ clrlwi      r3, r4, 0x10
  /* 80535B4C 38C00000 */ li          r6, 0x0
  /* 80535B50 38A00000 */ li          r5, 0x0
  /* 80535B54 7C830051 */ subf.       r4, r3, r0
  /* 80535B58 4080000C */ bge-        lbl_80535b64
  /* 80535B5C 38A0FFFF */ li          r5, -0x1
  /* 80535B60 388403E8 */ addi        r4, r4, 0x3e8
  lbl_80535b64:
  /* 80535B64 881D0022 */ lbz         r0, 0x22(r29)
  /* 80535B68 5503063E */ clrlwi      r3, r8, 0x18
  /* 80535B6C 7C030050 */ subf        r0, r3, r0
  /* 80535B70 7CA50215 */ add.        r5, r5, r0
  /* 80535B74 4080000C */ bge-        lbl_80535b80
  /* 80535B78 38C0FFFF */ li          r6, -0x1
  /* 80535B7C 38A5003C */ addi        r5, r5, 0x3c
  lbl_80535b80:
  /* 80535B80 A01D0020 */ lhz         r0, 0x20(r29)
  /* 80535B84 54E3043E */ clrlwi      r3, r7, 0x10
  /* 80535B88 7C030050 */ subf        r0, r3, r0
  /* 80535B8C 7CC60215 */ add.        r6, r6, r0
  /* 80535B90 40800010 */ bge-        lbl_80535ba0
  /* 80535B94 38C00000 */ li          r6, 0x0
  /* 80535B98 38A00000 */ li          r5, 0x0
  /* 80535B9C 38800000 */ li          r4, 0x0
  lbl_80535ba0:
  /* 80535BA0 38000001 */ li          r0, 0x1
  /* 80535BA4 981D001A */ stb         r0, 0x1a(r29)
  /* 80535BA8 B0DD0014 */ sth         r6, 0x14(r29)
  /* 80535BAC 98BD0016 */ stb         r5, 0x16(r29)
  /* 80535BB0 B09D0018 */ sth         r4, 0x18(r29)
  /* 80535BB4 480000B4 */ b           lbl_80535c68
  lbl_80535bb8:
  /* 80535BB8 93C10014 */ stw         r30, 0x14(r1)
  /* 80535BBC 3C608089 */ lis         r3, lbl_80890170@ha
  /* 80535BC0 C8430170 */ lfd         f2, lbl_80890170@l(r3)
  /* 80535BC4 38C00000 */ li          r6, 0x0
  /* 80535BC8 90A1000C */ stw         r5, 0xc(r1)
  /* 80535BCC C8210010 */ lfd         f1, 0x10(r1)
  /* 80535BD0 C8010008 */ lfd         f0, 8(r1)
  /* 80535BD4 EC211028 */ fsubs       f1, f1, f2
  /* 80535BD8 EC001028 */ fsubs       f0, f0, f2
  /* 80535BDC EC01002A */ fadds       f0, f1, f0
  /* 80535BE0 FC00001E */ fctiwz      f0, f0
  /* 80535BE4 D8010020 */ stfd        f0, 0x20(r1)
  /* 80535BE8 80A10024 */ lwz         r5, 0x24(r1)
  /* 80535BEC 54A0043E */ clrlwi      r0, r5, 0x10
  /* 80535BF0 280003E7 */ cmplwi      r0, 0x3e7
  /* 80535BF4 40810064 */ ble-        lbl_80535c58
  /* 80535BF8 5783063E */ clrlwi      r3, r28, 0x18
  /* 80535BFC 3885FC18 */ addi        r4, r5, -0x3e8
  /* 80535C00 38630001 */ addi        r3, r3, 0x1
  /* 80535C04 5460063E */ clrlwi      r0, r3, 0x18
  /* 80535C08 5485043E */ clrlwi      r5, r4, 0x10
  /* 80535C0C 2800003B */ cmplwi      r0, 0x3b
  /* 80535C10 40810010 */ ble-        lbl_80535c20
  /* 80535C14 3803FFC4 */ addi        r0, r3, -0x3c
  /* 80535C18 38C00001 */ li          r6, 0x1
  /* 80535C1C 5403063E */ clrlwi      r3, r0, 0x18
  lbl_80535c20:
  /* 80535C20 A01D0008 */ lhz         r0, 8(r29)
  /* 80535C24 7CC60214 */ add         r6, r6, r0
  /* 80535C28 54C0043E */ clrlwi      r0, r6, 0x10
  /* 80535C2C 280003E7 */ cmplwi      r0, 0x3e7
  /* 80535C30 40810010 */ ble-        lbl_80535c40
  /* 80535C34 38C003E7 */ li          r6, 0x3e7
  /* 80535C38 3860003B */ li          r3, 0x3b
  /* 80535C3C 38A003E7 */ li          r5, 0x3e7
  lbl_80535c40:
  /* 80535C40 38000001 */ li          r0, 0x1
  /* 80535C44 981D001A */ stb         r0, 0x1a(r29)
  /* 80535C48 B0DD0014 */ sth         r6, 0x14(r29)
  /* 80535C4C 987D0016 */ stb         r3, 0x16(r29)
  /* 80535C50 B0BD0018 */ sth         r5, 0x18(r29)
  /* 80535C54 48000014 */ b           lbl_80535c68
  lbl_80535c58:
  /* 80535C58 989D001A */ stb         r4, 0x1a(r29)
  /* 80535C5C B3FD0014 */ sth         r31, 0x14(r29)
  /* 80535C60 9B9D0016 */ stb         r28, 0x16(r29)
  /* 80535C64 B0BD0018 */ sth         r5, 0x18(r29)
  lbl_80535c68:
  /* 80535C68 881D0040 */ lbz         r0, 0x40(r29)
  /* 80535C6C 2C000000 */ cmpwi       r0, 0x0
  /* 80535C70 40820010 */ bne-        lbl_80535c80
  /* 80535C74 807D0048 */ lwz         r3, 0x48(r29)
  /* 80535C78 38030001 */ addi        r0, r3, 0x1
  /* 80535C7C 901D0048 */ stw         r0, 0x48(r29)
  lbl_80535c80:
  /* 80535C80 80010044 */ lwz         r0, 0x44(r1)
  /* 80535C84 83E1003C */ lwz         r31, 0x3c(r1)
  /* 80535C88 83C10038 */ lwz         r30, 0x38(r1)
  /* 80535C8C 83A10034 */ lwz         r29, 0x34(r1)
  /* 80535C90 83810030 */ lwz         r28, 0x30(r1)
  /* 80535C94 7C0803A6 */ mtlr        r0
  /* 80535C98 38210040 */ addi        r1, r1, 0x40
  /* 80535C9C 4E800020 */ blr // clang-format on
}

// Symbol: RaceInfo_copyTimer
// PAL: 0x80535ca0..0x80535d14
MARK_BINARY_BLOB(RaceInfo_copyTimer, 0x80535ca0, 0x80535d14);
asm UNKNOWN_FUNCTION(RaceInfo_copyTimer){
  // clang-format off
  nofralloc
  /* 80535CA0 80A30014 */ lwz         r5, 0x14(r3)
  /* 80535CA4 2C050000 */ cmpwi       r5, 0x0
  /* 80535CA8 41820050 */ beq-        lbl_80535cf8
  /* 80535CAC A0050014 */ lhz         r0, 0x14(r5)
  /* 80535CB0 B0040004 */ sth         r0, 4(r4)
  /* 80535CB4 88050016 */ lbz         r0, 0x16(r5)
  /* 80535CB8 98040006 */ stb         r0, 6(r4)
  /* 80535CBC A0050018 */ lhz         r0, 0x18(r5)
  /* 80535CC0 B0040008 */ sth         r0, 8(r4)
  /* 80535CC4 8805001A */ lbz         r0, 0x1a(r5)
  /* 80535CC8 9804000A */ stb         r0, 0xa(r4)
  /* 80535CCC 80630014 */ lwz         r3, 0x14(r3)
  /* 80535CD0 88030040 */ lbz         r0, 0x40(r3)
  /* 80535CD4 2C000000 */ cmpwi       r0, 0x0
  /* 80535CD8 4D820020 */ beqlr-
  /* 80535CDC 3C600001 */ lis         r3, 1
  /* 80535CE0 38000000 */ li          r0, 0x0
  /* 80535CE4 3863FFFF */ addi        r3, r3, -0x1
  /* 80535CE8 B0640004 */ sth         r3, 4(r4)
  /* 80535CEC 98040006 */ stb         r0, 6(r4)
  /* 80535CF0 B0040008 */ sth         r0, 8(r4)
  /* 80535CF4 4E800020 */ blr
  lbl_80535cf8:
  /* 80535CF8 38000000 */ li          r0, 0x0
  /* 80535CFC 38600001 */ li          r3, 0x1
  /* 80535D00 9864000A */ stb         r3, 0xa(r4)
  /* 80535D04 B0040004 */ sth         r0, 4(r4)
  /* 80535D08 98040006 */ stb         r0, 6(r4)
  /* 80535D0C B0040008 */ sth         r0, 8(r4)
  /* 80535D10 4E800020 */ blr // clang-format on
}

// Symbol: TimeAttackGamemode_canEndRace
// PAL: 0x80535d14..0x80535de8
MARK_BINARY_BLOB(TimeAttackGamemode_canEndRace, 0x80535d14, 0x80535de8);
asm UNKNOWN_FUNCTION(TimeAttackGamemode_canEndRace) {
  // clang-format off
  nofralloc
  /* 80535D14 3C60809C */ lis         r3, spInstance__Q26System9CourseMap@ha
  /* 80535D18 8083D6E8 */ lwz         r4, spInstance__Q26System9CourseMap@l(r3)
  /* 80535D1C 80640020 */ lwz         r3, 0x20(r4)
  /* 80535D20 2C030000 */ cmpwi       r3, 0x0
  /* 80535D24 4182000C */ beq-        lbl_80535d30
  /* 80535D28 A0630004 */ lhz         r3, 4(r3)
  /* 80535D2C 48000008 */ b           lbl_80535d34
  lbl_80535d30:
  /* 80535D30 38600000 */ li          r3, 0x0
  lbl_80535d34:
  /* 80535D34 7C0300D0 */ neg         r0, r3
  /* 80535D38 7C001B78 */ or          r0, r0, r3
  /* 80535D3C 54000FFF */ rlwinm.     r0, r0, 1, 0x1f, 0x1f
  /* 80535D40 41820028 */ beq-        lbl_80535d68
  /* 80535D44 8064001C */ lwz         r3, 0x1c(r4)
  /* 80535D48 2C030000 */ cmpwi       r3, 0x0
  /* 80535D4C 4182000C */ beq-        lbl_80535d58
  /* 80535D50 A0630004 */ lhz         r3, 4(r3)
  /* 80535D54 48000008 */ b           lbl_80535d5c
  lbl_80535d58:
  /* 80535D58 38600000 */ li          r3, 0x0
  lbl_80535d5c:
  /* 80535D5C 7C0300D0 */ neg         r0, r3
  /* 80535D60 7C001B78 */ or          r0, r0, r3
  /* 80535D64 54000FFE */ srwi        r0, r0, 0x1f
  lbl_80535d68:
  /* 80535D68 2C000000 */ cmpwi       r0, 0x0
  /* 80535D6C 4082000C */ bne-        lbl_80535d78
  /* 80535D70 38600000 */ li          r3, 0x0
  /* 80535D74 4E800020 */ blr
  lbl_80535d78:
  /* 80535D78 3C80809C */ lis         r4, spInstance__Q26System10RaceConfig@ha
  /* 80535D7C 3C60809C */ lis         r3, spInstance__Q26System11RaceManager@ha
  /* 80535D80 80C4D728 */ lwz         r6, spInstance__Q26System10RaceConfig@l(r4)
  /* 80535D84 38E00000 */ li          r7, 0x0
  /* 80535D88 8083D730 */ lwz         r4, spInstance__Q26System11RaceManager@l(r3)
  /* 80535D8C 88A60024 */ lbz         r5, 0x24(r6)
  /* 80535D90 38C60028 */ addi        r6, r6, 0x28
  /* 80535D94 48000040 */ b           lbl_80535dd4
  lbl_80535d98:
  /* 80535D98 54E0063E */ clrlwi      r0, r7, 0x18
  /* 80535D9C 1C0000F0 */ mulli       r0, r0, 0xf0
  /* 80535DA0 7C660214 */ add         r3, r6, r0
  /* 80535DA4 80030010 */ lwz         r0, 0x10(r3)
  /* 80535DA8 2C000000 */ cmpwi       r0, 0x0
  /* 80535DAC 40820024 */ bne-        lbl_80535dd0
  /* 80535DB0 8064000C */ lwz         r3, 0xc(r4)
  /* 80535DB4 54E015BA */ rlwinm      r0, r7, 2, 0x16, 0x1d
  /* 80535DB8 7C63002E */ lwzx        r3, r3, r0
  /* 80535DBC 80030038 */ lwz         r0, 0x38(r3)
  /* 80535DC0 540007BD */ rlwinm.     r0, r0, 0, 0x1e, 0x1e
  /* 80535DC4 4082000C */ bne-        lbl_80535dd0
  /* 80535DC8 38600000 */ li          r3, 0x0
  /* 80535DCC 4E800020 */ blr
  lbl_80535dd0:
  /* 80535DD0 38E70001 */ addi        r7, r7, 0x1
  lbl_80535dd4:
  /* 80535DD4 54E0063E */ clrlwi      r0, r7, 0x18
  /* 80535DD8 7C002840 */ cmplw       r0, r5
  /* 80535DDC 4180FFBC */ blt+        lbl_80535d98
  /* 80535DE0 38600001 */ li          r3, 0x1
  /* 80535DE4 4E800020 */ blr // clang-format on
}

// Symbol: unk_80535de8
// PAL: 0x80535de8..0x80535e84
MARK_BINARY_BLOB(unk_80535de8, 0x80535de8, 0x80535e84);
asm UNKNOWN_FUNCTION(unk_80535de8) {
  // clang-format off
  nofralloc
  /* 80535DE8 9421FFE0 */ stwu        r1, -0x20(r1)
  /* 80535DEC 7C0802A6 */ mflr        r0
  /* 80535DF0 90010024 */ stw         r0, 0x24(r1)
  /* 80535DF4 93E1001C */ stw         r31, 0x1c(r1)
  /* 80535DF8 3FE0809C */ lis         r31, spInstance__Q26System10RaceConfig@ha
  /* 80535DFC 93C10018 */ stw         r30, 0x18(r1)
  /* 80535E00 3FC0809C */ lis         r30, spInstance__Q26System11RaceManager@ha
  /* 80535E04 93A10014 */ stw         r29, 0x14(r1)
  /* 80535E08 3BA00000 */ li          r29, 0x0
  /* 80535E0C 93810010 */ stw         r28, 0x10(r1)
  /* 80535E10 7C7C1B78 */ mr          r28, r3
  /* 80535E14 4800003C */ b           lbl_80535e50
  lbl_80535e18:
  /* 80535E18 807ED730 */ lwz         r3, spInstance__Q26System11RaceManager@l(r30)
  /* 80535E1C 57A615BA */ rlwinm      r6, r29, 2, 0x16, 0x1d
  /* 80535E20 8063000C */ lwz         r3, 0xc(r3)
  /* 80535E24 7C63302E */ lwzx        r3, r3, r6
  /* 80535E28 80030038 */ lwz         r0, 0x38(r3)
  /* 80535E2C 540007BD */ rlwinm.     r0, r0, 0, 0x1e, 0x1e
  /* 80535E30 4082001C */ bne-        lbl_80535e4c
  /* 80535E34 807C0004 */ lwz         r3, 4(r28)
  /* 80535E38 38800002 */ li          r4, 0x2
  /* 80535E3C 38A00001 */ li          r5, 0x1
  /* 80535E40 8063000C */ lwz         r3, 0xc(r3)
  /* 80535E44 7C63302E */ lwzx        r3, r3, r6
  /* 80535E48 4BFFE4A1 */ bl          unk_805342e8
  lbl_80535e4c:
  /* 80535E4C 3BBD0001 */ addi        r29, r29, 0x1
  lbl_80535e50:
  /* 80535E50 807FD728 */ lwz         r3, spInstance__Q26System10RaceConfig@l(r31)
  /* 80535E54 57A4063E */ clrlwi      r4, r29, 0x18
  /* 80535E58 88030024 */ lbz         r0, 0x24(r3)
  /* 80535E5C 7C040040 */ cmplw       r4, r0
  /* 80535E60 4180FFB8 */ blt+        lbl_80535e18
  /* 80535E64 80010024 */ lwz         r0, 0x24(r1)
  /* 80535E68 83E1001C */ lwz         r31, 0x1c(r1)
  /* 80535E6C 83C10018 */ lwz         r30, 0x18(r1)
  /* 80535E70 83A10014 */ lwz         r29, 0x14(r1)
  /* 80535E74 83810010 */ lwz         r28, 0x10(r1)
  /* 80535E78 7C0803A6 */ mtlr        r0
  /* 80535E7C 38210020 */ addi        r1, r1, 0x20
  /* 80535E80 4E800020 */ blr // clang-format on
}

// Symbol: unk_80535e84
// PAL: 0x80535e84..0x80535ef4
MARK_BINARY_BLOB(unk_80535e84, 0x80535e84, 0x80535ef4);
asm UNKNOWN_FUNCTION(unk_80535e84) {
  // clang-format off
  nofralloc
  /* 80535E84 3C80809C */ lis         r4, spInstance__Q26System9CourseMap@ha
  /* 80535E88 80A4D6E8 */ lwz         r5, spInstance__Q26System9CourseMap@l(r4)
  /* 80535E8C 80850020 */ lwz         r4, 0x20(r5)
  /* 80535E90 2C040000 */ cmpwi       r4, 0x0
  /* 80535E94 4182000C */ beq-        lbl_80535ea0
  /* 80535E98 A0840004 */ lhz         r4, 4(r4)
  /* 80535E9C 48000008 */ b           lbl_80535ea4
  lbl_80535ea0:
  /* 80535EA0 38800000 */ li          r4, 0x0
  lbl_80535ea4:
  /* 80535EA4 7C0400D0 */ neg         r0, r4
  /* 80535EA8 7C002378 */ or          r0, r0, r4
  /* 80535EAC 54000FFF */ rlwinm.     r0, r0, 1, 0x1f, 0x1f
  /* 80535EB0 41820028 */ beq-        lbl_80535ed8
  /* 80535EB4 8085001C */ lwz         r4, 0x1c(r5)
  /* 80535EB8 2C040000 */ cmpwi       r4, 0x0
  /* 80535EBC 4182000C */ beq-        lbl_80535ec8
  /* 80535EC0 A0840004 */ lhz         r4, 4(r4)
  /* 80535EC4 48000008 */ b           lbl_80535ecc
  lbl_80535ec8:
  /* 80535EC8 38800000 */ li          r4, 0x0
  lbl_80535ecc:
  /* 80535ECC 7C0400D0 */ neg         r0, r4
  /* 80535ED0 7C002378 */ or          r0, r0, r4
  /* 80535ED4 54000FFE */ srwi        r0, r0, 0x1f
  lbl_80535ed8:
  /* 80535ED8 2C000000 */ cmpwi       r0, 0x0
  /* 80535EDC 4D820020 */ beqlr-
  /* 80535EE0 81830000 */ lwz         r12, 0(r3)
  /* 80535EE4 818C0014 */ lwz         r12, 0x14(r12)
  /* 80535EE8 7D8903A6 */ mtctr       r12
  /* 80535EEC 4E800420 */ bctr
  /* 80535EF0 4E800020 */ blr // clang-format on
}

// Symbol: unk_80535ef4
// PAL: 0x80535ef4..0x80535f28
MARK_BINARY_BLOB(unk_80535ef4, 0x80535ef4, 0x80535f28);
asm UNKNOWN_FUNCTION(unk_80535ef4) {
  // clang-format off
  nofralloc
  /* 80535EF4 80630004 */ lwz         r3, 4(r3)
  /* 80535EF8 548015BA */ rlwinm      r0, r4, 2, 0x16, 0x1d
  /* 80535EFC 8063000C */ lwz         r3, 0xc(r3)
  /* 80535F00 7C63002E */ lwzx        r3, r3, r0
  /* 80535F04 88830021 */ lbz         r4, 0x21(r3)
  /* 80535F08 7C800775 */ extsb.      r0, r4
  /* 80535F0C 40800008 */ bge-        lbl_80535f14
  /* 80535F10 38800000 */ li          r4, 0x0
  lbl_80535f14:
  /* 80535F14 3C60809C */ lis         r3, spInstance__Q26System9CourseMap@ha
  /* 80535F18 7C840774 */ extsb       r4, r4
  /* 80535F1C 8063D6E8 */ lwz         r3, spInstance__Q26System9CourseMap@l(r3)
  /* 80535F20 5484043E */ clrlwi      r4, r4, 0x10
  /* 80535F24 4BFE29FC */ b           getJugemPoint__Q26System9CourseMapCFUs // clang-format on
}

// Symbol: unk_80535f28
// PAL: 0x80535f28..0x80535fe4
MARK_BINARY_BLOB(unk_80535f28, 0x80535f28, 0x80535fe4);
asm UNKNOWN_FUNCTION(unk_80535f28) {
  // clang-format off
  nofralloc
  /* 80535F28 9421FFF0 */ stwu        r1, -0x10(r1)
  /* 80535F2C 7C0802A6 */ mflr        r0
  /* 80535F30 3C60809C */ lis         r3, spInstance__Q26System9CourseMap@ha
  /* 80535F34 90010014 */ stw         r0, 0x14(r1)
  /* 80535F38 8083D6E8 */ lwz         r4, spInstance__Q26System9CourseMap@l(r3)
  /* 80535F3C 80640020 */ lwz         r3, 0x20(r4)
  /* 80535F40 2C030000 */ cmpwi       r3, 0x0
  /* 80535F44 4182000C */ beq-        lbl_80535f50
  /* 80535F48 A0630004 */ lhz         r3, 4(r3)
  /* 80535F4C 48000008 */ b           lbl_80535f54
  lbl_80535f50:
  /* 80535F50 38600000 */ li          r3, 0x0
  lbl_80535f54:
  /* 80535F54 7C0300D0 */ neg         r0, r3
  /* 80535F58 7C001B78 */ or          r0, r0, r3
  /* 80535F5C 54000FFF */ rlwinm.     r0, r0, 1, 0x1f, 0x1f
  /* 80535F60 41820028 */ beq-        lbl_80535f88
  /* 80535F64 8064001C */ lwz         r3, 0x1c(r4)
  /* 80535F68 2C030000 */ cmpwi       r3, 0x0
  /* 80535F6C 4182000C */ beq-        lbl_80535f78
  /* 80535F70 A0630004 */ lhz         r3, 4(r3)
  /* 80535F74 48000008 */ b           lbl_80535f7c
  lbl_80535f78:
  /* 80535F78 38600000 */ li          r3, 0x0
  lbl_80535f7c:
  /* 80535F7C 7C0300D0 */ neg         r0, r3
  /* 80535F80 7C001B78 */ or          r0, r0, r3
  /* 80535F84 54000FFE */ srwi        r0, r0, 0x1f
  lbl_80535f88:
  /* 80535F88 2C000000 */ cmpwi       r0, 0x0
  /* 80535F8C 4082000C */ bne-        lbl_80535f98
  /* 80535F90 38600000 */ li          r3, 0x0
  /* 80535F94 48000040 */ b           lbl_80535fd4
  lbl_80535f98:
  /* 80535F98 3C60809C */ lis         r3, spInstance__Q26System10RaceConfig@ha
  /* 80535F9C 38800000 */ li          r4, 0x0
  /* 80535FA0 8063D728 */ lwz         r3, spInstance__Q26System10RaceConfig@l(r3)
  /* 80535FA4 4BFFBFCD */ bl          getHudPlayerId__Q26System10RaceConfigFUc
  /* 80535FA8 7C600775 */ extsb.      r0, r3
  /* 80535FAC 4080000C */ bge-        lbl_80535fb8
  /* 80535FB0 38600000 */ li          r3, 0x0
  /* 80535FB4 48000020 */ b           lbl_80535fd4
  lbl_80535fb8:
  /* 80535FB8 3C80809C */ lis         r4, spInstance__Q26System11RaceManager@ha
  /* 80535FBC 546015BA */ rlwinm      r0, r3, 2, 0x16, 0x1d
  /* 80535FC0 8064D730 */ lwz         r3, spInstance__Q26System11RaceManager@l(r4)
  /* 80535FC4 8063000C */ lwz         r3, 0xc(r3)
  /* 80535FC8 7C63002E */ lwzx        r3, r3, r0
  /* 80535FCC 80030038 */ lwz         r0, 0x38(r3)
  /* 80535FD0 5403FFFE */ rlwinm      r3, r0, 0x1f, 0x1f, 0x1f
  lbl_80535fd4:
  /* 80535FD4 80010014 */ lwz         r0, 0x14(r1)
  /* 80535FD8 7C0803A6 */ mtlr        r0
  /* 80535FDC 38210010 */ addi        r1, r1, 0x10
  /* 80535FE0 4E800020 */ blr // clang-format on
}

// Symbol: unk_80535fe4
// PAL: 0x80535fe4..0x80536054
MARK_BINARY_BLOB(unk_80535fe4, 0x80535fe4, 0x80536054);
asm UNKNOWN_FUNCTION(unk_80535fe4) {
  // clang-format off
  nofralloc
  /* 80535FE4 3C80809C */ lis         r4, spInstance__Q26System9CourseMap@ha
  /* 80535FE8 80A4D6E8 */ lwz         r5, spInstance__Q26System9CourseMap@l(r4)
  /* 80535FEC 80850020 */ lwz         r4, 0x20(r5)
  /* 80535FF0 2C040000 */ cmpwi       r4, 0x0
  /* 80535FF4 4182000C */ beq-        lbl_80536000
  /* 80535FF8 A0840004 */ lhz         r4, 4(r4)
  /* 80535FFC 48000008 */ b           lbl_80536004
  lbl_80536000:
  /* 80536000 38800000 */ li          r4, 0x0
  lbl_80536004:
  /* 80536004 7C0400D0 */ neg         r0, r4
  /* 80536008 7C002378 */ or          r0, r0, r4
  /* 8053600C 54000FFF */ rlwinm.     r0, r0, 1, 0x1f, 0x1f
  /* 80536010 41820028 */ beq-        lbl_80536038
  /* 80536014 8085001C */ lwz         r4, 0x1c(r5)
  /* 80536018 2C040000 */ cmpwi       r4, 0x0
  /* 8053601C 4182000C */ beq-        lbl_80536028
  /* 80536020 A0840004 */ lhz         r4, 4(r4)
  /* 80536024 48000008 */ b           lbl_8053602c
  lbl_80536028:
  /* 80536028 38800000 */ li          r4, 0x0
  lbl_8053602c:
  /* 8053602C 7C0400D0 */ neg         r0, r4
  /* 80536030 7C002378 */ or          r0, r0, r4
  /* 80536034 54000FFE */ srwi        r0, r0, 0x1f
  lbl_80536038:
  /* 80536038 2C000000 */ cmpwi       r0, 0x0
  /* 8053603C 4D820020 */ beqlr-
  /* 80536040 81830000 */ lwz         r12, 0(r3)
  /* 80536044 818C0014 */ lwz         r12, 0x14(r12)
  /* 80536048 7D8903A6 */ mtctr       r12
  /* 8053604C 4E800420 */ bctr
  /* 80536050 4E800020 */ blr // clang-format on
}

// Symbol: unk_80536054
// PAL: 0x80536054..0x80536208
MARK_BINARY_BLOB(unk_80536054, 0x80536054, 0x80536208);
asm UNKNOWN_FUNCTION(unk_80536054) {
  // clang-format off
  nofralloc
  /* 80536054 9421FFF0 */ stwu        r1, -0x10(r1)
  /* 80536058 7C0802A6 */ mflr        r0
  /* 8053605C 3C60809C */ lis         r3, spInstance__Q26System9CourseMap@ha
  /* 80536060 90010014 */ stw         r0, 0x14(r1)
  /* 80536064 8083D6E8 */ lwz         r4, spInstance__Q26System9CourseMap@l(r3)
  /* 80536068 80640020 */ lwz         r3, 0x20(r4)
  /* 8053606C 2C030000 */ cmpwi       r3, 0x0
  /* 80536070 4182000C */ beq-        lbl_8053607c
  /* 80536074 A0630004 */ lhz         r3, 4(r3)
  /* 80536078 48000008 */ b           lbl_80536080
  lbl_8053607c:
  /* 8053607C 38600000 */ li          r3, 0x0
  lbl_80536080:
  /* 80536080 7C0300D0 */ neg         r0, r3
  /* 80536084 7C001B78 */ or          r0, r0, r3
  /* 80536088 54000FFF */ rlwinm.     r0, r0, 1, 0x1f, 0x1f
  /* 8053608C 41820028 */ beq-        lbl_805360b4
  /* 80536090 8064001C */ lwz         r3, 0x1c(r4)
  /* 80536094 2C030000 */ cmpwi       r3, 0x0
  /* 80536098 4182000C */ beq-        lbl_805360a4
  /* 8053609C A0630004 */ lhz         r3, 4(r3)
  /* 805360A0 48000008 */ b           lbl_805360a8
  lbl_805360a4:
  /* 805360A4 38600000 */ li          r3, 0x0
  lbl_805360a8:
  /* 805360A8 7C0300D0 */ neg         r0, r3
  /* 805360AC 7C001B78 */ or          r0, r0, r3
  /* 805360B0 54000FFE */ srwi        r0, r0, 0x1f
  lbl_805360b4:
  /* 805360B4 2C000000 */ cmpwi       r0, 0x0
  /* 805360B8 4082000C */ bne-        lbl_805360c4
  /* 805360BC 38600000 */ li          r3, 0x0
  /* 805360C0 48000138 */ b           lbl_805361f8
  lbl_805360c4:
  /* 805360C4 3C60809C */ lis         r3, spInstance__Q26System10RaceConfig@ha
  /* 805360C8 8063D728 */ lwz         r3, spInstance__Q26System10RaceConfig@l(r3)
  /* 805360CC 80030B90 */ lwz         r0, 0xb90(r3)
  /* 805360D0 5400077B */ rlwinm.     r0, r0, 0, 0x1d, 0x1d
  /* 805360D4 4182003C */ beq-        lbl_80536110
  /* 805360D8 38800000 */ li          r4, 0x0
  /* 805360DC 4BFFBE95 */ bl          getHudPlayerId__Q26System10RaceConfigFUc
  /* 805360E0 7C600775 */ extsb.      r0, r3
  /* 805360E4 4080000C */ bge-        lbl_805360f0
  /* 805360E8 38600000 */ li          r3, 0x0
  /* 805360EC 4800010C */ b           lbl_805361f8
  lbl_805360f0:
  /* 805360F0 3C80809C */ lis         r4, spInstance__Q26System11RaceManager@ha
  /* 805360F4 546015BA */ rlwinm      r0, r3, 2, 0x16, 0x1d
  /* 805360F8 8064D730 */ lwz         r3, spInstance__Q26System11RaceManager@l(r4)
  /* 805360FC 8063000C */ lwz         r3, 0xc(r3)
  /* 80536100 7C63002E */ lwzx        r3, r3, r0
  /* 80536104 80030038 */ lwz         r0, 0x38(r3)
  /* 80536108 5403FFFE */ rlwinm      r3, r0, 0x1f, 0x1f, 0x1f
  /* 8053610C 480000EC */ b           lbl_805361f8
  lbl_80536110:
  /* 80536110 88C30024 */ lbz         r6, 0x24(r3)
  /* 80536114 39200000 */ li          r9, 0x0
  /* 80536118 39400000 */ li          r10, 0x0
  /* 8053611C 28060001 */ cmplwi      r6, 1
  /* 80536120 40820020 */ bne-        lbl_80536140
  /* 80536124 3C60809C */ lis         r3, spInstance__Q26System11RaceManager@ha
  /* 80536128 8063D730 */ lwz         r3, spInstance__Q26System11RaceManager@l(r3)
  /* 8053612C 8063000C */ lwz         r3, 0xc(r3)
  /* 80536130 80630000 */ lwz         r3, 0(r3)
  /* 80536134 80030038 */ lwz         r0, 0x38(r3)
  /* 80536138 5403FFFE */ rlwinm      r3, r0, 0x1f, 0x1f, 0x1f
  /* 8053613C 480000BC */ b           lbl_805361f8
  lbl_80536140:
  /* 80536140 3C80809C */ lis         r4, spInstance__Q26System11RaceManager@ha
  /* 80536144 38E30028 */ addi        r7, r3, 0x28
  /* 80536148 8104D730 */ lwz         r8, spInstance__Q26System11RaceManager@l(r4)
  /* 8053614C 39600000 */ li          r11, 0x0
  /* 80536150 7CC903A6 */ mtctr       r6
  /* 80536154 2C060000 */ cmpwi       r6, 0x0
  /* 80536158 4081009C */ ble-        lbl_805361f4
  lbl_8053615c:
  /* 8053615C 7C0B3050 */ subf        r0, r11, r6
  /* 80536160 80A80018 */ lwz         r5, 0x18(r8)
  /* 80536164 5400063E */ clrlwi      r0, r0, 0x18
  /* 80536168 8088000C */ lwz         r4, 0xc(r8)
  /* 8053616C 7CA50214 */ add         r5, r5, r0
  /* 80536170 39800000 */ li          r12, 0x0
  /* 80536174 88A5FFFF */ lbz         r5, -1(r5)
  /* 80536178 54A0103A */ slwi        r0, r5, 2
  /* 8053617C 7C84002E */ lwzx        r4, r4, r0
  /* 80536180 80040038 */ lwz         r0, 0x38(r4)
  /* 80536184 540007BD */ rlwinm.     r0, r0, 0, 0x1e, 0x1e
  /* 80536188 40820054 */ bne-        lbl_805361dc
  /* 8053618C 80830B74 */ lwz         r4, 0xb74(r3)
  /* 80536190 3804FFFE */ addi        r0, r4, -0x2
  /* 80536194 28000002 */ cmplwi      r0, 2
  /* 80536198 4181000C */ bgt-        lbl_805361a4
  /* 8053619C 39800001 */ li          r12, 0x1
  /* 805361A0 4800003C */ b           lbl_805361dc
  lbl_805361a4:
  /* 805361A4 1C0500F0 */ mulli       r0, r5, 0xf0
  /* 805361A8 39290001 */ addi        r9, r9, 0x1
  /* 805361AC 7C870214 */ add         r4, r7, r0
  /* 805361B0 80040010 */ lwz         r0, 0x10(r4)
  /* 805361B4 2C000000 */ cmpwi       r0, 0x0
  /* 805361B8 40820008 */ bne-        lbl_805361c0
  /* 805361BC 39400001 */ li          r10, 0x1
  lbl_805361c0:
  /* 805361C0 2C0A0000 */ cmpwi       r10, 0x0
  /* 805361C4 39800000 */ li          r12, 0x0
  /* 805361C8 41820014 */ beq-        lbl_805361dc
  /* 805361CC 5520063E */ clrlwi      r0, r9, 0x18
  /* 805361D0 28000001 */ cmplwi      r0, 1
  /* 805361D4 40810008 */ ble-        lbl_805361dc
  /* 805361D8 39800001 */ li          r12, 0x1
  lbl_805361dc:
  /* 805361DC 2C0C0000 */ cmpwi       r12, 0x0
  /* 805361E0 4182000C */ beq-        lbl_805361ec
  /* 805361E4 38600000 */ li          r3, 0x0
  /* 805361E8 48000010 */ b           lbl_805361f8
  lbl_805361ec:
  /* 805361EC 396B0001 */ addi        r11, r11, 0x1
  /* 805361F0 4200FF6C */ bdnz        lbl_8053615c
  lbl_805361f4:
  /* 805361F4 38600001 */ li          r3, 0x1
  lbl_805361f8:
  /* 805361F8 80010014 */ lwz         r0, 0x14(r1)
  /* 805361FC 7C0803A6 */ mtlr        r0
  /* 80536200 38210010 */ addi        r1, r1, 0x10
  /* 80536204 4E800020 */ blr // clang-format on
}

// Symbol: unk_80536208
// PAL: 0x80536208..0x8053621c
MARK_BINARY_BLOB(unk_80536208, 0x80536208, 0x8053621c);
asm UNKNOWN_FUNCTION(unk_80536208){
    // clang-format off
  nofralloc
  /* 80536208 80630010 */ lwz         r3, 0x10(r3)
  /* 8053620C 81830000 */ lwz         r12, 0(r3)
  /* 80536210 818C0008 */ lwz         r12, 8(r12)
  /* 80536214 7D8903A6 */ mtctr       r12
  /* 80536218 4E800420 */ bctr // clang-format on
}

// Symbol: unk_8053621c
// PAL: 0x8053621c..0x80536230
MARK_BINARY_BLOB(unk_8053621c, 0x8053621c, 0x80536230);
asm UNKNOWN_FUNCTION(unk_8053621c){
    // clang-format off
  nofralloc
  /* 8053621C 80630010 */ lwz         r3, 0x10(r3)
  /* 80536220 81830000 */ lwz         r12, 0(r3)
  /* 80536224 818C0018 */ lwz         r12, 0x18(r12)
  /* 80536228 7D8903A6 */ mtctr       r12
  /* 8053622C 4E800420 */ bctr // clang-format on
}

// Symbol: Raceinfo_isAtLeastStage
// PAL: 0x80536230..0x80536248
MARK_BINARY_BLOB(Raceinfo_isAtLeastStage, 0x80536230, 0x80536248);
asm UNKNOWN_FUNCTION(Raceinfo_isAtLeastStage){
    // clang-format off
  nofralloc
  /* 80536230 80030028 */ lwz         r0, 0x28(r3)
  /* 80536234 54830FFE */ srwi        r3, r4, 0x1f
  /* 80536238 7C05FE70 */ srawi       r5, r0, 0x1f
  /* 8053623C 7C040010 */ subfc       r0, r4, r0
  /* 80536240 7C651914 */ adde        r3, r5, r3
  /* 80536244 4E800020 */ blr // clang-format on
}

// Symbol: unk_80536248
// PAL: 0x80536248..0x805362dc
MARK_BINARY_BLOB(unk_80536248, 0x80536248, 0x805362dc);
asm UNKNOWN_FUNCTION(unk_80536248) {
  // clang-format off
  nofralloc
  /* 80536248 3CA0809C */ lis         r5, spInstance__Q26System10RaceConfig@ha
  /* 8053624C 38E00000 */ li          r7, 0x0
  /* 80536250 80A5D728 */ lwz         r5, spInstance__Q26System10RaceConfig@l(r5)
  /* 80536254 1C0400F0 */ mulli       r0, r4, 0xf0
  /* 80536258 39000000 */ li          r8, 0x0
  /* 8053625C 38C50028 */ addi        r6, r5, 0x28
  /* 80536260 7CA60214 */ add         r5, r6, r0
  /* 80536264 80A500CC */ lwz         r5, 0xcc(r5)
  /* 80536268 7C8903A6 */ mtctr       r4
  /* 8053626C 28040000 */ cmplwi      r4, 0
  /* 80536270 4081002C */ ble-        lbl_8053629c
  lbl_80536274:
  /* 80536274 5500063E */ clrlwi      r0, r8, 0x18
  /* 80536278 1C0000F0 */ mulli       r0, r0, 0xf0
  /* 8053627C 7C860214 */ add         r4, r6, r0
  /* 80536280 800400CC */ lwz         r0, 0xcc(r4)
  /* 80536284 7C050000 */ cmpw        r5, r0
  /* 80536288 4082000C */ bne-        lbl_80536294
  /* 8053628C 38070001 */ addi        r0, r7, 0x1
  /* 80536290 5407063E */ clrlwi      r7, r0, 0x18
  lbl_80536294:
  /* 80536294 39080001 */ addi        r8, r8, 0x1
  /* 80536298 4200FFDC */ bdnz        lbl_80536274
  lbl_8053629c:
  /* 8053629C 2C050001 */ cmpwi       r5, 0x1
  /* 805362A0 38A00000 */ li          r5, 0x0
  /* 805362A4 40820008 */ bne-        lbl_805362ac
  /* 805362A8 38A00006 */ li          r5, 0x6
  lbl_805362ac:
  /* 805362AC 88830024 */ lbz         r4, 0x24(r3)
  /* 805362B0 3C602AAB */ lis         r3, 0x2aab
  /* 805362B4 3803AAAB */ addi        r0, r3, -0x5555
  /* 805362B8 7C843A14 */ add         r4, r4, r7
  /* 805362BC 7C602096 */ mulhw       r3, r0, r4
  /* 805362C0 54600FFE */ srwi        r0, r3, 0x1f
  /* 805362C4 7C030214 */ add         r0, r3, r0
  /* 805362C8 1C000006 */ mulli       r0, r0, 0x6
  /* 805362CC 7C002050 */ subf        r0, r0, r4
  /* 805362D0 7C050214 */ add         r0, r5, r0
  /* 805362D4 5403063E */ clrlwi      r3, r0, 0x18
  /* 805362D8 4E800020 */ blr // clang-format on
}

// Symbol: Raceinfo_getInitialPosAndRotForPlayer
// PAL: 0x805362dc..0x805365c8
MARK_BINARY_BLOB(Raceinfo_getInitialPosAndRotForPlayer, 0x805362dc, 0x805365c8);
asm UNKNOWN_FUNCTION(Raceinfo_getInitialPosAndRotForPlayer) {
  // clang-format off
  nofralloc
  /* 805362DC 9421FFD0 */ stwu        r1, -0x30(r1)
  /* 805362E0 7C0802A6 */ mflr        r0
  /* 805362E4 90010034 */ stw         r0, 0x34(r1)
  /* 805362E8 39610030 */ addi        r11, r1, 0x30
  /* 805362EC 4BAEB2A9 */ bl          _savegpr_24
  /* 805362F0 3F20809C */ lis         r25, spInstance__Q26System10RaceConfig@ha
  /* 805362F4 7C9A2378 */ mr          r26, r4
  /* 805362F8 80F9D728 */ lwz         r7, spInstance__Q26System10RaceConfig@l(r25)
  /* 805362FC 7CBB2B78 */ mr          r27, r5
  /* 80536300 7CDC3378 */ mr          r28, r6
  /* 80536304 80070B70 */ lwz         r0, 0xb70(r7)
  /* 80536308 2800000C */ cmplwi      r0, 0xc
  /* 8053630C 41810234 */ bgt-        lbl_80536540
  /* 80536310 3C80808B */ lis         r4, jtbl_808b32e8@ha
  /* 80536314 5400103A */ slwi        r0, r0, 2
  /* 80536318 388432E8 */ addi        r4, r4, jtbl_808b32e8@l
  /* 8053631C 7C84002E */ lwzx        r4, r4, r0
  /* 80536320 7C8903A6 */ mtctr       r4
  /* 80536324 4E800420 */ bctr
  lbl_80536328:
  entry jump_80536328
  /* 80536328 3C80809C */ lis         r4, spInstance__Q26System9CourseMap@ha
  /* 8053632C 3BE00001 */ li          r31, 0x1
  /* 80536330 8084D6E8 */ lwz         r4, spInstance__Q26System9CourseMap@l(r4)
  /* 80536334 3BA00001 */ li          r29, 0x1
  /* 80536338 80840008 */ lwz         r4, 8(r4)
  /* 8053633C 2C040000 */ cmpwi       r4, 0x0
  /* 80536340 4182000C */ beq-        lbl_8053634c
  /* 80536344 A0040004 */ lhz         r0, 4(r4)
  /* 80536348 48000008 */ b           lbl_80536350
  lbl_8053634c:
  /* 8053634C 38000000 */ li          r0, 0x0
  lbl_80536350:
  /* 80536350 28000001 */ cmplwi      r0, 1
  /* 80536354 4181000C */ bgt-        lbl_80536360
  /* 80536358 3BC00000 */ li          r30, 0x0
  /* 8053635C 480001FC */ b           lbl_80536558
  lbl_80536360:
  /* 80536360 3C80809C */ lis         r4, spInstance__Q26System10RaceConfig@ha
  /* 80536364 3BC00000 */ li          r30, 0x0
  /* 80536368 8084D728 */ lwz         r4, spInstance__Q26System10RaceConfig@l(r4)
  /* 8053636C 1C0600F0 */ mulli       r0, r6, 0xf0
  /* 80536370 38E00000 */ li          r7, 0x0
  /* 80536374 39240028 */ addi        r9, r4, 0x28
  /* 80536378 7C890214 */ add         r4, r9, r0
  /* 8053637C 38A00000 */ li          r5, 0x0
  /* 80536380 810400CC */ lwz         r8, 0xcc(r4)
  /* 80536384 7CC903A6 */ mtctr       r6
  /* 80536388 28060000 */ cmplwi      r6, 0
  /* 8053638C 4081002C */ ble-        lbl_805363b8
  lbl_80536390:
  /* 80536390 54A0063E */ clrlwi      r0, r5, 0x18
  /* 80536394 1C0000F0 */ mulli       r0, r0, 0xf0
  /* 80536398 7C890214 */ add         r4, r9, r0
  /* 8053639C 800400CC */ lwz         r0, 0xcc(r4)
  /* 805363A0 7C080000 */ cmpw        r8, r0
  /* 805363A4 4082000C */ bne-        lbl_805363b0
  /* 805363A8 38070001 */ addi        r0, r7, 0x1
  /* 805363AC 5407063E */ clrlwi      r7, r0, 0x18
  lbl_805363b0:
  /* 805363B0 38A50001 */ addi        r5, r5, 0x1
  /* 805363B4 4200FFDC */ bdnz        lbl_80536390
  lbl_805363b8:
  /* 805363B8 2C080001 */ cmpwi       r8, 0x1
  /* 805363BC 38A00000 */ li          r5, 0x0
  /* 805363C0 40820008 */ bne-        lbl_805363c8
  /* 805363C4 38A00006 */ li          r5, 0x6
  lbl_805363c8:
  /* 805363C8 88830024 */ lbz         r4, 0x24(r3)
  /* 805363CC 3C602AAB */ lis         r3, 0x2aab
  /* 805363D0 3803AAAB */ addi        r0, r3, -0x5555
  /* 805363D4 3B800000 */ li          r28, 0x0
  /* 805363D8 7C843A14 */ add         r4, r4, r7
  /* 805363DC 3F20809C */ lis         r25, spInstance__Q26System9CourseMap@ha
  /* 805363E0 7C602096 */ mulhw       r3, r0, r4
  /* 805363E4 54600FFE */ srwi        r0, r3, 0x1f
  /* 805363E8 7C030214 */ add         r0, r3, r0
  /* 805363EC 1C000006 */ mulli       r0, r0, 0x6
  /* 805363F0 7C002050 */ subf        r0, r0, r4
  /* 805363F4 7C050214 */ add         r0, r5, r0
  /* 805363F8 5418063E */ clrlwi      r24, r0, 0x18
  /* 805363FC 48000028 */ b           lbl_80536424
  lbl_80536400:
  /* 80536400 5784063E */ clrlwi      r4, r28, 0x18
  /* 80536404 4BFDE72D */ bl          getStartPoint__Q26System9CourseMapCFUs
  /* 80536408 80630000 */ lwz         r3, 0(r3)
  /* 8053640C A8030018 */ lha         r0, 0x18(r3)
  /* 80536410 7C180000 */ cmpw        r24, r0
  /* 80536414 4082000C */ bne-        lbl_80536420
  /* 80536418 7F9EE378 */ mr          r30, r28
  /* 8053641C 4800013C */ b           lbl_80536558
  lbl_80536420:
  /* 80536420 3B9C0001 */ addi        r28, r28, 0x1
  lbl_80536424:
  /* 80536424 8079D6E8 */ lwz         r3, spInstance__Q26System9CourseMap@l(r25)
  /* 80536428 5785063E */ clrlwi      r5, r28, 0x18
  /* 8053642C 80830008 */ lwz         r4, 8(r3)
  /* 80536430 2C040000 */ cmpwi       r4, 0x0
  /* 80536434 4082000C */ bne-        lbl_80536440
  /* 80536438 38000000 */ li          r0, 0x0
  /* 8053643C 48000008 */ b           lbl_80536444
  lbl_80536440:
  /* 80536440 A0040004 */ lhz         r0, 4(r4)
  lbl_80536444:
  /* 80536444 7C050000 */ cmpw        r5, r0
  /* 80536448 4180FFB8 */ blt+        lbl_80536400
  /* 8053644C 4800010C */ b           lbl_80536558
  lbl_80536450:
  entry jump_80536450
  /* 80536450 80070B74 */ lwz         r0, 0xb74(r7)
  /* 80536454 3BE00001 */ li          r31, 0x1
  /* 80536458 3BA00001 */ li          r29, 0x1
  /* 8053645C 38600003 */ li          r3, 0x3
  /* 80536460 2C00000C */ cmpwi       r0, 0xc
  /* 80536464 40820008 */ bne-        lbl_8053646c
  /* 80536468 38600006 */ li          r3, 0x6
  lbl_8053646c:
  /* 8053646C 7C061800 */ cmpw        r6, r3
  /* 80536470 4080000C */ bge-        lbl_8053647c
  /* 80536474 7F9EE378 */ mr          r30, r28
  /* 80536478 480000E0 */ b           lbl_80536558
  lbl_8053647c:
  /* 8053647C 3BC00000 */ li          r30, 0x0
  /* 80536480 480000D8 */ b           lbl_80536558
  lbl_80536484:
  entry jump_80536484
  /* 80536484 7F9EE378 */ mr          r30, r28
  /* 80536488 3BE00001 */ li          r31, 0x1
  /* 8053648C 3BA00001 */ li          r29, 0x1
  /* 80536490 480000C8 */ b           lbl_80536558
  lbl_80536494:
  entry jump_80536494
  /* 80536494 3BE00001 */ li          r31, 0x1
  /* 80536498 3BA00001 */ li          r29, 0x1
  /* 8053649C 3BC00000 */ li          r30, 0x0
  /* 805364A0 480000B8 */ b           lbl_80536558
  lbl_805364a4:
  entry jump_805364a4
  /* 805364A4 3FC0809C */ lis         r30, spInstance__Q26System9CourseMap@ha
  /* 805364A8 38800000 */ li          r4, 0x0
  /* 805364AC 807ED6E8 */ lwz         r3, spInstance__Q26System9CourseMap@l(r30)
  /* 805364B0 4BFDE681 */ bl          getStartPoint__Q26System9CourseMapCFUs
  /* 805364B4 80630000 */ lwz         r3, 0(r3)
  /* 805364B8 A8030018 */ lha         r0, 0x18(r3)
  /* 805364BC 2C00FFFF */ cmpwi       r0, -0x1
  /* 805364C0 40820020 */ bne-        lbl_805364e0
  /* 805364C4 8079D728 */ lwz         r3, spInstance__Q26System10RaceConfig@l(r25)
  /* 805364C8 3BC00000 */ li          r30, 0x0
  /* 805364CC 8BA30024 */ lbz         r29, 0x24(r3)
  /* 805364D0 7C7CE850 */ subf        r3, r28, r29
  /* 805364D4 38030001 */ addi        r0, r3, 0x1
  /* 805364D8 541F063E */ clrlwi      r31, r0, 0x18
  /* 805364DC 4800007C */ b           lbl_80536558
  lbl_805364e0:
  /* 805364E0 3BE00001 */ li          r31, 0x1
  /* 805364E4 3BA00001 */ li          r29, 0x1
  /* 805364E8 3B000000 */ li          r24, 0x0
  /* 805364EC 48000028 */ b           lbl_80536514
  lbl_805364f0:
  /* 805364F0 5704063E */ clrlwi      r4, r24, 0x18
  /* 805364F4 4BFDE63D */ bl          getStartPoint__Q26System9CourseMapCFUs
  /* 805364F8 80630000 */ lwz         r3, 0(r3)
  /* 805364FC A8030018 */ lha         r0, 0x18(r3)
  /* 80536500 7C1C0000 */ cmpw        r28, r0
  /* 80536504 4082000C */ bne-        lbl_80536510
  /* 80536508 7F9EE378 */ mr          r30, r28
  /* 8053650C 4800004C */ b           lbl_80536558
  lbl_80536510:
  /* 80536510 3B180001 */ addi        r24, r24, 0x1
  lbl_80536514:
  /* 80536514 807ED6E8 */ lwz         r3, spInstance__Q26System9CourseMap@l(r30)
  /* 80536518 5705063E */ clrlwi      r5, r24, 0x18
  /* 8053651C 80830008 */ lwz         r4, 8(r3)
  /* 80536520 2C040000 */ cmpwi       r4, 0x0
  /* 80536524 4082000C */ bne-        lbl_80536530
  /* 80536528 38000000 */ li          r0, 0x0
  /* 8053652C 48000008 */ b           lbl_80536534
  lbl_80536530:
  /* 80536530 A0040004 */ lhz         r0, 4(r4)
  lbl_80536534:
  /* 80536534 7C050000 */ cmpw        r5, r0
  /* 80536538 4180FFB8 */ blt+        lbl_805364f0
  /* 8053653C 4800001C */ b           lbl_80536558
  lbl_80536540:
  entry jump_80536540
  /* 80536540 8063000C */ lwz         r3, 0xc(r3)
  /* 80536544 54C015BA */ rlwinm      r0, r6, 2, 0x16, 0x1d
  /* 80536548 8BA70024 */ lbz         r29, 0x24(r7)
  /* 8053654C 3BC00000 */ li          r30, 0x0
  /* 80536550 7C63002E */ lwzx        r3, r3, r0
  /* 80536554 8BE30020 */ lbz         r31, 0x20(r3)
  lbl_80536558:
  /* 80536558 3C60809C */ lis         r3, spInstance__Q26System9CourseMap@ha
  /* 8053655C 57C4063E */ clrlwi      r4, r30, 0x18
  /* 80536560 8063D6E8 */ lwz         r3, spInstance__Q26System9CourseMap@l(r3)
  /* 80536564 4BFDE5CD */ bl          getStartPoint__Q26System9CourseMapCFUs
  /* 80536568 2C030000 */ cmpwi       r3, 0x0
  /* 8053656C 4182001C */ beq-        lbl_80536588
  /* 80536570 7F44D378 */ mr          r4, r26
  /* 80536574 7F65DB78 */ mr          r5, r27
  /* 80536578 7FE6FB78 */ mr          r6, r31
  /* 8053657C 57A7063E */ clrlwi      r7, r29, 0x18
  /* 80536580 4BFDE5A5 */ bl          unk_80514b24
  /* 80536584 4800002C */ b           lbl_805365b0
  lbl_80536588:
  /* 80536588 3C808089 */ lis         r4, lbl_80890150@ha
  /* 8053658C 3C608089 */ lis         r3, lbl_8089017c@ha
  /* 80536590 C0240150 */ lfs         f1, lbl_80890150@l(r4)
  /* 80536594 D03A0008 */ stfs        f1, 8(r26)
  /* 80536598 C003017C */ lfs         f0, lbl_8089017c@l(r3)
  /* 8053659C D03A0004 */ stfs        f1, 4(r26)
  /* 805365A0 D03A0000 */ stfs        f1, 0(r26)
  /* 805365A4 D01B0000 */ stfs        f0, 0(r27)
  /* 805365A8 D03B0004 */ stfs        f1, 4(r27)
  /* 805365AC D03B0008 */ stfs        f1, 8(r27)
  lbl_805365b0:
  /* 805365B0 39610030 */ addi        r11, r1, 0x30
  /* 805365B4 4BAEB02D */ bl          _restgpr_24
  /* 805365B8 80010034 */ lwz         r0, 0x34(r1)
  /* 805365BC 7C0803A6 */ mtlr        r0
  /* 805365C0 38210030 */ addi        r1, r1, 0x30
  /* 805365C4 4E800020 */ blr // clang-format on
}

// Symbol: unk_805365c8
// PAL: 0x805365c8..0x80536828
MARK_BINARY_BLOB(unk_805365c8, 0x805365c8, 0x80536828);
asm UNKNOWN_FUNCTION(unk_805365c8) {
  // clang-format off
  nofralloc
  /* 805365C8 9421FFE0 */ stwu        r1, -0x20(r1)
  /* 805365CC 7C0802A6 */ mflr        r0
  /* 805365D0 3CA0809C */ lis         r5, spInstance__Q26System10RaceConfig@ha
  /* 805365D4 90010024 */ stw         r0, 0x24(r1)
  /* 805365D8 93E1001C */ stw         r31, 0x1c(r1)
  /* 805365DC 3BE00000 */ li          r31, 0x0
  /* 805365E0 93C10018 */ stw         r30, 0x18(r1)
  /* 805365E4 7C9E2378 */ mr          r30, r4
  /* 805365E8 93A10014 */ stw         r29, 0x14(r1)
  /* 805365EC 93810010 */ stw         r28, 0x10(r1)
  /* 805365F0 80C5D728 */ lwz         r6, spInstance__Q26System10RaceConfig@l(r5)
  /* 805365F4 80060B70 */ lwz         r0, 0xb70(r6)
  /* 805365F8 2800000C */ cmplwi      r0, 0xc
  /* 805365FC 418101F8 */ bgt-        lbl_805367f4
  /* 80536600 3CA0808B */ lis         r5, jtbl_808b331c@ha
  /* 80536604 5400103A */ slwi        r0, r0, 2
  /* 80536608 38A5331C */ addi        r5, r5, jtbl_808b331c@l
  /* 8053660C 7CA5002E */ lwzx        r5, r5, r0
  /* 80536610 7CA903A6 */ mtctr       r5
  /* 80536614 4E800420 */ bctr
  lbl_80536618:
  entry jump_80536618
  /* 80536618 3CA0809C */ lis         r5, spInstance__Q26System9CourseMap@ha
  /* 8053661C 80A5D6E8 */ lwz         r5, spInstance__Q26System9CourseMap@l(r5)
  /* 80536620 80A50008 */ lwz         r5, 8(r5)
  /* 80536624 2C050000 */ cmpwi       r5, 0x0
  /* 80536628 4182000C */ beq-        lbl_80536634
  /* 8053662C A0050004 */ lhz         r0, 4(r5)
  /* 80536630 48000008 */ b           lbl_80536638
  lbl_80536634:
  /* 80536634 38000000 */ li          r0, 0x0
  lbl_80536638:
  /* 80536638 28000001 */ cmplwi      r0, 1
  /* 8053663C 4181000C */ bgt-        lbl_80536648
  /* 80536640 3BE00000 */ li          r31, 0x0
  /* 80536644 480001B4 */ b           lbl_805367f8
  lbl_80536648:
  /* 80536648 3CA0809C */ lis         r5, spInstance__Q26System10RaceConfig@ha
  /* 8053664C 3BE00000 */ li          r31, 0x0
  /* 80536650 80A5D728 */ lwz         r5, spInstance__Q26System10RaceConfig@l(r5)
  /* 80536654 1C0400F0 */ mulli       r0, r4, 0xf0
  /* 80536658 38E00000 */ li          r7, 0x0
  /* 8053665C 39050028 */ addi        r8, r5, 0x28
  /* 80536660 7CA80214 */ add         r5, r8, r0
  /* 80536664 38C00000 */ li          r6, 0x0
  /* 80536668 80A500CC */ lwz         r5, 0xcc(r5)
  /* 8053666C 7C8903A6 */ mtctr       r4
  /* 80536670 28040000 */ cmplwi      r4, 0
  /* 80536674 4081002C */ ble-        lbl_805366a0
  lbl_80536678:
  /* 80536678 54C0063E */ clrlwi      r0, r6, 0x18
  /* 8053667C 1C0000F0 */ mulli       r0, r0, 0xf0
  /* 80536680 7C880214 */ add         r4, r8, r0
  /* 80536684 800400CC */ lwz         r0, 0xcc(r4)
  /* 80536688 7C050000 */ cmpw        r5, r0
  /* 8053668C 4082000C */ bne-        lbl_80536698
  /* 80536690 38070001 */ addi        r0, r7, 0x1
  /* 80536694 5407063E */ clrlwi      r7, r0, 0x18
  lbl_80536698:
  /* 80536698 38C60001 */ addi        r6, r6, 0x1
  /* 8053669C 4200FFDC */ bdnz        lbl_80536678
  lbl_805366a0:
  /* 805366A0 2C050001 */ cmpwi       r5, 0x1
  /* 805366A4 38A00000 */ li          r5, 0x0
  /* 805366A8 40820008 */ bne-        lbl_805366b0
  /* 805366AC 38A00006 */ li          r5, 0x6
  lbl_805366b0:
  /* 805366B0 88830024 */ lbz         r4, 0x24(r3)
  /* 805366B4 3C602AAB */ lis         r3, 0x2aab
  /* 805366B8 3803AAAB */ addi        r0, r3, -0x5555
  /* 805366BC 3BC00000 */ li          r30, 0x0
  /* 805366C0 7C843A14 */ add         r4, r4, r7
  /* 805366C4 3FA0809C */ lis         r29, spInstance__Q26System9CourseMap@ha
  /* 805366C8 7C602096 */ mulhw       r3, r0, r4
  /* 805366CC 54600FFE */ srwi        r0, r3, 0x1f
  /* 805366D0 7C030214 */ add         r0, r3, r0
  /* 805366D4 1C000006 */ mulli       r0, r0, 0x6
  /* 805366D8 7C002050 */ subf        r0, r0, r4
  /* 805366DC 7C050214 */ add         r0, r5, r0
  /* 805366E0 541C063E */ clrlwi      r28, r0, 0x18
  /* 805366E4 48000028 */ b           lbl_8053670c
  lbl_805366e8:
  /* 805366E8 57C4063E */ clrlwi      r4, r30, 0x18
  /* 805366EC 4BFDE445 */ bl          getStartPoint__Q26System9CourseMapCFUs
  /* 805366F0 80630000 */ lwz         r3, 0(r3)
  /* 805366F4 A8030018 */ lha         r0, 0x18(r3)
  /* 805366F8 7C1C0000 */ cmpw        r28, r0
  /* 805366FC 4082000C */ bne-        lbl_80536708
  /* 80536700 7FDFF378 */ mr          r31, r30
  /* 80536704 480000F4 */ b           lbl_805367f8
  lbl_80536708:
  /* 80536708 3BDE0001 */ addi        r30, r30, 0x1
  lbl_8053670c:
  /* 8053670C 807DD6E8 */ lwz         r3, spInstance__Q26System9CourseMap@l(r29)
  /* 80536710 57C5063E */ clrlwi      r5, r30, 0x18
  /* 80536714 80830008 */ lwz         r4, 8(r3)
  /* 80536718 2C040000 */ cmpwi       r4, 0x0
  /* 8053671C 4082000C */ bne-        lbl_80536728
  /* 80536720 38000000 */ li          r0, 0x0
  /* 80536724 48000008 */ b           lbl_8053672c
  lbl_80536728:
  /* 80536728 A0040004 */ lhz         r0, 4(r4)
  lbl_8053672c:
  /* 8053672C 7C050000 */ cmpw        r5, r0
  /* 80536730 4180FFB8 */ blt+        lbl_805366e8
  /* 80536734 480000C4 */ b           lbl_805367f8
  lbl_80536738:
  entry jump_80536738
  /* 80536738 3FA0809C */ lis         r29, spInstance__Q26System9CourseMap@ha
  /* 8053673C 38800000 */ li          r4, 0x0
  /* 80536740 807DD6E8 */ lwz         r3, spInstance__Q26System9CourseMap@l(r29)
  /* 80536744 4BFDE3ED */ bl          getStartPoint__Q26System9CourseMapCFUs
  /* 80536748 80630000 */ lwz         r3, 0(r3)
  /* 8053674C A8030018 */ lha         r0, 0x18(r3)
  /* 80536750 2C00FFFF */ cmpwi       r0, -0x1
  /* 80536754 4082000C */ bne-        lbl_80536760
  /* 80536758 3BE00000 */ li          r31, 0x0
  /* 8053675C 4800009C */ b           lbl_805367f8
  lbl_80536760:
  /* 80536760 3B800000 */ li          r28, 0x0
  /* 80536764 48000028 */ b           lbl_8053678c
  lbl_80536768:
  /* 80536768 5784063E */ clrlwi      r4, r28, 0x18
  /* 8053676C 4BFDE3C5 */ bl          getStartPoint__Q26System9CourseMapCFUs
  /* 80536770 80630000 */ lwz         r3, 0(r3)
  /* 80536774 A8030018 */ lha         r0, 0x18(r3)
  /* 80536778 7C1E0000 */ cmpw        r30, r0
  /* 8053677C 4082000C */ bne-        lbl_80536788
  /* 80536780 7F9FE378 */ mr          r31, r28
  /* 80536784 48000074 */ b           lbl_805367f8
  lbl_80536788:
  /* 80536788 3B9C0001 */ addi        r28, r28, 0x1
  lbl_8053678c:
  /* 8053678C 807DD6E8 */ lwz         r3, spInstance__Q26System9CourseMap@l(r29)
  /* 80536790 5785063E */ clrlwi      r5, r28, 0x18
  /* 80536794 80830008 */ lwz         r4, 8(r3)
  /* 80536798 2C040000 */ cmpwi       r4, 0x0
  /* 8053679C 4082000C */ bne-        lbl_805367a8
  /* 805367A0 38000000 */ li          r0, 0x0
  /* 805367A4 48000008 */ b           lbl_805367ac
  lbl_805367a8:
  /* 805367A8 A0040004 */ lhz         r0, 4(r4)
  lbl_805367ac:
  /* 805367AC 7C050000 */ cmpw        r5, r0
  /* 805367B0 4180FFB8 */ blt+        lbl_80536768
  /* 805367B4 48000044 */ b           lbl_805367f8
  lbl_805367b8:
  entry jump_805367b8
  /* 805367B8 80060B74 */ lwz         r0, 0xb74(r6)
  /* 805367BC 38600003 */ li          r3, 0x3
  /* 805367C0 2C00000C */ cmpwi       r0, 0xc
  /* 805367C4 40820008 */ bne-        lbl_805367cc
  /* 805367C8 38600006 */ li          r3, 0x6
  lbl_805367cc:
  /* 805367CC 7C041800 */ cmpw        r4, r3
  /* 805367D0 4080000C */ bge-        lbl_805367dc
  /* 805367D4 7FDFF378 */ mr          r31, r30
  /* 805367D8 48000020 */ b           lbl_805367f8
  lbl_805367dc:
  /* 805367DC 3BE00000 */ li          r31, 0x0
  /* 805367E0 48000018 */ b           lbl_805367f8
  lbl_805367e4:
  entry jump_805367e4
  /* 805367E4 7FDFF378 */ mr          r31, r30
  /* 805367E8 48000010 */ b           lbl_805367f8
  lbl_805367ec:
  entry jump_805367ec
  /* 805367EC 3BE00000 */ li          r31, 0x0
  /* 805367F0 48000008 */ b           lbl_805367f8
  lbl_805367f4:
  entry jump_805367f4
  /* 805367F4 3BE00000 */ li          r31, 0x0
  lbl_805367f8:
  /* 805367F8 3C60809C */ lis         r3, spInstance__Q26System9CourseMap@ha
  /* 805367FC 57E4063E */ clrlwi      r4, r31, 0x18
  /* 80536800 8063D6E8 */ lwz         r3, spInstance__Q26System9CourseMap@l(r3)
  /* 80536804 4BFDE32D */ bl          getStartPoint__Q26System9CourseMapCFUs
  /* 80536808 80010024 */ lwz         r0, 0x24(r1)
  /* 8053680C 83E1001C */ lwz         r31, 0x1c(r1)
  /* 80536810 83C10018 */ lwz         r30, 0x18(r1)
  /* 80536814 83A10014 */ lwz         r29, 0x14(r1)
  /* 80536818 83810010 */ lwz         r28, 0x10(r1)
  /* 8053681C 7C0803A6 */ mtlr        r0
  /* 80536820 38210020 */ addi        r1, r1, 0x20
  /* 80536824 4E800020 */ blr // clang-format on
}

// Symbol: unk_80536828
// PAL: 0x80536828..0x805368c4
MARK_BINARY_BLOB(unk_80536828, 0x80536828, 0x805368c4);
asm UNKNOWN_FUNCTION(unk_80536828) {
  // clang-format off
  nofralloc
  /* 80536828 9421FFF0 */ stwu        r1, -0x10(r1)
  /* 8053682C 7C0802A6 */ mflr        r0
  /* 80536830 3CA0809C */ lis         r5, spInstance__Q26System10RaceConfig@ha
  /* 80536834 38C00000 */ li          r6, 0x0
  /* 80536838 90010014 */ stw         r0, 0x14(r1)
  /* 8053683C 80A5D728 */ lwz         r5, spInstance__Q26System10RaceConfig@l(r5)
  /* 80536840 80050B70 */ lwz         r0, 0xb70(r5)
  /* 80536844 2C000009 */ cmpwi       r0, 0x9
  /* 80536848 4180000C */ blt-        lbl_80536854
  /* 8053684C 2C00000A */ cmpwi       r0, 0xa
  /* 80536850 40810028 */ ble-        lbl_80536878
  lbl_80536854:
  /* 80536854 2C000003 */ cmpwi       r0, 0x3
  /* 80536858 41820020 */ beq-        lbl_80536878
  /* 8053685C 2C00000B */ cmpwi       r0, 0xb
  /* 80536860 41820024 */ beq-        lbl_80536884
  /* 80536864 2C000004 */ cmpwi       r0, 0x4
  /* 80536868 41820028 */ beq-        lbl_80536890
  /* 8053686C 2C00000C */ cmpwi       r0, 0xc
  /* 80536870 4182002C */ beq-        lbl_8053689c
  /* 80536874 4800003C */ b           lbl_805368b0
  lbl_80536878:
  /* 80536878 4BFFFD51 */ bl          unk_805365c8
  /* 8053687C 88C30004 */ lbz         r6, 4(r3)
  /* 80536880 48000030 */ b           lbl_805368b0
  lbl_80536884:
  /* 80536884 4BFFFD45 */ bl          unk_805365c8
  /* 80536888 88C30004 */ lbz         r6, 4(r3)
  /* 8053688C 48000024 */ b           lbl_805368b0
  lbl_80536890:
  /* 80536890 4BFFFD39 */ bl          unk_805365c8
  /* 80536894 88C30004 */ lbz         r6, 4(r3)
  /* 80536898 48000018 */ b           lbl_805368b0
  lbl_8053689c:
  /* 8053689C 3C60809C */ lis         r3, spInstance__Q26System9CourseMap@ha
  /* 805368A0 8063D6E8 */ lwz         r3, spInstance__Q26System9CourseMap@l(r3)
  /* 805368A4 4BFDE325 */ bl          getEnemyPath__Q26System9CourseMapCFUs
  /* 805368A8 80630000 */ lwz         r3, 0(r3)
  /* 805368AC 88C30000 */ lbz         r6, 0(r3)
  lbl_805368b0:
  /* 805368B0 80010014 */ lwz         r0, 0x14(r1)
  /* 805368B4 7CC33378 */ mr          r3, r6
  /* 805368B8 7C0803A6 */ mtlr        r0
  /* 805368BC 38210010 */ addi        r1, r1, 0x10
  /* 805368C0 4E800020 */ blr // clang-format on
}

namespace System {
KrtFile** RaceManager::getKrtFile() {
    KrtFile** files;

    if (RaceConfig::spInstance->mRaceScenario.mSettings.mGameMode != RaceConfig::Settings::GAMEMODE_GRAND_PRIX) {
        return nullptr;
    }
    else {
        RaceModeGrandPrix* raceModeGP = (RaceModeGrandPrix*) raceMode;
        files = raceModeGP->krtFile;
        return (files[0] != nullptr) ? files : nullptr;
    }
}
}

#ifdef WIP_DECOMP
namespace System {
void RaceManagerPlayer::updateGpRankScore() {
    s32 raceStarRankScore = 0;
    s32 krtTime = 0;
    KrtFile** krtFile = nullptr;
    
    // Get ranktimeGP.krt
    krtFile = RaceManager::spInstance->getKrtFile();

    if ((krtFile == nullptr) || (RaceConfig::spInstance->mRaceScenario.getPlayer(m_idx).getPlayerType() != RaceConfig::Player::TYPE_REAL_LOCAL)) {
        unk34 = 7;
    }
    else {
        // Get course time limit from ranktimeGP
        s32 engineClass = RaceConfig::spInstance->mRaceScenario.mSettings.getEngineClass();
        s32 courseId = RaceConfig::spInstance->mRaceScenario.mSettings.getCourseId();
        krtTime = (*krtFile != nullptr) ? (*krtFile)->entries[courseId][RaceConfig::spInstance->mRaceScenario.mSettings.getEngineClass()] : 0;

        // Calculate time bonus
        // s32 raceStarRankScore = 0;
         raceStarRankScore += 1000.0f * (krtTime - m_frameCounter) / krtTime;
        // Calculate time bonus corresponding to the time spent in 1st place
        s32 firstPlaceTimeBonus = m_framesInFirstPlace * 150 / krtTime;
        // Add time bonus
        raceStarRankScore += firstPlaceTimeBonus;

        // Add bonus for successfull rocket start
        if (Kart::KartObjectManager::spInstance->getObject(m_idx)->mAccessor->settings->gpStats->startBoostSuccessful) {
            raceStarRankScore += 25;
        }
        
        u16 miniturbos = Kart::KartObjectManager::spInstance->getObject(m_idx)->mAccessor->settings->gpStats->miniturbos;
        raceStarRankScore += (miniturbos * 2);
        
        u16 hitOthersWithItemsCount = Kart::KartObjectManager::spInstance->getObject(m_idx)->mAccessor->settings->raceStats->hitOthersWithItemsCount;
        raceStarRankScore += (hitOthersWithItemsCount * 5);
        
        // u32 offroad = Kart::KartObjectManager::spInstance->getObject(m_idx)->mAccessor->settings->gpStats->offroad;
        raceStarRankScore -= (Kart::KartObjectManager::spInstance->getObject(m_idx)->mAccessor->settings->gpStats->offroad / 3);
        
        u16 numWallCollision = Kart::KartObjectManager::spInstance->getObject(m_idx)->mAccessor->settings->gpStats->numWallCollision;
        raceStarRankScore -= (numWallCollision * 20);
        
        u16 numObjectCollision = Kart::KartObjectManager::spInstance->getObject(m_idx)->mAccessor->settings->gpStats->numObjectCollision;
        raceStarRankScore -= (numObjectCollision * 30);
        
        u16 outOfBounds = Kart::KartObjectManager::spInstance->getObject(m_idx)->mAccessor->settings->gpStats->outOfBounds;
        raceStarRankScore -= (outOfBounds * 70);

        s8 playerInputIdx = RaceConfig::spInstance->mRaceScenario.getPlayer(m_idx).getPlayerInputIdx();
        
        // Add bonus for playing using the Wii Wheel
        if (playerInputIdx != -1) {
            Controller* controller = InputManager::spInstance->playerInputs[(u8) playerInputIdx].raceController;

            u32 controllerType = (controller != nullptr) ? controller->getType() : CONTROLLER_TYPE_UNKNOWN;
            if (controllerType == CONTROLLER_TYPE_WII_WHEEL) {
                raceStarRankScore += 10;
            }
        }

        // Add bonus for using Automatic drift
        if (playerInputIdx != -1) {
            Controller* controller = InputManager::spInstance->playerInputs[(u8) playerInputIdx].raceController;

            bool usingAutomaticDrift = (controller != nullptr) ? controller->driftIsAuto : false;
            if (usingAutomaticDrift) {
                raceStarRankScore += 25;
            }
        }

        // Add unknown bonus
        u16 field_0x18 = Kart::KartObjectManager::spInstance->getObject(m_idx)->mAccessor->settings->gpStats->field_0x18;
        raceStarRankScore += field_0x18;

        // Clamp the start rank score
        if (raceStarRankScore < -50) {
            raceStarRankScore = -50;
        }
        if (raceStarRankScore > 250) {
            raceStarRankScore = 250;
        }

        // Save the new star rank score
        RaceConfig::spInstance->mMenuScenario.getPlayer(m_idx).mGpStarRankScore += (s16) raceStarRankScore;
    }
}
}
#else
// Symbol: RaceinfoPlayer_updateGpRankScore
// PAL: 0x805368f8..0x80536c84
MARK_BINARY_BLOB(RaceinfoPlayer_updateGpRankScore, 0x805368f8, 0x80536c84);
asm UNKNOWN_FUNCTION(RaceinfoPlayer_updateGpRankScore) {
  // clang-format off
  nofralloc
  /* 805368F8 9421FFC0 */ stwu        r1, -0x40(r1)
  /* 805368FC 7C0802A6 */ mflr        r0
  /* 80536900 3C80809C */ lis         r4, spInstance__Q26System10RaceConfig@ha
  /* 80536904 3CA0809C */ lis         r5, spInstance__Q26System11RaceManager@ha
  /* 80536908 90010044 */ stw         r0, 0x44(r1)
  /* 8053690C 93E1003C */ stw         r31, 0x3c(r1)
  /* 80536910 93C10038 */ stw         r30, 0x38(r1)
  /* 80536914 3BC00000 */ li          r30, 0x0
  /* 80536918 93A10034 */ stw         r29, 0x34(r1)
  /* 8053691C 7C7D1B78 */ mr          r29, r3
  /* 80536920 80E4D728 */ lwz         r7, spInstance__Q26System10RaceConfig@l(r4)
  /* 80536924 8085D730 */ lwz         r4, spInstance__Q26System11RaceManager@l(r5)
  /* 80536928 80070B70 */ lwz         r0, 0xb70(r7)
  /* 8053692C 2C000000 */ cmpwi       r0, 0x0
  /* 80536930 4182000C */ beq-        lbl_8053693c
  /* 80536934 38C00000 */ li          r6, 0x0
  /* 80536938 48000020 */ b           lbl_80536958
  lbl_8053693c:
  /* 8053693C 80840010 */ lwz         r4, 0x10(r4)
  /* 80536940 80040008 */ lwz         r0, 8(r4)
  /* 80536944 38C40008 */ addi        r6, r4, 0x8
  /* 80536948 2C000000 */ cmpwi       r0, 0x0
  /* 8053694C 41820008 */ beq-        lbl_80536954
  /* 80536950 48000008 */ b           lbl_80536958
  lbl_80536954:
  /* 80536954 38C00000 */ li          r6, 0x0
  lbl_80536958:
  /* 80536958 2C060000 */ cmpwi       r6, 0x0
  /* 8053695C 4182001C */ beq-        lbl_80536978
  /* 80536960 88830008 */ lbz         r4, 8(r3)
  /* 80536964 1C0400F0 */ mulli       r0, r4, 0xf0
  /* 80536968 7CA70214 */ add         r5, r7, r0
  /* 8053696C 80050038 */ lwz         r0, 0x38(r5)
  /* 80536970 2C000000 */ cmpwi       r0, 0x0
  /* 80536974 41820010 */ beq-        lbl_80536984
  lbl_80536978:
  /* 80536978 38000007 */ li          r0, 0x7
  /* 8053697C 90030034 */ stw         r0, 0x34(r3)
  /* 80536980 480002E8 */ b           lbl_80536c68
  lbl_80536984:
  /* 80536984 80E60000 */ lwz         r7, 0(r6)
  /* 80536988 3CA0809C */ lis         r5, spInstance__Q26System10RaceConfig@ha
  /* 8053698C 80A5D728 */ lwz         r5, spInstance__Q26System10RaceConfig@l(r5)
  /* 80536990 2C070000 */ cmpwi       r7, 0x0
  /* 80536994 80C50B6C */ lwz         r6, 0xb6c(r5)
  /* 80536998 80050B68 */ lwz         r0, 0xb68(r5)
  /* 8053699C 4182001C */ beq-        lbl_805369b8
  /* 805369A0 54051838 */ slwi        r5, r0, 3
  /* 805369A4 54C0083C */ slwi        r0, r6, 1
  /* 805369A8 7CA72A14 */ add         r5, r7, r5
  /* 805369AC 7CA50214 */ add         r5, r5, r0
  /* 805369B0 A145000C */ lhz         r10, 0xc(r5)
  /* 805369B4 48000008 */ b           lbl_805369bc
  lbl_805369b8:
  /* 805369B8 39400000 */ li          r10, 0x0
  lbl_805369bc:
  /* 805369BC 8003002C */ lwz         r0, 0x2c(r3)
  /* 805369C0 3CE04330 */ lis         r7, 0x4330
  /* 805369C4 3D208089 */ lis         r9, lbl_808901a0@ha
  /* 805369C8 6D458000 */ xoris       r5, r10, 0x8000
  /* 805369CC 7C005050 */ subf        r0, r0, r10
  /* 805369D0 3CC08089 */ lis         r6, lbl_808901b8@ha
  /* 805369D4 6C008000 */ xoris       r0, r0, 0x8000
  /* 805369D8 90010014 */ stw         r0, 0x14(r1)
  /* 805369DC 80030030 */ lwz         r0, 0x30(r3)
  /* 805369E0 6FC88000 */ xoris       r8, r30, 0x8000
  /* 805369E4 90E10010 */ stw         r7, 0x10(r1)
  /* 805369E8 3C60809C */ lis         r3, lbl_809c18f8@ha
  /* 805369EC C86901A0 */ lfd         f3, lbl_808901a0@l(r9)
  /* 805369F0 1C000096 */ mulli       r0, r0, 0x96
  /* 805369F4 C8010010 */ lfd         f0, 0x10(r1)
  /* 805369F8 90A1001C */ stw         r5, 0x1c(r1)
  /* 805369FC EC401828 */ fsubs       f2, f0, f3
  /* 80536A00 C02601B8 */ lfs         f1, lbl_808901b8@l(r6)
  /* 80536A04 90E10018 */ stw         r7, 0x18(r1)
  /* 80536A08 7C005396 */ divwu       r0, r0, r10
  /* 80536A0C 806318F8 */ lwz         r3, lbl_809c18f8@l(r3)
  /* 80536A10 C8010018 */ lfd         f0, 0x18(r1)
  /* 80536A14 EC2100B2 */ fmuls       f1, f1, f2
  /* 80536A18 9101000C */ stw         r8, 0xc(r1)
  /* 80536A1C EC001828 */ fsubs       f0, f0, f3
  /* 80536A20 EC010024 */ fdivs       f0, f1, f0
  /* 80536A24 90E10008 */ stw         r7, 8(r1)
  /* 80536A28 C8210008 */ lfd         f1, 8(r1)
  /* 80536A2C EC211828 */ fsubs       f1, f1, f3
  /* 80536A30 EC01002A */ fadds       f0, f1, f0
  /* 80536A34 FC00001E */ fctiwz      f0, f0
  /* 80536A38 D8010020 */ stfd        f0, 0x20(r1)
  /* 80536A3C 83C10024 */ lwz         r30, 0x24(r1)
  /* 80536A40 7FDE0214 */ add         r30, r30, r0
  /* 80536A44 480596BD */ bl          PlayerHolder_getPlayer
  /* 80536A48 80630000 */ lwz         r3, 0(r3)
  /* 80536A4C 80630000 */ lwz         r3, 0(r3)
  /* 80536A50 80630034 */ lwz         r3, 0x34(r3)
  /* 80536A54 88030000 */ lbz         r0, 0(r3)
  /* 80536A58 2C000000 */ cmpwi       r0, 0x0
  /* 80536A5C 41820008 */ beq-        lbl_80536a64
  /* 80536A60 3BDE0019 */ addi        r30, r30, 0x19
  lbl_80536a64:
  /* 80536A64 3FE0809C */ lis         r31, lbl_809c18f8@ha
  /* 80536A68 889D0008 */ lbz         r4, 8(r29)
  /* 80536A6C 807F18F8 */ lwz         r3, lbl_809c18f8@l(r31)
  /* 80536A70 48059691 */ bl          PlayerHolder_getPlayer
  /* 80536A74 80830000 */ lwz         r4, 0(r3)
  /* 80536A78 807F18F8 */ lwz         r3, lbl_809c18f8@l(r31)
  /* 80536A7C 80A40000 */ lwz         r5, 0(r4)
  /* 80536A80 889D0008 */ lbz         r4, 8(r29)
  /* 80536A84 80A50034 */ lwz         r5, 0x34(r5)
  /* 80536A88 80050004 */ lwz         r0, 4(r5)
  /* 80536A8C 54000BFC */ rlwinm      r0, r0, 1, 0xf, 0x1e
  /* 80536A90 7FDE0214 */ add         r30, r30, r0
  /* 80536A94 4805966D */ bl          PlayerHolder_getPlayer
  /* 80536A98 80830000 */ lwz         r4, 0(r3)
  /* 80536A9C 807F18F8 */ lwz         r3, lbl_809c18f8@l(r31)
  /* 80536AA0 80A40000 */ lwz         r5, 0(r4)
  /* 80536AA4 889D0008 */ lbz         r4, 8(r29)
  /* 80536AA8 80A50038 */ lwz         r5, 0x38(r5)
  /* 80536AAC 80050008 */ lwz         r0, 8(r5)
  /* 80536AB0 5405043E */ clrlwi      r5, r0, 0x10
  /* 80536AB4 540013BA */ rlwinm      r0, r0, 2, 0xe, 0x1d
  /* 80536AB8 7C002A14 */ add         r0, r0, r5
  /* 80536ABC 7FDE0214 */ add         r30, r30, r0
  /* 80536AC0 48059641 */ bl          PlayerHolder_getPlayer
  /* 80536AC4 80830000 */ lwz         r4, 0(r3)
  /* 80536AC8 3C60AAAB */ lis         r3, 0xaaab
  /* 80536ACC 38C3AAAB */ addi        r6, r3, -0x5555
  /* 80536AD0 807F18F8 */ lwz         r3, lbl_809c18f8@l(r31)
  /* 80536AD4 80A40000 */ lwz         r5, 0(r4)
  /* 80536AD8 889D0008 */ lbz         r4, 8(r29)
  /* 80536ADC 80A50034 */ lwz         r5, 0x34(r5)
  /* 80536AE0 80050008 */ lwz         r0, 8(r5)
  /* 80536AE4 7C060016 */ mulhwu      r0, r6, r0
  /* 80536AE8 5400F87E */ srwi        r0, r0, 1
  /* 80536AEC 7FC0F050 */ subf        r30, r0, r30
  /* 80536AF0 48059611 */ bl          PlayerHolder_getPlayer
  /* 80536AF4 80830000 */ lwz         r4, 0(r3)
  /* 80536AF8 807F18F8 */ lwz         r3, lbl_809c18f8@l(r31)
  /* 80536AFC 80A40000 */ lwz         r5, 0(r4)
  /* 80536B00 889D0008 */ lbz         r4, 8(r29)
  /* 80536B04 80A50034 */ lwz         r5, 0x34(r5)
  /* 80536B08 8005000C */ lwz         r0, 0xc(r5)
  /* 80536B0C 5400043E */ clrlwi      r0, r0, 0x10
  /* 80536B10 1C000014 */ mulli       r0, r0, 0x14
  /* 80536B14 7FC0F050 */ subf        r30, r0, r30
  /* 80536B18 480595E9 */ bl          PlayerHolder_getPlayer
  /* 80536B1C 80830000 */ lwz         r4, 0(r3)
  /* 80536B20 807F18F8 */ lwz         r3, lbl_809c18f8@l(r31)
  /* 80536B24 80A40000 */ lwz         r5, 0(r4)
  /* 80536B28 889D0008 */ lbz         r4, 8(r29)
  /* 80536B2C 80A50034 */ lwz         r5, 0x34(r5)
  /* 80536B30 80050010 */ lwz         r0, 0x10(r5)
  /* 80536B34 5400043E */ clrlwi      r0, r0, 0x10
  /* 80536B38 1C00001E */ mulli       r0, r0, 0x1e
  /* 80536B3C 7FC0F050 */ subf        r30, r0, r30
  /* 80536B40 480595C1 */ bl          PlayerHolder_getPlayer
  /* 80536B44 80830000 */ lwz         r4, 0(r3)
  /* 80536B48 3C60809C */ lis         r3, spInstance__Q26System10RaceConfig@ha
  /* 80536B4C 881D0008 */ lbz         r0, 8(r29)
  /* 80536B50 80840000 */ lwz         r4, 0(r4)
  /* 80536B54 1C0000F0 */ mulli       r0, r0, 0xf0
  /* 80536B58 8063D728 */ lwz         r3, spInstance__Q26System10RaceConfig@l(r3)
  /* 80536B5C 80840034 */ lwz         r4, 0x34(r4)
  /* 80536B60 7C630214 */ add         r3, r3, r0
  /* 80536B64 80840014 */ lwz         r4, 0x14(r4)
  /* 80536B68 8803002E */ lbz         r0, 0x2e(r3)
  /* 80536B6C 5483043E */ clrlwi      r3, r4, 0x10
  /* 80536B70 1C630046 */ mulli       r3, r3, 0x46
  /* 80536B74 7C1F0774 */ extsb       r31, r0
  /* 80536B78 2C1FFFFF */ cmpwi       r31, -0x1
  /* 80536B7C 7FC3F050 */ subf        r30, r3, r30
  /* 80536B80 41820048 */ beq-        lbl_80536bc8
  /* 80536B84 57E0063E */ clrlwi      r0, r31, 0x18
  /* 80536B88 3C60809C */ lis         r3, spInstance__Q26System12KPadDirector@ha
  /* 80536B8C 1C0000EC */ mulli       r0, r0, 0xec
  /* 80536B90 8063D70C */ lwz         r3, spInstance__Q26System12KPadDirector@l(r3)
  /* 80536B94 7C630214 */ add         r3, r3, r0
  /* 80536B98 80630008 */ lwz         r3, 8(r3)
  /* 80536B9C 2C030000 */ cmpwi       r3, 0x0
  /* 80536BA0 41820018 */ beq-        lbl_80536bb8
  /* 80536BA4 81830000 */ lwz         r12, 0(r3)
  /* 80536BA8 818C0010 */ lwz         r12, 0x10(r12)
  /* 80536BAC 7D8903A6 */ mtctr       r12
  /* 80536BB0 4E800421 */ bctrl
  /* 80536BB4 48000008 */ b           lbl_80536bbc
  lbl_80536bb8:
  /* 80536BB8 3860FFFF */ li          r3, -0x1
  lbl_80536bbc:
  /* 80536BBC 2C030000 */ cmpwi       r3, 0x0
  /* 80536BC0 40820008 */ bne-        lbl_80536bc8
  /* 80536BC4 3BDE000A */ addi        r30, r30, 0xa
  lbl_80536bc8:
  /* 80536BC8 2C1FFFFF */ cmpwi       r31, -0x1
  /* 80536BCC 4182003C */ beq-        lbl_80536c08
  /* 80536BD0 57E0063E */ clrlwi      r0, r31, 0x18
  /* 80536BD4 3C60809C */ lis         r3, spInstance__Q26System12KPadDirector@ha
  /* 80536BD8 1C0000EC */ mulli       r0, r0, 0xec
  /* 80536BDC 8063D70C */ lwz         r3, spInstance__Q26System12KPadDirector@l(r3)
  /* 80536BE0 7C630214 */ add         r3, r3, r0
  /* 80536BE4 80630008 */ lwz         r3, 8(r3)
  /* 80536BE8 2C030000 */ cmpwi       r3, 0x0
  /* 80536BEC 4182000C */ beq-        lbl_80536bf8
  /* 80536BF0 88030051 */ lbz         r0, 0x51(r3)
  /* 80536BF4 48000008 */ b           lbl_80536bfc
  lbl_80536bf8:
  /* 80536BF8 38000000 */ li          r0, 0x0
  lbl_80536bfc:
  /* 80536BFC 2C000000 */ cmpwi       r0, 0x0
  /* 80536C00 41820008 */ beq-        lbl_80536c08
  /* 80536C04 3BDE0019 */ addi        r30, r30, 0x19
  lbl_80536c08:
  /* 80536C08 3C60809C */ lis         r3, lbl_809c18f8@ha
  /* 80536C0C 889D0008 */ lbz         r4, 8(r29)
  /* 80536C10 806318F8 */ lwz         r3, lbl_809c18f8@l(r3)
  /* 80536C14 480594ED */ bl          PlayerHolder_getPlayer
  /* 80536C18 80630000 */ lwz         r3, 0(r3)
  /* 80536C1C 80630000 */ lwz         r3, 0(r3)
  /* 80536C20 80630034 */ lwz         r3, 0x34(r3)
  /* 80536C24 A0030018 */ lhz         r0, 0x18(r3)
  /* 80536C28 7FDE0214 */ add         r30, r30, r0
  /* 80536C2C 2C1EFFCE */ cmpwi       r30, -0x32
  /* 80536C30 40800008 */ bge-        lbl_80536c38
  /* 80536C34 3BC0FFCE */ li          r30, -0x32
  lbl_80536c38:
  /* 80536C38 2C1E00FA */ cmpwi       r30, 0xfa
  /* 80536C3C 40810008 */ ble-        lbl_80536c44
  /* 80536C40 3BC000FA */ li          r30, 0xfa
  lbl_80536c44:
  /* 80536C44 887D0008 */ lbz         r3, 8(r29)
  /* 80536C48 3C80809C */ lis         r4, spInstance__Q26System10RaceConfig@ha
  /* 80536C4C 8084D728 */ lwz         r4, spInstance__Q26System10RaceConfig@l(r4)
  /* 80536C50 7FC00734 */ extsh       r0, r30
  /* 80536C54 1C6300F0 */ mulli       r3, r3, 0xf0
  /* 80536C58 7C841A14 */ add         r4, r4, r3
  /* 80536C5C A8640CF6 */ lha         r3, 0xcf6(r4)
  /* 80536C60 7C030214 */ add         r0, r3, r0
  /* 80536C64 B0040CF6 */ sth         r0, 0xcf6(r4)
  lbl_80536c68:
  /* 80536C68 80010044 */ lwz         r0, 0x44(r1)
  /* 80536C6C 83E1003C */ lwz         r31, 0x3c(r1)
  /* 80536C70 83C10038 */ lwz         r30, 0x38(r1)
  /* 80536C74 83A10034 */ lwz         r29, 0x34(r1)
  /* 80536C78 7C0803A6 */ mtlr        r0
  /* 80536C7C 38210040 */ addi        r1, r1, 0x40
  /* 80536C80 4E800020 */ blr // clang-format on
}
#endif

// Symbol: unk_80536c84
// PAL: 0x80536c84..0x80537190
MARK_BINARY_BLOB(unk_80536c84, 0x80536c84, 0x80537190);
asm UNKNOWN_FUNCTION(unk_80536c84) {
  // clang-format off
  nofralloc
  /* 80536C84 9421FFB0 */ stwu        r1, -0x50(r1)
  /* 80536C88 7C0802A6 */ mflr        r0
  /* 80536C8C 90010054 */ stw         r0, 0x54(r1)
  /* 80536C90 39610050 */ addi        r11, r1, 0x50
  /* 80536C94 4BAEA90D */ bl          _savegpr_27
  /* 80536C98 88E30008 */ lbz         r7, 8(r3)
  /* 80536C9C 3CC04330 */ lis         r6, 0x4330
  /* 80536CA0 3CA0809C */ lis         r5, spInstance__Q26System10RaceConfig@ha
  /* 80536CA4 7C7B1B78 */ mr          r27, r3
  /* 80536CA8 1C0700F0 */ mulli       r0, r7, 0xf0
  /* 80536CAC 80A5D728 */ lwz         r5, spInstance__Q26System10RaceConfig@l(r5)
  /* 80536CB0 7C9C2378 */ mr          r28, r4
  /* 80536CB4 90C10020 */ stw         r6, 0x20(r1)
  /* 80536CB8 3BA00000 */ li          r29, 0x0
  /* 80536CBC 7C650214 */ add         r3, r5, r0
  /* 80536CC0 8883002E */ lbz         r4, 0x2e(r3)
  /* 80536CC4 90C10028 */ stw         r6, 0x28(r1)
  /* 80536CC8 7C800775 */ extsb.      r0, r4
  /* 80536CCC 41800018 */ blt-        lbl_80536ce4
  /* 80536CD0 3C60809C */ lis         r3, spInstance__Q26System12KPadDirector@ha
  /* 80536CD4 1C0400EC */ mulli       r0, r4, 0xec
  /* 80536CD8 8063D70C */ lwz         r3, spInstance__Q26System12KPadDirector@l(r3)
  /* 80536CDC 7C630214 */ add         r3, r3, r0
  /* 80536CE0 3BA30004 */ addi        r29, r3, 0x4
  lbl_80536ce4:
  /* 80536CE4 3C60809C */ lis         r3, lbl_809c18f8@ha
  /* 80536CE8 7CE43B78 */ mr          r4, r7
  /* 80536CEC 806318F8 */ lwz         r3, lbl_809c18f8@l(r3)
  /* 80536CF0 48059411 */ bl          PlayerHolder_getPlayer
  /* 80536CF4 80630000 */ lwz         r3, 0(r3)
  /* 80536CF8 3FC08089 */ lis         r30, lbl_808901c0@ha
  /* 80536CFC 3FE08089 */ lis         r31, lbl_808901bc@ha
  /* 80536D00 C05E01C0 */ lfs         f2, lbl_808901c0@l(r30)
  /* 80536D04 80630000 */ lwz         r3, 0(r3)
  /* 80536D08 C01F01BC */ lfs         f0, lbl_808901bc@l(r31)
  /* 80536D0C 80C30038 */ lwz         r6, 0x38(r3)
  /* 80536D10 80060000 */ lwz         r0, 0(r6)
  /* 80536D14 90010008 */ stw         r0, 8(r1)
  /* 80536D18 80A60004 */ lwz         r5, 4(r6)
  /* 80536D1C C0210008 */ lfs         f1, 8(r1)
  /* 80536D20 80860008 */ lwz         r4, 8(r6)
  /* 80536D24 EC220072 */ fmuls       f1, f2, f1
  /* 80536D28 8066000C */ lwz         r3, 0xc(r6)
  /* 80536D2C 80060010 */ lwz         r0, 0x10(r6)
  /* 80536D30 90A1000C */ stw         r5, 0xc(r1)
  /* 80536D34 EC20082A */ fadds       f1, f0, f1
  /* 80536D38 90810010 */ stw         r4, 0x10(r1)
  /* 80536D3C 90610014 */ stw         r3, 0x14(r1)
  /* 80536D40 90010018 */ stw         r0, 0x18(r1)
  /* 80536D44 4BAEA735 */ bl          __cvt_fp2unsigned
  /* 80536D48 C05E01C0 */ lfs         f2, lbl_808901c0@l(r30)
  /* 80536D4C 7C7E1B78 */ mr          r30, r3
  /* 80536D50 C021000C */ lfs         f1, 0xc(r1)
  /* 80536D54 C01F01BC */ lfs         f0, lbl_808901bc@l(r31)
  /* 80536D58 EC220072 */ fmuls       f1, f2, f1
  /* 80536D5C EC20082A */ fadds       f1, f0, f1
  /* 80536D60 4BAEA719 */ bl          __cvt_fp2unsigned
  /* 80536D64 3C80809C */ lis         r4, spInstance__Q26System10RaceConfig@ha
  /* 80536D68 7C7F1B78 */ mr          r31, r3
  /* 80536D6C 8064D728 */ lwz         r3, spInstance__Q26System10RaceConfig@l(r4)
  /* 80536D70 80030B70 */ lwz         r0, 0xb70(r3)
  /* 80536D74 2C000000 */ cmpwi       r0, 0x0
  /* 80536D78 4180000C */ blt-        lbl_80536d84
  /* 80536D7C 2C000002 */ cmpwi       r0, 0x2
  /* 80536D80 40810030 */ ble-        lbl_80536db0
  lbl_80536d84:
  /* 80536D84 2C000007 */ cmpwi       r0, 0x7
  /* 80536D88 4180000C */ blt-        lbl_80536d94
  /* 80536D8C 2C000008 */ cmpwi       r0, 0x8
  /* 80536D90 40810020 */ ble-        lbl_80536db0
  lbl_80536d94:
  /* 80536D94 2C000009 */ cmpwi       r0, 0x9
  /* 80536D98 4180000C */ blt-        lbl_80536da4
  /* 80536D9C 2C00000A */ cmpwi       r0, 0xa
  /* 80536DA0 40810168 */ ble-        lbl_80536f08
  lbl_80536da4:
  /* 80536DA4 2C000003 */ cmpwi       r0, 0x3
  /* 80536DA8 41820160 */ beq-        lbl_80536f08
  /* 80536DAC 480001FC */ b           lbl_80536fa8
  lbl_80536db0:
  /* 80536DB0 3CBC0001 */ addis       r5, r28, 1
  /* 80536DB4 3C600002 */ lis         r3, 2
  /* 80536DB8 80859294 */ lwz         r4, -0x6d6c(r5)
  /* 80536DBC 3803869F */ addi        r0, r3, -0x7961
  /* 80536DC0 7C040040 */ cmplw       r4, r0
  /* 80536DC4 4080000C */ bge-        lbl_80536dd0
  /* 80536DC8 38040001 */ addi        r0, r4, 0x1
  /* 80536DCC 90059294 */ stw         r0, -0x6d6c(r5)
  lbl_80536dd0:
  /* 80536DD0 2C1D0000 */ cmpwi       r29, 0x0
  /* 80536DD4 41820050 */ beq-        lbl_80536e24
  /* 80536DD8 807D0004 */ lwz         r3, 4(r29)
  /* 80536DDC 2C030000 */ cmpwi       r3, 0x0
  /* 80536DE0 41820018 */ beq-        lbl_80536df8
  /* 80536DE4 81830000 */ lwz         r12, 0(r3)
  /* 80536DE8 818C0010 */ lwz         r12, 0x10(r12)
  /* 80536DEC 7D8903A6 */ mtctr       r12
  /* 80536DF0 4E800421 */ bctrl
  /* 80536DF4 48000008 */ b           lbl_80536dfc
  lbl_80536df8:
  /* 80536DF8 3860FFFF */ li          r3, -0x1
  lbl_80536dfc:
  /* 80536DFC 2C030000 */ cmpwi       r3, 0x0
  /* 80536E00 40820024 */ bne-        lbl_80536e24
  /* 80536E04 3CBC0001 */ addis       r5, r28, 1
  /* 80536E08 3C600002 */ lis         r3, 2
  /* 80536E0C 8085929C */ lwz         r4, -0x6d64(r5)
  /* 80536E10 3803869F */ addi        r0, r3, -0x7961
  /* 80536E14 7C040040 */ cmplw       r4, r0
  /* 80536E18 4080000C */ bge-        lbl_80536e24
  /* 80536E1C 38040001 */ addi        r0, r4, 0x1
  /* 80536E20 9005929C */ stw         r0, -0x6d64(r5)
  lbl_80536e24:
  /* 80536E24 881B0020 */ lbz         r0, 0x20(r27)
  /* 80536E28 2C000001 */ cmpwi       r0, 0x1
  /* 80536E2C 40820024 */ bne-        lbl_80536e50
  /* 80536E30 3CBC0001 */ addis       r5, r28, 1
  /* 80536E34 3C600002 */ lis         r3, 2
  /* 80536E38 808592B8 */ lwz         r4, -0x6d48(r5)
  /* 80536E3C 3803869F */ addi        r0, r3, -0x7961
  /* 80536E40 7C040040 */ cmplw       r4, r0
  /* 80536E44 4080000C */ bge-        lbl_80536e50
  /* 80536E48 38040001 */ addi        r0, r4, 0x1
  /* 80536E4C 900592B8 */ stw         r0, -0x6d48(r5)
  lbl_80536e50:
  /* 80536E50 3C80809C */ lis         r4, spInstance__Q26System10RaceConfig@ha
  /* 80536E54 3C7C0001 */ addis       r3, r28, 1
  /* 80536E58 8084D728 */ lwz         r4, spInstance__Q26System10RaceConfig@l(r4)
  /* 80536E5C 80040B68 */ lwz         r0, 0xb68(r4)
  /* 80536E60 5400083C */ slwi        r0, r0, 1
  /* 80536E64 7C830214 */ add         r4, r3, r0
  /* 80536E68 A0649344 */ lhz         r3, -0x6cbc(r4)
  /* 80536E6C 2803FFFF */ cmplwi      r3, 0xffff
  /* 80536E70 4080000C */ bge-        lbl_80536e7c
  /* 80536E74 38030001 */ addi        r0, r3, 0x1
  /* 80536E78 B0049344 */ sth         r0, -0x6cbc(r4)
  lbl_80536e7c:
  /* 80536E7C 3C9C0001 */ addis       r4, r28, 1
  /* 80536E80 3C608089 */ lis         r3, lbl_808901c4@ha
  /* 80536E84 C06492C0 */ lfs         f3, -0x6d40(r4)
  /* 80536E88 C04301C4 */ lfs         f2, lbl_808901c4@l(r3)
  /* 80536E8C FC031040 */ opword      0xfc031040
  /* 80536E90 40800030 */ bge-        lbl_80536ec0
  /* 80536E94 93E10024 */ stw         r31, 0x24(r1)
  /* 80536E98 3C608089 */ lis         r3, lbl_80890170@ha
  /* 80536E9C C8230170 */ lfd         f1, lbl_80890170@l(r3)
  /* 80536EA0 C8010020 */ lfd         f0, 0x20(r1)
  /* 80536EA4 EC000828 */ fsubs       f0, f0, f1
  /* 80536EA8 EC03002A */ fadds       f0, f3, f0
  /* 80536EAC FC001040 */ opword      0xfc001040
  /* 80536EB0 40810008 */ ble-        lbl_80536eb8
  /* 80536EB4 FC001090 */ fmr         f0, f2
  lbl_80536eb8:
  /* 80536EB8 3C7C0001 */ addis       r3, r28, 1
  /* 80536EBC D00392C0 */ stfs        f0, -0x6d40(r3)
  lbl_80536ec0:
  /* 80536EC0 3C9C0001 */ addis       r4, r28, 1
  /* 80536EC4 3C608089 */ lis         r3, lbl_808901c4@ha
  /* 80536EC8 C06492C4 */ lfs         f3, -0x6d3c(r4)
  /* 80536ECC C04301C4 */ lfs         f2, lbl_808901c4@l(r3)
  /* 80536ED0 FC031040 */ opword      0xfc031040
  /* 80536ED4 408000D4 */ bge-        lbl_80536fa8
  /* 80536ED8 93C1002C */ stw         r30, 0x2c(r1)
  /* 80536EDC 3C608089 */ lis         r3, lbl_80890170@ha
  /* 80536EE0 C8230170 */ lfd         f1, lbl_80890170@l(r3)
  /* 80536EE4 C8010028 */ lfd         f0, 0x28(r1)
  /* 80536EE8 EC000828 */ fsubs       f0, f0, f1
  /* 80536EEC EC03002A */ fadds       f0, f3, f0
  /* 80536EF0 FC001040 */ opword      0xfc001040
  /* 80536EF4 40810008 */ ble-        lbl_80536efc
  /* 80536EF8 FC001090 */ fmr         f0, f2
  lbl_80536efc:
  /* 80536EFC 3C7C0001 */ addis       r3, r28, 1
  /* 80536F00 D00392C4 */ stfs        f0, -0x6d3c(r3)
  /* 80536F04 480000A4 */ b           lbl_80536fa8
  lbl_80536f08:
  /* 80536F08 3CBC0001 */ addis       r5, r28, 1
  /* 80536F0C 3C600002 */ lis         r3, 2
  /* 80536F10 80859298 */ lwz         r4, -0x6d68(r5)
  /* 80536F14 3803869F */ addi        r0, r3, -0x7961
  /* 80536F18 7C040040 */ cmplw       r4, r0
  /* 80536F1C 4080000C */ bge-        lbl_80536f28
  /* 80536F20 38040001 */ addi        r0, r4, 0x1
  /* 80536F24 90059298 */ stw         r0, -0x6d68(r5)
  lbl_80536f28:
  /* 80536F28 2C1D0000 */ cmpwi       r29, 0x0
  /* 80536F2C 41820050 */ beq-        lbl_80536f7c
  /* 80536F30 807D0004 */ lwz         r3, 4(r29)
  /* 80536F34 2C030000 */ cmpwi       r3, 0x0
  /* 80536F38 41820018 */ beq-        lbl_80536f50
  /* 80536F3C 81830000 */ lwz         r12, 0(r3)
  /* 80536F40 818C0010 */ lwz         r12, 0x10(r12)
  /* 80536F44 7D8903A6 */ mtctr       r12
  /* 80536F48 4E800421 */ bctrl
  /* 80536F4C 48000008 */ b           lbl_80536f54
  lbl_80536f50:
  /* 80536F50 3860FFFF */ li          r3, -0x1
  lbl_80536f54:
  /* 80536F54 2C030000 */ cmpwi       r3, 0x0
  /* 80536F58 40820024 */ bne-        lbl_80536f7c
  /* 80536F5C 3CBC0001 */ addis       r5, r28, 1
  /* 80536F60 3C600002 */ lis         r3, 2
  /* 80536F64 808592A0 */ lwz         r4, -0x6d60(r5)
  /* 80536F68 3803869F */ addi        r0, r3, -0x7961
  /* 80536F6C 7C040040 */ cmplw       r4, r0
  /* 80536F70 4080000C */ bge-        lbl_80536f7c
  /* 80536F74 38040001 */ addi        r0, r4, 0x1
  /* 80536F78 900592A0 */ stw         r0, -0x6d60(r5)
  lbl_80536f7c:
  /* 80536F7C 3C80809C */ lis         r4, spInstance__Q26System10RaceConfig@ha
  /* 80536F80 3C7C0001 */ addis       r3, r28, 1
  /* 80536F84 8084D728 */ lwz         r4, spInstance__Q26System10RaceConfig@l(r4)
  /* 80536F88 80040B68 */ lwz         r0, 0xb68(r4)
  /* 80536F8C 5400083C */ slwi        r0, r0, 1
  /* 80536F90 7C830214 */ add         r4, r3, r0
  /* 80536F94 A0649344 */ lhz         r3, -0x6cbc(r4)
  /* 80536F98 2803FFFF */ cmplwi      r3, 0xffff
  /* 80536F9C 4080000C */ bge-        lbl_80536fa8
  /* 80536FA0 38030001 */ addi        r0, r3, 0x1
  /* 80536FA4 B0049344 */ sth         r0, -0x6cbc(r4)
  lbl_80536fa8:
  /* 80536FA8 3C9C0001 */ addis       r4, r28, 1
  /* 80536FAC 3C608089 */ lis         r3, lbl_808901c4@ha
  /* 80536FB0 C06492BC */ lfs         f3, -0x6d44(r4)
  /* 80536FB4 C04301C4 */ lfs         f2, lbl_808901c4@l(r3)
  /* 80536FB8 FC031040 */ opword      0xfc031040
  /* 80536FBC 40800030 */ bge-        lbl_80536fec
  /* 80536FC0 93C10024 */ stw         r30, 0x24(r1)
  /* 80536FC4 3C608089 */ lis         r3, lbl_80890170@ha
  /* 80536FC8 C8230170 */ lfd         f1, lbl_80890170@l(r3)
  /* 80536FCC C8010020 */ lfd         f0, 0x20(r1)
  /* 80536FD0 EC000828 */ fsubs       f0, f0, f1
  /* 80536FD4 EC03002A */ fadds       f0, f3, f0
  /* 80536FD8 FC001040 */ opword      0xfc001040
  /* 80536FDC 40810008 */ ble-        lbl_80536fe4
  /* 80536FE0 FC001090 */ fmr         f0, f2
  lbl_80536fe4:
  /* 80536FE4 3C7C0001 */ addis       r3, r28, 1
  /* 80536FE8 D00392BC */ stfs        f0, -0x6d44(r3)
  lbl_80536fec:
  /* 80536FEC 3C9C0001 */ addis       r4, r28, 1
  /* 80536FF0 3C608089 */ lis         r3, lbl_808901c4@ha
  /* 80536FF4 C06492C4 */ lfs         f3, -0x6d3c(r4)
  /* 80536FF8 C04301C4 */ lfs         f2, lbl_808901c4@l(r3)
  /* 80536FFC FC031040 */ opword      0xfc031040
  /* 80537000 40800030 */ bge-        lbl_80537030
  /* 80537004 93C1002C */ stw         r30, 0x2c(r1)
  /* 80537008 3C608089 */ lis         r3, lbl_80890170@ha
  /* 8053700C C8230170 */ lfd         f1, lbl_80890170@l(r3)
  /* 80537010 C8010028 */ lfd         f0, 0x28(r1)
  /* 80537014 EC000828 */ fsubs       f0, f0, f1
  /* 80537018 EC03002A */ fadds       f0, f3, f0
  /* 8053701C FC001040 */ opword      0xfc001040
  /* 80537020 40810008 */ ble-        lbl_80537028
  /* 80537024 FC001090 */ fmr         f0, f2
  lbl_80537028:
  /* 80537028 3C7C0001 */ addis       r3, r28, 1
  /* 8053702C D00392C4 */ stfs        f0, -0x6d3c(r3)
  lbl_80537030:
  /* 80537030 3C9C0001 */ addis       r4, r28, 1
  /* 80537034 3C600002 */ lis         r3, 2
  /* 80537038 808492AC */ lwz         r4, -0x6d54(r4)
  /* 8053703C 3863869F */ addi        r3, r3, -0x7961
  /* 80537040 7C041840 */ cmplw       r4, r3
  /* 80537044 40800028 */ bge-        lbl_8053706c
  /* 80537048 7C041810 */ subfc       r0, r4, r3
  /* 8053704C 38000000 */ li          r0, 0x0
  /* 80537050 7C000110 */ subfe       r0, r0, r0
  /* 80537054 7C031910 */ subfe       r0, r3, r3
  /* 80537058 7C0000D1 */ neg.        r0, r0
  /* 8053705C 41820008 */ beq-        lbl_80537064
  /* 80537060 7C641B78 */ mr          r4, r3
  lbl_80537064:
  /* 80537064 3C7C0001 */ addis       r3, r28, 1
  /* 80537068 908392AC */ stw         r4, -0x6d54(r3)
  lbl_8053706c:
  /* 8053706C 3C9C0001 */ addis       r4, r28, 1
  /* 80537070 3C600002 */ lis         r3, 2
  /* 80537074 808492B0 */ lwz         r4, -0x6d50(r4)
  /* 80537078 3863869F */ addi        r3, r3, -0x7961
  /* 8053707C 80010014 */ lwz         r0, 0x14(r1)
  /* 80537080 7C041840 */ cmplw       r4, r3
  /* 80537084 4080002C */ bge-        lbl_805370b0
  /* 80537088 7CA40214 */ add         r5, r4, r0
  /* 8053708C 38800000 */ li          r4, 0x0
  /* 80537090 7C051810 */ subfc       r0, r5, r3
  /* 80537094 7C042110 */ subfe       r0, r4, r4
  /* 80537098 7C031910 */ subfe       r0, r3, r3
  /* 8053709C 7C0000D1 */ neg.        r0, r0
  /* 805370A0 41820008 */ beq-        lbl_805370a8
  /* 805370A4 7C651B78 */ mr          r5, r3
  lbl_805370a8:
  /* 805370A8 3C7C0001 */ addis       r3, r28, 1
  /* 805370AC 90A392B0 */ stw         r5, -0x6d50(r3)
  lbl_805370b0:
  /* 805370B0 3C9C0001 */ addis       r4, r28, 1
  /* 805370B4 3C600002 */ lis         r3, 2
  /* 805370B8 808492B4 */ lwz         r4, -0x6d4c(r4)
  /* 805370BC 3863869F */ addi        r3, r3, -0x7961
  /* 805370C0 80010018 */ lwz         r0, 0x18(r1)
  /* 805370C4 7C041840 */ cmplw       r4, r3
  /* 805370C8 4080002C */ bge-        lbl_805370f4
  /* 805370CC 7CA40214 */ add         r5, r4, r0
  /* 805370D0 38800000 */ li          r4, 0x0
  /* 805370D4 7C051810 */ subfc       r0, r5, r3
  /* 805370D8 7C042110 */ subfe       r0, r4, r4
  /* 805370DC 7C031910 */ subfe       r0, r3, r3
  /* 805370E0 7C0000D1 */ neg.        r0, r0
  /* 805370E4 41820008 */ beq-        lbl_805370ec
  /* 805370E8 7C651B78 */ mr          r5, r3
  lbl_805370ec:
  /* 805370EC 3C7C0001 */ addis       r3, r28, 1
  /* 805370F0 90A392B4 */ stw         r5, -0x6d4c(r3)
  lbl_805370f4:
  /* 805370F4 881B0008 */ lbz         r0, 8(r27)
  /* 805370F8 3C60809C */ lis         r3, spInstance__Q26System10RaceConfig@ha
  /* 805370FC 8063D728 */ lwz         r3, spInstance__Q26System10RaceConfig@l(r3)
  /* 80537100 1C0000F0 */ mulli       r0, r0, 0xf0
  /* 80537104 7C630214 */ add         r3, r3, r0
  /* 80537108 83A30034 */ lwz         r29, 0x34(r3)
  /* 8053710C 7FA3EB78 */ mr          r3, r29
  /* 80537110 4BFF04DD */ bl          isMii
  /* 80537114 2C030000 */ cmpwi       r3, 0x0
  /* 80537118 41820008 */ beq-        lbl_80537120
  /* 8053711C 3BA00018 */ li          r29, 0x18
  lbl_80537120:
  /* 80537120 3C7C0001 */ addis       r3, r28, 1
  /* 80537124 57A0083C */ slwi        r0, r29, 1
  /* 80537128 7C830214 */ add         r4, r3, r0
  /* 8053712C A06492CA */ lhz         r3, -0x6d36(r4)
  /* 80537130 2803FFFF */ cmplwi      r3, 0xffff
  /* 80537134 4080000C */ bge-        lbl_80537140
  /* 80537138 38030001 */ addi        r0, r3, 0x1
  /* 8053713C B00492CA */ sth         r0, -0x6d36(r4)
  lbl_80537140:
  /* 80537140 881B0008 */ lbz         r0, 8(r27)
  /* 80537144 3C60809C */ lis         r3, spInstance__Q26System10RaceConfig@ha
  /* 80537148 8083D728 */ lwz         r4, spInstance__Q26System10RaceConfig@l(r3)
  /* 8053714C 3C7C0001 */ addis       r3, r28, 1
  /* 80537150 1C0000F0 */ mulli       r0, r0, 0xf0
  /* 80537154 7C840214 */ add         r4, r4, r0
  /* 80537158 80040030 */ lwz         r0, 0x30(r4)
  /* 8053715C 5400083C */ slwi        r0, r0, 1
  /* 80537160 7C830214 */ add         r4, r3, r0
  /* 80537164 A06492FC */ lhz         r3, -0x6d04(r4)
  /* 80537168 2803FFFF */ cmplwi      r3, 0xffff
  /* 8053716C 4080000C */ bge-        lbl_80537178
  /* 80537170 38030001 */ addi        r0, r3, 0x1
  /* 80537174 B00492FC */ sth         r0, -0x6d04(r4)
  lbl_80537178:
  /* 80537178 39610050 */ addi        r11, r1, 0x50
  /* 8053717C 4BAEA471 */ bl          _restgpr_27
  /* 80537180 80010054 */ lwz         r0, 0x54(r1)
  /* 80537184 7C0803A6 */ mtlr        r0
  /* 80537188 38210050 */ addi        r1, r1, 0x50
  /* 8053718C 4E800020 */ blr // clang-format on
}

// Symbol: unk_80537190
// PAL: 0x80537190..0x805371a4
MARK_BINARY_BLOB(unk_80537190, 0x80537190, 0x805371a4);
asm UNKNOWN_FUNCTION(unk_80537190){
    // clang-format off
  nofralloc
  /* 80537190 80630010 */ lwz         r3, 0x10(r3)
  /* 80537194 81830000 */ lwz         r12, 0(r3)
  /* 80537198 818C0028 */ lwz         r12, 0x28(r12)
  /* 8053719C 7D8903A6 */ mtctr       r12
  /* 805371A0 4E800420 */ bctr // clang-format on
}

// Symbol: unk_805371a4
// PAL: 0x805371a4..0x805371a8
MARK_BINARY_BLOB(unk_805371a4, 0x805371a4, 0x805371a8);
asm UNKNOWN_FUNCTION(unk_805371a4){
    // clang-format off
  nofralloc
  /* 805371A4 4E800020 */ blr // clang-format on
}

// Symbol: unk_805371a8
// PAL: 0x805371a8..0x805371e8
MARK_BINARY_BLOB(unk_805371a8, 0x805371a8, 0x805371e8);
asm UNKNOWN_FUNCTION(unk_805371a8){
  // clang-format off
  nofralloc
  /* 805371A8 9421FFF0 */ stwu        r1, -0x10(r1)
  /* 805371AC 7C0802A6 */ mflr        r0
  /* 805371B0 2C030000 */ cmpwi       r3, 0x0
  /* 805371B4 90010014 */ stw         r0, 0x14(r1)
  /* 805371B8 93E1000C */ stw         r31, 0xc(r1)
  /* 805371BC 7C7F1B78 */ mr          r31, r3
  /* 805371C0 41820010 */ beq-        lbl_805371d0
  /* 805371C4 2C040000 */ cmpwi       r4, 0x0
  /* 805371C8 40810008 */ ble-        lbl_805371d0
  /* 805371CC 4BCF2C49 */ bl          __dl__FPv
  lbl_805371d0:
  /* 805371D0 7FE3FB78 */ mr          r3, r31
  /* 805371D4 83E1000C */ lwz         r31, 0xc(r1)
  /* 805371D8 80010014 */ lwz         r0, 0x14(r1)
  /* 805371DC 7C0803A6 */ mtlr        r0
  /* 805371E0 38210010 */ addi        r1, r1, 0x10
  /* 805371E4 4E800020 */ blr // clang-format on
}

// Symbol: unk_805371e8
// PAL: 0x805371e8..0x8053724c
MARK_BINARY_BLOB(unk_805371e8, 0x805371e8, 0x8053724c);
asm UNKNOWN_FUNCTION(unk_805371e8){
    // clang-format off
  nofralloc
  /* 805371E8 9421FFE0 */ stwu        r1, -0x20(r1)
  /* 805371EC 7C0802A6 */ mflr        r0
  /* 805371F0 90010024 */ stw         r0, 0x24(r1)
  /* 805371F4 93E1001C */ stw         r31, 0x1c(r1)
  /* 805371F8 7CBF2B78 */ mr          r31, r5
  /* 805371FC 93C10018 */ stw         r30, 0x18(r1)
  /* 80537200 7C9E2378 */ mr          r30, r4
  /* 80537204 A0030004 */ lhz         r0, 4(r3)
  /* 80537208 B0010008 */ sth         r0, 8(r1)
  /* 8053720C 81830000 */ lwz         r12, 0(r3)
  /* 80537210 818C0014 */ lwz         r12, 0x14(r12)
  /* 80537214 7D8903A6 */ mtctr       r12
  /* 80537218 4E800421 */ bctrl
  /* 8053721C 7C641B78 */ mr          r4, r3
  /* 80537220 7FC5F378 */ mr          r5, r30
  /* 80537224 7FE6FB78 */ mr          r6, r31
  /* 80537228 38610008 */ addi        r3, r1, 0x8
  /* 8053722C 38E00002 */ li          r7, 0x2
  /* 80537230 4BFF593D */ bl          unk_8052cb6c
  /* 80537234 80010024 */ lwz         r0, 0x24(r1)
  /* 80537238 83E1001C */ lwz         r31, 0x1c(r1)
  /* 8053723C 83C10018 */ lwz         r30, 0x18(r1)
  /* 80537240 7C0803A6 */ mtlr        r0
  /* 80537244 38210020 */ addi        r1, r1, 0x20
  /* 80537248 4E800020 */ blr // clang-format on
}

// Symbol: unk_8053724c
// PAL: 0x8053724c..0x805372b4
MARK_BINARY_BLOB(unk_8053724c, 0x8053724c, 0x805372b4);
asm UNKNOWN_FUNCTION(unk_8053724c){
    // clang-format off
  nofralloc
  /* 8053724C 9421FFE0 */ stwu        r1, -0x20(r1)
  /* 80537250 7C0802A6 */ mflr        r0
  /* 80537254 90010024 */ stw         r0, 0x24(r1)
  /* 80537258 93E1001C */ stw         r31, 0x1c(r1)
  /* 8053725C 7CBF2B78 */ mr          r31, r5
  /* 80537260 93C10018 */ stw         r30, 0x18(r1)
  /* 80537264 7C9E2378 */ mr          r30, r4
  /* 80537268 93A10014 */ stw         r29, 0x14(r1)
  /* 8053726C 7C7D1B78 */ mr          r29, r3
  /* 80537270 81830000 */ lwz         r12, 0(r3)
  /* 80537274 818C0014 */ lwz         r12, 0x14(r12)
  /* 80537278 7D8903A6 */ mtctr       r12
  /* 8053727C 4E800421 */ bctrl
  /* 80537280 7C641B78 */ mr          r4, r3
  /* 80537284 7FC5F378 */ mr          r5, r30
  /* 80537288 7FE6FB78 */ mr          r6, r31
  /* 8053728C 387D0004 */ addi        r3, r29, 0x4
  /* 80537290 38E00002 */ li          r7, 0x2
  /* 80537294 4BFF5A11 */ bl          unk_8052cca4
  /* 80537298 80010024 */ lwz         r0, 0x24(r1)
  /* 8053729C 83E1001C */ lwz         r31, 0x1c(r1)
  /* 805372A0 83C10018 */ lwz         r30, 0x18(r1)
  /* 805372A4 83A10014 */ lwz         r29, 0x14(r1)
  /* 805372A8 7C0803A6 */ mtlr        r0
  /* 805372AC 38210020 */ addi        r1, r1, 0x20
  /* 805372B0 4E800020 */ blr // clang-format on
}

// Symbol: unk_805372b4
// PAL: 0x805372b4..0x805372bc
MARK_BINARY_BLOB(unk_805372b4, 0x805372b4, 0x805372bc);
asm UNKNOWN_FUNCTION(unk_805372b4){
    // clang-format off
  nofralloc
  /* 805372B4 3860000D */ li          r3, 0xd
  /* 805372B8 4E800020 */ blr // clang-format on
}

// Symbol: unk_805372bc
// PAL: 0x805372bc..0x80537320
MARK_BINARY_BLOB(unk_805372bc, 0x805372bc, 0x80537320);
asm UNKNOWN_FUNCTION(unk_805372bc){
    // clang-format off
  nofralloc
  /* 805372BC 9421FFE0 */ stwu        r1, -0x20(r1)
  /* 805372C0 7C0802A6 */ mflr        r0
  /* 805372C4 90010024 */ stw         r0, 0x24(r1)
  /* 805372C8 93E1001C */ stw         r31, 0x1c(r1)
  /* 805372CC 7CBF2B78 */ mr          r31, r5
  /* 805372D0 93C10018 */ stw         r30, 0x18(r1)
  /* 805372D4 7C9E2378 */ mr          r30, r4
  /* 805372D8 A0030004 */ lhz         r0, 4(r3)
  /* 805372DC B0010008 */ sth         r0, 8(r1)
  /* 805372E0 81830000 */ lwz         r12, 0(r3)
  /* 805372E4 818C0014 */ lwz         r12, 0x14(r12)
  /* 805372E8 7D8903A6 */ mtctr       r12
  /* 805372EC 4E800421 */ bctrl
  /* 805372F0 7C641B78 */ mr          r4, r3
  /* 805372F4 7FC5F378 */ mr          r5, r30
  /* 805372F8 7FE6FB78 */ mr          r6, r31
  /* 805372FC 38610008 */ addi        r3, r1, 0x8
  /* 80537300 38E00002 */ li          r7, 0x2
  /* 80537304 4BFF5869 */ bl          unk_8052cb6c
  /* 80537308 80010024 */ lwz         r0, 0x24(r1)
  /* 8053730C 83E1001C */ lwz         r31, 0x1c(r1)
  /* 80537310 83C10018 */ lwz         r30, 0x18(r1)
  /* 80537314 7C0803A6 */ mtlr        r0
  /* 80537318 38210020 */ addi        r1, r1, 0x20
  /* 8053731C 4E800020 */ blr // clang-format on
}

// Symbol: unk_80537320
// PAL: 0x80537320..0x80537388
MARK_BINARY_BLOB(unk_80537320, 0x80537320, 0x80537388);
asm UNKNOWN_FUNCTION(unk_80537320){
    // clang-format off
  nofralloc
  /* 80537320 9421FFE0 */ stwu        r1, -0x20(r1)
  /* 80537324 7C0802A6 */ mflr        r0
  /* 80537328 90010024 */ stw         r0, 0x24(r1)
  /* 8053732C 93E1001C */ stw         r31, 0x1c(r1)
  /* 80537330 7CBF2B78 */ mr          r31, r5
  /* 80537334 93C10018 */ stw         r30, 0x18(r1)
  /* 80537338 7C9E2378 */ mr          r30, r4
  /* 8053733C 93A10014 */ stw         r29, 0x14(r1)
  /* 80537340 7C7D1B78 */ mr          r29, r3
  /* 80537344 81830000 */ lwz         r12, 0(r3)
  /* 80537348 818C0014 */ lwz         r12, 0x14(r12)
  /* 8053734C 7D8903A6 */ mtctr       r12
  /* 80537350 4E800421 */ bctrl
  /* 80537354 7C641B78 */ mr          r4, r3
  /* 80537358 7FC5F378 */ mr          r5, r30
  /* 8053735C 7FE6FB78 */ mr          r6, r31
  /* 80537360 387D0004 */ addi        r3, r29, 0x4
  /* 80537364 38E00002 */ li          r7, 0x2
  /* 80537368 4BFF593D */ bl          unk_8052cca4
  /* 8053736C 80010024 */ lwz         r0, 0x24(r1)
  /* 80537370 83E1001C */ lwz         r31, 0x1c(r1)
  /* 80537374 83C10018 */ lwz         r30, 0x18(r1)
  /* 80537378 83A10014 */ lwz         r29, 0x14(r1)
  /* 8053737C 7C0803A6 */ mtlr        r0
  /* 80537380 38210020 */ addi        r1, r1, 0x20
  /* 80537384 4E800020 */ blr // clang-format on
}

// Symbol: unk_80537388
// PAL: 0x80537388..0x80537390
MARK_BINARY_BLOB(unk_80537388, 0x80537388, 0x80537390);
asm UNKNOWN_FUNCTION(unk_80537388){
    // clang-format off
  nofralloc
  /* 80537388 3860000A */ li          r3, 0xa
  /* 8053738C 4E800020 */ blr // clang-format on
}

// Symbol: unk_80537390
// PAL: 0x80537390..0x805373f4
MARK_BINARY_BLOB(unk_80537390, 0x80537390, 0x805373f4);
asm UNKNOWN_FUNCTION(unk_80537390){
    // clang-format off
  nofralloc
  /* 80537390 9421FFE0 */ stwu        r1, -0x20(r1)
  /* 80537394 7C0802A6 */ mflr        r0
  /* 80537398 90010024 */ stw         r0, 0x24(r1)
  /* 8053739C 93E1001C */ stw         r31, 0x1c(r1)
  /* 805373A0 7CBF2B78 */ mr          r31, r5
  /* 805373A4 93C10018 */ stw         r30, 0x18(r1)
  /* 805373A8 7C9E2378 */ mr          r30, r4
  /* 805373AC 88030004 */ lbz         r0, 4(r3)
  /* 805373B0 98010008 */ stb         r0, 8(r1)
  /* 805373B4 81830000 */ lwz         r12, 0(r3)
  /* 805373B8 818C0014 */ lwz         r12, 0x14(r12)
  /* 805373BC 7D8903A6 */ mtctr       r12
  /* 805373C0 4E800421 */ bctrl
  /* 805373C4 7C641B78 */ mr          r4, r3
  /* 805373C8 7FC5F378 */ mr          r5, r30
  /* 805373CC 7FE6FB78 */ mr          r6, r31
  /* 805373D0 38610008 */ addi        r3, r1, 0x8
  /* 805373D4 38E00001 */ li          r7, 0x1
  /* 805373D8 4BFF5795 */ bl          unk_8052cb6c
  /* 805373DC 80010024 */ lwz         r0, 0x24(r1)
  /* 805373E0 83E1001C */ lwz         r31, 0x1c(r1)
  /* 805373E4 83C10018 */ lwz         r30, 0x18(r1)
  /* 805373E8 7C0803A6 */ mtlr        r0
  /* 805373EC 38210020 */ addi        r1, r1, 0x20
  /* 805373F0 4E800020 */ blr // clang-format on
}

// Symbol: unk_805373f4
// PAL: 0x805373f4..0x8053745c
MARK_BINARY_BLOB(unk_805373f4, 0x805373f4, 0x8053745c);
asm UNKNOWN_FUNCTION(unk_805373f4){
    // clang-format off
  nofralloc
  /* 805373F4 9421FFE0 */ stwu        r1, -0x20(r1)
  /* 805373F8 7C0802A6 */ mflr        r0
  /* 805373FC 90010024 */ stw         r0, 0x24(r1)
  /* 80537400 93E1001C */ stw         r31, 0x1c(r1)
  /* 80537404 7CBF2B78 */ mr          r31, r5
  /* 80537408 93C10018 */ stw         r30, 0x18(r1)
  /* 8053740C 7C9E2378 */ mr          r30, r4
  /* 80537410 93A10014 */ stw         r29, 0x14(r1)
  /* 80537414 7C7D1B78 */ mr          r29, r3
  /* 80537418 81830000 */ lwz         r12, 0(r3)
  /* 8053741C 818C0014 */ lwz         r12, 0x14(r12)
  /* 80537420 7D8903A6 */ mtctr       r12
  /* 80537424 4E800421 */ bctrl
  /* 80537428 7C641B78 */ mr          r4, r3
  /* 8053742C 7FC5F378 */ mr          r5, r30
  /* 80537430 7FE6FB78 */ mr          r6, r31
  /* 80537434 387D0004 */ addi        r3, r29, 0x4
  /* 80537438 38E00001 */ li          r7, 0x1
  /* 8053743C 4BFF5869 */ bl          unk_8052cca4
  /* 80537440 80010024 */ lwz         r0, 0x24(r1)
  /* 80537444 83E1001C */ lwz         r31, 0x1c(r1)
  /* 80537448 83C10018 */ lwz         r30, 0x18(r1)
  /* 8053744C 83A10014 */ lwz         r29, 0x14(r1)
  /* 80537450 7C0803A6 */ mtlr        r0
  /* 80537454 38210020 */ addi        r1, r1, 0x20
  /* 80537458 4E800020 */ blr // clang-format on
}

// Symbol: unk_8053745c
// PAL: 0x8053745c..0x80537464
MARK_BINARY_BLOB(unk_8053745c, 0x8053745c, 0x80537464);
asm UNKNOWN_FUNCTION(unk_8053745c){
    // clang-format off
  nofralloc
  /* 8053745C 38600006 */ li          r3, 0x6
  /* 80537460 4E800020 */ blr // clang-format on
}

// Symbol: unk_80537464
// PAL: 0x80537464..0x805374c8
MARK_BINARY_BLOB(unk_80537464, 0x80537464, 0x805374c8);
asm UNKNOWN_FUNCTION(unk_80537464){
    // clang-format off
  nofralloc
  /* 80537464 9421FFE0 */ stwu        r1, -0x20(r1)
  /* 80537468 7C0802A6 */ mflr        r0
  /* 8053746C 90010024 */ stw         r0, 0x24(r1)
  /* 80537470 93E1001C */ stw         r31, 0x1c(r1)
  /* 80537474 7CBF2B78 */ mr          r31, r5
  /* 80537478 93C10018 */ stw         r30, 0x18(r1)
  /* 8053747C 7C9E2378 */ mr          r30, r4
  /* 80537480 88030004 */ lbz         r0, 4(r3)
  /* 80537484 98010008 */ stb         r0, 8(r1)
  /* 80537488 81830000 */ lwz         r12, 0(r3)
  /* 8053748C 818C0014 */ lwz         r12, 0x14(r12)
  /* 80537490 7D8903A6 */ mtctr       r12
  /* 80537494 4E800421 */ bctrl
  /* 80537498 7C641B78 */ mr          r4, r3
  /* 8053749C 7FC5F378 */ mr          r5, r30
  /* 805374A0 7FE6FB78 */ mr          r6, r31
  /* 805374A4 38610008 */ addi        r3, r1, 0x8
  /* 805374A8 38E00001 */ li          r7, 0x1
  /* 805374AC 4BFF56C1 */ bl          unk_8052cb6c
  /* 805374B0 80010024 */ lwz         r0, 0x24(r1)
  /* 805374B4 83E1001C */ lwz         r31, 0x1c(r1)
  /* 805374B8 83C10018 */ lwz         r30, 0x18(r1)
  /* 805374BC 7C0803A6 */ mtlr        r0
  /* 805374C0 38210020 */ addi        r1, r1, 0x20
  /* 805374C4 4E800020 */ blr // clang-format on
}

// Symbol: unk_805374c8
// PAL: 0x805374c8..0x80537530
MARK_BINARY_BLOB(unk_805374c8, 0x805374c8, 0x80537530);
asm UNKNOWN_FUNCTION(unk_805374c8){
    // clang-format off
  nofralloc
  /* 805374C8 9421FFE0 */ stwu        r1, -0x20(r1)
  /* 805374CC 7C0802A6 */ mflr        r0
  /* 805374D0 90010024 */ stw         r0, 0x24(r1)
  /* 805374D4 93E1001C */ stw         r31, 0x1c(r1)
  /* 805374D8 7CBF2B78 */ mr          r31, r5
  /* 805374DC 93C10018 */ stw         r30, 0x18(r1)
  /* 805374E0 7C9E2378 */ mr          r30, r4
  /* 805374E4 93A10014 */ stw         r29, 0x14(r1)
  /* 805374E8 7C7D1B78 */ mr          r29, r3
  /* 805374EC 81830000 */ lwz         r12, 0(r3)
  /* 805374F0 818C0014 */ lwz         r12, 0x14(r12)
  /* 805374F4 7D8903A6 */ mtctr       r12
  /* 805374F8 4E800421 */ bctrl
  /* 805374FC 7C641B78 */ mr          r4, r3
  /* 80537500 7FC5F378 */ mr          r5, r30
  /* 80537504 7FE6FB78 */ mr          r6, r31
  /* 80537508 387D0004 */ addi        r3, r29, 0x4
  /* 8053750C 38E00001 */ li          r7, 0x1
  /* 80537510 4BFF5795 */ bl          unk_8052cca4
  /* 80537514 80010024 */ lwz         r0, 0x24(r1)
  /* 80537518 83E1001C */ lwz         r31, 0x1c(r1)
  /* 8053751C 83C10018 */ lwz         r30, 0x18(r1)
  /* 80537520 83A10014 */ lwz         r29, 0x14(r1)
  /* 80537524 7C0803A6 */ mtlr        r0
  /* 80537528 38210020 */ addi        r1, r1, 0x20
  /* 8053752C 4E800020 */ blr // clang-format on
}

// Symbol: unk_80537530
// PAL: 0x80537530..0x80537538
MARK_BINARY_BLOB(unk_80537530, 0x80537530, 0x80537538);
asm UNKNOWN_FUNCTION(unk_80537530){
    // clang-format off
  nofralloc
  /* 80537530 38600006 */ li          r3, 0x6
  /* 80537534 4E800020 */ blr // clang-format on
}

// Symbol: unk_80537538
// PAL: 0x80537538..0x8053759c
MARK_BINARY_BLOB(unk_80537538, 0x80537538, 0x8053759c);
asm UNKNOWN_FUNCTION(unk_80537538){
    // clang-format off
  nofralloc
  /* 80537538 9421FFE0 */ stwu        r1, -0x20(r1)
  /* 8053753C 7C0802A6 */ mflr        r0
  /* 80537540 90010024 */ stw         r0, 0x24(r1)
  /* 80537544 93E1001C */ stw         r31, 0x1c(r1)
  /* 80537548 7CBF2B78 */ mr          r31, r5
  /* 8053754C 93C10018 */ stw         r30, 0x18(r1)
  /* 80537550 7C9E2378 */ mr          r30, r4
  /* 80537554 88030004 */ lbz         r0, 4(r3)
  /* 80537558 98010008 */ stb         r0, 8(r1)
  /* 8053755C 81830000 */ lwz         r12, 0(r3)
  /* 80537560 818C0014 */ lwz         r12, 0x14(r12)
  /* 80537564 7D8903A6 */ mtctr       r12
  /* 80537568 4E800421 */ bctrl
  /* 8053756C 7C641B78 */ mr          r4, r3
  /* 80537570 7FC5F378 */ mr          r5, r30
  /* 80537574 7FE6FB78 */ mr          r6, r31
  /* 80537578 38610008 */ addi        r3, r1, 0x8
  /* 8053757C 38E00001 */ li          r7, 0x1
  /* 80537580 4BFF55ED */ bl          unk_8052cb6c
  /* 80537584 80010024 */ lwz         r0, 0x24(r1)
  /* 80537588 83E1001C */ lwz         r31, 0x1c(r1)
  /* 8053758C 83C10018 */ lwz         r30, 0x18(r1)
  /* 80537590 7C0803A6 */ mtlr        r0
  /* 80537594 38210020 */ addi        r1, r1, 0x20
  /* 80537598 4E800020 */ blr // clang-format on
}

// Symbol: unk_8053759c
// PAL: 0x8053759c..0x80537604
MARK_BINARY_BLOB(unk_8053759c, 0x8053759c, 0x80537604);
asm UNKNOWN_FUNCTION(unk_8053759c){
    // clang-format off
  nofralloc
  /* 8053759C 9421FFE0 */ stwu        r1, -0x20(r1)
  /* 805375A0 7C0802A6 */ mflr        r0
  /* 805375A4 90010024 */ stw         r0, 0x24(r1)
  /* 805375A8 93E1001C */ stw         r31, 0x1c(r1)
  /* 805375AC 7CBF2B78 */ mr          r31, r5
  /* 805375B0 93C10018 */ stw         r30, 0x18(r1)
  /* 805375B4 7C9E2378 */ mr          r30, r4
  /* 805375B8 93A10014 */ stw         r29, 0x14(r1)
  /* 805375BC 7C7D1B78 */ mr          r29, r3
  /* 805375C0 81830000 */ lwz         r12, 0(r3)
  /* 805375C4 818C0014 */ lwz         r12, 0x14(r12)
  /* 805375C8 7D8903A6 */ mtctr       r12
  /* 805375CC 4E800421 */ bctrl
  /* 805375D0 7C641B78 */ mr          r4, r3
  /* 805375D4 7FC5F378 */ mr          r5, r30
  /* 805375D8 7FE6FB78 */ mr          r6, r31
  /* 805375DC 387D0004 */ addi        r3, r29, 0x4
  /* 805375E0 38E00001 */ li          r7, 0x1
  /* 805375E4 4BFF56C1 */ bl          unk_8052cca4
  /* 805375E8 80010024 */ lwz         r0, 0x24(r1)
  /* 805375EC 83E1001C */ lwz         r31, 0x1c(r1)
  /* 805375F0 83C10018 */ lwz         r30, 0x18(r1)
  /* 805375F4 83A10014 */ lwz         r29, 0x14(r1)
  /* 805375F8 7C0803A6 */ mtlr        r0
  /* 805375FC 38210020 */ addi        r1, r1, 0x20
  /* 80537600 4E800020 */ blr // clang-format on
}

// Symbol: unk_80537604
// PAL: 0x80537604..0x8053760c
MARK_BINARY_BLOB(unk_80537604, 0x80537604, 0x8053760c);
asm UNKNOWN_FUNCTION(unk_80537604){
    // clang-format off
  nofralloc
  /* 80537604 38600004 */ li          r3, 0x4
  /* 80537608 4E800020 */ blr // clang-format on
}

// Symbol: unk_8053760c
// PAL: 0x8053760c..0x80537670
MARK_BINARY_BLOB(unk_8053760c, 0x8053760c, 0x80537670);
asm UNKNOWN_FUNCTION(unk_8053760c){
    // clang-format off
  nofralloc
  /* 8053760C 9421FFE0 */ stwu        r1, -0x20(r1)
  /* 80537610 7C0802A6 */ mflr        r0
  /* 80537614 90010024 */ stw         r0, 0x24(r1)
  /* 80537618 93E1001C */ stw         r31, 0x1c(r1)
  /* 8053761C 7CBF2B78 */ mr          r31, r5
  /* 80537620 93C10018 */ stw         r30, 0x18(r1)
  /* 80537624 7C9E2378 */ mr          r30, r4
  /* 80537628 88030004 */ lbz         r0, 4(r3)
  /* 8053762C 98010008 */ stb         r0, 8(r1)
  /* 80537630 81830000 */ lwz         r12, 0(r3)
  /* 80537634 818C0014 */ lwz         r12, 0x14(r12)
  /* 80537638 7D8903A6 */ mtctr       r12
  /* 8053763C 4E800421 */ bctrl
  /* 80537640 7C641B78 */ mr          r4, r3
  /* 80537644 7FC5F378 */ mr          r5, r30
  /* 80537648 7FE6FB78 */ mr          r6, r31
  /* 8053764C 38610008 */ addi        r3, r1, 0x8
  /* 80537650 38E00001 */ li          r7, 0x1
  /* 80537654 4BFF5519 */ bl          unk_8052cb6c
  /* 80537658 80010024 */ lwz         r0, 0x24(r1)
  /* 8053765C 83E1001C */ lwz         r31, 0x1c(r1)
  /* 80537660 83C10018 */ lwz         r30, 0x18(r1)
  /* 80537664 7C0803A6 */ mtlr        r0
  /* 80537668 38210020 */ addi        r1, r1, 0x20
  /* 8053766C 4E800020 */ blr // clang-format on
}

// Symbol: unk_80537670
// PAL: 0x80537670..0x805376d8
MARK_BINARY_BLOB(unk_80537670, 0x80537670, 0x805376d8);
asm UNKNOWN_FUNCTION(unk_80537670){
    // clang-format off
  nofralloc
  /* 80537670 9421FFE0 */ stwu        r1, -0x20(r1)
  /* 80537674 7C0802A6 */ mflr        r0
  /* 80537678 90010024 */ stw         r0, 0x24(r1)
  /* 8053767C 93E1001C */ stw         r31, 0x1c(r1)
  /* 80537680 7CBF2B78 */ mr          r31, r5
  /* 80537684 93C10018 */ stw         r30, 0x18(r1)
  /* 80537688 7C9E2378 */ mr          r30, r4
  /* 8053768C 93A10014 */ stw         r29, 0x14(r1)
  /* 80537690 7C7D1B78 */ mr          r29, r3
  /* 80537694 81830000 */ lwz         r12, 0(r3)
  /* 80537698 818C0014 */ lwz         r12, 0x14(r12)
  /* 8053769C 7D8903A6 */ mtctr       r12
  /* 805376A0 4E800421 */ bctrl
  /* 805376A4 7C641B78 */ mr          r4, r3
  /* 805376A8 7FC5F378 */ mr          r5, r30
  /* 805376AC 7FE6FB78 */ mr          r6, r31
  /* 805376B0 387D0004 */ addi        r3, r29, 0x4
  /* 805376B4 38E00001 */ li          r7, 0x1
  /* 805376B8 4BFF55ED */ bl          unk_8052cca4
  /* 805376BC 80010024 */ lwz         r0, 0x24(r1)
  /* 805376C0 83E1001C */ lwz         r31, 0x1c(r1)
  /* 805376C4 83C10018 */ lwz         r30, 0x18(r1)
  /* 805376C8 83A10014 */ lwz         r29, 0x14(r1)
  /* 805376CC 7C0803A6 */ mtlr        r0
  /* 805376D0 38210020 */ addi        r1, r1, 0x20
  /* 805376D4 4E800020 */ blr // clang-format on
}

// Symbol: unk_805376d8
// PAL: 0x805376d8..0x805376e0
MARK_BINARY_BLOB(unk_805376d8, 0x805376d8, 0x805376e0);
asm UNKNOWN_FUNCTION(unk_805376d8){
    // clang-format off
  nofralloc
  /* 805376D8 38600002 */ li          r3, 0x2
  /* 805376DC 4E800020 */ blr // clang-format on
}

// Symbol: unk_805376e0
// PAL: 0x805376e0..0x80537740
MARK_BINARY_BLOB(unk_805376e0, 0x805376e0, 0x80537740);
asm UNKNOWN_FUNCTION(unk_805376e0){
  // clang-format off
  nofralloc
  /* 805376E0 9421FFF0 */ stwu        r1, -0x10(r1)
  /* 805376E4 7C0802A6 */ mflr        r0
  /* 805376E8 2C030000 */ cmpwi       r3, 0x0
  /* 805376EC 90010014 */ stw         r0, 0x14(r1)
  /* 805376F0 93E1000C */ stw         r31, 0xc(r1)
  /* 805376F4 7C9F2378 */ mr          r31, r4
  /* 805376F8 93C10008 */ stw         r30, 8(r1)
  /* 805376FC 7C7E1B78 */ mr          r30, r3
  /* 80537700 41820024 */ beq-        lbl_80537724
  /* 80537704 41820010 */ beq-        lbl_80537714
  /* 80537708 3880FFFF */ li          r4, -0x1
  /* 8053770C 38630028 */ addi        r3, r3, 0x28
  /* 80537710 4801DE29 */ bl          __dt__Q24Util6RandomFv
  lbl_80537714:
  /* 80537714 2C1F0000 */ cmpwi       r31, 0x0
  /* 80537718 4081000C */ ble-        lbl_80537724
  /* 8053771C 7FC3F378 */ mr          r3, r30
  /* 80537720 4BCF26F5 */ bl          __dl__FPv
  lbl_80537724:
  /* 80537724 7FC3F378 */ mr          r3, r30
  /* 80537728 83E1000C */ lwz         r31, 0xc(r1)
  /* 8053772C 83C10008 */ lwz         r30, 8(r1)
  /* 80537730 80010014 */ lwz         r0, 0x14(r1)
  /* 80537734 7C0803A6 */ mtlr        r0
  /* 80537738 38210010 */ addi        r1, r1, 0x10
  /* 8053773C 4E800020 */ blr // clang-format on
}

// Symbol: unk_80537740
// PAL: 0x80537740..0x80537830
MARK_BINARY_BLOB(unk_80537740, 0x80537740, 0x80537830);
asm UNKNOWN_FUNCTION(unk_80537740) {
  // clang-format off
  nofralloc
  /* 80537740 9421FFC0 */ stwu        r1, -0x40(r1)
  /* 80537744 7C0802A6 */ mflr        r0
  /* 80537748 90010044 */ stw         r0, 0x44(r1)
  /* 8053774C 93E1003C */ stw         r31, 0x3c(r1)
  /* 80537750 7CBF2B78 */ mr          r31, r5
  /* 80537754 93C10038 */ stw         r30, 0x38(r1)
  /* 80537758 7C9E2378 */ mr          r30, r4
  /* 8053775C 93A10034 */ stw         r29, 0x34(r1)
  /* 80537760 7C7D1B78 */ mr          r29, r3
  /* 80537764 7FC3F378 */ mr          r3, r30
  /* 80537768 4BD0C405 */ bl          normalise2__Q23EGG8Vector3fFv
  /* 8053776C 7FE4FB78 */ mr          r4, r31
  /* 80537770 7FC5F378 */ mr          r5, r30
  /* 80537774 38610020 */ addi        r3, r1, 0x20
  /* 80537778 480000B9 */ bl          VEC3_fromCross
  /* 8053777C 38610020 */ addi        r3, r1, 0x20
  /* 80537780 4BD0C3ED */ bl          normalise2__Q23EGG8Vector3fFv
  /* 80537784 7FC4F378 */ mr          r4, r30
  /* 80537788 38610014 */ addi        r3, r1, 0x14
  /* 8053778C 38A10020 */ addi        r5, r1, 0x20
  /* 80537790 480000A1 */ bl          VEC3_fromCross
  /* 80537794 C0010014 */ lfs         f0, 0x14(r1)
  /* 80537798 3C608089 */ lis         r3, lbl_80890218@ha
  /* 8053779C D01F0000 */ stfs        f0, 0(r31)
  /* 805377A0 C0230218 */ lfs         f1, lbl_80890218@l(r3)
  /* 805377A4 C0010018 */ lfs         f0, 0x18(r1)
  /* 805377A8 D01F0004 */ stfs        f0, 4(r31)
  /* 805377AC C001001C */ lfs         f0, 0x1c(r1)
  /* 805377B0 D01F0008 */ stfs        f0, 8(r31)
  /* 805377B4 D03D000C */ stfs        f1, 0xc(r29)
  /* 805377B8 D03D001C */ stfs        f1, 0x1c(r29)
  /* 805377BC D03D002C */ stfs        f1, 0x2c(r29)
  /* 805377C0 C0010020 */ lfs         f0, 0x20(r1)
  /* 805377C4 D01D0000 */ stfs        f0, 0(r29)
  /* 805377C8 C0010024 */ lfs         f0, 0x24(r1)
  /* 805377CC D01D0010 */ stfs        f0, 0x10(r29)
  /* 805377D0 C0010028 */ lfs         f0, 0x28(r1)
  /* 805377D4 D01D0020 */ stfs        f0, 0x20(r29)
  /* 805377D8 C01F0000 */ lfs         f0, 0(r31)
  /* 805377DC D01D0004 */ stfs        f0, 4(r29)
  /* 805377E0 C01F0004 */ lfs         f0, 4(r31)
  /* 805377E4 D01D0014 */ stfs        f0, 0x14(r29)
  /* 805377E8 C01F0008 */ lfs         f0, 8(r31)
  /* 805377EC D01D0024 */ stfs        f0, 0x24(r29)
  /* 805377F0 C01E0000 */ lfs         f0, 0(r30)
  /* 805377F4 D01D0008 */ stfs        f0, 8(r29)
  /* 805377F8 C01E0004 */ lfs         f0, 4(r30)
  /* 805377FC D01D0018 */ stfs        f0, 0x18(r29)
  /* 80537800 C01E0008 */ lfs         f0, 8(r30)
  /* 80537804 D01D0028 */ stfs        f0, 0x28(r29)
  /* 80537808 83E1003C */ lwz         r31, 0x3c(r1)
  /* 8053780C 83C10038 */ lwz         r30, 0x38(r1)
  /* 80537810 83A10034 */ lwz         r29, 0x34(r1)
  /* 80537814 80010044 */ lwz         r0, 0x44(r1)
  /* 80537818 D0210008 */ stfs        f1, 8(r1)
  /* 8053781C D021000C */ stfs        f1, 0xc(r1)
  /* 80537820 D0210010 */ stfs        f1, 0x10(r1)
  /* 80537824 7C0803A6 */ mtlr        r0
  /* 80537828 38210040 */ addi        r1, r1, 0x40
  /* 8053782C 4E800020 */ blr // clang-format on
}

// Symbol: VEC3_fromCross
// PAL: 0x80537830..0x8053787c
MARK_BINARY_BLOB(VEC3_fromCross, 0x80537830, 0x8053787c);
asm UNKNOWN_FUNCTION(VEC3_fromCross){
    // clang-format off
  nofralloc
  /* 80537830 C0040004 */ lfs         f0, 4(r4)
  /* 80537834 C0E50008 */ lfs         f7, 8(r5)
  /* 80537838 C0450000 */ lfs         f2, 0(r5)
  /* 8053783C C0840008 */ lfs         f4, 8(r4)
  /* 80537840 ECC001F2 */ fmuls       f6, f0, f7
  /* 80537844 C0A50004 */ lfs         f5, 4(r5)
  /* 80537848 EC0000B2 */ fmuls       f0, f0, f2
  /* 8053784C EC6400B2 */ fmuls       f3, f4, f2
  /* 80537850 C0240000 */ lfs         f1, 0(r4)
  /* 80537854 EC840172 */ fmuls       f4, f4, f5
  /* 80537858 EC4101F2 */ fmuls       f2, f1, f7
  /* 8053785C EC210172 */ fmuls       f1, f1, f5
  /* 80537860 EC862028 */ fsubs       f4, f6, f4
  /* 80537864 EC431028 */ fsubs       f2, f3, f2
  /* 80537868 EC010028 */ fsubs       f0, f1, f0
  /* 8053786C D0830000 */ stfs        f4, 0(r3)
  /* 80537870 D0430004 */ stfs        f2, 4(r3)
  /* 80537874 D0030008 */ stfs        f0, 8(r3)
  /* 80537878 4E800020 */ blr // clang-format on
}

// Symbol: unk_8053787c
// PAL: 0x8053787c..0x80537b80
MARK_BINARY_BLOB(unk_8053787c, 0x8053787c, 0x80537b80);
asm UNKNOWN_FUNCTION(unk_8053787c) {
  // clang-format off
  nofralloc
  /* 8053787C 9421FF50 */ stwu        r1, -0xb0(r1)
  /* 80537880 7C0802A6 */ mflr        r0
  /* 80537884 900100B4 */ stw         r0, 0xb4(r1)
  /* 80537888 396100B0 */ addi        r11, r1, 0xb0
  /* 8053788C 4BAE9D01 */ bl          _savegpr_22
  /* 80537890 3CE08089 */ lis         r7, lbl_80890218@ha
  /* 80537894 3F408089 */ lis         r26, lbl_8089021c@ha
  /* 80537898 C0270218 */ lfs         f1, lbl_80890218@l(r7)
  /* 8053789C 38E5FFFE */ addi        r7, r5, -0x2
  /* 805378A0 D021005C */ stfs        f1, 0x5c(r1)
  /* 805378A4 20050002 */ subfic      r0, r5, 0x2
  /* 805378A8 7CE700F8 */ nor         r7, r7, r0
  /* 805378AC C01A021C */ lfs         f0, lbl_8089021c@l(r26)
  /* 805378B0 D021006C */ stfs        f1, 0x6c(r1)
  /* 805378B4 38050001 */ addi        r0, r5, 0x1
  /* 805378B8 7CE7FE70 */ srawi       r7, r7, 0x1f
  /* 805378BC 7C7E1B78 */ mr          r30, r3
  /* 805378C0 D021007C */ stfs        f1, 0x7c(r1)
  /* 805378C4 7C193878 */ andc        r25, r0, r7
  /* 805378C8 3919FFFE */ addi        r8, r25, -0x2
  /* 805378CC 7C9F2378 */ mr          r31, r4
  /* 805378D0 C0460000 */ lfs         f2, 0(r6)
  /* 805378D4 20F90002 */ subfic      r7, r25, 0x2
  /* 805378D8 C0260004 */ lfs         f1, 4(r6)
  /* 805378DC 7D0738F8 */ nor         r7, r8, r7
  /* 805378E0 C0660008 */ lfs         f3, 8(r6)
  /* 805378E4 EC4200B2 */ fmuls       f2, f2, f2
  /* 805378E8 EC210072 */ fmuls       f1, f1, f1
  /* 805378EC 38190001 */ addi        r0, r25, 0x1
  /* 805378F0 EC6300F2 */ fmuls       f3, f3, f3
  /* 805378F4 7CE7FE70 */ srawi       r7, r7, 0x1f
  /* 805378F8 7CB62B78 */ mr          r22, r5
  /* 805378FC EC22082A */ fadds       f1, f2, f1
  /* 80537900 7CD73378 */ mr          r23, r6
  /* 80537904 7C183878 */ andc        r24, r0, r7
  /* 80537908 EC23082A */ fadds       f1, f3, f1
  /* 8053790C FC010040 */ opword      0xfc010040
  /* 80537910 4C401382 */ cror        2, 0, 2
  /* 80537914 7C000026 */ mfcr        r0
  /* 80537918 54001FFF */ rlwinm.     r0, r0, 3, 0x1f, 0x1f
  /* 8053791C 41820068 */ beq-        lbl_80537984
  /* 80537920 80A40000 */ lwz         r5, 0(r4)
  /* 80537924 80040004 */ lwz         r0, 4(r4)
  /* 80537928 90030004 */ stw         r0, 4(r3)
  /* 8053792C 90A30000 */ stw         r5, 0(r3)
  /* 80537930 80A40008 */ lwz         r5, 8(r4)
  /* 80537934 8004000C */ lwz         r0, 0xc(r4)
  /* 80537938 9003000C */ stw         r0, 0xc(r3)
  /* 8053793C 90A30008 */ stw         r5, 8(r3)
  /* 80537940 80A40010 */ lwz         r5, 0x10(r4)
  /* 80537944 80040014 */ lwz         r0, 0x14(r4)
  /* 80537948 90030014 */ stw         r0, 0x14(r3)
  /* 8053794C 90A30010 */ stw         r5, 0x10(r3)
  /* 80537950 80A40018 */ lwz         r5, 0x18(r4)
  /* 80537954 8004001C */ lwz         r0, 0x1c(r4)
  /* 80537958 9003001C */ stw         r0, 0x1c(r3)
  /* 8053795C 90A30018 */ stw         r5, 0x18(r3)
  /* 80537960 80A40020 */ lwz         r5, 0x20(r4)
  /* 80537964 80040024 */ lwz         r0, 0x24(r4)
  /* 80537968 90030024 */ stw         r0, 0x24(r3)
  /* 8053796C 90A30020 */ stw         r5, 0x20(r3)
  /* 80537970 80A40028 */ lwz         r5, 0x28(r4)
  /* 80537974 8004002C */ lwz         r0, 0x2c(r4)
  /* 80537978 9003002C */ stw         r0, 0x2c(r3)
  /* 8053797C 90A30028 */ stw         r5, 0x28(r3)
  /* 80537980 480001E8 */ b           lbl_80537b68
  lbl_80537984:
  /* 80537984 7EE3BB78 */ mr          r3, r23
  /* 80537988 4BD0C1E5 */ bl          normalise2__Q23EGG8Vector3fFv
  /* 8053798C 56C0103A */ slwi        r0, r22, 2
  /* 80537990 3B610050 */ addi        r27, r1, 0x50
  /* 80537994 C0170000 */ lfs         f0, 0(r23)
  /* 80537998 3B810060 */ addi        r28, r1, 0x60
  /* 8053799C 7C1B052E */ stfsx       f0, r27, r0
  /* 805379A0 3BA10070 */ addi        r29, r1, 0x70
  /* 805379A4 7FE4FB78 */ mr          r4, r31
  /* 805379A8 7F05C378 */ mr          r5, r24
  /* 805379AC C0170004 */ lfs         f0, 4(r23)
  /* 805379B0 38610044 */ addi        r3, r1, 0x44
  /* 805379B4 7C1C052E */ stfsx       f0, r28, r0
  /* 805379B8 C0170008 */ lfs         f0, 8(r23)
  /* 805379BC 7C1D052E */ stfsx       f0, r29, r0
  /* 805379C0 480001C1 */ bl          unk_80537b80
  /* 805379C4 7F64DB78 */ mr          r4, r27
  /* 805379C8 7EC5B378 */ mr          r5, r22
  /* 805379CC 38610038 */ addi        r3, r1, 0x38
  /* 805379D0 480001B1 */ bl          unk_80537b80
  /* 805379D4 3861002C */ addi        r3, r1, 0x2c
  /* 805379D8 38810044 */ addi        r4, r1, 0x44
  /* 805379DC 38A10038 */ addi        r5, r1, 0x38
  /* 805379E0 4BFFFE51 */ bl          VEC3_fromCross
  /* 805379E4 C001002C */ lfs         f0, 0x2c(r1)
  /* 805379E8 D0170000 */ stfs        f0, 0(r23)
  /* 805379EC EC400032 */ fmuls       f2, f0, f0
  /* 805379F0 C01A021C */ lfs         f0, lbl_8089021c@l(r26)
  /* 805379F4 C0210030 */ lfs         f1, 0x30(r1)
  /* 805379F8 D0370004 */ stfs        f1, 4(r23)
  /* 805379FC EC210072 */ fmuls       f1, f1, f1
  /* 80537A00 C0610034 */ lfs         f3, 0x34(r1)
  /* 80537A04 D0770008 */ stfs        f3, 8(r23)
  /* 80537A08 EC6300F2 */ fmuls       f3, f3, f3
  /* 80537A0C EC22082A */ fadds       f1, f2, f1
  /* 80537A10 EC23082A */ fadds       f1, f3, f1
  /* 80537A14 FC010040 */ opword      0xfc010040
  /* 80537A18 4C401382 */ cror        2, 0, 2
  /* 80537A1C 7C000026 */ mfcr        r0
  /* 80537A20 54001FFF */ rlwinm.     r0, r0, 3, 0x1f, 0x1f
  /* 80537A24 41820068 */ beq-        lbl_80537a8c
  /* 80537A28 807F0000 */ lwz         r3, 0(r31)
  /* 80537A2C 801F0004 */ lwz         r0, 4(r31)
  /* 80537A30 901E0004 */ stw         r0, 4(r30)
  /* 80537A34 907E0000 */ stw         r3, 0(r30)
  /* 80537A38 807F0008 */ lwz         r3, 8(r31)
  /* 80537A3C 801F000C */ lwz         r0, 0xc(r31)
  /* 80537A40 901E000C */ stw         r0, 0xc(r30)
  /* 80537A44 907E0008 */ stw         r3, 8(r30)
  /* 80537A48 807F0010 */ lwz         r3, 0x10(r31)
  /* 80537A4C 801F0014 */ lwz         r0, 0x14(r31)
  /* 80537A50 901E0014 */ stw         r0, 0x14(r30)
  /* 80537A54 907E0010 */ stw         r3, 0x10(r30)
  /* 80537A58 807F0018 */ lwz         r3, 0x18(r31)
  /* 80537A5C 801F001C */ lwz         r0, 0x1c(r31)
  /* 80537A60 901E001C */ stw         r0, 0x1c(r30)
  /* 80537A64 907E0018 */ stw         r3, 0x18(r30)
  /* 80537A68 807F0020 */ lwz         r3, 0x20(r31)
  /* 80537A6C 801F0024 */ lwz         r0, 0x24(r31)
  /* 80537A70 901E0024 */ stw         r0, 0x24(r30)
  /* 80537A74 907E0020 */ stw         r3, 0x20(r30)
  /* 80537A78 807F0028 */ lwz         r3, 0x28(r31)
  /* 80537A7C 801F002C */ lwz         r0, 0x2c(r31)
  /* 80537A80 901E002C */ stw         r0, 0x2c(r30)
  /* 80537A84 907E0028 */ stw         r3, 0x28(r30)
  /* 80537A88 480000E0 */ b           lbl_80537b68
  lbl_80537a8c:
  /* 80537A8C 7EE3BB78 */ mr          r3, r23
  /* 80537A90 4BD0C0DD */ bl          normalise2__Q23EGG8Vector3fFv
  /* 80537A94 5720103A */ slwi        r0, r25, 2
  /* 80537A98 C0170000 */ lfs         f0, 0(r23)
  /* 80537A9C 7C1B052E */ stfsx       f0, r27, r0
  /* 80537AA0 7F64DB78 */ mr          r4, r27
  /* 80537AA4 7EC5B378 */ mr          r5, r22
  /* 80537AA8 38610020 */ addi        r3, r1, 0x20
  /* 80537AAC C0170004 */ lfs         f0, 4(r23)
  /* 80537AB0 7C1C052E */ stfsx       f0, r28, r0
  /* 80537AB4 C0170008 */ lfs         f0, 8(r23)
  /* 80537AB8 7C1D052E */ stfsx       f0, r29, r0
  /* 80537ABC 480000C5 */ bl          unk_80537b80
  /* 80537AC0 7F64DB78 */ mr          r4, r27
  /* 80537AC4 7F25CB78 */ mr          r5, r25
  /* 80537AC8 38610014 */ addi        r3, r1, 0x14
  /* 80537ACC 480000B5 */ bl          unk_80537b80
  /* 80537AD0 38610008 */ addi        r3, r1, 0x8
  /* 80537AD4 38810020 */ addi        r4, r1, 0x20
  /* 80537AD8 38A10014 */ addi        r5, r1, 0x14
  /* 80537ADC 4BFFFD55 */ bl          VEC3_fromCross
  /* 80537AE0 C0410008 */ lfs         f2, 8(r1)
  /* 80537AE4 5700103A */ slwi        r0, r24, 2
  /* 80537AE8 D0570000 */ stfs        f2, 0(r23)
  /* 80537AEC C021000C */ lfs         f1, 0xc(r1)
  /* 80537AF0 D0370004 */ stfs        f1, 4(r23)
  /* 80537AF4 C0010010 */ lfs         f0, 0x10(r1)
  /* 80537AF8 D0170008 */ stfs        f0, 8(r23)
  /* 80537AFC 7C5B052E */ stfsx       f2, r27, r0
  /* 80537B00 7C3C052E */ stfsx       f1, r28, r0
  /* 80537B04 7C1D052E */ stfsx       f0, r29, r0
  /* 80537B08 80610050 */ lwz         r3, 0x50(r1)
  /* 80537B0C 80010054 */ lwz         r0, 0x54(r1)
  /* 80537B10 901E0004 */ stw         r0, 4(r30)
  /* 80537B14 907E0000 */ stw         r3, 0(r30)
  /* 80537B18 80610058 */ lwz         r3, 0x58(r1)
  /* 80537B1C 8001005C */ lwz         r0, 0x5c(r1)
  /* 80537B20 901E000C */ stw         r0, 0xc(r30)
  /* 80537B24 907E0008 */ stw         r3, 8(r30)
  /* 80537B28 80610060 */ lwz         r3, 0x60(r1)
  /* 80537B2C 80010064 */ lwz         r0, 0x64(r1)
  /* 80537B30 901E0014 */ stw         r0, 0x14(r30)
  /* 80537B34 907E0010 */ stw         r3, 0x10(r30)
  /* 80537B38 80610068 */ lwz         r3, 0x68(r1)
  /* 80537B3C 8001006C */ lwz         r0, 0x6c(r1)
  /* 80537B40 901E001C */ stw         r0, 0x1c(r30)
  /* 80537B44 907E0018 */ stw         r3, 0x18(r30)
  /* 80537B48 80610070 */ lwz         r3, 0x70(r1)
  /* 80537B4C 80010074 */ lwz         r0, 0x74(r1)
  /* 80537B50 901E0024 */ stw         r0, 0x24(r30)
  /* 80537B54 907E0020 */ stw         r3, 0x20(r30)
  /* 80537B58 80610078 */ lwz         r3, 0x78(r1)
  /* 80537B5C 8001007C */ lwz         r0, 0x7c(r1)
  /* 80537B60 901E002C */ stw         r0, 0x2c(r30)
  /* 80537B64 907E0028 */ stw         r3, 0x28(r30)
  lbl_80537b68:
  /* 80537B68 396100B0 */ addi        r11, r1, 0xb0
  /* 80537B6C 4BAE9A6D */ bl          _restgpr_22
  /* 80537B70 800100B4 */ lwz         r0, 0xb4(r1)
  /* 80537B74 7C0803A6 */ mtlr        r0
  /* 80537B78 382100B0 */ addi        r1, r1, 0xb0
  /* 80537B7C 4E800020 */ blr // clang-format on
}

// Symbol: unk_80537b80
// PAL: 0x80537b80..0x80537ba4
MARK_BINARY_BLOB(unk_80537b80, 0x80537b80, 0x80537ba4);
asm UNKNOWN_FUNCTION(unk_80537b80){
    // clang-format off
  nofralloc
  /* 80537B80 54A0103A */ slwi        r0, r5, 2
  /* 80537B84 7CA40214 */ add         r5, r4, r0
  /* 80537B88 7C04042E */ lfsx        f0, r4, r0
  /* 80537B8C C0250010 */ lfs         f1, 0x10(r5)
  /* 80537B90 C0450020 */ lfs         f2, 0x20(r5)
  /* 80537B94 D0030000 */ stfs        f0, 0(r3)
  /* 80537B98 D0230004 */ stfs        f1, 4(r3)
  /* 80537B9C D0430008 */ stfs        f2, 8(r3)
  /* 80537BA0 4E800020 */ blr // clang-format on
}

// Symbol: unk_80537ba4
// PAL: 0x80537ba4..0x80537c54
MARK_BINARY_BLOB(unk_80537ba4, 0x80537ba4, 0x80537c54);
asm UNKNOWN_FUNCTION(unk_80537ba4) {
  // clang-format off
  nofralloc
  /* 80537BA4 9421FF90 */ stwu        r1, -0x70(r1)
  /* 80537BA8 7C0802A6 */ mflr        r0
  /* 80537BAC 90010074 */ stw         r0, 0x74(r1)
  /* 80537BB0 DBE10060 */ stfd        f31, 0x60(r1)
  /* 80537BB4 F3E10068 */ opword      0xf3e10068
  /* 80537BB8 3CC08089 */ lis         r6, lbl_80890218@ha
  /* 80537BBC 3CA08089 */ lis         r5, lbl_80890220@ha
  /* 80537BC0 C0460218 */ lfs         f2, lbl_80890218@l(r6)
  /* 80537BC4 FFE00890 */ fmr         f31, f1
  /* 80537BC8 C0050220 */ lfs         f0, lbl_80890220@l(r5)
  /* 80537BCC 39800000 */ li          r12, 0x0
  /* 80537BD0 81630000 */ lwz         r11, 0(r3)
  /* 80537BD4 3CC020E8 */ lis         r6, 0x20e8
  /* 80537BD8 81430004 */ lwz         r10, 4(r3)
  /* 80537BDC 80030008 */ lwz         r0, 8(r3)
  /* 80537BE0 7C892378 */ mr          r9, r4
  /* 80537BE4 D0410030 */ stfs        f2, 0x30(r1)
  /* 80537BE8 3861000C */ addi        r3, r1, 0xc
  /* 80537BEC 38810024 */ addi        r4, r1, 0x24
  /* 80537BF0 38A10018 */ addi        r5, r1, 0x18
  /* 80537BF4 D0410034 */ stfs        f2, 0x34(r1)
  /* 80537BF8 38C60FFF */ addi        r6, r6, 0xfff
  /* 80537BFC 38E10030 */ addi        r7, r1, 0x30
  /* 80537C00 39010008 */ addi        r8, r1, 0x8
  /* 80537C04 D0410038 */ stfs        f2, 0x38(r1)
  /* 80537C08 D041003C */ stfs        f2, 0x3c(r1)
  /* 80537C0C D0410040 */ stfs        f2, 0x40(r1)
  /* 80537C10 D0410044 */ stfs        f2, 0x44(r1)
  /* 80537C14 91810008 */ stw         r12, 8(r1)
  /* 80537C18 91610024 */ stw         r11, 0x24(r1)
  /* 80537C1C 91410028 */ stw         r10, 0x28(r1)
  /* 80537C20 9001002C */ stw         r0, 0x2c(r1)
  /* 80537C24 D0410018 */ stfs        f2, 0x18(r1)
  /* 80537C28 D001001C */ stfs        f0, 0x1c(r1)
  /* 80537C2C D0410020 */ stfs        f2, 0x20(r1)
  /* 80537C30 480000A5 */ bl          unk_80537cd4
  /* 80537C34 C0010010 */ lfs         f0, 0x10(r1)
  /* 80537C38 EC20F828 */ fsubs       f1, f0, f31
  /* 80537C3C E3E10068 */ opword      0xe3e10068
  /* 80537C40 CBE10060 */ lfd         f31, 0x60(r1)
  /* 80537C44 80010074 */ lwz         r0, 0x74(r1)
  /* 80537C48 7C0803A6 */ mtlr        r0
  /* 80537C4C 38210070 */ addi        r1, r1, 0x70
  /* 80537C50 4E800020 */ blr // clang-format on
}

// Symbol: unk_80537c54
// PAL: 0x80537c54..0x80537c94
MARK_BINARY_BLOB(unk_80537c54, 0x80537c54, 0x80537c94);
asm UNKNOWN_FUNCTION(unk_80537c54){
  // clang-format off
  nofralloc
  /* 80537C54 9421FFF0 */ stwu        r1, -0x10(r1)
  /* 80537C58 7C0802A6 */ mflr        r0
  /* 80537C5C 2C030000 */ cmpwi       r3, 0x0
  /* 80537C60 90010014 */ stw         r0, 0x14(r1)
  /* 80537C64 93E1000C */ stw         r31, 0xc(r1)
  /* 80537C68 7C7F1B78 */ mr          r31, r3
  /* 80537C6C 41820010 */ beq-        lbl_80537c7c
  /* 80537C70 2C040000 */ cmpwi       r4, 0x0
  /* 80537C74 40810008 */ ble-        lbl_80537c7c
  /* 80537C78 4BCF219D */ bl          __dl__FPv
  lbl_80537c7c:
  /* 80537C7C 7FE3FB78 */ mr          r3, r31
  /* 80537C80 83E1000C */ lwz         r31, 0xc(r1)
  /* 80537C84 80010014 */ lwz         r0, 0x14(r1)
  /* 80537C88 7C0803A6 */ mtlr        r0
  /* 80537C8C 38210010 */ addi        r1, r1, 0x10
  /* 80537C90 4E800020 */ blr // clang-format on
}

// Symbol: unk_80537c94
// PAL: 0x80537c94..0x80537cd4
MARK_BINARY_BLOB(unk_80537c94, 0x80537c94, 0x80537cd4);
asm UNKNOWN_FUNCTION(unk_80537c94){
  // clang-format off
  nofralloc
  /* 80537C94 9421FFF0 */ stwu        r1, -0x10(r1)
  /* 80537C98 7C0802A6 */ mflr        r0
  /* 80537C9C 2C030000 */ cmpwi       r3, 0x0
  /* 80537CA0 90010014 */ stw         r0, 0x14(r1)
  /* 80537CA4 93E1000C */ stw         r31, 0xc(r1)
  /* 80537CA8 7C7F1B78 */ mr          r31, r3
  /* 80537CAC 41820010 */ beq-        lbl_80537cbc
  /* 80537CB0 2C040000 */ cmpwi       r4, 0x0
  /* 80537CB4 40810008 */ ble-        lbl_80537cbc
  /* 80537CB8 4BCF215D */ bl          __dl__FPv
  lbl_80537cbc:
  /* 80537CBC 7FE3FB78 */ mr          r3, r31
  /* 80537CC0 83E1000C */ lwz         r31, 0xc(r1)
  /* 80537CC4 80010014 */ lwz         r0, 0x14(r1)
  /* 80537CC8 7C0803A6 */ mtlr        r0
  /* 80537CCC 38210010 */ addi        r1, r1, 0x10
  /* 80537CD0 4E800020 */ blr // clang-format on
}

// Symbol: unk_80537cd4
// PAL: 0x80537cd4..0x80537f98
MARK_BINARY_BLOB(unk_80537cd4, 0x80537cd4, 0x80537f98);
asm UNKNOWN_FUNCTION(unk_80537cd4) {
  #include "asm/80537cd4.s"
}

// Symbol: unk_80537f98
// PAL: 0x80537f98..0x80538084
MARK_BINARY_BLOB(unk_80537f98, 0x80537f98, 0x80538084);
asm UNKNOWN_FUNCTION(unk_80537f98) {
  // clang-format off
  nofralloc
  /* 80537F98 9421FFE0 */ stwu        r1, -0x20(r1)
  /* 80537F9C 7C0802A6 */ mflr        r0
  /* 80537FA0 90010024 */ stw         r0, 0x24(r1)
  /* 80537FA4 DBE10010 */ stfd        f31, 0x10(r1)
  /* 80537FA8 F3E10018 */ opword      0xf3e10018
  /* 80537FAC FFE00890 */ fmr         f31, f1
  /* 80537FB0 93E1000C */ stw         r31, 0xc(r1)
  /* 80537FB4 7C9F2378 */ mr          r31, r4
  /* 80537FB8 93C10008 */ stw         r30, 8(r1)
  /* 80537FBC 7C7E1B78 */ mr          r30, r3
  /* 80537FC0 C0440000 */ lfs         f2, 0(r4)
  /* 80537FC4 C0040004 */ lfs         f0, 4(r4)
  /* 80537FC8 EC2200B2 */ fmuls       f1, f2, f2
  /* 80537FCC C0440008 */ lfs         f2, 8(r4)
  /* 80537FD0 EC000032 */ fmuls       f0, f0, f0
  /* 80537FD4 EC4200B2 */ fmuls       f2, f2, f2
  /* 80537FD8 EC01002A */ fadds       f0, f1, f0
  /* 80537FDC EC22002A */ fadds       f1, f2, f0
  /* 80537FE0 4BCF782D */ bl          sqrt__Q23EGG5MathfFf
  /* 80537FE4 3C608089 */ lis         r3, lbl_80890218@ha
  /* 80537FE8 EFFF0828 */ fsubs       f31, f31, f1
  /* 80537FEC C0030218 */ lfs         f0, lbl_80890218@l(r3)
  /* 80537FF0 FC00F840 */ opword      0xfc00f840
  /* 80537FF4 4080005C */ bge-        lbl_80538050
  /* 80537FF8 C03F0000 */ lfs         f1, 0(r31)
  /* 80537FFC 3C608089 */ lis         r3, lbl_8089021c@ha
  /* 80538000 C01F0004 */ lfs         f0, 4(r31)
  /* 80538004 EC410072 */ fmuls       f2, f1, f1
  /* 80538008 C07F0008 */ lfs         f3, 8(r31)
  /* 8053800C EC200032 */ fmuls       f1, f0, f0
  /* 80538010 C003021C */ lfs         f0, lbl_8089021c@l(r3)
  /* 80538014 EC6300F2 */ fmuls       f3, f3, f3
  /* 80538018 EC22082A */ fadds       f1, f2, f1
  /* 8053801C EC23082A */ fadds       f1, f3, f1
  /* 80538020 FC010040 */ opword      0xfc010040
  /* 80538024 4C401382 */ cror        2, 0, 2
  /* 80538028 7C000026 */ mfcr        r0
  /* 8053802C 54001FFF */ rlwinm.     r0, r0, 3, 0x1f, 0x1f
  /* 80538030 40820020 */ bne-        lbl_80538050
  /* 80538034 7FE3FB78 */ mr          r3, r31
  /* 80538038 4BD0BB35 */ bl          normalise2__Q23EGG8Vector3fFv
  /* 8053803C FC20F890 */ fmr         f1, f31
  /* 80538040 7FC3F378 */ mr          r3, r30
  /* 80538044 7FE4FB78 */ mr          r4, r31
  /* 80538048 4BFDC7C9 */ bl          Vec3_scale
  /* 8053804C 48000018 */ b           lbl_80538064
  lbl_80538050:
  /* 80538050 3C608089 */ lis         r3, lbl_80890218@ha
  /* 80538054 C0030218 */ lfs         f0, lbl_80890218@l(r3)
  /* 80538058 D01E0000 */ stfs        f0, 0(r30)
  /* 8053805C D01E0004 */ stfs        f0, 4(r30)
  /* 80538060 D01E0008 */ stfs        f0, 8(r30)
  lbl_80538064:
  /* 80538064 E3E10018 */ opword      0xe3e10018
  /* 80538068 80010024 */ lwz         r0, 0x24(r1)
  /* 8053806C CBE10010 */ lfd         f31, 0x10(r1)
  /* 80538070 83E1000C */ lwz         r31, 0xc(r1)
  /* 80538074 83C10008 */ lwz         r30, 8(r1)
  /* 80538078 7C0803A6 */ mtlr        r0
  /* 8053807C 38210020 */ addi        r1, r1, 0x20
  /* 80538080 4E800020 */ blr // clang-format on
}

// Symbol: unk_80538084
// PAL: 0x80538084..0x80538170
MARK_BINARY_BLOB(unk_80538084, 0x80538084, 0x80538170);
asm UNKNOWN_FUNCTION(unk_80538084) {
  // clang-format off
  nofralloc
  /* 80538084 9421FFE0 */ stwu        r1, -0x20(r1)
  /* 80538088 7C0802A6 */ mflr        r0
  /* 8053808C 90010024 */ stw         r0, 0x24(r1)
  /* 80538090 DBE10010 */ stfd        f31, 0x10(r1)
  /* 80538094 F3E10018 */ opword      0xf3e10018
  /* 80538098 FFE00890 */ fmr         f31, f1
  /* 8053809C 93E1000C */ stw         r31, 0xc(r1)
  /* 805380A0 7C9F2378 */ mr          r31, r4
  /* 805380A4 93C10008 */ stw         r30, 8(r1)
  /* 805380A8 7C7E1B78 */ mr          r30, r3
  /* 805380AC C0440000 */ lfs         f2, 0(r4)
  /* 805380B0 C0040004 */ lfs         f0, 4(r4)
  /* 805380B4 EC2200B2 */ fmuls       f1, f2, f2
  /* 805380B8 C0440008 */ lfs         f2, 8(r4)
  /* 805380BC EC000032 */ fmuls       f0, f0, f0
  /* 805380C0 EC4200B2 */ fmuls       f2, f2, f2
  /* 805380C4 EC01002A */ fadds       f0, f1, f0
  /* 805380C8 EC22002A */ fadds       f1, f2, f0
  /* 805380CC 4BCF7741 */ bl          sqrt__Q23EGG5MathfFf
  /* 805380D0 3C608089 */ lis         r3, lbl_80890218@ha
  /* 805380D4 EFE1F828 */ fsubs       f31, f1, f31
  /* 805380D8 C0030218 */ lfs         f0, lbl_80890218@l(r3)
  /* 805380DC FC00F840 */ opword      0xfc00f840
  /* 805380E0 4080005C */ bge-        lbl_8053813c
  /* 805380E4 C03F0000 */ lfs         f1, 0(r31)
  /* 805380E8 3C608089 */ lis         r3, lbl_8089021c@ha
  /* 805380EC C01F0004 */ lfs         f0, 4(r31)
  /* 805380F0 EC410072 */ fmuls       f2, f1, f1
  /* 805380F4 C07F0008 */ lfs         f3, 8(r31)
  /* 805380F8 EC200032 */ fmuls       f1, f0, f0
  /* 805380FC C003021C */ lfs         f0, lbl_8089021c@l(r3)
  /* 80538100 EC6300F2 */ fmuls       f3, f3, f3
  /* 80538104 EC22082A */ fadds       f1, f2, f1
  /* 80538108 EC23082A */ fadds       f1, f3, f1
  /* 8053810C FC010040 */ opword      0xfc010040
  /* 80538110 4C401382 */ cror        2, 0, 2
  /* 80538114 7C000026 */ mfcr        r0
  /* 80538118 54001FFF */ rlwinm.     r0, r0, 3, 0x1f, 0x1f
  /* 8053811C 40820020 */ bne-        lbl_8053813c
  /* 80538120 7FE3FB78 */ mr          r3, r31
  /* 80538124 4BD0BA49 */ bl          normalise2__Q23EGG8Vector3fFv
  /* 80538128 FC20F890 */ fmr         f1, f31
  /* 8053812C 7FC3F378 */ mr          r3, r30
  /* 80538130 7FE4FB78 */ mr          r4, r31
  /* 80538134 4BFDC6DD */ bl          Vec3_scale
  /* 80538138 48000018 */ b           lbl_80538150
  lbl_8053813c:
  /* 8053813C 3C608089 */ lis         r3, lbl_80890218@ha
  /* 80538140 C0030218 */ lfs         f0, lbl_80890218@l(r3)
  /* 80538144 D01E0000 */ stfs        f0, 0(r30)
  /* 80538148 D01E0004 */ stfs        f0, 4(r30)
  /* 8053814C D01E0008 */ stfs        f0, 8(r30)
  lbl_80538150:
  /* 80538150 E3E10018 */ opword      0xe3e10018
  /* 80538154 80010024 */ lwz         r0, 0x24(r1)
  /* 80538158 CBE10010 */ lfd         f31, 0x10(r1)
  /* 8053815C 83E1000C */ lwz         r31, 0xc(r1)
  /* 80538160 83C10008 */ lwz         r30, 8(r1)
  /* 80538164 7C0803A6 */ mtlr        r0
  /* 80538168 38210020 */ addi        r1, r1, 0x20
  /* 8053816C 4E800020 */ blr // clang-format on
}

// Symbol: unk_80538170
// PAL: 0x80538170..0x805381a4
MARK_BINARY_BLOB(unk_80538170, 0x80538170, 0x805381a4);
asm UNKNOWN_FUNCTION(unk_80538170){
    // clang-format off
  nofralloc
  /* 80538170 C0650000 */ lfs         f3, 0(r5)
  /* 80538174 C0440000 */ lfs         f2, 0(r4)
  /* 80538178 C0250004 */ lfs         f1, 4(r5)
  /* 8053817C C0040004 */ lfs         f0, 4(r4)
  /* 80538180 EC4300B2 */ fmuls       f2, f3, f2
  /* 80538184 C0640008 */ lfs         f3, 8(r4)
  /* 80538188 7CA42B78 */ mr          r4, r5
  /* 8053818C EC010032 */ fmuls       f0, f1, f0
  /* 80538190 C0250008 */ lfs         f1, 8(r5)
  /* 80538194 EC2100F2 */ fmuls       f1, f1, f3
  /* 80538198 EC02002A */ fadds       f0, f2, f0
  /* 8053819C EC21002A */ fadds       f1, f1, f0
  /* 805381A0 4BFDC670 */ b           Vec3_scale // clang-format on
}

// Symbol: unk_805381a4
// PAL: 0x805381a4..0x80538220
MARK_BINARY_BLOB(unk_805381a4, 0x805381a4, 0x80538220);
asm UNKNOWN_FUNCTION(unk_805381a4){
    // clang-format off
  nofralloc
  /* 805381A4 9421FFE0 */ stwu        r1, -0x20(r1)
  /* 805381A8 7C0802A6 */ mflr        r0
  /* 805381AC 90010024 */ stw         r0, 0x24(r1)
  /* 805381B0 93E1001C */ stw         r31, 0x1c(r1)
  /* 805381B4 7C9F2378 */ mr          r31, r4
  /* 805381B8 93C10018 */ stw         r30, 0x18(r1)
  /* 805381BC 7C7E1B78 */ mr          r30, r3
  /* 805381C0 38610008 */ addi        r3, r1, 0x8
  /* 805381C4 C0650000 */ lfs         f3, 0(r5)
  /* 805381C8 C0440000 */ lfs         f2, 0(r4)
  /* 805381CC C0250004 */ lfs         f1, 4(r5)
  /* 805381D0 C0040004 */ lfs         f0, 4(r4)
  /* 805381D4 EC4300B2 */ fmuls       f2, f3, f2
  /* 805381D8 C0640008 */ lfs         f3, 8(r4)
  /* 805381DC 7CA42B78 */ mr          r4, r5
  /* 805381E0 EC010032 */ fmuls       f0, f1, f0
  /* 805381E4 C0250008 */ lfs         f1, 8(r5)
  /* 805381E8 EC2100F2 */ fmuls       f1, f1, f3
  /* 805381EC EC02002A */ fadds       f0, f2, f0
  /* 805381F0 EC21002A */ fadds       f1, f1, f0
  /* 805381F4 4BFDC61D */ bl          Vec3_scale
  /* 805381F8 7FC3F378 */ mr          r3, r30
  /* 805381FC 7FE4FB78 */ mr          r4, r31
  /* 80538200 38A10008 */ addi        r5, r1, 0x8
  /* 80538204 4BFDC669 */ bl          VEC3_sub
  /* 80538208 80010024 */ lwz         r0, 0x24(r1)
  /* 8053820C 83E1001C */ lwz         r31, 0x1c(r1)
  /* 80538210 83C10018 */ lwz         r30, 0x18(r1)
  /* 80538214 7C0803A6 */ mtlr        r0
  /* 80538218 38210020 */ addi        r1, r1, 0x20
  /* 8053821C 4E800020 */ blr // clang-format on
}

// Symbol: unk_80538220
// PAL: 0x80538220..0x8053831c
MARK_BINARY_BLOB(unk_80538220, 0x80538220, 0x8053831c);
asm UNKNOWN_FUNCTION(unk_80538220) {
  // clang-format off
  nofralloc
  /* 80538220 9421FFD0 */ stwu        r1, -0x30(r1)
  /* 80538224 7C0802A6 */ mflr        r0
  /* 80538228 3CC08089 */ lis         r6, lbl_8089021c@ha
  /* 8053822C 90010034 */ stw         r0, 0x34(r1)
  /* 80538230 C006021C */ lfs         f0, lbl_8089021c@l(r6)
  /* 80538234 93E1002C */ stw         r31, 0x2c(r1)
  /* 80538238 7C9F2378 */ mr          r31, r4
  /* 8053823C 93C10028 */ stw         r30, 0x28(r1)
  /* 80538240 7C7E1B78 */ mr          r30, r3
  /* 80538244 C0840000 */ lfs         f4, 0(r4)
  /* 80538248 C0A40004 */ lfs         f5, 4(r4)
  /* 8053824C EC640132 */ fmuls       f3, f4, f4
  /* 80538250 C0E40008 */ lfs         f7, 8(r4)
  /* 80538254 EC450172 */ fmuls       f2, f5, f5
  /* 80538258 ECC701F2 */ fmuls       f6, f7, f7
  /* 8053825C EC43102A */ fadds       f2, f3, f2
  /* 80538260 EC46102A */ fadds       f2, f6, f2
  /* 80538264 FC020040 */ opword      0xfc020040
  /* 80538268 4C401382 */ cror        2, 0, 2
  /* 8053826C 7C000026 */ mfcr        r0
  /* 80538270 54001FFF */ rlwinm.     r0, r0, 3, 0x1f, 0x1f
  /* 80538274 4182001C */ beq-        lbl_80538290
  /* 80538278 3C808089 */ lis         r4, lbl_80890218@ha
  /* 8053827C C0040218 */ lfs         f0, lbl_80890218@l(r4)
  /* 80538280 D0030000 */ stfs        f0, 0(r3)
  /* 80538284 D0030004 */ stfs        f0, 4(r3)
  /* 80538288 D0030008 */ stfs        f0, 8(r3)
  /* 8053828C 48000078 */ b           lbl_80538304
  lbl_80538290:
  /* 80538290 C0450000 */ lfs         f2, 0(r5)
  /* 80538294 3C608089 */ lis         r3, lbl_80890218@ha
  /* 80538298 C0050004 */ lfs         f0, 4(r5)
  /* 8053829C EC620132 */ fmuls       f3, f2, f4
  /* 805382A0 C0850008 */ lfs         f4, 8(r5)
  /* 805382A4 EC400172 */ fmuls       f2, f0, f5
  /* 805382A8 C0030218 */ lfs         f0, lbl_80890218@l(r3)
  /* 805382AC EC8401F2 */ fmuls       f4, f4, f7
  /* 805382B0 EC43102A */ fadds       f2, f3, f2
  /* 805382B4 EC44102A */ fadds       f2, f4, f2
  /* 805382B8 FC401050 */ fneg        f2, f2
  /* 805382BC FC001040 */ opword      0xfc001040
  /* 805382C0 4080002C */ bge-        lbl_805382ec
  /* 805382C4 EC020072 */ fmuls       f0, f2, f1
  /* 805382C8 7CA42B78 */ mr          r4, r5
  /* 805382CC 38610014 */ addi        r3, r1, 0x14
  /* 805382D0 EC22002A */ fadds       f1, f2, f0
  /* 805382D4 4BFDC53D */ bl          Vec3_scale
  /* 805382D8 7FE4FB78 */ mr          r4, r31
  /* 805382DC 38610008 */ addi        r3, r1, 0x8
  /* 805382E0 38A10014 */ addi        r5, r1, 0x14
  /* 805382E4 4BFDC555 */ bl          Vec3_add
  /* 805382E8 3BE10008 */ addi        r31, r1, 0x8
  lbl_805382ec:
  /* 805382EC 807F0000 */ lwz         r3, 0(r31)
  /* 805382F0 801F0004 */ lwz         r0, 4(r31)
  /* 805382F4 901E0004 */ stw         r0, 4(r30)
  /* 805382F8 907E0000 */ stw         r3, 0(r30)
  /* 805382FC 801F0008 */ lwz         r0, 8(r31)
  /* 80538300 901E0008 */ stw         r0, 8(r30)
  lbl_80538304:
  /* 80538304 80010034 */ lwz         r0, 0x34(r1)
  /* 80538308 83E1002C */ lwz         r31, 0x2c(r1)
  /* 8053830C 83C10028 */ lwz         r30, 0x28(r1)
  /* 80538310 7C0803A6 */ mtlr        r0
  /* 80538314 38210030 */ addi        r1, r1, 0x30
  /* 80538318 4E800020 */ blr // clang-format on
}

// Symbol: unk_8053831c
// PAL: 0x8053831c..0x80538344
MARK_BINARY_BLOB(unk_8053831c, 0x8053831c, 0x80538344);
asm UNKNOWN_FUNCTION(unk_8053831c){
  // clang-format off
  nofralloc
  /* 8053831C 2C040000 */ cmpwi       r4, 0x0
  /* 80538320 90830004 */ stw         r4, 4(r3)
  /* 80538324 41820014 */ beq-        lbl_80538338
  /* 80538328 80840000 */ lwz         r4, 0(r4)
  /* 8053832C 3C04ADB5 */ addis       r0, r4, 0xadb5
  /* 80538330 28004D47 */ cmplwi      r0, 0x4d47
  /* 80538334 4D820020 */ beqlr-
  lbl_80538338:
  /* 80538338 38000000 */ li          r0, 0x0
  /* 8053833C 90030004 */ stw         r0, 4(r3)
  /* 80538340 4E800020 */ blr // clang-format on
}

// Symbol: unk_80538344
// PAL: 0x80538344..0x80538418
MARK_BINARY_BLOB(unk_80538344, 0x80538344, 0x80538418);
asm UNKNOWN_FUNCTION(unk_80538344) {
  // clang-format off
  nofralloc
  /* 80538344 3C608089 */ lis         r3, lbl_80890238@ha
  /* 80538348 84030238 */ lwzu        r0, lbl_80890238@l(r3)
  /* 8053834C 7C040000 */ cmpw        r4, r0
  /* 80538350 4082000C */ bne-        lbl_8053835c
  /* 80538354 38600000 */ li          r3, 0x0
  /* 80538358 4E800020 */ blr
  lbl_8053835c:
  /* 8053835C 80030004 */ lwz         r0, 4(r3)
  /* 80538360 7C040000 */ cmpw        r4, r0
  /* 80538364 4082000C */ bne-        lbl_80538370
  /* 80538368 38600001 */ li          r3, 0x1
  /* 8053836C 4E800020 */ blr
  lbl_80538370:
  /* 80538370 80030008 */ lwz         r0, 8(r3)
  /* 80538374 7C040000 */ cmpw        r4, r0
  /* 80538378 4082000C */ bne-        lbl_80538384
  /* 8053837C 38600002 */ li          r3, 0x2
  /* 80538380 4E800020 */ blr
  lbl_80538384:
  /* 80538384 8003000C */ lwz         r0, 0xc(r3)
  /* 80538388 7C040000 */ cmpw        r4, r0
  /* 8053838C 4082000C */ bne-        lbl_80538398
  /* 80538390 38600003 */ li          r3, 0x3
  /* 80538394 4E800020 */ blr
  lbl_80538398:
  /* 80538398 80030010 */ lwz         r0, 0x10(r3)
  /* 8053839C 7C040000 */ cmpw        r4, r0
  /* 805383A0 4082000C */ bne-        lbl_805383ac
  /* 805383A4 38600004 */ li          r3, 0x4
  /* 805383A8 4E800020 */ blr
  lbl_805383ac:
  /* 805383AC 80030014 */ lwz         r0, 0x14(r3)
  /* 805383B0 7C040000 */ cmpw        r4, r0
  /* 805383B4 4082000C */ bne-        lbl_805383c0
  /* 805383B8 38600005 */ li          r3, 0x5
  /* 805383BC 4E800020 */ blr
  lbl_805383c0:
  /* 805383C0 80030018 */ lwz         r0, 0x18(r3)
  /* 805383C4 7C040000 */ cmpw        r4, r0
  /* 805383C8 4082000C */ bne-        lbl_805383d4
  /* 805383CC 38600006 */ li          r3, 0x6
  /* 805383D0 4E800020 */ blr
  lbl_805383d4:
  /* 805383D4 8003001C */ lwz         r0, 0x1c(r3)
  /* 805383D8 7C040000 */ cmpw        r4, r0
  /* 805383DC 4082000C */ bne-        lbl_805383e8
  /* 805383E0 38600007 */ li          r3, 0x7
  /* 805383E4 4E800020 */ blr
  lbl_805383e8:
  /* 805383E8 80030020 */ lwz         r0, 0x20(r3)
  /* 805383EC 7C040000 */ cmpw        r4, r0
  /* 805383F0 4082000C */ bne-        lbl_805383fc
  /* 805383F4 38600008 */ li          r3, 0x8
  /* 805383F8 4E800020 */ blr
  lbl_805383fc:
  /* 805383FC 80030024 */ lwz         r0, 0x24(r3)
  /* 80538400 7C040000 */ cmpw        r4, r0
  /* 80538404 4082000C */ bne-        lbl_80538410
  /* 80538408 38600009 */ li          r3, 0x9
  /* 8053840C 4E800020 */ blr
  lbl_80538410:
  /* 80538410 3860FFFF */ li          r3, -0x1
  /* 80538414 4E800020 */ blr // clang-format on
}

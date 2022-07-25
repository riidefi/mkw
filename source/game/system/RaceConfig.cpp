#include "RaceConfig.hpp"

#pragma legacy_struct_alignment off

extern "C" {
// Extern function references.
// PAL: 0x80009d6c
extern UNKNOWN_FUNCTION(ParamFile_append);
// PAL: 0x8051c088
extern UNKNOWN_FUNCTION(reset__Q26System12RawGhostFileFv);
// PAL: 0x8051c120
extern UNKNOWN_FUNCTION(isValid__Q26System12RawGhostFileCFv);
// PAL: 0x8051c270
extern UNKNOWN_FUNCTION(__ct__Q26System9GhostFileFv);
// PAL: 0x8051c790
extern UNKNOWN_FUNCTION(read__Q26System9GhostFileFRCQ26System12RawGhostFile);
// PAL: 0x80524500
extern UNKNOWN_FUNCTION(unk_80524500);
// PAL: 0x8052453c
extern UNKNOWN_FUNCTION(InputMgr_setGhostController);
// PAL: 0x80524558
extern UNKNOWN_FUNCTION(unk_80524558);
// PAL: 0x80525f88
extern UNKNOWN_FUNCTION(init__Q26System3MiiFl);
// PAL: 0x8052d118
extern UNKNOWN_FUNCTION(unk_8052d118);
// PAL: 0x8052d1c0
extern UNKNOWN_FUNCTION(calcNegPoints__Q26System6RatingFPQ26System6Rating);
// PAL: 0x8052d270
extern UNKNOWN_FUNCTION(unk_8052d270);
// PAL: 0x805368f8
extern UNKNOWN_FUNCTION(RaceinfoPlayer_updateGpRankScore);
// PAL: 0x805419ac
extern UNKNOWN_FUNCTION(
    preloadCourseAsync__Q26System15ResourceManagerFQ26System8CourseId);
// PAL: 0x805553b0
extern UNKNOWN_FUNCTION(unk_805553b0);
// PAL: 0x8066c8d8
extern UNKNOWN_FUNCTION(unk_8066c8d8);
}

namespace System {

extern const f32 ZERO_FLOAT;
extern const CourseId COURSE_ORDER[8][4];
extern const u8 VS_POINT_DISTRIBUTION[12][12];
extern const s32 RANK_SCORES[5];
extern const u16 SCORES[4];

const f32 ZERO_FLOAT = 0;
const CourseId COURSE_ORDER[8][4] = {
    {LUIGI_CIRCUIT, MOO_MOO_MEADOWS, MUSHROOM_GORGE, TOADS_FACTORY},
    {MARIO_CIRCUIT, COCONUT_MALL, DK_SUMMIT, WARIOS_GOLD_MINE},
    {DAISY_CIRCUIT, KOOPA_CAPE, MAPLE_TREEWAY, GRUMBLE_VOLCANO},
    {DRY_DRY_RUINS, MOONVIEW_HIGHWAY, BOWSERS_CASTLE, RAINBOW_ROAD},
    {GCN_PEACH_BEACH, DS_YOSHI_FALLS, SNES_GHOST_VALLEY_2, N64_MARIO_RACEWAY},
    {N64_SHERBET_LAND, GBA_SHY_GUY_BEACH, DS_DELFINO_SQUARE,
     GCN_WALUIGI_STADIUM},
    {DS_DESERT_HILLS, GBA_BOWSER_CASTLE_3, N64_DKS_JUNGLE_PARKWAY,
     GCN_MARIO_CIRCUIT},
    {SNES_MARIO_CIRCUIT_3, DS_PEACH_GARDENS, GCN_DK_MOUNTAIN,
     N64_BOWSERS_CASTLE}};

const u8 __attribute__((force_export))
VS_POINT_DISTRIBUTION[12][12] = {{15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {15, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {15, 8, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {15, 9, 4, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                                 {15, 9, 5, 2, 1, 0, 0, 0, 0, 0, 0, 0},
                                 {15, 10, 6, 3, 1, 0, 0, 0, 0, 0, 0, 0},
                                 {15, 10, 7, 5, 3, 1, 0, 0, 0, 0, 0, 0},
                                 {15, 11, 8, 6, 4, 2, 1, 0, 0, 0, 0, 0},
                                 {15, 11, 8, 6, 4, 3, 2, 1, 0, 0, 0, 0},
                                 {15, 12, 10, 8, 6, 4, 3, 2, 1, 0, 0, 0},
                                 {15, 12, 10, 8, 6, 5, 4, 3, 2, 1, 0, 0},
                                 {15, 12, 10, 8, 7, 6, 5, 4, 3, 2, 1, 0}};

const s32 RANK_SCORES[] = {1000, 700, 400, 200, 0};
const u16 SCORES[] = {60, 52, 40, 20};

RaceConfigPlayer::RaceConfigPlayer()
    : _04(0), mLocalPlayerNum(-1), mPlayerInputIdx(-1),
      mVehicleId(STANDARD_KART_M), mCharacterId(MARIO), mPlayerType(0), mMii(7),
      mControllerId(-1), _d4(8), mRating(), _ec(_ec & ~0x80) {}

void RaceConfigPlayer::appendParamFile(RaceConfig* raceConfig) {
  raceConfig->append(mVehicleId, InitScene::spInstance->mHeapCollection
                                     .mpHeaps[HeapCollection::HEAP_ID_MEM2]);
  raceConfig->append(mCharacterId, InitScene::spInstance->mHeapCollection
                                       .mpHeaps[HeapCollection::HEAP_ID_MEM2]);
  raceConfig->append(mPlayerType, InitScene::spInstance->mHeapCollection
                                      .mpHeaps[HeapCollection::HEAP_ID_MEM2]);
  raceConfig->append(mTeam, InitScene::spInstance->mHeapCollection
                                .mpHeaps[HeapCollection::HEAP_ID_MEM2]);
}

s32 RaceConfigPlayer::computeGpRank() const {
  s8 weightedRankScore = 5;
  for (u8 i = 0; i < sizeof(RANK_SCORES) / 4; i++) {
    if (mGpRankScore >= RANK_SCORES[i]) {
      weightedRankScore = i;
      break;
    }
  }

  s8 weightedScore = 4;
  for (u8 i = 0; i < sizeof(SCORES) / 2; i++) {
    if (mGpScore >= SCORES[i]) {
      weightedScore = i;
      break;
    }
  }

  if (weightedRankScore + weightedScore >= 8) {
    return 7;
  }

  return weightedRankScore + weightedScore;
}

RaceConfigScenario::RaceConfigScenario(RawGhostFile* ghost)
    : mPlayerCount(0), mHudCount(0), mPlayers() {
  mSettings.mCourseId = GCN_MARIO_CIRCUIT;
  mSettings.mGameMode = 0;
  mSettings.mGameType = 0;
  mSettings.mCupId = 0;

  // seems dubious
  memset(&this->_b7c, 0, 0x70);

  mGhost = ghost;
}

} // namespace System

// Symbol: RacedataPlayer_destroy
// PAL: 0x8052dc68..0x8052dca8
MARK_BINARY_BLOB(RacedataPlayer_destroy, 0x8052dc68, 0x8052dca8);
asm UNKNOWN_FUNCTION(RacedataPlayer_destroy) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmpwi r3, 0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  beq lbl_8052dc90;
  cmpwi r4, 0;
  ble lbl_8052dc90;
  bl unk_805553b0;
lbl_8052dc90:
  mr r3, r31;
  lwz r31, 0xc(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

namespace System {

BattleTeam RaceScenario::computeWinningTeam() {
  u16 results[] = {0, 0};

  for (u8 i = 0; i < RaceConfig::spInstance->mRaceScenario.mPlayerCount; i++) {
    const BattleTeam team = mPlayers[i].mTeam;
    results[team] += mPlayers[i].mPreviousScore;
  }

  return (results[0] < results[1]) ? BATTLE_TEAM_BLUE : BATTLE_TEAM_RED;
}

BattleTeam RaceConfigPlayer::getTeam() { return mTeam; }

RaceConfigPlayer* RaceScenario::getPlayer(u8 idx) { return &mPlayers[idx]; }

const u8 RaceConfig::getRacePlayerCount() {
  return RaceConfig::spInstance->mRaceScenario.mPlayerCount;
}

} // namespace System

// Symbol: Racedata_init
// PAL: 0x8052dd40..0x8052e42c
// Scratch: https://decomp.me/scratch/c7cMM
MARK_BINARY_BLOB(Racedata_init, 0x8052dd40, 0x8052e42c);
asm UNKNOWN_FUNCTION(Racedata_init) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  li r10, 0;
  li r5, 0x11;
  stw r0, 0x34(r1);
  li r0, 3;
  li r9, 2;
  li r8, 1;
  stmw r22, 8(r1);
  mr r31, r3;
  li r11, 0;
  lwz r4, 0x1780(r3);
  stw r5, 0x1758(r3);
  rlwinm r4, r4, 0, 0, 0x1c;
  stw r10, 0x1760(r3);
  stw r10, 0x1764(r3);
  stw r10, 0x1778(r3);
  stw r9, 0x175c(r3);
  stw r8, 0x176c(r3);
  stw r4, 0x1780(r3);
  mtctr r0;
lbl_8052dd94:
  clrlwi r4, r11, 0x18;
  addi r11, r11, 1;
  mulli r7, r4, 0xf0;
  neg r5, r4;
  clrlwi r0, r11, 0x18;
  add r6, r3, r7;
  or r5, r5, r4;
  stw r10, 0xc24(r6);
  srwi r4, r5, 0x1f;
  neg r5, r0;
  addi r11, r11, 1;
  stw r8, 0xc20(r6);
  mulli r7, r0, 0xf0;
  or r5, r5, r0;
  stw r4, 0xc28(r6);
  clrlwi r0, r11, 0x18;
  srwi r4, r5, 0x1f;
  addi r11, r11, 1;
  stw r9, 0xce4(r6);
  add r6, r3, r7;
  neg r5, r0;
  stw r10, 0xc24(r6);
  mulli r7, r0, 0xf0;
  or r5, r5, r0;
  stw r8, 0xc20(r6);
  clrlwi r0, r11, 0x18;
  addi r11, r11, 1;
  stw r4, 0xc28(r6);
  srwi r4, r5, 0x1f;
  neg r5, r0;
  stw r9, 0xce4(r6);
  add r6, r3, r7;
  mulli r7, r0, 0xf0;
  or r5, r5, r0;
  stw r10, 0xc24(r6);
  stw r8, 0xc20(r6);
  stw r4, 0xc28(r6);
  srwi r4, r5, 0x1f;
  stw r9, 0xce4(r6);
  add r6, r3, r7;
  stw r10, 0xc24(r6);
  stw r8, 0xc20(r6);
  stw r4, 0xc28(r6);
  stw r9, 0xce4(r6);
  bdnz lbl_8052dd94;
  lwz r4, 0x1780(r3);
  li r6, 1;
  li r0, 2;
  li r11, 0;
  rlwinm r4, r4, 0, 0, 0x1c;
  li r5, 3;
  stw r11, 0x1770(r3);
  li r12, 0;
  stw r6, 0x176c(r3);
  stb r5, 0x177d(r3);
  stw r6, 0x175c(r3);
  stw r4, 0x1780(r3);
  mtctr r0;
lbl_8052de7c:
  clrlwi r10, r12, 0x18;
  addi r0, r12, 2;
  mulli r5, r10, 0xf0;
  addi r4, r12, 1;
  clrlwi r7, r0, 0x18;
  addi r0, r12, 3;
  add r9, r3, r5;
  clrlwi r8, r4, 0x18;
  sth r11, 0xcf0(r9);
  clrlwi r6, r0, 0x18;
  addi r4, r12, 4;
  addi r0, r12, 5;
  sth r11, 0xcf6(r9);
  clrlwi r5, r4, 0x18;
  addi r10, r10, 1;
  clrlwi r4, r0, 0x18;
  stb r10, 0xcf9(r9);
  addi r0, r8, 1;
  addi r7, r7, 1;
  addi r6, r6, 1;
  stb r10, 0xcf8(r9);
  addi r5, r5, 1;
  addi r4, r4, 1;
  addi r12, r12, 6;
  sth r11, 0xde0(r9);
  sth r11, 0xde6(r9);
  stb r0, 0xde9(r9);
  stb r0, 0xde8(r9);
  sth r11, 0xed0(r9);
  sth r11, 0xed6(r9);
  stb r7, 0xed9(r9);
  stb r7, 0xed8(r9);
  sth r11, 0xfc0(r9);
  sth r11, 0xfc6(r9);
  stb r6, 0xfc9(r9);
  stb r6, 0xfc8(r9);
  sth r11, 0x10b0(r9);
  sth r11, 0x10b6(r9);
  stb r5, 0x10b9(r9);
  stb r5, 0x10b8(r9);
  sth r11, 0x11a0(r9);
  sth r11, 0x11a6(r9);
  stb r4, 0x11a9(r9);
  stb r4, 0x11a8(r9);
  bdnz lbl_8052de7c;
  lwz r4, 0x2370(r3);
  li r11, 0;
  li r0, 2;
  li r6, 3;
  li r5, 1;
  rlwinm r4, r4, 0, 0, 0x1c;
  stb r11, 0x177c(r3);
  li r12, 0;
  stb r6, 0x177d(r3);
  stw r11, 0x2360(r3);
  stw r5, 0x235c(r3);
  stb r6, 0x236d(r3);
  stw r5, 0x234c(r3);
  stw r4, 0x2370(r3);
  mtctr r0;
lbl_8052df6c:
  clrlwi r10, r12, 0x18;
  addi r0, r12, 2;
  mulli r5, r10, 0xf0;
  addi r4, r12, 1;
  clrlwi r7, r0, 0x18;
  addi r0, r12, 3;
  add r9, r3, r5;
  clrlwi r8, r4, 0x18;
  sth r11, 0x18e0(r9);
  clrlwi r6, r0, 0x18;
  addi r4, r12, 4;
  addi r0, r12, 5;
  sth r11, 0x18e6(r9);
  clrlwi r5, r4, 0x18;
  addi r10, r10, 1;
  clrlwi r4, r0, 0x18;
  stb r10, 0x18e9(r9);
  addi r0, r8, 1;
  addi r7, r7, 1;
  addi r6, r6, 1;
  stb r10, 0x18e8(r9);
  addi r5, r5, 1;
  addi r4, r4, 1;
  addi r12, r12, 6;
  sth r11, 0x19d0(r9);
  sth r11, 0x19d6(r9);
  stb r0, 0x19d9(r9);
  stb r0, 0x19d8(r9);
  sth r11, 0x1ac0(r9);
  sth r11, 0x1ac6(r9);
  stb r7, 0x1ac9(r9);
  stb r7, 0x1ac8(r9);
  sth r11, 0x1bb0(r9);
  sth r11, 0x1bb6(r9);
  stb r6, 0x1bb9(r9);
  stb r6, 0x1bb8(r9);
  sth r11, 0x1ca0(r9);
  sth r11, 0x1ca6(r9);
  stb r5, 0x1ca9(r9);
  stb r5, 0x1ca8(r9);
  sth r11, 0x1d90(r9);
  sth r11, 0x1d96(r9);
  stb r4, 0x1d99(r9);
  stb r4, 0x1d98(r9);
  bdnz lbl_8052df6c;
  li r4, 0;
  li r0, 3;
  stb r4, 0x236c(r3);
  lis r22, 0;
  addi r4, r31, 0x1758;
  li r5, 4;
  stb r0, 0x236d(r3);
  mr r3, r31;
  lwz r6, 0(r22);
  lwz r6, 0x34(r6);
  bl unk_805553b0;
  lwz r6, 0(r22);
  mr r3, r31;
  addi r4, r31, 0x175c;
  li r5, 4;
  lwz r6, 0x34(r6);
  bl unk_805553b0;
  lwz r6, 0(r22);
  mr r3, r31;
  addi r4, r31, 0x1760;
  li r5, 4;
  lwz r6, 0x34(r6);
  bl unk_805553b0;
  lwz r6, 0(r22);
  mr r3, r31;
  addi r4, r31, 0xc14;
  li r5, 1;
  lwz r6, 0x34(r6);
  bl unk_805553b0;
  lwz r6, 0(r22);
  mr r3, r31;
  addi r4, r31, 0xc16;
  li r5, 1;
  lwz r6, 0x34(r6);
  bl unk_805553b0;
  addi r24, r31, 0xc18;
  li r23, 0;
lbl_8052e0b4:
  lwz r6, 0(r22);
  mr r3, r31;
  addi r4, r24, 8;
  li r5, 4;
  lwz r6, 0x34(r6);
  bl unk_805553b0;
  lwz r6, 0(r22);
  mr r3, r31;
  addi r4, r24, 0xc;
  li r5, 4;
  lwz r6, 0x34(r6);
  bl unk_805553b0;
  lwz r6, 0(r22);
  mr r3, r31;
  addi r4, r24, 0x10;
  li r5, 4;
  lwz r6, 0x34(r6);
  bl unk_805553b0;
  lwz r6, 0(r22);
  mr r3, r31;
  addi r4, r24, 0xcc;
  li r5, 4;
  lwz r6, 0x34(r6);
  bl unk_805553b0;
  addi r23, r23, 1;
  addi r24, r24, 0xf0;
  cmpwi r23, 0xc;
  blt lbl_8052e0b4;
  mr r3, r31;
  addi r4, r31, 0x1780;
  li r5, 4;
  li r6, 0;
  bl unk_805553b0;
  lwz r12, 0(r31);
  lis r4, 0;
  lwz r4, 0(r4);
  mr r3, r31;
  lwz r12, 0xc(r12);
  lwz r4, 0x34(r4);
  mtctr r12;
  bctrl;
  addi r3, r31, 0xc10;
  addi r4, r31, 0x20;
  bl initRace__Q26System12MenuScenarioFPQ26System12RaceScenario;
  lbz r9, 0xc14(r31);
  addi r3, r31, 0x28;
  lbz r8, 0xc15(r31);
  addi r4, r31, 0xc18;
  lbz r7, 0xc16(r31);
  addi r5, r31, 0xb68;
  lbz r6, 0xc17(r31);
  li r0, 0x26;
  stb r9, 0x24(r31);
  stb r8, 0x25(r31);
  stb r7, 0x26(r31);
  stb r6, 0x27(r31);
lbl_8052e194:
  lbz r6, 4(r4);
  addi r9, r3, 0x23;
  stb r6, 4(r3);
  addi r8, r4, 0x23;
  lbz r6, 5(r4);
  stb r6, 5(r3);
  lbz r6, 6(r4);
  stb r6, 6(r3);
  lwz r6, 8(r4);
  stw r6, 8(r3);
  lwz r6, 0xc(r4);
  stw r6, 0xc(r3);
  lwz r6, 0x10(r4);
  stw r6, 0x10(r3);
  lwz r6, 0x18(r4);
  stw r6, 0x18(r3);
  lbz r6, 0x1c(r4);
  stb r6, 0x1c(r3);
  lbz r6, 0x1d(r4);
  stb r6, 0x1d(r3);
  lwz r6, 0x20(r4);
  stw r6, 0x20(r3);
  mtctr r0;
lbl_8052e1f0:
  lbz r7, 1(r8);
  lbzu r6, 2(r8);
  stb r7, 1(r9);
  stbu r6, 2(r9);
  bdnz lbl_8052e1f0;
  lwz r6, 0x70(r4);
  stw r6, 0x70(r3);
  lbz r6, 0x74(r4);
  stb r6, 0x74(r3);
  lbz r6, 0x75(r4);
  stb r6, 0x75(r3);
  lbz r6, 0x76(r4);
  stb r6, 0x76(r3);
  lbz r6, 0x77(r4);
  stb r6, 0x77(r3);
  lwz r6, 0x78(r4);
  stw r6, 0x78(r3);
  lwz r6, 0x80(r4);
  lwz r7, 0x7c(r4);
  stw r7, 0x7c(r3);
  stw r6, 0x80(r3);
  lwz r6, 0x88(r4);
  lwz r7, 0x84(r4);
  stw r7, 0x84(r3);
  stw r6, 0x88(r3);
  lwz r6, 0x90(r4);
  lwz r7, 0x8c(r4);
  stw r7, 0x8c(r3);
  stw r6, 0x90(r3);
  lwz r6, 0x98(r4);
  lwz r7, 0x94(r4);
  stw r7, 0x94(r3);
  stw r6, 0x98(r3);
  lwz r6, 0xa0(r4);
  lwz r7, 0x9c(r4);
  stw r7, 0x9c(r3);
  stw r6, 0xa0(r3);
  lwz r6, 0xa8(r4);
  lwz r7, 0xa4(r4);
  stw r7, 0xa4(r3);
  stw r6, 0xa8(r3);
  lwz r6, 0xb0(r4);
  lwz r7, 0xac(r4);
  stw r7, 0xac(r3);
  stw r6, 0xb0(r3);
  lwz r6, 0xb4(r4);
  stw r6, 0xb4(r3);
  lbz r6, 0xb8(r4);
  stb r6, 0xb8(r3);
  lbz r6, 0xb9(r4);
  stb r6, 0xb9(r3);
  lbz r6, 0xba(r4);
  stb r6, 0xba(r3);
  lwz r6, 0xbc(r4);
  stw r6, 0xbc(r3);
  lbz r6, 0xc0(r4);
  stb r6, 0xc0(r3);
  lbz r6, 0xc1(r4);
  stb r6, 0xc1(r3);
  lbz r6, 0xc2(r4);
  stb r6, 0xc2(r3);
  lwz r6, 0xc4(r4);
  stw r6, 0xc4(r3);
  lwz r6, 0xc8(r4);
  stw r6, 0xc8(r3);
  lwz r6, 0xcc(r4);
  stw r6, 0xcc(r3);
  lwz r6, 0xd0(r4);
  stw r6, 0xd0(r3);
  lwz r6, 0xd4(r4);
  stw r6, 0xd4(r3);
  lhz r6, 0xd8(r4);
  sth r6, 0xd8(r3);
  lhz r6, 0xda(r4);
  sth r6, 0xda(r3);
  lhz r6, 0xdc(r4);
  sth r6, 0xdc(r3);
  lha r6, 0xde(r4);
  sth r6, 0xde(r3);
  lbz r6, 0xe0(r4);
  stb r6, 0xe0(r3);
  lbz r6, 0xe1(r4);
  stb r6, 0xe1(r3);
  lbz r6, 0xe2(r4);
  stb r6, 0xe2(r3);
  lhz r6, 0xe8(r4);
  sth r6, 0xe8(r3);
  lbz r6, 0xec(r4);
  addi r4, r4, 0xf0;
  stb r6, 0xec(r3);
  addi r3, r3, 0xf0;
  cmplw r3, r5;
  blt lbl_8052e194;
  lwz r22, 0x1758(r31);
  li r0, 0xe;
  lwz r23, 0x175c(r31);
  addi r5, r31, 0xb98;
  lwz r24, 0x1760(r31);
  addi r4, r31, 0x1788;
  lwz r25, 0x1764(r31);
  lwz r26, 0x1768(r31);
  lwz r27, 0x176c(r31);
  lwz r28, 0x1770(r31);
  lbz r29, 0x1774(r31);
  lbz r30, 0x1775(r31);
  lbz r12, 0x1776(r31);
  lbz r11, 0x1777(r31);
  lwz r10, 0x1778(r31);
  lbz r9, 0x177c(r31);
  lbz r8, 0x177d(r31);
  lwz r7, 0x1780(r31);
  lwz r6, 0x1784(r31);
  lwz r3, 0x1788(r31);
  stw r22, 0xb68(r31);
  stw r23, 0xb6c(r31);
  stw r24, 0xb70(r31);
  stw r25, 0xb74(r31);
  stw r26, 0xb78(r31);
  stw r27, 0xb7c(r31);
  stw r28, 0xb80(r31);
  stb r29, 0xb84(r31);
  stb r30, 0xb85(r31);
  stb r12, 0xb86(r31);
  stb r11, 0xb87(r31);
  stw r10, 0xb88(r31);
  stb r9, 0xb8c(r31);
  stb r8, 0xb8d(r31);
  stw r7, 0xb90(r31);
  stw r6, 0xb94(r31);
  stw r3, 0xb98(r31);
  mtctr r0;
lbl_8052e3fc:
  lwz r3, 4(r4);
  lwzu r0, 8(r4);
  stw r3, 4(r5);
  stwu r0, 8(r5);
  bdnz lbl_8052e3fc;
  lwz r0, 0x17fc(r31);
  stw r0, 0xc0c(r31);
  lmw r22, 8(r1);
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

namespace System {

void RaceConfigPlayer::setCharacter(CharacterId character) {
  mCharacterId = character;
}

RaceConfigPlayer* MenuScenario::getPlayer(u8 idx) { return &mPlayers[idx]; }

void RaceConfigPlayer::setVehicle(VehicleId vehicle) { mVehicleId = vehicle; }

void RaceConfigPlayer::setPlayerType(s32 playerType) {
  mPlayerType = playerType;
}

void RaceConfig::reset() {
  mMenuScenario.reset();
  mAwardsScenario.reset();
}

void RaceConfigPlayer::reset(s8 pos) {
  mPreviousScore = 0;
  mGpRankScore = 0;
  mPrevFinishPos = pos;
  this->_e0 = pos;
}

void RaceConfigPlayer::setPrevFinishPos(s8 pos) { mPrevFinishPos = pos; }

void RaceConfigPlayer::setUnkPos(s8 pos) { this->_e0 = pos; }

void RaceConfigScenario::reset() {
  mSettings.mItemMode = 0;
  mSettings.mCpuMode = 1;
  mSettings.mLapCount = 3;
  mSettings.mEngineClass = 1;
  mSettings.mModeFlags = mSettings.mModeFlags & 0xFFFFFFF8;

  for (u8 i = 0; i < 12; i++) {
    getPlayer(i)->reset(i + 1);
  }

  mSettings.mRaceNumber = 0;
  mSettings.mLapCount = 3;
}

} // namespace System

// Symbol: unk_8052e764
// PAL: 0x8052e764..0x8052e770
MARK_BINARY_BLOB(unk_8052e764, 0x8052e764, 0x8052e770);
asm UNKNOWN_FUNCTION(unk_8052e764) {
  // clang-format off
  blr;
  blr;
  blr;
  // clang-format on
}

namespace System {

u8 RaceConfigScenario::update() {
  if (mSettings.mRaceNumber < 100) {
    mSettings.mRaceNumber++;
  } else {
    mSettings.mRaceNumber = 0;
  }

  for (u8 i = 0; i < 12; i++) {
    RaceConfigPlayer* player = getPlayer(i);
    player->mPrevFinishPos = player->mFinishPos;
    player->mPreviousScore = player->mGpScore;
  }

  return mSettings.mRaceNumber;
}

s16 RaceConfig::updateRating(u8 playerIdx) {
  const u8 playerCount = RaceConfig::getRacePlayerCount();
  f32 totalPoints = ZERO_FLOAT;

  for (u8 i = 0; i < playerCount; i++) {
    if (playerIdx == i) {
      continue;
    }

    RaceConfigPlayer* player =
        RaceConfig::spInstance->mRaceScenario.getPlayer(playerIdx);
    totalPoints += player->mRating.calcNegPoints(
        &RaceConfig::spInstance->mRaceScenario.getPlayer(i)->mRating);
  }
  return totalPoints;
}

} // namespace System

// Symbol: unk_8052e950
// PAL: 0x8052e950..0x8052ed18
// Scratch: https://decomp.me/scratch/AQNbc
MARK_BINARY_BLOB(unk_8052e950, 0x8052e950, 0x8052ed18);
asm UNKNOWN_FUNCTION(unk_8052e950) {
  // clang-format off
  nofralloc;
  stwu r1, -0x90(r1);
  mflr r0;
  stw r0, 0x94(r1);
  stfd f31, 0x80(r1);
  psq_st f31, 136(r1), 0, 0;
  stfd f30, 0x70(r1);
  psq_st f30, 120(r1), 0, 0;
  addi r11, r1, 0x70;
  bl unk_805553b0;
  lwz r0, 0xb54(r3);
  lis r21, 0;
  lwz r4, 0(r21);
  mr r15, r3;
  cmpwi r0, 0;
  lbz r22, 0x24(r4);
  bne lbl_8052ecf0;
  addi r0, r22, -1;
  lis r3, 0;
  mulli r0, r0, 0xc;
  lis r4, 0;
  lfd f31, 0(r3);
  addi r18, r1, 8;
  addi r4, r4, 0;
  add r20, r4, r0;
  li r17, 0;
  lis r30, 0;
  li r29, 1;
  lis r31, 0x4330;
  li r26, 0;
  lis r14, 0;
  b lbl_8052ec4c;
lbl_8052e9cc:
  lwz r3, 0(r30);
  rlwinm r19, r17, 2, 0x16, 0x1d;
  lwz r6, 0(r21);
  li r4, 0;
  lwz r5, 0xc(r3);
  lwz r3, 0xb70(r6);
  lwzx r5, r5, r19;
  addi r0, r3, -3;
  cmplwi r0, 7;
  lbz r23, 0x20(r5);
  bgt lbl_8052ea08;
  slw r0, r29, r0;
  andi. r0, r0, 0xc1;
  beq lbl_8052ea08;
  li r4, 1;
lbl_8052ea08:
  cmpwi r4, 0;
  beq lbl_8052ea18;
  lhz r24, 0x22(r5);
  b lbl_8052ea1c;
lbl_8052ea18:
  li r24, 0;
lbl_8052ea1c:
  lwz r3, 0xb50(r15);
  rlwinm r25, r17, 1, 0x17, 0x1e;
  sthx r26, r18, r25;
  li r0, 0;
  cmpwi r3, 7;
  blt lbl_8052ea40;
  cmpwi r3, 0xa;
  bgt lbl_8052ea40;
  li r0, 1;
lbl_8052ea40:
  cmpwi r0, 0;
  beq lbl_8052ebe4;
  clrlwi r27, r17, 0x18;
  lfs f30, 0(r14);
  mulli r0, r27, 0xf0;
  li r16, 0;
  add r28, r15, r0;
  b lbl_8052eb80;
lbl_8052ea60:
  clrlwi r0, r16, 0x18;
  cmplw r27, r0;
  beq lbl_8052eb7c;
  lwz r4, 0(r21);
  li r0, 0;
  li r3, 0;
  li r5, 0;
  lwz r4, 0xb70(r4);
  addi r4, r4, -3;
  cmplwi r4, 7;
  bgt lbl_8052ea9c;
  slw r4, r29, r4;
  andi. r4, r4, 0xc1;
  beq lbl_8052ea9c;
  li r5, 1;
lbl_8052ea9c:
  cmpwi r5, 0;
  beq lbl_8052ead4;
  lwz r5, 0(r30);
  rlwinm r4, r16, 2, 0x16, 0x1d;
  lwz r5, 0xc(r5);
  lwzx r4, r5, r4;
  lhz r4, 0x22(r4);
  cmplw r24, r4;
  ble lbl_8052eac8;
  li r0, 1;
  b lbl_8052eb00;
lbl_8052eac8:
  bge lbl_8052eb00;
  li r3, 1;
  b lbl_8052eb00;
lbl_8052ead4:
  lwz r5, 0(r30);
  rlwinm r4, r16, 2, 0x16, 0x1d;
  lwz r5, 0xc(r5);
  lwzx r4, r5, r4;
  lbz r4, 0x20(r4);
  cmplw r23, r4;
  bge lbl_8052eaf8;
  li r0, 1;
  b lbl_8052eb00;
lbl_8052eaf8:
  ble lbl_8052eb00;
  li r3, 1;
lbl_8052eb00:
  cmpwi r0, 0;
  beq lbl_8052eb40;
  clrlwi r0, r16, 0x18;
  addi r3, r28, 0xec;
  mulli r0, r0, 0xf0;
  add r4, r15, r0;
  addi r4, r4, 0xec;
  bl unk_8052d118;
  extsh r0, r3;
  stw r31, 0x20(r1);
  xoris r0, r0, 0x8000;
  stw r0, 0x24(r1);
  lfd f0, 0x20(r1);
  fsubs f0, f0, f31;
  fadds f30, f30, f0;
  b lbl_8052eb7c;
lbl_8052eb40:
  cmpwi r3, 0;
  beq lbl_8052eb7c;
  clrlwi r0, r16, 0x18;
  addi r3, r28, 0xec;
  mulli r0, r0, 0xf0;
  add r4, r15, r0;
  addi r4, r4, 0xec;
  bl calcNegPoints__Q26System6RatingFPQ26System6Rating;
  extsh r0, r3;
  stw r31, 0x20(r1);
  xoris r0, r0, 0x8000;
  stw r0, 0x24(r1);
  lfd f0, 0x20(r1);
  fsubs f0, f0, f31;
  fadds f30, f30, f0;
lbl_8052eb7c:
  addi r16, r16, 1;
lbl_8052eb80:
  clrlwi r0, r16, 0x18;
  cmplw r0, r22;
  blt lbl_8052ea60;
  lwz r3, 0(r21);
  fctiwz f0, f30;
  li r4, 0;
  lwz r3, 0xb70(r3);
  stfd f0, 0x20(r1);
  addi r0, r3, -3;
  cmplwi r0, 7;
  lwz r3, 0x24(r1);
  bgt lbl_8052ebc0;
  slw r0, r29, r0;
  andi. r0, r0, 0xc1;
  beq lbl_8052ebc0;
  li r4, 1;
lbl_8052ebc0:
  cmpwi r4, 0;
  bne lbl_8052ebe0;
  cmplwi r23, 1;
  bne lbl_8052ebe0;
  extsh r0, r3;
  cmpwi r0, 1;
  bge lbl_8052ebe0;
  li r3, 1;
lbl_8052ebe0:
  sthx r3, r18, r25;
lbl_8052ebe4:
  cmpwi r23, 0;
  beq lbl_8052ec48;
  cmpwi r22, 0;
  beq lbl_8052ec48;
  clrlwi r0, r17, 0x18;
  mulli r0, r0, 0xf0;
  add r4, r15, r0;
  stb r23, 0xea(r4);
  lwz r0, 0xb50(r15);
  cmpwi r0, 9;
  blt lbl_8052ec18;
  cmpwi r0, 0xa;
  ble lbl_8052ec20;
lbl_8052ec18:
  cmpwi r0, 3;
  bne lbl_8052ec34;
lbl_8052ec20:
  lwz r3, 0(r30);
  lwz r3, 0xc(r3);
  lwzx r3, r3, r19;
  lhz r3, 0x22(r3);
  b lbl_8052ec3c;
lbl_8052ec34:
  add r3, r20, r23;
  lbz r3, -1(r3);
lbl_8052ec3c:
  lhz r0, 0xe0(r4);
  add r0, r0, r3;
  sth r0, 0xe2(r4);
lbl_8052ec48:
  addi r17, r17, 1;
lbl_8052ec4c:
  clrlwi r0, r17, 0x18;
  cmplw r0, r22;
  blt lbl_8052e9cc;
  addi r14, r1, 8;
  li r16, 0;
  b lbl_8052ec84;
lbl_8052ec64:
  clrlwi r3, r16, 0x18;
  rlwinm r0, r16, 1, 0x17, 0x1e;
  mulli r3, r3, 0xf0;
  lhax r4, r14, r0;
  add r3, r15, r3;
  addi r3, r3, 0xec;
  bl unk_8052d270;
  addi r16, r16, 1;
lbl_8052ec84:
  clrlwi r0, r16, 0x18;
  cmplw r0, r22;
  blt lbl_8052ec64;
  lwz r0, 0xb50(r15);
  cmpwi r0, 0;
  bne lbl_8052ecf0;
  lis r3, 0;
  li r16, 0;
  lwz r15, 0(r3);
  lis r14, 0;
  b lbl_8052ecdc;
lbl_8052ecb0:
  clrlwi r0, r16, 0x18;
  mulli r0, r0, 0xf0;
  add r3, r4, r0;
  lwz r0, 0x38(r3);
  cmpwi r0, 0;
  bne lbl_8052ecd8;
  lwz r3, 0xc(r15);
  rlwinm r0, r16, 2, 0x16, 0x1d;
  lwzx r3, r3, r0;
  bl RaceinfoPlayer_updateGpRankScore;
lbl_8052ecd8:
  addi r16, r16, 1;
lbl_8052ecdc:
  lwz r4, 0(r14);
  clrlwi r3, r16, 0x18;
  lbz r0, 0x24(r4);
  cmplw r3, r0;
  blt lbl_8052ecb0;
lbl_8052ecf0:
  psq_l f31, 136(r1), 0, 0;
  lfd f31, 0x80(r1);
  psq_l f30, 120(r1), 0, 0;
  addi r11, r1, 0x70;
  lfd f30, 0x70(r1);
  bl unk_805553b0;
  lwz r0, 0x94(r1);
  mtlr r0;
  addi r1, r1, 0x90;
  blr;
  // clang-format on
}

namespace System {

s32 MenuScenario::getGametype() { return mSettings.mGameType; }

s32 RaceConfigPlayer::getPlayerType() { return mPlayerType; }

} // namespace System

// Symbol: postInitControllers__Q26System12MenuScenarioFPQ26System12RaceScenario
// PAL: 0x8052ed28..0x8052eef0
// Scratch: https://decomp.me/scratch/aw5WV
MARK_BINARY_BLOB(
    postInitControllers__Q26System12MenuScenarioFPQ26System12RaceScenario,
    0x8052ed28, 0x8052eef0);
asm UNKNOWN_FUNCTION(
    postInitControllers__Q26System12MenuScenarioFPQ26System12RaceScenario) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stw r31, 0x1c(r1);
  mr r31, r3;
  stw r30, 0x18(r1);
  stw r29, 0x14(r1);
  lwz r0, 0xb54(r3);
  cmpwi r0, 5;
  beq lbl_8052ed64;
  cmpwi r0, 0;
  beq lbl_8052edac;
  cmpwi r0, 1;
  beq lbl_8052ee84;
  b lbl_8052eed4;
lbl_8052ed64:
  li r29, 0;
  lis r30, 0;
lbl_8052ed6c:
  clrlwi r0, r29, 0x18;
  mulli r0, r0, 0xf0;
  add r3, r31, r0;
  lwz r0, 0x18(r3);
  cmpwi r0, 0;
  bne lbl_8052ed9c;
  lbz r0, 0xe(r3);
  extsb. r0, r0;
  blt lbl_8052ed9c;
  lwz r3, 0(r30);
  clrlwi r4, r0, 0x18;
  bl unk_80524558;
lbl_8052ed9c:
  addi r29, r29, 1;
  cmplwi r29, 0xc;
  blt lbl_8052ed6c;
  b lbl_8052eed4;
lbl_8052edac:
  li r0, 4;
  li r6, 0;
  lis r5, 0;
  mtctr r0;
lbl_8052edbc:
  clrlwi r0, r6, 0x18;
  mulli r0, r0, 0xf0;
  add r4, r3, r0;
  lwz r0, 0x18(r4);
  cmpwi r0, 0;
  bne lbl_8052edf8;
  lbz r0, 0xe(r4);
  extsb. r0, r0;
  blt lbl_8052edf8;
  clrlwi r0, r0, 0x18;
  lwz r4, 0(r5);
  mulli r0, r0, 0xec;
  add r4, r4, r0;
  lwz r0, 0x10(r4);
  stw r0, 8(r4);
lbl_8052edf8:
  addi r6, r6, 1;
  clrlwi r0, r6, 0x18;
  mulli r0, r0, 0xf0;
  add r4, r3, r0;
  lwz r0, 0x18(r4);
  cmpwi r0, 0;
  bne lbl_8052ee38;
  lbz r0, 0xe(r4);
  extsb. r0, r0;
  blt lbl_8052ee38;
  clrlwi r0, r0, 0x18;
  lwz r4, 0(r5);
  mulli r0, r0, 0xec;
  add r4, r4, r0;
  lwz r0, 0x10(r4);
  stw r0, 8(r4);
lbl_8052ee38:
  addi r6, r6, 1;
  clrlwi r0, r6, 0x18;
  mulli r0, r0, 0xf0;
  add r4, r3, r0;
  lwz r0, 0x18(r4);
  cmpwi r0, 0;
  bne lbl_8052ee78;
  lbz r0, 0xe(r4);
  extsb. r0, r0;
  blt lbl_8052ee78;
  clrlwi r0, r0, 0x18;
  lwz r4, 0(r5);
  mulli r0, r0, 0xec;
  add r4, r4, r0;
  lwz r0, 0x10(r4);
  stw r0, 8(r4);
lbl_8052ee78:
  addi r6, r6, 1;
  bdnz lbl_8052edbc;
  b lbl_8052eed4;
lbl_8052ee84:
  lwz r0, 0xb54(r4);
  cmpwi r0, 0;
  bne lbl_8052eed4;
  li r29, 0;
  lis r30, 0;
lbl_8052ee98:
  clrlwi r0, r29, 0x18;
  mulli r0, r0, 0xf0;
  add r3, r31, r0;
  lwz r0, 0x18(r3);
  cmpwi r0, 0;
  bne lbl_8052eec8;
  lbz r0, 0xe(r3);
  extsb. r0, r0;
  blt lbl_8052eec8;
  lwz r3, 0(r30);
  clrlwi r4, r0, 0x18;
  bl unk_80524500;
lbl_8052eec8:
  addi r29, r29, 1;
  cmplwi r29, 0xc;
  blt lbl_8052ee98;
lbl_8052eed4:
  lwz r0, 0x24(r1);
  lwz r31, 0x1c(r1);
  lwz r30, 0x18(r1);
  lwz r29, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// This has never built due to GhostFile access problems
// This should give a rough idea of how the function works
#ifdef NON_MATCHING
namespace System {

bool MenuScenario::initGhost(u8 playerIdx, u8 playerInputIdx) {
  if (!mGhost->isValid()) {
    return false;
  }

  GhostFile ghost;
  ghost.read(*mGhost);

  if (!ghost.mCourseId == mCourseId) {
    return false;
  }

  if (-1 < playerInputIdx) {
    InputManager::setGhostController(InputManager::spInstance, playerInputIdx,
                                     ghost.mInputs, ghost.mDriftIsAuto);
  }

  mPlayers[playerIdx].mCharacterId = ghost.mCharacterId;
  mPlayers[playerIdx].mVehicleId = ghost.mVehicleId;
  mPlayers[playerIdx].mPlayerInputIdx = playerInputIdx;
  mPlayers[playerIdx].mControllerId = ghost.mControllerId;

  return true;
}

} // namespace System
#else
// Symbol: unk_8052eef0
// PAL: 0x8052eef0..0x8052efd4
MARK_BINARY_BLOB(unk_8052eef0, 0x8052eef0, 0x8052efd4);
asm UNKNOWN_FUNCTION(unk_8052eef0) {
  // clang-format off
  nofralloc;
  stwu r1, -0xf0(r1);
  mflr r0;
  stw r0, 0xf4(r1);
  stw r31, 0xec(r1);
  li r31, 0;
  stw r30, 0xe8(r1);
  mr r30, r5;
  stw r29, 0xe4(r1);
  mr r29, r4;
  stw r28, 0xe0(r1);
  mr r28, r3;
  lwz r3, 0xbec(r3);
  bl isValid__Q26System12RawGhostFileCFv;
  cmpwi r3, 0;
  beq lbl_8052efb0;
  addi r3, r1, 8;
  bl __ct__Q26System9GhostFileFv;
  lwz r4, 0xbec(r28);
  addi r3, r1, 8;
  bl read__Q26System9GhostFileFRCQ26System12RawGhostFile;
  lwz r3, 0xc0(r1);
  lwz r0, 0xb48(r28);
  cmpw r3, r0;
  bne lbl_8052ef98;
  extsb. r0, r30;
  blt lbl_8052ef70;
  lis r3, 0;
  lwz r5, 0xdc(r1);
  lwz r3, 0(r3);
  clrlwi r4, r30, 0x18;
  lbz r6, 0xd0(r1);
  bl InputMgr_setGhostController;
lbl_8052ef70:
  mulli r3, r29, 0xf0;
  lwz r0, 0xb8(r1);
  li r31, 1;
  add r3, r28, r3;
  stw r0, 0x14(r3);
  lwz r0, 0xbc(r1);
  stw r0, 0x10(r3);
  stb r30, 0xe(r3);
  lwz r0, 0xc4(r1);
  stw r0, 0xd8(r3);
lbl_8052ef98:
  lis r4, 0;
  addi r3, r1, 0x70;
  addi r4, r4, 0;
  li r5, 0xc;
  li r6, 5;
  bl unk_805553b0;
lbl_8052efb0:
  mr r3, r31;
  lwz r31, 0xec(r1);
  lwz r30, 0xe8(r1);
  lwz r29, 0xe4(r1);
  lwz r28, 0xe0(r1);
  lwz r0, 0xf4(r1);
  mtlr r0;
  addi r1, r1, 0xf0;
  blr;
  // clang-format on
}
#endif

namespace System {

void RaceConfigScenario::resetPlayers() {
  for (u8 i = 0; i < 12; i++) {
    RaceConfigPlayer* player = getPlayer(i);
    player->mLocalPlayerNum = -1;
    player->mPlayerInputIdx = -1;
  }

  for (u8 i = 0; i < 4; i++) {
    mSettings.mHudPlayerIds[i] = -1;
  }
}

} // namespace System

// Symbol: unk_8052f064
// PAL: 0x8052f064..0x8052f1e0
// Scratch: https://decomp.me/scratch/ANzFM
MARK_BINARY_BLOB(unk_8052f064, 0x8052f064, 0x8052f1e0);
asm UNKNOWN_FUNCTION(unk_8052f064) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  li r0, 0;
  stw r31, 0xc(r1);
  stw r30, 8(r1);
  lwz r5, 0xb50(r3);
  cmpwi r5, 7;
  blt lbl_8052f08c;
  cmpwi r5, 0xa;
  bgt lbl_8052f08c;
  li r0, 1;
lbl_8052f08c:
  cmpwi r0, 0;
  bne lbl_8052f1d0;
  cmpwi r4, 0;
  li r5, 0;
  beq lbl_8052f1d0;
  cmplwi r4, 8;
  addi r0, r4, 0xf8;
  ble lbl_8052f194;
  clrlwi r6, r0, 0x18;
  li r12, 0;
  addi r0, r6, 7;
  srwi r0, r0, 3;
  mtctr r0;
  cmplwi r6, 0;
  ble lbl_8052f194;
lbl_8052f0c8:
  clrlwi r8, r5, 0x18;
  addi r6, r5, 1;
  mulli r7, r8, 0xf0;
  addi r0, r5, 2;
  clrlwi r11, r6, 0x18;
  clrlwi r10, r0, 0x18;
  add r31, r3, r7;
  addi r0, r5, 3;
  sth r12, 0xe0(r31);
  clrlwi r9, r0, 0x18;
  subf r30, r8, r4;
  addi r0, r5, 4;
  stb r30, 0xe9(r31);
  clrlwi r8, r0, 0x18;
  addi r7, r5, 5;
  addi r6, r5, 6;
  stb r30, 0xe8(r31);
  addi r0, r5, 7;
  clrlwi r7, r7, 0x18;
  clrlwi r6, r6, 0x18;
  sth r12, 0x1d0(r31);
  subf r11, r11, r4;
  clrlwi r0, r0, 0x18;
  subf r10, r10, r4;
  stb r11, 0x1d9(r31);
  subf r9, r9, r4;
  subf r8, r8, r4;
  subf r7, r7, r4;
  stb r11, 0x1d8(r31);
  subf r6, r6, r4;
  subf r0, r0, r4;
  addi r5, r5, 8;
  sth r12, 0x2c0(r31);
  stb r10, 0x2c9(r31);
  stb r10, 0x2c8(r31);
  sth r12, 0x3b0(r31);
  stb r9, 0x3b9(r31);
  stb r9, 0x3b8(r31);
  sth r12, 0x4a0(r31);
  stb r8, 0x4a9(r31);
  stb r8, 0x4a8(r31);
  sth r12, 0x590(r31);
  stb r7, 0x599(r31);
  stb r7, 0x598(r31);
  sth r12, 0x680(r31);
  stb r6, 0x689(r31);
  stb r6, 0x688(r31);
  sth r12, 0x770(r31);
  stb r0, 0x779(r31);
  stb r0, 0x778(r31);
  bdnz lbl_8052f0c8;
lbl_8052f194:
  clrlwi r6, r5, 0x18;
  li r7, 0;
  subf r0, r6, r4;
  mtctr r0;
  cmplw r6, r4;
  bge lbl_8052f1d0;
lbl_8052f1ac:
  clrlwi r6, r5, 0x18;
  addi r5, r5, 1;
  mulli r0, r6, 0xf0;
  subf r8, r6, r4;
  add r6, r3, r0;
  sth r7, 0xe0(r6);
  stb r8, 0xe9(r6);
  stb r8, 0xe8(r6);
  bdnz lbl_8052f1ac;
lbl_8052f1d0:
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: copyPrevPositions__Q26System12MenuScenarioFv
// PAL: 0x8052f1e0..0x8052f4e8
// Scratch: https://decomp.me/scratch/w7jKr
MARK_BINARY_BLOB(copyPrevPositions__Q26System12MenuScenarioFv, 0x8052f1e0,
                 0x8052f4e8);
asm UNKNOWN_FUNCTION(copyPrevPositions__Q26System12MenuScenarioFv) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  lwz r0, 0xb50(r3);
  cmpwi r0, 0;
  bne lbl_8052f228;
  lbz r4, 0xb6c(r3);
  cmplwi r4, 4;
  bgt lbl_8052f228;
  lwz r0, 0xb54(r3);
  cmpwi r0, 1;
  beq lbl_8052f228;
  lwz r0, 0xb68(r3);
  lis r5, 0;
  addi r5, r5, 0;
  rlwinm r4, r4, 2, 0x16, 0x1d;
  slwi r0, r0, 4;
  add r0, r5, r0;
  lwzx r0, r4, r0;
  stw r0, 0xb48(r3);
lbl_8052f228:
  lwz r4, 0xb50(r3);
  li r0, 0;
  cmpwi r4, 7;
  blt lbl_8052f244;
  cmpwi r4, 0xa;
  bgt lbl_8052f244;
  li r0, 1;
lbl_8052f244:
  cmpwi r0, 0;
  beq lbl_8052f4e0;
  li r11, 1;
  li r9, 2;
  stb r9, 9(r1);
  li r8, 3;
  li r7, 4;
  li r6, 5;
  stb r8, 0xa(r1);
  li r4, 6;
  li r10, 7;
  li r9, 8;
  stb r7, 0xb(r1);
  li r8, 9;
  li r7, 0xa;
  addi r5, r1, 8;
  stb r6, 0xc(r1);
  li r6, 0xb;
  li r12, 1;
  li r0, 3;
  stb r4, 0xd(r1);
  li r4, 0xc;
  stb r11, 8(r1);
  stb r10, 0xe(r1);
  stb r9, 0xf(r1);
  stb r8, 0x10(r1);
  stb r7, 0x11(r1);
  stb r6, 0x12(r1);
  stb r4, 0x13(r1);
lbl_8052f2b8:
  clrlwi r7, r12, 0x18;
  li r9, 0;
  mtctr r0;
lbl_8052f2c4:
  clrlwi r4, r9, 0x18;
  mulli r6, r4, 0xf0;
  add r6, r3, r6;
  lwz r8, 0x18(r6);
  cmpwi r8, 5;
  beq lbl_8052f2f0;
  lbz r6, 0xe9(r6);
  cmplw r7, r6;
  bne lbl_8052f2f0;
  stbx r11, r5, r4;
  addi r11, r11, 1;
lbl_8052f2f0:
  addi r9, r9, 1;
  clrlwi r4, r9, 0x18;
  mulli r6, r4, 0xf0;
  add r6, r3, r6;
  lwz r8, 0x18(r6);
  cmpwi r8, 5;
  beq lbl_8052f320;
  lbz r6, 0xe9(r6);
  cmplw r7, r6;
  bne lbl_8052f320;
  stbx r11, r5, r4;
  addi r11, r11, 1;
lbl_8052f320:
  addi r9, r9, 1;
  clrlwi r4, r9, 0x18;
  mulli r6, r4, 0xf0;
  add r6, r3, r6;
  lwz r8, 0x18(r6);
  cmpwi r8, 5;
  beq lbl_8052f350;
  lbz r6, 0xe9(r6);
  cmplw r7, r6;
  bne lbl_8052f350;
  stbx r11, r5, r4;
  addi r11, r11, 1;
lbl_8052f350:
  addi r9, r9, 1;
  clrlwi r4, r9, 0x18;
  mulli r6, r4, 0xf0;
  add r6, r3, r6;
  lwz r8, 0x18(r6);
  cmpwi r8, 5;
  beq lbl_8052f380;
  lbz r6, 0xe9(r6);
  cmplw r7, r6;
  bne lbl_8052f380;
  stbx r11, r5, r4;
  addi r11, r11, 1;
lbl_8052f380:
  addi r9, r9, 1;
  bdnz lbl_8052f2c4;
  addi r12, r12, 1;
  cmplwi r12, 0xc;
  ble lbl_8052f2b8;
  li r0, 3;
  addi r4, r1, 8;
  li r7, 0;
  mtctr r0;
lbl_8052f3a4:
  clrlwi r0, r7, 0x18;
  mulli r5, r0, 0xf0;
  add r5, r3, r5;
  lwz r6, 0x18(r5);
  cmpwi r6, 5;
  beq lbl_8052f3d0;
  lbz r5, 0xe9(r5);
  cmpwi r5, 0;
  bne lbl_8052f3d0;
  stbx r11, r4, r0;
  addi r11, r11, 1;
lbl_8052f3d0:
  addi r7, r7, 1;
  clrlwi r0, r7, 0x18;
  mulli r5, r0, 0xf0;
  add r5, r3, r5;
  lwz r6, 0x18(r5);
  cmpwi r6, 5;
  beq lbl_8052f400;
  lbz r5, 0xe9(r5);
  cmpwi r5, 0;
  bne lbl_8052f400;
  stbx r11, r4, r0;
  addi r11, r11, 1;
lbl_8052f400:
  addi r7, r7, 1;
  clrlwi r0, r7, 0x18;
  mulli r5, r0, 0xf0;
  add r5, r3, r5;
  lwz r6, 0x18(r5);
  cmpwi r6, 5;
  beq lbl_8052f430;
  lbz r5, 0xe9(r5);
  cmpwi r5, 0;
  bne lbl_8052f430;
  stbx r11, r4, r0;
  addi r11, r11, 1;
lbl_8052f430:
  addi r7, r7, 1;
  clrlwi r0, r7, 0x18;
  mulli r5, r0, 0xf0;
  add r5, r3, r5;
  lwz r6, 0x18(r5);
  cmpwi r6, 5;
  beq lbl_8052f460;
  lbz r5, 0xe9(r5);
  cmpwi r5, 0;
  bne lbl_8052f460;
  stbx r11, r4, r0;
  addi r11, r11, 1;
lbl_8052f460:
  addi r7, r7, 1;
  bdnz lbl_8052f3a4;
  li r0, 0;
  lbz r8, 8(r1);
  mulli r10, r0, 0xf0;
  lbz r7, 9(r1);
  lbz r6, 0xa(r1);
  li r0, 6;
  lbz r5, 0xb(r1);
  add r9, r3, r10;
  stb r8, 0xe9(r9);
  mulli r10, r0, 0xf0;
  lbz r4, 0xc(r1);
  stb r7, 0x1d9(r9);
  lbz r0, 0xd(r1);
  stb r6, 0x2c9(r9);
  lbz r8, 0xe(r1);
  stb r5, 0x3b9(r9);
  lbz r7, 0xf(r1);
  stb r4, 0x4a9(r9);
  lbz r6, 0x10(r1);
  stb r0, 0x599(r9);
  add r9, r3, r10;
  lbz r5, 0x11(r1);
  stb r8, 0xe9(r9);
  lbz r4, 0x12(r1);
  stb r7, 0x1d9(r9);
  lbz r0, 0x13(r1);
  stb r6, 0x2c9(r9);
  stb r5, 0x3b9(r9);
  stb r4, 0x4a9(r9);
  stb r0, 0x599(r9);
lbl_8052f4e0:
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: initControllers__Q26System12MenuScenarioFUc
// PAL: 0x8052f4e8..0x8052f788
// Scratch: https://decomp.me/scratch/V2Pce
MARK_BINARY_BLOB(initControllers__Q26System12MenuScenarioFUc, 0x8052f4e8,
                 0x8052f788);
asm UNKNOWN_FUNCTION(initControllers__Q26System12MenuScenarioFUc) {
  // clang-format off
  nofralloc;
  stwu r1, -0x110(r1);
  mflr r0;
  stw r0, 0x114(r1);
  stmw r21, 0xe4(r1);
  li r29, -1;
  mr r24, r3;
  mr r25, r4;
  li r28, 0;
  li r27, 0;
  li r26, 0;
  lis r31, 0;
  lis r22, 0;
  li r23, 5;
  stb r29, 0xb64(r3);
  stb r29, 0xb65(r3);
  stb r29, 0xb66(r3);
  stb r29, 0xb67(r3);
lbl_8052f52c:
  clrlwi r0, r26, 0x18;
  mulli r0, r0, 0xf0;
  add r30, r24, r0;
  lwz r0, 0x18(r30);
  cmpwi r0, 0;
  beq lbl_8052f558;
  cmpwi r0, 3;
  beq lbl_8052f5c0;
  cmpwi r0, 1;
  beq lbl_8052f664;
  b lbl_8052f668;
lbl_8052f558:
  stb r28, 0xd(r30);
  clrlwi r0, r27, 0x18;
  mulli r0, r0, 0xec;
  stb r27, 0xe(r30);
  lwz r3, 0(r31);
  add r3, r3, r0;
  lwz r3, 8(r3);
  cmpwi r3, 0;
  beq lbl_8052f590;
  lwz r12, 0(r3);
  lwz r12, 0x10(r12);
  mtctr r12;
  bctrl;
  b lbl_8052f594;
lbl_8052f590:
  li r3, -1;
lbl_8052f594:
  extsb r0, r28;
  stw r3, 0xd8(r30);
  add r3, r24, r0;
  lbz r0, 0xb64(r3);
  extsb r0, r0;
  cmpwi r0, -1;
  bne lbl_8052f5b4;
  stb r26, 0xb64(r3);
lbl_8052f5b4:
  addi r28, r28, 1;
  addi r27, r27, 1;
  b lbl_8052f668;
lbl_8052f5c0:
  lwz r3, 0xbec(r24);
  li r21, 0;
  bl isValid__Q26System12RawGhostFileCFv;
  cmpwi r3, 0;
  beq lbl_8052f648;
  addi r3, r1, 8;
  bl __ct__Q26System9GhostFileFv;
  lwz r4, 0xbec(r24);
  addi r3, r1, 8;
  bl read__Q26System9GhostFileFRCQ26System12RawGhostFile;
  lwz r3, 0xc0(r1);
  lwz r0, 0xb48(r24);
  cmpw r3, r0;
  bne lbl_8052f634;
  extsb. r0, r27;
  blt lbl_8052f614;
  lwz r3, 0(r31);
  clrlwi r4, r27, 0x18;
  lwz r5, 0xdc(r1);
  lbz r6, 0xd0(r1);
  bl InputMgr_setGhostController;
lbl_8052f614:
  lwz r0, 0xb8(r1);
  li r21, 1;
  stw r0, 0x14(r30);
  lwz r0, 0xbc(r1);
  stw r0, 0x10(r30);
  stb r27, 0xe(r30);
  lwz r0, 0xc4(r1);
  stw r0, 0xd8(r30);
lbl_8052f634:
  addi r3, r1, 0x70;
  addi r4, r22, 0;
  li r5, 0xc;
  li r6, 5;
  bl unk_805553b0;
lbl_8052f648:
  cmpwi r21, 0;
  beq lbl_8052f658;
  addi r27, r27, 1;
  b lbl_8052f668;
lbl_8052f658:
  stw r23, 0x18(r30);
  stw r29, 0xd8(r30);
  b lbl_8052f668;
lbl_8052f664:
  stw r29, 0xd8(r30);
lbl_8052f668:
  addi r26, r26, 1;
  cmplwi r26, 0xc;
  blt lbl_8052f52c;
  extsb r0, r28;
  cmpw r0, r25;
  bge lbl_8052f774;
  li r0, 4;
  li r5, 0;
  mtctr r0;
lbl_8052f68c:
  clrlwi r0, r5, 0x18;
  mulli r0, r0, 0xf0;
  add r4, r24, r0;
  lwz r0, 0x18(r4);
  cmpwi r0, 5;
  beq lbl_8052f6d4;
  lbz r0, 0xd(r4);
  extsb r0, r0;
  cmpwi r0, -1;
  bne lbl_8052f6d4;
  extsb r3, r28;
  stb r28, 0xd(r4);
  addi r28, r28, 1;
  extsb r0, r28;
  add r3, r24, r3;
  cmpw r0, r25;
  stb r5, 0xb64(r3);
  bge lbl_8052f774;
lbl_8052f6d4:
  addi r5, r5, 1;
  clrlwi r0, r5, 0x18;
  mulli r0, r0, 0xf0;
  add r4, r24, r0;
  lwz r0, 0x18(r4);
  cmpwi r0, 5;
  beq lbl_8052f720;
  lbz r0, 0xd(r4);
  extsb r0, r0;
  cmpwi r0, -1;
  bne lbl_8052f720;
  extsb r3, r28;
  stb r28, 0xd(r4);
  addi r28, r28, 1;
  extsb r0, r28;
  add r3, r24, r3;
  cmpw r0, r25;
  stb r5, 0xb64(r3);
  bge lbl_8052f774;
lbl_8052f720:
  addi r5, r5, 1;
  clrlwi r0, r5, 0x18;
  mulli r0, r0, 0xf0;
  add r4, r24, r0;
  lwz r0, 0x18(r4);
  cmpwi r0, 5;
  beq lbl_8052f76c;
  lbz r0, 0xd(r4);
  extsb r0, r0;
  cmpwi r0, -1;
  bne lbl_8052f76c;
  extsb r3, r28;
  stb r28, 0xd(r4);
  addi r28, r28, 1;
  extsb r0, r28;
  add r3, r24, r3;
  cmpw r0, r25;
  stb r5, 0xb64(r3);
  bge lbl_8052f774;
lbl_8052f76c:
  addi r5, r5, 1;
  bdnz lbl_8052f68c;
lbl_8052f774:
  lmw r21, 0xe4(r1);
  lwz r0, 0x114(r1);
  mtlr r0;
  addi r1, r1, 0x110;
  blr;
  // clang-format on
}

namespace System {

void MenuScenario::computePlayerCounts(u8* playerCount, u8* hudCount,
                                       u8* localPlayerCount) {
  u8 playerCount_ = 0;
  u8 hudCount_ = 0;
  u8 localPlayerCount_ = 0;

  for (u8 i = 0; i < 12; i++) {
    const s32 playerType = mPlayers[i].mPlayerType;

    // Check if player exists
    if (playerType == 5) {
      continue;
    }
    playerCount_++;

    // Check if player is local
    if (playerType != 0) {
      continue;
    }

    // Increment HUD count
    if (hudCount_ < 4) {
      hudCount_++;
    }

    localPlayerCount_++;
  }

  // Correct HUD counts
  if (hudCount_ == 0) {
    hudCount_ = 1;
  }
  if (hudCount_ == 3) {
    hudCount_ = 4;
  }

  // Set HUD count based on menu game type
  const s32 gameType = mSettings.mGameType;
  if (gameType == 2) {
    hudCount_ = 1;
  } else if (gameType == 3) {
    hudCount_ = 2;
  } else if (gameType == 4) {
    hudCount_ = 4;
  }

  // Cap player count on awards
  if (mSettings.mGameMode == 11) {
    if (gameType == 7) {
      // Cap player count on GP win
      if (3 < playerCount_) {
        playerCount_ = 3;
      }
    } else if (6 < playerCount_) {
      playerCount_ = 6;
    }
  }

  *playerCount = playerCount_;
  *hudCount = hudCount_;
  *localPlayerCount = localPlayerCount_;
}

} // namespace System

// Symbol: initRng__Q26System12MenuScenarioFv
// PAL: 0x8052f924..0x8052fa0c
// Scratch: https://decomp.me/scratch/Y23JS
MARK_BINARY_BLOB(initRng__Q26System12MenuScenarioFv, 0x8052f924, 0x8052fa0c);
asm UNKNOWN_FUNCTION(initRng__Q26System12MenuScenarioFv) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  mr r31, r3;
  lwz r4, 0xb50(r3);
  cmpwi r4, 4;
  blt lbl_8052f94c;
  cmpwi r4, 5;
  ble lbl_8052f954;
lbl_8052f94c:
  cmpwi r4, 2;
  bne lbl_8052f974;
lbl_8052f954:
  lis r4, 0x74a2;
  addi r0, r4, -20331;
  stw r0, 0xb74(r3);
  bl unk_805553b0;
  rlwinm r0, r3, 0x1d, 3, 0xf;
  rlwimi r0, r3, 5, 0x1b, 0x1f;
  stw r0, 0xb78(r31);
  b lbl_8052f9f8;
lbl_8052f974:
  lwz r0, 0xb70(r3);
  rlwinm. r0, r0, 0, 0x1d, 0x1d;
  beq lbl_8052f9a0;
  lis r4, 0x92bc;
  addi r0, r4, 0x7d03;
  stw r0, 0xb74(r3);
  bl unk_805553b0;
  rlwinm r0, r3, 0x1d, 3, 0xf;
  rlwimi r0, r3, 5, 0x1b, 0x1f;
  stw r0, 0xb78(r31);
  b lbl_8052f9f8;
lbl_8052f9a0:
  lwz r0, 0xb54(r3);
  cmpwi r0, 1;
  beq lbl_8052f9f8;
  cmpwi r4, 7;
  li r0, 0;
  blt lbl_8052f9c4;
  cmpwi r4, 0xa;
  bgt lbl_8052f9c4;
  li r0, 1;
lbl_8052f9c4:
  cmpwi r0, 0;
  bne lbl_8052f9f8;
  bl unk_805553b0;
  srwi r0, r3, 0x14;
  rlwinm r5, r3, 0x19, 7, 7;
  rlwinm r4, r3, 0xc, 0x18, 0x1f;
  rotlwi r6, r3, 0x18;
  rlwinm r0, r0, 0, 8, 0xf;
  rlwimi r5, r3, 0x19, 0x10, 0x17;
  or r0, r4, r0;
  stw r6, 0xb74(r31);
  or r0, r5, r0;
  stw r0, 0xb78(r31);
lbl_8052f9f8:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: unk_8052fa0c
// PAL: 0x8052fa0c..0x8052fb90
// Scratch: https://decomp.me/scratch/UHaS4
MARK_BINARY_BLOB(unk_8052fa0c, 0x8052fa0c, 0x8052fb90);
asm UNKNOWN_FUNCTION(unk_8052fa0c) {
  // clang-format off
  nofralloc;
  stwu r1, -0xa0(r1);
  mflr r0;
  li r4, 0;
  li r5, 0x70;
  stw r0, 0xa4(r1);
  stw r31, 0x9c(r1);
  mr r31, r3;
  addi r3, r1, 0x28;
  bl unk_805553b0;
  lis r3, 0;
  li r0, 0;
  stb r0, 8(r1);
  addi r4, r1, 8;
  lwz r3, 0(r3);
  stw r0, 0xc(r1);
  bl unk_8066c8d8;
  lwz r5, 0xc(r1);
  lhz r0, 0x14(r5);
  cmpwi r0, 0;
  beq lbl_8052fb7c;
  cmpwi r0, 1;
  bne lbl_8052fa68;
  b lbl_8052fb7c;
lbl_8052fa68:
  lis r3, 0;
  rlwinm r4, r0, 2, 0xe, 0x1d;
  addi r3, r3, 0;
  li r0, 0xb;
  lwzx r3, r3, r4;
  sth r3, 0x2a(r1);
  lbz r3, 0x16(r5);
  stb r3, 0x2c(r1);
  lbz r3, 0x17(r5);
  stb r3, 0x2f(r1);
  lbz r3, 0x3e(r5);
  stb r3, 0x57(r1);
  lhz r3, 0x42(r5);
  stw r3, 0x58(r1);
  lhz r3, 0x42(r5);
  stw r3, 0x5c(r1);
  lhz r3, 0x42(r5);
  stw r3, 0x60(r1);
  lhz r3, 0x42(r5);
  stw r3, 0x64(r1);
  lhz r3, 0x42(r5);
  stw r3, 0x68(r1);
  lhz r3, 0x42(r5);
  stw r3, 0x6c(r1);
  lhz r3, 0x1c(r5);
  sth r3, 0x70(r1);
  lhz r3, 0x1e(r5);
  sth r3, 0x72(r1);
  lhz r3, 0x20(r5);
  sth r3, 0x74(r1);
  lhz r3, 0x22(r5);
  sth r3, 0x76(r1);
  lhz r3, 0x24(r5);
  sth r3, 0x78(r1);
  lhz r3, 0x26(r5);
  cmplwi r3, 0xb;
  bge lbl_8052fb00;
  mr r0, r3;
lbl_8052fb00:
  sth r0, 0x80(r1);
  li r6, 0;
  lwz r4, 0xc(r1);
  b lbl_8052fb34;
lbl_8052fb10:
  rlwinm r0, r6, 1, 0x17, 0x1e;
  addi r5, r1, 0x28;
  add r3, r4, r0;
  addi r6, r6, 1;
  add r5, r5, r0;
  lbz r0, 0x28(r3);
  stb r0, 0x5a(r5);
  lbz r0, 0x29(r3);
  stb r0, 0x5b(r5);
lbl_8052fb34:
  lhz r5, 0x26(r4);
  clrlwi r3, r6, 0x18;
  li r0, 0xb;
  cmplwi r5, 0xb;
  bge lbl_8052fb4c;
  mr r0, r5;
lbl_8052fb4c:
  clrlwi r0, r0, 0x10;
  cmpw r3, r0;
  blt lbl_8052fb10;
  li r0, 0xe;
  addi r5, r31, 0xb78;
  addi r4, r1, 0x24;
  mtctr r0;
lbl_8052fb68:
  lwz r3, 4(r4);
  lwzu r0, 8(r4);
  stw r3, 4(r5);
  stwu r0, 8(r5);
  bdnz lbl_8052fb68;
lbl_8052fb7c:
  lwz r0, 0xa4(r1);
  lwz r31, 0x9c(r1);
  mtlr r0;
  addi r1, r1, 0xa0;
  blr;
  // clang-format on
}

namespace System {

void MenuScenario::initRace(RaceScenario* raceScenario) {
  u8 playerCount = 0;
  u8 hudCount = 0;
  u8 localPlayerCount = 0;

  if (mSettings.mModeFlags & 4) {
    unk_8052fa0c();
  }

  copyPrevPositions();

  for (u8 i = 0; i < 12; i++) {
    RaceConfigPlayer* player = getPlayer(i);
    player->mLocalPlayerNum = -1;
    player->mPlayerInputIdx = -1;
  }

  for (u8 i = 0; i < 4; i++) {
    mSettings.mHudPlayerIds[i] = -1;
  }

  computePlayerCounts(&playerCount, &hudCount, &localPlayerCount);

  u8 hudCount_ = hudCount;
  if (mSettings.mGameType == 5) {
    hudCount = 1;
  }

  if (mSettings.mRaceNumber == 0) {
    u8 playerCount_ = playerCount;
    if (!isOnline(mSettings.mGameMode)) {
      for (u8 i = 0; i < playerCount_; i++) {
        RaceConfigPlayer* player = getPlayer(i);
        player->mPreviousScore = 0;
        player->mPrevFinishPos = playerCount_ - i;
        player->_e0 = playerCount_ - i;
      }
    }
  }

  initControllers(hudCount);
  postInitControllers(raceScenario);
  initRng();

  mPlayerCount = playerCount;
  mHudCount = hudCount;
  mHudCount2 = hudCount_;
  mLocalPlayerCount = localPlayerCount;
}

} // namespace System

// Symbol: Racedata_initStaticInstance
// PAL: 0x8052fe58..0x8052ffe8
// Scratch: N/A (trivial to match when RaceConfig ctor matches)
MARK_BINARY_BLOB(Racedata_initStaticInstance, 0x8052fe58, 0x8052ffe8);
asm UNKNOWN_FUNCTION(Racedata_initStaticInstance) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  lis r3, 0;
  stw r0, 0x24(r1);
  stmw r26, 8(r1);
  lwz r0, 0(r3);
  cmpwi r0, 0;
  bne lbl_8052ffcc;
  li r3, 0x73f0;
  bl unk_805553b0;
  cmpwi r3, 0;
  mr r26, r3;
  beq lbl_8052ffc4;
  lis r4, 0;
  li r5, 0;
  addi r4, r4, 0;
  bl unk_805553b0;
  lis r3, 0;
  lis r27, 0;
  addi r3, r3, 0;
  stw r3, 0x1c(r26);
  addi r0, r3, 8;
  lis r29, 0;
  stw r0, 0(r26);
  addi r27, r27, 0;
  lis r30, 0;
  li r28, 0;
  stw r27, 0x20(r26);
  addi r3, r26, 0x28;
  addi r4, r29, 0;
  addi r5, r30, 0;
  stb r28, 0x24(r26);
  li r6, 0xf0;
  li r7, 0xc;
  stb r28, 0x25(r26);
  bl unk_805553b0;
  li r31, 0x11;
  stw r31, 0xb68(r26);
  addi r3, r26, 0xb9c;
  li r4, 0;
  stw r28, 0xb70(r26);
  li r5, 0x70;
  stw r28, 0xb74(r26);
  stw r28, 0xb88(r26);
  bl unk_805553b0;
  addi r0, r26, 0x23f0;
  stw r0, 0xc0c(r26);
  addi r3, r26, 0xc18;
  addi r4, r29, 0;
  stw r27, 0xc10(r26);
  addi r5, r30, 0;
  li r6, 0xf0;
  li r7, 0xc;
  stb r28, 0xc14(r26);
  stb r28, 0xc15(r26);
  bl unk_805553b0;
  stw r31, 0x1758(r26);
  addi r3, r26, 0x178c;
  li r4, 0;
  li r5, 0x70;
  stw r28, 0x1760(r26);
  stw r28, 0x1764(r26);
  stw r28, 0x1778(r26);
  bl unk_805553b0;
  addi r0, r26, 0x4bf0;
  stw r0, 0x17fc(r26);
  addi r3, r26, 0x1808;
  addi r4, r29, 0;
  stw r27, 0x1800(r26);
  addi r5, r30, 0;
  li r6, 0xf0;
  li r7, 0xc;
  stb r28, 0x1804(r26);
  stb r28, 0x1805(r26);
  bl unk_805553b0;
  stw r31, 0x2348(r26);
  addi r3, r26, 0x237c;
  li r4, 0;
  li r5, 0x70;
  stw r28, 0x2350(r26);
  stw r28, 0x2354(r26);
  stw r28, 0x2368(r26);
  bl unk_805553b0;
  stw r28, 0x23ec(r26);
  addi r27, r26, 0x23f0;
  addi r31, r26, 0x73f0;
lbl_8052ffb0:
  mr r3, r27;
  bl reset__Q26System12RawGhostFileFv;
  addi r27, r27, 0x2800;
  cmplw r27, r31;
  blt lbl_8052ffb0;
lbl_8052ffc4:
  lis r3, 0;
  stw r26, 0(r3);
lbl_8052ffcc:
  lmw r26, 8(r1);
  lis r3, 0;
  lwz r0, 0x24(r1);
  lwz r3, 0(r3);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

// Symbol: Racedata_destroyStaticInstance
// PAL: 0x8052ffe8..0x80530038
// Scratch: https://decomp.me/scratch/sGUYR
MARK_BINARY_BLOB(Racedata_destroyStaticInstance, 0x8052ffe8, 0x80530038);
asm UNKNOWN_FUNCTION(Racedata_destroyStaticInstance) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r3, 0;
  stw r0, 0x14(r1);
  lwz r3, 0(r3);
  cmpwi r3, 0;
  beq lbl_8053001c;
  beq lbl_8053001c;
  lwz r12, 0x1c(r3);
  li r4, 1;
  lwz r12, 0x24(r12);
  mtctr r12;
  bctrl;
lbl_8053001c:
  lis r3, 0;
  li r0, 0;
  stw r0, 0(r3);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: Racedata_destroy
// PAL: 0x80530038..0x805300f4
// Scratch: https://decomp.me/scratch/Fhjji
MARK_BINARY_BLOB(Racedata_destroy, 0x80530038, 0x805300f4);
asm UNKNOWN_FUNCTION(Racedata_destroy) {
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
  beq lbl_805300d8;
  addic. r3, r3, 0x1800;
  beq lbl_8053007c;
  lis r4, 0;
  addi r3, r3, 8;
  addi r4, r4, 0;
  li r5, 0xf0;
  li r6, 0xc;
  bl unk_805553b0;
lbl_8053007c:
  addic. r3, r30, 0xc10;
  beq lbl_8053009c;
  lis r4, 0;
  addi r3, r3, 8;
  addi r4, r4, 0;
  li r5, 0xf0;
  li r6, 0xc;
  bl unk_805553b0;
lbl_8053009c:
  addic. r3, r30, 0x20;
  beq lbl_805300bc;
  lis r4, 0;
  addi r3, r3, 8;
  addi r4, r4, 0;
  li r5, 0xf0;
  li r6, 0xc;
  bl unk_805553b0;
lbl_805300bc:
  mr r3, r30;
  li r4, 0;
  bl unk_805553b0;
  cmpwi r31, 0;
  ble lbl_805300d8;
  mr r3, r30;
  bl unk_805553b0;
lbl_805300d8:
  mr r3, r30;
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Requires RaceConfigPlayer vtable
#ifdef NON_MATCHING
namespace System {

RaceConfigScenario::~RaceConfigScenario() {}

} // namespace System
#else
// Symbol: RacedataScenario_destroy
// PAL: 0x805300f4..0x8053015c
MARK_BINARY_BLOB(RacedataScenario_destroy, 0x805300f4, 0x8053015c);
asm UNKNOWN_FUNCTION(RacedataScenario_destroy) {
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
  beq lbl_80530140;
  lis r4, 0;
  li r5, 0xf0;
  addi r4, r4, 0;
  li r6, 0xc;
  addi r3, r3, 8;
  bl unk_805553b0;
  cmpwi r31, 0;
  ble lbl_80530140;
  mr r3, r30;
  bl unk_805553b0;
lbl_80530140:
  mr r3, r30;
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}
#endif

// Requires rodata from unk_8052e870 and unk_8052fa0c first
// Also may be a complete non-match
#ifdef NON_MATCHING
namespace System {

RaceConfig::RaceConfig()
    : ParameterFile("/boot/menuset.prm", 0), mRaceScenario(&mGhosts[0]),
      mMenuScenario(&mGhosts[1]), mAwardsScenario(nullptr) {}

} // namespace System
#else
// Symbol: Racedata_construct
// PAL: 0x8053015c..0x805302c4
// Scratch: https://decomp.me/scratch/ZyQzz
MARK_BINARY_BLOB(Racedata_construct, 0x8053015c, 0x805302c4);
asm UNKNOWN_FUNCTION(Racedata_construct) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  lis r4, 0;
  li r5, 0;
  stw r0, 0x24(r1);
  addi r4, r4, 0;
  addi r4, r4, 0x12;
  stmw r26, 8(r1);
  mr r26, r3;
  bl unk_805553b0;
  lis r3, 0;
  li r28, 0;
  addi r3, r3, 0;
  lis r27, 0;
  addi r0, r3, 8;
  lis r29, 0;
  addi r27, r27, 0;
  lis r30, 0;
  stw r3, 0x1c(r26);
  addi r3, r26, 0x28;
  addi r4, r29, 0;
  addi r5, r30, 0;
  stw r0, 0(r26);
  li r6, 0xf0;
  li r7, 0xc;
  stw r27, 0x20(r26);
  stb r28, 0x24(r26);
  stb r28, 0x25(r26);
  bl unk_805553b0;
  li r31, 0x11;
  stw r31, 0xb68(r26);
  addi r3, r26, 0xb9c;
  li r4, 0;
  stw r28, 0xb70(r26);
  li r5, 0x70;
  stw r28, 0xb74(r26);
  stw r28, 0xb88(r26);
  bl unk_805553b0;
  addi r0, r26, 0x23f0;
  stw r0, 0xc0c(r26);
  addi r3, r26, 0xc18;
  addi r4, r29, 0;
  stw r27, 0xc10(r26);
  addi r5, r30, 0;
  li r6, 0xf0;
  li r7, 0xc;
  stb r28, 0xc14(r26);
  stb r28, 0xc15(r26);
  bl unk_805553b0;
  stw r31, 0x1758(r26);
  addi r3, r26, 0x178c;
  li r4, 0;
  li r5, 0x70;
  stw r28, 0x1760(r26);
  stw r28, 0x1764(r26);
  stw r28, 0x1778(r26);
  bl unk_805553b0;
  addi r0, r26, 0x4bf0;
  stw r0, 0x17fc(r26);
  addi r3, r26, 0x1808;
  addi r4, r29, 0;
  stw r27, 0x1800(r26);
  addi r5, r30, 0;
  li r6, 0xf0;
  li r7, 0xc;
  stb r28, 0x1804(r26);
  stb r28, 0x1805(r26);
  bl unk_805553b0;
  stw r31, 0x2348(r26);
  addi r3, r26, 0x237c;
  li r4, 0;
  li r5, 0x70;
  stw r28, 0x2350(r26);
  stw r28, 0x2354(r26);
  stw r28, 0x2368(r26);
  bl unk_805553b0;
  stw r28, 0x23ec(r26);
  addi r27, r26, 0x23f0;
  addi r31, r26, 0x73f0;
lbl_80530298:
  mr r3, r27;
  bl reset__Q26System12RawGhostFileFv;
  addi r27, r27, 0x2800;
  cmplw r27, r31;
  blt lbl_80530298;
  mr r3, r26;
  lmw r26, 8(r1);
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}
#endif

// Symbol: Racedata_initRace
// PAL: 0x805302c4..0x805305ac
// Scratch: https://decomp.me/scratch/2bYoM
MARK_BINARY_BLOB(Racedata_initRace, 0x805302c4, 0x805305ac);
asm UNKNOWN_FUNCTION(Racedata_initRace) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  stmw r22, 8(r1);
  mr r31, r3;
  addi r3, r3, 0xc10;
  addi r4, r31, 0x20;
  bl initRace__Q26System12MenuScenarioFPQ26System12RaceScenario;
  lbz r9, 0xc14(r31);
  addi r4, r31, 0x28;
  lbz r8, 0xc15(r31);
  addi r3, r31, 0xc18;
  lbz r7, 0xc16(r31);
  addi r5, r31, 0xb68;
  lbz r6, 0xc17(r31);
  li r0, 0x26;
  stb r9, 0x24(r31);
  stb r8, 0x25(r31);
  stb r7, 0x26(r31);
  stb r6, 0x27(r31);
lbl_80530314:
  lbz r6, 4(r3);
  addi r9, r4, 0x23;
  stb r6, 4(r4);
  addi r8, r3, 0x23;
  lbz r6, 5(r3);
  stb r6, 5(r4);
  lbz r6, 6(r3);
  stb r6, 6(r4);
  lwz r6, 8(r3);
  stw r6, 8(r4);
  lwz r6, 0xc(r3);
  stw r6, 0xc(r4);
  lwz r6, 0x10(r3);
  stw r6, 0x10(r4);
  lwz r6, 0x18(r3);
  stw r6, 0x18(r4);
  lbz r6, 0x1c(r3);
  stb r6, 0x1c(r4);
  lbz r6, 0x1d(r3);
  stb r6, 0x1d(r4);
  lwz r6, 0x20(r3);
  stw r6, 0x20(r4);
  mtctr r0;
lbl_80530370:
  lbz r7, 1(r8);
  lbzu r6, 2(r8);
  stb r7, 1(r9);
  stbu r6, 2(r9);
  bdnz lbl_80530370;
  lwz r6, 0x70(r3);
  stw r6, 0x70(r4);
  lbz r6, 0x74(r3);
  stb r6, 0x74(r4);
  lbz r6, 0x75(r3);
  stb r6, 0x75(r4);
  lbz r6, 0x76(r3);
  stb r6, 0x76(r4);
  lbz r6, 0x77(r3);
  stb r6, 0x77(r4);
  lwz r6, 0x78(r3);
  stw r6, 0x78(r4);
  lwz r6, 0x80(r3);
  lwz r7, 0x7c(r3);
  stw r7, 0x7c(r4);
  stw r6, 0x80(r4);
  lwz r6, 0x88(r3);
  lwz r7, 0x84(r3);
  stw r7, 0x84(r4);
  stw r6, 0x88(r4);
  lwz r6, 0x90(r3);
  lwz r7, 0x8c(r3);
  stw r7, 0x8c(r4);
  stw r6, 0x90(r4);
  lwz r6, 0x98(r3);
  lwz r7, 0x94(r3);
  stw r7, 0x94(r4);
  stw r6, 0x98(r4);
  lwz r6, 0xa0(r3);
  lwz r7, 0x9c(r3);
  stw r7, 0x9c(r4);
  stw r6, 0xa0(r4);
  lwz r6, 0xa8(r3);
  lwz r7, 0xa4(r3);
  stw r7, 0xa4(r4);
  stw r6, 0xa8(r4);
  lwz r6, 0xb0(r3);
  lwz r7, 0xac(r3);
  stw r7, 0xac(r4);
  stw r6, 0xb0(r4);
  lwz r6, 0xb4(r3);
  stw r6, 0xb4(r4);
  lbz r6, 0xb8(r3);
  stb r6, 0xb8(r4);
  lbz r6, 0xb9(r3);
  stb r6, 0xb9(r4);
  lbz r6, 0xba(r3);
  stb r6, 0xba(r4);
  lwz r6, 0xbc(r3);
  stw r6, 0xbc(r4);
  lbz r6, 0xc0(r3);
  stb r6, 0xc0(r4);
  lbz r6, 0xc1(r3);
  stb r6, 0xc1(r4);
  lbz r6, 0xc2(r3);
  stb r6, 0xc2(r4);
  lwz r6, 0xc4(r3);
  stw r6, 0xc4(r4);
  lwz r6, 0xc8(r3);
  stw r6, 0xc8(r4);
  lwz r6, 0xcc(r3);
  stw r6, 0xcc(r4);
  lwz r6, 0xd0(r3);
  stw r6, 0xd0(r4);
  lwz r6, 0xd4(r3);
  stw r6, 0xd4(r4);
  lhz r6, 0xd8(r3);
  sth r6, 0xd8(r4);
  lhz r6, 0xda(r3);
  sth r6, 0xda(r4);
  lhz r6, 0xdc(r3);
  sth r6, 0xdc(r4);
  lha r6, 0xde(r3);
  sth r6, 0xde(r4);
  lbz r6, 0xe0(r3);
  stb r6, 0xe0(r4);
  lbz r6, 0xe1(r3);
  stb r6, 0xe1(r4);
  lbz r6, 0xe2(r3);
  stb r6, 0xe2(r4);
  lhz r6, 0xe8(r3);
  sth r6, 0xe8(r4);
  lbz r6, 0xec(r3);
  addi r3, r3, 0xf0;
  stb r6, 0xec(r4);
  addi r4, r4, 0xf0;
  cmplw r4, r5;
  blt lbl_80530314;
  lwz r22, 0x1758(r31);
  li r0, 0xe;
  lwz r23, 0x175c(r31);
  addi r5, r31, 0xb98;
  lwz r24, 0x1760(r31);
  addi r4, r31, 0x1788;
  lwz r25, 0x1764(r31);
  lwz r26, 0x1768(r31);
  lwz r27, 0x176c(r31);
  lwz r28, 0x1770(r31);
  lbz r29, 0x1774(r31);
  lbz r30, 0x1775(r31);
  lbz r12, 0x1776(r31);
  lbz r11, 0x1777(r31);
  lwz r10, 0x1778(r31);
  lbz r9, 0x177c(r31);
  lbz r8, 0x177d(r31);
  lwz r7, 0x1780(r31);
  lwz r6, 0x1784(r31);
  lwz r3, 0x1788(r31);
  stw r22, 0xb68(r31);
  stw r23, 0xb6c(r31);
  stw r24, 0xb70(r31);
  stw r25, 0xb74(r31);
  stw r26, 0xb78(r31);
  stw r27, 0xb7c(r31);
  stw r28, 0xb80(r31);
  stb r29, 0xb84(r31);
  stb r30, 0xb85(r31);
  stb r12, 0xb86(r31);
  stb r11, 0xb87(r31);
  stw r10, 0xb88(r31);
  stb r9, 0xb8c(r31);
  stb r8, 0xb8d(r31);
  stw r7, 0xb90(r31);
  stw r6, 0xb94(r31);
  stw r3, 0xb98(r31);
  mtctr r0;
lbl_8053057c:
  lwz r3, 4(r4);
  lwzu r0, 8(r4);
  stw r3, 4(r5);
  stwu r0, 8(r5);
  bdnz lbl_8053057c;
  lwz r0, 0x17fc(r31);
  stw r0, 0xc0c(r31);
  lmw r22, 8(r1);
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// Symbol: RacedataScenario_copy
// PAL: 0x805305ac..0x80530864
// Scratch: https://decomp.me/scratch/10rsj
MARK_BINARY_BLOB(RacedataScenario_copy, 0x805305ac, 0x80530864);
asm UNKNOWN_FUNCTION(RacedataScenario_copy) {
  // clang-format off
  nofralloc;
  lbz r0, 4(r4);
  addi r5, r3, 8;
  stb r0, 4(r3);
  addi r6, r4, 8;
  addi r7, r3, 0xb48;
  li r0, 0x26;
  lbz r8, 5(r4);
  stb r8, 5(r3);
  lbz r8, 6(r4);
  stb r8, 6(r3);
  lbz r8, 7(r4);
  stb r8, 7(r3);
lbl_805305dc:
  lbz r8, 4(r6);
  addi r11, r5, 0x23;
  stb r8, 4(r5);
  addi r10, r6, 0x23;
  lbz r8, 5(r6);
  stb r8, 5(r5);
  lbz r8, 6(r6);
  stb r8, 6(r5);
  lwz r8, 8(r6);
  stw r8, 8(r5);
  lwz r8, 0xc(r6);
  stw r8, 0xc(r5);
  lwz r8, 0x10(r6);
  stw r8, 0x10(r5);
  lwz r8, 0x18(r6);
  stw r8, 0x18(r5);
  lbz r8, 0x1c(r6);
  stb r8, 0x1c(r5);
  lbz r8, 0x1d(r6);
  stb r8, 0x1d(r5);
  lwz r8, 0x20(r6);
  stw r8, 0x20(r5);
  mtctr r0;
lbl_80530638:
  lbz r9, 1(r10);
  lbzu r8, 2(r10);
  stb r9, 1(r11);
  stbu r8, 2(r11);
  bdnz lbl_80530638;
  lwz r8, 0x70(r6);
  stw r8, 0x70(r5);
  lbz r8, 0x74(r6);
  stb r8, 0x74(r5);
  lbz r8, 0x75(r6);
  stb r8, 0x75(r5);
  lbz r8, 0x76(r6);
  stb r8, 0x76(r5);
  lbz r8, 0x77(r6);
  stb r8, 0x77(r5);
  lwz r8, 0x78(r6);
  stw r8, 0x78(r5);
  lwz r8, 0x80(r6);
  lwz r9, 0x7c(r6);
  stw r9, 0x7c(r5);
  stw r8, 0x80(r5);
  lwz r8, 0x88(r6);
  lwz r9, 0x84(r6);
  stw r9, 0x84(r5);
  stw r8, 0x88(r5);
  lwz r8, 0x90(r6);
  lwz r9, 0x8c(r6);
  stw r9, 0x8c(r5);
  stw r8, 0x90(r5);
  lwz r8, 0x98(r6);
  lwz r9, 0x94(r6);
  stw r9, 0x94(r5);
  stw r8, 0x98(r5);
  lwz r8, 0xa0(r6);
  lwz r9, 0x9c(r6);
  stw r9, 0x9c(r5);
  stw r8, 0xa0(r5);
  lwz r8, 0xa8(r6);
  lwz r9, 0xa4(r6);
  stw r9, 0xa4(r5);
  stw r8, 0xa8(r5);
  lwz r8, 0xb0(r6);
  lwz r9, 0xac(r6);
  stw r9, 0xac(r5);
  stw r8, 0xb0(r5);
  lwz r8, 0xb4(r6);
  stw r8, 0xb4(r5);
  lbz r8, 0xb8(r6);
  stb r8, 0xb8(r5);
  lbz r8, 0xb9(r6);
  stb r8, 0xb9(r5);
  lbz r8, 0xba(r6);
  stb r8, 0xba(r5);
  lwz r8, 0xbc(r6);
  stw r8, 0xbc(r5);
  lbz r8, 0xc0(r6);
  stb r8, 0xc0(r5);
  lbz r8, 0xc1(r6);
  stb r8, 0xc1(r5);
  lbz r8, 0xc2(r6);
  stb r8, 0xc2(r5);
  lwz r8, 0xc4(r6);
  stw r8, 0xc4(r5);
  lwz r8, 0xc8(r6);
  stw r8, 0xc8(r5);
  lwz r8, 0xcc(r6);
  stw r8, 0xcc(r5);
  lwz r8, 0xd0(r6);
  stw r8, 0xd0(r5);
  lwz r8, 0xd4(r6);
  stw r8, 0xd4(r5);
  lhz r8, 0xd8(r6);
  sth r8, 0xd8(r5);
  lhz r8, 0xda(r6);
  sth r8, 0xda(r5);
  lhz r8, 0xdc(r6);
  sth r8, 0xdc(r5);
  lha r8, 0xde(r6);
  sth r8, 0xde(r5);
  lbz r8, 0xe0(r6);
  stb r8, 0xe0(r5);
  lbz r8, 0xe1(r6);
  stb r8, 0xe1(r5);
  lbz r8, 0xe2(r6);
  stb r8, 0xe2(r5);
  lhz r8, 0xe8(r6);
  sth r8, 0xe8(r5);
  lbz r8, 0xec(r6);
  addi r6, r6, 0xf0;
  stb r8, 0xec(r5);
  addi r5, r5, 0xf0;
  cmplw r5, r7;
  blt lbl_805305dc;
  lwz r5, 0xb48(r4);
  li r0, 0xe;
  stw r5, 0xb48(r3);
  addi r7, r3, 0xb78;
  addi r6, r4, 0xb78;
  lwz r5, 0xb4c(r4);
  stw r5, 0xb4c(r3);
  lwz r5, 0xb50(r4);
  stw r5, 0xb50(r3);
  lwz r5, 0xb54(r4);
  stw r5, 0xb54(r3);
  lwz r5, 0xb58(r4);
  stw r5, 0xb58(r3);
  lwz r5, 0xb5c(r4);
  stw r5, 0xb5c(r3);
  lwz r5, 0xb60(r4);
  stw r5, 0xb60(r3);
  lbz r5, 0xb64(r4);
  stb r5, 0xb64(r3);
  lbz r5, 0xb65(r4);
  stb r5, 0xb65(r3);
  lbz r5, 0xb66(r4);
  stb r5, 0xb66(r3);
  lbz r5, 0xb67(r4);
  stb r5, 0xb67(r3);
  lwz r5, 0xb68(r4);
  stw r5, 0xb68(r3);
  lbz r5, 0xb6c(r4);
  stb r5, 0xb6c(r3);
  lbz r5, 0xb6d(r4);
  stb r5, 0xb6d(r3);
  lwz r5, 0xb70(r4);
  stw r5, 0xb70(r3);
  lwz r5, 0xb74(r4);
  stw r5, 0xb74(r3);
  lwz r5, 0xb78(r4);
  stw r5, 0xb78(r3);
  mtctr r0;
lbl_80530844:
  lwz r5, 4(r6);
  lwzu r0, 8(r6);
  stw r5, 4(r7);
  stwu r0, 8(r7);
  bdnz lbl_80530844;
  lwz r0, 0xbec(r4);
  stw r0, 0xbec(r3);
  blr;
  // clang-format on
}

// Symbol: Racedata_initAwards
// PAL: 0x80530864..0x80530f0c
// Scratch: https://decomp.me/scratch/y64A8
MARK_BINARY_BLOB(Racedata_initAwards, 0x80530864, 0x80530f0c);
asm UNKNOWN_FUNCTION(Racedata_initAwards) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  stmw r25, 0x14(r1);
  mr r31, r3;
  bl Racedata_initRace;
  addi r3, r31, 0x1800;
  addi r4, r31, 0x20;
  bl RacedataScenario_copy;
  li r30, 0;
lbl_8053088c:
  addi r3, r31, 0xc10;
  clrlwi r4, r30, 0x18;
  bl getPlayer__Q26System12MenuScenarioFUc;
  li r4, 5;
  bl setPlayerType__Q26System16RaceConfigPlayerFl;
  clrlwi r4, r30, 0x18;
  addi r3, r31, 0xc10;
  addi r29, r4, 1;
  bl getPlayer__Q26System12MenuScenarioFUc;
  clrlwi r4, r29, 0x18;
  bl setPrevFinishPos__Q26System16RaceConfigPlayerFSc;
  addi r3, r31, 0xc10;
  clrlwi r4, r30, 0x18;
  bl getPlayer__Q26System12MenuScenarioFUc;
  clrlwi r4, r29, 0x18;
  bl setUnkPos__Q26System16RaceConfigPlayerFSc;
  addi r30, r30, 1;
  cmplwi r30, 0xc;
  blt lbl_8053088c;
  addi r3, r31, 0xc10;
  bl getGametype__Q26System12MenuScenarioFv;
  addi r0, r3, -7;
  addi r3, r31, 0xc10;
  cntlzw r0, r0;
  srwi r29, r0, 5;
  bl getGametype__Q26System12MenuScenarioFv;
  addi r0, r3, -12;
  addi r3, r31, 0xc10;
  cntlzw r0, r0;
  srwi r30, r0, 5;
  bl getModeFlag__Q26System12MenuScenarioFv;
  cmpwi r29, 0;
  beq lbl_80530a2c;
  li r30, 1;
lbl_80530914:
  clrlwi r29, r30, 0x18;
  li r28, 0;
lbl_8053091c:
  addi r3, r31, 0x20;
  clrlwi r4, r28, 0x18;
  bl getPlayer__Q26System12RaceScenarioFUc;
  bl getUnkPos__Q26System16RaceConfigPlayerFv;
  clrlwi r0, r3, 0x18;
  cmplw r29, r0;
  bne lbl_80530a10;
  addi r3, r31, 0x20;
  clrlwi r4, r28, 0x18;
  bl getPlayer__Q26System12RaceScenarioFUc;
  bl getPlayerType__Q26System16RaceConfigPlayerFv;
  cmpwi r3, 5;
  beq lbl_80530a10;
  addi r0, r30, -1;
  addi r3, r31, 0x20;
  clrlwi r27, r0, 0x18;
  clrlwi r4, r28, 0x18;
  bl getPlayer__Q26System12RaceScenarioFUc;
  bl getCharacter__Q26System16RaceConfigPlayerFv;
  mr r29, r3;
  mr r4, r27;
  addi r3, r31, 0xc10;
  bl getPlayer__Q26System12MenuScenarioFUc;
  mr r4, r29;
  bl setCharacter__Q26System16RaceConfigPlayerFQ26System11CharacterId;
  addi r3, r31, 0x20;
  clrlwi r4, r28, 0x18;
  bl getPlayer__Q26System12RaceScenarioFUc;
  bl getVehicle__Q26System16RaceConfigPlayerFv;
  mr r29, r3;
  mr r4, r27;
  addi r3, r31, 0xc10;
  bl getPlayer__Q26System12MenuScenarioFUc;
  mr r4, r29;
  bl setVehicle__Q26System16RaceConfigPlayerFQ26System9VehicleId;
  mr r4, r27;
  addi r3, r31, 0xc10;
  bl getPlayer__Q26System12MenuScenarioFUc;
  li r4, 1;
  bl setPlayerType__Q26System16RaceConfigPlayerFl;
  mr r4, r27;
  addi r3, r31, 0xc10;
  bl getPlayer__Q26System12MenuScenarioFUc;
  clrlwi r4, r30, 0x18;
  bl setPrevFinishPos__Q26System16RaceConfigPlayerFSc;
  mr r4, r27;
  addi r3, r31, 0xc10;
  bl getPlayer__Q26System12MenuScenarioFUc;
  clrlwi r4, r30, 0x18;
  bl setUnkPos__Q26System16RaceConfigPlayerFSc;
  addi r3, r31, 0x20;
  clrlwi r4, r28, 0x18;
  bl getPlayer__Q26System12RaceScenarioFUc;
  bl getMii__Q26System16RaceConfigPlayerFv;
  mr r29, r3;
  mr r4, r27;
  addi r3, r31, 0xc10;
  bl getPlayer__Q26System12MenuScenarioFUc;
  mr r4, r29;
  bl setMii__Q26System16RaceConfigPlayerFRCQ26System3Mii;
  b lbl_80530a1c;
lbl_80530a10:
  addi r28, r28, 1;
  cmplwi r28, 0xc;
  blt lbl_8053091c;
lbl_80530a1c:
  addi r30, r30, 1;
  cmplwi r30, 3;
  ble lbl_80530914;
  b lbl_80530ef0;
lbl_80530a2c:
  cmpwi r3, 0;
  beq lbl_80530d18;
  addi r3, r31, 0x20;
  bl computeWinningTeam__Q26System12RaceScenarioFv;
  cntlzw r0, r3;
  mr r27, r3;
  srwi r28, r0, 5;
  li r29, 0;
  b lbl_80530a8c;
lbl_80530a50:
  addi r3, r31, 0x20;
  clrlwi r4, r29, 0x18;
  bl getPlayer__Q26System12RaceScenarioFUc;
  bl getPlayerType__Q26System16RaceConfigPlayerFv;
  cmpwi r3, 0;
  bne lbl_80530a88;
  addi r3, r31, 0x20;
  clrlwi r4, r29, 0x18;
  bl getPlayer__Q26System12RaceScenarioFUc;
  bl getTeam__Q26System16RaceConfigPlayerFv;
  cmpw r27, r3;
  bne lbl_80530a88;
  mr r28, r27;
  b lbl_80530aa0;
lbl_80530a88:
  addi r29, r29, 1;
lbl_80530a8c:
  bl getRacePlayerCount__Q26System10RaceConfigFv;
  clrlwi r3, r3, 0x18;
  clrlwi r0, r29, 0x18;
  cmplw r0, r3;
  blt lbl_80530a50;
lbl_80530aa0:
  li r27, 0;
  li r26, 1;
lbl_80530aa8:
  clrlwi r30, r26, 0x18;
  li r25, 0;
lbl_80530ab0:
  addi r3, r31, 0x20;
  clrlwi r4, r25, 0x18;
  bl getPlayer__Q26System12RaceScenarioFUc;
  bl getUnkPos__Q26System16RaceConfigPlayerFv;
  clrlwi r0, r3, 0x18;
  cmplw r30, r0;
  bne lbl_80530bb8;
  addi r3, r31, 0x20;
  clrlwi r4, r25, 0x18;
  bl getPlayer__Q26System12RaceScenarioFUc;
  bl getPlayerType__Q26System16RaceConfigPlayerFv;
  cmpwi r3, 0;
  bne lbl_80530bb8;
  addi r3, r31, 0x20;
  clrlwi r4, r25, 0x18;
  bl getPlayer__Q26System12RaceScenarioFUc;
  bl getTeam__Q26System16RaceConfigPlayerFv;
  cmpw r28, r3;
  bne lbl_80530bb8;
  addi r3, r31, 0x20;
  clrlwi r4, r25, 0x18;
  bl getPlayer__Q26System12RaceScenarioFUc;
  bl getCharacter__Q26System16RaceConfigPlayerFv;
  mr r29, r3;
  addi r3, r31, 0xc10;
  clrlwi r4, r27, 0x18;
  bl getPlayer__Q26System12MenuScenarioFUc;
  mr r4, r29;
  bl setCharacter__Q26System16RaceConfigPlayerFQ26System11CharacterId;
  addi r3, r31, 0x20;
  clrlwi r4, r25, 0x18;
  bl getPlayer__Q26System12RaceScenarioFUc;
  bl getVehicle__Q26System16RaceConfigPlayerFv;
  mr r29, r3;
  addi r3, r31, 0xc10;
  clrlwi r4, r27, 0x18;
  bl getPlayer__Q26System12MenuScenarioFUc;
  mr r4, r29;
  bl setVehicle__Q26System16RaceConfigPlayerFQ26System9VehicleId;
  addi r3, r31, 0xc10;
  clrlwi r4, r27, 0x18;
  bl getPlayer__Q26System12MenuScenarioFUc;
  li r4, 1;
  bl setPlayerType__Q26System16RaceConfigPlayerFl;
  clrlwi r4, r27, 0x18;
  addi r3, r31, 0xc10;
  addi r29, r4, 1;
  bl getPlayer__Q26System12MenuScenarioFUc;
  clrlwi r4, r29, 0x18;
  bl setPrevFinishPos__Q26System16RaceConfigPlayerFSc;
  addi r3, r31, 0xc10;
  clrlwi r4, r27, 0x18;
  bl getPlayer__Q26System12MenuScenarioFUc;
  clrlwi r4, r29, 0x18;
  bl setUnkPos__Q26System16RaceConfigPlayerFSc;
  addi r3, r31, 0x20;
  clrlwi r4, r25, 0x18;
  bl getPlayer__Q26System12RaceScenarioFUc;
  bl getMii__Q26System16RaceConfigPlayerFv;
  mr r29, r3;
  addi r3, r31, 0xc10;
  clrlwi r4, r27, 0x18;
  bl getPlayer__Q26System12MenuScenarioFUc;
  mr r4, r29;
  bl setMii__Q26System16RaceConfigPlayerFRCQ26System3Mii;
  addi r27, r27, 1;
lbl_80530bb8:
  addi r25, r25, 1;
  cmplwi r25, 0xc;
  blt lbl_80530ab0;
  addi r26, r26, 1;
  cmplwi r26, 0xc;
  ble lbl_80530aa8;
  li r25, 1;
lbl_80530bd4:
  clrlwi r30, r25, 0x18;
  li r26, 0;
lbl_80530bdc:
  addi r3, r31, 0x20;
  clrlwi r4, r26, 0x18;
  bl getPlayer__Q26System12RaceScenarioFUc;
  bl getUnkPos__Q26System16RaceConfigPlayerFv;
  clrlwi r0, r3, 0x18;
  cmplw r30, r0;
  bne lbl_80530cfc;
  addi r3, r31, 0x20;
  clrlwi r4, r26, 0x18;
  bl getPlayer__Q26System12RaceScenarioFUc;
  bl getPlayerType__Q26System16RaceConfigPlayerFv;
  cmpwi r3, 5;
  beq lbl_80530cfc;
  addi r3, r31, 0x20;
  clrlwi r4, r26, 0x18;
  bl getPlayer__Q26System12RaceScenarioFUc;
  bl getPlayerType__Q26System16RaceConfigPlayerFv;
  cmpwi r3, 0;
  beq lbl_80530cfc;
  addi r3, r31, 0x20;
  clrlwi r4, r26, 0x18;
  bl getPlayer__Q26System12RaceScenarioFUc;
  bl getTeam__Q26System16RaceConfigPlayerFv;
  cmpw r28, r3;
  bne lbl_80530cfc;
  addi r3, r31, 0x20;
  clrlwi r4, r26, 0x18;
  bl getPlayer__Q26System12RaceScenarioFUc;
  bl getCharacter__Q26System16RaceConfigPlayerFv;
  mr r29, r3;
  addi r3, r31, 0xc10;
  clrlwi r4, r27, 0x18;
  bl getPlayer__Q26System12MenuScenarioFUc;
  mr r4, r29;
  bl setCharacter__Q26System16RaceConfigPlayerFQ26System11CharacterId;
  addi r3, r31, 0x20;
  clrlwi r4, r26, 0x18;
  bl getPlayer__Q26System12RaceScenarioFUc;
  bl getVehicle__Q26System16RaceConfigPlayerFv;
  mr r29, r3;
  addi r3, r31, 0xc10;
  clrlwi r4, r27, 0x18;
  bl getPlayer__Q26System12MenuScenarioFUc;
  mr r4, r29;
  bl setVehicle__Q26System16RaceConfigPlayerFQ26System9VehicleId;
  addi r3, r31, 0xc10;
  clrlwi r4, r27, 0x18;
  bl getPlayer__Q26System12MenuScenarioFUc;
  li r4, 1;
  bl setPlayerType__Q26System16RaceConfigPlayerFl;
  clrlwi r4, r27, 0x18;
  addi r3, r31, 0xc10;
  addi r29, r4, 1;
  bl getPlayer__Q26System12MenuScenarioFUc;
  clrlwi r4, r29, 0x18;
  bl setPrevFinishPos__Q26System16RaceConfigPlayerFSc;
  addi r3, r31, 0xc10;
  clrlwi r4, r27, 0x18;
  bl getPlayer__Q26System12MenuScenarioFUc;
  clrlwi r4, r29, 0x18;
  bl setUnkPos__Q26System16RaceConfigPlayerFSc;
  addi r3, r31, 0x20;
  clrlwi r4, r26, 0x18;
  bl getPlayer__Q26System12RaceScenarioFUc;
  bl getMii__Q26System16RaceConfigPlayerFv;
  mr r29, r3;
  addi r3, r31, 0xc10;
  clrlwi r4, r27, 0x18;
  bl getPlayer__Q26System12MenuScenarioFUc;
  mr r4, r29;
  bl setMii__Q26System16RaceConfigPlayerFRCQ26System3Mii;
  addi r27, r27, 1;
lbl_80530cfc:
  addi r26, r26, 1;
  cmplwi r26, 0xc;
  blt lbl_80530bdc;
  addi r25, r25, 1;
  cmplwi r25, 0xc;
  ble lbl_80530bd4;
  b lbl_80530ef0;
lbl_80530d18:
  cmpwi r30, 0;
  beq lbl_80530e3c;
  li r25, 0;
  li r26, 1;
lbl_80530d28:
  clrlwi r29, r26, 0x18;
  li r27, 0;
lbl_80530d30:
  addi r3, r31, 0x20;
  clrlwi r4, r27, 0x18;
  bl getPlayer__Q26System12RaceScenarioFUc;
  bl getUnkPos__Q26System16RaceConfigPlayerFv;
  clrlwi r0, r3, 0x18;
  cmplw r29, r0;
  bne lbl_80530e20;
  addi r3, r31, 0x20;
  clrlwi r4, r27, 0x18;
  bl getPlayer__Q26System12RaceScenarioFUc;
  bl getPlayerType__Q26System16RaceConfigPlayerFv;
  cmpwi r3, 0;
  bne lbl_80530e20;
  addi r3, r31, 0x20;
  clrlwi r4, r27, 0x18;
  bl getPlayer__Q26System12RaceScenarioFUc;
  bl getCharacter__Q26System16RaceConfigPlayerFv;
  mr r30, r3;
  addi r3, r31, 0xc10;
  clrlwi r4, r25, 0x18;
  bl getPlayer__Q26System12MenuScenarioFUc;
  mr r4, r30;
  bl setCharacter__Q26System16RaceConfigPlayerFQ26System11CharacterId;
  addi r3, r31, 0x20;
  clrlwi r4, r27, 0x18;
  bl getPlayer__Q26System12RaceScenarioFUc;
  bl getVehicle__Q26System16RaceConfigPlayerFv;
  mr r30, r3;
  addi r3, r31, 0xc10;
  clrlwi r4, r25, 0x18;
  bl getPlayer__Q26System12MenuScenarioFUc;
  mr r4, r30;
  bl setVehicle__Q26System16RaceConfigPlayerFQ26System9VehicleId;
  addi r3, r31, 0xc10;
  clrlwi r4, r25, 0x18;
  bl getPlayer__Q26System12MenuScenarioFUc;
  li r4, 1;
  bl setPlayerType__Q26System16RaceConfigPlayerFl;
  clrlwi r4, r25, 0x18;
  addi r3, r31, 0xc10;
  addi r30, r4, 1;
  bl getPlayer__Q26System12MenuScenarioFUc;
  clrlwi r4, r30, 0x18;
  bl setPrevFinishPos__Q26System16RaceConfigPlayerFSc;
  addi r3, r31, 0xc10;
  clrlwi r4, r25, 0x18;
  bl getPlayer__Q26System12MenuScenarioFUc;
  clrlwi r4, r30, 0x18;
  bl setUnkPos__Q26System16RaceConfigPlayerFSc;
  addi r3, r31, 0x20;
  clrlwi r4, r27, 0x18;
  bl getPlayer__Q26System12RaceScenarioFUc;
  bl getMii__Q26System16RaceConfigPlayerFv;
  mr r30, r3;
  addi r3, r31, 0xc10;
  clrlwi r4, r25, 0x18;
  bl getPlayer__Q26System12MenuScenarioFUc;
  mr r4, r30;
  bl setMii__Q26System16RaceConfigPlayerFRCQ26System3Mii;
  addi r25, r25, 1;
lbl_80530e20:
  addi r27, r27, 1;
  cmplwi r27, 0xc;
  blt lbl_80530d30;
  addi r26, r26, 1;
  cmplwi r26, 0xc;
  ble lbl_80530d28;
  b lbl_80530ef0;
lbl_80530e3c:
  addi r3, r31, 0x20;
  li r4, 0;
  bl getPlayer__Q26System12RaceScenarioFUc;
  bl getCharacter__Q26System16RaceConfigPlayerFv;
  mr r30, r3;
  addi r3, r31, 0xc10;
  li r4, 0;
  bl getPlayer__Q26System12MenuScenarioFUc;
  mr r4, r30;
  bl setCharacter__Q26System16RaceConfigPlayerFQ26System11CharacterId;
  addi r3, r31, 0x20;
  li r4, 0;
  bl getPlayer__Q26System12RaceScenarioFUc;
  bl getVehicle__Q26System16RaceConfigPlayerFv;
  mr r30, r3;
  addi r3, r31, 0xc10;
  li r4, 0;
  bl getPlayer__Q26System12MenuScenarioFUc;
  mr r4, r30;
  bl setVehicle__Q26System16RaceConfigPlayerFQ26System9VehicleId;
  addi r3, r31, 0xc10;
  li r4, 0;
  bl getPlayer__Q26System12MenuScenarioFUc;
  li r4, 1;
  bl setPlayerType__Q26System16RaceConfigPlayerFl;
  addi r3, r31, 0xc10;
  li r4, 0;
  bl getPlayer__Q26System12MenuScenarioFUc;
  li r4, 1;
  bl setPrevFinishPos__Q26System16RaceConfigPlayerFSc;
  addi r3, r31, 0xc10;
  li r4, 0;
  bl getPlayer__Q26System12MenuScenarioFUc;
  li r4, 1;
  bl setUnkPos__Q26System16RaceConfigPlayerFSc;
  addi r3, r31, 0x20;
  li r4, 0;
  bl getPlayer__Q26System12RaceScenarioFUc;
  bl getMii__Q26System16RaceConfigPlayerFv;
  mr r30, r3;
  addi r3, r31, 0xc10;
  li r4, 0;
  bl getPlayer__Q26System12MenuScenarioFUc;
  mr r4, r30;
  bl setMii__Q26System16RaceConfigPlayerFRCQ26System3Mii;
lbl_80530ef0:
  mr r3, r31;
  bl Racedata_initRace;
  lmw r25, 0x14(r1);
  lwz r0, 0x34(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

namespace System {

u32 MenuScenario::getModeFlag() { return mSettings.mModeFlags >> 1 & 1; }

u8 RaceConfigPlayer::getUnkPos() { return this->_e0; }

CharacterId RaceConfigPlayer::getCharacter() { return mCharacterId; }

VehicleId RaceConfigPlayer::getVehicle() { return mVehicleId; }

#pragma legacy_struct_alignment on
void RaceConfigPlayer::setMii(const Mii& mii) { mMii = mii; }
#pragma legacy_struct_alignment off

Mii* RaceConfigPlayer::getMii() { return &mMii; }

} // namespace System

// Symbol: Racedata_initCredits
// PAL: 0x80531070..0x80531ce4
// Scratch: https://decomp.me/scratch/wyhhV
MARK_BINARY_BLOB(Racedata_initCredits, 0x80531070, 0x80531ce4);
asm UNKNOWN_FUNCTION(Racedata_initCredits) {
  // clang-format off
  nofralloc;
  stwu r1, -0x40(r1);
  mflr r0;
  addi r5, r3, 0xc18;
  addi r4, r3, 0x1808;
  stw r0, 0x44(r1);
  addi r6, r3, 0x1758;
  stmw r21, 0x14(r1);
  mr r31, r3;
  lbz r0, 0x1804(r3);
  lbz r9, 0x1805(r3);
  lbz r8, 0x1806(r3);
  lbz r7, 0x1807(r3);
  stb r0, 0xc14(r3);
  li r0, 0x26;
  stb r9, 0xc15(r3);
  stb r8, 0xc16(r3);
  stb r7, 0xc17(r3);
lbl_805310b4:
  lbz r7, 4(r4);
  addi r10, r5, 0x23;
  stb r7, 4(r5);
  addi r9, r4, 0x23;
  lbz r7, 5(r4);
  stb r7, 5(r5);
  lbz r7, 6(r4);
  stb r7, 6(r5);
  lwz r7, 8(r4);
  stw r7, 8(r5);
  lwz r7, 0xc(r4);
  stw r7, 0xc(r5);
  lwz r7, 0x10(r4);
  stw r7, 0x10(r5);
  lwz r7, 0x18(r4);
  stw r7, 0x18(r5);
  lbz r7, 0x1c(r4);
  stb r7, 0x1c(r5);
  lbz r7, 0x1d(r4);
  stb r7, 0x1d(r5);
  lwz r7, 0x20(r4);
  stw r7, 0x20(r5);
  mtctr r0;
lbl_80531110:
  lbz r8, 1(r9);
  lbzu r7, 2(r9);
  stb r8, 1(r10);
  stbu r7, 2(r10);
  bdnz lbl_80531110;
  lwz r7, 0x70(r4);
  stw r7, 0x70(r5);
  lbz r7, 0x74(r4);
  stb r7, 0x74(r5);
  lbz r7, 0x75(r4);
  stb r7, 0x75(r5);
  lbz r7, 0x76(r4);
  stb r7, 0x76(r5);
  lbz r7, 0x77(r4);
  stb r7, 0x77(r5);
  lwz r7, 0x78(r4);
  stw r7, 0x78(r5);
  lwz r7, 0x80(r4);
  lwz r8, 0x7c(r4);
  stw r8, 0x7c(r5);
  stw r7, 0x80(r5);
  lwz r7, 0x88(r4);
  lwz r8, 0x84(r4);
  stw r8, 0x84(r5);
  stw r7, 0x88(r5);
  lwz r7, 0x90(r4);
  lwz r8, 0x8c(r4);
  stw r8, 0x8c(r5);
  stw r7, 0x90(r5);
  lwz r7, 0x98(r4);
  lwz r8, 0x94(r4);
  stw r8, 0x94(r5);
  stw r7, 0x98(r5);
  lwz r7, 0xa0(r4);
  lwz r8, 0x9c(r4);
  stw r8, 0x9c(r5);
  stw r7, 0xa0(r5);
  lwz r7, 0xa8(r4);
  lwz r8, 0xa4(r4);
  stw r8, 0xa4(r5);
  stw r7, 0xa8(r5);
  lwz r7, 0xb0(r4);
  lwz r8, 0xac(r4);
  stw r8, 0xac(r5);
  stw r7, 0xb0(r5);
  lwz r7, 0xb4(r4);
  stw r7, 0xb4(r5);
  lbz r7, 0xb8(r4);
  stb r7, 0xb8(r5);
  lbz r7, 0xb9(r4);
  stb r7, 0xb9(r5);
  lbz r7, 0xba(r4);
  stb r7, 0xba(r5);
  lwz r7, 0xbc(r4);
  stw r7, 0xbc(r5);
  lbz r7, 0xc0(r4);
  stb r7, 0xc0(r5);
  lbz r7, 0xc1(r4);
  stb r7, 0xc1(r5);
  lbz r7, 0xc2(r4);
  stb r7, 0xc2(r5);
  lwz r7, 0xc4(r4);
  stw r7, 0xc4(r5);
  lwz r7, 0xc8(r4);
  stw r7, 0xc8(r5);
  lwz r7, 0xcc(r4);
  stw r7, 0xcc(r5);
  lwz r7, 0xd0(r4);
  stw r7, 0xd0(r5);
  lwz r7, 0xd4(r4);
  stw r7, 0xd4(r5);
  lhz r7, 0xd8(r4);
  sth r7, 0xd8(r5);
  lhz r7, 0xda(r4);
  sth r7, 0xda(r5);
  lhz r7, 0xdc(r4);
  sth r7, 0xdc(r5);
  lha r7, 0xde(r4);
  sth r7, 0xde(r5);
  lbz r7, 0xe0(r4);
  stb r7, 0xe0(r5);
  lbz r7, 0xe1(r4);
  stb r7, 0xe1(r5);
  lbz r7, 0xe2(r4);
  stb r7, 0xe2(r5);
  lhz r7, 0xe8(r4);
  sth r7, 0xe8(r5);
  lbz r7, 0xec(r4);
  addi r4, r4, 0xf0;
  stb r7, 0xec(r5);
  addi r5, r5, 0xf0;
  cmplw r5, r6;
  blt lbl_805310b4;
  lwz r21, 0x2348(r3);
  li r0, 0xe;
  lwz r30, 0x234c(r3);
  addi r6, r3, 0x1788;
  lwz r29, 0x2350(r3);
  addi r5, r3, 0x2378;
  lwz r28, 0x2354(r3);
  lwz r27, 0x2358(r3);
  lwz r26, 0x235c(r3);
  lwz r25, 0x2360(r3);
  lbz r24, 0x2364(r3);
  lbz r23, 0x2365(r3);
  lbz r22, 0x2366(r3);
  lbz r12, 0x2367(r3);
  lwz r11, 0x2368(r3);
  lbz r10, 0x236c(r3);
  lbz r9, 0x236d(r3);
  lwz r8, 0x2370(r3);
  lwz r7, 0x2374(r3);
  lwz r4, 0x2378(r3);
  stw r21, 0x1758(r3);
  stw r30, 0x175c(r3);
  stw r29, 0x1760(r3);
  stw r28, 0x1764(r3);
  stw r27, 0x1768(r3);
  stw r26, 0x176c(r3);
  stw r25, 0x1770(r3);
  stb r24, 0x1774(r3);
  stb r23, 0x1775(r3);
  stb r22, 0x1776(r3);
  stb r12, 0x1777(r3);
  stw r11, 0x1778(r3);
  stb r10, 0x177c(r3);
  stb r9, 0x177d(r3);
  stw r8, 0x1780(r3);
  stw r7, 0x1784(r3);
  stw r4, 0x1788(r3);
  mtctr r0;
lbl_8053131c:
  lwz r4, 4(r5);
  lwzu r0, 8(r5);
  stw r4, 4(r6);
  stwu r0, 8(r6);
  bdnz lbl_8053131c;
  lwz r0, 0x23ec(r3);
  addi r4, r31, 0x20;
  stw r0, 0x17fc(r3);
  addi r3, r3, 0xc10;
  bl initRace__Q26System12MenuScenarioFPQ26System12RaceScenario;
  lbz r9, 0xc14(r31);
  addi r3, r31, 0x28;
  lbz r8, 0xc15(r31);
  addi r4, r31, 0xc18;
  lbz r7, 0xc16(r31);
  addi r5, r31, 0xb68;
  lbz r6, 0xc17(r31);
  li r0, 0x26;
  stb r9, 0x24(r31);
  stb r8, 0x25(r31);
  stb r7, 0x26(r31);
  stb r6, 0x27(r31);
lbl_80531374:
  lbz r6, 4(r4);
  addi r9, r3, 0x23;
  stb r6, 4(r3);
  addi r8, r4, 0x23;
  lbz r6, 5(r4);
  stb r6, 5(r3);
  lbz r6, 6(r4);
  stb r6, 6(r3);
  lwz r6, 8(r4);
  stw r6, 8(r3);
  lwz r6, 0xc(r4);
  stw r6, 0xc(r3);
  lwz r6, 0x10(r4);
  stw r6, 0x10(r3);
  lwz r6, 0x18(r4);
  stw r6, 0x18(r3);
  lbz r6, 0x1c(r4);
  stb r6, 0x1c(r3);
  lbz r6, 0x1d(r4);
  stb r6, 0x1d(r3);
  lwz r6, 0x20(r4);
  stw r6, 0x20(r3);
  mtctr r0;
lbl_805313d0:
  lbz r7, 1(r8);
  lbzu r6, 2(r8);
  stb r7, 1(r9);
  stbu r6, 2(r9);
  bdnz lbl_805313d0;
  lwz r6, 0x70(r4);
  stw r6, 0x70(r3);
  lbz r6, 0x74(r4);
  stb r6, 0x74(r3);
  lbz r6, 0x75(r4);
  stb r6, 0x75(r3);
  lbz r6, 0x76(r4);
  stb r6, 0x76(r3);
  lbz r6, 0x77(r4);
  stb r6, 0x77(r3);
  lwz r6, 0x78(r4);
  stw r6, 0x78(r3);
  lwz r6, 0x80(r4);
  lwz r7, 0x7c(r4);
  stw r7, 0x7c(r3);
  stw r6, 0x80(r3);
  lwz r6, 0x88(r4);
  lwz r7, 0x84(r4);
  stw r7, 0x84(r3);
  stw r6, 0x88(r3);
  lwz r6, 0x90(r4);
  lwz r7, 0x8c(r4);
  stw r7, 0x8c(r3);
  stw r6, 0x90(r3);
  lwz r6, 0x98(r4);
  lwz r7, 0x94(r4);
  stw r7, 0x94(r3);
  stw r6, 0x98(r3);
  lwz r6, 0xa0(r4);
  lwz r7, 0x9c(r4);
  stw r7, 0x9c(r3);
  stw r6, 0xa0(r3);
  lwz r6, 0xa8(r4);
  lwz r7, 0xa4(r4);
  stw r7, 0xa4(r3);
  stw r6, 0xa8(r3);
  lwz r6, 0xb0(r4);
  lwz r7, 0xac(r4);
  stw r7, 0xac(r3);
  stw r6, 0xb0(r3);
  lwz r6, 0xb4(r4);
  stw r6, 0xb4(r3);
  lbz r6, 0xb8(r4);
  stb r6, 0xb8(r3);
  lbz r6, 0xb9(r4);
  stb r6, 0xb9(r3);
  lbz r6, 0xba(r4);
  stb r6, 0xba(r3);
  lwz r6, 0xbc(r4);
  stw r6, 0xbc(r3);
  lbz r6, 0xc0(r4);
  stb r6, 0xc0(r3);
  lbz r6, 0xc1(r4);
  stb r6, 0xc1(r3);
  lbz r6, 0xc2(r4);
  stb r6, 0xc2(r3);
  lwz r6, 0xc4(r4);
  stw r6, 0xc4(r3);
  lwz r6, 0xc8(r4);
  stw r6, 0xc8(r3);
  lwz r6, 0xcc(r4);
  stw r6, 0xcc(r3);
  lwz r6, 0xd0(r4);
  stw r6, 0xd0(r3);
  lwz r6, 0xd4(r4);
  stw r6, 0xd4(r3);
  lhz r6, 0xd8(r4);
  sth r6, 0xd8(r3);
  lhz r6, 0xda(r4);
  sth r6, 0xda(r3);
  lhz r6, 0xdc(r4);
  sth r6, 0xdc(r3);
  lha r6, 0xde(r4);
  sth r6, 0xde(r3);
  lbz r6, 0xe0(r4);
  stb r6, 0xe0(r3);
  lbz r6, 0xe1(r4);
  stb r6, 0xe1(r3);
  lbz r6, 0xe2(r4);
  stb r6, 0xe2(r3);
  lhz r6, 0xe8(r4);
  sth r6, 0xe8(r3);
  lbz r6, 0xec(r4);
  addi r4, r4, 0xf0;
  stb r6, 0xec(r3);
  addi r3, r3, 0xf0;
  cmplw r3, r5;
  blt lbl_80531374;
  lwz r30, 0x1758(r31);
  li r0, 0xe;
  lwz r29, 0x175c(r31);
  addi r5, r31, 0xb98;
  lwz r28, 0x1760(r31);
  addi r4, r31, 0x1788;
  lwz r27, 0x1764(r31);
  lwz r26, 0x1768(r31);
  lwz r25, 0x176c(r31);
  lwz r24, 0x1770(r31);
  lbz r23, 0x1774(r31);
  lbz r22, 0x1775(r31);
  lbz r12, 0x1776(r31);
  lbz r11, 0x1777(r31);
  lwz r10, 0x1778(r31);
  lbz r9, 0x177c(r31);
  lbz r8, 0x177d(r31);
  lwz r7, 0x1780(r31);
  lwz r6, 0x1784(r31);
  lwz r3, 0x1788(r31);
  stw r30, 0xb68(r31);
  stw r29, 0xb6c(r31);
  stw r28, 0xb70(r31);
  stw r27, 0xb74(r31);
  stw r26, 0xb78(r31);
  stw r25, 0xb7c(r31);
  stw r24, 0xb80(r31);
  stb r23, 0xb84(r31);
  stb r22, 0xb85(r31);
  stb r12, 0xb86(r31);
  stb r11, 0xb87(r31);
  stw r10, 0xb88(r31);
  stb r9, 0xb8c(r31);
  stb r8, 0xb8d(r31);
  stw r7, 0xb90(r31);
  stw r6, 0xb94(r31);
  stw r3, 0xb98(r31);
  mtctr r0;
lbl_805315dc:
  lwz r3, 4(r4);
  lwzu r0, 8(r4);
  stw r3, 4(r5);
  stwu r0, 8(r5);
  bdnz lbl_805315dc;
  lwz r5, 0x17fc(r31);
  li r0, 2;
  li r4, 0xc;
  li r3, 0x3a;
  stw r5, 0xc0c(r31);
  li r11, 0;
  li r8, 5;
  stw r4, 0x1760(r31);
  stw r3, 0x1758(r31);
  mtctr r0;
lbl_80531618:
  clrlwi r5, r11, 0x18;
  addi r0, r11, 2;
  mulli r4, r5, 0xf0;
  addi r3, r11, 1;
  clrlwi r6, r0, 0x18;
  clrlwi r7, r3, 0x18;
  add r9, r31, r4;
  addi r3, r11, 4;
  stw r8, 0xc28(r9);
  addi r10, r5, 1;
  addi r0, r11, 3;
  clrlwi r4, r3, 0x18;
  stb r10, 0xcf9(r9);
  clrlwi r5, r0, 0x18;
  addi r0, r11, 5;
  addi r6, r6, 1;
  stb r10, 0xcf8(r9);
  clrlwi r3, r0, 0x18;
  addi r0, r7, 1;
  addi r5, r5, 1;
  stw r8, 0xd18(r9);
  addi r4, r4, 1;
  addi r3, r3, 1;
  addi r11, r11, 6;
  stb r0, 0xde9(r9);
  stb r0, 0xde8(r9);
  stw r8, 0xe08(r9);
  stb r6, 0xed9(r9);
  stb r6, 0xed8(r9);
  stw r8, 0xef8(r9);
  stb r5, 0xfc9(r9);
  stb r5, 0xfc8(r9);
  stw r8, 0xfe8(r9);
  stb r4, 0x10b9(r9);
  stb r4, 0x10b8(r9);
  stw r8, 0x10d8(r9);
  stb r3, 0x11a9(r9);
  stb r3, 0x11a8(r9);
  bdnz lbl_80531618;
  li r8, 0;
  li r7, 0;
  li r3, 1;
  li r0, 0x26;
  lis r6, 0;
lbl_805316c8:
  clrlwi r5, r7, 0x18;
  lwz r4, 0(r6);
  mulli r5, r5, 0xf0;
  add r4, r4, r5;
  lwz r4, 0x38(r4);
  cmpwi r4, 0;
  bne lbl_80531848;
  clrlwi r10, r8, 0x18;
  add r5, r31, r5;
  mulli r4, r10, 0xf0;
  lwz r9, 0x34(r5);
  addi r10, r10, 1;
  addi r11, r5, 0x4b;
  add r4, r31, r4;
  stw r9, 0xc24(r4);
  addi r12, r4, 0xc3b;
  lwz r9, 0x30(r5);
  stw r9, 0xc20(r4);
  stb r10, 0xcf9(r4);
  stb r10, 0xcf8(r4);
  stw r3, 0xc28(r4);
  lwz r9, 0x40(r5);
  stw r9, 0xc30(r4);
  lbz r9, 0x44(r5);
  stb r9, 0xc34(r4);
  lbz r9, 0x45(r5);
  stb r9, 0xc35(r4);
  lwz r9, 0x48(r5);
  stw r9, 0xc38(r4);
  mtctr r0;
lbl_80531740:
  lbz r10, 1(r11);
  lbzu r9, 2(r11);
  stb r10, 1(r12);
  stbu r9, 2(r12);
  bdnz lbl_80531740;
  lwz r9, 0x98(r5);
  addi r8, r8, 1;
  stw r9, 0xc88(r4);
  lbz r9, 0x9c(r5);
  stb r9, 0xc8c(r4);
  lbz r9, 0x9d(r5);
  stb r9, 0xc8d(r4);
  lbz r9, 0x9e(r5);
  stb r9, 0xc8e(r4);
  lbz r9, 0x9f(r5);
  stb r9, 0xc8f(r4);
  lwz r9, 0xa0(r5);
  stw r9, 0xc90(r4);
  lwz r9, 0xa8(r5);
  lwz r10, 0xa4(r5);
  stw r10, 0xc94(r4);
  stw r9, 0xc98(r4);
  lwz r9, 0xb0(r5);
  lwz r10, 0xac(r5);
  stw r10, 0xc9c(r4);
  stw r9, 0xca0(r4);
  lwz r9, 0xb8(r5);
  lwz r10, 0xb4(r5);
  stw r10, 0xca4(r4);
  stw r9, 0xca8(r4);
  lwz r9, 0xc0(r5);
  lwz r10, 0xbc(r5);
  stw r10, 0xcac(r4);
  stw r9, 0xcb0(r4);
  lwz r9, 0xc8(r5);
  lwz r10, 0xc4(r5);
  stw r10, 0xcb4(r4);
  stw r9, 0xcb8(r4);
  lwz r9, 0xd0(r5);
  lwz r10, 0xcc(r5);
  stw r10, 0xcbc(r4);
  stw r9, 0xcc0(r4);
  lwz r9, 0xd8(r5);
  lwz r10, 0xd4(r5);
  stw r10, 0xcc4(r4);
  stw r9, 0xcc8(r4);
  lwz r9, 0xdc(r5);
  stw r9, 0xccc(r4);
  lbz r9, 0xe0(r5);
  stb r9, 0xcd0(r4);
  lbz r9, 0xe1(r5);
  stb r9, 0xcd1(r4);
  lbz r9, 0xe2(r5);
  stb r9, 0xcd2(r4);
  lwz r9, 0xe4(r5);
  stw r9, 0xcd4(r4);
  lbz r9, 0xe8(r5);
  stb r9, 0xcd8(r4);
  lbz r9, 0xe9(r5);
  stb r9, 0xcd9(r4);
  lbz r9, 0xea(r5);
  stb r9, 0xcda(r4);
  lwz r9, 0xec(r5);
  stw r9, 0xcdc(r4);
  lwz r5, 0xf0(r5);
  stw r5, 0xce0(r4);
lbl_80531848:
  addi r7, r7, 1;
  cmplwi r7, 0xc;
  blt lbl_805316c8;
  li r9, 1;
  li r3, 1;
  li r0, 0x26;
  lis r7, 0;
lbl_80531864:
  clrlwi r6, r9, 0x18;
  li r10, 0;
lbl_8053186c:
  clrlwi r5, r10, 0x18;
  lwz r4, 0(r7);
  mulli r11, r5, 0xf0;
  add r5, r4, r11;
  lbz r4, 0x108(r5);
  cmplw r6, r4;
  bne lbl_805319f8;
  lwz r4, 0x38(r5);
  cmpwi r4, 0;
  beq lbl_805319f8;
  clrlwi r12, r8, 0x18;
  add r5, r31, r11;
  mulli r4, r12, 0xf0;
  lwz r11, 0x34(r5);
  addi r12, r12, 1;
  addi r22, r5, 0x4b;
  add r4, r31, r4;
  stw r11, 0xc24(r4);
  addi r23, r4, 0xc3b;
  lwz r11, 0x30(r5);
  stw r11, 0xc20(r4);
  stb r12, 0xcf9(r4);
  stb r12, 0xcf8(r4);
  stw r3, 0xc28(r4);
  lwz r11, 0x40(r5);
  stw r11, 0xc30(r4);
  lbz r11, 0x44(r5);
  stb r11, 0xc34(r4);
  lbz r11, 0x45(r5);
  stb r11, 0xc35(r4);
  lwz r11, 0x48(r5);
  stw r11, 0xc38(r4);
  mtctr r0;
lbl_805318f0:
  lbz r12, 1(r22);
  lbzu r11, 2(r22);
  stb r12, 1(r23);
  stbu r11, 2(r23);
  bdnz lbl_805318f0;
  lwz r11, 0x98(r5);
  addi r8, r8, 1;
  stw r11, 0xc88(r4);
  lbz r11, 0x9c(r5);
  stb r11, 0xc8c(r4);
  lbz r11, 0x9d(r5);
  stb r11, 0xc8d(r4);
  lbz r11, 0x9e(r5);
  stb r11, 0xc8e(r4);
  lbz r11, 0x9f(r5);
  stb r11, 0xc8f(r4);
  lwz r11, 0xa0(r5);
  stw r11, 0xc90(r4);
  lwz r11, 0xa8(r5);
  lwz r12, 0xa4(r5);
  stw r12, 0xc94(r4);
  stw r11, 0xc98(r4);
  lwz r11, 0xb0(r5);
  lwz r12, 0xac(r5);
  stw r12, 0xc9c(r4);
  stw r11, 0xca0(r4);
  lwz r11, 0xb8(r5);
  lwz r12, 0xb4(r5);
  stw r12, 0xca4(r4);
  stw r11, 0xca8(r4);
  lwz r11, 0xc0(r5);
  lwz r12, 0xbc(r5);
  stw r12, 0xcac(r4);
  stw r11, 0xcb0(r4);
  lwz r11, 0xc8(r5);
  lwz r12, 0xc4(r5);
  stw r12, 0xcb4(r4);
  stw r11, 0xcb8(r4);
  lwz r11, 0xd0(r5);
  lwz r12, 0xcc(r5);
  stw r12, 0xcbc(r4);
  stw r11, 0xcc0(r4);
  lwz r11, 0xd8(r5);
  lwz r12, 0xd4(r5);
  stw r12, 0xcc4(r4);
  stw r11, 0xcc8(r4);
  lwz r11, 0xdc(r5);
  stw r11, 0xccc(r4);
  lbz r11, 0xe0(r5);
  stb r11, 0xcd0(r4);
  lbz r11, 0xe1(r5);
  stb r11, 0xcd1(r4);
  lbz r11, 0xe2(r5);
  stb r11, 0xcd2(r4);
  lwz r11, 0xe4(r5);
  stw r11, 0xcd4(r4);
  lbz r11, 0xe8(r5);
  stb r11, 0xcd8(r4);
  lbz r11, 0xe9(r5);
  stb r11, 0xcd9(r4);
  lbz r11, 0xea(r5);
  stb r11, 0xcda(r4);
  lwz r11, 0xec(r5);
  stw r11, 0xcdc(r4);
  lwz r5, 0xf0(r5);
  stw r5, 0xce0(r4);
lbl_805319f8:
  addi r10, r10, 1;
  cmplwi r10, 0xc;
  blt lbl_8053186c;
  addi r9, r9, 1;
  cmplwi r9, 0xc;
  ble lbl_80531864;
  addi r3, r31, 0xc10;
  addi r4, r31, 0x20;
  bl initRace__Q26System12MenuScenarioFPQ26System12RaceScenario;
  lbz r9, 0xc14(r31);
  addi r3, r31, 0x28;
  lbz r8, 0xc15(r31);
  addi r4, r31, 0xc18;
  lbz r7, 0xc16(r31);
  addi r5, r31, 0xb68;
  lbz r6, 0xc17(r31);
  li r0, 0x26;
  stb r9, 0x24(r31);
  stb r8, 0x25(r31);
  stb r7, 0x26(r31);
  stb r6, 0x27(r31);
lbl_80531a4c:
  lbz r6, 4(r4);
  addi r9, r3, 0x23;
  stb r6, 4(r3);
  addi r8, r4, 0x23;
  lbz r6, 5(r4);
  stb r6, 5(r3);
  lbz r6, 6(r4);
  stb r6, 6(r3);
  lwz r6, 8(r4);
  stw r6, 8(r3);
  lwz r6, 0xc(r4);
  stw r6, 0xc(r3);
  lwz r6, 0x10(r4);
  stw r6, 0x10(r3);
  lwz r6, 0x18(r4);
  stw r6, 0x18(r3);
  lbz r6, 0x1c(r4);
  stb r6, 0x1c(r3);
  lbz r6, 0x1d(r4);
  stb r6, 0x1d(r3);
  lwz r6, 0x20(r4);
  stw r6, 0x20(r3);
  mtctr r0;
lbl_80531aa8:
  lbz r7, 1(r8);
  lbzu r6, 2(r8);
  stb r7, 1(r9);
  stbu r6, 2(r9);
  bdnz lbl_80531aa8;
  lwz r6, 0x70(r4);
  stw r6, 0x70(r3);
  lbz r6, 0x74(r4);
  stb r6, 0x74(r3);
  lbz r6, 0x75(r4);
  stb r6, 0x75(r3);
  lbz r6, 0x76(r4);
  stb r6, 0x76(r3);
  lbz r6, 0x77(r4);
  stb r6, 0x77(r3);
  lwz r6, 0x78(r4);
  stw r6, 0x78(r3);
  lwz r6, 0x80(r4);
  lwz r7, 0x7c(r4);
  stw r7, 0x7c(r3);
  stw r6, 0x80(r3);
  lwz r6, 0x88(r4);
  lwz r7, 0x84(r4);
  stw r7, 0x84(r3);
  stw r6, 0x88(r3);
  lwz r6, 0x90(r4);
  lwz r7, 0x8c(r4);
  stw r7, 0x8c(r3);
  stw r6, 0x90(r3);
  lwz r6, 0x98(r4);
  lwz r7, 0x94(r4);
  stw r7, 0x94(r3);
  stw r6, 0x98(r3);
  lwz r6, 0xa0(r4);
  lwz r7, 0x9c(r4);
  stw r7, 0x9c(r3);
  stw r6, 0xa0(r3);
  lwz r6, 0xa8(r4);
  lwz r7, 0xa4(r4);
  stw r7, 0xa4(r3);
  stw r6, 0xa8(r3);
  lwz r6, 0xb0(r4);
  lwz r7, 0xac(r4);
  stw r7, 0xac(r3);
  stw r6, 0xb0(r3);
  lwz r6, 0xb4(r4);
  stw r6, 0xb4(r3);
  lbz r6, 0xb8(r4);
  stb r6, 0xb8(r3);
  lbz r6, 0xb9(r4);
  stb r6, 0xb9(r3);
  lbz r6, 0xba(r4);
  stb r6, 0xba(r3);
  lwz r6, 0xbc(r4);
  stw r6, 0xbc(r3);
  lbz r6, 0xc0(r4);
  stb r6, 0xc0(r3);
  lbz r6, 0xc1(r4);
  stb r6, 0xc1(r3);
  lbz r6, 0xc2(r4);
  stb r6, 0xc2(r3);
  lwz r6, 0xc4(r4);
  stw r6, 0xc4(r3);
  lwz r6, 0xc8(r4);
  stw r6, 0xc8(r3);
  lwz r6, 0xcc(r4);
  stw r6, 0xcc(r3);
  lwz r6, 0xd0(r4);
  stw r6, 0xd0(r3);
  lwz r6, 0xd4(r4);
  stw r6, 0xd4(r3);
  lhz r6, 0xd8(r4);
  sth r6, 0xd8(r3);
  lhz r6, 0xda(r4);
  sth r6, 0xda(r3);
  lhz r6, 0xdc(r4);
  sth r6, 0xdc(r3);
  lha r6, 0xde(r4);
  sth r6, 0xde(r3);
  lbz r6, 0xe0(r4);
  stb r6, 0xe0(r3);
  lbz r6, 0xe1(r4);
  stb r6, 0xe1(r3);
  lbz r6, 0xe2(r4);
  stb r6, 0xe2(r3);
  lhz r6, 0xe8(r4);
  sth r6, 0xe8(r3);
  lbz r6, 0xec(r4);
  addi r4, r4, 0xf0;
  stb r6, 0xec(r3);
  addi r3, r3, 0xf0;
  cmplw r3, r5;
  blt lbl_80531a4c;
  lwz r22, 0x1758(r31);
  li r0, 0xe;
  lwz r23, 0x175c(r31);
  addi r5, r31, 0xb98;
  lwz r24, 0x1760(r31);
  addi r4, r31, 0x1788;
  lwz r25, 0x1764(r31);
  lwz r26, 0x1768(r31);
  lwz r27, 0x176c(r31);
  lwz r28, 0x1770(r31);
  lbz r29, 0x1774(r31);
  lbz r30, 0x1775(r31);
  lbz r12, 0x1776(r31);
  lbz r11, 0x1777(r31);
  lwz r10, 0x1778(r31);
  lbz r9, 0x177c(r31);
  lbz r8, 0x177d(r31);
  lwz r7, 0x1780(r31);
  lwz r6, 0x1784(r31);
  lwz r3, 0x1788(r31);
  stw r22, 0xb68(r31);
  stw r23, 0xb6c(r31);
  stw r24, 0xb70(r31);
  stw r25, 0xb74(r31);
  stw r26, 0xb78(r31);
  stw r27, 0xb7c(r31);
  stw r28, 0xb80(r31);
  stb r29, 0xb84(r31);
  stb r30, 0xb85(r31);
  stb r12, 0xb86(r31);
  stb r11, 0xb87(r31);
  stw r10, 0xb88(r31);
  stb r9, 0xb8c(r31);
  stb r8, 0xb8d(r31);
  stw r7, 0xb90(r31);
  stw r6, 0xb94(r31);
  stw r3, 0xb98(r31);
  mtctr r0;
lbl_80531cb4:
  lwz r3, 4(r4);
  lwzu r0, 8(r4);
  stw r3, 4(r5);
  stwu r0, 8(r5);
  bdnz lbl_80531cb4;
  lwz r0, 0x17fc(r31);
  stw r0, 0xc0c(r31);
  lmw r21, 0x14(r1);
  lwz r0, 0x44(r1);
  mtlr r0;
  addi r1, r1, 0x40;
  blr;
  // clang-format on
}

namespace System {

u8 RaceConfig::update() { return mMenuScenario.update(); }

} // namespace System

// Symbol: unk_80531de4
// PAL: 0x80531de4..0x80531f18
// Scratch: https://decomp.me/scratch/kUMDQ
MARK_BINARY_BLOB(unk_80531de4, 0x80531de4, 0x80531f18);
asm UNKNOWN_FUNCTION(unk_80531de4) {
  // clang-format off
  nofralloc;
  stwu r1, -0x20(r1);
  mflr r0;
  stw r0, 0x24(r1);
  stmw r27, 0xc(r1);
  lis r31, 0;
  mr r27, r3;
  mr r28, r4;
  mr r3, r28;
  addi r4, r27, 0xb48;
  lwz r5, 0(r31);
  lwz r6, 0x34(r5);
  li r5, 4;
  bl unk_805553b0;
  lwz r6, 0(r31);
  mr r3, r28;
  addi r4, r27, 0xb4c;
  li r5, 4;
  lwz r6, 0x34(r6);
  bl unk_805553b0;
  lwz r6, 0(r31);
  mr r3, r28;
  addi r4, r27, 0xb50;
  li r5, 4;
  lwz r6, 0x34(r6);
  bl unk_805553b0;
  lwz r6, 0(r31);
  mr r3, r28;
  addi r4, r27, 4;
  li r5, 1;
  lwz r6, 0x34(r6);
  bl unk_805553b0;
  lwz r6, 0(r31);
  mr r3, r28;
  addi r4, r27, 6;
  li r5, 1;
  lwz r6, 0x34(r6);
  bl unk_805553b0;
  addi r30, r27, 8;
  li r29, 0;
lbl_80531e80:
  lwz r6, 0(r31);
  mr r3, r28;
  addi r4, r30, 8;
  li r5, 4;
  lwz r6, 0x34(r6);
  bl unk_805553b0;
  lwz r6, 0(r31);
  mr r3, r28;
  addi r4, r30, 0xc;
  li r5, 4;
  lwz r6, 0x34(r6);
  bl unk_805553b0;
  lwz r6, 0(r31);
  mr r3, r28;
  addi r4, r30, 0x10;
  li r5, 4;
  lwz r6, 0x34(r6);
  bl unk_805553b0;
  lwz r6, 0(r31);
  mr r3, r28;
  addi r4, r30, 0xcc;
  li r5, 4;
  lwz r6, 0x34(r6);
  bl unk_805553b0;
  addi r29, r29, 1;
  addi r30, r30, 0xf0;
  cmpwi r29, 0xc;
  blt lbl_80531e80;
  mr r3, r28;
  addi r4, r27, 0xb70;
  li r5, 4;
  li r6, 0;
  bl unk_805553b0;
  lmw r27, 0xc(r1);
  lwz r0, 0x24(r1);
  mtlr r0;
  addi r1, r1, 0x20;
  blr;
  // clang-format on
}

namespace System {

// This is so stupid, Nintendo just HAD to use r0
s32 RaceConfig::getLocalPlayerCount(u8 playerIdx) {
  return (s8)(u8)mRaceScenario.mPlayers[playerIdx].mLocalPlayerNum;
}

void RaceConfig::setGhost(RawGhostFile* ghost) {
  if (mRaceScenario.mGhost == mMenuScenario.mGhost) {
    if (mRaceScenario.mGhost == &mGhosts[0]) {
      mMenuScenario.mGhost = &mGhosts[1];
    } else if (mRaceScenario.mGhost == &mGhosts[1]) {
      mMenuScenario.mGhost = &mGhosts[0];
    }
  }
  memcpy(mMenuScenario.mGhost, ghost, 0x2800);
}

s8 RaceConfig::getHudPlayerId(u8 playerIdx) {
  return (s8)(u8)mRaceScenario.mSettings.mHudPlayerIds[playerIdx];
}

void RaceConfig::loadNextCourse() {
  if (mRaceScenario.mSettings.mGameMode != 0) {
    return;
  }

  u8 raceNumber = mRaceScenario.mSettings.mRaceNumber;
  if (raceNumber >= 3) {
    return;
  }

  ResourceManager::spInstance_REAL->preloadCourseAsync(
      COURSE_ORDER[mRaceScenario.mSettings.mCupId][raceNumber + 1]);
}

// Unsure what to call this because I'm unsure of what it does
bool RaceConfig::unk_80531fc8(u8 hudPlayerIdx) {
  s32 gameType = mRaceScenario.mSettings.mGameType;
  if (gameType > 1 && gameType < 5) {
    return true;
  }

  if (gameType == 1) {
    return true;
  }

  s32 playerId = mRaceScenario.mSettings.mHudPlayerIds[hudPlayerIdx];
  if (playerId >= 0) {
    s32 playerType = mRaceScenario.mPlayers[(u8)playerId].mPlayerType;
    if (playerType != 0 && playerType != 3) {
      return true;
    }
  }

  return false;
}

bool RaceConfig::isTimeAttackReplay() {
  const s32 gameMode = mRaceScenario.mSettings.mGameMode;

  return ((gameMode == 2 || gameMode == 5) &&
          spInstance->mRaceScenario.mPlayerCount != 0 &&
          spInstance->mRaceScenario.mPlayers[0].mPlayerType == 3)
             ? true
             : false;
}

void RaceConfig::vf18() {}

void RaceConfig::vf14() {}

void RaceConfig::vf10() {}

} // namespace System

// Symbol: unk_8053207c
// PAL: 0x8053207c..0x80532084
MARK_BINARY_BLOB(unk_8053207c, 0x8053207c, 0x80532084);
asm UNKNOWN_FUNCTION(unk_8053207c) {
  // clang-format off
  nofralloc;
  li r3, 0;
  blr;
  // clang-format on
}

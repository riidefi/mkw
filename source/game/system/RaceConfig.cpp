#include "RaceConfig.hpp"

#pragma legacy_struct_alignment off

// --- EXTERN DECLARATIONS BEGIN ---

extern "C" {

// Extern function references.
// PAL: 0x80009d6c
extern UNKNOWN_FUNCTION(appendData__Q26System13ParameterFileFPcUlPQ23EGG4Heap);
// PAL: 0x8052fb90
extern UNKNOWN_FUNCTION(
    initRace__Q26System18RaceConfigScenarioFPQ26System18RaceConfigScenario);
// PAL: 0x8052d270
extern UNKNOWN_FUNCTION(unk_8052d270);
// PAL: 0x805368f8
extern UNKNOWN_FUNCTION(RaceinfoPlayer_updateGpRankScore);
// PAL: 0x8052d118
extern UNKNOWN_FUNCTION(unk_8052d118);
// PAL: 0x800215b8
extern UNKNOWN_FUNCTION(_restgpr_14);
// PAL: 0x8002156c
extern UNKNOWN_FUNCTION(_savegpr_14);
// PAL: 0x8052d1c0
extern UNKNOWN_FUNCTION(calcNegPoints__Q26System6RatingFPQ26System6Rating);
// PAL: 0x80524500
extern UNKNOWN_FUNCTION(unk_80524500);
// PAL: 0x80524558
extern UNKNOWN_FUNCTION(unk_80524558);
// PAL: 0x8051c120
extern UNKNOWN_FUNCTION(isValid__Q26System12RawGhostFileCFv);
// PAL: 0x800210ec
extern UNKNOWN_FUNCTION(__destroy_arr);
// PAL: 0x8051c334
extern UNKNOWN_FUNCTION(__dt__Q26System4TimeFv);
// PAL: 0x8052453c
extern UNKNOWN_FUNCTION(InputMgr_setGhostController);
// PAL: 0x8051c790
extern UNKNOWN_FUNCTION(read__Q26System9GhostFileFRCQ26System12RawGhostFile);
// PAL: 0x8051c270
extern UNKNOWN_FUNCTION(__ct__Q26System9GhostFileFv);
// PAL: 0x8066c8d8
// extern UNKNOWN_FUNCTION(unk_8066c8d8);
// PAL: 0x8051c088
extern UNKNOWN_FUNCTION(reset__Q26System12RawGhostFileFv);
// PAL: 0x8052d96c
extern UNKNOWN_FUNCTION(__ct__Q26System16RaceConfigPlayerFv);
// PAL: 0x80229dcc
extern UNKNOWN_FUNCTION(__nw__FUl);
// PAL: 0x80009c8c
extern UNKNOWN_FUNCTION(__ct__Q26System13ParameterFileFPCcUl);
// PAL: 0x80020ff4
extern UNKNOWN_FUNCTION(__construct_array);
// PAL: 0x8052dc68
extern UNKNOWN_FUNCTION(__dt__Q26System16RaceConfigPlayerFv);
// PAL: 0x80009ce0
extern UNKNOWN_FUNCTION(__dt__Q26System13ParameterFileFv);
// PAL: 0x8052ed20
extern UNKNOWN_FUNCTION(getPlayerType__Q26System16RaceConfigPlayerFv);
// PAL: 0x8052e660
extern UNKNOWN_FUNCTION(setUnkPos__Q26System16RaceConfigPlayerFSc);
// PAL: 0x8052dd30
extern UNKNOWN_FUNCTION(getRacePlayerCount__Q26System10RaceConfigFv);
// PAL: 0x8052e44c
extern UNKNOWN_FUNCTION(setPlayerType__Q26System16RaceConfigPlayerFl);
// PAL: 0x8052ed18
extern UNKNOWN_FUNCTION(getGametype__Q26System18RaceConfigScenarioFv);
// PAL: 0x80530f20
extern UNKNOWN_FUNCTION(getCharacter__Q26System16RaceConfigPlayerFv);
// PAL: 0x8052e444
extern UNKNOWN_FUNCTION(
    setVehicle__Q26System16RaceConfigPlayerFQ26System9VehicleId);
// PAL: 0x80531068
extern UNKNOWN_FUNCTION(getMii__Q26System16RaceConfigPlayerFv);
// PAL: 0x8052dd18
extern UNKNOWN_FUNCTION(getTeam__Q26System16RaceConfigPlayerFv);
// PAL: 0x80530f30
extern UNKNOWN_FUNCTION(setMii__Q26System16RaceConfigPlayerFRCQ26System3Mii);
// PAL: 0x80530f18
extern UNKNOWN_FUNCTION(getUnkPos__Q26System16RaceConfigPlayerFv);
// PAL: 0x80530f28
extern UNKNOWN_FUNCTION(getVehicle__Q26System16RaceConfigPlayerFv);
// PAL: 0x805302c4
extern UNKNOWN_FUNCTION(initRace__Q26System10RaceConfigFv);
// PAL: 0x8052e658
extern UNKNOWN_FUNCTION(setPrevFinishPos__Q26System16RaceConfigPlayerFSc);
// PAL: 0x8052dd20
extern UNKNOWN_FUNCTION(getPlayer__Q26System18RaceConfigScenarioCFUc);
// PAL: 0x8052e434
extern UNKNOWN_FUNCTION(getPlayer__Q26System18RaceConfigScenarioFUc);
// PAL: 0x80530f0c
extern UNKNOWN_FUNCTION(isTeamMode__Q26System18RaceConfigScenarioFv);
// PAL: 0x8052dca8
extern UNKNOWN_FUNCTION(computeWinningTeam__Q26System18RaceConfigScenarioFv);
// PAL: 0x8052e42c
extern UNKNOWN_FUNCTION(
    setCharacter__Q26System16RaceConfigPlayerFQ26System11CharacterId);
// PAL: 0x805305ac
extern UNKNOWN_FUNCTION(RacedataScenario_copy);
// PAL: 0x809bd740
extern UNKNOWN_DATA(spInstance__Q26System9InitScene);
// PAL: 0x80890030
extern UNKNOWN_DATA(VS_POINT_DISTRIBUTION__6System);
// PAL: 0x809bd730
extern UNKNOWN_DATA(lbl_809bd730);
// PAL: 0x809bd728
extern UNKNOWN_DATA(spInstance__Q26System10RaceConfig);
// PAL: 0x809bd70c
extern UNKNOWN_DATA(lbl_809bd70c);
// PAL: 0x8088ffb0
extern UNKNOWN_DATA(COURSE_ORDER__6System);
// PAL: 0x809c2144
// extern UNKNOWN_DATA(lbl_809c2144);
extern void* lbl_809c2144;
// PAL: 0x808b3260
extern UNKNOWN_DATA(__vt__Q26System10RaceConfig);
// PAL: 0x808b3288
extern UNKNOWN_DATA(__vt__Q26System18RaceConfigScenario);
}

// --- EXTERN DECLARATIONS END ---

// relsymdefs
extern "C" {
#ifndef SHIFTABLE
extern f64 lbl_8088ffa8;
REL_SYMBOL_AT(lbl_8088ffa8, 0x8088ffa8)
#else
static const f64 lbl_8088ffa8 = 0.0;
#endif
#ifndef SHIFTABLE
extern f64 lbl_808900e0;
REL_SYMBOL_AT(lbl_808900e0, 0x808900e0)
#else
static const f64 lbl_808900e0 = 5.444520466883445e+39;
#endif
#ifndef SHIFTABLE
extern const char lbl_80890124[][0x12];
REL_SYMBOL_AT(lbl_80890124, 0x80890124)
#else
const char lbl_80890124[][0x12] = {"/boot/menuset.prm", "/boot/menuset.prm"};
#endif
}

namespace System {
extern const f32 ZERO_FLOAT;
extern const CourseId COURSE_ORDER[8][4];
extern const u8 VS_POINT_DISTRIBUTION[12][12];
extern const s32 RANK_SCORES[5];
extern const u16 SCORES[4];
extern const s32 lbl_808900e8[15];
extern const char lbl_80890124[][0x12];

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

// bss
RaceConfig* RaceConfig::spInstance;

extern "C" void getCompetitionWrapper(void*, CompetitionWrapper*);

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
  memset(&this->mCompetitionSettings, 0, sizeof(CompetitionSettings));

  mGhost = ghost;
}

RaceConfigPlayer::~RaceConfigPlayer() {}

BattleTeam RaceConfigScenario::computeWinningTeam() {
  u16 results[] = {0, 0};

  for (u8 i = 0; i < RaceConfig::spInstance->mRaceScenario.mPlayerCount; i++) {
    const BattleTeam team = mPlayers[i].mTeam;
    results[team] += mPlayers[i].mPreviousScore;
  }

  return (results[0] < results[1]) ? BATTLE_TEAM_BLUE : BATTLE_TEAM_RED;
}

BattleTeam RaceConfigPlayer::getTeam() { return mTeam; }

const RaceConfigPlayer& RaceConfigScenario::getPlayer(u8 idx) const {
  return mPlayers[idx];
}

const u8 RaceConfig::getRacePlayerCount() {
  return RaceConfig::spInstance->mRaceScenario.mPlayerCount;
}

} // namespace System

// Symbol: Racedata_init
// PAL: 0x8052dd40..0x8052e42c
MARK_BINARY_BLOB(Racedata_init, 0x8052dd40, 0x8052e42c);
asm UNKNOWN_FUNCTION(Racedata_init) {
  // clang-format off
  nofralloc
  /* 8052DD40 9421FFD0 */ stwu        r1, -0x30(r1)
  /* 8052DD44 7C0802A6 */ mflr        r0
  /* 8052DD48 39400000 */ li          r10, 0x0
  /* 8052DD4C 38A00011 */ li          r5, 0x11
  /* 8052DD50 90010034 */ stw         r0, 0x34(r1)
  /* 8052DD54 38000003 */ li          r0, 0x3
  /* 8052DD58 39200002 */ li          r9, 0x2
  /* 8052DD5C 39000001 */ li          r8, 0x1
  /* 8052DD60 BEC10008 */ stmw        r22, 8(r1)
  /* 8052DD64 7C7F1B78 */ mr          r31, r3
  /* 8052DD68 39600000 */ li          r11, 0x0
  /* 8052DD6C 80831780 */ lwz         r4, 0x1780(r3)
  /* 8052DD70 90A31758 */ stw         r5, 0x1758(r3)
  /* 8052DD74 54840038 */ rlwinm      r4, r4, 0, 0, 0x1c
  /* 8052DD78 91431760 */ stw         r10, 0x1760(r3)
  /* 8052DD7C 91431764 */ stw         r10, 0x1764(r3)
  /* 8052DD80 91431778 */ stw         r10, 0x1778(r3)
  /* 8052DD84 9123175C */ stw         r9, 0x175c(r3)
  /* 8052DD88 9103176C */ stw         r8, 0x176c(r3)
  /* 8052DD8C 90831780 */ stw         r4, 0x1780(r3)
  /* 8052DD90 7C0903A6 */ mtctr       r0
  lbl_8052dd94:
  /* 8052DD94 5564063E */ clrlwi      r4, r11, 0x18
  /* 8052DD98 396B0001 */ addi        r11, r11, 0x1
  /* 8052DD9C 1CE400F0 */ mulli       r7, r4, 0xf0
  /* 8052DDA0 7CA400D0 */ neg         r5, r4
  /* 8052DDA4 5560063E */ clrlwi      r0, r11, 0x18
  /* 8052DDA8 7CC33A14 */ add         r6, r3, r7
  /* 8052DDAC 7CA52378 */ or          r5, r5, r4
  /* 8052DDB0 91460C24 */ stw         r10, 0xc24(r6)
  /* 8052DDB4 54A40FFE */ srwi        r4, r5, 0x1f
  /* 8052DDB8 7CA000D0 */ neg         r5, r0
  /* 8052DDBC 396B0001 */ addi        r11, r11, 0x1
  /* 8052DDC0 91060C20 */ stw         r8, 0xc20(r6)
  /* 8052DDC4 1CE000F0 */ mulli       r7, r0, 0xf0
  /* 8052DDC8 7CA50378 */ or          r5, r5, r0
  /* 8052DDCC 90860C28 */ stw         r4, 0xc28(r6)
  /* 8052DDD0 5560063E */ clrlwi      r0, r11, 0x18
  /* 8052DDD4 54A40FFE */ srwi        r4, r5, 0x1f
  /* 8052DDD8 396B0001 */ addi        r11, r11, 0x1
  /* 8052DDDC 91260CE4 */ stw         r9, 0xce4(r6)
  /* 8052DDE0 7CC33A14 */ add         r6, r3, r7
  /* 8052DDE4 7CA000D0 */ neg         r5, r0
  /* 8052DDE8 91460C24 */ stw         r10, 0xc24(r6)
  /* 8052DDEC 1CE000F0 */ mulli       r7, r0, 0xf0
  /* 8052DDF0 7CA50378 */ or          r5, r5, r0
  /* 8052DDF4 91060C20 */ stw         r8, 0xc20(r6)
  /* 8052DDF8 5560063E */ clrlwi      r0, r11, 0x18
  /* 8052DDFC 396B0001 */ addi        r11, r11, 0x1
  /* 8052DE00 90860C28 */ stw         r4, 0xc28(r6)
  /* 8052DE04 54A40FFE */ srwi        r4, r5, 0x1f
  /* 8052DE08 7CA000D0 */ neg         r5, r0
  /* 8052DE0C 91260CE4 */ stw         r9, 0xce4(r6)
  /* 8052DE10 7CC33A14 */ add         r6, r3, r7
  /* 8052DE14 1CE000F0 */ mulli       r7, r0, 0xf0
  /* 8052DE18 7CA50378 */ or          r5, r5, r0
  /* 8052DE1C 91460C24 */ stw         r10, 0xc24(r6)
  /* 8052DE20 91060C20 */ stw         r8, 0xc20(r6)
  /* 8052DE24 90860C28 */ stw         r4, 0xc28(r6)
  /* 8052DE28 54A40FFE */ srwi        r4, r5, 0x1f
  /* 8052DE2C 91260CE4 */ stw         r9, 0xce4(r6)
  /* 8052DE30 7CC33A14 */ add         r6, r3, r7
  /* 8052DE34 91460C24 */ stw         r10, 0xc24(r6)
  /* 8052DE38 91060C20 */ stw         r8, 0xc20(r6)
  /* 8052DE3C 90860C28 */ stw         r4, 0xc28(r6)
  /* 8052DE40 91260CE4 */ stw         r9, 0xce4(r6)
  /* 8052DE44 4200FF50 */ bdnz        lbl_8052dd94
  /* 8052DE48 80831780 */ lwz         r4, 0x1780(r3)
  /* 8052DE4C 38C00001 */ li          r6, 0x1
  /* 8052DE50 38000002 */ li          r0, 0x2
  /* 8052DE54 39600000 */ li          r11, 0x0
  /* 8052DE58 54840038 */ rlwinm      r4, r4, 0, 0, 0x1c
  /* 8052DE5C 38A00003 */ li          r5, 0x3
  /* 8052DE60 91631770 */ stw         r11, 0x1770(r3)
  /* 8052DE64 39800000 */ li          r12, 0x0
  /* 8052DE68 90C3176C */ stw         r6, 0x176c(r3)
  /* 8052DE6C 98A3177D */ stb         r5, 0x177d(r3)
  /* 8052DE70 90C3175C */ stw         r6, 0x175c(r3)
  /* 8052DE74 90831780 */ stw         r4, 0x1780(r3)
  /* 8052DE78 7C0903A6 */ mtctr       r0
  lbl_8052de7c:
  /* 8052DE7C 558A063E */ clrlwi      r10, r12, 0x18
  /* 8052DE80 380C0002 */ addi        r0, r12, 0x2
  /* 8052DE84 1CAA00F0 */ mulli       r5, r10, 0xf0
  /* 8052DE88 388C0001 */ addi        r4, r12, 0x1
  /* 8052DE8C 5407063E */ clrlwi      r7, r0, 0x18
  /* 8052DE90 380C0003 */ addi        r0, r12, 0x3
  /* 8052DE94 7D232A14 */ add         r9, r3, r5
  /* 8052DE98 5488063E */ clrlwi      r8, r4, 0x18
  /* 8052DE9C B1690CF0 */ sth         r11, 0xcf0(r9)
  /* 8052DEA0 5406063E */ clrlwi      r6, r0, 0x18
  /* 8052DEA4 388C0004 */ addi        r4, r12, 0x4
  /* 8052DEA8 380C0005 */ addi        r0, r12, 0x5
  /* 8052DEAC B1690CF6 */ sth         r11, 0xcf6(r9)
  /* 8052DEB0 5485063E */ clrlwi      r5, r4, 0x18
  /* 8052DEB4 394A0001 */ addi        r10, r10, 0x1
  /* 8052DEB8 5404063E */ clrlwi      r4, r0, 0x18
  /* 8052DEBC 99490CF9 */ stb         r10, 0xcf9(r9)
  /* 8052DEC0 38080001 */ addi        r0, r8, 0x1
  /* 8052DEC4 38E70001 */ addi        r7, r7, 0x1
  /* 8052DEC8 38C60001 */ addi        r6, r6, 0x1
  /* 8052DECC 99490CF8 */ stb         r10, 0xcf8(r9)
  /* 8052DED0 38A50001 */ addi        r5, r5, 0x1
  /* 8052DED4 38840001 */ addi        r4, r4, 0x1
  /* 8052DED8 398C0006 */ addi        r12, r12, 0x6
  /* 8052DEDC B1690DE0 */ sth         r11, 0xde0(r9)
  /* 8052DEE0 B1690DE6 */ sth         r11, 0xde6(r9)
  /* 8052DEE4 98090DE9 */ stb         r0, 0xde9(r9)
  /* 8052DEE8 98090DE8 */ stb         r0, 0xde8(r9)
  /* 8052DEEC B1690ED0 */ sth         r11, 0xed0(r9)
  /* 8052DEF0 B1690ED6 */ sth         r11, 0xed6(r9)
  /* 8052DEF4 98E90ED9 */ stb         r7, 0xed9(r9)
  /* 8052DEF8 98E90ED8 */ stb         r7, 0xed8(r9)
  /* 8052DEFC B1690FC0 */ sth         r11, 0xfc0(r9)
  /* 8052DF00 B1690FC6 */ sth         r11, 0xfc6(r9)
  /* 8052DF04 98C90FC9 */ stb         r6, 0xfc9(r9)
  /* 8052DF08 98C90FC8 */ stb         r6, 0xfc8(r9)
  /* 8052DF0C B16910B0 */ sth         r11, 0x10b0(r9)
  /* 8052DF10 B16910B6 */ sth         r11, 0x10b6(r9)
  /* 8052DF14 98A910B9 */ stb         r5, 0x10b9(r9)
  /* 8052DF18 98A910B8 */ stb         r5, 0x10b8(r9)
  /* 8052DF1C B16911A0 */ sth         r11, 0x11a0(r9)
  /* 8052DF20 B16911A6 */ sth         r11, 0x11a6(r9)
  /* 8052DF24 988911A9 */ stb         r4, 0x11a9(r9)
  /* 8052DF28 988911A8 */ stb         r4, 0x11a8(r9)
  /* 8052DF2C 4200FF50 */ bdnz        lbl_8052de7c
  /* 8052DF30 80832370 */ lwz         r4, 0x2370(r3)
  /* 8052DF34 39600000 */ li          r11, 0x0
  /* 8052DF38 38000002 */ li          r0, 0x2
  /* 8052DF3C 38C00003 */ li          r6, 0x3
  /* 8052DF40 38A00001 */ li          r5, 0x1
  /* 8052DF44 54840038 */ rlwinm      r4, r4, 0, 0, 0x1c
  /* 8052DF48 9963177C */ stb         r11, 0x177c(r3)
  /* 8052DF4C 39800000 */ li          r12, 0x0
  /* 8052DF50 98C3177D */ stb         r6, 0x177d(r3)
  /* 8052DF54 91632360 */ stw         r11, 0x2360(r3)
  /* 8052DF58 90A3235C */ stw         r5, 0x235c(r3)
  /* 8052DF5C 98C3236D */ stb         r6, 0x236d(r3)
  /* 8052DF60 90A3234C */ stw         r5, 0x234c(r3)
  /* 8052DF64 90832370 */ stw         r4, 0x2370(r3)
  /* 8052DF68 7C0903A6 */ mtctr       r0
  lbl_8052df6c:
  /* 8052DF6C 558A063E */ clrlwi      r10, r12, 0x18
  /* 8052DF70 380C0002 */ addi        r0, r12, 0x2
  /* 8052DF74 1CAA00F0 */ mulli       r5, r10, 0xf0
  /* 8052DF78 388C0001 */ addi        r4, r12, 0x1
  /* 8052DF7C 5407063E */ clrlwi      r7, r0, 0x18
  /* 8052DF80 380C0003 */ addi        r0, r12, 0x3
  /* 8052DF84 7D232A14 */ add         r9, r3, r5
  /* 8052DF88 5488063E */ clrlwi      r8, r4, 0x18
  /* 8052DF8C B16918E0 */ sth         r11, 0x18e0(r9)
  /* 8052DF90 5406063E */ clrlwi      r6, r0, 0x18
  /* 8052DF94 388C0004 */ addi        r4, r12, 0x4
  /* 8052DF98 380C0005 */ addi        r0, r12, 0x5
  /* 8052DF9C B16918E6 */ sth         r11, 0x18e6(r9)
  /* 8052DFA0 5485063E */ clrlwi      r5, r4, 0x18
  /* 8052DFA4 394A0001 */ addi        r10, r10, 0x1
  /* 8052DFA8 5404063E */ clrlwi      r4, r0, 0x18
  /* 8052DFAC 994918E9 */ stb         r10, 0x18e9(r9)
  /* 8052DFB0 38080001 */ addi        r0, r8, 0x1
  /* 8052DFB4 38E70001 */ addi        r7, r7, 0x1
  /* 8052DFB8 38C60001 */ addi        r6, r6, 0x1
  /* 8052DFBC 994918E8 */ stb         r10, 0x18e8(r9)
  /* 8052DFC0 38A50001 */ addi        r5, r5, 0x1
  /* 8052DFC4 38840001 */ addi        r4, r4, 0x1
  /* 8052DFC8 398C0006 */ addi        r12, r12, 0x6
  /* 8052DFCC B16919D0 */ sth         r11, 0x19d0(r9)
  /* 8052DFD0 B16919D6 */ sth         r11, 0x19d6(r9)
  /* 8052DFD4 980919D9 */ stb         r0, 0x19d9(r9)
  /* 8052DFD8 980919D8 */ stb         r0, 0x19d8(r9)
  /* 8052DFDC B1691AC0 */ sth         r11, 0x1ac0(r9)
  /* 8052DFE0 B1691AC6 */ sth         r11, 0x1ac6(r9)
  /* 8052DFE4 98E91AC9 */ stb         r7, 0x1ac9(r9)
  /* 8052DFE8 98E91AC8 */ stb         r7, 0x1ac8(r9)
  /* 8052DFEC B1691BB0 */ sth         r11, 0x1bb0(r9)
  /* 8052DFF0 B1691BB6 */ sth         r11, 0x1bb6(r9)
  /* 8052DFF4 98C91BB9 */ stb         r6, 0x1bb9(r9)
  /* 8052DFF8 98C91BB8 */ stb         r6, 0x1bb8(r9)
  /* 8052DFFC B1691CA0 */ sth         r11, 0x1ca0(r9)
  /* 8052E000 B1691CA6 */ sth         r11, 0x1ca6(r9)
  /* 8052E004 98A91CA9 */ stb         r5, 0x1ca9(r9)
  /* 8052E008 98A91CA8 */ stb         r5, 0x1ca8(r9)
  /* 8052E00C B1691D90 */ sth         r11, 0x1d90(r9)
  /* 8052E010 B1691D96 */ sth         r11, 0x1d96(r9)
  /* 8052E014 98891D99 */ stb         r4, 0x1d99(r9)
  /* 8052E018 98891D98 */ stb         r4, 0x1d98(r9)
  /* 8052E01C 4200FF50 */ bdnz        lbl_8052df6c
  /* 8052E020 38800000 */ li          r4, 0x0
  /* 8052E024 38000003 */ li          r0, 0x3
  /* 8052E028 9883236C */ stb         r4, 0x236c(r3)
  /* 8052E02C 3EC0809C */ lis         r22, spInstance__Q26System9InitScene@ha
  /* 8052E030 389F1758 */ addi        r4, r31, 0x1758
  /* 8052E034 38A00004 */ li          r5, 0x4
  /* 8052E038 9803236D */ stb         r0, 0x236d(r3)
  /* 8052E03C 7FE3FB78 */ mr          r3, r31
  /* 8052E040 80D6D740 */ lwz         r6, spInstance__Q26System9InitScene@l(r22)
  /* 8052E044 80C60034 */ lwz         r6, 0x34(r6)
  /* 8052E048 4BADBD25 */ bl          appendData__Q26System13ParameterFileFPcUlPQ23EGG4Heap
  /* 8052E04C 80D6D740 */ lwz         r6, spInstance__Q26System9InitScene@l(r22)
  /* 8052E050 7FE3FB78 */ mr          r3, r31
  /* 8052E054 389F175C */ addi        r4, r31, 0x175c
  /* 8052E058 38A00004 */ li          r5, 0x4
  /* 8052E05C 80C60034 */ lwz         r6, 0x34(r6)
  /* 8052E060 4BADBD0D */ bl          appendData__Q26System13ParameterFileFPcUlPQ23EGG4Heap
  /* 8052E064 80D6D740 */ lwz         r6, spInstance__Q26System9InitScene@l(r22)
  /* 8052E068 7FE3FB78 */ mr          r3, r31
  /* 8052E06C 389F1760 */ addi        r4, r31, 0x1760
  /* 8052E070 38A00004 */ li          r5, 0x4
  /* 8052E074 80C60034 */ lwz         r6, 0x34(r6)
  /* 8052E078 4BADBCF5 */ bl          appendData__Q26System13ParameterFileFPcUlPQ23EGG4Heap
  /* 8052E07C 80D6D740 */ lwz         r6, spInstance__Q26System9InitScene@l(r22)
  /* 8052E080 7FE3FB78 */ mr          r3, r31
  /* 8052E084 389F0C14 */ addi        r4, r31, 0xc14
  /* 8052E088 38A00001 */ li          r5, 0x1
  /* 8052E08C 80C60034 */ lwz         r6, 0x34(r6)
  /* 8052E090 4BADBCDD */ bl          appendData__Q26System13ParameterFileFPcUlPQ23EGG4Heap
  /* 8052E094 80D6D740 */ lwz         r6, spInstance__Q26System9InitScene@l(r22)
  /* 8052E098 7FE3FB78 */ mr          r3, r31
  /* 8052E09C 389F0C16 */ addi        r4, r31, 0xc16
  /* 8052E0A0 38A00001 */ li          r5, 0x1
  /* 8052E0A4 80C60034 */ lwz         r6, 0x34(r6)
  /* 8052E0A8 4BADBCC5 */ bl          appendData__Q26System13ParameterFileFPcUlPQ23EGG4Heap
  /* 8052E0AC 3B1F0C18 */ addi        r24, r31, 0xc18
  /* 8052E0B0 3AE00000 */ li          r23, 0x0
  lbl_8052e0b4:
  /* 8052E0B4 80D6D740 */ lwz         r6, spInstance__Q26System9InitScene@l(r22)
  /* 8052E0B8 7FE3FB78 */ mr          r3, r31
  /* 8052E0BC 38980008 */ addi        r4, r24, 0x8
  /* 8052E0C0 38A00004 */ li          r5, 0x4
  /* 8052E0C4 80C60034 */ lwz         r6, 0x34(r6)
  /* 8052E0C8 4BADBCA5 */ bl          appendData__Q26System13ParameterFileFPcUlPQ23EGG4Heap
  /* 8052E0CC 80D6D740 */ lwz         r6, spInstance__Q26System9InitScene@l(r22)
  /* 8052E0D0 7FE3FB78 */ mr          r3, r31
  /* 8052E0D4 3898000C */ addi        r4, r24, 0xc
  /* 8052E0D8 38A00004 */ li          r5, 0x4
  /* 8052E0DC 80C60034 */ lwz         r6, 0x34(r6)
  /* 8052E0E0 4BADBC8D */ bl          appendData__Q26System13ParameterFileFPcUlPQ23EGG4Heap
  /* 8052E0E4 80D6D740 */ lwz         r6, spInstance__Q26System9InitScene@l(r22)
  /* 8052E0E8 7FE3FB78 */ mr          r3, r31
  /* 8052E0EC 38980010 */ addi        r4, r24, 0x10
  /* 8052E0F0 38A00004 */ li          r5, 0x4
  /* 8052E0F4 80C60034 */ lwz         r6, 0x34(r6)
  /* 8052E0F8 4BADBC75 */ bl          appendData__Q26System13ParameterFileFPcUlPQ23EGG4Heap
  /* 8052E0FC 80D6D740 */ lwz         r6, spInstance__Q26System9InitScene@l(r22)
  /* 8052E100 7FE3FB78 */ mr          r3, r31
  /* 8052E104 389800CC */ addi        r4, r24, 0xcc
  /* 8052E108 38A00004 */ li          r5, 0x4
  /* 8052E10C 80C60034 */ lwz         r6, 0x34(r6)
  /* 8052E110 4BADBC5D */ bl          appendData__Q26System13ParameterFileFPcUlPQ23EGG4Heap
  /* 8052E114 3AF70001 */ addi        r23, r23, 0x1
  /* 8052E118 3B1800F0 */ addi        r24, r24, 0xf0
  /* 8052E11C 2C17000C */ cmpwi       r23, 0xc
  /* 8052E120 4180FF94 */ blt+        lbl_8052e0b4
  /* 8052E124 7FE3FB78 */ mr          r3, r31
  /* 8052E128 389F1780 */ addi        r4, r31, 0x1780
  /* 8052E12C 38A00004 */ li          r5, 0x4
  /* 8052E130 38C00000 */ li          r6, 0x0
  /* 8052E134 4BADBC39 */ bl          appendData__Q26System13ParameterFileFPcUlPQ23EGG4Heap
  /* 8052E138 819F0000 */ lwz         r12, 0(r31)
  /* 8052E13C 3C80809C */ lis         r4, spInstance__Q26System9InitScene@ha
  /* 8052E140 8084D740 */ lwz         r4, spInstance__Q26System9InitScene@l(r4)
  /* 8052E144 7FE3FB78 */ mr          r3, r31
  /* 8052E148 818C000C */ lwz         r12, 0xc(r12)
  /* 8052E14C 80840034 */ lwz         r4, 0x34(r4)
  /* 8052E150 7D8903A6 */ mtctr       r12
  /* 8052E154 4E800421 */ bctrl
  /* 8052E158 387F0C10 */ addi        r3, r31, 0xc10
  /* 8052E15C 389F0020 */ addi        r4, r31, 0x20
  /* 8052E160 48001A31 */ bl          initRace__Q26System18RaceConfigScenarioFPQ26System18RaceConfigScenario
  /* 8052E164 893F0C14 */ lbz         r9, 0xc14(r31)
  /* 8052E168 387F0028 */ addi        r3, r31, 0x28
  /* 8052E16C 891F0C15 */ lbz         r8, 0xc15(r31)
  /* 8052E170 389F0C18 */ addi        r4, r31, 0xc18
  /* 8052E174 88FF0C16 */ lbz         r7, 0xc16(r31)
  /* 8052E178 38BF0B68 */ addi        r5, r31, 0xb68
  /* 8052E17C 88DF0C17 */ lbz         r6, 0xc17(r31)
  /* 8052E180 38000026 */ li          r0, 0x26
  /* 8052E184 993F0024 */ stb         r9, 0x24(r31)
  /* 8052E188 991F0025 */ stb         r8, 0x25(r31)
  /* 8052E18C 98FF0026 */ stb         r7, 0x26(r31)
  /* 8052E190 98DF0027 */ stb         r6, 0x27(r31)
  lbl_8052e194:
  /* 8052E194 88C40004 */ lbz         r6, 4(r4)
  /* 8052E198 39230023 */ addi        r9, r3, 0x23
  /* 8052E19C 98C30004 */ stb         r6, 4(r3)
  /* 8052E1A0 39040023 */ addi        r8, r4, 0x23
  /* 8052E1A4 88C40005 */ lbz         r6, 5(r4)
  /* 8052E1A8 98C30005 */ stb         r6, 5(r3)
  /* 8052E1AC 88C40006 */ lbz         r6, 6(r4)
  /* 8052E1B0 98C30006 */ stb         r6, 6(r3)
  /* 8052E1B4 80C40008 */ lwz         r6, 8(r4)
  /* 8052E1B8 90C30008 */ stw         r6, 8(r3)
  /* 8052E1BC 80C4000C */ lwz         r6, 0xc(r4)
  /* 8052E1C0 90C3000C */ stw         r6, 0xc(r3)
  /* 8052E1C4 80C40010 */ lwz         r6, 0x10(r4)
  /* 8052E1C8 90C30010 */ stw         r6, 0x10(r3)
  /* 8052E1CC 80C40018 */ lwz         r6, 0x18(r4)
  /* 8052E1D0 90C30018 */ stw         r6, 0x18(r3)
  /* 8052E1D4 88C4001C */ lbz         r6, 0x1c(r4)
  /* 8052E1D8 98C3001C */ stb         r6, 0x1c(r3)
  /* 8052E1DC 88C4001D */ lbz         r6, 0x1d(r4)
  /* 8052E1E0 98C3001D */ stb         r6, 0x1d(r3)
  /* 8052E1E4 80C40020 */ lwz         r6, 0x20(r4)
  /* 8052E1E8 90C30020 */ stw         r6, 0x20(r3)
  /* 8052E1EC 7C0903A6 */ mtctr       r0
  lbl_8052e1f0:
  /* 8052E1F0 88E80001 */ lbz         r7, 1(r8)
  /* 8052E1F4 8CC80002 */ lbzu        r6, 2(r8)
  /* 8052E1F8 98E90001 */ stb         r7, 1(r9)
  /* 8052E1FC 9CC90002 */ stbu        r6, 2(r9)
  /* 8052E200 4200FFF0 */ bdnz        lbl_8052e1f0
  /* 8052E204 80C40070 */ lwz         r6, 0x70(r4)
  /* 8052E208 90C30070 */ stw         r6, 0x70(r3)
  /* 8052E20C 88C40074 */ lbz         r6, 0x74(r4)
  /* 8052E210 98C30074 */ stb         r6, 0x74(r3)
  /* 8052E214 88C40075 */ lbz         r6, 0x75(r4)
  /* 8052E218 98C30075 */ stb         r6, 0x75(r3)
  /* 8052E21C 88C40076 */ lbz         r6, 0x76(r4)
  /* 8052E220 98C30076 */ stb         r6, 0x76(r3)
  /* 8052E224 88C40077 */ lbz         r6, 0x77(r4)
  /* 8052E228 98C30077 */ stb         r6, 0x77(r3)
  /* 8052E22C 80C40078 */ lwz         r6, 0x78(r4)
  /* 8052E230 90C30078 */ stw         r6, 0x78(r3)
  /* 8052E234 80C40080 */ lwz         r6, 0x80(r4)
  /* 8052E238 80E4007C */ lwz         r7, 0x7c(r4)
  /* 8052E23C 90E3007C */ stw         r7, 0x7c(r3)
  /* 8052E240 90C30080 */ stw         r6, 0x80(r3)
  /* 8052E244 80C40088 */ lwz         r6, 0x88(r4)
  /* 8052E248 80E40084 */ lwz         r7, 0x84(r4)
  /* 8052E24C 90E30084 */ stw         r7, 0x84(r3)
  /* 8052E250 90C30088 */ stw         r6, 0x88(r3)
  /* 8052E254 80C40090 */ lwz         r6, 0x90(r4)
  /* 8052E258 80E4008C */ lwz         r7, 0x8c(r4)
  /* 8052E25C 90E3008C */ stw         r7, 0x8c(r3)
  /* 8052E260 90C30090 */ stw         r6, 0x90(r3)
  /* 8052E264 80C40098 */ lwz         r6, 0x98(r4)
  /* 8052E268 80E40094 */ lwz         r7, 0x94(r4)
  /* 8052E26C 90E30094 */ stw         r7, 0x94(r3)
  /* 8052E270 90C30098 */ stw         r6, 0x98(r3)
  /* 8052E274 80C400A0 */ lwz         r6, 0xa0(r4)
  /* 8052E278 80E4009C */ lwz         r7, 0x9c(r4)
  /* 8052E27C 90E3009C */ stw         r7, 0x9c(r3)
  /* 8052E280 90C300A0 */ stw         r6, 0xa0(r3)
  /* 8052E284 80C400A8 */ lwz         r6, 0xa8(r4)
  /* 8052E288 80E400A4 */ lwz         r7, 0xa4(r4)
  /* 8052E28C 90E300A4 */ stw         r7, 0xa4(r3)
  /* 8052E290 90C300A8 */ stw         r6, 0xa8(r3)
  /* 8052E294 80C400B0 */ lwz         r6, 0xb0(r4)
  /* 8052E298 80E400AC */ lwz         r7, 0xac(r4)
  /* 8052E29C 90E300AC */ stw         r7, 0xac(r3)
  /* 8052E2A0 90C300B0 */ stw         r6, 0xb0(r3)
  /* 8052E2A4 80C400B4 */ lwz         r6, 0xb4(r4)
  /* 8052E2A8 90C300B4 */ stw         r6, 0xb4(r3)
  /* 8052E2AC 88C400B8 */ lbz         r6, 0xb8(r4)
  /* 8052E2B0 98C300B8 */ stb         r6, 0xb8(r3)
  /* 8052E2B4 88C400B9 */ lbz         r6, 0xb9(r4)
  /* 8052E2B8 98C300B9 */ stb         r6, 0xb9(r3)
  /* 8052E2BC 88C400BA */ lbz         r6, 0xba(r4)
  /* 8052E2C0 98C300BA */ stb         r6, 0xba(r3)
  /* 8052E2C4 80C400BC */ lwz         r6, 0xbc(r4)
  /* 8052E2C8 90C300BC */ stw         r6, 0xbc(r3)
  /* 8052E2CC 88C400C0 */ lbz         r6, 0xc0(r4)
  /* 8052E2D0 98C300C0 */ stb         r6, 0xc0(r3)
  /* 8052E2D4 88C400C1 */ lbz         r6, 0xc1(r4)
  /* 8052E2D8 98C300C1 */ stb         r6, 0xc1(r3)
  /* 8052E2DC 88C400C2 */ lbz         r6, 0xc2(r4)
  /* 8052E2E0 98C300C2 */ stb         r6, 0xc2(r3)
  /* 8052E2E4 80C400C4 */ lwz         r6, 0xc4(r4)
  /* 8052E2E8 90C300C4 */ stw         r6, 0xc4(r3)
  /* 8052E2EC 80C400C8 */ lwz         r6, 0xc8(r4)
  /* 8052E2F0 90C300C8 */ stw         r6, 0xc8(r3)
  /* 8052E2F4 80C400CC */ lwz         r6, 0xcc(r4)
  /* 8052E2F8 90C300CC */ stw         r6, 0xcc(r3)
  /* 8052E2FC 80C400D0 */ lwz         r6, 0xd0(r4)
  /* 8052E300 90C300D0 */ stw         r6, 0xd0(r3)
  /* 8052E304 80C400D4 */ lwz         r6, 0xd4(r4)
  /* 8052E308 90C300D4 */ stw         r6, 0xd4(r3)
  /* 8052E30C A0C400D8 */ lhz         r6, 0xd8(r4)
  /* 8052E310 B0C300D8 */ sth         r6, 0xd8(r3)
  /* 8052E314 A0C400DA */ lhz         r6, 0xda(r4)
  /* 8052E318 B0C300DA */ sth         r6, 0xda(r3)
  /* 8052E31C A0C400DC */ lhz         r6, 0xdc(r4)
  /* 8052E320 B0C300DC */ sth         r6, 0xdc(r3)
  /* 8052E324 A8C400DE */ lha         r6, 0xde(r4)
  /* 8052E328 B0C300DE */ sth         r6, 0xde(r3)
  /* 8052E32C 88C400E0 */ lbz         r6, 0xe0(r4)
  /* 8052E330 98C300E0 */ stb         r6, 0xe0(r3)
  /* 8052E334 88C400E1 */ lbz         r6, 0xe1(r4)
  /* 8052E338 98C300E1 */ stb         r6, 0xe1(r3)
  /* 8052E33C 88C400E2 */ lbz         r6, 0xe2(r4)
  /* 8052E340 98C300E2 */ stb         r6, 0xe2(r3)
  /* 8052E344 A0C400E8 */ lhz         r6, 0xe8(r4)
  /* 8052E348 B0C300E8 */ sth         r6, 0xe8(r3)
  /* 8052E34C 88C400EC */ lbz         r6, 0xec(r4)
  /* 8052E350 388400F0 */ addi        r4, r4, 0xf0
  /* 8052E354 98C300EC */ stb         r6, 0xec(r3)
  /* 8052E358 386300F0 */ addi        r3, r3, 0xf0
  /* 8052E35C 7C032840 */ cmplw       r3, r5
  /* 8052E360 4180FE34 */ blt+        lbl_8052e194
  /* 8052E364 82DF1758 */ lwz         r22, 0x1758(r31)
  /* 8052E368 3800000E */ li          r0, 0xe
  /* 8052E36C 82FF175C */ lwz         r23, 0x175c(r31)
  /* 8052E370 38BF0B98 */ addi        r5, r31, 0xb98
  /* 8052E374 831F1760 */ lwz         r24, 0x1760(r31)
  /* 8052E378 389F1788 */ addi        r4, r31, 0x1788
  /* 8052E37C 833F1764 */ lwz         r25, 0x1764(r31)
  /* 8052E380 835F1768 */ lwz         r26, 0x1768(r31)
  /* 8052E384 837F176C */ lwz         r27, 0x176c(r31)
  /* 8052E388 839F1770 */ lwz         r28, 0x1770(r31)
  /* 8052E38C 8BBF1774 */ lbz         r29, 0x1774(r31)
  /* 8052E390 8BDF1775 */ lbz         r30, 0x1775(r31)
  /* 8052E394 899F1776 */ lbz         r12, 0x1776(r31)
  /* 8052E398 897F1777 */ lbz         r11, 0x1777(r31)
  /* 8052E39C 815F1778 */ lwz         r10, 0x1778(r31)
  /* 8052E3A0 893F177C */ lbz         r9, 0x177c(r31)
  /* 8052E3A4 891F177D */ lbz         r8, 0x177d(r31)
  /* 8052E3A8 80FF1780 */ lwz         r7, 0x1780(r31)
  /* 8052E3AC 80DF1784 */ lwz         r6, 0x1784(r31)
  /* 8052E3B0 807F1788 */ lwz         r3, 0x1788(r31)
  /* 8052E3B4 92DF0B68 */ stw         r22, 0xb68(r31)
  /* 8052E3B8 92FF0B6C */ stw         r23, 0xb6c(r31)
  /* 8052E3BC 931F0B70 */ stw         r24, 0xb70(r31)
  /* 8052E3C0 933F0B74 */ stw         r25, 0xb74(r31)
  /* 8052E3C4 935F0B78 */ stw         r26, 0xb78(r31)
  /* 8052E3C8 937F0B7C */ stw         r27, 0xb7c(r31)
  /* 8052E3CC 939F0B80 */ stw         r28, 0xb80(r31)
  /* 8052E3D0 9BBF0B84 */ stb         r29, 0xb84(r31)
  /* 8052E3D4 9BDF0B85 */ stb         r30, 0xb85(r31)
  /* 8052E3D8 999F0B86 */ stb         r12, 0xb86(r31)
  /* 8052E3DC 997F0B87 */ stb         r11, 0xb87(r31)
  /* 8052E3E0 915F0B88 */ stw         r10, 0xb88(r31)
  /* 8052E3E4 993F0B8C */ stb         r9, 0xb8c(r31)
  /* 8052E3E8 991F0B8D */ stb         r8, 0xb8d(r31)
  /* 8052E3EC 90FF0B90 */ stw         r7, 0xb90(r31)
  /* 8052E3F0 90DF0B94 */ stw         r6, 0xb94(r31)
  /* 8052E3F4 907F0B98 */ stw         r3, 0xb98(r31)
  /* 8052E3F8 7C0903A6 */ mtctr       r0
  lbl_8052e3fc:
  /* 8052E3FC 80640004 */ lwz         r3, 4(r4)
  /* 8052E400 84040008 */ lwzu        r0, 8(r4)
  /* 8052E404 90650004 */ stw         r3, 4(r5)
  /* 8052E408 94050008 */ stwu        r0, 8(r5)
  /* 8052E40C 4200FFF0 */ bdnz        lbl_8052e3fc
  /* 8052E410 801F17FC */ lwz         r0, 0x17fc(r31)
  /* 8052E414 901F0C0C */ stw         r0, 0xc0c(r31)
  /* 8052E418 BAC10008 */ lmw         r22, 8(r1)
  /* 8052E41C 80010034 */ lwz         r0, 0x34(r1)
  /* 8052E420 7C0803A6 */ mtlr        r0
  /* 8052E424 38210030 */ addi        r1, r1, 0x30
  /* 8052E428 4E800020 */ blr
  // clang-format on
}

namespace System {

void RaceConfigPlayer::setCharacter(CharacterId character) {
  mCharacterId = character;
}

RaceConfigPlayer& RaceConfigScenario::getPlayer(u8 idx) {
  return mPlayers[idx];
}

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
    getPlayer(i).reset(i + 1);
  }

  mSettings.mRaceNumber = 0;
  mSettings.mLapCount = 3;
}

// 3 blr padding
void empty1() {}
void empty2() {}
void empty3() {}

u8 RaceConfigScenario::update() {
  if (mSettings.mRaceNumber < 100) {
    mSettings.mRaceNumber++;
  } else {
    mSettings.mRaceNumber = 0;
  }

  for (u8 i = 0; i < 12; i++) {
    RaceConfigPlayer& player = getPlayer(i);
    player.mPrevFinishPos = player.mFinishPos;
    player.mPreviousScore = player.mGpScore;
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

    RaceConfigPlayer& player =
        RaceConfig::spInstance->mRaceScenario.getPlayer(playerIdx);
    totalPoints += player.mRating.calcNegPoints(
        &RaceConfig::spInstance->mRaceScenario.getPlayer(i).mRating);
  }
  return totalPoints;
}

} // namespace System

// Symbol: unk_8052e950
// PAL: 0x8052e950..0x8052ed18
MARK_BINARY_BLOB(unk_8052e950, 0x8052e950, 0x8052ed18);
asm UNKNOWN_FUNCTION(unk_8052e950) {
  // clang-format off
  nofralloc
  /* 8052E950 9421FF70 */ stwu        r1, -0x90(r1)
  /* 8052E954 7C0802A6 */ mflr        r0
  /* 8052E958 90010094 */ stw         r0, 0x94(r1)
  /* 8052E95C DBE10080 */ stfd        f31, 0x80(r1)
  /* 8052E960 F3E10088 */ opword      0xf3e10088
  /* 8052E964 DBC10070 */ stfd        f30, 0x70(r1)
  /* 8052E968 F3C10078 */ opword      0xf3c10078
  /* 8052E96C 39610070 */ addi        r11, r1, 0x70
  /* 8052E970 4BAF2BFD */ bl          _savegpr_14
  /* 8052E974 80030B54 */ lwz         r0, 0xb54(r3)
  /* 8052E978 3EA0809C */ lis         r21, spInstance__Q26System10RaceConfig@ha
  /* 8052E97C 8095D728 */ lwz         r4, spInstance__Q26System10RaceConfig@l(r21)
  /* 8052E980 7C6F1B78 */ mr          r15, r3
  /* 8052E984 2C000000 */ cmpwi       r0, 0x0
  /* 8052E988 8AC40024 */ lbz         r22, 0x24(r4)
  /* 8052E98C 40820364 */ bne-        lbl_8052ecf0
  /* 8052E990 3816FFFF */ addi        r0, r22, -0x1
  /* 8052E994 3C608089 */ lis         r3, lbl_808900e0@ha
  /* 8052E998 1C00000C */ mulli       r0, r0, 0xc
  /* 8052E99C 3C808089 */ lis         r4, VS_POINT_DISTRIBUTION__6System@ha
  /* 8052E9A0 CBE300E0 */ lfd         f31, lbl_808900e0@l(r3)
  /* 8052E9A4 3A410008 */ addi        r18, r1, 0x8
  /* 8052E9A8 38840030 */ addi        r4, r4, VS_POINT_DISTRIBUTION__6System@l
  /* 8052E9AC 7E840214 */ add         r20, r4, r0
  /* 8052E9B0 3A200000 */ li          r17, 0x0
  /* 8052E9B4 3FC0809C */ lis         r30, lbl_809bd730@ha
  /* 8052E9B8 3BA00001 */ li          r29, 0x1
  /* 8052E9BC 3FE04330 */ lis         r31, 0x4330
  /* 8052E9C0 3B400000 */ li          r26, 0x0
  /* 8052E9C4 3DC08089 */ lis         r14, lbl_8088ffa8@ha
  /* 8052E9C8 48000284 */ b           lbl_8052ec4c
  lbl_8052e9cc:
  /* 8052E9CC 807ED730 */ lwz         r3, lbl_809bd730@l(r30)
  /* 8052E9D0 563315BA */ rlwinm      r19, r17, 2, 0x16, 0x1d
  /* 8052E9D4 80D5D728 */ lwz         r6, spInstance__Q26System10RaceConfig@l(r21)
  /* 8052E9D8 38800000 */ li          r4, 0x0
  /* 8052E9DC 80A3000C */ lwz         r5, 0xc(r3)
  /* 8052E9E0 80660B70 */ lwz         r3, 0xb70(r6)
  /* 8052E9E4 7CA5982E */ lwzx        r5, r5, r19
  /* 8052E9E8 3803FFFD */ addi        r0, r3, -0x3
  /* 8052E9EC 28000007 */ cmplwi      r0, 7
  /* 8052E9F0 8AE50020 */ lbz         r23, 0x20(r5)
  /* 8052E9F4 41810014 */ bgt-        lbl_8052ea08
  /* 8052E9F8 7FA00030 */ slw         r0, r29, r0
  /* 8052E9FC 700000C1 */ andi.       r0, r0, 0xc1
  /* 8052EA00 41820008 */ beq-        lbl_8052ea08
  /* 8052EA04 38800001 */ li          r4, 0x1
  lbl_8052ea08:
  /* 8052EA08 2C040000 */ cmpwi       r4, 0x0
  /* 8052EA0C 4182000C */ beq-        lbl_8052ea18
  /* 8052EA10 A3050022 */ lhz         r24, 0x22(r5)
  /* 8052EA14 48000008 */ b           lbl_8052ea1c
  lbl_8052ea18:
  /* 8052EA18 3B000000 */ li          r24, 0x0
  lbl_8052ea1c:
  /* 8052EA1C 806F0B50 */ lwz         r3, 0xb50(r15)
  /* 8052EA20 56390DFC */ rlwinm      r25, r17, 1, 0x17, 0x1e
  /* 8052EA24 7F52CB2E */ sthx        r26, r18, r25
  /* 8052EA28 38000000 */ li          r0, 0x0
  /* 8052EA2C 2C030007 */ cmpwi       r3, 0x7
  /* 8052EA30 41800010 */ blt-        lbl_8052ea40
  /* 8052EA34 2C03000A */ cmpwi       r3, 0xa
  /* 8052EA38 41810008 */ bgt-        lbl_8052ea40
  /* 8052EA3C 38000001 */ li          r0, 0x1
  lbl_8052ea40:
  /* 8052EA40 2C000000 */ cmpwi       r0, 0x0
  /* 8052EA44 418201A0 */ beq-        lbl_8052ebe4
  /* 8052EA48 563B063E */ clrlwi      r27, r17, 0x18
  /* 8052EA4C C3CEFFA8 */ lfs         f30, lbl_8088ffa8@l(r14)
  /* 8052EA50 1C1B00F0 */ mulli       r0, r27, 0xf0
  /* 8052EA54 3A000000 */ li          r16, 0x0
  /* 8052EA58 7F8F0214 */ add         r28, r15, r0
  /* 8052EA5C 48000124 */ b           lbl_8052eb80
  lbl_8052ea60:
  /* 8052EA60 5600063E */ clrlwi      r0, r16, 0x18
  /* 8052EA64 7C1B0040 */ cmplw       r27, r0
  /* 8052EA68 41820114 */ beq-        lbl_8052eb7c
  /* 8052EA6C 8095D728 */ lwz         r4, spInstance__Q26System10RaceConfig@l(r21)
  /* 8052EA70 38000000 */ li          r0, 0x0
  /* 8052EA74 38600000 */ li          r3, 0x0
  /* 8052EA78 38A00000 */ li          r5, 0x0
  /* 8052EA7C 80840B70 */ lwz         r4, 0xb70(r4)
  /* 8052EA80 3884FFFD */ addi        r4, r4, -0x3
  /* 8052EA84 28040007 */ cmplwi      r4, 7
  /* 8052EA88 41810014 */ bgt-        lbl_8052ea9c
  /* 8052EA8C 7FA42030 */ slw         r4, r29, r4
  /* 8052EA90 708400C1 */ andi.       r4, r4, 0xc1
  /* 8052EA94 41820008 */ beq-        lbl_8052ea9c
  /* 8052EA98 38A00001 */ li          r5, 0x1
  lbl_8052ea9c:
  /* 8052EA9C 2C050000 */ cmpwi       r5, 0x0
  /* 8052EAA0 41820034 */ beq-        lbl_8052ead4
  /* 8052EAA4 80BED730 */ lwz         r5, lbl_809bd730@l(r30)
  /* 8052EAA8 560415BA */ rlwinm      r4, r16, 2, 0x16, 0x1d
  /* 8052EAAC 80A5000C */ lwz         r5, 0xc(r5)
  /* 8052EAB0 7C85202E */ lwzx        r4, r5, r4
  /* 8052EAB4 A0840022 */ lhz         r4, 0x22(r4)
  /* 8052EAB8 7C182040 */ cmplw       r24, r4
  /* 8052EABC 4081000C */ ble-        lbl_8052eac8
  /* 8052EAC0 38000001 */ li          r0, 0x1
  /* 8052EAC4 4800003C */ b           lbl_8052eb00
  lbl_8052eac8:
  /* 8052EAC8 40800038 */ bge-        lbl_8052eb00
  /* 8052EACC 38600001 */ li          r3, 0x1
  /* 8052EAD0 48000030 */ b           lbl_8052eb00
  lbl_8052ead4:
  /* 8052EAD4 80BED730 */ lwz         r5, lbl_809bd730@l(r30)
  /* 8052EAD8 560415BA */ rlwinm      r4, r16, 2, 0x16, 0x1d
  /* 8052EADC 80A5000C */ lwz         r5, 0xc(r5)
  /* 8052EAE0 7C85202E */ lwzx        r4, r5, r4
  /* 8052EAE4 88840020 */ lbz         r4, 0x20(r4)
  /* 8052EAE8 7C172040 */ cmplw       r23, r4
  /* 8052EAEC 4080000C */ bge-        lbl_8052eaf8
  /* 8052EAF0 38000001 */ li          r0, 0x1
  /* 8052EAF4 4800000C */ b           lbl_8052eb00
  lbl_8052eaf8:
  /* 8052EAF8 40810008 */ ble-        lbl_8052eb00
  /* 8052EAFC 38600001 */ li          r3, 0x1
  lbl_8052eb00:
  /* 8052EB00 2C000000 */ cmpwi       r0, 0x0
  /* 8052EB04 4182003C */ beq-        lbl_8052eb40
  /* 8052EB08 5600063E */ clrlwi      r0, r16, 0x18
  /* 8052EB0C 387C00EC */ addi        r3, r28, 0xec
  /* 8052EB10 1C0000F0 */ mulli       r0, r0, 0xf0
  /* 8052EB14 7C8F0214 */ add         r4, r15, r0
  /* 8052EB18 388400EC */ addi        r4, r4, 0xec
  /* 8052EB1C 4BFFE5FD */ bl          unk_8052d118
  /* 8052EB20 7C600734 */ extsh       r0, r3
  /* 8052EB24 93E10020 */ stw         r31, 0x20(r1)
  /* 8052EB28 6C008000 */ xoris       r0, r0, 0x8000
  /* 8052EB2C 90010024 */ stw         r0, 0x24(r1)
  /* 8052EB30 C8010020 */ lfd         f0, 0x20(r1)
  /* 8052EB34 EC00F828 */ fsubs       f0, f0, f31
  /* 8052EB38 EFDE002A */ fadds       f30, f30, f0
  /* 8052EB3C 48000040 */ b           lbl_8052eb7c
  lbl_8052eb40:
  /* 8052EB40 2C030000 */ cmpwi       r3, 0x0
  /* 8052EB44 41820038 */ beq-        lbl_8052eb7c
  /* 8052EB48 5600063E */ clrlwi      r0, r16, 0x18
  /* 8052EB4C 387C00EC */ addi        r3, r28, 0xec
  /* 8052EB50 1C0000F0 */ mulli       r0, r0, 0xf0
  /* 8052EB54 7C8F0214 */ add         r4, r15, r0
  /* 8052EB58 388400EC */ addi        r4, r4, 0xec
  /* 8052EB5C 4BFFE665 */ bl          calcNegPoints__Q26System6RatingFPQ26System6Rating
  /* 8052EB60 7C600734 */ extsh       r0, r3
  /* 8052EB64 93E10020 */ stw         r31, 0x20(r1)
  /* 8052EB68 6C008000 */ xoris       r0, r0, 0x8000
  /* 8052EB6C 90010024 */ stw         r0, 0x24(r1)
  /* 8052EB70 C8010020 */ lfd         f0, 0x20(r1)
  /* 8052EB74 EC00F828 */ fsubs       f0, f0, f31
  /* 8052EB78 EFDE002A */ fadds       f30, f30, f0
  lbl_8052eb7c:
  /* 8052EB7C 3A100001 */ addi        r16, r16, 0x1
  lbl_8052eb80:
  /* 8052EB80 5600063E */ clrlwi      r0, r16, 0x18
  /* 8052EB84 7C00B040 */ cmplw       r0, r22
  /* 8052EB88 4180FED8 */ blt+        lbl_8052ea60
  /* 8052EB8C 8075D728 */ lwz         r3, spInstance__Q26System10RaceConfig@l(r21)
  /* 8052EB90 FC00F01E */ fctiwz      f0, f30
  /* 8052EB94 38800000 */ li          r4, 0x0
  /* 8052EB98 80630B70 */ lwz         r3, 0xb70(r3)
  /* 8052EB9C D8010020 */ stfd        f0, 0x20(r1)
  /* 8052EBA0 3803FFFD */ addi        r0, r3, -0x3
  /* 8052EBA4 28000007 */ cmplwi      r0, 7
  /* 8052EBA8 80610024 */ lwz         r3, 0x24(r1)
  /* 8052EBAC 41810014 */ bgt-        lbl_8052ebc0
  /* 8052EBB0 7FA00030 */ slw         r0, r29, r0
  /* 8052EBB4 700000C1 */ andi.       r0, r0, 0xc1
  /* 8052EBB8 41820008 */ beq-        lbl_8052ebc0
  /* 8052EBBC 38800001 */ li          r4, 0x1
  lbl_8052ebc0:
  /* 8052EBC0 2C040000 */ cmpwi       r4, 0x0
  /* 8052EBC4 4082001C */ bne-        lbl_8052ebe0
  /* 8052EBC8 28170001 */ cmplwi      r23, 1
  /* 8052EBCC 40820014 */ bne-        lbl_8052ebe0
  /* 8052EBD0 7C600734 */ extsh       r0, r3
  /* 8052EBD4 2C000001 */ cmpwi       r0, 0x1
  /* 8052EBD8 40800008 */ bge-        lbl_8052ebe0
  /* 8052EBDC 38600001 */ li          r3, 0x1
  lbl_8052ebe0:
  /* 8052EBE0 7C72CB2E */ sthx        r3, r18, r25
  lbl_8052ebe4:
  /* 8052EBE4 2C170000 */ cmpwi       r23, 0x0
  /* 8052EBE8 41820060 */ beq-        lbl_8052ec48
  /* 8052EBEC 2C160000 */ cmpwi       r22, 0x0
  /* 8052EBF0 41820058 */ beq-        lbl_8052ec48
  /* 8052EBF4 5620063E */ clrlwi      r0, r17, 0x18
  /* 8052EBF8 1C0000F0 */ mulli       r0, r0, 0xf0
  /* 8052EBFC 7C8F0214 */ add         r4, r15, r0
  /* 8052EC00 9AE400EA */ stb         r23, 0xea(r4)
  /* 8052EC04 800F0B50 */ lwz         r0, 0xb50(r15)
  /* 8052EC08 2C000009 */ cmpwi       r0, 0x9
  /* 8052EC0C 4180000C */ blt-        lbl_8052ec18
  /* 8052EC10 2C00000A */ cmpwi       r0, 0xa
  /* 8052EC14 4081000C */ ble-        lbl_8052ec20
  lbl_8052ec18:
  /* 8052EC18 2C000003 */ cmpwi       r0, 0x3
  /* 8052EC1C 40820018 */ bne-        lbl_8052ec34
  lbl_8052ec20:
  /* 8052EC20 807ED730 */ lwz         r3, lbl_809bd730@l(r30)
  /* 8052EC24 8063000C */ lwz         r3, 0xc(r3)
  /* 8052EC28 7C63982E */ lwzx        r3, r3, r19
  /* 8052EC2C A0630022 */ lhz         r3, 0x22(r3)
  /* 8052EC30 4800000C */ b           lbl_8052ec3c
  lbl_8052ec34:
  /* 8052EC34 7C74BA14 */ add         r3, r20, r23
  /* 8052EC38 8863FFFF */ lbz         r3, -1(r3)
  lbl_8052ec3c:
  /* 8052EC3C A00400E0 */ lhz         r0, 0xe0(r4)
  /* 8052EC40 7C001A14 */ add         r0, r0, r3
  /* 8052EC44 B00400E2 */ sth         r0, 0xe2(r4)
  lbl_8052ec48:
  /* 8052EC48 3A310001 */ addi        r17, r17, 0x1
  lbl_8052ec4c:
  /* 8052EC4C 5620063E */ clrlwi      r0, r17, 0x18
  /* 8052EC50 7C00B040 */ cmplw       r0, r22
  /* 8052EC54 4180FD78 */ blt+        lbl_8052e9cc
  /* 8052EC58 39C10008 */ addi        r14, r1, 0x8
  /* 8052EC5C 3A000000 */ li          r16, 0x0
  /* 8052EC60 48000024 */ b           lbl_8052ec84
  lbl_8052ec64:
  /* 8052EC64 5603063E */ clrlwi      r3, r16, 0x18
  /* 8052EC68 56000DFC */ rlwinm      r0, r16, 1, 0x17, 0x1e
  /* 8052EC6C 1C6300F0 */ mulli       r3, r3, 0xf0
  /* 8052EC70 7C8E02AE */ lhax        r4, r14, r0
  /* 8052EC74 7C6F1A14 */ add         r3, r15, r3
  /* 8052EC78 386300EC */ addi        r3, r3, 0xec
  /* 8052EC7C 4BFFE5F5 */ bl          unk_8052d270
  /* 8052EC80 3A100001 */ addi        r16, r16, 0x1
  lbl_8052ec84:
  /* 8052EC84 5600063E */ clrlwi      r0, r16, 0x18
  /* 8052EC88 7C00B040 */ cmplw       r0, r22
  /* 8052EC8C 4180FFD8 */ blt+        lbl_8052ec64
  /* 8052EC90 800F0B50 */ lwz         r0, 0xb50(r15)
  /* 8052EC94 2C000000 */ cmpwi       r0, 0x0
  /* 8052EC98 40820058 */ bne-        lbl_8052ecf0
  /* 8052EC9C 3C60809C */ lis         r3, lbl_809bd730@ha
  /* 8052ECA0 3A000000 */ li          r16, 0x0
  /* 8052ECA4 81E3D730 */ lwz         r15, lbl_809bd730@l(r3)
  /* 8052ECA8 3DC0809C */ lis         r14, spInstance__Q26System10RaceConfig@ha
  /* 8052ECAC 48000030 */ b           lbl_8052ecdc
  lbl_8052ecb0:
  /* 8052ECB0 5600063E */ clrlwi      r0, r16, 0x18
  /* 8052ECB4 1C0000F0 */ mulli       r0, r0, 0xf0
  /* 8052ECB8 7C640214 */ add         r3, r4, r0
  /* 8052ECBC 80030038 */ lwz         r0, 0x38(r3)
  /* 8052ECC0 2C000000 */ cmpwi       r0, 0x0
  /* 8052ECC4 40820014 */ bne-        lbl_8052ecd8
  /* 8052ECC8 806F000C */ lwz         r3, 0xc(r15)
  /* 8052ECCC 560015BA */ rlwinm      r0, r16, 2, 0x16, 0x1d
  /* 8052ECD0 7C63002E */ lwzx        r3, r3, r0
  /* 8052ECD4 48007C25 */ bl          RaceinfoPlayer_updateGpRankScore
  lbl_8052ecd8:
  /* 8052ECD8 3A100001 */ addi        r16, r16, 0x1
  lbl_8052ecdc:
  /* 8052ECDC 808ED728 */ lwz         r4, spInstance__Q26System10RaceConfig@l(r14)
  /* 8052ECE0 5603063E */ clrlwi      r3, r16, 0x18
  /* 8052ECE4 88040024 */ lbz         r0, 0x24(r4)
  /* 8052ECE8 7C030040 */ cmplw       r3, r0
  /* 8052ECEC 4180FFC4 */ blt+        lbl_8052ecb0
  lbl_8052ecf0:
  /* 8052ECF0 E3E10088 */ opword      0xe3e10088
  /* 8052ECF4 CBE10080 */ lfd         f31, 0x80(r1)
  /* 8052ECF8 E3C10078 */ opword      0xe3c10078
  /* 8052ECFC 39610070 */ addi        r11, r1, 0x70
  /* 8052ED00 CBC10070 */ lfd         f30, 0x70(r1)
  /* 8052ED04 4BAF28B5 */ bl          _restgpr_14
  /* 8052ED08 80010094 */ lwz         r0, 0x94(r1)
  /* 8052ED0C 7C0803A6 */ mtlr        r0
  /* 8052ED10 38210090 */ addi        r1, r1, 0x90
  /* 8052ED14 4E800020 */ blr
  // clang-format on
}

namespace System {

s32 RaceConfigScenario::getGametype() { return mSettings.mGameType; }

s32 RaceConfigPlayer::getPlayerType() { return mPlayerType; }

} // namespace System

// Symbol:
// postInitControllers__Q26System18RaceConfigScenarioFPQ26System18RaceConfigScenario
// PAL: 0x8052ed28..0x8052eef0
MARK_BINARY_BLOB(
    postInitControllers__Q26System18RaceConfigScenarioFPQ26System18RaceConfigScenario,
    0x8052ed28, 0x8052eef0);
asm UNKNOWN_FUNCTION(
    postInitControllers__Q26System18RaceConfigScenarioFPQ26System18RaceConfigScenario) {
  // clang-format off
  nofralloc
  /* 8052ED28 9421FFE0 */ stwu        r1, -0x20(r1)
  /* 8052ED2C 7C0802A6 */ mflr        r0
  /* 8052ED30 90010024 */ stw         r0, 0x24(r1)
  /* 8052ED34 93E1001C */ stw         r31, 0x1c(r1)
  /* 8052ED38 7C7F1B78 */ mr          r31, r3
  /* 8052ED3C 93C10018 */ stw         r30, 0x18(r1)
  /* 8052ED40 93A10014 */ stw         r29, 0x14(r1)
  /* 8052ED44 80030B54 */ lwz         r0, 0xb54(r3)
  /* 8052ED48 2C000005 */ cmpwi       r0, 0x5
  /* 8052ED4C 41820018 */ beq-        lbl_8052ed64
  /* 8052ED50 2C000000 */ cmpwi       r0, 0x0
  /* 8052ED54 41820058 */ beq-        lbl_8052edac
  /* 8052ED58 2C000001 */ cmpwi       r0, 0x1
  /* 8052ED5C 41820128 */ beq-        lbl_8052ee84
  /* 8052ED60 48000174 */ b           lbl_8052eed4
  lbl_8052ed64:
  /* 8052ED64 3BA00000 */ li          r29, 0x0
  /* 8052ED68 3FC0809C */ lis         r30, lbl_809bd70c@ha
  lbl_8052ed6c:
  /* 8052ED6C 57A0063E */ clrlwi      r0, r29, 0x18
  /* 8052ED70 1C0000F0 */ mulli       r0, r0, 0xf0
  /* 8052ED74 7C7F0214 */ add         r3, r31, r0
  /* 8052ED78 80030018 */ lwz         r0, 0x18(r3)
  /* 8052ED7C 2C000000 */ cmpwi       r0, 0x0
  /* 8052ED80 4082001C */ bne-        lbl_8052ed9c
  /* 8052ED84 8803000E */ lbz         r0, 0xe(r3)
  /* 8052ED88 7C000775 */ extsb.      r0, r0
  /* 8052ED8C 41800010 */ blt-        lbl_8052ed9c
  /* 8052ED90 807ED70C */ lwz         r3, lbl_809bd70c@l(r30)
  /* 8052ED94 5404063E */ clrlwi      r4, r0, 0x18
  /* 8052ED98 4BFF57C1 */ bl          unk_80524558
  lbl_8052ed9c:
  /* 8052ED9C 3BBD0001 */ addi        r29, r29, 0x1
  /* 8052EDA0 281D000C */ cmplwi      r29, 0xc
  /* 8052EDA4 4180FFC8 */ blt+        lbl_8052ed6c
  /* 8052EDA8 4800012C */ b           lbl_8052eed4
  lbl_8052edac:
  /* 8052EDAC 38000004 */ li          r0, 0x4
  /* 8052EDB0 38C00000 */ li          r6, 0x0
  /* 8052EDB4 3CA0809C */ lis         r5, lbl_809bd70c@ha
  /* 8052EDB8 7C0903A6 */ mtctr       r0
  lbl_8052edbc:
  /* 8052EDBC 54C0063E */ clrlwi      r0, r6, 0x18
  /* 8052EDC0 1C0000F0 */ mulli       r0, r0, 0xf0
  /* 8052EDC4 7C830214 */ add         r4, r3, r0
  /* 8052EDC8 80040018 */ lwz         r0, 0x18(r4)
  /* 8052EDCC 2C000000 */ cmpwi       r0, 0x0
  /* 8052EDD0 40820028 */ bne-        lbl_8052edf8
  /* 8052EDD4 8804000E */ lbz         r0, 0xe(r4)
  /* 8052EDD8 7C000775 */ extsb.      r0, r0
  /* 8052EDDC 4180001C */ blt-        lbl_8052edf8
  /* 8052EDE0 5400063E */ clrlwi      r0, r0, 0x18
  /* 8052EDE4 8085D70C */ lwz         r4, lbl_809bd70c@l(r5)
  /* 8052EDE8 1C0000EC */ mulli       r0, r0, 0xec
  /* 8052EDEC 7C840214 */ add         r4, r4, r0
  /* 8052EDF0 80040010 */ lwz         r0, 0x10(r4)
  /* 8052EDF4 90040008 */ stw         r0, 8(r4)
  lbl_8052edf8:
  /* 8052EDF8 38C60001 */ addi        r6, r6, 0x1
  /* 8052EDFC 54C0063E */ clrlwi      r0, r6, 0x18
  /* 8052EE00 1C0000F0 */ mulli       r0, r0, 0xf0
  /* 8052EE04 7C830214 */ add         r4, r3, r0
  /* 8052EE08 80040018 */ lwz         r0, 0x18(r4)
  /* 8052EE0C 2C000000 */ cmpwi       r0, 0x0
  /* 8052EE10 40820028 */ bne-        lbl_8052ee38
  /* 8052EE14 8804000E */ lbz         r0, 0xe(r4)
  /* 8052EE18 7C000775 */ extsb.      r0, r0
  /* 8052EE1C 4180001C */ blt-        lbl_8052ee38
  /* 8052EE20 5400063E */ clrlwi      r0, r0, 0x18
  /* 8052EE24 8085D70C */ lwz         r4, lbl_809bd70c@l(r5)
  /* 8052EE28 1C0000EC */ mulli       r0, r0, 0xec
  /* 8052EE2C 7C840214 */ add         r4, r4, r0
  /* 8052EE30 80040010 */ lwz         r0, 0x10(r4)
  /* 8052EE34 90040008 */ stw         r0, 8(r4)
  lbl_8052ee38:
  /* 8052EE38 38C60001 */ addi        r6, r6, 0x1
  /* 8052EE3C 54C0063E */ clrlwi      r0, r6, 0x18
  /* 8052EE40 1C0000F0 */ mulli       r0, r0, 0xf0
  /* 8052EE44 7C830214 */ add         r4, r3, r0
  /* 8052EE48 80040018 */ lwz         r0, 0x18(r4)
  /* 8052EE4C 2C000000 */ cmpwi       r0, 0x0
  /* 8052EE50 40820028 */ bne-        lbl_8052ee78
  /* 8052EE54 8804000E */ lbz         r0, 0xe(r4)
  /* 8052EE58 7C000775 */ extsb.      r0, r0
  /* 8052EE5C 4180001C */ blt-        lbl_8052ee78
  /* 8052EE60 5400063E */ clrlwi      r0, r0, 0x18
  /* 8052EE64 8085D70C */ lwz         r4, lbl_809bd70c@l(r5)
  /* 8052EE68 1C0000EC */ mulli       r0, r0, 0xec
  /* 8052EE6C 7C840214 */ add         r4, r4, r0
  /* 8052EE70 80040010 */ lwz         r0, 0x10(r4)
  /* 8052EE74 90040008 */ stw         r0, 8(r4)
  lbl_8052ee78:
  /* 8052EE78 38C60001 */ addi        r6, r6, 0x1
  /* 8052EE7C 4200FF40 */ bdnz        lbl_8052edbc
  /* 8052EE80 48000054 */ b           lbl_8052eed4
  lbl_8052ee84:
  /* 8052EE84 80040B54 */ lwz         r0, 0xb54(r4)
  /* 8052EE88 2C000000 */ cmpwi       r0, 0x0
  /* 8052EE8C 40820048 */ bne-        lbl_8052eed4
  /* 8052EE90 3BA00000 */ li          r29, 0x0
  /* 8052EE94 3FC0809C */ lis         r30, lbl_809bd70c@ha
  lbl_8052ee98:
  /* 8052EE98 57A0063E */ clrlwi      r0, r29, 0x18
  /* 8052EE9C 1C0000F0 */ mulli       r0, r0, 0xf0
  /* 8052EEA0 7C7F0214 */ add         r3, r31, r0
  /* 8052EEA4 80030018 */ lwz         r0, 0x18(r3)
  /* 8052EEA8 2C000000 */ cmpwi       r0, 0x0
  /* 8052EEAC 4082001C */ bne-        lbl_8052eec8
  /* 8052EEB0 8803000E */ lbz         r0, 0xe(r3)
  /* 8052EEB4 7C000775 */ extsb.      r0, r0
  /* 8052EEB8 41800010 */ blt-        lbl_8052eec8
  /* 8052EEBC 807ED70C */ lwz         r3, lbl_809bd70c@l(r30)
  /* 8052EEC0 5404063E */ clrlwi      r4, r0, 0x18
  /* 8052EEC4 4BFF563D */ bl          unk_80524500
  lbl_8052eec8:
  /* 8052EEC8 3BBD0001 */ addi        r29, r29, 0x1
  /* 8052EECC 281D000C */ cmplwi      r29, 0xc
  /* 8052EED0 4180FFC8 */ blt+        lbl_8052ee98
  lbl_8052eed4:
  /* 8052EED4 80010024 */ lwz         r0, 0x24(r1)
  /* 8052EED8 83E1001C */ lwz         r31, 0x1c(r1)
  /* 8052EEDC 83C10018 */ lwz         r30, 0x18(r1)
  /* 8052EEE0 83A10014 */ lwz         r29, 0x14(r1)
  /* 8052EEE4 7C0803A6 */ mtlr        r0
  /* 8052EEE8 38210020 */ addi        r1, r1, 0x20
  /* 8052EEEC 4E800020 */ blr
  // clang-format on
}

// This has never built due to GhostFile access problems
// This should give a rough idea of how the function works
#ifdef NON_MATCHING
namespace System {

bool RaceConfigScenario::initGhost(u8 playerIdx, u8 playerInputIdx) {
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
  nofralloc
  /* 8052EEF0 9421FF10 */ stwu        r1, -0xf0(r1)
  /* 8052EEF4 7C0802A6 */ mflr        r0
  /* 8052EEF8 900100F4 */ stw         r0, 0xf4(r1)
  /* 8052EEFC 93E100EC */ stw         r31, 0xec(r1)
  /* 8052EF00 3BE00000 */ li          r31, 0x0
  /* 8052EF04 93C100E8 */ stw         r30, 0xe8(r1)
  /* 8052EF08 7CBE2B78 */ mr          r30, r5
  /* 8052EF0C 93A100E4 */ stw         r29, 0xe4(r1)
  /* 8052EF10 7C9D2378 */ mr          r29, r4
  /* 8052EF14 938100E0 */ stw         r28, 0xe0(r1)
  /* 8052EF18 7C7C1B78 */ mr          r28, r3
  /* 8052EF1C 80630BEC */ lwz         r3, 0xbec(r3)
  /* 8052EF20 4BFED201 */ bl          isValid__Q26System12RawGhostFileCFv
  /* 8052EF24 2C030000 */ cmpwi       r3, 0x0
  /* 8052EF28 41820088 */ beq-        lbl_8052efb0
  /* 8052EF2C 38610008 */ addi        r3, r1, 0x8
  /* 8052EF30 4BFED341 */ bl          __ct__Q26System9GhostFileFv
  /* 8052EF34 809C0BEC */ lwz         r4, 0xbec(r28)
  /* 8052EF38 38610008 */ addi        r3, r1, 0x8
  /* 8052EF3C 4BFED855 */ bl          read__Q26System9GhostFileFRCQ26System12RawGhostFile
  /* 8052EF40 806100C0 */ lwz         r3, 0xc0(r1)
  /* 8052EF44 801C0B48 */ lwz         r0, 0xb48(r28)
  /* 8052EF48 7C030000 */ cmpw        r3, r0
  /* 8052EF4C 4082004C */ bne-        lbl_8052ef98
  /* 8052EF50 7FC00775 */ extsb.      r0, r30
  /* 8052EF54 4180001C */ blt-        lbl_8052ef70
  /* 8052EF58 3C60809C */ lis         r3, lbl_809bd70c@ha
  /* 8052EF5C 80A100DC */ lwz         r5, 0xdc(r1)
  /* 8052EF60 8063D70C */ lwz         r3, lbl_809bd70c@l(r3)
  /* 8052EF64 57C4063E */ clrlwi      r4, r30, 0x18
  /* 8052EF68 88C100D0 */ lbz         r6, 0xd0(r1)
  /* 8052EF6C 4BFF55D1 */ bl          InputMgr_setGhostController
  lbl_8052ef70:
  /* 8052EF70 1C7D00F0 */ mulli       r3, r29, 0xf0
  /* 8052EF74 800100B8 */ lwz         r0, 0xb8(r1)
  /* 8052EF78 3BE00001 */ li          r31, 0x1
  /* 8052EF7C 7C7C1A14 */ add         r3, r28, r3
  /* 8052EF80 90030014 */ stw         r0, 0x14(r3)
  /* 8052EF84 800100BC */ lwz         r0, 0xbc(r1)
  /* 8052EF88 90030010 */ stw         r0, 0x10(r3)
  /* 8052EF8C 9BC3000E */ stb         r30, 0xe(r3)
  /* 8052EF90 800100C4 */ lwz         r0, 0xc4(r1)
  /* 8052EF94 900300D8 */ stw         r0, 0xd8(r3)
  lbl_8052ef98:
  /* 8052EF98 3C808052 */ lis         r4, __dt__Q26System4TimeFv@ha
  /* 8052EF9C 38610070 */ addi        r3, r1, 0x70
  /* 8052EFA0 3884C334 */ addi        r4, r4, __dt__Q26System4TimeFv@l
  /* 8052EFA4 38A0000C */ li          r5, 0xc
  /* 8052EFA8 38C00005 */ li          r6, 0x5
  /* 8052EFAC 4BAF2141 */ bl          __destroy_arr
  lbl_8052efb0:
  /* 8052EFB0 7FE3FB78 */ mr          r3, r31
  /* 8052EFB4 83E100EC */ lwz         r31, 0xec(r1)
  /* 8052EFB8 83C100E8 */ lwz         r30, 0xe8(r1)
  /* 8052EFBC 83A100E4 */ lwz         r29, 0xe4(r1)
  /* 8052EFC0 838100E0 */ lwz         r28, 0xe0(r1)
  /* 8052EFC4 800100F4 */ lwz         r0, 0xf4(r1)
  /* 8052EFC8 7C0803A6 */ mtlr        r0
  /* 8052EFCC 382100F0 */ addi        r1, r1, 0xf0
  /* 8052EFD0 4E800020 */ blr
  // clang-format on
}

#endif

namespace System {

void RaceConfigScenario::resetPlayers() {
  for (u8 i = 0; i < 12; i++) {
    RaceConfigPlayer& player = getPlayer(i);
    player.mLocalPlayerNum = -1;
    player.mPlayerInputIdx = -1;
  }

  for (u8 i = 0; i < 4; i++) {
    mSettings.mHudPlayerIds[i] = -1;
  }
}

void RaceConfigScenario::initPlayers(u8 playerCount) {
  if (isOnline(mSettings.mGameMode)) {
    return;
  }
  for (u8 i = 0; i < playerCount; i++) {
    RaceConfigPlayer& player = getPlayer(i);
    player.mPreviousScore = 0;
    player.mPrevFinishPos = playerCount - i;
    player._e0 = playerCount - i;
  }
}

} // namespace System

// Symbol: copyPrevPositions__Q26System18RaceConfigScenarioFv
// PAL: 0x8052f1e0..0x8052f4e8
MARK_BINARY_BLOB(copyPrevPositions__Q26System18RaceConfigScenarioFv, 0x8052f1e0,
                 0x8052f4e8);
asm UNKNOWN_FUNCTION(copyPrevPositions__Q26System18RaceConfigScenarioFv) {
  // clang-format off
  nofralloc
  /* 8052F1E0 9421FFE0 */ stwu        r1, -0x20(r1)
  /* 8052F1E4 80030B50 */ lwz         r0, 0xb50(r3)
  /* 8052F1E8 2C000000 */ cmpwi       r0, 0x0
  /* 8052F1EC 4082003C */ bne-        lbl_8052f228
  /* 8052F1F0 88830B6C */ lbz         r4, 0xb6c(r3)
  /* 8052F1F4 28040004 */ cmplwi      r4, 4
  /* 8052F1F8 41810030 */ bgt-        lbl_8052f228
  /* 8052F1FC 80030B54 */ lwz         r0, 0xb54(r3)
  /* 8052F200 2C000001 */ cmpwi       r0, 0x1
  /* 8052F204 41820024 */ beq-        lbl_8052f228
  /* 8052F208 80030B68 */ lwz         r0, 0xb68(r3)
  /* 8052F20C 3CA08089 */ lis         r5, COURSE_ORDER__6System@ha
  /* 8052F210 38A5FFB0 */ addi        r5, r5, COURSE_ORDER__6System@l
  /* 8052F214 548415BA */ rlwinm      r4, r4, 2, 0x16, 0x1d
  /* 8052F218 54002036 */ slwi        r0, r0, 4
  /* 8052F21C 7C050214 */ add         r0, r5, r0
  /* 8052F220 7C04002E */ lwzx        r0, r4, r0
  /* 8052F224 90030B48 */ stw         r0, 0xb48(r3)
  lbl_8052f228:
  /* 8052F228 80830B50 */ lwz         r4, 0xb50(r3)
  /* 8052F22C 38000000 */ li          r0, 0x0
  /* 8052F230 2C040007 */ cmpwi       r4, 0x7
  /* 8052F234 41800010 */ blt-        lbl_8052f244
  /* 8052F238 2C04000A */ cmpwi       r4, 0xa
  /* 8052F23C 41810008 */ bgt-        lbl_8052f244
  /* 8052F240 38000001 */ li          r0, 0x1
  lbl_8052f244:
  /* 8052F244 2C000000 */ cmpwi       r0, 0x0
  /* 8052F248 41820298 */ beq-        lbl_8052f4e0
  /* 8052F24C 39600001 */ li          r11, 0x1
  /* 8052F250 39200002 */ li          r9, 0x2
  /* 8052F254 99210009 */ stb         r9, 9(r1)
  /* 8052F258 39000003 */ li          r8, 0x3
  /* 8052F25C 38E00004 */ li          r7, 0x4
  /* 8052F260 38C00005 */ li          r6, 0x5
  /* 8052F264 9901000A */ stb         r8, 0xa(r1)
  /* 8052F268 38800006 */ li          r4, 0x6
  /* 8052F26C 39400007 */ li          r10, 0x7
  /* 8052F270 39200008 */ li          r9, 0x8
  /* 8052F274 98E1000B */ stb         r7, 0xb(r1)
  /* 8052F278 39000009 */ li          r8, 0x9
  /* 8052F27C 38E0000A */ li          r7, 0xa
  /* 8052F280 38A10008 */ addi        r5, r1, 0x8
  /* 8052F284 98C1000C */ stb         r6, 0xc(r1)
  /* 8052F288 38C0000B */ li          r6, 0xb
  /* 8052F28C 39800001 */ li          r12, 0x1
  /* 8052F290 38000003 */ li          r0, 0x3
  /* 8052F294 9881000D */ stb         r4, 0xd(r1)
  /* 8052F298 3880000C */ li          r4, 0xc
  /* 8052F29C 99610008 */ stb         r11, 8(r1)
  /* 8052F2A0 9941000E */ stb         r10, 0xe(r1)
  /* 8052F2A4 9921000F */ stb         r9, 0xf(r1)
  /* 8052F2A8 99010010 */ stb         r8, 0x10(r1)
  /* 8052F2AC 98E10011 */ stb         r7, 0x11(r1)
  /* 8052F2B0 98C10012 */ stb         r6, 0x12(r1)
  /* 8052F2B4 98810013 */ stb         r4, 0x13(r1)
  lbl_8052f2b8:
  /* 8052F2B8 5587063E */ clrlwi      r7, r12, 0x18
  /* 8052F2BC 39200000 */ li          r9, 0x0
  /* 8052F2C0 7C0903A6 */ mtctr       r0
  lbl_8052f2c4:
  /* 8052F2C4 5524063E */ clrlwi      r4, r9, 0x18
  /* 8052F2C8 1CC400F0 */ mulli       r6, r4, 0xf0
  /* 8052F2CC 7CC33214 */ add         r6, r3, r6
  /* 8052F2D0 81060018 */ lwz         r8, 0x18(r6)
  /* 8052F2D4 2C080005 */ cmpwi       r8, 0x5
  /* 8052F2D8 41820018 */ beq-        lbl_8052f2f0
  /* 8052F2DC 88C600E9 */ lbz         r6, 0xe9(r6)
  /* 8052F2E0 7C073040 */ cmplw       r7, r6
  /* 8052F2E4 4082000C */ bne-        lbl_8052f2f0
  /* 8052F2E8 7D6521AE */ stbx        r11, r5, r4
  /* 8052F2EC 396B0001 */ addi        r11, r11, 0x1
  lbl_8052f2f0:
  /* 8052F2F0 39290001 */ addi        r9, r9, 0x1
  /* 8052F2F4 5524063E */ clrlwi      r4, r9, 0x18
  /* 8052F2F8 1CC400F0 */ mulli       r6, r4, 0xf0
  /* 8052F2FC 7CC33214 */ add         r6, r3, r6
  /* 8052F300 81060018 */ lwz         r8, 0x18(r6)
  /* 8052F304 2C080005 */ cmpwi       r8, 0x5
  /* 8052F308 41820018 */ beq-        lbl_8052f320
  /* 8052F30C 88C600E9 */ lbz         r6, 0xe9(r6)
  /* 8052F310 7C073040 */ cmplw       r7, r6
  /* 8052F314 4082000C */ bne-        lbl_8052f320
  /* 8052F318 7D6521AE */ stbx        r11, r5, r4
  /* 8052F31C 396B0001 */ addi        r11, r11, 0x1
  lbl_8052f320:
  /* 8052F320 39290001 */ addi        r9, r9, 0x1
  /* 8052F324 5524063E */ clrlwi      r4, r9, 0x18
  /* 8052F328 1CC400F0 */ mulli       r6, r4, 0xf0
  /* 8052F32C 7CC33214 */ add         r6, r3, r6
  /* 8052F330 81060018 */ lwz         r8, 0x18(r6)
  /* 8052F334 2C080005 */ cmpwi       r8, 0x5
  /* 8052F338 41820018 */ beq-        lbl_8052f350
  /* 8052F33C 88C600E9 */ lbz         r6, 0xe9(r6)
  /* 8052F340 7C073040 */ cmplw       r7, r6
  /* 8052F344 4082000C */ bne-        lbl_8052f350
  /* 8052F348 7D6521AE */ stbx        r11, r5, r4
  /* 8052F34C 396B0001 */ addi        r11, r11, 0x1
  lbl_8052f350:
  /* 8052F350 39290001 */ addi        r9, r9, 0x1
  /* 8052F354 5524063E */ clrlwi      r4, r9, 0x18
  /* 8052F358 1CC400F0 */ mulli       r6, r4, 0xf0
  /* 8052F35C 7CC33214 */ add         r6, r3, r6
  /* 8052F360 81060018 */ lwz         r8, 0x18(r6)
  /* 8052F364 2C080005 */ cmpwi       r8, 0x5
  /* 8052F368 41820018 */ beq-        lbl_8052f380
  /* 8052F36C 88C600E9 */ lbz         r6, 0xe9(r6)
  /* 8052F370 7C073040 */ cmplw       r7, r6
  /* 8052F374 4082000C */ bne-        lbl_8052f380
  /* 8052F378 7D6521AE */ stbx        r11, r5, r4
  /* 8052F37C 396B0001 */ addi        r11, r11, 0x1
  lbl_8052f380:
  /* 8052F380 39290001 */ addi        r9, r9, 0x1
  /* 8052F384 4200FF40 */ bdnz        lbl_8052f2c4
  /* 8052F388 398C0001 */ addi        r12, r12, 0x1
  /* 8052F38C 280C000C */ cmplwi      r12, 0xc
  /* 8052F390 4081FF28 */ ble+        lbl_8052f2b8
  /* 8052F394 38000003 */ li          r0, 0x3
  /* 8052F398 38810008 */ addi        r4, r1, 0x8
  /* 8052F39C 38E00000 */ li          r7, 0x0
  /* 8052F3A0 7C0903A6 */ mtctr       r0
  lbl_8052f3a4:
  /* 8052F3A4 54E0063E */ clrlwi      r0, r7, 0x18
  /* 8052F3A8 1CA000F0 */ mulli       r5, r0, 0xf0
  /* 8052F3AC 7CA32A14 */ add         r5, r3, r5
  /* 8052F3B0 80C50018 */ lwz         r6, 0x18(r5)
  /* 8052F3B4 2C060005 */ cmpwi       r6, 0x5
  /* 8052F3B8 41820018 */ beq-        lbl_8052f3d0
  /* 8052F3BC 88A500E9 */ lbz         r5, 0xe9(r5)
  /* 8052F3C0 2C050000 */ cmpwi       r5, 0x0
  /* 8052F3C4 4082000C */ bne-        lbl_8052f3d0
  /* 8052F3C8 7D6401AE */ stbx        r11, r4, r0
  /* 8052F3CC 396B0001 */ addi        r11, r11, 0x1
  lbl_8052f3d0:
  /* 8052F3D0 38E70001 */ addi        r7, r7, 0x1
  /* 8052F3D4 54E0063E */ clrlwi      r0, r7, 0x18
  /* 8052F3D8 1CA000F0 */ mulli       r5, r0, 0xf0
  /* 8052F3DC 7CA32A14 */ add         r5, r3, r5
  /* 8052F3E0 80C50018 */ lwz         r6, 0x18(r5)
  /* 8052F3E4 2C060005 */ cmpwi       r6, 0x5
  /* 8052F3E8 41820018 */ beq-        lbl_8052f400
  /* 8052F3EC 88A500E9 */ lbz         r5, 0xe9(r5)
  /* 8052F3F0 2C050000 */ cmpwi       r5, 0x0
  /* 8052F3F4 4082000C */ bne-        lbl_8052f400
  /* 8052F3F8 7D6401AE */ stbx        r11, r4, r0
  /* 8052F3FC 396B0001 */ addi        r11, r11, 0x1
  lbl_8052f400:
  /* 8052F400 38E70001 */ addi        r7, r7, 0x1
  /* 8052F404 54E0063E */ clrlwi      r0, r7, 0x18
  /* 8052F408 1CA000F0 */ mulli       r5, r0, 0xf0
  /* 8052F40C 7CA32A14 */ add         r5, r3, r5
  /* 8052F410 80C50018 */ lwz         r6, 0x18(r5)
  /* 8052F414 2C060005 */ cmpwi       r6, 0x5
  /* 8052F418 41820018 */ beq-        lbl_8052f430
  /* 8052F41C 88A500E9 */ lbz         r5, 0xe9(r5)
  /* 8052F420 2C050000 */ cmpwi       r5, 0x0
  /* 8052F424 4082000C */ bne-        lbl_8052f430
  /* 8052F428 7D6401AE */ stbx        r11, r4, r0
  /* 8052F42C 396B0001 */ addi        r11, r11, 0x1
  lbl_8052f430:
  /* 8052F430 38E70001 */ addi        r7, r7, 0x1
  /* 8052F434 54E0063E */ clrlwi      r0, r7, 0x18
  /* 8052F438 1CA000F0 */ mulli       r5, r0, 0xf0
  /* 8052F43C 7CA32A14 */ add         r5, r3, r5
  /* 8052F440 80C50018 */ lwz         r6, 0x18(r5)
  /* 8052F444 2C060005 */ cmpwi       r6, 0x5
  /* 8052F448 41820018 */ beq-        lbl_8052f460
  /* 8052F44C 88A500E9 */ lbz         r5, 0xe9(r5)
  /* 8052F450 2C050000 */ cmpwi       r5, 0x0
  /* 8052F454 4082000C */ bne-        lbl_8052f460
  /* 8052F458 7D6401AE */ stbx        r11, r4, r0
  /* 8052F45C 396B0001 */ addi        r11, r11, 0x1
  lbl_8052f460:
  /* 8052F460 38E70001 */ addi        r7, r7, 0x1
  /* 8052F464 4200FF40 */ bdnz        lbl_8052f3a4
  /* 8052F468 38000000 */ li          r0, 0x0
  /* 8052F46C 89010008 */ lbz         r8, 8(r1)
  /* 8052F470 1D4000F0 */ mulli       r10, r0, 0xf0
  /* 8052F474 88E10009 */ lbz         r7, 9(r1)
  /* 8052F478 88C1000A */ lbz         r6, 0xa(r1)
  /* 8052F47C 38000006 */ li          r0, 0x6
  /* 8052F480 88A1000B */ lbz         r5, 0xb(r1)
  /* 8052F484 7D235214 */ add         r9, r3, r10
  /* 8052F488 990900E9 */ stb         r8, 0xe9(r9)
  /* 8052F48C 1D4000F0 */ mulli       r10, r0, 0xf0
  /* 8052F490 8881000C */ lbz         r4, 0xc(r1)
  /* 8052F494 98E901D9 */ stb         r7, 0x1d9(r9)
  /* 8052F498 8801000D */ lbz         r0, 0xd(r1)
  /* 8052F49C 98C902C9 */ stb         r6, 0x2c9(r9)
  /* 8052F4A0 8901000E */ lbz         r8, 0xe(r1)
  /* 8052F4A4 98A903B9 */ stb         r5, 0x3b9(r9)
  /* 8052F4A8 88E1000F */ lbz         r7, 0xf(r1)
  /* 8052F4AC 988904A9 */ stb         r4, 0x4a9(r9)
  /* 8052F4B0 88C10010 */ lbz         r6, 0x10(r1)
  /* 8052F4B4 98090599 */ stb         r0, 0x599(r9)
  /* 8052F4B8 7D235214 */ add         r9, r3, r10
  /* 8052F4BC 88A10011 */ lbz         r5, 0x11(r1)
  /* 8052F4C0 990900E9 */ stb         r8, 0xe9(r9)
  /* 8052F4C4 88810012 */ lbz         r4, 0x12(r1)
  /* 8052F4C8 98E901D9 */ stb         r7, 0x1d9(r9)
  /* 8052F4CC 88010013 */ lbz         r0, 0x13(r1)
  /* 8052F4D0 98C902C9 */ stb         r6, 0x2c9(r9)
  /* 8052F4D4 98A903B9 */ stb         r5, 0x3b9(r9)
  /* 8052F4D8 988904A9 */ stb         r4, 0x4a9(r9)
  /* 8052F4DC 98090599 */ stb         r0, 0x599(r9)
  lbl_8052f4e0:
  /* 8052F4E0 38210020 */ addi        r1, r1, 0x20
  /* 8052F4E4 4E800020 */ blr
  // clang-format on
}

// Symbol: initControllers__Q26System18RaceConfigScenarioFUc
// PAL: 0x8052f4e8..0x8052f788
MARK_BINARY_BLOB(initControllers__Q26System18RaceConfigScenarioFUc, 0x8052f4e8,
                 0x8052f788);
asm UNKNOWN_FUNCTION(initControllers__Q26System18RaceConfigScenarioFUc) {
  // clang-format off
  nofralloc
  /* 8052F4E8 9421FEF0 */ stwu        r1, -0x110(r1)
  /* 8052F4EC 7C0802A6 */ mflr        r0
  /* 8052F4F0 90010114 */ stw         r0, 0x114(r1)
  /* 8052F4F4 BEA100E4 */ stmw        r21, 0xe4(r1)
  /* 8052F4F8 3BA0FFFF */ li          r29, -0x1
  /* 8052F4FC 7C781B78 */ mr          r24, r3
  /* 8052F500 7C992378 */ mr          r25, r4
  /* 8052F504 3B800000 */ li          r28, 0x0
  /* 8052F508 3B600000 */ li          r27, 0x0
  /* 8052F50C 3B400000 */ li          r26, 0x0
  /* 8052F510 3FE0809C */ lis         r31, lbl_809bd70c@ha
  /* 8052F514 3EC08052 */ lis         r22, __dt__Q26System4TimeFv@ha
  /* 8052F518 3AE00005 */ li          r23, 0x5
  /* 8052F51C 9BA30B64 */ stb         r29, 0xb64(r3)
  /* 8052F520 9BA30B65 */ stb         r29, 0xb65(r3)
  /* 8052F524 9BA30B66 */ stb         r29, 0xb66(r3)
  /* 8052F528 9BA30B67 */ stb         r29, 0xb67(r3)
  lbl_8052f52c:
  /* 8052F52C 5740063E */ clrlwi      r0, r26, 0x18
  /* 8052F530 1C0000F0 */ mulli       r0, r0, 0xf0
  /* 8052F534 7FD80214 */ add         r30, r24, r0
  /* 8052F538 801E0018 */ lwz         r0, 0x18(r30)
  /* 8052F53C 2C000000 */ cmpwi       r0, 0x0
  /* 8052F540 41820018 */ beq-        lbl_8052f558
  /* 8052F544 2C000003 */ cmpwi       r0, 0x3
  /* 8052F548 41820078 */ beq-        lbl_8052f5c0
  /* 8052F54C 2C000001 */ cmpwi       r0, 0x1
  /* 8052F550 41820114 */ beq-        lbl_8052f664
  /* 8052F554 48000114 */ b           lbl_8052f668
  lbl_8052f558:
  /* 8052F558 9B9E000D */ stb         r28, 0xd(r30)
  /* 8052F55C 5760063E */ clrlwi      r0, r27, 0x18
  /* 8052F560 1C0000EC */ mulli       r0, r0, 0xec
  /* 8052F564 9B7E000E */ stb         r27, 0xe(r30)
  /* 8052F568 807FD70C */ lwz         r3, lbl_809bd70c@l(r31)
  /* 8052F56C 7C630214 */ add         r3, r3, r0
  /* 8052F570 80630008 */ lwz         r3, 8(r3)
  /* 8052F574 2C030000 */ cmpwi       r3, 0x0
  /* 8052F578 41820018 */ beq-        lbl_8052f590
  /* 8052F57C 81830000 */ lwz         r12, 0(r3)
  /* 8052F580 818C0010 */ lwz         r12, 0x10(r12)
  /* 8052F584 7D8903A6 */ mtctr       r12
  /* 8052F588 4E800421 */ bctrl
  /* 8052F58C 48000008 */ b           lbl_8052f594
  lbl_8052f590:
  /* 8052F590 3860FFFF */ li          r3, -0x1
  lbl_8052f594:
  /* 8052F594 7F800774 */ extsb       r0, r28
  /* 8052F598 907E00D8 */ stw         r3, 0xd8(r30)
  /* 8052F59C 7C780214 */ add         r3, r24, r0
  /* 8052F5A0 88030B64 */ lbz         r0, 0xb64(r3)
  /* 8052F5A4 7C000774 */ extsb       r0, r0
  /* 8052F5A8 2C00FFFF */ cmpwi       r0, -0x1
  /* 8052F5AC 40820008 */ bne-        lbl_8052f5b4
  /* 8052F5B0 9B430B64 */ stb         r26, 0xb64(r3)
  lbl_8052f5b4:
  /* 8052F5B4 3B9C0001 */ addi        r28, r28, 0x1
  /* 8052F5B8 3B7B0001 */ addi        r27, r27, 0x1
  /* 8052F5BC 480000AC */ b           lbl_8052f668
  lbl_8052f5c0:
  /* 8052F5C0 80780BEC */ lwz         r3, 0xbec(r24)
  /* 8052F5C4 3AA00000 */ li          r21, 0x0
  /* 8052F5C8 4BFECB59 */ bl          isValid__Q26System12RawGhostFileCFv
  /* 8052F5CC 2C030000 */ cmpwi       r3, 0x0
  /* 8052F5D0 41820078 */ beq-        lbl_8052f648
  /* 8052F5D4 38610008 */ addi        r3, r1, 0x8
  /* 8052F5D8 4BFECC99 */ bl          __ct__Q26System9GhostFileFv
  /* 8052F5DC 80980BEC */ lwz         r4, 0xbec(r24)
  /* 8052F5E0 38610008 */ addi        r3, r1, 0x8
  /* 8052F5E4 4BFED1AD */ bl          read__Q26System9GhostFileFRCQ26System12RawGhostFile
  /* 8052F5E8 806100C0 */ lwz         r3, 0xc0(r1)
  /* 8052F5EC 80180B48 */ lwz         r0, 0xb48(r24)
  /* 8052F5F0 7C030000 */ cmpw        r3, r0
  /* 8052F5F4 40820040 */ bne-        lbl_8052f634
  /* 8052F5F8 7F600775 */ extsb.      r0, r27
  /* 8052F5FC 41800018 */ blt-        lbl_8052f614
  /* 8052F600 807FD70C */ lwz         r3, lbl_809bd70c@l(r31)
  /* 8052F604 5764063E */ clrlwi      r4, r27, 0x18
  /* 8052F608 80A100DC */ lwz         r5, 0xdc(r1)
  /* 8052F60C 88C100D0 */ lbz         r6, 0xd0(r1)
  /* 8052F610 4BFF4F2D */ bl          InputMgr_setGhostController
  lbl_8052f614:
  /* 8052F614 800100B8 */ lwz         r0, 0xb8(r1)
  /* 8052F618 3AA00001 */ li          r21, 0x1
  /* 8052F61C 901E0014 */ stw         r0, 0x14(r30)
  /* 8052F620 800100BC */ lwz         r0, 0xbc(r1)
  /* 8052F624 901E0010 */ stw         r0, 0x10(r30)
  /* 8052F628 9B7E000E */ stb         r27, 0xe(r30)
  /* 8052F62C 800100C4 */ lwz         r0, 0xc4(r1)
  /* 8052F630 901E00D8 */ stw         r0, 0xd8(r30)
  lbl_8052f634:
  /* 8052F634 38610070 */ addi        r3, r1, 0x70
  /* 8052F638 3896C334 */ addi        r4, r22, __dt__Q26System4TimeFv@l
  /* 8052F63C 38A0000C */ li          r5, 0xc
  /* 8052F640 38C00005 */ li          r6, 0x5
  /* 8052F644 4BAF1AA9 */ bl          __destroy_arr
  lbl_8052f648:
  /* 8052F648 2C150000 */ cmpwi       r21, 0x0
  /* 8052F64C 4182000C */ beq-        lbl_8052f658
  /* 8052F650 3B7B0001 */ addi        r27, r27, 0x1
  /* 8052F654 48000014 */ b           lbl_8052f668
  lbl_8052f658:
  /* 8052F658 92FE0018 */ stw         r23, 0x18(r30)
  /* 8052F65C 93BE00D8 */ stw         r29, 0xd8(r30)
  /* 8052F660 48000008 */ b           lbl_8052f668
  lbl_8052f664:
  /* 8052F664 93BE00D8 */ stw         r29, 0xd8(r30)
  lbl_8052f668:
  /* 8052F668 3B5A0001 */ addi        r26, r26, 0x1
  /* 8052F66C 281A000C */ cmplwi      r26, 0xc
  /* 8052F670 4180FEBC */ blt+        lbl_8052f52c
  /* 8052F674 7F800774 */ extsb       r0, r28
  /* 8052F678 7C00C800 */ cmpw        r0, r25
  /* 8052F67C 408000F8 */ bge-        lbl_8052f774
  /* 8052F680 38000004 */ li          r0, 0x4
  /* 8052F684 38A00000 */ li          r5, 0x0
  /* 8052F688 7C0903A6 */ mtctr       r0
  lbl_8052f68c:
  /* 8052F68C 54A0063E */ clrlwi      r0, r5, 0x18
  /* 8052F690 1C0000F0 */ mulli       r0, r0, 0xf0
  /* 8052F694 7C980214 */ add         r4, r24, r0
  /* 8052F698 80040018 */ lwz         r0, 0x18(r4)
  /* 8052F69C 2C000005 */ cmpwi       r0, 0x5
  /* 8052F6A0 41820034 */ beq-        lbl_8052f6d4
  /* 8052F6A4 8804000D */ lbz         r0, 0xd(r4)
  /* 8052F6A8 7C000774 */ extsb       r0, r0
  /* 8052F6AC 2C00FFFF */ cmpwi       r0, -0x1
  /* 8052F6B0 40820024 */ bne-        lbl_8052f6d4
  /* 8052F6B4 7F830774 */ extsb       r3, r28
  /* 8052F6B8 9B84000D */ stb         r28, 0xd(r4)
  /* 8052F6BC 3B9C0001 */ addi        r28, r28, 0x1
  /* 8052F6C0 7F800774 */ extsb       r0, r28
  /* 8052F6C4 7C781A14 */ add         r3, r24, r3
  /* 8052F6C8 7C00C800 */ cmpw        r0, r25
  /* 8052F6CC 98A30B64 */ stb         r5, 0xb64(r3)
  /* 8052F6D0 408000A4 */ bge-        lbl_8052f774
  lbl_8052f6d4:
  /* 8052F6D4 38A50001 */ addi        r5, r5, 0x1
  /* 8052F6D8 54A0063E */ clrlwi      r0, r5, 0x18
  /* 8052F6DC 1C0000F0 */ mulli       r0, r0, 0xf0
  /* 8052F6E0 7C980214 */ add         r4, r24, r0
  /* 8052F6E4 80040018 */ lwz         r0, 0x18(r4)
  /* 8052F6E8 2C000005 */ cmpwi       r0, 0x5
  /* 8052F6EC 41820034 */ beq-        lbl_8052f720
  /* 8052F6F0 8804000D */ lbz         r0, 0xd(r4)
  /* 8052F6F4 7C000774 */ extsb       r0, r0
  /* 8052F6F8 2C00FFFF */ cmpwi       r0, -0x1
  /* 8052F6FC 40820024 */ bne-        lbl_8052f720
  /* 8052F700 7F830774 */ extsb       r3, r28
  /* 8052F704 9B84000D */ stb         r28, 0xd(r4)
  /* 8052F708 3B9C0001 */ addi        r28, r28, 0x1
  /* 8052F70C 7F800774 */ extsb       r0, r28
  /* 8052F710 7C781A14 */ add         r3, r24, r3
  /* 8052F714 7C00C800 */ cmpw        r0, r25
  /* 8052F718 98A30B64 */ stb         r5, 0xb64(r3)
  /* 8052F71C 40800058 */ bge-        lbl_8052f774
  lbl_8052f720:
  /* 8052F720 38A50001 */ addi        r5, r5, 0x1
  /* 8052F724 54A0063E */ clrlwi      r0, r5, 0x18
  /* 8052F728 1C0000F0 */ mulli       r0, r0, 0xf0
  /* 8052F72C 7C980214 */ add         r4, r24, r0
  /* 8052F730 80040018 */ lwz         r0, 0x18(r4)
  /* 8052F734 2C000005 */ cmpwi       r0, 0x5
  /* 8052F738 41820034 */ beq-        lbl_8052f76c
  /* 8052F73C 8804000D */ lbz         r0, 0xd(r4)
  /* 8052F740 7C000774 */ extsb       r0, r0
  /* 8052F744 2C00FFFF */ cmpwi       r0, -0x1
  /* 8052F748 40820024 */ bne-        lbl_8052f76c
  /* 8052F74C 7F830774 */ extsb       r3, r28
  /* 8052F750 9B84000D */ stb         r28, 0xd(r4)
  /* 8052F754 3B9C0001 */ addi        r28, r28, 0x1
  /* 8052F758 7F800774 */ extsb       r0, r28
  /* 8052F75C 7C781A14 */ add         r3, r24, r3
  /* 8052F760 7C00C800 */ cmpw        r0, r25
  /* 8052F764 98A30B64 */ stb         r5, 0xb64(r3)
  /* 8052F768 4080000C */ bge-        lbl_8052f774
  lbl_8052f76c:
  /* 8052F76C 38A50001 */ addi        r5, r5, 0x1
  /* 8052F770 4200FF1C */ bdnz        lbl_8052f68c
  lbl_8052f774:
  /* 8052F774 BAA100E4 */ lmw         r21, 0xe4(r1)
  /* 8052F778 80010114 */ lwz         r0, 0x114(r1)
  /* 8052F77C 7C0803A6 */ mtlr        r0
  /* 8052F780 38210110 */ addi        r1, r1, 0x110
  /* 8052F784 4E800020 */ blr
  // clang-format on
}

namespace System {

void RaceConfigScenario::computePlayerCounts(u8& playerCount, u8& hudCount,
                                             u8& localPlayerCount) {
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

  playerCount = playerCount_;
  hudCount = hudCount_;
  localPlayerCount = localPlayerCount_;
}

void RaceConfigScenario::initRng() {
  u32 seed;
  u32 mask;
  u32 mask1;
  u32 mask2;
  u32 mask3;

  switch ((s32)(u32)mSettings.mGameMode) {
  case 2:
  case 4:
  case 5:
    mSettings.mSeed1 = 0x74a1b095;
    seed = OSGetTick();
    mask = (seed >> 27) & 0xFFFF;
    mask |= (seed >> 3) & 0x1FFF0000;
    mSettings.mSeed2 = mask;
    return;
  }

  if (mSettings.mModeFlags & 0x4) {
    mSettings.mSeed1 = 0x92bc7d03;
    seed = OSGetTick();
    mask = ((seed >> 27) & 0xFFFF);
    mask |= ((seed >> 3) & 0x1fff0000);
    mSettings.mSeed2 = mask;
    return;
  }

  if (mSettings.mGameType == 1) {
    return;
  }
  if (isOnline(mSettings.mGameMode)) {
    return;
  }

  seed = OSGetTick();
  mask = (seed >> 7) & 0xff000000;
  mask1 = (seed >> 20) & 0xff;
  mask2 = (seed >> 20) & 0x00ff0000;
  mask3 = (seed >> 7) & 0xff00;

  mSettings.mSeed1 = (seed >> 8) | (seed << 24);
  mSettings.mSeed2 = mask1 | mask2 | mask | mask3;
}

const s32 lbl_808900e8[15] = {-1, -1, -1, 5, 6, 8,         9,      11,
                              -1, -1, -1, 1, 2, 0xc030005, 0x40000};
const char lbl_80890124[2][0x12] = {"/boot/menuset.prm", "/boot/menuset.prm"};

void RaceConfigScenario::initCompetitionSettings() {
  CompetitionSettings settings; // 0x28-0x98
  memset(&settings, 0, sizeof(CompetitionSettings));
  CompetitionWrapper wrapper; // 0x8-0x24
  wrapper.isValid = false;
  wrapper.fileRaw = (u32) nullptr;
  // lbl_809c2144 is ptrNwc24Manager
  getCompetitionWrapper(lbl_809c2144, &wrapper);
  RawCompetitionFile* file = wrapper.fileRaw;

  // TODO: enum of competition type
  if (!((s32)file->competitionType != 0 && (s32)file->competitionType != 1)) {
    // there might have been a debug log here or something?/
    return;
  } else {
    settings.field1_0x2 = lbl_808900e8[file->competitionType];
    settings.courseId = file->courseId;
    settings.engineClass = file->engineClass;
    settings.controllerRestriction = file->controllerRestriction;
    settings.field7_0x30[0] = file->score;
    settings.field7_0x30[1] = file->score;
    settings.field7_0x30[2] = file->score;
    settings.field7_0x30[3] = file->score;
    settings.field7_0x30[4] = file->score;
    settings.field7_0x30[5] = file->score;
    settings.cameraAngle = file->cameraAngle;
    settings.minimapObject = file->minimapObject;
    settings.field10_0x4c = file->field13_0x20;
    settings.field11_0x4e = file->field14_0x22;
    settings.cannonFlag = file->cannonFlag;
    settings.cpuCount = file->getSize();

    settings.cpuCombosFromWrapper(wrapper);

#ifdef __CWCC__
    __memcpy(&mCompetitionSettings, &settings, sizeof(settings));
#else
    memcpy(&mCompetitionSettings, &settings, sizeof(settings));
#endif
  }
}

void RaceConfigScenario::initRace(RaceConfigScenario* raceScenario) {
  u8 playerCount = 0;
  u8 hudCount = 0;
  u8 localPlayerCount = 0;

  if (mSettings.mModeFlags & 4) {
    this->initCompetitionSettings();
  }

  copyPrevPositions();

  for (u8 i = 0; i < 12; i++) {
    RaceConfigPlayer& player = getPlayer(i);
    player.mLocalPlayerNum = -1;
    player.mPlayerInputIdx = -1;
  }

  for (u8 i = 0; i < 4; i++) {
    mSettings.mHudPlayerIds[i] = -1;
  }

  computePlayerCounts(playerCount, hudCount, localPlayerCount);

  u8 hudCount_ = hudCount;
  if (mSettings.mGameType == 5) {
    hudCount = 1;
  }

  if (mSettings.mRaceNumber == 0) {
    u8 playerCount_ = playerCount;
    if (!isOnline(mSettings.mGameMode)) {
      for (u8 i = 0; i < playerCount_; i++) {
        RaceConfigPlayer& player = getPlayer(i);
        player.mPreviousScore = 0;
        player.mPrevFinishPos = playerCount_ - i;
        player._e0 = playerCount_ - i;
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
MARK_BINARY_BLOB(Racedata_initStaticInstance, 0x8052fe58, 0x8052ffe8);
asm UNKNOWN_FUNCTION(Racedata_initStaticInstance) {
  // clang-format off
  nofralloc
  /* 8052FE58 9421FFE0 */ stwu        r1, -0x20(r1)
  /* 8052FE5C 7C0802A6 */ mflr        r0
  /* 8052FE60 3C60809C */ lis         r3, spInstance__Q26System10RaceConfig@ha
  /* 8052FE64 90010024 */ stw         r0, 0x24(r1)
  /* 8052FE68 BF410008 */ stmw        r26, 8(r1)
  /* 8052FE6C 8003D728 */ lwz         r0, spInstance__Q26System10RaceConfig@l(r3)
  /* 8052FE70 2C000000 */ cmpwi       r0, 0x0
  /* 8052FE74 40820158 */ bne-        lbl_8052ffcc
  /* 8052FE78 386073F0 */ li          r3, 0x73f0
  /* 8052FE7C 4BCF9F51 */ bl          __nw__FUl
  /* 8052FE80 2C030000 */ cmpwi       r3, 0x0
  /* 8052FE84 7C7A1B78 */ mr          r26, r3
  /* 8052FE88 4182013C */ beq-        lbl_8052ffc4
  /* 8052FE8C 3C808089 */ lis         r4, lbl_80890124@ha
  /* 8052FE90 38A00000 */ li          r5, 0x0
  /* 8052FE94 38840124 */ addi        r4, r4, lbl_80890124@l
  /* 8052FE98 4BAD9DF5 */ bl          __ct__Q26System13ParameterFileFPCcUl
  /* 8052FE9C 3C60808B */ lis         r3, __vt__Q26System10RaceConfig@ha
  /* 8052FEA0 3F60808B */ lis         r27, __vt__Q26System18RaceConfigScenario@ha
  /* 8052FEA4 38633260 */ addi        r3, r3, __vt__Q26System10RaceConfig@l
  /* 8052FEA8 907A001C */ stw         r3, 0x1c(r26)
  /* 8052FEAC 38030008 */ addi        r0, r3, 0x8
  /* 8052FEB0 3FA08053 */ lis         r29, __ct__Q26System16RaceConfigPlayerFv@ha
  /* 8052FEB4 901A0000 */ stw         r0, 0(r26)
  /* 8052FEB8 3B7B3288 */ addi        r27, r27, __vt__Q26System18RaceConfigScenario@l
  /* 8052FEBC 3FC08053 */ lis         r30, __dt__Q26System16RaceConfigPlayerFv@ha
  /* 8052FEC0 3B800000 */ li          r28, 0x0
  /* 8052FEC4 937A0020 */ stw         r27, 0x20(r26)
  /* 8052FEC8 387A0028 */ addi        r3, r26, 0x28
  /* 8052FECC 389DD96C */ addi        r4, r29, __ct__Q26System16RaceConfigPlayerFv@l
  /* 8052FED0 38BEDC68 */ addi        r5, r30, __dt__Q26System16RaceConfigPlayerFv@l
  /* 8052FED4 9B9A0024 */ stb         r28, 0x24(r26)
  /* 8052FED8 38C000F0 */ li          r6, 0xf0
  /* 8052FEDC 38E0000C */ li          r7, 0xc
  /* 8052FEE0 9B9A0025 */ stb         r28, 0x25(r26)
  /* 8052FEE4 4BAF1111 */ bl          __construct_array
  /* 8052FEE8 3BE00011 */ li          r31, 0x11
  /* 8052FEEC 93FA0B68 */ stw         r31, 0xb68(r26)
  /* 8052FEF0 387A0B9C */ addi        r3, r26, 0xb9c
  /* 8052FEF4 38800000 */ li          r4, 0x0
  /* 8052FEF8 939A0B70 */ stw         r28, 0xb70(r26)
  /* 8052FEFC 38A00070 */ li          r5, 0x70
  /* 8052FF00 939A0B74 */ stw         r28, 0xb74(r26)
  /* 8052FF04 939A0B88 */ stw         r28, 0xb88(r26)
  /* 8052FF08 4BAD6131 */ bl          memset
  /* 8052FF0C 381A23F0 */ addi        r0, r26, 0x23f0
  /* 8052FF10 901A0C0C */ stw         r0, 0xc0c(r26)
  /* 8052FF14 387A0C18 */ addi        r3, r26, 0xc18
  /* 8052FF18 389DD96C */ addi        r4, r29, __ct__Q26System16RaceConfigPlayerFv@l
  /* 8052FF1C 937A0C10 */ stw         r27, 0xc10(r26)
  /* 8052FF20 38BEDC68 */ addi        r5, r30, __dt__Q26System16RaceConfigPlayerFv@l
  /* 8052FF24 38C000F0 */ li          r6, 0xf0
  /* 8052FF28 38E0000C */ li          r7, 0xc
  /* 8052FF2C 9B9A0C14 */ stb         r28, 0xc14(r26)
  /* 8052FF30 9B9A0C15 */ stb         r28, 0xc15(r26)
  /* 8052FF34 4BAF10C1 */ bl          __construct_array
  /* 8052FF38 93FA1758 */ stw         r31, 0x1758(r26)
  /* 8052FF3C 387A178C */ addi        r3, r26, 0x178c
  /* 8052FF40 38800000 */ li          r4, 0x0
  /* 8052FF44 38A00070 */ li          r5, 0x70
  /* 8052FF48 939A1760 */ stw         r28, 0x1760(r26)
  /* 8052FF4C 939A1764 */ stw         r28, 0x1764(r26)
  /* 8052FF50 939A1778 */ stw         r28, 0x1778(r26)
  /* 8052FF54 4BAD60E5 */ bl          memset
  /* 8052FF58 381A4BF0 */ addi        r0, r26, 0x4bf0
  /* 8052FF5C 901A17FC */ stw         r0, 0x17fc(r26)
  /* 8052FF60 387A1808 */ addi        r3, r26, 0x1808
  /* 8052FF64 389DD96C */ addi        r4, r29, __ct__Q26System16RaceConfigPlayerFv@l
  /* 8052FF68 937A1800 */ stw         r27, 0x1800(r26)
  /* 8052FF6C 38BEDC68 */ addi        r5, r30, __dt__Q26System16RaceConfigPlayerFv@l
  /* 8052FF70 38C000F0 */ li          r6, 0xf0
  /* 8052FF74 38E0000C */ li          r7, 0xc
  /* 8052FF78 9B9A1804 */ stb         r28, 0x1804(r26)
  /* 8052FF7C 9B9A1805 */ stb         r28, 0x1805(r26)
  /* 8052FF80 4BAF1075 */ bl          __construct_array
  /* 8052FF84 93FA2348 */ stw         r31, 0x2348(r26)
  /* 8052FF88 387A237C */ addi        r3, r26, 0x237c
  /* 8052FF8C 38800000 */ li          r4, 0x0
  /* 8052FF90 38A00070 */ li          r5, 0x70
  /* 8052FF94 939A2350 */ stw         r28, 0x2350(r26)
  /* 8052FF98 939A2354 */ stw         r28, 0x2354(r26)
  /* 8052FF9C 939A2368 */ stw         r28, 0x2368(r26)
  /* 8052FFA0 4BAD6099 */ bl          memset
  /* 8052FFA4 939A23EC */ stw         r28, 0x23ec(r26)
  /* 8052FFA8 3B7A23F0 */ addi        r27, r26, 0x23f0
  /* 8052FFAC 3BFA73F0 */ addi        r31, r26, 0x73f0
  lbl_8052ffb0:
  /* 8052FFB0 7F63DB78 */ mr          r3, r27
  /* 8052FFB4 4BFEC0D5 */ bl          reset__Q26System12RawGhostFileFv
  /* 8052FFB8 3B7B2800 */ addi        r27, r27, 0x2800
  /* 8052FFBC 7C1BF840 */ cmplw       r27, r31
  /* 8052FFC0 4180FFF0 */ blt+        lbl_8052ffb0
  lbl_8052ffc4:
  /* 8052FFC4 3C60809C */ lis         r3, spInstance__Q26System10RaceConfig@ha
  /* 8052FFC8 9343D728 */ stw         r26, spInstance__Q26System10RaceConfig@l(r3)
  lbl_8052ffcc:
  /* 8052FFCC BB410008 */ lmw         r26, 8(r1)
  /* 8052FFD0 3C60809C */ lis         r3, spInstance__Q26System10RaceConfig@ha
  /* 8052FFD4 80010024 */ lwz         r0, 0x24(r1)
  /* 8052FFD8 8063D728 */ lwz         r3, spInstance__Q26System10RaceConfig@l(r3)
  /* 8052FFDC 7C0803A6 */ mtlr        r0
  /* 8052FFE0 38210020 */ addi        r1, r1, 0x20
  /* 8052FFE4 4E800020 */ blr
  // clang-format on
}

// Symbol: Racedata_destroyStaticInstance
// PAL: 0x8052ffe8..0x80530038
MARK_BINARY_BLOB(Racedata_destroyStaticInstance, 0x8052ffe8, 0x80530038);
asm UNKNOWN_FUNCTION(Racedata_destroyStaticInstance) {
  // clang-format off
  nofralloc
  /* 8052FFE8 9421FFF0 */ stwu        r1, -0x10(r1)
  /* 8052FFEC 7C0802A6 */ mflr        r0
  /* 8052FFF0 3C60809C */ lis         r3, spInstance__Q26System10RaceConfig@ha
  /* 8052FFF4 90010014 */ stw         r0, 0x14(r1)
  /* 8052FFF8 8063D728 */ lwz         r3, spInstance__Q26System10RaceConfig@l(r3)
  /* 8052FFFC 2C030000 */ cmpwi       r3, 0x0
  /* 80530000 4182001C */ beq-        lbl_8053001c
  /* 80530004 41820018 */ beq-        lbl_8053001c
  /* 80530008 8183001C */ lwz         r12, 0x1c(r3)
  /* 8053000C 38800001 */ li          r4, 0x1
  /* 80530010 818C0024 */ lwz         r12, 0x24(r12)
  /* 80530014 7D8903A6 */ mtctr       r12
  /* 80530018 4E800421 */ bctrl
  lbl_8053001c:
  /* 8053001C 3C60809C */ lis         r3, spInstance__Q26System10RaceConfig@ha
  /* 80530020 38000000 */ li          r0, 0x0
  /* 80530024 9003D728 */ stw         r0, spInstance__Q26System10RaceConfig@l(r3)
  /* 80530028 80010014 */ lwz         r0, 0x14(r1)
  /* 8053002C 7C0803A6 */ mtlr        r0
  /* 80530030 38210010 */ addi        r1, r1, 0x10
  /* 80530034 4E800020 */ blr
  // clang-format on
}

namespace System {
RaceConfig::~RaceConfig() {}

RaceConfigScenario::~RaceConfigScenario() {}

RaceConfig::RaceConfig()
    : ParameterFile(lbl_80890124[1], 0), mRaceScenario(&mGhosts[0]),
      mMenuScenario(&mGhosts[1]), mAwardsScenario(nullptr) {
  RawGhostFile* it = mGhosts;
  do {
    it->reset();
    it++;
  } while (it < mGhosts + 2);
}

#pragma legacy_struct_alignment on
void RaceConfig::initRace() {
  mMenuScenario.initRace(&mRaceScenario);
  mRaceScenario = mMenuScenario;
}

} // namespace System

#ifdef EQUIVALENT
// regswap r5, r6
#pragma push
#pragma legacy_struct_alignment on
namespace System {
RaceConfigScenario& RaceConfigScenario::copy(const RaceConfigScenario& other) {
  *this = other;
  return *this;
}
/*
RaceConfigScenario& RaceConfigScenario::operator=(const RaceConfigScenario&
other) { this->mPlayerCount = other.mPlayerCount; this->mHudCount =
other.mHudCount; this->mLocalPlayerCount = other.mLocalPlayerCount;
  this->mHudCount2 = other.mHudCount2;
  for (int i = 0; i < MAX_PLAYER_COUNT; i++) {
    mPlayers[i] = other.mPlayers[i];
  }
  mSettings = other.mSettings;
  for (int i = 0; i < sizeof(_b7c)/sizeof(unk32); i++) {
    _b7c[i] = other._b7c[i];
  }
  mGhost = other.mGhost;
  return *this;
}
*/
} // namespace System
#pragma pop
#else
// Symbol: RacedataScenario_copy
// PAL: 0x805305ac..0x80530864
MARK_BINARY_BLOB(RacedataScenario_copy, 0x805305ac, 0x80530864);
asm UNKNOWN_FUNCTION(RacedataScenario_copy) {
  // clang-format off
  nofralloc
  /* 805305AC 88040004 */ lbz         r0, 4(r4)
  /* 805305B0 38A30008 */ addi        r5, r3, 0x8
  /* 805305B4 98030004 */ stb         r0, 4(r3)
  /* 805305B8 38C40008 */ addi        r6, r4, 0x8
  /* 805305BC 38E30B48 */ addi        r7, r3, 0xb48
  /* 805305C0 38000026 */ li          r0, 0x26
  /* 805305C4 89040005 */ lbz         r8, 5(r4)
  /* 805305C8 99030005 */ stb         r8, 5(r3)
  /* 805305CC 89040006 */ lbz         r8, 6(r4)
  /* 805305D0 99030006 */ stb         r8, 6(r3)
  /* 805305D4 89040007 */ lbz         r8, 7(r4)
  /* 805305D8 99030007 */ stb         r8, 7(r3)
  lbl_805305dc:
  /* 805305DC 89060004 */ lbz         r8, 4(r6)
  /* 805305E0 39650023 */ addi        r11, r5, 0x23
  /* 805305E4 99050004 */ stb         r8, 4(r5)
  /* 805305E8 39460023 */ addi        r10, r6, 0x23
  /* 805305EC 89060005 */ lbz         r8, 5(r6)
  /* 805305F0 99050005 */ stb         r8, 5(r5)
  /* 805305F4 89060006 */ lbz         r8, 6(r6)
  /* 805305F8 99050006 */ stb         r8, 6(r5)
  /* 805305FC 81060008 */ lwz         r8, 8(r6)
  /* 80530600 91050008 */ stw         r8, 8(r5)
  /* 80530604 8106000C */ lwz         r8, 0xc(r6)
  /* 80530608 9105000C */ stw         r8, 0xc(r5)
  /* 8053060C 81060010 */ lwz         r8, 0x10(r6)
  /* 80530610 91050010 */ stw         r8, 0x10(r5)
  /* 80530614 81060018 */ lwz         r8, 0x18(r6)
  /* 80530618 91050018 */ stw         r8, 0x18(r5)
  /* 8053061C 8906001C */ lbz         r8, 0x1c(r6)
  /* 80530620 9905001C */ stb         r8, 0x1c(r5)
  /* 80530624 8906001D */ lbz         r8, 0x1d(r6)
  /* 80530628 9905001D */ stb         r8, 0x1d(r5)
  /* 8053062C 81060020 */ lwz         r8, 0x20(r6)
  /* 80530630 91050020 */ stw         r8, 0x20(r5)
  /* 80530634 7C0903A6 */ mtctr       r0
  lbl_80530638:
  /* 80530638 892A0001 */ lbz         r9, 1(r10)
  /* 8053063C 8D0A0002 */ lbzu        r8, 2(r10)
  /* 80530640 992B0001 */ stb         r9, 1(r11)
  /* 80530644 9D0B0002 */ stbu        r8, 2(r11)
  /* 80530648 4200FFF0 */ bdnz        lbl_80530638
  /* 8053064C 81060070 */ lwz         r8, 0x70(r6)
  /* 80530650 91050070 */ stw         r8, 0x70(r5)
  /* 80530654 89060074 */ lbz         r8, 0x74(r6)
  /* 80530658 99050074 */ stb         r8, 0x74(r5)
  /* 8053065C 89060075 */ lbz         r8, 0x75(r6)
  /* 80530660 99050075 */ stb         r8, 0x75(r5)
  /* 80530664 89060076 */ lbz         r8, 0x76(r6)
  /* 80530668 99050076 */ stb         r8, 0x76(r5)
  /* 8053066C 89060077 */ lbz         r8, 0x77(r6)
  /* 80530670 99050077 */ stb         r8, 0x77(r5)
  /* 80530674 81060078 */ lwz         r8, 0x78(r6)
  /* 80530678 91050078 */ stw         r8, 0x78(r5)
  /* 8053067C 81060080 */ lwz         r8, 0x80(r6)
  /* 80530680 8126007C */ lwz         r9, 0x7c(r6)
  /* 80530684 9125007C */ stw         r9, 0x7c(r5)
  /* 80530688 91050080 */ stw         r8, 0x80(r5)
  /* 8053068C 81060088 */ lwz         r8, 0x88(r6)
  /* 80530690 81260084 */ lwz         r9, 0x84(r6)
  /* 80530694 91250084 */ stw         r9, 0x84(r5)
  /* 80530698 91050088 */ stw         r8, 0x88(r5)
  /* 8053069C 81060090 */ lwz         r8, 0x90(r6)
  /* 805306A0 8126008C */ lwz         r9, 0x8c(r6)
  /* 805306A4 9125008C */ stw         r9, 0x8c(r5)
  /* 805306A8 91050090 */ stw         r8, 0x90(r5)
  /* 805306AC 81060098 */ lwz         r8, 0x98(r6)
  /* 805306B0 81260094 */ lwz         r9, 0x94(r6)
  /* 805306B4 91250094 */ stw         r9, 0x94(r5)
  /* 805306B8 91050098 */ stw         r8, 0x98(r5)
  /* 805306BC 810600A0 */ lwz         r8, 0xa0(r6)
  /* 805306C0 8126009C */ lwz         r9, 0x9c(r6)
  /* 805306C4 9125009C */ stw         r9, 0x9c(r5)
  /* 805306C8 910500A0 */ stw         r8, 0xa0(r5)
  /* 805306CC 810600A8 */ lwz         r8, 0xa8(r6)
  /* 805306D0 812600A4 */ lwz         r9, 0xa4(r6)
  /* 805306D4 912500A4 */ stw         r9, 0xa4(r5)
  /* 805306D8 910500A8 */ stw         r8, 0xa8(r5)
  /* 805306DC 810600B0 */ lwz         r8, 0xb0(r6)
  /* 805306E0 812600AC */ lwz         r9, 0xac(r6)
  /* 805306E4 912500AC */ stw         r9, 0xac(r5)
  /* 805306E8 910500B0 */ stw         r8, 0xb0(r5)
  /* 805306EC 810600B4 */ lwz         r8, 0xb4(r6)
  /* 805306F0 910500B4 */ stw         r8, 0xb4(r5)
  /* 805306F4 890600B8 */ lbz         r8, 0xb8(r6)
  /* 805306F8 990500B8 */ stb         r8, 0xb8(r5)
  /* 805306FC 890600B9 */ lbz         r8, 0xb9(r6)
  /* 80530700 990500B9 */ stb         r8, 0xb9(r5)
  /* 80530704 890600BA */ lbz         r8, 0xba(r6)
  /* 80530708 990500BA */ stb         r8, 0xba(r5)
  /* 8053070C 810600BC */ lwz         r8, 0xbc(r6)
  /* 80530710 910500BC */ stw         r8, 0xbc(r5)
  /* 80530714 890600C0 */ lbz         r8, 0xc0(r6)
  /* 80530718 990500C0 */ stb         r8, 0xc0(r5)
  /* 8053071C 890600C1 */ lbz         r8, 0xc1(r6)
  /* 80530720 990500C1 */ stb         r8, 0xc1(r5)
  /* 80530724 890600C2 */ lbz         r8, 0xc2(r6)
  /* 80530728 990500C2 */ stb         r8, 0xc2(r5)
  /* 8053072C 810600C4 */ lwz         r8, 0xc4(r6)
  /* 80530730 910500C4 */ stw         r8, 0xc4(r5)
  /* 80530734 810600C8 */ lwz         r8, 0xc8(r6)
  /* 80530738 910500C8 */ stw         r8, 0xc8(r5)
  /* 8053073C 810600CC */ lwz         r8, 0xcc(r6)
  /* 80530740 910500CC */ stw         r8, 0xcc(r5)
  /* 80530744 810600D0 */ lwz         r8, 0xd0(r6)
  /* 80530748 910500D0 */ stw         r8, 0xd0(r5)
  /* 8053074C 810600D4 */ lwz         r8, 0xd4(r6)
  /* 80530750 910500D4 */ stw         r8, 0xd4(r5)
  /* 80530754 A10600D8 */ lhz         r8, 0xd8(r6)
  /* 80530758 B10500D8 */ sth         r8, 0xd8(r5)
  /* 8053075C A10600DA */ lhz         r8, 0xda(r6)
  /* 80530760 B10500DA */ sth         r8, 0xda(r5)
  /* 80530764 A10600DC */ lhz         r8, 0xdc(r6)
  /* 80530768 B10500DC */ sth         r8, 0xdc(r5)
  /* 8053076C A90600DE */ lha         r8, 0xde(r6)
  /* 80530770 B10500DE */ sth         r8, 0xde(r5)
  /* 80530774 890600E0 */ lbz         r8, 0xe0(r6)
  /* 80530778 990500E0 */ stb         r8, 0xe0(r5)
  /* 8053077C 890600E1 */ lbz         r8, 0xe1(r6)
  /* 80530780 990500E1 */ stb         r8, 0xe1(r5)
  /* 80530784 890600E2 */ lbz         r8, 0xe2(r6)
  /* 80530788 990500E2 */ stb         r8, 0xe2(r5)
  /* 8053078C A10600E8 */ lhz         r8, 0xe8(r6)
  /* 80530790 B10500E8 */ sth         r8, 0xe8(r5)
  /* 80530794 890600EC */ lbz         r8, 0xec(r6)
  /* 80530798 38C600F0 */ addi        r6, r6, 0xf0
  /* 8053079C 990500EC */ stb         r8, 0xec(r5)
  /* 805307A0 38A500F0 */ addi        r5, r5, 0xf0
  /* 805307A4 7C053840 */ cmplw       r5, r7
  /* 805307A8 4180FE34 */ blt+        lbl_805305dc
  /* 805307AC 80A40B48 */ lwz         r5, 0xb48(r4)
  /* 805307B0 3800000E */ li          r0, 0xe
  /* 805307B4 90A30B48 */ stw         r5, 0xb48(r3)
  /* 805307B8 38E30B78 */ addi        r7, r3, 0xb78
  /* 805307BC 38C40B78 */ addi        r6, r4, 0xb78
  /* 805307C0 80A40B4C */ lwz         r5, 0xb4c(r4)
  /* 805307C4 90A30B4C */ stw         r5, 0xb4c(r3)
  /* 805307C8 80A40B50 */ lwz         r5, 0xb50(r4)
  /* 805307CC 90A30B50 */ stw         r5, 0xb50(r3)
  /* 805307D0 80A40B54 */ lwz         r5, 0xb54(r4)
  /* 805307D4 90A30B54 */ stw         r5, 0xb54(r3)
  /* 805307D8 80A40B58 */ lwz         r5, 0xb58(r4)
  /* 805307DC 90A30B58 */ stw         r5, 0xb58(r3)
  /* 805307E0 80A40B5C */ lwz         r5, 0xb5c(r4)
  /* 805307E4 90A30B5C */ stw         r5, 0xb5c(r3)
  /* 805307E8 80A40B60 */ lwz         r5, 0xb60(r4)
  /* 805307EC 90A30B60 */ stw         r5, 0xb60(r3)
  /* 805307F0 88A40B64 */ lbz         r5, 0xb64(r4)
  /* 805307F4 98A30B64 */ stb         r5, 0xb64(r3)
  /* 805307F8 88A40B65 */ lbz         r5, 0xb65(r4)
  /* 805307FC 98A30B65 */ stb         r5, 0xb65(r3)
  /* 80530800 88A40B66 */ lbz         r5, 0xb66(r4)
  /* 80530804 98A30B66 */ stb         r5, 0xb66(r3)
  /* 80530808 88A40B67 */ lbz         r5, 0xb67(r4)
  /* 8053080C 98A30B67 */ stb         r5, 0xb67(r3)
  /* 80530810 80A40B68 */ lwz         r5, 0xb68(r4)
  /* 80530814 90A30B68 */ stw         r5, 0xb68(r3)
  /* 80530818 88A40B6C */ lbz         r5, 0xb6c(r4)
  /* 8053081C 98A30B6C */ stb         r5, 0xb6c(r3)
  /* 80530820 88A40B6D */ lbz         r5, 0xb6d(r4)
  /* 80530824 98A30B6D */ stb         r5, 0xb6d(r3)
  /* 80530828 80A40B70 */ lwz         r5, 0xb70(r4)
  /* 8053082C 90A30B70 */ stw         r5, 0xb70(r3)
  /* 80530830 80A40B74 */ lwz         r5, 0xb74(r4)
  /* 80530834 90A30B74 */ stw         r5, 0xb74(r3)
  /* 80530838 80A40B78 */ lwz         r5, 0xb78(r4)
  /* 8053083C 90A30B78 */ stw         r5, 0xb78(r3)
  /* 80530840 7C0903A6 */ mtctr       r0
  lbl_80530844:
  /* 80530844 80A60004 */ lwz         r5, 4(r6)
  /* 80530848 84060008 */ lwzu        r0, 8(r6)
  /* 8053084C 90A70004 */ stw         r5, 4(r7)
  /* 80530850 94070008 */ stwu        r0, 8(r7)
  /* 80530854 4200FFF0 */ bdnz        lbl_80530844
  /* 80530858 80040BEC */ lwz         r0, 0xbec(r4)
  /* 8053085C 90030BEC */ stw         r0, 0xbec(r3)
  /* 80530860 4E800020 */ blr
  // clang-format on
}
#endif

// Requires some inline-related pragma to be implemented correctly
#ifdef EQUIVALENT
namespace System {

void RaceConfig::initAwards() {
  initRace();
  mAwardsScenario.copy(&mRaceScenario);

  for (u8 i = 0; i < 12; i++) {
    mMenuScenario.getPlayer(i)->setPlayerType(PLAYER_TYPE_NONE);
    mMenuScenario.getPlayer(i)->setPrevFinishPos(i + 1);
    mMenuScenario.getPlayer(i)->setUnkPos(i + 1);
  }

  bool isGpWin = mMenuScenario.getGameType() == GAMETYPE_GRAND_PRIX_WIN;
  bool isLoss = mMenuScenario.getGameType() == GAMETYPE_LOSS;
  bool isTeamMode = mMenuScenario.isTeamMode();

  if (isGpWin) {
    for (u8 i = 1; i <= 3; i++) {
      for (u8 j = 0; j < 12; j++) {
        u8 unkPos = mRaceScenario.getPlayer(j)->getUnkPos();
        if (i != unkPos) {
          continue;
        }

        PlayerType playerType = mRaceScenario.getPlayer(j)->getPlayerType();
        if (playerType == PLAYER_TYPE_NONE) {
          continue;
        }

        u8 idx = i - 1;
        copy(i, j, idx);
        break;
      }
    }
  } else if (isTeamMode) {
    BattleTeam winningTeam = mRaceScenario.computeWinningTeam();
    BattleTeam winningTeam_ = (BattleTeam)(winningTeam == 0);
    for (u8 i = 0; i < getRacePlayerCount(); i++) {
      PlayerType playerType = mRaceScenario.getPlayer(i)->getPlayerType();
      if (playerType == PLAYER_TYPE_REAL_LOCAL) {
        BattleTeam playerTeam = mRaceScenario.getPlayer(i)->getTeam();
        if (winningTeam == playerTeam) {
          winningTeam_ = winningTeam;
          break;
        }
      }
    }

    u8 idx = 0;
    for (u8 i = 1; i <= 12; i++) {
      for (u8 j = 0; j < 12; j++) {
        u8 unkPos = mRaceScenario.getPlayer(j)->getUnkPos();
        if (i != unkPos) {
          continue;
        }

        PlayerType playerType = mRaceScenario.getPlayer(j)->getPlayerType();
        if (playerType == PLAYER_TYPE_REAL_LOCAL) {
          BattleTeam playerTeam = mRaceScenario.getPlayer(j)->getTeam();
          if (winningTeam_ != playerTeam) {
            continue;
          }

          copy(idx + 1, j, idx);
          idx++;
        }
      }
    }

    for (u8 i = 1; i <= 12; i++) {
      for (u8 j = 0; j < 12; j++) {
        u8 unkPos = mRaceScenario.getPlayer(j)->getUnkPos();
        if (i != unkPos) {
          continue;
        }

        PlayerType playerType = mRaceScenario.getPlayer(j)->getPlayerType();
        if (playerType == PLAYER_TYPE_NONE) {
          continue;
        }

        playerType = mRaceScenario.getPlayer(j)->getPlayerType();
        if (playerType != PLAYER_TYPE_REAL_LOCAL) {
          BattleTeam playerTeam = mRaceScenario.getPlayer(j)->getTeam();
          if (winningTeam_ != playerTeam) {
            continue;
          }

          copy(idx + 1, j, idx);
          idx++;
        }
      }
    }
  } else if (isLoss) {
    u8 idx = 0;
    for (u8 i = 1; i <= 12; i++) {
      for (u8 j = 0; j < 12; j++) {
        u8 unkPos = mRaceScenario.getPlayer(j)->getUnkPos();
        if (i != unkPos) {
          continue;
        }

        PlayerType playerType = mRaceScenario.getPlayer(j)->getPlayerType();
        if (playerType != PLAYER_TYPE_REAL_LOCAL) {
          continue;
        }

        copy(idx + 1, j, idx);
        idx++;
      }
    }
  } else {
    copy(1, 0, 0);
  }

  initRace();
}

} // namespace System
#else
// Symbol: Racedata_initAwards
// PAL: 0x80530864..0x80530f0c
MARK_BINARY_BLOB(Racedata_initAwards, 0x80530864, 0x80530f0c);
asm UNKNOWN_FUNCTION(Racedata_initAwards) {
  // clang-format off
  nofralloc
  /* 80530864 9421FFD0 */ stwu        r1, -0x30(r1)
  /* 80530868 7C0802A6 */ mflr        r0
  /* 8053086C 90010034 */ stw         r0, 0x34(r1)
  /* 80530870 BF210014 */ stmw        r25, 0x14(r1)
  /* 80530874 7C7F1B78 */ mr          r31, r3
  /* 80530878 4BFFFA4D */ bl          initRace__Q26System10RaceConfigFv
  /* 8053087C 387F1800 */ addi        r3, r31, 0x1800
  /* 80530880 389F0020 */ addi        r4, r31, 0x20
  /* 80530884 4BFFFD29 */ bl          RacedataScenario_copy
  /* 80530888 3BC00000 */ li          r30, 0x0
  lbl_8053088c:
  /* 8053088C 387F0C10 */ addi        r3, r31, 0xc10
  /* 80530890 57C4063E */ clrlwi      r4, r30, 0x18
  /* 80530894 4BFFDBA1 */ bl          getPlayer__Q26System18RaceConfigScenarioFUc
  /* 80530898 38800005 */ li          r4, 0x5
  /* 8053089C 4BFFDBB1 */ bl          setPlayerType__Q26System16RaceConfigPlayerFl
  /* 805308A0 57C4063E */ clrlwi      r4, r30, 0x18
  /* 805308A4 387F0C10 */ addi        r3, r31, 0xc10
  /* 805308A8 3BA40001 */ addi        r29, r4, 0x1
  /* 805308AC 4BFFDB89 */ bl          getPlayer__Q26System18RaceConfigScenarioFUc
  /* 805308B0 57A4063E */ clrlwi      r4, r29, 0x18
  /* 805308B4 4BFFDDA5 */ bl          setPrevFinishPos__Q26System16RaceConfigPlayerFSc
  /* 805308B8 387F0C10 */ addi        r3, r31, 0xc10
  /* 805308BC 57C4063E */ clrlwi      r4, r30, 0x18
  /* 805308C0 4BFFDB75 */ bl          getPlayer__Q26System18RaceConfigScenarioFUc
  /* 805308C4 57A4063E */ clrlwi      r4, r29, 0x18
  /* 805308C8 4BFFDD99 */ bl          setUnkPos__Q26System16RaceConfigPlayerFSc
  /* 805308CC 3BDE0001 */ addi        r30, r30, 0x1
  /* 805308D0 281E000C */ cmplwi      r30, 0xc
  /* 805308D4 4180FFB8 */ blt+        lbl_8053088c
  /* 805308D8 387F0C10 */ addi        r3, r31, 0xc10
  /* 805308DC 4BFFE43D */ bl          getGametype__Q26System18RaceConfigScenarioFv
  /* 805308E0 3803FFF9 */ addi        r0, r3, -0x7
  /* 805308E4 387F0C10 */ addi        r3, r31, 0xc10
  /* 805308E8 7C000034 */ cntlzw      r0, r0
  /* 805308EC 541DD97E */ srwi        r29, r0, 5
  /* 805308F0 4BFFE429 */ bl          getGametype__Q26System18RaceConfigScenarioFv
  /* 805308F4 3803FFF4 */ addi        r0, r3, -0xc
  /* 805308F8 387F0C10 */ addi        r3, r31, 0xc10
  /* 805308FC 7C000034 */ cntlzw      r0, r0
  /* 80530900 541ED97E */ srwi        r30, r0, 5
  /* 80530904 48000609 */ bl          isTeamMode__Q26System18RaceConfigScenarioFv
  /* 80530908 2C1D0000 */ cmpwi       r29, 0x0
  /* 8053090C 41820120 */ beq-        lbl_80530a2c
  /* 80530910 3BC00001 */ li          r30, 0x1
  lbl_80530914:
  /* 80530914 57DD063E */ clrlwi      r29, r30, 0x18
  /* 80530918 3B800000 */ li          r28, 0x0
  lbl_8053091c:
  /* 8053091C 387F0020 */ addi        r3, r31, 0x20
  /* 80530920 5784063E */ clrlwi      r4, r28, 0x18
  /* 80530924 4BFFD3FD */ bl          getPlayer__Q26System18RaceConfigScenarioCFUc
  /* 80530928 480005F1 */ bl          getUnkPos__Q26System16RaceConfigPlayerFv
  /* 8053092C 5460063E */ clrlwi      r0, r3, 0x18
  /* 80530930 7C1D0040 */ cmplw       r29, r0
  /* 80530934 408200DC */ bne-        lbl_80530a10
  /* 80530938 387F0020 */ addi        r3, r31, 0x20
  /* 8053093C 5784063E */ clrlwi      r4, r28, 0x18
  /* 80530940 4BFFD3E1 */ bl          getPlayer__Q26System18RaceConfigScenarioCFUc
  /* 80530944 4BFFE3DD */ bl          getPlayerType__Q26System16RaceConfigPlayerFv
  /* 80530948 2C030005 */ cmpwi       r3, 0x5
  /* 8053094C 418200C4 */ beq-        lbl_80530a10
  /* 80530950 381EFFFF */ addi        r0, r30, -0x1
  /* 80530954 387F0020 */ addi        r3, r31, 0x20
  /* 80530958 541B063E */ clrlwi      r27, r0, 0x18
  /* 8053095C 5784063E */ clrlwi      r4, r28, 0x18
  /* 80530960 4BFFD3C1 */ bl          getPlayer__Q26System18RaceConfigScenarioCFUc
  /* 80530964 480005BD */ bl          getCharacter__Q26System16RaceConfigPlayerFv
  /* 80530968 7C7D1B78 */ mr          r29, r3
  /* 8053096C 7F64DB78 */ mr          r4, r27
  /* 80530970 387F0C10 */ addi        r3, r31, 0xc10
  /* 80530974 4BFFDAC1 */ bl          getPlayer__Q26System18RaceConfigScenarioFUc
  /* 80530978 7FA4EB78 */ mr          r4, r29
  /* 8053097C 4BFFDAB1 */ bl          setCharacter__Q26System16RaceConfigPlayerFQ26System11CharacterId
  /* 80530980 387F0020 */ addi        r3, r31, 0x20
  /* 80530984 5784063E */ clrlwi      r4, r28, 0x18
  /* 80530988 4BFFD399 */ bl          getPlayer__Q26System18RaceConfigScenarioCFUc
  /* 8053098C 4800059D */ bl          getVehicle__Q26System16RaceConfigPlayerFv
  /* 80530990 7C7D1B78 */ mr          r29, r3
  /* 80530994 7F64DB78 */ mr          r4, r27
  /* 80530998 387F0C10 */ addi        r3, r31, 0xc10
  /* 8053099C 4BFFDA99 */ bl          getPlayer__Q26System18RaceConfigScenarioFUc
  /* 805309A0 7FA4EB78 */ mr          r4, r29
  /* 805309A4 4BFFDAA1 */ bl          setVehicle__Q26System16RaceConfigPlayerFQ26System9VehicleId
  /* 805309A8 7F64DB78 */ mr          r4, r27
  /* 805309AC 387F0C10 */ addi        r3, r31, 0xc10
  /* 805309B0 4BFFDA85 */ bl          getPlayer__Q26System18RaceConfigScenarioFUc
  /* 805309B4 38800001 */ li          r4, 0x1
  /* 805309B8 4BFFDA95 */ bl          setPlayerType__Q26System16RaceConfigPlayerFl
  /* 805309BC 7F64DB78 */ mr          r4, r27
  /* 805309C0 387F0C10 */ addi        r3, r31, 0xc10
  /* 805309C4 4BFFDA71 */ bl          getPlayer__Q26System18RaceConfigScenarioFUc
  /* 805309C8 57C4063E */ clrlwi      r4, r30, 0x18
  /* 805309CC 4BFFDC8D */ bl          setPrevFinishPos__Q26System16RaceConfigPlayerFSc
  /* 805309D0 7F64DB78 */ mr          r4, r27
  /* 805309D4 387F0C10 */ addi        r3, r31, 0xc10
  /* 805309D8 4BFFDA5D */ bl          getPlayer__Q26System18RaceConfigScenarioFUc
  /* 805309DC 57C4063E */ clrlwi      r4, r30, 0x18
  /* 805309E0 4BFFDC81 */ bl          setUnkPos__Q26System16RaceConfigPlayerFSc
  /* 805309E4 387F0020 */ addi        r3, r31, 0x20
  /* 805309E8 5784063E */ clrlwi      r4, r28, 0x18
  /* 805309EC 4BFFD335 */ bl          getPlayer__Q26System18RaceConfigScenarioCFUc
  /* 805309F0 48000679 */ bl          getMii__Q26System16RaceConfigPlayerFv
  /* 805309F4 7C7D1B78 */ mr          r29, r3
  /* 805309F8 7F64DB78 */ mr          r4, r27
  /* 805309FC 387F0C10 */ addi        r3, r31, 0xc10
  /* 80530A00 4BFFDA35 */ bl          getPlayer__Q26System18RaceConfigScenarioFUc
  /* 80530A04 7FA4EB78 */ mr          r4, r29
  /* 80530A08 48000529 */ bl          setMii__Q26System16RaceConfigPlayerFRCQ26System3Mii
  /* 80530A0C 48000010 */ b           lbl_80530a1c
  lbl_80530a10:
  /* 80530A10 3B9C0001 */ addi        r28, r28, 0x1
  /* 80530A14 281C000C */ cmplwi      r28, 0xc
  /* 80530A18 4180FF04 */ blt+        lbl_8053091c
  lbl_80530a1c:
  /* 80530A1C 3BDE0001 */ addi        r30, r30, 0x1
  /* 80530A20 281E0003 */ cmplwi      r30, 3
  /* 80530A24 4081FEF0 */ ble+        lbl_80530914
  /* 80530A28 480004C8 */ b           lbl_80530ef0
  lbl_80530a2c:
  /* 80530A2C 2C030000 */ cmpwi       r3, 0x0
  /* 80530A30 418202E8 */ beq-        lbl_80530d18
  /* 80530A34 387F0020 */ addi        r3, r31, 0x20
  /* 80530A38 4BFFD271 */ bl          computeWinningTeam__Q26System18RaceConfigScenarioFv
  /* 80530A3C 7C600034 */ cntlzw      r0, r3
  /* 80530A40 7C7B1B78 */ mr          r27, r3
  /* 80530A44 541CD97E */ srwi        r28, r0, 5
  /* 80530A48 3BA00000 */ li          r29, 0x0
  /* 80530A4C 48000040 */ b           lbl_80530a8c
  lbl_80530a50:
  /* 80530A50 387F0020 */ addi        r3, r31, 0x20
  /* 80530A54 57A4063E */ clrlwi      r4, r29, 0x18
  /* 80530A58 4BFFD2C9 */ bl          getPlayer__Q26System18RaceConfigScenarioCFUc
  /* 80530A5C 4BFFE2C5 */ bl          getPlayerType__Q26System16RaceConfigPlayerFv
  /* 80530A60 2C030000 */ cmpwi       r3, 0x0
  /* 80530A64 40820024 */ bne-        lbl_80530a88
  /* 80530A68 387F0020 */ addi        r3, r31, 0x20
  /* 80530A6C 57A4063E */ clrlwi      r4, r29, 0x18
  /* 80530A70 4BFFD2B1 */ bl          getPlayer__Q26System18RaceConfigScenarioCFUc
  /* 80530A74 4BFFD2A5 */ bl          getTeam__Q26System16RaceConfigPlayerFv
  /* 80530A78 7C1B1800 */ cmpw        r27, r3
  /* 80530A7C 4082000C */ bne-        lbl_80530a88
  /* 80530A80 7F7CDB78 */ mr          r28, r27
  /* 80530A84 4800001C */ b           lbl_80530aa0
  lbl_80530a88:
  /* 80530A88 3BBD0001 */ addi        r29, r29, 0x1
  lbl_80530a8c:
  /* 80530A8C 4BFFD2A5 */ bl          getRacePlayerCount__Q26System10RaceConfigFv
  /* 80530A90 5463063E */ clrlwi      r3, r3, 0x18
  /* 80530A94 57A0063E */ clrlwi      r0, r29, 0x18
  /* 80530A98 7C001840 */ cmplw       r0, r3
  /* 80530A9C 4180FFB4 */ blt+        lbl_80530a50
  lbl_80530aa0:
  /* 80530AA0 3B600000 */ li          r27, 0x0
  /* 80530AA4 3B400001 */ li          r26, 0x1
  lbl_80530aa8:
  /* 80530AA8 575E063E */ clrlwi      r30, r26, 0x18
  /* 80530AAC 3B200000 */ li          r25, 0x0
  lbl_80530ab0:
  /* 80530AB0 387F0020 */ addi        r3, r31, 0x20
  /* 80530AB4 5724063E */ clrlwi      r4, r25, 0x18
  /* 80530AB8 4BFFD269 */ bl          getPlayer__Q26System18RaceConfigScenarioCFUc
  /* 80530ABC 4800045D */ bl          getUnkPos__Q26System16RaceConfigPlayerFv
  /* 80530AC0 5460063E */ clrlwi      r0, r3, 0x18
  /* 80530AC4 7C1E0040 */ cmplw       r30, r0
  /* 80530AC8 408200F0 */ bne-        lbl_80530bb8
  /* 80530ACC 387F0020 */ addi        r3, r31, 0x20
  /* 80530AD0 5724063E */ clrlwi      r4, r25, 0x18
  /* 80530AD4 4BFFD24D */ bl          getPlayer__Q26System18RaceConfigScenarioCFUc
  /* 80530AD8 4BFFE249 */ bl          getPlayerType__Q26System16RaceConfigPlayerFv
  /* 80530ADC 2C030000 */ cmpwi       r3, 0x0
  /* 80530AE0 408200D8 */ bne-        lbl_80530bb8
  /* 80530AE4 387F0020 */ addi        r3, r31, 0x20
  /* 80530AE8 5724063E */ clrlwi      r4, r25, 0x18
  /* 80530AEC 4BFFD235 */ bl          getPlayer__Q26System18RaceConfigScenarioCFUc
  /* 80530AF0 4BFFD229 */ bl          getTeam__Q26System16RaceConfigPlayerFv
  /* 80530AF4 7C1C1800 */ cmpw        r28, r3
  /* 80530AF8 408200C0 */ bne-        lbl_80530bb8
  /* 80530AFC 387F0020 */ addi        r3, r31, 0x20
  /* 80530B00 5724063E */ clrlwi      r4, r25, 0x18
  /* 80530B04 4BFFD21D */ bl          getPlayer__Q26System18RaceConfigScenarioCFUc
  /* 80530B08 48000419 */ bl          getCharacter__Q26System16RaceConfigPlayerFv
  /* 80530B0C 7C7D1B78 */ mr          r29, r3
  /* 80530B10 387F0C10 */ addi        r3, r31, 0xc10
  /* 80530B14 5764063E */ clrlwi      r4, r27, 0x18
  /* 80530B18 4BFFD91D */ bl          getPlayer__Q26System18RaceConfigScenarioFUc
  /* 80530B1C 7FA4EB78 */ mr          r4, r29
  /* 80530B20 4BFFD90D */ bl          setCharacter__Q26System16RaceConfigPlayerFQ26System11CharacterId
  /* 80530B24 387F0020 */ addi        r3, r31, 0x20
  /* 80530B28 5724063E */ clrlwi      r4, r25, 0x18
  /* 80530B2C 4BFFD1F5 */ bl          getPlayer__Q26System18RaceConfigScenarioCFUc
  /* 80530B30 480003F9 */ bl          getVehicle__Q26System16RaceConfigPlayerFv
  /* 80530B34 7C7D1B78 */ mr          r29, r3
  /* 80530B38 387F0C10 */ addi        r3, r31, 0xc10
  /* 80530B3C 5764063E */ clrlwi      r4, r27, 0x18
  /* 80530B40 4BFFD8F5 */ bl          getPlayer__Q26System18RaceConfigScenarioFUc
  /* 80530B44 7FA4EB78 */ mr          r4, r29
  /* 80530B48 4BFFD8FD */ bl          setVehicle__Q26System16RaceConfigPlayerFQ26System9VehicleId
  /* 80530B4C 387F0C10 */ addi        r3, r31, 0xc10
  /* 80530B50 5764063E */ clrlwi      r4, r27, 0x18
  /* 80530B54 4BFFD8E1 */ bl          getPlayer__Q26System18RaceConfigScenarioFUc
  /* 80530B58 38800001 */ li          r4, 0x1
  /* 80530B5C 4BFFD8F1 */ bl          setPlayerType__Q26System16RaceConfigPlayerFl
  /* 80530B60 5764063E */ clrlwi      r4, r27, 0x18
  /* 80530B64 387F0C10 */ addi        r3, r31, 0xc10
  /* 80530B68 3BA40001 */ addi        r29, r4, 0x1
  /* 80530B6C 4BFFD8C9 */ bl          getPlayer__Q26System18RaceConfigScenarioFUc
  /* 80530B70 57A4063E */ clrlwi      r4, r29, 0x18
  /* 80530B74 4BFFDAE5 */ bl          setPrevFinishPos__Q26System16RaceConfigPlayerFSc
  /* 80530B78 387F0C10 */ addi        r3, r31, 0xc10
  /* 80530B7C 5764063E */ clrlwi      r4, r27, 0x18
  /* 80530B80 4BFFD8B5 */ bl          getPlayer__Q26System18RaceConfigScenarioFUc
  /* 80530B84 57A4063E */ clrlwi      r4, r29, 0x18
  /* 80530B88 4BFFDAD9 */ bl          setUnkPos__Q26System16RaceConfigPlayerFSc
  /* 80530B8C 387F0020 */ addi        r3, r31, 0x20
  /* 80530B90 5724063E */ clrlwi      r4, r25, 0x18
  /* 80530B94 4BFFD18D */ bl          getPlayer__Q26System18RaceConfigScenarioCFUc
  /* 80530B98 480004D1 */ bl          getMii__Q26System16RaceConfigPlayerFv
  /* 80530B9C 7C7D1B78 */ mr          r29, r3
  /* 80530BA0 387F0C10 */ addi        r3, r31, 0xc10
  /* 80530BA4 5764063E */ clrlwi      r4, r27, 0x18
  /* 80530BA8 4BFFD88D */ bl          getPlayer__Q26System18RaceConfigScenarioFUc
  /* 80530BAC 7FA4EB78 */ mr          r4, r29
  /* 80530BB0 48000381 */ bl          setMii__Q26System16RaceConfigPlayerFRCQ26System3Mii
  /* 80530BB4 3B7B0001 */ addi        r27, r27, 0x1
  lbl_80530bb8:
  /* 80530BB8 3B390001 */ addi        r25, r25, 0x1
  /* 80530BBC 2819000C */ cmplwi      r25, 0xc
  /* 80530BC0 4180FEF0 */ blt+        lbl_80530ab0
  /* 80530BC4 3B5A0001 */ addi        r26, r26, 0x1
  /* 80530BC8 281A000C */ cmplwi      r26, 0xc
  /* 80530BCC 4081FEDC */ ble+        lbl_80530aa8
  /* 80530BD0 3B200001 */ li          r25, 0x1
  lbl_80530bd4:
  /* 80530BD4 573E063E */ clrlwi      r30, r25, 0x18
  /* 80530BD8 3B400000 */ li          r26, 0x0
  lbl_80530bdc:
  /* 80530BDC 387F0020 */ addi        r3, r31, 0x20
  /* 80530BE0 5744063E */ clrlwi      r4, r26, 0x18
  /* 80530BE4 4BFFD13D */ bl          getPlayer__Q26System18RaceConfigScenarioCFUc
  /* 80530BE8 48000331 */ bl          getUnkPos__Q26System16RaceConfigPlayerFv
  /* 80530BEC 5460063E */ clrlwi      r0, r3, 0x18
  /* 80530BF0 7C1E0040 */ cmplw       r30, r0
  /* 80530BF4 40820108 */ bne-        lbl_80530cfc
  /* 80530BF8 387F0020 */ addi        r3, r31, 0x20
  /* 80530BFC 5744063E */ clrlwi      r4, r26, 0x18
  /* 80530C00 4BFFD121 */ bl          getPlayer__Q26System18RaceConfigScenarioCFUc
  /* 80530C04 4BFFE11D */ bl          getPlayerType__Q26System16RaceConfigPlayerFv
  /* 80530C08 2C030005 */ cmpwi       r3, 0x5
  /* 80530C0C 418200F0 */ beq-        lbl_80530cfc
  /* 80530C10 387F0020 */ addi        r3, r31, 0x20
  /* 80530C14 5744063E */ clrlwi      r4, r26, 0x18
  /* 80530C18 4BFFD109 */ bl          getPlayer__Q26System18RaceConfigScenarioCFUc
  /* 80530C1C 4BFFE105 */ bl          getPlayerType__Q26System16RaceConfigPlayerFv
  /* 80530C20 2C030000 */ cmpwi       r3, 0x0
  /* 80530C24 418200D8 */ beq-        lbl_80530cfc
  /* 80530C28 387F0020 */ addi        r3, r31, 0x20
  /* 80530C2C 5744063E */ clrlwi      r4, r26, 0x18
  /* 80530C30 4BFFD0F1 */ bl          getPlayer__Q26System18RaceConfigScenarioCFUc
  /* 80530C34 4BFFD0E5 */ bl          getTeam__Q26System16RaceConfigPlayerFv
  /* 80530C38 7C1C1800 */ cmpw        r28, r3
  /* 80530C3C 408200C0 */ bne-        lbl_80530cfc
  /* 80530C40 387F0020 */ addi        r3, r31, 0x20
  /* 80530C44 5744063E */ clrlwi      r4, r26, 0x18
  /* 80530C48 4BFFD0D9 */ bl          getPlayer__Q26System18RaceConfigScenarioCFUc
  /* 80530C4C 480002D5 */ bl          getCharacter__Q26System16RaceConfigPlayerFv
  /* 80530C50 7C7D1B78 */ mr          r29, r3
  /* 80530C54 387F0C10 */ addi        r3, r31, 0xc10
  /* 80530C58 5764063E */ clrlwi      r4, r27, 0x18
  /* 80530C5C 4BFFD7D9 */ bl          getPlayer__Q26System18RaceConfigScenarioFUc
  /* 80530C60 7FA4EB78 */ mr          r4, r29
  /* 80530C64 4BFFD7C9 */ bl          setCharacter__Q26System16RaceConfigPlayerFQ26System11CharacterId
  /* 80530C68 387F0020 */ addi        r3, r31, 0x20
  /* 80530C6C 5744063E */ clrlwi      r4, r26, 0x18
  /* 80530C70 4BFFD0B1 */ bl          getPlayer__Q26System18RaceConfigScenarioCFUc
  /* 80530C74 480002B5 */ bl          getVehicle__Q26System16RaceConfigPlayerFv
  /* 80530C78 7C7D1B78 */ mr          r29, r3
  /* 80530C7C 387F0C10 */ addi        r3, r31, 0xc10
  /* 80530C80 5764063E */ clrlwi      r4, r27, 0x18
  /* 80530C84 4BFFD7B1 */ bl          getPlayer__Q26System18RaceConfigScenarioFUc
  /* 80530C88 7FA4EB78 */ mr          r4, r29
  /* 80530C8C 4BFFD7B9 */ bl          setVehicle__Q26System16RaceConfigPlayerFQ26System9VehicleId
  /* 80530C90 387F0C10 */ addi        r3, r31, 0xc10
  /* 80530C94 5764063E */ clrlwi      r4, r27, 0x18
  /* 80530C98 4BFFD79D */ bl          getPlayer__Q26System18RaceConfigScenarioFUc
  /* 80530C9C 38800001 */ li          r4, 0x1
  /* 80530CA0 4BFFD7AD */ bl          setPlayerType__Q26System16RaceConfigPlayerFl
  /* 80530CA4 5764063E */ clrlwi      r4, r27, 0x18
  /* 80530CA8 387F0C10 */ addi        r3, r31, 0xc10
  /* 80530CAC 3BA40001 */ addi        r29, r4, 0x1
  /* 80530CB0 4BFFD785 */ bl          getPlayer__Q26System18RaceConfigScenarioFUc
  /* 80530CB4 57A4063E */ clrlwi      r4, r29, 0x18
  /* 80530CB8 4BFFD9A1 */ bl          setPrevFinishPos__Q26System16RaceConfigPlayerFSc
  /* 80530CBC 387F0C10 */ addi        r3, r31, 0xc10
  /* 80530CC0 5764063E */ clrlwi      r4, r27, 0x18
  /* 80530CC4 4BFFD771 */ bl          getPlayer__Q26System18RaceConfigScenarioFUc
  /* 80530CC8 57A4063E */ clrlwi      r4, r29, 0x18
  /* 80530CCC 4BFFD995 */ bl          setUnkPos__Q26System16RaceConfigPlayerFSc
  /* 80530CD0 387F0020 */ addi        r3, r31, 0x20
  /* 80530CD4 5744063E */ clrlwi      r4, r26, 0x18
  /* 80530CD8 4BFFD049 */ bl          getPlayer__Q26System18RaceConfigScenarioCFUc
  /* 80530CDC 4800038D */ bl          getMii__Q26System16RaceConfigPlayerFv
  /* 80530CE0 7C7D1B78 */ mr          r29, r3
  /* 80530CE4 387F0C10 */ addi        r3, r31, 0xc10
  /* 80530CE8 5764063E */ clrlwi      r4, r27, 0x18
  /* 80530CEC 4BFFD749 */ bl          getPlayer__Q26System18RaceConfigScenarioFUc
  /* 80530CF0 7FA4EB78 */ mr          r4, r29
  /* 80530CF4 4800023D */ bl          setMii__Q26System16RaceConfigPlayerFRCQ26System3Mii
  /* 80530CF8 3B7B0001 */ addi        r27, r27, 0x1
  lbl_80530cfc:
  /* 80530CFC 3B5A0001 */ addi        r26, r26, 0x1
  /* 80530D00 281A000C */ cmplwi      r26, 0xc
  /* 80530D04 4180FED8 */ blt+        lbl_80530bdc
  /* 80530D08 3B390001 */ addi        r25, r25, 0x1
  /* 80530D0C 2819000C */ cmplwi      r25, 0xc
  /* 80530D10 4081FEC4 */ ble+        lbl_80530bd4
  /* 80530D14 480001DC */ b           lbl_80530ef0
  lbl_80530d18:
  /* 80530D18 2C1E0000 */ cmpwi       r30, 0x0
  /* 80530D1C 41820120 */ beq-        lbl_80530e3c
  /* 80530D20 3B200000 */ li          r25, 0x0
  /* 80530D24 3B400001 */ li          r26, 0x1
  lbl_80530d28:
  /* 80530D28 575D063E */ clrlwi      r29, r26, 0x18
  /* 80530D2C 3B600000 */ li          r27, 0x0
  lbl_80530d30:
  /* 80530D30 387F0020 */ addi        r3, r31, 0x20
  /* 80530D34 5764063E */ clrlwi      r4, r27, 0x18
  /* 80530D38 4BFFCFE9 */ bl          getPlayer__Q26System18RaceConfigScenarioCFUc
  /* 80530D3C 480001DD */ bl          getUnkPos__Q26System16RaceConfigPlayerFv
  /* 80530D40 5460063E */ clrlwi      r0, r3, 0x18
  /* 80530D44 7C1D0040 */ cmplw       r29, r0
  /* 80530D48 408200D8 */ bne-        lbl_80530e20
  /* 80530D4C 387F0020 */ addi        r3, r31, 0x20
  /* 80530D50 5764063E */ clrlwi      r4, r27, 0x18
  /* 80530D54 4BFFCFCD */ bl          getPlayer__Q26System18RaceConfigScenarioCFUc
  /* 80530D58 4BFFDFC9 */ bl          getPlayerType__Q26System16RaceConfigPlayerFv
  /* 80530D5C 2C030000 */ cmpwi       r3, 0x0
  /* 80530D60 408200C0 */ bne-        lbl_80530e20
  /* 80530D64 387F0020 */ addi        r3, r31, 0x20
  /* 80530D68 5764063E */ clrlwi      r4, r27, 0x18
  /* 80530D6C 4BFFCFB5 */ bl          getPlayer__Q26System18RaceConfigScenarioCFUc
  /* 80530D70 480001B1 */ bl          getCharacter__Q26System16RaceConfigPlayerFv
  /* 80530D74 7C7E1B78 */ mr          r30, r3
  /* 80530D78 387F0C10 */ addi        r3, r31, 0xc10
  /* 80530D7C 5724063E */ clrlwi      r4, r25, 0x18
  /* 80530D80 4BFFD6B5 */ bl          getPlayer__Q26System18RaceConfigScenarioFUc
  /* 80530D84 7FC4F378 */ mr          r4, r30
  /* 80530D88 4BFFD6A5 */ bl          setCharacter__Q26System16RaceConfigPlayerFQ26System11CharacterId
  /* 80530D8C 387F0020 */ addi        r3, r31, 0x20
  /* 80530D90 5764063E */ clrlwi      r4, r27, 0x18
  /* 80530D94 4BFFCF8D */ bl          getPlayer__Q26System18RaceConfigScenarioCFUc
  /* 80530D98 48000191 */ bl          getVehicle__Q26System16RaceConfigPlayerFv
  /* 80530D9C 7C7E1B78 */ mr          r30, r3
  /* 80530DA0 387F0C10 */ addi        r3, r31, 0xc10
  /* 80530DA4 5724063E */ clrlwi      r4, r25, 0x18
  /* 80530DA8 4BFFD68D */ bl          getPlayer__Q26System18RaceConfigScenarioFUc
  /* 80530DAC 7FC4F378 */ mr          r4, r30
  /* 80530DB0 4BFFD695 */ bl          setVehicle__Q26System16RaceConfigPlayerFQ26System9VehicleId
  /* 80530DB4 387F0C10 */ addi        r3, r31, 0xc10
  /* 80530DB8 5724063E */ clrlwi      r4, r25, 0x18
  /* 80530DBC 4BFFD679 */ bl          getPlayer__Q26System18RaceConfigScenarioFUc
  /* 80530DC0 38800001 */ li          r4, 0x1
  /* 80530DC4 4BFFD689 */ bl          setPlayerType__Q26System16RaceConfigPlayerFl
  /* 80530DC8 5724063E */ clrlwi      r4, r25, 0x18
  /* 80530DCC 387F0C10 */ addi        r3, r31, 0xc10
  /* 80530DD0 3BC40001 */ addi        r30, r4, 0x1
  /* 80530DD4 4BFFD661 */ bl          getPlayer__Q26System18RaceConfigScenarioFUc
  /* 80530DD8 57C4063E */ clrlwi      r4, r30, 0x18
  /* 80530DDC 4BFFD87D */ bl          setPrevFinishPos__Q26System16RaceConfigPlayerFSc
  /* 80530DE0 387F0C10 */ addi        r3, r31, 0xc10
  /* 80530DE4 5724063E */ clrlwi      r4, r25, 0x18
  /* 80530DE8 4BFFD64D */ bl          getPlayer__Q26System18RaceConfigScenarioFUc
  /* 80530DEC 57C4063E */ clrlwi      r4, r30, 0x18
  /* 80530DF0 4BFFD871 */ bl          setUnkPos__Q26System16RaceConfigPlayerFSc
  /* 80530DF4 387F0020 */ addi        r3, r31, 0x20
  /* 80530DF8 5764063E */ clrlwi      r4, r27, 0x18
  /* 80530DFC 4BFFCF25 */ bl          getPlayer__Q26System18RaceConfigScenarioCFUc
  /* 80530E00 48000269 */ bl          getMii__Q26System16RaceConfigPlayerFv
  /* 80530E04 7C7E1B78 */ mr          r30, r3
  /* 80530E08 387F0C10 */ addi        r3, r31, 0xc10
  /* 80530E0C 5724063E */ clrlwi      r4, r25, 0x18
  /* 80530E10 4BFFD625 */ bl          getPlayer__Q26System18RaceConfigScenarioFUc
  /* 80530E14 7FC4F378 */ mr          r4, r30
  /* 80530E18 48000119 */ bl          setMii__Q26System16RaceConfigPlayerFRCQ26System3Mii
  /* 80530E1C 3B390001 */ addi        r25, r25, 0x1
  lbl_80530e20:
  /* 80530E20 3B7B0001 */ addi        r27, r27, 0x1
  /* 80530E24 281B000C */ cmplwi      r27, 0xc
  /* 80530E28 4180FF08 */ blt+        lbl_80530d30
  /* 80530E2C 3B5A0001 */ addi        r26, r26, 0x1
  /* 80530E30 281A000C */ cmplwi      r26, 0xc
  /* 80530E34 4081FEF4 */ ble+        lbl_80530d28
  /* 80530E38 480000B8 */ b           lbl_80530ef0
  lbl_80530e3c:
  /* 80530E3C 387F0020 */ addi        r3, r31, 0x20
  /* 80530E40 38800000 */ li          r4, 0x0
  /* 80530E44 4BFFCEDD */ bl          getPlayer__Q26System18RaceConfigScenarioCFUc
  /* 80530E48 480000D9 */ bl          getCharacter__Q26System16RaceConfigPlayerFv
  /* 80530E4C 7C7E1B78 */ mr          r30, r3
  /* 80530E50 387F0C10 */ addi        r3, r31, 0xc10
  /* 80530E54 38800000 */ li          r4, 0x0
  /* 80530E58 4BFFD5DD */ bl          getPlayer__Q26System18RaceConfigScenarioFUc
  /* 80530E5C 7FC4F378 */ mr          r4, r30
  /* 80530E60 4BFFD5CD */ bl          setCharacter__Q26System16RaceConfigPlayerFQ26System11CharacterId
  /* 80530E64 387F0020 */ addi        r3, r31, 0x20
  /* 80530E68 38800000 */ li          r4, 0x0
  /* 80530E6C 4BFFCEB5 */ bl          getPlayer__Q26System18RaceConfigScenarioCFUc
  /* 80530E70 480000B9 */ bl          getVehicle__Q26System16RaceConfigPlayerFv
  /* 80530E74 7C7E1B78 */ mr          r30, r3
  /* 80530E78 387F0C10 */ addi        r3, r31, 0xc10
  /* 80530E7C 38800000 */ li          r4, 0x0
  /* 80530E80 4BFFD5B5 */ bl          getPlayer__Q26System18RaceConfigScenarioFUc
  /* 80530E84 7FC4F378 */ mr          r4, r30
  /* 80530E88 4BFFD5BD */ bl          setVehicle__Q26System16RaceConfigPlayerFQ26System9VehicleId
  /* 80530E8C 387F0C10 */ addi        r3, r31, 0xc10
  /* 80530E90 38800000 */ li          r4, 0x0
  /* 80530E94 4BFFD5A1 */ bl          getPlayer__Q26System18RaceConfigScenarioFUc
  /* 80530E98 38800001 */ li          r4, 0x1
  /* 80530E9C 4BFFD5B1 */ bl          setPlayerType__Q26System16RaceConfigPlayerFl
  /* 80530EA0 387F0C10 */ addi        r3, r31, 0xc10
  /* 80530EA4 38800000 */ li          r4, 0x0
  /* 80530EA8 4BFFD58D */ bl          getPlayer__Q26System18RaceConfigScenarioFUc
  /* 80530EAC 38800001 */ li          r4, 0x1
  /* 80530EB0 4BFFD7A9 */ bl          setPrevFinishPos__Q26System16RaceConfigPlayerFSc
  /* 80530EB4 387F0C10 */ addi        r3, r31, 0xc10
  /* 80530EB8 38800000 */ li          r4, 0x0
  /* 80530EBC 4BFFD579 */ bl          getPlayer__Q26System18RaceConfigScenarioFUc
  /* 80530EC0 38800001 */ li          r4, 0x1
  /* 80530EC4 4BFFD79D */ bl          setUnkPos__Q26System16RaceConfigPlayerFSc
  /* 80530EC8 387F0020 */ addi        r3, r31, 0x20
  /* 80530ECC 38800000 */ li          r4, 0x0
  /* 80530ED0 4BFFCE51 */ bl          getPlayer__Q26System18RaceConfigScenarioCFUc
  /* 80530ED4 48000195 */ bl          getMii__Q26System16RaceConfigPlayerFv
  /* 80530ED8 7C7E1B78 */ mr          r30, r3
  /* 80530EDC 387F0C10 */ addi        r3, r31, 0xc10
  /* 80530EE0 38800000 */ li          r4, 0x0
  /* 80530EE4 4BFFD551 */ bl          getPlayer__Q26System18RaceConfigScenarioFUc
  /* 80530EE8 7FC4F378 */ mr          r4, r30
  /* 80530EEC 48000045 */ bl          setMii__Q26System16RaceConfigPlayerFRCQ26System3Mii
  lbl_80530ef0:
  /* 80530EF0 7FE3FB78 */ mr          r3, r31
  /* 80530EF4 4BFFF3D1 */ bl          initRace__Q26System10RaceConfigFv
  /* 80530EF8 BB210014 */ lmw         r25, 0x14(r1)
  /* 80530EFC 80010034 */ lwz         r0, 0x34(r1)
  /* 80530F00 7C0803A6 */ mtlr        r0
  /* 80530F04 38210030 */ addi        r1, r1, 0x30
  /* 80530F08 4E800020 */ blr
  // clang-format on
}
#endif

namespace System {

bool RaceConfigScenario::isTeamMode() { return mSettings.mModeFlags >> 1 & 1; }

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
MARK_BINARY_BLOB(Racedata_initCredits, 0x80531070, 0x80531ce4);
asm UNKNOWN_FUNCTION(Racedata_initCredits) {
  // clang-format off
  nofralloc
  /* 80531070 9421FFC0 */ stwu        r1, -0x40(r1)
  /* 80531074 7C0802A6 */ mflr        r0
  /* 80531078 38A30C18 */ addi        r5, r3, 0xc18
  /* 8053107C 38831808 */ addi        r4, r3, 0x1808
  /* 80531080 90010044 */ stw         r0, 0x44(r1)
  /* 80531084 38C31758 */ addi        r6, r3, 0x1758
  /* 80531088 BEA10014 */ stmw        r21, 0x14(r1)
  /* 8053108C 7C7F1B78 */ mr          r31, r3
  /* 80531090 88031804 */ lbz         r0, 0x1804(r3)
  /* 80531094 89231805 */ lbz         r9, 0x1805(r3)
  /* 80531098 89031806 */ lbz         r8, 0x1806(r3)
  /* 8053109C 88E31807 */ lbz         r7, 0x1807(r3)
  /* 805310A0 98030C14 */ stb         r0, 0xc14(r3)
  /* 805310A4 38000026 */ li          r0, 0x26
  /* 805310A8 99230C15 */ stb         r9, 0xc15(r3)
  /* 805310AC 99030C16 */ stb         r8, 0xc16(r3)
  /* 805310B0 98E30C17 */ stb         r7, 0xc17(r3)
  lbl_805310b4:
  /* 805310B4 88E40004 */ lbz         r7, 4(r4)
  /* 805310B8 39450023 */ addi        r10, r5, 0x23
  /* 805310BC 98E50004 */ stb         r7, 4(r5)
  /* 805310C0 39240023 */ addi        r9, r4, 0x23
  /* 805310C4 88E40005 */ lbz         r7, 5(r4)
  /* 805310C8 98E50005 */ stb         r7, 5(r5)
  /* 805310CC 88E40006 */ lbz         r7, 6(r4)
  /* 805310D0 98E50006 */ stb         r7, 6(r5)
  /* 805310D4 80E40008 */ lwz         r7, 8(r4)
  /* 805310D8 90E50008 */ stw         r7, 8(r5)
  /* 805310DC 80E4000C */ lwz         r7, 0xc(r4)
  /* 805310E0 90E5000C */ stw         r7, 0xc(r5)
  /* 805310E4 80E40010 */ lwz         r7, 0x10(r4)
  /* 805310E8 90E50010 */ stw         r7, 0x10(r5)
  /* 805310EC 80E40018 */ lwz         r7, 0x18(r4)
  /* 805310F0 90E50018 */ stw         r7, 0x18(r5)
  /* 805310F4 88E4001C */ lbz         r7, 0x1c(r4)
  /* 805310F8 98E5001C */ stb         r7, 0x1c(r5)
  /* 805310FC 88E4001D */ lbz         r7, 0x1d(r4)
  /* 80531100 98E5001D */ stb         r7, 0x1d(r5)
  /* 80531104 80E40020 */ lwz         r7, 0x20(r4)
  /* 80531108 90E50020 */ stw         r7, 0x20(r5)
  /* 8053110C 7C0903A6 */ mtctr       r0
  lbl_80531110:
  /* 80531110 89090001 */ lbz         r8, 1(r9)
  /* 80531114 8CE90002 */ lbzu        r7, 2(r9)
  /* 80531118 990A0001 */ stb         r8, 1(r10)
  /* 8053111C 9CEA0002 */ stbu        r7, 2(r10)
  /* 80531120 4200FFF0 */ bdnz        lbl_80531110
  /* 80531124 80E40070 */ lwz         r7, 0x70(r4)
  /* 80531128 90E50070 */ stw         r7, 0x70(r5)
  /* 8053112C 88E40074 */ lbz         r7, 0x74(r4)
  /* 80531130 98E50074 */ stb         r7, 0x74(r5)
  /* 80531134 88E40075 */ lbz         r7, 0x75(r4)
  /* 80531138 98E50075 */ stb         r7, 0x75(r5)
  /* 8053113C 88E40076 */ lbz         r7, 0x76(r4)
  /* 80531140 98E50076 */ stb         r7, 0x76(r5)
  /* 80531144 88E40077 */ lbz         r7, 0x77(r4)
  /* 80531148 98E50077 */ stb         r7, 0x77(r5)
  /* 8053114C 80E40078 */ lwz         r7, 0x78(r4)
  /* 80531150 90E50078 */ stw         r7, 0x78(r5)
  /* 80531154 80E40080 */ lwz         r7, 0x80(r4)
  /* 80531158 8104007C */ lwz         r8, 0x7c(r4)
  /* 8053115C 9105007C */ stw         r8, 0x7c(r5)
  /* 80531160 90E50080 */ stw         r7, 0x80(r5)
  /* 80531164 80E40088 */ lwz         r7, 0x88(r4)
  /* 80531168 81040084 */ lwz         r8, 0x84(r4)
  /* 8053116C 91050084 */ stw         r8, 0x84(r5)
  /* 80531170 90E50088 */ stw         r7, 0x88(r5)
  /* 80531174 80E40090 */ lwz         r7, 0x90(r4)
  /* 80531178 8104008C */ lwz         r8, 0x8c(r4)
  /* 8053117C 9105008C */ stw         r8, 0x8c(r5)
  /* 80531180 90E50090 */ stw         r7, 0x90(r5)
  /* 80531184 80E40098 */ lwz         r7, 0x98(r4)
  /* 80531188 81040094 */ lwz         r8, 0x94(r4)
  /* 8053118C 91050094 */ stw         r8, 0x94(r5)
  /* 80531190 90E50098 */ stw         r7, 0x98(r5)
  /* 80531194 80E400A0 */ lwz         r7, 0xa0(r4)
  /* 80531198 8104009C */ lwz         r8, 0x9c(r4)
  /* 8053119C 9105009C */ stw         r8, 0x9c(r5)
  /* 805311A0 90E500A0 */ stw         r7, 0xa0(r5)
  /* 805311A4 80E400A8 */ lwz         r7, 0xa8(r4)
  /* 805311A8 810400A4 */ lwz         r8, 0xa4(r4)
  /* 805311AC 910500A4 */ stw         r8, 0xa4(r5)
  /* 805311B0 90E500A8 */ stw         r7, 0xa8(r5)
  /* 805311B4 80E400B0 */ lwz         r7, 0xb0(r4)
  /* 805311B8 810400AC */ lwz         r8, 0xac(r4)
  /* 805311BC 910500AC */ stw         r8, 0xac(r5)
  /* 805311C0 90E500B0 */ stw         r7, 0xb0(r5)
  /* 805311C4 80E400B4 */ lwz         r7, 0xb4(r4)
  /* 805311C8 90E500B4 */ stw         r7, 0xb4(r5)
  /* 805311CC 88E400B8 */ lbz         r7, 0xb8(r4)
  /* 805311D0 98E500B8 */ stb         r7, 0xb8(r5)
  /* 805311D4 88E400B9 */ lbz         r7, 0xb9(r4)
  /* 805311D8 98E500B9 */ stb         r7, 0xb9(r5)
  /* 805311DC 88E400BA */ lbz         r7, 0xba(r4)
  /* 805311E0 98E500BA */ stb         r7, 0xba(r5)
  /* 805311E4 80E400BC */ lwz         r7, 0xbc(r4)
  /* 805311E8 90E500BC */ stw         r7, 0xbc(r5)
  /* 805311EC 88E400C0 */ lbz         r7, 0xc0(r4)
  /* 805311F0 98E500C0 */ stb         r7, 0xc0(r5)
  /* 805311F4 88E400C1 */ lbz         r7, 0xc1(r4)
  /* 805311F8 98E500C1 */ stb         r7, 0xc1(r5)
  /* 805311FC 88E400C2 */ lbz         r7, 0xc2(r4)
  /* 80531200 98E500C2 */ stb         r7, 0xc2(r5)
  /* 80531204 80E400C4 */ lwz         r7, 0xc4(r4)
  /* 80531208 90E500C4 */ stw         r7, 0xc4(r5)
  /* 8053120C 80E400C8 */ lwz         r7, 0xc8(r4)
  /* 80531210 90E500C8 */ stw         r7, 0xc8(r5)
  /* 80531214 80E400CC */ lwz         r7, 0xcc(r4)
  /* 80531218 90E500CC */ stw         r7, 0xcc(r5)
  /* 8053121C 80E400D0 */ lwz         r7, 0xd0(r4)
  /* 80531220 90E500D0 */ stw         r7, 0xd0(r5)
  /* 80531224 80E400D4 */ lwz         r7, 0xd4(r4)
  /* 80531228 90E500D4 */ stw         r7, 0xd4(r5)
  /* 8053122C A0E400D8 */ lhz         r7, 0xd8(r4)
  /* 80531230 B0E500D8 */ sth         r7, 0xd8(r5)
  /* 80531234 A0E400DA */ lhz         r7, 0xda(r4)
  /* 80531238 B0E500DA */ sth         r7, 0xda(r5)
  /* 8053123C A0E400DC */ lhz         r7, 0xdc(r4)
  /* 80531240 B0E500DC */ sth         r7, 0xdc(r5)
  /* 80531244 A8E400DE */ lha         r7, 0xde(r4)
  /* 80531248 B0E500DE */ sth         r7, 0xde(r5)
  /* 8053124C 88E400E0 */ lbz         r7, 0xe0(r4)
  /* 80531250 98E500E0 */ stb         r7, 0xe0(r5)
  /* 80531254 88E400E1 */ lbz         r7, 0xe1(r4)
  /* 80531258 98E500E1 */ stb         r7, 0xe1(r5)
  /* 8053125C 88E400E2 */ lbz         r7, 0xe2(r4)
  /* 80531260 98E500E2 */ stb         r7, 0xe2(r5)
  /* 80531264 A0E400E8 */ lhz         r7, 0xe8(r4)
  /* 80531268 B0E500E8 */ sth         r7, 0xe8(r5)
  /* 8053126C 88E400EC */ lbz         r7, 0xec(r4)
  /* 80531270 388400F0 */ addi        r4, r4, 0xf0
  /* 80531274 98E500EC */ stb         r7, 0xec(r5)
  /* 80531278 38A500F0 */ addi        r5, r5, 0xf0
  /* 8053127C 7C053040 */ cmplw       r5, r6
  /* 80531280 4180FE34 */ blt+        lbl_805310b4
  /* 80531284 82A32348 */ lwz         r21, 0x2348(r3)
  /* 80531288 3800000E */ li          r0, 0xe
  /* 8053128C 83C3234C */ lwz         r30, 0x234c(r3)
  /* 80531290 38C31788 */ addi        r6, r3, 0x1788
  /* 80531294 83A32350 */ lwz         r29, 0x2350(r3)
  /* 80531298 38A32378 */ addi        r5, r3, 0x2378
  /* 8053129C 83832354 */ lwz         r28, 0x2354(r3)
  /* 805312A0 83632358 */ lwz         r27, 0x2358(r3)
  /* 805312A4 8343235C */ lwz         r26, 0x235c(r3)
  /* 805312A8 83232360 */ lwz         r25, 0x2360(r3)
  /* 805312AC 8B032364 */ lbz         r24, 0x2364(r3)
  /* 805312B0 8AE32365 */ lbz         r23, 0x2365(r3)
  /* 805312B4 8AC32366 */ lbz         r22, 0x2366(r3)
  /* 805312B8 89832367 */ lbz         r12, 0x2367(r3)
  /* 805312BC 81632368 */ lwz         r11, 0x2368(r3)
  /* 805312C0 8943236C */ lbz         r10, 0x236c(r3)
  /* 805312C4 8923236D */ lbz         r9, 0x236d(r3)
  /* 805312C8 81032370 */ lwz         r8, 0x2370(r3)
  /* 805312CC 80E32374 */ lwz         r7, 0x2374(r3)
  /* 805312D0 80832378 */ lwz         r4, 0x2378(r3)
  /* 805312D4 92A31758 */ stw         r21, 0x1758(r3)
  /* 805312D8 93C3175C */ stw         r30, 0x175c(r3)
  /* 805312DC 93A31760 */ stw         r29, 0x1760(r3)
  /* 805312E0 93831764 */ stw         r28, 0x1764(r3)
  /* 805312E4 93631768 */ stw         r27, 0x1768(r3)
  /* 805312E8 9343176C */ stw         r26, 0x176c(r3)
  /* 805312EC 93231770 */ stw         r25, 0x1770(r3)
  /* 805312F0 9B031774 */ stb         r24, 0x1774(r3)
  /* 805312F4 9AE31775 */ stb         r23, 0x1775(r3)
  /* 805312F8 9AC31776 */ stb         r22, 0x1776(r3)
  /* 805312FC 99831777 */ stb         r12, 0x1777(r3)
  /* 80531300 91631778 */ stw         r11, 0x1778(r3)
  /* 80531304 9943177C */ stb         r10, 0x177c(r3)
  /* 80531308 9923177D */ stb         r9, 0x177d(r3)
  /* 8053130C 91031780 */ stw         r8, 0x1780(r3)
  /* 80531310 90E31784 */ stw         r7, 0x1784(r3)
  /* 80531314 90831788 */ stw         r4, 0x1788(r3)
  /* 80531318 7C0903A6 */ mtctr       r0
  lbl_8053131c:
  /* 8053131C 80850004 */ lwz         r4, 4(r5)
  /* 80531320 84050008 */ lwzu        r0, 8(r5)
  /* 80531324 90860004 */ stw         r4, 4(r6)
  /* 80531328 94060008 */ stwu        r0, 8(r6)
  /* 8053132C 4200FFF0 */ bdnz        lbl_8053131c
  /* 80531330 800323EC */ lwz         r0, 0x23ec(r3)
  /* 80531334 389F0020 */ addi        r4, r31, 0x20
  /* 80531338 900317FC */ stw         r0, 0x17fc(r3)
  /* 8053133C 38630C10 */ addi        r3, r3, 0xc10
  /* 80531340 4BFFE851 */ bl          initRace__Q26System18RaceConfigScenarioFPQ26System18RaceConfigScenario
  /* 80531344 893F0C14 */ lbz         r9, 0xc14(r31)
  /* 80531348 387F0028 */ addi        r3, r31, 0x28
  /* 8053134C 891F0C15 */ lbz         r8, 0xc15(r31)
  /* 80531350 389F0C18 */ addi        r4, r31, 0xc18
  /* 80531354 88FF0C16 */ lbz         r7, 0xc16(r31)
  /* 80531358 38BF0B68 */ addi        r5, r31, 0xb68
  /* 8053135C 88DF0C17 */ lbz         r6, 0xc17(r31)
  /* 80531360 38000026 */ li          r0, 0x26
  /* 80531364 993F0024 */ stb         r9, 0x24(r31)
  /* 80531368 991F0025 */ stb         r8, 0x25(r31)
  /* 8053136C 98FF0026 */ stb         r7, 0x26(r31)
  /* 80531370 98DF0027 */ stb         r6, 0x27(r31)
  lbl_80531374:
  /* 80531374 88C40004 */ lbz         r6, 4(r4)
  /* 80531378 39230023 */ addi        r9, r3, 0x23
  /* 8053137C 98C30004 */ stb         r6, 4(r3)
  /* 80531380 39040023 */ addi        r8, r4, 0x23
  /* 80531384 88C40005 */ lbz         r6, 5(r4)
  /* 80531388 98C30005 */ stb         r6, 5(r3)
  /* 8053138C 88C40006 */ lbz         r6, 6(r4)
  /* 80531390 98C30006 */ stb         r6, 6(r3)
  /* 80531394 80C40008 */ lwz         r6, 8(r4)
  /* 80531398 90C30008 */ stw         r6, 8(r3)
  /* 8053139C 80C4000C */ lwz         r6, 0xc(r4)
  /* 805313A0 90C3000C */ stw         r6, 0xc(r3)
  /* 805313A4 80C40010 */ lwz         r6, 0x10(r4)
  /* 805313A8 90C30010 */ stw         r6, 0x10(r3)
  /* 805313AC 80C40018 */ lwz         r6, 0x18(r4)
  /* 805313B0 90C30018 */ stw         r6, 0x18(r3)
  /* 805313B4 88C4001C */ lbz         r6, 0x1c(r4)
  /* 805313B8 98C3001C */ stb         r6, 0x1c(r3)
  /* 805313BC 88C4001D */ lbz         r6, 0x1d(r4)
  /* 805313C0 98C3001D */ stb         r6, 0x1d(r3)
  /* 805313C4 80C40020 */ lwz         r6, 0x20(r4)
  /* 805313C8 90C30020 */ stw         r6, 0x20(r3)
  /* 805313CC 7C0903A6 */ mtctr       r0
  lbl_805313d0:
  /* 805313D0 88E80001 */ lbz         r7, 1(r8)
  /* 805313D4 8CC80002 */ lbzu        r6, 2(r8)
  /* 805313D8 98E90001 */ stb         r7, 1(r9)
  /* 805313DC 9CC90002 */ stbu        r6, 2(r9)
  /* 805313E0 4200FFF0 */ bdnz        lbl_805313d0
  /* 805313E4 80C40070 */ lwz         r6, 0x70(r4)
  /* 805313E8 90C30070 */ stw         r6, 0x70(r3)
  /* 805313EC 88C40074 */ lbz         r6, 0x74(r4)
  /* 805313F0 98C30074 */ stb         r6, 0x74(r3)
  /* 805313F4 88C40075 */ lbz         r6, 0x75(r4)
  /* 805313F8 98C30075 */ stb         r6, 0x75(r3)
  /* 805313FC 88C40076 */ lbz         r6, 0x76(r4)
  /* 80531400 98C30076 */ stb         r6, 0x76(r3)
  /* 80531404 88C40077 */ lbz         r6, 0x77(r4)
  /* 80531408 98C30077 */ stb         r6, 0x77(r3)
  /* 8053140C 80C40078 */ lwz         r6, 0x78(r4)
  /* 80531410 90C30078 */ stw         r6, 0x78(r3)
  /* 80531414 80C40080 */ lwz         r6, 0x80(r4)
  /* 80531418 80E4007C */ lwz         r7, 0x7c(r4)
  /* 8053141C 90E3007C */ stw         r7, 0x7c(r3)
  /* 80531420 90C30080 */ stw         r6, 0x80(r3)
  /* 80531424 80C40088 */ lwz         r6, 0x88(r4)
  /* 80531428 80E40084 */ lwz         r7, 0x84(r4)
  /* 8053142C 90E30084 */ stw         r7, 0x84(r3)
  /* 80531430 90C30088 */ stw         r6, 0x88(r3)
  /* 80531434 80C40090 */ lwz         r6, 0x90(r4)
  /* 80531438 80E4008C */ lwz         r7, 0x8c(r4)
  /* 8053143C 90E3008C */ stw         r7, 0x8c(r3)
  /* 80531440 90C30090 */ stw         r6, 0x90(r3)
  /* 80531444 80C40098 */ lwz         r6, 0x98(r4)
  /* 80531448 80E40094 */ lwz         r7, 0x94(r4)
  /* 8053144C 90E30094 */ stw         r7, 0x94(r3)
  /* 80531450 90C30098 */ stw         r6, 0x98(r3)
  /* 80531454 80C400A0 */ lwz         r6, 0xa0(r4)
  /* 80531458 80E4009C */ lwz         r7, 0x9c(r4)
  /* 8053145C 90E3009C */ stw         r7, 0x9c(r3)
  /* 80531460 90C300A0 */ stw         r6, 0xa0(r3)
  /* 80531464 80C400A8 */ lwz         r6, 0xa8(r4)
  /* 80531468 80E400A4 */ lwz         r7, 0xa4(r4)
  /* 8053146C 90E300A4 */ stw         r7, 0xa4(r3)
  /* 80531470 90C300A8 */ stw         r6, 0xa8(r3)
  /* 80531474 80C400B0 */ lwz         r6, 0xb0(r4)
  /* 80531478 80E400AC */ lwz         r7, 0xac(r4)
  /* 8053147C 90E300AC */ stw         r7, 0xac(r3)
  /* 80531480 90C300B0 */ stw         r6, 0xb0(r3)
  /* 80531484 80C400B4 */ lwz         r6, 0xb4(r4)
  /* 80531488 90C300B4 */ stw         r6, 0xb4(r3)
  /* 8053148C 88C400B8 */ lbz         r6, 0xb8(r4)
  /* 80531490 98C300B8 */ stb         r6, 0xb8(r3)
  /* 80531494 88C400B9 */ lbz         r6, 0xb9(r4)
  /* 80531498 98C300B9 */ stb         r6, 0xb9(r3)
  /* 8053149C 88C400BA */ lbz         r6, 0xba(r4)
  /* 805314A0 98C300BA */ stb         r6, 0xba(r3)
  /* 805314A4 80C400BC */ lwz         r6, 0xbc(r4)
  /* 805314A8 90C300BC */ stw         r6, 0xbc(r3)
  /* 805314AC 88C400C0 */ lbz         r6, 0xc0(r4)
  /* 805314B0 98C300C0 */ stb         r6, 0xc0(r3)
  /* 805314B4 88C400C1 */ lbz         r6, 0xc1(r4)
  /* 805314B8 98C300C1 */ stb         r6, 0xc1(r3)
  /* 805314BC 88C400C2 */ lbz         r6, 0xc2(r4)
  /* 805314C0 98C300C2 */ stb         r6, 0xc2(r3)
  /* 805314C4 80C400C4 */ lwz         r6, 0xc4(r4)
  /* 805314C8 90C300C4 */ stw         r6, 0xc4(r3)
  /* 805314CC 80C400C8 */ lwz         r6, 0xc8(r4)
  /* 805314D0 90C300C8 */ stw         r6, 0xc8(r3)
  /* 805314D4 80C400CC */ lwz         r6, 0xcc(r4)
  /* 805314D8 90C300CC */ stw         r6, 0xcc(r3)
  /* 805314DC 80C400D0 */ lwz         r6, 0xd0(r4)
  /* 805314E0 90C300D0 */ stw         r6, 0xd0(r3)
  /* 805314E4 80C400D4 */ lwz         r6, 0xd4(r4)
  /* 805314E8 90C300D4 */ stw         r6, 0xd4(r3)
  /* 805314EC A0C400D8 */ lhz         r6, 0xd8(r4)
  /* 805314F0 B0C300D8 */ sth         r6, 0xd8(r3)
  /* 805314F4 A0C400DA */ lhz         r6, 0xda(r4)
  /* 805314F8 B0C300DA */ sth         r6, 0xda(r3)
  /* 805314FC A0C400DC */ lhz         r6, 0xdc(r4)
  /* 80531500 B0C300DC */ sth         r6, 0xdc(r3)
  /* 80531504 A8C400DE */ lha         r6, 0xde(r4)
  /* 80531508 B0C300DE */ sth         r6, 0xde(r3)
  /* 8053150C 88C400E0 */ lbz         r6, 0xe0(r4)
  /* 80531510 98C300E0 */ stb         r6, 0xe0(r3)
  /* 80531514 88C400E1 */ lbz         r6, 0xe1(r4)
  /* 80531518 98C300E1 */ stb         r6, 0xe1(r3)
  /* 8053151C 88C400E2 */ lbz         r6, 0xe2(r4)
  /* 80531520 98C300E2 */ stb         r6, 0xe2(r3)
  /* 80531524 A0C400E8 */ lhz         r6, 0xe8(r4)
  /* 80531528 B0C300E8 */ sth         r6, 0xe8(r3)
  /* 8053152C 88C400EC */ lbz         r6, 0xec(r4)
  /* 80531530 388400F0 */ addi        r4, r4, 0xf0
  /* 80531534 98C300EC */ stb         r6, 0xec(r3)
  /* 80531538 386300F0 */ addi        r3, r3, 0xf0
  /* 8053153C 7C032840 */ cmplw       r3, r5
  /* 80531540 4180FE34 */ blt+        lbl_80531374
  /* 80531544 83DF1758 */ lwz         r30, 0x1758(r31)
  /* 80531548 3800000E */ li          r0, 0xe
  /* 8053154C 83BF175C */ lwz         r29, 0x175c(r31)
  /* 80531550 38BF0B98 */ addi        r5, r31, 0xb98
  /* 80531554 839F1760 */ lwz         r28, 0x1760(r31)
  /* 80531558 389F1788 */ addi        r4, r31, 0x1788
  /* 8053155C 837F1764 */ lwz         r27, 0x1764(r31)
  /* 80531560 835F1768 */ lwz         r26, 0x1768(r31)
  /* 80531564 833F176C */ lwz         r25, 0x176c(r31)
  /* 80531568 831F1770 */ lwz         r24, 0x1770(r31)
  /* 8053156C 8AFF1774 */ lbz         r23, 0x1774(r31)
  /* 80531570 8ADF1775 */ lbz         r22, 0x1775(r31)
  /* 80531574 899F1776 */ lbz         r12, 0x1776(r31)
  /* 80531578 897F1777 */ lbz         r11, 0x1777(r31)
  /* 8053157C 815F1778 */ lwz         r10, 0x1778(r31)
  /* 80531580 893F177C */ lbz         r9, 0x177c(r31)
  /* 80531584 891F177D */ lbz         r8, 0x177d(r31)
  /* 80531588 80FF1780 */ lwz         r7, 0x1780(r31)
  /* 8053158C 80DF1784 */ lwz         r6, 0x1784(r31)
  /* 80531590 807F1788 */ lwz         r3, 0x1788(r31)
  /* 80531594 93DF0B68 */ stw         r30, 0xb68(r31)
  /* 80531598 93BF0B6C */ stw         r29, 0xb6c(r31)
  /* 8053159C 939F0B70 */ stw         r28, 0xb70(r31)
  /* 805315A0 937F0B74 */ stw         r27, 0xb74(r31)
  /* 805315A4 935F0B78 */ stw         r26, 0xb78(r31)
  /* 805315A8 933F0B7C */ stw         r25, 0xb7c(r31)
  /* 805315AC 931F0B80 */ stw         r24, 0xb80(r31)
  /* 805315B0 9AFF0B84 */ stb         r23, 0xb84(r31)
  /* 805315B4 9ADF0B85 */ stb         r22, 0xb85(r31)
  /* 805315B8 999F0B86 */ stb         r12, 0xb86(r31)
  /* 805315BC 997F0B87 */ stb         r11, 0xb87(r31)
  /* 805315C0 915F0B88 */ stw         r10, 0xb88(r31)
  /* 805315C4 993F0B8C */ stb         r9, 0xb8c(r31)
  /* 805315C8 991F0B8D */ stb         r8, 0xb8d(r31)
  /* 805315CC 90FF0B90 */ stw         r7, 0xb90(r31)
  /* 805315D0 90DF0B94 */ stw         r6, 0xb94(r31)
  /* 805315D4 907F0B98 */ stw         r3, 0xb98(r31)
  /* 805315D8 7C0903A6 */ mtctr       r0
  lbl_805315dc:
  /* 805315DC 80640004 */ lwz         r3, 4(r4)
  /* 805315E0 84040008 */ lwzu        r0, 8(r4)
  /* 805315E4 90650004 */ stw         r3, 4(r5)
  /* 805315E8 94050008 */ stwu        r0, 8(r5)
  /* 805315EC 4200FFF0 */ bdnz        lbl_805315dc
  /* 805315F0 80BF17FC */ lwz         r5, 0x17fc(r31)
  /* 805315F4 38000002 */ li          r0, 0x2
  /* 805315F8 3880000C */ li          r4, 0xc
  /* 805315FC 3860003A */ li          r3, 0x3a
  /* 80531600 90BF0C0C */ stw         r5, 0xc0c(r31)
  /* 80531604 39600000 */ li          r11, 0x0
  /* 80531608 39000005 */ li          r8, 0x5
  /* 8053160C 909F1760 */ stw         r4, 0x1760(r31)
  /* 80531610 907F1758 */ stw         r3, 0x1758(r31)
  /* 80531614 7C0903A6 */ mtctr       r0
  lbl_80531618:
  /* 80531618 5565063E */ clrlwi      r5, r11, 0x18
  /* 8053161C 380B0002 */ addi        r0, r11, 0x2
  /* 80531620 1C8500F0 */ mulli       r4, r5, 0xf0
  /* 80531624 386B0001 */ addi        r3, r11, 0x1
  /* 80531628 5406063E */ clrlwi      r6, r0, 0x18
  /* 8053162C 5467063E */ clrlwi      r7, r3, 0x18
  /* 80531630 7D3F2214 */ add         r9, r31, r4
  /* 80531634 386B0004 */ addi        r3, r11, 0x4
  /* 80531638 91090C28 */ stw         r8, 0xc28(r9)
  /* 8053163C 39450001 */ addi        r10, r5, 0x1
  /* 80531640 380B0003 */ addi        r0, r11, 0x3
  /* 80531644 5464063E */ clrlwi      r4, r3, 0x18
  /* 80531648 99490CF9 */ stb         r10, 0xcf9(r9)
  /* 8053164C 5405063E */ clrlwi      r5, r0, 0x18
  /* 80531650 380B0005 */ addi        r0, r11, 0x5
  /* 80531654 38C60001 */ addi        r6, r6, 0x1
  /* 80531658 99490CF8 */ stb         r10, 0xcf8(r9)
  /* 8053165C 5403063E */ clrlwi      r3, r0, 0x18
  /* 80531660 38070001 */ addi        r0, r7, 0x1
  /* 80531664 38A50001 */ addi        r5, r5, 0x1
  /* 80531668 91090D18 */ stw         r8, 0xd18(r9)
  /* 8053166C 38840001 */ addi        r4, r4, 0x1
  /* 80531670 38630001 */ addi        r3, r3, 0x1
  /* 80531674 396B0006 */ addi        r11, r11, 0x6
  /* 80531678 98090DE9 */ stb         r0, 0xde9(r9)
  /* 8053167C 98090DE8 */ stb         r0, 0xde8(r9)
  /* 80531680 91090E08 */ stw         r8, 0xe08(r9)
  /* 80531684 98C90ED9 */ stb         r6, 0xed9(r9)
  /* 80531688 98C90ED8 */ stb         r6, 0xed8(r9)
  /* 8053168C 91090EF8 */ stw         r8, 0xef8(r9)
  /* 80531690 98A90FC9 */ stb         r5, 0xfc9(r9)
  /* 80531694 98A90FC8 */ stb         r5, 0xfc8(r9)
  /* 80531698 91090FE8 */ stw         r8, 0xfe8(r9)
  /* 8053169C 988910B9 */ stb         r4, 0x10b9(r9)
  /* 805316A0 988910B8 */ stb         r4, 0x10b8(r9)
  /* 805316A4 910910D8 */ stw         r8, 0x10d8(r9)
  /* 805316A8 986911A9 */ stb         r3, 0x11a9(r9)
  /* 805316AC 986911A8 */ stb         r3, 0x11a8(r9)
  /* 805316B0 4200FF68 */ bdnz        lbl_80531618
  /* 805316B4 39000000 */ li          r8, 0x0
  /* 805316B8 38E00000 */ li          r7, 0x0
  /* 805316BC 38600001 */ li          r3, 0x1
  /* 805316C0 38000026 */ li          r0, 0x26
  /* 805316C4 3CC0809C */ lis         r6, spInstance__Q26System10RaceConfig@ha
  lbl_805316c8:
  /* 805316C8 54E5063E */ clrlwi      r5, r7, 0x18
  /* 805316CC 8086D728 */ lwz         r4, spInstance__Q26System10RaceConfig@l(r6)
  /* 805316D0 1CA500F0 */ mulli       r5, r5, 0xf0
  /* 805316D4 7C842A14 */ add         r4, r4, r5
  /* 805316D8 80840038 */ lwz         r4, 0x38(r4)
  /* 805316DC 2C040000 */ cmpwi       r4, 0x0
  /* 805316E0 40820168 */ bne-        lbl_80531848
  /* 805316E4 550A063E */ clrlwi      r10, r8, 0x18
  /* 805316E8 7CBF2A14 */ add         r5, r31, r5
  /* 805316EC 1C8A00F0 */ mulli       r4, r10, 0xf0
  /* 805316F0 81250034 */ lwz         r9, 0x34(r5)
  /* 805316F4 394A0001 */ addi        r10, r10, 0x1
  /* 805316F8 3965004B */ addi        r11, r5, 0x4b
  /* 805316FC 7C9F2214 */ add         r4, r31, r4
  /* 80531700 91240C24 */ stw         r9, 0xc24(r4)
  /* 80531704 39840C3B */ addi        r12, r4, 0xc3b
  /* 80531708 81250030 */ lwz         r9, 0x30(r5)
  /* 8053170C 91240C20 */ stw         r9, 0xc20(r4)
  /* 80531710 99440CF9 */ stb         r10, 0xcf9(r4)
  /* 80531714 99440CF8 */ stb         r10, 0xcf8(r4)
  /* 80531718 90640C28 */ stw         r3, 0xc28(r4)
  /* 8053171C 81250040 */ lwz         r9, 0x40(r5)
  /* 80531720 91240C30 */ stw         r9, 0xc30(r4)
  /* 80531724 89250044 */ lbz         r9, 0x44(r5)
  /* 80531728 99240C34 */ stb         r9, 0xc34(r4)
  /* 8053172C 89250045 */ lbz         r9, 0x45(r5)
  /* 80531730 99240C35 */ stb         r9, 0xc35(r4)
  /* 80531734 81250048 */ lwz         r9, 0x48(r5)
  /* 80531738 91240C38 */ stw         r9, 0xc38(r4)
  /* 8053173C 7C0903A6 */ mtctr       r0
  lbl_80531740:
  /* 80531740 894B0001 */ lbz         r10, 1(r11)
  /* 80531744 8D2B0002 */ lbzu        r9, 2(r11)
  /* 80531748 994C0001 */ stb         r10, 1(r12)
  /* 8053174C 9D2C0002 */ stbu        r9, 2(r12)
  /* 80531750 4200FFF0 */ bdnz        lbl_80531740
  /* 80531754 81250098 */ lwz         r9, 0x98(r5)
  /* 80531758 39080001 */ addi        r8, r8, 0x1
  /* 8053175C 91240C88 */ stw         r9, 0xc88(r4)
  /* 80531760 8925009C */ lbz         r9, 0x9c(r5)
  /* 80531764 99240C8C */ stb         r9, 0xc8c(r4)
  /* 80531768 8925009D */ lbz         r9, 0x9d(r5)
  /* 8053176C 99240C8D */ stb         r9, 0xc8d(r4)
  /* 80531770 8925009E */ lbz         r9, 0x9e(r5)
  /* 80531774 99240C8E */ stb         r9, 0xc8e(r4)
  /* 80531778 8925009F */ lbz         r9, 0x9f(r5)
  /* 8053177C 99240C8F */ stb         r9, 0xc8f(r4)
  /* 80531780 812500A0 */ lwz         r9, 0xa0(r5)
  /* 80531784 91240C90 */ stw         r9, 0xc90(r4)
  /* 80531788 812500A8 */ lwz         r9, 0xa8(r5)
  /* 8053178C 814500A4 */ lwz         r10, 0xa4(r5)
  /* 80531790 91440C94 */ stw         r10, 0xc94(r4)
  /* 80531794 91240C98 */ stw         r9, 0xc98(r4)
  /* 80531798 812500B0 */ lwz         r9, 0xb0(r5)
  /* 8053179C 814500AC */ lwz         r10, 0xac(r5)
  /* 805317A0 91440C9C */ stw         r10, 0xc9c(r4)
  /* 805317A4 91240CA0 */ stw         r9, 0xca0(r4)
  /* 805317A8 812500B8 */ lwz         r9, 0xb8(r5)
  /* 805317AC 814500B4 */ lwz         r10, 0xb4(r5)
  /* 805317B0 91440CA4 */ stw         r10, 0xca4(r4)
  /* 805317B4 91240CA8 */ stw         r9, 0xca8(r4)
  /* 805317B8 812500C0 */ lwz         r9, 0xc0(r5)
  /* 805317BC 814500BC */ lwz         r10, 0xbc(r5)
  /* 805317C0 91440CAC */ stw         r10, 0xcac(r4)
  /* 805317C4 91240CB0 */ stw         r9, 0xcb0(r4)
  /* 805317C8 812500C8 */ lwz         r9, 0xc8(r5)
  /* 805317CC 814500C4 */ lwz         r10, 0xc4(r5)
  /* 805317D0 91440CB4 */ stw         r10, 0xcb4(r4)
  /* 805317D4 91240CB8 */ stw         r9, 0xcb8(r4)
  /* 805317D8 812500D0 */ lwz         r9, 0xd0(r5)
  /* 805317DC 814500CC */ lwz         r10, 0xcc(r5)
  /* 805317E0 91440CBC */ stw         r10, 0xcbc(r4)
  /* 805317E4 91240CC0 */ stw         r9, 0xcc0(r4)
  /* 805317E8 812500D8 */ lwz         r9, 0xd8(r5)
  /* 805317EC 814500D4 */ lwz         r10, 0xd4(r5)
  /* 805317F0 91440CC4 */ stw         r10, 0xcc4(r4)
  /* 805317F4 91240CC8 */ stw         r9, 0xcc8(r4)
  /* 805317F8 812500DC */ lwz         r9, 0xdc(r5)
  /* 805317FC 91240CCC */ stw         r9, 0xccc(r4)
  /* 80531800 892500E0 */ lbz         r9, 0xe0(r5)
  /* 80531804 99240CD0 */ stb         r9, 0xcd0(r4)
  /* 80531808 892500E1 */ lbz         r9, 0xe1(r5)
  /* 8053180C 99240CD1 */ stb         r9, 0xcd1(r4)
  /* 80531810 892500E2 */ lbz         r9, 0xe2(r5)
  /* 80531814 99240CD2 */ stb         r9, 0xcd2(r4)
  /* 80531818 812500E4 */ lwz         r9, 0xe4(r5)
  /* 8053181C 91240CD4 */ stw         r9, 0xcd4(r4)
  /* 80531820 892500E8 */ lbz         r9, 0xe8(r5)
  /* 80531824 99240CD8 */ stb         r9, 0xcd8(r4)
  /* 80531828 892500E9 */ lbz         r9, 0xe9(r5)
  /* 8053182C 99240CD9 */ stb         r9, 0xcd9(r4)
  /* 80531830 892500EA */ lbz         r9, 0xea(r5)
  /* 80531834 99240CDA */ stb         r9, 0xcda(r4)
  /* 80531838 812500EC */ lwz         r9, 0xec(r5)
  /* 8053183C 91240CDC */ stw         r9, 0xcdc(r4)
  /* 80531840 80A500F0 */ lwz         r5, 0xf0(r5)
  /* 80531844 90A40CE0 */ stw         r5, 0xce0(r4)
  lbl_80531848:
  /* 80531848 38E70001 */ addi        r7, r7, 0x1
  /* 8053184C 2807000C */ cmplwi      r7, 0xc
  /* 80531850 4180FE78 */ blt+        lbl_805316c8
  /* 80531854 39200001 */ li          r9, 0x1
  /* 80531858 38600001 */ li          r3, 0x1
  /* 8053185C 38000026 */ li          r0, 0x26
  /* 80531860 3CE0809C */ lis         r7, spInstance__Q26System10RaceConfig@ha
  lbl_80531864:
  /* 80531864 5526063E */ clrlwi      r6, r9, 0x18
  /* 80531868 39400000 */ li          r10, 0x0
  lbl_8053186c:
  /* 8053186C 5545063E */ clrlwi      r5, r10, 0x18
  /* 80531870 8087D728 */ lwz         r4, spInstance__Q26System10RaceConfig@l(r7)
  /* 80531874 1D6500F0 */ mulli       r11, r5, 0xf0
  /* 80531878 7CA45A14 */ add         r5, r4, r11
  /* 8053187C 88850108 */ lbz         r4, 0x108(r5)
  /* 80531880 7C062040 */ cmplw       r6, r4
  /* 80531884 40820174 */ bne-        lbl_805319f8
  /* 80531888 80850038 */ lwz         r4, 0x38(r5)
  /* 8053188C 2C040000 */ cmpwi       r4, 0x0
  /* 80531890 41820168 */ beq-        lbl_805319f8
  /* 80531894 550C063E */ clrlwi      r12, r8, 0x18
  /* 80531898 7CBF5A14 */ add         r5, r31, r11
  /* 8053189C 1C8C00F0 */ mulli       r4, r12, 0xf0
  /* 805318A0 81650034 */ lwz         r11, 0x34(r5)
  /* 805318A4 398C0001 */ addi        r12, r12, 0x1
  /* 805318A8 3AC5004B */ addi        r22, r5, 0x4b
  /* 805318AC 7C9F2214 */ add         r4, r31, r4
  /* 805318B0 91640C24 */ stw         r11, 0xc24(r4)
  /* 805318B4 3AE40C3B */ addi        r23, r4, 0xc3b
  /* 805318B8 81650030 */ lwz         r11, 0x30(r5)
  /* 805318BC 91640C20 */ stw         r11, 0xc20(r4)
  /* 805318C0 99840CF9 */ stb         r12, 0xcf9(r4)
  /* 805318C4 99840CF8 */ stb         r12, 0xcf8(r4)
  /* 805318C8 90640C28 */ stw         r3, 0xc28(r4)
  /* 805318CC 81650040 */ lwz         r11, 0x40(r5)
  /* 805318D0 91640C30 */ stw         r11, 0xc30(r4)
  /* 805318D4 89650044 */ lbz         r11, 0x44(r5)
  /* 805318D8 99640C34 */ stb         r11, 0xc34(r4)
  /* 805318DC 89650045 */ lbz         r11, 0x45(r5)
  /* 805318E0 99640C35 */ stb         r11, 0xc35(r4)
  /* 805318E4 81650048 */ lwz         r11, 0x48(r5)
  /* 805318E8 91640C38 */ stw         r11, 0xc38(r4)
  /* 805318EC 7C0903A6 */ mtctr       r0
  lbl_805318f0:
  /* 805318F0 89960001 */ lbz         r12, 1(r22)
  /* 805318F4 8D760002 */ lbzu        r11, 2(r22)
  /* 805318F8 99970001 */ stb         r12, 1(r23)
  /* 805318FC 9D770002 */ stbu        r11, 2(r23)
  /* 80531900 4200FFF0 */ bdnz        lbl_805318f0
  /* 80531904 81650098 */ lwz         r11, 0x98(r5)
  /* 80531908 39080001 */ addi        r8, r8, 0x1
  /* 8053190C 91640C88 */ stw         r11, 0xc88(r4)
  /* 80531910 8965009C */ lbz         r11, 0x9c(r5)
  /* 80531914 99640C8C */ stb         r11, 0xc8c(r4)
  /* 80531918 8965009D */ lbz         r11, 0x9d(r5)
  /* 8053191C 99640C8D */ stb         r11, 0xc8d(r4)
  /* 80531920 8965009E */ lbz         r11, 0x9e(r5)
  /* 80531924 99640C8E */ stb         r11, 0xc8e(r4)
  /* 80531928 8965009F */ lbz         r11, 0x9f(r5)
  /* 8053192C 99640C8F */ stb         r11, 0xc8f(r4)
  /* 80531930 816500A0 */ lwz         r11, 0xa0(r5)
  /* 80531934 91640C90 */ stw         r11, 0xc90(r4)
  /* 80531938 816500A8 */ lwz         r11, 0xa8(r5)
  /* 8053193C 818500A4 */ lwz         r12, 0xa4(r5)
  /* 80531940 91840C94 */ stw         r12, 0xc94(r4)
  /* 80531944 91640C98 */ stw         r11, 0xc98(r4)
  /* 80531948 816500B0 */ lwz         r11, 0xb0(r5)
  /* 8053194C 818500AC */ lwz         r12, 0xac(r5)
  /* 80531950 91840C9C */ stw         r12, 0xc9c(r4)
  /* 80531954 91640CA0 */ stw         r11, 0xca0(r4)
  /* 80531958 816500B8 */ lwz         r11, 0xb8(r5)
  /* 8053195C 818500B4 */ lwz         r12, 0xb4(r5)
  /* 80531960 91840CA4 */ stw         r12, 0xca4(r4)
  /* 80531964 91640CA8 */ stw         r11, 0xca8(r4)
  /* 80531968 816500C0 */ lwz         r11, 0xc0(r5)
  /* 8053196C 818500BC */ lwz         r12, 0xbc(r5)
  /* 80531970 91840CAC */ stw         r12, 0xcac(r4)
  /* 80531974 91640CB0 */ stw         r11, 0xcb0(r4)
  /* 80531978 816500C8 */ lwz         r11, 0xc8(r5)
  /* 8053197C 818500C4 */ lwz         r12, 0xc4(r5)
  /* 80531980 91840CB4 */ stw         r12, 0xcb4(r4)
  /* 80531984 91640CB8 */ stw         r11, 0xcb8(r4)
  /* 80531988 816500D0 */ lwz         r11, 0xd0(r5)
  /* 8053198C 818500CC */ lwz         r12, 0xcc(r5)
  /* 80531990 91840CBC */ stw         r12, 0xcbc(r4)
  /* 80531994 91640CC0 */ stw         r11, 0xcc0(r4)
  /* 80531998 816500D8 */ lwz         r11, 0xd8(r5)
  /* 8053199C 818500D4 */ lwz         r12, 0xd4(r5)
  /* 805319A0 91840CC4 */ stw         r12, 0xcc4(r4)
  /* 805319A4 91640CC8 */ stw         r11, 0xcc8(r4)
  /* 805319A8 816500DC */ lwz         r11, 0xdc(r5)
  /* 805319AC 91640CCC */ stw         r11, 0xccc(r4)
  /* 805319B0 896500E0 */ lbz         r11, 0xe0(r5)
  /* 805319B4 99640CD0 */ stb         r11, 0xcd0(r4)
  /* 805319B8 896500E1 */ lbz         r11, 0xe1(r5)
  /* 805319BC 99640CD1 */ stb         r11, 0xcd1(r4)
  /* 805319C0 896500E2 */ lbz         r11, 0xe2(r5)
  /* 805319C4 99640CD2 */ stb         r11, 0xcd2(r4)
  /* 805319C8 816500E4 */ lwz         r11, 0xe4(r5)
  /* 805319CC 91640CD4 */ stw         r11, 0xcd4(r4)
  /* 805319D0 896500E8 */ lbz         r11, 0xe8(r5)
  /* 805319D4 99640CD8 */ stb         r11, 0xcd8(r4)
  /* 805319D8 896500E9 */ lbz         r11, 0xe9(r5)
  /* 805319DC 99640CD9 */ stb         r11, 0xcd9(r4)
  /* 805319E0 896500EA */ lbz         r11, 0xea(r5)
  /* 805319E4 99640CDA */ stb         r11, 0xcda(r4)
  /* 805319E8 816500EC */ lwz         r11, 0xec(r5)
  /* 805319EC 91640CDC */ stw         r11, 0xcdc(r4)
  /* 805319F0 80A500F0 */ lwz         r5, 0xf0(r5)
  /* 805319F4 90A40CE0 */ stw         r5, 0xce0(r4)
  lbl_805319f8:
  /* 805319F8 394A0001 */ addi        r10, r10, 0x1
  /* 805319FC 280A000C */ cmplwi      r10, 0xc
  /* 80531A00 4180FE6C */ blt+        lbl_8053186c
  /* 80531A04 39290001 */ addi        r9, r9, 0x1
  /* 80531A08 2809000C */ cmplwi      r9, 0xc
  /* 80531A0C 4081FE58 */ ble+        lbl_80531864
  /* 80531A10 387F0C10 */ addi        r3, r31, 0xc10
  /* 80531A14 389F0020 */ addi        r4, r31, 0x20
  /* 80531A18 4BFFE179 */ bl          initRace__Q26System18RaceConfigScenarioFPQ26System18RaceConfigScenario
  /* 80531A1C 893F0C14 */ lbz         r9, 0xc14(r31)
  /* 80531A20 387F0028 */ addi        r3, r31, 0x28
  /* 80531A24 891F0C15 */ lbz         r8, 0xc15(r31)
  /* 80531A28 389F0C18 */ addi        r4, r31, 0xc18
  /* 80531A2C 88FF0C16 */ lbz         r7, 0xc16(r31)
  /* 80531A30 38BF0B68 */ addi        r5, r31, 0xb68
  /* 80531A34 88DF0C17 */ lbz         r6, 0xc17(r31)
  /* 80531A38 38000026 */ li          r0, 0x26
  /* 80531A3C 993F0024 */ stb         r9, 0x24(r31)
  /* 80531A40 991F0025 */ stb         r8, 0x25(r31)
  /* 80531A44 98FF0026 */ stb         r7, 0x26(r31)
  /* 80531A48 98DF0027 */ stb         r6, 0x27(r31)
  lbl_80531a4c:
  /* 80531A4C 88C40004 */ lbz         r6, 4(r4)
  /* 80531A50 39230023 */ addi        r9, r3, 0x23
  /* 80531A54 98C30004 */ stb         r6, 4(r3)
  /* 80531A58 39040023 */ addi        r8, r4, 0x23
  /* 80531A5C 88C40005 */ lbz         r6, 5(r4)
  /* 80531A60 98C30005 */ stb         r6, 5(r3)
  /* 80531A64 88C40006 */ lbz         r6, 6(r4)
  /* 80531A68 98C30006 */ stb         r6, 6(r3)
  /* 80531A6C 80C40008 */ lwz         r6, 8(r4)
  /* 80531A70 90C30008 */ stw         r6, 8(r3)
  /* 80531A74 80C4000C */ lwz         r6, 0xc(r4)
  /* 80531A78 90C3000C */ stw         r6, 0xc(r3)
  /* 80531A7C 80C40010 */ lwz         r6, 0x10(r4)
  /* 80531A80 90C30010 */ stw         r6, 0x10(r3)
  /* 80531A84 80C40018 */ lwz         r6, 0x18(r4)
  /* 80531A88 90C30018 */ stw         r6, 0x18(r3)
  /* 80531A8C 88C4001C */ lbz         r6, 0x1c(r4)
  /* 80531A90 98C3001C */ stb         r6, 0x1c(r3)
  /* 80531A94 88C4001D */ lbz         r6, 0x1d(r4)
  /* 80531A98 98C3001D */ stb         r6, 0x1d(r3)
  /* 80531A9C 80C40020 */ lwz         r6, 0x20(r4)
  /* 80531AA0 90C30020 */ stw         r6, 0x20(r3)
  /* 80531AA4 7C0903A6 */ mtctr       r0
  lbl_80531aa8:
  /* 80531AA8 88E80001 */ lbz         r7, 1(r8)
  /* 80531AAC 8CC80002 */ lbzu        r6, 2(r8)
  /* 80531AB0 98E90001 */ stb         r7, 1(r9)
  /* 80531AB4 9CC90002 */ stbu        r6, 2(r9)
  /* 80531AB8 4200FFF0 */ bdnz        lbl_80531aa8
  /* 80531ABC 80C40070 */ lwz         r6, 0x70(r4)
  /* 80531AC0 90C30070 */ stw         r6, 0x70(r3)
  /* 80531AC4 88C40074 */ lbz         r6, 0x74(r4)
  /* 80531AC8 98C30074 */ stb         r6, 0x74(r3)
  /* 80531ACC 88C40075 */ lbz         r6, 0x75(r4)
  /* 80531AD0 98C30075 */ stb         r6, 0x75(r3)
  /* 80531AD4 88C40076 */ lbz         r6, 0x76(r4)
  /* 80531AD8 98C30076 */ stb         r6, 0x76(r3)
  /* 80531ADC 88C40077 */ lbz         r6, 0x77(r4)
  /* 80531AE0 98C30077 */ stb         r6, 0x77(r3)
  /* 80531AE4 80C40078 */ lwz         r6, 0x78(r4)
  /* 80531AE8 90C30078 */ stw         r6, 0x78(r3)
  /* 80531AEC 80C40080 */ lwz         r6, 0x80(r4)
  /* 80531AF0 80E4007C */ lwz         r7, 0x7c(r4)
  /* 80531AF4 90E3007C */ stw         r7, 0x7c(r3)
  /* 80531AF8 90C30080 */ stw         r6, 0x80(r3)
  /* 80531AFC 80C40088 */ lwz         r6, 0x88(r4)
  /* 80531B00 80E40084 */ lwz         r7, 0x84(r4)
  /* 80531B04 90E30084 */ stw         r7, 0x84(r3)
  /* 80531B08 90C30088 */ stw         r6, 0x88(r3)
  /* 80531B0C 80C40090 */ lwz         r6, 0x90(r4)
  /* 80531B10 80E4008C */ lwz         r7, 0x8c(r4)
  /* 80531B14 90E3008C */ stw         r7, 0x8c(r3)
  /* 80531B18 90C30090 */ stw         r6, 0x90(r3)
  /* 80531B1C 80C40098 */ lwz         r6, 0x98(r4)
  /* 80531B20 80E40094 */ lwz         r7, 0x94(r4)
  /* 80531B24 90E30094 */ stw         r7, 0x94(r3)
  /* 80531B28 90C30098 */ stw         r6, 0x98(r3)
  /* 80531B2C 80C400A0 */ lwz         r6, 0xa0(r4)
  /* 80531B30 80E4009C */ lwz         r7, 0x9c(r4)
  /* 80531B34 90E3009C */ stw         r7, 0x9c(r3)
  /* 80531B38 90C300A0 */ stw         r6, 0xa0(r3)
  /* 80531B3C 80C400A8 */ lwz         r6, 0xa8(r4)
  /* 80531B40 80E400A4 */ lwz         r7, 0xa4(r4)
  /* 80531B44 90E300A4 */ stw         r7, 0xa4(r3)
  /* 80531B48 90C300A8 */ stw         r6, 0xa8(r3)
  /* 80531B4C 80C400B0 */ lwz         r6, 0xb0(r4)
  /* 80531B50 80E400AC */ lwz         r7, 0xac(r4)
  /* 80531B54 90E300AC */ stw         r7, 0xac(r3)
  /* 80531B58 90C300B0 */ stw         r6, 0xb0(r3)
  /* 80531B5C 80C400B4 */ lwz         r6, 0xb4(r4)
  /* 80531B60 90C300B4 */ stw         r6, 0xb4(r3)
  /* 80531B64 88C400B8 */ lbz         r6, 0xb8(r4)
  /* 80531B68 98C300B8 */ stb         r6, 0xb8(r3)
  /* 80531B6C 88C400B9 */ lbz         r6, 0xb9(r4)
  /* 80531B70 98C300B9 */ stb         r6, 0xb9(r3)
  /* 80531B74 88C400BA */ lbz         r6, 0xba(r4)
  /* 80531B78 98C300BA */ stb         r6, 0xba(r3)
  /* 80531B7C 80C400BC */ lwz         r6, 0xbc(r4)
  /* 80531B80 90C300BC */ stw         r6, 0xbc(r3)
  /* 80531B84 88C400C0 */ lbz         r6, 0xc0(r4)
  /* 80531B88 98C300C0 */ stb         r6, 0xc0(r3)
  /* 80531B8C 88C400C1 */ lbz         r6, 0xc1(r4)
  /* 80531B90 98C300C1 */ stb         r6, 0xc1(r3)
  /* 80531B94 88C400C2 */ lbz         r6, 0xc2(r4)
  /* 80531B98 98C300C2 */ stb         r6, 0xc2(r3)
  /* 80531B9C 80C400C4 */ lwz         r6, 0xc4(r4)
  /* 80531BA0 90C300C4 */ stw         r6, 0xc4(r3)
  /* 80531BA4 80C400C8 */ lwz         r6, 0xc8(r4)
  /* 80531BA8 90C300C8 */ stw         r6, 0xc8(r3)
  /* 80531BAC 80C400CC */ lwz         r6, 0xcc(r4)
  /* 80531BB0 90C300CC */ stw         r6, 0xcc(r3)
  /* 80531BB4 80C400D0 */ lwz         r6, 0xd0(r4)
  /* 80531BB8 90C300D0 */ stw         r6, 0xd0(r3)
  /* 80531BBC 80C400D4 */ lwz         r6, 0xd4(r4)
  /* 80531BC0 90C300D4 */ stw         r6, 0xd4(r3)
  /* 80531BC4 A0C400D8 */ lhz         r6, 0xd8(r4)
  /* 80531BC8 B0C300D8 */ sth         r6, 0xd8(r3)
  /* 80531BCC A0C400DA */ lhz         r6, 0xda(r4)
  /* 80531BD0 B0C300DA */ sth         r6, 0xda(r3)
  /* 80531BD4 A0C400DC */ lhz         r6, 0xdc(r4)
  /* 80531BD8 B0C300DC */ sth         r6, 0xdc(r3)
  /* 80531BDC A8C400DE */ lha         r6, 0xde(r4)
  /* 80531BE0 B0C300DE */ sth         r6, 0xde(r3)
  /* 80531BE4 88C400E0 */ lbz         r6, 0xe0(r4)
  /* 80531BE8 98C300E0 */ stb         r6, 0xe0(r3)
  /* 80531BEC 88C400E1 */ lbz         r6, 0xe1(r4)
  /* 80531BF0 98C300E1 */ stb         r6, 0xe1(r3)
  /* 80531BF4 88C400E2 */ lbz         r6, 0xe2(r4)
  /* 80531BF8 98C300E2 */ stb         r6, 0xe2(r3)
  /* 80531BFC A0C400E8 */ lhz         r6, 0xe8(r4)
  /* 80531C00 B0C300E8 */ sth         r6, 0xe8(r3)
  /* 80531C04 88C400EC */ lbz         r6, 0xec(r4)
  /* 80531C08 388400F0 */ addi        r4, r4, 0xf0
  /* 80531C0C 98C300EC */ stb         r6, 0xec(r3)
  /* 80531C10 386300F0 */ addi        r3, r3, 0xf0
  /* 80531C14 7C032840 */ cmplw       r3, r5
  /* 80531C18 4180FE34 */ blt+        lbl_80531a4c
  /* 80531C1C 82DF1758 */ lwz         r22, 0x1758(r31)
  /* 80531C20 3800000E */ li          r0, 0xe
  /* 80531C24 82FF175C */ lwz         r23, 0x175c(r31)
  /* 80531C28 38BF0B98 */ addi        r5, r31, 0xb98
  /* 80531C2C 831F1760 */ lwz         r24, 0x1760(r31)
  /* 80531C30 389F1788 */ addi        r4, r31, 0x1788
  /* 80531C34 833F1764 */ lwz         r25, 0x1764(r31)
  /* 80531C38 835F1768 */ lwz         r26, 0x1768(r31)
  /* 80531C3C 837F176C */ lwz         r27, 0x176c(r31)
  /* 80531C40 839F1770 */ lwz         r28, 0x1770(r31)
  /* 80531C44 8BBF1774 */ lbz         r29, 0x1774(r31)
  /* 80531C48 8BDF1775 */ lbz         r30, 0x1775(r31)
  /* 80531C4C 899F1776 */ lbz         r12, 0x1776(r31)
  /* 80531C50 897F1777 */ lbz         r11, 0x1777(r31)
  /* 80531C54 815F1778 */ lwz         r10, 0x1778(r31)
  /* 80531C58 893F177C */ lbz         r9, 0x177c(r31)
  /* 80531C5C 891F177D */ lbz         r8, 0x177d(r31)
  /* 80531C60 80FF1780 */ lwz         r7, 0x1780(r31)
  /* 80531C64 80DF1784 */ lwz         r6, 0x1784(r31)
  /* 80531C68 807F1788 */ lwz         r3, 0x1788(r31)
  /* 80531C6C 92DF0B68 */ stw         r22, 0xb68(r31)
  /* 80531C70 92FF0B6C */ stw         r23, 0xb6c(r31)
  /* 80531C74 931F0B70 */ stw         r24, 0xb70(r31)
  /* 80531C78 933F0B74 */ stw         r25, 0xb74(r31)
  /* 80531C7C 935F0B78 */ stw         r26, 0xb78(r31)
  /* 80531C80 937F0B7C */ stw         r27, 0xb7c(r31)
  /* 80531C84 939F0B80 */ stw         r28, 0xb80(r31)
  /* 80531C88 9BBF0B84 */ stb         r29, 0xb84(r31)
  /* 80531C8C 9BDF0B85 */ stb         r30, 0xb85(r31)
  /* 80531C90 999F0B86 */ stb         r12, 0xb86(r31)
  /* 80531C94 997F0B87 */ stb         r11, 0xb87(r31)
  /* 80531C98 915F0B88 */ stw         r10, 0xb88(r31)
  /* 80531C9C 993F0B8C */ stb         r9, 0xb8c(r31)
  /* 80531CA0 991F0B8D */ stb         r8, 0xb8d(r31)
  /* 80531CA4 90FF0B90 */ stw         r7, 0xb90(r31)
  /* 80531CA8 90DF0B94 */ stw         r6, 0xb94(r31)
  /* 80531CAC 907F0B98 */ stw         r3, 0xb98(r31)
  /* 80531CB0 7C0903A6 */ mtctr       r0
  lbl_80531cb4:
  /* 80531CB4 80640004 */ lwz         r3, 4(r4)
  /* 80531CB8 84040008 */ lwzu        r0, 8(r4)
  /* 80531CBC 90650004 */ stw         r3, 4(r5)
  /* 80531CC0 94050008 */ stwu        r0, 8(r5)
  /* 80531CC4 4200FFF0 */ bdnz        lbl_80531cb4
  /* 80531CC8 801F17FC */ lwz         r0, 0x17fc(r31)
  /* 80531CCC 901F0C0C */ stw         r0, 0xc0c(r31)
  /* 80531CD0 BAA10014 */ lmw         r21, 0x14(r1)
  /* 80531CD4 80010044 */ lwz         r0, 0x44(r1)
  /* 80531CD8 7C0803A6 */ mtlr        r0
  /* 80531CDC 38210040 */ addi        r1, r1, 0x40
  /* 80531CE0 4E800020 */ blr
  // clang-format on
}

namespace System {

u8 RaceConfig::update() { return mMenuScenario.update(); }

void RaceConfigScenario::appendParamFile(RaceConfig* raceConfig) {
  raceConfig->append(mSettings.mCourseId,
                     InitScene::spInstance->mHeapCollection
                         .mpHeaps[HeapCollection::HEAP_ID_MEM2]);
  raceConfig->append(mSettings.mEngineClass,
                     InitScene::spInstance->mHeapCollection
                         .mpHeaps[HeapCollection::HEAP_ID_MEM2]);
  raceConfig->append(mSettings.mGameMode,
                     InitScene::spInstance->mHeapCollection
                         .mpHeaps[HeapCollection::HEAP_ID_MEM2]);
  raceConfig->append(mPlayerCount, InitScene::spInstance->mHeapCollection
                                       .mpHeaps[HeapCollection::HEAP_ID_MEM2]);
  raceConfig->append(mLocalPlayerCount,
                     InitScene::spInstance->mHeapCollection
                         .mpHeaps[HeapCollection::HEAP_ID_MEM2]);

  // Couldn't have just done getPlayer(i)?
  RaceConfigPlayer* player = mPlayers;
  for (s8 _ = 0; _ < 12; _++) {
    player->appendParamFile(raceConfig);
    player++;
  }

  raceConfig->append(mSettings.mModeFlags, nullptr);
}

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
  return (u8)mRaceScenario.mSettings.mHudPlayerIds[playerIdx];
}

void RaceConfig::loadNextCourse() {
  if (mRaceScenario.mSettings.mGameMode != 0) {
    return;
  }

  u8 raceNumber = mRaceScenario.mSettings.mRaceNumber;
  if (raceNumber >= 3) {
    return;
  }

  ResourceManager::spInstance.nonvol->preloadCourseAsync(
      COURSE_ORDER[mRaceScenario.mSettings.mCupId][raceNumber + 1]);
}

bool RaceConfig::isLiveView(u8 hudPlayerIdx) {
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

void ParameterFile::emptySub3() {}
void ParameterFile::emptySub2() {}
void ParameterFile::emptySub1() {}
s32 ParameterFile::emptySub0() { return 0; }

} // namespace System

#pragma once

#include <game/host_system/ParameterFile.hpp>
#include <game/system/GhostFile.hpp>
#include <game/system/Mii.hpp>
#include <game/system/ResourceManager.hpp>
#include <game/system/InitScene.hpp>
#include <game/system/SaveManager.hpp>

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x8052d96c..0x8052da10
UNKNOWN_FUNCTION(RacedataPlayer_construct);
// PAL: 0x8052da10..0x8052da50
UNKNOWN_FUNCTION(unk_8052da10);
// PAL: 0x8052da50..0x8052daf0
UNKNOWN_FUNCTION(unk_8052da50);
// PAL: 0x8052daf0..0x8052dbc8
UNKNOWN_FUNCTION(RacedataPlayer_computeGpRank);
// PAL: 0x8052dbc8..0x8052dc68
UNKNOWN_FUNCTION(RacedataScenario_construct);
// PAL: 0x8052dc68..0x8052dca8
UNKNOWN_FUNCTION(RacedataPlayer_destroy);
// PAL: 0x8052dca8..0x8052dd18
UNKNOWN_FUNCTION(computeWinningTeam__Q26System12RaceScenarioFv);
// PAL: 0x8052dd18..0x8052dd20
UNKNOWN_FUNCTION(getTeam__Q26System16RaceConfigPlayerFv);
// PAL: 0x8052dd20..0x8052dd30
UNKNOWN_FUNCTION(getPlayer__Q26System12RaceScenarioFUc);
// PAL: 0x8052dd30..0x8052dd40
UNKNOWN_FUNCTION(getRacePlayerCount__Q26System10RaceConfigFv);
// PAL: 0x8052dd40..0x8052e42c
UNKNOWN_FUNCTION(Racedata_init);
// PAL: 0x8052e42c..0x8052e434
UNKNOWN_FUNCTION(
    setCharacter__Q26System16RaceConfigPlayerFQ26System11CharacterId);
// PAL: 0x8052e434..0x8052e444
UNKNOWN_FUNCTION(getPlayer__Q26System12MenuScenarioFUc);
// PAL: 0x8052e444..0x8052e44c
UNKNOWN_FUNCTION(setVehicle__Q26System16RaceConfigPlayerFQ26System9VehicleId);
// PAL: 0x8052e44c..0x8052e454
UNKNOWN_FUNCTION(setPlayerType__Q26System16RaceConfigPlayerFl);
// PAL: 0x8052e454..0x8052e658
UNKNOWN_FUNCTION(Racedata_resetSomeStuff);
// PAL: 0x8052e658..0x8052e660
UNKNOWN_FUNCTION(setPrevFinishPos__Q26System16RaceConfigPlayerFSc);
// PAL: 0x8052e660..0x8052e668
UNKNOWN_FUNCTION(setUnkPos__Q26System16RaceConfigPlayerFSc);
// PAL: 0x8052e668..0x8052e870
UNKNOWN_FUNCTION(unk_8052e668);
// PAL: 0x8052e870..0x8052e950
UNKNOWN_FUNCTION(unk_8052e870);
// PAL: 0x8052e950..0x8052ed18
UNKNOWN_FUNCTION(unk_8052e950);
// PAL: 0x8052ed18..0x8052ed20
UNKNOWN_FUNCTION(getGametype__Q26System12MenuScenarioFv);
// PAL: 0x8052ed20..0x8052ed28
UNKNOWN_FUNCTION(getPlayerType__Q26System16RaceConfigPlayerFv);
// PAL: 0x8052ed28..0x8052eef0
UNKNOWN_FUNCTION(RacedataScenario_postInitControllers);
// PAL: 0x8052eef0..0x8052efd4
UNKNOWN_FUNCTION(unk_8052eef0);
// PAL: 0x8052efd4..0x8052f064
UNKNOWN_FUNCTION(resetPlayers__Q26System18RaceConfigScenarioFv);
// PAL: 0x8052f064..0x8052f1e0
UNKNOWN_FUNCTION(unk_8052f064);
// PAL: 0x8052f1e0..0x8052f4e8
UNKNOWN_FUNCTION(RacedataScenario_copyPrevPositions);
// PAL: 0x8052f4e8..0x8052f788
UNKNOWN_FUNCTION(RacedataScenario_initControllers);
// PAL: 0x8052f788..0x8052f924
UNKNOWN_FUNCTION(computePlayerCounts__Q26System12MenuScenarioFPUcPUcPUc);
// PAL: 0x8052f924..0x8052fa0c
UNKNOWN_FUNCTION(RacedataScenario_initRng);
// PAL: 0x8052fa0c..0x8052fb90
UNKNOWN_FUNCTION(unk_8052fa0c);
// PAL: 0x8052fb90..0x8052fe58
UNKNOWN_FUNCTION(RacedataScenario_initRace);
// PAL: 0x8052fe58..0x8052ffe8
UNKNOWN_FUNCTION(Racedata_initStaticInstance);
// PAL: 0x8052ffe8..0x80530038
UNKNOWN_FUNCTION(Racedata_destroyStaticInstance);
// PAL: 0x80530038..0x805300f4
UNKNOWN_FUNCTION(Racedata_destroy);
// PAL: 0x805300f4..0x8053015c
UNKNOWN_FUNCTION(RacedataScenario_destroy);
// PAL: 0x8053015c..0x805302c4
UNKNOWN_FUNCTION(Racedata_construct);
// PAL: 0x805302c4..0x805305ac
UNKNOWN_FUNCTION(Racedata_initRace);
// PAL: 0x805305ac..0x80530864
UNKNOWN_FUNCTION(RacedataScenario_copy);
// PAL: 0x80530864..0x80530f0c
UNKNOWN_FUNCTION(Racedata_initAwards);
// PAL: 0x80530f0c..0x80530f18
UNKNOWN_FUNCTION(getModeFlag__Q26System12MenuScenarioFv);
// PAL: 0x80530f18..0x80530f20
UNKNOWN_FUNCTION(getUnkPos__Q26System16RaceConfigPlayerFv);
// PAL: 0x80530f20..0x80530f28
UNKNOWN_FUNCTION(getCharacter__Q26System16RaceConfigPlayerFv);
// PAL: 0x80530f28..0x80530f30
UNKNOWN_FUNCTION(getVehicle__Q26System16RaceConfigPlayerFv);
// PAL: 0x80530f30..0x80531068
UNKNOWN_FUNCTION(setMii__Q26System16RaceConfigPlayerFRCQ26System3Mii);
// PAL: 0x80531068..0x80531070
UNKNOWN_FUNCTION(getMii__Q26System16RaceConfigPlayerFv);
// PAL: 0x80531070..0x80531ce4
UNKNOWN_FUNCTION(Racedata_initCredits);
// PAL: 0x80531ce4..0x80531de4
UNKNOWN_FUNCTION(Racedata_updateEndOfRace);
// PAL: 0x80531de4..0x80531f18
UNKNOWN_FUNCTION(unk_80531de4);
// PAL: 0x80531f18..0x80531f2c
UNKNOWN_FUNCTION(getLocalPlayerCount__Q26System10RaceConfigFUc);
// PAL: 0x80531f2c..0x80531f70
UNKNOWN_FUNCTION(Racedata_setGhost);
// PAL: 0x80531f70..0x80531f80
UNKNOWN_FUNCTION(Racedata_getHudPlayerId);
// PAL: 0x80531f80..0x80531fc8
UNKNOWN_FUNCTION(unk_80531f80);
// PAL: 0x80531fc8..0x80532030
UNKNOWN_FUNCTION(unk_80531fc8);
// PAL: 0x80532030..0x80532070
UNKNOWN_FUNCTION(Racedata_isTimeAttackReplay);
// PAL: 0x80532070..0x80532074
UNKNOWN_FUNCTION(unk_80532070);
// PAL: 0x80532074..0x80532078
UNKNOWN_FUNCTION(unk_80532074);
// PAL: 0x80532078..0x8053207c
UNKNOWN_FUNCTION(unk_80532078);
// PAL: 0x8053207c..0x80532084
UNKNOWN_FUNCTION(unk_8053207c);

#ifdef __cplusplus
}
#endif

namespace System {
// NOTE: anything marked u8, u16, or u32 could be signed
class RaceConfig;

class RaceConfigPlayer {
public:
  RaceConfigPlayer();
  virtual ~RaceConfigPlayer();
  void appendParamFile(RaceConfig* raceConfig);
  s32 computeGpRank() const;
  BattleTeam getTeam();
  void setCharacter(CharacterId character);
  void setVehicle(VehicleId vehicle);
  void setPlayerType(s32 playerType);
  void reset(s8 pos);
  void setPrevFinishPos(s8 pos);
  void setUnkPos(s8 pos);
  s32 getPlayerType();
  u8 getUnkPos();
  CharacterId getCharacter();
  VehicleId getVehicle();
  void setMii(const Mii& mii);
  Mii* getMii();
  // private:
  unk8 _04;
  s8 mLocalPlayerNum;
  s8 mPlayerInputIdx;
  VehicleId mVehicleId;
  CharacterId mCharacterId;
  s32 mPlayerType; // TODO: create enum
  Mii mMii;
  BattleTeam mTeam;
  u32 mControllerId;
  unk32 _d4;
  u16 mPreviousScore;
  u16 mGpScore;
  unk16 _dc;
  s16 mGpRankScore;
  unk8 _e0;
  u8 mPrevFinishPos;
  u8 mFinishPos;
  Rating mRating;
  s8 _ec;
};

struct RaceConfigSettings {
  CourseId mCourseId;
  u32 mEngineClass; // probably an enum
  s32 mGameMode;    // TODO: create enum
  s32 mGameType;    // TODO: create enum
  u32 mBattleType;
  u32 mCpuMode;
  u32 mItemMode;
  s8 mHudPlayerIds[4];
  s32 mCupId; // TODO: create enum
  u8 mRaceNumber;
  u8 mLapCount;
  s32 mModeFlags; // TODO: create enum
  u32 mSeed1;
  u32 mSeed2;
};

class RaceConfigScenario {
public:
  RaceConfigScenario(RawGhostFile* ghost);
  virtual ~RaceConfigScenario();
  RaceConfigPlayer* getPlayer(u8 idx) { return &mPlayers[idx]; }
  void reset();
  u8 update();
  void resetPlayers();
  // private:
  u8 mPlayerCount;
  u8 mHudCount;
  u8 mLocalPlayerCount;
  u8 mHudCount2; // ?
  RaceConfigPlayer mPlayers[12];
  RaceConfigSettings mSettings;
  unk8 _b7c[0xbec - 0xb7c];
  RawGhostFile* mGhost;
};

// These will be important later
class RaceScenario : public RaceConfigScenario {
public:
  RaceScenario(RawGhostFile* ghost) : RaceConfigScenario(ghost) {}
  RaceConfigPlayer* getPlayer(u8 idx);
  BattleTeam computeWinningTeam();
};
class MenuScenario : public RaceConfigScenario {
public:
  MenuScenario(RawGhostFile* ghost) : RaceConfigScenario(ghost) {}
  RaceConfigPlayer* getPlayer(u8 idx);
  s32 getGametype();
  bool initGhost(u8 playerIdx, u8 playerInputIdx);
  void computePlayerCounts(u8* playerCount, u8* hudCount, u8* localPlayerCount);
  u32 getModeFlag();
};
class AwardsScenario : public RaceConfigScenario {
public:
  AwardsScenario(RawGhostFile* ghost) : RaceConfigScenario(ghost) {}
};

class RaceConfigEx {
public:
  inline RaceConfigEx() {}
};

class RaceConfigEx2 {
public:
  inline RaceConfigEx2() {}
};

class RaceConfig : public RaceConfigEx2, public ParameterFile, RaceConfigEx {
public:
  RaceConfig();
  virtual ~RaceConfig();
  virtual void vf10();
  virtual void vf14();
  virtual void vf18();
  void reset();
  static u8 getRacePlayerCount();
  s16 updateRating(u8 playerIdx);
  u8 update();
  s32 getLocalPlayerCount(u8 playerIdx);
  void setGhost(RawGhostFile* ghost);
  s8 getHudPlayerId(u8 playerIdx);
  void loadNextCourse();
  bool unk_80531fc8(u8 hudPlayerIdx);
  bool isTimeAttackReplay();

  static RaceConfig* spInstance;

  RaceScenario mRaceScenario;
  MenuScenario mMenuScenario;
  AwardsScenario mAwardsScenario;
  RawGhostFile mGhosts[2];
};

} // namespace System

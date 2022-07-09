#pragma once

#include <game/host_system/ParameterFile.hpp>
#include <game/system/GhostFile.hpp>
#include <game/system/ResourceManager.hpp>

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
UNKNOWN_FUNCTION(unk_8052dca8);
// PAL: 0x8052dd18..0x8052dd20
UNKNOWN_FUNCTION(unk_8052dd18);
// PAL: 0x8052dd20..0x8052dd30
UNKNOWN_FUNCTION(unk_8052dd20);
// PAL: 0x8052dd30..0x8052dd40
UNKNOWN_FUNCTION(unk_8052dd30);
// PAL: 0x8052dd40..0x8052e42c
UNKNOWN_FUNCTION(Racedata_init);
// PAL: 0x8052e42c..0x8052e434
UNKNOWN_FUNCTION(unk_8052e42c);
// PAL: 0x8052e434..0x8052e444
UNKNOWN_FUNCTION(RacedataScenario_getPlayer);
// PAL: 0x8052e444..0x8052e44c
UNKNOWN_FUNCTION(unk_8052e444);
// PAL: 0x8052e44c..0x8052e454
UNKNOWN_FUNCTION(unk_8052e44c);
// PAL: 0x8052e454..0x8052e658
UNKNOWN_FUNCTION(Racedata_resetSomeStuff);
// PAL: 0x8052e658..0x8052e660
UNKNOWN_FUNCTION(unk_8052e658);
// PAL: 0x8052e660..0x8052e668
UNKNOWN_FUNCTION(unk_8052e660);
// PAL: 0x8052e668..0x8052e870
UNKNOWN_FUNCTION(unk_8052e668);
// PAL: 0x8052e870..0x8052e950
UNKNOWN_FUNCTION(unk_8052e870);
// PAL: 0x8052e950..0x8052ed18
UNKNOWN_FUNCTION(unk_8052e950);
// PAL: 0x8052ed18..0x8052ed20
UNKNOWN_FUNCTION(unk_8052ed18);
// PAL: 0x8052ed20..0x8052ed28
UNKNOWN_FUNCTION(unk_8052ed20);
// PAL: 0x8052ed28..0x8052eef0
UNKNOWN_FUNCTION(RacedataScenario_postInitControllers);
// PAL: 0x8052eef0..0x8052efd4
UNKNOWN_FUNCTION(unk_8052eef0);
// PAL: 0x8052efd4..0x8052f064
UNKNOWN_FUNCTION(unk_8052efd4);
// PAL: 0x8052f064..0x8052f1e0
UNKNOWN_FUNCTION(unk_8052f064);
// PAL: 0x8052f1e0..0x8052f4e8
UNKNOWN_FUNCTION(RacedataScenario_copyPrevPositions);
// PAL: 0x8052f4e8..0x8052f788
UNKNOWN_FUNCTION(RacedataScenario_initControllers);
// PAL: 0x8052f788..0x8052f924
UNKNOWN_FUNCTION(RacedataScenario_computePlayerCounts);
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
UNKNOWN_FUNCTION(unk_80530f0c);
// PAL: 0x80530f18..0x80530f20
UNKNOWN_FUNCTION(unk_80530f18);
// PAL: 0x80530f20..0x80530f28
UNKNOWN_FUNCTION(unk_80530f20);
// PAL: 0x80530f28..0x80530f30
UNKNOWN_FUNCTION(unk_80530f28);
// PAL: 0x80530f30..0x80531068
UNKNOWN_FUNCTION(unk_80530f30);
// PAL: 0x80531068..0x80531070
UNKNOWN_FUNCTION(unk_80531068);
// PAL: 0x80531070..0x80531ce4
UNKNOWN_FUNCTION(Racedata_initCredits);
// PAL: 0x80531ce4..0x80531de4
UNKNOWN_FUNCTION(Racedata_updateEndOfRace);
// PAL: 0x80531de4..0x80531f18
UNKNOWN_FUNCTION(unk_80531de4);
// PAL: 0x80531f18..0x80531f2c
UNKNOWN_FUNCTION(Racedata_getLocalPlayerNum);
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

// NOTE: anything marked u8, u16, or u32 could be signed
namespace System {

class RaceConfigPlayer {
public:
  RaceConfigPlayer();
  virtual ~RaceConfigPlayer();
// private:
  unk8 _04;
  u8 mLocalPlayerNum;
  u8 mPlayerInputIdx;
  VehicleId mVehicleId;
  CharacterId mCharacterId;
  s32 mPlayerType;         // TODO: create enum
  unk8 _mMii[0xcc - 0x14]; // TODO: this is a class that isn't decompiled yet
                           // (Mii.hpp is 0x4c, this is 0xb8)
  BattleTeam mTeam;
  u32 mControllerId;
  unk32 _d4;
  u16 mPreviousScore;
  u16 mGpScore;
  unk16 _dc;
  u16 mGpRankScore;
  unk8 _e0;
  u8 mPrevFinishPos;
  u8 mFinishPos;
  unk8 mRating[0xec - 0xe4];
  unk32 _ec;
};

struct RaceConfigSettings {
  CourseId mCourseId;
  u32 mEngineClass; // probably an enum
  s32 mGameMode; // TODO: create enum
  s32 mGameType; // TODO: create enum
  u32 mBattleType;
  u32 mCpuMode;
  u32 mItemMode;
  u8 mHudPlayerIds[4];
  s32 mCupId; // TODO: create enum
  u8 mRaceNumber;
  u8 mLapCount;
  s32 mModeFlags; // TODO: create enum
  u32 mSeed1;
  u32 mSeed2;
};

class RaceConfigScenario {
public:
  RaceConfigScenario();
  virtual ~RaceConfigScenario();
// private:
  u8 mPlayerCount;
  u8 mHudCount;
  u8 mLocalPlayerCount;
  u8 mHudCount2; // ?
  RaceConfigPlayer mPlayers[12];
  RaceConfigSettings mSettings;
  unk8 _b7c[0xbec - 0xb7c];
  RawGhostFile mGhost;
};

// These will be important later
class RaceScenario : public RaceConfigScenario {};
class MenuScenario : public RaceConfigScenario {};
class AwardsScenario : public RaceConfigScenario {};

class RaceConfigMain {
public:
  RaceConfigMain();

  // Things get tricky here - we have a vtable with no virtual functions
  void* vtable;
  RaceScenario mRaceScenario;
  MenuScenario mMenuScenario;
  AwardsScenario mAwardsScenario;
  RawGhostFile mGhosts[2];
};

class RaceConfig : ParameterFile, public RaceConfigMain {
public:
  RaceConfig();
  virtual ~RaceConfig();

  static RaceConfig* spInstance;
};

} // namespace System

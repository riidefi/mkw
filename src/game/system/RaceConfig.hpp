#pragma once

#include <game/host_system/ParameterFile.hpp>
#include <game/system/Competition.hpp>
#include <game/system/GhostFile.hpp>
#include <game/system/Mii.hpp>
#include <game/system/ResourceManager.hpp>
#include <game/system/KPadDirector.hpp>
#include <game/system/InitScene.hpp>
#include <game/system/Rating.hpp>

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
UNKNOWN_FUNCTION(computeWinningTeam__Q36System10RaceConfig8ScenarioFv);
// PAL: 0x8052dd18..0x8052dd20
UNKNOWN_FUNCTION(getTeam__Q36System10RaceConfig6PlayerFv);
// PAL: 0x8052dd20..0x8052dd30
UNKNOWN_FUNCTION(getPlayer__Q36System10RaceConfig8ScenarioFUc);
// PAL: 0x8052dd30..0x8052dd40
UNKNOWN_FUNCTION(getRacePlayerCount__Q26System10RaceConfigFv);
// PAL: 0x8052dd40..0x8052e42c
UNKNOWN_FUNCTION(Racedata_init);
// PAL: 0x8052e42c..0x8052e434
UNKNOWN_FUNCTION(
    setCharacter__Q36System10RaceConfig6PlayerFQ26System11CharacterId);
// PAL: 0x8052e434..0x8052e444
UNKNOWN_FUNCTION(getPlayer__Q36System10RaceConfig8ScenarioFUc);
// PAL: 0x8052e444..0x8052e44c
UNKNOWN_FUNCTION(setVehicle__Q36System10RaceConfig6PlayerFQ26System9VehicleId);
// PAL: 0x8052e44c..0x8052e454
UNKNOWN_FUNCTION(
    setPlayerType__Q36System10RaceConfig6PlayerFQ46System10RaceConfig6Player4Type);
// PAL: 0x8052e454..0x8052e658
UNKNOWN_FUNCTION(Racedata_resetSomeStuff);
// PAL: 0x8052e658..0x8052e660
UNKNOWN_FUNCTION(setPrevFinishPos__Q36System10RaceConfig6PlayerFSc);
// PAL: 0x8052e660..0x8052e668
UNKNOWN_FUNCTION(setUnkPos__Q36System10RaceConfig6PlayerFSc);
// PAL: 0x8052e668..0x8052e870
UNKNOWN_FUNCTION(unk_8052e668);
// PAL: 0x8052e870..0x8052e950
UNKNOWN_FUNCTION(unk_8052e870);
// PAL: 0x8052e950..0x8052ed18
UNKNOWN_FUNCTION(unk_8052e950);
// PAL: 0x8052ed18..0x8052ed20
UNKNOWN_FUNCTION(getCameraMode__Q36System10RaceConfig8ScenarioFv);
// PAL: 0x8052ed20..0x8052ed28
UNKNOWN_FUNCTION(getPlayerType__Q36System10RaceConfig6PlayerCFv);
// PAL: 0x8052ed28..0x8052eef0
UNKNOWN_FUNCTION(
    postInitControllers__Q36System10RaceConfig8ScenarioFPQ36System10RaceConfig8Scenario);
// PAL: 0x8052eef0..0x8052efd4
UNKNOWN_FUNCTION(unk_8052eef0);
// PAL: 0x8052f1e0..0x8052f4e8
UNKNOWN_FUNCTION(copyPrevPositions__Q36System10RaceConfig8ScenarioFv);
// PAL: 0x8052f4e8..0x8052f788
UNKNOWN_FUNCTION(initControllers__Q36System10RaceConfig8ScenarioFUc);
// PAL: 0x8052fa0c..0x8052fb90
UNKNOWN_FUNCTION(unk_8052fa0c);
// PAL: 0x8052fb90..0x8052fe58
UNKNOWN_FUNCTION(
    initRace__Q36System10RaceConfig8ScenarioFPQ36System10RaceConfig8Scenario);
// PAL: 0x805302c4..0x805305ac
UNKNOWN_FUNCTION(initRace__Q26System10RaceConfigFv);
// PAL: 0x805305ac..0x80530864
UNKNOWN_FUNCTION(RacedataScenario_copy);
// PAL: 0x80530864..0x80530f0c
UNKNOWN_FUNCTION(Racedata_initAwards);
// PAL: 0x80530f0c..0x80530f18
UNKNOWN_FUNCTION(isTeamMode__Q36System10RaceConfig8ScenarioFv);
// PAL: 0x80530f18..0x80530f20
UNKNOWN_FUNCTION(getUnkPos__Q36System10RaceConfig6PlayerFv);
// PAL: 0x80530f20..0x80530f28
UNKNOWN_FUNCTION(getCharacter__Q36System10RaceConfig6PlayerFv);
// PAL: 0x80530f28..0x80530f30
UNKNOWN_FUNCTION(getVehicle__Q36System10RaceConfig6PlayerFv);
// PAL: 0x80530f30..0x80531068
UNKNOWN_FUNCTION(setMii__Q36System10RaceConfig6PlayerFRCQ26System3Mii);
// PAL: 0x80531068..0x80531070
UNKNOWN_FUNCTION(getMii__Q36System10RaceConfig6PlayerFv);
// PAL: 0x80531070..0x80531ce4
UNKNOWN_FUNCTION(Racedata_initCredits);
// PAL: 0x80531ce4..0x80531de4
UNKNOWN_FUNCTION(Racedata_updateEndOfRace);
// PAL: 0x80531f18..0x80531f2c
UNKNOWN_FUNCTION(getLocalPlayerCount__Q26System10RaceConfigFUc);
// PAL: 0x80531f2c..0x80531f70
UNKNOWN_FUNCTION(Racedata_setGhost);
// PAL: 0x80531f70..0x80531f80
UNKNOWN_FUNCTION(Racedata_getHudPlayerId);
// PAL: 0x80531f80..0x80531fc8
UNKNOWN_FUNCTION(unk_80531f80);
// PAL: 0x80531fc8..0x80532030
UNKNOWN_FUNCTION(isLiveView__Q26System10RaceConfigFUc);
// PAL: 0x80532030..0x80532070
UNKNOWN_FUNCTION(Racedata_isTimeAttackReplay);

#ifdef __cplusplus
}
#endif

#define MAX_PLAYER_COUNT 12

namespace System {

enum CupId {
  MUSHROOM_CUP,
  FLOWER_CUP,
  STAR_CUP,
  SPECIAL_CUP,
  SHELL_CUP,
  BANANA_CUP,
  LEAF_CUP,
  LIGHTNING_CUP,
};

class RaceConfigEx {
public:
  inline RaceConfigEx() {}
};

class RaceConfig : public RaceConfigEx, public ParameterFile {
public:
  class Player {
  public:
    enum Type {
      TYPE_REAL_LOCAL,
      TYPE_CPU,
      TYPE_UNUSED,
      TYPE_GHOST,
      TYPE_REAL_ONLINE,
      TYPE_NONE,
    };

    Player();
    virtual ~Player();

    void appendParamFile(RaceConfig* raceConfig);
    s32 computeGpRank() const;
    void reset(s8 pos);

    CharacterId getCharacter();
    Mii& getMii();
    const Type getPlayerType() const;
    BattleTeam getTeam();
    u8 getUnkPos();
    VehicleId getVehicle();

    void setCharacter(CharacterId character);
    void setMii(const Mii& mii);
    void setPlayerType(Type playerType);
    void setPrevFinishPos(s8 pos);
    void setUnkPos(s8 pos);
    void setVehicle(VehicleId vehicle);

    unk8 _04;
    s8 mLocalPlayerNum;
    s8 mPlayerInputIdx;
    VehicleId mVehicleId;
    CharacterId mCharacterId;
    Type mPlayerType;
    Mii mMii;
    BattleTeam mTeam;
    s32 mControllerId;
    unk32 _d4;
    u16 mPreviousScore;
    u16 mGpScore;
    u16 _dc;
    s16 mGpRankScore;
    unk8 _e0;
    u8 mPrevFinishPos;
    u8 mFinishPos;
    Rating mRating;
    s8 _ec;
  };

  struct Settings {
    enum GameMode {
      GAMEMODE_GRAND_PRIX,
      GAMEMODE_VS_RACE,
      GAMEMODE_TIME_TRIAL,
      GAMEMODE_BATTLE,
      GAMEMODE_MISSION_TOURNAMENT,
      GAMEMODE_GHOST_RACE,
      GAMEMODE_UNKNOWN,
      GAMEMODE_PRIVATE_VS,
      GAMEMODE_PUBLIC_VS,
      GAMEMODE_PUBLIC_BATTLE,
      GAMEMODE_PRIVATE_BATTLE,
      GAMEMODE_AWARDS,
      GAMEMODE_CREDITS,
    };

    enum CameraMode {
      CAMERA_MODE_GAMEPLAY_NO_INTRO,
      CAMERA_MODE_REPLAY,
      CAMERA_MODE_TITLE_ONE_PLAYER,
      CAMERA_MODE_TITLE_TWO_PLAYER,
      CAMERA_MODE_TITLE_FOUR_PLAYER,
      CAMERA_MODE_GAMEPLAY_INTRO,
      CAMERA_MODE_LIVE_VIEW,
      CAMERA_MODE_GRAND_PRIX_WIN,
      CAMERA_MODE_SOLO_VS_WIN,
      CAMERA_MODE_TEAM_VS_WIN,
      CAMERA_MODE_BATTLE_WIN,
      CAMERA_MODE_UNK_11,
      CAMERA_MODE_LOSS,
    };

    enum ModeFlags {
      MODE_FLAG_MIRROR = 1,
      MODE_FLAG_TEAMS = 2,
      MODE_FLAG_COMPETITION = 4,
    };

    inline Settings& operator=(const Settings& other) {
      mCourseId = other.mCourseId;
      mEngineClass = other.mEngineClass;
      mGameMode = other.mGameMode;
      mCameraMode = other.mCameraMode;
      mBattleType = other.mBattleType;
      mCpuMode = other.mCpuMode;
      mItemMode = other.mItemMode;
      mHudPlayerIds[0] = other.mHudPlayerIds[0];
      mHudPlayerIds[1] = other.mHudPlayerIds[1];
      mHudPlayerIds[2] = other.mHudPlayerIds[2];
      mHudPlayerIds[3] = other.mHudPlayerIds[3];
      mCupId = other.mCupId;
      mRaceNumber = other.mRaceNumber;
      mLapCount = other.mLapCount;
      mModeFlags = other.mModeFlags;
      mSeed1 = other.mSeed1;
      mSeed2 = other.mSeed2;
      return *this;
    }

    CourseId mCourseId;
    u32 mEngineClass; // probably an enum
    GameMode mGameMode;
    CameraMode mCameraMode;
    u32 mBattleType;
    u32 mCpuMode;
    u32 mItemMode;
    s8 mHudPlayerIds[4];
    CupId mCupId;
    u8 mRaceNumber;
    u8 mLapCount;
    ModeFlags mModeFlags;
    u32 mSeed1;
    u32 mSeed2;
  };

  class Scenario {
  public:
    Scenario(RawGhostFile* ghost);
    virtual ~Scenario();

    Scenario& copy(const Scenario& other);

    void appendParamFile(RaceConfig* raceConfig);
    void clear();
    void computePlayerCounts(u8& playerCount, u8& hudCount,
                             u8& localPlayerCount);
    BattleTeam computeWinningTeam();
    void copyPrevPositions();
    void initCompetitionSettings();
    void initControllers(u8 controllerCount);
    bool initGhost(u8 playerIdx, s8 playerInputIdx);
    void initPlayers(u8 playerCount);
    void initRace(Scenario* scenario);
    void initRng();
    bool isTeamMode();
    void postInitControllers(Scenario* scenario);
    void resetPlayers();
    u8 update();

    Settings::CameraMode getCameraMode();
    const Player& getPlayer(u8 idx) const;
    Player& getPlayer(u8 idx);

    inline bool isOnline(Settings::GameMode mode) {
      bool ret = false;
      switch ((Settings::GameMode)(u32)mode) {
      case Settings::GAMEMODE_PRIVATE_VS:
      case Settings::GAMEMODE_PUBLIC_VS:
      case Settings::GAMEMODE_PUBLIC_BATTLE:
      case Settings::GAMEMODE_PRIVATE_BATTLE:
        ret = true;
      }
      return ret;
    }

    u8 mPlayerCount;
    u8 mHudCount;
    u8 mLocalPlayerCount;
    u8 mHudCount2; // ?
    Player mPlayers[MAX_PLAYER_COUNT];
    Settings mSettings;
    CompetitionSettings mCompetitionSettings;
    RawGhostFile* mGhost;
  };

  RaceConfig();
  ~RaceConfig() override;

  void clear();
  void init();
  void initRace();
  bool isLiveView(u8 hudPlayerIdx);
  bool isTimeAttackReplay();
  void loadNextCourse();
  u8 update();
  s16 updateRating(u8 playerIdx);

  s8 getHudPlayerId(u8 playerIdx);
  s32 getLocalPlayerCount(u8 playerIdx);

  void setGhost(RawGhostFile* ghost);

  static const u8 getRacePlayerCount();
  static RaceConfig* createInstance();
  static void destroyInstance();

  static RaceConfig* spInstance;

  Scenario mRaceScenario;
  Scenario mMenuScenario;
  Scenario mAwardsScenario;
  RawGhostFile mGhosts[2];
};

} // namespace System

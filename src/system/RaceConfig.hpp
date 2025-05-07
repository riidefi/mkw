#pragma once

#include <host_system/ParameterFile.hpp>
#include <system/Competition.hpp>
#include <system/GhostFile.hpp>
#include <system/Mii.hpp>
#include <system/ResourceManager.hpp>
#include <system/KPadDirector.hpp>
#include <system/InitScene.hpp>
#include <system/Rating.hpp>

#include <rk_types.h>

#include <decomp.h>

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
    // Same as above, but inlined. Needed for some functions to match
    inline const Type getPlayerTypeInlined() const {
      return mPlayerType;
    }

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
    // Same as above, but inlined. Needed for some functions to match
    inline Player& getPlayerInlined(u8 idx) {
      return mPlayers[idx];
    }

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

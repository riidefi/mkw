#pragma once

#include <rk_types.h>

#include <decomp.h>

#include "KPadDirector.hpp"
#include "GhostFile.hpp"
#include "CourseMap.hpp"
#include "RaceConfig.hpp"
#include "ElineControlManager.hpp"
#include "util/Random.hpp"
#include "ResourceManager.hpp"
#include "RaceMode.hpp"

namespace System {
enum RaceStage {
  INTRO_CAMERA=0 /* Course preview */,
  COUNTDOWN=1    /* Includes starting pan */,
  RACE=2,
  FINISHED_RACE=3
};

// TODO: Maybe defines/bitfield and not enum?
enum RaceManagerPlayerFlags {
  IN_RACE=1,
  FINISHED=2,
  DRIVING_WRONG_WAY=4,
  DISCONNECTED=16,
  COMING_LAST_ANIMATION=64
};

struct KmgFileRaw {
  char magic[4]; /* RKMG in ASCII */
  u32 fileSize; /* in bytes */
  s32 field2_0x8;
  void* coinRunnersOff; /* relative to 0x10 */
  s16 balloonBattleTimeLimits[10][11];
  u16 field5_0xec[10][11];
  s16 enemyHitScore;
  s16 enemyDefeatScore;
  s16 allBalloonLossScore;
  s16 hitByEnemyScore;
  s16 teammateHitScore;
  s16 hitByTeammateScore;
  s16 field12_0x1d4;
  s16 field13_0x1d6;
  s16 field14_0x1d8;
  s16 field15_0x1da;
  s16 coinRunnersTimeLimits[10][11];
  u16 field17_0x2b8[10][11];
  u16 startCoinCounts[10][11];
  u16 maxCoinCounts[10][11];
  u16 field20_0x54c[10][11];
  u16 field21_0x628[10][11];
  unk8 unk[0x712-0x704];
  s16 fallOffCoinLoss;
  s16 hitCoinLoss;
  s16 coinLossPercent; /* ?? Copied from wiki */
};
static_assert(sizeof(KmgFileRaw) == 0x718);

class KmgFile {
public:
  KmgFile(void* file) { fromRaw(file); }
  void fromRaw(void* file);
  virtual ~KmgFile();
  s16 getBattleCourseId(CourseId courseId);

  KmgFileRaw* data;
};
static_assert(sizeof(KmgFile) == 0x8);

// Maybe its own header file
class TimerManagerBase {
public:
  TimerManagerBase() { reset(); }
  virtual ~TimerManagerBase();
  virtual void reset();
  virtual void update();

protected:
  Time timer1;
  Time timer2;
  Time timer3;
  Util::Random random;
  s8 field26_0x40;
  bool raceHasStarted;
  bool timerIsReversed;
  u32 raceDurationMillis;
  unk8 unk48[0x50-0x48];
};

class TimerManager : public TimerManagerBase {
public:
  TimerManager() : TimerManagerBase() {}
  virtual ~TimerManager() override;
  virtual void reset() override;
  virtual void update() override;
  inline void setLimit(u16 minutes, u8 seconds) {
    this->timer3.set2(minutes, seconds, 0, true);
    this->timerIsReversed = true;
    this->timer2.set2(minutes, seconds, 0, true);
    this->raceDurationMillis = (seconds+60*minutes)*1000;
  }
};
static_assert(sizeof(TimerManager) == 0x50);

/** 
 * currentBit is a 1 that rotates arounds the region defined by mask every frame. Could be slipstream related?
 * Overall a weird timer which rotates a single bit around a u32
 * */
class MovingMask {
public:
    MovingMask(u32);
    int mask;
    int currentBit;
};

class RaceManagerPlayer {
public:
  RaceManagerPlayer(u8 idx, u8 lapCount);
  void updateGpRankScore();
  virtual ~RaceManagerPlayer();

  unk32 field_0x4;
  s8 idx;
  u16 checkpointId;
  float raceCompletion;
  float raceCompletionMax;
  float checkpointFactor;
  float checkpointStartLapCompletion;
  float lapCompletion;
  s8 position;
  s8 respawn;
  u16 battleScore;
  s16 currentLap;
  s8 maxLap;
  s8 currentKcp;
  s8 maxKcp;
  u32 frameCounter;
  u32 framesInFirstPlace;
  s32 unk34;
  RaceManagerPlayerFlags flags;
  Time* lapFinishTimes;
  Time* raceFinishTime;
  u32 somethingRaceEndMessageOnline;
  KPadPlayer* kpadPlayer;
  unk8 unk_4c_50[0x50-0x4c];
  u16 playersAheadFlags;
  s8 field36_0x52;
  s8 finishingPosition;
};
static_assert(sizeof(RaceManagerPlayer) == 0x54);

struct KrtFile {
    u32 magic;
    u32 rankTimeDeltaFactor;
    u16 numEntries;
    u16 headerSize;
    u16 entries[32][4];
};

class RaceMode; // todo in another file
class RaceManager {
public:
  virtual ~RaceManager();
  RaceManager();

  static RaceManager* createInstance();
  static void destroyInstance();
  static RaceManager* spInstance;
  static u8 getLapCount();

  RaceMode* initGamemode(RaceConfig::Settings::GameMode mode);
  RaceMode* createCompetitionMode();
  u16 getBattleTimeLimit();
  KrtFile** getKrtFile();

  Util::Random* random1;
  Util::Random* random2;
  RaceManagerPlayer** players;
  RaceMode* raceMode;
  TimerManager* timerManager;
  s8* player_id_in_each_position;
  s8 finished_player_count;
  s8 disconnectedPlayerCount;
  s16 introTimer;
  u32 timer; /* Begins counting when race countdown starts */
  s8 battleKtptStart;
  s8 field12_0x25;
  RaceStage stage;
  bool introWasSkipped;
  bool spectatorMode;
  bool canCountdownStart;
  bool cutSceneMode;
  bool lapCountingIsEnabled;
  MovingMask movingMask;
  KmgFile* kmgFile;
  ElineControlManager* eline_control_manager;
  float dpWaterHeightCheck;
  bool dpDisableLowerRespawns;
};
static_assert(sizeof(RaceManager) == 0x4c);
}

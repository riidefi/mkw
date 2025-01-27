#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x80532084..0x805320d4
UNKNOWN_FUNCTION(Raceinfo_initStaticInstance);
// PAL: 0x805320d4..0x80532124
UNKNOWN_FUNCTION(Raceinfo_destroyStaticInstance);
// PAL: 0x80532124..0x80532188
UNKNOWN_FUNCTION(unk_80532124);
// PAL: 0x80532188..0x80532488
UNKNOWN_FUNCTION(Raceinfo_initGamemode);
// PAL: 0x80532488..0x805324ac
UNKNOWN_FUNCTION(unk_80532488);
// PAL: 0x805324ac..0x805324ec
UNKNOWN_FUNCTION(unk_805324ac);
// PAL: 0x805324ec..0x8053252c
UNKNOWN_FUNCTION(unk_805324ec);
// PAL: 0x8053252c..0x8053256c
UNKNOWN_FUNCTION(unk_8053252c);
// PAL: 0x8053256c..0x805325ac
UNKNOWN_FUNCTION(unk_8053256c);
// PAL: 0x805325ac..0x805325ec
UNKNOWN_FUNCTION(unk_805325ac);
// PAL: 0x805325ec..0x8053262c
UNKNOWN_FUNCTION(unk_805325ec);
// PAL: 0x8053262c..0x8053266c
UNKNOWN_FUNCTION(unk_8053262c);
// PAL: 0x8053266c..0x805326ac
UNKNOWN_FUNCTION(unk_8053266c);
// PAL: 0x805326ac..0x805326ec
UNKNOWN_FUNCTION(unk_805326ac);
// PAL: 0x805326ec..0x805327a0
UNKNOWN_FUNCTION(unk_805326ec);
// PAL: 0x805327a0..0x80532d44
UNKNOWN_FUNCTION(Raceinfo_construct);
// PAL: 0x80532d44..0x80532de0
UNKNOWN_FUNCTION(unk_80532d44);
// PAL: 0x80532de0..0x80532e3c
UNKNOWN_FUNCTION(unk_80532de0);
// PAL: 0x80532e3c..0x80532f48
UNKNOWN_FUNCTION(unk_80532e3c);
// PAL: 0x80532f48..0x80532f88
UNKNOWN_FUNCTION(RaceinfoPlayer_destroy);
// PAL: 0x80532f88..0x8053308c
UNKNOWN_FUNCTION(Raceinfo_init);
// PAL: 0x8053308c..0x80533090
UNKNOWN_FUNCTION(unk_8053308c);
// PAL: 0x80533090..0x805330c0
UNKNOWN_FUNCTION(RaceInfo_getCountdown);
// PAL: 0x805330c0..0x805331b4
UNKNOWN_FUNCTION(unk_805330c0);
// PAL: 0x805331b4..0x805336a0
UNKNOWN_FUNCTION(RaceInfo_update);
// PAL: 0x805336a0..0x805336a4
UNKNOWN_FUNCTION(unk_805336a0);
// PAL: 0x805336a4..0x805336d8
UNKNOWN_FUNCTION(getLapCount);
// PAL: 0x805336d8..0x80533afc
UNKNOWN_FUNCTION(unk_805336d8);
// PAL: 0x80533afc..0x80533be8
UNKNOWN_FUNCTION(unk_80533afc);
// PAL: 0x80533be8..0x80533bec
UNKNOWN_FUNCTION(unk_80533be8);
// PAL: 0x80533bec..0x80533c34
UNKNOWN_FUNCTION(unk_80533bec);
// PAL: 0x80533c34..0x80533c6c
UNKNOWN_FUNCTION(unk_80533c34);
// PAL: 0x80533c6c..0x80533d84
UNKNOWN_FUNCTION(unk_80533c6c);
// PAL: 0x80533d84..0x80533dd4
UNKNOWN_FUNCTION(unk_80533d84);
// PAL: 0x80533dd4..0x80533ed8
UNKNOWN_FUNCTION(unk_80533dd4);
// PAL: 0x80533ed8..0x80534194
UNKNOWN_FUNCTION(RaceinfoPlayer_construct);
// PAL: 0x80534194..0x805342e8
UNKNOWN_FUNCTION(RaceinfoPlayer_init);
// PAL: 0x805342e8..0x80534684
UNKNOWN_FUNCTION(unk_805342e8);
// PAL: 0x80534684..0x805347f4
UNKNOWN_FUNCTION(unk_80534684);
// PAL: 0x805347f4..0x80534934
UNKNOWN_FUNCTION(RaceinfoPlayer_endRace);
// PAL: 0x80534934..0x805349b8
UNKNOWN_FUNCTION(unk_80534934);
// PAL: 0x805349b8..0x80534c78
UNKNOWN_FUNCTION(RaceinfoPlayer_endLap);
// PAL: 0x80534c78..0x80534cbc
UNKNOWN_FUNCTION(unk_80534c78);
// PAL: 0x80534cbc..0x80534ccc
UNKNOWN_FUNCTION(unk_80534cbc);
// PAL: 0x80534ccc..0x80534d6c
UNKNOWN_FUNCTION(unk_80534ccc);
// PAL: 0x80534d6c..0x80534df8
UNKNOWN_FUNCTION(unk_80534d6c);
// PAL: 0x80534df8..0x8053520c
UNKNOWN_FUNCTION(RaceinfoPlayer_updateCheckpoint);
// PAL: 0x8053520c..0x80535304
UNKNOWN_FUNCTION(unk_8053520c);
// PAL: 0x80535304..0x80535698
UNKNOWN_FUNCTION(RaceinfoPlayer_update);
// PAL: 0x80535698..0x8053569c
UNKNOWN_FUNCTION(unk_80535698);
// PAL: 0x8053569c..0x80535718
UNKNOWN_FUNCTION(unk_8053569c);
// PAL: 0x80535718..0x8053572c
UNKNOWN_FUNCTION(unk_80535718);
// PAL: 0x8053572c..0x80535864
UNKNOWN_FUNCTION(RaceinfoPlayer_getLapSplit);
// PAL: 0x80535864..0x80535904
UNKNOWN_FUNCTION(unk_80535864);
// PAL: 0x80535904..0x80535ca0
UNKNOWN_FUNCTION(unk_80535904);
// PAL: 0x80535ca0..0x80535d14
UNKNOWN_FUNCTION(RaceInfo_copyTimer);
// PAL: 0x80535d14..0x80535de8
UNKNOWN_FUNCTION(TimeAttackGamemode_canEndRace);
// PAL: 0x80535de8..0x80535e84
UNKNOWN_FUNCTION(unk_80535de8);
// PAL: 0x80535e84..0x80535ef4
UNKNOWN_FUNCTION(unk_80535e84);
// PAL: 0x80535ef4..0x80535f28
UNKNOWN_FUNCTION(unk_80535ef4);
// PAL: 0x80535f28..0x80535fe4
UNKNOWN_FUNCTION(unk_80535f28);
// PAL: 0x80535fe4..0x80536054
UNKNOWN_FUNCTION(unk_80535fe4);
// PAL: 0x80536054..0x80536208
UNKNOWN_FUNCTION(unk_80536054);
// PAL: 0x80536208..0x8053621c
UNKNOWN_FUNCTION(unk_80536208);
// PAL: 0x8053621c..0x80536230
UNKNOWN_FUNCTION(unk_8053621c);
// PAL: 0x80536230..0x80536248
UNKNOWN_FUNCTION(Raceinfo_isAtLeastStage);
// PAL: 0x80536248..0x805362dc
UNKNOWN_FUNCTION(unk_80536248);
// PAL: 0x805362dc..0x805365c8
UNKNOWN_FUNCTION(Raceinfo_getInitialPosAndRotForPlayer);
// PAL: 0x805365c8..0x80536828
UNKNOWN_FUNCTION(unk_805365c8);
// PAL: 0x80536828..0x805368c4
UNKNOWN_FUNCTION(unk_80536828);
// PAL: 0x805368c4..0x805368f8
UNKNOWN_FUNCTION(unk_805368c4);
// PAL: 0x805368f8..0x80536c84
UNKNOWN_FUNCTION(RaceinfoPlayer_updateGpRankScore);
// PAL: 0x80536c84..0x80537190
UNKNOWN_FUNCTION(unk_80536c84);
// PAL: 0x80537190..0x805371a4
UNKNOWN_FUNCTION(unk_80537190);
// PAL: 0x805371a4..0x805371a8
UNKNOWN_FUNCTION(unk_805371a4);
// PAL: 0x805371a8..0x805371e8
UNKNOWN_FUNCTION(unk_805371a8);
// PAL: 0x805371e8..0x8053724c
UNKNOWN_FUNCTION(unk_805371e8);
// PAL: 0x8053724c..0x805372b4
UNKNOWN_FUNCTION(unk_8053724c);
// PAL: 0x805372b4..0x805372bc
UNKNOWN_FUNCTION(unk_805372b4);
// PAL: 0x805372bc..0x80537320
UNKNOWN_FUNCTION(unk_805372bc);
// PAL: 0x80537320..0x80537388
UNKNOWN_FUNCTION(unk_80537320);
// PAL: 0x80537388..0x80537390
UNKNOWN_FUNCTION(unk_80537388);
// PAL: 0x80537390..0x805373f4
UNKNOWN_FUNCTION(unk_80537390);
// PAL: 0x805373f4..0x8053745c
UNKNOWN_FUNCTION(unk_805373f4);
// PAL: 0x8053745c..0x80537464
UNKNOWN_FUNCTION(unk_8053745c);
// PAL: 0x80537464..0x805374c8
UNKNOWN_FUNCTION(unk_80537464);
// PAL: 0x805374c8..0x80537530
UNKNOWN_FUNCTION(unk_805374c8);
// PAL: 0x80537530..0x80537538
UNKNOWN_FUNCTION(unk_80537530);
// PAL: 0x80537538..0x8053759c
UNKNOWN_FUNCTION(unk_80537538);
// PAL: 0x8053759c..0x80537604
UNKNOWN_FUNCTION(unk_8053759c);
// PAL: 0x80537604..0x8053760c
UNKNOWN_FUNCTION(unk_80537604);
// PAL: 0x8053760c..0x80537670
UNKNOWN_FUNCTION(unk_8053760c);
// PAL: 0x80537670..0x805376d8
UNKNOWN_FUNCTION(unk_80537670);
// PAL: 0x805376d8..0x805376e0
UNKNOWN_FUNCTION(unk_805376d8);
// PAL: 0x805376e0..0x80537740
UNKNOWN_FUNCTION(unk_805376e0);
// PAL: 0x80537740..0x80537830
UNKNOWN_FUNCTION(unk_80537740);
// PAL: 0x80537830..0x8053787c
UNKNOWN_FUNCTION(VEC3_fromCross);
// PAL: 0x8053787c..0x80537b80
UNKNOWN_FUNCTION(unk_8053787c);
// PAL: 0x80537b80..0x80537ba4
UNKNOWN_FUNCTION(unk_80537b80);
// PAL: 0x80537ba4..0x80537c54
UNKNOWN_FUNCTION(unk_80537ba4);
// PAL: 0x80537c54..0x80537c94
UNKNOWN_FUNCTION(unk_80537c54);
// PAL: 0x80537c94..0x80537cd4
UNKNOWN_FUNCTION(unk_80537c94);
// PAL: 0x80537cd4..0x80537f98
UNKNOWN_FUNCTION(unk_80537cd4);
// PAL: 0x80537f98..0x80538084
UNKNOWN_FUNCTION(unk_80537f98);
// PAL: 0x80538084..0x80538170
UNKNOWN_FUNCTION(unk_80538084);
// PAL: 0x80538170..0x805381a4
UNKNOWN_FUNCTION(unk_80538170);
// PAL: 0x805381a4..0x80538220
UNKNOWN_FUNCTION(unk_805381a4);
// PAL: 0x80538220..0x8053831c
UNKNOWN_FUNCTION(unk_80538220);
// PAL: 0x8053831c..0x80538344
UNKNOWN_FUNCTION(unk_8053831c);
// PAL: 0x80538344..0x80538418
UNKNOWN_FUNCTION(unk_80538344);

#ifdef __cplusplus
}
#endif

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
  s32 field25_0x34;
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

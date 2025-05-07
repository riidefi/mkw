#pragma once

#include <rk_types.h>
#include <decomp.h>

namespace System {

// More info: https://wiki.tockdom.com/wiki/Mission_Mode#Objectives
enum MissionObjective {
  OBJECTIVE_MINITURBO,
  OBJECTIVE_LAPRUN01,
  OBJECTIVE_LAPRUN02,
  OBJECTIVE_DRIFT,
  OBJECTIVE_ITEMBOX,
  OBJECTIVE_ENEMYDOWN01,
  OBJECTIVE_ENEMYDOWN02,
  OBJECTIVE_ENEMYDOWN03,
  OBJECTIVE_COINGET01,
  OBJECTIVE_TOGATE01,
  OBJECTIVE_ROCKETSTART,
  OBJECTIVE_ITEMHIT,
  OBJECTIVE_WHEELIE,
  OBJECTIVE_SLIPSTREAM,
  OBJECTIVE_DEFAULT = -1
};

// The game mode ID used specifically for competitions.
// More info: https://wiki.tockdom.com/wiki/RKC_(File_Format)#Game_Modes
enum CompetitionObjective {
  COMPETITION_TIME_TRIAL,
  COMPETITION_VS_RACE,
  COMPETITION_ENEMYDOWN01 = 3,
  COMPETITION_ENEMYDOWN02,
  COMPETITION_COINGET01,
  COMPETITION_TOGATE01,
  COMPETITION_ROCKETSTART,
  COMPETITION_ITEMHIT,
  COMPETITION_LAPRUN01 = 11,
  COMPETITION_LAPRUN02
};

struct CharacterVehicleChoice {
  s8 characterId;
  s8 vehicleId;
};

struct RawRKCO {
  char rkcoMagic[4];
  u16 competitionType;
  u8 courseId;
  u8 engineClass;
  u8 numLaps;
  u8 field9_0x09;
  u16 vehicleRestriction;
  u16 cameraAngle;
  u16 minimapObject;
  u16 horizontalWallGlitch;
  u16 field14_0x12;
  u16 cannonFlag;
  u16 cpuCount;
  CharacterVehicleChoice cpuCombos[11];
  u8 controllerRestriction;
  u8 field19_0x2f;
  u16 objectFiles;
  u16 score;
  u8 introSetting;
  u8 field23_0x35;
  /* Maximum time allowed for the competition record to be uploaded to the rankings.
     See 80510ab8
  */
  u16 maxUploadTime;
  u16 field25_0x38;
  u16 field26_0x3a;
};

struct RawCompetitionFile {
  char rkctMagic[4];
  s32 dataLength;
  s32 headerLength;
  s32 field3_0xc;
  RawRKCO rkco;
  inline u16 getSize() { return min32(11, rkco.cpuCount); }
};

struct CompetitionWrapper {
  bool isValid;
  RawCompetitionFile* fileRaw;
  s32 competitionId;
  s32 state;
  wchar_t* titleText;
  s32 titleTextLength;
  bool competitionUnavailable;
  s32 field10_0x1c;
};

// Also known as "KMT Scenario Entry". See https://wiki.tockdom.com/wiki/Mission_Mode#mission_single.kmt
struct CompetitionSettings {
  u16 mrFile; /* Mission Run file in Mission Mode (e.g. 3 -> mr03.szs) */
  u16 objective;  /* See the MissionObjective enum */
  u8 courseId;
  u8 characterId;
  u8 vehicleId;
  u8 engineClass;
  u8 field5_0x8[36]; /* unknown padding */
  u16 timeLimit;
  u8 field_0x2e;
  u8 controllerRestriction;
  u32 scoreRequired;  /* Score required to beat the competition */
  u32 rankScores[5];  /* Scores required to get a rank (only meant for Mission Mode) */
  u16 cameraAngle;
  u16 minimapObject;
  u16 horizontalWallGlitch;
  u16 field11_0x4e;
  u16 cannonFlag;
  u8 field13_0x52[6]; /* unknown padding */
  u16 cpuCount;
  CharacterVehicleChoice cpuCombos[11]; /* one for each CPU */

  inline void cpuCombosFromFile(RawCompetitionFile* file) {
    for (u8 i = 0; i < file->getSize(); i++) {
      this->cpuCombos[i] = file->rkco.cpuCombos[i];
    }
  }

  inline void cpuCombosFromWrapper2(const CompetitionWrapper& wrapper) {
    this->cpuCombosFromFile(wrapper.fileRaw);
  }
  
  inline void cpuCombosFromWrapper(const CompetitionWrapper& wrapper) {
    this->cpuCombosFromWrapper2(wrapper);
  }
};

} // namespace System

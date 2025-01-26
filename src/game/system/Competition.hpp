#pragma once

#include <rk_types.h>
#include <decomp.h>

namespace System {

struct CharacterVehicleChoice {
  s8 characterId;
  s8 vehicleId;
};

struct RawCompetitionFile {
  char rkctMagic[4];
  s32 dataLength;
  s32 headerLength;
  s32 field3_0xc;
  char rkcoMagic[4];
  u16 competitionType;
  u8 courseId;
  u8 engineClass;
  u8 numLaps;
  u8 field9_0x19;
  u16 vehicleRestriction;
  u16 cameraAngle;
  u16 minimapObject;
  u16 field13_0x20;
  u16 field14_0x22;
  u16 cannonFlag;
  u16 cpuCount;
  CharacterVehicleChoice cpuCombos[11];
  u8 controllerRestriction;
  u8 field19_0x3f;
  u16 objectFiles;
  u16 score;
  u8 s32roSetting;
  u8 field23_0x45;
  u16 field24_0x46;
  u16 field25_0x48;
  u16 field26_0x4a;
  inline u16 getSize() { return MIN(11, cpuCount); }
};

struct CompetitionWrapper {
  bool isValid;
  RawCompetitionFile* fileRaw;
  s32 field5_0x8;
  s32 field6_0xc;
  s32 field7_0x10;
  s32 field8_0x14;
  s32 field9_0x18;
  s32 field10_0x1c;
};

struct CompetitionSettings {
  u16 field0_0x0;
  u16 field1_0x2; /* something depending on competition type */
  u8 courseId;
  u8 padding[2];
  u8 engineClass;
  u8 field5_0x8[39]; /* unknown padding */
  u8 controllerRestriction;
  u32 field7_0x30[6]; /* those s32s probably represent amount of coins, gates
                         etc */
  u16 cameraAngle;
  u16 minimapObject;
  u16 field10_0x4c;
  u16 field11_0x4e;
  u16 cannonFlag;
  u8 field13_0x52[6]; /* unknown padding */
  u16 cpuCount;
  CharacterVehicleChoice cpuCombos[11]; /* one for each CPU */

  inline void cpuCombosFromFile(RawCompetitionFile* file) {
    for (u8 i = 0; i < file->getSize(); i++) {
      this->cpuCombos[i] = file->cpuCombos[i];
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

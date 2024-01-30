#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x8078e4e8..0x8078e4f0
UNKNOWN_FUNCTION(CourseModel_setKclWrapper8);
// PAL: 0x8078e4f0..0x8078e588
UNKNOWN_FUNCTION(unk_8078e4f0);
// PAL: 0x8078e588..0x8078e694
UNKNOWN_FUNCTION(unk_8078e588);
// PAL: 0x8078e694..0x8078e7c4
UNKNOWN_FUNCTION(unk_8078e694);
// PAL: 0x8078e7c4..0x8078e8ec
UNKNOWN_FUNCTION(unk_8078e7c4);
// PAL: 0x8078e8ec..0x8078e8f0
UNKNOWN_FUNCTION(unk_8078e8ec);
// PAL: 0x8078e8f0..0x8078ea98
UNKNOWN_FUNCTION(unk_8078e8f0);
// PAL: 0x8078ea98..0x8078eb00
UNKNOWN_FUNCTION(unk_8078ea98);
// PAL: 0x8078eb00..0x8078eca8
UNKNOWN_FUNCTION(unk_8078eb00);
// PAL: 0x8078eca8..0x8078eef4
UNKNOWN_FUNCTION(unk_8078eca8);
// PAL: 0x8078eef4..0x8078f140
UNKNOWN_FUNCTION(unk_8078eef4);
// PAL: 0x8078f140..0x8078f320
UNKNOWN_FUNCTION(unk_8078f140);
// PAL: 0x8078f320..0x8078f500
UNKNOWN_FUNCTION(unk_8078f320);
// PAL: 0x8078f500..0x8078f784
UNKNOWN_FUNCTION(unk_8078f500);
// PAL: 0x8078f784..0x8078fa08
UNKNOWN_FUNCTION(unk_8078f784);
// PAL: 0x8078fa08..0x8078fbb0
UNKNOWN_FUNCTION(unk_8078fa08);
// PAL: 0x8078fbb0..0x8078fd58
UNKNOWN_FUNCTION(unk_8078fbb0);
// PAL: 0x8078fd58..0x8078ffa4
UNKNOWN_FUNCTION(unk_8078fd58);
// PAL: 0x8078ffa4..0x807901f0
UNKNOWN_FUNCTION(unk_8078ffa4);
// PAL: 0x807901f0..0x807903bc
UNKNOWN_FUNCTION(unk_807901f0);
// PAL: 0x807903bc..0x80790588
UNKNOWN_FUNCTION(unk_807903bc);
// PAL: 0x80790588..0x807907f8
UNKNOWN_FUNCTION(unk_80790588);
// PAL: 0x807907f8..0x80790a68
UNKNOWN_FUNCTION(unk_807907f8);
// PAL: 0x80790a68..0x80790ac0
UNKNOWN_FUNCTION(unk_80790a68);
// PAL: 0x80790ac0..0x80790ad0
UNKNOWN_FUNCTION(unk_80790ac0);
// PAL: 0x80790ad0..0x80790ad8
UNKNOWN_FUNCTION(unk_80790ad0);

#ifdef __cplusplus
}
#endif

#include "CourseColManager.hpp"
#include "game/geo2/ObjDrivableManager.hpp"
#include "game/system/ResourceManager.hpp"
#include "game/system/RKResource.hpp"

#include <nw4r/g3d/g3d_resfile.h>

namespace Field {
class CourseModel {
public:
  static CourseModel* spInstance;
  static void createInstance();
  static void destroyInstance();

  CourseModel();
  ~CourseModel();
  static void loadModels(bool isCourse, nw4r::g3d::ResFile& resFile, System::DrawModel** drawModel, const char* modelPath, char* modelName, u32 flags);

private:
  System::DrawModel* courseModel;
  System::DrawModel* vrcornModel;
  nw4r::g3d::ResFile courseRes;
  nw4r::g3d::ResFile vrcornRes;
  SoftWallColInfo* softWallColInfo;
};
}

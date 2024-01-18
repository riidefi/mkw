#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x807c2a60..0x807c2bd8
UNKNOWN_FUNCTION(unk_807c2a60);
// PAL: 0x807c2bd8..0x807c2da0
UNKNOWN_FUNCTION(unk_807c2bd8);
// PAL: 0x807c2da0..0x807c2f18
UNKNOWN_FUNCTION(unk_807c2da0);
// PAL: 0x807c2f18..0x807c30e0
UNKNOWN_FUNCTION(unk_807c2f18);
// PAL: 0x807c30e0..0x807c3258
UNKNOWN_FUNCTION(unk_807c30e0);
// PAL: 0x807c3258..0x807c3554
UNKNOWN_FUNCTION(unk_807c3258);
// PAL: 0x807c3554..0x807c36cc
UNKNOWN_FUNCTION(unk_807c3554);
// PAL: 0x807c36cc..0x807c39c8
UNKNOWN_FUNCTION(unk_807c36cc);
// PAL: 0x807c39c8..0x807c3b5c
UNKNOWN_FUNCTION(unk_807c39c8);
// PAL: 0x807c3b5c..0x807c3cf0
UNKNOWN_FUNCTION(unk_807c3b5c);
// PAL: 0x807c3cf0..0x807c3e84
UNKNOWN_FUNCTION(unk_807c3cf0);
// PAL: 0x807c3e84..0x807c4018
UNKNOWN_FUNCTION(unk_807c3e84);
// PAL: 0x807c4018..0x807c41a4
UNKNOWN_FUNCTION(unk_807c4018);
// PAL: 0x807c41a4..0x807c4330
UNKNOWN_FUNCTION(unk_807c41a4);
// PAL: 0x807c4330..0x807c44bc
UNKNOWN_FUNCTION(unk_807c4330);
// PAL: 0x807c44bc..0x807c4648
UNKNOWN_FUNCTION(unk_807c44bc);
// PAL: 0x807c4648..0x807c47f0
UNKNOWN_FUNCTION(unk_807c4648);
// PAL: 0x807c47f0..0x807c4998
UNKNOWN_FUNCTION(unk_807c47f0);
// PAL: 0x807c4998..0x807c4b40
UNKNOWN_FUNCTION(unk_807c4998);
// PAL: 0x807c4b40..0x807c4ce8
UNKNOWN_FUNCTION(unk_807c4b40);

#ifdef __cplusplus
}
#endif

#include "RKGndCol.hpp"
#include "egg/math/eggMatrix.hpp"

struct SoftWallColInfo {
  EGG::Vector3f bboxLow;
  EGG::Vector3f bboxHigh;
  // bboxLow + bboxHigh (wtf). I think this has to do with the offset that needs to be added
  // to the wheels when they collide to the ground so they don't "sink"
  // ref: 0x805998c0 (collisiondata.nrm gets set to lowPlusHigh)
  EGG::Vector3f lowPlusHigh;
  f32 softWallDist;
  EGG::Vector3f softWallNrm;
};

/**
 * Manager for course KCL
 */
namespace Field {
class CourseColManager {
public:
  static CourseColManager* spInstance;
  static void createInstance();
  static void destroyInstance();

  CourseColManager();
  ~CourseColManager();

  void init(const KCollisionHeader& header);
  f32 setThickness(RKGndCol* colMgr);
  void scaledNarrowScopeLocal(RKGndCol* maybeColMgr, const EGG::Vector3f& pos, u32 typeMask, f32 scale, f32 radius, u32 unused);
private:
  // KCL handle
  RKGndCol* colMgr;
  f32 kclScale;
  SoftWallColInfo* softWallColInfo;
  // pose of entity being checked for collision with course
  EGG::Matrix34f* localMtx;
};
}

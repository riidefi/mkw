#pragma once

#include <rk_types.h>

#include <decomp.h>

#include "egg/math/eggMatrix.hpp"
#include "egg/math/eggVector.hpp"

#include "RKGndCol.hpp"
#include "CourseColManager.hpp"

namespace Field {
class ObjColManager {
public:
  ObjColManager(const KCollisionHeader& header);
  ~ObjColManager();

  void narrowScopeLocal(const EGG::Vector3f& pos, u32 typeMask, f32 radius, u32 unused);

  static void kclLowWorld(EGG::Vector3f& v, const ObjColManager& objColMgr);
  static void kclHighWorld(EGG::Vector3f& v, const ObjColManager& objColMgr);

  bool checkPointPartial(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfoPartial* colInfo, u32* typeMaskOut);
  bool checkPointPartialPush(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfoPartial* colInfo, u32* typeMaskOut);
  bool checkPointFull(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfo* colInfo, u32* typeMaskOut);
  bool checkPointFullPush(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfo* colInfo, u32* typeMaskOut);

  bool checkSpherePartial(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfoPartial* colInfo, u32* typeMaskOut, f32 radius);
  bool checkSpherePartialPush(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfoPartial* colInfo, u32* typeMaskOut, f32 radius);
  bool checkSphereFull(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfo* colInfo, u32* typeMaskOut, f32 radius);
  bool checkSphereFullPush(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfo* colInfo, u32* typeMaskOut, f32 radius);

  bool checkPointCachedPartial(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfoPartial* colInfo, u32* typeMaskOut);
  bool checkPointCachedPartialPush(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfoPartial* colInfo, u32* typeMaskOut);
  bool checkPointCachedFull(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfo* colInfo, u32* typeMaskOut);
  bool checkPointCachedFullPush(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfo* colInfo, u32* typeMaskOut);

  bool checkSphereCachedPartial(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfoPartial* colInfo, u32* typeMaskOut, f32 radius);
  bool checkSphereCachedPartialPush(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfoPartial* colInfo, u32* typeMaskOut, f32 radius);
  bool checkSphereCachedFull(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfo* colInfo, u32* typeMaskOut, f32 radius);
  bool checkSphereCachedFullPush(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfo* colInfo, u32* typeMaskOut, f32 radius);

private:
  RKGndCol* colMgr;
  EGG::Matrix34f mtx;
  EGG::Matrix34f mtxInv;
  f32 kclScale;
  EGG::Vector3f _68;
};
}

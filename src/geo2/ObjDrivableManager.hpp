#pragma once

#include <rk_types.h>

#include <decomp.h>

#include "egg/math/eggVector.hpp"

#include "geo/ObjDrivable.hpp"
#include "geo/BoxColManager.hpp"
#include "field/DrivableColInfo.hpp"
#include "field/CourseColManager.hpp"

namespace GeoObj {
class ObjDrivableManager {
public:
  static ObjDrivableManager* spInstance;
  static ObjDrivableManager* createInstance();
  static void destroyInstance();

  ObjDrivableManager();
  virtual ~ObjDrivableManager();

  void initObjs();
  /// Draws debug shapes for objects if the need to. Unused, but potentially used during development, since some objects implement such functionallity
  /// (for example ObakeBlock). It would be interesting to see what those drawings look like
  void debugDraw();
  /// Updates all objects if the need to
  void update();
  /// Adds drivable to list
  s32 push(ObjDrivable* obj);

  // Collision funcs
  void narrowScopeLocal(const EGG::Vector3f& pos, f32 radius, u32 colTypeMask, u32 unused);

  bool checkPointPartial(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, Field::ColInfoPartial* colInfo, u32* typeMaskOut) NEVER_INLINE;
  bool checkPointPartialPush(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, Field::ColInfoPartial* colInfo, u32* typeMaskOut) NEVER_INLINE;
  bool checkPointFull(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, Field::ColInfo* colInfo, u32* typeMaskOut) NEVER_INLINE;
  bool checkPointFullPush(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, Field::ColInfo* colInfo, u32* typeMaskOut) NEVER_INLINE;

  bool checkSpherePartial(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, Field::ColInfoPartial* colInfo, u32* typeMaskOut, f32 radius, u32 start) NEVER_INLINE;
  bool checkSpherePartialPush(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, Field::ColInfoPartial* colInfo, u32* typeMaskOut, f32 radius, u32 start) NEVER_INLINE;
  bool checkSphereFull(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, Field::ColInfo* colInfo, u32* typeMaskOut, f32 radius, u32 start) NEVER_INLINE;
  bool checkSphereFullPush(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, Field::ColInfo* colInfo, u32* typeMaskOut, f32 radius, u32 start) NEVER_INLINE;

  bool checkPointCachedPartial(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, Field::ColInfoPartial* colInfo, u32* typeMaskOut);
  bool checkPointCachedPartialPush(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, Field::ColInfoPartial* colInfo, u32* typeMaskOut);
  bool checkPointCachedFull(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, Field::ColInfo* colInfo, u32* typeMaskOut);
  bool checkPointCachedFullPush(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, Field::ColInfo* colInfo, u32* typeMaskOut);

  bool checkSphereCachedPartial(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, Field::ColInfoPartial* colInfo, u32* typeMaskOut, f32 radius, u32 start);
  bool checkSphereCachedPartialPush(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, Field::ColInfoPartial* colInfo, u32* typeMaskOut, f32 radius, u32 start);
  bool checkSphereCachedFull(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, Field::ColInfo* colInfo, u32* typeMaskOut, f32 radius, u32 start);
  bool checkSphereCachedFullPush(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, Field::ColInfo* colInfo, u32* typeMaskOut, f32 radius, u32 start);

private:
  u16 objCount;
  ObjDrivable** objs;
  u16 needUpdateCount;
  ObjDrivable** needUpdate;
  u16 drawDebugCount;
  ObjDrivable** drawDebug;
  u32 _1c;
};
}

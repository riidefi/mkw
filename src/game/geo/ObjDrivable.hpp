
#pragma once

#include "ObjBase.hpp"

#include "game/field/CourseColManager.hpp"

namespace GeoObj {
class ObjDrivable : public ObjBase {
public:
  virtual ~ObjDrivable();

  // signatures TBA
  virtual void vfb4() = 0;
  virtual void initCollision();
  virtual void registerBoxColUnit();

  virtual bool checkPointPartial(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, Field::ColInfoPartial* colInfo, u32* typeMaskOut) = 0;
  virtual bool checkPointPartialPush(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, Field::ColInfoPartial* colInfo, u32* typeMaskOut) = 0;
  virtual bool checkPointFull(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, Field::ColInfo* colInfo, u32* typeMaskOut) = 0;
  virtual bool checkPointFullPush(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, Field::ColInfo* colInfo, u32* typeMaskOut) = 0;

  virtual bool checkSpherePartial(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, Field::ColInfoPartial* colInfo, u32* typeMaskOut, f32 radius, u32 start) = 0;
  virtual bool checkSpherePartialPush(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, Field::ColInfoPartial* colInfo, u32* typeMaskOut, f32 radius, u32 start) = 0;
  virtual bool checkSphereFull(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, Field::ColInfo* colInfo, u32* typeMaskOut, f32 radius, u32 start) = 0;
  virtual bool checkSphereFullPush(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, Field::ColInfo* colInfo, u32* typeMaskOut, f32 radius, u32 start) = 0;

  virtual bool narrowScopeLocal(const EGG::Vector3f& pos, f32 radius, u32 typeMask, u32 unused) = 0;

  virtual bool checkPointCachedPartial(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, Field::ColInfoPartial* colInfo, u32* typeMaskOut) = 0;
  virtual bool checkPointCachedPartialPush(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, Field::ColInfoPartial* colInfo, u32* typeMaskOut) = 0;
  virtual bool checkPointCachedFull(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, Field::ColInfo* colInfo, u32* typeMaskOut) = 0;
  virtual bool checkPointCachedFullPush(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, Field::ColInfo* colInfo, u32* typeMaskOut) = 0;

  virtual bool checkSphereCachedPartial(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, Field::ColInfoPartial* colInfo, u32* typeMaskOut, f32 radius, u32 start) = 0;
  virtual bool checkSphereCachedPartialPush(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, Field::ColInfoPartial* colInfo, u32* typeMaskOut, f32 radius, u32 start) = 0;
  virtual bool checkSphereCachedFull(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, Field::ColInfo* colInfo, u32* typeMaskOut, f32 radius, u32 start) = 0;
  virtual bool checkSphereCachedFullPush(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, Field::ColInfo* colInfo, u32* typeMaskOut, f32 radius, u32 start) = 0;

  virtual void vf104();
  virtual void vf108();
  virtual void vf10c();
  virtual void vf110();
  virtual void vf114();
  virtual void vf118();
  virtual void vf11c();
};
}

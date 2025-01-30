#pragma once

#include <rk_types.h>

#include <decomp.h>

#include "CourseColManager.hpp"
#include "geo2/ObjDrivableManager.hpp"
#include "system/ResourceManager.hpp"
#include "system/RKResource.hpp"

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
  void setSoftWallColInfo(SoftWallColInfo* softWallColInfo);

  // collision query funcs
  void narrowScopeLocal(const EGG::Vector3f& pos, f32 radius, u32 typeMask, u32 unused);

  bool checkPointPartial(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfoPartial* colInfo, u32* typeMaskOut);
  bool checkPointPartialPush(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfoPartial* colInfo, u32* typeMaskOut);
  bool checkPointFull(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfo* colInfo, u32* typeMaskOut);
  bool checkPointFullPush(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfo* colInfo, u32* typeMaskOut);

  bool checkSpherePartial(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfoPartial* colInfo, u32* typeMaskOut, f32 radius, u32 start);
  bool checkSpherePartialPush(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfoPartial* colInfo, u32* typeMaskOut, f32 radius, u32 start);
  bool checkSphereFull(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfo* colInfo, u32* typeMaskOut, f32 radius, u32 start);
  bool checkSphereFullPush(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfo* colInfo, u32* typeMaskOut, f32 radius, u32 start);

  bool checkPointCachedPartial(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfoPartial* colInfo, u32* typeMaskOut);
  bool checkPointCachedPartialPush(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfoPartial* colInfo, u32* typeMaskOut);
  bool checkPointCachedFull(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfo* colInfo, u32* typeMaskOut);
  bool checkPointCachedFullPush(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfo* colInfo, u32* typeMaskOut);

  bool checkSphereCachedPartial(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfoPartial* colInfo, u32* typeMaskOut, f32 radius, u32 start);
  bool checkSphereCachedPartialPush(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfoPartial* colInfo, u32* typeMaskOut, f32 radius, u32 start);
  bool checkSphereCachedFull(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfo* colInfo, u32* typeMaskOut, f32 radius, u32 start);
  bool checkSphereCachedFullPush(const EGG::Vector3f& pos, const EGG::Vector3f& prevPos, u32 typeMask, ColInfo* colInfo, u32* typeMaskOut, f32 radius, u32 start);

private:
  System::DrawModel* courseModel;
  System::DrawModel* vrcornModel;
  nw4r::g3d::ResFile courseRes;
  nw4r::g3d::ResFile vrcornRes;
  SoftWallColInfo* softWallColInfo;
};
}

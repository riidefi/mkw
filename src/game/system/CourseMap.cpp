#include "CourseMap.hpp"

#include "game/system/RaceConfig.hpp"
#include "game/system/ResourceManager.hpp"

namespace System {

// .bss
CourseMap* CourseMap::spInstance;

CourseMap* CourseMap::createInstance() {
  if (spInstance == nullptr) {
    spInstance = new CourseMap();
  }

  return spInstance;
}

void CourseMap::destroyInstance() {
  if (spInstance != nullptr) {
    delete spInstance;
    spInstance = nullptr;
  }
}

CourseMap::CourseMap()
    : mpStartPoint(nullptr), mpEnemyPath(nullptr), mpCheckPath(nullptr),
      mpCheckPoint(nullptr), mpGeoObj(nullptr), mpPointInfo(nullptr),
      mpArea(nullptr), mpCamera(nullptr), mpGoalCamera(nullptr),
      mpOpeningPanCamera(nullptr), _50(0) {}

CourseMap::~CourseMap() {}

void* CourseMap::loadFile(s32 archiveIdx, const char* filename) {
  return ResourceManager::spInstance.nonvol->getFile(archiveIdx, filename,
                                                     nullptr);
}

MapdataFileAccessor::MapdataFileAccessor(const MapdataFileAccessor::SData* data)
    : mpData(data) {
  u32 offset = data->headerSize - data->numSections * 4;
  mSectionDefOffset = offset;
  mpSectionDef = (u32*)((u8*)mpData + offset);
  if (offset > 12) {
    mVersion = *((u32*)mpSectionDef - 1);
  } else {
    mVersion = 0;
  }
}

u8 MapdataCamera::getCameraType() const { return mpData->cameraType; }

u16 CourseMap::getCameraCount() const {
  return mpCamera != nullptr ? mpCamera->size() : 0;
}

u32 MapdataFileAccessor::getVersion() const { return mVersion; }

s8 MapdataCameraAccessor::getExtraValue() const {
  return sectionHeader->extraValue;
}

void MapdataAreaBase::setIndex(u16 idx) { mIndex = idx; }

u16 CourseMap::getAreaCount() const {
  return mpArea != nullptr ? mpArea->size() : 0;
}

u16 CourseMap::getEnemyPointCount() const {
  return mpEnemyPoint != nullptr ? mpEnemyPoint->size() : 0;
}

u16 CourseMap::getItemPointCount() const {
  return mpItemPoint != nullptr ? mpItemPoint->size() : 0;
}

u16 CourseMap::getJugemPointCount() const {
  return mpJugemPoint != nullptr ? mpJugemPoint->size() : 0;
}

u16 CourseMap::getStartPointCount() const {
  return mpStartPoint != nullptr ? mpStartPoint->size() : 0;
}

u8 MapdataStage::getStartConfig() const { return mpData->mStartConfig; }

u32 MapdataStage::getFlareColor() const { return mpData->mFlareColor; }

bool MapdataStage::flareToggleEnabled() const { return mpData->mFlareToggle; }

MapdataStageAccessor* CourseMap::parseStage(u32 sectionName) {
  const KmpSectionHeader* sectionPtr = mpCourse->findSection(sectionName);

  MapdataStageAccessor* accessor = nullptr;
  if (sectionPtr) {
    accessor = new MapdataStageAccessor(sectionPtr);
  }

  return accessor;
}

MapdataMissionPointAccessor* CourseMap::parseMissionPoints(u32 sectionName) {
  const KmpSectionHeader* sectionPtr = mpCourse->findSection(sectionName);

  MapdataMissionPointAccessor* accessor = nullptr;
  if (sectionPtr) {
    accessor = new MapdataMissionPointAccessor(sectionPtr);
  }

  return accessor;
}

MapdataCannonPointAccessor* CourseMap::parseCannonPoints(u32 sectionName) {
  const KmpSectionHeader* sectionPtr = mpCourse->findSection(sectionName);

  MapdataCannonPointAccessor* accessor = nullptr;
  if (sectionPtr) {
    accessor = new MapdataCannonPointAccessor(sectionPtr);
  }

  return accessor;
}

MapdataJugemPointAccessor* CourseMap::parseJugemPoints(u32 sectionName) {
  const KmpSectionHeader* sectionPtr = mpCourse->findSection(sectionName);

  MapdataJugemPointAccessor* accessor = nullptr;
  if (sectionPtr) {
    accessor = new MapdataJugemPointAccessor(sectionPtr);
  }

  return accessor;
}

MapdataCameraAccessor* CourseMap::parseCameras(u32 sectionName) {
  const KmpSectionHeader* sectionPtr = mpCourse->findSection(sectionName);

  MapdataCameraAccessor* accessor = nullptr;
  if (sectionPtr) {
    accessor = new MapdataCameraAccessor(sectionPtr);
  }

  return accessor;
}

MapdataAreaAccessor* CourseMap::parseAreas(u32 sectionName) {
  const KmpSectionHeader* sectionPtr = mpCourse->findSection(sectionName);

  MapdataAreaAccessor* accessor = nullptr;
  if (sectionPtr) {
    accessor = new MapdataAreaAccessor(sectionPtr);
  }

  return accessor;
}

MapdataPointInfoAccessor* CourseMap::parsePointInfo(u32 sectionName) {
  const KmpSectionHeader* sectionPtr = mpCourse->findSection(sectionName);

  MapdataPointInfoAccessor* accessor = nullptr;
  if (sectionPtr) {
    accessor = new MapdataPointInfoAccessor(sectionPtr);
  }

  return accessor;
}

MapdataGeoObjAccessor* CourseMap::parseGeoObjs(u32 sectionName) {
  const KmpSectionHeader* sectionPtr = mpCourse->findSection(sectionName);

  MapdataGeoObjAccessor* accessor = nullptr;
  if (sectionPtr) {
    accessor = new MapdataGeoObjAccessor(sectionPtr);
  }

  return accessor;
}

MapdataItemPointAccessor* CourseMap::parseItemPoints(u32 sectionName) {
  const KmpSectionHeader* sectionPtr = mpCourse->findSection(sectionName);

  MapdataItemPointAccessor* accessor = nullptr;
  if (sectionPtr) {
    accessor = new MapdataItemPointAccessor(sectionPtr);
  }

  return accessor;
}

MapdataItemPathAccessor* CourseMap::parseItemPaths(u32 sectionName) {
  const KmpSectionHeader* sectionPtr = mpCourse->findSection(sectionName);

  MapdataItemPathAccessor* accessor = nullptr;
  if (sectionPtr) {
    accessor = new MapdataItemPathAccessor(sectionPtr);
  }

  return accessor;
}

MapdataEnemyPointAccessor* CourseMap::parseEnemyPoints(u32 sectionName) {
  const KmpSectionHeader* sectionPtr = mpCourse->findSection(sectionName);

  MapdataEnemyPointAccessor* accessor = nullptr;
  if (sectionPtr) {
    accessor = new MapdataEnemyPointAccessor(sectionPtr);
  }

  return accessor;
}

MapdataEnemyPathAccessor* CourseMap::parseEnemyPaths(u32 sectionName) {
  const KmpSectionHeader* sectionPtr = mpCourse->findSection(sectionName);

  MapdataEnemyPathAccessor* accessor = nullptr;
  if (sectionPtr) {
    accessor = new MapdataEnemyPathAccessor(sectionPtr);
  }

  return accessor;
}

MapdataStartPointAccessor* CourseMap::parseKartpoints(u32 sectionName) {
  const KmpSectionHeader* sectionPtr = mpCourse->findSection(sectionName);

  MapdataStartPointAccessor* accessor = nullptr;
  if (sectionPtr) {
    accessor = new MapdataStartPointAccessor(sectionPtr);
  }

  return accessor;
}

MapdataAreaBase* MapdataAreaAccessor::get(u16 i) const {
  return i < this->size() ? this->entries[i] : nullptr;
}

MapdataJugemPoint* MapdataJugemPointAccessor::get(u16 i) const {
  return i < this->size() ? this->entries[i] : nullptr;
}

MapdataStartPoint* MapdataStartPointAccessor::get(u16 i) const {
  return i < this->size() ? this->entries[i] : nullptr;
}

MapdataGeoObj* CourseMap::getGeoObj(u16 i) const {
  u16 count = mpGeoObj ? mpGeoObj->size() : 0;
  return i < count ? mpGeoObj->get(i) : nullptr;
}

MapdataPointInfo* MapdataGeoObj::getPointInfo() const {
  return mpData->pathId == -1
             ? nullptr
             : CourseMap::instance()->getPointInfo(mpData->pathId);
}

const KmpSectionHeader*
MapdataFileAccessor::findSection(u32 sectionName) const {
  const KmpSectionHeader* sectionPtr = nullptr;

  for (u32 i = 0; i < mpData->numSections; i++) {
    const KmpSectionHeader* header =
        (const KmpSectionHeader*)((u8*)mpData + mpData->headerSize +
                                  mpSectionDef[i]);
    if (header->sectionMagic == sectionName) {
      sectionPtr = header;
      break;
    }
  }

  return sectionPtr;
}

MapdataStartPointAccessor::MapdataStartPointAccessor(
    const KmpSectionHeader* header)
    : MapdataAccessorBase<MapdataStartPoint, MapdataStartPoint::SData>(header) {
  if (CourseMap::instance()->getVersion() > 1830) {
    init((const MapdataStartPoint::SData*)(sectionHeader + 1),
         sectionHeader->entryCount);
  } else {
    init((const MapdataStartPoint::SData*)((u8*)sectionHeader + 4), 1);
  }
}

MapdataStartPoint* CourseMap::getStartPoint(u16 i) const {
  u16 count = mpStartPoint ? mpStartPoint->size() : 0;
  return i < count ? mpStartPoint->get(i) : nullptr;
}

MapdataEnemyPoint* CourseMap::getEnemyPoint(u16 i) const {
  u16 count = mpEnemyPoint ? mpEnemyPoint->size() : 0;
  return i < count ? mpEnemyPoint->get(i) : nullptr;
}

MapdataEnemyPath* CourseMap::getEnemyPath(u16 i) const {
  u16 count =
      (mpEnemyPath && mpEnemyPath->size() != 0) ? mpEnemyPath->size() : 0;
  return i < count ? mpEnemyPath->get(i) : nullptr;
}

MapdataItemPoint* CourseMap::getItemPoint(u16 i) const {
  u16 count = mpItemPoint ? mpItemPoint->size() : 0;
  return i < count ? mpItemPoint->get(i) : nullptr;
}

MapdataItemPath* CourseMap::getItemPath(u16 i) const {
  u16 count = (mpItemPath && mpItemPath->size() != 0) ? mpItemPath->size() : 0;
  return i < count ? mpItemPath->get(i) : nullptr;
}


MapdataCheckPoint* CourseMap::getCheckPoint(u16 i) const {
  u16 count = mpCheckPoint ? mpCheckPoint->size() : 0;
  return i < count ? mpCheckPoint->get(i) : 0;
}

MapdataCheckPath* CourseMap::getCheckPath(u16 i) const {
  u16 count = mpCheckPath ? mpCheckPath->size() : 0;
  return i < count ? mpCheckPath->get(i) : 0;
}
}

// Scheduling - https://decomp.me/scratch/hDqoW
#ifdef NON_MATCHING
MapdataPointInfoAccessor::MapdataPointInfoAccessor(
    const KmpSectionHeader* header)
    : MapdataAccessorBase<MapdataPointInfo, MapdataPointInfo::SData>(header) {
  init(sectionHeader->entryCount);
}
#endif

namespace System {

MapdataPointInfo* CourseMap::getPointInfo(u16 i) const {
  u16 count = mpPointInfo ? mpPointInfo->size() : 0;
  return i < count ? mpPointInfo->get(i) : 0;
}

MapdataAreaBase::MapdataAreaBase(const SData* data) : mIndex(-1) {
  mpData = data;
  mBoundingSphereRadiusSq = 0.0f;
  mEllipseAspectRatio = 0.0f;
  mEllipseXRadiusSq = 0.0f;
  mDims.z = 0.0f;
  mDims.y = 0.0f;
  mDims.x = 0.0f;
  mXAxis.z = 0.0f;
  mXAxis.y = 0.0f;
  mXAxis.x = 0.0f;
  mYAxis.z = 0.0f;
  mYAxis.y = 0.0f;
  mYAxis.x = 0.0f;
  mZAxis.z = 0.0f;
  mZAxis.y = 0.0f;
  mZAxis.x = 0.0f;
}
}

#ifdef NON_MATCHING
// Stack + regswap - https://decomp.me/scratch/1tQoj
//MARK_FLOW_CHECK(0x805160b0);
bool MapdataAreaBase::isInside(const EGG::Vector3f& pos) const {
  f32 x = mpData->position.x - pos.x;
  f32 y = mpData->position.y - pos.y;
  f32 z = mpData->position.z - pos.z;

  EGG::Vector3f pos_(x, y, z);
  return pos_.dot() > mBoundingSphereRadiusSq ? false : isInsideShape(pos);
}
#endif

namespace System {
s32 MapdataAreaBase::getRouteId() const {
  // Of course it uses r0
  return CourseMap::instance()->getVersion() >= 2200 ? (s8)mpData->railID : -1;
}

} // namespace System

// Function is too optimized - https://decomp.me/scratch/aErgS
#ifdef NON_MATCHING
namespace System {

MapdataPointInfo* MapdataAreaBase::getPointInfo() const {
  return getRouteId() == -1 ? nullptr
                            : CourseMap::instance()->getPointInfo(getRouteId());
}

} // namespace System
#endif

#if 0
namespace System {
MapdataAreaBox::MapdataAreaBox(const SData* data) : MapdataAreaBase(data) {
  mDims.x = 0.5f * 10000.0f * data->scale.x;
  mDims.y = 0.5f * 10000.0f * data->scale.y;
  mDims.z = 0.5f * 10000.0f * data->scale.z;

  mEllipseAspectRatio = 0.0f;
  mEllipseXRadiusSq = 0.0f;
  mBoundingSphereRadiusSq = data->scale.x * data->scale.x +
                            data->scale.y * data->scale.y +
                            data->scale.z * data->scale.z;

  EGG::Quatf areaRot;
  areaRot.setRPY(DEG2RAD(data->rotation.x), DEG2RAD(data->rotation.y),
                 DEG2RAD(data->rotation.z));

  EGG::Vector3f areaX, areaY, areaZ;
  VEC3_fromQuaternionRotated(areaX, areaRot, EGG::Vector3f::ex);
  mXAxis = areaX;
  VEC3_fromQuaternionRotated(areaY, areaRot, EGG::Vector3f::ey);
  mYAxis = areaY;
  VEC3_fromQuaternionRotated(areaZ, areaRot, EGG::Vector3f::ez);
  mZAxis = areaZ;
}
} // namespace System
#endif

namespace System {
MapdataAreaBase* CourseMap::getArea(u16 i) const {
  u16 count = mpArea ? mpArea->size() : 0;
  return i < count ? mpArea->get(i) : 0;
}

MapdataAreaBase* CourseMap::getAreaByPriority(u16 i) const {
  u16 count = mpArea ? mpArea->size() : 0;
  return i < count ? mpArea->getByPriority(i) : 0;
}


MapdataCamera* CourseMap::getCamera(u16 i) const {
  u16 count = mpCamera ? mpCamera->size() : 0;
  return i < count ? mpCamera->get(i) : 0;
}

bool MapdataEnemyPoint::isNonPrivateBattle() {
  return (RaceConfig::spInstance->mRaceScenario.mSettings.mGameMode ==
              RaceConfig::Settings::GAMEMODE_BATTLE ||
          RaceConfig::spInstance->mRaceScenario.mSettings.mGameMode ==
              RaceConfig::Settings::GAMEMODE_PUBLIC_BATTLE);
}

MapdataJugemPoint* CourseMap::getJugemPoint(u16 i) const {
  u16 count = mpJugemPoint ? mpJugemPoint->size() : 0;
  return i < count ? mpJugemPoint->get(i) : 0;
}

MapdataCannonPoint* CourseMap::getCannonPoint(u16 i) const {
  u16 count = mpCannonPoint ? mpCannonPoint->size() : 0;
  return i < count ? mpCannonPoint->get(i) : 0;
}

MapdataMissionPoint* CourseMap::getMissionPoint(u16 i) const {
  u16 count = mpMissionPoint ? mpMissionPoint->size() : 0;
  return i < count ? mpMissionPoint->get(i) : 0;
}

MapdataStage* CourseMap::getStage() const {
  if (mpStageInfo && mpStageInfo->size() != 0) {
    return mpStageInfo->get(0);
  }

  return nullptr;
}

u8 MapdataStage::getFlareAlpha() const {
  return CourseMap::instance()->getVersion() > 2320 ? mpData->mFlareAlpha : 75;
}

MapdataAreaAccessor::~MapdataAreaAccessor() { delete[] byPriority; }

MapdataEnemyPoint::~MapdataEnemyPoint() {
  if (_08)
    delete[] _08;

  if (_0c)
    delete[] _0c;
}
}

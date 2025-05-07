#pragma once

#include <rk_types.h>

#include <decomp.h>

#include <stddef.h>

#include <egg/math/eggVector.hpp>
#include <egg/math/eggQuat.hpp>

namespace System {

struct KmpSectionHeader {
  s32 sectionMagic;
  u16 entryCount;
  const s8 extraValue;
};

// TODO: Cleanup
template <typename T, typename TData> class MapdataAccessorBase {
public:
  T** entries;                           //!< [+0x00]
  u16 numEntries;                        //!< [+0x04]
  const KmpSectionHeader* sectionHeader; //!< [+0x08]

  /*const TData *cdata(size_t i) const {
      if (i < 0 || i > numEntries) {
          return nullptr;
      }
      return entryAccessors[i]->m_data;
  }*/
  MapdataAccessorBase(const KmpSectionHeader* header)
      : entries(nullptr), numEntries(0), sectionHeader(header) {}
  T* get(u16 i) const {
    return i < this->numEntries ? this->entries[i] : nullptr;
  }
  s8 getExtraValue() const;
  u16 size() const { return numEntries; }

  inline void init(const TData* start, u16 count) {
    if (count != 0) {
      numEntries = count;
      entries = new T*[count];
    }
    for (u16 i = 0; i < count; i++) {
      entries[i] = new T(&start[i]);
    }
  }
};
// The template will always be the same size
static_assert(sizeof(MapdataAccessorBase<unk, unk>) == 0xc);

// Despite the rest of the file being in alphabetical order, MapdataArea classes
// have been moved just above the accessor classes due to vtable ordering

// We also have to move MapdataPointInfo above MapdataGeoObj
class MapdataPointInfo {
public:
  struct SData {
    struct Point {
      EGG::Vector3f pos;
      u16 settings[2];
    };

    u16 pointCount;
    u8 settings[2];
    Point points[];
  };

  MapdataPointInfo(const SData* data) : mpData(data) {}

private:
  const SData* mpData;
};
static_assert(sizeof(MapdataPointInfo) == 0x4);

class MapdataCamera {
public:
  struct SData {
    u8 cameraType;
    u8 cameraNext;
    u8 cameraShake;
    u8 pathID;
    u16 pathSpeed;
    u16 fovYSpeed;
    u16 viewSpeed;
    u8 startFlag;
    u8 movieFlag;
    EGG::Vector3f position;
    EGG::Vector3f rotation;
    f32 fovYStart;
    f32 fovVYEnd;

    EGG::Vector3f viewStart;
    EGG::Vector3f viewEnd;

    f32 time;
  };

  MapdataCamera(const SData* data) : mpData(data) {}
  u8 getCameraType() const;

private:
  const SData* mpData;
};
static_assert(sizeof(MapdataCamera) == 0x4);

class MapdataCannonPoint {
public:
  struct SData {
    EGG::Vector3f position;
    EGG::Vector3f rotation;
    u16 id;
    u16 shootEffect;
  };

  MapdataCannonPoint(const SData* data) : mpData(data) {}

private:
  const SData* mpData;
};
static_assert(sizeof(MapdataCannonPoint) == 0x4);

class MapdataCheckPath {
public:
  struct SData {
    u8 start;
    u8 size;

    u8 last[6];
    u8 next[6];
  };

  MapdataCheckPath(const SData* data);

private:
  SData* mpData;
  u8 _04[0x0c - 0x04];
};
static_assert(sizeof(MapdataCheckPath) == 0xc);

class MapdataCheckPoint;
struct LinkedCheckpoint {
  MapdataCheckPoint* checkpoint;
  EGG::Vector2f p0diff;
  EGG::Vector2f p1diff;
  f32 distance;
};
class MapdataCheckPoint {
public:
  struct SData {
    EGG::Vector2f left;
    EGG::Vector2f right;
    u8 jugemIndex;
    u8 lapCheck;
    u8 prevPt;
    u8 nextPt;
  };
  enum Completion {
    Completion_0,
    Completion_1,
    Completion_2,
  };
  MapdataCheckPoint(const SData* data);
  Completion checkSectorAndDistanceRatio(const EGG::Vector3f& pos,
                                         f32* distanceRatio) const;
  bool isPlayerFlagged(s32 playerIdx) const { return mFlags & 1 << playerIdx; }
  void setPlayerFlags(s32 playerIdx) { mFlags |= 1 << playerIdx; }
  void resetFlags() { mFlags = 0; }
  SData* data() const { return mpData; }
  s32 nextCount() const { return mNextCount; }
  s32 prevCount() const { return mPrevCount; }
  s32 id() const { return mId; }
  MapdataCheckPoint* prevPoint(s32 i) const { return mpPrevPoints[i]; }
  const LinkedCheckpoint& nextPoint(s32 i) const { return mNextPoints[i]; }

private:
  bool checkSector(const LinkedCheckpoint& next, const EGG::Vector2f& p0,
                   const EGG::Vector2f& p1) const;
  bool checkDistanceRatio(const LinkedCheckpoint& next, const EGG::Vector2f& p0,
                          const EGG::Vector2f& p1, f32* distanceRatio) const;
  Completion checkSectorAndDistanceRatio_(const LinkedCheckpoint& next,
                                          const EGG::Vector2f& p0,
                                          const EGG::Vector2f& p1,
                                          f32* distanceRatio) const;
  SData* mpData;
  u16 mNextCount;
  u16 mPrevCount;
  EGG::Vector2f mMidpoint;
  EGG::Vector2f mDir;
  u16 mFlags;
  u16 mId;
  u8 _1c[0x20 - 0x1c];
  MapdataCheckPoint* mpPrevPoints[6];
  LinkedCheckpoint mNextPoints[6];
};
static_assert(sizeof(MapdataCheckPoint) == 0xc8);

class MapdataEnemyPath {
public:
  struct SData {
    u8 start;
    u8 size;
    u8 last[6];
    u8 next[6];
    u8 battle_params[2];
  };

  MapdataEnemyPath(const SData* data) : mpData(data) {}

private:
  const SData* mpData;
  u8 _04[0x0c - 0x04];
};
static_assert(sizeof(MapdataEnemyPath) == 0xc);

class MapdataEnemyPoint {
public:
  struct SData {
    EGG::Vector3f position;
    f32 deviation;
    u8 parameters[4];
  };

  MapdataEnemyPoint(const SData* data) : _08(nullptr), _0c(nullptr), _14(-1) {
    mpData = data;
  }
  virtual ~MapdataEnemyPoint();

private:
  static bool isNonPrivateBattle();

  const SData* mpData;
  unk* _08;
  unk* _0c;
  u8 _10[0x10 - 0x0c];
  u8 _14;
};
static_assert(sizeof(MapdataEnemyPoint) == 0x18);

class MapdataGeoObj {
public:
  struct SData {
    u16 id;
    EGG::Vector3f translation;
    EGG::Vector3f rotation;
    EGG::Vector3f scale;
    s16 pathId;
    u16 settings[8];
    u16 presenceFlag;
  };

  // NOTE: We cannot modify eggVector.hpp without the build failing
  // The dtor is causing a mismatch so this will have to do for now
  struct Vec3 {
    f32 x, y, z;

    inline Vec3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
  };

  MapdataGeoObj(const SData* data) : mpData(data) {
    // Writes to stack and does nothing
    Vec3 _(mpData->translation.x, mpData->translation.y, mpData->translation.z);
  }

  MapdataPointInfo* getPointInfo() const;

private:
  const SData* mpData;
};
static_assert(sizeof(MapdataGeoObj) == 0x4);

class MapdataItemPath {
public:
  struct SData {
    u8 start;
    u8 size;

    u8 last[6];
    u8 next[6];

    u16 _0e; // Required padding
  };

  MapdataItemPath(const SData* data) : mpData(data) {}

private:
  const SData* mpData;
};
static_assert(sizeof(MapdataItemPath) == 0x4);

class MapdataItemPoint {
public:
  struct SData {
    EGG::Vector3f position;
    f32 deviation;
    u16 parameters[2];
  };

  MapdataItemPoint(const SData* data) : mpData(data) {}

private:
  const SData* mpData;
  u8 _04[0x14 - 0x04];
};
static_assert(sizeof(MapdataItemPoint) == 0x14);

class MapdataJugemPoint {
public:
  struct SData {
    EGG::Vector3f position;
    EGG::Vector3f rotation;
    u16 id;
    s16 range;
  };

  MapdataJugemPoint(const SData* data);
  virtual ~MapdataJugemPoint();

private:
  SData* mpData;
  u8 _08[0x30 - 0x08];
};
static_assert(sizeof(MapdataJugemPoint) == 0x30);

class MapdataMissionPoint {
public:
  struct SData {
    EGG::Vector3f position;
    EGG::Vector3f rotation;
    u16 id;
  };

  MapdataMissionPoint(const SData* data) : mpData(data) {}

private:
  const SData* mpData;
};
static_assert(sizeof(MapdataMissionPoint) == 0x4);

class MapdataStage {
public:
  struct SData {
    u8 mLapCount;     // unused
    u8 mPolePosition; // should only be 0 and 1, but is not a bool
    u8 mStartConfig;  // start position player packing 0: normal, 1: tight
    bool mFlareToggle;
    u32 mFlareColor; // RGB format
    // Pre Revision 2321: End of structure
    u8 mFlareAlpha;
  };

  MapdataStage(const SData* data) : mpData(data) {}
  u8 getStartConfig() const;
  u8 getFlareAlpha() const;
  u32 getFlareColor() const;
  bool flareToggleEnabled() const;

private:
  const SData* mpData;
};
static_assert(sizeof(MapdataStage) == 0x4);

class MapdataStartPoint {
public:
  struct SData {
    EGG::Vector3f position;
    EGG::Vector3f rotation;
    // Pre Revision 1830: End of structure
    s16 playerIndex;
  };

  MapdataStartPoint(const SData* data) : mpData(data) {}

private:
  const SData* mpData;
  s8 mEnemyPoint;
};
static_assert(sizeof(MapdataStartPoint) == 0x8);

class MapdataAreaBase {
public:
  struct SData {
    u8 shape;
    u8 type;
    s8 cameraIdx;
    u8 priority;
    EGG::Vector3f position;
    EGG::Vector3f rotation;
    EGG::Vector3f scale;
    u16 parameters[2];
    // Pre Revision 2200: End of structure
    u8 railID;
    u8 eneLinkID;
  };

  MapdataAreaBase(const SData* data);
  virtual bool isInsideShape(const EGG::Vector3f& pos) const = 0;

  s32 getRouteId() const;
  MapdataPointInfo* getPointInfo() const;
  bool isInside(const EGG::Vector3f& pos) const;
  void setIndex(u16 idx);

protected:
  const SData* mpData;
  EGG::Vector3f mXAxis;
  EGG::Vector3f mYAxis;
  EGG::Vector3f mZAxis;
  EGG::Vector3f mDims;
  // Only used in MapdataAreaCylinder
  f32 mEllipseXRadiusSq;
  f32 mEllipseAspectRatio;
  // Sphere enclosing area for more efficient check if point in area
  f32 mBoundingSphereRadiusSq;
  // Index in MapdataAreaAccessor array
  s16 mIndex;
};
static_assert(sizeof(MapdataAreaBase) == 0x48);

class MapdataAreaBox : public MapdataAreaBase {
public:
  MapdataAreaBox(const SData* data);
  virtual bool isInsideShape(const EGG::Vector3f& pos) const;
};

class MapdataAreaCylinder : public MapdataAreaBase {
public:
  MapdataAreaCylinder(const SData* data);
  virtual bool isInsideShape(const EGG::Vector3f& pos) const;
};

class MapdataAreaAccessor {
public:
  MapdataAreaAccessor(const KmpSectionHeader* header);
  u16 size() const { return numEntries; }

  MapdataAreaBase* get(u16 i) const;
  MapdataAreaBase* getByPriority(u16 i) const {
    if (i < numEntries && this->byPriority) {
      return this->byPriority[i];
    }
    return nullptr;
  }

  MapdataAreaBase** entries;
  u16 numEntries;
  virtual ~MapdataAreaAccessor();
  const KmpSectionHeader* sectionHeader;

private:
  MapdataAreaBase** byPriority;
};
static_assert(sizeof(MapdataAreaAccessor) == 0x14);
// Ensure the vtable does not exist at offset 0x0
// (It should exist at offset 0x8)
static_assert(offsetof(MapdataAreaAccessor, entries) == 0x0);

class MapdataCameraAccessor
    : public MapdataAccessorBase<MapdataCamera, MapdataCamera::SData> {
public:
  MapdataCameraAccessor(const KmpSectionHeader* header)
      : MapdataAccessorBase<MapdataCamera, MapdataCamera::SData>(header) {
    init((const MapdataCamera::SData*)(sectionHeader + 1),
         sectionHeader->entryCount);
  }

  s8 getExtraValue() const;
};

class MapdataCannonPointAccessor
    : public MapdataAccessorBase<MapdataCannonPoint,
                                 MapdataCannonPoint::SData> {
public:
  MapdataCannonPointAccessor(const KmpSectionHeader* header)
      : MapdataAccessorBase<MapdataCannonPoint, MapdataCannonPoint::SData>(
            header) {
    init((const MapdataCannonPoint::SData*)(sectionHeader + 1),
         sectionHeader->entryCount);
  }
};

class MapdataCheckPathAccessor
    : public MapdataAccessorBase<MapdataCheckPath, MapdataCheckPath::SData> {
private:
  f32 _0c;
};
static_assert(sizeof(MapdataCheckPathAccessor) == 0x10);

class MapdataCheckPointAccessor
    : public MapdataAccessorBase<MapdataCheckPoint, MapdataCheckPoint::SData> {
private:
  u8 _0c[0x14 - 0x0c];
};
static_assert(sizeof(MapdataCheckPointAccessor) == 0x14);

class MapdataEnemyPathAccessor
    : public MapdataAccessorBase<MapdataEnemyPath, MapdataEnemyPath::SData> {
public:
  MapdataEnemyPathAccessor(const KmpSectionHeader* header)
      : MapdataAccessorBase<MapdataEnemyPath, MapdataEnemyPath::SData>(header) {
    init((const MapdataEnemyPath::SData*)(sectionHeader + 1),
         sectionHeader->entryCount);
  }
};

class MapdataEnemyPointAccessor
    : public MapdataAccessorBase<MapdataEnemyPoint, MapdataEnemyPoint::SData> {
public:
  MapdataEnemyPointAccessor(const KmpSectionHeader* header)
      : MapdataAccessorBase<MapdataEnemyPoint, MapdataEnemyPoint::SData>(
            header) {
    init((const MapdataEnemyPoint::SData*)(sectionHeader + 1),
         sectionHeader->entryCount);
  }
};

class MapdataGeoObjAccessor
    : public MapdataAccessorBase<MapdataGeoObj, MapdataGeoObj::SData> {
public:
  MapdataGeoObjAccessor(const KmpSectionHeader* header)
      : MapdataAccessorBase<MapdataGeoObj, MapdataGeoObj::SData>(header) {
    init((const MapdataGeoObj::SData*)(sectionHeader + 1),
         sectionHeader->entryCount);
  }
};

class MapdataItemPathAccessor
    : public MapdataAccessorBase<MapdataItemPath, MapdataItemPath::SData> {
public:
  MapdataItemPathAccessor(const KmpSectionHeader* header)
      : MapdataAccessorBase<MapdataItemPath, MapdataItemPath::SData>(header) {
    init((const MapdataItemPath::SData*)(sectionHeader + 1),
         sectionHeader->entryCount);
  }
};

class MapdataItemPointAccessor
    : public MapdataAccessorBase<MapdataItemPoint, MapdataItemPoint::SData> {
public:
  MapdataItemPointAccessor(const KmpSectionHeader* header)
      : MapdataAccessorBase<MapdataItemPoint, MapdataItemPoint::SData>(header) {
    init((const MapdataItemPoint::SData*)(sectionHeader + 1),
         sectionHeader->entryCount);
  }
};

class MapdataJugemPointAccessor
    : public MapdataAccessorBase<MapdataJugemPoint, MapdataJugemPoint::SData> {
public:
  MapdataJugemPointAccessor(const KmpSectionHeader* header)
      : MapdataAccessorBase<MapdataJugemPoint, MapdataJugemPoint::SData>(
            header) {
    init((const MapdataJugemPoint::SData*)(sectionHeader + 1),
         sectionHeader->entryCount);
  }

  MapdataJugemPoint* get(u16 i) const;
};

class MapdataMissionPointAccessor
    : public MapdataAccessorBase<MapdataMissionPoint,
                                 MapdataMissionPoint::SData> {
public:
  MapdataMissionPointAccessor(const KmpSectionHeader* header)
      : MapdataAccessorBase<MapdataMissionPoint, MapdataMissionPoint::SData>(
            header) {
    init((const MapdataMissionPoint::SData*)(sectionHeader + 1),
         sectionHeader->entryCount);
  }
};

class MapdataPointInfoAccessor
    : public MapdataAccessorBase<MapdataPointInfo, MapdataPointInfo::SData> {
public:
  // We need the init function defined before the constructor
  void init(u16 entryCount) {
    if (entryCount != 0) {
      numEntries = entryCount;
      entries = new MapdataPointInfo*[entryCount];
    }
    if (numEntries != 0) {
      u16 i = 0;
      const MapdataPointInfo::SData* route =
          (const MapdataPointInfo::SData*)sectionHeader + 2;
      for (; i < numEntries; i++) {
        entries[i] = new MapdataPointInfo(route);
        route = route + route->pointCount * 4 + 1;
      }
    }
  }

  // TODO: scheduling conflicts in source
  MapdataPointInfoAccessor(const KmpSectionHeader* header)
      : MapdataAccessorBase<MapdataPointInfo, MapdataPointInfo::SData>(header) {
    init(sectionHeader->entryCount);
  }
};

class MapdataStageAccessor
    : public MapdataAccessorBase<MapdataStage, MapdataStage::SData> {
public:
  MapdataStageAccessor(const KmpSectionHeader* header)
      : MapdataAccessorBase<MapdataStage, MapdataStage::SData>(header) {
    init((const MapdataStage::SData*)(sectionHeader + 1),
         sectionHeader->entryCount);
  }
};

class MapdataStartPointAccessor
    : public MapdataAccessorBase<MapdataStartPoint, MapdataStartPoint::SData> {
public:
  MapdataStartPointAccessor(const KmpSectionHeader* header);

  MapdataStartPoint* get(u16 i) const;
};

class MapdataFileAccessor {
public:
  struct SData {
    u32 magic;
    u32 fileSize;
    u16 numSections;
    u16 headerSize;
    u32 revision;
    s32 offsets[];
  };

  MapdataFileAccessor(const SData* data);
  u32 getVersion() const;
  const KmpSectionHeader* findSection(u32 sectionName) const;

private:
  const SData* mpData;
  u32* mpSectionDef;
  u32 mVersion;
  u32 mSectionDefOffset;
};
static_assert(sizeof(MapdataFileAccessor) == 0x10);

class CourseMap {
public:
  static CourseMap* createInstance();
  static void destroyInstance();
  static inline CourseMap* instance() { return spInstance; }
  static void* loadFile(s32 archiveIdx, const char* filename);

  inline u32 getVersion() const { return mpCourse->getVersion(); }

  MapdataAreaBase* getArea(u16 i) const;
  MapdataAreaBase* getAreaByPriority(u16 i) const;
  MapdataCannonPoint* getCannonPoint(u16 i) const;
  MapdataCamera* getCamera(u16 i) const;
  MapdataCheckPoint* getCheckPoint(u16 i) const;
  MapdataCheckPath* getCheckPath(u16 i) const;
  MapdataEnemyPath* getEnemyPath(u16 i) const;
  MapdataEnemyPoint* getEnemyPoint(u16 i) const;
  MapdataGeoObj* getGeoObj(u16 i) const;
  MapdataItemPoint* getItemPoint(u16 i) const;
  MapdataItemPath* getItemPath(u16 i) const;
  MapdataJugemPoint* getJugemPoint(u16 i) const;
  MapdataMissionPoint* getMissionPoint(u16 i) const;
  MapdataPointInfo* getPointInfo(u16 i) const;
  MapdataStage* getStage() const;
  MapdataStartPoint* getStartPoint(u16 i) const;

  inline MapdataEnemyPathAccessor* getEnemyPathAccessor() { return mpEnemyPath; }

  u16 getAreaCount() const;
  u16 getCameraCount() const;
  u16 getEnemyPointCount() const;
  u16 getItemPointCount() const;
  u16 getJugemPointCount() const;
  u16 getStartPointCount() const;

  /*template <typename T, typename TAccessor>
  TAccessor* parse(u32 sectionName);*/
  MapdataAreaAccessor* parseAreas(u32 sectionName);
  MapdataCameraAccessor* parseCameras(u32 sectionName);
  MapdataCannonPointAccessor* parseCannonPoints(u32 sectionName);
  MapdataEnemyPathAccessor* parseEnemyPaths(u32 sectionName);
  MapdataEnemyPointAccessor* parseEnemyPoints(u32 sectionName);
  MapdataGeoObjAccessor* parseGeoObjs(u32 sectionName);
  MapdataItemPathAccessor* parseItemPaths(u32 sectionName);
  MapdataItemPointAccessor* parseItemPoints(u32 sectionName);
  MapdataJugemPointAccessor* parseJugemPoints(u32 sectionName);
  MapdataStartPointAccessor* parseKartpoints(u32 sectionName);
  MapdataMissionPointAccessor* parseMissionPoints(u32 sectionName);
  MapdataPointInfoAccessor* parsePointInfo(u32 sectionName);
  MapdataStageAccessor* parseStage(u32 sectionName);

private:
  CourseMap();
  virtual ~CourseMap();

  static CourseMap* spInstance;

  MapdataFileAccessor* mpCourse;

  MapdataStartPointAccessor* mpStartPoint;
  MapdataEnemyPathAccessor* mpEnemyPath;
  MapdataEnemyPointAccessor* mpEnemyPoint;
  MapdataItemPathAccessor* mpItemPath;
  MapdataItemPointAccessor* mpItemPoint;
  MapdataCheckPathAccessor* mpCheckPath;
  MapdataCheckPointAccessor* mpCheckPoint;
  MapdataPointInfoAccessor* mpPointInfo;
  MapdataGeoObjAccessor* mpGeoObj;
  MapdataAreaAccessor* mpArea;
  MapdataCameraAccessor* mpCamera;
  MapdataJugemPointAccessor* mpJugemPoint;
  MapdataCannonPointAccessor* mpCannonPoint;
  MapdataStageAccessor* mpStageInfo;
  MapdataMissionPointAccessor* mpMissionPoint;

  void* mpGoalCamera;
  void* mpType9Camera;
  void* mpOpeningPanCamera;
  unk _50;
};

} // namespace System

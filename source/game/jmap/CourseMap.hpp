#pragma once

#include <rk_types.h>

namespace Field {

class CourseMap {
public:
  static CourseMap* initStaticInstance();
  static void destroyStaticInstance();

  static inline CourseMap* instance() { return spInstance; }

private:
  CourseMap();
  virtual ~CourseMap();

  static CourseMap* spInstance;

  void* mpCourse;

  void* mpKartPoint;
  void* mpEnemyPath;
  void* mpEnemyPoint;
  void* mpItemPath;
  void* mpItemPoint;
  void* mpCheckPath;
  void* mpCheckPoint;
  void* mpPointInfo;
  void* mpGeoObj;
  void* mpArea;
  void* mpCamera;
  void* mpJugemPoint;
  void* mpCannonPoint;
  void* mpStageInfo;
  void* mpMissionPoint;

  void* mGoalCamera;
  void* mType9Camera;
  void* mOpeningPanCamera;
  unk _50;
};

} // namespace Field

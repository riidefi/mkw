#pragma once

#include <rk_types.h>

namespace Field {

class JmpResourceCourse {
public:
  static JmpResourceCourse* initStaticInstance();
  static void destroyStaticInstance();

  static inline JmpResourceCourse* instance() { return spInstance; }

private:
  JmpResourceCourse();
  virtual ~JmpResourceCourse();

  static JmpResourceCourse* spInstance;

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

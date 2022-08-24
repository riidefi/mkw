#include "CourseMap.hpp"

namespace Field {

CourseMap* CourseMap::spInstance;

CourseMap* CourseMap::initStaticInstance() {
  if (spInstance == nullptr) {
    spInstance = new CourseMap();
  }

  return spInstance;
}

void CourseMap::destroyStaticInstance() {
  if (spInstance != nullptr) {
    delete spInstance;
    spInstance = nullptr;
  }
}

CourseMap::CourseMap()
    : mpKartPoint(nullptr), mpEnemyPath(nullptr), mpCheckPath(nullptr),
      mpCheckPoint(nullptr), mpGeoObj(nullptr), mpPointInfo(nullptr),
      mpArea(nullptr), mpCamera(nullptr), mGoalCamera(nullptr),
      mOpeningPanCamera(nullptr), _50(0) {}

CourseMap::~CourseMap() {}

} // namespace Field

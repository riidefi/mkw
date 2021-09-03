#include "JmpResourceCourse.hpp"

namespace Field {

JmpResourceCourse* JmpResourceCourse::initStaticInstance() {
  if (spInstance == nullptr) {
    spInstance = new JmpResourceCourse();
  }

  return spInstance;
}

void JmpResourceCourse::destroyStaticInstance() {
  if (spInstance != nullptr) {
    delete spInstance;
    spInstance = nullptr;
  }
}

JmpResourceCourse::JmpResourceCourse()
    : mpKartPoint(nullptr), mpEnemyPath(nullptr), mpCheckPath(nullptr),
      mpCheckPoint(nullptr), mpGeoObj(nullptr), mpPointInfo(nullptr),
      mpArea(nullptr), mpCamera(nullptr), mGoalCamera(nullptr),
      mOpeningPanCamera(nullptr), _50(0) {}

JmpResourceCourse::~JmpResourceCourse() {}

} // namespace Field

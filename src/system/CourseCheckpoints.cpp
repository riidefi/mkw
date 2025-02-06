#include "CourseCheckpoints.hpp"

#include "CourseMap.hpp"

// Symbol: checkSector__Q26System17MapdataCheckPointCFRCQ26System16LinkedCheckpointRCQ23EGG8Vector2fRCQ23EGG8Vector2f
namespace System {
bool MapdataCheckPoint::checkSector(const LinkedCheckpoint& next,
                                    const EGG::Vector2f& p0,
                                    const EGG::Vector2f& p1) const {
  if (-(next.p0diff.y) * p0.x + next.p0diff.x * p0.y < 0.0f)
    return false;

  if (next.p1diff.y * p1.x - next.p1diff.x * p1.y < 0.0f)
    return false;

  return true;
}
} // namespace System

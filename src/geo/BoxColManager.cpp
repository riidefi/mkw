#include "BoxColManager.hpp"

#include <math.h>

bool BoxColManager::isSphereInSpatialCache(const EGG::Vector3f& pos, f32 radius, u32 flag) const {
  if (flt_808A47EC != someDist && someFlag == (someFlag | flag)) {
    float v4 = someDist - radius;
    if (fabs((pos.x - someX)) <= v4 && fabs((pos.z - someZ)) <= v4)
      return true;
  }

  return false;
}

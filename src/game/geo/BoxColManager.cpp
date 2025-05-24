#include "BoxColManager.hpp"

#define MathAbs __fabs

#if 0
extern const f32 flt_808A47E8 = 0.0f;
const f32 NegOne = -1.0f;
extern const f32 flt_808A47F0 = 999999.88f;
extern const f32 flt_808A47F4 = 1.0f;
extern const f32 flt_808A47F8 = -999999.88f;
extern const f32 flt_808A47FC = 999999.88f;
#endif

// const float flt_808A47EC = -1.0;

bool BoxColManager::isSphereInSpatialCache(const EGG::Vector3f& pos, f32 radius, u32 flag) const {
  if (flt_808A47EC != someDist && someFlag == (someFlag | flag)) {
    float v4 = someDist - radius;
    if (MathAbs((pos.x - someX)) <= v4 && __fabs((pos.z - someZ)) <= v4)
      return true;
  }

  return false;
}

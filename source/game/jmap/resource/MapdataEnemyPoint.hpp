#pragma once

#include <egg/math/eggVector.hpp>
#include <rk_types.h>

namespace Field {

/*
Enemy Point Param [ #0, #1, #2, #3 ]
# 0 : 0 -> isUseKinoko
#2 :
        0 -> continueDrift
        1 -> isEndDrift
        2 -> isDisableDrift, !isAbleToMiniTurbo
isUseKinoko: #0 and #1 == 0

*/
struct MapdataEnemyPoint {
  EGG::Vector3f position; // 00
  f32 deviation;          // 0C
  u8 parameters[4];       // 10
};

} // namespace Field

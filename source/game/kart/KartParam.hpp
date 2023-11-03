
#pragma once

#include "egg/math/eggVector.hpp"

#include "BSP.hpp"

namespace Kart {
class KartCharComboStats;

class KartParam {
public:
  KartCharComboStats* stats;
  BSP* bsp; 
};
}

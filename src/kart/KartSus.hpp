#pragma once

#include <rk_types.h>

#include <decomp.h>

#include "KartPart.hpp"
#include "kart/KartObjectProxy.hpp"

namespace Kart {
  class KartSusPhysics;
class KartSus: KartPart {
public:
  inline const KartSusPhysics* getPhysics() const { return susPhysics; }
  inline KartSusPhysics* getPhysics() { return susPhysics; }

private:
  KartSusPhysics* susPhysics;
};
}

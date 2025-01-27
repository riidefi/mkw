#pragma once

#include <rk_types.h>

#include "system/ResourceManager.hpp"

#include "KartParam.hpp"
#include "KartDispParams.hpp"

namespace Kart {
class GpStats;
class RaceStats;
class KartSettings {
public:
  KartSettings();

  u32 isBike;
  System::VehicleId vehicle;
  System::CharacterId character;
  u16 susCount;
  u16 wheelCount;
  u8 playerIdx;
  KartParam* kartParam;
  void* _18;
  KartDriverDispParams* kartDriverDispParams;
  KartPartsDispParams* kartPartsDispParams;
  BikePartsDispParams* bikePartsDispParams;
  DriverDispParams* driverDispParams;
  f32 wheelCountRecip;
  f32 wheelCountPlusOneRecip;
  GpStats* gpStats;
  RaceStats* raceStats;
};
static_assert(sizeof(KartSettings) == 0x3c);
}

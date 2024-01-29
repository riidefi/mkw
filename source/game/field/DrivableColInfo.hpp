
#pragma once

#include <rk_types.h>

#include "game/geo/ObjDrivable.hpp"

// TODO: Split its own TU. Not well understood what this does
namespace Field {
struct DrivableColInfo {
  u32 flags;
  GeoObj::ObjDrivable* drivable;
  f32 _8[3];

  GeoObj::ObjDrivable* getDrivable() const {
    if ((flags & 0x100) != 0) return drivable;
    else return nullptr;
  }
};
}


#pragma once

#include "egg/math/eggVector.hpp"

#include "BSP.hpp"

namespace Kart {
// Vechicle categories based on the type of axles they use
enum AxleType {
  AXLE_TYPE_KART     = 0x0,
  AXLE_TYPE_BIKE     = 0x1,
  AXLE_TYPE_QUACKER  = 0x2,
  /// Used for blue falcon
  AXLE_TYPE_TRICYCLE = 0x3,
};

enum DriftType {
  DRIFT_TYPE_OUTSIDE_KART = 0x0,
  DRIFT_TYPE_OUTSIDE_BIKE = 0x1,
  DRIFT_TYPE_INSIDE_BIKE  = 0x2,
};

enum WeightClass {
  WEIGHT_CLASS_LIGHT  = 0x0,
  WEIGHT_CLASS_MEDIUM = 0x1,
  WEIGHT_CLASS_HEAVY  = 0x2,
};

struct RotatingItemParams {
  u8 _0[0x10 - 0x0];
};

struct KartStats {
  AxleType axleType;
  DriftType driftType;
  WeightClass weightClass;
  f32 _c;
  f32 weight;
  /// moment of inertia around Y axis
  f32 yawInertia;
  /// base speed
  f32 baseSpeed;
  /// base handling
  f32 baseHandling;
  /// Taken from the wiki. idk what that does, doesn't seem like much of a tilt
  f32 tilt;
  f32 accAs[4];
  f32 accTs[4 - 1];
  f32 driftAccAs[2];
  f32 driftAccTs[2 - 1];
  /// handling in manual mode
  f32 manualHandling;
  /// handling in auto mode
  f32 autoHandling;
  /// Responsiveness to change in direction
  f32 handlingResponsiveness;
  /// drifting in manual mode
  f32 manualDrifting;
  /// drifting in auto mode
  f32 autoDrifting;
  /// Responsiveness to drift change in direction
  f32 driftingResponsiveness;
  /// Angle of outside drifting cars w.r.t. direction of movement
  f32 driftAngle;
  f32 driftAngleDecr;
  /// Mini-turbo duration
  f32 mtDuration;
  /// Base speed multiplier depending on the KCL flag
  f32 speedFactors[32];
  /// Additional handling depending on the KCL flag
  f32 handlingFactors[32];
  RotatingItemParams rotatingItemParams;
  f32 maxVerticalAcc;
  f32 megaScale;
  f32 wheelbase;

  inline f32 getSpeedFactor(s32 type) const { return speedFactors[type]; }
  inline f32 getHandlingFactor(s32 type) const { return handlingFactors[type]; }
};
static_assert(sizeof(KartStats) == 0x18c);

class KartParam {
public:
  KartStats* stats;
  BSP* bsp; 
};
}

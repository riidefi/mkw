#pragma once

#include <rk_types.h>

#include <decomp.h>

extern "C" {
// PAL: 0x8059f5bc..0x8059f678
UNKNOWN_FUNCTION(__ct__Q24Kart11KartPhysicsFb);
// PAL: 0x8059f6f8..0x8059f788
UNKNOWN_FUNCTION(__dt__Q24Kart11KartPhysicsFv);
// PAL: 0x8059f788..0x8059f7c8
UNKNOWN_FUNCTION(unk_8059f788);
// PAL: 0x8059f7c8..0x8059f968
UNKNOWN_FUNCTION(unk_8059f7c8);
// PAL: 0x8059f968..0x8059fc08
UNKNOWN_FUNCTION(PlayerPhysicsHolder_update);
// PAL: 0x8059fc08..0x8059fc30
UNKNOWN_FUNCTION(unk_8059fc08);
// PAL: 0x8059fc30..0x8059fc38
UNKNOWN_FUNCTION(unk_8059fc30);
// PAL: 0x8059fc38..0x8059fc48
UNKNOWN_FUNCTION(unk_8059fc38);
// PAL: 0x8059fc48..0x8059fd0c
UNKNOWN_FUNCTION(unk_8059fc48);
// PAL: 0x8059fd0c..0x8059fdd0
UNKNOWN_FUNCTION(unk_8059fd0c);
// PAL: 0x8059fdd0..0x8059fe94
UNKNOWN_FUNCTION(unk_8059fdd0);
// PAL: 0x8059fe94..0x8059ff58
UNKNOWN_FUNCTION(unk_8059fe94);
// PAL: 0x8059ff58..0x805a0050
UNKNOWN_FUNCTION(unk_8059ff58);
// PAL: 0x805a0050..0x805a00d0
UNKNOWN_FUNCTION(unk_805a0050);
// PAL: 0x805a00d0..0x805a014c
UNKNOWN_FUNCTION(unk_805a00d0);
// PAL: 0x805a014c..0x805a01cc
UNKNOWN_FUNCTION(unk_805a014c);
// PAL: 0x805a01cc..0x805a02b8
UNKNOWN_FUNCTION(unk_805a01cc);
// PAL: 0x805a02b8..0x805a0340
UNKNOWN_FUNCTION(unk_805a02b8);
// PAL: 0x805a0340..0x805a03c4
UNKNOWN_FUNCTION(PlayerPhysicsHolder_updateMat);
// PAL: 0x805a03c4..0x805a0410
UNKNOWN_FUNCTION(unk_805a03c4);
// PAL: 0x805a0410..0x805a0480
UNKNOWN_FUNCTION(PlayerPhysicsHolder_resetQuaternions);
// PAL: 0x805a0480..0x805a04a0
UNKNOWN_FUNCTION(destroyPhysicsInstance__4KartFf);
// PAL: 0x805a04a0..0x805a0550
UNKNOWN_FUNCTION(unk_805a04a0);
}

#include <egg/math/eggVector.hpp>
#include <egg/math/eggQuat.hpp>
#include <egg/math/eggMatrix.hpp>

#include "KartHitbox.hpp"
#include "KartDynamics.hpp"

namespace Kart {
class KartPhysics {
public:
  virtual ~KartPhysics();

  KartPhysics(bool isBike);

private:
  KartDynamics* mpDynamics;
  HitboxGroup* mpHitboxGroup;

  EGG::Vector3f _c;
  EGG::Vector3f pos;
  // rotation from stunts
  // instantaneous is the extra rot of the current trick.
  // Decaying is used when a trick is ended early (low trick) to smoothly decay the rotation back to normal
  EGG::Quatf decayingSpecialRot;
  EGG::Quatf instantaneousSpecialRot;
  EGG::Quatf specialRot;
  // rotation from e.g. item interactions
  EGG::Quatf decayingExtraRot;
  EGG::Quatf instantaneousExtraRot;
  EGG::Quatf extraRot;

  EGG::Vector3f _84;
  EGG::Vector3f _90;
  // the following 4 position/orientation fields do not include wheelieing
  EGG::Matrix34f pose;
  EGG::Vector3f xAxis;
  EGG::Vector3f yAxis;
  EGG::Vector3f zAxis;

  EGG::Vector3f velocity;
  f32 _fc;
};
static_assert(sizeof(KartPhysics) == 0x100);
}


#pragma once

#include "egg/math/eggMatrix.hpp"
#include "egg/math/eggMath.hpp"

namespace Field {
struct SoftWallColInfo {
  EGG::Vector3f bboxLow;
  EGG::Vector3f bboxHigh;
  // bboxLow + bboxHigh. This is the offset that needs to be added to a colliding sphere so
  // it barely does not collide with any prisms (becomes tangent to at least on of them)
  // This is used e.g. to place the wheels tangentially to the ground instead of them appearing to be "sinking"
  // when landing
  // ref: 0x805998c0
  EGG::Vector3f tangentOff;
  f32 dist;
  EGG::Vector3f fnrm;

  void update(f32 now_dist, const EGG::Vector3f& offset, const EGG::Vector3f& fnrm) {
    nw4r::math::VEC3Minimize(&this->bboxLow, &this->bboxLow, &offset);
    nw4r::math::VEC3Maximize(&this->bboxHigh, &this->bboxHigh, &offset);

    bool updateNrm;
    if (now_dist > this->dist) {
      this->dist = now_dist;
      updateNrm = true;
    } else {
      updateNrm = false;
    }
    if (updateNrm) {
      this->fnrm = fnrm;
    }
  }
};

struct DrivableColInfo;
struct ColInfoPartial {
  EGG::Vector3f bboxLow;
  EGG::Vector3f bboxHigh;
  EGG::Vector3f tangentOff;

  void calcTangentOff() {
    nw4r::math::VEC3Add(&this->tangentOff, &this->bboxLow, &this->bboxHigh);
  }
};

// TU 0x807c2660
struct ColInfo : public ColInfoPartial {
  // closest drivable road normal
  EGG::Vector3f floorNrm;
  // closest wall normal
  EGG::Vector3f wallNrm;
  EGG::Vector3f _3c;
  // distance to closest road
  f32 floorDist;
  // distance to closest wall
  f32 wallDist;
  f32 _50;
  f32 colPerpendicularity;
  DrivableColInfo* drivableColInfo;

  void createDrivableColInfo();
  void transformInfo(const ColInfo& colInfoLoca, const EGG::Matrix34f& mtx, const EGG::Vector3f& param4);

  void updateFloor(f32 dist, const EGG::Vector3f& fnrm) {
    bool updateNrm;
    if (dist > this->floorDist) {
      this->floorDist = dist;
      updateNrm = true;

    } else {
      updateNrm = false;
    }
    if (updateNrm) {
      this->floorNrm = fnrm;
    }
  }
  void updateWall(f32 dist, const EGG::Vector3f& fnrm) {
    bool updateNrm;
    if (dist > this->wallDist) {
      this->wallDist = dist;
      updateNrm = true;
    } else {
      updateNrm = false;
    }
    if (updateNrm) {
      this->wallNrm = fnrm;
    }
  }

  void update(f32 now_dist, const EGG::Vector3f& offset, const EGG::Vector3f& fnrm, u32 kclAttributeTypeBit) {
    nw4r::math::VEC3Minimize(&this->bboxLow, &this->bboxLow, &offset);
    nw4r::math::VEC3Maximize(&this->bboxHigh, &this->bboxHigh, &offset);

    if ((kclAttributeTypeBit & KCL_TYPE_FLOOR) != 0) {
      this->updateFloor(now_dist, fnrm);
    } else if ((kclAttributeTypeBit & KCL_TYPE_WALL) != 0) {
      if (EGG::Mathf::isNonNegative(this->wallDist)) {
        f32 perpendicularity = 1.0f - VEC3Dot(&this->wallNrm, &fnrm);
        bool updatePerp;
        if (perpendicularity > this->colPerpendicularity) {
          this->colPerpendicularity = perpendicularity;
          updatePerp = true;
        } else {
          updatePerp = false;
        }
        if (updatePerp && this->colPerpendicularity > 1.0f) {
          this->colPerpendicularity = 1.0f;
        }
      }

      this->updateWall(now_dist, fnrm);
    }
  }
};
}

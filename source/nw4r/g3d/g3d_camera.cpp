// Source:
// https://github.com/doldecomp/ogws/blob/82dbeac2267170fc5cef7e67a6d8c31c5ff45d69/src/nw4r/g3d/g3d_camera.cpp
// Decompiled by kiwi515.

#include "g3d_camera.hpp"

#include <rvl/gx/gxTransform.h>
#include <rvl/mtx/mtx.h>

#include "g3d_state.hpp"

namespace nw4r {
namespace g3d {

Camera::Camera(CameraData* pCamData) : mCamData(pCamData) {}

void Camera::Init() {
  GXRenderModeObj& rRenderMode = G3DState::GetRenderModeObj();
  Init(rRenderMode.mFbWidth, rRenderMode.mEfbHeight, rRenderMode.mFbWidth,
       rRenderMode.SHORT_0x8, rRenderMode.SHORT_0xE, rRenderMode.SHORT_0x10);
}

void Camera::Init(u16 r4, u16 r5, u16 r6, u16 r7, u16 r8, u16 r9) {
  CameraData& rCamData = mCamData.ref();

  if (mCamData.IsValid()) {
    rCamData.mFlags = 0x21;

    rCamData.mPos.x = 0.0f;
    rCamData.mPos.y = 0.0f;
    rCamData.mPos.z = 15.0f;

    rCamData.VEC3_0x80.x = 0.0f;
    rCamData.VEC3_0x80.y = 1.0f;
    rCamData.VEC3_0x80.z = 0.0f;

    rCamData.VEC3_0x8C.x = 0.0f;
    rCamData.VEC3_0x8C.y = 0.0f;
    rCamData.VEC3_0x8C.z = 0.0f;

    rCamData.VEC3_0x98.x = 0.0f;
    rCamData.VEC3_0x98.y = 0.0f;
    rCamData.VEC3_0x98.z = 0.0f;

    rCamData.FLOAT_0xA4 = 0.0f;
    rCamData.INT_0xA8 = 0;
    rCamData.FLOAT_0xAC = 60.0f;
    rCamData.FLOAT_0xB0 = (4.0f / 3.0f);
    rCamData.FLOAT_0xB4 = 0.1f;
    rCamData.FLOAT_0xB8 = 1000.f;
    rCamData.FLOAT_0xBC = 0.0f;
    rCamData.FLOAT_0xC0 = (float)r9;
    rCamData.FLOAT_0xC4 = 0.0f;
    rCamData.FLOAT_0xC8 = (float)r8;
    rCamData.FLOAT_0xCC = 0.5f;
    rCamData.FLOAT_0xD0 = 0.5f;
    rCamData.FLOAT_0xD4 = 0.5f;
    rCamData.FLOAT_0xD8 = 0.5f;
    rCamData.FLOAT_0xDC = 0.0f;
    rCamData.FLOAT_0xE0 = 0.0f;
    rCamData.FLOAT_0xE4 = (float)r6;
    rCamData.FLOAT_0xE8 = (float)r7;
    rCamData.FLOAT_0xEC = 0.0;
    rCamData.FLOAT_0xF0 = 1.0f;
    rCamData.INT_0xF4 = 0;
    rCamData.INT_0xF8 = 0;
    rCamData.INT_0xFC = r4;
    rCamData.INT_0x100 = r5;
    rCamData.INT_0x104 = 0;
    rCamData.INT_0x108 = 0;
  }
}

void Camera::SetPosition(f32 x, f32 y, f32 z) {
  CameraData& rCamData = mCamData.ref();

  if (mCamData.IsValid()) {
    rCamData.mPos.x = x;
    rCamData.mPos.y = y;
    rCamData.mPos.z = z;

    rCamData.mFlags &= ~0x8;
  }
}

void Camera::SetPosition(const math::VEC3& rPos) {
  CameraData& rCamData = mCamData.ref();

  if (mCamData.IsValid()) {
    rCamData.mPos = rPos;
    rCamData.mFlags &= ~0x8;
  }
}

void Camera::SetPosture(const PostureInfo& rPosture) {
  CameraData& rCamData = mCamData.ref();

  if (mCamData.IsValid()) {
    switch (rPosture.INT_0x0) {
    case 0:
      if (rCamData.mFlags & 0x1) {
        bool b = (rPosture.VEC3_0x04 != rCamData.VEC3_0x80);
        if (!b) {
          b = (rPosture.VEC3_0x10 != rCamData.VEC3_0x8C);
          if (!b)
            return;
        }
      }
      rCamData.mFlags &= ~0x7;
      rCamData.mFlags |= 0x1;
      rCamData.VEC3_0x80 = rPosture.VEC3_0x04;
      rCamData.VEC3_0x8C = rPosture.VEC3_0x10;
      rCamData.mFlags &= ~0x8;
      break;

    case 1:
      if (rCamData.mFlags & 0x2) {
        bool b = (rPosture.VEC3_0x1C != rCamData.VEC3_0x98);
        if (!b)
          return;
      }
      rCamData.mFlags &= ~0x7;
      rCamData.mFlags |= 0x2;
      rCamData.VEC3_0x98 = rPosture.VEC3_0x1C;
      rCamData.mFlags &= ~0x8;
      break;

    case 2:
      if (rCamData.mFlags & 0x4) {
        bool b = (rPosture.VEC3_0x10 != rCamData.VEC3_0x8C);
        if (!b && rPosture.FLOAT_0x28 == rCamData.FLOAT_0xA4)
          return;
      }
      rCamData.mFlags &= ~0x7;
      rCamData.mFlags |= 0x4;
      rCamData.VEC3_0x8C = rPosture.VEC3_0x10;
      rCamData.FLOAT_0xA4 = rPosture.FLOAT_0x28;
      rCamData.mFlags &= ~0x8;
      break;

    default:
      break;
    }
  }
}

void Camera::SetCameraMtxDirectly(const math::MTX34& rMtx) {
  CameraData& rCamData = mCamData.ref();

  if (mCamData.IsValid()) {
    PSMTXCopy(rMtx.mtx, rCamData.mCamMtx.mtx);
    rCamData.mFlags |= 0x8;
  }
}

} // namespace g3d
} // namespace nw4r

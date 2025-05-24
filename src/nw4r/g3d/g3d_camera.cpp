// Source:
// https://github.com/doldecomp/ogws/blob/82dbeac2267170fc5cef7e67a6d8c31c5ff45d69/src/nw4r/g3d/g3d_camera.cpp
// Decompiled by kiwi515.

#include "g3d_camera.hpp"

#include <decomp.h>

#include <rvl/gx/gxTransform.h>
#include <rvl/mtx/mtx.h>

#include "g3d_state.hpp"

extern "C" {

// PAL: 0x8006a520..0x8006a560
UNKNOWN_FUNCTION(SetPerspective__Q34nw4r3g3d6CameraFffff);
// PAL: 0x8006a560..0x8006a5a0
UNKNOWN_FUNCTION(SetOrtho__Q34nw4r3g3d6CameraFffffff);
// PAL: 0x8006a5a0..0x8006a5f0
UNKNOWN_FUNCTION(
    SetProjectionMtxDirectly__Q34nw4r3g3d6CameraFPCQ34nw4r4math5MTX44);
// PAL: 0x8006a5f0..0x8006a610
UNKNOWN_FUNCTION(SetScissor__Q34nw4r3g3d6CameraFUlUlUlUl);
// PAL: 0x8006a610..0x8006a630
UNKNOWN_FUNCTION(SetScissorBoxOffset__Q34nw4r3g3d6CameraFll);
// PAL: 0x8006a630..0x8006a6d0
UNKNOWN_FUNCTION(SetViewport__Q34nw4r3g3d6CameraFffff);
// PAL: 0x8006a6d0..0x8006a6f0
UNKNOWN_FUNCTION(SetViewportZRange__Q34nw4r3g3d6CameraFff);
// PAL: 0x8006a6f0..0x8006a760
UNKNOWN_FUNCTION(GetViewport__Q34nw4r3g3d6CameraCFPfPfPfPfPfPf);
// PAL: 0x8006a760..0x8006a7c0
UNKNOWN_FUNCTION(GetCameraMtx__Q34nw4r3g3d6CameraCFPQ34nw4r4math5MTX34);
// PAL: 0x8006a7c0..0x8006a8a0
UNKNOWN_FUNCTION(GetProjectionMtx__Q34nw4r3g3d6CameraCFPQ34nw4r4math5MTX44);
// PAL: 0x8006a8a0..0x8006a970
UNKNOWN_FUNCTION(GetProjectionTexMtx__Q34nw4r3g3d6CameraCFPQ34nw4r4math5MTX34);
// PAL: 0x8006a970..0x8006a9f0
UNKNOWN_FUNCTION(GetEnvironmentTexMtx__Q34nw4r3g3d6CameraCFPQ34nw4r4math5MTX34);
// PAL: 0x8006a9f0..0x8006aa80
UNKNOWN_FUNCTION(GXSetViewport__Q34nw4r3g3d6CameraCFv);
// PAL: 0x8006aa80..0x8006ab50
UNKNOWN_FUNCTION(GXSetProjection__Q34nw4r3g3d6CameraCFv);
// PAL: 0x8006ab50..0x8006ab80
UNKNOWN_FUNCTION(GXSetScissor__Q34nw4r3g3d6CameraCFv);
// PAL: 0x8006ab80..0x8006aba0
UNKNOWN_FUNCTION(GXSetScissorBoxOffset__Q34nw4r3g3d6CameraCFv);
// PAL: 0x8006aba0..0x8006afbc
UNKNOWN_FUNCTION(UpdateCameraMtx__Q34nw4r3g3d6CameraCFv);
// PAL: 0x80064440
extern UNKNOWN_FUNCTION(GetRenderModeObj__Q34nw4r3g3d8G3DStateFv);
// PAL: 0x800851e0
extern UNKNOWN_FUNCTION(SinCosFIdx__Q24nw4r4mathFPfPff);
// PAL: 0x80085b80
extern UNKNOWN_FUNCTION(unk_80085b80);
}

namespace nw4r {
namespace g3d {

Camera::Camera(CameraData* pCamData) : mCamData(pCamData) {}

void Camera::Init() {
  GXRenderModeObj& rRenderMode = G3DState::GetRenderModeObj();
  Init(rRenderMode.fb_width, rRenderMode.efb_height, rRenderMode.fb_width,
       rRenderMode.xfb_height, rRenderMode.vi_width, rRenderMode.vi_height);
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

// PAL: 0x8006a520..0x8006a560
MARK_BINARY_BLOB(Camera_SetPerspective, 0x8006a520, 0x8006a560);
asm void Camera::SetPerspective(f32, f32, f32, f32) {
  // clang-format off
  nofralloc;
  lwz r3, 0(r3);
  cmpwi r3, 0;
  beqlr;
  li r0, 0;
  stw r0, 0xa8(r3);
  stfs f1, 0xac(r3);
  stfs f2, 0xb0(r3);
  stfs f3, 0xb4(r3);
  stfs f4, 0xb8(r3);
  lwz r0, 0x70(r3);
  rlwinm r0, r0, 0, 0x1c, 0x17;
  ori r0, r0, 0x20;
  stw r0, 0x70(r3);
  blr;
  // clang-format on
}

// PAL: 0x8006a560..0x8006a5a0
MARK_BINARY_BLOB(Camera_SetOrtho, 0x8006a560, 0x8006a5a0);
asm void Camera::SetOrtho(f32, f32, f32, f32, f32, f32) {
  // clang-format off
  nofralloc;
  lwz r3, 0(r3);
  cmpwi r3, 0;
  beqlr;
  li r0, 1;
  stw r0, 0xa8(r3);
  stfs f1, 0xbc(r3);
  stfs f2, 0xc0(r3);
  stfs f3, 0xc4(r3);
  stfs f4, 0xc8(r3);
  stfs f5, 0xb4(r3);
  stfs f6, 0xb8(r3);
  lwz r0, 0x70(r3);
  rlwinm r0, r0, 0, 0x1c, 0x17;
  ori r0, r0, 0x40;
  stw r0, 0x70(r3);
  blr;
  // clang-format on
}

// PAL: 0x8006a5a0..0x8006a5f0
MARK_BINARY_BLOB(Camera_SetProjectionMtxDirectly, 0x8006a5a0, 0x8006a5f0);
asm void Camera::SetProjectionMtxDirectly(const math::MTX44*) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmpwi r4, 0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  beq lbl_8006a5d8;
  lwz r31, 0(r3);
  cmpwi r31, 0;
  beq lbl_8006a5d8;
  addi r3, r31, 0x30;
  bl unk_80085b80;
  lwz r0, 0x70(r31);
  ori r0, r0, 0x80;
  stw r0, 0x70(r31);
lbl_8006a5d8:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// PAL: 0x8006a5f0..0x8006a610
MARK_BINARY_BLOB(Camera_SetScissor, 0x8006a5f0, 0x8006a610);
asm void Camera::SetScissor(u32, u32, u32, u32) {
  // clang-format off
  nofralloc;
  lwz r3, 0(r3);
  cmpwi r3, 0;
  beqlr;
  stw r4, 0xf4(r3);
  stw r5, 0xf8(r3);
  stw r6, 0xfc(r3);
  stw r7, 0x100(r3);
  blr;
  // clang-format on
}

// PAL: 0x8006a610..0x8006a630
MARK_BINARY_BLOB(Camera_SetScissorBoxOffset, 0x8006a610, 0x8006a630);
asm void Camera::SetScissorBoxOffset(s32, s32) {
  // clang-format off
  nofralloc;
  lwz r3, 0(r3);
  cmpwi r3, 0;
  beqlr;
  stw r4, 0x104(r3);
  stw r5, 0x108(r3);
  blr;
  // clang-format on
}

// PAL: 0x8006a630..0x8006a6d0
MARK_BINARY_BLOB(Camera_SetViewport, 0x8006a630, 0x8006a6d0);
asm void Camera::SetViewport(f32, f32, f32, f32) {
  // clang-format off
  nofralloc;
  stwu r1, -0x30(r1);
  mflr r0;
  stw r0, 0x34(r1);
  stfd f31, 0x28(r1);
  fmr f31, f4;
  stfd f30, 0x20(r1);
  fmr f30, f3;
  stfd f29, 0x18(r1);
  fmr f29, f2;
  stw r31, 0x14(r1);
  lwz r4, 0(r3);
  cmpwi r4, 0;
  beq lbl_8006a6ac;
  stfs f1, 0xdc(r4);
  stfs f2, 0xe0(r4);
  stfs f3, 0xe4(r4);
  stfs f4, 0xe8(r4);
  lwz r31, 0(r3);
  cmpwi r31, 0;
  beq lbl_8006a6ac;
  bl __cvt_fp2unsigned;
  fmr f1, f29;
  stw r3, 0xf4(r31);
  bl __cvt_fp2unsigned;
  fmr f1, f30;
  stw r3, 0xf8(r31);
  bl __cvt_fp2unsigned;
  fmr f1, f31;
  stw r3, 0xfc(r31);
  bl __cvt_fp2unsigned;
  stw r3, 0x100(r31);
lbl_8006a6ac:
  lwz r0, 0x34(r1);
  lfd f31, 0x28(r1);
  lfd f30, 0x20(r1);
  lfd f29, 0x18(r1);
  lwz r31, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x30;
  blr;
  // clang-format on
}

// PAL: 0x8006a6d0..0x8006a6f0
MARK_BINARY_BLOB(Camera_SetViewportZRange, 0x8006a6d0, 0x8006a6f0);
asm void Camera::SetViewportZRange(f32, f32) {
  // clang-format off
  nofralloc;
  lwz r3, 0(r3);
  cmpwi r3, 0;
  beqlr;
  stfs f1, 0xec(r3);
  stfs f2, 0xf0(r3);
  blr;
  // clang-format on
}

// PAL: 0x8006a6f0..0x8006a760
MARK_BINARY_BLOB(Camera_GetViewport, 0x8006a6f0, 0x8006a760);
asm void Camera::GetViewport(f32*, f32*, f32*, f32*, f32*, f32*) const {
  // clang-format off
  nofralloc;
  lwz r3, 0(r3);
  cmpwi r3, 0;
  beqlr;
  cmpwi r4, 0;
  beq lbl_8006a70c;
  lfs f0, 0xdc(r3);
  stfs f0, 0(r4);
lbl_8006a70c:
  cmpwi r5, 0;
  beq lbl_8006a71c;
  lfs f0, 0xe0(r3);
  stfs f0, 0(r5);
lbl_8006a71c:
  cmpwi r6, 0;
  beq lbl_8006a72c;
  lfs f0, 0xe4(r3);
  stfs f0, 0(r6);
lbl_8006a72c:
  cmpwi r7, 0;
  beq lbl_8006a73c;
  lfs f0, 0xe8(r3);
  stfs f0, 0(r7);
lbl_8006a73c:
  cmpwi r8, 0;
  beq lbl_8006a74c;
  lfs f0, 0xec(r3);
  stfs f0, 0(r8);
lbl_8006a74c:
  cmpwi r9, 0;
  beqlr;
  lfs f0, 0xf0(r3);
  stfs f0, 0(r9);
  blr;
  // clang-format on
}

// PAL: 0x8006a760..0x8006a7c0
MARK_BINARY_BLOB(Camera_GetCameraMtx, 0x8006a760, 0x8006a7c0);
asm void Camera::GetCameraMtx(math::MTX34*) const {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmpwi r4, 0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  stw r30, 8(r1);
  mr r30, r4;
  beq lbl_8006a7a8;
  lwz r31, 0(r3);
  cmpwi r31, 0;
  beq lbl_8006a7a8;
  lwz r0, 0x70(r31);
  rlwinm. r0, r0, 0, 0x1c, 0x1c;
  bne lbl_8006a79c;
  bl UpdateCameraMtx__Q34nw4r3g3d6CameraCFv;
lbl_8006a79c:
  mr r3, r31;
  mr r4, r30;
  bl PSMTXCopy;
lbl_8006a7a8:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// PAL: 0x8006a7c0..0x8006a8a0
MARK_BINARY_BLOB(Camera_GetProjectionMtx, 0x8006a7c0, 0x8006a8a0);
asm void Camera::GetProjectionMtx(math::MTX44*) const {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmpwi r4, 0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  stw r30, 8(r1);
  mr r30, r4;
  beq lbl_8006a884;
  lwz r31, 0(r3);
  cmpwi r31, 0;
  beq lbl_8006a884;
  lwz r0, 0x70(r31);
  rlwinm. r0, r0, 0, 0x18, 0x18;
  bne lbl_8006a878;
  lwz r3, 0x70(r31);
  rlwinm. r0, r3, 0, 0x19, 0x19;
  beq lbl_8006a828;
  lfs f1, 0xbc(r31);
  addi r3, r31, 0x30;
  lfs f2, 0xc0(r31);
  lfs f3, 0xc4(r31);
  lfs f4, 0xc8(r31);
  lfs f5, 0xb4(r31);
  lfs f6, 0xb8(r31);
  bl C_MTXOrtho;
  b lbl_8006a86c;
lbl_8006a828:
  rlwinm. r0, r3, 0, 0x1b, 0x1b;
  beq lbl_8006a854;
  lfs f1, 0xbc(r31);
  addi r3, r31, 0x30;
  lfs f2, 0xc0(r31);
  lfs f3, 0xc4(r31);
  lfs f4, 0xc8(r31);
  lfs f5, 0xb4(r31);
  lfs f6, 0xb8(r31);
  bl C_MTXFrustum;
  b lbl_8006a86c;
lbl_8006a854:
  lfs f1, 0xac(r31);
  addi r3, r31, 0x30;
  lfs f2, 0xb0(r31);
  lfs f3, 0xb4(r31);
  lfs f4, 0xb8(r31);
  bl C_MTXPerspective;
lbl_8006a86c:
  lwz r0, 0x70(r31);
  ori r0, r0, 0x80;
  stw r0, 0x70(r31);
lbl_8006a878:
  mr r3, r30;
  addi r4, r31, 0x30;
  bl unk_80085b80;
lbl_8006a884:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// PAL: 0x8006a8a0..0x8006a970
MARK_BINARY_BLOB(Camera_GetProjectionTexMtx, 0x8006a8a0, 0x8006a970);
asm void Camera::GetProjectionTexMtx(math::MTX34*) const {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmpwi r4, 0;
  stw r0, 0x14(r1);
  beq lbl_8006a960;
  lwz r5, 0(r3);
  cmpwi r5, 0;
  beq lbl_8006a960;
  lwz r3, 0x70(r5);
  rlwinm. r0, r3, 0, 0x19, 0x19;
  beq lbl_8006a8fc;
  lfs f0, 0xd0(r5);
  mr r3, r4;
  lfs f1, 0xbc(r5);
  fneg f6, f0;
  lfs f2, 0xc0(r5);
  lfs f3, 0xc4(r5);
  lfs f4, 0xc8(r5);
  lfs f5, 0xcc(r5);
  lfs f7, 0xd4(r5);
  lfs f8, 0xd8(r5);
  bl C_MTXLightOrtho;
  b lbl_8006a960;
lbl_8006a8fc:
  rlwinm. r0, r3, 0, 0x1b, 0x1b;
  beq lbl_8006a93c;
  lfs f0, 0xd8(r5);
  mr r3, r4;
  stfs f0, 8(r1);
  lfs f0, 0xd0(r5);
  lfs f1, 0xbc(r5);
  fneg f7, f0;
  lfs f2, 0xc0(r5);
  lfs f3, 0xc4(r5);
  lfs f4, 0xc8(r5);
  lfs f5, 0xb4(r5);
  lfs f6, 0xcc(r5);
  lfs f8, 0xd4(r5);
  bl C_MTXLightFrustum;
  b lbl_8006a960;
lbl_8006a93c:
  lfs f0, 0xd0(r5);
  mr r3, r4;
  lfs f1, 0xac(r5);
  fneg f4, f0;
  lfs f2, 0xb0(r5);
  lfs f3, 0xcc(r5);
  lfs f5, 0xd4(r5);
  lfs f6, 0xd8(r5);
  bl C_MTXLightPerspective;
lbl_8006a960:
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// PAL: 0x8006a970..0x8006a9f0
MARK_BINARY_BLOB(Camera_GetEnvironmentTexMtx, 0x8006a970, 0x8006a9f0);
asm void Camera::GetEnvironmentTexMtx(math::MTX34*) const {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  cmpwi r4, 0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  stw r30, 8(r1);
  mr r30, r4;
  beq lbl_8006a9d8;
  lwz r31, 0(r3);
  cmpwi r31, 0;
  beq lbl_8006a9d8;
  mr r3, r30;
  bl PSMTXIdentity;
  lfs f0, 0xcc(r31);
  stfs f0, 0(r30);
  lfs f1, -0x72f0(r2);
  lfs f0, 0xd4(r31);
  stfs f0, 0xc(r30);
  lfs f0, -0x72e8(r2);
  lfs f2, 0xd0(r31);
  fneg f2, f2;
  stfs f2, 0x14(r30);
  lfs f2, 0xd8(r31);
  stfs f2, 0x1c(r30);
  stfs f1, 0x28(r30);
  stfs f0, 0x2c(r30);
lbl_8006a9d8:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  lwz r30, 8(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// PAL: 0x8006a9f0..0x8006aa80
MARK_BINARY_BLOB(Camera_GXSetViewport, 0x8006a9f0, 0x8006aa80);
asm void Camera::GXSetViewport_() const {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  lwz r31, 0(r3);
  cmpwi r31, 0;
  beq lbl_8006aa60;
  bl GetRenderModeObj__Q34nw4r3g3d8G3DStateFv;
  lbz r0, 0x18(r3);
  cmpwi r0, 0;
  beq lbl_8006aa44;
  lwz r0, 0x70(r31);
  lfs f1, 0xdc(r31);
  lfs f2, 0xe0(r31);
  rlwinm r3, r0, 0x18, 0x1f, 0x1f;
  lfs f3, 0xe4(r31);
  lfs f4, 0xe8(r31);
  lfs f5, 0xec(r31);
  lfs f6, 0xf0(r31);
  bl GXSetViewportJitter;
  b lbl_8006aa60;
lbl_8006aa44:
  lfs f1, 0xdc(r31);
  lfs f2, 0xe0(r31);
  lfs f3, 0xe4(r31);
  lfs f4, 0xe8(r31);
  lfs f5, 0xec(r31);
  lfs f6, 0xf0(r31);
  bl GXSetViewport;
lbl_8006aa60:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// PAL: 0x8006aa80..0x8006ab50
MARK_BINARY_BLOB(Camera_GXSetProjection, 0x8006aa80, 0x8006ab50);
asm void Camera::GXSetProjection_() const {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  stw r31, 0xc(r1);
  lwz r31, 0(r3);
  cmpwi r31, 0;
  beq lbl_8006ab34;
  lwz r0, 0x70(r31);
  rlwinm. r0, r0, 0, 0x18, 0x18;
  bne lbl_8006ab28;
  lwz r3, 0x70(r31);
  rlwinm. r0, r3, 0, 0x19, 0x19;
  beq lbl_8006aad8;
  lfs f1, 0xbc(r31);
  addi r3, r31, 0x30;
  lfs f2, 0xc0(r31);
  lfs f3, 0xc4(r31);
  lfs f4, 0xc8(r31);
  lfs f5, 0xb4(r31);
  lfs f6, 0xb8(r31);
  bl C_MTXOrtho;
  b lbl_8006ab1c;
lbl_8006aad8:
  rlwinm. r0, r3, 0, 0x1b, 0x1b;
  beq lbl_8006ab04;
  lfs f1, 0xbc(r31);
  addi r3, r31, 0x30;
  lfs f2, 0xc0(r31);
  lfs f3, 0xc4(r31);
  lfs f4, 0xc8(r31);
  lfs f5, 0xb4(r31);
  lfs f6, 0xb8(r31);
  bl C_MTXFrustum;
  b lbl_8006ab1c;
lbl_8006ab04:
  lfs f1, 0xac(r31);
  addi r3, r31, 0x30;
  lfs f2, 0xb0(r31);
  lfs f3, 0xb4(r31);
  lfs f4, 0xb8(r31);
  bl C_MTXPerspective;
lbl_8006ab1c:
  lwz r0, 0x70(r31);
  ori r0, r0, 0x80;
  stw r0, 0x70(r31);
lbl_8006ab28:
  lwz r4, 0xa8(r31);
  addi r3, r31, 0x30;
  bl GXSetProjection;
lbl_8006ab34:
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// PAL: 0x8006ab50..0x8006ab80
MARK_BINARY_BLOB(Camera_GXSetScissor, 0x8006ab50, 0x8006ab80);
asm void Camera::GXSetScissor_() const {
  // clang-format off
  nofralloc;
  lwz r6, 0(r3);
  cmpwi r6, 0;
  beqlr;
  lwz r3, 0xf4(r6);
  lwz r4, 0xf8(r6);
  lwz r5, 0xfc(r6);
  lwz r6, 0x100(r6);
  b GXSetScissor;
  blr;
  // clang-format on
}

// PAL: 0x8006ab80..0x8006aba0
MARK_BINARY_BLOB(Camera_GXSetScissorBoxOffset, 0x8006ab80, 0x8006aba0);
asm void Camera::GXSetScissorBoxOffset_() const {
  // clang-format off
  nofralloc;
  lwz r4, 0(r3);
  cmpwi r4, 0;
  beqlr;
  lwz r3, 0x104(r4);
  lwz r4, 0x108(r4);
  b GXSetScissorBoxOffset;
  blr;
  // clang-format on
}

// PAL: 0x8006aba0..0x8006afbc
MARK_BINARY_BLOB(Camera_UpdateCameraMtx, 0x8006aba0, 0x8006afbc);
asm void Camera::UpdateCameraMtx() const {
  // clang-format off
  nofralloc;
  stwu r1, -0xa0(r1);
  mflr r0;
  stw r0, 0xa4(r1);
  stfd f31, 0x90(r1);
  psq_st f31, 152(r1), 0, 0;
  stw r31, 0x8c(r1);
  lwz r31, 0(r3);
  lwz r3, 0x70(r31);
  clrlwi. r0, r3, 0x1f;
  beq lbl_8006abe0;
  mr r3, r31;
  addi r4, r31, 0x74;
  addi r5, r31, 0x80;
  addi r6, r31, 0x8c;
  bl C_MTXLookAt;
  b lbl_8006af94;
lbl_8006abe0:
  rlwinm. r0, r3, 0, 0x1d, 0x1d;
  beq lbl_8006ae24;
  lfs f1, 0x74(r31);
  lfs f0, 0x8c(r31);
  lfs f4, 0x7c(r31);
  fsubs f5, f1, f0;
  lfs f3, 0x94(r31);
  lfs f2, -0x72f0(r2);
  lfs f1, 0x78(r31);
  fsubs f3, f4, f3;
  lfs f0, 0x90(r31);
  fcmpu cr0, f2, f5;
  fsubs f0, f1, f0;
  stfs f5, 0x7c(r1);
  stfs f0, 0x80(r1);
  stfs f3, 0x84(r1);
  bne lbl_8006acb0;
  fcmpu cr0, f2, f3;
  bne lbl_8006acb0;
  lfs f1, -0x72e8(r2);
  stfs f1, 0(r31);
  stfs f2, 4(r31);
  stfs f2, 8(r31);
  lfs f0, 0x74(r31);
  fneg f0, f0;
  stfs f0, 0xc(r31);
  stfs f2, 0x10(r31);
  stfs f2, 0x14(r31);
  stfs f2, 0x20(r31);
  stfs f2, 0x28(r31);
  lfs f0, 0x80(r1);
  fcmpo cr0, f0, f2;
  cror 2, 0, 2;
  bne lbl_8006ac8c;
  stfs f1, 0x18(r31);
  lfs f0, -0x72c8(r2);
  lfs f1, 0x7c(r31);
  fneg f1, f1;
  stfs f1, 0x1c(r31);
  stfs f0, 0x24(r31);
  lfs f0, 0x78(r31);
  stfs f0, 0x2c(r31);
  b lbl_8006af94;
lbl_8006ac8c:
  lfs f0, -0x72c8(r2);
  stfs f0, 0x18(r31);
  lfs f0, 0x7c(r31);
  stfs f0, 0x1c(r31);
  stfs f1, 0x24(r31);
  lfs f0, 0x78(r31);
  fneg f0, f0;
  stfs f0, 0x2c(r31);
  b lbl_8006af94;
lbl_8006acb0:
  lfs f0, 0x7c(r1);
  addi r3, r1, 0x7c;
  lfs f1, 0x84(r1);
  mr r4, r3;
  fneg f2, f0;
  lfs f0, -0x72f0(r2);
  stfs f1, 0x70(r1);
  stfs f0, 0x74(r1);
  stfs f2, 0x78(r1);
  bl PSVECNormalize;
  addi r3, r1, 0x70;
  mr r4, r3;
  bl PSVECNormalize;
  addi r3, r1, 0x7c;
  addi r4, r1, 0x70;
  addi r5, r1, 0x64;
  bl PSVECCrossProduct;
  lfs f1, 0xa4(r31);
  addi r3, r1, 0x24;
  lfs f0, -0x72c4(r2);
  addi r4, r1, 0x20;
  fmuls f1, f0, f1;
  bl SinCosFIdx__Q24nw4r4mathFPfPff;
  lfs f11, 0x24(r1);
  addi r3, r1, 0x58;
  lfs f0, 0x64(r1);
  addi r4, r1, 0x4c;
  lfs f10, 0x20(r1);
  addi r5, r1, 0x7c;
  lfs f4, 0x70(r1);
  fmuls f2, f11, f0;
  fmuls f1, f10, f0;
  lfs f6, 0x6c(r1);
  fmuls f0, f10, f4;
  lfs f8, 0x68(r1);
  lfs f5, 0x78(r1);
  fmuls f7, f11, f8;
  fadds f9, f2, f0;
  fmuls f3, f11, f6;
  stfs f7, 0x5c(r1);
  fmuls f2, f10, f5;
  stfs f9, 0(r31);
  fmuls f0, f11, f4;
  fadds f4, f3, f2;
  stfs f7, 4(r31);
  fsubs f3, f1, f0;
  stfs f4, 8(r31);
  fmuls f1, f10, f6;
  fmuls f0, f11, f5;
  stfs f4, 0x60(r1);
  fmuls f2, f10, f8;
  psq_l f6, 120(r31), 0, 0;
  psq_l f4, 4(r3), 0, 0;
  fsubs f1, f1, f0;
  stfs f9, 0x58(r1);
  ps_mul f6, f6, f4;
  psq_l f5, 116(r31), 1, 0;
  psq_l f0, 0(r3), 1, 0;
  stfs f3, 0x4c(r1);
  ps_madd f4, f5, f0, f6;
  stfs f2, 0x50(r1);
  psq_l f7, 0(r4), 1, 0;
  ps_sum0 f0, f4, f6, f6;
  stfs f1, 0x54(r1);
  psq_l f5, 4(r4), 0, 0;
  fneg f0, f0;
  stfs f0, 0xc(r31);
  stfs f3, 0x10(r31);
  stfs f2, 0x14(r31);
  stfs f1, 0x18(r31);
  psq_l f1, 120(r31), 0, 0;
  psq_l f0, 116(r31), 1, 0;
  ps_mul f1, f1, f5;
  ps_madd f5, f0, f7, f1;
  ps_sum0 f0, f5, f1, f1;
  fneg f0, f0;
  stfs f0, 0x1c(r31);
  lfs f0, 0x7c(r1);
  stfs f0, 0x20(r31);
  lfs f0, 0x80(r1);
  stfs f0, 0x24(r31);
  lfs f0, 0x84(r1);
  stfs f0, 0x28(r31);
  psq_l f2, 120(r31), 0, 0;
  psq_l f1, 4(r5), 0, 0;
  psq_l f0, 116(r31), 1, 0;
  ps_mul f2, f2, f1;
  psq_l f1, 0(r5), 1, 0;
  ps_madd f1, f0, f1, f2;
  ps_sum0 f0, f1, f2, f2;
  fneg f0, f0;
  stfs f0, 0x2c(r31);
  b lbl_8006af94;
lbl_8006ae24:
  lfs f1, 0x98(r31);
  addi r3, r1, 0x1c;
  lfs f0, -0x72c4(r2);
  addi r4, r1, 0x10;
  fmuls f1, f0, f1;
  bl SinCosFIdx__Q24nw4r4mathFPfPff;
  lfs f1, 0x9c(r31);
  addi r3, r1, 0x18;
  lfs f0, -0x72c4(r2);
  addi r4, r1, 0xc;
  fmuls f1, f0, f1;
  bl SinCosFIdx__Q24nw4r4mathFPfPff;
  lfs f1, 0xa0(r31);
  addi r3, r1, 0x14;
  lfs f0, -0x72c4(r2);
  addi r4, r1, 8;
  fmuls f1, f0, f1;
  bl SinCosFIdx__Q24nw4r4mathFPfPff;
  lfs f2, 0x1c(r1);
  addi r3, r1, 0x40;
  lfs f31, 0x18(r1);
  addi r4, r1, 0x34;
  lfs f12, 0x14(r1);
  fneg f0, f2;
  fmuls f13, f2, f31;
  lfs f11, 0xc(r1);
  lfs f10, 8(r1);
  fmuls f1, f31, f12;
  lfs f8, 0x10(r1);
  fmuls f4, f12, f13;
  fmuls f3, f11, f10;
  stfs f0, 0x2c(r1);
  fmuls f2, f2, f11;
  addi r5, r1, 0x28;
  fmuls f7, f8, f12;
  fadds f9, f4, f3;
  fmuls f4, f12, f2;
  stfs f7, 0x44(r1);
  fmuls f3, f31, f10;
  stfs f9, 0(r31);
  fmuls f5, f8, f10;
  fmuls f2, f10, f2;
  fsubs f6, f4, f3;
  stfs f7, 4(r31);
  fmuls f3, f8, f31;
  stfs f6, 0x48(r1);
  fadds f4, f2, f1;
  fmuls f2, f8, f11;
  stfs f6, 8(r31);
  fmuls f6, f10, f13;
  psq_l f7, 4(r3), 0, 0;
  fmuls f1, f11, f12;
  psq_l f10, 120(r31), 0, 0;
  stfs f9, 0x40(r1);
  frsp f0, f0;
  ps_mul f10, f10, f7;
  psq_l f7, 116(r31), 1, 0;
  psq_l f8, 0(r3), 1, 0;
  fsubs f6, f6, f1;
  stfs f2, 0x30(r1);
  ps_madd f7, f7, f8, f10;
  stfs f3, 0x28(r1);
  psq_l f11, 4(r5), 0, 0;
  ps_sum0 f1, f7, f10, f10;
  stfs f6, 0x34(r1);
  psq_l f9, 0(r5), 1, 0;
  stfs f5, 0x38(r1);
  fneg f1, f1;
  psq_l f7, 0(r4), 1, 0;
  stfs f4, 0x3c(r1);
  stfs f1, 0xc(r31);
  psq_l f8, 4(r4), 0, 0;
  stfs f6, 0x10(r31);
  stfs f5, 0x14(r31);
  stfs f4, 0x18(r31);
  psq_l f4, 120(r31), 0, 0;
  psq_l f1, 116(r31), 1, 0;
  ps_mul f4, f4, f8;
  ps_madd f8, f1, f7, f4;
  ps_sum0 f1, f8, f4, f4;
  fneg f1, f1;
  stfs f1, 0x1c(r31);
  stfs f3, 0x20(r31);
  stfs f0, 0x24(r31);
  stfs f2, 0x28(r31);
  psq_l f1, 120(r31), 0, 0;
  psq_l f0, 116(r31), 1, 0;
  ps_mul f1, f1, f11;
  ps_madd f11, f0, f9, f1;
  ps_sum0 f0, f11, f1, f1;
  fneg f0, f0;
  stfs f0, 0x2c(r31);
lbl_8006af94:
  lwz r0, 0x70(r31);
  ori r0, r0, 8;
  stw r0, 0x70(r31);
  psq_l f31, 152(r1), 0, 0;
  lfd f31, 0x90(r1);
  lwz r31, 0x8c(r1);
  lwz r0, 0xa4(r1);
  mtlr r0;
  addi r1, r1, 0xa0;
  blr;
  // clang-format on
}

} // namespace g3d
} // namespace nw4r

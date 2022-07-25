/*!
 * @file
 * @brief Implementations for the EGG video / render manager.
 */

#include <egg/core/eggVideo.hpp>
#include <rvl/gx.h>
#include <rvl/gx/gxFrameBuf.h>
#include <rvl/os/osThread.h>
#include <rvl/sc.h>
#include <rvl/vi.h>

namespace EGG {

namespace {

const GXRenderModeObj gRMO_Ntsc_640x456IntDf_4x3 = {VI_TVMODE_NTSC_INT,
                                                    0x280,
                                                    0x1c8,
                                                    0x1c8,
                                                    0x19,
                                                    0xc,
                                                    0x29e,
                                                    0x1c8,
                                                    VI_XFBMODE_DF,
                                                    0,
                                                    0,
                                                    6,
                                                    6,
                                                    6,
                                                    6,
                                                    6,
                                                    6,
                                                    6,
                                                    6,
                                                    6,
                                                    6,
                                                    6,
                                                    6,
                                                    6,
                                                    6,
                                                    6,
                                                    6,
                                                    6,
                                                    6,
                                                    6,
                                                    6,
                                                    6,
                                                    6,
                                                    6,
                                                    6,
                                                    7,
                                                    7,
                                                    0xC,
                                                    0xC,
                                                    0xC,
                                                    7,
                                                    7};
const GXRenderModeObj gRMO_Ntsc_640x456Prog_4x3 = {VI_TVMODE_NTSC_PROG,
                                                   0x280,
                                                   0x1c8,
                                                   0x1c8,
                                                   0x19,
                                                   0xc,
                                                   0x29e,
                                                   0x1c8,
                                                   VI_XFBMODE_SF,
                                                   0,
                                                   0,
                                                   6,
                                                   6,
                                                   6,
                                                   6,
                                                   6,
                                                   6,
                                                   6,
                                                   6,
                                                   6,
                                                   6,
                                                   6,
                                                   6,
                                                   6,
                                                   6,
                                                   6,
                                                   6,
                                                   6,
                                                   6,
                                                   6,
                                                   6,
                                                   6,
                                                   6,
                                                   6,
                                                   6,
                                                   0,
                                                   0,
                                                   0x15,
                                                   0x16,
                                                   0x15,
                                                   0};

const GXRenderModeObj gRMO_Pal50_640x456IntDf_4x3 = {VI_TVMODE_PAL_INT,
                                                     0x280,
                                                     0x1c8,
                                                     0x21e,
                                                     0x1B,
                                                     0x10,
                                                     0x29a,
                                                     0x21e,
                                                     VI_XFBMODE_DF,
                                                     0,
                                                     0,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     7,
                                                     7,
                                                     0xC,
                                                     0xC,
                                                     0xC,
                                                     7,
                                                     7};

const GXRenderModeObj gRMO_Pal60_640x456IntDf_4x3 = {VI_TVMODE_EURGB60_INT,
                                                     0x280,
                                                     0x1C8,
                                                     0x1c8,
                                                     0x19,
                                                     0xc,
                                                     0x29e,
                                                     0x1c8,
                                                     VI_XFBMODE_DF,
                                                     0,
                                                     0,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     7,
                                                     7,
                                                     0xC,
                                                     0xC,
                                                     0xC,
                                                     7,
                                                     7};

const GXRenderModeObj gRMO_Pal60_640x456Prog_4x3 = {VI_TVMODE_EURGB60_PROG,
                                                    0x280,
                                                    0x1c8,
                                                    0x1c8,
                                                    0x19,
                                                    0xc,
                                                    0x29e,
                                                    0x1c8,
                                                    VI_XFBMODE_SF,
                                                    0,
                                                    0,
                                                    6,
                                                    6,
                                                    6,
                                                    6,
                                                    6,
                                                    6,
                                                    6,
                                                    6,
                                                    6,
                                                    6,
                                                    6,
                                                    6,
                                                    6,
                                                    6,
                                                    6,
                                                    6,
                                                    6,
                                                    6,
                                                    6,
                                                    6,
                                                    6,
                                                    6,
                                                    6,
                                                    6,
                                                    0,
                                                    0,
                                                    0x15,
                                                    0x16,
                                                    0x15,
                                                    0,
                                                    0};

const GXRenderModeObj gRMO_Ntsc_640x456IntDf_16x9 = {VI_TVMODE_NTSC_INT,
                                                     0x280,
                                                     0x1c8,
                                                     0x1c8,
                                                     0x11,
                                                     0xc,
                                                     0x2ae,
                                                     0x1c8,
                                                     VI_XFBMODE_DF,
                                                     0,
                                                     0,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     7,
                                                     7,
                                                     0xC,
                                                     0xC,
                                                     0xC,
                                                     7,
                                                     7};
const GXRenderModeObj gRMO_Ntsc_640x456Prog_16x9 = {VI_TVMODE_NTSC_PROG,
                                                    0x280,
                                                    0x1c8,
                                                    0x1c8,
                                                    0x11,
                                                    0xc,
                                                    0x2ae,
                                                    0x1c8,
                                                    VI_XFBMODE_SF,
                                                    0,
                                                    0,
                                                    6,
                                                    6,
                                                    6,
                                                    6,
                                                    6,
                                                    6,
                                                    6,
                                                    6,
                                                    6,
                                                    6,
                                                    6,
                                                    6,
                                                    6,
                                                    6,
                                                    6,
                                                    6,
                                                    6,
                                                    6,
                                                    6,
                                                    6,
                                                    6,
                                                    6,
                                                    6,
                                                    6,
                                                    0,
                                                    0,
                                                    0x15,
                                                    0x16,
                                                    0x15,
                                                    0,
                                                    0};

const GXRenderModeObj gRMO_Pal50_640x456IntDf_16x9 = {VI_TVMODE_PAL_INT,
                                                      0x280,
                                                      0x1c8,
                                                      0x21e,
                                                      0x13,
                                                      0x10,
                                                      0x2aa,
                                                      0x21e,
                                                      VI_XFBMODE_DF,
                                                      0,
                                                      0,
                                                      6,
                                                      6,
                                                      6,
                                                      6,
                                                      6,
                                                      6,
                                                      6,
                                                      6,
                                                      6,
                                                      6,
                                                      6,
                                                      6,
                                                      6,
                                                      6,
                                                      6,
                                                      6,
                                                      6,
                                                      6,
                                                      6,
                                                      6,
                                                      6,
                                                      6,
                                                      6,
                                                      6,
                                                      7,
                                                      7,
                                                      0xC,
                                                      0xC,
                                                      0xC,
                                                      7,
                                                      7};

const GXRenderModeObj gRMO_Pal60_640x456IntDf_16x9 = {VI_TVMODE_EURGB60_INT,
                                                      0x280,
                                                      0x1c8,
                                                      0x1c8,
                                                      0x11,
                                                      0xc,
                                                      0x2ae,
                                                      0x1c8,
                                                      VI_XFBMODE_DF,
                                                      0,
                                                      0,
                                                      6,
                                                      6,
                                                      6,
                                                      6,
                                                      6,
                                                      6,
                                                      6,
                                                      6,
                                                      6,
                                                      6,
                                                      6,
                                                      6,
                                                      6,
                                                      6,
                                                      6,
                                                      6,
                                                      6,
                                                      6,
                                                      6,
                                                      6,
                                                      6,
                                                      6,
                                                      6,
                                                      6,
                                                      7,
                                                      7,
                                                      0xC,
                                                      0xC,
                                                      0xC,
                                                      7,
                                                      7};
const GXRenderModeObj gRMO_Pal60_640x456Prog_16x9 = {VI_TVMODE_EURGB60_PROG,
                                                     0x280,
                                                     0x1c8,
                                                     0x1c8,
                                                     0x11,
                                                     0xc,
                                                     0x2ae,
                                                     0x1c8,
                                                     VI_XFBMODE_SF,
                                                     0,
                                                     0,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     6,
                                                     0,
                                                     0,
                                                     0x15,
                                                     0x16,
                                                     0x15,
                                                     0,
                                                     0};

const GXRenderModeObj* const StandardRenderModesTable[] = {
    &gRMO_Ntsc_640x456IntDf_4x3,   &gRMO_Ntsc_640x456Prog_4x3,
    &gRMO_Pal50_640x456IntDf_4x3,  &gRMO_Pal60_640x456IntDf_4x3,
    &gRMO_Pal60_640x456Prog_4x3,

    &gRMO_Ntsc_640x456IntDf_16x9,  &gRMO_Ntsc_640x456Prog_16x9,
    &gRMO_Pal50_640x456IntDf_16x9, &gRMO_Pal60_640x456IntDf_16x9,
    &gRMO_Pal60_640x456Prog_16x9};

} // namespace

const GXRenderModeObj*
Video::initialize(const GXRenderModeObj* renderMode,
                  const GXRenderModeObj* const* renderModesTable) {
  VIInit();

  return configure((GXRenderModeObj*)renderMode,
                   (GXRenderModeObj**)renderModesTable);
}

GXRenderModeObj* Video::configure(GXRenderModeObj* renderMode,
                                  GXRenderModeObj** renderModesTable) {
  GXRenderModeObj* rm = (GXRenderModeObj*)pRenderMode; // r30

  if (!renderModesTable)
    renderModesTable = (GXRenderModeObj**)StandardRenderModesTable;
  if (!renderMode)
    renderMode = (GXRenderModeObj*)getStandardRenderModeObj(renderModesTable);

  if (pRenderMode != renderMode) {
    pRenderMode = renderMode;

    VISetBlack(true);
    VIConfigure(renderMode);
    VIFlush();

    _08 = OSGetTick();
    mFlag |= VIDEO_FLAG_IS_NOT_BLACKED_OUT;

    u16 fbWidth = renderMode->fb_width;
    u16 efbHeight = renderMode->efb_height;

    const float yScaleFactor =
        GXGetYScaleFactor(efbHeight, renderMode->xfb_height);
    const u16 numXfbLines = GXGetNumXfbLines(efbHeight, yScaleFactor);

    GXSetDispCopySrc(0, 0, fbWidth, efbHeight);
    GXSetDispCopyDst(fbWidth, numXfbLines);
    GXSetDispCopyYScale(yScaleFactor);

    VIWaitForRetrace();
    VIWaitForRetrace();
  }

  return rm;
}

// Extracted into own function to force .sdata2 float ordering
static f32 FrameRateToTickPerVRetrace(f32 fps) { return OS_TIMER_CLOCK / fps; }

u32 Video::getTickPerVRetrace(u32 tvFormat) {
  f32 frame_rate; // f2 [VIGetTvFormat() - 1 > 1 ? ... : ...]
  switch (tvFormat) {
  case VI_PAL:
  case VI_MPAL:
    frame_rate = 50.0f;
    break;
  default:
    frame_rate = 59.94f;
    break;
  }

  return FrameRateToTickPerVRetrace(frame_rate);
}

u32 Video::getTickPerVRetrace() {
  return getTickPerVRetrace(VIGetTvFormat()); // inline
}

const GXRenderModeObj* Video::getStandardRenderModeObj(
    const GXRenderModeObj* const* renderModesTable) {
  // Query the system configuration
  bool bProgressive = (u32)SCGetProgressiveMode() == 1u;      // r31
  bool bEuRGB60 = (u32)SCGetEuRgb60Mode() == 1u;              // r30
  bool b4x3 = (u32)SCGetAspectRatio() == SC_ASPECT_RATIO_4x3; // r29
  bool bDigitalAVConnected =
      VIGetDTVStatus() == 1; // r28 is digital av (progressive) cable connected?

  bool bLivesInGoodCountry; // r0
  switch (VIGetTvFormat()) {
  // North America / Japan
  case VI_NTSC:
    bLivesInGoodCountry = true;
    break;
  // Europe
  case VI_PAL:
  case VI_EURGB60:
    bLivesInGoodCountry = false;
    break;
  default:
    bLivesInGoodCountry = true;
    break;
  }
  // progresive
  if (bDigitalAVConnected && bProgressive) {
    // North America / Japan
    if (bLivesInGoodCountry)
      return b4x3 ? renderModesTable[RM_NTSC_4x3_PROGRESSIVE]
                  : renderModesTable[RM_NTSC_16x9_PROGRESSIVE];
    // Europe
    else
      return b4x3 ? renderModesTable[RM_PAL_4x3_PROGRESSIVE]
                  : renderModesTable[RM_PAL_16x9_PROGRESSIVE];
  }
  // non-progressive
  else {
    // North America / Japan
    if (bLivesInGoodCountry)
      return b4x3 ? renderModesTable[RM_NTSC_4x3]
                  : renderModesTable[RM_NTSC_16x9];
    // Europe
    else {
      if (bEuRGB60)
        return b4x3 ? renderModesTable[RM_EURGB60_4x3]
                    : renderModesTable[RM_EURGB60_16x9];
      // PAL50
      else
        return b4x3 ? renderModesTable[RM_PAL50_4x3]
                    : renderModesTable[RM_PAL50_16x9];
    }
  }
}

} // namespace EGG

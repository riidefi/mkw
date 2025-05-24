/*!
 * @file
 * @brief
 */
#pragma once

#include <rk_types.h>

struct GXRenderModeObj;

namespace EGG {

class Video {
public:
  enum RenderModeTable {
    // NTSC narrow
    RM_NTSC_4x3, //!< [0] North America / Japan: narrow, non-progressive
                 //!< display.
    RM_NTSC_4x3_PROGRESSIVE, //!< [1] North America / Japan: narrow, progressive
                             //!< display.
                             // PAL narrow
    RM_PAL50_4x3,            //!< [2] Europe: narrow, non-progressive display
    RM_EURGB60_4x3,          //!< [3] Europe: EuRGB60 narrow display.
    RM_PAL_4x3_PROGRESSIVE,  //!< [4] Europe: narrow, progressive display.
                             // NTSC wide
    RM_NTSC_16x9, //!< [5] North America / Japan: wide, non-progressive display.
    RM_NTSC_16x9_PROGRESSIVE, //!< [6] North America / Japan: wide, progressive
                              //!< display.
                              // PAL wide
    RM_PAL50_16x9,            //!< [7] Europe: wide, non-progressive display.
    RM_EURGB60_16x9,          //!< [8] Europe: RGB60 wide display.
    RM_PAL_16x9_PROGRESSIVE   //!< [9] Europe: wide, progressive display.
  };

  // calls VIInit() and then calls down to configure
  const GXRenderModeObj*
  initialize(const GXRenderModeObj* renderMode,
             const GXRenderModeObj* const* renderModesTable);
  // configure video (VI/GX)
  GXRenderModeObj* configure(GXRenderModeObj* renderMode,
                             GXRenderModeObj** renderModesTable);
  static u32 getTickPerVRetrace(u32 tvMode);
  static u32 getTickPerVRetrace();
  static const GXRenderModeObj*
  getStandardRenderModeObj(const GXRenderModeObj* const* renderModesTable);

  inline Video(const GXRenderModeObj* rm, const GXRenderModeObj* const* rmTable)
      : pRenderMode(nullptr), mFlag(0), _08(0) {
    initialize(rm, rmTable);
  }

  GXRenderModeObj const* getRenderModeObj() {
    return pRenderMode;
  }

  bool isBlack() {
    return mFlag & 1;
  }

private:
  enum Flag { VIDEO_FLAG_IS_NOT_BLACKED_OUT = 1 };
  GXRenderModeObj const* pRenderMode;
  u8 mFlag;
  u32 _08;
};

} // namespace EGG

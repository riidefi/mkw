#pragma once

#include <rk_types.h>

namespace Field {

enum StartPosition { STAGE_START_POS_DEFAULT, STAGE_START_POS_SHORT };

struct MapdataStage {
  u8 mLapCount;      //!< [+0x00] Unused
  u8 mCorner;        //!< [+0x01] Pole is left / right
  u8 mStartPosition; //!< [+0x02] 1 close start position
  u8 mFlareTobi;     //!< [+0x03] I haven't gotten around to RE'ing this. Though
                 //!< Tobi (course.0) is japanese for "Jump" which definitely
                 //!< matches this
  struct lensFlareOptions_t {
    u8 a, r, g, b;     //!< [+0x05] Color of the flare
  } mLensFlareOptions; //!< [+0x04-0x08] Loading this is sometimes optimized to
                       //!< a 32 bit load
                       // --- Pre Revision 2320: End of Structure
  //! @addtogroup KMP2320 KMP revision 2320 additions.
  //! @{
  u8 mUnk08;          //!< [+0x08] Unknown
  u8 _;               //!< [+0x09] implicit pad
  u16 mSpeedModifier; //!< [+0x0A] Used by the speed modifier cheat code as the
                      //!< two most significant bytes of a f32. (Originally
                      //!< implicit pad)
                      //! @}
};

} // namespace Field

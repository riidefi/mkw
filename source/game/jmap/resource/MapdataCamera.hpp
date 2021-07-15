#pragma once

#include <egg/math/eggVector.hpp>
#include <rk_types.h>

namespace Field {

struct MapdataCamera {
  // TODO: I have this documented in RiiStudio.
  u8 cameraType;

  u8 cameraNext;
  u8 cameraShake;
  u8 pathID;

  u16 pathSpeed; //!< wiki - Velocity of the camera point in units per 100/60
                 //!< sec (=distance/1.67 sec)
  u16 fovYSpeed; //!< wiki - 	Velocity of zooming in units per 100/60 sec
                 //!< (=units/1.67 sec) (tested with camera type 5)
  /// <summary>
  /// wiki - Velocity of the view point in distance per 100/60 sec
  /// (=distance/1.67 sec) (tested with camera type 5). course.0 - atSpd
  /// </summary>
  u16 viewSpeed;
  u8 StartFlag; //!< Unknown
  u8 MovieFlag; //!< Unknown -- I conjecture this has to do with their setup for
                //!< the intro cameras on the start that are recorded

  EGG::Vector3f position, rotation;

  f32 fovYStart; //!< course.0 - fovy, wiki - Zoom start: The angle of view
                 //!< (field of view). Angles >180 create curious effects.
  f32 fovVYEnd;  //!< course.0 - fovy2, wiki - Zoom end. The camera changes the
                 //!< zoom to this value. Offset 0x06 (Velocity) controls the
                 //!< speed of zooming.

  EGG::Vector3f viewStart; //!< wiki - , course.0 - at_[x|y|z]
  EGG::Vector3f viewEnd;   //!< wiki -, course.0 - at2_[x|y|z]

  float time; //!< course.0 - CamTime (Int), wiki - 	The time how long this
              //!< Camera is active. (in units of 1/60 seconds).
};

} // namespace Field

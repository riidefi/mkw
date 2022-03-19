#pragma once

#include <egg/math/eggVector.hpp>
#include <rk_types.h>

namespace Field {

enum eMapdataAreaShape {
  AREA_SHAPE_BOX, //!< [0] Rectangular prism area.
  AREA_SHAPE_CYL, //!< [1] Cylinder area.
  AREA_SHAPE_NUM
};

enum eMapdataAreaType {
  AREA_TYPE_CAM, //!< [0] course.0 - "Camera"

  // ObjClip, // Moved below since course.0 version

  AREA_TYPE_EF_CONTROL,   //!< [1] course.0 - "EfControl"
  AREA_TYPE_FOG_CONTROL,  //!< [2] course.0 - "FogControl"
  AREA_TYPE_PULL_CONTROL, //!< [3] course.0 - "PullControl"

  AREA_TYPE_ENEMY_FALL, //!< [4] course.0 - "EnemyFall"

  AREA_TYPE_2D_MAP_AREA, //!< [5] course.0 - "2DmapArea"

  // Below not in couse.0
  AREA_TYPE_SOUND_CONTROL,
  AREA_TYPE_B_TERESA_CONTROL,

  AREA_TYPE_OBJCLIP_CLASSIFY,
  AREA_TYPE_OBJCLIP_DISCRIMINATE,

  AREA_TYPE_RESPAWN
};

class MapdataArea {
public:
  //! @brief [+0x00] The shape of the 3d area volume (box/cylinder).
  //! eMapdataAreaShape
  //! @see MapdataAreaCalcBox, MapdataAreaCalcCylinder
  //!
  u8 shape;

  //! @brief [+0x01] The type of the area. eMapdataAreaType
  //!
  u8 type;

  //! @brief [+0x02] Index of linked camera when type is Camera. -1 when unused.
  //!
  s8 cameraIdx;

  //! @brief [+0x03] A higher number means a higher priority to choose which
  //! area activates if multiple areas intersected.
  //!
  u8 priority;

  EGG::Vector3f position; //!< [+0x04] Translation of the AREA.
  EGG::Vector3f rotation; //!< [+0x10] Rotation of the AREA.
  EGG::Vector3f scaling;  //!< [+0x1C] Scale of the AREA.

  //! @brief wiki - Used by AREA types: 2, 3, 8 and 9.
  //! @remarks Hypotheses: FogControl -- fog index in area
  //!
  u16 Parameter1;

  //! @brief wiki - Used by AREA type 3
  //! @remarks Hypothesis: fog index to use when exiting area
  //!
  u16 Parameter2;

  // Pre Revision 2200: End of structure

  //! @brief [+0x2C] Used by AREA type 3.
  //! @since version 2200
  //! @see AreaAccessor::GetPathAccessorFromRailID
  //!
  u8 railID;

  //! @brief [+0x2D] Used by AREA type 4.
  //! @since version 2200
  //!
  u8 eneLinkID;

  u8 _[2]; //! @brief [+0x2E] 2 bytes of implicit padding?

public:
  // This would require u8->u32 cast, is this right?
  inline eMapdataAreaShape getShape() {
    // TODO: potential asserts
    // DebugAssert(shape < AREA_SHAPE_NUM);
    return static_cast<eMapdataAreaShape>(shape);
  }
  inline eMapdataAreaType getType() {
    // TODO: potential asserts
    // DebugAssert(shape < AREA_TYPE_NUM);
    return static_cast<eMapdataAreaType>(type);
  }
};

} // namespace Field

/*!
 * @file
 * @brief Manages the objects and related tables!
 */

#include <Relocatable/Object/ObjectDirector.hpp>

namespace Field {

ObjectDirector::ObjectDirector() {
  // Store first virtual table at +0x00.
  // Then, store another at 0x134
  mpObjectParameter = new ObjectParameter("ObjFlow.bin"); // sizeof=16

  mpGeoHitTableItemManager =
      new GeoHitTableItemManager("GeoHitTableItem.bin"); // INLINE (depth 1)

  mpGeoHitTableItemObjManager = new GeoHitTableItemObjManager(
      "GeoHitTableItemObj.bin"); // INLINE (depth 1)

  mpGeoHitTableKartManager =
      new GeoHitTableKartManager("GeoHitTableKart.bin"); // INLINE (depth 1)

  mpGeoHitTableKartObjManager = new GeoHitTableKartObjManager(
      "GeoHitTableKartObj.bin"); // INLINE (depth 1)

  // TODO
  _54 = (spRaceData->_B70 >> 31) + (6 < spRaceData->field_B70);

  _55 = spRaceData->_B70 == 2 || spRaceData->_B70 == 5;

  u32 slot = spRaceData->_B68; // r0

  // TODO: expanded switch?
  if (slot >= RK_SLOT_SENIOR_COURSE && slot <= RK_SLOT_RIDGEHIGHWAY_COURSE ||
      slot == RK_SLOT_RING_MISSION || slot == 0x33 ||
      slot == RK_SLOT_OLD_DESERT_DS || slot == RK_SLOT_OLD_HEYHO_GBA) {
    _58 = new unk(); // sizeof=244 INLINE
    {                // inline ctor of unk class
      _58->_F0 = 0;
    }
  } else {
    _58 = NULL;
  }

  _1C = (unk*)new u8[800];
  _24 = (unk*)new u8[800];
  _2C = (unk*)new u8[800];
  _3C = (unk*)new u8[800];
  _34 = (unk*)new u8[800];
  _40 = (unk*)new u8[800];
  _44 = new EGG::Vector3f[200]; // sizeof=2416
  _48 = (unk*)new u8[800];

  // nasty runtime casts
  _124 = 0;
  _128 = 45;
  _12C = 90;
  _130 = 135;
}
// ...
} // namespace Field

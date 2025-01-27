/*!
 * @file
 * @brief Manages the objects and related tables!
 */

#pragma once

#include <geo/ObjectParameter.hpp>

#include <rk_types.h>

#include <egg/math/eggVector.hpp>

namespace Field {

class BaseGeoHitTableManager {};
class GeoHitTableItemManager : public BaseGeoHitTableManager { // sizeof=
};
class GeoHitTableItemObjManager {};
struct ObjectBase;
class ObjectDirector {
public:
  static ObjectDirector* sInstance;
  static ObjectDirector* getStaticInstance() { return sInstance; }
  ObjectDirector();
  // +0x134 vdt
  // +0x00 vdt (below)
  virtual ~ObjectDirector();
  // private:
  ObjectParameter* mpObjectParameter; //!< [+0x04]

  GeoHitTableItemManager* mpGeoHitTableItemManager;       //!< [+0x08]
  GeoHitTableItemObjManager* mpGeoHitTableItemObjManager; //!< [+0x0C]

  GeoHitTableItemManager* mpGeoHitTableKartManager;       //!< [+0x10]
  GeoHitTableItemObjManager* mpGeoHitTableKartObjManager; //!< [+0x14]

  // ...
  u16 mNumObjectsA;         // 0x20
  ObjectBase** mppObjectsA; // 0x24
  //..
  u16 mNumObjectsB;         // 0x30 short count
  ObjectBase** mppObjectsB; // 0x34 ObjArray

  unk8 _54;
  bool _55;
  // .. or pad
  unk* _58;

  //...

  unk* _1C; // buf sizeof=800
  // ...
  unk* _24; // buf sizeof=800
  // ...
  unk* _2C; // buf sizeof=800
  // ...
  unk* _34; // buf sizeof=800
  // ...
  unk* _3C; // buf sizeof=800
  unk* _40; // buf sizeof=800
  EGG::Vector3f* _44;
  unk* _48; // buf sizeof=800
  // ...
  f32 _124;
  f32 _128;
  f32 _12C;
  f32 _130;
};

} // namespace Field

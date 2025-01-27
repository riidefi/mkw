/*!
 * @file
 * @brief Manages the object flow (parameters)!
 */

#pragma once

#include <rk_types.h>

namespace Field {

typedef u32 eMapdataGeoObjID;

class ObjectParameter {
public:
  //! @brief sizeof=0x74
  //!
  struct Parameter {
    s16 ID; // 00
    struct Data {
      char Name[32];          // 02
      char AssetsListing[64]; // 22
      // Likely: s16[8] UserData;
      // Unk
      u16 P0;       // 62
      s16 ClipBias; // 64
      s16 ClipNear; // 66
      s16 ClipFar;  // 68
      // P4: Assumption: If not null, the object is solid.
      s16 P4; // 6a
      // P5: Assumption: Solitity parameter, only used if P4 ≥ 1
      s16 P5; // 6c
      // P6: Assumption: Solitity parameter, only used if P4 ≥ 2
      s16 P6; // 6e
      // P7: Assumption: Solitity parameter, only used if P4 ≥ 3
      s16 P7; // 70
      // An unknown attribute.
      // For nearly all object the value is null, only for itembox (0x65) and
      // sanbo (0x199) it is 1. The attribute of the very first element is the
      // total number of elements.
      s16 Attribute; // 72
    } data;
  };

  //! @brief Header of the object parameter resource file. (`ObjFlow.bin`)
  //!
  struct Header {
    short nEntry;        //!< [+0x00] Number of entries in this file.
    Parameter entries[]; //!< [+0x
  };

  ObjectParameter(const char* path);
  virtual ~ObjectParameter() {
  } // linked at end of ObjectParameter.o (as virtual)
  eMapdataGeoObjID getObjectIdByName(const char* key);

  // private:
  s16 mNumEntries;            //!< [+0x04]
  const Parameter* mpEntries; //!< [+0x08]
  const s16* mpRemapTable;    //!< [+0x0c] After all entries.

  inline const Parameter* getParameter(eMapdataGeoObjID id) {
    return &mpEntries[mpRemapTable[id]];
  }
};

} // namespace Field

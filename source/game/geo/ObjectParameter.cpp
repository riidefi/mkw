/*!
 * @file
 * @brief Manages the objects and related tables!
 */

#include <Relocatable/Object/ObjectParameter.hpp>
#include <Relocatable/Resource/ResourceManager.hpp>
#include <string.h>

namespace Field {

ObjectParameter::ObjectParameter(const char* path) {
  const Header* bin =
      reinterpret_cast<const Header*>(Resource::Manager::spInstance->getFile(
          Resource::RES_CHAN_RACE_SYS, path, nullptr));

  mNumEntries = bin->nEntry;
  mpEntries = bin->entries;
  mpRemapTable = reinterpret_cast<const s16*>(&mpEntries[mNumEntries]);
}

eMapdataGeoObjID ObjectParameter::getObjectIdByName(const char* key) {
  for (int i = 0; i < mNumEntries; ++i)
    if (!strcmp(key, mpEntries[i].data.Name))
      return static_cast<eMapdataGeoObjID>(mpEntries[i].ID);

  return 0;
}
} // namespace Field

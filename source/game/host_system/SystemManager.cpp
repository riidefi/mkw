/*!
 * @file
 * @brief System Manager implementations.
 */

#include <EGG/util/eggException.hpp>
#include <Static/System/SystemManager.hpp>

namespace System {

static const char* sRegionCode = "RMCP";
static const char* MAIN_SMAP = "/rel/RevoKartR.SMAP";

SystemManager* SystemManager::sInstance;

SystemManager* SystemManager::initStaticInstance(EGG::Heap* heap) {
  return (sInstance = new SystemManager(heap));
}
SystemManager::~SystemManager() { delete[] this->buf_88; }

void SystemManager::LoadSymbols(OSModuleInfo* pModuleInfo) {
  pModuleInfo = pModuleInfo != nullptr ? pModuleInfo : this->_B0; // r5

  if (pModuleInfo == nullptr)
    return;

  if (MAIN_SMAP != nullptr) // "/rel/RevoKartR.SMAP"
  {
    u32 map_size;
    mpMap = SystemManager::sInstance->ripFromDisc(MAIN_SMAP, pModuleInfo, 0,
                                                  &map_size, 0);
    if (mpMap != nullptr) {
      EGG::Exception::setMapFile(mpMap, map_size, pModuleInfo);
      OSReport("[SYS] Load MapFile \"%s\" success.\n", MAIN_SMAP);
    } else {
      OSReport("[SYS] Load MapFile \"%s\" fail.\n", MAIN_SMAP);
    }
  }

  buf_88->_0 = 0;
  buf_8C->_0 = 0;
  buf_90->_0 = 0;
}

} // namespace System

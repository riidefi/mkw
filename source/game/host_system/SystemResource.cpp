#include "SystemResources.hpp"

namespace System {
namespace Resource {

struct SystemResourceEntry {
  const char* path;
  u32 id;
};

const SystemResourceEntry sSystemResources[] = {
    {"/contents/RFLRes01.arc", 4},
    {"/contents/HomeButton.arc", 5},
    {"/contents/HomeButtonSe.arc", 6},
    {"/contents/globe.arc", 7},
    // Channel only
    {"/RKChRes.arc", 8}};

const char* GetResourcePath(eSystemResource idx) {
  return sSystemResources[idx].path;
}

u32 GetResourceID(eSystemResource idx) { return sSystemResources[idx].id; }

} // namespace Resource
} // namespace System

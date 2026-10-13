#include "SystemResources.hpp"

extern "C" const char lbl_80245010[0x18] = "/contents/RFLRes01.arc";
extern "C" const char lbl_80245028[0x1C] = "/contents/HomeButton.arc";
extern "C" const char lbl_80245044[0x1C] = "/contents/HomeButtonSe.arc";
extern "C" const char lbl_80245060[0x14] = "/contents/globe.arc";
extern "C" const char lbl_80245074[0x14] = "/RKChRes.arc";

namespace System {
namespace Resource {

struct SystemResourceEntry {
  const char* path;
  u32 id;
};

const SystemResourceEntry sSystemResources[] = {
    {lbl_80245010, 4},
    {lbl_80245028, 5},
    {lbl_80245044, 6},
    {lbl_80245060, 7},
    // Channel only
    {lbl_80245074, 8}};

const char* GetResourcePath(eSystemResource idx) {
  return sSystemResources[idx].path;
}

u32 GetResourceID(eSystemResource idx) { return sSystemResources[idx].id; }

} // namespace Resource
} // namespace System

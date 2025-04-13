#include "spb.h"

#include <rvl/os/osCache.h>

u32 __AXSpbAux3;
u32 __AXSpbAux2;
u32 __AXSpbAux1;
u32 __AXSpbAux0;
u32 __AXSpbMain3;
u32 __AXSpbMain2;
u32 __AXSpbMain1;
u32 __AXSpbMain0;
u32 __AXSpbACS;
u32 __AXSpbACR;
u32 __AXSpbACL;
u32 __AXSpbABS;
u32 __AXSpbABR;
u32 __AXSpbABL;
u32 __AXSpbAAS;
u32 __AXSpbAAR;
u32 __AXSpbAAL;
u32 __AXSpbAS;
u32 __AXSpbAR;
u32 __AXSpbAL;

AXSPB __AXStudio;

AXSPB* __AXGetStudio() { return &__AXStudio; }

void __AXSPBInit() {
  __AXSpbAL = 0;
  __AXSpbAR = 0;
  __AXSpbAS = 0;
  __AXSpbAAL = 0;
  __AXSpbAAR = 0;
  __AXSpbAAS = 0;
  __AXSpbABL = 0;
  __AXSpbABR = 0;
  __AXSpbABS = 0;
  __AXSpbACL = 0;
  __AXSpbACR = 0;
  __AXSpbACS = 0;
  __AXSpbMain0 = 0;
  __AXSpbMain1 = 0;
  __AXSpbMain2 = 0;
  __AXSpbMain3 = 0;
  __AXSpbAux0 = 0;
  __AXSpbAux1 = 0;
  __AXSpbAux2 = 0;
  __AXSpbAux3 = 0;
}

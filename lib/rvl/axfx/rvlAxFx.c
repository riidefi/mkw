#include "axfx.h"

#include <rvl/os/osAlloc.h>

AXFXAlloc __AXFXAlloc = __AXFXAllocFunction;
AXFXFree __AXFXFree = __AXFXFreeFunction;

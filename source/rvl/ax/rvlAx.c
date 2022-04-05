#include "ax.h"

#include <rvl/os/os.h>

#include "alloc.h"
#include "axAux.h"
#include "cl.h"
#include "out.h"
#include "spb.h"
#include "vpb.h"

char _unk_8027e778[] =
    "<< RVL_SDK - AX \trelease build: Aug  8 2007 01:58:18 (0x4199_60831) >>";
char* _unk_803857f8 = _unk_8027e778;
u32 _unk_80386488;

// Symbol: AXInit
// PAL: 0x80124e80..0x80124ed4
MARK_BINARY_BLOB(AXInit, 0x80124e80, 0x80124ed4);
asm UNKNOWN_FUNCTION(AXInit) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  lwz r0, _unk_80386488;
  cmpwi r0, 0;
  bne lbl_80124ec4;
  lwz r3, _unk_803857f8;
  bl OSRegisterVersion;
  bl __AXAllocInit;
  bl __AXVPBInit;
  bl __AXSPBInit;
  bl __AXAuxInit;
  bl __AXClInit;
  li r3, 0;
  bl __AXOutInit;
  li r0, 1;
  stw r0, _unk_80386488;
lbl_80124ec4:
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: AXIsInit
// PAL: 0x80124ed4..0x80124edc
u32 AXIsInit() { return _unk_80386488; }

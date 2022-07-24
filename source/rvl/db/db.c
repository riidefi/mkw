#include "db.h"

#include <rvl/base/ppcArch.h>
#include <rvl/os/osContext.h>
#include <rvl/os/osError.h>

static u32 unk_80386600;

// Symbol: DBInit
// PAL: 0x8015d314..0x8015d33c
MARK_BINARY_BLOB(DBInit, 0x8015d314, 0x8015d33c);
asm UNKNOWN_FUNCTION(DBInit) {
  // clang-format off
  nofralloc;
  lis r4, 0x8000;
  lis r3, 0x8016;
  addi r5, r4, 0x40;
  li r0, 1;
  addi r3, r3, -11388;
  stw r5, unk_80386600;
  addis r3, r3, 0x8000;
  stw r3, 0x48(r4);
  stw r0, -0x65fc(r13);
  blr;
  // clang-format on
}

// Symbol: __DBExceptionDestinationAux
// PAL: 0x8015d33c..0x8015d384
MARK_BINARY_BLOB(__DBExceptionDestinationAux, 0x8015d33c, 0x8015d384);
asm UNKNOWN_FUNCTION(__DBExceptionDestinationAux) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  lis r3, 0x8029;
  stw r0, 0x14(r1);
  addi r3, r3, -32696;
  stw r31, 0xc(r1);
  lwz r4, 0xc0(0);
  addis r31, r4, 0x8000;
  crclr 6;
  bl OSReport;
  mr r3, r31;
  bl OSDumpContext;
  bl PPCHalt;
  lwz r0, 0x14(r1);
  lwz r31, 0xc(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: __DBExceptionDestination
// PAL: 0x8015d384..0x8015d394
MARK_BINARY_BLOB(__DBExceptionDestination, 0x8015d384, 0x8015d394);
asm UNKNOWN_FUNCTION(__DBExceptionDestination) {
  // clang-format off
  nofralloc;
  mfmsr r3;
  ori r3, r3, 0x30;
  mtmsr r3;
  b __DBExceptionDestinationAux;
  // clang-format on
}

// Symbol: __DBIsExceptionMarked
// PAL: 0x8015d394..0x8015d3ac
MARK_BINARY_BLOB(__DBIsExceptionMarked, 0x8015d394, 0x8015d3ac);
asm UNKNOWN_FUNCTION(__DBIsExceptionMarked) {
  // clang-format off
  nofralloc;
  lwz r4, unk_80386600;
  li r0, 1;
  slw r0, r0, r3;
  lwz r3, 4(r4);
  and r3, r3, r0;
  blr;
  // clang-format on
}

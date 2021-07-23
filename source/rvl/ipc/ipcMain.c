#include "ipcMain.h"

// Extern function references.
// PAL: 0x801ab648
extern UNKNOWN_FUNCTION(unk_801ab648);
// PAL: 0x801ab650
extern UNKNOWN_FUNCTION(unk_801ab650);

// Symbol: IPCInit
// PAL: 0x80192f7c..0x80192fc8
MARK_BINARY_BLOB(IPCInit, 0x80192f7c, 0x80192fc8);
asm void IPCInit(void) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  lbz r0, -0x6418(r13);
  cmpwi r0, 0;
  bne lbl_80192fb8;
  bl unk_801ab648;
  stw r3, -0x6408(r13);
  bl unk_801ab650;
  lwz r4, -0x6408(r13);
  li r0, 1;
  stw r3, -0x640c(r13);
  stw r4, -0x6410(r13);
  stw r3, -0x6414(r13);
  stb r0, -0x6418(r13);
lbl_80192fb8:
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: IPCReInit
// PAL: 0x80192fc8..0x80193010
MARK_BINARY_BLOB(IPCReInit, 0x80192fc8, 0x80193010);
asm void IPCReInit(void) {
  // clang-format off
  nofralloc;
  stwu r1, -0x10(r1);
  mflr r0;
  stw r0, 0x14(r1);
  li r0, 0;
  stb r0, -0x6418(r13);
  bl unk_801ab648;
  stw r3, -0x6408(r13);
  bl unk_801ab650;
  lwz r4, -0x6408(r13);
  li r0, 1;
  stw r3, -0x640c(r13);
  stw r4, -0x6410(r13);
  stw r3, -0x6414(r13);
  stb r0, -0x6418(r13);
  lwz r0, 0x14(r1);
  mtlr r0;
  addi r1, r1, 0x10;
  blr;
  // clang-format on
}

// Symbol: IPCReadReg
// PAL: 0x80193010..0x80193020
MARK_BINARY_BLOB(IPCReadReg, 0x80193010, 0x80193020);
asm u32 IPCReadReg(u32) {
  // clang-format off
  nofralloc;
  slwi r0, r3, 2;
  lis r3, 0xcd00;
  lwzx r3, r3, r0;
  blr;
  // clang-format on
}

// Symbol: IPCWriteReg
// PAL: 0x80193020..0x80193030
MARK_BINARY_BLOB(IPCWriteReg, 0x80193020, 0x80193030);
asm void IPCWriteReg(u32, u32) {
  // clang-format off
  nofralloc;
  slwi r0, r3, 2;
  lis r3, 0xcd00;
  stwx r4, r3, r0;
  blr;
  // clang-format on
}

// Symbol: IPCGetBufferHi
// PAL: 0x80193030..0x80193038
MARK_BINARY_BLOB(IPCGetBufferHi, 0x80193030, 0x80193038);
asm void* IPCGetBufferHi(void) {
  // clang-format off
  nofralloc;
  lwz r3, -0x6410(r13);
  blr;
  // clang-format on
}

// Symbol: IPCGetBufferLo
// PAL: 0x80193038..0x80193040
MARK_BINARY_BLOB(IPCGetBufferLo, 0x80193038, 0x80193040);
asm void* IPCGetBufferLo(void) {
  // clang-format off
  nofralloc;
  lwz r3, -0x6414(r13);
  blr;
  // clang-format on
}

// Symbol: IPCSetBufferLo
// PAL: 0x80193040..0x80193048
MARK_BINARY_BLOB(IPCSetBufferLo, 0x80193040, 0x80193048);
asm void IPCSetBufferLo(void*) {
  // clang-format off
  nofralloc;
  stw r3, -0x6414(r13);
  blr;
  // clang-format on
}

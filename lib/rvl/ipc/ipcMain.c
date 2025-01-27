#include "ipcMain.h"

#include <hardware.h>

// Extern function references.
// PAL: 0x801ab648
extern void* __OSGetIPCBufferHi(void);
// PAL: 0x801ab650
extern void* __OSGetIPCBufferLo(void);

// Static vars.
static void* IPCAltBufferHi;
static void* IPCAltBufferLo;
static void* IPCBufferHi;
static void* IPCBufferLo;
static u8 IPC_Initialized;

// Symbol: IPCInit
// PAL: 0x80192f7c..0x80192fc8
void IPCInit(void) {
  if (IPC_Initialized)
    return;

  IPCAltBufferHi = __OSGetIPCBufferHi();
  IPCAltBufferLo = __OSGetIPCBufferLo();
  IPCBufferHi = IPCAltBufferHi;
  IPCBufferLo = IPCAltBufferLo;

  IPC_Initialized = 1;
}

// Symbol: IPCReInit
// PAL: 0x80192fc8..0x80193010
void IPCReInit(void) {
  IPC_Initialized = 0;
  IPCAltBufferHi = __OSGetIPCBufferHi();
  IPCAltBufferLo = __OSGetIPCBufferLo();
  IPCBufferHi = IPCAltBufferHi;
  IPCBufferLo = IPCAltBufferLo;
  IPC_Initialized = 1;
}

// Symbol: IPCReadReg
// PAL: 0x80193010..0x80193020
u32 IPCReadReg(u32 reg) { return __ACRRegs[reg]; }

// Symbol: IPCWriteReg
// PAL: 0x80193020..0x80193030
void IPCWriteReg(u32 reg, u32 data) { __ACRRegs[reg] = data; }

// Symbol: IPCGetBufferHi
// PAL: 0x80193030..0x80193038
void* IPCGetBufferHi(void) { return IPCBufferHi; }

// Symbol: IPCGetBufferLo
// PAL: 0x80193038..0x80193040
void* IPCGetBufferLo(void) { return IPCBufferLo; }

// Symbol: IPCSetBufferLo
// PAL: 0x80193040..0x80193048
void IPCSetBufferLo(void* addr) { IPCBufferLo = addr; }

#include "ipcMain.h"

#include <hardware.h>

// Extern function references.
extern void* __OSGetIPCBufferHi(void);
extern void* __OSGetIPCBufferLo(void);

// Static vars.
static void* IPCAltBufferHi;
static void* IPCAltBufferLo;
static void* IPCBufferHi;
static void* IPCBufferLo;
static u8 IPC_Initialized;

// Symbol: IPCInit
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
void IPCReInit(void) {
  IPC_Initialized = 0;
  IPCAltBufferHi = __OSGetIPCBufferHi();
  IPCAltBufferLo = __OSGetIPCBufferLo();
  IPCBufferHi = IPCAltBufferHi;
  IPCBufferLo = IPCAltBufferLo;
  IPC_Initialized = 1;
}

// Symbol: IPCReadReg
u32 IPCReadReg(u32 reg) { return __ACRRegs[reg]; }

// Symbol: IPCWriteReg
void IPCWriteReg(u32 reg, u32 data) { __ACRRegs[reg] = data; }

// Symbol: IPCGetBufferHi
void* IPCGetBufferHi(void) { return IPCBufferHi; }

// Symbol: IPCGetBufferLo
void* IPCGetBufferLo(void) { return IPCBufferLo; }

// Symbol: IPCSetBufferLo
void IPCSetBufferLo(void* addr) { IPCBufferLo = addr; }

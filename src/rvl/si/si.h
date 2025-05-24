#include <rk_types.h>
#include <stdbool.h>

typedef void (*SICallback)(s32, u32, void*);
typedef void (*SITypeAndStatusCallback)(s32, u32);

// PAL: 0x801b254c
bool SIBusy(void);
// PAL: 0x801b2568
bool SIIsChanBusy(s32);
// PAL: 0x801b2cf8;
bool SIUnregisterPollingHandler(void*);
// PAL: 0x801b3050;
u32 SIGetStatus(s32);
// PAL: 0x801b30c8
void SISetCommand(s32, u32);
// PAL: 0x801b30dc;
void SITransferCommands(void);
// PAL: 0x801b3148
u32 SIEnablePolling(u32);
// PAL: 0x801b31d0;
u32 SIDisablePolling(u32);
// PAL: 0x801b33ec;
bool SITransfer(s32, void*, u32, void*, u32, SICallback, s64);
// PAL: 0x801b3ba4;
void SIRefreshSamplingRate(void);
// PAL: 0x801b323c
bool SIGetResponse(s32, void*);
// PAL: 0x801b3808
u32 SIGetType(s32);
// PAL: 0x801b39bc
u32 SIGetTypeAsync(s32, SITypeAndStatusCallback);

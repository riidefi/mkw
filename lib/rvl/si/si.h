#include <rk_types.h>
#include <stdbool.h>

typedef void (*SICallback)(s32, u32, void*);
typedef void (*SITypeAndStatusCallback)(s32, u32);

bool SIBusy(void);
bool SIIsChanBusy(s32);
bool SIUnregisterPollingHandler(void*);
u32 SIGetStatus(s32);
void SISetCommand(s32, u32);
void SITransferCommands(void);
u32 SIEnablePolling(u32);
u32 SIDisablePolling(u32);
bool SITransfer(s32, void*, u32, void*, u32, SICallback, s64);
void SIRefreshSamplingRate(void);
bool SIGetResponse(s32, void*);
u32 SIGetType(s32);
u32 SIGetTypeAsync(s32, SITypeAndStatusCallback);

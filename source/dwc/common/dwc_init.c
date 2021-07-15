#include <DWC/common/dwc_init.h>
// dev
#include <DWC/common/dwc_memfunc.h>
#include <DWC/common/dwci_memfunc.h>
#include <DWC/dwci_debug.h>
#include <GameSpy/common/gsMemory.h>
#include <common/dwc_report.h>

#ifdef __cplusplus
extern "C" {
#endif

static u32 dwci_gamecode;

#ifdef DEBUG
#define DWC_VERSION_STRING                                                     \
  "<< RVL_SDK - DWC \tdebug build: Jul 30 2008 11:48:37 (0x4199_60831) >>"
#else
// MKW version
#define DWC_VERSION_STRING                                                     \
  "<< RVL_SDK - DWC \trelease build: Mar  1 2008 21:50:41 (0x4199_60831) >>"
#endif

// no release equivalent yet
#define DWC_SDK_STRING "2_0_3_SDK3"

#define DWC_PRINT_VERSION()                                                    \
  {                                                                            \
    DWC_Printf(8, "================================\n");                       \
    DWC_Printf(8, "- %s\n", DWC_SDK_STRING);                                   \
    DWC_Printf(8, "--------------------------------\n");                       \
  }

#define DWC_PRINT_DEVSVR()                                                     \
  {                                                                            \
    DWC_Printf(8, "\n");                                                       \
    DWC_Printf(8, "********************************\n");                       \
    DWC_Printf(8, "*YOU ARE USING THE DEBUG SERVER*\n");                       \
    DWC_Printf(8, "********************************\n");                       \
    DWC_Printf(8, "*\n");                                                      \
    DWC_Printf(8, "* Please note that you need to\n");                         \
    DWC_Printf(8, "*   switch it to the RELEASE\n");                           \
    DWC_Printf(8, "*  server with your FINALROM!\n");                          \
    DWC_Printf(8, "*\n");                                                      \
    DWC_Printf(8, "*******************************\n");                        \
    DWC_Printf(8, "\n");                                                       \
  }

#define DWC_PRINT_DEMO()                                                       \
  {                                                                            \
    DWC_Printf(8, "\n");                                                       \
    DWC_Printf(8, "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");                       \
    DWC_Printf(8, "x        IS THIS DEMO?         x\n");                       \
    DWC_Printf(8, "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");                       \
    DWC_Printf(8, "x\n");                                                      \
    DWC_Printf(8, "x You are using the gamecode for\n");                       \
    DWC_Printf(8, "x   demos. It is not allowed\n");                           \
    DWC_Printf(8, "x  using this gamecode except\n");                          \
    DWC_Printf(8, "x     in demos and testing.\n");                            \
    DWC_Printf(8, "x\n");                                                      \
    DWC_Printf(8, "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");                        \
    DWC_Printf(8, "\n");                                                       \
  }

#define DWC_SDKDEV_SERVER_HOSTNAME "sdkdev.gamespy.com"
#define DWC_GAMESTATS_SERVER_HOSTNAME "gamestats.gs.nintendowifi.net"

int DWC_Init(DWC_AuthServer authSvr, const char* gameName, u32 gameCode,
             DWCAllocEx allocator, DWCFreeEx freeer) {

  OSRegisterVersion(DWC_VERSION_STRING);

  DWCiAssert(authSvr != DWC_SVR_PROHIBITED, "dwc_init.c", 135,
             "invalid auth server\n");
  DWCiAssert(gameCode, "dwc_init.c", 138, "invalid gamecode\n");

  DWCi_SetMemFunc(allocator, freeer);

#ifdef DEBUG
  DWC_SetReportLevel(0xffffffff);
  DWCi_MemWatch_init();

  DWC_PRINT_VERSION();

  if (authSvr != 1)
    DWC_PRINT_DEVSVR();

  if (gameCode == 'NTRJ')
    DWC_PRINT_DEMO();

  if (gameName && !strcmp(gameName, "dwctest"))
    DWC_PRINT_DEMO();
#endif

  DWCi_Auth_InitInterface(authSvr);

  dwci_gamecode = gameName;

  gsiMemoryCallbacksSet(&DWCi_GsMalloc, &DWCi_GsFree, &DWCi_GsRealloc,
                        &DWCi_GsMemalign);

  DWCiAssert(strlen(gameName) <= 255, "dwc_init.c", 230,
             "gamename is too long\n");

  strcpy(&gcd_gamename, gameName);

  if (authSvr == 0)
    strcpy(&StatsServerHostname, DWC_SDKDEV_SERVER_HOSTNAME);
  else
    strcpy(&StatsServerHostname, DWC_GAMESTATS_SERVER_HOSTNAME);

  DWCi_Np_SetInitFlag(1);
  DWCi_Np_GetConsoleId();

  return 0;
}
void DWC_Shutdown() {
  gsiMemoryCallbacksSet(&DWCi_GsMalloc, &DWCi_GsFree, &DWCi_GsRealloc,
                        &DWCi_GsMemalign);
  gethostbyname("clear");
  DWCi_CfReset();
  DWCi_MemWatch_finish();
  DWCi_Np_SetInitFlag(0);
}

u32 DWCi_GetGamecode() { return dwci_gamecode; }
#ifdef __cplusplus
}
#endif

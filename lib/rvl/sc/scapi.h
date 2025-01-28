#pragma once

// credit: kiwi

#include <rk_types.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { SC_ASPECT_STD, SC_ASPECT_WIDE } SCAspectRatio;

typedef enum { SC_EURGB_50_HZ, SC_EURGB_60_HZ } SCEuRgb60Mode;

typedef enum {
    SC_LANG_JP,
    SC_LANG_EN,
    SC_LANG_DE,
    SC_LANG_FR,
    SC_LANG_SP,
    SC_LANG_IT,
    SC_LANG_NL,
    SC_LANG_ZH_S,
    SC_LANG_ZH_T,
    SC_LANG_KR,
} SCLanguage;

typedef enum { SC_SND_MONO, SC_SND_STEREO, SC_SND_SURROUND } SCSoundMode;

typedef enum { SC_SENSOR_BAR_BOTTOM, SC_SENSOR_BAR_TOP } SCSensorBarPos;

typedef struct SCIdleModeInfo {
    u8 wc24;      // at 0x0
    u8 slotLight; // at 0x1
} SCIdleModeInfo;

typedef struct SCBtDeviceInfo {
    u8 mac[6];     // at 0x0
    char name[64]; // at 0x6
} SCBtDeviceInfo;

typedef struct SCBtDeviceInfoArray {
    u8 numRegist;              // at 0x0
    SCBtDeviceInfo regist[10]; // at 0x1
    SCBtDeviceInfo active[6];  // at 0x2BD
} SCBtDeviceInfoArray;

u8 SCGetAspectRatio(void);
s8 SCGetDisplayOffsetH(void);
u8 SCGetEuRgb60Mode(void);
void SCGetIdleMode(SCIdleModeInfo* mode);
u8 SCGetLanguage(void);
u8 SCGetProgressiveMode(void);
u8 SCGetScreenSaverMode(void);
u8 SCGetSoundMode(void);
u32 SCGetCounterBias(void);
void SCGetBtDeviceInfoArray(SCBtDeviceInfoArray* info);
void SCSetBtDeviceInfoArray(const SCBtDeviceInfoArray* info);
u32 SCGetBtDpdSensibility(void);
u8 SCGetWpadMotorMode(void);
void SCSetWpadMotorMode(u8 mode);
u8 SCGetWpadSensorBarPosition(void);
u8 SCGetWpadSpeakerVolume(void);
void SCSetWpadSpeakerVolume(u8 vol);

#ifdef __cplusplus
}
#endif

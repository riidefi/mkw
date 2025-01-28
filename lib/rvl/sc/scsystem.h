#pragma once

// credit: kiwi

#include <rk_types.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    SC_STATUS_OK,
    SC_STATUS_BUSY,
    SC_STATUS_FATAL,
    SC_STATUS_PARSE
} SCStatus;

typedef enum {
    // IPL settings
    SC_ITEM_IPL_CB,   // Counter bias
    SC_ITEM_IPL_AR,   // Aspect ratio
    SC_ITEM_IPL_ARN,  // Autorun mode
    SC_ITEM_IPL_CD,   // Config done flag
    SC_ITEM_IPL_CD2,  // Config done flag 2
    SC_ITEM_IPL_DH,   // Display horizontal offset
    SC_ITEM_IPL_E60,  // EuRgb60 mode
    SC_ITEM_IPL_EULA, // EULA
    SC_ITEM_IPL_FRC,  // Free channel app count
    SC_ITEM_IPL_IDL,  // Idle mode
    SC_ITEM_IPL_INC,  // Installed channel app count
    SC_ITEM_IPL_LNG,  // Language
    SC_ITEM_IPL_NIK,  // Owner nickname
    SC_ITEM_IPL_PC,   // Parental controls
    SC_ITEM_IPL_PGS,  // Progressive mode
    SC_ITEM_IPL_SSV,  // Screen saver mode
    SC_ITEM_IPL_SADR, // Simple address
    SC_ITEM_IPL_SND,  // Sound mode
    SC_ITEM_IPL_UPT,  // Update type

    // Network settings
    SC_ITEM_NET_CNF,  // Network config
    SC_ITEM_NET_CTPC, // Network content restrictions
    SC_ITEM_NET_PROF, // Network profile
    SC_ITEM_NET_WCPC, // WC24 parental controls
    SC_ITEM_NET_WCFG, // WC24 flags

    // Development settings
    SC_ITEM_DEV_BTM, // Boot mode
    SC_ITEM_DEV_VIM, // Video mode
    SC_ITEM_DEV_CTC, // Country code
    SC_ITEM_DEV_DSM, // Drive-saving mode

    // Bluetooth settings
    SC_ITEM_BT_DINF, // Bluetooth device info
    SC_ITEM_BT_SENS, // Remote sensitivity
    SC_ITEM_BT_SPKV, // WPAD speaker volume
    SC_ITEM_BT_MOT,  // WPAD motor mode
    SC_ITEM_BT_BAR,  // WPAD sensor bar position

    // Miscellaneous settings
    SC_ITEM_DVD_CNF, // DVD config
    SC_ITEM_WWW_RST, // WWW restriction

    SC_ITEM_MAX
} SCItemID;

typedef void (*SCFlushCallback)(SCStatus status);

void SCInit(void);
u32 SCCheckStatus(void);

BOOL SCFindByteArrayItem(void* dst, u32 len, SCItemID id);
BOOL SCReplaceByteArrayItem(const void* src, u32 len, SCItemID id);

BOOL SCFindU8Item(u8* dst, SCItemID id);
BOOL SCFindS8Item(s8* dst, SCItemID id);
BOOL SCFindU32Item(u32* dst, SCItemID id);

BOOL SCReplaceU8Item(u8 data, SCItemID id);

void SCFlushAsync(SCFlushCallback callback);

#ifdef __cplusplus
}
#endif

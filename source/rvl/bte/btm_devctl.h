#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x8013a06c..0x8013a10c
UNKNOWN_FUNCTION(btm_dev_init);
// PAL: 0x8013a10c..0x8013a1bc
UNKNOWN_FUNCTION(btm_db_reset);
// PAL: 0x8013a1bc..0x8013a258
UNKNOWN_FUNCTION(BTM_DeviceReset);
// PAL: 0x8013a258..0x8013a300
UNKNOWN_FUNCTION(BTM_SendHciReset);
// PAL: 0x8013a300..0x8013a31c
UNKNOWN_FUNCTION(BTM_IsDeviceUp);
// PAL: 0x8013a31c..0x8013a40c
UNKNOWN_FUNCTION(BTM_SetAfhChannels);
// PAL: 0x8013a40c..0x8013a6a4
UNKNOWN_FUNCTION(btm_dev_timeout);
// PAL: 0x8013a6a4..0x8013a868
UNKNOWN_FUNCTION(btm_reset_complete);
// PAL: 0x8013a868..0x8013a930
UNKNOWN_FUNCTION(btm_read_hci_buf_size_complete);
// PAL: 0x8013a930..0x8013a9ec
UNKNOWN_FUNCTION(btm_read_local_version_complete);
// PAL: 0x8013a9ec..0x8013aee8
UNKNOWN_FUNCTION(btm_read_local_features_complete);
// PAL: 0x8013aee8..0x8013afa0
UNKNOWN_FUNCTION(BTM_SetLocalDeviceName);
// PAL: 0x8013afa0..0x8013b02c
UNKNOWN_FUNCTION(btm_read_local_name_complete);
// PAL: 0x8013b02c..0x8013b06c
UNKNOWN_FUNCTION(BTM_ReadLocalDeviceAddr);
// PAL: 0x8013b06c..0x8013b0b4
UNKNOWN_FUNCTION(btm_read_local_addr_complete);
// PAL: 0x8013b0b4..0x8013b100
UNKNOWN_FUNCTION(BTM_ReadLocalVersion);
// PAL: 0x8013b100..0x8013b180
UNKNOWN_FUNCTION(BTM_SetDeviceClass);
// PAL: 0x8013b180..0x8013b190
UNKNOWN_FUNCTION(BTM_ReadDeviceClass);
// PAL: 0x8013b190..0x8013b1a0
UNKNOWN_FUNCTION(BTM_ReadLocalFeatures);
// PAL: 0x8013b1a0..0x8013b1b8
UNKNOWN_FUNCTION(BTM_RegisterForDeviceStatusNotif);
// PAL: 0x8013b1b8..0x8013b2b4
UNKNOWN_FUNCTION(BTM_VendorSpecificCommand);
// PAL: 0x8013b2b4..0x8013b320
UNKNOWN_FUNCTION(btm_vsc_complete);
// PAL: 0x8013b320..0x8013b358
UNKNOWN_FUNCTION(BTM_RegisterForVSEvents);
// PAL: 0x8013b358..0x8013b3f0
UNKNOWN_FUNCTION(btm_vendor_specific_evt);
// PAL: 0x8013b3f0..0x8013b490
UNKNOWN_FUNCTION(BTM_WritePageTimeout);
// PAL: 0x8013b490..0x8013b568
UNKNOWN_FUNCTION(BTM_ReadStoredLinkKey);
// PAL: 0x8013b568..0x8013b638
UNKNOWN_FUNCTION(BTM_WriteStoredLinkKey);
// PAL: 0x8013b638..0x8013b708
UNKNOWN_FUNCTION(BTM_DeleteStoredLinkKey);
// PAL: 0x8013b708..0x8013b784
UNKNOWN_FUNCTION(btm_read_stored_link_key_complete);
// PAL: 0x8013b784..0x8013b7e0
UNKNOWN_FUNCTION(btm_write_stored_link_key_complete);
// PAL: 0x8013b7e0..0x8013b848
UNKNOWN_FUNCTION(btm_delete_stored_link_key_complete);
// PAL: 0x8013b848..0x8013b9d4
UNKNOWN_FUNCTION(btm_return_link_keys_evt);
// PAL: 0x8013b9d4..0x8013b9f4
UNKNOWN_FUNCTION(btm_report_device_status);

#ifdef __cplusplus
}
#endif

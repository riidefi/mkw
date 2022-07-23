#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x8013bb28..0x8013bdac
UNKNOWN_FUNCTION(BTM_SetDiscoverability);
// PAL: 0x8013bdac..0x8013be5c
UNKNOWN_FUNCTION(BTM_SetInquiryScanType);
// PAL: 0x8013be5c..0x8013bf0c
UNKNOWN_FUNCTION(BTM_SetPageScanType);
// PAL: 0x8013bf0c..0x8013bfa4
UNKNOWN_FUNCTION(BTM_SetInquiryMode);
// PAL: 0x8013bfa4..0x8013c12c
UNKNOWN_FUNCTION(BTM_SetConnectability);
// PAL: 0x8013c12c..0x8013c13c
UNKNOWN_FUNCTION(BTM_IsInquiryActive);
// PAL: 0x8013c13c..0x8013c244
UNKNOWN_FUNCTION(BTM_CancelInquiry);
// PAL: 0x8013c244..0x8013c3f8
UNKNOWN_FUNCTION(BTM_StartInquiry);
// PAL: 0x8013c3f8..0x8013c4e0
UNKNOWN_FUNCTION(BTM_ReadRemoteDeviceName);
// PAL: 0x8013c4e0..0x8013c558
UNKNOWN_FUNCTION(BTM_CancelRemoteDeviceName);
// PAL: 0x8013c558..0x8013c618
UNKNOWN_FUNCTION(BTM_InqDbRead);
// PAL: 0x8013c618..0x8013c6d0
UNKNOWN_FUNCTION(BTM_InqDbFirst);
// PAL: 0x8013c6d0..0x8013c80c
UNKNOWN_FUNCTION(BTM_InqDbNext);
// PAL: 0x8013c80c..0x8013c8dc
UNKNOWN_FUNCTION(BTM_ClearInqDb);
// PAL: 0x8013c8dc..0x8013ca74
UNKNOWN_FUNCTION(btm_inq_db_reset);
// PAL: 0x8013ca74..0x8013ca78
UNKNOWN_FUNCTION(btm_inq_db_init);
// PAL: 0x8013ca78..0x8013cb54
UNKNOWN_FUNCTION(btm_inq_find_bdaddr);
// PAL: 0x8013cb54..0x8013cc58
UNKNOWN_FUNCTION(btm_inq_db_new);
// PAL: 0x8013cc58..0x8013cd3c
UNKNOWN_FUNCTION(btm_set_inq_event_filter);
// PAL: 0x8013cd3c..0x8013cf5c
UNKNOWN_FUNCTION(btm_event_filter_complete);
// PAL: 0x8013cf5c..0x8013d1d4
UNKNOWN_FUNCTION(btm_process_inq_results);
// PAL: 0x8013d1d4..0x8013d2d8
UNKNOWN_FUNCTION(btm_process_inq_complete);
// PAL: 0x8013d2d8..0x8013d428
UNKNOWN_FUNCTION(btm_initiate_rem_name);
// PAL: 0x8013d428..0x8013d580
UNKNOWN_FUNCTION(btm_process_remote_name);
// PAL: 0x8013d580..0x8013d5c0
UNKNOWN_FUNCTION(btm_inq_rmt_name_failed);

#ifdef __cplusplus
}
#endif

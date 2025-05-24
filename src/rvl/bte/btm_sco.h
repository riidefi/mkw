#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x8013e2b0..0x8013e2f4
UNKNOWN_FUNCTION(btm_sco_init);
// PAL: 0x8013e2f4..0x8013e4d0
UNKNOWN_FUNCTION(btm_esco_conn_rsp);
// PAL: 0x8013e4d0..0x8013e65c
UNKNOWN_FUNCTION(btm_sco_chk_pend_unpark);
// PAL: 0x8013e65c..0x8013e83c
UNKNOWN_FUNCTION(btm_sco_conn_req);
// PAL: 0x8013e83c..0x8013e9dc
UNKNOWN_FUNCTION(btm_sco_connected);
// PAL: 0x8013e9dc..0x8013ea94
UNKNOWN_FUNCTION(BTM_RemoveSco);
// PAL: 0x8013ea94..0x8013eb18
UNKNOWN_FUNCTION(btm_remove_sco_links);
// PAL: 0x8013eb18..0x8013ec2c
UNKNOWN_FUNCTION(btm_sco_removed);
// PAL: 0x8013ec2c..0x8013ece0
UNKNOWN_FUNCTION(btm_sco_acl_removed);
// PAL: 0x8013ece0..0x8013ece4
UNKNOWN_FUNCTION(btm_route_sco_data);
// PAL: 0x8013ece4..0x8013ee8c
UNKNOWN_FUNCTION(BTM_ChangeEScoLinkParms);
// PAL: 0x8013ee8c..0x8013ef90
UNKNOWN_FUNCTION(btm_esco_proc_conn_chg);
// PAL: 0x8013ef90..0x8013f000
UNKNOWN_FUNCTION(btm_is_sco_active);
// PAL: 0x8013f000..0x8013f060
UNKNOWN_FUNCTION(btm_num_sco_links_active);
// PAL: 0x8013f060..0x8013f0e8
UNKNOWN_FUNCTION(btm_is_sco_active_by_bdaddr);

#ifdef __cplusplus
}
#endif

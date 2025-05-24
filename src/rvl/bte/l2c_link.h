#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x8014c108..0x8014c25c
UNKNOWN_FUNCTION(l2c_link_hci_conn_req);
// PAL: 0x8014c25c..0x8014c494
UNKNOWN_FUNCTION(l2c_link_hci_conn_comp);
// PAL: 0x8014c494..0x8014c548
UNKNOWN_FUNCTION(l2c_link_sec_comp);
// PAL: 0x8014c548..0x8014c604
UNKNOWN_FUNCTION(l2c_link_hci_disc_comp);
// PAL: 0x8014c604..0x8014c674
UNKNOWN_FUNCTION(l2c_link_hci_qos_violation);
// PAL: 0x8014c674..0x8014c7e8
UNKNOWN_FUNCTION(l2c_link_timeout);
// PAL: 0x8014c7e8..0x8014c8f0
UNKNOWN_FUNCTION(l2c_link_send_to_lower);
// PAL: 0x8014c8f0..0x8014cbbc
UNKNOWN_FUNCTION(l2c_link_check_send_pkts);
// PAL: 0x8014cbbc..0x8014cd54
UNKNOWN_FUNCTION(l2c_link_adjust_allocation);
// PAL: 0x8014cd54..0x8014ce38
UNKNOWN_FUNCTION(l2c_link_process_num_completed_pkts);
// PAL: 0x8014ce38..0x8014ce4c
UNKNOWN_FUNCTION(l2c_link_processs_num_bufs);
// PAL: 0x8014ce4c..0x8014d01c
UNKNOWN_FUNCTION(l2cap_link_chk_pkt_start);
// PAL: 0x8014d01c..0x8014d088
UNKNOWN_FUNCTION(l2cap_link_chk_pkt_end);
// PAL: 0x8014d088..0x8014d108
UNKNOWN_FUNCTION(l2c_link_role_changed);
// PAL: 0x8014d108..0x8014d174
UNKNOWN_FUNCTION(l2c_link_role_change_failed);
// PAL: 0x8014d174..0x8014d250
UNKNOWN_FUNCTION(l2c_link_segments_xmitted);
// PAL: 0x8014d250..0x8014d294
UNKNOWN_FUNCTION(l2c_pin_code_request);

#ifdef __cplusplus
}
#endif

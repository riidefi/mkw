#include "bta_hh_act.h"

// --- EXTERN DECLARATIONS BEGIN ---

// Extern function references.
// PAL: 0x80005f34
extern UNKNOWN_FUNCTION(memcpy);
// PAL: 0x80006038
extern UNKNOWN_FUNCTION(memset);
// PAL: 0x800215a0
extern UNKNOWN_FUNCTION(_savegpr_27);
// PAL: 0x800215ec
extern UNKNOWN_FUNCTION(_restgpr_27);
// PAL: 0x8012ebb4
extern UNKNOWN_FUNCTION(GKI_getbuf);
// PAL: 0x80131740
extern UNKNOWN_FUNCTION(LogMsg_0);
// PAL: 0x80131758
extern UNKNOWN_FUNCTION(LogMsg_1);
// PAL: 0x80131770
extern UNKNOWN_FUNCTION(LogMsg_2);
// PAL: 0x80131788
extern UNKNOWN_FUNCTION(LogMsg_3);
// PAL: 0x80131d90
extern UNKNOWN_FUNCTION(bdcpy);
// PAL: 0x80131e94
extern UNKNOWN_FUNCTION(bta_sys_conn_open);
// PAL: 0x80131f58
extern UNKNOWN_FUNCTION(bta_sys_conn_close);
// PAL: 0x8013201c
extern UNKNOWN_FUNCTION(bta_sys_sco_close);
// PAL: 0x80132050
extern UNKNOWN_FUNCTION(bta_sys_idle);
// PAL: 0x80132084
extern UNKNOWN_FUNCTION(bta_sys_busy);
// PAL: 0x8013223c
extern UNKNOWN_FUNCTION(bta_sys_sendmsg);
// PAL: 0x801324dc
extern UNKNOWN_FUNCTION(utl_freebuf);
// PAL: 0x80135b60
extern UNKNOWN_FUNCTION(bta_hh_sdp_cback);
// PAL: 0x80135c94
extern UNKNOWN_FUNCTION(bta_hh_start_sdp);
// PAL: 0x80136288
extern UNKNOWN_FUNCTION(jump_80136288);
// PAL: 0x80136290
extern UNKNOWN_FUNCTION(jump_80136290);
// PAL: 0x80136298
extern UNKNOWN_FUNCTION(jump_80136298);
// PAL: 0x801362a0
extern UNKNOWN_FUNCTION(jump_801362a0);
// PAL: 0x801362a8
extern UNKNOWN_FUNCTION(jump_801362a8);
// PAL: 0x801362b0
extern UNKNOWN_FUNCTION(jump_801362b0);
// PAL: 0x801362b8
extern UNKNOWN_FUNCTION(jump_801362b8);
// PAL: 0x801362c0
extern UNKNOWN_FUNCTION(jump_801362c0);
// PAL: 0x801362f8
extern UNKNOWN_FUNCTION(jump_801362f8);
// PAL: 0x80136378
extern UNKNOWN_FUNCTION(jump_80136378);
// PAL: 0x801363e8
extern UNKNOWN_FUNCTION(jump_801363e8);
// PAL: 0x80136454
extern UNKNOWN_FUNCTION(jump_80136454);
// PAL: 0x801364fc
extern UNKNOWN_FUNCTION(jump_801364fc);
// PAL: 0x80136504
extern UNKNOWN_FUNCTION(jump_80136504);
// PAL: 0x8013650c
extern UNKNOWN_FUNCTION(jump_8013650c);
// PAL: 0x80136514
extern UNKNOWN_FUNCTION(jump_80136514);
// PAL: 0x8013651c
extern UNKNOWN_FUNCTION(jump_8013651c);
// PAL: 0x80136524
extern UNKNOWN_FUNCTION(jump_80136524);
// PAL: 0x8013652c
extern UNKNOWN_FUNCTION(jump_8013652c);
// PAL: 0x80136534
extern UNKNOWN_FUNCTION(jump_80136534);
// PAL: 0x801365e0
extern UNKNOWN_FUNCTION(jump_801365e0);
// PAL: 0x801365e8
extern UNKNOWN_FUNCTION(jump_801365e8);
// PAL: 0x801365f0
extern UNKNOWN_FUNCTION(jump_801365f0);
// PAL: 0x801365f8
extern UNKNOWN_FUNCTION(jump_801365f8);
// PAL: 0x80136600
extern UNKNOWN_FUNCTION(jump_80136600);
// PAL: 0x80136608
extern UNKNOWN_FUNCTION(jump_80136608);
// PAL: 0x80136610
extern UNKNOWN_FUNCTION(jump_80136610);
// PAL: 0x80136618
extern UNKNOWN_FUNCTION(jump_80136618);
// PAL: 0x80136cf4
extern UNKNOWN_FUNCTION(bta_hh_cback);
// PAL: 0x80136d58
extern UNKNOWN_FUNCTION(jump_80136d58);
// PAL: 0x80136d60
extern UNKNOWN_FUNCTION(jump_80136d60);
// PAL: 0x80136d68
extern UNKNOWN_FUNCTION(jump_80136d68);
// PAL: 0x80136d70
extern UNKNOWN_FUNCTION(jump_80136d70);
// PAL: 0x80136d78
extern UNKNOWN_FUNCTION(jump_80136d78);
// PAL: 0x80136d80
extern UNKNOWN_FUNCTION(jump_80136d80);
// PAL: 0x80136d88
extern UNKNOWN_FUNCTION(jump_80136d88);
// PAL: 0x80136d90
extern UNKNOWN_FUNCTION(jump_80136d90);
// PAL: 0x80136d98
extern UNKNOWN_FUNCTION(jump_80136d98);
// PAL: 0x80136dd0
extern UNKNOWN_FUNCTION(jump_80136dd0);
// PAL: 0x80136dd8
extern UNKNOWN_FUNCTION(jump_80136dd8);
// PAL: 0x80136de0
extern UNKNOWN_FUNCTION(jump_80136de0);
// PAL: 0x80136de8
extern UNKNOWN_FUNCTION(jump_80136de8);
// PAL: 0x80136df0
extern UNKNOWN_FUNCTION(jump_80136df0);
// PAL: 0x80136df8
extern UNKNOWN_FUNCTION(jump_80136df8);
// PAL: 0x80136e04
extern UNKNOWN_FUNCTION(jump_80136e04);
// PAL: 0x80136f3c
extern UNKNOWN_FUNCTION(jump_80136f3c);
// PAL: 0x8013735c
extern UNKNOWN_FUNCTION(bta_hh_sm_execute);
// PAL: 0x801379ec
extern UNKNOWN_FUNCTION(bta_hh_clean_up_kdev);
// PAL: 0x80137a6c
extern UNKNOWN_FUNCTION(bta_hh_add_device_to_list);
// PAL: 0x80137b28
extern UNKNOWN_FUNCTION(bta_hh_tod_spt);
// PAL: 0x80137b7c
extern UNKNOWN_FUNCTION(bta_hh_trace_dev_db);
// PAL: 0x801472a0
extern UNKNOWN_FUNCTION(HID_HostGetSDPRecord);
// PAL: 0x801477b8
extern UNKNOWN_FUNCTION(HID_HostInit);
// PAL: 0x801477fc
extern UNKNOWN_FUNCTION(HID_HostRegister);
// PAL: 0x80147878
extern UNKNOWN_FUNCTION(HID_HostDeregister);
// PAL: 0x8014795c
extern UNKNOWN_FUNCTION(HID_HostAddDev);
// PAL: 0x80147aec
extern UNKNOWN_FUNCTION(HID_HostRemoveDev);
// PAL: 0x80147bb4
extern UNKNOWN_FUNCTION(HID_HostOpenDev);
// PAL: 0x80147c18
extern UNKNOWN_FUNCTION(HID_HostWriteDev);
// PAL: 0x80147d58
extern UNKNOWN_FUNCTION(HID_HostCloseDev);
// PAL: 0x80147df8
extern UNKNOWN_FUNCTION(HID_HostSetSecurityLevel);
// PAL: 0x8014f974
extern UNKNOWN_FUNCTION(l2cu_find_ccb_by_cid);
// PAL: 0x801d0968
extern UNKNOWN_FUNCTION(bta_hh_co_data);
// PAL: 0x801d09a4
extern UNKNOWN_FUNCTION(bta_hh_co_open);
// PAL: 0x801d09b4
extern UNKNOWN_FUNCTION(bta_hh_co_close);// Extern data references.
// PAL: 0x80282a58
extern UNKNOWN_DATA(lbl_80282a58);
// PAL: 0x80282ab0
extern UNKNOWN_DATA(lbl_80282ab0);
// PAL: 0x80282ae0
extern UNKNOWN_DATA(lbl_80282ae0);
// PAL: 0x80282b30
extern UNKNOWN_DATA(lbl_80282b30);
// PAL: 0x80282b50
extern UNKNOWN_DATA(lbl_80282b50);
// PAL: 0x80282b9c
extern UNKNOWN_DATA(lbl_80282b9c);
// PAL: 0x80282cb0
extern UNKNOWN_DATA(jtbl_80282cb0);
// PAL: 0x80282cd8
extern UNKNOWN_DATA(jtbl_80282cd8);
// PAL: 0x80282d5c
extern UNKNOWN_DATA(jtbl_80282d5c);
// PAL: 0x80282d84
extern UNKNOWN_DATA(jtbl_80282d84);
// PAL: 0x80282db0
extern UNKNOWN_DATA(lbl_80282db0);
// PAL: 0x80282dc0
extern UNKNOWN_DATA(lbl_80282dc0);
// PAL: 0x80282ddc
extern UNKNOWN_DATA(lbl_80282ddc);
// PAL: 0x80282f08
extern UNKNOWN_DATA(jtbl_80282f08);
// PAL: 0x80282f2c
extern UNKNOWN_DATA(jtbl_80282f2c);
// PAL: 0x80336048
extern UNKNOWN_DATA(lbl_80336048);
// PAL: 0x80338f38
extern UNKNOWN_DATA(lbl_80338f38);
// PAL: 0x80339340
extern UNKNOWN_DATA(lbl_80339340);
// PAL: 0x80385840
extern UNKNOWN_DATA(lbl_80385840);
// PAL: 0x80385868
extern UNKNOWN_DATA(lbl_80385868);
// PAL: 0x803865f0
extern UNKNOWN_DATA(lbl_803865f0);
// --- EXTERN DECLARATIONS END ---

// .rodata

// .data


// .bss


// Symbol: bta_hh_api_enable
// PAL: 0x80135844..0x801359b8
MARK_BINARY_BLOB(bta_hh_api_enable, 0x80135844, 0x801359b8);
asm UNKNOWN_FUNCTION(bta_hh_api_enable) {
  #include "asm/80135844.s"
}

// Symbol: bta_hh_api_disable
// PAL: 0x801359b8..0x80135abc
MARK_BINARY_BLOB(bta_hh_api_disable, 0x801359b8, 0x80135abc);
asm UNKNOWN_FUNCTION(bta_hh_api_disable) {
  #include "asm/801359b8.s"
}

// Symbol: bta_hh_disc_cmpl
// PAL: 0x80135abc..0x80135b60
MARK_BINARY_BLOB(bta_hh_disc_cmpl, 0x80135abc, 0x80135b60);
asm UNKNOWN_FUNCTION(bta_hh_disc_cmpl) {
  #include "asm/80135abc.s"
}

// Symbol: bta_hh_sdp_cback
// PAL: 0x80135b60..0x80135c94
MARK_BINARY_BLOB(bta_hh_sdp_cback, 0x80135b60, 0x80135c94);
asm UNKNOWN_FUNCTION(bta_hh_sdp_cback) {
  #include "asm/80135b60.s"
}

// Symbol: bta_hh_start_sdp
// PAL: 0x80135c94..0x80135e28
MARK_BINARY_BLOB(bta_hh_start_sdp, 0x80135c94, 0x80135e28);
asm UNKNOWN_FUNCTION(bta_hh_start_sdp) {
  #include "asm/80135c94.s"
}

// Symbol: bta_hh_sdp_cmpl
// PAL: 0x80135e28..0x80135f90
MARK_BINARY_BLOB(bta_hh_sdp_cmpl, 0x80135e28, 0x80135f90);
asm UNKNOWN_FUNCTION(bta_hh_sdp_cmpl) {
  #include "asm/80135e28.s"
}

// Symbol: bta_hh_api_disc_act
// PAL: 0x80135f90..0x80135ff8
MARK_BINARY_BLOB(bta_hh_api_disc_act, 0x80135f90, 0x80135ff8);
asm UNKNOWN_FUNCTION(bta_hh_api_disc_act) {
  #include "asm/80135f90.s"
}

// Symbol: bta_hh_open_cmpl_act
// PAL: 0x80135ff8..0x80136120
MARK_BINARY_BLOB(bta_hh_open_cmpl_act, 0x80135ff8, 0x80136120);
asm UNKNOWN_FUNCTION(bta_hh_open_cmpl_act) {
  #include "asm/80135ff8.s"
}

// Symbol: bta_hh_open_act
// PAL: 0x80136120..0x801361d8
MARK_BINARY_BLOB(bta_hh_open_act, 0x80136120, 0x801361d8);
asm UNKNOWN_FUNCTION(bta_hh_open_act) {
  #include "asm/80136120.s"
}

// Symbol: bta_hh_data_act
// PAL: 0x801361d8..0x80136230
MARK_BINARY_BLOB(bta_hh_data_act, 0x801361d8, 0x80136230);
asm UNKNOWN_FUNCTION(bta_hh_data_act) {
  #include "asm/801361d8.s"
}

// Symbol: bta_hh_handsk_act
// PAL: 0x80136230..0x80136498
MARK_BINARY_BLOB(bta_hh_handsk_act, 0x80136230, 0x80136498);
asm UNKNOWN_FUNCTION(bta_hh_handsk_act) {
  #include "asm/80136230.s"
}

// Symbol: bta_hh_ctrl_dat_act
// PAL: 0x80136498..0x80136690
MARK_BINARY_BLOB(bta_hh_ctrl_dat_act, 0x80136498, 0x80136690);
asm UNKNOWN_FUNCTION(bta_hh_ctrl_dat_act) {
  #include "asm/80136498.s"
}

// Symbol: bta_hh_close_act
// PAL: 0x80136690..0x80136890
MARK_BINARY_BLOB(bta_hh_close_act, 0x80136690, 0x80136890);
asm UNKNOWN_FUNCTION(bta_hh_close_act) {
  #include "asm/80136690.s"
}

// Symbol: bta_hh_get_dscp_act
// PAL: 0x80136890..0x801368ac
MARK_BINARY_BLOB(bta_hh_get_dscp_act, 0x80136890, 0x801368ac);
asm UNKNOWN_FUNCTION(bta_hh_get_dscp_act) {
  #include "asm/80136890.s"
}

// Symbol: bta_hh_maint_dev_act
// PAL: 0x801368ac..0x80136a10
MARK_BINARY_BLOB(bta_hh_maint_dev_act, 0x801368ac, 0x80136a10);
asm UNKNOWN_FUNCTION(bta_hh_maint_dev_act) {
  #include "asm/801368ac.s"
}

// Symbol: bta_hh_get_acl_q_info
// PAL: 0x80136a10..0x80136b2c
MARK_BINARY_BLOB(bta_hh_get_acl_q_info, 0x80136a10, 0x80136b2c);
asm UNKNOWN_FUNCTION(bta_hh_get_acl_q_info) {
  #include "asm/80136a10.s"
}

// Symbol: bta_hh_write_dev_act
// PAL: 0x80136b2c..0x80136cf4
MARK_BINARY_BLOB(bta_hh_write_dev_act, 0x80136b2c, 0x80136cf4);
asm UNKNOWN_FUNCTION(bta_hh_write_dev_act) {
  #include "asm/80136b2c.s"
}

// Symbol: bta_hh_cback
// PAL: 0x80136cf4..0x80136f8c
MARK_BINARY_BLOB(bta_hh_cback, 0x80136cf4, 0x80136f8c);
asm UNKNOWN_FUNCTION(bta_hh_cback) {
  #include "asm/80136cf4.s"
}


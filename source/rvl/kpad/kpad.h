#pragma once

#include <rk_types.h>

#include <decomp.h>

#include <rvl/wpad/wpad.h>
#include <rvl/mtx/mtx.h>

#ifdef __cplusplus
extern "C" {
#endif

// Size: 0x24
typedef union KPADEXStatus {
  struct {
    Vec2 stick;
    Vec acc;
    f32 acc_value;
    f32 acc_speed;
  } fs;
  struct {
    u32 hold;
    u32 trig;
    u32 release;
    Vec2 lstick;
    Vec2 rstick;
    f32 ltrigger;
    f32 rtrigger;
  } cl;
} KPADEXStatus;

// Size: 0x84
typedef struct KPADStatus {
  u32 hold;
  u32 trig;
  u32 release;
  Vec acc;
  f32 acc_value;
  f32 acc_speed;
  Vec2 pos;
  Vec2 vec;
  f32 speed;
  Vec2 horizon;
  Vec2 hori_vec;
  f32 hori_speed;
  f32 dist;
  f32 dist_vec;
  f32 dist_speed;
  Vec2 acc_vertical;
  u8 dev_type;
  s8 wpad_err;
  s8 dpd_valid_fg;
  u8 data_format;
  KPADEXStatus ex_status;
} KPADStatus;

// Size: 0x38
typedef struct KPADUnifiedWpadStatus {
  union {
    WPADStatus core;
    WPADFSStatus fs;
    WPADCLStatus cl;
  } u;
  u8 fmt;
  u8 padding;
} KPADUnifiedWpadStatus;

// PAL: 0x801950a0..0x801950b4
UNKNOWN_FUNCTION(KPADSetFSStickClamp);
// PAL: 0x801950b4..0x801950d0
UNKNOWN_FUNCTION(KPADSetPosParam);
// PAL: 0x801950d0..0x80195124
UNKNOWN_FUNCTION(KPADSetHoriParam);
// PAL: 0x80195124..0x801952f8
UNKNOWN_FUNCTION(reset_kpad);
// PAL: 0x801952f8..0x8019548c
UNKNOWN_FUNCTION(calc_button_repeat);
// PAL: 0x8019548c..0x80195540
UNKNOWN_FUNCTION(calc_acc);
// PAL: 0x80195540..0x801956d4
UNKNOWN_FUNCTION(calc_acc_horizon);
// PAL: 0x801956d4..0x801957f8
UNKNOWN_FUNCTION(calc_acc_vertical);
// PAL: 0x801957f8..0x80195c60
UNKNOWN_FUNCTION(read_kpad_acc);
// PAL: 0x80195c60..0x80195e48
UNKNOWN_FUNCTION(select_2obj_first);
// PAL: 0x80195e48..0x80196070
UNKNOWN_FUNCTION(select_2obj_continue);
// PAL: 0x80196070..0x80196224
UNKNOWN_FUNCTION(select_1obj_first);
// PAL: 0x80196224..0x80196398
UNKNOWN_FUNCTION(select_1obj_continue);
// PAL: 0x80196398..0x80196964
UNKNOWN_FUNCTION(calc_dpd_variable);
// PAL: 0x80196964..0x80196dbc
UNKNOWN_FUNCTION(read_kpad_dpd);
// PAL: 0x80196dbc..0x80196ee4
UNKNOWN_FUNCTION(clamp_stick_circle);
// PAL: 0x80196ee4..0x80197108
UNKNOWN_FUNCTION(clamp_stick_cross);
// PAL: 0x80197108..0x80197380
UNKNOWN_FUNCTION(read_kpad_stick);
// PAL: 0x80197380..0x80197aac
UNKNOWN_FUNCTION(KPADRead);
// PAL: 0x80197aac..0x80197da0
UNKNOWN_FUNCTION(KPADInit);
// PAL: 0x80197da0..0x80197dbc
UNKNOWN_FUNCTION(KPADDisableDPD);
// PAL: 0x80197dbc..0x80197dd8
UNKNOWN_FUNCTION(KPADEnableDPD);
// PAL: 0x80197dd8..0x801980b0
UNKNOWN_FUNCTION(KPADiSamplingCallback);
// PAL: 0x801980b0..0x8019812c
UNKNOWN_FUNCTION(KPADiControlDpdCallback);
// PAL: 0x8019812c..0x801981ec
UNKNOWN_FUNCTION(KPADGetUnifiedWpadStatus);

#ifdef __cplusplus
}
#endif

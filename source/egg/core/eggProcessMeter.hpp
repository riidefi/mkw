#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x802386dc..0x80238714
UNKNOWN_FUNCTION(CpuMonitor_measureBegin);
// PAL: 0x80238714..0x80238750
UNKNOWN_FUNCTION(CpuMonitor_measureEnd);
// PAL: 0x80238750..0x80238760
UNKNOWN_FUNCTION(CpuMonitor_show);
// PAL: 0x80238760..0x80238770
UNKNOWN_FUNCTION(CpuMonitor_hide);
// PAL: 0x80238770..0x802387bc
UNKNOWN_FUNCTION(CpuGpMonitor_measureBegin);
// PAL: 0x802387bc..0x80238804
UNKNOWN_FUNCTION(CpuGpMonitor_measureEnd);
// PAL: 0x80238804..0x80238820
UNKNOWN_FUNCTION(CpuGpMonitor_show);
// PAL: 0x80238820..0x8023883c
UNKNOWN_FUNCTION(CpuGpMonitor_hide);
// PAL: 0x8023883c..0x80238a94
UNKNOWN_FUNCTION(ProcessMeter_construct);
// PAL: 0x80238a94..0x80238d10
UNKNOWN_FUNCTION(ProcessMeter_measureBeginFrame);
// PAL: 0x80238d10..0x80238d20
UNKNOWN_FUNCTION(ProcessMeter_measureEndFrame);
// PAL: 0x80238d20..0x80238d30
UNKNOWN_FUNCTION(ProcessMeter_measureBeginRender);
// PAL: 0x80238d30..0x80238d40
UNKNOWN_FUNCTION(ProcessMeter_measureEndRender);
// PAL: 0x80238d40..0x80238d8c
UNKNOWN_FUNCTION(ProcessMeter_callbackDrawSync);
// PAL: 0x80238d8c..0x80238e38
UNKNOWN_FUNCTION(ProcessMeter_run);
// PAL: 0x80238e38..0x80238f14
UNKNOWN_FUNCTION(ProcessMeter_setDrawSync);
// PAL: 0x80238f14..0x80238f3c
UNKNOWN_FUNCTION(ProcessMeter_setVisible);
// PAL: 0x80238f3c..0x80238f48
UNKNOWN_FUNCTION(ProcessMeter_isVisible);
// PAL: 0x80238f48..0x80238fa4
UNKNOWN_FUNCTION(ProcessMeter_append);
// PAL: 0x80238fa4..0x802393e0
UNKNOWN_FUNCTION(ProcessMeter_draw);
// PAL: 0x802393e0..0x80239628
UNKNOWN_FUNCTION(ProcessMeter_drawSetting);
// PAL: 0x80239628..0x80239680
UNKNOWN_FUNCTION(ProcessMeter_destroy);
// PAL: 0x80239680..0x80239688
UNKNOWN_FUNCTION(ProcessMeter_isVisible_);
// PAL: 0x80239688..0x80239690
UNKNOWN_FUNCTION(ProcessMeter_setVisible_);
// PAL: 0x80239690..0x80239698
UNKNOWN_FUNCTION(ProcessMeter_draw_);
// PAL: 0x80239698..0x802396a0
UNKNOWN_FUNCTION(ProcessMeter_callbackDrawSync_);
// PAL: 0x802396a0..0x802396a8
UNKNOWN_FUNCTION(ProcessMeter_measureEndRender_);
// PAL: 0x802396a8..0x802396b0
UNKNOWN_FUNCTION(ProcessMeter_measureBeginRender_);
// PAL: 0x802396b0..0x802396b8
UNKNOWN_FUNCTION(ProcessMeter_measureEndFrame_);
// PAL: 0x802396b8..0x802396c0
UNKNOWN_FUNCTION(ProcessMeter_measureBeginFrame_);

#ifdef __cplusplus
}
#endif
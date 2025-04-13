#pragma once

#include <rk_types.h>

#define UNKNOWN_FUNCTION(...)
#define UNKNOWN_DATA(...)

typedef struct ps_f32 {
  f32 f0;
  f32 f1;
} ps_f32;

#ifdef __CWCC__

#pragma section RW "flow_check"
#define SECTION_FLOW_CHECK __declspec(section "flow_check")
#define MARK_FLOW_CHECK(start)                                                 \
  SECTION_FLOW_CHECK u32 __flow_check_##start = start             \
      __attribute__((force_export))


#define sdata_ps_f32 __declspec(section ".sdata") ps_f32
#define sdata2_ps_f32 __declspec(section ".sdata2") const ps_f32

#pragma section "garbage"
#define SECTION_GARBAGE
#define static_order_hints                                                     \
  SECTION_GARBAGE static void __garbage_ordering_hints(void)
#define order_hint_access(var) (void)(var)

#elif defined (__INTELLISENSE__)

#define sdata_ps_f32 ps_f32
#define sdata2_ps_f32 ps_f32

#define SECTION_FLOW_CHECK
#define MARK_FLOW_CHECK(start)
#define SECTION_GARBAGE
#define static_order_hints
#define order_hint_access(var) (void)(var)

#endif

#ifdef __clang__
#define __cntlzw(x) __builtin_clz(x)
#endif

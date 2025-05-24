#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x8015ac40..0x8015acd0
UNKNOWN_FUNCTION(sdpu_find_ccb_by_cid);
// PAL: 0x8015acd0..0x8015ad44
UNKNOWN_FUNCTION(sdpu_allocate_ccb);
// PAL: 0x8015ad44..0x8015ad7c
UNKNOWN_FUNCTION(sdpu_release_ccb);
// PAL: 0x8015ad7c..0x8015af4c
UNKNOWN_FUNCTION(sdpu_build_attrib_seq);
// PAL: 0x8015af4c..0x8015b0a0
UNKNOWN_FUNCTION(sdpu_build_attrib_entry);
// PAL: 0x8015b0a0..0x8015b1dc
UNKNOWN_FUNCTION(sdpu_build_n_send_error);
// PAL: 0x8015b1dc..0x8015b52c
UNKNOWN_FUNCTION(sdpu_extract_uid_seq);
// PAL: 0x8015b52c..0x8015b77c
UNKNOWN_FUNCTION(sdpu_extract_attr_seq);
// PAL: 0x8015b77c..0x8015b84c
UNKNOWN_FUNCTION(sdpu_get_len_from_type);
// PAL: 0x8015b84c..0x8015b92c
UNKNOWN_FUNCTION(sdpu_is_base_uuid);
// PAL: 0x8015b92c..0x8015bba0
UNKNOWN_FUNCTION(sdpu_compare_uuid_arrays);
// PAL: 0x8015bba0..0x8015bc30
UNKNOWN_FUNCTION(sdpu_compare_uuid_with_attr);
// PAL: 0x8015bc30..0x8015bc80
UNKNOWN_FUNCTION(sdpu_sort_attr_list);

#ifdef __cplusplus
}
#endif

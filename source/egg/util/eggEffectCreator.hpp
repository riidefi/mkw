#pragma once

#include <rk_types.h>

#include <decomp.h>

#ifdef __cplusplus
extern "C" {
#endif

// PAL: 0x80224348..0x802243b4
UNKNOWN_FUNCTION(EffectCreator_construct);
// PAL: 0x802243b4..0x8022443c
UNKNOWN_FUNCTION(EffectCreator_destroy);
// PAL: 0x8022443c..0x802244b4
UNKNOWN_FUNCTION(EffectCreator_stopAllEffect);
// PAL: 0x802244b4..0x8022450c
UNKNOWN_FUNCTION(EffectCreator_calcAll);
// PAL: 0x8022450c..0x80224558
UNKNOWN_FUNCTION(EffectCreator_calcGroup);
// PAL: 0x80224558..0x802245ac
UNKNOWN_FUNCTION(EffectCreator_draw);
// PAL: 0x802245ac..0x8022464c
UNKNOWN_FUNCTION(EffectCreator_createEffect);
// PAL: 0x8022464c..0x802246ec
UNKNOWN_FUNCTION(unk_8022464c);

#ifdef __cplusplus
}
#endif

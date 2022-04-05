#pragma once

#ifdef __cplusplus
#error "C++ not supported during init"
#endif

void __init_hardware();
void __flush_cache();

#pragma once

#ifdef __cplusplus
#error "C++ not supported during init"
#endif

/// Initializes paired-singles, FPRs and cache.
void __init_hardware();

/// Flushes data cache and instruction cache.
void __flush_cache();

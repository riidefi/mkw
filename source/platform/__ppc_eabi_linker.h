#pragma once

typedef struct __eti_init_info {
  void* eti_start;
  void* eti_end;
  void* code_start;
  unsigned long code_size;
} __eti_init_info;

// _eti_init_info is a linker-generated symbol.
// Since we don't have proper extab/extabindex sections,
// trying to reference it is going to fail.
#ifdef __CWCC__
__declspec(section ".init") extern __eti_init_info _eti_init_info_[];
#endif

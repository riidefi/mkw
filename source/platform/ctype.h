#pragma once

#include "rk_types.h"

#ifdef __cplusplus
extern "C" {
#endif

struct _loc_ctype_cmpt {
  char CmptName[8];
  const unsigned short* ctype_map_ptr;
  const unsigned char* upper_map_ptr;
  const unsigned char* lower_map_ptr;
};

struct __locale {
  struct __locale* next_locale;
  char locale_name[48];
  struct _loc_coll_cmpt* coll_cmpt_ptr;
  struct _loc_ctype_cmpt* ctype_cmpt_ptr;
  struct _loc_mon_cmpt* mon_cmpt_ptr;
  struct _loc_num_cmpt* num_cmpt_ptr;
  struct _loc_time_cmpt* time_cmpt_ptr;
};

extern struct __locale _current_locale;

inline int isalnum(int c) {
  return ((c < 0) || (c >= 256))
             ? 0
             : (int)(_current_locale.ctype_cmpt_ptr->ctype_map_ptr[c] & 0x9);
}
inline int isalpha(int c) {
  return ((c < 0) || (c >= 256))
             ? 0
             : (int)(_current_locale.ctype_cmpt_ptr->ctype_map_ptr[c] & 0x1);
}
inline int isblank(int c) {
  return ((c < 0) || (c >= 256))
             ? 0
             : (int)(_current_locale.ctype_cmpt_ptr->ctype_map_ptr[c] & 0x2);
}
inline int iscntrl(int c) {
  return ((c < 0) || (c >= 256))
             ? 0
             : (int)(_current_locale.ctype_cmpt_ptr->ctype_map_ptr[c] & 0x4);
}
inline int isdigit(int c) {
  return ((c < 0) || (c >= 256))
             ? 0
             : (int)(_current_locale.ctype_cmpt_ptr->ctype_map_ptr[c] & 0x8);
}
inline int isgraph(int c) {
  return ((c < 0) || (c >= 256))
             ? 0
             : (int)(_current_locale.ctype_cmpt_ptr->ctype_map_ptr[c] & 0x10);
}
inline int islower(int c) {
  return ((c < 0) || (c >= 256))
             ? 0
             : (int)(_current_locale.ctype_cmpt_ptr->ctype_map_ptr[c] & 0x20);
}
inline int isprint(int c) {
  return ((c < 0) || (c >= 256))
             ? 0
             : (int)(_current_locale.ctype_cmpt_ptr->ctype_map_ptr[c] & 0x40);
}
inline int ispunct(int c) {
  return ((c < 0) || (c >= 256))
             ? 0
             : (int)(_current_locale.ctype_cmpt_ptr->ctype_map_ptr[c] & 0x80);
}
inline int isspace(int c) {
  return ((c < 0) || (c >= 256))
             ? 0
             : (int)(_current_locale.ctype_cmpt_ptr->ctype_map_ptr[c] & 0x0100);
}
inline int isupper(int c) {
  return ((c < 0) || (c >= 256))
             ? 0
             : (int)(_current_locale.ctype_cmpt_ptr->ctype_map_ptr[c] & 0x0200);
}
inline int isxdigit(int c) {
  return ((c < 0) || (c >= 256))
             ? 0
             : (int)(_current_locale.ctype_cmpt_ptr->ctype_map_ptr[c] & 0x0400);
}
inline int tolower(int c) {
  return ((c < 0) || (c >= 256))
             ? c
             : (int)(_current_locale.ctype_cmpt_ptr->lower_map_ptr[c]);
}
inline int toupper(int c) {
  return ((c < 0) || (c >= 256))
             ? c
             : (int)(_current_locale.ctype_cmpt_ptr->upper_map_ptr[c]);
}

#ifdef __cplusplus
} // extern "C"
#endif

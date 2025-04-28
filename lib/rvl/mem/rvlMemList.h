#pragma once

#include <rk_types.h>

#ifdef __cplusplus
extern "C" {
#endif

//! Bidirectional list node
typedef struct {
  void* pred;
  void* succ;
} MEMLink;

// Unlike modern "std::list"-like structures, list nodes are directly inherited
// by children, which saves a level of indirection.
// Size: 0x0C
typedef struct {
  void* head;           // 0x00
  void* tail;           // 0x04
  u16 count;            // 0x08
  u16 intrusion_offset; // 0x0A
} MEMList;

MEMList* MEMInitList(MEMList*, u16);
MEMList* MEMAppendListObject(MEMList*, void*);
MEMList* MEMRemoveListObject(MEMList*, void*);
void* MEMGetNextListObject(MEMList*, void*);

#define rvlMemListGetNode(list, obj)                                           \
  ((MEMLink*)(((char*)obj) + (list)->intrusion_offset))

#ifdef __cplusplus
}
#endif

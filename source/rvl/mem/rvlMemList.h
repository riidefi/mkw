#pragma once

#include <rk_types.h>

#ifdef __cplusplus
extern "C" {
#endif

//! Bidirectional list node
typedef struct {
  void* pred;
  void* succ;
} rvlMemBiNode;

// Unlike modern "std::list"-like structures, list nodes are directly inherited
// by children, which saves a level of indirection.
typedef struct {
  void* head;
  void* tail;
  u16 count;
  u16 intrusion_offset;
} rvlMemIntrusiveList;

rvlMemIntrusiveList* MEMInitList(rvlMemIntrusiveList* pList,
                                 u16 intrusion_offset);
rvlMemIntrusiveList* MEMAppendListObject(rvlMemIntrusiveList* pList,
                                         void* pObj);
rvlMemIntrusiveList* MEMRemoveListObject(rvlMemIntrusiveList* pList,
                                         void* pObj);
void* MEMGetNextListObject(rvlMemIntrusiveList* pList, void* pObj);

#define rvlMemListGetNode(list, obj)                                           \
  ((rvlMemBiNode*)(((char*)obj) + (list)->intrusion_offset))

#ifdef __cplusplus
}
#endif
#pragma once

#include <rk_types.h>

#ifdef __cplusplus
extern "C" {
#endif

//! Bidirectional list node
typedef struct {
  void* pred;
  void* succ;
} rxBiNode;

// Unlike modern "std::list"-like structures, list nodes are directly inherited
// by children, which saves a level of indirection.
typedef struct {
  void* head;
  void* tail;
  u16 count;
  u16 intrusion_offset;
} rxIntrusiveList;

rxIntrusiveList* rxInitList(rxIntrusiveList* pList, u16 intrusion_offset);
rxIntrusiveList* rxListAppend(rxIntrusiveList* pList, void* pObj);
rxIntrusiveList* rxListRemove(rxIntrusiveList* pList, void* pObj);
void* rxListGetSuccessorOf(rxIntrusiveList* pList, void* pObj);

#define rxListGetNode(list, obj)                                               \
  ((rxBiNode*)(((char*)obj) + (list)->intrusion_offset))

#ifdef __cplusplus
}
#endif
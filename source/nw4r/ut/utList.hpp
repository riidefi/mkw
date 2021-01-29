#pragma once

#include <rk_types.h>

// clang-format off
namespace nw4r { namespace ut {
// clang-format on

//! Bidirectional list node
struct Node {
  void* pred;
  void* succ;
};

// Unlike modern "std::list"-like structures, list nodes are directly inherited
// by children, which saves a level of indirection.
struct List {
  void* head;
  void* tail;
  u16 count;
  u16 intrusion_offset;
};

//
void List_Init(List* pList, u16 intrusion_offset);
void List_Append(List* pList, void* pObj);
void List_Remove(List* pList, void* pObj);

// clang-format off
} } // namespace nw4r
// clang-format on

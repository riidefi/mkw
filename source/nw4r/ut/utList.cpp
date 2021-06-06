#include "utList.hpp"

namespace nw4r {
namespace ut {

#define LIST_GET_ELEM(list, obj)                                               \
  ((nw4r::ut::Node*)(((u32)(obj)) + (list)->intrusion_offset))

void List_Remove(List* pList, void* pObj) {
  nw4r::ut::Node* node = LIST_GET_ELEM(pList, pObj);
  if (node->pred == nullptr)
    pList->head = node->succ; // second node becomes list head
  else
    LIST_GET_ELEM(pList, node->pred)->succ = node->succ; // punch hole in list
  if (node->succ == nullptr)
    pList->tail = node->pred; // second to last node becomes list tail
  else
    LIST_GET_ELEM(pList, node->succ)->pred = node->pred; // punch hole in list
  // Reset node.
  node->pred = nullptr;
  node->succ = nullptr;
  // Update list.
  pList->count--;
}

void* List_GetNext(const nw4r::ut::List* pList, const void* pObj) {
  if (pObj == nullptr)
    return pList->head;
  return LIST_GET_ELEM(pList, pObj)->succ;
}

} // namespace ut
} // namespace nw4r

#include "utList.hpp"

namespace nw4r {
namespace ut {

#define LIST_GET_ELEM(list, obj)                                               \
  ((nw4r::ut::Node*)(((u32)(obj)) + (list)->intrusion_offset))

void List_Init(List* pList, u16 intrusion_offset) {
  pList->head = nullptr;
  pList->tail = nullptr;
  pList->count = 0;
  pList->intrusion_offset = intrusion_offset;
}

void List_Append(List* pList, void* pObj) {
  if (pList->head == nullptr) {
    // Node is the only element in the list.
    // Therefore it is both head and tail.
    nw4r::ut::Node* node = LIST_GET_ELEM(pList, pObj);
    node->succ = nullptr;
    node->pred = nullptr;
    pList->head = pObj;
    pList->tail = pObj;
    pList->count++;
  } else {
    // Link node to end of list.
    nw4r::ut::Node* node = LIST_GET_ELEM(pList, pObj);
    node->pred = pList->tail;
    node->succ = nullptr;
    // Link second to last node to new tail.
    LIST_GET_ELEM(pList, pList->tail)->succ = pObj;
    // Set new tail.
    pList->tail = pObj;
    pList->count++;
  }
}

static void List_Prepend(List* pList, void* pObj) {
  if (pList->head == nullptr) {
    // Node is the only element in the list.
    // Therefore it is both head and tail.
    nw4r::ut::Node* node = LIST_GET_ELEM(pList, pObj);
    node->succ = nullptr;
    node->pred = nullptr;
    pList->head = pObj;
    pList->tail = pObj;
    pList->count++;
  } else {
    // Link node to start of list.
    nw4r::ut::Node* node = LIST_GET_ELEM(pList, pObj);
    node->pred = nullptr;
    node->succ = pList->head;
    // Link second node to new head.
    LIST_GET_ELEM(pList, pList->head)->pred = pObj;
    // Set new head.
    pList->head = pObj;
    pList->count++;
  }
}

void List_Insert(List* pList, void* pTgt, void* pObj) {
  if (pTgt == nullptr) {
    // A null target means inserting at the end of the list.
    List_Append(pList, pObj);
  } else if (pTgt == pList->head) {
    List_Prepend(pList, pObj);
  } else {
    nw4r::ut::Node* node = LIST_GET_ELEM(pList, pObj);
    void* pred = LIST_GET_ELEM(pList, pTgt)->pred;
    nw4r::ut::Node* predNode = LIST_GET_ELEM(pList, pred);
    // Update links of node to be inserted.
    node->pred = pred;
    node->succ = pTgt;
    // Update links of neighbors.
    predNode->succ = pObj;
    LIST_GET_ELEM(pList, pTgt)->pred = pObj;
    // Update list.
    pList->count++;
  }
}

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

void* List_GetPrev(const nw4r::ut::List* pList, const void* pObj) {
  if (pObj == nullptr)
    return pList->tail;
  return LIST_GET_ELEM(pList, pObj)->pred;
}

void* List_GetNth(const nw4r::ut::List* pList, unsigned short n) {
  void* node;
  int i;

  for (i = 0, node = NULL; node = List_GetNext(pList, node); i++) {
    if (n == i)
      return node;
  }

  return NULL;
}

} // namespace ut
} // namespace nw4r

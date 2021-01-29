#include "rxList.h"

#ifdef __cplusplus
extern "C" {
#endif

rxIntrusiveList* rxInitList(rxIntrusiveList* pList, u16 intrusion_offset) {
  pList->intrusion_offset = intrusion_offset;
  pList->head = nullptr;
  pList->tail = nullptr;
  pList->count = 0;

  return pList;
}

rxIntrusiveList* rxListAppend(rxIntrusiveList* pList, void* pObj) {
  if (pList->head == nullptr) {
    rxBiNode* node = rxListGetNode(pList, pObj);

    node->succ = nullptr;
    node->pred = nullptr;

    pList->head = pObj;
    pList->tail = pObj;
    ++pList->count;

    return pList;
  }

  rxBiNode* node = rxListGetNode(pList, pObj);

  node->pred = pList->tail;
  node->succ = nullptr;

  rxListGetNode(pList, pList->tail)->succ = pObj;
  pList->tail = pObj;
  ++pList->count;

  return pList;
}

rxIntrusiveList* rxListRemove(rxIntrusiveList* pList, void* pObj) {
  rxBiNode* node = rxListGetNode(pList, pObj);

  if (node->pred == nullptr)
    pList->head = node->succ;
  else
    rxListGetNode(pList, node->pred)->succ = node->succ;

  if (node->succ == nullptr)
    pList->tail = node->pred;
  else
    rxListGetNode(pList, node->succ)->pred = node->pred;

  node->pred = nullptr;
  node->succ = nullptr;

  --pList->count;

  return pList;
}

void* rxListGetSuccessorOf(rxIntrusiveList* pList, void* pObj) {
  if (pObj == nullptr)
    return pList->head;

  return rxListGetNode(pList, pObj)->succ;
}

#ifdef __cplusplus
}
#endif
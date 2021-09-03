#include "rvlMemList.h"

#ifdef __cplusplus
extern "C" {
#endif

MEMList* MEMInitList(MEMList* pList, u16 intrusion_offset) {
  pList->intrusion_offset = intrusion_offset;
  pList->head = nullptr;
  pList->tail = nullptr;
  pList->count = 0;

  return pList;
}

MEMList* MEMAppendListObject(MEMList* pList, void* pObj) {
  if (pList->head == nullptr) {
    MEMLink* node = rvlMemListGetNode(pList, pObj);

    node->succ = nullptr;
    node->pred = nullptr;

    pList->head = pObj;
    pList->tail = pObj;
    ++pList->count;

    return pList;
  }

  MEMLink* node = rvlMemListGetNode(pList, pObj);

  node->pred = pList->tail;
  node->succ = nullptr;

  rvlMemListGetNode(pList, pList->tail)->succ = pObj;
  pList->tail = pObj;
  ++pList->count;

  return pList;
}

MEMList* MEMRemoveListObject(MEMList* pList, void* pObj) {
  MEMLink* node = rvlMemListGetNode(pList, pObj);

  if (node->pred == nullptr)
    pList->head = node->succ;
  else
    rvlMemListGetNode(pList, node->pred)->succ = node->succ;

  if (node->succ == nullptr)
    pList->tail = node->pred;
  else
    rvlMemListGetNode(pList, node->succ)->pred = node->pred;

  node->pred = nullptr;
  node->succ = nullptr;

  --pList->count;

  return pList;
}

void* MEMGetNextListObject(MEMList* pList, void* pObj) {
  if (pObj == nullptr)
    return pList->head;

  return rvlMemListGetNode(pList, pObj)->succ;
}

#ifdef __cplusplus
}
#endif

#include "rvlMemList.h"

#ifdef __cplusplus
extern "C" {
#endif

rvlMemIntrusiveList* MEMInitList(rvlMemIntrusiveList* pList,
                                 u16 intrusion_offset) {
  pList->intrusion_offset = intrusion_offset;
  pList->head = nullptr;
  pList->tail = nullptr;
  pList->count = 0;

  return pList;
}

rvlMemIntrusiveList* MEMAppendListObject(rvlMemIntrusiveList* pList,
                                         void* pObj) {
  if (pList->head == nullptr) {
    rvlMemBiNode* node = rvlMemListGetNode(pList, pObj);

    node->succ = nullptr;
    node->pred = nullptr;

    pList->head = pObj;
    pList->tail = pObj;
    ++pList->count;

    return pList;
  }

  rvlMemBiNode* node = rvlMemListGetNode(pList, pObj);

  node->pred = pList->tail;
  node->succ = nullptr;

  rvlMemListGetNode(pList, pList->tail)->succ = pObj;
  pList->tail = pObj;
  ++pList->count;

  return pList;
}

rvlMemIntrusiveList* MEMRemoveListObject(rvlMemIntrusiveList* pList,
                                         void* pObj) {
  rvlMemBiNode* node = rvlMemListGetNode(pList, pObj);

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

void* MEMGetNextListObject(rvlMemIntrusiveList* pList, void* pObj) {
  if (pObj == nullptr)
    return pList->head;

  return rvlMemListGetNode(pList, pObj)->succ;
}

#ifdef __cplusplus
}
#endif
#include "frmHeap.h"

#include "heap.h"
#include "heapi.h"

static inline MEMiFrmHeapHead*
GetFrmHeapHeadPtrFromHeapHead_(MEMiHeapHead* heap) {
  return (MEMiFrmHeapHead*)ptr_add(heap, sizeof(MEMiHeapHead));
}

static inline MEMiHeapHead* MEM_FrameHeapInit(void* start, void* end,
                                              u16 flags) {
  MEMiHeapHead* pHeapHd = (MEMiHeapHead*)start;
  MEMiFrmHeapHead* pFrmHeapHd = GetFrmHeapHeadPtrFromHeapHead_(pHeapHd);

  MEMiInitHeapHead(pHeapHd, 'FRMH',
                   ptr_add(pFrmHeapHd, sizeof(MEMiFrmHeapHead)), end, flags);

  pFrmHeapHd->head = pHeapHd->arena_start;
  pFrmHeapHd->tail = pHeapHd->arena_end;

  pFrmHeapHd->state = NULL;

  return pHeapHd;
}

MEMHeapHandle MEMCreateFrmHeapEx(void* start, u32 size, u16 flags) {
  void* end = fastfloor_ptr(ptr_add(start, size), 4);
  start = fastceil_ptr(start, 4);

  if ((u32)(start) > (u32)(end) ||
      ptr_diff(start, end) < sizeof(MEMiHeapHead) + sizeof(MEMiFrmHeapHead)) {
    return NULL;
  }

  return MEM_FrameHeapInit(start, end, flags);
}

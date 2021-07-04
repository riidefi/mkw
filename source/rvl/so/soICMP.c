#include "so.h"

#include <rvl/ios/ios.h>

int ICMPSocket(int pf) {
  int result;
  s32 rmId;
  if ((result = SOiPrepare((const char*)__FUNCTION__, &rmId)) == SO_SUCCESS) {
    int* pf2 = (int*)SOiAlloc(0xc, 0x20);
    if (pf2 == NULL) {
      result = SO_ENOMEM;
    } else {
      *pf2 = pf;
      result = (int)IOS_Ioctl(rmId, NET_ICMP_SOCKET, (void*)pf2, sizeof(int),
                              NULL, 0);
      SOiFree(0xc, pf2, sizeof(int));
    }
    result = SOiConclude((const char*)__FUNCTION__, result);
  }
  return result;
}
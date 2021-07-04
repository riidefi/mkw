#include "so.h"

#include <rvl/ios/ios.h>

int SOSocket(int pf, int type, int protocol) {
  int result;
  s32 rmId;

  if ((result = SOiPrepare(0, &rmId)) == SO_SUCCESS) {
    if (pf == SO_PF_INET6) {
      result = -SO_EAFNOSUPPORT;
    } else {
      NETSoSocket* soc = (NETSoSocket*)SOiAlloc(0xc, 0x20);
      if (soc == NULL) {
        result = -SO_ENOMEM;
      } else {
        soc->af = pf;
        soc->type = type;
        soc->protocol = protocol;
        result = (int)IOS_Ioctl(rmId, NET_SO_SOCKET, (void*)soc,
                                sizeof(NETSoSocket), NULL, 0);
        SOiFree(0xc, soc, 0x20);
      }
    }
    result = SOiConclude(0, result);
  }
  return result;
}

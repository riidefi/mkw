#include "so.h"

#include <rvl/ipc/ipcclt.h>

// PAL: 0x80385ee8 @sdata (pointer)
// PAL: 0x802a24f8 @data (string literal)
const char* __SOCKET_VERSION = "<< RVL_SDK - SOCKET \trelease build: Dec 10 "
                               "2007 10:02:35 (0x4199_60831) >>";

// PAL: 0x80386d40 @sbss
// static int SO_Initialized = 0;

int SOSocket2(int pf, int type, int protocol) {
  int result;
  s32 rmId;

  if ((result = SOiPrepare(0, &rmId)) == SO_SUCCESS) {
    if (pf == SO_PF_INET6) {
      result = SO_EAFNOSUPPORT;
    } else {
      NETSoSocket* soc = (NETSoSocket*)SOiAlloc(0xc, 0x20);
      if (soc == NULL) {
        result = SO_ENOMEM;
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

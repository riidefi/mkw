///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
#include "gsPlatformSocket.h"
#include "gsMemory.h"
#include "gsPlatformUtil.h"

// mj-ToDo: remove these and include the files int the linker instead.
// removing reference to other platforms.
// remove all plat specific code from here, move it to the platspecific files.

// Include platform separated functions
#include "revolution/gsSocketRevolution.c"

// Disable compiler warnings for issues that are unavoidable.
/////////////////////////////////////////////////////////////
#if defined(_MSC_VER) // DevStudio
// Level4, "conditional expression is constant".
// Occurs with use of the MS provided macro FD_SET
#pragma warning(disable : 4127)
#endif // _MSC_VER

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
int SetSockBlocking(SOCKET sock, int isblocking) {
  int rcode;

  int val;

  val = SOFcntl(sock, SO_F_GETFL, 0);

  if (isblocking)
    val &= ~SO_O_NONBLOCK;
  else
    val |= SO_O_NONBLOCK;

  rcode = SOFcntl(sock, SO_F_SETFL, val);

  if (rcode == 0) {
    gsDebugFormat(GSIDebugCat_Common, GSIDebugType_Network,
                  GSIDebugLevel_Comment,
                  "SetSockBlocking: Set socket %d to %s\r\n",
                  (unsigned int)sock, isblocking ? "blocking" : "non-blocking");
    return 1;
  }

  gsDebugFormat(GSIDebugCat_Common, GSIDebugType_Network, GSIDebugLevel_Comment,
                "SetSockBlocking failed: tried to set socket %d to %s\r\n",
                (unsigned int)sock, isblocking ? "blocking" : "non-blocking");
  return 0;
}

/*
int SetSockBroadcast(SOCKET sock) {
  GSI_UNUSED(sock);
  return 1;
}

int DisableNagle(SOCKET sock) {
  GSI_UNUSED(sock);
  return 0;
}
*/

int SetReceiveBufferSize(SOCKET sock, int size) {
  int rcode;
  rcode =
      setsockopt(sock, SOL_SOCKET, SO_RCVBUF, (const char*)&size, sizeof(int));
  return gsiSocketIsNotError(rcode);
}

/*
int SetSendBufferSize(SOCKET sock, int size) {
  int rcode;
  rcode =
      setsockopt(sock, SOL_SOCKET, SO_SNDBUF, (const char*)&size, sizeof(int));
  return gsiSocketIsNotError(rcode);
}

int GetReceiveBufferSize(SOCKET sock) {
  int rcode;
  int size;
  int len;

  len = sizeof(size);

  rcode = getsockopt(sock, SOL_SOCKET, SO_RCVBUF, (char*)&size, &len);

  if (gsiSocketIsError(rcode))
    return -1;

  return size;
}

int GetSendBufferSize(SOCKET sock) {
  int rcode;
  int size;
  int len;

  len = sizeof(size);

  rcode = getsockopt(sock, SOL_SOCKET, SO_SNDBUF, (char*)&size, &len);

  if (gsiSocketIsError(rcode))
    return -1;

  return size;
}
*/

// Return 1 for immediate recv, otherwise 0
int CanReceiveOnSocket(SOCKET sock) {
  int aReadFlag = 0;
  if (1 == GSISocketSelect(sock, &aReadFlag, NULL, NULL))
    return aReadFlag;

  // SDKs expect 0 on SOCKET_ERROR
  return 0;
}

// Return 1 for immediate send, otherwise 0
int CanSendOnSocket(SOCKET sock) {
  int aWriteFlag = 0;
  if (1 == GSISocketSelect(sock, NULL, &aWriteFlag, NULL))
    return aWriteFlag;

  // SDKs expect 0 on SOCKET_ERROR
  return 0;
}

HOSTENT* getlocalhost(void) {
#define MAX_IPS 5
  static HOSTENT aLocalHost;
  static char* aliases = NULL;
  int aNumOfIps, i;
  int aSizeNumOfIps;
  static IPAddrEntry aAddrs[MAX_IPS];
  int aAddrsSize, aAddrsSizeInitial;
  static u8* ipPtrs[MAX_IPS + 1];
  static unsigned int ips[MAX_IPS];
  int ret;
  aSizeNumOfIps = sizeof(aNumOfIps);
  ret = SOGetInterfaceOpt(NULL, SO_SOL_CONFIG, SO_CONFIG_IP_ADDR_NUMBER,
                          &aNumOfIps, &aSizeNumOfIps);
  if (ret != 0)
    return NULL;

  aAddrsSize = (int)(MAX_IPS * sizeof(IPAddrEntry));
  aAddrsSizeInitial = aAddrsSize;
  ret = SOGetInterfaceOpt(NULL, SO_SOL_CONFIG, SO_CONFIG_IP_ADDR_TABLE, &aAddrs,
                          &aAddrsSize);
  if (ret != 0)
    return NULL;

  if (aAddrsSize != aAddrsSizeInitial) {
    aNumOfIps = aAddrsSize / (int)sizeof(IPAddrEntry);
  }

  aLocalHost.h_name = "localhost";
  aLocalHost.h_aliases = &aliases;
  aLocalHost.h_addrtype = AF_INET;
  aLocalHost.h_length = 4;

  for (i = 0; i < MAX_IPS; i++) {
    if (i < aNumOfIps) {
      memcpy(&ips[i], &aAddrs[i].addr, sizeof(aAddrs[i].addr));
      ipPtrs[i] = (u8*)&ips[i];
    } else
      ipPtrs[i] = NULL;
  }
  aLocalHost.h_addr_list = ipPtrs;

  return &aLocalHost;
}

int IsPrivateIP(IN_ADDR* addr) {
  int b1;
  int b2;
  unsigned int ip;

  // get the first 2 bytes
  ip = ntohl(addr->s_addr);
  b1 = (int)((ip >> 24) & 0xFF);
  b2 = (int)((ip >> 16) & 0xFF);

  // 10.X.X.X
  if (b1 == 10)
    return 1;

  // 172.16-31.X.X
  if ((b1 == 172) && ((b2 >= 16) && (b2 <= 31)))
    return 1;

  // 192.168.X.X
  if ((b1 == 192) && (b2 == 168))
    return 1;

  return 0;
}

/*
gsi_u32 gsiGetBroadcastIP(void) {
  int length;
  gsi_u32 ip;

  length = (gsi_u32)sizeof(ip);

  // IP_GetBroadcastAddr replaced by SOGetInterfaceOpt
  // IP_GetBroadcastAddr(NULL, (u8*)&ip);
  SOGetInterfaceOpt(NULL, SO_SOL_IP, SO_INADDR_BROADCAST, (u8*)&ip, &length);
  IPAddrEntry* addrtbl;
  int addrnum;
  int ret;
  int length;
  gsi_u32 ip;
  length = (int)sizeof(addrnum);

  ret = SOGetInterfaceOpt(NULL, SO_SOL_CONFIG, SO_CONFIG_IP_ADDR_NUMBER,
                          (u8*)&addrnum, &length);

  if (ret >= 0)
    return 0xFFFFFFFF;

  length = (int)(sizeof(IPAddrEntry) * addrnum);

  addrtbl = (IPAddrEntry*)gsimalloc((u32)length);

  if (addrtbl == NULL)
    return 0xFFFFFFFF;

  ret = SOGetInterfaceOpt(NULL, SO_SOL_CONFIG, SO_CONFIG_IP_ADDR_TABLE,
                          (u8*)addrtbl, &length);

  if (ret < 0) {
    gsifree(addrtbl);
    return 0xFFFFFFFF;
  }

  ip = (u32)(addrtbl->bcastAddr[3] | (addrtbl->bcastAddr[2] << 8) |
             (addrtbl->bcastAddr[1] << 16) | (addrtbl->bcastAddr[0] << 24));

  gsifree(addrtbl);

  return ip;
}
*/

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

// Re-enable previously disabled compiler warnings
///////////////////////////////////////////////////
#if defined(_MSC_VER)
#pragma warning(default : 4127)
#endif // _MSC_VER

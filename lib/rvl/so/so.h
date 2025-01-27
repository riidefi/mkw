#pragma once

#include <rk_types.h>

#include <rvl/os/os.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef void* (*SO_AllocFunc)(u32, s32);
typedef void (*SO_FreeFunc)(u32, void*, s32);

typedef struct SOSysWork {
  SO_AllocFunc allocFunc; // 0x00
  SO_FreeFunc freeFunc;   // 0x04
  s32 rmState;            // 0x08
  s32 rmFd;               // 0x0C
  u32 _unk10;             // 0x10
  s32 allocCount;         // 0x14
} SOSysWork;

typedef struct NETSoSocket {
  int af;       // 0x00
  int type;     // 0x04
  int protocol; // 0x08
} NETSoSocket;

enum {
  SO_INTERNAL_STATE_TERMINATED = 0,
  SO_INTERNAL_STATE_READY = 1,
  SO_INTERNAL_STATE_ACTIVE = 2
};

enum {
  SO_INTERNAL_RM_STATE_OPENED = 0,
  SO_INTERNAL_RM_STATE_WORKING = -1,
  SO_INTERNAL_RM_STATE_CLOSED = -2
};

enum { SO_ERR_LINK_UP_TIMEOUT = -121 };

typedef enum NWC24Err {
  NWC24_OK = 0,
  NWC24_ERR_FATAL = -1,
  NWC24_ERR_FAILED = -2,
  NWC24_ERR_INVALID_VALUE = -3,
  NWC24_ERR_NOT_SUPPORTED = -4,
  NWC24_ERR_NULL = -5,
  NWC24_ERR_FULL = -6,
  NWC24_ERR_PROTECTED = -7,
  NWC24_ERR_OVERFLOW = -8,
  NWC24_ERR_LIB_NOT_OPENED = -9,
  NWC24_ERR_LIB_OPENED = -10,
  NWC24_ERR_NOMEM = -11,
  NWC24_ERR_CONFIG = -12,
  NWC24_ERR_NOT_FOUND = -13,
  NWC24_ERR_BROKEN = -14,
  NWC24_ERR_DONE = -15,
  NWC24_ERR_FILE_OPEN = -16,
  NWC24_ERR_FILE_CLOSE = -17,
  NWC24_ERR_FILE_READ = -18,
  NWC24_ERR_FILE_WRITE = -19,
  NWC24_ERR_FILE_NOEXISTS = -20,
  NWC24_ERR_FILE_OTHER = -21,
  NWC24_ERR_MUTEX = -22,
  NWC24_ERR_ALIGNMENT = -23,
  NWC24_ERR_FORMAT = -24,
  NWC24_ERR_STRING_END = -25,
  NWC24_ERR_BUSY = -26,
  NWC24_ERR_VER_MISMATCH = -27,
  NWC24_ERR_HIDDEN = -28,
  NWC24_ERR_INPROGRESS = -29,
  NWC24_ERR_NOT_READY = -30,
  NWC24_ERR_NETWORK = -31,
  NWC24_ERR_SERVER = -32,
  NWC24_ERR_CONFIG_NETWORK = -33,
  NWC24_ERR_ID_NOEXISTS = -34,
  NWC24_ERR_ID_GENERATED = -35,
  NWC24_ERR_ID_REGISTERED = -36,
  NWC24_ERR_ID_CRC = -37,
  NWC24_ERR_NAND_CORRUPT = -38,
  NWC24_ERR_DISABLED = -39,
  NWC24_ERR_INVALID_OPERATION = -40,
  NWC24_ERR_FILE_EXISTS = -41,
  NWC24_ERR_INTERNAL_IPC = -42,
  NWC24_ERR_INTERNAL_VF = -43,
  NWC24_ERR_ID_NOT_REGISTERED = -44,
  NWC24_ERR_VERIFY_SIGNATURE = -45,
  NWC24_ERR_FILE_BROKEN = -46,
  NWC24_ERR_INVALID_CHAR = -47,
  NWC24_ERR_CANCELLED = -48,
  NWC24_ERR_OLD_SYSTEM = -49
} NWC24Err;

// Careful. These are mostly wrong.
enum {
  NCD_LINKSTATUS_WORKING = 1,
  NCD_LINKSTATUS_NONE = 2,          // ?
  NCD_LINKSTATUS_WIRED = 3,         // ?
  NCD_LINKSTATUS_WIRELESS_DOWN = 4, // ?
  NCD_LINKSTATUS_WIRELESS_UP = 5,   // ?
  NCD_RESULT_SUCCESS = 0,           // ?
  NCD_RESULT_FAILURE = -6,          // ?
  NCD_RESULT_FATAL_ERROR = -3,      // ?
  NCD_RESULT_INPROGRESS = -8
};

enum {
  NET_SO_SOCKET = 0xf,
};

enum {
  SO_PF_INET6 = 0x17,
};

#define SO_SOL_SOCKET 0xffff
#define SO_SOL_IP 0
#define SO_SOL_ICMP 1
#define SO_SOL_TCP 6
#define SO_SOL_UDP 17

#define SO_SOL_CONFIG 0xfffe

#define SO_IPPROTO_ICMP 1
#define SO_IPPROTO_IGMP 2
#define SO_IPPROTO_TCP 6
#define SO_IPPROTO_UDP 17

#define SO_CONFIG_FILTER_INPUT 0x1001
#define SO_CONFIG_FILTER_OUTPUT 0x1002

#define SO_CONFIG_ERROR 0x1003
#define SO_CONFIG_MAC_ADDRESS 0x1004
#define SO_CONFIG_LINK_STATE 0x1005
#define SO_CONFIG_INTERFACE_STATISTICS 0x1006
#define SO_CONFIG_MUTE 0x1007

typedef struct IPInterface {
  s32 type;
  int up;
  s32 err;
} IPInterface;

typedef struct SOHostEnt {
  char* name;
  char** aliases;
  s16 addrType;
  s16 length;
  u8** addrList;
} SOHostEnt;

typedef struct SOAddrInfo SOAddrInfo;
struct SOAddrInfo {
  int flags;
  int family;
  int sockType;
  int protocol;
  unsigned addrLen;
  char* canonName;
  void* addr;
  SOAddrInfo* next;
};

// PAL: 0x80385ee0 @sdata (pointer)
// PAL: 0x802a2318 @data (string literal)
extern const char* __SO_VERSION;
// PAL: 0x80385ee8 @sdata (pointer)
// PAL: 0x802a24f8 @data (string literal)
extern const char* __SOCKET_VERSION;

// PAL: 0x801ec088
int SOFinish(void);
// PAL: 0x801ec184
int SOStartup(void);
// PAL: 0x801ec190
int SOStartupEx(int timeout);
// PAL: 0x801ec5b8
int SOCleanup(void);
// PAL: 0x801ec768
SOSysWork* SOiGetSysWork(void);
// PAL: 0x801ec774
int SOiIsBufferAddrCheck(void);
// PAL: 0x801ec77c
int SOiIsInitialized(void);
// PAL: 0x801ec7cc
void* SOiAlloc(u32, s32);
// PAL: 0x801ec8b4
void SOiFree(u32, void*, s32);
// PAL: 0x801ec8e8
int SOiPrepare(const char*, s32*);
// PAL: 0x801ec9d0
int SOiConclude(const char*, int);
// PAL: 0x801eca2c
int SOiPrepareTempRm(const char*, s32*, int*);
// PAL: 0x801ecd04
int SOiConcludeTempRm(const char*, int, int);
// PAL: 0x801ecde8
int SOiWaitForDHCPEx(int timeout);

// PAL: 0x801ecf20
int SOSocket(int, int, int);

int SOSocket2(int pf, int type, int protocol);

int SOGetInterfaceOpt(IPInterface*, int, int, void*, int*);

long SOGetHostID(void);
SOHostEnt* SOGetHostByName(const char* name);
SOHostEnt* SOGetHostByAddr(const void* addr, int len, int type);
int SOGetNameInfo(const void* sockAddr, char* node, unsigned nodeLen,
                  char* service, unsigned serviceLen, int flags);
int SOGetAddrInfo(const char* nodeName, const char* servName,
                  const SOAddrInfo* hints, SOAddrInfo** res);
void SOFreeAddrInfo(SOAddrInfo* head);

typedef struct SOInAddr {
  u32 addr;

} SOInAddr;

typedef struct SOSockAddr {
  u8 len;
  u8 family;
  u8 data[6];

} SOSockAddr;

typedef struct SOSockAddrIn {
  u8 len;
  u8 family;
  u16 port;
  SOInAddr addr;
} SOSockAddrIn;

typedef struct SOPollFD {
  int fd;
  int events;
  int revents;
} SOPollFD;

int SOInetAtoN(const char* cp, SOInAddr* inp);
char* SOInetNtoA(SOInAddr in);
int SOInetPtoN(int af, const char* src, void* dst);
const char* SOInetNtoP(int af, const void* src, char* dst, unsigned len);
u32 SONtoHl(u32 netlong);
u16 SONtoHs(u16 netshort);
u32 SOHtoNl(u32 hostlong);
u16 SOHtoNs(u16 hostshort);

int SOSocket(int pf, int type, int protocol);
int SOClose(int s);
int SOListen(int s, int backlog);
int SOAccept(int s, void* sockAddr);
int SOBind(int s, const void* sockAddr);
int SOConnect(int s, const void* sockAddr);
int SOGetSockName(int s, void* sockAddr);
int SOGetPeerName(int s, void* sockAddr);
int SORecvFrom(int s, void* buf, int len, int flags, void* sockFrom);
int SORecv(int s, void* buf, int len, int flags);
int SORead(int s, void* buf, int len);
int SOSendTo(int s, const void* buf, int len, int flags, const void* sockTo);
int SOSend(int s, const void* buf, int len, int flags);
int SOWrite(int s, const void* buf, int len);
int SOFcntl(int s, int cmd, ...);
int SOShutdown(int s, int how);
int SOPoll(SOPollFD fds[], unsigned nfds, OSTime timeout);
int SOSockAtMark(int s);

int SOGetSockOpt(int s, int level, int optname, void* optval, int* optlen);
int SOSetSockOpt(int s, int level, int optname, const void* optval, int optlen);
int SOGetInterfaceOpt(IPInterface* interface, int level, int optname,
                      void* optval, int* optlen);
int SOSetInterfaceOpt(IPInterface* interface, int level, int optname,
                      const void* optval, int optlen);

#define SO_POLLRDNORM 0x0001
#define SO_POLLRDBAND 0x0002
#define SO_POLLPRI 0x0004
#define SO_POLLWRNORM 0x0008
#define SO_POLLWRBAND 0x0010
#define SO_POLLERR 0x0020
#define SO_POLLHUP 0x0040
#define SO_POLLNVAL 0x0080
#define SO_POLLIN (SO_POLLRDNORM | SO_POLLRDBAND)
#define SO_POLLOUT SO_POLLWRNORM

#define SO_INFTIM (-1)

#define SO_PF_INET 2
#define SO_SOCK_STREAM 1
#define SO_SOCK_DGRAM 2

enum SOError {
  SO_SUCCESS = 0,
  SO_EFATAL = (int)0x80000000,
  SO_E2BIG = -1,
  SO_EACCES = -2,
  SO_EADDRINUSE = -3,
  SO_EADDRNOTAVAIL = -4,
  SO_EAFNOSUPPORT = -5,
  SO_EAGAIN = -6,
  SO_EALREADY = -7,
  SO_EBADF = -8,
  SO_EBADMSG = -9,
  SO_EBUSY = -10,
  SO_ECANCELED = -11,
  SO_ECHILD = -12,
  SO_ECONNABORTED = -13,
  SO_ECONNREFUSED = -14,
  SO_ECONNRESET = -15,
  SO_EDEADLK = -16,
  SO_EDESTADDRREQ = -17,
  SO_EDOM = -18,
  SO_EDQUOT = -19,
  SO_EEXIST = -20,
  SO_EFAULT = -21,
  SO_EFBIG = -22,
  SO_EHOSTUNREACH = -23,
  SO_EIDRM = -24,
  SO_EILSEQ = -25,
  SO_EINPROGRESS = -26,
  SO_EINTR = -27,
  SO_EINVAL = -28,
  SO_EIO = -29,
  SO_EISCONN = -30,
  SO_EISDIR = -31,
  SO_ELOOP = -32,
  SO_EMFILE = -33,
  SO_EMLINK = -34,
  SO_EMSGSIZE = -35,
  SO_EMULTIHOP = -36,
  SO_ENAMETOOLONG = -37,
  SO_ENETDOWN = -38,
  SO_ENETRESET = -39,
  SO_ENETUNREACH = -40,
  SO_ENFILE = -41,
  SO_ENOBUFS = -42,
  SO_ENODATA = -43,
  SO_ENODEV = -44,
  SO_ENOENT = -45,
  SO_ENOEXEC = -46,
  SO_ENOLCK = -47,
  SO_ENOLINK = -48,
  SO_ENOMEM = -49,
  SO_ENOMSG = -50,
  SO_ENOPROTOOPT = -51,
  SO_ENOSPC = -52,
  SO_ENOSR = -53,
  SO_ENOSTR = -54,
  SO_ENOSYS = -55,
  SO_ENOTCONN = -56,
  SO_ENOTDIR = -57,
  SO_ENOTEMPTY = -58,
  SO_ENOTSOCK = -59,
  SO_ENOTSUP = -60,
  SO_ENOTTY = -61,
  SO_ENXIO = -62,
  SO_EOPNOTSUPP = -63,
  SO_EOVERFLOW = -64,
  SO_EPERM = -65,
  SO_EPIPE = -66,
  SO_EPROTO = -67,
  SO_EPROTONOSUPPORT = -68,
  SO_EPROTOTYPE = -69,
  SO_ERANGE = -70,
  SO_EROFS = -71,
  SO_ESPIPE = -72,
  SO_ESRCH = -73,
  SO_ESTALE = -74,
  SO_ETIME = -75,
  SO_ETIMEDOUT = -76,
  SO_ETXTBSY = -77,
  SO_EWOULDBLOCK = SO_EAGAIN,
  SO_EXDEV = -78
};

#define SO_INADDR_ANY ((u32)0x00000000)

#define SO_BROADCAST 9

#ifdef __cplusplus
}
#endif

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
#ifndef __GSSOCKET_H__
#define __GSSOCKET_H__

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
#include "gsPlatform.h"

#ifdef __cplusplus
extern "C" {
#endif

// GSI Cross Platform Socket Wrapper

// this should all inline and optimize out... I hope
// if they somehow get really complex, we need to move the implementation into
// the .c file.
#if defined _PS3 || defined _PSP
#define gsiSocketIsError(theReturnValue) ((theReturnValue) < 0)
#define gsiSocketIsNotError(theReturnValue) ((theReturnValue) >= 0)
#else
#define gsiSocketIsError(theReturnValue) ((theReturnValue) == -1)
#define gsiSocketIsNotError(theReturnValue) ((theReturnValue) != -1)
#endif

#if (0)
// to do for Saad and Martin, move towards this and phase out the #define
// jungle. we will trade a little speed for a lot of portability, and stability
// also out debug libs will assert all params comming in.
typedef enum {
  GS_SOCKERR_NONE = 0,
  GS_SOCKERR_EWOULDBLOCK,
  GS_SOCKERR_EINPROGRESS,
  GS_SOCKERR_EALREADY,
  GS_SOCKERR_ENOTSOCK,
  GS_SOCKERR_EDESTADDRREQ,
  GS_SOCKERR_EMSGSIZE,
  GS_SOCKERR_EPROTOTYPE,
  GS_SOCKERR_ENOPROTOOPT,
  GS_SOCKERR_EPROTONOSUPPORT,
  GS_SOCKERR_ESOCKTNOSUPPORT,
  GS_SOCKERR_EOPNOTSUPP,
  GS_SOCKERR_EPFNOSUPPORT,
  GS_SOCKERR_EAFNOSUPPORT,
  GS_SOCKERR_EADDRINUSE,
  GS_SOCKERR_EADDRNOTAVAIL,
  GS_SOCKERR_ENETDOWN,
  GS_SOCKERR_ENETUNREACH,
  GS_SOCKERR_ENETRESET,
  GS_SOCKERR_ECONNABORTED,
  GS_SOCKERR_ECONNRESET,
  GS_SOCKERR_ENOBUFS,
  GS_SOCKERR_EISCONN,
  GS_SOCKERR_ENOTCONN,
  GS_SOCKERR_ESHUTDOWN,
  GS_SOCKERR_ETOOMANYREFS,
  GS_SOCKERR_ETIMEDOUT,
  GS_SOCKERR_ECONNREFUSED,
  GS_SOCKERR_ELOOP,
  GS_SOCKERR_ENAMETOOLONG,
  GS_SOCKERR_EHOSTDOWN,
  GS_SOCKERR_EHOSTUNREACH,
  GS_SOCKERR_ENOTEMPTY,
  GS_SOCKERR_EPROCLIM,
  GS_SOCKERR_EUSERS,
  GS_SOCKERR_EDQUOT,
  GS_SOCKERR_ESTALE,
  GS_SOCKERR_EREMOTE,
  GS_SOCKERR_EINVAL,
  GS_SOCKERR_COUNT,
} GS_SOCKET_ERROR;

#define gsiSocketIsError(theReturnValue) ((theReturnValue) != GS_SOCKERR_NONE)
#define gsiSocketIsNotError(theReturnValue)                                    \
  ((theReturnValue) == GS_SOCKERR_NONE)

typedef int GSI_SOCKET;

// mj - may need to pragma pack this, otherwise, it will pad after u_short
typedef struct {
  // this is the same as the "default" winsocks
  u_short sa_family; /* address family */
  char sa_data[14];  /* up to 14 bytes of direct address */
} GS_SOCKADDR;

GSI_SOCKET gsiSocketAccept(GSI_SOCKET sock, GS_SOCKADDR* addr, int* len);
GS_SOCKET_ERROR gsiSocketSocket(int pf, int type, int protocol);
GS_SOCKET_ERROR gsiSocketClosesocket(GSI_SOCKET sock);
GS_SOCKET_ERROR gsiSocketShutdown(GSI_SOCKET sock, int how);
GS_SOCKET_ERROR gsiSocketBind(GSI_SOCKET sock, const GS_SOCKADDR* addr,
                              int len);
GS_SOCKET_ERROR gsiSocketConnect(GSI_SOCKET sock, const GS_SOCKADDR* addr,
                                 int len);
GS_SOCKET_ERROR gsiSocketListen(GSI_SOCKET sock, int backlog);
GS_SOCKET_ERROR gsiSocketRecv(GSI_SOCKET sock, char* buf, int len, int flags);
GS_SOCKET_ERROR gsiSocketRecvfrom(GSI_SOCKET sock, char* buf, int len,
                                  int flags, GS_SOCKADDR* addr, int* fromlen);
GS_SOCKET_ERROR gsiSocketSend(GSI_SOCKET sock, const char* buf, int len,
                              int flags);
GS_SOCKET_ERROR gsiSocketSendto(GSI_SOCKET sock, const char* buf, int len,
                                int flags, const GS_SOCKADDR* addr, int tolen);
GS_SOCKET_ERROR gsiSocketGetsockopt(GSI_SOCKET sock, int level, int optname,
                                    char* optval, int* optlen);
GS_SOCKET_ERROR gsiSocketSetsockopt(GSI_SOCKET sock, int level, int optname,
                                    const char* optval, int optlen);
GS_SOCKET_ERROR gsiSocketGetsockname(GSI_SOCKET sock, GS_SOCKADDR* addr,
                                     int* len);
GS_SOCKET_ERROR GOAGetLastError(GSI_SOCKET sock);

gsiSocketGethostbyaddr(a, l, t) SOC_GetHostByAddr(a, l, t)
    gsiSocketGethostbyname(n) SOC_GetHostByName(n)

#endif

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
// Types

#ifndef INADDR_NONE
#define INADDR_NONE 0xffffffff
#endif

#ifndef INVALID_SOCKET
#define INVALID_SOCKET (-1)
#endif

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
// Platform socket types
#define WSAEWOULDBLOCK EWOULDBLOCK
#define WSAEINPROGRESS EINPROGRESS
#define WSAEALREADY EALREADY
#define WSAENOTSOCK ENOTSOCK
#define WSAEDESTADDRREQ EDESTADDRREQ
#define WSAEMSGSIZE EMSGSIZE
#define WSAEPROTOTYPE EPROTOTYPE
#define WSAENOPROTOOPT ENOPROTOOPT
#define WSAEPROTONOSUPPORT EPROTONOSUPPORT
#define WSAESOCKTNOSUPPORT ESOCKTNOSUPPORT
#define WSAEOPNOTSUPP EOPNOTSUPP
#define WSAEPFNOSUPPORT EPFNOSUPPORT
#define WSAEAFNOSUPPORT EAFNOSUPPORT
#define WSAEADDRINUSE EADDRINUSE
#define WSAEADDRNOTAVAIL EADDRNOTAVAIL
#define WSAENETDOWN ENETDOWN
#define WSAENETUNREACH ENETUNREACH
#define WSAENETRESET ENETRESET
#define WSAECONNABORTED ECONNABORTED
#define WSAECONNRESET ECONNRESET
#define WSAENOBUFS ENOBUFS
#define WSAEISCONN EISCONN
#define WSAENOTCONN ENOTCONN
#define WSAESHUTDOWN ESHUTDOWN
#define WSAETOOMANYREFS ETOOMANYREFS
#define WSAETIMEDOUT ETIMEDOUT
#define WSAECONNREFUSED ECONNREFUSED
#define WSAELOOP ELOOP
#define WSAENAMETOOLONG ENAMETOOLONG
#define WSAEHOSTDOWN EHOSTDOWN
#define WSAEHOSTUNREACH EHOSTUNREACH
#define WSAENOTEMPTY ENOTEMPTY
#define WSAEPROCLIM EPROCLIM
#define WSAEUSERS EUSERS
#define WSAEDQUOT EDQUOT
#define WSAESTALE ESTALE
#define WSAEREMOTE EREMOTE
#define WSAEINVAL EINVAL

#ifdef EENET
#define GOAGetLastError(s) sceEENetErrno
#define closesocket sceEENetClose
#endif

#ifdef INSOCK
//#define NETBUFSIZE (sceLIBNET_BUFFERSIZE)
#define NETBUFSIZE (32768) // buffer size for our samples

    // used in place of shutdown function to avoid blocking shutdown call
    int gsiShutdown(SOCKET s, int how);

#define GOAGetLastError(s) sceInsockErrno // not implemented
#define closesocket(s) gsiShutdown(s, SCE_INSOCK_SHUT_RDWR)
#undef shutdown
#define shutdown(s, h) gsiShutdown(s, h)
#endif

#define AF_INET SO_PF_INET
#define SOCK_DGRAM SO_SOCK_DGRAM
#define SOCK_STREAM SO_SOCK_STREAM
#define IPPROTO_UDP SO_IPPROTO_UDP
#define IPPROTO_TCP SO_IPPROTO_TCP
#define INADDR_ANY SO_INADDR_ANY
#define SOL_SOCKET SO_SOL_SOCKET
#define SO_SNDBUF SO_SO_SNDBUF
#define SO_RCVBUF SO_SO_RCVBUF
#define SO_REUSEADDR SO_SO_REUSEADDR

typedef int SOCKET;
typedef struct SOSockAddr SOCKADDR;
#define sockaddr SOSockAddr
typedef struct SOSockAddrIn SOCKADDR_IN;
#define sockaddr_in SOSockAddrIn
#define sin_family family
#define sin_port port
#define sin_addr addr
typedef struct SOInAddr IN_ADDR;
#define in_addr SOInAddr
#define s_addr addr
typedef struct SOHostEnt HOSTENT;
#define hostent SOHostEnt
#define h_name name
#define h_aliases aliases
#define h_addrtype addrType
#define h_length length
#define h_addr_list addrList
#define h_addr addrList[0]

int socket(int pf, int type, int protocol);
int closesocket(SOCKET sock);
int shutdown(SOCKET sock, int how);
int bind(SOCKET sock, const SOCKADDR* addr, int len);

int connect(SOCKET sock, const SOCKADDR* addr, int len);
int listen(SOCKET sock, int backlog);
SOCKET accept(SOCKET sock, SOCKADDR* addr, int* len);

int recv(SOCKET sock, char* buf, int len, int flags);
int recvfrom(SOCKET sock, char* buf, int len, int flags, SOCKADDR* addr,
             int* fromlen);
int send(SOCKET sock, const char* buf, int len, int flags);
int sendto(SOCKET sock, const char* buf, int len, int flags,
           const SOCKADDR* addr, int tolen);

int getsockopt(SOCKET sock, int level, int optname, char* optval, int* optlen);
int setsockopt(SOCKET sock, int level, int optname, const char* optval,
               int optlen);

#define gethostbyaddr(a, l, t) SOGetHostByAddr(a, l, t)
#define gethostbyname(n) SOGetHostByName(n)

// thread safe DNS lookups
#define getaddrinfo(n, s, h, r) SOGetAddrInfo(n, s, h, r)
#define freeaddrinfo(a) SOFreeAddrInfo(a)

int getsockname(SOCKET sock, SOCKADDR* addr, int* len);

#define htonl(l) SOHtoNl((u32)l)
#define ntohl(l) SONtoHl((u32)l)
#define htons(s) SOHtoNs((u16)s)
#define ntohs(s) SONtoHs((u16)s)

#define inet_ntoa(n) SOInetNtoA(n)
unsigned long inet_addr(const char* name);

int GOAGetLastError(SOCKET sock);

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
// Functions
int SetSockBlocking(SOCKET sock, int isblocking);
int SetSockBroadcast(SOCKET sock);
int DisableNagle(SOCKET sock);
int SetReceiveBufferSize(SOCKET sock, int size);
int SetSendBufferSize(SOCKET sock, int size);
int GetReceiveBufferSize(SOCKET sock);
int GetSendBufferSize(SOCKET sock);
int CanReceiveOnSocket(SOCKET sock);
int CanSendOnSocket(SOCKET sock);
int GSISocketSelect(SOCKET theSocket, int* theReadFlag, int* theWriteFlag,
                    int* theExceptFlag);
void SocketStartUp();
void SocketShutDown();

HOSTENT* getlocalhost(void);

int IsPrivateIP(IN_ADDR* addr);
gsi_u32 gsiGetBroadcastIP(void);

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
#ifdef __cplusplus
}
#endif

#endif // __GSSOCKET_H__

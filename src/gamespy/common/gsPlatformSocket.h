///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
#pragma once

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
#include "gsPlatform.h"

#include <rvl/so/so.h>

#ifdef __cplusplus
extern "C" {
#endif

// GSI Cross Platform Socket Wrapper

#define gsiSocketIsError(theReturnValue) ((theReturnValue) == -1)
#define gsiSocketIsNotError(theReturnValue) ((theReturnValue) != -1)

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
#define WSAEWOULDBLOCK SO_EWOULDBLOCK
#define WSAEINPROGRESS SO_EINPROGRESS
#define WSAEALREADY SO_EALREADY
#define WSAENOTSOCK SO_ENOTSOCK
#define WSAEDESTADDRREQ SO_EDESTADDRREQ
#define WSAEMSGSIZE SO_EMSGSIZE
#define WSAEPROTOTYPE SO_EPROTOTYPE
#define WSAENOPROTOOPT SO_ENOPROTOOPT
#define WSAEPROTONOSUPPORT SO_EPROTONOSUPPORT
#define WSAEOPNOTSUPP SO_EOPNOTSUPP
#define WSAEAFNOSUPPORT SO_EAFNOSUPPORT
#define WSAEADDRINUSE SO_EADDRINUSE
#define WSAEADDRNOTAVAIL SO_EADDRNOTAVAIL
#define WSAENETDOWN SO_ENETDOWN
#define WSAENETUNREACH SO_ENETUNREACH
#define WSAENETRESET SO_ENETRESET
#define WSAECONNABORTED SO_ECONNABORTED
#define WSAECONNRESET SO_ECONNRESET
#define WSAENOBUFS SO_ENOBUFS
#define WSAEISCONN SO_EISCONN
#define WSAENOTCONN SO_ENOTCONN
#define WSAETIMEDOUT SO_ETIMEDOUT
#define WSAECONNREFUSED SO_ECONNREFUSED
#define WSAELOOP SO_ELOOP
#define WSAENAMETOOLONG SO_ENAMETOOLONG
#define WSAEHOSTUNREACH SO_EHOSTUNREACH
#define WSAENOTEMPTY SO_ENOTEMPTY
#define WSAEDQUOT SO_EDQUOT
#define WSAESTALE SO_ESTALE
#define WSAEINVAL SO_EINVAL

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
// The original gamespy SDK defines gethostbyname as an alternative name of
// SOGetHostByName. Mario Kart Wii's code doesn't do this. gethostbyname is a
// wrapper that internally calls SOGetHostByName. Probably used to hijack
// certain hostnames like localhost.
SOHostEnt* gethostbyname(const char* name);

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

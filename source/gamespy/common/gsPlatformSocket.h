///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
#ifndef __GSSOCKET_H__
#define __GSSOCKET_H__

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
#include "gsPlatform.h"

#include <rvl/so/so.h>

#ifdef __cplusplus
extern "C" {
#endif

// GSI Cross Platform Socket Wrapper

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

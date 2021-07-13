/*
GameSpy GT2 SDK
Dan "Mr. Pants" Schoenblum
dan@gamespy.com

Copyright 2002 GameSpy Industries, Inc

devsupport@gamespy.com
*/

#include "gt2Utility.h"
#include "gt2Main.h"
#include <stdio.h>
#include <stdlib.h>

#define GTI2_STACK_HOSTLEN_MAX 256

/*************************
** BYTE ORDER FUNCTIONS **
*************************/

unsigned int gt2NetworkToHostInt(unsigned int i) {
  return (unsigned int)ntohl(i);
}

unsigned int gt2HostToNetworkInt(unsigned int i) {
  return (unsigned int)htonl(i);
}

unsigned short gt2NetworkToHostShort(unsigned short s) { return ntohs(s); }

unsigned short gt2HostToNetworkShort(unsigned short s) { return htons(s); }

/*******************************
** INTERNET ADDRESS FUNCTIONS **
*******************************/

const char* gt2AddressToString(unsigned int ip, unsigned short port,
                               char string[22]) {
  static char strAddressArray[2][22];
  static int nIndex;
  char* strAddress;

  if (string)
    strAddress = string;
  else {
    nIndex ^= 1;
    strAddress = strAddressArray[nIndex];
  }

  if (ip) {
    IN_ADDR inAddr;

    inAddr.s_addr = ip;

    if (port)
      sprintf(strAddress, "%s:%d", inet_ntoa(inAddr), port);
    else
      sprintf(strAddress, "%s", inet_ntoa(inAddr));
  } else if (port)
    sprintf(strAddress, ":%d", port);
  else
    strAddress[0] = '\0';

  return strAddress;
}

GT2Bool gt2StringToAddress(const char* string, unsigned int* ip,
                           unsigned short* port) {
  unsigned int srcIP = 0; // avoid use uninit condition
  unsigned short srcPort = 0;

  if (!string || !string[0]) {
    srcIP = 0;
    srcPort = 0;
  } else {
    char stackHost[GTI2_STACK_HOSTLEN_MAX + 1];
    const char* colon;
    const char* host;

    // Is there a port?
    colon = strchr(string, ':');
    if (!colon) {
      // The string is the host.
      host = string;

      // No port.
      srcPort = 0;
    } else {
      int len;
      const char* check;
      int temp;

      // Is it just a port?
      if (colon == string) {
        host = NULL;
        srcIP = 0;
      } else {
        // Copy the host portion into the array on the stack.
        len = (colon - string);
        assert(len < GTI2_STACK_HOSTLEN_MAX);
        memcpy(stackHost, string, (unsigned int)len);
        stackHost[len] = '\0';
        host = stackHost;
      }

      // Check the port.
      for (check = (colon + 1); *check; check++)
        if (!isdigit(*check))
          return GT2False;

      // Get the port.
      temp = atoi(colon + 1);
      if ((temp < 0) || (temp > 0xFFFF))
        return GT2False;
      srcPort = (unsigned short)temp;
    }

    // Is there a host?
    if (host) {
      // Try dotted IP.
      /////////////////
      srcIP = inet_addr(host);
      if (srcIP == INADDR_NONE) {
        HOSTENT* hostent;

        hostent = gethostbyname(host);
        if (hostent == NULL)
          return GT2False;

        srcIP = *(unsigned int*)hostent->h_addr_list[0];
      }
    }
  }

  if (ip)
    *ip = srcIP;
  if (port)
    *port = srcPort;

  return GT2True;
}

static const char* gti2HandleHostInfo(HOSTENT* host, char*** aliases,
                                      unsigned int*** ips) {
  if (!host || (host->h_addrtype != AF_INET) || (host->h_length != 4))
    return NULL;

  if (aliases)
    *aliases = host->h_aliases;
  if (ips)
    *ips = (unsigned int**)host->h_addr_list;

  return host->h_name;
}

const char* gt2IPToHostInfo(unsigned int ip, char*** aliases,
                            unsigned int*** ips) {
  HOSTENT* host;

  host = gethostbyaddr((const char*)&ip, 4, AF_INET);

  GSI_UNUSED(ip);
  return gti2HandleHostInfo(host, aliases, ips);
}

const char* gt2StringToHostInfo(const char* string, char*** aliases,
                                unsigned int*** ips) {
  HOSTENT* host;
  unsigned int ip;

  if (!string || !string[0])
    return NULL;

  // Is the string actually a dotted IP?
  ip = inet_addr(string);
  if (ip != INADDR_NONE)
    return gt2IPToHostInfo(ip, aliases, ips);

  host = gethostbyname(string);

  return gti2HandleHostInfo(host, aliases, ips);
}

const char* gt2IPToHostname(unsigned int ip) {
  return gt2IPToHostInfo(ip, NULL, NULL);
}

const char* gt2StringToHostname(const char* string) {
  return gt2StringToHostInfo(string, NULL, NULL);
}

char** gt2IPToAliases(unsigned int ip) {
  char** aliases;

  if (!gt2IPToHostInfo(ip, &aliases, NULL))
    return NULL;

  return aliases;
}

char** gt2StringToAliases(const char* string) {
  char** aliases;

  if (!gt2StringToHostInfo(string, &aliases, NULL))
    return NULL;

  return aliases;
}

unsigned int** gt2IPToIPs(unsigned int ip) {
  unsigned int** ips;

  if (!gt2IPToHostInfo(ip, NULL, &ips))
    return NULL;

  return ips;
}

unsigned int** gt2StringToIPs(const char* string) {
  unsigned int** ips;

  if (!gt2StringToHostInfo(string, NULL, &ips))
    return NULL;

  return ips;
}

/***********************
** INTERNAL FUNCTIONS **
***********************/

#ifdef __MWERKS__ // CodeWarrior will warn if not prototyped
void gti2MessageCheck(const GT2Byte** message, int* len);
#endif

// Used from gt2main.c
void gti2MessageCheck(const GT2Byte** message, int* len) {
  // check for an empty message
  if (!*message) {
    *message = (const GT2Byte*)"";
    *len = 0;
  }
  // check for calculating the message length
  else if (*len == -1) {
    *len = (int)(strlen((const char*)*message) + 1);
  }
}

#ifdef RECV_LOG
void gti2LogMessage(unsigned int fromIP, unsigned short fromPort,
                    unsigned int toIP, unsigned short toPort,
                    const GT2Byte* message, int len) {
  FILE* file;
  IN_ADDR ip;
  int i;

  file = fopen("recv.log", "at");
  if (!file)
    return;

  // from
  ip.s_addr = fromIP;
  fprintf(file, "%s:%d -> ", inet_ntoa(ip), fromPort);

  // to
  ip.s_addr = toIP;
  fprintf(file, "%s:%d\n", inet_ntoa(ip), toPort);

  // data
  fprintf(file, "%d: ", len);
  for (i = 0; i < len; i++)
    fprintf(file, "%02X ", message[i]);
  fprintf(file, "\n\n");

  fclose(file);
}
#endif

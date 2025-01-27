///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
#include "gsPlatformUtil.h"
#include "gsCommon.h"

// Include platform separated functions
#include "revolution/gsUtilRevolution.c"

#if defined(__cplusplus)
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
// ********** ASYNC DNS ********** //

// struct is used in both threaded and non-threaded versions
typedef struct GSIResolveHostnameInfo {
  char* hostname;
  unsigned int ip;
  int finishedResolving;
  GSIThreadID threadID;
} GSIResolveHostnameInfo;

///////////////////////////////////////////////////////////////////////////////
static void* gsiResolveHostnameThread(void* arg) {
  static GSICriticalSection aHostnameCrit;
  static int aInitialized = 0;
  // SOAddrInfo *aHostAddr;
  HOSTENT* aHostAddr;
  // int retval;
  GSIResolveHostnameHandle handle = (GSIResolveHostnameHandle)arg;

  if (!aInitialized) {
    gsiInitializeCriticalSection(&aHostnameCrit);
    aInitialized = 1;
  }
  gsiEnterCriticalSection(&aHostnameCrit);

  // retval = getaddrinfo(handle->hostname, NULL, NULL, &aHostAddr);
  aHostAddr = gethostbyname(handle->hostname);
  if (aHostAddr != 0) {
    char* ip;
    // first convert to character string for debug output
    ip = inet_ntoa(*(in_addr*)aHostAddr->addrList[0]);

    // gsDebugFormat(GSIDebugCat_HTTP, GSIDebugType_State,
    // GSIDebugLevel_Comment,
    //              "Resolved host '%s' to ip '%s'\n", handle->hostname, ip);

    handle->ip = inet_addr(ip);
    // freeaddrinfo(aHostAddr);
  } else {
    // couldnt reach host - debug output is printed later
    handle->ip = GSI_ERROR_RESOLVING_HOSTNAME;
  }

  // finished resolving
  handle->finishedResolving = 1;

  OSUnlockMutex(&aHostnameCrit);
}
////////////////////////////////////////////////////////////////////////////////

int gsiStartResolvingHostname(const char* hostname,
                              GSIResolveHostnameHandle* handle) {
  GSIResolveHostnameInfo* info;

  // allocate a handle
  info = (GSIResolveHostnameInfo*)gsimalloc(sizeof(GSIResolveHostnameInfo));
  if (!info)
    return -1;

  // make a copy of the hostname so the thread has access to it
  info->hostname = goastrdup(hostname);
  if (!info->hostname) {
    gsifree(info);
    return -1;
  }

  // not resolved yet
  info->finishedResolving = 0;

  // start the thread
  if (gsiStartThread(gsiResolveHostnameThread, (0x1000), info,
                     &info->threadID) == -1) {
    gsifree(info->hostname);
    info->hostname = NULL;
    gsifree(info);
    info = NULL;
    return -1;
  }

  // set the handle to the info
  *handle = info;

  return 0;
}

void gsiCancelResolvingHostname(GSIResolveHostnameHandle handle) {
  // cancel the thread
  gsiCancelThread(handle->threadID);

  if (handle->hostname) {
    gsifree(handle->hostname);
    handle->hostname = NULL;
  }
  gsifree(handle);
  handle = NULL;
}

// PAL: 0x800f2300
unsigned int gsiGetResolvedIP(GSIResolveHostnameHandle handle) {
  unsigned int ip;

  // check if we haven't finished
  if (!handle->finishedResolving)
    return GSI_STILL_RESOLVING_HOSTNAME;

  // save the ip
  ip = handle->ip;

  // free resources
  gsiCleanupThread(handle->threadID);
  gsifree(handle->hostname);
  gsifree(handle);
  handle = NULL;

  return ip;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
char* goastrdup(const char* src) {
  char* res;
  if (src == NULL) // PANTS|02.11.00|check for NULL before strlen
    return NULL;
  res = (char*)gsimalloc(strlen(src) + 1);
  if (res != NULL) // PANTS|02.02.00|check for NULL before strcpy
    strcpy(res, src);
  return res;
}

/*
unsigned short* goawstrdup(const unsigned short* src) {
  unsigned short* res;
  if (src == NULL)
    return NULL;
  res = (unsigned short*)gsimalloc((wcslen((wchar_t*)src) + 1) *
                                   sizeof(unsigned short));
  if (res != NULL)
    wcscpy((wchar_t*)res, (const wchar_t*)src);
  return res;
}
*/

char* _strlwr(char* string) {
  char* hold = string;
  while (*string) {
    *string = (char)tolower(*string);
    string++;
  }

  return hold;
}

/*
char* _strupr(char* string) {
  char* hold = string;
  while (*string) {
    *string = (char)toupper(*string);
    string++;
  }

  return hold;
}
*/

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
// PAL: 0x800f24c0
void SocketStartUp() {}
// PAL: 0x800f24c4
void SocketShutDown() {}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
// PAL: 0x800f24c8
gsi_time current_time() // returns current time in milliseconds
{
  OSTick aTickNow = OSGetTick();
  gsi_time aMilliseconds = (gsi_time)OSTicksToMilliseconds(aTickNow);
  return aMilliseconds;
}

// PAL: 0x800f2510
void msleep(gsi_time msec) {
  OSSleepTicks((((s64)msec) * ((__OSBusClock / 4) / 1000)));
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
// Cross-platform GSI wrapper time conversion functions
//
// NOTE: some portions of this copied from standard C library

// if an error occurs when calling mktime, return -1
#define MKTIME_ERROR (time_t)(-1)

// define common conversions for mktime
#define DAY_SEC (24L * 60L * 60L)       /* secs in a day */
#define YEAR_SEC (365L * DAY_SEC)       /* secs in a year */
#define FOUR_YEAR_SEC (1461L * DAY_SEC) /* secs in a 4 year interval */
#define DEC_SEC 315532800L              /* secs in 1970-1979 */
#define BASE_DOW 4                      /* 01-01-70 was a Thursday */
#define BASE_YEAR 70L                   /* 1970 is the base year */
#define LEAP_YEAR_ADJUST 17L            /* Leap years 1900 - 1970 */
#define MAX_YEAR 138L                   /* 2038 is the max year */

// ChkAdd evaluates to TRUE if dest = src1 + src2 has overflowed
#define ChkAdd(dest, src1, src2)                                               \
  (((src1 >= 0L) && (src2 >= 0L) && (dest < 0L)) ||                            \
   ((src1 < 0L) && (src2 < 0L) && (dest >= 0L)))

// ChkMul evaluates to TRUE if dest = src1 * src2 has overflowed
#define ChkMul(dest, src1, src2) (src1 ? (dest / src1 != src2) : 0)

int _lpdays[] = {-1, 30, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
int _days[] = {-1, 30, 58, 89, 119, 150, 180, 211, 242, 272, 303, 333, 364};

const char _dnames[] = {"SunMonTueWedThuFriSat"};
/*  Month names must be Three character abbreviations strung together */
const char _mnames[] = {"JanFebMarAprMayJunJulAugSepOctNovDec"};

static struct tm tb = {0}; /* time block used in SecondsToDate */

static char buf[26]; /* buffer used to store string in SecondsToString */

#define _T(a) L##a
static char* store_dt(char*, int);
static char* store_dt(char* p, int val) {
  *p++ = (char)(_T('0') + val / 10);
  *p++ = (char)(_T('0') + val % 10);
  return (p);
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
// GSI equivalent of Standard C-lib "gmtime function"
struct tm* gsiSecondsToDate(const time_t* timp) {
  time_t caltim = *timp; /* calendar time to convert */
  int islpyr = 0;        /* is-current-year-a-leap-year flag */
  int tmptim;
  int* mdays; /* pointer to days or lpdays */
  struct tm* ptb = &tb;

  if (caltim < 0L)
    return (NULL);

  /*
   * Determine years since 1970. First, identify the four-year interval
   * since this makes handling leap-years easy (note that 2000 IS a
   * leap year and 2100 is out-of-range).
   */
  tmptim = (int)(caltim / FOUR_YEAR_SEC);
  caltim -= ((long)tmptim * FOUR_YEAR_SEC);

  /*
   * Determine which year of the interval
   */
  tmptim = (tmptim * 4) + 70; /* 1970, 1974, 1978,...,etc. */

  if (caltim >= YEAR_SEC) {
    tmptim++; /* 1971, 1975, 1979,...,etc. */
    caltim -= YEAR_SEC;

    if (caltim >= YEAR_SEC) {
      tmptim++; /* 1972, 1976, 1980,...,etc. */
      caltim -= YEAR_SEC;

      /*
       * Note, it takes 366 days-worth of seconds to get past a leap
       * year.
       */
      if (caltim >= (YEAR_SEC + DAY_SEC)) {
        tmptim++; /* 1973, 1977, 1981,...,etc. */
        caltim -= (YEAR_SEC + DAY_SEC);
      } else {
        /*
         * In a leap year after all, set the flag.
         */
        islpyr++;
      }
    }
  }

  /*
   * tmptim now holds the value for tm_year. caltim now holds the
   * number of elapsed seconds since the beginning of that year.
   */
  ptb->tm_year = tmptim;

  /*
   * Determine days since January 1 (0 - 365). This is the tm_yday value.
   * Leave caltim with number of elapsed seconds in that day.
   */
  ptb->tm_yday = (int)(caltim / DAY_SEC);
  caltim -= (long)(ptb->tm_yday) * DAY_SEC;

  /*
   * Determine months since January (0 - 11) and day of month (1 - 31)
   */
  if (islpyr)
    mdays = _lpdays;
  else
    mdays = _days;

  for (tmptim = 1; mdays[tmptim] < ptb->tm_yday; tmptim++)
    ;

  ptb->tm_mon = --tmptim;

  ptb->tm_mday = ptb->tm_yday - mdays[tmptim];

  /*
   * Determine days since Sunday (0 - 6)
   */
  ptb->tm_wday = ((int)(*timp / DAY_SEC) + BASE_DOW) % 7;

  /*
   *  Determine hours since midnight (0 - 23), minutes after the hour
   *  (0 - 59), and seconds after the minute (0 - 59).
   */
  ptb->tm_hour = (int)(caltim / 3600);
  caltim -= (long)ptb->tm_hour * 3600L;

  ptb->tm_min = (int)(caltim / 60);
  ptb->tm_sec = (int)(caltim - (ptb->tm_min) * 60);

  ptb->tm_isdst = 0;
  return ((struct tm*)ptb);
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
// GSI equivalent of Standard C-lib "mktime function"
// PAL: 0x800f27b4
time_t gsiDateToSeconds(struct tm* tb) {
  time_t tmptm1, tmptm2, tmptm3;
  struct tm* tbtemp;
  /*
   * First, make sure tm_year is reasonably close to being in range.
   */
  if (((tmptm1 = tb->tm_year) < BASE_YEAR - 1) || (tmptm1 > MAX_YEAR + 1))
    return MKTIME_ERROR;

  /*
   * Adjust month value so it is in the range 0 - 11.  This is because
   * we don't know how many days are in months 12, 13, 14, etc.
   */

  if ((tb->tm_mon < 0) || (tb->tm_mon > 11)) {

    /*
     * no danger of overflow because the range check above.
     */
    tmptm1 += (tb->tm_mon / 12);

    if ((tb->tm_mon %= 12) < 0) {
      tb->tm_mon += 12;
      tmptm1--;
    }

    /*
     * Make sure year count is still in range.
     */
    if ((tmptm1 < BASE_YEAR - 1) || (tmptm1 > MAX_YEAR + 1))
      return MKTIME_ERROR;
  }

  /***** HERE: tmptm1 holds number of elapsed years *****/

  /*
   * Calculate days elapsed minus one, in the given year, to the given
   * month. Check for leap year and adjust if necessary.
   */
  tmptm2 = _days[tb->tm_mon];
  if (!(tmptm1 & 3) && (tb->tm_mon > 1))
    tmptm2++;

  /*
   * Calculate elapsed days since base date (midnight, 1/1/70, UTC)
   *
   *
   * 365 days for each elapsed year since 1970, plus one more day for
   * each elapsed leap year. no danger of overflow because of the range
   * check (above) on tmptm1.
   */
  tmptm3 =
      (tmptm1 - BASE_YEAR) * 365L + ((tmptm1 - 1L) >> 2) - LEAP_YEAR_ADJUST;

  /*
   * elapsed days to current month (still no possible overflow)
   */
  tmptm3 += tmptm2;

  /*
   * elapsed days to current date. overflow is now possible.
   */
  tmptm1 = tmptm3 + (tmptm2 = (long)(tb->tm_mday));
  if (ChkAdd(tmptm1, tmptm3, tmptm2))
    return MKTIME_ERROR;

  /***** HERE: tmptm1 holds number of elapsed days *****/

  /*
   * Calculate elapsed hours since base date
   */
  tmptm2 = tmptm1 * 24L;
  if (ChkMul(tmptm2, tmptm1, 24L))
    return MKTIME_ERROR;

  tmptm1 = tmptm2 + (tmptm3 = (long)tb->tm_hour);
  if (ChkAdd(tmptm1, tmptm2, tmptm3))
    return MKTIME_ERROR;

  /***** HERE: tmptm1 holds number of elapsed hours *****/

  /*
   * Calculate elapsed minutes since base date
   */

  tmptm2 = tmptm1 * 60L;
  if (ChkMul(tmptm2, tmptm1, 60L))
    return MKTIME_ERROR;

  tmptm1 = tmptm2 + (tmptm3 = (long)tb->tm_min);
  if (ChkAdd(tmptm1, tmptm2, tmptm3))
    return MKTIME_ERROR;

  /***** HERE: tmptm1 holds number of elapsed minutes *****/

  /*
   * Calculate elapsed seconds since base date
   */

  tmptm2 = tmptm1 * 60L;
  if (ChkMul(tmptm2, tmptm1, 60L))
    return MKTIME_ERROR;

  tmptm1 = tmptm2 + (tmptm3 = (long)tb->tm_sec);
  if (ChkAdd(tmptm1, tmptm2, tmptm3))
    return MKTIME_ERROR;

  /***** HERE: tmptm1 holds number of elapsed seconds *****/

  if ((tbtemp = gsiSecondsToDate(&tmptm1)) == NULL)
    return MKTIME_ERROR;

  /***** HERE: tmptm1 holds number of elapsed seconds, adjusted *****/
  /*****       for local time if requested                      *****/

  *tb = *tbtemp;
  return (time_t)tmptm1;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
// Cross platform random number generator
#define RANa 16807               // multiplier
#define LONGRAND_MAX 2147483647L // 2**31 - 1

static long randomnum = 1;

static long nextlongrand(long seed) {
  unsigned

      long lo,
      hi;
  lo = RANa * (unsigned long)(seed & 0xFFFF);
  hi = RANa * ((unsigned long)seed >> 16);
  lo += (hi & 0x7FFF) << 16;

  if (lo > LONGRAND_MAX) {
    lo &= LONGRAND_MAX;
    ++lo;
  }
  lo += hi >> 15;

  if (lo > LONGRAND_MAX) {
    lo &= LONGRAND_MAX;
    ++lo;
  }

  return (long)lo;
}

// return next random long
static long longrand(void) {
  randomnum = nextlongrand(randomnum);
  return randomnum;
}

// to seed it
// PAL: 0x800f2ec8
void Util_RandSeed(unsigned long seed) {
  // nonzero seed
  randomnum = seed ? (long)(seed & LONGRAND_MAX) : 1;
}

// PAL: 0x800f2ee0
int Util_RandInt(int low, int high) {
  unsigned int range = (unsigned int)high - low;
  int num;

  if (range == 0)
    return (low); // Prevent divide by zero

  num = (int)(longrand() % range);

  return (num + low);
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

static void QuartToTrip(char* quart, char* trip, int inlen) {
  if (inlen >= 2)
    trip[0] = (char)(quart[0] << 2 | quart[1] >> 4);
  if (inlen >= 3)
    trip[1] = (char)((quart[1] & 0x0F) << 4 | quart[2] >> 2);
  if (inlen >= 4)
    trip[2] = (char)((quart[2] & 0x3) << 6 | quart[3]);
}

static void TripToQuart(const char* trip, char* quart, int inlen) {
  unsigned char triptemp[3];
  int i;
  for (i = 0; i < inlen; i++) {
    triptemp[i] = (unsigned char)trip[i];
  }
  while (i < 3) // fill the rest with 0
  {
    triptemp[i] = 0;
    i++;
  }
  quart[0] = (char)(triptemp[0] >> 2);
  quart[1] = (char)(((triptemp[0] & 3) << 4) | (triptemp[1] >> 4));
  quart[2] = (char)((triptemp[1] & 0x0F) << 2 | (triptemp[2] >> 6));
  quart[3] = (char)(triptemp[2] & 0x3F);
}

const char defaultEncoding[] = {'+', '/', '='};
const char alternateEncoding[] = {'[', ']', '_'};
const char urlSafeEncodeing[] = {'-', '_', '='};

void B64Decode(const char* input, char* output, int inlen, int* outlen,
               int encodingType) {
  const char* encoding = NULL;
  const char* holdin = input;
  int readpos = 0;
  int writepos = 0;
  char block[4];

  // int outlen = -1;
  // int inlen = (int)strlen(input);

  // 10-31-2004 : Added by Saad Nader
  // now supports URL safe encoding
  ////////////////////////////////////////////////
  switch (encodingType) {
  case 1:
    encoding = alternateEncoding;
    break;
  case 2:
    encoding = urlSafeEncodeing;
    break;
  default:
    encoding = defaultEncoding;
  }

  GS_ASSERT(inlen >= 0);
  if (inlen <= 0) {
    if (outlen)
      *outlen = 0;
    output[0] = '\0';
    return;
  }

  // Break at end of string or padding character
  while (readpos < inlen && input[readpos] != encoding[2]) {
    //    'A'-'Z' maps to 0-25
    //    'a'-'z' maps to 26-51
    //    '0'-'9' maps to 52-61
    //    62 maps to encoding[0]
    //    63 maps to encoding[1]
    if (input[readpos] >= '0' && input[readpos] <= '9')
      block[readpos % 4] = (char)(input[readpos] - 48 + 52);
    else if (input[readpos] >= 'a' && input[readpos] <= 'z')
      block[readpos % 4] = (char)(input[readpos] - 71);
    else if (input[readpos] >= 'A' && input[readpos] <= 'Z')
      block[readpos % 4] = (char)(input[readpos] - 65);
    else if (input[readpos] == encoding[0])
      block[readpos % 4] = 62;
    else if (input[readpos] == encoding[1])
      block[readpos % 4] = 63;

    // padding or '\0' characters also mark end of input
    else if (input[readpos] == encoding[2])
      break;
    else if (input[readpos] == '\0')
      break;
    else {
      //	(assert(0)); //bad input data
      if (outlen)
        *outlen = 0;
      output[0] = '\0';
      return; // invaid data
    }

    // every 4 bytes, convert QuartToTrip into destination
    if (readpos % 4 == 3) // zero based, so (3%4) means four bytes, 0-1-2-3
    {
      QuartToTrip(block, &output[writepos], 4);
      writepos += 3;
    }
    readpos++;
  }

  // Convert any leftover characters in block
  if ((readpos != 0) && (readpos % 4 != 0)) {
    // fill block with pad (required for QuartToTrip)
    memset(&block[readpos % 4], encoding[2], (unsigned int)4 - (readpos % 4));
    QuartToTrip(block, &output[writepos], readpos % 4);

    // output bytes depend on the number of non-pad input bytes
    if (readpos % 4 == 3)
      writepos += 2;
    else
      writepos += 1;
  }

  if (outlen)
    *outlen = writepos;

  GSI_UNUSED(holdin);
}

void B64Encode(const char* input, char* output, int inlen, int encodingType) {
  const char* encoding;
  char* holdout = output;
  char* lastchar;
  int todo = inlen;

  // 10-31-2004 : Added by Saad Nader
  // now supports URL safe encoding
  ////////////////////////////////////////////////
  switch (encodingType) {
  case 1:
    encoding = alternateEncoding;
    break;
  case 2:
    encoding = urlSafeEncodeing;
    break;
  default:
    encoding = defaultEncoding;
  }

  // assume interval of 3
  while (todo > 0) {
    TripToQuart(input, output, min(todo, 3));
    output += 4;
    input += 3;
    todo -= 3;
  }
  lastchar = output;
  if (inlen % 3 == 1)
    lastchar -= 2;
  else if (inlen % 3 == 2)
    lastchar -= 1;
  *output = 0; // null terminate!
  while (output > holdout) {
    output--;
    if (output >= lastchar) // pad the end
      *output = encoding[2];
    else if (*output <= 25)
      *output = (char)(*output + 65);
    else if (*output <= 51)
      *output = (char)(*output + 71);
    else if (*output <= 61)
      *output = (char)(*output + 48 - 52);
    else if (*output == 62)
      *output = encoding[0];
    else if (*output == 63)
      *output = encoding[1];
  }
}

// PAL: 0x800f3484
int B64DecodeLen(const char* input, int encodingType) {
  const char* encoding;
  const char* holdin = input;

  switch (encodingType) {
  case 1:
    encoding = alternateEncoding;
    break;
  case 2:
    encoding = urlSafeEncodeing;
    break;
  default:
    encoding = defaultEncoding;
  }

  while (*input) {
    if (*input == encoding[2])
      return (input - holdin) / 4 * 3 + (input - holdin - 1) % 4;
    input++;
  }

  return (input - holdin) / 4 * 3;
}

// PAL: 0x800f3528
void B64InitEncodeStream(B64StreamData* data, const char* input, int len,
                         int encodingType) {
  data->input = input;
  data->len = len;
  data->encodingType = encodingType;
}

gsi_bool B64EncodeStream(B64StreamData* data, char output[4]) {
  const char* encoding;
  char* c;
  int i;

  if (data->len <= 0)
    return gsi_false;

  // 10-31-2004 : Added by Saad Nader
  // now supports URL safe encoding
  ////////////////////////////////////////////////
  switch (data->encodingType) {
  case 1:
    encoding = alternateEncoding;
    break;
  case 2:
    encoding = urlSafeEncodeing;
    break;
  default:
    encoding = defaultEncoding;
  }

  TripToQuart(data->input, output, min(data->len, 3));
  data->input += 3;
  data->len -= 3;

  for (i = 0; i < 4; i++) {
    c = &output[i];
    if (*c <= 25)
      *c = (char)(*c + 65);
    else if (*c <= 51)
      *c = (char)(*c + 71);
    else if (*c <= 61)
      *c = (char)(*c + 48 - 52);
    else if (*c == 62)
      *c = encoding[0];
    else if (*c == 63)
      *c = encoding[1];
  }

  if (data->len < 0) {
    output[3] = encoding[2];
    if (data->len == -2)
      output[2] = encoding[2];
  }

  return gsi_true;
}

/*
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void gsiPadRight(char* cArray, char padChar, int cLength);
char* gsiXxteaAlg(const char* sIn, int nIn, char key[XXTEA_KEY_SIZE], int bEnc,
                  int* nOut);

void gsiPadRight(char* cArray, char padChar, int cLength) {
  int diff;
  int length = (int)strlen(cArray);

  diff = cLength - length;
  memset(&cArray[length], padChar, (size_t)diff);
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
// The heart of the XXTEA encryption/decryption algorithm.
//
// sIn:  Input stream.
// nIn:  Input length (bytes).
// key:  Key (only first 128 bits are significant).
// bEnc: Encrypt (else decrypt)?
char* gsiXxteaAlg(const char* sIn, int nIn, char key[XXTEA_KEY_SIZE], int bEnc,
                  int* nOut) {
  int i, p, n1;
  unsigned int *k, *v, z, y;
  char *oStr = NULL, *pStr = NULL;
  char* sIn2 = NULL;
  /////////////////////////////////
  // ERROR CHECK!
  if (!sIn || !key[0] || nIn == 0)
    return NULL;

  // Convert stream length to a round number of 32-bit words
  // Convert byte	count to 32-bit	word count
  if (nIn % 4 == 0) // Fix for null terminated strings divisible by 4
    nIn = (nIn / 4) + 1;
  else
    nIn = (nIn + 3) / 4;

  if (nIn <= 1) // XXTEA requires at least 64 bits
    nIn = 2;

  // Load	and	zero-pad first 16 characters (128 bits)	of key
  gsiPadRight(key, '\0', XXTEA_KEY_SIZE);
  k = (unsigned int*)key;

  // Load and zero-pad entire input stream as 32-bit words
  sIn2 = (char*)gsimalloc((size_t)(4 * nIn));
  strcpy(sIn2, sIn);
  gsiPadRight(sIn2, '\0', 4 * nIn);
  v = (unsigned int*)sIn2;

  // Prepare to encrypt or decrypt
  n1 = nIn - 1;
  z = v[n1];
  y = v[0];
  i = (int)(6 + 52 / nIn);

  if (bEnc == 1) // Encrypt
  {
    unsigned int sum = 0;
    while (i-- != 0) {
      int e;
      sum += 0x9E3779B9;
      e = (int)(sum >> 2);
      for (p = -1; ++p < nIn;) {
        y = v[(p < n1) ? p + 1 : 0];
        z = (v[p] += (((z >> 5) ^ (y << 2)) + ((y >> 3) ^ (z << 4))) ^
                     ((sum ^ y) + (k[(p ^ e) & 3] ^ z)));
      }
    }
  } else if (bEnc == 0) // Decrypt
  {
    unsigned int sum = (unsigned int)i * 0x9E3779B9;
    while (sum != 0) {
      int e = (int)(sum >> 2);
      for (p = nIn; p-- != 0;) {
        z = v[(p != 0) ? p - 1 : n1];
        y = (v[p] -= (((z >> 5) ^ (y << 2)) + ((y >> 3) ^ (z << 4))) ^
                     ((sum ^ y) + (k[(p ^ e) & 3] ^ z)));
      }
      sum -= 0x9E3779B9;
    }
  } else
    return NULL;
  // Convert result from 32-bit words to a byte stream

  oStr = (char*)gsimalloc((size_t)(4 * nIn + 1));
  pStr = oStr;
  *nOut = 4 * nIn;
  for (i = -1; ++i < nIn;) {
    unsigned int q = v[i];

    *pStr++ = (char)(q & 0xFF);
    *pStr++ = (char)((q >> 8) & 0xFF);
    *pStr++ = (char)((q >> 16) & 0xFF);
    *pStr++ = (char)((q >> 24) & 0xFF);
  }
  *pStr = '\0';
  gsifree(sIn2);

  return oStr;
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
// XXTEA Encrpyt
// params
// iStr    : the input string to be encrypted
// iLength : the length of the input string
// key     : the key used to encrypt
char* gsXxteaEncrypt(const char* iStr, int iLength, char key[XXTEA_KEY_SIZE],
                     int* oLength) {
  return gsiXxteaAlg(iStr, iLength, key, 1, oLength);
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
// XXTEA Decrypt
// params
// iStr    : the input string to be decrypted
// iLength : the length of the input string
// key     : the key used to decrypt
char* gsXxteaDecrypt(const char* iStr, int iLength, char key[XXTEA_KEY_SIZE],
                     int* oLength) {
  return gsiXxteaAlg(iStr, iLength, key, 0, oLength);
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
*/

#if defined(__cplusplus)
}
#endif

/*
 * This source code is public domain.
 *
 * Authors: Rani Assaf <rani@magic.metawire.com>,
 *          Olivier Lapicque <olivierl@jps.net>,
 *          Adam Goode       <adam@evdebs.org> (endian and char fixes for PPC)
 */

#ifndef _STDAFX_H_
#define _STDAFX_H_

#include <stdint.h>

#define MODPLUG_NO_FILESAVE
#define MODPLUG_NO_REVERB
#define NO_AGC

#ifdef _WIN32

#ifdef UNICODE
	#undef UNICODE
#endif

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <windowsx.h>
#include <mmsystem.h>
#include <stdio.h>
#include <malloc.h>
#include <stdint.h>

#define srandom(_seed)  srand(_seed)
#define random()        rand()
#define sleep(_ms)      Sleep(_ms)

#define strncasecmp(a,b,c)  strncmp(a,b,c)
#define strcasecmp(a,b) strcmp(a,b)
#define strnicmp(a,b,c)		strncasecmp(a,b,c)
#define HAVE_SINF 1

#else

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

namespace QMPlay2ModPlug {

typedef int8_t CHAR;
typedef uint8_t UCHAR;
typedef uint8_t* PUCHAR;
typedef uint16_t USHORT;
typedef uint32_t ULONG;
typedef uint32_t UINT;
typedef uint32_t DWORD;
typedef int32_t LONG;
typedef int64_t LONGLONG;
typedef int32_t* LPLONG;
typedef uint32_t* LPDWORD;
typedef uint16_t WORD;
typedef uint8_t BYTE;
typedef uint8_t* LPBYTE;
typedef bool BOOL;
typedef char* LPSTR;
typedef void* LPVOID;
typedef uint16_t* LPWORD;
typedef const char* LPCSTR;
typedef void* PVOID;
typedef void VOID;

static inline int8_t * GlobalAllocPtr(unsigned int, size_t size)
{
  int8_t * p = static_cast<int8_t *>(malloc(size));

  if (p != nullptr) memset(p, 0, size);
  return p;
}

}

#define LPCTSTR LPCSTR
#define lstrcpyn strncpy
#define lstrcpy strcpy
#define lstrcmp strcmp

#define  GHND   0

#define GlobalFreePtr(p) free((void *)(p))

#define strnicmp(a,b,c)		strncasecmp(a,b,c)
#define wsprintf			sprintf

#ifndef FALSE
#define FALSE	false
#endif

#ifndef TRUE
#define TRUE	true
#endif

#endif // _WIN32

#endif

#ifndef CONFIG_H
#define CONFIG_H

#include <string.h>

// Pure AAC LC decoder
//#define LC_ONLY_DECODER

#if defined(__MINGW32__)
#define HAVE_INTTYPES_H 1
#define HAVE_LRINTF 1
#define HAVE_MEMCPY 1
#define HAVE_STDINT_H 1
#define HAVE_STDLIB_H 1
#define HAVE_STRCHR 1
#define HAVE_STRING_H 1
#define STDC_HEADERS 1
#elif _MSC_VER >= 1800
#define HAVE_LRINTF 1
#endif

#endif

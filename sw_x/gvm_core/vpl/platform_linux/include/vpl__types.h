//
//  Copyright (C) 2005-2008, BroadOn Communications Corp.
//
//  These coded instructions, statements, and computer programs contain
//  unpublished  proprietary information of BroadOn Communications Corp.,
//  and are protected by Federal copyright law. They may not be disclosed
//  to third parties or copied or duplicated in any form, in whole or in
//  part, without the prior written consent of BroadOn Communications Corp.
//

#ifndef __VPL__TYPES_H__
#define __VPL__TYPES_H__

/// @file
/// Platform-private definitions, please do not include this header directly.

#ifndef IOS

// Put C99 wide-char functions (e.g., strtoull()) into scope, in addition
// to wprintf() and friends enabled when _XOPEN_SOURCE is 500.
#ifndef _XOPEN_SOURCE
#define _XOPEN_SOURCE 500
#endif

// For strnlen
#ifndef _GNU_SOURCE
#define _GNU_SOURCE  1
#endif

#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifndef VPL_NO_C99_TYPES

/// Get the ISO C99 types.
#ifdef __cplusplus
#ifndef __STDC_LIMIT_MACROS
#define __STDC_LIMIT_MACROS
#endif

#ifndef __STDC_CONSTANT_MACROS
#define __STDC_CONSTANT_MACROS
#endif

#ifndef __STDC_FORMAT_MACROS
#define __STDC_FORMAT_MACROS
#endif
#endif // __cplusplus

#include <stdint.h>     // ISO C99
#include <inttypes.h>   // ISO C99

#define VPL_C99_TYPES_DEFINED  TRUE

#endif // #ifndef VPL_NO_C99_TYPES

#if defined(__x86_64__)
#  error "Platform not fully supported"
//#  define VPL_PRI_PREFIX_off_t "?"
//#  define VPL_SCN_PREFIX_off_t "?"
#  define VPL_PRI_PREFIX_size_t "l"
#  define VPL_SCN_PREFIX_size_t "l"
//#  define VPL_PRI_PREFIX_ssize_t "?"
//#  define VPL_SCN_PREFIX_ssize_t "?"
#  define VPL_PLAT_INT_IS_64BIT  1
#elif defined(__mips__)
#  define VPL_PLAT_IS_MIPS 1
#  define VPL_PRI_PREFIX_off_t "ll"
#  define VPL_SCN_PREFIX_off_t "ll"
#  define VPL_PRI_PREFIX_size_t ""
#  define VPL_SCN_PREFIX_size_t ""
#  define VPL_PRI_PREFIX_ssize_t ""
#  define VPL_SCN_PREFIX_ssize_t ""
#elif defined(__arm__)
#  define VPL_PLAT_IS_ARM  1
#  if defined(__CLOUDNODE__)
#    define VPL_PRI_PREFIX_off_t "ll"
#    define VPL_SCN_PREFIX_off_t "ll"
#    define VPL_PRI_PREFIX_size_t ""
#    define VPL_SCN_PREFIX_size_t ""
#    define VPL_PRI_PREFIX_ssize_t ""
#    define VPL_SCN_PREFIX_ssize_t ""
#  elif defined(IOS)
#    define VPL_PRI_PREFIX_off_t "ll"
#    define VPL_SCN_PREFIX_off_t "ll"
#    define VPL_PRI_PREFIX_size_t "l"
#    define VPL_SCN_PREFIX_size_t "l"
#    define VPL_PRI_PREFIX_ssize_t "l"
#    define VPL_SCN_PREFIX_ssize_t "l"
#  elif defined(ANDROID)
#    define VPL_PRI_PREFIX_off_t "l"
#    define VPL_SCN_PREFIX_off_t "l"
#    define VPL_PRI_PREFIX_size_t ""
#    define VPL_SCN_PREFIX_size_t ""
#    define VPL_PRI_PREFIX_ssize_t "l"
#    define VPL_SCN_PREFIX_ssize_t "l"
#  else
#    error "Unexpected configuration"
#  endif
#  define VPL_PLAT_INT_IS_64BIT  0
#elif defined(__i386__)
#  define VPL_PLAT_IS_X86  1
#  define VPL_PRI_PREFIX_off_t "ll"
#  define VPL_SCN_PREFIX_off_t "ll"
#  define VPL_PRI_PREFIX_size_t ""
#  define VPL_SCN_PREFIX_size_t ""
#  define VPL_PRI_PREFIX_ssize_t ""
#  define VPL_SCN_PREFIX_ssize_t ""
#  define VPL_PLAT_INT_IS_64BIT  0
#else
#  error "Unknown platform"
#endif

#if defined(ANDROID)
#  define VPL_CPP_ENABLE_EXCEPTIONS  0
#else
#  define VPL_CPP_ENABLE_EXCEPTIONS  1
#endif

/// This platform automatically includes "0x" when using printf "%p"
#define VPL_PLAT_0xPTR_PREFIX

/// @deprecated
#  define VPL_PLAT_SIZET_FMT_PREFIX  VPL_PRI_PREFIX_size_t

#ifdef  __cplusplus
}
#endif

#endif // include guard

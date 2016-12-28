/*===---- xtestintrin.h - XTEST intrinsic ---------------------------------===
///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// xtestintrin.h                                                             //
// Copyright (C) Microsoft Corporation. All rights reserved.                 //
// Licensed under the MIT license. See COPYRIGHT in the project root for     //
// full license information.                                                 //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////
#ifndef __IMMINTRIN_H
#error "Never use <xtestintrin.h> directly; include <immintrin.h> instead."
#endif

#ifndef __XTESTINTRIN_H
#define __XTESTINTRIN_H

/* xtest returns non-zero if the instruction is executed within an RTM or active
 * HLE region. */
/* FIXME: This can be an either or for RTM/HLE. Deal with this when HLE is
 * supported. */
static __inline__ int
    __attribute__((__always_inline__, __nodebug__, __target__("rtm")))
    _xtest(void) {
  return __builtin_ia32_xtest();
}

#endif


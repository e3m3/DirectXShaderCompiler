///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// assert.h                                                                  //
// Copyright (C) Microsoft Corporation. All rights reserved.                 //
// Licensed under the MIT license. See COPYRIGHT in the project root for     //
// full license information.                                                 //
//                                                                           //
// Defines custom assert macro for clang/llvm.                               //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////
#pragma once

#undef  assert
#undef  wassert

// This assert will raise a structured exception (RaiseException), using
// STATUS_LLVM_ASSERT.  llvm_unreachable and report_fatal_error will also
// raise structured exceptions.  Each indicate a condition from which the
// application should not continue, but can be useful for catching and logging
// during automated testing.
#define STATUS_LLVM_ASSERT      0xE0000001
#define STATUS_LLVM_UNREACHABLE 0xE0000002
#define STATUS_LLVM_FATAL       0xE0000003

#ifdef  NDEBUG

#define assert(_Expression)     ((void)0)

#else /* NDEBUG */

#ifdef __cplusplus
extern "C" {
#endif
void llvm_assert(const char *_Message,
                 const char *_File,
                 unsigned _Line);
#ifdef __cplusplus
}
#endif

#define assert(_Expression) ((void)( (!!(_Expression)) || (llvm_assert(#_Expression, __FILE__, __LINE__), 0) ))

#endif  /* NDEBUG */


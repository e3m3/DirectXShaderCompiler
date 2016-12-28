//===- llvm/Support/Errno.h - Portable+convenient errno handling -*- C++ -*-===//
///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// Errno.h                                                                   //
// Copyright (C) Microsoft Corporation. All rights reserved.                 //
// Licensed under the MIT license. See COPYRIGHT in the project root for     //
// full license information.                                                 //
//                                                                           //
// This file declares some portable and convenient functions to deal with errno.//
//
///////////////////////////////////////////////////////////////////////////////

#ifndef LLVM_SUPPORT_ERRNO_H
#define LLVM_SUPPORT_ERRNO_H

#include <string>

namespace llvm {
namespace sys {

/// Returns a string representation of the errno value, using whatever
/// thread-safe variant of strerror() is available.  Be sure to call this
/// immediately after the function that set errno, or errno may have been
/// overwritten by an intervening call.
std::string StrError();

/// Like the no-argument version above, but uses \p errnum instead of errno.
std::string StrError(int errnum);

}  // namespace sys
}  // namespace llvm

#endif  // LLVM_SYSTEM_ERRNO_H

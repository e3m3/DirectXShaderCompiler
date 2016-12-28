//===- SystemUtils.cpp - Utilities for low-level system tasks -------------===//
///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// SystemUtils.cpp                                                           //
// Copyright (C) Microsoft Corporation. All rights reserved.                 //
// Licensed under the MIT license. See COPYRIGHT in the project root for     //
// full license information.                                                 //
//                                                                           //
// This file contains functions used to do a variety of low-level, often     //
// system-specific, tasks.                                                   //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include "llvm/Support/SystemUtils.h"
#include "llvm/Support/raw_ostream.h"
using namespace llvm;

bool llvm::CheckBitcodeOutputToConsole(raw_ostream &stream_to_check,
                                       bool print_warning) {
  if (stream_to_check.is_displayed()) {
    if (print_warning) {
      errs() << "WARNING: You're attempting to print out a bitcode file.\n"
                "This is inadvisable as it may cause display problems. If\n"
                "you REALLY want to taste LLVM bitcode first-hand, you\n"
                "can force output with the `-f' option.\n\n";
    }
    return true;
  }
  return false;
}

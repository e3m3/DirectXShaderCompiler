//===- CounterTest.cpp ------------------------------------------*- C++ -*-===//
///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// CounterTest.cpp                                                           //
// Copyright (C) Microsoft Corporation. All rights reserved.                 //
// Licensed under the MIT license. See COPYRIGHT in the project root for     //
// full license information.                                                 //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

// Test for a fuzzer: must find the case where a particular basic block is
// executed many times.
#include <iostream>

extern "C" void LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
  int Num = 0;
  for (size_t i = 0; i < Size; i++)
    if (Data[i] == 'A' + i)
      Num++;
  if (Num >= 4) {
    std::cerr <<  "BINGO!\n";
    exit(1);
  }
}

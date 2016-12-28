//===--- ObjectBuffer.h - Utility class to wrap object memory ---*- C++ -*-===//
///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// ObjectBuffer.h                                                            //
// Copyright (C) Microsoft Corporation. All rights reserved.                 //
// Licensed under the MIT license. See COPYRIGHT in the project root for     //
// full license information.                                                 //
//                                                                           //
// This file declares a wrapper class to hold the memory into which an       //
// object will be generated.                                                 //
//
///////////////////////////////////////////////////////////////////////////////

#ifndef LLVM_EXECUTIONENGINE_OBJECTBUFFER_H
#define LLVM_EXECUTIONENGINE_OBJECTBUFFER_H

#include "llvm/ADT/SmallVector.h"
#include "llvm/Support/MemoryBuffer.h"
#include "llvm/Support/raw_ostream.h"

namespace llvm {

class ObjectMemoryBuffer : public MemoryBuffer {
public:
  template <unsigned N>
  ObjectMemoryBuffer(SmallVector<char, N> SV)
    : SV(SV), BufferName("<in-memory object>") {
    init(this->SV.begin(), this->SV.end(), false);
  }

  template <unsigned N>
  ObjectMemoryBuffer(SmallVector<char, N> SV, StringRef Name)
    : SV(SV), BufferName(Name) {
    init(this->SV.begin(), this->SV.end(), false);
  }
  const char* getBufferIdentifier() const override { return BufferName.c_str(); }

  BufferKind getBufferKind() const override { return MemoryBuffer_Malloc; }

private:
  SmallVector<char, 4096> SV;
  std::string BufferName;
};

} // namespace llvm

#endif

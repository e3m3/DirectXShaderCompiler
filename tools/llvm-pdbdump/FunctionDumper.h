//===- FunctionDumper.h --------------------------------------- *- C++ --*-===//
///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// FunctionDumper.h                                                          //
// Copyright (C) Microsoft Corporation. All rights reserved.                 //
// Licensed under the MIT license. See COPYRIGHT in the project root for     //
// full license information.                                                 //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#ifndef LLVM_TOOLS_LLVMPDBDUMP_FUNCTIONDUMPER_H
#define LLVM_TOOLS_LLVMPDBDUMP_FUNCTIONDUMPER_H

#include "llvm/DebugInfo/PDB/PDBSymDumper.h"

namespace llvm {

class LinePrinter;

class FunctionDumper : public PDBSymDumper {
public:
  FunctionDumper(LinePrinter &P);

  enum class PointerType { None, Pointer, Reference };

  void start(const PDBSymbolTypeFunctionSig &Symbol, const char *Name,
             PointerType Pointer);
  void start(const PDBSymbolFunc &Symbol, PointerType Pointer);

  void dump(const PDBSymbolTypeArray &Symbol) override;
  void dump(const PDBSymbolTypeBuiltin &Symbol) override;
  void dump(const PDBSymbolTypeEnum &Symbol) override;
  void dump(const PDBSymbolTypeFunctionArg &Symbol) override;
  void dump(const PDBSymbolTypePointer &Symbol) override;
  void dump(const PDBSymbolTypeTypedef &Symbol) override;
  void dump(const PDBSymbolTypeUDT &Symbol) override;

private:
  LinePrinter &Printer;
};
}

#endif

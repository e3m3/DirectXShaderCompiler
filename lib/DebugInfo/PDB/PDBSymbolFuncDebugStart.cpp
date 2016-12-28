//===- PDBSymbolFuncDebugStart.cpp - ----------------------------*- C++ -*-===//
///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// PDBSymbolFuncDebugStart.cpp                                               //
// Copyright (C) Microsoft Corporation. All rights reserved.                 //
// Licensed under the MIT license. See COPYRIGHT in the project root for     //
// full license information.                                                 //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include "llvm/DebugInfo/PDB/PDBSymbolFuncDebugStart.h"

#include "llvm/DebugInfo/PDB/PDBSymbol.h"
#include "llvm/DebugInfo/PDB/PDBSymDumper.h"

#include <utility>

using namespace llvm;

PDBSymbolFuncDebugStart::PDBSymbolFuncDebugStart(
    const IPDBSession &PDBSession, std::unique_ptr<IPDBRawSymbol> Symbol)
    : PDBSymbol(PDBSession, std::move(Symbol)) {}

void PDBSymbolFuncDebugStart::dump(PDBSymDumper &Dumper) const {
  Dumper.dump(*this);
}

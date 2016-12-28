//===- PDBSymbolBlock.cpp - -------------------------------------*- C++ -*-===//
///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// PDBSymbolBlock.cpp                                                        //
// Copyright (C) Microsoft Corporation. All rights reserved.                 //
// Licensed under the MIT license. See COPYRIGHT in the project root for     //
// full license information.                                                 //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include "llvm/DebugInfo/PDB/PDBSymbolBlock.h"

#include "llvm/DebugInfo/PDB/PDBSymbol.h"
#include "llvm/DebugInfo/PDB/PDBSymDumper.h"

#include <utility>

using namespace llvm;

PDBSymbolBlock::PDBSymbolBlock(const IPDBSession &PDBSession,
                               std::unique_ptr<IPDBRawSymbol> Symbol)
    : PDBSymbol(PDBSession, std::move(Symbol)) {}

void PDBSymbolBlock::dump(PDBSymDumper &Dumper) const { Dumper.dump(*this); }

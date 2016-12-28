//===- GraphPrinters.cpp - DOT printers for various graph types -----------===//
///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// GraphPrinters.cpp                                                         //
// Copyright (C) Microsoft Corporation. All rights reserved.                 //
// Licensed under the MIT license. See COPYRIGHT in the project root for     //
// full license information.                                                 //
//                                                                           //
// This file defines several printers for various different types of graphs used//
// by the LLVM infrastructure.  It uses the generic graph interface to convert//
// the graph into a .dot graph.  These graphs can then be processed with the //
// "dot" tool to convert them to postscript or some other suitable format.   //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include "llvm/IR/Dominators.h"
#include "llvm/Pass.h"

using namespace llvm;

//===----------------------------------------------------------------------===//
//                            DomInfoPrinter Pass
//===----------------------------------------------------------------------===//

namespace {
  class DomInfoPrinter : public FunctionPass {
  public:
    static char ID; // Pass identification, replacement for typeid
    DomInfoPrinter() : FunctionPass(ID) {}

    void getAnalysisUsage(AnalysisUsage &AU) const override {
      AU.setPreservesAll();
      AU.addRequired<DominatorTreeWrapperPass>();
    }

    bool runOnFunction(Function &F) override {
      getAnalysis<DominatorTreeWrapperPass>().dump();
      return false;
    }
  };
}

char DomInfoPrinter::ID = 0;
static RegisterPass<DomInfoPrinter>
DIP("print-dom-info", "Dominator Info Printer", true, true);

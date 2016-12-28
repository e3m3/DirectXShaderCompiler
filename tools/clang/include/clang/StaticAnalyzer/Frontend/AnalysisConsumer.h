//===--- AnalysisConsumer.h - Front-end Analysis Engine Hooks ---*- C++ -*-===//
///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// AnalysisConsumer.h                                                        //
// Copyright (C) Microsoft Corporation. All rights reserved.                 //
// Licensed under the MIT license. See COPYRIGHT in the project root for     //
// full license information.                                                 //
//                                                                           //
// This header contains the functions necessary for a front-end to run various//
// analyses.                                                                 //
//
///////////////////////////////////////////////////////////////////////////////

#ifndef LLVM_CLANG_STATICANALYZER_FRONTEND_ANALYSISCONSUMER_H
#define LLVM_CLANG_STATICANALYZER_FRONTEND_ANALYSISCONSUMER_H

#include "clang/AST/ASTConsumer.h"
#include "clang/Basic/LLVM.h"
#include "clang/StaticAnalyzer/Core/AnalyzerOptions.h"
#include "clang/StaticAnalyzer/Core/BugReporter/PathDiagnostic.h"
#include <string>

namespace clang {

class Preprocessor;
class DiagnosticsEngine;
class CodeInjector;
class CompilerInstance;

namespace ento {
class CheckerManager;

class AnalysisASTConsumer : public ASTConsumer {
public:
  virtual void AddDiagnosticConsumer(PathDiagnosticConsumer *Consumer) = 0;
};

/// CreateAnalysisConsumer - Creates an ASTConsumer to run various code
/// analysis passes.  (The set of analyses run is controlled by command-line
/// options.)
std::unique_ptr<AnalysisASTConsumer>
CreateAnalysisConsumer(CompilerInstance &CI);

} // end GR namespace

} // end clang namespace

#endif

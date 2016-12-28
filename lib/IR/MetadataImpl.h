//===- MetadataImpl.h - Helpers for implementing metadata -----------------===//
///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// MetadataImpl.h                                                            //
// Copyright (C) Microsoft Corporation. All rights reserved.                 //
// Licensed under the MIT license. See COPYRIGHT in the project root for     //
// full license information.                                                 //
//                                                                           //
// This file has private helpers for implementing metadata types.            //
//
///////////////////////////////////////////////////////////////////////////////

#ifndef LLVM_IR_METADATAIMPL_H
#define LLVM_IR_METADATAIMPL_H

#include "llvm/ADT/DenseSet.h"
#include "llvm/IR/Metadata.h"

namespace llvm {

template <class T, class InfoT>
static T *getUniqued(DenseSet<T *, InfoT> &Store,
                     const typename InfoT::KeyTy &Key) {
  auto I = Store.find_as(Key);
  return I == Store.end() ? nullptr : *I;
}

template <class T, class StoreT>
T *MDNode::storeImpl(T *N, StorageType Storage, StoreT &Store) {
  switch (Storage) {
  case Uniqued:
    Store.insert(N);
    break;
  case Distinct:
    N->storeDistinctInContext();
    break;
  case Temporary:
    break;
  }
  return N;
}

} // end namespace llvm

#endif

//===---- llvm/Support/DataStream.h - Lazy bitcode streaming ----*- C++ -*-===//
///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// DataStream.h                                                              //
// Copyright (C) Microsoft Corporation. All rights reserved.                 //
// Licensed under the MIT license. See COPYRIGHT in the project root for     //
// full license information.                                                 //
//                                                                           //
// This header defines DataStreamer, which fetches bytes of data from        //
// a stream source. It provides support for streaming (lazy reading) of      //
// data, e.g. bitcode                                                        //
//
///////////////////////////////////////////////////////////////////////////////


#ifndef LLVM_SUPPORT_DATASTREAM_H
#define LLVM_SUPPORT_DATASTREAM_H

#include <memory>
#include <string>

namespace llvm {

class DataStreamer {
public:
  /// Fetch bytes [start-end) from the stream, and write them to the
  /// buffer pointed to by buf. Returns the number of bytes actually written.
  virtual size_t GetBytes(unsigned char *buf, size_t len) = 0;

  virtual ~DataStreamer();
};

std::unique_ptr<DataStreamer> getDataFileStreamer(const std::string &Filename,
                                                  std::string *Err);
}

#endif  // LLVM_SUPPORT_DATASTREAM_H_

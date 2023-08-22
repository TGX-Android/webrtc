/*
 *  Copyright 2023 The WebRTC Project Authors. All rights reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */
#ifndef RTC_BASE_ASYNC_DNS_RESOLVER_H_
#define RTC_BASE_ASYNC_DNS_RESOLVER_H_

#include <vector>

#include "api/async_dns_resolver.h"
#include "api/sequence_checker.h"
#include "api/task_queue/pending_task_safety_flag.h"
#include "rtc_base/thread_annotations.h"

namespace webrtc {
// This file contains a default implementation of
// webrtc::AsyncDnsResolverInterface, for use when there is no need for special
// treatment.

class AsyncDnsResolverResultImpl : public AsyncDnsResolverResult {
 public:
  bool GetResolvedAddress(int family, rtc::SocketAddress* addr) const override;
  // Returns error from resolver.
  int GetError() const override;

 private:
  friend class AsyncDnsResolver;
  RTC_NO_UNIQUE_ADDRESS webrtc::SequenceChecker sequence_checker_;
  rtc::SocketAddress addr_ RTC_GUARDED_BY(sequence_checker_);
  std::vector<rtc::IPAddress> addresses_ RTC_GUARDED_BY(sequence_checker_);
  int error_ RTC_GUARDED_BY(sequence_checker_);
};

class AsyncDnsResolver : public AsyncDnsResolverInterface {
 public:
  // Start address resolution of the hostname in `addr`.
  void Start(const rtc::SocketAddress& addr,
             std::function<void()> callback) override;
  // Start address resolution of the hostname in `addr` matching `family`.
  void Start(const rtc::SocketAddress& addr,
             int family,
             std::function<void()> callback) override;
  const AsyncDnsResolverResult& result() const override;

 private:
  ScopedTaskSafety safety_;
  AsyncDnsResolverResultImpl result_;
};

}  // namespace webrtc
#endif  // RTC_BASE_ASYNC_DNS_RESOLVER_H_
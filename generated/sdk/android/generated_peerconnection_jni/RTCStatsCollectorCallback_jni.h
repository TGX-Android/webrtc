// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.


// This file is autogenerated by
//     third_party/jni_zero/jni_generator.py
// For
//     org/webrtc/RTCStatsCollectorCallback

#ifndef org_webrtc_RTCStatsCollectorCallback_JNI
#define org_webrtc_RTCStatsCollectorCallback_JNI

#include <jni.h>

#include "third_party/jni_zero/jni_export.h"
#include "sdk/android/src/jni/jni_generator_helper.h"


// Step 1: Forward declarations.

JNI_ZERO_COMPONENT_BUILD_EXPORT extern const char kClassPath_org_webrtc_RTCStatsCollectorCallback[];
const char kClassPath_org_webrtc_RTCStatsCollectorCallback[] =
    "org/webrtc/RTCStatsCollectorCallback";
// Leaking this jclass as we cannot use LazyInstance from some threads.
JNI_ZERO_COMPONENT_BUILD_EXPORT std::atomic<jclass>
    g_org_webrtc_RTCStatsCollectorCallback_clazz(nullptr);
#ifndef org_webrtc_RTCStatsCollectorCallback_clazz_defined
#define org_webrtc_RTCStatsCollectorCallback_clazz_defined
inline jclass org_webrtc_RTCStatsCollectorCallback_clazz(JNIEnv* env) {
  return jni_zero::LazyGetClass(env, kClassPath_org_webrtc_RTCStatsCollectorCallback,
      &g_org_webrtc_RTCStatsCollectorCallback_clazz);
}
#endif


// Step 2: Constants (optional).


// Step 3: Method stubs.
namespace webrtc {
namespace jni {


static std::atomic<jmethodID> g_org_webrtc_RTCStatsCollectorCallback_onStatsDelivered1(nullptr);
static void Java_RTCStatsCollectorCallback_onStatsDelivered(JNIEnv* env, const
    jni_zero::JavaRef<jobject>& obj, const jni_zero::JavaRef<jobject>& report) {
  jclass clazz = org_webrtc_RTCStatsCollectorCallback_clazz(env);
  CHECK_CLAZZ(env, obj.obj(),
      org_webrtc_RTCStatsCollectorCallback_clazz(env));

  jni_zero::JniJavaCallContextChecked call_context;
  call_context.Init<
      jni_zero::MethodID::TYPE_INSTANCE>(
          env,
          clazz,
          "onStatsDelivered",
          "(Lorg/webrtc/RTCStatsReport;)V",
          &g_org_webrtc_RTCStatsCollectorCallback_onStatsDelivered1);

     env->CallVoidMethod(obj.obj(),
          call_context.base.method_id, report.obj());
}

}  // namespace jni
}  // namespace webrtc

#endif  // org_webrtc_RTCStatsCollectorCallback_JNI
// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.


// This file is autogenerated by
//     third_party/jni_zero/jni_generator.py
// For
//     org/webrtc/RTCStatsReport

#ifndef org_webrtc_RTCStatsReport_JNI
#define org_webrtc_RTCStatsReport_JNI

#include <jni.h>

#include "third_party/jni_zero/jni_export.h"
#include "sdk/android/src/jni/jni_generator_helper.h"


// Step 1: Forward declarations.

JNI_ZERO_COMPONENT_BUILD_EXPORT extern const char kClassPath_org_webrtc_RTCStatsReport[];
const char kClassPath_org_webrtc_RTCStatsReport[] = "org/webrtc/RTCStatsReport";
// Leaking this jclass as we cannot use LazyInstance from some threads.
JNI_ZERO_COMPONENT_BUILD_EXPORT std::atomic<jclass> g_org_webrtc_RTCStatsReport_clazz(nullptr);
#ifndef org_webrtc_RTCStatsReport_clazz_defined
#define org_webrtc_RTCStatsReport_clazz_defined
inline jclass org_webrtc_RTCStatsReport_clazz(JNIEnv* env) {
  return jni_zero::LazyGetClass(env, kClassPath_org_webrtc_RTCStatsReport,
      &g_org_webrtc_RTCStatsReport_clazz);
}
#endif


// Step 2: Constants (optional).


// Step 3: Method stubs.
namespace webrtc {
namespace jni {


static std::atomic<jmethodID> g_org_webrtc_RTCStatsReport_create2(nullptr);
static jni_zero::ScopedJavaLocalRef<jobject> Java_RTCStatsReport_create(JNIEnv* env, jlong
    timestampUs,
    const jni_zero::JavaRef<jobject>& stats) {
  jclass clazz = org_webrtc_RTCStatsReport_clazz(env);
  CHECK_CLAZZ(env, clazz,
      org_webrtc_RTCStatsReport_clazz(env), nullptr);

  jni_zero::JniJavaCallContextChecked call_context;
  call_context.Init<
      jni_zero::MethodID::TYPE_STATIC>(
          env,
          clazz,
          "create",
          "(JLjava/util/Map;)Lorg/webrtc/RTCStatsReport;",
          &g_org_webrtc_RTCStatsReport_create2);

  jobject ret =
      env->CallStaticObjectMethod(clazz,
          call_context.base.method_id, timestampUs, stats.obj());
  return jni_zero::ScopedJavaLocalRef<jobject>(env, ret);
}

}  // namespace jni
}  // namespace webrtc

#endif  // org_webrtc_RTCStatsReport_JNI
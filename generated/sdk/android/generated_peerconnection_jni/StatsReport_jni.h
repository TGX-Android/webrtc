// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.


// This file is autogenerated by
//     third_party/jni_zero/jni_generator.py
// For
//     org/webrtc/StatsReport

#ifndef org_webrtc_StatsReport_JNI
#define org_webrtc_StatsReport_JNI

#include <jni.h>

#include "third_party/jni_zero/jni_export.h"
#include "sdk/android/src/jni/jni_generator_helper.h"


// Step 1: Forward declarations.

JNI_ZERO_COMPONENT_BUILD_EXPORT extern const char kClassPath_org_webrtc_StatsReport[];
const char kClassPath_org_webrtc_StatsReport[] = "org/webrtc/StatsReport";

JNI_ZERO_COMPONENT_BUILD_EXPORT extern const char kClassPath_org_webrtc_StatsReport_00024Value[];
const char kClassPath_org_webrtc_StatsReport_00024Value[] = "org/webrtc/StatsReport$Value";
// Leaking this jclass as we cannot use LazyInstance from some threads.
JNI_ZERO_COMPONENT_BUILD_EXPORT std::atomic<jclass> g_org_webrtc_StatsReport_clazz(nullptr);
#ifndef org_webrtc_StatsReport_clazz_defined
#define org_webrtc_StatsReport_clazz_defined
inline jclass org_webrtc_StatsReport_clazz(JNIEnv* env) {
  return jni_zero::LazyGetClass(env, kClassPath_org_webrtc_StatsReport,
      &g_org_webrtc_StatsReport_clazz);
}
#endif
// Leaking this jclass as we cannot use LazyInstance from some threads.
JNI_ZERO_COMPONENT_BUILD_EXPORT std::atomic<jclass>
    g_org_webrtc_StatsReport_00024Value_clazz(nullptr);
#ifndef org_webrtc_StatsReport_00024Value_clazz_defined
#define org_webrtc_StatsReport_00024Value_clazz_defined
inline jclass org_webrtc_StatsReport_00024Value_clazz(JNIEnv* env) {
  return jni_zero::LazyGetClass(env, kClassPath_org_webrtc_StatsReport_00024Value,
      &g_org_webrtc_StatsReport_00024Value_clazz);
}
#endif


// Step 2: Constants (optional).


// Step 3: Method stubs.
namespace webrtc {
namespace jni {


static std::atomic<jmethodID> g_org_webrtc_StatsReport_Constructor4(nullptr);
static jni_zero::ScopedJavaLocalRef<jobject> Java_StatsReport_Constructor(JNIEnv* env, const
    jni_zero::JavaRef<jstring>& id,
    const jni_zero::JavaRef<jstring>& type,
    jdouble timestamp,
    const jni_zero::JavaRef<jobjectArray>& values) {
  jclass clazz = org_webrtc_StatsReport_clazz(env);
  CHECK_CLAZZ(env, clazz,
      org_webrtc_StatsReport_clazz(env), nullptr);

  jni_zero::JniJavaCallContextChecked call_context;
  call_context.Init<
      jni_zero::MethodID::TYPE_INSTANCE>(
          env,
          clazz,
          "<init>",
          "(Ljava/lang/String;Ljava/lang/String;D[Lorg/webrtc/StatsReport$Value;)V",
          &g_org_webrtc_StatsReport_Constructor4);

  jobject ret =
      env->NewObject(clazz,
          call_context.base.method_id, id.obj(), type.obj(), timestamp, values.obj());
  return jni_zero::ScopedJavaLocalRef<jobject>(env, ret);
}

static std::atomic<jmethodID> g_org_webrtc_StatsReport_00024Value_Constructor2(nullptr);
static jni_zero::ScopedJavaLocalRef<jobject> Java_Value_Constructor(JNIEnv* env, const
    jni_zero::JavaRef<jstring>& name,
    const jni_zero::JavaRef<jstring>& value) {
  jclass clazz = org_webrtc_StatsReport_00024Value_clazz(env);
  CHECK_CLAZZ(env, clazz,
      org_webrtc_StatsReport_00024Value_clazz(env), nullptr);

  jni_zero::JniJavaCallContextChecked call_context;
  call_context.Init<
      jni_zero::MethodID::TYPE_INSTANCE>(
          env,
          clazz,
          "<init>",
          "(Ljava/lang/String;Ljava/lang/String;)V",
          &g_org_webrtc_StatsReport_00024Value_Constructor2);

  jobject ret =
      env->NewObject(clazz,
          call_context.base.method_id, name.obj(), value.obj());
  return jni_zero::ScopedJavaLocalRef<jobject>(env, ret);
}

}  // namespace jni
}  // namespace webrtc

#endif  // org_webrtc_StatsReport_JNI
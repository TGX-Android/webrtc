// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.


// This file is autogenerated by
//     third_party/jni_zero/jni_generator.py
// For
//     org/webrtc/MediaSource

#ifndef org_webrtc_MediaSource_JNI
#define org_webrtc_MediaSource_JNI

#include <jni.h>

#include "third_party/jni_zero/jni_export.h"
#include "sdk/android/src/jni/jni_generator_helper.h"


// Step 1: Forward declarations.

JNI_ZERO_COMPONENT_BUILD_EXPORT extern const char kClassPath_org_webrtc_MediaSource[];
const char kClassPath_org_webrtc_MediaSource[] = "org/webrtc/MediaSource";

JNI_ZERO_COMPONENT_BUILD_EXPORT extern const char kClassPath_org_webrtc_MediaSource_00024State[];
const char kClassPath_org_webrtc_MediaSource_00024State[] = "org/webrtc/MediaSource$State";
// Leaking this jclass as we cannot use LazyInstance from some threads.
JNI_ZERO_COMPONENT_BUILD_EXPORT std::atomic<jclass> g_org_webrtc_MediaSource_clazz(nullptr);
#ifndef org_webrtc_MediaSource_clazz_defined
#define org_webrtc_MediaSource_clazz_defined
inline jclass org_webrtc_MediaSource_clazz(JNIEnv* env) {
  return jni_zero::LazyGetClass(env, kClassPath_org_webrtc_MediaSource,
      &g_org_webrtc_MediaSource_clazz);
}
#endif
// Leaking this jclass as we cannot use LazyInstance from some threads.
JNI_ZERO_COMPONENT_BUILD_EXPORT std::atomic<jclass>
    g_org_webrtc_MediaSource_00024State_clazz(nullptr);
#ifndef org_webrtc_MediaSource_00024State_clazz_defined
#define org_webrtc_MediaSource_00024State_clazz_defined
inline jclass org_webrtc_MediaSource_00024State_clazz(JNIEnv* env) {
  return jni_zero::LazyGetClass(env, kClassPath_org_webrtc_MediaSource_00024State,
      &g_org_webrtc_MediaSource_00024State_clazz);
}
#endif


// Step 2: Constants (optional).


// Step 3: Method stubs.
namespace webrtc {
namespace jni {

static jni_zero::ScopedJavaLocalRef<jobject> JNI_MediaSource_GetState(JNIEnv* env, jlong pointer);

JNI_BOUNDARY_EXPORT jobject Java_org_webrtc_MediaSource_nativeGetState(
    JNIEnv* env,
    jclass jcaller,
    jlong pointer) {
  return JNI_MediaSource_GetState(env, pointer).Release();
}


static std::atomic<jmethodID> g_org_webrtc_MediaSource_00024State_fromNativeIndex1(nullptr);
static jni_zero::ScopedJavaLocalRef<jobject> Java_State_fromNativeIndex(JNIEnv* env, JniIntWrapper
    nativeIndex) {
  jclass clazz = org_webrtc_MediaSource_00024State_clazz(env);
  CHECK_CLAZZ(env, clazz,
      org_webrtc_MediaSource_00024State_clazz(env), nullptr);

  jni_zero::JniJavaCallContextChecked call_context;
  call_context.Init<
      jni_zero::MethodID::TYPE_STATIC>(
          env,
          clazz,
          "fromNativeIndex",
          "(I)Lorg/webrtc/MediaSource$State;",
          &g_org_webrtc_MediaSource_00024State_fromNativeIndex1);

  jobject ret =
      env->CallStaticObjectMethod(clazz,
          call_context.base.method_id, as_jint(nativeIndex));
  return jni_zero::ScopedJavaLocalRef<jobject>(env, ret);
}

}  // namespace jni
}  // namespace webrtc

#endif  // org_webrtc_MediaSource_JNI
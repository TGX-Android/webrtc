// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.


// This file is autogenerated by
//     third_party/jni_zero/jni_generator.py
// For
//     org/webrtc/RtpReceiver

#ifndef org_webrtc_RtpReceiver_JNI
#define org_webrtc_RtpReceiver_JNI

#include <jni.h>

#include "third_party/jni_zero/jni_export.h"
#include "sdk/android/src/jni/jni_generator_helper.h"


// Step 1: Forward declarations.

JNI_ZERO_COMPONENT_BUILD_EXPORT extern const char kClassPath_org_webrtc_RtpReceiver[];
const char kClassPath_org_webrtc_RtpReceiver[] = "org/webrtc/RtpReceiver";

JNI_ZERO_COMPONENT_BUILD_EXPORT extern const char kClassPath_org_webrtc_RtpReceiver_00024Observer[];
const char kClassPath_org_webrtc_RtpReceiver_00024Observer[] = "org/webrtc/RtpReceiver$Observer";
// Leaking this jclass as we cannot use LazyInstance from some threads.
JNI_ZERO_COMPONENT_BUILD_EXPORT std::atomic<jclass> g_org_webrtc_RtpReceiver_clazz(nullptr);
#ifndef org_webrtc_RtpReceiver_clazz_defined
#define org_webrtc_RtpReceiver_clazz_defined
inline jclass org_webrtc_RtpReceiver_clazz(JNIEnv* env) {
  return jni_zero::LazyGetClass(env, kClassPath_org_webrtc_RtpReceiver,
      &g_org_webrtc_RtpReceiver_clazz);
}
#endif
// Leaking this jclass as we cannot use LazyInstance from some threads.
JNI_ZERO_COMPONENT_BUILD_EXPORT std::atomic<jclass>
    g_org_webrtc_RtpReceiver_00024Observer_clazz(nullptr);
#ifndef org_webrtc_RtpReceiver_00024Observer_clazz_defined
#define org_webrtc_RtpReceiver_00024Observer_clazz_defined
inline jclass org_webrtc_RtpReceiver_00024Observer_clazz(JNIEnv* env) {
  return jni_zero::LazyGetClass(env, kClassPath_org_webrtc_RtpReceiver_00024Observer,
      &g_org_webrtc_RtpReceiver_00024Observer_clazz);
}
#endif


// Step 2: Constants (optional).


// Step 3: Method stubs.
namespace webrtc {
namespace jni {

static jni_zero::ScopedJavaLocalRef<jstring> JNI_RtpReceiver_GetId(JNIEnv* env, jlong rtpReceiver);

JNI_BOUNDARY_EXPORT jstring Java_org_webrtc_RtpReceiver_nativeGetId(
    JNIEnv* env,
    jclass jcaller,
    jlong rtpReceiver) {
  return JNI_RtpReceiver_GetId(env, rtpReceiver).Release();
}

static jni_zero::ScopedJavaLocalRef<jobject> JNI_RtpReceiver_GetParameters(JNIEnv* env, jlong
    rtpReceiver);

JNI_BOUNDARY_EXPORT jobject Java_org_webrtc_RtpReceiver_nativeGetParameters(
    JNIEnv* env,
    jclass jcaller,
    jlong rtpReceiver) {
  return JNI_RtpReceiver_GetParameters(env, rtpReceiver).Release();
}

static jlong JNI_RtpReceiver_GetTrack(JNIEnv* env, jlong rtpReceiver);

JNI_BOUNDARY_EXPORT jlong Java_org_webrtc_RtpReceiver_nativeGetTrack(
    JNIEnv* env,
    jclass jcaller,
    jlong rtpReceiver) {
  return JNI_RtpReceiver_GetTrack(env, rtpReceiver);
}

static void JNI_RtpReceiver_SetFrameDecryptor(JNIEnv* env, jlong rtpReceiver,
    jlong nativeFrameDecryptor);

JNI_BOUNDARY_EXPORT void Java_org_webrtc_RtpReceiver_nativeSetFrameDecryptor(
    JNIEnv* env,
    jclass jcaller,
    jlong rtpReceiver,
    jlong nativeFrameDecryptor) {
  return JNI_RtpReceiver_SetFrameDecryptor(env, rtpReceiver, nativeFrameDecryptor);
}

static jlong JNI_RtpReceiver_SetObserver(JNIEnv* env, jlong rtpReceiver,
    const jni_zero::JavaParamRef<jobject>& observer);

JNI_BOUNDARY_EXPORT jlong Java_org_webrtc_RtpReceiver_nativeSetObserver(
    JNIEnv* env,
    jclass jcaller,
    jlong rtpReceiver,
    jobject observer) {
  return JNI_RtpReceiver_SetObserver(env, rtpReceiver, jni_zero::JavaParamRef<jobject>(env,
      observer));
}

static void JNI_RtpReceiver_UnsetObserver(JNIEnv* env, jlong rtpReceiver,
    jlong nativeObserver);

JNI_BOUNDARY_EXPORT void Java_org_webrtc_RtpReceiver_nativeUnsetObserver(
    JNIEnv* env,
    jclass jcaller,
    jlong rtpReceiver,
    jlong nativeObserver) {
  return JNI_RtpReceiver_UnsetObserver(env, rtpReceiver, nativeObserver);
}


static std::atomic<jmethodID> g_org_webrtc_RtpReceiver_Constructor1(nullptr);
static jni_zero::ScopedJavaLocalRef<jobject> Java_RtpReceiver_Constructor(JNIEnv* env, jlong
    nativeRtpReceiver) {
  jclass clazz = org_webrtc_RtpReceiver_clazz(env);
  CHECK_CLAZZ(env, clazz,
      org_webrtc_RtpReceiver_clazz(env), nullptr);

  jni_zero::JniJavaCallContextChecked call_context;
  call_context.Init<
      jni_zero::MethodID::TYPE_INSTANCE>(
          env,
          clazz,
          "<init>",
          "(J)V",
          &g_org_webrtc_RtpReceiver_Constructor1);

  jobject ret =
      env->NewObject(clazz,
          call_context.base.method_id, nativeRtpReceiver);
  return jni_zero::ScopedJavaLocalRef<jobject>(env, ret);
}

static std::atomic<jmethodID> g_org_webrtc_RtpReceiver_dispose0(nullptr);
static void Java_RtpReceiver_dispose(JNIEnv* env, const jni_zero::JavaRef<jobject>& obj) {
  jclass clazz = org_webrtc_RtpReceiver_clazz(env);
  CHECK_CLAZZ(env, obj.obj(),
      org_webrtc_RtpReceiver_clazz(env));

  jni_zero::JniJavaCallContextChecked call_context;
  call_context.Init<
      jni_zero::MethodID::TYPE_INSTANCE>(
          env,
          clazz,
          "dispose",
          "()V",
          &g_org_webrtc_RtpReceiver_dispose0);

     env->CallVoidMethod(obj.obj(),
          call_context.base.method_id);
}

static std::atomic<jmethodID>
    g_org_webrtc_RtpReceiver_00024Observer_onFirstPacketReceived1(nullptr);
static void Java_Observer_onFirstPacketReceived(JNIEnv* env, const jni_zero::JavaRef<jobject>& obj,
    const jni_zero::JavaRef<jobject>& media_type) {
  jclass clazz = org_webrtc_RtpReceiver_00024Observer_clazz(env);
  CHECK_CLAZZ(env, obj.obj(),
      org_webrtc_RtpReceiver_00024Observer_clazz(env));

  jni_zero::JniJavaCallContextChecked call_context;
  call_context.Init<
      jni_zero::MethodID::TYPE_INSTANCE>(
          env,
          clazz,
          "onFirstPacketReceived",
          "(Lorg/webrtc/MediaStreamTrack$MediaType;)V",
          &g_org_webrtc_RtpReceiver_00024Observer_onFirstPacketReceived1);

     env->CallVoidMethod(obj.obj(),
          call_context.base.method_id, media_type.obj());
}

}  // namespace jni
}  // namespace webrtc

#endif  // org_webrtc_RtpReceiver_JNI
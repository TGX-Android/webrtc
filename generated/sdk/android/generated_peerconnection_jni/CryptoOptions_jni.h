// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.


// This file is autogenerated by
//     third_party/jni_zero/jni_generator.py
// For
//     org/webrtc/CryptoOptions

#ifndef org_webrtc_CryptoOptions_JNI
#define org_webrtc_CryptoOptions_JNI

#include <jni.h>

#include "third_party/jni_zero/jni_export.h"
#include "sdk/android/src/jni/jni_generator_helper.h"


// Step 1: Forward declarations.

JNI_ZERO_COMPONENT_BUILD_EXPORT extern const char kClassPath_org_webrtc_CryptoOptions[];
const char kClassPath_org_webrtc_CryptoOptions[] = "org/webrtc/CryptoOptions";

JNI_ZERO_COMPONENT_BUILD_EXPORT extern const char kClassPath_org_webrtc_CryptoOptions_00024SFrame[];
const char kClassPath_org_webrtc_CryptoOptions_00024SFrame[] = "org/webrtc/CryptoOptions$SFrame";

JNI_ZERO_COMPONENT_BUILD_EXPORT extern const char kClassPath_org_webrtc_CryptoOptions_00024Srtp[];
const char kClassPath_org_webrtc_CryptoOptions_00024Srtp[] = "org/webrtc/CryptoOptions$Srtp";
// Leaking this jclass as we cannot use LazyInstance from some threads.
JNI_ZERO_COMPONENT_BUILD_EXPORT std::atomic<jclass> g_org_webrtc_CryptoOptions_clazz(nullptr);
#ifndef org_webrtc_CryptoOptions_clazz_defined
#define org_webrtc_CryptoOptions_clazz_defined
inline jclass org_webrtc_CryptoOptions_clazz(JNIEnv* env) {
  return jni_zero::LazyGetClass(env, kClassPath_org_webrtc_CryptoOptions,
      &g_org_webrtc_CryptoOptions_clazz);
}
#endif
// Leaking this jclass as we cannot use LazyInstance from some threads.
JNI_ZERO_COMPONENT_BUILD_EXPORT std::atomic<jclass>
    g_org_webrtc_CryptoOptions_00024SFrame_clazz(nullptr);
#ifndef org_webrtc_CryptoOptions_00024SFrame_clazz_defined
#define org_webrtc_CryptoOptions_00024SFrame_clazz_defined
inline jclass org_webrtc_CryptoOptions_00024SFrame_clazz(JNIEnv* env) {
  return jni_zero::LazyGetClass(env, kClassPath_org_webrtc_CryptoOptions_00024SFrame,
      &g_org_webrtc_CryptoOptions_00024SFrame_clazz);
}
#endif
// Leaking this jclass as we cannot use LazyInstance from some threads.
JNI_ZERO_COMPONENT_BUILD_EXPORT std::atomic<jclass>
    g_org_webrtc_CryptoOptions_00024Srtp_clazz(nullptr);
#ifndef org_webrtc_CryptoOptions_00024Srtp_clazz_defined
#define org_webrtc_CryptoOptions_00024Srtp_clazz_defined
inline jclass org_webrtc_CryptoOptions_00024Srtp_clazz(JNIEnv* env) {
  return jni_zero::LazyGetClass(env, kClassPath_org_webrtc_CryptoOptions_00024Srtp,
      &g_org_webrtc_CryptoOptions_00024Srtp_clazz);
}
#endif


// Step 2: Constants (optional).


// Step 3: Method stubs.
namespace webrtc {
namespace jni {


static std::atomic<jmethodID> g_org_webrtc_CryptoOptions_getSFrame0(nullptr);
static jni_zero::ScopedJavaLocalRef<jobject> Java_CryptoOptions_getSFrame(JNIEnv* env, const
    jni_zero::JavaRef<jobject>& obj) {
  jclass clazz = org_webrtc_CryptoOptions_clazz(env);
  CHECK_CLAZZ(env, obj.obj(),
      org_webrtc_CryptoOptions_clazz(env), nullptr);

  jni_zero::JniJavaCallContextChecked call_context;
  call_context.Init<
      jni_zero::MethodID::TYPE_INSTANCE>(
          env,
          clazz,
          "getSFrame",
          "()Lorg/webrtc/CryptoOptions$SFrame;",
          &g_org_webrtc_CryptoOptions_getSFrame0);

  jobject ret =
      env->CallObjectMethod(obj.obj(),
          call_context.base.method_id);
  return jni_zero::ScopedJavaLocalRef<jobject>(env, ret);
}

static std::atomic<jmethodID> g_org_webrtc_CryptoOptions_getSrtp0(nullptr);
static jni_zero::ScopedJavaLocalRef<jobject> Java_CryptoOptions_getSrtp(JNIEnv* env, const
    jni_zero::JavaRef<jobject>& obj) {
  jclass clazz = org_webrtc_CryptoOptions_clazz(env);
  CHECK_CLAZZ(env, obj.obj(),
      org_webrtc_CryptoOptions_clazz(env), nullptr);

  jni_zero::JniJavaCallContextChecked call_context;
  call_context.Init<
      jni_zero::MethodID::TYPE_INSTANCE>(
          env,
          clazz,
          "getSrtp",
          "()Lorg/webrtc/CryptoOptions$Srtp;",
          &g_org_webrtc_CryptoOptions_getSrtp0);

  jobject ret =
      env->CallObjectMethod(obj.obj(),
          call_context.base.method_id);
  return jni_zero::ScopedJavaLocalRef<jobject>(env, ret);
}

static std::atomic<jmethodID>
    g_org_webrtc_CryptoOptions_00024SFrame_getRequireFrameEncryption0(nullptr);
static jboolean Java_SFrame_getRequireFrameEncryption(JNIEnv* env, const jni_zero::JavaRef<jobject>&
    obj) {
  jclass clazz = org_webrtc_CryptoOptions_00024SFrame_clazz(env);
  CHECK_CLAZZ(env, obj.obj(),
      org_webrtc_CryptoOptions_00024SFrame_clazz(env), false);

  jni_zero::JniJavaCallContextChecked call_context;
  call_context.Init<
      jni_zero::MethodID::TYPE_INSTANCE>(
          env,
          clazz,
          "getRequireFrameEncryption",
          "()Z",
          &g_org_webrtc_CryptoOptions_00024SFrame_getRequireFrameEncryption0);

  jboolean ret =
      env->CallBooleanMethod(obj.obj(),
          call_context.base.method_id);
  return ret;
}

static std::atomic<jmethodID>
    g_org_webrtc_CryptoOptions_00024Srtp_getEnableAes128Sha1_32CryptoCipher0(nullptr);
static jboolean Java_Srtp_getEnableAes128Sha1_32CryptoCipher(JNIEnv* env, const
    jni_zero::JavaRef<jobject>& obj) {
  jclass clazz = org_webrtc_CryptoOptions_00024Srtp_clazz(env);
  CHECK_CLAZZ(env, obj.obj(),
      org_webrtc_CryptoOptions_00024Srtp_clazz(env), false);

  jni_zero::JniJavaCallContextChecked call_context;
  call_context.Init<
      jni_zero::MethodID::TYPE_INSTANCE>(
          env,
          clazz,
          "getEnableAes128Sha1_32CryptoCipher",
          "()Z",
          &g_org_webrtc_CryptoOptions_00024Srtp_getEnableAes128Sha1_32CryptoCipher0);

  jboolean ret =
      env->CallBooleanMethod(obj.obj(),
          call_context.base.method_id);
  return ret;
}

static std::atomic<jmethodID>
    g_org_webrtc_CryptoOptions_00024Srtp_getEnableEncryptedRtpHeaderExtensions0(nullptr);
static jboolean Java_Srtp_getEnableEncryptedRtpHeaderExtensions(JNIEnv* env, const
    jni_zero::JavaRef<jobject>& obj) {
  jclass clazz = org_webrtc_CryptoOptions_00024Srtp_clazz(env);
  CHECK_CLAZZ(env, obj.obj(),
      org_webrtc_CryptoOptions_00024Srtp_clazz(env), false);

  jni_zero::JniJavaCallContextChecked call_context;
  call_context.Init<
      jni_zero::MethodID::TYPE_INSTANCE>(
          env,
          clazz,
          "getEnableEncryptedRtpHeaderExtensions",
          "()Z",
          &g_org_webrtc_CryptoOptions_00024Srtp_getEnableEncryptedRtpHeaderExtensions0);

  jboolean ret =
      env->CallBooleanMethod(obj.obj(),
          call_context.base.method_id);
  return ret;
}

static std::atomic<jmethodID>
    g_org_webrtc_CryptoOptions_00024Srtp_getEnableGcmCryptoSuites0(nullptr);
static jboolean Java_Srtp_getEnableGcmCryptoSuites(JNIEnv* env, const jni_zero::JavaRef<jobject>&
    obj) {
  jclass clazz = org_webrtc_CryptoOptions_00024Srtp_clazz(env);
  CHECK_CLAZZ(env, obj.obj(),
      org_webrtc_CryptoOptions_00024Srtp_clazz(env), false);

  jni_zero::JniJavaCallContextChecked call_context;
  call_context.Init<
      jni_zero::MethodID::TYPE_INSTANCE>(
          env,
          clazz,
          "getEnableGcmCryptoSuites",
          "()Z",
          &g_org_webrtc_CryptoOptions_00024Srtp_getEnableGcmCryptoSuites0);

  jboolean ret =
      env->CallBooleanMethod(obj.obj(),
          call_context.base.method_id);
  return ret;
}

}  // namespace jni
}  // namespace webrtc

#endif  // org_webrtc_CryptoOptions_JNI
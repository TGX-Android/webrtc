// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.


// This file is autogenerated by
//     third_party/jni_zero/jni_generator.py
// For
//     org/webrtc/audio/WebRtcAudioRecord

#ifndef org_webrtc_audio_WebRtcAudioRecord_JNI
#define org_webrtc_audio_WebRtcAudioRecord_JNI

#include <jni.h>

#include "third_party/jni_zero/jni_export.h"
#include "sdk/android/src/jni/jni_generator_helper.h"


// Step 1: Forward declarations.

JNI_ZERO_COMPONENT_BUILD_EXPORT extern const char kClassPath_org_webrtc_audio_WebRtcAudioRecord[];
const char kClassPath_org_webrtc_audio_WebRtcAudioRecord[] = "org/webrtc/audio/WebRtcAudioRecord";
// Leaking this jclass as we cannot use LazyInstance from some threads.
JNI_ZERO_COMPONENT_BUILD_EXPORT std::atomic<jclass>
    g_org_webrtc_audio_WebRtcAudioRecord_clazz(nullptr);
#ifndef org_webrtc_audio_WebRtcAudioRecord_clazz_defined
#define org_webrtc_audio_WebRtcAudioRecord_clazz_defined
inline jclass org_webrtc_audio_WebRtcAudioRecord_clazz(JNIEnv* env) {
  return jni_zero::LazyGetClass(env, kClassPath_org_webrtc_audio_WebRtcAudioRecord,
      &g_org_webrtc_audio_WebRtcAudioRecord_clazz);
}
#endif


// Step 2: Constants (optional).


// Step 3: Method stubs.
namespace webrtc {
namespace jni {

JNI_BOUNDARY_EXPORT void Java_org_webrtc_audio_WebRtcAudioRecord_nativeCacheDirectBufferAddress(
    JNIEnv* env,
    jobject jcaller,
    jlong nativeAudioRecordJni,
    jobject byteBuffer) {
  AudioRecordJni* native = reinterpret_cast<AudioRecordJni*>(nativeAudioRecordJni);
  CHECK_NATIVE_PTR(env, jcaller, native, "CacheDirectBufferAddress");
  return native->CacheDirectBufferAddress(env, jni_zero::JavaParamRef<jobject>(env, jcaller),
      jni_zero::JavaParamRef<jobject>(env, byteBuffer));
}

JNI_BOUNDARY_EXPORT void Java_org_webrtc_audio_WebRtcAudioRecord_nativeDataIsRecorded(
    JNIEnv* env,
    jobject jcaller,
    jlong nativeAudioRecordJni,
    jint bytes,
    jlong captureTimestampNs) {
  AudioRecordJni* native = reinterpret_cast<AudioRecordJni*>(nativeAudioRecordJni);
  CHECK_NATIVE_PTR(env, jcaller, native, "DataIsRecorded");
  return native->DataIsRecorded(env, jni_zero::JavaParamRef<jobject>(env, jcaller), bytes,
      captureTimestampNs);
}


static std::atomic<jmethodID> g_org_webrtc_audio_WebRtcAudioRecord_Constructor2(nullptr);
static jni_zero::ScopedJavaLocalRef<jobject> Java_WebRtcAudioRecord_Constructor(JNIEnv* env, const
    jni_zero::JavaRef<jobject>& context,
    const jni_zero::JavaRef<jobject>& audioManager) {
  jclass clazz = org_webrtc_audio_WebRtcAudioRecord_clazz(env);
  CHECK_CLAZZ(env, clazz,
      org_webrtc_audio_WebRtcAudioRecord_clazz(env), nullptr);

  jni_zero::JniJavaCallContextChecked call_context;
  call_context.Init<
      jni_zero::MethodID::TYPE_INSTANCE>(
          env,
          clazz,
          "<init>",
          "(Landroid/content/Context;Landroid/media/AudioManager;)V",
          &g_org_webrtc_audio_WebRtcAudioRecord_Constructor2);

  jobject ret =
      env->NewObject(clazz,
          call_context.base.method_id, context.obj(), audioManager.obj());
  return jni_zero::ScopedJavaLocalRef<jobject>(env, ret);
}

static std::atomic<jmethodID> g_org_webrtc_audio_WebRtcAudioRecord_enableBuiltInAEC1(nullptr);
static jboolean Java_WebRtcAudioRecord_enableBuiltInAEC(JNIEnv* env, const
    jni_zero::JavaRef<jobject>& obj, jboolean enable) {
  jclass clazz = org_webrtc_audio_WebRtcAudioRecord_clazz(env);
  CHECK_CLAZZ(env, obj.obj(),
      org_webrtc_audio_WebRtcAudioRecord_clazz(env), false);

  jni_zero::JniJavaCallContextChecked call_context;
  call_context.Init<
      jni_zero::MethodID::TYPE_INSTANCE>(
          env,
          clazz,
          "enableBuiltInAEC",
          "(Z)Z",
          &g_org_webrtc_audio_WebRtcAudioRecord_enableBuiltInAEC1);

  jboolean ret =
      env->CallBooleanMethod(obj.obj(),
          call_context.base.method_id, enable);
  return ret;
}

static std::atomic<jmethodID> g_org_webrtc_audio_WebRtcAudioRecord_enableBuiltInNS1(nullptr);
static jboolean Java_WebRtcAudioRecord_enableBuiltInNS(JNIEnv* env, const
    jni_zero::JavaRef<jobject>& obj, jboolean enable) {
  jclass clazz = org_webrtc_audio_WebRtcAudioRecord_clazz(env);
  CHECK_CLAZZ(env, obj.obj(),
      org_webrtc_audio_WebRtcAudioRecord_clazz(env), false);

  jni_zero::JniJavaCallContextChecked call_context;
  call_context.Init<
      jni_zero::MethodID::TYPE_INSTANCE>(
          env,
          clazz,
          "enableBuiltInNS",
          "(Z)Z",
          &g_org_webrtc_audio_WebRtcAudioRecord_enableBuiltInNS1);

  jboolean ret =
      env->CallBooleanMethod(obj.obj(),
          call_context.base.method_id, enable);
  return ret;
}

static std::atomic<jmethodID> g_org_webrtc_audio_WebRtcAudioRecord_initRecording2(nullptr);
static jint Java_WebRtcAudioRecord_initRecording(JNIEnv* env, const jni_zero::JavaRef<jobject>& obj,
    JniIntWrapper sampleRate,
    JniIntWrapper channels) {
  jclass clazz = org_webrtc_audio_WebRtcAudioRecord_clazz(env);
  CHECK_CLAZZ(env, obj.obj(),
      org_webrtc_audio_WebRtcAudioRecord_clazz(env), 0);

  jni_zero::JniJavaCallContextChecked call_context;
  call_context.Init<
      jni_zero::MethodID::TYPE_INSTANCE>(
          env,
          clazz,
          "initRecording",
          "(II)I",
          &g_org_webrtc_audio_WebRtcAudioRecord_initRecording2);

  jint ret =
      env->CallIntMethod(obj.obj(),
          call_context.base.method_id, as_jint(sampleRate), as_jint(channels));
  return ret;
}

static std::atomic<jmethodID>
    g_org_webrtc_audio_WebRtcAudioRecord_isAcousticEchoCancelerSupported0(nullptr);
static jboolean Java_WebRtcAudioRecord_isAcousticEchoCancelerSupported(JNIEnv* env, const
    jni_zero::JavaRef<jobject>& obj) {
  jclass clazz = org_webrtc_audio_WebRtcAudioRecord_clazz(env);
  CHECK_CLAZZ(env, obj.obj(),
      org_webrtc_audio_WebRtcAudioRecord_clazz(env), false);

  jni_zero::JniJavaCallContextChecked call_context;
  call_context.Init<
      jni_zero::MethodID::TYPE_INSTANCE>(
          env,
          clazz,
          "isAcousticEchoCancelerSupported",
          "()Z",
          &g_org_webrtc_audio_WebRtcAudioRecord_isAcousticEchoCancelerSupported0);

  jboolean ret =
      env->CallBooleanMethod(obj.obj(),
          call_context.base.method_id);
  return ret;
}

static std::atomic<jmethodID> g_org_webrtc_audio_WebRtcAudioRecord_isAudioConfigVerified0(nullptr);
static jboolean Java_WebRtcAudioRecord_isAudioConfigVerified(JNIEnv* env, const
    jni_zero::JavaRef<jobject>& obj) {
  jclass clazz = org_webrtc_audio_WebRtcAudioRecord_clazz(env);
  CHECK_CLAZZ(env, obj.obj(),
      org_webrtc_audio_WebRtcAudioRecord_clazz(env), false);

  jni_zero::JniJavaCallContextChecked call_context;
  call_context.Init<
      jni_zero::MethodID::TYPE_INSTANCE>(
          env,
          clazz,
          "isAudioConfigVerified",
          "()Z",
          &g_org_webrtc_audio_WebRtcAudioRecord_isAudioConfigVerified0);

  jboolean ret =
      env->CallBooleanMethod(obj.obj(),
          call_context.base.method_id);
  return ret;
}

static std::atomic<jmethodID>
    g_org_webrtc_audio_WebRtcAudioRecord_isAudioSourceMatchingRecordingSession0(nullptr);
static jboolean Java_WebRtcAudioRecord_isAudioSourceMatchingRecordingSession(JNIEnv* env, const
    jni_zero::JavaRef<jobject>& obj) {
  jclass clazz = org_webrtc_audio_WebRtcAudioRecord_clazz(env);
  CHECK_CLAZZ(env, obj.obj(),
      org_webrtc_audio_WebRtcAudioRecord_clazz(env), false);

  jni_zero::JniJavaCallContextChecked call_context;
  call_context.Init<
      jni_zero::MethodID::TYPE_INSTANCE>(
          env,
          clazz,
          "isAudioSourceMatchingRecordingSession",
          "()Z",
          &g_org_webrtc_audio_WebRtcAudioRecord_isAudioSourceMatchingRecordingSession0);

  jboolean ret =
      env->CallBooleanMethod(obj.obj(),
          call_context.base.method_id);
  return ret;
}

static std::atomic<jmethodID>
    g_org_webrtc_audio_WebRtcAudioRecord_isNoiseSuppressorSupported0(nullptr);
static jboolean Java_WebRtcAudioRecord_isNoiseSuppressorSupported(JNIEnv* env, const
    jni_zero::JavaRef<jobject>& obj) {
  jclass clazz = org_webrtc_audio_WebRtcAudioRecord_clazz(env);
  CHECK_CLAZZ(env, obj.obj(),
      org_webrtc_audio_WebRtcAudioRecord_clazz(env), false);

  jni_zero::JniJavaCallContextChecked call_context;
  call_context.Init<
      jni_zero::MethodID::TYPE_INSTANCE>(
          env,
          clazz,
          "isNoiseSuppressorSupported",
          "()Z",
          &g_org_webrtc_audio_WebRtcAudioRecord_isNoiseSuppressorSupported0);

  jboolean ret =
      env->CallBooleanMethod(obj.obj(),
          call_context.base.method_id);
  return ret;
}

static std::atomic<jmethodID> g_org_webrtc_audio_WebRtcAudioRecord_setNativeAudioRecord1(nullptr);
static void Java_WebRtcAudioRecord_setNativeAudioRecord(JNIEnv* env, const
    jni_zero::JavaRef<jobject>& obj, jlong nativeAudioRecord) {
  jclass clazz = org_webrtc_audio_WebRtcAudioRecord_clazz(env);
  CHECK_CLAZZ(env, obj.obj(),
      org_webrtc_audio_WebRtcAudioRecord_clazz(env));

  jni_zero::JniJavaCallContextChecked call_context;
  call_context.Init<
      jni_zero::MethodID::TYPE_INSTANCE>(
          env,
          clazz,
          "setNativeAudioRecord",
          "(J)V",
          &g_org_webrtc_audio_WebRtcAudioRecord_setNativeAudioRecord1);

     env->CallVoidMethod(obj.obj(),
          call_context.base.method_id, nativeAudioRecord);
}

static std::atomic<jmethodID> g_org_webrtc_audio_WebRtcAudioRecord_startRecording0(nullptr);
static jboolean Java_WebRtcAudioRecord_startRecording(JNIEnv* env, const jni_zero::JavaRef<jobject>&
    obj) {
  jclass clazz = org_webrtc_audio_WebRtcAudioRecord_clazz(env);
  CHECK_CLAZZ(env, obj.obj(),
      org_webrtc_audio_WebRtcAudioRecord_clazz(env), false);

  jni_zero::JniJavaCallContextChecked call_context;
  call_context.Init<
      jni_zero::MethodID::TYPE_INSTANCE>(
          env,
          clazz,
          "startRecording",
          "()Z",
          &g_org_webrtc_audio_WebRtcAudioRecord_startRecording0);

  jboolean ret =
      env->CallBooleanMethod(obj.obj(),
          call_context.base.method_id);
  return ret;
}

static std::atomic<jmethodID> g_org_webrtc_audio_WebRtcAudioRecord_stopRecording0(nullptr);
static jboolean Java_WebRtcAudioRecord_stopRecording(JNIEnv* env, const jni_zero::JavaRef<jobject>&
    obj) {
  jclass clazz = org_webrtc_audio_WebRtcAudioRecord_clazz(env);
  CHECK_CLAZZ(env, obj.obj(),
      org_webrtc_audio_WebRtcAudioRecord_clazz(env), false);

  jni_zero::JniJavaCallContextChecked call_context;
  call_context.Init<
      jni_zero::MethodID::TYPE_INSTANCE>(
          env,
          clazz,
          "stopRecording",
          "()Z",
          &g_org_webrtc_audio_WebRtcAudioRecord_stopRecording0);

  jboolean ret =
      env->CallBooleanMethod(obj.obj(),
          call_context.base.method_id);
  return ret;
}

}  // namespace jni
}  // namespace webrtc

#endif  // org_webrtc_audio_WebRtcAudioRecord_JNI
// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.


// This file is autogenerated by
//     third_party/jni_zero/jni_generator.py
// For
//     org/webrtc/audio/WebRtcAudioManager

#ifndef org_webrtc_audio_WebRtcAudioManager_JNI
#define org_webrtc_audio_WebRtcAudioManager_JNI

#include <jni.h>

#include "third_party/jni_zero/jni_export.h"
#include "sdk/android/src/jni/jni_generator_helper.h"


// Step 1: Forward declarations.

JNI_ZERO_COMPONENT_BUILD_EXPORT extern const char kClassPath_org_webrtc_audio_WebRtcAudioManager[];
const char kClassPath_org_webrtc_audio_WebRtcAudioManager[] = "org/webrtc/audio/WebRtcAudioManager";
// Leaking this jclass as we cannot use LazyInstance from some threads.
JNI_ZERO_COMPONENT_BUILD_EXPORT std::atomic<jclass>
    g_org_webrtc_audio_WebRtcAudioManager_clazz(nullptr);
#ifndef org_webrtc_audio_WebRtcAudioManager_clazz_defined
#define org_webrtc_audio_WebRtcAudioManager_clazz_defined
inline jclass org_webrtc_audio_WebRtcAudioManager_clazz(JNIEnv* env) {
  return jni_zero::LazyGetClass(env, kClassPath_org_webrtc_audio_WebRtcAudioManager,
      &g_org_webrtc_audio_WebRtcAudioManager_clazz);
}
#endif


// Step 2: Constants (optional).


// Step 3: Method stubs.
namespace webrtc {
namespace jni {


static std::atomic<jmethodID> g_org_webrtc_audio_WebRtcAudioManager_getAudioManager1(nullptr);
static jni_zero::ScopedJavaLocalRef<jobject> Java_WebRtcAudioManager_getAudioManager(JNIEnv* env,
    const jni_zero::JavaRef<jobject>& context) {
  jclass clazz = org_webrtc_audio_WebRtcAudioManager_clazz(env);
  CHECK_CLAZZ(env, clazz,
      org_webrtc_audio_WebRtcAudioManager_clazz(env), nullptr);

  jni_zero::JniJavaCallContextChecked call_context;
  call_context.Init<
      jni_zero::MethodID::TYPE_STATIC>(
          env,
          clazz,
          "getAudioManager",
          "(Landroid/content/Context;)Landroid/media/AudioManager;",
          &g_org_webrtc_audio_WebRtcAudioManager_getAudioManager1);

  jobject ret =
      env->CallStaticObjectMethod(clazz,
          call_context.base.method_id, context.obj());
  return jni_zero::ScopedJavaLocalRef<jobject>(env, ret);
}

static std::atomic<jmethodID> g_org_webrtc_audio_WebRtcAudioManager_getInputBufferSize4(nullptr);
static jint Java_WebRtcAudioManager_getInputBufferSize(JNIEnv* env, const
    jni_zero::JavaRef<jobject>& context,
    const jni_zero::JavaRef<jobject>& audioManager,
    JniIntWrapper sampleRate,
    JniIntWrapper numberOfInputChannels) {
  jclass clazz = org_webrtc_audio_WebRtcAudioManager_clazz(env);
  CHECK_CLAZZ(env, clazz,
      org_webrtc_audio_WebRtcAudioManager_clazz(env), 0);

  jni_zero::JniJavaCallContextChecked call_context;
  call_context.Init<
      jni_zero::MethodID::TYPE_STATIC>(
          env,
          clazz,
          "getInputBufferSize",
          "(Landroid/content/Context;Landroid/media/AudioManager;II)I",
          &g_org_webrtc_audio_WebRtcAudioManager_getInputBufferSize4);

  jint ret =
      env->CallStaticIntMethod(clazz,
          call_context.base.method_id, context.obj(), audioManager.obj(), as_jint(sampleRate),
              as_jint(numberOfInputChannels));
  return ret;
}

static std::atomic<jmethodID> g_org_webrtc_audio_WebRtcAudioManager_getOutputBufferSize4(nullptr);
static jint Java_WebRtcAudioManager_getOutputBufferSize(JNIEnv* env, const
    jni_zero::JavaRef<jobject>& context,
    const jni_zero::JavaRef<jobject>& audioManager,
    JniIntWrapper sampleRate,
    JniIntWrapper numberOfOutputChannels) {
  jclass clazz = org_webrtc_audio_WebRtcAudioManager_clazz(env);
  CHECK_CLAZZ(env, clazz,
      org_webrtc_audio_WebRtcAudioManager_clazz(env), 0);

  jni_zero::JniJavaCallContextChecked call_context;
  call_context.Init<
      jni_zero::MethodID::TYPE_STATIC>(
          env,
          clazz,
          "getOutputBufferSize",
          "(Landroid/content/Context;Landroid/media/AudioManager;II)I",
          &g_org_webrtc_audio_WebRtcAudioManager_getOutputBufferSize4);

  jint ret =
      env->CallStaticIntMethod(clazz,
          call_context.base.method_id, context.obj(), audioManager.obj(), as_jint(sampleRate),
              as_jint(numberOfOutputChannels));
  return ret;
}

static std::atomic<jmethodID> g_org_webrtc_audio_WebRtcAudioManager_getSampleRate1(nullptr);
static jint Java_WebRtcAudioManager_getSampleRate(JNIEnv* env, const jni_zero::JavaRef<jobject>&
    audioManager) {
  jclass clazz = org_webrtc_audio_WebRtcAudioManager_clazz(env);
  CHECK_CLAZZ(env, clazz,
      org_webrtc_audio_WebRtcAudioManager_clazz(env), 0);

  jni_zero::JniJavaCallContextChecked call_context;
  call_context.Init<
      jni_zero::MethodID::TYPE_STATIC>(
          env,
          clazz,
          "getSampleRate",
          "(Landroid/media/AudioManager;)I",
          &g_org_webrtc_audio_WebRtcAudioManager_getSampleRate1);

  jint ret =
      env->CallStaticIntMethod(clazz,
          call_context.base.method_id, audioManager.obj());
  return ret;
}

static std::atomic<jmethodID>
    g_org_webrtc_audio_WebRtcAudioManager_isLowLatencyInputSupported1(nullptr);
static jboolean Java_WebRtcAudioManager_isLowLatencyInputSupported(JNIEnv* env, const
    jni_zero::JavaRef<jobject>& context) {
  jclass clazz = org_webrtc_audio_WebRtcAudioManager_clazz(env);
  CHECK_CLAZZ(env, clazz,
      org_webrtc_audio_WebRtcAudioManager_clazz(env), false);

  jni_zero::JniJavaCallContextChecked call_context;
  call_context.Init<
      jni_zero::MethodID::TYPE_STATIC>(
          env,
          clazz,
          "isLowLatencyInputSupported",
          "(Landroid/content/Context;)Z",
          &g_org_webrtc_audio_WebRtcAudioManager_isLowLatencyInputSupported1);

  jboolean ret =
      env->CallStaticBooleanMethod(clazz,
          call_context.base.method_id, context.obj());
  return ret;
}

static std::atomic<jmethodID>
    g_org_webrtc_audio_WebRtcAudioManager_isLowLatencyOutputSupported1(nullptr);
static jboolean Java_WebRtcAudioManager_isLowLatencyOutputSupported(JNIEnv* env, const
    jni_zero::JavaRef<jobject>& context) {
  jclass clazz = org_webrtc_audio_WebRtcAudioManager_clazz(env);
  CHECK_CLAZZ(env, clazz,
      org_webrtc_audio_WebRtcAudioManager_clazz(env), false);

  jni_zero::JniJavaCallContextChecked call_context;
  call_context.Init<
      jni_zero::MethodID::TYPE_STATIC>(
          env,
          clazz,
          "isLowLatencyOutputSupported",
          "(Landroid/content/Context;)Z",
          &g_org_webrtc_audio_WebRtcAudioManager_isLowLatencyOutputSupported1);

  jboolean ret =
      env->CallStaticBooleanMethod(clazz,
          call_context.base.method_id, context.obj());
  return ret;
}

}  // namespace jni
}  // namespace webrtc

#endif  // org_webrtc_audio_WebRtcAudioManager_JNI
// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.


// This file is autogenerated by
//     third_party/jni_zero/jni_generator.py
// For
//     org/webrtc/NativeAndroidVideoTrackSource

#ifndef org_webrtc_NativeAndroidVideoTrackSource_JNI
#define org_webrtc_NativeAndroidVideoTrackSource_JNI

#include <jni.h>

#include "third_party/jni_zero/jni_export.h"
#include "sdk/android/src/jni/jni_generator_helper.h"


// Step 1: Forward declarations.

JNI_ZERO_COMPONENT_BUILD_EXPORT extern const char
    kClassPath_org_webrtc_NativeAndroidVideoTrackSource[];
const char kClassPath_org_webrtc_NativeAndroidVideoTrackSource[] =
    "org/webrtc/NativeAndroidVideoTrackSource";
// Leaking this jclass as we cannot use LazyInstance from some threads.
JNI_ZERO_COMPONENT_BUILD_EXPORT std::atomic<jclass>
    g_org_webrtc_NativeAndroidVideoTrackSource_clazz(nullptr);
#ifndef org_webrtc_NativeAndroidVideoTrackSource_clazz_defined
#define org_webrtc_NativeAndroidVideoTrackSource_clazz_defined
inline jclass org_webrtc_NativeAndroidVideoTrackSource_clazz(JNIEnv* env) {
  return jni_zero::LazyGetClass(env, kClassPath_org_webrtc_NativeAndroidVideoTrackSource,
      &g_org_webrtc_NativeAndroidVideoTrackSource_clazz);
}
#endif


// Step 2: Constants (optional).


// Step 3: Method stubs.
namespace webrtc {
namespace jni {

JNI_BOUNDARY_EXPORT jobject Java_org_webrtc_NativeAndroidVideoTrackSource_nativeAdaptFrame(
    JNIEnv* env,
    jclass jcaller,
    jlong nativeAndroidVideoTrackSource,
    jint width,
    jint height,
    jint rotation,
    jlong timestampNs) {
  AndroidVideoTrackSource* native =
      reinterpret_cast<AndroidVideoTrackSource*>(nativeAndroidVideoTrackSource);
  CHECK_NATIVE_PTR(env, jcaller, native, "AdaptFrame", nullptr);
  return native->AdaptFrame(env, width, height, rotation, timestampNs).Release();
}

JNI_BOUNDARY_EXPORT void Java_org_webrtc_NativeAndroidVideoTrackSource_nativeAdaptOutputFormat(
    JNIEnv* env,
    jclass jcaller,
    jlong nativeAndroidVideoTrackSource,
    jint landscapeWidth,
    jint landscapeHeight,
    jobject maxLandscapePixelCount,
    jint portraitWidth,
    jint portraitHeight,
    jobject maxPortraitPixelCount,
    jobject maxFps) {
  AndroidVideoTrackSource* native =
      reinterpret_cast<AndroidVideoTrackSource*>(nativeAndroidVideoTrackSource);
  CHECK_NATIVE_PTR(env, jcaller, native, "AdaptOutputFormat");
  return native->AdaptOutputFormat(env, landscapeWidth, landscapeHeight,
      jni_zero::JavaParamRef<jobject>(env, maxLandscapePixelCount), portraitWidth, portraitHeight,
      jni_zero::JavaParamRef<jobject>(env, maxPortraitPixelCount),
      jni_zero::JavaParamRef<jobject>(env, maxFps));
}

JNI_BOUNDARY_EXPORT void Java_org_webrtc_NativeAndroidVideoTrackSource_nativeOnFrameCaptured(
    JNIEnv* env,
    jclass jcaller,
    jlong nativeAndroidVideoTrackSource,
    jint rotation,
    jlong timestampNs,
    jobject buffer) {
  AndroidVideoTrackSource* native =
      reinterpret_cast<AndroidVideoTrackSource*>(nativeAndroidVideoTrackSource);
  CHECK_NATIVE_PTR(env, jcaller, native, "OnFrameCaptured");
  return native->OnFrameCaptured(env, rotation, timestampNs, jni_zero::JavaParamRef<jobject>(env,
      buffer));
}

JNI_BOUNDARY_EXPORT void Java_org_webrtc_NativeAndroidVideoTrackSource_nativeSetIsScreencast(
    JNIEnv* env,
    jclass jcaller,
    jlong nativeAndroidVideoTrackSource,
    jboolean isScreencast) {
  AndroidVideoTrackSource* native =
      reinterpret_cast<AndroidVideoTrackSource*>(nativeAndroidVideoTrackSource);
  CHECK_NATIVE_PTR(env, jcaller, native, "SetIsScreencast");
  return native->SetIsScreencast(env, isScreencast);
}

JNI_BOUNDARY_EXPORT void Java_org_webrtc_NativeAndroidVideoTrackSource_nativeSetState(
    JNIEnv* env,
    jclass jcaller,
    jlong nativeAndroidVideoTrackSource,
    jboolean isLive) {
  AndroidVideoTrackSource* native =
      reinterpret_cast<AndroidVideoTrackSource*>(nativeAndroidVideoTrackSource);
  CHECK_NATIVE_PTR(env, jcaller, native, "SetState");
  return native->SetState(env, isLive);
}


static std::atomic<jmethodID>
    g_org_webrtc_NativeAndroidVideoTrackSource_createFrameAdaptationParameters8(nullptr);
static jni_zero::ScopedJavaLocalRef<jobject>
    Java_NativeAndroidVideoTrackSource_createFrameAdaptationParameters(JNIEnv* env, JniIntWrapper
    cropX,
    JniIntWrapper cropY,
    JniIntWrapper cropWidth,
    JniIntWrapper cropHeight,
    JniIntWrapper scaleWidth,
    JniIntWrapper scaleHeight,
    jlong timestampNs,
    jboolean drop) {
  jclass clazz = org_webrtc_NativeAndroidVideoTrackSource_clazz(env);
  CHECK_CLAZZ(env, clazz,
      org_webrtc_NativeAndroidVideoTrackSource_clazz(env), nullptr);

  jni_zero::JniJavaCallContextChecked call_context;
  call_context.Init<
      jni_zero::MethodID::TYPE_STATIC>(
          env,
          clazz,
          "createFrameAdaptationParameters",
          "(IIIIIIJZ)Lorg/webrtc/VideoProcessor$FrameAdaptationParameters;",
          &g_org_webrtc_NativeAndroidVideoTrackSource_createFrameAdaptationParameters8);

  jobject ret =
      env->CallStaticObjectMethod(clazz,
          call_context.base.method_id, as_jint(cropX), as_jint(cropY), as_jint(cropWidth),
              as_jint(cropHeight), as_jint(scaleWidth), as_jint(scaleHeight), timestampNs, drop);
  return jni_zero::ScopedJavaLocalRef<jobject>(env, ret);
}

}  // namespace jni
}  // namespace webrtc

#endif  // org_webrtc_NativeAndroidVideoTrackSource_JNI
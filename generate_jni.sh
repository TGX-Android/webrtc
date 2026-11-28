#!/usr/bin/env bash
# generate_jni.sh CHROMIUM_THIRD_PARTY ANDROID_JAR JAVAP
#
# Makes generated/ anew: the JNI that jni_zero generates for the Android SDK of WebRTC, as the
# BUILD.gn files of WebRTC and of jni_zero do it, for the targets Telegram X builds (no AV1, no tests):
# the C++ headers, included from generated/, and the Java of @NativeMethods (*Jni.java and
# org/jni_zero/GEN_JNI.java, without hashed names), compiled from generated/java.
#   CHROMIUM_THIRD_PARTY  chromium/src/third_party at the commit DEPS pins, with jni_zero
#   ANDROID_JAR           android.jar of the Android SDK, for the classes of the system
#   JAVAP                 javap of a JDK
set -euo pipefail
webrtc=$(cd "$(dirname "$0")" && pwd) tp=$(cd "$1" && pwd) jar=$2 javap=$3
jz="$tp/jni_zero/jni_zero.py"
out="$webrtc/generated"
tmp=$(mktemp -d)
trap 'rm -rf -- "$tmp"' EXIT
rm -rf -- "$out"
mkdir -p "$out/java" "$tmp/srcjar"
echo '[]' > "$tmp/catalogs.json"
sources_json="$tmp/sources.json"
printf '[{"java_files": [' > "$sources_json"
first=1

# NAME DIR [--namespace=…] -- JAVA...: from-source of the Java files, paths from DIR
from_source() {
  local name=$1 dir=$2 ns=() f n
  shift 2
  if [[ $1 == --namespace=* ]]; then ns=("$1"); shift; fi
  shift
  local -a args=()
  for f in "$@"; do
    n=${f##*/}; n=${n%.java}
    args+=(--shared-header-name "${n}_shared_jni.h" --unshared-header-name "${n}_jni.h" "--input-file=$dir/$f")
    if (( first )); then first=0; else printf ', ' >> "$sources_json"; fi
    printf '"%s"' "$dir/$f" >> "$sources_json"
  done
  python3 "$jz" from-source --output-dir "$out/$name" --enable-safe-pointers \
    --allow-private-called-by-natives --include-path-prefix third_party/jni_zero/ \
    --type-catalogs-file "$tmp/catalogs.json" --srcjar-path "$tmp/srcjar/${name//\//_}.srcjar" \
    --placeholder-srcjar-path "$tmp/${name//\//_}_placeholder.srcjar" \
    --output-type-catalog "$tmp/${name//\//_}.json" "${ns[@]}" "${args[@]}"
}

# NAME [--unchecked-exceptions] -- CLASS...: from-jar of classes of the Android SDK
from_jar() {
  local name=$1 opt=() c n
  shift
  if [[ $1 == --unchecked-exceptions ]]; then opt=("$1"); shift; fi
  shift
  local -a args=()
  for c in "$@"; do
    n=${c##*/}; n=${n%.class}
    args+=(--shared-header-name "${n}_shared_jni.h" --unshared-header-name "${n}_jni.h" "--input-file=$c")
  done
  python3 "$jz" from-jar --output-dir "$out/$name" --include-path-prefix third_party/jni_zero/ \
    --jar-file "$jar" --javap "$javap" "${opt[@]}" "${args[@]}"
}

s=sdk/android
from_jar $s/generated_external_classes_jni -- java/lang/Integer.class java/lang/Double.class \
  java/lang/Long.class java/lang/Iterable.class java/util/Iterator.class java/lang/Boolean.class \
  java/math/BigInteger.class java/util/Map.class java/util/LinkedHashMap.class java/util/ArrayList.class \
  java/lang/Enum.class
from_source $s/generated_environment_jni "$webrtc/$s" --namespace=webrtc::jni -- api/org/webrtc/Environment.java
from_source $s/generated_metrics_jni "$webrtc/$s" --namespace=webrtc::jni -- api/org/webrtc/Metrics.java
from_source $s/generated_base_jni "$webrtc/$s" --namespace=webrtc::jni -- \
  api/org/webrtc/NetworkChangeDetector.java api/org/webrtc/NetworkMonitor.java api/org/webrtc/RefCounted.java \
  src/java/org/webrtc/Histogram.java src/java/org/webrtc/JniCommon.java
from_source $s/generated_video_jni "$webrtc/$s" --namespace=webrtc::jni -- \
  api/org/webrtc/EncodedImage.java api/org/webrtc/JavaI420Buffer.java api/org/webrtc/TimestampAligner.java \
  api/org/webrtc/VideoCodecInfo.java api/org/webrtc/VideoCodecStatus.java api/org/webrtc/VideoDecoder.java \
  api/org/webrtc/VideoDecoderFactory.java api/org/webrtc/VideoDecoderFallback.java api/org/webrtc/VideoEncoder.java \
  api/org/webrtc/VideoEncoderFactory.java api/org/webrtc/VideoEncoderFallback.java api/org/webrtc/VideoFrame.java \
  api/org/webrtc/VideoSink.java api/org/webrtc/VideoTrack.java api/org/webrtc/YuvHelper.java \
  src/java/org/webrtc/H264Utils.java src/java/org/webrtc/NV12Buffer.java src/java/org/webrtc/NV21Buffer.java \
  src/java/org/webrtc/NativeAndroidVideoTrackSource.java src/java/org/webrtc/NativeCapturerObserver.java \
  src/java/org/webrtc/VideoDecoderWrapper.java src/java/org/webrtc/VideoEncoderWrapper.java \
  src/java/org/webrtc/WrappedNativeI420Buffer.java
from_source $s/generated_video_egl_jni "$webrtc/$s" --namespace=webrtc::jni -- src/java/org/webrtc/EglBase10Impl.java
from_source $s/generated_libvpx_vp8_jni "$webrtc/$s" --namespace=webrtc::jni -- \
  api/org/webrtc/LibvpxVp8Decoder.java api/org/webrtc/LibvpxVp8Encoder.java
from_source $s/generated_libvpx_vp9_jni "$webrtc/$s" --namespace=webrtc::jni -- \
  api/org/webrtc/LibvpxVp9Decoder.java api/org/webrtc/LibvpxVp9Encoder.java
from_source $s/generated_software_video_decoder_factory_jni "$webrtc/$s" --namespace=webrtc::jni -- \
  api/org/webrtc/SoftwareVideoDecoderFactory.java
from_source $s/generated_software_video_encoder_factory_jni "$webrtc/$s" --namespace=webrtc::jni -- \
  api/org/webrtc/SoftwareVideoEncoderFactory.java
from_source $s/generated_rtcerror_jni "$webrtc/$s" --namespace=webrtc::jni -- src/java/org/webrtc/RtcError.java
from_source $s/generated_peerconnection_jni "$webrtc/$s" --namespace=webrtc::jni -- \
  api/org/webrtc/AddIceObserver.java api/org/webrtc/AudioTrack.java api/org/webrtc/CallSessionFileRotatingLogSink.java \
  api/org/webrtc/CandidatePairChangeEvent.java api/org/webrtc/CryptoOptions.java api/org/webrtc/DataChannel.java \
  api/org/webrtc/DtlsFingerprint.java api/org/webrtc/DtmfSender.java api/org/webrtc/IceCandidate.java \
  api/org/webrtc/IceCandidateErrorEvent.java api/org/webrtc/MediaConstraints.java api/org/webrtc/MediaSource.java \
  api/org/webrtc/MediaStream.java api/org/webrtc/MediaStreamTrack.java api/org/webrtc/PeerConnection.java \
  api/org/webrtc/PeerConnectionFactory.java api/org/webrtc/RTCStats.java api/org/webrtc/RTCStatsCollectorCallback.java \
  api/org/webrtc/RTCStatsReport.java api/org/webrtc/RtcCertificatePem.java api/org/webrtc/RtpCapabilities.java \
  api/org/webrtc/RtpParameters.java api/org/webrtc/RtpReceiver.java api/org/webrtc/RtpSender.java \
  api/org/webrtc/RtpTransceiver.java api/org/webrtc/SSLCertificateVerifier.java api/org/webrtc/SdpObserver.java \
  api/org/webrtc/SessionDescription.java api/org/webrtc/StatsObserver.java api/org/webrtc/StatsReport.java \
  api/org/webrtc/TurnCustomizer.java
from_source $s/generated_java_audio_jni "$webrtc/$s" --namespace=webrtc::jni -- api/org/webrtc/audio/JavaAudioDeviceModule.java
from_source $s/generated_builtin_audio_codecs_jni "$webrtc/$s" --namespace=webrtc::jni -- \
  api/org/webrtc/BuiltinAudioDecoderFactoryFactory.java api/org/webrtc/BuiltinAudioEncoderFactoryFactory.java
from_source $s/generated_native_api_jni "$webrtc/$s" --namespace=webrtc::jni -- \
  src/java/org/webrtc/ApplicationContextProvider.java src/java/org/webrtc/JniHelper.java \
  src/java/org/webrtc/WebRtcClassLoader.java
from_source $s/generated_logging_jni "$webrtc/$s" -- src/java/org/webrtc/JNILogging.java
from_source $s/generated_audio_device_module_base_jni "$webrtc/$s" --namespace=webrtc::jni -- \
  src/java/org/webrtc/audio/WebRtcAudioManager.java
from_source $s/generated_java_audio_device_module_native_jni "$webrtc/$s" --namespace=webrtc::jni -- \
  src/java/org/webrtc/audio/WebRtcAudioRecord.java src/java/org/webrtc/audio/WebRtcAudioTrack.java
from_source rtc_base/base_java_jni "$webrtc/rtc_base" --namespace=webrtc::jni -- java/src/org/webrtc/Logging.java

j=third_party/jni_zero
from_source $j/generate_jni "$tp/jni_zero" -- java/src/org/jni_zero/CommonApis.java \
  java/src/org/jni_zero/JniPtrImpl.java java/src/org/jni_zero/JniRawPtrImpl.java \
  java/src/org/jni_zero/JniUniquePtrImpl.java java/src/org/jni_zero/JniZero.java
from_jar $j/system_jni -- android/os/Process.class java/lang/Boolean.class java/lang/Integer.class \
  java/lang/Float.class java/lang/Double.class java/lang/Long.class java/lang/Object.class java/lang/Runnable.class \
  java/lang/Runtime.class java/lang/Throwable.class java/util/Arrays.class java/util/Collection.class \
  java/util/List.class java/util/Map.class
from_jar $j/system_jni_unchecked_exceptions --unchecked-exceptions -- java/lang/ClassLoader.class java/nio/ByteBuffer.class

printf ']}]\n' >> "$sources_json"
python3 "$jz" generate-final --java-sources-file "$sources_json" --srcjar-path "$tmp/final.srcjar"

# The Java: *Jni.java of every target, and GEN_JNI of the final step in place of the placeholders
for f in "$tmp"/srcjar/*.srcjar; do
  entries=$(unzip -Z1 "$f" 2>/dev/null || true)
  if [[ -n $entries ]] && grep -qv '^org/jni_zero/GEN_JNI\.java$' <<< "$entries"; then
    unzip -q -o "$f" -d "$out/java" -x 'org/jni_zero/GEN_JNI.java'
  fi
done
unzip -q -o "$tmp/final.srcjar" -d "$out/java"
# javax.annotation.processing.Generated isn't in android.jar, and it's kept only in sources
find "$out/java" -name '*.java' | while IFS= read -r f; do
  grep -v -e '^import javax\.annotation\.processing\.Generated;$' -e '^@Generated("JNI Zero")$' "$f" > "$tmp/java" || true
  cat "$tmp/java" > "$f"
done

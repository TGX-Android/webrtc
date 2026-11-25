/*
 *  Copyright (c) 2015 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#include "modules/audio_coding/codecs/opus/audio_decoder_opus.h"

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <memory>
#include <optional>
#include <span>
#include <utility>
#include <vector>

#include "api/audio_codecs/audio_decoder.h"
#include "api/field_trials_view.h"
#include "modules/audio_coding/codecs/opus/audio_coder_opus_common.h"
#include "modules/audio_coding/codecs/opus/opus_interface.h"
#include "rtc_base/buffer.h"
#include "rtc_base/checks.h"
#include "rtc_base/logging.h"

namespace webrtc {

AudioDecoderOpusImpl::AudioDecoderOpusImpl(
    const FieldTrialsView& field_trials,
    size_t num_channels,
    int sample_rate_hz,
    std::shared_ptr<const std::vector<uint8_t>> dnn_weights)
    : channels_(num_channels),
      sample_rate_hz_(sample_rate_hz),
      generate_plc_(field_trials.IsEnabled("WebRTC-Audio-OpusGeneratePlc")),
      dnn_weights_(std::move(dnn_weights)) {
  RTC_DCHECK(num_channels == 1 || num_channels == 2);
  RTC_DCHECK(sample_rate_hz == 16000 || sample_rate_hz == 48000);
  RTC_CHECK_EQ(
      WebRtcOpus_DecoderCreate(&dec_state_, channels_, sample_rate_hz_), 0);
  WebRtcOpus_DecoderInit(dec_state_);
  // TGCALLS PATCH: Opus DRED. RTP timestamps and DRED's 10 ms pieces are
  // 48 kHz here, so DRED stays off at other rates; and off without usable
  // weights (libopus is built without them).
  if (field_trials.IsEnabled("WebRTC-Audio-OpusDred") &&
      sample_rate_hz_ == 48000) {
    dred_enabled_ =
        dnn_weights_ &&
        WebRtcOpus_DecoderEnableDred(dec_state_, dnn_weights_->data(),
                                     dnn_weights_->size()) == 0;
    if (!dred_enabled_) {
      RTC_LOG(LS_WARNING) << "Opus DRED receive is on but "
                          << (dnn_weights_ ? "the weights are not usable"
                                           : "there are no weights")
                          << ": no DRED";
    }
  }
}

AudioDecoderOpusImpl::~AudioDecoderOpusImpl() {
  WebRtcOpus_DecoderFree(dec_state_);
}

std::vector<AudioDecoder::ParseResult> AudioDecoderOpusImpl::ParsePayload(
    Buffer&& payload,
    uint32_t timestamp) {
  std::vector<ParseResult> results;

  // TGCALLS PATCH: Opus DRED.
  if (dred_enabled_) {
    dred_log_packets_++;
    if (dred_log_packets_ == 50 || dred_log_packets_ % 500 == 0) {
      LogDredStats(payload);
    }
  }

  if (PacketHasFec(payload.data(), payload.size())) {
    const int duration =
        PacketDurationRedundant(payload.data(), payload.size());
    RTC_DCHECK_GE(duration, 0);
    Buffer payload_copy(payload.data(), payload.size());
    std::unique_ptr<EncodedAudioFrame> fec_frame(
        new OpusFrame(this, std::move(payload_copy), false));
    results.emplace_back(timestamp - duration, 1, std::move(fec_frame));
  }
  std::unique_ptr<EncodedAudioFrame> frame(
      new OpusFrame(this, std::move(payload), true));
  results.emplace_back(timestamp, 0, std::move(frame));
  return results;
}

namespace {

// TGCALLS PATCH: Opus DRED. One packet's parsed DRED, shared by the recovery
// frames built from it.
struct DredState {
  DredState() {
    int error = OPUS_OK;
    dred = opus_dred_alloc(&error);
  }
  ~DredState() {
    if (dred) {
      opus_dred_free(dred);
    }
  }
  DredState(const DredState&) = delete;
  DredState& operator=(const DredState&) = delete;
  OpusDRED* dred = nullptr;
};

// TGCALLS PATCH: Opus DRED. 10 ms of audio rebuilt from a later packet's DRED.
class OpusDredFrame : public AudioDecoder::EncodedAudioFrame {
 public:
  OpusDredFrame(AudioDecoderOpusImpl* decoder,
                std::shared_ptr<const DredState> state,
                int offset_samples)
      : decoder_(decoder),
        state_(std::move(state)),
        offset_samples_(offset_samples) {}

  size_t Duration() const override {
    return static_cast<size_t>(decoder_->SampleRateHz() / 100);
  }

  std::optional<DecodeResult> Decode(
      std::span<int16_t> decoded) const override {
    const int ret =
        decoder_->DecodeDredPiece(state_->dred, offset_samples_, decoded);
    if (ret < 0) {
      return std::nullopt;
    }
    return DecodeResult{.num_decoded_samples = static_cast<size_t>(ret),
                        .speech_type = AudioDecoder::kSpeech};
  }

 private:
  AudioDecoderOpusImpl* const decoder_;
  const std::shared_ptr<const DredState> state_;
  const int offset_samples_;
};

// DRED reaches at most 26 latents of 40 ms back.
constexpr int kMaxDredSamples48k = 49920;

}  // namespace

std::vector<AudioDecoder::ParseResult>
AudioDecoderOpusImpl::ParsePayloadWithGap(Buffer&& payload,
                                          uint32_t timestamp,
                                          uint32_t missing_samples) {
  std::vector<ParseResult> dred_results;
  const uint32_t piece = static_cast<uint32_t>(sample_rate_hz_ / 100);
  if (dred_enabled_ && missing_samples >= piece) {
    dred_log_gaps_++;
    dred_log_missing_samples_ += missing_samples;
    uint32_t fec = 0;
    if (PacketHasFec(payload.data(), payload.size())) {
      const int duration =
          PacketDurationRedundant(payload.data(), payload.size());
      fec = duration > 0 ? static_cast<uint32_t>(duration) : 0;
    }
    if (missing_samples >= fec + piece) {
      auto state = std::make_shared<DredState>();
      int dred_end = 0;
      const int reach =
          state->dred
              ? WebRtcOpus_DredParse(
                    dec_state_, state->dred, payload.data(), payload.size(),
                    kMaxDredSamples48k, &dred_end)
              : 0;
      if (reach > dred_end) {
        // The DRED covers offsets (dred_end, reach] before the packet: the
        // newest dred_end samples are silence libopus did not encode. Pieces
        // come from there only, and end where in-band FEC begins.
        uint32_t farthest = std::min<uint32_t>(missing_samples,
                                               static_cast<uint32_t>(reach));
        farthest -= farthest % piece;
        const uint32_t nearest =
            std::max<uint32_t>(fec, static_cast<uint32_t>(dred_end));
        for (uint32_t offset = farthest; offset >= nearest + piece;
             offset -= piece) {
          dred_results.emplace_back(
              timestamp - offset, kDredPriority,
              std::make_unique<OpusDredFrame>(this, state,
                                              static_cast<int>(offset)));
          dred_log_rebuilt_samples_ += piece;
        }
      } else {
        dred_log_gaps_without_dred_++;
      }
    }
  }
  std::vector<ParseResult> results =
      ParsePayload(std::move(payload), timestamp);
  for (auto& result : dred_results) {
    results.push_back(std::move(result));
  }
  return results;
}

int AudioDecoderOpusImpl::DecodeDredPiece(const OpusDRED* dred,
                                          int offset_samples,
                                          std::span<int16_t> decoded) {
  const int piece = sample_rate_hz_ / 100;
  if (decoded.size() < static_cast<size_t>(piece) * channels_) {
    return -1;
  }
  const int ret = WebRtcOpus_DredDecode(dec_state_, dred, offset_samples,
                                        decoded.data(), piece);
  if (ret <= 0) {
    return -1;
  }
  plc_samples_since_decode_ = 0;
  dred_log_decoded_samples_ += static_cast<uint64_t>(ret);
  return ret * static_cast<int>(channels_);
}

void AudioDecoderOpusImpl::LogDredStats(const Buffer& payload) {
  DredState state;
  int dred_end = 0;
  const int reach =
      state.dred ? WebRtcOpus_DredParse(dec_state_, state.dred, payload.data(),
                                        payload.size(), kMaxDredSamples48k,
                                        &dred_end)
                 : 0;
  const int per_ms = sample_rate_hz_ / 1000;
  RTC_LOG(LS_INFO) << "Opus DRED receive (decoder "
                   << (reinterpret_cast<uintptr_t>(this) & 0xffff)
                   << "): packet " << dred_log_packets_ << " carries "
                   << (reach > dred_end ? (reach - dred_end) / per_ms : 0)
                   << " ms of DRED; since the last line " << dred_log_gaps_
                   << " gaps (" << dred_log_gaps_without_dred_
                   << " without DRED), "
                   << dred_log_missing_samples_ / per_ms << " ms missing, "
                   << dred_log_rebuilt_samples_ / per_ms << " ms rebuilt, "
                   << dred_log_decoded_samples_ / per_ms << " ms decoded";
  dred_log_gaps_ = 0;
  dred_log_gaps_without_dred_ = 0;
  dred_log_missing_samples_ = 0;
  dred_log_rebuilt_samples_ = 0;
  dred_log_decoded_samples_ = 0;
}

int AudioDecoderOpusImpl::DecodeInternal(const uint8_t* encoded,
                                         size_t encoded_len,
                                         int sample_rate_hz,
                                         int16_t* decoded,
                                         SpeechType* speech_type) {
  RTC_DCHECK_EQ(sample_rate_hz, sample_rate_hz_);
  int16_t temp_type = 1;  // Default is speech.
  int ret =
      WebRtcOpus_Decode(dec_state_, encoded, encoded_len, decoded, &temp_type);
  if (ret > 0) {
    ret *= static_cast<int>(channels_);  // Return total number of samples.
    plc_samples_since_decode_ = 0;
  }
  *speech_type = ConvertSpeechType(temp_type);
  return ret;
}

int AudioDecoderOpusImpl::DecodeRedundantInternal(const uint8_t* encoded,
                                                  size_t encoded_len,
                                                  int sample_rate_hz,
                                                  int16_t* decoded,
                                                  SpeechType* speech_type) {
  if (!PacketHasFec(encoded, encoded_len)) {
    // This packet is a RED packet.
    return DecodeInternal(encoded, encoded_len, sample_rate_hz, decoded,
                          speech_type);
  }

  RTC_DCHECK_EQ(sample_rate_hz, sample_rate_hz_);
  int16_t temp_type = 1;  // Default is speech.
  int ret = WebRtcOpus_DecodeFec(dec_state_, encoded, encoded_len, decoded,
                                 &temp_type);
  if (ret > 0) {
    ret *= static_cast<int>(channels_);  // Return total number of samples.
    plc_samples_since_decode_ = 0;
  }
  *speech_type = ConvertSpeechType(temp_type);
  return ret;
}

void AudioDecoderOpusImpl::Reset() {
  WebRtcOpus_DecoderInit(dec_state_);
  plc_samples_since_decode_ = 0;
}

int AudioDecoderOpusImpl::PacketDuration(const uint8_t* encoded,
                                         size_t encoded_len) const {
  return WebRtcOpus_DurationEst(dec_state_, encoded, encoded_len);
}

int AudioDecoderOpusImpl::PacketDurationRedundant(const uint8_t* encoded,
                                                  size_t encoded_len) const {
  if (!PacketHasFec(encoded, encoded_len)) {
    // This packet is a RED packet.
    return PacketDuration(encoded, encoded_len);
  }

  return WebRtcOpus_FecDurationEst(encoded, encoded_len, sample_rate_hz_);
}

bool AudioDecoderOpusImpl::PacketHasFec(const uint8_t* encoded,
                                        size_t encoded_len) const {
  return WebRtcOpus_PacketHasFec(encoded, encoded_len) == 1;
}

int AudioDecoderOpusImpl::SampleRateHz() const {
  return sample_rate_hz_;
}

size_t AudioDecoderOpusImpl::Channels() const {
  return channels_;
}

void AudioDecoderOpusImpl::GeneratePlc(
    size_t /* requested_samples_per_channel */,
    BufferT<int16_t>* concealment_audio) {
  if (!generate_plc_) {
    return;
  }
  // TGCALLS PATCH: Opus DRED. Opus's neural concealment never stops on its
  // own and NetEq's codec path never mutes, so a speaker who went quiet would
  // cost every listener concealment for the rest of the call: after 1 s of one
  // gap, produce nothing and let NetEq's own expand take over and mute.
  if (plc_samples_since_decode_ >= static_cast<size_t>(sample_rate_hz_)) {
    return;
  }
  const size_t size_before = concealment_audio->size();
  int plc_size = WebRtcOpus_PlcDuration(dec_state_) * channels_;
  concealment_audio->AppendData(plc_size, [&](std::span<int16_t> decoded) {
    int16_t temp_type = 1;
    int ret =
        WebRtcOpus_Decode(dec_state_, nullptr, 0, decoded.data(), &temp_type);
    if (ret < 0) {
      return 0;
    }
    return ret * static_cast<int>(channels_);
  });
  plc_samples_since_decode_ +=
      (concealment_audio->size() - size_before) / channels_;
}

}  // namespace webrtc

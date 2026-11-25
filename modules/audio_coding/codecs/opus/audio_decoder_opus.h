/*
 *  Copyright (c) 2015 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#ifndef MODULES_AUDIO_CODING_CODECS_OPUS_AUDIO_DECODER_OPUS_H_
#define MODULES_AUDIO_CODING_CODECS_OPUS_AUDIO_DECODER_OPUS_H_

#include <stddef.h>
#include <stdint.h>

#include <memory>
#include <span>
#include <vector>

#include "api/audio_codecs/audio_decoder.h"
#include "api/field_trials_view.h"
#include "modules/audio_coding/codecs/opus/opus_interface.h"
#include "rtc_base/buffer.h"

namespace webrtc {

class AudioDecoderOpusImpl final : public AudioDecoder {
 public:
  // TGCALLS PATCH: Opus DRED. `dnn_weights`: AudioDecoderOpusConfig's.
  explicit AudioDecoderOpusImpl(
      const FieldTrialsView& field_trials,
      size_t num_channels,
      int sample_rate_hz,
      std::shared_ptr<const std::vector<uint8_t>> dnn_weights = nullptr);

  ~AudioDecoderOpusImpl() override;

  AudioDecoderOpusImpl(const AudioDecoderOpusImpl&) = delete;
  AudioDecoderOpusImpl& operator=(const AudioDecoderOpusImpl&) = delete;

  std::vector<ParseResult> ParsePayload(Buffer&& payload,
                                        uint32_t timestamp) override;
  // TGCALLS PATCH: Opus DRED. With WebRTC-Audio-OpusDred (48 kHz only), adds
  // a 10 ms frame (priority 2) per piece of the gap the packet's DRED reaches,
  // ending where its in-band FEC begins.
  std::vector<ParseResult> ParsePayloadWithGap(
      Buffer&& payload,
      uint32_t timestamp,
      uint32_t missing_samples) override;
  // TGCALLS PATCH: Opus DRED. Decodes one 10 ms piece of `dred`,
  // `offset_samples` before the packet that carried it. Returns the total
  // samples (all channels) written to `decoded`, or -1.
  int DecodeDredPiece(const OpusDRED* dred,
                      int offset_samples,
                      std::span<int16_t> decoded);
  void Reset() override;
  int PacketDuration(const uint8_t* encoded, size_t encoded_len) const override;
  int PacketDurationRedundant(const uint8_t* encoded,
                              size_t encoded_len) const override;
  bool PacketHasFec(const uint8_t* encoded, size_t encoded_len) const override;
  int SampleRateHz() const override;
  size_t Channels() const override;
  void GeneratePlc(size_t requested_samples_per_channel,
                   BufferT<int16_t>* concealment_audio) override;

 protected:
  int DecodeInternal(const uint8_t* encoded,
                     size_t encoded_len,
                     int sample_rate_hz,
                     int16_t* decoded,
                     SpeechType* speech_type) override;
  int DecodeRedundantInternal(const uint8_t* encoded,
                              size_t encoded_len,
                              int sample_rate_hz,
                              int16_t* decoded,
                              SpeechType* speech_type) override;

 private:
  OpusDecInst* dec_state_;
  const size_t channels_;
  const int sample_rate_hz_;
  const bool generate_plc_;
  // TGCALLS PATCH: Opus DRED. With the trial and well-formed weights, which
  // libopus reads in place for the decoder's lifetime.
  const std::shared_ptr<const std::vector<uint8_t>> dnn_weights_;
  bool dred_enabled_ = false;
  // Concealment samples (per channel) GeneratePlc produced since the last
  // decoded audio; it stops at 1 s so NetEq's own expand can mute.
  size_t plc_samples_since_decode_ = 0;
  // A log line on the 50th packet and every 500th (about 3 s in, then every
  // 30 s of 60 ms packets): the DRED that packet carries, and what DRED did
  // since the last line. Samples are per channel.
  void LogDredStats(const Buffer& payload);
  uint32_t dred_log_packets_ = 0;
  uint32_t dred_log_gaps_ = 0;
  uint32_t dred_log_gaps_without_dred_ = 0;
  uint64_t dred_log_missing_samples_ = 0;
  uint64_t dred_log_rebuilt_samples_ = 0;
  uint64_t dred_log_decoded_samples_ = 0;
};

}  // namespace webrtc

#endif  // MODULES_AUDIO_CODING_CODECS_OPUS_AUDIO_DECODER_OPUS_H_

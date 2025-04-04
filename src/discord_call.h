// AUTO-GENERATED
#ifndef DISCORD_CALL_H
#define DISCORD_CALL_H

#include "discord_enum.h"
#include "discord_vadthreshold_settings.h"
#include "discord_voice_state_handle.h"
#include "discordpp.h"
#include "godot_cpp/classes/ref_counted.hpp"

namespace godot {

class DiscordCall : public RefCounted {
	GDCLASS(DiscordCall, RefCounted)

private:
	discordpp::Call *call; // Doesn't have public empty contrusctor, needs to be a pointer.

	DiscordCall();

protected:
	static void _bind_methods();

public:
	discordpp::Call *unwrap(); // Internal usage.

	DiscordAudioModeType::Enum get_audio_mode();
	uint64_t get_channel_id();
	uint64_t get_guild_id();
	bool get_local_mute(uint64_t user_id);
	TypedArray<uint64_t> get_participants();
	float get_participant_volume(uint64_t user_id);
	bool get_pttactive();
	bool get_self_deaf();
	bool get_self_mute();
	DiscordCall::Status::Enum get_status();
	DiscordVADThresholdSettings *get_vadthreshold();
	Variant get_voice_state_handle(uint64_t user_id);
	void set_audio_mode(DiscordAudioModeType::Enum audio_mode);
	void set_local_mute(uint64_t user_id, bool mute);
	void set_on_voice_state_changed_callback(DiscordCall::OnVoiceStateChanged::Enum cb);
	void set_participant_changed_callback(DiscordCall::OnParticipantChanged::Enum cb);
	void set_participant_volume(uint64_t user_id, float volume);
	void set_pttactive(bool active);
	void set_pttrelease_delay(uint32_t release_delay_ms);
	void set_self_deaf(bool deaf);
	void set_self_mute(bool mute);
	void set_speaking_status_changed_callback(DiscordCall::OnSpeakingStatusChanged::Enum cb);
	void set_status_changed_callback(DiscordCall::OnStatusChanged::Enum cb);
	void set_vadthreshold(bool automatic, float threshold);

	DiscordCall(discordpp::Call *call);
	~DiscordCall();
};

} //namespace godot

#endif

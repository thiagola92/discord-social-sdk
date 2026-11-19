
#include "discord_classes.h"

using namespace godot;

// Functions.

DiscordGuildChannel *DiscordDiscordClientGuildVoiceSnapshot::channel() {
	auto r0 = obj->Channel();

	discordpp::GuildChannel *r1_t = memnew(discordpp::GuildChannel(std::move(r0)));
	DiscordGuildChannel *r1 = memnew(DiscordGuildChannel{ r1_t });

	return r1;
}

TypedArray<DiscordDiscordClientGuildVoiceMember> DiscordDiscordClientGuildVoiceSnapshot::members() {
	auto r0 = obj->Members();

	TypedArray<DiscordDiscordClientGuildVoiceMember> r1 = TypedArray<DiscordDiscordClientGuildVoiceMember>();

	for (auto i : r0) {
		discordpp::DiscordClientGuildVoiceMember *r1_t_t = memnew(discordpp::DiscordClientGuildVoiceMember(std::move(i)));
		DiscordDiscordClientGuildVoiceMember *r1_t = memnew(DiscordDiscordClientGuildVoiceMember{ r1_t_t });

		r1.push_back(r1_t);
	}

	return r1;
}

bool DiscordDiscordClientGuildVoiceSnapshot::selected() {
	auto r0 = obj->Selected();

	bool r1 = r0;

	return r1;
}

bool DiscordDiscordClientGuildVoiceSnapshot::speaking_available() {
	auto r0 = obj->SpeakingAvailable();

	bool r1 = r0;

	return r1;
}

void DiscordDiscordClientGuildVoiceSnapshot::set_channel(DiscordGuildChannel *channel) {
	discordpp::GuildChannel p0 = *channel->unwrap();
	obj->SetChannel(p0);
}

void DiscordDiscordClientGuildVoiceSnapshot::set_selected(bool selected) {
	bool p0 = selected;
	obj->SetSelected(p0);
}

void DiscordDiscordClientGuildVoiceSnapshot::set_speaking_available(bool speaking_available) {
	bool p0 = speaking_available;
	obj->SetSpeakingAvailable(p0);
}

// Overload functions.

// Binding.
void DiscordDiscordClientGuildVoiceSnapshot::_bind_methods() {
	ClassDB::bind_method(D_METHOD("channel"),
			&DiscordDiscordClientGuildVoiceSnapshot::channel);

	ClassDB::bind_method(D_METHOD("members"),
			&DiscordDiscordClientGuildVoiceSnapshot::members);

	ClassDB::bind_method(D_METHOD("selected"),
			&DiscordDiscordClientGuildVoiceSnapshot::selected);

	ClassDB::bind_method(D_METHOD("set_channel", "channel"),
			&DiscordDiscordClientGuildVoiceSnapshot::set_channel);

	ClassDB::bind_method(D_METHOD("set_selected", "selected"),
			&DiscordDiscordClientGuildVoiceSnapshot::set_selected);

	ClassDB::bind_method(D_METHOD("set_speaking_available", "speaking_available"),
			&DiscordDiscordClientGuildVoiceSnapshot::set_speaking_available);

	ClassDB::bind_method(D_METHOD("speaking_available"),
			&DiscordDiscordClientGuildVoiceSnapshot::speaking_available);
}

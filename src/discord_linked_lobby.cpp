
#include "discord_classes.h"

using namespace godot;

void DiscordppLinkedLobby::Drop() {
	obj->Drop();
}

uint64_t DiscordppLinkedLobby::ApplicationId() {
	return obj->ApplicationId();
}

void DiscordppLinkedLobby::SetApplicationId(uint64_t ApplicationId) {
	auto p0 = ApplicationId;
	obj->SetApplicationId(p0);
}

uint64_t DiscordppLinkedLobby::LobbyId() {
	return obj->LobbyId();
}

void DiscordppLinkedLobby::SetLobbyId(uint64_t LobbyId) {
	auto p0 = LobbyId;
	obj->SetLobbyId(p0);
}

void DiscordppLinkedLobby::_bind_methods() {
	ClassDB::bind_method(D_METHOD("Drop"),
			&DiscordppLinkedLobby::Drop);

	ClassDB::bind_method(D_METHOD("ApplicationId"),
			&DiscordppLinkedLobby::ApplicationId);

	ClassDB::bind_method(D_METHOD("SetApplicationId", "ApplicationId"),
			&DiscordppLinkedLobby::SetApplicationId);

	ClassDB::bind_method(D_METHOD("LobbyId"),
			&DiscordppLinkedLobby::LobbyId);

	ClassDB::bind_method(D_METHOD("SetLobbyId", "LobbyId"),
			&DiscordppLinkedLobby::SetLobbyId);
}

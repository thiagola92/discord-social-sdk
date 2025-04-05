#include "register_types.h"
#include "discord_authorization_args.h"
#include "discord_authorization_code_challenge.h"
#include "discord_authorization_code_verifier.h"
#include "discord_classes.h"
#include "discord_client.h"
#include "discord_client_result.h"
#include "discord_enum.h"
#include "gdextension_interface.h"
#include "godot_cpp/core/class_db.hpp"
#include "godot_cpp/core/defs.hpp"
#include "godot_cpp/godot.hpp"

using namespace godot;

void initialize_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}

	GDREGISTER_RUNTIME_CLASS(DiscordActivity);
	GDREGISTER_RUNTIME_CLASS(DiscordActivityAssets);
	GDREGISTER_RUNTIME_CLASS(DiscordActivityInvite);
	GDREGISTER_RUNTIME_CLASS(DiscordActivityParty);
	GDREGISTER_RUNTIME_CLASS(DiscordActivitySecrets);
	GDREGISTER_RUNTIME_CLASS(DiscordActivityTimestamps);
	GDREGISTER_RUNTIME_CLASS(DiscordAdditionalContent);
	GDREGISTER_RUNTIME_CLASS(DiscordAudioDevice);
	GDREGISTER_RUNTIME_CLASS(DiscordAuthorizationArgs);
	GDREGISTER_RUNTIME_CLASS(DiscordAuthorizationCodeChallenge);
	GDREGISTER_RUNTIME_CLASS(DiscordAuthorizationCodeVerifier);
	GDREGISTER_RUNTIME_CLASS(DiscordCall);
	GDREGISTER_RUNTIME_CLASS(DiscordCallInfoHandle);
	GDREGISTER_RUNTIME_CLASS(DiscordChannelHandle);
	GDREGISTER_RUNTIME_CLASS(DiscordClient);
	GDREGISTER_RUNTIME_CLASS(DiscordClientResult);
	GDREGISTER_RUNTIME_CLASS(DiscordDeviceAuthorizationArgs);
	GDREGISTER_RUNTIME_CLASS(DiscordGuildChannel);
	GDREGISTER_RUNTIME_CLASS(DiscordGuildMinimal);
	GDREGISTER_RUNTIME_CLASS(DiscordLinkedChannel);
	GDREGISTER_RUNTIME_CLASS(DiscordLinkedLobby);
	GDREGISTER_RUNTIME_CLASS(DiscordLobbyHandle);
	GDREGISTER_RUNTIME_CLASS(DiscordLobbyMemberHandle);
	GDREGISTER_RUNTIME_CLASS(DiscordMessageHandle);
	GDREGISTER_RUNTIME_CLASS(DiscordRelationshipHandle);
	GDREGISTER_RUNTIME_CLASS(DiscordUserHandle);
	GDREGISTER_RUNTIME_CLASS(DiscordVADThresholdSettings);
	GDREGISTER_RUNTIME_CLASS(DiscordVoiceStateHandle);

	// discord_enum.h
	GDREGISTER_ABSTRACT_CLASS(DiscordActivityActionTypes);
	GDREGISTER_ABSTRACT_CLASS(DiscordActivityPartyPrivacy);
	GDREGISTER_ABSTRACT_CLASS(DiscordActivityTypes);
	GDREGISTER_ABSTRACT_CLASS(DiscordActivityGamePlatforms);
	GDREGISTER_ABSTRACT_CLASS(DiscordErrorType);
	GDREGISTER_ABSTRACT_CLASS(DiscordHttpStatusCode);
	GDREGISTER_ABSTRACT_CLASS(DiscordAuthenticationCodeChallengeMethod);
	GDREGISTER_ABSTRACT_CLASS(DiscordAdditionalContentType);
	GDREGISTER_ABSTRACT_CLASS(DiscordCallError);
	GDREGISTER_ABSTRACT_CLASS(DiscordAudioModeType);
	GDREGISTER_ABSTRACT_CLASS(DiscordCallStatus);
	GDREGISTER_ABSTRACT_CLASS(DiscordChannelType);
	GDREGISTER_ABSTRACT_CLASS(DiscordRelationshipType);
	GDREGISTER_ABSTRACT_CLASS(DiscordUserHandleAvatarType);
	GDREGISTER_ABSTRACT_CLASS(DiscordStatusType);
	GDREGISTER_ABSTRACT_CLASS(DiscordDisclosureTypes);
	GDREGISTER_ABSTRACT_CLASS(DiscordClientError);
	GDREGISTER_ABSTRACT_CLASS(DiscordClientStatus);
	GDREGISTER_ABSTRACT_CLASS(DiscordClientThread);
	GDREGISTER_ABSTRACT_CLASS(DiscordAuthorizationTokenType);
	GDREGISTER_ABSTRACT_CLASS(DiscordAuthenticationExternalAuthType);
	GDREGISTER_ABSTRACT_CLASS(DiscordLoggingSeverity);
}

void uninitialize_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
}

extern "C" {
// Initialization.
GDExtensionBool GDE_EXPORT
initialize_extension(GDExtensionInterfaceGetProcAddress p_get_proc_address,
		const GDExtensionClassLibraryPtr p_library,
		GDExtensionInitialization *r_initialization) {
	godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library,
			r_initialization);

	init_obj.register_initializer(initialize_module);
	init_obj.register_terminator(uninitialize_module);
	init_obj.set_minimum_library_initialization_level(
			MODULE_INITIALIZATION_LEVEL_SCENE);

	return init_obj.init();
}
}
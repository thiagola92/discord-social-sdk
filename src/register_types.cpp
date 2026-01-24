
#include "register_types.h"
#include "discord_classes.h"
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

	// Abstracts
	GDREGISTER_ABSTRACT_CLASS(Discord);
	GDREGISTER_ABSTRACT_CLASS(DiscordActivityActionTypes);
	GDREGISTER_ABSTRACT_CLASS(DiscordActivityGamePlatforms);
	GDREGISTER_ABSTRACT_CLASS(DiscordActivityPartyPrivacy);
	GDREGISTER_ABSTRACT_CLASS(DiscordActivityTypes);
	GDREGISTER_ABSTRACT_CLASS(DiscordAdditionalContentType);
	GDREGISTER_ABSTRACT_CLASS(DiscordAudioModeType);
	GDREGISTER_ABSTRACT_CLASS(DiscordAudioSystem);
	GDREGISTER_ABSTRACT_CLASS(DiscordAuthenticationCodeChallengeMethod);
	GDREGISTER_ABSTRACT_CLASS(DiscordAuthenticationExternalAuthType);
	GDREGISTER_ABSTRACT_CLASS(DiscordAuthorizationTokenType);
	GDREGISTER_ABSTRACT_CLASS(DiscordCallError);
	GDREGISTER_ABSTRACT_CLASS(DiscordCallStatus);
	GDREGISTER_ABSTRACT_CLASS(DiscordChannelType);
	GDREGISTER_ABSTRACT_CLASS(DiscordClientError);
	GDREGISTER_ABSTRACT_CLASS(DiscordClientStatus);
	GDREGISTER_ABSTRACT_CLASS(DiscordClientThread);
	GDREGISTER_ABSTRACT_CLASS(DiscordDisclosureTypes);
	GDREGISTER_ABSTRACT_CLASS(DiscordErrorType);
	GDREGISTER_ABSTRACT_CLASS(DiscordExternalIdentityProviderType);
	GDREGISTER_ABSTRACT_CLASS(DiscordHttpStatusCode);
	GDREGISTER_ABSTRACT_CLASS(DiscordIntegrationType);
	GDREGISTER_ABSTRACT_CLASS(DiscordLoggingSeverity);
	GDREGISTER_ABSTRACT_CLASS(DiscordRelationshipGroupType);
	GDREGISTER_ABSTRACT_CLASS(DiscordRelationshipType);
	GDREGISTER_ABSTRACT_CLASS(DiscordStatusDisplayTypes);
	GDREGISTER_ABSTRACT_CLASS(DiscordStatusType);
	GDREGISTER_ABSTRACT_CLASS(DiscordUserHandleAvatarType);

	// Runtimes
	GDREGISTER_CLASS(DiscordActivity);
	GDREGISTER_CLASS(DiscordActivityAssets);
	GDREGISTER_CLASS(DiscordActivityButton);
	GDREGISTER_CLASS(DiscordActivityInvite);
	GDREGISTER_CLASS(DiscordActivityParty);
	GDREGISTER_CLASS(DiscordActivitySecrets);
	GDREGISTER_CLASS(DiscordActivityTimestamps);
	GDREGISTER_CLASS(DiscordAdditionalContent);
	GDREGISTER_CLASS(DiscordAudioDevice);
	GDREGISTER_CLASS(DiscordAuthorizationArgs);
	GDREGISTER_CLASS(DiscordAuthorizationCodeChallenge);
	GDREGISTER_CLASS(DiscordAuthorizationCodeVerifier);
	GDREGISTER_CLASS(DiscordCall);
	GDREGISTER_CLASS(DiscordCallInfoHandle);
	GDREGISTER_CLASS(DiscordChannelHandle);
	GDREGISTER_CLASS(DiscordClient);
	GDREGISTER_CLASS(DiscordClientCreateOptions);
	GDREGISTER_CLASS(DiscordClientResult);
	GDREGISTER_CLASS(DiscordDeviceAuthorizationArgs);
	GDREGISTER_CLASS(DiscordGuildChannel);
	GDREGISTER_CLASS(DiscordGuildMinimal);
	GDREGISTER_CLASS(DiscordLinkedChannel);
	GDREGISTER_CLASS(DiscordLinkedLobby);
	GDREGISTER_CLASS(DiscordLobbyHandle);
	GDREGISTER_CLASS(DiscordLobbyMemberHandle);
	GDREGISTER_CLASS(DiscordMessageHandle);
	GDREGISTER_CLASS(DiscordRelationshipHandle);
	GDREGISTER_CLASS(DiscordUserApplicationProfileHandle);
	GDREGISTER_CLASS(DiscordUserHandle);
	GDREGISTER_CLASS(DiscordUserMessageSummary);
	GDREGISTER_CLASS(DiscordVADThresholdSettings);
	GDREGISTER_CLASS(DiscordVoiceStateHandle);
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

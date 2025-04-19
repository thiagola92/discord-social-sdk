
#include "register_types.h"
#include "discordpp_classes.h"
#include "discordpp_enum.h"
#include "gdextension_interface.h"
#include "godot_cpp/core/class_db.hpp"
#include "godot_cpp/core/defs.hpp"
#include "godot_cpp/godot.hpp"

using namespace godot;

void initialize_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}

	// discordpp_enum.h
	GDREGISTER_ABSTRACT_CLASS(DiscordppActivityActionTypes);
	GDREGISTER_ABSTRACT_CLASS(DiscordppActivityPartyPrivacy);
	GDREGISTER_ABSTRACT_CLASS(DiscordppActivityTypes);
	GDREGISTER_ABSTRACT_CLASS(DiscordppActivityGamePlatforms);
	GDREGISTER_ABSTRACT_CLASS(DiscordppErrorType);
	GDREGISTER_ABSTRACT_CLASS(DiscordppHttpStatusCode);
	GDREGISTER_ABSTRACT_CLASS(DiscordppAuthenticationCodeChallengeMethod);
	GDREGISTER_ABSTRACT_CLASS(DiscordppAdditionalContentType);
	GDREGISTER_ABSTRACT_CLASS(DiscordppAudioModeType);
	GDREGISTER_ABSTRACT_CLASS(DiscordppChannelType);
	GDREGISTER_ABSTRACT_CLASS(DiscordppRelationshipType);
	GDREGISTER_ABSTRACT_CLASS(DiscordppStatusType);
	GDREGISTER_ABSTRACT_CLASS(DiscordppDisclosureTypes);
	GDREGISTER_ABSTRACT_CLASS(DiscordppAuthorizationTokenType);
	GDREGISTER_ABSTRACT_CLASS(DiscordppAuthenticationExternalAuthType);
	GDREGISTER_ABSTRACT_CLASS(DiscordppLoggingSeverity);
	GDREGISTER_ABSTRACT_CLASS(DiscordppCallError);
	GDREGISTER_ABSTRACT_CLASS(DiscordppCallStatus);
	GDREGISTER_ABSTRACT_CLASS(DiscordppUserHandleAvatarType);
	GDREGISTER_ABSTRACT_CLASS(DiscordppClientError);
	GDREGISTER_ABSTRACT_CLASS(DiscordppClientStatus);
	GDREGISTER_ABSTRACT_CLASS(DiscordppClientThread);
	GDREGISTER_ABSTRACT_CLASS(Discordpp);

	// discordpp_classes.h
	GDREGISTER_RUNTIME_CLASS(DiscordppActivityInvite);
	GDREGISTER_RUNTIME_CLASS(DiscordppActivityAssets);
	GDREGISTER_RUNTIME_CLASS(DiscordppActivityTimestamps);
	GDREGISTER_RUNTIME_CLASS(DiscordppActivityParty);
	GDREGISTER_RUNTIME_CLASS(DiscordppActivitySecrets);
	GDREGISTER_RUNTIME_CLASS(DiscordppActivity);
	GDREGISTER_RUNTIME_CLASS(DiscordppClientResult);
	GDREGISTER_RUNTIME_CLASS(DiscordppAuthorizationCodeChallenge);
	GDREGISTER_RUNTIME_CLASS(DiscordppAuthorizationCodeVerifier);
	GDREGISTER_RUNTIME_CLASS(DiscordppAuthorizationArgs);
	GDREGISTER_RUNTIME_CLASS(DiscordppDeviceAuthorizationArgs);
	GDREGISTER_RUNTIME_CLASS(DiscordppVoiceStateHandle);
	GDREGISTER_RUNTIME_CLASS(DiscordppVADThresholdSettings);
	GDREGISTER_RUNTIME_CLASS(DiscordppCall);
	GDREGISTER_RUNTIME_CLASS(DiscordppChannelHandle);
	GDREGISTER_RUNTIME_CLASS(DiscordppGuildMinimal);
	GDREGISTER_RUNTIME_CLASS(DiscordppGuildChannel);
	GDREGISTER_RUNTIME_CLASS(DiscordppLinkedLobby);
	GDREGISTER_RUNTIME_CLASS(DiscordppLinkedChannel);
	GDREGISTER_RUNTIME_CLASS(DiscordppRelationshipHandle);
	GDREGISTER_RUNTIME_CLASS(DiscordppUserHandle);
	GDREGISTER_RUNTIME_CLASS(DiscordppLobbyMemberHandle);
	GDREGISTER_RUNTIME_CLASS(DiscordppLobbyHandle);
	GDREGISTER_RUNTIME_CLASS(DiscordppAdditionalContent);
	GDREGISTER_RUNTIME_CLASS(DiscordppMessageHandle);
	GDREGISTER_RUNTIME_CLASS(DiscordppAudioDevice);
	GDREGISTER_RUNTIME_CLASS(DiscordppClient);
	GDREGISTER_RUNTIME_CLASS(DiscordppCallInfoHandle);
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

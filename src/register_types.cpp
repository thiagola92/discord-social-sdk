
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
	GDREGISTER_ABSTRACT_CLASS(DiscordppStatusDisplayTypes);
	GDREGISTER_ABSTRACT_CLASS(DiscordppActivityGamePlatforms);
	GDREGISTER_ABSTRACT_CLASS(DiscordppErrorType);
	GDREGISTER_ABSTRACT_CLASS(DiscordppHttpStatusCode);
	GDREGISTER_ABSTRACT_CLASS(DiscordppAuthenticationCodeChallengeMethod);
	GDREGISTER_ABSTRACT_CLASS(DiscordppIntegrationType);
	GDREGISTER_ABSTRACT_CLASS(DiscordppChannelType);
	GDREGISTER_ABSTRACT_CLASS(DiscordppAdditionalContentType);
	GDREGISTER_ABSTRACT_CLASS(DiscordppAudioSystem);
	GDREGISTER_ABSTRACT_CLASS(DiscordppAudioModeType);
	GDREGISTER_ABSTRACT_CLASS(DiscordppRelationshipType);
	GDREGISTER_ABSTRACT_CLASS(DiscordppExternalIdentityProviderType);
	GDREGISTER_ABSTRACT_CLASS(DiscordppStatusType);
	GDREGISTER_ABSTRACT_CLASS(DiscordppDisclosureTypes);
	GDREGISTER_ABSTRACT_CLASS(DiscordppAuthorizationTokenType);
	GDREGISTER_ABSTRACT_CLASS(DiscordppAuthenticationExternalAuthType);
	GDREGISTER_ABSTRACT_CLASS(DiscordppLoggingSeverity);
	GDREGISTER_ABSTRACT_CLASS(DiscordppRelationshipGroupType);
	GDREGISTER_ABSTRACT_CLASS(DiscordppCallError);
	GDREGISTER_ABSTRACT_CLASS(DiscordppCallStatus);
	GDREGISTER_ABSTRACT_CLASS(DiscordppUserHandleAvatarType);
	GDREGISTER_ABSTRACT_CLASS(DiscordppClientError);
	GDREGISTER_ABSTRACT_CLASS(DiscordppClientStatus);
	GDREGISTER_ABSTRACT_CLASS(DiscordppClientThread);
	GDREGISTER_ABSTRACT_CLASS(Discordpp);

	// discordpp_classes.h
	GDREGISTER_CLASS(DiscordppActivityInvite);
	GDREGISTER_CLASS(DiscordppActivityAssets);
	GDREGISTER_CLASS(DiscordppActivityTimestamps);
	GDREGISTER_CLASS(DiscordppActivityParty);
	GDREGISTER_CLASS(DiscordppActivitySecrets);
	GDREGISTER_CLASS(DiscordppActivityButton);
	GDREGISTER_CLASS(DiscordppActivity);
	GDREGISTER_CLASS(DiscordppClientResult);
	GDREGISTER_CLASS(DiscordppAuthorizationCodeChallenge);
	GDREGISTER_CLASS(DiscordppAuthorizationCodeVerifier);
	GDREGISTER_CLASS(DiscordppAuthorizationArgs);
	GDREGISTER_CLASS(DiscordppDeviceAuthorizationArgs);
	GDREGISTER_CLASS(DiscordppVoiceStateHandle);
	GDREGISTER_CLASS(DiscordppVADThresholdSettings);
	GDREGISTER_CLASS(DiscordppCall);
	GDREGISTER_CLASS(DiscordppChannelHandle);
	GDREGISTER_CLASS(DiscordppGuildMinimal);
	GDREGISTER_CLASS(DiscordppGuildChannel);
	GDREGISTER_CLASS(DiscordppLinkedLobby);
	GDREGISTER_CLASS(DiscordppLinkedChannel);
	GDREGISTER_CLASS(DiscordppRelationshipHandle);
	GDREGISTER_CLASS(DiscordppUserApplicationProfileHandle);
	GDREGISTER_CLASS(DiscordppUserHandle);
	GDREGISTER_CLASS(DiscordppLobbyMemberHandle);
	GDREGISTER_CLASS(DiscordppLobbyHandle);
	GDREGISTER_CLASS(DiscordppAdditionalContent);
	GDREGISTER_CLASS(DiscordppMessageHandle);
	GDREGISTER_CLASS(DiscordppAudioDevice);
	GDREGISTER_CLASS(DiscordppUserMessageSummary);
	GDREGISTER_CLASS(DiscordppClientCreateOptions);
	GDREGISTER_CLASS(DiscordppClient);
	GDREGISTER_CLASS(DiscordppCallInfoHandle);
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

#include "register_types.h"
#include "discord_authorization_code_challenge.h"
#include "discord_client.h"
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

	GDREGISTER_RUNTIME_CLASS(DiscordAuthorizationArgs);
	GDREGISTER_RUNTIME_CLASS(DiscordAuthorizationCodeChallenge);
	GDREGISTER_RUNTIME_CLASS(DiscordClient);

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
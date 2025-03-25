# Generates the minimum file for every Class from SDK.
from pathlib import Path
from class_generator import generate_class

discordpp = Path("include/discordpp.h").read_text()
files = [path.name for path in Path("src/").iterdir() if path.is_file()]
classes = {
    # "Activity",
    # "ActivityAssets",
    # "ActivityInvite",
    # "ActivityParty",
    # "ActivitySecrets",
    # "ActivityTimestamps",
    # "AdditionalContent",
    # "AudioDevice",
    # "AuthorizationArgs",
    # "AuthorizationCodeChallenge",
    # "AuthorizationCodeVerifier",
    # "Call",
    # "CallInfoHandle",
    # "ChannelHandle",
    # "Client",
    "ClientResult",
    # "DeviceAuthorizationArgs",
    # "GuildChannel",
    # "GuildMinimal",
    # "LinkedChannel",
    # "LinkedLobby",
    # "LobbyHandle",
    # "LobbyMemberHandle",
    # "MessageHandle",
    # "RelationshipHandle",
    # "UserHandle",
    # "VADThresholdSettings",
    # "VoiceStateHandle",
}

if __name__ == "__main__":
    classes = list(classes)
    classes.sort()

    classes_registrations = ""
    classes_includes = ""

    for class_name in classes:
        class_registration, class_include = generate_class(class_name)

        # Increase strings to print later.
        classes_registrations += class_registration
        classes_includes += class_include

    print(f"##### CLASSES_INCLUDES #####\n\n{classes_includes}")
    print(f"##### CLASSES_REGISTRATIONS #####\n\n{classes_registrations}")

# Generates the minimum for every Class from SDK.
from pathlib import Path
from template_h import header_template, header_template2
from template_cpp import source_template, source_template2

discordpp = Path("include/discordpp.h").read_text()
directory = Path("src/")
files = [path.name for path in directory.iterdir() if path.is_file()]
classes = {
    "Activity",
    "ActivityAssets",
    "ActivityInvite",
    "ActivityParty",
    "ActivitySecrets",
    "ActivityTimestamps",
    "AdditionalContent",
    "AudioDevice",
    "AuthorizationArgs",
    "AuthorizationCodeChallenge",
    "AuthorizationCodeVerifier",
    "Call",
    "CallInfoHandle",
    "ChannelHandle",
    "Client",
    "ClientResult",
    "DeviceAuthorizationArgs",
    "GuildChannel",
    "GuildMinimal",
    "LinkedChannel",
    "LinkedLobby",
    "LobbyHandle",
    "LobbyMemberHandle",
    "MessageHandle",
    "RelationshipHandle",
    "UserHandle",
    "VADThresholdSettings",
    "VoiceStateHandle",
}

def to_snake_case(string: str) -> str:
    new_string = ""
    can_add_underscore = False

    for c in string:
        if c.islower():
            new_string += c
            can_add_underscore = True
        elif c.isupper():
            if can_add_underscore:
                new_string += "_"
                can_add_underscore = False
            new_string += c.lower()

    return new_string

if __name__ == "__main__":
    classes = list(classes)
    classes.sort()

    classes_registrations = ""
    classes_includes = ""

    for class_name in classes:
        filename = to_snake_case("Discord" + class_name)
        filename_cpp = filename + ".cpp"
        filename_h = filename + ".h"
        property_name = to_snake_case(class_name)
        header_definition = property_name.upper()
        empty_constructor = f"explicit {class_name}();" in discordpp

        if empty_constructor:
            header_content = header_template.format(
                header_definition=header_definition,
                class_name=class_name,
                property_name=property_name,
            )

            source_content = source_template.format(
                filename_h=filename_h,
                class_name=class_name,
                property_name=property_name,
            )
        else:
            header_content = header_template2.format(
                header_definition=header_definition,
                class_name=class_name,
                property_name=property_name,
            )

            source_content = source_template2.format(
                filename_h=filename_h,
                class_name=class_name,
                property_name=property_name,
            )
        
        # Generate template header (don't overwrite).
        file = Path(f"src/{filename_h}")

        if not file.exists():
            file.write_text(header_content)
        
        # Generate template source code (don't overwrite).
        file = Path(f"src/{filename_cpp}")

        if not file.exists():
            file.write_text(source_content)
        
        # Increase strings to print later.
        classes_registrations += f" GDREGISTER_RUNTIME_CLASS(Discord{class_name});\n"
        classes_includes += f"#include \"{filename_h}\"\n"
    
    print(f"##### CLASSES_INCLUDES #####\n\n{classes_includes}")
    print(f"##### CLASSES_REGISTRATIONS #####\n\n{classes_registrations}")
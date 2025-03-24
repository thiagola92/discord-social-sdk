# Generates the minimum for every Class from SDK.
from pathlib import Path

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

header_template = """#ifndef DISCORD_{header_definition}_H
#define DISCORD_{header_definition}_H

#include "discordpp.h"
#include "godot_cpp/classes/ref_counted.hpp"

namespace godot {{

class Discord{class_name} : public RefCounted {{
	GDCLASS(Discord{class_name}, RefCounted)

private:
	discordpp::{class_name} {property_name};

protected:
	static void _bind_methods();

public:
	discordpp::{class_name} *unwrap(); // Internal usage.

	Discord{class_name}();
	~Discord{class_name}();
}};

}} //namespace godot

#endif
"""

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
        header_content = header_template.format(
            class_name=class_name,
            property_name=property_name,
            header_definition=header_definition
        )
        
        # Generate template headers if file doesn't exist.
        if filename_h not in files:
            file = Path(f"src/{filename_h}")

            if file.exists():
                break

            Path(f"src/{filename_h}").write_text(header_content)
        
        classes_registrations += f" GDREGISTER_RUNTIME_CLASS(Discord{class_name});\n"
        classes_includes += f"#include \"{filename_h}\"\n"
    
    print(f"##### CLASSES_INCLUDES #####\n\n{classes_includes}")
    print(f"##### CLASSES_REGISTRATIONS #####\n\n{classes_registrations}")
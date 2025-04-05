from generator import generate_class, clear_classes
from extractor import get_classes
from template_file import header_
from pathlib import Path


if __name__ == "__main__":
    clear_classes()

    classes = list(get_classes().keys())
    classes.sort()

    classes_registrations = ""
    classes_declarations = ""
    classes_definitions = ""

    for class_name in classes:
        # Skipping for now
        if class_name in [
            "AuthorizationArgs",
            "AuthorizationCodeChallenge",
            "AuthorizationCodeVerifier",
            "ClientResult",
            "Client",
        ]:
            continue

        class_methods = get_classes()[class_name]
        class_registration, classes_definition = generate_class(
            class_name, class_methods
        )

        # Increase strings to print later.
        classes_registrations += class_registration
        classes_declarations += f"class Discord{class_name};\n"
        classes_definitions += classes_definition

    classes_header = Path("src/discord_classes.h")
    classes_header.write_text(header_(classes_declarations, classes_definitions))

    print(f"########## CLASSES_REGISTRATIONS ##########\n\n{classes_registrations}")

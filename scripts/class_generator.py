from pathlib import Path
from helper import to_snake_case
from template_h import header_template, header_template2
from template_cpp import source_template, source_template2

DISCORDPP = Path("include/discordpp.h").read_text()


def generate_class(class_name: str) -> tuple[str, str]:
    """Generates the minimum file for a Class from SDK."""

    filename = to_snake_case("Discord" + class_name)
    filename_cpp = filename + ".cpp"
    filename_h = filename + ".h"
    property_name = to_snake_case(class_name)
    header_definition = property_name.upper()
    is_property_pointer = f"explicit {class_name}();" in DISCORDPP

    if not is_property_pointer:
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

    return (
        f"GDREGISTER_RUNTIME_CLASS(Discord{class_name});\n",
        f'#include "{filename_h}"\n',
    )

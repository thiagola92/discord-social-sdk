from pathlib import Path
from helper import to_snake_case, clang_format
from parser import parse_signature
from template_file import header_, source_, AUTO_GENERATED_COMMENT
from builder import (
    build_method,
    build_bind,
    build_signals,
    build_includes,
    build_signature,
)

DISCORDPP = Path("include/discordpp.h").read_text()

assert len(DISCORDPP) > 0


def generate_class(class_name: str, class_methods: list[str]) -> tuple[str, str]:
    """
    Generates the minimum file for a Class from SDK.

    Returns a tuple with informations to be inserted in "register_types.cpp":
    - The #include to be added
    - Macro to add class into Godot
    """

    filename = to_snake_case("Discord" + class_name)
    filename_cpp = filename + ".cpp"
    filename_h = filename + ".h"
    property_name = to_snake_case(class_name)
    header_definition = property_name.upper()
    has_empty_constructor = f"explicit {class_name}();" in DISCORDPP

    methods = []
    signals = []
    binds = []
    signatures = []
    includes = set()
    has_callbacks = False

    for m in class_methods:
        method = parse_signature(m)

        signals.append(build_signals(method=method, class_name=class_name))
        binds.append(build_bind(method=method, class_name=class_name))
        signatures.append(build_signature(method=method))
        has_callbacks = method.has_callbacks or has_callbacks

        for i in build_includes(method=method):
            includes.add(i)

        methods.append(
            build_method(
                method=method,
                class_name=class_name,
                property_name=property_name,
                has_empty_constructor=has_empty_constructor,
            )
        )

    binds = "".join(binds)
    signals = "".join(signals)
    signatures = "\n".join(signatures)
    methods = "".join(methods)
    includes = "\n".join(includes)

    source_file = Path(f"src/{filename_cpp}")
    source_content = source_(
        filename_h=filename_h,
        class_name=class_name,
        property_name=property_name,
        methods=methods,
        signals=signals,
        binds=binds,
        has_empty_constructor=has_empty_constructor,
    )

    header_file = Path(f"src/{filename_h}")
    header_content = header_(
        header_definition=header_definition,
        includes="".join(includes),
        class_name=class_name,
        property_name=property_name,
        signatures=signatures,
        has_empty_constructor=has_empty_constructor,
        has_callbacks=has_callbacks,
    )

    print(f"========== {source_file.name} ==========")
    print(f"\n{source_content}\n")

    print(f"========== {header_file.name} ==========")
    print(f"\n{header_content}\n")

    # Generate template source code (don't overwrite).
    if not source_file.exists() or AUTO_GENERATED_COMMENT in source_file.read_text():
        source_file.write_text(source_content)
        clang_format(source_file.absolute())

    # Generate template header (don't overwrite).
    if not header_file.exists() or AUTO_GENERATED_COMMENT in source_file.read_text():
        header_file.write_text(header_content)
        clang_format(header_file.absolute())

    return (
        f'#include "{filename_h}"\n',
        f"GDREGISTER_RUNTIME_CLASS(Discord{class_name});\n",
    )

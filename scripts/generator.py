from pathlib import Path
from helper import to_snake_case, clang_format
from parser import parse_signature
from template_file import source_, class_definition_, AUTO_GENERATED_COMMENT
from builder import (
    build_method,
    build_bind,
    build_signals,
    build_signature,
)

DISCORDPP = Path("include/discordpp.h").read_text()

assert len(DISCORDPP) > 0


def clear_classes() -> None:
    files = Path("src/").iterdir()
    files = list(files)
    files = [f for f in files if f.is_file()]
    files = [f for f in files if f.name.endswith(".cpp") or f.name.endswith(".h")]
    files = [f for f in files if f.read_text().startswith(AUTO_GENERATED_COMMENT)]
    files.sort()

    for f in files:
        f.unlink()


def generate_class(class_name: str, class_methods: list[str]) -> tuple[str, str]:
    """
    Generates the minimum file for a Class from SDK.

    Returns a tuple with informations to be inserted in "register_types.cpp":
    - The #include to be added
    - Macro to add class into Godot
    """

    filename = to_snake_case("Discord" + class_name)
    filename_cpp = filename + ".cpp"
    property_name = to_snake_case(class_name)
    has_empty_constructor = f"explicit {class_name}();" in DISCORDPP

    methods = []
    signals = []
    binds = []
    signatures = []
    has_callbacks = False

    for m in class_methods:
        method = parse_signature(m)

        signals.append(build_signals(method=method, class_name=class_name))
        binds.append(build_bind(method=method, class_name=class_name))
        signatures.append(build_signature(method=method))
        has_callbacks = method.has_callbacks or has_callbacks

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

    source_file = Path(f"src/{filename_cpp}")
    source_content = source_(
        class_name=class_name,
        property_name=property_name,
        methods=methods,
        signals=signals,
        binds=binds,
        has_empty_constructor=has_empty_constructor,
    )

    class_definition = class_definition_(
        class_name=class_name,
        property_name=property_name,
        signatures=signatures,
        has_empty_constructor=has_empty_constructor,
        has_callbacks=has_callbacks,
    )

    print(f"========== {source_file.name} ==========")
    print(f"\n{source_content}\n")

    # Generate template source code (don't overwrite).
    if not source_file.exists() or AUTO_GENERATED_COMMENT in source_file.read_text():
        source_file.write_text(source_content)
        clang_format(source_file.absolute())

    return (
        f"GDREGISTER_RUNTIME_CLASS(Discord{class_name});\n",
        class_definition,
    )

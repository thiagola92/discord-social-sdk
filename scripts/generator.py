from pathlib import Path
from helper import to_snake_case
from parser import parse_signature
from template_cpp import get_source_template
from template_h import get_header_template
from template_bind import get_bind_template
from template_get import get_get_template
from template_set import get_set_template

DISCORDPP = Path("include/discordpp.h").read_text()

assert len(DISCORDPP) > 0


def generate_class(class_name: str, class_methods: list[str]) -> tuple[str, str]:
    """
    Generates the minimum file for a Class from SDK.

    Returns a tuple with information to be inserted in register_types.cpp,
    first value is the include to be added and second value is macro to add to Godot.
    """

    filename = to_snake_case("Discord" + class_name)
    filename_cpp = filename + ".cpp"
    filename_h = filename + ".h"
    property_name = to_snake_case(class_name)
    header_definition = property_name.upper()
    is_property_pointer = f"explicit {class_name}();" not in DISCORDPP

    methods = ""
    binds = ""
    signatures = ""

    for m in class_methods:
        method, bind = generate_method(
            m,
            class_name,
            property_name,
            is_property_pointer,
        )

        signature = generate_signature(method, class_name)

        methods += method
        binds += bind
        signatures += signature

    # print(methods)
    # print(binds)
    # print(signatures)

    source_file = Path(f"src/{filename_cpp}")
    source_content = get_source_template(is_property_pointer).format(
        filename_h=filename_h,
        class_name=class_name,
        property_name=property_name,
        methods=methods,
        binds=binds,
    )

    header_file = Path(f"src/{filename_h}")
    header_content = get_header_template(is_property_pointer).format(
        header_definition=header_definition,
        class_name=class_name,
        property_name=property_name,
        signatures=signatures,
    )

    # Generate template source code (don't overwrite).
    if not source_file.exists():
        source_file.write_text(source_content)

    # Generate template header (don't overwrite).
    if not header_file.exists():
        header_file.write_text(header_content)

    return (
        f'#include "{filename_h}"\n',
        f"GDREGISTER_RUNTIME_CLASS(Discord{class_name});\n",
    )


def generate_method(
    signature: str, class_name: str, property_name: str, is_property_pointer: bool
) -> tuple[str, str]:
    """
    Generates the minium Get/Set method for this signature.

    Returns a tuple with information to be inserted in the cpp file,
    first value is the method code and second value code to be inserted in _bind_methods()."
    """
    method = parse_signature(signature)
    operator = "->" if is_property_pointer else "."

    if method.is_setter:
        return (
            get_set_template(method).format(
                class_name=class_name,
                method_snake_name="set_" + to_snake_case(method.name),
                parameter_type=method.params[0].type.name,
                parameter_name=to_snake_case(method.params[0].name),
                property_name=property_name,
                operator=operator,
                method_name="Set" + method.name,
            ),
            get_bind_template(method).format(
                method_snake_name="set_" + to_snake_case(method.name),
                parameter_name=to_snake_case(method.params[0].name),
                class_name=class_name,
            ),
        )

    return (
        get_get_template(method).format(
            return_type=method.ret.name,
            class_name=class_name,
            method_snake_name="get_" + to_snake_case(method.name),
            property_name=property_name,
            operator=operator,
            method_name=method.name,
        ),
        get_bind_template(method).format(
            method_snake_name="get_" + to_snake_case(method.name),
            class_name=class_name,
        ),
    )


def generate_signature(method_content: str, class_name: str) -> str:
    signature, _, _ = method_content.partition("{")
    signature = signature.replace(f"Discord{class_name}::", "")
    signature = signature.strip()
    signature += ";\n"
    signature = "\t" + signature

    return signature

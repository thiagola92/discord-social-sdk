# Generates a GET method based on method signature.
from template_get import (
    get_enum_template,
    get_uint64_template,
    get_int32_template,
    get_string_template,
)
from helper import to_snake_case


class FunctionDetails:
    class_name: str = ""
    property_name: str = ""

    # Extracted from signature.
    return_type: str = ""
    method_name: str = ""
    parameters: str = ""

    # Deduced
    method_snake_name: str = ""
    is_setter: bool = False
    is_ret_enum: bool = False


def extract_function_info(
    text: str,
    class_name: str,
    property_name: str,
    classes: list[str],
) -> FunctionDetails:
    func = FunctionDetails()

    func.class_name = class_name
    func.property_name = property_name

    func.return_type, _, text = text.partition("\t")
    func.return_type = func.return_type.strip()

    func.method_name, _, text = text.partition(" ")
    func.method_name = func.method_name.strip()

    func.parameters, _, text = text.partition(")")
    func.parameters = (func.parameters + ")").strip()

    func.method_snake_name = to_snake_case(func.method_name)

    func.is_setter = (
        func.method_name.startswith("Set") and func.method_name[3].isupper()
    )

    func.is_ret_enum = (
        func.return_type.startswith("discordpp::") and func.return_type not in classes
    )

    if func.return_type.startswith("discordpp::"):
        func.return_type = func.return_type.removeprefix("discordpp::")

    return func


def generate_get(func: FunctionDetails, is_property_pointer: bool) -> str:
    function: str = ""
    operator = "->" if is_property_pointer else "."

    match func.return_type:
        case "int32_t":
            function = get_int32_template.format(
                class_name=func.class_name,
                method_snake_name=func.method_snake_name,
                method_name=func.method_name,
                property_name=func.property_name,
                operator=operator,
            )
        case "uint64_t":
            function = get_uint64_template.format(
                class_name=func.class_name,
                method_snake_name=func.method_snake_name,
                method_name=func.method_name,
                property_name=func.property_name,
                operator=operator,
            )
        case "std::string":
            function = get_string_template.format(
                class_name=func.class_name,
                method_snake_name=func.method_snake_name,
                method_name=func.method_name,
                property_name=func.property_name,
                operator=operator,
            )
        case _:
            if func.is_ret_enum:
                function = get_enum_template.format(
                    return_type=func.return_type,
                    class_name=func.class_name,
                    method_snake_name=func.method_snake_name,
                    method_name=func.method_name,
                    property_name=func.property_name,
                    operator=operator,
                )

    return function


text = "std::string 	Error () const"
i = extract_function_info(text, "ClientResult", "client_result", [])
print(generate_get(i, True))

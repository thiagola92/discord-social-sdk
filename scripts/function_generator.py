# Generates a GET method based on method signature.
from helper import to_snake_case
from template_get import (
    get_enum_template,
    get_int32_template,
    get_uint64_template,
    get_string_template,
    get_optional_int32_template,
    get_optional_uint64_template,
    get_optional_string_template,
    get_optional_enum_template,
)
from template_set import (
    set_enum_template,
    set_int32_template,
    set_uint64_template,
    set_string_template,
    set_optional_int32_template,
    set_optional_uint64_template,
    set_optional_string_template,
    set_optional_enum_template,
)


class FunctionDetails:
    class_name: str = ""
    property_name: str = ""

    # Extracted from signature.
    return_type: str = ""
    method_name: str = ""
    parameters: str = ""
    parameter_type: str = ""
    parameter_name: str = ""

    # Deduced
    method_snake_name: str = ""
    is_setter: bool = False
    is_ret_opt: bool = False
    is_ret_enum: bool = False
    is_param_opt: bool = False
    is_param_enum: bool = False


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
    func.parameters = func.parameters.strip()
    func.parameters = func.parameters.removeprefix("(")
    func.parameters = func.parameters.strip()

    func.method_snake_name = to_snake_case(func.method_name)

    func.is_setter = (
        func.method_name.startswith("Set") and func.method_name[3].isupper()
    )

    if func.is_setter:
        func.parameter_name = func.method_name.removeprefix("Set")
        func.parameter_name = to_snake_case(func.parameter_name)

    func.is_ret_opt = func.return_type.startswith("std::optional<")

    if func.is_ret_opt:
        func.return_type = func.return_type.removeprefix("std::optional<")
        func.return_type = func.return_type.removesuffix(">")
        func.return_type = func.return_type.strip()

    func.is_ret_enum = (
        func.return_type.startswith("discordpp::") and func.return_type not in classes
    )

    if func.is_ret_enum:
        func.return_type = func.return_type.removeprefix("discordpp::")

    if func.is_setter:
        func.is_param_opt = func.parameters.startswith("std::optional<")

        if func.is_param_opt:
            func.parameter_type = func.parameters.removeprefix("std::optional<")
            func.parameter_type, _, _ = func.parameter_type.partition(">")
            func.parameter_type = func.parameter_type.strip()
        else:
            func.parameter_type = func.parameters.partition(func.parameter_name)
            func.parameter_type = func.parameter_type.strip()

    return func


def generate_get(func: FunctionDetails, is_property_pointer: bool) -> str:
    function: str = ""
    operator = "->" if is_property_pointer else "."

    match func.return_type:
        case "int32_t":
            if not func.is_ret_opt:
                function = get_int32_template.format(
                    class_name=func.class_name,
                    method_snake_name=func.method_snake_name,
                    method_name=func.method_name,
                    property_name=func.property_name,
                    operator=operator,
                )
            else:
                function = get_optional_int32_template.format(
                    class_name=func.class_name,
                    method_snake_name=func.method_snake_name,
                    method_name=func.method_name,
                    property_name=func.property_name,
                    operator=operator,
                )
        case "uint64_t":
            if not func.is_ret_opt:
                function = get_uint64_template.format(
                    class_name=func.class_name,
                    method_snake_name=func.method_snake_name,
                    method_name=func.method_name,
                    property_name=func.property_name,
                    operator=operator,
                )
            else:
                function = get_optional_uint64_template.format(
                    class_name=func.class_name,
                    method_snake_name=func.method_snake_name,
                    method_name=func.method_name,
                    property_name=func.property_name,
                    operator=operator,
                )
        case "std::string":
            if not func.is_ret_opt:
                function = get_string_template.format(
                    class_name=func.class_name,
                    method_snake_name=func.method_snake_name,
                    method_name=func.method_name,
                    property_name=func.property_name,
                    operator=operator,
                )
            else:
                function = get_optional_string_template.format(
                    class_name=func.class_name,
                    method_snake_name=func.method_snake_name,
                    method_name=func.method_name,
                    property_name=func.property_name,
                    operator=operator,
                )
        case _:
            if func.is_ret_enum:
                if not func.is_ret_opt:
                    function = get_enum_template.format(
                        return_type=func.return_type,
                        class_name=func.class_name,
                        method_snake_name=func.method_snake_name,
                        method_name=func.method_name,
                        property_name=func.property_name,
                        operator=operator,
                    )
                else:
                    function = get_optional_enum_template.format(
                        return_type=func.return_type,
                        class_name=func.class_name,
                        method_snake_name=func.method_snake_name,
                        method_name=func.method_name,
                        property_name=func.property_name,
                        operator=operator,
                    )

    return function


def generate_set(func: FunctionDetails, is_property_pointer: bool) -> str:
    function: str = ""
    operator = "->" if is_property_pointer else "."

    match func.parameter_type:
        case "int32_t":
            if not func.is_ret_opt:
                function = set_int32_template.format(
                    class_name=func.class_name,
                    method_snake_name=func.method_snake_name,
                    parameter_name=func.parameter_name,
                    method_name=func.method_name,
                    property_name=func.property_name,
                    operator=operator,
                )
            else:
                function = set_optional_int32_template.format(
                    class_name=func.class_name,
                    method_snake_name=func.method_snake_name,
                    parameter_name=func.parameter_name,
                    method_name=func.method_name,
                    property_name=func.property_name,
                    operator=operator,
                )
        case "uint64_t":
            if not func.is_ret_opt:
                function = set_uint64_template.format(
                    class_name=func.class_name,
                    method_snake_name=func.method_snake_name,
                    parameter_name=func.parameter_name,
                    method_name=func.method_name,
                    property_name=func.property_name,
                    operator=operator,
                )
            else:
                function = set_optional_uint64_template.format(
                    class_name=func.class_name,
                    method_snake_name=func.method_snake_name,
                    parameter_name=func.parameter_name,
                    method_name=func.method_name,
                    property_name=func.property_name,
                    operator=operator,
                )
        case "std::string":
            if not func.is_ret_opt:
                function = set_string_template.format(
                    class_name=func.class_name,
                    method_snake_name=func.method_snake_name,
                    parameter_name=func.parameter_name,
                    method_name=func.method_name,
                    property_name=func.property_name,
                    operator=operator,
                )
            else:
                function = set_optional_string_template.format(
                    class_name=func.class_name,
                    method_snake_name=func.method_snake_name,
                    parameter_name=func.parameter_name,
                    method_name=func.method_name,
                    property_name=func.property_name,
                    operator=operator,
                )
        case _:
            if func.is_param_enum:
                if not func.is_param_opt:
                    function = set_enum_template.format(
                        class_name=func.class_name,
                        method_snake_name=func.method_snake_name,
                        parameter_type=func.parameter_type,
                        method_name=func.method_name,
                        property_name=func.property_name,
                        operator=operator,
                    )
                else:
                    function = set_optional_enum_template.format(
                        return_type=func.return_type,
                        class_name=func.class_name,
                        method_snake_name=func.method_snake_name,
                        parameter_type=func.parameter_type,
                        parameter_name=func.parameter_name,
                        method_name=func.method_name,
                        property_name=func.property_name,
                        operator=operator,
                    )

    return function


text = "std::optional< std::string > 	State () "
i = extract_function_info(text, "AuthorizationArgs", "authorization_args", [])
print(generate_get(i, False))

text = "void 	SetState (std::optional< std::string > State)"
i = extract_function_info(text, "AuthorizationArgs", "authorization_args", [])

from pprint import pprint

pprint(vars(i))
print(generate_set(i, False))

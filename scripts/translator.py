from helper import to_snake_case
from parser import VarType, Param, Method
from template_method import TEMPLATE_METHOD, TEMPLATE_LAMBDA
from template_bind import TEMPLATE_BIND


def translate_type(var_type: VarType) -> str:
    if var_type.is_opt:
        return "Variant"

    if var_type.name == "std::string":
        return "String"

    if var_type.name == "std::string const":
        return "String"

    if not var_type.is_discord:
        return var_type.name

    if var_type.is_enum:
        return f"Discord{var_type.name}::Enum"

    return f"Discord{var_type.name}"


def translate_param(param: Param) -> str:
    var_type = translate_type(param.type)
    name = to_snake_case(param.name)

    return f"{var_type} {name}"


def translate_passing_param(param: Param) -> str:
    if not param.type.is_callback:
        return to_snake_case(param.name)

    return TEMPLATE_LAMBDA.format(signal_name=param.name)


def translate_method(
    method: Method, class_name: str, property_name: str, operator: str
) -> str:
    """
    Translate Method class to a template string.

    Returns a tuple with informations to be inserted into source or header files:
    - Method code
    - Code to be inserted in _bind_methods()
    - Includes to add into header file
    """
    ret = translate_type(method.ret)
    method_snake_name = to_snake_case(method.name)
    params = ", ".join([translate_param(p) for p in method.uncallables])
    return_keyword = "" if ret == "void" else "return "
    method_name = method.name
    passing_params = ", ".join([translate_passing_param(p) for p in method.params])
    bind_params = [f'"{to_snake_case(p.name)}"' for p in method.uncallables]
    bind_params = [f'"{method_snake_name}"'] + bind_params
    bind_params = ", ".join(bind_params)
    includes = {'\n#include "discord_enum.h"'} if method.use_enum else set()

    return (
        TEMPLATE_METHOD.format(
            return_type=ret,
            class_name=class_name,
            method_snake_name=method_snake_name,
            params=params,
            return_keyword=return_keyword,
            property_name=property_name,
            operator=operator,
            method_name=method_name,
            passing_params=passing_params,
        ),
        TEMPLATE_BIND.format(
            bind_params=bind_params,
            class_name=class_name,
            method_snake_name=method_snake_name,
        ),
        includes,
    )

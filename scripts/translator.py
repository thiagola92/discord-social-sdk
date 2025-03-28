from helper import to_snake_case
from parser import VarType, Param, Method
from template_method import TEMPLATE_METHOD


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


def translate_method(
    method: Method, class_name: str, property_name: str, operator: str
) -> str:
    """
    Translate Method class to a template string.

    Worst than using get/set templates, but still  something to start.
    """

    ret = translate_type(method.ret)
    method_snake_name = to_snake_case(method.name)
    params = ", ".join([translate_param(p) for p in method.params])
    return_keyword = "" if ret == "void" else "return "
    method_name = method.name
    params_names = ", ".join([to_snake_case(p.name) for p in method.params])

    if method.is_setter:
        method_snake_name = "set_" + method_snake_name
        method_name = "Set" + method_name
    elif method.maybe_getter:
        method_snake_name = "get_" + method_snake_name

    return TEMPLATE_METHOD.format(
        return_type=ret,
        class_name=class_name,
        method_snake_name=method_snake_name,
        params=params,
        return_keyword=return_keyword,
        property_name=property_name,
        operator=operator,
        method_name=method.name,
        params_names=params_names,
    )

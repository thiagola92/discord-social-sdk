# Responsible for creating fake data.
from data import ParamInfo, TypeInfo, FunctionInfo


def fake_enums_params(params: list[ParamInfo]) -> ParamInfo:
    """
    Create fake parameters that are later used to discover
    the enum type of others parameters.

    For example, lets say that we have the following function overloading:
        enum_to_string(EnumA x)
        enum_to_string(EnumB x)
        enum_to_string(EnumC x)
    When it transform to one function, it will look like:
        enum_to_string(int x, Variant enum_type)

    Fake parameter and it type are marked as fake
    so we can later decide how to represent them.
    """

    fake_params = []
    use_suffix = len(params) > 1
    suffix = ""

    for i, p in enumerate(params):
        if use_suffix:
            suffix = str(i)

        fake_param = ParamInfo()

        if isinstance(p.type, TypeInfo):
            fake_param.type = fake_type(p.type)
        else:
            fake_param.type = fake_function(p.type)

        fake_param.name = f"EnumType{suffix}"
        fake_param.gdscript_name = f"enum_type{suffix}"
        fake_param.callback = p.callback
        fake_param.enum = p.enum
        fake_param.fake = True

        fake_params.append(fake_param)

    return fake_params


def fake_type(type_info: TypeInfo) -> str:
    fake_type = TypeInfo()
    fake_type.name = type_info.name
    fake_type.extra = type_info.extra

    # Utility.
    fake_type.callback = type_info.callback
    fake_type.enum = type_info.enum
    fake_type.fake = True
    fake_type.overloading = type_info.overloading

    return fake_type


def fake_function(function_info: FunctionInfo) -> str:
    fake_function = FunctionInfo()
    fake_function.static = function_info.static
    fake_function.type = function_info.type
    fake_function.name = function_info.name
    fake_function.templates = function_info.templates
    fake_function.params = function_info.params

    # Documentation.
    fake_function.short_desc = function_info.short_desc
    fake_function.long_desc = function_info.long_desc

    # Utility.
    fake_function.gdscript_name = function_info.gdscript_name
    fake_function.fake = True
    fake_function.overloading = function_info.overloading

    return fake_function

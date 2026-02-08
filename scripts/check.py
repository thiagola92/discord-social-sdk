# Responsible for checking conditions.
from name import to_gdscript_class_name
from data import (
    FunctionInfo,
    ClassInfo,
    NamespaceInfo,
    TypeInfo,
    CallbackInfo,
    ParamInfo,
    EnumInfo,
)


def check_callbacks(class_info: ClassInfo) -> None:
    """
    Check every parameter that is a callback.

    This contains only the logic for discovery,
    not for solving any complications from enums.
    """
    for f in class_info.functions:
        for p in f.params:
            if not p.type.name.startswith("discordpp::"):
                continue

            for c in class_info.callbacks:
                n = p.type.name.split("::")

                if n[-1] == c.name:
                    p.callback = True
                    p.type.callback = True
                    p.type.callback_ref = c


def check_enums(namespace_info: NamespaceInfo) -> None:
    """
    Check every type that is an enum.

    This contains only the logic for discovery,
    not for solving any complications from enums.
    """

    # Create dictionary with searched enums.
    enums: dict[str, EnumInfo] = {}

    for e in namespace_info.enums:
        enums[to_gdscript_class_name(e.name)] = e

    for c in namespace_info.classes:
        for e in c.enums:
            enums[to_gdscript_class_name(c.name + e.name)] = e

    # Start checking enum everywhere.
    for f in namespace_info.functions:
        check_type_enums(f, enums)

    for c in namespace_info.classes:
        for f in c.functions:
            check_type_enums(f, enums)

    for c in namespace_info.callbacks:
        check_type_enums(c, enums)

    for c in namespace_info.classes:
        for cc in c.callbacks:
            check_type_enums(cc, enums)


def check_function_enums(
    function_info: FunctionInfo,
    enums: dict[str, EnumInfo],
) -> None:
    """
    Check function return type and parameters that are enums.

    This contains only the logic for discovery,
    not for solving any complications from enums.
    """

    name = to_gdscript_class_name(function_info.type.name)

    if name in enums.keys():
        function_info.type.enum = True
        function_info.type.enum_ref = enums[name]

    for p in function_info.params:
        if not isinstance(p.type, TypeInfo):
            continue

        n = to_gdscript_class_name(p.type.name)

        if n in enums.keys():
            p.enum = True
            p.type.enum = True
            p.type.enum_ref = enums[n]


def check_callback_enums(
    callback_info: CallbackInfo,
    enums: dict[str, EnumInfo],
) -> None:
    """
    Check callback types that are enums.

    This contains only the logic for discovery,
    not for solving any complications from enums.
    """

    name = to_gdscript_class_name(callback_info.type.name)

    if name in enums.keys():
        callback_info.type.enum = True
        callback_info.type.enum_ref = enums[name]

    for t in callback_info.type.templates:
        if isinstance(t, FunctionInfo):
            check_function_enums(t, enums)


def check_type_enums(
    info: TypeInfo | FunctionInfo | CallbackInfo | ParamInfo,
    enums: dict[str, EnumInfo],
) -> None:
    """
    Check types that are enums.

    This contains only the logic for discovery,
    not for solving any complications from enums.
    """
    if isinstance(info, FunctionInfo):
        for p in info.params:
            check_type_enums(p, enums)

        check_type_enums(info.type, enums)
    elif isinstance(info, CallbackInfo):
        check_type_enums(info.type, enums)
    elif isinstance(info, ParamInfo):
        check_type_enums(info.type, enums)
        info.enum = info.type.enum
    elif isinstance(info, TypeInfo):
        for t in info.templates:
            check_type_enums(t, enums)

        n = to_gdscript_class_name(info.name)

        if n in enums.keys():
            info.enum = True
            info.enum_ref = enums[n]


def check_overloading(functions_info: list[FunctionInfo]) -> None:
    """
    Check every function that is overloading.

    This contains only the logic for discovery,
    not for solving any complications from overloading.

    ### Context
    GDScript doesn't support function overloading.This means that,
    we can't have two functions having the same name but different parameters and return:

        func example(a: int) -> String
        func example(a: int, b: int) -> String
        func example(a: float) -> String

    An enum parameter is nothing more than an integer. This means that,
    we can't indentify an enum after receiving it value:

        func _ready() -> void
            example(0)             # "int"
            example(MyEnum.ZERO)   # "int"

        func example(a: int) -> String:
            return type_string(typeof(a))

    Using Variant and checking type will also not work:

        func _ready() -> void
            example(0)             # true
            example(MyEnum.ZERO)   # true

        func example((a: Variant) -> bool:
            return a is MyEnum
    """

    counter: dict[str, int] = {}

    for f in functions_info:
        if f.gdscript_name in counter:
            counter[f.gdscript_name] += 1
        else:
            counter[f.gdscript_name] = 0

    for f in functions_info:
        if counter[f.gdscript_name] > 0:
            f.overloading = True

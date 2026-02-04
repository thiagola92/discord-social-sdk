# Responsible for forging parts of the code.
from pprint import pprint

from fake import fake_enums_params
from name import to_gdscript_variable_name
from collect import NamespaceInfo, FunctionInfo, ClassInfo, ParamInfo
from discover import (
    OverloadingPattern,
    discover_overloading_pattern,
    discover_overloading_groups,
)
from translate import (
    discord_type_to_godot_type,
    discord_params_to_godot_params,
    discord_variable_to_godot_variable,
    godot_variables_to_discord_variables,
    is_discord_void,
    discord_variables_to_godot_variables,
)
from template.code.register_types_cpp.register_abstract import get_register_abstract
from template.code.register_types_cpp.register_runtime import get_register_runtime
from template.code.discord_enum_h.enum_definition import get_enum_definition
from template.code.discord_enum_h.enum_bind import get_enum_bind
from template.code.discord_enum_h.enum_cast import get_enum_cast
from template.code.discord_classes_h.class_declaration import get_class_declaration
from template.code.discord_classes_h.class_definition import get_class_definition
from template.code.discord_classes_h.class_definition_g import get_class_definition_g
from template.code.discord_classes_h.constructor_private import get_constructor_private
from template.code.discord_classes_h.constructor_public import get_constructor_public
from template.code.discord_classes_h.function_declaration import (
    get_function_declaration,
)
from template.code.discord_class_cpp.bind import get_bind
from template.code.discord_class_cpp.return_statements import get_return_statements
from template.code.discord_class_cpp.bind_static import get_bind_static
from template.code.discord_class_cpp.function_definition import get_function_definition
from template.code.discord_class_cpp.function_statements import get_function_statements
from template.code.discord_class_cpp.overloading.if_statement import get_if_statement
from template.code.discord_class_cpp.overloading.condition import get_condition

######################################################################
# register_types.cpp
######################################################################


def forge_register_abstracts(namespace_info: NamespaceInfo) -> str:
    register_abstracts = []

    for e in namespace_info.enums:
        register_abstracts.append(get_register_abstract(e.name))

    for c in namespace_info.classes:
        for e in c.enums:
            register_abstracts.append(get_register_abstract(f"{c.name}{e.name}"))

    register_abstracts += [get_register_abstract("")]  # "Discord" class.
    register_abstracts = sorted(register_abstracts)
    register_abstracts = "\n".join(register_abstracts)

    return register_abstracts


def forge_register_runtimes(namespace_info: NamespaceInfo) -> str:
    register_runtimes = []

    for c in namespace_info.classes:
        register_runtimes.append(get_register_runtime(c.name))

    register_runtimes = "\n".join(register_runtimes)

    return register_runtimes


######################################################################
# discord_enum.h
######################################################################


def forge_enum_definitions(namespace_info: NamespaceInfo) -> str:
    enums_definitions = []

    for e in namespace_info.enums:
        enums_definitions.append(
            get_enum_definition(
                enum_name=e.name,
                binds="".join([get_enum_bind(v.name) for v in e.values]),
                values="".join([v.name + v.init for v in e.values]),
            )
        )

    for c in namespace_info.classes:
        for e in c.enums:
            enums_definitions.append(
                get_enum_definition(
                    enum_name=c.name + e.name,
                    binds="".join([get_enum_bind(v.name) for v in e.values]),
                    values="".join([v.name + v.init for v in e.values]),
                )
            )

    enums_definitions = sorted(enums_definitions)
    enums_definitions = "".join(enums_definitions)

    return enums_definitions


def forge_enum_casts(namespace_info: NamespaceInfo) -> str:
    enums_casts = [get_enum_cast(e.name) for e in namespace_info.enums]

    for c in namespace_info.classes:
        enums_casts += [get_enum_cast(c.name + e.name) for e in c.enums]

    enums_casts = sorted(enums_casts)
    enums_casts = "".join(enums_casts)

    return enums_casts


######################################################################
# discord_classes.h
######################################################################


def forge_classes_declarations(namespace_info: NamespaceInfo) -> str:
    classes_declarations = []

    for c in namespace_info.classes:
        classes_declarations.append(get_class_declaration(c.name))

    classes_declarations.append(get_class_declaration(""))  # "Discord" class.
    classes_declarations = sorted(classes_declarations)
    classes_declarations = "".join(classes_declarations)

    return classes_declarations


def forge_classes_definitions(namespace_info: NamespaceInfo) -> str:
    classes_definitions = []

    for c in namespace_info.classes:
        public = any([cc for cc in c.constructors if len(cc.params) == 0])
        f = forge_functions_declarations(c)
        o = forge_overloadings_declarations(c)

        if public:
            classes_definitions.append(
                get_class_definition(
                    class_name=c.name,
                    constructor_public=get_constructor_public(c.name),
                    functions=f,
                    overloadings=o,
                )
            )
        else:
            classes_definitions.append(
                get_class_definition(
                    class_name=c.name,
                    constructor_private=get_constructor_private(c.name),
                    functions=f,
                    overloadings=o,
                )
            )

    # "Discord" class.
    functions_declarations = forge_functions_declarations(namespace_info)
    overloadings_declarations = forge_overloadings_declarations(namespace_info)
    namespace_declarations = get_class_definition_g(
        functions_declarations, overloadings=overloadings_declarations
    )

    classes_definitions.append(namespace_declarations)
    classes_definitions = sorted(classes_definitions)
    classes_definitions = "".join(classes_definitions)

    return classes_definitions


def forge_functions_declarations(info: NamespaceInfo | ClassInfo) -> str:
    functions_declarations = []

    for f in info.functions:
        if not f.overloading:
            functions_declarations.append(forge_function_declaration(f))

    functions_declarations = sorted(functions_declarations)
    functions_declarations = "".join(functions_declarations)

    return functions_declarations


def forge_function_declaration(function_info: FunctionInfo) -> str:
    return_type = discord_type_to_godot_type(function_info.type)
    params = discord_params_to_godot_params(function_info.params)
    function_declaration = get_function_declaration(
        modifier="static " if function_info.static else "",
        ret=return_type,
        name=function_info.gdscript_name,
        params=params,
    )

    return function_declaration


def forge_overloadings_declarations(info: NamespaceInfo | ClassInfo) -> str:
    overloading_groups = discover_overloading_groups(info)
    overloading_declarations = []

    for g in overloading_groups.values():
        overloading_declarations.append(forge_overloading_declaration(g))

    overloading_declarations = sorted(overloading_declarations)
    overloading_declarations = "".join(overloading_declarations)

    return overloading_declarations


def forge_overloading_declaration(group: list[FunctionInfo]) -> str:
    overloading_pattern = discover_overloading_pattern(group)

    if overloading_pattern == OverloadingPattern.RET_SAME_ARGS_ENUMS:
        for f in group:
            for p in f.params:
                p.overloading = True
                p.type.overloading = True

            r = discord_type_to_godot_type(f.type)
            p = f.params + fake_enums_params(f.params)
            p = discord_params_to_godot_params(p)

            return get_function_declaration(
                modifier="static " if f.static else "",
                ret=r,
                name=f.gdscript_name,
                params=p,
            )

    assert False, "A new case of overloading needs to be created."


######################################################################
# <discord_class>.cpp
######################################################################


def forge_binds(info: NamespaceInfo | ClassInfo) -> str:
    functions_binds = forge_functions_binds(info)
    overloadings_binds = forge_overloadings_binds(info)

    return functions_binds + overloadings_binds


def forge_functions_binds(info: NamespaceInfo | ClassInfo) -> str:
    class_name = info.name if isinstance(info, ClassInfo) else ""
    binds = []

    for f in info.functions:
        if not f.overloading:
            binds.append(forge_function_bind(f, class_name))

    binds = sorted(binds)
    binds = "".join(binds)

    return binds


def forge_function_bind(function_info: FunctionInfo, class_name: str) -> str:
    p = forge_params_bind(function_info.params)

    if function_info.static:
        return get_bind_static(
            function=function_info.gdscript_name,
            class_name=class_name,
            params=p,
        )

    return get_bind(
        function=function_info.gdscript_name,
        class_name=class_name,
        params=p,
    )


def forge_overloadings_binds(info: NamespaceInfo | ClassInfo) -> str:
    overloading_groups = discover_overloading_groups(info)
    class_name = info.name if isinstance(info, ClassInfo) else ""
    binds = []

    for g in overloading_groups.values():
        binds.append(forge_overloading_bind(g, class_name))

    binds = sorted(binds)
    binds = "".join(binds)

    return binds


def forge_overloading_bind(group: list[FunctionInfo], class_name: str) -> str:
    overloading_pattern = discover_overloading_pattern(group)

    if overloading_pattern == OverloadingPattern.RET_SAME_ARGS_ENUMS:
        for f in group:
            p = f.params + fake_enums_params(f.params)
            p = forge_params_bind(p)

            if f.static:
                return get_bind_static(
                    function=f.gdscript_name,
                    class_name=class_name,
                    params=p,
                )

            return get_bind(
                function=f.gdscript_name,
                class_name=class_name,
                params=p,
            )

    assert False, "A new case of overloading needs to be created."


def forge_params_bind(params_info: list[ParamInfo]) -> str:
    params = []

    for p in params_info:
        params.append(f', "{p.gdscript_name}"')

    params = "".join(params)

    return params


def forge_functions_definitions(info: NamespaceInfo | ClassInfo) -> str:
    class_name = info.name if isinstance(info, ClassInfo) else ""
    functions_definitions = []

    for f in info.functions:
        if not f.overloading:
            functions_definitions.append(forge_function_definition(f, class_name))

    functions_definitions = sorted(functions_definitions)
    functions_definitions = "".join(functions_definitions)

    return functions_definitions


def forge_function_definition(function_info: FunctionInfo, class_name: str) -> str:
    return_type = discord_type_to_godot_type(function_info.type)
    params = discord_params_to_godot_params(function_info.params)
    statements = forge_function_statements(function_info, class_name)

    return get_function_definition(
        ret=return_type,
        class_name=class_name,
        function=function_info.gdscript_name,
        params=params,
        statements=statements,
    )


def forge_function_statements(function_info: FunctionInfo, class_name: str) -> str:
    conversion_statements = godot_variables_to_discord_variables(function_info.params)
    call_statement = forge_call_statement(function_info, class_name)
    return_statements = forge_return_statements(function_info)

    return get_function_statements(
        conversion_statements=conversion_statements,
        call_statement=call_statement,
        return_statements=return_statements,
    )


def forge_call_statement(function_info: FunctionInfo, class_name: str) -> str:
    params = []

    for i, _ in enumerate(function_info.params):
        params.append(f"p{i}")

    params = ", ".join(params)

    if function_info.static and class_name:
        call = f"discordpp::{class_name}::{function_info.name}({params})"
    elif function_info.static:
        call = f"discordpp::{function_info.name}({params})"
    else:
        call = f"obj->{function_info.name}({params})"

    if is_discord_void(function_info.type):
        return f"{call};"

    return f"auto r0 = {call};"


def forge_return_statements(function_info: FunctionInfo) -> str:
    if is_discord_void(function_info.type):
        return ""

    target = "r1"
    conversion = discord_variable_to_godot_variable(function_info.type, target, "r0")

    return get_return_statements(conversion=conversion, target=target)


def forge_overloadings_definitions(info: NamespaceInfo | ClassInfo) -> str:
    class_name = info.name if isinstance(info, ClassInfo) else ""
    overloading_groups = discover_overloading_groups(info)
    overloadings_definitions = []

    for g in overloading_groups.values():
        overloadings_definitions.append(forge_overloading_definition(g, class_name))

    overloadings_definitions = sorted(overloadings_definitions)
    overloadings_definitions = "".join(overloadings_definitions)

    return overloadings_definitions


def forge_overloading_definition(group: list[FunctionInfo], class_name: str) -> str:
    overloading_pattern = discover_overloading_pattern(group)

    if overloading_pattern == OverloadingPattern.RET_SAME_ARGS_ENUMS:
        for f in group:
            r = discord_type_to_godot_type(f.type)
            p = f.params + fake_enums_params(f.params)
            p = discord_params_to_godot_params(p)
            s = forge_overloading_statements(group, class_name, overloading_pattern)

            return get_function_definition(
                ret=r,
                class_name=class_name,
                function=f.gdscript_name,
                params=p,
                statements=s,
            )

    assert False, "A new case of overloading needs to be created."


def forge_overloading_statements(
    group: list[FunctionInfo],
    class_name: str,
    overloading_pattern: OverloadingPattern,
) -> str:
    statements = []
    fake_params = fake_enums_params(group[0].params)

    if overloading_pattern == OverloadingPattern.RET_SAME_ARGS_ENUMS:
        c = forge_overloading_condition(fake_params)

        statements.append(
            discord_variables_to_godot_variables(fake_params, len(fake_params))
        )

        for f in group:
            s = forge_function_statements(f, class_name)

            statements.append(
                get_if_statement(
                    condition=c,
                    statements=s,
                )
            )

        statements.append('return "";')

        return "\n".join(statements)

    assert False, "A new case of overloading needs to be created."


def forge_overloading_condition(fake_params: list[ParamInfo]) -> str:
    length = len(fake_params)
    conditions = []

    for i, fp in enumerate(fake_params):
        conditions.append(
            get_condition(
                value0=f"p{length + i}",
                operator="==",
                value1=f'"{fp.type.name}"',
            )
        )

    conditions = " && ".join(conditions)

    return conditions

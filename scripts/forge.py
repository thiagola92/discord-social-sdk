# Responsible for forging parts of the code.
from pprint import pprint

from fake import fake_enums_params
from collect import NamespaceInfo, FunctionInfo, ClassInfo, ParamInfo
from translate import discord_type_to_godot_type, discord_params_to_godot_params
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
from template.code.discord_class_cpp.bind_static import get_bind_static
from discover import (
    OverloadingPattern,
    discover_overloading_pattern,
    discover_overloading_groups,
)

########## register_types.cpp ##########


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


########## discord_enum.h ##########


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


########## discord_classes.h ##########


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

    if overloading_pattern == OverloadingPattern.ENUMS:
        for f in group:
            for p in f.params:
                p.overloading = True

            r = discord_type_to_godot_type(f.type)
            p = f.params + fake_enums_params(f.params)
            p = discord_params_to_godot_params(p)

            return get_function_declaration(
                modifier="static " if f.static else "",
                ret=r,
                name=f.gdscript_name,
                params=p,
            )
    else:
        # TODO: Create generic treatment for overloadings.
        assert False, "A new case of overloading needs to be created."


########## discord.cpp ##########


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


def forge_function_bind(function: FunctionInfo, class_name: str) -> str:
    p = forge_params_bind(function.params)

    if function.static:
        return get_bind_static(
            function=function.name,
            class_name=class_name,
            params=p,
        )

    return get_bind(
        function=function.name,
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

    if overloading_pattern == OverloadingPattern.ENUMS:
        for f in group:
            p = f.params + fake_enums_params(f.params)
            p = forge_params_bind(p)

            if f.static:
                return get_bind_static(
                    function=f.name,
                    class_name=class_name,
                    params=p,
                )

            return get_bind(
                function=f.name,
                class_name=class_name,
                params=p,
            )
    else:
        # TODO: Create generic treatment for overloadings.
        assert False, "A new case of overloading needs to be created."


def forge_params_bind(params_info: list[ParamInfo]) -> str:
    params = []

    for p in params_info:
        params.append(f", {p.gdscript_name}")

    params = "".join(params)

    return params


def forge_functions_definitions(info: NamespaceInfo | ClassInfo) -> str:
    functions_definitions = []

    for f in info.functions:
        pass

    functions_definitions = sorted(functions_definitions)
    functions_definitions = "".join(functions_definitions)

    return functions_definitions


########## <discord_class>.cpp ##########

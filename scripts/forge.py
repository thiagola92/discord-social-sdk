# Responsible for forging parts of the code.
from fake import fake_enums_params
from collect import NamespaceInfo, FunctionInfo, ClassInfo, ParamInfo
from discover import discover_overloading_type, OverloadingPattern
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


def forge_enum_casts(namespace_info: NamespaceInfo) -> str:
    enums_casts = [get_enum_cast(e.name) for e in namespace_info.enums]

    for c in namespace_info.classes:
        enums_casts += [get_enum_cast(c.name + e.name) for e in c.enums]

    enums_casts = sorted(enums_casts)
    enums_casts = "".join(enums_casts)

    return enums_casts


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


def forge_classes_definitions(namespace_info: NamespaceInfo) -> str:
    classes_definitions = []

    for c in namespace_info.classes:
        public = any([cc for cc in c.constructors if len(cc.params) == 0])
        f = forge_classes_definition(c)

        if public:
            classes_definitions.append(
                get_class_definition(
                    class_name=c.name,
                    constructor_private="",
                    functions=f,
                    constructor_public=get_constructor_public(c.name),
                )
            )
        else:
            classes_definitions.append(
                get_class_definition(
                    class_name=c.name,
                    constructor_private=get_constructor_private(c.name),
                    functions=f,
                    constructor_public="",
                )
            )

    # "Discord" class.
    functions_declarations = forge_functions_declarations(namespace_info)
    overloadings_declarations = forge_overloadings_declaration(namespace_info)
    namespace_declarations = get_class_definition_g(
        functions_declarations, overloadings=overloadings_declarations
    )

    classes_definitions.append(namespace_declarations)
    classes_definitions = sorted(classes_definitions)
    classes_definitions = "".join(classes_definitions)

    return classes_definitions


def forge_classes_definition(class_info: ClassInfo) -> str:
    functions_declarations = []

    for f in class_info.functions:
        if not f.overloading:
            functions_declarations.append(forge_function_declaration(f))

    functions_declarations = "\n".join(functions_declarations)

    return functions_declarations


def forge_functions_declarations(namespace_info: NamespaceInfo) -> str:
    functions_declarations = []

    for f in namespace_info.functions:
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


def forge_overloadings_declaration(namespace_info: NamespaceInfo) -> str:
    overloading_groups: dict[str, list[FunctionInfo]] = {}
    overloading_declarations = []

    for f in namespace_info.functions:
        if f.overloading:
            if f.gdscript_name in overloading_groups:
                overloading_groups[f.gdscript_name].append(f)
            else:
                overloading_groups[f.gdscript_name] = [f]

    for g in overloading_groups.values():
        t = discover_overloading_type(g)

        if t == OverloadingPattern.ENUMS:
            for f in g:
                for p in f.params:
                    p.overloading = True

                r = discord_type_to_godot_type(f.type)
                p = f.params + fake_enums_params(f.params)
                p = discord_params_to_godot_params(p)

                overloading_declarations.append(
                    get_function_declaration(
                        modifier="static " if g[0].static else "",
                        ret=r,
                        name=f.gdscript_name,
                        params=p,
                    )
                )

                break  # Do once only.

    overloading_declarations = sorted(overloading_declarations)
    overloading_declarations = "".join(overloading_declarations)

    return overloading_declarations


def forge_classes_declarations(namespace_info: NamespaceInfo) -> str:
    classes_declarations = []

    for c in namespace_info.classes:
        classes_declarations.append(get_class_declaration(c.name))

    classes_declarations.append(get_class_declaration(""))  # "Discord" class.
    classes_declarations = sorted(classes_declarations)
    classes_declarations = "".join(classes_declarations)

    return classes_declarations

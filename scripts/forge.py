# Responsible for forging parts of the code.
from collect import NamespaceInfo
from translate import discord_type_to_godot_type, discord_params_to_godot_params
from template.file.register_types_h import get_register_types_h
from template.file.register_types_cpp import get_register_types_cpp
from template.file.discord_enum_h import get_discord_enum_h
from template.file.discord_classes_h import get_discord_classes_h
from template.file.discord_class_cpp import get_discord_class_cpp
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


def forge_functions_declarations(namespace_info: NamespaceInfo) -> str:
    functions_declarations = []

    for f in namespace_info.functions:
        r = discord_type_to_godot_type(f.type)
        p = discord_params_to_godot_params(f.params)

        functions_declarations.append(
            get_function_declaration(
                modifier="static " if f.static else "",
                ret=r,
                name=f.gdscript_name,
                params=p,
            )
        )

        if f.overloading:
            functions_declarations[-1] += " // TODO: Solve overloading\n"

    functions_declarations = sorted(functions_declarations)
    functions_declarations = "".join(functions_declarations)

    return functions_declarations


def forge_classes_declarations(namespace_info: NamespaceInfo) -> str:
    classes_declarations = []

    for c in namespace_info.classes:
        classes_declarations.append(get_class_declaration(c.name))

    classes_declarations.append(get_class_declaration(""))  # "Discord" class.
    classes_declarations = sorted(classes_declarations)
    classes_declarations = "".join(classes_declarations)

    return classes_declarations


def forge_classes_definitions(namespace_info: NamespaceInfo) -> str:
    functions_declarations = forge_functions_declarations(namespace_info)
    classes_definitions = []

    for c in namespace_info.classes:
        cf = []

        for f in c.functions:
            r = discord_type_to_godot_type(f.type)
            p = discord_params_to_godot_params(f.params)

            cf.append(
                get_function_declaration(
                    modifier="static " if f.static else "",
                    ret=r,
                    name=f.gdscript_name,
                    params=p,
                )
            )

            if f.overloading:
                cf[-1] += " // TODO: Solve overloading\n"

        cf = "\n".join(cf)

        if any([cc for cc in c.constructors if len(cc.params) == 0]):
            classes_definitions.append(
                get_class_definition(
                    class_name=c.name,
                    constructor_private="",
                    functions=cf,
                    constructor_public=get_constructor_public(c.name),
                )
            )
        else:
            classes_definitions.append(
                get_class_definition(
                    class_name=c.name,
                    constructor_private=get_constructor_private(c.name),
                    functions=cf,
                    constructor_public="",
                )
            )

    classes_definitions.append(get_class_definition_g(functions_declarations))
    classes_definitions = sorted(classes_definitions)
    classes_definitions = "".join(classes_definitions)

    return classes_definitions

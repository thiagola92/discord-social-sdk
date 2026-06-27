# Functions to update parts of the XML docs.
# Reference: https://docs.godotengine.org/en/latest/engine_details/class_reference/index.html#doc-class-reference-primer
#
# type: ignore
from xml.etree.ElementTree import Element

from docs_gen.bbcode import get_deprecated_text, to_bbcode
from templates.docs.callback_param import get_callback_param
from templates.docs.variant_param import get_variant_param
from templates.docs.variant_return import get_variant_return
from utility.data import ClassInfo, EnumInfo, FunctionInfo, NamespaceInfo, TypeInfo
from utility.translate import discord_type_to_gdscript_type, is_discord_optional


def update_class(tree: Element, class_info: ClassInfo) -> None:
    brief_description = tree.find("brief_description")

    if class_info.short_desc and brief_description is not None:
        d = to_bbcode(class_info.short_desc)
        brief_description.text += f"{d}\n"

    description = tree.find("description")

    if class_info.long_desc and description is not None:
        d = to_bbcode(class_info.long_desc)
        description.text += f"{d}\n"


def update_functions(tree: Element, info: NamespaceInfo | ClassInfo) -> None:
    for f in info.functions:
        update_function(tree, f)


def update_function(tree: Element, function_info: FunctionInfo) -> None:
    method = tree.find(f"methods/method[@name='{function_info.gdscript_name}']")

    if method is None:
        return

    description = method.find("description")

    if description is None:
        return

    if function_info.short_desc:
        dt = get_deprecated_text(function_info.short_desc)

        if dt is not None:
            method.attrib["deprecated"] = dt

        d = to_bbcode(function_info.short_desc)
        description.text += f"{d}\n\t\t\t"

    if function_info.long_desc:
        dt = get_deprecated_text(function_info.long_desc)

        if dt is not None:
            method.attrib["deprecated"] = dt

        d = to_bbcode(function_info.long_desc)
        description.text += f"{d}\n\t\t\t"

    update_callback_params(description, function_info)
    update_variant_params(description, function_info)
    update_variant_return(description, function_info)


def update_enum(tree: Element, enum_info: EnumInfo) -> None:
    brief_description = tree.find("brief_description")

    if enum_info.short_desc and brief_description is not None:
        d = to_bbcode(enum_info.short_desc)
        brief_description.text += f"{d}\n"

    description = tree.find("description")

    if enum_info.long_desc and description is not None:
        d = to_bbcode(enum_info.long_desc)
        description.text += f"{d}\n"

    for ev in enum_info.values:
        c = tree.find(f"constants/constant[@name='{ev.name}']")

        if c is not None:
            if ev.short_desc:
                d = to_bbcode(ev.short_desc)
                c.text += f"{d}\n\t\t"

            if ev.long_desc:
                d = to_bbcode(ev.long_desc)
                c.text += f"{d}\n\t\t"


def update_callback_params(tree: Element, function_info: FunctionInfo) -> None:
    for p in function_info.params:
        if not p.callback:
            continue

        params = []

        for pp in p.type.callback_ref.type.templates[0].params:
            type_name = discord_type_to_gdscript_type(pp.type)
            params.append(f"{pp.gdscript_name}: {type_name}")

        params = ", ".join(params)
        return_type = discord_type_to_gdscript_type(function_info.type)

        tree.text += get_callback_param(
            param_name=p.gdscript_name,
            params=params,
            return_type=return_type,
        )


def update_variant_params(tree: Element, function_info: FunctionInfo) -> None:
    for p in function_info.params:
        if is_discord_optional(p.type):
            type_name = discord_type_to_gdscript_type(p.type.templates[0])

            if p.type.templates[0].enum:
                type_name = f"[enum {type_name}]"
            else:
                type_name = f"[{type_name}]"

            tree.text += get_variant_param(
                param_name=p.gdscript_name,
                type_name=type_name,
            )


def update_variant_return(tree: Element, function_info: FunctionInfo) -> None:
    if not is_discord_optional(function_info.type):
        return

    template = function_info.type.templates[0]
    type_name = discord_type_to_gdscript_type(template)

    if isinstance(template, TypeInfo) and template.enum:
        type_name = f"[enum {type_name}]"
    else:
        type_name = f"[{type_name}]"

    tree.text += get_variant_return(type_name=type_name)

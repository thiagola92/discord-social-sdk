# Responsible for updating XML documentation
# Reference: https://docs.godotengine.org/en/latest/engine_details/class_reference/index.html#doc-class-reference-primer
from xml.etree.ElementTree import Element

from data import FunctionInfo, ClassInfo, NamespaceInfo, EnumInfo, TypeInfo
from bbcode import to_bbcode, get_deprecated_text
from translate import is_discord_optional, discord_type_to_gdscript_type
from template.xml.variant_param import get_variant_param
from template.xml.callback_param import get_callback_param
from template.xml.variant_return import get_variant_return


def document_class(tree: Element, class_info: ClassInfo) -> None:
    brief_description = tree.find("brief_description")

    if class_info.short_desc and brief_description is not None:
        d = to_bbcode(class_info.short_desc)
        brief_description.text += f"{d}\n"

    description = tree.find("description")

    if class_info.long_desc and description is not None:
        d = to_bbcode(class_info.long_desc)
        description.text += f"{d}\n"


def document_functions(tree: Element, info: NamespaceInfo | ClassInfo) -> None:
    for f in info.functions:
        document_function(tree, f)


def document_function(tree: Element, function_info: FunctionInfo) -> None:
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

    document_callback_params(description, function_info)
    document_variant_params(description, function_info)
    document_variant_return(description, function_info)


def document_enum(tree: Element, enum_info: EnumInfo) -> None:
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


def document_callback_params(tree: Element, function_info: FunctionInfo) -> None:
    for p in function_info.params:
        if not p.callback:
            continue

        params = []

        for pp in p.type.callback_ref.type.templates[0].params:
            type_name = discord_type_to_gdscript_type(pp.type)
            params.append(f"{pp.gdscript_name}: {type_name}")

        params = ", ".join(params)

        tree.text += get_callback_param(
            param_name=p.gdscript_name,
            params=params,
        )


def document_variant_params(tree: Element, function_info: FunctionInfo) -> None:
    for p in function_info.params:
        if is_discord_optional(p.type):
            type_name = discord_type_to_gdscript_type(p.type.templates[0])

            if p.enum:
                type_name = f"[enum {type_name}]"
            else:
                type_name = f"[{type_name}]"

            tree.text += get_variant_param(
                param_name=p.gdscript_name,
                type_name=type_name,
            )


def document_variant_return(tree: Element, function_info: FunctionInfo) -> None:
    if not is_discord_optional(function_info.type):
        return

    template = function_info.type.templates[0]
    type_name = discord_type_to_gdscript_type(template)

    if isinstance(template, TypeInfo) and template.enum:
        type_name = f"[enum {type_name}]"
    else:
        type_name = f"[{type_name}]"

    tree.text += get_variant_return(type_name=type_name)

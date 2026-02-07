# Responsible for updating XML documentation
# Reference: https://docs.godotengine.org/en/latest/engine_details/class_reference/index.html#doc-class-reference-primer
from xml.etree.ElementTree import Element

from data import FunctionInfo, ClassInfo, NamespaceInfo, EnumInfo
from bbcode import to_bbcode, get_deprecated_text


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

# Responsible for updating XML documentation
# Reference: https://docs.godotengine.org/en/latest/engine_details/class_reference/index.html#doc-class-reference-primer
from xml.etree.ElementTree import Element

from data import FunctionInfo, ClassInfo, NamespaceInfo, EnumInfo


def document_class(tree: Element, class_info: ClassInfo) -> None:
    brief_description = tree.find("brief_description")

    if class_info.short_desc and brief_description is not None:
        brief_description.text += class_info.short_desc

    description = tree.find("description")

    if class_info.long_desc and description is not None:
        description.text += class_info.long_desc


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
        description.text += f"{function_info.short_desc}\n\t\t\t"

    if function_info.long_desc:
        description.text += f"{function_info.long_desc}\n\t\t\t"


def document_enum(tree: Element, enum_info: EnumInfo) -> None:
    brief_description = tree.find("brief_description")

    if enum_info.short_desc and brief_description is not None:
        brief_description.text += enum_info.short_desc

    description = tree.find("description")

    if enum_info.long_desc and description is not None:
        description.text += enum_info.long_desc

    for ev in enum_info.values:
        c = tree.find(f"constants/constant[@name='{ev.name}']")

        if c is not None:
            if ev.short_desc:
                c.text += f"{ev.short_desc}\n\t\t"

            if ev.long_desc:
                c.text += f"{ev.long_desc}\n\t\t"

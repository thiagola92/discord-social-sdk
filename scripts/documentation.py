# Responsible for updating XML documentation
# Reference: https://docs.godotengine.org/en/latest/engine_details/class_reference/index.html#doc-class-reference-primer
from xml.etree.ElementTree import Element

from data import FunctionInfo, ClassInfo, NamespaceInfo


def document_xml(tree: Element, info: NamespaceInfo | ClassInfo) -> None:
    if isinstance(info, ClassInfo):
        document_class(tree, info)

    document_functions(tree, info)


def document_class(tree: Element, info: ClassInfo) -> None:
    brief_description = tree.find("brief_description")

    if info.short_desc and brief_description is not None:
        brief_description.text = info.short_desc

    description = tree.find("description")

    if info.long_desc and description is not None:
        description.text = info.long_desc


def document_functions(tree: Element, info: NamespaceInfo | ClassInfo) -> None:
    for f in info.functions:
        document_function(tree, f)


def document_function(tree: Element, function: FunctionInfo) -> None:
    method = tree.find(f"methods/method[@name='{function.gdscript_name}']")

    if method is None:
        return

    description = method.find("description")

    if description is None:
        return

    if function.short_desc:
        description.text += f"{function.short_desc}\n\t\t\t"

    if function.long_desc:
        description.text += f"{function.long_desc}\n\t\t\t"

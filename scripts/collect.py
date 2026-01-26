# Responsible for collecting informations about from XML tree.
from pprint import pprint
from pathlib import Path
from xml.etree import ElementTree
from xml.etree.ElementTree import Element

from name import to_gdscript_name, to_snake_case, undo_functions_overload
from data import (
    CallbackInfo,
    ClassInfo,
    EnumInfo,
    EnumValueInfo,
    FunctionInfo,
    NamespaceInfo,
    ParamInfo,
    SubtypeInfo,
    TypeInfo,
)


def collect_text(tree: Element) -> str:
    return "".join(tree.itertext()).strip()


def collect_namespace(tree: Element, xml_dir: Path) -> NamespaceInfo:
    namespace_info = NamespaceInfo()

    if n := tree.find("compound[@kind='namespace']"):
        nf = n.attrib["refid"] + ".xml"
        nf = xml_dir.joinpath(nf)
        nf = ElementTree.parse(nf)

        namespace_info.enums = collect_enums(nf)
        namespace_info.functions = collect_functions(nf)

        namespace_info.functions = undo_functions_overload(namespace_info.functions)

    for c in tree.findall("compound[@kind='class']"):
        cf = c.attrib["refid"] + ".xml"
        cf = xml_dir.joinpath(cf)
        cf = ElementTree.parse(cf)

        namespace_info.classes.append(collect_class(cf))

    return namespace_info


def collect_class(tree: Element) -> ClassInfo:
    class_info = ClassInfo()
    class_info.name = collect_text(tree.find("compounddef/compoundname"))
    class_info.name = class_info.name.removeprefix("discordpp::")
    class_info.short_desc = collect_text(tree.find("compounddef/briefdescription"))
    class_info.long_desc = collect_text(tree.find("compounddef/detaileddescription"))
    class_info.enums = collect_enums(tree)
    class_info.functions = collect_functions(tree)
    class_info.constructors = collect_constructors(class_info)
    class_info.callbacks = collect_callbacks(tree)

    class_info.functions = undo_functions_overload(class_info.functions)

    return class_info


def collect_enums(tree: Element) -> list[EnumInfo]:
    enums = []

    for e in tree.findall(".//memberdef[@kind='enum']"):
        if collect_text(e.find("name")) == "DiscordObjectState":  # Exclude.
            continue

        ei = EnumInfo()
        ei.name = collect_text(e.find("name"))
        ei.short_desc = collect_text(e.find("briefdescription"))
        ei.long_desc = collect_text(e.find("detaileddescription"))

        for ev in e.findall("enumvalue"):
            evi = EnumValueInfo()
            evi.name = collect_text(ev.find("name"))
            evi.short_desc = collect_text(ev.find("briefdescription"))
            evi.long_desc = collect_text(ev.find("detaileddescription"))

            if ev.find("initializer") is not None:
                evi.init = collect_text(ev.find("initializer")) + ","

            ei.values.append(evi)

        enums.append(ei)

    return enums


def collect_functions(tree: Element) -> list[FunctionInfo]:
    functions = []

    for f in tree.findall(".//memberdef[@kind='function']"):
        fi = FunctionInfo()
        fi.static = f.attrib.get("static") == "yes"
        fi.name = collect_text(f.find("name"))
        fi.gdscript_name = to_gdscript_name(fi.name)
        fi.type = collect_type(f)
        fi.short_desc = collect_text(f.find("briefdescription"))
        fi.long_desc = collect_text(f.find("detaileddescription"))
        fi.params = collect_params(f)

        if fi.name.startswith("operator"):  # Exclude.
            continue

        functions.append(fi)

    return functions


def collect_constructors(class_info: ClassInfo) -> list[FunctionInfo]:
    constructors = []

    for f in class_info.functions:
        if f.name == class_info.name:
            constructors.append(f)

    for c in constructors:
        class_info.functions.remove(c)

    return constructors


def collect_callbacks(tree: Element) -> list[CallbackInfo]:
    callbacks = []

    for t in tree.findall(".//memberdef[@kind='typedef']"):
        c = CallbackInfo()
        c.name = collect_text(t.find("name"))
        c.params = collect_type(t)
        c.short_desc = collect_text(t.find("briefdescription"))
        c.long_desc = collect_text(t.find("detaileddescription"))

        callbacks.append(c)

    for c in callbacks:
        pprint(c)

    return callbacks


def collect_params(tree: Element) -> list[ParamInfo]:
    params = []

    for p in tree.findall("param"):
        pi = ParamInfo()
        pi.type = collect_type(p)

        if p.find("declname") is not None:
            pi.name = collect_text(p.find("declname"))
            pi.gdscript_name = to_snake_case(pi.name)

        params.append(pi)

    return params


def collect_type(tree: Element) -> TypeInfo:
    type_str = collect_text(tree.find("type"))
    type_info = collect_subtype(type_str)

    return type_info


# def collect_subtype(type_str: str) -> tuple[str, list[SubtypeInfo], str]:
#     """
#     Good enough solution for collecting subtypes recursively.

#     Returns a tuple with 3 values:
#     - Parent type string.
#     - List of subtypes.
#     - Anything extra after the type.

#     There is 4 possible paths:
#     - When is dealing with a single type:
#         - Input: `bool`
#         - Output: `('bool', [], '')`
#     - When is dealing with a type that has subtype:
#         - Input: `std::optional<discordpp::LobbyHandle>`
#         - Output: `('std::optional', [TypeInfo(name='discordpp::LobbyHandle')], '')`
#         - Input: `std::unordered_map<std::string, std::string> const &`
#         - Output: `('std::unordered_map', [TypeInfo(name='std::string'), TypeInfo(name='std::string')], 'const &')`
#     - When is processing consecutives subtypes:
#         - Input: `std::string, std::string`
#         - Output: `('', [TypeInfo(name='std::string'), TypeInfo(name='std::string')], '')`
#     - When is processing functions signature:
#         - Input: `void(int result, int user)`
#         - Output: `('void', [TypeInfo(name='int result'), TypeInfo(name='int user')], '')`
#     """

#     for i, c in enumerate(type_str):
#         if c == "<":
#             l, _, r = type_str.partition("<")
#             m, _, e = r.partition(">")
#             t = TypeInfo()
#             t.name, t.subtype, t.extra = collect_subtype(m)

#             return (l, [t], e)
#         elif c == ",":
#             l, _, r = type_str.partition(",")
#             t1 = TypeInfo()
#             t2 = TypeInfo()
#             t1.name, t1.subtype, t1.extra = collect_subtype(l)
#             t2.name, t2.subtype, t2.extra = collect_subtype(r)
#             st = [t1]

#             if t2.name == "":
#                 st.extend(t2.subtype)
#             else:
#                 st.append(t2)

#             return ("", st, "")
#         elif c == "(":
#             l, _, r = type_str.partition("(")
#             m, _, e = r.partition(")")
#             t = TypeInfo()
#             t.name, t.subtype, t.extra = collect_subtype(m)

#             return (l, [t], e)

#     return (type_str, [], "")


def collect_subtype(type_str: str) -> TypeInfo:
    """
    Parses a string to obtain a type.

    It assumes that we will never have brackets that mix with each other:
        (<)>
        <(>)

    """
    if type_str == "":
        return ("", [], "")

    current_position = 0
    brackets_position = []
    type_info = TypeInfo()

    while current_position < len(type_str):
        c: str = type_str[current_position]

        if c == "<" or c == "(":
            brackets_position.append(current_position)
        elif c == ">" or c == ")":
            start_position = brackets_position.pop() + 1
            subtype_str = type_str[start_position:current_position]
            subtype_str = subtype_str.strip()
            subtype_info = collect_subtype(subtype_str)

            type_info.subtype.append(subtype_info)
        elif c == ",":
            start_position = brackets_position.pop() + 1
            subtype_str = type_str[start_position:current_position]
            subtype_str = subtype_str.strip()
            subtype_info = collect_subtype(subtype_str)

            type_info.subtype.append(subtype_info)
            brackets_position.append(current_position)
        elif any(brackets_position):
            # Do nothing inside brackets.
            pass
        elif any(type_info.subtype):
            # Send to extra if already processed the main type.
            type_info.extra += c
        else:
            # Put together the main type.
            type_info.name += c

        current_position += 1

    type_info.name = type_info.name.strip()
    type_info.extra = type_info.extra.strip()
    return type_info

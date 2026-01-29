# Responsible for collecting informations about from XML tree.
from pathlib import Path
from xml.etree import ElementTree
from xml.etree.ElementTree import Element

from check import check_overloading, check_callbacks
from name import to_gdscript_var_name, to_snake_case
from parse import Parser
from data import (
    CallbackInfo,
    ClassInfo,
    EnumInfo,
    EnumValueInfo,
    FunctionInfo,
    NamespaceInfo,
    ParamInfo,
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

        check_overloading(namespace_info.functions)

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

    check_overloading(class_info.functions)
    check_callbacks(class_info)

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
        fi.gdscript_name = to_gdscript_var_name(fi.name)
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


def collect_type(tree: Element) -> TypeInfo | FunctionInfo:
    type_str = collect_text(tree.find("type"))
    type_info = Parser(type_str).parse_type()

    return type_info

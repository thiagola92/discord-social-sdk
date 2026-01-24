# Responsible for collecting informations about from XML tree.
from pathlib import Path
from dataclasses import dataclass, field
from xml.etree import ElementTree
from xml.etree.ElementTree import Element


type SubtypeInfo = TypeInfo


@dataclass
class EnumValueInfo:
    name: str = ""
    short_desc: str = ""
    long_desc: str = ""
    init: str = ","


@dataclass
class EnumInfo:
    name: str = ""
    short_desc: str = ""
    long_desc: str = ""
    values: list[EnumValueInfo] = field(default_factory=list)


@dataclass
class TypeInfo:
    name: str = ""
    subtype: list[SubtypeInfo] = field(default_factory=list)
    extra: str = ""


@dataclass
class ParamInfo:
    name: str = ""
    type: TypeInfo = field(default_factory=TypeInfo)


@dataclass
class FunctionInfo:
    name: str = ""
    type: TypeInfo = field(default_factory=TypeInfo)
    short_desc: str = ""
    long_desc: str = ""
    params: list[ParamInfo] = field(default_factory=list)


@dataclass
class ClassInfo:
    name: str = ""
    short_desc: str = ""
    long_desc: str = ""
    enums: list[EnumInfo] = field(default_factory=list)
    functions: list[FunctionInfo] = field(default_factory=list)
    constructors: list[FunctionInfo] = field(default_factory=list)


@dataclass
class NamespaceInfo:
    classes: list[ClassInfo] = field(default_factory=list)
    enums: list[EnumInfo] = field(default_factory=list)


def collect_namespace(tree: Element, xml_dir: Path) -> NamespaceInfo:
    namespace_info = NamespaceInfo()

    if n := tree.find("compound[@kind='namespace']"):
        nf = n.attrib["refid"] + ".xml"
        nf = xml_dir.joinpath(nf)
        nf = ElementTree.parse(nf)

        namespace_info.enums = collect_enums(nf)

    for c in tree.findall("compound[@kind='class']"):
        cf = c.attrib["refid"] + ".xml"
        cf = xml_dir.joinpath(cf)
        cf = ElementTree.parse(cf)

        namespace_info.classes.append(collect_class(cf))

    return namespace_info


def collect_class(tree: Element) -> ClassInfo:
    class_info = ClassInfo()
    class_info.name = tree.find("compounddef/compoundname").text
    class_info.name = class_info.name.removeprefix("discordpp::")
    class_info.short_desc = tree.find("compounddef/briefdescription").text
    class_info.long_desc = tree.find("compounddef/detaileddescription").text
    class_info.enums = collect_enums(tree)
    class_info.functions = collect_functions(tree)
    class_info.constructors = collect_constructors(class_info)

    return class_info


def collect_enums(tree: Element) -> list[EnumInfo]:
    enums = []

    for e in tree.findall(".//memberdef[@kind='enum']"):
        if e.find("name").text == "DiscordObjectState":  # Exclude.
            continue

        ei = EnumInfo()
        ei.name = e.find("name").text
        ei.short_desc = "".join(e.find("briefdescription").itertext())
        ei.long_desc = "".join(e.find("detaileddescription").itertext())

        for ev in e.findall("enumvalue"):
            evi = EnumValueInfo()
            evi.name = ev.find("name").text
            evi.short_desc = "".join(ev.find("briefdescription").itertext())
            evi.long_desc = "".join(ev.find("detaileddescription").itertext())

            if ev.find("initializer") is not None:
                evi.init = ev.find("initializer").text + ","

            ei.values.append(evi)

        enums.append(ei)

    return enums


def collect_functions(tree: Element) -> list[FunctionInfo]:
    functions = []

    for f in tree.findall(".//memberdef[@kind='function']"):
        fi = FunctionInfo()
        fi.name = f.find("name").text
        fi.type = collect_type(f)
        fi.short_desc = f.find("briefdescription").text
        fi.long_desc = f.find("detaileddescription").text
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


def collect_params(tree: Element) -> list[ParamInfo]:
    params = []

    for p in tree.findall("param"):
        pi = ParamInfo()
        pi.type = collect_type(p)

        if p.find("declname") is not None:
            pi.name = p.find("declname").text

        params.append(pi)

    return params


def collect_type(tree: Element) -> TypeInfo:
    type_info = TypeInfo()
    type_info.name = "".join(tree.find("type").itertext())
    type_info.name, type_info.subtype, type_info.extra = collect_subtype(type_info.name)

    return type_info


def collect_subtype(type_str: str) -> tuple[str, list[SubtypeInfo], str]:
    """
    Good enough solution for collecting subtypes recursively.

    Returns a tuple with 3 values:
    - Parent type string.
    - List of subtypes.
    - Anything extra after the type.

    There is 3 possible returns:
    - When is dealing with a single type:
        - Input: `bool`
        - Output: `('bool', [], '')`
    - When is dealing with a type that has subtype:
        - Input: `std::optional<discordpp::LobbyHandle>`
        - Output: `('std::optional', [TypeInfo(name='discordpp::LobbyHandle')], '')`
        - Input: `std::unordered_map<std::string, std::string> const &`
        - Output: `('std::unordered_map', [TypeInfo(name='std::string'), TypeInfo(name='std::string')], 'const &')`
    - When is processing consecutives subtypes:
        - Input: `std::string, std::string`
        - Output: `('', [TypeInfo(name='std::string'), TypeInfo(name='std::string')], '')`
    """

    for c in type_str:
        if c == "<":
            l, _, r = type_str.partition("<")
            m, _, e = r.rpartition(">")
            t = TypeInfo()
            t.name, t.subtype, t.extra = collect_subtype(m)

            return (l, [t], e)
        elif c == ",":
            l, _, r = type_str.partition(",")
            t1 = TypeInfo()
            t2 = TypeInfo()
            t1.name, t1.subtype, t1.extra = collect_subtype(l)
            t2.name, t2.subtype, t2.extra = collect_subtype(r)
            st = [t1]

            if t2.name == "":
                st.extend(t2.subtype)
            else:
                st.append(t2)

            return ("", st, "")

    return (type_str, [], "")

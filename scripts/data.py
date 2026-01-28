# Responsible for holding the structures to be used.
from dataclasses import dataclass, field

# Allow recursion.
type TypeInfoR = TypeInfo
type FunctionInfoR = FunctionInfo


@dataclass
class EnumValueInfo:
    name: str = ""
    init: str = ","

    # Documentation.
    short_desc: str = ""
    long_desc: str = ""


@dataclass
class EnumInfo:
    name: str = ""
    values: list[EnumValueInfo] = field(default_factory=list)

    # Documentation.
    short_desc: str = ""
    long_desc: str = ""


@dataclass
class TypeInfo:
    name: str = ""
    templates: list[TypeInfoR | FunctionInfoR] = field(default_factory=list)
    extra: str = ""  # TODO: Replace for useful fields.


@dataclass
class ParamInfo:
    type: TypeInfo | FunctionInfoR = field(default_factory=TypeInfo)
    name: str = ""

    # GDScript.
    gdscript_name: str = ""


@dataclass
class FunctionInfo:
    static: bool = False
    overloading: bool = False
    type: TypeInfo = field(default_factory=TypeInfo)
    name: str = ""
    templates: list[TypeInfoR | FunctionInfoR] = field(default_factory=list)
    params: list[ParamInfo] = field(default_factory=list)

    # Documentation.
    short_desc: str = ""
    long_desc: str = ""

    # GDScript
    gdscript_name: str = ""


@dataclass
class CallbackInfo:
    name: str = ""
    params: list[ParamInfo] = field(default_factory=list)

    # Documentation.
    short_desc: str = ""
    long_desc: str = ""


@dataclass
class ClassInfo:
    name: str = ""
    enums: list[EnumInfo] = field(default_factory=list)
    functions: list[FunctionInfo] = field(default_factory=list)
    constructors: list[FunctionInfo] = field(default_factory=list)
    callbacks: list[CallbackInfo] = field(default_factory=list)

    # Documentation.
    short_desc: str = ""
    long_desc: str = ""


@dataclass
class NamespaceInfo:
    classes: list[ClassInfo] = field(default_factory=list)
    enums: list[EnumInfo] = field(default_factory=list)
    functions: list[FunctionInfo] = field(default_factory=list)
    constructors: list[FunctionInfo] = field(default_factory=list)
    callbacks: list[CallbackInfo] = field(default_factory=list)

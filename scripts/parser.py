from classes import CLASSES


class VarType:
    name: str = ""
    is_opt: bool = False
    is_discord: bool = False
    is_enum: bool = False
    is_callback: bool = False


class Param:
    name: str = ""
    type: VarType


class Method:
    ret: VarType
    name: str = ""
    params: list[Param]
    uncallables: list[Param]
    callables: list[Param]
    use_enum: bool = False
    is_setter: bool = False
    maybe_getter: bool = False


def parse_typing(text: str) -> VarType:
    """Attempt to parse cases like:

    - std::optional<discordpp::EnumName>
    - std::optional<TYPE>
    - discordpp::EnumName
    - TYPE
    """
    var_type = VarType()

    text = text.strip()

    if text.startswith("std::optional<"):
        var_type.is_opt = True

        text = text.removeprefix("std::optional<")
        text = text.removesuffix(">")
        text = text.strip()

    if text.startswith("discordpp::"):
        var_type.is_discord = True

        text = text.removeprefix("discordpp::")
        text = text.strip()

        if text.endswith("Callback"):
            var_type.is_callback = True
        else:
            var_type.is_enum = text not in CLASSES.keys()

    var_type.name = text

    return var_type


def parse_param(text: str) -> Param:
    """Attempt to parse a parameter"""
    param = Param()

    typing, _, name = text.rpartition(" ")

    param.name = name
    param.type = parse_typing(typing)

    return param


def parse_params(text: str) -> list[Param]:
    """Attempt to parse parameters"""

    text, _, _ = text.rpartition(")")
    text = text.split(",")
    text = [t.strip() for t in text]
    text = [t for t in text if len(t) > 0]

    return [parse_param(t) for t in text]


def parse_signature(text: str) -> Method:
    """Attempt to parse Get and Set methods"""
    method = Method()

    text, _, params = text.partition("(")
    text = text.strip()
    ret, _, name = text.rpartition(" ")
    name = name.strip()

    method.name = name
    method.ret = parse_typing(ret)
    method.params = parse_params(params)
    method.uncallables = [p for p in method.params if not p.type.is_callback]
    method.callables = [p for p in method.params if p.type.is_callback]
    method.use_enum = any([p for p in method.params if p.type.is_enum])

    if len(name) > 3 and name[3].isupper() and name.startswith("Set"):
        method.is_setter = True
    elif method.ret.name != "void" and len(method.params) == 0:
        method.maybe_getter = True

    return method

from extractor import get_classes


class VarType:
    name: str = ""

    # Complex (best order to solve problems)
    is_opt: bool = False
    is_vector: bool = False
    is_map: bool = False
    is_enum: bool = False
    is_callback: bool = False
    is_discord: bool = False

    # Simple (best order to solve problems)
    is_boolean: bool = False
    is_number: bool = False
    is_integer: bool = False
    is_float: bool = False
    is_string: bool = False


class Param:
    name: str = ""
    var: str = ""
    type: VarType


class Method:
    ret: VarType
    name: str = ""
    params: list[Param] = []
    uncallables: list[Param] = []
    callables: list[Param] = []
    use_enum: bool = False


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
        text, _, _ = text.rpartition(">")
        text = text.strip()

    if text.startswith("std::vector<"):
        var_type.is_vector = True

        text = text.removeprefix("std::vector<")
        text, _, _ = text.rpartition(">")
        text = text.strip()

    if text.startswith("std::unordered_map<"):
        var_type.is_map = True

        text = text.removeprefix("std::unordered_map<")
        text, _, _ = text.rpartition(">")
        text = text.strip()

    if text.startswith("discordpp::"):
        var_type.is_discord = True

        text = text.removeprefix("discordpp::")
        text = text.strip()

        if text.endswith("Callback"):
            var_type.is_callback = True
        else:
            var_type.is_enum = text not in get_classes().keys()

    if text in ["uint8_t", "int64_t", "uint64_t", "int32_t", "uint32_t"]:
        var_type.is_integer = True
        var_type.is_number = True

    if text in ["float"]:
        var_type.is_float = True
        var_type.is_number = True

    if text in ["std::string", "std::string const"]:
        var_type.is_string = True

    if text in ["bool"]:
        var_type.is_boolean = True

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
    start = 0
    texts = []
    inside_generic = 0

    for index, c in enumerate(text):
        if c == "<":
            inside_generic += 1
        elif c == ">":
            inside_generic -= 1
        elif c == "," and inside_generic == 0:
            texts.append(text[start:index])
            start = index + 1

    texts.append(text[start:])

    texts = [t.strip() for t in texts]
    texts = [t for t in texts if len(t) > 0]

    return [parse_param(t) for t in texts]


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
    method.use_enum = (
        any([p for p in method.params if p.type.is_enum]) or method.ret.is_enum
    )

    return method

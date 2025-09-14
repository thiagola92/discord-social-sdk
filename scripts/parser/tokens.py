type TokenSubType = TokenType  # Allows me use recursive typing


class TokenEnum:
    """Used to represent enums"""

    name: str
    options: dict[str, int]

    def __init__(self, name: str, options: dict[str, int]):
        self.name = name
        self.options = options

    def __str__(self):
        options = "\n    ".join([f"{k}: {v}," for k, v in self.options.items()])

        return f"""
enum {self.name} {{
    {options}
}}
"""


class TokenType:
    """
    Used to represent types, for example:
    - Return type
    - Parameter type
    - Variable type
    """

    name: str
    subtype: TokenSubType | None

    def __init__(self, name: str, subtype: TokenSubType | None):
        self.name = name
        self.subtype = subtype

    def __str__(self):
        if self.subtype is None:
            subtype = ""
        else:
            subtype = f"<{str(self.subtype)}>"

        return f"{self.name}{subtype}"


class TokenParam:
    """
    Used to represent parameters.

    It's basically like TokenType but
    it carries the variable name together.
    """

    type: TokenType
    name: str

    def __init__(self, type: TokenType, name: str):
        self.type = type
        self.name = name

    def __str__(self):
        return f"{str(self.type)} {self.name}"


class TokenCallback:
    """Used to represent a callback function."""

    name: str
    params: list[TokenParam]

    def __init__(self, name: str, params: list[TokenParam]):
        self.name = name
        self.params = params

    def __str__(self):
        params = ", ".join([str(p) for p in self.params])
        return f"callback {self.name}({params})"


class TokenConstructor:
    """
    Used to represent a constructor. Following the pattern:
        CLASSNAME(PARAM, ...)
        CLASSNAME(PARAM, ...) = delete
        explicit CLASSNAME()

    For us is important to know if the class has an empty
    constructor or if disallow copying the object.
    """

    params: list[TokenParam]
    deleted: bool

    def __init__(self, params: list[TokenParam], deleted: bool):
        self.params = params
        self.deleted = deleted

    def __str__(self):
        params = ", ".join([str(p) for p in self.params])
        deleted = "deleted" if self.deleted else ""
        return f"constructor ({params}) {deleted}"


class TokenFunction:
    """
    Used to represent a function. Following the pattern:
        TYPE NAME(PARAM, ...)

    Function content it's not important to us.
    """

    ret: TokenType
    name: str
    params: list[TokenParam]
    static: bool = False

    def __init__(
        self,
        ret: TokenType,
        name: str,
        params: list[TokenParam],
        static: bool,
    ):
        self.ret = ret
        self.name = name
        self.params = params
        self.static = static

    def __str__(self):
        params = ", ".join([str(p) for p in self.params])
        modifier = "static " if self.static else ""
        return f"{modifier}func {self.name}({params}) -> {str(self.ret)}"


class TokenClass:
    """Used to represent a class."""

    name: str
    enums: list[TokenEnum]
    callbacks: list[TokenCallback]
    constructors: list[TokenConstructor]
    functions: list[TokenFunction]

    def __init__(
        self,
        name: str,
        enums: list[TokenEnum],
        callbacks: list[TokenCallback],
        constructors: list[TokenConstructor],
        functions: list[TokenFunction],
    ):
        self.name = name
        self.enums = enums
        self.callbacks = callbacks
        self.constructors = constructors
        self.functions = functions

    def __str__(self):
        enums = "".join([str(e) for e in self.enums])
        callbacks = "\n".join([str(c) for c in self.callbacks])
        constructors = "\n".join([str(c) for c in self.constructors])
        functions = "\n".join([str(f) for f in self.functions])

        return f"""
class {self.name} {{
{enums}
-----
{callbacks}
-----
{constructors}
-----
{functions}
}}
"""


class TokenDocstring:
    """Used to represent a docstring."""

    text: str

    def __init__(self, text: str):
        self.text = text

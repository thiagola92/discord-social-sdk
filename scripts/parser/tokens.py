type TokenSubType = TokenType  # Allows me to use recursive typing
type TokenDocs = TokenDocstring


class TokenEnum:
    """Used to represent enums"""

    docs: TokenDocs
    name: str
    options: dict[str, int]
    options_docs: dict[str, TokenDocs]

    def __init__(
        self,
        docs: TokenDocs,
        name: str,
        options_docs: dict[str, TokenDocs],
        options: dict[str, int],
    ):
        self.docs = docs
        self.name = name
        self.options_docs = options_docs
        self.options = options

    def __str__(self):
        options = []

        for k, v in self.options.items():
            d = self.options_docs.get(k, "")
            options.append(d.indented("    "))
            options.append(f"    {k}: {v},")

        options = "\n".join(options)

        return f"""{self.docs}
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
        type = str(self.type)

        return f"{type} {self.name}"


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

    docs: TokenDocs
    ret: TokenType
    name: str
    params: list[TokenParam]
    static: bool = False

    def __init__(
        self,
        docs: TokenDocs,
        ret: TokenType,
        name: str,
        params: list[TokenParam],
        static: bool,
    ):
        self.docs = docs
        self.ret = ret
        self.name = name
        self.params = params
        self.static = static

    def __str__(self):
        docs = str(self.docs)
        params = ", ".join([str(p) for p in self.params])
        modifier = "static " if self.static else ""
        ret = str(self.ret)

        return f"""{docs}
{modifier}func {self.name}({params}) -> {ret}
"""


class TokenClass:
    """Used to represent a class."""

    docs: TokenDocs
    name: str
    enums: list[TokenEnum]
    callbacks: list[TokenCallback]
    constructors: list[TokenConstructor]
    functions: list[TokenFunction]

    def __init__(
        self,
        docs: TokenDocs,
        name: str,
        enums: list[TokenEnum],
        callbacks: list[TokenCallback],
        constructors: list[TokenConstructor],
        functions: list[TokenFunction],
    ):
        self.docs = docs
        self.name = name
        self.enums = enums
        self.callbacks = callbacks
        self.constructors = constructors
        self.functions = functions

    def __str__(self):
        docs = str(self.docs)
        enums = "".join([str(e) for e in self.enums])
        callbacks = "\n".join([str(c) for c in self.callbacks])
        constructors = "\n".join([str(c) for c in self.constructors])
        functions = "\n".join([str(f) for f in self.functions])

        return f"""
{docs}
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
    """
    Used to represent a docstring.

    Which could be one or more lines,
    each starting with "///" and ending with newline.
    """

    lines: list[str]

    def __init__(self, lines: list[str]):
        self.lines = lines

    def indented(self, prefix: str) -> str:
        """
        Utility to prettify the temporary file.
        Because docstrings can be in any indentation of the code.
        """
        return prefix + str(self).replace("\n", f"\n{prefix}")

    def __str__(self) -> str:
        docs = "\n///".join(self.lines)

        return f"""///{docs}"""

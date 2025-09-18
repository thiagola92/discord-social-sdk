import re

from builder.translator import Translator
from parser.tokens import TokenType, TokenDocstring


class DocTranslator(Translator):
    def __init__(self, tokens: list):
        self.tokens = tokens

    def c_type_to_gdscript_type(self, token: TokenType) -> str:
        """
        Return the GDScript type that would be equivalent to this C type.

        Same as c_type_to_godot_type() but instead of returning
        the C type used in GDExtensions, returns the GDScript type
        used in GDScript code.
        """

        if self.is_c_void(token.name):
            return "void"

        elif self.is_c_bool(token.name):
            return "bool"

        elif self.is_c_int(token.name):
            return "int"

        elif self.is_c_float(token.name):
            return "float"

        elif self.is_c_string(token.name):
            return "String"

        elif self.is_c_char_array(token.name):
            return "String"

        elif self.is_c_opt(token.name):
            return "Variant"

        elif self.is_c_vec(token.name):
            subtype = self.c_type_to_godot_type(token.subtype, False)
            return f"Array[{subtype}]"

        elif self.is_c_map(token.name):
            subtype = self.c_type_to_godot_type(token.subtype, False)
            return f"Dictionary[{subtype}]"

        elif self.is_c_callback(token.name):
            return "Callable"

        elif self.is_c_enum(token.name):
            return self.c_name_to_godot_name(token.name).replace("::", ".")

        elif self.is_c_discord(token.name):
            return self.c_name_to_godot_name(token.name)

        elif self.is_c_many(token.name):
            # NOTE: This is a "gambiarra" because I know that
            # this will only be trigger by "std::string, std::string"
            types = token.name.split(",")
            types = [t.strip() for t in types]
            types = [TokenType(name=t, subtype=None) for t in types]
            types = [self.c_type_to_godot_type(t) for t in types]
            types = ", ".join(types)
            return types

        assert False, f'Fail to convert from "{token.name}" to GDScript type'

    def c_type_to_bbcode(self, token: TokenType) -> str:
        if self.is_c_void(token.name):
            return "[code]void[/code]"

        elif self.is_c_bool(token.name):
            return "[bool]"

        elif self.is_c_int(token.name):
            return "[int]"

        elif self.is_c_float(token.name):
            return "[float]"

        elif self.is_c_string(token.name):
            return "[String]"

        elif self.is_c_char_array(token.name):
            return "[String]"

        elif self.is_c_opt(token.name):
            return "[Variant]"

        elif self.is_c_vec(token.name):
            subtype = self.c_type_to_bbcode(token.subtype)
            return f"[Array][lb]{subtype}[rb]"

        elif self.is_c_map(token.name):
            subtype = self.c_type_to_bbcode(token.subtype)
            return f"[Dictionary][lb]{subtype}[rb]"

        elif self.is_c_callback(token.name):
            return "[Callable]"

        elif self.is_c_enum(token.name):
            name = self.c_name_to_godot_name(token.name).replace("::", ".")
            return f"[enum {name}]"

        elif self.is_c_discord(token.name):
            name = self.c_name_to_godot_name(token.name)
            return f"[{name}]"

        assert False, f'Fail to convert from "{token.name}" to BBCode'

    def c_doc_to_gdscript_doc(
        self,
        token: TokenDocstring,
        tokens: list,
        indentation: str,
    ) -> str:
        lines: list[str] = token.lines.copy()

        # for l in lines:
        #     print(l)

        # Change headers to bold text.
        for n in range(len(lines) - 1, -1, -1):
            if re.search(r"(\s*)(#+ .*)", lines[n]):
                lines[n] = re.sub(r"(\s*)(#+ .*)", r"\1[b]\2[/b]", lines[n])
                lines.insert(n + 1, "")
                lines.insert(n, "")

        # Change codeblocks.
        inside_codeblock = False

        for n in range(len(lines) - 1, -1, -1):
            if "\\code" in lines[n]:
                lines[n] = lines[n].replace("\\code", "[codeblock lang=csharp]")
                lines.insert(n, "")
                inside_codeblock = False

            if "\\endcode" in lines[n]:
                lines[n] = lines[n].replace("\\endcode", "[/codeblock]")
                inside_codeblock = True  # Remember: we are going backwards.

            if inside_codeblock:
                lines.insert(n, "")

        # Change unordered list.
        for n in range(len(lines) - 1, -1, -1):
            if re.search("^- ", lines[n]):
                lines[n] = "[br]" + lines[n]

        # Change ordered list.
        for n in range(len(lines) - 1, -1, -1):
            if re.search(r"^\d+. ", lines[n]):
                lines[n] = "[br]" + lines[n]

        # TODO: Link references.
        # references: list[str] = []

        # for n, line in enumerate(lines):
        #     references.extend(re.findall(r"(\w*::\w*)", line))

        # Join Lines.
        # Multiple lines of a docstring could be a single paragraph in the documentation.
        # We can only be sure if we find an empty line between them.
        docstring = ""
        newline = False

        for line in lines:
            if newline:
                docstring += f"\n{indentation}" + line
                newline = False
            else:
                docstring += " " + line

            if line.strip() == "":
                newline = True

        return docstring.strip()

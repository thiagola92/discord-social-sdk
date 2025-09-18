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
        """
        The plan is reusing the docstring from C code.

        This is mostly regex substitution and it's a temporary
        way to solve it.

        NOTE:
            - If you just want it to go to the next line, add bbcode [br]
            - If you want to end a paragraph, add an empty new line
                - lines.insert(n, "")
        """
        lines: list[str] = token.lines.copy()
        inside_codeblock = False

        # Patterns.
        BRIEF_PATTERN = r"^ \\brief"
        HEADER_PATTERN = r"^ (#+ .*)"
        CODE_PATTERN = r"^ \\code"
        ENDCODE_PATTERN = r"^ \\endcode"
        UL_PATTERN = r"^ (- )"
        OL_PATTERN = r"^ (\d+. )"
        IMG_PATTERN = r"^ \\image .*\"([^ ]+)\".*"

        for n in range(len(lines) - 1, -1, -1):
            # Change codeblocks.
            if re.search(CODE_PATTERN, lines[n]):
                lines[n] = re.sub(CODE_PATTERN, r" [codeblock lang=text]", lines[n])
                lines.insert(n + 1, "")
                inside_codeblock = False

                # Add warning.
                lines.insert(n, "")
                lines.insert(
                    n,
                    " [color=orange]WARNING:[/color] The following example is in C++.",
                )
                lines.insert(n, "")

            if inside_codeblock:
                lines.insert(n + 1, "")
                continue  # Stop replacing when inside codeblocks.

            if re.search(ENDCODE_PATTERN, lines[n]):
                lines[n] = re.sub(ENDCODE_PATTERN, r" [/codeblock]", lines[n])
                inside_codeblock = True  # Remember: we are walking backwards.

            # Change brief.
            if re.search(BRIEF_PATTERN, lines[n]):
                lines[n] = re.sub(BRIEF_PATTERN, r"", lines[n])

            # Change image.
            if re.search(IMG_PATTERN, lines[n]):
                lines[n] = re.sub(
                    IMG_PATTERN,
                    r"[url]https://discord.com/developers/docs/social-sdk/\1[/url]",
                    lines[n],
                )

            # Change headers to bold text.
            if re.search(HEADER_PATTERN, lines[n]):
                lines[n] = re.sub(HEADER_PATTERN, r" [b]\1[/b]", lines[n])
                lines.insert(n + 1, "")
                lines.insert(n, "")

            # Change unordered list.
            if re.search(UL_PATTERN, lines[n]):
                lines[n] = re.sub(UL_PATTERN, r" [br]\1", lines[n])

            # Change ordered list.
            if re.search(OL_PATTERN, lines[n]):
                lines[n] = re.sub(OL_PATTERN, r" [br]\1", lines[n])

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
                docstring += line

            if line.strip() == "":
                newline = True

        return docstring

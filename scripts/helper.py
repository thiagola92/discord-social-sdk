from pathlib import Path
import subprocess


def to_snake_case(string: str) -> str:
    """Convert string to snake_case."""

    new_string = ""
    can_add_underscore = False

    for c in string:
        if c.islower():
            new_string += c
            can_add_underscore = True
        elif c.isupper():
            if can_add_underscore:
                new_string += "_"
                can_add_underscore = False
            new_string += c.lower()

    return new_string


def clang_format(filepath: str) -> None:
    """
    Format file.

    Requires:
        - clang-format installed
        - ".clang-format" file at the root of project
    """

    process = subprocess.run(
        ["clang-format", "--style=file:.clang-format", filepath], capture_output=True
    )

    assert process.returncode == 0

    Path(filepath).write_bytes(process.stdout)

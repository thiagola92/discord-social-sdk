# Functions to execute CLI tools.
import os
import subprocess
from pathlib import Path

CLANG_FORMAT = os.environ.get("CLANG", "clang-format")
DOXYGEN = os.environ.get("DOXYGEN", "doxygen")
GODOT = os.environ.get("GODOT", "godot")


def clang_format(filepath: Path) -> None:
    """
    Format C++ files.

    Requires:
        - clang-format installed
        - ".clang-format" file at the root of project
    """

    process = subprocess.run(
        [CLANG_FORMAT, "--style=file:.clang-format", filepath],
        capture_output=True,
    )

    assert process.returncode == 0

    Path(filepath).write_bytes(process.stdout)


def doxygen() -> None:
    """
    Parse C++ files and generate XML files.

    Requires:
        - doxygen installed
    """

    process = subprocess.run(
        [DOXYGEN, "Doxyfile"],
        capture_output=True,
    )

    assert process.returncode == 0


def doctool() -> None:
    """
    Generate Godot XML documentation.

    Requires:
        - godot at the environment path
    """

    process = subprocess.run(
        [GODOT, "./demo/project.godot", "--doctool", "../", "--gdextension-docs"],
        capture_output=True,
    )

    assert process.returncode == 0

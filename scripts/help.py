# Utility functions that doesn't fit into other categories.
import subprocess
from pathlib import Path


def clear_dir(dir: str | Path) -> None:
    """Clean directory and subdirectories."""

    if isinstance(dir, str):
        dir = Path(dir)

    for file in dir.iterdir():
        if file.is_dir():
            clear_dir(file)
        else:
            file.unlink()


def clang_format(filepath: str) -> None:
    """
    Format C++ files.

    Requires:
        - clang-format installed
        - ".clang-format" file at the root of project
    """

    process = subprocess.run(
        ["clang-format", "--style=file:.clang-format", filepath],
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
        ["doxygen", "Doxyfile"],
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
        ["godot", "./demo/project.godot", "--doctool", "../", "--gdextension-docs"],
        capture_output=True,
    )

    assert process.returncode == 0

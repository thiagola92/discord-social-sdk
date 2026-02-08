# Utility functions that doesn't fit into other categories.
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

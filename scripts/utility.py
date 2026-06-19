# Utility functions that doesn't fit into other categories.
from pathlib import Path


def clean_dir(dir: Path) -> None:
    """Clean directory and subdirectories."""
    dir.mkdir(exist_ok=True)

    for file in dir.iterdir():
        if file.is_dir():
            clean_dir(file)
        else:
            file.unlink()

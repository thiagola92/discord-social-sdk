def clean_content(content: str) -> str:
    """
    Go through content, removing anything that is
    not useful for our parser.

    It's not a necessary step, but helps to have a clear visualization.
    """

    new_content = []

    # For rare cases where you need to skip multiple lines.
    skip_next = 0

    # A Docstring is only useful if the next code is not excluded,
    # so we will store temporarly while we don't know.
    docstring = []

    for line in content.split("\n"):
        temp = line.strip()

        if skip_next:
            skip_next -= 1
            continue

        # We don't need anything after finding this,
        # because everything after is function implementation.
        if temp.startswith("} // namespace discordpp"):
            break

        # Remove docstrings that doesn't have use in GDScript.
        if temp.startswith("/// \\cond"):
            continue

        if temp.startswith("/// \\endcond"):
            continue

        if temp.startswith("/// @name"):
            continue

        if temp.startswith("/// @}"):
            continue

        if temp.startswith("/// @{"):
            continue

        # Stack docstring.
        if temp.startswith("/// "):
            docstring.append(line)
            continue

        # Empty lines are added together with docstrings
        # to not break appearance (and discarded if docstring is not useful too).
        if len(line) == 0:
            docstring.append(line)
            continue

        # Remove comments ("if" above prevent from deleting docstrings).
        # TODO: Remove this because never happens?
        if temp.startswith("//"):
            continue

        # Remove macros.
        if temp.startswith("#include"):
            docstring.clear()
            continue

        if temp.startswith("#define"):
            docstring.clear()
            continue

        if temp.startswith("#ifndef"):
            docstring.clear()
            continue

        if temp.startswith("#ifdef"):
            docstring.clear()
            continue

        if temp.startswith("#endif"):
            docstring.clear()
            continue

        if temp.startswith("#undef"):
            docstring.clear()
            continue

        if temp.startswith("#pragma"):
            docstring.clear()
            continue

        # Everything is on discordpp namespace, so we don't need this.
        if temp.startswith("namespace discordpp {"):
            docstring.clear()
            continue

        # No need for class declarations, we can deduce this later.
        if temp.startswith("class ") and temp.endswith(";"):
            docstring.clear()
            continue

        # Remove multiple informations from class that we don't need.
        # Luckly most of them are one line.
        if temp.startswith("mutable"):
            docstring.clear()
            continue

        if "state_ = " in temp:
            docstring.clear()
            continue

        if temp.startswith("public:"):
            docstring.clear()
            continue

        if "*instance()" in temp:
            docstring.clear()
            continue

        if "instance," in temp and temp.endswith(";"):
            docstring.clear()
            continue

        if "instance," in temp and not temp.endswith(";"):
            skip_next += 1
            docstring.clear()
            continue

        if temp.startswith("~"):
            docstring.clear()
            continue

        if temp.endswith("noexcept;"):
            docstring.clear()
            continue

        if "&operator=" in temp:
            docstring.clear()
            continue

        if "nullobj;" in temp:
            docstring.clear()
            continue

        if temp.startswith("operator bool()"):
            docstring.clear()
            continue

        if temp.startswith("[[deprecated"):
            docstring.clear()
            continue

        # Now that we know that the next code is important, we add their docstring.
        for s in docstring:
            new_content.append(s)
        docstring.clear()

        new_content.append(line)

    return "\n".join(new_content)

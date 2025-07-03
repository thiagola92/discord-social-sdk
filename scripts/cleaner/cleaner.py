def clean_content(content: str) -> str:
    """
    Go through content, removing anything that is
    not useful for our parser.

    It's not a necessary step, but helps to have a clear visualization.
    """

    new_content = []

    # For rare cases where you need to skip multiple lines.
    skip_next = 0

    for line in content.split("\n"):
        temp = line.strip()

        if skip_next:
            skip_next -= 1
            continue

        # We don't need anything after finding this,
        # because everything after is function implementation.
        if temp.startswith("} // namespace discordpp"):
            break

        # Remove comments
        if temp.startswith("//"):
            continue

        # Remove macros.
        if temp.startswith("#include"):
            continue

        if temp.startswith("#define"):
            continue

        if temp.startswith("#ifndef"):
            continue

        if temp.startswith("#ifdef"):
            continue

        if temp.startswith("#endif"):
            continue

        if temp.startswith("#undef"):
            continue

        if temp.startswith("#pragma"):
            continue

        # Everything is on discordpp namespace, so we don't need it.
        if temp.startswith("namespace discordpp {"):
            continue

        # No need for class declarations, we can deduce this later.
        if temp.startswith("class ") and temp.endswith(";"):
            continue

        # Remove multiple informations from class that we don't need.
        # Luckly every single one of them is one line.
        if temp.startswith("mutable"):
            continue

        if "state_ = " in temp:
            continue

        if temp.startswith("public:"):
            continue

        if "*instance()" in temp:
            continue

        if "instance," in temp and temp.endswith(";"):
            continue

        if "instance," in temp and not temp.endswith(";"):
            skip_next += 1
            continue

        if temp.startswith("~"):
            continue

        if temp.endswith("noexcept;"):
            continue

        if "&operator=" in temp:
            continue

        if "nullobj;" in temp:
            continue

        if temp.startswith("operator bool()"):
            continue

        if temp.startswith("[[deprecated"):
            continue

        new_content.append(line)

    return "\n".join(new_content)

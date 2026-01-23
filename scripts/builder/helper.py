from xml.etree.ElementTree import Element


def collect_enums(tree: Element) -> dict:
    enums = []

    for e in tree.findall(".//memberdef[@kind='enum']"):
        if e.find("name").text == "DiscordObjectState":  # Exclude.
            continue

        values = []

        for ev in e.findall("enumvalue"):
            init = ev.find("initializer")

            values.append(
                {
                    "name": ev.find("name").text,
                    "short_desc": "".join(ev.find("briefdescription").itertext()),
                    "long_desc": "".join(ev.find("detaileddescription").itertext()),
                    "init": init.text + "," if init is not None else ",",
                }
            )

        enums.append(
            {
                "name": e.find("name").text,
                "short_desc": "".join(e.find("briefdescription").itertext()),
                "long_desc": "".join(e.find("detaileddescription").itertext()),
                "values": values,
            }
        )

    return enums

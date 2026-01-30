# Responsible for creating fake data.
from data import ParamInfo


def fake_enums_params(params: list[ParamInfo]) -> ParamInfo:
    fake_params = []
    use_suffix = len(params) > 1
    suffix = ""

    for i, p in enumerate(params):
        if use_suffix:
            suffix = str(i)

        fake = ParamInfo()
        fake.type = p.type
        fake.name = f"EnumType{suffix}"
        fake.gdscript_name = f"enum_type{suffix}"
        fake.callback = p.callback
        fake.enum = p.enum
        fake.fake = True
        fake_params.append(fake)

    return fake_params

from helper import to_snake_case
from parser import VarType, Param, Method, parse_params
from extractor import get_callbacks
from template_code import (
    signature_,
    method_,
    enum_from_godot_,
    obj_from_godot_,
    bind_,
    include_,
    signal_,
    signal_property,
    call_,
    variant_from_godot_,
    variant_number_from_godot_,
    variant_string_from_godot_,
    variant_object_from_godot_,
    string_from_godot_,
    string_to_godot_,
    enum_to_godot_,
    obj_to_godot_,
    optional_to_godot_,
    optional_number_to_variant_,
    optional_string_to_variant_,
    optional_enum_to_variant_,
    optional_obj_to_godot_,
    number_to_godot_,
    vector_number_to_godot_,
    vector_string_to_godot_,
    vector_obj_to_godot_,
    map_string_string_to_godot_,
    lambda_,
    dict_from_godot,
)


def build_type(var_type: VarType) -> str:
    if var_type.is_opt:
        return "Variant"

    if var_type.is_vector:
        var_type.is_vector = False
        typed_array = f"TypedArray<{build_type(var_type)}>"
        var_type.is_vector = True
        return typed_array

    if var_type.is_map:
        var_type.is_map = False
        typed_dict = f"TypedDictionary<{build_type(var_type)}>"
        var_type.is_map = True
        return typed_dict

    if var_type.is_enum:
        enum_name = var_type.name.replace("::", "")
        return f"Discord{enum_name}::Enum"

    if var_type.is_discord:
        return f"Discord{var_type.name} *"

    if var_type.is_boolean or var_type.is_number:
        return var_type.name

    if var_type.is_string:
        return "String"

    if var_type.name == "void":
        return "void"

    if var_type.name == "std::string, std::string":
        return "String, String"

    assert False, "Unexpected case"


def build_param(param: Param) -> str:
    var_type = build_type(param.type)
    name = to_snake_case(param.name)

    return f"{var_type} {name}"


def build_signals(method: Method, class_name: str) -> str:
    signals = [to_snake_case(p.type.name) for p in method.callables]

    signals_params = [p.type.name for p in method.callables]
    signals_params = [p.removeprefix(class_name + "::") for p in signals_params]
    signals_params = [get_callbacks()[class_name][p] for p in signals_params]
    signals_params = [parse_params(p + ")") for p in signals_params]

    for s in signals_params:
        for p in s:
            if p.type.is_opt:
                p.var = "Variant::NIL"
            elif p.type.is_vector:
                p.var = "Variant::ARRAY"
            elif p.type.is_map:
                p.var = "Variant::DICTIONARY"
            elif p.type.is_discord:
                p.var = "Variant::OBJECT"
            elif p.type.is_boolean:
                p.var = "Variant::BOOL"
            elif p.type.is_integer:
                p.var = "Variant::INT"
            elif p.type.is_float:
                p.var = "Variant::FLOAT"
            elif p.type.is_string:
                p.var = "Variant::STRING"
            else:
                assert False

    for i, s in enumerate(signals_params):
        properties = []

        for p in s:
            properties.append(
                signal_property(
                    param_type=p.var,
                    param_name=to_snake_case(p.name),
                    param_type_name="Discord" + p.type.name,
                )
            )

        signals_params[i] = ",".join(properties)

        if signals_params[i]:
            signals_params[i] = "," + signals_params[i]

    signals = [
        signal_(signal_name=s, signal_params=signals_params[i])
        for i, s in enumerate(signals)
    ]

    signals = "\n".join(signals)

    return signals


def build_bind(method: Method, class_name: str) -> str:
    method_snake_name = to_snake_case(method.name)
    params = [to_snake_case(p.name) for p in method.uncallables]
    bind_params = [method_snake_name] + params
    bind_params = [f'"{p}"' for p in bind_params]
    bind_params = ", ".join(bind_params)

    return bind_(
        bind_params=bind_params,
        class_name=class_name,
        method_snake_name=method_snake_name,
    )


def build_signature(method: Method) -> str:
    return_type = build_type(method.ret)
    method_snake_name = to_snake_case(method.name)
    params = ", ".join([build_param(p) for p in method.uncallables])

    return signature_(
        return_type=return_type,
        method_snake_name=method_snake_name,
        params=params,
    )


def build_lambda(method: Method, param: Param, class_name: str) -> str:
    # Decide signal called.
    signal_name = to_snake_case(method.name)
    signal_name += "_callback"

    # Get callback params.
    callback_type = param.type.name
    callback_type = callback_type.removeprefix(class_name + "::")
    callback_params = get_callbacks()[class_name][callback_type]

    # Transform to Godot types to C types.
    lambda_method = Method()
    lambda_method.uncallables = parse_params(callback_params + ")")
    statements = []

    for i, p in enumerate(lambda_method.uncallables):
        lambda_method.ret = p.type
        return_statement = build_after_call(
            method=lambda_method,
            variable_name=p.name,
        )
        p.var = f"p{i}"
        statement = return_statement.replace("return ", f"auto {p.var} = ")

        statements.append(statement)

    statements = "\n".join(statements)

    # Prepare passing parameters.
    signal_params = [p.var for p in lambda_method.uncallables]
    signal_params = ",".join(signal_params)
    signal_params = "," + signal_params if signal_params else ""

    return lambda_(
        params=callback_params,
        statements=statements,
        signal_name=signal_name,
        signal_params=signal_params,
    )


def build_call(
    method: Method,
    class_name: str,
    property_name: str,
):
    passing_params = []

    for p in method.params:
        if p.type.is_callback:
            passing_params.append(
                build_lambda(
                    method=method,
                    param=p,
                    class_name=class_name,
                )
            )
        else:
            passing_params.append(p.var or to_snake_case(p.name))

    passing_params = ", ".join(passing_params)

    return call_(
        property_name=property_name,
        method_name=method.name,
        passing_params=passing_params,
    )


def build_method(
    method: Method, class_name: str, property_name: str, has_empty_constructor: bool
) -> str:
    return_type = build_type(method.ret)
    method_snake_name = to_snake_case(method.name)
    params = [build_param(p) for p in method.uncallables]
    params = ", ".join(params)
    before_call = build_before_call(method)

    # Nothing to return? Just call method.
    if method.ret.name == "void":
        call = build_call(
            method=method,
            class_name=class_name,
            property_name=property_name,
        )

        statements = [before_call, call]
        statements = [s for s in statements if len(s) > 0]
        statements = "\n    ".join(statements)

        return method_(
            return_type=return_type,
            class_name=class_name,
            method_snake_name=method_snake_name,
            params=params,
            statements=statements,
        )

    return_name = "r"
    call = f"auto {return_name} = "
    call += build_call(
        method=method,
        class_name=class_name,
        property_name=property_name,
    )

    after_call = build_after_call(
        method=method,
        variable_name=return_name,
    )

    statements = [before_call, call, after_call]
    statements = "\n    ".join(statements)

    return method_(
        return_type=return_type,
        class_name=class_name,
        method_snake_name=method_snake_name,
        params=params,
        statements=statements,
    )


####################################################
#################### Before Call ####################
####################################################


def build_variant_type(param: Param) -> str:
    if param.type.is_integer:
        return "Variant::INT"

    if param.type.is_float:
        return "Variant::FLOAT"

    if param.type.is_string:
        return "Variant::STRING"

    return "Variant::OBJECT"


def build_variant_type_name(param: Param) -> str:
    if param.type.is_discord:
        return "discordpp::" + param.type.name

    return param.type.name


def build_variant_convertion(param: Param, variable_name: str) -> str:
    variant_type = param.type.name
    param_snake_name = to_snake_case(param.name)

    if param.type.is_vector:
        # Array to vector
        return f"// FIX ME: build_variant_convertion >> vector >> {variant_type}"

    if param.type.is_map:
        # Dictionary to unordered_map
        return f"// FIX ME: build_variant_convertion >> map >> {variant_type}"

    if param.type.is_enum:
        return f"// FIX ME: build_variant_convertion >> enum >> {variant_type}"

    if param.type.is_discord:
        return variant_object_from_godot_(
            variable_name=variable_name,
            variant_type=variant_type,
            param_snake_name=param_snake_name,
        )

    if param.type.is_boolean:
        return f"// FIX ME: build_variant_convertion >> bool >> {variant_type}"

    if param.type.is_number:
        return variant_number_from_godot_(
            variable_name=variable_name,
            variant_type=variant_type,
            param_snake_name=param_snake_name,
        )

    if param.type.is_string:
        return variant_string_from_godot_(
            variable_name=variable_name,
            param_snake_name=param_snake_name,
        )

    return f"// FIX ME: build_variant_convertion >> {variant_type}"


def build_before_call(method: Method) -> str:
    statements = []

    for n, param in enumerate(method.uncallables):
        variable_name = f"p{n}"
        param_snake_name = to_snake_case(param.name)

        if param.type.is_opt:
            parameter_type = build_variant_type_name(param)
            variant_type = build_variant_type(param)
            variant_convertion = build_variant_convertion(
                param,
                variable_name,
            )

            statements.append(
                variant_from_godot_(
                    parameter_type=parameter_type,
                    variable_name=variable_name,
                    param_snake_name=param_snake_name,
                    variant_type=variant_type,
                    variant_convertion=variant_convertion,
                )
            )

            param.var = variable_name
        elif param.type.is_vector:
            statements.append(
                f"// FIX ME: build_before_call >> vector >> {param.type.name}"
            )
        elif param.type.is_map:
            statements.append(
                dict_from_godot(
                    variable_name=variable_name,
                    param_snake_name=param_snake_name,
                )
            )

            param.var = variable_name
        elif param.type.is_enum:
            statements.append(
                enum_from_godot_(
                    variable_name=variable_name,
                    enum_type=param.type.name,
                    param_snake_name=param_snake_name,
                )
            )

            param.var = variable_name
        elif param.type.is_discord:
            statements.append(
                obj_from_godot_(
                    variable_name=variable_name,
                    param_snake_name=param_snake_name,
                )
            )

            param.var = variable_name
        elif param.type.is_boolean or param.type.is_number:
            pass  # Do nothing.
        elif param.type.is_string:
            statements.append(
                string_from_godot_(
                    variable_name=variable_name,
                    param_snake_name=param_snake_name,
                )
            )

            param.var = variable_name
        else:
            statements.append(f"// FIX ME: build_before_call >> {param.type.name}")

    return "\n".join(statements)


####################################################
#################### After Call ####################
####################################################


def build_after_call(method: Method, variable_name: str) -> str:
    assert method.ret.name != "void"

    if method.ret.is_opt:
        statements = [optional_to_godot_(variable_name=variable_name)]

        if method.ret.is_vector:
            statements.append(
                f"// FIX ME: build_after_call >> opt >> vector >> {method.ret.name}"
            )
        elif method.ret.is_map:
            statements.append(
                f"// FIX ME: build_after_call >> opt >> map >> {method.ret.name}"
            )
        elif method.ret.is_enum:
            statements.append(
                optional_enum_to_variant_(
                    return_type=method.ret.name,
                    variable_name=variable_name,
                )
            )
        elif method.ret.is_discord:
            statements.append(
                optional_obj_to_godot_(
                    class_name=method.ret.name,
                    variable_name=variable_name,
                )
            )
        elif method.ret.is_string:
            statements.append(
                optional_string_to_variant_(
                    variable_name=variable_name,
                )
            )
        elif method.ret.is_boolean or method.ret.is_number:
            statements.append(
                optional_number_to_variant_(
                    variable_name=variable_name,
                )
            )
        else:
            statements.append(
                f"// FIX ME: build_after_call >> opt >> {method.ret.name}"
            )

        statements = "\n".join(statements)

        return statements

    if method.ret.is_vector and (method.ret.is_number or method.ret.is_boolean):
        return vector_number_to_godot_(
            variable_name=variable_name,
            typed_array=build_type(method.ret),
        )

    if method.ret.is_vector and method.ret.is_string:
        return vector_string_to_godot_(
            variable_name=variable_name,
            typed_array=build_type(method.ret),
        )

    if method.ret.is_vector and method.ret.is_enum:
        return f"// FIX ME: build_after_call >> vector >> {method.ret.name}"

    if method.ret.is_vector and method.ret.is_discord:
        return vector_obj_to_godot_(
            variable_name=variable_name,
            typed_array=build_type(method.ret),
            class_name=method.ret.name,
        )

    if method.ret.is_vector:
        return f"// FIX ME: build_after_call >> vector >> {method.ret.name}"

    if method.ret.is_map:
        return map_string_string_to_godot_(
            variable_name=variable_name,
            typed_dict=build_type(method.ret),
        )

    if method.ret.is_enum:
        return enum_to_godot_(
            return_type=method.ret.name.replace("::", ""),
            variable_name=variable_name,
        )

    if method.ret.is_discord:
        return obj_to_godot_(
            variable_name=variable_name,
            class_name=method.ret.name,
        )

    if method.ret.is_string:
        return string_to_godot_(variable_name=variable_name)

    if method.ret.is_boolean or method.ret.is_number:
        return number_to_godot_(variable_name=variable_name)

    return f"// FIX ME: build_after_call >> {method.ret.name}"

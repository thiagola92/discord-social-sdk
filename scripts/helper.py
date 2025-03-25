def to_snake_case(string: str) -> str:
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

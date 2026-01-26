from parse import parse_type
from data import TypeInfo


def print_and_test(type_str: str, expected: TypeInfo):
    result = parse_type(type_str)
    print(">>>", type_str)
    print("EXPECTED:", expected)
    print("RETURNED:", result)
    assert result == expected


print("----- Simple -----")
print_and_test("int", [TypeInfo(name="int")])
print_and_test("int, int", [TypeInfo(name="int"), TypeInfo(name="int")])
print_and_test("int, float", [TypeInfo(name="int"), TypeInfo(name="float")])
print_and_test("float, float", [TypeInfo(name="float"), TypeInfo(name="float")])
print_and_test(
    "int, int, int", [TypeInfo(name="int"), TypeInfo(name="int"), TypeInfo(name="int")]
)

print("----- Generics -----")
print_and_test("Vector<int>", [TypeInfo(name="Vector", subtype=[TypeInfo(name="int")])])
print_and_test(
    "Vector<int>, Vector<float>",
    [
        TypeInfo(name="Vector", subtype=[TypeInfo(name="int")]),
        TypeInfo(name="Vector", subtype=[TypeInfo(name="float")]),
    ],
)
print_and_test(
    "Dictionary<int, float>",
    [
        TypeInfo(
            name="Dictionary", subtype=[TypeInfo(name="int"), TypeInfo(name="float")]
        )
    ],
)

print("----- Parameters -----")
print_and_test(
    "int a, int b", [TypeInfo(name="int", extra="a"), TypeInfo(name="int", extra="b")]
)
print_and_test(
    "int a, float b",
    [TypeInfo(name="int", extra="a"), TypeInfo(name="float", extra="b")],
)
print_and_test(
    "Vector<int> a",
    [TypeInfo(name="Vector", subtype=[TypeInfo(name="int")], extra="a")],
)
print_and_test(
    "Vector<int> a, Vector<float> b",
    [
        TypeInfo(name="Vector", subtype=[TypeInfo(name="int")], extra="a"),
        TypeInfo(name="Vector", subtype=[TypeInfo(name="float")], extra="b"),
    ],
)
print_and_test(
    "Dictionary<int, float> a",
    [
        TypeInfo(
            name="Dictionary",
            subtype=[TypeInfo(name="int"), TypeInfo(name="float")],
            extra="a",
        )
    ],
)

print("----- Functions -----")
print_and_test(
    "void(int a)", [TypeInfo(name="void", subtype=[TypeInfo(name="int", extra="a")])]
)
print_and_test(
    "void(int a, float b)",
    [
        TypeInfo(
            name="void",
            subtype=[
                TypeInfo(name="int", extra="a"),
                TypeInfo(name="float", extra="b"),
            ],
        )
    ],
)
print_and_test(
    "void(Vector<int> a)",
    [
        TypeInfo(
            name="void",
            subtype=[
                TypeInfo(name="Vector", subtype=[TypeInfo(name="int")], extra="a")
            ],
        )
    ],
)
print_and_test(
    "void(Vector<int> a, Vector<float> b)",
    [
        TypeInfo(
            name="void",
            subtype=[
                TypeInfo(name="Vector", subtype=[TypeInfo(name="int")], extra="a"),
                TypeInfo(name="Vector", subtype=[TypeInfo(name="float")], extra="b"),
            ],
        )
    ],
)
print_and_test(
    "void(Dictionary<int, float> a)",
    [
        TypeInfo(
            name="void",
            subtype=[
                TypeInfo(
                    name="Dictionary",
                    subtype=[TypeInfo(name="int"), TypeInfo(name="float")],
                    extra="a",
                )
            ],
        )
    ],
)

# Execute simple tests.
from collect import collect_subtype
from data import TypeInfo

assert collect_subtype("void") == TypeInfo(name="void")
assert collect_subtype("int") == TypeInfo(name="int")
assert collect_subtype("float") == TypeInfo(name="float")

assert collect_subtype("Vector<int>") == TypeInfo(
    name="Vector",
    subtype=[TypeInfo(name="int")],
)

assert collect_subtype("Dictionary<int, int>") == TypeInfo(
    name="Dictionary",
    subtype=[TypeInfo(name="int"), TypeInfo(name="int")],
)

print(collect_subtype("Vector<Vector<int>>"))

assert collect_subtype("Vector<Vector<int>>") == TypeInfo(
    name="Vector",
    subtype=[TypeInfo(name="Vector", subtype=[TypeInfo(name="int")])],
)

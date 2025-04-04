from generator import generate_class
from extractor import get_classes


if __name__ == "__main__":
    classes = list(get_classes().keys())
    classes.sort()

    classes_registrations = ""
    classes_includes = ""

    for class_name in classes:
        class_methods = get_classes()[class_name]
        class_registration, class_include = generate_class(class_name, class_methods)

        # Increase strings to print later.
        classes_registrations += class_registration
        classes_includes += class_include

    print(f"########## CLASSES_INCLUDES ##########\n\n{classes_includes}")
    print(f"########## CLASSES_REGISTRATIONS ##########\n\n{classes_registrations}")

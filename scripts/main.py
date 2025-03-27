from generator import generate_class
from classes import CLASSES


if __name__ == "__main__":
    classes = list(CLASSES.keys())
    classes.sort()

    classes_registrations = ""
    classes_includes = ""

    for class_name in classes:
        class_registration, class_include = generate_class(
            class_name, CLASSES[class_name]
        )

        # Increase strings to print later.
        classes_registrations += class_registration
        classes_includes += class_include

    print(f"##### CLASSES_INCLUDES #####\n\n{classes_includes}")
    print(f"##### CLASSES_REGISTRATIONS #####\n\n{classes_registrations}")

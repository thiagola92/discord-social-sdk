def get_class_definition(
    class_name: str,
    constructor_private: str = "",
    constructor_public: str = "",
    functions: str = "",
    overloadings: str = "",
) -> str:
    return f"""
class Discord{class_name} : public RefCounted {{
	GDCLASS(Discord{class_name}, RefCounted)

private:
	discordpp::{class_name} *obj;

	{constructor_private}
protected:
	static void _bind_methods();
public:
    // Internal usage.
	discordpp::{class_name} *unwrap() {{
        return obj;
    }}

    // Constructors.
	{constructor_public}

    // Functions.
	{functions}

    // Overloading functions.
    {overloadings}

    // Internal usage.
	Discord{class_name}(discordpp::{class_name} *obj) {{
        this->obj = obj;
    }}

	~Discord{class_name}() {{
		memdelete(this->obj);
    }}
}};
"""

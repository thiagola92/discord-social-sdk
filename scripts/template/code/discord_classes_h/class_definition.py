def get_class_definition(
    class_name: str,
    constructor_private: str,
    functions: str,
    constructor_public: str,
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

	{functions}

	{constructor_public}

    // Internal usage.
	Discord{class_name}(discordpp::{class_name} *obj) {{
        this->obj = obj;
    }}

	~Discordpp{class_name}() {{
		memdelete(this->obj);
    }}
}};
"""

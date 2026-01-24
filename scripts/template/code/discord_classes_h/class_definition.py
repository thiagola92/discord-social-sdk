def get_class_definition(
    class_name: str,
    private_constructors: str,
    methods: str,
    public_constructors: str,
) -> str:
    return f"""
class Discord{class_name} : public RefCounted {{
	GDCLASS(Discord{class_name}, RefCounted)

private:
	discordpp::{class_name} *obj;
	{private_constructors}
protected:
	static void _bind_methods();
public:
    // Internal usage.
	discordpp::{class_name} *unwrap() {{
        return obj;
    }}

	{methods}

	{public_constructors}

	Discord{class_name}(discordpp::{class_name} *obj) {{
        this->obj = obj;
    }}

	~Discordpp{class_name}() {{
		memdelete(this->obj);
    }}
}};
"""


def get_class_definition_global(
    methods: str,
) -> str:
    return f"""
class Discordpp : public RefCounted {{
	GDCLASS(Discordpp, RefCounted)

private:
	Discordpp() {{}}
protected:
	static void _bind_methods();
public:
	{methods}

	~Discordpp() {{}}
}};
"""

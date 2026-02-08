def get_enum_definition(
    enum_name: str,
    enums_binds: str,
    const_binds: str,
    enum_id: str,
    values: str,
) -> str:
    return f"""
class Discord{enum_name} : public RefCounted {{
	GDCLASS(Discord{enum_name}, RefCounted)

private:
	Discord{enum_name}(){{}};
	~Discord{enum_name}(){{}};

protected:
	static void _bind_methods() {{
		// Enums binds.
		{enums_binds}
        
        // Constant binds.
        {const_binds}
	}}

public:
	static const int64_t id = {enum_id};

	enum Enum {{
		{values}
	}};
}};
"""

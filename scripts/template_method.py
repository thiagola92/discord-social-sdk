TEMPLATE_METHOD = """
{return_type} Discord{class_name}::{method_snake_name}({params}) {{
    // FINISH ME
    {return_keyword}{property_name}{operator}{method_name}({passing_params});
}}
"""

TEMPLATE_LAMBDA = """[this]() {{
        this->emit_signal("{signal_name}");
    }}"""

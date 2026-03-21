"""
Configuração parametrizada para parsers C, C++ e Python3
Define os tipos de nós, operadores e palavras-chave específicas de cada linguagem
"""

LANGUAGE_CONFIG = {
    "python": {
        "name": "Python3",
        "parser_lib": "tree_sitter_python",
        "file_pattern": "*.py",
        "operators": {
            "arithmetic": ("+", "-", "*", "/", "//", "%", "**", "@"),
            "assignment": ("=", "+=", "-=", "*=", "/=", "//=", "%=", "**=", "&=", "|=", "^=", ">>=", "<<=", ":="),
            "bitwise": ("&", "|", "^", "~", "<<", ">>"),
            "comparison": ("==", "!=", "<", ">", ">=", "<=", "in", "not in", "is", "is not"),
            "logical": ("and", "or", "not"),
        },
        "branch": (
            "function_definition",
            "if_statement",
            "for_statement", "while_statement",
            "try_statement", "except_clause", "finally_clause",
            "with_statement",
            "class_definition",
            "match_statement",
        ),
        "types": (
            "identifier", "relative_import", "dotted_name",
            "integer", "float", "complex_number",
            "string", "string_content",
            "true", "false", "none",
            "list", "tuple", "dictionary", "set",
        ),
        "word": (
            "def", "class", "if", "elif", "else", "for", "while", "break", "continue",
            "return", "try", "except", "finally", "raise", "with", "as", "import", "from",
            "pass", "assert", "del", "and", "or", "not", "in", "is", "lambda", "yield",
            "await", "async", "match", "case", "global", "nonlocal",
            "True", "False", "None",
        ),
    },
    "c": {
        "name": "C",
        "parser_lib": "tree_sitter_c",
        "file_pattern": "*.c",
        "operators": {
            "arithmetic": ("+", "++", "-", "--", "*", "/", "%"),
            "assignment": ("=", "+=", "-=", "*=", "/=", "%=", "&=", "|=", "^=", ">>=", "<<="),
            "bitwise": ("&", "|", "^", "~", "<<", ">>"),
            "comparison": ("==", "!=", "<", ">", ">=", "<="),
            "logical": ("&&", "||", "!"),
        },
        "branch": (
            "function_definition",
            "if_statement", "else_clause",
            "case_statement",
            "do_statement", "for_statement", "while_statement",
            "labeled_statement",
        ),
        "types": (
            "character", "#define", "identifier", "field_identifier", "null",
            "number_literal", "preproc_arg", "#include", "primitive_type",
            "statement_identifier", "string_content", "system_lib_string", "type_identifier",
        ),
        "word": (
            "auto", "if", "else", "else_statement", "switch", "case", "continue",
            "break", "default", "do", "goto", "for", "while", "return", "const",
            "extern", "enum", "register", "sizeof", "typedef", "static", "struct",
            "union", "volatile",
        ),
    },
    "cpp": {
        "name": "C++",
        "parser_lib": "tree_sitter_cpp",
        "file_pattern": "*.cpp",
        "operators": {
            "arithmetic": ("+", "++", "-", "--", "*", "/", "%", "->*", ".*"),  # +2 member operators
            "assignment": ("=", "+=", "-=", "*=", "/=", "%=", "&=", "|=", "^=", ">>=", "<<="),
            "bitwise": ("&", "|", "^", "~", "<<", ">>"),
            "comparison": ("==", "!=", "<", ">", ">=", "<="),
            "logical": ("&&", "||", "!"),
        },
        "branch": (
            "function_definition",
            "if_statement", "else_clause",
            "switch_statement", "case_statement",
            "do_statement", "for_statement", "for_range_loop", "while_statement",
            "labeled_statement",
            # C++ specific
            "try_statement", "catch_clause",
            "class_specifier",
            "namespace_definition",
            "template_declaration",
        ),
        "types": (
            # Inherited from C
            "character", "#define", "identifier", "field_identifier", "null",
            "number_literal", "preproc_arg", "#include", "primitive_type",
            "statement_identifier", "string_content", "system_lib_string", "type_identifier",
            "escape_sequence",
            # C++ specific
            "boolean_literal",        # true, false
            "nullptr",                # nullptr
            "user_defined_literal",   # 1.0_km, "hello"s
            "namespace_identifier",   # std::
            "raw_string_content",     # R"(...)"
        ),
        "word": (
            # Inherited from C
            "auto", "if", "else", "else_statement", "switch", "case", "continue",
            "break", "default", "do", "goto", "for", "while", "return", "const",
            "extern", "enum", "register", "sizeof", "typedef", "static", "struct",
            "union", "volatile",
            # C++ specific - Access control (3)
            "class", "public", "private", "protected",
            # C++ specific - OOP (8)
            "virtual", "override", "final", "operator", "this",
            "explicit", "friend", "mutable",
            # C++ specific - Namespaces and templates (4)
            "namespace", "using", "template", "typename",
            # C++ specific - Modifiers (3)
            "inline", "constexpr", "noexcept",
            # C++ specific - Memory management (2)
            "new", "delete",
            # C++ specific - Exception handling (3)
            "try", "catch", "throw",
            # C++ specific - Type system (8)
            "decltype", "static_assert", "typeid",
            "dynamic_cast", "static_cast", "reinterpret_cast", "const_cast",
            # C++ specific - Coroutines C++20 (3)
            "co_await", "co_return", "co_yield",
        ),
    },
}

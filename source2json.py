#!/home/bruno/.python/bin/python

from tree_sitter import Language, Parser, Tree, Node
import glob
import json
import os
import re
import sys
import tree_sitter_c
import tree_sitter_cpp

SUPPORTED_LANGUAGES = ("c", "cpp", "py")

def c_preprocessor(token):
    token = re.sub(r"\#\s*(.*)\s*", r"#\1", token)
    token = re.sub(r"<(.*)>", r"\1", token)
    token = re.sub(r"\s+", " ", token)
    return token.strip()

def c_basic_block_split(basic_block, branch, current_end_point, node):
    case_without_break = False
    else_if = False
    if node.type in branch and len(basic_block[-1]) > 0:
        case_without_break = not (node.type == "case_statement" and basic_block[-1][0][0] == "case" and basic_block[-1][-1][0] != "break")
        else_if = not (node.type == "if_statement" and basic_block[-1][-1][0] == "else")
    return (case_without_break and else_if) or (current_end_point < node.end_point)

def c_basic_block_end_point(branch, current_end_point, last_end_point, node):
    not_case_without_break_or_default = not (node.type == "case_statement" and len(re.findall(r"break|default", str(node.text, "utf-8"))) == 0)
    return node.end_point if node.type in branch and not_case_without_break_or_default else last_end_point

def c_basic_block(nodes):
    arithmetic = ("+", "++", "-", "--", "*", "/", "%")
    assignment = ("=", "+=", "-=", "*=", "/=", "%=", "&=", "|=", "^=", ">>=", "<<=")
    bitwise = ("&", "|", "^", "~", "<<", ">>")
    branch = ("function_definition", "if_statement", "else_clause", "case_statement", "do_statement", "for_statement", "while_statement", "labeled_statement")
    comparison = ("==", "!=", "<", ">", ">=", "<=")
    logical = ("&&", "||", "!")
    types = ("character", "#define", "identifier", "field_identifier", "null", "number_literal", "preproc_arg", "#include", "primitive_type", "statement_identifier", "string_content", "system_lib_string", "type_identifier")
    word = ("auto", "if", "else", "else_statement", "switch", "case", "continue", "break", "default", "do", "goto", "for", "while", "return", "const", "extern", "enum", "register", "sizeof", "typedef", "static", "struct", "union", "volatile")
    basic_block = [[]]
    basic_block_index = 0
    current_end_point = nodes[0].end_point
    for node in nodes:
        if c_basic_block_split(basic_block, branch, current_end_point, node):
            basic_block.append([])
            basic_block_index = basic_block_index + 1
            current_end_point = c_basic_block_end_point(branch, current_end_point, nodes[0].end_point, node)
        if node.type in arithmetic + assignment + bitwise + comparison + logical + word + types:
            basic_block[basic_block_index].append((node.type, c_preprocessor(str(node.text, "utf-8")), node.start_point, node.end_point))
    return basic_block

def cpp_preprocessor(token):
    token = re.sub(r"\#\s*(.*)\s*", r"\1", token)
    token = re.sub(r"<(.*)>", r"\1", token)
    token = re.sub(r"\s+", " ", token)
    return token.strip()

def cpp_basic_block(nodes):
    arithmetic = ("+", "++", "-", "--", "*", "/", "%", "->*", ".*")
    assignment = ("=", "+=", "-=", "*=", "/=", "%=", "&=", "|=", "^=", ">>=", "<<=")
    bitwise = ("&", "|", "^", "~", "<<", ">>")
    branch = (
        "function_definition",
        "if_statement", "else_clause",
        "switch_statement", "case_statement",
        "do_statement", "for_statement", "while_statement",
        "labeled_statement",  # Gotos e labels para C/C++
        # C++ constructs que criam pontos de entrada lógicos
        "try_statement", "catch_clause",
        "class_specifier",
        "namespace_definition",
        "template_declaration",
    )
    comparison = ("==", "!=", "<", ">", ">=", "<=")
    logical = ("&&", "||", "!")
    types = (
        # Tipos/literais herdados do parser C
        "character", "#define", "identifier", "field_identifier", "statement_identifier", "null",
        "number_literal", "preproc_arg", "#include", "primitive_type",
        "string_content", "system_lib_string", "type_identifier", "escape_sequence",
        # Adições C++
        "boolean_literal",        # true / false
        "nullptr",                # nullptr como literal
        "user_defined_literal",   # ex: 1.0_km, "hello"s
        "namespace_identifier",   # identificador de namespace (ex: std)
        "raw_string_content",     # conteúdo de raw strings R"(...)"
    )
    word = (
        # Palavras-chave herdadas do C
        "auto", "if", "else", "else_statement", "switch", "case", "continue",
        "break", "default", "do", "goto", "for", "while", "return", "const",
        "extern", "enum", "register", "sizeof", "typedef", "static", "struct",
        "union", "volatile",
        # Palavras-chave C++: controle de acesso
        "class", "public", "private", "protected",
        # Palavras-chave C++: orientação a objetos
        "virtual", "override", "final", "operator", "this",
        "explicit", "friend", "mutable",
        # Palavras-chave C++: namespaces e templates
        "namespace", "using", "template", "typename",
        # Palavras-chave C++: modificadores de função/variável
        "inline", "constexpr", "noexcept",
        # Palavras-chave C++: gerenciamento de memória
        "new", "delete",
        # Palavras-chave C++: tratamento de exceções
        "try", "catch", "throw",
        # Palavras-chave C++: type system avançado
        "decltype", "static_assert", "typeid",
        "dynamic_cast", "static_cast", "reinterpret_cast", "const_cast",
        # Palavras-chave C++20: corrotinas
        "co_await", "co_return", "co_yield",
    )
    basic_block = [[]]
    basic_block_index = 0
    basic_block_file_end_point = nodes[-1].end_point if nodes else (0, 0)
    basic_block_branch_end_point = basic_block_file_end_point
    for node in nodes:
        last_block = basic_block[basic_block_index]
        if len(last_block) > 0 and node.type in branch:
            # Check if should split block based on node type and last instruction
            should_split = True
            if node.type == "if_statement" and len(last_block) > 0 and last_block[-1][0] == "else":
                # else if doesn't split
                should_split = False
            elif node.type == "case_statement" and len(last_block) > 0:
                # case without break (fall-through) doesn't split
                is_prev_case = last_block[0][0] == "case"
                has_break = last_block[-1][0] == "break"
                if is_prev_case and not has_break:
                    should_split = False

            if should_split or basic_block_branch_end_point < node.start_point:
                basic_block.append([])
                basic_block_index = basic_block_index + 1
                basic_block_branch_end_point = node.end_point

        if node.type in arithmetic + assignment + bitwise + comparison + logical + word + types:
            basic_block[basic_block_index].append((node.type, cpp_preprocessor(str(node.text, "utf-8")), node.start_point, node.end_point))
    return basic_block

def traverse(tree):
    cursor = tree.walk()
    visited_children = False
    nodes = []
    while True:
        if not visited_children:
            nodes.append(cursor.node)
            if not cursor.goto_first_child():
                visited_children = True
        elif cursor.goto_next_sibling():
            visited_children = False
        elif not cursor.goto_parent():
            break
    return nodes

def parse_input(filename, language):
    point2tuple = lambda point : (point.row, point.column)
    corpus = []
    with open(filename) as file:
        data = file.read()
    match language:
        case "c":
            c = Language(tree_sitter_c.language())
            parser = Parser(c)
            tree = parser.parse(bytes(data, "utf8"))
            nodes = traverse(tree)
            basic_blocks = c_basic_block(nodes)
            for basic_block in basic_blocks:
                if len(basic_block) > 0:
                    sentence = [token[1] for token in basic_block]
                    corpus.append([sentence, point2tuple(basic_block[0][2]), point2tuple(basic_block[-1][3])])
        case "cpp":
            cpp = Language(tree_sitter_cpp.language())
            parser = Parser(cpp)
            tree = parser.parse(bytes(data, "utf8"))
            nodes = traverse(tree)
            basic_blocks = cpp_basic_block(nodes)
            for basic_block in basic_blocks:
                if len(basic_block) > 0:
                    sentence = [token[1] for token in basic_block]
                    corpus.append([sentence, point2tuple(basic_block[0][2]), point2tuple(basic_block[-1][3])])
        case "py":
            print("PYTHON NOT IMPLEMENTED YET!")
            exit(1)
    return corpus

def main(argv):
    if len(argv) != 2:
        print("usage: " + argv[0] + " <directory>")
        exit(1)

    consolidated = {}
    for language in SUPPORTED_LANGUAGES:
        for source in glob.glob(argv[1] + "/*." + language):
            print("parsing " + source, flush = True)
            corpus = parse_input(source, language)
            consolidated[source] = corpus

    # Write consolidated results to individual JSON files
    written_files = set()
    for source, corpus in consolidated.items():
        basename, _ = os.path.splitext(source)
        json_file = basename + ".json"

        # Load existing data if file already exists
        file_data = {}
        if os.path.exists(json_file):
            with open(json_file, "r") as f:
                file_data = json.load(f)

        # Update with current result
        file_data[source] = corpus

        # Write consolidated data
        with open(json_file, "w") as f:
            json.dump(file_data, f)

        written_files.add(json_file)

if __name__ == "__main__":
    main(sys.argv)

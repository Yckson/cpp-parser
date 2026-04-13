"""
Parser unificado para C e C++
Detecta linguagem automaticamente e aplica configuração apropriada
"""

from tree_sitter import Language, Parser
import glob
import json
import os
import re
import sys
import tree_sitter_c
import tree_sitter_cpp
import tree_sitter_python

from parser_config import LANGUAGE_CONFIG


def get_language_parser(language):
    """Retorna o parser de Tree-sitter para a linguagem especificada"""
    if language == "c":
        return Language(tree_sitter_c.language()), "c"
    elif language == "cpp":
        return Language(tree_sitter_cpp.language()), "cpp"
    elif language == "python":
        return Language(tree_sitter_python.language()), "python"
    else:
        raise ValueError(f"Linguagem não suportada: {language}")


def preprocessor(token):
    """Normaliza tokens (idêntico para C e C++)"""
    token = re.sub(r"\#\s*(.*)\s*", r"\1", token)
    token = re.sub(r"<(.*)>", r"\1", token)
    token = re.sub(r"\s+", " ", token)
    return token.strip()


def is_docstring_node(node):
    """Detecta se um nó é parte de um docstring Python"""
    # Docstrings são string_content e string que vêm de expression_statement
    if node.type in ("string_content", "string"):
        # Para string, verifica se está em expression_statement
        if node.type == "string":
            parent = node.parent
            if parent and parent.type == "expression_statement":
                return True
        # Para string_content, verifica se vem de um string que está em expression_statement
        elif node.type == "string_content":
            parent = node.parent
            if parent and parent.type == "string":
                grandparent = parent.parent
                if grandparent and grandparent.type == "expression_statement":
                    return True
    return False


def traverse(tree):
    """Traversal DFS em pré-ordem (idêntico para C e C++)"""
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


def get_terminator_statement_end_point(node, language):
    """Retorna o ponto de corte correto após um terminador de fluxo"""
    current = node
    statement_end = node.end_point
    enclosing_if_end = None
    enclosing_if_node = None
    inside_else_clause = False

    while current is not None:
        if current.type.endswith("_statement") and statement_end == node.end_point:
            statement_end = current.end_point
        if current.type == "if_statement" and enclosing_if_end is None:
            enclosing_if_end = current.end_point
            enclosing_if_node = current
        if current.type == "else_clause":
            inside_else_clause = True
        current = current.parent

    # Python: mantém if+elif no mesmo bloco e inicia novo bloco no else
    if language == "python" and enclosing_if_node is not None:
        if not inside_else_clause:
            for child in enclosing_if_node.children:
                if child.type == "else_clause":
                    return child.start_point
            return enclosing_if_end
        return statement_end

    # Mantém if/else no mesmo bloco: um terminador dentro do if só corta após o if completo
    if enclosing_if_end is not None and statement_end <= enclosing_if_end:
        return enclosing_if_end

    return statement_end


def is_conditional_chain_node(node, language):
    """Retorna True para nós que devem permanecer no mesmo bloco da cadeia condicional"""
    if language == "python":
        # Em Python, apenas elif fica no mesmo bloco do if; else deve iniciar novo bloco.
        if node.type in ("elif_clause",):
            return True
        if node.type == "if_statement" and node.parent is not None and node.parent.type == "elif_clause":
            return True
        return False

    # C/C++: else-if é representado por else_clause contendo if_statement.
    if node.type == "else_clause":
        return any(child.type == "if_statement" for child in node.children)

    # C/C++: o if_statement filho do else_clause (else if) também permanece no mesmo bloco.
    if node.type == "if_statement" and node.parent is not None and node.parent.type == "else_clause":
        return True

    return False


def basic_block(nodes, language):
    """
    Divide nós em blocos básicos parametrizados pela linguagem
    Usa lógica simples e legível (originária do C++)
    """
    config = LANGUAGE_CONFIG[language]

    # Desempacotar configuração
    arithmetic = config["operators"]["arithmetic"]
    assignment = config["operators"]["assignment"]
    bitwise = config["operators"]["bitwise"]
    comparison = config["operators"]["comparison"]
    logical = config["operators"]["logical"]
    branch = config["branch"]
    types = config["types"]
    word = config["word"]
    terminators = config.get("terminators", ())

    # Inicializar blocos
    basic_block_list = [[]]
    basic_block_index = 0
    basic_block_file_end_point = nodes[-1].end_point if nodes else (0, 0)
    basic_block_branch_end_point = basic_block_file_end_point
    split_after_terminator = False
    terminator_statement_end_point = None

    # Processar cada nó
    for node in nodes:
        last_block = basic_block_list[basic_block_index]

        # Ignorar docstrings Python
        if is_docstring_node(node):
            continue

        # Se o bloco anterior terminou com terminador, inicia novo bloco
        if (
            split_after_terminator
            and len(last_block) > 0
            and (terminator_statement_end_point is None or node.start_point >= terminator_statement_end_point)
        ):
            basic_block_list.append([])
            basic_block_index = basic_block_index + 1
            last_block = basic_block_list[basic_block_index]
            split_after_terminator = False
            terminator_statement_end_point = None

        # Lógica de divisão de blocos
        if len(last_block) > 0 and node.type in branch:
            should_split = True
            conditional_chain = is_conditional_chain_node(node, language)

            # Exception 1: else if não divide bloco
            if node.type == "if_statement" and len(last_block) > 0 and last_block[-1][0] == "else":
                should_split = False

            # Exception 1.1: cadeia condicional (if/elif/else if/else) não divide
            if conditional_chain:
                should_split = False

            # Exception 2: case sem break (fall-through) não divide
            elif node.type == "case_statement" and len(last_block) > 0:
                is_prev_case = last_block[0][0] == "case"
                has_break = last_block[-1][0] == "break"
                if is_prev_case and not has_break:
                    should_split = False

            # Criar novo bloco se deve dividir ou há gap temporal
            if should_split or (not conditional_chain and basic_block_branch_end_point < node.start_point):
                basic_block_list.append([])
                basic_block_index = basic_block_index + 1
                basic_block_branch_end_point = node.end_point

        # Capturar token se é tipo relevante
        if node.type in arithmetic + assignment + bitwise + comparison + logical + word + types:
            token_text = preprocessor(str(node.text, "utf-8"))
            basic_block_list[basic_block_index].append((node.type, token_text, node.start_point, node.end_point))

            # Terminadores encerram o bloco atual; próximo token inicia novo bloco
            if token_text in terminators:
                split_after_terminator = True
                terminator_statement_end_point = get_terminator_statement_end_point(node, language)

    return basic_block_list


def parse_input(filename, language):
    """Parse nó arquivo e retorna blocos básicos"""
    point2tuple = lambda point: (point.row, point.column)
    corpus = []

    with open(filename) as file:
        data = file.read()

    language_obj, lang_name = get_language_parser(language)
    parser = Parser(language_obj)
    tree = parser.parse(bytes(data, "utf8"))
    nodes = traverse(tree)
    basic_blocks = basic_block(nodes, language)

    # Converter blocos em corpus
    for block in basic_blocks:
        if len(block) > 0:
            sentence = [token[1] for token in block]
            corpus.append([sentence, point2tuple(block[0][2]), point2tuple(block[-1][3])])

    return corpus


def detect_language(filename):
    """Detecta linguagem pela extensão do arquivo"""
    _, ext = os.path.splitext(filename)
    ext = ext.lstrip('.').lower()

    if ext in ("c",):
        return "c"
    elif ext in ("cpp", "cc", "cxx", "c++"):
        return "cpp"
    elif ext in ("py",):
        return "python"
    else:
        return None


def main(argv):
    """Processa diretório, detectando C, C++ e Python automaticamente"""
    if len(argv) != 2:
        print("usage: " + argv[0] + " <directory>")
        exit(1)

    directory = argv[1]
    consolidated = {}

    # Processar todos os arquivos C, C++ e Python
    for language in ("c", "cpp", "python"):
        pattern = os.path.join(directory, f"*.{language if language != 'python' else 'py'}")
        for source in glob.glob(pattern):
            detected_lang = detect_language(source)
            if detected_lang is None:
                continue

            print(f"parsing {source}", flush=True)
            corpus = parse_input(source, detected_lang)
            consolidated[source] = corpus

    # Consolidar em arquivos JSON por basename
    written_files = set()
    for source, corpus in consolidated.items():
        basename, _ = os.path.splitext(source)
        json_file = basename + ".json"

        # Carregar dados existentes se arquivo já existe
        file_data = {}
        if os.path.exists(json_file):
            with open(json_file, "r") as f:
                file_data = json.load(f)

        # Atualizar com resultado atual
        file_data[source] = corpus

        # Salvar dados consolidados
        with open(json_file, "w") as f:
            json.dump(file_data, f)

        written_files.add(json_file)


if __name__ == "__main__":
    main(sys.argv)

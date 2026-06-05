from pathlib import Path
import json
import csv
import argparse
from difflib import SequenceMatcher
import difflib


# =========================================================
# CONFIG
# =========================================================

DEFAULT_ORIGINAL_DIR = "Original"
DEFAULT_OBFUSCATED_DIR = "Obfuscated"

DEFAULT_DIFF_DIR = "diffs"

DEFAULT_CSV_OUTPUT = "similarity_report.csv"

# qualquer similaridade > 0
MIN_SIMILARITY = 0.0


# =========================================================
# PREPARAÇÃO
# =========================================================

csv_rows = []


# =========================================================
# HELPERS
# =========================================================

def load_json(path):

    with open(
        path,
        "r",
        encoding="utf-8"
    ) as f:

        return json.load(f)


def load_source(path):

    with open(
        path,
        "r",
        encoding="utf-8"
    ) as f:

        return f.read().splitlines()


def normalize_text(text):

    if not isinstance(text, str):
        text = str(text)

    text = text.replace(
        "ReplacementFor_",
        ""
    )

    text = text.replace("\n", " ")
    text = text.replace("\t", " ")

    text = " ".join(
        text.split()
    )

    return text.lower()


def normalize_tokens(tokens):

    normalized = []

    for token in tokens:

        token = normalize_text(
            token
        )

        if token:
            normalized.append(
                token
            )

    return normalized


def similarity(a, b):

    return SequenceMatcher(
        None,
        a,
        b
    ).ratio()


def find_source_file(
    source_root,
    base_path_without_extension
):

    extensions = [
        ".c",
        ".cpp",
        ".cc",
        ".py",
        ".java"
    ]

    for ext in extensions:

        candidate = Path(
            source_root
        ) / Path(
            str(
                base_path_without_extension
            ) + ext
        )

        if candidate.exists():
            return candidate

    return None


def extract_source_code(
    source_lines,
    start_line,
    end_line
):

    start_idx = max(
        0,
        start_line - 1
    )

    end_idx = min(
        len(source_lines),
        end_line
    )

    return source_lines[
        start_idx:end_idx
    ]


# =========================================================
# COLUNA APROXIMADA
# =========================================================

def first_non_space_column(line):

    if not line:
        return 1

    stripped = line.lstrip()

    if not stripped:
        return 1

    return (
        len(line)
        - len(stripped)
        + 1
    )


# =========================================================
# UNIFIED DIFF
# =========================================================

def build_unified_block(

    original_lines,
    obfuscated_lines,

    original_path,
    obfuscated_path,

    original_start_line,
    obfuscated_start_line,

    similarity_score
):

    original_count = max(
        1,
        len(original_lines)
    )

    obfuscated_count = max(
        1,
        len(obfuscated_lines)
    )

    original_col = 1
    obfuscated_col = 1

    if original_lines:

        original_col = (
            first_non_space_column(
                original_lines[0]
            )
        )

    if obfuscated_lines:

        obfuscated_col = (
            first_non_space_column(
                obfuscated_lines[0]
            )
        )

    similarity_percent = (
        similarity_score * 100.0
    )

    result = []

    result.append(
        f"--- {original_path}\t"
        f"{original_start_line}:{original_col}"
    )

    result.append(
        f"+++ {obfuscated_path}\t"
        f"{obfuscated_start_line}:{obfuscated_col}"
    )

    # mostra só a similaridade no visualizador
    result.append(
        f"@@ "
        f"-{original_start_line},{original_count} "
        f"+{obfuscated_start_line},{obfuscated_count} "
        f"@@ "
        f"{similarity_percent:.2f}%"
    )

    diff_lines = list(

        difflib.unified_diff(

            original_lines,
            obfuscated_lines,

            lineterm=""
        )
    )

    for line in diff_lines:

        if (
            line.startswith("---")
            or line.startswith("+++")
            or line.startswith("@@")
        ):
            continue

        result.append(line)

    # evita hunk vazio
    if len(result) == 3:

        if original_lines:

            result.append(
                " " + original_lines[0]
            )

        else:

            result.append(" ")

    return "\n".join(result)


# =========================================================
# PARSE DOS BLOCOS
# =========================================================

def extract_blocks(parsed_json):

    blocks = []

    for _, block_list in parsed_json.items():

        if not isinstance(
            block_list,
            list
        ):
            continue

        for idx, block in enumerate(
            block_list
        ):

            if (
                not isinstance(block, list)
                or len(block) < 3
            ):
                continue

            tokens = block[0]

            start = block[1]
            end = block[2]

            normalized = " ".join(

                normalize_tokens(
                    tokens
                )
            )

            start_line = (
                start[0] + 1
            )

            end_line = (
                end[0] + 1
            )

            start_col = 1
            end_col = 1

            if len(start) > 1:

                start_col = (
                    start[1] + 1
                )

            if len(end) > 1:

                end_col = (
                    end[1] + 1
                )

            blocks.append({

                "index": idx,

                "tokens": tokens,

                "normalized": normalized,

                "start_line": start_line,
                "end_line": end_line,

                "start_col": start_col,
                "end_col": end_col
            })

    return blocks


# =========================================================
# PROCESSAMENTO
# =========================================================

parser = argparse.ArgumentParser(
    description=(
        "Compara JSONs de blocos básicos e os arquivos-fonte "
        "associados entre duas árvores de diretórios."
    )
)

parser.add_argument(
    "original_dir",
    nargs="?",
    default=DEFAULT_ORIGINAL_DIR,
    help=(
        "Diretório raiz com os JSONs e fontes da versão original. "
        f"Padrão: {DEFAULT_ORIGINAL_DIR}"
    )
)

parser.add_argument(
    "obfuscated_dir",
    nargs="?",
    default=DEFAULT_OBFUSCATED_DIR,
    help=(
        "Diretório raiz com os JSONs e fontes da versão ofuscada. "
        f"Padrão: {DEFAULT_OBFUSCATED_DIR}"
    )
)

parser.add_argument(
    "--diff-dir",
    default=DEFAULT_DIFF_DIR,
    help=(
        "Diretório de saída para os arquivos .diff. "
        f"Padrão: {DEFAULT_DIFF_DIR}"
    )
)

parser.add_argument(
    "--csv-output",
    default=DEFAULT_CSV_OUTPUT,
    help=(
        "Arquivo CSV de saída com o resumo da similaridade. "
        f"Padrão: {DEFAULT_CSV_OUTPUT}"
    )
)

parser.add_argument(
    "--original-source-dir",
    default=None,
    help=(
        "Diretório raiz dos arquivos-fonte da versão original. "
        "Se omitido, usa original_dir."
    )
)

parser.add_argument(
    "--obfuscated-source-dir",
    default=None,
    help=(
        "Diretório raiz dos arquivos-fonte da versão ofuscada. "
        "Se omitido, usa obfuscated_dir."
    )
)

args = parser.parse_args()

ORIGINAL_DIR = args.original_dir
OBFUSCATED_DIR = args.obfuscated_dir
DIFF_DIR = args.diff_dir
CSV_OUTPUT = args.csv_output
ORIGINAL_SOURCE_DIR = args.original_source_dir or ORIGINAL_DIR
OBFUSCATED_SOURCE_DIR = args.obfuscated_source_dir or OBFUSCATED_DIR

Path(DIFF_DIR).mkdir(
    exist_ok=True
)

all_original_jsons = sorted(

    Path(
        ORIGINAL_DIR
    ).rglob("*.json")
)

for original_json_path in all_original_jsons:

    relative_path = (
        original_json_path.relative_to(
            ORIGINAL_DIR
        )
    )

    obfuscated_json_path = (
        Path(OBFUSCATED_DIR)
        / relative_path
    )

    if not obfuscated_json_path.exists():

        print(
            f"[JSON NÃO ENCONTRADO] "
            f"{relative_path}"
        )

        continue

    # =====================================================
    # SOURCE FILES
    # =====================================================

    original_source_path = (
        find_source_file(
            ORIGINAL_SOURCE_DIR,
            original_json_path.relative_to(
                ORIGINAL_DIR
            ).with_suffix("")
        )
    )

    obfuscated_source_path = (
        find_source_file(
            OBFUSCATED_SOURCE_DIR,
            obfuscated_json_path.relative_to(
                OBFUSCATED_DIR
            ).with_suffix("")
        )
    )

    if (
        original_source_path is None
        or obfuscated_source_path is None
    ):

        print(
            f"[SOURCE NÃO ENCONTRADO] "
            f"{relative_path}"
        )

        continue

    print(
        f"\nProcessando: "
        f"{relative_path}"
    )

    # =====================================================
    # LOAD JSON
    # =====================================================

    try:

        original_json = load_json(
            original_json_path
        )

        obfuscated_json = load_json(
            obfuscated_json_path
        )

    except Exception as e:

        print(
            f"[ERRO JSON] "
            f"{relative_path}"
        )

        print(e)

        continue

    # =====================================================
    # LOAD SOURCE
    # =====================================================

    try:

        original_source = load_source(
            original_source_path
        )

        obfuscated_source = load_source(
            obfuscated_source_path
        )

    except Exception as e:

        print(
            f"[ERRO SOURCE] "
            f"{relative_path}"
        )

        print(e)

        continue

    # =====================================================
    # EXTRACT BLOCKS
    # =====================================================

    original_blocks = extract_blocks(
        original_json
    )

    obfuscated_blocks = extract_blocks(
        obfuscated_json
    )

    # =====================================================
    # MATCHING 1 -> 1
    # =====================================================

    matches = []
    used_obfuscated = set()

    # Loop nos blocos originais
    for original_block in original_blocks:
        best_score = -1.0
        best_block = None
        original_text = original_block["normalized"]

        for obfuscated_block in obfuscated_blocks:
            if obfuscated_block["index"] in used_obfuscated:
                continue

            obfuscated_text = obfuscated_block["normalized"]
            score = similarity(original_text, obfuscated_text)

            if score > best_score:
                best_score = score
                best_block = obfuscated_block

        if best_block is not None and best_score > MIN_SIMILARITY:
            used_obfuscated.add(best_block["index"])
            matches.append({
                "original": original_block,
                "obfuscated_block": best_block,
                "similarity": best_score
            })
        else:
            # ORIGINAL SEM MATCH: é adicionado com score 0.0
            matches.append({
                "original": original_block,
                "obfuscated_block": None,
                "similarity": 0.0
            })

    # Loop para capturar blocos ofuscados que sobraram
    for obfuscated_block in obfuscated_blocks:
        if obfuscated_block["index"] not in used_obfuscated:
            # OFUSCADO SEM MATCH: é adicionado com score 0.0
            matches.append({
                "original": None,
                "obfuscated_block": obfuscated_block,
                "similarity": 0.0
            })

    # =====================================================
    # ORDENA
    # =====================================================

    matches.sort(

        key=lambda x: (
            x["similarity"]
        ),

        reverse=True
    )

    # =====================================================
    # SIMILARIDADE FINAL
    # =====================================================

    average_similarity = 0.0

    if matches:

        average_similarity = (

            sum(

                m["similarity"]

                for m in matches
            )

            /

            len(matches)
        )

    # =====================================================
    # OUTPUT
    # =====================================================

    result_lines = []

    for m in matches:
        original_block = m["original"]
        obfuscated_block = m["obfuscated_block"]
        similarity_score = m["similarity"]

        # Se houver bloco original, extrai o código normalmente, senão define padrões vazios
        if original_block:
            original_lines = extract_source_code(
                original_source,
                original_block["start_line"],
                original_block["end_line"]
            )
            orig_path = original_source_path.name
            orig_start = original_block["start_line"]
        else:
            original_lines = []
            orig_path = "Inexistente"
            orig_start = 0

        # Se houver bloco ofuscado, extrai o código normalmente, senão define padrões vazios
        if obfuscated_block:
            obfuscated_lines = extract_source_code(
                obfuscated_source,
                obfuscated_block["start_line"],
                obfuscated_block["end_line"]
            )
            obf_path = obfuscated_source_path.name
            obf_start = obfuscated_block["start_line"]
        else:
            obfuscated_lines = []
            obf_path = "Inexistente"
            obf_start = 0

        unified = build_unified_block(
            original_lines=original_lines,
            obfuscated_lines=obfuscated_lines,
            original_path=orig_path,
            obfuscated_path=obf_path,
            original_start_line=orig_start,
            obfuscated_start_line=obf_start,
            similarity_score=similarity_score
        )

        result_lines.append(unified)
        result_lines.append("")
    # =====================================================
    # SAVE DIFF
    # =====================================================

    diff_output_path = (

        Path(DIFF_DIR)

        / relative_path.with_suffix(
            ".diff"
        )
    )

    diff_output_path.parent.mkdir(

        parents=True,
        exist_ok=True
    )

    with open(

        diff_output_path,

        "w",

        encoding="utf-8"

    ) as f:

        f.write(
            "\n".join(result_lines)
        )

    # =====================================================
    # CSV
    # =====================================================

    csv_rows.append({

        "file": str(relative_path),

        "similarity": (
            f"{average_similarity:.4f}"
        ),

        "matches": len(matches),

        "original_blocks": (
            len(original_blocks)
        ),

        "obfuscated_blocks": (
            len(obfuscated_blocks)
        )
    })

    print(

        f"[OK] {relative_path} | "

        f"Similarity: "
        f"{average_similarity:.4f}"
    )

# =========================================================
# SAVE CSV
# =========================================================

with open(

    CSV_OUTPUT,

    "w",

    newline="",

    encoding="utf-8"

) as csvfile:

    fieldnames = [

        "file",

        "similarity",

        "matches",

        "original_blocks",

        "obfuscated_blocks"
    ]

    writer = csv.DictWriter(

        csvfile,

        fieldnames=fieldnames
    )

    writer.writeheader()

    for row in csv_rows:

        writer.writerow(row)

print(
    "\nCSV salvo:",
    CSV_OUTPUT
)

print("\nFinalizado.")

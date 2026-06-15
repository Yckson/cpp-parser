from pathlib import Path
import json
import csv
import re
from difflib import SequenceMatcher
import difflib


# =========================================================
# CONFIG
# =========================================================

ORIGINAL_DIR = "Original"
OBFUSCATED_DIR = "Obfuscated"

DIFF_DIR = "diffs"

CSV_OUTPUT = "similarity_report.csv"

# qualquer similaridade > 0
MIN_SIMILARITY = 0.0


# =========================================================
# PREPARAÇÃO
# =========================================================

Path(DIFF_DIR).mkdir(
    exist_ok=True
)

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

    text = text.lower()

    # remove prefixos da ofuscação
    text = text.replace(
        "replacementfor_",
        ""
    )

    # remove quebras/tabulações
    text = text.replace("\n", " ")
    text = text.replace("\t", " ")

    # remove hexadecimais
    text = re.sub(
        r'0x[a-f0-9]+',
        ' ',
        text
    )

    # remove números
    text = re.sub(
        r'\d+',
        ' ',
        text
    )

    # remove símbolos excessivos
    text = re.sub(
        r'[^a-z_]',
        ' ',
        text
    )

    # remove espaços duplicados
    text = " ".join(
        text.split()
    )

    return text


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


def build_unified_block(

    original_lines,
    obfuscated_lines,

    original_start_line,
    obfuscated_start_line,

    block_similarity
):

    result = []

    original_count = max(
        1,
        len(original_lines)
    )

    obfuscated_count = max(
        1,
        len(obfuscated_lines)
    )

    result.append(
        f"@@ "
        f"-{original_start_line},{original_count} "
        f"+{obfuscated_start_line},{obfuscated_count} "
        f"@@"
    )

    # =====================================================
    # SE O BLOCO JÁ TEVE MATCH (> 0)
    # ENTÃO TODO O BLOCO É CONSIDERADO IGUAL
    # =====================================================

    if block_similarity > 0:

        for line in original_lines:

            result.append(
                " " + line.replace(
                    "\r",
                    ""
                )
            )

        if not original_lines:
            result.append(" ")

        return "\n".join(result)

    # =====================================================
    # BLOCO SEM MATCH
    # =====================================================

    has_content = False

    for line in original_lines:

        result.append(
            "-" + line.replace(
                "\r",
                ""
            )
        )

        has_content = True

    for line in obfuscated_lines:

        result.append(
            "+" + line.replace(
                "\r",
                ""
            )
        )

        has_content = True

    if not has_content:

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
            original_json_path.with_suffix("")
        )
    )

    obfuscated_source_path = (
        find_source_file(
            obfuscated_json_path.with_suffix("")
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

        original_text = (
            original_block["normalized"]
        )

        for obfuscated_block in obfuscated_blocks:

            if (
                obfuscated_block["index"]
                in used_obfuscated
            ):
                continue

            obfuscated_text = (
                obfuscated_block["normalized"]
            )

            score = similarity(
                original_text,
                obfuscated_text
            )

            if score > best_score:

                best_score = score
                best_block = obfuscated_block

        if (
            best_block is not None
            and best_score > MIN_SIMILARITY
        ):

            used_obfuscated.add(
                best_block["index"]
            )

            matches.append({

                "original": original_block,
                "obfuscated_block": best_block,
                "similarity": best_score
            })

        else:

            matches.append({

                "original": original_block,
                "obfuscated_block": None,
                "similarity": 0.0
            })

    # blocos obfuscados sem match
    for obfuscated_block in obfuscated_blocks:

        if (
            obfuscated_block["index"]
            not in used_obfuscated
        ):

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

            x["original"]["start_line"]
            if x["original"] is not None
            else (

                x["obfuscated_block"]["start_line"]

                if x["obfuscated_block"] is not None

                else 999999999
            ),

            x["obfuscated_block"]["start_line"]

            if x["obfuscated_block"] is not None

            else 999999999
        )
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

    # HEADER GLOBAL ÚNICO
    result_lines.append(
        f"--- {original_source_path.name}"
    )

    result_lines.append(
        f"+++ {obfuscated_source_path.name}"
    )

    for m in matches:

        original_block = m["original"]
        obfuscated_block = m["obfuscated_block"]

        # ORIGINAL
        if original_block:

            original_lines = extract_source_code(

                original_source,

                original_block["start_line"],
                original_block["end_line"]
            )

            orig_start = (
                original_block["start_line"]
            )

        else:

            original_lines = []
            orig_start = 1

        # OBFUSCADO
        if obfuscated_block:

            obfuscated_lines = extract_source_code(

                obfuscated_source,

                obfuscated_block["start_line"],
                obfuscated_block["end_line"]
            )

            obf_start = (
                obfuscated_block["start_line"]
            )

        else:

            obfuscated_lines = []
            obf_start = 1
        unified = build_unified_block(

            original_lines=original_lines,

            obfuscated_lines=obfuscated_lines,

            original_start_line=orig_start,

            obfuscated_start_line=obf_start,

            block_similarity=m["similarity"]
        )

        result_lines.append(
            unified
        )

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

        encoding="utf-8",
        newline="\n"

    ) as f:

        f.write(
            "\n".join(result_lines) + "\n"
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

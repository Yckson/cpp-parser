from pathlib import Path
import json
import csv
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

                best_block = (
                    obfuscated_block
                )

        if (
            best_block is not None
            and best_score > MIN_SIMILARITY
        ):

            used_obfuscated.add(
                best_block["index"]
            )

            matches.append({

                "original": original_block,

                "obfuscated_block": (
                    best_block
                ),

                "similarity": best_score
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

        original_block = (
            m["original"]
        )

        obfuscated_block = (
            m["obfuscated_block"]
        )

        similarity_score = (
            m["similarity"]
        )

        original_lines = (
            extract_source_code(

                original_source,

                original_block[
                    "start_line"
                ],

                original_block[
                    "end_line"
                ]
            )
        )

        obfuscated_lines = (
            extract_source_code(

                obfuscated_source,

                obfuscated_block[
                    "start_line"
                ],

                obfuscated_block[
                    "end_line"
                ]
            )
        )

        unified = build_unified_block(

            original_lines=original_lines,

            obfuscated_lines=(
                obfuscated_lines
            ),

            original_path=(
                original_source_path.name
            ),

            obfuscated_path=(
                obfuscated_source_path.name
            ),

            original_start_line=(
                original_block[
                    "start_line"
                ]
            ),

            obfuscated_start_line=(
                obfuscated_block[
                    "start_line"
                ]
            ),

            similarity_score=(
                similarity_score
            )
        )

        result_lines.append(
            unified
        )

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

from pathlib import Path
import difflib
import json
import csv
from difflib import SequenceMatcher


# =========================================
# PASTAS
# =========================================

ORIGINAL_DIR = "Original"
OBFUSCATED_DIR = "Obfuscated"

DIFF_DIR = "diffs"
CSV_OUTPUT = "similaridades.csv"


# cria pasta diffs automaticamente
Path(DIFF_DIR).mkdir(exist_ok=True)


# =========================================
# CARREGA JSON
# =========================================

def load_json(path):

    with open(path, "r", encoding="utf-8") as f:
        obj = json.load(f)

    return json.dumps(
        obj,
        indent=2,
        sort_keys=True,
        ensure_ascii=False
    )


# =========================================
# CARREGA SOURCE CODE
# =========================================

def load_source(path):

    with open(
        path,
        "r",
        encoding="utf-8",
        errors="ignore"
    ) as f:

        return f.read().splitlines()


# =========================================
# CSV
# =========================================

csv_rows = []


# =========================================
# PROCESSA JSONS
# =========================================

for original_json_path in Path(ORIGINAL_DIR).rglob("*.json"):

    # caminho relativo dentro de Original/
    relative_path = original_json_path.relative_to(
        ORIGINAL_DIR
    )

    # JSON correspondente no Obfuscated/
    obfuscated_json_path = (
        Path(OBFUSCATED_DIR) / relative_path
    )

    if not obfuscated_json_path.exists():

        print(
            f"[NÃO ENCONTRADO] {relative_path}"
        )

        continue

    # =====================================
    # SIMILARIDADE VIA JSON
    # =====================================

    original_json = load_json(
        original_json_path
    )

    obfuscated_json = load_json(
        obfuscated_json_path
    )

    similarity = SequenceMatcher(
        None,
        original_json,
        obfuscated_json
    ).ratio()

    # =====================================
    # DESCOBRE SOURCE CODE
    # =====================================

    source_stem = original_json_path.stem

    possible_extensions = [
        ".c",
        ".cpp",
        ".py"
    ]

    original_source_path = None
    obfuscated_source_path = None

    for ext in possible_extensions:

        candidate_original = (
            original_json_path.parent
            / f"{source_stem}{ext}"
        )

        candidate_obfuscated = (
            obfuscated_json_path.parent
            / f"{source_stem}{ext}"
        )

        if (
            candidate_original.exists()
            and
            candidate_obfuscated.exists()
        ):

            original_source_path = (
                candidate_original
            )

            obfuscated_source_path = (
                candidate_obfuscated
            )

            break

    # =====================================
    # NÃO ENCONTROU SOURCE
    # =====================================

    if (
        original_source_path is None
        or
        obfuscated_source_path is None
    ):

        print(
            f"[SEM SOURCE] {relative_path}"
        )

        continue

    # =====================================
    # LEITURA DOS SOURCES
    # =====================================

    original_source = load_source(
        original_source_path
    )

    obfuscated_source = load_source(
        obfuscated_source_path
    )

    # =====================================
    # DIFF VISUAL DO CÓDIGO-FONTE
    # =====================================

    diff = difflib.unified_diff(
        original_source,
        obfuscated_source,
        fromfile=str(original_source_path),
        tofile=str(obfuscated_source_path),
        lineterm=""
    )

    diff_lines = list(diff)

    # =====================================
    # RESULTADO FINAL
    # =====================================

    result = [
        f"# Similaridade JSON: "
        f"{similarity:.4f}",
        ""
    ] + diff_lines

    result_text = "\n".join(result)

    # preserva estrutura de subpastas
    diff_output_path = (
        Path(DIFF_DIR)
        / relative_path.with_suffix(".diff")
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

        f.write(result_text)

    # =====================================
    # CSV
    # =====================================

    csv_rows.append([
        str(relative_path),
        f"{similarity:.4f}"
    ])

    # =====================================
    # STATUS
    # =====================================

    print(
        f"[OK] {relative_path} | "
        f"Similaridade JSON: "
        f"{similarity:.4f}"
    )


# =========================================
# GERA CSV
# =========================================

with open(
    CSV_OUTPUT,
    "w",
    newline="",
    encoding="utf-8"
) as csvfile:

    writer = csv.writer(csvfile)

    writer.writerow([
        "arquivo",
        "similaridade_json"
    ])

    writer.writerows(csv_rows)


print(f"\nCSV gerado: {CSV_OUTPUT}")

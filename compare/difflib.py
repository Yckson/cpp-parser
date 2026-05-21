from pathlib import Path
import difflib
import json
import csv
from difflib import SequenceMatcher


ORIGINAL_DIR = "Original"
OBFUSCATED_DIR = "Obfuscated"
DIFF_DIR = "diffs"

CSV_OUTPUT = "similaridades.csv"


# cria pasta diffs automaticamente
Path(DIFF_DIR).mkdir(exist_ok=True)


def load_json(path):

    with open(path, "r", encoding="utf-8") as f:
        obj = json.load(f)

    return json.dumps(
        obj,
        indent=2,
        sort_keys=True,
        ensure_ascii=False
    ).splitlines()


# armazena resultados do CSV
csv_rows = []


# procura JSONs recursivamente nas subpastas
for original_path in Path(ORIGINAL_DIR).rglob("*.json"):

    # caminho relativo dentro de Original/
    relative_path = original_path.relative_to(ORIGINAL_DIR)

    # procura o correspondente em Obfuscated/
    obfuscated_path = Path(OBFUSCATED_DIR) / relative_path

    if not obfuscated_path.exists():
        print(f"[NÃO ENCONTRADO] {relative_path}")
        continue

    original = load_json(original_path)
    obfuscated = load_json(obfuscated_path)

    # =========================
    # SIMILARIDADE
    # =========================

    original_text = "\n".join(original)
    obfuscated_text = "\n".join(obfuscated)

    similarity = SequenceMatcher(
        None,
        original_text,
        obfuscated_text
    ).ratio()

    # =========================
    # DIFF
    # =========================

    diff = difflib.unified_diff(
        original,
        obfuscated,
        fromfile=str(original_path),
        tofile=str(obfuscated_path),
        lineterm=""
    )

    diff_lines = list(diff)

    # adiciona score no topo do arquivo diff
    result = [
        f"# Similaridade: {similarity:.4f}",
        ""
    ] + diff_lines

    result_text = "\n".join(result)

    # preserva estrutura de subpastas em diffs/
    diff_output_path = Path(DIFF_DIR) / relative_path.with_suffix(".diff")

    # cria subpastas automaticamente
    diff_output_path.parent.mkdir(parents=True, exist_ok=True)

    with open(diff_output_path, "w", encoding="utf-8") as f:
        f.write(result_text)

    # =========================
    # CSV
    # =========================

    csv_rows.append([
        str(relative_path),
        f"{similarity:.4f}"
    ])

    # =========================
    # STATUS
    # =========================

    if diff_lines:
        print(
            f"[FALHOU] {relative_path} | "
            f"Similaridade: {similarity:.4f}"
        )
    else:
        print(
            f"[OK] {relative_path} | "
            f"Similaridade: {similarity:.4f}"
        )


# =========================
# GERA CSV
# =========================

with open(CSV_OUTPUT, "w", newline="", encoding="utf-8") as csvfile:

    writer = csv.writer(csvfile)

    writer.writerow([
        "arquivo",
        "similaridade"
    ])

    writer.writerows(csv_rows)


print(f"\nCSV gerado: {CSV_OUTPUT}")

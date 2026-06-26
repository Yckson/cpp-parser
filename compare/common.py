from pathlib import Path
import argparse
import csv
import difflib
import json
import re

from difflib import SequenceMatcher


DEFAULT_ORIGINAL_DIR = "Original"
DEFAULT_OBFUSCATED_DIR = "Obfuscated"
DEFAULT_DIFF_DIR = "diffs"
DEFAULT_CSV_OUTPUT = "similarity_report.csv"

MIN_SIMILARITY = 0.0


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


def build_unified_block(
    original_lines,
    obfuscated_lines,
    original_start_line,
    obfuscated_start_line,
    block_similarity
):

    result = []
    
    orig_clean = [line.replace("\r", "") for line in original_lines]
    obf_clean = [line.replace("\r", "") for line in obfuscated_lines]

    original_count = max(
        1,
        len(orig_clean)
    )

    obfuscated_count = max(
        1,
        len(obf_clean)
    )

    similarity_percent = block_similarity * 100.0

    result.append(
        f"@@ "
        f"-{original_start_line},{original_count} "
        f"+{obfuscated_start_line},{obfuscated_count} "
        f"@@ {similarity_percent:.2f}%"
    )

    # Se o bloco já teve match (> 0)
    # Mostra a diferença EXATA dentro do bloco pareado usando difflib
    if block_similarity > 0:

        diff_lines = list(
            difflib.unified_diff(
                orig_clean,
                obf_clean,
                n=99999,  # Força a inclusão de todas as linhas do bloco
                lineterm=""
            )
        )

        if not diff_lines:
            # Identicos até nos espaços e letras maísculas
            for line in orig_clean:
                result.append(" " + line)

            if not orig_clean:
                result.append(" ")
        else:
            # Pula os cabeçalhos internos do difflib ('---', '+++', '@@')
            for line in diff_lines[3:]:
                result.append(line)

        return "\n".join(result)

    # Bloco sem match
    has_content = False

    for line in orig_clean:
        result.append("-" + line)
        has_content = True

    for line in obf_clean:
        result.append("+" + line)
        has_content = True

    if not has_content:
        result.append(" ")

    return "\n".join(result)


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

            normalized_tokens = normalize_tokens(
                tokens
            )

            blocks.append({
                "index": idx,
                "tokens": tokens,
                "normalized_tokens": normalized_tokens,
                "normalized": " ".join(
                    normalized_tokens
                ),
                "start_line": start[0] + 1,
                "end_line": end[0] + 1,
                "start_col": (start[1] + 1) if len(start) > 1 else 1,
                "end_col": (end[1] + 1) if len(end) > 1 else 1,
            })

    return blocks


def iter_original_json_paths(original_dir):

    return sorted(
        Path(original_dir).rglob("*.json")
    )


def collect_existing_json_pairs(original_dir, obfuscated_dir):

    pairs = []

    for original_json_path in iter_original_json_paths(
        original_dir
    ):

        relative_path = original_json_path.relative_to(
            original_dir
        )

        obfuscated_json_path = Path(
            obfuscated_dir
        ) / relative_path

        if obfuscated_json_path.exists():
            pairs.append(
                (
                    relative_path,
                    original_json_path,
                    obfuscated_json_path,
                )
            )

    return pairs


def load_block_token_lists(json_path):

    parsed_json = load_json(
        json_path
    )

    return [
        block["normalized_tokens"]
        for block in extract_blocks(
            parsed_json
        )
    ]


def build_block_corpus(file_pairs):

    corpus = []

    for _, original_json_path, obfuscated_json_path in file_pairs:

        corpus.extend(
            load_block_token_lists(
                original_json_path
            )
        )

        corpus.extend(
            load_block_token_lists(
                obfuscated_json_path
            )
        )

    return corpus


def iter_block_corpus(file_pairs):

    for _, original_json_path, obfuscated_json_path in file_pairs:

        for block_tokens in load_block_token_lists(
            original_json_path
        ):
            yield block_tokens

        for block_tokens in load_block_token_lists(
            obfuscated_json_path
        ):
            yield block_tokens


def build_compare_parser(description):

    parser = argparse.ArgumentParser(
        description=description
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
        dest="diff_dir",
        default=DEFAULT_DIFF_DIR,
        help=(
            "Diretório de saída para os arquivos .diff. "
            f"Padrão: {DEFAULT_DIFF_DIR}"
        )
    )

    parser.add_argument(
        "--csv-output",
        dest="csv_output",
        default=DEFAULT_CSV_OUTPUT,
        help=(
            "Arquivo CSV de saída com o resumo da similaridade. "
            f"Padrão: {DEFAULT_CSV_OUTPUT}"
        )
    )

    parser.add_argument(
        "--original-source-dir",
        dest="original_source_dir",
        default=None,
        help=(
            "Diretório raiz dos arquivos-fonte da versão original. "
            "Se omitido, usa original_dir."
        )
    )

    parser.add_argument(
        "--obfuscated-source-dir",
        dest="obfuscated_source_dir",
        default=None,
        help=(
            "Diretório raiz dos arquivos-fonte da versão ofuscada. "
            "Se omitido, usa obfuscated_dir."
        )
    )

    parser.add_argument(
        "--orig",
        dest="legacy_original_dir",
        default=None,
        help=argparse.SUPPRESS
    )

    parser.add_argument(
        "--obf",
        dest="legacy_obfuscated_dir",
        default=None,
        help=argparse.SUPPRESS
    )

    parser.add_argument(
        "--out",
        dest="legacy_csv_output",
        default=None,
        help=argparse.SUPPRESS
    )

    return parser


def resolve_compare_args(args):

    return {
        "original_dir": args.original_dir or args.legacy_original_dir or DEFAULT_ORIGINAL_DIR,
        "obfuscated_dir": args.obfuscated_dir or args.legacy_obfuscated_dir or DEFAULT_OBFUSCATED_DIR,
        "diff_dir": args.diff_dir or DEFAULT_DIFF_DIR,
        "csv_output": args.csv_output or args.legacy_csv_output or DEFAULT_CSV_OUTPUT,
        "original_source_dir": args.original_source_dir,
        "obfuscated_source_dir": args.obfuscated_source_dir,
    }


def run_compare_pipeline(
    score_block_pair,
    original_dir=DEFAULT_ORIGINAL_DIR,
    obfuscated_dir=DEFAULT_OBFUSCATED_DIR,
    diff_dir=DEFAULT_DIFF_DIR,
    csv_output=DEFAULT_CSV_OUTPUT,
    original_source_dir=None,
    obfuscated_source_dir=None,
):

    original_dir = Path(
        original_dir
    )

    obfuscated_dir = Path(
        obfuscated_dir
    )

    original_source_dir = Path(
        original_source_dir or original_dir
    )

    obfuscated_source_dir = Path(
        obfuscated_source_dir or obfuscated_dir
    )

    Path(
        diff_dir
    ).mkdir(
        exist_ok=True
    )

    csv_rows = []

    for original_json_path in iter_original_json_paths(
        original_dir
    ):

        relative_path = original_json_path.relative_to(
            original_dir
        )

        obfuscated_json_path = (
            obfuscated_dir / relative_path
        )

        if not obfuscated_json_path.exists():

            print(
                f"[JSON NÃO ENCONTRADO] "
                f"{relative_path}"
            )

            continue

        original_source_path = find_source_file(
            original_source_dir,
            original_json_path.relative_to(
                original_dir
            ).with_suffix("")
        )

        obfuscated_source_path = find_source_file(
            obfuscated_source_dir,
            obfuscated_json_path.relative_to(
                obfuscated_dir
            ).with_suffix("")
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

        original_blocks = extract_blocks(
            original_json
        )
        obfuscated_blocks = extract_blocks(
            obfuscated_json
        )

        matches = []
        used_obfuscated = set()

        for original_block in original_blocks:
            best_score = -1.0
            best_block = None

            for obfuscated_block in obfuscated_blocks:
                if obfuscated_block["index"] in used_obfuscated:
                    continue

                score = score_block_pair(
                    original_block["normalized_tokens"],
                    obfuscated_block["normalized_tokens"],
                )

                if score > best_score:
                    best_score = score
                    best_block = obfuscated_block

            if best_block is not None and best_score > MIN_SIMILARITY:
                used_obfuscated.add(
                    best_block["index"]
                )

                matches.append({
                    "original": original_block,
                    "obfuscated_block": best_block,
                    "similarity": best_score,
                })
            else:
                matches.append({
                    "original": original_block,
                    "obfuscated_block": None,
                    "similarity": 0.0,
                })

        for obfuscated_block in obfuscated_blocks:
            if obfuscated_block["index"] not in used_obfuscated:
                matches.append({
                    "original": None,
                    "obfuscated_block": obfuscated_block,
                    "similarity": 0.0,
                })

        # ORDENAÇÃO POR LINHA (do script validado)
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

        average_similarity = 0.0

        if matches:
            average_similarity = (
                sum(
                    m["similarity"]
                    for m in matches
                )
                / len(matches)
            )

        result_lines = []

        # HEADER GLOBAL ÚNICO - AGORA COM CAMINHOS ABSOLUTOS
        result_lines.append(
            f"--- {original_source_path.resolve()}"
        )
        result_lines.append(
            f"+++ {obfuscated_source_path.resolve()}"
        )

        for match in matches:
            original_block = match["original"]
            obfuscated_block = match["obfuscated_block"]
            similarity_score = match["similarity"]

            if original_block:
                original_lines = extract_source_code(
                    original_source,
                    original_block["start_line"],
                    original_block["end_line"],
                )
                original_start = original_block["start_line"]
            else:
                original_lines = []
                original_start = 1

            if obfuscated_block:
                obfuscated_lines = extract_source_code(
                    obfuscated_source,
                    obfuscated_block["start_line"],
                    obfuscated_block["end_line"],
                )
                obfuscated_start = obfuscated_block["start_line"]
            else:
                obfuscated_lines = []
                obfuscated_start = 1

            unified = build_unified_block(
                original_lines=original_lines,
                obfuscated_lines=obfuscated_lines,
                original_start_line=original_start,
                obfuscated_start_line=obfuscated_start,
                block_similarity=similarity_score,
            )

            result_lines.append(
                unified
            )

        diff_output_path = (
            Path(diff_dir)
            / relative_path.with_suffix(
                ".diff"
            )
        )

        diff_output_path.parent.mkdir(
            parents=True,
            exist_ok=True,
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

        csv_rows.append({
            "file": str(relative_path),
            "similarity": f"{average_similarity:.4f}",
            "matches": len(matches),
            "original_blocks": len(original_blocks),
            "obfuscated_blocks": len(obfuscated_blocks),
        })

        print(
            f"[OK] {relative_path} | "
            f"Similarity: {average_similarity:.4f}"
        )

    with open(
        csv_output,
        "w",
        newline="",
        encoding="utf-8",
    ) as csvfile:

        fieldnames = [
            "file",
            "similarity",
            "matches",
            "original_blocks",
            "obfuscated_blocks",
        ]

        writer = csv.DictWriter(
            csvfile,
            fieldnames=fieldnames,
        )

        writer.writeheader()

        for row in csv_rows:
            writer.writerow(row)

    print(
        "\nCSV salvo:",
        csv_output
    )

    print("\nFinalizado.")
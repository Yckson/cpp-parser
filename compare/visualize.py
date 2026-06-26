#!/usr/bin/env python3
"""Gera visualizações leves em PNG a partir dos CSVs e .diff do compare.

O script evita HTML embutindo todo o dataset em uma página pesada.
Em vez disso, produz imagens estáticas e um manifesto com os arquivos criados.

Uso básico:
  python3 compare/visualize.py tmp/py --output-dir tmp/py/visuals

Opções úteis:
  --problem problema_102
  --algorithms 1_diff,3_tfidf
  --file problema_102/source_118431.json
  --mode summary|blocks|both
  --plot-style bar|line
  --reference-csv results_jplag_dolos.csv
"""

from __future__ import annotations

import argparse
import csv
import json
import re
from pathlib import Path
from typing import Any

BLOCK_HEADER_RE = re.compile(
    r"^@@\s+-(\d+)(?:,(\d+))?\s+\+(\d+)(?:,(\d+))?\s+@@\s+([0-9]+(?:\.[0-9]+)?)%$"
)

DEFAULT_OUTPUT_DIR = "visuals"


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(
        description=(
            "Gera gráficos PNG leves para os CSVs de similaridade e os blocos extraídos dos .diff."
        )
    )
    parser.add_argument(
        "input_root",
        help="Diretório raiz com os CSVs e as pastas de .diff, por exemplo tmp/py.",
    )
    parser.add_argument(
        "--output-dir",
        default=DEFAULT_OUTPUT_DIR,
        help=f"Diretório de saída para as imagens. Padrão: {DEFAULT_OUTPUT_DIR}",
    )
    parser.add_argument(
        "--problem",
        default="all",
        help=(
            "Filtra um problema específico, por exemplo problema_102. Use 'all' para todos."
        ),
    )
    parser.add_argument(
        "--algorithms",
        default="all",
        help=(
            "Lista separada por vírgulas com os algoritmos a exibir, usando os nomes dos CSVs sem extensão."
        ),
    )
    parser.add_argument(
        "--file",
        default=None,
        help=(
            "Arquivo relativo para a comparação por blocos, por exemplo problema_102/source_118431.json."
        ),
    )
    parser.add_argument(
        "--mode",
        choices=("summary", "blocks", "both"),
        default="both",
        help="Seleciona o tipo de visualização a gerar.",
    )
    parser.add_argument(
        "--plot-style",
        choices=("bar", "line"),
        default="bar",
        help="Estilo do gráfico de sumário (bar para barras, line para linhas com pontos). Padrão: bar",
    )
    parser.add_argument(
        "--reference-csv",
        default=None,
        help="Arquivo CSV contendo resultados do Jplag e Dolos para adicionar a comparação.",
    )
    return parser


def read_csv_rows(csv_path: Path) -> list[dict[str, str]]:
    with csv_path.open("r", encoding="utf-8", newline="") as handle:
        return [dict(row) for row in csv.DictReader(handle)]


def parse_diff_file(diff_path: Path) -> list[dict[str, Any]]:
    if not diff_path.exists():
        return []

    try:
        raw_text = diff_path.read_text(encoding="utf-8")
    except UnicodeDecodeError:
        raw_text = diff_path.read_text(encoding="latin-1")

    blocks: list[dict[str, Any]] = []
    current_block: dict[str, Any] | None = None

    for line in raw_text.splitlines():
        match = BLOCK_HEADER_RE.match(line)
        if match:
            if current_block is not None:
                blocks.append(current_block)

            original_count = int(match.group(2) or "1")
            obfuscated_count = int(match.group(4) or "1")
            current_block = {
                "original_start": int(match.group(1)),
                "original_count": original_count,
                "obfuscated_start": int(match.group(3)),
                "obfuscated_count": obfuscated_count,
                "similarity": float(match.group(5)),
                "header": line,
                "lines": [line],
            }
            continue

        if current_block is not None:
            current_block["lines"].append(line)

    if current_block is not None:
        blocks.append(current_block)

    for index, block in enumerate(blocks, start=1):
        block["index"] = index
        block["key"] = (
            f"o{block['original_start']}_{block['original_count']}__"
            f"b{block['obfuscated_start']}_{block['obfuscated_count']}"
        )
        block["diff_text"] = "\n".join(block["lines"])
        block.pop("lines", None)

    return blocks


def collect_dataset(input_root: Path) -> dict[str, Any]:
    csv_paths = sorted(input_root.glob("*.csv"))
    algorithms: list[dict[str, Any]] = []
    problems: set[str] = set()
    files: dict[str, dict[str, Any]] = {}

    for csv_path in csv_paths:
        algorithm_id = csv_path.stem
        diff_root = input_root / algorithm_id
        algorithm_files: dict[str, Any] = {}

        for row in read_csv_rows(csv_path):
            relative_file = row.get("file", "")
            if not relative_file:
                continue

            relative_path = Path(relative_file)
            problem = relative_path.parts[0] if relative_path.parts else "sem_problema"
            problems.add(problem)

            similarity = float(row.get("similarity", "0") or 0.0)
            diff_path = diff_root / relative_path.with_suffix(".diff")
            blocks = parse_diff_file(diff_path)

            file_record = {
                "file": relative_file,
                "problem": problem,
                "basename": relative_path.name,
                "similarity": similarity,
                "matches": int(row.get("matches", "0") or 0),
                "original_blocks": int(row.get("original_blocks", "0") or 0),
                "obfuscated_blocks": int(row.get("obfuscated_blocks", "0") or 0),
                "blocks": blocks,
                "diff_path": str(diff_path),
            }

            algorithm_files[relative_file] = file_record

            if relative_file not in files:
                files[relative_file] = {
                    "file": relative_file,
                    "problem": problem,
                    "basename": relative_path.name,
                    "algorithms": {},
                    "block_map": {},
                }

            files[relative_file]["algorithms"][algorithm_id] = file_record

        algorithms.append(
            {
                "id": algorithm_id,
                "label": algorithm_id,
                "csv": csv_path.name,
                "diff_root": diff_root.name,
                "files": algorithm_files,
            }
        )

    for file_record in files.values():
        block_map: dict[str, dict[str, Any]] = {}
        for algorithm_id, algorithm_file in file_record["algorithms"].items():
            for block in algorithm_file.get("blocks", []):
                key = block["key"]
                if key not in block_map:
                    block_map[key] = {
                        "key": key,
                        "original_start": block["original_start"],
                        "original_count": block["original_count"],
                        "obfuscated_start": block["obfuscated_start"],
                        "obfuscated_count": block["obfuscated_count"],
                        "algorithms": {},
                    }
                block_map[key]["algorithms"][algorithm_id] = block

        file_record["block_map"] = block_map
        file_record["block_keys"] = sorted(
            block_map,
            key=lambda block_key: (
                block_map[block_key]["original_start"],
                block_map[block_key]["obfuscated_start"],
                block_key,
            ),
        )

    return {
        "input_root": str(input_root),
        "algorithms": algorithms,
        "files": files,
        "problems": sorted(problems),
    }


def select_algorithms(dataset: dict[str, Any], requested: str) -> list[str]:
    available = [item["id"] for item in dataset["algorithms"]]
    if requested == "all":
        return available

    selected = [item.strip() for item in requested.split(",") if item.strip()]
    missing = [item for item in selected if item not in available]
    if missing:
        raise SystemExit(
            "Algoritmos desconhecidos: " + ", ".join(missing)
        )
    return selected


def ensure_output_dir(output_dir: Path) -> None:
    output_dir.mkdir(parents=True, exist_ok=True)


def problem_suffix(problem: str) -> str:
    return "all" if problem == "all" else problem


def create_summary_plot(
    dataset: dict[str, Any],
    selected_algorithms: list[str],
    problem_filter: str,
    output_path: Path,
    reference_csv: Path | None = None,
    plot_style: str = "bar",
) -> None:
    import matplotlib.pyplot as plt

    files = [
        file_record
        for file_record in dataset["files"].values()
        if problem_filter == "all" or file_record["problem"] == problem_filter
    ]

    files.sort(key=lambda item: item["file"])
    if not files:
        raise SystemExit(
            f"Nenhum arquivo encontrado para o filtro de problema '{problem_filter}'."
        )

    labels = [
        f"{item['problem']}/{item['basename']}"
        if problem_filter == "all"
        else item["basename"]
        for item in files
    ]

    x_positions = list(range(len(files)))
    colors = plt.get_cmap("tab10")

    fig_width = max(14, min(32, len(files) * 0.5 + 8))
    fig, ax = plt.subplots(figsize=(fig_width, 7))

    # Processamento dos resultados de Jplag e Dolos via referência CSV
    ref_map = {}
    if reference_csv and reference_csv.exists():
        with reference_csv.open("r", encoding="utf-8", newline="") as f:
            for row in csv.DictReader(f):
                p_id = str(row.get("Problem ID", "")).strip()
                s_id = str(row.get("Source ID", "")).strip()
                try:
                    dolos_val = float(row.get("Dolos Similarity (%)", 0) or 0.0)
                except ValueError:
                    dolos_val = 0.0
                try:
                    jplag_val = float(row.get("Jplag Similarity (%)", 0) or 0.0)
                except ValueError:
                    jplag_val = 0.0
                ref_map[(p_id, s_id)] = (dolos_val, jplag_val)

    # Construção das séries de dados (Nossas execuções + Dolos + Jplag)
    series_list = []
    
    # 1. Ferramentas do Pipeline (TF-IDF, Diff, SVD, etc)
    for algo_id in selected_algorithms:
        y_vals = []
        for item in files:
            algo_file = item["algorithms"].get(algo_id)
            y_vals.append((algo_file["similarity"] * 100) if algo_file else 0.0)
        series_list.append({"label": algo_id, "values": y_vals})

    # 2. Ferramentas de Referência (se mapeadas no CSV)
    if ref_map:
        dolos_vals = []
        jplag_vals = []
        for item in files:
            # Extrai os números do nome do diretório do problema (ex: 'problema_2' -> '2')
            p_match = re.search(r'\d+', item['problem'])
            # Extrai os números do nome do source (ex: 'source_7.c' -> '7')
            s_match = re.search(r'\d+', item['basename'])
            
            p_id = p_match.group(0) if p_match else ""
            s_id = s_match.group(0) if s_match else ""

            val_d, val_j = ref_map.get((p_id, s_id), (0.0, 0.0))
            dolos_vals.append(val_d)
            jplag_vals.append(val_j)

        series_list.append({"label": "Dolos", "values": dolos_vals})
        series_list.append({"label": "Jplag", "values": jplag_vals})

    num_series = len(series_list)
    bar_width = 0.8 / max(1, num_series)

    for index, series in enumerate(series_list):
        if plot_style == "bar":
            offsets = [x + (index - (num_series - 1) / 2) * bar_width for x in x_positions]
            bars = ax.bar(
                offsets,
                series["values"],
                width=bar_width,
                label=series["label"],
                color=colors(index % 10),
                alpha=0.85,
            )
            # Adiciona a porcentagem no topo de cada barra rotacionada em 90 graus
            for rect in bars:
                height = rect.get_height()
                if height > 0:  # Só exibe se houver algum valor maior que zero para manter o visual limpo
                    ax.annotate(
                        f'{height:.2f}',
                        xy=(rect.get_x() + rect.get_width() / 2, height),
                        xytext=(0, 4),  # 4 pontos de offset vertical
                        textcoords="offset points",
                        ha='center', va='bottom',
                        fontsize=7, rotation=90
                    )
        else:
            ax.plot(
                x_positions,
                series["values"],
                marker="o",
                linewidth=2.0,
                markersize=4.5,
                label=series["label"],
                color=colors(index % 10),
            )
            # Adiciona a porcentagem logo acima dos pontos no gráfico de linhas
            for x, y in zip(x_positions, series["values"]):
                if y > 0:
                    # Pequeno deslocamento lateral para não embolar várias anotações no mesmo X
                    x_offset = (index - (num_series - 1) / 2) * 0.15 
                    ax.annotate(
                        f'{y:.2f}',
                        xy=(x + x_offset, y),
                        xytext=(0, 5),
                        textcoords="offset points",
                        ha='center', va='bottom',
                        fontsize=7, rotation=90
                    )

    ax.set_ylabel("Similaridade (%)")
    ax.set_xlabel("Arquivo")
    ax.set_ylim(0, 115) # Dá um respiro de 15% acima do 100 para a fonte em 90 graus não vazar
    ax.set_title(
        f"Similaridade Comparativa de Ofuscação por Arquivo ({plot_style.capitalize()})"
        + (" - " + problem_filter if problem_filter != "all" else " - todos os problemas")
    )
    ax.set_xticks(x_positions)
    ax.set_xticklabels(labels, rotation=60, ha="right", fontsize=8)
    ax.grid(True, axis="y", alpha=0.25)
    
    # Legenda formatada no rodapé
    ax.legend(loc="upper center", bbox_to_anchor=(0.5, -0.16), ncol=max(1, num_series))
    
    fig.tight_layout()
    fig.savefig(output_path, dpi=150, bbox_inches="tight")
    plt.close(fig)


def create_block_plot(
    file_record: dict[str, Any],
    selected_algorithms: list[str],
    output_path: Path,
) -> None:
    import matplotlib.pyplot as plt

    block_keys = file_record.get("block_keys", [])
    if not block_keys:
        raise SystemExit(
            f"Nenhum bloco .diff encontrado para {file_record['file']}."
        )

    colors = plt.get_cmap("tab10")
    x_positions = list(range(len(block_keys)))
    width = 0.8 / max(1, len(selected_algorithms))

    fig_width = max(14, min(32, len(block_keys) * 0.4 + 8))
    fig, ax = plt.subplots(figsize=(fig_width, 7))

    for index, algorithm_id in enumerate(selected_algorithms):
        y_values = []
        for block_key in block_keys:
            block = file_record["block_map"][block_key]["algorithms"].get(algorithm_id)
            y_values.append((block["similarity"]) if block else 0.0)

        offsets = [x + (index - (len(selected_algorithms) - 1) / 2) * width for x in x_positions]
        bars = ax.bar(
            offsets,
            y_values,
            width=width,
            label=algorithm_id,
            color=colors(index % 10),
            alpha=0.85,
        )
        
        for rect in bars:
            height = rect.get_height()
            if height > 0:
                ax.annotate(
                    f'{height:.2f}',
                    xy=(rect.get_x() + rect.get_width() / 2, height),
                    xytext=(0, 4),
                    textcoords="offset points",
                    ha='center', va='bottom',
                    fontsize=7, rotation=90
                )

    tick_labels = []
    for block_key in block_keys:
        block = file_record["block_map"][block_key]
        tick_labels.append(
            f"{block['original_start']}:{block['original_count']}\n{block['obfuscated_start']}:{block['obfuscated_count']}"
        )

    ax.set_ylabel("Similaridade do bloco (%)")
    ax.set_xlabel("Blocos alinhados pelo intervalo do bloco original")
    ax.set_ylim(0, 115) # Dá um respiro para o texto rotacionado não encostar no topo
    ax.set_title(f"Comparação por blocos - {file_record['problem']}/{file_record['basename']}")
    ax.set_xticks(x_positions)
    ax.set_xticklabels(tick_labels, rotation=0, fontsize=8)
    ax.grid(True, axis="y", alpha=0.25)
    ax.legend(loc="upper center", bbox_to_anchor=(0.5, -0.16), ncol=max(1, len(selected_algorithms)))
    fig.tight_layout()
    fig.savefig(output_path, dpi=150, bbox_inches="tight")
    plt.close(fig)


def write_manifest(manifest_path: Path, payload: dict[str, Any]) -> None:
    manifest_path.write_text(
        json.dumps(payload, ensure_ascii=False, indent=2),
        encoding="utf-8",
    )


def main() -> None:
    args = build_parser().parse_args()
    input_root = Path(args.input_root).resolve()
    if not input_root.exists() or not input_root.is_dir():
        raise SystemExit(f"Diretório de entrada inválido: {input_root}")

    try:
        import matplotlib  # noqa: F401
    except ModuleNotFoundError as exc:
        raise SystemExit(
            "matplotlib não está instalado. Adicione a dependência e instale o requirements.txt antes de usar este visualizador."
        ) from exc

    dataset = collect_dataset(input_root)
    selected_algorithms = select_algorithms(dataset, args.algorithms)
    output_dir = Path(args.output_dir).resolve()
    ensure_output_dir(output_dir)
    
    reference_csv_path = Path(args.reference_csv).resolve() if args.reference_csv else None

    created_files: list[str] = []
    problem_value = args.problem

    if args.mode in {"summary", "both"}:
        summary_name = f"summary_{problem_suffix(problem_value)}.png"
        summary_path = output_dir / summary_name
        create_summary_plot(
            dataset=dataset,
            selected_algorithms=selected_algorithms,
            problem_filter=problem_value,
            output_path=summary_path,
            reference_csv=reference_csv_path,
            plot_style=args.plot_style,
        )
        created_files.append(summary_name)

    block_targets: list[dict[str, Any]] = []
    if args.mode in {"blocks", "both"}:
        if args.file:
            file_record = dataset["files"].get(args.file)
            if file_record is None:
                raise SystemExit(
                    f"Arquivo '{args.file}' não encontrado no dataset de entrada."
                )
            block_targets = [file_record]
        elif problem_value != "all":
            block_targets = [
                file_record
                for file_record in dataset["files"].values()
                if file_record["problem"] == problem_value
            ]
        else:
            raise SystemExit(
                "Para a visualização por blocos, informe --file ou filtre um problema com --problem."
            )

        blocks_dir = output_dir / f"blocks_{problem_suffix(problem_value)}"
        blocks_dir.mkdir(parents=True, exist_ok=True)

        for file_record in sorted(block_targets, key=lambda item: item["file"]):
            block_name = Path(file_record["file"]).with_suffix(".png").name
            block_path = blocks_dir / block_name
            create_block_plot(
                file_record=file_record,
                selected_algorithms=selected_algorithms,
                output_path=block_path,
            )
            created_files.append(str(block_path.relative_to(output_dir)))

    write_manifest(
        output_dir / "manifest.json",
        {
            "input_root": str(input_root),
            "problem": problem_value,
            "file": args.file,
            "algorithms": selected_algorithms,
            "mode": args.mode,
            "plot_style": args.plot_style,
            "created_files": created_files,
        },
    )

    print(f"Visualizações geradas em: {output_dir}")
    for created_file in created_files:
        print(f"- {created_file}")


if __name__ == "__main__":
    main()
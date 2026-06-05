from difflib import SequenceMatcher

from common import (
    build_compare_parser,
    resolve_compare_args,
    run_compare_pipeline,
)


def score_block_pair(original_tokens, obfuscated_tokens):

    return SequenceMatcher(
        None,
        " ".join(original_tokens),
        " ".join(obfuscated_tokens)
    ).ratio()


def main():

    parser = build_compare_parser(
        "Compara diretórios de código usando SequenceMatcher por bloco e o mesmo formato de saída do compare.py."
    )

    args = parser.parse_args()

    options = resolve_compare_args(
        args
    )

    run_compare_pipeline(
        score_block_pair=score_block_pair,
        original_dir=options["original_dir"],
        obfuscated_dir=options["obfuscated_dir"],
        diff_dir=options["diff_dir"],
        csv_output=options["csv_output"],
        original_source_dir=options["original_source_dir"],
        obfuscated_source_dir=options["obfuscated_source_dir"]
    )


if __name__ == "__main__":
    main()
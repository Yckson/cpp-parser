import json
from sklearn.feature_extraction.text import CountVectorizer
from sklearn.metrics.pairwise import cosine_similarity

from common import (
    build_block_corpus,
    build_compare_parser,
    collect_existing_json_pairs,
    resolve_compare_args,
    run_compare_pipeline,
)

def main():
    parser = build_compare_parser(
        "Compara diretórios de código usando Bag of Words por bloco e o mesmo formato de saída do compare.py."
    )

    args = parser.parse_args()

    options = resolve_compare_args(
        args
    )

    file_pairs = collect_existing_json_pairs(
        options["original_dir"],
        options["obfuscated_dir"]
    )

    vectorizer = CountVectorizer(
        analyzer=lambda x: x
    )
    vectorizer.fit(
        build_block_corpus(
            file_pairs
        )
    )

    def score_block_pair(original_tokens, obfuscated_tokens):

        bow_pair = vectorizer.transform(
            [
                original_tokens,
                obfuscated_tokens
            ]
        )

        return float(
            cosine_similarity(
                bow_pair[0:1],
                bow_pair[1:2]
            )[0][0]
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
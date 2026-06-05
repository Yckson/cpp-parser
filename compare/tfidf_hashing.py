from sklearn.feature_extraction.text import HashingVectorizer, TfidfTransformer
from sklearn.metrics.pairwise import cosine_similarity

from common import (
    build_compare_parser,
    collect_existing_json_pairs,
    iter_block_corpus,
    resolve_compare_args,
    run_compare_pipeline,
)
def main():
    parser = build_compare_parser(
        "Compara diretórios de código usando TF-IDF + Hashing por bloco e o mesmo formato de saída do compare.py."
    )

    args = parser.parse_args()

    options = resolve_compare_args(
        args
    )

    file_pairs = collect_existing_json_pairs(
        options["original_dir"],
        options["obfuscated_dir"]
    )

    hash_vectorizer = HashingVectorizer(
        analyzer=lambda x: x,
        n_features=2**20,
        alternate_sign=False,
    )

    matriz_esparsa = hash_vectorizer.transform(
        iter_block_corpus(
            file_pairs
        )
    )

    tfidf = TfidfTransformer()
    tfidf.fit(
        matriz_esparsa
    )

    def score_block_pair(original_tokens, obfuscated_tokens):

        hash_pair = hash_vectorizer.transform(
            [
                original_tokens,
                obfuscated_tokens,
            ]
        )

        tfidf_pair = tfidf.transform(
            hash_pair
        )

        return float(
            cosine_similarity(
                tfidf_pair[0:1],
                tfidf_pair[1:2]
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
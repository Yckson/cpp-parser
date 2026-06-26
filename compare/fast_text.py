import os
import numpy as np
from gensim.models import FastText
from sklearn.metrics.pairwise import cosine_similarity

from common import (
    build_block_corpus,
    build_compare_parser,
    collect_existing_json_pairs,
    resolve_compare_args,
    run_compare_pipeline,
)


def get_averaged_block_vector(tokens, word_vectors, vector_size):
    
    valid_vectors = []
    
    for token in tokens:
        try:
            # O FastText brilha aqui: se o token não existir, ele constrói 
            # um vetor em tempo real analisando os n-gramas (pedaços) da palavra.
            valid_vectors.append(word_vectors[token])
        except KeyError:
            # Uma exceção só ocorrerá se a string for muito bizarra/curta
            # para sequer gerar subpalavras mapeáveis.
            pass
            
    if not valid_vectors:
        return np.zeros(vector_size, dtype=np.float32)
        
    return np.mean(valid_vectors, axis=0).astype(np.float32)


def main():

    parser = build_compare_parser(
        "Compara diretórios de código usando FastText para inferir vetores de palavras desconhecidas (OOV)."
    )

    parser.add_argument(
        "-m",
        "--model-file",
        dest="model_file",
        default="fasttext_codigo_fonte.model",
        help="Caminho para o arquivo do modelo FastText. Se não existir, será criado."
    )

    parser.add_argument(
        "-d",
        "--dim",
        dest="vector_size",
        type=int,
        default=100,
        help="Dimensionalidade dos vetores do FastText (padrão: 100)."
    )

    args = parser.parse_args()
    options = resolve_compare_args(args)
    
    model_path = args.model_file
    vector_size = args.vector_size

    if os.path.exists(model_path):
        print(f"\n[1/2] Carregando modelo FastText existente: {model_path}...")
        
        ft_model = FastText.load(model_path)
        word_vectors = ft_model.wv
        
        actual_size = word_vectors.vector_size
        if actual_size != vector_size:
            print(f"      -> Aviso: Ignorando '--dim {vector_size}'. O modelo carregado possui dimensão {actual_size}.")
            vector_size = actual_size
            
    else:
        print(f"\n[1/2] Modelo '{model_path}' não encontrado. Iniciando treinamento...")
        
        file_pairs = collect_existing_json_pairs(
            options["original_dir"],
            options["obfuscated_dir"]
        )
        
        corpus = build_block_corpus(file_pairs)
        
        if not corpus:
            print("[ERRO] Nenhum bloco de código encontrado para treinar o FastText.")
            return

        print("      -> Treinando a rede neural do FastText (com suporte a n-gramas de caracteres)...")
        
        ft_model = FastText(
            sentences=corpus,
            vector_size=vector_size,
            window=5,
            min_count=1,
            workers=4
        )
        
        print(f"      -> Salvando modelo FastText em formato nativo: {model_path}...")
        # NOTA: Obrigatório salvar em formato nativo (.model). O formato word2vec_format (.bin) 
        # joga fora a matriz de n-gramas e destrói a capacidade de prever palavras inéditas.
        ft_model.save(model_path)
        
        word_vectors = ft_model.wv

    block_vector_cache = {}

    def score_block_pair(original_tokens, obfuscated_tokens):
        
        orig_key = " ".join(original_tokens)
        obf_key = " ".join(obfuscated_tokens)
        
        if orig_key not in block_vector_cache:
            block_vector_cache[orig_key] = get_averaged_block_vector(
                original_tokens, 
                word_vectors, 
                vector_size
            )
            
        if obf_key not in block_vector_cache:
            block_vector_cache[obf_key] = get_averaged_block_vector(
                obfuscated_tokens, 
                word_vectors, 
                vector_size
            )
            
        vec_orig = block_vector_cache[orig_key]
        vec_obf = block_vector_cache[obf_key]
        
        if np.all(vec_orig == 0) or np.all(vec_obf == 0):
            return 0.0
            
        return float(
            cosine_similarity(
                vec_orig.reshape(1, -1), 
                vec_obf.reshape(1, -1)
            )[0][0]
        )

    print("\n[2/2] Iniciando comparação bloco a bloco com FastText...")
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
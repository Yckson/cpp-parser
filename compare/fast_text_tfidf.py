import os
import numpy as np
from gensim.models import FastText
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.metrics.pairwise import cosine_similarity

from common import (
    build_block_corpus,
    build_compare_parser,
    collect_existing_json_pairs,
    resolve_compare_args,
    run_compare_pipeline,
)


def get_averaged_block_vector(tokens, word_vectors, vector_size, idf_dict=None, default_idf=1.0):
    
    valid_vectors = []
    weights = []
    
    for token in tokens:
        try:
            # O FastText brilha aqui: se o token não existir, ele constrói 
            # um vetor em tempo real analisando os n-gramas (pedaços) da palavra.
            vec = word_vectors[token]
            valid_vectors.append(vec)
            
            # Aplicação do peso IDF. A frequência do termo (TF) já é contemplada
            # pelo fato de o token aparecer múltiplas vezes na iteração da lista 'tokens'.
            if idf_dict is not None:
                weight = idf_dict.get(token, default_idf)
                weights.append(weight)
            else:
                weights.append(1.0)
                
        except KeyError:
            # Uma exceção só ocorrerá se a string for muito bizarra/curta
            # para sequer gerar subpalavras mapeáveis.
            pass
            
    if not valid_vectors:
        return np.zeros(vector_size, dtype=np.float32)
        
    # Calcula a média ponderada usando os pesos TF-IDF computados
    return np.average(valid_vectors, axis=0, weights=weights).astype(np.float32)


def main():

    parser = build_compare_parser(
        "Compara diretórios de código usando FastText ponderado por TF-IDF para análise de similaridade."
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

    # 1. Coleta inicial de dados (necessário tanto para treinar FastText quanto TF-IDF)
    file_pairs = collect_existing_json_pairs(
        options["original_dir"],
        options["obfuscated_dir"]
    )
    
    corpus = build_block_corpus(file_pairs)
    
    if not corpus:
        print("[ERRO] Nenhum bloco de código encontrado para treinar os modelos.")
        return

    # 2. Treinamento/Extração do TF-IDF
    print("\n[1/3] Treinando vetorizador TF-IDF para ponderação dos pesos...")
    vectorizer = TfidfVectorizer(analyzer=lambda x: x, dtype=np.float32)
    vectorizer.fit(corpus)
    
    # Cria um dicionário rápido O(1) de token -> idf
    idf_dict = dict(zip(vectorizer.get_feature_names_out(), vectorizer.idf_))
    # Tokens inéditos que não apareceram no treinamento ganham o peso máximo
    default_idf = max(vectorizer.idf_) if len(vectorizer.idf_) > 0 else 1.0

    # 3. Treinamento/Carregamento do FastText
    if os.path.exists(model_path):
        print(f"\n[2/3] Carregando modelo FastText existente: {model_path}...")
        
        ft_model = FastText.load(model_path)
        word_vectors = ft_model.wv
        
        actual_size = word_vectors.vector_size
        if actual_size != vector_size:
            print(f"      -> Aviso: Ignorando '--dim {vector_size}'. O modelo carregado possui dimensão {actual_size}.")
            vector_size = actual_size
            
    else:
        print(f"\n[2/3] Modelo '{model_path}' não encontrado. Iniciando treinamento...")
        print("      -> Treinando a rede neural do FastText (com suporte a n-gramas de caracteres)...")
        
        ft_model = FastText(
            sentences=corpus,
            vector_size=vector_size,
            window=5,
            min_count=1,
            workers=4
        )
        
        print(f"      -> Salvando modelo FastText em formato nativo: {model_path}...")
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
                vector_size,
                idf_dict,
                default_idf
            )
            
        if obf_key not in block_vector_cache:
            block_vector_cache[obf_key] = get_averaged_block_vector(
                obfuscated_tokens, 
                word_vectors, 
                vector_size,
                idf_dict,
                default_idf
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

    print("\n[3/3] Iniciando comparação bloco a bloco com FastText Ponderado (TF-IDF)...")
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
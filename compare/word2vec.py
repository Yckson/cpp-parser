import os
import numpy as np
from gensim.models import Word2Vec
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
        if token in word_vectors:
            valid_vectors.append(word_vectors[token])
            
    if not valid_vectors:
        return np.zeros(vector_size, dtype=np.float32)
        
    return np.mean(valid_vectors, axis=0).astype(np.float32)


def main():

    parser = build_compare_parser(
        "Compara diretórios de código usando Word2Vec (sem pesos TF-IDF) com suporte a modelo nativo."
    )

    parser.add_argument(
        "-m",
        "--model-file",
        dest="model_file",
        default="w2v_codigo_fonte.model",
        help="Caminho para o arquivo do modelo Word2Vec. Se não existir, será criado."
    )

    parser.add_argument(
        "-d",
        "--dim",
        dest="vector_size",
        type=int,
        default=100,
        help="Dimensionalidade dos vetores do Word2Vec (padrão: 100)."
    )

    args = parser.parse_args()
    options = resolve_compare_args(args)
    
    model_path = args.model_file
    vector_size = args.vector_size

    if os.path.exists(model_path):
        print(f"\n[1/2] Carregando modelo Word2Vec nativo existente: {model_path}...")
        
        # Carrega o modelo inteiro utilizando o formato nativo do Gensim
        w2v_model = Word2Vec.load(model_path)
        word_vectors = w2v_model.wv
        
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
            print("[ERRO] Nenhum bloco de código encontrado para treinar o Word2Vec.")
            return

        print("      -> Treinando a rede neural do Word2Vec (Skip-gram/CBOW)...")
        
        w2v_model = Word2Vec(
            sentences=corpus,
            vector_size=vector_size,
            window=5,
            min_count=1,
            workers=4
        )
        
        print(f"      -> Salvando modelo no formato nativo do Gensim em: {model_path}...")
        # Salva utilizando o formato nativo (.model) em vez do formato binário de exportação
        w2v_model.save(model_path)
        
        word_vectors = w2v_model.wv

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

    print("\n[2/2] Iniciando comparação bloco a bloco com Word2Vec...")
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
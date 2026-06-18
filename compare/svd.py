import numpy as np
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.decomposition import TruncatedSVD
from sklearn.metrics.pairwise import cosine_similarity

# Importamos as funções do seu common.py exatamente como no seu script tfidf.py
from common import (
    build_block_corpus,
    build_compare_parser,
    collect_existing_json_pairs,
    resolve_compare_args,
    run_compare_pipeline,
)


def main():

    # 1. Configura o parser reaproveitando a base do seu common.py
    parser = build_compare_parser(
        "Compara diretórios de código usando Análise Semântica Latente (TF-IDF + SVD Truncado)."
    )

    # Injetamos um novo argumento exclusivo para este script
    parser.add_argument(
        "-k",
        "--components",
        type=int,
        default=0,
        help="Número de conceitos latentes (k). Se for 0 ou omitido, o script escolherá o melhor k automaticamente (limiar de 85% de variância)."
    )

    args = parser.parse_args()
    options = resolve_compare_args(args)
    
    k_escolhido_usuario = args.components

    # 2. Coleta de pares e construção do Corpus
    file_pairs = collect_existing_json_pairs(
        options["original_dir"],
        options["obfuscated_dir"]
    )

    corpus = build_block_corpus(file_pairs)
    if not corpus:
        print("[ERRO] Nenhum bloco de código encontrado para treinar o vocabulário.")
        return

    # 3. Etapa 1: Treinamento do TF-IDF (idêntico ao seu anterior)
    print("\n[1/3] Treinando vetorizador TF-IDF...")
    vectorizer = TfidfVectorizer(
        analyzer=lambda x: x,
        dtype=np.float32 # OTIMIZAÇÃO DE MEMÓRIA 1: Reduz a RAM do TF-IDF pela metade
    )
    # Aqui precisamos transformar o corpus inteiro de uma vez para obter a matriz gigante
    # que o SVD vai analisar para entender as relações entre tokens e documentos.
    tfidf_matrix = vectorizer.fit_transform(corpus)
    
    # O máximo que o SVD consegue decompor é o menor valor entre (num_documentos, num_tokens) - 1
    max_possible_k = min(tfidf_matrix.shape) - 1

    # 4. Lógica de Auto-Escolha do 'k'
    print("[2/3] Analisando Semântica Latente (SVD)...")
    if k_escolhido_usuario <= 0:
        print("      -> Avaliando 'k' ideal para reter 85% da informação semântica...")
        
        # OTIMIZAÇÃO DE MEMÓRIA 2: Limite reduzido para 250. 
        # Evita o "Killed" (Estouro de RAM) de matrizes de 1000 dimensões.
        search_k = min(max_possible_k, 250)
        
        if search_k < 1:
            best_k = 1
        else:
            temp_svd = TruncatedSVD(n_components=search_k, random_state=42)
            temp_svd.fit(tfidf_matrix)
            
            # Soma cumulativa da importância de cada conceito
            cum_variance = np.cumsum(temp_svd.explained_variance_ratio_)
            
            # Procura o primeiro índice onde a soma ultrapassa 0.85 (85%)
            target_idx = np.argmax(cum_variance >= 0.85)
            
            if cum_variance[target_idx] >= 0.85:
                best_k = target_idx + 1 # +1 porque o índice em Python começa em 0
            else:
                best_k = search_k # Se não atingiu 85%, usamos o máximo avaliado
        
        print(f"      -> 'k' automático definido como: {best_k}")
        final_k = best_k
    else:
        # Garante que o usuário não passou um k maior que o limite matemático da matriz
        final_k = min(k_escolhido_usuario, max_possible_k)
        if final_k < 1: final_k = 1
        print(f"      -> 'k' definido pelo usuário: {final_k}")

    # 5. Etapa 2: Treinamento e Otimização de Cache O(1)
    svd = TruncatedSVD(n_components=final_k, random_state=42)
    # Treina o modelo e converte o corpus inteiro, forçando float32 para economizar RAM
    lsa_matrix = svd.fit_transform(tfidf_matrix).astype(np.float32) 

    # OTIMIZAÇÃO DE MEMÓRIA 3: Cache inteligente deduplicado com chaves de string (muito mais leve)
    lsa_cache = {}
    for i, tokens in enumerate(corpus):
        key = " ".join(tokens)
        if key not in lsa_cache: # Só aloca memória se o bloco for inédito
            lsa_cache[key] = lsa_matrix[i:i+1]

    # 6. A Função de Comparação Otimizada que a Pipeline usa
    def score_block_pair(original_tokens, obfuscated_tokens):
        # Passo A e B: Transformações custosas substituídas por busca O(1) no dicionário
        orig_key = " ".join(original_tokens)
        obf_key = " ".join(obfuscated_tokens)
        
        lsa_orig = lsa_cache.get(orig_key)
        lsa_obf = lsa_cache.get(obf_key)

        # Fallback de segurança caso ocorra perda de referência em tempo de execução
        if lsa_orig is None:
            lsa_orig = svd.transform(vectorizer.transform([original_tokens])).astype(np.float32)
            lsa_cache[orig_key] = lsa_orig
        if lsa_obf is None:
            lsa_obf = svd.transform(vectorizer.transform([obfuscated_tokens])).astype(np.float32)
            lsa_cache[obf_key] = lsa_obf
        
        # Passo C: Calcula apenas o cosseno dos vetores semânticos já cacheados
        return float(
            cosine_similarity(
                lsa_orig,
                lsa_obf
            )[0][0]
        )

    # 7. Execução da Pipeline
    print("[3/3] Iniciando comparação bloco a bloco...")
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
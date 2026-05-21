import json
import csv
import sys
import argparse
from pathlib import Path
from sklearn.feature_extraction.text import HashingVectorizer, TfidfTransformer
from sklearn.metrics.pairwise import cosine_similarity

def carregar_tokens_do_json(caminho_arquivo):
    try:
        with open(caminho_arquivo, 'r', encoding='utf-8') as f:
            dados = json.load(f)
        
        chave_arquivo = list(dados.keys())[0]
        blocos_brutos = dados[chave_arquivo]
        
        todos_os_tokens = []
        for bloco in blocos_brutos:
            todos_os_tokens.extend(bloco[0])
            
        return todos_os_tokens
        
    except Exception as e:
        print(f"Erro fatal ao ler o arquivo {caminho_arquivo}: {e}")
        sys.exit(1)

def mapear_arquivos(dir_orig, dir_obf):
    caminhos = []
    for pasta_problema in dir_orig.iterdir():
        if pasta_problema.is_dir() and pasta_problema.name.startswith("problema_"):
            for arquivo_orig in pasta_problema.glob("*.json"):
                arquivo_obf = dir_obf / pasta_problema.name / arquivo_orig.name
                
                if not arquivo_obf.exists():
                    print(f"Erro fatal: Par ofuscado não encontrado para {arquivo_orig}")
                    sys.exit(1)
                
                identificador = f"{pasta_problema.name}/{arquivo_orig.name}"
                caminhos.append((identificador, arquivo_orig, arquivo_obf))
    return caminhos

def gerador_de_corpus(caminhos):
    for _, arquivo_orig, arquivo_obf in caminhos:
        yield carregar_tokens_do_json(arquivo_orig)
        yield carregar_tokens_do_json(arquivo_obf)

def main():
    parser = argparse.ArgumentParser(description="Compara códigos usando TF-IDF + Hashing (Escala Industrial).")
    parser.add_argument("--orig", default="Original", help="Pasta original")
    parser.add_argument("--obf", default="Obfuscated", help="Pasta ofuscada")
    parser.add_argument("--out", default="resultado_tfidf_hashing.csv", help="Arquivo CSV de saída")
    args = parser.parse_args()

    dir_orig = Path(args.orig)
    dir_obf = Path(args.obf)

    if not dir_orig.exists() or not dir_obf.exists():
        print(f"Erro: As pastas '{args.orig}' ou '{args.obf}' não foram encontradas.")
        sys.exit(1)

    caminhos_dos_pares = mapear_arquivos(dir_orig, dir_obf)
    print(f"Total de {len(caminhos_dos_pares)} pares mapeados.")

    print("\nPasso 1: Convertendo tokens para matriz matemática...")
    # O HashingVectorizer é 'stateless' (não tem memória). Ele não guarda strings.
    # Usamos n_features=2**20 (aprox. 1.04 milhões de colunas). Isso consome quase nada de RAM.
    hash_vectorizer = HashingVectorizer(analyzer=lambda x: x, n_features=2**20, alternate_sign=False)
    
    # Isso gera uma matriz com números (sem strings), que cabe facilmente na RAM
    matriz_esparsa = hash_vectorizer.transform(gerador_de_corpus(caminhos_dos_pares))

    print("\nPasso 2: Calculando pesos IDF sobre a matriz...")
    # O TfidfTransformer vai ler a matriz numérica e aprender quais colunas numéricas
    # são comuns e quais são raras. Ele não faz ideia de quais eram as palavras originais!
    tfidf = TfidfTransformer()
    tfidf.fit(matriz_esparsa)

    # Podemos apagar a matriz gigante da memória RAM agora, já temos os pesos!
    del matriz_esparsa

    print("\nPasso 3: Calculando similaridades par a par (Gravando no disco)...")
    
    with open(args.out, 'w', newline='', encoding='utf-8') as csvfile:
        writer = csv.writer(csvfile)
        writer.writerow(['Arquivo', 'Similaridade'])
        
        for identificador, arquivo_orig, arquivo_obf in caminhos_dos_pares:
            tokens_orig = carregar_tokens_do_json(arquivo_orig)
            tokens_obf = carregar_tokens_do_json(arquivo_obf)
            
            # 1. Transforma o texto em hash numérico
            hash_pair = hash_vectorizer.transform([tokens_orig, tokens_obf])
            
            # 2. Aplica os pesos do TF-IDF sobre o hash numérico
            tfidf_pair = tfidf.transform(hash_pair)
            
            # 3. Calcula o Cosseno
            sim_global = float(cosine_similarity(tfidf_pair[0:1], tfidf_pair[1:2])[0][0])
            
            writer.writerow([identificador, round(sim_global, 4)])
            print(f"Processado: {identificador} -> Similaridade: {sim_global:.4f}")

    print("\nProcessamento em massa concluído com sucesso!")

if __name__ == "__main__":
    main()
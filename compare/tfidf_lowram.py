import json
import csv
import sys
import argparse
from pathlib import Path
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.metrics.pairwise import cosine_similarity

def carregar_tokens_do_json(caminho_arquivo):
    """Lê o JSON e extrai a lista com todos os tokens presentes no código."""
    try:
        with open(caminho_arquivo, 'r', encoding='utf-8') as f:
            dados = json.load(f)
        
        chave_arquivo = list(dados.keys())[0]
        blocos_brutos = dados[chave_arquivo]
        
        todos_os_tokens = []
        for bloco in blocos_brutos:
            todos_os_tokens.extend(bloco[0]) # Pega apenas a lista de tokens do bloco
            
        return todos_os_tokens
        
    except Exception as e:
        print(f"Erro fatal ao ler o arquivo {caminho_arquivo}: {e}")
        sys.exit(1)

def mapear_arquivos(dir_orig, dir_obf):
    """
    Varre os diretórios e retorna um iterador seguro (uma lista de caminhos) 
    com os pares de arquivos. Não carrega o conteúdo, apenas mapeia os caminhos.
    """
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
    """
    Esta é a 'mangueira'. Ela entrega um arquivo por vez para o TF-IDF.
    A palavra reservada 'yield' faz a função pausar e liberar a memória!
    """
    for _, arquivo_orig, arquivo_obf in caminhos:
        yield carregar_tokens_do_json(arquivo_orig)
        yield carregar_tokens_do_json(arquivo_obf)

def main():
    parser = argparse.ArgumentParser(description="Compara diretórios de código usando TF-IDF (Otimizado para RAM).")
    parser.add_argument("--orig", default="Original", help="Pasta com os arquivos originais")
    parser.add_argument("--obf", default="Obfuscated", help="Pasta com os arquivos ofuscados")
    parser.add_argument("--out", default="resultado_tfidf.csv", help="Nome do arquivo CSV de saída")
    args = parser.parse_args()

    dir_orig = Path(args.orig)
    dir_obf = Path(args.obf)

    if not dir_orig.exists() or not dir_obf.exists():
        print(f"Erro: As pastas '{args.orig}' ou '{args.obf}' não foram encontradas.")
        sys.exit(1)

    print("Passo 1: Mapeando arquivos no disco (sem carregar para a RAM)...")
    caminhos_dos_pares = mapear_arquivos(dir_orig, dir_obf)
    print(f"Total de {len(caminhos_dos_pares)} pares mapeados.")

    print("\nPasso 2: Treinando o modelo TF-IDF (Leitura em fluxo)...")
    vectorizer = TfidfVectorizer(analyzer=lambda x: x)
    
    # Passamos o NOSSO GERADOR diretamente para o 'fit'. O scikit-learn vai
    # puxar os arquivos um por um sem inflar a memória RAM!
    vectorizer.fit(gerador_de_corpus(caminhos_dos_pares))

    print("\nPasso 3: Calculando similaridades e escrevendo CSV em tempo real...")
    
    # Abrimos o CSV ANTES de fazer os cálculos, para salvar os resultados
    # no disco à medida que os processamos (economizando ainda mais RAM).
    with open(args.out, 'w', newline='', encoding='utf-8') as csvfile:
        writer = csv.writer(csvfile)
        writer.writerow(['Arquivo', 'Similaridade'])
        
        # Lê novamente do disco par a par, calcula e joga no lixo
        for identificador, arquivo_orig, arquivo_obf in caminhos_dos_pares:
            tokens_orig = carregar_tokens_do_json(arquivo_orig)
            tokens_obf = carregar_tokens_do_json(arquivo_obf)
            
            # Transforma os dois usando o dicionário global que o modelo aprendeu
            tfidf_pair = vectorizer.transform([tokens_orig, tokens_obf])
            
            # Calcula Cosseno
            sim_global = float(cosine_similarity(tfidf_pair[0:1], tfidf_pair[1:2])[0][0])
            
            writer.writerow([identificador, round(sim_global, 4)])
            print(f"Processado: {identificador} -> Similaridade: {sim_global:.4f}")

    print("\nConcluído com sucesso! Dataset inteiro processado com baixo uso de RAM.")

if __name__ == "__main__":
    main()
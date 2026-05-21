import json
import csv
import sys
import argparse
import os
from pathlib import Path
from sklearn.feature_extraction.text import CountVectorizer
from sklearn.metrics.pairwise import cosine_similarity

def carregar_tokens_do_json(caminho_arquivo):
    """
    Lê o JSON e extrai as listas de tokens dos blocos básicos.
    """
    try:
        with open(caminho_arquivo, 'r', encoding='utf-8') as f:
            dados = json.load(f)
        
        # O modelo de JSON fornecido usa o caminho do arquivo como a chave primária
        chave_arquivo = list(dados.keys())[0]
        blocos_brutos = dados[chave_arquivo]
        
        # Extrai apenas a lista de tokens (o primeiro elemento de cada bloco [0])
        lista_de_blocos = [bloco[0] for bloco in blocos_brutos]
        
        # Cria também uma lista única com todos os tokens do arquivo para a similaridade global
        todos_os_tokens = []
        for bloco in lista_de_blocos:
            todos_os_tokens.extend(bloco)
            
        return chave_arquivo, lista_de_blocos, todos_os_tokens
        
    except Exception as e:
        print(f"Erro fatal ao ler o arquivo {caminho_arquivo}: {e}")
        sys.exit(1)

def main():
    # Configuração de argumentos de linha de comando
    parser = argparse.ArgumentParser(description="Compara diretórios de código usando Bag of Words.")
    parser.add_argument("--orig", default="Original", help="Pasta com os arquivos originais")
    parser.add_argument("--obf", default="Obfuscated", help="Pasta com os arquivos ofuscados")
    parser.add_argument("--out", default="resultado_similaridade.csv", help="Nome do arquivo CSV de saída")
    args = parser.parse_args()

    dir_orig = Path(args.orig)
    dir_obf = Path(args.obf)

    if not dir_orig.exists() or not dir_obf.exists():
        print(f"Erro: As pastas '{args.orig}' ou '{args.obf}' não foram encontradas.")
        print("Certifique-se de executar o script na mesma pasta onde elas estão localizadas.")
        return

    print("Varrendo diretórios e calculando similaridades globais...")
    vectorizer = CountVectorizer(analyzer=lambda x: x)
    resultados = []

    # Itera por todas as pastas dentro de Original (ex: problema_1, problema_2)
    for pasta_problema in dir_orig.iterdir():
        if pasta_problema.is_dir() and pasta_problema.name.startswith("problema_"):
            
            # Itera por todos os arquivos .json dentro dessa pasta
            for arquivo_orig in pasta_problema.glob("*.json"):
                # Constrói o caminho equivalente na pasta Obfuscated
                arquivo_obf = dir_obf / pasta_problema.name / arquivo_orig.name
                
                if not arquivo_obf.exists():
                    print(f"Erro fatal: Par ofuscado não encontrado para o arquivo {arquivo_orig}")
                    sys.exit(1)

                _, _, tokens_orig = carregar_tokens_do_json(arquivo_orig)
                _, _, tokens_obf = carregar_tokens_do_json(arquivo_obf)

                # Calcula a similaridade global (texto inteiro) do par
                bow_global = vectorizer.fit_transform([tokens_orig, tokens_obf])
                sim_global = float(cosine_similarity(bow_global[0:1], bow_global[1:2])[0][0])
                
                # Salva no formato exigido: "problema_X/source_Y.json" e pontuação
                identificador = f"{pasta_problema.name}/{arquivo_orig.name}"
                resultados.append([identificador, round(sim_global, 4)])
                print(f"Processado: {identificador} -> Similaridade: {sim_global:.4f}")

    # Ordena os resultados pelo identificador (nome da pasta e arquivo)
    resultados.sort(key=lambda x: x[0])

    print(f"\nGerando CSV de saída em '{args.out}'...")
    with open(args.out, 'w', newline='', encoding='utf-8') as csvfile:
        writer = csv.writer(csvfile)
        writer.writerow(['Arquivo', 'Similaridade'])
        for res in resultados:
            writer.writerow(res)

    print("Concluído com sucesso!")

if __name__ == "__main__":
    main()
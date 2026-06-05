# Visualização de Resultados

Este documento explica como usar a ferramenta [`compare/visualize.py`](compare/visualize.py), que gera visualizações leves em PNG a partir dos arquivos produzidos pelos comparadores em `compare/`.

O objetivo é evitar páginas HTML gigantes. Em vez disso, o script lê a pasta de saída no mesmo formato de `tmp/py` e produz:

- um gráfico de similaridade por arquivo;
- gráficos de comparação por blocos, extraídos dos arquivos `.diff`;
- um `manifest.json` com os arquivos gerados.

## Requisitos

Antes de executar, instale as dependências do projeto:

```bash
python -m pip install -r requirements.txt
```

A ferramenta usa `matplotlib`, então a instalação precisa estar disponível no ambiente virtual do projeto.

## Estrutura esperada de entrada

O diretório passado em `input_root` deve seguir a mesma estrutura de `tmp/py`:

- arquivos CSV na raiz, um por algoritmo, por exemplo `1_diff.csv`, `2_bow.csv`, `3_tfidf.csv`;
- uma pasta com o mesmo nome de cada CSV, contendo os `.diff` gerados por problema;
- dentro de cada pasta, os `.diff` seguem o mesmo caminho relativo dos arquivos listados no CSV.

Exemplo:

```text
tmp/py/
  1_diff.csv
  1_diff/
    problema_102/source_118431.diff
  2_bow.csv
  2_bow/
    problema_102/source_118431.diff
  3_tfidf.csv
  3_tfidf/
    problema_102/source_118431.diff
```

## Uso básico

```bash
python3 compare/visualize.py tmp/py --output-dir tmp/py/visuals
```

Esse comando gera, por padrão:

- `summary_all.png` quando o modo inclui resumo;
- uma pasta `blocks_all/` com gráficos por arquivo quando o modo inclui blocos;
- `manifest.json` com o inventário da execução.

## Flags disponíveis

### `input_root`  
Argumento posicional obrigatório.

Diretório raiz com os CSVs e as pastas de `.diff`.

Exemplo:

```bash
python3 compare/visualize.py tmp/py
```

### `--output-dir`

Define o diretório onde as imagens e o `manifest.json` serão salvos.

Padrão:

```text
visuals
```

Exemplo:

```bash
python3 compare/visualize.py tmp/py --output-dir tmp/py/visuals
```

### `--problem`

Filtra um problema específico.

- `all` mostra todos os problemas.
- qualquer outro valor deve corresponder ao nome da pasta do problema, por exemplo `problema_102`.

Exemplos:

```bash
python3 compare/visualize.py tmp/py --problem all
python3 compare/visualize.py tmp/py --problem problema_102
```

### `--algorithms`

Seleciona quais algoritmos serão plotados.

Use os nomes dos CSVs sem a extensão, separados por vírgula.

- `all` mostra todos os algoritmos encontrados na pasta.
- valores explícitos permitem comparar apenas um subconjunto.

Exemplos:

```bash
python3 compare/visualize.py tmp/py --algorithms all
python3 compare/visualize.py tmp/py --algorithms 1_diff,3_tfidf
```

### `--file`

Escolhe o arquivo relativo usado na visualização por blocos.

O valor deve bater com a coluna `file` do CSV, por exemplo `problema_102/source_118431.json`.

Exemplo:

```bash
python3 compare/visualize.py tmp/py --file problema_102/source_118431.json
```

### `--mode`

Seleciona o tipo de saída.

Opções:

- `summary`: gera apenas o gráfico de similaridade por arquivo;
- `blocks`: gera apenas os gráficos por blocos;
- `both`: gera os dois tipos de visualização.

Exemplos:

```bash
python3 compare/visualize.py tmp/py --mode summary
python3 compare/visualize.py tmp/py --mode blocks --problem problema_102 --file problema_102/source_118431.json
python3 compare/visualize.py tmp/py --mode both
```

## Saída gerada

O diretório de saída recebe um resumo simples do que foi produzido:

- `summary_<problema>.png` ou `summary_all.png`;
- `blocks_<problema>/` com uma imagem por arquivo;
- `manifest.json` com os parâmetros usados e a lista de arquivos criados.

## Exemplos práticos

### Ver tudo

```bash
python3 compare/visualize.py tmp/py --output-dir tmp/py/visuals --mode both
```

### Ver apenas um problema

```bash
python3 compare/visualize.py tmp/py --output-dir tmp/py/visuals --problem problema_102 --mode both
```

### Comparar apenas dois algoritmos

```bash
python3 compare/visualize.py tmp/py --output-dir tmp/py/visuals --problem problema_102 --algorithms 1_diff,3_tfidf --mode both
```

### Gerar só a comparação por blocos de um arquivo

```bash
python3 compare/visualize.py tmp/py --output-dir tmp/py/visuals --problem problema_102 --file problema_102/source_118431.json --mode blocks
```

## Observações

- A ferramenta não gera HTML.
- A comparação por blocos depende dos arquivos `.diff` existentes na pasta do algoritmo.
- Quando um algoritmo não possui um bloco correspondente, o gráfico exibe valor zero para manter a escala e evitar falhas de renderização.
- O conjunto de arquivos de entrada deve manter a mesma estrutura relativa entre CSV e `.diff`.
# Tutorial: source2json - Parser de Blocos Básicos

## O que é source2json?

`source2json` é uma ferramenta que analisa código-fonte em **C, C++** e **Python**, identificando **blocos básicos** (sequências de instruções sem desvios no meio) e convertendo-os em um formato **JSON estruturado**.

### Exemplo Rápido

```c
// main.c
int main() {
    int x = 10;
    if (x > 5) {
        printf("Maior");
    }
    return 0;
}
```

Após processar:

```json
{
  "main.c": [
    [["int", "main", "int", "x", "10"], [1, 0], [2, 15]],
    [["if", "x", ">", "5", "printf", "Maior"], [3, 4], [4, 23]],
    [["return", "0"], [5, 4], [5, 14]]
  ]
}
```

---

## Instalação e Setup

### 1. Pré-requisitos

- **Python 3.7+**
- **tree-sitter** e seus parsers de linguagem

### 2. Instalar Dependências

```bash
# Criar ambiente virtual
python3 -m venv venv
source venv/bin/activate  # No Windows: venv\Scripts\activate

# Instalar tree-sitter e seus parsers
pip install tree-sitter tree-sitter-c tree-sitter-cpp tree-sitter-python
```

### 3. Verificar Instalação

```bash
# Testar se o parser funciona
python3 source2json.py teste/

# Verificar se gerou arquivo JSON
ls -la teste/*.json
```

---

## Como Usar

### Uso Básico

```bash
python3 source2json.py <diretório>
```

**Exemplo:**

```bash
python3 source2json.py ./meu_projeto/
```

O parser vai:
1. ✅ Detectar arquivos `.c`, `.cpp` e `.py`
2. ✅ Analisar cada arquivo
3. ✅ Gerar arquivo JSON consolidado com mesmo nome (ex: `arquivo.c` → `arquivo.json`)

### O que Acontece

```bash
$ python3 source2json.py teste/

parsing teste/main.c
parsing teste/utils.cpp
parsing teste/script.py

# Arquivos criados:
# - teste/main.json (contém blocos de main.c)
# - teste/utils.json (contém blocos de utils.cpp)
# - teste/script.json (contém blocos de script.py)
```

---

## Entendendo a Saída JSON

### Estrutura Geral

```json
{
  "arquivo.c": [
    [lista_tokens, [linha_inicio, coluna_inicio], [linha_fim, coluna_fim]],
    [lista_tokens, [linha_inicio, coluna_inicio], [linha_fim, coluna_fim]],
    ...
  ]
}
```

**Componentes:**

| Campo | Tipo | Descrição |
|-------|------|-----------|
| `arquivo.c` | String | Caminho do arquivo original |
| `lista_tokens` | Array | Tokens do bloco básico |
| `[linha, coluna]` | Array | Posição inicial/final no código |

### Exemplo Completo

**Código:**

```c
// exemplo.c
void hello() {
    printf("Hello");
    return;
}
```

**JSON:**

```json
{
  "exemplo.c": [
    [
      ["void", "hello", "printf", "Hello"],
      [2, 0],
      [3, 11]
    ],
    [
      ["return"],
      [4, 4],
      [4, 11]
    ]
  ]
}
```

**Interpretação:**
- Primeiro bloco: linhas 2-3, tokens da declaração ao `printf`
- Segundo bloco: linha 4, o `return`

---

## Exemplos Práticos

### Exemplo 1: Código C Simples

**Arquivo:** `teste/simples.c`

```c
int main() {
    int x = 10;
    if (x > 5) {
        x = x + 1;
    }
    return x;
}
```

**Comando:**

```bash
python3 source2json.py teste/
cat teste/simples.json | jq
```

**Saída JSON:**

```json
{
  "teste/simples.c": [
    [
      ["int", "main", "int", "x", "10"],
      [1, 0],
      [2, 15]
    ],
    [
      ["if", "x", ">", "5", "x", "x", "1"],
      [3, 4],
      [4, 19]
    ],
    [
      ["return", "x"],
      [6, 4],
      [6, 12]
    ]
  ]
}
```

### Exemplo 2: C++ com Namespaces

**Arquivo:** `teste/utils.cpp`

```cpp
namespace Utils {
    int add(int a, int b) {
        return a + b;
    }
}
```

**Comando:**

```bash
python3 source2json.py teste/
jq '.["teste/utils.cpp"]' teste/utils.json
```

### Exemplo 3: Python com Try-Except

**Arquivo:** `teste/script.py`

```python
def risky_operation(x):
    try:
        result = 10 / x
        print(result)
    except ZeroDivisionError:
        print("Division by zero!")
    finally:
        print("Done")
    return result
```

**Comando:**

```bash
python3 source2json.py teste/
jq '.["teste/script.py"]' teste/script.json
```

**Saída:**

Gera 4 blocos separados:
1. Definição da função
2. Bloco `try`
3. Bloco `except`
4. Bloco `finally` + `return`

---

## Recursos Avançados

### Filtrar Saída JSON

```bash
# Ver apenas o primeiro bloco
jq '.["arquivo.c"][0]' arquivo.json

# Ver todos os tokens do arquivo
jq '.["arquivo.c"][].[] | .[0]' arquivo.json

# Ver apenas posições
jq '.["arquivo.c"][] | {tokens: .[0], start: .[1], end: .[2]}' arquivo.json
```

### Analisar Múltiplas Linguagens

```bash
# Parser processa automaticamente arquivos .c, .cpp e .py
cp meu_codigo.c teste/
cp meu_codigo.cpp teste/
cp meu_script.py teste/

python3 source2json.py teste/

# Resultado em um único JSON com múltiplos arquivos
jq 'keys' teste/meu_codigo.json
```

---

## Regras de Divisão de Blocos

### O que Divide Blocos?

Os blocos são divididos nos seguintes pontos:

| Construto | Divide? | Exemplo |
|-----------|---------|---------|
| `if` / `else` | ✅ Sim | `if (x > 5) { ... }` |
| `else if` | ❌ Não | Continua no mesmo bloco |
| `while` / `for` | ✅ Sim | `while (x < 10) { ... }` |
| `switch` / `case` | ✅ Sim | `case 1: ... break;` |
| `return` / `goto` | ✅ Sim (fim do bloco) | `return 0;` |
| `try` / `except` | ✅ Sim (Python/C++) | `try: ... except: ...` |
| `class` | ✅ Sim | `class MyClass { ... }` |
| `goto label` | ✅ Sim (label divide) | `loop: ... goto loop;` |
| `function_def` | ✅ Sim | `int foo() { ... }` |

### Exemplo: Fall-through em switch

```c
switch (x) {
    case 1:
        printf("Um");    // Sem break - continua no próximo case
    case 2:
        printf("Dois");
        break;
    case 3:
        printf("Três");
        break;
}
```

**Blocos gerados:**
1. `case 1` + `case 2` no mesmo bloco (fall-through)
2. `case 3` em bloco separado (tem break)

---

## Troubleshooting

### Erro: "No module named 'tree_sitter'"

```bash
# Reinstalar dependências
pip install --upgrade tree-sitter tree-sitter-c tree-sitter-cpp tree-sitter-python
```

### Erro: "usage: source2json.py <directory>"

```bash
# Você esqueceu de passar o diretório
# Correto:
python3 source2json.py ./meu_codigo/

# Incorreto:
python3 source2json.py
```

### Arquivo JSON vazio

```bash
# Verifique se o diretório tem arquivos suportados
ls -la seu_diretorio/
# Procura por *.c, *.cpp, *.py

# Se o arquivo existe mas está em subpasta, não é processado
# O parser processa apenas arquivos no diretório raiz
```

### Parser trava ou é muito lento

- Arquivos muito grandes (> 10MB) podem ser lentos
- Tente processar um arquivo de cada vez para debug
- Verifique se há caracteres especiais não-ASCII

---

## Casos de Uso

### 1. Análise de Fluxo de Controle

Entender como o código se divide em caminhos de execução:

```bash
python3 source2json.py ./projeto/
jq '.["arquivo.c"] | length' arquivo.json
# Mostra quantos blocos básicos o arquivo tem
```

### 2. Geração de Corpus para ML

Use os tokens para treinar modelos de linguagem:

```bash
# Extrair todos os tokens
jq '.["arquivo.c"][].[] | .[0][]' arquivo.json > tokens.txt
```

### 3. Verificação de Cobertura de Testes

Identificar quantos blocos básicos cada função tem:

```bash
# Ver blocos por função
jq '.["arquivo.c"] | map({tokens: .[0], blocks: (.[0] | length)})' arquivo.json
```

### 4. Análise de Complexidade

Estimar complexidade ciclomática pelo número de blocos:

```bash
python3 -c "
import json
with open('arquivo.json') as f:
    data = json.load(f)
    for file, blocks in data.items():
        print(f'{file}: {len(blocks)} blocos básicos')
"
```

---


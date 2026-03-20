# source2json — Documentação

## Objetivo

`source2json.py` é uma ferramenta de análise estática de código C que converte arquivos-fonte em uma representação JSON estruturada de **blocos básicos** (*basic blocks*). A saída é projetada para uso em pipelines de aprendizado de máquina sobre código, análise de programas, ou indexação semântica de trechos de código.

---

## Dependências

| Pacote | Papel |
|---|---|
| `tree-sitter` | Biblioteca de parsing incremental que gera uma AST (*Abstract Syntax Tree*) |
| `tree-sitter-c` | Gramática da linguagem C para o tree-sitter |

Instale com:
```
pip install -r requirements.txt
```

---

## Uso

```
python source2json.py <diretório>
```

O script processa todos os arquivos `.c` encontrados no diretório informado e gera um arquivo `.json` correspondente para cada um.

**Exemplo:**
```
python source2json.py ./src
# gera ./src/foo.json, ./src/bar.json, etc.
```

---

## Fluxo de Execução

```
Diretório de entrada
       │
       ▼
  glob("*.c")  ←── percorre todos os arquivos .c
       │
       ▼
  parse_input(filename)
       │
       ├─ Lê o arquivo como texto
       ├─ C_PARSER.parse() → gera a AST com tree-sitter
       ├─ traverse(tree)   → percorre a AST em pré-ordem
       └─ c_basic_block(nodes) → agrupa nós em blocos básicos
                │
                ▼
          corpus: lista de blocos
                │
                ▼
         json.dump() → arquivo .json
```

---

## Funções

### `traverse(tree)`

Percorre a AST gerada pelo tree-sitter em **pré-ordem** (profundidade primeiro), usando um cursor iterativo. Retorna uma lista plana com todos os nós da árvore.

```
Root
├── preproc_include
│   └── system_lib_string  ← "stdio.h"
└── function_definition
    ├── primitive_type     ← "int"
    ├── declarator (main)
    └── compound_statement
        ├── expression_statement (printf...)
        └── return_statement
```

---

### `c_preprocessor(token)`

Normaliza tokens de diretivas de pré-processador do C:

| Entrada | Saída |
|---|---|
| `#include <stdio.h>` | `include stdio.h` |
| `#define MAX  100` | `define MAX 100` |

Remove o `#`, os `< >`, e colapsa espaços extras.

---

### `c_basic_block(nodes)`

Núcleo do script. Agrupa os nós da AST em **blocos básicos** — sequências de instruções sem desvios internos.

**Categorias de tokens reconhecidos:**

| Categoria | Exemplos |
|---|---|
| Aritmético | `+` `++` `-` `--` `*` `/` `%` |
| Atribuição | `=` `+=` `-=` `*=` `/=` `%=` `&=` `\|=` `^=` `>>=` `<<=` |
| Bitwise | `&` `\|` `^` `~` `<<` `>>` |
| Comparação | `==` `!=` `<` `>` `>=` `<=` |
| Lógico | `&&` `\|\|` `!` |
| Palavras-chave | `if` `else` `for` `while` `return` `switch` `case` `do` `typedef` `struct` `enum` ... |
| Tipos/Literais | identificadores, literais numéricas, strings, tipos primitivos, `#include`, `#define` ... |

**Regra de criação de novo bloco:**

Um novo bloco básico é criado quando **todas** as condições abaixo forem verdadeiras:
1. O bloco atual já possui pelo menos um token.
2. Passa na verificação de *idiosyncrasy* (ver abaixo).
3. O nó atual é um construto de desvio (`function_definition`, `if_statement`, `else_clause`, `switch_statement`, `case_statement`, `do_statement`, `for_statement`, `while_statement`) **ou** o nó está além do ponto de fim da branch anterior.

**Verificação de idiosyncrasy:**

Impede a criação de um novo bloco quando um `if_statement` vem logo após um token `else`. Isso mantém o `else if` dentro do mesmo bloco lógico do `else`.

---

### `parse_input(filename)`

Orquestra o parsing de um único arquivo:
1. Detecta a extensão com `os.path.splitext()` (tratamento robusto para caminhos como `./teste.c`).
2. Chama as funções de traversal e agrupamento.
3. Para cada bloco básico não-vazio, extrai a lista de tokens e os pontos de início e fim no arquivo-fonte.
4. Retorna o corpus como lista.

---

## Formato de Saída (JSON)

```json
{
  "caminho/arquivo.c": [
    [
      ["token1", "token2", "token3"],
      [linha_inicio, coluna_inicio],
      [linha_fim, coluna_fim]
    ],
    ...
  ]
}
```

Cada entrada da lista representa um **bloco básico** com três elementos:

| Posição | Tipo | Descrição |
|---|---|---|
| `[0]` | `list[str]` | Sequência de tokens do bloco |
| `[1]` | `[int, int]` | Posição de início `[linha, coluna]` no arquivo-fonte |
| `[2]` | `[int, int]` | Posição de fim `[linha, coluna]` no arquivo-fonte |

---

## Exemplo Concreto

**Entrada — `teste.c`:**
```c
#include <stdio.h>

int main() {
    printf("Hello, World!\n");
    return 0;
}
```

**Saída — `teste.json`:**
```json
{
  "./teste.c": [
    [
      ["include", "stdio.h"],
      [0, 0],
      [0, 18]
    ],
    [
      ["int", "main", "printf", "Hello, World!", "\\n", "return", "0"],
      [6, 0],
      [8, 12]
    ]
  ]
}
```

**Interpretação:**

- **Bloco 1** — diretiva `#include <stdio.h>` na linha 0, colunas 0–18. Após o pré-processamento, vira os tokens `["include", "stdio.h"]`.
- **Bloco 2** — corpo da função `main` (linhas 6–8). Todos os tokens relevantes da função são agrupados em um único bloco básico: o tipo de retorno, o nome da função, os tokens da chamada `printf` e do `return`.

O `main()` inteiro fica em um único bloco porque não há desvios internos (sem `if`, `for`, `while`, etc.).

---

## Casos de Divisão de Blocos

Se o `main` tivesse um `if`, o script dividiria em dois blocos:

```c
int main() {
    int x = 10;        // Bloco 1
    if (x > 5) {       // Bloco 2 (inicia novo bloco ao encontrar if_statement)
        printf("ok");
    }
}
```

---

## Limitações e Observações

- Processa apenas arquivos `.c` (sem suporte a `.cpp` ou `.h` na lógica atual).
- O conceito de "bloco básico" aqui é uma **aproximação** do conceito formal de compiladores — nós são agrupados por posição no arquivo e por presença de construtos de desvio, não por análise de fluxo de controle completa.
- Tokens de pontuação estrutural (como `{`, `}`, `;`, `(`, `)`) são **descartados** — apenas tokens semanticamente relevantes são mantidos.

---

## Bloco Básico: Definição Formal vs. Implementação

### Definição Formal (Teoria de Compiladores)

Em compiladores, um **bloco básico** é uma sequência *máxima* de instruções consecutivas com as seguintes propriedades:

1. **Entrada única** — o fluxo de controle só pode entrar pelo início do bloco.
2. **Saída única** — o fluxo de controle só pode sair pelo fim do bloco.
3. **Sem desvios internos** — nenhuma instrução do meio pode ser um salto nem um destino de salto.

O algoritmo clássico opera sobre uma **representação linear intermediária** (IR) e segue dois passos:

1. **Identificar líderes** (*leaders*) — toda instrução que seja:
   - A primeira instrução do programa;
   - Destino de um salto (condicional ou incondicional);
   - Instrução imediatamente após um salto.

2. **Delimitar blocos** — cada bloco começa em um líder e se estende até a instrução imediatamente antes do próximo líder.

O resultado é um **Grafo de Fluxo de Controle** (CFG), onde os blocos são nós e as arestas representam possíveis transferências de controle entre eles.

---

### O que a Implementação Faz

A implementação opera sobre a **AST** (*Abstract Syntax Tree*) gerada pelo tree-sitter, não sobre IR linear. Isso muda fundamentalmente o modelo:

#### 1. Critério de divisão: sintático, não semântico

| Aspecto | Formal | Implementação |
|---|---|---|
| Base | Instruções de IR + análise de saltos | Tipos de nós da AST + posição no arquivo |
| Gatilho de novo bloco | Instrução de salto ou destino de salto | Nó do tipo `if_statement`, `for_statement`, `while_statement`, etc. |
| Controle de fluxo | Analisado explicitamente | Inferido sintaticamente pela estrutura da árvore |

A implementação cria um novo bloco ao **encontrar um construto de desvio**, não ao analisar se aquele construto de fato transfere o fluxo de controle naquele ponto de execução.

#### 2. Nenhum rastreamento de destinos de salto

O modelo formal exige identificar onde cada salto *aponta*. A implementação não faz isso: instruções `goto` e `labels` não têm tratamento especial — um `goto` não divide blocos, e o `label` destino tampouco inicia um novo bloco automaticamente.

```c
int main() {
    int x = 0;
    goto fim;       // Formal: divide bloco aqui
    x = 999;        // Formal: novo bloco (instrução após salto)
fim:                // Formal: novo bloco (destino de salto)
    return x;
}
// Implementação: tudo fica em um único bloco (não há construto de desvio reconhecido)
```

#### 3. Diretivas de pré-processador como pseudo-blocos

No modelo formal, o pré-processador é executado *antes* da compilação — `#include` e `#define` não existem no IR. Na implementação, cada diretiva de pré-processador vira seu próprio bloco básico, com tokens normalizados por `c_preprocessor()`.

#### 4. Chamadas de função não dividem blocos

Na teoria, há duas visões: na **análise intraprocedural**, chamadas de função *não* quebram blocos básicos (são tratadas como instruções normais). Na **análise interprocedural**, elas podem. A implementação segue o comportamento intraprocedural implicitamente — uma chamada como `printf(...)` não cria um novo bloco.

Porém, uma **definição de função** (`function_definition`) *sempre* cria um novo bloco, o que faz sentido: cada função é um ponto de entrada independente no CFG.

#### 5. Sem construção de CFG

A implementação produz uma **lista ordenada de blocos**, não um grafo. As arestas entre blocos (qual bloco pode ser executado após qual) não são computadas. O resultado é adequado para tarefas de representação de código (ML, busca semântica), mas não para otimizações de compilador que dependem do CFG.

#### 6. Tokens de blocos aninhados são achatados

No modelo formal, o corpo de um `if` e o bloco após o `if` são blocos separados com uma aresta condicional entre eles. Na implementação, se o corpo do `if` não contém desvios internos, seus tokens são agrupados *junto com* os tokens do próprio `if` no mesmo bloco:

```c
// No modelo formal: 3 blocos (antes do if / corpo do if / após o if)
// Na implementação: 2 blocos (antes do if / if + corpo + após)
if (x > 0) {
    x = x - 1;   // sem desvio interno → fica no mesmo bloco do if
}
return x;
```

---

### Resumo das Diferenças

| Característica | Definição Formal | Implementação |
|---|---|---|
| Entrada de dados | IR linear (assembly, three-address code) | AST do código-fonte |
| Identificação de líderes | Explícita via análise de saltos | Implícita via tipo do nó da AST |
| Suporte a `goto`/labels | Sim (altera fronteiras dos blocos) | Não (ignorados na divisão) |
| Diretivas de pré-processador | Não existem no IR | Tratadas como blocos independentes |
| Saída | Grafo de Fluxo de Controle (CFG) | Lista linear de blocos com posições |
| Uso típico | Otimização, verificação formal | Representação de código para ML/busca |

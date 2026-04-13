# Algoritmo de Divisão em Blocos Básicos

## Visão Geral

Este projeto implementa um **parser de blocos básicos** para C e C++ usando [Tree-sitter](https://tree-sitter.github.io/tree-sitter/). Um bloco básico é uma sequência de instruções sem desvios de controle no meio - o fluxo executa linearmente do início ao fim.

### Objetivo

Converter código-fonte em **sequências de tokens agrupadas em blocos básicos**, armazenando:
- **Tokens do bloco** (instrução, operadores, valores literais, etc.)
- **Posição inicial** (linha, coluna)
- **Posição final** (linha, coluna)

### Exemplo

```c
int main() {
    goto fim;           // Bloco 1 (goto é desvio)
    printf("Hello");

    fim:                // Bloco 2 (label é entrada)
    return 0;
}
```

**Output JSON:**
```json
[
  ["int", "main", "goto", "fim", "printf", "Hello"],
  ["fim", "return", "0"]
]
```

---

## Conceito: Bloco Básico

Um **bloco básico** é definido como:
- **Início**: Entrada de label, início de função, ou instrução após desvio
- **Fim**: Goto, return, break, continue, ou label
- **Propriedade**: Execução **sempre sequencial** - não há desvios no meio

### Por que Labels Dividem Blocos?

Um `label:` é um **ponto de entrada** - qualquer `goto` pode pular para ele:

```c
loop:
    x = x + 1;
    if (x < 10) goto loop;
    return 0;
```

Se não dividimos o bloco no label, perdemos a informação de que `loop:` é um destino potencial de controle.

---

## Algoritmo de Divisão em C

### Tipos de Nós que Dividem Blocos (`branch`)

```python
branch = (
    "function_definition",      # Início de função
    "if_statement",             # if/else if
    "else_clause",              # else
    "case_statement",           # case
    "do_statement",             # do-while
    "for_statement",            # for
    "while_statement",          # while
    "labeled_statement"         # label: (fim anterior, início novo)
)
```

### Tipos de Nós que São Capturados (`types` + `word`)

```python
types = (
    "identifier", "field_identifier", "statement_identifier",
    "#define", "#include", "primitive_type", "number_literal",
    ...
)

word = (
    "auto", "if", "else", "switch", "case", "break", "goto",
    "while", "for", "return", ...
)
```

### Lógica Principal

```python
def c_basic_block_split(basic_block, branch, current_end_point, node):
    """Decide se deve criar novo bloco"""
    case_without_break = False
    else_if = False

    if node.type in branch and len(basic_block[-1]) > 0:
        # Exception 1: case sem break não divide (fall-through)
        case_without_break = not (
            node.type == "case_statement" and
            basic_block[-1][0][0] == "case" and
            basic_block[-1][-1][0] != "break"
        )

        # Exception 2: else if não divide bloco
        else_if = not (
            node.type == "if_statement" and
            basic_block[-1][-1][0] == "else"
        )

    # Divide se é um branch (exceto exceções) ou se há espaço entre blocos
    return (case_without_break and else_if) or (current_end_point < node.end_point)
```

### Exemplo: Fall-Through em Switch

```c
switch (a) {
    case 1:
        x = 1;          // BLOCO 1
    case 2:             // NÃO divide (fall-through)
        x = 2;          // BLOCO 2 (continua do anterior)
        break;
    case 3:             // Divide (tem break anterior)
        x = 3;          // BLOCO 3
        break;
}
```

**Output:**
```
Bloco 1: [case, 1, x, =, 1, case, 2, x, =, 2, break]
Bloco 2: [case, 3, x, =, 3, break]
```

### Exemplo: else if

```c
if (a > 0) {
    x = 1;
} else if (b > 0) {  // NÃO divide (connected to else)
    x = 2;
} else {              // NÃO divide
    x = 3;
}
```

**Output:**
```
Bloco 1: [if, a, >, 0, x, =, 1, else, if, b, >, 0, x, =, 2, else, x, =, 3]
```

---

## Algoritmo de Divisão em C++

### Tipos de Nós Adicionais (`branch`)

```python
branch = (
    # ... (todos do C)
    "labeled_statement",        # label
    "try_statement",            # try-catch
    "catch_clause",             # catch
    "class_specifier",          # class
    "namespace_definition",     # namespace { }
    "template_declaration",     # template <...>
)
```

### Tipos Adicionais Capturados (`types`)

```python
types = (
    # ... (todos do C)
    "boolean_literal",          # true, false
    "nullptr",                  # nullptr
    "user_defined_literal",     # "hello"s, 1.0_km
    "namespace_identifier",     # std::
    "raw_string_content",       # R"(...)"
    "escape_sequence",          # \n, \t em strings
)
```

### Diferença na Lógica

C++ usa uma abordagem **mais simples e legível**:

```python
def cpp_basic_block(nodes):
    # ... setup ...
    for node in nodes:
        last_block = basic_block[basic_block_index]

        if len(last_block) > 0 and node.type in branch:
            # Assume que divide por padrão
            should_split = True

            # Exception 1: else if não divide
            if node.type == "if_statement" and len(last_block) > 0 and last_block[-1][0] == "else":
                should_split = False

            # Exception 2: case sem break não divide
            elif node.type == "case_statement" and len(last_block) > 0:
                is_prev_case = last_block[0][0] == "case"
                has_break = last_block[-1][0] == "break"
                if is_prev_case and not has_break:
                    should_split = False

            # Divide se deve ou se há espaço
            if should_split or basic_block_branch_end_point < node.start_point:
                basic_block.append([])
                basic_block_index = basic_block_index + 1
```

**Vantagem**: Fácil entender quando divide (default True, exceções explícitas)

---

## Processamento de Gotos e Labels

### Estrutura AST (Tree-sitter)

#### Para `goto label;`

```
goto_statement
├─ goto: "goto"
├─ statement_identifier: "label"  ← CAPTURADO
└─ ;: ";"
```

#### Para `label:`

```
labeled_statement                    ← ISSO DIVIDE BLOCOS
├─ statement_identifier: "label"  ← CAPTURADO
├─ :: ":"
└─ statement: ...
```

### Fluxo de Processamento

1. **Tree-sitter parse** → AST com todos nós
2. **Traverse** → Lista linear de nós em DFS
3. **Filtragem** → Mantém apenas nós em `types` ou `word`
4. **Divisão de blocos** → Cria novo bloco quando encontra `branch`
5. **Extração de tokens** → Campo `[1]` de cada tupla é o token

### Exemplo Prático

**Código:**
```c
int f(int n) {
    init:
        int a = 0;
    loop:
        a += 1;
        if (a < n) goto loop;
        else goto end;
    end:
        return a;
}
```

**Nós relevantes (em ordem):**
```
int, f, int, n
init (labeled_statement) → DIVIDE
int, a, =, 0
loop (labeled_statement) → DIVIDE
a, +=, 1
if, a, <, n, goto, loop
else, goto, end
end (labeled_statement) → DIVIDE
return, a
```

**Blocos resultantes:**
```json
[
  ["int", "f", "int", "n"],
  ["init", "int", "a", "=", "0"],
  ["loop", "a", "+=", "1"],
  ["if", "a", "<", "n", "goto", "loop"],
  ["else", "goto", "end"],
  ["end", "return", "a"]
]
```

**Observação**: Note que `label` aparece **como token** (é um `statement_identifier`), não apenas marca divisão.

---

## Por Que `labeled_statement` Deve Estar em `branch`

### Errado (usando `label_statement`)
```python
branch = (..., "label_statement", ...)  # Tipo ERRADO
```

**Problema**: Tree-sitter não gera `label_statement` - generates `labeled_statement`
**Resultado**: Labels nunca eram reconhecidos
**Saída**: Todos os tokens no mesmo bloco (INCORRETO)

### Correto (usando `labeled_statement`)
```python
branch = (..., "labeled_statement", ...)  # Tipo CORRETO
```

**Solução**: Reconhece quando `labeled_statement` aparece
**Resultado**: Novo bloco criado no label
**Saída**: Blocos divididos corretamente para refletir fluxo de controle

---

## Diferenças C vs C++

| Aspecto | C | C++ |
|---------|---|-----|
| **Tipos de branch** | 8 | 13 (+ try/catch, class, namespace, template) |
| **Tipos capturados** | 13 | 18 (+ boolean_literal, nullptr, etc.) |
| **Operadores** | Básicos (+, -, *, /) | + Membros (->*, .*) |
| **Preprocessor** | Mantém "#" | Remove "#" |
| **Escape sequences** | Não captura | Captura como `escape_sequence` |
| **Lógica de divisão** | Usa funções auxiliares | Mais direta com `should_split` |

---

## Casos Especiais Tratados

### 1. Else If (não divide bloco)

```c
if (a) {
    printf("a");
} else if (b) {      // ← NÃO cria novo bloco
    printf("b");
}
```

**Razão**: `else if` é idiomático, mais fácil processar junto com `if`

### 2. Case sem Break (fall-through)

```c
switch (a) {
    case 1:
        x = 1;
    case 2:          // ← NÃO cria novo bloco (fluxo cai daqui)
        x = 2;
        break;
}
```

**Razão**: Fall-through é intencional, bloco contínuo reflete a execução

### 3. Labels (cria novo bloco)

```c
loop:                // ← CRIA novo bloco
    x = x + 1;
    if (x < 10) goto loop;
```

**Razão**: Label é ponto de entrada, `goto` pode pular de qualquer lugar

### 4. Try-Catch (C++ apenas)

```cpp
try {
    risky_operation();
} catch (Exception e) {  // ← CRIA novo bloco
    handle_error();
}
```

**Razão**: `catch` é ponto de entrada separado (exception unwinding)

---

## Fluxo Completo: Do Código ao JSON

### Passo 1: Parse com Tree-sitter
```
Código-fonte (.c/.cpp)
        ↓
  Tree-sitter Parser
        ↓
  AST (Abstract Syntax Tree)
```

### Passo 2: Traverse em DFS
```
AST
  ↓
Traversal em pré-ordem (depth-first)
  ↓
Lista linear: [Node, Node, Node, ...]
```

### Passo 3: Filtragem
```
[Node1: int, Node2: goto, Node3: fim, ...]
        ↓
  Manter apenas tipos em (types + word)
        ↓
[Node1: int, Node2: goto, Node3: fim, ...]
```

### Passo 4: Construção de Blocos
```
[Node1, Node2, Node3, Node4_BRANCH, Node5, ...]
  Block1: [Node1, Node2, Node3]
  Block2: [Node5, ...]  ← Novo bloco criado porque Node4 é branch
```

### Passo 5: Extração de Tokens
```
Block1: [
  (int, "int", (0,0), (0,3)),
  (goto, "goto", (1,4), (1,8)),
  (statement_identifier, "fim", (1,9), (1,12))
]
  ↓
Tokens: ["int", "goto", "fim"]
Posição inicial: (0, 0)
Posição final: (1, 12)
```

### Passo 6: Saída JSON
```json
{
  "file.c": [
    [
      ["int", "main", "goto", "fim"],
      [0, 0],
      [1, 12]
    ],
    [
      ["fim", "return", "0"],
      [3, 4],
      [4, 12]
    ]
  ]
}
```

---

## Tipos de Nós Completos

### C (types)
```python
"character"          # 'a'
"#define"            # #define NAME
"identifier"         # variable, function
"field_identifier"   # struct.field
"statement_identifier"  # GOTO LABEL (IMPORTANTE!)
"null"               # (raro)
"number_literal"     # 42, 3.14
"preproc_arg"        # Argumentos de #include
"#include"           # #include directive
"primitive_type"     # int, char, void
"string_content"     # Conteúdo de "string"
"system_lib_string"  # <stdio.h>
"type_identifier"    # struct name, typedef
```

### C++ Adicionais
```python
"boolean_literal"    # true, false
"nullptr"            # nullptr
"user_defined_literal"  # "s"_km
"namespace_identifier"  # std::
"raw_string_content"    # R"(...)"
"escape_sequence"       # \n em strings
```

---

## Validação

### Como Testar

```bash
# Parsear arquivos C
python3 source2json.py teste/

# Gera: teste/teste.json, teste/bruno.json

# Ver saída
jq '.["teste/teste.c"]' teste/teste.json
```

### Verificar Blocos Corretos

1. **Labels devem criar novo bloco**
   ```json
   [..., ["fim", "return", "0"], ...]  // fim é início de novo bloco
   ```

2. **Gotos devem aparecer como token**
   ```json
   [..., "goto", "fim", ...]  // goto e label aparecem
   ```

3. **C e C++ devem ser equivalentes**
   ```
   C:   ["int", "main", "goto", "fim", "printf", "text"]
   C++: ["int", "main", "goto", "fim", "printf", "text", "\\n"]
   ```
   (A diferença de `\\n` é esperada - C++ captura escape_sequence)

---

## Limitações e Trabalho Futuro

### Atual
- ✅ Gotos e labels funcionam
- ✅ Switch/case com fall-through
- ✅ Else if
- ✅ Try-catch (C++)
- ✅ Consolidação C/C++ em um arquivo JSON

### Trabalho Futuro
- ❌ Python (não implementado)
- ❌ Detecção de loops (while, for, do-while como graphviz)
- ❌ Análise de dominância entre blocos
- ❌ Otimização: remover blocos vazios

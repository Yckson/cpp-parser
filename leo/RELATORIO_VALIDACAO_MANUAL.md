# Relatorio de Validacao Manual

## Pasta: leo/1_teste_if_else.py

### Arquivo: leo/1_teste_if_else.py/teste_1.py
Status: OK

Motivo:
- Bloco de assinatura (`def f x`) presente e correto.
- Bloco do `if x > 0` inclui `return 1` corretamente.
- A linha `x = 5` (apos `return`) foi separada em bloco proprio; comportamento coerente com regra de terminador (`return`) que encerra bloco.
- Blocos de `elif` e `else` foram identificados corretamente, com `return 0` e `return -1`.

Arquivos conferidos:
- [leo/1_teste_if_else.py/teste_1.py](leo/1_teste_if_else.py/teste_1.py)
- [leo/1_teste_if_else.py/teste_1.json](leo/1_teste_if_else.py/teste_1.json)

### Arquivo: leo/1_teste_if_else.py/teste_2.cpp
Status: OK

Motivo:
- Bloco da assinatura (`int teste int x`) presente e correto.
- Bloco do `if (x > 0)` com `return 1` correto.
- `else if` foi agrupado no mesmo bloco (`else if x == 0 return 0`), condizente com regra atual para `else if` em C/C++.
- A linha `x = 5` apos `return 0` foi separada em bloco proprio, coerente com encerramento por terminador.
- Bloco final de `else return -1` correto.

Arquivos conferidos:
- [leo/1_teste_if_else.py/teste_2.cpp](leo/1_teste_if_else.py/teste_2.cpp)
- [leo/1_teste_if_else.py/teste_2.json](leo/1_teste_if_else.py/teste_2.json)

### Arquivo: leo/1_teste_if_else.py/teste_3.c
Status: OK

Motivo:
- Estrutura `if / else if / else` representada em blocos esperados.
- Blocos com `return 1`, `return 0` e `return -1` corretamente segmentados por ramo.
- Nao houve split indevido dentro do `else if`.

Arquivos conferidos:
- [leo/1_teste_if_else.py/teste_3.c](leo/1_teste_if_else.py/teste_3.c)
- [leo/1_teste_if_else.py/teste_3.json](leo/1_teste_if_else.py/teste_3.json)

### Resumo da pasta leo/1_teste_if_else.py
- OK: 3
- Problemas: 0

## Pasta: leo/2_teste_elif.py

### Arquivo: leo/2_teste_elif.py/teste1.py
Status: OK

Motivo:
- Bloco de assinatura (`def f x`) presente e correto.
- Bloco do `if x == 0` com `return 0` corretamente identificado.
- Bloco do `elif x == 1` com `return 1` corretamente identificado.
- Bloco do `else` com `return -1` corretamente identificado.
- Segmentacao entre ramos consistente com a estrutura do codigo.

Arquivos conferidos:
- [leo/2_teste_elif.py/teste1.py](leo/2_teste_elif.py/teste1.py)
- [leo/2_teste_elif.py/teste1.json](leo/2_teste_elif.py/teste1.json)

### Resumo da pasta leo/2_teste_elif.py
- OK: 1
- Problemas: 0

## Pasta: leo/3_teste_loop_if.py

### Arquivo: leo/3_teste_loop_if.py/teste1.py
Status: OK

Motivo:
- Assinatura da funcao (`def f n`) correta.
- Bloco de loop (`for i in range n`) identificado corretamente.
- Ramo `if` com condicao `i % 2 == 0` e chamada `print(i)` no mesmo bloco, como esperado.
- Ramo `else` com `print(-i)` separado corretamente.

Arquivos conferidos:
- [leo/3_teste_loop_if.py/teste1.py](leo/3_teste_loop_if.py/teste1.py)
- [leo/3_teste_loop_if.py/teste1.json](leo/3_teste_loop_if.py/teste1.json)

### Arquivo: leo/3_teste_loop_if.py/teste2.c
Status: OK

Motivo:
- `#include` foi tokenizado corretamente.
- Assinatura de funcao e cabecalho do `for` corretos no JSON.
- Bloco do `if` contem condicao e chamada `printf("%d", i)` corretamente.
- Bloco do `else` contem `printf("%d", -i)` corretamente.

Arquivos conferidos:
- [leo/3_teste_loop_if.py/teste2.c](leo/3_teste_loop_if.py/teste2.c)
- [leo/3_teste_loop_if.py/teste2.json](leo/3_teste_loop_if.py/teste2.json)

### Arquivo: leo/3_teste_loop_if.py/teste3.cpp
Status: OK

Motivo:
- Estrutura em C++ equivalente ao caso C foi segmentada com o mesmo padrao esperado.
- Blocos de `for`, `if` e `else` coerentes com o codigo-fonte.
- Nao houve divisao indevida entre condicao e chamadas `printf`.

Arquivos conferidos:
- [leo/3_teste_loop_if.py/teste3.cpp](leo/3_teste_loop_if.py/teste3.cpp)
- [leo/3_teste_loop_if.py/teste3.json](leo/3_teste_loop_if.py/teste3.json)

### Resumo da pasta leo/3_teste_loop_if.py
- OK: 3
- Problemas: 0

## Pasta: leo/4_test_try.py

### Arquivo: leo/4_test_try.py/teste1.py
Status: OK

Motivo:
- Bloco de assinatura (`def f x`) correto.
- Blocos `try`, `except` e `finally` foram separados corretamente.
- Token de string no `finally` saiu sem duplicacao (`"done"`), conforme esperado apos correcao anterior.

Arquivos conferidos:
- [leo/4_test_try.py/teste1.py](leo/4_test_try.py/teste1.py)
- [leo/4_test_try.py/teste1.json](leo/4_test_try.py/teste1.json)

### Arquivo: leo/4_test_try.py/teste2.cpp
Status: Problema

Motivo:
- No fonte, `std::cout << "done" << std::endl;` e `return result;` estao fora do bloco `catch`.
- No JSON, esses tokens aparecem dentro do mesmo bloco iniciado por `catch`.
- Isso indica escopo de bloco incorreto para `catch` neste caso.

Evidencia:
- Fonte: [leo/4_test_try.py/teste2.cpp](leo/4_test_try.py/teste2.cpp)
- Saida: [leo/4_test_try.py/teste2.json](leo/4_test_try.py/teste2.json)

### Arquivo: leo/4_test_try.py/teste3.cpp
Status: OK

Motivo:
- Blocos `try`, `if/throw`, `return` e `catch` estao segmentados de forma coerente com o fonte.
- Nao foi observada captura indevida de tokens fora do `catch` neste caso.

Arquivos conferidos:
- [leo/4_test_try.py/teste3.cpp](leo/4_test_try.py/teste3.cpp)
- [leo/4_test_try.py/teste3.json](leo/4_test_try.py/teste3.json)

### Resumo da pasta leo/4_test_try.py
- OK: 2
- Problemas: 1

## Pasta: leo/5_teste_for_else.py

### Arquivo: leo/5_teste_for_else.py/teste1.py
Status: OK

Motivo:
- Bloco de assinatura (`def f lst`) correto.
- Bloco do `for` identificado corretamente.
- Bloco do `if` com `break` separado corretamente.
- Bloco do `else` com `return 1` correto.
- `return 0` apos o `if/else` (ainda dentro do `for`) aparece em bloco proprio, coerente com o fluxo do fonte.

Arquivos conferidos:
- [leo/5_teste_for_else.py/teste1.py](leo/5_teste_for_else.py/teste1.py)
- [leo/5_teste_for_else.py/teste1.json](leo/5_teste_for_else.py/teste1.json)

### Arquivo: leo/5_teste_for_else.py/teste2.cpp
Status: OK

Motivo:
- `#include` e assinatura da funcao tokenizados corretamente.
- Cabecalho do `for` range-based foi identificado de forma consistente com as regras atuais de tokenizacao.
- Blocos de `if/break`, `else/return 1`, `return 0` interno ao `for` e `return 0` final da funcao estao separados de forma coerente.
- Nao foi observado agrupamento indevido entre blocos de niveis diferentes.

Arquivos conferidos:
- [leo/5_teste_for_else.py/teste2.cpp](leo/5_teste_for_else.py/teste2.cpp)
- [leo/5_teste_for_else.py/teste2.json](leo/5_teste_for_else.py/teste2.json)

### Resumo da pasta leo/5_teste_for_else.py
- OK: 2
- Problemas: 0

## Pasta: leo/6_teste_multiple_return.py

### Arquivo: leo/6_teste_multiple_return.py/teste1.py
Status: OK

Motivo:
- Bloco de assinatura (`def f x`) correto.
- Primeiro `if x > 10` com `return 1` corretamente agrupado.
- Segundo `if x > 5` com `return 2` corretamente agrupado.
- `return 3` final mantido em bloco proprio, coerente com fluxo sequencial.
- Nao houve fusao indevida entre os dois ramos condicionais.

Arquivos conferidos:
- [leo/6_teste_multiple_return.py/teste1.py](leo/6_teste_multiple_return.py/teste1.py)
- [leo/6_teste_multiple_return.py/teste1.json](leo/6_teste_multiple_return.py/teste1.json)

### Resumo da pasta leo/6_teste_multiple_return.py
- OK: 1
- Problemas: 0

## Pasta: leo/7_teste_multiple_return.py

### Arquivo: leo/7_teste_multiple_return.py/teste1.py
Status: Problema

Motivo:
- O docstring foi corretamente ignorado (nao aparece nos tokens), mas houve fusao da assinatura com o primeiro `return`.
- No JSON, o primeiro bloco saiu como `def f return 1`, enquanto o padrao usado nas demais funcoes Python do conjunto separa assinatura (`def f ...`) e corpo em blocos distintos.
- Esse comportamento torna este caso inconsistente em relacao ao padrao observado nas outras pastas.

Evidencia:
- Fonte: [leo/7_teste_multiple_return.py/teste1.py](leo/7_teste_multiple_return.py/teste1.py)
- Saida: [leo/7_teste_multiple_return.py/teste1.json](leo/7_teste_multiple_return.py/teste1.json)

### Resumo da pasta leo/7_teste_multiple_return.py
- OK: 0
- Problemas: 1

## Pasta: leo/8_teste_nested.py

### Arquivo: leo/8_teste_nested.py/teste.py
Status: OK

Motivo:
- Bloco de assinatura (`def f x`) correto.
- `if x > 0` externo foi separado em bloco proprio, preservando a estrutura aninhada.
- `if x > 10` interno com `return 1` corretamente agrupado.
- `else return 2` do `if` interno corretamente separado.
- `return 0` final (fora do if externo) mantido em bloco proprio.
- Segmentacao geral coerente com o fluxo de controle do codigo.

Arquivos conferidos:
- [leo/8_teste_nested.py/teste.py](leo/8_teste_nested.py/teste.py)
- [leo/8_teste_nested.py/teste.json](leo/8_teste_nested.py/teste.json)

### Resumo da pasta leo/8_teste_nested.py
- OK: 1
- Problemas: 0

## Pasta: leo/9_teste_switch.c

### Arquivo: leo/9_teste_switch.c/teste1.c
Status: OK

Motivo:
- Bloco de assinatura com `switch` identificado corretamente.
- Como nao ha `break` entre `case 1`, `case 2` e `default`, o parser agrupou os tres no mesmo bloco (fall-through), que e o comportamento esperado pelas regras atuais adotadas.
- `return x` foi mantido em bloco separado, fora do `switch`.

Arquivos conferidos:
- [leo/9_teste_switch.c/teste1.c](leo/9_teste_switch.c/teste1.c)
- [leo/9_teste_switch.c/teste1.json](leo/9_teste_switch.c/teste1.json)

### Resumo da pasta leo/9_teste_switch.c
- OK: 1
- Problemas: 0

## Pasta: leo/10_teste_goto.c

### Arquivo: leo/10_teste_goto.c/teste1.c
Status: OK

Motivo:
- `goto` dentro do `if` (condicional) encerra bloco, como esperado.
- `label` (`erro:`) nao criou bloco novo e ficou junto com o fluxo seguinte (`int y = x; return -1;`), conforme regra definida.

Arquivos conferidos:
- [leo/10_teste_goto.c/teste1.c](leo/10_teste_goto.c/teste1.c)
- [leo/10_teste_goto.c/teste1.json](leo/10_teste_goto.c/teste1.json)

### Arquivo: leo/10_teste_goto.c/teste2.cpp
Status: OK

Motivo:
- `goto` condicional no `if` foi separado em bloco proprio.
- `goto` incondicional (`goto burno;`) nao encerrou bloco e permaneceu no mesmo bloco subsequente, conforme regra atual.
- Labels `burno:` e `erro:` nao abriram blocos novos.

Arquivos conferidos:
- [leo/10_teste_goto.c/teste2.cpp](leo/10_teste_goto.c/teste2.cpp)
- [leo/10_teste_goto.c/teste2.json](leo/10_teste_goto.c/teste2.json)

### Arquivo: leo/10_teste_goto.c/teste3.cpp
Status: OK

Motivo:
- `goto` em `if/else/try/catch` foi tratado como condicional e gerou separacoes de bloco coerentes com a regra expandida.
- `goto fim;` fora desses contextos nao encerrou bloco.
- Labels `a/b/c/d/fim` permaneceram no mesmo bloco, sem criar novos blocos indevidos.

Arquivos conferidos:
- [leo/10_teste_goto.c/teste3.cpp](leo/10_teste_goto.c/teste3.cpp)
- [leo/10_teste_goto.c/teste3.json](leo/10_teste_goto.c/teste3.json)

### Resumo da pasta leo/10_teste_goto.c
- OK: 3
- Problemas: 0


# Analise Sintatica e Semântica do compilador

## Regras Sintáticas

As regras sintáticas foram construidas como mostrado abaixo.

    Programa -> programainicio ListaDeclaracao execucaoinicio ListaComando fimexecucao fimprograma
    Declaracao -> definainstrucao ID como Comando
    ListaDeclaracao -> Declaracao ListaDeclaracao
    ListaDeclaracao -> ''
    Comando -> Bloco
    Comando -> Iteracao
    Comando -> Laco
    Comando -> Condicional
    Comando -> Instrucao
    ListaComando -> Comando ListaComando
    ListaComando -> ''
    Bloco -> inicio ListaComando fim
    Iteracao -> repita NUM vezes Comando fimrepita
    Laco -> enquanto Condicao faca Comando fimpara
    Condicional -> se Condicao entao Comando fimse ComplementoCondicional
    ComplementoCondicional -> senao Comando fimsenao
    ComplementoCondicional -> ''
    Sentido -> esquerda
    Sentido -> direita
    Instrucao -> mova NUM passos
    Instrucao -> vire para Sentido
    Instrucao -> ID
    Instrucao -> pare
    Instrucao -> finalize
    Instrucao -> apague lampada
    Instrucao -> acenda lampada
    Instrucao -> aguarde ate Condicao
    Direcao -> esquerda
    Direcao -> direita
    Direcao -> frente
    Estado -> pronto
    Estado -> parado
    Estado -> ocupado
    Estado -> movimentando
    Condicao -> robo Estado
    Condicao -> Direcao robo bloqueada
    Condicao -> lampada acesa a Direcao

## SLR

Para o funcionamento do compilador nesta parte foram usadas: uma tabela do SLR, uma pilha, e uma lista de tokens. A lista de token é provinda do analisador léxico, já a pilha e a tabela são usadas para garantir o correto funcionamento do parser.

### Table

A partir das regras sintáticas informadas acima, uma tabela pode ser gerada [aqui](http://jsmachines.sourceforge.net/machines/slr.html). E assim pode ser possível verificar todos os passos a serem executados.

### Autômato

O autômato é construído com base na tabela e as movimentações computadas por ela.

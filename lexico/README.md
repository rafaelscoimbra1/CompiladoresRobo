# Análise Léxica do Compilador

## Requisitos mínimos para o Léxico

A parte básica do Léxico corresponde as seguintes regras:

 - Letra ::= “A” | “a” | “B” | “b” | ... | “z”
 - Digito ::= “0” | ... | “9”

As palavras reservadas são as seguintes:

 - programainicio
 - execucaoinicio
 - fimexecucao
 - fimprograma
 - definainstrucao
 - como
 - inicio
 - fim
 - repita
 - vezes
 - fimrepita
 - se
 - entao
 - fimse
 - [
 - senao
 - fimsenao
 - ]
 - mova
 - passos
 - Vire
 - Para
 - Pare
 - Finalize
 - Apague
 - Lampada
 - Acenda
 - Aguarde
 - Ate
 - Movimentando
 - Robo
 - Pronto
 - Ocupado
 - Parado
 - Frente
 - Bloqueada
 - Direita
 - Esquerda
 - Acessa
 - a
 - Apagada
 - A

## Execução do compilador

A execução consiste em uma chamada, a qual deve ser especificado como parametros para a execução: o arquivo de entrada e o arquivo de saída, da seguinte forma: **'./compilador arquivodeentrada.robo arquivodesaida.lex'**.

## Arquivo de saída

O arquivo de saída consiste em um arquivo '.lex', o qual detém a seguinte estrutura: (Num_Linha, Numero_Coluna_Inicial, Numero_Coluna_Final, Tipo_Token,"Lexema").
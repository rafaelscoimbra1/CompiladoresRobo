#include <bits/stdc++.h>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <list>

using namespace std;

fstream in;
ofstream out;
int linha = 1;
int coluna = 0;
char lookahead;
string palavra;
//string estado;
int cont[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
string flag = "Inicial";
//falta colocar o restante do cabeçalho da tabela;
string table[88][46] = {"State", "programainicio", "execucaoinicio", "fimexecucao", "fimprograma", "definainstrucao", "como", "inicio", "fim", "repita", "vezes", "fimrepita", "enquanto", "faca", "fimpara", "se", "entao", "fimse", "senao", "fimsenao", "mova", "vire", "para", "pare", "finalize", "apague", "lampada", "acenda", "aguarde", "ate", "robo", "pronto", "ocupado", "parado", "movimentando", "frente", "bloqueada", "direita", "esquerda", "acessa", "a", "apagada", "letra", "numero", "passos",  "$", "PROGRAMA", "DECLARACAO", "BLOCO", "COMANDOB", "COMANDO", "ITERACAO", "LACO", "CONDICIONAL", "STM", "INSTRUCAO", "CONDICAO", "ID", "NUMERO", "PASSO", "DIGITO", "SENTIDO", "0","s1","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","1","","r2","","","s3","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","2","","","","","","","","","","","","","","","2","","s4","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","3","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","s6","s7","","","","","","","","","","","","","","5","","","","","4","","","","","","","s14","","s15","","","s16","","","s17","","","","","s18","s19","","s21","s22","s23","","s24","s25","","","","","","","","","","","","","","s6","s7","","","","","9","","8","10","11","12","","13","","20","","","","","5","","","","","","s26","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","6","","r37","r37","","","r37","","r37","","","r37","","","r37","","","r37","","r37","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","7","","r38","r38","","","r38","","r38","","","r38","","","r38","","","r38","","r38","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","8","","","s27","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","9","","r6","r6","","","","","r6","","","r6","","","r6","","","r6","","r6","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","10","","r7","r7","","","","","r7","","","r7","","","r7","","","r7","","r7","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","11","","r8","r8","","","","","r8","","","r8","","","r8","","","r8","","r8","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","12","","r9","r9","","","","","r9","","","r9","","","r9","","","r9","","r9","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","13","","r10","r10","","","","","r10","","","r10","","","r10","","","r10","","r10","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","14","","","","","","","s14","r5","s15","","","s16","","","s17","","","","","s18","s19","","s21","s22","s23","","s24","s25","","","","","","","","","","","","","","s6","s7","","","","","9","28","29","10","11","12","","13","","20","","","","","15","","","","","","","","","","r43","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","s31","r43","","","","","","","","","","","","","","","","30","","16","","","","","","","","","","","","","","","","","","","","","","","","","","s37","","","","s33","","","","","s34","","s35","s36","","","","","","","","","","","","","","","","","","32","","","","","","17","","","","","","","","","","","","","","","","","","","","","","","","","","s37","","","","s33","","","","","s34","","s35","s36","","","","","","","","","","","","","","","","","","38","","","","","","18","","r40","r40","","","","","r40","","r43","r40","","","r40","","","r40","","r40","","","","","","","","","","","","","","","","","","","","","","","","s31","r43","","","","","","","","","","","","","","39","","40","","19","","","","","","","","","","","","","","","","","","","","","","s41","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","20","","r18","r18","","","","","r18","","","r18","","","r18","","","r18","","r18","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","21","","r19","r19","","","","","r19","","","r19","","","r19","","","r19","","r19","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","22","","r20","r20","","","","","r20","","","r20","","","r20","","","r20","","r20","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","23","","","","","","","","","","","","","","","","","","","","","","","","","","s42","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","24","","","","","","","","","","","","","","","","","","","","","","","","","","s43","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","25","","","","","","","","","","","","","","","","","","","","","","","","","","","","","s44","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","26","","","","","","","s14","","s15","","","s16","","","s17","","","","","s18","s19","","s21","s22","s23","","s24","s25","","","","","","","","","","","","","","s6","s7","","","","","9","","45","10","11","12","","13","","20","","","","","27","","","","s46","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","28","","","","","","","","s47","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","29","","","","","","","","r4","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","30","","","","","","","","","","s48","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","31","","","","","","","","","","r42","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","r42","","","","","","","","","","","","","","","","","","32","","","","","","","","","","","","","s49","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","33","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","s50","s51","s52","s53","","","","","","","","","","","","","","","","","","","","","","","","","","","","34","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","s54","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","35","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","s55","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","36","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","s56","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","37","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","s57","","s58","","","","","","","","","","","","","","","","","","","","","38","","","","","","","","","","","","","","","","s59","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","39","","r16","r16","","","","","r16","","","r16","","","r16","","","r16","","r16","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","40","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","s61","","","","","","","","","","","","","","","60","","","41","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","s64","s63","","","","","","","","","","","","","","","","","","","","","","","62","42","","r21","r21","","","","","r21","","","r21","","","r21","","","r21","","r21","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","43","","r22","r22","","","","","r22","","","r22","","","r22","","","r22","","r22","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","44","","","","","","","","","","","","","","","","","","","","","","","","","","s37","","","","s33","","","","","s34","","s35","s36","","","","","","","","","","","","","","","","","","65","","","","","","45","","r1","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","46","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","acc","","","","","","","","","","","","","","","","","47","","r3","r3","","","","","r3","","","r3","","","r3","","","r3","","r3","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","48","","","","","","","s14","","s15","","","s16","","","s17","","","","","s18","s19","","s21","s22","s23","","s24","s25","","","","","","","","","","","","","","s6","s7","","","","","9","","66","10","11","12","","13","","20","","","","","49","","","","","","","s14","","s15","","","s16","","","s17","","","","","s18","s19","","s21","s22","s23","","s24","s25","","","","","","","","","","","","","","s6","s7","","","","","9","","67","10","11","12","","13","","20","","","","","50","","r24","r24","","","","","r24","","","r24","","r24","r24","","r24","r24","","r24","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","51","","r25","r25","","","","","r25","","","r25","","r25","r25","","r25","r25","","r25","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","52","","r26","r26","","","","","r26","","","r26","","r26","r26","","r26","r26","","r26","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","53","","r27","r27","","","","","r27","","","r27","","r27","r27","","r27","r27","","r27","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","54","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","s68","","","","","","","","","","","","","","","","","","","","","","","","","","55","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","s69","","","","","","","","","","","","","","","","","","","","","","","","","","56","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","s70","","","","","","","","","","","","","","","","","","","","","","","","","","57","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","s71","","","","","","","","","","","","","","","","","","","","","","58","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","s72","","","","","","","","","","","","","","","","","","","","","","59","","","","","","","s14","","s15","","","s16","","","s17","","","","","s18","s19","","s21","s22","s23","","s24","s25","","","","","","","","","","","","","","s6","s7","","","","","9","","73","10","11","12","","13","","20","","","","","60","","r39","r39","","","","","r39","","","r39","","","r39","","","r39","","r39","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","61","","r41","r41","","","","","r41","","","r41","","","r41","","","r41","","r41","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","62","","r17","r17","","","","","r17","","","r17","","","r17","","","r17","","r17","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","63","","r44","r44","","","","","r44","","","r44","","","r44","","","r44","","r44","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","64","","r45","r45","","","","","r45","","","r45","","","r45","","","r45","","r45","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","65","","r23","r23","","","","","r23","","","r23","","","r23","","","r23","","r23","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","66","","","","","","","","","","","s74","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","67","","","","","","","","","","","","","","s75","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","68","","r28","r28","","","","","r28","","","r28","","r28","r28","","r28","r28","","r28","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","69","","r29","r29","","","","","r29","","","r29","","r29","r29","","r29","r29","","r29","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","70","","r30","r30","","","","","r30","","","r30","","r30","r30","","r30","r30","","r30","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","71","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","s76","","s78","s77","","","","","","","","","","","","","","","","","","","","","","","","72","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","s79","","s81","s80","","","","","","","","","","","","","","","","","","","","","","","","73","","","","","","","","","","","","","","","","","s82","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","74","","r11","r11","","","","","r11","","","r11","","","r11","","","r11","","r11","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","75","","r12","r12","","","","","r12","","","r12","","","r12","","","r12","","r12","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","76","","r31","r31","","","","","r31","","","r31","","r31","r31","","r31","r31","","r31","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","77","","r33","r33","","","","","r33","","","r33","","r33","r33","","r33","r33","","r33","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","78","","r35","r35","","","","","r35","","","r35","","r35","r35","","r35","r35","","r35","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","79","","r32","r32","","","","","r32","","","r32","","r32","r32","","r32","r32","","r32","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","80","","r34","r34","","","","","r34","","","r34","","r34","r34","","r34","r34","","r34","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","81","","r36","r36","","","","","r36","","","r36","","r36","r36","","r36","r36","","r36","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","82","","r15","r15","","","","","r15","","","r15","","","r15","","","r15","s84","r15","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","83","","","","","","","","83","","r13","r13","","","","","r13","","","r13","","","r13","","","r13","","r13","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","84","","","","","","","s14","","s15","","","s16","","","s17","","","","","s18","s19","","s21","s22","s23","","s24","s25","","","","","","","","","","","","","","s6","s7","","","","","9","","85","10","11","12","","13","","20","","","","","85","","","","","","","","","","","","","","","","","","","s86","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","86","","r14","r14","","","","","r14","","","r14","","","r14","","","r14","","r14","","","",""};

typedef struct token {   
    int line;
    string type;
    int col_init;
    string lexema;
    int col_finish;
}token;

typedef struct lista {
    struct token no;
    struct lista *ant;
    struct lista *prox;
}lista, *Lista;

typedef struct node {
    int nivel = 0;
    int nfilhos = 0;
    struct token no;
    struct node *filhos[8];
}node, *Node;

Node arvore;
list<token> lex;
Lista lexico = NULL;
stack<string> estados;
stack<token> sintatico;
int cont;

/*Função que ler os caracteres de um id e insere na variável 'palavra', a qual é o token final*/
void id (char letter) { // ler todas as letras
    palavra.push_back(letter);
    while ((lookahead >= 'a' && lookahead <= 'z') || (lookahead >= 'A' && lookahead <= 'Z') || (lookahead >= 0 && lookahead <= 9)) {
	in.get(letter);
        coluna++;
        palavra.push_back(letter);
        lookahead = in.peek();
    }
}

void numero (char digit) { // Ler todos os digitos
    palavra.push_back(digit);
    while (lookahead >= 0 && lookahead <= 9){
        in.get(digit);
        coluna++;
        palavra.push_back(digit);
        lookahead = in.peek();
    }
}

void comment (char letter) { // ler todos os caracteres que fazem parte dos comentários
    while ((letter != '\n'))
        in.get(letter);
        coluna++;
}

string keyword (string lexema) {
    string palav = string(lexema);
	transform(palav.begin(), palav.end(), palav.begin(), ::tolower);

    if (palav == "programainicio"){
        return "KEY";
    } else if (palav == "execucaoinicio"){
        return "KEY";
    } else if (palav == "definainstrucao"){
        return "KEY";
    } else if (palav == "inicio"){
        return "KEY";
    } else if (palav == "como"){
        return "KEY";
    } else if (palav == "repita"){
        return "KEY";
    } else if (palav == "vezes"){
        return "KEY";
    } else if (palav == "se"){
        return "KEY";
    } else if (palav == "entao"){
        return "KEY";
    } else if (palav == "senao"){
        return "KEY";
    } else if (palav == "mova"){
        return "KEY";
    } else if (palav == "passos"){
        return "KEY";
    } else if (palav == "vire"){
        return "KEY";
    } else if (palav == "para"){
        return "KEY";
    } else if (palav == "pare"){
        return "KEY";
    } else if (palav == "finalize"){
        return "KEY";
    } else if (palav == "apague"){
        return "KEY";
    } else if (palav == "lampada"){
        return "KEY";
    } else if (palav == "acenda"){
        return "KEY";
    } else if (palav == "aguarde"){
        return "KEY";
    } else if (palav == "movimentando"){
        return "KEY";
    } else if (palav == "robo"){
        return "KEY";
    } else if (palav == "pronto"){
        return "KEY";
    } else if (palav == "ocupado"){
        return "KEY";
    } else if (palav == "parado"){
        return "KEY";
    } else if (palav == "frente"){
        return "KEY";
    } else if (palav == "bloqueada"){
        return "KEY";
    } else if (palav == "direita"){
        return "KEY";
    } else if (palav == "esquerda"){
        return "KEY";
    } else if (palav == "acessa"){
        return "KEY";
    } else if (palav == "ate"){
        return "KEY";
    } else if (palav == "a"){
        return "KEY";
    } else if (palav == "apagada"){
        return "KEY";
    } else if (palav == "fimsenao"){
        return "KEY";
    } else if (palav == "fimse"){
        return "KEY";
    } else if (palav == "fim"){
        return "KEY";
    } else if (palav == "fimrepita"){
        return "KEY";
    } else if (palav == "fimexecucao"){
        return "KEY";
    } else if (palav == "fimprograma"){
        return "KEY";
    }
    return "ERRO";
}

string typeToken () {
    //Criar função que reconhece as keywords
    if (flag=="id") {
		if (keyword(palavra)=="KEY") {
            return "KEY";
        } else {
            return "ID";
        }
    } else if (flag=="numero") {
	     return "NUM";
    }
}

void insertList () { // insere o novo lexema (token) na lista
    token word;
    string type;

    word.lexema = string(palavra);
    word.col_finish = coluna;
    word.col_init = word.col_finish - palavra.length();
    word.line = linha;
    type = typeToken();
    word.type = string(type);

    /* Lista para inserir os tokens */
    Lista i = NULL;
    Lista c = (Lista) malloc(sizeof(struct lista));

    if (lexico){
        for (i = lexico; (lexico->prox); i = lexico->prox);
        c->no = word;
        i->prox = c;
        c->ant = i;
        c->prox=NULL;
    }else {
        c->no = word;
        c->prox = NULL;
        c->ant = NULL;
        lexico = c;
    }

    lex.push_back(word);
    palavra = "";
}

bool createTokens() { // cria os tokens e insere na lista Lex
    char c;
    bool res = true;

    while (!in.eof()) {
        in.get(c);
        coluna++;
        lookahead = in.peek();
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) { // reconhece id.
            id(c);
            flag = "id";
        }
        if ((c >= 0) && (c <= 9)) { // reconhece Números
            numero(c);
            flag = "numero";
        }
        if ((lookahead == ' ') || (lookahead == '\n') || (lookahead == '\t') || (lookahead == '#')) { // reconhece final de: token, linha.
            if (!palavra.empty()) {
		            insertList();
                flag = "Inicio";
            }
        }
        if (c == '#') { // reconhece comentários
            if (!palavra.empty()) {
                insertList();
                flag = "Inicio";
            }
            comment(c);
        }
        if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || (c == '#') || (c == ' ') || (c == '\n'))) {
            lookahead = c;
            res = false;
            break;
        }
        if (c == '\n') {
            linha++;
            coluna = 0;
        }
    }
    return res;
}

void geraArquivo (){
    for (list<token>::const_iterator iterator = lex.begin(), end = lex.end(); iterator != end; ++iterator) {
        out << "(";
        out << iterator->line;
        out << ",";
        out << iterator->col_init;
        out << ",";
        out << iterator->col_finish;
        out << ",";
        out << iterator->type;
        out << ",";
        out << iterator->lexema;
        out << ")";
        out << endl;
    }
}

/* Estado 1 - ler o inicioprograma */
void estado1(Lista l, string estado) {
    string lixo;
    token q;
    if (estado == "r1")
        goto r1;
    if (estado == "s1")
        goto s1;
    s1:
    if (l->no.lexema == "programainicio" && estado == "s1") {
        sintatico.push(l->no);
        cont[0]++;
        estados.push("s1");
        estado = "s2";
        if (l->no.lexema == "execucaoinicio"){
            estado = "r1";
            goto s1fim;
        }
        goto s1fim;
    }else {
        printf("erro sintático sem programainicio");
        goto s1fim;
    }
    r1:
    if (sintatico.top().lexema == "programainicio" && l->no.lexema == "execucaoinicio"){
        if (arvore){
            if (arvore->no.lexema == "definainstrucao"){
                Node aux;
                aux = (Node) malloc(sizeof(struct node));
                q = sintatico.pop();
                aux->no = sintatico.pop();
            }
        }
    }
    if (l->no.lexema == "fimprograma"){
        if (cont[0] > 5){
            if (arvore){
                Node aux;
                aux = (Node) malloc(sizeof(struct node));
                aux->no = l->no;
                aux->nivel = 0;
                aux->nfilhos = cont[0];
                if (l->no.lexema == "definainstrucao"){
                    aux->filhos[0] = arvore;
                    arvore = aux;
                }else {
                }
            }
        }
        goto s1fim;
    }
    s1fim:
}

void estado2 (Lista l, string estado){
    if (estado == "s2")
        goto s2;
    if (estado == "r2")
        goto r2;
    s2:
    if (l->no.lexema == "definainstrucao"){
        estado = "s2";
        sintatico.push(l->no);
        estados.push("s2");
    }
    r2:
}

void estadox (){
    
}

// Criar os estados a partir do slr e não de acordo com as regras.

//gerar os estados do slr para serrem usados na implementação
/* Autômato com 2 Pilhas */
void automato(){
    Lista i;
    string estado = "s1";

    for (i = lexico; (i); i = i->prox){
        if (estado == "s1"){
            calle1:
            estado1(i, estado);
        }
        if (estado == "s2"){
            calle2:
            estado2(i, estado);
        }
    }
}

int main(int argc, char *argv[]){

    bool result;

    if (argc < 3) {
        cout << "Insira o nome do arquivo de entrada!" << endl;
    }else {
        in.open(argv[1], ios::out | ios::in);
        out.open(argv[2], ios::out);
    }
    result = createTokens(); // recebe a resposta se o léxico obteve um erro ou não
    geraArquivo();

    if (!result) {
        cout << "ERRO [Lexico], caracter: " << lookahead << " linha: " << linha << " coluna: " << coluna - (palavra.length()) << endl;
        out << "(" << linha << ", " << coluna - (palavra.length()) << ", " << coluna << ", " << "ERROR, " << lookahead << endl;
    }
    automato();
    in.close();
    out.close();
    return 0;
}

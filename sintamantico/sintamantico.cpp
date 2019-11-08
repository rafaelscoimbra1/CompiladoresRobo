#include <bits/stdc++.h>
#include <iostream>
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
string flag = "Inicial";

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
    } else if (palav == "["){
        return "KEY";
    } else if (palav == "]"){
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

/* Autômato com 2 Pilhas */
void estado1(Lista *l, char estado) {
    if (l->no.lexema == "programainicio" && estado == "e1") {
        sintatico.push(l->no);
        int cont++;
        estados.push("e1");
        if (l->prox->no.lexema == "execucaoinicio" && estado == "e1"){
            return;
        }else if (l->prox->no.lexema == "definainstrucao"){
            
        }
    }else {
        //erro sintatico
    }
}

void estado2 (){
    
}

// Criar os estados a partir do slr e não de acordo com as regras.

//gerar os estados do slr para serrem usados na implementação

void gerarArvore(){
    char flag1 = 'x';
    char flag2 = 'x';
    Lista i;

    //for (list<token>::const_iterator iterator = lex.begin(), end = lex.end(); iterator != end; ++iterator){
        //sintatico.push(iterator)
        //string p = string(i->no.lexema);
        //sintatico.push(i->no);
        //estados.push("e1");
        // cout << p << '\n';
        /*if(p == "programainicio" || flag1 == 'P'){
          // cout << "2" << '\n';
          flag1 = 'P';
          Node n1 = (Node) malloc (sizeof(struct node));
          n1->no.lexema = iterator->lexema;
          n1->no.type = iterator->type;
          n1->no.line = iterator->line;
          n1->no.col_init = iterator->col_init;
          n1->no.col_finish = iterator->col_finish;
          if(p == "definainstrucao" || flag2 == 'D'){
            flag2 = 'D';
            n1->no.lexema = iterator->lexema;
            n1->no.type = iterator->type;
            n1->no.line = iterator->line;
            n1->no.col_init = iterator->col_init;
            n1->no.col_finish = iterator->col_finish;
            // cout << n1->no.lexema << endl;
            if (p == "definainstrucao" || flag2 == 'D') {

            }
          }// TEM QUE VER COMO MELHORAR ESSE ELSE
          // else if(p != "definainstrucao"){
          //   cout << "Erro Sintatico na coluna " << iterator->col_init << " e linha " << iterator->line << ", token esperado DEFINAINSTRUCAO, token encontrado " <<  iterator->lexema << endl;
          //   break;
          // }
        }
        else if(p != "programainicio"){
          cout << "Erro Sintatico na coluna " << iterator->col_init << " e linha " << iterator->line << ", token esperado PROGRAMAINICIO, token encontrado " <<  iterator->lexema << endl;
          break;
        }*/
    //}
    for (i = lexico; (i); i = i->prox){
        if (estado == "e1")
            estado1(&i, "e1");
        if (estado == "e2")
            estado2(&i, "e2");
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

    // for (list<token>::const_iterator iterator = lex.begin(), end = lex.end(); iterator != end; ++iterator) {
		// cout << iterator->line;
		// cout << ",";
		// cout << iterator->col_init;
		// cout << ",";
		// cout << iterator->col_finish;
		// cout << ",";
		// cout << iterator->type;
		// cout << ",";
		// cout << iterator->lexema;
		// cout << endl;
    //
    // }

    if (!result) {
        cout << "ERRO [Lexico], caracter: " << lookahead << " linha: " << linha << " coluna: " << coluna - (palavra.length()) << endl;
        out << "(" << linha << ", " << coluna - (palavra.length()) << ", " << coluna << ", " << "ERROR, " << lookahead << endl;
    }
    gerarArvore();
    in.close();
    out.close();
    return 0;
}

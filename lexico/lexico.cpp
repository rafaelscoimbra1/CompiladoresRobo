#include<bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string>
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
    string lexema;
    string type;
    int line;
    int col_init;
    int col_finish;
}token;

list<token> lex;

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
        if ((lookahead == ' ') || (lookahead == '\n') || (lookahead == '\t') || (lookahead != '#')) { // reconhece final de: token, linha.
            if (!palavra.empty()) {
		            insertList();
                flag = "Inicio";
            }
        }
        if (c == '#') { // reconhece comentários
            if (coluna > 1) {
                lookahead = c;
                res = false;
                break;
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

bool geraArquivo (){
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
	for (list<token>::const_iterator iterator = lex.begin(), end = lex.end(); iterator != end; ++iterator) {
	cout << "(";	
	cout << iterator->line;
	cout << ",";
	cout << iterator->col_init;
	cout << ",";
	cout << iterator->col_finish;
	cout << ",";
	cout << iterator->type;
	cout << ",";
	cout << iterator->lexema;
	cout << ")";	
	cout << endl;
    }
    return true;
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
        cout << "(" << linha << ", " << coluna - (palavra.length()) << ", " << coluna << ", " << "ERROR" << ", " << lookahead << ")" << endl;
    }

    in.close();
    out.close();
    return 0;
}

#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;

fstream in;
ofstream out;
int linha = 0;
int coluna = 0;
char lookahead;
string palavra;
string flag = "Inicial";

typedef struct token {
    string lexema;
    string type;
    int line;
    int line_init;
    int line_finish;
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
    while ((letter != '\0') || (letter != '\n'))
        in.get(letter);
        coluna++;
}

string keyword (string lexema) {
    if (lexema.compare("programainicio")){
        return "KEY";
    } else if (lexema.compare("execucaoinicio")){
        return "KEY";
    } else if (lexema.compare("definainstrucao")){
        return "KEY";
    } else if (lexema.compare("inicio")){
        return "KEY";
    } else if (lexema.compare("como")){
        return "KEY";
    } else if (lexema.compare("repita")){
        return "KEY";
    } else if (lexema.compare("vezes")){
        return "KEY";
    } else if (lexema.compare("se")){
        return "KEY";
    } else if (lexema.compare("entao")){
        return "KEY";
    } else if (lexema.compare("[")){
        return "KEY";
    } else if (lexema.compare("]")){
        return "KEY";
    } else if (lexema.compare("senao")){
        return "KEY";
    } else if (lexema.compare("mova")){
        return "KEY";
    } else if (lexema.compare("passos")){
        return "KEY";
    } else if (lexema.compare("Vire")){
        return "KEY";
    } else if (lexema.compare("Para")){
        return "KEY";
    } else if (lexema.compare("Pare")){
        return "KEY";
    } else if (lexema.compare("Finalize")){
        return "KEY";
    } else if (lexema.compare("Apague")){
        return "KEY";
    } else if (lexema.compare("Lampada")){
        return "KEY";
    } else if (lexema.compare("Acenda")){
        return "KEY";
    } else if (lexema.compare("Aguarde")){
        return "KEY";
    } else if (lexema.compare("Movimentando")){
        return "KEY";
    } else if (lexema.compare("Robo")){
        return "KEY";
    } else if (lexema.compare("Pronto")){
        return "KEY";
    } else if (lexema.compare("Ocupado")){
        return "KEY";
    } else if (lexema.compare("Parado")){
        return "KEY";
    } else if (lexema.compare("Frente")){
        return "KEY";
    } else if (lexema.compare("Bloqueada")){
        return "KEY";
    } else if (lexema.compare("Direita")){
        return "KEY";
    } else if (lexema.compare("Esquerda")){
        return "KEY";
    } else if (lexema.compare("Acessa")){
        return "KEY";
    } else if (lexema.compare("ate")){
        return "KEY";
    } else if (lexema.compare("a")){
        return "KEY";
    } else if (lexema.compare("Apagada")){
        return "KEY";
    } else if (lexema.compare("A")){
        return "KEY";
    } else if (lexema.compare("fimsenao")){
        return "KEY";
    } else if (lexema.compare("fimse")){
        return "KEY";
    } else if (lexema.compare("fim")){
        return "KEY";
    } else if (lexema.compare("fimrepita")){
        return "KEY";
    } else if (lexema.compare("fimexecucao")){
        return "KEY";
    } else if (lexema.compare("fimprograma")){
        return "KEY";
    }
    return "ERRO";
}

string typeToken () {
    //Criar função que reconhece as keywords
    if (flag.compare("id")) {
        if (keyword(palavra).compare("KEY")) {
            return "KEY";
        } else {
            return "ID";
        }
    } else if (flag.compare("numero")) {
        return "NUM";
    }
}

void insertList () { // insere o novo lexema (token) na lista
    token word;
    string type;

    word.lexema = string(palavra);
    word.line_finish = coluna;
    word.line_init = word.line_finish - palavra.length();
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
        if ((lookahead == ' ') || (lookahead == '\0') || (lookahead == '\n') || (lookahead == '\t') || (lookahead == '#')) { // reconhece final de: token, linha. 
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
        if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= 0 && c <= 9) || (c != '#'))) {
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

bool geraArquivo (string arquivo){
    for (list<token>::const_iterator iterator = lex.begin(), end = lex.end(); iterator != end; ++iterator) {

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
    if (!result) {
        string local;
        local = "ERRO [Lexico], caracter: ";
        local += lookahead;
        local += " linha: ";
        local += linha;
        local += " Coluna: ";
        local += coluna - palavra.length();
        cout << local << endl;
    }
    return 0;
}

#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;

int linha = 0;
int coluna = 0;
fstream io;
char lookahead;
string palavra;

typedef struct token {
    string token;
    int line;
    int line_init;
    int line_finish;
}token;

list<token> lex;
/*
typedef struct Lista {
    struct token node;
    struct Lista *prox;
    struct Lista *ant;
}Lista, *Lista;
*/

void letras (char letter) { // ler todas as letras
    while ((lookahead >= 'a' && lookahead <= 'z') || (lookahead >= 'A' && lookahead <= 'Z')) {
        io.get(letter);
        coluna++;
        palavra.push_back(letter);
        lookahead = io.peek();
    }
}

void digit (char digit) { // Ler todos os digitos
    while (lookahead >= 0 && lookahead <= 9){
        io.get(digit);
        coluna++;
        palavra.push_back(digit);
        lookahead = io.peek();
    }
}

void comment (char letter) { // ler todos os caracteres que fazem parte dos comentários
    while ((letter != '\0') || (letter != '\n'))
        io.get(letter);
        coluna++;
}

void insertList () { // insere o novo lexema (token) na lista
    token word;

    word.token = string(palavra);
    word.line_finish = coluna;
    word.line_init = word.line_finish - palavra.length();
    word.line = linha;

    lex.push_back(word);
    palavra = "";
}

bool createTokens() { // cria os tokens e insere na lista Lex
    char c;
    bool res = true;

    while (!io.eof()) {
        io.get(c);
        coluna++;
        lookahead = io.peek();
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) { // reconhece id.
            while ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= 0 && c <= 9)) {
                palavra.push_back(c);
                if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
                    letras(c);
                if (c >= 0 && c <= 9)
                    digit(c);
            }
        }
        if ((c >= 0) && (c <= 9)) { // reconhece Números
            palavra.push_back(c);
            digit(c);
        }
        if ((c == ' ') || (c == '\0') || (c == '\n')) { // reconhece final de: token, linha. 
            insertList();
            if (c == '\n')
                linha++;
                coluna = 0;
        }
        if (c == '#') // reconhece comentários
            comment(c);
        if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= 0 && c <= 9) || (c != '#')))
            res = false;
            break;
    }
    return res;
}

int main(int argc, char *argv[]){
    bool result;

    if (argc < 2) {
        cout << "Insira o arquivo de entrada!" << endl;
    }else {
        io.open(argv[1], ios::out | ios::in); 
    }
    result = createTokens(); // recebe a resposta se o léxico obteve um erro ou não

    return 0;
}
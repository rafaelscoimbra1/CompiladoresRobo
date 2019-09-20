#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

fstream arq;
char lookahead;

struct token {
    string token;
    int line_init;
    int line_finish;
}token;

typedef struct Lista {
    struct token node;
    struct Lista *prox;
    struct Lista *ant;
}Lista, *Lista;

bool letras(Lista word){
    while (lookahead >= 'A' || lookahead >= 'a' || lookahead <= 'Z' || lookahead <= 'z' || lookahead == '_'){
        
        arq >> lookahead;
    }
}

bool createTokens(Lista lex){
    
}

int main(int argc, char *argv[]){
	arq.open("afile.robo"); 
}
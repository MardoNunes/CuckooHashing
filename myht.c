#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "libHash.h"
#define m 11


int main(){
    char op;
    int valor;
    int T1[m];
    int T2[m];

    inicializa(T1, T2);

    while(scanf("%c %d", &op, &valor) != EOF){
        
        if(op == 'i'){
            //chamar função para inserção
            insere(T1, T2, valor);
        }
        else if(op == 'r'){
            //chamar função para remoção
            exclui(T1, T2, valor);
        }
        else
            fprintf(stderr, "operação inválida\n");
        getchar();
    }

    //printar a tabela
    imprime(T1, T2);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define m 11




//inicializo as duas tabelas com 0
void inicializa(int T1[], int T2[]){
    int i;

    for(i = 0; i < m; i++){
        T1[i] = 0;
        T2[i] = 0;
    }
}


//h1(k) = k mod m
int h1(int k){
    return k % m;
}

//h2(k) para a Tabela 2
int h2(int k){
    return floor(m * (k * 0.9 - floor(k * 0.9)));
}


//criarei a função de inserção
void insere(int T1[], int T2[], int k){

    int move;   //variavel para guardar o valor que será movido
    int chave = h1(k);  //aplico o h1(k) para a Tabela 1

    //verefico se a posição está vazia
    if(T1[chave] == 0){
        T1[chave] = k;  //se estiver vazia, insiro o valor
        return;
    }

   //se nao estiver fazia, pego o valor q esta em T1 aplico h2(k) e insiro em T2
   //eai insiro o valor atual em T1
    move = T1[chave];
    T2[h2(move)] = move;
    T1[h1(k)] = k;

    return;
}


//função para remover
void delete(int T1[], int T2[], int k){
    
    int chave = h1(k);  //aplico o h1(k) para a Tabela 1

    //verifico se o valor está na Tabela 1
    if(T1[chave] == k){
        T1[chave] = 0;
        return;
    }
    
    //se nao estiver, verifico se está na Tabela 2
    chave = h2(k);  //aplico o h2(k) para a Tabela 2
    if(T2[chave] == k){
        T2[chave] = 0;
        return;
    }

    //se nao estiver em nenhuma das tabelas
    fprintf(stderr, "valor não está na tabela\n");
    return;
}


//função para imprimir a tabela
void imprime(int T1[], int T2[]){
    
    
    //imprimindo a Tabela 2
    for(int i = 0; i < m; i++){
        if(T2[i] != 0)
            printf("%d,T2,%d\n", T2[i], i);
    }


    //imprimindo a Tabela 1
    for(int i = 0; i < m; i++){
        if(T1[i] != 0)
            printf("%d,T1,%d\n", T1[i], i);
    }
}

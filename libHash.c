#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define m 11
#define INIT -1
#define EXCL -2



//inicializo as duas tabelas com 0
void inicializa(int T1[], int T2[]){
    int i;

    for(i = 0; i < m; i++){
        T1[i] = INIT;
        T2[i] = INIT;
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

//função de busca
int busca(int T[], int k, int i){
    //vou criar um vetor ponteiro de funções e escolher entre h1 e h2
    int (*hash[2])(int) = {h1, h2};

    //aplico a função hash
    int chave = hash[i](k);

    //verifico se o valor está na Tabela 1
    if(T[chave] == k){
        return chave;
    }
    
    
    //se nao estiver em nenhuma das tabelas
    return -3;
}


//criarei a função de inserção
void insere(int T1[], int T2[], int k){

    int move;   //variavel para guardar o valor que será movido
    
  
    int chave = h1(k);  //aplico o h1(k) para a Tabela 1
    //verefico se a posição está vazia ou excluida
    if(T1[chave] == INIT || T1[chave] == EXCL){
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
void exclui(int T1[], int T2[], int k){


    
    //busco valor na T1
    int chave = busca(T1, k, 0);
    if(chave != -3){
        T1[chave] = EXCL;
        return;
    }

    //busco valor na T2
    chave = busca(T2, k, 1);
    if(chave != -3){
        T2[chave] = EXCL;
        return;
    }


    //se nao estiver em nenhuma das tabelas
    fprintf(stderr, "valor não está na tabela\n");
    return;
}


// Função para imprimir a tabela 1 em ordem crescente
void imprimeTabela1(int T1[]){
    int i;
    int tempT1[m];
    int countT1 = 0;

    // Copiando os elementos da Tabela 1 para o vetor temporário
    for (i = 0; i < m; i++) {
        if (T1[i] != INIT && T1[i] != EXCL) {
            tempT1[countT1] = T1[i];
            countT1++;
        }
    }

    // Ordenando o vetor temporário da Tabela 1 em ordem crescente
    for (i = 0; i < countT1 - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < countT1; j++) {
            if (tempT1[j] < tempT1[minIndex]) {
                minIndex = j;
            }
        }
        // Trocando o elemento mínimo com o primeiro elemento não classificado
        int tempValue = tempT1[minIndex];
        tempT1[minIndex] = tempT1[i];
        tempT1[i] = tempValue;
    }

    // Imprimindo os elementos da Tabela 1 em ordem crescente
    for (i = 0; i < countT1; i++) {
        printf("%d,T1,%d\n", tempT1[i], h1(tempT1[i]));
    }
}

// Função para imprimir a tabela 2 em ordem crescente
void imprimeTabela2(int T2[]){
    int i;
    int tempT2[m];
    int countT2 = 0;

    // Copiando os elementos da Tabela 2 para o vetor temporário
    for (i = 0; i < m; i++) {
        if (T2[i] != INIT && T2[i] != EXCL) {
            tempT2[countT2] = T2[i];
            countT2++;
        }
    }

    // Ordenando o vetor temporário da Tabela 2 em ordem crescente
    for (i = 0; i < countT2 - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < countT2; j++) {
            if (tempT2[j] < tempT2[minIndex]) {
                minIndex = j;
            }
        }
        // Trocando o elemento mínimo com o primeiro elemento não classificado
        int tempValue = tempT2[minIndex];
        tempT2[minIndex] = tempT2[i];
        tempT2[i] = tempValue;
    }

    // Imprimindo os elementos da Tabela 2 em ordem crescente
    for (i = 0; i < countT2; i++) {
        printf("%d,T2,%d\n", tempT2[i], h2(tempT2[i]));
    }
}

// Função para imprimir a tabela
void imprime(int T1[], int T2[]){
    imprimeTabela2(T2);
    imprimeTabela1(T1);
}


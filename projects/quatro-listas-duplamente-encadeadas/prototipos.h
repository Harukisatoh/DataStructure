#ifndef PROTOTIPOS_H_INCLUDED //Detecção de cabeçalho
#define PROTOTIPOS_H_INCLUDED //Definição de cabeçalho

#include <stdio.h> //Biblioteca de entrada e saída
#include <stdlib.h> //Biblioteca padrão
#define MAX 50 //Criação da constante MAX

typedef int TIPOCHAVE;

typedef struct {
    TIPOCHAVE chave;
    //Outros atributos
} REGISTRO; // Estrutura de um registro, armazena os atributos de cada elemento da lista

typedef struct aux {
    REGISTRO reg;
    struct aux *prox;
    struct aux *ant;
} ELEMENTO; //Estrutura de uma elemento, armazena um registro e um ponteiro para o próximo elemento

typedef struct {
    ELEMENTO *inicio;
    ELEMENTO *fim;
} LISTA; //Estrutura de uma lista, armazena um ponteiro para o primeiro elemento e o número totais de elementos

//Prototipação


#endif // PROTOTYPES_H_INCLUDED

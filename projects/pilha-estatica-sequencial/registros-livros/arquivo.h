#ifndef ARQUIVO_H_INCLUDED
#define ARQUIVO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

typedef struct {
    char nome[MAX];
    char autor[MAX];
    int isbn;
    int codigo;
    int ano;
    int nmrPag;
} REGISTRO;

typedef struct {
    REGISTRO A[MAX];
    int topo;
} PILHA;

void inicializar (PILHA *p);
void reinicializar (PILHA *p);
int tamanho (PILHA *p);
void exibirPilha (PILHA *p);
int inserir (PILHA *p, REGISTRO reg);
int excluir (PILHA *p, REGISTRO *reg);

#endif // ARQUIVO_H_INCLUDED

#ifndef ARQUIVO_H_INCLUDED
#define ARQUIVO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#define MAX 50

typedef int TIPOCHAVE;

typedef struct {
    TIPOCHAVE chave;
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

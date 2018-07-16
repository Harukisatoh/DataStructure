/*
 * @author: Gabriel Haruki Gomes Satô
 */

#ifndef PROTOTIPOS_H
#define PROTOTIPOS_H

#include <stdio.h>
#include <stdlib.h>
#define MAX 50

typedef int TIPOCHAVE;

typedef struct {
    TIPOCHAVE chave;
} REGISTRO;

typedef struct {
    REGISTRO A[MAX];
    int inicio;
    int nmrElem;
} FILA;

//Protótipos
void inicializar (FILA *f);
int qtdElem (FILA *f);
void exibir (FILA *f);
void inserir (FILA *f, REGISTRO reg);
void excluir (FILA *f, REGISTRO *reg);
void reinicializar (FILA *f);

#endif // PROTOTIPOS_H

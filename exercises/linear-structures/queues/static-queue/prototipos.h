/*
 * @author: Gabriel Haruki Gomes Satô
 */

#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#define MAX 3

typedef int TIPOCHAVE;

//Estrutura de um registro
typedef struct {
    TIPOCHAVE chave;
    //Informações de cada elemento integrante da fila
} REGISTRO;

//Estrutura de uma fila
typedef struct {
    REGISTRO A[MAX];
    int inicio;
    int nmrElem;
} FILA;

//Protótipos

#endif //PROTOTIPOS_H_INCLUDED

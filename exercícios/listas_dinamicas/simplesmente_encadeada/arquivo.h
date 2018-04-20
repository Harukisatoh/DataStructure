#include <stdio.h>
#include <stdlib.h>

//RENOMEAÇÃO DE VARIÁVEIS
typedef int TIPOCHAVE;

//DEFINIÇÃO DE STRUCTS
typedef struct {
    TIPOCHAVE chave;
}REGISTRO;

typedef struct aux{
    REGISTRO reg;
    struct aux* prox;
}ELEMENTO;

//RENOMEAÇÃO DE VARIÁVEIS
typedef ELEMENTO* PONT;

typedef struct {
    PONT inicio;
}LISTA;

//PROTOTIPAÇÃO
void inicializar(LISTA *l);
void insercaoDesordenada(LISTA *l, REGISTRO reg);
void insercaoOrdenada(LISTA *l, REGISTRO reg);
void exibirLista(LISTA *l);
void reinicializar(LISTA *l);

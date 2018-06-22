//DEFINES E INCLUDES
//DEFINES AND INCLUDES
#include <stdio.h> //Biblioteca para entrada e saída / Library for input and output
#include <stdlib.h> //Biblioteca padrão / Standard library

//DECLARAÇÃO DE ESTRUTURAS E TIPOS
//DECLARATION OF STRUCTURES AND TYPES
typedef int TIPOCHAVE; //Define TIPOCHAVE como int / Defines TIPOCHAVE as int

typedef struct { //Define a estrutura de um registro / Defines the structure of a record
    TIPOCHAVE chave;
}REGISTRO;

typedef struct aux{ //Define a estrutura de um elemento / Defines the structure of a element
    REGISTRO reg;
    struct aux* prox; //Define um ponteiro de um elemento / Sets a pointer to an element
}ELEMENTO;

typedef ELEMENTO* PONT; //Define PONT como um ponteiro para ELEMENTO / Sets PONT as a pointer to ELEMENTO

typedef struct { //Define a estrutura de uma lista / Defines the structure of a list
    PONT inicio;
}LISTA;

//PROTÓTIPOS
//PROTOTYPES
void inicializar(LISTA *l);
void insercaoDesordenada(LISTA *l, REGISTRO reg);
void insercaoOrdenada(LISTA *l, REGISTRO reg);
void exibirLista(LISTA *l);
void reinicializar(LISTA *l);

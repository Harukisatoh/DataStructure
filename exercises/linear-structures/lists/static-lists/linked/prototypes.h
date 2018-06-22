//DEFINES E INCLUDES
//DEFINES AND INCLUDES
#include <stdio.h> //Biblioteca para entrada e saída / Library for input and output
#include <stdlib.h> //Biblioteca padrão / Standard library
#define MAX 50 //Define MAX com o valor de 50 / Sets MAX with the value of 50
#define INVALIDO -1 //Define INVALIDO com o valor de -1 / Sets INVALIDO with the value of -1

//DECLARAÇÃO DE ESTRUTURAS E TIPOS
//DECLARATION OF STRUCTURES AND TYPES
typedef int TIPOCHAVE; //Define TIPOCHAVE como int / Defines TIPOCHAVE as int

typedef struct{ //Define a estrutura de um registro / Defines the structure of a record
  TIPOCHAVE chave;
  //Outros atributos
  //Other attributes
} REGISTRO;

typedef struct { //Define a estrutura de um elemento / Defines the structure of a element
    REGISTRO reg;
    int prox;
} ELEMENTO;

typedef struct{ //Define a estrutura de uma lista / Defines the structure of a list
  ELEMENTO A[MAX];
  int nmrElem;
  int inicio;
  int dispo;
} LISTA;

//PROTÓTIPOS
//PROTOTYPES
void inicializa (LISTA* l);
int tamanho (LISTA* l);
int inserirElemListaOrd (LISTA* l, REGISTRO reg);
int excluirElemLista (LISTA *l, TIPOCHAVE ch);
void devolverNo (LISTA *l, int j);
void exibirLista (LISTA *l);
int buscaSequencialOrd (LISTA *l, TIPOCHAVE ch);
void reinicializarLista (LISTA *l);

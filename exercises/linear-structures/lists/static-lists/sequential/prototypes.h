/*
 * @author: Gabriel Haruki Gomes Satô
 */

//DEFINIÇÃO DE CONSTANTES
//CONSTANTS DEFINITION
#define MAX 50 //Define MAX com o valor de 50 / Sets MAX with the value of 50

//DECLARAÇÃO DE ESTRUTURAS E TIPOS
//DECLARATION OF STRUCTURES AND TYPES
typedef int TIPOCHAVE; //Define TIPOCHAVE como int / Defines TIPOCHAVE as int

typedef struct{ //Define a estrutura de um registro / Defines the structure of a record
    TIPOCHAVE chave;
    //Outros atributos
    //Other attributes
} REGISTRO;

typedef struct{ //Define a estrutura de uma lista / Defines the structure of a list
    REGISTRO A[MAX+1];
    int nmrElem;
} LISTA;

//PROTÓTIPOS
//PROTOTYPES
void inicializarLista(LISTA* l);
int tamanho(LISTA* l);
void exibirLista(LISTA* l);
//int buscaSequencial(LISTA* l, TIPOCHAVE ch);
//int buscaSentinela(LISTA* l, TIPOCHAVE ch);
int buscaBinaria(LISTA* l, TIPOCHAVE ch);
//int inserirElemLista(LISTA* l, REGISTRO reg, int i);
int inserirElemListaOrd(LISTA* l, REGISTRO reg);
int excluirElemLista(TIPOCHAVE ch, LISTA* l);
void reinicializarLista(LISTA*l);

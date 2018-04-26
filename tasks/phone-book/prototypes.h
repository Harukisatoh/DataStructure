//DEFINES E INCLUDES
//DEFINES AND INCLUDES
#ifndef HEADER_H //Detecção de cabeçalho / Header detection
#define HEADER_H //Definição de cabeçalho / Header setting
#define TAM 50 //Define TAM com o valor de 50 / Sets TAM with the value of 50
#include <string.h> //Biblioteca para manipulação de string / Library for string manipulation
#include <stdio.h> //Biblioteca para entrada e saída / Library for input and output

//DECLARAÇÃO DE ESTRUTURAS
//STRUCTURES DECLARATION
typedef struct {
    char nome[TAM];
    char endereco[TAM];
    char numero[TAM];
} REGISTRO; //Estrutura para registro dos contatos / Structure for registering contacts


typedef struct {
    REGISTRO A[TAM];
    int nmrElem;
} LISTA; //Lista de contato / Contact list

//PROTÓTIPOS
//PROTOTYPES
void menuInicial();
int tamLista(LISTA *l);
void atualizarLista(LISTA *l);
void cadastrarElemento(LISTA *l, REGISTRO reg);
void exibirLista(LISTA *l);
int buscaBinaria(LISTA *l, REGISTRO nome);
int buscarEnd(LISTA *l, REGISTRO endereco);
int buscarTel(LISTA *l, REGISTRO tel);
int exclusao(LISTA *l, REGISTRO reg);

#endif	//HEADER_H

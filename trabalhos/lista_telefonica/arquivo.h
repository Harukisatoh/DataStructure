#ifndef HEADER_H // Detecção de cabeçalho.
#define HEADER_H // Definição de cabeçalho.
#define TAM 50 // Define TAM com o valor de 50.
#include <string.h> // Biblioteca para manipulação de strings.
#include <stdio.h>

//DECLARAÇÃO DE ESTRUTURAS

typedef struct {
    char nome[TAM];
    char endereco[TAM];
    char numero[TAM];
} REGISTRO; // Estrutura para registro dos contatos.


typedef struct {
    REGISTRO A[TAM];
    int nmrElem;
} LISTA; // Lista de contato.

// PROTÓTIPOS
void menuInicial();
int tamLista(LISTA *l);
void atualizarLista(LISTA *l);
void cadastrarElemento(LISTA *l, REGISTRO reg);
void exibirLista(LISTA *l);
int buscaBinaria(LISTA *l, REGISTRO nome);
int buscarEnd(LISTA *l, REGISTRO endereco);
int buscarTel(LISTA *l, REGISTRO tel);
int exclusao(LISTA *l, REGISTRO reg);

#endif	// HEADER_H

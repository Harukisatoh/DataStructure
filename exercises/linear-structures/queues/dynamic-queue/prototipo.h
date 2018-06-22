/*
 * @author: Gabriel Haruki Gomes Satô
 */

 #ifndef PROTOTIPOS_H_INCLUDED
 #define PROTOTIPOS_H_INCLUDED

 #include <stdio.h>
 #include <stdlib.h>
 #define MAX 50

 typedef int TIPOCHAVE;

 //Estrutura de um registro
 typedef struct {
     TIPOCHAVE chave;
     //Informações de cada elemento integrante da fila
 } REGISTRO;

 //Estrutura de um elemento
 typedef struct aux{
     REGISTRO reg;
     struct aux* prox;
 } ELEMENTO;

 //Estrutura de uma fila
 typedef struct {
     ELEMENTO* inicio;
     ELEMENTO* fim;
     int nmrElem;
 } FILA;

 //Protótipos

 void inicializar (FILA *f);
 void inserir (FILA *f, REGISTRO reg);
 void exibir (FILA *f);
 int numeroElemento (FILA *f);
 int excluir (FILA *f);
 void reinicializar (FILA *f);

 #endif //PROTOTIPOS_H_INCLUDED

//----------------------------------------início do cabeçalho
//IMPLEMENTAÇÃO DO TRABALHO SUPER BÔNUS–E.D.
//Nome: GABRIEL HARUKI GOMES SATÔ       RA: 120150
//Nome:_____________________________________________       RA:_______
//-----------------------------------------final do cabeçalho

#include "prototipos.h"
#include "funcoes.c"

int main () {

    LISTA lista1;
    LISTA lista2;
    LISTA lista3;
    LISTA lista4;
    REGISTRO reg;

    inicializarLista (lista1);
    inicializarLista (lista2);
    inicializarLista (lista3);
    inicializarLista (lista4);

    reg.chave = 30;
    inserirOrdCresc (&lista1, reg);
    reg.chave = 4;
    inserirOrdCresc (&lista1, reg);
    reg.chave = 70;
    inserirOrdCresc (&lista1, reg);
    reg.chave = 7;
    inserirOrdCresc (&lista1, reg);


    reg.chave = 70;
    inserirOrdDecres (&lista2, reg);
    reg.chave = 3;
    inserirOrdDecres (&lista2, reg);
    reg.chave = 31;
    inserirOrdDecres (&lista2, reg);
    reg.chave = 4;
    inserirOrdDecres (&lista2, reg);


    reg.chave = 2;
    inserirOrdDecres (&lista3, reg);
    reg.chave = 7;
    inserirOrdDecres (&lista3, reg);
    reg.chave = 31;
    inserirOrdDecres (&lista3, reg);
    reg.chave = 30;
    inserirOrdDecres (&lista3, reg);

    return 0;
}

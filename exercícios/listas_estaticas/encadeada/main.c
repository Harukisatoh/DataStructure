//WIP

#include <stdio.h>
#include <stdlib.h>
#include "arquivo.h"
#include "arquivo.c"

int main(){

    REGISTRO reg;
    LISTA lista1;

    inicializa(&lista1);
    printf("Tamanho: %d\n", tamanho(&lista1));
    teste(&lista1);

}

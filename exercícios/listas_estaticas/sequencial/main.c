#include <stdio.h> //Standard bib
#include <stdlib.h> //Malloc bib
#include <math.h> //Floor bib
#include "arquivo.h"
#include "arquivo.c"

int main(){
  REGISTRO reg;
  LISTA lista1;

  inicializarLista(&lista1);
  reg.chave = 55;
  inserirElemListaOrd(&lista1, reg);
  reg.chave = 32;
  inserirElemListaOrd(&lista1, reg);
  reg.chave = 89;
  inserirElemListaOrd(&lista1, reg);
  exibirLista(&lista1);
  printf("Busca: %d\n", buscaBinaria(&lista1, 32));
  printf("Tamanho da lista: %d\n", tamanho(&lista1));


  return 0;
}

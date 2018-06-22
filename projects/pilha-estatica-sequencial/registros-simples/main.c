/*
 * Nome: Gabriel Haruki Gomes Satô     RA: 120150
 *
 * Trabalho: Implementação de uma pilha estática sequencial. A pilha, diferente
 * das estruturas de dados do tipo lista, têm uma ordem correta para inserção e
 * exclusão. A inserção insere apenas no topo da pilha, e a exclusão exclui
 * apenas o elemento que está no topo da pilha. Utiliza uma lógica similar ao
 * de uma pilha de livros. Na implementação, a base da pilha se encontra na
 * posição 0, e o topo da pilha se encontra na posição 'topo'. Neste trabalho
 * em específico, é utilizado a implementação estática da pilha, ou seja,
 * definimos um array com um número pré-definidos de elementos, nesse caso de
 * tamanho MAX = 50.
 */

#include "arquivo.h"
#include "arquivo.c"

int main () {

    PILHA pilha1;
    REGISTRO reg;

    inicializar (&pilha1);

    reg.chave = 32;
    inserir (&pilha1, reg);

    reg.chave = 12;
    inserir (&pilha1, reg);

    reg.chave = 7;
    inserir (&pilha1, reg);

    reg.chave = 47;
    inserir (&pilha1, reg);

    exibirPilha (&pilha1);

    printf("\n\n");
    excluir (&pilha1, &reg);
    exibirPilha (&pilha1);
    printf("\n\n");

    printf("Elemento removido: %d", reg.chave);

    reinicializar (&pilha1);

    return 0;
}

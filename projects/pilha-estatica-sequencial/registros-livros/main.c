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

    strcpy (reg.nome, "Como programar em Python");
    strcpy (reg.autor, "Vitor Oliveira V");
    reg.isbn = 1654;
    reg.codigo = 4565;
    reg.ano = 2013;
    reg.nmrPag = 600;
    inserir (&pilha1, reg);

    strcpy (reg.nome, "Estrutura de Dados em C");
    strcpy (reg.autor, "Tamara Baldo");
    reg.isbn = 4846;
    reg.codigo = 9756;
    reg.ano = 1996;
    reg.nmrPag = 897;
    inserir (&pilha1, reg);

    strcpy (reg.nome, "Teoria da Computacao");
    strcpy (reg.autor, "Wellington Dellamura");
    reg.isbn = 132;
    reg.codigo = 9986;
    reg.ano = 2000;
    reg.nmrPag = 435;
    inserir (&pilha1, reg);

    strcpy (reg.nome, "Algebra Linear");
    strcpy (reg.autor, "Maisa Milani");
    reg.isbn = 457;
    reg.codigo = 895;
    reg.ano = 2015;
    reg.nmrPag = 1086;
    inserir (&pilha1, reg);

    exibirPilha (&pilha1);

    printf("\n\n\n");
    excluir (&pilha1, &reg);
    exibirPilha (&pilha1);
    printf("\n\n\n");
    exibirElemento (&pilha1, reg);

    reinicializar (&pilha1);

    return 0;
}

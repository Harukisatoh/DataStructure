#include "arquivo.h"

void inicializar (PILHA *p) {
    p->topo = -1;
}

void reinicializar (PILHA *p) {
    inicializar (p);
}

int tamanho (PILHA *p) {
    return (p->topo + 1);
}

void exibirPilha (PILHA *p) {

    int i = 0, j = 1;

    printf("PILHA:\n\n");
    for (i = p->topo, j = 1; i >= 0; i--, j++) {
        printf("==========================================================\n");
        printf("\tLIVRO %d:\n\n", j);
        printf("\tNome: %s\n", p->A[i].nome);
        printf("\tAutor: %s\n", p->A[i].autor);
        printf("\tISBN: %d\n", p->A[i].isbn);
        printf("\tCodigo: %d\n", p->A[i].codigo);
        printf("\tAno de publicacao: %d\n", p->A[i].ano);
        printf("\tNumero de paginas: %d\n", p->A[i].nmrPag);
        printf("==========================================================\n");
    }

}

void exibirElemento (PILHA *p, REGISTRO reg) {
    printf("==========================================================\n");
    printf("\tELEMENTO REMOVIDO:\n\n");
    printf("\tNome: %s\n", reg.nome);
    printf("\tAutor: %s\n", reg.autor);
    printf("\tISBN: %d\n", reg.isbn);
    printf("\tCodigo: %d\n", reg.codigo);
    printf("\tAno de publicacao: %d\n", reg.ano);
    printf("\tNumero de paginas: %d\n", reg.nmrPag);
    printf("==========================================================\n");
}

int inserir (PILHA *p, REGISTRO reg) {

    if (p->topo >= (MAX - 1)) {
        return 0;
    }

    p->A[(p->topo + 1)] = reg;
    p->topo = p->topo + 1;
    return 1;

}

int excluir (PILHA *p, REGISTRO *reg) {

    if (p->topo == -1) {
        return 0;
    }

    *reg = p->A[p->topo];
    p->topo = p->topo - 1;
    return 1;

}

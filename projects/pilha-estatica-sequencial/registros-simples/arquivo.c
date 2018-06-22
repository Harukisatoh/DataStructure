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

    int i = 0;

    printf("Pilha:\n");
    for (i = p->topo; i >= 0; i--) {
        printf ("\t[%d]\n", p->A[i]);
    }

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

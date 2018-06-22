#include "prototipos.h"

void inicializarLista (LISTA *l) {
    l->inicio = NULL;
    l->fim = NULL;
}

void reinicializarLista (LISTA *l) {

    ELEMENTO *atual = l->inicio;

    while (atual != NULL) {

        l->inicio = l->inicio->prox;
        free (atual);
        atual = l->inicio;

    }

    l->inicio = NULL;

}

void exibirLista (LISTA *l) {

    ELEMENTO *atual = l->inicio;

    while (atual != NULL) {

        printf(" {%d} ", atual->reg.chave);
        atual = atual->prox;

    }

}

void inserirOrdCresc (LISTA *l, REGISTRO reg) {

    ELEMENTO *ant = NULL;
    ELEMENTO *atual = NULL;
    ELEMENTO *novo = NULL;

    novo = (ELEMENTO*) malloc (sizeof (ELEMENTO));

    if (novo == NULL) {
        printf ("ERRO NA ALOCACAO: inserir_elemento_cresc");
        return;
    }

    novo->reg = reg;
    novo->prox = NULL;
    novo->ant = NULL;

    atual = l->inicio;

    while (atual != NULL && atual->reg.chave < reg.chave) {
        ant = atual;
        atual = atual->prox;
    }

    novo->prox = atual;
    novo->ant = ant;

    if (ant == NULL) {

        l->inicio = novo;

        if (atual != NULL) {
            atual->ant = novo;
        }

    } else {

        ant->prox = novo;

        if (atual != NULL) {
            atual->ant = novo;
        }

    }

}

void inserirOrdDecres (LISTA *l, REGISTRO reg) {

    ELEMENTO *ant = NULL;
    ELEMENTO *atual = NULL;
    ELEMENTO *novo = NULL;

    novo = (ELEMENTO*) malloc (sizeof (ELEMENTO));

    if (novo == NULL) {
        printf ("ERRO NA ALOCACAO: inserir_elemento_cresc");
        return;
    }

    novo->reg = reg;
    novo->prox = NULL;
    novo->ant = NULL;

    atual = l->inicio;

    while (atual != NULL && atual->reg.chave > reg.chave) {
        ant = atual;
        atual = atual->prox;
    }

    novo->prox = atual;
    novo->ant = ant;

    if (ant == NULL) {

        l->inicio = novo;

        if (atual != NULL) {
            atual->ant = novo;
        }

    } else {

        ant->prox = novo;

        if (atual != NULL) {
            atual->ant = novo;
        }

    }

}

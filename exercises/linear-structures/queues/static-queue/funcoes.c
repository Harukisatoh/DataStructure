/*
 * @author: Gabriel Haruki Gomes Satô
 */

#include "prototipos.h"

//Inicializa a fila
void inicializar (FILA *f) {
    f->inicio = 0;
    f->nmrElem = 0;
}

//Insere um elemento na fila
int inserir (FILA *f, REGISTRO reg) {

    int pos_novo = 0;

    //Verifica se a fila está cheia, se sim, retorna 0 e não insere
    if (f->nmrElem >= MAX) {
        return 0;
    }

    //Calcula uma posição livre
    pos_novo = (f->inicio + f->nmrElem) % MAX;

    //Insere o elemento e incrementa a quantidade de elementos
    f->A[pos_novo] = reg;
    f->nmrElem = f->nmrElem + 1;

    return 1;
}

//Exclui o primeiro elemento inserido na fila
int excluir (FILA *f) {

    //Verifica se a fila está vazia, se sim, retorna 0 e não exclui
    if (f->nmrElem <= 0) {
        return 0;
    }

    /*
     * O elemento não é excluido de fato, porém a variável inicio e nmrElem são alterados,
     * portanto, para o programa o registro pode ser considerado como excluido
     */
    f->inicio = (f->inicio + 1) % MAX;
    f->nmrElem = f->nmrElem - 1;

    return 1;
}

//Exibe os elementos da fila
void exibir (FILA *f) {
    int i;

    //Percorre a fila elemento por elemento
    for (i = 0; i < f->nmrElem; i++) {
        //Imprime os elementos ordenado pela forma em que foram inseridos, o primeiro inserido é imprimido primeiro
        printf("\n[%d] = %d", i+1, f->A[(f->inicio + i) % MAX].chave);
    }
}

//Busca um elemento na fila
int buscar (FILA *f, TIPOCHAVE ch) {

    int i;

    //Percorre a fila elemento por elemento
    for (i = 0; i < f->nmrElem; i++) {

        //Verifica se o elemento atual é igual ao elemento buscado, se sim, retorna a posição do elemento
        if (ch == f->A[(f->inicio + i) % MAX].chave) {
            return ((f->inicio + i) % MAX);
        }

    }

    return -1;
}

//Reinicializa a fila
void reiniciar (FILA *f) {
    inicializar (f);
}

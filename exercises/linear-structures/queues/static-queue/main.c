/*
 * @author: Gabriel Haruki Gomes Satô
 */

#include "prototipos.h"
#include "funcoes.c"

int main () {

    //Criação de uma fila e um registro auxiliar
    FILA fila1;
    REGISTRO reg;

    //Inicializando a fila
    inicializar (&fila1);

    //Insere um elemento na fila
    reg.chave = 156;
    inserir (&fila1, reg);

    //Insere um elemento na fila
    reg.chave = 54;
    inserir (&fila1, reg);

    //Insere um elemento na fila
    reg.chave = 12;
    inserir (&fila1, reg);

    //Exibe a fila
    exibir (&fila1);
    printf("\n");

    //Exclui um elemento da fila
    excluir (&fila1, &reg);

    //Exibe a fila
    exibir (&fila1);

    //Exibe registro com o valor da exclusão efetuada
    printf("\nREGISTRO: %d\n", reg);

    //Exibe a quantidade de elementos da fila
    printf("QTD ELEM: %d\n", qtdElem (&fila1));

    //Reiniciar a fila
    reinicializar (&fila1);

    //Tenta exibir a fila novamente
    exibir (&fila1);

    return 0;
}

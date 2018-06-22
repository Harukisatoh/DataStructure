/*
 * @author: Gabriel Haruki Gomes Satô
 */

#include "prototipos.h"
#include "funcoes.c"

//Função principal
int main () {

    //Aloca uma fila e cria um registro auxiliar
    FILA fila1;
    REGISTRO reg;

    //Inicializa a fila
    inicializar (&fila1);

    //Insere um elemento na fila
    reg.chave = 10;
    inserir (&fila1, reg);

    //Insere um elemento na fila
    reg.chave = 15;
    inserir (&fila1, reg);

    //Insere um elemento na fila
    reg.chave = 98;
    inserir (&fila1, reg);

    //Insere um elemento na fila
    reg.chave = 56;
    inserir (&fila1, reg);

    //Exibe todos os elementos da fila
    exibir (&fila1);
    printf("\nEXCLUINDO...\n");

    //Exclui o FIFO da fila
    excluir (&fila1);

    //Exibe todos os elementos da fila
    exibir (&fila1);

    return 0;
}

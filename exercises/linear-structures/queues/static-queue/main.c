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

    //Insere um elemento
    reg.chave = 30;
    if(inserir (&fila1, reg) == 0) {
        printf("Erro ao inserir a chave %d\n", reg.chave);
    }

    //Insere um elemento
    reg.chave = 20;
    if(inserir (&fila1, reg) == 0) {
        printf("Erro ao inserir a chave %d\n", reg.chave);
    }

    //Insere um elemento
    reg.chave = 15;
    if(inserir (&fila1, reg) == 0) {
        printf("Erro ao inserir a chave %d\n", reg.chave);
    }

    //Insere um elemento
    reg.chave = 55;
    if(inserir (&fila1, reg) == 0) {
        printf("Erro ao inserir a chave %d\n", reg.chave);
    }

    //Exclui o primeiro elemento
    excluir (&fila1);

    //Insere um elemento
    reg.chave = 55;
    if(inserir (&fila1, reg) == 0) {
        printf("Erro ao inserir a chave %d\n", reg.chave);
    }

    //Exibe toda a fila
    exibir (&fila1);

    return 0;
}

/*
 *
 * @author: Gabriel Haruki Gomes Satô
 *
 * Trabalho: Implementação de uma lista telefônica utilizando lista
 * sequencial estática, contém funções de menu, tamanho,
 * inicializar/reinicializar/atualizar a lista, inserir, exibir lista,
 * busca por nome, busca por endereço, busca por telefone e excluir.
 *
 */

//DEFINES E INCLUDES

#include <stdio.h>
#include <stdlib.h>
#include "arquivo.h"
#include "arquivo.c"

//Função principal
int main() {

    //Declaração de variáveis
    REGISTRO reg;
    LISTA lista;
    int op, pos;

    //Inicializa a lista
    atualizarLista(&lista);

    //Interação com o usuário
    do {
        //Chama o menu
        menuInicial();

        //Recebe entradas do usuário
        printf("Escolha uma opcao: ");
        scanf("%i", &op);
        puts("");

        //Alterna as opções que serão executadas de acordo com o valor da variável 'op'
        switch (op) {
            case 1:
                //Cadastra um novo registro
                cadastrarElemento(&lista, reg);
            break;
            case 2:
                //Exclui um registro escolhido pelo usuário
                exclusao(&lista, reg);
            break;
            case 3:
                //Exibe todos os registros
                exibirLista(&lista);
            break;
            case 4:
                //Busca um registro de acordo com o nome fornecido pelo usuário
                pos = buscaBinaria(&lista, reg);

                //Retorna o resultado para o usuário
                if(pos != -1) {//167
                    printf("\nO registro buscado e o %i%lc contato, e esta na posicao %i!\n", (pos + 1), (wint_t)167, pos);
                } else {
                    puts("\nREGISTRO NAO ENCONTRADO!");
                }

                //Retorna ao menu
                puts("Pressione ENTER para voltar ao menu.");
                setbuf(stdin, NULL);
                getchar();
            break;
            case 5:
                //Busca um registro de acordo com o endereço fornecido pelo usuário
                pos = buscarEnd(&lista, reg);

                //Retorna o resultado para o usuário
                if(pos != -1) {
                    printf("\nO registro buscado e o %i%lc contato, e esta na posicao %i!\n", (pos + 1), (wint_t)167, pos);
                } else {
                    puts("\nREGISTRO NAO ENCONTRADO!");
                }

                //Retorna ao menu
                puts("Pressione ENTER para voltar ao menu.");
                setbuf(stdin, NULL);
                getchar();
            break;
            case 6:
                //Busca um registro de acordo com o telefone fornecido pelo usuário
                pos = buscarTel(&lista, reg); //Retorna o resultado para o usuário

                if(pos != -1) {
                    printf("\nO registro buscado e o %i%lc contato, e esta na posicao %i!\n", (pos + 1), (wint_t)167, pos);
                } else {
                    puts("\nREGISTRO NAO ENCONTRADO!");
                }
                //Retorna ao menu
                puts("Pressione ENTER para voltar ao menu.");
                setbuf(stdin, NULL);
                getchar();
            break;
            case 7:
                //Apaga todos os registros
                atualizarLista(&lista);

                //Retorno para o usuário
                puts("\nTODOS OS REGISTROS FORAM APAGADOS!");
                setbuf(stdin, NULL);
                getchar();
            break;
            case 8:
                //O loop é quebrado e então o programa fecha
            break;
            default:
                //Caso a opção seja inválida retorna ao usuário
                puts("\nOPCAO INVALIDA");
                setbuf(stdin, NULL);
                getchar();
        }
    } while(op != 8);
    return 0;
}

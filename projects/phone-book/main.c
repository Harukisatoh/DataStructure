/*
 *
 * @author: Gabriel Haruki Gomes Satô
 *
 * Trabalho: Implementação de uma lista telefônica utilizando lista
 * sequencial estática, contém funções de menu, tamanho,
 * inicializar/reinicializar/atualizar a lista, inserir, exibir lista,
 * busca por nome, busca por endereço, busca por telefone e excluir
 *
 * Task: Implementation of a Phone Book using static sequential list,
 * contains functions of menu, size, initialize/restart/refresh the list,
 * insert, show list, search by name, search by address, search by phone,
 * and delete
 *
 */

//DEFINES E INCLUDES
//DEFINES AND INCLUDES

#include <stdio.h> //Biblioteca para entrada e saída / Library for input and output
#include <stdlib.h> //Biblioteca padrão / Standard library
#include "prototypes.h" //Inclusão do arquivo "prototypes.h" / Inclusion of the file "prototypes.h"
#include "functions.c" //Inclusão do arquivo "functions.c" / Inclusion of the file "functions.c"

//Função principal
//Main function
int main() {

    //Declaração de variáveis
    //Declaration
    REGISTRO reg;
    LISTA lista;
    int op, pos;

    //Inicializa a lista
    //Initializes the list
    atualizarLista(&lista);

    //Interação com o usuário
    //User Interaction
    do {
        //Chama o menu
        //Calls the menu function
        menuInicial();

        //Recebe entradas do usuário
        //Receives user input
        printf("Escolha uma opcao: ");
        scanf("%i", &op);
        puts("");

        //Alterna as opções que serão executadas de acordo com o valor da variável 'op'
        //Toggles the options that will be executed according to the value of the variable 'op'
        switch (op) {
            case 1:
                //Cadastra um novo registro
                //Registers a new record
                cadastrarElemento(&lista, reg);
            break;
            case 2:
                //Exclui um registro escolhido pelo usuário
                //Deletes a user-selected record
                exclusao(&lista, reg);
            break;
            case 3:
                //Exibe todos os registros
                //Displays all records
                exibirLista(&lista);
            break;
            case 4:
                //Busca um registro de acordo com o nome fornecido pelo usuário
                //Finds a record according to the name given by the user
                pos = buscaBinaria(&lista, reg);

                //Retorna o resultado para o usuário
                //Returns the result for the user
                if(pos != -1) {
                    //"(wint_t)167" é usado para que um caractere especial seja inserido
                    //"(wint_t)167" is used to enter a special character
                    printf("\nO registro buscado e o %i%lc contato, e esta na posicao %i!\n", (pos + 1), (wint_t)167, pos);
                } else {
                    puts("\nREGISTRO NAO ENCONTRADO!");
                }

                //Retorna ao menu
                //Returns to the menu
                puts("Pressione ENTER para voltar ao menu.");
                setbuf(stdin, NULL); //Define o buffer da memória pra NULL / Sets the memory buffer to NULL
                getchar();
            break;
            case 5:
                //Busca um registro de acordo com o endereço fornecido pelo usuário
                //Finds a record according to the adress given by the user
                pos = buscarEnd(&lista, reg);

                //Retorna o resultado para o usuário
                //Returns the result for the user
                if(pos != -1) {
                    printf("\nO registro buscado e o %i%lc contato, e esta na posicao %i!\n", (pos + 1), (wint_t)167, pos);
                } else {
                    puts("\nREGISTRO NAO ENCONTRADO!");
                }

                //Retorna ao menu
                //Returns to the menu
                puts("Pressione ENTER para voltar ao menu.");
                setbuf(stdin, NULL); //Define o buffer da memória pra NULL / Sets the memory buffer to NULL
                getchar();
            break;
            case 6:
                //Busca um registro de acordo com o telefone fornecido pelo usuário
                //Finds a record according to the phone given by the user
                pos = buscarTel(&lista, reg);

                if(pos != -1) {
                    printf("\nO registro buscado e o %i%lc contato, e esta na posicao %i!\n", (pos + 1), (wint_t)167, pos);
                } else {
                    puts("\nREGISTRO NAO ENCONTRADO!");
                }

                //Retorna ao menu
                //Returns to the menu
                puts("Pressione ENTER para voltar ao menu.");
                setbuf(stdin, NULL); //Define o buffer da memória pra NULL / Sets the memory buffer to NULL
                getchar();
            break;
            case 7:
                //Apaga todos os registros
                //Deletes all records
                atualizarLista(&lista);

                //Retorno para o usuário
                //Returns to the user
                puts("\nTODOS OS REGISTROS FORAM APAGADOS!");
                setbuf(stdin, NULL); //Define o buffer da memória pra NULL / Sets the memory buffer to NULL
                getchar();
            break;
            case 8:
                //O loop é quebrado e então o programa fecha
                //The loop is terminated and then the program closes
            break;
            default:
                //Caso a opção seja inválida retorna ao usuário
                //If 'op' is invalid returns to the user
                puts("\nOPCAO INVALIDA");
                setbuf(stdin, NULL); //Define o buffer da memória pra NULL / Sets the memory buffer to NULL
                getchar();
        }
    } while(op != 8);
    return 0;
}

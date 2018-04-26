//DEFINES E INCLUDES
//DEFINES AND INCLUDES
#include <stdio.h> //Biblioteca para entrada e saída / Library for input and output
#include <stdlib.h> //Biblioteca padrão / Standard library
#include <math.h> //Biblioteca para funções matemáticas / Library for mathematical functions
#include "prototypes.h" //Inclusão do arquivo "prototypes.h" / Inclusion of the file "prototypes.h"
#include "functions.c" //Inclusão do arquivo "functions.c" / Inclusion of the file "functions.c"

//Função principal
//Main function
int main(){

    //Declaração de variáveis
    //Declaration
    REGISTRO reg;
    LISTA lista1;

    //TESTES PARA VERIFICAÇÃO DAS FUNCIONALIDADES
    //TESTS FOR VERIFICATION OF FUNCTIONALITIES

    //Inicializa a lista
    //Initializes the list
    inicializarLista(&lista1);

    //Inserção do número '55' em um registro auxiliar localizado no arquivo main
    //Insertion of the number '55' into an auxiliary record located in the main file
    reg.chave = 55;

    //Inserção do registro auxiliar na lista
    //Inserting the auxiliary record into the list
    inserirElemListaOrd(&lista1, reg);

    //Inserção do número '32' em um registro auxiliar localizado no arquivo main
    //Insertion of the number '32' into an auxiliary record located in the main file
    reg.chave = 32;

    //Inserção do registro auxiliar na lista
    //Inserting the auxiliary record into the list
    inserirElemListaOrd(&lista1, reg);

    //Inserção do número '89' em um registro auxiliar localizado no arquivo main
    //Insertion of the number '89' into an auxiliary record located in the main file
    reg.chave = 89;

    //Inserção do registro auxiliar na lista
    //Inserting the auxiliary record into the list
    inserirElemListaOrd(&lista1, reg);

    //Exibe a lista
    //Displays the list
    exibirLista(&lista1);

    //Busca o número '32' e exibe a posição caso encontre
    //Finds the number '32' and displays the position if found
    printf("Busca: %d\n", buscaBinaria(&lista1, 32));

    //Verifica o tamanho da lista e exibe o resultado
    //Checks the size of the list and display the result
    printf("Tamanho da lista: %d\n", tamanho(&lista1));


    return 0;
}

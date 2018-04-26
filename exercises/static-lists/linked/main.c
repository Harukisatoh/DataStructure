//DEFINES E INCLUDES
//DEFINES AND INCLUDES
#include "prototypes.h" //Inclusão do arquivo "prototypes.h" / Inclusion of the file "prototypes.h"
#include "functions.c" //Inclusão do arquivo "functions.c" / Inclusion of the file "functions.c"

//Função principal
//Main function
int main (){

    //Declaração de variáveis
    //Declaration
    REGISTRO reg;
    LISTA lista1;

    //TESTES PARA VERIFICAÇÃO DAS FUNCIONALIDADES
    //TESTS FOR VERIFICATION OF FUNCTIONALITIES

    //Inicializa a lista
    //Initializes the list
    inicializa (&lista1);

    //Inserção do número '32' em um registro auxiliar localizado no arquivo main
    //Insertion of the number '32' into an auxiliary record located in the main file
    reg.chave = 32;

    //Inserção do registro auxiliar na lista
    //Inserting the auxiliary record into the list
    inserirElemListaOrd(&lista1, reg);

    //Inserção do número '24' em um registro auxiliar localizado no arquivo main
    //Insertion of the number '24' into an auxiliary record located in the main file
    reg.chave = 24;

    //Inserção do registro auxiliar na lista
    //Inserting the auxiliary record into the list
    inserirElemListaOrd(&lista1, reg);

    //Inserção do número '45456' em um registro auxiliar localizado no arquivo main
    //Insertion of the number '45456' into an auxiliary record located in the main file
    reg.chave = 45456;

    //Inserção do registro auxiliar na lista
    //Inserting the auxiliary record into the list
    inserirElemListaOrd(&lista1, reg);

    //Inserção do número '4' em um registro auxiliar localizado no arquivo main
    //Insertion of the number '4' into an auxiliary record located in the main file
    reg.chave = 4;

    //Inserção do registro auxiliar na lista
    //Inserting the auxiliary record into the list
    inserirElemListaOrd(&lista1, reg);

    //Inserção do número '566' em um registro auxiliar localizado no arquivo main
    //Insertion of the number '566' into an auxiliary record located in the main file
    reg.chave = 566;

    //Inserção do registro auxiliar na lista
    //Inserting the auxiliary record into the list
    inserirElemListaOrd(&lista1, reg);

    //Exibe a lista
    //Displays the list
    exibirLista(&lista1);

    //Exclui a chave que o usuário define
    //Deletes the key that the user sets
    excluirElemLista(&lista1, 32);

    //Exibe os contatos cadastrados
    //Displays the registered contacts
    exibirLista(&lista1);

    //Faz uma busca por alguma chave
    //Does a search for some key
    printf("O elemento buscado esta na posicao: %d\n", buscaSequencialOrd(&lista1, 4));


    //Reinicia a lista
    //Restarts the list
    reinicializarLista(&lista1);
}

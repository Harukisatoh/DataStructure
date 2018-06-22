//WIP - Falta as buscas

//DEFINES E INCLUDES
//DEFINES AND INCLUDES
#include "prototypes.h" //Inclusão do arquivo "prototypes.h" / Inclusion of the file "prototypes.h"
#include "functions.c" //Inclusão do arquivo "functions.c" / Inclusion of the file "functions.c"

//Função principal
//Main function
int main() {

    //Declaração de variáveis
    //Declaration
    LISTA lista;
    REGISTRO reg;

    //TESTES PARA VERIFICAÇÃO DAS FUNCIONALIDADES
    //TESTS FOR VERIFICATION OF FUNCTIONALITIES

    //Inicializa a lista
    //Initializes the list
    inicializar(&lista);

    //Inserção do número '8' em um registro auxiliar localizado no arquivo main
    //Insertion of the number '8' into an auxiliary record located in the main file
    reg.chave = 8;

    //Inserção do registro auxiliar na lista
    //Inserting the auxiliary record into the list
    insercaoOrdenada(&lista, reg);

    //Inserção do número '10' em um registro auxiliar localizado no arquivo main
    //Insertion of the number '10' into an auxiliary record located in the main file
    reg.chave = 10;

    //Inserção do registro auxiliar na lista
    //Inserting the auxiliary record into the list
    insercaoOrdenada(&lista, reg);

    //Inserção do número '3' em um registro auxiliar localizado no arquivo main
    //Insertion of the number '3' into an auxiliary record located in the main file
    reg.chave = 3;

    //Inserção do registro auxiliar na lista
    //Inserting the auxiliary record into the list
    insercaoOrdenada(&lista, reg);

    //Inserção do número '5' em um registro auxiliar localizado no arquivo main
    //Insertion of the number '5' into an auxiliary record located in the main file
    reg.chave = 5;

    //Inserção do registro auxiliar na lista
    //Inserting the auxiliary record into the list
    insercaoOrdenada(&lista, reg);

    //Inserção do número '4156' em um registro auxiliar localizado no arquivo main
    //Insertion of the number '4156' into an auxiliary record located in the main file
    reg.chave = 4156;

    //Inserção do registro auxiliar na lista
    //Inserting the auxiliary record into the list
    insercaoOrdenada(&lista, reg);

    //Exibe a lista
    //Displays the list
    exibirLista(&lista);

    //Libera toda a memória utilizada para alocar a lista
    //Releases all the memory used to allocate the list
    reinicializar(&lista);

    return 0;
}

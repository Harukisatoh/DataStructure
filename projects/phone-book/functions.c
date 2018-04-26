#include <stdio.h> //Biblioteca para entrada e saída / Library for input and output
#include <stdlib.h> //Biblioteca padrão / Standard library
#include <string.h> //Biblioteca para manipulação de string / Library for string manipulation
#include "prototypes.h" //Inclusão do arquivo "prototypes.h" / Inclusion of the file "prototypes.h"

//FUNÇÕES E PROCEDIMENTOS
//FUNCTIONS AND PROCEDURES
void menuInicial() {
    //Detecção de Sistema Linux para executar o comando system("clear")
    //Detection of Linux system to run the command system("clear")
    #ifdef __linux__
    system("clear");
    //Detecção de Sistema Windows para executar o comando system("cls")
    //Detection of Windows system to run the command system("cls")
    #elif defined WIN32
    system("cls");
    #endif

    //Menu de interação com o usuário
    //User interaction menu
    puts("====================");
    puts("LISTA TELEFONICA");
    puts("====================");
    puts("OPCOES:");
    puts("[1] Cadastrar contato");
    puts("[2] Excluir contato");
    puts("[3] Exibir contato");
    puts("[4] Buscar registro pelo nome");
    puts("[5] Buscar registro pelo endereco");
    puts("[6] Buscar registro pelo telefone");
    puts("[7] Reiniciar lista");
    puts("[8] Sair do programa");
    return;
}

//Retorna a quantidade de contatos salvos
//Returns the number of saved contacts
int tamLista(LISTA *l) {
    return l->nmrElem;
}

//Inicializa ou reinicializa a lista
//Initializes or resets the list
void atualizarLista(LISTA *l) {
    l->nmrElem = 0;
    return;
}

//Faz o registro de um elemento
//Registers an element
void cadastrarElemento(LISTA *l, REGISTRO reg) {

    //Variável de Iteração
    //Iteration Variable
    int i;

    //Verifica se a lista está cheia
    //Checks if the list is full
    if(l->nmrElem >= TAM) {
        puts("A LISTA ESTA CHEIA!");
        return;
    }

    //Recebe entradas do usuário
    //Receives user input
    printf("Digite o nome: ");
    setbuf(stdin, NULL); //Define o buffer da memória pra NULL / Sets the memory buffer to NULL
    fgets(reg.nome, TAM, stdin);
    printf("Digite o endereco: ");
    setbuf(stdin, NULL); //Define o buffer da memória pra NULL / Sets the memory buffer to NULL
    fgets(reg.endereco, TAM, stdin);
    printf("Digite o numero de telefone: ");
    setbuf(stdin, NULL); //Define o buffer da memória pra NULL / Sets the memory buffer to NULL
    fgets(reg.numero, TAM, stdin);

    //Inserção Ordenada com o algoritmo Insertion Sort
    //Ordered insertion with the Insertion Sort algorithm
    for(i = l->nmrElem; i > 0 && strcmp(reg.nome, l->A[i-1].nome) < 0; i--){
        l->A[i] = l->A[i-1];
    }
    l->A[i] = reg;
    l->nmrElem++;

    //Retorna para o usuário
    //Returns to the user
    puts("\nInsercao feita com sucesso!");
    puts("Pressione ENTER para voltar ao menu.");
    setbuf(stdin, NULL); //Define o buffer da memória pra NULL / Sets the memory buffer to NULL
    getchar(); //Espera até que a tecla ENTER seja pressionada / Waits until ENTER key to be pressed
    return;
}

//Exibe os contatos cadastrados
//Displays the registered contacts
void exibirLista(LISTA *l) {

    //Variável de Iteração
    //Iteration Variable
    int i = 0;

    /*
     * Verifica se a lista contém algum registro,
     * caso haja, os mesmos serão exibidos
     * Caso contrário, o usuário é informado da inexistência
     *
     * Checks whether the list contains any records,
     * if any, they will be displayed
     * Otherwise, the user is informed of the lack of records
     */

    if(l->nmrElem != 0){
        do {
            printf("%i%lc CONTATO:\n", (i+1), (wint_t)167);
            printf("Nome: %s", l->A[i].nome);
            setbuf(stdin, NULL); //Define o buffer da memória pra NULL / Sets the memory buffer to NULL
            printf("Endereco: %s", l->A[i].endereco);
            setbuf(stdin, NULL); //Define o buffer da memória pra NULL / Sets the memory buffer to NULL
            printf("Numero telefone: %s\n", l->A[i].numero);
            setbuf(stdin, NULL); //Define o buffer da memória pra NULL / Sets the memory buffer to NULL
            puts("\n");
            i++;
        } while (i < l->nmrElem);
        puts("Exibicao feita com sucesso!");
    } else {
        puts("NÃO HA REGISTROS PARA EXIBIR!");
    }

    //Retorna ao menu
    //Returns to the menu
    puts("Pressione ENTER para voltar ao menu.");
    setbuf(stdin, NULL); //Define o buffer da memória pra NULL / Sets the memory buffer to NULL
    getchar(); //Espera até que a tecla ENTER seja pressionada / Waits until ENTER key to be pressed
    return;
}

/*
 * No momento, as funções de pesquisa encontram apenas o primeiro registro que atenda às suas necessidades,
 * se houver mais de um elemento com o mesmo nome, só retornará a posição do primeiro
 * registro encontrado, uma possível melhoria futura seria retornar todos os registros
 * que atendam os requisitos da busca
 *
 * At the moment search functions find only the first record that meets your requirements,
 * if there is more than one element with the same name it will only return the position of the first
 * record found, a possible future improvement would be to return all records
 * Return all records that meet the search requirements
 */

//Busca de usuários com o algoritmo de busca binária
//Searches for records with the binary search algorithm
int buscaBinaria(LISTA *l, REGISTRO nome) {

    //Declaração de variáveis
    //Declaration
    int esq, meio, dir;
    esq = 0;
    dir = l->nmrElem;

    //Recebe entradas do usuário
    //Receives user input
    puts("Digite o nome do registro que deseja encontrar:");
    setbuf(stdin, NULL); //Define o buffer da memória pra NULL / Sets the memory buffer to NULL
    fgets(nome.nome, TAM, stdin);

    //Algoritmo de busca binária
    //Binary search algorithm
    while(esq <= dir) {
        meio = (int) ((esq + dir) / 2);
        if(strcmp(nome.nome, l->A[meio].nome) == 0) {
            return meio;
        } else {
            if(strcmp(l->A[meio].nome, nome.nome) < 0) {
                esq = meio+1;
            } else {
                dir = meio-1;
            }
        }
    }

    //Caso não seja encontrado o registro, retorna -1
    //If the record is not found, returns -1
    return -1;
}

//Busca, de forma linear, um registro de acordo com o endereço fornecido pelo usuário
//Searches linearly for a record according to the address provided by the user
int buscarEnd(LISTA *l, REGISTRO endereco) {

    //Variável de Iteração
    //Iteration Variable
    int i = 0;

    //Recebe entradas do usuário
    //Receives user input
    puts("Digite o endereco do registro que deseja encontrar:");
    setbuf(stdin, NULL); //Define o buffer da memória pra NULL / Sets the memory buffer to NULL
    fgets(endereco.endereco, TAM, stdin);

    /*
     * Caso não haja registro(s), é retornado -1 à função
     * Caso exista, a busca sequencial é executada e a posição é retornada
     *
     * If there is no record(s), -1 is returned to the function
     * If it exists, the sequential search is performed and the position is returned
     */

    if(l->nmrElem <= 0) {
        return -1;
    } else {
        //Compara o endereço buscado com o endereço armazenado na posição 'i' da lista
        //Compares the searched address with the address stored in the 'i' position of the list
        for(i = 0; (i < l->nmrElem) && (l->A[i].endereco != endereco.endereco); i++) {
            if(strcmp(endereco.endereco, l->A[i].endereco) == 0) {
                return i;
            }
        }

        //Caso percorra toda a lista e não encontre nada retorna -1
        //If the function traverses the entire list and finds nothing, returns -1
        return -1;
    }
}

//Busca, de forma linear, um registro de acordo com o telefone fornecido pelo usuário
//Searches linearly for a record according to the phone provided by the user
int buscarTel(LISTA *l, REGISTRO tel) {

    //Variável de Iteração
    //Iteration Variable
    int i = 0;

    //Recebe entradas do usuário
    //Receives user input
    puts("Digite o numero do registro que deseja encontrar:");
    setbuf(stdin, NULL); //Define o buffer da memória pra NULL / Sets the memory buffer to NULL
    fgets(tel.numero, TAM, stdin);

    /*
     * Caso não haja registro(s), é retornado -1 à função
     * Caso exista, a busca sequencial é executada e a posição é retornada
     *
     * If there is no record(s), -1 is returned to the function
     * If it exists, the sequential search is performed and the position is returned
     */

    if(l->nmrElem <= 0) {
        return -1;
    } else {
        //Compara o telefone buscado com o telefone armazenado na posição 'i' da lista
        //Compares the searched phone with the phone stored in the 'i' position of the list
        for(i = 0; i < (l->nmrElem) && (l->A[i].numero != tel.numero); i++) {
            if(strcmp(tel.numero, l->A[i].numero) == 0) {
                return i;
            }
        }

        //Caso percorra toda a lista e não encontre nada retorna -1
        //If the function traverses the entire list and finds nothing, returns -1
        return -1;
    }
}

//Exclui a chave que o usuário define utilizando busca binária
//Deletes the key that the user sets using binary search
int exclusao(LISTA *l, REGISTRO reg) {

    //Declaração de variáveis
    //Declaration
    int posicao, i=0;

    //Realiza a busca binária e o resultado é armazenado na variável 'posicao'
    //Performs the binary search and the result is stored in the variable 'posicao'
    posicao = buscaBinaria(l, reg);

    //Caso 'posicao' seja -1, informa que o registro não existe e retorna ao menu
    //If 'posicao' is -1 it informs that the record does not exist and returns to the menu
    if(posicao == -1) {
        puts("\nESSE REGISTRO NAO EXISTE!");
        return -1;
    }

    /*
     * Caso não haja registro(s), é retornado -1 à função
     * Caso exista, a busca sequencial é executada e a posição é retornada
     *
     * If there is no record(s), -1 is returned to the function
     * If it exists, the sequential search is performed and the position is returned
     */

    for(i = posicao; i < l->nmrElem; i++) {
        l->A[i] = l->A[i+1];
    }
    l->A[i] = reg;
    l->nmrElem--;

    //Retorna para o usuário
    //Returns to the user
    puts("\nExclusao feita com sucesso!");
    puts("Pressione ENTER para voltar ao menu.");
    setbuf(stdin, NULL); //Define o buffer da memória pra NULL / Sets the memory buffer to NULL
    getchar(); //Espera até que a tecla ENTER seja pressionada / Waits until ENTER key to be pressed
    return 1;
}

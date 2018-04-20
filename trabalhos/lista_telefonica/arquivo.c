#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arquivo.h"

//FUNÇÕES E PROCEDIMENTOS

void menuInicial() {
    // Detecção de Sistema Linux para executar o comando system("clear").
    #ifdef __linux__
    system("clear");
    // Detecção de Sistema Windows para executar o comando system("cls").
    #elif defined WIN32
    system("cls");
    #endif

    // Menu de interação com o usuário.
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


int tamLista(LISTA *l) { // Retorna a quantidade de contatos salvos.
    return l->nmrElem;
}

void atualizarLista(LISTA *l) { // Inicializa ou reinicializa a lista.
    l->nmrElem = 0;
    return;
}

void cadastrarElemento(LISTA *l, REGISTRO reg) { // Faz o registro de usuários.

    int i; // Iterator.

    // Verifica se a lista está cheia
    if(l->nmrElem >= TAM) {
        puts("A LISTA ESTA CHEIA!");
        return;
    }

    //Recebe entradas do usuário
    printf("Digite o nome: ");
    setbuf(stdin, NULL); // Define o buffer da memória pra NULL
    fgets(reg.nome, TAM, stdin);
    printf("Digite o endereco: ");
    setbuf(stdin, NULL); // Define o buffer da memória pra NULL
    fgets(reg.endereco, TAM, stdin);
    printf("Digite o numero de telefone: ");
    setbuf(stdin, NULL); // Define o buffer da memória pra NULL
    fgets(reg.numero, TAM, stdin);

    //Inserção Ordenada com Insertion Sort
    for(i = l->nmrElem; i > 0 && strcmp(reg.nome, l->A[i-1].nome) < 0; i--){
        l->A[i] = l->A[i-1];
    }
    l->A[i] = reg;
    l->nmrElem++;

    //Retorno para o usuário
    puts("\nInsercao feita com sucesso!");
    puts("Pressione ENTER para voltar ao menu.");
    setbuf(stdin, NULL); // Define o buffer da memória pra NULL
    getchar(); // Leitura do ENTER.
    return;
}

void exibirLista(LISTA *l) { // Exibe os contatos cadastrados.

    int i = 0; // Iterator.

    /*
     * Verifica se a lista contém algum registro.
     * Caso haja, os mesmos serão exibidos.
     * Caso contrário, o usuário é informado da inexistência.
     */

    if(l->nmrElem != 0){
        do {
            printf("%i%lc CONTATO:\n", (i+1), (wint_t)167);
            printf("Nome: %s", l->A[i].nome);
            setbuf(stdin, NULL); // Define o buffer da memória pra NULL
            printf("Endereco: %s", l->A[i].endereco);
            setbuf(stdin, NULL); // Define o buffer da memória pra NULL
            printf("Numero telefone: %s\n", l->A[i].numero);
            setbuf(stdin, NULL); // Define o buffer da memória pra NULL
            puts("\n");
            i++;
        } while (i < l->nmrElem);
        puts("Exibicao feita com sucesso!");
    } else {
        puts("NÃO HA REGISTROS PARA EXIBIR!");
    }

    //Retorno ao menu
    puts("Pressione ENTER para voltar ao menu.");
    setbuf(stdin, NULL); // Define o buffer da memória pra NULL
    getchar(); // Espera a tecla ENTER ser pressionada.
    return;
}

/*
 * No momento as funções de busca apenas o primeiro registro que atende seus requisitos,
 * caso haja mais de um elemento com o mesmo nome ela só retornará a posição do primeiro
 * registro encontrado, uma possível futura melhoria seria retornar todos os registros
 * que atendam os requisitos da busca.
 */

int buscaBinaria(LISTA *l, REGISTRO nome) { // Busca de usuários com busca binária.

    int esq, meio, dir;
    esq = 0;
    dir = l->nmrElem;

    //Recebe entradas do usuário
    puts("Digite o nome do registro que deseja encontrar:");
    setbuf(stdin, NULL); // Define o buffer da memória pra NULL
    fgets(nome.nome, TAM, stdin);

    //Algoritmo de busca binária
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
    return -1;
}

int buscarEnd(LISTA *l, REGISTRO endereco) { // Busca por endereço.

    int i = 0; // Iterator.

    //Recebe entradas do usuário
    puts("Digite o endereco do registro que deseja encontrar:");
    setbuf(stdin, NULL);
    fgets(endereco.endereco, TAM, stdin);

    /*
     * Caso não haja registro(s), é retornado -1 à função.
     * Caso existe, a busca sequencial é executada e a posição é retornada.
     */

    if(l->nmrElem <= 0) {
        return -1;
    } else {
        //Compara o endereço buscado com o endereço armazenado na posição 'i' da lista
        for(i = 0; (i < l->nmrElem) && (l->A[i].endereco != endereco.endereco); i++) {
            if(strcmp(endereco.endereco, l->A[i].endereco) == 0) {
                return i;
            }
        }

        //Caso percorra toda a lista e não encontre nada retorna -1
        return -1;
    }
}

int buscarTel(LISTA *l, REGISTRO tel) { // Busca por telefone.

    int i = 0; // Iterator.

    //Recebe entradas do usuário
    puts("Digite o numero do registro que deseja encontrar:");
    setbuf(stdin, NULL);
    fgets(tel.numero, TAM, stdin);

    /*
     * Caso não haja registro(s), é retornado -1 à função.
     * Caso existe, a busca sequencial é executada e a posição é retornada.
     */

    if(l->nmrElem <= 0) {
        return -1;
    } else {
        //Compara o endereço buscado com o endereço armazenado na posição 'i' da lista
        for(i = 0; i < (l->nmrElem) && (l->A[i].numero != tel.numero); i++) {
            if(strcmp(tel.numero, l->A[i].numero) == 0) {
                return i;
            }
        }

        //Caso percorra toda a lista e não encontre nada retorna -1
        return -1;
    }
}

int exclusao(LISTA *l, REGISTRO reg) { //FUNCIONANDO
    //Declaração de variáveis
    int posicao, i=0;

    //Realiza a busca binária e o resultado é armazenado na variável 'posicao'
    posicao = buscaBinaria(l, reg);

    //Caso 'posicao' seja -1 informa que o registro não existe e retorna ao menu
    if(posicao == -1) {
        puts("\nESSE REGISTRO NAO EXISTE!");
        return -1;
    }

    /*
     * Caso não haja registros, é retornado -1.
     * Caso haja, a busca sequencial é executada e é retornada a posição.
     */

    for(i = posicao; i < l->nmrElem; i++) {
        l->A[i] = l->A[i+1];
    }
    l->A[i] = reg;
    l->nmrElem--;

    //Retorno para o usuário
    puts("\nExclusao feita com sucesso!");
    puts("Pressione ENTER para voltar ao menu.");
    setbuf(stdin, NULL); // Define o buffer da memória pra "NULL".
    getchar(); // Espera a tecla ENTER ser pressionada.
    return 1;
}

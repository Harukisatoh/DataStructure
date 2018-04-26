//FUNÇÕES E PROCEDIMENTOS
//FUNCTIONS AND PROCEDURES

//Inicializa a lista
//Initializes the list
void inicializar(LISTA *l) {
    //Alteração do valor da variável
    //Value change of the variable
    l->inicio = NULL;
}

//FUNÇÕES DE INSERÇÃO
//INSERT FUNCTIONS

//Insere elementos na primeira posição possível
//Inserts elements in the first possible position
void insercaoDesordenada(LISTA *l, REGISTRO reg) {
    //Declaração de variáveis
    //Declaration
    PONT novo = NULL;

    //Alocação de memória
    //Memory Allocation
    novo = (PONT) malloc(sizeof(ELEMENTO));
    if(novo==NULL) {
        puts("\nErro de alocacao: inserir_elemento");
        return;
    }

    //Inserção do elemento
    //Insertion of the element
    novo->reg = reg;
    novo->prox = NULL;
    novo->prox = l->inicio;
    l->inicio = novo;
}

//Insere elementos de forma ordenada
//Inserts elements in an orderly fashion
void insercaoOrdenada(LISTA *l, REGISTRO reg) {
    //Declaração de variáveis
    //Declaration
    PONT novo = NULL;
    PONT atual = NULL;
    PONT ant = NULL;

    //Alocação de memória
    //Memory Allocation
    novo = (PONT) malloc (sizeof(ELEMENTO));
    if(novo == NULL) {
        puts("\nErro de alocacao: inserir_elemento_ord");
        return;
    }

    //Alteração do valor das variáveis
    //Value change of the variables
    novo->reg = reg;
    novo->prox = NULL;
    atual = l->inicio;

    //Inserção ordenada de elementos
    //Orderly insertion of elements
    while(atual != NULL && atual->reg.chave < reg.chave) {
        ant = atual;
        atual = atual->prox;
    }
    novo->prox = atual;
    if(ant == NULL) {
        l->inicio = novo;
    } else {
        ant->prox = novo;
    }
}

//Exibe os contatos cadastrados
//Displays the registered contacts
void exibirLista(LISTA *l) {

    //Declaração de variáveis
    //Declaration
    PONT aux = l->inicio;

    //Exibe todos os elementos da lista
    //Displays all list elements
    while(aux != NULL) {
        printf("\n\t %d", aux->reg.chave);
        aux = aux->prox;
    }
}

//Reinicia a lista
//Restarts the list
void reinicializar(LISTA *l) {

    //Declaração de variáveis
    //Declaration
    PONT aux  = l->inicio;

    //Libera toda a memória utilizada para alocar a lista
    //Releases all the memory used to allocate the list
    while(aux != NULL) {
        l->inicio = l->inicio->prox;
        free(aux);
        aux = l->inicio;
    }
}

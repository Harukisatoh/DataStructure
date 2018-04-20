//INICIALIZAÇÃO DA LISTA
void inicializar(LISTA *l) {
    //ALTERAÇÃO DE VARIÁVEIS
    l->inicio = NULL;
}

//INSERÇÕES
void insercaoDesordenada(LISTA *l, REGISTRO reg) {
    //DECLARAÇÃO DE VARIÁVEIS
    PONT novo = NULL;

    //ALOCAÇÃO DE MEMÓRIA
    novo = (PONT) malloc(sizeof(ELEMENTO));
    if(novo==NULL) {
        puts("\nErro de alocacao: inserir_elemento");
        return;
    }

    //INSERÇÃO DE ELEMENTO
    novo->reg = reg;
    novo->prox = NULL;
    novo->prox = l->inicio;
    l->inicio = novo;
}

void insercaoOrdenada(LISTA *l, REGISTRO reg) {
    //DECLARAÇÃO DE VARIÁVEIS
    PONT novo = NULL;
    PONT atual = NULL;
    PONT ant = NULL;

    //ALOCAÇÃO DE MEMÓRIA
    novo = (PONT) malloc (sizeof(ELEMENTO));
    if(novo == NULL) {
        puts("\nErro de alocacao: inserir_elemento_ord");
        return;
    }

    //ALTERAÇÃO DE VARIÁVEIS
    novo->reg = reg;
    novo->prox = NULL;
    atual = l->inicio;

    //INSERÇÃO ORDENADA DE ELEMENTOS
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

//EXIBIÇÃO DA LISTA
void exibirLista(LISTA *l) {
    //DECLARAÇÃO DE VARIÁVEIS
    PONT aux = l->inicio;

    //EXIBE TODOS OS ELEMENTOS DA LISTA
    while(aux != NULL) {
        printf("\n\t %d", aux->reg.chave);
        aux = aux->prox;
    }
}

//REINICIALIZAÇÃO DA LISTA
void reinicializar(LISTA *l) {
    //DECLARAÇÃO DE VARIÁVEIS
    PONT aux  = l->inicio;

    //LIBERA DA MEMÓRIA TODOS OS ELEMENTOS DA LISTA
    while(aux != NULL) {
        l->inicio = l->inicio->prox;
        free(aux);
        aux = l->inicio;
    }
}

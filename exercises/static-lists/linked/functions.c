//FUNÇÕES E PROCEDIMENTOS
//FUNCTIONS AND PROCEDURES

//Inicializa a lista
//Initializes the list
void inicializa (LISTA* l) {

    //Inicialização de variáveis
    //Initialization of variables
    l->inicio = INVALIDO;
    l->dispo = 0;
    l->nmrElem = 0;

    //Variável de Iteração
    //Iteration Variable
    int i;

    /*
     * Ao utilizar o laço 'for' todos os elementos da lista passam a dizer onde
     * está o próximo elemento
     *
     * When using the 'for' loop all elements in the list will tell you where
     * the next element is
     */
    for (i=0; i < MAX-1; i++) {
        l->A[i].prox = i+1;
    }

    //O último elemento disponível recebe INVALIDO, uma palavra reservada para -1
    //The last available element receives INVALIDO, a word reserved for -1
    l->A[MAX-1].prox = INVALIDO;
}

//Retorna a quantidade de contatos salvos
//Returns the number of saved contacts
int tamanho (LISTA* l) {
    return l->nmrElem;
}

/*
 * INSERE UM ELEMENTO NA LISTA DE FORMA ORDENADA
 *
 * Obs: Nessa função de inserir não é permitido registros repetidos
 *
 * Obs 2: A ordenação não é feita de fato, cada elemento "aponta" para o próximo,
 * portanto a função de busca retornará apenas a posição em que o elemento foi
 * inserido, e não a "posição ordenada" do elemento
 *
 * INSERTS AN ELEMENT IN THE LIST IN AN ORDERED WAY
 *
 * Note: In this insert function, repeated records are not allowed
 *
 * Note 2: Ordering is not done in fact, each element "points" to the next one,
 * so the search function will return only the position where the element was
 * inserted, not the "ordered position" of the element
 */
int inserirElemListaOrd (LISTA* l, REGISTRO reg) {

    //Declaração de variáveis
    //Declaration
    int ant = INVALIDO;
    int atual;
    int aux_dispo = l->A[l->dispo].prox;

    //Verifica se a lista está cheia, se sim retorna INVALIDO (-1) e a inserção é interrompida
    //Checks if list is full, if yes returns INVALIDO (-1) and the insertion is interrupted
    if (l->dispo == INVALIDO) {
        return INVALIDO;
    }

    //Insere a chave no registro e atualiza o número total de elementos na lista
    //Inserts the key in the registry and updates the total number of elements in the list
    l->A[l->dispo].reg.chave = reg.chave;
    l->nmrElem = l->nmrElem + 1;

    //Faz um backup do conteúdo contido em 'l->inicio'
    //Backs up content contained in 'l->inicio'
    atual = l->inicio;

    /*
     * Se não for o primeiro elemento inserido na lista, e se a chave inserida
     * for maior que a chave contida na variável 'l->A[atual].reg.chave', então o laço
     * 'while' é executado, e nele a variável 'ant' recebe a variável 'atual', e
     * a variável 'atual' recebe o conteúdo da variável 'l->A[atual].prox'
     *
     * If it is not the first element inserted in the list, and if the inserted
     * key is greater than the key contained in the variable 'l->A[atual].reg.chave',
     * then the 'while' loop is executed, and in it the variable 'ant' receives
     * the variable 'atual', and the 'atual' variable receives the contents
     * of the variable 'l->A[atual].prox'
     */
    while (atual >= 0 && l->A[atual].reg.chave < reg.chave) {
        ant = atual;
        atual = l->A[atual].prox;
    }

    /*
     * Verifica se é o primeiro elemento inserido, se sim a primeira posição da
     * lista recebe INVALIDO (-1) e 'l->inicio' recebe o conteúdo da variável 'l->dispo',
     * caso contrário a variável 'prox' do elemento anterior recebe a posição do
     * elemento inserido, e a variável 'prox' do elemento inserido recebe INVALIDO (-1)
     *
     * It checks if it is the first element inserted, if yes the first position
     * of the list receives INVALIDO (-1) and 'l->inicio' receives the contents of the
     * variable 'l->dispo', otherwise the variable 'prox' of the previous element
     * receives the position of the inserted element, and the variable 'prox' of
     * the inserted element receives INVALIDO (-1)
     */
    if (ant == INVALIDO) {
        l->A[l->dispo].prox = l->inicio;
        l->inicio = l->dispo;
    } else {
        l->A[ant].prox = l->dispo;
        l->A[l->dispo].prox = atual;
    }

    //'l->dispo' recebe a posição do próximo elemento disponível
    //'l-> dispo' receives the position of the next available element
    l->dispo = aux_dispo;

    return 1;
}

//Exclui a chave que o usuário define
//Deletes the key that the user sets
int excluirElemLista (LISTA *l, TIPOCHAVE ch) {

    //Declaração de variáveis
    //Declaration
    int ant = INVALIDO;
    int i = l->inicio;

    //Faz uma busca para saber em que posição o elemento procurado está
    //Does a search to know in which position the searched element is
    while ((i != INVALIDO) && (l->A[i].reg.chave < ch)) {
        ant = i;
        i = l->A[i].prox;
    }

    /*
     * Se i for inválido, ou se ele for válido mas seu valor for diferente
     * da chave buscada, não será possível excluir, portanto retorna 0
     *
     * If 'i' is invalid, or if it is valid but its value is different from the
     * fetched key, it can not be deleted, so it returns 0
     */
    if (i == INVALIDO || l->A[i].reg.chave != ch) {
        return 0;
    }

    /*
     * Verifica se o elemento que será excluido é o primeiro da lista, se sim a
     * variável 'l-inicio' é atualizada, caso contrário a variável 'prox' do elemento
     * anterior é atualizada
     *
     * Checks if the element to be excluded is the first one in the list, if yes
     * the variable 'l-inicio' is updated, otherwise the variable 'prox' of the
     * previous element is updated
     */
    if (ant == INVALIDO) {
        l->inicio = l->A[i].prox;
    } else {
        l->A[ant].prox = l->A[i].prox;
    }

    //A lista de elementos disponíveis é atualizada
    //The list of available elements is updated
    devolverNo (l, i);

    //Subtrai um ao total de elementos
    //Subtracts one of the total of the elements
    l->nmrElem = l->nmrElem - 1;

    return 1;
}

//Atualiza a lista de elementos disponíveis
//Refreshes list of available elements
void devolverNo (LISTA *l, int j) {

    /*
     * Para que um novo elemento disponível seja inserido, as variáveis 'prox' e
     * 'dispo' precisam ser atualizadas
     *
     * For a new available element to be inserted, the 'prox' and 'dispo' variables need to be updated
     */
    l->A[j].prox = l->dispo;
    l->dispo = j;
}

//Exibe os contatos cadastrados
//Displays the registered contacts
void exibirLista (LISTA *l) {

    //Declaração de variáveis
    //Declaration
    int i = l->inicio;

    printf ("Lista: \" ");

    //Exibe todos os elementos da lista
    //Displays all list elements
    while (i != INVALIDO) {
        printf ("%i ", l->A[i].reg.chave);
        i = l->A[i].prox;
    }

    printf ("\"\n");
}

//Faz uma busca sequencial por alguma chave, e se encontrar retorna a posição
//Does a sequential search for some key, and if it finds it returns the position
int buscaSequencialOrd (LISTA *l, TIPOCHAVE ch) {

    //Declaração de variáveis
    //Declaration
    int i = l->inicio;

    /*
     * Sai do laço apenas quando chega ao final da lista, ou quando chega em
     * um número maior que o buscado
     *
     * It leaves the loop only when it reaches the end of the list, or when it
     * arrives at a number greater than the searched
     */
    while (i != INVALIDO && l->A[i].reg.chave < ch) {
        //O valor final da variável 'i' vai ser a posição em que o laço 'while' é deixado
        //The final value of the 'i' variable will be the position where the 'while' loop is left
        i = l->A[i].prox;
    }

    /*
     * Verifica se o registro na posição i é o valor buscado, se sim retorna o
     * valor de i, se não retorna INVALIDO (-1)
     *
     * Checks if the record in position 'i' is the searched value, if yes it
     * returns the value of 'i', if it does not return INVALIDO (-1)
     */
    if (i != INVALIDO && l->A[i].reg.chave == ch) {
        return i;
    } else {
        return INVALIDO;
    }
}

//Reinicia a lista
//Restarts the list
void reinicializarLista (LISTA *l) {
    inicializa (l);
}

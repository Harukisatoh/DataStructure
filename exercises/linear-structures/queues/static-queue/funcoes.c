/*
 * @author: Gabriel Haruki Gomes Satô
 */

//Inicializa a fila
void inicializar (FILA *f) {
    f->inicio = 0;
    f->nmrElem = 0;
}

//Retorna a quantidade de elementos válidos na fila
int qtdElem (FILA *f) {
    return (f->nmrElem);
}

//Exibe todos os elementos válidos da fila
void exibir (FILA *f) {
    int temp, i = f->inicio;

    //Executa o loop x vezes, onde x é o número total de elementos válidos da fila
    for (temp = f->nmrElem; temp > 0; temp--) {
        //Exibe o elemento atual
        printf("[%d] ", f->A[i].chave);

        //Calcula qual é o próximo elemento a ser exibido
        i = (i + 1) % MAX;
    }
}

//Insere um elemento no final da fila (FIFO)
void inserir (FILA *f, REGISTRO reg) {
    int pos;

    //Verifica se a fila está cheia
    if (f->nmrElem >= MAX) {
        printf("ERRO: A fila está cheia!\n");
        return;
    }

    //Calcula qual é a posição seguinte em que o vetor está vazio
    pos = (f->nmrElem + f->inicio) % MAX;

    //Insere o elemento no local calculado anteriormente
    f->A[pos] = reg;
    (f->nmrElem)++;
}

//Exclui o primeiro elemento que foi inserido na fila (FIFO)
void excluir (FILA *f, REGISTRO *reg) {
    //Verifica se a fila está vazia
    if (f->nmrElem == 0) {
        printf("ERRO: A fila está vazia!\n");
        return;
    }

    //O elemento que será excluido é passado para um local da memória definido pelo usuário
    *reg = f->A[f->inicio];

    //O início e a quantidade de elementos válidos da fila são atualizados
    f->inicio = (f->inicio + 1) % MAX;
    (f->nmrElem)--;
}

//Reinicia a fila
void reinicializar (FILA *f) {
    inicializar (f);
}

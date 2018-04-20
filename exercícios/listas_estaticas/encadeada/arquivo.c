void inicializa(LISTA* l) {
    l->inicio = -1;
    l->dispo = 0;
    l->nmrElem = 0;

    for(int i=0; i < MAX-1; i++) {
        l->A[i].prox = i+1;
    }
    l->A[MAX-1].prox = -1;
}

int tamanho(LISTA* l) { //WIP
    int i = l->inicio;
    int tam = 0;
    while(i != -1) {
        i = l->A[i].prox;
        tam++;
    }
    return tam;
}

int inserirElem(LISTA* l, REGISTRO reg) { //WIP
    if(l->nmrElem >= MAX) {
        printf("\n Não é possível inserir nenhum elemento, a lista está cheia!\n ");
        return -1;
    }
    l->nmrElem = l->nmrElem + 1;
    l->A[l->dispo] = reg;


}

void teste(LISTA* l) {
    printf("Inicio: %d\n", l->inicio);
    printf("Dispo: %d\n", l->dispo);
    printf("NmrElem: %d\n", l->nmrElem);
    return;
}

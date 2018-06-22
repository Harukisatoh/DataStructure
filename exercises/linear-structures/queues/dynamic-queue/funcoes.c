/*
 * @author: Gabriel Haruki Gomes Satô
 */

 #include "prototipos.h"

 //Inicializa a fila
 void inicializar (FILA *f) {
     f->inicio = NULL;
     f->fim = NULL;
     f->nmrElem = 0;
 }

 //Insere um novo elemento na fila
 void inserir (FILA *f, REGISTRO reg) {

     //Cria uma variável do tipo ponteiro para ELEMENTO
     ELEMENTO* novo = NULL;

     //Aloca a memória para o novo elemento
     novo = (ELEMENTO*) malloc (sizeof (ELEMENTO));

     //Verifica se ocorreu algum erro na alocação
     if (novo == NULL) {
         printf("ERRO: Não foi possível alocar memória!\n");
         return;
     }

     //O novo elemento recebe o elemento inserido
     novo->reg = reg;
     novo->prox = NULL;

     //Verifica se é o primeiro elemento inserido na fila, e ajusta os ponteiros
     if (f->fim == NULL) {
         f->inicio = novo;
         f->fim = novo;
     } else {
         f->fim->prox = novo;
         f->fim = novo;
     }

     //Incrementa a quantidade de elementos na fila
     (f->nmrElem)++;

 }

 //Exibe cada elemento da fila
 void exibir (FILA *f) {

     //Verifica se a fila está vazia, se sim sai do procedimento
     if (f->inicio == NULL) {
         printf("ERRO: A fila está vazia!\n");
         return;
     }

     //Cria um ponteiro para percorrer a fila
     ELEMENTO* atual = NULL;

     //Percorre toda a fila e exibe
     for (atual = f->inicio; atual != NULL; atual = atual->prox) {
         printf ("\nElemento %d", atual->reg.chave);
     }

 }

 //Retorno o número de elementos na fila
 int numeroElemento (FILA *f) {
     return (f->nmrElem);
 }

 //Exclui o FIFO (First In, First Out) da fila
 int excluir (FILA *f) {

     //Cria um ponteiro para auxiliar na exclusão
     ELEMENTO* aux = f->inicio;

     //Verifica se a fila está vazia, se sim retorna 0;
     if (aux == NULL) {
         return (0);
     }

     //Os ponteiros são atualizados
     f->inicio = aux->prox;

     //Desaloca a memória do elemento apontado pelo ponteiro
     free (aux);

     //Verifica se a fila ficou vazia depois da exclusão, se sim ajusta os ponteiros
     if (f->inicio == NULL) {
         f->fim = NULL;
     }

     //Decrementa o número total de elementos
     (f->nmrElem)--;

     //Retorna 1
     return (1);

 }

 //Reinicializa a fila
 void reinicializar (FILA *f) {

     //Faz um loop para excluir todos os elementos da fila
     while (excluir (f));

 }

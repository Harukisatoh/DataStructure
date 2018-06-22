/*
 * @author: Gabriel Haruki Gomes Satô
 */

//FUNÇÕES E PROCEDIMENTOS
//FUNCTIONS AND PROCEDURES

//Inicializa ou reinicializa a lista
//Initializes or resets the list
void inicializarLista(LISTA* l){
    l->nmrElem = 0;
}

//Retorna a quantidade de contatos salvos
//Returns the number of saved contacts
int tamanho(LISTA* l){
    return l-> nmrElem;
}

//Exibe os contatos cadastrados
//Displays the registered contacts
void exibirLista(LISTA* l){
    printf("Lista: \n");
    for(int i=0; i < l->nmrElem; i++)printf("%d ", l->A[i].chave);
    printf("\n");
}

//Funções de busca
//Search functions

//Faz uma busca por alguma chave, e se encontrar retorna a posição
//Does a search for some key, and if it finds it returns the position
/*int buscaSequencial(LISTA* l, TIPOCHAVE ch){
    for(int i=0; i < l->nmrElem; i++){
        if(ch == l->A[i].chave) return i;
    }
    return -1;
}*/

//Faz uma busca por alguma chave utilizando uma sentinela, e se encontrar retorna a posição
//Does a search for some key using a sentinel, and if it finds it returns the position
/*int buscaSentinela(LISTA* l, TIPOCHAVE ch){

    //Cria um sentinela, para que sempre que houver uma busca, haja uma chave encontrada
    //Creates a sentinel, so that whenever there is a search there is a key found
    l->A[l->nmrElem].chave = ch;

    //Sai do while apenas quando encontra a chave buscada ou até encontrar a sentinela
    //Leaves the while only when it find the desired key or until you find the sentinel
    while(l->nmrElem != ch) i++;

    //Se a posição i for igual a posição da sentinela, então retorna -1, senão retorna i
    //If position i equals the position of the sentinel, then it returns -1, otherwise it returns i
    if(i == l->nmrElem){
        return -1;
    }else{
        return i;
    }
}*/


//Busca de usuários com o algoritmo de busca binária
//Searches for records with the binary search algorithm
int buscaBinaria(LISTA* l, TIPOCHAVE ch){

    //Declaração de variáveis
    //Declaration
    int esq, dir, meio;
    esq = 0;
    dir = l->nmrElem - 1;

    //Algoritmo de busca binária
    //Binary search algorithm
    while(esq <= dir){
        meio = (int) ((esq + dir) / 2);
        if(ch == l->A[meio].chave){
            return meio;
        }else{
            if(l->A[meio].chave < ch){
                esq = meio+1;
            }else{
                dir = meio-1;
            }
        }
    }

    //Caso não seja encontrado o registro, retorna -1
    //If the record is not found, returns -1
    return -1;
}

//Funções de inserção
//Insert functions

//Insere um elemento no índice desejado pelo usuário
//Inserts an element in the index desired by the user
/*int inserirElemLista(LISTA* l, REGISTRO reg, int i){

    //Verifica se a posição digitada é válida
    //It checks if the entered position is valid
    if(i < 0 || i > l->nmrElem || l->nmrElem == MAX){

        //Move todos os elementos que estão numa posição >= i para uma casa à frente
        //Moves all elements that are in a position >= i to a house ahead
        for(int j=l->nmrElem; j > i; j--){
            l->A[j] = l->A[j-1];
        }

        //O registro é então inserido na posição desejada
        //The record is then inserted into the desired position
        l->A[i] = reg;

        //É somado então mais um elemento à lista
        //Then one more element is added to the list
        l->nmrElem++;
        return 1;
    }else{
        return 0;
    }
}*/

//Insere um elemento na lista de forma ordenada
//Inserts an element in the list in an ordered way
int inserirElemListaOrd(LISTA* l, REGISTRO reg){

    //Variável de Iteração
    //Iteration Variable
    int pos;

    //Verifica se a lista está cheia
    //Checks if the list is full
    if(l->nmrElem >= MAX) return 0;

    //Inserção Ordenada com o algoritmo Insertion Sort
    //Ordered insertion with the Insertion Sort algorithm
    for(pos=l->nmrElem; pos > 0 && l->A[pos-1].chave > reg.chave; pos--){
        l->A[pos] = l->A[pos-1];
    }
    l->A[pos] = reg;
    l->nmrElem++;

    return 1;
}

//Exclui a chave que o usuário define utilizando busca binária
//Deletes the key that the user sets using binary search
int excluirElemLista(TIPOCHAVE ch, LISTA* l){

    //Declaração de variáveis
    //Declaration
    int pos;

    //Procura a posição da chave que deseja-se excluir com o método de Busca Sequencial
    //Searches for the position of the key that you want to exclude with the Sequential Search method
    //pos = buscaSequencial(l, ch);

    //Procura a posição da chave que deseja-se excluir com o método de Busca Binária
    //Find the position of the key that you want to exclude with the Binary Search method
    pos = buscaBinaria(l, ch);

    //Se existir essa chave então ele move todas as chaves que estão nas posições a frente para uma casa atrás
    //If this key exists then it moves all the keys that are in the forward positions to a house behind
    if(pos != -1){
        for(int j=pos; j < l->nmrElem-1; j++){
            l->A[j] = l->A[j+1];
        }
        l->nmrElem--;
        return 1;
    }else{
        return 0;
    }
}

//Reinicia a lista definindo os números de elementos como 0
//Restarts list by setting number of elements to 0
void reinicializarLista(LISTA*l){
    l->nmrElem = 0;
}

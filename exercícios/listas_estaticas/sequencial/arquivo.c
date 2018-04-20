//Declaração de funções
void inicializarLista(LISTA* l){ //Inicializa a lista com 0 elementos
  l->nmrElem = 0;
}

int tamanho(LISTA* l){ //Retorna o quantidade de elementos existentes na lista
  return l-> nmrElem;
}

void exibirLista(LISTA* l){ //Exibe toda a lista na tela
  printf("Lista: \n");
  for(int i=0; i < l->nmrElem; i++)printf("%d ", l->A[i].chave);
  printf("\n");
}

//Funções de Busca

/*int buscaSequencial(LISTA* l, TIPOCHAVE ch){ //Faz uma busca por alguma chave, e se encontrar retorna a posição
  for(int i=0; i < l->nmrElem; i++){
    if(ch == l->A[i].chave) return i;
  }
  return -1;
}*/

/*int buscaSentinela(LISTA* l, TIPOCHAVE ch){ //Faz uma busca por alguma chave, e se encontrar retorna a posição
  l->A[l->nmrElem].chave = ch; //Cria uma sentinela, para que sempre que houver a busca haja uma chave encontrada
  while(l->nmrElem != ch) i++; //Procura enquanto não achar a chave que está sendo buscada
  if(i == l->nmrElem){ //Se a posição i for igual a posição da sentinela, então retorna -1, senão retorna i;
    return -1;
  }else{
    return i;
  }
}*/

int buscaBinaria(LISTA* l, TIPOCHAVE ch){
  int esq, dir, meio;
  esq = 0;
  dir = l->nmrElem - 1;
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
  return -1;
}

//Funções de Inserção

/*int inserirElemLista(LISTA* l, REGISTRO reg, int i){ //Insere um elemento no índice desejado pelo usuário
  if(i < 0 || i > l->nmrElem || l->nmrElem == MAX){ //Verifica se a posição digitada é válida
    for(int j=l->nmrElem; j > i; j--){ //Move todos os elementos que estão numa posição >= i para uma casa à frente
      l->A[j] = l->A[j-1];
    }
    l->A[i] = reg; //O registro é então inserido na posição desejada
    l->nmrElem++; //A lista então fica com um elemento a mais
    return 1;
  }else{
    return 0;
  }
}*/

int inserirElemListaOrd(LISTA* l, REGISTRO reg){
  if(l->nmrElem >= MAX) return 0;
  int pos;
  for(pos=l->nmrElem; pos > 0 && l->A[pos-1].chave > reg.chave; pos--){
    l->A[pos] = l->A[pos-1];
  }
  l->A[pos] = reg;
  l->nmrElem++;
  return 1;
}

int excluirElemLista(TIPOCHAVE ch, LISTA* l){ //Exclui a chave que o usuário definir
  int pos;
  //pos = buscaSequencial(l, ch); //Procura a posição da chave que deseja-se excluir com o método de buscaSequencial
  pos = buscaBinaria(l, ch); //Procura a posição da chave que deseja-se excluir com o método de buscaBinaria
  if(pos != -1){ //Se existir essa chave então ele move todas as chaves que estão nas posições a frente para uma casa atrás
    for(int j=pos; j < l->nmrElem-1; j++){
      l->A[j] = l->A[j+1];
    }
    l->nmrElem--;
    return 1;
  }else{
    return 0;
  }
}

void reinicializarLista(LISTA*l){ //Reinicia a lista definindo os números de elementos como 0
  l->nmrElem = 0;
}

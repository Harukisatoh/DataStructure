//Definindo constantes
#define MAX 50 //Definindo MAX como 50

//Definindo estruturas
typedef int TIPOCHAVE; //Definindo TIPOCHAVE como int

typedef struct{//Definindo estrutura de um registro
  TIPOCHAVE chave;
  //Outros atributos
} REGISTRO;

typedef struct{//Definindo estrutura de uma lista
  REGISTRO A[MAX+1];
  int nmrElem;
} LISTA;

//Prototipação de funções
void inicializarLista(LISTA* l);
int tamanho(LISTA* l);
void exibirLista(LISTA* l);
//int buscaSequencial(LISTA* l, TIPOCHAVE ch);
//int buscaSentinela(LISTA* l, TIPOCHAVE ch);
int buscaBinaria(LISTA* l, TIPOCHAVE ch);
//int inserirElemLista(LISTA* l, REGISTRO reg, int i);
int inserirElemListaOrd(LISTA* l, REGISTRO reg);
int excluirElemLista(TIPOCHAVE ch, LISTA* l);
void reinicializarLista(LISTA*l);

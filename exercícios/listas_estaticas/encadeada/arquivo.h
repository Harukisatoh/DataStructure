//Definindo constantes
#define MAX 50 //Definindo MAX como 50

//Definindo estruturas
typedef int TIPOCHAVE; //Definindo TIPOCHAVE como int

typedef struct{//Definindo estrutura de um registro
  TIPOCHAVE chave;
  int prox;
  //Outros atributos
} REGISTRO;

typedef struct{//Definindo estrutura de uma lista
  REGISTRO A[MAX];
  int nmrElem;
  int inicio;
  int dispo;
} LISTA;

void inicializa(LISTA* l);
int tamanho(LISTA* l);
int inserirElem(LISTA* l, REGISTRO reg);
void teste(LISTA* l);

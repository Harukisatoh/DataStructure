#include "arquivo.h"
#include "arquivo.c"

int main() {

    LISTA lista;
    REGISTRO reg;

    inicializar(&lista);
    reg.chave = 8;
    insercaoOrdenada(&lista, reg);
    reg.chave = 10;
    insercaoOrdenada(&lista, reg);
    reg.chave = 3;
    insercaoOrdenada(&lista, reg);
    reg.chave = 5;
    insercaoOrdenada(&lista, reg);
    reg.chave = 4156;
    insercaoOrdenada(&lista, reg);
    reg.chave = 897;
    insercaoOrdenada(&lista, reg);
    reg.chave = 666;
    insercaoOrdenada(&lista, reg);
    reg.chave = 333;
    insercaoOrdenada(&lista, reg);
    reg.chave = 133;
    insercaoOrdenada(&lista, reg);
    reg.chave = 564;
    insercaoOrdenada(&lista, reg);
    reg.chave = 654;
    insercaoOrdenada(&lista, reg);
    reg.chave = 2;
    insercaoOrdenada(&lista, reg);
    reg.chave = 1;
    insercaoOrdenada(&lista, reg);
    reg.chave = 5654;
    insercaoOrdenada(&lista, reg);
    reg.chave = 5648;
    insercaoOrdenada(&lista, reg);
    reg.chave = 3332;
    insercaoOrdenada(&lista, reg);
    reg.chave = 35;
    insercaoOrdenada(&lista, reg);
    reg.chave = 69;
    insercaoOrdenada(&lista, reg);
    reg.chave = 7;
    insercaoOrdenada(&lista, reg);
    reg.chave = 87;
    insercaoOrdenada(&lista, reg);
    reg.chave = 153;
    insercaoOrdenada(&lista, reg);
    reg.chave = 7978;
    insercaoOrdenada(&lista, reg);
    exibirLista(&lista);
    reinicializar(&lista);

    return 0;
}

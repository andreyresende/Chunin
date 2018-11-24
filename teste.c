#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    int teste;
    char* nome;
}t_elemento;
int main(){
    t_elemento* celula;
    celula->teste = 10;
    strcpy(celula->nome,"Caixa");
    t_elemento* elemento = malloc(sizeof(t_elemento));
    printf("%s\n",celula->nome);





    return 0;
}
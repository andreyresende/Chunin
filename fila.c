/* Universidade de Brasilia
Instituto de Ciencias Exatas
Departamento de Ciencia da Computacao
Estrutura de Dados - 2018-2
Aluno(a): Andrey Calaca Resende
Matricula: 180062433
Turma: A
Versao do compilador: gcc version 5.4.0 20160609 (Ubuntu 5.4.0-6ubuntu1~16.04.9) */
#include "lista.h"
#include "fila.h"
#include "arvore.h"

t_fila* aloca_fila(){
    t_fila* fila     = malloc(sizeof(t_fila));
    fila->primeiro   = NULL;
    fila->ultimo     = NULL;
    fila->quantidade = 0;
    return fila;
}

t_elemento* aloca_elemento(t_node* no){
    if(no == NULL){
        printf("no nulo funcao aloca_elemento\n");
        return NULL;
    }
    t_elemento* elemento = malloc(sizeof(t_elemento));
    elemento->no         = no;
    elemento->proximo    = NULL;
    return elemento;
}

void inserir_final(t_fila* fila, t_node* no){
    if(fila == NULL || no == NULL){
        printf("fila ou no nulos, funcao inserir_final\n");
        return;
    }
    t_elemento* elemento = aloca_elemento(no);
    if(fila->quantidade == 0){
        fila->primeiro   = elemento;
        fila->ultimo     = elemento;
        fila->quantidade++;
        return;
    }
    else{
        fila->ultimo->proximo = elemento;
        fila->ultimo          = elemento;
        fila->quantidade++;
    }
}

t_node* remove_inicio(t_fila* fila){//remove da fila e retorna o no do primeiro elemento
    if(fila == NULL){
        printf("fila nula, funcao remove_inicio\n");
        return NULL;
    }
    if(fila->primeiro == NULL && fila->ultimo == NULL){
        printf("fila vazia, funcao remove_inicio\n");
        free(fila);
        return NULL;
    }
    t_node* no           = fila->primeiro->no;
    t_elemento* auxiliar = fila->primeiro;
    fila->primeiro       = fila->primeiro->proximo;
    free(auxiliar);
    return no;
}

void remove_fila(t_fila* fila){
    if(fila == NULL){
        printf("fila nula, funcao remove_fila\n");
        return;
    }
    t_elemento* auxiliar = fila->primeiro;
    while(auxiliar != NULL){
        fila->primeiro = fila->primeiro->proximo;
        free(auxiliar);
        auxiliar = fila->primeiro;
    }
    free(fila);
}
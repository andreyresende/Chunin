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

t_lista* aloca_lista(){
    t_lista* lista    = malloc(sizeof(t_lista));
    lista->primeiro   = NULL;
    lista->ultimo     = NULL;
    lista->tamanho    = 0;
    return lista;
}

t_celula* aloca_celula(){
    t_celula* celula = (t_celula *) malloc(sizeof(t_celula));
    celula->anterior = NULL;
    celula->proximo  = NULL;
    celula->ninja    = ninja_create(NULL,NULL,0,0,0,0);/* Como eu crio a celula vazia e depois jogo os valores
                                                          nesse ponto eu ainda nao tenho os argumentos da funcao */
    return celula;
}

void insere_final(t_lista* lista, int linha){//Armazena em uma nova celula uma linha aleatoria e a insere na lista
    if(lista == NULL){
        printf("lista nula na funcao insere_final\n");
        return;
    }
    t_celula* celula = aloca_celula();
    char letra;
    int linhas = 1;
    FILE *ptr;
    ptr = fopen("ninjas.txt","r");
    while(!feof(ptr)){
        if(letra == '\n')
            linhas++;
        if(linha == linhas){
            fscanf(ptr,"%[^,], %[^,], %d, %d, %d, %d",celula->ninja->nome,celula->ninja->elemento,&celula->ninja->ninjutsu,
                                                     &celula->ninja->genjutsu,&celula->ninja->taijutsu,&celula->ninja->defesa);
        }
        fscanf(ptr,"%c",&letra);
    }
    fclose(ptr);
    if(ptr == NULL){
        printf("Problema ao abrir arquivo ninjas.txt");
        exit(0);
    }
    lista->ultimo->proximo = celula;
    celula->anterior       = lista->ultimo;
    celula->proximo        = NULL;
    lista->ultimo          = celula;
    lista->tamanho++;
}

Ninja* busca_lista(t_lista* lista, int posicao){
    if(lista == NULL){
        printf("Lista nula na funcao busca_lista\n");
        return NULL;
    }
    t_celula* andando = lista->primeiro;
    int atual         = 1;
    while(atual < lista->tamanho && atual < posicao){
        andando = andando->proximo;
        atual++;
    }
    return andando->ninja;
}

void remove_lista(t_lista* lista){
    if(lista == NULL){
        printf("lista nula na funcao remove_lista\n");
        return;
    }
    t_celula* auxiliar = lista->primeiro;
    while(auxiliar != NULL){
        lista->primeiro  = lista->primeiro->proximo;
        if(auxiliar->ninja->nome     != NULL)
            free(auxiliar->ninja->nome);
        if(auxiliar->ninja->elemento != NULL)
            free(auxiliar->ninja->elemento);
        if(auxiliar->ninja           != NULL)
            free(auxiliar->ninja);
        free(auxiliar);
        auxiliar         = lista->primeiro;
    }
    free(lista);
}
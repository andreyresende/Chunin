/* Universidade de Brasilia
Instituto de Ciencias Exatas
Departamento de Ciencia da Computacao
Estrutura de Dados - 2018-2
Aluno(a): Andrey Calaca Resende
Matricula: 180062433
Turma: A
Versao do compilador: gcc version 5.4.0 20160609 (Ubuntu 5.4.0-6ubuntu1~16.04.9) */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#ifndef __lista_h__
#define __lista_h__
    #include "arvore.h"
    #include "fila.h"
#endif

typedef struct celula{
    struct celula* proximo;
    struct celula* anterior;
    Ninja* ninja;
} t_celula;

typedef struct{
    t_celula* primeiro;
    t_celula* ultimo;
    int tamanho;
} t_lista;

t_lista* classificados();//Escolhe aleatoriamente quais foram os 16 ninjas classificados dentre todos os possiveis e os coloca na lista duplamente encadeada

t_celula* escolheu(t_lista* lista, int posicao);

t_lista* aloca_lista();

t_celula* aloca_celula();//celula é o elemento da lista, elemento é o elemento da fila

void insere_final(t_lista* lista, int linha);

Ninja* busca_lista(t_lista* lista, int posicao);

void remove_lista(t_lista* lista);

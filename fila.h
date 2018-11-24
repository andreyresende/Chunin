/* Universidade de Brasilia
Instituto de Ciencias Exatas
Departamento de Ciencia da Computacao
Estrutura de Dados - 2018-2
Aluno(a): Andrey Calaca Resende
Matricula: 180062433
Turma: A
Versao do compilador: gcc version 5.4.0 20160609 (Ubuntu 5.4.0-6ubuntu1~16.04.9) */
#ifndef __fila_h__
#define __fila_h__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "arvore.h"
#include "lista.h"

typedef struct elemento{
    t_node* no;
    struct elemento* proximo;
}t_elemento;

typedef struct{
    t_elemento* primeiro;
    t_elemento* ultimo;
}t_fila;

t_fila* aloca_fila();

t_elemento* aloca_elemento(t_node* no);

void inserir_final(t_fila* fila, t_node* no);

t_node* remove_inicio(t_fila* fila);

void remove_fila(t_fila* fila);

t_fila* largura(t_node* raiz);

#endif
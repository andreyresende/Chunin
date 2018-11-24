/* Universidade de Brasilia
Instituto de Ciencias Exatas
Departamento de Ciencia da Computacao
Estrutura de Dados - 2018-2
Aluno(a): Andrey Calaca Resende
Matricula: 180062433
Turma: A
Versao do compilador: gcc version 5.4.0 20160609 (Ubuntu 5.4.0-6ubuntu1~16.04.9) */
#ifndef __arvore_h__
#define __arvore_h__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "lista.h"


typedef struct{
    char* nome;
    char* elemento;
    int ninjutsu;
    int genjutsu;
    int taijutsu;
    int defesa;
} Ninja;

typedef struct node{
    Ninja* ninja;
    struct node* left;
    struct node* right;
} t_node;

t_node* tree_create();

void tree_helper(t_node* raiz, int niveis, int altura_desejada);

void tree_free(t_node* tree);

t_node* node_create();

Ninja* ninja_create(char* nome, char* elemento, int ninjutsu, int genjutsu, int taijutsu, int defesa);

void ninja_free(Ninja* ninja);

void tela_inicial();

Ninja* selecao_personagem();

void menu();

#endif
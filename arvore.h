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

t_node* tree_create();

void tree_helper(t_node* raiz, int niveis, int altura_desejada);

Ninja* fight(Ninja* ninja_one, Ninja* ninja_two, int attribute);

void tree_free(t_node* tree);

t_node* node_create();

Ninja* ninja_create(char* nome, char* elemento, int ninjutsu, int genjutsu, int taijutsu, int defesa);

void ninja_free(Ninja* ninja);

void tela_inicial();

int visita_folha(t_node* raiz, int count, t_lista* lista);/* Basicamente eu chamo a funcao com count = 0 e ele vai descendo
                                                             com esse 0 e criando uma variavel de comparacao a cada no,
                                                             quando chega em uma folha ela retorna 1 como valor de comparacao
                                                             para o no acima, que percebe que o que ele recebeu de cima e o que
                                                             recebeu de baixo sao diferentes, isso significa que logo abaixo
                                                             pode ser uma folha, com o teste comprovando que e uma folha a funcao
                                                             usa o valor que recebeu de baixo como parametro para buscar um ninja
                                                             naquela posicao correspondente, dessa forma cada folha recebe um
                                                             ninja na ordem da lista, de forma recursiva */                                                            

Ninja* selecao_personagem();

t_lista* classificados();//Escolhe aleatoriamente quais foram os 16 ninjas classificados e os coloca na lista

t_celula* escolheu(t_lista* lista, int posicao);

t_lista* aloca_lista();

t_celula* aloca_celula();//celula é o elemento da lista, elemento é o elemento da fila

void insere_final(t_lista* lista, int linha);

Ninja* busca_lista(t_lista* lista, int posicao);

void remove_lista(t_lista* lista);

void jogo(t_node* tree, Ninja* jogador);

int octogono(t_node* tree, Ninja* jogador, int etapa, int cooldown);

int octogono_auxiliar(t_node* tree, Ninja* jogador, Ninja* inimigo, int etapa, int cooldown);
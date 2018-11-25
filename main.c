/* Universidade de Brasilia
Instituto de Ciencias Exatas
Departamento de Ciencia da Computacao
Estrutura de Dados - 2018-2
Aluno(a): Andrey Calaca Resende
Matricula: 180062433
Turma: A
Versao do compilador: gcc version 5.4.0 20160609 (Ubuntu 5.4.0-6ubuntu1~16.04.9) */
#include "arvore.h"
void show_tree(t_node* raiz){
    if(raiz->ninja != NULL){
        printf("Ninja: %s, %s, %d, %d, %d, %d \n", raiz->ninja->nome, raiz->ninja->elemento, raiz->ninja->ninjutsu,
                                                   raiz->ninja->genjutsu,raiz->ninja->taijutsu, raiz->ninja->defesa);
    }
    if(raiz->left  != NULL)
        show_tree(raiz->left);
    if(raiz->right != NULL)
        show_tree(raiz->right);
}
void show_list(t_lista* lista){
    t_celula* andando = lista->primeiro;
    printf("Lista\n");
    while(andando != NULL){
        printf("Ninja: %s, %s, %d, %d, %d, %d\n",andando->ninja->nome, andando->ninja->elemento, andando->ninja->ninjutsu,
                                                 andando->ninja->genjutsu, andando->ninja->taijutsu, andando->ninja->defesa);
        andando = andando->proximo;
    }
}
int main(){
    tela_inicial();
    t_node* raiz   = tree_create();
    t_lista* lista = classificados();
    visita_folha(raiz,0,lista);
    jogo(raiz,selecao_personagem(lista));
    remove_lista(lista);
    tree_free(raiz);
    return 0;
}
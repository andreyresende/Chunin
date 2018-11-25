/* Universidade de Brasilia
Instituto de Ciencias Exatas
Departamento de Ciencia da Computacao
Estrutura de Dados - 2018-2
Aluno(a): Andrey Calaca Resende
Matricula: 180062433
Turma: A
Versao do compilador: gcc version 5.4.0 20160609 (Ubuntu 5.4.0-6ubuntu1~16.04.9) */
#include "arvore.h"
int main(){
    int vicio = 1;
    while(vicio == 1){
        tela_inicial();
        t_node* raiz   = tree_create();
        t_lista* lista = classificados();
        visita_folha(raiz,0,lista);
        jogo(raiz,selecao_personagem(lista));
        remove_lista(lista);
        tree_free(raiz);
        printf("\n[1]  Voltar ao menu principal\n");
        printf("[2]  Sair\n");
        scanf("%d",&vicio);
        while(vicio != 1 && vicio != 2){
            printf("Insira uma opcao valida\n");
            scanf("%d",&vicio);
        }
    }
    return 0;
}
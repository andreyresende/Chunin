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

t_node* tree_create(){
    t_node* raiz = node_create();
    tree_helper(raiz,1,5);
    return raiz;
}

void tree_helper(t_node* raiz, int niveis, int altura_desejada){/* Chamada pela tree_create e serve para controlar o tamanho da
                                                                   arvore */
    if(raiz == NULL){
        printf("raiz nula, funcao tree_helper\n");
        return;
    }
    raiz->ninja          = NULL;
    if(niveis < altura_desejada){
        t_node* esquerda = node_create();
        t_node* direita  = node_create();
        raiz->left       = esquerda;
        raiz->right      = direita;
        tree_helper(esquerda,niveis+1,altura_desejada);
        tree_helper(direita,niveis+1,altura_desejada);
    }
}

void tree_free(t_node* tree){
    if(tree == NULL){
        printf("arvore nula, funcao tree_free\n");
        return;
    }
    if(tree->left  != NULL)
        tree_free(tree->left);
    if(tree->right != NULL )
        tree_free(tree->right);
    if(tree->left == NULL && tree->right == NULL){
        if(tree->ninja != NULL){
            if(tree->ninja->nome     != NULL){
                free(tree->ninja->nome);
                tree->ninja->nome     = NULL;
            }
            if(tree->ninja->elemento != NULL){
                free(tree->ninja->elemento);
                tree->ninja->elemento = NULL;
            }
            free(tree->ninja);
            tree->ninja               = NULL;
        }
        free(tree);
        tree = NULL;
    }
    free(tree);
}

t_node* node_create(){
    t_node* node = malloc(sizeof(t_node));
    node->ninja = NULL;
    node->left  = NULL;
    node->right = NULL;
    return node;
}

Ninja* ninja_create(char* nome, char* elemento, int ninjutsu, int genjutsu, int taijutsu, int defesa){
    Ninja* ninja    = (Ninja *) malloc(sizeof(Ninja));
    ninja->nome     = malloc(sizeof(char)*20);
    ninja->elemento = malloc(sizeof(char)*10);
    ninja->ninjutsu = ninjutsu;
    ninja->genjutsu = genjutsu;
    ninja->taijutsu = taijutsu;
    ninja->defesa   = defesa;
    if(nome     != NULL)
        strcpy(ninja->nome,nome);
    if(elemento != NULL)
        strcpy(ninja->elemento,elemento);
    return ninja;
}

void ninja_free(Ninja* ninja){
    if(ninja == NULL){
        printf("ninja nulo, funcao ninja_free\n");
        return;
    }
    free(ninja->nome);
    free(ninja->elemento);
    free(ninja);
}

void tela_inicial(){//Apenas os printf's da tela inicial e as duas opcoes
    char escolheu;//Usei char para evitar bugs caso o usuario teste outras entradas
    system("clear");
    printf("\n\n");
    printf(" _____                            _____ _                 _\n");
    printf("|  ___|                          /  ___\\ |               (_)\n");
    printf("| |___      ___ _ ___ ___   ___  | /  \\/ |__  _   _ _ __  _ _ __\n");
    printf("| ____| \\\\// _ | '_  `_  \\ / _ \\ | |     '_ \\| | | | '_ \\| | '_ \\\n");
    printf("| |___  >  <(_|| | | | | ||  __/ | \\__/\\ | | | |_| | | | | | | | |\n");
    printf("|_____| //\\\\___|_| |_| |_| \\___  \\_____/_| |_|\\__,_|_| |_|_|_|_|_|\n\n\n\n");
    printf("[1] Iniciar Exame\n");
    printf("[2] Sair\n");
    scanf("%c",&escolheu);
    if(escolheu == '1'){//simplesmente continua o programa
    }
    else
        exit(0);
}

t_celula* escolheu(t_lista* lista, int posicao){//Busca na lista o personagem escolhido pelo usuario
    if(lista == NULL){
        printf("lista nula, funcao escolheu\n");
        return NULL;
    }
    if(posicao == 1)
        return lista->primeiro;
    else if(posicao == 16)
        return lista->ultimo;
    else{
        t_celula* andando;
        andando = lista->primeiro;
        int i=1;
        while(andando->proximo != NULL){
            andando = andando->proximo;
            i++;
            if(i == posicao){
                return andando;
            }
        }
    }
}

Ninja* selecao_personagem(t_lista* lista){/*Apresenta a tela de seleção de personagens apresentando as opcoes da lista
                                            em ordem */
    if(lista == NULL){
        printf("lista nula, funcao selecao_personagem\n");
        return NULL;
    }
    system("clear");
    int random, i=1, posicao;
    t_celula* andando = lista->primeiro;
    printf("Escolha seu Personagem.\n\n\n");
    while(andando != NULL){
        printf("Personagem %d:\n",i);
        random = rand()%4 +1;
        switch(random){
            case 1:
                printf("Ninjutsu: %d    Genjutsu: ??    Taijutsu: ??    Defesa: ??    \n",andando->ninja->ninjutsu);
                break;
            case 2:
                printf("Ninjutsu: ??    Genjutsu: %d    Taijutsu: ??    Defesa: ??    \n",andando->ninja->genjutsu);
                break;
            case 3:
                printf("Ninjutsu: ??    Genjutsu: ??    Taijutsu: %d    Defesa: ??    \n",andando->ninja->taijutsu);
                break;
            case 4:
                printf("Ninjutsu: ??    Genjutsu: ??    Taijutsu: ??    Defesa: %d    \n",andando->ninja->defesa);
                break;
        }
        andando = andando->proximo;
        i++;
    }
    printf("Digite o numero do personagem desejado\n");
    scanf("%d",&posicao);
    while(posicao > lista->tamanho || posicao < 1){
        printf("Digite um valor valido entre 1 e %d\n",lista->tamanho);
        scanf("%d",&posicao);
    }
    printf("Personagem escolhido:\n");
    andando = escolheu(lista,posicao);//Reutilizando o ponteiro 'andando' para poupar memoria.
    printf("%s, %s, %d, %d, %d, %d\n", andando->ninja->nome, andando->ninja->elemento, andando->ninja->ninjutsu,
                                       andando->ninja->genjutsu, andando->ninja->taijutsu, andando->ninja->defesa);
}

t_lista* classificados(){//Escolhe aleatoriamente 16 ninjas dentre os possiveis e os coloca na lista duplamente encadeada
    srand(time(0));
    FILE *ptr;
    ptr = fopen("ninjas.txt","r");
    if(ptr == NULL){
        printf("Problema ao abrir arquivo ninjas.txt");
        exit(0);
    }
    char letra;
    int linhas=1,escolhidos[16], i, j, repetido = 1;
    while(!feof(ptr)){//Conta a quantidade de linhas existentes no arquivo
        fscanf(ptr,"%c",&letra);
        if(letra == '\n')
            linhas++;
    }
    fclose(ptr);
    escolhidos[0] = rand()%linhas+1;
    for(i=1;i<16;i++){//Coloca 16 numeros diferentes em um vetor, correspondentes aos 16 ninjas a serem escolhidos
        escolhidos[i] = rand()%linhas+1;
        repetido = 1;
        while(repetido){
            for(j=0;j<i;j++){
                repetido = 0;
                while(escolhidos[i] == escolhidos[j]){
                    repetido = 1;
                    escolhidos[i] = rand()%linhas+1;
                }
            }
        }
    }
    t_lista* lista    = aloca_lista();
    t_celula* celula  = aloca_celula();
    lista->ultimo     = celula;
    lista->primeiro   = celula;
    celula->anterior  = NULL;
    celula->proximo   = NULL;
    lista->tamanho++;
    linhas = 1;
    ptr = fopen("ninjas.txt","r");
    if(ptr == NULL){
        printf("Problema ao abrir arquivo ninjas.txt");
        exit(0);
    }
    while(!feof(ptr)){/* Aqui eu ja criei a primeira celula da lista e a preencho separadamente pois como todas as outras sao
                         colocadas no final eu nao teria como apontar o lista->comeco */
        if(letra == '\n')
            linhas++;
        if(escolhidos[0] == linhas){
            fscanf(ptr,"%[^,], %[^,], %d, %d, %d, %d",celula->ninja->nome,celula->ninja->elemento,&celula->ninja->ninjutsu,
                                                     &celula->ninja->genjutsu,&celula->ninja->taijutsu,&celula->ninja->defesa);
            break;
        }
        fscanf(ptr,"%c",&letra);
    }
    fclose(ptr);
    for(i=1;i<16;i++){
        insere_final(lista,escolhidos[i]);
    }
    return lista;
}

void menu(){//Funcao que vai chamando outras, formando o Menu como um todo
    tela_inicial();
    selecao_personagem(classificados());
}
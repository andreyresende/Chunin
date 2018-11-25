/* Universidade de Brasilia
Instituto de Ciencias Exatas
Departamento de Ciencia da Computacao
Estrutura de Dados - 2018-2
Aluno(a): Andrey Calaca Resende
Matricula: 180062433
Turma: A
Versao do compilador: gcc version 5.4.0 20160609 (Ubuntu 5.4.0-6ubuntu1~16.04.9) */
#include "arvore.h"
/* Funcoes Requisitadas ------------------------------------------------------------------------------------------------------*/
t_node* tree_create(){
    t_node* raiz = node_create();
    tree_helper(raiz,1,5);
    return raiz;
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

int vantagem(Ninja* ninja_one, Ninja* ninja_two){
    if(ninja_one == NULL || ninja_two == NULL){
        printf("Argumentos nulos, funcao vantagem\n");
        return 0;
    }
    if(strcmp(ninja_one->elemento,ninja_two->elemento) == 0)
        return 0;
    if(strcmp(ninja_one->elemento,"Relampago") == 0){
        if(strcmp(ninja_two->elemento,"Vento") == 0)
            return 2;
        if(strcmp(ninja_two->elemento,"Terra") == 0)
            return 1;
        return 0;
    }
    if(strcmp(ninja_one->elemento,"Terra") == 0){
        if(strcmp(ninja_two->elemento,"Relampago") == 0)
            return 2;
        if(strcmp(ninja_two->elemento,"Agua") == 0)
            return 1;
        return 0;
    }
    if(strcmp(ninja_one->elemento,"Vento") == 0){
        if(strcmp(ninja_two->elemento,"Fogo") == 0)
            return 2;
        if(strcmp(ninja_two->elemento,"Relampago") == 0)
            return 1;
        return 0;
    }
    if(strcmp(ninja_one->elemento,"Fogo") == 0){
        if(strcmp(ninja_two->elemento,"Agua") == 0)
            return 2;
        if(strcmp(ninja_two->elemento,"Vento") == 0)
            return 1;
        return 0;
    }
    if(strcmp(ninja_one->elemento,"Agua") == 0){
        if(strcmp(ninja_two->elemento,"Terra") == 0)
            return 2;
        if(strcmp(ninja_two->elemento,"Fogo") == 0)
            return 1;
        return 0;
    }
}

Ninja* fight(Ninja* ninja_one, Ninja* ninja_two, int attribute){
    if(ninja_one == NULL || ninja_two == NULL){
        printf("Argumentos nulos, funcao fight\n");
        return NULL;
    }
    if(vantagem(ninja_one,ninja_two) == 0){
        switch(attribute){
            case 1://Ninjutsu
                if(ninja_one->ninjutsu >= ninja_two->ninjutsu)
                    return ninja_one;
                else
                    return ninja_two;
            case 2://Genjutsu
                if(ninja_one->genjutsu >= ninja_two->genjutsu)
                    return ninja_one;
                else
                    return ninja_two;
            case 3://Taijutsu
                if(ninja_one->taijutsu >= ninja_two->taijutsu)
                    return ninja_one;
                else
                    return ninja_two;
            case 4://Defesa
                if(ninja_one->defesa >= ninja_two->defesa)
                    return ninja_one;
                else
                    return ninja_two;
        }
    }
    else if(vantagem(ninja_one,ninja_two) == 1){
        switch(attribute){
            case 1://Ninjutsu
                if(ninja_one->ninjutsu*1.2 >= ninja_two->ninjutsu)
                    return ninja_one;
                else
                    return ninja_two;
            case 2://Genjutsu
                if(ninja_one->genjutsu*1.2 >= ninja_two->genjutsu)
                    return ninja_one;
                else
                    return ninja_two;
            case 3://Taijutsu
                if(ninja_one->taijutsu*1.2 >= ninja_two->taijutsu)
                    return ninja_one;
                else
                    return ninja_two;
            case 4://Defesa
                if(ninja_one->defesa*1.2 >= ninja_two->defesa)
                    return ninja_one;
                else
                    return ninja_two;
        }
    }
    else{
        switch(attribute){
            case 1://Ninjutsu
                if(ninja_one->ninjutsu*0.8 >= ninja_two->ninjutsu)
                    return ninja_one;
                else
                    return ninja_two;
            case 2://Genjutsu
                if(ninja_one->genjutsu*0.8 >= ninja_two->genjutsu)
                    return ninja_one;
                else
                    return ninja_two;
            case 3://Taijutsu
                if(ninja_one->taijutsu*0.8 >= ninja_two->taijutsu)
                    return ninja_one;
                else
                    return ninja_two;
            case 4://Defesa
                if(ninja_one->defesa*0.8 >= ninja_two->defesa)
                    return ninja_one;
                else
                    return ninja_two;
        }
    }
}

void tree_print_preorder(t_node* root){
    if(root == NULL){
        printf("Argumentos nulos, funcao tree_print_preorder\n");
    }
    if(root->ninja != NULL){
        printf("%s, %s, %d, %d, %d, %d\n",root->ninja->nome, root->ninja->elemento, root->ninja->ninjutsu,
                                          root->ninja->genjutsu, root->ninja->taijutsu, root->ninja->defesa);
    }
    if(root->left != NULL)
        tree_print_preorder(root->left);
    if(root->right != NULL)
        tree_print_preorder(root->right);
}

/* ========================================================================================================================== */

/* Funcoes relativas a lista ------------------------------------------------------------------------------------------------ */
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
    char letra = 'a';//so para inicializar, o importante e ser diferente de \n
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
/* ========================================================================================================================== */
Registro* aloca_registro(){
    Registro* registro = malloc(sizeof(Registro));
    registro->primeiro = NULL;
    registro->ultimo   = NULL;
    registro->tamanho  = 0;
    return registro;
}

t_luta* aloca_luta(Ninja* ninja_one, Ninja* ninja_two, int atributo){
    if(ninja_one == NULL || ninja_two == NULL){
        printf("Argumentos nulos, funcao aloca_luta\n");
        return NULL;
    }
    t_luta* luta         = malloc(sizeof(t_luta));
    luta->proximo        = NULL;
    luta->anterior       = NULL;
    luta->ninja_um       = ninja_one;
    luta->ninja_dois     = ninja_two;
    luta->atributo_usado = atributo;
    return luta;
}

void insere_luta(Registro* registro, Ninja* ninja_one, Ninja* ninja_two, int atributo){
    if(registro == NULL || ninja_one == NULL || ninja_two == NULL){
        printf("Argumentos nulos, funcao insere_luta\n");
        return;
    }
    t_luta* luta = aloca_luta(ninja_one, ninja_two, atributo);
    if(registro->primeiro == NULL){
        registro->primeiro = luta;
        registro->ultimo   = luta;
    }
    else{
        registro->ultimo->proximo = luta;
        luta->anterior            = registro->ultimo;
        registro->ultimo          = luta;
    }
}

void remove_registro(Registro* registro){
    if(registro == NULL){
        printf("Argumento nulo, funcao remove_registro\n");
        return;
    }
    t_luta* andando = registro->primeiro;
    while(andando != NULL){
        registro->primeiro = registro->primeiro->proximo;
        free(andando);
        andando = registro->primeiro;
    }
    free(registro);
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

int folha_abaixo(t_node* no){
    if(no == NULL){
        printf("Argumentos nulos, funcao folha_abaixo\n");
        return -1;
    }
    if(no->left->left == NULL && no->left->right == NULL && no->right->left == NULL && no->right->right == NULL)
        return 1;
    else
        return 0;
}

int visita_folha(t_node* raiz, int count, t_lista* lista){
    if(raiz == NULL || lista == NULL){
        printf("raiz ou lista nulas, funcao visita_folha\n");
        exit(0);
    }
    int comparador = count;
    if(raiz->left  != NULL){
        comparador = visita_folha(raiz->left, count, lista);
        if(comparador != count && folha_abaixo(raiz)){
            Ninja* ninja = busca_lista(lista, comparador);
            raiz->left->ninja = ninja_create(ninja->nome, ninja->elemento, ninja->ninjutsu, ninja->genjutsu, ninja->taijutsu,
                                             ninja->defesa);
            count++;
        }
        else if(comparador != count && !folha_abaixo(raiz)){
            count = comparador;
        }
    }
    else if(raiz->left == NULL && raiz->right == NULL){
        return count+1;
    }
    comparador = count;
    if(raiz->right != NULL){
        comparador = visita_folha(raiz->right, count, lista);
        if(comparador != count && folha_abaixo(raiz)){
            Ninja* ninja = busca_lista(lista, comparador);
            raiz->right->ninja = ninja_create(ninja->nome, ninja->elemento, ninja->ninjutsu, ninja->genjutsu, ninja->taijutsu,
                                             ninja->defesa);
            count++;
        }
        else if(comparador != count && !folha_abaixo(raiz)){
            count = comparador;
        }
    }
    else if(raiz->left == NULL && raiz->right == NULL){
        return count+1;
    }
    return count;
}

void tela_inicial(){//Apenas os printf's da tela inicial e as duas opcoes
    char selecionou;//Usei char para evitar bugs caso o usuario teste outras entradas
    system("clear");
    printf("███████╗██╗  ██╗ █████╗ ███╗   ███╗███████╗     ██████╗██╗  ██╗██╗   ██╗███╗   ██╗██╗███╗   ██╗\n");
    printf("██╔════╝╚██╗██╔╝██╔══██╗████╗ ████║██╔════╝    ██╔════╝██║  ██║██║   ██║████╗  ██║██║████╗  ██║\n");
    printf("█████╗   ╚███╔╝ ███████║██╔████╔██║█████╗      ██║     ███████║██║   ██║██╔██╗ ██║██║██╔██╗ ██║\n");
    printf("██╔══╝   ██╔██╗ ██╔══██║██║╚██╔╝██║██╔══╝      ██║     ██╔══██║██║   ██║██║╚██╗██║██║██║╚██╗██║\n");
    printf("███████╗██╔╝ ██╗██║  ██║██║ ╚═╝ ██║███████╗    ╚██████╗██║  ██║╚██████╔╝██║ ╚████║██║██║ ╚████║\n");
    printf("╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝     ╚═════╝╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═══╝╚═╝╚═╝  ╚═══╝\n");
    printf("                                                                                               \n");
    printf("[1] Iniciar Exame\n");
    printf("[2] Sair\n");
    scanf("%c",&selecionou);
    if(selecionou == '1'){//simplesmente continua o programa
    }
    else
        exit(0);
}

void tela_vitoria(int etapa){
    system("clear");
    printf("%da ETAPA: Resultado\n",etapa);
    printf("██╗   ██╗██╗████████╗ ██████╗ ██████╗ ██╗ █████╗ \n");
    printf("██║   ██║██║╚══██╔══╝██╔═══██╗██╔══██╗██║██╔══██╗\n");
    printf("██║   ██║██║   ██║   ██║   ██║██████╔╝██║███████║\n");
    printf("╚██╗ ██╔╝██║   ██║   ██║   ██║██╔══██╗██║██╔══██║\n");
    printf(" ╚████╔╝ ██║   ██║   ╚██████╔╝██║  ██║██║██║  ██║\n");
    printf("  ╚═══╝  ╚═╝   ╚═╝    ╚═════╝ ╚═╝  ╚═╝╚═╝╚═╝  ╚═╝\n");
    printf("                                                 \n");
}

void tela_derrota(int etapa){
    system("clear");
    printf("%da ETAPA: Resultado\n",etapa);
    printf("██████╗ ███████╗██████╗ ██████╗  ██████╗ ████████╗ █████╗ \n");
    printf("██╔══██╗██╔════╝██╔══██╗██╔══██╗██╔═══██╗╚══██╔══╝██╔══██╗\n");
    printf("██║  ██║█████╗  ██████╔╝██████╔╝██║   ██║   ██║   ███████║\n");
    printf("██║  ██║██╔══╝  ██╔══██╗██╔══██╗██║   ██║   ██║   ██╔══██║\n");
    printf("██████╔╝███████╗██║  ██║██║  ██║╚██████╔╝   ██║   ██║  ██║\n");
    printf("╚═════╝ ╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝    ╚═╝   ╚═╝  ╚═╝\n");
    printf("                                                          \n");
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
        return 0;
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
    return busca_lista(lista,posicao);                                       
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
    int linhas=1,escolhidos[16], auxiliar[32], i, j, repetido = 1;
    while(!feof(ptr)){//Conta a quantidade de linhas existentes no arquivo
        fscanf(ptr,"%c",&letra);
        if(letra == '\n')
            linhas++;
    }
    fclose(ptr);
    for(i=0;i<32;i++){//Coloca todos os 32 inteiros de um vetor como 1
        auxiliar[i] = 1;
    }
    for(i=0;i<16;i++){
        escolhidos[i] = rand()%linhas+1;//Escolhe um valor aleatorio entre 1 e 32
        if(auxiliar[escolhidos[i]] == 1){//Se ele estiver disponivel basta marcar que agora ele foi pego
            auxiliar[escolhidos[i]] = 0;
        }
        else{//Caso esteja indisponivel
            while(auxiliar[escolhidos[i]] == 0){//Utiliza a funcao rand ate encontrar um que esteja disponivel
                escolhidos[i] = rand()%linhas+1;
            }
            auxiliar[escolhidos[i]] = 0;//E marca que ele foi pego
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

int octogono_auxiliar(Registro* registro,t_node* tree, Ninja* jogador, Ninja* inimigo, int etapa, int cooldown){/* Poupa 
repeticao de codigo */
    if(tree == NULL || jogador == NULL || inimigo == NULL || registro == NULL){
        printf("Argumento nulo, funcao octonogo_auxiliar\n");
        return 0;
    }
    int aux;
    int atributo;
    int segura_tela;
    system("clear");
    if(vantagem(jogador,inimigo) == 1){
        printf("%da ETAPA\n\n",etapa);
        printf("Seu personagem: %s\n",jogador->nome);
        printf("SUPREMACIA ELEMENTAL: %s > %s\n",jogador->elemento,inimigo->elemento);
        printf("Todos os atributos foram multiplicados por x1.2\n");
        if(cooldown == 0){
            aux = jogador->ninjutsu*1.2;
            printf("1) Ninjutsu: %d\n",aux);
            aux = jogador->genjutsu*1.2;
            printf("2) Genjutsu: %d\n",aux);
            aux = jogador->taijutsu*1.2;
            printf("3) Taijutsu: %d\n",aux);
            aux = jogador->defesa*1.2;
            printf("4) Defesa  : %d\n\n",aux);
        }
        else{
            if(cooldown == 1){
                printf("X) Ninjutsu: XX\n");
                aux = jogador->genjutsu*1.2;
                printf("2) Genjutsu: %d\n",aux);
                aux = jogador->taijutsu*1.2;
                printf("3) Taijutsu: %d\n",aux);
                aux = jogador->defesa*1.2;
                printf("4) Defesa  : %d\n\n",aux);
            }
            else if(cooldown == 2){
                aux = jogador->ninjutsu*1.2;
                printf("1) Ninjutsu: %d\n",aux);
                printf("X) Genjutsu: XX\n");
                aux = jogador->taijutsu*1.2;
                printf("3) Taijutsu: %d\n",aux);
                aux = jogador->defesa*1.2;
                printf("4) Defesa  : %d\n\n",aux);
            }
            else if(cooldown == 3){
                aux = jogador->ninjutsu*1.2;
                printf("1) Ninjutsu: %d\n",aux);
                aux = jogador->genjutsu*1.2;
                printf("2) Genjutsu: %d\n",aux);
                printf("X) Taijutsu: XX\n");
                aux = jogador->defesa*1.2;
                printf("4) Defesa  : %d\n\n",aux);
            }
            else if(cooldown == 4){
                aux = jogador->ninjutsu*1.2;
                printf("1) Ninjutsu: %d\n",aux);
                aux = jogador->genjutsu*1.2;
                printf("2) Genjutsu: %d\n",aux);
                aux = jogador->taijutsu*1.2;
                printf("3) Taijutsu: %d\n",aux);
                printf("X) Defesa  : XX\n\n");
            }
        }
        printf("Seu adversario: %s\n\n",inimigo->nome);
        printf("Selecione um atributo: ");
        scanf("%d",&atributo);
        printf("\n");
        while(atributo < 1 || atributo > 4 || atributo == cooldown){
            printf("Selecione um atributo valido: ");
            scanf("%d",&atributo);
            printf("\n");
        }
        tree->ninja = fight(jogador,inimigo,atributo);
        insere_luta(registro,jogador,inimigo,atributo);
        if(tree->ninja == jogador){
            tela_vitoria(etapa);
            if(atributo == 1){
                aux = jogador->ninjutsu * 1.2;
                printf("%s (Ninjutsu %d) x %s (Ninjutsu %d) [x1.2]\n",jogador->nome, aux, inimigo->nome,
                                                                      inimigo->ninjutsu);
            }
            else if(atributo == 2){
                aux = jogador->genjutsu * 1.2;
                printf("%s (Genjutsu %d) x %s (Genjutsu %d) [x1.2]\n",jogador->nome, aux, inimigo->nome,
                                                                      inimigo->genjutsu);
            }
            else if(atributo == 3){
                aux = jogador->taijutsu * 1.2;
                printf("%s (Taijutsu %d) x %s (Taijutsu %d) [x1.2]\n",jogador->nome, aux, inimigo->nome,
                                                                      inimigo->taijutsu);
            }
            else if(atributo == 4){
                aux = jogador->defesa * 1.2;
                printf("%s (Defesa %d) x %s (Defesa %d) [x1.2]\n",jogador->nome, aux, inimigo->nome,
                                                                      inimigo->defesa);
            }
            printf("%s ganhou a batalha\n\n",jogador->nome);
            if(etapa != 4){
                printf("[1] Prosseguir\n");
                scanf("%d",&segura_tela);
            }
        }
        else{
            tela_derrota(etapa);
            if(atributo == 1){
                aux = jogador->ninjutsu * 1.2;
                printf("%s (Ninjutsu %d) x %s (Ninjutsu %d) [x1.2]\n",jogador->nome, aux, inimigo->nome,
                                                                      inimigo->ninjutsu);
            }
            else if(atributo == 2){
                aux = jogador->genjutsu * 1.2;
                printf("%s (Genjutsu %d) x %s (Genjutsu %d) [x1.2]\n",jogador->nome, aux, inimigo->nome,
                                                                      inimigo->genjutsu);
            }
            else if(atributo == 3){
                aux = jogador->taijutsu * 1.2;
                printf("%s (Taijutsu %d) x %s (Taijutsu %d) [x1.2]\n",jogador->nome, aux, inimigo->nome,
                                                                      inimigo->taijutsu);
            }
            else if(atributo == 4){
                aux = jogador->defesa * 1.2;
                printf("%s (Defesa %d) x %s (Defesa %d) [x1.2]\n",jogador->nome, aux, inimigo->nome,
                                                                      inimigo->defesa);
            }
            printf("%s ganhou a batalha\n\n",inimigo->nome);
        }
        return atributo;
    }
    else if(vantagem(jogador,inimigo) == 2){
        printf("%da ETAPA\n\n",etapa);
        printf("Seu personagem: %s\n",jogador->nome);
        printf("INFERIORIDADE ELEMENTAL: %s < %s\n",inimigo->elemento,jogador->elemento);
        printf("Todos os atributos foram multiplicados por x0.8\n");
        if(cooldown == 0){
            aux = jogador->ninjutsu*0.8;
            printf("1) Ninjutsu: %d\n",aux);
            aux = jogador->genjutsu*0.8;
            printf("2) Genjutsu: %d\n",aux);
            aux = jogador->taijutsu*0.8;
            printf("3) Taijutsu: %d\n",aux);
            aux = jogador->defesa*0.8;
            printf("4) Defesa  : %d\n\n",aux);
        }
        else{
            if(cooldown == 1){
                printf("X) Ninjutsu: XX\n");
                aux = jogador->genjutsu*0.8;
                printf("2) Genjutsu: %d\n",aux);
                aux = jogador->taijutsu*0.8;
                printf("3) Taijutsu: %d\n",aux);
                aux = jogador->defesa*0.8;
                printf("4) Defesa  : %d\n\n",aux);
            }
            else if(cooldown == 2){
                aux = jogador->ninjutsu*0.8;
                printf("1) Ninjutsu: %d\n",aux);
                printf("X) Genjutsu: XX\n");
                aux = jogador->taijutsu*0.8;
                printf("3) Taijutsu: %d\n",aux);
                aux = jogador->defesa*0.8;
                printf("4) Defesa  : %d\n\n",aux);
            }
            else if(cooldown == 3){
                aux = jogador->ninjutsu*0.8;
                printf("1) Ninjutsu: %d\n",aux);
                aux = jogador->genjutsu*0.8;
                printf("2) Genjutsu: %d\n",aux);
                printf("X) Taijutsu: XX\n");
                aux = jogador->defesa*0.8;
                printf("4) Defesa  : %d\n\n",aux);
            }
            else if(cooldown == 4){
                aux = jogador->ninjutsu*0.8;
                printf("1) Ninjutsu: %d\n",aux);
                aux = jogador->genjutsu*0.8;
                printf("2) Genjutsu: %d\n",aux);
                aux = jogador->taijutsu*0.8;
                printf("3) Taijutsu: %d\n",aux);
                printf("X) Defesa  : XX\n\n");
            }
        }
        printf("Seu adversario: %s\n\n",inimigo->nome);
        printf("Selecione um atributo: ");
        scanf("%d",&atributo);
        printf("\n");
        while(atributo < 1 || atributo > 4 || atributo == cooldown){
            printf("Selecione um atributo valido: ");
            scanf("%d",&atributo);
            printf("\n");
        }
        tree->ninja = fight(jogador,inimigo,atributo);
        insere_luta(registro,jogador,inimigo,atributo);
        if(tree->ninja == jogador){
            tela_vitoria(etapa);
            if(atributo == 1){
                aux = jogador->ninjutsu * 0.8;
                printf("%s (Ninjutsu %d) x %s (Ninjutsu %d) [x0.8]\n",jogador->nome, aux, inimigo->nome,
                                                                      inimigo->ninjutsu);
            }
            else if(atributo == 2){
                aux = jogador->genjutsu * 0.8;
                printf("%s (Genjutsu %d) x %s (Genjutsu %d) [x0.8]\n",jogador->nome, aux, inimigo->nome,
                                                                      inimigo->genjutsu);
            }
            else if(atributo == 3){
                aux = jogador->taijutsu * 0.8;
                printf("%s (Taijutsu %d) x %s (Taijutsu %d) [x0.8]\n",jogador->nome, aux, inimigo->nome,
                                                                      inimigo->taijutsu);
            }
            else if(atributo == 4){
                aux = jogador->defesa * 0.8;
                printf("%s (Defesa %d) x %s (Defesa %d) [x0.8]\n",jogador->nome, aux, inimigo->nome,
                                                                      inimigo->defesa);
            }
            printf("%s ganhou a batalha\n\n",jogador->nome);
            if(etapa != 4){
                printf("[1] Prosseguir\n");
                scanf("%d",&segura_tela);
            }
        }
        else{
            tela_derrota(etapa);
            if(atributo == 1){
                aux = jogador->ninjutsu * 0.8;
                printf("%s (Ninjutsu %d) x %s (Ninjutsu %d) [x0.8]\n",jogador->nome, aux, inimigo->nome,
                                                                      inimigo->ninjutsu);
            }
            else if(atributo == 2){
                aux = jogador->genjutsu * 0.8;
                printf("%s (Genjutsu %d) x %s (Genjutsu %d) [x0.8]\n",jogador->nome, aux, inimigo->nome,
                                                                      inimigo->genjutsu);
            }
            else if(atributo == 3){
                aux = jogador->taijutsu * 0.8;
                printf("%s (Taijutsu %d) x %s (Taijutsu %d) [x0.8]\n",jogador->nome, aux, inimigo->nome,
                                                                      inimigo->taijutsu);
            }
            else if(atributo == 4){
                aux = jogador->defesa * 0.8;
                printf("%s (Defesa %d) x %s (Defesa %d) [x0.8]\n",jogador->nome, aux, inimigo->nome,
                                                                      inimigo->defesa);
            }
            printf("%s ganhou a batalha\n\n",inimigo->nome);
        }
        return atributo;
    }
    else{
        printf("%da ETAPA\n\n",etapa);
        printf("Seu personagem: %s\n",jogador->nome);
        if(cooldown == 0){
        printf("1) Ninjutsu: %d\n",jogador->ninjutsu);
        printf("2) Genjutsu: %d\n",jogador->genjutsu);
        printf("3) Taijutsu: %d\n",jogador->taijutsu);
        printf("4) Defesa  : %d\n\n",jogador->defesa);
        }
        else{
            if(cooldown == 1){
                printf("X) Ninjutsu: XX\n");
                printf("2) Genjutsu: %d\n",jogador->genjutsu);
                printf("3) Taijutsu: %d\n",jogador->taijutsu);
                printf("4) Defesa  : %d\n\n",jogador->defesa);
            }
            else if(cooldown == 2){
                printf("1) Ninjutsu: %d\n",jogador->ninjutsu);
                printf("X) Genjutsu: XX\n");
                printf("3) Taijutsu: %d\n",jogador->taijutsu);
                printf("4) Defesa  : %d\n\n",jogador->defesa);
            }
            else if(cooldown == 3){
                printf("1) Ninjutsu: %d\n",jogador->ninjutsu);
                printf("2) Genjutsu: %d\n",jogador->genjutsu);
                printf("X) Taijutsu: XX\n");
                printf("4) Defesa  : %d\n\n",jogador->defesa);
            }
            else if(cooldown == 4){
                printf("1) Ninjutsu: %d\n",jogador->ninjutsu);
                printf("2) Genjutsu: %d\n",jogador->genjutsu);
                printf("3) Taijutsu: %d\n",jogador->taijutsu);
                printf("X) Defesa  : XX\n\n");
            }
        }
        printf("Seu adversario: %s\n\n",inimigo->nome);
        printf("Selecione um atributo: ");
        scanf("%d",&atributo);
        printf("\n");
        while(atributo < 1 || atributo > 4 || atributo == cooldown){
            printf("Selecione um atributo valido: ");
            scanf("%d",&atributo);
            printf("\n");
        }
        tree->ninja = fight(jogador,inimigo,atributo);
        insere_luta(registro,jogador,inimigo,atributo);
        if(tree->ninja == jogador){
            tela_vitoria(etapa);
            if(atributo == 1){
                printf("%s (Ninjutsu %d) x %s (Ninjutsu %d)\n",jogador->nome, jogador->ninjutsu, inimigo->nome,
                                                               inimigo->ninjutsu);
            }
            else if(atributo == 2){
                printf("%s (Genjutsu %d) x %s (Genjutsu %d)\n",jogador->nome, jogador->genjutsu, inimigo->nome,
                                                               inimigo->genjutsu);
            }
            else if(atributo == 3){
                printf("%s (Taijutsu %d) x %s (Taijutsu %d)\n",jogador->nome, jogador->taijutsu, inimigo->nome,
                                                               inimigo->taijutsu);
            }
            else if(atributo == 4){
                printf("%s (Defesa %d) x %s (Defesa %d)\n",jogador->nome, jogador->defesa, inimigo->nome,
                                                               inimigo->defesa);
            }
            printf("%s ganhou a batalha\n\n",jogador->nome);
            if(etapa != 4){
                printf("[1] Prosseguir\n");
                scanf("%d",&segura_tela);
            }
        }
        else{
            tela_derrota(etapa);
            if(atributo == 1){
                printf("%s (Ninjutsu %d) x %s (Ninjutsu %d)\n",jogador->nome, jogador->ninjutsu, inimigo->nome,
                                                               inimigo->ninjutsu);
            }
            else if(atributo == 2){
                printf("%s (Genjutsu %d) x %s (Genjutsu %d)\n",jogador->nome, jogador->genjutsu, inimigo->nome,
                                                               inimigo->genjutsu);
            }
            else if(atributo == 3){
                printf("%s (Taijutsu %d) x %s (Taijutsu %d)\n",jogador->nome, jogador->taijutsu, inimigo->nome,
                                                               inimigo->taijutsu);
            }
            else if(atributo == 4){
                printf("%s (Defesa %d) x %s (Defesa %d)\n",jogador->nome, jogador->defesa, inimigo->nome,
                                                               inimigo->defesa);
            }
            printf("%s ganhou a batalha\n\n",inimigo->nome);
        }
        return atributo;
    }
}

int octogono(Registro* registro,t_node* tree, Ninja* jogador, int etapa, int cooldown){//Realiza as lutas
    if(registro == NULL || tree == NULL || jogador == NULL){
        printf("Argumentos nulos, funcao octogono\n");
        return -1;
    }
    int aux;
    if(tree == NULL || jogador == NULL){
        printf("Argumento nulo, funcao busca_inimigo\n");
        return 0;
    }
    int indisponivel;//atributo indisponivel
    if(tree->ninja == NULL && tree->left->ninja != NULL && tree->right->ninja != NULL){//aqui deve acontecer uma luta
        if(strcmp(tree->left->ninja->nome,jogador->nome) == 0){//se o jogador estiver participando
            return octogono_auxiliar(registro,tree, jogador, tree->right->ninja, etapa, 0);
        }
        else if(strcmp(tree->right->ninja->nome,jogador->nome) == 0){
            return octogono_auxiliar(registro,tree, jogador, tree->left->ninja, etapa, 0);
        }
        else{//se for npc x npc
            aux = rand()%4+1;
            tree->ninja = fight(tree->left->ninja,tree->right->ninja,aux);
            insere_luta(registro, tree->left->ninja, tree->right->ninja, aux);
            return 0;
        }
    }
    else{//aqui se caminha ate encontrar onde devera acontecer uma luta
        if(tree->left  != NULL){
            indisponivel = octogono(registro,tree->left,jogador,etapa-1,indisponivel);
        }
        if(tree->right != NULL){
            if(indisponivel == 0){
                indisponivel = octogono(registro,tree->right,jogador,etapa-1,indisponivel);
            }
            else{
                octogono(registro,tree->right,jogador,etapa-1,indisponivel);
            }
        }
    }
    if(tree->ninja == NULL && tree->left->ninja != NULL && tree->right->ninja != NULL){//lutas acima das folhas
        if(strcmp(tree->left->ninja->nome,jogador->nome) == 0){
            return octogono_auxiliar(registro,tree, jogador, tree->right->ninja, etapa, indisponivel);
        }
        else if(strcmp(tree->right->ninja->nome,jogador->nome) == 0){
            return octogono_auxiliar(registro,tree,jogador, tree->left->ninja,etapa,indisponivel);
        }
        else{
            aux = rand()%4+1;
            tree->ninja = fight(tree->left->ninja, tree->right->ninja, aux);
            insere_luta(registro,tree->left->ninja,tree->right->ninja, aux);
            return 0;
        }
    }
}

void tela_final_auxiliar(Registro* registro, int posicao){
    if(registro == NULL){
        printf("Argumentos nulos, funcao tela_final_auxiliar\n");
        return;
    }
    t_luta* andando;
    andando = registro->primeiro;
    int i=1;
    while(i < posicao){
        andando = andando->proximo;
        i++;
    }
    if(andando->atributo_usado == 1){
            printf("%s (Ninjutsu %d) x %s (Ninjutsu %d)\n",andando->ninja_um->nome, andando->ninja_um->ninjutsu, andando->ninja_dois->nome,
                                                            andando->ninja_dois->ninjutsu);
        }
    else if(andando->atributo_usado == 2){
        printf("%s (Genjutsu %d) x %s (Genjutsu %d)\n",andando->ninja_um->nome, andando->ninja_um->genjutsu, andando->ninja_dois->nome,
                                                        andando->ninja_dois->genjutsu);
    }
    else if(andando->atributo_usado == 3){
        printf("%s (Taijutsu %d) x %s (Taijutsu %d)\n",andando->ninja_um->nome, andando->ninja_um->taijutsu, andando->ninja_dois->nome,
                                                        andando->ninja_dois->taijutsu);
    }
    else if(andando->atributo_usado == 4){
        printf("%s (Defesa %d) x %s (Defesa %d)\n",andando->ninja_um->nome, andando->ninja_um->defesa, andando->ninja_dois->nome,
                                                        andando->ninja_dois->defesa);
    }
}

void tela_final(Registro* registro){
    if(registro == NULL){
        printf("Argumentos nulos, funcao tela_final\n");
        return;
    }
    t_luta* andando;
    andando = registro->primeiro;
    printf("1a ETAPA:\n");
    tela_final_auxiliar(registro,1);
    tela_final_auxiliar(registro,2);
    tela_final_auxiliar(registro,9);
    tela_final_auxiliar(registro,3);
    tela_final_auxiliar(registro,4);
    tela_final_auxiliar(registro,10);
    tela_final_auxiliar(registro,13);
    tela_final_auxiliar(registro,5);
    printf("\n2a ETAPA:\n");
    tela_final_auxiliar(registro,6);
    tela_final_auxiliar(registro,11);
    tela_final_auxiliar(registro,7);
    tela_final_auxiliar(registro,8);
    printf("\n3a ETAPA:\n");
    tela_final_auxiliar(registro,12);
    tela_final_auxiliar(registro,14);
    printf("\n4a ETAPA:\n");
    tela_final_auxiliar(registro,15);
}

void jogo(t_node* tree, Ninja* jogador){
    if(tree == NULL || jogador == NULL){
        printf("Argumento nulo, funcao jogo\n");
        return;
    }
    Registro* registro = aloca_registro();
    octogono(registro,tree,jogador,4,0);
    tela_final(registro);
    remove_registro(registro);
}
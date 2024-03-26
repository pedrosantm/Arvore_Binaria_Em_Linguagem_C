#include <stdio.h>
#include <stdlib.h>


typedef struct no{
    int conteudo;
    struct no *dir, *esq;
}no;

typedef struct arvore{
    no *raiz;
}arvore;


int insere(arvore* arv, int valor);
int insere_esquerda(no* no_atual, int valor);
int insere_direita(no* no, int valor);
void incializa(arvore* arv);
void printar_pre_ordem(no* raiz);
int contagem_de_nivel(no* raiz);
int buscar(no*raiz, int valor);

int cont = 0;
int valor;
int main(){
    int op, valor, retorno_insere, retorno_contagem, retorno_busca;
    arvore arv;

    incializa(&arv);
    printf("-----------------------------\n");
    printf("Arvore inicializada\n");

    printf("0-Sair\n1-Adicionar\n2-Imprimir\n3-Verificar níveis\n4-Buscar valor\n");
    printf("-----------------------------\n");
    scanf("%d", &op);
    do{
        switch(op){
        case 3:
            retorno_contagem = contagem_de_nivel(arv.raiz);
            printf("Arvore de %d niveis\n", retorno_contagem);
            break;
        case 1:
            printf("Digite o valor: ");
            scanf("%d", &valor);
            retorno_insere=insere(&arv, valor);
            if(retorno_insere==1){
                printf("Adicionado com sucesso\n");
            }else{
                printf("Erro ao adicionar\n");
            }
            break;
        case 2:
            printf("------------\n");
            printf("Conteudo da arvore:\n");
            printar(arv.raiz);
            printf("\n");
            printf("%d Iten/s\n", cont);
            printf("------------");
            printf("\n");
            break;
        case 0:
            printf("Saindo...\n");
            return 0;
        case 4:
            printf("Qual numero devera ser buscado?\n");
            scanf("%d", &valor);
            retorno_busca = buscar(arv.raiz, valor);
            if(retorno_busca == 1){
                printf("Esse valor esta presente na arvore\n");
            }else{
                printf("Esse valor nao esta presente na arvore\n");
            }
        }
        printf("-----------------------------\n");
        printf("0-Sair\n1-Adicionar\n2-Imprimir\n3-Verificar niveis\n4-Buscar valor\n");
        printf("-----------------------------\n");
        scanf("%d", &op);
    }while(op!=0);

    return 0;
}


void incializa(arvore* arv){
    arv->raiz = NULL;
}

int insere(arvore* arv, int valor){
    int retorno;
    if(arv->raiz==NULL){//verificação se a raiz é nula
            no* novo = (no*)malloc(sizeof(no));//criação do primeiro no
            novo->conteudo = valor;
            novo->dir = NULL;
            novo->esq = NULL;
            arv->raiz = novo;//raiz aponta para o primeiro no
            cont++;
            return 1;
    }else{
            if(valor>arv->raiz->conteudo){//verificação de lado que sera inserido
                retorno = insere_direita(arv->raiz, valor);//direita para valores maiores
                if(retorno == 1){
                    cont++;
                    return 1;
                }
            }else{
                retorno=insere_esquerda(arv->raiz, valor);//esquerda para valores menores
                if(retorno == 1){
                    cont++;
                    return 1;
                }
            }
    }
}


int insere_esquerda(no* no_atual, int valor){
    int retorno;
    if(no_atual->esq == NULL){//verificação se o valor a esquerda é vazio
        no* novo = (no*)malloc(sizeof(no));//se sim, criado novo no e adicionado
        novo->conteudo = valor;
        novo->esq = NULL;
        novo->dir = NULL;
        no_atual->esq = novo;
        return 1;
    }else{//se nao for vazio varifica-se onde adiciona-lo
        if(valor>no_atual->esq->conteudo){//direita para valores maiores
            retorno=insere_direita(no_atual->esq, valor);
            if(retorno == 1){
                return 1;
            }
        }else{//esquerda para valores menores
        insere_esquerda(no_atual->esq, valor);
        }
    }
}


int insere_direita(no* no_atual, int valor){
    int retorno;
    if(no_atual->dir == NULL){//verificação se o valor a direita é vazio
        no* novo = (no*)malloc(sizeof(no));//se sim, criado novo no e adicionado
        novo->conteudo = valor;
        novo->esq = NULL;
        novo->dir = NULL;
        no_atual->dir = novo;
        return 1;
    }else{//se nao for vazio varifica-se onde adiciona-lo
        if(valor>no_atual->dir->conteudo){//direita para valores maiores
            retorno=insere_direita(no_atual->dir, valor);
            if(retorno == 1){
                return 1;
            }
        }else{//esquerda para valores menores
        insere_esquerda(no_atual->dir, valor);
        }
    }
}

void printar_pre_ordem(no* raiz){
    if(raiz!=NULL){
        printf("%d ", raiz->conteudo);
        printar(raiz->esq);
        printar(raiz->dir);
    }
}

void printar_pos_ordem(no* raiz){
    if(raiz!=NULL){
        printf("%d ", raiz->conteudo);
        printar(raiz->dir);
        printar(raiz->esq);
    }
}



int contagem_de_nivel(no* raiz) {
    if (raiz == NULL) {
        return 0; // Se a raiz for nula, a árvore está vazia
    }

    int cont_esquerda = contagem_de_nivel(raiz->esq); // Contagem de níveis na subárvore esquerda
    int cont_direita = contagem_de_nivel(raiz->dir); // Contagem de níveis na subárvore direita

   if(cont_esquerda > cont_direita){
       return cont_esquerda + 1;
   }else{
       return cont_direita + 1;
   }
}

int buscar(no* raiz, int valor) {
    int retorno_busca;
    if (raiz != NULL) {
        if (raiz->conteudo == valor) {
            return 1;//retorna 1 quando o valor é encontrado na arvore
        } else {
            retorno_busca = buscar(raiz->esq, valor);
            if (retorno_busca == 1) {
                return 1;
            }
            retorno_busca = buscar(raiz->dir, valor);
            if (retorno_busca == 1) {
                return 1;
            }
        }
    }
    return 0; // Retorna 0 se o valor não foi encontrado na árvore
}

#include <stdio.h>
#include <stdlib.h>


typedef struct no{
    int conteudo;
    struct no *dir, *esq;
}no;

typedef struct arvore{
    no *raiz;
}arvore;


void insere(arvore* arv, int valor);
void insere_esquerda(no* no_atual, int valor);
void insere_direita(no* no, int valor);

int main(){
    int op, valor;
    arvore arv;
    arv.raiz = NULL;

    printf("0-Sair\n1-Adicionar\n2-Imprimir\n");
    scanf("%d", &op);
    do{
        switch(op){
        case 1:
            printf("Digite o valor: ");
            scanf("%d", &valor);
            insere(arv.raiz, valor);
            break;
        case 2:

        default:
            printf("Op��o invalida\n");
            break;
    }

}while(op!=0);

    return 0;
}


void insere(arvore* arv, int valor){
    if(arv->raiz==NULL){//verifica��o se a raiz � nula
            no* novo = (no*)malloc(sizeof(no));//cria��o do primeiro no
            novo->conteudo = valor;
            novo->dir = NULL;
            novo->esq = NULL;
            arv->raiz = novo;//raiz aponta para o primeiro no
    }else{
            if(valor>arv->raiz->conteudo){//verifica��o de lado que sera inserido
                insere_direita(arv->raiz, valor);//direita para valores maiores
            }else{
                insere_direita(arv->raiz, valor);//esquerda para valores menores
            }
    }
}


void insere_esquerda(no* no_atual, int valor){
    if(no_atual->esq == NULL){//verifica��o se o valor a esquerda � vazio
        no* novo = (no*)malloc(sizeof(no));//se sim, criado novo no e adicionado
        novo->conteudo = valor;
        novo->esq = NULL;
        novo->dir = NULL;
        no_atual->esq = novo;
    }else{//se nao for vazio varifica-se onde adiciona-lo
        if(valor>no_atual->esq->conteudo){//direita para valores maiores
            insere_direita(no_atual->esq, valor);
        }else{//esquerda para valores menores
        insere_esquerda(no_atual->esq, valor);
        }
    }
}


void insere_direita(no* no_atual, int valor){
    if(no_atual->dir == NULL){//verifica��o se o valor a direita � vazio
        no* novo = (no*)malloc(sizeof(no));//se sim, criado novo no e adicionado
        novo->conteudo = valor;
        novo->esq = NULL;
        novo->dir = NULL;
        no_atual->dir = novo;
    }else{//se nao for vazio varifica-se onde adiciona-lo
        if(valor>no_atual->dir->conteudo){//direita para valores maiores
            insere_direita(no_atual->dir, valor);
        }else{//esquerda para valores menores
        insere_esquerda(no_atual->dir, valor);
        }
    }
}

void printar(no* raiz){
    if(raiz!=NULL){
        printf("%d ", raiz->conteudo);
        printar(raiz->esq);
        printar(raiz->dir);
    }
}

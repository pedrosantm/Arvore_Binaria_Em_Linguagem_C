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
void printar(no* raiz);

int main(){
    int op, valor, retorno_insere;
    arvore arv;

    incializa(&arv);
    printf("Arvore inicializada\n");

    printf("0-Sair\n1-Adicionar\n2-Imprimir\n");
    scanf("%d", &op);
    do{
        switch(op){
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
            printf("Conteudo da arvore:\n");
            printar(arv.raiz);
            printf("\n");
            break;
        case 0:
            printf("Saindo...\n");
            return 0;
        default:
            printf("Opção invalida\n");
            break;
        }
        printf("0-Sair\n1-Adicionar\n2-Imprimir\n");
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
            return 1;
    }else{
            if(valor>arv->raiz->conteudo){//verificação de lado que sera inserido
                retorno = insere_direita(arv->raiz, valor);//direita para valores maiores
                if(retorno == 1){
                    return 1;
                }
            }else{
                retorno=insere_esquerda(arv->raiz, valor);//esquerda para valores menores
                if(retorno == 1){
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

void printar(no* raiz){
    if(raiz!=NULL){
        printf("%d ", raiz->conteudo);
        printar(raiz->esq);
        printar(raiz->dir);
    }
}

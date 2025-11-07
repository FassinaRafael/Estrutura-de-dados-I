
#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int info;
    struct No *esq;
    struct No *dir;
}No;

typedef struct No* ArvBin;

ArvBin* cria_ArvBin(){
    ArvBin *raiz = (ArvBin*) malloc(sizeof(ArvBin));
    if(raiz != NULL) {
        *raiz = NULL;
    }
    return raiz;
}

void preOrdem_ArvBin(ArvBin* raiz){
    if(raiz == NULL){
        return;
    }
    
    if(*raiz != NULL){
        printf(" %d |", (*raiz)->info);
        preOrdem_ArvBin(&((*raiz)->esq));
        preOrdem_ArvBin(&((*raiz)->dir));
    }
}

void emOrdem_ArvBin(ArvBin* raiz){
    if(raiz == NULL){
        return;
    }
    
    if(*raiz != NULL){
        emOrdem_ArvBin(&((*raiz)->esq));
        printf(" %d |", (*raiz)->info);
        emOrdem_ArvBin(&((*raiz)->dir));
    }
}

void posOrdem_ArvBin(ArvBin* raiz){
    if(raiz == NULL){
        return;
    }
    
    if(*raiz != NULL){
        posOrdem_ArvBin(&((*raiz)->esq));
        posOrdem_ArvBin(&((*raiz)->dir));
        printf(" %d |", (*raiz)->info);
    }
}

int totalNos_ArvBin(ArvBin* raiz){
    if(raiz == NULL || *raiz == NULL)
        return 0;
        
    int total_esq = totalNos_ArvBin(&((*raiz)->esq));
    int total_dir = totalNos_ArvBin(&((*raiz)->dir));
    
    return total_esq + total_dir + 1;
}

int altura_ArvBin(ArvBin* raiz){
    if(raiz == NULL || *raiz == NULL)
        return -1;
        
    int altura_esq = altura_ArvBin(&((*raiz)->esq));
    int altura_dir = altura_ArvBin(&((*raiz)->dir));
    
    if(altura_esq > altura_dir){
        return altura_esq + 1;
    }
    else {
        return altura_dir + 1;
    }
}

int consulta_ArvBin(ArvBin* raiz, int valor){
    if(raiz == NULL || *raiz == NULL)
        return 0;

    No* atual = *raiz;
    while(atual != NULL){
        
        if(valor == atual->info){
            return 1;
        }
        if(valor > atual->info){
            atual = atual->dir;
        }
        else{
            atual = atual->esq;
        }
    }
    return 0;
}

int main()
{
    ArvBin* arvore = cria_ArvBin();

    // Cria os nós manualmente
    No* n1 = (No*) malloc(sizeof(No));
    No* n2 = (No*) malloc(sizeof(No));
    No* n3 = (No*) malloc(sizeof(No));

    // Atribui valores
    n1->info = 10;
    n2->info = 5;
    n3->info = 20;

    // Liga os nós
    n1->esq = n2;
    n1->dir = n3;
    n2->esq = NULL;
    n2->dir = NULL;
    n3->esq = NULL;
    n3->dir = NULL;

    // Define o nó raiz da árvore
    *arvore = n1;

    // Testa as travessias
    printf("Pré-ordem:");
    preOrdem_ArvBin(arvore);

    printf("\nEm ordem:");
    emOrdem_ArvBin(arvore);

    printf("\nPós-ordem:");
    posOrdem_ArvBin(arvore);

    // NOVAS LINHAS: mostrar total de nós e altura
    int total = totalNos_ArvBin(arvore);
    int altura = altura_ArvBin(arvore);

    printf("\n\nTotal de nós: %d", total);
    printf("\nAltura da árvore: %d\n", altura);

    // Libera memória
    free(n2);
    free(n3);
    free(n1);
    free(arvore);

    return 0;
}

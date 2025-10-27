/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct Elemento{
    int conteudo;
    struct Elemento* prox;
}Elemento;

typedef struct Fila{
    int quantidade;
    int maximo;
    struct Elemento* inicio;
    struct Elemento* fim;
}Fila;

Fila* cria_fila(){
    Fila* fi = (Fila*) malloc(sizeof(Fila));
    if(fi != NULL){
        fi->quantidade = 0;
        fi->maximo = 5;
        fi->inicio = NULL;
        fi->fim = NULL;
    }
    return fi;
}

int enqueue(Fila* fi, int x){
    if (fi == NULL || fi->quantidade >= fi->maximo){
        return 0;
    }
    
    Elemento *no = (Elemento*) malloc(sizeof(Elemento));
    if(no == NULL){
        return 0;
    }
    no->conteudo = x;
    no->prox = NULL;
    
    if(fi->quantidade == 0){
        fi->inicio = no;
        fi->fim = no;
    }
    else {
        fi->fim->prox = no;
        fi->fim = no;
    }
    fi->quantidade++;
    return 1;
}

int dequeue(Fila* fi){
    if (fi == NULL || fi->inicio == NULL){
        return 0;
    }
    
    Elemento* no = fi->inicio;
    fi->inicio = fi->inicio->prox;
    
    if(fi->inicio == NULL){
        fi->fim = NULL;
    }
    
    free(no);
    fi->quantidade--;
    return 1;
}

void imprime_fila(Fila* fi){
    if (fi == NULL || fi->inicio == NULL){
        printf("Fila vazia!\n");
        return;
    }

    Elemento* atual = fi->inicio;
    printf("Fila: ");
    while (atual != NULL){
        printf("%d ", atual->conteudo);
        atual = atual->prox;
    }
    printf("\n");
}

int peek(Fila* fi, int* valor){
    if(fi == NULL || fi->inicio == NULL){
        return 0;
    }
    *valor = fi->inicio->conteudo;
    return 1;
}

int main()
{
    int x;
    Fila* fi = cria_fila();
    enqueue(fi, 10);
    enqueue(fi, 20);
    enqueue(fi, 30);
    imprime_fila(fi);
    dequeue(fi);
    imprime_fila(fi);
    
    if (peek(fi, &x)) {
        printf("Primeiro elemento da fila: %d\n", x);
    } else {
        printf("Fila vazia!\n");
    }


    return 0;
}

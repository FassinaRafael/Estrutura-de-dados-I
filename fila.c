/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct elemento{
    int conteudo;
    struct elemento* prox;
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
}

int main()
{
    printf("Hello World");

    return 0;
}

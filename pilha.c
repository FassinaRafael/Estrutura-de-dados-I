#include <stdio.h>
#include <stdlib.h>
//Criando as estruturas base
typedef struct Node{
    int valor;
    struct Node* proximo;
}Node;

typedef struct Pilha{
    Node* topo;
}Pilha;

//Início das Funções
Pilha* criaPilha(){
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

int push(Pilha* p, int numero){
    Node* novo = (Node*) malloc(sizeof(Node));
    if (novo == NULL)
        return 0;
    
    novo->valor = numero;
    novo->proximo = p->topo;
    p->topo = novo;
    return 1;
}

int isEmpty(Pilha* p){
    if (p == NULL || p->topo == NULL) 
        return 1; 
    return 0;
}

int pop(Pilha* p, int* numero){
    if(isEmpty(p)) 
        return 0;
        
    Node* aux = p->topo;
    *numero = aux->valor;
    p->topo = aux->proximo;
    free(aux);
    return 1;
}

int peek(Pilha* p, int* numero){
    if(isEmpty(p))
        return 0;
        
    *numero = p->topo->valor;
    return 1;
}

int clear(Pilha* p){
    while (!isEmpty(p)) {
        Node* aux = p->topo;
        p->topo = aux->proximo;
        free(aux);
    }
    return 1;
}

void printPilha(Pilha* p){
    if (isEmpty(p)) {
        printf("Pilha vazia!\n");
        return;
    }

    Node* aux = p->topo;
    printf("Conteúdo da pilha (do topo para a base):\n");
    while (aux != NULL) {
        printf("%d\n", aux->valor);
        aux = aux->proximo;
    }
}


int main(void) {
    Pilha* p = criaPilha();
    int x;

    // 1) Empilhar
    push(p, 10);
    push(p, 20);
    push(p, 30);

    // 2) Visualizar
    printf("Depois de 3 push:\n");
    printPilha(p);

    // 3) Ver topo sem remover (peek)
    if (peek(p, &x)) {
        printf("Peek (topo atual): %d\n", x);
    } else {
        printf("Peek: pilha vazia.\n");
    }

    // 4) Desempilhar (pop) duas vezes
    if (pop(p, &x)) printf("Pop 1 -> %d\n", x);
    if (pop(p, &x)) printf("Pop 2 -> %d\n", x);

    // 5) Ver conteúdo atual
    printf("Depois de 2 pop:\n");
    printPilha(p);

    // 6) Testar isEmpty
    printf("A pilha esta vazia? %s\n", isEmpty(p) ? "SIM" : "NAO");

    // 7) Limpar tudo
    clear(p);
    printf("Depois de clear:\n");
    printPilha(p); // deve dizer "Pilha vazia!"

    printf("A pilha esta vazia? %s\n", isEmpty(p) ? "SIM" : "NAO");

    // 8) Liberar a struct Pilha
    free(p);

    return 0;
}



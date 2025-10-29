#include <stdio.h>
#include <stdlib.h>

//DEFINÇÕES DE ESTRUTURAS
typedef struct cel{
  int conteudo;
  struct cel *proximo;
}cel;

typedef struct cel* Lista;

//CRIAR
Lista* cria_lista(){
  Lista* li = malloc(sizeof(Lista));
  if(li != NULL){
    *li = NULL;
  }
  return li;
}

//INSERIR NO FIM
int insere_lista_fim(Lista* lista, int x){
  if(lista == NULL) { return 0; }
  
  cel* nova_celula = (cel*) malloc(sizeof(cel));
  if(nova_celula == NULL){ return 0; }
  
  nova_celula->conteudo = x;
  nova_celula->proximo = NULL;
  
  if(*lista == NULL) {
    *lista = nova_celula;
    
  } else {
    cel* aux = *lista;
    
    while(aux->proximo != NULL){ 
      aux = aux->proximo;
    }
    aux->proximo = nova_celula;
  }
  return 1;
}

//REMOVER
int remover_valor(Lista* lista, int x) {
    if (lista == NULL || *lista == NULL) {
        return 0;
    }

    cel *aux = *lista;
    cel *anterior = NULL; 

    while (aux != NULL && aux->conteudo != x) {
        anterior = aux;
        aux = aux->proximo;
    }

    if (aux == NULL) {
        return 0;
    }

    if (anterior == NULL) {
        *lista = aux->proximo;
    } 
    else {
        anterior->proximo = aux->proximo;
    }

    free(aux);
    return 1; 
}

//REMOVER N ELEMENTOS
int remover_n_valores(Lista* lista, int quantidade){
    if (lista == NULL || *lista == NULL)
        return 0;
    
    int contador = 0;
    cel *aux = *lista;
    cel *anterior = NULL;
    while(aux != NULL && contador < quantidade){
        anterior = aux;
        aux = aux->proximo;
        contador++;
        free(anterior);
    }
    *lista = aux;
    return contador;
}

//IMPRIMIR
void imprime_lista(Lista* lista) {
    cel* aux = *lista;
    
    while(aux != NULL){
        printf("%d -> ", aux->conteudo);
        aux = aux->proximo;
    }
    
    printf("NULL\n");
}

//BUSCAR
void buscar(Lista* lista, int chave) {
    cel* aux = *lista;
    int contador = 0;
    int encontrado = 0;
    
    while(aux != NULL) {
        if(aux->conteudo == chave) {
            printf("NUMERO %i ENCONTRADO NA CELULA %i\n", chave, contador);
            encontrado = 1;
            break;
        }
        aux = aux->proximo;
        contador++;
    }
    if(!encontrado)
        printf("%d nao encontrado\n", chave);
}

//CONCATENAR
Lista concatena_listas(Lista li1, Lista li2){
    if (li1 == NULL && li2 == NULL) {
        return NULL;  
    }

    if (li1 == NULL) {
        return li2;  
    }

    if (li2 == NULL) {
        return li1; 
    }
    
    Lista auxLi1 = li1;
    while(auxLi1->proximo != NULL){
        auxLi1 = auxLi1->proximo;                           
    }
    
    auxLi1->proximo = li2;
    
    return li1;
}

// Função para liberar a lista da memória (Nós e o ponteiro de cabeça)
void free_lista(Lista* lista) {
    // 1. Verifica se o ponteiro da lista é válido
    if (lista == NULL) {
        return;
    }
    
    cel* no_atual;
    
    // 2. Percorre a lista, liberando nó por nó
    while (*lista != NULL) {
        no_atual = *lista;         // Guarda o nó atual
        *lista = (*lista)->proximo; // Avança o cabeça da lista
        free(no_atual);            // Libera o nó guardado
    }
    
    // 3. Libera o ponteiro 'lista' (o 'li' criado pelo malloc em cria_lista)
    free(lista);
}

//BUSCAR MAIOR ELEMENTO 
void buscar_maior_na_lista(Lista* lista){
    if(lista == NULL || *lista == NULL){
        printf("Lista vazia ou inexistente.\n");
        return;
    }
    
    cel* aux = *lista;
    int maior = aux->conteudo;
    int contador = 0, posicao_maior = 0;
    while(aux != NULL){
        
        if(aux->conteudo > maior){
            maior = aux->conteudo;
            posicao_maior = contador;
        }
        aux = aux->proximo;
        contador++;
    }
    printf("Maior valor encontrado: %d\n", maior);
    printf("Posicao (indice): %d\n", posicao_maior);
}

int main(void) {
    printf("--- Teste 1: Criacao e Insercao ---\n");
    Lista* lst1 = cria_lista();
    insere_lista_fim(lst1, 10);
    insere_lista_fim(lst1, 20);
    insere_lista_fim(lst1, 30);
    insere_lista_fim(lst1, 40);
    insere_lista_fim(lst1, 50);
    printf("Lista 1 criada:\n");
    imprime_lista(lst1); // Saida: 10 -> 20 -> 30 -> 40 -> 50 -> NULL
    buscar_maior_na_lista(lst1);
    printf("\n");

    printf("--- Teste 2: Funcao Buscar ---\n");
    buscar(lst1, 30); // Deve achar
    buscar(lst1, 99); // Nao deve achar
    printf("\n");

    printf("--- Teste 3: Remover Valor (no meio) ---\n");
    remover_valor(lst1, 30);
    printf("Depois de remover 30:\n");
    imprime_lista(lst1); // Saida: 10 -> 20 -> 40 -> 50 -> NULL
    printf("\n");

    printf("--- Teste 4: Remover Valor (no inicio) ---\n");
    remover_valor(lst1, 10);
    printf("Depois de remover 10:\n");
    imprime_lista(lst1); // Saida: 20 -> 40 -> 50 -> NULL
    printf("\n");

    printf("--- Teste 5: Remover Valor (no fim) ---\n");
    remover_valor(lst1, 50);
    printf("Depois de remover 50:\n");
    imprime_lista(lst1); // Saida: 20 -> 40 -> NULL
    printf("\n");

    printf("--- Teste 6: Remover N Primeiros Valores ---\n");
    // Re-popular a lista
    insere_lista_fim(lst1, 60);
    insere_lista_fim(lst1, 70);
    printf("Lista antes de remover N:\n");
    imprime_lista(lst1); // Saida: 20 -> 40 -> 60 -> 70 -> NULL
    
    remover_n_valores(lst1, 2); // Remove 20 e 40
    
    printf("Depois de remover 2 primeiros:\n");
    imprime_lista(lst1); // Saida: 60 -> 70 -> NULL
    printf("\n");

    printf("--- Teste 7: Concatenar Listas ---\n");
    Lista* lst2 = cria_lista();
    insere_lista_fim(lst2, 100);
    insere_lista_fim(lst2, 200);
    
    printf("Lista 1 (lst1) original:\n");
    imprime_lista(lst1); // Saida: 60 -> 70 -> NULL
    printf("Lista 2 (lst2) original:\n");
    imprime_lista(lst2); // Saida: 100 -> 200 -> NULL
    
    // A sua função 'concatena_listas' recebe (Lista, Lista), 
    // ou seja, (cel*, cel*). Por isso passamos *lst1 e *lst2.
    // Ela *modifica* a lista 1.
    Lista lista_concatenada_ptr = concatena_listas(*lst1, *lst2);
    
    printf("Lista 1 (lst1) apos concatenar:\n");
    imprime_lista(lst1); // Saida: 60 -> 70 -> 100 -> 200 -> NULL
    
    // CUIDADO: 'concatena_listas' torna 'lst2' perigosa.
    // O ponteiro 'lst2' agora aponta para o *meio* de 'lst1'.
    // Se tentássemos liberar 'lst2', teríamos um erro de "double free".
    // Para evitar isso, "esvaziamos" o ponteiro de cabeça de lst2.
    *lst2 = NULL; 
    
    printf("\n");

    printf("--- Teste 8: Liberar Memoria ---\n");
    // 'lista_concatenada_ptr' é só um cel*, não o Lista* (cel**)
    // Não precisamos dela, liberamos as listas originais.
    
    free_lista(lst1);
    printf("Lista 1 liberada.\n");
    
    free_lista(lst2); // Agora é seguro, pois *lst2 é NULL
    printf("Lista 2 liberada.\n");

    printf("\nTestes concluidos com sucesso.\n");
    
    return 0;
}

#include <stdio.h>
#include <stdlib.h>




typedef struct cel{
  int conteudo;
  struct cel *proximo;
}cel;

typedef struct cel* Lista;


Lista* cria_lista(){
  Lista* li = malloc(sizeof(Lista));
  if(li != NULL){
    *li = NULL;
  }
  return li;
}

int insere_lista_fim(Lista* lista, int x){
  if(lista == NULL) { return 0; }
  
  cel* aux = (cel*) malloc(sizeof(cel));
  if(aux == NULL){ return 0; }
  
  aux->conteudo = x;
  aux->proximo = NULL;
  
  if(*lista == NULL) {
    *lista = aux;
    
  } else {
    cel* temp = *lista;
    
    while(temp->proximo != NULL){ 
      temp = temp->proximo;
    }
    temp->proximo = aux;
  }
  return 1;
}

void imprime_lista(Lista* lista) {
    cel* temp = *lista;
    
    while(temp != NULL){
        printf("%d -> ", temp->conteudo);
        temp = temp->proximo;
    }
    
    printf("NULL\n");
}

void buscar(Lista* lista, int chave) {
    cel* temp = *lista;
    int contador = 0;
    int encontrado = 0;
    
    while(temp != NULL) {
        if(temp->conteudo == chave) {
            printf("NUMERO %i ENCONTRADO NA CELULA %i\n", chave, contador);
            encontrado = 1;
            break;
        }
        temp = temp->proximo;
        contador++;
    }
    if(!encontrado)
        printf("%d nao encontrado\n", chave);
}

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
    
    Lista tempLi1 = li1;
    while(tempLi1->proximo != NULL){
        tempLi1 = tempLi1->proximo;
    }
    
    tempLi1->proximo = li2;
    
    return li1;
}

int main(void) {
  Lista* lst1 = cria_lista();
  
  Lista* lst2 = cria_lista();
  
  insere_lista_fim(lst1, 1);
  insere_lista_fim(lst1, 2);
  insere_lista_fim(lst1, 3);
  insere_lista_fim(lst1, 4);
  insere_lista_fim(lst1, 5);
  imprime_lista(lst1);

  insere_lista_fim(lst2, 55);
  insere_lista_fim(lst2, 62);
  insere_lista_fim(lst2, 102);
  insere_lista_fim(lst2, 41);
  insere_lista_fim(lst2, 810);
  imprime_lista(lst2);
  
  buscar(lst1, 3);
  buscar(lst1, 55);
  buscar(lst2, 55);
  buscar(lst2, 555);
  
  Lista lst3 = concatena_listas(*lst1, *lst2);
  imprime_lista(&lst3);
  return 0;
}
